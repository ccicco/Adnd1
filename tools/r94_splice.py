#!/usr/bin/env python3
# R94-CHUNK-1-START
# R94 "THE NERVE" splice - the hire's loyalty lives on the
# career events. Content-anchored, idempotent.
# Patch groups (5 files):
#   game/party.h     - clampLoyalty + loyaltyDrift + the
#                      event deltas (deep descent -2, delve
#                      completed +3, hard watch -1)
#   game/state_core.cpp - descend(): a NEW deepest record
#                      wears on the hire
#   game/state_town.cpp - enterTown: a completed delve lifts
#                      him; a bitten road wears on him
#   game/state_dungeon.cpp - an interrupted camp wears on him
#   regtest.cpp      - "R94 nerve audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
# DESIGN: loyalty range 0..125 (the loader's existing bounds).
# The deltas are small and directional: success pays, the
# unlit deeps and frightened watches cost. The quit checks
# (<25 in billTownVisit, the d100 gate in leaveTown) are
# unchanged - they now see a living stat. Save format
# unchanged (loyalty was already saved); a mid-session load
# restores the drifted value.
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
# 1) party.h - the loyalty drift helpers
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""// R93: the deepest-depth tracker (career; depth 1 counts -
// a first delve is a delve)
inline int deepestOf(int cur, int level) {
    return level > cur ? level : cur;
}""",
"""// R93: the deepest-depth tracker (career; depth 1 counts -
// a first delve is a delve)
inline int deepestOf(int cur, int level) {
    return level > cur ? level : cur;
}

// R94: the hire's loyalty drift. Range 0..125 (the loader's
// existing bounds); clampLoyalty keeps every drift in range.
inline int clampLoyalty(int loy) {
    if (loy < 0) return 0;
    if (loy > 125) return 125;
    return loy;
}

inline int loyaltyDrift(int loy, int delta) {
    return clampLoyalty(loy + delta);
}

// R94: the career events that move him - a NEW deepest
// record costs 2 (the unlit deeps wear), a completed delve
// pays 3 (shared success, and the purse), a frightened
// watch (interrupted camp or a bitten road) costs 1.
inline int loyaltyDriftDeepDescent() { return -2; }
inline int loyaltyDriftDelveDone()   { return  3; }
inline int loyaltyDriftHardWatch()   { return -1; }""",
'party.h loyalty helpers')
# R94-CHUNK-1-END
# R94-CHUNK-2-START

# ---------------------------------------------------------------------------
# 2) state_core.cpp - a new deepest record wears on the hire
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""void AppState::descend(){
        ++dungeonLevel;
        // R93: the career ledger tracks the deepest level
        party.deepestLevel =
            deepestOf(party.deepestLevel, dungeonLevel);
        log.add("You descend the worn stairs...");""",
"""void AppState::descend(){
        ++dungeonLevel;
        // R93: the career ledger tracks the deepest level
        int before = party.deepestLevel;
        party.deepestLevel =
            deepestOf(party.deepestLevel, dungeonLevel);
        // R94: a NEW deepest record wears on the hire (only
        // a record moves him - treading known halls does not)
        if (party.deepestLevel > before &&
            party.henchmanPresent && party.henchmanHp > 0) {
            party.henchmanLoyalty = loyaltyDrift(
                party.henchmanLoyalty,
                loyaltyDriftDeepDescent());
            char lb[96];
            snprintf(lb, sizeof lb,
                     "The unlit deeps weigh on %s.",
                     party.henchmanName.c_str());
            log.add(lb);
        }
        log.add("You descend the worn stairs...");""",
'state_core.cpp deep descent drift')

# ---------------------------------------------------------------------------
# 3) state_town.cpp - the completed delve lifts him; the
#    bitten road wears on him
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        if (dm::wanderCheck(dice, wander)) {
            log.add("Something follows you to the stairs!");
            spawnWanderingEncounter();
            return;   // the town can wait; the fight cannot
        }""",
"""        if (dm::wanderCheck(dice, wander)) {
            log.add("Something follows you to the stairs!");
            // R94: a frightened watch costs him a little nerve
            if (party.henchmanPresent && party.henchmanHp > 0)
                party.henchmanLoyalty = loyaltyDrift(
                    party.henchmanLoyalty,
                    loyaltyDriftHardWatch());
            spawnWanderingEncounter();
            return;   // the town can wait; the fight cannot
        }""",
'state_town.cpp bitten road drift')

OK &= patch('game/state_town.cpp',
"""        ++party.delveCount;
        party.totalGold += party.delveGold;
        char rb[128];""",
"""        ++party.delveCount;
        party.totalGold += party.delveGold;
        // R94: a completed delve lifts the hire - shared
        // success, and the purse to follow
        if (party.henchmanPresent && party.henchmanHp > 0) {
            party.henchmanLoyalty = loyaltyDrift(
                party.henchmanLoyalty,
                loyaltyDriftDelveDone());
            char lb[96];
            snprintf(lb, sizeof lb,
                     "%s is flush with the success.",
                     party.henchmanName.c_str());
            log.add(lb);
        }
        char rb[128];""",
'state_town.cpp delve done drift')

# ---------------------------------------------------------------------------
# 4) state_dungeon.cpp - the interrupted camp wears on him
# ---------------------------------------------------------------------------
OK &= patch('game/state_dungeon.cpp',
"""        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            spawnWanderingEncounter();
            return;
        }""",
"""        if (dm::wanderCheck(dice, wander)) {
            log.add("The rest is interrupted!");
            // R94: the frightened watch costs him nerve
            if (party.henchmanPresent && party.henchmanHp > 0)
                party.henchmanLoyalty = loyaltyDrift(
                    party.henchmanLoyalty,
                    loyaltyDriftHardWatch());
            spawnWanderingEncounter();
            return;
        }""",
'state_dungeon.cpp interrupted camp drift')
# R94-CHUNK-2-END
# R94-CHUNK-3-START

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the R94 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R93 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R93 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R94: nerve audit ----
    {
        int bad = 0;
        // the event deltas
        if (loyaltyDriftDeepDescent() != -2) ++bad;
        if (loyaltyDriftDelveDone()   !=  3) ++bad;
        if (loyaltyDriftHardWatch()   != -1) ++bad;
        // the clamp: 0..125 (the loader's bounds)
        if (clampLoyalty(-5) != 0) ++bad;
        if (clampLoyalty(130) != 125) ++bad;
        if (clampLoyalty(50) != 50) ++bad;
        // a simulated career: hired at 50 (CHA 10, no adj),
        // one record descent (48), a hard watch (47), then
        // the completed delve (50) - a rough delve nets even;
        // a clean one gains
        {
            int loy = 50;
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            if (loy != 48) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 47) ++bad;
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 50) ++bad;
            // a clean delve (record + done only): 48 + 3 = 51
            loy = loyaltyDrift(loy, loyaltyDriftDeepDescent());
            loy = loyaltyDrift(loy, loyaltyDriftDelveDone());
            if (loy != 51) ++bad;
        }
        // the floor holds under a cowardly streak
        {
            int loy = 1;
            for (int i = 0; i < 5; ++i)
                loy = loyaltyDrift(loy, loyaltyDriftHardWatch());
            if (loy != 0) ++bad;
        }
        printf("R94 nerve audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp nerve audit')

# ---------------------------------------------------------------------------
# 6) playverify checklist - the R94 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R94: the nerve
- [ ] With the henchman hired, descend DEEPER than ever
      before: the log shows "The unlit deeps weigh on
      <name>." (only a new record moves him - known halls
      do not).
- [ ] An interrupted camp or a bitten retreat road shows no
      line but quietly costs him 1 nerve (watch the loyalty
      figure on the town screen roster if displayed).
- [ ] A clean return shows "<name> is flush with the
      success." (+3) after the Delve #N report line.
- [ ] The existing quit checks are unchanged: loyalty below
      25 in town billing, or a failed d100 at the descent
      gate, still loses him - but the stat now moves with
      the career instead of only dunning.

## Sign-off""",
'playverify nerve section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R94 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R94-CHUNK-3-END
