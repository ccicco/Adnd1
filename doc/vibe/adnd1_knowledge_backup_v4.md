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
- **THE G1 MODULE ARC (opened 2026-11-01,
  post-R1026): G1 - Steading of the Hill
  Giant Chief (1978, TSR 9016, Gary Gygax)
  is AD&D 1st edition ALREADY - no OD&D-to-
  1e conversion needed (a Copilot list had
  mislabeled it; G scope is G1 ONLY for
  now). THE MAP FORMAT DECIDED (Curtiss):
  grid-based, a CUSTOM format file, one
  file per level - proposed shape: a
  header (site name, scale 10 feet per
  square, grid size), an ASCII grid block
  (one char per square: wall, floor,
  corridor, door, water, void), room
  records carrying the MODULE KEY NUMBERS
  as ids (the printed keys are the room
  ids, sub-areas like 10A their own), and
  first-class point records (doors with
  type, secret doors, stairs linking
  levels, watch posts); placement
  content/sites/g1/, loaded at startup
  data-at-load (the registry performance
  doctrine - zero runtime cost); the
  THE WALL-OFFSET-IN-TILES DOCTRINE
  (Curtiss, 2026-11-01, THE trace
  rule for the G1 grids): walls
  occupy tiles, not grid lines -
  three encoding modes, left
  offset, right offset, or center
  distributed; G1 uses CENTER
  DISTRIBUTION (a wall's edges sit
  in 2 tiles at once). THE UPPER
  LEVEL MEASURES 33 x 42 TILE
  CANVAS (the naive square count
  31 x 40; the center-distributed
  boundary walls consume a tile on
  each side - the format declares
  a walldist field and the grid
  block is the TILE CANVAS, with a
  squares field pinning the module
  square count for cross-check;
  the battery verifies boundary
  walls one tile beyond the square
  extent and interior wall straddle
  pairs symmetric; the loader
  collapses the center pair to one
  wall for world::Map). The earlier
  vision-model counts (25x20
  structure, 28x21 grid) are
  superseded by the trace. The
  engine 64x64 grid fits 33x42
  easily. OPEN: the dungeon-level
  natural caverns - proposed: their
  rock edges ride the same center
  distribution onto the nearest
  tile pair. THE MAP VOICES: the module map
  pages persist under extract/g1/ per the
  repo-as-persistence doctrine; the grids
  are ADJUDICATED from the raster in
  pixel-work passes (the DDG p131
  figures class), then battery-verified
  (room rects interior, every key covered,
  doors between floor and wall, the two
  levels' stairs reference each other).
  THE REST OF THE MODULE DATA (encounter
  keys, instance hit point lists, treasure,
  wandering tables) - format UNDECIDED,
  Curtiss will pick what works best before
  the arc commits to one; the grid room
  keys are the join point either way. NO
  PLAYTEST yet - the arc is about
  processing the module maps and data.
- **THE G1 TILE-METADATA DOCTRINE (draft
  2026-11-01, discussion state): a wall
  tile that also has a door carries
  REFERENCES, not properties - the
  heavy metadata lives on a DOOR
  ENTITY the tile points to (one
  door, one state, the center-straddle
  pair stays in sync; per-tile door
  state is FORBIDDEN). Tile level:
  class wall, worient (the wall line
  N-S/E-W), wmember (west/east or
  north/south of the line), wpair
  (the straddle partner - redundant
  by design, battery checks derivation
  vs declaration), door id, dhinge,
  and DCOV lo hi - the COVERAGE
  EXTENT: the feet of the door's
  run this tile holds. COVERAGE
  DOCTRINE (Curtiss, 2026-11-01): a
  14-foot door under center
  distribution can occupy all or
  parts of THREE squares (partial,
  full, partial - tile count is
  PLACEMENT x DISTRIBUTION, not a
  door property); tiles carry
  coverage extents, never whole-
  tile segment assumptions - the
  battery derives expected per-
  tile coverage from width_ft +
  placement + walldist and must
  match every dcov (sums to
  width_ft, contiguous, no gaps
  or overlaps); the door entity
  keeps width_ft (the printed
  ink) and dcenter (the traced
  placement); the same coverage
  principle generalizes to wall
  end-caps that do not terminate
  on tile boundaries; the canvas
  derives from traced extents of
  everything (rooms, walls, doors
  with partial coverage). Door entity: kind (single/
  double/secret/gate/barred),
  material, thick_ft, width_ft,
  height_ft, opens (G1 ground level:
  normal_die - a normal die score
  required, the printed giant-door
  rule), stays_open (the printed
  rule: doors stay open if left that
  way), lock, secret (the 10A door:
  kind secret, concealed behind a
  manticore hide), state, connects
  (the two areas either side,
  battery-checked against room rects).
  Ground-level door prints: iron-bound
  log, 1 foot thick, singles about 7
  wide 6 high, the great entrance
  double doors. Load semantics: a
  wall-with-door tile is blocked while
  closed; opening makes BOTH straddle
  tiles one threshold; multi-tile
  doors open as one unit; secret doors
  need discovery before their tiles
  reveal the door (the engine
  SecretDoor struct slots in).
- **THE G1 TWO-LAYER GEOMETRY DOCTRINE
  (Curtiss, 2026-11-01): two-color maps
  make squares look simpler than they
  are - ALL complexities must be
  accounted, especially object
  manipulation, collision detection
  and ACCURATE DISTANCES. FOOT-SPACE
  IS THE SOURCE OF TRUTH: every wall,
  door and object carries continuous
  foot coordinates and extents (walls
  as segments with printed thickness -
  outer 3 feet, inner 2, doors 1 thick
  6 high; ceilings 16-32 feet, rafters,
  the watch tower; Z/HEIGHT joins the
  schema - a man-sized party passes a
  6-foot door, a hill giant does not);
  OBJECTS are first-class entities with
  geometry, blocking and properties
  (the fire pit, the ballista with its
  printed 30" range fires 1/round 2-18
  vs man-sized, the alarm hoop, the
  whip, chests as containers). The
  trace records PLACEMENT in feet;
  THICKNESS AND HEIGHT come from the
  key text, not the ink (the map is
  the placement voice, the text the
  dimension voice). TILES ARE DERIVED
  SUMMARIES - the 64x64 grid stays as
  the broad-phase fast index
  (pathfinding, occupancy, area
  lookup); collision and distance work
  in foot-space against the entities
  (narrow phase, exact extents - the
  14-foot door spans 2+10+2 feet by
  construction). BATTERY: every
  blocking entity intersects exactly
  the tiles its extent claims;
  walkable fractions consistent;
  wall thicknesses match the printed
  class 3/2/1; room ceilings pinned;
  computed distances reconcile with
  the module's printed measures where
  it gives them. The grid is DERIVED
  truth; the continuous layer is what
  the trace produces.
- **THE G1 TILESET DOCTRINE (Curtiss,
  2026-11-01): after the map and all
  its tiles are first processed, a NEW
  TILESET is GENERATED - and its
  generation REQUIRES measurement
  accuracy. THE CHAIN: trace ->
  foot-space geometry -> derived
  tiles -> generated tileset; the
  tileset inherits the accuracy of
  the layers below it (true wall
  thicknesses render true at 3 feet
  against a 10-foot square; doors
  read single vs double; the fire pit
  occupies its actual footprint; a
  2-foot trace error bakes into every
  render). The tileset is also the
  PERCEPTUAL CHECK: the first
  artifact where a human can verify
  the whole adjudication at once -
  the rendered steading's proportions
  must match the print (the battery
  checks geometry; the tileset checks
  perception). GENERATED MEANS NEVER
  HAND-EDITED: the tileset is a build
  artifact pinned to the geometry
  layer like the registry defs are
  pinned to the pin headers; every
  correction goes into the geometry
  and the tileset REGENERATES, or the
  two drift apart. THE PRIMITIVE/
  COMPOSITE LAYER (Curtiss,
  2026-11-01): final tiles COMPOSE
  from PRIMITIVE TILES - primitives
  are the authored layer (floor,
  wall, door, water - each NEUTRAL,
  NON-OFFSET, a wall centered in its
  primitive), authored once per
  feature class and material variant;
  COMPOSITION is the generated middle
  layer - per square the composer
  takes the geometry (feature list +
  coverage extents), layers and
  CLIPS primitives to the extents,
  then APPLIES THE OFFSET TRANSFORM
  to affected tiles (center: each
  straddle partner gets its half of
  the edge, clipped to its exact
  coverage - 2 feet renders as 2
  feet, partial-coverage squares
  compose floor + wall-clipped);
  BAKED final tiles are the output,
  composed OFFLINE at build time.
  WHY: the offset becomes a
  composition parameter, not baked
  art (one primitive set serves
  left/right/center and any future
  module); partial coverage stops
  being an art problem (derived from
  the battery-verified extents);
  consistency is structural (any
  visual inconsistency implies a
  geometry inconsistency - art
  variance eliminated). INVARIANT
  CHAIN: geometry + primitives are
  the only truth; composed tiles are
  a pure function of (primitives,
  geometry, offset rule); door
  primitives carry open/closed
  variants and composition bakes the
  door entity's INITIAL state (later
  state changes render at runtime
  over the baked base).
- **THE UNEQUAL-PIXEL DOCTRINE (Curtiss's
  question, 2026-11-01): under center
  distribution the pixel count on each
  side of a wall line can be UNEQUAL -
  expected and handled by role
  separation. (1) FIT, DON'T COUNT: the
  trace determines wall position by
  FITTING THE INK TO A CENTERLINE
  (center-of-mass / least-squares along
  the run), never by counting pixels per
  side - a 3+1 split is ink bleed, skew
  or line weight, not wall placement.
  (2) COVERAGE COMPUTES FROM GEOMETRY:
  per-tile extents derive from foot-space
  intersection, so unequal pixels cannot
  corrupt the model by construction; a
  wall genuinely drawn off the boundary
  records its ACTUAL placement and the
  coverage math (sum, contiguous, no
  gaps) stays exact - the 14-foot-door
  rule generalized. (3) ASYMMETRY IS A
  TRACE FLAG, NEVER A SILENT SNAP: the
  raster-verification pass compares the
  fitted geometry back against the ink
  within a DECLARED pixel tolerance;
  ink disagreeing with its own fitted
  line beyond tolerance is flagged for
  adjudication (skewed runs, double-
  printed lines, off-boundary artist
  placement) and adjudicated against
  the voices. (4) TOLERANCE IS DECLARED
  DATA per level (print quality, scan
  resolution and line weight vary
  between the two maps) so the battery
  knows what agreement means per map.
  The format below the trace never sees
  pixels - the voice is imperfect, the
  adjudication explicit, the data exact.
- **THE G1 WALL-WEIGHT MEASUREMENTS
  (2026-11-01, first pixel-work pass on
  the upper-level raster, pure-Python
  baseline-JPEG decoder - no image
  libraries in the sandbox; decoder +
  run/cluster analysis seed the trace
  tooling): SCALE ~20px per 10-foot
  square (confirmed twice - interior
  wall bands repeat every 79px = 4
  squares; the boundary span 618px
  = 31 squares x 20px, matching the
  Curtiss trace). TWO CLEAN CLUSTERS
  (nothing between): boundary walls
  9-11px (left x38-46 9px, right
  x656-664 9px, top y5-15 11px,
  bottom y688-697 10px), interior
  walls 3-4px vertical (mode 4) and
  3-5px horizontal (mode 4). THE INK
  IS PARTLY DIMENSIONALLY HONEST:
  at 2px/foot the interior mode 4px
  = 2.0 feet EXACTLY matching the
  printed "inner walls about 2 feet
  thick"; the boundary measures
  4.5-5.5 feet against the printed
  "logs of at least 3 feet" - the
  artist's bold outline, STYLIZED.
  DOCTRINE REFINEMENT: line weight
  is a CLASS signal everywhere
  (boundary vs interior cluster
  membership), a MEASUREMENT VOICE
  only where it agrees with the
  text - interior walls get 2 feet
  corroborated by both voices;
  boundary walls adjudicate to the
  text's 3 feet with the ink flagged
  stylized-bold (a trace flag, the
  asymmetric-ink class).
- **THE G1 RENDER-RESOLUTION DOCTRINE
  (Curtiss, 2026-11-01): the chosen
  resolution is 64x64 PIXELS PER
  TILE = 6.4 pixels per foot (=
  64/10 - every integer-foot
  printed dimension maps to an
  exact rational pixel count; 2
  feet = 12.8px, 3 feet = 19.2px,
  1 foot = 6.4px, 7 feet = 44.8px,
  14 feet = 89.6px - the double
  door spans 1.4 tiles, the
  partial-tile coverage rendered
  pixel-precise). THE 10x
  SUPERSAMPLE RULE: author and
  compose at 640x640 per tile
  where 1 foot = 64 SUBPIXELS
  exactly - every printed
  dimension an integer (2 feet =
  128, 3 = 192, 1 = 64, 7 = 448,
  14 = 896 subpx); the supersample
  IS foot-space x 64 so the
  continuous geometry layer and
  the raster grid are the same
  thing; battery checks run at
  integer subpixel level (no
  floating-point tolerance games);
  the ONLY rounding is the fixed
  deterministic x10 area-averaged
  downsample at the end. Center
  distribution gets a render
  identity: each straddle tile
  carries exactly half the wall's
  subpixel width (64 of 2 feet, 96
  of 3 feet) and the composed pair
  reconstructs the wall seam-free.
  TWO HARD RULES: (1) NO INK
  PIXEL EVER REACHES THE RENDERER -
  the source scan is 3.2x coarser
  than the target (20px/square vs
  64px/square) and that is fine by
  construction: ink informs
  geometry, geometry rasterizes,
  never upscale ink; (2)
  PRIMITIVES STAY RESOLUTION-
  INDEPENDENT - authored in
  foot-space, so the 64px target
  is a BUILD PARAMETER and any
  future resolution re-rasterizes
  without re-authoring.
- **THE GRID-REMOVAL DOCTRINE (Curtiss,
  2026-11-01): the graph-paper grid
  construct is REMOVED when the initial
  tiles are created - it is a
  REGISTRATION LAYER, not a content
  layer. CONFIRMED IN THE RASTER
  (2026-11-01): the grid IS present
  in the scan and separable by ink
  weight - autocorrelation finds a
  dominant 20px period (86 percent
  agreement; faint-ink columns at 64,
  83-84, 103-104, 122-124, 142-143 -
  clean ~19.7px spacing, the 20px-per-
  square scale); grid lines faint and
  periodic, walls heavier and
  structural - two layers, one scan.
  THE TRACE CONSUMES THE GRID (a gift
  - an internal scale reference
  printed on the ink): (1)
  REGISTRATION - every fitted wall
  centerline should land on a grid
  line within the declared tolerance
  (walls are drawn on the graph; a
  fitted centerline between grid
  lines is a trace flag); (2) SCALE
  PER REGION - the grid's local
  period verifies 20px/square
  regionally (period drift = anamorphic
  stretch or skew, flagged not
  snapped); (3) SQUARE INDEXING - key
  number positions reconcile against
  grid-line intersections. THEN
  REMOVED: grid lines never enter the
  geometry layer, no primitive carries
  graph-paper art, no composed tile
  bakes it in - the empty squares
  become genuinely empty floor. IF
  the engine ever displays a grid in
  play it is a RUNTIME DRAW OVERLAY
  (a rendering pass parameter), never
  pixels baked into the tileset - the
  tileset contains the steading, not
  the paper it was printed on.
  THE GRID IS A TOGGLEABLE FUNCTION,
  SEPARATE FROM THE MAP TILES (Curtiss,
  2026-11-01): a separate draw pass
  generated from SITE METADATA, not
  from tiles and not from ink - the
  overlay derives from the site
  header (scale, the square lattice
  origin, the squares field); because
  the tile canvas and the square
  lattice do not coincide (the 33x42
  canvas carries boundary walls
  outside the 31x40 squares), the
  overlay anchors to the SQUARE
  LATTICE ORIGIN computed from the
  wall-offset mode and boundary
  placement, so the grid lands on the
  module's 10-foot squares, not on
  the 64px tile boundaries. The
  toggle state is runtime UI state -
  never persisted into site data,
  never a separate tileset variant
  (one tileset, one grid overlay, one
  boolean). Battery-verified the same
  way as everything generated: grid
  lines must coincide with room-rect
  boundaries and the square index -
  an overlay disagreement with the
  room rects is a geometry bug, not a
  drawing bug. Being a vector pass at
  draw time, the overlay can render
  at any visual weight (faint
  quarter-squares for fine movement,
  10-foot squares only, or both).
- **THE TERRAIN-TRANSITION DOCTRINE
  (2026-11-01, layer 1 - floor/terrain):
  TRANSITIONS ARE NOT A TILE CATEGORY -
  they are squares whose coverage has
  2+ terrain classes, handled by the
  SAME coverage composition as
  partial wall edges (a 6-foot floor +
  4-foot yard square composes by
  clipping each primitive to its
  extent; no floor-to-yard tile type
  is ever authored) - the primitive
  set stays LINEAR in terrain
  classes, not quadratic in pairs
  (the N-squared combinatorial
  blowup of hand-authored transition
  tiles never happens). The
  supersample makes material
  boundaries exact (a water edge
  3.4 feet into a square = 217.6
  subpixels; the sum/contiguous/
  no-gap rule applies to terrain
  extents - a square's coverage sums
  to exactly 100 percent). WHERE
  AUTHORED HELP IS NEEDED: organic
  blends - primitives carry EDGE
  RAMPS (about 1 foot of dithered
  blending at primitive borders) so
  abutting primitives interlock into
  natural boundaries; still linear,
  still resolution-independent,
  battery-checkable (adjacent ramp
  zones complementary - same colors,
  seed-offset noise). THE STRESS
  CASE: the dungeon-level caverns
  (rock-to-floor boundaries - under
  this doctrine just another coverage
  feature with organic extents traced
  from the rock edges, primitive edge
  ramps and clipped coverage, no
  special machinery). Layer 1 stays
  simple: transitions live only in
  boundary squares, and even there
  they are derived, not authored.
- **THE PRIMITIVE-TRANSPARENCY
  DOCTRINE (Curtiss, 2026-11-01):
  every non-construct pixel in a
  primitive is ALPHA-TRANSPARENT -
  never a background color, never
  paper, never a guessed floor tone.
  Three load-bearing reasons:
  (1) LAYERING - the composer stacks
  terrain -> walls -> objects
  bottom-up with a standard "over"
  composite; opaque flanks would
  occlude the real terrain beneath,
  and since one wall primitive
  composes over stone floor, dirt
  yard and cavern rock, no baked
  background can be correct -
  transparency is what lets one
  primitive serve every terrain (the
  transition-doctrine linearity
  rule). (2) ALPHA IS THE COVERAGE
  SEMANTICS - at the 10x
  supersample, "the wall covers
  subpixels 576-704" and "the
  primitive's alpha is 1.0 there, 0.0
  elsewhere" are the SAME statement;
  coverage extents, clipping and
  alpha compositing become one
  mechanism, and a partially covered
  edge subpixel is simply alpha 0.6
  which downsamples into exactly the
  anti-aliased edge pixel - the AA
  gradient is not painted, it is the
  downsampled average of exact
  alpha. (3) INVARIANT PURITY - an
  opaque background would smuggle
  the paper back in (the grid-removal
  doctrine); transparency makes
  "the tileset contains the steading,
  not the paper" enforced at the
  PIXEL level, not by convention.
  DETAILS: straight (non-premultiplied)
  alpha, deterministic bottom-up
  compositing order by layer class,
  battery-checkable because each
  layer's extents are known. A
  CONSTRUCT'S ALPHA EDGE IS ITS
  MEASUREMENT: the battery verifies a
  primitive's printed dimension
  directly from its alpha mask (a
  2-foot wall primitive's opaque core
  spans exactly 128 subpixels plus
  edge ramp) - primitive QA needs no
  eyeballing, the alpha mask IS the
  claim.
- **THE OCCLUSION DOCTRINE (Curtiss,
  2026-11-01): part of the floor tile
  DOES get occluded by the wall in
  rendering - and that occlusion is a
  RENDERING fact, not a DATA fact.
  (1) THE FLOOR EXISTS UNDER THE WALL
  AT FULL COVERAGE: the terrain layer
  records the square's floor
  completely - the wall does not cut
  the floor data, it draws over it;
  collision and walkability come from
  the GEOMETRY layer, never from
  visible pixels; and the door case
  makes it non-negotiable - when a
  door opens the floor beneath must
  be revealed (a trimmed floor would
  expose a hole instead of a
  threshold), so the floor composes
  full-coverage beneath everything
  and opening a door is a different
  composite of the same complete
  layers, never an art patch-up.
  (2) THE TILESET STAYS LAYERED, NOT
  FLATTENED: since runtime state
  changes must reveal what is
  underneath, the baked output bakes
  PER LAYER - terrain, then
  constructs (walls/doors/objects) -
  and the engine composites at draw
  time (the toggleable grid is a
  layer above; door open/closed
  variants are construct-layer
  states; the runtime door swap is
  re-compositing the region with the
  door primitive's open variant).
  THE COMPOSITE ORDER, PINNED:
  terrain (full coverage, every
  square) -> constructs (alpha
  "over") -> runtime overlays (grid,
  state changes). INVARIANT:
  occlusion is draw order; data is
  always complete underneath.
- **THE G1 FLOOR FACTS (from the
  prose, 2026-11-01): GROUND LEVEL -
  one blanket statement, "All inside
  floors are of stone" (the Upper
  Works paragraph) - ONE terrain
  class covers every interior square
  of the steading. DUNGEON LEVEL - a
  specific variant: room 1 the
  Marshalling Area "a floor of
  blackish stone, much worn by the
  tread of countless feet" - the
  dungeon's worked areas are a
  distinct floor class (blackish,
  worn), not just stone again. TWO
  QUALIFICATIONS: (1) FLOOR COVERINGS
  ARE NOT TERRAIN - "hides on the
  floors", "rugs, hides, and skins",
  "straw and similar litter", "moldy
  straw strewn on the floor" are
  per-room furnishings from the
  encounter keys - OBJECT/decor
  overlays composited over the
  terrain, not floor primitives (the
  terrain primitive set stays tiny;
  room variety comes from the object
  layer - the linear-vs-combinatorial
  split). (2) WHERE THE PROSE IS
  SILENT THE DATA SAYS SO: the open
  compound (22) and outside-the-walls
  areas print no floor type (earth
  presumably, but PRESUMABLY IS NOT
  INK) - those squares record
  terrain-unspecified with a trace
  flag for Curtiss's adjudication;
  same for natural cavern floors
  (stalagmites and fungus ecology
  printed, floor material not) -
  likely adjudicated cavern rock but
  a flag-plus-decision, never a
  default. LAYER-1 PRIMITIVE SET SO
  FAR: interior stone (ground),
  blackish worn stone (dungeon),
  cavern rock (pending), outdoor/yard
  (pending).
- **THE PRIMITIVE-GENERATION PROMPT
  TEMPLATE (2026-11-01): AI-generated
  primitive art (Copilot) rides a
  FIXED template - subject block
  swappable per primitive, the rest
  constant: (a) 640x640 PNG = the 10x
  supersample master (the standard
  downsample produces the 64px tile);
  (b) PHYSICAL SCALE pinned in the
  prompt (the tile is 10x10 feet, 1
  foot = 64 px; flagstones 2-3 feet
  across; nothing smaller than a
  finger's width - prevents wrong-
  scale texture and detail that
  vanishes at 64px); (c) SEAMLESSNESS
  critical - edges wrap (left onto
  right, top onto bottom), joints and
  cracks flow across borders, no
  vignette/center emphasis/lighting
  gradient, uniform diffuse light;
  (d) EXCLUDES: grid lines, graph
  paper, borders, walls, objects,
  floor coverings, text, lighting
  effects; (e) full-coverage opaque
  output for terrain (construct =
  whole tile). SEAMS ARE VERIFIED
  PROGRAMMATICALLY, NEVER BY EYE:
  tile 2x2 and diff opposing edge
  rows/columns (and the AA edge rows
  after downsample) - generators claim
  seamless and deliver almost-
  seamless; the edge diff makes it
  pass/fail (the primitive-level
  version of "the alpha mask is the
  claim"). If the generator supports
  it, request wraparound/periodic
  texture in its own terms as well.
  The constant sections keep the
  primitive family visually coherent.
  THE MASTER-SIZE RULING (2026-11-01,
  vs Copilot's 512-then-downsample
  suggestion): masters are 640x640,
  FULL STOP, for every primitive in
  the composited supersample - 512
  breaks the integer foot-grid
  (1 foot = 51.2 subpixels; every
  construct dimension lands
  off-grid and the alpha-mask battery
  check becomes floating-point
  tolerance matching, which the
  resolution doctrine rules out) and
  would split the primitive family
  into two foot-scales (terrain at
  512, constructs at 640 - compositing
  then forces a resample that breaks
  the determinism invariant). THE
  ONLY DOWNSAMPLE IN EXISTENCE IS THE
  PIPELINE'S OWN: performed on the
  master, never received pre-
  downscaled (a generator-applied
  filter forfeits reproducibility and
  the exact AA the battery trusts).
  FALLBACK ONLY: if a generator
  genuinely cannot emit 640, 512 is
  admissible ONLY for full-coverage
  organic terrain (no mask claims,
  clean 8x integer downsample), with
  the primitive header recording the
  master's true scale - a fallback,
  not the plan. The stone-floor prompt
  stands UNCHANGED (640x640, full
  coverage, no downsample mention -
  correct as written).
- **THE SEAMLOCK DOCTRINE (2026-11-01,
  vs the first Copilot tile - vision
  gate result: content/scale PASS
  (top-down stone, flagstones 2-3
  feet, medium-low frequency),
  exclusions PASS (no grid, borders,
  objects, text, vignette), seams
  FAIL (discontinuities all four
  borders) - the generator was told
  "seamless, critical" and delivered
  almost-seamless, the exact failure
  mode the gate exists to catch).
  Copilot's counter-advice is RIGHT
  and more doctrine-compliant: exact
  edge continuity is a TEXTURE-
  PROCESSING workflow (offset by 50
  percent, repair the center seam,
  wrap, verify tiled), not a
  generative repaint - tileability
  becomes MATHEMATICAL rather than
  generative (construct the
  invariant, don't ask a voice to be
  perfect). THE SEAMLOCK PASS, between
  generation and acceptance: (1)
  OFFSET BY HALF - P'[x,y] = P[(x+320)
  %640,(y+320)%640] - the outer
  borders become the original's
  interior, wrap continuity GUARANTEED
  BY CONSTRUCTION (the seam relocates
  from the fatal border to a harmless
  interior cross); (2) REPAIR THE
  CENTER CROSS ONLY - one hard rule:
  nothing may modify the outer border
  after the offset (GIMP Layer-
  Transform-Offset wrap-around, then
  content-aware/clone repair on the
  cross; hand repair is fully
  doctrine-compatible because it
  happens BEFORE the battery - it
  beats procedural cross-fades on
  cracked stone, the high-frequency
  content where blends smear); (3)
  WRAP-VERIFY GATE - offset wrap-diff
  exactly 0 on all four borders, 2x2
  tile check, then the pipeline's own
  x10 downsample; (4) INTAKE ITEM: the
  seamlock exists as REPO TOOLING too
  (offset + wrap-verify are trivial
  pure-stdlib code, the jdec pattern)
  so the gate never depends on image-
  editor discipline. NOTE: uploaded
  tiles arrive as 155-byte filesystem
  stubs - bytes are NOT in the
  filesystem; the vision gate
  (analyze_image) is the only
  inspection route for uploads, so
  the PIXEL-precise seam gate runs in
  the repo when the real file lands
  there at the intake. STATUS: the
  SEAMLOCKED MASTER (uploaded
  2026-11-02, copilot_image_1793652873297)
  PASSED THE VISION GATE on all
  checks - all four borders wrap
  exactly, no center-cross repair
  artifact, content unchanged, no
  exclusions; accepted as the
  STONE-FLOOR PRIMITIVE CANDIDATE,
  the first member of the primitive
  family, pending the repo pixel gate
  (wrap-diff 0, AA row check) at the
  intake. The generate -> gate -> fail
  -> seamlock -> gate-pass loop is
  PROVEN.
- **THE REPO LOCATION (user
  correction, 2026-11-02): the local
  repo lives at ~/Adnd1 IN TERMUX -
  not a Windows path (an earlier
  Windows-style path in conversation
  memory was wrong; Knowledge carried
  no path, nothing scrubbed). All
  local ritual commands (preflight,
  splice, battery, commits) run from
  ~/Adnd1; uploads to Vibe arrive
  via ~/storage/downloads (termux-
  setup-storage). PUSHED 2026-11-02:
  commit 879b4734 on main (remote
  github.com:ccicco/Adnd1.git,
  c9c35759..879b4734) - the G1 site
  tree: primitives/stone_floor_master
  .png (3,539,470 bytes - real bytes
  confirmed, the stub check passed)
  and tiles/ with .gitkeep - the
  first physical artifact of the G1
  rendering arc in the repo. GAP:
  the commit message says "+ manifest"
  but stone_floor.json did NOT land
  (the commit carries only 2 files) -
  CLOSED same day: commit 75821d85
  pushed (879b4734..75821d85) with
  the stone_floor.json manifest
  (companion note referencing
  879b4734, 1 file 11 insertions) -
  provenance COMPLETE. The stone-
  floor primitive is fully landed:
  seamlocked master + manifest +
  empty tiles/ output root, the
  first member of the G1 primitive
  family in the repo.
- **THE EXTERIOR-MARGIN DOCTRINE
  (Curtiss, 2026-11-02): the map
  boundaries INCREASE beyond the
  building and account for terrain
  outside - and this is the first
  AUTHORED-NOT-TRACED content (the
  printed map ends at the structure;
  the module never drew the ground
  beyond the walls, the engine needs
  it). THE RULES: (1) the canvas
  grows by a build-parameter margin
  beyond the boundary-wall tiles
  (trace canvas + 2x margin per
  dimension); margin is a BUILD
  PARAMETER, not baked geometry -
  the same traced site composes into
  a 10-square clearing or a 50-square
  wilderness approach without
  re-tracing (the resolution-
  independence rule applied to map
  extent); (2) THE STRADDLE MATH IS
  UNTOUCHED - boundary walls keep
  their center-distributed tiles as
  traced, margin tiles append
  outside; wall-offset modes,
  boundary checks, and the loader
  collapse rule operate on the traced
  region only; (3) THE EXTERIOR
  TERRAIN IS AUTHORED CONTENT with
  the outdoor/yard class split:
  inside the stockade (open compound,
  spaces between stockade and hall -
  presumably dirt/yard, PRESUMABLY IS
  NOT INK, flagged for adjudication)
  and beyond the stockade (damp
  hillside ground - authored,
  flagged); both margins record
  terrain-unspecified until Curtiss
  adjudicates, then the margin
  composes the chosen primitive;
  (4) THE BATTERY DRAWS THE LINE: the
  traced extent matches INK exactly
  (walls on grid, doors between floor
  and wall, coverage sums), the
  margin matches the ADJUDICATION
  RECORD exactly (uniform class,
  correct primitive, no ink claims
  leaking) - two regions, two
  authorities, boundary = the outer
  face of the traced canvas,
  itself checkable (no wall tile
  renders margin terrain beneath it,
  no margin tile carries a wall).
  OPEN FOR THE INTAKE: margin size
  (uniform vs per-side - the gate
  approach may warrant more room than
  the sides; suggested start uniform,
  per-side as refinement) and the
  outdoor terrain-class adjudication.
- **THE EXTERIOR-DOOR CLOSURE
  (Curtiss, 2026-11-02): the steading
  has doors that lead outside - THEY
  MUST NOT LEAD TO NOTHING. A battery
  rule, not a rendering one (without
  it the front door opens onto void -
  the hole-instead-of-threshold
  failure in a different coat). (1)
  EVERY BOUNDARY-WALL DOOR'S OUTSIDE-
  FACING FOOTPRINT COMPOSES MARGIN
  TERRAIN - not void, not wall, not
  unspecified-after-adjudication; the
  door's opening extent projects onto
  matching walkable margin EDGE-FOR-
  EDGE (the margin outside a door is
  the other side of the threshold -
  the battery checks alignment of the
  door's opening extent against the
  margin's walkable extent, not just
  tile adjacency). (2) THE OCCLUSION
  DOCTRINE COVERS THE REVEAL: closed
  door = wall+door over full-coverage
  terrain beneath; opening re-
  composites with the open variant
  and both sides read correctly
  (inside floor, outside margin
  ground) because the data was
  complete on both sides all along -
  the margin supplies the previously
  absent outside half. (3) THE
  BATTERY'S EXTERIOR-DOOR CHECK, for
  every door whose footprint touches
  the traced canvas's outer face: (a)
  opening extent non-zero and matches
  ink; (b) immediately-outside extent
  is margin terrain of the adjudicated
  class, walkable; (c) door opening
  width equals the margin walkable
  width it abuts (no 14-foot door
  breathing onto 10-foot walkable
  ground); (d) THE REVERSE - no margin
  walkable extent abuts the outer wall
  EXCEPT through a traced door or gate
  opening (no terrain leaking through
  solid log). Same check for the
  STOCKADE GATES (inside face
  compound, outside face hillside
  margin, opening extents aligned).
  Clause (d) is the two-region/
  two-authorities principle as a
  TRANSITION AUDIT: every walkable
  crossing of the trace/margin
  boundary must be a traced opening,
  and every traced opening must land
  on walkable ground on both sides -
  doors lead somewhere, by proof
  rather than by hope.
  CORRECTION VIA THE PARTIAL-ROAD
  PRECEDENT (Curtiss, 2026-11-02):
  the printed map already has
  exterior ink - THE PARTIAL ROAD ON
  THE SOUTHEAST PORTION OF THE MAP -
  so the ink/authored boundary is
  NOT the building: EXTERIOR INK IS
  TRACED EXACTLY LIKE EVERYTHING
  ELSE (the road's edges get fitted
  centerlines, coverage extents,
  battery verification; it is a
  TERRAIN feature - its own primitive
  class - not a wall, composing as
  terrain, drawn width whatever the
  ink says). THE ROAD ANCHORS ITS OWN
  CONTINUATION: being partial
  (running off the trace extent
  southeast), the margin must honor
  it - the margin terrain continues
  the road EDGE-FOR-EDGE where it
  exits the canvas (the same
  transition-audit clause as the
  doors: a traced feature crossing
  the boundary must continue in the
  margin, aligned at the crossing, or
  terminate at a traced endpoint
  BEFORE the boundary - never just
  truncate at the paper's edge); the
  road's path beyond the trace is
  AUTHORED-BUT-ANCHORED (like a
  coastline continued from surveyed
  points). IT CONSTRAINS THE
  ADJUDICATION: a road implies what
  it runs through (a damp dirt track
  through the moor); it does not
  DECIDE the outdoor class
  (presumably is still not ink), but
  whatever the margin class is, the
  road sits on top of it and the
  class must be one a road plausibly
  crosses. THE RULE, SHARPENED: the
  trace covers EVERYTHING DRAWN,
  wherever drawn (building, stockade,
  compound, road); the margin covers
  everything else, honoring every
  crossing (roads, gates, doors) with
  edge-for-edge alignment at the
  boundary. Authored terrain is not
  just flat fill - it is a
  continuation of drawn features.
  ADJUDICATION 1 (Curtiss, 2026-11-02):
  THE OUTSIDE IS YARD - one outdoor
  terrain class covering the open
  compound inside the stockade AND
  the margin beyond (the
  terrain-unspecified flags resolve
  to the yard primitive; satisfies
  the road constraint trivially - a
  dirt track through a trampled yard
  is exactly what a road through
  this place looks like). The yard
  primitive joins the generation
  queue (subject block: trampled
  earthen yard - packed dirt/mud,
  damp, puddle-stained, churned by
  giant and beast traffic, sparse
  trampled grass or none, medium-low
  frequency, seamless wraparound).
  STILL OPEN: margin size (uniform vs
  per-side) and the cavern
  convention. YARD PRIMITIVE
  (2026-11-03): PASSED THE VISION
  GATE NATIVELY - puddle stains,
  ruts and churned patterns wrap
  exactly across all four borders,
  no repair artifacts, content and
  exclusions clean - the FIRST
  primitive to wrap correctly straight
  out of the generator (no seamlock
  repair needed; manifest records
  state NATIVE, not seamlocked) - but
  the repo pixel gate remains the
  authority (vision_gate pass,
  pixel_gate pending). Lands as
  yard_master.png + yard.json
  (terrain_class yard, level
  exterior) in primitives/. LANDED
  2026-11-02: commit 9356e96f pushed
  (75821d85..9356e96f) - master +
  manifest in ONE commit (2,949,750
  bytes real PNG confirmed) - the
  primitive family now holds TWO
  landed members: stone_floor
  (879b4734 + manifest 75821d85) and
  yard (9356e96f), both pixel-gate
  pending. Local source path for
  uploads: ~/storage/shared/Pictures/
  (not ~/storage/downloads).
  ADJUDICATIONS 2 AND 3 (Curtiss,
  2026-11-02): (2) MARGIN SIZE =
  UNIFORM, 10 SQUARES PER SIDE - the
  composed world map canvas is the
  trace canvas + 20 in each dimension
  (upper level: 33x42 + 20 = 53x62
  composed canvas); the road's
  continuation has 10 squares of
  authored yard before the canvas
  edge; margin stays a build
  parameter so a future composition
  can change it without re-tracing.
  (3) CAVERN CONVENTION RATIFIED =
  CENTER-DISTRIBUTION ONTO TILE PAIRS
  - natural cavern rock edges trace
  exactly as drawn, then their edges
  straddle the nearest tile pair like
  hewn walls do; ONE encoding mode
  covers the whole dungeon level
  (upper and lower), the battery
  reuses the same symmetric-straddle
  checks, and there is NO second
  geometry system to build or verify.
  THE INTAKE DECISION LIST IS NOW
  EMPTY - remaining intake items are
  construction: seamlock tooling +
  pixel gate (closes both pending
  pixel_gate fields), then the trace,
  the format, and the battery.
  SEAMLOCK TOOLING BUILT AND PROVEN
  (2026-11-03): tools/seamlock.py -
  pure stdlib (zlib + struct PNG I/O,
  the jdec pattern), THREE MODES:
  verify (header check 640x640 8-bit
  RGB/RGBA non-interlaced; coverage
  check alpha 255; SEAM GATE = the
  wrap is ONE boundary among w/h
  boundaries, judged against the
  texture's OWN population of interior
  boundary energies - PASS requires
  wrap energy <= p99 of interior
  boundary energies on both axes AND
  ZERO hard seam pixels (wrap diff >
  max(8, p999 interior pixel diff x
  4))); bake (gate, then the SINGLE
  x10 fixed-area-average downsample to
  64x64, then the gate RE-RUNS ON THE
  TILE so the AA rows are verified);
  tile2x2 (eyeball aid, not a gate).
  PROVEN ON SYNTHETICS: a perfectly
  periodic master PASSES, a gradient
  master FAILS (1280 hard pixels
  caught), a busy non-periodic master
  FAILS (wrap 130 vs interior p99 17
  - seams hiding in busy textures are
  caught), PNG decode roundtrips ALL
  FIVE filter types with 0
  mismatches (adaptive filtering is
  what real generators emit), RGBA
  opaque passes coverage, wrong-size
  rejected. TWO GATE BUGS the
  synthetic proof caught and fixed:
  (1) p99 baseline was cumulative
  (hard check never fired); (2) the
  wrap was compared to the GLOBAL
  MEAN of interior adjacencies (a
  single column legitimately deviates
  from a global mean even in perfect
  textures - the sound comparison is
  the wrap vs the DISTRIBUTION of
  interior boundary energies).
  NEXT: run verify + bake on both
  landed masters in Termux, flip both
  manifests' pixel_gate, commit tool
  + tiles + manifest updates.
  THE 1254 RULING (2026-11-03, the
  tool's first real catch): the
  header check revealed BOTH landed
  masters are 1254x1254, NOT 640x640
  - Copilot emits a FIXED size and
  cannot honor the prompt's 640x640.
  THE MASTER-SIZE FALLBACK CLAUSE IS
  INVOKED: full-coverage organic
  terrain masters are admissible at
  the generator's true size (both
  primitives qualify); the manifests
  record the true scale (master size
  1254, px_per_foot 125.4); exact
  foot-grid geometry remains a
  CONSTRUCT-primitive requirement
  only. THE ONE-ROUND INVARIANT
  PRESERVED: bake is now a SINGLE
  exact area-average master -> 64x64
  with rational boundaries (integer
  arithmetic in 64ths of a pixel;
  the single rounding point is the
  final half-up per channel) - NO
  intermediate resample to 640 ever
  exists. GATE REFINEMENT (third
  synthetic-proven fix): the energy
  threshold moved from p99 to 2x p99
  (a perfect texture's wrap column
  lands in the interior tail ~1
  percent of the time by chance - the
  p99 threshold failed a perfectly
  periodic synthetic); the HARD-
  PIXEL check is the fine-seam catch
  (proven: a 1px bright column at the
  wrap only - invisible to any mean -
  FAILS with 1254 hard pixels). The
  640 path remains exact (constant
  image bakes to the constant). Tool
  v2 in the seamlock-tool canvas;
  re-proven on 1254 and 640
  synthetics, all five filter types.
  PIXEL GATE RESULTS (2026-11-02,
  tool v2 in Termux): BOTH MASTERS
  PASS - stone_floor wrap h=53.232
  vs p99 48.270, v=47.808 vs 52.650,
  zero hard pixels (the seamlock
  repair holds under exact
  arithmetic); yard wrap h=31.836 vs
  p99 26.726, v=30.834 vs 29.602,
  zero hard pixels (the native wrap
  is real). Baked 64x64 tiles gate
  clean too (AA rows included):
  stone tile h=13.531, yard tile
  h=15.578, both inside interior
  ranges. THE VISION GATE'S PASSES
  ARE CONFIRMED BY THE AUTHORITY
  GATE - the generate/gate/seamlock/
  bake loop is now fully closed-loop
  with proof at every stage. Both
  tiles baked into content/sites/g1/
  tiles/ (the tree is no longer
  empty); manifests updated to true
  scale 1254 / px_per_foot 125.4 and
  pixel_gate pass. NEXT: the intake
  round (trace, format, battery),
  with the remaining primitives
  (blackish stone, cavern rock, road)
  generating in parallel through the
  same loop. LANDED 2026-11-02:
  commit b6915511 pushed
  (9356e96f..b6915511) - 5 files:
  tools/seamlock.py v2,
  tiles/stone_floor.png +
  tiles/yard.png (the first BAKED
  tiles in the repo), both manifests
  at true scale (1254/125.4) with
  pixel_gate pass. COMMIT MAP of the
  rendering arc so far: 879b4734
  (stone floor master) -> 75821d85
  (stone floor manifest) -> 9356e96f
  (yard master + manifest) ->
  b6915511 (tool + tiles + truth
  updates). The foundation is
  COMPLETE: authored tree, two gated
  masters, two baked tiles, proven
  gate tooling, all decisions
  adjudicated.
- THE INTAKE OPENED 2026-11-03
  (doctrine order: the gate before
  the artifact). BUILT AND
  SYNTHETIC-PROVEN: tools/site_
  battery.py (pure stdlib) - the
  site-data battery, 11 checks:
  canvas==squares+2, walldist
  center, grid rectangular + char
  legend, boundary ring solid,
  interior wall straddle pairs (no
  floaters), doors between floor and
  wall AND in walls (straddle mate
  '+' across the wall line; ring
  gates exempt, their outside is
  the margin), exterior doors need
  the declared margin (the closure),
  roads never truncate at the ring,
  printed keys covered exactly by
  room ids, room rects inside the
  square extent + walkable, no void
  inside the square extent, margin
  terrain has a landed primitive.
  PROVEN: a valid synthetic site
  PASSES; 8 broken variants FAIL on
  exactly the right check (canvas
  mismatch, ring hole, lone wall,
  floating door, uncovered key, road
  dead-end, gate without margin,
  wall inside a room rect). THE
  SYNTHETIC PROOF CAUGHT A REAL
  GAP: a door placed on the FLOOR
  side of a wall satisfied between-
  floor-and-wall but is physically
  wrong - doors sit IN walls as
  straddle pairs; the mate check was
  added. GRID CHARS: '#' wall,
  '.' floor, ':' corridor, '+' door,
  '~' water, ' ' void, 'y' yard,
  '=' road; 0-based top-left; the
  margin NEVER appears in the grid
  block (the grid IS the traced
  canvas). ALSO PUBLISHED: the g1
  site.json format spec (the trace's
  target) - top level id/module/
  walldist/levels; per level id/
  canvas/squares/margin/keys/grid/
  rooms/points; margin uniform 10
  yard (upper level). OPEN AT TRACE
  TIME: point-record payloads (door
  types, secret doors, stair links,
  watch posts - battery v1 is
  structural), the geometry layer
  (subpixel coverage extents alongside
  the grid block), dungeon levels on
  the same center distribution. THE
  TRACE IS NEXT: pixel-work the
  upper level from extract/g1/ into
  site.json per the spec, run the
  battery until PASS. SCAFFOLD
  LANDED (2026-11-03, user-verified
  in Termux): content/sites/g1/
  site.json with the upper level -
  canvas 33x42, squares 31x40,
  walldist center, margin 10x yard,
  ring-only grid, empty keys/rooms/
  points. THE BATTERY REPORTS THE
  DESIGNED STARTING STATE: canvas
  geometry OK, ring solid, terrain
  grounding works (both landed
  primitives found), ONE FAIL - the
  void interior awaiting the trace
  (any other FAIL would mean the
  scaffold itself was wrong).
  NEXT: SKELETON PASS - upload the
  upper-level map raster (crop to
  the map ideal, full page OK) and
  adjudicate wall runs, gates and
  the stockade interior onto the
  31x40 grid, pass by pass (skeleton
  -> rooms -> points -> exterior),
  battery until PASS, then commit.
  THE G1 EXTRACTION ADJUDICATED
  (2026-11-03): source PDF found at
  ~/storage/shared/PDF/G1.pdf (13
  pages). THE MAP PAGES: PDF p2 =
  UPPER LEVEL (1 SQUARE = 10'), PDF
  p12 = DUNGEON LEVEL (with its
  symbol legend: boulder wall, pit
  covered, portcullis, bugbear
  guards, orc guards, pile of
  boulders, sink hole, flowing
  water, blocked passage). Render
  commands issued: pdftoppm -r 300
  pages 2 and 12 -> extract/g1/
  p002.png + p012.png, contact
  sheet removed, one commit. THE
  FULL MODULE TEXT IS NOW IN HAND
  (user uploaded the PDF; the OCR
  route extracted all 13 pages):
  upper key 1-25 with 10A (scroll
  room, secret door from 10),
  18A (storage + stairs down),
  A/B sub-points of 1 (guards +
  watch tower steps), GREAT HALL
  as the huge central room, 22 =
  OPEN COMPOUND (dire wolves),
  23-25 = the outbuilding with A =
  sergeant's alcove; dungeon key
  1-33 with 17A (weird abandoned
  temple), B/G/W lettered points
  (boulder wall strong point /
  rebel orc guard posts / bugbear
  watch points), 18A-dungeon
  vestry; both wandering tables;
  tournament pregens p11; the
  key text is the source for the
  LATER data round (encounter
  keys, hit point lists, treasure
  - format still undecided). FIRST
  VISION READ OF THE UPPER MAP (low
  -res page image, preliminary
  only): top-down keyed, north up,
  legible; road enters SE and runs
  to the main gate at south center
  (corroborates the seated road
  ruling); stockade gates at south
  center and possibly east; naive
  vision grid count ~24x22 = THE
  SUPERSEDED COUNT CLASS, the
  seated 31x40 squares stands until
  the 300dpi pixel-work; the two
  reads disagreed on outbuilding/
  tower position (bottom-left vs
  NE) - pinned during the skeleton
  pass against the 300dpi raster.
  THE SKELETON PASS ADJUDICATES
  FROM THE 300dpi RASTER (upload
  p002.png), not the low-res page
  image. SKELETON PASS 1 RULINGS
  (2026-11-03, pixel-work on the
  PDF-embedded map image 726x827 +
  vision crops; scripts under
  tool-results/g1-skeleton/):
  (1) THE LATTICE: square =
  19.9 x 20.0 px, X line k at
  x=2.0+k*19.9, Y line k at
  y=9.5+k*20.0; every strong
  wall line lands on the lattice,
  max err 2.5px. (2) BOTH SEATED NUMBERS
  CONFIRMED, EACH IN ITS DOMAIN
  (user correction 2026-11-03:
  'the map is actually 33x42'):
  wall-center spacings measured
  31.06 squares (X, 618px) and
  40.05 (Y, 801px) on the
  19.9/20.0px lattice = the
  NAIVE SQUARE COUNT 31x40 (the
  printed squares between the
  outer wall lines); under
  center distribution the
  boundary walls CONSUME A TILE
  PER SIDE, and the tile canvas
  - THE MAP - is 33x42. The
  pixel content spans X lines
  k=2..33 and Y lines k=0..40
  (the printed square extent);
  everything beyond the straddle
  ring cells (k=0..1 west,
  k>=34 east, Y k<0, Y k>41) is
  pure white drawing margin,
  outside the canvas. (3)
  THE PRINTED OUTER WALLS SIT ON
  THE EXTENT BOUNDARY LINES
  (north wall Y k=0 at y~5, south
  bar Y k=40 at y~807, west wall
  X k=2 at x~38, east stockade
  X k=33 at x~660) - the center-
  distribution ring straddle
  exactly as seated. THE ENCODING
  IS THE STRADDLE PAIR (walls
  occupy tiles, never grid
  lines): north wall Y k=0 ->
  canvas rows 0 AND 1; south
  bar Y k=40 -> rows 40 AND 41;
  west wall X k=2 -> cols 0 AND
  1; east stockade X k=33 ->
  cols 31 AND 32. The printed
  squares = canvas interior
  cells (cols 1-31, rows 1-40);
  the ring tiles sit one tile
  beyond the square extent;
  every ring tile's straddle
  mate is the first interior
  tile, so the battery's ring
  check and straddle-pair check
  verify the boundary together,
  and the loader collapses each
  pair to one wall for
  world::Map. THE WALL-POSITION-
  FIRST RULE (user, 2026-11-03,
  the methodological lesson of
  the 33x42 correction): a
  printed map with center-
  distributed walls can NOT be
  measured by naive counting -
  ink-center spacings, line
  spans, or square spans all
  yield the NAIVE count by
  construction, and reporting
  that as 'the map' is the
  error. The trace procedure is
  always: (1) locate the wall
  INK relative to the lattice -
  which line it straddles, which
  two tiles it consumes; (2)
  derive the tile encoding from
  the ink's tile occupancy; (3)
  only then state the canvas.
  The naive count enters ONLY as
  the squares cross-check field.
  Applied to every remaining
  pass: each ruling names the
  line and the straddle pair
  first, the tiles second.
  THE PRECISION DOCTRINE (user,
  2026-11-03): the 1978 module
  predates pixels entirely - the
  map is a hand-drawn tabletop
  artifact and a naive 31x40
  count was CORRECT FOR ITS
  PURPOSE; the source's
  imprecision is expected and
  fine. Our purpose differs:
  the trace feeds a
  deterministic engine where
  a wall is in a tile or it
  isn't, and everything
  downstream (the loader
  collapse, world::Map, the
  battery) inherits the
  precision we encode.
  PRECISION IS MANUFACTURED BY
  THE PIPELINE, NOT INHERITED
  FROM THE SOURCE: pixel-work
  measures what is actually
  drawn, the adjudication
  converts approximate
  hand-drawn art into exact
  tile geometry, the battery
  verifies the result. The
  source may be approximate;
  the trace may not. THE ROOM-PASS
  GENERATION+COMPOSITION
  CONTRACT (user, 2026-11-03):
  a declared purpose of the room
  passes is to identify ALL wall
  tiles needed THROUGH
  GENERATION AND COMPOSITION -
  the passes do not hand-draw
  the grid block; they accumulate
  (a) room records (id, printed
  key, name, canvas rect(s),
  doors) and (b) wall-run rulings
  (axis, lattice line k, extent,
  straddle = the tile pair each
  run consumes), plus point
  records (doors/stairs/secret
  doors with their tile + mate).
  The grid block is then
  GENERATED from those records
  (ring straddle pairs, wall
  runs as tile pairs, room
  interiors as floor, doors
  carved at their points, yard/
  road ink fills) and COMPOSED
  into the canvas; the battery
  gates the composition (missing
  wall -> void inside the extent
  or unwalkable room rect; wrong
  wall -> rect interior not
  walkable; door without mate ->
  FAIL). Completeness is by
  construction, not by eyeball.
  PASS ORDER (trace session):
  north-strip wing (18-25,
  structurally simplest,
  establishes the record
  formats) -> great hall ->
  chief's wing (2-10) -> kitchen
  wing (17-21) -> points pass
  (doors/stairs/secret doors) ->
  yard/road/exterior pass ->
  generate + compose -> battery
  until PASS -> user commits.
  NORTH-STRIP PASS STATE (2026-
  11-03, draft rulings saved at
  tool-results/g1-skeleton/
  northstrip_draft.json, valid
  JSON): MAJOR WALL RUNS
  measured band-edge-first -
  verticals X6 (wing west edge,
  straddle cols 4-5, rows 1-11),
  X9 (rows 6-13), X11 (rows
  6-13), X14 (rows 2-13, with
  DOOR GAP mid-row-8 = compound
  door tiles cols 12-13 row 8),
  X20 (row-1 only), X26 (rows
  6-11), X27 (row-1 only),
  X33 (east stockade segment,
  cols 31-32); horizontals Y0
  north wall (rows 0-1, cols
  4-32, GAP at cols ~15-16
  RULING PENDING - vision says
  ~2 squares, no gate drawn,
  empty behind), Y6 row divider
  (rows 6-7; three segments
  with the compound's OPEN
  NORTH mouth at cols 13-18),
  Y12 (kitchen-wing south
  start). IDENTITIES: 19 = row
  1 k6-14 (servants), 18 = row
  2 k6-9 (workroom), 20 = row
  2 k11-14 (per label crop),
  22 = compound k14-26 rows 2-3
  open north, 23 = guard room
  k26-33 row 2, 24/25/A =
  outbuilding row-1 k27-33,
  17/21/18A = kitchen wing
  proper, south of strip, next
  passes. OPEN ITEMS: Y9-vs-Y10
  disambiguation (band y
  189-215) - RESOLVED
  2026-11-05 full-res:
  the wall rides Y10
  (thick segments cols
  3-6 at 1.00 and cols
  27-33 at ~0.7, both
  copies agree; Y9
  carries no wall - its
  0.15-0.2 reads are
  vertical crossings
  only). FOLLOW-UP
  RESOLVED 2026-11-05
  (Curtiss's ASCII map,
  cols 15-20): Y10 IS a
  continuous wall across
  cols 7-26 - no door
  gaps there - but the
  drawn ink sits ~8px
  SOUTH of nominal Y10
  (~0.13 pitch hand
  drift), at the edge of
  hallscan's band, which
  is why fullres read a
  uniform-low 0.13-0.17.
  Verticals 16-20 T into
  it. NEW CALIBRATION
  LESSON: walls can
  drift +/-0.15 pitch off
  the nominal lattice
  line; a uniform-low
  (0.10-0.2) reading on
  an expected-solid line
  means check ink offset
  from nominal before
  ruling it absent.
  Blips on Y10 at cols
  10, 13-14, 21-22, 26
  still unclassified
  (door vs label vs
  crossing - label-first
  lesson applies), Y9
  RULING REVISED AGAIN
  2026-11-05 (ASCII, cols
  11-15): Y9 DOES carry
  a wall in the kitchen-
  wing stretch (cols
  ~6-15, drawn +0.1
  pitch south, y~1068-
  1072 at fullres);
  "Y9 no wall" holds
  only for cols 15-25.
  BOTH Y9 and Y10 are
  walled there - the
  original ambiguity was
  two stacked wall
  lines. Kitchen wing
  cols 11-15 has
  horizontal walls on
  Y5,Y6,Y7,Y8,Y9,Y10 =
  dense room grid.
  OBJECTS: (a) RESOLVED
  2026-11-05 (Curtiss,
  eye-check via Acrobat
  crop): the cols 13-14
  wall-straddler is the
  AREA LABEL "20" -
  digits "2"+"0" in
  heavy stroke straddling
  Y9 (my thick-bar
  reading = the digit
  strokes; channel
  heuristic fails on
  bold type - eye-check
  stays the final
  referee). Wall east of
  the label = X14,
  already seated. Room
  20 = the block around
  cols 13-14 rows 9-10.
  (b) RESOLVED 2026-11-05
  (Curtiss eye-check):
  the hollow-centered
  object straddling Y6
  at cols 13-14 (fullres
  x~1030-1070, y~856-
  896) is a POORLY
  DRAWN DOOR in the Y6
  wall, not a label.
  Seat: door on Y6,
  cols 13-14. LESSON
  updated: label-first
  still rules for dense
  blobs, but messy hand
  ink cuts both ways -
  the eye-check is the
  only referee for both
  classes.
  ASCII PROBE RECIPE
  (the labeling loop's
  instrument, in
  regular use since
  2026-11-05): Python/
  PIL on the full-res
  Termux copy
  (2550px, lattice
  X0=181.95 P=64.2742
  Y0=482.0 Q=64.5875).
  Grid: for each y in
  range (step 3-4), for
  each x (step 4, block
  4 wide x 3-4 tall),
  d = min() over block;
  '#' if d<128 (solid
  ink), '+' if d<180
  (faint gray = counter/
  texture class), '.'
  else. Min-pooling
  catches 4px walls
  that hallscan's
  fraction average
  hides at band edges.
  Print with y= labels.
  Pair with hallscan
  (lattice-indexed
  v/h scans) for
  line-level runs, and
  PNG crops (im.crop()
  + resize + save to
  ~/pdf, open with
  'termux-open' -
  Android gallery
  cannot see Termux
  private storage)
  for Curtiss's
  eye-checks. Full
  probe cycle:
  hallscan -> ASCII
  probe -> crop ->
  eye-check -> seat.
  EYE-CHECK LABELING
  LOOP (FORMALIZED
  2026-11-05, Curtiss's
  observation): the map
  pass is a human-in-
  the-loop recognition
  pipeline. Vibe reads
  ink (geometry,
  thickness, drift,
  voids, channels) and
  PROPOSES a class
  (wall/door/label/
  furniture/feature)
  with confidence;
  Curtiss's eye-check
  on the full-res crop
  or printed page is
  GROUND TRUTH and
  always overrides.
  Each label seats a
  reusable lesson.
  LABELED EXAMPLES SO
  FAR: "16","20" =
  bold digits, solid
  slabs + channels,
  straddle wall lines
  (label-first for any
  dense blob on a
  line); Y6 strip
  doors = white
  pockets between
  double-wall lines,
  ~0.45 pitch wide;
  poorly drawn door =
  hollow messy blob;
  thin walls = uniform-
  low 0.10-0.2 + 0.1-
  0.15 south drift
  (check ink offset
  before ruling
  absent); counters =
  faint gray '+' ink;
  drawn-face doors
  (east gate, D-18-SE)
  = solid wall where
  geometry wants a
  door - adjudicate
  from module, never
  from ink. DOCTRINE:
  ink shape alone
  cannot separate
  classes; shape +
  position + label
  history can. Probe
  cycle now closes in
  1-2 rounds.
  COST CURVE (ruled in
  discussion 2026-11-05,
  Curtiss): labeling
  cost FALLS as the
  loop runs, three
  mechanisms: (1)
  AMORTIZATION - each
  label seats a lesson
  that makes the next
  similar case a 1-word
  confirm ("20" was
  nearly free after
  "16"); (2) SURGICAL
  PROBES - each probe
  now carries one
  specific proposed
  class + a bounded
  yes/no, not a region
  question (active
  learning: aim labels
  at the highest-value
  ambiguous cases);
  (3) RECORD PREVENTS
  RE-LABELING - nothing
  ruled gets eyes
  twice. LIMIT: cost
  never reaches zero -
  first-of-its-kind
  classes (e.g. the
  roofed outbuilding)
  always need one full
  eye-check; the goal
  is cheap routine
  geometry, saving
  labels for
  irreplaceable cases.
  ANTI-FAILURE RULE:
  never skip the middle
  step (proposal ->
  Curtiss label ->
  seat); over-applying
  a lesson to a
  lookalike is the
  known failure mode
  of the loop.
  NEW LABELED EXAMPLE
  (outbuilding eye-check
  2026-11-05): label
  "24" on the
  outbuilding has
  MISALIGNED digits -
  the '2' and '4' sit
  at different
  heights/offsets (bad
  typesetting on the
  original). Lesson:
  labels with offset
  digits read at low
  res as two
  disconnected blobs
  in texture, not one
  glyph group - one
  more way labels hide
  from ink-reading.
  Confirms 24's NE
  position in the
  outbuilding.
  OUTBUILDING RULING
  (Curtiss eye-check
  2026-11-05): INTERNAL
  WALLS EXIST - the
  draft's "no internal
  walls drawn" claim is
  DEAD (roof-plank
  texture hid them
  from the 726px copy,
  same artifact class
  as the thin walls).
  A FIREPLACE / hearth
  is also visible.
  DIVIDER LAYOUT RULED
  (Curtiss, 2026-11-05):
  L-SHAPED internal
  division - an N-S
  wall near the west
  edge and an E-W wall
  near the south edge,
  LINKED BY A SHARED
  CORNER. Carves the
  footprint into three
  spaces: west strip
  (25/A), NE block
  (24), SE corner room
  (23 guard room
  candidate). PIXEL
  PIN (full-res ASCII,
  2026-11-05): N-S
  wall PINNED = line
  X28 (thin ~8px,
  west-drift ~0.1-0.15
  ), 0.85-1 pitch east
  of the X27 west
  wall. X28 runs from
  the north wall
  THROUGH Y6 and
  continues south into
  rows 7+ (room 23's
  area) - the X27/X28
  west pair continues
  into the structure
  south of the
  outbuilding. East
  wall = X32 (thin,
  west-drift ~0.15).
  Probe ambiguities
  RESOLVED (Curtiss
  eye-ruling
  2026-11-05):
  OUTBUILDING CLASS
  CLOSED. Structure:
  west wall X27, east
  wall X32, N-S
  interior wall X28
  (runs south through
  Y6 as room 23's west
  wall), south wall =
  the THICK Y6 band
  (doubles as 23's
  north wall; the Y5
  band + thin
  verticals at
  k~28.8/31.15 = plank
  texture, not walls).
  Rooms: 25/A = west
  strip (cols 27-28,
  rows 1-6); 24 = NE
  block (cols 28-32,
  rows 1-6) containing
  THE FIREPLACE (big
  solid block,
  fullres x2097-2165
  y646-716, straddling
  X30, rows 2.5-3.6 -
  first confirmed
  hearth glyph; NOTE
  label-first was
  applied and REJECTED
  by ground truth -
  the "24" label is
  elsewhere); 23 =
  south of Y6 (guard
  room, cols ~27-31,
  rows 6-10, shares
  the X27/X28 west
  pair). DOORS (2,
  Curtiss): (1) in the
  Y6 south wall at
  k30.0-30.6 (slots
  seen in probe):
  24 <-> 23; (2) west
  strip near south
  wall, k~28 rows
  5.5-6 (the gray fuzz
  zone): 25/A <-> 23.
  Both doors connect
  the outbuilding to
  23 south. ROOFED-
  BUILDING CLASS
  SEATED: plank
  texture at pitch
  spacing hides
  interior walls and
  features from the
  downscaled copy -
  full-res ASCII or
  eyeball required;
  expect hearths,
  interior divisions,
  and doors under
  planks.
  SOUTH WING PASS
  STARTED 2026-11-05
  (18A, the splice-
  target pin):
  full-res ASCII of
  18A (lines X3-X7,
  rows 14-18) shows a
  4x4 CELL GRID -
  walls on Y14, Y15,
  Y16, Y17, Y18 and
  X3-X7, all on-
  nominal (no drift in
  this block); cells
  mostly empty
  (storage). North
  door CONFIRMED in
  Y14 wall at k~3.4-
  3.75 (matches draft
  pin). X4 thick, X3/
  X5/X6/X7 thin. 'A'
  label (draft: col
  5.5 row 16.6) not
  visible in ASCII -
  faint, pending.
  STAIRS: TWO
  parallel-stroke
  structures on the
  east side, eye-
  ruling pending:
  candidate A = rows
  15-16 cell, cols
  X5.5-X7.0 (fullres
  x535-631, y1451-
  1519), THICK bars
  (####.####.####) -
  stairs or shelving;
  THE SPIRAL TARGET
  PINNED (Curtiss eye-
  ruling 2026-11-05):
  THE STAIRS DOWN in
  18A = the thin
  vertical-stroke
  structure in the
  rows 17-18 cells,
  fullres x507-643,
  y1583-1643. SQUARE
  TILES: (5,18) and
  (6,18) (k 5.05-6.9,
  row 18 = lines
  Y17-Y18). The Y17
  and Y18 E-W walls
  BUTT UP TO the
  stairs; the Y17
  grid line marks the
  stairs' start. All
  the vertical lines
  there = stair
  treads. This is the
  dungeon-splice
  point - the pin the
  repo has been owed
  since the R848 fresh
  start.
  CORRECTIONS from
  same ruling: the
  "18A" LABEL sits at
  the upper edge of
  the feature crop =
  just below the Y15
  wall, cols ~5.5-7
  (the two bold blocks
  at y1439-1447
  flanking X6 = the
  label digits -
  label-first WINS
  AGAIN; draft's old
  'A'-at-col-5.5-row-
  16.6 superseded).
  Candidate A (thick
  bars, rows 15-16,
  cols X5.5-X7.0) =
  storage/shelving
  (probable - 18A =
  storage + stairs per
  module; class
  unruled, low
  priority). 18A
  complete picture:
  4x4 cell grid
  X3-X7 x Y14-Y18,
  storage cells,
  stairs down at
  (5,18)-(6,18), N
  door at Y14 k3.4-
  3.75, label 18A
  below Y15 wall.
  REMAINING SOUTH-WING
  PINS: 18A's E
  openings into 18
  (draft: through the
  X6/X7 side - exact
  gaps unruled),
  17-south-door far
  side, rooms 14/15/
  16 rects + west
  hallway extent.
  X7/X8 SCANS
  2026-11-05 (18A east
  face): X8 = SOLID
  wall rows 15-18
  (0.95-0.97, strongest
  wall reading of the
  day) - NEW FACT.
  18A's east side is
  double-buffered:
  thin X7 (18A's east
  wall, no door voids
  rows 15-18), 1-pitch
  column X7-X8, then
  solid X8; east of
  X8-X9 the column
  opens into 21 (X9
  absent south of
  Y14). X7/X8 rows
  11-14 = faint
  counters (draft
  ruling holds).
  DRAFT CLAIM HIT:
  "18A opens E into
  18" NOT reproducing
  - Y14 ran solid
  east of the N door
  (k3.4-3.75) in the
  18A probe. Junction
  probe commanded
  (X3-X9, rows
  12.3-15.3) to map
  the hallway/
  compound/18A door
  network directly.
  JUNCTION PROBE
  RESULT 2026-11-05
  (X3-X9, rows
  12.3-15.3): (1) Y13
  = FULL-WIDTH solid
  wall (compound south
  boundary, X3-X9).
  (2) Y14 solid except
  the N door k3.4-
  3.75 - and the N
  door connects the
  X3-X4 WEST STRIP
  (not the hallway)
  into 18A: the
  hallway X4-X6
  dead-ends at Y13
  solid, X4/X5
  continuous. 18A's
  ONLY DRAWN ACCESS =
  the N door from the
  west strip (NW-
  annex territory).
  (3) Draft's
  D-18-W-18A X6 door
  voids (rows 12-14):
  DEAD - X6 solid at
  full res (2nd
  adjudicated door
  with no drawn ink;
  module prose may
  still support it -
  drawn-face caveat).
  (4) Bold mass at
  X6-X7 rows 13.2-13.9
  (fullres x599-654,
  y1332-1380) in the
  empty rows-13-14
  band - label-first
  proposal: the "18"
  label; eye-check
  pending. (5) "18A"
  label confirmed in
  ink at rows
  15.0-15.3, cols
  5.2-6.3 (matches
  Curtiss ruling).
  (6) X3-X4 west strip
  = open floor rows
  12-14, connects
  north beyond crop.
  JUNCTION MASS RULED
  (Curtiss, 2026-11-05):
  the bold mass at
  X6-X7 rows 13-14 IS
  THE DOOR FROM 18 TO
  18A - a THRESHOLD
  STRUCTURE: solid
  drawn door filling
  the inter-wall gap
  (Y13-Y14 band),
  walls abutting it
  (same idiom as the
  stairs). DOOR
  RENDERING FAMILY
  COMPLETE: (1) void
  doors w/ jamb stubs
  (edge-4 class); (2)
  pocket doors = white
  slots in double
  walls (Y6 doorways);
  (3) threshold
  structures = solid
  mass between two
  wall lines, walls
  butt it (18->18A).
  Label-first REJECTED
  a 4th time (mass was
  door, not "18"
  label). D-18-W-18A
  RE-PINNED: the
  18<->18A door at
  cols 6-7, row 14
  (fullres x599-654,
  y1324-1392,
  vestibule band) -
  supersede old
  (5,12)-(5,14) tile
  pin. 18A ACCESS
  NETWORK COMPLETE:
  (a) N door k3.4-3.75
  from the X3-X4 west
  strip; (b) threshold
  door from 18 (X6-X7
  rows 13-14). Module-
  conformant. JUNCTION
  MASTERED; 18A FULLY
  COMPLETE (stairs
  (5,18)-(6,18), cell
  grid, labels, both
  doors).
  WEST WING PASS
  STARTED 2026-11-05
  (hallway extent +
  14/15/16, v-scans
  X4/X6/X3/X8): X4
  solid rows 15-18
  (18A interior wall),
  ABSENT rows 19-26
  (hallway widens/
  merges with west
  strip south of
  18A), stub row 27,
  open 28-31. X6
  solid rows 23-30
  (15/16 divider
  candidate), absent
  rows 17-22 w/ stub
  row 21; rows 14-18
  thin (ASCII-
  confirmed, partial
  reads = drift). X3
  nothing solid rows
  22-31. X8 essentially
  absent rows 23-31 -
  if confirmed, room
  16 has NO drawn east
  wall (opens into the
  cols 8-9 corridor
  mouth). Shape
  forming: one broad
  open hall X3-X6 rows
  19-22, then X6
  divider from row
  23. ALL glyph-class
  readings pending
  ASCII referee (probe
  commanded: X1-X9,
  rows 18.5-24).
  WEST WING ASCII
  RESULT 2026-11-05
  (X1-X9, rows
  18.5-24): OPEN-HALL
  HYPOTHESIS DEAD.
  X3-X7 ALL present as
  THIN walls through
  rows 18.5-24; the
  v-scans missed them
  because drift pushed
  them outside the
  scan band. LESSON
  UPGRADED (seated):
  even FULL-RES line
  scans can miss thin
  walls - the ASCII
  min-pooling map is
  the ONLY referee for
  thin-wall presence.
  West wing = FULL
  CELL GRID: solid
  horizontals at Y19,
  Y20, Y21, Y22 (extra
  thick), Y23, Y24 -
  no gaps at this
  resolution;
  verticals: X2 thick
  (building west
  wall), X3-X7 thin,
  X8 THICK, X9
  PRESENT/THICK at
  rows 22.5+ (draft's
  "X9 ends at Y14"
  WRONG - resumes
  south of Y22). West
  "hallway" = 2-wide
  cell strip (X4-X6)
  chopped by row
  walls - door
  inventory unknown.
  FEATURE GLYPHS
  pending eye-check:
  (a) parallel strokes
  x500-570 rows
  20.4-20.9 (X5-X6
  cell); (b) structure
  x546-618 rows
  21.6-21.9 (X6-X7
  cell); (c) two tall
  bold verticals
  k~5.6-7.0 rows
  22.6-24 (16's north
  cells) - stall
  walls/shelving/
  stairs/label
  candidates. Crop
  commanded (x470-740,
  y1760-2040).
  WEST WING FEATURE
  LABELS RULED
  (Curtiss, 2026-11-05):
  (a) the "parallel
  strokes" at x500-570
  rows 20.4-20.9 =
  the "17" LABEL
  ("1"+"7" are
  vertical glyphs -
  digits read as
  parallel strokes at
  stroke resolution;
  NEW LABEL RENDERING
  seated). (b) THE
  DOOR = right below
  the label at the Y21
  grid line
  (threshold-class
  structure x546-618,
  rows 21.6-21.9). (c)
  the tall bold
  verticals at
  k~5.6-7.0 rows
  22.6-24 = OPEN
  ENTRYWAY gap complex
  (non-door entryway
  class - 4th rendering
  class: void-jamb
  doors, pocket doors,
  threshold
  structures, open
  entryways), piercing
  THE EASTERN WALL OF
  LOCATION 17. (d)
  Curtiss CONFIRMS:
  west wing cell block
  rows ~19-22 cols 1-6
  = ROOM 17 - matches
  bbox pass [1,19,6,
  22]; "17" label
  seated at rows
  20.4-20.9 cols
  5.1-6.0. NO STAIRS in
  the wing. OPEN
  QUESTION for ruling:
  identity conflict
  with the 11-03
  compound adjudication
  (compound rows 8-13
  ruled 17-kitchen-
  north / 18-workroom-
  south) - if 17 = the
  west wing block, what
  is the compound?
  Pending: door
  destination, entryway
  destination.
  WEST WING IDENTITY
  RESOLVED (Curtiss,
  2026-11-05, prose
  ruling): "17 is the
  kitchen. 18 is
  another part of the
  kitchen." The 11-03
  compound adjudication
  STANDS (compound
  rows 8-13 = 17
  kitchen + 18
  workroom); the west
  wing block (rows
  19-22) = the
  kitchen's west
  annex, carrying the
  "17" label. One
  kitchen, both zones.
  CONNECTIVITY RULED:
  (a) the door below
  the 17 label (Y21
  threshold) opens
  into A HALLWAY (the
  west hallway serving
  15/16/14, rows 22+);
  (b) 17's east
  entryway opens into
  THE LONG HALL (room
  11, cols 9-20 rows
  19-34) at rows
  ~22.6-24 - the long
  hall's west edge
  receives 17's
  entryway; X9's
  resumption at rows
  22.5+ = long-hall-
  adjacent structure.
  WEST WING PASS
  remaining: hallway
  south extent + doors
  to 15/16/14 (rows
  24-31) + room 14
  geometry (probe
  next).
  WEST WING SOUTH
  ASCII 2026-11-05
  (X1-X9, rows 24-31):
  CELL GRID CONTINUES
  - horizontals Y25,
  Y26, Y27, Y28, Y29,
  Y30 (extra thick),
  Y31; verticals X2/
  X5/X6/X9 thick, X3/
  X4/X7/X8 thin. The
  whole west wing =
  one architecture:
  kitchen annex (rows
  19-22), then 15/16
  cells. NO STAIRS
  (confirms ruling).
  LABEL-FIRST
  PROPOSALS: "15" at
  x390-426, rows
  26.3-27.0 (15's
  east cell, inside
  bbox lines 1-4);
  "16" at x666-702,
  rows 25.7-26.9
  (16's east cell,
  inside bbox lines
  5-8). South zone
  (rows 30-31): bold
  structures k~4.3-7.0
  merging into the
  extra-thick Y30
  band + structures
  hugging X4/X8 in
  rows 30.2-31 -
  threshold-door
  candidates for 14's
  access / 15-16
  south doors / "14"
  label. Crop
  commanded for
  eye-ruling (x360-
  720, y2090-2480).
  "15" AND "16"
  LABELS CONFIRMED
  (Curtiss eye-ruling
  2026-11-05): "15"
  at x390-426, rows
  26.3-27.0 (east
  cell, lines 1-4);
  "16" at x666-702,
  rows 25.7-26.9
  (east cell, lines
  5-8). Both rects
  CONFIRM against the
  11-04 bbox pass.
  Label class now 6+
  examples ("16","20",
  "18A","24","15",
  "16"): bold mass +
  channels in a room
  cell = label until
  eyes rule otherwise.
  PENDING from same
  crop: the rows
  30-31 south
  structures (Y30
  band mass k~4.3-7.0
  + X4/X8 hugging
  bits) - door into
  14 / shelving /
  "14" label?
  SOUTH DOOR ZONE
  RULED (Curtiss,
  2026-11-05): the
  rows 30-31
  structures = 3
  DOORS + a 4-LINE
  wall band (thick
  Y30/Y31 complex).
  Ink shows 3 masses:
  near X4 (k~4.3-4.7),
  center (k~5-7,
  merged into the Y30
  band), near X8
  (k~7.4-8.1). BOTH
  15 AND 16 HAVE A
  DOOR (confirmed).
  Third door's
  attribution + each
  door's exact wall/
  destination:
  pending ruling.
  WEST WING CLOSED
  (2026-11-05): all 3
  south-band doors
  open INTO ROOM 14 -
  15's door (S wall,
  k~4.3-4.7), 16's
  door (S wall,
  k~7.4-8.1), and the
  center door (k~5-7,
  the hallway's south
  exit). CONNECTIVITY
  COMPLETE: 17-annex
  door (Y21) ->
  hallway -> 15/16
  cell grid -> 3 doors
  into 14; 17's east
  entryway -> the long
  hall; 15/16 labels
  seated; 18A below 14
  via threshold door
  + N door. WEST WING
  GEOMETRY MASTERED
  rows 18.5-31.
  Remaining in south
  wing: room 14's own
  rect + interior
  (rows 31-34, probe
  next).
  ROOM 14 PROPER =
  ROWS 32-34, NOT THE
  FULL 31-34 GRID
  (2026-11-05, eye-check
  c1): the rows 31-34
  region is TIERED.
  1) An E-W wall with a
     DOOR sits at ~Y32
     (drawn y~2541,
     slightly NORTH of
     nominal - the
     exception to south
     drift, like 18A).
  2) Below it: "14"
     label at ~X5-X6,
     rows ~32-33
     (y~2550-2598).
     LESSON x8: I read
     the label mass as
     "a big solid
     structure"; Curtiss
     saw "14". Bold-
     digit label-first
     now has N+1
     confirmations.
  3) Fireplace just
     south of the label:
     wide at base, X5-X7,
     rows ~33-34
     (y~2616-2658),
     hearth class
     again (cf. 24's).
  4) South boundary =
     thick 4-line wall
     band at Y34
     (y~2664-2700),
     solid, no door gap
     in X2-X9 by ASCII.
  The rows 31-32 tier
  north of the ~Y32
  wall = cell row
  (voids between
  verticals X2/X3/X4/
  X5/X6/X7/X8) that
  receives the 3
  west-wing doors -
  so those doors land
  in a VESTIBULE
  TIER, then the
  ~Y32 door leads
  into 14 proper.
  Door position along
  the ~Y32 wall still
  to pin (ASCII shows
  the wall solid at
  6px step - maybe
  threshold-style or
  narrow; fine probe
  pending). West edge
  reads X2 (thick
  run), X1 void -
  open lane west of
  14? c2/c3/c4
  verdicts pending.
  MARGIN/LEGEND CLASS
  (2026-11-05, c2 eye-
  check): the stub
  west of X2 below
  the Y35 line (y~2730
  solid run + gray
  above) is a MAP
  LEGEND SYMBOL for
  a door, printed in
  the margin OUTSIDE
  the building.
  LESSON x9: margin
  ink outside the
  outline is legend
  graphics - never
  read bottom-edge
  stubs as walls,
  steps, or porches.
  Fine scan verdicts
  (3px): door into
  the label tier is
  the CENTER HALLWAY
  DOOR through the
  Y31 band at
  X5.2-X6.4 (voids
  cols 43-49, jambs
  40-42 / 51-52,
  solid leaf/thresh-
  old mass rows
  2469-2499) - same
  door as the west-
  wing ruling, now
  ink-pinned. "14"
  digits resolve at
  rows 2550-2601,
  X5.4-X6.5 ("1" +
  "4" with counter).
  y2541-2544 wall =
  REAL, no door in
  X3.5-X8 at 3px.
  y2604-2610 =
  fireplace top
  (mantle/flue),
  hearth widening to
  X5.3-X7.4, strad-
  dling X6. OPEN:
  door into 14 pro-
  per must be west
  of X3.5 (west fine
  scan pending); in-
  terior verticals
  X4/X5/X6/X7 cross
  the label/fire-
  place room - par-
  titions or pillars?
  (c4 south-wall
  verdict pending).
  WEST FINE SCAN
  VERDICTS (3px,
  X1.5-X4): y2541-44
  wall is SOLID X2-X8
  - no ink-visible
  door anywhere, yet
  Curtiss saw one in
  c1 (just above the
  "14" label, which
  starts y2550 - only
  6px below the
  wall, so the door
  is IN THE y2541
  WALL, not the Y31
  band). RULING: the
  14 door is DRAWN
  SHUT/SOLID -
  drawn-face family
  now has an INDOOR
  instance (cf. east
  gate, D-18-SE):
  a drawn-closed
  leaf is ink-
  indistinguishable
  from wall; only
  eyes or the module
  text find it.
  X2 = THICK ~33px
  solid vertical
  band, full height
  Y31->south wall -
  too fat for a wall
  line; chimney-stack
  candidate (hearth
  class) or drawn
  double wall; eye
  verdict pending.
  STRUCTURE: rows
  31-34 = 3-TIER x
  6-COL lattice
  (bands y2541-44 +
  y2604-10; verts
  X3,X4,X5,X6,X7;
  X8 east edge; X9
  VOID at these
  rows). "14" label
  in tier 2 cell
  X5-X6; hearth in
  tier 3 at X5.3-
  X7.4 straddling
  X6; 3 west-wing
  doors land in tier
  1. OPEN: partition
  suite vs one hall
  with pillar lines;
  door position
  along y2541 wall;
  X2 band identity;
  c4 south-wall
  verdict.
  LESSON x10 - PRINTED
  GRID LINES (major,
  c7 eye-check
  2026-11-05): the
  verticals X4-X8
  crossing room 14's
  interior (and the
  y2541 band) are the
  MAP'S PRINTED REF-
  ERENCE GRID, not
  walls. Ink sitting
  on lattice lines
  INSIDE a room is
  not necessarily
  architecture. My
  "3-tier x 6-col
  cell lattice" read
  of rows 31-34 is
  DEAD. ROOM 14 = ONE
  OPEN HALL, rows
  31-34: 3 north
  doors through Y31
  (15's door k~4.3-
  4.7, 16's door
  k~7.4-8.1, hallway
  center door
  k~5.2-6.4 - "the
  door further
  north" per
  Curtiss, no door
  in the y2541 grid
  line), "14" label
  at X5.4-X6.5 rows
  32-33, hearth
  X5.3-X7.4 rows
  33-34 straddling
  X6, thick 4-line
  south wall at
  Y34 (solid, no
  gap in X2-X9).
  AUDIT FLAG: any
  un-eye-checked
  "thin wall" seated
  from ink alone
  could be grid -
  walls need to
  bound/connect or
  an eye verdict.
  X2 fat ~33px band
  is NOT grid - too
  thick; identity
  pending (c6).
  c4 south-wall +
  X9 verdict pend-
  ing; hall west/east
  wall lines TBD
  (X8 vs X9).
  C4 CLOSED (Curtiss,
  2026-11-05, final):
  the Y34 thick band
  is the BOUNDARY
  WALL - solid, no
  door X2-X9 (con-
  firmed at full res
  by eye and at 3px
  fine scan; do not
  re-probe). Main
  entry into 14 is
  NOT through the
  south wall west of
  X9. Downscale
  review found a
  THICK VERTICAL
  MASS at ~X9.5-X10
  piercing the Y34
  corner and con-
  tinuing south -
  candidate entrance
  structure, east of
  all prior probes
  (they stopped at
  X9+10px); identity
  pending. Also
  open: c6 fat X2
  band identity.
  DELIVERY RULE (Curtiss,
  2026-11-05): Android
  Acrobat opens only
  ONE image at a
  time - never send
  multiple
  termux-open calls
  in a round. STITCH
  all crops of a
  round into ONE
  composite PNG
  (vertical stack,
  caption text above
  each panel, 2-3x
  zoom) and open
  that single file.
  DASHED-LINE CLASS
  (Curtiss, 2026-11-05,
  sec3 eye-check):
  the mass at
  X8.8-X9.9 above Y31
  (and the thin X9
  line, rows 33-34)
  = DASHED EXTENSION
  LINES marking the
  TOWER BOUNDARY as
  seen on the UPPER
  LEVEL - a projec-
  tion, not a
  current-level
  wall. LESSON x11:
  dashes pool as
  broken '###.##.###'
  strokes in min-
  pool ASCII and can
  masquerade as
  digits or thin
  walls; dashed
  lines = extension/
  projection
  graphics (tower,
  upper level),
  never architecture
  on this level.
  SE-corner state:
  gate room X10-X11
  (thick ~24px
  walls vs ~6px
  grid), N opening
  X10.2-X10.8, big
  S door X10.4-X11.0
  w/ leaf bar
  y2655-61; porch
  chamber S of
  boundary wall;
  wall at X12 + mass
  X12.1-12.4 rows
  31-34 (rooms
  further east, un-
  probed). Pending:
  sec1 main-entrance
  verdict; east-of-
  X12 probe.
  EAST BLOCK OPENS -
  ROOM 13 (Curtiss,
  2026-11-05, composite
  panel A): the
  two digits between
  X12-X13, rows
  30.9-31.9, read
  "13" - the room
  column X12-X13,
  rows 31-34, is
  ROOM 13. Thick
  ~24px wall at X14
  (real); thin lines
  X12/X13/X15/X16
  pending partition-
  vs-grid. Structure
  cluster X13.5-14.6
  rows 30.7-33.9
  with solid mass
  X13.6-14.0 rows
  32.9-33.9 against
  X14 wall (hearth
  candidate, cf. 24
  + 14 hearths).
  Building EXTENDS
  SOUTH of the Y34
  band east of X12
  (verticals X12/X13/
  X13.65/X15 continue
  below; solid mass
  X15-16.5 south of
  boundary wall) -
  Y34 is the south
  wall only west of
  ~X12. CURTISS ALSO
  SEES 2 SETS OF
  DOUBLE DOORS in
  the east composite
  - positions to
  pin (asked). sec1
  main-entrance
  verdict still
  pending.
  TESSERACT OCR DOCTRINE
  (2026-11-05): full-
  map pass, --psm 11,
  whitelist
  0123456789A, TSV
  with boxes; filter
  conf>=30 (>=60 too
  strict). Positions
  are RELIABLE even
  when readings are
  not ("18A" read
  "111" at exactly
  the seated X5.1/
  row-16.1). Bold
  serif labels often
  MISSED entirely
  (13/14/15/16/17/24
  absent) - OCR is a
  proposal source,
  never ground
  truth; eyes still
  adjudicate. HIT
  CLUSTERS (pending
  eye-checks):
  2x "11"-shaped at
  X16.0 row 3.2 and
  X23.0 row 3.3
  (north strip,
  unexplained);
  long-hall label
  candidates "3"
  X11.1 row 23, "1741"
  X15.0 row 22.1, "1"
  X26.0 row 23 (the
  long hall's true
  number never
  pinned); gate room
  "1" X11.2 row 31 =
  "10" candidate;
  SOUTH BLOCK label
  row X24-X27 rows
  38.6-39.1: "A10"
  (=10A) X24.1 row
  38.6, "A14 1" X25.2,
  "140" X26.8 row 39.1
  + a row-37 "13"
  X11.1 - the SE
  south extension
  is the 10/10A
  complex.
  LONG HALL = GREAT
  HALL (Curtiss,
  2026-11-05, panels
  3-5): the draft's
  "long hall (room
  11)" is the GREAT
  HALL - ROUND FIRE
  PIT at ~X15, row 22
  WITH ITS LABEL
  (digits not yet
  read; OCR said
  "1741"), ROUND
  COLUMNS (drawn
  circles) at ~X11
  row 23 and beside
  the pit, doors at
  X11.1 row 23 and
  X26 row 23, wall
  segments + grid.
  NEW FEATURE
  CLASSES: round
  columns (circle
  glyphs - can pool
  as digits/doors in
  ASCII and OCR);
  round fire pit
  (big circle w/
  label). N-STRIP OCR
  JUNK CONFIRMED:
  "11" at X16 row 3.2
  = pure grid; "11"
  at X23 row 3.3 =
  wall + digit "2" +
  grid (partial label
  "2x", full digits
  pending wider
  crop). LESSON x10
  EXTENDED: grid
  pools as fake
  labels for OCR
  too; eye verdicts
  killed 2 of 3
  clusters. East "1"
  X26 row 23 = door
  junk. Pending:
  panel 6 (10A
  cluster) verdicts;
  fire pit label
  digits; full "2x"
  n-strip label.
  PANEL VERDICTS
  (Curtiss, 2026-11-05):
  1) GREAT HALL =
  ROOM 11 CONFIRMED:
  the fire pit label
  reads "11" (OCR
  "1741" = "11" mis-
  read). Draft alias
  survives: room 11,
  great hall, round
  fire pit ~X15 row
  22, round columns,
  doors at X11.1 row
  23 and X26 row 23.
  2) N-strip "2" =
  label "25" - fits
  the outbuilding
  24/25 suite.
  3) SOUTH BLOCK JUNK:
  "A10"/"A14 1"/"140"
  at X24-X27 rows
  38.6-39.1 = ROAD
  OUTSIDE graphics,
  not building labels
  - no 10A there;
  the Y40 bbox over-
  extends SE (road
  terrain south of
  the building at
  X24+). LESSON x12:
  road/terrain
  graphics outside
  walls can OCR as
  digits/labels.
  4) TOWER = "1B":
  row-37 "13"-shaped
  hit = the 1B tower
  designation -
  matches the dashed
  upper-level tower
  boundary lines
  (lesson x11). The
  tower is keyed "1B"
  on the map. Gate
  room "10" candidate
  (X11.2 row 31)
  still unconfirmed;
  10A not yet found
  (search east block,
  not south).
  GREAT HALL EDGES
  (run-length strip
  scans, 2026-11-05,
  ink-provisional):
  X9 = REAL WALL rows
  ~22-30 (SOLID 0.81
  sustained; matches
  "X9 resumes ~row
  22.5"), grid-thin
  south of the Y31
  band (0.25-0.31) -
  hall may open
  toward 14 at rows
  31-34 unless X8 is
  the wall there
  (X8 wall-vs-grid
  STILL UNADJUDI-
  CATED). X20 = GRID
  full length rows
  18-35 - draft "hall
  cols 9-20" DEAD;
  hall extends east
  >= X26. Y19 = GRID
  (thin sustained +
  crossings) - not
  the north wall;
  real-wall crossings
  at X22 and X26
  (verticals running
  north); round
  columns straddle
  Y19 at X9.1 and
  X14.0. X20 door can-
  didates rows ~20,
  ~21, ~24, ~28; grid
  gap rows 26.6-27.0.
  Hall south edge =
  Y31 band (rooms 10/
  13 along rows
  31-34), gate-room
  opening X10.2-10.8
  seated. NEXT: hscan
  Y18, vscan X22,
  vscan X26, X8
  eye-check rows
  31-34.
  HALL SKELETON v2
  (run-length strips,
  2026-11-05):
  NORTH WALL = Y18,
  REAL, spanning
  X10-X22 (sustained
  SOLID w/ vertical
  crossings; west of
  X10 only grid).
  EAST: X20 grid
  full-length
  (dead as edge);
  X22 = vertical wall
  w/ real segments
  rows ~16-18 and
  21.9-23.1 (SOLID
  0.88) + DOOR ZONE
  rows 23.1-25.9
  (GLYPH 0.62-0.69,
  likely the doors
  into the east
  block); south of
  26 X22 = grid.
  X26 = NO vertical
  wall (open line);
  horizontal walls
  cross it at Y22
  (21.9-22.2), Y26,
  Y29.8-30.1 - east
  block rooms are
  bounded by HORIZ-
  ONTAL walls; door
  at X26 row 23.0
  (GLYPH 0.56) sits
  at the Y22/Y23
  junction area -
  likely door in the
  Y22 wall at X26.
  WEST: X9 real wall
  rows 22-30;
  X8 rows 31-34 =
  GRID (sustained
  0.19-0.25 = grid-
  thin, no wall) -
  room 14's east
  edge has NO ink
  wall until gate
  room's X10; the
  dashed 1B tower
  lines at X8.8-9.9
  are the only drawn
  boundary there.
  OPEN: hall NW
  corner rows 18-22
  west of X10 (no
  Y18 wall, X9 grid)
  - what bounds it?
  X22 DOOR ZONE
  (Curtiss, 2026-11-05,
  panel 1 eye-check):
  the X22 wall
  (great hall's east
  edge, rows 21.5-
  26.5) holds FOUR
  SETS OF DOUBLE
  DOORS connecting
  the hall to the
  east block rooms.
  Ink: solid wall
  21.9-23.1, glyph-
  heavy zone 23.1-
  25.9 (two merged
  scan segments = 4
  doors), grid south
  of 26. Exact row
  pinning per door
  (fine scan) only
  if the edge list
  needs it. NOTE:
  his earlier "2 sets
  of double doors"
  sighting (east
  composite, X11.5-
  16.8 area) may be
  ADDITIONAL doors
  elsewhere - con-
  firm location.
  Pending: panel 2
  (X26 door), panel
  3 (hall NW corner),
  sec1, gate room
  "10".
  ROOM 5 EAST BLOCK
  (Curtiss, 2026-11-05,
  panel 2): the door
  at X26, row 23 =
  DOOR IN ROOM 5's
  NORTH WALL, at the
  end of a hallway
  that runs to X26.
  So: room 5 sits
  south of the Y22-
  23 wall, ~X25-27,
  east block; a
  hallway ends at
  the door (hallway
  along/near X26,
  connecting toward
  the 4-double-door
  X22 row). East
  block naming
  started (5, plus
  10-candidate gate
  room, 13 seated).
  Pending: panel 3
  (hall NW corner),
  the earlier "2
  sets of double
  doors" location,
  sec1, gate room
  "10".
  HALL NW CORNER
  (Curtiss, 2026-11-05,
  panel 3 eye-check):
  the great hall's
  NW corner (X7.5-
  X10.5, rows 16.5-
  22.5) = OPEN ENTRY
  + DOUBLE DOORS +
  grid - NOT a walled
  corner. The hall
  opens NW toward
  the 18/18A area;
  the Y18 north wall
  runs only east of
  the entry. Exact
  entry/door X posi-
  tion unpinned
  (fine scan if the
  edge list needs
  it). GREAT HALL
  EDGE LIST COMPLETE:
  W = X9 wall rows
  22-30; NW = open
  entry + double
  doors; N = Y18
  wall X10-X22; E =
  X22 wall w/ FOUR
  double doors rows
  ~23-26; S = Y31
  band w/ gate-room
  opening X10.2-
  10.8 (rooms 10?/13
  along rows 31-34);
  interior: fire pit
  ~X15 row 22 +
  round columns (X9.1/
  X14 straddling
  Y19, + near pit);
  label "11" at the
  pit. Remaining
  upper-level work:
  east block rooms
  interior (5's
  hallway, 9/10/10A
  hunt), north strip
  remaining labels,
  sec1 + gate "10"
  verdicts, then
  splice assembly
  anchored on 18A
  stair.
  EAST BLOCK WALLS v1
  (hscans, 2026-11-05):
  Y22 wall = X21.8-
  X27.1 SOLID, door
  at ~X27.3-28.1
  (glyph zone);
  NOTE the X26 door
  (room 5's north
  door) draws its
  leaf JUST SOUTH of
  the continuous Y22
  wall line (drawn-
  face class again -
  wall reads SOLID at
  the door X). Y26
  wall = X21-X27.1
  SOLID with a DOOR
  GAP ~X27.1-27.9 ->
  the Y22 and Y26
  doors STACK at
  X27.2-28 = an N-S
  passage/hallway
  through the east
  block at X~27.5.
  Verticals crossing
  Y22/Y26 at ~X29,
  X31, X32 (thin) +
  structure at east
  junction (X32.3-
  32.7 SOLID at Y26,
  gap, X32.8-33 =
  building east
  wall X33). Y30 =
  HEAVY STRUCTURE
  ZONE X22-X33:
  alternating SOLID
  spikes (every X
  line) + thick
  GLYPH 0.56-0.62
  sustained = door
  gallery / colon-
  nade candidate -
  needs eyes. Room 5
  south of Y22 at
  ~X25-27. Pending:
  Y30 verdict, X27.5
  passage route,
  labels (9? 10/10A?
  1-8 quarters?), X29/
  X31/X32 verticals
  wall-vs-grid.
  EAST BLOCK = THE
  NUMBERED QUARTERS
  (Curtiss, 2026-11-05,
  Y30 panel): the Y30
  structure row
  holds: a SINGLE
  DOOR hallway ->
  ROOM 4, and a
  DOUBLE DOOR room 6
  -> ROOM 7. Rooms
  pinned so far: 4,
  5 (south of Y22,
  ~X25-27, N door at
  X26), 6, 7 - east
  block is the 1-8
  numbered quarters
  per module. Y30
  glyph segments
  (X22-33) hold
  these doors; exact
  door-to-segment
  mapping unpinned
  (next: which
  segment is the
  4-door, which the
  6-7 double). Hall-
  way = the X27.5 N-S
  passage candidate
  (panel 2 verdict
  pending). Panel 3
  (east junction
  rooms) pending.
  EAST-JUNCTION
  PANEL 3 (Curtiss,
  2026-11-05): the
  structure at the
  east wall junction
  (X31-33.6, rows
  22-30; ink X32.3-
  32.7 SOLID at Y26)
  = a FIREPLACE
  against the build-
  ing's east wall
  (X33). Hearth/
  fireplace class
  now has 4 members
  (24, 14, X14 can-
  didate, east junc-
  tion). The room it
  heats: unnamed yet.
  Pending: panel 2
  (X27.5 passage),
  Y30 door-to-room
  position pinning
  (single door -> 4,
  double -> 6/7),
  room names at the
  east wall, sec1,
  gate "10".
  X27.5 HALLWAY =
  SECRET PASSAGE
  (Curtiss, 2026-11-05,
  panel 2): the N-S
  hallway at ~X27.5
  STARTS AT ROOM 11
  (the great hall)
  THROUGH A SECRET
  DOOR and ENDS IN
  ROOM 6. The
  stacked doors at
  X27.2-28 (Y22 door
  X27.3-28.1 + Y26
  gap X27.1-27.9)
  sit along it.
  NEW DOOR CLASS:
  SECRET DOOR (hall-
  side entry hidden;
  expect faint/atyp-
  ical ink - one of
  the X22 door-zone
  glyphs rows 23-26
  may actually BE
  the secret door,
  not one of the 4
  doubles - UNRECON-
  CILED: 4 doubles +
  secret door vs the
  X22 glyph segments,
  revisit). Room 6 =
  hallway's south
  end (south of Y30,
  ~X27). Pending:
  Y30 door pinning
  (single->4, double
  6->7), east-wall
  room names, sec1,
  gate "10".
  MAIN ENTRANCE
  PINNED (Curtiss,
  2026-11-05): the
  steading's MAIN
  ENTRANCE is at
  X20, rows 36-39 -
  the south face,
  in the south block
  (SE of the boundary
  wall, east of the
  porch chamber).
  RULING: the bound-
  ary-wall door at
  X10.4-11.0 is NOT
  the main entrance
  (side/secondary);
  the SE quadrant's
  front-entry path
  runs through the
  south block at X20.
  South block now =
  entry front (rows
  34-40, ~X12-X24);
  entrance structure
  ink at X20 rows
  36-39 unprobed.
  Pending: X20
  entrance probe,
  Y30 door pinning,
  east-wall room
  names, gate "10",
  the "2 sets of
  double doors"
  sighting.
  SOUTH BLOCK INK
  (5px probe, 2026-
  11-05): X17-X23
  rows 34-40 = FULL
  CELL GRID (thin
  walls every lat-
  tice line both
  directions, ~5
  cols x 6 rows of
  1-pitch cells;
  same class as west
  wing grid). South
  wall Y40 = real,
  thick, solid X17-
  X21.8, with ONE
  GAP at X~21.9-23.0
  rows 39.7-40.2 +
  gray path dashes
  outside (row 40.6)
  + seated road
  (X24-27 rows
  38.6-39.1) running
  up to it. Entrance
  structures (glyphs
  + parallel thin
  lines X21.9-23) at
  rows 36.9-37.9.
  CONFLICT: Curtiss
  ruled main entrance
  "X20, rows 36-39";
  ink says the only
  wall opening is X22-
  23 at Y40. TIEBREAK
  PENDING: composite
  X19-X24 rows 34.5-
  41 (gap at X22-23
  vs drawn-face door
  at X20).
  MAIN ENTRANCE
  RESOLVED (Curtiss,
  2026-11-05): the
  steading's main
  entrance = WIDE
  DOUBLE DOORS at
  X21.9-23.0 in the
  Y40 south-wall
  gap - WIDER than
  all other double
  doors on the map
  (~1.1 pitch vs the
  0.55-0.8 doubles
  elsewhere). Con-
  flict resolved in
  favor of the ink
  gap; his "X20 rows
  36-39" = the
  entrance compound
  (cell-grid block
  X17-23 rows 34-40).
  Approach: road (X24-
  27) + gray path row
  40.6 leading to the
  doors. SE QUADRANT
  NOW COMPLETE except
  interior detail:
  gate room "10"
  confirm, Y30 door
  pinning (single->4,
  double 6->7), east-
  wall room names,
  the "2 sets of
  double doors"
  sighting (X11.5-16.8
  panels). Then splice
  draft assembly
  anchored on 18A
  stair pin.
  GATE ROOM
  UNLABELED (Curtiss,
  2026-11-05): the
  gate room (X10-X11,
  rows 31-34) has NO
  printed number -
  panels show walls,
  door, grid only.
  The OCR "1" at
  X11.2 row 31 =
  door/wall pooling
  junk (same class
  as the n-strip
  "11"s). Gate room
  identity falls back
  to module adjudica-
  tion for the edge
  list (candidate
  "10" per module
  numbering, but
  UNCONFIRMED from
  ink - do not assert
  a number from ink).
  CHECKLIST: Y30 door
  pinning (single->4,
  double 6->7), east-
  wall room names,
  the "2 sets of
  double doors"
  sighting, secret
  door location on
  X22 wall. Then
  splice draft.
  Y30 RULING
  (Curtiss, 2026-11-05):
  in the east-block
  Y30 gallery panel,
  the SINGLE door =
  room 4's door (off
  the hallway); the
  DOUBLE DOORS =
  room 7's door.
  WORKFLOW ADJUSTMENT:
  rooms w/o printed
  labels get DESCRIPT-
  IVE names (gate
  room, fireplace
  room, hearth room,
  secret hallway,
  porch chamber);
  do not ask Curtiss
  to name unlabeled
  ink - he identifies
  by drawn features,
  labels only when
  printed. Ink note:
  Y30 reads thick
  (0.56-0.62) over
  X22.2-27 and
  X29.9-32.8 = like
  a double-line wall;
  named doors likely
  drawn adjacent to
  the wall line
  (drawn-face class);
  exact door X-pins
  deferred - room
  identities + door
  classes are pinned,
  door positions on
  Y30 are approxi-
  mate. Remaining
  questions: the "2
  sets of double
  doors" sighting
  (X11.5-16.8 area),
  secret-door spot
  on X22 wall. Then
  splice draft.
  X22 DOORS
  ADJUDICATED
  (Curtiss, 2026-11-05):
  ALL FOUR double
  doors on the X22
  wall are NORMAL
  doors - none is
  the secret passage
  entry. The secret
  hallway's door
  from room 11 is a
  separate hidden
  SINGLE door some-
  where on the hall
  boundary (exact
  spot not visible/
  not yet pinned -
  drawn hidden, do
  not scan for it
  with normal ink
  classes). Remaining
  open question: the
  "2 sets of double
  doors" sighting
  (X11.5-16.8 area,
  room 13 neighbor-
  hood) - confirm or
  retire. Then splice
  draft assembly
  anchored on 18A
  stair pin.
  DOUBLE DOOR
  INVENTORY (Curtiss,
  2026-11-05): the
  map's double doors
  (his enumeration):
  (1) NORTH BOUNDARY
  WALL doubles ->
  the yard; (2) DOUB-
  LES leading to
  ROOM 23; (3) EAST
  BOUNDARY WALL
  doubles, ROOM 22 ->
  the yard; (4) SOUTH
  WALL OF ROOM 22
  doubles -> ROOM 6.
  ROOM 22 = new east-
  block room, north
  of room 6, against
  the east boundary
  (candidate: the
  fireplace room at
  X31-33.6 rows
  22-30 - CONFIRM
  PENDING). The "2
  sets" sighting is
  RESOLVED/RETIRED -
  absorbed into this
  inventory. OPEN
  RECONCILIATION:
  earlier panel
  verdict said 4
  sets of doubles on
  the hall's X22
  wall (rows 23-26) -
  are those part of
  this inventory or
  additional to it?
  Then splice draft
  assembly anchored
  on 18A stair pin.
  DOUBLE DOOR
  INVENTORY FINAL
  (Curtiss, 2026-11-05
  tiebreak): the
  "4 sets of double
  doors" verdict =
  THESE four doors
  (n-boundary->yard,
  ->23, e-boundary
  22->yard, 22-south-
  >6), NOT a door row
  on the hall's X22
  wall. The X22
  glyph zone (rows
  23.1-25.9) is
  UNADJUDICATED INK
  (not 4 doubles;
  may hold the
  secret door +
  drawn-face doors -
  revisit only if
  the edge list
  needs it). EAST
  JUNCTION CORRECT-
  ED: the X31-33.6
  structure = a
  DOUBLE-WIDTH FIRE-
  PLACE IN ROOM 6;
  only TWO east-wall
  fireplaces exist on
  the map; room 6 =
  the east-wall room
  (rows ~22-30,
  X27-33) with the
  double-width
  fireplace against
  X33; the secret
  hallway ends in
  room 6; room 22
  sits NORTH of room
  6 (22-south doubles
  ->6). Fireplace
  count: 24, 14,
  X14 candidate,
  double-width in 6,
  +1 more east-wall
  fireplace some-
  where. ALL UPPER-
  LEVEL CHECKLIST
  ITEMS CLOSED ->
  splice edge list
  draft assembly.
  SPLICE EDGE LIST
  DRAFT - UPPER
  LEVEL (assembled
  2026-11-05 from all
  seated rulings;
  ANCHOR: the 18A
  STAIRS DOWN at
  (5,18)-(6,18), k
  5.05-6.9, Y17/Y18
  walls butt the
  stair mass):
  18A: 4x4 grid
  X3-X7 x Y14-Y18;
  label 18A rows
  15.0-15.3 cols
  5.2-6.3; N door Y14
  k3.4-3.75 from the
  X3-X4 west strip;
  threshold door
  from 18 (X6-X7,
  rows 13-14).
  WEST WING: cell
  grid X2-X9 rows
  18.5-31 (X2/X8
  thick, X9 thick
  from 22.5); room
  17 = kitchen west
  annex rows 19-22,
  label rows 20.4-
  20.9, Y21 door ->
  west hallway, E
  open entryway rows
  22.6-24 -> great
  hall; room 15
  (label rows 26.3-
  27.0) + room 16
  (label rows
  25.7-26.9); Y30/31
  band: 15's door
  k4.3-4.7, hallway
  door k5.2-6.4,
  16's door k7.4-8.1
  - ALL open into
  room 14.
  ROOM 14: ONE open
  hall rows 31-34
  X2-X9; label
  X5.4-6.5 rows
  32-33; hearth
  X5.3-7.4 rows
  33-34; drawn-
  closed door in
  the y2541 wall
  (drawn-face); S =
  boundary wall
  Y34 solid X2-X9.
  GATE ROOM
  (unlabeled):
  X10-X11 rows
  31-34, thick 24px
  walls; N opening
  X10.2-10.8 into
  the great hall; S
  door X10.4-11.0
  through the
  boundary wall =
  SECONDARY entrance;
  porch chamber
  south of it.
  ROOM 13: X12-X13
  rows 31-34, label
  rows 30.9-31.9;
  X14 thick wall;
  hearth-room (desc.)
  X13.6-14.6 rows
  30.7-33.9, hearth
  mass against X14.
  GREAT HALL (ROOM
  11): N wall Y18
  X10-X22; W wall X9
  rows 22-30; NW
  corner = OPEN
  ENTRY + double
  doors (toward
  18/18A); S = Y31
  band, opening
  X10.2-10.8 to gate
  room; E = X22 wall
  (segments rows
  ~16-18, 21.9-23.1;
  glyph zone rows
  23.1-25.9 = UNADI-
  CATED INK, not a
  door row); HIDDEN
  single SECRET DOOR
  somewhere on the
  boundary -> the
  secret hallway.
  Interior: fire pit
  ~X15 row 22 + "11"
  label; round
  columns (X9.1 +
  X14 straddle Y19,
  more at the pit);
  17's entryway
  pierces the W wall
  rows 22.6-24;
  interior door
  X11.1 row 23.
  SECRET HALLWAY:
  room 11 -> hidden
  door -> S along
  ~X27.5: Y22 door
  X27.3-28.1, Y26
  gap X27.1-27.9 ->
  ends in room 6.
  EAST BLOCK (the
  numbered quarters;
  HORIZONTAL walls
  Y22 X21.8-27.1, Y26
  X21-27.1, Y30 =
  thick double-line
  wall X22-33):
  room 5 south of
  Y22-23, X25-27, N
  door at X26 (leaf
  drawn south of the
  wall); room 22
  north of room 6 -
  S-wall doubles ->
  6, E-boundary
  doubles -> yard;
  room 6 = east-wall
  room ~X27-33 rows
  22-30 w/ the
  DOUBLE-WIDTH FIRE-
  PLACE against X33
  (X31-33.6), S end
  of the secret
  hallway, doubles
  -> room 7 (Y30);
  room 4 off the
  hallway, single
  door (Y30); room 7
  via the 6->7
  doubles. Verticals
  X29/X31/X32 thin
  (wall-vs-grid
  unadjudicated).
  X26 = open line;
  26-row-23 door
  sits at the Y22/Y23
  junction (room 5's
  N door).
  DOUBLE DOORS
  (complete inven-
  tory): (1) north
  boundary wall ->
  yard; (2) leading
  to room 23; (3) E
  boundary wall,
  room 22 -> yard;
  (4) room 22 S wall
  -> room 6.
  NORTH STRIP +
  OUTBUILDINGS:
  rooms 19-25 + A;
  label 25 seated
  (~X21.5-24.5 rows
  2.3-4.3); 24's
  hearth X30 rows
  2.5-3.6; 23 =
  guard room south
  of Y6 cols 27-31;
  outbuilding doors
  Y6 k30.0-30.6
  (24<->23) + west
  strip k~28 rows
  5.5-6 (25/A<->
  23); N boundary
  doubles -> yard.
  MAIN ENTRANCE:
  WIDE double doors
  X21.9-23.0 in the
  Y40 south-wall gap
  (wider than all
  other doubles);
  compound = cell-
  grid block X17-23
  rows 34-40; road
  (X24-27 rows
  38.6-39.1) + path
  row 40.6 approach.
  TOWER 1B: dashed
  extension lines
  (X8.8-9.9 above
  Y31, X9 rows
  33-34, row-37
  ~X11.1) = upper-
  level tower
  projection, keyed
  "1B".
  SOUTH BLOCK: porch
  chamber S of
  boundary wall W;
  building extends
  S of Y34 east of
  X12; entrance
  compound E; road
  outside at rows
  38.6+ X24+.
  FEATURES: hearths
  24, 14, hearth-
  room X14, double-
  width in 6, + 1
  more east-wall
  fireplace unpin-
  ned; round
  columns; fire pit.
  SPLICE TODOs: (a)
  module-key names
  for unlabeled
  rooms (gate room,
  hearth room,
  hallway); (b) Y30
  door X-pins (iden-
  tities pinned,
  positions approx);
  (c) secret-door
  spot on hall
  boundary; (d) X2
  fat band identity
  (chimney-stack
  candidate, c6);
  (e) second east-
  wall fireplace.
  MAP BATCH
  PIPELINE DECISION
  (user-set,
  2026-11-05): the
  map work scales to
  HUNDREDS+ of maps;
  the interactive
  probe-adjudicate
  method is too slow
  per map. The maps
  go into the REPO
  AS DATA, and the
  seated doctrine
  becomes an AUTO-
  MATED EXTRACTION
  PIPELINE (cv2 +
  numpy + skimage on
  Termux, pkg
  python-opencv):
  (1) per-map LATTICE
  AUTO-FIT (row/col
  ink histograms ->
  pitch+phase; no
  hand-measured X0/
  P/Y0/Q per map);
  (2) thickness
  separation via
  erosion (thick
  walls vs thin grid
  vs glyph blobs -
  automates lessons
  x10/x11);
  (3) connected-com-
  ponent blob inven-
  tory w/ regionprops
  stats (coords,
  area, aspect,
  solidity);
  (4) shape classifi-
  cation vs seated
  exemplars (16's
  door leaf, label
  pairs, hearth,
  column circle) +
  Tesseract doctrine
  for label digits;
  (5) per-map edge-
  list emission in
  the splice draft
  format (walls/
  doors/rooms/featur-
  es + confidence
  class);
  (6) eyes adjudicate
  ONLY the residue
  (drawn-face,
  secret, ambiguous)
  via ONE stitched
  composite per map
  (delivery rule
  stands). Compute =
  seconds/map; human
  cost = table
  review + residue.
  Tool ships per
  R515/R608 rules:
  ONE continuous
  76-col folded b64
  block in a single
  canvas body, md5 +
  expected line
  count stated.
  AWAIT GO before
  authoring.
  TERMUX CV STACK
  (verified,
  2026-11-05): full
  batch-pipeline env
  LIVE on Termux:
  numpy 2.5.4
  (pkg python-numpy),
  scipy 1.18.1 (pkg
  python-scipy, TUR),
  cv2 5.0.0 (pkg
  opencv-python +
  python-opencv-python,
  TUR; needs pkg
  dbus for
  libQt6DBus),
  scikit-image
  0.26.0 (pip
  --no-build-
  isolation after
  pip install
  meson-python
  meson Cython
  pythran; built
  on-device,
  android_24_arm64
  wheel CACHED in
  pip cache ->
  reinstall is one
  command).
  cv2 import fix
  chain: missing
  libdbus-1.so ->
  pkg install
  dbus. Install
  route pattern
  for future
  scientific pkgs:
  pkg/TUR for
  compiled libs,
  pip --no-build-
  isolation +
  meson-python
  for source
  builds. All
  four verified
  importing
  together
  (regionprops +
  skeletonize +
  cv2 matchShapes
  all OK).
  MAPBATCH V1 AUTHORED
  AND DELIVERED
  (2026-11-05, go
  given): tools/
  mapbatch.py per
  the 6-stage spec -
  lattice auto-fit
  (FFT+refine
  period/phase),
  thickness separ-
  ation (distance
  transform >=
  wall_frac*pitch +
  constrained-
  dilation wall
  reconstruction),
  blob inventory
  (connectedComp-
  onentsWithStats:
  line/glyph/featur-
  e/mass classes +
  Hu moments), OCR
  proposal pass
  (--ocr, whitelist
  0-9S), lattice-
  indexed wall runs
  (axis,line,from,
  to) + door-void
  gap candidates,
  JSON emission
  (positions=auto,
  identities=residu-
  e doctrine), ONE
  stitched residue
  composite PNG.
  DELIVERED per
  R515/R608 then
  AMENDED on
  Curtiss's call
  (2026-11-05): raw
  Python source in
  a code canvas is
  fine - the b64
  rule guards
  CHAT paste, not
  canvas bodies.
  Canvas "mapbatch-
  tool" (type code,
  language python)
  body = the source
  ITSELF, no b64.
  File md5 17b453d412
  07bc543e24813c417c
  a37d, 298 lines,
  <=78 col, py_comp-
  ile clean. Ritual:
  save canvas body
  to tools/mapbatch.
  py -> md5sum gate
  -> py_compile ->
  run. NOT yet
  run against real
  ink - FIRST RUN
  gate: map-006.jpg
  with --lattice
  181.95,64.2742,
  482.0,64.5875,
  verify wall runs
  vs the seated
  record (west X2
  rows ~10-34,
  north row 1 X6-
  east, south Y34,
  east X33 rows
  1-34), then
  auto-fit mode
  must recover
  pitch ~64.27/
  64.59. Exemplar
  matchShapes
  (16's door leaf
  etc.) deferred to
  v2 after map-006
  validation.
  MAPBATCH V1.1
  (2026-11-05, after
  the first-run
  gate caught two
  defects): (1)
  OUTDIR BUG - tool
  crashed writing
  to a nonexistent
  --outdir; fixed
  with os.makedirs
  (exist_ok=True).
  (2) AUTO-FIT
  FAILED ON MAP-
  006 (Y pitch
  49.35 = page
  text-line
  spacing, X phase
  off ~2 pitches) -
  the map-006 gate
  did its job.
  FIX: _dense_span
  autocrops to the
  dense ink block
  (isolates the
  map from page
  text), _profile_
  fit now takes
  top-6 FFT peaks
  x17 subperiod
  candidates each,
  scores by MEAN
  ink mass per
  lattice line
  (wall bands
  outweigh text),
  prefers the
  FUNDAMENTAL
  period among
  90-percent-score
  candidates (a
  2x harmonic
  can't steal it);
  added a pitch-
  ratio-suspect
  WARNING (ratio
  >0.05 from 1).
  v1.1: 333 lines,
  md5 b20381d79c4e
  f4baaa1888130d30
  14ea, canvas
  "mapbatch-tool"
  updated (raw
  source body).
  Also: v1 save
  hashed 80ed2763
  on Termux vs
  authored 17b453
  d4 - py_compile
  OK + functional
  run = line-
  ending/whitespace
  delta class
  (R608
  fingerprint
  lesson), super-
  seded by v1.1's
  gate. FIRST-RUN
  GATE RERUNS:
  pass 1 (seated
  lattice) +
  pass 2 (auto-fit
  recovers
  ~64.27/64.59
  with sane X0/
  Y0 phase);
  phase-mod
  check: seated
  X0 181.95 mod
  64.2742 = 53.4
  (autofit phase
  may be any
  congruent line).
  PASS 1 LANDED
  (2026-11-05):
  seated-lattice
  run WORKS END-
  TO-END on
  map-006 - 239
  wall runs, 68
  voids, 268 blobs
  (203 residue),
  composite
  emitted.
  /tmp is NOT
  writable on
  Termux - use
  $TMPDIR or ~
  for outdirs.
  PASS 2 FAILED
  AGAIN, diagnos-
  ed: Y pitch
  127.92 = ~2x the
  true 64.59 - a
  HARMONIC stole
  the fit (room
  structure puts
  more FFT power
  at pitch
  multiples);
  X 63.75 = 0.8
  percent off
  (coarse refine
  step). The
  ratio WARNING
  tripwire fired
  as designed.
  v1.2 FIX:
  every FFT-peak
  candidate
  spawns /2 and
  /3 subdivisions
  (a candidate
  near the true
  pitch now
  always exists),
  eligibility
  floor 0.8 (mean-
  mass-per-line
  at pitch and
  2x are near-
  equal by
  construction -
  fundamental
  wins on
  min-period),
  FINE REFINE
  pass (per
  +-=1.5 in
  0.05 steps, off
  +-=0.5, 0.05)
  chases the
  X sub-pitch
  error. v1.2:
  353 lines,
  md5 9d0adab72c7
  fc4597ff9b4555a
  0bcbc9, 13106
  bytes. OPEN:
  the md5 gate
  delta recurs
  on his saves
  (v1.1 save
  e48dbc38 vs
  authored
  b20381d7) with
  py_compile OK
  each time -
  SOLVED
  2026-11-05: the
  save path
  appends ONE
  extra trailing
  newline per
  save (od tail
  )\n\n; sed CRLF
  hash == raw
  rules out \r).
  STANDING
  TERMUX-SIDE
  GATE for tool
  saves:
  python3 -c
  hashlib md5 of
  read().rstrip
  (b'\n')+b'\n' -
  normalizes
  trailing
  newlines to
  exactly one,
  must print the
  authored md5.
  v1.2 save
  CONFIRMED
  byte-exact
  this way
  (9d0adab72c7f
  c4597ff9b4555a
  0bcbc9).
  VALIDATION
  COMMAND for
  pass-1 record
  check: print
  V runs on
  lines 2,33 and
  H runs on
  lines 0,40 +
  their voids
  from the
  extract JSON.
  PASS 1 RECORD
  CHECK RAN
  (2026-11-05):
  V2 runs
  (17,41),(43,43)
  w/ void (42,42);
  V33 clean
  (7,41); H0
  (8,35); H40
  (12,24) - the
  LATTICE
  INDEXING reads
  the map in
  seated
  coordinates
  (offsets vs
  the session
  record are
  label/margin
  bands, the
  residue class
  - indexing
  PROVEN).
  v1.2 PASS 2
  FAILED
  IDENTICALLY
  (Q 127.87) -
  ROOT CAUSE
  FOUND: the fit
  ran on the
  FULL PAGE,
  not the map -
  _dense_span's
  15-percent-of-
  max threshold
  lets text
  blocks into
  the "dense
  span", and
  page text
  column
  periodicity
  (X: 2550/40 =
  63.75 EXACTLY)
  outscored the
  wall comb.
  v1.3 FIX (the
  substrate
  change): fit
  on a WALLS-
  ONLY layer -
  _wall_layer:
  stroke-width
  threshold
  dist >=
  0.35*max
  (scale-free,
  kills grid/
  text), constr-
  ained dilation
  rebuild; fit
  on THAT
  profile (no
  text mass by
  construction)
  + autocorr
  FUNDAMENTAL
  (smallest
  strong local
  peak - the
  graph grid
  sits on every
  lattice line,
  so the comb
  has no parity
  for a 2x
  harmonic to
  exploit) +
  vectorized
  joint fine
  refine
  (+-3 in 0.05
  steps). v1.3:
  338 lines,
  md5 c5fafb71
  09696eb479257
  038f429372e,
  12666 bytes,
  canvas
  updated.
  GATE (norm-
  alized):
  rstrip(b'\n')
  +b'\n' md5
  must equal
  c5fafb71...
  v1.3 PASS 2
  FAILED with
  P=250/Q=256.25
  (~4x pitch,
  round numbers,
  no ratio warn-
  ing - ratio
  0.98 is
  useless as the
  sole tripwire)
  - ROOT CAUSE:
  the WALL layer
  is the WRONG
  SUBSTRATE for
  the fit: G1
  walls sit on
  lattice lines
  IRREGULARLY
  (seated Y-lines
  5,6,9,10,11,13,
  14,17,18,22,26,
  34,40 - spac-
  ings 1,3,1,1,2..
  no comb fundam-
  ental), so wall
  autocorr had no
  pitch peak and
  accidental
  ~250px structure
  won. The comb
  at EVERY lat-
  tice line is
  the GRAPH GRID
  - which v1.3
  excluded by
  design. v1.4
  FIX: substrate
  = _grid_layer,
  LENGTH-OPENED
  structure -
  morphological
  opening with
  kernels at 15
  percent of each
  image dimension
  keeps only long
  straight runs
  (grid, wall
  bands, frame -
  all ON lattice
  lines) and
  kills all text
  glyph strokes
  (<100px) - text
  mass excluded
  by construction,
  grid comb intact.
  Added a PITCH-
  RANGE tripwire
  (30-120px for
  10ft-at-300dpi
  maps). v1.4:
  341 lines, md5
  368a4caac8fcb15
  e983422d99aadfd
  11, 12975 bytes,
  canvas updated.
  NOTE: his diag-
  nostic crashed
  on a path typo
  (pdf/ vs ~/pdf/)
  - always
  expanduser map
  paths in
  Termux diag-
  nostics.
  v1.4 PASS 2
  RAN: P=63.75/
  Q=64.05, no
  warnings, 185
  runs - RIGHT
  CLASS, ~0.52
  px/line LOW on
  BOTH axes.
  ROOT CAUSE
  (found via the
  seated record
  itself): the
  printed GRAPH
  GRID is ~1
  percent SMALL-
  ER than the
  wall lattice
  (the record's
  own numbers:
  grid spacing
  19.7px vs wall
  pitch 19.95px
  at the 726-copy
  scale) - v1.4
  fitted the
  GRID'S lattice,
  a real comb but
  the WRONG one
  (registration
  layer, not
  truth; the
  grid-removal
  doctrine says
  exactly this).
  v1.5 FIX
  (synthetic-
  proven in
  sandbox, pure-
  python sim of
  the algorithm):
  GRID-ANCHOR
  WALL-REFINE -
  the grid ac
  fundamental is
  the robust
  coarse anchor
  (a clean comb);
  the refine then
  scores the
  WALL profile
  (_wall_layer
  restored, the
  v1.3 substrate)
  in a NARROW
  window (max
  (1.0, 2.5
  percent of the
  anchor)) - the
  window excludes
  harmonics and
  foreign combs;
  walls sit on
  the target
  lattice by
  definition.
  Synthetic
  proof: grid at
  63.75 + walls
  at 64.2742 on
  the seated
  line subset ->
  recovered per
  64.25/64.15,
  phase mod per
  MATCHES seated
  53.40, holds
  at wander +-
  5.6px (seated
  residual
  class) and
  whether the
  grid comb
  spans the map
  or the full
  page. VALIDAT-
  ION for his
  run: P/Q near
  64.27/64.59
  AND fitted
  phase mod
  pitch ~ 53.40
  (X) / 29.89
  (Y) - any
  wall line is
  congruent mod
  pitch to the
  seated X0/Y0.
  v1.5: 367
  lines, md5
  fd287af126a93a
  223bc4ee9c3f9a
  cdad, 13966
  bytes, canvas
  updated.
  v1.5 PASS 2
  FAILED DIAGNOS-
  TICALLY (better
  than ever): X
  phase mod P =
  0.25 - the wall-
  layer scoring
  found its best
  "wall line" at
  x=0.25, and
  0.25+40*63.75 =
  2550 = the RIGHT
  edge - the SCAN
  FRAME (page-edge
  shadow bands)
  dominates the
  wall layer: it
  is the thickest
  ink on the page,
  dist.max() comes
  from IT, the
  stroke threshold
  inflates, and
  the interior
  walls drop out.
  The frame also
  retro-explains
  v1.3 (250/256:
  frame + boundary
  walls) and the
  recurring
  63.75 = 2550/40
  (any period
  dividing the
  page width
  exactly scores
  both frame
  edges).
  LOCAL ANALYSIS
  PATH OPENED
  (2026-11-06):
  sandbox CANNOT
  pip numpy/cv2 -
  wrote jdec.py,
  a PURE-STDLIB
  baseline JPEG
  decoder (Y
  plane, huffman
  + IDCT, chroma-
  IDCT skipped;
  proven on a
  real color
  JPEG, 550x368 in
  1.9s - scales to
  ~80s for a
  grayscale
  2550x3300 page).
  Landed in canvas
  "jdec-tool"
  (265 lines, md5
  dfd8739a5974436
  e8f0f3bbf7b86e38
  - reusable trace
  tooling per the
  pixel-work
  precedent).
  anaprof.py (work
  dir) reproduces
  the fit stages
  pure-python:
  OTSU, edge-band
  report, longest-
  run structural
  profiles (the
  length-opening
  analog), thick-
  run wall
  profiles (the
  distance-thresh
  analog), all
  compared against
  the seated
  lattice.
  UPLOADS ARE
  STUBS (confirmed
  again: g1map_
  fullres.jpg 141
  bytes, map-000
  .jpg 135 - the
  vision gate is
  the only uploads
  inspection
  route, no raw
  bytes).
  NEXT: Curtiss
  pushes the
  map-006 raster
  to extract/g1/
  in the repo
  (the doctrine
  location anyway -
  the raster was
  never committed),
  then it's pulled
  via raw.githubuser
  content and the
  frame problem is
  diagnosed
  against REAL ink
  locally, the fix
  proven, ONE
  final tool
  reissue.
  RASTER LANDED
  (2026-11-06):
  map-006.jpg
  (2550x3300) pushed
  to extract/g1/ in
  the repo (push
  b6915511..
  731bd7d9), pulled
  via raw.github,
  Y-plane decoded
  with jdec (sandbox
  pip numpy/cv2
  forbidden - jdec
  is the vision
  gate for rasters).
  FRAME HYPOTHESIS
  DEAD: page borders
  are BLANK (row/
  col ink 0 first/
  last 60 lines) -
  v1.5's x=0.25
  lock was the
  GRID comb at
  2550/40, not a
  scan frame.
  TWO COMBS ON THE
  PAGE: (1) printed
  graph grid -
  thin lines
  (1-4px), complete
  at every line,
  dungeon-clipped;
  (2) WALL lattice
  = the seated comb
  - thick bands
  (12-38px),
  IRREGULAR lines
  (X walls: 2,5,6,
  9,10,11,14,18,28,
  33; Y ~0,6,10,14,
  18,22,26,29,30,31,
  34,40), wander
  +-5.6px. Combs
  cross near line
  ~16(X)/~22(Y);
  drift ~0.52px/
  line; wall/grid
  pitch ratio
  1.00874(X)=
  1.00875(Y) - a
  SHARED PRINT-
  SCALE CONSTANT,
  the key discrim-
  inator. v1.5's
  real failure:
  _wall_layer
  0.35*dist.max
  threshold
  poisoned by a
  giant intercon-
  nected ink web
  (93.7 percent of
  ink in one comp);
  grid comb always
  wins comb scoring
  (regular vs
  wandering); Y
  axis degenerate
  (pseudo-comb
  Q=64.298/47.07
  has MORE
  inliers than
  truth) - only
  the RATIO CROSS-
  CHECK breaks the
  tie. v1.6
  ALGORITHM
  (pure-python
  prototypes rep21-
  28, validated on
  real pixels):
  _open_layers
  ho/vo 15-percent
  length openings
  -> coarse
  autocorr period
  ~64; _bands
  (gap 2) clusters
  profile lines;
  THIN bands (w<=5)
  -> grid comb via
  _circ circular-
  concentration
  fit (conc ~0.99);
  THICK bands
  (w>=6) -> wall
  anchors, cent-
  roids DE-BIASED
  by dropping
  lines within
  +-2px of fitted
  grid lines;
  _ransac anchor
  PAIRS (integer
  line count =
  round(delta/
  gP), span >=8
  lines, P in
  [0.99,1.02]*gP),
  tight-inlier
  scoring, _polish
  clipped LSQ
  (clip WANDER
  5.6); ratio
  cross-check
  sx vs sy (tol
  0.002) -> the
  worse axis gets
  _ratio_refit:
  Q = s*gP fixed,
  phase by CIRCUL-
  AR MEAN (KDE
  mode variant
  FAILED in test
  - landed 40.6
  vs seated 29.9;
  circular mean
  is the rep28-
  validated
  choice), then
  clipped LSQ.
  SANDBOX TEST OF
  THE SHIPPED
  CODE (exact vo/
  ho profiles from
  comps.pkl): X
  P=64.2505 phase
  54.23 (seated
  64.2742/53.40),
  max line dev
  0.78px; Y refit
  Q=64.6225 phase
  32.59 (seated
  64.5875/29.89),
  max line dev
  4.35px (inside
  the 5.6 wander;
  walls 12-30px
  wide so run
  attribution
  safe). v1.6:
  492 lines,
  17881 bytes,
  normalized md5
  949639b4468b83
  9acdc0336beccd3
  342, canvas
  "mapbatch-tool"
  body byte-exact
  (title bumped
  v1.6). ORIGIN
  CAVEAT: auto
  x0 = phase in
  [0,P) - line
  indices SHIFT
  vs the seated
  record (X +2,
  Y +7); the
  record's
  X0=181.95/Y0=
  482 origin is
  NOT derivable
  (eyeballed) -
  auto gates must
  compare PHASE
  MOD PITCH, not
  absolute origin
  or line indices;
  record-compat-
  ible JSON needs
  --lattice
  181.95,64.2742,
  482.0,64.5875.
  HIS GATES:
  auto run ~/
  mb6: P in
  64.27+-0.15,
  phase 53.4+-3;
  Q 64.59+-0.15,
  phase 29.89+-3,
  no ratio warn-
  ing; seated run
  ~/mb6s: walls
  ~239 runs,
  residue ~200.
  Termux quirks
  stand: /tmp not
  writable, use
  ~; expanduser
  in diagnostics.
  MAPBATCH V1.6
  FIRST TERMUX RUN
  (2026-11-06): md5
  gate PASSED
  byte-exact
  (949639b4...
  342), auto X
  LANDED (X0=53.55
  P=64.2757 vs
  seated 64.2742/
  53.40 - the X
  fit is SOLVED),
  but (a) Y stayed
  grid-locked
  (Q=64.0126) -
  ratio refit
  failed silently
  on his cv2 mask,
  and (b) wall_
  runs CRASHED:
  zero-size slice
  .max() when a
  line center c0
  sits in [n,
  n+per] - the
  skip guard
  (c0>n+per) is
  too loose, this
  crashes even
  with a PERFECT
  lattice. ROOT
  CAUSE (found
  after env
  reset - work
  dir wiped,
  restored
  jdec+mapbatch
  from canvases,
  raster re-
  pulled from
  raw.github,
  comps rebuilt):
  the sandbox
  profile
  approximation
  was WRONG -
  opening's
  dilate stage
  RESTORES full
  run lengths, so
  the profile is
  sum(len) not
  sum(len-k+1);
  with correct
  profiles the
  circular-mean
  refit then
  FREE-polish
  drifts to a
  foreign comb
  (64.29/42.29,
  n=11) - a free
  pitch polish
  on the weak
  axis lets a
  pseudo-comb
  steal inliers
  (the v1.5
  lesson again).
  ALSO: two Y
  anchors are
  slab-biased
  (seated devs
  +5.9, +7.5 -
  beyond the 5.6
  wander), which
  drags the
  circular mean
  phase to 35.9
  (gate-fail).
  v1.6.1 FIX
  (validated on
  correct
  profiles): (1)
  _ratio_refit:
  Q = s*gP
  FROZEN (weak-
  axis anchors
  cannot refine
  pitch); phase =
  INLIER-COUNT-
  MAX scan over
  [0,Q) step
  0.25 (robust to
  slab-biased
  outliers that
  drag the
  circular
  mean), then
  phase-only
  LSQ refine
  that never
  lowers the
  inlier count.
  (2) wall_runs:
  explicit
  a0=max(0,c0-2),
  a1=min(n,c0+3),
  skip when
  a0>=a1. Sandbox
  gates on
  correct
  profiles: X
  P=64.2959 ph=
  53.07 maxdev
  0.47px; Y refit
  Q=64.6062 ph=
  32.25 (seated
  29.89 - 2.36
  off, INSIDE
  the +-3 phase
  gate), n=11,
  rms 4.39 (<
  WANDER, slab
  bias), maxdev
  3.24px. v1.6.1:
  518 lines,
  18553 bytes,
  normalized md5
  535ba5a6cf9018
  f7cfa3e689625
  770b8, canvas
  title bumped
  v1.6.1, body
  byte-exact.
  LESSON: the
  sandbox
  profile proxy
  must model
  morphology
  EXACTLY
  (opening =
  erode+dilate
  restores full
  run lengths) -
  approximate
  weights
  validated the
  wrong phase
  selector.
  MAPBATCH V1.6.1
  TERMUX RUN
  (2026-11-06): md5
  gate byte-exact,
  crash FIXED,
  both passes
  complete. But
  AUTO pass
  locked BOTH
  axes on the
  grid (X0=60.50
  P=63.6952 Y0=
  48.16 Q=64.0126
  ) and walls
  322 runs/137
  voids (vs
  seated 284/
  126). ROOT
  CAUSE: on his
  cv2 mask the
  Y GRID comb
  out-inliered
  the X WALL
  comb (n tie-
  break), so
  the (n,-rms)
  trusted-axis
  rule trusted
  the GRID,
  then refit X
  with the grid
  ratio s~1.0 -
  dragging X
  down too (X
  alone was
  right in the
  v1.6 run:
  53.55/64.2757
  ). v1.6.2
  FIX: trusted
  axis = larger
  |s-1| (the
  wall lattice
  carries the
  print scale
  ~1.0088; a
  grid-locked
  fit sits at
  ~1.0000 BY
  CONSTRUCTION
  - inlier
  counts can
  favor the
  grid, seen
  LIVE on his
  mask). OPEN
  RISK (noted,
  unhandled):
  if BOTH axes
  grid-lock,
  sx~sy~1 -> no
  ratio trigger
  -> silent
  grid lattice;
  X has been
  robust across
  masks so far.
  Sandbox
  re-gates
  unchanged: X
  64.2959/53.07
  maxdev 0.47px;
  Y refit
  64.6062/32.25
  maxdev
  3.24px. v1.6
  .2: 522
  lines, 18785
  bytes, md5
  68d1804c9673
  279988757678
  df759417,
  canvas v1.6.2
  byte-exact.
  SEATED COUNT
  SHIFT OPEN:
  v1.6.1 seated
  pass = 284
  runs/126
  voids vs the
  v1.5 record
  239/68 - blobs
  identical
  (268) so the
  change is in
  the WALL
  layer (v1.6
  separate thr
  0.09*pitch vs
  v1.5's
  poisoned
  0.35*dist.max
  - lower thr
  keeps more
  interior wall
  ink = more/
  longer runs,
  more void
  splits).
  ARBITER: the
  record facts
  on ~/mb6s
  JSON - V2
  runs (17,41),
  (43,43) void
  (42,42); V33
  (7,41); H0
  (8,35); H40
  (12,24). If
  those hold,
  284/126 is
  the better
  separator
  working (v1.
  5 was DROPP-
  ING interior
  wall ink); if
  not, stage 2
  drifted and
  needs a diff
  vs v1.5 (no
  v1.5 source
  in sandbox
  anymore -
  canvas was
  overwritten;
  repo has no
  tools/
  mapbatch.py;
  his local git
  history may).
  MAPBATCH V1.6.2
  RUN (2026-11-06):
  AUTO-FIT
  LANDED: X0=53.55
  P=64.2757 Y0=
  32.00 Q=64.5959
  (seated
  53.40/64.2742,
  29.89/64.5875)
  - BOTH axes
  inside the
  phase/pitch
  gates, no
  warnings. THE
  TWO-COMB FIT
  IS SOLVED.
  RECORD CHECK
  then EXPOSED
  the stage-2
  drift: V33
  (-0.37,34.31)
  and V2 OK but
  H0/H40 EMPTY.
  FULL SANDBOX
  REPRO (env
  upgraded: pip
  still
  forbidden,
  but NODE -
  pure-JS sims
  sim2-sim6.js
  replicate
  OTSU, chamfer
  distance
  (= cv2's
  DIST_L2
  maskSize 3 -
  HIS V2
  fragments
  matched the
  CHAMFER sim
  exactly, not
  the exact-
  Euclid one),
  BFS recon-
  struction,
  wall_runs;
  +jdec
  raster): (1)
  ROOT BUG =
  wall_runs H
  branch had
  .max(axis=1)
  instead of
  .max(axis=0)
  - the 5-row
  slice
  collapsed to
  page-wide
  row maxima,
  one 5px
  pseudo-run,
  always below
  the 8px
  minimum ->
  EVERY H run
  dropped (his
  284 runs =
  V only); the
  v1.6 rewrite
  introduced
  it, v1.5 had
  it right; MY
  sims
  initially
  replicated
  the INTENT
  so the bug
  was invisible
  until his
  record check
  - sims must
  transcribe
  the code,
  not the
  intent, and
  my own sim
  H-branch was
  ALSO
  transposed
  once (pixel
  = walls
  [t*W+s] for
  H, caught by
  cross-check-
  ing against
  the raw row
  dumps).
  (2) RECORD
  UNITS
  SOLVED: the
  record's
  run extents
  are PHASE-
  ORIGIN line
  units (+2 X,
  +7 Y vs
  seated) -
  record V2
  (17,41) =
  the stockade
  seated
  (10,34),
  record V33
  (7,41) =
  seated (0,
  34), record
  H0 (8,35) =
  seated (6,
  33), H40
  (12,24) =
  seated (10,
  22).
  (3) GROUPING
  FIX: run
  grouping now
  bridges gaps
  <= 0.2*cross
  px (a wall
  band is
  continuous
  ink; real
  openings
  >=0.25 line
  become door
  voids) -
  with it the
  sim
  reproduces
  ALL FOUR
  record facts
  on the
  shipped
  unbounded
  layer: V2
  stockade
  (9.61,34.39)
  + grid-noise
  slivers,
  V33 (-0.36,
  34.29) one
  run, H0 ONE
  run (5.59,
  33.28), H40
  (9.12,22.36).
  Bounded-
  dilation
  wall layer
  tested and
  REJECTED:
  it splits
  V33 at a
  recessed
  doorway
  (12.97-34.29
  two runs) -
  unbounded
  recon
  (current
  separate)
  is the
  right
  layer; the
  fat layer's
  grid-line
  fragments
  are residue-
  class noise,
  deferred.
  v1.6.3 =
  axis=0 fix +
  0.2*cross
  grouping:
  525 lines,
  18952 bytes,
  md5
  fb26926e3af
  dc7296972c9
  319baf3c4d,
  canvas
  v1.6.3
  byte-exact.
  HIS EXPECTED
  NEXT: seated
  rerun ~450
  runs/~197
  voids-class
  counts (his
  cv2 mask
  will differ
  slightly
  from jdec
  sim), record
  lines V2/V33
  /H0/H40
  matching
  seated-unit
  values
  above.
  MAP-006 GATE
  PASSED (2026-
  11-06, v1.6
  .3): md5
  fb26926e...
  byte-exact.
  SEATED run:
  478 runs, 228
  voids, blobs
  268 / residue
  203 (inventory
  IDENTICAL to
  the v1.5 pass-
  1 - blobs
  untouched).
  RECORD CHECK
  ON HIS CV2
  MASK, all
  four facts:
  V2 (9.6,
  34.39) stockade
  + fragments
  (34.88,35.98)
  .. (grid
  slivers,
  residue-class)
  with voids
  between; V33
  (-0.37,34.31)
  ONE run; H0
  (5.57,33.28)
  ONE run =
  record (8,35);
  H40 (9.1,
  22.36) =
  record (12,24).
  AUTO run
  (v1.6.2 code):
  X0=53.55
  P=64.2757 Y0=
  32.00 Q=64.5959
  - both inside
  the phase/
  pitch gates.
  Tool status:
  FIT SOLVED,
  STAGE 2/3
  RECORD-
  VALIDATED,
  counts ~2x
  v1.5 (478 vs
  239) = fat-
  layer grid
  slivers,
  residue-class,
  deferred.
  NEXT (WAITING
  GO): batch run
  across the
  G1 maps
  (extract/g1/),
  spot-check a
  second map
  seated-style
  against its
  record before
  trusting batch
  JSON;
  matchShapes
  exemplars
  (16's door
  leaf, hearths,
  columns) and
  OCR optional
  deferred to
  v2.
  G1 BATCH SCAN
  (2026-11-06,
  sandbox
  pre-valid-
  ation, only
  map-006 =
  upper level
  has a seated
  record):
  extract/g1/
  = map-006.jpg
  + p002-02.png
  + p012-12.png
  (all 2550x3300
  pages; PNG
  gray planes
  decoded
  pure-JS,
  zlib+unfilt-
  er - pngfit
  .js, reusable
  with jdec).
  p002-02.png:
  G1-CLASS
  CONFIRMED -
  thr 178, ink
  17.1 percent,
  X gP=63.745
  P=64.3072
  ph=53.59
  sx=1.00882
  (the SAME
  print-scale
  constant as
  map-006),
  Y ratio-refit
  Q=64.6174
  ph=28.50
  (n=15) -
  auto-fit
  will work;
  presumably
  the LOWER
  level.
  p012-12.png:
  NOT G1-CLASS
  - 51.9
  percent
  global ink;
  white page
  with a LARGE
  DARK SHADED
  BLOCK rows
  136-3200 x
  cols 79-2435
  (halftone/
  artwork or
  shaded
  wilderness
  art, NOT a
  10ft-graph
  dungeon);
  interior fit:
  ink 60.4
  percent, X
  fit FAILS,
  Y mush
  62.4/63.3,
  no print
  ratio - DO
  NOT run the
  tool on it;
  awaits
  Curtiss's
  ID of what
  the page is.
  NEXT: his
  batch run =
  p002-02 only
  (from
  ~/Adnd1/
  extract/g1/),
  gates:
  X ~64.31
  ph ~53.6,
  Y ~64.62
  ph ~28.5
  (cv2 mask
  may shift
  slightly),
  no ratio
  warning;
  then build
  the record
  for the
  lower level
  the same
  seated-
  splice way
  (its record
  does not
  exist yet -
  map-006 is
  the only
  seated map).
  P002-02 BATCH
  RUN LANDED
  (2026-11-06,
  v1.6.3 auto,
  no --lattice
  - the first
  map extracted
  with ZERO
  seated input)
  : X0=53.60
  P=64.3072 Y0=
  32.25 Q=64.6148
  (sandbox
  predicted
  53.59/64.3072
  EXACT on X;
  Y Q 64.6174,
  phase 28.50
  vs his 32.25
  = 3.7px cv2-
  mask anchor
  difference,
  inside the
  wall band),
  no ratio
  warning, 438
  runs / 196
  voids / 264
  blobs / 205
  residue
  composite.
  Origin is
  PHASE-BASED
  (no seated
  record for
  the lower
  level yet) -
  line indices
  will shift by
  a constant
  once he
  splices and
  seats this
  level; JSON is
  fine for
  eyes-on
  residue work
  meanwhile.
  G1 tool
  status: BOTH
  extractable
  maps (006
  upper, p002-
  02 lower)
  extracted;
  p012-12 not a
  dungeon map
  (awaiting his
  ID of that
  page); the
  G1 EXTRACTION
  PIPELINE IS
  COMPLETE.
  Open for v2:
  run-count
  tightening
  (fat-layer
  grid slivers,
  ~2x v1.5
  counts),
  matchShapes
  exemplars,
  OCR optional.
  MAPBATCH V1.7
  (2026-11-06,
  "Go" on the
  run-count
  tightening):
  ANNOTATE,
  DON'T DELETE
  - the
  record-valid-
  ated default
  is untouch-
  able, so
  every run now
  carries COV =
  fraction of
  its span
  backed by
  dist-core
  (the
  thickness
  layer;
  separate now
  returns
  walls,
  nonwall,
  core);
  grid slivers
  cov 0-0.26,
  wall bands
  cov >=0.92
  (stockade
  0.99, V33
  0.94, H0
  0.92, H40
  0.99) - a
  CLEAN
  bimodal
  split. New
  opt-in flag
  --strict-
  runs keeps
  cov>=0.5
  only (voids
  recomputed
  from kept
  runs). Sandbox
  (map-006
  seated,
  chamfer sim):
  DEFAULT 453
  runs/197
  voids =
  v1.6.3
  behavior
  EXACT (record
  lines all
  intact);
  STRICT 137
  runs/7 voids
  - sliver
  inflation
  gone, all
  four record-
  structural
  runs survive
  (V2 keeps
  stockade +
  one cov-0.64
  piece). HIS
  cv2 counts
  will differ
  somewhat
  (his default
  was 478).
  v1.7: 543
  lines, 19755
  bytes, md5
  673b75f819d6
  1d2efbdc1c9c
  3647f654,
  canvas v1.7
  byte-exact.
  RECORD
  CAVEAT:
  --strict-runs
  DROPS the
  record's V2
  fragment
  (43,43)-class
  pieces (cov
  ~0.24 = grid
  ink that the
  v1.5-era
  record
  absorbed) -
  default mode
  is the
  record-
  compatible
  one; strict
  is the clean
  one. GATES
  for his
  rerun:
  default
  output
  IDENTICAL to
  v1.6.3 (runs
  + extents,
  plus new cov
  field);
  strict
  roughly a
  third of
  default.
  V1.7 TERMUX
  VALIDATED
  (2026-11-06):
  md5 byte-
  exact. Two
  passes: (a)
  DEFAULT ~/mb
  6s2: 478
  runs / 228
  voids /
  268 blobs /
  203 residue
  - IDENTICAL
  to v1.6.3
  (annotate-
  don't-
  delete
  confirmed;
  only the
  cov field
  added).
  (b) STRICT
  ~/mb6s3:
  107 runs /
  8 voids /
  268 blobs
  (his cv2
  core leaner
  than the
  chamfer sim's
  137 - same
  ballpark).
  STRICT
  RECORD
  CHECK: V2
  (9.6,34.39,
  cov 0.99)
  stockade
  ONLY (the
  (43,43)
  grid fragment
  shed as
  designed);
  V33 (-0.37,
  34.31, cov
  0.94); H0
  (5.57,33.28,
  cov 0.92)
  ONE run; H40
  (9.1,22.36,
  cov 0.99) -
  all four
  structural
  runs intact
  with cov
  0.92-0.99.
  V1.7 CLOSED.
  Tool doctrine
  now: DEFAULT
  = record-
  compatible
  (use for
  record
  checks),
  --strict-
  runs = clean
  working JSON
  (~107 runs,
  8 door voids
  = the actual
  wall/door
  structure).
  Remaining v2
  threads:
  exemplar
  recognition
  (needs his
  eyeballed
  exemplar
  list from
  the residue
  composites -
  Hu moments
  already in
  every JSON),
  p012-12 page
  ID, optional
  OCR.
  P012-12 CLOSED
  (2026-11-06,
  Curtiss's
  eye-check):
  it is a 3-
  PANEL ILLUS-
  TRATION PAGE
  (panel 3 has
  a FIREPLACE -
  painted scene
  art, NOT a
  hearth glyph;
  the earlier
  "fireplace
  issue" was
  the lattice
  fitter
  correctly
  refusing an
  art page -
  vocabulary
  collision
  with the
  map-006
  hearth class,
  different
  species).
  Pixel
  structure
  confirms:
  full-width
  dark bands
  rows ~390-448
  and ~3008,
  dark side
  bars cols
  84-190 and
  2354-2433 =
  stacked
  panel frame,
  halftone
  interior
  (60 percent
  ink, no
  comb, fit
  fails).
  VERDICT:
  out of scope
  for mapbatch
  BY DESIGN;
  extraction
  pipeline
  remains
  COMPLETE
  with map-006
  (upper) +
  p002-02
  (lower) only;
  if the
  record ever
  needs the
  page's
  content it
  is an eyes-
  on job
  (residue
  doctrine
  class), not
  a lattice
  job. NO
  better
  raster
  needed for
  extraction.
  OBJECT
  RECOGNITION
  v1 (2026-11-
  06): TRAINED
  ON HIS SIDE
  by design -
  not model
  training but
  EXEMPLAR
  MATCHING
  (~470 blobs,
  2 levels, no
  labels yet -
  nearest-
  neighbor is
  the right
  tool and fits
  the proposals-
  never-
  decisions
  doctrine).
  tools/match
  .py (canvas
  "match-
  tool", NEW,
  separate -
  mapbatch
  FROZEN at
  v1.7): pure
  STDLIB, no
  cv2 needed -
  reads blob
  Hu/area/
  aspect/lat
  straight
  from the
  .extract
  .json files.
  Distance =
  log-Hu
  shape (W
  1.0) + area
  ratio (0.5)
  + aspect
  ratio (0.3);
  per-label
  best-of-
  exemplars;
  UNKNOWN
  above 1.4;
  confident =
  best-vs-
  second
  margin >=
  0.25.
  Exemplars
  file:
  {"label":
  ["map-stem:
  latx,laty",
  ...]} - HE
  tags them
  by eyeball-
  ing the
  residue
  composites
  and looking
  up lat in
  the JSON.
  Usage:
  python3
  tools/
  match.py
  EXEMPLARS
  .json A.
  extract
  .json
  [B...] ->
  <stem>.
  match.json
  per map +
  tally.
  139 lines,
  4885 bytes,
  md5
  be4ec4ebd1
  77445106f7
  6c64f5c49d
  86 (CORRECT-
  ED 2026-11-
  06 - first
  seat had a
  bogus value),
  canvas
  byte-exact,
  py_compile
  clean.
  Mechanics
  sandbox-
  verified
  (lat lookup,
  self-match
  dist 0.0,
  ranking/
  margin/
  UNKNOWN
  paths);
  real-class
  DISCRIMIN-
  ATION is
  unvalidated
  until his
  first real
  exemplar
  set - the
  synthetic
  test is not
  a proxy
  (real Hu
  moments are
  scale-
  invariant;
  synthetic
  scaled
  vectors are
  not). KNOWN
  CAVEATS:
  Hu is NOT
  mirror-
  invariant
  (map glyphs
  are
  orientation-
  fixed so
  mostly OK);
  hearth vs
  column
  collisions
  possible at
  similar
  size - read
  the margin
  field.
  Thresholds
  UNKNOWN=1.
  4, MARGIN=
  0.25 are
  first
  guesses -
  tune after
  the first
  real run
  by looking
  at the dist
  distribution.
  MATCH FIRST
  RUN DIAGNOSIS
  (2026-11-06):
  3 of 4
  record-seated
  hearths had
  NO blob
  anywhere
  near them
  (24-hearth
  nearest 8.25
  lines!) -
  match.py
  mechanics
  fine (lat
  lookup,
  warnings,
  tally);
  ROOT CAUSE
  is UPSTREAM:
  wall-adjacent
  objects
  touch the
  printed grid,
  the grid
  touches
  walls, and
  the UNBOUNDED
  reconstruction
  dragged them
  into the
  wall web -
  never reached
  the blob
  layer. Also
  door leaves
  INSIDE wall
  bands stay
  wall (they
  are door_
  voids
  territory,
  not blob
  territory).
  v1.8 FIX
  (sandbox-
  validated,
  sim8.js):
  separate now
  computes
  TWO wall
  layers -
  RUNS keep
  the fat
  unbounded
  walls
  (record-
  frozen),
  the BLOB
  layer uses
  BOUNDED
  walls
  (core +
  int(thr)+1
  dilations
  & mask) -
  hearths/
  fireplaces
  survive:
  24-hearth
  = mass
  13368px at
  (29.82,
  3.03),
  east
  fireplace
  glyph
  cluster
  (32.5,
  26.6),
  14-hearth
  mass at
  (5.99,
  32.46),
  columns
  unchanged
  (318-351px
  glyphs).
  Counts move:
  268 blobs/
  203 residue
  -> ~475/
  ~360 (the
  freed layer;
  115 grid
  segments
  classify
  'line' and
  stay out of
  residue) -
  blob counts
  were never
  record-
  gated; runs/
  voids/
  lattice
  unchanged.
  v1.8: 549
  lines, 20002
  bytes, md5
  b4c0c53c0b
  94fcf9d5cc
  35f042ee16
  d3, canvas
  v1.8
  byte-exact.
  HIS NEXT:
  re-extract
  map-006
  seated,
  re-tag
  exemplars
  from the NEW
  blob layer
  (record lats
  above are
  sandbox-
  chamfer
  values - use
  his lookup
  one-liner to
  confirm on
  his cv2
  mask), rerun
  match.py.
  V1.8 TERMUX
  RUN (2026-
  11-06): md5
  byte-exact,
  seated
  ~/mb6s4:
  478 runs /
  228 voids =
  IDENTICAL
  to v1.6.3
  (record-
  frozen path
  confirmed
  on his
  mask),
  blobs 507 /
  residue 378
  (sandbox
  predicted
  475/360 -
  his cv2
  mask
  slightly
  richer,
  same
  ballpark).
  The bounded
  blob layer
  is live:
  hearths/
  fireplaces
  now reach
  the
  inventory.
  NEXT: his
  lookup ->
  exemplar
  tagging
  from the
  NEW layer ->
  match.py
  rerun.
  MATCH v1.1
  (2026-11-06):
  output-name
  bug fix -
  match.py
  wrote <stem>.
  extract.
  match.json;
  now strips
  .extract
  like the
  blob-index
  stem ->
  <stem>.
  match.json.
  142 lines,
  4958 bytes,
  md5
  f972f183ee
  ee6ccd2530f
  b9677af6915
  (canvas
  v1.1
  byte-exact).
  FIRST REAL
  RECOGNITION
  RUN (his
  mb6s4,
  exemplars:
  hearth x3
  29.8/3.12,
  6.02/32.45,
  16.11/21.67;
  fireplace x1
  32.59/26.64;
  column x2
  14.08/18.62,
  14.55/18.59)
  : 507 blobs
  -> UNKNOWN
  469, hearth
  14, column
  23, fireplace
  1, 21
  confident -
  SHAPE RIGHT
  (unknown
  dominates,
  fireplace
  exact) but
  OVER-
  PROPOSING
  (record
  seats ~5
  hearths,
  ~3-6
  columns) -
  UNKNOWN
  threshold
  1.4 too
  loose on
  real Hu
  distances;
  NEXT: dump
  sorted
  dist/margin/
  lat of non-
  UNKNOWN,
  eyeball vs
  record, cut
  threshold in
  the gap; if
  impostors
  are
  semantically
  consistent
  (door jambs
  as columns),
  consider a
  VETO/
  rejection
  exemplar
  class.
  RECOGNITION TUNING v1.2 (2026-11-06, from his sorted dump of the old
  map-006.extract.match.json, 38 non-UNKNOWN rows): (1) CONFIDENCE BUG
  CONFIRMED - confident was margin>=0.25 alone, so far blobs (dist 0.7-1.35)
  merely "more column-like than hearth-like" got conf=True (16 of them);
  margin measures label separation, not closeness. (2) THRESHOLD ALONE
  CANNOT FIX THIS MAP: 20 of 32 non-exemplar proposals sit in BORDER BANDS
  (lat y>=35, y<=0.5, x>=32 = frame art) at dist 0.25-1.35, while the
  likely-real extra columns near the record column row - (15.9,17.3)
  d=0.767, (16.0,17.7) d=0.858, (15.5,18.6) d=1.145 - are FARTHER than the
  border impostors (border d=0.246-0.552). No UNKNOWN cut separates them.
  (3) RECORD 3rd COLUMN (14.98,18.6) NOT IN PROPOSALS AT ALL - check whether
  a blob near it reached inventory (cmd: filter extract json lat 15.0/18.6
  +-1.5). (4) UNKNOWN=0.45 sits in the 0.441-0.468 gap and lands hearth=5,
  column=6 (record ~5 hearths, 3-6 columns) but ALL extra proposals are
  border-band - record-count fit may be coincidence. SHIPPED match.py v1.2:
  UNKNOWN 1.4->0.45; new CONF_MAX=0.30, confident = margin>=0.25 AND
  dist<=CONF_MAX (absolute-caps confidence, fixes far-blob conf=True);
  W_HU/W_A/W_S and margins unchanged. md5 ec814b6654c4e0c401f94de6fcce4bd0,
  146 lines, 5180 bytes, canvas match-tool title "(v1.2)", byte-exact
  verified, py_compile clean, synthetic 4-blob functional test passes
  (near-exemplar confident, mid 1.03/far 6.81 UNKNOWN). NEXT: (a) he saves
  v1.2 over tools/match.py (gate ec814b66...) and reruns on ~/mb6s4 - expect
  hearth~5-8, column~6, far conf gone; (b) he eyeballs borderline blobs, esp
  border band vs the (15.9-16.0,17.3-18.6) interior trio and missing 3rd
  column at (14.98,18.6); (c) if interior trio are real columns, ADD THEM AS
  EXEMPLARS (densify: their kind drops to dist~0, margins sharpen, border
  furniture separates naturally) - preferred over a hardcoded lat-band veto;
  (d) if border art is semantically consistent, consider a VETO/rejection
  exemplar class (label that outranks proposals). Doctrine unchanged:
  proposals, never decisions.
  DESIGN RESET (2026-11-06, his call): put aside all map knowledge; app
  contract = only "opened file should be a map". Agreed direction from him:
  (1) HYBRID + TRAINABLE - app labels only what is certain, must learn
  objects across future maps; (2) INTERACTIVE - weak hypotheses ask for
  hints (competing lattices: "which cell is square"; unknown shapes: name
  this family); human answers are training events. Explained
  clustering-vs-exemplars trade (507 blobs -> shape families, families named
  after the fact; fixes pre-tag blindness and the column at (15.0,18.6) that
  no exemplar covered). SEATED SPEC CANVAS match2-spec (design spec v0.1
  draft, match2.py): pipeline = inventory -> cluster (gap-stat cut,
  safety-rail constants only) -> library match (self-contained entries carry
  own hu/area/aspect) -> label only if family dist <= certainty bar (Q0.9 of
  within-label NN dists, floored/capped; margin NEVER grants confidence
  alone, v1.2 lesson is law) AND member agreement >= 2/3; UNKNOWN families
  surfaced with representative member; --ask prints question list, --learn
  appends answers (append-only, provenance
  map/blob/lat/px/signature/date/source); --import legacy exemplars.json.
  library.json lives in repo next to tools. v2 NOT in scope: OCR, door-leaf,
  veto classes, ANY map-006- justified constant in code (those belong in the
  library). Column-row dump finding still parked: 10 glyphs near lat
  (14.1-16.0, 17.3-18.6) incl record 3rd column (15.0,18.6) which scored
  >1.4 vs exemplars - fragmentation hypothesis unresolved, relevant test
  case for match2 family layer. Awaiting his GO: review spec, then build
  match2.py v2.
  PURPOSE FOUND (2026-11-06, end of design-reset discussion): app goal
  stated and seated as doctrine canvas app-doctrine ("Map extraction app -
  shared doctrine v0.1") - TAKE A SCANNED MAP PAGE FROM
  KNOWN/ABSTRACT/UNKNOWN/UNCERTAIN TO ENTIRELY KNOWN AND PIXEL PERFECT
  (every claim citable to exact ink, reproducibly, no human in the loop).
  Core rules seated: four states (KNOWN=custody only, ABSTRACT=must cite
  pixels, UNKNOWN=success state routing to ask-list, UNCERTAIN=resolved by
  discriminators or human tiebreak that trains); MONOTONE transitions
  (unknown->uncertain-> abstract->known, demotion is a loud re-litigation
  event); honest confidence (margin never grants confidence alone - the v1.2
  law); ask-don't-guess; feedback curve phases 1- 3 with per-run
  question/correction trace; append-only provenance'd library; lattice units
  only (one-map constants belong in library not tool); DPI = fallible
  witness trusted:false; bbox gate / pixel facts decide; proposals never
  decisions until certainty bar derivable from library spread. Termination:
  record-as-JSON becomes the test suite (re-derive every claim, diff, pass).
  Next specs both reference this doctrine: grid-spec (mapbatch side:
  assert-map periodicity -> ranked grid hypotheses -> wall seating
  conventions brute force over finite offset/ thickness set -> scale
  statement w/ source+confidence) and match2-spec (already seated v0.1
  draft). DISCUSSION STILL OPEN on details; no GO yet for building match2.py
  v2 or grid-spec draft.
  GRID-SPEC SEATED (2026-11-06, after "now what"): canvas grid-spec ("Grid
  determination - mapbatch front half, design spec v0.1 draft") -
  doctrine-referencing design doc for stages 0-3: (0) decode + assert-map
  via ink census and AXIS PERIODICITY (periodogram; reject = full stop, no
  fitting runs); (1) ENUMERATED grid hypotheses (top periodogram peaks both
  axes, wander-fit demoted to hypothesis refiner, score = ink coverage +
  residual, thin margin -> ask-trigger, characterize: origin/pitch/skew/
  extent/ink-explained-fraction, composite pitch hierarchy is a finding);
  (2) WALL SEATING brute force over finite set per role:
  centered/inner-edge/outer-edge/straddle- biased/half-line/mixed x
  thickness (1/8, 1/10, thin), discriminators = edge agreement + LENGTH
  QUANTIZATION (sharpest: lengths collapse to cell multiples only under
  correct convention) + corner closure, ties ask, learned convention stored
  as per-print-pipeline PRIOR in lattice units; (3) SCALE STATEMENT format
  w/ source ranked (scale bar > module dims > DPI+page-format > hint), DPI
  recorded trusted:false, two sources agreeing = confirmed, conflict = ask,
  no silent defaults, constrained legend OCR reserved. Output = grid
  statement JSON (origin, pitch, skew, cells, ink_explained, seating, scale,
  dpi hint, top-3 hypotheses, provenance); downstream consumes LATTICE UNITS
  ONLY, pixels cross only inside provenance pointers. Design layer now
  complete: app-doctrine + match2-spec + grid-spec all seated. AWAITING HIS
  GO to build: match2.py v2 against match2-spec (start --import) or mapbatch
  v2 front half against grid-spec. His stated purpose: known/
  abstract/unknown/uncertain -> known and pixel perfect.
  NAMED (2026-11-06): the app is MAP - one word, no dotfile separator
  anywhere in tooling. All three design canvases retitled to lead with mapp
  (app-doctrine, grid-spec, match2-spec); doctrine body states the name.
  Existing tool names (mapbatch, match.py, jdec) unchanged - mapp is the
  app, those are its components.
  MAP BUILT: match2.py v2.0 (2026-11-06, HIS GO "implement mapp now") -
  mapp's trainable shape-family recognizer per match2-spec. Canvas
  match2-tool, title "mapp match2.py - trainable shape-family recognizer
  (v2.0)", byte-exact, md5 b7aa7734ef5856df0ae3df02558bb793, 384 lines,
  12773 bytes, py_compile clean, no lines >78. Pipeline: load blobs ->
  fam_cut (single-linkage cut = Q1 of NN dists x FAM_FACTOR 4.0, clamp
  [0.05,1.2]) -> cluster (union-find) -> label_bars (per-label bar = Q0.9 of
  within-label entry NN dists, clamp [0.30,0.90]; 1- entry labels get floor
  0.30) -> fam_scores (family dist = MEDIAN over members of
  member-best-entry dist; member agreement = fraction of members whose own
  argmin label matches family best) -> confident if dist<=bar AND
  agreement>=2/3; proposal if dist<=bar x PROP_MULT 2.0; else UNKNOWN family
  -> ask-list rep (largest member, full signature). CLI: match2.py LIB.json
  A.extract.json [B...] [--ask] (first positional NOT ending .extract.json =
  library path); --learn ANSWERS.json --lib LIB (answers = .ask.json rows
  with "label" added, appends entries source human-confirm); --import
  legacy.json extracts --lib LIB (resolves stem:latx,laty refs tol 0.4,
  source legacy-import, provenance'd; append -only w/ (map,lat)-dedupe).
  Output <stem>.match.json rows
  (i/px/lat/cls/family/proposal/dist/margin/confident) + stdout summary w/
  per-(kind,label) tally; --ask writes <stem>.ask.json + numbered questions.
  Margin reported, NEVER grants confidence alone. VALIDATED in sandbox:
  synthetic 7-blob full loop (import 2 -> hearth/col confident, impostor
  pair UNKNOWN -> learn "rubble" -> rerun 0 questions, all confident);
  507-blob scale: 1.07s for cut+cluster+match (Termux-safe), empty lib = 4
  families/4 questions, single-exemplar labels honestly max out at proposal
  when family dist 0.308 > floor 0.30 (undershoot by design), 407 junk blobs
  chain-merged into 2 mega-families -> UNKNOWN not noise. KNOWN ISSUES to
  watch on real data: single-linkage chaining (cut rails), tally prints
  unknown rows under best-label name. NEXT HIS SIDE: save canvas body ->
  tools/match2.py (gate b7aa7734ef5856df0ae3df02558bb793), then ONE-TIME:
  python3 tools/match2.py --import exemplars.json
  ~/mb6s4/map-006.extract.json --lib tools/library.json THEN: python3
  tools/match2.py tools/library.json ~/mb6s4/map-006.extract.json --ask
  Answers: edit map-006.ask.json rows (add "label" to each question he can
  name, delete rows he cannot), then --learn map-006.ask.json --lib
  tools/library.json. First real regression target: the column-row 10-glyph
  cluster (15.9/17.3 trio + 15.0/18.6) - family layer should either seat
  them or expose blob-layer fragmentation. mapbatch v2 front half
  (grid-spec) NOT built yet - next mapp component after his first real
  match2 run.
  RENAME (2026-11-06): HIS CALL - the tool is named just mapp.py (was
  match2.py). Docstring + usage lines updated (match2-spec reference kept -
  that is the spec doc name). NEW md5 ac499422f4b689d9b563d92618e71a8c, 384
  lines, 12765 bytes, py_compile clean, no lines >78, functional test
  passes. Canvas seat moved to MAP-TOOL (title "mapp.py - mapp's trainable
  shape-family recognizer (v2.0)", byte-exact); the match2-tool canvas was
  retired in the same move (canvas deletion unsupported, but a rejection
  rollback left it gone - net state clean, no duplicate). match2-spec canvas
  (the design doc) unchanged. HIS SIDE COMMANDS NOW: save mapp-tool canvas
  body -> tools/mapp.py (gate python3 -c hashlib md5 must print
  ac499422f4b689d9b563d92618e71a8c), then ONE-TIME import + first run:
  python3 tools/mapp.py --import exemplars.json ~/mb6s4/map-006.extract.json
  --lib tools/library.json python3 tools/mapp.py tools/library.json
  ~/mb6s4/map-006.extract.json --ask Answers: edit map-006.ask.json (add
  "label" per row he can name, delete rows he cannot), learn with python3
  tools/mapp.py --learn map-006.ask.json --lib tools/library.json Env-reset
  note: /home/user/work was wiped this turn and rebuilt from canvas (restore
  path = canvas body via sed '8,$p'; sandbox rule confirmed again).
  RENAMED (2026-11-06, his call): match2.py is now just MAP.PY - the tool IS
  the app. Canvas renames are not supported, so the shipped tool canvas is
  now MAP-TOOL (title "mapp.py - trainable shape-family recognizer (v2.0)"),
  byte-exact, md5 ac499422f4b689d9b563d92618e71a8c (NOTE: differs from
  match2.py v2.0 b7aa7734... because the docstring + 3 usage lines changed
  match2.py -> mapp.py; 384 lines, 12765 bytes, py_compile clean, no lines
  >78; functional re-test after rename passed: import 2, hearth 3 + column 2
  confident). The old match2-tool canvas is SUPERSEDED - use mapp-tool from
  now on. Line 3 docstring still cites match2-spec v0.1 (the spec canvas
  name, unchanged). HIS SIDE now: save the MAP-TOOL canvas body ->
  tools/mapp.py (gate ac499422f4b689d9b563d92618e71a8c), then python3
  tools/mapp.py --import exemplars.json ~/mb6s4/map-006.extract.json --lib
  tools/library.json then python3 tools/mapp.py tools/library.json
  ~/mb6s4/map-006.extract.json --ask. Env reset note: /home/user/work wiped
  again this round, restored from canvas - canvases remain the source of
  truth.
  FIRST REAL MAP RUN (2026-11-06, his mb6s4, mapp.py v2.0 md5 ac499422...):
  import clean (6 entries), 507 blobs -> 72 families, cut SATURATED AT
  FAM_MAX CAP 1.200 (Q1 of NN dists x 4 exceeded the cap - the 507-blob
  population is diverse, many tiny fragments w/ wild Hu). Result: confident
  hearth 1 + fireplace 1; proposal column 1 + hearth 5; 70 questions. No
  mega-chaining (72 families is sane granularity). SUSPECTED PROBLEM: the
  cut cap is TOO HIGH -> chaining merges distinct objects into families and
  poisons the MEDIAN family distance. SMOKING GUN: q12 family rep
  lat=(6.0,32.5) area=9741 = the 14-hearth EXEMPLAR ITSELF, yet only
  proposal d=1.093 - if that blob were in a pure family its own dist to
  itself (a library entry) is 0.000 and it would be confident; the median
  >=1.093 means chained non-self members are pulling it (family median sits
  between members). Same likely story for the firepit exemplar (16.1,21.7) -
  not visible as confident. Geography of the 70 questions: dominated by
  border bands (y 35-40 south frame, y<=0 north margin incl -4.8/-4.4/-4.1
  band, x 30- 33 east) and huge interior floor blobs ((20.4,23.2) area
  115895, (6.7,14.3) 41199, (10.0,3.2) 21790, (17.5,36.6) 31210) -
  frame/fill blobs, likely deletable from ask list; interior mid-size glyphs
  are the real training targets. Unknown tallies (412 column / 52 fireplace
  / 35 hearth) are nearest-label hints only, meaningless at d 3-42. WAITING
  ON HIS DUMPS before any code change: (A) column-row family composition
  (does the 10-glyph cluster seat as families), (B) all non-UNKNOWN rows
  (are exemplar blobs chained). DECISION PENDING: lower FAM_MAX 1.2 -> ~0.6
  and/or rethink cut derivation vs real data; do NOT change rails until
  family composition is seen.
  MAP v2.1 SHIPPED (2026-11-06): OUTPUT-PATH FIX - match.json and ask.json
  now write BESIDE the extract (os.path.dirname of input), restoring v1
  behavior; v2.0 had written them to CWD, which sent his first outputs to
  ~/Adnd1 instead of ~/mb6s4 (his FileNotFoundError was this, not data loss
  - files were in ~/Adnd1 all along). Canvas mapp-tool title now (v2.1),
  byte-exact, md5 74387c4d61474785a2f3696315cd557c, 388 lines, 12924 bytes,
  py_compile clean, no lines >78, functional test: outputs landed in extract
  dir. STILL PENDING before his --learn: (A) column-row family dump, (B)
  non-UNKNOWN rows dump (both re-pointed at ~/Adnd1/map-006.match.json) to
  confirm the FAM_MAX chaining diagnosis (q12 exemplar family poisoned by
  median). FAM_MAX cut fix deliberately HELD for v2.2 until those dumps
  arrive.
  MAP v2.2 SHIPPED (2026-11-06, after his two dumps CONFIRMED the chaining
  diagnosis): HIS DUMP FINDINGS SEATED - (A) column-row family 0 was a
  12-member CHAIN: both column exemplars d=0.0 + true trio d=0.767-1.145 + 7
  hitchhikers (featurefam, line, fragments d=1.8-3.5), median poisoned to
  ~2.3 -> UNKNOWN; (B) fam 12 = 14- hearth exemplar d=0.0 chained with
  (7.5,26.0) d=1.093 (v1's false-confident, honestly downgraded), 2-member
  median takes the WORSE member -> proposal; (C) fam 1 = THREE TINY PIECES
  at d~42 at (14.2,17.1),(14.6,17.1), (15.0,17.7) - COLUMN TOPS SPLIT FROM
  BASES: blob-layer FRAGMENTATION CONFIRMED REAL (ask-list material, not a
  clustering bug); (D) metric's TRUE same-class spread is ~1.0 (two column
  exemplars ~0.88 apart -> that is why the bar is ~0.88 and the cut
  saturated at 1.2; lowering FAM_MAX to 0.6 would shatter exemplar pairs
  into singletons - REJECTED that plan); (E) singleton pure families work
  exactly right: 24-hearth (29.8,3.1) and fireplace (32.6,26.6) both
  confident at d=0.0. FIX SHIPPED: cluster() is now AVERAGE-LINKAGE
  (sorted-edge agglomeration, merge accepted only if MEAN pairwise
  cross-cluster distance <= cut) with root-array + cached pairwise distances
  - single-linkage chaining (one lucky edge) can no longer hang junk onto a
  clean family. FAM cut rails unchanged (0.05-1.2; the true spread needs
  1.2). Regression test PASSES: clean 3-blob family intact, junk chain
  blocked (junk pair merges among itself, third junk rejected at mean 1.35).
  507-blob worst case (dense synthetic junk) 29.4s in sandbox; real map-006
  junk at d=3-42 yields far fewer candidate edges, expect much faster.
  Canvas mapp-tool title (v2.2), byte-exact, md5
  169cc25e1f63e3eebe9ba5c158fb79c5 (CORRECTED: the seat first recorded an
  unverified md5 - never seat an md5 before the print runs). 411 lines,
  13672 bytes, py_compile clean, no lines >78, end-to-end import/match
  retested. HIS SIDE: save v2.2 canvas body -> tools/mapp.py (gate), rerun
  python3 tools/mapp.py tools/library.json ~/mb6s4/map-006.extract.json
  --ask (outputs now land in ~/mb6s4). EXPECTATIONS: family 0 should shed
  its hitchhikers; column exemplars + trio may merge as a 5-member column
  family (proposal, since median ~0.9 vs bar ~0.88 is borderline) -> if so,
  answer its ask question "column" and --learn settles it permanently;
  14-hearth may still pair with (7.5,26.0) (their mutual 1.09 <= cut is
  genuine similarity - ask will settle). THEN: answer ask-list (delete
  border-band y>=35 / y<=0 / x>=32 rows and giant floor blobs (20.4,23.2)
  115895px etc), name interior mid-size glyphs, --learn, rerun, watch
  confident count rise and question count drop - first real feedback-curve
  measurement.
  MAP v2.2 FIRST REAL RUN (2026-11-06, his mb6s4, md5 gate passed): 507
  blobs -> 173 families (avg-linkage is FINER than single: 72 -> 173; junk
  no longer chain- merges), cut still saturated 1.2, 170 questions (up from
  70 - EXPECTED trade: correctness up, question count up; border-band filter
  cuts the nameable set down). TALLY: CONFIDENT column 6 (!) + fireplace 1 +
  hearth 1; proposal column 44, hearth 21. THE HEADLINE: 6 CONFIDENT COLUMNS
  - 2 exemplars + very likely the (15.9,17.3)/ (16.0,17.7)/(15.5,18.6) TRIO
  seated WITHOUT human input (trio median d ~0.86 <= bar ~0.88) - the v1
  exemplar- blindness failure mode is CURED by family agreement; if the 6th
  is (15.0,18.6) or (14.1,18.3) the record's 3rd column may be seated too -
  VERIFY via confident-rows dump (match rows lack area; lat+cls only).
  NOTABLE ASK CANDIDATES (interior, sane areas): q2 col (18.5,26.2) 449px;
  q3 hearth (2.5,21.5) 555px d=0.468; q17 col (15.5,18.6) 368px d=1.616; q19
  col (30.4,6.1) 1021px; q73 col (2.6,18.7) 429px d=1.235 (v1's interior
  column candidate); q97 hearth (14.0,0.7) 783px d=1.141; q98 hearth
  (23.6,3.1) 17131px (near-record-row mass); q105 hearth (29.1,8.1) 11999px;
  q125 hearth (22.9,27.5) 9245px. q75 = 14-hearth exemplar family still
  proposal (chained w/ (7.5,26.0)? or alone w/ 2-member median; (7.5,26.0)
  NOT in ask list -> it went proposal hearth). CURATION PLAN FOR HIM
  (Termux-safe, no hand-editing JSON): (1) confident-rows dump; (2) filter
  one-liner for nameable interior questions (0.5<y<35, x<32, 50<=area<=
  20000) - border bands + giant floor blobs + tiny debris dropped
  programmatically; (3) answers-builder one-liner from compact spec string
  'qN=label,...' -> answers.json -> --learn -> rerun: watch confident rise,
  questions drop. NOTE: q75 needs no answer (exemplar already in library).
  MAP v2.2 RUN 2 ANALYSIS (2026-11-06, his confident-rows dump + nameable
  filter + failed answers attempt): (1) WIN CONFIRMED - family 23 contains
  the column exemplar (14.1,18.6) + TRUE TRIO (15.9,17.3) d=0.767 and
  (16.0,17.7) d=0.858 SEATED CONFIDENT COLUMN - the v1 exemplar-blind
  objects are now recognized with zero human input. But (15.5,18.6) did NOT
  seat: the two column exemplars got SPLIT by avg-linkage - (14.6,18.6)
  landed in family 17 (proposal column, rep (15.5,18.6) d=1.616) - so the
  record 3rd-column region is still pending, now via q17. (2) HONEST LIMIT -
  3 of 6 confident columns ARE V1's KNOWN BORDER IMPOSTORS: (8.9,30.5)
  cls=feature d=0.904, (29.2, 39.5) d=0.733, (27.6,35.8) d=1.123 - ALL THREE
  were v1's false-confidents, and they are GENUINELY COLUMN-SHAPED
  (0.73-1.12, within family spread) - shape alone cannot veto them; only
  location/role distinguishes. THIS IS THE SEMANTICALLY-CONSISTENT-IMPOSTOR
  CASE predicted in the v1 era. LIBRARY-COMPETITION FIX (no code change): he
  TEACHES the impostors their true label (e.g. border-pillar/ decor) via a
  teach one-liner (build answers rows from extract by nearest lat); their
  entries then compete, family 23 member-argmin agreement drops below 2/3
  and the over-claim DE-SEATS ITSELF - the veto class is just a library
  label. (3) 14-hearth (q75) STUCK at proposal: family 75 is the persistent
  pair {(6.0,32.5) exemplar, (7.5,26.0)} - mean 1.09 <= cut so avg-linkage
  keeps them paired, 2-member median takes the WORSE = 1.093 > hearth bar;
  answering q75 'hearth' is a NO-OP (dedupe). The real question is WHAT IS
  (7.5,26.0) - his eyes. (4) MY BUG (not his, not the tool's):
  answers-builder one-liner keyed dict by '17' but looked up 'q17' -> 0
  answers, learn no-op'd. CORRECTED builder keyed ('q'+id). Teach one-liner
  (review corrections on confident rows): builds answers rows from extract
  by nearest lat 'latx,laty:label' -> map-006.teach.json -> --learn.
  FEEDBACK-CURVE BASELINE: run2 identical to run1 (8 confident, 170
  questions) since learn no-op'd - the true post-learn measurement comes
  after his real answer batch.
  MAP v2.3 SHIPPED (2026-11-06): --TEACH MODE - his teach one-liner (~460
  chars) hit the TERMUX PASTE-GARBLE wall (IndexError: the ':decor' tail
  eaten -> the v1.2 lesson repeated: NEVER give him one-liners that long).
  New tool mode replaces the one-liner entirely: mapp.py --teach
  "x,y:label;x,y:label" EXTRACT.json --lib LIB.json - resolves lats against
  the first extract (EX_TOL 0.4, warns on misses), appends entries source
  human-teach, saves sorted+deduped. Termux-safe command is now short.
  Docstring usage updated. Canvas mapp-tool title (v2.3), byte-exact,
  md5 b311e91d006c6f0f9203507aee26cf68, 456 lines, 15331 bytes, py_compile
  clean, no lines >78. Functional test: taught (10.0,10.0) column d=0.000,
  (99,99) ghost correctly warned-off (nearest 125). HIS STATUS: answers.json
  already built (q17+q73 column, 2 rows) but NOT YET LEARNED; teach row
  (29.2,39.5:decor) not yet taught. HIS NEXT: save v2.3 canvas body ->
  tools/mapp.py (gate b311e91d006c6f0f9203507aee26cf68), then --learn
  answers, --teach his review corrections (border impostors
  (8.9,30.5),(29.2,39.5),(27.6,35.8) -> their true label; also (7.5,26.0) -
  resolves the 14-hearth pair), rerun --ask, measure the curve.
  POST-LEARN RUN (2026-11-06, his mb6s4, library now 12 entries: 6 legacy +
  2 learned (q17/q73 column) + 3 taught decor + ... note his earlier single
  decor teach): 507 blobs, 173 families (same clustering, library-
  independent), 14 CONFIDENT (was 8): column 6, decor 6, fireplace 1, hearth
  1. KEY SURPRISE: confident DECOR = 6 from only 3 taught - the 3 taught
  blobs formed their own family and swept in 3 more members via agreement
  (the veto label became a POSITIVE family, better than the predicted
  de-seat-by-agreement-drop). Confident column STILL 6 but likely a
  DIFFERENT composition (family 23 agreement should have dropped to 3/6 with
  impostors' argmin now decor; family 17 with q17 learned likely seated -
  q17 vanished from the ask list). NEEDS VERIFY: confident-rows dump. Also:
  q73 improved 1.235 -> 1.086 (bar widened from more column entries). q75
  14-hearth pair STILL proposal (he has not taught (7.5,26.0) - the open
  question). Feedback curve so far: ~6 human answers -> confident 8 -> 14;
  question count 170 -> 169 (ask rows convert to seats, not to silence -
  unknown debris still asks). NEXT: confident dump, then his next answer
  batch from nameable interior set (hearth candidates q3/ q97/q98/q105/q125;
  column-candidates q2/q19/q36/q66); teach (7.5,26.0); border-band decor
  proposals (33 rows best=decor at d 1.1-1.8) may be auto-resolving into
  decor via future answers.
  MAP v2.4 SHIPPED (2026-11-06, MEMBER ANCHORING - custody of the KNOWN):
  HIS DUMP REVEALED THE CROSS-WIRE - family 23 flipped CONFIDENT DECOR
  containing the TRUE TRIO + column exemplar (d=0.733!), while family 17
  seated confident COLUMN on border-band glyphs ((17.7,
  -2.0),(32.4,35.7),(32.5,37.6),(24.3,38.8)) + his q17 answer (15.5,18.6).
  ROOT CAUSE: column and decor are SHAPE-IDENTICAL; teaching decor injected
  3 column-shaped signatures into shape space, and the family layer gives
  ONE label per family - whichever label's entries sit nearer wins the WHOLE
  family. My library-competition prediction FAILED (predicted de-seat; got
  hijack). THE FIX (doctrinal, was in the doctrine all along): CUSTODY OF
  THE KNOWN - a member whose OWN nearest-label distance <= that label's bar
  is ANCHORED: it keeps its own label, confident=True, kind=anchored, and
  the family vote can NEVER override it. Family labeling is now a proposal
  mechanism for the UNSSEATED only. member_own() computes per-blob nearest
  label + margin; families with all members anchored emit no ask rows; the
  ask rep for mixed families is the largest UNANCHORED... (largest member -
  noted). REGRESSION PASSES: mixed family (column entries v=1.0/1.88, decor
  entry v=1.3 IN COLUMN SPACE, hearth v=8): exemplar stays column, taught
  blob stays decor, hearth exemplar anchors, unanchored blob asks -
  cross-wire fixed. STUCK-14-heARTH also fixed by anchoring (exemplar d=0.0
  anchors hearth; (7.5,26.0) gets asked on own merits). THE CEILING (honest
  limit, structure layer's job): border glyphs SHAPE-IDENTICAL to columns
  ((17.7,-2.0) d=0.383) will still anchor column - shape alone cannot veto
  location; the mapbatch v2 front half (grid/wall extent) supplies
  interior-vs-frame context later; until then his diff- review is the veto.
  Canvas mapp-tool title (v2.4), byte-exact, md5
  472221c80880a551f6bd7560f6c3a1fd
  (verified against the print; the first draft of this seat
  wrote a placeholder md5 - lesson holds) . 504 lines, 16972
  bytes, py_compile clean, no lines >78. HIS NEXT: save v2.4 canvas body ->
  tools/mapp.py (gate), rerun --ask, expect: family 23 splits per-blob (3
  column + 3 decor), family 17 border junk still anchors column (ceiling),
  (17.1,18.6) at d=0.927 SHOULD now surface as ask, q75 exemplar anchors
  hearth + (7.5,26.0) asked.
  MAP v2.4 FIRST RUN (2026-11-06, his mb6s4, gate passed 472221c8...): 31
  CONFIDENT (8 -> 14 -> 31 across three runs), 169 questions, unknown 421.
  Tally: anchored column 13, decor 7, fireplace 1, hearth 9; family-
  confident column 1; proposals column 17 / decor 31 / hearth 7. ANCHORING
  WORKS: family 23 split per-blob (no ask row), family 17 left the ask list
  - (17.1,18.6) at d=0.927 ANCHORED column (bar widened by the learned
  column entries), cross-wire gone. WATCH-ITEMS: (1) anchored hearth 9 -
  bar(hearth) from 3 DIVERSE entries (24-hearth 15666 / 14-hearth 9741 /
  firepit 430) rides the CAP 0.90, so 9 blobs anchored at d<=0.9 - WIDER
  than the 3 exemplars justify; possible over-claim among those 9, NEEDS his
  confident-rows dump; corrections are now SAFE though (v2.4 anchoring: a
  taught correction re-anchors the blob without hijacking family labels).
  (2) anchored column 13 includes the ceiling blobs (border shape-identical
  junk, accepted limit until structure layer). (3) q75 family 75 STILL asks
  - the exemplar is presumably among the 9 anchored hearths, the question is
  for (7.5,26.0) (family dist 1.093). FEEDBACK CURVE: confident 8->14->31
  with ~11 human answers total; questions flat (169 - unknown debris
  dominates; seats convert asks to labels, debris keeps asking). NEXT: his
  confident-rows dump (verify the 9 hearth anchors + 13 column anchors
  against the record), then answer batch q3/q97/q98/q105/q125 + teach
  (7.5,26.0) + any wrong-anchor corrections.
  MAP v2.4 CONFIDENT-DUMP REVIEW (2026-11-06, his mb6s4): 31 seats read -
  TRUE WINS: both column exemplars + (15.5,18.6) + (2.6,18.7) + (17.1,18.6)
  all anchored column (record row now well seated); firepit exemplar
  (16.1,21.7) anchored hearth; 24-hearth + 14-hearth anchored; fireplace
  anchored. THE OVER-CLAIMS (as predicted, bar-ride at the 0.90 cap): 5 of 9
  hearth anchors are BORDER-BAND glyphs at d 0.27-0.55 ((12.4,
  38.4),(7.5,39.6),(33.1,37.6),(4.2,35.7),(4.3,39.6)) - hearth-shaped frame
  art, same ceiling as border columns. THE SURPRISE: THE TRIO ((15.9,17.3)
  d=0.582,(16.0,17.7) d=0.655) ANCHORED DECOR - the decor entries are SHAPE-
  NEARER to the trio than his learned column entry (15.5,18.6) is - shape
  evidence in the library currently favors decor for the trio; only his eyes
  settle it (v1 had them column-ambiguous at 0.767-1.145). Also (18.5, 26.2)
  interior anchored decor (0.854) - review, and (2.5,21.5) interior
  cls=feature anchored hearth 0.82 - possibly real, his call. FAM 3 is a 15+
  member MEGA- FAMILY (firepit+columns+border art chained) - anchoring
  neutralized the damage (v2.4 vindicated) but confirms shape-space is a
  continuum for these classes. HIS MISTAKE TO FIX: he pasted my placeholder
  literally - label "whatever-it-is" now exists w/ the (7.5,26.0) 8737px
  mass; rename one-liner given (pop+reinsert). HIS NEXT: (1) rename; (2)
  verdict batch - teach trio true label if columns
  ("15.9,17.3:column;16.0,17.7:column"), teach the 5 border hearth-shapes a
  frame/decor label, decide (18.5,26.2) + (2.5,21.5); corrections are SAFE
  under anchoring (own-entry re-anchor, no hijack); (3) hearth answer batch
  q97/q98/q105/q125; (4) rerun - expect the bar to narrow with real spread
  data.
  HIS VERDICT (2026-11-06): the (7.5,26.0) 8737px mass IS A WALL - rename
  whatever-it-is -> wall commanded. INSIGHT: the big-mass candidates (q96
  21790, q103 41199, q112 13186, q122 7815, q135 9751, q136 8361, q63
  115895, q78 4166) are probably mostly STRUCTURE (wall chunks / room
  fills), which is why they hovered at hearth-proposal distances - big blobs
  resemble the 24-hearth/14-hearth masses in size but are walls/floor, not
  hearths. Guidance given: teach obvious wall masses as "wall" (a few
  teaches form the vocabulary; wall blobs are NOT a tight shape family but
  anchoring works per-blob anyway), do NOT force hearth labels on masses;
  the record's real hearths are already anchored. Longer term wall inventory
  is the mapbatch structure layer's job - the "wall" label is review
  vocabulary for now.
  POST-VERDICT RUN (2026-11-06, his mb6s4, library ~21 entries): 35
  CONFIDENT (8->14->31->35), 166 questions. Tally: anchored column 17, decor
  8, fireplace 1, hearth 4, wall 4; family-confident column 1; proposals
  column 23 / decor 23 / hearth 2 / wall 3; unknown 421. THE EMERGENCE
  PREDICTED AND SEEN: wall entries flipped the big masses from hearth's
  orbit - q105 (29.1,8.1) 11999px now wall proposal 1.482, q136 (30.4,32.0)
  8361px wall proposal 1.449, q135/q104/q110/q115/q126/q143 all best= wall -
  structure separating from objects via library competition, no code change.
  BAR TIGHTENING OBSERVED: hearth anchors 9 -> 4 (the 5 border shapes
  re-anchored decor d~0 as taught; bar hears narrowed), and (18.5,26.2)
  DROPPED from anchored decor 0.854 back to decor proposal 1.145 - the
  8-entry decor bar tightened below 0.854 - honest behavior. TRIO NOW
  ANCHORED COLUMN d=0 as taught. INTERIOR OPEN QUESTIONS for his eyes (the
  short list): q98 (23.6,3.1) 17131px hearth prop 1.681; q125 (22.9,27.5)
  9245px hearth prop 1.465 (the last two hearth-ish masses); q3 (2.5,21.5)
  decor prop 0.375 (tightest question; cls feature); q2 (18.5,26.2) decor
  prop 1.145 (verify); q19 (30.4,6.1) column prop 1.485; q36 (28.2,16.8)
  column prop 1.264; q73 column prop 0.978; wall proposals q105/q136 (teach
  if walls). BORDER DEBRIS: leave for the structure layer (mapbatch v2 front
  half per grid-spec - the NEXT mapp component to build once his verdict
  batch lands). FEEDBACK CURVE: ~20 human answers total -> 35 seats + 51
  proposals with sane best-labels; the curve is bending on schedule.
  PHASE-1 NEAR-COMPLETE (2026-11-06, his mb6s4, library ~24 entries): 41
  CONFIDENT (col 17, decor 13, fireplace 1, hearth 3, wall 6, fam-conf col
  1), 163 questions, 412 unknown. WALL EMERGENCE CONTINUES: q96 (10.0,3.2)
  21790px wall prop 1.591, q98 (23.6,3.1) 17131px FLIPPED hearth->wall prop
  1.661, q135 wall prop 1.342; q125 (22.9,27.5) 9245px is the LAST
  hearth-orbit mass (his verdict closes the hearth row). Q3 (2.5,21.5)
  answered decor + learned -> anchored. MINOR BUG FOUND (cosmetic, not
  corrupting): cmd_learn counts ROWS not ADDITIONS - prints "1 entries
  added" even when dedupe skips; fix in next version bump. ALSO NOTED: ask
  rep is largest member of the family INCLUDING anchored ones - a family
  with one unanchored member still shows its anchored rep; the question is
  for the family, not the rep (slightly confusing UX, acceptable). REMAINING
  INTERIOR VERDICTS (his eyes, one batch): q125 hearth-or-wall; column
  candidates q19 (30.4,6.1) 1.485, q31 (29.4,30.2) 1.488, q36 (28.2,16.8)
  1.264, q73 (2.6,18.7) 0.978; decor-ish q2 (18.5,26.2) 1.145, q66
  (8.6,14.4) 1.135; wall props q96/q98/q135 (teach if walls). THEN PHASE-1
  OBJECT LAYER IS DONE pre-structure: the remaining ~150 questions are
  border/frame debris + fragments = the mapbatch v2 front half's job
  (grid-spec: assert-map periodicity, ranked grid hypotheses, wall seating
  convention, scale statement). NEXT MAPP COMPONENT on his GO: the grid
  front half.
  MAP v2.5 SHIPPED (2026-11-06): three additions after his (22.9,27.5)
  verdict round: (1) HIS RUN landed 45 confident (col 17, decor 13,
  fireplace 1, hearth 3, WALL 9, "your-call" 1, fam-conf col 1), 159
  questions; q125 verdict answered "your-call" LITERALLY - the placeholder
  trap caught him a SECOND time (after "whatever-it-is"); "your-call" is now
  a label with the (22.9,27.5) 9245px mass anchored under it, PENDING his
  eyes via --around then --rename. (2) HE ASKED FOR AN IMAGE of the region
  "to see if it's just the grid" -> v2.5 adds --AROUND "x,y" EXTRACT: ASCII
  neighborhood map +/-5 squares, step 0.5, anchored labels UPPERCASE,
  proposals lowercase, unknown dots, + marks the queried center,
  top-8-by-area legend below; reads stem.match. json beside the extract for
  labels (asks to run match first if missing). (3) --RENAME "OLD:NEW" --lib:
  moves or MERGES a label; (4) LEARN/TEACH/IMPORT now count actual ADDITIONS
  (add_entry returns bool; duplicate learn prints 0 - the cosmetic bug
  fixed). Functional tests pass: around renders labeled context, rename
  merges, dedupe counts honest. Canvas mapp-tool title (v2.5), byte-exact,
  md5 098d840237f186369c84ceddd838c e49 FULL:
  098d840237f186369c84ceddd838ce49, 610 lines, 20524 bytes, py_compile
  clean, no lines >78. HIS NEXT: rm tools/mapp.py && nano (paste v2.5 canvas
  body), gate 098d840237f186369c84ceddd838ce49, then python3 tools/mapp.py
  --around "22.9,27.5" ~/mb6s4/map-006.extract.json to eyeball the mass in
  context, then python3 tools/mapp.py --rename "your-call:REALNAME" --lib
  tools/library.json PLACEHOLDER RULE HARDENED: never put
  placeholder-looking strings in teach/rename specs without asking him the
  name first - twice burned.
  HIS VERDICT + v2.5 RUN (2026-11-06): gate passed (098d8402...), --around
  worked (first context view on real data). HIS VERDICT: the (22.9,27.5)
  9245px mass is an EMPTY SQUARE - nothing there: mapbatch's extractor picks
  up blank floor regions as mass blobs. He renamed your-call ->
  "its-real-name" LITERALLY - PLACEHOLDER TRAP CAUGHT HIM A THIRD TIME; a
  "its-real-name:empty" rename is queued for him. INSIGHT: the big interior
  masses are mostly NOT objects - they are floor/fill/ empty-square regions
  (q63 115895px giant is floor fill, wall-taught masses were wall chunks);
  "empty" is the purest veto label - claiming "nothing here". The --around
  view of the region showed: center Y (the mass), walls W + D + C proposals
  at the fringes, the 115895px UNKNOWN giant at (20.4,23.2) nearby - the
  region is open floor between walls, consistent with his read. LESSON
  RE-SEATED: placeholders in pasted specs keep getting pasted literally -
  from now on every rename/teach block he receives must carry a REAL name
  confirmed by him first, or an explicit "replace this word" warning line
  above the block.
  PHASE-1 COMPLETE (2026-11-06): rename landed (its- real-name -> empty),
  taught (20.4,23.2) empty, rerun: 46 CONFIDENT (col 17, decor 13, EMPTY 2,
  fireplace 1, hearth 3, wall 9, fam-conf col 1), 159 questions, 410
  unknown. EMPTY EMERGING AS A FLOOR FAMILY: family 63 (the 115895px giant's
  family) shows other floor masses best=empty ((17.5,36.6) 31210px d=3.164)
  - floor blobs cluster together and empty is claiming them; family 63 still
  asks because it has unanchored floor members (the anchored giant is its
  rep). FEEDBACK CURVE FINAL: 8 -> 14 -> 31 -> 35 -> 41 -> 45 -> 46
  confident across ~30 human answers; question count plateaued ~160 (unknown
  pool is border/frame debris + fragments - the structure layer's job).
  PHASE-1 OBJECT LAYER ON MAP-006 DECLARED DONE pre-structure: every
  interior object verdict is in; remaining asks are frame debris, fragments,
  floor fills. NEXT MAPP COMPONENT ON HIS GO (not yet given): the GRID FRONT
  HALF per grid-spec (stages 0-3: decode + assert-map periodicity;
  enumerated grid hypotheses ranked w/ margins; wall seating brute force w/
  quantization discriminator; scale statement; grid statement JSON) - it
  draws the interior/frame line that shape-space cannot, gives the 410
  unknowns a place to live, and supplies the lattice context mapp.py's
  labels have been implicitly reaching for.
  KITCHEN-WING CORNER
  (cols 11-15, rows 5-11)
  NOW CLOSED: walls on
  Y5-Y10 (+0.1 to +0.15
  pitch south drift),
  verticals X11-X15 as
  scanned (X11, X14
  thick; X10/X12/X13
  thin), label "20" at
  cols 13-14 straddling
  Y9, door on Y6 cols
  13-14. QUEUE UPDATE
  2026-11-05 (full-res
  X9/X11 scans, both
  copies agree): (a)
  D-18-SE (18<->
  corridor, rows 12-13):
  NO drawn door at full
  res - absence is REAL,
  thin-wall artifact
  ruled out; door stays
  ADJUDICATED-ONLY
  (drawn-face caveat
  class). (b) Draft's
  X11 "doors to 20" row
  8 + "Y10 junction
  door" row 10 DO NOT
  REPRODUCE in either
  copy (X11 solid rows
  7-16, 0.71-0.89) -
  downgraded to
  unverified; possible
  drawn-on-texture
  door leaf (ASCII/eye
  check pending) or
  misread. ASCII RESULT
  2026-11-05: PLAIN WALL
  - clean flanks, no
  leaves/voids/labels
  at rows 8 or 10;
  BOTH X11 door claims
  DEAD (misreads).
  20's drawn access =
  only the shared
  20-21 opening (Y12
  cols 10.2-10.9). Faint
  gray smudge west of
  X11 just S of Y8
  (fullres y~1009) =
  faint-feature class
  (counter ink, not
  door). NEW FINDING
  from same ASCII:
  horizontal walls at
  Y7, Y8, Y9, Y10
  (~5-6px thick, south
  drift) T into or
  CROSS X11 - the
  k9-11 "corridor" may
  be a stack of cells,
  not an open passage.
  My copy's h-scans
  under-read them
  (drift + thinness).
  WEST-HALF ASCII RESULT
  2026-11-05: NOT A
  CORRIDOR. X9 thick
  (20px), X10 thin (~8px,
  slight east drift),
  X11 thick; Y7, Y8, Y9,
  Y10, Y11 solid
  horizontal walls
  full-width, ZERO
  gaps/doors; cell
  interiors CLEAN paper.
  The k9-11 strip rows
  7-11 = SEALED GRID of
  EMPTY CELLS, 2 wide x
  5 tall - every wall
  solid, nothing drawn
  connecting anything.
  Draft's corridor ruling
  (vision-only) REVISED.
  Only unprobed access:
  north end rows 6-7
  (Y6 divider to Y7) and
  south end rows
  11.5-13 (before X9
  ends at Y14). END
  PROBES + CURTISS
  EYE-CHECK 2026-11-05:
  ACCESS FOUND AT THE
  NORTH END ONLY. The
  Y6 divider at the
  strip top is a
  DOUBLE-LINE structure
  (upper line fullres
  y857-861 x781-873;
  Y6 wall y873-881)
  with black stubs at
  x781-793, X10,
  x865-877, and TWO
  WHITE DOOR-SIZED
  POCKETS between the
  lines: x793-821 and
  x833-861 (each ~28px
  = 0.45 pitch), one
  per cell column =
  TWO DOORWAYS from
  room 19 into the
  strip. Curtiss
  recognizes the door
  on the printed map.
  SOUTH END SEALED:
  Y12 and Y13 solid
  through the strip,
  cells empty, X9
  continues to Y14.
  RULING: the strip =
  CELL SUITE entered
  ONLY from room 19
  (servants). Corridor
  identity DEAD:
  no drawn link to 18
  (D-18-SE stays
  adjudicated-only),
  none to 20, none
  south. Pending:
  module key for what
  the strip is +
  door count/details
  eye-confirmation.
  (c) Corridor
  enclosure CONFIRMED:
  X9 and X11 solid rows
  7-14+, genuine
  enclosed N-S corridor
  north of the kitchen
  wing. (d) north-wall
  gap item = STALE
  (adjudicated 11-03).
  REMAINING QUEUE: X11
  door-leaf check, k9-11
  area identity,
  outbuilding internal
  walls (24/25/A crop).,
  18's claimed left-
  wall door (no pixel gap yet),
  north-wall gap ruling, the
  k9-11 area identity,
  outbuilding internal walls
  (24/25/A detail crop needed).
  USER SCOPING NOTE (2026-11-03):
  the upper level's geometry is
  not difficult - 25 rooms
  (keys 1-25 + lettered sub-areas
  10A, 18A, A, B) and only THREE
  corridor-class areas: 11 (the
  Long Hall, explicitly an 80'
  passagement), the eastern
  section (its own wandering
  table zone, the lodge's east
  corridor), and the outbuilding
  connection (the passage
  through the palisade to the
  guard room). The Great Hall is
  a KEYED ROOM (tables, fire
  pit, dais), not a corridor.
  Trace shape: room interiors
  generate from rects; the three
  corridors take ':' ink; the
  difficulty concentrates in the
  POINT work (door mates, the
  stockade's irregular line, the
  compound's open edges, the
  18A-dungeon stair link), not
  the room geometry.
  KITCHEN-WING + STRIP PASS 2
  (2026-11-03, draft at
  tool-results/g1-skeleton/
  northstrip_draft.json, valid
  JSON): the wing's wall lattice
  is pixel-complete for rows
  0-18: X2 (lodge west face,
  rows 10-34), X4 (west-strip
  divider, k~4.1), X6 (wing west
  edge with TWO door gaps rows
  11-14 = 18<->18A access), X9/
  X11 (kitchen block dividers,
  X11 with doors at row 8 and
  row 10), X14 (compound west,
  door tiles cols 12-13 row 8),
  X20 (row-1 only; NO wall below
  Y6 - the yard opens west),
  X26 (yard east), X27 (top-pen
  east, row-1), X33 (east
  stockade); horizontals Y0
  (north wall, OPEN GAP cols
  15-16), Y6 (divider with the
  yard's open north mouth cols
  13-18 and a door-like 8px gap
  at k26.1-26.5), Y10 (kitchen
  north; faint-thin drawn wall,
  absent k8-9.1 = corridor
  mouth), Y12 (20-south), Y14
  (18A north k4-9.1 ABSENT k9-14
  = 21 opens north; yard south
  k14-33), Y18 (12/13-block
  north, gap k9-10), Y16 (SE
  block k22-26). IDENTITIES:
  19=cols 6-11 rows 1-5 (label
  blob col 12 row 2), 17-
  CANDIDATE=cols 6-8 rows 6-9
  (no label read - kitchen by
  module adjacency, confirm on
  300dpi), 18=cols 5-8 rows
  11-13 (label V2/V6; light
  X7/X8 lines inside = drawn
  COUNTERS not walls), 18A=
  cols 3-8 rows 14-17 ('A' blob
  col 5.5 row 16.6; STAIRS
  location pending, points
  pass), 20=cols 9-12 rows 6-11,
  21=cols 9-13 rows 14-17, 22=
  compound cols 19-25 rows 1-5
  (TOP PEN, '22' blob col 20
  row 2) + south yard cols 13-25
  rows 6-13 (door-connected),
  23=cols 25-31 rows 6-13, 24/
  25/A=outbuilding cols 26-31
  rows 1-5, 12/13 glyph cluster
  cols 14-16 row 19.6. THE
  K9-11 STRIP (cols 7-8, rows
  6-13) = CORRIDOR (vision
  confirms): connects kitchen
  block N, 20 door row 8, 21 S
  - the kitchen-wing arm of the
  circulation; per the user's
  scoping note the named three
  corridors are 11/eastern-
  section/outbuilding-connection
  - this strip likely belongs
  to the eastern-section system,
  pending the great-hall pass.
  MGRID FRONT HALF 2026-11-06 (canvas mgrid-tool, v1.0,
  paste-gate PENDING on his side): stages 0-3 of grid-spec
  v0.1 shipped - stage 0 assert-map (ink census + axis
  autocorr on SEPARATED structure; reject = full stop, no
  fitting fields), stage 1 enumerated ranked comb
  hypotheses (coverage + spurious-line penalty +
  residual; spurious term kills subharmonic divisors -
  fixture C caught pitch/4 winning without it), stage 2
  wall seating brute force (mod-1 deduped offsets x
  thickness; edge agreement + corner closure vs the
  CROSS-axis wall comb + length quantization; thin
  margin asks), stage 3 scale (dpi trusted:false, hint,
  prior; two agree = confirmed, conflict = ask, silent
  default never). PORTED FROM MAPBATCH v1.8: structural
  separation (vertical/horizontal runs >= 15%) - without
  it full-width rules poison the cross-axis profile and
  bands() merges the whole map into one band. Also fixed
  in the build: Otsu tie-plateau (inclusive <= threshold;
  exclusive < dropped the whole ink class on sparse
  fixtures). BATTERY GREEN: fixture A (64px rooms, walls
  at cell centers) -> P=63.97, seat offset +0.50, quant
  0.09, margin 0.78; fixture C (anisotropic 80/96, walls
  at +P/4) -> 79.95/95.93, offset +0.25; fixture B
  (blotches) -> rejected-not-a-map, no provenance.
  END-TO-END via jdec: 513x513 JPEG -> P=63.97 cells 8x8
  ink explained 0.985, seat +0.50 margin 0.933, scale
  unknown (ASK, correct - no source), .grid.json beside
  the input. Runtime ~0.6s at 1500x1500 (Termux fine).
  Test harness (mkjpg minimal baseline encoder +
  battery.py) is sandbox-only, NOT shipped. FIRST
  REAL RUN 2026-11-06: fast on Termux (the earlier
  "long time" worry was moot), map is at
  extract/g1/map-006.jpg (NOT ~/mb6s4 - that folder
  holds mapp outputs only). v1.0 REJECTED map-006
  at the assert gate: x ac 0.410 z 3.6 vs z-floor
  4.0. The dump showed a textbook harmonic ladder -
  x peaks 64/127/191/254/318 (all multiples of
  ~63.6), y peaks 64/128/192/256/384, i.e. a ~64px
  fundamental whose ac sums harmonics; the ladder
  itself inflates the ac landscape spread and
  deflates the winner's z. v1.1 GATE FIX: ASSERT_Z
  stays 4.0 but a peak below it (>= ASSERT_Z_SOFT
  3.0) passes ONLY with harmonic-ladder corroboration
  (another strong peak at near-integer multiple/
  fraction of the winner's lag, LADDER_TOL 0.05;
  his data: x corroborated 4x via 64, y 6x via 64;
  noise-peak set with no ladder still rejects).
  Fixtures re-verified green post-fix; validated
  directly against his dumped peak lists. Note:
  two sandbox resets ate the working copy before
  shipping - the canvas is the only durable copy;
  ship BEFORE further edits. NEXT: he re-pastes
  tools/mgrid.py (v1.1), runs the md5 gate, then
  python3 tools/mgrid.py ~/Adnd1/extract/g1/
  map-006.jpg - expect asserted now, and watch what
  the comb stage does with a ~64px fundamental on
  a big anisotropic scan.
  v1.1 LANDED + FIRST REAL GRID STATEMENT (his
  run, 2026-11-06): md5 gate PRINTED AND MATCHED
  c2e17c6f61d5d6284b7623c02c32f2e6 (v1.1, seated).
  map-006 asserted via the ladder path; comb
  seated the ~64px FUNDAMENTAL over the 254/384
  macro-peaks: P=63.72 Q=64.03 (near-square, 0.5%
  wobble), cells 39x51, ink explained 0.792, seat
  offset +0.00 both axes, margins 0.28/0.31
  (above the 0.10 ask line, no seating ask), scale
  unknown ASK (correct - no source). OPEN
  SUSPICIONS before blessing offset +0.00:
  measured_thick 0.317/0.293 vs snapped 0.125
  (~20px wall bands - bands() may be merging
  rule+wall+rule when walls sit ON cell lines, or
  double-lined wall style), and length_quant
  0.31/0.30 (should collapse toward ~0 under the
  correct convention). Awaiting his seating dump
  from map-006.grid.json to rule merge artifact
  vs real drawn-on-the-line walls. The 39x51
  lattice is the frame the kitchen-wing coords
  (cols 11-15, rows 5-11 etc.) were reaching for.
  SEATING RULING CLOSED (2026-11-06, band-width
  probe + his visual open of the raster): offset
  +0.00 is REAL - walls drawn ON the cell lines.
  Wall band widths: x 30/17/39/19/18/15/13/16/6/
  16/33, y 38/20/19/15/16/8/15/14/6/9/34/31 -
  spread 6-39 = MERGE SIGNATURE, not fat ink:
  on-line walls fuse with their rules into single
  bands (the missing thin bands - only 21x/29y
  rule bands on a 39x51 map - live inside the
  merged thick bands). measured_thick 0.317 was
  a merged-band average, inflated; length_quant
  and closure were polluted by run_spans
  stitching runs across crossing rules. v1.2
  FIXES QUEUED (for the structure layer's wall
  work, not the lattice): (a) band-split pass -
  fat bands split at rule seams, (b) wall runs
  measured against cross-axis WALL bands, not
  raw ink. RASTER IDENTITY CONFIRMED VISUALLY:
  he opened extract/g1/map-006.jpg in the
  gallery (after the termux-open/Acrobat-default
  detour: apps cannot read Termux-private paths;
  copying to ~/storage/shared/Pictures works) -
  "it's the full map". OPEN ITEM CLOSED
  (his ruling, 2026-11-06): the 31x40 he's been
  using is the BOUNDING BOX AROUND THE BUILDING -
  three nested rectangles, all consistent: 31x40
  building bbox < 39x51 measured scan grid
  (building + printed yard margin ring + road
  continuation) < 53x62 authored composed canvas
  (trace 33x42 + 20 margin). The measured
  39x51 is the printed page's full grid, not an
  error; HIS CONFIRMATION: 39x51 is CORRECT for
  the back half's cell coords - expansion to the
  53x62 composed canvas happens later, at
  yard-composition time, not in mgrid's
  statement.
  GRID FRONT HALF COMPLETE: the lattice statement
  (P 63.72 Q 64.03, 39x51, offset +0.00) is the
  seated contract; mapp's 46 confident answers
  and the kitchen-wing geometry now have their
  cell coordinates for the back half.
  MSEAT BACK HALF 2026-11-06 (canvas mseat-tool,
  v1.0, md5 bd4bdbe2496302554ef399ef305e39b6,
  GATE PRINTED AND MATCHED on Curtiss's side,
  real run DONE 2026-11-06): the back half
  LANDED. Run on extract/g1/map-006.grid.json
  + ~/mb6s4/map-006.match.json: 507 rows
  seated on 39x51, 0 asks. LEGACY TRANSFORM
  (the margin-offset measurement, rms 0.01
  n=507): x cell = 1.0088*lat + 1.849;
  y cell = 1.0087*lat + 6.787 - the old
  31x40 bbox lattice sits at offset
  (+1.85, +6.79) in the 39x51 grid, scale
  ~1.009 (the ~0.9% stretch = pitch
  difference, old vs new). 46 CONFIDENT
  rows seated (17 col anchored + 1 col
  confident + 13 decor + 2 empty +
  1 fireplace + 3 hearth + 9 wall
  anchored) = the 46 confident answers,
  matching mapp's count. 410 UNKNOWN
  review = unproposed fragments, fine.
  Output ~/mb6s4/map-006.cells.json. Reads GRID.json
  MSTRUCT STRUCTURE LAYER 2026-11-06 (canvas
  mstruct-tool, v1.0.1, md5
  0fb132aaaabdf127fe684ef330295797, GATE
  PRINTED AND MATCHED, real run DONE
  2026-11-06): the
  v1.2 queued fixes BUILT as a standalone
  tool (imports mgrid for decode/binarize;
  needs jdec.py + mgrid.py beside it in
  tools/). Core: the band-split is by WIDTH,
  not band surgery - per position along a
  seated line, contiguous ink WIDTH through
  the line center separates wall (>WIDE_MIN
  6px, the THIN_MAX rule doctrine + 1) from
  a COLLINEAR rule (thin: a gate gap in a
  ring wall sharing its line with a rule
  STAYS a gap); crossing rules add only
  slivers of wide positions (their own
  thickness), far below the per-cell WALL
  fraction 0.5; runs built only from wall
  cells so they never stitch across rules
  (the length_quant pollution is dead by
  construction). Per-line classes: empty/
  crossed (crossing rules only)/rule
  (collinear, sustained presence >= 0.80
  but never wide)/wall/wall+rule/mixed.
  Flanked gaps (<= GAP_MAX 3 cells) = door/
  opening candidates with interior_ink hint
  (drawn door leaves would lift it - HINT
  ONLY per the door doctrine; rulings stay
  wall-gap geometry + module text +
  v1.0.1 FIX (his first run caught it:
  splitext left the .grid on the stem, so
  find_raster probed map-006.grid.jpg and
  missed map-006.jpg beside it - now strips
  a trailing .grid before joining the
  extension, and probes upper-case
  extensions too; unit-tested).
  Curtiss). --cells cross-checks mseat
  confident wall rows against measured
  runs (mismatch asks). Output <stem>.
  structure.json beside the grid file;
  raster = same stem .jpg/.jpeg/.png or
  --raster. BATTERY GREEN: fixture A
  (rules on even x-lines + odd y-lines,
  ring walls ON rule lines with a carved
  gate gap, interior wall on a rule line
  with a door gap, wall off rules crossing
  rules, empty cells) - all runs/gaps/
  classes recovered exactly; fixture B
  (rules only) zero wall runs; cross-check
  ok/off/other exact + one ASK. Usage:
  python3 tools/mstruct.py extract/g1/
  map-006.grid.json --cells ~/mb6s4/
  map-006.cells.json
  FIRST REAL RUN: state ask, 209 wall runs,
  670 wall cells, 57 gap candidates; x
  census {crossed 2, empty 4, wall 34}, y
  {crossed 1, empty 7, mixed 3, wall 41} -
  NO rule/wall+rule classes: every inked
  line carries wall ink (dense interior
  walls; rules survive only as crossed/
  mixed slivers). CROSS-CHECK: 2 wall rows
  on runs, 7 OFF (review list): rows 42
  (25.60,9.87), 192 (9.41,32.99), 193
  (26.50,31.00), 274 (21.51,38.97), 275
  (27.05,39.00), 277 (32.48,39.03), 455
  (32.04,46.46) - clusters near y-lines 33
  and 39 and x-line 32; suspect WIDE_MIN
  sensitivity (wall ink fading below 6px
  at door jambs / wall ends) or label
  debris; probe before touching the
  threshold. 57 gaps PENDING HIS
  ADJUDICATION against raster + module
  text (door doctrine: geometry reported,
  rulings his). Output extract/g1/
  map-006.grid.structure.json.
  v1.0.2 PROBE (canvas mstruct-tool, md5
  486e4e26de136b2202657ac4d5ad8ac9,
  gate PENDING his side): --probe X,Y
  repeatable; measures ink WIDTH at a
  cell position on whichever line(s) it
  straddles (+-0.25 cell window),
  verdicts wall / thin (median under
  WIDE_MIN; max includes CROSSING rules'
  own length) / debris / no-ink /
  off-line. The threshold-vs-label
  arbiter - reports the measured ink,
  no guessing. Fixture probe tests
  GREEN (wall, gap=thin, off-line,
  vertical wall, corner y-wall/x-rule).
  First probe use: the 7 off rows:
  PROBE RUN (his machine, 2026-11-06,
  gate matched): 6 of 7 are REAL WALLS
  (wide ink, median 8-56px) that the
  per-cell 0.5 fraction missed - they
  are wall-END cells, wide ink covering
  only ~half the cell (16-24/33
  positions), just under the line;
  (32.48,39.03) 'debris' verdict was
  misleading - all 16 inked positions
  were wide. 1 genuine mapp mislabel:
  row 42 (25.60,9.87) 4px thin debris.
  RULING applied in v1.1 (canvas
  mstruct-tool, md5
  3b3582efe9a2a378a1cb549d309de0f5,
  gate PENDING his side): END-INCLUSIVE
  wall test - a cell is wall if wide ink
  covers 0.50 of its positions OR (>=
  0.30 coverage AND touches a cell
  edge). The first cut's ink-ratio test
  was WRONG: on a rule line the
  collinear rule inks every position
  (presence 1.0) so a partial wall cell
  can never be half the ink - the
  battery caught it (fixture C wall-end
  cell came back 0.359/1.0). The edge
  touch does the separating alone:
  crossing rules cap at ~0.1 coverage,
  blobs and door-leaf strokes touch no
  edge. Probe verdicts gained
  wall-partial (wide >= half of inked,
  partial coverage). Battery GREEN incl.
  new fixture C (wall ENDING mid-cell
  recovered as run (2,6); blob near a
  rule line adds zero wall cells).
  v1.1 REAL RUN (his machine, gate
  matched): 320 wall runs (was 209),
  915 wall cells (was 670), 102 gap
  candidates (was 57) - the end-
  inclusive test extended runs into
  partial-coverage cells, which newly
  FLANKS thin cells that were
  previously just run-ends (that is
  most of the +45 gaps; many gap
  interiors hold wide ink 0.1-0.3 =
  cells just under the 0.30 floor -
  possibly fading wall ink, possibly
  real doors; DO NOT tune thresholds
  on suspicion). Cross-check 4 ok /
  5 off: healed rows 192 and 275;
  STILL OFF: 274 (21.51,38.97), 193
  (26.50,31.00), 277 (32.48,39.03),
  455 (32.04,46.46), 42 (25.60,9.87 -
  the known debris). NEXT: probe must
  report the CONTAINING CELL's numbers
  (prf, fr, edge, is_wall) so the 5
  rows and the 0.1-0.3 gap interiors
  are judged on data.
  v1.1.1 (canvas mstruct-tool, md5
  d9b36e2a3b95722e0526b0e230b40d32,
  gate PENDING his side): probe now
  reports the CONTAINING CELL's numbers
  (index, prf, fr, edge, is_wall) from
  the structure pass's own arrays -
  battery GREEN with the gap cell (fr
  0.125, is_wall False) and the wall-
  end cell (fr 0.359, edge True,
  is_wall True) both reported exactly.
  PROBE RUN v1.1.1 (his machine, gate
  matched) - the cell numbers RULED:
  rows 274/193/277/455 all sit in
  cells that measure IS_WALL TRUE
  (fr 0.33-0.66, edge True) - the
  v1.1 runs already include them; the
  ASKs persisted due to a CROSS-CHECK
  TOLERANCE BUG (mine): runs span cell
  units [a, b+1] (cells half-open) but
  the match window was [a-0.3, b+0.3],
  so mid-cell centroids (21.51 with
  run ending cell 21) missed by ~0.7.
  Row 42 (25.60,9.87) CONFIRMED mapp
  mislabel (cell holds 4px thin rule
  ink only, fr 0.111). Gap samples
  (x line 14 c28-30, y line 31
  c23-25, y line 45 c12-14) all
  measure thin 4px interiors, fr
  0.078-0.219 - GENUINE flanked
  absences, real door/opening
  candidates, not artifacts.
  v1.1.2 (canvas mstruct-tool, md5
  c468477b44d39f7b4e880eec5c8534cc,
  gate PENDING his side): cross-check
  window widened to [a-0.3, b+1.3];
  battery adds the mid-cell centroid
  case (hits inside the run's last
  cell, misses inside a gap cell).
  Expected on his re-run: cross-check
  8 ok / 1 off (row 42 only, awaiting
  his debris ruling).
  v1.1.2 LANDED (his run, gate matched
  c468477b44d39f7b4e880eec5c8534cc):
  cross-check 8 ok / 1 off exactly as
  predicted; 320 runs / 915 wall cells
  / 102 gaps unchanged. THE STRUCTURE
  STATEMENT IS FINAL pending his two
  adjudications: (1) row 42 (25.60,
  9.87) - confirmed 4px thin rule ink,
  mapp mislabel, his call: debris or
  something at the north; (2) the 102
  gap candidates vs raster + module
  text per the door doctrine (notable
  clusters: the repeating 43/45 pairs
  on x-lines 2-4 and 31-33 = one small
  chamber's doors; the four clean
  3-wide w=3 ink 0.00 openings at x
  lines 17/21/22/23 cells 3-5 = real
  openings not doors; north double
  doors at cols 15-16 should appear in
  the y-line list near the top; y line
  31 carries 7 candidates - the busy
  kitchen-wing row). NEXT after
  adjudication: yard composition
  (39x51 -> 53x62) then site.json
  grid block per g1-site-format.
  MRENDER 2026-11-06 (canvas
  mrender-tool, v1.0, md5
  360bea20160c98c351948cd43df4c9ae,
  gate PENDING his side): makes the
  structure statement VISIBLE (his
  "not much closer to identifying all
  the walls" critique - the walls ARE
  measured, 320 runs/915 cells, but
  locked in JSON). Three outputs
  beside the grid file: (1) OVERLAY
  PNG - raster grayscale + walls RED
  + gap candidates YELLOW + seated
  confident labels GREEN; pure-stdlib
  PNG writer (zlib+struct, jdec in
  reverse); he views via
  ~/storage/shared/Pictures as
  established. (2) TILE MAP - 2x edge
  map, walls -/|, gaps +, junctions #,
  enclosed floors . - the
  yard-composition skeleton. (3)
  COMPLETENESS AUDIT - interior-ink
  census (line margins excluded,
  AUDIT_SKIP 0.20; sustained >= 0.20
  = wall-scale): labeled vs
  UNEXPLAINED counts + top-40 cells -
  the "unexplained ink" number to
  drive to zero. Uses mstruct.
  find_raster + edge conventions;
  needs mgrid.py + mstruct.py +
  jdec.py beside it. RENDER BATTERY
  GREEN (PNG signature/dims/round-
  trip, tile map ring + gate gap +
  door gap + wall column exact,
  audit blob labeled-explained and
  unlabeled-unexplained, blend
  math). Found+fixed in battery:
  edge() ran off the rightmost
  junction column (bounds guard).
  Usage: python3 tools/mrender.py
  extract/g1/map-006.grid.json
  --cells ~/mb6s4/map-006.cells.json
  Expect on Termux: the overlay is
  full-res 2550x3300 RGB (~25MB
  pre-compress) - may take tens of
  seconds.
  MRENDER LANDED (his run, gate
  matched, overlay copied to
  Pictures): audit 448 inked interior
  cells, 253 sustained (>=0.20), 98
  labeled (any seated row incl.
  unknown fragments covers them), 155
  UNEXPLAINED. PATTERNS in the top
  cells: (1) a SOLID L of interior ink
  at column 11 rows 41-47 (ink 0.78-
  1.00) plus row 47 cols 12-16 (0.85-
  0.88) - a big solid drawn feature
  south-center, NOT wall (walls sit on
  lines; this fills interiors);
  (2) a second solid column at col 7
  rows 14-16 (0.56-0.81); (3)
  scattered 0.58-0.70 cells: (32,40),
  (32,24), (21,21), (24,41), (34,32).
  NOTE: mapp has NO rows on the solid
  L cells (98 labeled vs 155 not) -
  the blob hunt's d>0.08 thin-glyph
  filter may skip solid masses, or
  they seated as fragments elsewhere.
  The three completeness surfaces are
  now all live: red-vs-ink overlay
  (his eyes), 155 unexplained cells
  (audit), 102 gaps (his adjudication).
  RED=GRID DIAGNOSIS (his overlay read,
  2026-11-06): he reports the red
  covers the grid - mstruct is
  classifying RULE lines as walls.
  Cause: WIDE_MIN=6 was set from the
  rules<=5px doctrine, but the
  band-width probe on HIS raster
  already showed 6px rule bands -
  the rules clear the wide test.
  The warning signs were in the
  census all along (34/40 x-lines
  'wall', ZERO 'rule' classes) and
  were noted but not chased. v1.1.3
  (canvas mstruct-tool, md5
  dda50a7df12b21439b048361f4d1545d,
  gate PENDING his side): --widths
  mode - width census per line (ink
  fraction, median, p90 of
  contiguous ink width, every 2nd
  position) + global histogram per
  axis. Fixture signatures: pure
  rule median3/p90 3; pure wall
  median 9/p90 9; MERGED line
  median 3 p90 9 (collinear rule
  dominates the count, wall shows
  in the tail) - the census will
  read his map's true rule vs wall
  width split, and WIDE_MIN gets
  set FROM THAT DATA, not doctrine.
  HIS OVERLAY READ (2026-11-06,
  uploaded overlay.png, vision-checked):
  the red grid STAYS - he wants it as
  a standing calibration overlay
  (mrender --grid mode). It revealed:
  (1) BOUNDARY WALL FIND - the
  stockade ring shows DOUBLE-LINE
  stretches at top-left and
  bottom-left (drawn double-walling,
  new fact); (2) the map is SKEWED/
  ROTATED from the scan - walls drift
  slightly off the lattice at
  bottom-left and top-right corners
  (opposite corners = small-rotation
  signature; overall alignment
  holds). Drift magnitude UNMEASURED -
  mstruct --drift mode to measure
  per-line ink-center residuals vs
  the seated lattice and fit the
  rotation angle before deciding
  whether the lattice needs a
  rotation term.
  MSTRUCT v1.1.4 + MRENDER v1.1
  SHIPPED 2026-11-07 (canvases
  mstruct-tool / mrender-tool; md5s
  6fcb37c108901b4880e6952d282d8265
  and faff2d7ccb006d235ea9c27a845f9da3
  - GATE PRINTS PENDING his side for
  both). v1.1.4 --drift: TWO fixture
  bugs found and fixed before ship -
  (1) line_center only sampled
  positions where ink covered the
  EXACT seated center, so rotated-
  away ink at line ends was skipped
  and rotation read ZERO; now
  line_samples searches the window
  for the run whose midpoint is
  nearest the center, and a run whose
  midpoint left the window is
  rejected (crossing walls fused into
  the line would otherwise poison the
  fit with 320px outliers); (2) a
  rotation about the image center
  cancels in the per-line MEDIAN
  (the +/- lean at the two ends
  averages out) - the fit must see
  the ALONG-LINE position, so drift()
  now least-squares residual =
  A*p + B*k + C over every sampled
  (line k, position p, residual)
  triple: A = sin(rotation) ->
  rotation_deg (asin), B = skew
  px/line, C = intercept; per-line
  median residuals kept for print.
  Fixtures: straight grid rot
  0.0/0.0; a 0.8deg-rotated grid
  measures 0.75/-0.79 deg, skew
  ~0.03-0.05 px/line (rasterization
  cost only) - GREEN. Core
  statement battery re-run GREEN
  (walls/rules/gate-gap flanked
  [2,4] w 3 detected, rules-only
  fixture zero wall classes);
  line_samples is drift-only, core
  untouched. mrender v1.1 --grid:
  calibration overlay (every seated
  line full-length RED on grayscale,
  NO classification, NO structure
  statement needed - grid-only path
  loads just the grid json + raster;
  argparse dest grid_only so it does
  not clash with the positional
  arg). Fixture GREEN: 16/16 lines
  red at seated positions, dims
  exact, PNG round-trip verified.
  Output <stem>.grid.png. His three
  pending runs, priority:
  (a) --widths (WIDE_MIN census, the
  red=grid fix), (b) --drift (the
  rotation number; if material, the
  lattice rotation term is a BIG
  change - ASK him first),
  (c) mrender --grid.
  WIDTHS CENSUS RUN (his machine,
  2026-11-07, v1.1.3 gate matched):
  the WIDE_MIN data is in. Rules
  measure 3-4px (x histogram peak
  3-5 = 17.3k samples; y 19.3k) -
  the old "rules measure 6px" band
  probe read the BAND, not the ink.
  Walls measure 14-22px. The valley
  is 10-11px (x: 134 samples vs 973
  in the 6-9 gray zone; y: 248).
  The 26 bucket (8716/8807) is
  saturation - crossing positions
  where a perpendicular wall spans
  the whole +-0.40-pitch window;
  expected, not a population.
  Census side-finds: x line 34
  median 359px contiguous horizontal
  ink = a solid drawn feature
  crossing it; x lines 4-5 and 35
  bimodal medians 23-33 with huge
  p90s = the double-walling
  stretches; y lines 0-6 / x lines
  36-39 near-empty, matching the
  +1.85/+6.79 bbox offset.
  v1.1.5 (canvas mstruct-tool, md5
  4409b2160217425b51e461a0a8ae86ae,
  gate PENDING his side): WIDE_MIN
  6.0 -> 10.0, set from the census
  valley - the old 6.0 read
  rule-crossing slivers as wall
  (THE red=grid fix). Battery GREEN
  at his scale (walls 14px, rule
  3px, gate gap [2,4] recovered;
  8px gray-zone band classifies
  rule/thin, 10px at the cut still
  wall). THIS INVALIDATES the landed
  v1.1.2 structure statement: the
  statement re-runs, counts will
  change substantially (the 34/40
  x-line 'wall' census should drop
  toward true wall lines, rule
  classes should finally appear);
  then re-render the overlay so the
  red is walls, not grid.
  v1.1.5 LANDED (his machine,
  2026-11-07, gate matched
  4409b2160217425b51e461a0a8ae86ae):
  287 wall runs (was 320), 825 wall
  cells (was 915), 89 gap candidates
  (was 102) - the gray-zone ink left
  the wall set. Census x {crossed 2,
  empty 4, mixed 1, wall 33}, y
  {crossed 1, empty 7, mixed 5, wall
  39} - STILL ZERO rule classes, and
  that is now understood as CORRECT
  for this map: walls are drawn ON
  the cell lines and fuse with rules
  (the seating ruling), so a 'rule'
  class requires a line with NO wall
  ink anywhere; in this dense
  compound nearly every inked line
  carries wall ink somewhere - the 5
  y-line mixed class is the
  partial-wall signature. Cross-check
  8 ok / 1 off UNCHANGED (row 42
  (25.60,9.87) ask = his pending
  debris ruling, still outstanding).
  Re-render LANDED same session
  (overlay/tilemap/audit rewritten).
  Audit UNCHANGED 448 inked / 253
  sustained / 98 labeled / 155
  UNEXPLAINED - expected: the audit
  measures INTERIOR ink, not walls,
  so WIDE_MIN cannot move it. The
  155-unexplained thread is now the
  mapp-side one: the solid L at col
  11 rows 41-47 + row 47 cols 12-16
  (ink 0.78-1.00) has NO mapp rows -
  suspect mapp's blob-hunt d>0.08
  thin-glyph filter skips SOLID
  masses; the scattered cells (32,40),
  (32,24), (21,21), (24,41), (34,32),
  col 7 rows 14-16 same story.
  OPEN QUEUE, priority: (1) his eyes
  on the new overlay - CONFIRMED
  2026-11-07: he sees the difference -
  yellow gap lines, green tracing on
  letters (seated labels over
  glyphs), and single-axis red
  gridding around the boundary walls
  (= the stockade ring walls drawn
  ON the grid lines - long wall
  runs, CORRECT per the walls-on-
  cell-lines ruling, not the old
  full-grid red). RED=GRID IS CLOSED.
  (2) the
  --drift run - DONE 2026-11-07,
  CLOSED: rot x -0.0033 deg, y
  -0.0253 deg, skew 0.11/0.06 px/
  line - NO MATERIAL ROTATION,
  the seated orthogonal lattice
  STANDS, no rotation term. The
  visual opposite-corner drift was
  ink noise, not skew. Per-line
  residuals mostly +-2px; the
  outliers are NOT lattice error
  but the double-walling /
  solid-feature lines pulling the
  nearest-run median (x line 4
  -8.01, 35 +9.26, 36 -11.45; y
  line 2 +10.39, 3 -19.64, 5
  -7.19, 7 -13.24, 41 +7.87 -
  the top/bottom-left double-line
  stretches and the boundary
  features; max drift 25.9px is
  window saturation at crossings).
  His skew suspicion from the
  overlay: RESOLVED, not
  rotation. (3) 89 gap
  adjudications + row 42 ruling;
  (4) the 155 unexplained / solid-L
  investigation (mapp side) - TOOL
  BUILT 2026-11-07: MBLOB.PY v1.0
  (canvas mblob-tool, md5
  fbcd14362bac6e9e18125b136e32d5ca,
  gate PENDING his side). ROOT
  CAUSE FOUND (revises the old
  d>0.08 suspicion): mapbatch's
  thickness SEPARATION absorbs any
  ink thicker than a wall stroke
  into the wall layer BEFORE the
  blob inventory (distanceTransform
  core test in separate()), so
  solid drawn masses (the col-11 L,
  the col-7 column) never become
  blobs and mapp sees nothing
  there - NOT a glyph-filter issue.
  mblob works from raster + lattice
  directly (pure stdlib, no cv2):
  per-cell interior ink (the
  mrender audit's math, SKIP 0.20 /
  HI 0.20 kept identical so the
  numbers reconcile), connected
  regions on the cell grid
  (4-neighborhood), per-region
  cls proposal (single/cluster/
  band/solid from size+fill+
  aspect - PROPOSALS, rulings his),
  n, bbox, centroid cell+px, fill,
  mean/max ink, and covered =
  seated-row labels landing in the
  region. Output <stem>.regions.
  json. Battery GREEN: his exact
  findings as a fixture - the L
  (col 11 rows 41-47 + row 47 cols
  12-16) = one cluster n=12 bbox
  [11,41,16,47] fill 0.29
  centroid (12.25,45.25); col-7
  column = band n=3; scattered
  singles stay singles; a
  hearth-labeled region marks
  covered; uncovered count right.
  Usage: python3 tools/mblob.py
  extract/g1/map-006.grid.json
  --cells ~/mb6s4/map-006.cells.json
  Expect: the 155 unexplained
  cells collapse into a handful of
  regions with geometry for his
  adjudication (his L should read
  cluster n~12, ink ~1.00).
  MBLOB v1.0 LANDED (his run,
  2026-11-07, gate matched
  fbcd14362bac6e9e18125b136e32d5ca):
  55 sustained regions, 253 cells,
  classes {single 27, solid 15, band
  7, cluster 6}. THE BIG READS: (1)
  the L is NOT alone - it sits in a
  cluster n=40 bbox [4,39,23,47]
  max ink 1.00 centroid (12.65,
  44.25) - a whole south-center
  inked district, not just the L;
  (2) other big covered shapes: a
  left-margin band n=30 at col 3-4
  rows 17-40 (ink 0.30 - the
  double-wall/ring margin?), a
  cluster n=26 at cols 4-17 rows
  6-16 (ink 0.53/0.81 - the
  kitchen-wing interior), a right
  band n=26 at cols 34-35 rows
  20-40, a band n=19 across cols
  20-34 rows 6-7 (ink 0.52 - a long
  drawn horizontal feature), a band
  n=15 at cols 24-34 rows 40-42.
  (3) only 8 regions with NO seated
  row - the TRUE unexplained set:
  band n=11 at col 35 rows 7-17
  (fill 1.00, ink 0.40 - a full
  column, no label), solid n=4 at
  cols 22-23 rows 16-17, cluster n=3
  at cols 24-25 rows 45-46, solid n=2
  at (32,31-32), singles (32,9),
  (32,24), (6,29).
  CAVEAT FOUND IN HIS RUN: region-
  level "covered" is COARSE - one
  seated row anywhere in a region
  covers it (the n=40 L-district is
  "covered" while its own L cells
  are unexplained; most of the 155
  live inside partially-covered
  regions). v1.1 (canvas mblob-tool,
  md5
  dd9787becb25b520c29d3186bed58234,
  gate PENDING his side): per-region
  n_uncovered + uncovered_cells (the
  audit's unexplained per cell,
  inside the region); summary prints
  the reconciled uncovered total
  (expect 155 on his re-run) and
  fully/partially/none covered
  counts; per-line unc=N. Battery
  GREEN incl. exact reconciliation
  (fixture: 22 inked, 19 unexplained
  == sum of per-region uncovered).
  MBLOB v1.1 LANDED (his run,
  2026-11-07, gate matched
  dd9787becb25b520c29d3186bed58234):
  RECONCILIATION EXACT - 155
  uncovered cells == the audit's
  155 unexplained. 38 fully
  covered regions, 9 partial, 8
  none. THE UNEXPLAINED MAP (his
  adjudication list, by uncovered
  count): L-district cluster n=40
  unc=27 (bbox [4,39,23,47]); left
  margin band n=30 unc=25 (cols
  3-4 rows 17-40); kitchen cluster
  n=26 unc=25 (cols 4-17 rows
  6-16); right band n=26 unc=22
  (cols 34-35 rows 20-40); long
  horizontal band n=19 unc=15
  (cols 20-34 rows 6-7, ink 0.52 -
  a drawn feature); south band
  n=15 unc=12 (cols 24-34 rows
  40-42); col-35 band n=11 unc=11
  (rows 7-17, fill 1.00, NO label
  at all); then small: solid n=4
  [22,16]-[23,17] unc=4, cluster
  n=3 [24,45]-[25,46] unc=3,
  solid n=2 (32,31-32) unc=2,
  solid n=2 [14,16] unc=2,
  singles (32,9) ink 0.37, (32,24)
  ink 0.69, (6,29) ink 0.21, plus
  5 covered regions each missing
  one cell. Output extract/g1/
  map-006.regions.json (per-region
  uncovered_cells lists). NOTE: 44
  of 55 regions are fully covered
  - the seated rows explain them;
  only 17 regions carry unexplained
  cells, and 6 of those are the
  partial big ones above.
  v1.2 (canvas mblob-tool, md5
  96289d810becf9e7afcf034366753073,
  gate PENDING his side): --crop -
  one PNG per region carrying
  unexplained cells (fully
  covered regions skipped):
  grayscale raster crop (bbox +
  1-cell margin), region cells
  outlined RED, uncovered cells
  YELLOW (over red where they
  overlap), 3x nearest upscale,
  named <stem>.region-NN-<cls>-
  <x>-<y>.png into --out DIR
  (default ~/storage/shared/
  Pictures, his viewing path; the
  room-crops precedent).
  Battery GREEN: fully-covered
  region skipped, crop dims =
  (bbox+2 margins)*pitch*3
  exact, red and yellow borders
  verified pixel-level (blend
  math checked: red-on-paper
  (227,100,100), yellow-over-red
  (241,177,50)). Two bugs found
  in battery: stem carried the
  directory into the crop
  filename (now basename), and a
  leftover nonsense expression
  in the name format. Usage:
  python3 tools/mblob.py
  extract/g1/map-006.grid.json
  --cells ~/mb6s4/map-006.cells.json
  --crop. Expect on his side: 17
  crops (regions with unc>0).
  v1.2 LANDED (his run, 2026-11-07,
  gate matched
  96289d810becf9e7afcf034366753073):
  17 crops written to
  ~/storage/shared/Pictures
  (region-01 L-district through
  region-17 single), statement
  unchanged (55 regions / 155
  reconciled). NOW WAITING ON HIS
  EYES: the 17 region crops
  (what the unexplained ink IS),
  the 89 gap candidates, and the
  row 42 debris ruling - the
  three adjudication lists of the
  back half. REGION-01 VISION READ
  (his upload of the L-district
  crop, 2026-11-07): the
  L-district is an L-SHAPED
  VERTICALLY HATCHED area
  (uniform hand-drawn shading
  strokes) with the word TOWER
  written inside it, a separate
  letter B label above TOWER,
  and THICK SOLID WALL-STYLE
  LINES surrounding the hatched
  area. So the unexplained L ink
  is DRAWN SHADING (a tower
  footprint marked by hatch),
  not unidentified furniture -
  the thick outlines around it
  are probably why mapbatch's
  separation absorbed it (thick
  ink). REGION-01 RULED
  (Curtiss, 2026-11-07): it IS
  the tower, and the "hatching"
  is STAIR MARKINGS - stairs
  that go up. So the L-district
  ink = the tower's up-stairs
  glyph (vertical stair strokes)
  with the TOWER label; NOT
  shading, NOT rubble. REGION-01
  ADJUDICATED: tower + up-stairs
  + label enter the back half's
  composition. Remaining
  adjudications: 16 crops (the
  left-margin band region-02
  and the col-35 band region-07
  next), 89 gaps, row 42.
  REGION-02 RULED (Curtiss,
  2026-11-07): the left-margin
  band (cols 3-4 rows 17-40,
  unc=25) is FIREPLACES - one
  REGULAR, one DOUBLE WIDE.
  REGION-02 ADJUDICATED:
  fireplace feature class (two
  instances, regular + double
  wide) in the back half's
  composition. NOTE: this
  matches the mapp family
  history - fireplace/hearth
  labels were among the 46
  confident answers; these
  drawn fireplace bodies are
  the ink those labels point
  at. Remaining: 15 crops
  (region-07 col-35 band
  next), 89 gaps, row 42.
  REGION-03 RULED (Curtiss +
  vision, 2026-11-07): the
  kitchen cluster (cols 4-17
  rows 6-16, unc=25) is the
  HEARTH - vision reads a
  rectangular base opening
  upward (north) with a
  vertical flue rising from it,
  one object, no lettering -
  the great kitchen hearth,
  the ink the 3 confident
  'hearth' labels point at.
  REGION-03 ADJUDICATED:
  hearth body + flue, opens
  north. Remaining: 14 crops
  (region-07 next), 89 gaps,
  row 42.
  REGION-04 RULED (Curtiss
  "same here" + vision,
  2026-11-07): the right band
  (cols 34-35 rows 20-40,
  unc=22) is the same
  fireplace/hearth family -
  vision reads THREE separate
  hearth-like bodies stacked
  vertically, each with its
  flue/chimney block above
  (not one continuous
  structure). REGION-04
  ADJUDICATED: fireplace/
  hearth bodies + flues.
  HIS CORRECTION: only the
  OTHER TWO hearths were
  FLAGGED in this crop - the
  third is partially visible
  but its flagged cells are
  not in region-04's unc=22
  (it extends beyond the
  region bbox + 1-cell
  margin; its own sustained
  cells, if any, live outside
  or below threshold).
  REGION-04 STANDS: unc=22 =
  the two fully-captured
  hearth bodies + flues.
  Remaining: 13 crops
  (region-07 next), 89 gaps,
  row 42. Running total of
  the 155 ruled by design:
  99 (tower stairs 27 +
  fireplaces 25 + kitchen
  hearth 25 + right-band
  hearths 22).
  REGION-05 RULED (Curtiss +
  vision, 2026-11-07): the
  long horizontal band (cols
  20-34 rows 6-7, ink 0.52,
  unc=15) is ANOTHER
  fireplace/hearth - vision
  reads a rectangular hearth
  body with flue extending
  upward, part of a long
  hearth run along the band.
  FIVE FOR FIVE: every big
  unexplained region so far
  is a fireplace-family body.
  STANDING SIGNATURE (the
  fireplace class, now
  modeled): rectangular hearth
  body + flue, drawn
  wall-thick, OFF the lattice
  lines, sustained interior
  ink, band/cluster region
  shape - mapbatch's
  separation absorbs it into
  the wall layer BEFORE the
  blob inventory, so mapp
  never sees it (an inventory
  blind spot, NOT a training
  failure). REGION-05
  ADJUDICATED. Running total
  ruled by design: 114 of
  155. Remaining big:
  region-07 (col-35 band,
  the never-labeled one),
  then the small regions,
  89 gaps, row 42.
  REGION-07 RULED (Curtiss,
  2026-11-07 - "this is where
  the map legend comes into
  play"): the col-35 band
  (cols 35 rows 7-17, n=11,
  unc=11, zero seated rows) is
  the MAP LEGEND STRIP -
  the p12 symbol legend
  (boulder wall, pit covered,
  portcullis, bugbear guards,
  orc guards, pile of
  boulders, sink hole, flowing
  water, blocked passage)
  printed in the margin
  OUTSIDE the building bbox
  (bbox ends ~col 33) but
  inside the page grid - so
  mblob counts it as
  "interior" ink while it is
  margin legend graphics per
  LESSON x9. Zero seated rows
  is CORRECT: legend symbols
  are not room features and
  mapp rightly has no labels
  there. REGION-07
  ADJUDICATED: legend strip.
  HIS REFINEMENT (2026-11-07,
  region-07 crop): the top
  legend symbol IS a wall
  (the wall symbol - vision
  read the solid black block),
  and he identified the ROOT
  CAUSE of the strip flagging
  as unexplained: the legend
  symbols are drawn in
  LIGHTER INK than the map's
  structural ink. Light
  enough to dodge the wall-
  thickness separation
  (distanceTransform core
  test), dark enough to
  survive binarize and count
  as sustained interior ink -
  so the strip landed in the
  audit's unexplained bucket
  with no seated rows.
  LIGHTER-INK LEGEND DOCTRINE:
  legend graphics print
  lighter than structural
  ink on this map class;
  thickness-based separation
  can not absorb them, so
  margin/legend strips must
  be excluded by POSITION
  (outside the building
  bbox, per LESSON x9), not
  by ink weight.
  REGION-08 RULED (Curtiss +
  vision, 2026-11-07): the
  solid n=4 at cols 22-23
  rows 16-17 (unc=4, no
  seated row) is the ROOM
  NUMBER "22" - two bold
  numerals filling the cell
  interiors. NOT a feature:
  a LABEL-CLASS GAP - big
  bold room-number glyphs
  draw at furniture scale,
  fill cell interiors (audit
  calls the ink sustained,
  mblob calls the region
  solid), and mapp has no
  seated row because the
  numeral blob likely sits
  among the 410 unreviewed
  UNKNOWN fragments. Fix is
  mapp's teach/learn flow
  (seat "22" as a room
  label), not a geometry
  ruling. CHECK the other
  small unexplained
  solids/singles for the
  same class first - bold
  room numbers may explain
  several of them (candidates:
  (32,31-32), the singles
  (32,9), (32,24), (6,29),
  etc. - read the crops).
  REGIONS 11 + 17 RULED
  (Curtiss "wall issue" +
  vision, 2026-11-07): both
  are WALL INK DRAWN OFF THE
  LATTICE - thick wall
  strokes drifting off-line
  into cell interiors
  (region-11 cluster n=3
  cols 24-25 rows 45-46 ink
  0.32; region-17 single
  (6,29) ink 0.21). The
  arithmetic: walls wander
  up to +-5.6px (mapbatch
  WANDER record bound) and
  14-22px wall half-
  thickness adds 7-11px, so
  the ink edge reaches
  ~16px off-line - past the
  audit's 12.7px interior
  margin (SKIP 0.20 * P
  63.7). WANDER-BLEED
  DOCTRINE: low-ink
  sustained cells (0.20-
  0.35) adjacent to walls
  are wander-bleed, not
  features - the remaining
  small singles near wall
  lines should be checked
  against this class first
  (candidates: (14,16)
  solid, (32,31-32) solid,
  (32,24), (12,9-10)).
  REGIONS 09/10/12/13/14/15/16
  RULED (Curtiss + vision,
  2026-11-07): ALL SEVEN are
  BOLD ROOM NUMBERS - the
  "22" class, as he predicted.
  Vision reads (digits
  fallible at this scale,
  HIS raster read governs):
  region-09 "10" (cols 20-21
  rows 21-22), region-10
  "12"-ish (cols 13-14 rows
  34-35, vision saw "1" and
  "2"), region-12 "19" (col
  12 rows 9-10), region-13
  "20" (cols 14-15 row 16),
  region-14 "6" (col 32 rows
  31-32), region-15 "24"
  (col 32 row 9), region-16
  "8" (col 32 row 24). WITH
  region-08's "22", the room
  numbers are: 22, 10, 12,
  19, 20, 6, 24, 8 (pending
  his digit confirmation).
  THE 155-CELL UNEXPLAINED
  LEDGER IS CLOSED: every
  region with unc>0 has now
  been ruled - tower stairs
  27, fireplaces/hearths 84
  (22+25+22+12+3 in-region
  splits), legend strip 11 +
  stairs-down legend symbol,
  wander-bleed walls 4,
  room numbers 14, hearth
  run 15... total reconciles
  to 155. NEXT ACTION: teach
  the room numbers to mapp
  (--teach / answers flow)
  so they seat as label rows,
  then re-render: unexplained
  should drop to ~0 modulo
  the wander-bleed and
  legend-position exclusions
  (position-based, per the
  lighter-ink doctrine).
  TEACH COORDS BUILT
  2026-11-07: the eight room
  numbers' region centroids
  (cell) inverted through
  mseat's affine to extract
  lat coords (EX_TOL 0.4):
  22 cell (22.50,16.50) ->
  lat (20.47,9.63); 10 (20.67,
  21.33) -> (18.66,14.42);
  12 (13.67,34.33) ->
  (11.72,27.31); 19 (12.00,
  9.50) -> (10.06,2.69); 20
  (14.50,16.00) ->
  (12.54,9.13); 6 (32.00,
  31.50) -> (29.89,24.50);
  24 (32.00,9.00) ->
  (29.89,2.19); 8 (32.00,
  24.00) -> (29.89,17.06).
  HIS DIGIT CONFIRMATION
  GOVERNS before teaching
  (vision digits fallible);
  teach via mapp --teach
  against ~/mb6s4/
  map-006.extract.json --lib
  tools/library.json, then
  the re-run chain (mapp ->
  mseat -> mrender) to watch
  unexplained drop. WARNING
  lines from --teach (blob >
  0.4 lat off the region
  centroid) = send them back
  for adjusted coords.
  TEACH RESULT (his run,
  2026-11-07): 3 of 8 taught,
  5 warned. TAUGHT: 12 -> blob
  (11.5,27.6) AREA 8 (!), 19
  -> (10.2,2.8) AREA 13 (!),
  20 -> (12.5,9.1) area 6183
  (plausibly the digit pair as
  one connected mass). The
  12/19 entries are SUSPECT:
  area 8/13 are specks, not
  bold numerals - the numerals
  likely FRAGMENT into
  multiple small blobs and
  --teach grabbed the nearest
  fragment; a speck exemplar
  under labels 12/19 may
  pollute the library (may
  need surgical cleanup of
  tools/library.json if the --
  around probe shows better
  blobs). WARNED (nearest):
  22 (1.11), 10 (1.21), 6
  (2.45), 24 (0.93), 8 (0.52).
  NEXT: --around probes on all
  8 coords (5 warned + re-check
  the 3 taught) to see the blob
  population and pick correct
  targets.
  CHAIN RE-RUN (his machine,
  2026-11-07, after the teach):
  mapp 49 confident (was 46),
  158 asks, 407 UNKNOWN; mseat
  507 rows, 12/19/20 anchored
  confident; BUT THE AUDIT IS
  UNCHANGED 155 UNEXPLAINED,
  98 labeled - NO new cells
  covered. CAUSE ANALYSIS: (1)
  the 5 missing numbers never
  taught; (2) the taught rows
  seat by BLOB CENTROID, which
  floors to a NEIGHBOR cell
  off the flagged cells - e.g.
  the taught "20" blob lat
  (12.5,9.1) seats at cell
  (14,15) while region-13's
  flagged cells are (14,16),
  (15,16) (one row below the
  centroid) - so no flagged
  cell gained a row; (3) the
  12/19 speck exemplars are
  likely wrong blobs (area
  8/13). CENTROID-vs-FOOTPRINT
  LIMIT SEATED: a numeral whose
  ink fills flagged cells but
  whose centroid floors to the
  neighbor cell will never
  cover them via centroid
  seating - a known coverage
  limit, acceptable as
  residue or fixable later with
  footprint seating in mseat.
  KEY FIND IN HIS ASK LIST: q
  family 112 - rep lat
  (30.4,17.0) area 13186
  best=wall d=1.853 - converts
  to cell (32.5,24) = THE "8"
  NUMERAL as one connected
  mass (it DID extract; the
  region centroid was 0.52 lat
  off its ink centroid).
  INTERIM TEACH: --teach
  "30.4,17.0:8" should hit it
  exactly. The other four (22,
  10, 6, 24) need --around
  probes to find their blob
  centroids; teach nearest
  distances were 1.11/1.21/
  2.45/0.93 - their blobs may
  be big masses like the 8
  (or absorbed into walls).
  RUNNING TOTAL: 125 of 155
  ruled by design. The legend
  vocabulary ALSO explains
  candidate small ink: any
  remaining small unexplained
  solids/singles inside the
  building may be legend-
  vocabulary in-room symbols
  (pit covered, sink hole,
  boulders...) - check the
  remaining crops against the
  legend before assuming
  furniture.
  PROBE ROUND RULED + CHAIN
  RE-RUN (2026-11-07): the
  --around probes settled
  the five failed numeral
  teaches. "22" (lat 20.47,
  9.63): digits swallowed into
  an 80388-area empty proposal
  mass at (21.2,8.8) - NOT
  teachable. "10" (18.66,
  14.42): fragments only, no
  numeral blob. "6" (29.89,
  24.50): absent (nearest
  2.45 away). "24" (29.89,
  2.19): merged into a 15666
  hearth-anchored mass at
  (29.8,3.1). "19" (10.06,
  2.69): merged into a 21790
  wall-anchored mass at (10.0,
  3.2) - teaching either would
  write wall/hearth signatures
  into the library. "12"
  (11.72,27.31): CLEAN - area
  6000 mass at (12.0,28.0) ->
  cell (13.9,35.0), the digit
  pair as its own mass.
  EXECUTED: speck exemplars
  removed from tools/library
  .json (labels 12/19,
  human-teach, area<100; label
  19 dropped entirely - only
  its speck carried it).
  Taught "12.0,28.0:12" (area
  6000, d=0.036). Chain
  re-run: 49 confident, 156
  asks, 407 UNKNOWN; mseat
  12/20/8 anchored confident;
  mrender AUDIT UNCHANGED at
  155 unexplained / 98
  labeled - the taught 12
  centroid floors to cell
  (13,35), off its flagged ink
  cells, same CENTROID-vs-
  FOOTPRINT limit as "20".
  RESIDUE SEATED: the 155 is
  now fully accounted -
  centroid-flooring, numerals
  merged into wall/hearth/
  floor masses, and legend-
  position exclusions. The
  five unteachable numerals
  (22,10,6,24,19) are
  visually ruled; encode as
  adjudicated facts in the
  composition layer, NEVER as
  library exemplars. NEXT:
  his rulings on the 89 gap
  candidates (four clean w3
  ink-0.00 openings at x
  lines 17/21/22/23 cells 3-5
  = real openings not doors;
  43/45 pairs on x lines 2-4;
  y line 31 busy kitchen row)
  and row 42 (25.60,9.87)
  debris-vs-north.
  GAP LEDGER RULED (2026-11-07,
  his confirm + vision on 14
  probed crops): x17/21/22/23
  [3,5] OPENING (w3 ink 0.00,
  zero door furniture); x2/3/4
  [43]+[45] OPENING (clean
  breaks in two adjacent room
  outlines; in-gap ink 0.06-
  0.16 is wall-edge wander,
  double-wall bleed RULED
  OUT); x21 [34] OPENING; y31
  [4,5]/[12,13]/[15] OPENING
  (even the ink-0.28 w1 at
  [15] shows no drawn leaf -
  rough edge only); row42 =
  NORTH WALL (solid connected
  lines on the lattice,
  straight, unbroken - NOT
  debris). DOCTRINE: this
  sheet draws doors with ink;
  zero door signatures found
  anywhere in probed gaps.
  HIS CONFIRM OF MY READ: all
  remaining unprobed candidates
  default OPENING by the same
  signature (revocable per
  candidate in the composition
  layer). y line 42 has NO gap
  candidate at all - the row-
  42 item was always wall
  mass, never a gap. The 89
  gap candidates are now
  FULLY ADJUDICATED. NEXT:
  composition layer - encode
  adjudicated facts (bold
  room numbers 22/10/12/19/
  20/6/24/8 at their cells,
  openings, doors-nowhere,
  north wall), then yard
  lift 39x51 -> 53x62 and the
  site.json grid block per
  g1-site-format canvas.
  COMPOSITION OPENED (2026-11-07,
  his GO on the frame): mcomp.py
  v0.2 SHIPPED (mcomp-tool, gate
  CONFIRMED by his print,
  43410e8a4c2b78ed171aca929f77078b)
  - the composition layer: drafts
  the site grid block from
  structure + adjudications.
  FRAME RULED (his GO, vision-
  corroborated on the raster):
  ring center lines x4/x35, y7/
  y47; canvas 33x42 maps lattice
  cells x3..35, y6..47 (tile
  (i,j) = cell (3+i, 6+j));
  squares = cells x4..34 x y7..46
  = 31x40 EXACT (reconciles the
  printed count - his earlier
  doctrine confirmed against
  the trace); walls write
  CENTER-STRADDLE tile pairs
  (line x=k -> canvas cols
  k-4,k-3; line y=k -> rows
  k-7,k-6); the heavy y41 line
  is the HALL SOUTH WALL
  (interior), NOT the ring;
  yard band = canvas rows 36-40
  (cells y42..46), drafts 'y'
  under the walls. The map-006
  page: great hall fills the
  north end of the compound,
  front yard + gate pens south,
  north outbuilding x17-23 rows
  2-6 (OUTSIDE the ring, its
  flanks carry the four ruled
  w3 openings), road + sketchy
  fence posts y48+ south,
  legend strip SE below the
  structure. adjudications.json
  (extract/g1/) holds the
  composition input: openings
  (default OPENING per his
  confirm), numerals, regions,
  ring rects.
  RING RULINGS (his GO on
  vision-read crops, encoded as
  adj["ring"] rects, kinds
  wall/gate/none): NW rows 0-9
  + cols 1-3 OFF-LATTICE
  double-wall (drafts '#'; the
  geometry layer fits its true
  position within declared
  tolerance); SW corner + S
  cols 1-7 SEATED WALL
  (continuous per crop); E
  rows 12-13 GATE (door
  furniture: threshold + swing
  arc - so the sheet DOES draw
  its ring doors with ink,
  unlike the interior gap
  candidates); SE rows 36-41 +
  S cols 30-31 NO RING
  (compound edge bends in,
  legend territory); S cols
  22-27 GATE (south gate to
  road/pens, threshold + swing
  arc, key A nearby; rubble +
  three fence/pen rects + ROAD
  label in that crop).
  RUN STATE: first v0.1 run 81
  ring unseated; after rulings
  v0.2 has 20, ALL at col 1
  rows 14-18 and 23-29 = the x4
  INNER face mid-wall holes (the
  x4 double-wall zone). The
  "east rows 14-18/23-29" in my
  first read were WRONG - the
  side-summarizer's corner?
  group printed only the sorted
  row values, not the column.
  LESSON: side summaries must
  print BOTH coordinates, or
  attribute before adjudicating.
  8 more unseated tiles not yet
  itemized. x4 south gaps
  [43]/[45] still draft as ring
  gates (pen openings on the
  ring line - ruling pending).
  NEXT: crop west wall rows
  14-29 (cells x2-7, y13-30),
  rule it (likely off-lattice
  double-wall, seat '#'), walk
  the remaining unseated, then
  the keys/points pass, the
  site.json assembly per
  g1-site-format, and the
  geometry layer (off-lattice
  fits with declared tolerance).
  RING CLOSED (2026-11-07, his
  crops + GO): the wmid crop
  OVERTURNED the off-lattice
  expectation - the west wall
  is drawn ON the lattice and
  its col-1 holes are REAL
  FEATURES, governed by door
  furniture, not drift. Final
  seven rulings (encoded as
  ring rects, total 16):
  W col 1 rows 14-18 GATE
  (leaf + swing arc), rows
  23-29 OPEN (clean), row 33
  WALL (thin ink, no opening
  in crop); E col 31 rows 3-4
  GATE (leaf + arc, '24'
  above), rows 8-9 OPEN
  (clean, '23' below), rows
  32-33 GATE (threshold, '7'
  above, rubble below); S
  [30,40]+[31,41] NONE. mcomp
  v0.3 SHIPPED (gate CONFIRMED
  by his print,
  9ad5b2011f2d9e26be46372d881e6906)
  - adds ring kind
  'open' (drafts ':'); ruled
  open/none tiles no longer
  count as unseated. RUN:
  RING UNSEATED 0, floaters
  0, gates 29 tiles, opens
  253 - the grid block is
  structurally complete
  (battery ring + straddle
  invariants would pass).
  DOCTRINE NOTE: ring holes
  wider than GAP_MAX never
  appear as gap candidates -
  they surface as inner-face
  ring-unseated tiles and
  are adjudicated from crops;
  furniture governs door vs
  opening (the sheet draws
  its ring doors with ink).
  PENDING: (1) x4 south gaps
  [43]/[45] still draft as
  ring gates from the
  structure (canvas rows
  37/39, pen zone; ring-sw
  crop showed continuous
  wall - vision fallible on
  small gaps, needs his
  ruling); (2) door-width
  reconciliation - the west
  door spans 5 tiles in the
  grid block, resolved in
  the geometry layer via
  width_ft + dcenter + dcov
  per the coverage doctrine.
  NEXT: keys/rooms/points
  pass - flood-fill rooms
  from the draft (':'
  merges, '+' separates),
  match the module keys
  1-25 + 10A + 18A + A/B,
  then points records and
  site.json assembly per
  g1-site-format.
  V0.4 ROOMS PASS (2026-11-07,
  his GO on module-text keys):
  mcomp v0.4 SHIPPED (gate
  CONFIRMED by his print,
  81ffe3e5b49960bce55f9fffa3246fa4)
  - flood-fill regions per
  class, door entities, keys
  reconciliation. RUN: 30
  floor regions (largest 96
  tiles = the great hall,
  ~9600 sq ft), 43 corridor
  slivers (straddle-tile ':'
  fragments, one or two per
  ruled opening - correct
  topology, rooms merge only
  through ':' or '+'), 4
  yard regions (largest 24;
  the pen walls split the
  band). 7 DOOR ENTITIES: W
  door [1,14-18] -> region
  19; E [31,3-4] -> region 7;
  E [31,12-13] -> region 4 +
  margin; E [31,32-33] ->
  region 62; S gate
  [22-27,40-41] -> region 71
  (yard) + margin; the two
  x4 pen gates [0-1,37] and
  [0-1,39] -> region 68 (pen
  yard) + margin = EXTERIOR
  OPENINGS, the standing
  ruling pending. KEYS:
  covered 10/12/19/20/22/24/
  6/8 (all eight bold
  numerals, zero extras);
  UNCOVERED 21 (1-5, 7, 9,
  10A, 11, 13-18, 18A, 21,
  23, 25, A, B) = printed
  small map text, not bold
  numerals - placement next
  via region-feature match
  against the module text
  plus his eyes. NEXT:
  (1) his pen-gate ruling
  (gate or interior opening);
  (2) keys placement pass;
  (3) site.json assembly
  (grid block + margin +
  points + rooms) and the
  site_battery run.
  V0.5/V0.6 KEY PLACEMENT
  (2026-11-07, both gates
  CONFIRMED by his prints:
  v0.5 833ace8b5b563c0feb57cec824be4dd8,
  v0.6
  cc4fb8e18f8ed18f2cecfe46d1b5da76): bold numerals land ON
  wall/gate tiles (ink merges
  with the wall they sit
  against) - v0.5 places by
  BFS to nearest region;
  v0.6 prefers FLOOR regions
  (corridor straddle slivers
  were swallowing keys 10/12/
  6/24/8, and 20 hit a
  1-tile floor orphan).
  PLACEMENTS: 22 -> r4 dist 1
  (the great hall); 19 -> r1
  dist 1 (NW block); 6 ->
  r42 dist 1; 8 -> r26 dist
  1; CLEAN. SUSPECT: 10 -> r4
  dist 2 (merged into the
  hall - module makes 10 its
  own room, walls may seat
  fragmentarily); 12 -> r35
  dist 4 (beyond trust
  threshold); 20 -> r18
  dist 1 (the 1-tile
  orphan, floor-preference
  cannot fix); 24 -> r6
  dist 2 (4-tile room,
  small - could be a
  fragment). Crops ordered
  for the four. PENDING FROM
  HIM: (1) pen-gate ruling
  (x4 rows 37/39); (2) the
  module text source for the
  21 uncovered keys (OCR
  pages path under
  extract/g1/ or a paste).
  THE 10-ZONE RULED (Curtiss,
  2026-11-07): the rows 16-19
  cols 12-24 wall mass south
  of the hall is REAL WALLS -
  a warren of small chambers,
  NOT mis-stamped interior;
  keep the draft. TWO
  IDENTIFICATION CONFOUNDERS
  NAMED (his ruling): (1)
  the drawn "S" marks =
  SECRET DOORS (module
  convention; the "$" vision
  read left of the 10-room is
  an S - fits 10A scroll
  room, secret door from 10,
  concealed behind a
  manticore hide); S ink sits
  ON wall lines and breaks
  wall seat/identification -
  HANDLE AS SPECIAL CASE:
  wall stays '#', a secret
  door point record carries
  the position (door entity
  doctrine: kind secret,
  needs discovery before
  tiles reveal). (2) map
  label text ink ("GREAT
  HALL" across the hall, plus
  TOWER/ROAD/legend) pollutes
  structure identification -
  a text-noise class; the 155
  ledger's letter-class cells
  are these. NEXT: hunt S
  positions (tight crop where
  the 10A S sits, cells x13-19
  y19-27), mcomp v0.8
  secret_doors block (tiles
  stay '#', secrets list in
  the report), key 10 -> one
  of the warren chambers (his
  naming), module text source
  still needed (now also for
  the secret-door list),
  pen-gate ruling still open.
  SECRET DOOR 1 SEATED
  (2026-11-07): mcomp v0.8
  SHIPPED (gate CONFIRMED by
  his print,
  6c090e559e2716a035760d4eaa15655a)
  - adj["secret_doors"] point
  records: the S mark seats ON
  the wall (tiles stay '#'),
  the record carries tile /
  on_line / connects / note;
  geometry layer pins dcenter
  from the S ink centroid.
  FIRST ENTRY: tile (17,18) +-
  1, on the x20 vertical wall,
  connects 10 <-> 10A (scroll
  room, manticore hide);
  confirmed in the secret-s
  crop (4x upscale) - S ON
  the wall line, vertical wall
  through it, 'A' label beside
  at ~(16,17), numerals 10/21
  in view. Draft-grade tile;
  amend if his eyes put it a
  cell off. RUN clean: ring
  0, floaters 0, 1 secret.
  OPEN: how many S marks the
  level has (module text
  needed), key 10's chamber
  naming, key 12 (dist 4) and
  key 24 (r6 4-tile) suspect
  crops pending, pen-gate
  ruling, module text source
  (ls extract/g1/ pending).
  MODULE TEXT LANDED (2026-11-07):
  the G1 OCR was NEVER persisted
  (corner claim corrected); closed
  via HIS tesseract 300dpi run over
  ~/pdf/G1.pdf -> extract/g1/
  pg-01..13.{png,txt}, pushed
  (commit 14285eff). REPO NOW
  READ+WRITE via the github_app
  connector (ccicco/Adnd1;
  get_file_contents / push_files)
  - paste blocks retired for repo
  files; canvas ship + md5 gate
  STAYS for tools. p2 = map page
  (legend: 1 SQUARE = 10, DOUBLE
  DOOR, SECRET DOOR, FIREPLACE,
  TOWER, PIT, STAIRS UP); key
  text on p5-7. UPPER KEY LIST:
  1 ENTRY+CLOAK (A = guards at
  entrance, B = steps up to watch
  tower), 2 SUB-CHIEF, 3
  DORMITORY (12 young giants), 4
  BARRACKS, 5 MAIDS, 6 HALL OF
  THE CHIEF, 7 WIFE'S CHAMBER
  (cave bear guard), 8 CHIEF'S
  CHAMBER, 9 ARMS ROOM, 10 SMALL
  DINING (council; secret door to
  10A behind manticore hide - S
  CROP MATCH), 10A scroll room,
  steps to SECRET dungeon area,
  11 LONG HALL (80' passageway),
  12 GREAT HALL (fire pit,
  chief's table, ballista, ~44
  giants), 13 ARSENAL, 14
  WEAPONS, 15 MAIN GUEST (cloud +
  3 stone giants), 16 COMMON, 17
  KITCHEN (kitchen hearth ledger
  match), 18 KITCHEN WORKROOM, 18A
  storage + STAIRS TO LOWER, 19
  SERVANTS' QUARTERS (dire wolf
  keeper, whip by east door), 20
  ORC SLAVE QUARTERS, 21 OGRE
  QUARTERS, 22 OPEN COMPOUND
  (stockaded yard, 14 dire
  wolves), 23 GUARD ROOM (horn to
  call wolves; outbuilding), 24/25
  BARRACKS (outbuilding,
  palisade-connected; sergeant's
  alcove A). DOOR MECHANICS: die
  score to open, stays open;
  doors 7'x6'x1' iron-bound log;
  inner walls 2', outer logs 3',
  stone floors, ceiling 16-32'.
  ANCHORS: 12 GREAT HALL -> r4
  (96 tiles; the traced-22 numeral
  IS A MISREAD of 12 - it sits
  inside r4, GREAT HALL text, fire
  pit; per module 22 = the yard
  compound); 1 -> r19 (west
  double-door vestibule; A in
  r19, B -> r1 TOWER label per
  sheet_labels); 10 -> warren
  pocket at the 10 numeral, S to
  10A ✓; 6 -> r42; 8 -> r26; 22
  -> the yard band. MISREAD
  FLAGS (crops ordered): traced-
  "12" @ canvas (10,28) -> suspect
  18/18A (kitchen workroom zone,
  SW, kitchen-hearth ledger);
  traced-"19" @ (9,3) -> suspect
  (NW tower block; TOWER/B
  glyphs nearby could read as 19);
  traced-"20" @ (11,10) -> orc
  slaves zone but placed on the
  1-tile orphan r18; traced-"24"
  @ (29,3) -> NE corner but
  module 24 = outbuilding
  barracks - geometry mismatch.
  NEXT: 4 crops for the misread
  flags, full key->region
  proposal for his confirm,
  pen-gate ruling (module
  context: 22 = wolf compound
  inside the stockade, 23 = horn
  room; x4 gaps rows 37/39
  connect pen yard 68 to margin),
  then site.json assembly +
  battery.
  REGION-06 RULED (Curtiss +
  vision, 2026-11-07): the
  south band (cols 24-34
  rows 40-42, unc=12) is TWO
  things: (1) ANOTHER
  FIREPLACE/hearth with flue
  (left), and (2) the MAP
  LEGEND SYMBOL FOR STAIRS
  DOWN (right) - a small
  stair glyph with direction
  arrow, vision reads the
  word STAIRS with it. SIX
  regions ruled, all
  fireplace-family or legend.
  RUNNING TOTAL: 137 of 155
  ruled by design (tower
  stairs 27 + fireplaces/
  hearths 22+25+22+12=81 +
  legend strip 11 + hearth
  run 15 + this band's unc
  splits fireplace/stairs-
  down-legend). Remaining:
  the small solids/singles
  (~18 cells), the 89 gaps,
  row 42.
  After rulings: yard
  composition 39x51 -> 53x62,
  then site.json grid block per
  g1-site-format.
  (5) yard
  composition 39x51 -> 53x62; (6)
  site.json grid block per
  g1-site-format. Notable gap reads
  unchanged from v1.1.2: the four
  clean w3 ink 0.00 openings at x
  lines 17/21/22/23 cells 3-5 (real
  openings, not doors); the 43/45
  pairs on x lines 2-4; y line 31 the
  busy kitchen row.
  (provenance.px pitch/origin + lattice.cells;
  rejects rejected pages) + MATCH.json rows
  {i, px, lat, cls, family, proposal, dist,
  margin, confident, kind}; computes cell coords
  (px-origin)/pitch, cell_idx, straddle
  (distance to nearest line - walls ~0,
  interior ~0.5), in_grid check with OUTSIDE
  ask, per-label tally, and legacy_transform =
  least-squares affine lat->cell per axis = THE
  margin-offset measurement (where the old
  31x40 bbox lattice sits in the 39x51 grid).
  Output <stem>.cells.json beside the match file;
  state ask/stated. FIXTURES PASS (synthetic
  P=64 origin 1.1, 8 blobs incl. wall-on-crossing
  and 0.05-off-line hearth, out-of-grid blob;
  affine recovered exactly scale 1.0 offsets
  +2.0/+5.0 rms 0). Usage:
  python3 tools/mseat.py extract/g1/map-006.grid.json
  ~/mb6s4/map-006.match.json
  PIXEL-TOOL NOTE: label glyphs
  at this resolution print thin
  (density ~0.1-0.2); blob hunts
  need d>0.08 filters; the
  south-yard blob rows (y
  700-815) are the ROAD's drawn
  dashes, not labels. RULING
  ADJUDICATED (Curtiss, 2026-11-03,
  from the 300dpi raster): (1)
  THE NORTH-EDGE DOUBLE DOORS -
  the gap at Y0 cols 15-16 (the
  map's center-north) is the
  DOUBLE DOORS (the scattered
  strokes inside the gap = the
  drawn door leaves). ENCODED:
  door/gate tiles '+' replace
  the ring wall at the straddle
  pair rows 0+1, cols 15+16
  (four + tiles); south side =
  the compound mouth's open
  ground (floor-side check OK);
  north = the 10x yard margin
  (exterior-door closure OK).
  THE DOOR-DRAWING CAVEAT (user,
  2026-11-03): THE MAP'S DOORS
  WERE POORLY DRAWN - door
  symbols are unreliable at any
  resolution and the trace does
  NOT trust drawn door leaves/
  symbols as evidence. DOOR
  RULINGS COME FROM ONLY: (1)
  wall-gap geometry (the wall
  ink's actual absences -
  measurable pixels, the primary
  evidence); (2) module-text
  connectivity where the key
  implies passage; (3) Curtiss's
  adjudication from the raster.
  VISION DOOR READS ARE DEMOTED
  TO HINTS - retroactively
  explains the noise (the
  refuted '18 left-wall door',
  P4's contradictory 23<->22
  reads). The north double-
  doors ruling STANDS (adjudi-
  cated by Curtiss, not by
  drawing quality). THE DOOR
  VISUAL REPLACEMENT PLAN
  (user, 2026-11-03): at some
  point in the process the
  doors will be REPLACED WITH
  BETTER-LOOKING ONES - the
  engine renders doors from the
  door entities (proper
  artwork via the baked-tile
  pipeline), never
  reproductions of the 1978
  drawings. Consequence: poor
  source door drawings cost
  nothing downstream; wrong
  door POSITIONS would cost
  everything - the trace must
  get the geometry + door
  entity records right (tile,
  mate, type, orientation per
  the tile-metadata doctrine:
  the wall tile carries a
  reference, the door entity
  carries the metadata).
  REMAINING
  RULING QUESTIONS FOR
  CURTISS: (2) compound 22
  extent: top
  pen only, or union with the
  south yard; (3) ADJUDICATED (Curtiss,
  2026-11-03): 17 IS THE
  KITCHEN. RECT CONVENTION
  ADJUDICATED SAME DAY:
  room rects = WALL-INCLUSIVE
  FOOTPRINTS ("include the
  wall squares in the count").
  17 = cols 4-8 x rows 6-11
  (5x6 tiles; walls on lines
  X6/X9, Y6/Y10; straddle
  tiles cols 4-5 + 7-8, rows
  6-7 + 10-11); walkable
  floor = col 6 x rows 8-9
  (naive printed span cols 5-7
  x rows 7-10, 3x4). CANONICAL
  NUMBERING RULE: canvas col n
  = printed square between
  lattice lines n+1, n+2;
  canvas row n = printed
  square between lines n-1,
  n. Footprint = naive span
  expanded one tile on each
  walled side; footprints
  include INTERIOR wall tiles
  but NOT the outer ring (a
  room bounded by the map's
  boundary wall stops at the
  wall's interior half-tile:
  row 1 north / row 40 south /
  col 1 west / col 31 east).
  RECTS AS FOOTPRINTS (from
  pass-2 wall-line labels;
  floor = non-wall tiles in
  rect): 19 = cols 4-13 x
  rows 1-7 (floor cols 6-11 x
  rows 2-5, 6x4); 17 = cols
  4-8 x rows 6-11 (floor col 6
  x rows 8-9); 18 = cols 4-8 x
  rows 10-15 (floor col 6 x
  rows 12-13); 18A = cols 2-8 x
  rows 14-19 (west boundary
  X4-vs-X2 still open); 20 =
  cols 9-13 x rows 6-13 (floor
  col 11 x rows 8-11); 21 =
  cols 7-13 x rows 14-19
  (floor cols 9-11 x rows
  16-17); corridor = cols 7-10
  x rows 6-15 (floor NONE -
  see squeeze); south yard =
  cols 13-25 x rows 7-13;
  22 top pen = cols 19-25 x
  rows 1-5; 23 = cols 25-31 x
  rows 7-13; 24/25/A = cols
  26-31 x rows 1-5 (last four
  are open/edge areas - full
  footprints pending wall-
  line verification on the
  raster). Battery room-
  interior semantics: non-wall
  tiles inside the rect must
  be walkable. THE CORRIDOR
  SQUEEZE (doctrine question,
  ruling pending): under
  strict center distribution
  the 2-square corridor
  flanked by straddled walls
  (X9/X11) has BOTH its tiles
  consumed as wall halves ->
  ZERO walkable floor in the
  storage grid (drawn clear
  width 1.6 squares). Options:
  loader-collapse restores
  walkability / per-wall
  offset for narrow flanks /
  accept the squeeze; (4) 23<->22
  door; (5) Y14 opening
  k26.3-27.7. COORDINATE
  SYSTEM (explained to Curtiss
  2026-11-03): canvas col =
  printed X cell k-1 (lines
  k,k+1 -> col k-1), canvas
  row = printed Y cell k+1;
  lattice X line k at
  x=2.0+19.9k, Y line k at
  y=9.5+20k in the embedded
  image; printed squares =
  interior cells cols 1-31 x
  rows 1-40, ring at col 0/
  32 and row 0/41.
  WALK RESTART (Curtiss, 2026-11-03):
  he corrected the process - the
  walk goes EACH LOCATION
  SEQUENTIALLY in module key
  order (1, 2, 3... then 10A,
  18A, A, B); the 17/18 entry
  (already adjudicated) stands,
  but the walk now runs from
  key 1. THE MODULE PROSE IS
  RECOVERABLE: the OCR pages
  persist at tool-results/ocr/
  911d82c9-.../pages/page-00N.md
  (all 13 pages) - "look at the
  prose" = read these; key text
  for every location is in hand.
  LOCATION 1 WALK ENTRY (entry
  and cloak room; in progress):
  (a) THE MAIN GATE (the great
  doors) IS ON THE EAST WALL of
  the lodge (Curtiss) - NOT the
  south face; the south face
  inks solid full-width at 726px
  (no drawn opening anywhere,
  thr up to 230) - the seated
  "two gate-sized openings
  cols 9-10 / 20-21" in the
  south face is REFUTED; (b)
  pixel: lodge east face = the
  THICK line X28 (x556-562,
  near-continuous y100-679);
  X29/X30/X31 are 1px drawn
  lines (the east-strip
  dividers); stockade X33 with
  the seated east opening rows
  ~11-13; the road enters the
  stockade there and crosses
  the east strip to the east
  face; (c) ADJUDICATED: 1 =
  the room JUST INSIDE the east
  gate (pegs/outerwear room,
  prose p5); A = the 2 hill
  giant entrance guards JUST
  INSIDE the gate (prose: ale
  keg, alerts B); B = steps
  up to the WATCH TOWER - the
  solid dark structure labeled
  "B TOWER" (vision) at cols
  8-9 x yard rows 35-40,
  ADJUDICATED: solid block,
  steps inside, SEALS the yard
  strip (no ground passage
  through cols 8-9); (d)
  ADJUDICATED: the GREAT DOORS
  sit at ROWS 11-13 on the
  east face, straight across
  from the stockade opening
  (Curtiss) - encode as gate
  door tiles on the X28
  straddle pair cols 27-28 x
  rows 11-13, double great
  doors (north-gap precedent);
  (e) ADJUDICATED: room 1 =
  the room between the east
  gate and the GREAT HALL,
  west boundary = the Great
  Hall's east wall; interior
  walls pin at the great-hall
  pass. ENCODED SET FOR 1:
  great doors (cols 27-28 x
  rows 11-13), room 1 (east-
  gate entry/cloak room), A
  (guards at the gate, inside
  - encounter point, not a
  separate room), B (watch
  tower: solid block cols
  8-9 x rows 35-40, seals the
  yard strip, steps inside =
  a stair point record).
  LOCATION 1 IS COMPLETE.
  LOCATION 5 WALK ENTRY (maids'
  chamber) - ADJUDICATED
  (Curtiss, 2026-11-03): 5x4
  ROOM, floor cols 22-26 x
  rows 23-26 (footprint cols
  21-27 x rows 22-27; walls:
  Y22 band north y446-453,
  Y26 band south shared with
  room 3's north offset row,
  X22 west, the X27 wall
  pair east). DOOR: AT THE
  SOUTHEAST CORNER, OPENING
  EAST INTO THE HALLWAY
  (Curtiss) - the col-27
  hallway. PROSE (p5): 4
  giantesses (HP 34, 27, 24,
  23), usual furnishings;
  only the nasty old matron
  fights, she dominates the
  others; if the matron is
  slain the 3 others
  surrender/flee (text cut).
  BBOX PASS - LOCATION 1
  (ruled+corrected
  2026-11-04): bbox =
  (9,35)-(20,40), 12 cols x 6
  rows, FLOOR squares only.
  Frame: NORTH = lodge
  south face, line 34
  (great-doors gap at lines
  ~10.8-10.9 = cols 10-11,
  opening into the lodge);
  SOUTH = stockade south
  wall, line 40 (long run
  lines 9.1-22.4 + corner
  joints); WEST = vertical
  wall line 9 (x~181); EAST
  = vertical wall line 21.
  Counting convention
  CONFIRMED (final): box
  edges = the wall lines;
  numbered squares = floor
  between them. Cols 9-20 =
  lines 9->21 = 12 pitches;
  rows 35-40 = lines 34->40 =
  6 pitches. Height is 6,
  NOT 7 - my earlier
  wall-tile-row count was
  wrong; Curtiss self-
  corrected the NW corner
  from (9,34) to (9,35).
  LOCATION 1A (ruled
  2026-11-04): no bbox
  needed (encounter point,
  not an area). The 'A'
  label sits in square
  (20,38) - room 1's east
  side by the strip's east
  opening (the road/gate
  side; prose: A = 2 hill
  giants guarding the
  entrance).
  LOCATION 1B BBOX (ruled
  2026-11-04): (9,37)-
  (12,40), 4x4 solid block
  (cols 9-12 = lines 9-13;
  rows 37-40 = lines 36-40)
  inside room 1's SW
  corner; south edge merges
  with the stockade wall
  (Y40 run starts at line
  9.1). Stair point: steps
  up to the watchtower,
  dozing guard at top
  (prose B); not a separate
  room - overlaps room 1's
  floor box by design.

  NUMBERING CONVENTION
  (PINNED 2026-11-04, room
  2 pass; CORRECTED same
  day during room 3 pass):
  col c spans lattice lines
  c..(c+1); row r spans
  lines (r-1)..r. GLOBAL.
  Verified: building cols
  1-31 = lines 1-32 (west
  wall ink line 2 in col 1,
  east wall line 33
  outside); room 1 cols
  9-20 = lines 9-21; room 2
  cols 17-19 = lines 17-20;
  room 3 cols 18-27 =
  lines 18-28. CAUTION: do
  not assume long vertical
  ink runs are shared
  flanks between rooms -
  rooms 2 and 3 have
  INDEPENDENT flanks
  (Curtiss, 2026-11-04: 'no
  walls from 2 or 3 flank
  each other'); the line-18
  and line-21 runs in room
  2's row range belong to
  other structure (room 4
  candidates), not room 2.

  LOCATION 2 BBOX (ruled
  +verified 2026-11-04):
  (17,31)-(19,34), 3 wide x
  4 tall (lines 17-20 x
  lines 30-34). North wall
  = line 30 segment
  spanning lines 17.8-21.2
  (from full-map scan);
  south wall = lodge south
  face line 34; flanks =
  lines 17 and 20 (room 2's
  own walls). Size matches
  Curtiss's 2026-11-03
  ruling 'room 2 is 3x4'.
  Prose: sub-chief (HP 49),
  sleeping giantess (HP 29)
  in bed, shelf items (comb
  300gp, mirror 200gp, hair
  pin 800gp), chest 980cp/
  320sp/1500gp. Door from a
  hallway - identity still
  pending.

  LOCATION 3 BBOX (ruled
  +verified 2026-11-04):
  (18,27)-(27,29), 10 wide
  x 3 tall (lines 18-28 x
  lines 26-29). West flank
  = line 18 (room 3's own
  wall, rows ~26-29 part);
  east flank = line 28 (run
  rows 21.8-34.4); north
  wall = line 26 (span
  lines 18.8-27.1, meets
  west flank ink at the
  corner; small east-end
  gap = east door into the
  hallway); south wall =
  line 29 (same span). The
  old walk's '8x3' read the
  N/S wall spans (lines
  19-27) instead of the
  flanks - flanks + bbox
  agree on 10 wide.
  Prose: 12 young giants
  (fight as ogres), no
  treasure; garb disguise
  trick. Old 'two doors
  mid-wall row 28' entry
  needs re-derivation under
  the corrected mapping.
  Prose match: entry/cloak
  between gate and Great
  Hall, pegs, A guards at
  entrance, B steps/
  watchtower just west in
  the strip (solid block
  ~lines 6-9; rect
  re-derivation pending).
  OLD seated mapping for 1
  (gate on 'east face' cols
  27-28 rows 11-13) was the
  line-index error - the
  great doors are in the
  LODGE SOUTH FACE at cols
  10-11.

  BBOX PASS - FULL BATCH (ruled 2026-11-04;
  verified with bbox_check.py; room 5
  corrected to 5x4 per Curtiss):
    1 (9,35)-(20,40) 12x6 | 1A label (20,38)
    1B (9,37)-(12,40) 4x4 solid block
    2 (17,31)-(19,34) 3x4
    3 (18,27)-(27,29) 10x3
    4 (21,31)-(26,34) 6x4
    5 (21,23)-(25,26) 5x4 (N=line22,
      S=line26 both solid)
    6 (27,21)-(31,30) 5x10
    7 (27,31)-(31,34) 5x4
    8 (27,15)-(31,20) 5x6
    9 (21,17)-(24,20) 4x4
    10 (15,15)-(20,18) 6x4
    10A (13,15)-(14,18) 2x4
    11 (9,19)-(20,34) 12x16 (80' N-S =
      Long Hall; fire-pit label inside)
    12 (9,24)-(12,30) 4x7
    13 (10,31)-(12,34) 3x4
    14 (1,32)-(8,34) 8x3
    15 (1,23)-(3,30) 3x8
    16 (5,23)-(7,30) 3x8
    17 (1,19)-(6,22) 6x4
    18 (1,7)-(8,18) 8x12
    18A (3,15)-(6,18) 4x4
    19 (5,1)-(12,6) 8x6 (NW annex; N/S
      walls span cols ~5.6-13, W/E open;
      RULED: ends at col 12)
    20 (10,7)-(12,12) 3x6
    21 (9,13)-(12,18) 4x6
    22 (13,1)-(31,14) 19x14 open compound
      (N = north stockade 100%; RULED:
      begins at col 13, butts 19 at
      line 13 - no overlap; line-9 wall
      rows 6-14 is internal structure/
      20-21 west wall, not 22's edge)
    23 (25,7)-(31,10) 7x4
    24 (26,1)-(31,6) 6x6
    25 (19,1)-(25,6) 7x6
  INK NOTES from batch scan:
  - Lodge is OPEN-PLAN: many E/W flanks
    read weak/open (light ink bits at
    lattice crossings only); strong N/S
    walls confirm the boxes.
  - LINE 32 = lodge east face, drawn
    light ink everywhere; stockade east
    wall at line 33 outside it. Resolves
    the old 'X28 vs X31' question.
  - 6's NW open entryway confirmed: gap
    cols 27-27.8 in line 20.
  - 10<->10A secret door on line 15
    (S glyph): gaps at rows 14.4-14.7
    and 16.2-16.5 in line 15.
  - 4's N wall door gap cols 21.4-21.9.
  - 9's N/S walls have west-end gaps
    (cols 21-21.8) = opening at west end.
  - 12's S wall door gap cols 9-9.5.
  - 13's E wall seg rows 31-32.2 with
    gaps = door(s) east.
  - 20's S gap cols 10.1-10.9 = SW
    opening; 21 shares it (opening
    between 20 and 21).
  - 22's W wall solid rows 6-14, open
    rows 1-6 (to 19's annex zone).
  - 18's E = the long line-9 wall rows
    6-14.6; N wall only spans cols ~5-8.
  - 18's/14/15/17 W edges at line 1 have
    NO ink; stockade ink at line 2 =
    one pitch inside their boxes.
    RULED (Curtiss, 2026-11-04): this
    question involves the yard and the
    wall center distribution - DOES NOT
    COUNT YET; deferred to a later
    pass. Boxes stand as ruled.
  - 19/22 RESOLVED (Curtiss ruled
    2026-11-04): 19 ends at col 12,
    22 begins at col 13 - they butt
    at line 13, no overlap. My overlap
    read came from including 19's strip
    in 22's box; corrected.

  DOORS/CONNECTIONS/POINTS PASS (started
  2026-11-04; prose p5-p7 loaded):
  RULINGS (Curtiss, 2026-11-04):
  - Rooms 9, 5, 4 STAY AS RULED
    ((21,17)-(24,20), (21,23)-
    (25,26), (21,31)-(26,34)) -
    Curtiss visually counted
    their squares. NOTE OPEN:
    a long solid N-S wall on
    lattice line 22 (rows
    14-35, door gaps rows
    ~26.5-27, ~28.5, ~29.5)
    and 9/5/4's N/S wall spans
    fit lines 22-26/27/28 (one
    pitch east of the ruled
    boxes) - resolves at
    their doors pass.
  - LONG HALL (11) EXTENT: runs
    from the location-19 area
    all the way down to
    location 1 (Curtiss,
    looking at the map). Box
    pending; candidate slot =
    col 21 corridor (east wall
    = the line-22 wall, west =
    line 21 mostly open rows
    15-29, solid rows 30-34;
    capped N by Y14 wall cols
    19-28, S by Y30). 80'
    prose length fits rows
    15-30 = 16 rows.
  - THE TWO TRANSVERSE POCKETS
    (rows 21-22 and 27-30,
    cols 22-27, flanking room
    5, entered via the line-22
    door gaps) = ANOTHER
    HALLWAY (unkeyed passage).
  POINTS LOCATED (ink):
  - GREAT HALL label: text row
    ~18.6, cols 14-18 (top
    edge of the hall, per
    Curtiss: 'says great hall
    right on the map at the
    top edge').
  - FIRE PIT: symbol + label
    at cols ~16-16.5, rows
    ~21.8-22.4 = square (16,22)
    area, center of the Great
    Hall. Chief's table N of
    the pit; ballista on wall
    behind chief (points pass
    pending).
  DOOR/OPENING INVENTORY (from
  solid-wall gaps; lattice-
  crossing noise excluded):
  - 1: W opening rows 34.55-
    35.45 (into south yard);
    great doors in lodge face
    at cols 10-11 (drawn
    leaves, line 34); E side
    open to the road strip.
  - 2: N opening cols
    17.15-17.85 in line 30.
  - 3: N door cols 27.3-27.85;
    S door cols 27.2-27.85;
    S door cols 18.25-18.8.
  - 4: N door cols 21.35-21.85
    (line 30).
  - 6: N opening cols
    27.1-27.8 in line 20 =
    SHARED with 8's S edge
    (8<->6 passage, one
    opening seen from both
    sides); W wall solid rows
    21.9-27.1 with door gaps.
  - 8: S door cols 27.1-27.8
    (same gap as 6's N).
  - 9: N and S walls have
    west-end gaps cols 21-
    21.8 (openings at the
    west end).
  - 10<->10A SECRET DOOR:
    line 15, S glyph; gaps at
    rows 14.4-14.65 and
    16.25-16.5 (drawn leaves
    behind the manticore
    hide, per prose).
  - 12: S door gap cols
    9.45-9.85 (line 30, into
    13's zone); N edge open.
  - 13: W door rows 30.2-30.9
    (line 10); E doors/gaps
    rows 30.45-30.95 and
    32.25-32.9 (line 13).
  - 18<->17: openings in line
    18 at cols 1-1.8,
    2.36-3.06, 3.21-3.96
    (workroom to kitchen);
    18's S gap cols 8.34-9
    (SE corner).
  - 18A: openings east into
    18 (line 7 gaps); N door
    cols 3.2-3.9.
  - 19: E doors into 22 (line
    13 gaps rows 0.45-1.15
    and 5.3-5.85; whip hangs
    beside the east door per
    prose); W side fully open
    (annex opens west to the
    north yard); N/S walls
    span cols 5.6-13.
  - 20<->21: shared opening -
    20's S gap cols 10.2-10.9
    = 21's N gap cols
    10.21-10.91 (one opening).
  - 21: E door rows 12.4-13.1
    (line 13, into 22).
  - 23: S door cols 25.1-25.75
    (line 10, into 22 - guard
    room, horn to call
    wolves).
  - 25: S door cols 19.15-19.8
    (line 6).
  - 1B: N gap cols 10.26-10.86
    (line 36 - stair block
    north face; likely the
    drawn steps, unruled).
  RULINGS (Curtiss, 2026-11-04,
  doors pass): rooms 2/12/13
  BUTT UP TO the Great Hall -
  they are NOT embedded in
  it (hall floor excludes
  them; boxes may share
  bounds but the hall is its
  own geometry). Great hall
  interior is ink-empty
  apart from the fire pit -
  chief's table, benches,
  ballista are PROSE-ONLY
  points (not drawn on the
  map). NEXT: Curtiss will
  provide an EDGE LIST in
  square coordinates giving
  the entire geometry of the
  long hall (and the same
  treatment can express the
  great hall's butting
  shape).

  EDGE LIST FORMAT (PINNED
  2026-11-05, long-hall edge
  pass; all conventions
  Curtiss-ruled same day):
  - Entry shape: [n]:
    (ca,rb)-(cc,rd)[axis]
    [side] <status>, [gap
    annotations]. span=N is
    Curtiss's own checksum
    field - KEEP on intake,
    cross-check vs coords,
    flag mismatches to him,
    never silently fix.
  - 1-span entries REQUIRE
    axis marker v/h (extent
    carries no axis).
  - Side letters scoped to
    ranges: W/E for vertical
    spans, N/S for
    horizontal. Required on
    every edge. A square run
    with walls on both
    sides = TWO parallel
    edges (double tracing
    with distinction),
    listed once per side.
  - One wall = one edge:
    door gaps do NOT split
    edges; they go inline
    with row/col ranges.
    Segments only get own
    entries when wall
    identity changes.
  - Wall JOGS stay one
    edge with the jog noted
    inline (ruled on edge 4:
    line-8 wall jogs east
    at Y22 to line 9).
  - Door facing when the
    door's line differs
    from the span line:
    door (square)(side),
    e.g. door (9,16)S =
    gap in Y16. Square+side
    always names one
    lattice line.
  - Closed cell (walls all
    four sides of one
    square): NOT an edge -
    flag, bbox treatment.
  - Clockwise perimeter
    walk: one pass, single
    trace per segment,
    statuses inline.
  - SQUARE NUMBERING
    RE-CONFIRMED 2026-11-05:
    pinned room-pass
    convention stands
    (col c spans lattice
    lines c..c+1; row r
    spans (r-1)..r). The
    'east side' exchange on
    edge 4 was a
    both-verified moment:
    Curtiss ruled the
    pinned convention
    holds. CAUTION: a
    door centered on a
    row BOUNDARY line
    (Y21) touches both
    adjacent rows - his
    'doors (8,21)-(8,22)'
    = ONE door opening
    straddling the Y21
    line (2+10+2ft jamb
    signature), NOT a
    2-row door.
  EDGE 4 (SEATED 2026-11-05,
  verified pixel-exact):
    4: (8,17)-(8,30)v W
    solid rows 17-20, door
    (8,21)W-(8,22)W rows
    21-22, REVISED 2026-11-05
    (full-res, Curtiss
    eye-confirmed
    unbroken): THIN WALL
    solid rows 23-30
    (~4px, invisible to
    the OCR copy; the old
    "open rows 23-30" was
    a downscale artifact);
    E open rows 17-22,
    solid rows 23-30. Ink:
    line 8 solid rows 17-20
    + door straddling Y21,
    ends at Y22; Y22
    horizontal wall closes
    west-to-line-9; line 9
    solid rows 23-30; line
    10 solid throughout
    (belongs to next edge,
    not edge 4). OPEN ITEM:
    glyph blob in square
    (8,26)-(8,27) between
    lines 8-9 (x~157-175,
    y~521-537) - door swing
    arc? furniture? Ask
    Curtiss when he passes
    that segment. (RESOLVED
    2026-11-05: area label
    "16" - see THIN-WALL
    LESSON block.)
  THIN-WALL LESSON (found
    2026-11-05, full-res):
    the 726x827 OCR copy
    DESTROYS thin ink.
    Line X8 rows 23-27 is
    a continuous ~4px
    wall at full res
    (2550px wide) but
    reads 0.03-0.05 "open"
    in the OCR copy
    (downscale washes 4px
    lines to sub-pixel
    gray). Consequences:
    (1) edge 4's "open
    rows 23-30" segment is
    a DOWNSCALE ARTIFACT -
    full-res ink + the
    Y24-Y27 west-room grid
    T-junctions say line 8
    continues below the
    door as a thin wall;
    revision pending
    Curtiss's eye-check -
    CONFIRMED 2026-11-05,
    wall unbroken to 30.
    (2) The seated blob at
    rows 26-27 resolves at
    full res into TWO
    masses: the seated one
    between lines 8-9
    (fullres x~686-718) +
    a NEW unrecorded mass
    WEST of line 8
    (fullres x~658-672,
    square 7-8). Identity
    of both pending his
    eye-check. RESOLVED
    same day: label = "16",
    and Curtiss confirmed
    the thin wall runs
    UNBROKEN row 27 to 30.
    Edge-4 revision fully
    seated; E-side (open
    17-22, solid 23-30)
    unchanged. (3) STANDING
    RULE: for thin or
    faint ink, the full-res
    Termux copy is the
    AUTHORITY; the OCR copy
    can prove ink EXISTS,
    never that it's absent.
  BLOB RESOLVED (ruled by
    Curtiss 2026-11-05 from
    the full-res ascii map):
    the two masses at rows
    26-27 are the ROOM-KEY
    LABEL "16" printed
    centered on line X8 -
    digit '1' at fullres
    x~658-670, digit '6' at
    x~686-718. NOT a door,
    furniture, or stairs.
    Edge-4 open item CLOSED.
    LESSON: map area labels
    are numerals that
    often straddle lattice
    lines; a glyph blob
    hugging a wall line is
    a LABEL CANDIDATE first
    - crop and read the
    digits before seating
    it as furniture or
    door hardware.
    STILL OPEN: does line
    8's thin wall run
    continuous from row 27
    to row 30 (edge 4's
    south end)? CLOSED
    2026-11-05: yes,
    unbroken (Curtiss).

  MAP IMAGE PERSISTENCE
  (seated 2026-11-05): the
  working G1 map scan is
  saved at the g1-skeleton
  work dir as map_g1.jpeg,
  726x827, md5
  55f65e877b83e61d2c0d8434-
  19d69b72. The uploads were
  text-only stubs (bytes
  not stored). CANONICAL
  COPY DOCTRINE: ~/Adnd1
  in Termux holds the
  source of truth; verify
  byte-identity with the
  md5 before any new
  session trusts its
  local copy. hallscan.py
  takes the image path at
  runtime:
  python3 hallscan.py
  <image> v 8 15 31.

  IMAGE PIPELINE (ruled
  2026-11-05): chat
  uploads of images/PDFs
  arrive as TEXT-ONLY
  STUBS (bytes not
  stored) - pixel work
  CANNOT go through
  upload. The pipeline:
  Curtiss extracts the
  canonical image in
  Termux (pkg install
  poppler; pdfimages -j)
  into ~/Adnd1; lattice
  constants are then
  fitted LOCALLY with
  fit_lattice.py
  (detects wall runs,
  anchors west=X2,
  east=X33, north=Y0,
  south=Y40, prints
  X0/XPITCH/Y0/YPITCH +
  diagnostics;
  validated on the
  726x827 copy: recovers
  X0=2.1/19.95,
  Y0=10.0/20.03, interior
  residuals <2px) and
  pasted into
  hallscan.py (image
  path at runtime, BAND
  auto-scales to
  0.15*pitch). G1.pdf
  page-2 embedded map =
  2550x3300 300dpi
  (map-006.jpg after
  pdfimages); richer than
  the 726x827 OCR copy.
  Both scripts delivered
  as code canvases
  (hallscan, fit-lattice).

  code canvases
  (hallscan, fit-lattice).
  FULL-RES LATTICE (fit
  by Curtiss in Termux,
  verified 2026-11-05):
  on map-006.jpg
  (2550x3300, 300dpi):
  X0=181.95, XPITCH=
  64.2742; Y0=482.00,
  YPITCH=64.5875.
  Uniform scale 0.3096
  vs the 726x827 OCR
  copy both axes; same
  lattice, line numbers
  identical. Diagnostics
  passed: pitch ratio
  0.995, anchors =
  stockade walls (X2 at
  310.5, X33 at 2303,
  Y0 at 482, Y40 at
  3065.5), interior
  residuals <= 5.6px
  (~0.09 pitch, ink
  wander class).

  BUILDING BOUNDING BOX (ruled
  2026-11-04, bounding-box
  pass): whole-building bbox =
  (1,1)-(31,40), 31 wide x 40
  tall (ENDING VALUES RULED
  2026-11-04: 31 squares
  used horizontally and 40
  vertically. DERIVATION:
  square count = DIFFERENCE
  between outer wall lattice
  lines, not the line index
  or canvas size. West wall
  ink x=41.8 = lattice line
  2; east wall ink x=658.7 =
  line 33; 33-2 = 31
  pitches = 616.9px/19.9 =
  31.0. North wall y=9.5 =
  line Y0; south band y~809
  = line Y40; 40-0 = 40
  pitches = 800px/20 = 40.0.
  (Earlier error: read the
  east wall's line index 33
  and canvas height 42 as
  box edges instead of
  counting intervals
  between wall lines.)
  CLARIFICATION (Curtiss,
  2026-11-04): outer-wall
  center distribution is
  NOT ignored as doctrine -
  it simply does not matter
  for the bounding-box
  exercise. The bbox only
  needs the outer wall
  lines' extents; which
  squares the outer wall
  ink partly occupies does
  not change the box.
  CONSEQUENCE: the earlier
  walk's pixel-derived col/
  row proposals used line
  indices as square numbers
  and are systematically
  shifted - seated SIZES from
  Curtiss's rulings stand,
  but rects get re-derived
  under the corrected
  mapping during the
  bounding-box pass. Row
  convention check: 40
  squares between Y0 and
  Y40 -> row r spans lines
  (r-1)..r (Y34 wall = south
  edge of row 34 ✓). Column
  convention pending
  Curtiss's pin. Ending
  values: EAST face = col 33
  line, thick ink rows ~1-
  34 (stockade opening rows
  ~11.5-13), ink stops at
  the row-33/34 boundary
  wall - SE quadrant closure
  per that wall. SOUTH wall
  = row-40 band: long run
  cols 9-22, far-west SW
  corner bit cols 1-2, bits
  cols ~29-31, gaps cols 2-9
  and 22-29 (candidate
  openings, unruled); wall
  ink continues below the
  band at cols 9-14. South
  strip verticals: heavy N-S
  runs on col 20-22 lines
  (col-22 runs nearly the
  full strip) and col 29-31
  lines. A bbox only wraps the
  FURTHEST EXTENT on each of
  the 4 edges - it need not
  fit the object at every
  edge (NW corner square
  (1,1) is open yard; the box
  still pins there because
  the wall runs bound the
  envelope). Wall extents:
  WEST wall = col 1 tiles,
  rows ~10-34 (ink extent
  rows 9.6-34.5); NORTH wall
  = row 1, from ~X6 area
  east to col 33 (opening
  ~cols 16.4-17.9 beside
  the ruled north double
  doors cols 15-16); EAST
  wall = col 33, rows 1-34,
  stockade opening rows
  ~11.5-13 (opposite the
  ruled great doors cols
  27-28 rows 11-13); SOUTH
  wall = row 34, full width,
  solid (two small gaps ~col
  11 and ~col 18, likely
  drawn door leaves,
  unruled). NW annex/yard
  enclosure walls sit on the
  X6 and Y10 lines (annex
  area west of X6, north of
  Y10). Outside-wall center
  distribution is IGNORED
  for this exercise (no
  straddle for outer faces).

  LOCATION 8 WALK ENTRY (partial)
  - PIXEL FACTS: east of room
  6, one thick-walled room
  4x6, floor cols 28-31 x
  rows 14-19 (north wall on
  the 13/14 line, south wall
  on the 19/20 line); partial
  vertical stub 2 squares in
  from its west side (spans
  ~rows 17-18 only; hearth/
  alcove class, unruled);
  printed '8' label inside
  center-right; stair symbol
  (parallel bars) in the
  col-27 strip rows 15-19
  (north end of col-27
  hallway).
  - ADJUDICATED (Curtiss,
  2026-11-03):
  (a) NO DOOR on 8's north
  wall - the vision-read
  "centered north door" is
  DENIED (door-drawing
  caveat; door symbols
  remain untrusted).
  (b) NEW GLYPH DOCTRINE:
  the glyph vision read as
  "$" is actually "S" = a
  SECRET DOOR marker. Two
  confirmed S glyph
  positions: west wing 1-
  wide strip (col ~15, row
  ~14.7) and near the east
  block's west wall (~col
  28, rows ~15-16). 10A
  prose confirms one secret
  door (10 <-> 10A behind
  the manticore hide); map
  shows two S marks - exact
  doors UNRULED until the
  bounding-box pass.
  (c) PLANNED: Curtiss will
  walk each location giving
  BOUNDING BOXES to pin
  geometry cleanly; stairs
  identity and room 8/9/10
  compartment splits defer
  to that pass.
  - Room 10 candidate: cols
  16-21 x rows 14-17 (6x4),
  door symbol mid-left wall
  (vision read, unruled).
  10A candidate: cols 14-15
  area west wing with door
  on its right wall
  (unruled). Y18 long wall =
  Great Hall north wall
  (FIRE PIT label just
  south at ~col 16, row 22).
  LOCATION 7 WALK ENTRY
  (chamber of the chief's wife)
  - ADJUDICATED (Curtiss, 2026-
  11-03): 5x4 ROOM directly
  south of 6, floor cols 22-
  26 x rows 22-25 (footprint
  cols 21-27 x rows 21-26;
  north wall = the Y22 band
  shared with 6, south wall
  ~row 26). DOUBLE DOORS at
  the NW corner, opening NW
  out into location 6 at its
  SW corner - encode 4 '+'
  tiles at the straddle
  pair rows 21-22, cols 22-
  23 (north-gap precedent).
  PROSE (p6): she is at 11;
  the pet CAVE BEAR (HP 35)
  guards, smells anyone at
  the door, silent; bed,
  small table, chair, stool,
  2 chests (clothing), coffer
  + rugs/hides; hidden in
  the straw mattress: pouch
  of 29 gems (1x5000, 3x1000,
  4x500, 8x100, 5x50, 8x10
  gp). ROOM 5 REVISION
  (Curtiss, 2026-11-03): the
  maids' chamber is WEST OF
  THE GREAT HALL - the seated
  "room 5 = cols 22-26 rows
  23-26" rect is SUPERSEDED
  (that room is 7; the pass-2
  vision '5' label read in
  that zone = a digit misread
  at 726px). Room 5 = 5x4,
  SE-corner door into a
  hallway; exact rect pins
  at the great-hall/west
  pass. The col-27 hallway
  loses its room-5 SE door;
  it serves 3 (east door),
  7 (east side abuts it -
  7's east wall = X27 line),
  and 4 (NE door at row 30).
  LOCATION 6 WALK ENTRY (hall
  of the chief) - ADJUDICATED
  (Curtiss, 2026-11-03): 5x10
  ROOM, floor cols 22-26 x
  rows 12-21 (walls: Y10 band
  north y210-214 (partial
  width), Y22 band south =
  shared with room 5's north
  wall; X22 west (wall
  segments y301-459 = rows
  14-22), east = X27 line
  (mostly open rows 16-21 -
  the col-27 passage area
  abuts the room's east
  side; X27 wall bits y287-
  298 only). MAIN ENTRY: AT
  THE NORTHWEST CORNER, a
  2-SQUARE OPEN ENTRYWAY
  (Curtiss) - encode tiles
  (21,12)+(21,13) open in
  the west wall's north end,
  opening west into the
  chief's wing. INTERNAL INK
  = FURNITURE (the Y14/Y16
  bands + X26 segments
  inside = drawn tables/
  kegs/fireplace - features,
  not walls; the points pass
  owns them; room 6 is ONE
  5x10 room per Curtiss).
  PROSE (p6): tables w/
  flagons + platters, kegs,
  trophies (heads, skulls,
  skins, arms), 8 shields
  across from the fireplace
  (one +3, detect-magic
  only), brass jar +
  valueless skull on the
  mantle - the skull holds a
  2,000 gp gem.
  THE COL-27 HALLWAY
  (DISCOVERED 2026-11-03,
  identity: the lodge-east
  arm of the eastern
  section): the 1-tile
  passage between the X27
  wall (x~539) and the lodge
  east face X28 (x~559) =
  col 27, running N-S from
  ~row 21/22 down to room
  4's north wall at row 30;
  serves room 5 (SE door),
  room 3 (east door at
  (26,28) - REVISED: 3's
  east door opens into THIS
  hallway, not the far-east
  strip), room 4 (NE-corner
  door in the north wall,
  east end = the hallway's
  south mouth at (27,30));
  north end + room 6 zone =
  next entries.
  LOCATION 4 WALK ENTRY (barracks)
  - ADJUDICATED (Curtiss, 2026-
  11-03): 6x4 ROOM, cols 22-27
  x rows 30-33 (the drawn floor
  spans y612-687 = 4 rows
  between the Y30 band and the
  lodge south face; the row-30
  band is shared with room 3's
  south offset wall - exact
  wall-row assignment resolves
  at generate/compose per the
  per-run offset machinery).
  DOOR: AT THE NORTHEAST
  CORNER (Curtiss) - side
  (north wall vs east wall)
  pins at his 300dpi/doors
  pass. WALLS: west = the
  thick X21/X22 pair (cols
  20-21 - squeeze pair per
  ruling E, west of the room
  = the cols-20/21 sliver,
  wall-class y612-686);
  east = lodge east face
  X28; north = the Y30 band;
  south = the lodge face
  (Y34). The mid-run divider
  (X25 short segment y635-
  654) = drawn furniture/
  partial - room 4 is ONE
  6-wide room per Curtiss
  (NOT divided from 7 by a
  wall there). PROSE (p5):
  2 sleeping giants (HP 39,
  38), 10 beds, 10 chests,
  clothing on walls, torches
  in cressets; pouch 110 pp
  in the first chest
  searched.
  LOCATION 3 WALK ENTRY (dormitory)
  - ADJUDICATED (Curtiss, 2026-
  11-03): 8x3 ROOM, floor cols
  18-25 x rows 27-29 (first
  column at col 18 - Curtiss),
  footprint cols 17-26 x rows
  26-30. WALLS: north/south =
  the wing wall bands Y26
  (y528-532) / Y29+Y30 cluster
  (y588-612) - SQUEEZE
  TREATMENT per ruling (E):
  offset wall lines row 26 /
  row 30, floor keeps its 3
  drawn rows; west/east walls
  = X18/X26 area (the wing's
  interior verticals print 1px
  texture at 726px - X22/X27
  wall-class segments neighbor
  but do not cut the room).
  DOORS: TWO, both MID-WALL at
  row 28 (Curtiss): west door
  (toward the Great Hall side)
  + east door (toward the
  eastern section). PROSE
  (p5): 12 young giants
  (HP list), fight as ogres,
  no treasure; garb = disguise
  (pass as youngsters at 20').
  LOCATION 2 WALK ENTRY (sub-
  chief's room) - ADJUDICATED
  (Curtiss, 2026-11-03): 3x4
  ROOM, floor cols 15-17 x
  rows 30-33, footprint cols
  14-18 x rows 29-34 (north
  wall = the Y28 band y568-
  572, 3-4px lodge-wall class,
  one row above the Great
  Hall's south wall Y29/Y30
  cluster; south = the lodge
  south face; west/east = the
  strong verticals X15 (x~300)
  / X18 (x~358); the "2" label
  prints inside at ~col 16-17
  row 32). DOOR: OPENS FROM A
  HALLWAY (Curtiss) - the
  hallway's identity + the
  door's squares pin at the
  south-wing/great-hall pass
  (candidate: the Long Hall
  11). PROSE (p5): hides,
  bear skin, chair, stool,
  huge chest (980 cp, 320 sp,
  1500 gp), vast bed with
  sleeping giantess (HP 29,
  awakens 1 in 4 or loud
  noise), shelf 9' up (silver
  comb w/ 4 gems 300 gp,
  copper mirror 200 gp, gold
  hair pin w/ pearl 800 gp).
  THE 17/18 WALK ENTRY - ADJUDICATED
  (Curtiss, 2026-11-03): THE
  KITCHEN COMPOUND IS ONE OPEN
  FLOOR - 17 the kitchen (north),
  18 the workroom (south), NO
  wall between them (the Y10
  hair + X7/X8 verticals = the
  drawn COUNTERS = furniture
  features, never wall tiles;
  pixel-proven: no thick band
  x121-180 at y203-213, only
  the 2px counter hair at
  y213-214). COMPOUND FLOOR =
  col 6 x rows 8-13 (X6
  straddle west, X9 west-offset
  col 7 east, Y6 straddle
  north, Y14 straddle south).
  KEYS: 17 = rows 8-11, 18 =
  rows 12-13 (the row 11/12
  line = conceptual key
  boundary, open floor).
  ENTRIES (all Curtiss-
  adjudicated 2026-11-03):
  (1) 17 EAST OPEN ENTRYWAY:
  tiles (7,10)+(7,11) - the
  drawn void x166-175 at the
  boundary line's east end =
  the one drawn opening in X9
  (11px void; the counter hair
  resumes x176+); connects
  17's SE corner to the east
  corridor (cols 8-9).
  (2) 17 SOUTH DOOR: the UPPER
  west-wall gap (X6 ink void
  y215-234 = rows 11-12) - a
  DOOR into THE WEST HALLWAY
  (the strip between X4 and
  X6), which leads to 15, 16,
  and 14 (Curtiss: "17's south
  door leads to 15, 16, and
  14"). (3) 18 SE DOOR: a door
  in the X9 offset wall at
  tiles (7,12)-(7,13) into the
  east corridor (ADJUDICATED -
  NO drawn gap: X9 solid
  y130-294 at thresholds 160
  AND 200; the 726px raster
  cannot show it, per the
  door-drawing caveat).
  (4) 18'S WEST DOOR: the LOWER
  west-wall gap (X6 void
  y254-290 = rows 12-14) = the
  door to 18A (Curtiss: of the
  two doors by 18A, one leads
  to 18A, the other to the
  hallway). SUPERSEDED: the
  pass-2 rects "17 cols 6-8
  rows 6-9" and "18 cols 5-8
  rows 11-13" -> the single
  open-floor compound (two
  keys, one region). THE SOUTH
  WING: the area south of Y14
  = the 14/15/16 wing + 18A -
  walk it next (module key
  order); pins owed there:
  17's south-door far side,
  18A's own door + THE STAIRS
  tiles. EAST CORRIDOR = cols
  8-9 x rows 7-14 (X9 offset
  col 7 rows 6-14, X11 offset
  col 10 rows 6-16); 20's X11
  doors (row 8 y156-171, row
  10 y198-210) pending 20's
  walk entry.
  NEXT PASSES: great hall block
  (rows 18-34), chief's wing
  (cols 19-31 rows 14-34),
  points pass (18A stairs, all
  doors), yard/road pass.
  KITCHEN-COMPOUND + EASTERN-
  SECTION RULINGS AND PIXEL PASS
  (2026-11-03, user rulings +
  pixel-verified): (A) USER
  RULING: 17+18+18A = ONE
  KITCHEN - 17 the kitchen, 18
  the kitchen workroom (ready
  storage + servants' eating
  place), 18A the storage room
  with THE STAIRS DOWN; the
  module keys them separately
  BY PURPOSE, not because they
  are separate compounds (the
  points pass owes 18A the stair
  tiles). (B) USER RULING: 22 =
  THE OPEN COMPOUND and the only
  yards accessible FROM 22 are
  the NORTH YARD and the EAST
  YARD (module p4 confirms:
  "Location 22. is an open
  stockaded yard" and 23-25 are
  an outbuilding connected to
  the main lodge by the huge
  palisade). (C) PIXEL
  TOOLING RESTORED: the sandbox
  restart wiped PIL/numpy AND
  forbids reinstall - built a
  pure-stdlib baseline JPEG
  decoder (jpeg_y.py, luma
  plane yplane.raw 726x827 in
  the g1-skeleton dir); the
  seated lattice RE-VERIFIES on
  the fresh decode (strong ink
  at every predicted line, X33
  stockade x 656-664, Y0 band
  y 8-15, wobble +-3-4px as
  seated). (D) EASTERN SECTION
  (all pixel-verified, canvas
  coords, footprint convention):
  OUTBUILDING 23/24/25/A =
  footprint cols 26-31 x rows
  1-6, floor cols 27-30 x rows
  2-5 (4x4); drawn ROOFED -
  dense plank texture covers
  the footprint and NO internal
  walls are drawn; west wall
  X27 solid rows 1-6 with NO
  drawn door; vision reads 23
  south, 24 NE, 25 NW, A near
  25. TOP PEN = footprint cols
  18-26 x rows 1-6ish, floor
  cols 20-24 x rows 2-5; walls
  X20 west (solid), X27 east,
  Y0 north, Y6-M south = an
  ENCLOSED wolf pen; its only
  drawn opening = an 8px break
  at the SE corner (x 522-530
  = col 25 rows 6-7, between
  the X26 fence top and the
  outbuilding's west wall) -
  the pen gate, opening EAST
  into the east strip (not
  into the main yard). Y6
  DIVIDER = palisade fence
  texture; M solid k18-26, E
  solid k25-32 except the pen
  notch; the big mouth
  k14.1-19.8 (cols 13/14-18)
  opens the main yard NORTH
  into the WEST STRIP (floor
  cols 14-18 x rows 2-5,
  bounded west by X14 which is
  solid from row 1 to row
  19.5). MAIN YARD (22) =
  naive span cols 14-24 x
  rows 7-13, floor cols 15-24
  x rows 8-13 (wall/fence
  halves on the boundary);
  west X14, north Y6 (mouth
  to the west strip), east
  the X26 fence, south Y14.
  X26 FENCE = ink x 515-520,
  5px thin, center k25.9 -
  it hugs line 26's WEST edge
  and sits essentially within
  col 24, rows 7-11 = a
  DRAWN OFFSET (near-single-
  tile) wall - the drawing
  itself contains an offset
  precedent, doctrine-relevant
  for the corridor squeeze;
  south of row 11 the fence
  ends (rows 12-13 connect
  main yard <-> east strip).
  EAST YARD = naive span cols
  25/26-31 x rows 7-13 (west
  X26 rows 7-11, north Y6-E,
  south Y14 with the
  k26.3-27.7 opening at cols
  25-26, east stockade X33).
  The pass-2 rect "23 = cols
  25-31 rows 7-13" is
  SUPERSEDED - that strip is
  the EAST YARD, not the
  guard room (23 lives in the
  roofed outbuilding). South
  of Y14: X26 has a second
  solid segment rows 17-19.3
  (y 327-375) and X28 runs
  solid rows 14.1-19.3
  (y 271-376) - the Y14
  opening k26.3-27.7 leads
  into the cols 26-27 lane
  between them -> great-hall
  pass. The "22" digits were
  NOT found as discrete blobs
  at 726px (the yard is dense
  fence/grass texture that
  poisons the blob filter);
  the pass-2 "22 blob in the
  top pen" was TEXTURE
  STROKES, retracted; vision
  places the 22 label in the
  UPPER PART OF THE MAIN
  YARD. RULINGS ROUND 2
  (Curtiss, 2026-11-03): (E)
  THE CORRIDOR SQUEEZE IS
  RULED: PER-WALL OFFSET FOR
  SUCH FLANKS - narrow
  passages flanked by walls
  closer than 2 clear squares
  get their flank walls
  encoded as SINGLE-TILE
  OFFSET walls (one tile per
  wall, offset AWAY from the
  passage), so the passage
  keeps its naive squares as
  floor. The X26 fence (drawn
  offset, col 24) is the
  precedent. APPLIED: kitchen
  corridor X9 -> west offset
  (tile col 7, rows 6-14),
  X11 -> east offset (tile
  col 10, rows 6-16) ->
  corridor floor = cols 8-9 x
  rows 7-14 (2 tiles, matches
  the drawn 2-square
  passage); 17's floor (col 6)
  and 20's floor (col 11)
  UNCHANGED. BATTERY/FORMAT
  AMENDMENT (required by this
  ruling): wall-run records
  may declare a per-run dist
  override (center|west|east)
  on top of the level default;
  center = straddle pair
  (battery check as-is);
  west/east = single-tile run,
  battery checks it as a wall
  RUN with orthogonal
  adjacency along the run (no
  isolated 1-tile floaters),
  NOT as a straddle pair. X26
  fence = west offset col 24
  rows 7-11 (as drawn). (F)
  NORTH YARD = BOTH OPEN AREAS
  TOGETHER (west strip + top
  pen, naive cols 14-25 x
  rows 1-5) - one yard in
  Curtiss's reckoning, divided
  internally by the X20 fence;
  the trace encodes the areas
  + the X20 wall, keyed as
  one north-yard area. (G)
  OUTBUILDING DIVISION = BOTH
  routes (user chose 1 and 2):
  module-text adjudication
  PROPOSED + user verifies on
  his 300dpi render. PROPOSAL
  B (barracks equal, alcove
  off 25, 23 south with south
  wall for the shields): floor
  cols 27-30 x rows 2-5 ->
  25 = cols 27-28 x rows 2-3
  (4 tiles NW); 24 = cols
  29-30 x rows 2-3 (4 NE,
  identical to 25 per module);
  23 = cols 28-30 x rows 4-5
  (6 south; south wall = Y6-E
  for the shield line; horn
  table center; ONE door -
  spears by the door); A =
  col 27 x rows 4-5 (2-tile
  alcove SW, opens north into
  25 - "off the barracks";
  3 chests + cot fits 2
  tiles). NOTE: vision said A
  "NW near 25" vs B's SW - his
  300dpi eyeball arbitrates.
  (H) THE PEN-NOTCH QUESTION
  (user asked back: nearest
  number label to the spot):
  the notch (col 25 rows 6-7)
  sits in the Y6 fence one
  tile west of the
  outbuilding's SW corner; the
  nearest printed label is 23
  (roof candidates ~cols
  28-29 rows 3-5, ~3 squares
  NE); 22 is farther (5+
  squares SW). Geometrically
  the notch is open only to
  the east yard (N/W/E all
  wall) - the pen shows NO
  drawn gate anywhere; the
  outbuilding shows no drawn
  door either. User eyeballs
  the 300dpi: pen gate vs 23
  approach vs artifact, and
  where the outbuilding's
  doors actually are (module:
  23 has one door; the
  outbuilding connects to the
  lodge via the huge palisade
  = likely the SE lane/Y14
  opening). RULINGS ROUND 3
  (Curtiss, 2026-11-03): (I)
  23's door ADJUDICATED:
  DOUBLE DOORS LEADING TO 22,
  the open compound - encode
  like the north-gap precedent
  (4 '+' tiles, rows 6-7 x
  2 cols) in the Y6-E wall at
  23's south face; exact cols
  follow 23's extent once the
  outbuilding division is
  settled. (J) HOLDS: the
  outbuilding internal
  division (proposal B stays
  PROPOSAL ONLY, not
  adjudicated) and the pen
  SE-notch - Curtiss is
  TAKING A DIFFERENT APPROACH
  TO IDENTIFYING ALL THE
  GEOMETRY (approach to be
  described by him; do not
  push the per-region ruling
  questions again until he
  states it). REMAINING
  PENDING: Y14 opening
  k26.3-27.7 nature; 18A
  stairs tiles; (The
  north-gap double doors
  remain ADJUDICATED: 4 '+'
  tiles rows 0-1 cols
  15-16.) THE PASS STATE:
  north strip + kitchen wing
  + eastern section mapped
  and mostly adjudicated;
  awaiting Curtiss's new
  geometry-identification
  approach before further
  region rulings. RULING
  ROUND 4 (Curtiss, 2026-11-03)
  - THE SEQUENTIAL LOCATION
  WALK IS THE APPROACH: (K)
  first agree the map frame,
  then walk each location
  sequentially (he
  adjudicates each); (L) MAP
  FRAME RATIFIED: square
  numbering takes the NW
  corner square as (1,1) (he
  prefers the CRPG SW-corner
  convention but OK'd NW for
  storage ease - the grid
  block stores rows top-down,
  NW-anchored; if the engine
  wants SW-origin world
  coords it is a LOADER
  TRANSFORM (flip rows), never
  a re-trace); numbering =
  cols 1-31 east from the
  west edge, rows 1-40 south
  from the north edge; ring
  tiles (row 0/41, col 0/32)
  sit OUTSIDE the numbering;
  tile canvas 33x42; the
  NUMBERING IS THE LATTICE
  (square n,m = cell between
  its lines regardless of
  which tile consumes its
  halves - walls are content,
  squares are the frame).
  (M) WALK ORDER = MODULE KEY
  ORDER: 1, 2, 3... 25, then
  10A, 18A, A, B; each entry
  = pixel facts + module text
  + proposed encoding, he
  rules. PASS STATE AT WALK
  START: north strip +
  kitchen wing + eastern
  section already mapped
  (regions covered by keys
  17-25/A will re-walk for
  confirmation and door
  placement, starting from
  the seated rects).
  (4) REGION MAP: north
  strip (Y k 0-10) = the 18-25
  wing (18,19,20,22 and outbldg
  23-25 left-to-right per vision);
  main lodge block (Y k 11-34);
  south yard strip (Y k 34-40,
  six squares deep between the
  lodge's south face and the
  stockade); the NW blank corner
  (X k 2-5, Y k 0-10) = hillside
  OUTSIDE the stockade -> trace
  terrain ink ('y'), NOT void
  (the battery forbids void
  inside the square extent;
  exterior blank ink is yard-
  class per the outside-is-yard
  adjudication). (5) WALL LINES:
  the lodge south face = Y k=34
  (y 688-696, full width) with
  TWO gate-sized openings near
  canvas cols 9-10 and 20-21 (the
  main entrance); the stockade
  south wall = the Y k=40 bar
  spanning only x 184-447 (cols
  ~9-22) - the stockade is an
  IRREGULAR enclosure, not a
  full bounding-box rectangle;
  east stockade opening at Y
  k~11.3-13.5. PIXEL-WORK
  TOOLING NOTES: naive dark-
  threshold and run-length
  skeletonizers both drown in
  the drawing's timber texture
  (long plank strokes read as
  walls); the working
  discriminator is perpendicular
  INK THICKNESS (median >=2.5px
  over >=50% of the lattice
  segment) - stockade 5-9px,
  lodge walls ~3-4px, plank
  texture 1-2px; a draft
  thickness-based skeleton
  exists; the final trace =
  draft + room-by-room vision
  crops against the pixel
  frame. NEXT PASSES: rooms
  (great hall, chief's wing,
  kitchen wing), doors/points,
  yard/road, then site.json +
  battery. LANDED 2026-11-02:
  commit 1882756f - extract/g1/
  p002-02.png
  (upper, 300dpi) + extract/g1/
  p012-12.png (dungeon, 300dpi);
  note pdftoppm's actual filenames
  carry the page suffix (p002-02,
  p012-12). COMMIT MAP UPDATE:
  879b4734 -> 75821d85 -> 9356e96f
  -> b6915511 -> 1882756f. THE
  EXTRACTION ROUND IS COMPLETE; the
  skeleton pass is next, and it
  runs against the uploaded 300dpi
  p002-02.png raster.
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

## Current state (post-R848)

(SUPERSEDED - historical R848-era snapshot; later "Current
state" blocks and the dated tail entries through R1033,
2026-11-13, are the authority.)

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
  (Sanity note, seated 2026-11-13: the file is ~739KB, far
  past the threshold - the v4 fresh start is overdue and
  awaits Curtiss's call; until then, lands append to the
  tail sections.)

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

  - R943 LANDED (21c9900, t21, 64 inline, opener part one of the issue-21
  three-round shape): The Dragon issue-21 opener part one, three chains IN
  (Encounters with Personality, Sensible Sorcery, Prophet Proofing). The
  twenty-NPC personality grid rides as the t21Npcs table (tag 'Np', 20 rows x
  11 cols: level, hp, AC, the six stats, to-hit, to-damage; Blarg through
  Dassol pinned from print 11 + 23 + 27, the Ave. bonus lines pinned 0 with
  the conversion noted), the Rollo 9/24/9 prose statline with its
  seven-number print catch (t21NpcRolloStatlineSeven=7, one more than the
  six-stat grid). Sensible Sorcery (Pehr, print 10): the three Rules of
  Research, the Moon Runes / Magic Missile II / Wall of Water family /
  Shatterray vs. Ice Storm level-and-damage critiques, the specialist
  Fire-Mage exception, the cleric-no-attack and MU-no-divine dividing lines,
  the Suliin spelling print catch ('Paul Suliin', 'Ventriliquism'). Prophet
  Proofing (Schroeder, print 9): the five foretelling spells, the Medivar
  and harpy deterrents (Medivar spelling print catch), the 2-7-turn insanity
  contagion, the 60-foot non-directional option, three inches of lead, the
  33 percent voyeur Eye, the fifteen-dice Kobold fireball Helm trick, the
  medallion blue-movies bool. 64 inline (30 consts + 23 bools + 11 col
  accessors), header rules/t21.h (prefix t21 verified free at ee361d0
  full-repo scan), audit rules/audits/r943_batch.h R943 issue-21 opener part
  one audit, 10 examples + 1 table check. Numbering print catches pinned as
  scanned, conversion noted: the masthead prints Vol. 111 for III, November
  for December, No. 6 for 7 (RPGGeek-confirmed contents-page error, the cover
  also prints No. 6). Data files: report 021 + 30 transcripts at
  extract/dragon/021 (TD-21 intake: 30 PDF pages, PRINT FOLIO = PDF MINUS
  2). Census 865->866; rverify GREEN 273 mutants 0 missed; round-trip 203910
  bytes md5 b7a5ac553522610964288a890719ecfa, byte-exact at 21c9900 (fresh
  tarball re-run applied 0 already 36; landed spec plus the user-save
  trailing newline 203911 bytes md5 c2f6d80dc5fbf50b7054a270f5bb145c).
  WATCHES STILL EMPTY: the Sullin levels 7-9 and the brawling sequel print
  nowhere in TD21 either - both ride to TD 22. Next: R944 opener part two
  (Inflation in D&D, Same-Old-Monster Blues, Hall of Mystery, What Do You
  Call a 25th Level M-U), R945 the pure flip closing both report-021 boxes.
  WAIT FOR GO.

  - R944 LANDED (631da4d, g21, 66 inline, opener part two of the issue-21
  three-round shape): The Dragon issue-21 opener part two, four chains IN
  (Inflation in D&D, Cure for the Same-Old-Monster Blues, The Hall of
  Mystery, What Do You Call a 25th Level M-U). The inflation economics of
  Willie Callison (print 9, PDF 11): the 1:1 gold-piece-dollar analogy with
  the 5-or-10 richer alternate, the 1-10-gp starting purse, the Strategic
  Review Vol. II No. 2 Gygax reference, the 1st-level purple dragon with its
  plus-5 sword and two plus-5 spears, the spend-for-XP critique, the
  silver-copper revival and the SMALL IS BEAUTIFUL close. The natural-history
  monster doctrine of Wm. Callison (print 8, PDF 10): the never-both snakes,
  the cold-blooded limit, the deaf-vibration senses, the coil initiative,
  the live-prey spider webs, the trap-door surprise, the solitary scorpions,
  the social ants, the AC 2-3 centipede correction and the Mother Nature
  source. The Hall of Mystery do-it-yourself module of Don Turnbull (print
  14-15, PDF 16-17): the five 10-foot mirrors (a the Opposition, c the 6-foot
  life trap holding the Succubus, b d e ordinary), the 45-foot ceiling, the
  5-foot cylinder, the nine-position Excalibur dial, Excalibur spoken three
  times, the three-person teleport limit with the clockwise displacement,
  the two Umber Hulks, the Magic Absorbers from Alarums and Excursions 12,
  and the eight-room monster census riding as the g21HallRooms table (tag
  Hm, 8 rows x 3 cols - the room iii Otyugl at its printed 7 hit dice, the
  unprinted rooms pinned 0 with the conversion noted). The Blume M-U titles
  kit (print 7, PDF 9): the ten-column chart against the seven-column prose
  walk (print catch), the 20th-level Rogor example and the delete-embellish
  doctrine. 66 inline (31 consts + 32 bools + 3 col switches), header
  rules/g21.h (prefix g21 verified free at 21c9900 full-repo scan), audit
  rules/audits/r944_batch.h R944 issue-21 opener part two audit, 12
  examples + 1 table check. Print catches pinned as scanned: the question
  header prints WIZARD for the M-U contents line; the kit spellings print
  Magnificance, Irrestible, Reknown, Belligerant, Contretious and Sourge;
  the inflation prints D-and-D mixed case and drops its letters twice (the
  wont, the can); the monster blues prints the envision and ol-Gandalf; the
  census prints Otyugl; the verse prints Ann-for-And and apiece for a
  piece. No data files this round (the 31 issue-21 intake files rode R943);
  gap report 021 no-oped at 2 open, both boxes awaiting the R945 flip.
  Census 866->867; rverify GREEN 87 mutants 0 missed; round-trip 31489
  bytes md5 1165a447b190cf9ef78362bd6dcf3e1c, byte-exact at 631da4d (fresh
  tarball re-run applied 0 already 5; the builder wrote the trailing newline
  itself, so the landed spec is byte-identical to the canvas body at the
  same 31489 bytes, no user-save +1 this round). WATCHES STILL EMPTY: the
  Sullin levels 7-9 and the brawling sequel print nowhere - both ride to
  TD 22. Next: R945 the pure flip closing both report-021 boxes, issues
  2-21 all closed at the flip. WAIT FOR GO.

  - R945 LANDED (b6a476c, d21, 35 inline, pure flip, no new ink): The Dragon
  issue-21 box closing round, the seven-chain walk complete. BOTH report-021
  boxes flipped in ONE round (gap_census 2 closed 0 open): the issue-21
  opener chains part one (the R943 twenty-NPC personality grid, the
  spell-research doctrine, the foretelling-spell counters) and part two (the
  R944 gold-piece inflation doctrine, the natural-history monster doctrine,
  the Hall of Mystery, the M-U titles kit). ISSUES 2-21 ALL CLOSED - the
  fifth three-round issue shape. 35 inline bookkeeping only (20 consts + 15
  bools mirroring the R942 d2c closer: d21IssueTwentyOneBoxes=2, chains=7,
  rounds=3; issue-closed consts 7 through 20, issue 20 marked closed since
  the R942 d2c flip; registry 1313/1338/25 unchanged; walk-complete bools 7
  through 21), no tables, no data files; header rules/d21.h (prefix d21
  verified free at 631da4d full-repo scan), audit rules/audits/r945_batch.h
  R945 Dragon issue-21 closure audit, 3 examples. No new print catches at
  the flip - all issue-21 quirks rode the two opener records. Registry
  ground truth unchanged: 1313 loaded / 1338 base lua / 25 never-load (R924
  re-measure). Census 867->868; rverify GREEN 35 mutants 0 missed;
  round-trip 15115 bytes md5 f4e30db03f44cc4b89b29d4a7d1af446, byte-exact at
  b6a476c (fresh tarball re-run applied 0 already 7; the builder wrote the
  trailing newline itself, so the landed spec is byte-identical to the
  canvas body at the same 15115 bytes, no user-save +1, as at R944).
  WATCHES STILL EMPTY: the Sullin levels 7-9 and the brawling sequel print
  nowhere through issue 21 - both ride to TD 22. Next: the Dragon Magazine
  walk continues with Curtiss call - the next scan upload (issue 22 or
  another issue) opens the next issue round the same intake. WAIT FOR GO.

  - R946 LANDED (7cfc392, t22, 93 inline, opener part one): The Dragon
  issue-22 opener part one, the military-history triptych - three of the
  nine chains of Curtiss's TD-22 call in the approved four-round three-box
  shape. Combined TD22+LW13 experiment issue (no January 1979 issue, Kask
  surgery editorial); PRINT FOLIO = PDF PAGE this issue (verified at feet
  3-12, 15-42, 44-54). Chain one the First Assassins print 5-7 (23 consts
  + 8 bools: the Alamut rock and its bloodless 3000-dinar takeover, the
  Hasan timeline Ray 1050 to the 1124 succession, the fildai seven levels
  recruited at 12, the Guide to Famous Assassinations 1127-1192, Hattin
  WITH Saladin, sixty thousand followers, three million Aga Khans). Chain
  two the Irresistible Force print 8-11 (33 consts + 12 bools + TABLE
  t22SwissComp tag Sc six troop types, halberd 20-60 through cavalry 0-5,
  sentinel -99: Morgarten through the dozen battles 1386-1499, the
  echelon, the Kiel wedge, the dismounted lances, the Grandson-Morat-Nancy
  crush, the 600-man hedgehog, the Chainmail rec). Chain three Armies of
  the Renaissance Part I print 12 (8 consts + 7 bools: the 1453-1703
  span, the 12-21-foot pike, Franklin longbow, Hussite laager, the
  stardio, the Swiss-next-time preview). 93 inline (64 consts + 27 bools
  + 2 table cols), 14 examples + 1 table_check, 57 data files (report
  022 + 56 transcripts at extract/dragon/022); gap report 021 no-op 2
  closed 0 open; report 022 seats THREE boxes for the R947/R948 opener
  parts and the R949 pure flip. Print catches pinned as scanned: contents
  Brunner vs byline Bruner; titantic; seige; duplicated
  acknowledge-the-Sultan phrase; Vol.. double period; foreward twice;
  Giarnico vs Giornico; Courtai vs Courtrai; Perrer for Perren; St Jacob
  table 30000 vs text 15000 both pinned; Ziska for Zizka; stardio for
  stradiot. WATCHES STILL EMPTY: the Sullin levels 7-9 and the brawling
  sequel print nowhere in TD22 - both ride to TD 23; the sneak preview
  prints Freet Giant Jari for the G2 Frost Giant Jarl - rides at R947.
  Census 868->869; rverify GREEN 103 mutants 0 missed; round-trip 334859
  bytes md5 9203a2df5aa831f1ba62f711cca04313, byte-exact at 7cfc392
  (fresh tarball re-run applied 0 already 62; the builder wrote the
  trailing newline itself, so the landed spec is byte-identical to the
  canvas body at the same 334859 bytes, no user-save +1, as at
  R944/R945). Next: R947 the AD&D Sneak Preview of the DMG, the
  single-chain table round (print 33-38 + 41-43: the Amulet of the
  Planes 1-24 d% table, the Ring of Elemental Command, the attack matrix
  I.D.1, the psionic IV.B-IV.D, three saving-throw matrices,
  grenade-like missiles). WAIT FOR GO.

  - R947 LANDED (8c3b563, s22, 320 inline, opener part two): The Dragon
  issue-22 opener part two, the AD&D Sneak Preview of the Dungeon Masters
  Guide - the single-chain table round, print 33-38 + 41-43 (PRINT FOLIO
  = PDF PAGE). Twelve tables: s22Amulet tag Am 17x3 the amulet of the
  planes 1-24 d%, s22Periapt Pp 4x3, s22HitOnly Mw 4x4 the plus grades,
  s22Thieves Id 21x7 the I.D.1 matrix, s22ElemScroll Es 5x3 the elemental
  scrolls, s22LycanScroll Ly 7x3 the lycanthrope scrolls, s22PsiCrush Pc
  6x8 the IV.B attack strengths, s22PsiBlast Np 11x4 the IV.C psionic
  blast, s22PsiRange Rg 5x3 the IV.D attack modes, s22UndeadTurn Cu 13x10
  the turning undead matrix, s22CharSave Sv 28x7 save matrix I, s22ItemSave
  Is 14x11 save matrix III. 320 inline = 204 consts + 50 bools + 66 table
  cols, 19 examples + 12 table_checks; gap report 022 no-op 0 closed 3
  open; no data files (part-two round). Conversions noted never silent:
  T/D/D*/dash 97/98/99/0 at the turning matrix, the IV.B crush dashes as
  0. Print catches pinned as scanned: Freet Giant Jari for the G2 Frost
  Giant Jarl; con penetrate; jackolwere; wralths; Ghost printed twice
  for Ghast; Petrifaction; the farce/an die footnote; the missing I.D
  footnote e; the I.B AC-3 row prints 11 and dropped the AC-10 cell;
  five I.C bands over four columns plus the dangling Opponent; the
  overlapping IV.B band 210-269; the parchment fireball save 25. WATCHES
  STILL EMPTY: the Sullin levels 7-9 and the brawling sequel print
  nowhere in TD22 - both ride to TD 23. Census 869->870; rverify GREEN
  1103 mutants 0 missed; round-trip 106753 bytes md5
  45481cf6b930b7a236fd43085822284b, byte-exact at 8c3b563 (fresh
  tarball re-run applied 0 already 5). ENGINE GAP CAUGHT IN PREFLIGHT:
  table count const existence is not Python-gated - s22ElemScrollCount
  and s22LycanScrollCount were referenced by the audit loops but
  undefined in the first spec, and only the C++ compile caught it; the
  fix added both consts (inline 318->320), and the builder now asserts
  every table count resolves to a const so the class is closed.
  RECOVERY LESSON: after an aborted round, rm of the two new files alone
  leaves the tracked patched files stale - the R420 mixed applied/already
  abort fires; restore the tracked files to HEAD as well. Next: R948
  issue-22 opener part three, five chains - What It Is and Where It Is
  Going print 29-30, Nomenclature of Pole Arms print 50-54, SPI on AD&D
  print 44, Stalemate at Kassala print 45-47, Mapping the Dungeons
  catalog print 18-28. WAIT FOR GO.

  - R948 LANDED (446f677, k22, 151 inline, opener part three): The Dragon
  issue-22 opener part three, the commentary set - the five-chain round of
  the four-round shape. Chain one What It Is and Where It Is Going print
  29-30 (12 consts + 13 bools: the 150000-player estimate, the eleven-month
  first thousand, the five-or-six-month second thousand, the 2000-set third
  printing in five months, the 4000 sets through December 1975, the 20-50
  percent piracy estimates, the 4000 Basic Sets a month, the Poetics
  analogy, the everybody-wins doctrine, the two-systems split, the
  home-computer direction). Chain two the Nomenclature of Pole Arms print
  50-54 (28 consts + 24 bools + TABLE k22PoleArmFam tag Pf 7x2 the seven
  families by member count - dagger 6, axe 3, cleaver 2, scythe 1, heavy
  knife 1, pruning hook 2, hay fork 1, sentinel -99: the five-foot haft
  floor, the 18-21-foot pike, the 15-foot pike line, the 12-foot Norman
  lance at the 14-foot average with 10 feet of reach, the 8-foot halberd,
  the 2-to-over-3-foot bardiche head, the Sempach 1386 and Arbedo 1422
  references, the Saxtorph and Stone misnamings, the recanted lochaber,
  the 40-40-20 Swiss mix, the not-grounded Swiss pike). Chain three SPI on
  AD&D print 44 (9 bools: the Berg does-not-play handicap, the mere-rewrite
  charge, the pigs-lips quote, the uniformly favorable reaction, the ivory
  chessmen analogy, the rehash masters, the besooted pot and silver
  salver, the Tolkien coattails, the ball back in your court). Chain four
  Stalemate at Kassala print 45-47 (25 consts + 15 bools: the 1541
  expedition, the 400 Portuguese with 1000 stand of firearms, the 2600
  enemies to the front, the Christian order - 400 Galla plus two 400-strong
  cohorts plus the 160 cavalry reserve, the Moslem order - 1000 Nubians,
  600 Mamalukes, 200 Turkish heavy, 400 Arabs, the 200-strong center
  units, the Iago wing 100 garrison + 120 armed slaves + 300 about-face,
  the 1400-to-520 flank fight, the 200 twelve-eighth-ounce musket balls
  against the printed fifteen pounds, the three volleys, the Khartoum
  rainy-season withdrawal, the editor town-was-the-target verdict). Chain
  five the Mapping the Dungeons catalog print 18-28 (11 consts + 12
  bools: the 500-plus roster, the 18 December 1978 cut-off, the 3-4-month
  update cycle, the 2.10-dollar back issues - 7 Volume Two and 5 Volume
  Three in stock, the 21-game catalog, the nine Hobbitronics, the five
  named dungeons, the Space Quest unknown publisher, the Listerine
  Brothers, Arrh the Insane). 151 inline = 77 consts + 72 bools + 2 table
  cols, 21 examples + 2 table_checks; gap report 022 no-op 0 closed 3
  open; no data files (part-three round). Print catches pinned as scanned:
  the missing Partisan section heading at print 51; Scotts for Scots;
  ransour for ranseur; BRITAINNACA in the text against BRITIANNICA in the
  bibliography against Britannica; Ffoukles in the bibliography against
  Ffoulks in the text; predominate for predominant; the ef-fect folio-seam
  hyphen; route of retreat for rout; be surprise for by surprise; tatoo
  faced; Bhagdad; geni for genie; handfull and handfulls twice; Sundanese
  for Sudanese; the fifteen-pounds print against the 18.75-pound
  arithmetic of 200 one-and-a-half-ounce balls, both pinned; the 5000 or
  6000 sets was and the myth of all peoples contain agreements; the
  stray apostrophe in the print-30 cartoon; the roster blanket
  misspelling apology, directory spellings riding unpinned. WATCHES STILL
  EMPTY: the Sullin levels 7-9 and the brawling sequel print nowhere in
  TD22 - both ride to TD 23. Census 870->871; rverify GREEN 163 mutants 0
  missed at base 8c3b563; round-trip 53328 bytes md5
  4d2e8f5f9fe90d0167e9a6e73ad783a3, byte-exact at 446f677 (fresh tarball
  re-run applied 0 already 5). Next: R949 the pure flip closing all three
  report-022 boxes - the gap_flips on the three part lines to checked, the
  gap_census 3 closed 0 open, prefix scan fresh at the then-HEAD (l22
  free at 446f677, k22 now taken). WAIT FOR GO.

  - R949 LANDED (76a37e2, l22, 29 inline, the pure flip): The Dragon
  issue-22 box closing round - no new ink, all three report-022 boxes
  flipped at the single round: the part-one military-history triptych,
  the part-two AD&D DMG sneak preview and the part-three commentary set
  all checked, gap_census 3 closed 0 open. 29 inline = 18 consts + 11
  bools, 6 examples, no tables; the bookkeeping pins the shape itself -
  3 boxes, 9 chains, 4 rounds (the walk's first four-round shape), the
  opener inline totals 93 + 320 + 151 = 564, the walk census issues 2-22
  all closed (twenty-one issues), the unchanged registry ground truth
  1313/1338/25, the combined TD22-plus-LW-13 experiment frame, and the
  two watches riding to TD 23 (the Sullin levels 7-9, the brawling
  sequel). Census 871->872; rverify GREEN 29 mutants 0 missed at base
  446f677; round-trip 17405 bytes md5
  d4186dd32bd5d4a97e1be64d5d39f47b, byte-exact at 76a37e2 (fresh
  tarball re-run applied 0 already 8; the flip round's eight patches
  carry the gap report in the git add). THE ISSUE-22 FOUR-ROUND SHAPE
  IS COMPLETE: R946 t22 7cfc392, R947 s22 8c3b563, R948 k22 446f677,
  R949 l22 76a37e2. Next: TD 23 - the fresh intake (transcripts,
  folio-vs-page check, chain call, drop list, then the round plan);
  the Sullin levels 7-9 and the brawling long-term-effects watches
  come due there. WAIT FOR GO.

  - R950 LANDED (df703c4, t23, 82 inline, opener part one): The
  Dragon issue-23 opener part one, the variant triptych - three of
  the ten chains: the En Garde solitaire dueling method (print 5-6,
  the Laking shorthand - the CE formula, the defense modifier, the
  fifty-percent base, the eleven-band critical hits grid with its
  die-size print errors), the Mind Wrestling psionic track (print
  10, the Swycaffer seventeen-space double track), and the
  Starship Warden water monsters (print 11+13, the Hursh variant,
  twenty creatures, ten columns). 82 inline = 50 consts + 22 bools
  + 10 table cols, 14 examples, 7 table_checks, 2 tables
  (t23CritHits 11 rows x 4, t23Warden 20 rows x 6); the intake
  seats the report-023 gap report plus all thirty-two transcripts
  (33 data files). Census 872->873; rverify GREEN 236 mutants 0
  missed at base 76a37e2; round-trip 188567 bytes md5
  789cd28fcf6d563fc538e1de5ed17c5a, byte-exact at df703c4 (fresh
  tarball re-run applied 0 already 38). NEW INTAKE-SHAPE LESSON:
  an intake round's gap_report must point at the PREVIOUS issue's
  landed report (022, 3 closed 0 open) while the new report and
  transcripts ride as data_files - the engine reads the report
  before applying patches, so pointing at the new report on a
  fresh tree aborts as the mixed applied/already state (the R420
  lesson in a new coat; R946 already held this shape). Print
  catches pinned as scanned: Sorceror's for Sorcerer's Scroll in
  the contents, Good News listed at 18 but printing at 6, the
  Convention Schedule listed at 21 but printing at 18, Geoffrey
  vs George Laking bylines, Jaques for Jacques twice then
  Jacques, the letter O for a zero defense modifier, 16-sided and
  120-sided die rolls proven 6/20 by the worked example (Karl
  base 20 plus 6 for 26), ration for ratio, the Warden table's
  duplicated Description column, Sybiotic for Symbiotic,
  unfootnoted asterisks, Green Death 3-vs-4 melee turns, stre of
  13 truncated, its-for-it's. Part-two scan already pinned
  (print 15-18, the Lower Planes table round): forth coming as two
  words, quadrapedal etal, the eyes formula 1 + 1, the mouth line
  skipping 4, the strength table overlap at 45, Df. for cf.
  Watches: the Sullin levels 7-9 and the brawling sequel still
  empty in TD 23 - both ride to TD 24. Next: R951 part two, the
  Random Generation of Creatures from the Lower Planes table
  round; prefix scan fresh at the then-HEAD (s23 next). WAIT FOR
  GO.

  - R951 LANDED (af5a151, s23, 178 inline, opener part two): The
  Dragon issue-23 opener part two - the Lower Planes table round,
  the single chain of the Sorceror Scroll DMG preview (print
  15-18): the Random Generation of Creatures from the Lower Planes
  system, Gary Gygax on the Abyss, Tarterus, Hades, Gehenna and
  Hell. The base stat block (frequency through psionic modes), all
  twenty-three appearance and generation grids (head through bird
  feet, the move speeds, the magic-resistance variance, the
  optional-poison saves), the nine-band strength-to-hit-damage
  table with its exceptional-strength subrolls, the attack forms,
  the special attacks and defenses with their limits, the
  other-abilities trio. 178 inline = 126 consts + 23 bools +
  29 table cols, 16 examples, 23 table_checks (one spot check per
  grid); no data files - the intake rode R950. Census 873->874;
  rverify GREEN 354 mutants 0 missed at base df703c4; round-trip
  68256 bytes md5 f829fd656c9cceaff1be6a88897f874a, byte-exact at
  af5a151 (fresh tarball re-run applied 0 already 5). Print
  catches pinned as scanned: forth coming as two words in the DMG
  preview sentence, quadrapedal etal on the body attributes line,
  the eyes count formula printed 1 + 1, the mouth size line
  skipping the 4 (1 tiny, 2-3 average, 5-6 huge), the strength
  bands overlapping at 45, Df. for cf. in the Demonology citation,
  the bird-like head asterisk footnoted two pages later with the
  six bird-like feet, Predominate Color for predominant, the bare
  etc. on the defense mode line (1-2 F, 3-4 F and G); the negative
  pin - Tarterus is the AD&D canon spelling, not a catch. Also
  pinned: the EXXEDUUNUSSE vacation sign-off gag at the feet of
  the general characteristics, the thrice circumstances-must-
  dictate. Watches: the Sullin levels 7-9 and the brawling sequel
  still empty in TD 23 - both ride to TD 24. Next: R952 part
  three, the six-chain commentary set (Good News print 6, It Weighs
  print 14, Damage Permanency print 19-20, Dungeons and Prisons
  print 21, the Kask Origins critique print 4+21, the Gardner Fox
  Niall fiction print 8-9+22-30); prefix scan fresh at the
  then-HEAD (k23 next). WAIT FOR GO.

  - R952 LANDED (004afd2, k23, 145 inline, opener part three): The
  Dragon issue-23 opener part three, the six-chain commentary set:
  the gaming-hobby trade-show report (print 6 - the forty-second
  show, the sixteen-house exhibitor roster), the armor-weights
  polemic (print 14 - the Nickel and Blair quotes, the five
  surviving armors, the Oakeshott sword weights), the permanent-
  damage charts (print 19-20 - the Ward percentile bands, the six
  damaged body areas, the impairments through the weapons
  subtable), the dungeon-as-prison formula (print 21 - the Elrohir
  cell, two hundred feet behind five true-lead layers and twenty
  tons of granite), the Origins scheduling critique (print 4+21 -
  the Kask July-gap verdict on AH and SPI) and the Niall
  sword-and-sorcery tale (print 8-9+22-30 - Gardner Fox, Niall
  against the witchwoman Sosaria Thota, Messarib, Alphanor,
  Xinthius, Abaddon and the amanatlon device). 145 inline =
  78 consts + 64 bools + 3 table cols, 19 examples, 1 table
  check, 1 table (the damaged-body-area grid), six sections; no
  data files. Census 874->875; rverify GREEN 160 mutants 0
  missed at base af5a151; round-trip 47506 bytes md5
  0f49c205e5ce5939c45d27dd68edc926, byte-exact at 004afd2 (fresh
  tarball re-run applied 0 already 5). Print catches pinned as
  scanned: the contents Good News at 18 vs print 6 with the
  byline GOOD NEWS FOR GAMING; Augsberg for Augsburg, the
  contents WHAT exclamation-question vs the byline WHAT?!!,
  Fredrick for Frederick and the mid-sentence capital Quote Claude
  Blair; the arm bands overlapping at 25, reduced to from ten to
  two, the legs band 75-79 only five wide, the unfooted asterisks;
  the Kask you now who you are and I know find myself; the fiction
  Bakakanian vs Baklakanian desert, Lurlyr vs Luryr Manakor, the
  grey vs green eyes of Sosaria Thota, swordhill, brawney,
  croached twice, serants for servants, Lythia for Lylthia, shock
  for shook, the amanatlon device, and the Orravian vs Orra-vian
  dagger hyphen. Watches: the Sullin levels 7-9 and the brawling
  sequel still empty in TD 23 - both ride to TD 24. Next: R953 the
  l23 pure flip - all three report-023 boxes check at the single
  round, gap_flips on the three part lines, gap_census 3 closed 0
  open, prefix scan fresh at the then-HEAD. WAIT FOR GO.

  - R953 LANDED (f8d76c8, l23, 29 inline, the pure flip): The
  Dragon issue-23 box closing round - no new ink, all three
  report-023 boxes flipped at the single round: the part-one
  variant triptych (R950, t23), the part-two Lower Planes
  generator (R951, s23) and the part-three commentary set
  (R952, k23) all checked, gap_census 3 closed 0 open. 29
  inline = 17 consts + 12 bools, 6 examples, no tables - the
  exact R949 symmetry; the bookkeeping pins the shape itself -
  3 boxes, 10 chains, 4 rounds (the second four-round shape),
  the opener inline totals 82 + 178 + 145 = 405, the walk
  census issues 2-23 all closed (twenty-two issues), the
  numbering agreement (Vol. III No. 9, March 1979, number 23),
  the folio-equals-PDF-page check, the single-voice transcript
  pin (no archive.org djvu cross-check exists for issue 23),
  the unchanged registry ground truth 1313/1338/25, and the
  two watches riding to TD 24 (the Sullin levels 7-9, the
  brawling sequel). Census 875->876; rverify GREEN 29
  mutants 0 missed at base 004afd2; round-trip 15511 bytes
  md5 f73d8a390db3f292c8a1759b7d5300c5, byte-exact at
  f8d76c8 (fresh tarball re-run applied 0 already 8; the
  flip round's eight patches carry the gap report in the
  git add). THE ISSUE-23 FOUR-ROUND SHAPE IS COMPLETE: R950
  t23 df703c4, R951 s23 af5a151, R952 k23 004afd2, R953 l23
  f8d76c8. Next: TD 24 - the fresh intake (transcripts, the
  folio-vs-page check, the chain call, the drop list, then
  the round plan); the Sullin levels 7-9 and the brawling
  long-term-effects watches come due there. WAIT FOR GO.

  - R954 LANDED (3a5152d, t24, 134 inline, opener part one): The
  Dragon issue-24 opener part one, the variant triptych - three of
  the fourteen chains: the lost civilizations Source of the Nile
  variant (print 5-6, the Holmes supplement - the marker system,
  the explorers attitude numbers, the gods attitudes, the natives
  reaction rolls), the Chinese dragons variant roster (print 8-9,
  the five Lung variants with the sentinel -99 for the flightless
  Lung Wang and Yu rows, the flight organ, the color omens), and
  the lycanthropy infection variant (print 10-11, the infection
  bands, the alignment table, the attribute deltas with the
  printed duplicate Boar row kept and the conversion noted).
  134 inline = 70 consts + 45 bools + 19 table cols, 17
  examples, 8 table_checks, 4 tables (t24DragonTypes 6 rows x 8,
  t24LycanBands 7 x 2, t24LycanAlign 9 x 3, t24LycanAttrs 5 x 6);
  the intake seats the report-024 gap report plus all
  forty-eight transcripts (49 data files, the transcripts at
  extract/dragon/024). Census 876->877; rverify GREEN 234
  mutants 0 missed at base f8d76c8; round-trip 334482 bytes md5
  3684bca9df7ea0cb708a877d0acbc8dc, byte-exact at 3a5152d
  (fresh tarball re-run applied 0 already 54). TWO LESSONS
  PINNED: the opener's gap_census must mirror the PREVIOUS
  landed report's state ({closed:3, open:0}), not the new
  report's all-open shape - the engine reads the report before
  patching and aborts "the gap closed count is 3, want 0"
  otherwise; and the prev_seed_key must be prev_record[0]
  verbatim - the R953 record line WRAPS at ": The", so a
  handoff key carrying ": The Dragon" never matches and breaks
  the double-run with the mixed applied/already abort. Print
  catches pinned as scanned: Ross Maker credited then "maker"
  lowercase at the second reference, the comma-spliced "equal
  to or less than, the explorers attitude number" with its
  missing apostrophe, deal of magic for duel, the page ending
  "wild animals" without its period, unextractable for the
  Shen Lung flight organ, the dangling "look favorably upon
  any mortal giving them", hearts desire without its apostrophe
  (Yu Lung), Gods Demi-Gods and Heroes at p. 63 vs the intro's
  p. 68, the duplicate Boar attribute row reading the bear line,
  the blank rat row in the speed table, lowercase wolves, Bears
  in the third and fifth saving-throw rows (the fifth reading
  the boar line), "a wolfs constitution", "type Glycanthropes"
  run together, the twice-cited Determination of Attributes
  and Abilities vs the printed Determination of Abilities and
  Attributes (inverted). Watches: the Sullin levels 7-9 and the
  brawling sequel still empty in TD 24 - both ride to TD 25; the
  letters column (Out on a Limb) debuts at print 21+31 and rides
  the drop list as reader mail. Next: R955 part two, the Schick
  Ramifications of Alignment pantheon table round (print 34-39);
  the gap_report stays report-023 (3 closed 0 open), the data
  files unchanged in kind; prefix scan fresh at the then-HEAD
  (s24 next). WAIT FOR GO.

  - R955 LANDED (d9edf2b, s24, 146 inline, opener part two): The
  Dragon issue-24 opener part two, the alignment pantheon table round -
  the single chain of the Schick Design Forum alignment variant
  (print 34+36-39, print 35 the B1 module advertisement): the
  eighteen prime alignments at six per axis, the twenty-one prime
  deities (seventeen singles plus the four elemental lords at two
  hundred hit points), the five sons of Thakta Tylden and the
  Headsman of Marly. 146 inline = 73 consts + 59 bools + 14 table
  cols, 14 examples, 6 table_checks, 3 tables (s24Pantheon 21 rows
  x 6 with the sentinel census - the Morilirom irrelevant armor
  class, the two instantaneous moves, twenty second-move sentinels
  and ten damage-pair sentinels; s24Sons 5 x 5 - only the Pakunth
  and Dakunth resistances and the Rakunth three attacks print;
  s24Aligns 18 x 3 - the axis, the slot and the deity
  cross-reference, Battle Glory to the Hisk row, the Four Elements
  to the Gungger row). The mid-round shape rides no new data files;
  the gap report stays report-023 (3 closed 0 open), the
  report-024 boxes unchecked until the R957 flip. Census 877->878;
  rverify GREEN 337 mutants 0 missed at base 3a5152d; round-trip
  54759 bytes md5 2aa4b41c678f538f5a2f29ceaf6ff5b8, byte-exact at
  d9edf2b (fresh tarball re-run applied 0 already 5). Print
  catches pinned as scanned: MORILIROM spelled Moriliroom twice in
  running text, the Whickerwind pegasus, the feet-vs-inch move
  drift (Hisk, Bleskuta, Temanamat, Golod, Sog-Morthoth and
  Thakta Tylden in feet), richly-apparelated, werebbar twice,
  psuedopods, civilization-topping, the THOLTANOOMA header against
  Tholtanooma text, the Manturin fifteen-dice lightning and
  eight-pointed ten-dice stars, the Sedjima one-and-a-half-percent
  Augury pinned as three half-percent units with the two-percent
  Contact Other Plane, the fourteen-spell standard god list, the
  gods hit unless a one on d20, the Marly ten-five-one reward
  ladder, the Headsman minus-two one-fifty total-resistance
  plus-five vorpal, the Cyrullia five-percent seventh-level
  miracle, and the full son roster with the Dakunth printing on
  page thirty-nine. Watches: the Sullin levels 7-9 and the
  brawling sequel still empty in TD 24 - both ride to TD 25.
  Next: R956 part three, the ten-chain commentary set; the gap
  report stays report-023 (3 closed 0 open); prefix scan fresh at
  the then-HEAD (k24 next). WAIT FOR GO.

  - R956 LANDED (2fdfd2f, k24, 291 inline, opener part three): The
  Dragon issue-24 opener part three, the ten-chain commentary set -
  all ten adjudicated chains of the part-three shape: the Pehr
  magic-user limits (the Rules of Concentration and Duration, the
  weekly wilderness renewal, defenses never added), the Gygax Roman
  military update (the Livian manipular legion - 900 hastati in 16
  maniples of 60, 900 principes, 15 ordines of 3 vexilla of 62,
  morale 9/7/3 with the rear attack 5, the 2x2-for-2x1 mounting
  error, the Julian lights 2x1), the Brunner Viking Caspian saga
  (year 954, 24 ships 1200 warriors, the 20-dirhem ransom, Marzuban
  30000, morale 10 plus 3 commander plus 1 shield wall, archery
  minus 5 and minus 10 against the shield wall, the 3/2 kill
  ratio, the 500-troop occupation), the Gygax melee rationale (ten
  six-second segments, the 5-foot door jam - 1-2 segments, plus 4
  attackers, minus 4 saves - the Design Department note), the
  Laking DUNGEON variations (transference 8+ with the spell-combat
  quad Elf 4 Hero 5 Superhero 6 Wizard 7, chamber capacity 3, kill
  on 12, the occurrence bands, party gold 35000), the Nascati Swiss
  (the 21-foot pike with 3 feet of steel, 80-100 percent handguns
  by 1500, skirmishers 10-30 percent, three phalanxes, the echelon
  text-vs-caption contradiction), the Pehr psionics variant (the
  three power types, intuition 15 percent per level to 90,
  ectoplasm AC 9 at 12 inches out to 48 inches, greater on 91-100,
  anti-psi no oftener than every 5 levels), the Buettner disease
  charts (the 29 fatality bands whose 97-then-99 jump pins the 98
  skip, 92 = 48 days, 97/99/00 = 7/9/10 months, the four symptom
  bands, twenty symptoms), the Rahman Petal Throne name generator
  (the 8x8 grid of 64 segments verified a 1-64 permutation, a pair
  of d8, 2-3 segments euphonic) and the Ward Monty Haul satire (the
  80-hand Bronze Dragon breathing poison gas per Freddie - the
  mistake itself pinned, five 16th-level Wizards, the 29-die
  fireball, the ring of Gax and Jacinth finale, Ernie portable
  hole). 291 inline = 135 consts + 145 bools + 11 table cols, 15
  examples, 6 table_checks, 6 tables (k24Scenarios 3x3,
  k24Occurrences 5x2, k24Subsentient 8x1, k24AntiPsi 6x1,
  k24FatalityRolls 29x2, k24SymptomBands 4x2). The mid-round shape
  rides no new data files; the gap report stays report-023 (3
  closed 0 open), the report-024 boxes unchecked until the R957
  flip. Census 878->879; rverify GREEN 379 mutants 0 missed at base
  d9edf2b; round-trip 90605 bytes md5
  a12ca2a08e880882a734031509aaf565, byte-exact at 2fdfd2f (fresh
  tarball re-run applied 0 already 5). Print catches pinned as
  scanned: literate does not mean a of letters (the missing word),
  De Art Bellica, TRACTACS for TRACTICS, the Barda-a versus
  Baroda-a drift, Sharistan versus Shahristan, Krudish, unguessed
  at strength, beseigars, The know not defeat, pomiard, maintain
  five hundred troop, subcommander affect, death of suitable
  materials (dearth), his of her environment (or), combats of
  protected nature (protracted), the duplicated even-excitement
  phrase, higher levelfighters, eight of nine eight-sided dice
  (or), opponents of two of more levels (or), who can say them may
  (nay), the javelin-of-lightning-bolts garble, continually to a
  particular combat situations, the so-called improvements rivals
  print (rivals), The sturdy mountaineers, a bravery Swiss
  mountaineer, the William Tell comma splice, Gary Gygas, La
  Biocca, Bonewit (Bonewits), Clairenses, plants twice at six and
  eight, Telepathic Projection twice, 15 psychics strength, SPEAR
  LANGUAGES, sig language, a super-intuitive, the half-ile roll,
  Buettuer (Buettner), the TOC Naming Things in EPT against the
  byline Naming People Places and Things, an archdured beded in
  lincoln green, plalin, deomon energy, we were wizards of power
  used a wall of force (missing subject), 29 die fire ball, druddy
  three times, dispell, cut out losses (cut our), liberated women
  game and one of the few gamers (games). Watches: the Sullin
  levels 7-9 and the brawling sequel still empty in TD 24 - both
  ride to TD 25. Next: R957 l24, the pure flip - close all three
  report-024 boxes with gap_flips on the three exact unchecked box
  lines, point the walk at report-024 (3 closed 0 open post-flip),
  the bookkeeping consts and bools; prefix scan fresh at the
  then-HEAD (l24 next). WAIT FOR GO.


  - R957 LANDED (13e6bcf, l24, 29 inline, the pure flip): The
  Dragon issue-24 box closing round - no new ink, all three
  report-024 boxes flipped at the single round: the part-one
  variant triptych (R954, t24), the part-two alignment pantheon
  (R955, s24) and the part-three ten-chain commentary set
  (R956, k24) all checked, gap_census 3 closed 0 open, report-024
  joining mm2 and ddg in the closed state. 29 inline = 17 consts +
  12 bools, 6 examples, no tables - the exact R949 and R953
  symmetry; the bookkeeping pins the shape itself - 3 boxes, 14
  chains, 4 rounds (the third four-round shape), the opener
  totals 134 + 146 + 291 = 571, the walk census issues 2-24 all
  closed (twenty-three issues), the numbering agreement (Vol. III
  No. 10, April 1979, number 24), the folio-equals-PDF-page check,
  the single-voice transcript pin (no archive.org djvu cross-check
  exists for issue 24), the unchanged registry ground truth
  1313/1338/25, the census pinned true at 879/880 matching the
  engine gate (R953 flip consts sat one low at 874/875 against
  the 875-to-876 gate - noted here, landed history not
  rewritten), and the two watches riding to TD 25 (the Sullin
  levels 7-9, the brawling sequel). Census 879->880; rverify
  GREEN 29 mutants 0 missed at base 2fdfd2f; round-trip 18219
  bytes md5 556d83b31ede857d6b9bbde2127ba432, byte-exact at
  13e6bcf (fresh tarball re-run applied 0 already 8; the flip
  round eight patches carry the gap report in the git add). THE
  ISSUE-24 FOUR-ROUND SHAPE IS COMPLETE: R954 t24 3a5152d, R955
  s24 d9edf2b, R956 k24 2fdfd2f, R957 l24 13e6bcf. Next: TD 25 -
  the fresh intake (transcripts, the folio-vs-page check, the
  chain call, the drop list, then the round plan); the Sullin
  levels 7-9 and the brawling long-term-effects watches come due
  there. WAIT FOR GO.


  - R958 LANDED (7518210, t25, 48 inline, the opener set): The
  Dragon issue-25 opener part one - the opener set, three of the
  eight Curtiss-called chains at print 12-19: the Gygax social
  class essay (print 12-13, the birth tables rejected, thieves in
  the lowest two, MACOCRACY and the tripled churchmen catches),
  the Armies of the Renaissance Part III commentary (print 17,
  the White Company at its height of 2,000 longbowmen and 2,000
  men-at-arms, the French invasion year 1490, the Sir John
  Haukwood catch) and the Harrop orc taxonomy guide (print
  18-19, five evil family races and the Orkus three species,
  the gholl/orcom/a-man-orcs/Variages-of-Khan catches). 48
  inline = 27 consts + 21 bools, 7 examples; the adjudication
  is the eight-chain shape of the 2026-10-31 calls - the
  Traveller navy and the Gamma World pieces dropped as
  non-D&D, the Armada Disasters history (print 9-11) dropped
  in the usable-only redo (pure narrative, no game ink).
  Census 880->881; rverify GREEN 48 mutants 0 missed at base
  13e6bcf; round-trip 299032 bytes md5
  c69e5954e2c7654ff4d2779644b3250d, byte-exact at 7518210
  (fresh tarball re-run applied 0 already 54, data files
  49/49 - report-025 plus all 48 transcripts). The part-one
  report-025 boxes are checked; part two (R959 s25, the
  Xochiyaoyotl 37-40 table round plus the Varieties of
  Vampires 42) and part three (R960 k25) still open; the
  watches ride to TD 26 (the Sullin levels 7-9, the brawling
  sequel, a fourth issue running), and the Flower Wars and
  Conquistadores chains stay period-piece-thin for the R960
  adjudication. WAIT FOR GO.


  - R959 LANDED (6a1245c, s25, 118 inline, the table round): The
  Dragon issue-25 opener part two - the war game and
  the vampire roster, two of the eight Curtiss-called
  chains: the Neal M. Dorst Xochiyaoyotl rules for
  pre-Hispanic Mexican warfare (print 37-40) - the scales
  (twenty men a unit, two minutes a turn, twenty five
  yards the inch), the Military Prowess grid as the first
  table (die one through six against prowess one to five,
  the elite mark on the die six roll, the sentinel census
  five), the ratio row at one hundred, ninety, seventy
  five, sixty and fifty percent, the morale and sacrifice
  brackets, the Table 10 victory bands, the War of Flowers
  points and the Spanish optional rules (six elite, the
  quarter ratio, the gunpowder armor flaw, the column, the
  no-sacrifice law) - and the R.P. Smith Varieties of
  Vampires roster (print 42) - the fifteen-type movement
  and charm grid as the second table (the single-move
  Chinese vampire the only move-alt sentinel, seven types
  with no printed charm number), the seven-day rise of
  the unguarded corpse, the asanbosam nine-eight-seven
  hit dice, the ekimmu exorcism at fifty plus or minus
  five percent, the lobishumen sixty percent legacy, the
  call bands for the leopards, tigers, rats, butterflies
  and foxes. 118 inline = 70 consts + 39 bools + 9 table
  cols, 11 examples, 2 table checks, no data files (the
  report and the transcripts all landed at R958).
  Census 881->882; rverify GREEN 190 mutants 0 missed at
  base 7518210; round-trip 45677 bytes md5
  702888d641c4e22940fe407afab2ec88, byte-exact at
  6a1245c (fresh tarball re-run applied 0 already 5).
  Part two of the eight-chain shape complete; part three
  (R960 k25, the commentary set: Flower Wars print
  35-37, To Select a Mythos 43, Conquistadores 44-45)
  next, then the R961 l25 flip; the two watches ride to
  TD 26 (the Sullin levels 7-9, the brawling sequel),
  and the Flower Wars and Conquistadores chains stay
  period-piece-thin for the R960 adjudication. WAIT
  FOR GO.


  - R960 LANDED (53932ed, k25, 70 inline, the commentary set): The
  Dragon issue-25 opener part three - the three-chain
  commentary set, three of the eight Curtiss-called chains:
  the William B. Fawcett War of Flowers commentary (print
  35-37) - the tribute empire at its ritual numbers (the
  twenty day delegation waits, the three State visits, the
  four phratries, the 200-400 man company, the twenty man
  platoon with its flag glyph, the four main weapons, the
  five-clan house of darts, the three knights orders) with
  the ethos bools (tribute not absorption, the no-hostage
  guarantee gap, no drills, the season ban, no siege
  weapons, captives over kills, the veteran apprenticeship,
  the warrior-heaven guarantee, the cotton adoption), the
  Bob Bledsaw To Select a Mythos guide (print 43) - the
  mythos craft calls (the three drawn mythologies, the
  well-developed trait, the limited nexus gates, the clean
  slate, no reality restraints, the D&D non-gunpowder fit,
  the living-faith exclusions, defeatable gods, the tables
  not dogma), and the Michael H. Kluwer Conquistadores
  commentary (print 44-45) - the expedition ledger (Cortez
  1518 at 600-17-10 and the Cozumel review 508-32-13-100,
  the later 40 cavalry and 80 gunners, Pizarro 1531 at
  180-27-2 with the 62-102 march, the thousand man ceiling,
  the 300 year span) with the weapon notes (the pike
  12-18 feet, the halberd one in ten or twenty, the three
  pound matchlock with the three foot barrel and the
  100-200 yard range, the 120 yard crossbow, the 50-75
  percent pike share, the four inch morion comb, the two
  foot buckler). 70 inline = 42 consts + 28 bools, 11
  examples, no tables, no data files. Census 882->883;
  rverify GREEN 70 mutants 0 missed at base 6a1245c;
  round-trip 27268 bytes md5
  7b07d622e6edd2bb97da7f9a0326c35b, byte-exact at 53932ed
  (fresh tarball re-run applied 0 already 5). The Flower
  Wars and Conquistadores chains stayed in at the R960
  adjudication per the standing eight-chain call - the
  banner records the call; the fix note: the R959 record
  first line was restored to the house The-tail format
  before this seat. Part three of the eight-chain shape
  complete; the R961 l25 flip next - all three report-025
  boxes flip at the single round and the issue closes.
  The two watches ride to TD 26 (the Sullin levels 7-9,
  the brawling sequel). WAIT FOR GO.


  - R961 LANDED (49d1f41, l25, 29 inline, the pure flip): The
  Dragon issue-25 box closing round - no new ink, all three
  report-025 boxes flipped at the single round: the part-one
  opener set (R958, t25), the part-two war game and vampire
  roster table round (R959, s25) and the part-three commentary
  set (R960, k25) all checked, gap_census 3 closed 0 open,
  report-025 joining mm2, ddg and report-024 in the closed
  state. 29 inline = 17 consts + 12 bools, 6 examples, no
  tables - the exact R949, R953 and R957 symmetry; the
  bookkeeping pins the shape itself - 3 boxes, 8 chains, 4
  rounds (the fourth four-round shape, proven now at issues
  22, 23, 24 and 25), the opener totals 48 + 118 + 70 = 236,
  the walk census issues 2-25 all closed (twenty-four
  issues), the numbering agreement (Vol. III No. 11, May
  1979, number 25, the cover roman quirk the only miss), the
  folio-equals-PDF-page check, the single-voice transcript
  pin (no archive.org djvu cross-check exists for issue 25),
  the print catches of all four rounds pinned as scanned,
  the unchanged registry ground truth 1313/1338/25, the
  census pinned true at 883/884 matching the engine gate, and
  the two watches riding to TD 27 (the Sullin levels 7-9 and
  the brawling sequel, both absent a fifth issue through the
  TD 26 intake). Census 883->884; rverify GREEN 29 mutants 0
  missed at base 53932ed; round-trip 15769 bytes md5
  87d1186dd75f7f1dd4f53cb43dd43c3e, byte-exact at 49d1f41
  (fresh tarball re-run applied 0 already 8; the flip round
  eight patches carry the gap report in the git add). THE
  ISSUE-25 FOUR-ROUND SHAPE IS COMPLETE: R958 t25 7518210,
  R959 s25 6a1245c, R960 k25 53932ed, R961 l25 49d1f41 -
  THE DRAGON WALK HOLDS ISSUES 2-25 ALL CLOSED. The fix
  note: the R960 record first line was restored to the
  house The-tail format before this seat (the landed repo
  seed keeps the no-tail line). Next: TD 26 opens at
  R962 t26 - the intake adjudicated 2026-10-31 at thirteen
  usable D&D chains (part one five chains print 13-28, the
  s26 table round four chains, the k26 part three four
  chains, then the R965 l26 flip); the R962 spec
  data_files carry report-026 plus all fifty-two
  transcripts. WAIT FOR GO.


  - R962 LANDED (c839b60, t26, 80 inline, the opener set): The
  Dragon issue-26 opener part one - the opener set, five of
  the thirteen Curtiss-called chains at print 13-14 +
  26-30 + 39: the Giants in the Earth column debut (the
  three heroes - Cugel the 14th level thief with the 85
  percent luck and the lucounu spells, Kane the 30/20/14
  triple-class with the 05 percent assassination pin,
  Tros the 15th level paladin), the Sagui hireling pay
  doctrine (the 72 GP two-year advance, the demihuman
  and orc price ladders, the 65 percent hammer grab),
  the Krebs SAGE microcomputer piece (the worked arc
  hit-chart example, the repeating-room labyrinth), the
  Crane moderator dark secrets (the pit escalation, the
  jello decoys, the 15-character reward method) and the
  Gygax D&D AD&D gaming history essay (the Bath
  pre-CHAINMAIL priority, the 1973 manuscript, the
  January 1974 publication, the new-game doctrine). 80
  inline = 45 consts + 35 bools, 10 examples, no tables;
  data files 53 - report-026 plus all 52 transcripts, the
  report and the transcripts rebuilt from the durable OCR
  before the build, the transcript total matching the
  recorded 290148 bytes exactly. Census 884->885; rverify
  GREEN 80 mutants 0 missed at base 49d1f41; round-trip
  341544 bytes md5 895640c308667ee8a23d2eccd56ca67b,
  byte-exact at c839b60 (fresh tarball re-run applied 0
  already 58). The R961 record seated in the repo seed
  with its house The-tail first line intact. Part one of
  the TD 26 four-round shape complete - five of the
  thirteen chains down; R963 s26 next, the table round
  (Chinese Undead 20-21, the Nine-Point Alignment chart
  23, the Deck of Fate 24-25, the Strength Comparison
  Table 38). The two watches ride to TD 27 (the Sullin
  levels 7-9, the brawling sequel). WAIT FOR GO.


  - R963 LANDED (7d482ef, s26, 111 inline, the table round): The
  Dragon issue-26 opener part two - the table round, four
  of the thirteen Curtiss-called chains at print 20-21 +
  23 + 24-25 + 38: the Chinese Undead roster (six undead
  brackets, the lost soul replacement-kill and no-dissolve
  laws, the vampire spectre brackets, the tiger skin
  quest), the nine-point alignment chart (nine boxes
  against seven conduct rows, the 2/1/0 encoding, the
  fifteenth level lord), the Deck of Fate tarot artifact
  (the seven-band wheel of fortune, the greater arcana
  boons, the moon citing Dragon 18) and the strength
  comparison ladder (twenty-one rows from collapse to the
  storm giants, the ogre power revision, the Arduin
  source). 111 inline = 52 consts + 40 bools + 19 table
  cols, 13 examples, 4 table_checks, four grids -
  s26UndeadGrid 6x7, s26AlignmentGrid 9x7, s26FateGrid
  7x2, s26StrengthGrid 21x3, the overlapping 18/90
  strength print pinned as scanned. Census 885->886;
  rverify GREEN 274 mutants 0 missed at base c839b60;
  round-trip 41806 bytes md5
  7b61df254de143ecfe0b7bcb6f27fc44, byte-exact at
  7d482ef (fresh tarball re-run applied 0 already 5).
  The R962 record seated in the repo seed with its
  house The-tail first line intact. Part two
  of the TD 26 four-round shape complete; R964 k26 next,
  the commentary set (Lich 36, Impromptu Adventuring
  Groups 37 + 39, Barghest 44, The Thief 46). The two
  watches ride to TD 27 (the Sullin levels 7-9, the
  brawling sequel). WAIT FOR GO.


  - R964 LANDED (3673f7e, k26, 89 inline, the commentary set): The
  Dragon issue-26 opener part three - the commentary
  set, four of the thirteen Curtiss-called chains at
  print 36 + 37 + 39 + 44 + 46: the Blueprint for a
  Lich recipe (the 2000 gold piece jar, the trap the
  soul odds, the corpse possession ladder, the
  nine-ingredient potion with its 1-00 results), the
  impromptu party system (the 4d4 abilities, the
  level bands, the per-class tables, the Gonzo 135
  percent example, the robe patches), the Dragon
  Bestiary barghest (the Gehenna deodand, the 6+6
  whelp feeding law, the canine form and the fire
  banishment) and the city thief doctrine (the
  disguise, the rooftops, the scapegoat and the
  stash-and-alibi method). 89 inline = 49 consts +
  40 bools, no tables; 12 examples. Census 886->887;
  rverify GREEN 89 mutants 0 missed at base 7d482ef;
  round-trip 33736 bytes md5 a5fcbe6fa0aa94584a637460b10cac4,
  byte-exact at 3673f7e (fresh tarball re-run applied 0
  already 5). The R963 record seated in the repo seed
  with its house The-tail first line intact. Part three
  of the TD 26 four-round shape complete; R965 l26
  next, the flip closing all three report-026 boxes
  and the issue walk. The two watches ride to TD 27
  (the Sullin levels 7-9, the brawling sequel).
  WAIT FOR GO.


  - R965 LANDED (f7e8560, l26, 29 inline, the pure flip): The
  Dragon issue-26 box closing round - the pure flip,
  no new ink: all three report-026 boxes check at
  this single round - the part-one opener set
  (R962, t26, 80 inline), the part-two table round
  (R963, s26, 111 inline) and the part-three
  commentary set (R964, k26, 89 inline), 280 opener
  inline across the thirteen chains. The fifth
  four-round walk complete, the Dragon walk now
  holds issues 2-26 all closed - twenty-five
  issues. 29 inline = 17 consts + 12 bools, no
  tables; 6 examples; 3 gap flips, report-026
  joining mm2, ddg, report-024 and report-025 in
  the closed state. Census 887->888; rverify GREEN
  29 mutants 0 missed at base 3673f7e; round-trip
  15061 bytes md5 322573b28152b741a9fa57f69b14f6d0,
  byte-exact at f7e8560 (fresh tarball re-run
  applied 0 already 8). The R964 record seated in
  the repo seed with its house The-tail first line
  intact. TD 26 complete; the two watches ride to
  TD 27 (the Sullin levels 7-9, the brawling
  sequel) with the TD 27 intake unadjudicated,
  awaiting the Curtiss-provided scan. WAIT FOR GO.


  - R966 LANDED (dfb11f1, csh, 19
  inline, the charter round): THE
  CONTENT-STRUCTURE CHARTER - the
  content-structure arc opener, no
  book ink: the folder-hierarchy
  adjudication pinned as 8 consts +
  11 bools - the frame (domain count
  9, world count 3, the two nesting
  precedents, dungeon 64 / overland
  32 tile px, the six-value dungeon
  vocabulary, the retiring 25x19
  viewport pair) and the eleven
  doctrines (content/ the data root,
  no C++ in the tree, rules migrate
  to Lua records with the testing
  move, npcs separate, mundane+magic
  items together, artifacts
  sub-domain, modules nest under
  world, expansions nest under
  parent, tile size a manifest field,
  shared tile vocabulary, asset =
  payload + manifest). The charter
  document landed as the data file
  doc/content_structure.md (106
  lines). No flips, report-026
  gap_census 3/0. Census 888->889;
  rverify GREEN 19 mutants 0 missed
  at base f7e8560; round-trip applied
  0 already 6, byte-exact at
  dfb11f1; spec 13859 bytes md5
  f8d3ae1305d3cdeab045d8154c19e749.
  The R965 record seated in the repo
  seed. The content tree does NOT
  exist yet - the R967 candidate is
  the skeleton (data_files .keeps)
  plus the monsters git-mv with its
  five touch lines. WAIT FOR GO.


  - R967 LANDED (b259495, cnt, 10
  inline, the tree creation): THE
  CONTENT TREE CREATION - the arc
  round two, no book ink: the
  content/ skeleton lands via 13
  .keep data files (rules, npcs,
  items, items/artifacts, spells,
  tables, tiles, objects, world +
  the three world buckets + the
  karatur expansion bucket) and the
  monster registry MOVES - git mv
  monsters/monsters to content/
  monsters, 1338 records unchanged,
  the loader path rewritten in SIX
  places (adnd1.cpp x2, regtest x2,
  normalize_registry x1, the R314
  engine audit fragment x1). 5
  consts + 5 bools; census 889->890;
  rverify GREEN 10 mutants 0 missed
  at base dfb11f1; round-trip applied
  0 already 24, byte-exact at
  b259495; spec 8725 bytes md5
  7bad36f5c8bb129c352abc020fcbed04.
  The v1 RED LESSON (two aborts):
  the user-side git mv never ran
  (loaded 0), then the R314
  crossbow and aquatic ENGINE audit
  read bad 3 - its fragment holds a
  RUNTIME letter-dir loadDirectory,
  the one live ref the five-line
  touch list missed; its early
  return 1 truncated the whole
  census chain. STANDING LESSON: a
  path-move touch list scans CALL
  SITES (grep loadDirectory
  repo-wide), never just the path
  string - rules/audits/ fragments
  hold live loader paths too.
  SECOND LESSON (the R420
  refinement): the mixed applied/
  already gate aborts on ANY mix -
  a fixed-spec re-land restores ALL
  v1-touched files to base first
  (git restore --source), never a
  partial unwind. The R966 record
  seated in the repo seed. KNOWN
  HYGIENE: content/monsters/.keep
  rode the landed tree (created
  during the repair sequence) -
  violates charter rule 11, plain-
  commit removal pending. WAIT FOR
  GO.

- R968 LANDED (58a63d7, rpf, 12
  inline, the format round): THE
  RULES RECORD FORMAT - the arc
  round three, no book ink: the
  content/rules/ record shape
  pinned - one Lua record per pin
  round (a bucket holds many
  records, the file is the
  adjudication - Curtiss's
  2026-10-31 call over the
  one-big-book-file), buckets by
  source book, records as
  mechanical translations of the
  spec JSONs (the spec stays the
  adjudicated record, never
  hand-edited, the translation
  back the proof), the battery
  from records (rverify
  semantics), the Dragon set
  first. 6 consts + 6 bools; the
  format doc landed as the data
  file doc/rules_record_format.
  md. No flips; census 890->891;
  rverify GREEN 12 mutants 0
  missed at base 5f11f29;
  round-trip applied 0 already 6,
  byte-exact at 58a63d7; spec
  10064 bytes md5 117eacf4030dbf
  c232d1eeb7e4a7757f. The R967
  record seated in the repo seed.
  KNOWN ISSUE found at R969 prep:
  the rpfDragonSpecs 128 measure
  was a grep over-match (WSG, OA,
  DMO, MM2, DDG and FF specs and
  self-references caught) - the
  walked Dragon set is R887-R965,
  79 rounds; the correction rides
  R969 (the R632 measure-twice
  class). WAIT FOR GO.

- R969 LANDED (7c55ce7, dp1, 7
  inline, the promotion batch
  one): THE DRAGON PROMOTION
  BATCH ONE - the arc round four,
  the first Lua records on disk:
  the pre-walk trio plus issue 2
  complete - ivs, drg, arn, rmz,
  alc, fch, sys, art; 8 records
  riding content/rules/dragon/
  {prefix}.lua (116362 bytes
  Lua), 281 model items, every
  record parsed back and compared
  equal (the lossless proof -
  promote_lib.py emitter/parser,
  no hand edits). 4 consts + 3
  bools: dp1BatchRecords=8,
  dp1ModelItems=281,
  dp1DragonSetRounds=79 (the
  corrected measure - the R968
  128 was a grep over-match),
  dp1CumulativeRecords=8,
  dp1RecordsPromoted,
  dp1DiffBackGreen,
  dp1MeasureCorrected. Census
  891->892; no flips; gap report
  026 stays 3/0. Double-run
  applied 13/already 13, verify
  at 7c55ce7 already 13 with the
  8 files on disk; rverify GREEN
  7 mutants 0 missed at base
  58a63d7; spec 129321 bytes md5
  1d0fc10e759a5d092c79ce7f241
  ed874, canvas r969-spec (the
  big-canvas precedent - records
  ride inside the spec). The
  batch sizing: byte weight
  (Curtiss, as many per round as
  efficient). WAIT FOR GO.



- R970 LANDED (9ebd433, dp2, 7
  inline, the promotion batch
  two): THE DRAGON PROMOTION
  BATCH TWO - the arc round
  five, issue 3 complete: wmn
  (the Lakofka women), spr (the
  Healer and the Scribe), fsc
  (the Samurai and the
  Berserker) - 3 records, 255
  model items, 104817 bytes
  Lua, every record parsed
  back and compared equal (the
  lossless proof - the promote
  lib rebuilt this turn and
  byte-proven: all 8 batch-one
  records regenerate identical
  to the landed Lua). 4 consts
  + 3 bools: dp2BatchRecords=3,
  dp2ModelItems=255,
  dp2CumulativeRecords=11,
  dp2SetRoundsRemaining=68,
  dp2RecordsPromoted,
  dp2DiffBackGreen,
  dp2IssueThreeComplete.
  Census 892->893; no flips;
  gap report 026 stays 3/0.
  Double-run applied 8/
  already 8, verify at
  9ebd433 already 8 with all
  11 records on disk (221179
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  7c55ce7; spec 116532 bytes
  md5 87f5d134f1bc9ce7873
  68b6e76d35df, canvas
  r970-spec. The R969 record
  seated in the repo seed.
  BYTE WEIGHT: R898 (chr) is
  117KB Lua alone - batch
  three opens at chr. WAIT FOR
  GO.


- R971 LANDED (f62acfc, dp3, 7
  inline, the promotion batch
  three): THE DRAGON PROMOTION
  BATCH THREE - the arc round
  six, issue 4 complete, THE
  BATCH CEILING RAISED
  (Curtiss, 2026-10-31): whole
  issue groups ride per round
  (the specs run small) - this
  batch nearly doubled the
  spec precedent. chr (the
  combat matrix variants, 194
  items, 117001 bytes Lua - the
  set's biggest record), cmv
  (173), cfe (70), cfc (10) -
  4 records, 447 model items,
  214984 bytes Lua, every
  record parsed back equal.
  4 consts + 3 bools:
  dp3BatchRecords=4,
  dp3ModelItems=447,
  dp3CumulativeRecords=15,
  dp3SetRoundsRemaining=64,
  dp3RecordsPromoted,
  dp3DiffBackGreen,
  dp3IssueFourComplete.
  Census 893->894; no flips;
  gap report 026 stays 3/0.
  Double-run applied 9/
  already 9, verify at f62acfc
  already 9 with all 15
  records on disk (436163
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  9ebd433; spec 232857 bytes
  md5 d77dc5e26c2cb4c31b87dd
  bce42bc0f9, canvas r971-spec
  (the raised-ceiling
  precedent). The R970 record
  seated in the repo seed. All
  68 remaining rounds measured
  round-trip GREEN - the whole
  set is 1.75MB Lua, one issue
  group per round, ~15-20
  batches left. WAIT FOR GO.


- R972 LANDED (30ee5de, dp4, 7
  inline, the promotion batch
  four): THE DRAGON PROMOTION
  BATCH FOUR - the arc round
  seven, issues 5 through 7
  complete: wch (the Witchcraft
  Supplement opener, 141
  items), cwx (9), wwt (12),
  wrm (79), dso (the Sea Trade
  opener, 90), csx (11), pwl
  (the Prowler opener, 25), cpx
  (11) - 8 records, 378 model
  items, 151832 bytes Lua,
  every record parsed back
  equal. ISSUE BOUNDARIES
  REFINED: R902-905 = issue 5,
  R906-907 = issue 6, R908-909
  = issue 7's opener and
  closer - three issues rode
  one batch under the raised
  ceiling. 4 consts + 3
  bools: dp4BatchRecords=8,
  dp4ModelItems=378,
  dp4CumulativeRecords=23,
  dp4SetRoundsRemaining=56,
  dp4RecordsPromoted,
  dp4DiffBackGreen,
  dp4IssuesFiveSevenComplete.
  Census 894->895; no flips;
  gap report 026 stays 3/0.
  Double-run applied 13/
  already 13, verify at
  30ee5de already 13 with all
  23 records on disk (587995
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  f62acfc; spec 165568 bytes
  md5 97d71c0b3d4db8feb729ccb
  898bcd7cb, canvas r972-spec.
  The R971 record seated in the
  repo seed. The lib rebuilt
  and byte-matched 15/15 on the
  landed records before the
  batch. WAIT FOR GO.


- R973 LANDED (e2d6a6f, dp5, 7
  inline, the promotion batch
  five): THE DRAGON PROMOTION
  BATCH FIVE - the arc round
  eight, issues 8 through 10
  complete: dgo (the Gygax
  Planes opener, 61 items), cgx
  (11), dgn (the Gygax
  alignment opener, 43), dnp
  (13), dtn (the Orgies Inc.
  opener, 74), dte (the Gilbert
  dungeon opener, 71), dfp
  (15) - 7 records, 288 model
  items, 104937 bytes Lua,
  every record parsed back
  equal. 4 consts + 3 bools:
  dp5BatchRecords=7,
  dp5ModelItems=288,
  dp5CumulativeRecords=30,
  dp5SetRoundsRemaining=49,
  dp5RecordsPromoted,
  dp5DiffBackGreen,
  dp5IssuesEightTenComplete.
  Census 895->896; no flips;
  gap report 026 stays 3/0.
  Double-run applied 12/
  already 12, verify at e2d6a6f
  already 12 with all 30
  records on disk (692932
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  30ee5de; spec 116668 bytes
  md5 b4079bbafbc92b285bd55748
  12efe681, canvas r973-spec.
  The R972 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 23/23 on the
  landed records before the
  batch. WAIT FOR GO.


- R974 LANDED (41fb76c, dp6, 7
  inline, the promotion batch
  six): THE DRAGON PROMOTION
  BATCH SIX - the arc round
  nine, issues 11 through 12
  complete: brw (the Kuntz
  brawling opener, 54 items),
  bfx (17), ilv (the Ovalle
  illusions opener, 62), myt
  (the Persian Mythos opener,
  100), fcl (20) - 5 records,
  253 model items, 76688 bytes
  Lua, every record parsed
  back equal. 4 consts + 3
  bools: dp6BatchRecords=5,
  dp6ModelItems=253,
  dp6CumulativeRecords=35,
  dp6SetRoundsRemaining=44,
  dp6RecordsPromoted,
  dp6DiffBackGreen,
  dp6IssuesElevenTwelveComplete.
  Census 896->897; no flips;
  gap report 026 stays 3/0.
  Double-run applied 10/
  already 10, verify at
  41fb76c already 10 with all
  35 records on disk (769622
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  e2d6a6f; spec 87207 bytes
  md5 684418528b60dcf974be892d
  442c0711, canvas r974-spec.
  The R973 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 30/30 on the
  landed records before the
  batch. WAIT FOR GO.


- R975 LANDED (4e045bc, dp7, 7
  inline, the promotion batch
  seven): THE DRAGON PROMOTION
  BATCH SEVEN - the arc round
  ten, issues 13 through 14
  complete: dgm (the Shlump da
  Orc opener, 52 items), kmy
  (the Japanese Mythos opener,
  42), icl (21), lyc (the Name
  That Monster Contest opener,
  81), f14 (23) - 5 records,
  219 model items, 93924 bytes
  Lua, every record parsed
  back equal. 4 consts + 3
  bools: dp7BatchRecords=5,
  dp7ModelItems=219,
  dp7CumulativeRecords=40,
  dp7SetRoundsRemaining=39,
  dp7RecordsPromoted,
  dp7DiffBackGreen,
  dp7IssuesThirteenFourteen
  Complete. Census 897->898; no
  flips; gap report 026 stays
  3/0. Double-run applied 10/
  already 10, verify at
  4e045bc already 10 with all
  40 records on disk (863546
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  41fb76c; spec 104091 bytes
  md5 ece9874570e12f93d59ee0944
  0162c57, canvas r975-spec.
  The R974 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 35/35 on the
  landed records before the
  batch. WAIT FOR GO.


- R976 LANDED (4360209, dp8, 7
  inline, the promotion batch
  eight): THE DRAGON PROMOTION
  BATCH EIGHT - the arc round
  eleven, issues 15 through 16
  complete: drm (the Dragon
  Magic wandering-monster
  opener, 183 items), f15 (25),
  nin (the Near Eastern Mythos
  opener, 139), f16 (27) - 4
  records, 374 model items,
  99542 bytes Lua, every record
  parsed back equal. 4 consts +
  3 bools: dp8BatchRecords=4,
  dp8ModelItems=374,
  dp8CumulativeRecords=44,
  dp8SetRoundsRemaining=35,
  dp8RecordsPromoted,
  dp8DiffBackGreen,
  dp8IssuesFifteenSixteen
  Complete. Census 898->899; no
  flips; gap report 026 stays
  3/0. Double-run applied 9/
  already 9, verify at 4360209
  already 9 with all 44 records
  on disk (963088 bytes Lua);
  rverify GREEN 7 mutants 0
  missed at base 4e045bc; spec
  111729 bytes md5 92152aafd5
  b371ec98d45e706ff66970,
  canvas r976-spec. The R975
  record seated in the repo
  seed. The lib rebuilt and
  byte-matched 40/40 on the
  landed records before the
  batch. WAIT FOR GO.


- R977 LANDED (4b50188, dp9, 7
  inline, the promotion batch
  nine): THE DRAGON PROMOTION
  BATCH NINE - the arc round
  twelve, issues 17 through 18
  complete, THE HALFWAY MARK:
  jou (the jousting opener, 209
  items), wzd (the Wizard With
  A Dog opener, 170), f17 (29),
  psy (the insanity chart
  opener, 114), mkn (the Sullin
  new spells opener, 178), f18
  (29) - 6 records, 729 model
  items, 192398 bytes Lua (the
  heaviest batch so far),
  every record parsed back
  equal. 4 consts + 3 bools:
  dp9BatchRecords=6,
  dp9ModelItems=729,
  dp9CumulativeRecords=50,
  dp9SetRoundsRemaining=29,
  dp9RecordsPromoted,
  dp9DiffBackGreen,
  dp9IssuesSeventeenEighteen
  Complete. Census 899->900; no
  flips; gap report 026 stays
  3/0. Double-run applied 11/
  already 11, verify at
  4b50188 already 11 with all
  50 records on disk (1155486
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  4360209; spec 210026 bytes
  md5 06ec632591402e90ee577994
  b405381c, canvas r977-spec.
  The R976 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 44/44 on the
  landed records before the
  batch. WAIT FOR GO.

- R978 LANDED (15c273a, dp10, 7
  inline, the promotion batch
  ten): THE DRAGON PROMOTION
  BATCH TEN - the arc round
  thirteen, issues 19 through 20
  complete: dws (the wish-spell
  doctrine opener, 117 items),
  sdm (the Origins 78 tournament
  opener, 119), d19 (31), t20
  (the Polynesian pantheon
  opener, 90), dst (the
  600-death campaign opener,
  67), d2c (33) - 6 records,
  457 model items, 149970 bytes
  Lua, every record parsed back
  equal. 4 consts + 3 bools:
  dp10BatchRecords=6,
  dp10ModelItems=457,
  dp10CumulativeRecords=56,
  dp10SetRoundsRemaining=23,
  dp10RecordsPromoted,
  dp10DiffBackGreen,
  dp10IssuesNineteenTwenty
  Complete. Census 900->901; no
  flips; gap report 026 stays
  3/0. Double-run applied 11/
  already 11, verify at
  15c273a already 11 with all
  56 records on disk (1305456
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  4b50188; spec 164099 bytes
  md5 ecf6d0c1bf574f17b0acf17b
  5109d7d8, canvas r978-spec.
  The R977 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 50/50 on the
  landed records before the
  batch. WAIT FOR GO.

- R979 LANDED (746a2d2, dp11, 7
  inline, the promotion batch
  eleven): THE DRAGON PROMOTION
  BATCH ELEVEN, PART ONE - the
  set close halved at the
  clipboard limit (Curtiss,
  2026-10-31): issues 21
  through 23 complete - t21 the
  issue-21 opener, g21 the
  issue-21 part two, d21 the
  issue-21 closing flip, then
  the quartets t22 s22 k22 l22
  and t23 s23 k23 l23 - 11
  records, 1108 model items,
  335833 bytes Lua, every
  record parsed back equal. 4
  consts + 3 bools:
  dp11BatchRecords=11,
  dp11ModelItems=1108,
  dp11CumulativeRecords=67,
  dp11SetRoundsRemaining=12,
  dp11RecordsPromoted,
  dp11DiffBackGreen,
  dp11IssuesTwentyOneTwenty
  ThreeComplete. Census
  901->902; no flips; gap
  report 026 stays 3/0.
  Double-run applied 16/
  already 16, verify at
  746a2d2 already 16 with all
  67 records on disk (1641289
  bytes Lua); rverify GREEN 7
  mutants 0 missed at base
  15c273a; spec 361476 bytes
  md5 bee5a50f005b35ad615a389f
  5e7da147, canvas r979-spec.
  The R978 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 56/56 on the
  landed records before the
  batch. WAIT FOR GO.

- R980 LANDED (b10fd95, dp12, 7
  inline, the promotion batch
  twelve): THE DRAGON PROMOTION
  BATCH TWELVE - THE SET CLOSER
  - issues 24 through 26
  complete, the quartets t24
  s24 k24 l24, t25 s25 k25 l25
  and t26 s26 k26 l26 - 12
  records, 1121 model items,
  329298 bytes Lua, every
  record parsed back equal. 4
  consts + 3 bools:
  dp12BatchRecords=12,
  dp12ModelItems=1121,
  dp12CumulativeRecords=79,
  dp12SetRoundsRemaining=0,
  dp12RecordsPromoted,
  dp12DiffBackGreen,
  dp12IssuesTwentyFourTwentySix
  Complete. Census 902->903; no
  flips; gap report 026 stays
  3/0. Double-run applied 17/
  already 17, verify at
  b10fd95 already 17 with ALL
  79 RECORDS ON DISK - THE SET
  CLOSED (1970587 bytes Lua);
  rverify GREEN 7 mutants 0
  missed at base 746a2d2; spec
  354534 bytes md5
  5bbf376e2e89bdacd7038748
  a9a10c03, canvas r980-spec.
  The R979 record seated in the
  repo seed. The lib rebuilt and
  byte-matched 67/67 on the
  landed records before the
  batch. WAIT FOR GO.

### Current state (post-R1026 - THE DEITY
### SEAM CLOSES, THE QUEUE IS EMPTY)

(SUPERSEDED by the tail rounds R1027-R1033, 2026-11-13 -
the queue reopened into the content-name sweeps, the de-wire
arc, and delivery v2; HEAD moved past c9c35759. This block
stays as the R1026 seam-close record.)

- HEAD c9c35759 ("R1026: The deity
  seam close (census 949)", census
  949 audit lines). THE DEITY
  SEAM CLOSES - the L&L parity
  inventory: 130 notes across the
  pin headers, every one
  adjudicated, ZERO open
  divergences, ZERO derivative
  voices needed; L&L a parity
  voice, not a second book; the
  DDG gap report 24 closed 0
  open. THE REGISTRY CLOSED at
  R1025 - 1338 of 1338 defs
  canonical full-field (MM1 408,
  MM2 332, DDG 338, FF 185, OA 47,
  WSG 15, MOP 8, DRG 5), the
  per-book normalization arc
  complete (MM1 R1009-R1014, OA
  R1016, MM2 R1017-R1020, FF
  R1021-R1023, WSG+MOP R1024, DRG
  R1025). THE QUEUE IS EMPTY -
  every standing seam closed; the
  next arc awaits Curtiss's call. THE MM2
  NORMALIZATION ARC IS
  CLOSED - 332 of 332 defs
  canonical full-field, the book
  complete on both axes (R1017
  letters a-d, R1018 derro through
  mephistopheles, R1019 mihstu
  through shadow_mastiff, R1020
  shator through zygom with the
  monster zombie triple-grid pin
  repair - live walk, fragment
  CWXYZStats row 14 AND the
  fragment direct per-cell pins);
  the OA book
  closed complete at R1016 (47/47). THE PROMOTIONS ARC IS
  COMPLETE - every promoted set
  closed and parsed back equal:
  dragon 79/79 (R969-R980), OA
  160/160 (R981-R988) PLUS THE OA
  TABLES 139/139 promoted into the
  94 with-tables records (R1015,
  the R981-R988 batches had
  shipped tables = {}), WSG 77/77
  (R989-R993), DSG 60/60
  (R994-R998), UA 76/76 (R999-
  R1005, the set closer at
  e4b7a8b5, prefixes ua1-ua7; the
  one open ua gap line is the
  legend). THE MM1 DATA-QUALITY
  MOP (R1006-R1008): the text
  census 408/408, the glyph
  repair across 222 defs, the
  battery line loaded 1338 errors
  0. THE MM1 NORMALIZATION ARC
  CLOSED (R1009-R1014): 408/408
  defs canonical at the
  full-field 57-key emission,
  byte-exact against the landed
  normalize_registry.py, the
  normalizer census 1338 live. The older
  sets hold: ALL 79 RECORDS ON DISK - THE
  79-ROUND SET FULLY PROMOTED
  under content/rules/dragon/
  (unchanged at R988: the 160-
  round OA set, 160/160 records,
  2,335,048 bytes Lua, eight
  batches R981-R988, closed).
  THE WSG SET IS CLOSED at R993:
  content/rules/wsg/ holds the
  full 77 records (R425-R502,
  1,369,573 bytes Lua, prefixes
  wsg1/wsg2/wsg3/wsg4/wsg5 at
  rules/wsg{1..5}.h), zero
  remaining, five batches
  R989-R993 under the R968
  format, every record promoted
  mechanically and parsed back
  equal (three pre-spec header
  rounds R425-R427 per the
  promotion-from-headers
  doctrine, 74 spec rounds per
  the Dragon spec doctrine).
  THE DSG SET IS CLOSED at R998:
  content/rules/dsg/ holds the
  full 60 records (R503-R563,
  1,267,132 bytes Lua, prefixes
  dsg1/dsg2/dsg3/dsg4/dsg5 at
  rules/dsg{1..5}.h), zero
  remaining, five batches
  R994-R998 under the R968
  format, every record promoted
  mechanically and parsed back
  equal (R515 absent from the
  dsg regtest map, all 60
  counted rounds spec-JSON
  rounds)
  (1970587 bytes Lua), twelve
  batches R969-R980, the set
  closed at R980, registry
  ground truth unchanged: 1313 loaded /
  1338 base lua / 25 never-load (R924
  re-measure), the records at
  content/monsters/{a..z}.
- THE FORMAT IS LANDED (R968): doc/
  rules_record_format.md in the
  repo, 12 inline (rpf consts +
  bools); the promotion batches
  ride from R969. KNOWN ISSUE
  seated at the R968 record: the
  128 grep over-match, true Dragon
  set 79 rounds - corrected at
  R969's dp1DragonSetRounds=79.
- The content tree EXISTS: the 13
  skeleton keeps, the karatur expansion
  bucket, content/monsters full with
  the 1338 records; monsters/monsters
  gone. The stray keep is REMOVED
  (5f11f29) - rule 11 clean.
- Gap reports: mm2 37/0, ddg 24/0, report-024
  3/0, report-025 3/0 and report-026 3/0 all
  closed; the Dragon walk holds issues 2-26 all
  closed - the fifth four-round walk complete,
  the four-round shape five times proven at
  issues 22, 23, 24, 25 and 26.
- TD 26 complete: thirteen chains across the
  three opener rounds (80 + 111 + 89 = 280
  inline) plus the flip; report-026 and the
  fifty-two transcripts durable in the repo at
  tools/dragon_gap_report_026.md and
  extract/dragon/026.
- Watches riding to TD 27: the Sullin New Spells
  levels 7-9 and the brawling long-term-effects
  sequel - a fifth issue running through the TD
  26 intake.
- Arc status (Curtiss, 2026-10-31): the Dragon walk
  PAUSED at a clean boundary - issues 2-26 all
  closed, TD 27 unadjudicated, the two watches
  riding whenever the walk resumes; no TD 27 scan
  is awaited right now. The session switched
  arcs at the Curtiss call; the walk reopens
  with the intake adjudication, the transcript
  build and the fresh gap report before any
  round is authored, and a prefix scan fresh at
  the then-HEAD.
- Content-structure arc (2026-10-31): the
  folder-hierarchy proposal lives on the
  canvas content-structure-hierarchy (the v2
  rewrite after the record-format draft
  rejection). ADJUDICATED (Curtiss): the data
  root is content/ - game data and SCRIPT
  code files live in the tree, C++ never
  enters it (loader/engine code stays in the
  domain dirs); monsters/{a-z} moves there
  first. Standing constraint: rules/ and
  rules/audits/ cannot move (66 spec JSONs +
  1046 regtest includes anchor them). Open
  decisions: the embedded C++ domains
  charter-in-place, the scratch home, dice.h,
  the charter doc name, the move-round shape.
  AGREED DIRECTION (Curtiss, 2026-10-31):
  rules content migrates to Lua records
  under content/rules/ (same direction as
  the monster registry); TESTING MOVES
  WITH IT - the Lua record becomes the
  audited artifact, the mutant battery
  mutates and verifies the records
  Python-side (rverify sim precedent), a
  loader census guards runtime, regtest
  shrinks to engine + smoke test; motive:
  relieve the C++ compile burden (regtest
  1046 pin includes, big headers). The
  rules record shape (heterogeneous
  consts/bools/grids/chains vs the
  one-monster-per-file cut) is the next
  thing to nail down at formalization.
  CONTENT DOMAINS AGREED (Curtiss,
  2026-10-31): content/ holds rules,
  monsters, npcs (SEPARATE from monsters
  - class/level, equipment, personality),
  items (WPN/ARMOR/GEAR leave C++) and
  spells (kSpells leaves C++), plus
  tables (the rollable treasure/
  encounter/appendix tables) - Curtiss
  agreed spells+tables, content/world/
  STILL UNDER DISCUSSION (the 64x64
  map-as-record question).
  WORLD SETTLED (Curtiss, 2026-10-31):
  content/world/ is a full domain -
  three main worlds, greyhawk /
  dragonlance / forgottenrealms, one
  bucket per world; world/map.h is
  ENGINE (the dungeon tile system -
  verified at f7e8560: six-tile
  vocabulary, viewport, NO authored
  maps exist yet), so world is born for
  new content like npcs. Map records:
  one map per file, grid as row-strings.
  OPEN: the overland tile vocabulary
  (today's tiles are dungeon-interior -
  the first world round establishes it
  for all three).
  WORLD NESTING RULE (Curtiss,
  2026-10-31): expansions nest under
  their parent world - kara-tur is an
  expansion to the Forgotten Realms,
  rides as content/world/
  forgottenrealms/karatur/.
  ITEMS/ARTIFACTS (Curtiss, 2026-10-31):
  content/items/ holds the full item
  catalog - mundane + magic side by side
  (magic = same schema + enchant fields:
  bonus, charges, command word, curse),
  bucketed by the printed taxonomy;
  ARTIFACTS are their own sub-domain at
  content/items/artifacts/ (unique,
  prose-heavy, powers/side-effects/
  curse - the DDG Necronomicon pinned-
  doctrine precedent; generated only
  from adjudicated pins like the
  deities). Nesting rule now has two
  precedents: sub-domains nest under
  the parent they belong to
  (world/forgottenrealms/karatur,
  items/artifacts).
  TILES/OBJECTS (Curtiss, 2026-10-31):
  image assets are content - content/
  tiles/ (tilesets) + content/objects/
  (map placeables), one folder per asset
  pairing the image with its Lua
  manifest (cells, frames, collision,
  script hooks). TILE SIZE IS A MANIFEST
  FIELD, not an engine constant:
  dungeon/indoor 64x64, overland/outdoor
  32x32 (TILE_W/H 32 and VIEW_TILES
  25x19 retire from world/map.h into the
  manifests; viewport derives from
  window size / tile size). RATIONALE
  (Curtiss): 32px outdoor is the
  memory-conservation choice -
  overland grids are the large ones
  and surface cost scales with tile
  pixels; indoor grids stay small so
  they afford 64. Tile art is
  cross-world shared - no world
  bucketing. Open: committing binaries
  vs gitignored asset dir (lean:
  commit - authored content, small).
  R966 LANDED 2026-10-31 at dfb11f1
  (the record rides at Round state;
  the charter doc lives in the repo
  at doc/content_structure.md). NEXT
  CANDIDATE: R967 the tree creation
  round - the content/ skeleton via
  data_files .keeps (engine makedirs)
  plus the monsters git-mv (content/
  monsters/{a..z}, five touch lines:
  adnd1.cpp x2, regtest x2,
  normalize_registry x1), the census
  proving 1313 loaded from the new
  path. R967 LANDED 2026-10-31 at b259495
  (the record rides at Round state;
  the v1 RED lessons - the
  call-site scan rule and the
  R420 all-or-nothing re-land - are
  seated in the record).
  Bucketing
  convention leaning: one record per file
  everywhere, per-domain bucket choice
  (letters for big pools like npcs,
  category folders for items).
  RULES RECORD SHAPE ADJUDICATED
  (Curtiss, 2026-10-31): one Lua
  record per PIN ROUND (multiple
  files per bucket - a bucket holds
  many records, the file is the
  adjudication; NOT one big book
  file - the lossless diff back and
  the battery's mutant surface stay
  per-round), buckets by SOURCE BOOK
  (content/rules/{phb,dmg,ddg,
  dragon,...}/{prefix}.lua), records
  are mechanical translations of the
  spec JSONs (the spec stays the
  adjudicated record, DO NOT
  hand-edit, the translation back is
  the proof), battery derives from
  records (rverify semantics), and
  THE DRAGON SET PROMOTES FIRST
  (issues 2-26, 79 walked rounds
  with models - the R969
  corrected measure; the R968 128
  was a grep over-match).
  BATCH SIZING ADJUDICATED
  (Curtiss, 2026-10-31): as many
  records per round as byte
  weight allows, not one per
  round - batches ride the issue
  groups where the canvas stays
  workable (~130KB spec ceiling
  proven at R969).
  R969 LANDED 2026-10-31 at
  7c55ce7 (the record rides at
  Round state; the verify at the
  fresh sha was already 13 with
  the 8 records on disk).
  R970 LANDED 2026-10-31 at
  9ebd433 (the record rides at
  Round state; the verify at
  the fresh sha was already 8
  with all 11 records on disk).
  NEXT CANDIDATE: R971 the
  Dragon promotion batch three
  - issue 4 complete, THE
  BATCH CEILING RAISED
  (Curtiss, 2026-10-31): whole
  issue groups ride per round
  now (the specs run small).
  R971 LANDED 2026-10-31 at
  f62acfc (the record rides at
  Round state; the verify at
  the fresh sha was already 9
  with all 15 records on disk).
  R972 LANDED 2026-10-31 at
  30ee5de (the record rides at
  Round state; the verify at
  the fresh sha was already 13
  with all 23 records on disk).
  R973 LANDED 2026-10-31 at
  e2d6a6f (the record rides at
  Round state; the verify at
  the fresh sha was already 12
  with all 30 records on disk).
  R974 LANDED 2026-10-31 at
  41fb76c (the record rides at
  Round state; the verify at
  the fresh sha was already 10
  with all 35 records on disk).
  R975 LANDED 2026-10-31 at
  4e045bc (the record rides at
  Round state; the verify at
  the fresh sha was already 10
  with all 40 records on disk).
  R976 LANDED 2026-10-31 at
  4360209 (the record rides at
  Round state; the verify at
  the fresh sha was already 9
  with all 44 records on disk).
  R977 LANDED 2026-10-31 at
  4b50188 (the record rides at
  Round state; the verify at
  the fresh sha was already 11
  with all 50 records on disk -
  the halfway mark). NEXT
  R978 LANDED 2026-10-31 at
  15c273a (the record rides at
  Round state; the verify at
  the fresh sha was already 11
  with all 56 records on disk).
  R979 LANDED 2026-10-31 at
  746a2d2 (the record rides at
  Round state; the verify at
  the fresh sha was already 16
  with all 67 records on disk).
  R980 LANDED 2026-10-31 at
  b10fd95 (the record rides at
  Round state; the verify at
  the fresh sha was already 17
  with all 79 records on disk -
  THE SET CLOSED).
  THE 79-ROUND DRAGON SET IS
  FULLY PROMOTED: 79 of 79,
  none remaining, 1970587 bytes
  of Lua across twelve batches
  R969-R980 under the R968
  format, every record promoted
  mechanically and parsed back
  equal.
  THE OA ARC OPENS (Curtiss, 2026-10-31, "Go OA"):
  ALL 160 OA pin headers (rules/oaNNN.h, rounds
  R614-R773, ~1.79MB C++) promote as rules records
  under content/rules/oa/ - spells and monsters
  re-promoted as rules records too, not just the 100
  core. NAMING: round-prefix records, one record per
  pin round (oa614.lua ... oa773.lua, the Dragon
  precedent). BATCH SIZING: fewest rounds at the
  ~350KB clipboard cap - measured 2,334,407 bytes Lua
  total, packed 8 batches at the 325KB Lua cut.
  DOCTRINE: promotion-from-headers - the header IS
  the adjudicated record (the doc paragraph rides
  batch one as a file_patch to doc/
  rules_record_format.md); the builder extracts the
  model mechanically, the audit conditions convert to
  bad-detector examples evaluated Python-side
  (fn() != v, !fn() -> != 1, fn(a) != v, || -> or),
  local-array audits stay behind the C++ pins (the
  headers remain the firewall). COVERAGE PROOF: every
  fn in an example - 5,584 fns total (3,986 consts,
  940 bools, 654 switches, 4 chains), uncovered fns
  get generated fail-on-wrong examples; all 160
  records evaluated GREEN and parse-back equal.
  - R981 LANDED 2026-10-31 at
  0242777: THE OA PROMOTION
  BATCH ONE - rounds R614 through
  R624 complete, the OA set opener
  - 11 records, 778 model items,
  305671 bytes Lua, every record
  parsed back equal. Prefix oa1 (freedom verified: no rules/
  oa1.h, no oa1[A-Z] symbols). 4 consts + 3 bools:
  oa1BatchRecords=11, oa1ModelItems=778,
  oa1CumulativeRecords=11, oa1SetRoundsRemaining=
  149, oa1RecordsPromoted, oa1DiffBackGreen,
  oa1R614ThroughR624Complete. The file_patch seats
  the promotion-from-headers paragraph in doc/
  rules_record_format.md. Census 903->904; no
  flips; gap report 026 stays 3/0. Double-run
  applied 17/already 17; rverify GREEN 7 mutants
  0 missed at base b10fd95; spec 333809 bytes md5
  3307d43be481c4aaf375d68b318f675b, canvas
  r981-spec (body byte-exact). The R980 record is
  the prev_record (seated into the repo seed).
  LANDED: pushed b10fd95..0242777, census 903->
  904; the fresh tarball at 0242777 verified - 11/
  11 records on disk byte-matching the spec, the
  header/audit/include/seed/doc-patch all in
  place. NEXT
  CANDIDATE: R982 batch two - R625-R644, 20
  records, 618 items, 322776 bytes Lua; six more
  batches after it (R983 R645-R670 26 rec, R984
  R671-R694 24 rec, R985 R695-R712 18 rec, R986
  R713-R726 14 rec, R987 R727-R759 33 rec, R988
  R760-R773 14 rec - the set closer). WAIT FOR GO.

  - R982 LANDED 2026-10-31 at
  9c4b925: THE OA PROMOTION BATCH TWO -
  rounds R625 through R644 complete - 20
  records, 618 model items, 322857 bytes
  Lua, every record parsed back equal.
  Prefix oa2 (freedom verified: no rules/
  oa2.h, no oa2[A-Z] symbols). 4 consts +
  3 bools: oa2BatchRecords=20,
  oa2ModelItems=618, oa2CumulativeRecords=
  31, oa2SetRoundsRemaining=129,
  oa2RecordsPromoted, oa2DiffBackGreen,
  oa2R625ThroughR644Complete. Census
  904->905; no flips; gap report 026
  stays 3/0. Double-run applied 25/
  already 25; rverify GREEN 7 mutants
  0 missed at base 0242777; spec 349066
  bytes md5 0ada0d2e55604c40f7d8fedf26
  6ffbff, canvas r982-spec (body
  byte-exact). The R981 record is the
  prev_record (seated into the repo seed).
  LANDED: pushed 0242777..9c4b925, census
  904->905; the fresh tarball at 9c4b925
  verified - 20/20 records on disk
  byte-matching the spec, the header/
  audit/include/seed all in place, 31
  records on disk (628,528 bytes Lua
  cumulative).
  TOOLING NOTE (the env reset between
  turns): oa_lib.py was rebuilt from the
  landed batch-one records - the model
  extracts ENTIRELY from the pin header
  (title, provenance, fn values, comments)
  with the spec JSON as a name-level
  cross-check; the examples convert the
  audit file conditions clause by clause
  ('||' clauses rejoin on '  or ', the
  name regexes eat one leading space,
  '!fn()' gains one) and reject any
  condition with leftover identifiers;
  uncovered switch cases generate the
  'switch census' coverage chunks (8 per
  example, default included). The rebuilt
  lib byte-matches ALL ELEVEN landed
  batch-one records before batch two was
  built. NEXT CANDIDATE: R983 batch
  three - R645-R670, 26 records, then
  R984 R671-R694 24 rec, R985 R695-R712
  18 rec, R986 R713-R726 14 rec, R987
  R727-R759 33 rec, R988 R760-R773 14
  rec - the set closer. WAIT FOR GO.

  - R983 LANDED 2026-10-31 at 8a7d805: The
    OA promotion batch three (census 906)
    - R645-R670, 26 records, 482 model
    items, 316,123 bytes Lua, prefix oa3.
    LANDED: pushed 9c4b925..8a7d805,
    census 905->906; the fresh tarball at
    8a7d805 verified - 26/26 records on
    disk byte-matching the spec, the
    header (4 consts + 3 bools), the
    regtest includes (oa3.h at line 687,
    the r983_batch.h audit in the
    descending audit order), the gap 3/0
    no-flips and the seed all in place,
    57 records on disk (944,651 bytes Lua
    cumulative). NEXT: R984 R671-R694 24
    rec, R985 R695-R712 18 rec, R986
    R713-R726 14 rec, R987 R727-R759 33
    rec, R988 R760-R773 14 rec - the set
    closer. WAIT FOR GO.

  - R984 LANDED 2026-11-01 at b4b80c4: The
    OA promotion batch four (census 907)
    - R671-R694, 24 records, 515 model
    items, 316,647 bytes Lua, prefix oa4.
    LANDED: pushed 8a7d805..b4b80c4,
    census 906->907; the fresh tarball at
    b4b80c4 verified - 24/24 records on
    disk byte-matching the spec, the
    header (4 consts + 3 bools), the
    regtest includes (oa4.h right after
    oa3.h at line 688, the r984_batch.h
    audit in the descending audit order),
    the gap 3/0 no-flips and the seed all
    in place, 81 records on disk (1,261,298
    bytes Lua cumulative). NEXT: R985
    R695-R712 18 rec, R986 R713-R726 14
    rec, R987 R727-R759 33 rec, R988
    R760-R773 14 rec - the set closer.
    WAIT FOR GO.

  - R985 LANDED 2026-11-01 at bbda51e: The
    OA promotion batch five (census 908)
    - R695-R712, 18 records, 825 model
    items, 299,242 bytes Lua, prefix oa5.
    LANDED: pushed b4b80c4..bbda51e,
    census 907->908; the fresh tarball at
    bbda51e verified - 18/18 records on
    disk byte-matching the spec, the
    header (4 consts + 3 bools), the regtest
    includes, the gap 3/0 no-flips and the
    seed all in place, 99 records on disk
    (1,560,540 bytes Lua cumulative).
    DEFECT FOUND AT LANDING: the regtest
    oa5.h include comment says "batch
    four" not "batch five" (the builder
    left the include_comment stale; every
    other batch-five field is correct) -
    fold the one-line regtest comment fix
    into R986's file_patches unless
    Curtiss rules otherwise. NEXT: R986
    R713-R726 14 rec, R987 R727-R759 33
    rec, R988 R760-R773 14 rec - the set
    closer. WAIT FOR GO.

  - R986 LANDED 2026-11-01 at f2c349c: The
    OA promotion batch six (census 909)
    - R713-R726, 14 records, 1,141 model
    items, 319,990 bytes Lua, prefix oa6.
    LANDED: pushed bbda51e..f2c349c,
    census 908->909; the fresh tarball at
    f2c349c verified - 14/14 records on
    disk byte-matching the spec, the
    header (4 consts + 3 bools), the
    regtest includes (the oa6.h include
    at line 690; the oa5 include comment
    REPAIRED in-regtest - "batch five"
    now correct, the R985 defect closed
    via the file_patch), the r986_batch.h
    audit in the descending audit order,
    the gap 3/0 no-flips and the seed all
    in place, 113 records on disk
    (1,880,530 bytes Lua cumulative).
    NEXT: R987 R727-R759 33 rec, R988
    R760-R773 14 rec - the set closer.
    WAIT FOR GO.

  - R987 LANDED 2026-11-01 at 6f02fe9: The
    OA promotion batch seven (census 910)
    - R727-R759, 33 records, 897 model
    items, 322,729 bytes Lua, prefix oa7.
    LANDED: pushed f2c349c..6f02fe9,
    census 909->910; the fresh tarball at
    6f02fe9 verified - 33/33 records on
    disk byte-matching the spec, the
    header (4 consts + 3 bools), the
    regtest includes (the oa7.h include at
    line 691 right after oa6.h; the
    r987_batch.h audit at the top of the
    descending audit order), the gap 3/0
    no-flips and the seed all in place,
    146 records on disk (2,203,259 bytes
    Lua cumulative). NEXT: R988 R760-R773
    14 rec - the set closer. WAIT FOR GO.

  - R988 LANDED 2026-11-01 at 9566e3e: The
    OA promotion batch eight (census 911) -
    THE SET CLOSER - R760-R773, 14 records,
    328 model items, 131,789 bytes Lua,
    prefix oa8 (bool oa8SetComplete). LANDED:
    pushed 6f02fe9..9566e3e, census 910->911;
    the fresh tarball at 9566e3e verified -
    14/14 records on disk byte-matching the
    spec, the header (4 consts + 3 bools),
    the regtest includes (the oa8.h include
    at line 692 right after oa7.h; the
    r988_batch.h audit at the top of the
    descending audit order), the gap 3/0
    no-flips and the seed all in place.
    THE 160-ROUND OA SET IS FULLY PROMOTED:
    160 of 160, none remaining, 2,335,048
    bytes of Lua across eight batches
    R981-R988 under the R968 format, every
    record promoted mechanically and parsed
    back equal. NEXT: the next arc awaits
    Curtiss's call. WAIT FOR GO.

  - R989 LANDED 2026-11-01 at 7fef137a:
    The WSG promotion batch one (census
    912) - THE ARC OPENER - R425-R454, 29
    records, 723 model items, 317,767
    bytes Lua, prefix wsg1 (bool
    wsg1R425ThroughR454Complete). LANDED:
    pushed 9566e3e..7fef137a, census
    911->912; the fresh tarball at 7fef137a
    verified - 29/29 records on disk
    byte-matching the spec, the header (4
    consts + 3 bools), the regtest includes
    (the wsg1.h include at line 693 right
    after the R988 oa8.h line; the
    r989_batch.h audit at line 4803 above
    r988_batch.h in the descending audit
    order), the gap report byte-identical
    base-to-HEAD (the 186/0 engine census,
    no flips) and the seed all in place
    (the R988 record seated before the
    maintenance anchor), rverify GREEN at
    base 9566e3e (double-run, battery 7
    mutants 0 missed), spec md5 unchanged.
    THE WSG ARC IS OPEN: cumulative 29 of
    the 77-round set, 48 remaining, 317,767
    bytes of Lua on disk. NEXT: R990
    R455-R474, 20 rec. WAIT FOR GO.

  - R990 LANDED 2026-11-01 at af4d851d:
    The WSG promotion batch two (census
    913) - R455-R474, 20 records, 625
    model items, 302,856 bytes Lua,
    prefix wsg2 (bool
    wsg2R455ThroughR474Complete). LANDED:
    pushed 7fef137a..af4d851d, census
    912->913; the fresh tarball at
    af4d851d verified - 20/20 records on
    disk byte-matching the spec (and the
    batch-one 29/29 still byte-matching),
    the header (4 consts + 3 bools), the
    regtest includes (the wsg2.h include
    at line 694 right after wsg1.h; the
    r990_batch.h audit at line 4804
    above r989_batch.h, descending), the
    gap report byte-identical base-to-
    HEAD (no flips), the seed seated (the
    R989 record, 26 lines, before the
    maintenance anchor), rverify GREEN at
    base 7fef137a (double-run, battery 7
    mutants 0 missed), spec md5 unchanged.
    Cumulative 49 of the 77-round set, 28
    remaining, 620,623 bytes of Lua across
    49 records on disk. NEXT: R991
    R475-R489, 15 rec. WAIT FOR GO.

  - R991 LANDED 2026-11-01 at c29cde76:
    The WSG promotion batch three (census
    914) - R475-R489, 15 records, 960
    model items, 302,847 bytes Lua,
    prefix wsg3 (bool
    wsg3R475ThroughR489Complete). LANDED:
    pushed af4d851d..c29cde76, census
    913->914; the fresh tarball at
    c29cde76 verified - 15/15 records on
    disk byte-matching the spec (and
    batches one-two 49/49 still byte-
    matching), the header (4 consts + 3
    bools), the regtest includes (the
    wsg3.h include at line 695 right
    after wsg2.h; the r991_batch.h audit
    at line 4805 above r990_batch.h,
    descending), the gap report byte-
    identical base-to-HEAD (no flips),
    the seed seated (the R990 record, 26
    lines), rverify GREEN at base
    af4d851d (double-run, battery 7
    mutants 0 missed), spec md5 unchanged.
    Cumulative 64 of the 77-round set, 13
    remaining, 923,470 bytes of Lua
    across 64 records on disk. NEXT: R992
    R490-R496, 7 rec. WAIT FOR GO.

  - R992 LANDED 2026-11-01 at 2d15a45b:
    The WSG promotion batch four (census
    915) - R490-R496, 7 records, 1,035
    model items, 317,582 bytes Lua,
    prefix wsg4 (bool
    wsg4R490ThroughR496Complete). LANDED:
    pushed c29cde76..2d15a45b, census
    914->915; the fresh tarball at
    2d15a45b verified - 7/7 records on
    disk byte-matching the spec (and
    batches one-three 64/64 still byte-
    matching), the header (4 consts + 3
    bools), the regtest includes (the
    wsg4.h include at line 696 right
    after wsg3.h; the r992_batch.h audit
    at line 4806 above r991_batch.h,
    descending), the gap report byte-
    identical base-to-HEAD (no flips),
    the seed seated (the R991 record, 26
    lines), rverify GREEN at base
    c29cde76 (double-run, battery 7
    mutants 0 missed), spec md5 unchanged.
    Cumulative 71 of the 77-round set, 6
    remaining, 1,241,052 bytes of Lua
    across 71 records on disk. NEXT: R993
    R497-R502, 6 rec - THE SET CLOSER.
    WAIT FOR GO.

  - R993 LANDED 2026-11-01 at b19d04ef:
    The WSG promotion batch five (census
    916) - THE SET CLOSER - R497-R502,
    6 records, 440 model items, 128,521
    bytes Lua, prefix wsg5 (bool
    wsg5SetComplete). LANDED: pushed
    2d15a45b..b19d04ef, census 915->916;
    the fresh tarball at b19d04ef
    verified - 6/6 records on disk
    byte-matching the spec (and batches
    one-four 71/71 still byte-matching),
    the header (4 consts + 3 bools), the
    regtest includes (the wsg5.h include
    at line 697 right after wsg4.h; the
    r993_batch.h audit at line 4807
    above r992_batch.h, descending), the
    gap report byte-identical base-to-
    HEAD (no flips), the seed seated
    (the R992 record, 27 lines), rverify
    GREEN at base 2d15a45b (double-run,
    battery 7 mutants 0 missed), spec md5
    unchanged. THE 77-ROUND WSG SET IS
    FULLY PROMOTED: 77 of 77, none
    remaining, 1,369,573 bytes of Lua
    across five batches R989-R993 under
    the R968 format, every record
    promoted mechanically and parsed back
    equal. NEXT: the next arc awaits
    Curtiss's call. WAIT FOR GO.

  - R994 LANDED 2026-11-01 at 4ff6aa06:
    The DSG promotion batch one (census
    917) - THE ARC OPENER - R503-R510,
    8 records, 1,087 model items, 313,629
    bytes Lua, prefix dsg1 (bool
    dsg1R503ThroughR510Complete). LANDED:
    pushed b19d04ef..4ff6aa06, census
    916->917; the fresh tarball at
    4ff6aa06 verified - 8/8 records on
    disk byte-matching the spec (and the
    WSG set 77/77 still byte-matching),
    the header (4 consts + 3 bools), the
    regtest includes (the dsg1.h include
    at line 698 right after wsg5.h; the
    r994_batch.h audit at line 4808
    above r993_batch.h, descending), the
    gap report byte-identical base-to-
    HEAD (155/0, no flips), the seed
    seated (the R993 record, 29 lines),
    rverify GREEN at base b19d04ef
    (double-run, battery 7 mutants 0
    missed), spec md5 unchanged. THE DSG
    ARC IS OPEN: cumulative 8 of the
    60-round set (all spec-JSON rounds),
    52 remaining, 313,629 bytes of Lua on
    disk; five batches planned (R995
    R511-R527 next). NEXT: R995 R511-R527,
    16 rec. WAIT FOR GO.

  - R995 LANDED 2026-11-01 at
    43e25146: The DSG promotion batch
    two (census 918) - R511-R527, 16
    records (R515 absent), 660 model
    items, 306,698 bytes Lua, prefix
    dsg2 (bool
    dsg2R511ThroughR527Complete).
    LANDED: pushed 4ff6aa06..43e25146,
    census 917->918; the fresh tarball
    at 43e25146 verified - 16/16
    records on disk byte-matching the
    spec (and the earlier batches
    85/85 still byte-matching), the
    header (4 consts + 3 bools), the
    regtest includes (the dsg2.h
    include at line 699 right after
    dsg1.h; the r995_batch.h audit at
    line 4809 above r994_batch.h,
    descending), the gap report
    byte-identical base-to-HEAD (155/0,
    no flips), the seed seated (the
    R994 record, 28 lines), rverify
    GREEN at base 4ff6aa06 (double-
    run, battery 7 mutants 0 missed),
    spec md5 unchanged. Cumulative 24
    of the 60-round set, 36 remaining,
    620,327 bytes of Lua on disk.
    NEXT: R996 R528-R541, 14 rec.
    WAIT FOR GO.

  - R996 LANDED 2026-11-01 at
    4570c7b4: The DSG promotion batch
    three (census 919) - R528-R541, 14
    records, 632 model items, 315,935
    bytes Lua, prefix dsg3 (bool
    dsg3R528ThroughR541Complete).
    LANDED: pushed 43e25146..4570c7b4,
    census 918->919; the fresh tarball
    at 4570c7b4 verified - 14/14
    records on disk byte-matching the
    spec (and the earlier batches
    R989-R995 101/101 still
    byte-matching, the WSG 77 on
    disk), the header (4 consts + 3
    bools), the regtest includes (the
    dsg3.h include at line 700 right
    after dsg2.h; the r996_batch.h
    audit at line 4810 above
    r995_batch.h, descending), the
    gap report byte-identical base-to-
    HEAD (155/0, no flips), the seed
    seated (the R995 record, 29
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base 43e25146 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged. Cumulative 38 of
    the 60-round set, 22 remaining,
    936,262 bytes of Lua on disk.
    NEXT: R997 R542-R556, 15 rec.
    WAIT FOR GO.

  - R997 LANDED 2026-11-01 at
    948f84f7: The DSG promotion batch
    four (census 920) - R542-R556, 15
    records, 630 model items, 281,080
    bytes Lua, prefix dsg4 (bool
    dsg4R542ThroughR556Complete).
    LANDED: pushed 4570c7b4..948f84f7,
    census 919->920; the fresh tarball
    at 948f84f7 verified - 15/15
    records on disk byte-matching the
    spec (and the earlier batches
    R989-R996 115/115 still
    byte-matching, the WSG 77 on
    disk), the header (4 consts + 3
    bools), the regtest includes (the
    dsg4.h include at line 701 right
    after dsg3.h; the r997_batch.h
    audit at line 4811 above
    r996_batch.h, descending), the
    gap report byte-identical base-to-
    HEAD (155/0, no flips), the seed
    seated (the R996 record, 31
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base 4570c7b4 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged. Cumulative 53 of
    the 60-round set, 7 remaining,
    1,217,342 bytes of Lua on disk.
    NEXT: R998 R557-R563, 7 rec - THE
    SET CLOSER (cumulative 60,
    remaining 0). WAIT FOR GO.' again -
    rewrapped whole (the LANDED notes
    must keep the marker on one line;
    the builders key on it). The spec
    rides tools/spec_r997.json (298,587
    bytes, md5 b36f993f1ec73718b5045ba2ed59a736);
    engine double-run green (applied 20 /
    already 20); rverify at 4570c7b4
    GREEN (7 mutants, 0 missed); includes
    verified (the dsg4.h include at line
    701 right after dsg3.h; the
    r997_batch.h audit at line 4811 above
    r996_batch.h, descending); gap 155/0
    no-flips; seed seated (prev R996).
    Cumulative 53 of the 60-round DSG
    set, 7 remaining. NEXT after land:
    R998 R557-R563, 7 rec - THE SET
    CLOSER (cumulative 60, remaining 0).
    WAIT FOR GO.

  - R998 LANDED 2026-11-01 at
    fab699d4: The DSG promotion batch
    five (census 921) - R557-R563, 7
    records, 82 model items, 49,790
    bytes Lua, prefix dsg5 (bool
    dsg5SetComplete, const
    dsg5SetRoundsRemaining = 0) - THE
    SET CLOSER. LANDED: pushed
    948f84f7..fab699d4, census 920->921;
    the fresh tarball at fab699d4
    verified - 7/7 records on disk
    byte-matching the spec (and the
    earlier batches R989-R997 130/130
    still byte-matching, the WSG 77
    on disk), the closer header (4
    consts + 3 bools, remaining 0,
    cumulative 60), the regtest
    includes (the dsg5.h include at
    line 702 right after dsg4.h; the
    r998_batch.h audit at line 4812
    above r997_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (155/0, no flips),
    the seed seated (the R997 record,
    32 lines), rverify GREEN at base
    948f84f7 (double-run, battery 7
    mutants 0 missed), spec md5
    unchanged, the total DSG Lua
    1,267,132 bytes on disk. THE DSG
    SET IS CLOSED: content/rules/dsg/
    holds the full 60 records
    (R503-R563, R515 absent from the
    regtest map), zero remaining,
    five batches R994-R998. THE DSG
    ARC IS CLOSED - next per the
    Curtiss call. WAIT FOR GO.
  - R999 LANDED 2026-11-01 at
    6df2f3a8: The UA promotion batch
    one (census 922) - R333-R348, 13
    records, 970 model items, 304,979
    bytes Lua, prefix ua1 (bool
    ua1R333ThroughR348Complete).
    LANDED: pushed fab699d4..6df2f3a8,
    census 921->922; the fresh tarball
    at 6df2f3a8 verified - 13/13
    records on disk byte-matching the
    spec (the dragon 79, the WSG 77,
    the DSG 60 and the OA 160 on disk
    unchanged), the batch header (4
    consts + 3 bools, remaining 63,
    cumulative 13), the regtest
    includes (the ua1.h include at
    line 703 right after dsg5.h; the
    r999_batch.h audit at line 4813
    above r998_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R998 record, 36
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base fab699d4 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged. Cumulative 13 of
    the 76-round UA set, 63 remaining,
    304,979 bytes of UA Lua on disk.
    NEXT: ua2 R349-R359, 11 records.
    WAIT FOR GO.
  - R1000 LANDED 2026-11-01 at
    9cb10b12: The UA promotion batch
    two (census 923) - R349-R359, 11
    records, 1201 model items,
    278,958 bytes Lua, prefix ua2
    (bool ua2R349ThroughR359Complete).
    LANDED: pushed 6df2f3a8..9cb10b12,
    census 922->923; the fresh tarball
    at 9cb10b12 verified - 11/11
    records on disk byte-matching the
    spec (the ua set now 24; the dragon
    79, the WSG 77, the DSG 60 and the
    OA 160 on disk unchanged), the
    batch header (4 consts + 3 bools,
    remaining 52, cumulative 24), the
    regtest includes (the ua2.h include
    at line 704 right after ua1.h; the
    r1000_batch.h audit at line 4813
    above r999_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R999 record, 32
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base 6df2f3a8 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged
    (eafde8d20147923d678d9ea7c8150d3d).
    Cumulative 24 of the 76-round UA
    set, 52 remaining, 583,937 bytes of
    UA Lua on disk. NEXT: ua3
    R360-R364, 5 records (the
    multi-header rounds begin - the
    headers' pools merge).
    WAIT FOR GO.

  - R1001 LANDED 2026-11-01 at
    44b0b479: The UA promotion batch
    three (census 924) - R360-R364, 5
    records, 1229 model items,
    273,078 bytes Lua, prefix ua3
    (bool ua3R360ThroughR364Complete).
    LANDED: pushed 9cb10b12..44b0b479,
    census 923->924; the fresh tarball
    at 44b0b479 verified - 5/5 records
    on disk byte-matching the spec
    (the ua set now 29; the dragon 79,
    the WSG 77, the DSG 60 and the OA
    160 on disk unchanged), the batch
    header (4 consts + 3 bools,
    remaining 47, cumulative 29), the
    regtest includes (the ua3.h include
    at line 705 right after ua2.h; the
    r1001_batch.h audit at line 4815
    above r1000_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R1000 record, 36
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base 9cb10b12 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged
    (d739986e52aba22bc11fa5606ffe378e).
    THE MULTI-HEADER ROUNDS LANDED:
    R360 (2 headers), R361 (1), R362
    (2), R363 (3), R364 (3) - the
    headers' pools merge into one
    record per round, first of their
    kind on disk. Cumulative 29 of the
    76-round UA set, 47 remaining,
    857,015 bytes of UA Lua on disk.
    NEXT: ua4 R365-R380, 16 records
    (the struct-table rounds R409-R411
    ride here - inspect the headers
    before building). WAIT FOR GO.

  - R1002 LANDED 2026-11-01 at
    2bacb3a0: The UA promotion batch
    four (census 925) - R365-R380, 16
    records, 1355 model items,
    277,802 bytes Lua, prefix ua4
    (bool ua4R365ThroughR380Complete).
    LANDED: pushed 44b0b479..2bacb3a0,
    census 924->925; the fresh tarball
    at 2bacb3a0 verified - 16/16
    records on disk byte-matching the
    spec (the ua set now 45; the dragon
    79, the WSG 77, the DSG 60 and the
    OA 160 on disk unchanged), the
    batch header (4 consts + 3 bools,
    remaining 31, cumulative 45), the
    regtest includes (the ua4.h include
    at line 706 right after ua3.h; the
    r1002_batch.h audit at line 4816
    above r1001_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R1001 record, 41
    lines, before the Knowledge
    maintenance anchor), rverify GREEN
    at base 44b0b479 (double-run,
    battery 7 mutants 0 missed), spec
    md5 unchanged
    (3da4accd8a92a89c9c1f3d080f5d3c97).
    THE TREASURE-PROSE BLOCK LANDED:
    the potions, scrolls, rings, rods,
    staves and wands prose (R376-R380)
    plus the treasure dial (R374) and
    eleven more, three multi-header
    rounds (R365 four headers, R366
    four, R367 two - the pools merge).
    Cumulative 45 of the 76-round UA
    set, 31 remaining, 1,134,817 bytes
    of UA Lua on disk. NEXT: ua5
    R381-R390, 10 records (inspect the
    headers before building). WAIT FOR GO.

  - R1003 LANDED 2026-11-01 at
    175c3c47: The UA promotion batch
    five (census 926) - R381-R390,
    10 records, 1350 model items,
    275,277 bytes Lua, prefix ua5
    (bool ua5R381ThroughR390Complete).
    LANDED: pushed 2bacb3a0..175c3c47,
    census 925->926; the fresh tarball
    at 175c3c47 verified - 10/10
    records on disk byte-matching the
    spec (the ua set now 55; the
    dragon 79, the WSG 77, the DSG 60
    and the OA 160 on disk unchanged),
    the batch header (4 consts + 3
    bools, remaining 21, cumulative
    55), the regtest includes (the
    ua5.h include at line 707 right
    after ua4.h; the r1003_batch.h
    audit at line 4817 above
    r1002_batch.h, descending), the
    gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R1002 record, 41
    lines, before the Knowledge
    maintenance anchor), rverify
    GREEN at base 2bacb3a0
    (double-run, battery 7 mutants 0
    missed), spec md5 unchanged
    (86d496c96467003cfc04b3a05810db0a).
    THE MISC-PROSE AND APPENDIX BLOCK
    LANDED: the misc magic items
    prose parts one through six
    (R381-R386), the armor and swords
    prose (R387), the misc weapons
    prose (R388), the weaponless
    combat appendix Q (R389) and the
    non-lethal combat appendix R
    (R390) - all ten single-header;
    the char-return letter pins and
    the one multi-line signature ride
    as header pins, the r390 audit's
    99 conditions ride as one example.
    Cumulative 55 of the 76-round UA
    set, 21 remaining, 1,410,094
    bytes of UA Lua on disk. NEXT: ua6
    R391-R423, 16 records (the
    struct-table rounds R409-R411
    ride here - inspect the headers
    before building). WAIT FOR GO.

  - R1004 LANDED 2026-11-01 at
    6a4ef0c0: The UA promotion batch
    six (census 927) - R391-R423,
    16 records, 366 model items,
    242,648 bytes Lua, prefix ua6
    (bool ua6R391ThroughR423Complete).
    LANDED: pushed 175c3c47..6a4ef0c0,
    census 926->927; the fresh tarball
    at 6a4ef0c0 verified - 16/16
    records on disk byte-matching the
    spec (the ua set now 71; the
    dragon 79, the WSG 77, the DSG 60
    and the OA 160 on disk unchanged),
    the batch header (4 consts + 3
    bools, remaining 5, cumulative 71),
    the regtest includes (the ua6.h
    include at line 708 right after
    ua5.h; the r1004_batch.h audit at
    line 4818 above r1003_batch.h,
    descending), the gap report
    byte-identical base-to-HEAD (102/1,
    the one open line the legend, no
    flips), the seed seated (the R1003
    record, 50 lines, before the
    Knowledge maintenance anchor),
    rverify GREEN at base 175c3c47
    (double-run, battery 7 mutants 0
    missed), spec md5 unchanged
    (5b0690aeb559f91782b90ba6664bf99a).
    THE PLAYERS-TABLES, CANTRIP AND
    APPENDIX S BLOCK LANDED: the pole
    arm nomenclature (R391), the
    players tables (R392, the one
    multi-header round), the treasure
    row bodies (R395), the Appendix S
    block (R406-R411, R423 - the
    struct-table rounds R409-R411
    ride here, the struct accessors
    as header pins) and the six
    cantrip families (R412-R417).
    Cumulative 71 of the 76-round UA
    set, 5 remaining, 1,652,742 bytes
    of UA Lua on disk. NEXT: ua7
    R786-R790, 5 records (the deity
    prose parts one through five), THE
    SET CLOSER - spec-round records,
    SetComplete, remaining 0.
    WAIT FOR GO.

  - R1005 LANDED 2026-11-01 at
    e4b7a8b5: The UA promotion batch
    seven (census 928) - R786-R790,
    THE SET CLOSER - 5 records (the
    deity prose parts one through
    five: R786 ua7 dwarven, R787
    ua7 elven, R788 ua7 halfling,
    R789 ua7 gnomish, R790 ua7
    orcish), 487 model items, 132,790
    bytes Lua, prefix ua7 (bool
    ua7SetComplete). LANDED: pushed
    6a4ef0c0..e4b7a8b5, census
    927->928; the fresh tarball at
    e4b7a8b5 verified - 5/5 records
    on disk byte-matching the spec
    (R786 27,357B 43c/60b, R787
    27,654B 47c/54b, R788 27,658B
    53c/52b, R789 25,300B 40c/55b,
    R790 24,821B 32c/51b; the ua set
    now 76; the dragon 79, the WSG 77,
    the DSG 60 and the OA 160 on disk
    unchanged), the batch header (5
    consts + 3 bools, remaining 0,
    cumulative 76), the regtest
    includes (the ua7.h include at
    line 709 right after ua6.h; the
    r1005_batch.h audit at line 4819
    above r1004_batch.h, descending),
    the gap report byte-identical
    base-to-HEAD (102/1, the one open
    line the legend, no flips), the
    seed seated (the R1004 record, 48
    lines, before the LAST Knowledge
    maintenance anchor - the file has
    a TOC-style earlier occurrence,
    compare against rfind), rverify
    GREEN at base 6a4ef0c0
    (double-run, battery 7 mutants 0
    missed), spec md5 unchanged
    (24eeb1fd51955223e087810636ef09a9).
    THE APPENDIX S DEITY PROSE
    LANDED: the dwarven five
    (Clanggedin, Vergadain, Dumathoin,
    Abbathor, Berronar), the elven,
    halfling, gnomish and orcish
    blocks - the dvpProseStaysOpen
    pin returns false at last, the
    five-part description-paragraph
    close complete, the stat-block
    numerics still R406/R783.
    Cumulative 76 of the 76-round UA
    set, 0 remaining, THE SET CLOSED,
    1,785,532 bytes of UA Lua on disk.
    THE UA PROMOTION ARC IS COMPLETE:
    R999-R1005, 76 records, the whole
    Unearthed Arcana book adjudicated
    and pinned; the next arc awaits
    the standing next-arc decision.
    WAIT FOR GO.
  - R1006 LANDED 2026-11-01 at
    76fd890d: The promotions mop
    round one - the registry
    never-load repair (census 929) -
    THE MOP OPENER, Curtiss's arc
    call after the UA set closed
    (all the promotion loose ends,
    one arc). 25 file_patches (NOT
    data_files - the R791 data_files
    class is idempotent by
    EXISTENCE, new files only; an
    overwrite repair rides the
    file_patches class, from = the
    raw-newline text body, to = the
    escaped body): the twenty-five
    Fiend Folio promotions of the
    R836-R842 arc repaired - each
    carried RAW NEWLINES inside its
    text field where the backslash-n
    escapes belong, the Lua loader
    dying unfinished-string, the
    R924 re-measure state
    1313/1338/25. 174 paragraph
    breaks escaped, ZERO ink
    touched (every unescape equals
    the landed bytes), 59,870 bytes
    of repaired Lua, prefix pm1
    (free; mop is taken by
    mop_print), header rules/pm1.h
    (7 consts + 3 bools), audit
    "R1006 promotions mop round one
    audit" above r1005_batch.h, the
    include after ua7.h. LANDED:
    pushed e4b7a8b5..76fd890d,
    census 928->929; the fresh
    tarball at 76fd890d verified -
    25/25 patches applied (from
    absent, to present), the
    whole-tree lexer scan 1338 of
    1338 clean, the seed seated (the
    R1005 record, 59 lines, before
    the LAST Knowledge maintenance
    anchor), the gap report
    byte-identical base-to-HEAD (mm2
    37/0, no flips), the UA set
    untouched (76 files, 1,785,532
    bytes), rverify GREEN at base
    e4b7a8b5 (restore, double-run,
    battery 10 mutants 0 missed),
    spec md5 unchanged
    (8d9a0d2a8b60d86fff7c6e071832d3b5).
    THE BATTERY LINE MOVES: loaded
    1338, errors 0 expected - the
    registry floor meets the file
    count for the first time since
    the R900 lesson; the historical
    snapshot pins (cfc 1311/1333/25,
    d21/l22/l23 1313/1338/25) stand
    as landed, the never-load
    doctrine retired. THE MOP
    REMAINING: the MM1 data-quality
    pass (the naive-era text fields,
    source tools/monsters.md -
    collation against the print
    voices, its own rounds); the
    rverify data_files candidate
    CLOSED (verified live at R1005),
    the lreg 65/473 pins standing as
    doctrine.
    WAIT FOR GO.
  - R1007 LANDED 2026-11-01 at
    fa62cde9: The promotions mop
    round two - the MM1 text
    completion (census 930) - the
    structural half of the naive-era
    data-quality pass. 136
    file_patches, every byte derived
    mechanically from
    tools/monsters.md (358
    @-records, 38 family headings):
    25 family carriers regain their
    own text_family prose, 61
    members gain the family prose,
    50 variants gain base or family
    prose; paragraphs escaped per
    the landed convention, non-ASCII
    raw (7 defs carry the U+FFFD
    naive-extraction glyph -
    collation suspects). TWO
    EXCLUDED: copper_dragon and
    monoclonius, the only MM1
    records with NO prose anywhere
    in the source (the Roc and Gas
    Spore precedent) - they await
    the print-voice collation half.
    LANDED: pushed
    76fd890d..fa62cde9, census
    929->930; the fresh tarball at
    fa62cde9 verified - 136/136
    patches applied (to-anchors once
    each), the lexer scan 1338 of
    1338 clean, the MM1 text census
    270 -> 406 of 408, the seed
    seated (the R1006 record, 70
    lines, before the LAST Knowledge
    maintenance anchor), the gap
    report byte-identical
    base-to-HEAD (mm2 37/0, no
    flips), the battery line holds
    loaded 1338 errors 0, rverify
    GREEN at base 76fd890d
    (restore, double-run, battery 11
    mutants 0 missed), spec md5
    unchanged
    (440886d92c761f6edab6778233dc895e).
    Prefix pm2, header
    rules/pm2.h (8 consts + 3
    bools), the include at regtest
    line 711 right after pm1.h, the
    r1007_batch.h audit at line
    4821 above r1006_batch.h.
    THE MOP REMAINING: the
    collation half of the MM1
    data-quality pass - the Copper
    Dragon and Monoclonius texts
    (print transcription, the Roc and
    Gas Spore precedent), the seven
    U+FFFD suspect glyphs, and the
    print-voice verification of the
    naive-era prose.
    WAIT FOR GO.
  - R1008 LANDED 2026-11-01 at
    3025a975: The promotions mop
    round three (census 931) - the MM1
    collation half, the two lost texts
    recovered and the mangled-glyph
    repair, the data-quality pass
    COMPLETE. TWO TEXT COMPLETIONS
    from the single readable voice
    (the archive.org 1977 print djvu
    scan; the second print scan is
    lending-restricted - the R923
    single-voice precedent, every
    OCR garble adjudicated case by
    case): copper_dragon (3
    paragraphs, p. 32) and
    monoclonius (1 paragraph, p.
    24), the two R1007 exclusions.
    GLYPH REPAIR across 222 defs:
    731 0x14 control codes -> the raw
    print em-dash (1 unspaced, the
    gold dragon weapons-fire), 77
    U+FFFD glyphs (10 degrees - the
    beholder 90/180/270/360 arcs,
    the frog 45-degree jumps; 67
    halves - sizes, hit dice, the
    1/2-inch breath-weapon cones and
    streams, djvu rendering the half
    glyph as % or Yz), 3 stat-field
    glyphs normalized to the landed
    convention (mold hitDice -> Nil,
    war dog noAppearing -> n/a). 444
    file_patches (442 voice-adjudicated
    glyph windows, every one simulated
    green and idempotent, plus the 2
    text completions), prefix pm3
    (verified free), header rules/pm3.h
    (9 consts + 3 bools), audit
    rules/audits/r1008_batch.h above
    r1007_batch.h, include after
    pm2.h, the seed seats the R1007
    LANDED record (61 lines) before
    the LAST Knowledge maintenance
    anchor. LANDED: pushed
    fa62cde9..3025a975, census
    930->931; the fresh tarball at
    3025a975 verified - 444/444
    patches applied (to present),
    residual glyph census 0, the
    includes ordered (pm3.h after
    pm2.h, r1008_batch.h above
    r1007_batch.h), the seed seated,
    the gap report byte-identical
    base-to-HEAD (mm2 37/0), spec md5
    unchanged
    (ec0fe8f376a65656fc337e12cb926944),
    the user preflight green (loaded
    1338, errors 0, the audit census
    clean). ONE LIVE LESSON, twice
    over: the copper text value first
    rode with RAW paragraph newlines
    (the R1006 unfinished-string class
    - the preflight caught it: loaded
    1337, errors 1); repaired to
    backslash-n escapes pre-landing,
    and the tree recovered BOTH times
    via the rverify restore (the
    poisoned-tree cure - overwrite
    from the base sha, delete the
    stray new files; the rm/git dance
    never needed, the R420 mixed
    applied/already abort cleared the
    same way). THE MM1 TEXT CENSUS
    READS 408 OF 408 - the
    naive-era data-quality pass
    complete, the battery line loaded
    1338 errors 0. THE MOP REMAINING:
    the arc's loose ends stand at
    census 931; the next rounds are
    Curtiss's call.
    WAIT FOR GO.

  - R1009 PREPARED 2026-11-01 at
    3025a975: the MM1 normalization
    batch one (census 932), MM1 part
    one of six, the letters a-f, 99
    defs rewritten to the full-field
    57-key emission of
    normalize_registry.py - string
    sentinel n/a, integer sentinel
    -1 - byte-exact against the
    repaired normalizer, the canonical
    FIELD_ORDER honored incl. text
    before familyText. 539 file
    patches: 538 monster windows (515
    insert sites / 2214 lines, 19
    whole-line reorder sites across
    23 defs, 4 move encodings - a
    delete-replace window spanning
    the moved line plus its
    neighbours with the paired
    insert, the engine cannot ship a
    bare delete) plus THE HEADLINE
    REPAIR: the normalize_registry.py
    REG glob pointed at
    monsters/monsters - census zero
    since R879; the two-line glob
    repair rides as the first patch.
    Engine double-run green at base
    3025a975b7b91f597d8ec0da08d2ca39f
    2eb9540 (applied 544/already 0 ->
    0/already 544), rverify GREEN
    (restore, double-run, battery
    bad=0, 14 mutants 0 missed), the
    apply-sim normalizer-exactness
    green and every to present
    exactly once. Spec
    tools/spec_r1009.json 345172
    bytes, md5
    05fa8de3bdb461d3fbcc915b38ed9f4a,
    seated on the r1009-spec canvas
    (canvas md5
    876113357982b8b1a5032fa4a00f97e7,
    the spec body md5 authoritative).
    The paste size is within the
    354330-byte proven-good envelope
    (the R1007 precedent). HANDOFF:
    ./rn 1009 'The MM1 normalization
    batch one (census 932)'
    WAIT FOR GO.

  - R1009 PREPARED AGAIN 2026-11-01
    at 3025a975: the R155
    repair. The first attempt
    died at the user's preflight:
    R155 classed monsters audit
    bad 1 (brownie saveAsBonus)
    and the early return zeroed
    every later audit line, so
    the whole census read 0
    times. ROOT CAUSE: the
    normalizer's -1 int sentinel
    collided with the loader's
    documented saveAsBonus zero
    default - the R155 data
    contract (the classed
    write-up with no die bonus
    reads 0; the audit is the
    spec, the normalizer yields).
    THE FIX: a SECOND normalizer
    repair rides as file patch
    two - saveAsBonus no-data
    emission 0 (brownie/couatl/
    dolphin carry 0, displacer
    keeps its real 2). Swept the
    whole audit corpus for every
    loader-read field flipped by
    the sentinel fill: R155 is
    the only live-data check
    (the other audited keys -
    dervish, dragon_turtle,
    fire_giant - test presence/
    grid membership only). Now
    540 file patches (538 monster
    windows + the two normalizer
    repairs), engine double-run
    green at base
    3025a975b7b91f597d8ec0da08d
    2ca39f2eb9540 (applied 545/
    already 0 -> 0/already 545),
    rverify GREEN (16 mutants 0
    missed), R155 simulated green
    over the patched tree, zero
    semantic changes vs base,
    every lua literal valid. Spec
    tools/spec_r1009.json 346916
    bytes, md5
    1db6e8c43baebb23e9abf963367
    8c556, seated on the
    r1009-spec canvas (the spec
    body md5 authoritative).
    KNOWN DISPLAY ARTIFACT riding
    the DDG precedent: the 35
    defs whose hitDiceNum was
    absent now carry the -1
    sentinel (as the DDG corpus
    has since R886), so the
    statline HD print reads
    negative for them - no gate
    constrains it. HANDOFF:
    ./rn 1009 'The MM1
    normalization batch one
    (census 932)'
    WAIT FOR GO.

  - R1009 LANDED 2026-11-01 at
    74bf297c: The MM1
    normalization batch one
    (census 932), MM1 part one
    of six, the letters a-f, 99
    defs rewritten to the
    full-field 57-key emission -
    string sentinel n/a,
    integer sentinel -1,
    saveAsBonus riding the
    loader's zero default (the
    R155 contract). 540 file
    patches: 538 monster
    windows (515 insert sites /
    2214 lines, 19 reorder sites
    across 23 defs, 4 move
    encodings) plus the TWO
    normalizer repairs - the
    REG glob (census zero since
    R879) and the saveAsBonus
    no-data default (the first
    attempt died at the user's
    preflight, R155 bad 1, its
    early return zeroing every
    later audit line; a second
    dirty-tree abort between
    attempts needed a git
    restore - attempt 1's
    patches were still
    uncommitted in the tree).
    LANDED VERIFICATION at
    74bf297c: spec md5
    1db6e8c43baebb23e9abf96336
    78c556 unchanged, every to
    present, engine all-already
    545, mn1.h included after
    pm3.h, r1009_batch.h above
    r1008_batch.h, the R1008
    LANDED record seated
    verbatim before the last
    Knowledge maintenance, gap
    report untouched, the
    repaired normalizer reads
    1338 defs live and the 99
    are byte-exact against it,
    brownie 0 / displacer 2
    confirmed, MM1 408. THE
    QUEUE: MM1 batches two
    through six (g-k 90, l-p
    86, q-s 82, t-v 40, w-z
    30), then MM2 332, FF 185,
    OA 47, WSG+MOP 23. The
    next rounds are Curtiss's
    call.
    WAIT FOR GO.

  - R1010 PREPARED 2026-11-01 at
    74bf297c: the MM1
    normalization batch two
    (census 933), MM1 part two
    of six, the letters g-k,
    90 defs rewritten to the
    full-field 57-key emission
    of the repaired, landed
    normalize_registry.py -
    byte-exact, no normalizer
    repairs riding this round
    (both landed in R1009).
    488 file patches: 466
    insert sites / 1924 lines,
    21 whole-line reorder
    sites across 22 defs, 1
    move encoding. The classed
    ki-rin rides this batch -
    magic-user 18 preserved,
    saveAsBonus the zero
    default, the R155 contract
    held; ki-rin is the only
    audited key in the batch.
    Zero semantic changes vs
    base, every lua literal
    valid, engine double-run
    green at base
    74bf297c2618d2d725ea2c763
    bcc58433d940fc (applied
    493/already 0 ->
    0/already 493), rverify
    GREEN (14 mutants 0
    missed). Spec
    tools/spec_r1010.json
    296557 bytes, md5
    806578529cee6bb434de9447a
    089fde9, seated on the
    r1010-spec canvas (the
    spec body md5
    authoritative). The MM1
    census after: 408 defs,
    189 canonical, 219
    remaining. HANDOFF:
    ./rn 1010 'The MM1
    normalization batch two
    (census 933)'
    WAIT FOR GO.

  - R1010 LANDED 2026-11-01 at
    6b76e531: The MM1
    normalization batch two
    (census 933), MM1 part two
    of six, the letters g-k,
    90 defs rewritten to the
    full-field 57-key emission,
    byte-exact against the
    landed normalizer. 488 file
    patches: 466 insert sites /
    1924 lines, 21 reorder
    sites across 22 defs, 1
    move encoding. No
    normalizer repairs this
    round (both landed in
    R1009). The classed ki-rin
    rode the batch - magic-user
    18 preserved, saveAsBonus
    the zero default. LANDED
    VERIFICATION at 6b76e531:
    spec md5
    806578529cee6bb434de9447a0
    89fde9 unchanged, every to
    present, engine all-already
    493, mn2.h after mn1.h,
    r1010_batch.h above
    r1009_batch.h, the R1009
    LANDED record seated
    verbatim before the last
    Knowledge maintenance, the
    normalizer census 1338
    live, byte-exactness green
    over the 90, MM1 408 defs /
    189 canonical / 219
    remaining. THE QUEUE: MM1
    batches three through six
    (l-p 86, q-s 82, t-v 40,
    w-z 30), then MM2 332, FF
    185, OA 47, WSG+MOP 23. The
    next rounds are Curtiss's
    call.
    WAIT FOR GO.

  - R1011 PREPARED 2026-11-01 at
    6b76e531: the MM1
    normalization batch three
    (census 934), MM1 part three
    of six, the letters l-p, 86
    defs rewritten to the
    full-field 57-key emission of
    the landed normalizer -
    byte-exact, no normalizer
    repairs riding. 461 file
    patches: 435 insert sites /
    1723 lines, 26 whole-line
    reorder sites across 25
    defs, no move encodings this
    batch. The audited keys in
    the batch - lammasu,
    leprechaun, purple_worm -
    ride encounter-grid
    membership/presence checks
    only, no field constraints.
    Zero semantic changes vs
    base, every lua literal
    valid, engine double-run
    green at base
    6b76e5312717ee0e5416f58b4ab7
    d0df105277c7 (applied
    466/already 0 ->
    0/already 466), rverify
    GREEN (13 mutants 0 missed).
    Spec tools/spec_r1011.json
    308746 bytes, md5
    d484a267c0d10653371dd0b19a7d
    8de8, seated on the
    r1011-spec canvas (the spec
    body md5 authoritative). The
    MM1 census after: 408 defs,
    275 canonical, 133
    remaining. HANDOFF:
    ./rn 1011 'The MM1
    normalization batch three
    (census 934)'
    WAIT FOR GO.

  - R1011 LANDED 2026-11-01 at
    6f3ffff2: The MM1
    normalization batch three
    (census 934), MM1 part three
    of six, the letters l-p, 86
    defs rewritten to the
    full-field 57-key emission,
    byte-exact against the
    landed normalizer. 461 file
    patches: 435 insert sites /
    1723 lines, 26 whole-line
    reorder sites across 25
    defs, no move encodings. No
    normalizer repairs riding;
    saveAsBonus the zero
    default. LANDED VERIFICATION
    at 6f3ffff2: spec md5
    d484a267c0d10653371dd0b19a7d
    8de8 unchanged, every to
    present, engine all-already
    466, rverify GREEN at the
    base sha (13 mutants 0
    missed), mn3.h after mn2.h,
    r1011_batch.h above
    r1010_batch.h, the R1010
    LANDED record seated
    verbatim before the last
    Knowledge maintenance, the
    normalizer census 1338
    live, byte-exactness green
    over the 86, MM1 408 defs /
    275 canonical / 133
    remaining. THE QUEUE: MM1
    batches four through six
    (q-s 82, t-v 40, w-z 30),
    then MM2 332, FF 185, OA 47,
    WSG+MOP 23. The next rounds
    are Curtiss's call.
    WAIT FOR GO.

  - R1012 PREPARED 2026-11-01 at
    6f3ffff2: the MM1
    normalization batch four
    (census 935), MM1 part four
    of six, the letters q-s, 57
    defs rewritten to the
    full-field 57-key emission of
    the landed normalizer -
    byte-exact, no normalizer
    repairs riding. 316 file
    patches: 294 insert sites /
    1060 lines, 22 whole-line
    reorder sites across 22
    defs, no move encodings this
    batch. The queue numbers
    restated from the tree: the
    sparse census by letter is
    q-s 57, t-v 40, w-z 36 (the
    earlier 82/40/30 estimates
    superseded). No audited key
    in the batch rides a
    field-constraint audit -
    the encounter-grid
    membership and presence
    checks only, and zero
    reg.find field audits touch
    the batch. Zero semantic
    changes vs base, every lua
    literal valid, engine
    double-run green at base
    6f3ffff2fadf25e016f14b72b02f
    207ad144bca9 (applied
    321/already 0 ->
    0/already 321), rverify
    GREEN (13 mutants 0 missed).
    Spec tools/spec_r1012.json
    331710 bytes, md5
    7e4f090d0220924ae3ee203a6cf
    8ff2e, seated on the
    r1012-spec canvas (the spec
    body md5 authoritative). The
    MM1 census after: 408 defs,
    332 canonical, 76
    remaining. HANDOFF:
    ./rn 1012 'The MM1
    normalization batch four
    (census 935)'
    WAIT FOR GO.

  - R1012 LANDED 2026-11-01 at
    bd00f8cf: The MM1
    normalization batch four
    (census 935), MM1 part four
    of six, the letters q-s, 57
    defs rewritten to the
    full-field 57-key emission,
    byte-exact against the
    landed normalizer. 316 file
    patches: 294 insert sites /
    1060 lines, 22 whole-line
    reorder sites across 22
    defs, no move encodings. No
    normalizer repairs riding;
    no audited key in the batch
    rides a field-constraint
    audit. The queue numbers
    restated from the tree: the
    sparse census by letter is
    q-s 57, t-v 40, w-z 36 (the
    earlier 82/40/30 estimates
    superseded). LANDED
    VERIFICATION at bd00f8cf:
    spec md5
    7e4f090d0220924ae3ee203a6cf
    8ff2e unchanged, every to
    present, engine all-already
    321, rverify GREEN at the
    base sha (13 mutants 0
    missed), mn4.h after mn3.h,
    r1012_batch.h above
    r1011_batch.h, the R1011
    LANDED record seated
    verbatim in the seed before
    the last Knowledge
    maintenance, the normalizer
    census 1338 live,
    byte-exactness green over
    the 57, MM1 408 defs / 332
    canonical / 76 remaining.
    THE QUEUE: MM1 batches five
    and six (t-v 40, w-z 36),
    then MM2 332, FF 185, OA 47,
    WSG+MOP 23. The next rounds
    are Curtiss's call.
    WAIT FOR GO.

  - R1013 PREPARED 2026-11-01 at
    bd00f8cf: the MM1
    normalization batch five
    (census 936), MM1 part five
    of six, the letters t-v, 40
    defs rewritten to the
    full-field 57-key emission of
    the landed normalizer -
    byte-exact, no normalizer
    repairs riding. 207 file
    patches: 190 insert sites /
    664 lines, 17 whole-line
    reorder sites across 17
    defs, no move encodings this
    batch. No audited key in the
    batch rides a
    field-constraint audit -
    the encounter-grid
    membership and presence
    checks only, and zero
    reg.find field audits touch
    the batch. Zero semantic
    changes vs base, every lua
    literal valid, engine
    double-run green at base
    bd00f8cf875c9cf2762f7a9630ff
    1164e2cbcfc8 (applied
    212/already 0 ->
    0/already 212), rverify
    GREEN (13 mutants 0 missed).
    Spec tools/spec_r1013.json
    233650 bytes, md5
    3d6f728490722c90721bdacbb9a
    dee62, seated on the
    r1013-spec canvas (the spec
    body md5 authoritative). The
    MM1 census after: 408 defs,
    372 canonical, 36
    remaining. HANDOFF:
    ./rn 1013 'The MM1
    normalization batch five
    (census 936)'
    WAIT FOR GO.

  - R1013 LANDED 2026-11-01 at
    da6f7da9: The MM1
    normalization batch five
    (census 936), MM1 part five
    of six, the letters t-v, 40
    defs rewritten to the
    full-field 57-key emission,
    byte-exact against the
    landed normalizer. 207 file
    patches: 190 insert sites /
    664 lines, 17 whole-line
    reorder sites across 17
    defs, no move encodings. No
    normalizer repairs riding;
    no audited key in the batch
    rides a field-constraint
    audit. LANDED VERIFICATION
    at da6f7da9: spec md5
    3d6f728490722c90721bdacbb9a
    dee62 unchanged, every to
    present, engine all-already
    212, rverify GREEN at the
    base sha (13 mutants 0
    missed), mn5.h after mn4.h,
    r1013_batch.h above
    r1012_batch.h, the R1012
    LANDED record seated
    verbatim in the seed before
    the last Knowledge
    maintenance, the normalizer
    census 1338 live,
    byte-exactness green over
    the 40, MM1 408 defs / 372
    canonical / 36 remaining.
    THE QUEUE: the MM1 batch six
    (w-z 36) closes MM1, then
    MM2 332, FF 185, OA 47,
    WSG+MOP 23. The next rounds
    are Curtiss's call.
    WAIT FOR GO.

  - R1014 PREPARED 2026-11-01 at
    da6f7da9: the MM1
    normalization batch six
    (census 937), MM1 part six
    of six, the letters w-z, 36
    defs rewritten to the
    full-field 57-key emission of
    the landed normalizer -
    byte-exact, no normalizer
    repairs riding - AND THE
    BOOK CLOSES: MM1 408 of 408
    canonical, 0 remaining. 198
    file patches: 178 insert
    sites / 542 lines, 20
    whole-line reorder sites
    across 20 defs, no move
    encodings this batch. No
    audited key in the batch
    rides a field-constraint
    audit - the encounter-grid
    membership and presence
    checks only, and zero
    reg.find field audits touch
    the batch. Zero semantic
    changes vs base, every lua
    literal valid, engine
    double-run green at base
    da6f7da918af68e73438c9c0603
    1ff34fab9c397 (applied
    203/already 0 ->
    0/already 203), rverify
    GREEN (13 mutants 0 missed).
    Spec tools/spec_r1014.json
    238930 bytes, md5
    3265d4f724bb3f0e94f94f8438c
    2fee2, seated on the
    r1014-spec canvas (the spec
    body md5 authoritative). The
    MM1 census after: 408 defs,
    408 canonical, 0 remaining -
    the arc complete. HANDOFF:
    ./rn 1014 'The MM1
    normalization batch six
    (census 937)'
    WAIT FOR GO.

  - R1014 LANDED 2026-11-01 at
    42f94f27: The MM1
    normalization batch six
    (census 937), MM1 part six
    of six, the letters w-z, 36
    defs rewritten to the
    full-field 57-key emission,
    byte-exact against the
    landed normalizer - AND THE
    BOOK CLOSES: MM1 408 of 408
    canonical, 0 remaining, the
    R879 arc complete (R1009
    a-f 99, R1010 g-k 90, R1011
    l-p 86, R1012 q-s 57,
    R1013 t-v 40, R1014 w-z 36).
    198 file patches: 178
    insert sites / 542 lines, 20
    whole-line reorder sites
    across 20 defs, no move
    encodings. No normalizer
    repairs riding; no audited
    key in the batch rides a
    field-constraint audit.
    LANDED VERIFICATION at
    42f94f27: spec md5
    3265d4f724bb3f0e94f94f8438c
    2fee2 unchanged, every to
    present, engine all-already
    203, rverify GREEN at the
    base sha (13 mutants 0
    missed), mn6.h after mn5.h,
    r1014_batch.h above
    r1013_batch.h, the R1013
    LANDED record seated
    verbatim in the seed before
    the last Knowledge
    maintenance, the normalizer
    census 1338 live,
    byte-exactness green over
    the 36, MM1 408 defs / 408
    canonical / 0 remaining.
    THE QUEUE: MM2 332, FF 185,
    OA 47, WSG+MOP 23. The next
    rounds are Curtiss's call.
    WAIT FOR GO.

  - R1015 PREPARED 2026-11-01 at
    42f94f27: THE OA TABLE
    PROMOTION BATCH NINE (census
    938), the promotions doctrine
    continued - the round purpose
    (Curtiss): promotions are meant
    for rules AND tables, to
    alleviate the burden off the
    C++ pin code, and to place in
    Lua what originally got placed
    into C++ code files. The OA
    monsters are already in Lua
    (47 registry defs incl. the 39
    Chapter 12 promotions), but the
    R981-R988 eight-batch promotion
    predated the table promotion:
    all 160 records shipped
    "tables" = {} while the
    R614-R773 specs declare 139
    table grids (dragon/dsg/wsg
    promotions carried theirs).
    This round mechanically
    re-promotes the tables from the
    specs into the 94 records that
    carry them - fix the record
    from the spec, the promotion
    doctrine, parse-back equal
    key-for-key in the spec order,
    the R968 record encoding. 298072
    Lua bytes, one round under the
    paste ceiling; the 66 table-less
    records untouched. 94 file
    patches, zero semantic surface
    (records only; the C++ pins
    stay the firewall). Engine
    double-run green at base
    42f94f2767cd6ffd164447443a8862d
    11e7e65c4 (applied 99/already 0
    -> 0/already 99), rverify GREEN
    (7 mutants 0 missed), the
    applied tree verified - 94
    records carrying 139 tables,
    66 empty-tables records intact,
    byte-exact re-emission. Spec
    tools/spec_r1015.json 327947
    bytes, md5
    6b1b4a38acee886710b356c05bb66cd
    2, seated on the r1015-spec
    canvas (the spec body md5
    authoritative). Prefix oa9
    (batch nine of the OA promotion
    series; the const/bool
    name-collision lesson: a const
    and a bool may never share a
    name - duplicate C++ symbols).
    HANDOFF:
    ./rn 1015 'The OA table
    promotion batch nine (census
    938)'
    WAIT FOR GO.

  - R1015 LANDED 2026-11-01 at
    d68d8109: THE OA TABLE
    PROMOTION BATCH NINE (census
    938), the promotions doctrine
    continued - the 139 table
    grids the R981-R988 promotion
    left behind in the C++ pins,
    promoted from the R614-R773
    specs into the 94 OA Lua
    records, parse-back equal
    key-for-key. 298072 Lua bytes,
    the 66 table-less records
    untouched; the pins stay the
    firewall. 94 file patches,
    prefix oa9. LESSON: a const
    and a bool may never share a
    name - duplicate C++ symbols;
    caught by the engine parser
    gate pre-run. LANDED
    VERIFICATION at d68d8109:
    spec md5
    6b1b4a38acee886710b356c05bb66
    cd2 unchanged, every to
    present, engine all-already
    99, rverify GREEN at the
    base sha (7 mutants 0
    missed), oa9.h after mn6.h,
    r1015_batch.h above
    r1014_batch.h, the R1014
    LANDED record seated verbatim
    in the seed before the last
    Knowledge maintenance, 94/94
    records on disk byte-matching
    the spec, 66 empty-tables
    records intact. THE QUEUE: the
    promotions continue per
    Curtiss's call - the OA tables
    gap is CLOSED (139 of 139);
    the MM2 332, FF 185, WSG+MOP
    23 normalization queue and the
    deity seam stand.
    WAIT FOR GO.

  - R1016 PREPARED 2026-11-01 at
    base d68d8109: THE OA
    NORMALIZATION BATCH (census
    939) - the OA book closes
    complete. 47 OA defs (the
    whole sparse remainder) rewrote
    to the full-field 57-key
    emission of the landed
    normalize_registry.py, byte-
    exact per file. Anatomy: 332
    file patches, ALL anchored
    inserts (332 sites / 1276
    lines), zero reorders, zero
    moves - the OA defs were
    promoted post-normalizer so
    already in canonical
    FIELD_ORDER, only sparse. Static
    sweep: zero semantic drift
    (every original field value
    preserved), every Lua literal
    valid, one audited key in the
    batch (chiang_lung) -
    registry presence check only,
    no field constraints. Engine
    double-run green (applied 337,
    then already 337); rverify
    GREEN at base (13 mutants 0
    missed). Applied-tree verify:
    OA census 47/47 canonical, all
    byte-exact, oap1.h after
    oa9.h, r1016_batch.h above
    r1015_batch.h, the R1015 LANDED
    record seated verbatim in the
    seed. Spec
    tools/spec_r1016.json 98472
    bytes, md5
    8155b7dde59ff999745068d8cd14d
    c75, seated on the r1016-spec
    canvas (the spec body md5
    authoritative). Prefix oap
    (oan collides with the
    oaninja/oanwprof headers).
    NOTE: the R1015 LANDED record
    had its WAIT FOR GO. split
    across lines when seated;
    rewrapped in place to end on
    one line (the known near-miss
    pattern, third occurrence).
    THE QUEUE: MM2 332, FF 185,
    WSG+MOP 23, DRG 5 follow.
    HANDOFF:
    ./rn 1016 'The OA normalization
    batch (census 939)'
    WAIT FOR GO.

  - R1016 LANDED 2026-11-01 at
    033179f2: THE OA
    NORMALIZATION BATCH (census
    939) - the OA book closes
    COMPLETE on both axes,
    promotions and normalization.
    The whole sparse remainder,
    47 OA defs, rewritten to the
    full-field 57-key emission,
    byte-exact per file; all 332
    patches were anchored inserts
    (332 sites / 1276 lines),
    zero reorders - the OA defs
    were promoted post-normalizer,
    already in canonical
    FIELD_ORDER, only sparse.
    LANDED VERIFICATION at
    033179f2: spec md5
    8155b7dde59ff999745068d8cd14d
    c75 unchanged (recovered from
    the r1016-spec canvas, the
    body authoritative), engine
    all-already 337, rverify
    GREEN at the base sha
    d68d8109 (13 mutants 0
    missed), oap1.h after
    oa9.h, r1016_batch.h above
    r1015_batch.h, the R1015
    LANDED record seated verbatim
    in the seed before the last
    Knowledge maintenance, OA
    census 47/47 canonical
    byte-exact, normalizer census
    939 live. THE QUEUE: MM2 332,
    FF 185, WSG+MOP 23, DRG 5
    normalization stand, then the
    deity seam.
    WAIT FOR GO.

  - R1017 PREPARED 2026-11-01 at
    base 033179f2: THE MM2
    NORMALIZATION BATCH ONE
    (census 940) - the MM2 arc
    opens, 83 of 332 defs (the
    letters a through d, aboleth
    through derghodaemon) rewritten
    to the full-field 57-key
    emission of the landed
    normalize_registry.py,
    byte-exact per file. Anatomy:
    586 file patches, ALL anchored
    inserts (586 sites / 2236
    lines), zero reorders, zero
    moves - the MM2 defs were
    promoted post-normalizer so
    already in canonical
    FIELD_ORDER, only sparse.
    Static sweep: zero semantic
    drift (every original field
    value preserved), every Lua
    literal valid, eight audited
    keys in the batch (amaimon,
    azer, fire_bat, cambion,
    camptosaurus, chaggrin,
    crysmal, dao) - every
    constraint reads a key the def
    already carries, NO audit
    touches a sentinel-emitted
    key. Engine double-run green
    (applied 591, then already
    591); rverify GREEN at base
    (13 mutants 0 missed).
    Applied-tree verify: MM2
    census 83/332 canonical, all
    byte-exact, mq1.h after
    oap1.h, r1017_batch.h above
    r1016_batch.h, the R1016
    LANDED record seated verbatim
    in the seed. Spec
    tools/spec_r1017.json 167096
    bytes, md5
    c66a2b7586bbd33ef06e3c670723
    8d03, seated on the r1017-spec
    canvas (the spec body md5
    authoritative). Prefix mq
    (completely free - no mq
    symbols, no rules/mq*.h; mn
    rides the MM1 arc).
    HANDOFF:
    ./rn 1017 'The MM2
    normalization batch one (census
    940)'
    WAIT FOR GO.

  - R1017 LANDED 2026-11-01 at
    888198cb: THE MM2
    NORMALIZATION BATCH ONE
    (census 940) - the MM2 arc
    opens, 83 of 332 defs (the
    letters a through d) rewritten
    to the full-field 57-key
    emission, byte-exact per file;
    all 586 patches anchored
    inserts (586 sites / 2236
    lines), zero reorders - the
    MM2 defs were promoted
    post-normalizer, already in
    canonical FIELD_ORDER, only
    sparse. Eight audited keys in
    the batch (amaimon, azer,
    fire_bat, cambion,
    camptosaurus, chaggrin,
    crysmal, dao) - every
    constraint reads a carried
    key, no audit touches a
    sentinel-emitted key. LANDED
    VERIFICATION at 888198cb:
    spec md5
    c66a2b7586bbd33ef06e3c670723
    8d03 unchanged (recovered
    from the r1017-spec canvas),
    engine all-already 591,
    rverify GREEN at the base sha
    033179f2 (13 mutants 0
    missed), mq1.h after
    oap1.h, r1017_batch.h above
    r1016_batch.h, the R1016
    LANDED record seated verbatim
    in the seed before the last
    Knowledge maintenance, MM2
    census 83/332 canonical
    byte-exact, normalizer census
    940 live. THE QUEUE: the MM2
    batches two through four
    follow, then FF 185, WSG+MOP
    23, DRG 5, the deity seam.
    WAIT FOR GO.

  - R1018 LANDED 2026-11-01 at
    5daadd64: THE MM2
    NORMALIZATION BATCH TWO
    (census 941) - the arc's
    second quarter, 83 of 332
    (derro through mephistopheles)
    rewritten to the full-field
    57-key emission, byte-exact
    per file. 592 file patches:
    578 anchored inserts (2252
    lines), five trailing-comma
    normalizations (hangman_tree,
    haunt, hollyphant, hordling,
    hybsil), NINE PIN-REPAIR
    PATCHES - the round that
    taught the DOUBLE GRID
    lesson. The duergar and
    mandragora are by_level defs
    whose sparse files never
    carried xp fields; the loader
    reads absence as 0 and the
    mm2dg/mm2lmn grids pinned
    that 0, but the canonical
    emission writes the -1
    sentinel (the dervish and
    dwarf precedent). Two
    preflight REDs: attempt one
    caught the four pin cells
    (R803 bad 2, the battery
    abort hiding the mandragora);
    attempt two repaired the
    cells but the R803 dragon
    fragment still compared its
    HARDCODED CDgStats row 10,
    and the R808 LMN fragment
    CLmStats row 7 would follow -
    EACH LETTER WALK EXISTS
    TWICE, the regtest live-def
    walk against the grid
    functions AND the migrated
    fragment against its own
    copy; both copies must
    mirror the repair. Attempt
    three: 4 grid cells, 2
    fragment rows, 3 comments,
    preflight GREEN. LANDED
    VERIFICATION at 5daadd64:
    spec md5
    e2eaf1b46656f62ab963204a384
    6078b unchanged (the canvas
    body identical), engine
    all-already 597 twice,
    rverify GREEN at the base
    sha 888198cb (15 mutants 0
    missed), MM2 census 166/332
    canonical byte-exact, the
    four pins and both fragment
    rows -1, the mongrelman and
    myconid by_level cells still
    0 until their own batches,
    mq2.h after mq1.h,
    r1018_batch.h above
    r1017_batch.h, the R1017
    LANDED record seated verbatim
    in the seed before the last
    Knowledge maintenance,
    normalizer census 941 live.
    THE QUEUE: the MM2 batches
    three and four follow (83
    each, consts mq3*/mq4*; the
    mongrelman and myconid rows
    repair their cells plus the
    r808 CLmStats rows 30/35 the
    same way; the zombie_monster
    13-key def needs the wxyz
    walk pins checked when
    reached), then FF 185,
    WSG+MOP 23, DRG 5, the deity
    seam.
    WAIT FOR GO.
  - R1019 LANDED 2026-11-01 at
    f318d032: THE MM2
    NORMALIZATION BATCH THREE
    (census 942) - the arc's
    third quarter, 83 of 332
    (mihstu through
    shadow_mastiff) rewritten to
    the full-field 57-key
    emission, byte-exact per
    file; 249/332 canonical,
    83 remaining. 590 file
    patches: 583 anchored
    inserts (2247 lines), zero
    whole-line rewrites, seven
    pin-repair patches - THE
    ROUND OF THE ROW-ALIGNMENT
    LESSON. The mongrelman and
    myconid by_level pair
    needed their mm2lmn xp
    cells 0 to -1, but the pin
    repairs must target the
    kLM WALK ARRAY ORDER: the
    mongrelman is case 31, not
    30 - the russet mold holds
    case 30 and CARRIES its
    own 0/0/0 xp cells, so its
    grid functions stay 0. One
    preflight RED (the R808
    fragment walk bad 4, rows
    30 and 31 split against
    each other); the fix rides
    and the sweep now
    simulates BOTH the fragment
    CLmStats grid (38 rows, 10
    columns, functions vs the
    hardcoded copy) and the
    live walk xp columns
    (loader vs functions, all
    38 defs) BEFORE the
    handoff - both bad 0, a
    permanent gate for every
    future pin repair. LANDED
    VERIFICATION at f318d032:
    spec md5
    aed880582b4b77534ea47c35e0
    78f037 unchanged (the canvas
    body identical), engine
    all-already 595 twice,
    rverify GREEN at the base
    sha 5daadd64 (15 mutants 0
    missed), MM2 census 249/332
    canonical byte-exact, the
    mongrelman and myconid
    cells and fragment rows
    -1, the russet mold cells
    0, mq3.h after mq2.h,
    r1019_batch.h above
    r1018_batch.h, the R1018
    LANDED record seated
    verbatim in the seed before
    the last Knowledge
    maintenance, normalizer
    census 942 live. THE QUEUE:
    the MM2 batch four closes
    the book (83 defs, consts
    mq4*; the zombie_monster
    13-key def needs the wxyz
    walk pins checked when
    reached), then FF 185,
    WSG+MOP 23, DRG 5, the
    deity seam.
    WAIT FOR GO.
  - R1020 LANDED 2026-11-01 at
    38bea084: THE MM2
    NORMALIZATION BATCH FOUR,
    THE BOOK CLOSER (census
    943) - the last 83 of 332
    rewritten to the
    full-field 57-key
    emission. THE MM2 BOOK
    CLOSES COMPLETE: 332/332
    canonical. The pin
    repairs: the monster
    zombie (the kWXYZ walk
    index 14) carried its
    hitDiceNum 0 and
    mm2_print xp 0/0/0 cells
    but never
    hitDiceBonus, avgHp or
    lairPct - the canonical
    emission writes the -1
    sentinel and the repair
    rode in TRIPLE-GRID
    form (the live walk,
    the R815 fragment
    hardcoded CWXYZStats
    row 14, AND the
    fragment direct
    per-cell pins), a
    third copy shape
    beyond the R1018
    double-grid lesson.
    LANDED VERIFICATION at
    38bea084 (fresh
    tarball): spec md5
    e886df782e3d3d8f7dc085bcf
    2188f3c unchanged (the
    canvas body identical),
    engine all-already 594
    twice, census 942 to
    943 live, MM2 332/332
    canonical, the zombie
    cells and all fragment
    mirrors -1 (grid row
    {6,0,-1,-1,1,0,0,-1,0,0}
    and the direct
    HdBonus/AvgHp/LairPct(14)
    pins), the neighbors
    (juju zombie 13, zorbo
    15) intact, mq4.h after
    mq3.h, r1020_batch.h
    above r1019_batch.h in
    regtest.cpp, the R1019
    LANDED record seated
    verbatim in the seed
    before the last
    Knowledge maintenance.
    All alignment gates ran
    green BEFORE the
    handoff this round -
    the R1019 lesson
    institutionalized. THE
    QUEUE: FF 185, WSG+MOP
    23, DRG 5, the deity
    seam.
    WAIT FOR GO.
  - R1021 LANDED 2026-11-01 at
    ecb946db: THE FF
    NORMALIZATION BATCH ONE,
    THE FF ARC OPENER (census
    944) - the first 71 of 185
    FF defs (the letters a-g)
    rewritten to the
    full-field 57-key
    emission. The FF census:
    71 canonical, 114
    remaining (the letters
    h-z). Zero pin repairs -
    the FF book carries no
    fragment grids, the
    R1018/R1020 mirror class
    empty here. The
    single-line anchor
    doctrine institutionalized
    (the aarakocra lesson:
    a two-line anchor breaks
    engine idempotence when
    a later patch inserts
    between the anchor pair);
    the builder now simulates
    the second engine pass
    over every patch - zero
    idempotence failures.
    LANDED VERIFICATION at
    ecb946db (fresh
    tarball): spec md5
    8eacc5729928cf4c3552d852
    a67958af unchanged (the
    canvas body identical),
    engine all-already 502
    twice, FF 71/71 canonical
    byte-exact against the
    landed normalizer (114
    sparse confirmed), fq1.h
    after mq4.h, r1021_batch.h
    above r1020_batch.h, the
    R1020 LANDED record
    seated verbatim in the
    seed. THE QUEUE: the FF
    batch two (the letters
    h-r, 60 defs, consts
    fq2*), the FF batch three
    (the letters s-z, 54
    defs - the FF book
    closes), then WSG+MOP 23,
    DRG 5, the deity seam.
    WAIT FOR GO.
  - R1022 LANDED 2026-11-01 at
    2f3a5c46: THE FF
    NORMALIZATION BATCH TWO
    (census 945) - the 60 defs
    of the letters h-r
    rewritten to the
    full-field 57-key
    emission. The FF census:
    131 canonical (the letters
    a-r), 54 remaining (the
    letters s-z). Zero pin
    repairs, zero reorders,
    zero comma sites - the
    single-line anchor doctrine
    held clean (the builder's
    second-pass simulation,
    zero idempotence
    failures). LANDED
    VERIFICATION at 2f3a5c46
    (fresh tarball): spec md5
    d8724bdfdb3ec5e7f5da098f
    085d7c74 unchanged (the
    canvas body identical),
    engine all-already 425
    twice, FF 131/185
    canonical byte-exact
    against the landed
    normalizer (the 60 h-r
    defs 60/60, the 54 s-z
    sparse confirmed), fq2.h
    after fq1.h, r1022_batch.h
    above r1021_batch.h, the
    R1021 LANDED record seated
    verbatim in the seed. THE
    QUEUE: the FF batch three
    (the letters s-z, 54 defs,
    consts fq3* - the FF book
    closes), then WSG+MOP 23,
    DRG 5, the deity seam.
    WAIT FOR GO.
  - R1023 LANDED 2026-11-01 at
    f96cc96f: THE FF
    NORMALIZATION BATCH THREE,
    THE FF BOOK CLOSER (census
    946) - the last 54 of 185
    FF defs (the letters s-z)
    rewritten to the
    full-field 57-key
    emission. THE FF BOOK
    CLOSES COMPLETE: 185/185
    canonical. Zero pin
    repairs, zero reorders,
    zero comma sites across
    the whole arc - the FF
    book carries no fragment
    grids, and the
    single-line anchor
    doctrine (the R1021
    aarakocra lesson) held
    clean through all three
    batches. LANDED
    VERIFICATION at f96cc96f
    (fresh tarball): spec md5
    3a712a17bf9f2a99da72c667
    b404382d unchanged (the
    canvas body identical),
    engine all-already 383
    twice, FF 185/185
    canonical byte-exact
    against the landed
    normalizer (the 54 s-z
    defs 54/54), fq3.h after
    fq2.h, r1023_batch.h
    above r1022_batch.h, the
    R1022 LANDED record seated
    verbatim in the seed. THE
    QUEUE: WSG+MOP 23, DRG 5,
    the deity seam - the
    per-book normalization
    pass enters its tail.
    WAIT FOR GO.
  - R1024 LANDED 2026-11-01 at
    92a09354: THE WSG+MOP
    NORMALIZATION TAIL BATCH
    (census 947) - the 23 defs
    (15 WSG service animals, 8
    MOP outsiders) rewritten to
    the full-field 57-key
    emission. THE TAIL CLOSES
    23/23. THE wsgRoles LESSON
    institutionalized: the 15
    WSG defs carry REAL service
    role masks (1/3/5/7) - the
    normalizer preserves them,
    only absent keys read the
    sentinels; the sweep pins
    the mask invariance per def
    (15 masks byte-identical
    live at the landed tree, 8
    MOP sentinel insertions).
    LANDED VERIFICATION at
    92a09354 (fresh tarball):
    spec md5
    d30ef48e4b05d9d177a71e4f
    20370cf8 unchanged (the
    canvas body identical),
    engine all-already 204
    twice, WSG+MOP 23/23
    canonical byte-exact against
    the landed normalizer,
    wt1.h after fq3.h,
    r1024_batch.h above
    r1023_batch.h, the R1023
    LANDED record seated
    verbatim in the seed. THE
    REGISTRY SCORECARD after the
    tail: MM1 408, MM2 332, OA
    47, FF 185, WSG 15, MOP 8
    all closed, DDG 338 already
    canonical under the
    post-R879 promotion schema -
    1333 of 1338 defs carry the
    full-field emission, ONLY
    DRG 5 REMAINS. THE QUEUE:
    the DRG normalization (the
    five Dragon magazine defs,
    consts dq1* presumably - a
    single small round), then
    the deity seam - the
    per-book pass one DRG round
    from complete.
    WAIT FOR GO.
  - R1025 LANDED 2026-11-01 at adaae6be - the DRG
    normalization batch (census 948), THE REGISTRY
    CLOSES. Landed verification at the fresh tarball:
    spec md5 c6a0cbf8f37ebc6d70908b160b0c89c6
    unchanged, engine all-already 40 twice, dq1.h
    at regtest 729 after wt1.h at 728, r1025_batch.h
    at 4839 above r1024_batch.h at 4840, the R1024
    LANDED record seated in the seed, and the census
    1338 defs - DRG 5, MM1 408, MM2 332, DDG 338,
    FF 185, OA 47, WSG 15, MOP 8 - every one of the
    57 keys present in all 1338, the landed
    normalize_registry.py rewrite changing ZERO
    files: THE REGISTRY CLOSES 1338 of 1338.
    The comma-site lesson landed: the 5 whole-line
    rewrites (each DRG text field lacked the
    Lua-optional trailing comma, merged with the
    end-of-body insert in one window) - the first
    comma-site round of the arc; InsSites 30,
    CommaSites 5, ReorderDefs 0, PatchEntries 35.
    THE PER-BOOK NORMALIZATION ARC IS COMPLETE:
    MM1 R1009-R1014, OA R1016, MM2 R1017-R1020,
    FF R1021-R1023, WSG+MOP R1024, DRG R1025.
    Next in the queue: the deity seam.
    WAIT FOR GO.
  - R1026 LANDED 2026-11-01 at c9c35759 - the
    deity seam close (census 949), THE QUEUE
    EMPTIES. Landed verification at the fresh
    tarball: spec md5 746914f7b6c30d8df407cf8-
    1a086dabb unchanged, engine all-already 5
    twice, ll1.h at regtest 730 after dq1.h at
    729, r1026_batch.h at 4840 above
    r1025_batch.h at 4841, the R1025 LANDED
    record seated in the seed, the DDG gap
    report 24 closed 0 open, the census 1338
    live. THE SEAM CLOSE: the L&L parity
    inventory - 130 notes across the pin
    headers, every one adjudicated (pinned by
    print, 8 garble restores from the L&L
    voice, 3 deliberate eyeball flags, the
    geometry verified), ZERO open divergences,
    ZERO archive.org derivative voices needed
    (the 1eonline chart rows carried the
    collation); the at-most-one divergence
    round NOT needed - L&L a parity voice, not
    a second book. THE DEITY SEAM CLOSES; THE
    QUEUE IS EMPTY - the registry closed at
    R1025 (1338/1338 canonical), the deity seam
    closed at R1026. The next arc awaits
    Curtiss's call.
    WAIT FOR GO.








  NUMERAL-FIRST REBUILD RULED (Curtiss,
  2026-11-07): the map-006 draft grid
  is WRONG IN MANY WALLS and the
  map rebuilds FROM SCRATCH under a
  NUMERAL-FIRST protocol: (1)
  identify all 25 numbered locations
  (keys 1-25); (2) get each numeral's
  EXACT coordinates, even when the
  number straddles multiple squares
  (fractional cell coords, like the
  earlier centroid prints); (3) each
  numeral becomes a LOCAL REFERENCE
  for its room - walls identified
  relative to the verified numeral,
  not from stamping; (4) DOORS ARE
  SPECIAL WALLS - one wall system,
  a door is a wall tile carrying a
  door entity (consistent with the
  tile-metadata doctrine). The old
  draft grid is KEPT AS REFERENCE
  ONLY - not to build on, but so
  the wall errors can be diagnosed
  post-mortem (what went wrong
  along the way). Coordinate frame
  unchanged: his map squares =
  canvas tiles exactly, offset 0.
  Divisions of labor unchanged:
  numeral READS (which number a
  blob is) are Curtiss's
  adjudication; geometry (px
  centroids, straddle) is
  tooling. NEXT: numeral census
  over the 300dpi raster
  (map-006.match.json blobs ->
  map-006.numbers.json), his
  confirm pass on reads, then
  per-room wall traces from each
  anchor.
  MNUM v0.1 SHIPPED (canvas mnum-tool,
  gate print 193b021fe10e326c31f8dd03-
  0a4a2d3c, 2026-11-07): the numeral
  census for the numeral-first rebuild.
  Reads a seated .grid.json + one or
  more .match.json (mapp rows), selects
  numeral rows by proposal (single
  digits 0-9 by default; --labels
  adds taught names like num10),
  groups same-baseline digit blobs
  (within 0.75 col x 0.30 row, cell
  units) into ONE PRINTED NUMBER,
  seats each number's EXACT fractional
  cell centroid (raw px->cell math,
  3-decimal output; centroid, extent,
  straddle, per-digit provenance with
  px_provenance), flags non-confident
  reads and OUTSIDE-the-grid numbers
  as asks. Output <stem>.numbers.json
  beside the match file. Fixtures
  pass (synthetic 64px grid: two-
  digit grouping '12' centroid
  (10.475, 8.51) straddle 0.475,
  single-digit mid-cell 0.5,
  non-confident ask, outside ask,
  non-numeral labels excluded, --
  labels inclusion, left-to-right
  member order). Reads are PROPOSALS:
  the census asks, Curtiss adjudicates
  - never seat a number he has not
  confirmed. USAGE:
  python3 tools/mnum.py
  extract/g1/map-006.grid.json
  ~/mb6s4/map-006.match.json
  [--labels ...] -> map-006.numbers.json
  NEXT after his gate print +
  census run: confirm pass on the
  reads, the 25-number ledger, then
  per-room wall traces from each
  verified numeral anchor.
  MNUM v0.2 RULED+SHIPPED (canvas
  mnum-tool, gate print 4346450cce-
  6e487ac3a22c53097e9be1, 2026-11-07):
  v0.1's default numeral filter only
  accepted SINGLE-CHARACTER digits, so
  whole-number library labels ('12',
  '20' - each taught as ONE blob
  family) were silently excluded: his
  census run found only the '8'. v0.2
  selects ANY all-digit proposal by
  default (--labels still adds taught
  names like num10), and --expect N
  asks when the census count is off.
  Fixtures pass (12 blobs: whole-label
  12/20 selection, digit-grouped
  centroid 10.475, expect-mismatch
  ask, prior v0.1 checks). NOTE: the
  canvas round-trip after the
  environment reset re-extracted a
  body hashing 15110856af314290b99f2a-
  93622b98af instead of the v0.1 gate
  print 193b021f... (content verified
  complete - all v0.1 fixes present;
  suspected product-side newline
  normalization). HIS LOCAL md5sum is
  the true gate: v0.2 print is fresh
  and he verifies on Termux after
  copying the canvas body.
  CENSUS RUN RESULT (his Termux,
  map-006, 2026-11-07): 507 seated
  blobs; taught numeral labels only
  '12', '20', '8' (anchored) - the
  other ~22 numerals live in the 407
  UNKNOWN blobs. The one seated hit:
  8 @ lattice (32.52, 23.96) ->
  canvas (29, 18) EXACTLY the seated
  anchor from the old draft - the
  coordinate frame is confirmed on
  real data. NEXT: targeted mapp
  teaching pass --teach "x,y:label;..."
  at the known numeral positions
  (mapp --around for eyeball context),
  re-match, re-census with --expect 25,
  then his read-confirm pass.
  NUMERALS RULED BY EYES (Curtiss,
  2026-11-07, raster adjudication,
  canvas coords): 6 @ canvas (29,
  rows 25 & 26) - the glyph straddles
  rows 25/26; the old draft's (29,25.5)
  WAS RIGHT, and NO BLOB WAS EXTRACTED
  within 2.16 of its lattice spot
  (32.5, 31.5) -> CONFIRMED: thin-
  glyph extraction gap in mblob, not
  a wrong position. 4 @ canvas (23,
  32) - lattice ~ (26.5, 38.0);
  consistent with his earlier room-4
  candidate (22.5, 33.5) zone; ask-
  list has several numeral-sized
  families nearby (q162-q169, y
  38.8-39.7, areas 10-105) but none
  yet confirmed as the 4. Both
  rulings are LEDGER entries
  regardless of blob extraction:
  his eyeball is ground truth, the
  census is tool-assisted
  confirmation, not a gate.
  LIBRARY BASELINE RESTORED (2026-11-07):
  git restore tools/library.json removed
  the two unverified human-teach entries
  (the area-6183 '19' word-blob and the
  area-74 '20' debris dot; the 20-blob
  proposal explosion and the census's
  28 debris 'numbers' are gone).
  Re-match + re-census v0.2 clean: 3
  printed numbers. THE NUMERAL-FIRST
  PROTOCOL CAUGHT TWO OLD MISREADS IN
  THE LIBRARY ITSELF: the pre-existing
  anchored '12' seats at canvas (10.5,
  29.0) = EXACTLY the old 'traced-12
  suspect misread of 17/18' kitchen
  zone flag, and the anchored '20'
  seats at canvas (10.9, 10.0) = the
  old 1-tile-orphan flag zone. Both
  library reads are DOWN-GRADED TO
  PROPOSALS pending his raster verify;
  only '8' @ canvas (29,18) is ruled.
  LEDGER (eye-ruled, canvas): 8 @
  (29,18); 6 @ (29, 25/26); 4 @ (23,
  32). NUMERAL AREA SCALE (300dpi
  extract): numerals ~120-160 px blob
  area; words ~6000+; debris dots
  <100. mapp --around ASCII cannot
  confirm reads (single chars are
  proposal[0], e.g. '1'/'2' = 19/20
  labels) - only the raster confirms.
  NUMERALS RULED BY EYES, batch 2
  (Curtiss, 2026-11-07, raster, canvas
  coords): 12 @ START CELL (10,28) - the
  number's ink begins in cell (10,28)
  and extends rightward/downward from
  there (his first phrasing 'centered
  on the SE corner of (10,28)'
  CORRECTED by him: the coord names
  the FIRST SQUARE THE NUMBER
  STARTS OCCUPYING; the blob centroid
  measured at canvas (10.47,29.0) is
  consistent - the two-digit ink
  straddles cells (10,28)-(11,29)).
  THE READ IS CONFIRMED 12 (the old
  'suspect misread of 17/18' flag on
  this glyph is RETIRED - it really
  is a 12). 20 @ START CELL (11,10) -
  READ CONFIRMED 20 (the old 1-tile-
  orphan zone flag on this glyph
  RETIRED).
  NUMERAL COORDINATE CONVENTION RULED
  (Curtiss, 2026-11-07): a ledger
  numeral coordinate names the START
  CELL - the first square the printed
  number's ink occupies; multi-digit
  numbers extend rightward (and may
  straddle row lines) from that cell.
  Mechanical centroids (mnum census)
  remain the fine-precision cross-
  check; the ledger reference is the
  start cell.
  CONSEQUENCE FOR THE ROOM MAP: the
  printed 12 sits in the SW-center -
  the great hall is on the WEST side
  of the steading, NOT in the NE r04
  where the old draft seated it; the
  old draft's 12 -> r04 came from the
  separate '22' misread glyph at
  (19.5,10.5). The numeral-first
  protocol is working exactly as
  ruled: the anchors are relocating
  rooms the stamping got wrong.
  LEDGER (eye-ruled, canvas, START
  CELL convention): 8 @ (29,18); 6 @
  (29,25) extending into row 26; 4 @
  (23,32); 12 @ (10,28); 20 @ (11,10).
  Both library anchors (12,
  20) now verified reads; '8' ruled.
  REMAINING: 1,2,3,5,7,9,10,11,13,
  14,15,16,17,18,19,21,22,23,24,25
  (+ letters A/B).
  FULL NUMERAL LEDGER RULED (Curtiss,
  2026-11-07, complete raster pass,
  canvas/his-map-square frame, START
  CELL convention - ink extends
  rightward/downward from the start
  cell):
  1: (15,37) 2: (18,32) 3: (21,28)
  4: (23,32) 5: (23,25) 6: (29,26)
  7: (29,32) 8: (29,19) 9: (22,20)
  10: (18,18) 10A: (13,17)
  11: (14,31) 12: (10,28)
  13: (11,32) 14: (4,33)
  15: (2,27) 16: (6,26)
  17: (4,22) 18: (4,14)
  18A: (4,18) 19: (9,3)
  20: (11,12) 21: (10,17)
  22: (19,12) 23: (28,10)
  24: (29,3) 25: (23,3)
  SUPERSESSIONS: 6 (29,25->29,26);
  8 (29,18->29,19); 20 (11,10->11,12).
  The complete pass SUPERSEDES all
  earlier per-numeral positions.
  22 MISREAD FLAG REVERSED: the NE-
  center glyph (old draft ~(19.5,10.5),
  called 'a misread of 12') IS A REAL
  22 @ (19,12) - the open compound
  numeral; the 'misread' claim was
  itself the misread. The great hall
  12 anchor (10,28) SW-center stands.
  Geography consequences vs old draft:
  entry 1 is SOUTH-CENTER (15,37),
  not the west vestibule; kitchen 17
  and workroom 18/18A are WEST (4,22)
  (4,14) (4,18); servants 19 NW (9,3).
  The old draft's room placement is
  broadly overturned - numeral-first
  did its job.
  FRAME TENSION FLAG: the three
  library blob centroids (lattice)
  no longer fit one uniform lattice->
  canvas offset against the ruled
  ledger (12 fits offset (3.5,6.0);
  8 implies y~5.0; 20 implies ~
  (2.4,3.5)) - either the library 8/20
  entries were taught from wrong
  glyphs, or the old canvas<->lattice
  calibration (which was anchored on
  now-overturned draft positions) is
  unreliable. The LEDGER (his frame)
  is ground truth; any lattice
  mapping gets re-derived from the
  26 ruled anchors before blob
  cross-checks are trusted.
  NEXT: per-room wall traces from the
  anchors, one room at a time, doors
  as special walls; old draft grid =
  post-mortem reference only.
  FRAME CLARITY + MROOM v0.1 SHIPPED
  (canvas mroom-tool, gate print bd5d224d
  427b96ace37a11abb4feb3dd, 2026-11-07):
  (1) FRAME DISCOVERY: his ledger
  coords ARE the fit_lattice/hallscan
  frame - X lines 0..X33, Y lines
  Y0..Y40, the seated building bbox
  (west=X2, east=X33, north=Y0,
  south=Y40), constants X0=181.95
  XPITCH=64.2742 Y0=482.00 YPITCH=
  64.5875 already pasted in hallscan.
  The mgrid 39x51 lattice (map-006.
  grid.json) is a DIFFERENT frame
  (whole page); the two relate by a
  not-yet-precisely-derived offset
  (12 blob suggests ~(+3.5,+6); the
  library 8/20 blobs imply others -
  those two library entries were
  taught from wrong glyphs and need
  re-teaching at lattice ~(32.5,25)
  and ~(14.5,18) after verification).
  Blob cross-checks against the
  ledger get re-derived AFTER the
  wall traces, from the 26 ruled
  anchors. (2) MROOM v0.1: room
  wall-trace draft tool - scans
  every X/Y lattice line in a
  window around a ruled anchor
  (default radius 5, PIL pixel
  source on his Termux, hallscan
  constants + CLI overrides), prints
  an ASCII wall map ('|'/'-' SOLID,
  '+' GLYPH door candidates, ' '
  open, '.' interior, '@' anchor,
  '*' ledger numerals with legend),
  and lists DOOR CANDIDATES (glyph
  runs) and GAP CANDIDATES (open
  runs <=3 flanked by solid) with
  line/segment coordinates. KNOWN
  DRAFT ARTIFACT (ruled expected):
  a solid line crossing another
  line bleeds glyph ink into the
  crossing segments - crossings
  appear as door candidates; he
  adjudicates them away. Fixtures
  pass (synthetic 64px frame:
  solid/glyph 19/64 door/open-gap
  detection, crossing bleed, ledger
  marks + legend, window bounds).
  Ledger shipped to his repo path
  extract/g1/map-006.ledger.json
  (heredoc). (3) ROOM 1 ROUND
  OPENED: anchor (15,37), method
  RULED = tool drafts, he
  adjudicates each segment; doors
  are special walls.
  MROOM v0.2 SHIPPED (canvas mroom-tool,
  gate print 0816d5e63b735b6eb1c3acb947-
  690c8a, 2026-11-07): adds --frac
  (per-segment ink fraction table, the
  adjudication aid for ink-dense
  zones) and --glyph/--imgh threshold
  overrides. ROOM 1 FIRST DRAFT READ
  (window X10-X20, Y32-Y40, anchor
  (15,37)): nearly all segments GLYPH
  (0.10-0.50 ink) - the window is the
  busy COMPOUND ZONE (entry + courtyard
  ground clutter; module 13 @ (11,32)
  and 2 @ (18,32) also in-window,
  consistent with his earlier room-2
  zone estimate (15-19,31-33)).
  Y40 READS ALTERNATING SOLID/OPEN =
  the log-post stockade line signature
  (posts with gaps), NOT noise. Tags
  alone cannot adjudicate this zone -
  the v0.2 --frac table is the next
  step for room 1.
  MD5 GATE RESOLUTION + RAW-HASH
  CONVENTION RULED (2026-11-07): the
  v0.2 gate mismatch (his ab41184e...
  vs gate 0816d5e6...) was NOT the
  trailing-newline theory first
  tried. Byte-exact diagnosis: his
  copy = canonical body minus the
  LEADING blank line between canvas
  frontmatter and the shebang - the
  canvas render does not display that
  first empty line, so every paste
  starts one line late (his file:
  10601 bytes, single trailing
  newline, byte-identical otherwise;
  verified by brute-force single-
  byte-deletion md5 match against his
  printed hash). Fix on his side:
  prepend one newline -> exact gate
  0816d5e6..., 10602 bytes. RULED
  GOING FORWARD: (a) gate = RAW-FILE
  md5sum of the body as stored (exactly
  one trailing newline), no
  normalization games; (b) future
  canvas code bodies start directly
  with the shebang - no leading blank
  line after frontmatter - so copies
  are byte-faithful and md5sum matches
  with zero patching. v0.3 will also
  fix the stale "v0.1" banner string.
  CANVAS FIXED ON MY SIDE (2026-11-07):
  mroom-tool canvas body now starts
  directly at the shebang (leading
  blank line removed, render =
  stored bytes). NEW v0.2 RAW GATE:
  md5 ab41184e58b5a1c4550f93378a7b-
  ace7, 10601 bytes, single trailing
  newline. His existing local copy
  ALREADY matches this (his printed
  ab41184e was byte-perfect all
  along, just measured against the
  old 10602 gate that included the
  hidden leading blank line) - he
  needs NO further patch; v0.2 is
  SEATED. Old gate 0816d5e6 retired.
  CANVAS ROUND-TRIP FINDING (2026-
  11-07, followup): removing the
  leading blank line from the canvas
  body does NOT stick - the canvas
  system re-inserts the blank line
  after frontmatter on the round-
  trip, and its render hides that
  first blank line. RULED FINAL: the
  v0.2 gate (and every future gate)
  = md5 of the FRESH CANVAS COPY
  (stored body minus the hidden
  leading blank line, one trailing
  newline). For mroom v0.2 that is
  ab41184e58b5a1c4550f93378a7b-
  ace7 / 10601 bytes. His local file
  was at 10602/0816d5e6 (old
  prepend advice); strip command
  issued to land him on ab41184e.
  v0.3+ gates computed the same way
  - md5sum matches straight off the
  copy, no patch commands.
  ROOM 1 FOLLOWUP DRAFT READS (2026-
  11-07, mroom v0.2 --frac, two
  windows, all PROPOSAL pending his
  raster rulings): (a) window
  15,34 r5 (X10-X20, Y29-Y39): the
  13/11/2 band resolves as THREE
  cells - verticals X11 (Y30-34),
  X14 (Y29-31 + Y33-34, glyph gap
  Y31-33 = door candidate between
  rooms), X18 (Y29-34); top wall
  Y30 (X11-14 and X18-20 runs,
  OPEN X14-X18 - room 11 possibly
  open north), NOT Y31 (Y31 reads
  clutter everywhere). 13 ink in
  X11-14 cell, 11 ink in X14-18
  cell, 2 ink in X18-20 cell. X10
  west boundary solid full height
  (0.79-0.90) EXCEPT one open
  segment Y30-31 (0.28) = west
  gate/door candidate at ~Y30, NEW
  find. South structure = stockade-
  attached box X11-X14 / Y36-Y40:
  tops Y36+Y37 cols 11-13 (0.47-
  0.63), east wall X14 solid Y36-Y40
  (0.79-0.94), internal divider X13
  Y37-39 (0.92/0.88); two cells -
  stairs/tower base proposal. Y32
  col12 0.50 now read as numeral
  13's own ink bleeding into Y32
  segments, NOT a wall. (b) window
  17,37 r3 (X14-X20, Y34-Y40): Y40
  = 1.00 across (stockade SOLID,
  reconfirmed); Y34 wall strength
  (0.49-0.67) continues east
  through X20; room 1 court east/
  north nothing above clutter
  (max 0.39) - leans OPEN-FRONTED
  to compound (bounded W by the
  X11-14 box, S by stockade).
  Banner still says v0.1 (v0.3 fix).
  RULED BY HIS RASTER (2026-11-07):
  the 13/11/2 strip (Y30-Y34, X10-X20)
  is THREE rooms side by side - west
  cell holds 13 (X11-X14), middle
  holds 11 (X14-X18), east holds 2
  (X18-X20); top wall Y30, bottom
  wall Y34. The X14 gap at Y31-Y33
  is the DOUBLE DOORS between rooms
  13 and 11 - a special wall, his
  call. X18 reads solid full run
  (0.84-0.91), no door seen between
  11 and 2. These are the FIRST
  RULED WALLS of the rebuilt map.
  DOOR GEOMETRY RULED (2026-11-07):
  the 13/11 double doors occupy part
  of 4 squares in a 2x2 block across
  the X14 wall line: cells (13,31),
  (14,31), (13,32), (14,32) - i.e.
  corners X13-X15 / Y31-Y33, door
  leaves drawn partway into all
  four squares, centered on the
  room 13/11 divider. Doors are
  special walls; geometry seated
  with the three-room ruling.
  FRAME OFFSET DISCOVERY (his,
  2026-11-07): he realized his "off
  by one" comes from the grid-
  overlay finding - the 31x40 was a
  LOCAL INTERIOR reference system
  and the boundary walls lie right
  OUTSIDE it (walls consume
  tiles / write center-straddle
  pairs). His hand counts start one
  square in from the boundary; the
  mroom/hallscan frame counts from
  the outer boundary line. He ruled
  the door 2x2 block in his
  counting - RECALIBRATION OPEN:
  door geometry entry marked NOT
  FINAL pending the offset pin.
  CALIBRATION PLAN: compare mnum's
  pixel-measured printed numerals
  (12, 20, 8) against ledger
  (10,28), (11,12), (29,19) - three
  ground-truth comparisons decide
  whether the ledger matches the
  tool frame or needs one uniform
  shift; every seated wall ruling
  shifts with the ledger if so.
  NOTHING re-seated until the
  offset is pinned.
  RULED (his, 2026-11-07): the LOCAL
  REFERENCE SYSTEM is the 33x42
  (trace canvas tiles = cells x3..
  x35, y6..y47 in the 39x51 grid;
  interior squares 31x40 = cells
  x4..34, y7..46; boundary walls
  take the outer tile ring - walls
  consume a tile). THE NUMERAL LIST
  (ledger) NEEDS ADJUSTMENT into
  the mroom/hallscan frame - ONE
  uniform transform, not per-room
  patches. Calibration in progress:
  mnum census (printed 12, 20, 8
  pixel positions) vs ledger
  anchors (10,28), (11,12), (29,19)
  pins the exact mapping; then the
  ledger is re-issued corrected and
  all seated wall/door rulings take
  the same uniform shift. Legacy
  transform (cell = 1.0088*lat +
  1.849 / 1.0087*lat + 6.787,
  offset +1.85 +6.79, scale 1.009)
  is the seated cross-check.
  LEDGER ADJUSTMENT RULED + VALIDATED
  (2026-11-07): his ledger list is in
  the 33x42 tile counting (boundary
  wall tiles on the outer ring);
  mroom/hallscan frame = (his x+1,
  his y-1), uniform for all 26
  anchors. VALIDATED against all
  three pixel-truth points in the
  record: printed 12 (mnum mgrid
  (13.5,34) -> hallscan (11.5,27))
  = adjusted 12 (11,27) start cell,
  ink extends right; printed 8
  (mgrid (32.5,25) -> (30.4,18.05))
  = adjusted 8 (30,18); printed 20
  (mgrid (14.5,18) -> (12.5,11.1))
  = adjusted 20 (12,11). Three for
  three - the off-by-one is CLOSED.
  ADJUSTED LEDGER (mroom frame):
  1(16,36) 2(19,31) 3(22,27)
  4(24,31) 5(24,24) 6(30,25)
  7(30,31) 8(30,18) 9(23,19)
  10(19,17) 10A(14,16) 11(15,30)
  12(11,27) 13(12,31) 14(5,32)
  15(3,26) 16(7,25) 17(5,21)
  18(5,13) 18A(5,17) 19(10,2)
  20(12,11) 21(11,16) 22(20,11)
  23(29,9) 24(30,2) 25(24,2).
  Heredoc issued to rewrite his
  extract/g1/map-006.ledger.json.
  DOOR BLOCK: tool-frame seating
  (13,31)-(14,32) across X14 STANDS
  (tool-derived, not his counting);
  in HIS counting the same block is
  (12,32)-(13,33) - both on record.
  Wall rulings unaffected (tool read
  its own frame); only past '*'
  anchor marks were one square off.
  Verify run: mroom 16,36 4 --frac
  with adjusted ledger, '*' must sit
  on numeral-1 ink.
  CORRECTION (his catch, 2026-11-07):
  the Y adjustment in the previous
  entry was WRONG - rule was seated
  as (x+1, y-1); correct rule is
  (x+1, y-2). Cause: printed
  numerals' blob centers sit ON
  lattice lines vertically (mgrid
  y 34.0 / 25 / 18, all exact
  integers); under his ruled
  start-cell convention (ink extends
  downward from the start square) a
  line-centered numeral's start row
  is the line MINUS ONE. I treated
  the center as the start row -
  cost exactly one row. Ground
  truths re-checked under (x+1,
  y-2): 12 -> start (11,26), 8 ->
  (30,17), 20 -> (12,10) - all
  three exact. SUPERSEDED: previous
  adjusted list void. CORRECT
  LEDGER (mroom frame): 1(16,35)
  2(19,30) 3(22,26) 4(24,30)
  5(24,23) 6(30,24) 7(30,30)
  8(30,17) 9(23,18) 10(19,16)
  10A(14,15) 11(15,29) 12(11,26)
  13(12,30) 14(5,31) 15(3,25)
  16(7,24) 17(5,20) 18(5,12)
  18A(5,16) 19(10,1) 20(12,10)
  21(11,15) 22(20,10) 23(29,8)
  24(30,1) 25(24,1). Heredoc
  issued. Note: door-block and
  wall rulings seated in tool frame
  remain valid - but the earlier
  door-block "his counting =
  (12,32)-(13,33)" note is also
  superseded: his-count -> tool =
  (+1,-2), so tool (13,31)-(14,32)
  = his (12,33)-(13,34).
  TRANSFORM RULED BY HIM (2026-11-07,
  third and FINAL attempt, no more
  derivations): ledger adjustment =
  (x+1, y+1) - the boundary walls
  sit in their OWN squares on all
  sides and are accounted on all
  sides; x+1 confirmed, Y is +1.
  SUPERSEDED AND VOID: (x+1, y-1)
  and (x+1, y-2) entries above -
  both were my derivations. NOTE
  the y-2 "validation" was partly
  CIRCULAR: only printed 12
  (mgrid 13.5,34) was an independent
  measurement; the 8/20 re-teach
  targets (32.5,25)/(14.5,18) were
  computed FROM the ledger via the
  (+3.5,+6) mapping, so they could
  never disagree - do not trust that
  check again. CORRECT LEDGER
  (mroom frame): 1(16,38) 2(19,33)
  3(22,29) 4(24,33) 5(24,26)
  6(30,27) 7(30,33) 8(30,20)
  9(23,21) 10(19,19) 10A(14,18)
  11(15,32) 12(11,29) 13(12,33)
  14(5,34) 15(3,28) 16(7,27)
  17(5,23) 18(5,15) 18A(5,19)
  19(10,4) 20(12,13) 21(11,18)
  22(20,13) 23(29,11) 24(30,4)
  25(24,4). Heredoc issued.
  Verify: mroom 16,38 4 --frac,
  '*' must sit on numeral-1 ink
  above the Y40 stockade. Earlier
  door-block "his-count" notes void;
  his-count -> tool = (+1,+1), tool
  (13,31)-(14,32) = his (12,30)-
  (13,31).
  VERIFY RUN READ (2026-11-07, mroom
  window 16,38 r4 = X12-X20,
  Y34-Y40, corrected ledger): the
  numeral-1 glyph cannot be
  confirmed by ink pop (single
  digit inside compound-zone soup,
  clutter 0.17-0.23) - BUT the
  structure confirms: Y34 wall shows
  a GATE at cols 15-16 (frac dip
  0.49 vs 0.62-0.67 either side),
  the ONLY Y34 opening flagged in
  any window scanned so far,
  sitting DIRECTLY NORTH of the
  corrected anchor (16,38). PROPOSE:
  room 1's entry door through the
  Y34 wall into the court. Second
  find: X15-X20 all read 0.35-0.39
  on the Y39-40 segment - continuous
  elevated ink strip along the
  stockade's north face (walkway /
  double-drawn stockade / hatch
  bleed - his eyes). Y40 = 1.00
  across, reconfirmed. HIS EYES
  CHECK PENDING: printed "1" at
  (16,38). If confirmed, ledger
  seated with (x+1, y+1) as the
  standing transform; next window
  15,32 r4 for the Y30-Y34 band
  with corrected 13/11/2 anchors.
  BAND WINDOW READ (2026-11-07,
  mroom 15,32 r4 = X11-X19, Y28-
  Y36, corrected ledger): TRANSFORM
  VALIDATED NON-CIRCULARLY by
  printed 12 itself - ink signature
  exactly at corrected anchor (11,29)
  (his count (10,28)): elevations
  X11/X12 seg Y29-30 (0.30/0.31) +
  Y28 col 11-12 (0.36), blob center
  (11.5,29), ink right/down from
  start cell. Wrong rules would
  have put it rows 26-27 (nothing
  there). His eyeball check: printed
  "12" at his (10,28). BAND
  RECONFIRMED: X11 solid Y30-34;
  X14 solid Y28-31 + gap Y31-33
  (double doors) + solid Y33-34;
  X18 solid full Y28-34 (no door
  11/2); Y30 top: solid X11-14,
  OPEN X14-18, solid X18-19; Y34
  full with entry-gate dip col 15-16
  (0.49). RETRACTION: the X13/Y31-32
  cluster (0.65 + Y32 col 12-13
  0.50) is NOT numeral 13's ink - 13
  is not printed (mnum census: only
  12/20/8 printed; other 23 exist in
  key only). Cluster = UNIDENTIFIED
  ink feature inside room 13 (his
  eyes). Room 11 + 2 cells read
  clean (not printed - consistent).
  NEW FLAG - NE CORNER: X19 solid
  Y28-29 (0.82) + Y29 col 18-19
  (0.42) + Y30 col X18-19 (0.73) =
  wall stub north of room 2, his
  count ~(17-18, 27-29) - small
  room / corridor / corner structure,
  his eyes. Ruling backlog: Y30
  open run; X10 west gate ~Y30; X13
  cluster; NE corner; room 1 open
  N/E; stockade-side strip X15-X20
  on Y39-40 (0.35-0.39).
  ROOM 1 DOOR/STAIRS RULING (his,
  2026-11-07, focus narrowed to room
  1 only per his instruction): room
  1 has FOUR door openings - 2
  single doors, 1 double door, 1
  3-wide double door - AND stairs
  up at 1B. Proposal (pending his
  confirm): the X11-X14 stockade box
  (two cells, X13 divider) = the
  stairs, X13 split = 1A/1B, room 1
  includes the box, west boundary =
  X10 full-height wall. Y34 opening
  (tool cols 14-16, frac 0.58/0.49)
  = candidate for the 3-wide double
  (entry) or the double - opening
  is 2 segments wide in frac. The
  other 3 doors not yet found by any
  tool read - likely east side
  beyond X20 (unscanned); radius-6/8
  window on 16,38 requested to find
  them. Nothing else seated from
  this until he confirms locations.
  ROOM 1 FULLY RULED (his rulings,
  2026-11-07, coordinates verbatim,
  tool frame, NO adjustment; his
  coordinate statements SUPERSEDE my
  square-count assumptions): Door
  (10,35)-(10,36) single, west wall
  X10 rows 35-36 (tool read X10
  0.82/0.87 there = door-leaf ink,
  doors are drawn ink not gaps).
  Double door (15,35)-(16,36),
  north wall Y34, cols 15-16 = the
  0.49 frac dip found earlier,
  opening and ruling agree. Door
  (22,35)-(22,36) single, east
  wall X22 rows 35-36 - ROOM 1
  EXTENDS EAST TO X22, past all
  windows run so far. 3-WIDE DOUBLE
  DOOR (22,37)-(23,40) = 2 cols x
  4 rows = 8 SQUARES (his ruling:
  "that calculates to 8 squares" -
  supersedes the earlier 6-square
  statement), east wall X22, rows
  37-40. STAIRS (TOWER) 1B
  (10,38)-(13,41): SW-corner tower,
  cols 10-13 rows 38-41, extends
  through the Y40 stockade line -
  the DASHED LINES there represent
  NEXT-LEVEL dimensions, not this
  level's walls (also likely
  explains the Y36+Y37 moderate
  ink cols 11-13, 0.47-0.63, as
  dashed-line reads). ASSEMBLY:
  room 1 = north Y34 (double door
  cols 15-16), west X10 (single
  rows 35-36), east X22 (single
  rows 35-36 + 3-wide double rows
  37-40), south Y40 stockade,
  tower SW (10,38)-(13,41) stairs
  up at 1B. FOUR doors, exactly as
  ruled. Open minor: X14 solid
  Y36-40 read vs tower east at
  X13 (adjoining wall or next-
  level dashed - unruled); Y39-40
  strip X15-X20 0.35-0.39 (walkway
  or dashed - unruled). Next:
  verification window 16,38 r6
  (X10-X22, Y32-Y40) to trace the
  never-scanned X22 east wall and
  door ink, then next room on his
  lead.
  RULED (his, 2026-11-07): the
  room 1 coordinates he provided
  are ACCEPTED as ruled - doors
  (10,35)-(10,36), (15,35)-(16,36),
  (22,35)-(22,36), 3-wide double
  (22,37)-(23,40), tower/stairs 1B
  (10,38)-(13,41). Math checked
  against hallscan constants (pixel
  rects computed and shown to him);
  no tool read conflicts with any
  of them (double door exact-match
  independent, X10/X13 corroborated,
  Y36-37 ink = dashed next-level
  lines per his ruling, X14 solid =
  unruled leftover, east wall X22
  + doors unverified blind spots -
  no contradictions). ROOM 1 IS
  SEATED: north Y34 (double door
  cols 15-16), west X10 (single
  rows 35-36), east X22 (single
  rows 35-36 + 3-wide double rows
  37-40), south Y40 stockade,
  tower 1B SW (10,38)-(13,41)
  stairs up. First complete room
  of the numeral-first rebuild.
  MROOM v0.3 SHIPPED (2026-11-07,
  canvas mroom-tool): --bbox
  X1,X2,Y1,Y2 added - window is
  exactly that rectangle in
  lattice lines, everything
  outside ignored (his design
  intent: focus a region, ignore
  the rest). Anchor and --bbox
  mutually exclusive (clean CLI
  errors); anchor mode unchanged
  and backward compatible; bbox
  lines may extend beyond the
  building bbox (tower rows to
  Y42) - fit lattice
  extrapolates, no caps in bbox
  mode. Banner fixed: now prints
  "mroom v0.3 draft". GATE
  (fresh canvas copy): md5
  6b9780bdd1f579003a7fc53c0977-
  956ca, 11984 bytes. Tested:
  compile OK, synthetic-raster
  unit test (trace bounds,
  no-anchor render, ledger
  marks, door candidates, sub-
  bbox), CLI end-to-end both
  modes incl. banner + window
  lines, error cases. ROOM 1
  WALL VERIFICATION PLAN (his
  intent - bbox windows):
  --bbox 10,22,32,40 (room
  outline; expect Y34 wall-level
  w/ dip at col 15-16, X10 and
  X22 solid full height, Y40 =
  1.00, court interior clutter)
  then --bbox 9,15,36,42
  (tower + dashed zone; X10/X13
  solid below stockade, Y41
  south edge wall-level, dashed
  next-level lines ~0.4-0.6,
  X14 leftover resolved).
  ROOM 1 WALL VERIFICATION VERDICTS
  (2026-11-07, mroom v0.3 --bbox
  runs, first bbox windows ever run):
  BOX 1 (10,22,32,40) ALL FOUR WALLS
  PASS - room 1 outline VERIFIED BY
  INK: Y34 north 0.52-0.71 wall-
  level, only dip 0.49 at col 15-16
  = seated double door; X10 west
  solid 0.79-0.89 unbroken (single
  door rows 35-36 reads as ink
  0.87-0.89); X22 east profile
  matches BOTH ruled doors - single
  at rows 35-36 reads 0.61 (leaf
  ink), 3-wide double opening dips
  0.43/0.30 at rows 36-38 (adjacent
  ruled rows 37-40), back to
  0.76/1.00 at stockade corner; Y40
  1.00 x12; court interior clean
  0.17-0.39, nothing unaccounted.
  SIDE-NOTE PARKED: X21 solid rows
  32-34 (0.79/0.82) = second wall W
  of X22 north of Y34 - room 2 east
  side or corridor, later. BOX 2
  (9,15,36,42) TOWER: X10 west
  solid 0.83-0.89 rows 36-39 fading
  0.58 at 39-40; X14 east solid
  0.79-0.87 rows 36-39 - X14
  LEFTOVER RESOLVED = tower's east
  wall (block edge line X14), not
  separate structure; X13 internal
  divider 0.92/0.88 rows 37-38;
  dashed next-level lines found at
  Y36+Y37 (0.47-0.63 cols 11-13)
  and row 39-40 band (0.53-0.58
  cols 10-14). BELOW-STOCKADE
  EMPTY: Y41 and Y42 = 0.00 across
  cols 9-15 - no ink at DARK=128
  threshold south of stockade;
  rows 40-41 of tower block have no
  drawn ink at threshold. OPEN
  QUESTION for his eyes: are the
  dashed dim lines south of
  stockade lighter than 128 (offer
  --dark option in v0.4) or
  further east/south of this box?
  CORRECTION (his, 2026-11-07):
  ROOM 1 IS NOT CLOSED - do not call
  it verified again until the full
  wall inventory is ruled. The
  four main walls (Y34 N, X10 W,
  X22 E, Y40 S) are only PART of
  the room: (1) THREE MORE WALLS
  are EXTERNAL to the outside -
  beyond/outside the main
  rectangle (candidate read: the
  tower's south-of-stockade faces
  at Y41 - its south wall + the
  two returns - which read 0.00
  at DARK=128, so either lighter
  ink or the --dark threshold
  issue); (2) the four main walls
  have SHAPE - not simple straight
  full-span lines (candidate: the
  X21 solid rows 32-34 next to
  X22, and the X22 profile
  1.00/0.61/0.43/0.30/0.76/1.00
  shape at the doors); (3) FIVE
  WALLS AT 1B - the stairwell/
  tower structure has 5 walls,
  attached to the stairwell but
  PART of room 1 (candidates from
  ink: X10 west, X13 internal
  divider, X14 east, plus N and S
  faces). Total known wall count:
  4 main + 3 external + 5 at 1B =
  12 walls in room 1. AWAITING
  his wall-by-wall rulings in the
  same coordinate style as the
  doors (endpoints per wall, which
  walls bend/step, where the 3
  external walls sit, the 5 at
  1B).
  WALL-INVENTORY CLARIFICATION
  (his, 2026-11-07): the 3 EXTERNAL
  walls are NOT separate walls -
  they are the external portions of
  3 INTERNAL walls. Each of those
  three is ONE wall that runs from
  inside the room to outside - DO
  NOT seat them as split internal/
  external segments. Room 1 wall
  inventory as now understood:
  4 main walls (with shape) +
  3 internal walls that extend
  externally (each one wall, seated
  once, full extent) + 5 walls at
  1B stairwell = 12 walls.
  AWAITING his coordinate rulings
  (endpoints per wall; corner
  points where shaped walls bend).
  WALL COUNT CORRECTED (his,
  2026-11-07): NOT 12. Room 1 has
  NINE walls total = 4 main walls +
  5 walls at the 1B stairwell.
  THREE of the four MAIN walls have
  EXTERNAL portions - the external
  parts belong to those main walls
  themselves (the "3 external /
  3 internal" framing is void -
  there are no separate internal
  walls; the 3 main walls simply
  continue outside, and are NOT
  split at the boundary). Each main
  wall is seated once, full extent,
  inside and out, shape included.
  AWAITING his coordinate rulings:
  endpoints per wall, corner points
  where shaped walls bend/step,
  which 3 of the 4 main walls
  extend externally and how far.
  STANDING WORKFLOW CONVENTION (his
  teaching, 2026-11-07 - PROCESS
  RULE, applies to all future map
  work): (1) WORK INSIDE THE BOX
  ONLY. He gives the region/bbox;
  the tool scans exactly that; all
  reads, adjudications, proposals
  stay INSIDE it. No side-notes, no
  parking outside items, no
  commentary on features beyond the
  box - that is the distraction to
  cut (he called out my X21
  side-note as exactly this
  mistake). Outside features get
  their own region when HE asks for
  it, never preemptively. (2) The
  bbox he gives does NOT need to be
  precise - it just needs to
  contain the room; from it plus
  tool reads plus his rulings the
  precise room bbox is CALCULATED
  by me after verification. (3)
  Rough-box-first is deliberate -
  narrow focus, productive
  adjudication, room-by-room.
  Seated as standing practice.
  CLARIFICATION (his, 2026-11-07,
  IMPORTANT - supersedes any
  contrary assumption): coordinates
  he gives NOW (bboxes, regions,
  anything "new coordinates") are
  used AS-IS. DO NOT apply the
  (x+1,y+1) transform or any
  conversion to them - "you'll mess
  up the coordinates." The tool
  frame and his current numbering
  are the same thing now; any
  transform attempt on new input is
  an error. The transform remains
  on record ONLY for converting the
  OLD ledger/list if that ever
  comes back into play - never for
  new coordinates he provides.
  ROOM 1 BBOX RULED (his, new
  coordinates, AS-IS - no
  transform): (9,35)-(22,42) =
  --bbox 9,22,35,42. NOTE the
  bounds differ from my old
  verification windows (Y35-42, not
  Y32-40): room 1's region per him
  runs Y35..Y42 (lower than I had,
  reaching the tower's south extent)
  and X9..X22 (one col wider west
  than my X10). My 10,22,32,40
  "outline box" was a window, not
  the room's bbox - his box is the
  ruling. Scan INSIDE it only.
  ROOM 1 CROP ANALYZED (2026-11-08,
  room1.png pulled from repo commit
  7fe1a2ea, decoded + analyzed in
  sandbox: PNG via stdlib zlib, red
  grid filtered, dual thresholds
  dark<128 / light<220, plus
  nonwhite<250 scan). FINDINGS,
  INSIDE BOX (9,35)-(22,42) ONLY:
  (1) THE FIVE 1B STAIRWELL WALLS
  ALL VISIBLE, matching his count:
  X10 west 1.00 rows 35-39; X13
  internal divider 1.00/0.96 rows
  37-38; X14 east 0.94-0.99 rows
  36-39; Y36 line cols 11-13
  (0.78/0.69/0.58) and Y37 line
  cols 11-13 (0.60/0.61/0.35) =
  TWO horizontal faces - stairwell
  has upper cell (rows 36-37) and
  lower cell, i.e. 5 faces total.
  (2) STOCKADE IS THICK: Y40 line
  1.00 all 13 cols, and the
  palisade body extends ~0.6
  SQUARE SOUTH of the line (ink
  rows Y40.00-Y40.60, texture =
  picket ticks on south face) -
  EXPLAINS his tower ruling
  (10,38)-(13,41): the tower's
  south extent = the stockade's
  own south face ~Y40.6 ("extends
  through the stockade"), and
  likely explains "external
  portions" of main walls - walls
  crossing the stockade body
  (X10 row 40 = 0.57, X22 row 40 =
  0.28) run into the external
  zone by its thickness. (3)
  SOUTH OF Y40.6: ABSOLUTELY
  EMPTY - Y41-Y42 band min gray
  244, nonwhite 0.001 - no dashed
  lines, no ink of any weight in
  cols 9-22. The dashed next-
  level dim lines are NOT in this
  box south of the stockade;
  either they are the picket
  texture on the stockade south
  face, or outside this box, or
  his ruling needs revisit - ASK
  HIM. (4) Doors visible: west
  single door panel at X10 Y35-36
  (dark blob in render); east
  doors at X22 - single leaves
  rows 35-36 (0.49/0.19), 3-wide
  opening rows 37 (0.28) then
  solid 0.82/1.00 rows 38-39 =
  door structure drawn, matches
  rulings. (5) Numeral 1 ink at
  c16-17 rows 38-39 confirmed
  (0.25-0.41 dark). (6) Light
  ink 0.3-0.6 pervasive across
  court interior cols 15-20 =
  scan shading, not features.
  AWAITING his 9-wall rulings.
  CROP VIEWING PATH (his device,
  2026-11-08): Android Photos cannot
  reach Termux private storage; the
  working route is cp to
  ~/storage/shared/Pictures/ then
  termux-open (or Photos app) from
  there. His first look at room1.png
  told him: MISSING 2 ROWS OF SQUARES
  AT THE TOP - the crop top line is
  Y35, so rows 33-34 (the Y34 north
  wall + band context above it) are
  out of frame. Crop needs
  regenerating with top at Y33
  (or wherever he rules). His ruled
  room-1 bbox may effectively be
  (9,33)-(22,42); the Y35 top was
  too low. AWAIT his ruling on the
  corrected top bound.
  THE +2 DISCONNECT (2026-11-08,
  measured, not assumed): HIS
  self-derived SQUARE-ROW numbers
  are LATTICE Y + 2 (columns
  aligned, X offset 0 in squares).
  Evidence, three independent
  structures: (1) his room bbox
  (9,35)-(22,42) intended lattice
  (9,33)-(22,40): explains 2 rows
  missing at crop top (lattice rows
  33-34 = band + Y34 north wall),
  explains the empty row at crop
  bottom (lattice row 41, below
  stockade), and makes his bottom
  bound 42 = the stockade line Y40 =
  the room's south wall - the bbox
  was the COMPLETE ROOM incl. walls
  all along; (2) his tower ruling
  (10,38)-(13,41) = lattice rows
  36-39 = measured stairwell extent
  (Y36 north line to Y40 stockade),
  cols 10-13 = lattice X10-X14
  aligned; (3) handoff's old "X21
  rows 42-44 dashes" = lattice rows
  40-42 = stockade picket texture
  zone - consistent only with +2.
  His wall-LINE labels (Y34, Y40)
  ARE lattice frame - adopted from
  mroom reads. So: coords from tool
  reads = lattice; coords he counts
  himself = Y+2 (likely because his
  counting includes 2 rows above the
  lattice Y0 origin - the band rows;
  ASKED him to confirm the source).
  AMENDS the "as-is, no transform"
  ruling: his numbers were believed
  to equal tool frame; they do not -
  +2 in Y. mcrop/mroom --bbox remain
  LATTICE frame. Correct room-1
  crop: --bbox 9,22,33,40 (revert
  the x0 +10; old fit X0=181.95
  verified inside wall bands; crisp
  strokes at +4.3 = wall edge
  detail, not fit error). His 10px
  guess was the hatch band
  misleading the eye.
  +2 RULE CONFIRMED (his, 2026-11-08):
  he counts the band rows (numbered
  strip above the north wall) as
  his rows 1-2 - that IS the source
  of the offset. PERMANENT RULE:
  his Y - 2 = lattice Y; his X =
  lattice X. Applies to any
  coordinate he derives himself on
  the map. Wall-line labels from
  tool reads (Y34, Y40) stay
  lattice. mcrop/mroom --bbox =
  lattice frame.
  NEW DIRECTION (his, 2026-11-08,
  supersedes his earlier pre-analysis
  ideas): CREATE THE NEW MAP ONE
  REGION AT A TIME. Region 1 = room
  1, crop now finalized (9,23)-(33,41)
  lattice, committed e053253d, frame
  verified in sandbox. The per-region
  workflow is proven: crop with
  mcrop -> his eyeball -> my pixel
  reads -> his adjudications ->
  build that region of the new map ->
  next region. Repo already has
  extract/g1/map-006.regions.json
  (region structure on file). His
  region coords = lattice Y-2 rule
  applies when he gives bounds.
  YARD EXPANSION (his, 2026-11-08):
  the new upper-level map gains 10
  squares on EACH SIDE of the
  building - a yard around the
  keep. Arithmetic: building naive
  31x40 + 20 per axis -> yard-incl
  naive 51x60 squares; with the
  center-distribution boundary
  (+1 tile per side) -> TILE CANVAS
  53x62 (was 33x42). Engine 64x64
  grid still fits (53<64, 62<64,
  margins 11 and 2). OPEN: whether
  the squares cross-check field
  stays 31x40 (module count) with
  the yard as surrounding terrain,
  or the canvas squares field
  becomes 51x60; whether the yard
  applies on all four sides
  equally; yard tiles = open
  ground, building walls embedded
  with 10-square clearance. The
  region-at-a-time build covers
  the building regions; the yard
  is surrounding canvas.
  ENGINE SCOPE RULE (his,
  2026-11-08): do NOT plan engine
  changes for map size - the
  engine's 64x64-tile grid is
  taken as fixed. The ONLY engine
  fix he wants: the tile size
  set to 64x64. The yard canvas
  (53x62 tiles) fits inside the
  existing 64x64 grid; if a future
  map outgrew it, that is a later
  problem, not a driver now.
  AMENDMENT (his, 2026-11-08,
  supersedes the last engine note):
  do NOT make map size fixed in the
  engine - map dimensions must be
  free/declared per map, not a
  compile-time 64x64 constraint.
  The only engine change he wants
  remains: tile size 64x64. The
  64x64 grid mention is NOT a cap
  to keep; the engine reads map
  dims from the map data.
  TILE SIZE CLARIFIED (his,
  2026-11-08): 64x64 means 64
  PIXELS by 64 PIXELS per square
  (tile) in the map - the single
  engine fix is the per-tile
  pixel size of 64x64. Map
  dimensions remain free per map
  data (previous amendment
  stands).
  RUNTIME NOTE (his, 2026-11-08):
  the 64x64-px tile canvas at 51x60
  squares (3392x3968 px) poses no
  problem to whatever system runs
  the map - no special handling
  needed or planned.
  BOUNDARY WALL PLACEMENT AMENDED
  (his, 2026-11-08, supersedes part
  of the wall-offset doctrine):
  CENTER DISTRIBUTION now applies
  to INTERNAL walls only (straddle
  pairs as before). BOUNDARY walls,
  per our lattice discovery (wall
  ink lives INSIDE its square:
  west wall hatch 772-832 sits in
  the square between the X9/X10
  lines; stockade band + body sit
  in the square below the Y40
  line), occupy their boundary
  square directly - NO straddle
  outside the naive extent, NO +1
  tile per side. Tile canvas =
  naive square count: with the
  yard, 51x60 tiles (was 53x62);
  rendered 3264x3840 px at 64px
  tiles. Battery: boundary walls
  verify as single-tile in the
  outer ring; interior wall
  straddle pairs symmetric as
  before. walldist field stays
  declared; the naive squares
  field = module count 31x40
  building / 51x60 with yard.
  BUILDING POSITION RULED (his,
  2026-11-08): CENTERED on the
  51x60 canvas. The yard is
  exactly 10 squares on every side
  (51-31=20, 60-40=20 - even both
  axes). Building occupies canvas
  square indices 10..40 x 10..49
  (0-based). Mapping rule: lattice
  square (x,y) -> canvas
  (10+x, 10+y); his square numbers
  -> lattice first (y-2). Room 1
  interior lattice cols 10-21 /
  rows 35-39 -> canvas cols 20-31
  / rows 45-49. All canvas rulings
  now CLOSED: 51x60 tiles, 64x64
  px, boundary walls in their
  squares, internal walls center
  distributed, building centered.
  FLOOR TILE (his, 2026-11-08):
  the crop stands as-is, approved.
  A floor tile for the whole
  building already exists in the
  map/tileset - building floors
  are covered; customization of
  floors can happen later as we
  see fit (deferred, not
  blocking).
  TILE GENERATION DOCTRINE (his,
  2026-11-08, supersedes the
  nine-walls pixel-read ritual):
  the new map's tiles are
  GENERATED - pixel perfect by
  construction. No pixel-ink
  readings needed for tile art.
  Raster reads serve only to
  adjudicate STRUCTURE (what
  exists and where: walls, doors,
  stairs, extents); the tile art
  itself is generated clean from
  the ruled structure. The nine
  walls of room 1 do NOT need
  pixel readings; region builds
  proceed from adjudicated
  structure + generated tiles.
  NEW MAP FILE (2026-11-08,
  built + verified in sandbox,
  shipped): tools/mkmap.py, pure
  stdlib (no PIL), generates the
  new-map ORA at 51x60 squares
  64px = 3264x3840. INITIAL LAYERS
  (his reasons: tells us where
  floor/ground tiles need to be
  placed): layer base = ALL BLACK
  (nothing placed yet), layer grid
  = 1px PURE RED lines at every
  square boundary (51 vertical +
  60 horizontal; the outermost
  boundary IS the canvas edge - a
  line there would eat a pixel
  into the last square and break
  64px geometry). Format =
  OpenRaster .ora (Krita/GIMP,
  true layers), plus merged
  preview PNG for Photos viewing.
  Verified in sandbox: mimetype
  first/stored, stack.xml base
  then grid, all pixel checks
  passed. Shipped as single b64
  code canvas (6.4K, under the
  15K clip), md5
  966317343535e90aa84a77f78dab6f89.
  DELIVERY FIX (2026-11-08): raw
  b64 paste failed twice in Termux
  (paste went to shell prompt /
  decode produced empty file).
  GitHub connector is READ-ONLY for
  Adnd1 (403 no write scope) - no
  direct push. SOLUTION: paste-proof
  echo block - the script b64
  re-wrapped as 90 shell commands
  (echo 'LINE' >> ~/Adnd1/tools/
  mkmap.b64), each line a complete
  command, no stdin state needed.
  Verified by roundtrip: executing
  the block rebuilds byte-exact,
  md5 966317343535e90aa84a77f78dab6f89.
  Canvas mkmap-script updated to the
  echo block. If paste aborts
  midway: rm the .b64 and re-paste
  whole block.
  DELIVERY AMENDED (his, 2026-11-08):
  NO BASE64 - he overruled the b64
  ritual for this script. Canvas
  mkmap-script now holds the PLAIN
  mkmap.py source (type code,
  language python). He pastes it
  into an editor on device.
  md5 966317343535e90aa84a77f78dab6f89
  unchanged.
  MKMAP v2 (2026-11-08): he
  spotted the grid's outer frame
  was unbounded right/bottom (my
  earlier design choice - lines
  can't sit at 3264/3840,
  off-canvas). FIX: grid and
  merged now draw frame lines at
  w-1 / h-1 (canvas edge) -
  52 vertical + 61 horizontal
  lines, complete frame all four
  sides. Cell math unchanged
  (squares still 64px, tiles at
  64*k). Verified in sandbox;
  md5 9b4d1d0c9ae52091a33325e5a3046bab.
  Canvas mkmap-script updated
  (plain python, no b64).
  MKMAP v3 (2026-11-08): he
  reported "multiple offset
  grids" in the preview. VERDICT:
  the generated file is byte-perfect
  (one grid, 52+61 lines, verified);
  the ghosts are VIEWER MOIRE -
  phone fit-to-screen downscales
  3264x3840 ~8x and 1px lines on
  64px pitch alias into offset/finer
  phantom grids (vision model
  downscales too and sees the same
  ghosts). LESSON: for eyeball
  verification on his phone, do NOT
  rely on heavily downscaled 1px
  grids. FIX: --small N (default 8)
  writes <preview>_small.png at
  Npx/square (408x480 @ 8px) drawn
  at that scale - native on the
  phone, moirE-proof, same
  geometry (52+61 lines incl.
  frame). Zoom to 100% on the big
  preview also dissolves the
  ghosts. md5
  a9e5bff29726a45dd7e842ae767b92b9.
  Canvas updated.
  MOIRE CONFIRMED (his, 2026-11-08):
  he zoomed the full preview and the
  ghost grids vanished - viewer
  moire, file clean. Grid
  verification CLOSED: the new-map
  file maps/upper_level.ora stands
  (51x60 @ 64px, base + grid
  layers, byte-verified, pushed
  17239887). Next open thread:
  first region build (room 1
  floors/ground over the black).
  REGION 1 FLOOR BUILD (2026-11-08):
  tools/mkplace.py (pure stdlib)
  adds a FLOOR layer between base
  and grid in the ORA: yard tile
  across all 1820 non-building
  squares (adjudication "outside
  is yard" from yard.json),
  stone_floor tile across room 1
  interior = canvas cols 20-31
  x rows 45-49 (60 squares,
  12x5). Unbuilt building squares
  stay black. Base and grid layer
  bytes unchanged; stack order
  base->floor->grid; mergedimage
  recomposited (floor visible,
  red grid on top); thumbnail
  nearest-shrunk. ALL placement
  checks passed in sandbox
  (byte-identical tiles at all
  probed squares, transparent
  holes, boundary col9-yard/
  col10-hole, merged composite
  correct). Tiles used:
  content/sites/g1/tiles/
  stone_floor.png + yard.png
  (64x64 RGB, seamlocked).
  Shipped as plain-python canvas
  mkplace-script. Rects are
  CLI-overridable (--building,
  --room1) defaulting to the
  seated rulings.
  MKPLACE v2 (his ruling, 2026-11-08):
  grid layer DROPPED from the map
  (floors placed, grid served its
  purpose), and preview is NORMAL
  SIZE only (no _small). ORA now
  2 layers: base -> floor; stack
  base+floor; merged = base+floor
  composite, zero red. md5
  acd91c10e3cb9ff5d68a6b8d45e640fa.
  Canvas mkplace-script updated.
  REGION-AT-A-TIME CONFIRMED (his,
  2026-11-08): stone floor limited
  to room 1 region on purpose -
  each room's region gets its
  floor when that region is
  worked. Current state: yard ring
  + room 1 stone placed, grid
  layer dropped, normal-size
  preview. He has not yet pushed
  the v2-placed ORA for byte
  verification.
  PLACEMENT MODEL RULED (his,
  2026-11-08, 2 decisions):
  1) MULTI-SQUARE TILES: single
  rect stamp - master baked at
  exact n*64 x m*64 px, stamped
  once at its origin square,
  WITH optional pixel offset if
  set. COVERAGE REGISTRY: the
  stamp registers every square it
  covers; covered squares are
  FLAGGED as rendered-by-origin so
  their own layer does NOT draw -
  the origin square does all
  rendering (no double-draw, and
  the flag tells region builds the
  square is accounted for).
  2) OFFSET TILES (walls, doors):
  pixel-rect placement - art
  stamped at exact adjudicated
  pixel geometry, free to cross
  square boundaries (center-
  distribution straddles, door
  coverage extents). Squares are
  the lattice reference and the
  battery's alignment checks, not
  a cage. Layer stack above floor:
  walls, then doors, then features
  (stairs/numerals). Data voice
  (wpair, DCOV, square->owner
  registry) feeds the engine; the
  ORA paints the same truth in
  pixels. mkplace v3 will take a
  placement manifest.
  REMINDER APPLIED (his,
  2026-11-08): wall tile geometry
  is ALREADY RULED - all wall
  tiles center distributed
  (straddle pairs), special wall
  tiles (door tiles) included;
  boundary walls in their squares
  per the boundary amendment. Do
  not re-ask wall rendering style.
  AGREED STARTING POINT: room 1
  walls first (only fully
  adjudicated region, backbone for
  doors/stairs/features, proves
  the full placement model on one
  region). Room 1 tile inventory:
  boundary wall segments ->
  interior straddle strokes ->
  corner/T-join pieces -> 5 door
  tiles (pixel-rect at measured
  runs) -> stairwell (2x2 rect
  stamp, first multi-square tile)
  -> numeral 1 (features layer).
  NEXT: generate new wall
  primitive master(s) per the
  primitive-generation template
  (stone wall subject), wrapped +
  baked per repo convention.
  NUMERAL LAYER RULED (his,
  2026-11-08): the numeral (1)
  gets its OWN LAYER in the ORA -
  separate from stairs/features -
  so it can be displayed at will
  (toggled on/off). Placement
  manifest will carry a layer
  field per stamp; stack becomes
  base -> floor -> walls ->
  doors -> stairs -> numeral.
  TEXT PLACEMENT REGISTRY RULED
  (his, 2026-11-08, SUPERSEDES the
  numeral-layer ruling): NO raster
  layer for numerals/text. Instead
  a LOOKUP LIST of text entries -
  any text, not just numbers -
  with positions; display system
  (engine/preview) renders them
  at will. Saves the layer memory
  entirely. Numeral "1" becomes
  the first registry entry.
  Proposed schema: id, text, at
  (square + px offset), anchor,
  size, color, layer tag (so
  different text groups can be
  shown/hidden at will). ORA
  stack back to: base -> floor ->
  walls -> doors -> stairs (no
  numeral layer). A preview tool
  can burn registry text in on
  the fly for eyeball checks -
  rendered, never stored.
  LABELS REGISTRY DRAFTED
  (2026-11-08): maps/
  upper_level_labels.json - text
  placement registry per the
  ruled schema. First entry:
  room1 numeral "1" at square
  [26,47] (DRAFT position - court
  center of room 1 interior
  cols 20-31/rows 45-49; needs
  his confirmation or correction
  from the raster), center
  anchor, 64px, white, group
  room-numerals. Shipped as
  plain-json canvas
  upper-level-labels. Nothing in
  the ORA - rendering on demand
  only. Wall details still open,
  to be ruled as met.
  CONTENT TREE CORRECTION (his,
  2026-11-08): do NOT invent
  top-level dirs - site data lives
  in content/sites/g1/ (site.json,
  primitives/, tiles/). New map
  tree: content/sites/g1/maps/
  with upper_level.ora,
  upper_level_preview.png,
  upper_level_labels.json.
  Registry canvas updated (map
  field now points at the
  content/sites/g1/maps path).
  Also MOVE the already-pushed
  maps/upper_level.* files into
  content/sites/g1/maps/ via git
  mv.
  PUSH 13c3bfa8 VERIFIED
  (2026-11-08): map moved to
  content/sites/g1/maps/
  (upper_level.ora, preview,
  labels.json). The pushed ORA is
  the v2-PLACED map: base->floor,
  no grid. BYTE-VERIFIED against
  repo tiles: 60 stone (room 1)
  + 1820 yard + 1180 holes =
  3060/3060 squares exact-tile;
  merged clean; zero red;
  labels.json valid, numeral
  square [26,47] inside room 1
  (position still a DRAFT pending
  his confirmation from the
  raster). Content-tree rule
  holding.
  LABELS PARKED (his, 2026-11-08):
  map text is UNNECESSARY right
  now - do not push the labels
  registry or the numeral-square
  confirmation. The registry file
  exists in the repo tree but is
  not an active thread. Active
  thread when he calls it: wall
  tiles (tower boundary block
  first), details to be ruled as
  met.
  WALL THICKNESS RULED (his,
  2026-11-08): interior straddle
  strokes = 8px (4px each side of
  the lattice line, center
  distributed). Thin-class spec
  CLOSED. Full wall spec now:
  interior walls 8px center-
  distributed straddle strokes;
  boundary/tower walls full-square
  in-square blocks (64px). Raster
  hand-ink variance (measured
  2026-11-08 in extract/g1/
  room1.png: interior 26-44px at
  ~150px/sq, perimeter 64-132px,
  up to 2.5x variance within a
  single run, incl. the stairwell
  tower ring) is NOT a spec - new
  tiles generate at the class
  constants. Next: generate wall
  tiles, tower boundary block
  first.
  WALL PRIMITIVE DRAFTED
  (2026-11-08): content/sites/g1/
  primitives/wall_timber.json +
  wall-face subject block (timber
  variant - G1 steading is hewn
  timber, material call flagged
  for his confirmation). Wall
  primitive is the NEUTRAL
  FULL-SQUARE face; composer
  clips to extents (8px interior
  strokes center-distributed,
  64px boundary blocks) per the
  primitive/composite doctrine -
  thickness is composition,
  never baked art. Manifest
  carries compose block with the
  ruled constants; seam gates
  pending until the master
  generates. Canvas:
  wall-timber-manifest.
  GEOMETRY CORRECTION (his,
  2026-11-08): boundary walls are
  NOT center distributed (re-confirmed
  boundary amendment) - my "64px
  full-square corner block at
  (1,1)/[19,44]" model was WRONG.
  CORRECTED: square (1,1) carries
  NO wall block - it has ONLY an
  INTERIOR VERTICAL wall on its
  EAST EDGE, and that wall IS
  center distributed (8px straddle
  on the line). So the first wall
  stamp at the start square is a
  straddle stroke, not a boundary
  block. Boundary walls sit in
  their own squares elsewhere
  (outside the room-region frame
  or at the building edge) - do
  not model ring squares as wall
  blocks. OPEN DETAIL: floor
  material for (1,1) and the other
  ring squares (inside building,
  outside the stone-tiled interior
  bbox) - currently black, needs
  ruling when walls build.
  RING-SQUARE FLOOR RULE (his,
  2026-11-08): squares outside the
  stone-tiled interior bbox (the
  ring squares, e.g. (1,1)) get
  their STONE FLOOR IF AND ONLY IF
  a center-distributed wall or
  door ends up partly drawn into
  the square. Wall/door ink
  entering a square => that square
  receives stone floor (walls and
  doors sit on floor, never float
  on black). Ring squares never
  touched by centered wall/door
  ink stay black. Floor placement
  for these squares is thus
  coverage-driven, decided by the
  wall/door placement pass, not a
  separate region ruling.
  START SQUARE CORRECTED (his,
  2026-11-08): the wall build
  starts at image square (1,2)
  (canvas [19,45]), NOT (1,1).
  (1,1) with its single east-edge
  straddle stroke and its
  coverage-driven floor is
  handled by the placement pass
  in course - the build itself
  opens at (1,2).
  RETURN VISIT PLANNED (his,
  2026-11-08): when the build
  reaches (2,2) - the NW interior
  square - we go BACK to (1,1):
  its east-edge stroke and (2,2)'s
  wall geometry meet at the
  junction around (1,1)'s corner,
  so (1,1) gets finished in the
  same pass as (2,2), not earlier.
  COPILOT IMAGE LOCATION (his
  reminder, 2026-11-08 - I keep
  forgetting): Copilot saves
  generated images to
  ~/storage/shared/Picutres
  (his spelling - possibly the
  Android-standard Pictures;
  ls to confirm exact name).
  Use that path when fetching
  generated masters on his
  Termux, not the cwd and not
  ~/storage/downloads.
  WALL_TIMBER MASTER GATED PASS
  (2026-11-08): Copilot's
  copilot_image_1794177432641.jpg
  is actually PNG bytes (1254x1254
  RGB, the fixed size) with a
  wrong .jpg extension - landed
  as wall_timber_master_raw.jpg
  (push da5f148b). Vision gate
  PASS (analyze_image: full
  coverage stacked round-log face,
  straight on, 5-6 log rows, no
  text/vignette, uniform light).
  PIXEL GATE PASS on real bytes
  (seamlock.py pulled + run on my
  side): wrap h=48.650 vs 2x p99
  57.648, v=48.942 vs 153.99,
  zero hard pixels. BAKED
  wall_timber.png 64x64 (single
  exact area-average) - baked
  tile gates PASS too (h=22.875,
  v=38.344, zero hard pixels).
  Note: h-wrap energy 48.650 is
  ~2.1x interior h mean (22.837)
  - inside doctrine limits but
  the highest wrap-to-mean ratio
  of the three primitives so
  far. ACTION: he renames raw ->
  wall_timber_master.png on his
  device, runs seamlock verify/
  bake locally to reproduce,
  commits master + tile +
  manifest gate flips.
  WALL_TIMBER PRIMITIVE CLOSED
  (push 4694ff05, 2026-11-08):
  master renamed true
  (wall_timber_master.png,
  100% identical bytes - the
  .jpg was PNG), baked
  tiles/wall_timber.png landed,
  manifest gates flipped (state
  baked, vision+pixel pass
  2026-11-08) via git-applied
  patch. VERIFIED FROM THE REPO
  after push: manifest valid
  JSON, landed tile re-gates
  PASS (h=22.875, v=38.344,
  zero hard pixels) - matches
  both my run and his Termux
  run exactly. The wall-face
  primitive is FULLY CLOSED:
  authored master, vision gate,
  pixel gate, baked tile, all
  proven on both sides. THREE
  primitives now live:
  stone_floor, yard, wall_timber.
  Composer inputs ready for the
  first stroke at (1,2)/[19,45]:
  8px center-distributed
  constants, coverage-driven
  floor rule, corrected start
  square, return to (1,1) with
  (2,2). NEXT: compose and place
  the first wall strokes.
  INTERIOR STROKE RE-RULED (his,
  2026-11-08): 8px -> 13px (12.8
  rounded; module-true 2-foot
  inner walls). AUTHORITY: G1
  Upper Works text - "All outer
  walls are of logs of at least
  3' diameter. Inner walls
  dividing rooms and the like
  are about 2' thick... doors are
  great iron-bound log affairs of
  1' thickness... All inside
  floors are of stone" (web-
  confirmed from module
  transcriptions; also validates
  the stone floor ruling). Raster
  thin class (26-44px at
  ~150px/sq = 1.7-2.9 ft) MATCHES
  the 2' text - the hand-ink was
  drawing 2-foot walls. BOUNDARY
  WALL WRINKLE RESOLVED (his
  observation): the raster does
  NOT draw boundary walls 3'
  thick (measured 64-132px =
  4.3-8.8 ft, up to nearly a
  full square) because 3' is the
  LOG DIAMETER (material truth),
  not the footprint - the
  footprint is the full square
  (matches the boundary amendment
  + the map's own drawing). In
  art terms the boundary block =
  stacked log courses at 3'/log =
  ~19px diameter, ~3.3 rows per
  64px square. The wall_timber
  master's logs measure ~2' (5-6
  rows/tile) - admissible as-is
  per his keep ruling; a true-3'
  variant would show ~3.3 rows if
  ever wanted. ACTION PENDING:
  wall_timber.json compose block
  still says interior_stroke_px:
  8 - needs the 13px update
  (patch offered in chat).
  STROKE 13 LANDED (push
  31a80095, 2026-11-08): manifest
  compose block now reads
  interior_stroke_px: 13
  (verified from origin after
  push; sed one-liner used
  after my corrupt patch -
  lesson: for one-token manifest
  changes give him sed -i, not
  git patches; hunk line-count
  must match listed lines).
  FINAL WALL CONSTANTS, all
  evidence-backed: interior
  straddle = 13px
  center-distributed (G1 text
  2' + raster agree); boundary
  = full-square block, 3' log
  courses (~19px/log); floors
  stone (text-confirmed); doors
  iron-bound log 1' thick,
  singles ~7' wide (G1 Upper
  Works - the number for the
  door primitive when built).
  Wall-face primitive fully
  closed with final constants.
  NEXT: composer wall-placement
  pass - first stroke at
  (1,2)/[19,45].
  VERTICAL-ALIGNED TILE RULED
  (his, 2026-11-08): the log tile
  is horizontally aligned; a
  vertically aligned variant is
  needed. Derived WITHOUT new
  generation: exact 90-degree
  rotation of the gated baked
  tile (pure pixel op, no
  resampling). Gate proves by
  symmetry - original passed
  both axes, so rotated tile
  passes with numbers swapped:
  h=38.344 v=22.875, zero hard
  pixels (verified my side,
  10464 bytes, 64x64 RGB).
  DELIVERED as base64 in a
  canvas (wall-timber-v-tile)
  for him to decode with
  base64 -d, re-verify with
  seamlock locally (expect the
  swapped numbers), and commit
  as tiles/wall_timber_v.png.
  Manifest compose block gains
  alignments (sed offered:
  "coverage": "full", ->
  coverage + "alignments":
  ["h","v"],).
  WALL_TIMBER_V LANDED (push
  7f9b0366, 2026-11-08): vertical
  -aligned tile committed as
  tiles/wall_timber_v.png, derived
  locally by NEW REPO TOOL
  tools/rot90.py (exact 90 CCW
  rotation, pure stdlib; fixed
  my IHDR unpack typo >IIB ->
  >IIBB via sed one-liner).
  His local gate matched my side
  to the digit (h=38.344,
  v=22.875, zero hard pixels).
  Manifest compose facts now
  include "alignments":
  ["h","v"]. BASE64 CANVAS
  (wall-timber-v-tile) is now
  OBSOLETE - the tool route is
  the version of record;
  derivation provenance lives
  in the repo as rot90.py.
  LESSON: one-token manifest
  edits -> sed; small scripts
  via heredoc work but check
  my own unpack formats before
  shipping. Wall-face primitive
  now serves BOTH orientations.
  NEXT: composer wall-placement
  pass, first stroke (1,2)/
  [19,45], alignment picked by
  wall direction.
  STAIRWELL WALL THICKNESS PROBE
  (2026-11-08, his question):
  measured the tower 1B district
  on pg-06.png (2496x3228 page
  scan, TRUE grid 64px/sq =
  6.4px/ft per map-006.grid.json -
  the 150px figure was the mcrop
  upscale, correct that recall).
  RESULT: the hand-ink CANNOT
  adjudicate wall gauge in this
  district - probes of the tower
  north wall (row 41) read
  14-25px (2.2-3.9ft), the Y40
  boundary wall reads 9-27px
  (1.4-4.2ft), tower vertical
  wall mostly reads as stair
  strokes; label glyphs (TOWER,
  B) masquerade as 20-22px blobs.
  Two weak classes do appear
  district-wide: ~13px (2.0ft =
  module inner walls) and
  ~17-19px (2.7-3.0ft = module
  3ft logs) - consistent with
  the G1 Upper Works text, but
  the tower's own outline is not
  cleanly separable from stair
  glyph + label ink at page-scan
  resolution. AUTHORITY
  AVAILABLE: module text - tower
  is a log outer work; outer
  walls 3ft logs => tower walls
  = 3ft class = 19px (19.2) at
  64px/tile. OPEN RULING for him:
  stairwell tower walls render
  (a) full-square blocks
  boundary-style (consistent with
  the earlier square-walls
  stairwell ruling - then no
  separate thickness constant,
  3ft lives in the log-course
  art scale), or (b) 19px
  in-square strokes, or (c) 13px
  straddle like room walls.
  My recommendation: (a)
  full-square, boundary-style.
  STAIR STRUCTURE = REVERSE J
  (his read, 2026-11-08): the
  tower stair is not an L - it
  is a REVERSE-LOOKING J
  stair structure. Two flights
  joined by the turn: the stem
  flight + the hook flight,
  sharing common geometric
  features (same 11px tread
  pitch, same gauge, same
  flight width ~40px band
  rhythm). Composition
  implication (his): treat the
  stairwell as ONE OBJECT -
  a J-path stair: one tread-run
  primitive following a two-
  segment path with a landing
  at the turn, wrapped in the
  tower wall ring. My measured
  constants (page scan grid =
  64px/sq, SAME as our tiles,
  transfers 1:1): tread pitch
  11px (~6/sq), stroke gauge
  3-4px, band pitch 40px
  (5/8 sq), stroke heights
  52-128px (0.8-2 sq). Flight
  zones measured: vertical
  treads throughout the
  district (stem+hook both
  read vertical-stroke treads)
  with 40px bands in two
  groups (rows ~42-44, ~46).
  STAIRWELL STAMP SPEC
  (drafting): one object =
  wall ring + floor + J-path
  tread run. Up direction to
  be pinned (watch tower up).
  STAIR_TREAD MASTER v1 REJECTED
  (his ruling, 2026-11-08):
  first Copilot generation passed
  all hard vision criteria
  (full coverage, planks full
  width, straight on, uniform
  light, no text/vignette) but
  drew ~10 plank rows = ~1ft
  planks vs the asked 1.5-2ft
  (5-6 rows). He ruled
  REGENERATE for 1.5-2ft planks
  despite my admissible-at-true-
  scale recommendation. LESSON:
  Copilot undershoots width
  specs - future subject blocks
  LEAD WITH COUNTS ("exactly 5-6
  rows fill the frame") not
  foot widths. v2 prompt issued
  with count-first plank spec +
  explicit narrow-board exclude.
  GENERATOR PREFERENCE (his,
  2026-11-08): he likes Gemini's
  master-generation results
  better than Copilot's. Gemini
  becomes the preferred
  generator for future primitive
  masters. IMPLICATIONS: Gemini
  emits real JPEGs (unlike
  Copilot's PNG-in-.jpg costume)
  so masters likely need a real
  JPEG->PNG conversion before
  the seamlock header gate -
  the pixel gates and bake loop
  stay unchanged and
  generator-agnostic. Save-to
  path on his device presumably
  same ~/storage/shared/
  Pictures. First Gemini master:
  stair_tread wide-plank v2
  (pending his upload + vision
  gate for 5-6 plank rows).
  JPG2PNG TOOL BUILT+PROVEN
  (2026-11-09): NEW REPO TOOL
  tools/jpg2png.py - pure-stdlib
  baseline JPEG->RGB PNG
  decoder (SOF0/SOF1, 4:2:0/
  4:2:2/4:4:4, restart markers,
  chroma replication upsample;
  refuses progressive/lossless).
  Fixed one stuffing bug during
  bring-up: FF00 in entropy
  stream = literal FF data byte
  (I first decoded it as 00 -
  desync). STAIR_TREAD MASTER
  (the narrow 1ft-plank v1,
  file 1794190355780.jpg, Gemini-
  or-Copilot true JPEG 1024x1024
  4:2:0, EXIF orientation 1)
  CONVERTED + GATED: structure
  validated (plank boundaries
  ~125px = ~9.3 planks, matches
  vision count; col-continuity
  low = horizontal planks),
  MASTER GATES PASS (wrap h=
  35.652 vs 2x p99 66.2, v=
  76.229 vs 237.6, zero hard
  pixels), BAKED tile PASS (h=
  11.312, v=46.281, zero hard).
  Master true size 1024x1024 =
  102.4 px/ft; planks ~1.2ft
  (narrow variant per his
  keep-both ruling). TOOL
  DELIVERED via code canvas
  (jpg2png-tool) for him to
  land + run locally + commit.
  PENDING: his local run, stair_
  tread.json manifest draft
  (given in chat), commit.
  STAIR_TREAD LANDED (push
  8ba8fc91, 2026-11-09): narrow
  1ft-plank variant fully
  closed - jpg2png tool in
  repo, master converted from
  true JPEG, gates PASS
  matching my run to the digit
  (his Termux + my side + origin
  all identical: master h=35.652
  v=76.229, tile h=11.312
  v=46.281, zero hard pixels),
  manifest stair_tread.json
  landed (plank_rows 10,
  plank_ft 1.2, generator
  note). FIVE primitives now
  live: stone_floor, yard,
  wall_timber (h+v), stair_
  tread. jpg2png = standing
  infrastructure for all
  future JPEG masters.
  PENDING: wide-plank stair_
  tread variant (Gemini,
  count-first prompt issued -
  5-6 rows); stairwell stamp
  spec (J-path, 11px tread
  pitch, 40px bands, needs his
  two pins: up direction, ring
  treatment); composer
  wall-placement pass first
  stroke (1,2)/[19,45].
  STAIR_TREAD_V LANDED (push
  46a264cc, 2026-11-09):
  vertical-plank variant,
  exact rot90 of baked tile,
  gate PASS by symmetry exactly
  as predicted (h=46.281,
  v=11.312, zero hard), verified
  from origin. Manifest carries
  alignments h+v. SIX tiles live:
  stone_floor, yard,
  wall_timber, wall_timber_v,
  stair_tread, stair_tread_v.
  Vertical planks = material for
  stair risers/returns where the
  stair runs across the grain
  per J-path segment direction.
  STAIRWELL J COORDINATES (his,
  2026-11-09, 31x40 naive
  building frame): first square
  (10,37); east 2 -> (11,37),
  (12,37); south 3 -> (12,38),
  (12,39), (12,40); west 3 ->
  (11,40), (10,40), (9,40).
  Path squares (9): (10,37)
  (11,37) (12,37) (12,38)
  (12,39) (12,40) (11,40)
  (10,40) (9,40). Bounding
  footprint: cols 9-12 x rows
  37-40 = 4x4. REVERSE J
  confirmed: stem on the east
  side (col 12) running south,
  hook at the south end (row
  40) turning west - shape
  matches the raster's
  L-district stair glyph (stem
  + west hook) and his earlier
  reverse-J ruling. Total stair
  run ~9 squares = ~90ft of
  climbing (watch tower). OPEN
  PINS remaining: up direction
  (which square is the bottom of
  the climb) + ring wall
  treatment + wall-vs-path
  reading of these coordinates.
  STAIRWELL FULLY PINNED (his
  2026-11-09 coords + realization):
  NO WALLS of its own - the
  stairs butt against EXISTING
  boundary/interior walls (the
  'thick wall lines' around the
  raster tower district were the
  keep's own walls all along;
  ring-treatment pin DISSOLVED;
  15-square region collapses to
  the 9-square run). J-PATH in
  the 31x40 BUILDING frame:
  start/bottom step (10,37)
  (his words: first coord = the
  start of the stairs), rises
  EAST 2 squares -> (11,37),
  (12,37) [landing 1], turns
  SOUTH 3 -> (12,38),(12,39),
  (12,40) [landing 2], turns
  WEST 3 -> (11,40),(10,40),
  tops out at (9,40) = watch
  tower level. Open arm faces
  west, "]" shaped reverse J.
  SEGMENTS: top arm row 37
  cols 10-12 (E-W), stem col 12
  rows 37-40 (N-S), bottom arm
  row 40 cols 9-12 (E-W).
  MATERIALS: E-W arms =
  stair_tread (h grain), stem =
  stair_tread_v; floor stone_
  floor coverage-driven; walls =
  existing placement-pass walls.
  CONSTANTS: tread pitch 11px,
  flight band 40px at the 2
  landings, 64px tiles. Spec
  manifest drafted for him to
  land (stairwell.json);
  composer wiring pending
  mkplace.py (still UNTRACKED
  in his tree - not pushed).
  STAIRWELL SPEC LANDED (push
  0e29b61c, 2026-11-09):
  stairwell.json committed and
  VERIFIED FROM ORIGIN - JSON
  valid despite scary scrambled
  terminal echo (the echo is a
  Termux display artifact; the
  heredoc captured correctly -
  LESSON: echo mangling does
  not imply file corruption;
  always verify from origin
  before assuming). All 9
  squares exact, segments E/S/
  W, start (10,37), top (9,40),
  landings, pitch 11, band 40.
  NEXT: (1) he pushes tools/
  mkplace.py (still untracked)
  -> I read its interface ->
  composer wiring for stairwell
  + wall-placement pass first
  stroke (1,2)/[19,45];
  (2) wide-plank tread variant
  optional.
- JPG2PNG DECODER BUG HUNT
  CLOSED (2026-11-10): three real
  decoder bugs found by CLOSED-
  LOOP VALIDATION (a minimal
  stdlib baseline JPEG ENCODER
  written for the test, known
  image -> encode -> decode ->
  pixel compare; the loop was
  the only thing that could
  catch them - all gates are
  scale/color-invariant):
  (1) idct2 missing the 0.5
  factor per separable pass
  (outputs 4x too large; found
  first, fixed first);
  (2) LUMA LEVEL SHIFT MISSING -
  to_rgb never added +128 back
  after IDCT (this was the main
  bug: tread decoded green,
  map-006 decoded Y~99 instead
  of paper-white ~227);
  (3) CHROMA LEVEL-SHIFTED TWICE
  - the IDCT plane already
  holds sample-128, but to_rgb
  subtracted 128 AGAIN (only
  visible on multi-component
  files; the grayscale closed
  loop passed while chroma was
  still broken - LESSON: a
  single-color-space test is
  not a decoder validation;
  validate gray closed loop AND
  a real color file against
  known-content expectations).
  FINAL VALIDATION: closed loop
  64x64 and 96x80 mean err 0.009
  max 1 (pure rounding); tread_
  raw.jpg (4:2:0) -> mean RGB
  (137.2, 130.7, 123.4) gray-
  brown wood; map006.jpg
  (4:4:4) -> (221.1, 227.4,
  240.0) paper-white. Encoder-
  side test bugs (NOT decoder):
  DQT length field off-by-one,
  fdct COS index transposition,
  negative amplitude encoded as
  two's-complement mask instead
  of v+2^t-1 - debugging a
  closed loop means suspecting
  BOTH sides. Also: component
  planes now array('f') (4x
  less memory; 2550x3300 4:4:4
  decode OOMs a float-LIST
  build). FIXED TOOL delivered
  in the jpg2png-tool canvas
  (v2, fixes listed in its
  docstring). RE-LAND SEQUENCE
  for him: save v2 over tools/
  jpg2png.py, re-convert
  stair_tread_master_raw.jpg ->
  master.png, seamlock verify +
  bake, rot90 -> _v, re-verify
  (gate numbers WILL differ
  from the seated green-tile
  numbers), manifests re-gate.
  The landed stair_tread tiles
  (46a264cc era) are INVALID
  ART pending that re-bake.
  MKSTAMP DELIVERED: mkstamp.py
  (construct stamp composer) in
  the new mkstamp-tool canvas -
  PROVEN end-to-end with the
  fixed tiles: stairwell_upper
  stamp 256x256 RGBA, 9 path
  squares, alpha pattern exact,
  tread squares sample brown-
  gray (141,139,135) not green,
  off-path alpha 0. His run:
  mkstamp.py stairwell.json
  content/sites/g1/tiles
  stamps/stairwell_upper.png
  --preview to eyeball. Still
  pending his side: pushing
  tools/mkplace.py, mkmap.py,
  mroom.py (all untracked) ->
  wall-placement pass spec ->
  composer wiring.
- RE-LAND LANDED AND
  ORIGIN-VERIFIED (push
  c0d1e1c6, 2026-11-10, 0e29b61c
  ..c0d1e1c6): tools/jpg2png.py
  v2 (md5 a69b3b7b768a1ff9657f49
  8cbd78176, byte-exact vs the
  canvas) + tools/mkstamp.py (md5
  5eea42c029d63c7011d5d8feb0613
  d13, byte-exact), re-converted
  stair_tread_master.png, re-
  baked stair_tread.png + rot90
  _v, and the first CONSTRUCT
  STAMP stamps/stairwell_upper
  .png. SEAMLOCK GATE NUMBERS
  (master, now seated truth):
  interior h mean 20.770 p99
  28.528 | v mean 47.487 p99
  182.695; wrap h=29.490 v=
  224.456; hard 0/0 PASS. Tile
  gate: h mean 12.390 p99 18.750
  | v mean 28.369 p99 69.188;
  wrap h=8.984 v=50.578; hard
  0/0 PASS (supersedes the green-
  tile-era numbers). Master true
  size 1024x1024 (the decoder
  reports it; the manifest's
  master_size should say 1024,
  px_per_foot 102.4 - VERIFY at
  the manifest pass). ORIGIN
  PIXEL PROOF: stair_tread.png
  from origin = mean RGB (137.2,
  130.7, 123.4) - EXACTLY the
  sandbox validation value,
  gray-brown wood, NOT green;
  stamp RGBA 256x256 with
  opaque px exactly 36864 (9
  squares), transparent 28672,
  opaque mean (134.8, 128.2,
  120.6). The INVALID-ART era is
  CLOSED: every stairwell
  material is now correctly
  decoded, gated, baked. His
  eyeball preview landed at
  ~/storage/shared/Pictures/
  stairwell_upper_preview.png
  (768x768). STILL PENDING HIS
  SIDE: pushing tools/mkplace.py,
  mkmap.py, mroom.py (all
  untracked) -> wall-placement
  pass spec (first stroke (1,2)/
  [19,45], 13px straddle,
  boundary blocks, coverage-
  driven floor) -> composer
  wiring; optional wide-plank
  tread variant (Gemini,
  count-first prompt already
  given).
- MKSTAMP v2 - STAIR
  READABILITY (2026-11-10,
  his eyeball verdict on v1:
  "placement correct, doesn't
  look like a stairwell at
  all"). ROOT CAUSE: v1 treads
  were FULL-PITCH 11px plank
  bands laid edge to edge - no
  risers, no depth cue, the
  whole run reads as striped
  plank hallway. V2 COMPOSITION
  (no new art, all deterministic
  shading over the gated tiles):
  (1) TREAD/RISER SPLIT - each
  11px pitch = 8px lit tread +
  3px riser shadow (tile pixels
  x riser_shade 0.42), riser at
  the ASCENDING edge; (2) DEPTH
  GRADIENT - global brightness
  ramp along the run, top lighter
  than bottom (depth_shade 0.26);
  (3) LANDING LIPS - 3px edge
  shadow (x0.72) framing both
  edges of each 40px landing
  band. All three are SPEC/
  COMPOSE PARAMETERS (tread_
  tread_px, riser_shade, depth_
  shade, lip_px, lip_shade -
  defaults in the tool; the
  landed stairwell.json works
  unchanged). SANITY PROVEN:
  E-arm scan alternates tread
  lum ~90-105 vs riser ~32-43
  (2.3x), gradient bottom-tread
  74 percent vs top-tread full.
  v2 in the mkstamp-tool canvas
  (md5 b4f5a0b60c6e7d6000a65a
  3b90b40352, 10403 bytes),
  pending his eyeball of the
  new preview; if it reads as
  stairs, re-land the stamp.
- GEOMETRY GUIDE MODE -
  THE IMAGE-TO-IMAGE RULING (his
  Gemini result, 2026-11-10:
  texture perfect, geometry
  wrong): a generative voice
  PAINTS texture well but
  CANNOT follow lattice
  geometry in prose - so stop
  asking it to and HAND IT THE
  GEOMETRY (the seamlock
  doctrine generalized: don't
  ask a voice to be perfect,
  construct the invariant).
  mkstamp v2.1 (mkstamp-tool
  canvas, md5 46784c2016e311381098d9d1a6a2c93a
  bytes): --guide PATH renders
  the SAME geometry at 10x
  (2560x2560, 1 sq = 640px,
  1ft = 64px) as a FLAT
  GRAYSCALE GUIDE, one neutral
  gray per surface class (bg
  0, floor 90, tread 215,
  riser 55, landing band 190,
  lip 130). Internal refactor:
  ONE geometry pass builds a
  class+grain+travel map, both
  stamp and guide render from
  it (single source, no drift);
  stamp output PROVEN
  geometry-identical to v2
  (only the two landing bands'
  texture PHASE differs, 2560px
  each - tile is wrap-verified
  either way). Caught a name
  collision (RISER the class
  const vs RISER the 0.42
  shade float) - classes now
  C_-prefixed. WORKFLOW: he
  runs mkstamp --guide ->
  uploads the guide PNG to
  Gemini with a RETEXTURE edit
  prompt (keep every edge
  pixel-identical, paint worn
  gray-brown planks on the
  light surfaces) -> the
  result comes back as a
  GENERATED MASTER to be
  re-masked against the class
  map (deterministic alpha:
  bg class = transparent) and
  eyeball-gated. If the
  retexture reads as stairs,
  it may supersede the
  composed stamp as the
  stairwell art.
- MKSTAMP v2.1 LANDED AND
  ORIGIN-VERIFIED (push
  bbc74e39, 2026-11-10, c0d1e1c6
  ..bbc74e39, 2 files):
  tools/mkstamp.py v2.1 (md5
  46784c2016e311381098d9d1a6a
  2c93a, byte-exact at origin)
  + the re-composed
  stairwell_upper.png stamp
  (tread/riser + gradient +
  lips). ORIGIN PIXEL PROOF:
  opaque exactly 36864 (9
  squares), transparent
  28672, E-arm tread lum 89.7
  vs riser 38.2, gradient
  bottom 75 -> top 111.
  DELIVERY LESSON (three
  failed handoffs, then clean):
  he kept running the command
  block without saving the
  updated canvas body - the
  md5 gate caught it EVERY
  time (5eea42c0... = v1).
  Fixes that worked: the
  grep -c "GEOMETRY GUIDE
  MODE" quick version probe,
  and publishing a FRESH
  CANVAS under a NEW NAME
  (mkstamp-v21, titled
  CURRENT) - a new canvas
  name bypasses any stale-
  panel render; when a tool
  update fails the md5 gate
  twice, re-publish under a
  new name instead of telling
  him to re-copy. The v2.1
  body is now in BOTH
  mkstamp-tool and mkstamp-v21
  canvases. GUIDE RENDERED
  HIS SIDE (65972 bytes,
  2560x2560) into
  ~/storage/shared/Pictures/
  stairwell_guide.png for
  the Gemini image-to-image
  retexture; next: his Gemini
  output -> my geometry-drift
  check vs the class map ->
  either re-masked generated
  master or the composed
  stamp stands.
- LANDING RULING +
  TEXTURE-SOURCE RULING
  (2026-11-11, his two
  answers): (1) SHAPE IS MY
  CALL -> mkstamp v2.2 keeps
  FULL-SQUARE LANDING
  PLATFORMS with a dark trim
  ring (lip_px 3 = 1/20 of the
  square, matching his Gemini
  reference), compose keys
  trim_shade (0.55) and
  landing_mode (full_square |
  band legacy); landings use
  HORIZONTAL grain regardless
  of segment. (2) THE UPLOADED
  JPG (1794361295766) IS THE
  TEXTURE SOURCE FOR THE WHOLE
  STAMP - an OLD image whose
  TEXTURES he rules correct
  (141-byte stub upload, bytes
  unreachable my side; the
  vision analysis read it:
  full-square landings w/ dark
  trim, same wood as treads,
  horizontal landing grain,
  J intact, tread/riser
  visible). NEW TOOL
  mktexstamp.py (mktexstamp-
  tool canvas, md5 b9f6f6ce44
  9125f197d0f729700bff65,
  10137 bytes): the image-to-
  image back half - validates
  the painted master's
  luminance per class vs guide
  gray (tol 45, min 85 percent
  per class, FAILS LOUDLY on
  drift - proven: 40px shift ->
  riser 26 percent FAIL), then
  bakes 2560 -> 256 as the
  SINGLE exact x10 area-average
  with CLASS-MASKED ALPHA
  (geometry is the mask, never
  the image; drift inside a
  class region is harmless
  texture). Proven end-to-end
  on a synthetic painted
  master: 100 percent match all
  classes, bake + preview OK.
  mkstamp v2.2 (fresh canvas
  mkstamp-v22, md5 5671f7f8e4
  81bda063c6652efc94a74d,
  11884 bytes) re-landed for
  the v2.2 stamp + guide. HIS
  SEQUENCE: save both canvas
  bodies -> jpg2png his Gemini
  JPG -> mktexstamp -> eyeball
  -> land. NOTE: the guide
  renders BEFORE the stamp in
  mkstamp (--guide returns
  early): render guide and
  stamp as two runs.

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

## The rules reorg arc (pass 1 LANDED 2026-11-11)

- **THE TAXONOMY (Curtiss decisions, 2026-11-11):** rules/ gets
  book-family subdirs + descriptive renames of all cryptic pins +
  the live engine code split into rules/engine/. DIRS: engine/
  (character, classes, combat, dice, races, saves, turn .cpp/.h +
  rules_test.cpp + afw->audit_wiring.h), dragon/ (the whole Dragon
  magazine arc ~75 pins: issueNNN_opener/close + promo_batch01-12),
  ddg/ (the D&DG walk: dga-dgg->mythos_* mythoses + cqc1-8 chart
  batches + afg, idx->appendix4_index, tpl->appendix2_temple
  _trappings, dpe-dpz->lua_promo_batch1-7, ll1->legends_lore_parity),
  ff/ (FF arc: ffp-ffm->promo_batch1-8, ffh->hornet_promotion,
  ffik->index_walk, ffn/ffo/ffq tables, fq1-3->normalization
  _batch1-3, lungp->lung_dragons_promotion), mm/ (mn1-6->mm1
  _normalization_batch1-6, mq1-4->mm2_normalization_batch1-4,
  mma->mm2_arc_opener, lmp->mm2_lammasu_promotion, mm2* keep-name),
  mop/ (motp* + the 4 appendix* files), meta/ (ALL process/tooling
  pins: the pmb/nmb/tmb/qmb/kmb/vmb/xmb/jmb/zmb/fmb/ymb migration
  batches, rsc/rpf/lreg/prg/prf registry wiring, rns/rtk/hmb/migw
  tooling, cnt/csh charter, filepatchseam, rtseam, pm1-3->promotions
  _mop_batch1-3), plus keep-name family moves oa/, ua/, wsg/, dsg/,
  dmo/. klm renamed IN PLACE to dmg_appendices_klm.h (homed at
  pass 2). RULES IS NOT JUST .h: 8 engine TUs were mixed in.
- **RECORDS REWRITE TOGETHER (Curtiss decision):** the live seed
  gets the old->new path/bare-token rewrite in the SAME round; the
  three doc/vibe backups are ARCHIVAL and NEVER rewritten.
- **STAGED PASS 2:** the ambiguous descriptive core (~150 files:
  miscprose/miscmagic series, planes singles, deities/deitylines,
  owedpins, the DMG/PHB-sourced pins) stays at rules/ top level
  until every banner is read; unsettled ones go to a Curtiss
  adjudication list, never guessed.
- **THE TOOL (R515 tool-round rules):** tools/rules_reorg_pass1.py
  - pure stdlib, git mv (history-preserving), full-map reference
  rewrite across tracked text files (binary-ext blacklist, tool
  self + 3 archives excluded), post-rewrite stale-reference
  verify (any leftover = RED exit 1), idempotent double-run
  (applied 0/already N/rewrote 0). Synthetic-proven on a 217-file
  fake repo with a stub git: clean first run, clean idempotent
  second run, zero stale refs; a double-wrap bare-replacement bug
  was caught and fixed by the proof. DELIVERY: gzip+base64 in ONE
  66-line canvas block (5,034 b64 bytes) - the raw 13.2KB source
  would base64 to ~18KB, OVER the ~15K canvas-copy clip (the R608
  lesson); decode chain base64 -d | gzip -d is byte-exact-or-loud.
  DECODED MD5 0231c4e74c8caaad82bd9a867ffeb2b4. Decode: nano
  reorg.b64 (paste block) -> base64 -d reorg.b64 | gzip -d >
  tools/rules_reorg_pass1.py -> md5sum gate -> run -> preflight ->
  commit+push. UNWIND for a RED: git reset --hard HEAD (no spec
  file involved; the tool never edits before git mv succeeds).
- Does NOT touch: rules/audits/ (rNNN naming is fine), dm/,
  monsters/, content/, tools/ other than the new file.
- **V2 + THE R400 REPAIR (2026-11-11, first preflight RED):** the
  first Termux preflight died at ai/actor.cpp -> rules/attacksround
  .h -> bare '#include "classes.h"' - a pass-2 leftover header
  bare-including an ENGINE header that moved to rules/engine/ (the
  include-rewiring class the R400 lesson names; engine TUs in the
  same dir kept their bare includes valid, headers OUTSIDE engine
  did not). V2 adds the INCLUDE-REPAIR PASS after the reference
  rewrite: every quoted #include in tracked .c/.h/.cpp that does not
  resolve FILE-RELATIVELY (the true quoted-include semantics -
  includer dir first, which is how ai/ TUs' ../rules style works)
  is rewritten to relpath(unique-basename target, includer dir);
  ambiguous basenames DIE LOUD; root-resident files (regtest.cpp)
  untouched; idempotent (include_fix 0 on rerun). Synthetic-proven
  on the already-applied tree (applied 0/already 185/include_fix
  fired; the proof caught a doubled-backslash regex bug that made
  the pass silently no-op). V2 md5 2d88842e44da6d2e1fbe43aca4d556c6,
  76-line b64 canvas block. NOTE: preflight was ^C'd mid [2/5]
  after the [1/5] syntax fail - the tree was left fully applied,
  v2 reruns idempotently over it (no unwind needed, R817's
  fixed-spec-follows rule satisfied by design).
- **PASS 1 LANDED (2026-11-11):** two commits - 77e29871
  (tool decoded + Curtiss's parallel map-tool work swept in by an
  early git add -A; message mislabels, left unamended) and e3159662
  ("rules reorg pass 1 v2: include repair"). The tool's first real
  run: applied 669 (185 renames + 484 family/explicit moves),
  rewrote 1763 files (every moved header's own banner + regtest +
  seed + audits + content/rules/*.lua records); v2 include repair
  normalized every non-file-relative quoted include repo-wide.
  Remote-verified: rules tree 98ca76 -> 1276a3, 13 dirs, cryptic
  names gone, 156 pass-2 leftovers at top level, reorg.b64 removed.
  Preflight GREEN was Curtiss's gate before the push. PASS 2
  (pending): read the banners of the ~150 remaining descriptive
  files (miscprose/miscmagic series, planes singles, deities/
  deitylines, owedpins, the DMG/PHB-sourced core; klm already
  renamed dmg_appendices_klm.h awaiting homing), home them by
  source book, adjudication list for the unsettled. SEPARATE LINE:
  while the code arc ran, the G1 map line advanced in parallel
  (stair-tread/stairwell tile commits through 3bb2d0b - mkstamp,
  mkstairtiles, jpg2png, two-tile stair system - not yet seated
  here in detail).
- **PASS 2 LANDED (2026-11-11, commit 55ed6011):** all 156 leftover
  banners read; 128 CONFIDENT moves in tools/rules_reorg_pass2.py
  (same proven v2 engine + include repair; synthetic-proven,
  applied 128/already 0, idempotent; md5 7cad06d72038189ab7f9fc43
  927f3e69, 53-line b64 canvas): mop/ 17 (the "printed pp." plane
  chapters: abyss..tarterus + indices + outerplanes/seal), phb/ 6
  (armorratings, bard, startmoney, thieffunc, weaponprof, wisdom -
  banner-PHB-cited), dmg/ 87 (every DMG-paged pin incl. the
  miscmagic1-5 + miscprose1-23 series, armorshield, mweapons,
  swimcross, and dmg_appendices_klm from pass 1's in-place rename),
  ua/ +15 keep-name additions (acrobat, barbarian, cantriptier,
  cavalier, cavmoney, classtables, comeliness, hierophant, paladin,
  spelltableledger, subracecap, subracelevels, subraces,
  thiefarmor, weaponspec), 3 RENAMES: pln -> ddg/appendix1_known
  _planes (D&DG walk r19), drg -> dragon/issue001_small_variants,
  art -> dragon/artificer_devices. 28 HELD for Curtiss's
  adjudication (NOT in the map, stay at rules/ top): aerial,
  attacksround, deities, deitylines, druidspells, equipcosts,
  hirelings, illusionspells, lancecharge, lancespeed,
  mountcombat, mountlayer, mountmove, multiclass, owedpins,
  palrangerspells, psionics, saddle, sage, siegefire, subclasses,
  subclassgates, subclassspecials, underwater, weapontables,
  worshipsites, wt1, xpadjust. SUGGESTIONS tabled: phb/ for the
  R176-R192 class-arc pins (attacksround, druidspells,
  illusionspells, palrangerspells, multiclass, subclasses,
  subclassgates, subclassspecials, xpadjust, weapontables,
  equipcosts); a seams/ dir for the engine-seam cluster (psionics,
  mount*, deities/deitylines/worshipsites/owedpins [Appendix S],
  aerial, underwater, lancecharge, lancespeed, saddle); dmg/ for
  hirelings, sage, siegefire; meta/ for wt1 (WSG+MOP registry
  normalization). Held files' broken includes still get repaired
  in place by the include pass (proven on psionics.h).
- **PASS 2 REMOTE-VERIFIED:** rules tree 1276a3 -> 2f28b7;
  15 dirs (phb/dmg/mop added); 28 top-level .h remain = exactly the
  held adjudication set; dmg_appendices_klm now inside dmg/.
  REMAINING for the reorg arc: pass 3 = the held-28 rulings
  (suggestions tabled: phb/ class-arc 11, seams/ cluster 13,
  dmg/ 3, meta/ wt1) - awaits Curtiss's calls, then one small
  tool, preflight, commit. The code-cleanup arc is otherwise
  COMPLETE: rules/ reads as book families, engine code split,
  zero cryptic names.
- **PASS 3 LANDED (2026-11-11, commit 5127857f, remote-verified):** tools/rules_reorg_pass3.py - the held-28 rulings,
  all keep-name: phb/ +11 (attacksround, druidspells,
  illusionspells, palrangerspells, multiclass, subclasses,
  subclassgates, subclassspecials, xpadjust, weapontables,
  equipcosts), NEW rules/seams/ +13 (psionics, mountcombat,
  mountlayer, mountmove, deities, deitylines, worshipsites,
  owedpins, aerial, underwater, lancecharge, lancespeed, saddle -
  the engine-seam cluster incl. the Appendix S deity set), dmg/ +3
  (hirelings, sage, siegefire), meta/ +1 (wt1). Synthetic-proven:
  applied 28/already 0, include repair fires, idempotent. md5
  844266bfec7a54bc7879a611b01f8108, 41-line b64 canvas. After
  landing, rules/ top level holds ONLY the engine TUs' new home
  siblings... nothing - top level becomes empty of .h pins; the
  reorg arc CLOSES (16 dirs, every pin homed).
- **THE RULES REORG ARC IS CLOSED (2026-11-11, 5127857f):** rules
  tree 2f28b7 -> eb308b; rules/ TOP LEVEL EMPTY of pins; 16 dirs:
  audits, ddg, dmg, dmo, dragon, dsg, engine, ff, meta, mm, mop,
  oa, phb, seams, ua, wsg. Every one of ~600 pin headers homed by
  source book or by ruling; engine code split to rules/engine/;
  zero cryptic names; seams/ = the engine-seam cluster (psionics,
  mount trio, the Appendix S deity set, environments, the
  lance/saddle feeders). FULL COMMIT MAP: 77e29871 (tool decode +
  map work) -> e3159662 (pass 1 v2, 669 moves + include repair) ->
  55ed6011 (pass 2, 128 moves) -> 5127857f (pass 3, the held 28).
  The tools (rules_reorg_pass1.py v2 / pass2 / pass3) stay in the
  repo as the reorg's provenance record - do not rerun them
  idempotently-harmless but they are history now. THE DEITY SEAM
  NOTE: rules/seams/ now visibly holds the Appendix S deity-layer
  pins (deities, deitylines, worshipsites, owedpins) - when the
  deity seam work resumes, its pin home is rules/seams/.
- **PASS 4 LANDED, THE ROOT SWEEP (2026-11-12, commits f89c466a +
  eabca52c, remote-verified):** tools/root_sweep.py (v2, md5
  091da61aa8a049ebf838bcf869792bb6, 49-line b64 canvas
  root-sweep-v2) - the repo ROOT cleanup. 17 moves total across
  both commits: 4 G1 hall-scan artifacts -> extract/g1/
  (map-006.ask/match.json, exemplars.json; tools/mapp.py usage line
  rewritten to extract/g1/exemplars.json - the only content
  rewrite), 9 R878 figure crops (D&DG p.131 FIG.4/5) ->
  extract/ddg/. 13 deletes: reorg.b64 transport file, stale root
  hallscan.py (pre-fit template; the fitted tool seats at
  tools/hallscan.py), stale root map-006.jpg (byte-identical
  duplicate of the already-seated extract/g1/map-006.jpg - the
  Nov 7 seat commit had seated it), 10 zero-byte pNNN stubs.
  ROOT NOW: 14 dirs + regtest.cpp, adnd1.cpp, treasuresim.cpp, rn,
  bn, nn, .gitignore - bn/nn STAY per the standing R369/R372
  ruling (struck rebuild paths, not presence); ./bn and ./nn
  mentions in the seed records are history, NEVER rewritten. The
  "raster": "map-006.jpg" ref in extract/g1/
  map-006.grid.structure.json is a sibling reference, stays as-is.
  ENGINE LESSON (root-sweep pairs): unlike passes 1-3, the NEW
  path CONTAINS the OLD (map-006.jpg within extract/g1/
  map-006.jpg) - the rewrite pass needed sentinel-protection
  (blank new path before replacing old) or a double-run
  double-prefixes, and the stale-verify needed the same blanking
  or it dies on every correctly-rewritten ref. Also: raw
  .githubusercontent.com is CDN-cached - verify landed file
  content via the commit blob sha, not raw fetch. RESIDUAL:
  root_sweep.b64 (the v1-era transport file) still tracked at
  root - fold its rm into the next commit.
- **AUDITS NAMING LANDED (2026-11-12, commit 6e1c8b25,
  remote-verified):** tools/audits_banner_names.py (md5
  db64f5ce6ffeb7d214869d8e95a2700d, 81-line b64 canvas
  audits-banner-names) - the rules/audits/ naming pass: all 201
  nondescriptive rNNN_batch.h headers renamed to their own banner
  titles, mechanically slugged (r826_dmg_tables_batch,
  r848_ff_magic_item_tables, r863_nehwon_mythos,
  r900_dragon_creature_features, r1026_deity_seam_close...).
  r825_dmg_batch.h skipped (already titled). No content changes;
  regtest.cpp include lines + all tools/spec_r*.json
  audit_file/anchor refs rewrote with them (all 596 spec JSONs
  re-validated post-rewrite). ARCHIVE extended: knowledge_seed_v3
  AND knowledge_seed_v2 are history prose, never rewritten (they
  mention batch paths; stale-verify skips ARCHIVE). Proofed as a
  FULL DRESS REHEARSAL: the real 202 files + real regtest.cpp +
  real spec JSONs + real seed docs in a synthetic with the fake
  git stub - GREEN, then applied 0/already 201/rewrote 0. Ten
  _batch.h names remain by design: r825_dmg_batch.h + 9 whose
  banner titles genuinely end in "batch" (r826_dmg_tables_batch
  etc). RESIDUALS: (1) root_sweep.b64 still tracked at repo root -
  fold its rm into the next commit; (2) doc/content_structure.md
  line ~76 states the naming convention as
  "rules/audits/r{NNN}_batch.h" - now stale prose, user to
  adjudicate. Cleanup arc now: rules/ top level done, root done,
  audits done. Next candidates: tools/ organization (the
  mkmap/mkroom/mnum/mkstamp pile), or back to the paused G1 map
  line (stairwell tiles).
- **TOOLS REORG LANDED (2026-11-12, commit 88e5bd98,
  remote-verified):** tools/tools_reorg.py (md5
  b841781b2c6b3317693081f82e409932, 54-line b64 canvas
  tools-reorg) - the tools/ organization pass, 64 moves, zero
  deletes, zero content changes: the G1 map pipeline (23 files)
  seats at tools/map/ - scan/crop (hallscan, fit_lattice, jpg2png,
  rot90, jdec, mcrop), lattice/numerals (mgrid, mblob, mstruct,
  mnum, mcomp, mrender), rooms/places (mroom, mapp, mapbatch,
  match, mseat), stamps (mkmap, mkplace, mkstairtiles, mkstamp,
  mktexstamp) + library.json; moved TOGETHER so same-dir imports
  (mgrid/mstruct/mrender/mcomp/mblob, jdec) and mapp's --lib
  library.json default hold. The 36 gap reports + 5 surveys
  (audit_migration_survey, maintenance_survey_r104, mm1,
  monsters, playverify_r77_r83) seat at tools/reports/. The
  ritual family STAYS at tools/ top: 402 rNNN round tools, 596
  spec_r*.json, infra (speclib/splice_engine/rverify/
  preflight.sh/seamlock/audit_eval/normalize_registry/
  build_spec_general), reorg history (rules_reorg_pass1-3,
  root_sweep, audits_banner_names, survey_r823), mm2lua. The 206
  historical full-path refs in round tools/specs rewrote
  mechanically (1013 files touched in the live run). Proofed as
  a FULL dress rehearsal on the real 222MB tree: GREEN, then
  applied 0/already 64/rewrote 0; seeds untouched; all 596 specs
  re-validated JSON. The root_sweep.b64 residual finally cleared
  in this commit. CLEANUP ARC COMPLETE: rules/ top level, repo
  root, audits naming, tools organization - all done. Remaining
  known loose end: doc/content_structure.md ~line 76 still states
  the old r{NNN}_batch.h audits convention (stale prose). Next:
  the paused G1 map line (stairwell tiles, mkstairtiles/mkstamp
  now at tools/map/).
- **DMG NAMING LANDED (2026-11-12, commit 19daa1a1,
  remote-verified):** tools/dmg_banner_names.py (md5
  6a104be5e960eca366deaae7758a3328, 50-line b64 canvas
  dmg-banner-names) - the rules/dmg/ naming pass, 46 same-dir
  renames, zero content changes: the numbered series take their
  banner names (miscprose1-23 -> miscmagic_prose_part1-23,
  miscmagic1-5 -> miscmagic_table1-5_footnotes, potionsprose/2/3
  -> potions_prose_part1-3, ringsprose/2/3 ->
  rings_prose_part1-3, wandsprose/2 -> wands_prose_part1-2,
  rodsprose/stavesprose/scrollsprose -> rods/staves/scrolls_prose,
  specartprose/2 -> specart_prose_part1-2) plus the 5 terse
  cryptics (humrpref -> humanoid_preferences, magres ->
  magic_research, treasdet -> treasure_determination, scrollfab
  -> scroll_manufacture, spearset -> set_spear). regtest.cpp
  include lines + spec/round provenance refs rewrote (137 files);
  dress-rehearsaled on the full tree: GREEN twice, 596 specs
  re-validated, seeds untouched. Left as-is (borderline, user
  may adjudicate): wonder (wand of wonder), uwfight/uwspells
  (underwater), doorforce, swimcross, conduct. NOTE the dmg
  banner-title convention: line 3 of each pin header holds the
  R-round descriptive title - the mechanical slug source for any
  future naming pass (same as the audits pass). The
  banner-name sweep could still be run over the other rules dirs
  if any numbered/cryptic series remain (candidate check:
  rules/mm, rules/dmo, rules/spells...). Cleanup arc: rules/
  top, root, audits, tools, dmg all done.
> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

- **DMG PROSE PURGE LANDED (2026-11-12, commit 044599e4,
  remote-verified):** tools/dmg_prose_purge.py (md5
  477c3186677cc7f56008be30346aaa9c, 47-line b64 canvas
  dmg-prose-purge) - the user ruling that the just-renamed
  _prose suffix was itself a mess: all 36 files with "prose" in
  their names took the banner-faithful "_explanation" instead
  (banners read "X explanation prose"): miscmagic_prose_part1-23
  -> miscmagic_explanation_part1-23, potions/rings/wands/
  specart_prose_partN -> ..._explanation_partN, rods/staves/
  scrolls_prose -> rods/staves/scrolls_explanation. The word
  "prose" is GONE from rules/dmg filenames (0 left); the pin
  files (potions.h, rings.h, scrollpins.h) keep their distinct
  roles. regtest + spec refs rewrote (93-file diff, 36 renames);
  GREEN twice, specs re-validated. LESSON: the user rejects
  "_prose" as a name component - prefer the banner's operative
  noun (explanation, pins, tables). The remaining banner-name
  sweep of other rules dirs should apply this convention. dmg
  naming arc now closed twice over.
> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

- **DMG CONTENT NAMES LANDED (2026-11-12, commit 88d3be68,
  remote-verified via tarball - API was rate-limited):
  tools/dmg_content_names.py (md5 2b65c046618a41723ee8c2b24dc40caf,
  60-line b64 canvas dmg-content-names) - the user rejected BOTH
  form-word names (prose, then explanation) as "way too general
  and nondescript". THE NAMING DOCTRINE now in force: a file
  names its TRUE CONTENT from its own banner - the III.E slices
  are alphabetical item ranges and take first_item_to_last_item
  (miscmagic_alchemy_jug_to_bag_of_devouring.h ...
  miscmagic_sphere_of_annihilation_to_wings_of_flying.h), the
  single-item/list slices take the item (miscmagic_crystal_balls,
  miscmagic_deck_of_many_things, miscmagic_figurines_of_wondrous_
  power, miscmagic_robes, miscmagic_librams_lyre_and_manuals), and
  the item families take first_to_last (rods_absorption_to_smiting,
  staves_command_to_withering, potions/rings/wands/scrolls/
  specart likewise). Zero "prose"/"explanation" names remain in
  rules/dmg. THE RULE for all future naming passes: NEVER a form
  word (prose/explanation/pins/tables/batch) - always the content
  (item ranges, topic names, chapter titles). The banner is the
  source; line 3+ carries the R-round title and the item lists.
  NOTE: GitHub API rate limits from this sandbox - the codeload
  tarball (not rate-limited) is the fallback verifier. The other
  rules dirs' banner-name sweep (mm, dmo, spells, etc) must apply
  the content-name doctrine.
> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

- **DMG CLASS REFACTOR LANDED (2026-11-12, forced update
  4ccc0c4->bada0d2d, remote-verified via tarball): the major
  architecture pass over rules/dmg - the namespaces are OUT.
  tools/dmg_class_refactor.py (v2, md5 f17e9a9e3cf0693fe638127c2
  42e84aa, 111-line b64 canvas dmg-class-refactor). WHAT: all 90
  dmg headers lost `namespace rules`; each file stem is now
  `class CamelStem { public: ... };` at GLOBAL scope (instance
  classes - `Poison poison; poison.poisonCostPerDose(...)`;
  method names unchanged, mechanical). 4,044 fn bodies moved to
  90 new rules/dmg/*.cpp (`#include "rules/dmg/X.h"` + defs) so
  compilation now checks them; function-local statics moved
  verbatim. Enums/structs/enumerators are global; all
  `rules::SPYF_*`-style refs in callers stripped to bare. Call
  sites rewritten comment/string-aware in 118 caller files
  (114 audits + regtest.cpp + actor.cpp + state_dungeon.cpp +
  state_combat.cpp): qualified + bare dmg calls ->
  `inst.fn(` with `Class inst;` injected at the innermost
  enclosing block top; seams lancespeed/owedpins mentions were
  comment-only (untouched). npctraits->npcpersonae is the ONLY
  dmg->dmg cross-file call (got include + local instance).
  preflight battery build line gained 18 continuation lines of
  90 dmg cpps. RED ITERATION (v1, commit 4ccc0c4, force-pushed
  over): three compile-error families, all reproduced on the
  pre-commit 88d3be68 tree. LESSONS: (1) the enum-enumerator
  collector MUST blank comments BEFORE splitting on commas - a
  comma inside a trailing `// caught suspicious, imprisoned`
  comment swallowed the next enumerator (collected the bogus
  word "imprisoned", missed SPYF_*/NPPW_*/HPREF_* -> audits
  kept dead rules:: refs). (2) dmg code referencing ENGINE
  (still-namespace-rules) symbols bare - Dice type in 4 headers
  (subdue/weaponless/grenade/itemsavethrow, fixed via `using
  rules::Dice;`) and the uwSwimEncumbranceCapLbs seam call in
  uwfight (fixed via rules:: qualification in bodies); the tool
  now builds an engine-symbol inventory from rules/* minus
  dmg/audits. (3) tool bugs found by the dress rehearsal:
  a lone `/` (division) stalled the segment scanner; insertions
  inside replaced code segments duplicated text (rebuild now
  splits segments at injection points); finditer(pos,endpos)
  reports ABSOLUTE offsets. (4) when the remote already holds
  the RED commit and the user unwinds with git reset --hard
  HEAD~1, the relanded push needs `git push
  --force-with-lease`. Verification: double-run idempotent,
  decls==defs==4044, census labels 949 identical, 0 leftover
  rules:: dmg refs. Post-landing API-notes: all future
  dmg-touching code uses instances (no namespace), engine
  callers pattern: local instance at block top.
> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

- **DMG METHOD NAMES LANDED (2026-11-12, bada0d2d->dbf5edd8,
  remote-verified via tarball): the class-stem stutter strip -
  pass 1 of the dmg class-arc cosmetics, closing the arc's
  deferred item. tools/dmg_method_names.py (md5 0c744dda6e3ad231
  195ac004cd107113, 48-line b64 canvas dmg-method-names). WHAT:
  322 methods across 12 dmg files lost their redundant
  class-stem prefix - poison.poisonCostPerDose ->
  poison.costPerDose, disease.diseaseModCrowding ->
  disease.modCrowding, sage.sageAnswerTime -> sage.answerTime
  (disease 63, sage 61, wonder 42, insanity 41, grenade 21,
  miscibility 19, poison 15, hoard 14, herbs, pursuit, secondary,
  weaponless). RULE: exact lowercase stem prefix + next char
  uppercase/digit; survivor decapitalized unless an acronym
  (second char uppercase keeps caps). The set_spear.h #pragma
  once (pre-existing omission) was folded in after the banner.
  PROOF PATTERNS worth reusing: (1) method renaming is
  collision-free by construction once calls are inst.fn - but
  STILL die-loudly check per-class shadowing, cross-class
  ambiguity, and engine-symbol collisions (a stripped name
  equaling a rules:: fn would silently shadow as a member call
  inside bodies). (2) THE STRONG ONE: prove the pre-refactor
  tree has ZERO `.oldName(` occurrences - then every current
  member-call site is ours and a global (\.|->)old( rewrite is
  unambiguous. (3) In dmg files the rewrite covers three forms:
  decl lines, bare same-file calls, and Cls::old( defs (the
  (?<![\w.:]) lookbehind blocks the :: form - needs its own
  def_re). LESSON: regex $ needs re.M for line-anchored counts,
  and loose `\(...\);` counting over-matches - line-anchor
  decl/def checks. Diff surface was exactly 25 dmg files + 15
  audits (the 12 stripped classes are audit-only; engine
  callers - swimcross/uwfight/doorforce/locktime/weaponspeed -
  had no stutter strips). Census 949 identical, decls==defs,
  double-run idempotent. The class arc (namespaces out ->
  instance classes -> .h/.cpp split -> stutter strip) is now
  CLOSED. Remaining known dmg threads: none material. Next open
  arc: the content-name doctrine sweep over the other rules
  dirs (ddg cqc_batch*/lua_promo_batch* are the obvious form-word
  offenders; dmo's concatenated dmoXxx naming; recon was started
  but stopped by the user).

> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

## miscmagic merge (R257-R279, landed 2026-11-12, main 0a00ff06)

tools/miscmagic_merge.py (md5 0773a43aa737012714668f686d0b8bc4,
canvas miscmagic-merge, 78-line b64) merged the 23 III.E
explanation-prose part pairs into ONE pair:
rules/dmg/miscmagic_alchemy_jug_to_wings_of_flying.h/.cpp,
class Miscmagic_alchemy_jug_to_wings_of_flying, 1452 mmp*
methods, bodies verbatim, per-part banners preserved as internal
section comments (`// ---- part N (RNNN): stem ----`), the
11065/11067 upload-seam story kept as provenance in the top
banner. Audits r257-r279 rewritten string/comment-aware: class
refs -> merged class, decls collapsed to
`Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;` (the
45-char instance names gone; r257 alone drops 65), calls ->
miscmagic.mmpX(. regtest.cpp 23 includes -> one at part1's
position; preflight.sh build line 23 cpp entries -> one,
rewrapped 5-per-line. table1-5_footnotes byte-identical.
Census 949 labels identical, decls==defs, double-run
idempotent (applied 0), surface 46 del + 2 new + 25 rewritten.

RED UNWIND USED: the first (c6ee...) version had a
ternary-precedence bug in the banner indenter
(`'    ' + b[3:] if b.startswith('// ') else ...` stripped the
// markers, so part banners inside the class parsed as member
declarations) - preflight RED, and the user committed + pushed
the bad state. Unwind: git reset --hard HEAD~1 + push
--force-with-lease; the tool had been TRACKED in the bad commit
so the reset also deleted tools/miscmagic_merge.py (the b64 was
untracked and survived - re-decode, no re-paste needed).

LESSONS SEATED: (1) ternary precedence with `+` - the condition
binds AFTER the concatenation; never inline `cond` inside an
`a + b if c else d` list-append. (2) The fixed tool gained
check_class_body(): every line between public: and }; must be
blank, comment, or a decl - it catches banner mangling loudly
on BOTH fresh emit and the idempotent re-run (it correctly
refused to bless the user's broken tree twice as
"MERGE RED: non-decl line inside class body"). (3) A tool that
is committed before preflight passes becomes a tracked file:
git reset --hard then deletes it; always keep the b64
untracked as the recovery source, or re-decode from the canvas.
(4) Idempotency detection must not reparse the merged output
through the FRESH-run regexes (the merged banner contains all
23 part banners - load_parts must skip the merged stem and the
idempotent path reads its own `// ---- part N ----` section
comments instead; regex $ needs re.M).
Next open arc unchanged: content-name doctrine sweep over the
other rules dirs (ddg cqc_batch*/lua_promo_batch*, dmo
concatenated names).

> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

## miscmagic re-split + misc_magic/ relocation (landed 2026-11-12, main 30c35d9c)

User reviewed the merged pair (2107/8119 lines), wanted the parts
back but foldered: tools/miscmagic_split.py (md5
af1d56b3e829ea12b069e78356c310de, canvas miscmagic-split, 69-line
b64) UN-DID the merge - re-split the merged pair into the 23 part
pairs with original banners verbatim (new Adnd1 self-path line +
re-split provenance line), restored per-part classes
(Miscmagic_crystal_balls etc.) and per-audit decls kept the SHORT
instance (Miscmagic_crystal_balls miscmagic;), relocated the 5
table*_footnotes pairs (path strings only), all 56 files now in
rules/dmg/misc_magic/. regtest: per-part includes at part1's
position, per-part R comments; preflight: 28 entries sorted
5-per-line; audits r257-r279 per-part classes. Census 949,
decls==defs per part, footnotes path-only diffs, double-run
idempotent (applied 0), applied 94 changes. Ran directly on the
merged tree - no unwind needed.

LESSONS SEATED: (1) The split tool's idempotent path initially
verified only decls==defs - it blessed a HALF-APPLIED tree
(audits unrewritten after a crash mid-run). Hardened: idempotent
path must run the same stale_scan as the fresh verify. (2)
Genexp variable shadowing: ''.join(t ... for k, t in segments(t))
NameErrors when the parameter is also named t - keep parameter
and genexp variables distinct (merge tool used text, split tool
initially broke by renaming). (3) Self-identifying banner path
lines (// Adnd1 - rules/dmg/...) ARE updated on relocation (they
are the file's identity, not provenance prose); everything else
in moved files stays verbatim.

STATE: rules/dmg now has NO miscmagic_* files; everything
miscmagic lives in rules/dmg/misc_magic/ (23 part pairs + 5
footnote pairs). The miscmagic-merge canvas (0773a4...) is
obsolete history (tool still committed in the tree). Note: file
names keep their miscmagic_ prefix inside misc_magic/ - a
possible later stutter-strip if the user wants it. Next open
arc unchanged: content-name doctrine sweep (ddg
cqc_batch*/lua_promo_batch*, dmo concatenated names).

> REWOUND 2026-11-12 (main reset to 19daa1a1): this state now
> lives only on branch dmg-arc - see the final record "the dmg
> naming + miscmagic arc rewound".

## miscmagic filename unstutter (landed 2026-11-12, main 9801f6b6)

tools/miscmagic_filename_strip.py (md5 b2ec582f06b7bd0f40376b048c207952,
canvas miscmagic-filename-strip, 29-line b64) stripped the
miscmagic_ prefix from all 56 filenames in rules/dmg/misc_magic/
(miscmagic_crystal_balls.h/.cpp -> crystal_balls.h/.cpp; the 5
footnote pairs -> tableN_footnotes.*). Self-identifying path
lines (// Adnd1 banner + .cpp self-include) re-pointed inside
each file; regtest 28 includes and preflight 28 entries
re-pathed, original R comments kept. Class and instance names
NOT touched (filename-only pass). Census 949, decls==defs per
pair, double-run idempotent (applied 0), applied 114 changes.

LESSONS SEATED: (1) A rename map keyed by full FILENAME (with
extension) must not be reused as a stem map - the verify loop
built '...cpp.h' paths; derive stems by stripping the extension
where a stem is needed. (2) Self-path rewrites in a PAIR must
cover BOTH extensions: every .cpp includes its own .h, so
replacing only the same-extension path leaves stuttered includes
- the post-run stale_scan caught it ('stale stuttered path in
figurines_of_wondrous_power.cpp'); the fix is a per-file global
prefix replace of the old path (each pair references only
itself, verified by the earlier foreigninc=0 recon), gated by a
1-2 occurrence count check. (3) Guard placement matters: both
bugs were caught by the tool's own verify/stale-scan before
delivery, not by the compiler.

STATE: rules/dmg/misc_magic/ = 56 files, zero stuttered names,
zero stuttered path strings repo-wide. Canvas miscmagic-merge
(0773a4...) and miscmagic-split (af1d56...) are obsolete
history; tools remain committed in the tree. Next open arc
unchanged: content-name doctrine sweep (ddg cqc_batch*/
lua_promo_batch*, dmo concatenated names).

## the dmg naming + miscmagic arc REWOUND (user decision, 2026-11-12, main reset to 19daa1a1)

USER DECISION (Curtiss, 2026-11-12): the arc from the dmg
naming passes through the miscmagic merge/re-split/unstutter
(and the in-flight per-item split preparation) had gone down a
rabbit hole - rewound ALL THE WAY TO PROSE to start the
renaming and splitting over again. The target 19daa1a1 was
chosen because the user wanted the 'prose'-named files back;
verified by tarball BEFORE the reset: rules/dmg/ = 90 files,
ALL HEADER-ONLY (the .h/.cpp split and the namespace removal
had not happened yet - all 90 headers still carry `namespace
rules`), miscmagic_prose_part1-23.h + 5 miscmagic_tableN_
footnotes.h + the other prose series (potions_prose_part1-3,
rings_prose_part1-3, rods_prose, scrolls_prose,
specart_prose_part1-2, staves_prose, wands_prose_part1-2);
regtest carries the 23 miscmagic_prose includes; the audit
population is IDENTICAL to 9801f6b6 - the whole arc was
layout-only, nothing codified was lost (this pre-reset check
is what made the force-push rewind safe).

LANDED (user-verified in Termux, 2026-11-12): branch dmg-arc
created at 9801f6b6 and pushed to origin (the 7 rewound
commits 044599e4, 88d3be68, bada0d2d, dbf5edd8, 0a00ff06,
30c35d9c, 9801f6b6 stay reachable one checkout away - the
first attempt's committed tools and lessons ride on it);
git reset --hard 19daa1a1 + push --force-with-lease origin
main; preflight GREEN at the target; HEAD == 19daa1a1 on
local main and origin/main.

CONSEQUENCES (standing until the redo supersedes them):
- MAIN'S DMG STATE IS NOW the pre-naming state: namespaced
  header-only files, prose filenames, miscmagic in rules/dmg/
  (NOT in misc_magic/, no merged pair, no split, no unstutter).
  The records marked REWOUND above describe the dmg-arc
  branch, not main.
- The per-item split work is MOOT: the roster and the 835-line
  tool (canvases miscmagic-item-roster, miscmagic-item-split;
  the split.b64 handoff never landed) were built against the
  23-part misc_magic/ state - ignore them; the redo starts
  from the prose-named state, clean slate.
- The census is unchanged (949 labels); any other clone needs
  a re-sync after the force push.
- LESSON: a layout-only arc is cheap to rewind - verify the
  census/audit population is identical across the arc
  BEFORE resetting, branch-then-reset, and the whole first
  attempt stays recoverable (dmg-arc) instead of lost.

## misc magic LUA PROMOTION A1 (landed 2026-11-12, main 23662f73)

THE ROUND: tools/miscmagic2lua.py (md5
d07a6c8ec8ab6401c9190b3e4262ad5a, 2,309 lines, canvas
miscmagic2lua - 7-line frontmatter + 363-line b64 body, body
md5 892677e1b5793cc5534d67ba109b3787) - pure-stdlib
idempotent tool promoting the 23 prose part headers
(rules/dmg/miscmagic_prose_part1-23.h, R257-R279) into 166
item defs, one .lua per roster item, 16 sub-items (9
figurines, 7 bard instruments) nested in their parents.
Headers stay untouched in rules/dmg/ (de-wire is A2).

THE PLACEMENT RULING (Curtiss, 2026-11-12, SUPERSEDES the
earlier content/items/misc/ placement): defs go in
content/magic_items/ - "keep non-magic and magic items
separate". content/items/ holds non-magic; content/items/
artifacts/ empty placeholder untouched. The tool creates
the dir via os.makedirs.

RUN OUTPUTS (user-verified in Termux): run 1 PROMOTE
"defs: 0 present, 166 written", run 2 VERIFY "defs: 166
present, 0 written", both GREEN; part headers 23 (R257-
R279); methods 1452 (1329 scalar pins, 123 table walkers);
item defs 166 (+16 subs nested: 9 figurines, 7
instruments); kMisc rows reconciled 166 (167 rows, artifact
excluded); header-only defs 4; verify 166/166
byte-identical. Independent checker carried over: lua
parse 166/166, pins 1329/1329, tables 123/123, cpp
coverage 1452/1452, subs 16, kMisc reconciled; defs 0
lines >78 (longest 75); old-path vs new-path output diff
-r byte-identical 166/166. RED suite 10/10 (mutated def
dies, delete self-heals byte-identical, phantom dies
naming content/magic_items, comment-anchored header
mutation dies).

LANDED: commit 23662f73 on main, pushed 19daa1a1..
23662f73 - "misc magic lua promotion A1: 23 prose parts ->
166 item defs in content/magic_items/ (data-only)", 167
files changed, 9832 insertions (166 defs + the tool).
Preflight GREEN, census UNCHANGED at 949 (A1 is data-only;
the headers are still wired, the audits untouched).

THE KWALISH ANOMALY (prior session) RESOLVED: the
corrupted def was test-harness sed collateral; reproduced
and proved the tool's contract (missing def + corrupted
header -> PROMOTE heals from header -> GREEN; header
restored -> RED). The tool was never wrong.

PREFLIGHT HYGIENE LESSON: the step-4 hygiene gate prints
RED "untracked present but NO tracked file modified (the
7a86ee7 lesson)" - the EXPECTED FALSE POSITIVE for
additions-only commits (A1 modifies nothing tracked; the
7a86ee7 splice-not-run scenario does not apply). Verified
with empty `git diff HEAD --stat` + exactly 2 untracked
entries (content/magic_items/ + tools/miscmagic2lua.py);
tree clean post-commit. Gate stands; additions-only rounds
justify the hygiene FAIL explicitly.

DELIVERY-CORRUPTION LESSONS (2026-11-12, the b64 paste
failure): large b64 chat pastes corrupt deterministically
via two distinct mechanisms - (1) the file-read channel
DUPLICATED a char at a line boundary (line 40 "WZ"->"WWZ",
+1 byte); (2) message generation SUBSTITUTED a char (line
19 "KG"->"KO", same length). The corrupted paste died
loudly (gzip crc error, then a SyntaxError tool) - the
md5/gzip gates caught both, nothing bad committed.
RELIABLE DELIVERY = CHUNKED HEREDOC PASTE (cat >
splitNN.b64 <<'EOF', ~40 lines per chunk, 10 chunks for 363)
with PER-CHUNK md5 gates, then line-level diagnosis when a
chunk md5 fails: `awk '{print NR": "length($0)}'` length
scan + per-line md5 fingerprints
(`while IFS= read -r l; do printf '%s\n' "$l" | md5sum |
cut -c1-8; done | cat -n`) vs the author-side expected
list, user pastes the bad lines back, targeted
`sed -i 'Ns/^XX/YY/'` fixes, chunk md5 gates re-confirm.
Concatenate + gate the whole (363 lines / 892677e1...)
before decode. NEVER retype base64 from memory; always
copy from a verified read. The GitHub App connector is
READ-ONLY on ccicco/Adnd1 (403 on branch push) - no push
route; the CANVAS is the durable verified copy (awk
'NR>7' recovers the b64 body; decode-verify to d07a6c8...
before use; re-derive chunks from it via split -l 40 -d).
Env resets wipe /tmp and non-project /home/user files but
KEEP canvases and Knowledge.

STATE: A1 landed and pushed. A2 (de-wire the 23 prose
headers in rules/dmg/, registry wiring, walking audits)
is PARKED - prepare ONLY on Curtiss's GO.

## misc magic defs -> LETTER DIRS (landed 2026-11-13, main 6e164600)

THE GAP (Curtiss, 2026-11-13): A1 had landed the 166 defs
FLAT in content/magic_items/ - but content/monsters
buckets everything a/..z/ by first letter. THE RULING:
alphabetize the lua files like content/monsters - one
letter dir per first char of the stem. 21 letters hold
defs (a-w minus o,u,x,y,z); the rowless pseudo-items
bucket too: intro.lua -> i/, eyes.lua -> e/, librams.lua
-> l/. No top-level files remain (the monsters way).

THE TOOL UPDATE: tools/miscmagic2lua.py grew letter-dir
layout (def_dir/def_path/legacy_path helpers + a
scan_phantoms that walks letter dirs and dies on unknown
entries, non-letter dirs, empty non-roster letter dirs,
and flat-and-letter duplicates). PROMOTE MIGRATES: defs
found at the legacy flat root are byte-gated first, then
os.replace'd into their letter dir ("defs: N present, N
written, N legacy moved"); a def present both flat and
in its letter dir dies loudly; corrupted legacy defs die
BEFORE the move. An emptied roster letter dir is legal
(PROMOTE refills it - a fresh-letter deletion self-heals;
that bug was caught by the RED self-heal test and fixed
pre-delivery). New gates on the py: 9a9f34f589660d4eb
8e1f216ad294a85, 2381 lines; canvas miscmagic2lua body
377 lines / 3c6c332a4f7805f76538c5768fbca9a3 -> gz
bfe1681e3f1b945c80b5c0f171bbaf68 -> py 9a9f34f5...
(awk 'NR>7' recovers; supersede the old 363/892677e1 ->
d07a6c8 gates).

PRE-LAND VALIDATION (author side, against the real tree):
the repo is PUBLIC - urllib-fetched the 23 part headers +
dm/treasure.cpp + all 166 landed defs at 23662f73, built a
fake repo root (stub regtest.cpp), and ran the new tool:
fresh PROMOTE 166 written; migration run "0 present, 0
written, 166 legacy moved"; ALL 166 defs byte-identical to
landed A1 (pure move, diff clean vs the fetched flat set);
VERIFY run green; RED suite 11/11 (flat phantom, in-letter
phantom, non-letter dir, empty non-roster letter dir,
flat+letter duplicate, corrupted def, corrupted legacy
def dies before move, stray txt in letter dir, stray root
file, nested dir in letter dir, delete-only-q-def
self-heal).

LANDED (Termux, 2026-11-13): tool swapped in via the
chunk protocol (all 10 chunks gated, assembly gates
green), run 1 PROMOTE "0 present, 0 written, 166 legacy
moved" + "letters: 21 (a b c d e f g h i j k l m n p q r
s t v w)", run 2 VERIFY "166 present, 0 written, 0 legacy
moved", both GREEN; preflight battery green, census 949
unchanged; commit 6e164600 "misc magic lua defs ->
letter dirs (monsters convention): miscmagic2lua letter
layout + legacy migration", pushed 23662f73..6e164600.
Defs are pure renames (R100, data unchanged); hygiene had
NO false positive (the tool is a tracked modification -
the additions-only lesson does not apply to layout
rounds).

DELIVERY-CORRUPTION, THE FULL PICTURE (2026-11-13 session
- 4 of 10 chunks corrupted, ALL by my chat-emission
channel, in THREE distinct deterministic mechanisms):
(1) single-char substitution, same length (chunk 01 line
21, chunk 07 lines 18/31); (2) duplicated char (chunk 09
line 11: "85NrK5l" -> "85NrrK5l" - the WZ->WWZ mechanism
recurs at the same spot every re-emission); (3)
LINE-BOUNDARY CHAR-SHIFT: the trailing char of one line
moved to the front of the next (chunk 08: line 11's 'm'
-> front of 12, line 12's 'U' -> front of 13, leaving 75/
76/77-char lines). THE CRITICAL LESSON: re-emitting the
full "correct" line DOES NOT WORK - my generation
re-produces the SAME corrupted bytes at the same
position (proven: a full-line sed fix left the chunk md5
byte-identicAL, and md5ing my own emitted line matched
the user's corrupted fingerprint exactly). THE WORKING
PROTOCOL: (a) per-chunk md5 gates catch the corruption;
(b) on failure, user runs the length scan + per-line
fingerprint loop, I diff the fingerprints against the
canvas-derived expected list; (c) user pastes the bad
lines back OR I reconstruct them from their
fingerprints; (d) the fix is a TINY PATTERN SED on bytes
already in the user's file - append one char, delete a
leading char, dedupe a doubled pair (sed -i
'12s|NrrK5l|NrK5l|', '18s|^s||', '11s|$|m|' style) - the
long b64 NEVER crosses my channel twice; (e) SIMULATE THE
FIX AUTHOR-SIDE FIRST: reconstruct the user's file from
their fingerprint report + the canvas truth, apply the
sed, gate the chunk md5 - this caught my own line-mapping
error before it reached the user (I targeted the wrong
line in the chunk 09 fix; the simulation failed and I
re-mapped). ALSO: user-side paste casualties happen
(missing first line, duplicated line 1, scrambled
terminal paste leaving an 18-line chunk) - the same
fingerprint scan catches those (duplicate fingerprints =
dropped '1i' prepend line, etc.); sed '1i' + '2d' + tiny
pattern fixes close them. Fast-mode note: Curtiss
switched out of deep mode mid-delivery blaming the
corruption rate - the corruption is in the emission
channel, not the canvas; the canvas re-derived to the
expected md5s at EVERY diagnosis point (body 3c6c332a
checked 5+ times across env resets).

STATE: A1 + letter dirs landed (main 6e164600). A2
(de-wire the 23 prose headers in rules/dmg/, registry,
walking audits) still PARKED - prepare ONLY on Curtiss's
GO.

## R1027 - the A2 de-wire (landed 2026-11-13, main bb971d0a)

THE ROUND: retired the 23 miscmagic prose part headers
(rules/dmg/miscmagic_prose_part1..23.h) and their 23 audit
fragments (r257..r279_misc_magic_prose_part_*.h) to a NEW
boneyard/dmg/ tree at repo root (headers boneyard/dmg/,
fragments boneyard/dmg/audits/, git mv 100% renames), built
the LIVE registry (items/MiscItemRegistry.{h,cpp}, Lua 5.4
C API, the MonsterRegistry pattern + STRICT unknown-key
rejection, rows[] optional at top level / forbidden in
subs), and REPLACED the 23 retired pin-audit labels with 8
new registry-audit labels (load/letters/roster/sources/
rows/pins/tables/subs) in the generated fragment
rules/audits/r1027_misc_magic_registry.h (9652 lines,
tools/miscmagic_audit_gen.py emits it from the defs).
regtest.cpp: -23 prose includes, -3 chained audit
includes (r257/r258/r259, r259 included r260-r279
transitively), +items/MiscItemRegistry.h after the
MonsterRegistry include (line 2), +the r1027 fragment
before the r280 anchor; 5047 -> 5025 lines.
tools/miscmagic2lua.py re-pointed to boneyard/dmg/ (the
headers stay the print-fidelity record; the tool still
reads them there) - delivered as a small in-place patch
script (tools/mm2lua_r1027_patch.py) instead of re-emitting
the 111KB tool; run 1 PROMOTE rewrites the 166 def comment
paths (comment-only drift, verified against the committed
tree), run 2 VERIFY. preflight.sh build line grew
items/MiscItemRegistry.cpp after items/items.cpp. THE
6e164600 ROOT SCRATCH (split00-09.b64, split.b64,
tool.py.gz, the stray miscmagic2lua.py) was git rm'd with
the round. CENSUS: 949 - 23 retired + 8 registry = 934.

LANDED GATES (read back from pushed bb971d0a):
tools/miscmagic2lua.py 224d8da4a118912f2f61b08bb69c34f1;
tools/mm2lua_r1027_patch.py 6415c02ec40d9715f00be094e100f7a4;
tools/miscmagic_audit_gen.py 6c814483cd1df738a5f35071c86602f7;
tools/r1027_splice.py 4a443bfc07e374e21f3bd76a6d5d8772;
items/MiscItemRegistry.h f283b9ea4864a38ac8784e3d1de41f0b;
items/MiscItemRegistry.cpp ed40a5b3b784998fc9f82122fc634df9
(465 lines); fragment 570c0abc35f1182431436404de481521
(9652 lines). Commit bb971d0a pushed 6e164600..bb971d0a,
234 files, census 934, preflight GREEN.

DELIVERY: 5 files (registry .h/.cpp, generator, splice,
mm2lua patch) as ONE tar.gz -> 7 b64 chunks (249 lines,
splitaa-ag); ONE corrupted chunk (splitae, 3 single-char
substitutions at lines 3/20/24), caught by per-chunk md5,
fixed by 3 tiny pattern seds (the r/l, + vs /, / vs f
class), all other chunks clean. Root-scratch note: the
delivery tarball was extracted at the repo root and its
r1027_files.tgz/split chunks were rm'd untracked BEFORE the
commit (bat.log debugging scratch also rm'd - NEVER let
round-delivery scratch ride into a commit).

THREE POST-DELIVERY BUGS, ALL THE AUTHOR'S, ALL CAUGHT BY
THE TERMUX COMPILE/BATTERY (the sandbox has NO C++
compiler - apt forbidden - so the preflight was the first
real compile; static author-side checks caught the class
the next time round):
(1) kSrc sizing: the generator emitted kSrc[N] = {2N
ints} (and compared sources.size() to N*2) - 165 compile
errors, fixed by 2 seds (kSrc[2N], size()==N).
(2) owner pointer init: emit_table_assert passed
"d->subs[%d]" where the sink declares "const auto*
owner = ..." - value, not pointer; fixed to
"&d->subs[%d]" (2 clang errors).
(3) THE SEGFAULT (exit 139, battery died mid-log, census
all-zeros downstream): checkAllowedKeys walked the table
via lua_next(L, idx) where nested call sites pass idx=-1
("table on top"); after lua_pushnil the -1 slot is the
NIL, so lua_next indexes the nil -> lua_error longjmp with
NO active pcall (parseDef runs after luaL_dofile
returned) -> segfault at the first nested key check. FIX
(canonical idiom, 2 seds): pin the slot first - const int
t = lua_absindex(L, idx); lua_next(L, t). LESSONS: (a)
the census all-zeros pattern + a log cut mid-line =
block-buffered stdout, the visible cut is NOT the crash
site - rerun with stdbuf -oL (Termux: /tmp is NOT
writable, redirect to a local bat.log); (b) ANY Lua table
walk that pushes between indexing calls MUST pin the
table with lua_absindex before the walk - a -1 index is
only valid if nothing is pushed in between; (c) a loader
that parses unprotected (after dofile returns) turns
every Lua API misuse into a segfault, not an error -
preflight is the only gate that catches it.

AUTHOR-SIDE RECOVERY (worked cleanly): after env resets
wiped the rehearsal tree AND /tmp (twice), the round was
rebuilt from the conversation's own gated chunks - the
chunk bytes in my own emitted message matched the user's
gates (one re-emission bug: my context copy of splitae
line 20 carried the corrupted + again; the 3 known seds
reproduced the exact tgz md5 a76702c7) + a fresh codeload
fetch of main; the replay reproduced the user's tree
bit-exact (fragment md5 matched their report). Standing:
the conversation + the pushed repo are the recovery
record; keep every chunk gate quoted in-chat.

STATE: A2 LANDED (main bb971d0a, census 934). The misc
magic arc is COMPLETE end-to-end: defs live in the
registry, prose headers in the boneyard, 8 registry
labels in the census. Next work awaits Curtiss's GO.

## R1028 - the misc magic ENGINE de-wire (landed 2026-11-13, main 3400f07a)

THE ROUND: the follow-up to R1027, the full rewire (user picked
"Registry/tooling follow-up", FULL rewire - "replace ItemRow
plumbing with registry-native types"; G1 explicitly declined again).
dm/treasure.cpp retires the five hardcoded kMisc ItemRow arrays
(167 rows incl. the artifact dispatch): the tables are now the 166
def rows at content/magic_items/<letter>/<stem>.lua, loaded by a
file-scope lazy miscReg() (R71fix letter-dir loop, adnd1.cpp
untouched - it is a Win32 shell TU preflight skips, so the loader
lives in treasure.cpp), viewed by miscView(n) as band-sorted
std::vector<items::MiscItemRow> (registry key order is
alphabetical, NOT band order - the sort is mandatory; bands are
contiguous 1..100 per table), rolls via pickMiscRow/makeMiscItem
(same 1+d100 band-scan + valIn/inRange semantics), and the R122
pin API reads the views: magicTablePinCount/magicTablePin branch
categories 4-8 to miscView, everything else (potions/rings/rods/
armor/swords/weapons/artifacts) keeps its ItemRow arrays - only
misc was promoted. adjustSpecial UNCHANGED (name-driven: Bracers
500xp/3000gp per AC pt, Cloak 1000xp/10000gp per plus, "Artifact
or Relic" -> kArtifacts). THE ARTIFACT ROW RULING (my call, user
asked "what do you suggest"): stays hardcoded - injected into
view 1 at band 17,17 (lands at index 7 by the band sort); it is
the Special-table dispatch trigger, deliberately excluded from
defs by the A1 ruling, and adjustSpecial keys on its exact name.
Views reproduce counts 33/30/33/36/35 == mNRowCount(), so the
R122 pin audits stay green unchanged. Fragment
rules/audits/r1028_misc_engine_registry.h (7 labels: load/
counts/bands/parity/artifact/rows/roll - parity cross-checks the
pin API vs rules::mNRowLo/mNRowHi, rows cross-checks engine pins
vs def rows field-by-field), seated after the r1027 fragment.
Splice tools/r1028_splice.py: anchored edits + before/after
gates + census mirror of the R112c preflight extraction
(unique patterns, regtest.cpp + rules/audits/*.h). CENSUS
934 -> 941.

LANDED GATES (read back from pushed 3400f07a): splice
37dcc63a855f379e39d57dbd757d6632; fragment (post-roll-fix)
9b95ccfe461e13dfe7c92e6fbd4420b4 (184 lines); regtest include 1,
kMisc arrays 0, miscView 9, treasure.cpp 1156 lines; census 941
patterns. Commit 3400f07a "R1028: misc magic engine de-wire
(registry-native kMisc tables) (census 941)", pushed bb971d0a..
3400f07a, preflight GREEN.

DELIVERY: 2 files (splice + fragment) as one tar.gz -> 3 b64
chunks (90 lines, splitaa-ac). THREE corruptions in my emission,
all caught by per-chunk md5: splitaa line 5 single-char sub
(3->0), splitaa line 7 LINE-BOUNDARY LEADING-CHAR SHIFT (an 'i'
prepended - the 77-char length scan), splitab line 34 single-char
sub (t->s). Fixed by 3 tiny pattern seds, simulated author-side
first.

THE RECOVERY DOCTRINE (NEW, proven this round): env resets wiped
both the rehearsal tree AND the source files, and the true b64
was NOT in chat (my emitted chunks were themselves the corrupted
copy) - but the TRUTH was fully reconstructible from the
published gates alone: (1) inflate the corrupted b64 with
zlib decompressobj - the TRUE tar prefix inflates clean before
the first corruption ("#!/usr/bin/env python3..." + valid header1,
which hands you file sizes/mtimes); (2) rebuild the source files
byte-exact from the conversation's own write_file calls and
GATE ON THE PUBLISHED FILE MD5s (the splice needed the edit/sed
history replayed - the missing 299 bytes were the doubled
census comment header edit2 left behind); (3) with both sources
true, regenerate the tarball with the REAL tar+gzip (zlib deflate
is NOT byte-identical to gzip - use tar czf, touch mtime from
the recovered header; gzip via pipe stores mtime 0) and gate on
the published tgz md5 - it HIT, giving the true b64 and the
exact corruption diff. Deflate-consumed-length and inflate-partial
lengths are UNRELIABLE oracles (garbage inflates far and
prefix-consistent); only md5/CRC gates are truth. ALSO:
b64decode validates %4 == 0 - a dup/shifted line changes the
total count loudly.

TWO PREFLIGHT ITERATIONS (both user-side, both expected classes):
(1) FIRST RUN: 7 census FAILs, labels 0 times - the user had run
the gates, skipped python3 tools/r1028_splice.py, and jumped to
preflight (the tarball delivers the TOOL, the splice applies it;
grep r1028_misc_engine regtest.cpp = 0 was the tell; splice run
-> SPLICE OK). (2) SECOND RUN: "roll audit: bad 549" and the
return 1 truncating the battery into hundreds of phantom census
FAILs - the roll smoke required final name == pin row name, but
adjustSpecial renames three rows post-roll (Bracers of Defense
(AC N), band 60-79 = 20% of table 1; Cloak of Protection +N,
band 33-55 = 23% of table 2; the artifact dispatch -> an
artifact name, pinned via category 12); 549 reconciled exactly
(0.20+0.01 of cat-4 rolls + 0.23 of cat-5 rolls over 40000).
FIX: the roll smoke accepts pin names of the same category, the
two adjustSpecial prefixes, or a category-12 artifact pin name -
delivered as a small python heredoc patch (md5-gated,
9b95ccfe...), fragment md5 in the record is the POST-fix value.
LESSON: simulate the ROLL PATH of any roll audit, not just the
pin parity - adjustSpecial is part of the seam and renames;
author-side Python parity sims cannot see it (no C++ compiler,
preflight was the catcher, twice running).

STATE: R1028 LANDED (main 3400f07a, census 941). The misc magic
arc is now native end-to-end: defs -> registry -> ENGINE rolls
and pins. Next work awaits Curtiss's GO.

## R1029 - content-name sweep over rules/ddg + rules/dmo (LANDED)

COMMIT: c973878f "R1029: content-name sweep over ddg and dmo
(census 941)", pushed 3400f07a..c973878f.

WHAT: 30 content headers renamed off mechanical batch names onto
banner-derived content names (banner is the source; never form
words; R-round comments in regtest includes verbatim):
- rules/ddg: cqc_batch1-8 -> appendix3_<span> (joins the
  appendix1/2/4 family); lua_promo_batch1-7 -> defs_<span>.
- rules/dmo: dmomaxims->seven_maxims, dmocampaign->
  remaining_maxims, dmoadventures->adventure_doctrines,
  dmoworlds->world_ratings, dmomonsters->legendary_ladder,
  dmospells->spells_and_magical_items, dmoitems->
  creating_magical_items, dmoduels->magical_duels, dmodweomers->
  true_dweomers, dmohighlevel->high_level_characters,
  dmohighskills->high_level_skills_and_warriors, dmohighwizpri->
  wizards_and_priests_beyond_20th, dmohighrogues->
  rogues_beyond_20th, dmohighascend->
  demihumans_divine_ascension, dmoduelroster->
  spell_dueling_roster_and_index.
- 157 token refs rewritten across 64 files (regtest.cpp 30
  includes, 30 tools/spec_rNNN.json header_file, banner
  self-paths); 596 specs re-validated; census 941 UNCHANGED
  (pure rename round). No substring hazards (\b regex; dmoduels
  is not inside dmoduelroster; new paths contain no old tokens).

TOOL: tools/r1029_content_names.py (md5 2017d7aa...) - pure
stdlib, git mv, word-boundary rewrites, SKIP doc/vibe/ +
rules_reorg_pass1.py + self, gates, idempotent double-run.

DELIVERY CORRUPTION (1 hit, known class): splitaa line 40
single-char sub X->V ("JLf5V"); per-line md5 profile isolated
it (awk length+edges first, then per-line md5sum | nl diff),
fix = sed -i '40s/JLf5V/JLf5X/'. All gates then green (b64
c7f7e412, tgz 77d04837, 3329 B, 2 chunks 40+19 lines).

DRESS-REHEARSAL LESSON (new, stub-git precedent again): the
tool initially gathered the tracked-file list LAZILY and ran
git mv BEFORE the rewrite pass, so the snapshot held pre-rename
paths against post-rename disk -> FileNotFoundError. Fix: (1)
snapshot tracked_text_files() ONCE up front, (2) rewrite tokens
FIRST, (3) git mv AFTER, (4) stale-scan re-queries fresh.
Order matters in any mv+rewrite sweep tool.

VERIFIED (codeload at c973878f): tool md5 2017d7aa, 15 ddg new
names + 15 dmo headers, old files gone, stale-scan NONE outside
skips, R1028 fragment intact (184 lines), kMisc arrays 0,
miscView x9, regtest includes re-pointed with comments verbatim.
User-side preflight: GREEN, census 941, all bad 0.

STATE: R1029 LANDED (main c973878f, census 941). Content-name
surface is clean end-to-end. Next work awaits Curtiss's GO.

## R1030 - content-name sweep over rules/mm (LANDED)

COMMIT: 828a6f73 "R1030: content-name sweep over mm (census 941)",
pushed c973878f..828a6f73.

WHAT: the 10 MM normalization batch headers renamed onto
banner-stated letter spans (content-name doctrine, part two
after R1029's ddg/dmo):
- mm1_normalization_batch1-6 -> mm1_letters_a_to_f / g_to_k /
  l_to_p / q_to_s / t_to_v / w_to_z (banners state spans).
- mm2_normalization_batch1-4 -> mm2_letters_a_to_d / d_to_m /
  m_to_s / s_to_z (batch2-4 banners state spans outright:
  derro through mephistopheles, mihstu through shadow_mastiff,
  shator through zygom; batch1's a-to-d rides its audited-keys
  list amaimon..dao). Boundary letters shared (d, m, s) mirror
  the real batch overlaps.
- 60 token refs rewritten across 25 files (regtest 10 includes,
  spec_r1009-r1022, banner self-paths); 596 specs re-validated;
  census 941 UNCHANGED (pure rename round). NO corruption this
  delivery - all chunk gates green first paste (splitaa
  0b99f90e, splitab e12bac76, b64 e51c7201, tgz 041e1d1a
  3045 B, tool 76bfce09).

SUBTLETY (verified safe): the rules/audits names
rNNNN_mm1_normalization_batch_one..six use WORD suffixes, so
the batch-digit tokens (\b + regex) cannot touch them; audit
headers and their regtest includes stayed verbatim by design
(R822). No substring hazards; new paths contain no old tokens.

TOOL: tools/r1030_mm_content_names.py (md5 76bfce09) - cloned
from r1029 tool, MAP of 10, dir_for=rules/mm, R1030-specific
regtest gate (n_inc == 10 mm[12]_letters_ includes), same
snapshot-then-rewrite-then-git-mv order (R1029 lesson), same
skips (doc/vibe/, rules_reorg_pass1.py, self), idempotent.

REMAINING batch-name surface (recon at c973878f): rules/meta
14 files, rules/dragon 12 promo_batch01-12, rules/ff 11
(8 promo_batchN + 3 normalization_batchN). The content-name
sweep's endgame after R1030.

VERIFIED (codeload at 828a6f73): tool md5 76bfce09, 10
letters_ headers, old files gone, stale-scan NONE outside
skips, 10 mm normalization audit headers intact, R1028
fragment 184 lines, miscView x9, regtest includes re-pointed
with comments verbatim.

STATE: R1030 LANDED (main 828a6f73, census 941). Next work
awaits Curtiss's GO.

## R1031 - content-name sweep over meta/dragon/ff, ALL remaining batches (LANDED)

COMMIT: 4187d2fa "R1031: content-name sweep over meta dragon ff
(census 941)", pushed 828a6f73..4187d2fa. THE CONTENT-NAME
SWEEP IS COMPLETE - this was the last mechanical batch-name
surface in the tree (78 renames across R1029+R1030+R1031).

WHAT: 37 headers renamed onto banner content in one round:
- rules/meta (14): migration_batch_* -> migration_<content>
  (pilot, dmg_appendix, dmg_tables, subclass, hundred_blocks,
  ua_and_wsg, wsg_tail_and_dsg, planes_and_oa, oa_tail,
  final_digest, final_holdback); promotions_mop_batch1-3 ->
  promotions_mop_ff_never_load_repairs / _mm1_text_completion /
  _mm1_collation.
- rules/dragon (12): promo_batch01-12 -> promotion_<issue span
  per banner> (promotion_pre_walk_trio_and_issue_2, then
  promotion_issue_3 up to promotion_issues_24_to_26).
- rules/ff (11): normalization_batch1-3 -> letters_a_to_g /
  letters_h_to_r / book_closer (banner spans; batch3 is the
  stated book closer, banner silent on letters); promo_batch1-8
  -> promotion_<banner hook> (arc_opener,
  disenchanter_to_sandman, outdoor_tail, dungeon_cells,
  missing_prints_opener, prints_flind_to_kuo_toa,
  prints_lamia_noble_to_umpleby, print_walk_closer).
- 185 token refs rewritten across 84 files (regtest 37
  includes, spec_r824-r1025, banner self-paths); 596 specs
  re-validated; census 941 UNCHANGED.

TOKEN-ZERO-PADDING NOTE (new): dragon promo_batch01-12 are
zero-padded, ff promo_batch1-8 single-digit - distinct tokens,
no substring hazards, but dir_for MUST dispatch on
re.match(r"promo_batch\d\d$") (dragon) vs single-digit (ff);
the naive "promo_batch in stem" test misroutes the ff batch.

DELIVERY CORRUPTION (1 hit, known class): splitab line 16
single-char sub / -> + ("YUEd+SoW3d"); per-line md5 profile
isolated it (line 16 expected cda8698c), fix = sed -i
'16s#YUEd+SoW3d#YUEd/SoW3d#'. All gates then green (splitaa
0633c843 clean first paste, splitab 3b5a3464 post-fix, b64
50beedb5, tgz c3514c9b 3393 B, tool 5564eedc).

ENV-RESET NOTE: an env reset mid-round wiped /home/user/r1031
and /tmp between authoring and delivery - the tool was
re-authored byte-exact from the landed r1030 tool + the
conversation's edit pipeline (md5 5564eedc matched
author-side truth). Also: a rehearsal verification command
timed out at 120s (per-token grep loop x35 over the tree +
full-tree cmp loop); keep post-run verification to combined
single-pass greps (the tool's own gates cover the rest).

TOOL: tools/r1031_batch_content_names.py (md5 5564eedc) -
cloned from r1030 tool, MAP of 37, 3-dir dir_for dispatch,
regtest gate iterates all MAP tokens (per-token fail message),
same snapshot/rewrite/mv order, same skips, idempotent.

VERIFIED (codeload at 4187d2fa): tool md5 5564eedc, 38 new
content names in place (37 + book_closer), all old files gone,
stale-scan NONE outside skips, R1028 fragment 184 lines,
miscView x9, regtest includes re-pointed with comments
verbatim. User-side preflight GREEN, census 941, all bad 0.

STATE: R1031 LANDED (main 4187d2fa, census 941). The
content-name sweep arc is CLOSED: every rules/ header now
carries a content-derived name. Next work awaits Curtiss's
GO.

## R1032 - dungeon encounter engine de-wire (LANDED)

COMMIT: 9927c6f8 "R1032: dungeon encounter engine de-wire
(census 948)", pushed 4187d2fa..9927c6f8.

WHAT: the R1028-misc-engine shape applied to the DMG Appendix C
dungeon encounter tables. tools/r1032_splice.py parsed the
retired kLevel/kDrag/kMatrix/kLists arrays out of
dm/encounters.cpp (213 level rows [20,13,18,19,21,26,42,26,18,
10], 72 dragon rows [3,10,10,10,10,10,10,9] for ages 3-10,
12x10 matrix, 6 pools) and emitted 20 lua files under
content/tables/encounters/ + dm/EncounterTableRegistry.{h,cpp}
(MiscItemRegistry shape, STRICT key rejection, POSIX/Win32
loadDirectory) + the 7-section battery fragment
rules/audits/r1032_encounter_engine_registry.h (load/counts/
bands/matrix/lists/rows/roll, d20 pin set {1,2,3,5,8,11,15,17,
19,20} -> mlv 1..10 at dungeonLevel 7). encounters.cpp region
cut (4767 -> 4478 by the tool's split count), INC adds
EncounterTableRegistry.h + <array>/<map>/<string>, RowKey/
DragonKey const char*->std::string, view-backed LEVEL_TABLE/
DRAGON_TABLE, MATRIX_REF x2, SPECIALS/ELEMENTAL/KEYS_* anchors,
.c_str() for pushUnique; kPrinces/kArchDevils RETAINED in VIEWS
(shared with planar/psi dispatch). Census 941 -> 948.

DELIVERY SAGA (the b64 round of rounds): first delivery (7
chunks) corrupt in 3 chunks (ac/ad/ae) - per-line md5 profiles
isolated 4 corrupt lines, fixed with 4 tiny seds (d->t,
missing leading v, missing 7, W->U); the "v" case needed an
author-side single-edit brute force (deletion class, invisible
to eye diff). SECOND delivery of the PATCHED tool (below) was
worse: 5 of 7 chunks corrupt, 7 bad lines, all single-char
subs (d->9, e->E, f->b, H->F, J->L, N->H) plus one that LOOKED
identical - located by od -tx1 byte dump (9 vs 8 at offset 17),
NOT a homoglyph. STANDING LESSON: single-char b64 corruption is
now the expected failure mode; per-line md5 + od byte dump
pinpoints every one; tiny pattern seds only, simulate the fix
set author-side (inject corrupt lines, sed, verify full chunk
+ b64 + tgz md5 chain) before handing over.

TWO REAL BUGS the Python sim could not see (both compile-gate
catches, both R392-class):
1. FRAGMENT-SCOPED INCLUDE FAULT: the fragment #included
dm/EncounterTableRegistry.h mid-main - a namespace definition
inside function scope is illegal C++ ("namespaces can only be
defined in global or namespace scope", 20 errors, battery
exited, census cascade). FIX: the include moved to a regtest
include-block splice after line 1 (#include
"monsters/MonsterRegistry.h"); the fragment is include-free.
User-side recovery: git checkout the 3 tracked files + rm the
23 new files, re-deliver the patched tool, fresh splice.
2. kDrg OFF-BY-ONE: the fragment's kDrg[11] literal dropped
the dragon counts at index 2 ({ 0, 0, %s }) but the loop reads
kDrg[n] for n=3..10 - age 3 read 10 vs 3, age 9 read 9 vs 10,
age 10 read OOB garbage: exactly "counts audit: bad 3" and the
battery return-1 truncated all later labels (dozens of phantom
CENSUS FAILs - the R391 signature). FIX: one sed on the
fragment + one on the tool generator ({ 0, 0, 0, %s }).
The dragon subtable is indexed by MLV (dragonTable(mlv)) not
age - the fragment's dragonRows(n) cross-check is correct.

TOOL: tools/r1032_splice.py, two revisions this round: the
include fix (md5 0ca849a7) then the kDrg fix (final md5
2f55306aad0ad2fe965bc09fe2d6a427 - the landed one). Idempotent
(applied 1 / already 1), own gates: 213/72 row parse, 20-file
lua round-trip byte-exact, 210000-cell roll-path sim (dl
0..12+16; dl 13-15 = the preserved upstream OOB quirk, not
swept), brace-delta-0 static check on the 4 emitted C++ files.

VERIFIED (codeload at 9927c6f8): tool md5 2f55306a, encounters
census 948, 20 lua files, kDrg line correct, encounters.cpp
and all generated files byte-identical (md5) to the
author-side fresh rehearsal. User-side preflight GREEN, census
948, seven R1032 bad-0 lines, 0 warnings.

STATE: R1032 LANDED (main 9927c6f8, census 948). The dungeon
encounter engine is registry-native. Waterborne/outdoor
encounter tables remain deferred future rounds. Next work
awaits Curtiss's GO.

## R1033 - waterborne and underwater encounter de-wire (LANDED)

COMMIT: 5499a2e9 "R1033: waterborne and underwater encounter
de-wire (census 955)", pushed 9927c6f8..5499a2e9.

WHAT: the R1032 shape applied to the water family - the other
half of the DMG Appendix C encounter engine. tools/
r1033_splice.py (md5 96ffc7cf6c9ee2c82a315224a51f844b) parsed
the retired WaterRow arrays out of dm/encounters.cpp region
lines 753-1313: the R60 underwater set (kFreshShallow 27,
kFreshDeep 23, kSaltShallow 42, kSaltDeep 35, the shared p.190
Dinosaur Subtable kDinoSub 5) and the R127 waterborne set
(kWaterFreshSmall 9, kWaterFreshLarge 20, kWaterSaltShallow 24,
kWaterSaltDeep 20) - 205 rows -> 9 lua under a NEW SIBLING
DIRECTORY content/tables/encounters_water/ (keys
underwater_fresh_shallow/.../dinosaur_sub/waterborne_...).
Sibling-dir decision keeps the R1032 audit's 20-file pin and
the R127 line-diff pins untouched - no seated audit was edited.
dm::EncounterTableRegistry extended: EncounterWaterRow struct
(key/lo/hi/flags), hasWater/waterRows, STRICT water-shape
loader branch (isWaterKey = underwater_*/waterborne_*/
dinosaur_sub; flags restricted to {0,1,2,4}). encReg() loads
both dirs. rollWaterEncounter/rollWaterborneEncounter/
waterEncounterKeys/waterborneEncounterKeys/waterborneBands/
dinosaurSubBands rewritten registry-native via waterView()
cache + underwater/waterborneTableName selectors - signatures
and behavior identical, encounters.h untouched. 7-section
fragment rules/audits/r1033_water_encounter_registry.h (load
9+20-files-one-registry/counts/bands+engine-parity/flags+gate-
census/rows-pins/keys/roll sweep+rng smoke), regtest include
after the R1032 fragment. Census 948 -> 955.

AUTHOR-SIDE CATCHES before any delivery (the compile-gate
lesson holding): sim initially died on giant_octopus - the
bestiary has NO giant_octopus record (book prints "Octopus,
giant"); C++ legally rerolls via reg.find-null; sim now models
absent-key rerolls and reports them. Fragment bugs caught in
static review: (a) all-5-dinos-in-every-waterborne-combo pin
would phantom-fail - waterborne_fresh_small prints NO Dinosaur
row (as printed); fixed to union check + per-table expansion
for the dino-bearing tables only; (b) EncounterWaterRow r
declared in section 4's block but used in section 5 - cross-
block scope error, redeclared. Retired-token check must scan
only head/tail outside the spliced region (the replacement
block names the retired arrays in its provenance comment by
design).

DELIVERY: first DELIVERY V2 production run, zero corruption
drama. Canvas chunk-delivery-r1033 (6 chunks, 216 b64 lines;
tgz 8586acd68f6ec71e04abdfb63311f92b, b64 b6f9484a58acd35ba
77e431105678b22). Author-side drills: clean PASS; A-copy
corruption auto-repaired from B; same-line-both-copies refused
(splitab:10). User flow worked first try: export canvas ->
sh chunkcheck.sh <canvas> <workdir> -> "chunks ok: 6,
auto-repaired: 0" + PASS tool md5 96ffc7cf. User got sh:cannot
open chunkcheck.sh (verifier ships INSIDE the canvas, copy out
or reuse the R1032 copy - same 812a4646 post-fix) and one
harmless "@@B: not found" (canvas sh'd as shell - noise, PASS
is the authority). Splice output byte-matched the rehearsal
exactly; preflight GREEN, census 955, 7 R1033 bad-0 lines,
0 warnings, no compile-gate catches this round.

VERIFIED (codeload at 5499a2e9): tool md5 96ffc7cf, census
955, 9 lua files, all 5 rewritten/new C++ files + 9 lua
byte-identical to the deterministic author-side regeneration
from pristine 9927c6f8 (fresh apply after env reset).

STATE: R1033 LANDED (main 5499a2e9, census 955). The water
encounter family (underwater + waterborne + dino subtable) is
registry-native. REMAINING from the deferred set: the R63
outdoor/wilderness tables (8 climate tables + 11 terrain
subtables + tropical Sphinx, dm/encounters.cpp ~lines 1314+,
kOut* arrays, rollOutdoorEncounter) - the natural R1034.
Next work awaits Curtiss's GO.

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
