---
name: adnd1-splice-work
description: Curtiss's Adnd1 repo pin-round workflow - the splice ritual conventions, verification steps, and standing decisions (v3, rebuilt at the R848 fresh start)
---

# Adnd1 splice work (v3, rebuilt at the R848 fresh start)

Rebuilt at the R848 fresh start (v3, 2026-10-25, commit 96831bb,
census 771). The v2 era snapshots live in the repo at doc/vibe/:
adnd1_knowledge_backup_v3.md (the full pre-restart knowledge
topic - the conventions, the lessons, the records R600-R848, the
R389-R599 archive and the R504-R510 extraction grids) and
adnd1_seed_backup_v3.md (the accumulated v2 seed - the records
R313-R847 under the R314-era conventions). Reference them on
demand, never load wholesale; the rounds R313-R847 also live in
the git history of adnd1_knowledge_seed_v2.md. The pre-v2
history (R172-R312) stays at adnd1_knowledge_backup_v2.md.

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

## Current state (post-R848)

- HEAD 96831bb ("R848: the FF magic item tables (census 771)"),
  battery census 771 audit lines, registry floor 995.
- Gap reports: mm2 37/0 closed. The R596-era standing states
  (UA 102/0, MotP 90/0, DMG 81/0, PHB 49/0, DSG 155/0, WSG
  186/0) hold as recorded; re-verify at HEAD before scoping.
- Round shape since R846: the spec-driven splice (tools/
  spec_rNNN.json -> splice_engine.py -> rverify.py), prefix per
  round (ffn/ffo/ffq - ALWAYS verify prefix freedom in
  regtest.cpp AND header_file availability in rules/ before
  authoring: R848 lost its first choice ffp to the R836 header).
- The next round is R849; its spec seats the R848 record
  (prev_record) sourced from adnd1_knowledge_backup_v3.md
  (top of the records block, PART 1 Round state).

## Round state (update each land)

## Knowledge maintenance

- Each land appends ONE entry to Round state above (date,
  commit, census, what landed, the lessons) - terse; the repo
  carries the code and the gap reports.
- When this file balloons past ~100KB, run the fresh start
  again (v4): backup + seed + continuation prompt saved to
  doc/vibe/ with a v4 suffix and committed BEFORE wiping
  knowledge and chats - the v3 process is the template.

## Tooling (R428, updated at R848)

- The splice engine: tools/splice_engine.py + speclib.py +
  rverify.py. A round is a JSON spec run through the engine;
  the battery derives from the spec (every table cell, every
  const, every bool). Future splices insert records above as
  usual.

