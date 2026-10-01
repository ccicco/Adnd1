#!/usr/bin/env python3
# R100 the henchman ages: the hire gets a youth (rolled at
# hire, 16..19 - a young fighter answers the call), a
# birthday line on the same 365-day career marks, and a
# repaired save line.
#
# THE REPAIR (found authoring this round): the loader reads
# a present flag (0/1, else "corrupt (hire)"), then hp/max/
# level/loyalty, the NAME, then trailing ints. The save
# wrote all nine ints BEFORE the name - so the hire's hp
# (always >= 2) hit the present flag and EVERY save made
# with a hired henchman failed to load. The save now writes
# the loader's contract; the hire's startAge rides as a
# sixth trailing int (older saves: absent, loads 0).
#
# Patches (10):
#   game/party.h      - henchmanStartAge + hireAgeYears()
#   game/state_town.cpp - age rolled at hire, message,
#                         birthday line
#   game/state_core.cpp - save repair + load trailing int
#   regtest.cpp       - R100 hire's years audit (incl. the
#                       pinned save/load contract)
#   tools/playverify_r77_r83.md - R100 section
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
# 1) party.h - the hire's startAge field
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    int  henchmanLevel  = 1;
    int  henchmanLoyalty = 50;
""",
"""    int  henchmanLevel  = 1;
    int  henchmanLoyalty = 50;
    // R100: the hire's youth - rolled when he answers the
    // call (a young fighter, the yard age). 0 = an older
    // save's hire, unknown youth.
    int  henchmanStartAge = 0;
""",
'party.h hire startAge')

# ---------------------------------------------------------------------------
# 2) party.h - the hire's age on the career clock
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}
""",
"""inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}

// R100: the hire's age on the same clock (his youth rolled
// at hire; 0 = unknown - an older save's hire)
inline int hireAgeYears(const Party& p) {
    return p.henchmanStartAge + p.careerDays / 365;
}
""",
'party.h hireAgeYears')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - the youth is rolled at hire
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        party.henchmanLoyalty = 50 + chaAdj;
        char buf[96];
""",
"""        party.henchmanLoyalty = 50 + chaAdj;
        // R100: the hire has a youth too - a young fighter
        // answers the call (16..19, the yard age)
        party.henchmanStartAge =
            rollStartingAge(rules::CLASS_FIGHTER, dice);
        char buf[96];
""",
'town.cpp hire age')

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the answer says his age
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""                 "%s the fighter answers the offer! (loyalty "
                 "%d%%)",
                 party.henchmanName.c_str(),
                 party.henchmanLoyalty);
""",
"""                 "%s the fighter answers the offer at %d "
                 "years! (loyalty %d%%)",
                 party.henchmanName.c_str(),
                 party.henchmanStartAge,
                 party.henchmanLoyalty);
""",
'town.cpp hire message')

# ---------------------------------------------------------------------------
# 5) state_town.cpp - the hire's birthday
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""            }
        }
        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend - a career day spent.");
""",
"""            }
        }
        // R100: the hire ages too - the same 365-day mark
        // (a hire of unknown youth stays silent)
        if (party.henchmanPresent &&
            party.henchmanStartAge > 0) {
            char hb[96];
            snprintf(hb, sizeof hb,
                     "%s turns %d years old.",
                     party.henchmanName.c_str(),
                     hireAgeYears(party));
            log.add(hb);
        }
        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend - a career day spent.");
""",
'town.cpp hire birthday')

# ---------------------------------------------------------------------------
# 6) state_core.cpp - the save repair
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        if (party.henchmanPresent)
            fprintf(f, "henchman %d %d %d %d %d %d %d %d %d %s\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanName.c_str());
""",
"""        // R100 repair: the loader reads a present flag,
        // then hp/max/level/loyalty, the NAME, then
        // trailing ints. The old save wrote all nine ints
        // before the name - its first int (the hire's hp,
        // always >= 2) hit the present flag, and every
        // save made with a hired henchman failed to load
        // ("corrupt (hire)"). The name now rides early;
        // six trailing ints follow (the sixth is the
        // hire's startAge, R100).
        if (party.henchmanPresent)
            fprintf(f,
                "henchman 1 %d %d %d %d %s %d %d %d %d %d %d\\n",
                    party.henchmanHp, party.henchmanMaxHp,
                    party.henchmanLevel, party.henchmanLoyalty,
                    party.henchmanName.c_str(),
                    party.henchmanXp, party.henchmanPurse,
                    party.delveGold,
                    party.henchmanWeaponPlus,
                    party.henchmanShieldPlus,
                    party.henchmanStartAge);
""",
'state_core.cpp save repair')

# ---------------------------------------------------------------------------
# 7) state_core.cpp - the loader's sixth trailing int
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int got = fscanf(f, "%d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl);
""",
"""                    int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0;
                    int hge = 0;   // R100: the hire's youth
                    int got = fscanf(f, "%d %d %d %d %d %d",
                                     &hxp, &hpu, &dgv, &wpl, &spl,
                                     &hge);
""",
'state_core.cpp load trailing')

OK &= patch('game/state_core.cpp',
"""                    if (got >= 5) p.henchmanShieldPlus = spl;
""",
"""                    if (got >= 5) p.henchmanShieldPlus = spl;
                    if (got >= 6) p.henchmanStartAge = hge;
""",
'state_core.cpp load age')

# ---------------------------------------------------------------------------
# 8) regtest.cpp - the hire's years audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R98 years tell audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R98 years tell audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----
    {
        int bad = 0;
        // the hire rides the same clock, from an unknown
        // youth default
        {
            Party p;
            if (p.henchmanStartAge != 0) ++bad;
            p.henchmanStartAge = 17;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 364;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 365;
            if (hireAgeYears(p) != 18) ++bad;
            p.careerDays = 3650;
            if (hireAgeYears(p) != 27) ++bad;
        }
        // the save/load contract, PINNED: a present flag,
        // four ints, the NAME, then six trailing ints (the
        // pre-R100 save put the name last and never loaded)
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (present != 1) ++bad;
            if (hp != 8 || mx != 8 || lv != 1 || loy != 50)
                ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge);
            if (got != 6) ++bad;
            if (hxp != 2000 || hpu != 300 || dgv != 500)
                ++bad;
            if (wpl != 1 || spl != 1) ++bad;
            if (hge != 17) ++bad;
        }
        printf("R100 hire's years audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp hire years audit')

# ---------------------------------------------------------------------------
# 9) playverify - the R100 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R98: the years tell
""",
"""## R100: the hire's years
- [ ] The hire's answer line reads "answers the offer at
      N years!" (16..19)
- [ ] The inn birthday that crosses a 365-day mark logs
      the hire's birthday too
- [ ] CRITICAL (R100 repair): save with a hired henchman,
      then load - it must load clean, and the hire's name,
      loyalty, xp, purse, kit pluses and age all survive
      (pre-R100 such saves failed "corrupt (hire)")
- [ ] An absent-hire save still writes "henchman 0" and
      loads clean

## R98: the years tell
""",
'playverify hire years section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R100 splice: ALL OK')
    sys.exit(0)
else:
    print('R100 splice: FAILED')
    sys.exit(1)
