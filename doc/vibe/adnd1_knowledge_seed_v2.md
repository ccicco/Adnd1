---
name: adnd1-delivery
description: How Adnd1 splice rounds reach Termux - the delivery format, the run ritual with md5 gates, and the hard-won lessons (R34-R314 era; the underwater seam era is open)
---

# Adnd1 delivery protocol (current practice, R314 era)

Rebuilt at the R312 fresh start (v2). The full pre-restart
history (rounds R172-R312 verbose, every lesson in context) is
backed up in the repo at doc/vibe/adnd1_knowledge_backup_v2.md
(public: readable via the raw URL or the GitHub connector) -
reference it on demand, never load it wholesale. Rounds before
R172 were already dropped at the R171b/R172 era cut; git
(ccicco/Adnd1, main) carries every commit.

## Delivery format

- The splice is delivered as a code canvas (e.g. the r312-splice
  canvas). The user opens it, selects all, copies, and pastes ONCE
  into nano: `nano tools/rNNN_splice.py`. The paste itself happens
  on the Termux side BEFORE the ritual; NEVER write the paste step
  as a ritual command (bit three times), and keep all paths
  repo-root relative ./tools/...
- Paste capacity is user-VERIFIED (R312 era): nano takes huge
  pastes fine (a 1 MB paste proven); CAT is what chokes. NEVER
  deliver repo files via cat heredoc on Termux - the old
  chunked-heredoc format is dead; canvas + one nano paste
  scales to any size.
- The ritual is delivered as ONE code block with expected values
  as inline # comments, AFTER the canvas reference (order
  matters):

  md5sum ./tools/rNNN_splice.py      # advisory (the paste drifts)
  python3 -m py_compile ./tools/rNNN_splice.py && echo COMPILE-OK
  python3 ./tools/rNNN_splice.py     # expect: ALL OK (applied N, already 0)
  python3 ./tools/rNNN_splice.py     # expect: ALL OK (applied 0, already N)
  md5sum rules/<created file>        # THE REAL GATE (when a file is created)
  ./tools/preflight.sh               # expect GREEN + new audits bad 0 + AUDIT CENSUS: N
  git add -A && git commit -m "RNNN: ..." && git push

- The pasted splice md5 always drifts (nano artifacts); the splice
  writes all created content programmatically with chr(10), so the
  created files are byte-exact. The REAL gates are: py_compile,
  the applied/already counts, the created-file md5, and preflight.
- The repo is PUBLIC: the assistant reads the land via raw
  URLs (web open) or the codeload tarball - the Termux
  tarball ritual is not the only way to read it (R174).

## Recovery ritual (re-running a FIXED splice after a bad land)

- FIRST rm the created file: the idempotence marker makes a broken
  file report "already" and stay broken. Then expect
  "applied 1, already N-1" on rerun.

## Acid-test checklist (before delivering any splice)

- Fresh tarball md5 must match HEAD before work (codeload:
  https://codeload.github.com/ccicco/Adnd1/tar.gz/<sha>).
- Idempotent (marker-based); assert after EVERY patch (the R142
  lesson); the tail ALWAYS prints; ZERO literal backslash bytes
  (BS = chr(92) only on printf continuation lines); no apostrophe
  inside single-quoted content strings (Q = chr(39)).
- Line bounds: 78 the created header, 76 regtest, 57 the gap
  report.
- Markers: a marker must be unique to the NEW text and ABSENT from
  the PRE-patch file (R178c), and for created headers a ZERO-PARAM
  accessor line (R311 - a parametered first choice never matched
  the already path), and a SINGLE-LINE fragment of the header
  comment - a marker wrapping across comment lines fails the
  create-if-absent assert (R217).
- Apply twice on a fresh tree (applied N / already 0, then 0 / N);
  a second virgin tree + splice must be byte-identical (diff -r).
- Every static audit array: declared size == initializer count AND
  every initializer line comma-terminated (R171b + R172).
- R207c (THE gate): run `python3 tools/audit_eval.py RNNNa` and
  demand "verified bad 0" - not UNVERIFIED - before delivery
  (YELLOW = RED). New seams are written in the grenade.h evaluable
  subset (constants, ternaries, clamp chains, tables, 1D arrays,
  locals, cross-calls, C-truncation division, early returns;
  no structs/engine objects). audit_eval loads all rules/*.h, so
  cross-header calls resolve.
- ENUM COLLISIONS: audit_eval keeps ONE global enum table across
  ALL rules/*.h - a new enum prefix can silently overwrite
  another header's count (the SM_ scroll prefix collided with
  siegefire.h) - grep rules/*.h for any new enum prefix BEFORE
  landing it (scroll materials are now SCM_).
- Table rounds: the band-contiguity loop (lo[i] == hi[i-1] +
  1) is mandatory, and DERIVE the header arrays from the
  ground-truth parse programmatically and diff them against the
  splice arrays (the R241 DERIVED-CHECK) - never trust
  hand-typed cells, even after a clean parse.
- Engine audits: replica-walk every seeded scenario in Python
  FIRST (the R304 discipline) and only then write the expected
  values. The canonical replica code (the seeded xorshift64*
  rng with rejection sampling) lives IN THE REPO - every
  engine-round splice carries it; tools/r312_splice.py is the
  freshest copy (the class with nxt/below/rrange). ENGINE IDIOM
  (R192b): rules::Dice wraps a rules::Rng& and the RNG OWNS
  THE SEED - rules::Rng r(seed); rules::Dice d(r); with
  separate Rng locals per independent roll.
  simulate EVERY accessor the audit probes, including patched
  engine functions (R181); pre-assert every roster index the audit
  probes (R182); copy every engine identifier character-for-
  character from the actual header, never comments or memory
  (R180b); audit blocks are located by printf("LABEL audit: bad
  and land between the prior round tail and the next head comment.
- Census: assert the exact 'audit: bad' count before and after
  (N -> N+1 per printf added); census line exactly once.
- Brace/paren delta symmetric on every touched .cpp/.h.
- Mutation test RED->GREEN on both sides (header value + audit
  expected) before delivery.
- THE INCLUDE-CHAIN RULE (R312b, third bite): every rules::
  accessor a new TU calls needs its header IN that TU - grep the
  include chain for each called accessor, never assume
  transitivity (appstate.h does NOT carry the rules/ headers).
- Preflight RED with ONE compile error and a wall of CENSUS FAILs
  downstream = fix the compile, not the census (R179b/R180b/R227/
  R312b). Engine-round preflight RED needs an rNNNb fix splice
  BEFORE any push; both splices land in ONE commit.
- No C++ compiler in the assistant sandbox: the compile proof is
  the Termux preflight itself; eyeball every generated C++ span.
- /tmp is wiped between turns and the splice working copy can be
  wiped by turn-start re-downloads: canvases are the durable
  copies (recover the body with tail -n +7 CANVAS.md). Deliver
  canvases by building in /tmp and copying ONCE, then verify the
  md5 across separate tool calls (the R310 guard revert;
  chunked-edit fallback if it bites).

## Current state (the seam era)

- R311 landed: rules/underwater.h - the DMG UNDERWATER
  ADVENTURES pins (surface swim, movement, vision, combat) as
  data; the spell lists ride R168 (rules/uwspells.h).
- R312 + R312b landed 2026-10-10: commit 8661437, census 237,
  THE FLOODED CROSSING - the first ENGINE SITE the underwater
  pins charge: rules/swimcross.h (the seam: swimArmorSwims 0/1/2
  swim with studded leather reading METAL, the JUDGMENT;
  swimMagicArmorSwims the dog paddle; swimCanSwim plus > 0 dog
  paddles; swimLoadBeyondArmorLbs 1 lb = 10 g.p. with the worn
  armor excluded; the one-roll-per-crossing, one-pool-per-delve
  and 2-3-side pool JUDGMENTS); world/map.h TILE_WATER = 5
  (walkable); placeFlood (a 2-3 x 2-3 ALL-FLOOR sheet clear of
  the stairs and the entry, guard 500, draw order x,y,w,h FIXED)
  called in newDungeon AFTER placeLockedDoors; enterWater (the
  first living member failing the gate blocks with the bump
  convention - turn, log, wanderCheck -> spawn; success logs the
  plunge and each living swimmer rolls below(100) against
  uwSurfaceDrownPct); adnd1.cpp gates dry-land -> water only and
  paints the water brush. Audits R312a (seam) + R312 (engine,
  seven replica-walked seeds).
- The dmg gap report (tools/dmg_gap_report.md) holds ZERO open
  items; the PHB arc is complete; every round appends its
  chronicle paragraph to that report (no box flips pending).
- The R298-R312 seam era pattern: pin the print as an evaluable
  rules/ header (grenade.h subset), wire the ENGINE SITE in
  state_dungeon.cpp (the R304 locked-door precedent: placement
  guard loop + bump convention + wanderer ride), audit twice
  (RNNNa seam for audit_eval, RNN engine on replica-walked
  seeds), census +1 per audit.
- STANDING SCOPE (user, 2026-10-05): more classes later from
  Dragon Magazine, Unearthed Arcana (cavalier, barbarian,
  thief-acrobat), campaigns, box sets - the class registry stays
  data-driven (append a row, not a re-carve); when a sourcebook
  arc opens, it gets its own gap report against the same engine
  conventions.
- R313 landed 2026-10-10: commit e6751ff, census 239, THE
  UNDERWATER FIGHT (every chargeable open thread at once):
  rules/uwfight.h (the seam - uwCrossCapLbs the R311 20-lb cap
  fed by the R153 strWeightAllowGp ladder, un-caller-fed;
  uwCrossLoadBars; uwStrikeAllowed thrusting-only;
  uwMissileBarred total - no special crossbow pinned) wired at
  the R312 crossing: the enterWater load gate (a living member
  past the strength-fed cap bars the company, the bump
  convention; the JUDGMENT - the surface paragraph carries no
  load bar, the movement paragraph folds onto the crossing);
  the water fight (ai/actor setWaterFight + the public
  waterStrikeAllowed probe - the crushing and cleaving swings
  fail; the bare fists, the monk open hand and the monsters
  outside the gate); the combatShoot/combatThrow bars in the
  pool. NOT charged (recorded in the seam header): the vision
  decay (no engine vision layer), the breathing aids (recorded
  notes, no print pin), the aquatic first strike and nets (no
  aquatic monster roster). Audits R313a (seam, audit_eval
  verified bad 0, 105 asserts) + R313 (engine, replica-walked
  seeds).
- R314 landed 2026-10-10: commit cabfcd8, census 241, THE
  DEEP CROSSBOW, THE AQUATIC FIRST STRIKE AND THE
  WATERBORNE WANDERERS (one splice): items WPN_CROSSBOW_DEEP (fights
  as the light crossbow - the p.38 AC row; half the range, 3
  tens of feet; ten times the price, 120 g.p.; the R311
  data) and the R313 missile bar lifted for it alone
  (combatShoot, the uwDeepCrossbowAllowed fold; the throw
  stays barred); the aquatic first strike folded at
  actor.cpp stepRound (the waterborne monsters floor at
  segment 1, the company earliest at 2 - the
  significantly-longer weapon exception reads data, no
  reach layer exists; the JUDGMENT: no roster is pinned,
  aquatic means the encounter arrived via the waterborne
  table); the waterborne wanderers at the flood pool (the
  R127 fresh shallow cool table, the state_sea precedent;
  the count rides the registry noAppearing; the aquatic
  flag rides the encounter). The net throw prose stays
  data (no net item is pinned). Audits R314a (seam,
  audit_eval verified bad 0) + R314 (engine,
  replica-walked seeds).
- Open threads: the vision decay seam (needs an engine vision
  layer first), a breathing mechanic (needs a print pin), the
  net throw prose (needs a net item), or any fresh seam /
  sourcebook gap report - next round is user choice.

## Round state (update each land)

- R312 + R312b landed 2026-10-10: commit 8661437, census 237
  (the flooded crossing - see Current state above).
- R313 landed 2026-10-10: commit e6751ff, census 239, the
  underwater fight (see Current state above). GREEN on the
  FIRST preflight (no b-round). Lessons: (1) the include-chain
  grep earned its keep AGAIN pre-delivery - state_dungeon.cpp
  called the uwfight accessors with no include (the R312b bite
  class, caught in the sandbox, not by preflight); (2) splice
  patch COUNT asserts must track the lettered patches (a patch
  g assert read 8 with 7 landed - count the letters, not the
  goal); (3) post-patch chronicle asserts must quote the line
  AS WRAPPED (the 57-col gap report wraps mid-phrase - assert
  a wrapped fragment, never the unwrapped sentence); (4) an
  actor.h anchor line with an apostrophe in a comment (the 10'
  bands line) cannot serve an apostrophe-free content block -
  pick another anchor (the R175 apostrophe rule cuts both
  ways).
- R314 landed 2026-10-10: commit cabfcd8, census 241, the
  deep crossbow and the aquatic wanderers (see Current
  state above). GREEN on the FIRST preflight (no b-round).
  Lessons: (1) the seam survey must GREP FOR THE PIN NAME
  FIRST - the R311 header already pinned
  uwAquaticFirstStrike, and the R314 seam reuses the
  existing pin instead of redefining it (a redefinition
  would shadow the data pin and break the R311 audit);
  (2) the wrapped-fragment lesson rides EVERY gap-report
  assert (the R314 census assert read the unwrapped
  phrase and failed in the sandbox - assert what the
  57-col wrap actually printed).
- R315 landed 2026-10-10: commit 7c3801b, census
  242, the net throwers of the waterborne table
  (see Current state above). GREEN on the FIRST
  preflight (no follow-up). Lessons: (1) PREFLIGHT
  RIDES EVERY SPLICE - a seed or doc splice is not
  exempt (the R314 convention note was wrong); (2)
  ONE SPLICE PER ROUND - the seed round-state entry
  rides the NEXT round splice as a patch (the entry
  names the landed code commit, so it lands after
  it); the letter suffix is ONLY for errors or bugs
  (r312b the precedent - the R313/R314 seed rounds
  broke the shape); (3) the MM arms rows read the
  Lua roster - grep the monster text before any
  fold; (4) no new pins - the R311 uwNet data
  charged via the R37 monster-missile pattern.
- R316 landed 2026-10-10 (the r316b fix,
  commit 9021b2c), census 243, the
  underwater vision seam (see Current state
  above). RED then GREEN: the sight print
  displaced the R314 W1 line and the older
  audit broke on its get(0); the r316b
  window scan fixed it. Lessons: (1) a NEW
  PRINT RIDES THE SHARED LOG - older audits
  assert the LOG WINDOW, not the head (the
  W1 scan is the pattern); (2) the sandbox
  cannot build the C++ - the Termux
  preflight is the ONLY gate that catches
  print interactions; (3) the naming held -
  the round record and the bug fix both
  committed, initial splices are never
  deleted; (4) the survey kills before the
  fold - no STATUS_LIGHT, no named pack
  items, no depth notion (the light/helm
  multiples and the decay stay recorded).

- R317 landed 2026-10-10: commit f98caa7,
  census 244, the infravision fold (see
  Current state above). GREEN on the FIRST
  preflight. Lessons: (1) the survey kill-
  list discipline paid - no STATUS_LIGHT,
  no named pack items, no depth notion,
  so the fold charged only the pins that
  existed (uwInfravisionSameAsDungeon meets
  raceInfravisionFeet); (2) no new state -
  the print rode the R316 site; the round
  stayed small because the data was
  already pinned and regtested.

- R318 landed 2026-10-10: commit 70216d6,
  census 245, the net entrap layer (see
  Current state above). RED then GREEN:
  the preflight caught bad 1 - the N3
  hold check. Lessons: (1) read the
  ENGINE CODE, not the comment - the
  tickStatus prose says permanent, the
  code kills the zero-round mark at the
  round-end tick, so the entrap
  evaporated and the r318b fix re-asserts
  the hooks each round (only the tear
  frees); (2) the round-end status tick
  is the interaction the sandbox cannot
  trace - the preflight stays the only
  gate that catches tick lifetimes; (3)
  the letter rule held - the initial
  splice committed alongside the fix,
  history intact; (4) the fix splice kept
  the audit as the gate and added a
  second-round regression check (the
  hold must survive two ticks).

- R319 landed 2026-10-10: commit
  c98c923, census 246, the underwater
  vision multiples (see Current state
  above). RED then GREEN: the build
  caught the W2/W3 audit calls -
  resolveCast sat private. Lessons: (1)
  a public seam needs a PUBLIC
  declaration - the partyMutable comment
  promised cast access, the declaration
  never moved (the r319b fix); (2) the
  sandbox has no compiler - a C++
  visibility error can only surface at
  the Termux build, and the census
  cascade (every audit appears 0 times)
  means the build died before the
  battery ran; (3) the light rows save
  not, so the W scenarios stayed draw-
  independent through the fix; (4) the
  latent kStatusNames shortfall (10
  names for 14 kinds) was found and
  fixed by the survey, before it bit.

- R320 landed 2026-10-10: commit
  94ca1df, census 247, the breathing
  aids (the druid spell and the potion
  claim). GREEN on the first paste.
  Lessons: (1) an idempotency guard
  must test the exact inserted text -
  two R320 guards matched text that
  never exists in the patched source
  (a row with a trailing comma vs the
  bare row; a contiguous phrase vs
  the split string literal), both
  caught by the sandbox double-run
  before delivery; (2) a source scan
  must match the literal split - the
  print rode two string literals, so
  the check scans the shared half;
  (3) a pointer compare against a
  string literal warns (-Wstring-
  compare) - the later audits compare
  through std::string.

- R321 landed 2026-10-11: commit
  cd6dc78, census 248, the
  aerial chapter (the OUT
  reversal; the pp.49-53 pins,
  the fly seams). GREEN on the
  first paste. Lessons: (1) a
  count-assert must not match
  its own inserted comment
  text - four R321 asserts
  counted phrases their own
  comments carried (the
  double-run caught all four
  before delivery); (2) verify
  a pre-existing count before
  pinning it (the pockets-the
  route had a third print
  already); (3) the UA arc
  opens R322 - the upload is
  the source of truth, and
  its OCR-mangled tables stay
  recorded until the book
  text arrives.

- R322 landed 2026-10-11: commit
  f83e11b, census 249, the UA arc
  opener: the comeliness pins
  (rules/comeliness.h) and the
  lossless ua gap report
  (tools/ua_gap_report.md) with the
  DEFERRED ontology (OUT nearly
  empty by design), the
  deferred-seams dependency graph,
  the playability closure criterion,
  the switchable treasure decision.
  GREEN on the second paste.
  Lessons: (1) a ritual block must
  be paste-safe - prose annotations
  in a shell block run as commands;
  the first paste executed nothing
  but noise and the splice never
  ran (preflight RED caught it
  before any git damage); (2) a
  pasted splice can hash off by a
  trailing newline (the nano save)
  - wc -c against the recorded
  byte count confirms the case, and
  the internal asserts plus the
  double-run are the content proof;
  (3) the OUT/DEFERRED axis lesson:
  the survey axis (can the engine
  hold it today) is not the intent
  axis (is it wanted, ever) -
  DEFERRED is the default resting
  state under the everything-and-
  the-kitchen-sink mission.

- R323 landed 2026-10-11: commit
  fe259f1, census 250, the UA
  subrace layer (rules/subraces.h):
  the CharSubRace and UaClass
  enums, Race Table I with the
  alignment column, the 17x17
  preferences matrix (verified
  cell by cell against the print),
  the SubRaceTraits records, the
  duergar/drow/svirfneblin reads.
  GREEN on the third paste (two
  fix rounds).
  Lessons: (1) the compile gate is
  the only proof of a seam - the
  v1 splice landed clean on every
  static check and still collided:
  SUB_COUNT already named a
  Subclass enum member in
  subclasses.h, so the compiler
  bound the traits table to their
  count (6) and the build RED-cascaded
  the whole census; the fix is the
  rename (SUBRACE_COUNT), and the
  audit at authoring time is now
  collision-first: grep every new
  identifier against every header
  in the regtest TU before
  authoring, then let the compile
  arbitrate; (2) an unpushed commit
  amends (git commit --amend
  --no-edit) - a fix round folds
  into the single round commit, no
  fix-commit history noise; (3) a
  fix splice takes the next letter
  (r323b) and self-identifies in
  its output; the md5 alone is a
  weak signal when the paste drifts
  a trailing newline.
- R324 landed 2026-10-11: commit
  a7a6a5c, census 251, the UA
  Character Race Table II
  (rules/subracelevels.h): the six
  sub-tables (II.A dwarves, II.B
  gnomes, II.C elves both printed
  blocks, II.D half-elves, II.E
  halflings, II.F half-orcs), the 47
  columns keyed by the vital ability
  (score*1000; the exceptional
  strength ladder 18/01-18/00 as
  18010-18999 with 18/00 at 18999),
  the dark-elf sex split, the U
  reads, the footnoted ability gates
  with the OR footnote, the
  escalation riders, the floor rule,
  the +2 single-class rule. GREEN on
  the second paste (one fix round,
  r324b, folded by amend).
  Lessons: (1) the oracle must read
  back out of the GENERATED header
  text, not the intent - the
  build-time simulation carried the
  wild elf in the elf gates block
  while the generated C++ omitted
  SUB_ELF_WILD; the double-entry
  check verified audit-vs-model,
  never model-vs-header, so the
  preflight read bad 2 and the
  if-bad-return bail-out cascaded
  the census (every audit after the
  block read CENSUS FAIL); the
  replay discipline (port the landed
  C++ literally into Python, replay
  the audit mechanically) found the
  2 fails exactly; (2) preflight is
  a pre-commit gate - run it before
  the git add; a post-amend run
  reads hygiene RED on a clean tree
  (untracked splice files with no
  modified tracked file is the
  never-ran shape, and the amend
  leaves exactly that); (3) the
  paste md5 drifts only the trailing
  newline (nano); the splice asserts
  are the tripwire.
- R325 landed 2026-10-11: commit
  2592126, census 252, the UA
  Race Table II caller round
  (rules/subracecap.h): the
  uaLevelCap fold at the gainXp
  queue and the trainer, the
  uaSubrace field with its save
  line, the +2 single-class rule
  against the R185 combo layer.
  GREEN on the second paste (one
  fix round, r325b, folded by
  amend): the U6 live walks
  passed st.rng (a rules::Rng)
  where gainXp and trainNext take
  a rules::Dice reference - the
  AppState dice{rng} member is
  the bridge (reseeding rides
  the reference). Lessons: (1)
  the oracle must type-check
  CALL SIGNATURES against the
  landed headers, not just
  identifier names - the r324b
  case-gap twin; (2) a failed
  build cascades the whole
  census (the battery never
  runs) - read the FIRST error,
  not the census.
- R326 landed 2026-10-11: commit
  e01935a, census 253, the UA
  creation round: the CR_SUBRACE
  picker stage (rows from
  subraceParentRace), the female
  field with its fem save line,
  makeMember wiring both fields,
  the dark-elf sex split live at
  the fold (the uaLevelCap female
  leg; the R325 audit compiles
  male on the default param).
  GREEN on the first paste. The
  oracle discipline held: the
  mechanical parse of the stacked
  case labels caught a hairfoot
  column misread before it hit
  C++, and the r325b signature
  check is why the old audit
  compiled unchanged.
- R327 landed 2026-10-11: commit
  47dce47, census 254, the UA
  Classes Tables I and II pin
  round (rules/classtables.h):
  the hit-die column, the
  two-dice first levels, the
  note-1 social-standing
  generators (3d4+1 or d10+3),
  the ranger 11-dice and monk
  18-dice maxima, the druid 23,
  the spell-ability legs, the
  Table II footnotes, the
  acrobat row. GREEN on the
  first paste. Lesson: the
  acrobat name reads needed
  strcmp, so regtest gained
  its cstring include - audit
  every new call signature
  against the landed includes
  before the paste.
- R328 landed 2026-10-11: commit
  e9b26eb, census 255, the UA
  cavalier pin round (rules/
  cavalier.h): the minima, the
  race gate, the weapons of
  choice, the parry and armor
  reads, the horsemanship
  ladder, the percentile
  growth, the saves and
  immunities, the chivalric
  code, the Table I clean
  cells (the 5/6/11/12 title
  holes stay open). GREEN on
  the first paste. Lesson:
  the four oracle fails were
  OCR needles (curly quotes,
  hyphenated breaks, scrambled
  grid text), not facts - fix
  needles against the extract,
  never the fact.
- R329 landed 2026-10-11: commit
  c128aec, census 256, the UA
  paladin re-parented under the
  cavalier pin round (rules/
  paladin.h): the re-parenting
  expressed as delegation - the
  minima and the 0-level track
  read the R328 cavalier pins,
  the lawful-good gate, the
  cavalier charge, the CHA
  percentile growth. GREEN on
  the first paste. Lesson: the
  ACID run itself caught an
  overcounted read-back assert
  (cavalierMinAbility appears
  twice - comment plus call);
  count asserts against actual
  file content, always.
- R330 landed 2026-10-11: commit
  76df31d, census 257, the UA
  druid hierophant ladder pin
  round (rules/hierophant.h): the
  hierarchy, the abdication, the
  Table I ladder, the spell
  abilities, the 16th-23rd
  powers, the plane and conjure
  ladders, the five conjuring
  tables; the earth 01-85 HD
  cell and the L21 title cell
  documented as OCR holes. GREEN
  on the first paste. Two
  lessons: a seam comment naming
  an identifier trips the
  not-in assert (reword the
  comment, not the assert); and
  the balance checker must strip
  comments before strings - the
  unpaired inch-mark quote in a
  comment swallowed real braces
  and faked an imbalance.
- R331 landed 2026-10-11: commit
  ae61566, census 258, the UA weapon
  specialization prose pin round
  (rules/weaponspec.h): the class gate,
  the slot costs, the melee and
  point-blank reads, the double, the
  table structure with the cleanly
  readable cells (the mangled fraction
  cells read empty - the item stays
  open pending the PDF). GREEN on the
  first paste. Two lessons carried:
  the balance checker must strip
  comments before strings (an unpaired
  inch-mark in a comment swallowed
  real braces); and a seam comment
  naming an identifier trips the
  not-in assert - reword the comment,
  not the assert.
- R332 landed 2026-10-11: commit
  b5380bd, census 259, the UA
  barbarian pin round
  (rules/barbarian.h): the
  requirements and the wisdom
  maximum, Barbarians Table I, the
  magic detestation (the award tail
  an OCR hole pinned as a bool), the
  strike ladder, the saves, the
  primary, secondary and tertiary
  ability ladders. GREEN on the
  first paste. No new lessons - the
  R330/R331 ones held (the
  comments-stripped-first balance
  checker, the seam-comment naming).
- R333 landed 2026-10-11: commit
  458c831, census 260, the UA
  ranger expansion pin round
  (rules/uaranger.h): the tracking
  base and terrain ladders, the
  indoor reads, the identification
  ladder, the giant-class roster
  expansion 11 -> 22 (gnoll decoded
  from the garbled cell); the spell
  progression closed via the landed
  R327/R184 seams (the UA prose is
  OCR-lost). GREEN on the first
  paste. No new lessons.
- R334 landed 2026-10-11: commit
  a22d9a1, census 261, the UA
  Thieves Table II pin round
  (rules/thiefarmor.h): the armor
  categories, the eight functions,
  the verified cells and holes, the
  footnotes; the paired attacks
  table - the five classes, the band
  edges, the verified rates. GREEN
  on the first paste. No new
  lessons; the item stays open
  pending the PDF read.
- R335 landed 2026-10-11: commit
  ef84109, census 262, the UA
  thief-acrobat pin round
  (rules/acrobat.h): the split class
  at 6th, Table I, the Function
  Table columns (the tumbling
  attack and evasion ladders
  cell-by-cell, the falling column
  where OCR survives), the
  tightrope walk, the vault and
  jump bands, the footnotes, the
  Table III dex bonuses. GREEN on
  the first paste. No new lessons.
- R336 landed 2026-10-11: commit
  74ebf6a, census 263, the UA
  cavalier money pin round
  (rules/cavmoney.h): the six
  stations in social-ladder
  order, the gold ranges, the
  printed formulas verified
  times-ten against the printed
  ranges and the R190 seam, the
  equipment lists item-by-item
  as printed, the tack and
  esquire prose; the paladin
  exception noted, not
  detailed. GREEN on the first
  paste. No new lessons.
- R337 landed 2026-10-11: commit
  924e41d, census 264, the UA
  weight and damage pin round
  (rules/uaweapontable.h): the
  67-row roster, all 50 PHB rows
  cell-verified against the R189
  seam (the hyphen-loss pattern
  proven row by row), the 17
  new-weapon rows pinned where
  printed or pattern-decoded.
  GREEN on the first paste.
  Lesson: the array-template
  generator emitted a duplicate
  const on the char* name row (a
  benign -Wduplicate-decl-specifier
  warning); fixed in R338.
- R338 landed 2026-10-11: commit
  1775600, census 265, the UA
  missile data pin round
  (rules/uamissile.h): the 24-row
  roster, the range column decoded
  as the long range in tens of feet
  (PHB-seam verified), the
  AC-adjustment ladders minus-loss
  decoded (the pattern seam-proven
  against the R145 rows); the
  R337b duplicate-const fix rode.
  GREEN on the first paste. No new
  lessons.
- R339 landed 2026-10-11: commit
  a701ba9, census 266, the UA
  proficiency pin round
  (rules/uaprof.h): the 14-row
  roster, seven rows cell-verified
  against the R297 PHB seam, the
  attributed fragment rows
  (illusionist, thief, assassin), the
  paladin and ranger deviations
  pinned as printed; the item
  closed. GREEN on the first paste.
  No new lessons.
- R340 landed 2026-10-11: commit
  1288a5c, census 267, the UA new
  weapons prose pin round
  (rules/uanewweapons.h): the 16
  printed descriptions, every
  readable number pinned, the
  khopesh slash-loss and whip 3d6
  decodes documented; the item
  stayed open (the DM pp. 77-79
  half). GREEN on the first paste.
  No new lessons.
- R341 landed 2026-10-11: commit
  d619290, census 268, the UA spell
  tables pin round, part 1
  (rules/uaspelltables.h): the
  cleric 1st-3rd table (20 rows,
  seam-verified against the R80
  registry), the cleric 4th-7th
  fragments, the druid tables (the
  readable rows seam-decoded as the
  1st-level roster) and the MU
  cantrip table (64 names); the MU
  spells tables and the illusionist
  table stayed OCR-scrambled -
  part 2 next. GREEN on the first
  paste. No new lessons.
- R342 landed 2026-10-11: commit
  3bba003, census 269, the UA
  spell tables pin round,
  part 2
  (rules/uaspelltables2.h):
  the MU 1st-5th columns
  (35/30/28/28/28 readable
  names, every garble
  position-decoded), the MU
  7th-9th continued table and
  the illusionist table; the
  6th column and the fragment
  cells are OCR holes - noted
  pending the PDF; the item
  closed. Lesson: the user
  paste's md5 drifted (nano
  whitespace) yet every gate
  passed - the idempotent
  double-run plus the census
  are the real fingerprint;
  md5 stays a convenience
  check. GREEN on the first
  paste.
- R343 landed 2026-10-11: commit
  46c65dc, census 270, the UA
  new cleric spells pin round,
  the 1st level
  (rules/uaclericspells1.h):
  ceremony (the ten varieties and
  the Sth-cell decodes), combine,
  endure cold/heat, penetrate
  disguise, invisibility to
  undead, portent (the 1d12/1d6
  mechanics), magic stone and
  precipitation; the digit-garble
  family decodes the four
  "Level: 7" cells as 1; the R341
  table hole at row 13 decodes as
  portent. The md5 drifts are
  benign paste whitespace - the
  double-run, the census and the
  preflight gates are the real
  fingerprint; GREEN on the first
  paste.
- R344 landed 2026-10-11: commit
  7734ea9, census 271, the UA
  new cleric spells pin round,
  the 2nd level
  (rules/uaclericspells2.h):
  aid, detect life, dust devil,
  enthrall, holy symbol,
  messenger, withdraw and
  wyvern watch; the digit-garble
  family decodes the five 7s as
  1; the R341 table hole at row
  18 decodes as withdraw. A
  nano-wrapped paste corrupted
  the splice and a prompt-
  prefixed runbook fed bash the
  prompts - both cost a reset.
  Lesson pinned: the save is
  cat > + Ctrl-D and the runbook
  carries bare commands; the
  py_compile/awk/tail pre-check
  gate runs before the first
  splice. GREEN after the reset.
- R345 landed 2026-10-11: commit
  9988376, census 272, the UA
  new cleric spells pin round,
  the 3rd level
  (rules/uaclericspells3.h):
  cloudburst, death's door,
  flame walk, magical vestment,
  meld into stone, negative
  plane protection, remove
  paralysis and water walk; the
  digit-garble family decodes
  the six 7s as 1 (two
  corroborated in-round); the
  R341 3rd-level column is
  fully readable - no hole
  decode. The paste survived a
  nano wrap this round, but
  cat > + Ctrl-D stays the
  pinned save method; GREEN on
  the first run.
- R346 landed 2026-10-11: commit
  942031f, census 273, the UA
  new cleric spells pin round,
  the 4th level
  (rules/uaclericspells4.h):
  abjure with the implore
  reverse, cloak of fear with
  the bravery reverse, giant
  insect with the count and
  hit-dice ladders and the wasp
  examples, imbue with spell
  ability, spell immunity and
  spike growth; the digit-garble
  family decodes the five 7s as
  1 (the cloak duration
  corroborated by its clean
  prose; the spike growth
  casting and duration decodes
  stay verbatim with doubt); the
  R341 continued table prints
  only fragments for the 4th
  level - the six names pin
  from the prose; the abjure
  range and spike growth Level
  cells are OCR holes - noted
  pending the PDF; a
  housekeeping commit (edb35d6)
  landed the eight R322-R327
  splice scripts; GREEN on the
  first run.
- R347 landed 2026-10-11: commit
  ed961b6, census 274, the UA
  new cleric spells pin round,
  the 5th level
  (rules/uaclericspells5.h):
  air walk with the ascent and
  descent ladder and the gust
  interplay, animate dead
  monsters, golem with the four
  material ladders, magic font
  with the vial capacity rule,
  rainbow with the four
  applications and the seven
  colors and draughts, and spike
  stones (the prose prints in
  the cleric chapter - the druid
  item seam-checks against this
  pin); the digit-garble family
  decodes the three stat-cell
  7s as 1; the rainbow
  7-missiles and the golem
  7-foot ceiling stay genuine;
  the R341 table prints seven
  fragments - magic font
  seam-checks; the animate dead
  monsters and rainbow Range
  cells and the straw golem SD
  decode are OCR holes - noted
  pending the PDF; GREEN on the
  first run.
- R348 landed 2026-10-11: commit
  f9e1522, census 275, the UA
  new cleric spells pin round,
  the 6th level
  (rules/uaclericspells6.h):
  forbiddance (the name header
  never prints - identified by
  the near-verbatim 2e
  descendant text; the ethics
  and morals entry ladder with
  the password gate) and heroes
  feast (the twelve-hour
  benefits and the one-hour
  consume rule); the
  digit-garble family decodes
  the two 7s as 1 (both
  corroborated); the
  forbiddance 6s stay genuine;
  the R341 table prints four
  fragments - neither name
  seam-checks; GREEN on the
  first run.
- R349 landed 2026-10-11: commit
  ba3dc04, census 276, the UA
  new cleric 7th level spells pin
  round (rules/uaclericspells7.h):
  exaction (the alignment gates
  and the bargain consequences)
  and succor (the prepared-object
  dweomer with the summons
  reverse); the family decodes
  the two 7s as 1; the item
  CLOSED - all seven levels
  pinned (R343-R349); the
  new-cleric-spells gap item
  checked off. Lesson: the user
  built the splice in nano (not
  the cat paste); the md5
  drifted (whitespace) yet
  py_compile, the width profile,
  the double-run and the census
  all passed - the gates stay
  the fingerprint, md5 a
  convenience. GREEN on the
  first run.
- R350 landed 2026-10-11: commit
  037cdf6, census 277, the UA
  new druid 1st level spells pin
  round (rules/uadruidspells1.h):
  ceremony (the nine varieties
  with the cast-out permission
  ladder), detect balance, detect
  poison and precipitation (the
  name header lost - identified
  via the R343 clerical pin); the
  family decodes the three 7s as
  1; the druid ladder opens. The
  ritual block is gates-only now
  (the file creation is the
  user-side step, done in nano).
  Lesson: the second nano md5
  drift with all gates green -
  the double-run plus the census
  stay the fingerprint. GREEN on
  the first run.
- R351 landed 2026-10-11: commit
  4f47d8a, census 278, the UA
  new druid 2nd level spells pin
  round (rules/uadruidspells2.h):
  flame blade (the undead and
  fire damage modifiers), the
  goodberry reverse (the name
  header lost), the reflecting
  pool behind the "Pool ion -"
  name garble (the scrying
  mechanics with the
  cast-through ladder) and slow
  poison (the herbal antidote
  chance); the family decodes
  the three 7s as 1; the ritual
  block dropped the invented
  git pull and the paste step -
  gates and landing only. GREEN
  on the first run.
- R352 landed 2026-10-11: commit
  849d516, census 279, the UA
  new druid 3rd level spells pin
  round (rules/uadruidspells3.h):
  cloudburst (the stat-block
  interleave decoded with the
  call lightning exclusion),
  know alignment (the
  five-creature cap, not
  reversible), spike growth (the
  material interleave with the
  seven twigs) and starshine (the
  school tail lost; seam-checks
  the R351 reflecting pool pin);
  the UA prints no 4th-level
  druid section. Lesson: the gap
  note tail line now ends two
  prior notes - the insert
  anchors on the two-line tail
  (note end plus the next item)
  or it would double-insert;
  the ACID assert caught it.
  GREEN on the first run.
- R353 landed 2026-10-11: commit
  cef4de6, census 280, the UA
  new druid 5th level spells pin
  round (rules/uadruidspells5.h):
  moonbeam (the movable spotlight
  beam with the color and vision
  effects) and spike stones
  (identical to the clerical); the
  spike stones stat cells
  seam-check the R347 clerical pin
  exactly - but the school cell
  prints Enhancement where the
  clerical reads Enchantment
  (flagged pending the PDF); the
  casting time cell lost. GREEN on
  the first run.
- R354 landed 2026-10-11: commit
  ae75dd2, census 281, the UA
  new druid 6th level spells pin
  round (rules/uadruidspells6.h):
  liveoak (the triggered treant
  with the 3-inch movement
  interleave decode) and water
  to dust (the name garble, the
  muddy multipliers and the
  water-native save gate); the
  family decodes the 7 turn as
  1. Lesson: the R354 splice
  dropped the leading blank
  entry line, merging the R352
  seed tail with the R353
  record on one line - this
  round repairs the merge; the
  entry list must open with a
  blank element. GREEN on the
  first run.
- R355 landed 2026-10-11: commit
  a70626d, census 282, the UA
  new druid 7th level spells pin
  round (rules/uadruidspells7.h):
  changestaff (the lost name
  header, the hit-die ladder with
  the wish-only recovery) and
  sunray (the blindness tiers and
  the undead damage split); the
  family decodes the 7 round as
  1; the druid spells item
  CLOSED; the R354 seed merge
  repaired (the entry list must
  open with a blank element).
  GREEN on the first run.
- R356 landed 2026-10-11: commit
  79cb0ce, census 283, the UA
  new magic-user 1st level spells
  pin round (rules/uamuspells1.h):
  the ten spell descriptions
  (alarm, armor, firewater,
  grease, melt, mount,
  precipitation seam-checking
  the R343 clerical pin minus
  the holy symbol, run, taunt,
  wizard mark); the family
  decodes the seven 7s as 1;
  no 1st-level MU table seam
  exists. GREEN on the first
  run.
- R357 landed 2026-10-11: commit
  46924c5, census 284, the UA
  new magic-user 2nd level spells
  pin round (rules/uamuspells2.h):
  the twelve spell descriptions
  (bind, deeppockets behind the
  lost name header, flaming
  sphere, irritation, know
  alignment behind the lost range
  cell, the Melf acid arrow,
  preserve, protection from
  cantrips behind the From
  Cantrips header garble, the
  Tasha laughter, vocalize, whip
  behind the lost level cell,
  zephyr); the family decodes
  the 7s as 1; the R342 MU table
  seam prints eight of the twelve
  names, the four absent noted.
  GREEN on the first run.
- R358 landed 2026-10-11: commit
  8db9ec7, census 285, the UA
  new magic-user 3rd level spells
  pin round (rules/uamuspells3.h):
  the eight spell descriptions
  (cloudburst seam-checking the
  R352 druid pin minus the holy
  symbol with the 3 diam. print
  flagged against the druid 4,
  detect illusion behind the lost
  name tail, item, material
  behind the degree range, the
  Melf minute meteors, secret
  page behind the 4th-heading
  interleave, the sepia snake
  sigil, wind wall); the family
  decodes the 7s as 1; the R342
  MU table seam prints four of
  the eight names, the four
  absent noted. GREEN on the
  first run.
- R359 landed 2026-10-11: commit
  97e1ff2, census 286, the UA
  new magic-user 4th level spells
  pin round (rules/uamuspells4.h):
  the eight spell descriptions
  (dispel illusion behind the lost
  name tail and the garbled
  half-inch range, the Evard
  black tentacles behind the lost
  level and range cells with the
  stray gf line, the Leomund
  secure shelter with the
  scrambled wind sentence, magic
  mirror with the scrambled
  component list, the Otiluke
  resilient sphere with the lost
  globe sentence, shout with the
  scrambled area tail, stoneskin
  behind the lost level and range
  cells, ultravision with the tail
  past the 5th heading); the R342
  MU table seam prints seven of
  the eight names, the Dispel
  fragment cell reads as a hole;
  the 5th through 9th
  levels. GREEN on the first
  run.
- R360 landed 2026-10-11: commit
  47a3e4f plus the 997ef44 b
  follow-up, census 287, the
  UA new magic-user 5th and
  6th level spells pin round
  (rules/uamuspells5.h and
  rules/uamuspells6.h): the
  twelve spell descriptions
  (avoidance behind the lost
  name header, dismissal
  behind the belabourment
  interleave, dolor with the
  range as printed, fabricate,
  the Leomund belabourment
  behind the lost name header,
  sending; chain lightning
  behind the truncated range
  tail and the garbled save
  fraction, contingency
  behind the lost casting
  cells, ensnarement behind
  the lost name header,
  eyebite behind the garbled
  school tail, the Mordenkainen
  lucubration behind the lost
  name header, transmute water
  to dust seam-checking the
  druid pin minus the mistletoe
  with the 6-segment print
  flagged against the druid 8);
  the family decodes the
  casting and duration 7s as
  1 with the range 7s staying
  as printed; the R342 MU
  table seam prints four of
  the 5th-level names,
  avoidance and dolor absent,
  and the 6th-level column is
  wholly lost; the b follow-up
  repaired the split audit
  printf; GREEN on the first
  run.
- R361 landed 2026-10-11: commit
  5c52199, census 288, the UA
  new magic-user 7th level spells
  pin round (rules/uamuspells7.h):
  the eight spell descriptions
  (banishment behind the scrambled
  stat head with the range
  interleaved, forcecage with the
  stat tail interleaved, the
  Mordenkainen magnificent mansion
  behind the garbled name header,
  sequester behind the lost name
  header, teleport without error
  with the stat cells scrambled,
  torment with the save ladder,
  truename with the polymorph
  verse ladder, volley with the
  Explanation line lost, the last
  two printing past the 8th-level
  table page); the family decodes
  the casting and duration 7s as
  1; the R342 MU table seam
  prints only the seven PHB
  fragments, none of the new names
  seam-checks; GREEN on the first
  run.
- R362 landed 2026-10-11: commit
  f9ef2b6, census 289, the UA new
  magic-user 8th and 9th level
  spells pin round
  (rules/uamuspells8.h and
  rules/uamuspells9.h): the four
  8th-level descriptions (binding
  with the lost range and duration
  cells and the six forms with the
  save ladder, demand behind the
  garbled components cell, the
  Otiluke telekinetic sphere behind
  the garbled name header with the
  lost range cell, sink with the
  lost level cell and the sinking
  ladder) and the four 9th-level
  descriptions (crystalbrittle with
  the item save ladder, succor with
  the interleaved stat tail, energy
  drain with the displaced casting
  cell, the Mordenkainen disjunction
  behind the garbled name header
  with the artifact chances); the
  R342 MU table seam checks demand
  at index 0 and sink at index 8
  with binding and the sphere
  absent, and only the two PHB 9th
  names print; the item CLOSED -
  all printed levels pinned
  (R356-R361 plus this round); GREEN
  on the first run.
- R363 landed 2026-10-11: commit
  3737448, census 290, the UA new
  illusionist cantrips and 1st/2nd
  level spells pin round
  (rules/uailcantrips.h,
  rules/uailspells1.h and
  rules/uailspells2.h): the eight
  cantrip descriptions (colored
  lights with the globe ladder, dim,
  haze, mask, mirage, noise, rainbow
  and the two-d illusion the item
  list missed), the chromatic orb
  with the color-by-level ladder,
  phantom armor at the printed 1st,
  read magic, spook, alter self and
  fascinate plus the ultravision and
  wind reprints; the R342 IL table
  seam prints only PHB names in the
  readable columns; the delude and
  wraithform third-level divergence
  flagged pending the PDF; the item
  stays open - the 3rd through 7th
  levels pin later; GREEN on the
  first run.
- R364 landed 2026-10-11: commit
  141fbcb, census 291, the UA new
  illusionist 3rd/4th/5th level
  spells pin round
  (rules/uailspells3.h,
  rules/uailspells4.h and
  rules/uailspells5.h): delude
  and wraithform at the printed
  3rd, phantom steed and phantom
  wind pinned as the print adds
  them, dispel magic, rainbow
  pattern, solid fog and vacancy
  at 4th, the advanced illusion,
  dream, the magic mirror reprint
  and tempus fugit at 5th; the
  R342 IL table 3rd-6th columns
  stay lost; the item stays open
  - the 6th and 7th levels pin in
  the next round; GREEN on the
  first run.
- R365 landed 2026-10-12: commit
  d7bb603, census 292, the UA new
  illusionist 6th/7th levels,
  acquisition and cost pin round
  (rules/uailspells6.h,
  rules/uailspells7.h,
  rules/uailacquisition.h and
  rules/uaspellcost.h): death fog,
  mislead, phantasmagoria and the
  mirage arcane at the printed 6th
  (the item-list 7th divergence
  flagged pending the PDF), shadow
  walk and weird at 7th; the IL
  spells item CLOSED - all printed
  levels pinned R363-R365; the
  acquisition item stays open (the
  row boundaries garble); GREEN on
  the first run.
- R366 landed 2026-10-12: commit
  3e742b3, census 293, the UA
  DM-section spells pin round
  (rules/uaspellbooks.h,
  rules/uaspellcomment.h,
  rules/uauwspelluse.h and
  rules/uadarkness.h): the MU
  spell book rules (the
  capacities and costs, the
  physical aspects, the values,
  the direct-casting and
  learning reads), the spell
  explanations commentary (the
  permanency lists and the
  Serten's immunity with the
  band assignment flagged), the
  underwater spell use lists
  and the effects of darkness
  ladder - all four items
  CLOSED; GREEN on the first
  run.
- R367 landed 2026-10-12: commit
  6047766, census 294, the UA
  campaign social class and birth
  pin round (rules/uasocialclass.h
  and rules/uabirth.h): the
  nine-band Social Class Table
  with the 68-entry occupation
  rosters, the starting-money
  note with the cavalier/paladin
  exception, the non-human
  placements and the
  one-rank-below profession rule;
  the 13-row Birth Table, the
  marital status split with the
  one-class-below-the-father read
  and the racial modifiers; both
  items CLOSED; the R336 seam
  cross-checks the cavalier
  stations; GREEN on the first
  run.- R368 landed 2026-10-12: commit
  37c7f1a, census 295, the UA
  Cavaliers Table I pin round
  (rules/uacavtable.h): the two
  0-level rows, the 1st-level
  footnote, the printed XP bands
  (the level-11 band decoded), the
  cumulative dice column, the level
  titles - the 11th and 12th cells
  newly readable (two of the four
  R328 holes close), the level-5
  grid Knight flagged, the level-6
  cell and the 12-sided header cell
  holes pending the PDF; the item
  CLOSED; the R368b follow-up fixed
  an off-by-one in the audit
  title-loop mapping (bad 12 to 0);
  the R328 seam cross-checks; GREEN
  on the second run, after the fix.- R369 landed 2026-10-12: commit
  41ca7f2, census 296, the UA
  cantrip acquisition pin round
  (rules/uacantacq.h): the five
  random known-count bands
  (reversed 2-8, legerdemain 2-5,
  person-affecting 2-8, personal
  2-8, haunting-sound 2-5), the 3
  developed cantrips cap with the
  DM review, the read-as-spell and
  recorded-as-spell notes; the
  useful one per point of
  intelligence free-choice read
  decoded from the garbled sentence
  (flagged pending the PDF); the
  item CLOSED; the R365 seam
  cross-checks the illusionist
  bands (the documented
  divergence) and the R366 seam
  the book counts; GREEN on the
  first run.- R370 landed 2026-10-12: commit
  4571cf3, census 297, the UA
  DM-section smalls part 1 pin
  round (rules/uasmalls1.h):
  Method V (the class-first prose
  clean, the dice table cells a
  flagged hole), the 12 starting
  hit-point minimums with the
  multi-class and con examples,
  the barding movement table (two
  lost cells flagged), the
  endurance, magical-barding and
  steeds rules; three items
  CLOSED; the R368 seam
  cross-checks the cavalier d10
  floor; GREEN on the first run.- R371 landed 2026-10-12: commit
  cfa4ec9, census 298, the UA
  expanded armor pin round
  (rules/uaarmor.h): the armor and
  encumbrance table rows (the
  banded, bronze plate, field
  plate, full plate, ring, scale,
  splint and studded leather rows
  with the costs, weights,
  movements, bulk flags and the
  shield rows) and the four
  descriptions (the bronze plate
  AC 4 with the rear-attack
  exposure, the elfin chain
  thief-wearable read, the field
  plate absorption with the cap
  and repair costs, the full
  plate); the R191 seam the plate
  AC ladder, the R334 seam the
  thief elfin rows, the R370 seam
  the barding weight read; two
  items CLOSED; GREEN on the
  first run.- R372 landed 2026-10-12: commit
  25881ba, census 299, the UA
  cavalier followers pin round
  (rules/uafollowers.h): the
  men-at-arms dice ladder (all d4,
  non-cumulative, the no-gain
  rule), the four equipment
  percentile rows with both
  outfits each and the medium
  warhorses at 91-00, the leader
  rules, the neutral-cause and
  evil-bandit reads with the 1
  and 5 percent monster chances,
  the henchman bonus and type
  table, the retainer ladder
  (the Knight prose conflict
  flagged), the paladin
  retainers; the R368 seam the
  title cells, the R371 seam the
  armor costs; two items CLOSED;
  GREEN on the first run.- R373 landed 2026-10-12: commit
  7893f9c, census 300, the UA
  comeliness note pin round
  (rules/uacomnote.h): the DM
  pointer to pages 6 and 7, the
  characteristic read, the
  effects on viewers and
  reactors, the trailing sentence
  hole flagged; the weapon
  descriptions item closed
  riding the R340 pins (the
  16-entry roster with the 14
  item-list types, the residual
  OCR holes flagged); the R322
  seam the creation roll and
  charisma ladder, the R340
  seam the roster, the R337
  seam the pole-arm rows; two
  items CLOSED; GREEN on the
  first run.- R374 landed 2026-10-12: commit
  1e9af1d, census 301, the UA
  treasure dial decision round
  (rules/uatreasuredial.h): THE
  DECISION resolved RUN BOTH -
  the DMG and UA tables ride as
  switchable alternatives behind
  a dial (DMG the default, UA,
  MERGED), playtesting picks;
  the per-source precedent
  rides the monster file format;
  the R219 seam the map bands,
  the R220 seam the hoard bands;
  the decision record landed, no
  item flipped; GREEN on the
  first run.- R375 landed 2026-10-12: commit
  23efe0c, census 302, the UA
  determination skeleton pin
  round (rules/uadetskel.h): the
  eight category bands and the
  sub-table splits pin clean (the
  misc magic carries SEVEN
  sub-bands, not two), the scroll
  footnotes pin (30 percent
  clerical, 25 druidical, 10
  illusionist, the DMG p. 121
  cross-ref); the row bodies of
  all eight tables OCR-scramble -
  the all-read-clean claim
  corrected, the item stays OPEN,
  PDF-gated; the R374 dial seam
  the modes; GREEN on the first
  run.- R376 landed 2026-10-12: commit
  be2766f, census 303, the UA
  new potions prose part 1
  round (rules/uapotprose.h):
  twelve of the nineteen
  new-potion descriptions pin
  clean (the four elixirs,
  fire breath, the oils of
  fiery burning, fumbling,
  sharpness, timelessness,
  rainbow hues,
  ventriloquism, vitality);
  seven descriptions
  OCR-scramble - the item
  AMENDED, stays OPEN,
  PDF-gated; the R375 seam
  the skeleton; GREEN on the
  first run.- R377 landed 2026-10-12: commit
  fe06b2c, census 304, the UA
  new scrolls protection prose
  pin round (rules/uaprotscr.h):
  eleven of the fifteen
  protection-scroll types pin
  clean (acid, breath weapons,
  fire, gas, illusions,
  paralyzation, plants,
  poison, the traps trio at
  50/30/20, water); four types
  OCR-scramble (cold,
  electricity, the two weapons
  scrolls) - the item
  AMENDED, stays OPEN,
  PDF-gated; the R376 seam the
  potions ledger, the R375
  seam the scroll splits;
  GREEN on the first run.- R378 landed 2026-10-12: commit
  a414462, census 305, the UA
  new rings prose pin round
  (rules/uaringprose.h): six
  of the thirteen new-ring
  descriptions pin clean
  (animal friendship,
  anything, blinking,
  jumping, mind shielding,
  truth); seven
  descriptions OCR-scramble
  (boccob, chameleon,
  clumsiness, faerie, ram,
  shocking grasp,
  sustenance) - the item
  AMENDED, stays OPEN,
  PDF-gated; the R377 seam
  the scrolls ledger, the
  R375 seam the ring band;
  GREEN on the first run.- R379 landed 2026-10-12: commit
  1b76292, census 306, the UA
  new rods staves prose pin
  round (rules/uarodstave.h):
  four of the eleven new
  descriptions pin clean
  (the rod of alertness, the
  rod of security, the
  staff-mace, the staff of
  slinging); seven
  descriptions OCR-scramble
  (flailing, passage,
  splendor, staff-spear,
  swarming insects, thunder
  and lightning, woodlands)
  - the item AMENDED, stays
  OPEN, PDF-gated; the R378
  seam the rings ledger,
  the R375 seam the rod
  band; GREEN on the first
  run.
## Knowledge maintenance

- Each land appends ONE entry to Round state above (date,
  commit, census, what landed, the lessons) - terse; the repo
  carries the code and the gap reports.
- When this file balloons past ~100KB, run the fresh start
  again (v3): backup + seed + continuation prompt saved to
  doc/vibe/ with a v3 suffix and committed BEFORE wiping
  knowledge and chats - the v2 process is the template.
