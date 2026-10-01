#!/usr/bin/env python3
# R93-CHUNK-1-START
# R93 "THE LEDGER" splice - the career ledger + return report
# + HUD laden cue. Content-anchored, idempotent.
# Patch groups (6 files):
#   game/party.h     - delveCount / deepestLevel / totalGold
#                      career fields + deepestOf helper
#   game/state_core.cpp - save "ledger" line (optional, v1
#                      compatible), load branch, descend +
#                      beginDelve track the deepest level
#   game/state_town.cpp - enterTown completes the delve in
#                      the ledger and prints the report line
#   adnd1.cpp        - HUD "Move N'" gains a * when laden
#   regtest.cpp      - "R93 ledger audit: bad 0"
#   tools/playverify_r77_r83.md - the walkthrough
# DESIGN: delveCount counts COMPLETED delves (incremented on
# the clean-road return, not the descent - a dead company
# that never returns was never a delve in the books).
# totalGold accumulates the GROSS delve take (before the
# crew's and hire's shares - the company's hauling record).
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
# 1) party.h - the career ledger fields
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""    int kills = 0;""",
"""    int kills = 0;

    // R93: the career ledger - completed delves, the
    // deepest level ever reached, and the gross gold hauled
    // over the company's life (before shares). delveCount
    // increments on the clean-road RETURN only - a company
    // that never comes back was never a delve in the books.
    int  delveCount   = 0;
    int  deepestLevel = 0;
    long totalGold    = 0;""",
'party.h ledger fields')

OK &= patch('game/party.h',
"""// R92: the road home - 12 turns per dungeon level (2 hours""",
"""// R93: the deepest-depth tracker (career; depth 1 counts -
// a first delve is a delve)
inline int deepestOf(int cur, int level) {
    return level > cur ? level : cur;
}

// R92: the road home - 12 turns per dungeon level (2 hours""",
'party.h deepestOf')

# ---------------------------------------------------------------------------
# 2) state_core.cpp - save, load, depth tracking
# ---------------------------------------------------------------------------
OK &= patch('game/state_core.cpp',
"""        fprintf(f, "gold %d kills %d potions %d depth %d\\n",
                party.gold, party.kills, party.potions,
                dungeonLevel);""",
"""        fprintf(f, "gold %d kills %d potions %d depth %d\\n",
                party.gold, party.kills, party.potions,
                dungeonLevel);
        // R93: the career ledger (optional line - v1 saves
        // load with a zeroed ledger)
        fprintf(f, "ledger %d %d %ld\\n",
                party.delveCount, party.deepestLevel,
                party.totalGold);""",
'state_core.cpp save ledger')

OK &= patch('game/state_core.cpp',
"""            } else if (strcmp(tag, "hpack") == 0) {""",
"""            } else if (strcmp(tag, "ledger") == 0) {
                // R93: optional line (v1 saves lack it)
                int dcnt = 0, ddep = 0;
                long tgold = 0;
                if (fscanf(f, "%d %d %ld", &dcnt, &ddep,
                           &tgold) != 3 ||
                    dcnt < 0 || dcnt > 99999 ||
                    ddep < 0 || ddep > 50 ||
                    tgold < 0 || tgold > 1000000000L) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (ledger).");
                    return false;
                }
                p.delveCount = dcnt;
                p.deepestLevel = ddep;
                p.totalGold = tgold;
            } else if (strcmp(tag, "hpack") == 0) {""",
'state_core.cpp load ledger')

OK &= patch('game/state_core.cpp',
"""void AppState::descend(){
        ++dungeonLevel;
        log.add("You descend the worn stairs...");""",
"""void AppState::descend(){
        ++dungeonLevel;
        // R93: the career ledger tracks the deepest level
        party.deepestLevel =
            deepestOf(party.deepestLevel, dungeonLevel);
        log.add("You descend the worn stairs...");""",
'state_core.cpp descend deepest')

OK &= patch('game/state_core.cpp',
"""        newDungeon(1);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The party of %d descends into the dungeon.",
                 (int)party.members.size());""",
"""        newDungeon(1);
        // R93: a first-level delve is still the deepest for a
        // fresh company
        party.deepestLevel =
            deepestOf(party.deepestLevel, 1);
        char buf[96];
        snprintf(buf, sizeof buf,
                 "The party of %d descends into the dungeon.",
                 (int)party.members.size());""",
'state_core.cpp beginDelve deepest')
# R93-CHUNK-1-END
# R93-CHUNK-2-START

# ---------------------------------------------------------------------------
# 3) state_town.cpp - the return completes the delve
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        turnCount += ascentTurns(dungeonLevel);
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        billTownVisit();   // R70: the shared arrival billing
    }""",
"""        turnCount += ascentTurns(dungeonLevel);
        mode = MODE_TOWN;
        log.add("You return to the town above.");
        // R93: the ledger closes the delve - count it, bank
        // the gross take, report (delveGold is the gross
        // take; the crew/hire shares are paid out of it in
        // billTownVisit below)
        ++party.delveCount;
        party.totalGold += party.delveGold;
        char rb[128];
        snprintf(rb, sizeof rb,
                 "Delve #%d complete - %d gp hauled "
                 "(career: depth %d, %ld gp).",
                 party.delveCount, party.delveGold,
                 party.deepestLevel, party.totalGold);
        log.add(rb);
        billTownVisit();   // R70: the shared arrival billing
    }""",
'state_town.cpp ledger report')

# ---------------------------------------------------------------------------
# 4) adnd1.cpp - the HUD laden cue
# ---------------------------------------------------------------------------
OK &= patch('adnd1.cpp',
"""             "Kills %d  Turn %d  Move %d'  Seed %llu  [P] quaff  "
             "[K] save  [L] load  [R] rest  [B] town",
             s.dungeonLevel, (int)s.dungeon.rooms.size(),
             s.countOccupied(), party.gold, party.potions,
             party.kills, s.turnCount, partyMoveRate(party),
             (unsigned long long)s.seed);""",
"""             "Kills %d  Turn %d  Move %d'%s  Seed %llu  [P] quaff  "
             "[K] save  [L] load  [R] rest  [B] town",
             s.dungeonLevel, (int)s.dungeon.rooms.size(),
             s.countOccupied(), party.gold, party.potions,
             party.kills, s.turnCount, partyMoveRate(party),
             partyMoveRate(party) < 120 ? "*" : "",
             (unsigned long long)s.seed);""",
'adnd1.cpp HUD laden cue')
# R93-CHUNK-2-END
# R93-CHUNK-3-START

# ---------------------------------------------------------------------------
# 5) regtest.cpp - the R93 audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R92 road audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
"""        printf("R92 road audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R93: ledger audit ----
    {
        int bad = 0;
        // the deepest tracker: monotone, never forgets
        if (deepestOf(0, 1) != 1) ++bad;    // a first delve
        if (deepestOf(1, 3) != 3) ++bad;    // deeper wins
        if (deepestOf(5, 3) != 5) ++bad;    // shallower loses
        if (deepestOf(5, 5) != 5) ++bad;    // equal holds
        // the ledger starts clean
        {
            Party p;
            if (p.delveCount != 0 || p.deepestLevel != 0 ||
                p.totalGold != 0) ++bad;
        }
        // a simulated career: 4 delves, deepest 3, gross
        // take banks - the arithmetic the report line prints
        {
            Party p;
            p.deepestLevel = deepestOf(p.deepestLevel, 1);
            p.deepestLevel = deepestOf(p.deepestLevel, 3);
            int hauls[4] = {400, 1200, 0, 800};
            for (int i = 0; i < 4; ++i) {
                ++p.delveCount;
                p.totalGold += hauls[i];
            }
            if (p.delveCount != 4) ++bad;
            if (p.deepestLevel != 3) ++bad;
            if (p.totalGold != 2400) ++bad;
        }
        printf("R93 ledger audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;""",
'regtest.cpp ledger audit')

# ---------------------------------------------------------------------------
# 6) playverify checklist - the R93 lines
# ---------------------------------------------------------------------------
OK &= patch('tools/playverify_r77_r83.md',
"""## Sign-off""",
"""## R93: the ledger
- [ ] Return to town ([B], clean road): after "You return to
      the town above." the report line prints
      "Delve #1 complete - 1200 gp hauled (career: depth 3,
      1200 gp)." - count, gross haul, career depth and
      lifetime gold. The count increments ONLY on the return
      (a bitten retreat retried does not double-count; the
      count closes on the clean road).
- [ ] Descend deeper on a later delve and the career depth
      in the report grows (never shrinks).
- [ ] HUD: when the company is laden (Move under 120') the
      status line shows "Move 60'*" - the asterisk is the
      encumbrance cue (120' shows no star).
- [ ] Save ([K]) and load ([L]): the ledger survives the
      round trip; a pre-R93 save loads with a clean ledger
      (Delve #1 on the next return).

## Sign-off""",
'playverify ledger section')

# ---------------------------------------------------------------------------
print("\n".join(REPORT))
print("R93 splice:", "ALL OK" if OK else "FAILURES PRESENT")
sys.exit(0 if OK else 1)
# R93-CHUNK-3-END
