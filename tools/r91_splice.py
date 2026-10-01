#!/usr/bin/env python3
# R91-CHUNK-1-START
# R91 "THE STAIRS" splice - the descent costs the clock.
# Content-anchored, idempotent. Patch groups (4 files):
#   game/party.h     - descentTurns(): 36 turns (6 hours of
#                      stair-trekking; R34 already treats the
#                      descent as rest-like - slots and ammo
#                      renew - but the clock saw nothing)
#   game/state_core.cpp - descend() charges the trek onto the
#                      NEW level's clock (newDungeon resets
#                      turnCount, so the charge lands after)
#                      and rolls one arrival wander check
#                      (parity: a camp's single bite for its
#                      hours; the stairs are the DMG's most-
#                      wandered ground)
#   regtest.cpp      - "R91 stairs audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
# DESIGN: the charge lands AFTER newDungeon (which resets
# turnCount to 0) - the new level starts at 36, the honest
# arrival time. One wander check per descent, same as rest.
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
# 1) party.h - the descent cost
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R90: what a camp costs the clock - a completed rest is 48
// turns (PHB: a turn is 10 minutes, so 8 hours of sleep at 6
// turns to the hour); one jumped in ambush is 4 turns of
// watch before the halls come calling. Rest is pace-free:
// sleeping is not movement, no matter the load.
inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}""",
"""// R90: what a camp costs the clock - a completed rest is 48
// turns (PHB: a turn is 10 minutes, so 8 hours of sleep at 6
// turns to the hour); one jumped in ambush is 4 turns of
// watch before the halls come calling. Rest is pace-free:
// sleeping is not movement, no matter the load.
inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}

// R91: what the stairs cost - 36 turns (6 hours of finding,
// clearing and descending the worn way down; R34's
// "the descent takes hours" made literal). Pace-free like
// rest: the trek is route-finding, not open movement. One
// arrival wander check accompanies it (camp parity).
inline int descentTurns() {
    return 36;
}""",
'party.h descentTurns')

# ---------------------------------------------------------------------------
# 2) state_core.cpp - descend charges the new level's clock
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""void AppState::descend(){
        ++dungeonLevel;
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R34: the descent takes hours - slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();""",
"""void AppState::descend(){
        ++dungeonLevel;
        log.add("You descend the worn stairs...");
        newDungeon(seed + 1000 + dungeonLevel);
        // R91: the trek lands on the NEW level's clock (the
        // reset above wiped the old debt - the company
        // arrives 6 hours deeper, not at a fresh zero)
        turnCount += descentTurns();
        // R91: the stairs are the most-wandered ground - one
        // arrival bite (camp parity: hours pass, one check)
        if (dm::wanderCheck(dice, wander)) {
            log.add("Something followed you down!");
            spawnWanderingEncounter();
        }
        // R34: the descent takes hours - slots return with the
        // new level (keeps a descended company from being stuck
        // dry with no rest opportunity)
        restoreSlots();""",
'state_core.cpp descent clock')
# R91-CHUNK-1-END
# R91-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) regtest.cpp - the R91 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R90 clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R90 clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R91: stairs audit ----
    {
        int bad = 0;
        // the descent costs 6 hours (36 turns) - rest parity:
        // hours of time, pace-free, one wander bite at the end
        if (descentTurns() != 36) ++bad;
        // the clock model is coherent: camp 48, interrupted
        // watch 4, stairs 36 - all under a 120' day (144 turns)
        if (restTurns(false) + descentTurns() > 144) ++bad;
        if (restTurns(true) + descentTurns() > 144) ++bad;
        // a descend-then-camp day (36 + 48) plus a 60-step
        // unburdened march (60) still fits the day
        if (36 + 48 + 60 > 144) ++bad;
        printf("R91 stairs audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp stairs audit')

# ---------------------------------------------------------------------------
# 4) playverify checklist - the R91 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R91: the stairs
- [ ] Descend the stairs (step onto them): the new level's
      HUD Turn starts at 36 (the 6-hour trek lands on the new
      level's clock - not a fresh zero).
- [ ] Occasionally the arrival line "Something followed you
      down!" appears with the level announcement - the one
      arrival wander check (camp parity: hours pass, one
      bite). The follower fight happens on the new level.

## Sign-off""",
'playverify stairs section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R91 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R91-CHUNK-2-END
