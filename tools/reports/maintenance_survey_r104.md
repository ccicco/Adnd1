# R104 maintenance survey - line counts and verdicts

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

## R107 appendix - the lean gate

The user spotted the doubled -Wswitch warning: every
preflight compiled every Termux-visible TU twice (the R99
syntax gate + the battery build). The gate now compiles
only the build's complement (game/, ai/, spelleffects/,
treasuresim.cpp) - every TU compiles exactly once per
preflight, 36 compile passes down to 24. Coverage gain
found by the survey: monsters/MonsterXp.cpp had never
been compiled by ANY path (old gate never listed
monsters/, build links only MonsterRegistry.cpp) while
its xpForKill/xpForNpc are called from
game/state_dungeon.cpp - it joined the gate.

## Standing rules from this survey

1. Book data (encounters, xp tables) is allowed to be
   huge - it is transcription, verified against the DMG.
2. adnd1.cpp is only ever touched in a round where the
   MSVC build can gate it (still pending, R74 backlog).
3. New translation units require build changes in two
   places (preflight.sh g++ list + the MSVC project);
   headers do not. Prefer intra-file refactors.
