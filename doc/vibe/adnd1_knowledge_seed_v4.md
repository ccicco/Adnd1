---
name: adnd1-splice-work
description: Curtiss's Adnd1 repo pin-round workflow - the splice ritual conventions, verification steps, and standing decisions (v4, rebuilt at the R1043 fresh start)
---

# Adnd1 splice work (v4, rebuilt at the R1043 fresh start)

Rebuilt at the R1043 fresh start (v4, 2026-11-14, commit
8972cdba, census 1022). The v3 era snapshot lives in the repo
at doc/vibe/adnd1_knowledge_backup_v4.md (the full pre-restart
topic: the conventions, the lessons, the R849-R1026 increment
with every round record, the G1 arc, the 2026-11-11 reorg and
miscmagic arcs, and the R1027-R1033 de-wire records), and the
paused G1 module arc lives in g1-arc.md in this topic. The
older snapshots remain: adnd1_knowledge_backup_v3.md (the
R600-R848 topic + the v2 seed records R313-R847) and
adnd1_knowledge_backup_v2.md (R172-R312). Reference them on
demand, never load wholesale.

## Ritual rules (standing decisions)

- **No editor or launcher step belongs in the ritual.** The ritual
  block contains only the verification commands (md5sum,
  py_compile, awk, tail, the double-run, preflight,
  git add/commit/push). NEVER demote preflight to a
  comment placeholder: it is ./tools/preflight.sh,
  invoked as its own command line between the
  double-run and git add - the ONLY step that
  compiles the C++ and executes the audit (the
  engine only re-parses in Python). R429 and R430
  rituals carried preflight as a comment only and
  both lands happened WITHOUT it running (both
  verified clean afterward, but that was luck, not
  the R392 rule); corrected 2026-10-14. The
  user saves the canvas body to
  `tools/rXXX_splice.py` by their own means; never include a
  nano/save step or an `./nn` launcher step. (nano struck twice,
  set in R369, 2026-10-12; `./nn` struck in R372, 2026-10-12.)
  **`./bn` is ALSO struck from the ritual** (user-set R516,
  reaffirmed 2026-10-17 mid-R541 after the R541 handoff drifted
  and re-included it): the user saves the canvas spec body to
  tools/spec_rXXX.json by their own means; the ritual starts at
  md5sum, and the md5sum gate expects the AUTHORED md5 exactly
  (no bn whitespace rewrite). The ritual block is: md5sum,
  the double engine run, ./tools/preflight.sh,
  git add/commit/push, git log - nothing before md5sum.
  The delivered handoff is ONE line ONLY: ./rn NNN '<msg>'
  (reaffirmed 2026-10-17 at R575 after the R575 handoff drifted
  and showed a ./bn line above the ./rn line - no extra lines,
  no pre-ritual commands in the handoff; reaffirmed again
  2026-10-24 at R804 after the R804 handoff drifted and
  re-included a ./bn line - the md5sum may be quoted as
  prose for the byte check, but the handoff block is the
  one ./rn line only).
- The splice file is <=78 columns except the embedded header opener
  line (92 chars). Idempotent: run twice -> applied N, already 0
  then applied 0, already N.
- Every splice: (a) insert the previous round's record into the
  seed before `## Knowledge maintenance`; (b) write new pin
  header(s) in rules/; (c) flip gap-report items; (d) regtest.cpp
  include + audit block before the R227 anchor; census
  `audit: bad ` count increments.
- Commit message: `RXXX: <the round title> (census N)`.
- **WAIT FOR GO before preparing the next round**
  (user-set 2026-10-22 at R765, after the R765
  landing was answered with an unprompted R766
  preparation): when the user pastes a landing
  output, the turn's work is seating the landed
  record into the Knowledge file and then
  STOPPING - report the seating, and prepare
  the next round ONLY when the user says go (or
  otherwise asks for the next round). Never start
  fetching, capture-hunting, or spec authoring
  for the next round unbidden.
- Preflight must show SYNTAX-OK, the census count, the round's
  `bad 0` label, GREEN.
- **Prose codifies: the spec vocabulary is a prose-to-code
  calculus, not a data format** (user-confirmed insight,
  2026-10-14, proven by R431). Any rule stated as 'X every N
  turns / a Y-in-Z chance / a +/-k modifier /
  condition-then-consequence' maps onto consts + bools +
  examples, with or without a printed grid; the audit mirror
  verifies each prose pin like a table cell (mutate it and the
  battery must go RED). Consequence: NO section of the book
  is unpinnable - there are no 'prose-only, cannot codify'
  gaps, only rounds with different const/bool-to-table
  ratios. A pure-prose round is just build_spec_general with
  empty tables/chains.

## Verification lessons

- TABLE TAGS MUST BE C++-IDENTIFIER-SAFE (the R639
  lesson, 2026-10-19): the splice engine and the
  rverify battery are Python-only - they never
  compile the emitted audit block, so a table tag
  with a hyphen (the ten-grid R639 first cut used
  T47-Armor, T47-Arms, ...) sails through the
  engine double-run and the mutant battery, then
  dies at the Termux preflight compile ("int
  CT47-Armor[28][3]" - invalid identifier, 20
  errors, preflight RED, nothing committed). The
  termux preflight is the ONLY C++ compile gate.
  Standing rule: a table tag must match
  [A-Za-z0-9_]+ (CamelCase like T47Armor when one
  printed table splits into several grids); scan
  the emitted audit block for hyphen tokens in
  code lines before publishing. REPAIR FLOW for a
  RED-no-commit round: GitHub stays at the base
  sha; the user resets the patched working tree
  first (git checkout -- regtest.cpp
  tools/oa_gap_report.md doc/vibe/..._seed_v2.md
  and rm the new header), then saves the fixed
  spec over tools/spec_rNNN.json, gates the new
  authored-plus-newline md5, and reruns the one
  ./rn handoff.
- **A RED-NO-COMMIT FIX ALWAYS RIDES WITH ITS
  UNWIND (the R817 lesson, user-set 2026-10-24
  after the R817 re-land aborted twice)**: a
  failed ./rn leaves the tree FULLY APPLIED
  (the engine writes before preflight ever
  compiles), so the re-land of the fixed spec
  runs against the "already" state - and when
  the fix changed any EMITTED content (R817:
  36 new Count consts, inline 141 -> 177), the
  verify pass dies on the stale on-disk header
  ("the emitted header inline count drifted")
  after sailing past the R420 mixed gate on a
  uniform already. STANDING RULE: whenever a
  round lands RED and a fixed spec follows,
  the re-handoff answer ALWAYS carries the
  unwind commands as prose (git restore
  --source <base-sha> the patched tracked
  files - regtest.cpp, the gap report, the
  seed - plus rm of the new header and any new
  data files), THEN the one ./rn handoff line.
  Never assume Curtiss's tree is clean after a
  failed round; never re-issue a fix without
  the unwind. This generalizes the R816
  re-land detour (2) and the R812 idempotent-
  by-existence stall into a rule the fix
  author follows mechanically.
- TOOL ROUNDS CANNOT GO VIA ./bn OR A CHAT PASTE (the R515 lesson,
  2026-10-17): ./bn only fetches spec_NNN.json splice bodies, and
  pasting a Python tool from chat corrupted it twice - the user
  pasted the chat ritual block instead of the canvas body, and
  commit 8bd8a0d landed a 76-byte file that was just the
  "md5sum ..." prompt line. STANDING METHOD: deliver tool-round
  scripts as BASE64 in a code canvas (76-col folded), and the
  ritual is nano -> paste the b64 block -> base64 -d > file ->
  md5sum gate -> run. base64 either decodes byte-exact or fails
  loudly; Python source pasted raw has no such property.
  R608 LESSON (2026-10-18): the AUTHORED
  canvas body itself shipped as ~25 separate
  b64 chunks and was broken at the source -
  the delivery failure was on the Vibe/canvas
  side, not the Termux decode. The R515 rule
  binds the AUTHOR: deliver base64 as ONE
  CONTINUOUS 76-col folded block in a single
  canvas body, never a chunked/multi-block
  body; state the expected line count and the
  decoded-file md5 in the handoff so both
  sides can verify before base64 -d.
  R608 REISSUE LESSONS (2026-10-18,
  mid-delivery, user-confirmed): (1) the
  user-side canvas COPY clips large bodies
  at ~15K chars (the b64 canvas copied at
  15001 bytes, the raw JSON at 32713 vs
  33491) - a short paste is a CLIP, not a
  corruption; diagnose by md5 fingerprint
  per top-level JSON field, then per item,
  and repair the damaged field only (base64
  repair blob + the md5 print as the gate).
  (2) RAW JSON IN CHAT IS STRUCK AS A
  DELIVERY ROUTE (R515 rule now binds the
  AUTHOR too): the chat renderer eats every
  `](` as Markdown link syntax, mangling
  every expr string in a pasted spec, AND
  the author's own hand-typed JSON carried
  a dev/dew typo the object counts could
  not see. Canvas (single b64 block) + md5
  gate is the ONLY delivery channel; if a
  chat-typed repair is ever unavoidable,
  build strings with chr() codes and
  fingerprint per item afterward. (3) A
  repair blob must carry its own expected
  line count so a dropped paste line is
  caught, not silently shifted (Python
  b64decode discards bad chars instead of
  failing loudly).

- **AUTHORED GAP-REPORT CANVASES MUST BE
  PRE-FLIP (the R796 lesson,
  2026-10-24)**: the MM2 arc-opener
  canvas was emitted post-round - the
  five boxes [x], the footer stamped -
  and its authored md5 covered the
  post-flip body, so the md5 gate
  passed while the engine read the
  flips as "already" against the
  applied seed/header/include/audit:
  the R420 mixed abort on every
  attempt, with the tree never dirty
  and nothing ever written. Standing
  rule: verify a delivered gap-report
  body with `grep -c '^- \[x\]'` == 0
  (box lines only; legend text may
  legitimately carry "[x]"). The
  repair for the class: reverse the
  spec's own gap_flips (to -> from)
  and gate the resulting pre-flip
  md5. Side lessons: the engine never
  reads or writes the gap report
  footer (authored free text); and
  git checkout with any invalid
  pathspec restores NOTHING - an
  untracked flip target can never be
  git-restored.

- **THE MM2 ARC IS NOT LETTER-BY-LETTER
  (user-set 2026-10-24, after the
  R797 landing)**: the letter A round
  was the arc's mechanics shakedown -
  proving the data_files registry
  promotion, the live def walk, the
  grids and the xp-source patch all
  work on the MM2 print. It is NOT
  the template for 25 more single-
  letter rounds: the round scope past
  A is Curtiss's call each time
  (multi-letter passes, thematic
  splits, or any other slicing of the
  31 open boxes are all on the
  table). Never presume "letter B
  next" when preparing a round.

- The local ACID fixture cannot compile C - audit blocks with
  index math get a Python simulation pass against the real repo
  headers before publish (R368 lesson: an off-by-one title-loop
  mapping shipped bad 12 and needed R368b).
- Since R369 the ACID test runs against the real regtest.cpp, gap
  report, and seed pulled from the repo at HEAD, not a synthetic
  fixture.
- An audit printf label is a contiguity marker: if it wraps past
  78 columns the marker string never appears intact in the patched
  regtest.cpp and the 'd audit line' assert fails at acid time.
  Keep the R-label text in the printf short enough to stay on one
  line (R389 lesson: shortened to `R389 UA weaponless combat pin
  audit`).
- Local "pristine" reference copies can be silently polluted by a
  failed acid run (a first-run traceback can still have patched
  earlier steps, or a run from the wrong CWD writes into the
  originals). Before declaring acid failure, re-fetch the seed /
  regtest / gap report from raw.githubusercontent at HEAD and
  re-md5 before re-running (R389 lesson).
- Multi-line Python string literals that split a C include comment
  can concatenate without the space at the split ("non-lethal"
  + "combat" -> "non-lethalcombat") and still pass every marker
  assert. After assembly, grep the patched regtest include line
  by eye or by exact-match against the intended comment text
  (R390 lesson).
- The R389 audit labels 356-389 are one line each; any new round
  copies that list and prepends its own short one-line label.
- An audit cross-check whose condition is TRUE on correct data
  increments bad on a healthy build (R391: `if (a + b >= total)
  ++bad;` fired on the correct 5+3 vs 7 and printed bad 1, and
  the block's `if (bad) return 1;` truncated the whole census
  run, making preflight show dozens of phantom CENSUS FAILs).
  Cross-checks must be written fail-on-wrong, and every check in
  the audit block gets a Python simulation pass (parse each
  `if (...) ++bad;`, eval against the header's return values)
  BEFORE publish - the R368 lesson generalized from index math
  to all conditions.
- The simulation pass validates audit SEMANTICS against Python
  models, not the emitted C. R392 shipped three C-level bugs
  the sim could not see: a `HDR[1:-1]` strip that ate the
  leading `/` of the `// ===` opener (the literal had no
  leading newline), a missing backslash escape on the dagger
  length `c. 15"` (inches, double-prime) leaving `""` unbalanced
  in uahandheld.h, and whole-function replacements that flipped
  return types (`uawtName` const char* -> int, `uawtIsNewWeapon`
  bool -> int; the last compiles silently). Since R392 every
  round gets a static header check before publish: per-line
  unescaped quote balance, brace balance, and
  signature-vs-array type consistency for every `inline`
  accessor in each touched header, plus a data cross-check of
  emitted string arrays against the clean pages (R392 lesson).
- State the published md5 in the handoff and gate the ritual on
  it: the user's Termux copy of the R392 body hashed
  differently from the tested artifact, and the first real
  signal was the compile errors, not the md5 line. `md5sum
  tools/rXXX_splice.py` is step 1 precisely to compare against
  the published value (R392 lesson).
- Commit only after preflight GREEN: R392 was
  committed RED (6cfd9c2, compile errors in the
  emitted headers). Two recoveries exist - reset
  (unwind the local commit, re-splice the fixed
  body, land one clean commit) or the b-route
  (keep the RED commit, land a repair splice on
  top, R391b precedent). The user chose the
  b-route: when a fix rides on top of a landed
  round, name it RXXXb - never re-issue the same
  round number for a fix (R392 lesson, user
  decision 2026-10-12).
- An ENGINE-CALLER patch (a game/*.cpp caller
  reading new rules/ accessors) must also patch
  that TU's #include - the game TUs do not pull
  the pin headers transitively (regtest does).
  The Python sim and the static header checks
  cannot see include wiring; the first compile
  on Termux is the gate (R400 lesson, caught
  RED with no commit landed).
- The TWO LOGGING LAYERS are OUT
  of the seam list (user
  decision, post-R404
  2026-10-13): if the seam
  candidates are the logging
  layers previously
  discussed, they must be
  dropped from the list -
  they will be dealt with
  separately at some point.
  The remaining in-scope
  seam after R404: the
  deity layer (Appendix S).

- **THE CREATURE-REGISTRY PROMOTION SEAM (user
  decision 2026-10-23, post-R790): the five
  pin-only creature sets get promoted into the
  LIVE MM1 registry format, and any fields their
  captures need beyond the mm2lua.py schema ride
  as schema adjustments.** Verified repo state at
  3ff2f2a: the live registry holds 408 defs,
  every one source "MM1" (monsters/monsters/
  <letter>/<name>.lua - generated tables, NOT
  hand-written; full prose in the text field,
  raw prints alongside cooked numerics; loaded
  at runtime by the Lua 5.4 C API loader in
  monsters/MonsterRegistry.cpp - defensive
  coercers, mixed values, MonsterDef). Of 580
  rules/ headers only 34 are runtime-wired
  (all UA-era or core); 546 are regtest-only
  pins. ZERO runtime includes for OA, WSG,
  DSG, DMO, and MOP - UA is the only book
  that crossed into the live engine. The five
  creature sets a registry promotion would
  cover: OA Chapter 12 (the ~30 monster
  headers oa050-oa103), WSG animals
  (wsganimal.h), DMO high-level monsters
  (dmomonsters.h), MOP Appendix II inner
  creatures (appendixiiinnercreatures.h), and
  MOP Appendix III outer creatures
  (appendixiiioutercreatures.h). Promotion
  rounds write .lua defs in the MM1 schema,
  extend the schema by ADJUSTMENT where a set
  needs fields MM1 lacks, feed them through
  the existing registry loader (encounter/
  xp/combat audits then exercise them live),
  and keep the pin headers as the
  print-fidelity record. THE COUNT (verified
  at 3ff2f2a): 65 new .lua defs - OA
  Chapter 12 = 39 (the 28 oa076-oa103
  headers, expanded: gaki x4, gargantua x3,
  oni x3, generals x3, buso x2, nature
  spirits x2, tengu x2 crow and humanoid,
  oriental dragons x2 the chiang lung and
  tun mi lung OA-printed additions, the
  rest singles), WSG animals = 18
  (wamAnimalCount, Table 13 ape to yak;
  one look at the wsg mount/fish headers
  before the cut - any stat-bearing
  creatures beyond the 18 ride in), MOP
  Appendix III = 8 (einheriar, marut, the
  Beastlands mortal cloud, the five
  archons). TWO ZERO-RECORD ADJUSTMENTS
  ride alongside: DMO dmomonsters.h is the
  Legendary Ladder doctrine (the +/-1/2/3
  altering rules and the 5 scion ranks) -
  a rank field on existing defs, not new
  files; MOP Appendix II is the elemental-
  analogue system (stat mods, movement
  multipliers, lair percentages, per-
  element abilities, the no-analogue
  doctrine) - a transform field, not new
  files. ROUND SHAPE (user decision
  2026-10-23): ALL IN ONE ROUND - the MM1
  precedent carries over (monsters2lua.py
  generated all 408 defs from the merged
  @-record file in one pass): one round
  generates all 65 defs from the pin
  headers, lands the two schema
  adjustments, and feeds the registry
  loader so the battery audits exercise
  them live (the encounter/xp census grows
  past the 408). The round awaits
  Curtiss's go.

- **Round scope is content-density driven, not one page
  per round** (user decision, 2026-10-15, post-R485): a
  round pins as much consecutive WSG material as the
  extraction and audit machinery can carry cleanly -
  whole chapter sections per round where the prose allows,
  splitting only where a printed grid, a contested settle
  or the spec size genuinely demands it. The one-page cadence
  of R482-R485 was a normalization artifact, not a rule.
  Extraction commands should request all pages the round
  needs up front, and the gap-report boxes flipped in one
  round are all the boxes whose sections the round pins.
  Starts at R486 - the natural hazards chapter (pp. 76-83)
  goes in as few rounds as the content allows.

## Standing seams and queue

- **The open seams (post-R848):** the deity layer (Appendix S) -
  the one remaining in-scope PIN seam after R404; the
  creature-registry promotion seam (the post-R790 user decision,
  all-in-one round shape - the 65 new .lua defs across OA
  Chapter 12, WSG animals, MOP Appendix III, with the DMO
  Legendary Ladder rank field and the MOP Appendix II elemental
  transform as schema adjustments; the census numbers verified at
  3ff2f2a are historical - the MM2 and FF promotion batches have
  since driven the registry floor to 995; re-verify the counts at
  the current HEAD before scoping the round); and the two
  logging layers (code-level and game-level) - OUT of the seam
  list, debugging phases only, parked per Curtiss.

- **THE G1 MODULE ARC (PAUSED):** the G1 (Steading of the
  Hill Giant Chief) map line - the module-arc decisions and
  the full doctrine set (tile metadata, two-layer geometry,
  tileset, unequal-pixel, wall weights, render resolution,
  grid removal, terrain transition, primitive transparency,
  occlusion, floor facts, seamlock, repo location, exterior
  margin, exterior-door closure) plus the extracted map data
  and the mkstamp/mktexstamp tooling records - moved VERBATIM
  to g1-arc.md in this topic at the v4 fresh start. Read it
  in sections when the arc resumes; nothing was summarized
  away.
- **NO DMG OR PHB ROUNDS (user decision
  2026-11-01, post-R1026): the round process
  will NOT run on the DMG or the PHB. The
  reason is performance - removing too much
  C++ code (the pinned-data migration the
  other books took) would greatly affect the
  performance of the game engine. The DMG
  (gap report 81/0) and the PHB (49/0) stay
  as they are; both books are OUT of the
  queue permanently. CONFIRMED BY CURTISS
  (2026-11-01): the C++ engine code of the
  non-monster books stays in the engine - the
  Lua registry files are DATA-AT-LOAD only
  (MonsterRegistry::loadFile parses each def
  once into a native MonsterDef struct and
  closes the Lua VM immediately; play-time
  reads are pure C++), so the Lua monster
  registry costs zero runtime performance.
- **WAIT FOR GO** before preparing any round; the queue reopens
  with Curtiss's call. The FF arc is CLOSED: the print walk
  (R845), the seven promotion batches (R836-R842), the index
  lines (R840) and the three table-group rounds (R846 the
  monster level tables, R847 the encounter listings, R848 the
  magic item tables).
- The landed-record convention rides unchanged: each round's
  spec seats the PREVIOUS round's record into this seed before
  the '## Knowledge maintenance' anchor (prev_seed_key checks
  idempotence), and the landed record is seated into the
  Personal Knowledge topic after each land.


## Current state (post-R1043, the v4 fresh start)

- HEAD 8972cdba ("R1043: weapon chart tables de-wire (census
  1022)"), battery census 1022 audit lines, 2026-11-14.
- The registry de-wire arc (R1027-R1043) is the live round
  shape: content/tables/* .lua defs on items::MiscItemRegistry,
  header-only seams, fragment audits with computed pins,
  census-driven regtest. Precedent shapes covered so far:
  header-only modules (R1040), percentile bands (R1041),
  price tables with tables[] structure (R1042), multi-family
  chart+list sets with re-purposed loader slots (R1043).
- De-wire queue (all WAIT FOR GO): the phb ladders
  (subclasses/bard xp-title pairs), dm/appendixi.h dressing
  tables (needs a new band-text registry), or a fresh survey
  of remaining hard-coded tables outside the encounter region.
  weapontables.h (the biggest phb fish) closed at R1043.
- The deity layer seam CLOSED at R1026 (the open-seam list
  above is the historical R848 view; the deity item was its
  last live entry).
- Delivery flow: delivery_pack.py + chunkcheck canvas (GATE
  lines are the identity, never the whole-file md5), three
  chunkcheck drills, preflight on Termux as the only
  compile+run gate, pre-delivery emulation STANDING PRACTICE.

## Knowledge maintenance (updated at the v4 fresh start)

- Each land appends ONE round record to the tail of this file
  (status line, work, lessons, STATE block) - terse; the repo
  carries the code.
- When this file balloons past ~100KB, run the fresh start
  again (v5): backup + rebuild, saved to doc/vibe/ with a v5
  suffix and committed BEFORE wiping - the v3 and v4 processes
  are the templates. The v4 rebuild (R1043, 2026-11-14) moved
  the pre-R1034 history to the repo backup
  (adnd1_knowledge_backup_v4.md) and the G1 arc to g1-arc.md;
  both are referenced, never summarized away. The v3 template's
  other two artifacts also rode the rebuild: the seed
  (adnd1_knowledge_seed_v4.md, the byte-copy of this entrypoint
  as landed) and the continuation prompt
  (adnd1_continuation_prompt_v4.md, matching the repo series
  adnd1_continuation_prompt_v2/v3.md) - all three committed to
  doc/vibe/ in one doc commit.

## Tooling (updated at the v4 fresh start)

- The R1034+ de-wire rounds: a per-round tools/rNNNN_splice.py
  (chunk-delivered via canvas, extraction by chunkcheck.sh,
  md5-gated), the rehearsal ritual (splice, idempotence,
  second-tree diff -r, emulator bad 0), then the Termux
  preflight (bash tools/preflight.sh, NEVER sh). The older
  spec-driven engine (tools/splice_engine.py + speclib.py +
  rverify.py, JSON specs, R846-R1033 era) remains in the repo
  and the backup record.

## Pre-R1034 history (pointers, not summaries)

- **R849-R1026 (the increment block, ~9.4k lines, verbatim
  in the repo backup adnd1_knowledge_backup_v4.md):** the
  spec-driven splice era - the TD/issue rounds (the Dragon
  issue-21 and issue-21 opener chains), the registry ground
  truth 1313 loaded / 1338 base lua / 25 never-load, the
  deity layer seam CLOSED at R1026 (commit c9c35759), and
  the G1 map-line/stair work (see g1-arc.md). Records R849-
  R1026 are all there; consult on demand, never wholesale.
- **2026-11-11 rules reorg arc (pass 1 LANDED, verbatim in
  the backup):** the rules/ directory reorganization, pass
  one landed.
- **2026-11-12/13 miscmagic arcs (verbatim in the backup):**
  the merge (0a00ff06), the re-split + misc_magic/
  relocation (30c35d9c), the filename unstutter (9801f6b6),
  the REWIND (user decision, reset to 19daa1a1), then the
  LUA PROMOTION A1 (23662f73) and the defs -> letter dirs
  (6e164600) that survived.
- **R1027 (bb971d0a):** the A2 de-wire. **R1028 (3400f07a):**
  the misc magic ENGINE de-wire. **R1029-R1031:** the
  content-name sweeps (rules/ddg + rules/dmo, rules/mm,
  meta/dragon/ff and all remaining batches). **R1032:** the
  dungeon encounter engine de-wire. **R1033:** the waterborne
  and underwater encounter de-wire. (Full records in the
  backup.)
## 2026-11-11 — Two-tile stair ruling + step pitch ruling (Curtiss, definitive)
- TWO-TILE RULING: the stair system composes from exactly TWO tiles at placement time — `stair_step.png` (one 10ft square of steps, + exact rot90 `stair_step_v.png` for N-S flights) and `stair_landing.png` (full-square platform, 0.5ft dark trim ring, horizontal grain). The monolithic stairwell stamp (mkstamp) is DEAD for the stair system; mkstamp's per-square placement was confirmed correct but rejected as over-machinery. stair_tread master remains the wood MATERIAL feeding mkstairtiles.py.
- STEP PITCH RULING (user-confirmed): 5 steps per 10ft square, 2ft each = 1.5ft tread + 0.5ft riser. In construct subpx (1ft = 64 subpx at 640 supersample): pitch 128 subpx = 96 tread + 32 riser; downsamples to 12.8px pitch at 64px tile. This is the ONLY layout where the tile wraps seamlessly (64 % 11 ≠ 0 superseded).
- Tools: tools/mkstairtiles.py (canvas mkstairtiles-tool, md5 ee5b3b6de0e6061936a92c7d99dbee69, 209 lines) bakes both from stair_tread_master.png; CLI `mkstairtiles.py MASTER.png TILES_DIR [--riser F] [--trim-shade F] [--trim-ft F]`. Landing shape (full-square + trim) was my call per his delegation; his Gemini reference showed full-square landings, same wood, horizontal grain.
- Baked tile gates (all seamlock PASS): stair_step riser bands ≈ x 10,23,36,49,61; tread lum ~150 vs riser ~74; landing center ~186 with trim on all four edges; _v bands run horizontally.
- Composition wiring waits on him pushing tools/mkplace.py, mkmap.py, mroom.py (all untracked in his tree).

## 2026-11-11 — Two-tile stair system LANDED (3bb2d0b1)
- Commit 3bb2d0b1 on origin/main: tools/mkstairtiles.py (md5 ee5b3b6de0e6061936a92c7d99dbee69) + stair_step.png fdba411981cf9a2937eda1523ba7419d + stair_step_v.png 4005857daa57209dc3e4950f4c64f372 + stair_landing.png c59c28f0a2cab264eeb9e3a7ccf95be8 (all 64x64). Verified from raw.githubusercontent at sha 3bb2d0b1 — origin md5s byte-identical to my gated bakes. seamlock verify PASS x3 on his side too. Master stair_tread_master.png md5 at this commit: 6e7dfc243e22a27758b922c5b37b53bd.
- Recovery lesson: an earlier paste-with-prompts mishap corrupted stair_tread_master.png and left junk files (a "not a PNG" stair_step/stair_landing pair + stray files literally named "done" and "python3"); fixed via git restore + rm before re-bake. Deliverable command blocks must be paste-safe: no prompt strings, no inline comments, one command per line — the prompt-string paste broke every multi-line continuation.
- Next: stairwell composes at placement from stair_step (E/W arms), stair_step_v (N-S stem), stair_landing at (12,37),(12,40); blocked on him pushing mkplace.py, mkmap.py, mroom.py (still untracked in his tree). His tree also has unrelated local mods (tools/mkstamp.py, deleted maps/upper_level_preview_small.png) not to ride along.


## The miscmagic and reorg arcs (summary; verbatim in the backup)

- The dmg naming + miscmagic arc was REWOUND by user decision
  (reset to 19daa1a1) after the merge/re-split/unstutter
  chain; the surviving shape is the LUA PROMOTION A1
  (23662f73) and the defs -> LETTER DIRS move (6e164600).
  The rules reorg arc pass 1 landed 2026-11-11; the stair
  rulings above are the definitive two-tile stair doctrine.
## DELIVERY V2 - the corruption diagnosis + the chunk-canvas protocol (2026-11-13, post-R1032)

THE DIAGNOSIS (12 pinpointed corruptions analyzed: 11 this round
+ R1031's): (a) ALWAYS in-alphabet - every corrupted byte stayed a
valid base64 char, grep '[^A-Za-z0-9+/=]' never fired - rejects
bit-rot/storage theories; (b) confusable-character bias - E->e
case flip, 8->9 adjacent digits, t->d, b/f, F/H, /->+ (the only
two base64 punctuation) - the signature of a statistical text
GENERATOR, not a byte channel; (c) rate ~2.8e-4/char (1 per ~47
b64 lines), positions uniform, NONDETERMINISTIC across
re-emissions of the same content; (d) corruption is present in
the assistant message itself (user paste-backs hash to the
corrupted bytes; author-side artifacts verified clean at every
step) - the lossy stage is message rendering/generation, NOT the
Termux paste. P(clean 20KB b64 delivery) ~ 0.4%: corruption is
CERTAIN, only positions vary. The trigger is the payload's
volume x zero redundancy (base64-of-gzip is maximal entropy -
no structure for the copy process to lean on) x md5-gate
visibility (the noise was always there; the gates expose it).

THE SAFEGUARD (delivery v2, built and proven 2026-11-13): the
chunk-delivery CANVAS. Tools: delivery_pack.py (author-side
packager, md5 8108c2901f8fce3dec868ed26d9311e8) + chunkcheck.sh
(user-side verifier, md5 36c25972a70c426e6b0a3775b10f4d27), both
stored IN THIS knowledge folder (env-reset-proof). Properties:
(1) ZERO TRANSCRIPTION - the packager pipes pristine bytes disk
-> canvas file; b64 is never typed into a message; (2) FILE-LEVEL
GATE - one md5 over the downloaded canvas replaces 262 line
gates (md5 of canvas file quoted in the delivery message; if it
matches, every chunk inside is byte-exact by construction);
(3) SELF-VERIFYING CONTENT - GATE lines (file/path/tgz/b64/lines/
chunks/verifier + per-chunk md5), a per-line LH manifest (8-hex
per b64 line), and the verifier script itself ride INSIDE the
canvas - the user needs zero chat round trips to validate;
(4) REDUNDANCY - every chunk ships as copies A and B; observed
single-char classes auto-repair from B with no paste-back
(P(both copies hit same line) ~ 5% per panel-copied delivery,
and the script flags the exact chunk:line for paste-back);
(5) the verifier extracts/verifies/repairs/unpacks and gates the
tool md5, exit 0 only on all-gates-pass.

USER FLOW (Termux): download the canvas via the canvas export
control -> md5sum the downloaded file vs the quoted canvas md5
-> awk '/^@@B chunkcheck.sh/{o=1;next} /^@@E chunkcheck.sh/
{o=0;next} o{print > "chunkcheck.sh"}' canvas.md -> sh
chunkcheck.sh canvas.md -> expect "CHUNKCHECK: PASS - <path> md5
<gate>". PANEL-COPY FALLBACK: paste chunks into splitXX by hand
-> sh chunkcheck.sh --verify canvas.md . (B copies auto-repair;
worst case prints chunk:line for paste-back). PROVEN AUTHOR-SIDE
on the landed R1032 tool (demo canvas chunk-delivery-r1032-demo,
canvas md5 3ff64ef5edb4af0d700a4c7bb4325ad6): clean extract PASS;
deletion-class + substitution-class damage in A auto-repaired
(PASS, zero round trips); same-line damage in BOTH copies
refused with the exact line flagged. STANDING RULE: all future
b64 payload deliveries go via the delivery-v2 canvas; the
message-body chunk paste is the fallback only, and per-line
diagnosis loops are retired in favor of the embedded manifest.

DELIVERY V2 AMENDMENT (2026-11-13, canvas affordances): the
canvas panel has NO download option - only copy or export.
CONSEQUENCES: (1) the canvas was RESTRUCTURED so every
machine-readable section (gates, manifest, each chunk A, each
chunk B, the verifier) is its own FENCED CODE BLOCK with a
per-block heading - panels typically offer a per-block copy
control, and every block is ~3KB, far under the ~15K panel-copy
clip ceiling (R608); extraction still keys on @@B/@@E markers,
so block-copy inner content assembles into a parseable
canvas.md with or without fence lines. (2) Export is the
preferred route: if it lands a real file, ONE md5 over it (the
canvas md5 quoted in the delivery message) replaces every
other gate. (3) The copy route: copy each block in order,
append into one canvas.md, run chunkcheck.sh canvas.md - the
B copies auto-repair copied single-char damage, worst case
flags chunk:line. Packager UPDATED: delivery_pack.py md5
26ba5ccafb7e702ecb11773bbbc2b486 (fenced blocks; chunkcheck.sh
unchanged, 36c25972a70c426e6b0a3775b10f4d27). Demo canvas
REGENERATED: 997 lines, 51206 bytes, canvas md5
f752e90171489d88a382dc5a0846b8f5; all three drills re-proven
on the fenced build (clean PASS / 2-line auto-repair PASS /
both-copies-damage refused with splitac:19 flagged). PENDING:
Curtiss's first real Export/copy test in Termux - if Android
download lands outside ~/storage/downloads, locate via
"find ~/storage/shared -iname '*chunk-delivery*' -mmin -10"
and seat the actual path here.

DELIVERY V2 - REAL-WORLD FINDINGS (2026-11-13, Curtiss's first
Export test): (1) the PLATFORM REWRITES PUBLISHED CANVAS FILES -
the authored canvas (997 lines, md5 f752e901) was normalized in
place to 996 lines / 51209 bytes (frontmatter values re-quoted,
trailing newline changed; stored md5 555ab7cd) - the FILE-LEVEL
md5 gate is therefore DEAD as a channel proof: quote it only as
an author-side fingerprint, never gate on the stored/exported
copy. (2) EXPORT TRANSFORMS AGAIN on top (Curtiss's exported
copy md5 908d6858 != stored 555ab7cd != authored f752e901) -
expected, cosmetic so far: the REWRITTEN STORED CANVAS still
passes the full chunkcheck gate chain (chunks byte-exact,
payload md5 2f55306a) - THE IN-CANVAS GATES ARE THE AUTHORITY,
exactly the case they were built for. (3) chunkcheck.sh BUG
FOUND + FIXED (the Termux run exposed it): the script cd'd into
the workdir BEFORE opening the canvas, so a relative canvas
path died ("cannot open canvas.md"); fixed by absolutizing $f
before cd - new verifier md5
812a46464fd451b565cb617f06df95d0 (the demo canvas still embeds
the pre-fix 36c25972: with it, pass the canvas path ABSOLUTE or
run from the canvas's directory; future canvases embed the
fixed one). STANDING: verify exported deliveries with
chunkcheck.sh only; expect stored/exported md5s to differ from
the authored one and rely on GATE/chunk/payload gates.

DELIVERY V2 - PROVEN IN TERMUX (2026-11-13): Curtiss exported
the demo canvas to Android, moved it to ~/Adnd1/canvas.md, and
sh chunkcheck.sh ~/Adnd1/canvas.md ~/chunktest printed
"chunks ok: 7, auto-repaired: 0, unrepairable: 0" +
"CHUNKCHECK: PASS - tools/r1032_splice.py md5 2f55306a" on the
FIRST real run. THE CHANNEL IS CLOSED-LOOP: authored bytes ->
published canvas (platform normalizes cosmetically) -> Export
(transforms cosmetically) -> Termux -> chunkcheck gates -> the
payload md5 gate matches the landed tool EXACTLY. File-level
canvas md5s are fingerprints only (authored f752e901; stored
555ab7cd; exported 908d6858 - all different, all carrying
identical payload). The working user flow is the absolute-path
form: sh chunkcheck.sh <canvas>.md <workdir>. From R1033 on,
every b64 payload ships as a delivery-v2 canvas built by
delivery_pack.py (knowledge folder, md5 26ba5cca) embedding the
fixed chunkcheck.sh (812a4646); message-body chunk paste and
per-line md5 diagnosis loops are RETIRED.

## R1034 - outdoor (wilderness) encounter de-wire (LANDED)

COMMIT: 00bb1a83 "R1034: outdoor encounter engine de-wire
(census 962)", pushed 5499a2e9..00bb1a83.

WHAT: the R1032/R1033 shape closed the deferred outdoor family.
tools/r1034_splice.py (LANDED md5
3e911321c3c26cec2788514c607d469b; first-delivery build
035a789ae45a163ae9226a5fea45158f was superseded in-flight, see
the dispatch-order catch) parsed the retired OutdoorRow arrays
out of dm/encounters.cpp lines 1042-2516: 8 climate tables
([12,24,59,40,38,23,29,52] rows: arctic/sub_arctic/temperate_
wild/temperate_inhabited/faerie/pleistocene/dinosaur_age/
tropical), 11 SUB_* subtables ([4,11,3,8,5,5,9,4,4,4,10]:
demihuman/dragon/frog/giant/humanoid/lycanthrope/men/snake/
sphinx/spider/undead), the tropical Sphinx footnote
(kSphinxT/kLoT/kHiT 4 bands) as outdoor_sphinx_t (terrain-
independent: all 8 cols identical), and 6 pick-sets
(ki_rin/leprechaun/porcupine/iguanodon/lammasu/wolf_dog ->
*_set lists) - 348 rows -> 21 lua under NEW SIBLING DIRECTORY
content/tables/encounters_outdoor/ (19 tables + sphinx_t +
outdoor_sets.lua in one file loading the 6 sets into m_lists).
Sibling-dir decision kept the R1032 20-file and R1033 9-file
pins untouched. Lua shape: rows = { { key, cols = { {lo,hi} x8
} } }, -1,-1 = no entry (legal per-column; populated entries
must chain 1->100). dm::EncounterTableRegistry extended:
EncounterOutdoorRow {key, lo[8], hi[8]} default-init -1,
hasOutdoor/outdoorRows, m_outdoors, STRICT loader branch
isOutdoorKey (prefix outdoor_) validating 8 pairs, plus the
outdoor_sets branch (setKey = <name>_set into m_lists,
kOutdoorSetKeys allowlist). rollOutdoorEncounter/
outdoorEncounterKeys/outdoorBands/outdoorSubBands rewritten
registry-backed - signatures unchanged, state_overland.cpp
untouched, encounters.h untouched. 7-section fragment
rules/audits/r1034_outdoor_encounter_registry.h (load 21+20+9
files one registry/counts/bands/pins/sets/keys/roll). Census
955 -> 962; encounters.cpp 4205 -> 3117.

PRESERVED R63 QUIRK: resolveOutdoorKey returns false for
SUB_CHARACTER (falls into the generic SUB_ branch, matches no
subtable), so rollCharacterParty in rollOutdoorEncounter is
dead code on main - preserved verbatim per the R1032 quirk
doctrine; sim counted 1290 dead SUB_CHARACTER cells;
fragment roll gates written for the quirk (populated combos
must have seen>0, produced<4000; NO parties/produced gates).

THE DISPATCH-ORDER CATCH (the round's lesson, user-side
preflight as the only compile gate DID ITS JOB): first
delivery ran GREEN in every author-side rehearsal (python sim
clean, 640k cells, round-trip byte-exact, drills green) but
user preflight printed "R1034 outdoor encounter registry load
audit: bad 2" then died. Diagnosis without a local compiler:
bad 2 = files 20!=21 (+1) + errors non-empty (+1) with arctic/
sphinx_t spot-checks passing = exactly ONE lua file failing
STRICT load. Root cause: isOutdoorKey (prefix "outdoor_")
matched "outdoor_sets", and the dispatch chain tests
isOutdoorKey(key) BEFORE the key=="outdoor_sets" branch - the
sets file hit the STRICT rows loader, failed "rows is not a
table", and its own branch was UNREACHABLE. The Python
rehearsal validated data, not dispatch order - author-side
sims cannot catch C++ control-flow bugs; the Termux preflight
is the only gate that can. FIX: isOutdoorKey now excludes
outdoor_sets explicitly, plus a fragment regression pin
(hasOutdoor("outdoor_sets") must be false) so the class is
guarded forever. LESSON STANDING: when adding a prefix
dispatch + an exception branch, the exception must be tested
BELOW the prefix gate or excluded in the prefix predicate; new
shape branches need a negative has-check pin.

DELIVERY (delivery v2 + first PATCH ROUTE): v2 tool canvas
r1034-delivery-v2 (8 chunks, 304 b64 lines; tgz
fd25827e7282c45f7272389cdff23cf2, b64 c66f030623477b60ec25b2d6
8a509ac9, verifier 812a4646; canvas authored md5 f3ecb299 as
fingerprint only). Drills: clean PASS / A-copy auto-repair /
both-copies refused. Curtiss preferred a DIFF over re-fetching
the tool (R1027 patch-script precedent): 12-line two-hunk
patch (r1034_fix.patch) pasted into nano and git-apply'd; the
patched tool hashed exactly the v2 md5 - the patch route is a
valid delivery-v2 sibling when the delta is tiny. Apply flow
on a spliced tree: patch tool -> git checkout -- the 4
rewritten tracked files (dm/encounters.cpp,
dm/EncounterTableRegistry.h/.cpp, regtest.cpp) -> targeted
git clean -fd content/tables/encounters_outdoor + the R1034
fragment (NEVER bare git clean - canvas.md/chunkcheck.sh ride
untracked at repo root) -> re-apply (the tool skips an
already-spliced tree; revert is mandatory). Preflight NOTE:
tools/preflight.sh line 98 uses ${PIPESTATUS[0]} - a bashism;
run it as ./tools/preflight.sh or bash tools/preflight.sh,
NEVER sh tools/preflight.sh (sh died "Bad substitution" at
98 AFTER the battery had already printed the real bad-2 catch
- the crash was the shell, not the splice). SCRATCH HYGIENE
(R1027 lesson held): preflight [4/5] flagged chunkcheck/paste
scratch (payload.b64/tgz, splitaa-ah + .b twins) - removed
before commit, excluded from the round.

VERIFIED (codeload at 00bb1a83): tool md5 3e911321, census
962, 21 lua files present, fragment md5 e1f1e215585676c4304c
da9d91031813, isOutdoorKey exclusion + hasOutdoor(outdoor_sets)
pin landed, encounters.cpp 3117 lines. User-side preflight
GREEN, census 962, 7 R1034 bad-0 lines, 0 warnings.

STATE: R1034 LANDED (main 00bb1a83, census 962). The DMG
Appendix C encounter engine is now FULLY registry-native:
dungeon (R1032) + water (R1033) + outdoor (R1034) families all
lua-backed, zero encounter arrays left in dm/encounters.cpp.
REMAINING deferred de-wire: the R64 city/town encounter matrix
(kCityMatrix, dm/encounters.cpp post-outdoor region) - the
natural R1035. Next work awaits Curtiss's GO.

## R1035 - city/town encounter de-wire (LANDED)

COMMIT: 14fc2780 "R1035: city encounter engine de-wire (census
969)", pushed 00bb1a83..14fc2780.

WHAT: the R1032/R1033/R1034 shape closed the R64 city family.
tools/r1035_splice.py (LANDED md5
e0a8595d777a0e2b969b88b6decec20d; first-delivery build
834135ca1c9b911f016b420f45b42ceb superseded in-flight by the
pin-index catch below) parsed the retired R64 region of
dm/encounters.cpp lines 1428-2123 (separator above
"// R64: the CITY/TOWN ENCOUNTER MATRIX" through separator above
"// R65: the ASTRAL"): kCityMatrix 46 rows (day/night percentile
bands, {-1,-1} = the book prints no band - NOT parens, parens
are invalid Lua), cityCountFor's 28 dice entries (dead bard entry
preserved per the quirk doctrine, monk_or_bard resolves on the
party path first; ghoul/ghast share one C++ branch -> two
entries; absent key rolls one specimen), rollProtectionDevice's
11 p.192 bands, rollCityMagicItems' 4x3 percent-per-level array,
and the R146/R174 flavor bands (kDrunkKinds 20, kHarlotKinds 12,
kNobleKinds 2, kSedanKinds 2, kRuffianKinds 6) -> 9 lua under NEW
SIBLING DIRECTORY content/tables/encounters_city/ (city_matrix/
city_counts/city_magic + city_band_{drunk,harlot,noble,sedan,
ruffian,protection}), keeping the R1032/R1033/R1034 file pins
untouched. Registry: EncounterCityRow/Band/Count/Magic structs,
m_city/m_cityBands/m_cityCounts/m_cityMagic, getters
hasCityMatrix/cityRows/hasCityBands/cityBands/cityBandLookup
(clamps 1-100)/cityCount (nullptr = one specimen)/cityMagic.
DISPATCH (R1034 lesson held): exact keys city_matrix/
city_counts/city_magic + exception-free city_band_ prefix,
negative pins in the fragment (!hasCityBands("city_matrix"),
!hasCityBands("outdoor_sets"), !hasOutdoor("city_matrix"),
!hasWater("city_band_drunk"), !hasCityBands("")) all green.
Mechanics verbatim in the engine: rollCityParty, the
second-percentile splits, nycadaemon/mezzadaemon re-roll advice,
plusForLevel, PROT_* enum mapping via protectionDeviceFromKind;
rollProtectionDevice KEPT (removed from the retired-token list).
47 companion keys (46 rows + 4 expansions - 1 brigand dup
- 2 demon/devil skips), pinned in BOTH the tool sim and the
fragment (want.size() != 47). 7-section fragment
rules/audits/r1035_city_encounter_registry.h (load/counts/bands/
pins/flavor/keys/roll; kBands/kBandRows at top scope),
regtest include after R1034's. Census 962 -> 969; encounters.cpp
3117 -> 2974. City keys are fiction-heavy: the keys/roll gates
check against the matrix expansion, never reg.find().

THE PIN-INDEX CATCH (the round's lesson; user-side preflight as
the only compile gate DID ITS JOB, again): preflight printed
"R1035 city encounter registry pins audit: bad 3" then a census
wall (every pattern, all rounds, "appears 0 times"). Root cause:
COLLATERAL, not a census bug - the fragment's spot-pins read
m[44] for weretiger, but matrix row index 44 is WRAITH;
weretiger is index 40 (row 0 = assassin at lua line 11, index =
line - 11). The three weretiger ifs produced exactly bad 3;
the fragment's "if (bad) return 1;" aborted regtest BEFORE
flavor/keys/roll and every downstream historical audit printed,
so the census greps found nothing. Diagnosis without a local
compiler: sections 1-3 printed bad 0 (load/counts/bands clean ->
dispatch and data fine), so bad 3 lived in section 4's value
pins; dumping the emitted city_matrix.lua against the pin
indices pinned it in one step. FIX: m[44] -> m[40] in the tool
(build_fragment lines 1720-1722) AND the live fragment (the
tool's already-applied path returns early and never rewrites
the fragment - patch BOTH; 6-line two-hunk patch,
git-apply'd, the R1034 patch route again). Fragment printf
count unchanged -> census stayed 969. LESSON STANDING:
spot-pin indices must be DERIVED from the emitted lua (grep -n,
index = line - first-row-line), never recalled from the source
region; and a census wall across ALL rounds is the signature of
an early-return abort, not a census defect - read the LAST
"bad N" line the battery printed before diagnosing the census.

DELIVERY (the round's channel lesson - TEXT SPLICE RETIRED):
Curtiss first rejected b64/chunk-canvas for R1035 ("go back to
text splices"). The text route then failed on BOTH sides within
680 lines: the author hand-transcribing part 1 introduced a
one-word typo (pilgrims), and a terminal bracketed-paste drop
silently lost 4 lines in part 1 (226 lines vs 228; per-slice
sed/md5 drilling located it). After that Curtiss chose the
canvas: delivery-v2 canvas r1035-delivery (9 chunks, 349 b64
lines; tgz f4734f5dcabeaf6fcdfe102bdb6abd83, b64
0e00a73595822d317f9a36ca2dfac1d1, verifier 812a4646; canvas
authored md5 a fingerprint only) - chunkcheck PASS on the FIRST
real run, tool md5 834135ca byte-exact. The 6-line pin fix then
rode the patch route. STANDING: text-in-chat splicing of
tool-sized payloads is DEAD; the delivery-v2 canvas is the
channel for payloads and the patch route for tiny deltas; the
author must never hand-transcribe payload bytes into chat (the
author's own transcription is the weak link, not the terminal).

VERIFIED (codeload at 14fc2780): tool md5 e0a8595d, 9 city lua
files present, encounters.cpp 2974 lines, fragment 7 printfs,
m[40] weretiger pin landed. User-side preflight GREEN, census
969, 7 R1035 bad-0 lines, 0 warnings.

STATE: R1035 LANDED (main 14fc2780, census 969). The DMG
Appendix C encounter engine is registry-native across all four
families (dungeon/water/outdoor/city). REMAINING deferred
de-wire: the R65 astral & ethereal planar encounter tables -
the natural R1036. Next work awaits Curtiss's GO.

## R1036 - planar astral/ethereal encounter de-wire (LANDED)

COMMIT: ddb6e54f "R1036: planar astral/ethereal encounter
de-wire (census 976)", pushed 14fc2780..ddb6e54f.

WHAT: the R1032-R1035 shape closed the R65 planar family.
tools/r1036_splice.py (LANDED md5
5e3814d354111c88b5bd748715289257; four in-flight deliveries
superseded - see DELIVERY below) parsed the retired R65 region of
dm/encounters.cpp lines 1982-2327 (separator above "// R65: the
ASTRAL & ETHEREAL encounter tables" through separator above
"// R66: the PSIONIC ENCOUNTER TABLE"): kAstralTable 24 rows,
kEtherealTable 27 rows (percentile bands, printed Numbers
column, PF_PRIME_ONLY = the (*) footnote), 7 pick-sets
(kDemonMinor 6, kDemonMajor 10, kDevilGreater 3, kDevilLesser
4, kTitanElder/Lesser/Major 2 each), PSYCHIC WIND 4 d20 bands
(1-12 slowed / 13-16 lost_return 2-20 / 17-19 off_course /
20 storm 4-40, save-fail -> cordBroken), ETHER CYCLONE 4 bands
(1-10 blown_about / 11-15 different_plane / 16-18 lost_new_plane
5-60 / 19-20 storm_astral 10-120, blownToAstral = !save) ->
5 lua under NEW SIBLING DIRECTORY content/tables/
encounters_planar/ (planar_astral, planar_ethereal - rows
{band,key,numbers,primeOnly}; planar_picks - 7 sets into m_lists
as <set>_set; planar_wind, planar_cyclone - bands
{band,effect,days={-1,-1} when none}). kPrinces/kArchDevils at
file top RETAINED engine-side (the R52 record, shared with the
dungeon family, outside the region). Registry:
EncounterPlanarRow{key,lo,hi,nMin,nMax,primeOnly} +
EncounterPlanarBand{lo,hi,effect,dMin=-1,dMax=-1}, m_planar +
m_planarBands, getters hasPlanar/planarRows/hasPlanarBands/
planarBands. Dispatch EXACT keys only, no prefix (R1034 lesson
held; negative pins in the fragment). Mechanics verbatim:
rollPlanarTravellerParty (the ** modified Human Subtable party,
1-6 members) KEPT VERBATIM; rollPlanarEncounter rewritten
registry-backed (prime-only footnote re-roll 24 attempts,
pick-set modulo selection via planarSetView, Numbers column
uniform count); planarEncounterKeys rewritten (companion astral
52 / ethereal 27); rollPsychicWind/rollEtherCyclone rewritten
band-backed (day rolls uniform over the printed range = the
retired expressions' spread; storm save logic verbatim). Seam
views planarView/planarBandView/planarSetView (the listView
idiom). 7-section fragment
rules/audits/r1036_planar_encounter_registry.h
(load/counts/bands/pins/parity/keys/roll), census 969 -> 976,
pins DERIVED from parsed data via idx() (never recalled).

DELIVERY (four canvas versions, all chunkcheck PASS - the
three in-flight fixes all surfaced ONLY at the Termux gate,
each costing a full git-reset replay):

v1 dbb276e26855ad263a1a76cbdef6004f: build FAILED - the R66
PSIONIC table's (*) rows resolved through kDemonMajor/
kDemonMinor/kDevilGreater, which were declared INSIDE the
excised region. The R65/R66 comments said "reused" but
nothing grepped the retired symbols' use-sites beyond the
region. v2 b4d8b97b2e5dd88bca2d566c056fee71 added R66_ROLL_
REWIRES + R66_KEYS_REWIRES: six replace_once sites rewired to
planarSetView (roll sites guarded like the ROLL_FN pick
lambda; companion loops iterate the view, pushUnique .c_str()).

v2: build clean, 0 warnings, but "parity audit: bad 75".
ROOT CAUSE: PsychicWindResult/EtherCycloneResult carry NO
default member initializers, and the retired code left the
fields each branch doesn't touch (days/cordBroken off their
paths) as stack garbage; the parity audit reads them on every
path. v3 bde1d33e85a088988135690fe41545b5: value-init
(PsychicWindResult r{}; EtherCycloneResult r{};) - behavior
identical on every traveled path, deterministic on the rest.

v3: "keys audit: bad 6" - exactly the six structural pins
(type_vi_demon_balor, pit_fiend, demogorgon, asmodeus,
elder_titan_ac_2, major_titan_ac_1) failed on the ETHREAL
pass: they sat outside the t==0 branch but are astral-only
facts (the ethereal table carries no demon/devil/titan rows).
v4 5e3814d354111c88b5bd748715289257 scoped them into the
t==0 block. User-side preflight then GREEN: census 976, seven
R1036 bad-0 lines, 0 warnings.

ALSO caught author-side before first delivery (rehearsal
only): the balor pin - "balor" is NOT a bestiary key, the
demon-major member is "type_vi_demon_balor" (grep the monster
content, never recall a key); fragment nums map must be keyed
by EXPANDED keys (pick-set members), not the PLANAR_* pseudo-
keys, or every pick roll false-trips the count check.

STANDING LESSONS ADDED:
1. CROSS-REGION DEPENDENCY SWEEP: before excising a region,
grep the WHOLE TU (and headers) for use-sites of every symbol
declared inside the region - a later region (R66) can resolve
through arrays the region declares. Retired-token checks must
use full declarations (the retained R65 provenance comment
mentions PF_PRIME_ONLY; R66 comments say "R65 kDemonMajor,").
2. STRUCT DEFAULTS vs PARITY AUDITS: a result struct without
default member initializers + a seam that copies the retired
branchy style = uninitialized reads. Any new seam that returns
a no-default struct must value-init (T r{}).
3. STRUCTURAL PINS ARE TABLE-SCOPED: check every pin against
the table(s) that actually carry the rows - a pin outside the
per-table branch silently tests every companion.
4. The abort-signature read held again, twice: read the LAST
"bad N" line (bad 75 parity, bad 6 keys), never the census
wall; the census wall is only the shadow of the fragment's
if (bad) return 1.
5. The exported canvas.md never matches the packer's canvas
md5 (the export adds a byte outside the gated region) - the
chunk gates are the authority; drop the whole-file md5 check
from the user flow.

VERIFIED (user-side preflight GREEN before commit; codeload
verification of ddb6e54f pending next round's preflight):
tool md5 5e3814d3, 5 planar lua files, fragment 7 printfs,
census 976, encounters.cpp 2985 lines.

STATE: R1036 LANDED (main ddb6e54f, census 976). The DMG
Appendix C encounter engine is registry-native across all
five families (dungeon/water/outdoor/city/planar). REMAINING
deferred de-wire candidates: the R66 psionic table now rides
planarSetView for its (*) rows (a natural R1037: retire
kPsionicTable to content/tables/ - note it would need the
R1036 pick-set views, already in place), and the R67 patrol/
stronghold tables beyond it. Next work awaits Curtiss's GO.

============================================================================
R1037 - THE R66 PSIONIC ENCOUNTER TABLE DE-WIRE (LANDED)
============================================================================

ROUND: R1037 (2026-11-14). LANDED at main 2f767d1b (parent
ddb6e54f, pristine codeload tgz md5 9befb010264949da83914b064a8382ef,
census 976). Census 976 -> 983 (7 printfs "R1037 psionic
encounter registry <load/counts/chains/pins/spells/keys/roll>
audit: bad %d"). Tool tools/r1037_splice.py md5
e19444c7f22047fb41010d1161eb058e, delivery canvas
"r1037-delivery" (6 chunks, chunkcheck drills all PASS:
clean / 1-char A-copy auto-repair / both-copies refuse).

WHAT RETIRED: dm/encounters.cpp lines 2347-2557 (separator
above "R66: the PSIONIC ENCOUNTER TABLE" through separator
above "R67: the PATROL") - the 19-row kPsionicTable and the
printed spells lists. NEW content/tables/encounters_psionic/:
psionic_table.lua (19 rows riding the R1036
EncounterPlanarRow shape verbatim - band/key/numbers/
primeOnly=false; the loader branch gains the exact key
"psionic_table", registry .h untouched) and psionic_spells.lua
({key, exact[20], family[6]} -> NEW loader branch ->
m_lists "psionic_spell_exact"/"psionic_spell_family"). Seam:
psionicSpellView (planarSetView lazy-load idiom) +
spellResemblesPsionicPower (case-insensitive, views) +
rollPsionicEncounter (planarView("psionic_table"), kPrinces/
kArchDevils verbatim, PSI_MEN -> rollCharacterParty(dice,8,8),
yellow_mold -> noAppearing fallback, 24-attempt reroll) +
psionicEncounterKeys (companion 41 = 13 plain + 10
demon_major + 6 demon_minor + 4 princes + 4 arch + 3
devil_greater + 1 character_party). Registry: planar branch
gains || key == "psionic_table"; kPsionicSpellKeys + spells
branch at the final else anchor. 4 tracked files rewritten
(encounters.cpp, EncounterTableRegistry.h/.cpp, regtest.cpp),
2 new lua + fragment r1037_psionic_encounter_registry.h.

FLIGHT RECORD (ONE canvas version, chunkcheck PASS on first
delivery; preflight GREEN first try - the R1036 lessons,
applied author-side, held):
- Anchor drift caught at rehearsal: the writers-comment anchor
  in EncounterTableRegistry.h includes the R1034 line
  ("r1034/r1035 and r1036 are the only writers") - the compaction
  summary's region text dropped it. ALWAYS re-grep every
  anchor against the pristine tree before building, even
  "known" ones.
- expected_keys KeyError: the pick map is keyed by SET NAME
  (demon_major) but the table rows carry PSEUDO-KEYS
  (PSI_DEMON_MAJOR) - the twin needs an explicit pseudo-key ->
  set-name map.
- Plain-append %% leak: build_fragment's first block is %-
  formatted (so printf needs %%d) but the sections-4-7 block
  is plain-appended (so a literal %d SURVIVES into the C++ -
  caught by reading the generated fragment, grep '%[ds]' minus
  the census lines). Rule: a %-formatted template and a plain
  template in the same builder is a footgun - substitute
  placeholders (__COMPANION__) after join instead.
- Mechanics-verbatim: the seam's pick block first drafted a
  lambda returning empty-string on a missing set (early
  return); the live code leaves the key unchanged and falls
  through to the ignore-&-reroll. The lambda was reverted to
  the verbatim if/else blocks - a "simplification" in a seam
  is a behavior change on the defensive path.
- The commit incidentally DELETED r1034_fix.patch (a 1.2KB
  stray diagnostic patch tracked since the R1034 era, removed
  from the user's tree earlier; the git add -A carried the
  pending deletion). Harmless cleanup, but it made the commit
  "9 files changed" instead of 7 - verify unexpected lines in
  the commit stat before pushing.

STANDING LESSONS REINFORCED: lesson 2 (value-init - not needed
here, DungeonEncounter e is assigned from the return, not
default-init), lesson 6 (nums map keyed by EXPANDED keys - the
R1037 roll sweep pinned counts per expanded key, zero false
trips), lesson 7 (all 13 plain keys + pick-set members grepped
from planar_picks.lua, never recalled). The R1036
cross-region sweep paid off: R66's (*) rows ALREADY resolved
through planarSetView post-R1036, so this round was a clean
table retirement with no hidden dependencies.

VERIFIED: landed main@2f767d1b codeload - census 983, both
lua present, tool md5 e19444c7 matches, kPsionicTable zero
occurrences in dm/encounters.cpp.

STATE: R1037 LANDED (main 2f767d1b, census 983). The DMG
Appendix C encounter engine is registry-native across all six
families (dungeon/water/outdoor/city/planar/psionic). NEXT
deferred candidate: the R67 patrol and CASTLE/FORTRESS tables
(dm/encounters.cpp, region above "R68", the next separator) -
note the patrol tables feed the inhabited-area logic, so the
cross-region sweep must cover castle/fortress generation use-
sites. Next work awaits Curtiss's GO.

=== ROUND 1038: the R67 patrol and CASTLE/FORTRESS tables de-wire ===

DELIVERED (v2, main@96c745b7, census 990). Retired five
printed castle tables into content/tables/encounters_castle/
(7 lua): castle_type (9 rows, size tokens small/medium/
large), castle_inh_small/medium/large (4 rows each, cats
totally_deserted/deserted_monster/humans/character_types),
castle_humans (4 rows: bandit x2, berserker, dervish),
castle_master (11 rows, prof tokens incl. magic_user,
monk_bard; OCR fixes vs print: assassin 94-96 lvl14, monk
97-99 lvl9-12, bard 100 lvl23), castle_artillery (8 rows;
both shell-keep rows share type "shell keep" - documented,
find-fallback verbatim). Region dm/encounters.cpp lines
2549-2901 at pristine 2f767d1b.

REGISTRY: new struct EncounterCastleRow (lo/hi + size/cat/
key/type/prof strings + lvlLo/lvlHi + n1/n2/n3, all
defaulted), m_castle map, hasCastle/castleRows. Loader: one
castle branch for the 7 exact keys at the final-else anchor,
per-table row-key lists (kCastleTypeKeys etc.) after
kPsionicSpellKeys. ProfId is the dm-local enum (dm/
encounters.cpp ~371; PROF_MU, PROF_MONK_BARD), NOT
rules::ProfRow. Seam: castleView (planarView idiom) +
sizeForToken/catForToken/profForToken; rewritten
rollCastleType (CastleType t{} value-init), castleInhabitants
(default table castle_inh_large), castleHumansType,
rollCastleMaster (classForProf(profForToken(row->prof))),
castleArtillery. VERBATIM: castleHumansCount,
rollCastleHenchmen, castleAwareness, rollPatrol. Public
signatures unchanged (state_overland callers). ENC_LOAD adds
encounters_castle after the psionic line; regtest include
after the R1037 line. Fragment r1038_castle_encounter_
registry.h, 7 sections, printfs "R1038 castle encounter
registry <sec> audit: bad %d". Cross-region sweep CLEAN
(arrays region-local).

FLIGHT RECORD (v1 FAILED at preflight, v2 clean):
- v1's load-audit section 1 contained BOTH the phantom
  negative pin `if (ereg.hasPlanar("psionic_table")) ++bad;`
  AND the intended positive `if (!ereg.hasPlanar(...)))
  ++bad;`. psionic_table IS in the family (R1037 stores it
  in m_planar), so the phantom trips unconditionally: an
  otherwise-green load reports exactly "load audit: bad 1",
  aborting the battery into a census wall (hundreds of
  "appears 0 times"). Looked like a loader failure, was a
  broken assertion. Fix: one line removed from
  build_fragment's section-1 template; v1 tree replay-reset,
  v2 re-delivered, preflight GREEN first try after that.
- LESSON (v1 root cause): negative pins must name keys
  ABSENT from the loaded registry; a negative pin on a key
  that IS loaded produces "bad 1" on a green load. Read the
  load-audit bad-N arithmetic before suspecting the loader.
- LESSON (new standing practice): with no author-side
  compiler, EMULATE the registry-load section's assertions
  in Python against the emitted lua data pre-delivery (model
  hasCastle/hasPlanar/hasPlanarBands pins, dir counts
  kf=7/df=20/wf=9/of=21/cf=9/xf=5/pf=2, list sizes, row
  counts and band chains). The v1 catch was pure inspection;
  the emulation script (emulation bad = 0 on v2, rehearsal
  trees under /tmp/r1038/rehearse3 + rehearse4, diff -r
  byte-identical) is now part of the pre-delivery ritual.
  NOTE: when writing the emulator, mind the pin semantics
  (if (!has(k)) ++bad means VALID iff k present) and lua
  shapes per table (castle_artillery rows have no band).
- LESSON (env): /tmp survives some resets but /home/user
  work dirs do not - recover tools from rehearsal trees or
  the delivery canvas. Also: the repo already contains
  tools/, so mkdir tools/ after a fresh extract fails; just
  cp into the existing dir.

VERIFIED: landed main@96c745b7 codeload (tgz md5
71e1bfaa3ffc67e6704504863d82b7a1) - census 990, 7 castle lua
present, tool md5 671402f09a137002c9ec3637a8a4ca15 matches,
kCastleTypeTable zero occurrences in dm/encounters.cpp,
fragment + EncounterTableRegistry.h + regtest.cpp carry the
R1038 marks.

STATE: R1038 LANDED (main 96c745b7, census 990). The R67
castle family is registry-native. Next deferred candidate:
continue the de-wire march upward from the R68 separator in
dm/encounters.cpp - re-scan the pristine region above R68 at
the CURRENT main before scoping (the census is now 990).
Next work awaits Curtiss's GO.

=== ROUND 1039: the R53 Character Subtable and R55 party
magic-item tables de-wire ===

DELIVERED (main@ac714faf, census 997). Retired six printed
tables into content/tables/encounters_party/ (6 lua):
character_subtable.lua (10 rows {band, prof, max}, prof
tokens the R1038 scheme incl. magic_user/monk_bard, per-
profession maxima 3/2/5/2/2/3/1/4/2/1),
magic_ladder.lua (13 rows {level, t1pct, t1n .. t4pct,
t4n}, pct -1 = automatic, level 13+ reads row 13), and
magic_table_1..4.lua (20/16/16/12 rows {die, kind, a, b};
kind tokens none/wpn/rng/arm/shd/arm_set; fiction-only rows
ride none). Region dm/encounters.cpp: separator above the
R53 header through the rollCharacterParty header (two anon
namespaces, R62 raceAllowsClass kept verbatim between).

REGISTRY: new struct EncounterPartyRow (lo/hi + prof/kind
strings + max + a/b + t1pct..t4n, all defaulted; lo==hi for
the unbanded ladder/die rows), m_party map,
hasParty/partyRows. Loader: one branch for the 6 exact keys
at the final-else anchor (after the castle branch), row-key
lists kPartySubKeys/kPartyLadderKeys/kPartyItemKeys after
kCastleArtilleryKeys. Loader enforces: subtable bands chain
01-00, ladder levels continue 1-13 exactly, die faces
continue from 1; pct fields -1..100, counts 0..3, pluses
0..5, max 1..5.

SEAM: partyView cache (R1032-R1038 idiom) +
subtableProfForToken (NOT profForToken - the castle seam's
profForToken lives in the SAME unnamed namespace later in
the file; a redefinition would break the build; ALWAYS grep
the whole TU for helper-name collisions before the seam),
kindForToken, rollPartyTable (the retired rollTable; "(d8,
d6)" half-dice reading kept verbatim), applyItem rewritten
onto the registry row (r.a/r.b), rollMagicItemsFor rewritten
onto the ladder row (defensive none{} value-init, R1036
lesson 2). KEPT VERBATIM: classForProf, characterLevelFor,
henchmanLevelFor, raceAllowsClass (sliced programmatically
from the parsed region at splice time - never hand-
transcribed), enum ProfId, enum ItemKind. rollCharacterParty
(public, outside the region): only the two
kProfTable[cand].max reads -> profMax(cand) (replace with
expected count 2). profFor signature unchanged (R64 city /
R65 planar / rollCharacterParty callers). ENC_LOAD adds
encounters_party after the castle line; regtest include
after the R1038 line. Fragment r1039_party_encounter_
registry.h, 7 sections (load/counts/subtable/ladder/items/
party/roll), printfs "R1039 party encounter registry <sec>
audit: bad %d". Cross-region sweep CLEAN (the sweep's
ItemRow hit in dm/treasure.cpp and MonkLadderRow in
rules/phb are unrelated pre-existing file-local symbols).

FLIGHT RECORD (ONE canvas version, chunkcheck PASS first
delivery; preflight GREEN first try - the R1038 emulation
lesson, applied author-side, held): the pre-delivery
emulation script (emulate_r1039.py, kept in r1039_work)
modeled the load-section has* pin semantics (valid iff the
pin agrees with the model - no phantom negatives), dir
counts nf=6/kf=7/df=20/wf=9/of=21/cf=9/xf=5/pf=2, list
size 20, all 87 data pins (10 subtable + 13 ladder + 64
item), and the chain invariants against the emitted lua:
emulation bad = 0 before packing.
- Anchor lesson: "// R53: the Character Subtable" ALSO
  matches an inline comment at line ~282 ("resolves here");
  src.index found that one first. Region anchors must be
  the FULL header line (grep every anchor for collisions
  before building - same family as the R1037 anchor-drift
  lesson).
- Build lesson: retired-token checks scan the SEAM TEXT too -
  the seam's own provenance comments must not quote the
  retired identifiers (kProfTable in a comment tripped the
  check).
- Bash lesson: heredoc'd emulators kept eating their own
  regexes; write the emulator to a FILE and run it (kept
  for reuse: /home/user/r1039_work/emulate_r1039.py).
- /tmp reset wiped main39/r1039_work mid-round: rebuilt from
  the repo; rehearsal trees rehearse5/rehearse6 under /tmp
  are disposable, delivery canvas + Knowledge persist.

VERIFIED: landed main@ac714faf codeload (tgz md5
b9dc075f68b5d065d7ca418c74db1bc7) - census 997, 6 party
lua present, tool md5 bf1cda6b9f32bf865f9b1d244264dcc8
matches, kProfTable/kLadder zero occurrences in
dm/encounters.cpp, fragment + registry header + regtest
carry the R1039 marks.

STATE: R1039 LANDED (main ac714faf, census 997). The DMG
Appendix C encounter engine plus its party-generation
tables are registry-native end to end. Remaining printed
percentile tables in dm/encounters.cpp: NONE - the de-wire
march through the Appendix C region is COMPLETE (only small
name lists remain: kPrinces/kArchDevils/kNames, not
percentile tables). Next candidates are elsewhere: the R53
subtable consumers (all registry-native now), the Appendix
P convention party (r156 fragment, dm/appendixp.h -
rollMemberMagic kit tables), or a new region survey of
hard-coded tables outside dm/encounters.cpp (e.g.
dm/treasure.cpp ItemRow family, rules/phb ladders). Next
work awaits Curtiss's GO.

== R1040: Appendix P convention-party tables de-wire ==
Date: 2026-11-14. LANDED main@8d948559 (census 1004).

TARGET: dm/appendixp.h (header-only, 233 lines, namespace
dm::appendixp) - the R147/R156 convention-party module
(DMG pp.225-226). Retired 8 printed tables into NEW dir
content/tables/appendixp/ (6 lua): band_level (9 rows
{band,option,level={lo,hi}}, bands 1-3 x options 1-3),
protective + weapons (7 rows each, TRANSPOSED {col,fighter,
magic_user,cleric,thief} - the source was 4 rows x 7 cols;
rows emit per printed COLUMN), potions (4 rows {class,pct,
max}), potion_types (10 rows {die,key}), kit (4 rows
{class,armorPct,weaponPct,shieldPct}).

STRUCT/REGISTRY: EncounterAppendixPRow (lo/hi + key + band/
option + fighter/magic_user/cleric/thief + pct/max +
armorPct/weaponPct/shieldPct, all defaulted; ordinal rides
row.lo=row.hi for gear/potions/types/kit, level pair for
band), m_appendixp, hasAppendixP/appendixPRows. Loader: one
else-if branch for 6 exact keys at the final-else anchor;
row-key lists kAppendixP{Band,Gear,Potion,Type,Kit}Keys
after kPartyItemKeys. NO ENC_LOAD change - the module is
header-only.

KEY DISCOVERY: encReg() is file-STATIC to
dm/encounters.cpp - a header cannot use it. Header-only
modules own their load: an inline apReg() singleton
(function-local static in an inline function = shared
across TUs) self-loads "content/tables/appendixp", plus
inline apView(name) per-TU cache (R1032-R1039 idiom).
appendixp.h gains #include "EncounterTableRegistry.h".
Helper names collision-checked: apReg/apView free.

SEAM: bandLevelLo/bandLevelHi (registry reads, defensive
1/2), protectivePct/weaponPct (row keyed col+1, class field
pick), potionPct/potionMax/potionType (potionType returns
r.key.c_str()), rollMemberMagic (kit row; shield via
shieldPct, classes 0/2 only). KEPT VERBATIM: abilityRoll,
the itemChance chain (Gonzo 135/54/9), rollItemPlus,
MemberMagic, SpurMember, rollSpurMember, enum LevelBand.
All public signatures unchanged (r147/r156 audits pin
them, untouched). RETIRED_TOKENS in appendixp.h only:
lo[3][3]/hi[3][3]/t[4][7]/static const int t[4]/k[10]/
kArmor/kWeapon.

FRAGMENT: rules/audits/r1040_appendixp_registry.h, 7
sections (load/counts/band/gear/potions/chain/member),
census 997->1004, printfs "R1040 appendixp registry <sec>
audit: bad %d". Section 6/7 use rules::Rng rng(1040). Dir
counts af=6 nf=6 kf=7 df=20 wf=9 of=21 cf=9 xf=5 pf=2
(psionic_table.lua rides the psionic dir but dispatches
into m_planar - key-based, not dir-based). Negative pins
hasAppendixP("")/("castle_type")/("appendixp_band") etc -
all keys genuinely absent from their maps (R1038 phantom
trap checked by emulation).

FLIGHT RECORD (TWO canvas versions; v1 FAILED the user's
preflight, v2 green - the round's big lesson):
- v1 bug: the loader's band-chain guard demanded
  prevOpt == 3 on the FIRST row (prevBand=0, prevOpt=0),
  so appendixp_band_level was REJECTED at load; bandLevelLo/
  Hi fell to defensive 1/2 -> R147 audit "bad 15" (7 of 9
  lo cells + 8 of 9 hi cells mismatch the defensive
  defaults - the count decodes the cause), regtest aborted
  at r147's return 1, and EVERY audit after r147 reported
  "appears 0 times" in the census (cascade, not 1004 real
  failures). Fix: prevBand != 0 && (bd != prevBand+1 ||
  prevOpt != 3). Second guard of the same class NOT
  present elsewhere: the ordinal families use
  c != prevKey + 1 with prevKey=0 init - first row passes.
- LESSON (extends the R1038 emulation lesson): the
  pre-delivery emulator modeled the PINS but not the
  LOADER. Model the loader's chain checks (order, ranges,
  first-row transitions) against the emitted lua too -
  loader_model.py now gates before packing, alongside the
  pin emulator. A defensive default's mismatch COUNT in a
  downstream audit decodes which table failed to load.
- v1 recovered cleanly because nothing was committed: the
  reset is git reset --hard HEAD && git clean -fd, then
  re-deliver the fixed canvas (v2). Rehearsal re-verified:
  fresh splice, idempotence, second-tree diff -r identical,
  loader model bad 0, seam/fragment checks.
- Delivery v2 canvas r1040-delivery-v2, tool md5
  5aeee661c3490532b9fc6da640b8b9b8, chunkcheck three
  drills green (clean PASS / auto-repair 1 PASS /
  both-copies FAIL exit 1). chunkcheck --verify skips
  re-extraction - use it for the corrupt drills (a bare
  run re-extracts and erases the corruption: auto-repair
  0 is the tell).
- /tmp reset again mid-round (env upgrade): main40.tgz
  fetched fresh from codeload ac714faf (codeload regenerates
  tarballs - the md5 changes, the tree does not); the tool
  was recovered from the delivery canvas itself
  (chunkcheck extract path), rehearsed, fixed, repacked.

VERIFIED: landed main@8d948559 codeload - census 1004, 6
appendixp lua present, tool md5 5aeee661c3490532b9fc6da640b
8b9b8 matches, kArmor zero in dm/appendixp.h, the fixed
guard (prevBand != 0) present in EncounterTableRegistry.cpp.

STATE: R1040 LANDED (main 8d948559, census 1004). The
Appendix P convention-party module is registry-native end
to end; dm/appendixp.h carries no printed arrays. The
de-wire march now has proven precedent for header-only
modules (own inline singleton - do not reach for encReg).
Next candidates: dm/treasure.cpp ItemRow family, rules/phb
ladders, or a fresh survey of hard-coded tables outside
the encounter region. Next work awaits Curtiss's GO.

=== R1041: treasure item tables de-wire =========================
STATUS: LANDED main@1ca7f1c6, 2026-11-14, census 1010
(verified codeload: 7 treasure lua present, tool md5
6d44b431dda9395831ca8de63cb04de8 matches, kPotions and
the whole ItemRow family zero in dm/treasure.cpp,
xp_hi keys + tables = {} in all 7 lua, regtest include
after the r1040 line, emulator bad 0 on the landed tree).

WORK: retired the 7 ItemRow percentile tables from
dm/treasure.cpp (DMG III.A potions 35 / III.C rings 24 /
III.D rods 30 / III.E Special artifacts 29 / III.F armor
26 / III.G swords 26 / III.H weapons 36, 206 rows) into
content/tables/treasure/ (7 lua, def keys = file stems =
set names treasure_potions etc., rows on the
items::MiscItemRow schema). III.B scrolls (kSpellScrolls/
ScrollRow) KEPT in-file. Seam file-local like the miscReg
idiom: tReg() singleton loads content/tables/treasure;
itemView(set) band-sorted per-view cache; category cases
{0,2,3,9,10,11,12} route through kSetFor[13] (1,4-8
nullptr); magicTablePinCount/magicTablePin route through
itemView with refusal semantics. Fragment
rules/audits/r1041_treasure_item_registry.h: 6 sections
(load/counts/bands/data/rows/edges) loading its own fresh
items::MiscItemRegistry; pins load==7, r122 kRows all 13
{35,25,24,30,33,30,33,36,35,26,26,36,29}, famous rows by
magicTablePin (cat, 0-based index) - Delusion (0,4),
Poison zeros (0,28), Water Breathing FLAT 400/0/900/0
(0,34) - NOT a range, Ring of Protection (2,11), Shield
-1 missile attractor gp 750 (9,25), twin Hammer +2
(11,18)/(11,19), Arrow +2 qty 2-16 (11,1), Throne of the
Gods zeros (12,27), Orb of the Dragonkind gp 10000-80000
(12,18) - plus a full 206-row engine-registry cross-read
and refusal edges. Commit 1ca7f1c6: 2 modified (dm/
treasure.cpp, regtest.cpp) + 9 added (7 lua + fragment +
tool). Printfs "R1041 treasure item registry <sec> audit:
bad %d".

FLIGHT RECORD (THREE canvas versions; v1 AND v2 both
failed the user's preflight with the SAME all-zero
census signature - the round's lesson pair):
- SHARED SIGNATURE: battery printed nothing (no "loaded
  1338", no audit lines), "BUILD: 0 warnings", then
  census: every pattern 0 times. Decode: regtest
  SEGFAULTED before the first ~4KB stdio flush (block-
  buffered pipe; the buffer is lost on crash) -> empty
  batfile -> the census script counts an empty file ->
  all-zero. ALL-ZERO CENSUS IS THE SIGNATURE OF AN EARLY
  CRASH, NOT 1000 REAL FAILURES. All three of: battery
  empty, build clean, census all-zero together mean
  "regtest died early", not "everything failed".
- MECHANICS: every load rejection lands in errors()
  (never stderr) - a silently empty view is
  indistinguishable from "loaded fine" until the first
  row fetch, and pickMiscRow's rows.back() on an EMPTY
  vector segfaults at the first magic-item roll (the
  statistical audit rolls early, before r122 can
  report). A rejected def gives NO console trace - the
  only observable is the crash.
- v1 bug: tables[] is MANDATORY in parseDef (lua_getfield
  then !lua_istable -> "missing tables[]") - my loader
  model had marked it optional. v2 added tables = {} to
  every emitted file - REAL fix, but insufficient.
- v2 bug (found on the third attempt, by READING the real
  loader end to end against the emitted lua): kRowKeys is
  {name, set, band, xp, xp_hi, gp, gp_hi, qty} - the row
  fields are xp_hi/gp_hi, NOT xp_high/gp_high. v2's 206
  rows all carried xp_high/gp_high -> checkAllowedKeys
  "unknown key 'xp_high'" -> all 7 defs rejected -> same
  empty-view segfault. LESSON: the loader SOURCE is the
  authority - every key spellings must be transcribed
  from parseDef/kXxxKeys arrays verbatim, and the
  emulator must enforce the allowlists EXACTLY (model
  kDefKeys/kRowKeys/kSourceKeys/kPinKeys/kTableKeys as
  literal key sets, not as "the fields I remember").
  C++ struct fields (r.xpHi) and lua keys (xp_hi) differ;
  check both independently.
- TRIAGE LESSON (third attempt): verify the USER'S TREE
  VERSION before re-diagnosing. md5sum the tool +
  grep a fix marker in emitted data distinguishes
  "stale v1 splice in their tree" from "v2 fix is
  wrong". This round the user answered v2 markers were
  present - which ruled out a skipped re-splice and
  forced the real v3 bug hunt. Also: when the signature
  repeats EXACTLY after a fix, suspect a SECOND schema
  miss of the same class, not a failed delivery.
- v3 tool fixed LUA_ROW (xp_hi/gp_hi), the round-trip
  regex, and the header comment; emulator rebuilt strict
  (rows parsed per-line strip + fullmatch - match() on
  indented lines fails silently, another silent-zero
  trap); famous-row pins then cross-checked scripted
  against the emitted lua (all 10 pins exact, including
  Water Breathing flat 400/900 - my own emulator first
  flagged it as a "range" because I misread the flight
  note; the pristine kPotions row 400,0,900,0 is the
  authority).
- Rehearsal (v3): fresh splice, idempotence ("applied 0,
  already 1"), second-tree diff -r identical, emulator
  bad 0 on both trees, retired tokens zero in the seam,
  chunkcheck three drills green (clean PASS / auto-repair
  1 PASS / both-copies FAIL exit 1). User preflight
  finally GREEN: six "R1041 treasure item registry ...
  bad 0", census 1010.
- Env resets hit twice more mid-round: /home/user/r1041_
  work and /tmp tarballs wiped both times; recovered via
  codeload refetch + chunkcheck extract from the delivery
  canvas + emulator rewritten from this record. Heredoc
  regex-mangling struck again (a python heredoc replace
  of regex backslashes silently failed - grep afterwards
  showed xp_high STILL in the tool; the edit tool on a
  /home/user copy fixed it). NEVER patch regex-bearing
  code through bash heredocs - edit tool or write_file
  only.

STATE: R1041 LANDED (main 1ca7f1c6, census 1010). The
treasure magic-item tables are registry-native; dm/
treasure.cpp carries no printed percentile arrays
(only III.B scrolls in-file, by design). De-wire
precedent now covers both a header-only module (R1040)
and a table-family seam with per-view caches (R1041).
Next candidates: rules/phb ladders, or a fresh survey
of hard-coded tables outside the encounter region.
Next work awaits Curtiss's GO.

=== R1042: equipment cost tables de-wire =========================
STATUS: LANDED main@4f0d8aa5, 2026-11-14, census 1016
(verified codeload: 3 equipment lua present, tool md5
1da10cf3ff8be9fea219d9314c2c4c3e matches, every static
price array zero in rules/phb/equipcosts.h, tables
entries + tables = {} in the lua, regtest include
after the r1041 line, emulator bad 0 on the landed
tree). FIRST-ATTEMPT LANDING - the round's process
lesson paid off.

WORK: retired the PHB BASIC EQUIPMENT AND SUPPLIES
COSTS tables from rules/phb/equipcosts.h into
content/tables/equipment/ (3 lua: equipment_arms 52,
equipment_armor 14, equipment_general 99 = 165 rows)
on the items::MiscItemRow schema with a coin
ENCODING: band = { i, i } the printed row index,
gp = the printed price in its printed coin, qty = {
coin, 0 } the coin code (1 copper, 2 silver, 3
gold; exactly one coin nonzero per row - the R300a
identity preserved into the schema). The general
list structure rides the def's tables[] block
NATIVELY: list_counts {11,3,21,29,10,6,9,10} and
list_first {0,11,14,35,64,74,80,89} as named
integer arrays - the first time tables[] carried
real data in a de-wire (R1041 left it empty).
Monetary pins (20 sp = 1 gp, 10 cp = 1 sp,
200 cp = 1 gp) STAY in-file (constants, not
tables). Seam header-only (the R1040 appendixp.h
idiom): eqReg() inline singleton loads
content/tables/equipment; eqView(key) per-TU
static map cache (function-local statics in inline
functions are shared across TUs); every eqc*
signature and clamp UNCHANGED (r300/r300a/r308
audits and the town stores pin them); empty-view
defensive guards (return ""/0 - never an unguarded
vector index; the R1041 rows.back() lesson made
explicit). Fragment
rules/audits/r1042_equipment_cost_registry.h: 6
sections (load/counts/bands/data/rows/edges),
fresh items::MiscItemRegistry; pins load==3, row
counts via the accessors, coin split 59/29/11,
list counts/firsts vs accessors for all 8 lists,
def pins (RowCount per def; the general def also
carries CoinSplit = cp*1000000 + sp*1000 + gp =
11029059), famous rows by computed index (arrow
single 2 sp, arrow dozen 1 gp, composite longbow
100 gp, javelin 10 sp, bastard sword 25, long
sword 15, two-handed 30, banded 90, plate 400,
belt 3 sp, ale pint 1 sp, garlic 5 cp, wolvesbane
10 sp, heavy warhorse 300, silver holy symbol 50,
war ship 20000, wagon 150), full 165-row
engine-registry cross-read, clamp edges.
Commit 4f0d8aa5: 2 modified (rules/phb/
equipcosts.h, regtest.cpp) + 5 added (3 lua +
fragment + tool). Printfs "R1042 equipment cost
registry <sec> audit: bad %d".

FLIGHT RECORD (one canvas, clean landing):
- TARGET SURVEY: candidates were phb ladders
(subclasses/bard), equipcosts.h, and dm/
appendixi.h dressing tables (needs a NEW band-
text registry - deferred). Curtiss picked
equipcosts (closest MiscItemRegistry fit). The
one-coin-per-row print identity made the qty
coin-code encoding clean.
- HAND-TRANSCRIPTION LESSON (round's big catch):
the fragment's famous-row pins are computed by
the tool from the PARSED arrays with a build-time
die() self-check, and the check caught THREE wrong
hand-transcribed values during the build (ale
pint 3 sp -> really 1 sp; wolvesbane 3 cp ->
really 10 sp; war ship 25000 -> really 20000;
plus symbol holy silver 25 -> 50). Standing rule
now explicit: NEVER hand-transcribe pin values
into a fragment - compute them from the parsed
source and let the tool die() on disagreement.
- Tool bug caught in rehearsal round one: int-
array parser captured the [N] in the declaration
itself (52 extra int). Always parse the block
AFTER the decl string, not from its start.
- CANVAS MD5 LESSON (delivery-flow): the
whole-file canvas md5 quoted by delivery_pack
is NOT stable across the UI export path (the
r1042 canvas was 133f1842 at pack time,
445b4230 on disk later, and the user's exported
canvas.md was 59036b6a - all three differ while
the payload is byte-perfect). The chunkcheck
GATE lines INSIDE the canvas are the identity
check: "grep -m1 'GATE file' canvas.md" +
"GATE path" name the tool and its md5 before
any extraction. Do not gate the delivery on the
whole-file md5; gate on the GATE lines, then
let chunkcheck's internal gates (b64 md5, chunk
hashes) do the byte validation. R1041 v3 had
the same silent mismatch and passed for the
same reason.
- Rehearsal: splice green, idempotence green,
second-tree diff -r identical, emulator bad 0 on
both trees (rebuilt once after an env reset wiped
the work dir - recover from the Knowledge flight
record), chunkcheck three drills green (clean
PASS / auto-repair 1 PASS / both-copies FAIL
exit 1). User preflight GREEN first try: six
"R1042 equipment cost registry ... bad 0",
r300/r300a/r308 still green through the seam,
census 1016.
- Block 0 lesson: check git status BEFORE
assuming clean; the user's tree carried stale
?? canvas.md/chunkcheck.sh from a previous
export. Untracked scratch is fine (the commit
block excludes it) but IDENTIFY the canvas via
GATE lines before extracting.

STATE: R1042 LANDED (main 4f0d8aa5, census 1016).
The PHB equipment price tables are registry-
native; equipcosts.h carries no price arrays
(only the monetary constants). De-wire precedent
now covers: header-only modules (R1040),
percentile band families (R1041), and price/
ladder tables with index-band + encoded-coin rows
plus tables[] carrying real list structure data
(R1042). Next candidates: rules/phb ladders
(subclasses/bard xp-title pairs - band = xp
range, name = title fits MiscItemRow cleanly),
dm/appendixi.h dressing tables (needs a new
band-text registry and loader), or a fresh survey
of remaining hard-coded tables outside the
encounter region (armorratings, equipcosts done,
weapontables.h 680 lines / 50 weapons is the
biggest phb fish left). Next work awaits
Curtiss's GO.

=== R1043: weapon chart tables de-wire =========================

STATUS: LANDED main@8972cdba, 2026-11-14, census 1022
(2 modified: rules/phb/weapontables.h, regtest.cpp;
9 added: 7 lua + fragment + tool). SECOND-ATTEMPT
landing - v1 failed the user's preflight with
"R189 weapon tables verify audit: bad 102" and a
census flood of zeros (user ^C'd). The failure
was a REAL bad N in an early audit whose return
gate aborts regtest, so every later census
pattern counted 0 - a cascade shape DISTINCT
from the R1041 all-zero segfault signature: the
battery printed normally (loaded 1338, monster
dump, earlier audits) up to the abort point.
Count the visible "bad N" to find the failing
audit.

WORK: retired the PHB weapon weight/damage chart,
the 18-row speed verify list and the five class
allowlists from rules/phb/weapontables.h into
content/tables/weapons/ (7 lua = def keys:
weapon_chart 50, weapon_speed 18, weapon_cleric
7, weapon_druid 9, weapon_mu_illusionist 3,
weapon_thief 8, weapon_monk 24 = 159 rows).
Chart encoding: band = { i, i } the print index,
gp = the printed weight in gp (spear minimum
40), qty = the S-M damage pair, xp/xp_hi = the
L damage pair (LITERALLY the L pair in the xp
slots - the loader slots are just numbers; the
r189 pins ride through unchanged). Speed rows:
gp = the factor, rest zero. List rows: name-only.
Seam header-only (R1040/R1042 idiom): wtReg()
inline singleton, wtView(name) per-TU static map
cache, all accessor signatures + clamps
unchanged (r158/r189/r198/r337 + the combat
engine pin them). In-file survivors:
spearWeightRange{40,60}, lanceChargingDouble,
spearSetChargingDouble, back+2/stunned+4,
classUsesAnyWeapon, weaponAllowedForClass
mechanics, classOilUse/classPoisonUse/
classPoisonUseForAlignment, classAllowance
Yes/Never/Referee. Fragment
rules/audits/r1043_weapon_chart_registry.h: 6
sections (load/counts/bands/data/rows/edges),
printfs "R1043 weapon chart registry <sec>
audit: bad %d", pins computed from the parsed
arrays. Retired tokens all zero, including the
file-scope kCleric[7]/kDruid[9]/kMuIll[3]/
kThief[8]/kMonk[24] and WEAPON_CHART_ROWS.
regtest include after the r1042 line.

THE V1 BUG (round's big lesson - tuple arity
mismatch): the parse built 7-wide chart tuples
(name, weight, sm_lo, sm_hi, l_lo, l_hi + the
stray 0), but LUA_ROW's emitter formats 6
slots: % (r[0], key, i, i, r[1], r[2], r[3],
0, r[4], r[5]). So qty = { r[4], r[5] } =
{ 0, sm_lo } - the sm_hi was DROPPED and the
S-M pair shifted: arrow emitted qty { 0, 1 }
instead of { 1, 6 }. ~100 SM checks + spot pins
= exactly the 102. Speed/list rows were immune
(their slots 4/5 are zeros). THREE verification
layers missed it, each for a structural reason:
(1) the round-trip compared the emission against
the SAME wrongly-shaped tuples - an
emission-vs-emission check is blind to arity
bugs because both sides carry them; (2) the
emulator's pair check was ordering-only (lo >
hi); 0 > sm_lo is false for every row with a
nonzero min; (3) nothing cross-read the emitted
data against the ORIGINAL parsed source. The
v2 hardening rules, now standing:
- round-trips must CROSS-READ the emission
  against the original parsed source (semantic
  check), never only against the input tuples
  handed to the emitter;
- pair invariants must reject DEGENERATE values
  (qtyLo = 0 where the printed mins are >= 1,
  xp = 0 on chart rows), not just ordering
  (lo > hi);
- lua_def now dies on any row tuple whose len
  != the emitter's slot count - the arity guard
  is the cheapest and came last; make it the
  first check written into a new emitter.
- The hardened emulator (emulate_r1043.py v2)
  parses the pristine header arrays
  independently and cross-reads every emitted
  row, plus famous r189 pins (arrow {1,6},
  battle axe {1,8}, row 26 L {3,18}, row 43
  SM {2,8}/L {2,16}, row 47 weight 250/L
  {3,18}, spear idx40 weight 40, voulge idx49
  weight 125, speed fist 1/dagger 2/spear 7).
  Regression-tested: a re-injected {0,1} arrow
  fails both the cross-read and the degenerate-
  min invariant.
- Header-parse gotcha (hit AGAIN in the v2
  emulator rebuild): anchoring an int-array
  parse on the ACCESSOR NAME captures the
  function-body brace, so the array size N
  leaks in as element 0 (51 values, shifted).
  The R1042 lesson said parse the block AFTER
  the decl; for accessor-name anchors, slice
  [1:] or anchor on the array name itself.
- Recovery path worked as designed: env reset
  wiped the work dir, but the v1 canvas
  survived under canvases/r1043-delivery;
  chunkcheck recovered the tool byte-exact
  (md5 match), and the fix was patched onto
  it. v2 delivered as canvases/r1043-delivery-v2
  (tool md5 a0ba573f009c55ef1c0333a62a94a130,
  4 chunks; the v1 canvas is superseded -
  chunkcheck identifies via GATE lines, and
  only the GATE tool md5 distinguishes v1
  43c197a0 from v2 a0ba573f, so name the
  canvas in the delivery blocks). Three
  chunkcheck drills green (clean PASS /
  auto-repair 1 / both-copies FAIL exit 1).
  User preflight GREEN on the v2: r189 bad 0
  through the seam, six R1043 sections bad 0,
  census 1022.
- Block 0 reset: the user's tree had the v1
  splice applied UNCOMMITTED - git reset
  --hard 4f0d8aa5 && git clean -fd before
  re-splicing v2. Expect that pattern whenever
  a failed splice was already applied.

STATE: R1043 LANDED (main 8972cdba, census
1022). The PHB weapon tables are registry-native;
weapontables.h carries no chart/speed/list arrays
(only the mechanics: charging doubles, weight
range, clamps, class-use encodings). De-wire
precedent now covers: header-only modules (R1040),
percentile bands (R1041), price tables with
tables[] structure (R1042), and multi-family
chart+list sets with re-purposed loader slots
(R1043). weapontables.h was the biggest phb fish
left; remaining candidates: the phb ladders
(subclasses/bard xp-title pairs), dm/appendixi.h
dressing tables (needs a band-text registry), or a
fresh survey outside the encounter region. Next
work awaits Curtiss's GO.
