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

- R848 LANDED 2026-10-25: commit
  96831bb65334302564a3c0bbbf92cdf24207acdd
  (pushed 4024a96..96831bb,
  census 770 -> 771), THE FF
  MAGIC ITEM TABLES - round three
  of the three FF table-group rounds
  (the table-group closer). THE
  WALK: 5 tables, 77 rows, every
  cell pinned - the 13 party magic
  bands (print p. 101, the
  Individual-is-Nth-level rows, N
  1-13, one percent-chance and
  count pair per offered table,
  the percentage dropped at the
  automatic rows: Table I automatic
  from 10th, Table II from 12th,
  Table III at 13th) and the four
  die tables (print pp. 101-102:
  Table I 20, Table II 16, Table
  III 16, Table IV 12; 64 roster
  labels). THE SHAPE: the band
  cols Ord/Pct/Num per table
  I-IV (Pct 0 with Count 0 = not
  offered, 0 with Count above 0 =
  automatic), the item cols
  Ord/Ct (Ord the 64-label roster
  ordinal, first appearance
  Tables I-IV; Ct the printed
  leading count), tags Bnd/T1/T2/
  T3/T4, prefix ffq (ffp taken:
  the R836 promotion header owns
  rules/ffp.h). THE CENSUS PINS:
  ZERO registry defs touched (the
  item rows are not monster
  listings, no defs promoted, the
  registry floor holds at 995). THE
  ADJUDICATIONS (the four-voice
  collation - djvu, the
  word-geometry xml, abbyy and the
  pdf Capture layer - the DMG
  npcparty parity the
  tie-breaker): 18 forced repairs
  (the party-prose garbles Ittirm =
  Items and i item = 1 item, the
  Table i/M/ML/111/lit name
  garbles, the (d8 n d6) header,
  41 = +1, the super-heroism
  comma, chairman = chainmail, the
  robe b fending = blending, the
  talisman of, the pdf ,BLE and
  sdint garbles). THE NOTED INK:
  the ring of protection +1 (both
  char voices drop the +1, the pdf
  Capture voice reads it, the DMG
  parity agrees - pinned), the FF
  dust of appearance against the
  DMG dust of disappearance (FF ink
  pinned, the divergence noted),
  the +1 (or +2) et al dagger row
  without the DMG six-dagger
  footnote, the (d8, d6) linear
  convention (d6 1-3 the d8 result
  1-8, d6 4-6 d8+8, 9-16), the
  personal-select advice and the
  groups-or-multiples note, and the
  bands match the DMG listing
  exactly. Header rules/ffq.h (12
  consts + 11 bools + 17 table
  cols, inline 40), audit "R848 FF
  magic item tables audit", rode
  rules/audits/r848_batch.h; 16
  examples; rverify double-run
  GREEN, 268 mutants 0 missed; the
  R847 record seated into the seed.
  Spec tools/spec_r848.json, md5
  a2d67003832b6f6450c9789d5ea51eb3
  (authored-plus-newline). NEXT:
  the FF table-group arc closed
  (round three of three); the
  splice queue reopens with
  Curtiss's call.
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
## Increment (appended 2026-10-27, R848 -> R886)

The delta since the R848 snapshot, appended in place:
the new standing decisions and seams, the round records
R849-R886, and the current state at R886. Everything
above this header stays the R848 content, unchanged.

### New standing decisions (post-R848)

- **AN INVOLUNTARY CHAT ROLLOVER RECOVERS
  CLEANLY (user-confirmed 2026-10-25: a
  landing paste hit the chat limit and the
  follow-on chat verified the round and
  seated it without problems)**: the landing
  is atomic OUTSIDE the chat - ./rn runs
  md5sum, the engine double-run, preflight
  and the git commit/push on Termux before
  the landing output is ever pasted - so the
  chat only verifies and seats. On a
  rollover the new chat reads this topic,
  takes the landing verification from the
  repo (git log at HEAD, the census, the
  gap-report flips), seats the record from
  the spec/header/commit (the record is
  DERIVED state - nothing unique is lost),
  then waits for go. If the chat died
  BEFORE ./rn ran: nothing applied, GitHub
  holds at the base sha, the spec canvas is
  durable - re-issue the same md5 handoff,
  zero re-authoring. Roll at round
  boundaries when possible, but the boundary
  is a preference, not a guarantee.

- **A LANDED + VERIFIED ROUND IS ALWAYS SEATED AND
  SAVED IN THE KNOWLEDGE (user-set 2026-10-27):**
  after a round lands and is verified, seating
  the landed record into this Knowledge topic
  is not optional or deferred - it is part of
  the round's completion. The full sequence per
  land: verify byte-exact against the rebuild
  (fresh tarball at the new SHA, spec/header/
  audit/census/defs/seed), seat the record at
  Round state (rindex before the last
  '## Knowledge maintenance'-style anchor, <=51
  cols, ends 'WAIT FOR GO.'), rewrite Current
  state for the new HEAD - then WAIT FOR GO
  before any next-round work.

### New standing seams (post-R848)

- **D&DG ARC PLAN (discussion state, 2026-10-25, awaiting go):**
  the two deity books are ONE book - the D&DG 1st printing
  (1980, 144pp, 17 mythoi incl. Cthulhu + Melnibonean) is the
  primary-ink superset; Legends & Lore 1984 is the retitled Fifth
  printing with the interior identical to the late 15-pantheon
  D&DG prints - L&L is a parity voice plus at most one small
  divergence round, not a second book. USER CAVEAT: D&DG entries
  carry CHARACTER STATS (class/level and psionics, unlike every
  other monster book), so any deity registry promotion needs NEW
  .lua fields riding as schema adjustments (the DMO rank-field /
  MOP App II transform precedent); the pin headers are unaffected
  (prose codifies). DECIDED (Curtiss 2026-10-27,
  post-R878): the deity defs WILL be promoted -
  all the D&DG monsters (the deities and the
  monster races), generated only from the
  adjudicated pin headers,
  maintenance arc first, promotion after (Curtiss
  2026-10-27); the
  archive.org derivative inventory (tesseract voices needed?) is
  checked at go.
  INTAKE VERIFIED (2026-10-25, ddg.pdf upload): the PDF is the
  SECOND printing (1980) - 17 mythoi with Cthulhu p.43 and
  Melnibonean p.86 in the contents, the Chaosium credit PRESENT
  on print p.4 (the only 1st-vs-2nd delta, one bool); Erol Otus
  cover, ISBN 0-935696-22-9. CONTENTS MAP: front matter 1-11;
  American Indian 12-16, Arthurian 17-21, Babylonian 22-25,
  Celtic 26-31, Central American 32-36, Chinese 37-42, Cthulhu
  43-48, Egyptian 49-56, Finnish 57-62, Greek 63-74, Indian
  75-80, Japanese 81-85, Melnibonean 86-95, Nehwon 96-104,
  Nonhumans' Deities 105-112, Norse 113-124, Sumerian 125-127;
  App 1 planes 128-133, App 2 temple trappings 134, App 3
  clerical chart 134-142, App 4 + index 143. STAT BLOCK FORMAT
  (Hiawatha read, pdf p.15): hit POINTS not dice; the 5-slot
  class grid (CLERIC/DRUID, FIGHTER, MAGIC-USER/ILLUSIONIST,
  THIEF/ASSASSIN, MONK/BARD - "Nth level X" or Nil); six ability
  scores S/I/W/D/C/CH with exceptional-strength brackets
  (S: 21 (+4, +9)); MAGIC RESISTANCE "Standard" doctrine;
  psionic ability + attack/defense modes. EXTRACTION STATE: the
  upload bytes do not persist on this side (stub); the OCR
  artifact partially persisted (pdf pages 1-31 - all front
  matter plus early American Indian/Arthurian, enough for the
  R849 opener) before the 8,388,608-byte session quota reverted
  the rest; the remaining voices run Termux-side (the v2
  doctrine: pdfimages + tesseract --psm 4 + TSV) plus the
  archive.org derivative fetches per round - stream, never
  duplicate. REPO-AS-PERSISTENCE (user decision 2026-10-25):
  the Termux tesseract pass commits to the repo at
  extract/ddg/ - pNNN_full.txt (--psm 4) and pNNN_tsv.tsv
  (TSV geometry) per page, NNN = PDF PAGE INDEX (the
  print-folio offset rides in the gap report header; v2
  naming per the pNNN_full/pNNN_tsv and extract/r504
  precedents); every round fetches its pages from
  raw.githubusercontent at HEAD (the rverify mechanism),
  byte-exact and quota-free - the repo IS the voice
  persistence across chats. LANDED 2026-10-25: commit cd645b4
  (293 files, 155,430 insertions, pushed d2ec61a..cd645b4)
  - pNNN_full.txt + pNNN_tsv.tsv, pdf pp 1-146; gates passed
  (146/146 files, Hiawatha x3 on p015, near-zeros only on art/
  cover pages); folio offset PRINT = PDF-1 verified at BOTH
  ends (p132 carries printed folio 131); p001/p123/p146 are
  cover/full-page-art (near-empty is correct); p132 (print
  131) holds FIG. 4/5, the character-alignment graph and the
  planes-of-alignment figures - a pixel-work candidate for
  the planes appendix round. Junk commits ea1e35d/c6a890b
  (unexpanded-glob zero-byte files) removed at d2ec61a;
  pdf/ gitignored, pg-*.png kept local only.

- **MAINTENANCE ARC AFTER D&DG (user-set 2026-10-25):** the D&DG
  character-stat fields make the lua schema evolve, and schema
  evolution is a REGISTRY-WIDE pass - a post-D&DG maintenance arc
  adds the new fields to ALL defs of ALL books, sentinel values
  where a book has no such content, keeping the registry uniform
  (explicit data over loader defaults; no per-book special-casing
  in the coercers). Shape: a tool-round script pass over every
  .lua def (MM1 408, MM2, FF, the 65-def promotion, the D&DG
  defs - re-verify the floor at HEAD first), with a census audit
  that every def carries every field (fail-on-wrong). Batch
  schema changes into this arc - each later field addition
  re-triggers a pass, so normalizing once to the final post-D&DG
  schema avoids repeat passes. OTHER maintenance tasks ride the
  same arc (user: "there will be other maintenance tasks as
  well"); it gets its own gap report when Curtiss opens it.
  PROVENANCE CAVEAT (user, 2026-10-25): the MM1 @-record source
  was pdf-extracted text with prior preprocessing - it worked but
  was NAIVE, and some issues may remain unfixed in the generated
  defs; the MM1 text fields are the least-adjudicated ink in the
  registry (generated before the four-voice / tesseract-geometry
  discipline existed). MAINTENANCE-ARC CANDIDATE: an MM1 data-
  quality pass (re-verify suspect text fields against the print
  - collation work, NOT audit work: a garbled but valid string
  still trips the mutant battery, so the audits cannot see text
  infidelity). D&DG RULE THAT FOLLOWS: deity defs are generated
  ONLY from adjudicated pin headers (the promotion-from-headers
  doctrine, like the 65-def round) - never straight from
  extraction; the pin rounds are the firewall.
  SCRIPT FACTS (mm2lua.py at HEAD, read 2026-10-25): the schema
  truth is FIELD_ORDER (41 keys); emission is SPARSE today (None
  fields are skipped) - the sentinel doctrine means switching to
  FULL-FIELD emission plus a one-shot idempotent normalizer pass
  over all defs (byte-stable, DO-NOT-HAND-EDIT-compatible);
  psionic + attackDefenseModes ALREADY exist in the schema (the
  1e psionics fields); `source` generalizes by design (MM1/MM2/
  FF/DDG); family/race/familyText maps to the mythos structure
  (family = mythos, familyText = mythos intro prose); character
  stats follow the raw-string + cooked-numerics pattern
  (hitDice/hitDiceNum/hitDiceBonus/avgHp, xp/xpPerHp/xpValue) -
  a classLevelsRaw + parsed-components shape fits it; MISSING for
  deities: divine rank (the DMO rank precedent), worshippers'
  alignment, symbol / area of control (statNote/text candidates);
  sentinel values must be distinct from real print values so the
  audits stay fail-on-wrong.

### Round state additions (R849-R886)

- R849 LANDED 2026-10-26: commit
  55e32fc1ed257613a35ce258b25cf79948c72a34 (pushed
  cd645b4..55e32fc,
  census 771 -> 772), THE DDG FRONT
  MATTER - the D&DG arc opener,
  print pp. 1-11 (title, foreword,
  contents, preface, credits, the
  explanatory notes with the seven
  over-18 ability grids and the
  psionic class table, the standard
  divine abilities, the DMing
  doctrine with the intervention
  modifiers, the clerics and
  spell-granting ladder, the omens,
  the soul/spirit mortality
  doctrine, the divine ascension
  requirements). THE SHAPE: 9
  grids + 1 chain (61 grid rows:
  Str/Wis/Int/Dex/Con/Cha 7 rows
  each, the horror table -1 to -7,
  the psionic classes I-VI, the
  intervention modifiers), the
  monster intelligence ladder to
  godlike; header rules/dga.h
  (inline 237), prefix dga; audit
  "R849 DDG front matter audit",
  rode rules/audits/r849_batch.h;
  19 examples. ZERO registry defs
  touched - the floor holds at 995.
  THE ADJUDICATIONS (physical-copy
  eyeball, the extract primary):
  the strength 23 damage +11 (the
  OCR +1) and the psionic class V
  lettered modes (attack A,B,C,E;
  defense F,G,H). THE NEW-ARC
  LESSON: a NEW arc's gap report is
  a SEPARATE authored artifact -
  ./rn on the arc opener died at
  rd(GR) FileNotFoundError until
  tools/ddg_gap_report.md was
  authored (pre-flip, 24 boxes, the
  census slicing derived to the
  spec's 1/23: App 4 and the index
  split, plus the print-p.131 FIG.
  4/5 alignment-figures pixel-work
  box; md5 3f3fc4b61b9fac57c47913e8
  dacdc83c, 1357 bytes); the gap
  report header carries the folio
  offset PRINT = PDF - 1. Spec
  tools/spec_r849.json, md5
  538b848dcbcf7eed1f0768bdc9a4e45c
  (the engine died at the flip
  target read, tree clean, no
  unwind needed). NEXT: the D&DG
  walk continues from the American
  Indian mythos (print pp. 12-16)
  - WAIT FOR GO.

- R850 LANDED 2026-10-26: commit
  7e8df392b3c0d7f567098fa1dcecb1c98baeb891
  (pushed 55e32fc..7e8df39,
  census 772 -> 773), THE
  AMERICAN INDIAN MYTHOS - the
  D&DG walk round two, print
  pp. 12-16: fourteen beings
  (Raven, Coyote, Hastsezini,
  Hastseltsi, Heng, Hiawatha,
  Hotoru, Qagwaaz, Shakak,
  Snake-Man, Stoneribs, the
  Thunder Bird, Yanauluha,
  Tobadzistsini), the
  pantheon-wide cleric doctrine
  and the sacred bundle. THE
  SHAPE: 4 grids (combat,
  class, ability, roster; 36
  cols, 14 rows each - one row
  per being), 93 consts + 103
  bools + 25 examples, inline
  232; header rules/dgb.h,
  prefix dgb; audit "R850
  American Indian mythos
  audit", rode
  rules/audits/r850_batch.h.
  ZERO registry defs touched -
  the floor holds at 995. THE
  ADJUDICATIONS (the four-voice
  collation, settled before the
  rebuild): Heng/Hotoru/
  Yanauluha #AT printed 3/2
  (the 47-48px three-glyph
  width), Coyote psionic class
  III and Hastsezini II (the
  IA geometry 47px), Hastsezini
  CH -1 (both voices, the
  horror-table doctrine), Shakak
  CH 6 (both voices), the
  Thunder Bird X/22,600 xp
  line, Stoneribs size 5 and
  one half feet (66 inches) -
  the Hastsezini CH -1 and
  Shakak CH 6 cells flagged for
  the physical-copy eyeball.
  THE REBUILD LESSON
  (user-relevant): a session
  reset between delivery and
  land took the authored spec,
  the builder AND the b64
  canvas - nothing on the
  Vibe side is durable except
  what is committed or seated
  in Knowledge; the recovery
  re-fetched the repo at the
  base sha, rebuilt the spec
  from the extraction voices
  plus the seated adjudications
  (a fresh md5 - the old gate
  number died with the reset),
  and re-ran the full battery
  (700 mutants, 0 missed) before
  the re-issue. DELIVERY: raw
  JSON in a code canvas (no
  base64 - user-set this round);
  paste -> md5 gate ->
  head -c 61449 fallback for a
  nano-added trailing newline.
  Spec tools/spec_r850.json,
  md5 4eba5547393129cf1418472
  fe21b453b (61,449 bytes).
  NEXT: the D&DG walk
  continues (Curtiss's call on
  the next slice) - WAIT FOR
  GO.

- R851 LANDED 2026-10-26: commit
  550339f65296e4ac36e0f7e304c696b23805da80
  (pushed 7e8df39..550339f,
  census 773 -> 774), THE
  ARTHURIAN MYTHOS - the D&DG walk
  round three, print pp. 17-21:
  fifteen beings (the average
  knight of renown and knight of
  quality templates, Arthur,
  Bernlad, Galahad, Gareth, Garlon,
  Gawaine, Lamorak, Launcelot,
  Merlin, Morgan le Fay, Palomides,
  Pellinore, Tristram) plus the
  printed name rosters - 90 good/
  neutral knights (26 of quality)
  and 13 evil (3 of quality), 103
  total - riding as the round's
  first data file
  doc/data/ddg_arthurian_knights.txt
  (the data_files mechanic's first
  NEW-directory use). THE SHAPE: 4
  grids x 15 rows (combat, class,
  ability, roster), 52 consts + 89
  bools + 38 table cols, inline 179;
  header rules/dgc.h, prefix dgc;
  audit "R851 Arthurian mythos
  audit", rode rules/audits/
  r851_batch.h; 25 examples. ZERO
  registry defs touched - the floor
  holds at 995. THE ADJUDICATIONS
  (IA 1st-print collation over the
  Termux fold): Garlon HP 80, #AT 1,
  AC 1 effectively -3; Arthur
  FIGHTER 14th level paladin; Gawaine
  alignment Neutral; Merlin psionic
  300, modes B/C/E over All, #AT 1;
  Morgan 5'4" (64in); Palomides 5 1/2'
  (66in); the evil roster adds Damas
  and King Mark. THE MIRROR CATCH:
  the audit mirror failed at build
  with 2 bad - the class grid had
  Garlon as illusionist 3 and
  Palomides assassin 3; the ink reads
  Garlon 3rd level THIEF and
  Palomides 3rd level in EACH monk and
  bard; the examples were right and
  the grids wrong (the mirror caught
  a grid-vs-example divergence before
  publish). The good roster was one
  short: Breunor (both voices, no
  asterisk) between Brandiles and
  Brian o' the Forest. EYEBALL CELLS
  (flagged, pending physical copy):
  Gawaine HP 112 (IA reads 172 -
  pinned 112), Garlon height (garbled
  both voices, size 0), Pellinore
  6'4" (76in, single-voice), Arthur
  paladin line (IA only). THE RED
  LESSON (first-land abort, no
  commit): the engine writes data
  files WITHOUT makedirs - doc/data/
  did not exist, the engine died
  mid-write-list with everything else
  applied; the unwind (git restore
  seed/regtest/gap report to base +
  rm dgc.h/r851_batch.h) plus
  mkdir -p doc/data re-landed clean;
  future data-file rounds need the
  directory or a one-line engine
  makedirs tweak in a tool round.
  DELIVERY: raw JSON canvas (no
  base64, the R850 rule). Spec
  tools/spec_r851.json, md5
  bc29e8d9021d81305d9044811d005a54
  (56,928 bytes). NEXT: the D&DG
  walk continues from the Babylonian
  mythos (print pp. 22-25) - WAIT
  FOR GO.

- R852 LANDED 2026-10-26: commit
  5f6789e9e1484e699cedc08d304b516898b28cb8
  (pushed 550339f..5f6789e,
  census 774 -> 775), THE
  BABYLONIAN MYTHOS - the D&DG walk
  round four, print pp. 22-25: ten
  beings (Anu, Anshar, Dahak, Druaga,
  Gilgamesh, Girru, Ishtar, Marduk,
  Nergal, Ramman), the pantheon-wide
  cleric doctrine (the kilt, the
  tithe, the payment advancement).
  THE SHAPE: 4 grids x 10 rows
  (combat, class, ability, roster;
  38 cols), 73 consts + 114 bools,
  inline 225; header rules/dgd.h,
  prefix dgd; audit "R852 Babylonian
  mythos audit", rode rules/audits/
  r852_batch.h; 34 examples. The
  roster grid carries the alignment
  codes (0 LG, 1 NG, 3 LN, 4 N, 6
  LE, 7 NE, 8 CE), the rank codes
  (0 lesser, 1 greater, 2 hero,
  3 monster - Gilgamesh the hero,
  Dahak the monster format), the
  plane codes (Nirvana through
  Concordant Opposition, 8 planes)
  and the psionic class cells (Anu
  and Anshar VI, the R849 class
  table). THE ADJUDICATIONS (the IA
  1st-print collation over the
  Termux fold): Gilgamesh 2 attacks
  (the IA xml word vs the Termux 3
  fold-garble), the Girru +3 axe
  (vs the +43 garble), the Anu 2-20
  (+7) line (IA; the fold ate it),
  Druaga CH 4 (the single-glyph
  15px TSV width vs the 24px
  two-digit calibration), Nergal
  12/12 and Ramman 12/48 moves,
  Dahak 72 feet long (the IA foot
  mark vs the Termux inch mark).
  EYEBALL CELLS (flagged): the
  Dahak move 9/18 (the 2nd-print
  extract vs the IA 1st-print 9/15,
  the Gawaine 112 precedent), the
  Anu size (the 6 clean, the inch
  mark garbled in both voices).
  ZERO registry defs touched - the
  floor holds at 995. This round
  also seated the R851 record into
  the seed (the prev_record). Spec
  tools/spec_r852.json, md5
  00af93e06db06c75d19ee15561ca920a
  (66,343 bytes). NEXT: the D&DG
  walk continues from the Celtic
  mythos (print pp. 26-31) - WAIT
  FOR GO.

- R853 LANDED 2026-10-26: commit
  ba14cd03b3e641b91fbca427ae5c8000fa74d736
  (pushed 5f6789e..ba14cd0,
  census 775 -> 776), THE
  CELTIC MYTHOS - the D&DG walk
  round five, print pp. 26-31:
  sixteen beings (Dagda, Arawn,
  Brigit, Cu Chulainn, Diancecht,
  Dunatis, Goibhnie, Lugh,
  Manannan Mac Lir, Math,
  Morrigan, Nuada, Oghma,
  Silvanus, the Master of the
  Hunt, the Pack of the Wild
  Hunt), the druid doctrine (the
  four feast-day sacrifices:
  Samain Nov 1, Imbalc Feb 1,
  Beltane May 1, Lugnasad Aug 1),
  the Wild Hunt doctrine, the
  tathlum and the Torc of the
  Gods. THE SHAPE: 4 grids x 16
  rows (combat, class, ability,
  roster; 38 cols - the roster
  col 9 repurposed as the Wild
  Hunt flag, col 8 as the
  in-each flag; Move 0 = printed
  Variable, Cls 99 = printed
  See below), 135 consts + 151
  bools + 38 table cols, inline
  324; 43 examples; header
  rules/dge.h, prefix dge;
  audit "R853 Celtic mythos
  audit", rode rules/audits/
  r853_batch.h. THE ADJUDICATIONS
  (the IA 1st-print collation
  over the Termux fold, the
  word-geometry tie-breaks):
  Dagda psionic II (29px
  two-glyph), Arawn VI (49px),
  Goibhnie VI (51px), Oghma IV
  (57px); Cu Chulainn 6'4" (76in)
  and Math 5'4" (64in) - the
  foot-mark-misread-as-1 decode
  of the printed 614/514 cells;
  Cu Chulainn I:17 (the Termux
  1117 vs the IA 1:97; the 116px
  four-glyph word); Lugh S:23
  (+5,+11) (the IA Sr20(
  misread); Lugh's fighter slot
  stays 19th level ranger (both
  print voices; the 1eonline
  transcription normalizes to
  fighter - the print pinned);
  the Morrigan CH "21 or -1"
  (both OCR voices garble
  identically, corroborated by
  the 1eonline transcription);
  Silvanus AC -4 and move
  18"/48" through forests (IA
  recovery); Nuada/Oghma sizes 6'
  (IA clean vs the Termux &
  garbles); Dagda M-U/I 15th in
  each + 20th bard (IA recovery
  of the fold); Math psionic a
  200-point score (the R851
  Merlin 300 precedent), modes
  A,B,C / F,G,H,I. EYEBALL CELLS
  (flagged): the Manannan
  trident drain fraction (pinned
  one-fourth, garbled both
  voices), the tathlum damage
  fraction (garbled both voices
  - a bool only, no const).
  ZERO registry defs touched -
  the floor holds at 995. This
  round seated the R852 record
  into the seed (the
  prev_record). Spec
  tools/spec_r853.json, md5
  846a14e4c126f441f21e8f11990c98c2
  (96,638 bytes). rverify
  double-run GREEN, 894 mutants
  0 missed; hyphen scan clean.
  NEXT: the D&DG walk continues
  from the Central American
  mythos (print pp. 32-36) -
  WAIT FOR GO.

- R854 LANDED 2026-10-26: commit
  e10a2090a52e95456c827c2c52b2e58d1e9c0949
  (pushed ba14cd0..e10a209,
  census 776 -> 777), THE
  CENTRAL AMERICAN MYTHOS - the
  D&DG walk round six, print
  pp. 32-36: fourteen beings
  (Quetzalcoatl, Camaxtli,
  Chalchiuhtlicue, Camazotz,
  Huhueteotl, Huitzilopochtli,
  the twin heroes Hunapu and
  Xbalanque, Itzamna,
  Tezcatlipoca, Mictlantecuhtli,
  Tlaloc, Tlazolteotl,
  Xochipilli), the elite-cleric
  doctrine with the compass
  directions (the +1 to hit / -1
  save in the chosen direction,
  the d4 when undictated, the
  east-red/south-yellow/
  west-black/north-white robes),
  all on the one parallel Prime
  Material Plane. THE SHAPE: 4
  grids x 14 rows (combat, class,
  ability, roster; 38 cols - the
  roster col 9 repurposed as the
  twin-pair flag, col 8 as the
  in-each flag; Move -1 = printed
  Infinite, RosDmgFixed = the
  printed-damage flags), 70
  consts + 127 bools + 38 table
  cols, inline 235; 30 examples;
  header rules/dgf.h, prefix dgf;
  audit "R854 Central American
  mythos audit", rode
  rules/audits/r854_batch.h. THE
  ADJUDICATIONS (the IA 1st-print
  djvu.xml geometry at 600dpi
  over the Termux extract):
  Tezcatlipoca psionic class II
  (the 28px two-glyph word vs the
  Termux single I; Itzamna VI the
  51px; eleven class-I the 9-11px
  single bars), the size decodes
  (Chalchiuhtlicue 6'4" and the
  twins 5'4" - both 149px six-glyph
  cells, the R853
  foot-mark-misread lesson;
  Xochipilli the printed 16'),
  the Tlazolteotl charisma 24/-5
  (Termux clean over the IA
  garble; Camazotz CH -2 and
  Mictlantecuhtli CH -4 as
  printed). EYEBALL CELLS
  (flagged): the Tlazolteotl hit
  points (the 2nd-print 211
  pinned vs the IA 1st-print 217 -
  a genuine print divergence, the
  Gawaine 112 precedent). ZERO
  registry defs touched - the
  floor holds at 995. THE RED
  LESSON (first-land abort, no
  commit): the intro-doctrine
  example carried Python True
  literals - py_expr_to_cpp
  translates m['x'] and ' or '
  but passes True through
  verbatim, so the audit emitted
  'dgfEastRed() != True' and
  died at the Termux compile
  ("use of undeclared identifier
  'True'"); the engine's own
  bool conds already audit every
  bool, so the fix dropped the
  four color clauses from the
  example. STANDING RULE: never
  put Python True/False literals
  in example exprs - scan the
  spec for True/False tokens
  before publish; the rverify
  Python sim cannot see
  undeclared C++ identifiers
  (the R392 sim-blindness class).
  The unwind+re-land rode the
  R817 rule (git restore to
  ba14cd0 + rm of the new
  header/audit; fresh md5
  cf07a5ef6e8988f1728ad9259cb200a3,
  75,550 bytes). rverify double-run
  GREEN, 729 mutants 0 missed;
  hyphen scan clean. NEXT: the
  D&DG walk continues from the
  Chinese mythos (print
  pp. 37-42) - WAIT FOR GO.

- R855 LANDED 2026-10-26: commit
  978337ddec018650d5d6730c4a986ca44a0c75eb
  (pushed e10a209..978337d,
  census 777 -> 778), THE
  CHINESE MYTHOS - the D&DG
  walk round seven, print
  pp. 37-42: eighteen beings
  (Shang-Ti, Chao Kung Ming,
  Chih Sung-Tzu, Chih-Chiang
  Fyu-Ya, Chung Kuel, Fei Lien
  and Feng Po the Counts of the
  Wind, Huan-Ti, Kuan Yin, Lei
  Kung, Lu Yueh, Ma Yuan, No
  Cha, Shan Hai Ching, the
  Spirits of the Air, Tou Mu,
  Wen Chung, Yen-Wang-Yeh), the
  celestial bureaucracy
  doctrine, and the seven
  devices (Iron Wand, Jade
  Scepter, Wind Fire Wheels,
  Canon of Changes, Dancing
  Sword of Lightning, Fire
  Gems, Giant Black Pearl).
  THE SHAPE: 132 consts + 109
  bools + 4 grids (38 table
  cols), 279 inlines, 28
  examples; header rules/dgg.h,
  prefix dgg; audit "R855
  Chinese mythos audit", rode
  rules/audits/r855_batch.h.
  THE ADJUDICATIONS (IA 1st-print
  djvu.xml geometry at 600dpi
  over the Termux extract):
  the psionic class cells
  (Chao Kung Ming II 27px and
  Tou Mu II 29px vs the Termux
  /I and //; Chih-Chiang Fyu-Ya
  VI 49px vs the Termux 11),
  the size decodes (Shang-Ti
  5'4" and Chao 6'2" - the
  149px foot-mark cells, the
  R853 lesson), the Standard-MR
  cells to 0 (Chih Sung-Tzu,
  Fei/Feng, Lu Yueh, Spirits),
  Kuan Yin D:12 and M-U "See
  below" (Cls 99, prose level
  20), the Spirits NO.
  APPEARING 1-100 (Termux +
  prose over the IA 17-1700
  djvu garble). EYEBALL CELLS
  (flagged): the Wen Chung hit
  points (the 2nd-print 213
  pinned vs the IA 1st-print
  273 - a genuine print
  divergence, the Gawaine 112
  precedent), the Chih
  Sung-Tzu size (garbled
  identically in both voices,
  the 0 sentinel pinned), the
  Wen Chung 12/21 move (both
  voices agree on the unusual
  printed slash - noted). ZERO
  registry defs touched - the
  floor holds at 995. Spec
  tools/spec_r855.json, md5
  f79efb40036dd62b2f56ed50d4d
  f0f14 (85,816 bytes). rverify
  double-run GREEN, 925 mutants
  0 missed; hyphen scan clean;
  zero True/False tokens (the
  R854 rule held first-try).
  NEXT: the D&DG walk continues
  from the Cthulhu mythos
  (print pp. 43-48) - WAIT FOR
  GO.

- R856 LANDED 2026-10-26: commit
  4852c1baf90d017fbc888e5bba4c3f
  88a97f4700 (pushed 978337d..
  4852c1b, census 778 -> 779),
  THE CTHULHU MYTHOS - the
  D&DG walk round eight, print
  pp. 43-48: fifteen beings
  (Cthulhu, Azathoth, Cthugha,
  the Byakhee servants of
  Hastur, the Flame Creatures,
  the Deep Ones, Hastur the
  Unspeakable, the Great Race,
  Ithaqua the Wind Walker, the
  Mi-Go, Nyarlathotep the
  crawling chaos, the
  Primordial Ones, the
  Shoggoths, Shub-Niggurath,
  Yog-Sothoth), the Old Ones
  lore (the 5 percent
  name-speaking, the R lyeh +4
  saves, the 100-mile release
  radius, the nature-creature
  warning), and the two
  artifacts: the Elder Sign and
  the Necronomicon (the 40
  percent alignment/madness
  roll below 5th, -5 per level,
  18 Int, 5 percent per level
  from 6th, 30 percent
  summoning insanity) plus the
  seven lesser books. THE
  SHAPE: 168 consts + 124
  bools + 4 grids (38 table
  cols - the roster col 9
  repurposed as the
  Shub-Niggurath d6 summon-list
  flag, col 8 as the in-each
  flag), 330 inlines, 29
  examples; header rules/cth.h,
  prefix cth; audit "R856
  Cthulhu mythos audit", rode
  rules/audits/r856_batch.h.
  THE PREFIX CATCH (the round's
  new lesson): dgh was NOT free
  - rules/oamonk.h owns
  dghMonkMinStr and friends
  (the oakensai comment even
  warned "verify free"), and
  the OA book had burned dgb
  through dgz entirely (the OA
  headers two-letter-walk
  dga..dhj+), so the D&DG
  rounds cannot take dgh+
  blindly; R856 rode the
  mnemonic prefix cth, verified
  free repo-wide with a
  full-repo scan (grep -rlE
  over all .h/.cpp/.py) before
  authoring. STANDING RULE: the
  prefix freedom check is now a
  FULL-REPO scan, not just
  regtest.cpp plus rules/
  - the two-letter pool is
  crowded and startswith
  collisions cost nothing to
  check. THE ADJUDICATIONS (the
  IA 1st-print djvu.xml
  geometry at 600dpi over the
  Termux extract): the psionic
  classes (the 10px single bars
  of Cthulhu, Cthugha, Hastur,
  Shub and Yog; Byakhee the
  54px IV; Ithaqua IV; Flame
  Creature V; Nyarlathotep V;
  Azathoth VI), the monster
  psionic point scores (Great
  Race 280, Mi-Go 90,
  Primordial One 206 - the R853
  Math 200 precedent), the
  Mi-Go size (the IA geometry 8
  feet against the Termux 8
  inches), the layout
  disentangle (segs 43-48
  re-columned: Ithaqua prose,
  Mi-Go, Nyarlathotep left and
  Nyarlathotep prose,
  Primordial One, Shoggoth
  right on print p. 46; the
  Byakhee and Flame Creature
  blocks of p. 44 split across
  the columns with the Termux
  psm-4 fold interleaving
  them). EYEBALL CELLS
  (flagged): the Cthulhu
  charisma (both voices read 7,
  the minus lost in the
  printed scrawl - pinned 7),
  the Cthugha ability line
  (IA-garbled, the Termux fold
  pinned: I 12, W 18, CH 1),
  the Azathoth size (the
  printed inconceivable,
  sentinel), the Nyarlathotep
  size (the printed Variable,
  sentinel), the Primordial One
  move 18/12 (both voices agree
  on the unusual slash) and the
  Mi-Go size feet-vs-inches.
  ZERO registry defs touched -
  the floor holds at 995. Spec
  tools/spec_r856.json, md5
  e18b66d0ba51639c60b9506f3b6
  97582 (87,377 bytes). rverify
  double-run GREEN, 862 mutants
  0 missed; hyphen scan clean;
  quote balance OK; zero
  True/False tokens (the R854
  rule held first-try, no
  first-land abort this
  round). NEXT: the D&DG walk
  continues from the Egyptian
  mythos (print pp. 49-56) -
  WAIT FOR GO.

- R857 LANDED 2026-10-26: commit
  08b8283602d9e1b0c6ae01340595e8e6
  bc566343 (pushed 4852c1b..
  08b8283, census 779 -> 780), THE
  EGYPTIAN MYTHOS - the D&DG walk
  round nine, print pp. 49-56:
  twenty-one beings (Ra, Anhur,
  Anubis, Apep, Apshai, Bast, Bes,
  the Flame Snake, Geb, Horus, Isis,
  Nephthys, Osiris, the Phoenix,
  Ptah, Seker, Set, the Minions of
  Set, Shu, Tefnut, Thoth), the
  temple and cleric-ladder
  doctrine, the true Ankh artifact
  and the 97-word hieroglyph grid
  (the round's first data file,
  doc/data/ddg_egyptian_hieroglyphs
  .txt, riding the R851 precedent).
  The headline adjudication: the
  GEOMETRY SWAP catch - the Termux
  fold had Ra/Anhur ability lines
  reversed, settled by geometry
  plus Anhur's +14 strength prose
  (Ra S:20 I:25 W:25 D:20 C:25
  CH:25; Anhur S:25(+7,+14)).
  Flagged eyeballs: Bast W:10
  (geometry over Termux W:70), Set
  MR 59 and Shu/Tefnut MR 69 pinned
  as printed, Horus size 6'2" and
  15"/15" move decode, Nephthys
  5'4" twin decode, Minions 6'4",
  Flame Snake xp base 745 garble,
  the hieroglyph AT word, Apep
  300' (IA feet over Termux
  inches), Ptah Infinite move ->
  -1 sentinel, Phoenix MR "See
  below" -> 0, Ra #AT 0/Nil ->
  DmgFixed 0. Spec a1cc786df9139f3
  24fac5a8f23a399ee, 400 inlines
  (152 consts, 210 bools, 38
  table cols), 31 examples, 21x38
  grids; engine applied 7/already
  7 double-run; rverify GREEN,
  1160 mutants 0 missed; hyphen
  scan clean; zero True/False
  tokens (the artifact name rides
  lowercased 'true Ankh' in
  comments after the raw grep
  caught 'True Ankh'); a builder
  grid slip (Bes/Osiris bard values
  in the Monk column, Thoth
  in-each 0) was caught first-try
  by the emitted-header audit
  mirror. NEXT: the D&DG walk
  continues from the Finnish
  mythos (print pp. 57-62) - WAIT
  FOR GO.

- R858 LANDED 2026-10-26: commit
  db4548071b69807c1e78a8ed0f63688beaa
  990c1 (pushed 08b8283..db45480,
  census 780 -> 781), THE FINNISH
  MYTHOS - the D&DG walk round ten,
  print pp. 57-62: twenty beings
  (Vainamoinen, Ahto, the Water
  Dwarf, Ilmarinen, Hiisi, Ilmatar,
  Kiputytto, Lemminkainen, Kullervo,
  Tiera, Louhi, Loviatar, Mielikki,
  the Son of Pohjola, Surma,
  Tuonetar, Tuoni, Ukko, Untamo, the
  Air Maiden), 6 heroes, 5 greater,
  4 lesser, 3 demigods, 2 servants;
  prefix klv ('fin' burned r312,
  full-repo scan clean). The
  headline adjudication: the
  KULLERVO/TIERA FOLD SWAP - the
  Termux full.txt interleaved the
  two blocks; geometry + tsv +
  prose settled Kullervo = CN, AC 1,
  S:19(+3,+7), Fighter 19, MU/I 8
  each, Thief 10, Bard 5, and Tiera =
  LG, AC 4, S:17(+1,+1), fighter-
  ranger 9, Bard 5. Flagged eyeballs:
  Lemminkainen MOVE 12 (both alt
  voices), Louhi HP 110 (81px token
  too narrow for 4 glyphs), Kiputytto
  #AT 1 (single 11px glyph), Mielikki
  psionic pipe -> class I, Tuonetar
  CH:-6, Hiisi W:10 and Kullervo W:6
  pinned, foot-mark size decodes
  (Lemminkainen 6'2", Kullervo 6'1",
  Tiera 5'4", Mielikki 5'1", Tuoni L
  10'), triple-slash moves Ahto
  18/24/24 and Tuoni 18/18/48,
  Tuonetar fear radius 30 FEET (djvu
  feet over tsv inches), Surma AC -2
  (dash token), strength brackets
  Water Dwarf 18(37), Lemminkainen
  18(09), Son of Pohjola 18(00),
  Loviatar 16(0,+1); Pohjola-enmity
  flags on Kullervo, Louhi, Son of
  Pohjola, Tuonetar. Spec
  565fae2736f6d1715893344385b5fbaa,
  312 inlines (126 consts, 148
  bools, 38 table cols), 34 examples,
  no data files; engine applied
  6/already 6 double-run; rverify
  GREEN, 1034 mutants 0 missed;
  hyphen scan clean; zero True/False
  tokens. Engine lesson: the emitted
  header contains ONLY names
  referenced in header_sections and
  every const/bool must be referenced
  EXACTLY ONCE - duplicate refs
  re-emit and inflate the inline
  count (engine dies on the mismatch);
  fixed via an explicit shared
  exclusion set + walk_names filter
  in the builder. NEXT: the D&DG walk
  continues from the Greek mythos
  (print pp. 63-74, the next open
  box) - WAIT FOR GO.

  - R859 LANDED 2026-10-26: commit 57b84aea31961dc9fd5bfea77dc2f956d14d3be1
  (pushed db45480..57b84ae, census 781 -> 782), THE GREEK MYTHOS - the D&DG
  walk round eleven, print pp. 63-74: forty beings (Zeus, the White Eagle,
  Achilles, Aphrodite, Antaeus, Apollo, Ares, Artemis, Athena, Atlas,
  Bellerophon, Cerberus, Circe, Coeus, Crius, the greater and lesser cyclopes,
  Demeter, Dionysus, Enceladus, Epimetheus, the Furies, Hades, Hecate, the
  Hecatoncheire, Hephaestus, Hera, Heracles, Hermes, Jason, Kronos, Nike,
  Oceanus, Odysseus, Pan, Perseus, Poseidon, Prometheus, Theseus, Tyche), 10
  greater, 8 lesser, 1 demigod, 6 heroes, 6 greater titans, 9 monsters; prefix
  grk (full-repo scan clean). The headline adjudication: the FRACTION
  FINGERPRINT - the half-height glyphs of the printed X 1/2 foot size cells
  decode as fractions, not X'Y" inches: Zeus 78, Achilles 66, Aphrodite 66,
  Artemis 66, Bellerophon 66, Hecate 66, Hera 66, Hermes 78, Hades 78 (the
  draft 6'1" was the fraction); Odysseus 5'4" the one true inch cell; Coeus
  CH:-4 pixel-verified; Dionysus and Hades psionic class III (three pipe bars,
  the R850 Coyote precedent, chocr glyph widths I 9-11px II 30 III 47 IV 54 V
  36 VI 50). Merged-column catches: Ares/Athena class swap, Atlas CE /
  Cerberus NE swap, Achilles Fighter 15. Flagged odd prints pinned as printed:
  Ares move 26/24, Hades move 29, Hades CH 24(-9), Bellerophon move 12. The
  R851-R858 16-cell repair table (all X 1/2 misreads: Morgan, Anu, CuChulainn,
  Math, Chalchiuhtlicue, the twins, ShangTi, ChaoKungMing, ChihSungTzu 0->78,
  Horus, Isis, Nephthys, Seker, MinionsOfSet, Thoth, Kullervo, Mielikki)
  verified and reported, NOT patched - Curtiss's call. Spec
  2f13b02dcce08dc6a61f3cf9fe5010bf, 99258 bytes; 332 inlines (116 consts, 178
  bools, 38 table cols), 40 examples, no data files; engine applied 6/already
  6 double-run; rverify GREEN, 1814 mutants 0 missed; hyphen scan clean; zero
  True/False tokens (bool examples dropped per the R854 rule - no spec has
  ever referenced a bool in an example). Engine lesson: the R859 census consts
  needed bare first-words in the section mapper (In, Half) - the camel regex
  stops at the second cap. NEXT: WAIT FOR GO.

  - R860 LANDED 2026-10-26: commit a4690e27d272601c4287c3486ab08958feed9a99
  (pushed 57b84ae..a4690e2, census 782 -> 783), THE INDIAN MYTHOS - the D&DG
  walk round twelve, print pp. 75-80: eighteen beings (Indra, the Elephant of
  Indra, Agni, Kali, Karttikeya, the Peacock of Karttikeya, Lakshmi, the
  Marut, Ratri, Rudra, Surya, Tvashtri, Ushas, Varuna, Vishnu, Garuda, Yama,
  the Water Buffalo of Yama), 6 greater, 3 lesser, 4 demigods, 5 monsters, no
  heroes, no titans; prefix idn ('ind' burned: six bare hits in
  MonsterRegistry.cpp; idn scanned clean repo-wide, the klv/fin precedent).
  The headline adjudication: the PSIONIC THREE-PIPE CATCH - the chocr char
  geometry at 600dpi (single pipe w10, V w36, VI w49, III w47) settles Indra
  TI! w47 = class III and Kali I(9)I(10)I(10) = III (the Termux voice read 11l
  and 1Nl, both three glyphs); I Agni, Tvashtri, Vishnu; V Ratri, Rudra, Yama;
  VI Karttikeya, Lakshmi, Surya, Ushas, Varuna. The FRACTION FINGERPRINT rides
  again: Ushas (514) = 5 1/2 foot = 66 and Varuna (614) = 6 1/2 foot = 78, the
  small-1 w24 + low-4 w40 clusters. The SURYA AC CATCH: chocr reads -3 where
  the Termux voice printed only the bare dash. Flagged odd prints pinned as
  printed: Indra AC em-dash -12, Kali move 27 without a slash, Kali W:5 and MR
  39%, the Marut move 9 apostrophe, the Buffalo L 12 inches at the shoulders
  (the one true-inch cell), Yama MR 25 percent with the 100 percent robes.
  Conventions: Agni/Yama MU/I See below -> 99/99 (the egp Isis precedent);
  paladin pairs Surya 16, Varuna 14, Vishnu 17; the Kali double in-each (C/D
  10 and MU/I 15). Spec 897b1742f51ca43d8c580317b9b9aa61, 66814 bytes; 241
  inlines (105 consts, 98 bools, 38 table cols), 21 examples, no data files;
  engine applied 6/already 6 double-run; rverify GREEN, 887 mutants 0 missed;
  hyphen scan clean; zero True/False tokens. Engine lesson: the R859
  section-mapper bare first-words (In, Half) carried over; the IA voices live
  in the repo extract plus the archive.org derivative stream (chocr + djvu
  fetched per round). NEXT: WAIT FOR GO.

  - R861 LANDED 2026-10-26: commit 98bd7f9240b5aff49100beed37b3e69f945c356d
  (pushed a4690e2..98bd7f9, census 783 -> 784), THE JAPANESE MYTHOS - the
  D&DG walk round thirteen, print pp. 81-85: thirteen beings (Ama-Tsu-Mara,
  Amaterasu Omikami, Daikoku, Ebisu, Hachiman, Kishijoten, Oh-Kuni-Nushi,
  Raiden, Raiko, Susanowo, Tsukiyomi, Yamamoto Date, Yoshi-iye), 5 greater,
  3 lesser, 2 demigods, 3 heroes, no monsters; prefix jpn ('jap' burned:
  lowercase 'jape' hits in r356_splice.py and uamuspells1.h; jpn scanned
  clean repo-wide). The headline adjudication: the DIGIT-SPLIT calibration
  - a narrow printed 1 splits into 1 and 7 fragments in the chocr char
  geometry at 600dpi: Kishijoten 31717 = 311 hp and 17 = 1 attack, Ebisu
  3173 = 313 hp, Hachiman 175th = the 15th assassin. The FRACTION
  FINGERPRINT: five X 1/2 cells (Ama-Tsu-Mara 78, Daikoku 66, Ebisu 66,
  Hachiman 78, Susanowo 78). The EBISU PLANE CATCH: the chocr reads the
  Seven Heavens where the merged voice said Prime Material. The AMATERASU
  WRAP-LINE CATCH: the 'in each' wrap restores illusionist 20, the round's
  only double in-each (MU/I 20 and M/B 15). Conventions: the Amaterasu
  Infinite move -1 sentinel (the Ptah precedent); the Susanowo 12/36/48
  triple slash encodes two with the 48 in the col comment (the klv Ahto
  precedent); the bare SIZE: M hero rows pinned 0 (Yamamoto Date,
  Yoshi-iye); the MONK/BARD in-each cells new this round (Amaterasu 15,
  Oh-Kuni 10, Yoshi-iye 5). Flagged odd prints pinned: Hachiman 28/21,
  Oh-Kuni-Nushi 15/12, Tsukiyomi 12/21 (descending pairs), Raiko 29,
  Yoshi-iye 19 (no slash). Spec a6c9678bcbe90271431041a204ecb130, 51297
  bytes; 179 inlines (57 consts, 84 bools, 38 table cols), 15 examples, no
  data files; engine applied 6/already 6 double-run; rverify GREEN, 635
  mutants 0 missed; hyphen scan clean; zero True/False tokens. NEXT: WAIT
  FOR GO.

  - R862 LANDED 2026-10-26: commit
  f21b8dcae902666becfe41e36ad958fee2ad6a7d (pushed
  98bd7f9..f21b8dc, census 784 -> 785), THE MELNIBONEAN
  MYTHOS - the D&DG walk round fourteen, print pp. 86-95,
  the monster-heaviest round of the walk: thirty-three
  beings - the four heroes (Elric, Moonglum, Theleb
  K'aarna, Yyrkoon), the three greater gods (Arioch,
  Donblas, Xiombarg), the six lesser gods (Darnizhaan,
  Grome, Kakatal, Misha, Pyaray, Straasha), the six
  demigod masters of the demi-planes (Fileet,
  Haaashastaak, Meerclar, Nnuurrr, Nuru-ah, Roofdrak)
  and fourteen monsters (the Assassinator of the Gods
  through the Vulture Lion); prefix mlb (full-repo scan
  clean). The headline adjudication: the ELRIC DUAL
  PRINT - the walk's only dual armor class (6 and minus
  6, the latter the Stormbringer wield-state) and a dual
  move (6 and 15); his printed Standard-or-85% magic
  resistance pins 0 with the 85 riding the Stormbringer
  consts. The SEE BELOW 99 PAIRS (the egp Isis
  precedent): Grome and Nuru-ah on both lines, Kakatal,
  Misha and Straasha on the MU/I line. The VARIABLE
  PINS: Arioch prints both SIZE: Variable and CHARISMA:
  Variable - both 0 with col comments; Nnuurrr and
  Pyaray print CH: -6. Flagged odd prints pinned as
  printed: the Haaashastaak and Nnuurrr W: 3 cells.
  The BARE AND STRAY SIZE PRINTS: Fileet the bare L
  pinned 0 (the R861 bare-M precedent), the Vampire
  Trees the L-plus-25-feet-tall print read as 300 with
  the stray plus noted. The monster XP romans verified:
  VIII/6,200 Assassinator flat, X/21,450 Quaolnargn
  flat, VIII/6,391 Mordagz flat, the per-hp rows Clakar
  VI/650+10, Dharzi II/90+5, Myyrrhn III/125+4, Nihrain
  and Oonai VII/1,950+14, Mist Giant VIII/4,950+16,
  Vampire Trees VIII/3,850+16, Vulture Lion IX/5,600+20;
  the Kelmain Variable XP rides a bool. The fraction
  fingerprint: Moonglum 66, Theleb K'aarna 66, Yyrkoon
  78. The ELENOIN-GRAHUK ENMITY PAIR (the grk
  printed-rivalry precedent, the round's only rivalry
  print). The psionic pipes: the w10 single pipe I of
  Arioch, Darnizhaan, Meerclar and Nuru-ah, Pyaray II,
  the w49 VI of Grome, Haaashastaak, Misha, Roofdrak
  and Straasha. ZERO registry defs touched - the floor
  holds at 995. Spec tools/spec_r862.json, md5
  5bb54a60bef7347b448f4f7a8ea153ec (93,354 bytes);
  355 inlines (167 consts, 150 bools, 38 table cols, 4
  grids x 33 rows), 16 examples, no data files; ddg gap
  14/24 closed, 10 open. The rverify mutant count rode
  only in the Termux landing output (not in the pasted
  excerpt) - amend at the next touch if Curtiss wants it
  recorded. NEXT: the D&DG walk continues from the
  Nehwon mythos (print pp. 96-104) - WAIT FOR GO.

  - R863 LANDED 2026-10-26: commit
  f34a53247168a8fce37956671653d54e50128eb0 (pushed
  f21b8dc..f34a532, census 785 -> 786), THE NEHWON
  MYTHOS - the D&DG walk round fifteen, print pp. 96-104:
  twenty-nine beings - the four heroes (Fafhrd, the
  Gray Mouser, Movarl, Pulgh), the two wizards
  (Ningauble of the Seven Eyes, Sheelba of the Eyeless
  Face), the two greater gods (Death, Kos), the six
  lesser gods (the Gods of Trouble, Hate, the Nehwon
  Earth God, the Rat God, the Red God, Tyaa), the five
  demigods (Aarth, the Gods of Lankhmar, Issek of the
  Jug, the Spider God, Votishal) and ten monsters
  (Astral Wolf, Behemoth, Bird of Tyaa, Cold Woman,
  Devourer, Nehwon Ghoul, Leviathan, Snow Serpent,
  Salt Spider, Water Cobra) - plus the Lankhmar
  doctrine of the intro (the Thieves Guild, the
  Slayers' Brotherhood, the Snow Witches, the Fire
  Sorcerers, the gems, the Cults of the Beast, the
  Godsland) and the six outdoor encounter tables of
  print p. 104 riding as the fifth grid (74 rows) plus
  the round's data file doc/data/
  ddg_nehwon_encounters.txt; prefix nhw (GitHub code
  search clean: only camelCase ConTinhWeapon nhW
  substrings, no lowercase nhw token). THE HEADLINE
  ADJUDICATIONS: the QUARTER-FOOT DECODE - the Mouser
  prints SIZE M (5 1/4 foot), the walk's first
  quarter-cell, pinned 63 inches (the 1eonline voice
  reads 5.25'); Aarth the half-foot 5 1/2 print pinned
  66. The DIVERGENT CELLS pinned by the 2nd-print
  extract with the L&L parity noted: Death AC -5 (L&L
  -4), the Gods of Trouble AC -2 (L&L -3, tsv-verified
  minus 2 at w22), Votishal HP 344 (L&L 244, the token
  confirmed on-page), Tyaa AC the bare-dash print
  pinned 0 (L&L -3, the w2 dash glyph) and Votishal AC
  the dash-minus pinned -2 (the Surma dash-token
  precedent). The odd prints pinned as printed: the
  Issek 12/12 dual move, Hate HP 0, the Hate See below
  MU/I pair 99/99 (the egp Isis precedent), the Hate
  dash W/C/CH cells 0, Death Infinite move -1
  sentinel, the bird of Tyaa 1/18 move split,
  Ningauble Nil attacks, Sheelba the bare M (the R861
  precedent), the Gods of Trouble Special MR 0 with
  the 30-foot no-magic radius const, the Devourer
  Variable size 0. The monster XP romans verified
  against both voices: III/90+3 astral wolf,
  VIII/4,000+20 behemoth, II/30+1 bird, X/28,500 cold
  woman flat, II/50+3 ghoul, X/15,800+35 leviathan,
  VII/2,050+14 snow serpent, III/105+3 salt spider,
  III/150+4 water cobra. The encounter-table catches:
  the marsh Men-brigand 21-42 / Men-merchant 43-50
  rows restored from the fold-garbled Termux voice
  via the L&L transcription, and the mountains
  overlap print (astral wolf 01-05, bird of Tyaa
  03-06) pinned as printed. The psionic pipes: class I
  of Death, the Gods of Trouble and the Rat God,
  class V of the Gods of Lankhmar and Votishal, class
  VI of the Nehwon Earth God and the Red God. The
  advisor rivalry pair of Ningauble and Sheelba (the
  mlb Elenoin-Grahuk precedent). ZERO registry defs
  touched - the floor holds at 995. Spec
  tools/spec_r863.json, md5
  8e9b030eeeeb422dfa238a8400159cf1 (82,563 bytes);
  268 inlines (147 consts, 79 bools, 42 table cols, 5
  grids x 29 rows + the 74-row encounter grid), 17
  examples; rverify double-run GREEN, 1624 mutants
  0 missed; hyphen scan clean; zero True/False
  tokens; ddg gap 15/24 closed, 9 open. NEXT: the
  D&DG walk continues from the Nonhumans' Deities
  (print pp. 105-112) - WAIT FOR GO.

  - R864 LANDED 2026-10-26: commit
  f555f6634463913be47052f47e10bcf72606b1fc (pushed
  f34a532..f555f66, census 786 -> 787), THE
  NONHUMANS' DEITIES - the D&DG walk round
  sixteen, print pp. 105-112: twenty beings -
  the six greater gods (Moradin, Corellon
  Larethian, Maglubiyet, Garl Glittergold,
  Yondalla, Gruumsh), the twelve lesser gods
  (Hruggek, Skerrit, Deep Sashelas, Lolth,
  Rillifane Rallathil, Grolantor, Skoraeus
  Stonebones, Kurtulmak, Blibdoolpoolp,
  Semuanya, Eadro, Sekolah) and the two
  demigods (Vaprak, Laogzed) - plus the
  shaman/witch-doctor doctrine of the intro
  (the 1d4 hp ladder, the fight-as-one-HD-
  better-per-two-levels rule, the paired
  witch-doctor 2-5) and the NOTE list (13
  MM/FF beings treated as lesser gods) with
  the round's data file doc/data/
  ddg_nonhuman_crossrefs.txt; prefix nhg
  (nhd BURNED - uapantheon.h/r405 owns it).
  THE HEADLINE ADJUDICATIONS: the
  MORADIN-CORELLON FOLD SWAP - the raw
  extract interleaves the two folded blocks,
  the tsv x-coords settle it (Moradin left
  col S:25(+7,+14) psionic VI, the 4-40
  (+14) hammer; Corellon right col S:21
  (+4,+9) psionic I, the 3-30 (+9) sword);
  the KURTULMAK-BLIBDOOLPOOLP TAIL SWAP the
  same way (Kurtulmak the 12th assassin /
  psionic VI / M 5 1/2 foot 66, Blibdoolpoolp
  the 15th assassin / psionic III / the
  20th-level MU); HRUGGEK DEX NOT PRINTED
  (the tsv shows the bare 36px inter-cell
  gap between W and C - pinned 0); the
  FRACTION SIZES Yondalla 4 1/2 foot 54 (the
  tesseract 42 misread) and Kurtulmak 66.
  LOLTH: the drow-form paren pinned -2 (the
  tesseract +2 conf 53, L&L -2, the
  game-sense tiebreak, eyeball flag), the
  MOVE 1"/9" web (the MM spider convention;
  the tesseract 17 misread), drow move 15
  const, MR 70 (L&L 75), the See below
  clr/drd and mu/ill lines 99 pairs with the
  16th-cleric/14th-MU drow consts, CH 3(23),
  L (M) -> 0. Other divergent cells pinned
  with the L&L parity noted: Vaprak W 12
  (L&L 18, conf 90), Sashelas D 21 (L&L 18),
  Laogzed the harmful-spells cleric (L&L
  destructive), the Nine Hells planes pinned
  for Maglubiyet/Kurtulmak/Gruumsh/Sekolah
  (the L&L Gehenna/Acheron/Stygia are
  transcriber D64 glosses). Skerrit: the
  Variable cells 0-sentinel with the AC 2
  floor pin and the centaur-form consts (AC
  2 / move 21 / the +3 spear 2-20 / forest
  -4). Eadro: the dual AC 0/-6, AT 1/8, the
  psionic II (the tsv I/ w15 width-match).
  The 12 As-16+-HD fighter cells pinned 16
  (the new round convention). Spec
  tools/spec_r864.json, md5
  7725bdcc81fd95739b0b19087d610ef9 (92,675
  bytes); 334 inlines (200 consts, 97
  bools, 37 table cols, 4 grids x 20 rows),
  19 examples; rverify double-run GREEN,
  1037 mutants 0 missed; hyphen scan clean;
  zero True/False tokens; ddg gap 16/24
  closed, 8 open. NEXT: the D&DG walk
  continues from the Norse mythos - WAIT
  FOR GO.

  - R865 LANDED 2026-10-26: commit
  efdb231b2c4c19e01fd7752495b033c167b8cede (pushed
  f555f66..efdb231, census 787 -> 788), THE NORSE
  MYTHOS - the D&DG walk round seventeen, print
  pp. 113-124, the being-heaviest round of the walk:
  thirty-five beings in print order (Odin, Hugin and
  Munin, Sleipnir, Freke and Gere, Aegir, Balder,
  Bragi, Fenris Wolf, Fjalar, Forseti, Fossergrim,
  Frey, Blodug-Hofi, Gullin-Bursti, Skirnir, Freya,
  Frigga, Garm, Heimdall, Hel, Jormungandr, Idun,
  Loki, Magni, Modi, the Norns, Sif, Surtur, Thor,
  Thrym, Tyr, Uller, Thor's goats, Vidar, the
  Valkyries) - 11 greater, 10 lesser, 4 no-rank
  class-grid rows (Fjalar, Skirnir, the Norns, the
  Valkyries), 11 MM-format blocks; prefix nrs
  (full-repo scan clean); the round's data file
  doc/data/ddg_norse_crossrefs.txt. THE HEADLINE
  ADJUDICATIONS: THOR AC BARE 4 (the tsv shows no
  minus glyph, L&L reads -4; pinned as printed 4,
  eyeball flag); Hel dmg (+38 print garble
  adjudicated to +8 by strength arithmetic plus
  L&L); the half-foot sizes Odin/Hel/Tyr 78 and
  Valkyries 66 (the 1/2 glyph garbles); Hugin move
  1/48 as printed plus the merged V1815 xp = VI/815
  (MM level-VI base corroboration); Frey psionic II
  (the width-15 two-pipe signature plus L&L); Thrym
  HP 300 from L&L (the print cell occluded by the
  plate illustration); Aegir AC -5 (L&L -3) and
  Freya AC -3 (L&L -4) pinned by print; Surtur
  W:14 D:12 (the W:i4 garble); Modi 2-or-4 /
  25-or-50 berserk cells (the walk's first
  non-dice damage); Thor 2(3) glove; Jormungandr
  the 25,000-mile size -> 0 sentinel plus const,
  the slashless X 55,000 print; Balder MU/I Nil,
  psionic VI. The L&L parity voice: per-being
  1eonline pages (odin.htm carries the
  companions, frey.htm carries Blodug/Gullin/
  Skirnir, thor.htm carries the goats); all stat
  lines cross-verified. Planes: Gladsheim 18,
  Bragi Elysium, Hel Hades, Loki Pandemonium (alt
  Gladsheim), the Norns Concordant Opposition,
  13 none-printed. Psionic pipes I x5, II x3,
  III x1, IV x2, V x3, VI x7, Nil x14. ZERO
  registry defs touched - the floor holds at
  995. Spec tools/spec_r865.json, md5
  fef1deae45e43d14eeab11497495c0e3 (122,207
  bytes); 471 inlines (259 consts, 175 bools, 37
  table cols, 4 grids x 35 rows), 20 examples;
  rverify double-run GREEN, 1729 mutants 0
  missed; hyphen scan clean; zero True/False
  tokens; ddg gap 17/24 closed, 7 open
  (Sumerian, App 1-4, the index, the alignment
  figures). ENGINE LESSON (R854/R859 rule
  refined): R865 is the FIRST spec to reference
  bools in example exprs - the audit mirror
  aborts on a bare bool ref ("an operator
  expected in a audit condition"); every bool
  ref in an example must carry an operator
  (m['x']() != 1 form - `not` does not
  translate); the R859 "no bool in examples"
  note is superseded, bools ARE exampleable
  with the operator form. NEXT: the D&DG walk
  continues from the Sumerian mythos (print
  pp. 125-127) - WAIT FOR GO.

  - R866 LANDED 2026-10-26: commit
  2e8ee02cc6e28ac2a3fda0c593dcfb172e2af252 (pushed
  efdb231..2e8ee02, census 788 -> 789), THE
  SUMERIAN MYTHOS - the D&DG walk round
  eighteen, print pp. 125-127: seven beings -
  the five greater gods (Enlil, Enki, Inanna,
  Ki, Utu) and the two lesser (Nanna-Sin,
  Nin-hursag) - plus the city-temple doctrine
  of the intro (the patron deity per city, the
  priest-king, the ziggurat temples, the 7th/
  15th/25th holy days, the new-moon sacrifice,
  the three-degree punishment ladder, the
  shaven clerics) and the pantheon-wide cloud
  chariots doctrine of print p. 127 (MV 24,
  teleport-to-clouds, indestructible); prefix
  smr (full-repo scan clean); no data files.
  THE CENSUS ODDITY: EVERY ONE OF THE SEVEN
  BEINGS PRINTS AC -2, the only uniform-AC
  pantheon of the walk. THE HEADLINE
  ADJUDICATIONS: the Enlil 127/36" move garble
  -> 12/36 (L&L) and the (64") size = the
  6 1/2 foot 78 fraction cell (L&L reads 6.5,
  the R859 fingerprint); the (&) and (5)/(6)
  size garbles read 72/60 through the L&L
  voice; the Utu 32 attacks garble -> 3/2
  (L&L); the Ki 15"/36"/ /36" triple slash
  pinned as printed in BOTH voices (the R861
  Susanowo convention, the duplicate 36 in the
  col comment); the Inanna single-pipe
  psionic I (L&L reads II) and the
  warriors-and-lovers worshipper line (L&L
  reads Lawful evil) pinned by print; the
  Enki 10th-level bard (L&L reads 13th in
  each) and the Enlil D:23 CH:24 cells (the
  L&L voice normalizes to the 25s) pinned by
  print with the divergences noted; Utu the
  Infinite move -1 sentinel; Nin-hursag the
  2-20 dice damage (the DmgFixed 0 row); the
  psm-4 fold interleaved the Inanna and Ki
  blocks of print 126 across the columns, the
  tsv x-y geometry sorted them (Inanna's
  prose starts bottom-left, continues
  top-right; Ki's block bottom-right). ZERO
  registry defs touched - the floor holds at
  995. Spec tools/spec_r866.json, md5
  36c031af18651f33961cd62cc1729acf (57,917
  bytes); 196 inlines (58 consts, 101
  bools, 37 table cols, 4 grids x 7 rows), 23
  examples; rverify double-run GREEN, 418
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens; the R865 bool-operator
  rule held first-try (all bool example refs
  carry != 1); ddg gap 18/24 closed, 6 open
  (App 1-4, the index, the alignment
  figures). NEXT: the D&DG walk past the
  mythoi - the appendices and the index
  (App 1 the planes pp. 128-133, App 2
  temple trappings p. 134, App 3 clerical
  chart pp. 134-142, App 4 + index p. 143,
  the p.131 alignment-figures pixel work) -
  WAIT FOR GO.

  - R867 LANDED 2026-10-26: commit
  35f7686ab8a50813697be0f958e75e086ad4779f (pushed
  2e8ee02..35f7686, census 789 -> 790), APPENDIX 1
  THE KNOWN PLANES OF EXISTENCE - the D&DG walk
  round nineteen, print pp. 128-133: the
  planar-cosmology prose (the infinite
  multiverse, the Inner Planes around the Prime
  Material, the Ethereal and Astral conduits,
  the Great Wheel, the seventeen outer planes,
  the elemental/para-elemental/positive/
  negative doctrine) plus EIGHT grids: the
  ethereal encounter table (31 rows), the
  astral encounter table (24 rows), the
  seventeen-outer-planes list (17 rows), the
  cyclone, wind and para-elemental tables (4
  rows each), the inner-plane random bands
  (13 rows) and the outer-plane random bands
  (18 rows) - plus the round's data file
  doc/data/ddg_planes_encounters.txt (the
  39-label creature roster + both printed
  encounter tables); prefix pln (full-repo
  scan clean); header rules/pln.h; audit
  "R867 known planes audit", rode
  rules/audits/r867_batch.h. THE HEADLINE
  ADJUDICATIONS: the wind-table 13-16 garble
  "Blocwozr;tfefr;:ourse" = "Blows off
  course" (the L&L transcription); the
  inner-random fold bands 8.9 -> 8-9 and
  1011 -> 10-11, the Negative 5-7 band by
  the 1-20 tiling arithmetic; the ethereal
  "Elemental, earth ]" count = 1 (the
  tiling geometry); the astral single-number
  tokens (shedu 2-5 etc.) read from L&L;
  the Titan lesser band 93-97 pinned over
  the L&L 92-97 typo; "Tifan, major" =
  Titan major; the BARDT/91h bard-footnote
  glyph garbles (fighter 7-8, thief 6-9
  d4+5); the High "00" -> 100 convention;
  Flag 1 = the asterisk creatures
  (basilisk, cockatrice, gorgon, medusa),
  Flag 2 = the human traveller subtable
  row. ZERO registry defs touched - the
  floor holds at 995. Spec
  tools/spec_r867.json, md5
  3116ee4c80ec448ea28960991bdbdb8c (79,784
  bytes); 238 inlines (71 consts, 137
  bools, 30 table cols, 8 grids), 23
  examples; rverify double-run GREEN, 718
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens (the R854 rule); all
  bool example refs in the != 1 operator
  form (the R865 rule held first-try);
  audit mirror caught two builder example
  ordinal slips pre-publish (the AtcOrd
  tail-row and the RnoHigh Abyss-band row
  index) plus a builder f-string slip -
  {M('col')}(i) emits m[...]()(i), the
  index must ride INSIDE the M() call;
  renamed ConcordantTrueN (its True
  substring trips the no-True-token scan).
  ddg gap 19/24 closed, 5 open (App 2-4,
  the index, the alignment figures). NEXT:
  the D&DG arc tail - App 2 temple
  trappings p. 134 or Curtiss's call -
  WAIT FOR GO.

  - R868 LANDED 2026-10-26: commit
  e4220b7bc9a7e1f14db3da193b1561a7fab21b0e (pushed
  35f7686..e4220b7, census 790 -> 791), APPENDIX 2
  TEMPLE TRAPPINGS - the D&DG walk round twenty,
  print p. 134: the stocking doctrine of the intro
  (the representative sample, the DM keying of
  worshipers and servitors, choose-from-list with
  random only for details or spur-of-the-moment, the
  not-applicable caveat, the no flame pits in a
  lawful good temple example) plus the 40-band
  trappings list (01-05 altar through 99-00 vestments)
  as the round's one grid (40 rows, Ord/Low/High) with
  the 40-label roster riding the round's data file
  doc/data/ddg_temple_trappings.txt; prefix tpl
  (full-repo scan clean); header rules/tpl.h; audit
  "R868 temple trappings audit", rode
  rules/audits/r868_batch.h. THE HEADLINE
  ADJUDICATIONS: the print reads CHOIR AREA (two
  words - the psm-4 fold merged them, the L&L voice
  keeps the space); FONT/IMMERSION CHAMBER (no space
  after the slash); LECTERN/DAIS (the L&L
  transcription trims to lectern - the print pinned);
  holy/unholy books AND tomes (the L&L
  double-ampersand a transcription artifact); and
  the L&L <cleric scrolls> and <+5 holy avenger,
  etc.> glosses are 5TH-PRINT ADDITIONS, absent from
  the 2nd print - noted divergences, not pinned. The
  vestments 00 reads 100 (the R867 High convention).
  THE BAND CLASSES: 11 single-number rows, 17
  two-number rows (the vestments 99-00 is a pair,
  not a wide band), 12 wide rows, the widest band
  six numbers (the books row 30-35); the list tiles
  01-00 = 100. ZERO registry defs touched - the
  floor holds at 995. Spec tools/spec_r868.json, md5
  e452e379e10f0fddfdd8be12f0598724 (19,954 bytes);
  33 inlines (17 consts, 13 bools, 3 table cols), 11
  examples; rverify double-run GREEN, 150 mutants 0
  missed; hyphen scan clean; zero True/False tokens
  in the emitted files (the seed record may carry
  them - the R867 spec precedent); the R865
  bool-operator rule held first-try. ENGINE LESSONS:
  the banner NEEDS a provenance field (the engine
  reads it unconditionally) and a grid
  header_sections ref is {kind: table, name: <the
  table name>} - a bare {kind: table} dies at
  pool[item[name]]. ddg gap 20/24 closed, 4 open
  (App 3, App 4, the index, the alignment figures).
  NEXT: App 3 the clerical chart pp. 134-142 (the
  big tabular tail, likely multiple rounds) or
  Curtiss's call - WAIT FOR GO.

  - R869 LANDED 2026-10-26: commit
  7ced16344157530ffbf05f1b97ec80624f28e140 (pushed
  06c35eb..7ced163, census 791 -> 792), APPENDIX 3
  THE CLERICAL CHART, BATCH ONE - the D&DG walk
  round twenty-one, print pp. 134-135: the chart
  intro/legend doctrine (quick-reference purpose,
  alphabetical-within-pantheon with the most
  important first, guidelines-only, rank-by-color,
  the ordained-anytime rule, the six field
  definitions with the acknowledgement-is-not-
  granting caveat) plus the FIRST BATCH of deity
  rows - American Indian (9), Babylonian (8),
  Celtic (12) - as the round's one grid (29 rows,
  13 cols: Ord, the nine string-field roster
  ordinals, the M/F/N-H flags) with the nine
  per-column rosters riding doc/data/
  ddg_clerical_chart_1.txt; prefix cqc
  (full-repo scan clean); header rules/cqc.h;
  audit "R869 clerical chart batch one audit",
  rode rules/audits/r869_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the first no-flip round; gap_flips: []
  is legal, gap census 20/4 unchanged). THE
  PRINT VOICE: the chart prints LANDSCAPE - the
  committed psm-4 pass is 90-degree garbage and
  the IA 1st-print scan is 180-flipped (decoded
  with noise: uoow=moon); the voice is the
  ROTATED tesseract pass (pdftoppm -r 300 renders
  the pdf pages, PIL rotate(-90), tesseract
  stdout redirect), committed 97fcaac (pdf
  136-143) + 06c35eb (pdf 135, the App 2 page's
  rotated block) after TWO zero-byte stray
  commits (c7ced34, 23af32b - the tesseract
  output-base .txt-APPEND trap doubles the
  extension and the empty files ride the commit;
  the fix: stdout redirect; and the pg-*.png were
  missing, regenerated via poppler). THE
  COLLATION VOICE: the 1eonline L&L per-deity
  chart rows (12 values after the Place of
  Worship header; the mml.htm slug for Manannan
  Mac Lir; urllib is 406-blocked, curl works).
  THE HEADLINE ADJUDICATIONS: the DRUAGA
  FEMALE-CLERICS X - the print reads two X marks
  (M and F) where the L&L voice reads male-only -
  pinned by print, eyeball flag (the Gawaine 112
  precedent); the sphere semicolons pinned by
  print (Heng thunder; weather, Hotoru wind;
  weather, Ishtar love; war, Marduk cities;
  weather, Brigit fire; poetry - the L&L
  transcription normalizes to commas); the
  Hastsezini jode green = jade green (L&L); the
  Arawn at death frequency (the fold); the Lugh
  Ltugh print garble; the Silvanus stray quote
  glyph noted; and the chart carries NO
  ARTHURIAN BLOCK (the Arthurian section is
  heroes-only - the batch order runs American
  Indian, Babylonian, Celtic). ZERO registry defs
  touched - the floor holds at 995. Spec
  tools/spec_r869.json, md5
  ca2f5f4ed13cbdc0453570e05df41ad9 (31,794
  bytes); 57 inlines (24 consts, 20 bools, 13
  table cols), 10 examples; rverify double-run
  GREEN, 421 mutants 0 missed; hyphen scan
  clean; zero True/False tokens in the emitted
  files; the R865 bool-operator rule held
  first-try. BUILDER LESSON: hand-guessed roster
  ordinals in example exprs are a losing bet -
  derive every grid-cell term from the computed
  rosters (a chk(name, field) helper building
  m[...](row) != code from ROWS/CODES); the
  audit mirror caught all 8 wrong-ordinal
  examples pre-publish. NEXT: the App 3 chart
  batches continue from Central American +
  Chinese + Cthulhu (pdf pp. 136-137) or
  Curtiss's call - WAIT FOR GO.

  - R870 LANDED 2026-10-27: commit
  87bf7db2853dd0138ef61c040fc3a376e9a61598 (pushed
  7ced163..87bf7db, census 792 -> 793), APPENDIX 3
  THE CLERICAL CHART, BATCH TWO - the D&DG walk
  round twenty-two, print pp. 136-137: the Central
  American (12), Chinese (15) and Cthulhu (8) deity
  rows as the round's one grid (35 rows, 13 cols:
  Ord, the nine string-field roster ordinals, the
  M/F/N-H flags) with the nine per-column rosters
  riding doc/data/ddg_clerical_chart_2.txt; prefix
  cqc2 (full-repo scan clean); header rules/cqc2.h;
  audit "R870 clerical chart batch two audit", rode
  rules/audits/r870_batch.h. NO GAP FLIP - the
  App 3 box stays open until the last chart batch
  (the R869 no-flip precedent; gap census 20/4
  unchanged). THE PAGE-BREAK LESSON: the Cthulhu
  block spills onto pdf p138's head (Ithaqua,
  Nyarlathotep, Shub-Niggurath, Yog-Sothoth) - each
  chart pdf page may carry the previous batch's
  tail; the L&L slugs for the odd names ride the
  index pages (flafp.htm for Fei Lien and Feng Po,
  nocha.htm for No Cha). THE HEADLINE
  ADJUDICATIONS: the HASTUR COLOR - the print
  reads sky blue where the L&L voice reads
  yellow-orange (an L&L duplication of the Cthuga
  entry) - pinned by print, eyeball flag (the
  Druaga precedent); the print's gray spellings
  (Ithaqua, Shub-Niggurath) pinned over the L&L
  grey; the L&L <sea caves> gloss on the Cthulhu
  place a 5th-print addition, noted not pinned;
  the chart prints CTHUGA where the write-up and
  the R856 walk pin Cthugha (the chart garble
  noted, the row rides the write-up spelling); the
  !-glyph name garbles (Huehueteotl, Tlazolteotl)
  and the FeiLien space restored from L&L; the
  semicolon spheres (bats; evil, life; love; water,
  gambling; chance) - both voices agree here, both
  pinned. THE FLAG CLASSES: every batch two row
  reads a male X (35), 22 female X (11 CA, 9
  Chinese, 2 Cthulhu), 12 non-human X (4 CA - the
  Chinese pantheon reads none - 8 Cthulhu, every
  Cthulhu row). ZERO registry defs touched - the
  floor holds at 995. Spec tools/spec_r870.json,
  md5 484a83271432d34dc09e0b3c3c00b84a (31,335
  bytes, authored-plus-newline); 46 inlines (23
  consts, 10 bools, 13 table cols), 7 examples;
  rverify double-run GREEN, 488 mutants 0 missed
  (re-run GREEN on the exact final bytes after the
  trailing-newline append); hyphen scan clean;
  zero True/False tokens in the emitted files; the
  R865 bool-operator rule held first-try; the
  chk(name, field) builder pattern held first-try
  (zero wrong-ordinal examples - the R869 lesson
  paid off). NEXT: the App 3 chart batches
  continue from Egyptian + Finnish (pdf 138) or
  Curtiss's call - WAIT FOR GO.

  - R871 LANDED 2026-10-27: commit
  42a4fb828c2cbe10129484405a6ba7c5007d704a (pushed
  87bf7db..42a4fb8, census 793 -> 794), APPENDIX 3
  THE CLERICAL CHART, BATCH THREE - the D&DG walk
  round twenty-three, print pp. 138-139: the
  Egyptian (17) and Finnish (11) deity rows as the
  round's one grid (28 rows, 13 cols: Ord, the
  nine string-field roster ordinals, the M/F/N-H
  flags) with the nine per-column rosters riding
  doc/data/ddg_clerical_chart_3.txt; prefix cqc3
  (full-repo scan clean); header rules/cqc3.h;
  audit "R871 clerical chart batch three audit",
  rode rules/audits/r871_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the R869 no-flip precedent; gap census
  20/4 unchanged). THE HEADLINE ADJUDICATIONS:
  the SEKER ROW - the L&L transcription
  duplicates Shu onto Seker (bare, blue vest,
  light blue, equinox, semiannually, gems) while
  the print reads the distinct Seker row
  (feathered helm, white tunic, white, summer
  solstice, annually, jewelry) - pinned by
  print, eyeball flag (the Hastur/R869 Druaga
  precedent class: L&L duplication); the empty
  L&L sphere cells (Geb earth, Set evil) pinned
  by print; the Isis magic spelling pinned (the
  L&L magick <(The Occult)> gloss a 5th-print
  addition); the ILMATAR SINGLE X - the TSV
  geometry seats it in the F column (x 1085
  against the M 1030 / F 1086 bars; the first
  geometry pin of the chart rounds),
  female-only, both voices agree; the Bes
  Ie;:nher garble restored to leather vest,
  kilt from L&L; the Ukko chain mail pinned
  over the L&L chian typo; the Mielikki
  lowercase nature pinned. THE FLAG CLASSES:
  male 27 (Ilmatar the only row without),
  female 27 (Anhur the only row without),
  non-human 6 (all Egyptian - the Finnish
  rows read none). ZERO registry defs touched
  - the floor holds at 995. Spec
  tools/spec_r871.json, md5
  de52a8ab7a2121174bb201ed53cbd208 (27,624
  bytes, authored-plus-newline); 45 inlines
  (22 consts, 10 bools, 13 table cols), 7
  examples; rverify double-run GREEN, 396
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  R865 bool-operator rule held first-try; the
  chk(name, field) builder pattern held
  first-try. NEXT: the App 3 chart batches
  continue from Greek + Indian (pdf 139, the
  Greek block below the R871 Finnish tail) or
  Curtiss's call - WAIT FOR GO.

  - R872 LANDED 2026-10-27: commit
  aa3e815c2ea1ec164d7e3aeb2d775d552642990d (pushed
  42a4fb8..aa3e815, census 794 -> 795), APPENDIX 3
  THE CLERICAL CHART, BATCH FOUR - the D&DG walk
  round twenty-four, print pp. 139-140: the Greek
  (18) and Indian (13) deity rows as the round's
  one grid (31 rows, 13 cols: Ord, the nine
  string-field roster ordinals, the M/F/N-H flags)
  with the nine per-column rosters riding
  doc/data/ddg_clerical_chart_4.txt; prefix cqc4
  (full-repo scan clean); header rules/cqc4.h;
  audit "R872 clerical chart batch four audit",
  rode rules/audits/r872_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the R869 no-flip precedent; gap census
  20/4 unchanged). THE HEADLINE ADJUDICATIONS:
  the APHRODITE X PAIR - the print reads two X
  marks (M and F, the TSV geometry at x
  1049/1104) where the L&L voice reads
  female-only - pinned by print, eyeball flag
  (the Druaga precedent); the ZEUS COLUMN SPLIT -
  the print reads color white and holy days red
  sunrise (both voices agree - an eyeball
  oddity, not a divergence); the Poseidon seqa
  garble restored to sea; earthquakes from L&L
  (the sea/seas ambiguity rides the
  restoration); the Apollo laure! garble
  restored to laurel wreath; the Indra rainbow
  pinned plain (the L&L <> glyph an artifact);
  the Yama no-article form pinned (the L&L
  inserts a) with the stray : glyph noted; the
  Ushas atdawn fold restored (the Arawn/Hades
  fold class); the Rudra red, black comma
  pinned; the geometry confirmed Artemis (F +
  N-H), Pan (M + N-H), Indra/Karttikeya/Yama
  male-only - all agreeing with L&L. THE FLAG
  CLASSES: male 29 (Artemis and Ushas the rows
  without), female 26 (Apollo, Pan, Indra,
  Karttikeya, Yama the rows without),
  non-human 9 (5 Greek, 4 Indian). ZERO
  registry defs touched - the floor holds at
  995. Spec tools/spec_r872.json, md5
  fa6e5f1302a257f93722b66a89479330 (28,203
  bytes, authored-plus-newline); 45 inlines
  (22 consts, 10 bools, 13 table cols), 7
  examples; rverify double-run GREEN, 435
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  R865 bool-operator rule held first-try; the
  chk(name, field) builder pattern held (one
  census-comment fix mid-build - the male count
  comment named only Artemis, Ushas corrected).
  NEXT: the App 3 chart batches continue from
  Japanese + Melnibonean (pdf 140, the Japanese
  block below the R872 Indian tail) or
  Curtiss's call - WAIT FOR GO.

  - R873 LANDED 2026-10-27: commit
  397b33b8317fdcfb3f002f906b7edb6aaf8f0172 (pushed
  aa3e815..397b33b, census 795 -> 796), APPENDIX 3
  THE CLERICAL CHART, BATCH FIVE - the D&DG walk
  round twenty-five, print pp. 140-141: the
  Japanese (10) and Melnibonean (15) deity rows as
  the round's one grid (25 rows, 13 cols: Ord, the
  nine string-field roster ordinals, the M/F/N-H
  flags) with the nine per-column rosters riding
  doc/data/ddg_clerical_chart_5.txt; prefix cqc5
  (full-repo scan clean); header rules/cqc5.h;
  audit "R873 clerical chart batch five audit",
  rode rules/audits/r873_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the R869 no-flip precedent; gap census
  20/4 unchanged). THE HEADLINE ADJUDICATIONS:
  the AMA-TSU-MARA DIVERGENCE - the print reads
  metalwork at the hearth where the L&L voice
  reads precious metalwork and temple - pinned
  by print (metalwork + hearth); the DAIKOKU
  SPHERE GARBLE restored (wealth; luck, the
  name on the R861 Daikoku pin); the TEN
  MELNIBONEAN N-H-ONLY ROWS - TSV geometry
  (single X at x 1144-1152, the N-H column;
  M ~1040, F ~1097) with L&L agreeing - Arioch,
  Darnizhaan (M + N-H), Donblas, Pyaray, Xiombarg
  carry M/F marks, the elemental/beast rows
  carry none; the HAAASHASTAAK COLUMN SHIFT -
  the L&L voice moves dinosaurs from animal to
  sphere, the print animal pinned (lizard,
  dinosaur); the L&L [swan]/[tiger]/[whale]
  brackets read as gloss markers, not ink - the
  plain print animals pinned; the Hachiman
  equirox garble restored (fall equinox); the
  Ebisu brownrobes fold restored (brown robes,
  like the R872 Ushas atdawn class); the
  Tsukiyomi L&L page header read Sphere of
  Worship (the alternate header) - the row
  itself agrees; the Roofdrak stray » glyph
  and the Grome stray apostrophe noted (print
  artifacts, not ink). THE FLAG CLASSES: male
  15, female 13, non-human 15 (the ten
  N-H-only Melnibonean rows plus Darnizhaan,
  Donblas, Arioch, Pyaray, Xiombarg; the
  Japanese rows read no N-H marks). ZERO
  registry defs touched - the floor holds at
  995. Spec tools/spec_r873.json, md5
  87dc83f95d916d3454361658d82804c2 (25,853
  bytes, authored-plus-newline); 45 inlines
  (22 consts, 10 bools, 13 table cols), 6
  examples; rverify double-run GREEN, 357
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  chk(name, field) builder pattern held
  first-try; the canvas spec-r873 gated
  byte-exact (frontmatter + spec bytes, no
  extra newline). NEXT: the App 3 chart batches
  continue from Nehwon (pdf 141) or Curtiss's
  call - WAIT FOR GO.

  - R874 LANDED 2026-10-27: commit
  bb7ff6330d1b90f983ae1fe981243384eed2db28 (pushed
  397b33b..bb7ff63, census 796 -> 797), APPENDIX 3
  THE CLERICAL CHART, BATCH SIX - the D&DG walk
  round twenty-six, print p. 141: the thirteen
  Nehwon deity rows as the round's one grid
  (13 rows, 13 cols: Ord, the nine string-field
  roster ordinals, the M/F/N-H flags) with the nine
  per-column rosters riding
  doc/data/ddg_clerical_chart_6.txt; prefix cqc6
  (full-repo scan clean); header rules/cqc6.h;
  audit "R874 clerical chart batch six audit",
  rode rules/audits/r874_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the R869 no-flip precedent; gap census
  20/4 unchanged). THE HEADLINE ADJUDICATIONS:
  the AARTH DIVERGENCE - the print reads the
  flags male + female only (the geometry seats
  no X at the N-H column) where the L&L voice
  reads a third X - pinned by print, eyeball
  flag; the RED GOD SPHERE - the print glyph run
  reads fire where the L&L voice reads
  underground areas - pinned by print (the
  red-failed hawk garble restored to red-tailed
  hawk, the redstudded fold restored to red
  studded leather); the HATE PLACE - the print
  reads the single word underground (the
  garble restored) where the L&L voice adds
  temple - pinned by print; the EARTH GOD NAME -
  the rotated pass reads Earth God but the row
  sorts after Kos (the N of Nehwon) and the R863
  prose name carries the prefix - pinned Nehwon
  Earth God; the RAT GOD GEOMETRY - the X pair
  at M and N-H, none at F (the L&L voice agrees);
  the TYAA female-only flag (the single X at the
  F column, the L&L voice agrees); the Gods of
  Lankhmar year's end and Spider God summer
  solstice garbles restored; the Gods of Trouble
  stray dot noted (a print artifact, not ink). THE
  FLAG CLASSES: male 12, female 11, non-human 2
  (Death and the Rat God). ZERO registry defs
  touched - the floor holds at 995. Spec
  tools/spec_r874.json, md5
  87cc63bfd273f47e5fde5c4b96290a1a (23,144
  bytes, authored-plus-newline); 44 inlines
  (21 consts, 10 bools, 13 table cols), 6
  examples; rverify double-run GREEN, 200
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  builder computed every ordinal from the
  rosters (the R869 lesson held); the canvas
  spec-r874 gated byte-exact (frontmatter +
  spec bytes, no extra newline). NOTE: the
  1eonline fetch needed the full Chrome UA plus
  the Referer header this round (the bare curl
  UA hit the Mod_Security 406 again; the domain
  is 1eonline.info, not .com). NEXT: the App 3
  chart batches continue from the Nonhumans'
  Deities rows (pdf 142) or Curtiss's call -
  WAIT FOR GO.

  - R875 LANDED 2026-10-27: commit
  91b983c320a3a228771974e35be5c355f0263981 (pushed
  bb7ff63..91b983c, census 797 -> 798), APPENDIX 3
  THE CLERICAL CHART, BATCH SEVEN - the D&DG walk
  round twenty-seven, print p. 142: the twenty-four
  Nonhumans' Deities rows as the round's one grid
  (24 rows, 13 cols: Ord, the nine string-field
  roster ordinals, the M/F/N-H flags) with the nine
  per-column rosters riding
  doc/data/ddg_clerical_chart_7.txt; prefix cqc7
  (full-repo scan clean); header rules/cqc7.h;
  audit "R875 clerical chart batch seven audit",
  rode rules/audits/r875_batch.h. NO GAP FLIP -
  the App 3 box stays open until the last chart
  batch (the R869 no-flip precedent; gap census
  20/4 unchanged). THE HEADLINE GEOMETRY: THE
  WHOLE BATCH IS N-H-ONLY - all 24 X marks seat
  at the N-H column (headers M 1014, F 1071,
  N-H 1127; zero M and zero F marks anywhere);
  the L&L voice agrees on all 22 rows it carries.
  THE ADJUDICATIONS: the DEMOGORGON AND YEENOGHU
  PRINT-ONLY ROWS (the L&L MM pages carry no
  chart row) - the Demogorgon color reptile green
  and the ixitxachitl sphere garble restored ride
  the print; the NAME GARBLE CLASS - Sekolah,
  Semuanya, Skoraeus Stonebones, Surtur, Thrym
  and Yeenoghu restored per the R864 crossref
  pins (the stray 4 glyph before Surtur noted);
  the Deep Sashelas seqa green garble restored to
  sea green (the R872 Poseidon class); the
  Grolantor daork brown and na garbles restored;
  the Garl warhelm and Gruumsh waorhelm folds
  restored to war helm (the R874 red studded
  class); the Gruumsh body wrap black plate mail
  with its underscore and dash-pair strays noted;
  the Lolth stray i glyph and wrap-line dot
  noted; the Yondalla colon glyph noted (both
  voices carry it). THE FLAG CLASSES: male 0,
  female 0, non-human 24. ZERO registry defs
  touched - the floor holds at 995. Spec
  tools/spec_r875.json, md5
  208bde026f0a66983ad7899d4ae9c389 (27,785
  bytes, authored-plus-newline); 44 inlines
  (21 consts, 10 bools, 13 table cols), 6
  examples; rverify double-run GREEN, 343
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  builder computed every ordinal from the
  rosters (the R869 lesson held); the canvas
  spec-r875 gated byte-exact (frontmatter +
  spec bytes, no extra newline). NOTE: the
  builder may carry apostrophes in the emitted
  header comments via double-quoted Python
  string literals (Nonhumans' Deities) - the
  engine gates count double quotes only, and the
  R873/R874 apostrophe-free style was builder
  convenience, not a gate. NEXT: the LAST chart
  batch - Norse + Sumerian (pdf 143, the R865/
  R866 mythos rows) - carries the App 3 gap
  flip; scope it with Curtiss - WAIT FOR GO.

  - R876 LANDED 2026-10-27: commit
  021f18afa8f1e80b199a68809c410029c56e1fa6 (pushed
  91b983c..021f18a, census 798 -> 799), APPENDIX 3
  THE CLERICAL CHART, BATCH EIGHT - the D&DG walk
  round twenty-eight, print p. 143: the LAST chart
  batch - the twenty-one Norse rows (the nineteen
  data rows plus the Surtur and Thrym
  cross-references) and the seven Sumerian rows as
  the round's one grid (28 rows, 13 cols: Ord, the
  nine string-field roster ordinals, the M/F/N-H
  flags) with the nine per-column rosters riding
  doc/data/ddg_clerical_chart_8.txt; prefix cqc8
  (full-repo scan clean); header rules/cqc8.h;
  audit "R876 clerical chart batch eight audit",
  rode rules/audits/r876_batch.h. NO GAP FLIP -
  the App 3 flip was HELD at the R876 scoping per
  Curtiss ("hold the no-flip precedent one more
  round"): gap_flips: [], the census holds 20/4,
  and the no-flip precedent now extends PAST the
  last chart batch - the flip rides whichever round
  Curtiss assigns it to. THE CROSSREF SCOPING
  (author's call per Curtiss): the Surtur and Thrym
  "see Nonhumans' Deities" rows pinned AS GRID ROWS
  with 0-sentinel fields and the crossref comment
  (they physically print as chart rows; their
  field data landed R875 - print fidelity, the
  bare-cell/See-below 0-sentinel convention). THE
  HEADLINE ADJUDICATIONS (the rotated pass primary,
  the TSV geometry, the 1eonline L&L collation -
  full Chrome UA + Referer, the R874 note held
  first-try): the FRIGGA FEMALE-ONLY single X
  (geometry seats it at the F column, no M mark -
  the L&L voice agrees, the walk's first
  female-only Norse row) and the HEL MALE-ONLY
  single X (the same class, both voices agree); the
  THOR FORM DIVERGENCE - the print reads burnt
  animals where the L&L voice reads crafted items -
  pinned by print, eyeball flag (the R869 Druaga
  precedent); the Frey ornate helm restored over
  the L&L orntate garble; the Loki strife; fire
  semicolon pinned by print (the L&L comma an
  artifact); the Uty -> Utu and lowercase idun ->
  Idun garbles restored per the R865/R866 pins; the
  Nin-Hursag chart capitalization pinned per the
  chart print; the Odin wolves, ravens, Heimdall
  white plate mail and Idun forest meadows wraps
  restored. THE FLAG CLASSES: male 25, female 17
  (Frigga the only row without an M mark),
  non-human 3 (Frey, Enki, Ki). ZERO registry defs
  touched - the floor holds at 995. Spec
  tools/spec_r876.json, md5
  a849eac50ab05afa9d1d40e75424036d (29,736 bytes,
  authored-plus-newline); 45 inlines (23 consts, 9
  bools, 13 table cols), 6 examples; the builder
  computed every ordinal from the rosters (the
  R869 chk pattern held first-try; a builder-side
  female recount 16 -> 17 caught pre-publish by
  the assert); rverify double-run GREEN, 396
  mutants 0 missed; hyphen scan clean; zero
  True/False tokens in the emitted files; the
  canvas spec-r876 gated byte-exact (frontmatter +
  spec bytes, no extra newline). The v4 fresh start
  stays deferred per Curtiss ("later - just keep
  seating records"), the topic rides past 100KB.
  NEXT: the chart walk is COMPLETE - the D&DG tail
  is App 4 (pdf 143), the index (pdf 143), the
  print-p.131 FIG. 4/5 alignment-figures pixel
  work, and the parked App 3 gap flip - Curtiss's
  call - WAIT FOR GO.

  - R877 LANDED 2026-10-27: commit
  6a95b8b8b9d4cc77c2ba2dd8994dcc6043b16e84 (pushed
  021f18a..6a95b8b, census 799 -> 800), APPENDIX 4
  AND THE INDEX - the D&DG walk round twenty-nine,
  print pp. 143-144 (pdf 144-145): the whole D&D
  tail - the seventeen-entry FURTHER REFERENCE
  bibliography (pdf 144 top) and the 433-term INDEX
  OF PROPER NAMES across the six column runs
  (61/61/61/84/83/83). THE TRIPLE GAP FLIP: the
  App 3, App 4 and index boxes closed together (the
  parked App 3 flip riding R877 per Curtiss's
  assignment, the R485 doctrine) - gap census
  20/4 -> 23/1, the alignment figures the lone open
  box. THE MECHANISM NOTE: the sandbox lost git and
  every C++ compiler and the GitHub App connector
  proved read-only (403 on all writes), so the
  spec transited via the gated canvas and CURTISS
  ran ./rn in Termux - zero deviation, preflight
  GREEN on his fresh binary; the landed tree
  verified byte-exact against the sandbox
  reference (tarball fetch, all eight files
  cmp-clean). ROUND FACTS: 637 citations, 307
  single-page terms, Odin Ord 287 the only 8-page
  term (113,114,116,118,119,120,123,124), Thrym
  Ord 379 the 123,108,113 wrap; App 4: 17 entries,
  16 dated, Paperback 4 (Budge, Davidson, Malory,
  Squire), TwoVolumes 2 (Hodge, Malory), NoDate 1
  (Hackin). THE HEADLINE ADJUDICATIONS: the
  leading-1 drop class has EIGHT members
  (Blodug-Hofi 117 found at the final-parse
  review); the fused-glyph pages (Eadro 111,
  Vaprak 111, Jason 71, Harp of Calm 115); the
  name garbles restored per the walk pins (R'lyeh
  through Ningauble of the 7 Eyes - the numeral 7
  rides the print); the Caduceus + Nemean lion
  skin 71 class (the IA voice drops the leading
  7); Ankh true lowercased per the R857 grep-gate
  precedent; the print order quirks (7) pinned as
  printed, both voices agreeing; the
  word-convention sorts read as convention; the
  non-ascending citation lists and double listings
  pinned (Karttikeya x2, Deep Sashelas, the Hunt
  packs); Rakel of Iron the eyeball flag; the
  Horus stray dash; the write-up divergences
  (Chuthga, Sleipnir, Snake-Man) pinned by print;
  the App 4 IA restores (Encyclopedia to
  Encyclopaedia, Indians, Lid., in-cluded, Eric!)
  and print oddities (Rowan & Littlefield,
  Bullfinch) pinned as printed; the boldface
  doctrine pinned with the noted per-term
  bold-detection limitation; the INDEX headers not
  terms. THE SHAPE: the index grid one row per
  term (433 rows, 10 cols: Ord + P1..P8 + Count,
  0-sentinel), the App 4 grid one row per entry
  (17 rows, 5 cols: Ord, Year, Paperback,
  TwoVolumes, NoDate); the rosters ride
  doc/data/ddg_index.txt and doc/data/
  ddg_app4.txt; prefix idx (full-repo scan clean);
  header rules/idx.h; audit "R877 Appendix 4 and
  index audit" rode rules/audits/r877_batch.h;
  regtest.cpp +2 include lines. ZERO registry
  defs touched - the floor holds at 995. Spec
  tools/spec_r877.json, md5
  9e5402c229888deaf566d9921f8d1d8d (80,636 bytes,
  authored-plus-newline); 57 inlines (24 consts,
  18 bools, 15 cols), 6 examples; the builder
  computed every ordinal from the rosters.
  LESSON: const names collided with table col
  names (idxApp4Paperback etc.) - the engine's
  parse_header dedupe caught it, renamed to
  idxApp4PaperbackCount/idxApp4TwoVolumesCount/
  idxApp4NoDateCount; the engine skips writing
  header/audit when the file exists (idempotency)
  - a spec change needs a fresh pristine tree
  re-extract. rverify double-run GREEN, 4,457
  mutants 0 missed; statics clean (audits dir
  799 = 798+1, idx.h maxwidth 92 opener-only,
  r877_batch.h 78 chars char-based - an earlier
  "80" was awk counting UTF-8 bytes of the right
  single quote; zero True/False tokens; quote
  parity even, idx.h zero double quotes; hyphen
  scan clean); the R876 record seated in the
  seed at line 25569; the canvas spec-r877 gated
  byte-exact (frontmatter + spec bytes, no extra
  newline). The v4 fresh start stays deferred per
  Curtiss. NEXT: the D&DG tail is ONE item - the
  print-p.131 FIG. 4/5 alignment-figures pixel
  round - Curtiss's call - WAIT FOR GO.

  - R878 LANDED 2026-10-27: commit
  7f4470980c34031928bf2e830f29f686ca98fb64 (pushed
  6a95b8b..7f44709, census 800 -> 801), THE
  ALIGNMENT FIGURES - the D&DG walk round thirty,
  the PIXEL round, print p. 131 (pdf 132): FIG. 4
  the character alignment graph and FIG. 5 the
  planes of alignment. THE LAST GAP FLIP: the
  alignment figures box closed - gap census
  23/1 -> 24/0, THE D&DG WALK COMPLETE. ROUND
  FACTS (vision reads of Curtiss's pdftoppm
  renders at c8bf507 and 1028ebe; both text
  voices near-zero on the page): FIG. 4 - nine
  alignments in print reading order (Ord 0
  NEUTRAL GOOD north through Ord 8 NEUTRAL
  center), CURVED lines converging at center
  (the crescent read, NOT crossing Venn
  lenses), the center circle NEUTRAL (true
  neutral), the four curved corner descriptors
  Saintly LG / Beatific CG / Diabolic LE /
  Demoniac CE only; the NEUTRAL EVIL label and
  the center circle are vision-only (tesseract
  TSV misses them). FIG. 5 - 16 segments around
  the CONCORDANT OPPOSITION center, straight
  radial dividers, plane names only, no arrows;
  ELYSIUM top, HADES bottom; the cycle reads the
  p. 129 print list order CLOCKWISE; the figure
  spells TARTARUS where the p. 129 list reads
  Tarterus (the pln.h pin) - the figure-vs-list
  delta pinned both as printed, TARTARUS
  eyeball-confirmed by Curtiss; the wheel matches
  the pln.h seventeen-planes pin. THE SHAPE:
  afgG4 one row per alignment (9 rows, cols
  Ord/Pos/Desc, 0-sentinel), afgG5 one row per
  plane (17 rows, cols Ord/Pos - the positions
  computed: Ord 3 ELYSIUM at 1 through Ord 1 at
  15, Ord 2 at 16, Ord 17 center at 0); the
  rosters ride doc/data/ddg_fig4.txt and
  doc/data/ddg_fig5.txt; prefix afg (full-repo
  scan clean); header rules/afg.h; audit "R878
  alignment figures audit" rode
  rules/audits/r878_batch.h; regtest.cpp +2
  include lines; 19 consts, 18 bools, 5 cols, 6
  examples (bool refs in the != 1 operator form
  per the R865 rule), 42 inlines. ZERO registry
  defs touched - the floor holds at 995. Spec
  tools/spec_r878.json, md5
  2e17babe37da1924d126d439aecbb66d (24,009
  bytes); the canvas spec-r878 gated byte-exact.
  THE MECHANISM NOTE: same canvas handoff - the
  spec transited via the gated canvas, CURTISS
  ran ./rn in Termux, zero deviation; the landed
  tree verified byte-exact against a sandbox
  re-derive from the pristine 1028ebe tree plus
  the canvas spec (the env reset wiped the build
  trees mid-verify - the canvas proved the
  authoritative transit, all eight files
  cmp-clean, zero strays). rverify GREEN, 98
  mutants 0 missed; statics clean (audits dir
  800 = 799+1, afg.h maxwidth 92 opener-only,
  r878_batch.h 78 chars char-based, zero
  True/False tokens in the emitted C++ files,
  quote parity even, hyphen scan clean - the
  standard section dividers only); the R877
  record seated in the seed before the
  maintenance anchor, idempotency key present.
  NEXT: the D&DG walk is COMPLETE - the queue per
  Curtiss's call 2026-10-27: the MAINTENANCE ARC
  FIRST (the registry-wide schema pass: full-field
  emission, the new DDG fields on all defs,
  sentinels distinct from print values), THEN the
  DDG lua promotion (all the D&DG monsters - the
  deities and the monster races - generated from
  the adjudicated pin headers, the
  promotion-from-headers doctrine; the stale "open
  calls: pin-only vs promoted" line RETIRED).
  WAIT FOR GO.
  - R879 LANDED 2026-10-27: commit
  dbe31707f510a24507fa34a1f69ac40b0641e996 (pushed
  7f44709..dbe3170, census 801 -> 802), THE
  REGISTRY SCHEMA - the maintenance-arc opener, the
  registry-wide schema pass.
  THE SHAPE: the live union schema pinned at 57
  keys (40 mm2lua base + 8 adjustment + 9 new DDG:
  divineRank, worshippersAlignment, symbol,
  areaOfControl, classLevelsRaw, classLevelsCooked,
  hitPointsRaw, hitPoints, hitPointsNote); mm2lua
  FIELD_ORDER widened + the emit loop switched
  full-field; MonsterRegistry.h/.cpp +9 DDG fields,
  uniform coercers one pass; sentinels DISTINCT
  from print values ("n/a" strings, -1 ints - 13
  int keys: hitDiceNum, hitDiceBonus, avgHp, xp,
  xpPerHp, xpValue, lairPct, saveAsBonus,
  loadNormal, loadMax, rank, wsgRoles, hitPoints);
  the one-shot idempotent normalizer shipped as a
  data_file (tools/normalize_registry.py) plus
  doc/data/registry_schema.txt +
  doc/data/registry_census.txt (the REAL per-key-
  per-book census).
  THE CENSUS PINS: floor 995 - MM1 408, MM2 332, FF
  185, OA 47, WSG 15, MOP 8; ZERO registry defs
  touched by R879 (the book rounds rewrite them);
  wsgRoles rides 15 WSG defs PLUS 3 MM1 mounts
  (pony, ape, mule) - the anchor catch of the
  round.
  THE MECHANICS: prefix rsc (full-repo scan clean),
  header rules/rsc.h (maxwidth 92 opener-only),
  audit "R879 registry schema audit" rode
  rules/audits/r879_batch.h (78 char-based); 10
  consts, 9 bools, 2 grids (books 6x2, keys 57x7
  real census), 7 examples (bool refs != 1 form),
  28 inlines, seed + the 76-line R878 record before
  the maintenance anchor; gap census 24/0
  untouched.
  VERIFIED: rverify GREEN, 430 mutants 0 missed;
  the normalizer proven idempotent in-sandbox (995
  rewritten once, zero on rerun, byte-identical);
  no compiler in the sandbox - Curtiss's ./rn
  preflight is the compile gate; the landed tree
  verified BYTE-EXACT vs a full re-derive from
  pristine 7f44709 plus the canvas spec (whole-repo
  diff zero). Spec tools/spec_r879.json, md5
  a5e8ae3e7d657338b4b97be1bcf85ffe (36,162 bytes);
  the canvas spec-r879 gated byte-exact.
  NEXT: the arc continues - the per-book
  normalization rounds (MM1 408, likely split; MM2
  332; FF 185; OA 47; WSG+MOP 23 tail), the defs
  rewritten by the normalizer and shipped as spec
  data_files byte-exact; THEN the DDG lua promotion
  (promotion-from-headers). WAIT FOR GO.
  - R880 LANDED 2026-10-27: commit
  22f9d1b55fa1401128b90b1f57c395a6d3ce8ce1 (pushed
  dbe3170..22f9d1b, census 802 -> 803), THE DDG LUA
  PROMOTION, BATCH ONE - the first promotion round,
  the first registry growth since the 995 floor: 55
  full-field defs (American Indian 14, Arthurian
  15, Babylonian 10, Celtic 16), the floor 995 ->
  1050.
  THE SHAPE: generated ONLY from the adjudicated
  pin headers (dgb/dgc/dgd/dge) - the four grids x
  rows (combat, class, ability, roster) parsed
  straight from the switch accessors; the name
  orders LOCKED by the pinned cross-references (the
  3/2 attacks comment, the Standard magic-
  resistance trio, the CH -1 and CH 6 cells, the
  Thunder Bird X/22,600, the Yanauluha
  cleric-20/druid-13, the Merlin 300-score) and
  verified against the primary ink extract pages;
  the legend tables decode verbatim (alignments,
  ranks, planes, worshipper alignments, the 99 see-
  below code, Standard/Infinite/Variable).
  THE HONEST BOUNDARIES: the prose stays contract-
  side (text/specials sentinel); damage emits ONLY
  pinned figures (the dgb strength bonuses, Merlin
  1-10 and Morgan 1-4, the six Babylonian figures)
  - the ten flagged Celtic rows carry figures the
  walk never adjudicated into the header, they stay
  n/a; symbols and areas of control stay n/a (no
  symbol grids pinned for these mythoi, though the
  print carries them - a possible future pin
  round); the two Arthurian templates emit
  alignment variable with the 80/85-lawful note
  (the header's own 4/5-code erratum vs the landed
  7/8 cells - NOT touched).
  THE CATCHES: the dgb Shakak/Snake-Man order
  corrected by the CH 6 pin (row 8, the tesseract
  column interleave misleads); the dge legend says
  eleven fixed-damage rows but the grid and audit
  pin ten - the grid wins.
  THE MECHANICS: prefix dpe (full-repo scan clean),
  header rules/dpe.h (92 opener-only), audit "R880
  DDG promotion audit" rode
  rules/audits/r880_batch.h (801 -> 802 audit
  files); 12 consts, 10 bools, 2 grids (mythoi 4x4,
  key-fill 57x2), 7 examples, inline 28; file
  patches: splice_engine.py makedirs before a data-
  file write (the R851 lesson - the promoted defs
  land in new lettered subdirs),
  normalize_registry.py book_of + DDG, the
  registry_census.txt refresh (the DDG column,
  floor 1050); seed + the 53-line R879 record.
  VERIFIED: rverify GREEN, 152 mutants 0 missed;
  the patched normalizer census reads 1050 defs
  (DDG=55, every key on every DDG def); idempotency
  - first pass rewrites only the 995 sparse MM defs
  (their cargo rides the book rounds), the 55 DDG
  defs never rewrite; the landed tree verified
  BYTE-EXACT vs a full re-derive from pristine
  dbe3170 plus the canvas spec (whole-repo diff
  zero). Spec tools/spec_r880.json, md5
  40c3faa414ae3d618d6906baa707ef20 (110,210 bytes);
  the canvas spec-r880 gated byte-exact.
  NEXT: the promotion continues print-order - batch
  two (Central American 14 + Chinese 18 + Cthulhu
  15 + Egyptian 21 = 68 defs), then the
  Greek/Finnish, Indian/Japanese/Melnibonean and
  tail batches through Nonhumans and Norse. WAIT
  FOR GO.
  - R881 LANDED 2026-10-27: commit
  7dc48c28fc968a35cc6b255d50198d51bb201765 (pushed
  22f9d1b..7dc48c2, census 803 -> 804), THE DDG LUA
  PROMOTION, BATCH TWO - 68 full-field defs
  (Central American 14, Chinese 18, Cthulhu 15,
  Egyptian 21), the floor 1050 -> 1118, DDG 123.
  THE SHAPE: generated ONLY from the adjudicated
  dgf/dgg/cth/egp pin headers; the name orders
  LOCKED by the pinned cross-references (the
  summon-list flags, the Set-enmity flag, the twin
  pairs) plus primary-ink verification; Phoenix
  seated as "Phoenix (Egyptian)" (the MM2
  collision). HONEST BOUNDARIES:
  worshippersAlignment unpinned all 68 (no grids);
  the print-only fighter/paladin lines (Anhur,
  Horus, Seker, Shu); the garbled size/damage cells
  (Azathoth, Nyarlathotep, Chih Sung-Tzu, Spirits
  of the Air) and the unpinned lair percents stay
  sentinel. Spec tools/spec_r881.json, md5
  f36a706f2659f089e2b6d7f62d5819b9 (132,649 bytes);
  the canvas spec-r881 gated byte-exact. NEXT: the
  promotion continues print-order - Greek/Finnish,
  then Indian/Japanese/Melnibonean, then the tail
  batches through Nonhumans and Norse. WAIT FOR GO.
  - R882 LANDED 2026-10-27: commit
  2c9698198f68482bc5d9b2b159ff6a95b7f2c051
  (pushed 7dc48c2..2c96981, census 804 -> 805),
  THE DDG LUA PROMOTION, BATCH THREE - 60
  full-field defs (Finnish 20, Greek 40),
  the floor 1118 -> 1178, DDG 183. THE SHAPE:
  generated ONLY from the adjudicated klv/grk
  pin headers, prefix dpu; the grids hold the
  header row order while def emission rides
  the primary-ink print order (four adjacent
  pairs differ: Ilmarinen/Hiisi,
  Lemminkainen/Kullervo, Untamo/Air Maiden,
  Aphrodite/Antaeus - stat signatures verified
  both ways). PinnedDamage 44 (klv 12, grk 32);
  damage parens print on only some rows, and
  where printed equal the strength-damage grid
  (Artemis alone prints her +5 weapon bonus).
  HONEST BOUNDARIES: Apollo damage
  "By weapon type" and Poseidon's garbled cell
  -> n/a + flags; Atlas AtN pin 3 vs print 2;
  Ahto MR dual print (grid 50); Hermes AtN
  unrecovered; Furies/Circe xp -1; lair
  percents unpinned; worshippersAlignment,
  symbol, areaOfControl n/a all; the ranger
  prints ride the FIGHTER line (grids zero).
  Spec tools/spec_r882.json, md5
  39ba336b6f0fe28722d7daa531ba1178
  (117,796 bytes); the canvas spec-r882 gated
  byte-exact; rverify 144 mutants 0 missed;
  the land verified byte-exact against the
  fresh-tarball rebuild (1178 defs, dpu.h,
  audit, census, seed, regtest identical;
  engine idempotent applied 66 / already 66).
  NEXT: the promotion continues print-order -
  Indian/Japanese/Melnibonean, then the tail
  batches through Nonhumans and Norse. WAIT
  FOR GO.
  - R883 LANDED 2026-10-27: commit
  e1bb81748d7a4a73c1a685b0a74b799ed4b15e5f
  (pushed 2c96981..e1bb817, census 805 -> 806),
  THE DDG LUA PROMOTION, BATCH FOUR - 31
  full-field defs (Indian 18, Japanese 13),
  the floor 1178 -> 1209, DDG 214. THE SHAPE:
  generated ONLY from the adjudicated idn/jpn
  pin headers, prefix dpw; def emission rides
  the primary-ink print order (Amaterasu sits
  in the LEFT column of print 81 below the
  intro, so she reads before Ama-Tsu-Mara -
  the geometry-verified swap). PinnedDamage
  26 (idn 15, jpn 11 - Yamamoto Date 3-18 is
  pinned); the fixed-points damage cells
  (45/20/40 points); parens == StrDmg where
  printed. THE MARUT RENAME: the MOP Marut
  holds m/marut.lua, so the DDG Marut rides
  the R881 Phoenix precedent as "Marut
  (Indian)" (m/marut_indian.lua). The
  rangers print on the FIGHTER lines
  (Hachiman 20, Raiko 18, Susanowo 13,
  Tsukiyomi 12, Yoshi-iye 13); Susanowo is
  R13, not F13. HONEST BOUNDARIES: the
  buffalo 12-inch shoulder size (the one
  true-inch cell), the Susanowo and
  Kishijoten move slashes (the printed 48
  and third /12 ride col comments/garbles),
  Susanowo MR dual print (grid 30), the
  digit-split cells (Ebisu HP 3173 -> 313,
  Kishijoten HP 31717 -> 311, Kishijoten
  AtN 17 -> 1, Hachiman AC ~1, Hachiman
  assassin 175th -> 15, Tvashtri F ink 17
  vs grid 11); lair percents unpinned;
  worshippersAlignment, symbol, areaOfControl
  n/a all. Spec tools/spec_r883.json, md5
  99cd81742b062b3bfdb7191c55f75d66
  (71,581 bytes); the canvas spec-r883 gated
  byte-exact; rverify 144 mutants 0 missed;
  the land verified byte-exact against the
  fresh-tarball rebuild (1209 defs, dpw.h,
  audit, census, seed, regtest, spec
  identical; engine idempotent applied 37 /
  already 37). NEXT: the promotion continues
  print-order - Melnibonean, then the tail
  batches through Nonhumans and Norse. WAIT
  FOR GO.

  - R884 LANDED 2026-10-27: commit
  d838c9a95b0242007049a065075fc208085f4b40
  (pushed e1bb817..d838c9a, census 806 -> 807),
  THE DDG LUA PROMOTION, BATCH FIVE - 33
  full-field defs (the Melnibonean mythos),
  the floor 1209 -> 1242, DDG 247. THE SHAPE:
  generated ONLY from the adjudicated mlb pin
  headers, prefix dpx; def emission rides the
  grid order (Elric through Yyrkoon, the
  print order). Monster rows 14, hit-dice
  rows 8 (Clakar 6, Dharzi 2, Mist Giant 12,
  Myyrrhn 3, Nihrain 7, Oonai 7, vampire
  trees 8, vulture lion 9), PinnedDamage 26;
  parens == StrDmg where printed (Arioch,
  Donblas, Xiombarg +14). The ranger cells
  print on the FIGHTER lines (Grome 18,
  Misha 18, Roofdrak 15 - the pin adjudicates
  the Nth level ranger prints; no F tokens
  on those rows). HONEST BOUNDARIES: the
  HD-row tsv garbles vs the pins, the Kelmain
  See-below hit dice and Variable xp, the
  Oonai Variable attacks, the vampire trees
  1-10 attack band, the Arioch Variable
  size and the Fileet bare L, the Elric
  Standard-or-85 MR and the Stormbringer
  alt AC -6 (unpinned; armorClass rides the
  primary 6), the Theleb pin neutral evil vs
  the ink lawful evil, the Nuru-ah
  single-pipe psionic I, the junk-swallowed
  Moonglum, Nnuurrr and Nuru-ah columns read
  from the full-text voice; lair percents
  unpinned; worshippersAlignment, symbol,
  areaOfControl n/a all. Spec
  tools/spec_r884.json, md5
  3a857818399309d709c22fe8c2121ef8 (75,595
  bytes); the canvas spec-r884 gated
  byte-exact; rverify 140 mutants 0 missed;
  the land verified byte-exact against the
  fresh-tarball rebuild (1242 defs, dpx.h,
  audit, census, seed, regtest, spec
  identical; engine idempotent applied 39 /
  already 39). NEXT: the promotion continues
  print-order - Nonhumans, then the Norse
  tail. WAIT FOR GO.
  - R885 LANDED 2026-10-27: commit
  a187f5044959bac894c0719f228ddb706d7d8ce4 (pushed
  d838c9a..a187f50, census 807 -> 808), THE DDG LUA
  PROMOTION, BATCH SIX - 49 full-field defs (the
  Nehwon mythos 29 and the Nonhumans' Deities 20),
  the floor 1242 -> 1291, DDG 296. THE SHAPE:
  generated ONLY from the adjudicated nhw/nhg pin
  headers, prefix dpy (full-repo scan clean); def
  emission rides the grid orders (Fafhrd through
  the Water Cobra, then Hruggek through Laogzed).
  Monster rows 10 (all Nehwon), hit-dice rows 7
  (the Water Cobra 3+3 the first DDG hit-dice
  bonus), PinnedDamage 34 (nhw 17, nhg 17); parens
  == StrDmg where printed. THE RENAMES: the MM2
  Behemoth and the FF Lolth hold the stems, so the
  DDG rows ride the Phoenix/Marut precedent as
  "Behemoth (Nehwon)" (b/behemoth_nehwon.lua) and
  "Lolth (Nonhumans' Deities)"
  (l/lolth_nonhumans_deities.lua). The rangers
  print on the FIGHTER lines (Fafhrd R15, Kos R15,
  Corellon R20, Rillifane R15 - no F tokens); the
  twelve As-16+-HD fighter cells read as F16; the
  Devourer is a monster-format row that still
  carries class cells (F5 M13 I25 T10) and Int 19,
  per grid. HONEST BOUNDARIES: the ghoul by-weapon
  print against its DmgFixed flag and the earth god
  5-50 print against its 0 - both pin-internal,
  both emitting the n/a sentinel (the grid's 18
  ones vs the const 17; the Godsland 8-vs-9 and
  InEach 3-vs-1 the same divergence class), the
  Votishal hp 344 against the L&L 244, the Hate
  See-below armor class and the Tyaa bare dash
  pinned 0, the Gods of Trouble Special MR 0 as
  Standard, Ningauble Nil attacks 0 and the L (9')
  against the L&L M (9'), the Lolth monster-block
  voice (the -2 drow paren, the 1/9 web walk, the
  MR 70 against the L&L 75, the See-below class
  pairs, the L (M) size, no plane printed - the
  grid Abyss), the Skerrit Variable cells with the
  armor-class 2 floor, the Sashelas Standard (out
  of water), the Nine Hells plane pins against the
  L&L D64 glosses, Moradin 4-40 (+14) against the
  L&L +17, the fraction and quarter sizes (the
  Mouser 5 1/4, Yondalla 4 1/2, Kurtulmak 5 1/2),
  the Hruggek 1-or-2 and Eadro 1-or-8 attack raws;
  lair percents unpinned; worshippersAlignment,
  symbol, areaOfControl n/a all. Spec
  tools/spec_r885.json, md5
  43e5f6bcd27746fcbef08b8cfbb2e260 (102,346 bytes);
  the canvas spec-r885 gated byte-exact; rverify
  144 mutants 0 missed; the land verified
  byte-exact against the fresh-tarball rebuild
  (1291 defs, dpy.h, audit, census, seed, regtest,
  spec identical; engine idempotent applied 55 /
  already 55). NEXT: the promotion tail - Norse,
  then Sumerian. WAIT FOR GO.
  - R886 LANDED 2026-10-27: commit
  69d4b93424c55ac1ad9dd82f95c3ff566157cecd
  (pushed a187f50..69d4b93, census 808 -> 809),
  THE DDG LUA PROMOTION, BATCH SEVEN - 42
  full-field defs (the Norse mythos 35, the
  Sumerian mythos 7), the floor 1291 -> 1333,
  DDG 338 - THE PROMOTION COMPLETE (55+68+
  60+31+33+49+42 = 338, every DDG row
  promoted). THE SHAPE: generated ONLY from
  the adjudicated nrs/smr pin headers, prefix
  dpz (full-repo scan clean); def emission
  rides the grid orders (Odin through the
  Valkyries, then Enlil through Utu). Monster
  rows 11 (the pin const against the ten
  rank-5 grid rows - the pin-internal flag),
  hit-dice rows 1 (the Fossergrim 5 HD
  print), PinnedDamage 32 (nrs 27, smr 5). NO
  RENAMES (all 42 stems free - no
  Behemoth-class collisions). The paladins
  ride the F tokens per the Surya convention
  (Tyr F25, Enki F13, Ki F10); the four
  no-rank rows (Fjalar, Skirnir, the Norns,
  the Valkyries) print no rank line and emit
  the n/a divine rank - the cross-pin
  rank-code collision with the nhw wizard 4.
  HONEST BOUNDARIES: the Thor bare 4 AC
  (L&L -4), the Hel +38 garble 8, the Aegir
  and Freya ACs by print, the Thrym 300
  occluded cell, the half-foot garbles )4
  and % reading 6 1/2 and 5 1/2 (Odin, Hel,
  Tyr, the Valkyries, Enlil), the Hugin 1/48
  and VI/815 glyphs, the Frey II pipe, the
  Fossergrim by-weapon print against its
  DmgFixed 1 and the Nin-hursag 2-20 against
  its 0 (pin-internal, n/a, with the
  27-vs-28 and 11-vs-10 flags), the Modi
  2 (or 4) and 25 or 50 (the first non-dice
  damage), the Thor 2(3) glove, the Frigga
  As-per-shape 0, the Jormungandr See-below
  move and 25,000-mile size (MR 99 vs the
  L&L 95; the L&L 1 ~ 7 attacks reading),
  the Garm 26,200 vs the L&L 26,000, the
  goats X/+ merged glyph 14,100, the literal
  99s (the Fjalar and Skirnir hit points,
  the Fenris and Jormungandr magic
  resistances), the Loki Pandemonium-or-
  Gladsheim alt, the Enlil 127/36" garble 12
  and D:23 CH:24 cells, the Utu 32 -> 3/2,
  the Ki 15/36//36 triple slash, the
  Fossergrim 9/ /36 double slash, the Inanna
  pipe I (L&L II) and warriors-and-lovers
  odd line, the Enki 10th-level bard (L&L
  13th), the Utu 15th in-each MU pair, the
  uniform -2 Sumerian AC; worshippers,
  symbol, areaOfControl n/a all. Spec
  tools/spec_r886.json, md5
  38babbb3c8e39637fb3b1ed0122fa232 (92,746
  bytes); the canvas spec-r886 gated
  byte-exact; rverify 144 mutants 0 missed;
  the land verified byte-exact against the
  fresh-tarball rebuild (1333 defs, dpz.h,
  audit, census, seed, regtest, spec
  identical; engine idempotent applied 48 /
  already 48). NEXT: the per-book
  normalization rounds (MM1 408, MM2 332, FF
  185, OA 47, WSG+MOP 23). WAIT FOR GO.

### Current state (post-R886, at the increment)

- HEAD 69d4b93 ("R886: The DDG lua
  promotion, batch seven (census 809)"),
  battery census 809 audit lines,
  registry floor 1333 (the 995 pre-DDG
  floor plus the 338 promoted DDG defs -
  batches one to seven, 55 + 68 + 60 + 31 +
  33 + 49 + 42; the 995 sparse defs untouched).
- Gap reports: mm2 37/0 closed; ddg 24/0
  closed - THE D&DG WALK COMPLETE
  (R849-R878). The R596-era standing
  states (UA 102/0, MotP 90/0, DMG 81/0,
  PHB 49/0, DSG 155/0, WSG 186/0) hold
  as recorded; re-verify at HEAD before
  scoping.
- Round shape since R846: the spec-driven splice (tools/
  spec_rNNN.json -> splice_engine.py -> rverify.py), prefix per
  round (dpz for R886; prefix freedom stays a
  FULL-REPO scan per the R856 dgh catch).
- THE DDG LUA PROMOTION IS COMPLETE - all
  338 DDG rows landed full-field (the
  maintenance arc after it, not before -
  Curtiss's call 2026-10-27). Landed:
  batch one (R880, 55 defs, dgb/dgc/dgd/dge),
  batch two (R881, 68 defs, dgf/dgg/
  cth/egp - Central American 14, Chinese
  18, Cthulhu 15, Egyptian 21; Phoenix
  seated as "Phoenix (Egyptian)"), batch
  three (R882, 60 defs, dpu - Finnish 20,
  Greek 40), batch four (R883, 31 defs,
  dpw - Indian 18, Japanese 13; Marut
  seated as "Marut (Indian)" per the
  Phoenix rename), batch five (R884,
  33 defs, dpx - Melnibonean 33, Elric
  through Yyrkoon), batch six (R885,
  49 defs, dpy - Nehwon 29, Nonhumans'
  Deities 20; Behemoth seated as
  "Behemoth (Nehwon)" and Lolth as
  "Lolth (Nonhumans' Deities)" per the
  Phoenix rename) and batch seven (R886,
  42 defs, dpz - Norse 35, Sumerian 7; no
  renames, all 42 stems free), the floor
  1050 -> 1333, DDG 338. NEXT: the
  per-book normalization rounds (MM1 408,
  MM2 332, FF 185, OA 47, WSG+MOP 23) -
  NOT authorized until Curtiss calls
  them. WAIT FOR GO before preparing any
  round. The next round's spec seats the
  R886 record (prev_record) - the record
  is derived state (the seed and the
  commit carry it).
- THE DOC/VIBE V3 SNAPSHOT FILES GET BROUGHT UP
  TO DATE BY APPEND (2026-10-27, Curtiss's
  call - NO v4 files, no full-file rewrites;
  the topic CONTINUES on v3, no wipe): the
  R848-R886 increment (the new decisions and
  seams, the records R849-R886, the current
  state) is APPENDED to
  adnd1_knowledge_backup_v3.md AND
  adnd1_knowledge_seed_v3.md; the state
  amendment is APPENDED to
  adnd1_continuation_prompt_v3.md;
  adnd1_seed_backup_v3.md stays untouched
  (the repo seed at HEAD carries the growth -
  refresh it as a cp only at the actual wipe).
  Append the next increment at the next land if
  more rounds land first.
