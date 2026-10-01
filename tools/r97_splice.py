#!/usr/bin/env python3
# R97 the gray beard: the career calendar starts aging the
# company. Each member rolls a starting age at creation
# (fighter 15+1d4, magic-user 24+2d8, cleric 18+1d4, thief
# 18+1d4 - creation-convention values, PHB book-verify
# pending), and ageYears(startAge + careerDays/365) grows
# on the R95 clock. Birthdays land on the inn night that
# crosses a 365-day mark. Save gains an optional per-member
# "age" line (v1 saves load at 0 - no birthdays then).
#
# Patches (9):
#   game/party.h      - startAge field + startAgeBase()/
#                       rollStartingAge()/ageYears() helpers
#   game/appstate.h   - makeMember rolls the starting age
#   adnd1.cpp         - the join message says the age
#   game/state_core.cpp - "age %d" save + load branch
#   game/state_town.cpp - inn birthday line
#   regtest.cpp       - R97 gray beard audit
#   tools/playverify_r77_r83.md - R97 section
import sys, os

os.chdir(os.path.dirname(os.path.abspath(__file__)) + '/..')

def rd(p):
    with open(p, 'r', encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(p, 'w', encoding='ascii') as f:
        f.write(s)

OK = True

def patch(path, anchor, repl, label):
    global OK
    s = rd(path)
    if repl in s:
        print(label + ': already patched')
        return True
    i = s.find(anchor)
    if i < 0:
        print(label + ': ANCHOR MISS')
        OK = False
        return False
    s = s.replace(anchor, repl, 1)
    wr(path, s)
    print(label + ': patched')
    return True

# ---------------------------------------------------------------------------
# 1) party.h - the startAge field
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    int  xp   = 0;
    int  level = 1;
    int  hp = 0, maxHp = 0;""",
"""    int  xp   = 0;
    int  level = 1;
    int  hp = 0, maxHp = 0;
    // R97: the gray beard - age at leaving the training
    // hall; grows on the R95 career clock (ageYears).
    // 0 = a v1 save member whose youth is unknown.
    int  startAge = 0;""",
'party.h startAge')

# ---------------------------------------------------------------------------
# 2) party.h - the aging helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int trainingDays(int newLevel) {
    return newLevel;
}
""",
"""inline int trainingDays(int newLevel) {
    return newLevel;
}

// R97: the gray beard. Starting age by class (creation
// convention; PHB book-verify pending): fighters leave the
// yard young, magic-users leave the tower late.
inline int startAgeBase(int classIndex) {
    switch (classIndex) {
        case CLASS_FIGHTER:     return 15;
        case CLASS_MAGIC_USER:  return 24;
        case CLASS_CLERIC:      return 18;
        default:                return 18;   // thief
    }
}

inline int rollStartingAge(int classIndex, rules::Dice& d) {
    if (classIndex == CLASS_MAGIC_USER)
        return startAgeBase(classIndex) + d.roll(2, 8, 0);
    return startAgeBase(classIndex) + d.roll(1, 4, 0);
}

// age today: the starting age plus whole years on the
// career clock (365 days to the year)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}
""",
'party.h aging helpers')

# ---------------------------------------------------------------------------
# 3) appstate.h - makeMember rolls the starting age
# ---------------------------------------------------------------------------
OK &= patch('game/appstate.h',
"""        c.classIndex = classIndex;
        c.level = 1;""",
"""        c.classIndex = classIndex;
        c.level = 1;
        // R97: the gray beard - when the career begins
        c.startAge = rollStartingAge(classIndex, creationDice);""",
'appstate.h makeMember age')

# ---------------------------------------------------------------------------
# 4) adnd1.cpp - the join message says the age
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""    snprintf(buf, sizeof buf, "%s the %s joins the party.",
             c.name.c_str(), CLASS_NAMES[c.classIndex]);""",
"""    snprintf(buf, sizeof buf, "%s the %s joins the party at %d years.",
             c.name.c_str(), CLASS_NAMES[c.classIndex],
             c.startAge);""",
'adnd1.cpp join message')

# ---------------------------------------------------------------------------
# 5) state_core.cpp - save + load the age line
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\\n", c.shieldPlus);""",
"""            if (c.shieldPlus > 0)
                fprintf(f, "shieldplus %d\\n", c.shieldPlus);
            // R97: the gray beard (optional line - v1 saves
            // load with an unknown youth, startAge 0)
            if (c.startAge > 0)
                fprintf(f, "age %d\\n", c.startAge);""",
'state_core.cpp save age')

OK &= patch('game/state_core.cpp',
"""            if (strcmp(tag, "ringplus") == 0) {""",
"""            if (strcmp(tag, "age") == 0) {
                int ag = 0;
                if (fscanf(f, "%d", &ag) != 1 ||
                    ag < 15 || ag > 100) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (age).");
                    return false;
                }
                c.startAge = ag;
            } else if (strcmp(tag, "ringplus") == 0) {""",
'state_core.cpp load age')

# ---------------------------------------------------------------------------
# 6) state_town.cpp - the inn birthday
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend - a career day spent.");""",
"""        // R97: the gray beard - the inn night that crosses
        // a 365-day mark is a birthday (only members whose
        // youth is known; delve-day batches can skip a
        // crossing, the town clock catches most)
        if (party.careerDays > 0 &&
            party.careerDays % 365 == 0) {
            for (auto& c : party.members) {
                if (c.hp <= 0 || c.startAge <= 0) continue;
                char ab[96];
                snprintf(ab, sizeof ab,
                         "%s turns %d years old.",
                         c.name.c_str(),
                         ageYears(c, party.careerDays));
                log.add(ab);
            }
        }
        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend - a career day spent.");""",
'town.cpp inn birthday')

# ---------------------------------------------------------------------------
# 7) regtest.cpp - the gray beard audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R96 town clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R96 town clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R97: gray beard audit ----
    {
        int bad = 0;
        // starting age bases: fighter youngest, MU latest
        if (startAgeBase(CLASS_FIGHTER)    != 15) ++bad;
        if (startAgeBase(CLASS_MAGIC_USER) != 24) ++bad;
        if (startAgeBase(CLASS_CLERIC)     != 18) ++bad;
        if (startAgeBase(CLASS_THIEF)      != 18) ++bad;
        // rolled bounds: fighter 16..19, MU 26..40
        {
            rules::Rng r{1};
            rules::Dice d(r);
            for (int i = 0; i < 200; ++i) {
                int f = rollStartingAge(CLASS_FIGHTER, d);
                int m = rollStartingAge(CLASS_MAGIC_USER, d);
                if (f < 16 || f > 19) ++bad;
                if (m < 26 || m > 40) ++bad;
            }
        }
        // the clock turns years only at whole 365s
        {
            Character c;
            c.startAge = 20;
            if (ageYears(c, 0)   != 20) ++bad;
            if (ageYears(c, 364) != 20) ++bad;
            if (ageYears(c, 365) != 21) ++bad;
            if (ageYears(c, 730) != 22) ++bad;
        }
        // an unknown youth (v1 save) stays 0 until the
        // clock grows years of its own
        {
            Character c;
            if (c.startAge != 0) ++bad;
            if (ageYears(c, 364) != 0) ++bad;
            if (ageYears(c, 365) != 1) ++bad;
        }
        printf("R97 gray beard audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp gray beard audit')

# ---------------------------------------------------------------------------
# 8) playverify - the R97 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R96: the town clock
""",
"""## R97: the gray beard
- [ ] A new member's join line reads "joins the party at
      N years" (fighter 16-19, cleric/thief 19-22, MU 26-40)
- [ ] The inn night that crosses a 365-day career mark
      logs "N turns M years old." for each living member
- [ ] A save round-trips the age; a v1 save loads with
      startAge 0 and no birthday lines
- [ ] The delve report and training days are unaffected

## R96: the town clock
""",
'playverify gray beard section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R97 splice: ALL OK')
    sys.exit(0)
else:
    print('R97 splice: FAILED')
    sys.exit(1)
