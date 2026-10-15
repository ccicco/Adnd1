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
  run.- R380 landed 2026-10-12: commit
  867e10a, census 307, the UA
  new wands prose pin round
  (rules/uawandprose.h): seven
  of the twelve wand types pin
  - five fully clean
  (anything, fireballs, flame
  extinguishing, ice storms,
  lightning bolts) plus two
  mechanics-clean with flagged
  holes (defoliation, metal
  command); five types
  OCR-scramble (buckler, earth
  and stone, force, size
  alteration, steam and vapor)
  - the item AMENDED, stays
  OPEN, PDF-gated; the R379
  seam the rods ledger, the
  R375 seam the wand band;
  GREEN on the first run.- R381 landed 2026-10-12: commit
  1ae8f21, census 308, the UA
  misc magic prose part 1 pin
  round (rules/uamiscprose1.h):
  thirteen A-C items pin -
  eight fully clean (beads of
  force, boots of the north,
  boots winged, bracers of
  archery, bracers of
  brachiation, cloak of
  arachnidia, cloak of the
  bat, cyclocone) plus five
  mechanics-clean with flagged
  holes (the amulet versus
  undead, the anything item,
  the boccob book, the boots
  of varied tracks, the chime
  of interruption); nothing
  in A-C fully garbles - the
  item AMENDED, stays OPEN
  for D-Z, PDF-gated; the
  R380 seam the wands ledger,
  the R375 seam the misc
  band; GREEN on the first
  run.- R382 landed 2026-10-12: commit
  471ff43, census 309, the UA
  misc magic prose part 2 pin
  round (rules/uamiscprose2.h):
  eight D-E items pin - one
  fully clean (the dust of
  tracelessness) plus seven
  mechanics-clean with flagged
  holes (the deck of illusions,
  the dicerion, the dust of
  dryness, the dust of illusion,
  the egg of desire, the egg of
  reason, the egg of shattering);
  nothing in D-E fully garbles
  - the item AMENDED, stays
  OPEN for F-Z, PDF-gated; the
  R381 seam the part-1 ledger,
  the R375 seam the misc band;
  GREEN on the second amend;
  the 382b using line and the
  382c egg-of-reason 66 check
  ride the fixers.- R383 landed 2026-10-12: commit
  1dbe6a0, census 310, the UA
  misc magic prose part 3 pin
  round (rules/uamiscprose3.h):
  eleven G-H items pin - two
  fully clean (the gloves of
  missile snaring, the hat of
  stupidity) plus nine
  mechanics-clean with flagged
  holes (the gem of insight,
  the girdle of dwarvenkind,
  the girdle of many pouches,
  the gloves of thievery,
  the hat of difference, the
  hat of disguise, the
  haversack, the horn of fog,
  the horn of goodness);
  nothing in G-H fully
  garbles - the item AMENDED,
  stays OPEN for I-Z,
  PDF-gated; the R382 seam
  the part-2 ledger, the
  R375 seam the misc band;
  GREEN on the first run.- R384 landed 2026-10-12: commit
  876adbc, census 311, the UA
  misc magic prose part 4 pin
  round (rules/uamiscprose4.h):
  nine I-P items pin - five
  fully clean (the iron bands
  of Bilarro, the lens of
  detection, the mantle of
  Celestian, the pearl of the
  sirines, the pouch of
  accessibility) plus four
  mechanics-clean with flagged
  holes (the lens of
  ultravision's diameter cell,
  Murlynd's spoon's gruel tail,
  the philosopher's stone's
  transmutation cells, the
  prison of Zagyg's attunement
  seam); nothing in I-P fully
  garbles - the item AMENDED,
  stays OPEN for Q-Z,
  PDF-gated; the R383 seam the
  part-3 ledger, the R375 seam
  the misc band; GREEN on the
  first run.- R385 landed 2026-10-12: commit
  cc5a2bc, census 312, the UA
  misc magic prose part 5 pin
  round (rules/uamiscprose5.h):
  eleven Q-S items pin - seven
  fully clean (the robe of
  stars, the scarab versus
  golems, the shadow lanthorn,
  the shoes of Fharlanghn, the
  slippers of kicking, the
  slippers of spider climbing,
  the sovereign glue) plus four
  mechanics-clean with flagged
  holes (the quiver of
  Ehlonna's command sentence,
  the robe of vermin's removal
  tail, the sheet of smallness'
  intro seam, the spoon of
  stirring's table cell);
  nothing in Q-S fully garbles -
  the item AMENDED, stays OPEN
  for S-Z, PDF-gated; the R384
  seam the part-4 ledger, the
  R375 seam the misc band;
  GREEN on the first run.- R386 landed 2026-10-12: commit
  e84e770, census 313, the UA
  misc magic prose part 6 pin
  round (rules/uamiscprose6.h):
  five S-Z items pin - two
  fully clean (the wind fan,
  Zagyg's flowing flagon) plus
  three mechanics-clean with
  flagged holes (the stone
  horse's activation word seam,
  the ultimate solution's
  transmutation seam,
  Zagyg's spell component case's
  gp tail); nothing in S-Z
  fully garbles - the item
  AMENDED, the prose pinned
  A-Z, stays PDF-gated only;
  the R385 seam the part-5
  ledger, the R375 seam the
  misc band; GREEN on the
  first run.- R387 landed 2026-10-12: commit
  5f9b91e, census 314, the UA
  armor and swords prose pin
  round (rules/uaarmprose.h):
  the pp. 104-105 stretch,
  eight items pin - four fully
  clean (the anything armor,
  the short sword of quickness,
  the sword of the planes, the
  anything sword) plus four
  mechanics-clean with flagged
  holes (the elfin chain
  mail's size-table garble, the
  plate's conform seam, the sun
  blade's radiance seam, the
  Final Word broadswords' names
  tail), riding the construction
  rule (+3 meteorite iron, +4
  mithral alloyed, +5 adamantite
  alloyed steel); nothing fully
  garbles - the item AMENDED,
  the prose pinned, stays
  PDF-gated only; the R386 seam
  the part-6 ledger, the R375
  seam the misc band; GREEN on
  the first run.- R388 landed 2026-10-12: commit
  cc2a141, census 315, the UA
  misc weapons prose pin round
  (rules/uamweapprose.h): the
  pp. 105-106 stretch, nine
  items pin - six fully clean
  (the bullet of impact, the
  dagger Longtooth, the darts
  of homing, the knife buckle,
  the magic quarterstaff, the
  scimitar of speed) plus
  three mechanics-clean with
  flagged holes (the axe of
  hurling's familiarization
  tail, the dagger of
  throwing's range cells, the
  hornblade's handle sentence)
  the R388 audit block covers
  in full; nothing fully
  garbles - the item AMENDED,
  the prose pinned, the
  treasure prose sweep
  complete, stays PDF-gated
  only; the R387 seam the
  armor ledger, the R375 seam
  the misc band; GREEN on
  the first run.- R389 landed 2026-10-12: commit
  b20764a, census 316, the UA
  weaponless combat appendix Q
  pin round (rules/uaappendq.h):
  the pp. 106-108 stretch, 207
  uaq pins, six items pin -
  one fully clean (the
  throwing rules) plus five
  mechanics-clean with flagged
  holes (the System I height
  example cell, the Pummeling
  Table row bodies, the kicking
  tail, the grappling size
  bands, the overbearing AC
  prose); nothing fully
  garbles; the R160 overlap
  reconciled (the DMG system
  stays the engine default,
  the UA System II pins as its
  own data layer); GREEN on
  the first run after the
  printf-label fix.- R390 landed 2026-10-12: commit
  ade8785, census 317, the UA
  non-lethal combat appendix R
  pin round (rules/uaappendr.h):
  the pp. 109-110 stretch, 85
  uanl pins, seven items pin -
  two fully clean (the subdual
  eligibility, the subdual
  damage accounting) plus five
  mechanics-clean with flagged
  holes (the subdual supercedes
  sentence, the vanquishing
  loser sentence, the chaotic
  constraints line, the
  monks-druids garble head,
  the disarming scimitar
  seam); nothing fully
  garbles; the R159 overlap
  reconciled (the DMG p.67
  knockout stays the engine
  default, the UA subdual pins
  as its own data layer), the
  R389 seam the System II
  weaponless layer; GREEN on
  the first run.
- R391 landed 2026-10-12: commit
  3b87a93 plus the R391b fix,
  census 318, the UA
  Appendix T pole-arm
  nomenclature pin round
  (rules/uaappendt.h): the pp.
  123-129 stretch, seven
  items - two fully clean (the
  spear family, the axe family)
  plus five mechanics-clean with
  flagged holes; nothing fully
  garbles; the R391b lesson: the
  audit cross-checks must
  fail-on-wrong, not fire-on-
  correct - the inverted
  family-coverage check flipped
  >= to <; RED until the fix,
  GREEN after; every audit
  check gets a Python
  simulation pass before
  publish.
- R392 landed 2026-10-12: 6cfd9c2
  committed RED plus the R392b
  repair a4bef30 (pushed
  together, b23846f..a4bef30),
  census 319, the UA players
  tables manifest sweep (pp.
  26-28, 20 manifest items): the
  equipment costs and hand-held
  tables pin NEW (uaequip26.h,
  uahandheld.h), the
  weight/damage, missile and
  proficiency tables amend; the
  clean PDF read fills every hole
  (the garrot L 1-6, the 68th
  row, the rate/range columns,
  the AC 7-10 ladders, the
  facing-page notes); the
  manifest closes; the R392
  lesson: the sim pass validates
  semantics, not emitted C - four
  C defects (a [1:-1] opener
  strip, an unescaped inches
  quote, two flipped return
  types) shipped past it; every
  round now gets the static
  header check; commit only on
  GREEN.
- R393 landed 2026-10-13: commit
  b069288, census 320, the
  PDF-read completion sweep: the
  clean PDF fills the three
  fragment-round holes -
  weaponspec.h all 24 spec
  cells plus the superseding
  note; thiefarmor.h the Open
  Locks 0/-5/-10, no-armor
  dashes, band-2 2/1,
  footnote-1 tail, footnote-4
  orphaned (the print anomaly);
  uailacquisition.h the IL
  starting list column-wise
  decode (the R365 interleave
  corrected). regtest
  R331/R334/R365 amend to the
  filled reads; the R393 audit
  lands before the R227 anchor;
  the three gap items flip
  AMENDED R393: closed. The
  body was rebuilt semantically
  after the sandbox lost the
  verified original (the
  published md5 differs by
  design); the Termux copy via
  ./nn hashed differently yet
  passed the battery - the ./nn
  save path may not be
  byte-faithful; verify the tail
  bytes next round.
- R394 landed 2026-10-13: commit
  4095934 (census 321, preflight
  GREEN), the UA DM tables
  manifest sweep: the clean PDF
  read (pp. 74, 76, 82-83,
  106-108) fills every flagged
  DM-section hole -
  uasmalls1.h the Method V 12 x
  7 dice matrix plus the barding
  column repin (a divergence
  fix: the R370 labels sat one
  column off); uasocialclass.h
  the LLC label and the Freed
  slaves roster head; uabirth.h
  the high-elf -20;
  uaappendq.h all six parts
  clean; TEN manifest items flip
  CLOSED; the Clerical QR rides
  Appendix S; Treasure Table III
  stays open for R395. The
  Termux copy hashed differently
  from the published md5 yet
  passed compile, the double-
  run, census 321 and the full
  battery - the ./nn save path
  still not byte-faithful (the
  R393 lesson); the R392 md5
  gate stays advisory.
- R395 landed 2026-10-13: commit
  1278168 (census 322, preflight
  GREEN), the UA Treasure Table
  III row bodies: the clean pp.
  84-89 read delivers every row
  body of all TWENTY-ONE tables
  (573 rows, perfect 1-100
  contiguity) - NEW
  rules/uadetrows.h (23
  accessors, flattened arrays:
  dice bands, names, marks,
  the x.p./g.p. columns as lo/
  hi pairs with the -1 none
  sentinel); the R375 skeleton
  flips (row-bodies-garble
  false x15 regtest sites; the
  seventh misc sub-table name
  III.E.7 reads clean) and the
  category names correct to
  Rings/Swords (the R375
  extract read them singular);
  both gap items flip AMENDED
  R395: closed - the UA report
  has no open table items. The
  generator stack (gen/emit/
  audit/build/sim) emits the
  header, the audit and the
  splice from rows.json. The
  ./nn save hash diverged for
  the third round running yet
  the copy passed the battery -
  stable and benign; the md5
  stays advisory.
- R396 landed 2026-10-13:
  commit daaad4a (census 323,
  preflight GREEN), the UA
  new-potions prose
  completion: the clean pp.
  90-91 read fills the
  seven PDF-gated
  descriptions (the oils of
  acid resistance,
  disenchantment, elemental
  invulnerability, impact,
  and the philters of
  beauty, glibness,
  stammering) - rules/
  uapotprose.h takes the
  fill sections, the part
  ledger flips 12/7 ->
  19/0, the R376 item
  flips AMENDED R396: closed
  - every UA potions-band
  description pins. The
  ./nn save hash diverged
  for the fourth round
  running yet the copy
  passed the battery -
  stable and benign; the
  md5 stays advisory.
- R397 landed 2026-10-13:
  commit 7e8cc89 (census 324,
  preflight GREEN), the UA
  scrolls rings rods staves
  wands prose completion:
  the clean pp. 91-98 read
  fills the four PDF-gated
  treasure items - the four
  scroll types
  (rules/uaprotscr.h), the
  seven rings
  (rules/uaringprose.h), the
  seven rods and staves
  (rules/uarodstave.h), the
  two wand holes and five
  garbled wands
  (rules/uawandprose.h); all
  four gap items flip
  AMENDED R397: closed -
  every UA treasure
  description pins. The
  ./nn save hash diverged
  for the fifth round running
  yet the copy passed the
  battery - stable and
  benign; the md5 stays
  advisory.
- R398 landed 2026-10-13:
  commit 2a9f559 (census 325,
  preflight GREEN), the UA
  misc magic flagged holes
  completion: the clean pp.
  98-104 read fills all 33
  flagged holes the six misc
  magic prose parts carry
  (rules/uamiscprose1.h
  through
  rules/uamiscprose6.h) -
  every part ledger runs
  clean, the four
  provisional pins correct
  (the lens diameter, the
  philosopher's stone
  pounds, the prison
  shrink). The ./nn save
  hash diverged for the
  sixth round running yet
  the copy passed the
  battery - stable and
  benign; the md5 stays
  advisory.
- R399 landed 2026-10-13:
  commit 5433fe5 (census 326,
  preflight GREEN), the UA
  armor swords misc weapons
  flagged holes completion:
  the clean pp. 104-106 read
  fills the last seven flagged
  holes (uaasp 4/4 -> 8/0,
  uamw 6/3 -> 9/0) - the ECM
  size table row-one label and
  height cells, the plate
  conform parenthetical, the
  sun blade radiance, the Final
  Word nine appellations, the
  axe of hurling tail, the
  dagger of throwing ranges and
  the hornblade handle. All
  PDF-gated prose now stands
  closed; the deferred seams
  remain.
- R400b landed 2026-10-13:
  commit c1313e3 (census 327,
  preflight GREEN), the UA
  comeliness site - the first
  deferred seam closes: the
  Character field (the raw 3d6
  base roll, the optional uacom
  save line), the creation roll
  and the two parley-gate
  reaction callers wire the
  R322 and R117 pins. The first
  R400 body failed the Termux
  compile (the game TUs do not
  pull rules/comeliness.h
  transitively) - no commit
  landed, the preflight RED gate
  held, and the fix body rode as
  R400b (the R392 convention,
  user decision): the two
  include patches, the audit
  label stays R400.
- R401 landed 2026-10-13:
  commit 6cf9115 (census 328,
  preflight GREEN), the UA
  cantrip tier seam - the
  sub-1st registry tier closes:
  rules/cantriptier.h (prefix
  cant, 31 inline functions) -
  the p. 45 tier traits, the
  0-level per-day xp ladder
  (neophyte 1, initiate 2,
  apprentice 3), the
  first-level discard and the
  four-cantrip retention, the
  round rules, the seven
  categories, the roster totals
  (66 MU + 8 IL). The R341
  decode corrects from the clean
  p. 30 scan: the reversed column
  prints Tangle, the personal
  Tweak - 66 names; the R341
  audit asserts reseat (Wilt 11,
  Unlock 9). The sim healthy
  pass caught two splice bugs
  pre-publish (the IL name
  asserts, the IL span assert) -
  fixed before the handoff. The
  ./nn save hash diverged for the
  ninth round running - benign;
  the md5 stays advisory.
- R402 landed 2026-10-13:
  commit 99f8bd2 (census 329,
  preflight GREEN), the UA
  treasure system dial - the
  R374 RUN BOTH decision wires:
  the runtime dial layer rides
  rules/uatreasuredial.h (the
  mode static, the
  validity-gated setter, the
  mode names, the dial-landed
  pin; the pending pins flip
  false - the UA pin rounds
  landed) and the mode-aware
  determination dispatch rides
  dm/treasure.cpp (the UA
  category bands, the carrier
  map, the sub-table splits -
  low the new UA table, high
  the DMG original, the misc
  seven sub-bands all UA - the
  row resolution off the R395
  bands, the MERGED union coin
  flip; the TU pulls its own
  rules includes - the R400
  lesson). The DMG default
  keeps the seventy landed
  audits authoritative. The
  ./nn save hash diverged for
  the tenth round running -
  benign; the md5 stays
  advisory.
- R403 landed 2026-10-13:
  commit feddba6 (census 330,
  preflight GREEN), the mount
  layer seam - the deferred
  engine seam lands on the R321
  aerial precedent: rules/
  mountlayer.h (prefix mml, 10
  inline functions) - the
  layer contract (no mount
  actor site; pins precede
  site; the charge stays
  open) and the six-feeder
  registry (R123 movement,
  R170 followers, R189 charge
  damage, R321 aerial, R328
  cavalier, R356 the mount
  spell), with the flying
  steed ladder cross-declared
  against the cavalier
  horsemanship tail. The
  mounted-combat charge stays
  open as its own ungated
  item. The ./nn save hash
  diverged for the eleventh
  round running - benign; the
  md5 stays advisory.
- R404 landed 2026-10-13:
  commit 9dc9a90 (census 331,
  preflight GREEN), the
  psionics seam - rules/
  psionics.h (prefix psx, 15
  inline functions) - the
  layer contract, the open/
  OUT records (the PHB
  sections OPEN, the DMG
  p.77 combat OUT), the
  duergar doubled chance
  (twice the usual, double
  all INT/WIS/CHA bonuses)
  and the svirfneblin PC
  ban, cross-checked against
  the R166/R323/R328 feeders.
  The psionic-combat charge
  stays open. The ./nn save
  hash diverged for the
  twelfth round running -
  benign; the md5 stays
  advisory. Ritual note: the
  ./nn step does not belong
  in the run ritual.
- R405 landed 2026-10-13:
  commit 548b966 (census 332,
  preflight GREEN), the deity
  layer seam - the LAST
  in-scope seam; rules/
  deities.h (prefix nhd, 24
  inline functions) - the
  Appendix S contract,
  source, census and dwarven
  reads, cross-checked
  against the R169/R322/
  R323/R404 feeders. The
  stat blocks + charts ride
  the seam ungated. The
  ./nn save hash diverged
  for the thirteenth round
  running - benign; the md5
  stays advisory. THE SEAM
  LIST IS NOW EMPTY.
- R406 landed 2026-10-13:
  commit 0ae5310 (census 333,
  preflight GREEN), the UA
  Appendix S stat blocks -
  the first ungated data round
  riding the R405 seam;
  rules/uaappends.h (prefix uas)
  - the 23 blocks pin the
  scan-clean numerics, the
  tier/rating censuses live
  against the seam, the 6985
  HP drift catch, the scan
  holes as sentinels. The
  class lines, MOVE, stat
  lines, prose and the
  charts stay open. The
  ./nn save hash diverged
  for the fourteenth round
  running - benign; the md5
  stays advisory.
- R407 landed 2026-10-13:
  commit a3570fb (census 334,
  preflight GREEN), the UA
  Appendix S clerical charts -
  rules/uascharts.h (prefix usc)
  - the five 8-column charts,
  23 rows, the 13 sacred
  animals, the gender reads,
  the frequency catches. The
  chart item CLOSES; Appendix
  S stays open on the class
  lines, MOVE, stat lines,
  prose. The ./nn save hash
  diverged for the fifteenth
  round running - benign; the
  md5 stays advisory.
- R408 landed 2026-10-13:
  commit cee2979 (census 335,
  preflight GREEN), the UA p. 26
  armor class table -
  rules/uaac26.h (prefix uacr)
  - the 11 composite rows, 28
  composites, the
  R191/R371/R392 cross-checks
  live; the two stale duplicate
  boxes close. The md5 diverged
  for the sixteenth round
  running - benign; the md5
  stays advisory.
- R409 landed 2026-10-13:
  commit bac456b (census 336,
  preflight GREEN), the UA
  Appendix S stat lines -
  rules/uasstatlines.h (prefix
  usl) - the 23
  S/I/W/D/C/CH/CM rows, the
  R153/R322 cross-checks live,
  the Cyrrollalee plus pair the
  recorded hole, the Bahgtru
  damage divergence recorded. The
  md5 diverged for the
  seventeenth round running -
  benign; the md5 stays  advisory.
- R410 landed 2026-10-13:
  commit e98c880 (census 337,
  preflight GREEN), the UA
  Appendix S class lines -
  rules/uasclasslines.h (prefix
  uascl) - the 23 blocks x 6
  printed lines, the Nil
  census 29, the psionic lines
  cross-checking the R406
  rating codes live (the
  Brandobaris missing line the
  recorded sentinel). The md5
  diverged for the eighteenth
  round running - benign; the
  md5 stays advisory.
- R411 landed 2026-10-13:
  commit 94e9302 (census 338,
  preflight GREEN), the UA
  Appendix S MOVE values -
  rules/uamoves.h (prefix umv)
  - the 23 rates, the five
  alternates, the Aerdrie
  flight-only flag; the Shargaas
  garble the recorded hole; the
  sanity ladders live; the
  pantheon prose alone stays open
  in Appendix S. The md5 diverged
  for the nineteenth round
  running - benign; the md5
  stays advisory.
- R412 landed 2026-10-13:
  commit 2927bfd (census 339,
  preflight GREEN), the UA
  USEFUL CANTRIP DESCRIPTIONS
  (pp. 45-47) - the first of the
  six MU cantrip description
  rounds; the R363 precedent
  rides; the casting-time family
  records as holes pending the
  PDF read. rules/uacantrips1.h
  (prefix ucn): the 20 useful
  cantrips in roster order, the
  school census 7/4/7/2, the 14
  clean areas, the six "7"-family
  area garbles the recorded
  holes, the mechanics pin (the
  40 F pair, the 1-4 damage pair,
  the salt limits, the tie range,
  the shine revalue, the color
  renewal, the polish floor).
  FIRST RUN RED: the first body
  emitted seven bare comment
  lines in the mechanics pins
  section - the C++ parse broke
  (the R392 comment-emission
  class); the R412b repair body
  re-prefixed the seven lines in
  place and landed both splice
  bodies (commit 2927bfd); two
  new guards ride since (the
  line-classification lint, the
  ucn identifier-resolution
  check). The md5 diverged for
  the TWENTY-FIRST round running
  - benign; the md5 stays
  advisory.
- R413 landed 2026-10-13:
  commit a3f059f (census 340,
  preflight GREEN), the UA
  REVERSED CANTRIP
  DESCRIPTIONS (pp. 47-48) -
  the second of the six MU
  cantrip description rounds;
  the R363/R412 precedents
  ride; the casting-time family
  records as holes pending the
  PDF read. rules/
  uacantrips2.h (prefix ucr):
  the 12 reversed cantrips in
  roster order, the school
  census 3/0/7/2, ALL 12 areas
  clean (ZERO area holes - the
  Dirty 4 sq. yds. cross-checks
  the Clean, the Dusty 10'
  radius, the Ravel Special,
  the Spill one container),
  the mechanics pin (the hairy
  growth pair, the knot and
  tangle ranges, the sour pint,
  the spill gallon, the
  tarnish/shine live pair).
  The R412b guards rode their
  first round clean (the
  line-classification lint, the
  ucr identifier-resolution
  check). First-try GREEN. The
  md5 diverged for the
  TWENTY-SECOND round running
  - benign; the md5 stays
  advisory.
- R414 landed 2026-10-13:
  commit 008066d (census 341,
  preflight GREEN), the UA
  LEGERDEMAIN CANTRIP
  DESCRIPTIONS (pp. 48-49) -
  the third of the six MU
  cantrip description rounds;
  the precedents ride; the
  casting-time family records
  as holes pending the PDF
  read. rules/uacantrips3.h
  (prefix ucl): the 6
  legerdemain cantrips in
  roster order, the school
  census 0/0/3/1/2 (Illusion
  a NEW school code), ALL 6
  areas clean, the HIDE
  DURATION LADDER (1 turn at
  2 cubic yards to 1 segment
  at 38) with the derivation
  cross-check. THE SIM CAUGHT
  AN R391-CLASS INVERTED
  CROSS-CHECK pre-publish (the
  first ladder derivation
  fired on healthy data) -
  the second live R391 catch.
  First-try GREEN. The md5
  diverged for the
  TWENTY-THIRD round running
  - benign; the md5 stays
  advisory.
- R415 landed 2026-10-13:
  commit c4dbccf (census 342,
  preflight GREEN), the UA
  PERSON-AFFECTING CANTRIP
  DESCRIPTIONS (p. 49) - the
  fourth of the six MU cantrip
  description rounds; the
  precedents ride. rules/
  uacantrips4.h (prefix ucp):
  the 10 person-affecting
  cantrips in roster order,
  the school census 8/0/0/1/0/1
  (Charm AS PRINTED, a NEW
  school code; the scan's
  "TVvitch" resolves as Twitch
  via the live roster), ALL 10
  areas clean (the one-person
  six and one-creature four,
  NEW area kinds), the yawn
  sleep susceptibility pins +
  the band derivation
  cross-check, the whole
  casting-time family the
  recorded holes pending the
  PDF read. Two pre-publish
  catches this round: a
  miscounted call-count assert
  and a bare comment line the
  R412b class guard caught.
  First-try GREEN on the user
  side. The md5 diverged for
  the SIXTEENTH round running
  - benign; the md5 stays
  advisory.
- R416 landed 2026-10-13:
  commit 51da28c (census 343,
  preflight GREEN), the UA
  PERSONAL CANTRIP
  DESCRIPTIONS (pp. 49-50) -
  the fifth of the six MU
  cantrip description rounds;
  the precedents ride. rules/
  uacantrips5.h (prefix uco):
  the 10 personal cantrips in
  roster order, the school
  census 1/0/1/0/0/0/5/3
  (Summoning and Conjuration
  AS PRINTED, NEW school
  codes; the scan's
  "Flrefinger" resolves as
  Firefinger via the live
  roster), the areas pin
  EIGHT clean with TWO area
  holes (the bluelight sphere
  and the firefinger line),
  the spider poison read +
  the band derivations, the
  casting-time, range-unit and
  slow-poison-defer families
  the recorded holes pending
  the PDF read. One pre-publish
  catch: a comma between
  adjacent string literals split
  the accessor line - the
  R412b class guard caught it.
  First-try GREEN on the user
  side. The md5 diverged for
  the SEVENTEENTH round running
  - benign; the md5 stays
  advisory.
- R417 landed 2026-10-13:
  commit 67c8f8a (census 344,
  preflight GREEN), the UA
  HAUNTING-SOUND CANTRIP
  DESCRIPTIONS (pp. 50-51) -
  the LAST of the six MU cantrip
  description rounds; ALL SIX
  now stand. rules/uacantrips6.h
  (prefix uch): the 8 haunting-
  sound cantrips in roster
  order, the school census
  3/0/0/0/5 (NO new codes),
  ALL 8 areas clean (the
  Special seven + the Tap
  1 sq. ft., a NEW area kind),
  the whistle pair pins clean
  (faint 10, loud 30, the
  loud == faint*3 derivation),
  the tap 1..3 band, the
  casting-time and range-unit
  families the recorded holes
  pending the PDF read. The
  49-line AMENDED R416 gap
  anchor was embedded byte-
  exact via a generator. The
  md5 diverged for the
  EIGHTEENTH round running -
  benign; the md5 stays
  advisory.
- R418 landed 2026-10-13:
  commits ade93bd + the R418b
  repair 21a7031 (census 345,
  preflight GREEN), the UA
  CANTRIP CASTING-TIME
  RESOLUTION PART 1 (book pp.
  45-48) - the PDF read resolves
  the useful (20), reversed (12)
  and legerdemain (6) casting-
  time families: 38 cells, ALL
  clean unit fractions AS
  PRINTED; the hole blocks amend
  to uXXCastTimeDen accessors over
  D[] arrays plus DenCount census
  helpers; censuses 17/0/2/1,
  4/1/5/2 and 0/1/1/4; the 2..10
  norm band cross-checks. The
  R418 body shipped RED (the
  orphaned || pin chains - the
  per-row emitter opened only the
  FIRST chain with if ( - three
  expected-expression compile
  errors, the battery never
  built, preflight cascaded into
  hundreds of phantom CENSUS
  FAILs); landed via the b-route
  (the R392/R392b precedent). The
  R418b repair added the standing
  gates: NO chain may begin with
  ||, and every regtest pin is
  mirror-evaled against the
  header D[] arrays. The ./nn
  save hash diverged twice -
  benign; the md5 stays advisory.
- R419 landed 2026-10-13:
  commit 058a00b (census 346,
  preflight GREEN), the UA
  CANTRIP CASTING-TIME
  RESOLUTION PART 2 (book pp.
  49-51) - the PDF read resolves
  the person-affecting (10),
  personal (10) and haunting-
  sound (8) casting-time
  families: 28 cells, all clean
  unit fractions AS PRINTED; the
  censuses 1/3/2/4, 7/3/0/0 and
  0/0/5/3 (the 1/6 inside the
  2..10 band); the two R416
  areas (the Bluelight sphere,
  the Firefinger line), the range
  units (the AD&D 1" notation),
  the slow-poison defer (1 day)
  and the creak reads (the
  former 1/3 segment, the
  traverse 10 feet) resolve with
  the read; the hole flags come
  off - the MU cantrip
  descriptions stand hole-free.
  The ./nn save hash diverged
  (50f18379 vs the published
  f4de3b1e) - benign (21st
  occurrence); the md5 stays
  advisory.
- R421 landed 2026-10-13:
  commits d20e300 + the
  R421b repair 1aa2c2f +
  the cleanup 365ec5b (one
  push, preflight GREEN on
  the repair run), the UA
  IL CANTRIP CAST-TIMES
  RESOLUTION (book pp. 65-66
  + the p. 31 column read) -
  the PDF read resolves the
  eight casting-time cells
  (colored lights, dim, haze
  and mirage at 1/2; rainbow
  at 1/3; mask, noise and
  the two-d-lusion at 1/8 -
  the census 4/1/3, the
  2..10 band holds), the
  mirage and two-d-lusion
  school cells and areas,
  the mirage somatic tail,
  the colored-lights
  reflection sentence and
  the R342 IL cantrip column
  (the eight names,
  cross-checked against the
  description roster row for
  row); the IL cantrip
  descriptions stand
  hole-free, the gap box
  flips, census 346 -> 347.
  DEFECT SHIPPED in d20e300
  (the push aborted): the
  R421 audit printf carried
  an unterminated string
  literal (the R418 pattern);
  R421b heals it (one patch,
  census stays 347) and lands
  the standing string-literal
  parity gate; the cleanup
  commit removes the stray
  "347" artifact. The ./nn
  save hash diverged -
  benign (23rd occurrence);
  the md5 stays advisory.
- R422 landed 2026-10-13:
  commit a911b59 (census 348,
  preflight GREEN on the FIRST
  run, pushed 365ec5b..a911b59),
  the APPENDIX R RESOLUTION - the
  clean p. 109 read resolves the
  five R390 flagged holes: the
  subdual supercedes sentence,
  the vanquishing loser sentence
  ("must honorably surrender
  immediately"), the chaotic
  constraints line ("under no
  constraints whatsoever") and
  the monks-druids head print
  whole; the disarming scimitar
  seam confirms as the print
  itself (the example names the
  scimitar, absent from the
  six-entry list - the book's
  own seam, pinned as printed);
  all seven items fully clean,
  the box flips; census 347 ->
  348. The advisory md5 diverged
  (6853301009da2dbb7087d714b0a097c9
  vs the published
  d135d3a864e1058bc621ff5a31c675d5)
  - benign; the md5 stays
  advisory.
- R423 landed 2026-10-13:
  commit a44b3d0 (census 349,
  preflight GREEN on the FIRST
  run, pushed a911b59..a44b3d0),
  the UA APPENDIX S PANTHEON
  PROSE - the five pantheon
  intro sections (pp. 110-120,
  the clean OCR read) pin as
  rules/uapantheon.h (NEW,
  prefix uapn), the censuses
  cross-checked live against
  the R405 seam (the described
  counts mirror nhdPantheonSize
  row for row, the sum mirrors
  nhdDeityCount 23, the Moradin
  rulings mirror the R405 seam
  functions); the Appendix S
  item CLOSES - the box flips,
  nothing stays open; census
  348 -> 349.
- R424 landed 2026-10-13:
  commit 8e710fb (census
  350, preflight GREEN on
  the FIRST run, pushed
  a44b3d0..8e710fb), the
  APPENDIX T RESOLUTION -
  the LAST open
  book-content box in the
  UA gap report closes.
  The clean OCR read
  (pages 124/127/128/129 =
  printed 123/126/127/128)
  resolves the five R391
  flagged holes: the
  classification system
  paragraph, the fauchard
  description, the
  Lucern/bec comparison
  tail, the combination
  intro, the bill-guisarme
  features list and the
  confusion sentence all
  print whole; every flag
  REPLACED 1:1 with a
  ReadsClean pin (the
  inline count 161 stays);
  the ledger flips clean 2
  -> 7, flagged 5 -> 0.
  Gap post-state: 102
  closed, 3 open (the two
  logging layers + the
  legend line) - ALL
  book-content boxes are
  CLOSED. Sim: 7 value + 3
  expectation mutants all
  RED, clean GREEN.
  Census 349 -> 350.
- R425 landed 2026-10-14:
  commit f313aa1 (census
  351, preflight GREEN on
  the FIRST run, pushed
  8e710fb..f313aa1), the
  WSG ARC OPENER - the
  wilderness proficiencies.
  rules/wsgprof.h (NEW, 33
  inlines, prefix wsg): the
  Proficiency Check system
  (1d20 vs the Appropriate
  Ability, the unmodified
  19/20 auto-fail, the 18
  cap, the 2-in-20 floor,
  the -2 improving step
  from 3rd level, an
  improved 19 succeeds, a
  natural 20 always fails),
  the slot rules (a weapon
  slot may hold a nonweapon
  proficiency, never the
  reverse), the expanding
  optional rule (1st level
  only, a delayed slot is
  lost), the horseman
  footnote, Table 1 (the 14
  class rows, the bard "as
  other classes" sentinel)
  and Table 2 (the 25 rows)
  as switches with the
  censuses and the book own
  denominator arithmetic.
  tools/wsg_gap_report.md
  (NEW): the lossless
  whole-book inventory -
  the 42-table manifest from
  the book own Tables index,
  the 14 chapters, the DM
  section, the weather
  appendix; 5 closed, 181
  open, 42 tables. The
  double-run 5/0 then 0/5;
  the user Termux md5 was
  not captured this round -
  575a6199 stays advisory
  (the compile, the double-
  run and the GREEN
  preflight prove the body).
  Census 350 -> 351.
- R426 landed 2026-10-14:
  commit 435aaac (census
  352, preflight GREEN,
  pushed f313aa1..435aaac),
  the dressing-for-the-
  weather chapter closes
  WHOLE - the first WSG
  pin round after the arc
  opener.
  rules/wsgdress.h (NEW, 54
  inlines, prefix wsd): the
  four clothing categories
  (very cold below 0, cold
  0-30, moderate 31-75, hot
  76+; the encumbrance
  equivalents - plate mail
  bulky 450 gp, ring mail
  fairly bulky 250 gp,
  leather non-bulky 150 gp,
  none - the outfit costs
  15/7/3 gp and the 6-sp
  robe, the layer
  equivalences 2-cold /
  4-moderate), Table 3 (the
  15 attire rows x the 4
  temperature columns,
  CUMULATIVE - the text
  layer DROPPED the Splint
  Mail label and the whole
  Leather Armor row, the
  grid re-read from the
  page image), the
  protected/unprotected
  rules (the five category
  clauses + the metal-armor
  clause above 80, studded
  leather not metal), the
  three exertion regimes
  and the clothing-as-armor
  option (AC 8/9, the
  10-percent miscast).
  tools/wsg_gap_report.md
  flips 8: 12 closed, 174
  open, 42 tables.
  INCIDENT: the first build
  was committed RED (local
  101082c, never pushed;
  the push was ^C-d on the
  RED preflight) - the
  audit block split C++
  identifiers across lines
  (57 sites) and the column
  switches emitted the
  parameter without its
  type; the reset route
  landed one clean commit.
  NEW GATE (the R426
  lesson): the
  no-split-identifier gate
  in every splice verify
  pass. The landed Termux
  md5 diverged from the
  published value by  exactly one trailing
  newline - benign, the
  md5 stays advisory.
  Census 351 -> 352.
- R427 landed 2026-10-14:
  commit 9723174 (census 353, preflight GREEN, (census 353, preflight GREEN,
  pushed 435aaac..9723174), the WSG environment data slice, printed pp. 21-22
  - Table 4 (the 13 temperature bands, the str/dex/con, land-move num/den and
  attack columns, 99 = no effect) and Table 5 (the 6 wind bands 0-10 to 80+,
  the missile/melee and move num/den columns, 99 = xx impossible), the
  how-to-use prose pins (the 2-turn strenuous window, the ex-str caps 18/17,
  fractions round up, the damage floor 1, the greater of the two move
  reductions, perpendicular one band lower) and the precipitation shifts
  (moderate +1 band, heavy +2, capped at the bottom 80+ line).
  rules/wsgenvfx.h NEW (38 inlines, prefix wse), verified cell for cell
  three-way (the page image vs the text layer vs the book own examples: 105
  deg band 10, -30 LM 1/2, 35 mph melee -2, 85/40 the greater reduction 2/3,
  the 90-mph cap). tools/wsg_gap_report.md flips 5: post-state 16 closed, 170
  open, 42 tables. Lessons: the 99 census was initialized to the expected
  values and then incremented - now zeros plus a separate expected array; the
  precip cap check band(90)+2 != 5 was TRUE on correct data and would have
  shipped bad 1 - now band(90) == 5 with the raw shift 5+2 = 7; the no-split
  gate caught 10 splits in the first build. Census 352 -> 353.
- R429 landed 2026-10-14:
  commit 2fbf672 (census 354, preflight GREEN, pushed b0acf8c..2fbf672), the
  WSG special weather data slice, printed pp. 23-24 - the FIRST PURE-DATA
  round: build_spec_r429.py (Vibe side) is only the ground-truth tables +
  labels over build_spec_general; zero engine changes (Table 6 doubled to
  half-points, Table 7 0/1/2 = -/D/X, Table 8 the 1dN die size, all sentinel
  0). rules/wsgsplwx.h NEW (70 inlines, prefix wsw) - Table 6 hurricane
  damage, Table 7 tornado codes (incl. the Wood and stone row), Table 8
  hailstorm dice, plus the hurricane, gale, tornado, sandstorm and hailstorm
  prose pins (45 consts, 11 bools, the hailstone-size chain). Ground truth
  three-way verified (IIIF vs djvu vs the printed prose; the Table 7 row
  labels re-read on the page image). rverify GREEN: 118 mutants, 0 missed. The
  seed patch carried the R427 record. NEW CONVENTIONS: round spec JSONs live
  in tools/ (untracked); the bn launcher names tools/spec_rXXX.json from the
  round number; the nano trailing newline is documented behavior, both md5s
  published, the md5 gate deterministic. Census 353 -> 354.
- R430 landed 2026-10-14:
  commit ae2a14c (census 355, pushed 2fbf672..ae2a14c; the preflight was
  SKIPPED that round - the cond-wrap defect it would have caught surfaced at
  R431, the engine gained the cond syntax gate and the R430 regtest block was
  regenerated clean), the WSG heat-and-cold data slice, printed pp. 25-27 -
  Table 9 (the 25 temperature damage bands, Con/Dmg x unprotected/protected,
  99 = the dash, the book own +3-then-+5 skip at 110-119) and Table 10 (the
  frostbite shares in sixths with the single-part thresholds Feet 4 / Ears 6 /
  Hands 8; the four combination-row cells BLANK IN PRINT, settled by the USER
  EYE-READ after the archive scan blurred them and vision reads confabulated;
  the user own copy upload agreed) plus the damage and Con-check adjustments,
  hypothermia, frostbite and heatstroke prose. rules/wsgheat.h NEW (72
  inlines, prefix wsh) - the heatstroke worked example pins as three checks
  (2+6 = 8, 2-1 = 1, 2/3 of 10 rounded up = 7). rverify GREEN: 215 mutants, 0
  missed. The nano-paste md5 matched the PREDICTED value exactly (the
  deterministic md5 convention working). Census 354 -> 355.
- R431 landed 2026-10-14: commit 0d22d27 (census 356, pushed ae2a14c..0d22d27,
  preflight GREEN from a real compiled binary), the WSG EQUIPMENT EFFECTS data
  slice, printed pp. 28-29 - the FIRST PURE-PROSE round (rules/wsgequip.h, 30
  inlines, prefix weq): the water and rust rules (dry metal every 2 days, oil
  every 2 weeks, the armor crack on an unmodified 20 for over 4 damage at
  1-in-3, the shield near-miss split at 50 percent, the weapon break on an
  unmodified 1 at 1-in-3), the leather and rope rules, the wet-arrow penalty
  (the specialist exempt) and the sand/dust chafe rules; the
  effects-of-the-environment chapter closes WHOLE. The round ALSO carried the
  engine fix (_wrap_cond plain-indents the wrapped condition continuations;
  the new gate_cond_syntax kills the broken-emit class at emit time) and the
  R430 regtest block regenerated clean. rverify GREEN: 30 mutants, 0 missed.
  The landing took four takes; the recovery rules (pastes after the git
  surgery, never run past a failed md5 gate, the reflog recovers a dropped
  commit) hold from here. Census 355 -> 356.
- R432 landed 2026-10-14: commit da25c98 (census 357, pushed 0d22d27..da25c98,
  preflight GREEN on the FIRST run - the md5 gate matched the predicted +nl
  variants exactly), the WSG ENCUMBRANCE AND MOVEMENT opener, printed pp.
  30-31 - Table 11 (the 14 strength rows x the Light/Moderate/Heavy/Severe gp
  limits, the plain-strength and the percentile row dispatch chains) and Table
  12 (the encumbrance category x the terrain class, the normal and the
  accelerated miles per half-day) with the bulk rule-of-thumb (x1 non-bulky,
  x2-3 bulky, x5 very bulky, 10 gp = 1 lb), the terrain definitions and the
  large-scale overland movement rules. rules/wsgencum.h NEW (54 inlines,
  prefix wem). The round ALSO carried the rverify chain-limit fix (the leaked
  loop variable read the last chain last limit - masked in R430 by its single
  chain, exposed here by the two). rverify GREEN: 153 mutants, 0 missed.
  Census 356 -> 357.
- R433 landed 2026-10-14: commit eb8937f (census 358, pushed da25c98..eb8937f,
  preflight GREEN on the FIRST run - the third clean first-try land in a row),
  the WSG LAND-BASED ANIMALS, printed pp. 31-32 - Table 13 (the 18 mounts and
  beasts of burden x the normal load, the maximum load and the
  unencumbered/encumbered rates over the three terrain classes; a 0 = cannot
  move there) with the two-designation rules, the forced-move stamina rules
  (the hours equal half the current rate, capped at 12; the cumulative fatigue
  chance 20/35/50 percent by terrain; the book own warhorse examples pinned)
  and the accelerated no-rest +1/3 spillover (written division-free - the
  float/int division class the sim exists to catch). rules/wsganimal.h NEW (28
  inlines, prefix wam). Ground truth three-way verified; the Sheep, Yak and
  light-war very-rugged cells absent from the djvu text layer were settled by
  the IIIF full-resolution eye-reads. rverify GREEN: 164 mutants, 0 missed.
  Census 357 -> 358.
- R434 landed 2026-10-14: commit 3d74d6a (census 359, pushed
  eb8937f..3d74d6a, preflight GREEN on the FIRST run - the fourth clean
  first-try land in a row), the WSG LAND-BASED VEHICLES, printed p. 33 - Table
  14 (the 21 cart, chariot and wagon rows by the animal team x the normal and
  rugged miles-per-half-day rates and the maximum gp loads; a 0 rugged entry =
  the vehicle cannot go there) with the prose rules (the miles-per-half-day
  scale, the no-very-rugged rule, the flat-or-path assumption, the pathless
  one-category-worse rule and the lightly-forested example). Key pins: the
  small cart/pony 8/4/3500, the medium cart/pony cannot go rugged (0), the
  large chariot/heavy horses fastest at 16/10, the large wagon/heavy horses
  hauling the most at 15000 gp. rules/wsgvehicle.h NEW (15 inlines, prefix
  wvv, checked free). Ground truth three-way verified (the djvu garbled four
  rows settled by the IIIF full-res eye-reads; the compiled-tables copy reads
  the cart medium/pony rugged cell as 6 - a djvu OCR error, the body text and
  the user copy both read 0). Gap 31/155 -> 33/153; census 358 -> 359. rverify
  GREEN: 75 mutants, 0 missed. Spec md5s: 357932ca authored / f5ed3223 +nl.
  GITHUB VERIFIED at the pinned full sha
  3d74d6ac18408f459bb55030360b5f54526d6f2c: census 359, the R434 audit
  present, wsgvehicle.h 15 inlines, the gap 33 closed / 153 open, the R433
  seed record in place. Next after landing: Table 15, the climbing rates - the
  movement-across-special-terrain section.
- R435 landed 2026-10-14: commit 76e9023 (census 360, pushed
  3d74d6a..76e9023, preflight GREEN on the FIRST run - the fifth clean
  first-try land in a row), the WSG CLIMBING, printed pp. 33-34 - Table 15
  (the 13 surface rows x the three condition rates in feet per round for a
  thief with the per-cell thief-or-mountaineering restricted flags) with the
  climbing prose (all characters can climb, the non-thief half rate, the dex
  Reaction/Attacking Adjustment, the no-tools assumption, the cracks assumed
  except the gentle nonslippery slope, the thieves-only devoid rule), the
  encumbrance modifications (the severe, heavy-or-moderate and light bands;
  the cliff needs an unencumbered climber), the surface types (the degree
  bands and elevation changes, under-15 not a slope, the overhang same rules)
  and the chance of falling (100 minus the Climbing Rating, the non-thief 40,
  the mountaineer-with-tools 80 on restricted surfaces, the d100 roll
  at-or-under succeeds). Key pins: the rough gentle slope 90/60/30, every
  cliff cell restricted, the cliff smooth no-ledges row 10*/5*/5*.
  rules/wsgclimb.h NEW (43 inlines, prefix wcs - wcl was NOT free, hits wclass
  in regtest; checked). Ground truth three-way verified (the cliff smooth
  with-ledges non-slippery cell: the djvu reads 16*, two eye-reads settle
  15*). Gap 33/153 -> 35/151; census 359 -> 360. rverify GREEN: 115 mutants, 0
  missed. Spec md5s: d5c4631f authored / 3a4514a2 +nl. GITHUB VERIFIED at the
  pinned full sha 76e9023b0174d3388d203cd1b9522e86cad33e67: census 360, the
  R435 audit present once, wsgclimb.h 43 inlines, the gap 35 closed / 151
  open, the R434 seed record in place. Next after landing: the climbing checks
  and Table 16 (p. 35).
- R436 landed 2026-10-14: commit 9d34030 (census 361, pushed
  76e9023..9d34030, preflight GREEN on the FIRST run - the sixth clean
  first-try land in a row), the WSG CLIMBING CHECKS, printed p. 35 - Table 16
  (the same 13 surface rows as Table 15 x the three condition modifiers to the
  non-thief Climbing Rating, from the +70 rough gentle non-slippery bonus down
  to the -50 cliff smooth no-ledges slippery penalty) with the 100 percent
  no-fall and 5 percent floor rules, the other modifiers (encumbrance, race,
  armor, strength and hands), the thief modifiers (the +30 auto rule, the
  doubled and quadrupled falling chances, the shared 5 percent floor) and the
  initial, intermediate and final check rules. rules/wsgcheck.h NEW (49
  inlines, prefix wck, checked free). Ground truth three-way verified (the
  djvu was missing the normal moderate, normal severe and both cliff smooth
  rows and garbled the smooth gentle row; four IIIF full-res eye-reads matched
  the user copy exactly). NOTE: the IIIF image path changed - use the
  iiif.archive.org/image/iiif/2 full URL with the jp2.zip path; the Table 16
  page is image file 0035.jp2. The first build had one TRUE-on-healthy example
  (the no-fall worked case written as equality); rewritten as the comparison.
  Gap 35/151 -> 37/149; census 360 -> 361. rverify GREEN: 85 mutants, 0
  missed. Spec md5s: be5e4b95 authored / fda106d4 +nl. GITHUB VERIFIED at the
  pinned full sha 9d3403089fe162b6329468792fd74f2fce5bb285: census 361, the
  R436 audit present once, wsgcheck.h 49 inlines, the gap 37 closed / 149
  open, the R435 seed record in place. Next after landing: the damage from
  falling, Table 17 (p. 35).
- R437 landed 2026-10-14: commit 90e0813 (census 362, pushed
  9d34030..90e0813, preflight GREEN on the FIRST run - the seventh clean
  first-try land in a row), the WSG DAMAGE FROM FALLING, printed pp. 35-36 -
  Table 17 (the six fall-distance bands x the band-minimum distances and the
  cumulative damage dice: 10 feet 1d6, 11-20 3d6, 21-30 6d6, 31-40 10d6, 41-50
  15d6, 51-or-more 20d6 the maximum) with the falling-vs-tumbling prose
  (falling = a vertical drop, much more liable to cause serious injury or
  death; tumbling down a moderate or gentle slope is Table 18, the next
  round), the 1d6-cumulative-per-10-feet basis, the figures applying to free
  fall AND tumbling down a severe slope, the smooth/slippery abrasion note and
  the unimpeded rates (1000 feet per round free fall, 600-800 feet per round
  down a severe slope). rules/wsgfall.h NEW (14 inlines, prefix wdf, checked
  free). Ground truth three-way verified (the 11-20 feet dice cell MISSING
  from the djvu; two eye-reads settled 3d6, matching the user copy). Gap
  37/149 -> 39/147; census 361 -> 362. rverify GREEN on the FIRST build: 24
  mutants, 0 missed. Spec md5s: 0961b993 authored / 8f86aadb +nl. GITHUB
  VERIFIED at the pinned full sha 90e0813cad2980016f7ffc306c08fc986516e18c:
  census 362, the R437 audit present once, wsgfall.h 14 inlines, the eye-read
  cell landed, the gap 39 closed / 147 open, the R436 seed record in place.
  Next after landing: the tumbling damage - Table 18 (p. 36).
- R438 landed 2026-10-14: commit e0bc5a3 (census 363, pushed
  90e0813..e0bc5a3, preflight GREEN on the FIRST run - the eighth clean
  first-try land in a row), the WSG TUMBLING DAMAGE, printed p. 36 - Table 18
  (the six moderate-or-gentle slope rows x the three condition cells, each
  entry split into the abrasion-free feet, the abrasion die and the impact
  distance) encoded as a 9-column table with the entry-format prose, the
  worst-case and gradual-stop impact rules, the flat-terrain extra abrasion
  and the tumble rates; the book own worked example (the smooth moderate
  slightly-slippery 40/3/20 cell) pinned as two division-free examples.
  rules/wsgtumble.h NEW (26 inlines, prefix wdt, checked free). Ground truth
  three-way verified (the two normal-row slippery cells settled by two IIIF
  eye-reads, matching the user copy). NOTE: the first build had a row-index
  slip in the worked example - the sim caught the two TRUE-on-healthy
  examples. NOTE: the GitHub API was rate-limited at verify time - the full
  sha came from the commit .patch page. Gap 39/147 -> 40/146; census 362 ->
  363. rverify GREEN: 71 mutants, 0 missed. Spec md5s: eb40665c authored /
  dc3c6146 +nl. GITHUB VERIFIED at the pinned full sha
  e0bc5a3852dd4d49197fb62f5ae04f9aac1d8c43: census 363, the R438 audit present
  once, wsgtumble.h 26 inlines, the eye-read cells landed, the gap 40 closed /
  146 open, the R437 seed record in place. Next after landing: the stopping of
  a fall - Table 19 (p. 36).
- R439 landed 2026-10-14: commit a6536db (census 364, pushed
  e0bc5a3..a6536db, preflight GREEN on the FIRST run - the ninth clean
  first-try land in a row), the WSG STOPPING A FALL, printed p. 36 - Table 19
  (the four surface rows x the three condition stop fractions, each a fraction
  of the Climbing Rating: gentle 7/8-3/4-2/3, moderate 3/4-2/3-1/2, severe
  2/3-1/2-1/4, cliff 1/2-1/4-dash) encoded as a 6-column numerator/
  denominator table with the one-attempt rule, the 50/75/100-foot windows, the
  protrusion requirement and the slope-self-halt rule; all fraction
  comparisons written cross-multiplied, division-free. rules/wsgstop.h NEW (20
  inlines, prefix wsf - wsp was NOT free). Ground truth three-way verified
  (the djvu table zone heavily garbled; two IIIF eye-reads matched the user
  copy exactly). Gap 40/146 -> 42/144; census 363 -> 364. rverify GREEN on the
  FIRST build: 38 mutants, 0 missed. Spec md5s: d8d12995 authored / 4be67f21
  +nl. GITHUB VERIFIED at the pinned full sha
  a6536db0d65969519eec30118498033c888ea682: census 364, the R439 audit present
  once, wsgstop.h 20 inlines, the fraction cells landed (the cliff 0/0 dash),
  the gap 42 closed / 144 open, the R438 seed record in place. Next after
  landing: the rope rules (p. 36).
- R440 landed 2026-10-14: commit 4bf7254 (census 365, pushed
  a6536db..4bf7254, preflight GREEN on the FIRST run - the tenth clean
  first-try land in a row), the WSG USING ROPE FOR MOVEMENT AND CLIMBING,
  printed p. 36 - the rope prose (no table this round): the single most
  important climbing equipment is a coil of rope; the standard 50-foot coil
  (somewhat smaller than half an inch in diameter) supports up to 1500 pounds
  without fraying or breaking; past the limit a 20 percent per-turn
  non-cumulative break chance while the strain remains; the weakening chance
  is cumulative - 10 percent after one turn of strain, 30 after two, 60 after
  three, 100 after four (the wsrWeakenPct switch ladder); a weakened rope
  breaks the next time it supports more than its limit at 40 percent per turn
  non-cumulative. rules/wsgrope.h NEW (12 inlines, prefix wsr - wro was NOT
  free; wsr checked free in all three TUs). Ground truth CLEAN two-way (the
  user copy OCR vs the djvu word layer - the section reads clean in the djvu,
  every number matched, no eye-reads needed). Gap 42/144 -> 43/143; census 364
  -> 365. rverify GREEN on the FIRST build: 11 mutants, 0 missed. Spec md5s:
  a88b0f6e authored / 44822213 +nl. GITHUB VERIFIED at the pinned full sha
  4bf7254a845854d6b6cb811ba606ba6ba327b691: census 365, the R440 audit present
  once with the bad 0 printf, wsgrope.h 12 inlines, the weakening ladder
  landed (0/10/30/60/100), the gap 43 closed / 143 open, the R439 seed record
  in place, no wsr hits in the caller TUs. Next after landing: the roping
  together (p. 37).
- R441 landed 2026-10-14: commit 1aa49f0 (census 366, pushed
  4bf7254..1aa49f0, preflight GREEN on the FIRST run), the WSG ROPING
  TOGETHER, printed p. 37 - the cascade prose (no table): adjacent climbers
  must recheck even after a success earlier in the same round; a fallen end
  character forces one adjacent check, a fallen middle character both sides;
  the wrpCascadePenaltyPct switch ladder 0/10/20/30/40 - a -10% step per
  fallen character beyond the first (the five-character example on a 200-foot
  rope cascades -10, -20, -30); the last-pair extra check; the tie capacity -
  50 feet ties two, one more per additional 50 feet. rules/wsgtog.h NEW (11
  inlines, prefix wrp - checked free in all three TUs). Ground truth CLEAN
  two-way (the user copy OCR vs the djvu word layer Guide_0037 - every number
  matched, no eye-reads). Gap 43/143 -> 44/142; census 365 -> 366. rverify:
  one authoring-side RED fix before delivery (the cascade switch argument off
  by one - caught by the audit mirror, rebuilt GREEN: 10 mutants, 0 missed);
  the DELIVERED spec ran first-try clean on the user side. Spec md5s: 7dabd14e
  authored / e00f5747 +nl. GITHUB VERIFIED at the pinned full sha
  1aa49f0ddd41f09f81d44a472357f60723960629: census 366, the R441 audit present
  once, wsgtog.h 11 inlines, the cascade ladder landed (0/10/20/30/40), the
  gap 44 closed / 142 open, the R440 seed record in place, no wrp hits in the
  caller TUs. Next after landing: the rappelling (p. 37).
- R442 landed 2026-10-14: commit e176cf3 (census 367, pushed
  1aa49f0..e176cf3, preflight GREEN on the FIRST run), the WSG RAPPELLING,
  printed p. 37 - the descent prose (no table): a rope-secured descent of a
  non-horizontal surface at a base speed of 120 feet per round (encumbrance
  and other penalties apply as for an ascent); a Climbing Check at +50% to the
  Climbing Rating for every round or part of a round; a failed check means the
  grip is lost - the character hangs upside down, spinning, until rescued or a
  successful Dexterity Check (once per round); the free-hanging variant (no
  surface to brace against) at +30% instead of +50%, with a +2 Dexterity
  modifier on a failed check. rules/wsgrapp.h NEW (9 inlines, prefix wrl -
  checked free in all three TUs). Ground truth CLEAN two-way (the user copy
  OCR vs the djvu word layer Guide_0037 - every number matched, no eye-reads).
  Gap 44/142 -> 45/141; census 366 -> 367. rverify GREEN on the FIRST build: 9
  mutants, 0 missed. Spec md5s: feddcf09 authored / 58ec04c2 +nl. GITHUB
  VERIFIED at the pinned full sha e176cf32b615d09a142b3eccf07b8f493f61617f:
  census 367, the R442 audit present once, wsgrapp.h 9 inlines, the rappel
  modifiers landed (+50/+30, Dex +2), the gap 45 closed / 141 open, the R441
  seed record in place, no wrl hits in the caller TUs. Next after landing: the
  belaying (p. 37).
- R443 landed 2026-10-14: commit 1f0a8d6 (census 368, pushed
  e176cf3..1f0a8d6, preflight GREEN on the FIRST run), the WSG BELAYING,
  printed p. 37 - the belay prose (no table): the climbing-rope intro (150 or
  200 feet, half an inch, the 2000-pound limit, subject to the R440
  weakening/breaking rules; the knot rules - only a rope-use proficient
  character ties a full-strength knot, anyone else loses 500 pounds, different
  diameters take the smaller limit minus 500); the belayer Climbing Check
  (failure = the full fall, success bounded by the rope length); the
  precarious-position jolt second check (failure = both fall) with the
  secure-position exemption (checks 2 vs 1); the paired-belay sequence (last
  cannot belay, leader cannot be belayed, one belay at a time, no climbing
  while belaying, the middle faller drags none below, the failed belayer can
  be saved by the character above, the first faller is unhelpable - only two
  per rope). rules/wsgbelay.h NEW (23 inlines, prefix wbl - checked free in
  all three TUs). Ground truth CLEAN two-way (the user copy OCR vs the djvu
  word layer Guide_0037 with the Guide_0038 head continuation - every number
  matched, no eye-reads). Gap 45/141 -> 46/140; census 367 -> 368. rverify
  GREEN on the FIRST build: 23 mutants, 0 missed. Spec md5s: 1925ade4 authored
  / 66c5e17d +nl. GITHUB VERIFIED at the pinned full sha
  1f0a8d663f9c83344908056e4b283f292b837b70: census 368, the R443 audit present
  once, wsgbelay.h 23 inlines, the belay cells landed (2000/500, checks 2/1,
  jolt 2 fallers), the gap 46 closed / 140 open, the R442 seed record in
  place, no wbl hits in the caller TUs. Next after landing: the grappling
  hooks (p. 38).
- R444 landed 2026-10-14: commit 5e98ed9 (census 369, pushed
  1f0a8d6..5e98ed9, preflight GREEN on the FIRST run), the WSG USE OF
  GRAPPLING HOOKS, printed p. 38 - the hook prose and TABLE 20 GRAPPLING
  SUCCESS: the 1/3-of-strength rounded-up times-10-feet throw (Str 8 = 30
  feet); the horizontal throw doubled from a secure position with a 10-foot
  whirling radius; the one-round throw with the 1d4 re-coil; the 01-05
  self-hit for 1d6; the 3-FOOT climb bonus (the eye-read resolving the OCR
  inch mark to the printed foot mark); Table 20 (the ten terrain rows x the
  protrusion pair and the three catch chances, the last eye-read row 80/90
  with 92/99/99); the solid vs not-solid procedure (solid holds indefinitely,
  not-solid gives way after 1d6 rounds of climbing); the recheck-after-10-feet
  rule. rules/wsggrap.h NEW (31 inlines, prefix wgh - checked free in all
  three TUs). Ground truth THREE-WAY (the djvu garbled at the last Table 20
  row, the strength fraction and the climb bonus; two independent IIIF
  eye-reads per zone matched the user copy exactly). Gap 46/140 -> 47/139;
  census 368 -> 369. rverify GREEN after two authoring-side RED fixes before
  delivery (generator-syntax table_checks the engine cannot emit into C++; a
  missing header_sections entry - both caught by the engine gates, rebuilt
  GREEN): 76 mutants, 0 missed. Spec md5s: 6a33723c authored / 101ca4fb +nl.
  GITHUB VERIFIED at the pinned full sha
  5e98ed94345df88146ff53de9a5cf11161522e43: census 369, the R444 audit present
  once, wsggrap.h 31 inlines, the Table 20 last row landed (80/90 with
  92/99/99 at case 9), the gap 47 closed / 139 open, the R443 seed record in
  place, no wgh hits in the caller TUs. Next after landing: the chasm crossing
  (p. 38).
- R445 landed 2026-10-14: commit a624caf (census 370, pushed
  5e98ed9..a624caf, preflight GREEN on the FIRST run), the WSG CROSSING A
  CHASM ON A ROPE, printed pp. 38-39 - the chasm prose and TABLE 21 THROWN
  LOOP RANGES: the two anchor factors (a protrusion, a hold - the grappling
  hook answers both via Table 20); the thrown loop (thief or rope-use
  proficient only, target directly across or slightly above/below, never on a
  vertical climb); Table 21 (the five level bands 40/50/60/75/90 feet, default
  90 continuing the 17+ band); the 10-foot whirl-radius assumption with the
  halved range otherwise; the 20% base hit with the +1%-per-foot closeness
  bonus (the fog example 17th level at 50 feet = 30%, cross-multiplied); the
  halving conditions (precip, wind over 20 mph, hampered visibility); the
  both-ends-anchored rule with the near-side protrusion; the 30-feet-per-round
  hand-over-hand crossing rate with the +2 Dex check for multiple hangers.
  rules/wsgchasm.h NEW (18 inlines, prefix wcx - checked free in all three
  TUs). Ground truth CLEAN two-way (the user copy OCR vs the djvu word layer
  Guide_0038 with the Guide_0039 head - every number matched, no eye-reads).
  Gap 47/139 -> 48/138; census 369 -> 370. rverify GREEN after one
  authoring-side RED fix before delivery (a table_check with a wrong
  arithmetic anchor - caught by the audit mirror, rebuilt GREEN): 22 mutants,
  0 missed; the DELIVERED spec ran first-try clean on the user side. Spec
  md5s: d8b1f7ca authored / 229d4126 +nl. GITHUB VERIFIED at the pinned full
  sha a624cafc9dba8401f7a2dae80c543e0d9e51583c: census 370, the R445 audit
  present once, wsgchasm.h 18 inlines, the Table 21 ladder landed
  (40/50/60/75/90 with default 90 at case 4), the gap 48 closed / 138 open,
  the R444 seed record in place, no wcx hits in the caller TUs. Next after
  landing: the mountaineering proficiency (p. 39).
- R446 landed 2026-10-14: commit 457a607 (full
  457a6077e44c9da7511638d1857aa4a8d5333954, census 371, pushed
  a624caf..457a607, preflight GREEN on the FIRST run), the WSG THE
  MOUNTAINEERING PROFICIENCY, printed p. 39 - the mountaineer prose (no
  table): the essential tools and skills (pitons - metal spikes pounded into
  cracks for a line anchor, never handholds or footholds; the special hammer,
  a weapon hammer will not do; the placement knowledge only a mountaineer
  has); the mountaineer-led roped ascent (one mountaineer enables the whole
  group on a surface they could not climb, if all are roped together and he
  leads); the piton-as-anchor uses (belayer backup, rappel anchor, chasm tie
  point); the piton loosen rules (a 10% come-loose chance, checked the first
  time it supports 100 pounds or more - pulling the rope does not count; a
  passed check stays lodged until a mountaineer dislodges it; a 10% chance a
  secured piton cannot be dislodged and must be left behind). rules/wsgmntnr.h
  NEW (12 inlines, prefix wmt - checked free in all three TUs). Ground truth
  CLEAN two-way (the user copy OCR vs the djvu word layer Guide_0039 - every
  number matched, no eye-reads). Gap 48/138 -> 49/137; census 370 -> 371.
  rverify GREEN on the FIRST build: 12 mutants, 0 missed; the DELIVERED spec
  ran first-try clean on the user side. Spec md5s: e528319b authored /
  cde774d5 +nl (the user paste hashed to the +nl variant exactly). GITHUB
  VERIFIED at the pinned full sha 457a6077e44c9da7511638d1857aa4a8d5333954:
  census 371, the R446 audit present once with the bad-0 printf, the include
  at line 151, wsgmntnr.h 12 inlines, the gap 49 closed / 137 open flipped
  with the Post-state at R446, the R445 seed record in place, no wmt hits in
  the caller TUs. Next after landing: the slippery horizontal surfaces (p.
  39).
- R447 landed 2026-10-14: commit 8a6f5c9
  (full 8a6f5c9c1c010c04290a8ee0d00e31bd8f
  d3acc8, census 372, pushed 457a607..
  8a6f5c9, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG MOVEMENT ON SLIPPERY
  HORIZONTAL SURFACES, printed p. 39 - the slippery prose (no table): the
  caution/fall rule (a character who does not exercise caution risks slipping
  and falling down - no direct damage, only an indirect cause of greater
  problems to come); the full-rate straight-line rule (no fall risk traveling
  straight); the Dex check on anything other than a very gradual turn or an
  abrupt stop/speed-up; the running rule (a Dex check after every five
  segments, even in a straight line); the half-rate free turn (turns need no
  check at half the full normal movement rate); the full-round speed-change
  exemption (a full round to slow down or speed up, full movement to
  standstill or vice versa, needs no check). rules/wsgslip.h NEW (8 inlines,
  prefix wsl - checked free in all three TUs). Ground truth CLEAN two-way (the
  user copy OCR vs the djvu word layer Guide_0039 - every number matched, no
  eye-reads). Gap 49/137 -> 50/136; census 371 -> 372. rverify GREEN on the
  FIRST build: 8 mutants, 0 missed. Spec
  md5s: b495d1da authored / 39486798 +nl -
  but the user-side file (fetched via bn)
  hashed 1871d1b6 / be4530a1 +nl, NOT the
  authored pair: a delivery-side newline
  variance, harmless (the engine applied the
  same 6 patches and the census/audit mirror
  was clean), but watch it - if the md5
  mismatches again, diff the user-side spec
  against the canvas before the splice.
  (canvas r447-splice). GITHUB VERIFIED at
  the pinned full sha
  8a6f5c9c1c010c04290a8ee0d00e31bd8f
  d3acc8: census 372, the R447 audit present
  once with the bad-0 printf, the include at
  line 152, wsgslip.h 8 inlines, the gap 50
  closed / 136 open flipped with the
  Post-state at R447, the R446 seed record
  in place, no wsl hits in the caller TUs.
  Next after landing: the jumping rules
  with Table 22 (pp. 39-40).
- R448 landed 2026-10-14: commit 55284c8
  (full 55284c825feb42295cddc2dd6c913f364a
  fb3d6b, census 373, pushed 8a6f5c9..
  55284c8, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG JUMPING, printed pp.
  39-40 - the jumping prose and TABLE 22 CHARACTERS' JUMPING ABILITY plus the
  p. 40 modifiers: the any-character rule (thief-acrobats and barbarians
  particularly skilled, but anyone can jump); the four-foot running advantage
  with its 20-foot straight run (no space or time - standing is the best); the
  half-height high jump; the flat-higher-surface roll landing; the
  thin-barrier high jump + Dex check with the 1d3 heap damage at five feet or
  higher and the next-round stand-up; the per-jump die roll (the 4th-level
  1d3=3 example); Table 22 (the seven bands 1-6 through 23+ - standing 1d4+1
  to 1d6+6, running 1d4+5 to 1d6+15, high 1d3 to 1d6+1, each cell split into
  die and plus); the cumulative modifiers (moderate -1, heavy -2 and cannot
  high jump, severe cannot jump at all, halfling -1 broad only, gnome/dwarf -2
  broad and -1 high) with the 2-foot broad and 1-foot high floors.
  rules/wsgjump.h NEW (28 inlines, prefix wjp - checked free in all three
  TUs). Ground truth: the prose CLEAN two-way (the user copy OCR vs the djvu
  word layer Guide_0039/Guide_0040); the Table 22 grid GARBLED in the djvu
  word layer, so every cell was confirmed by TWO independent IIIF eye-reads of
  leaf 39 - the OCR and both eye-reads agree on all 21 cells. Gap 50/136 ->
  51/135; census 372 -> 373. rverify GREEN on the FIRST build: 64 mutants, 0
  missed. Spec md5s: 8369062f authored /
  9edc42c4 +nl - the user-side file hashed
  576de88c / a0bc8674 +nl, the SAME
  delivery-side newline variance as R447
  (second round running; the engine applied
  the same 6 patches with a clean audit
  mirror, so it is cosmetic - but if it
  repeats, diff the bn-fetched spec against
  the canvas before the splice). GITHUB
  VERIFIED at the pinned full sha
  55284c825feb42295cddc2dd6c913f364a
  fb3d6b: census 373, the R448 audit with
  the bad-0 printf at line 49242, the
  include at line 153, wsgjump.h 28
  inlines, the gap 51 closed / 135 open
  flipped with the Post-state at R448, the
  R447 seed record in place, no wjp hits in
  the caller TUs (canvas r448-splice).
  Next after landing: the overland movement
  in reduced visibility with Table 23 (p.
  40).
- R449 landed 2026-10-14: commit 1c7b13c
  (full 1c7b13c9bdb75c5bca54a6a89117b75b
  01690550, census 374, pushed 55284c8..
  1c7b13c, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG OVERLAND MOVEMENT IN
  REDUCED VISIBILITY, printed pp. 40-41 - the visibility prose and TABLE 23
  MOVEMENT IN REDUCED VISIBILITY: the daylight assumption behind the
  previously described rates; the other-factors-first multiplication
  (encumb-rance, terrain, climbing applied to determine the current normal
  rate, THEN multiplied by the table entry; the 1/1 clear-daylight cell means
  no further reduction); the on-foot daylight hazard avoidance (no trees, no
  roots) with the night exception (a pit or cliff edge unless the surface is
  tested or probed with a pole); the infravision heat-only detection (a
  warm-blooded ambush yes, a cliff edge usually no); the Dex check above the
  maximum safe speed with the blunder/stop-short consequences (saddle, wagon
  seat, chariot front) and the twice-the-figure cap; Table 23 (the three light
  rows - daylight, moonlight, darkness - x the five conditions - clear,
  moderate fog, heavy fog or snow, heavy snow with wind, blowing sand or dust
  - from 1/1 down to 1/8, each cell split into numerator and denominator).
  rules/wsgvis.h NEW (21 inlines, prefix wsv - checked free in all three TUs).
  Ground truth: the prose CLEAN two-way (the user copy OCR vs the djvu word
  layer Guide_0040/Guide_0041 - the 2x cap and the 1/8 sandstorm-in-darkness
  example matched); the Table 23 grid GARBLED in the djvu word layer, so every
  cell was confirmed by TWO independent IIIF eye-reads of leaf 40 - the OCR
  and both eye-reads agree on all 15 fractions. Gap 51/135 -> 52/134; census
  373 -> 374. rverify GREEN after TWO authoring-side RED fixes before delivery
  (the monotonic row checks had the cross-multiplication inverted - caught by
  the audit mirror, rebuilt GREEN): 41 mutants,
  0 missed. Spec md5s: 9b9d6d0a authored /
  d5a0467c +nl - the user-side file hashed
  df55d840 / 9c41bb63 +nl, the delivery-side
  newline variance now THREE rounds running
  (R447-R449; cosmetic every time - the same 6
  patches, clean mirror; diagnose the bn
  fetch at the next mismatch). GITHUB VERIFIED
  at the pinned full sha
  1c7b13c9bdb75c5bca54a6a89117b75b
  01690550: census 374, the R449 audit with
  the bad-0 printf at line 49374, the include
  at line 154, wsgvis.h 21 inlines, the gap
  52 closed / 134 open flipped with the
  Post-state at R449, the R448 seed record in
  place, no wsv hits in the caller TUs
  (canvas r449-splice). Next after landing:
  the swimming rules with Table 24 (pp.
  41-42).
- R450 landed 2026-10-14: commit 657c7fc
  (full 657c7fc5d874d20bb53dc50d147534efe
  f19460d, census 375, pushed 1c7b13c..
  657c7fc, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG SWIMMING, printed p. 41 -
  the intro, TABLE 24 EFFECTS OF ENCUMBRANCE ON SWIMMING, and the Endurance
  and Speed subsections: the proficiency gate (only proficient swimmers propel
  themselves; the nonproficient do not simply sink - the section covers
  swimming and treading water); the three sub-skills (endurance, speed,
  diving) with encumbrance as the most important factor for any swimmer; Table
  24 (the five encumbrance rows x the four functions - none x2, light the
  baseline, moderate halves with the doubled dive, heavy quarters with the
  tripled dive, severe the dash everywhere but the tripled dive); the dash
  means impossible (severe sinks in water deeper than his height, cannot
  surface without dropping encumbrance); the endurance rules (base in turns =
  levels + constitution, the 3-turns-per-rest-turn rate, the doubled
  high-speed rate with the 1/10 endurance cut rounded up, the one-for-one
  high-speed recovery, the 18-turn 6th-level-thief-con-12 example); the speed
  rules (humans 40 feet per round, other races 30, monster stats supersede,
  the 2/3 subsurface cut rounded up, the strength ladder +1/+2/+3 inches, the
  light 1-3 and strong 4-6 current modifiers, the 0-inch hold position at
  endurance cost, the mercy-of-the-current backward drift 1-3 inches, the
  DM-determined currents with the gentle 1-2 and mountain 5-6 examples, the
  surface-only high speed halved at a 0 rate). rules/wsgswim.h NEW (38
  inlines, prefix wsm - the FIRST CHOICE wsw was TAKEN by the R429 hurricane
  pins; wsm checked free in all three TUs). Ground truth: the
  intro/Endurance/Speed prose CLEAN two-way (the user copy OCR vs the djvu
  word layer Guide_0041 - every number matched); the Table 24 grid and the
  strength/current modifier table GARBLED in the djvu word layer, so every
  cell was confirmed by TWO independent IIIF eye-reads of leaf 41 - the OCR
  and both eye-reads agree on all 20 Table 24 cells and all seven modifier
  rows. Gap 52/134 -> 53/133; census 374 -> 375. rverify GREEN on the FIRST
  build: 70 mutants, 0 missed. Spec md5s: 0575b256
  authored / d3de318b +nl - the user-side file
  hashed 759aaf3e / bfdaa64c +nl, the
  delivery-side newline variance FOUR rounds
  running (R447-R450; cosmetic every time -
  the same 6 patches, clean mirror; diagnose
  the bn fetch at the next mismatch).
  GITHUB VERIFIED at the pinned full sha
  657c7fc5d874d20bb53dc50d147534efe
  f19460d: census 375, the R450 audit with
  the bad-0 printf at line 49529, the
  include at line 155, wsgswim.h 38
  inlines, the gap 53 closed / 133 open
  flipped with the Post-state at R450, the
  R449 seed record in place, no wsm hits in
  the caller TUs (canvas r450-splice).
  Next after landing: the other effects of
  moving water (p. 42), then the diving and
  surfacing rules and the treading water.
- R451 landed 2026-10-14: commit 94d5631
  (full 94d5631ce3b4e551a5a11435b34da6671
  5fbe95e, census 376, pushed 657c7fc..
  94d5631, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG OTHER EFFECTS OF MOVING
  WATER, printed p. 42 - the rough-water prose (no table): the 1-10 stream
  hazard rating (1 the most hazardous; the number = the rounds before a
  proficiency check - rating 1 checks every round, rating 5 checks rounds 1,
  6, 11 and every fifth round thereafter); the 1d6 buffeting damage on a
  failed check; the virtually helpless nonproficient swimmer at 1d3 damage per
  round; the grab-a-protrusion halt (a Dex check, a new attempt every round,
  then a Strength check every two rounds to stay attached - failure sweeps him
  downstream); the waterfall rules (40 feet or more = half normal free-fall
  damage, a save vs breath weapon allowed - success at 40-100 feet = no
  damage, success beyond 100 feet = one-tenth rounded up, under 40 feet = no
  falling damage, treated as a normal dive; rocks at the base void the mercy -
  damage assessed as a fall through the air). rules/wsgmwater.h NEW (20
  inlines, prefix wmw - checked free in all three TUs). Ground truth CLEAN
  two-way (the user copy OCR vs the djvu word layer Guide_0042 - every number
  matched, no eye-reads). Gap 53/133 -> 54/132; census 375 -> 376. rverify
  GREEN on the FIRST build: 20 mutants, 0 missed. Spec md5s: e4cce91b
  authored / c402102b +nl - the user-side file
  hashed ff222b09 / fd3b03ce +nl, the
  delivery-side newline variance FIVE rounds
  running (R447-R451; cosmetic every time -
  the same 6 patches, clean mirror; diagnose
  the bn fetch at the next mismatch).
  GITHUB VERIFIED at the pinned full sha
  94d5631ce3b4e551a5a11435b34da6671
  5fbe95e: census 376, the R451 audit with
  the bad-0 printf at line 49614, the
  include at line 156, wsgmwater.h 20
  inlines, the gap 54 closed / 132 open
  flipped with the Post-state at R451, the
  R450 seed record in place, no wmw hits in
  the caller TUs (canvas r451-splice).
  Next after landing: the diving and
  surfacing rules (p. 42), then the treading
  water.
- R452 landed 2026-10-14: commit 8a59b1e
  (full 8a59b1e73bcde4301a2b9bd8254c819747
  1d44f0, census 377, pushed 94d5631..
  8a59b1e, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG DIVING AND SURFACING,
  printed p. 42
  SURFACING, printed p. 42 - the base downward swim
  rate 2 inches / 20 feet per round, doubled for
  moderately encumbered and tripled for heavily or
  severely encumbered characters (the same x2/x3/x3
  the Table 24 dive column carries), the
  leap-height extra-depth ladder (at least
  5/15/25/35/40 feet -> 1/2/3/4/5 inches on the
  first round of a dive), the 5-inch cap beyond 40
  feet regardless of height, and the
  falling-damage risk on a dive from 40 feet or
  more per the waterfall text. rules/wsgdive.h NEW
  (14 inlines: 7 consts + 5 bools + the 2-column
  table, prefix wdv - checked free in all three
  TUs). Ground truth CLEAN three-way: the user copy
  OCR (page 43) vs the djvu word layer Guide_0042 -
  the prose matched, but the djvu GARBLES the
  printed table (the 35-feet row reads "36 feet",
  the 40-feet row is mangled), so the ladder was
  settled by TWO independent IIIF eye-reads of leaf
  $42, which agree with the OCR exactly:
  5/15/25/35/40 -> 1/2/3/4/5. Gap 54/132 -> 55/131;
  census 376 -> 377. rverify GREEN on the FIRST
  build: 22 mutants, 0 missed (one RED build
  iteration on the author side: a cross-round
  example referencing wsmDiveNum was dropped - the
  engine's python-side model m knows only the
  round's own names; the Table 24 agreement lives in
  the audit comment). Spec md5s: d01492ce
  authored / 7f45249b +nl - the user-side file
  hashed 9baf38fe / a1e2369b +nl, the
  delivery-side newline variance SIX rounds
  running (R447-R452; cosmetic every time - the
  same 6 patches, clean mirror; diagnose the bn
  fetch at the next mismatch).
  GITHUB VERIFIED at the pinned full sha
  8a59b1e73bcde4301a2b9bd8254c819747
  1d44f0: census 377, the R452 audit with
  the bad-0 printf at line 49726, the
  include at line 157, wsgdive.h 14
  inlines, the gap 55 closed / 131 open
  flipped with the Post-state at R452, the
  R451 seed record in place, no wdv hits in
  the caller TUs, and the engine re-run on
  the landed tree reads applied 0 /
  already 6 (canvas r452-splice).
  Next after landing: the treading water (p. 43),
  then the drowning rules.
- R453 landed 2026-10-14: commit 8bda29f
  (full 8bda29f18f1a01cac45adaf3cf1f128
  3bd498458, census 378, pushed 8a59b1e..
  8bda29f, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG TREADING WATER,
  printed p. 43 - the proficient calm-water hold (a
  number of turns equal to TWICE the endurance
  score, one endurance point per two turns), the
  nonproficient limit (rounds equal to the
  STRENGTH score, modified for encumbrance the
  same way a swimmer's endurance is modified), the
  expiry checks (a Strength Check at expiration
  and every round thereafter, cumulative +1 after
  the first, per the printed 6-strength/12-round
  example - the strength limit doubled by the
  unencumbered endurance multiplier, +1 at the
  13th round, +2 at the 14th), and the current
  rules (carried at the current speed modified
  for encumbrance just as for swimming movement,
  the proficient hold-position effectively
  swimming with endurance assessed, the
  nonproficient sinking immediately if he
  resists). rules/wsgtread.h NEW (15 inlines: 6
  consts + 9 bools, prefix wtw - checked free in
  all three TUs). Ground truth CLEAN two-way
  (the user copy OCR page 44 vs the djvu word
  layer Guide_0043 - every number matched, the
  only djvu garbles the section header and word
  breaks, no eye-reads needed). Gap 55/131 ->
  56/130; census 377 -> 378. rverify GREEN on
  the FIRST build: 15 mutants, 0 missed. Spec
  md5s: 7445288f authored / 47290237 +nl -
  the user-side file hashed 048a40bf /
  63780cdc +nl, the delivery-side newline
  variance SEVEN rounds running (R447-R453;
  cosmetic every time - the same 6 patches,
  clean mirror; diagnose the bn fetch at the
  next mismatch).
  GITHUB VERIFIED at the pinned full sha
  8bda29f18f1a01cac45adaf3cf1f128
  3bd498458: census 378, the R453 audit with
  the bad-0 printf at line 49786, the
  include at line 158, wsgtread.h 15
  inlines, the gap 56 closed / 130 open
  flipped with the Post-state at R453, the
  R452 seed record in place, no wtw hits in
  the caller TUs, and the engine re-run on
  the landed tree reads applied 0 /
  already 6 (canvas r453-splice).
  Next after landing: the holding one breath
  (p. 43), then the drowning rules.
- R454 landed 2026-10-14: commit e0a5480
  (full e0a5480bcf6711eca0f55319809bbc5a
  62809a03, census 379, pushed 8bda29f..
  e0a5480, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG HOLDING ONE'S
  BREATH, printed p. 43 - the surfacing rate (2
  inches like the diving rate, doubled for the
  unencumbered, reduced for moderate/heavy, and
  needing ACTIVE work; the inert body rises by
  natural buoyancy at one-half inch, 5 feet per
  round, modified for encumbrance; the
  deliberate-encumbrance dive-and-divest trick),
  the non-cumulative diving-bonus note (the leap
  extra depth added AFTER encumbrance, per the
  6-inch moderately-encumbered 15-foot-leap
  example), the breath formula (rounds equal to
  ONE-THIRD of constitution, rounded up, deep
  breath assumed, no strenuous activity, normal
  movement and chest-opening/secret-passage/
  spellcasting allowed), the halved penalties for
  unprepared and for strenuous activity
  (cumulative to ONE-FOURTH, with the one-round
  floor), the expiration rules (a Constitution
  Check once per round, cumulative +2 after the
  first, per the con-12/4-round example - first
  check at the end of the 5th round, +2 at the
  6th, +4 at the 7th), the buoyancy-only
  non-swimmer surfacing, the out-of-air
  unconsciousness with the pulled-to-surface
  requirement, the not-underwater ONE-ROUND
  addition with the penalties applied after, and
  the hold-before-affected gas rules (a small
  dose as harmful as an extended one).
  rules/wsgbreath.h NEW (31 inlines: 13 consts
  + 18 bools, prefix whb - checked free in all
  three TUs). Ground truth CLEAN two-way (the
  user copy OCR page 44 vs the djvu word layer
  Guide_0043 - every number matched; the djvu
  garbles only the one-third fraction glyph
  itself, corroborated by the printed con-12 ->
  4-round example arithmetic; no eye-reads
  needed). Gap 56/130 -> 57/129; census 378 ->
  379. rverify GREEN on the FIRST build: 31
  mutants, 0 missed. Spec md5s: 201df1df
  authored / e7a704b7 +nl - the user-side file
  hashed a05e8356 / e1d546db +nl, the
  delivery-side newline variance EIGHT rounds
  running (R447-R454; cosmetic every time - the
  same 6 patches, clean mirror; diagnose the bn
  fetch at the next mismatch).
  GITHUB VERIFIED at the pinned full sha
  e0a5480bcf6711eca0f55319809bbc5a
  62809a03: census 379, the R454 audit with
  the bad-0 printf at line 49878, the
  include at line 159, wsgbreath.h 31
  inlines, the gap 57 closed / 129 open
  flipped with the Post-state at R454, the
  R453 seed record in place, no whb hits in
  the caller TUs, and the engine re-run on
  the landed tree reads applied 0 /
  already 6 (canvas r454-splice).
  Next after landing: the movement in waterborne
  vehicles (p. 44), then the capsizing and damage
  to craft.
- R455 landed 2026-10-14: commit eef7ebb
  (full eef7ebb219e862a96bed251965f65
  15c7015550d, census 380, pushed e0a5480..
  eef7ebb, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG MOVEMENT IN
  WATERBORNE VEHICLES, printed p. 44 (with the
  movement-modification prose continuing onto
  p. 45) - Table 25, the eight inland vessels
  (kayak, small canoe, small rowboat, coracle,
  large canoe, large rowboat, small barge,
  large barge) across length, width, the
  passenger+gold capacity, the four large-scale
  miles-per-half-day and four small-scale
  feet-per-round rates (sail/oar, normal/max),
  the encumbrance ranges (the large barge open
  10000+ encoded as a 0-max sentinel), the
  startup and hull ranges and the draughts;
  plus the modifications (the current
  drift/add/subtract, the 20-30 mph wind band
  with -1/+2 per 10 mph, the 5 mph no-sail
  floor, the right-angle max sail, the
  into-wind 3-inch reduction to the 1-inch
  minimum, the max-oar exertion ladder - two
  turns on, one off, fatigued half speed,
  forced one-turn exhaustion - and the
  shorthanded proportional rowing with the
  3-rowers large-rowboat example: 6 of 8
  miles, 45 of 60 feet). rules/wsgvessels.h NEW
  (55 inlines: 17 consts + 16 bools + the
  22-column grid split into Table 25a the
  characteristics / 25b the rates, prefix wvb -
  checked free in all three TUs). Ground
  truth CLEAN three-way: the prose matched the
  user copy OCR (pages 45-46) vs the djvu word
  layer (Guide_0044/0045), but the djvu
  TRUNCATES Table 25 (six of eight rows, the
  draught column garbled), so the grid was
  settled by TWO independent IIIF eye-reads of
  leaf $44 (1600px PNG - the 2400 scale is
  capped for this leaf), which agree with the
  OCR exactly on all eight rows and every cell.
  Gap 57/129 -> 58/128; census 379 -> 380.
  rverify GREEN: 209 mutants, 0 missed (the
  biggest battery yet) - three build
  iterations: the 22-column row literal broke
  the 78-col audit bound (split into 25a/25b
  with distinct C-array tags), then a bogus
  draught cross-multiplication (a third is NOT
  a half) and a broken replacement clause were
  fixed. Spec md5s: 2d325067 authored /
  b05c0189 +nl - the user-side file hashed
  36230c3e / 766d0d9b +nl, the delivery-side
  newline variance NINE rounds running
  (R447-R455; cosmetic every time - the same 6
  patches, clean mirror; diagnose the bn fetch
  at the next mismatch).
  GITHUB VERIFIED at the pinned full sha
  eef7ebb219e862a96bed251965f65
  15c7015550d: census 380, the R455 audit
  with the bad-0 printf at line 50105, the
  include at line 160, wsgvessels.h 55
  inlines with both the C25a/C25b grids
  landed, the gap 58 closed / 128 open
  flipped with the Post-state at R455, the
  R454 seed record in place, no wvb hits in
  the caller TUs, and the engine re-run on
  the landed tree reads applied 0 /
  already 6 (canvas r455-splice).
  Next after landing: the capsizing and damage
  to craft (Table 26, p. 45), then the boating
  proficiency and the portaging.
- R456 landed 2026-10-14: commit ecda891
  (full ecda8918fb75f7b49d594a4757ce39d5
  ce436a28, census 381, pushed eef7ebb..
  ecda891, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG CAPSIZING AND
  DAMAGE TO CRAFT, printed p. 45 - Table 26, the
  chance of capsizing (the eight vessels x the
  four wind/water conditions: kayak 25/40/60/
  80, small canoe 20/35/50/75, small rowboat
  5/15/30/50, coracle 10/20/30/50, large canoe
  10/20/30/40, large rowboat 0/10/25/40, small
  barge 0/5/10/20, large barge 0/0/5/10), the
  check triggers (entering/leaving the boat,
  abrupt movement, DM discretion), the
  under-sail +20 wherever the base exceeds
  zero, the condition bands (mild: wind 15 mph
  or less and current 3 inches or less;
  moderate: wind 16-30 or current to 6;
  dangerous: wind 31-50 or current to 9;
  severe: wind beyond 50 or current 9-plus),
  the boating-proficiency assumption, and the
  mast/sail damage rules (the 40 mph
  threshold, the percentage chance equal to
  the wind velocity, the 30% furled-sail
  reduction, the poor-rigging upward
  adjustment, the hourly check).
  rules/wsgcapsizing.h NEW (32 inlines: 16
  consts + 12 bools + the 4-column grid,
  prefix wcp - checked free in all three
  TUs). Ground truth CLEAN three-way: the
  prose matched the user copy OCR (page 46)
  vs the djvu word layer (Guide_0045), but
  the djvu TRUNCATES the Table 26 large barge
  row (the severe cell cut at the page
  break), so the grid was settled by TWO
  independent IIIF eye-reads of leaf $45,
  which agree with the OCR exactly on all
  eight rows - the large barge severe cell
  reads 10%. Gap 58/128 -> 59/127; census
  380 -> 381. rverify GREEN: 60 mutants, 0
  missed - one build iteration: the barge
  ladder is 0/0/5/10, NOT a strict step up
  (two zeros), so the monotonicity check was
  loosened to non-strict for the barge while
  the kayak stays strict. Spec md5s: 6922656
  39d51c9031ff4b58e84961087 user-side /
  dcc38c0a8f4181a5df421d7712b66b1b +nl,
  vs be6cea2b authored / 9992fc08 +nl
  (canvas r456-splice) - the delivery-side
  newline variance again, TEN rounds running
  (R447-R456), cosmetic every time; diagnose
  the bn fetch at the next mismatch. Base sha
  eef7ebb219e862a96bed251965f6515c7015550d.
  GITHUB VERIFIED at ecda8918fb75f7b49d594a
  4757ce39d5ce436a28: census 381, the R456
  audit line present, the wsgcapsizing.h
  include at line 161, 32 wcp inlines, the
  gap box [x] flipped, Post-state at R456
  once, the R455 seed record in place, no
  wcp hits in the caller TUs, and the engine
  re-run on the landed tree reads applied 0 /
  already 6 (canvas r456-splice).
  Next after landing: the boating proficiency
  (p. 45), then the portaging.
- R457 landed 2026-10-14: commit 9dbb69e
  (full 9dbb69e26002d1fc8a9473d12d0f1
  a5feb71577, census 382, pushed ecda891..
  9dbb69e, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG THE BOATING
  BOATING PROFICIENCY, printed p. 45 - a
  pure-prose round (no printed grid): the
  nonproficient movement penalties (the
  kayak, small canoe and coracle reduced to
  one-half of normal; the small rowboat,
  large canoe, large rowboat and small barge
  to two-thirds; the large barge to
  three-quarters), applied BEFORE the wind
  and current alterations; the capsize
  penalty (+25% where the base chance is
  greater than 0%, capped at 100%); the
  proficient-crew benefits (the -20% capsize
  per proficient character after the first,
  the -20% mast/sail damage reduction where
  they can secure the rigging or brace the
  mast, the all-proficient waiver of the
  movement penalties) and the sail-crew
  minimums (two characters for the large
  rowboat, small barge and large barge, one
  for all the rest). rules/wsgboat.h NEW
  (18 inlines: 6 consts + 9 bools + the
  synthesized 3-column grid - the
  movement-fraction num/den and the sail
  crew for the eight vessels, C27 - prefix
  wbp, checked free in all three TUs).
  Ground truth CLEAN two-way: the prose
  matched the user copy OCR (page 46) vs
  the djvu word layer (Guide_0045) - NO
  eye-reads needed (no printed table).
  Gap 59/127 -> 60/126; census 381 -> 382.
  rverify GREEN: 39 mutants, 0 missed.
  Spec md5s: 5e6328d2c2edaa3349975d7e0
  5653159 user-side / 4fd32208905f52f765a
  65e7feb815e66 +nl, vs cd29ed00 authored /
  5e6328d2 +nl (canvas r457-splice) - the
  delivery-side newline variance again,
  ELEVEN rounds running (R447-R457),
  cosmetic every time (this round the
  user-side FILE hash matches the authored
  +nl hash exactly, the +nl variant drifts);
  diagnose the bn fetch at the next
  mismatch. Base sha
  ecda8918fb75f7b49d594a4757ce39d5ce436a
  28. GITHUB VERIFIED at 9dbb69e26002d1fc
  a9473d12d0f1a5bfeb71577: census 382, the
  R457 audit line present, the wsgboat.h
  include at line 162, 18 wbp inlines, the
  gap box [x] flipped, Post-state at R457
  once, the R456 seed record in place, no
  wbp hits in the caller TUs, and the
  engine re-run on the landed tree reads
  applied 0 / already 6 (canvas r457-splice).
  Next after landing: the portaging
  (p. 45), then the use of a capsized
  vessel (p. 46).
- R458 landed 2026-10-14: commit 24b84d5
  (full 24b84d5b61a1159579f63619af834
  b9323c49a29, census 383, pushed 9dbb69e..
  24b84d5, preflight GREEN on the FIRST run,
  the splice double-run clean: applied 6 /
  already 6), the WSG PORTAGING, printed pp. 45-46 (spans the
  page break) - a pure-prose round (no
  printed grid): the solo-portage gate (a
  vessel smaller than a large rowboat can
  be portaged by one character able to
  support its encumbrance without becoming
  severely encumbered); the severe-
  encumbrance bar (severely encumbered
  characters cannot portage or help to
  portage); the portage-crew minimums and
  twice-minimum maximums (one and two
  below the large rowboat, two and four
  for the large rowboat and small barge,
  four and eight for the large barge; a
  third carrier beyond the maximum is of
  no use - the small-canoe example); and
  the portage move rate (3 inches, 3
  miles in eight hours, 30 feet per
  round, regardless of terrain or overall
  encumbrance status). rules/wsgportage.h
  NEW (16 inlines: 6 consts + 8 bools +
  the synthesized 2-column portage-crew
  grid C28, prefix wpg, checked free in
  all three TUs). Ground truth CLEAN
  two-way: the user copy OCR (pages
  46-47) vs the djvu word layer
  (Guide_0045/0046) - the djvu garbles
  only the page-break solo clause, which
  the OCR reads whole and the continuation
  text confirms; NO eye-reads needed.
  Gap 60/126 -> 61/125; census 382 -> 383.
  rverify GREEN: 30 mutants, 0 missed.
  Spec md5s: 4089b5be60b8d1ffb4e695340d
  53f77c user-side / 25744b106ccc627e361755
  22000df386 +nl, vs 46e1f794 authored /
  4089b5be +nl (canvas r458-splice) - the
  delivery-side newline variance again,
  TWELVE rounds running (R447-R458),
  cosmetic every time (as in R457, the
  user-side FILE hash matches the authored
  +nl hash exactly, the +nl variant
  drifts); diagnose the bn fetch at the
  next mismatch. Base sha
  9dbb69e26002d1fc8a9473d12d0f1a5feb
  71577. GITHUB VERIFIED at 24b84d5b61a
  1159579f63619af834b9323c49a29: census
  383, the R458 audit line present, the
  wsgportage.h include at line 163, 16
  wpg inlines, the gap box [x] flipped,
  Post-state at R458 once, the R457 seed
  record in place, no wpg hits in the
  caller TUs, and the engine re-run on
  the landed tree reads applied 0 /
  already 6 (canvas r458-splice).
  Next after landing: the use of a
  capsized vessel (p. 46), then the flying
  mounts (p. 47).
- R459 landed 2026-10-14: commit 5018a21
  (full 5018a21a1136fa30a8349a0f4
  4370746fdd6f366, census 384, pushed
  24b84d5..5018a21, preflight GREEN on
  the clean-run THIRD attempt, the splice
  double-run clean: applied 6 /
  already 6), the WSG USE OF A
  CAPSIZED VESSEL, printed p. 46 - a
  pure-prose round (no printed grid):
  the natural buoyancy (most vessels
  remain afloat just beneath the surface
  after capsizing or hull damage); the
  flotation preconditions (carrying no
  passengers and not more than 10% of
  the listed maximum cargo capacity,
  with the small-rowboat example - toss
  all but 200 gp worth and the foundering
  craft sinks to slightly beneath the
  surface and remains); the cling-to-the-
  sides flotation (usable as long as the
  weight is evenly distributed); the
  twice-capacity support figure (eight
  characters around a large rowboat of
  normal capacity four); and the sink
  rules (exceeding the weight limit or
  uneven distribution sinks the craft
  too far below to be usable).
  rules/wsgcapsized.h NEW (13 inlines:
  5 consts + 8 bools, prefix wcv,
  checked free in all three TUs). Ground
  truth CLEAN two-way: the user copy OCR
  (page 47) vs the djvu word layer
  (Guide_0046) - NO eye-reads needed.
  The numbers cross-check against the
  R455 Table 25 pin: the small rowboat
  2000 gp cargo maximum gives the 10%
  = 200 gp example, and the large
  rowboat capacity 4 gives the twice-
  capacity 8. Gap 61/125 -> 62/124;
  census 383 -> 384. rverify GREEN:
  13 mutants, 0 missed. REPAIRED before
  landing: the first spec carried
  Python-style '!= True' in two example
  exprs - clean in the Python audit
  mirror (True is valid Python) but
  invalid C++ (5 undeclared-identifier
  errors), caught by the user preflight
  RED, nothing committed; fixed to
  '!= 1' (valid both sides), tree
  reverted, double-run and rverify
  re-run clean. Lesson: NEVER use
  Python True/False in example exprs -
  use != 1 / == 0. Spec md5s:
  f9b1a666c5c7fd2900d9777d8b2549f4
  user-side / 840ec2eefee2a1a5b9909c13
  7c961d77 +nl, vs 98403989 authored /
  f9b1a666 +nl (canvas r459-splice) -
  the delivery-side newline variance
  again, THIRTEEN rounds running
  (R447-R459), cosmetic every time (as
  in R457/R458, the user-side FILE hash
  matches the authored +nl hash exactly,
  the +nl variant drifts). Base sha
  24b84d5b61a1159579f63619af834b932
  3c49a29. GITHUB VERIFIED at 5018a21a
  1136fa30a8349a0f44370746fdd6f366:
  census 384, the R459 audit line
  present, the wsgcapsized.h include at
  line 164, 13 wcv inlines, the gap box
  [x] flipped, Post-state at R459 once,
  the R458 seed record in place, NO True
  tokens in the landed wcv audit block,
  no wcv hits in the caller TUs, and the
  engine re-run on the landed tree reads
  applied 0 / already 6 (canvas
  r459-splice). Next after landing: the
  flying mounts (p. 47), then the to
  fall or not to fall (p. 48).
- R460 landed 2026-10-14: commit 10c968e (full
  10c968e20a8decdae84d73d14f584d8fd4104f51, census 385, pushed
  5018a21..10c968e), the WSG FLYING MOUNTS, printed p. 47 - Table 27 in four
  category grids (41 creatures x 7 columns: the normal and maximum loads with
  the dash as max = normal, the full and reduced move rates, the MC on the
  A=1..E=5 scale, the safe-turns/rest stamina pair), the column definitions
  (the plummet rule, the single-rate 0 marker, the MC drop when ridden with E
  unreducible, the over-load stamina cut), the solid-form footnote, the
  listing criteria, the training and willingness rules, the triple-to-fifty
  rations feeding and the even-distribution encumbrance with the 2:1 doubling.
  rules/wsgflymounts.h NEW (60 inlines, prefix wfm, checked free in all three
  TUs). Gap 62/124 -> 63/123; census 384 -> 385. The next round closes Chapter
  5: the fall chance and the airborne riding proficiency on printed pp. 48-49.
- R461 landed 2026-10-14: commit 1745169 (census 386, pushed
  cf8c4a5..1745169, preflight GREEN first run), the WSG CHAPTER 5 CLOSER - the
  airborne fall chance (printed p. 48) and the proficiency in airborne riding
  (printed p. 49) in one round, rules/wsgfallair.h NEW (31 inlines: 20 consts
  + 11 bools, prefix wfa, checked free in all three TUs), both gap items
  flipped in one commit (gap 63/123 -> 65/121). Ground truth clean two-way
  (the 8d6a65a0 OCR pages 49-50 vs the second OCR copy, the sign convention
  pinned by the p. 49 text: the -50% proficiency negates the +50% hands-free).
  rverify GREEN: 31 mutants, 0 missed; the double-run 7/0 then 0/7 on Termux
  with the md5 pair hit exactly. The next rounds open the food and water
  chapter: going without food, Table 28 and the water requirements (printed
  pp. 50-53).
## Knowledge maintenance

- Each land appends ONE entry to Round state above (date,
  commit, census, what landed, the lessons) - terse; the repo
  carries the code and the gap reports.
- When this file balloons past ~100KB, run the fresh start
  again (v3): backup + seed + continuation prompt saved to
  doc/vibe/ with a v3 suffix and committed BEFORE wiping
  knowledge and chats - the v2 process is the template.

## Tooling (R428, 2026-10-14)
- The splice engine landed: tools/splice_engine.py + speclib.py + rverify.py. A round is now a JSON spec run through the engine; the battery derives from the spec. Future splices insert records above as usual.
