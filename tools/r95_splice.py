# R95-CHUNK-1-START
#!/usr/bin/env python3
# R95 the calendar: career day counter across dungeon/overland/
# sea. One clock across all three time models.
#
# Patches (12):
#   game/state_overland.cpp - mangled arrival string repaired
#   game/party.h            - careerDays field + turnsPerDay()/
#                            dungeonDays() helpers
#   game/state_overland.cpp - march ([T]) + homeward ([H]) days
#   game/state_sea.cpp      - each sea day advances the career
#   game/state_core.cpp     - "caldays %d" save line + load
#                            branch (v1 saves load at 0 days)
#   game/state_town.cpp     - delve report gains day count
#   regtest.cpp             - R95 calendar audit
#   tools/playverify_r77_r83.md - R95 section
#
# The conversion: a dungeon day is 144 turns (the R89-R92
# coherence bound); overland/sea days count their own day
# counters directly. Town days are free (recovery/trade).
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

# ---------------------------------------------------------------------------
# 1) state_overland.cpp - the mangled arrival string (pre-existing
#    collision: "rise ahead" + "is over." merged into one line)
# ---------------------------------------------------------------------------
OK &= patch('game/state_overland.cpp',
"""        log.add("The walls of town rise aheadis over.");""",
"""        // R95 repair: this string was mangled by a past
        // round (two fragments collided) - "rise ahead" +
        // "the journey is over"
        log.add("The walls of town rise ahead - "
                "the journey is over.");""",
'overland.cpp arrival repair')

# ---------------------------------------------------------------------------
# 2) party.h - the careerDays field + calendar helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    int  delveCount   = 0;
    int  deepestLevel = 0;
    long totalGold    = 0;""",
"""    int  delveCount   = 0;
    int  deepestLevel = 0;
    long totalGold    = 0;

    // R95: the career calendar - total days the company has
    // been at it (dungeon, trail, sea; town days are free -
    // recovery and trade). One clock across all three time
    // models.
    int  careerDays   = 0;""",
'party.h careerDays')
# R95-CHUNK-1-END
# R95-CHUNK-2-START

OK &= patch('game/party.h',
"""inline int loyaltyDriftHardWatch()   { return -1; }
""",
"""inline int loyaltyDriftHardWatch()   { return -1; }

// R95: the calendar. A dungeon day is 144 turns (the R89-R92
// coherence bound: 120' unencumbered, 6 turns to the hour);
// the trail and the sea count their own days directly.
inline int turnsPerDay() { return 144; }

inline int dungeonDays(int turnCount) {
    return turnCount / turnsPerDay();
}
""",
'party.h calendar helpers')

# ---------------------------------------------------------------------------
# 3) state_overland.cpp - march and homeward days
# ---------------------------------------------------------------------------
OK &= patch('game/state_overland.cpp',
"""        ++overland.day;
        ++overland.daysOut;
        char buf[96];""",
"""        ++overland.day;
        ++overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        char buf[96];""",
'overland.cpp march day')

OK &= patch('game/state_overland.cpp',
"""        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        char buf[96];""",
"""        overland.homeward = true;
        ++overland.day;
        --overland.daysOut;
        ++party.careerDays;   // R95: the trail counts
        char buf[96];""",
'overland.cpp homeward day')

# ---------------------------------------------------------------------------
# 3) state_sea.cpp - each sailing day counts
# ---------------------------------------------------------------------------
OK &= patch('game/state_sea.cpp',
"""        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        char buf[96];""",
"""        sea.homeward = false;
        ++sea.day;
        ++sea.daysOut;
        ++party.careerDays;   // R95: the sea counts
        char buf[96];""",
'sea.cpp sea day')

OK &= patch('game/state_sea.cpp',
"""        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        char buf[96];""",
"""        sea.homeward = true;
        ++sea.day;
        --sea.daysOut;
        ++party.careerDays;   // R95: the sea road counts
        char buf[96];""",
'sea.cpp sea road day')
# R95-CHUNK-2-END
# R95-CHUNK-3-START

# ---------------------------------------------------------------------------
# 4) state_core.cpp - save/load + the delve report gains days
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "ledger %d %d %ld\\n",
                party.delveCount, party.deepestLevel,
                party.totalGold);""",
"""        fprintf(f, "ledger %d %d %ld\\n",
                party.delveCount, party.deepestLevel,
                party.totalGold);
        fprintf(f, "caldays %d\\n", party.careerDays);""",
'state_core.cpp save caldays')

OK &= patch('game/state_core.cpp',
"""            } else if (strcmp(tag, "ledger") == 0) {""",
"""            } else if (strcmp(tag, "caldays") == 0) {
                int cdays = 0;
                if (fscanf(f, "%d", &cdays) != 1 ||
                    cdays < 0 || cdays > 100000) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (caldays).");
                    return false;
                }
                p.careerDays = cdays;
            } else if (strcmp(tag, "ledger") == 0) {""",
'state_core.cpp load caldays')

OK &= patch('game/state_town.cpp',
"""        char rb[128];""",
"""        char rb[128];
        // R95: the delve's days convert at 144 turns apiece
        // and join the career clock
        int dDays = dungeonDays(turnCount);
        party.careerDays += dDays;
        snprintf(rb, sizeof rb,
                 "Delve #%d complete - %d gp hauled "
                 "(career: depth %d, %ld gp, %d days).",
                 party.delveCount, party.delveGold,
                 party.deepestLevel, party.totalGold,
                 party.careerDays);""",
'state_town.cpp report days')
# R95-CHUNK-3-END
# R95-CHUNK-4-START

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the calendar audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R94 nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }
""",
"""        printf("R94 nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R95: calendar audit ----
    {
        int bad = 0;
        // the conversion: 144 turns to the day
        if (turnsPerDay() != 144) ++bad;
        if (dungeonDays(0)    != 0) ++bad;
        if (dungeonDays(143)  != 0) ++bad;   // not yet a day
        if (dungeonDays(144)  != 1) ++bad;
        if (dungeonDays(156)  != 1) ++bad;   // a deep delve's
        if (dungeonDays(288)  != 2) ++bad;   // remainder is
        if (dungeonDays(1000) != 6) ++bad;   // honest floors
        // the ledger bounds still hold with days: a full
        // delve day (36 descent + 60 march + 48 camp = 144)
        // is exactly one career day
        if (descentTurns() + 60 + restTurns(false)
            != turnsPerDay()) ++bad;
        // the calendar starts clean and only grows
        {
            Party p;
            if (p.careerDays != 0) ++bad;
            p.careerDays += dungeonDays(144);
            p.careerDays += 1;               // an overland day
            p.careerDays += 1;               // a sea day
            if (p.careerDays != 3) ++bad;
        }
        printf("R95 calendar audit: bad %d\\n", bad);
        if (bad) return 1;
    }
""",
'regtest.cpp calendar audit')

# ---------------------------------------------------------------------------
# 6) playverify - the R95 section
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## R94: the nerve
""",
"""## R95: the calendar
- [ ] Each overland march ([T]/[H]) and sea sailing day
      increments the career day count
- [ ] The delve report line ends with the career day total
- [ ] A save round-trips the caldays value; a v1 save loads
      with 0 career days
- [ ] The town arrival string reads "The walls of town rise
      ahead - the journey is over." (no mangled text)

## R94: the nerve
""",
'playverify calendar section')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R95 splice: ALL OK')
    sys.exit(0)
else:
    print('R95 splice: FAILED')
    sys.exit(1)
# R95-CHUNK-4-END
