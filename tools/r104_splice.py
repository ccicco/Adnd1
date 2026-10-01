#!/usr/bin/env python3
# R104 the scales (MAINTENANCE): the line-count survey of
# the whole repo, and the one refactor it justified.
#
# THE SURVEY (verdicts in tools/maintenance_survey_r104.md):
#   dm/encounters.cpp  4214 - ~75% verbatim DMG book tables
#                              (data, not debt - leave)
#   adnd1.cpp          1699 - the Win32/GDI shell, ungated
#                              on Termux (defer to MSVC round)
#   regtest.cpp        1489 - linear audit battery (by design)
#   game/state_town.cpp 1232 - 28 linear shops - the ONE
#                              real debt: the spend-guard
#                              pattern x18
#   game/appstate.h    1199 - interface (leave)
#   others            <1120 - healthy
# THE REFACTOR: spendGold(party, log, cost, refusal) in
# party.h; all 18 shop sites converted; the sage's toll
# moved AFTER the empty-lore check (his true position -
# the old order could promise a price before knowing there
# was stock; no gold ever moved in that corner either way).
# The upkeep site (billed on return) and the crew-wages site
# are NOT shop spends - they stay as they are.
#
# Patches (20) + the survey doc (new file).
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

def put_file(path, content, label):
    global OK
    if os.path.exists(path):
        print(label + ': already present')
        return True
    wr(path, content)
    print(label + ': written')
    return True

# ---------------------------------------------------------------------------
# 1) party.h - the scales
# ---------------------------------------------------------------------------
OK &= patch('game/party.h',
"""inline int loyaltyGift() { return  5; }
inline int loyaltyRaise() { return 10; }
inline int henchmanUpkeep(int level, bool hasRaise) {
    return 100 * level + (hasRaise ? 100 : 0);
}
""",
"""inline int loyaltyGift() { return  5; }
inline int loyaltyRaise() { return 10; }
inline int henchmanUpkeep(int level, bool hasRaise) {
    return 100 * level + (hasRaise ? 100 : 0);
}

// R104: the town's scales - every shop asks the same
// question of the purse; this is the single asking (the
// maintenance survey found the guard-and-spend pattern
// repeated across eighteen town shops).
inline bool spendGold(Party& p, MessageLog& log, int cost,
                      const std::string& refusal) {
    if (p.gold < cost) {
        log.add(refusal);
        return false;
    }
    p.gold -= cost;
    return true;
}
""",
'party.h the scales')

# ---------------------------------------------------------------------------
# 2-19) the eighteen shops
# ---------------------------------------------------------------------------
OK &= patch('game/state_town.cpp',
"""        if (party.gold < 50) {
            log.add("The priest shakes his head - 50 gp.");
            return;
        }
        party.gold -= 50;
""",
"""        if (!spendGold(party, log, 50,
                "The priest shakes his head - 50 gp."))
            return;
""",
'potion shop')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 30) {
            log.add("The fletcher wants 30 gp.");
            return;
        }
        party.gold -= 30;
""",
"""        if (!spendGold(party, log, 30,
                "The fletcher wants 30 gp."))
            return;
""",
'fletcher')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 10) {
            log.add("The innkeeper wants 10 gp for the night.");
            return;
        }
        party.gold -= 10;
""",
"""        if (!spendGold(party, log, 10,
                "The innkeeper wants 10 gp for the night."))
            return;
""",
'inn')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 100) {
            log.add("The high priest asks 100 gp for a cure.");
            return;
        }
        party.gold -= 100;
""",
"""        if (!spendGold(party, log, 100,
                "The high priest asks 100 gp for a cure."))
            return;
""",
'temple cure')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 500) {
            log.add("The smith wants 500 gp for the enchanted "
                    "blade.");
            return;
        }
        party.gold -= 500;
""",
"""        if (!spendGold(party, log, 500,
                "The smith wants 500 gp for the enchanted "
                "blade."))
            return;
""",
'smith')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < cost) {
            char buf[96];
            snprintf(buf, sizeof buf,
                     "The training master wants %d gp.", cost);
            log.add(buf);
            return;
        }
        party.gold -= cost;
""",
"""        char tbuf[96];
        snprintf(tbuf, sizeof tbuf,
                 "The training master wants %d gp.", cost);
        if (!spendGold(party, log, cost, tbuf))
            return;
""",
'training master')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 75) {
            log.add("The armorer wants 75 gp.");
            return;
        }
        party.gold -= 75;
""",
"""        if (!spendGold(party, log, 75,
                "The armorer wants 75 gp."))
            return;
""",
'armorer')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 200) {
            log.add("The scribe wants 200 gp.");
            return;
        }
        party.gold -= 200;
""",
"""        if (!spendGold(party, log, 200,
                "The scribe wants 200 gp."))
            return;
""",
'scribe scroll')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 10000) {
            log.add("The masons want 10,000 gp for the keep.");
            return;
        }
        party.gold -= 10000;
""",
"""        if (!spendGold(party, log, 10000,
                "The masons want 10,000 gp for the keep."))
            return;
""",
'masons')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 100) {
            log.add("The scribe wants 100 gp for the scroll.");
            return;
        }
        party.gold -= 100;
""",
"""        if (!spendGold(party, log, 100,
                "The scribe wants 100 gp for the scroll."))
            return;
""",
'identify scroll')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 100) {
            log.add("The crier wants 100 gp to post the "
                    "offer.");
            return;
        }
        party.gold -= 100;
""",
"""        if (!spendGold(party, log, 100,
                "The crier wants 100 gp to post the offer."))
            return;
""",
'crier')

# the sage: the toll moves AFTER the empty-lore check (his
# true position - pre-R104 checked gold before knowing
# there was lore; no gold ever moved in that corner)
OK &= patch('game/state_town.cpp',
"""        if (party.gold < 200) {
            log.add("The sage wants 200 gp for his lore.");
            return;
        }
        auto keys = dm::encounterKeys(registry, dungeonLevel);
        if (keys.empty()) {
            log.add("The sage knows nothing of this depth.");
            return;
        }
        party.gold -= 200;
""",
"""        auto keys = dm::encounterKeys(registry, dungeonLevel);
        if (keys.empty()) {
            log.add("The sage knows nothing of this depth.");
            return;
        }
        if (!spendGold(party, log, 200,
                "The sage wants 200 gp for his lore."))
            return;
""",
'sage')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 500) {
            log.add("The spy wants 500 gp for the mission.");
            return;
        }
        party.gold -= 500;
""",
"""        if (!spendGold(party, log, 500,
                "The spy wants 500 gp for the mission."))
            return;
""",
'spy')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 500) {
            log.add("The peddler wants 500 gp for the item.");
            return;
        }
        party.gold -= 500;
""",
"""        if (!spendGold(party, log, 500,
                "The peddler wants 500 gp for the item."))
            return;
""",
'peddler')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 25) {
            log.add("A gift wants 25 gp - the purse is "
                    "too thin.");
            return;
        }
        party.gold -= 25;
""",
"""        if (!spendGold(party, log, 25,
                "A gift wants 25 gp - the purse is "
                "too thin."))
            return;
""",
'the gift')

OK &= patch('game/state_town.cpp',
"""            if (party.gold < 500) {
                char buf[96];
                snprintf(buf, sizeof buf,
                         "A raise costs 500 gp - the purse "
                         "holds %d.", party.gold);
                log.add(buf);
                return;
            }
            party.gold -= 500;
""",
"""            char rbuf[96];
            snprintf(rbuf, sizeof rbuf,
                     "A raise costs 500 gp - the purse "
                     "holds %d.", party.gold);
            if (!spendGold(party, log, 500, rbuf))
                return;
""",
'the raise')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 200) {
            log.add("The harbormaster wants 200 gp to sign "
                    "a crew.");
            return;
        }
        party.gold -= 200;
""",
"""        if (!spendGold(party, log, 200,
                "The harbormaster wants 200 gp to sign "
                "a crew."))
            return;
""",
'harbormaster')

OK &= patch('game/state_town.cpp',
"""        if (party.gold < 1000) {
            log.add("The temple demands a 1,000 gp offering "
                    "for the rite.");
            return;
        }
        party.gold -= 1000;
""",
"""        if (!spendGold(party, log, 1000,
                "The temple demands a 1,000 gp offering "
                "for the rite."))
            return;
""",
'raise dead')

# ---------------------------------------------------------------------------
# 20) regtest.cpp - the scales audit
# ---------------------------------------------------------------------------
OK &= patch('regtest.cpp',
"""        printf("R103 carrot audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
"""        printf("R103 carrot audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R104: scales audit ----
    {
        int bad = 0;
        Party p;
        MessageLog log;
        // a short purse refuses, moves no gold, and the
        // refusal is the shop's own words
        p.gold = 49;
        if (spendGold(p, log, 50,
                      "The priest shakes his head - 50 gp."))
            ++bad;
        if (p.gold != 49) ++bad;
        if (log.get(0) !=
            "The priest shakes his head - 50 gp.") ++bad;
        // exact coin spends to zero
        p.gold = 50;
        if (!spendGold(p, log, 50, "The fletcher wants 30 gp."))
            ++bad;
        if (p.gold != 0) ++bad;
        // a fat purse pays and keeps the change
        p.gold = 200;
        if (!spendGold(p, log, 75, "The armorer wants 75 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        // and refuses at 125 what it afforded at 200
        if (spendGold(p, log, 126, "The scribe wants 200 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        if (log.get(0) != "The scribe wants 200 gp.") ++bad;
        printf("R104 scales audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
""",
'regtest.cpp scales audit')

# ---------------------------------------------------------------------------
# 21) the survey, in-repo
# ---------------------------------------------------------------------------
SURVEY = """# R104 maintenance survey - line counts and verdicts

Date: R104 (after the R103 carrot). Repo total ~21,841
lines of C++ (source + headers, tools excluded).

## The ledger

| File                | Lines | Verdict                                   |
|---------------------|-------|-------------------------------------------|
| dm/encounters.cpp   | 4214  | ~75% verbatim DMG App. C tables - data,   |
|                     |       | not debt. Leave (book transcription).     |
| adnd1.cpp           | 1699  | The Win32/GDI shell. Ungated on Termux     |
|                     |       | (needs windows.h); refactor deferred to    |
|                     |       | the MSVC verify round - never blind.      |
| regtest.cpp         | 1489  | The audit battery - linear, append-only   |
|                     |       | by design (one section per round). Leave. |
| game/state_town.cpp  | 1232  | 28 linear shops - healthy shape, ONE debt: |
|                     |       | the spend-guard pattern x18 -> refactored  |
|                     |       | to spendGold() this round (~60 lines and  |
|                     |       | a whole error-class gone).                |
| game/appstate.h     | 1199  | Interface + state structs. Leave.         |
| game/state_dungeon  | 1120  | Logic, cohesive. Leave.                   |
| ai/actor.cpp        | 1072  | Logic, cohesive. Leave.                   |
| dm/treasure.cpp    | 1037  | Mostly treasure tables + logic. Leave.    |
| game/party.h        |  931  | Structs + inline rules helpers. Leave.     |
| game/state_core.cpp |  913  | Save/load. Leave (contract is pinned by    |
|                     |       | the battery).                             |
| all others          | < 900 | Healthy.                                  |

## What was refactored (R104 "the scales")

spendGold(party, log, cost, refusal) in game/party.h; all
18 town shop sites converted. The sage's toll moved AFTER
the empty-lore check (his true position - the old order
priced the question before knowing there was stock; no
gold ever moved in that corner either way). The upkeep
site (billed on return) and crew wages are not shop spends
and stay as they are. Shop behavior is unchanged - same
prices, same refusals, same purse math; the R104 scales
audit pins it.

## Standing rules from this survey

1. Book data (encounters, xp tables) is allowed to be
   huge - it is transcription, verified against the DMG.
2. adnd1.cpp is only ever touched in a round where the
   MSVC build can gate it (still pending, R74 backlog).
3. New translation units require build changes in two
   places (preflight.sh g++ list + the MSVC project);
   headers do not. Prefer intra-file refactors.
"""
OK &= put_file('tools/maintenance_survey_r104.md', SURVEY,
               'survey doc')

# ---------------------------------------------------------------------------
print()
if OK:
    print('R104 splice: ALL OK')
    sys.exit(0)
else:
    print('R104 splice: FAILED')
    sys.exit(1)
