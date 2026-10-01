#!/usr/bin/env python3
# R92-CHUNK-1-START
# R92 "THE ROAD HOME" splice - the retreat costs the clock.
# Content-anchored, idempotent. Patch groups (4 files):
#   game/party.h     - ascentTurns(levels): 12 turns per
#                      level (2 hours of climbing the worn
#                      ways back; stairs descent parity)
#   game/state_town.cpp - enterTown charges the climb and
#                      rolls one road wander check BEFORE
#                      the mode switch (an interrupted
#                      retreat stays in the dungeon)
#   regtest.cpp      - "R92 road audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
# DESIGN: the check rolls before mode = MODE_TOWN, so a
# followed company fights on the level it stood on. The
# climb is pace-free (route-finding, stairs parity). Turn
# and debt are session-scoped in town anyway (enterTown
# ends the delve's clock).
# All anchors and inserted text are ASCII-only (protocol rule).

import sys, os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
REPORT = []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='utf-8') as f:
        f.write(s)

def patch(fname, old, new, tag, count=1):
    s = rd(fname)
    if new in s:
        REPORT.append("%s: already patched" % tag)
        return True
    n = s.count(old)
    if n != count:
        REPORT.append("%s: FAIL (anchor x%d, want %d)" % (tag, n, count))
        return False
    wr(fname, s.replace(old, new, count))
    REPORT.append("%s: patched" % tag)
    return True

OK = True

# ---------------------------------------------------------------------------
# 1) party.h - the ascent cost
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R91: what the stairs cost - 36 turns (6 hours of finding,
// clearing and descending the worn way down; R34's
// "the descent takes hours" made literal). Pace-free like
// rest: the trek is route-finding, not open movement. One
// arrival wander check accompanies it (camp parity).
inline int descentTurns() {
    return 36;
}""",
"""// R91: what the stairs cost - 36 turns (6 hours of finding,
// clearing and descending the worn way down; R34's
// "the descent takes hours" made literal). Pace-free like
// rest: the trek is route-finding, not open movement. One
// arrival wander check accompanies it (camp parity).
inline int descentTurns() {
    return 36;
}

// R92: the road home - 12 turns per dungeon level (2 hours
// of climbing the worn ways back; the ascent skips the
// clearing and searching the descent spends, hence a third
// of descentTurns per level). Pace-free (stairs parity),
// one road wander check - rolled BEFORE the town switch so
// a followed company fights where it stands.
inline int ascentTurns(int dungeonLevel) {
    return 12 * dungeonLevel;
}""",
'party.h ascentTurns')

# ---------------------------------------------------------------------------
# 2) state_town.cpp - enterTown charges the climb
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""void AppState::enterTown(){
        if (mode != MODE_EXPLORE) return;
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        billTownVisit();   // R70: the shared arrival billing
    }""",
"""void AppState::enterTown(){
        if (mode != MODE_EXPLORE) return;
        // R92: the road home - the climb costs the delve's
        // clock 12 turns per level (2h each), and the road
        // gets one wander bite. The check rolls BEFORE the
        // mode switch: a followed company fights on the level
        // it stands on, not in the streets. The clock charge
        // lands on the CLEAN road only - a bitten retreat
        // costs combat rounds, and the post-fight [B] must
        // not charge the climb twice.
        if (dm::wanderCheck(dice, wander)) {
            log.add("Something follows you to the stairs!");
            spawnWanderingEncounter();
            return;   // the town can wait; the fight cannot
        }
        turnCount += ascentTurns(dungeonLevel);
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        billTownVisit();   // R70: the shared arrival billing
    }""",
'state_town.cpp road home')
# R92-CHUNK-1-END
# R92-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) regtest.cpp - the R92 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R91 stairs audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R91 stairs audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R92: road audit ----
    {
        int bad = 0;
        // the climb: 12 turns per level
        if (ascentTurns(1) != 12) ++bad;
        if (ascentTurns(3) != 36) ++bad;
        if (ascentTurns(6) != 72) ++bad;
        // stairs symmetry: one descent (36) out-climbs three
        // levels of ascent (36) - the way down clears ground,
        // the way up re-walks it
        if (descentTurns() != ascentTurns(3)) ++bad;
        // a deep delve is expensive to leave: level 10 costs
        // 120 turns (20 hours - a full adventuring day)
        if (ascentTurns(10) != 120) ++bad;
        // clock-model coherence: a shallow delve (descend 36
        // + climb 12 + camp 48 = 96) fits a 144-turn day;
        // a deep delve to 6 does NOT (36 + 72 + 48 = 156) -
        // multi-day delves are the honest consequence of depth
        if (descentTurns() + ascentTurns(1) + restTurns(false)
            > 144) ++bad;
        if (descentTurns() + ascentTurns(6) + restTurns(false)
            <= 144) ++bad;
        printf("R92 road audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp road audit')

# ---------------------------------------------------------------------------
# 4) playverify checklist - the R92 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R92: the road home
- [ ] Retreat to town ([B]): the return is no longer instant -
      rarely "Something follows you to the stairs!" fires and
      the fight happens ON the dungeon level (press [B] again
      after winning to finish the climb; the mode only
      switches on a clean road).
- [ ] A normal return still reads "You return to the town
      above." with the billing lines (rents, henchman pay).

## Sign-off""",
'playverify road section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R92 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R92-CHUNK-2-END
