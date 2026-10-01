#!/usr/bin/env python3
# R90-CHUNK-1-START
# R90 "THE CAMP CLOCK" splice - actions charge dungeon time.
# Content-anchored, idempotent. Patch groups (6 files):
#   game/party.h        - restTurns(bool interrupted): 48
#                         turns for a full camp (PHB 8 hours
#                         at 6 turns/hour), 4 when jumped;
#                         ticksFromDebt: the shared R89 tick
#                         math, now callable from tests
#   adnd1.cpp           - onPartyMove refactors onto
#                         ticksFromDebt (behavior identical)
#   game/state_dungeon.cpp - restExplore charges the clock:
#                         48 turns on a completed camp, 4 on
#                         an interrupted one (the single
#                         interrupt roll is unchanged)
#   game/state_combat.cpp - quaffExplore costs one turn and
#                         draws a wander bite (drinking in
#                         the halls is not free)
#   regtest.cpp         - "R90 clock audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
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
# 1) party.h - the shared clock math (testable free functions)
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R89: the pace cost of one step, tenths of a turn - a 120'
// company pays 10 (one turn per step, as ever); a 30' company
// pays 40 (four turns of dungeon time crawl past while the
// laden company shuffles, and the halls get four bites at
// the wander check)
inline int paceStepTenths(int moveRate) {
    return 1200 / moveRate;
}""",
"""// R89: the pace cost of one step, tenths of a turn - a 120'
// company pays 10 (one turn per step, as ever); a 30' company
// pays 40 (four turns of dungeon time crawl past while the
// laden company shuffles, and the halls get four bites at
// the wander check)
inline int paceStepTenths(int moveRate) {
    return 1200 / moveRate;
}

// R89/R90: the shared tick math - charge stepTenths onto the
// debt and return how many whole turns ticked. Kept here (not
// in adnd1.cpp) so the clock model is one function, used by
// the move path and pinned by the regtest.
inline int ticksFromDebt(int& moveDebt, int stepTenths) {
    moveDebt += stepTenths;
    int t = 0;
    while (moveDebt >= 10) {
        moveDebt -= 10;
        ++t;
    }
    return t;
}

// R90: what a camp costs the clock - a completed rest is 48
// turns (PHB: a turn is 10 minutes, so 8 hours of sleep at 6
// turns to the hour); one jumped in ambush is 4 turns of
// watch before the halls come calling. Rest is pace-free:
// sleeping is not movement, no matter the load.
inline int restTurns(bool interrupted) {
    return interrupted ? 4 : 48;
}""",
'party.h clock helpers')
# R90-CHUNK-1-END
# R90-CHUNK-2-START

# ---------------------------------------------------------------------------
# 2) adnd1.cpp - the move path refactors onto ticksFromDebt
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""    s.moveDebt += paceStepTenths(partyMoveRate(s.party));
    bool ticked = false;
    while (s.moveDebt >= 10) {
        s.moveDebt -= 10;
        ++s.turnCount;
        ticked = true;
    }
""",
"""    int ticked = ticksFromDebt(s.moveDebt,
                               paceStepTenths(
                                   partyMoveRate(s.party)));
    s.turnCount += ticked;
""",
'adnd1.cpp ticks refactor')

# ---------------------------------------------------------------------------
# 3) state_dungeon.cpp - the camp charges the clock
# ---------------------------------------------------------------------------
OK &= patch('game/state_dungeon.cpp',
"""        log.add("The party makes camp...");
        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            spawnWanderingEncounter();
            return;
        }""",
"""        log.add("The party makes camp...");
        // R90: the interrupted camp still burns watch turns
        turnCount += restTurns(true);
        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            spawnWanderingEncounter();
            return;
        }""",
'state_dungeon.cpp interrupted camp')

OK &= patch('game/state_dungeon.cpp',
"""        log.add("The company rests. Spells and wounds mend.");
    }""",
"""        // R90: a completed camp costs 48 turns (8 hours) -
        // the clock finally sees sleep (rest is pace-free)
        turnCount += restTurns(false);
        log.add("The company rests. Spells and wounds mend.");
    }""",
'state_dungeon.cpp camp clock')

# ---------------------------------------------------------------------------
# 4) state_combat.cpp - quaffing costs a turn and a bite
# ---------------------------------------------------------------------------
OK &= patch('game/state_combat.cpp',
"""        snprintf(buf, sizeof buf,
                 "%s quaffs a potion (+%d hp, now %d/%d, %d left).",
                 best->name.c_str(), best->hp - before,
                 best->hp, best->maxHp, party.potions);
        log.add(buf);
    }""",
"""        snprintf(buf, sizeof buf,
                 "%s quaffs a potion (+%d hp, now %d/%d, %d left).",
                 best->name.c_str(), best->hp - before,
                 best->hp, best->maxHp, party.potions);
        log.add(buf);
        // R90: drinking in the halls costs a turn - and the
        // turn can draw a wanderer (search parity)
        turnCount += 1;
        if (dm::wanderCheck(dice, wander))
            spawnWanderingEncounter();
    }""",
'state_combat.cpp quaff clock')
# R90-CHUNK-2-END
# R90-CHUNK-3-START

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the R90 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R89 pace audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R89 pace audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R90: clock audit ----
    {
        int bad = 0;
        // the camp costs: 48 turns complete, 4 interrupted
        if (restTurns(false) != 48) ++bad;
        if (restTurns(true)  != 4)  ++bad;
        // the tick math: a 90' company (13 tenths/step) ticks
        // late but never loses time - 10 steps = 13 turns
        {
            int debt = 0;
            int ticks = 0;
            for (int i = 0; i < 10; ++i)
                ticks += ticksFromDebt(debt, 13);
            if (ticks != 13 || debt != 0) ++bad;
        }
        // a 30' company (40 tenths) ticks 4 per step, no debt
        {
            int debt = 0;
            if (ticksFromDebt(debt, 40) != 4) ++bad;
            if (debt != 0) ++bad;
        }
        // a 120' company (10 tenths) ticks exactly 1 per step
        {
            int debt = 0;
            for (int i = 0; i < 100; ++i) {
                if (ticksFromDebt(debt, 10) != 1) ++bad;
                if (debt != 0) ++bad;
            }
        }
        // the debt never leaks across an odd pace change:
        // 3 steps at 13 -> 3 ticks, debt 9; one more at 10
        // -> 9+10=19 -> a tick, debt 9 again (the remainder
        // carries; time is conserved, never lost)
        {
            int debt = 0;
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 13->3
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 16->6
            if (ticksFromDebt(debt, 13) != 1) ++bad;   // 19->9
            if (debt != 9) ++bad;
            if (ticksFromDebt(debt, 10) != 1) ++bad;  // 19->9
            if (debt != 9) ++bad;
        }
        printf("R90 clock audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp clock audit')

# ---------------------------------------------------------------------------
# 6) playverify checklist - the R90 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R90: the camp clock
- [ ] Rest in the dungeon ([R]): on success the HUD Turn jumps
      by 48 (8 hours of camp - sleep finally costs time); an
      interrupted rest ("The rest is interrupted!") jumps it
      by 4 (the watch before the ambush).
- [ ] Quaff a potion in the dungeon ([P]): Turn advances by
      1 and the quaff can draw "Movement in the distance..."
      (drinking in the halls is not free; combat quaffs are
      unchanged - combat time is the round system).
- [ ] Walking behavior is unchanged from R89 (one turn per
      step unburdened, four at 30') - the refactor onto the
      shared tick math must be invisible.

## Sign-off""",
'playverify clock section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R90 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R90-CHUNK-3-END
