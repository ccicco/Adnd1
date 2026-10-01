#!/usr/bin/env python3
# R89-CHUNK-1-START
# R89 "THE SCALE + THE PACE" splice.
# Content-anchored, idempotent. Patch groups (7 files):
#   game/party.h   - coinWeightShare (10 coins per gp-unit,
#                    split across living members), memberLoad
#                    (gear + coin share), paceStepTenths;
#                    partyMoveRate sees the true load
#   game/appstate.h     - moveDebt accumulator
#   game/state_core.cpp - new-game reset clears moveDebt; [D]
#                    burden lines + Carried line show coin wt
#   game/state_town.cpp - [E] HEAVY warning sees coins too
#   adnd1.cpp      - onPartyMove: a step costs 1200/rate
#                    tenths of a turn; the wander check only
#                    fires on ticks (a 30' company is checked
#                    four times per step)
#   regtest.cpp    - "R89 pace audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
# DESIGN: coins are LIQUID - the packAdd gear gate excludes
# them by design (coin can be dropped/spent instantly); the
# burden display, the [E] warning and the pace tell the truth.
# turnCount is not saved (resets each session) - neither is
# moveDebt; consistent.
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
# 1) party.h - coin weight + the true load + the pace cost
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R88: the company's move rate - the slowest living member's
// band sets the pace (the company moves together); a dead or
// empty party is treated as unencumbered""",
"""// R89: the coin share - 10 gold coins weigh one gp unit
// (PHB p.101, 10 coins to the pound); the pooled purse is
// split evenly across the LIVING members (the hire is paid,
// not a pack mule for coin). Coins are LIQUID: the packAdd
// gear gate excludes them by design - the burden display,
// the [E] warning and the pace tell the truth instead.
inline int coinWeightShare(const Party& p) {
    int living = 0;
    for (const auto& c : p.members)
        if (c.hp > 0) ++living;
    if (living == 0) return 0;
    return p.gold / (10 * living);
}

// R89: a member's true load - worn kit, pack cargo, and his
// share of the company's coin
inline int memberLoad(const Party& p, const Character& c) {
    return carriedWeight(c) + coinWeightShare(p);
}

// R89: the pace cost of one step, tenths of a turn - a 120'
// company pays 10 (one turn per step, as ever); a 30' company
// pays 40 (four turns of dungeon time crawl past while the
// laden company shuffles, and the halls get four bites at
// the wander check)
inline int paceStepTenths(int moveRate) {
    return 1200 / moveRate;
}

// R88: the company's move rate - the slowest living member's
// band sets the pace (the company moves together); a dead or
// empty party is treated as unencumbered""",
'party.h coin/pace helpers')

OK &= patch('game/party.h',
"""        int m = items::movementForBand(
            items::encumbranceBand(carriedWeight(c),
                                   c.abilities.str));
        if (m < best) best = m;""",
"""        int m = items::movementForBand(
            items::encumbranceBand(memberLoad(p, c),
                                   c.abilities.str));
        if (m < best) best = m;""",
'party.h moveRate sees coins')

# ---------------------------------------------------------------------------
# 2) appstate.h - the pace debt accumulator
# ---------------------------------------------------------------------------
OK &= patch('game/appstate.h',
"""    int           turnCount = 0;
    uint64_t      seed = 1;""",
"""    int           turnCount = 0;
    int           moveDebt   = 0;   // R89: pace tenths owed
    uint64_t      seed = 1;""",
'appstate.h moveDebt')
# R89-CHUNK-1-END
# R89-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) state_core.cpp - reset + the dump lines
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        turnCount = 0;""",
"""        turnCount = 0;
        moveDebt   = 0;""",
'state_core.cpp reset debt')

OK &= patch('game/state_core.cpp',
"""            {
                int wt = carriedWeight(c);""",
"""            {
                // R89: the true load - kit, cargo, and the
                // member's share of the company's coin
                int wt = memberLoad(party, c);""",
'state_core.cpp burden sees coins')

OK &= patch('game/state_core.cpp',
"""        snprintf(buf, sizeof buf,
                 "Carried: %d potions, %d scrolls, %d gp.",
                 party.potions, party.scrolls, party.gold);
        log.add(buf);""",
"""        snprintf(buf, sizeof buf,
                 "Carried: %d potions, %d scrolls, %d gp "
                 "(coin %d wt each).",
                 party.potions, party.scrolls, party.gold,
                 coinWeightShare(party));
        log.add(buf);""",
'state_core.cpp carried line')

# ---------------------------------------------------------------------------
# 4) state_town.cpp - the [E] warning sees coins
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""                if (items::encumbranceBand(carriedWeight(c),
                                           c.abilities.str) ==""",
"""                if (items::encumbranceBand(memberLoad(party, c),
                                           c.abilities.str) ==""",
'state_town.cpp warning sees coins')

# ---------------------------------------------------------------------------
# 5) adnd1.cpp - the pace: steps cost tenths of a turn
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""    s.party.x = nx;
    s.party.y = ny;
    s.cam.follow(s.party);
    ++s.turnCount;
""",
"""    s.party.x = nx;
    s.party.y = ny;
    s.cam.follow(s.party);
    // R89: the pace - a step costs 1200/rate tenths of a turn.
    // A 120' company ticks a full turn every step (as ever);
    // a slower one accrues debt and ticks late - the wander
    // check only fires on ticks, so the laden are bitten
    // four times per step at 30'.
    s.moveDebt += paceStepTenths(partyMoveRate(s.party));
    bool ticked = false;
    while (s.moveDebt >= 10) {
        s.moveDebt -= 10;
        ++s.turnCount;
        ticked = true;
    }
""",
'adnd1.cpp pace debt')

OK &= patch('adnd1.cpp',
"""    if (dm::wanderCheck(s.dice, s.wander)) {
        int dist = dm::wanderDistance(s.dice);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Movement in the distance... (%d ft)", dist);
        s.log.add(buf);
        s.spawnWanderingEncounter();
    }
}""",
"""    if (ticked && dm::wanderCheck(s.dice, s.wander)) {
        int dist = dm::wanderDistance(s.dice);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "Movement in the distance... (%d ft)", dist);
        s.log.add(buf);
        s.spawnWanderingEncounter();
    }
}""",
'adnd1.cpp gated wander')
# R89-CHUNK-2-END
# R89-CHUNK-3-START

# ---------------------------------------------------------------------------
# 6) regtest.cpp - the R89 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R88 warning audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R88 warning audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R89: pace audit ----
    {
        int bad = 0;
        // the coin share: 10 coins per gp unit, split across
        // the living only
        {
            Party p;
            if (coinWeightShare(p) != 0) ++bad;   // no gold
            p.gold = 4000;
            if (coinWeightShare(p) != 0) ++bad;   // nobody living
            Character a, b2, c2, d2;
            a.hp = 10; b2.hp = 10; c2.hp = 10; d2.hp = 10;
            p.members.push_back(a);
            p.members.push_back(b2);
            p.members.push_back(c2);
            p.members.push_back(d2);
            if (coinWeightShare(p) != 100) ++bad;  // 4000/10/4
            p.members[3].hp = 0;                   // the dead
            if (coinWeightShare(p) != 133) ++bad;  // 4000/10/3
            p.gold = 4999;                         // floor
            if (coinWeightShare(p) != 166) ++bad;  // 4999/30
        }
        // the true load: kit + cargo + coin share
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            // default kit: dagger 20 gp
            if (memberLoad(p, c) != 20) ++bad;
            p.gold = 1000;
            if (memberLoad(p, c) != 120) ++bad;    // +100 coin
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            c.pack.push_back(sw);
            if (memberLoad(p, c) != 195) ++bad;    // +75 cargo
        }
        // the pace cost: 120'->10, 90'->13, 60'->20, 30'->40
        if (paceStepTenths(120) != 10) ++bad;
        if (paceStepTenths(90)  != 13) ++bad;
        if (paceStepTenths(60)  != 20) ++bad;
        if (paceStepTenths(30)  != 40) ++bad;
        // coins slow the company: a lone STR 10 member hauling
        // 20,000 gp carries 2000 wt -> HEAVY -> 30' -> four
        // wander bites per step
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            if (partyMoveRate(p) != 120) ++bad;
            p.gold = 20000;
            if (partyMoveRate(p) != 30) ++bad;
            if (paceStepTenths(partyMoveRate(p)) != 40) ++bad;
            // spending it all in town is instant relief
            p.gold = 0;
            if (partyMoveRate(p) != 120) ++bad;
        }
        printf("R89 pace audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp pace audit')

# ---------------------------------------------------------------------------
# 7) playverify checklist - the R89 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R89: the scale + the pace
- [ ] [D] dump kit: the "Carried:" line now ends
      "(coin N wt each)" - the purse weighs (10 coins per
      gp unit, split across living members).
- [ ] Burden lines count the coin share: a lone member
      hauling 20,000 gp shows "heavily burdened (2020 gp wt,
      move 30')" and the HUD Move reads 30'.
- [ ] Spend the purse in town and the company springs back to
      120' instantly (coin is liquid).
- [ ] The pace is mechanical: watch Turn on the HUD while
      walking - an unburdened company advances one turn per
      step; a 30' company gains four turns per step (wander
      checks fire only on turns - the laden are interrupted
      far more often; watch "Movement in the distance..." and
      count turns per step).

## Sign-off""",
'playverify pace section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R89 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R89-CHUNK-3-END
