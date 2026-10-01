#!/usr/bin/env python3
# R96 the town clock: town days stop being free. The inn
# night costs a career day; training costs days equal to
# the new level (a week of drills for a name, spent on the
# career calendar). Temple healing stays same-day (paid
# service, no days). No save-format change - careerDays
# is already persisted (R95 caldays line).
#
# Patches (6):
#   game/party.h       - trainingDays(newLevel) helper
#   game/state_town.cpp - inn night counts a career day
#   game/state_town.cpp - training counts its days
#   regtest.cpp        - R96 town clock audit
#   tools/playverify_r77_r83.md - R96 section
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
# 1) party.h - training takes days equal to the new level
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int dungeonDays(int turnCount) {
    return turnCount / turnsPerDay();
}
""",
"""inline int dungeonDays(int turnCount) {
    return turnCount / turnsPerDay();
}

// R96: the town clock. Training costs days equal to the
// new level - a fair price for a fair mastery (the 2nd
// rank is two days of drills, the 9th is nine).
inline int trainingDays(int newLevel) {
    return newLevel;
}
""",
'party.h trainingDays')

# ---------------------------------------------------------------------------
# 2) state_town.cpp - the inn night is a career day
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        party.gold -= 10;
        restoreSlots();""",
"""        party.gold -= 10;
        // R96: the town clock - a night at the inn is a
        // career day spent whole
        ++party.careerDays;
        restoreSlots();""",
'town.cpp inn day')

OK &= patch('game/state_town.cpp',
"""        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend.");""",
"""        log.add("A safe night at the inn. Spells, quivers, and "
                "wounds mend - a career day spent.");
""",
'town.cpp inn message')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - training spends its days
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        party.gold -= cost;
        int trained = party.trainNext(dice, log);""",
"""        party.gold -= cost;
        // R96: the town clock - training burns days equal
        // to the new level on the career calendar. The
        // count is taken BEFORE trainNext raises c.level
        // (the receipt must not grow with the promotion).
        int days = trainingDays(c.level + 1);
        party.careerDays += days;
        int trained = party.trainNext(dice, log);""",
'town.cpp training days')

OK &= patch('game/state_town.cpp',
"""            snprintf(buf, sizeof buf,
                     "Training paid (%d gp).", cost);""",
"""            snprintf(buf, sizeof buf,
                     "Training paid (%d gp, %d days).",
                     cost, days);""",
'town.cpp training message')

# ---------------------------------------------------------------------------
# 4) regtest.cpp - the town clock audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R95 calendar audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R95 calendar audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R96: town clock audit ----
    {
        int bad = 0;
        // training costs days equal to the new level
        if (trainingDays(2) != 2) ++bad;
        if (trainingDays(3) != 3) ++bad;
        if (trainingDays(9) != 9) ++bad;
        // the 1st rank is never free, the 20th never
        // costs more than the keep's patience (bound 1..20)
        if (trainingDays(1) < 1) ++bad;
        if (trainingDays(20) > 20) ++bad;
        // a town week: three inn nights and one promotion
        // to 3rd level - 3 + 3 days, no more, no less
        {
            Party p;
            p.careerDays = 0;
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += 1;                     // inn night
            p.careerDays += trainingDays(3);       // the drills
            if (p.careerDays != 6) ++bad;
        }
        printf("R96 town clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp town clock audit')

# ---------------------------------------------------------------------------
# 5) playverify - the R96 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R95: the calendar
""",
"""## R96: the town clock
- [ ] An inn night (10 gp) advances the career day count
      by one and the message says "a career day spent"
- [ ] Training adds days equal to the new level; the
      receipt reads "Training paid (N gp, D days)."
- [ ] Temple healing changes no days (same-day service)
- [ ] A save round-trips the grown career day count

## R95: the calendar
""",
'playverify town clock section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R96 splice: ALL OK')
    sys.exit(0)
else:
    print('R96 splice: FAILED')
    sys.exit(1)
