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
- R462 landed 2026-10-15: commit 56ac395 (census 387, pushed 1745169..56ac395,
preflight GREEN first run, the double-run 12/0 then 0/12), the WSG FOOD AND
WATER chapter opener, printed pp. 50-53 - going without food (the Table 28
4/5/6/7/8/10-day ladder, the 12-hour checks with the cumulative +1 then the +2
weakened shift, the weakened/distressed/incapacitated ladder with the
-1-per-day worsening, the two-step eating recovery, the -4 floor, the two-day
two-meal incapacitation recovery), going without water (the 3-day base, the
cumulative modifier set with the one-day floor, the total-deprivation
immediate incapacitation), the effects on animals (halved move and carry, the
3-turn hard-work incap, the 1.5x tolerance multiple, the 1-turn and 1-day
death rules, the 13-24-hour 1d12+12 recovery), the minimum daily requirement
of food (the 1-2 lb human ration with the 3/4 elf and 1/2 small-race
fractions, the pack arithmetic, the 1:2 meat-vegetable ratio, the two-meal
cadence, the half-ration cheat) and of water (the Table 29 4x4 pint grid, the
1/4 elf and 1/3 demihuman reductions, the 1/4-1/3 high-water-food credit, the
1/2/4-hour activity thresholds, the 7-gallon cubic foot, the waterskin and
encumbrance arithmetic). rules/wsgfood.h NEW (101 inlines: 76 consts + 17
bools + 2 chains + 6 table columns, prefix wnf, checked free in all three
TUs). Ground truth three-way (the Drive PDF OCR vs djvu vs the IIIF eye-reads;
both text layers garble Table 28 - the eye-read settled the ladder, confirmed
by the book example). Gap 65/121 -> 72/114; census 386 -> 387. rverify GREEN:
124 mutants, 0 missed; the Termux md5 hit the +nl pair value exactly. Next:
R463 - food gathering, foraging, Table 30 and the inedible plants (printed pp.
53-54).
- R463 LANDED 2026-10-15: commit 86421cd (census 388, pushed
  56ac395..86421cd), the WSG FOOD GATHERING AND FORAGING slice, printed pp.
  53-54 - foraging (the two-turn check, the 2-lb ration, the proficient 2-in-2
  or 1-in-1, the -20 inedible shift, the four-turn search limit with the
  2-normal/4-proficient checks, the one-mile move-on), Table 30 (all 132
  cells: the five climate-region grids, Arctic five terrains, the others
  seven, the chance/inedible pair per season) and the inedible plants (the 1d8
  dispatch: 1 poisonous with the 1d10-round onset, 2d10-turn cramps, 1d4
  hp/turn, the 1d4/hour rest-plus-water regain, the save halves, slow poison
  stacks to one-fourth, neutralize halts but no prior damage; 2-4 tainted
  half-strength 1d10 rounds/turns 1d2 hp/turn; 5-8 no food value). The
  when-not-to-use-the-table judgment pins as bools. rules/wsgforage.h NEW (83
  inlines: 28 consts + 14 bools + 1 chain + 40 table columns, prefix wfg,
  checked free in all three TUs). GROUND TRUTH: the biggest OCR fight of the
  arc - the two text layers (djvu vs pdfy) disagree or drop the Tem-F winter,
  St-P/Se/Sw winter, Tro-M winter and Tro-Se spring cells and both garble the
  Arctic P/Se rows; the pixels settled everything: a full native decode of
  leaf 0053 (a pure-Python JPEG decoder, 2432x3194), then vision reads of
  contrast-stretched cell crops (which exposed a band-map off-by-one-group -
  the blank slots were region label lines), then a glyph-level NCC classifier
  over same-page font templates (LOO 62/62, the disputed digits at 0.83-0.94):
  Tem-F W 80/40, St-P W 80/30, St-Se W 80/40, St-Sw W 40/60, Tro-M W 85/30,
  Tro-Se Sp/Au 95/50 (djvu 96 wrong), Arc-P 5/50-5/50-10/50-5/50, Arc-Se
  10/75-10/50-15/50-10/75, St-H 80/30-90/30-100/25-95/25. FIRST PREFLIGHT RED
  - no commit: all five Table 30 grids shared tag 30 and the engine derives
  the audit array name from the tag, so it emitted five int C30[][] in one
  scope; fixed by distinct tags 30A-30E. STANDING AUTHORING RULE: a
  multi-table round MUST use distinct per-table tags. NOTE: the user git add
  -A swept the previously untracked spec JSONs (spec_r429 through spec_r463)
  and the bn launcher INTO the commit (40 files) - the specs are now tracked
  in the repo; the R429 untracked-specs convention is superseded by user
  action. Gap 72/114 -> 76/110 (FOUR box flips + the post-state line); census
  387 -> 388. Verified at the raw sha 86421cd: the include after wsgfood.h,
  wsgforage.h 83 inlines, the four flips with the R463 text, the post-state
  76/110, the R462 seed record in place. Next: R464 - hunting, stalking a
  wounded animal and Table 31 (printed p. 55).
- R464 LANDED 2026-10-15: commit 91fad93 (census
  389, pushed 86421cd..91fad93), the WSG HUNTING AND
  STALKING slice, printed pp. 55-56 - hunting (the
  four-turn check, the -5% cumulative per party
  member beyond the first, the -10% mid-morning to
  mid-evening shift, the night gate on infravision/
  ultravision, the missile weapon averaging 3+ vs
  size L, melee only to finish, the 1d6
  game-encounter list with the 1d10
  greater-than-the-count hit procedure, 1/2/4 hits
  to kill S/M/L, one animal at a time, the 4-turn
  re-hunt after a negated encounter), stalking a
  wounded animal (the 20-foot missile-or-melee
  finish, the enraged size L charge at the closest
  character with the 50% 1d8 predamage and the AC 5
  stalk, the panicked size M 18-inch flight with the
  1d4 direction band and the 20-foot kill range, the
  first-miss escape) and Table 31 (all 132 cells:
  the 33-row terrain-by-season grid, Arctic 5 rows,
  the others 7). rules/wsghunt.h NEW (30 inlines:
  14 consts + 5 bools + 1 chain + 1 switch + 9 table
  columns, prefix whn, checked free in all three
  TUs). GROUND TRUTH: the vision sheets made two
  errors the pixels overturned (temperate mountains
  winter 25 not 15 - the glyphs show 2+5; arctic
  desert spring 5 not 30) and the text layers
  garbled the tropical mountains summer/autumn cells
  (40, not 10); the 1d6 list row 6 settled by
  glyph-segmentation of the native decode: size L,
  1d3 at 60-80 yards (the djvu 50-60 is a garble).
  BOOK DISCREPANCY NOTED, NOT FIXED: the p. 56
  example prints a 35% chance for three hunters in
  a tropical forest but Table 31 prints 50 and the
  party rule takes it to 40; the rule is pinned as
  printed, only the internally consistent examples
  are pinned (2 hunters 45, 3 hunters 40), and the
  discrepancy is recorded in the header banner.
  Gap 76/110 -> 79/107 (THREE box flips + the
  post-state line); census 388 -> 389. rverify FULL
  GREEN pre-landing: restore at 86421cd, double-run
  8/0 then 0/8, 183 mutants, 0 missed. Spec md5s:
  90b590fb authored / 17e91cd0 +nl - the Termux read
  the +nl value exactly (the deterministic nano
  gate). LANDED CLEAN on the first ritual run
  (double-run 8/0 then 0/8, preflight GREEN first
  try, R464 audit bad 0, census 389, 5 files / 1516
  insertions). VERIFIED at the raw sha 91fad93: the
  commit message and file list (regtest +215, the
  header 553, the spec 708, the gap 4/4, the seed
  +36), the include after wsgforage.h at line 169,
  wsghunt.h 30 inlines, the three flips with the
  R464 text, the post-state 79/107, the R463 seed
  record in place. NOTE: the bn launcher stays OUT
  of the ritual per the R372 standing decision (the
  user ran it separately by choice). Next: R465 -
  the hunting proficiency (p. 57), then fishing
  (p. 57) and the food-carrying items; the vision
  quota (20 analyze_image calls) may reset per
  response - budget the crops per turn.
- R465 LANDED 2026-10-15: commit 27481c0 (census 390, pushed
  91fad93..27481c0), the WSG HUNTING PROFICIENCY AND FISHING slice, printed p.
  57 with the spot-guideline tail on p. 58 - the hunting proficiency (the
  one-hit size M kill, the two-hit size L kill, the 50% one-attempt distance
  kill of a wounded size M, the single-hit wounded size L with multiple
  attempts, the successful Proficiency Check BEFORE the 1d6 roll, the
  missile-weapon requirement, no boost to the encounter chance or the prey
  size, the repeatable expeditions), fishing (the one-hour baited
  hook-and-line base, the net +50%, the zero-or-lower no-fish gate, the
  proficiency +2 in fair or good spots only, the cumulative -1 per extra group
  member, the cumulative -2 per hour beyond the first in the same spot, the
  fished-out rule with the one-day recovery, the spot-quality guidelines: boat
  mid-water beats shore, swamp/bog and stagnant shallow creek poor, shaded
  spots fair or good) and Table 32 (the 3x3 spot-by-time dice grid: Poor
  1d4-2/1d4/1d4+2, Fair 1d6-2/1d6-1/1d6+2, Good 1d8-2/1d6+2/1d8+2).
  rules/wsgfish.h NEW (29 inlines: 8 consts + 14 bools + 1 switch + 6 table
  columns, prefix wfs, checked free in all three TUs). GROUND TRUTH - the
  hardest pixel fight since R463: the OCR DROPPED the Fair-Day cell and
  garbled four Good cells; the native decode of the printed p. 57 image (a
  from-scratch pure-Python JPEG decoder, obj 548, 1179x1516, djvu-to-image
  calibration x=djvu*0.48, y=djvu*0.48+1) settled them. Fair-Day 1d6-2 (glyph
  holes=1, canonical-6 template 0.947, vision agrees). Good-Day 1d8-2 (the
  digit shows the 8 stacked-loop waist vs the reference 6 open top sweep;
  vision twice read a two-loop 8). Good-Night 1d6+2 EXAMPLE-PROVEN (the book
  A/B/C example: proficient A at a good spot at night rolls 1d6+4 = 1d6+2 +2,
  B 1d6+1, C 1d6). Good-Dawn 1d8+2 (same 8 waist; the plus sign vertical
  stroke survives as faint 158-238 grayscale traces through a minus-strength
  bar while the true minus on the same page shows pure 255 background around
  its bar - the decisive minus-vs-plus discriminator). Row labels Fair/Good
  pixel+vision confirmed. The p. 57 tail completes on p. 58: "...shaded by
  trees or overhanging terrain; such a spot will be fair or good, while an
  unshaded spot nearby on the same body of water will be a poor one" -
  included in provenance, the p. 58 box NOT flipped. The proficiency-check
  modifier ladder (+1/+3/+6/+10/+15) stays in the pp. 13-17 gap - out of scope
  this round. NOTE: the handoff said the post-state was 82/105 but the derived
  census computed 82/104 (the handoff was off by one); the computed value
  shipped and verifies at the raw sha. Gap 79/107 -> 82/104 (THREE box flips +
  the post-state line); census 389 -> 390. rverify FULL GREEN pre-landing at
  base 91fad93 (double-run 8/0 then 0/8, 40 mutants, 0 missed). Spec md5s:
  49d2e645 authored / a620f22e +nl - the Termux read the +nl value exactly.
  LANDED CLEAN on the first ritual run (double-run 8/0 then 0/8, preflight
  GREEN first try, R465 audit bad 0, AUDIT CENSUS: 390, 5 files / 956
  insertions; the user ran bn separately by choice, it stays out of the ritual
  per R372). VERIFIED at the raw sha 27481c0: the commit message and file list
  (regtest +167, the header 254, the spec 472, the gap 4/4, the seed +59), the
  include after wsghunt.h at line 170, wsgfish.h 29 inlines with the correct
  grid, the three flips with the R465 text, the post-state 82/104, the R464
  seed record in place. Next: R466 - consuming and carrying food (p. 58: the
  fish half ration, size S a full ration, size M feeds three, size L six
  rations, the druid disapproval, the encumbrance and spoilage factors) and
  Table 33: chance of food spoilage; then finding water.
- R466 LANDED 2026-10-15: commit e04918e (census 391, pushed
  27481c0..e04918e), the WSG CONSUMING AND CARRYING FOOD slice, printed p. 58
  - the ration ladder (one fish half a ration, one size S animal a full
  ration, one size M animal feeding three characters for a day, one size L
  animal six rations, at least twenty full rations from a size L carcass with
  a full day of expert butchering), the druid strong disapproval of
  intentional overkill with the feed-three excuse, the carry rule (excess need
  not be left behind; encumbrance is a DM ruling, spoilage the other factor),
  the gluttony/indigestion not-modeled note and Table 33: chance of food
  spoilage (the 4x10 grid: max days before the first check then the pct chance
  per subsequent day, per food type per effective-temperature band - green
  plants dash/6-20/4-30/2-40/1-50, fruits or vegetables
  dash/5-30/3-40/2-50/1-60, cooked meat dash/3-20/2-50/1-60/1-80, raw meat
  dash/2-50/1-70/1-80/1-90), with the mechanics: the warmest category applying
  at least one hour is the effective temperature, a category once used
  ratchets to the same or warmer for all later checks, continually frozen food
  keeps indefinitely, thawed food spoils from the thaw day (counted as day 1)
  even if promptly re-frozen; one failed check taints (secret Wisdom Check to
  notice, eatable anyway, CON check +4 to avoid nausea and cramps within
  1d10+10 minutes - the 11-20 onset window, -1 on attacks and
  dodging/maneuvering saves for 12 hours, then an unmodified CON check per
  hour to recover, tainted food still a full ration); a second failed check
  obviously spoils (CON check +10, penalties at least 24 hours if stricken,
  else a 50% chance of the full or half ration value, otherwise no nourishment
  at all). rules/wsgcarry.h NEW (47 inlines: 20 consts + 17 bools + 10 table
  columns, prefix wcc - wfs was taken by R465; checked free in all three TUs).
  GROUND TRUTH - the table rounds hit a new reader: the printed p. 58 image
  shows scanner DOUBLE-IMAGING (a ghost copy about 12 pixels below the true
  print), which is why the ASCII/pixel reads were ambiguous and the vision
  calls garbage; the pdfy EMBEDDED OCR TEXT LAYER (decompress the FlateDecode
  content stream of the page object and regex the Tm/Td/Tj tokens) is a
  high-quality positioned text source that settles the table WITHOUT pixels -
  use it (with the djvu word layer as the second reader and the arithmetic
  ladders as the tiebreaker) before fighting double-imaged pixels again. Both
  layers agree on every Table 33 value cell EXCEPT green-plants 31-50 (pdfy
  6/20 vs a djvu garble; 6/20 fits the days ladder 6,4,2,1 and the pct ladder
  20,30,40,50). The below-30 column is a dash in every row (both layers garble
  the dash glyph; the book explanation sentence - spoilage will not occur as
  long as the effective temperature remains within this range - confirms it);
  the dash is encoded as days=0/pct=0 with the wccDashNoSpoilage bool carrying
  the semantics. Note: the byte-level open_url fetch TRUNCATES around 24-32KB,
  so raw-sha verification of late-file items needs github_app
  get_file_contents (the resource blob) instead - regtest.cpp is still too big
  for it, but the gap report and the seed fit. Gap 82/104 -> 84/102 (TWO box
  flips + the post-state line - the handoff-derived numbers matched the
  computed census exactly this time); census 390 -> 391. rverify FULL GREEN
  pre-landing at base 27481c0 (double-run 7/0 then 0/7, 77 mutants, 0 missed).
  Spec md5s: 07dadcaf authored / 9857410b +nl - the Termux read the +nl value
  exactly. LANDED CLEAN on the first ritual run (double-run 7/0 then 0/7,
  preflight GREEN first try, R466 audit bad 0, AUDIT CENSUS: 391, 5 files /
  1326 insertions; the user ran bn separately by choice, it stays out of the
  ritual per R372). VERIFIED at the raw sha e04918e: the commit message and
  file list (regtest +253, the header 400, the spec 619, the gap 3/3, the seed
  +51), the include after wsgfish.h at line 176, wsgcarry.h 47 inlines with
  the correct grid, the two flips with the R466 text, the post-state 84/102,
  the finding-water boxes NOT flipped, the R465 seed record in place. Next:
  R467 - finding water (p. 58) and its Table 34; then where water is found (p.
  59) and water in the desert (p. 60).
- R467 LANDED 2026-10-15: commit efd8d78 (census 392, pushed
  e04918e..efd8d78), the WSG FINDING WATER slice, printed p. 58 with the
  mechanics and the grid on p. 59 - the water-finding checks (two per day for
  a lone character or a traveling group, extra searches automatically fail,
  the table not used where water is obviously and readily available: nearby
  fresh water still checks the taint, the snow-and-ice exception with the
  figures assuming no cover, ice at 30 degrees or lower carrying the taint
  chance of its source water, freshly fallen snow the purest water in nature
  with the mere-dusting note, sea water dehydrating via the salt, the seacoast
  dig at 100% above the high tide line and no more than two feet deep with the
  deeper-the-saltier gradient), the water-quality guidelines (river purer
  upstream, lake purer at the inflow, fast-flowing beats standing, ground
  water beats surface) and Table 34: chance of finding water (the 28-row x
  8-col grid: five climate bands - arctic D/H/M/P constant across seasons,
  subarctic/temperate/subtropical/tropical D/F/H/M/P/Sw - each cell the
  find%/taint% pair by season; the swamp rows top the find chances, the desert
  rows bottom them, the tropical swamp spring 90/75 the only taint value in
  the table not ending in 0). rules/wsgwater.h NEW (27 inlines: 5 consts + 14
  bools + 8 table columns, prefix wfw - wsw taken by R450; checked free in all
  three TUs). GROUND TRUTH - the NEW WORKFLOW, user decision this round, a
  proven success: the user ran tesseract ON TERMUX (pkg install poppler
  tesseract; pdfimages -png -f 59 -l 60 wsg.pdf; tesseract --psm 4 and the TSV
  output) and the grid was REBUILT FROM GEOMETRY - the TSV word bounding boxes
  place the terrain-code column at x 130-165, the season cells at x
  190/285/385/480, one row per 20px of y - no reading-order trust at all. All
  224 values three-way confirmed (tesseract TSV + pdfy embedded OCR + djvu);
  the tesseract slash-loss cells (570, 5170, 60740, 30730, 70170) resolve by
  the other readers; the two low-confidence terrain labels (subarctic E,
  temperate =%) resolve to F (forest - the missing terrain in both bands); the
  ONE contested value, tropical swamp spring, read 90/75 in BOTH text layers
  but 90/80 in two vision reads, and the USER READ THE PHYSICAL PAGE and
  settled it: 90/75, pinned as printed. THE TERMUX-TESSERACT WORKFLOW IS NOW
  THE PREFERRED READER for table rounds: it beats the pdfy layer (which
  garbles slashes), beats djvu (which scrambles grid order), is immune to the
  double-image ghost that killed R466 pixel work, and the TSV geometry enables
  structural cross-checks the prose readers cannot offer. Where water is found
  (p. 59) stays open - the DM standing-water reduction and the water-table
  definition were read this round but are NOT flipped. Gap 84/102 -> 86/100
  (TWO box flips + the post-state line); census 391 -> 392. rverify FULL GREEN
  pre-landing at base e04918e (double-run 7/0 then 0/7, 243 mutants, 0 missed
  - note the engine audit parser wants SINGLE-quoted model keys in
  table_checks; a first cut with double quotes aborted and was rebuilt). Spec
  md5s: bd27b835 authored / e1936b6a +nl - the Termux read the +nl value
  exactly. LANDED CLEAN on the first ritual run (double-run 7/0 then 0/7,
  preflight GREEN first try, R467 audit bad 0, AUDIT CENSUS: 392, 5 files /
  2173 insertions; the user ran bn separately by choice, it stays out of the
  ritual per R372). VERIFIED at the raw sha efd8d78: the commit message and
  file list (regtest +737, the header 667, the spec 708, the gap 3/3, the seed
  +58), the include after wsgcarry.h at line 177, wsgwater.h 27 inlines with
  the full 224-value grid including the case-27 90/75 cell, the two flips with
  the R467 text, the post-state 86/100, the where-water-is-found,
  water-in-the-desert and purifying-water boxes NOT flipped, the R466 seed
  record in place. Next: R468 - where water is found (p. 59: the
  standing-water reduction by terrain, the water table definition and
  depth-by-terrain rules) and the bad-water/vegetation-and-skeletons warning,
  then water in the desert (p. 60) and purifying water (p. 60).
- R468 LANDED 2026-10-15: commit 7ff85f9 (census 393, pushed
  efd8d78..7ff85f9), the WSG WHERE WATER IS FOUND slice, printed p. 59
  with
  the water-table depths on p. 60 - PURE PROSE round, no table: the
  standing-water basis (the Table 34 chance models a sizable quantity of
  standing water, not large enough for a lake or pond: an uncharted pool or
  a small depression holding rainstorm water not yet evaporated or
  absorbed), the drought DM reduction (no rain for several days lets the
  DM
  cut the find chance in certain terrains; a flat plain completely
  dried
  out, a swamp keeping standing water practically all the time), the
  water
  table (the level beneath the ground at which water lies after
  soaking into
  the terrain: a foot or two in low elevation, possibly
  higher than the
  terrain in a swamp near sea level, dozens or even
  hundreds of feet in high
  elevation without a large fresh-water body,
  greatly varying in the
  desert), the non-absorbent exception (a rocky
  mountain range with little
  loose soil, frozen ground - the water table
  nonexistent), the
  dig-for-water chance (after a surface-water fail on
  terrain where
  underground water may exist, whether it exists and how
  far down both DM
  determinations by terrain and elevation, the desert
  the exception with its
  own section) and vegetation as a water source
  (the subtropical and
  tropical plants storing fresh water against a dry
  spell, the cactus
  keeping many desert travelers from dying of thirst,
  the drought plains and
  hills plants, the DM availability-and-quantity
  ruling). rules/wsgwhere.h
  NEW (18 inlines: 4 consts - wwfLowElevMinFt
  1, wwfLowElevMaxFt 2,
  wwfHighElevMinFt 24, wwfHighElevMaxFt 100 - plus
  14 bools, prefix wwf,
  checked free). GROUND TRUTH two-way, no contested
  cells: the user-run
  Termux tesseract text of printed p. 59 (the --psm 4
  run from the R467
  extraction) vs the djvu word layer (Guide_0059 tail
  and Guide_0060), the
  two readers agreeing on every mechanic and every
  number; the section
  heading sits at the bottom of the p. 59 right
  column with the prose
  continuing onto p. 60, ending at the WATER IN
  THE DESERT heading. DEFERRED
  to R469: the permafrost discussion
  (p. 60, referenced by the frozen-ground
  exception) plus water in the
  desert (p. 60); then purifying water (p. 60)
  with the tainted-water
  effects (the bad-water/skeletal-remains warning
  belongs to the
  tainted-water text and stayed unpinned). Gap 86/100 ->
  87/99 (one box
  flip + the post-state line); census 392 -> 393. rverify
  FULL GREEN
  pre-landing at base efd8d78 (double-run 6/0 then 0/6, 18
  mutants, 0
  missed). Spec md5s: 7b21e348 authored / 293bfaba +nl - the
  Termux read
  the +nl value exactly. THE R468 LESSON, twice over: (1)
  example
  exprs must be C-clean as EMITTED - a first cut used != True, fine
  for
  the Python audit mirror (rverify stayed GREEN and missed it) but
  undeclared in regtest.cpp; preflight caught it at the C compile with
  12
  errors and the census block cascading to 390 FAILs; bools compare
  != 1,
  both-mirror valid. (2) a spec re-save after a failed run does
  NOT
  re-splice: the tree still carried the old applied edits, the
  engine read
  applied 0/already 6 and the broken True code stayed in
  regtest.cpp; the
  fix is git restore of the six touched files plus rm
  of the new header
  BEFORE re-running, then the first run must say
  applied 6. LANDED after the
  reset-and-resplice: preflight GREEN (only
  the two pre-existing warnings),
  R468 audit bad 0, AUDIT CENSUS: 393
  exactly once, 5 files / 597
  insertions. VERIFIED at the raw sha
  7ff85f9: the commit stats (regtest
  +84, the header 140, the spec 315,
  the gap 2/2, the seed +56), the include
  after wsgwater.h at line 173,
  the R468 audit label twice with zero True
  tokens in the emitted
  block, the gap 87/99 with the where-water box
  flipped and its
  post-state line, the spec md5 293bfaba, the R467 seed
  record in
  place. Next: R469 - water in the desert plus the permafrost
  discussion (p. 60), then purifying water (p. 60) with the
  tainted-water
  effects.
- R469 LANDED 2026-10-15: commit 13ebab2 (census 394, pushed
  7ff85f9..13ebab2), the WSG WATER IN THE DESERT slice with the
  PERMAFROST
  discussion, printed p. 60 - PURE PROSE round, no
  table: the desert water
  economy (deserts the most arid
  terrain, pitifully little rainfall quickly
  lost to
  evaporation in hot climates or to absorption in sandy or
  loose-soil ground, but some of the water that gets into the
  ground stays
  there and can be recovered with effort,
  perhaps some skill and more than a
  little bit of luck), the
  dig chance (at any given desert location a 40%
  chance that
  water lies 5-15 feet - 2d6+3 - beneath the surface and a
  60%
  chance of finding no water no matter how deep the
  party digs), the desert
  survival proficiency boost (a
  proficient character finds water at 80%
  instead of 40%)
  and the two-tries limit (as with any other attempt at
  finding water, only two tries in any 24-hour period), plus
  the permafrost
  mechanics (the subarctic warm-season
  condition with the temperature
  generally above freezing at
  least during daylight hours, the soil thawing
  to a depth of
  several inches with small vegetation taking root on the
  released water, the thin layer of arable soil over
  permanently frozen
  subsoil, permafrost a dependable source
  of water with the harvest
  technique: remove the upper
  layer of soil, chop out the iced-up soil
  beneath it and
  expose it to heat, the soil and sediment settling to the
  bottom when the ice melts and the water poured off - the
  harvest sentence
  seaming from the p. 59 right-column tail
  onto the p. 60 top right).
  rules/wsgdesert.h NEW (15
  inlines: 5 consts - wdsDigFindPct 40,
  wdsNoWaterPct 60,
  wdsProfFindPct 80, wdsDepthMinFt 5, wdsDepthMaxFt 15 -
  plus 10 bools, prefix wds, checked free). GROUND TRUTH
  two-way, no
  contested cells, no physical-page reads: the
  user-run Termux tesseract
  text of printed p. 60 (the
  --psm 4 run) vs the pdf embedded text layer
  (pdftotext -layout, pdf page 61) - the archive.org djvu
  item went DARK
  this round (an error page on every fetch),
  so the pdf text layer stood in
  as the second reader and
  performed cleanly; the two readers agreed on
  every
  mechanic and every number. Gap 87/99 -> 88/98 (one box
  flip + the
  post-state line); census 393 -> 394. rverify
  FULL GREEN pre-landing at
  base 7ff85f9 (double-run 6/0
  then 0/6, 15 mutants, 0 missed). Spec md5s:
  939f0f9b
  authored / f4893ddb +nl - the Termux read the +nl value
  exactly. LANDED CLEAN on the first ritual run: preflight
  GREEN first try
  (only the two pre-existing warnings), R469
  audit bad 0, AUDIT CENSUS: 394
  exactly once, 5 files /
  595 insertions. VERIFIED at the raw sha 13ebab2:
  the
  include after wsgwhere.h at line 174, the R469 audit
  label twice
  with ZERO True tokens in the emitted block
  (the R468 lesson applied -
  bools compare != 1, C-clean as
  emitted), the gap 88/98 with the
  water-in-the-desert box
  flipped and its post-state line, the spec md5
  f4893ddb,
  the R468 seed record in place. Next: R470 - purifying
  water
  (p. 60) with the tainted-water effects (the 10%
  boil-taint remainder, the
  2-5 round boil at sea level plus
  1d2 minutes per 1,000 feet of elevation,
  the 5%/3%
  evaporation ladder at the 5,000-foot break, the 6-hour
  mild
  and 18-hour severe minimum durations) and the
  bad-water/skeletal-remains
  waterhole warning.
- R470 LANDED 2026-10-15: commit 31f9a0f (census 395, pushed
  13ebab2..31f9a0f), the WSG PURIFYING WATER slice with the
  TAINTED-WATER
  EFFECTS, printed p. 60 - PURE PROSE round, no
  table, and the round that
  CLOSES THE WATER CHAPTER ARC
  (R467 finding water through Table 34, R468
  where water is
  found, R469 the desert and permafrost, R470 purifying and
  the taint effects): the purification trigger (characters
  suspecting
  scavenged water is tainted - a possibility
  that almost always exists - can
  greatly reduce the chance
  of harm by purifying before drinking), the boil
  rule
  (assuming no magical means, boiling the best way to remove
  impurities: a sufficiently long boil leaves only a 10%
  chance of remaining
  tainted, the required time 2-5
  rounds - 1d4+1 - at an elevation close to
  sea level plus
  an extra 1d2 minutes for every 1,000 feet of elevation
  above sea level, taking the water off the fire before
  the required time
  expires doing no good), the evaporation
  cost (at relatively low elevation
  - 5,000 feet or less -
  5% of the water volume lost per minute boiled, at
  higher
  elevation only 3% per minute, the quantity-over-quality
  tradeoff), the tainted-water effects (the same as eating
  tainted or
  spoiled food: mildly tainted water a 6-hour
  minimum duration instead of
  12, severely tainted water an
  18-hour minimum instead of 24), the severity
  ruling (the
  DM decides mild or severe; severe taint relatively more
  likely in areas of low elevation such as swamps and in
  perennially warm or
  hot climates where bacteria prosper -
  extreme heat kills bacteria, extreme
  cold does not
  necessarily, subarctic melt ice almost as likely to carry
  organic impurities as temperate lake water) and the
  bad-water warnings
  (taste and appearance not reliable
  purity indicators - the murky brown
  water may be less
  harmful than the fresh clear liquid; some wilderness
  water carries illness-producing bacteria beyond the taint
  effects and some
  is naturally poisonous, both DM matters;
  a waterhole devoid of vegetation
  and especially one ringed
  with skeletal remains a dead giveaway to find a
  different
  source; even without detect poison, caution and common
  sense
  go a long way). rules/wsgpurify.h NEW (23 inlines:
  11 consts -
  wpuBoilTaintRemainPct 10, wpuBoilRoundsMin 2,
  wpuBoilRoundsMax 5,
  wpuElevStepFt 1000, wpuEvapBreakFt
  5000, wpuEvapLowPctPerMin 5,
  wpuEvapHighPctPerMin 3,
  wpuMildMinHours 6, wpuMildFoodBaseHours 12,
  wpuSevereMinHours 18, wpuSevereFoodBaseHours 24 - plus 12
  bools, prefix
  wpu, checked free). GROUND TRUTH two-way,
  no contested cells, no
  physical-page reads: the user-run
  Termux tesseract text of printed p. 60
  (the --psm 4 run
  from the R469 extraction) vs the pdf embedded text layer
  (pdftotext -layout, pdf page 61; the djvu item still
  dark, the pdf layer
  the standing second reader); the two
  readers agreed on every mechanic and
  every number, the
  pdfy garbles resolving cleanly against tesseract (ld4+
  1
  = 1d4+1, detectpoison = detect poison, Punfymg Water =
  Purifying
  Water). Gap 88/98 -> 89/97 (one box flip + the
  post-state line); census
  394 -> 395. rverify FULL GREEN
  pre-landing at base 13ebab2 (double-run 6/0
  then 0/6, 23
  mutants, 0 missed). Spec md5s: 3cffcf2e authored /
  0b7373de
  +nl - the Termux read the +nl value exactly.
  LANDED CLEAN on the first
  ritual run: preflight GREEN
  first try (only the two pre-existing
  warnings), R470
  audit bad 0, AUDIT CENSUS: 395 exactly once, 5 files /
  741 insertions. VERIFIED at the raw sha 31f9a0f: the
  include after
  wsgdesert.h at line 175, the R470 audit
  label twice with ZERO True tokens
  in the emitted block
  (the R468 lesson holding), the gap 89/97 with the
  purifying-water box flipped and its post-state line, the
  spec md5
  0b7373de, the R469 seed record in place. Next:
  R471 opens the CAMPING AND
  CAMPFIRES arc (pp. 61-68) -
  natural shelters (p. 61) first.
- R471 LANDED 2026-10-15: commit 2eec600 (census 396, pushed
  31f9a0f..2eec600), the WSG NATURAL SHELTERS slice with
  TABLE 35, printed p. 61 - the CAMPING AND CAMPFIRES arc
  opener (pp. 61-68) and the FIRST TABLE ROUND since R467:
  the Table 35 grid (the chance of finding natural shelter
  or easily obtainable construction materials, the
  six-terrain by four-season percentage grid: Desert
  constant 20, Forest 90/100/100/100, Hills 40/60/70/60,
  Mountains constant 40, Plains 30/40/40/30, Swamp
  40/50/50/40), the check discipline (the DM checks
  whenever characters indicate they are looking; a failed
  check with the party still moving allows rechecks at
  three-turn intervals until shelter is found or they stop
  and camp unsheltered), the forest construction rules
  (boughs or branches cut and laid across a grid of poles
  for a roof and, properly positioned, wind-and-precip
  protection; pack animals needing a negotiable path into
  closely packed vegetation; 3-8 turns - 1d6+2 - of
  material time for a single character, minus 2 turns per
  additional helper down to a minimum of 3, then another 6
  turns to lash the poles and bind the shingles, minus 1
  turn per helper to a maximum of two helpers, the whole
  construction time halved with a rope use proficiency
  character among the workers), the terrain notes (the
  desert surface irregularities - large rocks, small
  crevasses, a steeply sloping sand dune - sheltering at
  least one side; the hills windbreak with spring-through-
  autumn greenery; the mountains read as rough rocky areas
  whose table entries model natural features - a cave,
  alcove or chimney between rock faces - where the wind
  cannot get inside; the plains gully two or three feet
  deep but the worst shelter in heavy rain, the non-lush
  material time 7-12 turns vs the 3-8 forest; the swamp
  debris pile or fallen tree as shelter or foundation) and
  the shelter-quality guidelines (many small vegetation
  pieces: poor, at best adequate; few large sturdy pieces:
  adequate or perhaps good; the lee side of a large rock:
  good wind but only adequate-or-poor precip protection -
  the prose seams mid-sentence onto p. 62 at the cave
  sentence). rules/wsgshelter.h NEW (31 inlines: 11 consts
  - wnsTerrainCount 6, the 3/8 forest band, the 2/1 helper
  reductions with the 3-turn floor and the 2-helper lash
  cap, the 6-turn lashing, the 7/12 plains band, the
  3-turn recheck - plus 16 bools plus the four Table 35
  season columns, prefix wns, checked free). GROUND TRUTH
  two-way, no contested cells, no physical-page reads: the
  user-run Termux tesseract text of printed p. 61 (the
  --psm 4 run) vs a VISION READ of the uploaded page image
  (pg61-000.png) - THE NEW READER COMBO: with the djvu item
  still dark, VISION-ON-PNG IS THE STANDING GRID SECOND
  READER (the R467 TSV-geometry workflow remains preferred
  when the TSV is captured; here the TSV was not run). The
  tesseract and vision reads AGREED ON ALL 24 CELLS. The
  pdf text layer garbles the grid badly (dropping the
  Forest, Hills and Mountains rows entirely and reading 4c
  for the Plains autumn 40) and served as the prose-only
  third reader; the prose numbers (the 1d6+2 dice, the
  helper reductions, the rope-use halving, the 7-12 plains
  ladder, the three-turn recheck) agreed across tesseract
  and pdfy. Gap 89/97 -> 91/95 (TWO box flips - Natural
  shelters + the Table 35 grid box, the R467 precedent -
  plus the post-state line); census 395 -> 396. rverify
  FULL GREEN pre-landing at base 31f9a0f (double-run 7/0
  then 0/7, 51 mutants, 0 missed) - after THREE spec bugs
  caught by the gates before any ritual run: (1) the table
  count const must ALSO appear in header_sections or the
  emitted header is one inline short; (2) the engine's
  condition syntax gate rejects Python any()-generators -
  table_checks must be explicit cell chains; (3) the plains
  7-12 band OVERLAPS the forest 3-8 band, so a
  plains-min-above-forest-max check was wrong (the correct
  form compares both ends separately). Spec md5s:
  76c5622d authored / e9ad609d +nl - the Termux read the
  +nl value exactly. LANDED CLEAN on the first ritual run:
  preflight GREEN first try (only the two pre-existing
  warnings), R471 audit bad 0, AUDIT CENSUS: 396 exactly
  once, 5 files / 1149 insertions. VERIFIED at the raw sha
  2eec600: the include after wsgpurify.h at line 176, the
  R471 audit label twice with ZERO True tokens, the full
  C35 grid verbatim ({20,20,20,20} up through
  {40,50,50,40}), the gap 91/95 with both boxes flipped and
  the post-state line, the spec md5 e9ad609d, the R470
  seed record in place. Next: R472 - portable shelters
  (p. 62) with Table 36 (portable shelter characteristics),
  the p. 61 cave-sentence seam riding along.
- R472 LANDED 2026-10-15: commit 663e014 (census 397, pushed
  2eec600..663e014), the WSG PORTABLE SHELTERS slice with
  TABLE 36, printed p. 62 - the second camping-arc round
  and the second TABLE ROUND of the arc: the p. 61 seam tail
  (a cave in the face of a mountain slope is a superior
  shelter in all respects, assuming the opening faces away
  from the wind; the DM judgment prevailing in any
  circumstances not covered by the guidelines), the hauling
  rules (a single mount or size M pack animal easily
  transporting all the gear for many shelter types with
  plenty of carrying capacity left over; in the absence of
  an animal a single average-strength character hauling on
  his back enough for himself and a small group at their
  rest stops), the simplest form (a single wooden pole of
  6-10 feet plus a fairly large expanse of heavy waterproofed
  cloth or similarly pliable material; the DM may allow a
  two- or three-piece pole apparatus held by lashings or
  pegs, easier to transport), the pitch rules (the pole
  anchored at 30 to 45 degrees, the covering draped over
  it, the edges tied down with ropes and stakes, the
  opening facing opposite the wind), the occupancy (one
  human or a pair of smaller characters, and in a pinch
  two men with no appreciable loss of protection or
  comfort), the escalation (more elaborate shelters for
  vicious weather or a decent-sized group huddling in one
  tent) and the Table 36 grid (the four quality bands
  poor/adequate/good/superior by small/medium/large:
  encumbrance 350/450/600, 500/600/750, 600/800/1000,
  750/1000/1500; cost 10/20/30, 30/50/75, 75/120/180,
  200/300/400 gp; setup 1d2+1/1d2+2/1d2+3, 1d3+1/1d3+2/
  1d3+3, 1d3+1/1d3+2/1d4+2, 1d4+1/1d4+2/1d4+3 turns - the
  GOOD LARGE 1d4+2 OUTLIER breaking the 1d3+ pattern of
  its band, verified in all three readers; moisture light/
  moderate/heavy/downpour; wind 20/30/40/50 pct; life span
  40/80/120/180 days). rules/wsgtents.h NEW (27 inlines: 8
  consts - the 6/10 pole band, the 30/45 pitch band, the
  3-piece pole cap, the 4-band x 3-size x 12-row geometry -
  plus 12 bools plus the seven Table 36 column switches -
  the setup dice split into a die and a modifier column,
  the moisture resistance as a 4-step tier, prefix wps,
  checked free). GROUND TRUTH two-way, no contested cells,
  no physical-page reads: the R467 TSV-GEOMETRY WORKFLOW
  (the uploaded p62_tsv.tsv word boxes) vs the user-run
  Termux tesseract text of printed p. 62; the two readers
  agree on ALL 72 GRID CELLS; the pdf text layer third
  reader garbles dice as ld (the known pattern) but agrees
  on every value and all prose numbers. Gap 91/95 -> 93/93
  (TWO box flips - portable shelters + the Table 36 grid
  box, the R467/R471 precedent - plus the post-state line);
  census 396 -> 397. rverify FULL GREEN pre-landing at base
  2eec600 (double-run 7/0 then 0/7, 104 mutants, 0 missed) -
  NO spec bugs this time: all three standing lessons (the
  count const in header_sections, explicit cell chains, no
  arithmetic inside condition operands) honored on the
  first write. Spec md5s: 2a1ae28a authored / f74ca64b +nl
  - the Termux read the +nl value exactly. LANDED CLEAN on
  the first ritual run: preflight GREEN first try (only the
  two pre-existing warnings), R472 audit bad 0, AUDIT
  CENSUS: 397 exactly once, 7 files / 1364 insertions (the
  p62 extraction files riding along in the commit).
  VERIFIED at the raw sha 663e014: the include after
  wsgshelter.h at line 177, the R472 audit label with ZERO
  True tokens, the C36 grid verbatim ({350,10,2,1,0,20,40}
  up through {1500,400,4,3,3,50,180}, the array declared
  [12][7]), the gap 93/93 with both boxes flipped and the
  post-state line, the spec md5 f74ca64b, the R471 seed
  record in place. Next: R473 - rest and comfort (p. 64)
  with Table 37 (effects of lack of sleep), continuing the
  camping arc.
- R473 LANDED 2026-10-15: commit 82ca9d9 (census 398, pushed
  663e014..82ca9d9), the WSG SHELTER MECHANICS AND REST AND
  COMFORT slice with TABLE 37, printed pp. 63-64 - the third
  camping-arc round and the third TABLE ROUND of the arc: the
  p. 62-63 seam (the shelter kit mechanics unpinned by R472,
  whose box covered only p. 62 - ridden along rather than
  orphaning the book numbers): the poor/adequate/good/superior
  kit setup rules (1/2/3-turn setup minimums, one-turn-less
  takedown at 5 rounds/1 turn/2 turns, the 1-turn helper
  saving), the Table 36 column semantics (the moisture and
  wind life-span point economy - the 10-mph/5-mph wind leak
  step, the twice-threshold 25 pct damage chance, the
  1/3-use and 1/2/4 point rates, the poor 40-to-20
  collapse), the 2/4/6 pole minimums and occupancy counts;
  then the p. 64 slice: rest and comfort (the 16-hour
  active day, the 3-hour camp chores, the 5-hour sleep
  requirement) and how much sleep (the two-day trigger with
  sunrise onset, the day-by-day average rest, the one-night
  negation, the 12-to-6 movement example) plus the Table 37
  five-band grid (less-than-5/4/3/2/1 hours by eight effect
  columns: Dex 1/2/3/4/5, Str 0/1/2/3/4, Wis 0/0/1/2/3,
  Con 0/0/0/1/2, to-hit 0/-1/-1/-2/-3, climb
  0/0/-10/-20/-30, move 0/0/-25/-33/-50, weight multiple
  0/0/0/50/100). rules/wsgsleep.h NEW (77 inlines: 41
  consts + 28 bools + the eight Table 37 column switches,
  prefix wrs - checked free in regtest.cpp and the game
  sources; wsl was TAKEN, the R369 wsgslip.h lesson).
  GROUND TRUTH: two-way on the prose (the Termux tesseract
  p63_full/p64_full vs the pdfy text layer, all prose
  numbers in agreement), THREE-WAY on the contested grid
  cells: tesseract garbled the LESS-THAN-2 DEXTERITY (+4)
  and STRENGTH (+3) cells into conf-49 noise; the pdf layer
  and a VISION READ of pg-001-2.png second-confirmed the
  full grid (the R471 vision-on-png contested-cell
  settler). Gap 93/93 -> 96/90 (THREE box flips + the
  post-state line: rest and comfort, how much sleep, the
  Table 37 grid box); census 397 -> 398. rverify FULL GREEN
  pre-landing at base 663e014 (double-run 8/0 then 0/8, 109
  mutants, 0 missed) - it caught ONE spec bug: my
  penalties-deepen-monotonically table_check had an
  INVERTED comparison direction (penalties are negative;
  the bad case is next > current, not current > next) -
  fixed and re-verified; also renamed
  wrsSuperiorKitTrueStructure -> wrsSuperiorKitStructure so
  the audit block carries no True substring. Spec md5s:
  ff9f7149 authored / 7415450d +nl - the Termux read the
  +nl value exactly. LANDED CLEAN on the first ritual run:
  preflight GREEN first try (the two pre-existing warnings
  plus the untracked-note for the p63/p64 extraction files,
  wsgsleep.h and the spec - the user committed only the 5
  repo files), R473 audit bad 0, AUDIT CENSUS: 398 exactly
  once, 5 files / 2051 insertions. VERIFIED at the raw sha
  82ca9d9: the include after wsgtents.h at line 178, the
  R473 audit label with ZERO True tokens, the C37 grid
  exact (all five rows across the eight column switches,
  col_default 0 with the 999 sentinel default discipline),
  the gap 96/90 with all three boxes flipped and the
  post-state line, the spec md5 7415450d, the R472 seed
  record in place. Next: R474 - good sleep vs bad sleep
  (p. 65) with Table 38 (campfire characteristics),
  continuing the camping arc.
- R474 LANDED 2026-10-15: commit e73bea2 (census 399, pushed
  82ca9d9..e73bea2), the WSG GOOD SLEEP VS BAD SLEEP and FIRE
  slice with TABLE 38, printed p. 65 - the fourth
  camping-arc round and the fourth TABLE ROUND of the arc:
  the rest-quality penalty ladder (not prone or relaxed -1;
  bare ground -1, wind of 20 mph+ -2 and light or moderate
  precipitation -3 with no shelter, all three waived for a
  plate wearer; personal temperature below 0 at -1 and
  above 90 at -2; any metal armor except plate -3; any plate
  -4) with the DM-summed reduction and the no-rest threshold
  (a total penalty exceeding the time spent trying to sleep
  means no refreshment at all), the extreme-weather bar
  (no sleep in a lightning storm, a hailstorm or a sandstorm
  unless inside a shelter, the commotion caveat, the
  DM-may-expand note), the longer-sleep compensation (a
  plate wearer's 5-hour night buys 1 hour of good rest, 9
  hours refresh like 5), the sleep-in-armor prudence with
  the one-night-in-two rule, the armor donning discipline
  (9 minus AC rounds, +2 for any plate, +5 more unaided for
  field or full plate: leather 1 round at AC 8, banded 5 at
  AC 4, full plate 11 helped or 16 solo at AC 0, doffing in
  half the time with 8 rounds to shed full plate alone);
  then the fire slice: the campfire function (not integral,
  cooking incidental and some plants poisonous raw, warmth
  primary and life-or-death) and Table 38 in TWO grids: the
  specs (fuel 6/12/18 turns for an 8-hour burn, start 2d20
  +0/+5/+10, refuel 3/6/9, wind resistance 20/30/40,
  capacity 6/10/15, visibility 240/360/540) and the
  warmth-at-distance ladder by nine distances (Small
  80/60/40/30/20/10/0/0/0; Medium dash then
  80/60/40/30/20/10/0/0; Large dash, dash, then
  80/60/40/30/20/10/0 - the three printed dashes pinned as
  the 999 no-warmth sentinel, the R472 wsgtents moisture
  precedent). rules/wsgfire.h NEW (65 inlines: 25 consts +
  23 bools + the 17 grid columns across the two tables,
  prefix wgf - checked free in regtest.cpp and the game
  sources). GROUND TRUTH two-way on the prose and the
  Table 38 top grid (the Termux tesseract p65_full/p65_tsv
  vs the pdfy text layer, pdf page 66; tesseract garbled
  only four penalty minus-signs, never a digit). FOUR
  contested warmth-grid cells (Small at 50 and 60 reading
  00 and 10, Large at 20 reading 4, Large at 60 reading O):
  pdfy read them 0/0/40/0 and the TSV WORD-BOX GEOMETRY
  settled them (the R467 workflow): the Small-at-60 box is
  20px wide like every single-digit cell (a true 10 is
  39px), the Large-at-20 box is 40px wide exactly like every
  two-digit 40 cell (a lone 4 is 19px); monotone decay per
  row and the larger-fire-warms-at-least-as-much
  cross-check confirm. NEW LESSON: the standing
  vision-on-png contested-cell settler FAILED on this page
  (two vision reads, each contradicting the two agreeing
  text layers on uncontested cells - reading the refuel
  column as the start dice and inventing dashes mid-row),
  so the TSV geometry plus monotonicity is the settler of
  record; the vision read is not reliable on dense small
  grids and should not override two agreeing text readers.
  Gap 96/90 -> 99/87 (THREE box flips + the post-state
  line: good sleep vs bad sleep, fire: friend and foe, the
  Table 38 box); census 398 -> 399. rverify FULL GREEN
  pre-landing at base 82ca9d9 (double-run 8/0 then 0/8, 99
  mutants, 0 missed) - NO spec bugs caught, the R473
  inverted-monotonicity lesson honored on the first write
  (the penalty check allows equal neighbors and fails only
  on shrink; the warmth check fails only on increase). Spec
  md5s: 242193bf authored / 4d95944d +nl - the Termux read
  the +nl value exactly. LANDED CLEAN on the first ritual
  run: preflight GREEN first try (the two pre-existing
  warnings plus the untracked-note for wsgfire.h and the
  spec - the user committed only the 5 repo files), R474
  audit bad 0, AUDIT CENSUS: 399 exactly once, 5 files /
  1706 insertions. VERIFIED at the raw sha e73bea2: the
  include after wsgsleep.h at line 179, the R474 audit
  label with ZERO True tokens, the C38 [3][8] and C38w
  [3][9] grids verbatim with the dash sentinels, the gap
  99/87 with all three boxes flipped and the post-state
  line, the spec md5 4d95944d, the R473 seed record in
  place (61 lines, directly before the maintenance anchor).
  Next: R475 - precautions and perils (p. 66) with Table 39
  (availability of fuel), continuing the camping arc.
- R475 LANDED 2026-10-15: commit 86ebdd8 (census 400, pushed
  e73bea2..86ebdd8), the WSG PRECAUTIONS AND PERILS slice with
  TABLE 39, printed p. 66 - the fifth camping-arc round and
  the fifth TABLE ROUND of the arc, riding the Table 38 column
  semantics seam unpinned by R474: the start discipline
  (2d20 rounds unproficient with tools, dry fuel and breeze of
  no more than 15 mph; 3d20 in wind over 15 mph or wet fuel; no
  start without tools unproficient; no start in wind over
  30 mph without magic), the refuel semantics (a fire not
  refueled in time shrinks to the next lower size; a small
  fire never goes out within three turns but provides no
  warmth), the wind resistance semantics (unprotected fires
  only; falter and flicker with no warmth over the rated
  velocity), the capacity semantics (six men at 10 feet,
  doubling to 12 at 20; clustering diminishes by one-third,
  one-half and two-thirds at five, three and one feet: 4/3/2
  characters), the visibility semantics (yards in moonlight,
  one-third off in twilight, one-half off in daylight; the
  540-yard large-fire flame), the warmth semantics (the
  80-degree safe distance, five segments to move, 3 feet from
  a medium fire and 5 from a large, the 10-mph calm
  assumption, windward minus 5 degrees per 10 mph, leeward
  plus 10 feet or one increment whichever is less, and the
  book 30-mph example: 20 degrees at 20 feet windward instead
  of 30, 10 feet leeward instead of 3), Table 39 in two grids
  (temperate by season: desert 20/20/20/20, forest
  70/100/100/100, hills 40/70/70/60, plains 50/70/80/70,
  swamp 40/30/30/40; climate modifiers: desert
  -20/-10/-10/-20, forest -100/-30/+30/+30, hills
  -30/-20/+10/+20, mountains -40/-30/+20/+30, plains
  -60/-40/+20/+20, swamp -40/-20/+10/+20), and the start of
  precautions and perils (no safe fire, no fire on
  combustibles, 1-3 turns to clear, sparks 100 feet in a
  strong wind). 81 inlines (43 consts, 30 bools, 8 grid
  columns) pin as rules/wsgfuel.h; census 399 -> 400; gap
  99/87 -> 101/85 (precautions and perils p. 66 + Table 39
  p. 66 boxes; next: uncontrollable fires p. 67). md5 pair:
  authored no-nl f4470756732fb40eacc929649e1d0fcb, as-built
  bd3e3f41d625b0cbb465bbf3e1efcba3; verified at raw sha on
  GitHub. GROUND-TRUTH LESSON: the hills rows of BOTH Table 39
  grids failed both text readers (the pdf text layer DROPPED
  them; tesseract garbled them) and were settled by TWO
  independent vision reads of the png that AGREED EXACTLY -
  this REFINES the R474 lesson: a single vision read is
  unreliable, but two independent agreeing vision reads
  settle a contested cell, especially when plausible against
  neighboring rows. ENGINE LESSON: the one-bad audit-mirror
  failure was a sense-inverted cross-const check - the
  leeward example increase is 7 feet (3 -> 10, the
  whichever-is-less one-increment path), not the full 10-foot
  step; cross-const arithmetic checks must respect
  whichever/minimum semantics before pinning equality.
- R476 LANDED 2026-10-15: commit 21d9e59 (census 401, pushed
  86ebdd8..21d9e59), the WSG UNCONTROLLABLE FIRES slice,
  printed p. 67 - the sixth camping-arc round, a pure prose
  round with NO table: the four cardinal rules of fire
  discipline (do not build larger than needed with the
  two-small-fires advice; never leave untended with the
  sentry spark watch), the spark semantics (sparks and ash
  once every 1d3 turns, carried downwind 10-30 feet by size
  plus one foot per 1 mph of wind, a 1 in 6 catch chance on
  combustible material, the wild fire that may char several
  miles), the average-case growth ladder (tiny flame to small
  in 1 turn, medium in 2, large in 4, uncontrollable within 6
  turns - one hour - by height or area), the extinguishing
  discipline (5 rounds small / 1 turn medium / 2 turns large,
  halved by a helper or 1/2/4 gallons of water, doubled on
  combustible material, a 1 in 10 residual chance, and the
  2d4-turn flare-up of a campfire left alive), and the
  uncontrollable-fire spread prose (rough circle stringing out
  into a wind-driven wall of fire; animals and wise
  characters flee ahead). 46 inlines (25 consts, 21 bools)
  pin as rules/wsgblaze.h; census 400 -> 401; gap 101/85 ->
  102/84 (uncontrollable fires p. 67 box; next: damage from
  fire p. 68). md5 pair: authored no-nl
  f4bc46529ddbdd42609b752ab7561c10, as-built
  7a74ea54869f36c766e8c503be11ea17; verified at raw sha on
  GitHub. GROUND TRUTH: two-way clean on every number, no
  contested cells, no vision reads needed - the user's initial
  two-small-tables report was an off-by-one against p. 66
  (already landed in R475); confirm the print-page vs pdf-page
  offset (printed p. 67 = pdf page 68) before doubting an
  extraction. ENGINE: the audit mirror passed on the FIRST
  build this round - applying the R475 whichever/minimum
  lesson at design time (all ladder and equality checks
  checked against the book semantics before building) pays.
- R477 LANDED 2026-10-15: commit 15093c4 (census 402, pushed
  21d9e59..15093c4), the WSG DAMAGE FROM FIRE slice, printed
  p. 68 - the seventh camping-arc round, closing the FIRE
  chapter, a pure prose round with NO table: the advance and
  firebreak prose (an uncontrollable fire advances at
  one-half of the wind velocity or 5 mph in any case; a trot
  stays ahead in calm air or light breeze; the firebreak of
  churned, cleared ground with dig and move earth and the
  18-strength spade of colossal excavation; the cut-in-half
  ruling; the cleared-area refuge with its too-close peril),
  the engulfment rule (10-15 points per round as 1d6+9, cut
  in half rounded up on a successful Constitution Check with
  a +4 modifier to the die roll, burn damage equal to
  one-third of full normal hit points rendering the victim
  unconscious and ending his Constitution Checks), the
  brief-contact rule (1d8 for leaping through a wall of fire,
  saves versus normal fire for every major item, 1d3 per
  burning item per round until extinguished or discarded,
  the Wisdom Check calm-hit-roll escape against the panic
  run at top speed in a random direction taking 1d4 per
  round until caught), and the extreme-heat rule (closer
  than 5 feet to a large fire or 3 feet to a medium fire
  counts as 120 degrees or higher per the Temperature Damage
  to Characters Table, with the activity-level adjustments
  waived). 38 inlines (17 consts, 21 bools) pin as
  rules/wsgdmg.h with prefix wdm (wdf collided in
  regtest.cpp); census 401 -> 402; gap 102/84 -> 103/83
  (damage from fire p. 68 box; next: medicine and first aid
  pp. 69-71, starting with availability of medicinal plants
  p. 69 which carries Table 40 - expect a TABLE ROUND).
  md5 pair: authored no-nl 6b33e7c698cca9cfe9266c2847290c1e,
  as-built 36b2ac593182c3468cb8fd4ac7923a7f; verified at raw
  sha on GitHub. GROUND TRUTH: two-way clean on every number,
  no contested cells, no vision reads needed. ENGINE: the
  audit mirror passed on the FIRST build again - design-time
  cross-const semantics checking is now the standing habit.
- R478 LANDED 2026-10-15: commit ac25aa5 (census 403, pushed
  15093c4..ac25aa5), the WSG MEDICINAL PLANTS slice with
  Table 40, printed p. 69 - the eighth camping-arc round,
  a TABLE round: the 34-row terrain-climate frame (D F H M P
  Se Sw; Arctic with NO swamp row, six terrains) pinned as
  two [34][4] grids - wmpVegChance (the left slash number,
  the vegetation chance) and wmpLocateChance (the right, the
  locate chance), four seasons apiece - plus the slash entry
  semantics (identify on a second roll at one-half or less,
  the upper half a wrong type believed right, plant lore
  always correct), the search discipline (one search per
  turn by function, keep moving, repeated searches of one
  area auto-fail, movement slowed, DM penalties and abuse
  guards), the worked example (tropical hills winter 90/30:
  15 right type, 16-30 wrong, 31-up nothing) and Appendix J
  at DMG pp. 220-221. THE SETTLE: the pdf layer DROPPED the
  entire leftmost terrain-code column AND all five seacoast
  rows - both text readers lost the Se rows entirely - and
  tesseract garbled many slash cells (10110, 5110, 1510,
  4010, 75140, 2010) while the Se rows sat in a consistent
  80px gap it showed; the settler needed SEVEN vision reads
  with two agreeing independent reads per contested cell,
  and the book's own worked example (tropical hills winter
  90/30) independently confirms the settled row 29. The
  spec md5 pair: authored cf3795c6810fe7a7c9921df5efb288d9,
  as-built 321a9a00146a3ef90a3cd118f5179b94 (the Termux
  md5 hit the +nl pair value exactly). rverify at 15093c4:
  298 mutants, 0 missed (272 grid cells + 15 consts + 11
  bools); inline_count 34; the include lands after wsgdmg.h
  at line 183; census 402 -> 403; the gap flips 103/83 ->
  105/81 (both the prose box and the Table 40 box), the
  R477 seed record in place (35 lines, directly before the
  maintenance anchor). One mid-build lesson: an example
  band check (wrong-min = den*roll+1) evaluated TRUE on
  healthy data - the mirror caught it before any patch
  landed; the floor is locate/2 + 1.
  Next: R479 - proficiency in plant lore (p. 70)
- R479 LANDED 2026-10-15: commit 8089f20 (census 404, pushed
  ac25aa5..8089f20), the WSG PLANT LORE PROFICIENCY slice,
  printed p. 70 - the ninth camping-arc round, a pure
  prose round with NO table, the short bridge section after
  the Table 40 pin: five qualification bools (the party
  survival benefit when no healing and curing magic is at
  hand, the safeguard against losing that aid along the
  way, the no-vegetation bar, the greater-chance-in-greenery
  rule, and the pointer to the Wilderness Proficiencies
  section for the benefits), prefix plr, pinned as
  rules/wsglore.h with the include after wsgmed.h at line
  184. THE SETTLE: two-way clean on the FIRST pass - the
  tesseract full-text and the pdfy layout read agree word
  for word, no contested cells, no vision reads needed; the
  section carries no numbers at all, so nothing could
  garble. The spec md5 pair: authored
  383346f39ad344d667b6894cc9eb4476, as-built
  f76ba76cb11e8b6243bacb0ba87a730f (the Termux md5 hit
  the +nl pair value exactly). rverify
  at ac25aa5: 5 mutants, 0 missed; inline_count 5; census
  403 -> 404; the gap flips 105/81 -> 106/80. One mid-build
  lesson: the first engine run hit a mixed applied/already
  state because the rules/ dir was missing in the fresh
  snapshot - the seed patch had already applied before the
  header write failed (the R420 gate caught it); always
  mkdir rules in a fresh snapshot before the first run.
  Next: R480 - injuries and treatment (p. 70)
- R480 LANDED 2026-10-15: commit 414dbb3 (census 405, pushed
  8089f20..414dbb3), the WSG INJURIES AND TREATMENT slice,
  printed p. 70 - the tenth camping-arc round, a pure
  prose round with NO table: the five specific injuries
  and treatments pinned as rules/wsginj.h with the include
  after wsglore.h at line 185 (prefix wtr, free in all four
  files). The frame: first-aid skills are common knowledge,
  useful only when the DM rules with proper reason that a
  specific injury was suffered. The broken bone: the splint
  aligns the ends, no hp regained until splinted, use of
  the injured extremity costs an immediate 1d6 and
  neutralizes healing to date, the bone heals last. The
  minor burn: two turns of immersion or a tight clean
  cloth for normal 1-per-day healing, else the -1 pain
  penalty and half-speed healing. The major burn: more
  than half the body, rest until half the lost hp,
  voluntary activity forfeits all regained points plus 1d4
  per round, the -3 pain penalty (exactly three times the
  minor one), the victim can still be carried. The major
  wound: an edged melee weapon with an unmodified damage
  roll of 6 or higher, DM discretion or the 25% artery
  chance, 2-4 (1d3+1) hp per round of bleeding, direct
  pressure for 2-7 (1d6+1) rounds at 1 hp lost per round,
  wrapping halts but a healing-proficiency character is
  needed for recovery, early release negates. The minor
  wound: assumed bandaged at first opportunity. THE
  SETTLE: the injuries section lives on the same settled
  printed p. 70 as R479 - both readers agree on every
  number, the tsv confirming the dice formulas cell by
  cell; no vision reads needed. The design-time check
  caught the dice-minimum semantics BEFORE the build: min
  = dice + plus (the R478-style first-try error of
  dice*sides+plus never reached the engine), all six
  example bands False on healthy data. The spec md5 pair:
  authored 0332daff4a0b0af138efcf3a380bb423, as-built
  f7dc3597786308753fc0e4f4beb16368 (the Termux md5 hit
  the +nl pair value exactly). rverify at 8089f20: 43
  mutants, 0 missed; inline_count 43 (24 consts + 19
  bools); census 404 -> 405; the gap flips 106/80 ->
  107/79.
  Next: R481 - first aid equipment (p. 71)
- R481 LANDED 2026-10-15: commit 5fe385c (census 406, pushed
  414dbb3..5fe385c), the WSG FIRST AID EQUIPMENT slice,
  printed p. 71 - the eleventh camping-arc round, CLOSING
  the medicine chapter, a pure prose round with NO table:
  the four essentials pinned as rules/wsgfae.h with the
  include after wsginj.h at line 186 (prefix wfe - free,
  but the FIRST FOUR candidates fae/wfa/fad/aeq ALL
  collided, needing fourteen probes). Bandages: several
  clean-fabric swatches for wounds and burns; clothing
  strips in a pinch but adventurer clothing is usually
  not clean, leaving infection possible even bandaged.
  Splints: unneeded through a wooded area, wise for a
  mountain or desert crossing - a couple of straight,
  short 2-3-foot rigid pieces bound along a broken limb
  to keep the bones aligned, or a large thick leather or
  untanned hide if large and rigid enough to immobilize
  the limb and both-side joints like a plaster cast.
  Stretcher: parts carried separately and assembled when
  needed - two poles at least as long as the victim
  height, sturdy cloth or leather to recline on, rope
  or cord to bind the poles to the edges; two comrades
  carry, each supporting half the weight unencumbered.
  Litter: a stretcher plus extra rope binding the victim
  to the frame; ONE carrier (or one mount or beast of
  burden) suffices at half the weight; unwise over rugged
  or very rugged terrain - one end always drags and the
  victim is jostled; the DM may rule further damage from
  the rough handling. THE SETTLE: two-way clean on the
  first pass - both readers agree on every number (the
  2-3 feet, the two poles, the half-weight bars); the
  skin-ailments and other-injuries prose at the top of
  the page belongs to the R480 injuries chapter and
  stayed out of scope. The spec md5 pair: authored
  54d42cfda2a8a2538442c3f461ee9f0b, as-built
  d7741c58547bad556b62349fcce20c6d (the Termux md5 hit
  the +nl pair value exactly). rverify at 414dbb3: 24
  mutants, 0 missed; inline_count 24 (8 consts + 16
  bools); census 405 -> 406; the gap flips 107/79 ->
  108/78, and the medicine chapter (R478-R481) is closed.
  Next: R482 - normal vision (p. 72)
- R482 LANDED 2026-10-15: commit c221b26 (census 407, pushed
  5fe385c..c221b26), the WSG NORMAL VISION slice, printed
  p. 72 - the first vision-and-visibility round, a pure
  prose round with NO table (Table 41 waits at p. 73):
  pinned as rules/wsgnvis.h with the include after wsgfae.h
  at line 187 (prefix wnv, free; nvi and vis both collided).
  The chapter frame: as many as three visual senses -
  normal vision, infravision, ultravision - each with
  advantages in some situations. The definition: normal
  vision is what humans and most creatures use most of the
  time, seeing images and colors within the visible
  spectrum between infrared and ultraviolet. The ranges:
  in clear air during daylight the effective range is 500
  yards (size M recognized by basic form), size S visible
  from 250, size L from at least 1000 - or much greater
  for a dragon or a tall building. The obstruction and
  elevation semantics: anything in the line of sight
  obstructs, ideal conditions are rare at shared ground
  elevation; the worked example - a six-foot orc on a
  flat plain visible at 500 yards drops to 250 (as if
  size S) under three-foot grass because only half its
  body shows; a lone mountain peak sees for miles but
  the range is unchanged - still within 500 yards of a
  size M to identify it; the converse: the man on the
  peak is himself recognizable within 500 - long-range
  visibility a blessing and a curse at once. THE SETTLE:
  two-way clean on the first pass - both readers agree on
  every number (the 500/250/1000, the three senses, the
  six-foot orc, the three-foot grass); the pdfy header
  line reads VIS1, a running-head artifact, not content.
  The spec md5 pair: authored
  c5f36505a7a8429003079ce4c25c243d, as-built
  80569c22828cb5d5aa0c78bbde0f8d6c (the Termux md5 hit the
  +nl pair value exactly). rverify at 5fe385c: 20 mutants,
  0 missed; inline_count 20 (8 consts + 12 bools); census
  406 -> 407; the gap flips 108/78 -> 109/77, opening the
  vision chapter.
  Next: R483 - infravision (p. 73) with Table 41
- R483 LANDED 2026-10-15: commit 19d5d92 (census 408, pushed
  c221b26..19d5d92), the WSG INFRAVISION and TABLE 41 slice,
  printed p. 73 - the second vision-and-visibility round,
  a TABLE round: the heat-vision definition (infravision sees
  the shapes of objects by sensing radiation in the infrared
  spectrum; all nonhuman player characters have it, most out
  to 60 yards outdoor scale, halflings other than pure-
  blooded Stouts 30, drow duergar and deep gnomes 120) and
  Table 41, the outdoor range of normal vision in yards for
  six conditions across four light levels - clear 500/300/
  50/25, overcast 400/250/50/25, moderate fog 150/100/25/15,
  heavy fog rain or snow 50/30/15/10, heavy snow with wind
  35/25/10/5, blowing sand or dust 20/20/10/5 - plus the
  size semantics (the range spots a size M object that
  stands out, double for size L, halve for size S), the
  long-range concentration and no-concealment assumption,
  the prone orc and three-foot-grass hiding rules, the
  daylight dual-scan gaze discipline (long and short range
  at once, full speed, gaze shifting every few seconds) and
  the moonlight/darkness footing discipline (scan degrades,
  a lone traveler watches his footing, a group splits
  lookout duty, stop-and-peer is safest but no guard
  against a nearby silent moving hazard). THE SETTLE:
  two-way clean on the first pass - the tesseract, pdfy
  and tsv reads agree on every number of the page (all 24
  grid cells, the two-line rows confirmed cell by cell);
  the infravision paragraph cuts mid-word at the page
  bottom, its continuation riding with p. 74. The spec
  md5 pair: authored 78259c1a4bebd3277a7c3b0fb8ea9eb7,
  as-built 211f29db9d605adff4e6a5672077f63d (the Termux
  md5 hit the +nl pair value exactly). rverify at c221b26:
  51 mutants, 0 missed (24 grid cells + 7 consts + 20
  bools); inline_count 31; the include lands after
  wsgnvis.h at line 188; census 407 -> 408; the gap flips
  109/77 -> 111/75 (both the infravision prose box AND the
  Table 41 box), the R482 seed record in place.
  Next: R484 - ultravision (p. 74)
- R484 LANDED 2026-10-15: commit b800d4a (census 409, pushed
  19d5d92..b800d4a), the WSG ULTRAVISION and infravision
  effectiveness slice, printed p. 74 - the third vision round,
  a prose round with a pin-table interior (no printed grid):
  pinned as rules/wsgultra.h with the include after wsginfra.h
  at line 189 (prefix wuv, free on the first probe). The daylight
  bar: infravision is useless in daylight or artificial
  illumination stronger than moonlight, the visible light
  overriding the heat radiation. The heat-as-light color scale:
  1 pitch black (below -50) through 10 excruciatingly bright
  (above 130), all ten temperature bands pinned with their
  contiguity checked at audit time. The surface-temperature
  examples: the 98-degree human brighter than his surroundings
  at air 90 or lower, demi-humans the same, the bundled man
  matching the air and undetectable save small uncovered
  spots; obstruction blocks as with normal vision but a great
  heat source is indirectly detectable - the campfire behind
  the rock shows as a dark shape on a lighter background. The
  extremes: below -50 all pitch black, above 130 blinding, and
  sudden close heat (a wall of fire) inflicts heat blindness -
  burned out until cure blindness, or temporarily blinded for
  5-10 turns (1d6+4). The cold-blooded bar: reptiles, insects
  and most nonmammalians undetectable at air temperature, but
  magic that abruptly changes the air reveals them briefly.
  Ultravision: the ultraviolet night vision - only the deep
  gnome has it inborn, to 30 yards as if by daylight normal
  vision; others gain it by magic (lens or spell, MU or
  illusionist); useless under any light brighter than
  moonlight - daylight shows nothing but blackness; best on a
  moonless clear night, the five sky modifiers 2/3, 1/2, 1/3,
  1/4 and thick cover 1/4 cumulative - the thick forest on a
  moonlit overcast night leaving 1/16 of ideal range. THE
  SETTLE: the five fractions were the contested cells - both
  text readers garbled the stacked fraction slashes and the
  vision reads repeatedly pattern-completed line one to 1/2;
  settled by the first full-list read, the pdfy text layer
  (X 2/3 with a real slash), an independent published
  transcription of the WSG list, and the book's own 1/16
  worked example confirming both 1/4 entries. The artificial
  illumination section opens at the page bottom, cut
  mid-word - out of scope, waiting for R485. The spec md5
  pair: authored d8dc6d703b991b21f8b43e4a43888eaa, as-built
  e9b3c6d614569d4ac507f5913e7ee2bf (the Termux md5 hit the
  +nl pair value exactly). rverify at 19d5d92: 71 mutants,
  0 missed (37 consts + 34 bools); inline_count 71; census
  408 -> 409; the gap flips 111/75 -> 112/74 (the ultravision
  box), the R483 seed record in place.
  Next: R485 - artificial illumination (p. 74, continuing
  onto printed p. 75)
- R485 LANDED 2026-10-15: commit e9d27ae (census 410, pushed
  b800d4a..e9d27ae), the WSG ARTIFICIAL ILLUMINATION slice,
  printed pp. 74-75 - the fourth and final vision round,
  CLOSING the vision and visibility chapter (R482-R485), a
  pure prose round with NO table: pinned as rules/wsglight.h
  with the include after wsgultra.h at line 190 (prefix wli,
  free on the first probe; wai/wal/wil/art all collided). The
  twilight frame: the section supplements the PHB p. 102
  statistics; an artificial light source in moonlight or
  darkness lets the illuminated see with normal vision as if
  the natural light was twilight (daylight for a continual
  light spell), but the light source's specified radius takes
  precedence over the Range of Normal Vision Table - the
  torch holder on a clear night sees only his 40-foot radius,
  though real twilight under a clear sky would show 300
  yards unaided. The torch wind bands: below 10 mph the PHB
  figures apply; 11-25 mph the flame struggles and flickers,
  reliable illumination only to 30 feet instead of 40 and a
  burn of 4 turns instead of 6; 26-40 mph the radius holds but
  the flame lasts only 2 turns, with a 25% chance checked
  every five rounds of wind-extinguishing and reignition;
  above 40 mph a torch cannot be kept burning more than 1
  round. Lighting takes 1 round plus 1 per 10 mph of wind,
  halved with fire building proficiency; a lighted torch is
  seen from 200 yards. The lantern and bullseye: protected
  flame, no flicker, constant radius; regular lantern light
  seen from 100 yards, the bullseye beam 200 yards looking
  back toward the source or 100 yards across the beam path.
  Magic weapons: smaller area than torch or lantern, no
  fuel, no wind effect, the glow seen from ten times the
  radius - dagger 100, short sword 150, long sword 200 feet.
  Campfires: small 80-foot radius, medium 120 feet on all
  sides, large at least 150 feet. The group visibility rules:
  any artificial light limits long-range visibility for
  everyone within the area - the lantern holder cannot make
  out details beyond his 30-foot radius, but someone at the
  fringe still sees normally into the darkness ahead, and the
  DM tracks who carries light and where the others stand.
  THE SETTLE: two-way clean on the first pass - tesseract,
  pdfy and tsv agree on every number (the wind bands, the
  30/40 feet, the 4/6/2 turns, the 25% and five rounds, the
  200/100/200/100 yards, the 100/150/200 glows, the 80/120/150
  campfire radii, the 30-foot lantern); the tesseract /arge
  is an italic-L scan artifact, pdfy reading large cleanly;
  the section's p. 74 tail opening (cut mid-word in il-) is
  pinned with this round. The spec md5 pair: authored
  601bdcdb475a1e7ccfc91d4cbcadcd67, as-built
  abf5b1854f6f17dcefc8d50e380c74b5 (the Termux md5 hit the
  +nl pair value exactly). rverify at b800d4a: 51 mutants,
  0 missed (32 consts + 19 bools); inline_count 51; census
  409 -> 410; the gap flips 112/74 -> 113/73 (the artificial
  illumination box), CLOSING the vision chapter, the R484
  seed record in place.
  Next: R486 - volcanoes (p. 76), opening the natural
  hazards chapter (pp. 76-83)
- R486 LANDED 2026-10-15: commit 908b31b (census 411, pushed
  e9d27ae..908b31b), the WSG NATURAL HAZARDS opener slice,
  printed pp. 76-79 - the FIRST content-density round (the
  post-R485 scope decision): four pages in one round, pinned
  as rules/wsghazd.h with the include after wsglight.h at
  line 191 (prefix whz, free on the first probe across all
  277 rules headers, regtest, both caller TUs, the seed and
  the gap report). The volcano frame: three eruption types -
  lava, ash, explosive - each volcano locked to one type,
  dormant volcanoes awakening in days or hours, the
  perpetually active ones spitting reminders every few
  weeks. Lava: magma inside, lava expelled; fluid magma
  sprays less violently; side fissures dissipate but never
  eliminate the crater flow; incinerates even barely flowing
  and retains serious-burn heat 2d3 weeks after stopping; a
  mobile character almost certainly avoids the 250-yd/hr
  flow, but pyroclastic bombs and blocks are the greater
  danger. The 1d4 lava bands: 1-2 fluid 2d6 days, 1d6/turn
  within 500 yd, +50 deg at 1/4 mi tapering 10 deg per
  1/4 mi to nothing at 1.5 mi; 3 thick 2d4 days, 1d4/turn,
  +30 deg dying at 1 mi; 4 thick plus pyroclastics, 1%/hr
  within 1000 yd hit for 2d6, +5%/hr and +1d6 per 100 yd
  closer. Ash: overshadowed lava, seldom violent past the
  opening blast; 2000-3000 ft opaque cloud, lighter ash
  dozens of miles settling 3-4 in; kills green plants yet
  is a supreme fertilizer; St. Helens 1980-81, six
  incidents over 10 months, mudslides over 100,000 acres,
  the 10-megaton May 18 blast flattening trees 4 mi out, the
  peak 9,677 to 8,364 ft. The 1d6 ash bands: 1-3 light
  12+ hr/day for 1d4+2 weeks, 2 in at 1d10+15 mi, 6 in
  within 1d6+4 mi, 1d3/turn within 2000 yd, save vs breath
  weapon/turn against a choking fit (-4 atk, +4 to be hit),
  two straight fails 1d4/round dying without aid in one
  turn; 4-5 heavy 1d6+5 hr/day for 1d3 weeks, 1d6+9 mi,
  9 in within 1d6+2 mi, danger zone 4000 yd; 6 heavy plus
  pyroclastics the first 3-8 days. Explosive: the salvo
  blows the top off; sight range mortal - the cloud and the
  3-5-mi glowing avalanche exude double-strength cloudkill,
  half a round of breath slaying below 8+1 HD, 8+1 to 10+1
  saving at -4, above saving normally; 1d3 days of warning
  first. Earthquakes: fault-line pressure, shock waves
  outdamaging the shift, quakes triggering quakes,
  aftershocks for days. Light: seconds of shiver, no direct
  harm, but spells ruined, the jostled trap-working thief
  failing 50%, the tightrope walker halved and falling
  without a Dex Check. Moderate: 10-15 sec (d6+9), 20%
  shorter, 30% longer to 30; both Dex+Str to straddle a
  limb, Climbing -50%, specialist missile -2 save point
  blank, non-specialist -3/-5/-7, melee -3 with slip-and-
  fall on a miss, rockfall/mudslide, 1-in-8 uprooted tree,
  the fissure with falling/abrasion/crush. Severe: all
  doubled, Climbing -100%, melee -6, 40-90 sec (1d6+3
  tens), hit the ground. Tidal waves: undersea cataclysm,
  the ocean passing the force on for thousands of miles;
  sighted 1/2 mi out, >=150 mph, <30 sec warning, >=75 ft
  by 500 ft, ~30 million gallons; several miles inland at
  20 mph, the 5,000-ft cliff sparing those hundreds of
  yards back while the 20-mi lowland fears as much as the
  coast; the direct-path victim dies. THE SETTLE: two-way
  clean on the first pass - the tesseract, pdfy and tsv
  reads agree on every number of all four pages; the
  garbles settled without contest (17/ and 1V2 both 1.5
  miles, /s and V4 the 1/4-mi reference distance,
  underatreehasa1in 8 is under a tree has a 1 in 8, the
  book's own crevasse spelling stands, (1d6 +3) beside
  40-90 seconds is tens-of-seconds notation). Printed p. 79
  ends mid-sentence at and he will - the tidal wave
  death-rule continuation rides with R487, and the tidal
  waves box stays open. The spec md5 pair: authored
  0c00efe722f1bccb4b6964cb2fde1c8e, as-built
  2e016efec5fbb629d3d4daa70068c506 (the Termux md5 hit the
  +nl pair value exactly). rverify at e9d27ae: 160
  mutants, 0 missed (95 consts + 65 bools); inline_count
  160; census 410 -> 411; the gap flips 113/73 -> 118/68
  (volcanoes, lava, ash, explosive, earthquakes - the
  tidal box held open), the R485 seed record in place.
  Next: R487 - the tidal wave death-rule tail plus floods
  and flash floods (p. 80), continuing the natural hazards
- R487 LANDED 2026-10-16: commit 5fa9bdf (census 412,
  pushed 908b31b..5fa9bdf), the WSG NATURAL HAZARDS CLOSER
  slice, printed pp. 80-83 - the chapter CLOSED in two
  content-density rounds. Pinned as rules/wsghazd2.h with
  the include after wsghazd.h at line 192 (prefix whz2 -
  free on the first probe; the natural first choice wfl
  collided with the R475 fire-fuel round, so the wsghazd2
  pairing carries the round), 111 inlines: 52 consts + 59
  bools in seven sections - the tidal death tail, floods,
  the flash-flood survival chain, avalanches, rockfalls,
  mudslides and quicksand. The tidal wave death tail
  landing from the R486 cut: the direct-path victim
  drowns shortly after being knocked unconscious, the
  late inland hit survivable by going with the flow for
  the swimming-proficient, the non-swimmer doomed even at
  the very end, the DM judging the circumstances. Floods:
  water flows downhill and spreads beyond its container,
  from heavy rain or a snowmelt heat wave, worse over
  frozen ground, usually beside a river or lake; the flash
  flood is fleeting - minutes, not days - mountainous
  terrain without a water body, a trickle at 10,000 feet
  a 30-50 mph torrent at 5,000; avoid a pass or gully
  within 2-3 hours of rain. Caught: the swimmer avoids
  drowning but not the battering, the non-swimmer treads
  toward refuge, the protrusion grab a Strength Check
  with 1d3-to-1d6 batter damage on failure and a
  re-check every 2 rounds while holding; d6+9 rounds at
  any point, 3d8 hours of afterflow. Avalanches: snow or
  ice needing a 12-inch cover, warm sun and bare rock
  favoring; growing as it falls, worst at the slope base;
  2d10-to-3d20 damage halved by curling, bend bars to
  avoid being swept while standing, a 50 percent hold
  while huddled; 2d3 feet of burial, 4d3 at the bottom;
  a Con Check for consciousness; 1 foot per round of
  self-dig with a secret Wis Check for direction unless
  huddled and oriented; the 10 percent find chance plus 1
  per intelligence and 25 for a digging victim, checked
  per searcher per victim; 2 and 3 feet per round of
  rescue digging, three diggers plus 1 foot each; 1d6+4
  rounds of trapped air then breath-holding and Con
  Checks. Rockfalls: freeze-thaw cracks in valley-walled
  peaks, crumbling faces every 2 months, loose rock the
  tell; the slope attack 4 per round for 1d4+1 rounds at
  5 HD for 1d4 each, Dex halving but never below 1, more
  than 20 points sweeping the victim down; the shield
  overhead intercepts 75 percent given both hands and a
  round from the back or a half from the belt; the cliff
  face 1-2 rounds at 7 HD and 1d6, the count from 1d4-1
  if warned or 1d6-3 if not, a Climbing Check on any roll
  of 3 or more and unconsciousness on two 5-or-6 head
  hits; the base 10 HD and 1d8 with the same head rule
  and no chance of falling. Mudslides: thick loose
  topsoil drenched on a moderate or severe slope,
  half-water mud on the moderate slope and less on the
  severe; grab rooted vegetation or ride down unhurt
  unless the valley collects a sinking depth; the
  swimmer rides on top at 1 inch per round, the
  non-swimmer treads for half his afloat time then
  Strength Checks per round and breath and Con Checks
  below. Quicksand: saturated swamp ground, sandy faster
  than muddy, no suction - tread and swim to safety, the
  pole rescue for a non-swimmer, only a
  swimming-proficient rescuer may enter. THE SETTLE:
  two-way clean on the first pass; the garbles settled
  without contest (lo% is 10 percent - the italic-L
  artifact seen at R484 and R485; l d 3 and ld4/ld6/ld8
  are the 1d classes; bend bars the book's own term; 1"
  the 1-inch move rate; lenghtens the book's own
  spelling). Pdf page 82 (printed p. 81) is the
  full-page avalanche illustration plate - empty in both
  readers by nature, so the empty page-82 tesseract reads
  were a puzzle solved, not a failure; the three text
  pages carry the full two-way evidence. The delivery
  detour: the daily upload limit was hit, so the
  extraction reads traveled by the git route - a scratch
  repo in ~/wsgx pushed to the r487-extraction branch
  (still on the remote - delete it when convenient),
  fetched raw and settled from there; the Termux ritual
  then committed the reads into the main tree as
  p08x_full.txt/p08x_tsv.tsv pairs (the first time
  extraction evidence rode inside a round's commit -
  acceptable since the reads back the spec's provenance,
  and the preflight [4/5] note confirmed them). The spec
  md5 pair: authored 9ed54e4e18c5e1e3803ea71c39c252e5,
  as-built 5b3fefed08c5cac6d5a78b07c783e029 (the Termux
  md5 hit the +nl pair value exactly). rverify at
  908b31b: 111 mutants, 0 missed (52 consts + 59
  bools); inline_count 111; census 411 -> 412; the gap
  flips 118/68 -> 122/64 (tidal waves, floods, the
  avalanches-rockfalls-mudslides box and quicksand), the
  R486 seed record in place. Next: R488 - fighting while
  climbing (printed p. 84), OPENING the wilderness
  combat chapter - the last WSG chapter (pdf pages 85-88
- R488 LANDED 2026-10-16: commit 1ac64e0 (census 413,
  pushed 5fa9bdf..1ac64e0), the WSG WILDERNESS COMBAT
  opener slice, printed pp. 84-87 - OPENING the wilderness
  combat chapter, the last WSG chapter. Pinned as
  rules/wsgfight.h with the include after wsghazd2.h at
  line 193 (prefix wfc - free on the first probe), 145
  inlines: 68 consts + 77 bools in nine sections - the
  chapter opener with the DSG pp. 30-34 cross-reference,
  fighting while climbing, precariously balanced, in
  water, in poor visibility, the inclement weather note,
  melee from a mount, missile from a mount and the
  dismount section through the p. 87 cut. Climbing: no
  dex AC bonus (the low-dex penalty stays), one hand on
  the surface, rear-attack vulnerability except from an
  adjacent climber, the strapped shield one step small
  and two large, -2 on a cliff face and -1 on a severe
  slope, +2/-2 elevation on the cliff and +1/-1 on the
  slope, combat damage forcing a Climbing Check (+10
  percent on the severe slope) and a half-total-hit-point
  hit forcing one at -10. Balanced: a melee miss forces
  a Dex Check, -4 knee-deep in mud and -2 on a wide
  ledge, unconsciousness or a 10-percent-of-hit-points
  hit at height forcing a Dex Check at -2 per foot from
  the edge, none needed 10 feet back, the nine-foot -18
  with 19-20 failing anyway, the sleep-spelled
  knee-deep victim and the face-down loose-soil victim
  both facing Con Checks, the knockdown recovery five
  segments or a full round at +4 on a slippery surface.
  Water: -1 waist, -2 chest, -4 over, damage floor 1,
  the attacker shares the penalty, aquatic natives
  exempt, the swimming-proficient halve the deep
  penalties. Poor visibility: -1 moonlight, -3 natural
  darkness, -4 total, vision bonuses cut a quarter and a
  half and negated, the total-darkness wild swing at 0
  or less modified hitting within twice weapon length
  (50 percent in natural darkness), the climbing cut 5
  and 10 percent and the precarious modifier +1 and +2.
  Mounts: +1 same size, -1 smaller, the footman -1 with
  the exact-number hit striking the mount, the airborne
  +1 (+2 swooping), the braced 3-foot weapon +4 forfeit-
  ing the dex bonus, riding proficiency and both hands
  for missiles, no longbow or heavy crossbow, one
  rate-of-fire step down the 6/1-to-1/1 scale (the
  javelin 5/2 to 2/1) never below 1/1, -1/-3/-5 by mount
  speed, the 45-degree and complex-maneuver bars, DMG
  p. 53 short-as-medium and medium-as-long unless
  hovering. Dismount through the cut: the land mount
  death dropping the rider (the proficient check or the
  1d3 tumble and a two-round recovery), the flying mount
  below half hit points checked every round, the natural
  20 unseat with a 3-foot weapon against the proficiency
  check, the ground 5-to-9-foot weapon at 20 and the
  10-foot at 16-20, the pull-down grapple at -4 unmounted
  with both falling 1d6, the cling to-hits each round and
  the rider's -2 attack on the grappler - the p. 87 cut
  is mid-sentence in the flying-mount-death text and the
  close-to-the-ground tail rides to R489 exactly as the
  tidal tail rode to R487. THE SETTLE: two-way clean on
  the first pass; the garbles settled without contest
  (the layout rate-of-fire scale 611 511 411 311 512 211
  312 111 is 6/1 5/1 4/1 3/1 5/2 2/1 3/2 1/1 with the
  slash rendered as a one - tesseract confirms with 6/1
  and the javelin 5-every-2 reduced to 2-per-round
  anchors the scale; the tesseract em-dash class matches
  the layout minus; + I is +1). One build lesson: the
  double-run first hit the R420 mixed-state abort
  because the prev_seed_key spanned a line break in the
  R487 record (pushed fell to line 2) - the seed key
  MUST be the record's exact first line, ending at the
  column-78 wrap, never mid-phrase across the wrap;
  fixed and re-verified GREEN. The spec md5 pair:
  authored dce33ce108505b1f4182857927a39e4e, as-built
  fd6f30ec24e43a651e9cc79ec891f172 (the Termux md5 hit
  the as-built exactly). rverify at 5fa9bdf: 145
  mutants, 0 missed; census 412 -> 413; the gap flips
  122/64 -> 128/58 (six boxes; the dismount box held
  open for its tail). Next: R489 - the forcing-
  opponents-to-dismount tail plus the rest of the
  combat chapter through its end, likely CLOSING the
  chapter (pdf pages 89-92 for printed pp. 88-91)
- R489 LANDED 2026-10-16: commit c11cbe1 (census 414,
  pushed 1ac64e0..c11cbe1), the WSG FATIGUE CHAPTER
  slice, printed pp. 87-89 - CLOSING the wilderness
  combat chapter with its dismount tail and LANDING
  the full fatigue and exhaustion chapter. Pinned as
  rules/wsgfatig.h with the include after
  wsgfight.h at line 194 (prefix wft - free on the
  first probe), 120 inlines: 65 consts + 55 bools in
  five sections - the chapter opener, the p. 87
  dismount tail, Characters, Land-based mounts and
  pack animals, Flying mounts. The R488 "cut"
  settled as a column wrap WITHIN p. 87, not a page
  cut: the right column carries "Dungeon Master may
  allow a character with proficiency in riding the
  mount to leap from its back and land safely on
  the ground" - the dismount section was complete
  and only the connective pin rode to this round,
  CLOSING the combat chapter. Characters: the
  4-turn strenuous risk (over-full movement, melee,
  climbing, swimming against a current, severe
  encumbrance), the 2-turn rest to avoid it, the
  6-turn first Constitution Check, 5 more turns on
  success with the interval shrinking 1 turn per
  success to a minimum of 1, fatigue dropping every
  ability score except comeliness by 2 until 2
  consecutive hours of rest (the Str 18 / Con 18 /
  Wis 14 examples: +1 to-hit lost and +2 damage to
  +1, 2 hp per hit die at a temporary 16, both
  bonus 1st-level spells lost with a spell-failure
  chance at an effective 12), checks reading the
  current score, a further -2 on attacks and saves,
  the per-turn Con Check while continuing with
  failure meaning exhaustion (another -2 and no
  voluntary action except when failure to move
  risks death), the 1-hour rest plus a check to
  leave only fatigue then 2 more hours, and the
  rest-while-carried and rest-tied-to-mount rules.
  Land-based mounts: 2 days without food and water
  or 3 days short rations fatigues, full ration plus
  8 hours rest recovers, overwork recovery 12 hours
  plus 2 per hour overworked (the 3-hour horse
  resting 18), fatigued half movement with
  1-round-per-turn bursts, the 3-inch terrain bar
  (the loaded horse and the camel in very rugged
  ground), 2 armor class places worse (7 to 9),
  only the animal-handling proficient calming the
  excited fatigued animal and only at the
  nonproficient chance, the cumulative 20% per hour
  exhaustion chance with the 1-hour reset, the
  collapse ladder 25/50/75, the oblivious exhausted
  animal that neither panics nor defends itself,
  the flat 50% death chance within 1d4 hours, and
  the 1d6-3 trauma drain through the 8-hour
  critical period with the 2-per-hour regain.
  Flying mounts: never exhausted; the stamina first
  number is the safe flying time (reduced when
  heavily loaded), past it a 1d10 per turn with the
  fatigue chance 10 minus the rest number (the
  black dragon 24/6 fatiguing on 1-4), flying and
  rest not in full blocks (the 30-turn window with
  24 aloft and 6 rest; the 7-turn last flight
  risking fatigue), exceeding then landing demanding
  a full rest, fatigue dropping the rate to
  two-thirds with 10 yards of altitude lost per
  round, the same-turn safe landing within 100
  yards, past that the second-turn steep dive with
  1d2 buffet damage per 10 yards dived halved for
  airborne-riding proficiency or secure strapping,
  the unstrapped rider thrown for 11-40 (3d10+10),
  and the 3-times post-fatigue rest refusal (18
  turns for the dragon) unless self-preservation
  dictates. THE SETTLE: two-way clean on the first
  pass (the layout l d 4 / l d 6 / l d l O / l d 2
  classes are 1d4 1d6 1d10 1d2; Constutition and
  conscutive are book typos; tesseract confirms 24/6,
  1-4 on 1d10, 1d2, 11-40, 18 turns, the 25/50/75
  ladder, 0-3, 2 per hour and 20%/hour). One
  delivery note: the Termux md5 hit the as-built
  exactly (964ca60dc49164730d224fe09a19ff8c); the
  authored canvas body md5 was
  edb1f9beec90f191c13c3902988147d3 and the two
  differ by bytes only - the pushed spec json
  compares semantically identical to the canvas
  body (the user's save path re-serialized it), the
  engine and rverify validated the content, so the
  pair rule stands: authored = the canvas body,
  as-built = what Termux saves. rverify at 1ac64e0:
  120 mutants, 0 missed; census 413 -> 414; the gap
  flips 128/58 -> 132/54 (four boxes: the dismount
  box plus all three fatigue boxes; the mounts and
  beasts catalog boxes stay open). Next: R490 -
  the MOUNTS AND BEASTS OF BURDEN catalog, printed
  pp. 90-94 (pdf pages 91-95; the reads for printed
  pp. 90-91 are already in hand from the R489
  extraction batch), opening with the ape/gorilla,
  bear, camel and dog entries and the animals-as-
  individuals section
- R490 LANDED 2026-10-16: commit 86a2308 (census 415,
  pushed c11cbe1..86a2308), the WSG MOUNTS AND BEASTS
  OF BURDEN chapter slice, printed pp. 90-94 - CLOSING
  the chapter. Pinned as rules/wsgmount.h with the
  include after wsgfatig.h at line 195 (prefix wmb -
  free on the first probe), 185 inlines: 80 consts +
  90 bools + the 15 Table 42 switch columns in
  seventeen sections - the opener, the twelve-animal
  catalog (ape/gorilla, brown bear, camel, sled dog,
  donkey, elephant, horse, mule, pony, giant ram,
  sheep, yak), animals as individuals, Table 42, the
  reaction bands, calming, understanding. The catalog:
  the gorilla (highest intelligence, point man, the
  1-in-6 surprise cut, the 50-degree floor, the 50-50
  lethargic-or-aggressive desertion, 10x food / 8x
  water, the 25% foraging no-return), the bear (magic
  to carry, 30% monthly reversion, no swamp or desert,
  8x / 6x), the camel (dromedary hot-desert, no severe
  slope, weak below 50 degrees after two days, the
  bactrian, the two-week fast with the half capacity
  in week two and the 10x / 20x empty refueling), the
  sled dog (the 40-degree ceiling, 2-3 inches of snow,
  the 50% cannibalism after two days, the seven-dog
  optimum with 200/300 gp losses per dog short and 3"
  per three dogs, the four-dog 9/6/3 and single-dog
  6/3), the elephant (command words, the 50-degree
  floor, the 3" forage slowdown, 50/30 rations, the
  50%-per-six-hours bolt after two unfed days), the
  horse (the overloaded one-turn rest per six turns,
  the half-ration bit, the 2% lame per eight rugged
  hours - draft 1% - with 01 at 12 hours and 02
  permanent, 4/4 rations), the mule (the half-hour
  stubborn root with the Strength Check, the
  three-fourths rations for three days), the pony
  (2% lame, 3 rations), the ram (70-degree ceiling,
  6/4 rations rising to 6 water above the 50-degree
  high), the sheep (six per handler, the 50%-per-hour
  unsupervised bolt, 70-degree ceiling, 2/2), and
  the yak (30 degrees, 6/4). Table 42: the 14-animal
  1d12 reaction grid across fire, weather, noise,
  odor and other - noticed / agitated / panicked, the
  bare trailing slash pinned as sentinel 13 (an
  impossible roll = no panic); the census 1/3/3/2/0.
  The bands: the two-round calm window, the 2d3-turn
  panicked flight, the fire commentary (lava and
  magical heat yes, faerie fire no; the quarter-mile
  bonfire and one-mile conflagration sensing), the
  weather sense, the noise habituation, the odor
  pungency bar, the other-quirk menagerie. Calming:
  the proficient every round, the nonproficient 20%
  with two attempts, movement only, the 50-50 motion
  split, the +2 agitated / +4 panicked proficient-
  only modifiers, the re-excitement. Understanding:
  the animal-lore guess vs the sensory guesswork vs
  the certainty. THE SETTLE - the hardest table yet:
  the Mule row defeated tesseract outright (conf 0.0
  on two cells; the row prints in lighter ink) and
  pdftotext dropped the horse-other, mule and pony
  rows entirely. Settled by a TEMPLATE-GLYPH OCR pass
  written from scratch on the 300-dpi png: digits and
  slashes harvested from the same table's confidently-
  read cells, classified by Hamming distance at the
  light-ink thresholds (120/140, not 170) - giving
  mule fire 6/11, weather 6/12, noise 6/11, odor
  7/12, other 6/10/12, agreeing with every tesseract
  fragment it did manage. The elephant noise cell
  first misread 8/17 from row-rule contamination and
  re-settled to 8/12 on the proper band; the camel
  and donkey "other" first glyphs (& and copyright)
  are both 6; the two-number cells end in a bare
  trailing slash pixel-identical to the interior
  slash - settled by ASCII-art rendering of the
  glyph. Layout garbles: 8110112 = 8/10/12 with the
  slash as a one; book typos "greater that that",
  "geta", "eal", "occurin", "1in 6". The md5 pair
  hit EXACTLY this round: Termux md5sum 8d6e2057a3b
  844eefdace037ff8b6331 = the pushed spec bytes; the
  authored canvas body dfc05e1cbdb3acc6618061d062cc
  6dbf compares semantically identical. rverify at
  c11cbe1: 380 mutants, 0 missed (the biggest battery
  yet - the 210 grid cells); census 414 -> 415; the
  gap flips 132/54 -> 135/51 (three boxes; the magic
  chapter boxes stay open). Next: R491 - MAGIC IN
  THE WILDERNESS, printed pp. 95-102 (pdf pages
  96-103), the last WSG chapter: spells, magic items
  and magic under wilderness conditions; extraction
  pass needed (8 pdf pages)
- R491 LANDED 2026-10-16: commit 4e07d5d (census 416,
  pushed 86a2308..4e07d5d), the WSG MAGIC IN THE
  WILDERNESS chapter slice, printed pp. 95-101 - CLOSING
  the chapter. Pinned as rules/wsgmagic.h with the
  include after wsgmount.h at line 196 (prefix wmg - free
  on the first probe), 241 inlines: 90 consts + 150
  bools + the wmgWebThickBand chain in twelve sections -
  the opener, spells A-B, spells C, spells D-F, spells
  G-L, spells M-S, spells T-W, potions, protection
  scrolls, rings, rods/staves/wands, miscellaneous
  magic. The spells: affect normal fires, air walk, airy
  water, alarm, animal summoning, animate object/rock,
  armor (10 degrees), augury, barkskin (half abrasion),
  bee, bind (100 ft of half-inch rope), bluelight
  (2x safe speed), bug (+10%), call lightning (always
  hits, at least half damage), call woodland beings,
  commune (1 fact/level), cone of cold (6 Con max, 1 per
  turn for 1 hour), control temperature, control
  weather (30-40 degrees, druidic 2 steps), control
  winds, cough/giggle/distract, create food & water,
  create water, cure blindness, cure disease, darkness
  (half safe rate), detect snares & pits, dig, dispel
  exhaustion, dry, earthquake (1 mile fault line, 50%,
  1d6 turns), fear, feign death (half exposure), find
  familiar, find traps, firewater (1 pint), flame
  strike (10 ft diameter), forcecage (5%/level, 20-ft
  fall), fumble (-20% or +4), gather, haste (-10%,
  +2), heal, heat metal (chill 7 rounds = 1 hour),
  hold person, insect plague, irritation, item, jump
  (50% on smooth), knot (1d4 min 1), locate animals/
  plants, lower water, massmorph, mending,
  misdirection, PFNM (hail/sandstorm immunity, still
  limited visibility, no lightning, lava not radiant
  heat), rainbow (cantrip chain: 1/round bow, half
  weight bridge, 6-in elevator, 6th-level draughts),
  resist cold/fire, run (1-turn exhaustion, endurance
  exception, runners exempt), shield (2/3 damage), sink
  (4 segments + 4 turns), snare (100% / 50%), stone
  tell, stoneskin (no abrasion, tumble dispels, hail
  one sequence), summon insects (40 degrees = half
  duration), symbol (Wisdom/Constitution Check every
  turn), transmute rock to mud, trip, water walk (2
  man-sized encumbered), weather summoning, web
  (5 ft thickness per 10 ft fall, 10-20-40-60 ladder,
  60 ft max, slope multipliers 2x severe / 4x moderate
  / 8x gentle, abrasion not impact), wraithform (no
  fall damage, cannot cast while falling - smoke
  component). Items: gaseous form (3-30 gale, death
  hurricane), invulnerability (40 ft fall / 80 ft
  tumble, halved beyond), vitality (7 days); scroll
  cold (+40 degrees or tolerable, whichever higher),
  fire mirror, gas (1-in no-wind radius); rings fire
  resistance, free action, protection (plus per die,
  min 1), sustenance (-5, once per 6 turns, natural 20
  still fails), warmth; rod of lordly might (20-ft
  pole Dex Check when severely encumbered, works out
  of charges), staff of swarming insects (40 degrees =
  30+5/level vs 60+10); apparatus of Kwalish, arrow of
  direction, cloak, cube of force (face 5), Daern's
  fortress (windproof, not climate-controlled),
  gauntlets of dexterity/fumbling (+/-10% climbing),
  mantle of Celestian (comfort, precipitation, no
  impact/wind protection), periapt (abrasion only),
  rope of climbing (Grappling Success Table 100%/50%),
  shoes of Fharlanghn (100% gentle/moderate, 80%
  severe/cliff), stone of good luck (+5% climbing,
  -1 die). THE SETTLE: two reads agree everywhere
  except insect plague (tesseract low-confidence 3
  and 12, conf 51/8, lose to the text layer's 9-in
  1.5-in cleric cloud - the 3/4-area math settles it)
  and the web examples (both reads dropped the 0 into
  1-in and 2-in webs; the doubled-40 and quadrupled-
  160 arithmetic proves the 10-ft and 20-ft thick
  webs). Printed p. 102 is ornament-only - the
  chapter ends at printed 101, and the gap-flip plan
  (six boxes) held. The chain lesson: the web
  thickness band (5/10/20 limits, tail 3) and every
  const feed the audit mirror; 243 mutants, 0
  missed. rverify double-run GREEN at 86a2308,
  idempotent at 4e07d5d (applied 0, already 10);
  preflight GREEN (census 416, R491 line 57839).
  md5 pair: authored canvas body 8fd2ae890f71b4a9711
  c60698fd0c3c, as-built Termux-saved bytes a5c9afd4
  0cce5e88132bcae2d9206df6 = authored + one trailing
  newline from the editor (same JSON before it; the
  splice and rverify both parsed the as-built file
  clean). Gap census 135/51 -> 141/45. Next: R492 -
  the WSG DM section, printed pp. 103-106 (pdf pages
  104-107), then the world-of-weather appendix (pp.
  107-119) and the compiled tables (pp. 120-126);
  extraction pass needed (4 pdf pages).
- R492 LANDED 2026-10-16: commit e84e00a (census 417,
  pushed 4e07d5d..e84e00a), the WSG DUNGEON MASTER
  SECTION slice, printed pp. 103-106 - CLOSING the
  section. Pinned as rules/wsgdm.h with the include
  after wsgmagic.h at line 197 (prefix wmd - free on
  the first probe; wdm is taken), 91 inlines: 27
  consts + 64 bools in ten sections - the opener,
  realism vs. fantasy, steps 1-2, steps 3-4, steps
  5-8, steps 9-10, the semi-finished product, scaling
  down, smaller scale more detail, winging it. The
  opener: the faded-world veteran and the first-time
  DM at the crossroads, no going back once the paper
  looks like a map. Realism vs. fantasy: the Earthlike
  assumption (water downhill, no swamp-to-desert
  without a pass), the familiar-features advantage
  (wooden mountains strain disbelief), homo sapiens
  dominant (no methane worlds), the world as
  inobtrusive backdrop, deviations on a small scale
  only (the boiling river, the frost-pulling forest).
  The ten steps: 20-40 miles per hex per the DMG p. 47,
  the 8.5x11 hex sheet covering 1600 x 1250 miles of
  two million square miles at 40 mph, the 50-or-60
  larger scale, the pp. 124-126 hex sheets; the
  coastline outline and sea level; the 10,000-foot and
  5,000-foot elevation lines at 5,000-foot increments;
  planet placement, five climatic regions, prevailing
  winds; rivers high-to-sea with the Mississippi/
  Amazon once-or-twice rarity and the subarctic
  networks, swamps in low wet country; the subtropical
  and downwind deserts (the global wind explanation,
  the rain-shadow explanation); forests near water
  below the tree line; the leftovers as hills or
  plains. Steps 9-10: oases, passes, the river through
  the desert with non-desert banks; the Grand Canyon/
  Death Valley/ Yellowstone features; the fault lines
  at abrupt elevation, seacoasts and mountain axes
  (San Andreas), the 20-to-40-mile hot spots where
  magma lies close, not every line quakes and not
  every hot spot erupts. The semi-finished product:
  the five political guidelines (cities by water with
  sea outlets, resource cities with roads, isolation
  independence with the Switzerland example, rivers
  as boundaries, elven/dwarven enclaves) and the
  Country A/B/C/D iron-ore example. Scaling down: the
  seven-league-boot caveat, the eight-hex cluster
  three wide at one-third (36-12-4-1-and-a-third-
  half-mile ladder), cluster maps on demand. The
  20-to-30-foot small cliff. Winging it: think on
  your feet, the oak-and-clearing example, the cannot-
  uncreate law, hex-paper sketching, between-session
  updates, the framework closing. THE SETTLE: all
  four pages agree two-way - tesseract 87/2 X 11 is
  8.5 x 11, and the 1V3 miles garble is 1-and-a-third
  in the cluster ladder. The extraction lesson:
  pdftoppm -gray writes .pgm, and globbing .png
  yielded four pages of empty tesseract reads that
  the visible-error page-104 retry closed (branch
  b4daf47, thirteen files). rverify double-run GREEN
  at 4e07d5d, idempotent at e84e00a (applied 0,
  already 6); preflight GREEN (census 417); 91
  mutants, 0 missed. md5 pair: authored canvas body
  13b58e2a714d5e969bffbeddb100f1a1, as-built
  26c0d9cbace624d0d775cfc8e704e82c = authored + one
  trailing editor newline (same JSON before it).
  Gap census 141/45 -> 143/43. Next: R493 - the
  APPENDIX: THE WORLD OF WEATHER, printed pp. 107-119
  (pdf pages 108-120), 13 pages, table-heavy (the
  weather generation system); then the compiled
  tables (pp. 120-126). Extraction pass needed (13
  pdf pages).

- R493 LANDED 2026-10-16: commit ceaff98 (census 418,
  pushed e84e00a..ceaff98), the WSG WORLD OF WEATHER
  appendix part 1 of 2, printed pp. 107-111 plus the
  extraordinary-precipitation tail from the top-left
  of printed p. 112 - the weather GENERATION system.
  Pinned as rules/wsgweather.h with the include after
  wsgdm.h at regtest.cpp line 198 (prefixes wwx for
  the pins and wws for the table switch columns -
  both free on the first probe), 170 inlines: 61
  consts + 54 bools + 1 chain + 54 table columns in
  13 sections - the opener and basic assumptions,
  climatic regions, the temperature letter codes,
  Table A1, how to use A1, Table A2, how to use A2,
  Table A3, rain sleet or snow, collecting
  precipitation, the intensity guidelines,
  extraordinary precipitation. Six tables: the
  letter-code scale (26x2), the A1 grid split Lo/
  Mean/Hi (30 rows x 12 months each, -1 sentinel for
  the blank arctic forest row), Table A2 (11 rows
  x 4: steps, precip, wind delta with the -99
  roll-2/roll-12 consult-Special sentinels, wind
  from), Table A3 (33 rows x 12: arctic carries
  desert/hills/mountains/plains/seacoast only, no
  forest or swamp; values 0-5 none through downpour;
  -99 out-of-range default). SETTLE: Table A3 is the
  transcription win - our pdf layout and psm6
  reads are heavily garbled there (psm6 pins only
  temperate hills and tropical mountains
  cell-for-cell); the s0py port disagrees in 19
  cells but all trace to his season-index rotation
  plus his two known errata (subarctic hills summer
  C and arctic plains summer C - transcription
  wins both). The A2 roll-2/roll-12 wind rows rest
  on the transcription alone (header bools
  wwxRoll2WindVeryStrong/wwxRoll12WindVerySlight,
  sentinel -99/dir 0). Two build-authoring bugs
  found and fixed during the round: the draft A3
  dict had garbled row lengths (12-15 chars mixing
  separator dashes with value dashes) - rebuilt
  from the wsgx.htm table parse - and one
  table-check used the wrong A1 row indices (the
  blank forest row instead of hills/mountains).
  Gap flip: ONLY the weather-system child box
  closed this round, 143/43 -> 144/42; the parent
  appendix box and the weather-effects-on-play
  child stay open for R494 (printed 112-119: Table
  A4 special weather, optional rules A5-A8, the
  effects section - R494 flips both and closes the
  appendix). Spec md5s: eedbd6d634d6a5397b2dbb40bb
  5397ab authored / 651390f2777a7daeb6e65083d2e40fd
  8 +nl; the committed spec matched +nl. rverify at
  ceaff98: restore clean, double-run GREEN, 1689
  mutants, 0 missed; preflight census 418, R493
  audit bad 0. Next: R494.

- R494 LANDED 2026-10-16: commit 7dd2f3f (census 419,
  pushed ceaff98..7dd2f3f), the WSG WORLD OF WEATHER
  appendix part 2 of 2 - the weather EFFECTS system
  and the optional rules, printed pp. 112-119. Pinned
  as rules/wsgweathx.h with the include after
  wsgweather.h (prefixes wwy for the pins and wwt for
  the table switch columns), 340 inlines: 220 consts +
  63 bools + 1 chain (wwyCycloneDriftFor, limits 6/7,
  tail 2) + 56 table columns in 25 sections. Nine
  tables: the Roll 2 cross-index (2 rows x 5 bands -
  see the lesson below), Table A4 the 33x4
  special-weather grid (packed base-10 four-letter
  codes A1/C2/D3/G4/M5/S6/T7/X8/Z9), the X dispatch
  (7 temp bands x 12 d6 cols), Table A5 humidity
  (33x4), the day-1/day-2 before and after adjustment
  grids (3x3 each), Table A6 effective temperature
  (25x5), Table A7 wind chill (17x8), Table A8 hours
  of daylight (15 latitude rows x 12 months in
  half-hours). Flips the weather-effects child box
  and the parent appendix box: 146 closed / 40 open -
  THE APPENDIX IS CLOSED; only the compiled tables
  pp. 120-126 remain in the WSG arc. Preflight GREEN
  (R494 WSG weather effects audit: bad 0), rverify
  GREEN (1102 mutants, 0 missed, double-run clean).
  THE R2 DEFECT CLASS (first C++-only catch since the
  battery went compiled): the Roll 2 cross-index was
  first encoded 1 data row x 10 cols with the count
  const wwyRoll2Rows = 2; speclib only walks actual
  data rows so the Python mirror read bad 0, but the
  emitted audit declares CR2[1][10] and loops
  b < wwyRoll2Rows() - row 1 reads out of bounds, all
  10 columns hit the -1 defaults, compiled bad
  EXACTLY 10. Preflight caught it (the audit return 1
  also truncated every audit physically after the
  R494 block, so the census flooded with phantom
  failures - fallout, not defects). The engine has NO
  count-vs-rows gate: a table whose count const
  exceeds its data rows is the R494 class; authors
  MUST check every table's count == len(data) before
  publishing. Fixed by reshaping R2 to the honest 2x5
  (cols wwtR2B24/B56/B7/B89/B1012, data
  [[1,2,2,0,0],[0,0,3,3,4]], inline_count 345->340).
  LESSON (delivery): overwriting an EXISTING canvas
  with a corrected spec body did NOT re-render the
  panel - the user kept copying the stale broken
  version; publishing under a NEW canvas name
  (r494-splice-fix) fixed the copy. When a spec is
  corrected mid-round, publish the fix as a new
  canvas, never an in-place overwrite. The ritual
  block stays pure shell (the user's standing rule);
  the bn launcher is user-side only. User-side spec
  md5 b258419d806323abca35fd5e7a20325d (authored
  865849524c765e9937b16f8fe51c1da1, +nl
  4f1dbaaa49d529e25b14145ac8ed069a - the
  delivery-side newline variance again, cosmetic; a
  c2bf4240... variant of the first (broken) spec also
  appeared - content-identical per the canonical
  sort-keys hash). The A4 grid transcription sources:
  the psm tesseract pass on pdf 113 (commit 52dd5fc,
  branch r493-extraction) with the settled overturns
  (C temperate seacoast, CXMZ subtropical seacoast
  Su, CXMZ subtropical swamp, CXMZ tropical seacoast
  Su low-conf, tropical swamp Wi inferred) and the
  s0py cross-checks for A5/A6/A7/A8; the
  1eonline.info transcription is BLOCKED (403).
- R495 LANDED 2026-10-16: commit 88c0739 (census 420,
  pushed 7dd2f3f..88c0739), the WSG COMPILED TABLES round -
  the play-session reprint section, printed pp. 120-123
  (pdf 121-124), THE ARC-COMPLETION ROUND: every section of
  the Wilderness Survival Guide is now pinned. Pinned as
  rules/wsgtables.h with the include after wsgweathx.h
  (prefix wct), a manifest round: 56 consts + 40 bools, no
  new grids (96 inlines) - the table data lives in the
  original headers; this round pins the compilation itself.
  Thirty of the forty-two book tables reprinted (12 omitted
  for space), each pinned with its from-page (T3:19 through
  T42:92). Reconciled cell-for-cell against the landed
  originals (R425-R494): TWENTY-NINE match; the one genuine
  print discrepancy is compiled Table 32 (fishing success)
  - Fair daytime 1d6-3 vs the original 1d6-2 and Good
  daytime 1d6-2 vs the original 1d8-2 - pinned
  compiled-side as the errata record (rules/wsgfish.h keeps
  the original readings); Night and Dawn-Dusk unchanged.
  Table 4's OCR-shredded attack cells (90-99 = -1,
  100-109 = -2) confirmed by user eyeball and match the
  pin; the R494 out-of-bounds table class could not recur
  (no tables in the spec). Flips the compiled-tables box:
  147 closed / 39 open - THE WSG ARC IS COMPLETE. Preflight
  GREEN (R495 WSG compiled tables audit: bad 0), rverify
  GREEN (96 mutants, 0 missed, double-run clean). ENGINE
  SYNTAX LESSON: example exprs must use C-style operators
  only - Python 'not'/'True'/'False' abort with "an
  operator expected in a audit condition" (the engine
  gate_cond_syntax whitelists + - * / % == != <= >= < > &&
  ||, with ' or ' translated to ' || '); bools must be
  compared as ints: "m['wctT3Matches']() != 1" (True == 1
  in the Python mirror, and valid C++ against the inline
  bool accessor). User-side spec md5
  fc81d915674066597eaa3dbea54633f1 differed from BOTH
  authored newline variants (0dcc7272... no-nl,
  d10cbe70... +nl) - cosmetic only: the engine, preflight,
  and rverify each parsed and validated the content
  end-to-end, so any material difference would have failed
  a gate. The spec was published as the NEW canvas
  r495-splice (never overwrite an existing canvas - the
  R494 delivery lesson). The ritual block stays pure shell
  (the user's standing rule); the bn launcher is
  user-side only.
- R496 LANDED 2026-10-16: commit bd58585 (census 421,
  pushed 88c0739..bd58585), the WSG GAP RECONCILIATION -
  the bookkeeping round: twenty-four boxes that were
  already pinned by earlier rounds flip in one commit.
  NO new book material; pinned as rules/wsgrecon.h
  (prefix wgr, 37 inlines: 13 consts + 24 bools). Eleven
  chapter parents flip, every child closed by R427-R491
  (env effects, encumbrance/movement, food/water,
  camping, medicine, vision, hazards, combat, fatigue,
  mounts, magic). Nine manifest lines flip (Tables 20-27
  and 42, pinned R444-R490). Four movement items flip:
  surface types, surface conditions, chance of falling
  (all inside wsgclimb.h R435) and movement across
  special terrain (wsgvehicle.h/wsgencum.h R434/R432 -
  verified in-header before flipping). Gap report: 147/39
  -> 171 closed / 15 open; the fifteen are the genuinely
  un-pinned prose: the overview chapter (pp. 7-10, 11
  boxes) and the proficiencies prose (pp. 11-17, 4
  boxes). Preflight GREEN (R496 WSG gap reconciliation
  audit: bad 0), rverify GREEN (37 mutants, 0 missed,
  double-run clean). Flip-count arithmetic pinned as
  consts and examples (147+24=171, 39-24=15, 11+9+3+1=24)
  so the reconciliation is itself audited. User-side
  spec md5 433b2e56cc637bb839b7d64504047273 differed
  from both authored variants (5ba8feee... no-nl,
  962b3dda... +nl) - cosmetic, same class as R495
  (every gate parsed and validated the content
  end-to-end). Spec published as the new canvas
  r496-splice. NEXT: only two prose rounds remain for
  full WSG gap closure - the overview (pp. 7-10) and
  the proficiencies prose (pp. 11-17, includes the
  Table 1/2-adjacent nonweapon list and descriptions).
- R497 LANDED 2026-10-16: commit 6276205 (census 422,
  pushed bd58585..6276205), the WSG OVERVIEW OF THE
  WILDERNESS, printed pp. 7-10 (pdf 8-11) - the terrain
  types, the hierarchy, the bodies of water and the
  climate zones. Pinned as rules/wsgoverview.h (prefix
  wov, 85 inlines: 27 consts + 58 bools, no grids).
  Load-bearing pins: the desert under-10-inches rainfall
  definition with the 70-foot dune cap (draa beyond),
  the hills 2,000/4,000-foot guideline bands, the
  mountain 4,000-foot minimum with the Earth tree line
  (10,000) and snow line (12,000), the 1-7 terrain
  hierarchy (seacoast highest) with the two exceptions,
  the five climate zones. Gap report 171/15 -> 182/4;
  only the proficiencies prose (pp. 11-17) remains.
  Preflight GREEN (R497 WSG overview audit: bad 0),
  rverify GREEN (85 mutants, 0 missed, double-run
  clean). The extraction lesson (NEW CLASS): the first
  extraction push 2644f42 was 22 files with 0
  insertions - pdftoppm could NOT write to /tmp in
  Termux, tesseract read a nonexistent glob, and empty
  output files committed silently; ALWAYS make the
  temp dir under $HOME (~/wsgx/tmp), and eyeball the
  commit insertions count (0 insertions = abort).
  Fixed by the forced-update retry 0d5f109 (13,653
  insertions). User-side spec md5
  8bed35c5d021d228acfd3e2444e5c5b8 differed from both
  authored variants (850ec75b... no-nl, 1ac5d3ef...
  +nl) - cosmetic, same class as R495/R496 (gates
  validated the content end-to-end). Spec published as
  the new canvas r497-splice. NEXT - R498: the
  wilderness proficiencies prose (printed pp. 11-17,
  pdf 12-18, already extracted at r497-extraction
  0d5f109): the nonweapon list, the choosing-skills
  rules and the proficiency descriptions - the LAST
  four open boxes; closure at 186/0.
- R498 LANDED 2026-10-16: commit d4f30ee (census 423,
  pushed 6276205..d4f30ee), the WSG PROFICIENCIES
  PROSE, printed pp. 11-17 (pdf 12-18) - THE WSG GAP
  CLOSURE ROUND: the gap report lands at 186 closed /
  0 open; THE ENTIRE WILDERNESS SURVIVAL GUIDE IS
  PINNED, cover to cover. Pinned as rules/wsgprofd.h
  (prefix wpd, 157 inlines: 85 consts + 72 bools, no
  grids). The R425 check/improving/expanding system and
  the Table 1/2 grids stay as seams; this round pins
  the DSG-system frame, the choosing-skills rules and
  all twenty-five descriptions: the healing package
  (1d3 emergency within 1 round, 1/2 hp per day travel/
  rest, the +2 poison save with the 1-turn rest and
  5-rounds aid, the disease step-down with the
  2-consecutive/3-total revert), the hunting party
  ladder 1/3/6/10/15 auto-fail at 6+, blind-fighting
  halved penalties (-2/-4 total, -1/-3 natural),
  direction sense (+4/+2 darkness, 90-degree error,
  natural 20 opposite), both riding feat lists
  (airborne and land-based), rope use (+3/+6 escape,
  +2 lasso, +10 percent climbing), running (the 2x/5
  rounds or 3/2/1 turn sprint, the +3-per-round
  extension, the distance packages), the survival
  shifts (20 degrees, bands 30/80), tracking (5 per
  level plus 5, cap 55 - half a ranger), weather sense
  (6 hours, +2 repeats, 12-hour lockout). Preflight
  GREEN (R498 WSG proficiencies prose audit: bad 0),
  rverify GREEN (157 mutants, 0 missed, double-run
  clean). User-side spec md5 1a348b91f6a013f5b21622b4
  7363019f differed from both authored variants
  (b68975ba... no-nl, 7f4168b2... +nl) - cosmetic,
  the standing class. Spec published as the new canvas
  r498-splice. THE WSG ARC: R425-R498, 74 rounds,
  every chapter, the DM section, the weather appendix,
  the compiled tables, and now the full gap report at
  zero open boxes. Next book candidates: the DSG
  (Dungeoneer's Survival Guide) is the natural next
  wilderness-adjacent pin target; the repo also has
  dmg_gap_report.md and phb_gap_report.md if any
  boxes remain open there.
- R499 LANDED 2026-10-16: commit bcaa323 (census 424,
  pushed d4f30ee..bcaa323), the WSG TEMPERATURE-CHAIN FOLD -
  THE FIRST SEAM ROUND after the gap report closed at 186/0:
  no new book pages. The dressing columns (rules/wsgdress.h
  wsdColForTemp), the Table 9 heat bands and frostbite
  threshold (rules/wsgheat.h wshHeatBandFor), the weather
  letter codes (rules/wsgweather.h wwsTempCodeHi) and the R498
  survival shifts (rules/wsgprofd.h) reconciled as one
  system. Pinned as rules/wsgtempfold.h (prefix wtf, 37
  inlines: 27 consts + 10 bools, no grids, NO gap flips - the
  report stays 186/0). THE FOLD PATTERN (NEW, load-bearing):
  R317/R401 predate the spec engine - no reusable fold spec
  existed, so R499 established the pattern: every seam value
  is re-read from its landed header and re-pinned as the
  fold's own consts, then the cross-header identities are
  proven const-to-const inside the spec's model (examples
  like wtfDressModLo() != wtfNoDmgLo()); the Python mirror
  cannot call other headers, so cross-header calls must be
  expressed as this-round consts - the redundant-but-audited
  pattern, and every identity rides the mutant battery.
  FINDINGS: three true boundary alignments (the moderate
  column and no-damage band 16 open at the same 31; band 15
  and the cold column top at the same 30; the frostbite
  threshold 0 equals the below-0 dress boundary value); one
  deliberate non-alignment (the hot column opens at 76, eight
  degrees INSIDE the 31-84 no-damage band - attire adjusts
  before Table 9 damage resumes at 85); the finer dress grid
  (moderate tops 75, no-damage runs to 84); the protected
  widening (no-damage 6 through 89 vs bare 31 through 84 -
  dash censuses 2 unprotected / 14 protected); the survival
  shifts land inside both (cold 30+20=50, heat 80-20=60).
  Preflight GREEN (R499 WSG temperature fold audit: bad 0),
  rverify GREEN (37 mutants, 0 missed, double-run clean).
  Engine tolerance confirmed: gap_flips:[] passes with the
  census gate on the closed report. User-side spec md5
  ebc706e5556d1a5e3df1845c4715012d differed from both
  authored variants (cf3cad50... +nl, f26b9324... no-nl) -
  cosmetic, the standing class. Spec published as the new
  canvas r499-splice; the user-side bn launcher ran outside
  the ritual block (the R372 rule held - bn was struck from
  the delivered block after a first draft carried it).
  NEXT - R500: another fold (candidates: the water chain -
  swimming/holding-breath/waterborne, or the movement chain -
  climbing/jumping/encumbrance), or the DSG as the next
  book.
- R500 LANDED 2026-10-16: commit 3e269ca (census 425,
  pushed bcaa323..3e269ca), the WSG SWIMMER'S MOTION-CHAIN
  FOLD - the second seam round, the R499 fold pattern
  applied to the water chapter: one swimmer state flows
  through five landed headers - the swimming rates
  (rules/wsgswim.h R450), the moving-water hazards
  (rules/wsgmwater.h R451), the dive leg (rules/wsgdive.h
  R452), the treading economy (rules/wsgtread.h R453) and
  the surfacing/breath rules (rules/wsgbreath.h R454).
  Pinned as rules/wsgswimfold.h (prefix wmf, 49 inlines:
  39 consts + 10 bools, no grids, NO gap flips - the
  report stays 186/0). FINDINGS: the vertical rates equal
  each other (dive base and surface base both 2 inches) and
  are exactly half the horizontal base (20 vs 40 feet); the
  Table 24 dive column matches the dive prose exactly (x2
  moderate, x3 heavy/severe); the encumbrance paradox (the
  moderate speed denominator 2 numerically equals the
  moderate dive multiplier 2 - the same weight that
  halves speed doubles the sink rate); the forty-foot
  agreement (the dive falling-damage threshold equals the
  waterfall save threshold - the headers cross-reference
  each other); the mercy drift cap equals the
  light-current range; the check ladders differ (breath
  Con Checks step +2, treading Str Checks step +1); three
  distinct endurance economies (rest 3/turn, high speed
  1/10, treading 1 point per 2 turns). Honesty fix during
  authoring: the treading example (str 6 -> 12 rounds) is
  doubled by the Table 24 UNENCUMBERED endurance modifier,
  not by the 2-turns-per-point constant - the 2s coincide
  but the semantics differ; pinned as wmfEncMultUnenc.
  Preflight GREEN (R500 WSG swimmer motion fold audit: bad
  0), rverify GREEN (49 mutants, 0 missed, double-run
  clean). Local gates: 42/42 mechanical cross-checks
  against the five headers; the mid-round mixed-state
  engine abort (old spec patches in the tree) resolved by
  refetching fresh bcaa323 - the R420 lesson holds.
  User-side spec md5 5a3d1cb8df82cab5a2b7e45433896a72
  differed from both authored variants (cd038256... +nl,
  35a1e056... no-nl) - cosmetic, the standing class.
  Spec published as the new canvas r500-splice. NEXT -
  R501: the third fold (candidates: the movement chain -
  climbing/jumping/encumbrance/falling, or the camp chain
  - fire/shelter/sleep), or the DSG as the next book.
- R501 LANDED 2026-10-16: commit 77d39de (census 426,
  pushed 3e269ca..77d39de), the WSG MOVEMENT/FALL-CHAIN
  FOLD - the third seam round, the R499 fold pattern
  applied to the climbing-and-falling chapter: one
  falling character flows through seven landed headers -
  the climbing ratings (rules/wsgclimb.h R435), the Table
  17 fall ladder (rules/wsgfall.h R437), the tumble rates
  (rules/wsgtumble.h R438), the stop windows
  (rules/wsgstop.h R439), the slippery-surface cadence
  (rules/wsgslip.h R447), the jump floors
  (rules/wsgjump.h R448) and the airborne fall chance
  (rules/wsgfallair.h R461). Pinned as rules/wsgmovefold.h
  (prefix wmv, 49 inlines: 39 consts + 10 bools, no grids,
  NO gap flips - the report stays 186/0). FINDINGS: the
  Table 17 dice are the TRIANGULAR numbers 1, 3, 6, 10,
  15, 20 (increments 2, 3, 4, 5 - each band adds one more
  die than the previous band added) and the 51-or-more
  band caps at 20d6 ONE DIE SHORT of the pure sequence
  value 21 - the printed maximum breaks the ladder it
  completes; the prose-vs-table tension (the linear
  1d6-per-10-feet understates the printed table at every
  band past the first - 3d6 at 20 feet, not 2d6; the
  table is the authority); the cliff/severe stop window
  of 50 feet is exactly the top of the 41-50 damage
  band; the gentle stop window of 100 feet equals the
  gentle tumble rate minimum; the rate ladder is
  contiguous and strictly ascending (100-300 gentle
  tumble, 300-500 moderate, 600-800 severe, 1000 free
  fall); the slip-to-tumble seam (the horizontal slip
  deals no direct damage, the inclined tumble abrasion
  kills). Preflight GREEN (R501 WSG movement fall fold
  audit: bad 0), rverify GREEN (49 mutants, 0 missed,
  double-run clean). Local gates: 43/43 mechanical
  cross-checks against the seven headers. User-side spec
  md5 923ea3d3181cd30519938565cb664e59 differed from
  both authored variants (36e0114b... +nl, a9dc57fe...
  no-nl) - cosmetic, the standing class. Spec published
  as the new canvas r501-splice. THE FOLD ARC: R499-R501,
  three clean lands (temperature, swimmer motion,
  movement/fall), the R499 pattern fully seasoned. NEXT -
  R502: the camp chain fold (fire/shelter/sleep -
  wsgshelter/wsgsleep/wsgfire/wsgfuel), or the DSG as
  the next book.
- R502 LANDED 2026-10-16: commit 4681d11 (census 427, pushed
77d39de..4681d11), the WSG CAMP-CHAIN FOLD - the fourth seam round, the R499
fold pattern applied to the camp chapter: one campsite flows through six
landed headers - the rest quality and Table 38 fire (rules/wsgfire.h R474),
the fire starting and fuel rules (rules/wsgfuel.h R475), the wildfire rules
(rules/wsgblaze.h R476), the tent quality system (rules/wsgsleep.h R473), the
natural shelters (rules/wsgshelter.h R471) and the R499 temperature chain
re-read for the seam. Pinned as rules/wsgcampfold.h (prefix wmc, 63 inlines:
53 consts + 10 bools, no grids, NO gap flips - the report stays 186/0).
FINDINGS: the wildfire hour (the 6-turn uncontrollable bar equals the 6 turns
per hour - a fire left alone for exactly one hour becomes uncontrollable); the
two-header refuel identity (the Table 38 small-fire refuel interval and the
fuel-header grace period are the same 3 turns); the twenty-mph triple
agreement (the small fire wind resistance, the rest wind-penalty threshold and
the poor-shelter full-protection example - three headers, one number); the
no-start paradox (no fire starts in wind over 30 mph - exactly the wind a
medium fire would have withstood); the arithmetic-vs-geometric split (the fuel
+6, refuel +3, wind-res +10 and spark +10 ladders are all arithmetic; the
growth ladder 1, 2, 4 is the chain's only doubling); THE R499 TEMPERATURE SEAM
ON BOTH SIDES (the rest cold threshold is the same 0 that opens the dress
below-0 column; the rest hot threshold of 90 opens one degree past the
protected no-damage top of 89, at heat band 18); the flat plate loss (5 hours
in plate rest like 1, 9 rest like 5 - a flat 4-hour loss either way); the tent
leak halves the wind step it cannot stop (5 per 10). Preflight GREEN (R502 WSG
camp chain fold audit: bad 0), rverify GREEN (63 mutants, 0 missed, double-run
clean). Local gates: 50/50 mechanical cross-checks against the six headers.
User-side spec md5 d08adacc36cd2e802aafa0f8b3991d89 differed from both
authored variants (533a6a35... +nl, ea20b948... no-nl) - cosmetic, the
standing class. Spec published as the new canvas r502-splice. THE FOLD ARC
COMPLETE: R499- R502, four clean lands (temperature, swimmer motion,
movement/fall, camp), 198 mutants all caught. The WSG mechanical seams are
exhausted; the natural next move is the DSG (Dungeoneer's Survival Guide) as
the next book, opening a fresh pin arc with its own gap report.
- R503 LANDED 2026-10-16: commit c8ec2d1 (census 428, pushed
0e8907a..c8ec2d1), the DSG OVERVIEW OF THE UNDERDARK, printed pp. 7-11 (pdf
8-12) - the arc first content round, the R497 pattern. Pinned as
rules/dsgoverview.h (prefix dov, 58 inlines: 8 consts + 50 bools, no grids).
Load-bearing pins: the pdf = printed + 1 offset (opener on pdf 7 for printed
6); the three-cave taxonomy; molten lava 1,800 F killing non-fire-resistant on
contact; the 10-foot dirt shoring; the realms-deeper-than-a-mile rule; the
living/dead cave mechanics (glisten/mud vs brittle/dust, standing water rarely
stagnant); the five hazard families. Gap report 0/151 -> 5 closed / 150 open:
the overview parent + natural/unnatural/hazards children + the DM TOC closed,
and THE DM SECTION RE-GRAINED from the DM TOC (its own underground-environment
chapter pp. 65-72, cultures 73-74, the 31-area Deepearth key 75-98, campaign
considerations 99-113, mapping 114-117) with the PERSPECTIVE MAPS box (pp.
124-127) the player TOC missed. LESSON: the engine gap_census.open counts
post-flip open LINES, not a hand-subtracted census - the first run died at
150-vs-147; simulate the flips and count. Preflight GREEN (R503 DSG overview
audit: bad 0), rverify GREEN (58 mutants, 0 missed, double-run clean, restore
at 0e8907a). User-side md5 8968bee3 = the authored +extra-blank-line variant,
the standing cosmetic class. The extraction rode the r503-extraction branch
(d8-d12 + d65 full/tsv/png, 18 files; pdf 9 is the cave-formations
illustration plate, labels only - not a failed read). NEXT - the DSG movement
chapter (printed pp. 12-22, pdf 13-23): the BIG cross-book seam
(wsgclimb/wsgswim/wsgrope are its downstream), extraction first.
- R504 LANDED 2026-10-16: commit e4f8c16 (census 429, pushed
a8c86de..e4f8c16), the DSG MOVEMENT CHAPTER PART I, printed pp. 12-19 (pdf
13-20): the check frames, swimming, breath, moving water, climbing,
rappelling, jumping and the rope system. Pinned as rules/dsgmove.h (prefix
dmv, 234 inlines: 119 consts + 91 bools + 2 chains + 6 tables/22 cols; 29
examples, 8 table_checks). Gap 5/150 -> 27/128: 16 chapter boxes (the check
frames through roping together) + the manifest tables 1-6; the movement parent
box stayed open for R505. First SPEC-DRIVEN round (the splice_engine.py +
speclib.py build from tools/spec_rXXX.json). The spec validation had one real
escape - dmvCrossTargetCount (the Table 5 row count) referenced by the header
build but never defined; the engine died KeyError on the first ritual run with
nothing patched (preflight RED, no commit). Fix: add the const, inline_count
233 -> 234, and a full pool-coverage pass before publish (every name in
header_sections, examples and table_checks resolves; every table count const
equals its data row count). LESSON: spec validation must pull every name the
engine will pull, not just lint shape. The two pinned cross-book divergences
stand (DSG strength speed bonus = the strength DAMAGE bonus, both cap +3; the
DSG encumbered jump -4 allowed where the WSG forbids severe jumps); the
printed dive example vs the Table 1 heavy row pinned as printed with the table
the authority (R501 precedent). Double-run applied 26/already 0 then 0/26;
preflight GREEN (R504 DSG movement I audit: bad 0), census 429. User-side spec
md5 46af790e differed from authored b83ba3a0 - cosmetic, the standing class.
GitHub verify at e4f8c16 clean: 234 inlines, zero dmv in caller TUs, gap
27/128, the R503 seed record in place. NEXT - R505: movement part II - the
bridges, the expanded falling rules, spelunking (T7), excavation (T8),
fatigue, darkness (T9) and slippery surfaces; the movement PARENT box flips
when both halves land.
- R505 LANDED 2026-10-17: commit 409150e (census 430,
  pushed e4f8c16..409150e), the DSG MOVEMENT CHAPTER
  PART II - printed pp. 19-22 (pdf 20-23): bridges,
  falling expanded, spelunking, excavation, fatigue,
  darkness and slippery surfaces. Pinned as
  rules/dsgmove2.h (prefix dmx, 130 inlines: 85 consts
  + 40 bools + 3 tables/5 cols; 22 examples, 8
  table_checks). Gap 27/128 -> 38/117: 11 flips - the
  movement PARENT box, 7 chapter boxes (Bridges,
  Falling expanded, Spelunking, Excavation, Fatigue,
  Darkness, Slippery) and manifest Tables 7/8/9.
  T7/T8 fractional feet pinned as inches (x12); T9 as
  degree+direction cols. Seams verified const-for-
  const against the landed WSG headers, nothing
  auto-credited: wsgfall (21-30=6d6, cap 20d6) and
  wsgstop (50ft) agree; wsgslip agrees whole;
  wsgmwater has no cap pin (the 10d6 waterfall cap is
  DSG-only); wsgfatig agrees with ONE framing
  divergence - WSG exhausted = additional -2 where
  DSG says -4 instead of -2 (both total -4), pinned
  as dmxExhaustedInsteadOfFatigue. The R504 record
  rode the prev_seed_key splice. Spec-driven round 2:
  the full pool-coverage validation held - double-run
  applied 15/already 0 then 0/15. Preflight GREEN
  (R505 DSG movement II audit: bad 0), census 430,
  gap 38/117. User-side spec md5 2e7af541 vs authored
  f4b55a00 - cosmetic, the standing class. NEXT -
  R506: the proficiencies chapter pp. 23-29, Tables
  10-13 (seam: the landed wsgprof/wsgprofd material).
- R506 LANDED 2026-10-17: commit b9c1f90 (census 431,
  pushed 409150e..b9c1f90), the DSG NONWEAPON
  PROFICIENCIES chapter, printed pp. 23-29 (pdf 24-30):
  the check system and Table 10, the slot economy, the
  artisans and NPC training, the optional bonuses, the
  craftsman and adventuring lists with Tables 11-13,
  and the XP option. Pinned as rules/dsgprof.h
  (prefix dnp, verified free; 208 inlines: 125 consts +
  68 bools + 4 tables/15 cols; 23 examples, 7
  table_checks). Gap 38/117 -> 50/105: 12 flips - the
  proficiencies PARENT box, 7 chapter boxes, manifest
  Tables 10-13. SEAMS verified const-for-const against
  the landed wsgprof/wsgprofd material, NOTHING
  auto-credited: Table 10 agrees cell-for-cell with the
  WSG Table 1 pins; 10 of 11 shared Table 13 rows
  DIVERGE (the DSG rebalanced them - Rope Use DEX 0 vs
  WSG WIS -3, Healing 2 slots WIS vs 1 slot INT, Riding
  +3 vs +2, Endurance 2-slot NA vs 1-slot WIS; only
  Blind-fighting agrees outright); the shared
  description numbers agree whole; the WSG check
  refinements (auto-fail 19/20, ability cap 18,
  2-in-20 floor) are WG-only, not printed in the DSG
  chapter - not auto-credited. Caution cells pinned AS
  PRINTED per the R501 precedent (Weaver 4/+4,
  Weaponsmith 3*/+3, trainer/armorer slots cells from
  prose, direction-sense roll-of-1 catastrophic digit).
  Spec-driven round 3: double-run applied 16/already 0
  then 0/16, no KeyError; preflight GREEN (R506 DSG
  proficiencies audit: bad 0), census 431, gap 50/105.
  User-side spec md5 62d2966a vs authored 258e56db -
  cosmetic, standing class. NEXT - R507: the DSG combat
  rules for underground play, printed pp. 30-33, Table
  14 (Mounted Bow Fire); EXTRACTION ROUND first, the
  cross-book seam candidate the WSG combat chapter
  (wsgfight.h R488) - nothing auto-credited.
- R507 LANDED 2026-10-17: commit 7403fbf (census 432,
  pushed b9c1f90..7403fbf), the DSG COMBAT RULES FOR
  UNDERGROUND PLAY, printed pp. 30-33 (pdf 31-34) - the
  wall, bridge/ledge, grab, water, narrow-passage,
  darkness, spellcasting and mounted rules with Table 14
  and the dismount tactics. NOTE THE PLATE: printed p. 31
  (pdf 32) is a full-page combat ILLUSTRATION PLATE (djvu
  garbage glyphs, Acrobat zero words) - the chapter text
  runs pp. 30 and 32-33 with the plummet-to/the-fate cut
  spanning it; the gap-report child page labels are the
  TOC's approximations (water/narrow/darkness print on
  p. 32, mounted runs to p. 33) and flipped as-is. Pinned
  as rules/dsgfight.h (prefix dnq, verified free; 216
  inlines: 69 consts + 145 bools + Table 14's 2 cols;
  34 examples, 2 table_checks). Gap 50/105 -> 60/95:
  10 flips - the combat PARENT, 8 children, manifest
  Table 14. SEAMS verified const-for-const against
  wsgfight.h (R488) and the landed dmv/dmx/dnp DSG
  headers, NOTHING auto-credited: agreements include the
  -10 half-hp Climbing Check, water -4/floor 1,
  darkness -4 + wild swing + Dex -2/Climb -10, mounted
  +1, exact-hit-strikes-mount, Table 14 -1/-3/-5 with
  the same band edges, 45 degrees, DMG p. 53, the whole
  dismount ladder (1d3, natural-20 3-foot, 5-9-foot,
  10-foot 16-20/25%, dive 1d6); SEVEN flagged divergences
  pinned as printed - headliner the bridge Dex-per-foot
  rule runs OPPOSITE SIGN to the WSG edge rule (+2/foot
  from the drop-off vs WSG -2/foot, and a different
  trigger: DSG hit-forced, WSG miss/10%-hp-forced), the
  wall -2 covers attack+damage+saves (WSG splits cliff
  -2/slope -1), the elevation flat +2/-2, the water
  waist-threshold halved ladder (no -1 step), the
  darkness -4 attacks+saves+damage+AC set, the mounted
  rate of fire HALVES (2/1->1/1, 3/1->3/2) vs the WSG
  one-step-down-the-scale, the bridge trigger itself;
  DSG-only: the boulder rules, the grab system, water
  grappling (UA 106/108), narrow passages (DMG 69-70),
  spellcasting-in-darkness Table 9, the mount species
  rules, the rider-vs-grappler -2; WSG-only not
  credited: moonlight/natural-dark steps, the 50% wild
  swing, swoop/braced/hover, the -4 pull-down. The
  -1096 garble settles as -10% (the % -> 96 OCR class);
  the clumsy-creature rating floor 0 is the one residual
  caution, pinned as printed. Double-run applied 14/
  already 0 then 0/14; preflight GREEN, census 432, gap
  60/95. User-side spec md5 5aaefc7f vs authored
  991f2515 - cosmetic, standing class. NEXT - R508: the
  DSG Battlesystem options underground, printed
  pp. 34-35 (pdf 35-36), no printed grid; EXTRACTION
  ROUND first (the small chapter may pin in one round);
  after that the underground-environment/DM section arc.
- R508 LANDED 2026-10-17: commit f617007 (census 433,
  pushed 7403fbf..f617007), the DSG BATTLESYSTEM OPTIONS
  UNDERGROUND, printed pp. 34-35 (pdf 35-36) - the whole
  chapter in one pure-prose round PLUS the R507 chapter
  tail from the top of printed p. 34: the footman
  pull-down (-2 at 6"/round or less, -4 at 7-12", -6
  above 12", the free steed attacks on a fast miss, -1
  per additional footman up to 4, the no-damage
  multi-person cushion, the 8-man-sized/4-large surround)
  and the stake defenses (two characters one hour per
  10-foot square of 4-5 foot stakes, the horsemanship
  check to enter, 1d4-1 stakes per 10-foot depth, chain
  -1/plate -2 barding, 2d6 per stake). The tail CORRECTS
  the R507 record's "WSG-only -4 pull-down" note: the
  DSG pull-down is real but speed-band framed where the
  WSG pins the flat -4 (wfcGrappleUnmountedPenalty).
  Chapter pins: the opener, narrow frontages (1/2" and
  3/4" bottleneck figures), the 10% wounded marker (vs
  25% standard, the 1-9/10+ orc example), the column
  formation (1"=10 yards, the twice-lengthwise shape
  change to the back, the narrower-corridor doubled
  spacing), the morale no-room auto-rout and the
  blocked-routing chain reaction, ventilation (gas
  durations doubled, the p. 36 smoke cross-ref, the
  wind-carried spell gas at 1/2 area diameter lasting
  2x), the flying ceiling bands (240 normal / 60-240
  thirds / 30-60 medium+low / under-30 low only), the
  line-of-sight set (+6 Attack Rating = the composite of
  the R507 dnqDark -4 attacks and damage, -4 saves, +4 AC
  vs melee, 1/3 movement, the automatic first-rank
  obstacle hit, one light per figure with the 24-figure
  example, +2 missiles vs illuminated units, the
  skirmisher exemption) and the cave-ins (6d8 collapse
  halved on a save, area plus 1" in all directions, the
  60-dice orc example, 4d8 mud fall, 1% base + 4%
  cumulative per sub-25 survived d100, the heavy-unit
  13-to-26 doubling and the direct-hit/adjacent-collapse
  doublings). Pinned as rules/dsgbatt.h (prefix dnr,
  verified free; 145 inlines: 57 consts + 88 bools, no
  grids; 22 examples). Gap 60/95 -> 69/86: 9 flips -
  the PARENT + 8 children. Garbles settled dual-read:
  djvu 648 = 6d8 (proven by the 60-dice example and the
  4d8 mud read), 496 = +4%, 1396 = 13%. Double-run
  applied 13/already 0 then 0/13; preflight GREEN, census
  433, gap 69/86. One pre-publish R392-class fix: raw
  inch-mark quotes in two comments reworded. User-side
  spec md5 75bf127c vs authored 9e90cb2f - cosmetic,
  standing class. NEXT - R509: EXTRACTION ROUND - the
  underground environment chapter begins, printed
  pp. 36-37 (pdf 37-38): air supply duration, fire and
  smoke underground, poisonous and noxious gases; the
  big pp. 36-55 arc.
- R509 LANDED 2026-10-17: commit ee310a8 (census 434,
  pushed f617007..ee310a8), the DSG UNDERGROUND ENVIRONMENT
  OPENER, printed pp. 36-37 (pdf 37-38) - the chapter opener
  plus four boxes: air supply duration (10 cubic feet per
  human per 24h rest, 12h moderate, 6h strenuous, 2x/4x
  rates, the 3+4x5=23 example, dwarf/elf 2/3, halfling/dog
  1/2, mule/ogre 2x, the post-exhaustion Con Check ladder -
  each fail -1 ability and -1 hp vs the reduced Con,
  unconscious at 0 abilities, dead at -10 hp, automatic at
  Con 0, recovery 3/turn; AIR ONLY, never breath-holding -
  the WSG R454 seam, nothing auto-credited), fire and oxygen
  (small fire drains a 10-ft cube in 2h/12 turns, torch 8h,
  4x fire 4x rate, oil 3 rounds counted as turns), smoke
  (1-ft layer per turn per 10x10 stacking from the ceiling,
  wet/green fuel + fabric + oil, Con Check per inhaled round,
  1d6 damage, 1d6 recovery per fresh-air round, cumulative,
  the 33-28-5 orc death example), gases (poisonous saves vs
  poison; noxious Con Check per round, fail -3 abilities and
  -3 attacks, helpless at 0 abilities but NO hp loss,
  3/turn recovery; natural gas 20%/round with open flame,
  1d6, +1d6 and +1 Wis per +10% potency, no Wis Check for
  odorless gas, careful-entry check only; the small-bird
  secret save one turn early as a 0th-level human, gradual
  gas only) and the VENTILATION LADDER (well-ventilated:
  no smoke accumulation, no oxygen exhaustion, gas spells
  halved, gases 2 turns; subtle/torch-flicker: normal
  spells, gases 1h, small smoke none, large/oil at 1/2;
  connected: small smoke 1/2, large normal, breathing never
  exhausts, gases 2-5h (1d4+1); none: full smoke rate,
  gases 24h unless heavier than air; sealed: finite air,
  smoke lingers 1d6h, gases until vented, spells normal).
  Pinned as rules/dsgair.h (prefix dna, verified free;
  98 inlines: 49 consts + 49 bools, no grids; 18 examples).
  Gap 69/86 -> 73/82: 4 child flips - the Ventilation box
  EXISTS as its own child (line 107; the earlier extraction
  note doubted it) - the pp. 36-55 PARENT stays open. Dual
  read done: djvu + the pdf Acrobat-Capture layer (pure-
  Python zlib/Tj extractor, size-gated streams, idx 48 =
  pdf 37 / idx 49 = pdf 38; Capture repeats each line up to
  3x - dedup by collapsing repeated prefix word-blocks);
  garble settled: djvu "213 as much oxygen" = 2/3 (Acrobat
  "consumes 2/3 as much"). Double-run applied 8/already 0
  then 0/8; preflight GREEN, census 434, gap 73/82. User-side
  spec md5 5b534b94 vs authored 13a9b440 - cosmetic,
  standing class. NEXT - R510: odor detection + Tables 15-16
  (printed pp. 37-38, pdf 38-39; manifest lines 180-181),
  then cave-ins (Table 17).
- R510 LANDED 2026-10-17: commit 2148097 (census 435,
  pushed ee310a8..2148097), the DSG ODOR DETECTION,
  printed pp. 37-38 (pdf 38-39) - the Wisdom Check
  procedure (at first encounter, secret DM roll, non-
  repeating, rechecked only on a stronger scent or a
  harder wind, full Wis only for easily-noticed odors,
  the cross-ref as the Wis modifier, the dash = no
  detection), the dog rules (Wis 16 this check only,
  the doubled distance before the negative modifiers,
  the described growl or cringe, the trained reaction),
  the Table 15 row definitions and grid (nine sources
  over the 1-120/121-360/361-1000/1000-5000 ft bands:
  small 0/-4/-8/dash, large +2/0/-4/-8, oil +4/+2/0/-4,
  conflagration +8/+4/+2/0, odorous gas +4/+2/0/-4,
  strong-odor 0/-2/-6/-10, mild-odor -2/-6/-10/dash,
  no-odor -6/-10/dash/dash, cooking food +2/0/-2/-6)
  and the Table 16 wind effects (strong Normal/1/2/
  none, medium Double/1/2/1-10, light Double/Normal/
  1-4, in the percent encoding) plus the wind
  definitions. The disputed small-fires row settled
  THREE-WAY: chapter djvu vs the compiled-tables
  appendix reprint vs the design ladder -> 0, -4, -8,
  dash. STANDING METHOD: the appendix reprint is the
  third read for disputed cells. Pinned as
  rules/dsgodor.h (prefix dnv, verified free; 51
  inlines: 15 consts + 27 bools + the two grids; 11
  examples + 5 table checks; 7 header sections). Gap
  73/82 -> 76/79: 3 flips - the Odor detection child
  + BOTH manifest lines (Tables 15 and 16 count in the
  closed census). DELIVERY LESSON: the spec goes via a
  code canvas, NEVER a chat paste - the chat renderer
  eats m['name'](arg) brackets (first attempt: engine
  abort, user md5 2bcb78ae vs authored 8df833cf; the
  canvas copy was byte-exact). Double-run applied
  7/already 0 then 0/7; preflight GREEN, census 435,
  gap 76/79. NEXT - R511: cave-ins - the causes
  (printed p. 38, pdf 39; child line 109) + the random
  occurrences and Table 17 (pp. 38-39; child line 110,
  manifest line 182), then chain reactions (Table 18)
  + the effects (R512).
- R511 LANDED 2026-10-17: commit 9b25d57 (census 436,
  pushed 2148097..9b25d57), the DSG CAVE-INS PART I,
  printed pp. 38-39 (pdf 39-40) - the cave-in opener
(cave-ins unique to the underground environment,
  considered when excavating, using explosive magic or
  otherwise stressing the overhanging rock, the
  bridge/floor collapses, the trigger-as-attack ploy
  with its chain-reaction risk), the Causes (the
  natural-disaster causes with the spell-duplicates-
  disaster rule and the raise water example, the ripe
  areas noted on the maps, the accidental causes on
  the frailest locations - weight or sound, the
  DM-assigned percentage, the 5% ledge example, the
  run and melee doublings, the 1% sword-clash
  example, the excavation causes at double the
  accidental chance and 10% per turn with the mining
  and shoring seam, the sabotage sixths in the
  exact-integer encoding - no miner 2/2/2 and with
  miner 4/1/1 of 6) and the Random occurrences (the
  1% per day base, the 10% per 10 days long-
  expedition option, the near-the-PCs-not-on-top
  rule) with the Table 17 eight-band location grid
  (00=100, movement-relative directions, the higher-
  roll-farther-away rule, the may-go-undiscovered
  note, the decayed-stone double-or-triple). The
  djvu garbles 596/196/1096 (the % sign OCR)
  settled by the Acrobat-Capture layer; Table 17
  confirmed THREE-WAY (chapter djvu + the compiled-
  tables appendix reprint + Capture). Pinned as
  rules/dsgcavein.h (prefix dnw, verified free; 50
  inlines: 17 consts + 30 bools + 3 T17 cols). Gap
  76/79 -> 79/76: 3 flips - the Causes and Random
  occurrences children + the Table 17 manifest line.
  DELIVERY: canvas r511-splice, authored md5
  7fe5974c; user-side md5 5d10773b differed yet the
  engine ran ALL OK twice and every count landed -
  the ./bn scaffold evidently rewrote whitespace,
  cosmetic, standing class. Double-run applied
  7/already 0 then 0/7; preflight GREEN, census
  435 -> 436, gap 79/76. NEXT - R512: cave-ins
  part II - chain reactions (Table 18; child line
  111, manifest line 183) + Effects of cave-ins
  (child line 112), then the Defensive Point Values
  section.
- R512 LANDED 2026-10-17: commit 82af928 (census 437,
  pushed 9b25d57..82af928), the DSG CAVE-INS PART II,
  printed pp. 39-40 (pdf 40-41) - the chain reactions
  (even a small cave-in weakening supporting
  structures for a gravity-driven chain collapse, the
  nearby ceilings and walls checked with a per-section
  d100 vs Table 18, equal-or-less collapses the
  adjacent area at about the same size, a miss within
  10% significantly weakens it, chain collapses force
  checks in all their adjacent areas with the
  tertiary chance half rounded up and each subsequent
  roll at 1/2 the forcing roll's chance, the decayed
  exception keeping the original chance in
  eroded/ancient-ruin areas, and the 9th-level druid
  transmute rock to mud example: the 100x80x10 ft
  ceiling, the 31-vs-48 collapse above, the 42-vs-24
  hold of the second layer, the side rolls
  12/65/97/33 with exactly one side continuing (33 >
  the 32% wall chance), the secondary checks at 1/2
  and the tertiary at 1/4) and the Effects (the
  falling distance and rough landing on top, the
  bridge along its entire unsupported length, the
  tunnel ceiling never wider than the tunnel, the
  random 20x20 roughly square base area with chain
  checks per adjacent square, the 3-ft layer
  assumption with the 2-ft ceiling-and-floor example,
  the 4d8 per 10 ft or less of thickness with a save
  vs petrification for half (dice+sides consts per
  the R508 dsgbatt.h convention), the 30-ft -> 12d8
  -> save-reduced 6d8 example, mud/silt at half rock
  damage with the save halving again, and water at
  half with a save for 1/4, the first 10-ft thickness
  only, no weight damage under a pouring column, the
  drowning risk). The Table 18 grid (Ceiling 48%/32%,
  Wall 32%/12%, Ledge/bridge 5%/12%, Support Column
  80%/4%) confirmed THREE-WAY: chapter djvu + the
  compiled-tables appendix reprint (djvu.txt line
  15559, garble 4896 = 48%) + Capture idx 52; the
  djvu garbles 648 = 6d8 and 114damage = 1/4 settled
  by the Capture layer. Pinned as
  rules/dsgcavein2.h (prefix dnx, verified free;
  66 inlines: 31 consts + 32 bools + 3 T18 cols).
  Gap 79/76 -> 82/73: 3 flips - the chain reactions
  and Effects children + the Table 18 manifest line.
  DELIVERY: canvas r512-splice, authored md5
  ce79d359; user-side md5 1ef1ded5 - the ./bn
  whitespace-rewrite class again, engine ALL OK
  twice, every count landed. Double-run applied
  7/already 0 then 0/7; preflight GREEN, census
  436 -> 437, gap 82/73. NEXT - R513: the Defensive
  Point Values of underground formations section +
  the Hypothermia optional rule.
- R513 LANDED 2026-10-17: commit ca386f5 (census 438,
  pushed 82af928..ca386f5), the DSG DPV AND
  HYPOTHERMIA, printed pp. 40-42 (pdf 41-43) - the
  defensive point values section (the DMG page-110
  fortification seam, the natural and constructed
  formations assigned DPVs, the destroy-on-attack-
  or-spell use, the cubic-open-space reading where
  the value is the damage needed to collapse the
  ceiling, the chain-reaction follow-up check - the
  R512 dsgcavein2.h seam) with the Table 19
  thirteen-formation grid (room 10-ft tube 50, room
  20-ft cube 90, column 3-ft 10, column 10-ft 100,
  wall 10-ft square 20, bridge small wooden 12,
  bridge small stone 40, bridge large stone 80,
  rock ledge per 1-ft 10, ceiling small cavern
  100, ceiling large cavern 250, stalactite small
  8, stalactite large 20) and the hypothermia
  optional rule (the damp-chill preamble, the
  one-turn swimming onset assuming no subterranean
  heat source, the shallow-water reduction -
  knee-to-waist deep one hour, shallower than knee
  no threat, the Constitution Check after onset
  with 1d6 lost on a failure repeated every turn,
  the losses accumulating until an external heat
  source and continuing even out of the water,
  the 1d6-per-turn recovery by a fire or
  warm-blooded creatures until fully recovered,
  the cold-adapted and ring-of-warmth immunity,
  and the grease or oil coating doubling both the
  pre-check time and the interval). Table 19
  confirmed by chapter djvu + the appendix reprint
  (all 13 rows); Capture idx 54 partial
  corroboration (garble 104 = 10-ft, the appendix
  drop of Stalactite on the small-8 row settled by
  the chapter); hypothermia numbers dual-confirmed
  on Capture idx 56-57. Pinned as
  rules/dsgdpv.h (prefix dny, verified free; 27
  inlines: 9 consts + 16 bools + 2 T19 cols; the
  loss/recovery 1d6 dice+sides consts per the R508
  convention). Gap 82/73 -> 85/70: 3 flips - the
  DPV and Hypothermia children + the Table 19
  manifest line. DELIVERY: canvas r513-splice,
  authored md5 1cf05a69; user-side md5 199eaa39 -
  the ./bn whitespace-rewrite class, engine ALL
  OK twice. Double-run applied 7/already 0 then
  0/7; preflight GREEN, census 437 -> 438, gap
  85/70. NEXT - R514: the Magnetic Effects of
  Lodestone section + the NPC long-adventure
  reactions through Table 20.
- R514 LANDED 2026-10-17: commit ff2a1c6 (census 439,
  pushed ca386f5..ff2a1c6), the DSG LODESTONE AND NPC
  REACTIONS, printed pp. 42-43 (pdf 43-44) - the
  magnetic effects of lodestone (magnetism on iron
  armor and weapons, the innocuous iron-ore form
  that cannot impede, the deep concentrated ores of
  powerful magnetic rock, the Wis Check detection at
  120 ft as a slight tug, the obvious stage within
  90 ft (noticeable but cannot pull against the
  will), the threatened stage within 30 ft with the
  strap-snapping pull on hanging iron, the Str
  checks for hand-held iron and iron armor with the
  10-ft pull on a failed armor check, the
  no-repeat hold on a success unless closer, the
  repeats each 10 ft of approach, the -2 Str at
  20 ft and -4 at 10 ft, the -6 removal check with
  the forever-stuck failure, and the loss of all
  powers off-site) and the NPC reactions to long
  underground adventures (the special incentives,
  the Loyalty Check on being informed per DMG pp.
  36-37, the week-or-more trigger with the
  dwarf/gnome/drow exemption, -5% per planned week,
  the -10% deception modifier, the -20%-month desert
  example, separate rolls per NPC, avoidance short
  of risking life on a failure, the compelled NPC
  unsteady, the first-week ill effects with the 10%
  morale penalty and the nervous jumpiness, the
  weekly rechecks, the irrational break rolling d100
  on Table 20, the four-band reactions grid (01-20
  runs screaming to the limits of Endurance, 21-55
  attacks a nearby PC, 56-85 sneaks away quietly,
  86-00 freezes in place; 00 = 100), the effect until
  slain or surfaced, and the 1d6 above-ground weeks
  with the recovery Wis Check and the permanent
  affliction on a failure). Penalties pinned as
  positive magnitudes with the minus in the
  name/comment. The djvu garbles -209/ = -20%
  (Capture) and ih place = in place (appendix)
  settled; Table 20 confirmed THREE-WAY (chapter +
  appendix reprint + Capture idx 62). Pinned as
  rules/dsglode.h (prefix dnz, verified free; 45
  inlines: 15 consts + 27 bools + 3 T20 cols). Gap
  85/70 -> 88/67: 3 flips - the Lodestone and NPC
  reactions children + the Table 20 manifest line.
  DELIVERY: canvas r514-splice, authored md5
  bf4b84d3; user-side md5 bc98809b - the ./bn
  whitespace-rewrite class, engine ALL OK twice.
  Double-run applied 7/already 0 then 0/7;
  preflight GREEN, census 438 -> 439, gap 88/67.
  NEXT - R515: Structural decay (printed p. 43,
  child line 117 - humid-air decay, the dry 2-3%,
  1d6-year rot onset, creosote doubling, the 5%-per-
  multiple collapse chance with the 1 = 20-year max
  and 6 = 120-year examples, the stress check;
  djvu.txt lines ~5500-5525 + Capture idx 62, the
  garbles 146 = 1d6 and 4100 = d100) - then the
  underground waterways section (standing water,
  flowing water, water temperature) begins.
- R515b LANDED 2026-10-17: commit b987ddb (census stays
  439 - a TOOL ROUND, not a splice; pushed 8bd8a0d..
  b987ddb after the 8bd8a0d mishap), the regtest/preflight
  CLEANUP: (a) rules/character.cpp AbilityScores::set()
  gains default: break - the -Wswitch warning dies;
  (b) regtest.cpp R320 statusName becomes a std::strcmp -
  the -Wstring-compare warning dies AND the latent
  pointer-compare bug (the old != "Breathing" checked
  identity, not content); (c) tools/preflight.sh step 2
  gains the QUIET BATTERY DISPLAY (green 'audit: bad 0'
  lines filtered from the terminal view ONLY - tee still
  writes the full output to $batfile so the R112c census
  gate is byte-identical; a nonzero bad stays visible)
  and the WARNING GATE (build stderr captured to
  $warnfile; ANY warning ends RED - the build is
  warning-clean as of R515b, so a new warning can never
  ride unseen). Tool delivered as tools/r515_cleanup.py
  (md5 29388f058f, all-or-nothing patches, idempotent:
  applied 4/0 then 0/4; census printf shape untouched,
  439 sites). DELIVERY took three attempts: 8bd8a0d
  landed a 76-byte file (the user pasted the chat ritual
  block instead of the canvas body) - repaired via the
  r515b-cleanup canvas with the script BASE64-encoded
  (116 lines, 76 cols; nano -> paste b64 -> base64 -d >
  file -> md5sum gate) which decoded byte-exact first
  try. NANO LESSON (user-confirmed): nano APPENDS a
  trailing newline/blank line to the pasted b64 block,
  and it caused decode trouble until removed - after
  the nano save, strip the stray trailing blank line
  before base64 -d (the md5sum gate catches it either
  way). NOTE: canvas panels may render COLLAPSED - the
  user must expand the panel to see the body. Also
  deleted the stray untracked 434 and main files.
  Expect the quiet preflight from now on: smoke lines,
  BUILD: 0 warnings, AUDIT CENSUS: N audit lines, GREEN.
  NEXT - R516: back to the book rounds - Structural decay
  (printed p. 43, child line 117 - humid-air decay, the
  dry 2-3%, 1d6-year rot onset (djvu garble 146 = 1d6),
  creosote doubling, the 5%-per-multiple collapse chance
  with the roll-1 = 20-year max and roll-6 = 120-year
  examples, the stress check (garble 4100 = d100)) with
  census_before 439, the next free dn-prefix (verify in
  regtest.cpp), header rules/dsgdecay.h, include_after =
  the R514 dsglode.h include line.
- R516 LANDED 2026-10-17: commit 10723f2 (census 439 -> 440,
  pushed b987ddb..10723f2), the DSG STRUCTURAL DECAY, printed
  p. 43 (pdf 44) - the aging-of-worked-wood rules (the gap
  report's child line says worked-stone; the section is wood):
  the humid-air assumption of the typical location, the
  almost-completely-dry areas at a mere 2 or 3% of the given
  rate, the 1d6-year rot onset (djvu garble 146 = 1d6,
  settled by Capture idx 62), the creosote-or-sealant
  doubling, the 5% collapse chance per multiple of the onset
  roll with the roll-1 20-year max (100%) and roll-6 120-year
  examples, the check on unusual stress, and the d100 check
  roll (djvu garble 4100 = d100). Pinned as
  rules/dsgdecay.h (prefix dns, verified free; 14 inlines:
  8 consts + 6 bools; the 1d6 onset as dice+sides consts per
  the R508 convention; no table - gap 88/67 -> 89/66, the
  child flip only). PREV_RECORD CARRIED TWO ENTRIES: R514 +
  R515b - the tool rounds never seed-append, so the R516
  spec's prev_record spliced both records before the
  Knowledge-maintenance anchor; future post-tool-round
  splices must do the same (each tool round defers its
  record to the next book round). STANDING RITUAL RULE
  (user-set, R516): NO ./bn and NO nano step may appear in
  the ritual block - the user runs both manually by their
  own means; the ritual contains only md5sum, the double
  engine run, ./tools/preflight.sh, git add/commit/push,
  git log. Expect the user-side md5 to be the ./bn
  whitespace-rewrite class, NOT the authored md5 - treat a
  differing md5 as benign when the engine reports ALL OK;
  the authored md5 is only for authoring-side reference. DELIVERY: canvas
  r516-splice, authored md5 c6322ddd (15035 bytes); user
  ran ./bn 516 despite the ritual dropping it - user-side
  md5 9c82198a, the whitespace-rewrite class, engine ALL OK
  twice (applied 5/already 0 then 0/5); preflight GREEN
  with the R515b quiet display and 0-warning gate, AUDIT
  CENSUS: 440. Ritual now has NO ./bn line; the md5sum gate
  expects the authored md5.
  NEXT - R517: Underground waterways (pp. 43-46) - standing
  water, flowing water, water temperature, access - then the
  water-travel Tables 21-26 section.
- R517 LANDED 2026-10-17: commit 567d81f (census 440 -> 441,
  pushed 10723f2..567d81f), the DSG UNDERGROUND WATERWAYS,
  printed pp. 43-46 (pdf 44-47) - the standing water rules
  (the low ceiling blocking boat travel, no-wind sailing,
  the cave-in tsunami and confining-wall chop, the
  drinkable inflow, the bottom-cork reservoirs), the salt
  seas, the impassable/narrow/average/wide diameter ladder
  (3 / 20 / 20-60 / 60 ft, depths 3 / 4-8 / 8), the
  50/100% flow, the 0-40 rate with the x20 ft/round, the six
  flow bands (stagnant 0, placid 1-2, medium 2-6, rapids
  6-12, cascade 12-30, waterfall 30-40) with speeds,
  slopes, audibility and the drop-off dice (1d6/1d3 on 5-6,
  1d6 with 6 = none / 1d4 ft, 3d6 / 1d8 ft), the damming
  math (1000 cu ft per flow per turn, double wide / quarter
  narrow, 1d6 worker points vs flow destruction,
  50/150/250 completed CPVs per the DMG 109-110 seam, the
  half-flow leak), the temperature ladder (1d4-mile warmth,
  6d6 boiling no-save with -2/die min 1, 1d6 very hot,
  bath-warm immunity), and the access rules. The djvu
  garbles: 10096 = 100% flow, "flow rate - 2-6" = 2-6
  (Capture settled), plus a stray STRUCTGRAL DECAY heading
  interrupting the waterways opener in djvu (Capture
  clean). Pinned as rules/dsgwater.h (prefix dnt, verified
  free; 110 inlines: 70 consts + 40 bools - the biggest
  header since R509; every die as dice+sides consts per the
  R508 convention). STANDING DESIGN NOTE: the flow bands
  pin as BOUND CONSTS, NOT a chain - the printed bands
  overlap at their edges (placid 1-2 / medium 2-6 share the
  2, rapids 6-12 share the 6) and a chain would force
  non-overlap the book does not have. Gap 89/66 -> 90/65:
  the single waterways child flip, no manifest line (no
  tables in this section). DELIVERY: canvas r517-splice,
  authored md5 ca4ac09e (48472 bytes); user ran ./bn 517
  manually per the standing rule - user-side md5 ff355363,
  the rewrite class, engine ALL OK twice (applied 5/0 then
  0/5); preflight GREEN with the quiet display, BUILD:
  0 warnings, AUDIT CENSUS: 441.
  NEXT - R518: Underground water travel (pp. 46-48) -
  Tables 21-26 (boat movement rates, standstill movement,
  draught and ceilings, nonproficiency penalties, collision
  probability, boat damage) - a table-heavy round; djvu
  from line ~5963, Capture idx 63-64 hold the reprints.
- R518 LANDED 2026-10-17: commit 5c2c04d (census 441 -> 442,
  pushed 567d81f..5c2c04d), the DSG UNDERGROUND WATER
  TRAVEL, printed pp. 46-48 (pdf 47-49) - SIX TABLES in one
  round, the most since the cave-in arcs: T21 movement
  rates (small rowboat 90/120 through large barge 20/30 to
  small canoe and kayak 120/180), T22 standstill rounds
  (1/3 to the large barge 5/10), T23 draught/ceilings (the
  fractions pinned AS WHOLE UNITS - draught in inches,
  ceiling in half-feet, so 1/3 ft = 4 in and 1 1/2 ft = 3
  half-feet), T24 nonproficiency (movement -30 to -60 as
  positive magnitudes per the R514 convention, capsize
  5/10/0/0/0/20/10/25% - djvu garble 2096 = 20%), T25
  collision probability (narrow 1/5/20 vs 10/20/40,
  average, wide; keyed width x 3 + flow), T26 the eight
  damage bands (01-05 through 99-00, hull-split 45-60
  pinned AS PRINTED, overlapping 21-45 at 45 - the R517
  pin-as-printed lesson). Prose pins: the 60-ft stream /
  90-ft canoe netting 30 upstream and 150 downstream, the
  5%-per-30-ft collision damage math (90 ft = 15%, the 05
  roll = 10% hull damage), the drop-off 5%/foot damage and
  capsize, the 99/00 miraculous survival, the Proficiency
  Check capsize save, bailing canceling one small hole,
  the 1d4-round refloat, the DMG p. 54 and DSG p. 25
  boatwright seams. The djvu table columns garbled heavily
  (ftir, bargelraft, 112ft/114/113 ft, dlOO, 4100); all
  six grids RECONSTRUCTED POSITIONALLY from the Capture
  Tm coordinates - the standard dual-read fallback when
  both layers garble a column layout. Tables 21-24 share
  one boat key order (noted in the sentinel). Pinned as
  rules/dsgboat.h (prefix dnu, verified free; 71 inlines:
  29 consts + 30 bools + 12 table cols; every effect die
  as dice+sides consts per the R508 convention). Gap
  90/65 -> 97/58: 7 flips - the water-travel child + all
  six table manifest lines. STAGING LESSON: the engine
  wrote the seed before dying on a missing rules/ dir
  (mixed applied/already state, the R420 abort caught it);
  always mkdir rules/ BEFORE the first engine run on a
  fresh staging tree, and restore the seed from origin
  before re-running. DELIVERY: canvas r518-splice,
  authored md5 5e71453a (41613 bytes); user ran ./bn 518
  manually per the standing rule - user-side md5
  e1536074, the rewrite class, engine ALL OK twice
  (applied 11/0 then 0/11); preflight GREEN with the
  quiet display, BUILD: 0 warnings, AUDIT CENSUS: 442.
  NEXT - R519: Mining begins - Where to Mine (p. 48, the
  prospecting rules) + possibly Types of Mines (p. 49,
  the vein/placer taxonomy); djvu from line ~6209, Capture
  idx 65+ holds the mining chapter.
- R519 LANDED 2026-10-17: commit c4cd8f5 (census 442 -> 443,
  pushed 5c2c04d..c4cd8f5), the DSG MINING OPENER, WHERE TO
  MINE AND TYPES OF MINES, printed pp. 48-49 (pdf 49-50) - the
  mining chapter begins. The opener (the mined stones and
  metals as the most valuable of underground resources, the
  miner-proficiency framework) and the prospecting rules: the
  Wisdom-score find chance plus the miner proficiency
  modifier, the no-yield regions of deep sand/dirt and
  hardened lava with the stream-traces exception, the
  post-search Proficiency Check over at least a week and four
  miles square, the good conditions, the deep-snow
  impossibility and thin-snow double/triple, the
  rainstorm/terrain/short-daylight interferences, the
  repeat-search ladder (-1/x2 second, -2/x3 third, automatic
  failure past a point - modifiers as positive magnitudes per
  the R514 convention), the success reading Table 30 (the
  R520 seam). The types-of-mines taxonomy: the placer/tunnel
  split, strip mining excluded (heavy equipment), the
  shallow-pan placer sifting of eroded streambed wealth
  without reaching a significant lode, the tunnel mine
  trading more work for much greater wealth, the rules
  dealing primarily with tunnel mining. Numbers dual-read on
  Capture idx 66 (clean both layers; no garbles this round).
  Pinned as rules/dsgmine.h (prefix dnm, verified free; 26
  inlines: 6 consts + 20 bools; no tables). Gap 97/58 ->
  99/56: 2 flips - the two mining child lines, no manifest
  lines. DELIVERY: canvas r519-splice, authored md5 7705e796
  (18292 bytes); user ran ./bn 519 manually per the standing
  rule - user-side md5 21bbf6fe, the rewrite class, engine
  ALL OK twice (applied 6/0 then 0/6); preflight GREEN with
  the quiet display, BUILD: 0 warnings, AUDIT CENSUS: 443.
  NEXT - R520: the mining chapter continues - Excavating a
  mine tunnel (p. 49, Table 27 the DMG p. 106 rates grid +
  the per-race 10-ft-tunnel miner maxima 16/12/8/6/4) +
  mineral vein direction and path alterations (Tables 28-29,
  the 1d6x10-ft depth, the 1d4 direction, the 20-ft sections
  with the secret 1d8 alterations) + possibly shoring (p. 50,
  the two side braces + ceiling brace, 30 ft of 1-ft-diameter
  bracing, 4 man-hours per set); djvu from line ~6465,
  Capture idx 67 holds T27-T29 clean.
- R520 LANDED 2026-10-17: commit e0581a7 (census 443 -> 444,
  pushed c4cd8f5..e0581a7), THE DSG MINING EXCAVATION VEINS
  AND SHORING, printed pp. 49-50 (pdf 50-51) - the tunnel
  excavation rules: Table 27 as the 8x3 rates grid (the
  DMG p. 106 reprint - gnoll/halfling/human 75/50/25,
  gnome/kobold 80/60/30, goblin/orc 85/65/30,
  dwarf/hobgoblin 90/70/35, ogre 150/100/50, hill giant
  250/150/75, fire/frost giant 300/200/100, stone giant
  500/350/175 cubic feet per miner per eight hours) with the
  per-race 10-ft-tunnel maxima 16/12/8/6/4 ft; the mineral
  vein rules - depth 1d6 x 10 ft, Table 28 the 1d4 direction
  faces, Table 29 the secret 1d8 path alterations (the
  djvu "D6 Roll" header garble settled as d8 by the appendix
  reprint; steep descent, shallow descent, curves right
  10-60 degrees, curves left 10-60 degrees, 5-6 continues
  straight as one band, shallow ascent, steep ascent) with
  20-ft sections, the must-follow vein rule, the both-ends
  stop over the duration rules, and the gorge pickup; and
  the shoring rules - two side braces plus one ceiling
  brace per 10-ft section, 30 ft of 1-ft-diameter bracing
  in the 10x10 tunnel, four man-hours per set, the
  carpenter/stonemason/miner proficiencies, and the
  18/50-strength solo-moving threshold. Pinned as
  rules/dsgmine2.h (prefix dnf, verified free; 43 inlines -
  21 consts, 15 bools, 7 table cols; Tables 27/28/29). Spec
  26,060 bytes, authored md5 e1b54aa9 (user-side identical -
  no ./bn rewrite this round). Engine applied 10 then
  0/10. Gap 99/56 -> 105/50 (6 flips: children 122/123/124
  and manifest Tables 27/28/29). NOTE: the spec's
  gap_census was first mis-set as 102/53 (closed before
  flips) - the engine gate caught it on the first
  staging run; corrected to 105/50 (post-flip), gen_r520.py
  synced. NEXT - R521: products of a mine (p. 50, pdf 51) -
  Table 30 plus the mithril/gemstone Tables 31-32 grids;
  djvu from ~line 6588, Capture idx 67-68; gap children
  125-126, manifest Tables 30/31/32.
- R521 LANDED 2026-10-17: commit a8503d2 (census 444 -> 445,
  pushed e0581a7..a8503d2), THE DSG MINING PRODUCTS OF A MINE,
  printed p. 50 (pdf 51) - the products rules: the 1d100
  products roll on Table 30 when a miner successfully locates
  minerals (the nine bands - copper 01-30, tin 31-40, lead
  41-66, iron 67-84, silver 85-92, gold 93-97, platinum 98,
  mithril 99, gemstones 00), the mithril possibility (the
  elven-chain-mail material, a mithril mine only deep under
  the earth in the most solid of bedrock - if the locale
  qualifies the player rolls 1d10 on Table 31 Mithril Check,
  otherwise rerolls on Table 30; silver, gold and platinum at
  highest quality on 1-5/6-8/9, mithril on 10), and the
  gemstone determination on Table 32 (sixteen stone types -
  bloodstone 01-08, onyx 09-18, turquoise 19-24, agate 25-30,
  aquamarine 31-36, garnet 37-42, jade 43-48, alexandrite
  49-54, amethyst 55-60, topaz 61-66, jet 67-72, opal 73-77,
  ruby 78-82, sapphire 83-87, diamond 88-92, emerald 93-96,
  with 97-99 rolling twice and 00 rolling three times - the
  97-or-greater result grants its additional rolls
  immediately, any additional 97+ grants them again with no
  limit, a duplicated substance is noted as Jade x2 and
  yields twice the usual amount, and one quality level
  applies to all stones of a single type in a mine). THE
  BLOODSTONE LESSON: the Table 32 01-08 row is the garble of
  the round - the djvu drops the row entirely, the Capture
  layer renders a "-1/^^" fragment, and the appendix reprint
  drops it too; all three machine reads fail the row, and
  Curtiss's physical read of printed p. 50 settled it as
  01-08 BLOODSTONE - the physical book outranks the scan
  (standing rule, now exercised once). The 1d10 mithril
  check pins as dice + sides consts (the djvu "1410" and
  Capture "ldlO" garbles both read as 1d10); the 00 bands
  pin as roll 100. Pinned as rules/dsgmine3.h (prefix dnpr,
  4-char because every dn? 3-char slot is taken; 23
  inlines - 8 consts, 9 bools, 6 table cols; Tables 30/31/
  32). Spec 19,747 bytes, md5 fc81fc406623a27aa608873b0bc8a678
  (user-side identical - no ./bn rewrite). Engine applied 8
  then 0/8. Gap 105/50 -> 109/46 (4 flips: the Products child
  125 and manifest lines Tables 30/31/32). NEXT - R522:
  quality of mine products (printed pp. 50-51, pdf 51-52) -
  Table 33 Ore Quality (the d10 grid - copper 200/300/350/
  700/900/1100/1400/1600/1800/2000-4000, silver 25/50/100/
  200/300/400/500/750/1000/2000, gold 10/25/50/100/200/300/
  400/500/750/1000, platinum 5/10/20/40/75/100/250/400/800/
  1000 - the 10-then-10 pure-vein rule and the 25%-to-5%
  unsmelted ore selling) and Table 34 Gemstone Quality (the
  per-man-week counts and average values, Agate 4d10 10 x
  1d6 gp through Emerald 1d10/5 300 x 1d8 gp and Diamond
  1d10/5, with the unfinished-stones 25%-to-10% selling, the
  weekly re-roll applying to all miners that week); djvu from
  ~line 6625, Capture idx 121-122; gap children 126-127,
  manifest Tables 33/34.
- R522 LANDED 2026-10-17: commit fbdd59f (census 445 -> 446,
  pushed a8503d2..fbdd59f), THE DSG MINE PRODUCT QUALITY,
  printed pp. 50-51 (pdf 51-52) - the metals rules: the ore
  quality equals the coins producible from the metal mined
  by a single miner in a week (the ore heavily mixed with
  rock, the smelter proficiency processing it to pure
  state, the rare pure-nugget vein), the Table 33 d10
  quality grid for five metals (copper 100/200/250/300/
  350/400/500/750/1000/2000, iron 200/300/500/700/900/
  1200/1600/2000/3000/4000, silver 25/50/100/200/300/400/
  500/750/1000/2000, gold 10/25/50/100/200/300/400/500/750/
  1000, platinum 5/10/20/40/75/100/250/400/800/1000), the
  pure-vein rule (a 10 on the quality roll means roll again
  - another 10 is a pure vein needing no smelting, 1-9
  smelts normally), the unsmelted selling (no more than
  25%, possibly 5%), and the iron equivalences (1000 coins
  of iron = a full plate suit, 100 spear points, or 500
  arrowheads); and the gemstones rules: the rough
  unrecognized stones identified by miner or jeweler
  proficiency after 1d6 turns of study, the Table 34
  seventeen stone rows in stones-per-man-week and average
  value (bloodstone 2d10 at 20 + 10d6 gp, amber 1d10 at
  6d100 gp, onyx 3d10 at 10 + 10d6 gp, turquoise and agate
  4d10 at 5d6 gp, aquamarine 1d10 at 10 x 5d6 gp, garnet
  and alexandrite 1d10 at 100 x 1d4 gp, jade 2d10 at
  10 x 5d6 gp, amethyst 1d10 at 100 x 1d6 gp, topaz 2d10 at
  100 x 1d4 gp, jet 1d10 at 10 x 5d6 gp, opal 1d10/3 at
  200 x 1d6 gp, ruby 1d10/3 at 200 x 1d8 gp, sapphire
  1d10/4 at 200 x 1d8 gp, diamond 1d10/5 at 300 x 1d6 gp,
  emerald 1d10/5 at 300 x 1d8 gp, the footnote rows rolling
  1d10 divided by 3/4/5 and rounded up), the unfinished
  selling (no greater than 25%, possibly 10%), and the
  weekly value re-roll (the week's quality applying to all
  miners that week, the miner count set before the rolls).
  THE OCR-FAILURE LESSON: the garbles are text the OCR
  layers simply failed - Table 33's copper and iron rows
  were dropped by EVERY machine read (djvu, Capture, and
  the appendix reprint alike), and Table 34's machine reads
  lost the stone labels and shuffled the cells; both grids
  were settled by Curtiss reading the physical pages via
  screenshot (Android Power + Volume Down; scroll-capture
  for tall grids), with the final contested cell - onyx
  10 + 10d6 gp - settled by Curtiss's direct read after
  vision passes wobbled the operator and die count. The
  physical book outranks the scan (the R521 bloodstone
  lesson, twice exercised). NOTE: amber appears in Table
  34 but not in Table 32's gemstone list - pinned as
  printed per the R517 never-repair lesson. Pinned as
  rules/dsgmine4.h (prefix dnqt, verified free; 38 inlines
  - 14 consts, 12 bools, 12 table cols; Table 33 as a 10x5
  metal grid, Table 34 as a 17x7 numeric encoding of count
  dice/sides/divisor and value add/mult/dice/sides).
  Spec 27,196 bytes, md5 b8ad012ae7a3e32ee38c9a243173aecb
  (user-side identical - no ./bn rewrite). Engine applied 7
  then 0/7. Gap 109/46 -> 112/43 (3 flips: the Quality
  child 126 and manifest lines Tables 33/34). NEXT - R523:
  the mining tail (printed p. 53, pdf 54) - calculating the
  value of a placer mine, smelting ore, finishing stones,
  duration of a mining site, inherent hazards of mining,
  and the claim; then p. 54 the hireling loyalty opener;
  djvu from ~line 6700, Capture idx 122-123; gap children
  128-133 (the placer value, smelting, duration, hazards
  and claim children), no named tables (a prose round).
- R523 LANDED 2026-10-17: commit 0573b9b (census 446 -> 447,
  pushed fbdd59f..0573b9b), THE DSG MINING TAIL, printed
  p. 53 (pdf 54) plus the claim continuation on printed
  p. 54 (pdf 55) - the placer value (only gold, silver or
  platinum placer-minable - copper, iron, mithril and
  gemstones impossible; the normal page-51 quality
  determination then the 1d4 x 10 percentage of full value,
  10-40%), the smelting (one smelter-proficiency character
  runs the operation with unskilled workers under
  supervision; the bellows-and-unmeltable-containers
  equipment over a coal, sometimes wood, fire; the smoke
  and smell making it almost impossible to conceal; the
  underground rule that careless ventilation lets the fire
  consume all the oxygen), the finishing (gemstones rarely
  need smelting - occasional heat for crusted minerals; the
  gem cutter proficiency cutting and polishing at 2d20
  stones per character per day, excavation usually greatly
  exceeding finishing; and the weekly 1d100
  exceptional-stone check - a 00 unearths a stone worth
  1d100 times the week's average value), the duration (the
  secret d100 man-weeks roll, the doubles ladder - doubles
  add a d100 of man-months, doubles again a d100 of
  man-years, repeating until a non-doubles roll; a month
  four weeks, a year 48 weeks; 12 miners use 12 man-weeks
  per week; the placer exception disregarding doubles and
  always depleting in 1-100 man-weeks), the hazards
  (inherent, with success attracting problems almost
  automatically), and the claim (the right to remove mineral
  wealth; clear titles rare, rulers usually holding title;
  the mining charter - as little as 25 or 30%, more often
  50%, a strong ruler always 50% - enforced by spies,
  surprise inspections, discreet observation or a
  ruler-employed smelter reporting exact amounts; cheating
  punished usually by death, leniency never restoring the
  mine; and the wilderness continuation - the overnight
  land war with tribute and winner-dependent claim
  recognition, the savage denizens raiding trespassers
  with cancellable charter-like monster agreements, no
  legal protection with claims held by force, claim-jumpers
  proportional to profitability, the rarely-working
  concealment - entrance hiding with secret doors and
  brush, tailings spread or dumped in water at the 25%
  mining rate, the chipping noise carrying to Underdark
  creatures, the bulette bust-in, the smelter smoke killing
  concealment - and the wealth-disposal risk). A CLEAN-READ
  ROUND: both machine reads agree on every number; the only
  garbles the standing die-notation OCR class (djvu "14100"/
  "4100", Capture "ld4"/"dlOO" all reading as 1d100/1d4).
  CATCH-UP LESSON: the exceptional-stone paragraph sits on
  printed p. 52 with no gap child of its own (it fell
  between the R521 products child and the R522 quality
  child) - it rode this round under the Finishing child
  flip, keeping the report lossless. Pinned as
  rules/dsgmine5.h (prefix dnrv, verified free; 48 inlines
  - 16 consts, 32 bools, no tables - a pure prose round).
  Spec 31,199 bytes, md5 4f1f2cdcd01ef0ff85637b692d6603b5
  (user-side identical - no ./bn rewrite). Engine applied
  10 then 0/10. Gap 112/43 -> 118/37 (6 flips: children
  127-132). NEXT - R524: hireling loyalty (printed pp. 54-
  55, pdf 55-56) - the loyalty basics, the loyalty checks,
  the modifiers and the trigger events, with Table 36 if
  the section carries one; djvu from ~line 7050, Capture
  idx 127-129; gap child 133 plus any Table 36 manifest
  line.
- R524 LANDED 2026-10-17: commit 7c7074c (census 447 -> 448,
  pushed 0573b9b..7c7074c), THE DSG HIRELING LOYALTY AND THE
  P. 55 HAZARDS, printed pp. 54-55 (pdf 55-56) - the hireling
  loyalty: a PC group cannot usually run a mine alone (even
  with a miner-proficiency supervisor, a large mine needs
  hired strong arms; adventurers better as scouts and guards
  when the claim is questionable or monsters possible),
  loyalty insignificant in iron or copper mines but a
  precious-metal or gemstone find a great temptation, the
  standard DMG page-36 Loyalty Check with the foreman as the
  liege, the + or - 10% security modifiers (a post-shift
  search +10%, no PCs present at shift end -10%), pay
  evaluated against the mine's value (the 1,000 gp of
  diamonds for a 20 gp wage), and the failed check not an
  immediate grab-and-run - the DM weighs the NPC's
  Intelligence, only perhaps 8-or-less attempting unplanned
  theft, exceptionally high Intelligence preparing the theft
  and the getaway or concealment, the thief stealing
  1d6 x 10% of his daily output; the natural hazards:
  flooding from a tapped underground water body or digging
  below the water table (adjudicated from the DM's map, the
  below-level escape very difficult, at-level a race to the
  exit, above-level easy; the flooded mine needing draining
  or pumping), and mine cave-ins (shoring partially
  preventing but never eliminating - shored every 10 feet 2%
  weekly, no shoring 50%, partial interpolated; the
  earthquake 1d4 x 10%, heavy rain or flood 1d3 x 10%,
  burrowers like umber hulks and ankhegs 1% per hit die; the
  d100 location roll designating one end 01 and the other
  100, e.g. a 30 on a 1200-ft shaft about 360 ft from the
  entrance; the automatic 20-foot-long 10-foot-thick fallen
  ceiling; chain reactions checked normally); and the
  unnatural hazards: the unnamed evil lurking deep in the
  earth at DM creativity (the burial-ground undead, the
  concerned deep-dwelling monsters), the drow and duergar
  regarding mineral wealth as their own with intervention
  rising in direct proportion to the mine's value, and the
  planar-gate risk - some horrid lower-plane denizen finding
  a path into the world up a deep-plunging tunnel. A
  CLEAN-READ ROUND: both machine reads agree on every
  number. THE MINING BLOCK IS NOW FULLY CLOSED (all
  children flipped), and the natural/unnatural hazards were
  the last open children of the big underground-environment
  chapter (pp. 36-55) - the chapter parent line is closeable
  at the next census check. SEAMS: DMG p. 36 loyalty, R520
  shoring (the 10-ft intervals match), R511 chain
  reactions, R518 water travel. Pinned as rules/dsgmine6.h
  (prefix dnsw, verified free; 38 inlines - 18 consts, 20
  bools, no tables - a pure prose round). Spec 24,783
  bytes, md5 1f37314d48a5eb0cbb1ca2024922da41 (user-side
  identical - no ./bn rewrite). Engine applied 7 then 0/7.
  Gap 118/37 -> 121/34 (3 flips: children 133-135). NEXT -
  R525: new equipment (printed pp. 56-58, pdf 57-59) - the
  Table 35 cost/weight grid plus the descriptions,
  transportation and proficiency-equipment lists; djvu from
  ~line 7220, Capture idx 130-131. WARNING: the djvu read
  of Table 35 shows OCR-failure cells (the crowbar "Зар",
  the reed "15р 1рс", the small-basket cost dropped) - plan
  for screenshot reads of printed p. 56 before authoring;
  gap children 136-140 plus the Table 35 manifest line.
- R525 LANDED 2026-10-17: commit 9cf5b25 (census 448 -> 449,
  pushed 7c7074c..9cf5b25), THE DSG EQUIPMENT COSTS AND
  WEIGHTS, printed pp. 56-57 (pdf 57-58) - the chapter frame
  (the equipment primarily for underground exploration but
  usable in any AD&D campaign, listed with average cost and
  typical encumbrance, the specific uses tied to the
  climbing, mining and water-travel rules) and the Table 35
  cost/weight grid: twenty general rows (air bladder 15 gp
  and 20 gp, basket large 5 sp and 80 gp, basket small 2 sp
  and 40 gp, beacon 40 gp and 200 gp, birdcage 5 sp and
  50 gp, box small gold 100 gp and 20 gp, box small lead
  20 gp and 20 gp, crampons 40 gp and 50 gp, crowbar 3 gp
  and 75 gp, drill iron 5 gp and 50 gp, grappling hook
  75 gp and 75 gp, lantern waterproof 50 gp and 50 gp, lard
  pint 5 cp and 20 gp, oil waterproofing 1 gp and 20 gp,
  pickaxe 20 gp and 200 gp, powder chalk 2 sp and 20 gp,
  pulley 25 gp and 60 gp, reed hollow 1 sp and 1 pc, shovel
  10 gp and 180 gp, whistle 1 sp and 1 pc) plus four
  transportation rows (boat collapsible 500 gp and 600 gp,
  canoe small 100 gp and 800 gp, canoe large 300 gp and
  1,600 gp, kayak 250 gp and 500 gp); and the proficiency
  equipment: the fourteen initial costs and minimum spaces
  (animal trainer 100 gp and 1-20 acres, armorer 1,250 gp
  and 20 x 20, blacksmith 1,000 gp and 30 x 30, boatwright
  1,000 gp and 50 x 120, bowyer/fletcher 250 gp and 20 x
  20, carpenter 400 gp and varies, gem cutter 2,225 gp and
  15 x 15, leatherworker 300 gp and 15 x 15, miner 750 gp
  and varies, potter 600 gp and 20 x 30, smelter 2,000 gp
  and 50 x 50, stonemason 250 gp and varies, weaponsmith
  1,500 gp and 40 x 30, weaver 500 gp and 30 x 30), the
  space-required rule (undersized space = only partially
  effective), and the raw-materials exclusion (the 11-20% -
  1d10 + 10 - of finished work value, the armorer or
  blacksmith needing iron and forge fuel). THE THIRD
  OCR-FAILURE ROUND OF THE STRETCH: both machine reads
  failed the same cells with genuine conflicts between them
  (the djvu garbling every sp as the Cyrillic ар and
  dropping the basket-small cost, the Capture layer
  dropping the lard/reed/whistle cells), and the vision
  passes wobbled the currency units - settled by Curtiss
  reading the physical printed p. 56 (air bladder 15 gp -
  the direct read that broke the unsafe sp-pattern
  assumption - baskets, crowbar, pulley, reed and whistle).
  The reed/whistle weight prints 1 pc - pinned as printed
  per the never-repair rule. LESSONS: (1) the authoring
  audit mirror caught a wrong-row lard index in a table
  check before anything landed - the mirror evaluates, not
  just counts; (2) the first user-side landing hit a NEW
  failure class - ./bn delivered the spec with two stray
  bytes appended after the closing brace (23257 vs 23255,
  JSON 'Extra data'), diagnosed via wc -c + tail and fixed
  with truncate -s 23255 - the md5-vs-authored check caught
  it before the engine ran. Pinned as rules/dsgequip.h
  (prefix dnta, verified free; 17 inlines - 5 consts, 8
  bools, 4 table cols; Table 35 as a 24x2 grid normalized to
  copper-piece costs and gp coin weights, the proficiencies
  as a 14x2 grid with the -99 sentinel holding the acres and
  Varies rows). Spec 23,255 bytes, md5
  7afc57d1e1cf5d0e6345980787b306cc. Engine applied 7 then
  0/7. Gap 121/34 -> 124/31 (3 flips: children 137, 140 and
  the Table 35 manifest line 200). NEXT - R526: the new
  equipment descriptions and transportation equipment
  (printed pp. 56-57, pdf 57-58; children 138-139) - the
  item prose (air bladder, baskets, beacon, birdcage, boxes,
  crampons, drill, grappling hooks, waterproof lantern, lard,
  waterproofing oil, pickaxe, chalk powder, pulleys, reed,
  shovel, whistle) with their numbers (the beacon 240-ft
  cone, the drill noise at 120 ft, the lantern 10-ft
  underwater radius and secret d6 burn, the lard 80%
  passage, the chalk 20-ft square, the pickaxe 1d10/1d20
  damage, the whistle 1,000 ft), then the collapsible boat,
  canoes and kayak, plus the animal-trainer proficiency
  opener; djvu ~lines 7255-7420 already extracted and CLEAN
  in both reads - a fast round expected. The descriptions
  prose is extracted; verify children 138-139 exact wording.
- R526 LANDED 2026-10-17: commit 6e315f4 (census 449 -> 450,
  pushed 9cf5b25..6e315f4), THE DSG EQUIPMENT
  DESCRIPTIONS AND TRANSPORTATION, printed pp. 56-57 (pdf
  57-58) - the item prose: the air bladder (flotation at a
  1/3 kick rate with no exertion or swimming needed, a full
  turn of rest air rising at the air-supply proportions when
  exerting), the baskets (woven, lidded, not waterproof), the
  beacon (a mounted 240-ft cone, 2 ft at the source
  broadening to a 90-ft fan, a pint of oil per 10 turns,
  tightly shutterable), the birdcage (three songbirds, 18 in
  high, a foot across), the boxes (2 x 2 ft and 1 1/2 in
  deep, lightproof and airtight), the crampons, the iron
  drill (a 1-in x 9-in hole, wood at 1 in per turn and stone
  in three, the 120-ft grinding noise), the grappling hooks,
  the waterproof lantern (10-ft underwater radius vs 30, the
  flame surviving water but not the missing air - a secret
  d6 of remaining rounds), the lard (an 80% passage squeeze,
  too stubborn to burn as a weapon but 2 hp per round of
  fire damage for 1d6 rounds, and a hypothermia
  insulator), the waterproofing oil (2 sq yd per pint of
  leather or wool never cotton, 1d6 x 6 turns of pouring
  water, 1d6 immersion, then wetter for 1d6 turns until
  saturated), the pickaxe (the miner's essential, the rate
  halved without it, a desperate weapon at -2 dealing 1d10
  small/medium and 1d20 large), the chalk powder (a 400-sq-ft
  or 8-character covering, the 10-ft dust cloud revealing
  invisibles), the pulleys (1/2/3 rope loops, two single
  doubling, two double quadrupling, two triple sextupling
  the lift), the hollow reed (the periscope breath, 1/3
  movement with a 10% per-round ripple, none floating), the
  shovel (the daily excavation halved without it) and the
  whistle (1,000 ft); and the transportation: the
  collapsible boat (a backpack-sized package unfolding into
  a small-rowboat equivalent in 1d3 turns, twice the listed
  weight when wet), the canoe (swifter, more maneuverable,
  easier to capsize - 3 normal or 2 heavy, the large 9 or
  6), and the kayak (the one-character craft, the oilskin
  layer keeping it dry even capsized). A CLEAN-READ ROUND:
  both machine reads agree on every number; no screenshots
  needed. WITH THIS ROUND THE NEW-EQUIPMENT PARENT (136) AND
  THE WHOLE pp. 36-55 UNDERGROUND-ENVIRONMENT CHAPTER ARE
  CLOSED. SEAMS: air supply p. 36, hypothermia p. 42, the
  movement p. 21 passage width, R520 pickaxe/shovel rates,
  the climbing crampons/hooks. Pinned as
  rules/dsgequip2.h (prefix dnet, verified free; 80 inlines
  - 54 consts, 26 bools, no tables). Spec 37,748 bytes, md5
  fdf6297d5d25e2f005d0ff5d91abeac1 (user-side identical).
  Engine applied 6 then 0/6. Gap 124/31 -> 126/29 (2 flips:
  children 138-139; the New equipment parent closes at the
  next census check). NEXT - R527: the proficiency
  descriptions (printed p. 58, pdf 59) - the fourteen
  prose paragraphs (animal trainer through weaver, the
  armorer's forge and ventilation, the boatwright's
  plus-10-ft space rule, the miner's pan-vs-tunnel
  equipment, the smelter's furnace/bellows/buckets, the
  weaver's spinning wheel and loom); djvu ~lines 7470-7575
  already extracted and CLEAN in both reads; no gap child
  of its own (the descriptions ride the Equipment for
  proficiencies child 140, already flipped at R525) - so
  R527 either pins the prose as a lossless catch-up round
  or skips to Improving Play; check the gap report for any
  p. 58 line before deciding.
- R527 LANDED 2026-10-17: commit 298d3e1 (census 450 -> 451,
  pushed 6e315f4..298d3e1), THE DSG PROFICIENCY
  DESCRIPTIONS, printed p. 58 (pdf 59) - the fourteen brief
  introductions: the animal trainer (little beyond
  harnesses and leashes, but a great deal of outdoor room,
  with shelter and food if boarding), the armorer (a small
  forge, several hammers, at least one small anvil and
  metal files, with good ventilation and exhaust for the
  especially hot fire the armor irons demand), the
  blacksmith (the armorer's equipment in greater
  assortment and size, but cruder iron needing
  lower-quality tools), the boatwright (a major investment
  at a carefully chosen launchable location - excepting
  kayaks, canoes and small rowboats - with the space the
  boat size plus 10 feet in all directions, the tools all
  carpentry plus pitch or tar), the bowyer/fletcher
  (little beyond knives and vises), the carpenter
  (hammers, spikes, axes, and chisels), the gem cutter
  (finely tooled chisels, hammers and vises, good light,
  sturdy safes or strongboxes), the leatherworker
  (punches, needles, knives, scissors, and treating oils),
  the miner (a shallow pan and container for stream
  panning, but picks, shovels, shoring timbers, hammers,
  spikes and mining carts for a tunnel, the need growing
  with the tunnel), the potter (the kiln limiting the wares),
  the smelter (the efficient high-temperature furnace, the
  individually operated bellows, and the iron-buckets-on-
  rails or cauldron/stone-trough feeding system), the
  stonemason (going where the work is, with a sturdy wagon
  and oxen), the weaponsmith (a small blacksmith's shop
  plus the fine finishing tools for edges and
  ornamentation), and the weaver (a very small area, the
  spinning wheel and loom). A CLEAN-READ ROUND. A LOSSLESS
  CATCH-UP ROUND (the R523 precedent, second application):
  no gap child of its own - the descriptions ride the
  already-flipped Equipment-for-proficiencies child 140,
  zero gap flips, the census unchanged at 126/29, and the
  git add drops dsg_gap_report.md (untouched). Pinned as
  rules/dsgequip3.h (prefix dnep, verified free; 16
  inlines - 1 const, 15 bools, no tables). Spec 16,269
  bytes, md5 d68d54037abe6e14a75dd0aa90edc32e (user-side
  identical). Engine applied 4 then 0/4. NEXT - R528: the
  Improving Play chapter (printed pp. 59-63, pdf 60-64,
  gap children ~141-149): the frame (the three categories -
  expedition planning, speeding play, effective fighting),
  then expedition planning proper (the before-leaving
  success/failure determination, the beasts of burden, the
  watercraft); djvu from ~line 7575 ("IMPROVING PLAY" seen
  there), Capture idx 137-141; check the gap report
  children list at authoring time. Mostly prose with
  possible small tables - check for any Table 36+.
- R528 LANDED 2026-10-17: commit 5b48f3d (census 451 -> 452,
  pushed 298d3e1..5b48f3d), THE DSG IMPROVING-PLAY OPENER:
  EXPEDITION PLANNING, BEASTS OF BURDEN, WATERCRAFT,
  printed pp. 59-60 (pdf 60-61) - the frame (the
  three categories: expedition planning, speeding play,
  effective fighting) and the expedition planning: the
  success or failure often determined before leaving base
  - more often the failure - so learn everything first
  (NPC interviews, the approaches, magic for insight, even
  rumors with a basis in fact - basilisk slithering means
  mirrors); scout with light avoid-combat parties (one or
  two thieves, invisibility, gaseous form) and keep
  scouting during the adventure (the listening-at-doors
  function, one character looking ahead, less ambush and
  more tactical options); the preparation: objectives,
  duration and areas, cliffs, water, light, extended food
  with extra carried, the return; foot travel on rough
  going, waterways the easy fast access but notoriously
  dangerous (the placid stream turning cascade or
  vanishing crack), beasts of burden where smooth; the
  mules: 2,000 gp saddlebag weight unencumbered, 6,000 gp
  max at 1/2 speed refusing over 8 hours a day, the 50%
  six-foot-or-less chasm (never wider, never loaded over
  2,000, no mind-changing), average-steepness stairs with
  human footing (hands-required slopes too steep), the 50%
  very-steep slope, the 90% willing swim with the six-foot
  jump (refusing over 2,000 gp), the 3-inch-per-round swim,
  the string following its leader (a refused leader
  unhitched, never changing its mind), the strange-odor
  jitters at 25% bolt/bray/freeze/normal (one group
  check), and the 360-ft stone noise muffled to 90 ft
  with daily-replaced boots; the dogs: the 100-lb war-dog
  varieties (shepherds, malamutes, wolfhounds),
  animal-trainer training required, 200 gp without
  penalty, 500 gp max at half speed and -4, no swimming or
  steep climbing over 200 gp, the 50%
  attack-strangers tendency (restrained dogs barking),
  the advanced-training discipline (hand signals needing
  sight), and the -2-not--4 darkness penalties; and the
  watercraft: the kayak nimblest and roughest-capable but
  needing small-boat proficiency from ALL characters,
  larger craft cargo-and-togetherness vs rough/narrow
  limits, the collapsible boat flexible but bulky and
  less sturdy, waterborne scouting the more vital (the
  waterway ascertained ahead, the one-way current needing
  a return plan). A CLEAN-READ ROUND: both machine reads
  agree on every number (djvu "5096" = 50%, corroborated
  by Capture). SEAMS: Monster Manual mule/war dog,
  R506/R527 animal trainer, R518 small-boat proficiency,
  R526 collapsible boat. THE CHAPTER SPLIT per the
  content-density rule: children 142-144 this round, R529
  takes 145-150 (fighting effectively, diversions,
  speeding play, creative spell use, languages, mapping).
  Pinned as rules/dsgplay.h (prefix dnip, verified free;
  43 inlines - 19 consts, 24 bools, no tables). Spec
  26,644 bytes, md5 06727a4b26c3fa0bb2391f12336267b5
  (user-side identical). Engine applied 7 then 0/7. Gap
  126/29 -> 129/26 (3 flips: children 142-144). NEXT -
  R529: the improving-play tail (printed pp. 60-63, pdf
  61-64; children 145-150): fighting effectively (the
  long-together effectiveness, the low-AC-between rule,
  the rear-guard retreat plans, the mini-teams, surprise
  with the ranger infravision note), creating diversions
  (the 1d4-round low-Int distraction, the medium/high-Int
  save vs spell, genius needing clever, PCs never
  saving), speeding play (the door-opening drills, the
  standard marching orders, the caller rotation), creative
  spell use (the silence coin, darkness vs infravision,
  the telekinesis slime pots, the shatter pots, the
  charm questioning, the toppling walls, the ricochet
  bolt), the languages of the underdark (the tapping
  language, 10x slower, drum amplification, the
  underground-native PCs knowing it), and the mapping
  techniques (the 10-ft graphing, the 10-20-ft error
  agonizing, the line-drawing alternative); djvu ~lines
  7848-8160 already extracted and CLEAN in both reads.
- R529 LANDED 2026-10-17: commit 39ce9b7 (census 452 -> 453,
  pushed 5b48f3d..39ce9b7), THE DSG IMPROVING-PLAY TAIL:
  FIGHTING EFFECTIVELY, DIVERSIONS, SPEEDING PLAY,
  SPELL USE, LANGUAGES, MAPPING, printed pp. 60-63
  (pdf 61-64) - the second half of the improving-play
  chapter (children 145-150), closing parent 141:
  the fighting effectively: the long-together
  effectiveness, the low-AC-between rule (the weakest
  front-line member positioned between the strong),
  the rear-guard retreat plans, the mini-teams, and
  the surprise with the ranger infravision note; the
  creating diversions: the 1d4-round low-Int
  distraction, the medium/high-Int save vs spell,
  the genius needing clever, the PCs never saving;
  the speeding play: the door-opening drills, the
  standard marching orders, the caller rotation; the
  creative spell use: the silence coin, the darkness
  vs infravision, the telekinesis slime pots, the
  shatter pots, the charm questioning, the toppling
  walls, the ricochet bolt; the languages of the
  underdark: the tapping language, the 10x slower,
  the drum amplification, the underground-native PCs
  knowing it; and the mapping techniques: the 10-ft
  graphing, the 10-20-ft error agonizing, the
  line-drawing alternative. A CLEAN-READ ROUND: both
  machine reads agree on every number. SEAMS: R528
  the improving-play opener (parent 141 now closed),
  Monster Manual ranger infravision, R80 spell
  silences/darkness/telekinesis/shatter/charm. Pinned
  as rules/dsgplay2.h (prefix dnpm, verified free;
  41 inlines - 7 consts, 34 bools, no tables). Spec
  32,472 bytes, md5 c02b4014ca43344f088fcfcac54114a9
  (user-side identical). Engine applied 10 then
  0/10, audit mirror clean. Gap 129/26 -> 135/20
  (6 flips: children 145-150). PREFLIGHT GREEN with
  census 453 audit lines, each exactly once, all bad
  0; BUILD: 0 warnings. NEXT - R530: the DM's section
  begins (printed pp. 64-120, re-grained at R503 - the
  gap report's DM's-section children list); the
  chapter parent 141 (Improving play) closes at the
  next census check once R529's children flip.
- R530 LANDED 2026-10-17: commit 716bde0 (census 453 -> 454,
  pushed 39ce9b7..716bde0), THE DSG UNDERGROUND
  ENVIRONMENT, the DM-section opener: printed pp. 65-68
  (pdf 66-69), the first DM-section child - the
  why-an-ecosystem justifications (defense: the dungeon
  safer than a castle - impervious to aerial attack, the
  earthquake target hard to identify at depth, held by a
  smaller group since access is limited, no wall garrison
  so a reserve against break-ins, the burrowers menacing
  but rarely marshalled; the drow and duergar survival
  through defensibility; mining: the dwarven and gnomish
  economies, the mines converted to fortresses, prisons
  and lairs, the burrowing-monster passageways, the
  connected limestone caverns many over 100 miles long;
  gravity: the centuries of creatures falling into holes
  and adapting to the dark world), the features of the
  underground game (the DM control over narrow options,
  the essential encounter in a central room, the
  plannable monster tactics with the rigged alarms and
  ambushes undoable by creative play, the beginners
  decision ease with the doorway and 10-foot-corridor
  defense, the danger atmosphere, the common fears, the
  alienness and wonder, the frontier below the feet with
  its exploration, scouting, plunder and conquest
  missions, and the back-to-basics variety), the nature
  of the underground environment and its denizens (the
  precarious balance of power upset by PC arrival, the
  land more precious than on the surface, the evil
  tendency with the drow and kuo-toa war banishment, the
  lower-planes theory and the oldest mind flayers and
  derro, the humorless philosophy with the functional
  art and the punished waste, the timelessness and the
  old-age-before-execution tale, the stubborn
  conservatism, the depth-shaped resources with the
  mile-floated wood and the raided food and slaves, the
  depth-shaped alienness, the sunless food chain with
  its fungi, rothe and cave pigs, the inedible
  stone-eaters, the minor scavengers, the nocturnal
  raiders, and the natural oxygen circulation through
  arctic shafts and geothermal heat), and a brief
  history of underground cultures (the five ancient
  cultures - the jermalaine tunnels, the myconid
  coexistence, the aboleth Darksea cities, the evicting
  cloakers, the mind flayer dominion checked only by
  low reproduction; the Alignment Wars with
  alignment-chosen sides and the seaborne kuo-toa; the
  evil halted at the sunlit tunnel mouths; the defeat,
  the retreat of drow and duergar and kuo-toa and the
  faded alliance; the immigrant niches; the interplanar
  doors with the Plane of Earth strongest; the
  gem-lusting svirfneblin, the stone-working pech and
  the interbred derro; and the savage wars of today
  with the isolated pockets between monster stretches).
  A CLEAN-READ ROUND: both machine reads agree on every
  number (djvu ~lines 8226-8860, Capture idx 149-162).
  SEAMS: Monster Manual burrowers and underground
  cultures, DMG inner planes, the R503 re-grain. Pinned
  as rules/dsgenv.h (prefix dnug, verified free; 51
  inlines - 4 consts, 47 bools, no tables). Spec 31,639
  bytes, md5 cfcb3916edb3d7ca26cea790296e1c73
  (user-side identical). Engine applied 5 then 0/5,
  audit mirror clean. Gap 135/20 -> 136/19 (1 flip).
  PREFLIGHT GREEN with census 454 audit lines, each
  exactly once, all bad 0; BUILD: 0 warnings. NEXT -
  R531: underground geography - domains in three
  dimensions (printed p. 69+, the surface terrain,
  temperature, humidity, size, origin, access and
  egress child), then the theories on the nature of
  the underground (pp. 70-71).
- R531 LANDED 2026-10-17: commit f52a044 (census 454 -> 455,
  pushed 716bde0..f52a044), THE DSG UNDERGROUND GEOGRAPHY
  AND THEORIES, printed pp. 69-71 (pdf 70-72), two
  children - the underground geography: domains in three
  dimensions (the total accessible area equaling the
  ground area of a large nation, the campaign-by-campaign
  world building, the 1,000-mile sample region; the
  surface terrain - the water-filled sea tunnels with
  their permanent-magic rationale, the stale dead-end
  air pockets, the water table, the higher-altitude
  mountain domains with explorers resurfacing at the
  mountain base, and the granite-versus-limestone
  seabeds; the temperature - the geothermal plant
  growth, the drow and duergar warm lairs making
  intelligent encounters likelier near heat, and the slow
  convection exploited by ventilation tunnels; the
  humidity - the brittle dried formations, the steamy
  scavenger-prized slippery rock, the dusty low-humidity
  areas, and the ever-changing erosion with its cave-ins
  and rock slides; the size - the creature-size limits
  of the three-foot halfling tunnels, the avoided
  unsupported caverns stretching a mile wide, the
  drow-duergar-derro support columns and permanenced
  spells, and the jermalaine-pech small-tunnel defense;
  the origin - the irregular natural caverns, the
  duergar-svirfneblin domed cities with their straight
  miles-long tunnels and ornate stonework, the drow-kuo-
  toa preference for conquering duergar lairs, and the
  mind flayer-myconid natural caverns; and the access
  and egress - the fresh air near surface connections,
  the no-access air shafts of the arctic example, and
  the easy-access raiders orcs, goblins and kobolds
  versus the deep cultures shunning the outside world),
  and the theories on the nature of the underground
  (the DM-decides frame and the sage-knowledge role
  playing; the hollow earth theory with its variants -
  the inner world of flyers and levitators cloaked in
  darkness with volcanic light, the lava-rain fire
  world, the far-fetched inner shell, and the Plane of
  Air connection; the Swiss cheese theory with the
  goblin-hobgoblin-orc ubiquity argument, the failed
  expeditions, and the unexploited connections; the
  isolated pockets theory with its forced-migration
  goblin-slave explanation; and the partial connection
  theory with its fire and water blocks and the
  later-sealed traversable pasts). A CLEAN-READ ROUND:
  both machine reads agree on every number (djvu ~lines
  8902-9268, Capture idx 163-168). SEAMS: R530
  environment, R521-R524 mining, Monster Manual
  cultures, DMG inner planes, the R503 re-grain. Pinned
  as rules/dsggeo.h (prefix dngr, verified free; 42
  inlines - 3 consts, 39 bools, no tables). Spec 29,092
  bytes, md5 ebc40e269c3b9a8778f5e102cf4093b1 (user-side
  identical). Engine applied 6 then 0/6, audit mirror
  clean. Gap 136/19 -> 138/17 (2 flips). PREFLIGHT GREEN
  with census 455 audit lines, each exactly once, all
  bad 0; BUILD: 0 warnings. NEXT - R532: the cultures
  of the underdark (printed pp. 73-74): the values and
  objectives frame plus the eight race write-ups (drow,
  kuo-toa, duergar, mind flayers, aboleth, derro,
  cloakers).
- R532 LANDED 2026-10-17: commit 3c3fc98 (census 455 -> 456,
  pushed f52a044..3c3fc98), THE DSG CULTURES OF THE
  UNDERDARK, printed pp. 73-74 (pdf 74-75), the third
  DM-section child - the values and objectives frame (the
  races relying less on trade and interaction than the
  surface races, the environment forcibly segregating
  them; trade governed more often by proximity than by
  alignment - an evil race more likely to trade with a
  nearby neutral race than a distant evil one; and the
  monster-encyclopedia referral), and the eight race
  write-ups: the drow (the strongly matriarchal society
  with females holding all power in government, military
  and home; the Lolth worship with the 6th-level-and-
  higher testing and the drider failures; the spider-like
  scorpions, pedipalp and solifugud; the web-pattern
  buildings with the traps channeling prey to the
  center; the aged-only cannibalism under population
  pressure; the treaty-breaking making alliances
  reluctant; and the long-term objective of ruling all
  subterranean races and controlling underworld access),
  the kuo-toa (the race past its prime struggling to
  retain its holdings, its inability to cooperate making
  it susceptible to conquest; the Sea Mother worship as
  the one unifying element with the holy-war dream; the
  5% insanity breeding the monitor class; and the
  slave-acquiring brute force, treachery or barter), the
  duergar (the disciplined and orderly evil allowing
  dominance; the mountain-and-hill-dwarf kinship in
  mining and metal-and-stone work; the fiendish
  imprisoning traps with slow painful deaths; the slave
  labor with complete disregard for welfare; the
  mercilessness and torture love; the extermination over
  driving off to eliminate reprisal; and the
  sculpture-and-metalworking craft trade for slaves and
  devices), the mind flayers (the aboleth the only
  non-hostile race with the sinister-connection legends;
  the brain hunger leaving bodies to the scavengers; the
  racial quest to douse the fires of the sun itself; the
  probability-travel escape from difficult odds; the
  rigidly psionic-ranked society with slave labor and
  slave food; the life-form experiments with their
  hostile hybrids; and the immunity-bought-with-slaves
  trade and the temporary aboleth pacts), the aboleth
  (the most alien culture from the human point of view,
  coldly ruthless with torture serving no rational
  purpose; the intended complete control of the
  underworld beginning with the underground waters - the
  main reason for the kuo-toan waning; the obscene mind
  flayer pacts with the illithid as a temporary tool; the
  godless reverence of the greater aboleth, one to six
  per city at four times the size and Hit Dice, the
  repositories of the alien knowledge; and the remote
  casually-guarded slave cities), the derro (the small
  savage bands never in large communities, raiding near
  the surface; the chaos and intraracial violence; the
  stealing over working and the short-lived duergar and
  drow pacts; and the 20-year savant war cycle ending in
  utter defeat but recovered by the high reproductive
  rate), and the cloakers (the true children of the
  earth with the Elemental Plane of Earth ties; the most
  intelligent of their type over the lurkers, miners,
  trappers and mantari servants; the violence answering
  all contact attempts; the toolless structureless
  culture with its instinctive community sense; and the
  guerrilla warfare and kin-sacrificing defense). A
  CLEAN-READ ROUND: both machine reads agree on every
  number (djvu ~lines 9268-9460, Capture idx 172-174;
  the FF/MM/MMII reference-title garbles settled by
  chapter context). SEAMS: Fiend Folio drow and kuo-toa,
  Monster Manual II duergar, aboleth, derro and cloakers,
  Monster Manual mind flayer, R530-R531 environment and
  geography, the R503 re-grain. Pinned as rules/dsgcult.h
  (prefix dncu, verified free; 42 inlines - 5 consts, 37
  bools, no tables). Spec 29,999 bytes, md5
  35e679031b2e4ff3d16bf4ce8e742d00 (user-side identical).
  Engine applied 5 then 0/5, audit mirror clean. Gap
  138/17 -> 139/16 (1 flip). PREFLIGHT GREEN with census
  456 audit lines, each exactly once, all bad 0; BUILD:
  0 warnings. NEXT - R533: the lands of Deepearth open
  (printed pp. 75+): the frame (the use-it-or-adapt-it
  setting, the moderately-small-nation area, the
  three-dimensional and geomorphic mapping referrals to
  p. 114, the hollow-earth note), the connecting
  passages (the human-sized passability, the water
  passages with the 1d6x10-ft width generation, the
  width-drift rolls, the 1d6 temperature bands with the
  boiling-hot danger, the tunnels with the 10% carved
  chance and the uniform 10-ft diameter) - the first
  procedurally-numbered DM-section round.
- R533 LANDED 2026-10-17: commit a1fb6a6 (census 456 -> 457,
  pushed 3c3fc98..a1fb6a6), THE DSG LANDS OF DEEPEARTH
  OPENER, printed p. 75 (pdf 76) - the setting frame and
  the connecting-passage generation: the frame (the lands
  presented in detail as a campaign setting, the party
  gaining many levels without exploring the entirety; the
  alternative example-of-the-ecosystem view, use-and-
  discard, expandable, the realms occupying no more area
  than a moderately small nation; the numbered-area rough
  detail; the page-114 three-dimensional and geomorphic
  mapping referrals; the hollow-earth-below note with the
  shafts from the lowest level; all passages passable to
  human-sized characters), the water passages (the rivers
  with their map-readable flow directions, the indicated
  waterfalls with map-scale drops, the rest navigable by
  boat with a skilled pilot and a little luck; the 1d6-x-10
  width generation for the 10-60-ft spread, the width
  constant for one mile, the drift reroll - 2-5 the same,
  1 shrinking 10 ft or 5 at the 10-ft floor, 6 growing
  10 ft even beyond 60; the 1d6 temperature - 1-5 very
  cold, the 6 heat check with the second d6 - 1
  cool-slightly-warmer, 6 boiling hot, 2-5 proportional;
  only the boiling water unsafe for unprotected
  characters), the tunnels (the human-passable diameters,
  mostly natural caverns, the 10%-per-10-miles carved
  chance, the carved uniform 10-ft diameter and height with
  no sudden obstacles; the 33%-per-mile obstacle chance
  with the 10d10 cliffs, the 20d10-deep 4d10-wide chasms,
  the cave-in remnants and the water-quicksand-oil-tar
  pools, never closing the passage; the 3d20 cavern
  widths from 3 to 60 ft, constant for 1d20-x-100 ft of
  100-2,000, the 1/3 change chance with the 3d20 reroll;
  the unintelligent dwellers - scavengers, fungi, molds
  and lichens - the intelligent denizens only passing
  through, the banished renegade bands the exception), and
  the area details (the framework-not-full-detail rule,
  the 300-ft square as 30-by-30 graph squares, and the
  DMG page-169 Random Dungeon Generation referral). A
  CLEAN-READ ROUND with one settled garble: the djvu
  cavern-width formula reads "(3420)", the Capture layer
  reads "(3d20)" - settled as 3d20 by the Capture read,
  corroborated by the 3-60-ft range (djvu ~lines
  9584-9712, Capture idx 176; the map pages pp. 76-77 are
  graphics and pin nothing). SEAMS: DMG Random Dungeon
  Generation p. 169, R518 water travel, R531 geography,
  the R503 re-grain. A ZERO-FLIP ROUND: the pp. 75-98
  Deepearth child remains open (the R527 precedent - the
  gap report NOT in the git add). Pinned as rules/
  dsgland.h (prefix dndl, verified free; 52 inlines -
  36 consts, 16 bools, no tables). Spec 25,945 bytes,
  md5 caba0e8133c6ae2b65017fdcbc88151c (user-side
  identical). Engine applied 4 then 0/4, audit mirror
  clean. Gap unchanged 139/16. PREFLIGHT GREEN with
  census 457 audit lines, each exactly once, all bad 0;
  BUILD: 0 warnings. NEXT - R534: the Deepearth area key
  begins (printed pp. 78+): the 31 numbered areas, two or
  three per round per the content-density rule, starting
  with areas 1-3 (the Great Lake, the city dungeon, the
  fungus forest per the R503 re-grain list).
- R534 LANDED 2026-10-17: commit 24139af (census 457 -> 458,
  pushed a1fb6a6..24139af), THE DSG DEEPEARTH AREAS 1-3,
  printed pp. 78-79 (pdf 79-80) - the individual area key
  opens: Area 1 The Great Lake (the fresh cold water; the
  rocky northern shore with the 1,200-ft maximum depth;
  the sandy shores with their 400-ft average; the southern
  limestone cliff rising 400 ft and never below 100, the
  50-ft depth sloping to 400 toward the center; the
  50-by-120-mile oval on bedrock under silt; the trout,
  salmon, carnivores and boat-swallowing giant gars; the
  lonely sirines and the central scrags; the fish and
  mill-wheel resources; the 20-ft half-water cave to Area
  5, the water-filled mine shafts, and the
  wall-of-force-with-permanence spur), Area 2 Surface
  Lands (the temperate terrain sloping south to north;
  the fortified river-bank trading city; the centaurs,
  halflings, and the rumored enchanted woods; the hill
  dwarves and hill giants at odds; the smoldering
  volcanoes rumored prowled by dragons; the farm-lumber-
  fish resources with the dwarf gold, silver, copper,
  bloodstone and ruby sales; the city dungeon linking
  sewers to the palace dungeon and Area 9, the
  thieves-guild connections, the four-level bandit
  dungeon with its secret passage to Area 4, the
  half-connecting hill caves to Area 3, and the taboo
  abandoned mine shaft), and Area 3 Upper Caverns (the
  central living-cave limestone maze, the 6-to-8-ft
  pools, the 300-ft-square excavation cap, the
  20x10x100-ft largest chamber with its 3x2-ft pinches,
  the wall-of-force watery wall; the raiding races -
  troglodytes, goblins, hobgoblins, ogres, trolls and
  lycanthropes; the scavengers, the gibbering mouther,
  greater basilisk, shambling mound and the wandering
  beholder; the air-water-plants resources; the 80-ft
  troglodyte amphitheater with the fungus-covered
  war-hero statue and its 10,000-gp eye-diamonds; and
  the 3x1-ft magic pool - the pint-per-year drip, the
  60-ft infravision, the 2d6-week durations, the 30
  pints keeping indefinitely). A CLEAN-READ ROUND: both
  machine reads agree on every number (djvu ~lines
  9840-9960, Capture idx 182-184; the "INDIVIDGAL" and
  "GPPER" djvu header garbles non-load-bearing). SEAMS:
  R518 water travel, Monster Manual denizens, PHB wall
  of force and permanence, R521-R522 mining, the R503
  re-grain. A ZERO-FLIP ROUND: the pp. 75-98 Deepearth
  child remains open (the R527/R533 precedent - the gap
  report NOT in the git add). Pinned as rules/dsgarea1.h
  (prefix dnar, verified free; 44 inlines - 26 consts,
  18 bools, no tables). Spec 26,829 bytes, md5
  39a292cc94236a717a1acb8cef31b173 (user-side identical).
  Engine applied 4 then 0/4, audit mirror clean. Gap
  unchanged 139/16. PREFLIGHT GREEN with census 458
  audit lines, each exactly once, all bad 0; BUILD: 0
  warnings. NEXT - R535: the Deepearth areas 4-5
  (printed pp. 79-80, pdf 80-81): Area 4 the Cathedral
  Caverns (the 1d6-mile caverns with 100-ft ceilings,
  the ornate stalactite appearance), then onward through
  the area key per the R503 re-grain list.
- R535 LANDED 2026-10-17: commit d08481f (census 458 -> 459,
  pushed 24139af..d08481f), THE DSG DEEPEARTH AREAS 4-5,
  printed pp. 79-81 (pdf 80-82) - the individual area key
  continues: Area 4 the Cathedral Caverns (the four 1d6-mile
  limestone caverns with 100-ft ceilings and 80/90-ft widths;
  the stalactite-stalagmite-drapery cathedral appearance; the
  west surface tunnel and the excavated link to the city
  dungeon behind its secret door; the 400-ft bandit sinkhole
  with the cave-in rubble; the 5-ft-wide 1-ft-deep streams;
  the isolated drow pocket - 25 fighters, equal
  noncombatants, poor and magicless; the piercer ceiling
  with the drow rim trail; the jellies, oozes, wererats and
  otyugh scavengers; the 12-HD sinkhole hydra starving in
  the central cavern; the diamond vein settled by jewelry
  proficiency; the 500-ft approach tunnel under 10 ft wide
  with pit traps, 6d6 falling blocks, shriekers, the
  illusionary dead end and the 100-ft oil-pot climb; and the
  geothermal gold mud pool - 20 ft wide, 5 ft deep, 20 gp
  per character, more than 10,000 gp), and Area 5 the
  Enclosed Caverns (the air-filled, water-choked caves fed
  by the subterranean river; the 3-to-4 meander and the
  sandy beach; the one-mile rapids and the 80% cascade
  sweep, two rounds to the quiet pool; eight sub-mile caves
  behind 2-ft tunnels; the 50-ft water-filled chute and the
  six low-clearance miles to the Area 14 waterfall; the 20
  mad castaways with their green-glow fungi light; the 6d6
  kuo-toa outpost guarding the chute with monthly sweeps;
  the fish-rat-beaver-weasel-rabbit fauna and the scrag;
  the nereid of the deep spring pool; the 1%-per-hour river
  finds - plate mail +2, shield +2, shield +3, longsword +1,
  spear +3; the surface net stopping short of the bottom;
  and the outpost's three vertical levels, secret doors and
  food-storage chamber). A CLEAN-READ ROUND: both machine
  reads agree on every number (djvu ~lines 10084-10295,
  Capture idx 368-372). DELIVERY NOTE: the user-side md5
  c3b23233763d24f02f83aebf9465426a = the staging md5 plus
  one trailing newline added by the copy path -
  byte-stripped they are identical; benign and
  engine-validated; from R536 the gen script emits the
  trailing newline so the md5s match as-delivered. A
  ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains
  open (the R527/R533/R534 precedent - the gap report NOT
  in the git add). Pinned as rules/dsgarea2.h (prefix dnac,
  verified free; 58 inlines - 33 consts, 25 bools, no
  tables). Spec 28,871 bytes landed (28,870 + newline),
  user-side md5 c3b23233763d24f02f83aebf9465426a,
  landed-GitHub identical. Engine applied 4 then 0/4,
  audit mirror clean. Gap unchanged 139/16. PREFLIGHT
  GREEN with census 459 audit lines, each exactly once,
  all bad 0; BUILD: 0 warnings. NEXT - R536: Area 6 the
  Caverns of the Ancients (printed p. 81, pdf 82): the
  30-ft entry tunnel, the domed half-mile chamber, the
  bestial temple, the 100-ft palace facade - its capture
  text already read warm.
- R536 LANDED 2026-10-17: commit f4d090e (census 459 -> 460,
  pushed d08481f..f4d090e), THE DSG DEEPEARTH AREAS 6-7,
  printed pp. 81-82 (pdf 82-83) - the individual area key
  reaches the dead heart and the great chasm: Area 6 the
  Caverns of the Ancients (the 30-ft-wide 10-ft-ceiling entry
  tunnel to the half-mile domed chamber; the bestial temple
  and its concentric two- and three-story stone rings with
  the cavern-wall barracks; the palace with its shut brass
  doors - the only closed doorways - and the 100-ft-high,
  300-ft-wide facade; the five 60-degree-interval tunnels
  gone to dusty farmland; the duergar exodus from the dried
  wells; the palace honor guard of hundreds of zombies,
  skeletons and mummified leaders pursuing only to the
  Area 6/7 juncture; the stale air - 2d6-round gasps,
  1d6-round recoveries; the stripped fragile furnishings;
  and the secret smithy trapdoor - the extinguished
  furnaces and the 25,000-gp forge-of-power anvil with its
  +1 enchantments, +2/+3 with a hammer of substance), and
  Area 7 the Grand Canyon of Deepearth (the ten-mile,
  mile-wide chasm with its 200-ft arching ceiling and the
  rubble gorge over a mile down; the dead water-erosion
  river; the stable cracked walls with no bridges; the
  hidden caverns 3,000 ft down and two miles south; the
  300-ft limestone cave mouths at 500-ft intervals; the
  1-to-3-ft sewer shafts; the mobats in 2d6 groups; the
  cave fishers, giant slugs, centipedes and carrion
  crawlers; the two dozen cloakers, 50% drawn to mobat
  fights; the stagnant pools with their 50% disease; and
  the sparse wall-niche fungi). A CLEAN-READ ROUND: both
  machine reads agree on every number (djvu ~lines
  10303-10463, Capture idx 372-376; the djvu "5096" and
  Capture "ld6" garbles settled by the other read).
  DELIVERY: the trailing-newline fix from R535 works - the
  user-side md5 5cadedf369df57c3e7aa880b001f454e matches
  the staging md5 exactly (spec 24,304 bytes). A ZERO-FLIP
  ROUND: the pp. 75-98 Deepearth child remains open (the
  R527/R533/R534/R535 precedent - the gap report NOT in
  the git add). Pinned as rules/dsgarea3.h (prefix dnae,
  verified free; 43 inlines - 30 consts, 13 bools, no
  tables). Engine applied 4 then 0/4, audit mirror clean.
  Gap unchanged 139/16. PREFLIGHT GREEN with census 460
  audit lines, each exactly once, all bad 0; BUILD: 0
  warnings. NEXT - R537: Area 8 the Fungus Forest (printed
  pp. 82-83, pdf 83-84): the dozen chambers several hundred
  feet across, the 50/60-ft ceilings, the 30-ft mushroom
  caps, the myconid circle of 20 with its animator-spore
  zombies - djvu text already extracted, capture warm.
- R537 LANDED 2026-10-17: commit 7d0bc86 (census 460 -> 461,
  pushed f4d090e..7d0bc86), THE DSG DEEPEARTH AREAS 8-9,
  printed pp. 82-84 (pdf 83-85) - the tended garden and the
  great crossroads: Area 8 the Fungus Forest (the maze-like
  circle of chambers several hundred feet across and 50/60
  ft high, ogre-passable throughout; the dozen carpeted
  chambers - shriekers, violet fungus, edibles - over soft
  loam; the cross-bred 30-ft caps with crushed-stone paths;
  the myconid tenders of the one fungus-free central cavern;
  the Area 9 irrigation relay with inverted mushroom caps;
  the circle of 20 under the very old king; the animator-
  spore zombies - humans, mobats, two derro, a host of
  jermalaine; the musty circulating air, stone cistern,
  unlimited guarded food; and the one-foot continual-light
  levitating boulder), and Area 9 the Caverns of Doom (the
  key crossroads; the western 1d3x10-ft city route, dead
  cave, pits and chasms; the five natural branch caverns;
  the six linked central caverns - hundreds-ft ceilings,
  1,000-ft widths, 2d6-mile lengths, 20/10-ft connections;
  the name from the surface tales; the jermalaine bands and
  northern community, the drow-duergar-pech pockets at
  odds, the city raiding parties; the monster menagerie -
  toads, stirges, piercers, spiders, jellies, puddings,
  molds, rust monsters, cockatrices, gargoyles, wraiths,
  wights; the only decent water in the section - the
  svirfneblin sub-2-ft pipelines from Area 4 to three
  caverns, two monopolized, one shared; the cave-pig herds
  and fungus gardens; the pech claims and their secret
  wall-of-stone-screened diamond mine; the duergar
  fortified spout pool with three blocked caves and acid
  above; and the jermalaine honeycomb - 18-to-24-inch
  passages, private streams, 20-ft-high exits with rope
  ladders). A CLEAN-READ ROUND: both machine reads agree on
  every number (djvu ~lines 10465-10692, Capture idx
  376-384; the Capture 'ld3x 10' settled by the djvu).
  DELIVERY HICCUP, RESOLVED: the first paste failed with
  'No such file' - the spec had not reached the Termux
  side; the user re-copied from the canvas, the md5
  900089b201294c6832509690c0ccc600 matched exactly (spec
  25,980 bytes, trailing-newline convention). CLEANUP
  NOTE: the user's stray save left tools/spec_r538.json
  untracked on the Termux side - it was NOT committed;
  delete it before the R538 round (no R538 spec exists
  yet). A ZERO-FLIP ROUND: the pp. 75-98 Deepearth child
  remains open (the R527/R533-R536 precedent - the gap
  report NOT in the git add). Pinned as rules/dsgarea4.h
  (prefix dnaf, verified free; 44 inlines - 26 consts,
  18 bools, no tables; 1d3x10 pinned as a count-sides-
  multiplier triple). Engine applied 4 then 0/4, audit
  mirror clean. Gap unchanged 139/16. PREFLIGHT GREEN
  with census 461 audit lines, each exactly once, all
  bad 0; BUILD: 0 warnings. NEXT - R538: Area 10 the
  Sunken Swamp (printed pp. 84-85, pdf 85-86): the
  quake-drowned forest, 1,000-to-4,000-ft chambers 3d6
  miles long, the degenerated 50-100-strong cannibal
  tribes, the reconciliation councils - djvu head read,
  capture warm.
- R538 LANDED 2026-10-17: commit 19ed143 (census 461 -> 462,
  pushed 7d0bc86..19ed143), THE DSG DEEPEARTH AREAS 10-11,
  printed pp. 84-86 (pdf 85-87) - the drowned land and the
  flayer outpost: Area 10 the Sunken Swamp (the ancient
  earthquake that split the faults and felled the surface
  forest and villages; the rock faces wedged into
  survivable hollows; the dozen-plus chambers 1,000 to
  4,000 ft wide and 3d6 miles long, dirt-lined over rotted
  timber, misted from above, glowing mosses as dim light;
  the oil-soaked shored tunnels linking each cavern to at
  least two others; the degenerated sub-savage tribes -
  50 to 100 per cavern, emotion-speech, the chosen-few
  factions, the study-then-eat hospitality, the
  free-for-all wars and casualty-devouring reconciliation
  councils; the scavengers, shambling mounds, snakes,
  spiders, toads, frogs over plentiful fungi; the muggy
  decay air, the shapeless earth, the smoky peat; the
  sacred roofless temple with its gold-silver-platinum
  relics, the corroded sacred armory; and the smallest dry
  cavern's petrified unburnable wood), and Area 11 the
  Outpost of the Illithids (the mile-round central cave
  with its 100-ft ceiling on six pillars, the four
  converging streams and the porous outflow-less pond; the
  four cardinal side caves - about a mile long, never more
  than 50 ft wide, ceilings to 20 ft but often 6 or less;
  the living-cave formations; the 25 mind flayers with their
  scouts and homeland alarms; the side-cave scavengers -
  crawlers, otyughs, rats, slimes, jellies, oozes; and the
  circle of dwarven one-room huts around the pool - a
  guard per entry cave, the secret trap-door trove of
  cp-sp-ep-gp coins, gems, weapons, scrolls, half-dozen
  potions). A CLEAN-READ ROUND: both machine reads agree on
  every number (djvu ~lines 10692-10885, Capture idx
  384-392). The user's stray spec_r538.json from the R537
  hiccup was removed pre-round and this round's delivery
  was clean on the first try: md5 477a7c14962016ff52ea48ff
  aad28123 matched exactly (spec 23,088 bytes). A
  ZERO-FLIP ROUND: the pp. 75-98 Deepearth child remains
  open (the R527/R533-R537 precedent - the gap report NOT
  in the git add). Pinned as rules/dsgarea5.h (prefix dnag,
  verified free; 37 inlines - 19 consts, 18 bools, no
  tables; 3d6 pinned as a count-sides pair). Engine applied
  4 then 0/4, audit mirror clean. Gap unchanged 139/16.
  PREFLIGHT GREEN with census 462 audit lines, each
  exactly once, all bad 0; BUILD: 0 warnings. NEXT - R539:
  Area 12 the Combat Zone (printed pp. 86-87, pdf 87-88):
  the three-by-four-mile open cavern, the dozen supporting
  blocks hundreds of feet across, the 100-ft gorge-floor
  walks, the 10/20/100-ft barriers, the jermalaine-pech
  war at 10-to-1 odds, the 3x5-ft widened connections - djvu
  head read, capture warm.
- R539 LANDED 2026-10-17: commit ca570ac (census 462 -> 463,
  pushed 19ed143..ca570ac), THE DSG DEEPEARTH AREAS 12-13,
  printed pp. 86-87 (pdf 87-88) - the battleground and the
  empty quarter: Area 12 the Combat Zone (the three-by-
  four-mile open cavern with little rock fill; the quake
  landscape and the dozen mighty blocks hundreds of feet
  across holding the sagging ceiling; the gorge-split floor
  - no 100-ft same-elevation walks, 10/20-ft drops,
  100-ft barriers; the jermalaine-widened 3x5-ft passages
  to Areas 9 and 13; the decimated defeatist jermalaine vs
  the disciplined pech - under 100, outnumbered 10-to-1,
  stone wagons and wall-of-stone bridges; the rats, mobats,
  chimera and basilisk nests; the column-side waterfalls
  and porous-floor pools; the quake-gathered iron-lead-
  gold veins with jade and onyx; the 20% hollow-shell
  bridge sabotage collapsing over 50 lb/500 gp; and the 16
  camouflaged troves - 2d6-x-1,000-gp gems, matching coins,
  lead-iron ingots, 16-ft seals), and Area 13 the Empty
  Caverns (the Area 12 tunnel and the Area 7 canyon crack;
  the numerous small maze caverns pinching under 18 inches;
  the dusty dead caves with brittle formations; the bat
  thousands, preying basilisks and carnivorous beetles;
  the two-end ventilation with no water or fungi; and the
  abandoned dry lair tunnels). A CLEAN-READ ROUND: both
  machine reads agree on every number (djvu ~lines
  10892-11036, Capture idx 392-396; only spacing garbles -
  'Adozen', 'zbne', 'wallofstone'). DELIVERY clean on the
  first try: md5 72c320487d957b116d408b66c6ba4e11 matched
  exactly (spec 19,844 bytes). A ZERO-FLIP ROUND: the
  pp. 75-98 Deepearth child remains open (the
  R527/R533-R538 precedent - the gap report NOT in the
  git add). Pinned as rules/dsgarea6.h (prefix dnah,
  verified free; 32 inlines - 20 consts, 12 bools, no
  tables; 2d6x1,000 pinned as a count-sides-multiplier
  triple). Engine applied 4 then 0/4, audit mirror clean.
  Gap unchanged 139/16. PREFLIGHT GREEN with census 463
  audit lines, each exactly once, all bad 0; BUILD: 0
  warnings. NEXT - R540: Area 14 the Reclaimed Caverns
  (printed pp. 86-87, pdf 87-88): the pech-diked former
  lake bed; the two river routes - the Area 5 river's
  500-ft waterfall and six-ft airspace, the eastern
  river's sinkhole dive with its 10-ft airspace; the three
  parallel caves; the 8x12-ft descending bridge cavern;
  the 300-miner pech community with iron and copper; the
  scrags, mounds, mouther, ropers, owl bear; the 20-25
  kuo-toan war parties; and the water-wheel pump with the
  smelting forge and its one-foot valley vent - djvu read,
  capture warm.
- R540 LANDED 2026-10-17: commit 00a983f (census 463 -> 464,
  pushed ca570ac..00a983f), THE DSG DEEPEARTH AREAS 14-15,
  printed pp. 86-88 (pdf 87-89) - the reclaimed lakebed and
  the great water: Area 14 the Reclaimed Caverns (the pech-
  drained former lake with its two north inflows and south
  outflows; the Area 5 river's 500-ft waterfall and six-ft
  airspace; the eastern river's thousand-ft mountain
  waterfall dive through the sinkhole, 10-ft airspace,
  navigable; the three parallel caves with walls-of-stone
  dikes; the 8x12-ft descending bridge cavern; the
  water-polished smooth caves; the 300-miner community
  over the iron and copper; the scrags, mounds, mouther,
  crickets, leeches, ropers, owl bear, rust monsters,
  cockatrices; the Area 15 kuo-toan sabotage war - 20-25
  parties every few months, always defeated; the guarded
  ore stockpiles; and the water-wheel centrifugal pump
  with the smelting forge venting through the one-foot
  aperture, the stone town stacked three-four deep), and
  Area 15 the Upper Lake of Deepearth (the almost
  completely water-filled chamber, boat-traversable; the
  west shoreline shelf 10-to-400 ft wide with its piers and
  50% chance of 1d6 longboats; the cold still 10-to-100-ft
  depths; the center drain matched to the inflow and
  regulated by the kuo-toa boulders; the blind fish and the
  great kuo-toan domes with their air pockets; the giant
  catfish-pike-gar-lamprey and the nagas, otters, crabs,
  turtles, scrags, lacedons; the aboleth - the most purely
  evil denizens of Deepearth, slavers of all but the
  kuo-toa; the aquatic fungi and brown algae; and the domed
  city by the drain - six hexagonal 150/50-ft domes with
  20 ft of air and swim-through elevator holes). A
  CLEAN-READ ROUND: both machine reads agree on every
  number (djvu ~lines 11005-11253, Capture idx 396-400;
  the djvu '5096' and Capture 'ld6' settled cross-read;
  NOTE the idx396 page-block order anomaly - the p. 87
  area 14 body leads the p. 86 tail blocks, all text
  present). DELIVERY clean on the first try: md5
  820b1b83b714bee67b54a6c0220ef318 matched exactly (spec
  25,408 bytes). A ZERO-FLIP ROUND: the pp. 75-98
  Deepearth child remains open (the R527/R533-R539
  precedent - the gap report NOT in the git add). Pinned
  as rules/dsgarea7.h (prefix dnai, verified free; 43
  inlines - 22 consts, 21 bools, no tables; 1d6 pinned as
  a count-sides pair). Engine applied 4 then 0/4, audit
  mirror clean. Gap unchanged 139/16. PREFLIGHT GREEN
  with census 464 audit lines, each exactly once, all
  bad 0; BUILD: 0 warnings. NEXT - R541: Area 16 the
  Mid-Level Caverns (printed pp. 88-89, pdf 89-90): the
  1,000-ft spiral stairway - 10-ft-wide stairs, one-ft
  deep, eight-inch drops, the 10-ft shaft, no guardrail;
  the drapery-central living cave; the west descent's
  1d6x10-ft cliffs and two 3-ft pinches; the 50-ft,
  20-to-30-ft-deep pools; the greater basilisk, mimics,
  bowlers, trappers, xorn, piercers, rock reptiles, scum
  creepers, mud men; the same copper-iron veins continuing
  - djvu head read, capture warm.
- R541 LANDED 2026-10-17: commit d346677f94e4a3f66c8541fad5b3d
  76597fa8cc1 (census 464 -> 465, pushed 00a983f..d346677), THE
  DSG DEEPEARTH AREAS 16-17, printed pp. 88-89 (pdf 89-90) -
  Area 16 the Mid-Level Caverns (the 1,000-ft spiral stairway
  with 10-ft width, 1-ft-deep stairs, 8-inch drops, hollow
  10-ft shaft, no guardrail; the living caves; the drapery
  central cave ringed by 12+ smaller caves; the steep west
  descent - 20-ft-wide cavern, 1d6x10-ft cliffs, two 3-ft
  pinches; the clear pools, largest 50 ft, commonly 20-30 ft
  deep; wilderness status with pech/jermalaine/derro/drow
  passing through; the monster caves - greater basilisk +
  mimics central, bowlers, trappers, xorn, piercers, rock
  reptiles, scum creepers, mud men in the flanks; fresh
  water/stuffy air/fungi; the Area 14 copper-iron veins
  streaking the draperies green/red; and the mud men's
  enchanted stream - potion of healing from its niche, magic
  lost to any container), and Area 17 the Lower Lake (the
  12x13-mile cavern, 600 ft high, bottom 500 ft water; the
  ceiling spout from the Upper Lake drain; the inaccessible
  shoreline, tunnel mouth 50 ft above the surface; the
  northern river 100 ft wide, 1d10+10 deep, ceiling 20-50
  ft; the silt floor; six underwater caves 100+ ft down; the
  aboleth-kuo-toa war; the kuo-toan southern domed city and
  inter-lake path; ~300 aboleth in the northern floating city
  with river-mouth guards; the fresh-water kraken - 40-ft
  entrance tunnel, 50 mixed-race slaves with a truce,
  tailing-stone pile; the >100,000-gp gold dust at 500 ft
  under the spout; the drain plunge - 2d6 rounds submerged,
  100-ft fall, 6d6 non-native halved on breath save, 3d6
  native negated on save; the aboleth city - 1,000-ft mucous
  disk, six slim towers, drain-holed wall, 20-30-ft lairs
  with 1 entrance, ~100-ft clan halls/nurseries/prisons with
  6 3-ft entrance holes, half water/half air with perch
  ledges, slave races held apart, Three Clans halls, 40-ft
  buoyancy disk). A CLEAN-READ ROUND: both machine reads
  agree on every number (djvu ~lines 11260-11493, capture
  idx 400-412; the capture '1dlO + 10' settled by the djvu
  as 1d10 + 10). 60 inlines (44 consts + 16 bools), header
  rules/dsgarea8.h, prefix dnaj, no table. DELIVERY clean
  md5-exact on the first try (the bn-free ritual): authored
  md5 6b5948ecc46381e012c183769e582bc4 matched exactly
  (spec 30,365 bytes), engine applied 4 then 0/4, preflight
  GREEN with AUDIT CENSUS: 465. A ZERO-FLIP ROUND: gap
  census stays 139/16, the pp. 75-98 Deepearth child open.
  NEXT - R542: Area 18 the Steam-Heated Caverns (printed
  pp. 90-91, pdf 91-92, djvu ~line 11485+) - volcanic
  fissures, the hot-water chute joining the meandering river
  five miles south, six large steamy caves, boiling-to-cool
  pools, mildew-slick rock - likely paired with Area 19.
- R542 LANDED 2026-10-17: commit 6a0c3d917c618fb7b3d99
  d4ec765a6b3d5f2df0a (census 465 -> 466, pushed
  d346677..6a0c3d9), THE DSG DEEPEARTH AREAS 18-19,
  printed pp. 90-91 (pdf 91-92) - Area 18 the
  Steam-Heated Caverns (the water-eroded region altered
  by volcanic upheavals, its sharp fissures tapped into
  the caves; the Lower Lake river reaching the connecting
  cavern five miles south, source of the rapid hot
  stream joining the river as the riverbed descends;
  the wide fine-sand shoreline landing; the expanded,
  straightened chute tunnel; the six large caves joined
  by narrow passages - steamy air, coated rock,
  boiling-to-cool pools, slippery mildew; the north
  tunnel to Area 21 with once-an-hour superheated
  blasts, 2% per round cumulative in 2% steps, 4d6
  halved on a breath save; the east stream inflicting
  4d6 per round, part-immersion reduced; the Plane of
  Fire spillover - efreet, fire elementals,
  salamanders, fire bats; the hell hounds, giant
  rats, green slime, crawlers, megalo centipedes; the
  fire giants holding sway, the nomadic clan over 50;
  the half-usual fatigue in the muggy air; water and
  fungi abundant, no minerals; and the geysers - a
  20% pool susceptibility, 6d6 halved on a save), and
  Area 19 the Chambers of Fire (the baked caves; the
  swept-clean approach tunnel at 1d6 per turn, dousing
  to avoid; the roughly circular caverns split by
  thousands-of-feet floor fissures belching smoke,
  poison gas, steam and fire once per hour per cavern,
  25% per type, lasting 1d6 rounds; the cave heat at
  1d6 per round, halved by dousing; the eruption
  volley - 6d6 per round from steam or fire halved on
  a breath save, poison gas save-or-die, 1d4 turns of
  smoke at the p. 36 effects; the 50% slender stone
  arches over the 3d6-foot fissures; the four mephit
  forms at 50% after the matching eruption, lava tied
  to poison gas; the common fire bats; the diving
  magmen; the smoky but breathable air, the mildew;
  and the remote cavern - 21-40 (1d20+20) toiling
  mephits widening the 20-foot fissure with fireproof
  pickaxes, intruders thrown in as offerings for a
  dark-lower-planes creature). A CLEAN-READ ROUND: both
  machine reads agree on every number (djvu ~lines
  11485-11685, capture idx 206/208; the djvu '296'
  and '346 ft' settled by the capture as 2% and 3d6
  ft, the capture 'ld6/ld4/ld20+20' settled by the
  djvu). 73 inlines (33 consts + 40 bools), header
  rules/dsgarea9.h, prefix dnak, no table. DELIVERY
  clean md5-exact on the first try: authored md5
  0ec642173140657e1f13d7fdc81388e2 matched exactly
  (spec 29,735 bytes) - the paste carried a stray
  './bn 542' line but no rewrite occurred; engine
  applied 4 then 0/4, preflight GREEN with AUDIT
  CENSUS: 466. A ZERO-FLIP ROUND: gap census stays
  139/16, the pp. 75-98 Deepearth child open. NEXT -
  R543: Area 20 the Lava Caves (printed p. 91, pdf
  92, djvu ~line 11688+) - the balcony cavern over the
  lava sea, the 400-ft cliff, the fire giant outpost
  of ~20 with a dozen hell hounds, the 1,000-ft
  ceiling, the once-a-decade invasions - likely
  paired with Area 21 the Elemental Vortex of Fire
  (p. 92); both reads already fetched this round.
- R543 LANDED 2026-10-17: commit 2765c345f27802ab0e9
  0e69b43fb21acdaf8107 (census 466 -> 467, pushed
  6a0c3d9..2765c34), THE DSG DEEPEARTH AREAS 20-21,
  printed pp. 91-92 (pdf 92-93) - Area 20 the Lava
  Caves (the balcony cavern overlooking the vast
  amphitheatre of molten rock, its weekly eruptions,
  the cataclysm-split cave half fallen away and baked
  brittle; the 400-ft climbable cliff with crags and
  support columns, the 1,000-ft ceiling losing chunks
  daily and venting smoke, the ocean-like swells and
  splashing; the fire giant outpost of ~20 with a
  dozen hell hounds, one of each always at the tunnel;
  the rock-island lairs of fire giants and lava
  children at 50% per island; the porpoise-like
  magmen, the ceiling-dwelling fire bats, the savage
  magma para-elementals; the once-a-decade elemental
  invasions repelled by the joined giants and lava
  children; the granite lava boats 80-240 ft at 20%
  width, twin-masted over 160 ft, an oar pair per 40
  ft; the fire giant king's island castle with its
  120-ft harbor mouth and dozen-per-flank towers), and
  Area 21 the Elemental Vortex of Fire (the waterless
  wind-sucked region, torch out 50%; the 1,000x300-ft
  rotted cavern; the perfectly circular 100-ft
  flame-ringed hole, hypnotic and bottomless, a
  Wisdom Check after one round compelling the failed
  jump; the vortex gate; the 1d6 guarding fire
  elementals and the 50% chance of 1d6 efreeti/
  salamanders/azer/fire bats/elemental grue
  reinforcing on the first and every other round; the
  hot dry sulphurous air; the 8d8-per-round passage
  falling as if feather-fallen, escapable by
  levitation or fly within five rounds, ten rounds to
  the volcanic landscape; and the two Prime
  connections - 50/50 Area 21 or the lava-sea
  whirlpool drawing boats within 500 ft). A CLEAN-
  READ ROUND: both machine reads agree on every
  number (djvu ~lines 11688-11932, capture idx 210
  with the p. 92 tail in idx 212; the djvu '848' and
  '5096' settled by the capture as 8d8 and 50%, the
  capture 'ld6' and 'ajarge' settled by the djvu). 63
  inlines (31 consts + 32 bools), header
  rules/dsgarea10.h, prefix dnal, no table. DELIVERY
  clean md5-exact on the first try: authored md5
  7032f70119bc39639f21e53aa2fd03b5 matched exactly
  (spec 28,396 bytes); engine applied 4 then 0/4,
  preflight GREEN with AUDIT CENSUS: 467. A ZERO-FLIP
  ROUND: gap census stays 139/16, the pp. 75-98
  Deepearth child open. NEXT - R544: Areas 22-23
  (printed pp. 92-93, pdf 93-94, djvu ~line 11935+) -
  Area 22 the Lands of the Deep Gnomes (the three-
  level 20x10-ft caverns, the 60-ft clan chambers,
  the 200-ft meeting hall, the ~5,000 svirfneblin with
  100+ rothe per clan, the smelter and the 550-
  Strength vault door on 500-sp silver bars) and Area
  23 the Lower Grand Canyon (the 1,200-ft descent, the
  1,000-ft width, the 20-ft bridge over the stone-
  arch arena); both reads already fetched this round.
- R544 LANDED 2026-10-17: commit 0523f0616f6e1f3bd677
  ba379dbd5d425436c1f5 (census 467 -> 468, pushed
  2765c34..0523f06), THE DSG DEEPEARTH AREAS 22-23,
  printed pp. 92-93 (pdf 93-94) - Area 22 the Lands
  of the Deep Gnomes (the long narrow north-south
  caverns stacked in three levels, averaging 20x10
  ft, pinching to 2-3 ft once per mile; the streams
  never filling the passages, the upper walks and
  gnome-built spiral stairways; the excavated homes
  from tiny burrows to crawl-in residences; one clan
  per cave with its 60x8-ft council chamber; the
  central 200x10-ft meeting chamber; the ~5,000
  svirfneblin with a third mobilizable; the
  protected rothe herds - 100 per clan, eight or 10
  times that; the trickling water and still pools;
  the Grand Canyon air circulation; the edible
  fungi; the iron-silver-copper-lead mines with
  five-mile shafts; the smelter and smithy venting
  to the lava sea; the traded and stockpiled
  surplus; and the vault - thousands of 500-sp
  silver bars behind the 550-Strength stone door
  opened weekly by winch teams, hidden by
  illusions), and Area 23 the Lower Grand Canyon
  (the lower portion of Area 7 descending another
  1,200 ft; the duergar and deep gnome domains
  meeting at the canyon, their thousand-spectator
  carved galleries facing across the 1,000-ft
  width; the 20-ft stone bridge; and the arena
  beneath - the three-dimensional web of stone
  arches, girders, rope ladders and nets where
  champion duels replace the wars, nonmissile
  weapons only, the duergar-svirfneblin duels always
  fatal, the girder spacing hampering the small
  warriors). A CLEAN-READ ROUND with no cross-read
  garbles at all: both machine reads agree on every
  number (djvu ~lines 11935-12079, capture idx 212
  = the p. 93 area-22 tail window, idx 214 head =
  area 23). 45 inlines (21 consts + 24 bools),
  header rules/dsgarea11.h, prefix dnam, no table,
  no dice. DELIVERY clean md5-exact on the first
  try: authored md5 022290ff9f29d2aae50abe8b916988
  38 matched exactly (spec 21,657 bytes); engine
  applied 4 then 0/4, preflight GREEN with AUDIT
  CENSUS: 468. A ZERO-FLIP ROUND: gap census stays
  139/16, the pp. 75-98 Deepearth child open.
  NEXT - R545: Areas 24-25 (printed p. 94, pdf 95,
  djvu ~line 12082+) - Area 24 the Domain of the
  Duergar (the ~100 caves of the 8,000 gray
  dwarves, the dammed water reservoirs, the 30-ft
  navigable outflow stream, the derro tenants and
  the 25%-escape slaves, the iron-copper-gold
  slave-worked mines, the gold sculptors with
  1d6x100-gp residences and 2d6x1,000-gp public
  halls and 20,000-gp life-size statues worth
  1d4+1 times intact, the fungus breweries and
  inns) and Area 25 the Windpipe (the six 80-ft-
  high living caves, the drow outpost of 4th+-
  level fighters with 5th+ MU and cleric, the 50%
  polluted pools, the ~20-ft smooth shaft); both
  reads already fetched this round (idx 214
  carried Area 24 in full and the Area 25 head).
- R545 LANDED 2026-10-17: commit c719f8828ff802cbd8e3
  2208ecf2a51be83b96d2 (census 468 -> 469, pushed
  0523f06..c719f88), THE DSG DEEPEARTH AREAS 24-25,
  printed p. 94 (pdf 95) - Area 24 the Domain of the
  Duergar (the largest gray dwarf concentration in
  Deepearth, nearly a hundred widened natural caves;
  the living caves, the ledged water-filled chambers,
  the drought-proof dammed reservoirs; the central
  council cavern; the 30-ft navigable outflow stream
  with its dry walkway; the 8,000 duergar with their
  rothe herds; the second-class derro tenants; the
  hundreds of demoralized slaves - humans, goblins,
  svirfneblin, drow - at a 25% escape-join chance;
  the un-eradicable giant bats; the Grand Canyon
  air and the cut ducts; the southwestern slave-
  worked iron-copper-gold mines; the fine-art
  metal-working and the gold sculptors - 1d6x100 gp
  per residence, six times that in larger homes,
  2d6x1,000 gp in the public halls, life-size
  20,000-gp statues worth 1d4+1 times intact; and
  the red-fungus breweries with the well-attended
  inns), and Area 25 the Windpipe (the six living
  caves with 80-ft miles-long central chambers
  joining at the excavated chamber; the high-level
  drow outpost - 4th+ fighters, 5th+ MU and cleric;
  the doombats, piercers, oozes, jellies, slimes,
  lichens, basidironds, rats and crawlers; the 50%
  polluted pools with one or two pure sources per
  cave; and the shaft - 20 ft wide, 20 miles to the
  mountain crevasse, door-sized entry, alternating
  blasts: one turn per hour roaring upward, four
  inactive, one down, varying as much as 50%; the
  ride five rounds up to Area 28, eight down, the
  failed Intelligence Check costing 6d6 falling
  damage). A CLEAN-READ ROUND: both machine reads
  agree on every number (djvu ~lines 12082-12255,
  capture idx 214 = Area 24 in full + the Area 25
  head, idx 216 head = the windpipe body; the
  capture ld6/2d6/ld4+1/ld12 settled by the djvu,
  the djvu 'realms o!' settled by the capture). 52
  inlines (31 consts + 21 bools), header
  rules/dsgarea12.h, prefix dnan, no table.
  DELIVERY clean md5-exact on the first try:
  authored md5 3739256c26c405c05ba60d9cbf2d1df2
  matched exactly (spec 25,012 bytes); engine
  applied 4 then 0/4, preflight GREEN with AUDIT
  CENSUS: 469. A ZERO-FLIP ROUND: gap census stays
  139/16, the pp. 75-98 Deepearth child open.
  NEXT - R546: Areas 26-27 (printed pp. 95-96, pdf
  96-97, djvu ~line 12258+) - Area 26 the Hallowed
  Grounds (the mile-wide dozen-mile-long caverns
  with 1,000-ft ceilings and gorges, the battle
  debris and thousands of skeletons, the undead
  legions - wights, wraiths, spectres, ghosts,
  skeletons - each cavern commanded by a lich of
  18-27th level (17+1d10), 20% MU/clerics, the
  treasure houses with their battle magic) and Area
  27 the Melting Pot (the small-cavern maze, the
  1d12-cave racial niches - drow, duergar, pech,
  derro, cloakers, myconids, umber hulks, kuo-toa -
  the sacred water, the exhausted mineral veins,
  the secret passages); both reads already
  fetched this round (idx 216 carried Area 26 in
  full and the Area 27 head).
- R546 LANDED 2026-10-17: commit 550374b6d44fbefb3fc
  7961c4c0c905e9593860 (census 469 -> 470, pushed
  c719f88..550374b), THE DSG DEEPEARTH AREAS 26-27,
  printed pp. 95-96 (pdf 96-97) - Area 26 the
  Hallowed Grounds (the largest chambers in all
  Deepearth - 1,000-ft ceilings, mile-wide dozen-
  mile-long caverns, bridged gorges, city ruins; the
  streams and deep lakes; the barren beaten look, the
  collapsed bridges; the battle debris and thousands
  of skeletons - drow, duergar, svirfneblin, derro,
  plus the skeleton-less pech, cloakers, illithids;
  the sacrosanct spirits - wights, wraiths,
  spectres, ghosts, skeletons - each cavern under a
  single lich; the plentiful air/water but no food;
  the centuries-scavenged battlefields; and the
  treasure houses - thousands of weapons, war
  machines, coin/gem/jewelry fortunes and battle
  magic beyond measure, each held by an undead army
  under a lich of 18-27th level (17+1d10), 20% MU/
  clerics and 80% magic-users), and Area 27 the
  Melting Pot (the small-cavern maze with lustrous
  formations; the racial niches of 1d12 caves -
  drow, duergar, pech, derro, cloakers, myconids,
  umber hulks, kuo-toa - each vigorously defended
  with fortifications, traps and war training; the
  rothe herds and fungus plots; the sacred
  unpollutable water; the exhausted veins and wise
  raw-material use; the secret passages and
  concealed entrances of the crowded history). A
  CLEAN-READ ROUND: both machine reads agree on every
  number (djvu ~lines 12258-12360, capture idx 216;
  the djvu '17 + 1410' and '8096' settled by the
  capture as 17+1d10 and 80%, the capture 'ld12'
  settled by the djvu as 1d12). 29 inlines (9 consts
  + 20 bools), header rules/dsgarea13.h, prefix
  dnao, no table. DELIVERY clean md5-exact on the
  first try: authored md5 927d5aaaae30248de10f7240
  671b45b8 matched exactly (spec 17,026 bytes);
  engine applied 4 then 0/4, preflight GREEN with
  AUDIT CENSUS: 470. A ZERO-FLIP ROUND: gap census
  stays 139/16, the pp. 75-98 Deepearth child open.
  NEXT - R547: Area 28 the Realm of the Drow
  (printed p. 96, pdf 97, djvu ~line 12362+) - the
  excavated realm of living caves, the mile-wide
  1,000-ft-domed council chamber with its
  levitation-only shaft, the built drow cities with
  surface-style buildings, the placid waterways and
  boat travel, likely paired with Area 29 the Dark
  Realms (p. 97); the djvu head is already read,
  capture window with the next fetch.
- R547 LANDED 2026-10-17: commit 627fcb27e3b6eb5ec35
  b6bf43fc84a9c2810cf54 (census 470 -> 471, pushed
  550374b..627fcb2), THE DSG DEEPEARTH AREAS 28-29,
  printed pp. 96-97 (pdf 97-98) - Area 28 the Realm
  of the Drow (the excavated caverns linking the
  living caves, the high point of drow culture; the
  perfectly circular council chamber over a mile in
  diameter with its 1,000-ft dome on massive columns
  and the flight-or-levitation shaft to the
  matriarchs' hall; the built cities - buildings
  erected in the caverns like surface communities;
  the plentiful water, the huge reservoirs, the
  placid waterways where boat travel rivals walking;
  the sculpted passages and spiral stairways; the
  miniature council refuges gated to 4th-level+ drow
  where levitation is universal, rope ladders for
  the rest in emergency; the 12,000+ drow with their
  rothe and cave pigs; the windpipe air and the
  sages' pressure theory; the clean water, the
  fungus farms with their slight surplus, the strict
  population control; the iron-copper-silver-gold-
  adamantite-mithril mines; and the architecture -
  columns, buttresses and domes lit by
  phosphorescent fungi, gold and silver ornament
  never structural), and Area 29 the Dark Realms
  (the spiderweb of living caves descending to the
  central chamber; the trickle that never floats a
  kayak, the water met as thick cold mud; the
  chamber with 12 mouth passages feeding the
  monstrous reservoir - 300 ft deep, nearly a mile
  across, its level constant for centuries; the
  cloakers driven into a few dozen caverns, the
  illithids' evil third, the well-defended derro;
  the unclaimed domains of slimes, oozes, jellies,
  animated fungi and scavengers; the hundred-plus
  Plane of Earth denizens - elementals, xorn,
  crysmal, galeb duhr, chaggrin, dao - clustered
  near their vortex; the stale air, the nearly
  unexploited gems and metals behind deadly hazards;
  and the mud whirlpool - the slow-motion vortex to
  the Plane of Earth, the Area 21 procedure without
  heat damage, breath held in transit). A CLEAN-READ
  ROUND: both machine reads agree on every number
  (djvu ~lines 12362-12554, capture idx 216 tail +
  idx 220 + idx 225 head; the djvu Cyrillic-The and
  '/evitation' settled by the capture). 35 inlines
  (6 consts + 29 bools), header rules/dsgarea14.h,
  prefix dnap, no table, no dice. DELIVERY clean
  md5-exact on the first try: authored md5
  9cb59d911ef52b45a1f742b1363d1e0e matched exactly
  (spec 19,327 bytes); engine applied 4 then 0/4,
  preflight GREEN with AUDIT CENSUS: 471. A ZERO-
  FLIP ROUND: gap census stays 139/16, the pp.
  75-98 Deepearth child open. NEXT - R548: Areas
  30-31, the FINAL TWO AREAS of the Deepearth key
  (printed pp. 97-98, pdf 98-99, djvu ~line 12557+) -
  Area 30 the Interplanar Whirlpool (the 2,000-ft
  plunge of the Area 17 river down the 100-ft shaft,
  the breakwater landing and switchback stairs, the
  nereid guardians with three-turn reinforcements,
  the water-vortex journey) and Area 31 Darksea (the
  hundred-mile mildly salty sea, the 1,000-ft
  ceilings and 2,000-ft depths, the aboleth capital
  with its 36 towers, the losing kuo-toan war);
  both reads already fetched this round (idx 229
  carried Area 30's tail, the whirlpool cavern and
  all of Area 31; after R548 lands the pp. 75-98
  Deepearth child GAP-FLIP question reopens).
- R548 LANDED 2026-10-17: commit fbd8408f56a7d817fd153e8
  172405e2ced3149d0 (census 471 -> 472, pushed
  627fcb2..fbd8408), THE DSG DEEPEARTH AREAS 30-31,
  printed pp. 97-98 (pdf 98-99) - Area 30 the
  Interplanar Whirlpool (the 2,000-ft plunge down a
  100-ft-diameter shaft with 20-ft minimum ceilings,
  the plane-water lake rarely shallower than 100 ft
  with bottoms 1,000 ft down, the nereid
  reinforcements arriving within 3 turns, the
  water-drinking planar corruption) and Area 31 the
  Darksea (the 100+ mile reach under 1,000-ft
  ceilings plunging 2,000 ft at deepest, the dozen+
  aboleth cities, the capital 3x usual size with 36
  towers against the standard 6). Prose-only round;
  12 consts + 24 bools, prefix dnaq, header
  rules/dsgarea15.h, spec 21,385 bytes, 36 inlines;
  djvu lines ~12557-12709 with capture idx 229
  cross-read (garbles: seerns->seems, var-dig->
  vardigg); first try: authored md5 cf3257a8e48110
  41de3d57dbc8ea91f matched exactly; engine applied
  4 then 0/4, preflight GREEN with AUDIT CENSUS:
  472. A ZERO-FLIP ROUND: gap census stays 139/16,
  the pp. 75-98 Deepearth child open. THE DEEPEARTH
  AREA KEY IS COMPLETE (areas 1-31, R533-R548).
  NEXT - R548: decision point - either the Deepearth
  child gap-flip round (the R527/R533-R548
  "until the setting lands in full" condition is
  finally satisfied) or the next DSG section (pp.
  99+ Campaign Considerations).
- R549 LANDED 2026-10-17: commit 00c2b327a8a4bdc394a5fc
  7009888cc35715a64f (census 472 -> 473, pushed
  fbd8408..00c2b32), THE DSG LANDS OF DEEPEARTH
  CLOSED - THE FIRST FLIP-ONLY ROUND OF THE ARC:
  zero pins (0 consts, 0 bools, 0 tables, 0
  inlines), the census advances by the audit block
  alone, and the long-held pp. 75-98 Lands of
  Deepearth child finally flips [x] - the gap
  census moves 139/16 -> 140/15. The child closes
  against work already landed and verified: R533
  the opener (rules/dsgland.h - the setting frame,
  the connecting-passage generation, the
  area-details framework; the pp. 76-77 map plates
  graphics, pinning nothing) and R534-R548 the
  individual area key, areas 1-31 (rules/
  dsgarea1.h through dsgarea15.h). The R503
  closure criterion - a box closes when the
  feature PLAYS right, and the flip rides the SAME
  commit - satisfied for the child the whole
  Deepearth stretch held open "until the setting
  lands in full". Prefix dnas (NOTE: the summary
  list of used dna* prefixes missed dnar - the
  R533 opener itself; verified free against
  regtest before use), header rules/dsgdeep.h
  (empty namespace, banner only), spec 4,960
  bytes, md5 015111a42b8d9e84708cb051b1f4b3b3
  matched exactly first try; engine applied 5
  then 0/5 - FIVE patches, one more than the
  usual four, because the gap report is in play
  this round; dsg_gap_report.md IS in the git add
  (the flip rides the commit); preflight GREEN
  with AUDIT CENSUS: 473. NEXT - R549: the DM
  section has two open children left - Campaign
  Considerations (pp. 99-113) and Mapping
  (pp. 114-117); next round opens pp. 99+.
- R550 LANDED 2026-10-17: commit 033b4399407ad31ee37c7
  17cdc990db7b37bb7a0 (census 473 -> 474, pushed
  00c2b32..033b439), THE DSG CAMPAIGN CONSIDERATIONS
  OPENER, printed pp. 99-100 (pdf 100-101) - the
  chapter frame (the myriad ingredients, the skilled
  DM with time, energy and the communication talent
  first, the willing players sharing common goals
  next, the hack-and-slash vs plot-structuring
  mismatch warning), the three player types - the
  Adventurers (combat above all, magic-bonus
  judging, quick replacement, the treasure draw,
  the easiest to DM for, monster intelligence and
  variation, item discipline with odd restrictions,
  planning-gated success, no instant death, the
  veteran return), the Problem-Solvers (the great
  puzzle, the convoluted plot the better, tactical
  battles, rules creativity, the routine boredom,
  the challenge balance, the borrowed tricks, the
  motivation toolkit, the mystery story line), and
  the Role-Players (total detail, the shopping
  role-play, the growth frame, the believable
  faults, the interaction talk, the personal
  stakes, the value hooks) - Challenges for the DM
  (the blend, all three served), the Fine Art of
  Juggling (feedback, the restless-Adventurer
  random encounter, the dying-bandit clue, the
  talk cadence, the per-style rewards), Designing
  the Adventure and the World (settings + story
  line, the deferred orc detail, the no-advance
  rule, the preparation payoff), and Worlds of
  Adventure through the social-structure split
  (the clear good/evil ease against the complex
  realistic societies; the contrast sentence
  breaks across the pp. 100-101 boundary and pins
  whole with the break noted). Prose-only round: 1
  const + 60 bools, prefix dcc (NEW FAMILY - the
  campaign chapter leaves the dna* Deepearth run
  behind; verified free), header rules/dsgcamp.h,
  spec 26,449 bytes, md5 dad51b1ab207aecca09f6432
  b55367b5 matched exactly first try, 61 inlines;
  djvu lines 12711-13012 with the Capture-layer
  pdf 100-101 cross-read - NOTE: the staging
  rebuild had no poppler, so the capture read rode
  a PURE-PYTHON extractor (book/pdf_text.py,
  reading the Tj/TJ text layer of the same IA
  pdf; parser page = printed page); the one
  settled garble djvu NPOs->NPCs. ENGINE LESSON:
  the cond syntax gate rejects the word 'not' in
  example exprs - use the '!= 1' form for bool
  examples (R550 first run aborted on it). A
  ZERO-FLIP ROUND: gap census stays 140/15, the
  pp. 99-113 Campaign Considerations child open
  until the whole chapter lands. NEXT - R550: the
  rest of Worlds of Adventure (pp. 101-103 - the
  real-life sources, richness of detail, variety
  of options, location types; djvu from ~line
  13012), then Plot and Counterplot (pp.
  103-106), the techniques + matrix campaign (pp.
  109-112), help from the players (p. 113), then
  the child flip.
- R551 LANDED 2026-10-17: commit 739d8fbc051f0cadb4b109
  cd69112972e939a078 (census 474 -> 475, pushed
  033b439..739d8fb), THE REST OF WORLDS OF
  ADVENTURE, printed pp. 101-103 (pdf 102-104) -
  the second half of the setting-design doctrine:
  the location-type variety (the underworld's
  missing climate criterion, the natural/
  artificial source, the unique area features, the
  inhabitant variety, the individualistic monsters
  - the fashion-judge orc chieftain, the
  story-starved captor chieftain - the
  stale-campaign surprise cure), the dangerous/
  safe mix (the friendly NPC encounters, the
  shoot-first consequences, the tranquil havens,
  the no-regular-haven-violations rule),
  Consistency (the underlying-idea rule, the
  familiarity-over-realism doctrine with the
  dragon example, the source and historical
  familiarity, the stable world rules, the nature
  laws - seasons, snowy mountaintops, tides - the
  growing familiarity, the law consequences with
  the treasury-thief example), the Intelligent
  Races questionnaire (foresight, the
  original-vs-known split, appearance, livelihood,
  the civilization hallmarks - literacy,
  metalworking, beyond-borders knowledge - the
  settlement scale, the customs with the
  empty-palm/handshake show-no-weapon example, the
  limitations, the preferences, the glocks, the
  first impressions), and Uniqueness (the DM's
  style, the unusual names, the new architecture
  and plant forms, the faithful-recreation
  exception). PURE-PROSE ROUND: 0 consts + 37
  bools, prefix dcd, header rules/dsgcamp2.h,
  spec 22,397 bytes, md5 7f95ce1627720d18ed4aab
  b6b61387ed2 matched exactly first try, 37
  inlines; djvu lines 13013-13326 with the Capture
  pdf 102-104 cross-read (clean; the one garble
  capture determinatibn->determination by djvu;
  the glocks passage identical in both reads).
  AUTHORING STUMBLES CAUGHT IN STAGING: the
  inline_count said 38 for 37 pins, and the first
  engine run hit the mixed applied/already state
  because prev_seed_key pointed at R549 while the
  seed at HEAD already held the R550 record - the
  R551 spec must insert the R550 record
  (prev_seed_key = R550's opening line). Both
  fixed before publish. A ZERO-FLIP ROUND: gap
  census stays 140/15. NEXT - R551: Plot and
  Counterplot: The Importance of Story, printed
  pp. 103-106 (the story structure - exposition,
  climax, denouement - the exposition techniques
  against the long NPC speech, the buildup
  techniques; djvu from ~line 13327), then the
  story techniques pp. 109-112, help from the
  players p. 113, then the child flip.
- R552 LANDED 2026-10-17: commit 3e9a7503d8891c183f9f0
  cd98328babaf757989e (census 475 -> 476, pushed
  739d8fb..3e9a750), THE DSG PLOT AND COUNTERPLOT,
  printed pp. 103-106 (pdf 104-107) - the
  storytelling doctrine: the chapter head (the
  story as important as the world setting, the DM
  as bard or storyteller), The Story Structure
  (the ancient hearth lineage, the exposition,
  the development with its rising tension and
  several climaxes, the climax resolving the major
  conflicts, the denouement retrospection), the
  exposition craft (the long-NPC-speech mistake,
  the acted-out encounter, the handouts, the
  information cards with the format fit, the
  combat opener especially for Adventurer-types,
  the combat-before-speech rule, the between-
  session advance information), the development
  craft (the minion encounters teaching the
  opposition, the sages/seers/beggars prods, the
  random-encounter balance, the semi-climax), the
  climax doctrine (the game-balance primary, the
  mental-plus-physical, the deadly potential, the
  adversary tactics with the special aid and the
  emergency escape route - the always-escaping
  villain campaigns, the multiple solutions, the
  staging drama - the evil temple or the
  fiery-chasm bridge, the dramatic key goal of
  fun), the denouement (the loose ends, the
  safety with the arrogance reminder, the
  next-adventure lead avoiding the inn opening),
  Multiple Story Lines (the tailored lines, the
  heroic epic form - broad good-sanctioned
  purpose, cost-gained achievement, the
  years-spanning conflict, the session climax
  and the 3-4-session major objectives, the rare
  cliffhanger with its low player tolerance, the
  periodic changes - the new epic every year or
  so), and the Story Elements head with The
  Villains (the antagonist as any blocking force,
  the unintelligent single-session foes, the
  minimal-intelligence tactical options, the
  villain hierarchy, the unique NPCs, the
  familiarization without confrontation, the
  personal confrontation relished, the buffoon,
  the party-equal power or the protections, the
  surviving villain returning stronger) and the
  Foreshadowing opener (the hints/portents/
  dreams, the black-hole warning, the
  Problem-Solver affinity, the augury
  invitation - the section crossing the pp.
  106-107 boundary, its tail completing next
  round). 3 consts + 52 bools, prefix dce, header
  rules/dsgcamp3.h, spec 30,736 bytes, md5
  6a580bd99a3334f53888eef48f924fae matched
  exactly first try, 55 inlines; djvu lines
  13327-13752 with the Capture pdf 104-107
  cross-read (clean). Another inline_count
  authoring miss caught in staging (56 written
  for 55 pins - ALWAYS recompute the count
  before publish). A ZERO-FLIP ROUND: gap census
  stays 140/15. NEXT - R552: the rest of Story
  Elements pp. 107-108 (the foreshadowing tail
  and the following elements), then Techniques
  of Story and Campaign Design pp. 109-112 (the
  matrix campaign, the master storyteller), help
  from the players p. 113, then the child flip.
- R553 LANDED 2026-10-17: commit f1428cb2d47935c465dfd9b
  cb82a1eddff7796 (census 476 -> 477, pushed
  3e9a750..f1428cb), THE DSG STORY ELEMENTS TAIL,
  printed pp. 107-108 - the rest of Story
  Elements ending at the TECHNIQUES OF STORY AND
  CAMPAIGN DESIGN head: the foreshadowing tail
  (the variety principle - corridor after
  corridor of bloody writing loses impact; the
  player-given invitations, the augury casting
  an invitation for clues; dreams effective but
  heavy-handed; the fortune-teller's dire
  warning; the anonymous message; town rumors),
  Mystery (the unknown as a great motivator with
  the answers a major satisfying reward; the
  neglected who-done-it used successfully; the
  secret antagonist with the dropped-clue trail
  - the vampire-lair example with bats and
  wolves, the broken mirror and the pouchful of
  garlic, the fresh corpse with the fang marks;
  the campaign mysteries - unknown parentage,
  the vanished community; the background
  questions with only a general idea needed; the
  dying messenger of Eric of Calrede; the
  speak-with-dead caveat), Challenge (shaped to
  the players' mental and physical interests -
  combat for Adventurers with an occasional
  mental problem, negotiation for Role-Players;
  the player feedback; the encounter's
  game-balance role - random and introductory
  light, climactic and milestone to the utmost
  limits; the Hit Dice and damage rough balance
  against tactics, position, and luck; the
  intelligent-play sufficiency; the changeable
  devastating screen die roll), Reward (the
  accomplishment basis, the tracked count, the
  during-adventure handouts - key clues, small
  treasures, needed equipment), Magical items
  (the one-or-two permanent items per level lid;
  generous with potions and scrolls; the
  class-directed items - leather armor to the
  thief, the mace +3 to the cleric; the
  armed-to-the-teeth campaign killer; the
  described and named swords with crest or
  script; the Sathas Sundown and Black Tower
  sage; the limitations on every permanent item;
  the story-part doctrine), Wealth (the taxes,
  thievery, tolls, and prices as drains; the XP
  for lost wealth kept; the low-value bulks and
  encumbrance; gemstones rare until a few
  levels; the spending sprees with the
  cleaned-out week), Discoveries (information as
  reward; the pieced-together clues the key),
  Gratitude (the high king's debt; the
  case-by-case extent - the paid rescue owing
  nothing; the explicit promises against
  requests; the beggar and barmaid favors;
  selfless motives binding more),
  Accomplishment (the difficult objective as its
  own reward for Role-Players; the good-deed
  cleric; the DM's zero effort; the immediately
  apparent success or failure), Experience
  Points (the adjustable DMG amounts - the
  troll-holding fighter; the landslide village
  earning no XP and even a penalty; the tentative
  design awards - 1,000 XP per burned pirate
  ship, undisclosed until after; the restructured
  system for non-treasure objectives; the
  optional magic-item XP, never for found-and-
  sold items), and Moral (the storyteller's
  meaningful lesson, unnoticed if not
  heavy-handed; the actions-with-consequences
  doctrine; the cooperation example; the killer
  consequences - jail, hanging, the fugitive
  ire; the accomplishment-merits-reward moral;
  the story-for-a-moral with its "It's not wise
  to fool the king" exemplars). 3 consts + 60
  bools, prefix dcf, header rules/dsgcamp4.h,
  spec 33,231 bytes, md5
  c98d9512e5416158760d59a26e9e7464 matched
  exactly first try, 63 inlines; djvu lines
  13752-14246 with the Capture pdf 108-109
  cross-read (clean - the OCR quirks settled by
  the cross-read). A ZERO-FLIP ROUND: gap census
  stays 140/15. An authoring catch in staging:
  the provenance draft leaked Cyrillic OCR
  garbles into the emitted header - rewritten
  pure-ASCII before publish (keep header lines
  ASCII, not just <=78 cols). NEXT - R554: the
  techniques of story and campaign design pp.
  109-112 (the linear adventure, the open
  campaign, the matrix, the DM as master
  storyteller), help from the players p. 113,
  then the pp. 99-113 Campaign Considerations
  child flip (zero pins, the gap report IN the
  git add).
- R554 LANDED 2026-10-17: commit 2d8597471da5e6fa8d9
  9a7e326107ea5a64f247c (census 477 -> 478,
  pushed f1428cb..2d85974), THE DSG TECHNIQUES OF
  STORY AND CAMPAIGN DESIGN, printed pp. 109-112 -
  the story-design doctrine ending at the HELP
  FROM THE PLAYERS head: the chapter head (the
  story line chosen shapes the gaming
  environment; three types of adventure design),
  The Linear Adventure (the certain-order
  encounters; the dungeon one-route maps with the
  predetermined locations; the outdoor thorn-wall
  and impassable-water obstacles; the
  no-wasted-design-time advantage; the difficulty
  as the PCs gain magical power; the tournament
  fit; the railroad frustration - generally
  undesirable for less structured play; the
  directed play with the illusion of choice),
  The Open Campaign (the de-emphasized story with
  the PC choices determining the course; the
  detailed countryside seeded with conflicts; the
  Adventurer fun continuing indefinitely; the
  greater Problem-Solver and Role-Player
  workload - the mental diet, the unique NPCs,
  the national-scope problems, the nomadic NPCs;
  the entire world setting built over time; the
  story-structure difficulty and the perverse
  players; the Events technique - the dragon's
  lair placed in the path with logic; the
  ask-ahead shortcut; the background conflicts -
  the wars with the met principals, the endless
  winter and the man-eating plants), The Matrix
  Campaign (the detailed story with the player
  choice; the motivating goals - the linear-open
  compromise fit for epics; the evil-cleric sect
  exposition opening options; the guided options
  north, east, and south with the western
  headquarters bided; the prepared courses - the
  raid, the sage interview, the prisoner rescue;
  the expanding branches steering toward the
  headquarters climax; the plot events; the soft
  border of the hapless waifs and the stranger's
  gems; the hard border of the cliff, sea,
  desert, the escalating army, the quest and geas
  as the last resort; the several approaches to
  the final encounter - never doomed for a wrong
  choice; the lost players shown the path gently
  but firmly - the henchman speaking up, the
  plain-language sage; the foreshadowed track),
  the Running the Game head (the two at-table
  functions - the story drawn in by the PCs' own
  motivations, the mechanics refereed to move the
  story along), Preparing For Play (the
  random-generation lists - eight NPC names
  rolled on 1d8, the personality traits, the
  appearance characteristics; the coded notes -
  AC, HD, hp, MV, damage, the own maps and
  symbols; the THACO shorthand with the ogre
  example - 15 to hit AC 0, 9 against AC 6, 19
  against AC -4; the map symbols; the anticipated
  surprises; the treasure decisions), and The
  Dungeon Master as Master Storyteller (the role
  most obvious during play; the pace - the
  minutes per melee and the story rate, the
  intensity-rest variety, the discarded slow
  rules, the optional Weapons vs. AC and
  spell-component systems, the preparation, the
  pertinent-rules review; the voice - the tone of
  the tragic ruin and the jolly inn, the volume
  of the unexpected, the varied rate with the
  occasional pause; the colorful word choice -
  the door crashing inward in a blast of
  splinters; the NPC voices from the old men to
  the heroic leaders, augmented by the facial
  expressions and gestures). 3 consts + 54
  bools, prefix dcg, header rules/dsgcamp5.h,
  spec 30,673 bytes, md5
  edc1eafae5becf409320a0893bedcd41 matched
  exactly first try, 57 inlines; djvu lines
  14247-14725 with the Capture pdf 109-113
  cross-read (clean). A ZERO-FLIP ROUND: gap
  census stays 140/15. An authoring catch in
  staging: the first audit label ran 54 cols
  (the R389 class limit) - shortened to "R554 DSG
  story design techniques audit" (keep audit
  labels under the length gate). NEXT - R555:
  help from the players pp. 113-114 (the
  overburdened-DM doctrine, rolling up PCs,
  adventure ideas, class responsibilities,
  controlling henchmen and NPCs), then the pp.
  99-113 Campaign Considerations child flip (zero
  pins, the gap report IN the git add).
- R555 LANDED 2026-10-17: commit ebf6dcbdd52165ccc6a
  ca88ba76cf1319e1e7630 (census 478 -> 479,
  pushed 2d85974..ebf6dcb), THE DSG HELP FROM THE
  PLAYERS, printed p. 113 - the chapter's final
  content round, ending at the MAPPING YOUR
  SETTINGS head: the overburdened-DM doctrine
  (the essential mystery of concealed rolls and
  tracked statistics; the frustrated DM and
  bored players; the tasks by desires, maturity,
  and game type; the more-allowed rule - no DM
  ever bored for lack of things to do; the
  supervision spectrum - tournaments demanding
  more, mature trustworthy PCs taking on
  responsibilities), Rolling Up Player
  Characters (the fun with the cooperative party
  needing little DM involvement; the supervised
  dice rolls and the understood procedure; the
  time gained for setting details; the novices
  briefed and taught by the other players),
  Providing Ideas for Adventures (the think-
  ahead tactic; the category ask between
  adventures - the players suggesting the type,
  the DM the details; the drow kingdom example -
  the long underground expedition, the route to
  the vast realms and wealth, the clues to the
  dungeon entrance and the tortuous maze; the
  advance ask aligning the story; the live
  feedback adjusting to expectations), Character
  Class Responsibilities (the obligations from
  rules or campaign considerations; the cleric's
  treasure donation and the thief's guild dues;
  the player bookkeeping with the DM freed; the
  guildmaster or high cleric investigation made
  an interesting encounter; the spell components -
  the deducted money, the noted gains, the
  adjudicated purchases, the druid's quest for
  greater mistletoe as a short adventure), and
  Controlling Henchmen, Hirelings, and other
  NPCs (the player control unless the NPCs are
  taken advantage of; the takeover technique for
  information and protection; the detailed
  personas - the selfish whiny henchman
  portrayed as such; the tracked locations -
  Olaf of the Black Tooth at the Shaggy Mammoth
  Inn remembered by the players; the player-
  stocked campaign - the assumed blacksmith, the
  probability by community size and
  availability). 24 bools, prefix dch, header
  rules/dsgcamp6.h, spec 19,562 bytes, md5
  97f2392b1a2706da56f0a3ee896e881a matched
  exactly first try, 24 inlines; djvu lines
  14726-14879 with the Capture pdf 113-114
  cross-read (clean - the section sits entirely
  on p. 113, the mapping head opening p. 114).
  A ZERO-FLIP ROUND: gap census stays 140/15.
  No authoring catches. NEXT - R556: the pp.
  99-113 Campaign Considerations child flip (zero
  pins, the gap report IN the git add), then the
  mapping chapter pp. 114-127 (orthographic vs.
  perspective mapping, the grids, symbols and
  map keys).
- R556 LANDED 2026-10-17: commit ec1acf314ebbbdc28a3c
  c2eee7d61ade013a694f (census 479 -> 480, pushed
  ebf6dcb..ec1acf3), THE DSG CAMPAIGN
  CONSIDERATIONS CLOSED - the second FLIP-ONLY
  round of the arc (like R549): zero consts,
  zero bools, zero tables, the census advancing
  by the audit block alone. The pp. 99-113
  Campaign Considerations child flips [x]
  against the six landed rounds: R550 the
  campaign opener pp. 99-100 (rules/dsgcamp.h),
  R551 the worlds of adventure pp. 101-103
  (rules/dsgcamp2.h), R552 the plot and
  counterplot pp. 103-106 (rules/dsgcamp3.h),
  R553 the story elements tail pp. 107-108
  (rules/dsgcamp4.h), R554 the techniques of
  story and campaign design pp. 109-112
  (rules/dsgcamp5.h) and R555 the help from the
  players p. 113 (rules/dsgcamp6.h) - census
  473 -> 479 through the run, each round
  double-run and preflight GREEN. The gap
  census moves 140/15 -> 141/14; the gap
  report WAS in the git add (5 files). Spec
  7,723 bytes, md5
  3980db479aef06079847c605fdbb627d matched
  exactly first try, 0 inlines, header
  rules/dsgcamp7.h, prefix dci. No book text
  pinned; no authoring catches. NEXT - R557:
  the mapping your settings chapter pp. 114-117
  (basic mapping considerations, perspective
  mapping, selecting a grid), then the compiled
  tables and the arc tail.
- R557 LANDED 2026-10-17: commit 3abdb7d50bbf121e72
  fe359da0545ad55735afdc (census 480 -> 481,
  pushed ec1acf3..3abdb7d), THE DSG MAPPING YOUR
  SETTINGS, printed pp. 114-117 - the whole
  mapping chapter in ONE round with the child
  flipped in the same commit (the single-round
  chapter precedent, as R530-R532): the head
  (the orthographic blueprint map with its
  per-level split, the perspective alternative),
  Basic Mapping Considerations (the effective
  map, the tools), Perspective Mapping (the 3-D
  advantages and the occlusion/time costs, the
  photocopy and tracing techniques), Selecting a
  Grid (the shape match, the occluded-area
  design, the front-loaded detail), Selecting a
  Starting Point (the front start, the control
  square), Drawing the Map, Mapping Symbols (the
  translated symbols, the 3-D styles), Splitting
  the Grid (the tracing and photocopy methods,
  the 10-ft-square 20-ft-platform example),
  Horizon Lines (the orientation, the
  perpendicular verticals), Geomorphic Mapping
  (the problem, the shapes - squares, triangles,
  hexagons; the standardized left-right-symmetric
  connections; the 60-ft section at 1-2 per side
  against the square-mile 6-8; the 75% entry
  rule), and Using Geomorphs (the random
  generation, the d3/d4/d6 placement rolls, the
  unnoticed matches and dead-end mismatches, the
  variety hiding revisits). 8 consts + 35
  bools, prefix dcj, header rules/dsgmap.h,
  spec 24,770 bytes, md5
  06ca8c8c0975a49990958655599be5d5 matched
  exactly first try, 43 inlines; djvu lines
  14880-15430 with the Capture pdf 114-118
  cross-read (clean). The Mapping your settings
  child flips [x] IN the same commit: gap census
  141/14 -> 142/13, the gap report in the git
  add (5 files). The pp. 118-120 grid plates are
  graphics and pin nothing. No authoring
  catches. NEXT - R558: the compiled tables p.
  121 (the book's own reprints - much already
  pinned const-for-const by R504/R505, so a
  verify-and-flip round), then the DM-section
  parent and the front-matter chapter p. 6,
  then the arc tail.
- R558 LANDED 2026-10-17: commit 9816ec6ca79c1d5995ee9
  f173c453d30f2e05b20 (census 481 -> 482, pushed
  3abdb7d..9816ec6), THE DSG COMPILED TABLES,
  printed pp. 121-123 - the verification-and-flip
  round: the book's thirty-four-table reprint
  spread, each table verified const-for-const
  against the pins its chapter already landed -
  Tables 1-9 the movement (R504/R505), 15-16 the
  odor, 17-18 the cave-ins, 19 the DPV, 20 the
  unsteady reactions, 21-26 the boats, 27-34 the
  mining - plus the footnotes (the encumbered
  sink, the thieves-only surfaces, the collision
  slash split, the pure-vein reroll). ONE GENUINE
  DELTA pinned: the compiled Table 3 carries five
  grapple rows where the chapter original carried
  two - the stone parapet (01-72/73-78/79-00),
  the stone wall top (01-83/84-89/90-00), and
  the tree branches (01-66/67-70/71-00) rows are
  new pins. Tables 10-14 are not reprinted. 9
  consts + 14 bools, prefix dck, header
  rules/dsgtabs.h, spec 15,083 bytes, md5
  a975c81c3b81f2be0903514d73dcd691 matched
  exactly first try, 23 inlines; djvu lines
  15340-15800 with the Capture pdf 121-123
  cross-read (clean - the garbled djvu table OCR
  settled against the capture and the landed
  chapter pins). The Compiled tables child flips
  [x] IN the same commit: gap census 142/13 ->
  143/12, the gap report in the git add (5
  files). No authoring catches. NEXT - R559: the
  perspective map plates pp. 124-127 (graphics -
  a verify-only flip round), then the index p.
  128 (a roster round), then the DM-section
  parent, the front-matter chapter p. 6, and the
  arc's final census.
- R559 LANDED 2026-10-17: commit 8060e227703c94fea42
  9dd3a8630a7f174b337f5 (census 482 -> 483, pushed
  9816ec6..8060e22), THE DSG PERSPECTIVE MAP
  PLATES CLOSED - the third FLIP-ONLY round of
  the arc (like R549/R556): zero pins, the
  census advancing by the audit block alone.
  The pp. 124-127 plates are graphics - the
  perspective grids, the horizon lines, and the
  printed 3-D symbol sheets serving the R557
  mapping doctrine (rules/dsgmap.h) - and pin
  nothing (the R549 Deepearth map-plate
  precedent applied to the DM-section plates;
  djvu lines 15810-15950 show zero prose cells,
  the index opening clean at printed p. 128).
  The gap census moves 143/12 -> 144/11; the
  gap report WAS in the git add (5 files).
  Spec 5,867 bytes, md5
  185397cb1e3c194ac6bd2e719090a48d matched
  exactly first try, 0 inlines, header
  rules/dsgplate.h, prefix dcl. No authoring
  catches. NEXT - R560: the index p. 128 (a
  roster round against the landing pattern it
  references), then the DM-section parent, the
  front-matter chapter p. 6, and the arc's
  final census.
- R560 LANDED 2026-10-17: commit 601f06b9d5719cb298ef8
  d5c36e8ab80eb2c1a05 (census 483 -> 484, pushed
  8060e22..601f06b), THE DSG INDEX, printed pp.
  127-128 - the roster round closing the book's
  back matter: the alphabetical topic list whose
  every page reference lands on a chapter this
  arc already pinned. 4 consts + 4 bools, prefix
  dcm, header rules/dsgindex.h: the Ability Check
  roster head p. 12, Mapping p. 114 (the R557
  chapter), the story-elements moral p. 109 (the
  R553 tail), the four underdark theories p. 71,
  plus see-cross-reference routing (Illithids/
  Smell), the player types p. 99 (R550), the
  equipment range pp. 56-58, and the back-cover
  blurb past the index. A FLIP round: the Index
  box closes, gap census 144/11 -> 145/10, the
  gap report WAS in the git add (5 files). Spec
  6,964 bytes, md5
  8768deba61764aeed748941f60cd2d2d matched
  exactly first try, 8 inlines; djvu lines
  15866-16247, the roster verified against the
  landed rounds page ranges (no reference outside
  pp. 6-128). No authoring catches. NEXT - R561:
  the DM-section parent box flip (pp. 64-120,
  flip-only against nine closed children, the
  R549/R556/R559 pattern), then the front-matter
  chapter p. 6, then the arc's final census.
- R561 LANDED 2026-10-17: commit 576fc65d2af319de3633
  75a04558172d657e7859 (census 484 -> 485, pushed
  601f06b..576fc65), THE DSG DM SECTION PARENT
  CLOSURE, printed pp. 64-120 - the fourth
  FLIP-ONLY round of the arc (the R549/R556/R559
  pattern): zero pins, the audit block the only
  census movement, the parent box closing against
  its nine already-closed children (the R503 DM
  table of contents, the R530/R531 environment
  chapter with the geography and theories, the
  R532 cultures, the R533-R549 Deepearth lands,
  the R550-R556 campaign chapter, the R557
  mapping). The gap census moves 145/10 -> 146/9;
  the gap report WAS in the git add (5 files).
  Spec 4,484 bytes, md5
  1ec18c627956f1221982d0b596b8c930 matched
  exactly first try, 0 inlines, header
  rules/dsgdmsec.h, prefix dcp. No authoring
  catches. NEXT - R562: the front-matter chapter
  p. 6 (the "what is it?" frame with its five
  sub-items - the mystery, the new rules, the
  denizens, the underground campaign, using this
  information), then the arc's final census.
- R562 LANDED 2026-10-17: commit 3edae896c212cfbf3a1a
  72daa90ba9f0d070e33a (census 485 -> 486, pushed
  5789fe4..3edae89), THE DSG WHAT-IS-IT FRONT
  MATTER, printed p. 6 - the chapter frame in ONE
  round with the parent and all five children
  flipped in the same commit (the R557
  single-round chapter precedent): the mystery
  (the sunless realms, the three lures), the new
  rules (the non-thief climbing, the OA
  proficiencies), the denizens (the four named
  cultures, the generators), the underground
  campaign (the DM half, the 3-D mapping, the
  story conflicts) and the using-this-information
  player/DM split (the Forbidden Territory). 4
  consts + 4 bools, prefix dcq, header
  rules/dsgintro.h. A FLIP round, six flips: gap
  census 146/9 -> 152/3; the gap report WAS in
  the git add (5 files). Spec 9,188 bytes, md5
  cec1797e10bf47169e2f6fbffb8f4171 matched
  exactly first try, 8 inlines; djvu lines
  466-585, each promise cross-checked against
  the chapter that later lands it. THIS ROUND
  LANDED VIA THE NEW rn SCRIPT (the two-argument
  landing ritual, landed at 5789fe4 between
  R561 and R562): ./rn 562 '<msg>' - the first
  live run, output exactly per the handoff
  checklist. One authoring catch in the mirror,
  caught by the record-extraction assert before
  emit: the R561 seed key was initially trimmed
  one char short. NEXT - R563: the arc's FINAL
  CENSUS - the last three open boxes are all
  already-landed big-chapter parents (the
  underground environment pp. 36-55, the new
  equipment pp. 56-58, the improving play pp.
  59-63); a triple-flip closure round (zero
  pins, the R549/R556/R559/R561 pattern) closing
  the DSG gap report to 155/0 and ending the arc
  R503 opened.
- R563 LANDED 2026-10-17: commit 9f636b8fd240e75d1587
  3b078325d722556c0669 (census 486 -> 487, pushed
  3edae89..9f636b8), THE DSG ARC FINAL CENSUS -
  the ARC-CLOSING round: the triple-flip closure
  with zero pins (the R549/R556/R559/R561 pattern
  applied to all three remaining parents at
  once): the underground environment pp. 36-55,
  the new equipment pp. 56-58 and the improving
  play pp. 59-63, all already-landed containers
  flipping against their children. THE GAP
  REPORT CLOSES 155/0 - the whole 128-page
  Dungeoneer's Survival Guide pinned cover to
  index, the arc R503 opened ending here. Spec
  6,403 bytes, md5
  821a635256c0a34dce2b79f5b7b36e17 matched
  exactly first try, 0 inlines, header
  rules/dsgfin.h, prefix dcr; the gap report
  WAS in the git add (5 files). Landed via rn
  (the second live run, flawless). No authoring
  catches. NEXT - R564: the first round AFTER
  the DSG arc - the engine and gap-report
  tooling are round-agnostic, but the next book
  or source must be chosen before any further
  spec is authored.
- R564 LANDED 2026-10-17: commit c4f9c6b8283aa05b3bdc9
  046d096450196f064f4 (census 487 -> 488, pushed
  9f636b8..c4f9c6b), THE MotP ARC OPENER (the
  R503 pattern), the Manual of the Planes
  (1987, Jeff Grubb, 128 pp.), printed pp. 5-10
  - the introduction: the five groupings
  (Prime/Ethereal/inner/Astral/outer), the
  organization pattern, the true/subjective
  time doctrine (Deep Ethereal 10:1, inner 1:2,
  Astral 365000:1), the natives-unaffected
  rule, the Astral spell exemption, the
  combined-spell both-limits rule. 4 consts +
  4 bools, prefix dcs, header rules/motpintro.h
  (MotP prefixes restart at dcs - dcm/dcn/dco/
  dcp were the DSG index/DM-section/arc pins).
  THIS ROUND LANDED A NEW GAP REPORT
  tools/motp_gap_report.md (60 boxes at opener)
  in the same commit as the spec - a FIRST for
  the arc-opener pattern. A FLIP round, five
  flips: gap census 0/60 -> 5/55; the spell-
  summary tables pp. 8-9 are GARBLED OCR,
  flagged in the report, staying open for a
  careful reconstruction round. TWO RITUAL
  CATCHES, both mine: (1) the gap report was
  published POST-FLIP (my mirror md5 was taken
  after the engine ran), so the first user run
  hit the mixed-state abort (the R420 lesson)
  - FIXED IN THE RITUAL: published canvases
  must be PRE-ENGINE state; (2) the two abort/
  restore cycles before the clean run (the
  user's revert snippet from the spec's own
  gap_flips worked first try). Spec 9,544
  bytes, md5 ee10ebe4f1cfb9aa0b84634fa2cf22de,
  8 inlines; gap report md5
  e206be697eeb821b3cccf33aa22b3e9d pre-flip
  state. NEXT - R565: the spell-summary
  reconstruction (pp. 8-9, the garbled OCR -
  column-by-column against the school lists),
  then the Ethereal chapter (pp. 11-21).
- R565 LANDED 2026-10-17: commit 5d0af5f2aaf659fd20db6a
  4e0d947d405d1a756d (census 488 -> 489, pushed
  c4f9c6b..5d0af5f), THE MotP SPELL-SUMMARY
  RECONSTRUCTION, printed pp. 8-9 - the one
  garbled spread of the scan closed on the
  reconstruction the gap report demanded: the
  eight school groups, the C/D/I/M class-code
  legend, the parenthetical pair codes, and 35
  sample entries verified legible in the OCR and
  matching the canonical PHB levels. 3 consts +
  2 bools, prefix dct (THE ENGINE CAUGHT THE
  TAKEN dcs PREFIX - R564 used it; the mirror
  aborted first try and the switch to dct was
  the fix). A FLIP round, one flip: gap census
  5/55 -> 6/54. Spec 7,107 bytes, md5
  8422b07ffd8aca8dedb4adebff1cf3ff matched
  exactly first try, 5 inlines, header
  rules/motpspell.h. NEXT - R566: the Ethereal
  chapter (pp. 11-21) - the proto-matter nature,
  the Border Ethereal, survival, encounters,
  combat, magic, the player characters and the
  demi-planes; expect the R557 single-round
  chapter pattern.
- R566 LANDED 2026-10-17: commit 351cd95557112b025029f
  6ddb22094950e1d284a (census 489 -> 490, pushed
  5d0af5f..351cd95), THE MotP ETHEREAL CHAPTER
  (the R557 one-round chapter pattern) WITH THE
  MANIFEST AMENDMENT riding in the same commit:
  the full-book table scan found 30 named
  tables/charts/frequencies the TOC boxes
  subsumed, the lossless convention demanded
  every one its own line item, the census grew
  60 -> 90 boxes. 13 pins, prefix dcu, header
  rules/motpeth.h: the Border/Deep split, the
  10x subjective time with subjective aging,
  100-yard vision, the 1-round fade (the phase
  spider pattern), the 1-in-10 Deep check,
  zero-base normal weapons + the one-plus magic
  reduction, the +20% thief shadows, no
  falling, the four named demi-planes, and the
  book-wide 2-20 d8+d12 doctrine. TWELVE flips
  in one commit (the parent, all eight section
  children, the two new Ethereal encounter
  items, and the 2-20 doctrine): gap census
  6/84 -> 18/72. TWO LESSONS: (1) the
  whole-file-replace workflow (cat > file) for
  gap-report changes - nano select-all is the
  wrong tool; (2) the pre-engine canvas publish
  held - the user's first run was clean despite
  the amendment, both md5s exact first try.
  Spec 13,638 bytes, md5
  7f9f1ad56b5986de3a46e98beb240dc9; gap report
  pre-flip md5 c41743b0f8a091e02abc05725ca33953.
  NEXT - R567: the inner planes in general
  (pp. 22-31) - the reaching/survival/movement
  doctrine, the native-frequency table with the
  one-rank decay rule, the school-effects
  matrix; then Air, Fire, Earth, Water in
  sequence.
- R567 LANDED 2026-10-17: commit cd2cf1bc3ddb9c3dc2d0
  7f9eeafee7345583d558 (census 490 -> 491,
  pushed 351cd95..cd2cf1b), THE MotP INNER
  PLANES IN GENERAL, printed pp. 22-31 - the
  doctrine round for the inner half: the
  18-plane sphere (6 major, 12 minor), the
  inborn hostility, the natives-see-the-Border
  rule, the 2d4 breathless rule, the 1:2
  subjective-time reversal (time FASTER here,
  the Ethereal's mirror), the local-gravity
  doctrine with the 1000-ft/round falls, the
  guide system with the 100-gp/hour
  inducements, the lone-human-20th-level rule,
  ultravision failing, the unguided
  random-direction rule, and the elemental
  home-immunity. 7 consts + 7 bools, prefix
  dcv, header rules/motpinner.h. THREE flips:
  gap census 18/72 -> 21/69. Authoring catch
  (mine, caught by the engine in the mirror):
  a const value as string ('4') - the engine
  wants ints; fixed to the die-side pin.
  Spec 12,369 bytes, md5
  1b39f2420aa3cd914ecfc76fee05f679 matched
  exactly first try, 14 inlines. NEXT - R568:
  the Plane of Elemental Air (pp. 31-36) -
  survival, the phenomena table, the
  high-winds table, the elemental pockets,
  encounters, combat, magic, features; then
  Fire, Earth, Water.
- R568 LANDED 2026-10-17: commit 2e16f6456e8558430cf7
  492e07b60f4194f3f59 (census 491 -> 492, pushed
  cd2cf1b..2e16f64), THE MotP PLANE OF
  ELEMENTAL AIR, printed pp. 31-36 - the whole
  plane chapter in one round: the hospitable
  doctrine with the four border gradations
  (Smoke, Ice, Lightning, Vacuum), the
  1000-yard sighting, the 1-in-20-per-12-hours
  check (phenomena/pocket/creature split), the
  d12 phenomena table (the maelstrom 2000-ft/
  turn escape, the 1-in-50 vortex), the
  WSG-adapted high-winds table (the 80-mph
  verbal cutoff, the 1d8-per-10-mph impact
  damage - the cross-book seam honored, MotP
  pins carry MotP text), the d20 pocket table
  (16 pocket types), the d8+d12 encounter
  chart, the invisible natives, the djinn
  landholds, and the features (Yan-C-Bin,
  Akadi, Bahamut's citadel, hooks and
  bubbles). 8 consts + 4 bools, prefix dcw,
  header rules/motpair.h. FOUR flips: gap
  census 21/69 -> 25/65. Spec 11,054 bytes,
  md5 d005297a5d545a7ca4e8a772330183d7
  matched exactly first try, 12 inlines. NEXT -
  R569: the Plane of Elemental Fire (pp.
  36-41) - the City of Brass, the efreet, the
  phenomena, the pockets, the survival; then
  Earth and Water.
- R569 LANDED 2026-10-17: commit 2c45a96a7e2d488b46c8
  0bd1d47305451643978d (census 492 -> 493,
  pushed 2e16f64..2c45a96), THE MotP PLANE OF
  ELEMENTAL FIRE, printed pp. 36-41 - the whole
  plane chapter in one round: the hellish
  doctrine with the four border gradations
  (Smoke, Magma, Radiance, Ash), the survival
  ladder (breath-save-or-die with 4d10/round
  survivors, melting metal, boiling fluids,
  the thin hot atmosphere), 120-foot vision,
  the 1-in-10-per-eight-hours check, the d12
  phenomena (hot spots with native healing,
  cold spots, the 2000-yard eruption, the
  explosion field), the d20 pocket table (the
  purest plane), the d8+d12 encounter chart
  (Imix on 2, efreeti on 11, salamanders on
  13), the native cold/water vulnerabilities
  (the 100-degree threshold, 1d6 per quart),
  the magic rule, and the features (Imix,
  Kossuth, the 40-mile City of Brass, the
  azer towers of Amaimon, the spiraling-flame
  artifact). 8 consts + 5 bools, prefix dcx,
  header rules/motpfire.h. THREE flips: gap
  census 25/65 -> 28/62. Spec 11,621 bytes,
  md5 eb56ba89eb9c9a1a7f95c79d29409846
  matched exactly first try, 13 inlines. NEXT -
  R570: the Plane of Elemental Earth (pp.
  41-46) - survival (breathing, the weight),
  movement through stone, the encounter
  context, the pockets, magic, the features;
  then Water closes the four majors.
- R570 LANDED 2026-10-17: commit 8fdfa5f51c0ef08ef0520
  29b1556db4ed4f51f6d (census 493 -> 494,
  pushed 2c45a96..8fdfa5f), THE MotP PLANE OF
  ELEMENTAL EARTH, printed pp. 41-46 - the
  whole plane chapter in one round: the
  least-hospitable doctrine (the solid wall -
  air, water and fire part but earth does
  not), the four border gradations, the
  1d2-per-turn pressure, blind but 6-inch
  hearing, the Strength 15/18/19/23
  brute-force ladder at one foot per turn,
  the 1-in-10-per-four-hours check, the d12
  phenomena (the d10 quake tiers 4d6/6d6/
  8d6, the fault lines, the 60/40 gas
  pockets, the fossils), the d20 pockets
  with the 80% air pockets, the native
  passwall and AC-2-mimic rules, the magic
  range rule, and the features (Ogremoch,
  Grumbar, the dao and the Great Dismal
  Delve, the silver doorways). 8 consts + 6
  bools, prefix dcy, header rules/
  motpearth.h. ONE flip: gap census 28/62
  -> 29/61. AUTHORING CATCH (mine, caught by
  the mirror's missing-key assert): keyed a
  flip to an 'Earth encounter context' item
  that does not exist in the manifest - the
  R566 amendment never created it; corrected
  to the single real box. Spec 11,594 bytes,
  md5 f5e952f1bf5eca11b6e96a8362f85fea
  matched exactly first try, 14 inlines.
  NEXT - R571: the Plane of Elemental Water
  (pp. 46-51), the last of the four majors;
  then the para-planes, the energy planes
  and the two quasi-groups.
- R571 LANDED 2026-10-17: commit 289841a4445263bba656
  318cf0dcd518f428f5e8 (census 494 -> 495,
  pushed 8fdfa5f..289841a), THE MotP PLANE OF
  ELEMENTAL WATER, printed pp. 46-51 - the
  whole plane chapter in one round, CLOSING
  THE FOUR MAJORS: the ocean-without-a-
  surface doctrine with the four border
  gradations (Ooze, Ice, Steam, Salt), the
  1/3-Con breath rule, 60-foot vision, the
  doubled swim rate, the 1-in-10-per-four-
  hours check, the d12 phenomena, the d20
  pocket table (fire/magma only in airy
  water), the d8+d12 chart (Charonadaemon 2,
  marids 10, tritons 11, eye of the deep
  20), the native fire double-damage
  vulnerability, the underwater combat
  rules, the magic rule, and the features
  (Istishia, the marid empire). 7 consts +
  6 bools, prefix dcz, header rules/
  motpwater.h. THREE flips: gap census
  29/61 -> 32/58. Spec 11,243 bytes, md5
  36abaaab578c0bcb4eb13bdf8430950a matched
  exactly first try, 13 inlines. NEXT -
  R572: the Para-Elemental Planes (pp.
  51-54) - Smoke, Magma, Ooze, Ice in one
  round; then the energy planes and the two
  quasi-groups close the inner half.
- R572 LANDED 2026-10-17: commit 1f15d1b4c70e50d2631
  445691bea4cbd791900d (census 495 -> 496,
  pushed 289841a..1f15d1b), THE MotP PARA-
  ELEMENTAL PLANES, printed pp. 51-54 - the
  four planes (Smoke, Magma, Ooze, Ice) in one
  round: the minor-plane doctrine, the
  per-plane survival (asphyxiation,
  heat-as-Fire, drowning-as-Water, the
  1d6-per-round ice cold reduced to per turn
  when protected), the vision ladder (30
  yards / touch / 10-20), the 1-in-20-per-
  eight-TRUE-hours check, the 50/50 pocket
  rule, the native immunity doctrine, the
  movement/combat/magic mappings onto the
  majors, the d8+d12 chart, and the features
  (the guide-bribe doubling, the archoments
  as Demi-Powers with no Greater Powers -
  Cryonax, Ehkahk, Chlimbia, Bwimb). 7
  consts + 6 bools, prefix dda, header rules/
  motppara.h. TWO flips: gap census 32/58
  -> 34/56. Spec 10,925 bytes, md5
  0592048d0b0c0d90f3b0756eb640b504 matched
  exactly first try, 13 inlines. NEXT - R573:
  the Energy Planes (p. 54) - Positive and
  Negative in one round (the 2d6 gain-and-
  explode, the 2d6-plus-level drain, the
  protection-spell paradox, the weakened
  Border Ethereal, no random encounters);
  then the two quasi-groups close the inner
  half.
- R573 LANDED 2026-10-17: commit 38d8c24e959770d154e9
  20c5a0cdafb717bb3a23 (census 496 -> 497,
  pushed 1f15d1b..38d8c24), THE MotP ENERGY
  PLANES, printed p. 54 - Positive and
  Negative in one round: the Plane-of-Life/
  Plane-of-Death doctrine, the 2d6-per-round
  gain exploding at twice the original total
  (extra points fading in 1d20 true turns),
  the 2d6-plus-one-level drain, the
  protection-spell paradox (the protections
  cannot be cast IN the planes), the
  no-breathing-energy rule, the 10-yard
  vision, the 10%-per-turn weakened Border
  Ethereal, the no-random-encounters
  doctrine, the magic max/min rule, and the
  features (the xeg-ya/xeg-yi with their
  2d6-8 guide roll, the trilloch, the undead
  Negative link). 5 consts + 6 bools, prefix
  ddb, header rules/motpenergy.h. TWO flips:
  gap census 34/56 -> 36/54. Spec 9,917
  bytes, md5 a7730e54aefc3f80de43b43a172c62e3
  matched exactly first try, 11 inlines. NOTE
  (user observation at R573, GENERAL - the
  whole splice ritual, not just the MotP
  arc): the ritual is going faster now. NEXT - R574: the
  Positive Quasi-Planes (pp.
  55-57) - Lightning, Radiance, Minerals,
  Steam in one round, including the Minerals
  petrification rule (the 80/20 split, the
  99% crumble); then the negative quasi-group
  closes the inner half.
- R574 LANDED 2026-10-17: commit 59139ceb2e2d7248c982
  d46b9e8016130cebd1dc (census 497 -> 498,
  pushed 38d8c24..59139ce), THE MotP POSITIVE
  QUASI-PLANES, printed pp. 55-57, the four in
  one round: Lightning, Radiance, Minerals and
  Steam - the agitated-matter doctrine with the
  tidal Positive borders, the per-plane
  survival (the 5/10/20% per-round strikes at
  1d8-of-d10s, the thunder deafness with the
  wax-plug fix, the Radiance blind save, the
  1d4-plus-AC Minerals movement damage, the
  muggy Steam slow), the 1-in-10 encounter
  check, the wall of brilliance at 3d6 per
  round, the pocket conversion, the native
  immunities, the doubled guide prices, the
  tower ring, the gem economy with the 1-in-100
  survival, and the fossilization (the 80/20
  split, the 99% crumble). 9 consts + 5 bools,
  prefix ddc, header rules/motpquasipos.h.
  THREE flips: gap census 36/54 -> 39/51. Spec
  12,801 bytes, md5 c43582f4e09062cc7a28d72877b
  6eb02 matched exactly first try, 14 inlines.
  NEXT - R575: the Negative Quasi-Planes (pp.
  57-59) - Vacuum, Ash, Dust, Salt in one
  round, the increasing-absence doctrine; the
  inner half closes, then the Astral chapter.
- R575 LANDED 2026-10-17: commit 4d9beb2736621e2b4c01902
  d943441dca69eca51 (census 498 -> 499,
  pushed 59139ce..4d9beb2), THE MotP NEGATIVE
  QUASI-PLANES, printed pp. 57-59, the four in
  one round: Vacuum, Ash, Dust and Salt - the
  increasing-absence doctrine, the per-plane
  survival (the Vacuum hold-breath-only rule,
  the 1-HD-per-round elemental loss, the
  1,000-yard doubled infravision, the Ash
  warmth depletion, the Dust crumbling, the
  Salt per-TURN elemental drain), the black
  wall at 3d6 per round, the 1-in-10
  life-level drain touch, the native rules,
  the magic decay, and the doubled guide
  prices; the Foreword doctrines (p. 3) rode
  as the third flip. ONE AMENDMENT: the
  encounter frequency corrected against the
  source - 1 in 10 per 12 hours, not the
  report's 1-in-20. 9 consts + 7 bools,
  prefix ddd, header rules/motpquasineg.h.
  THREE flips: gap census 39/51 -> 42/48 -
  THE INNER HALF IS CLOSED. Spec 13,798
  bytes, md5 17dcea0954b0b6edf591dfdbc0164033
  matched exactly first try, 16 inlines.
  LESSON (handoff discipline, same-day
  reaffirmation): the R575 handoff drifted
  and showed ./bn and a pre-run preamble;
  the delivered ritual block is ONE line
  only - ./rn NNN '<msg>' - pinned above at
  the R516/R541 rule. TEN straight
  first-tries (R566-R575). NEXT - R576: the
  Astral Plane chapter (pp. 60-72), the
  R557 one-round chapter pattern - reaching
  and the silver cords, the color pools,
  the no-gravity thought-movement, the
  encounter charts, combat, magic, and the
  features (githyanki, the dead gods).
- R576 LANDED 2026-10-17: commit 0c3bb0391fa4f4725a9088
  ca02d99f43e81422a7 (census 499 -> 500,
  pushed 4d9beb2..0c3bb03), THE ASTRAL PLANE,
  printed pp. 60-72, the whole chapter in one
  round (the R557 pattern), opening the second
  half of the book: the barren-vault doctrine
  (the transit plane, the wormholes, Anubis
  the sole resident Power), the reaching split
  (projection with the silver cords vs.
  physical travel), the cord rules (the
  1d10-turn dissolution clock, the 1d4+1-day
  coma, the 1% possession, the three severing
  forces), the color pools (the blind side,
  the d20 color table, the viewing altitude
  and percentile location, the 15% two-way and
  5% fixed portals), the survival (no breath,
  no food, the 365,000-to-1 time, the potion
  permanence, the dead infravision), the
  10-yards-per-minute-per-Int mental movement,
  the 1d10-every-four-hours check with the
  75/10/10/5 type split, the psychic wind
  1d20 table, the weightless combat (the AC 8
  astral base, the Int/Wis modifier swap), the
  magic school limits (the conjuration caps at
  4th/3rd/5th, the sphere areas, the
  extradimensional void, the Bigby-hand Int
  contests, the astral-searcher chance at 5x
  level), the PC adjustments (the thief noise
  split, the monk AC 7), and the features (the
  githyanki silver swords at AC 0 and 20%, the
  lich-queen, the fixed portals, Yggdrasil and
  Mount Olympus). 15 consts + 12 bools,
  prefix dde, header rules/astralplane.h.
  ELEVEN flips (the chapter parent + eight
  children + the encounter check + the sample
  charts): gap census 42/48 -> 53/37. Spec
  26,058 bytes, md5 59c8c5107530fda34335da98
  322d5ce matched exactly first try, 27
  inlines. NOTE (engine write-order lesson,
  caught locally pre-ritual): the first run
  aborted writing rules/astralplane.h into a
  missing rules/ dir AFTER the seed patch was
  staged - restored seed and report from the
  R575 sha and re-ran clean; the staging step
  should mkdir rules first (or fetch one
  header file) on fresh environments. ELEVEN
  straight first-tries (R566-R576). NEXT -
  R577: the outer planes in general (the
  final arc opens) - the group doctrine, the
  alignment-based structure, the paths
  between planes, then plane-by-plane.
- R577 LANDED 2026-10-17: commit 0cbff953202c7fc848eee
  45dfd21c8858f904f12 (census 500 -> 501,
  pushed 0c3bb03..0cbff95), THE OUTER PLANES
  IN GENERAL, printed pp. 73-84, the
  general-doctrine round opening the final
  arc: the Great Wheel (16 pieces plus the
  17th plane, the Upper/Lower/Law/Chaos
  groupings, the layer-count table with the
  Abyss' 666), the reaching (all travel
  through the Astral - the conduits, the
  plane shift with the arrival table, the
  gate rules, the color pools with new-body
  formation and the harmless cord snap), the
  survival (the like-the-Primes-only-more-so
  doctrine, the localized gravity, the
  per-realm directions, the two compasses),
  the movement (the realm borders, the
  Wisdom-check interlayer barriers at 70%
  one-way, the portal rules at 1-in-6 and
  50/50), the encounters (the unique-Powers
  2-or-20 rule, the human travelers, the
  native-body doctrine), the magic school by
  school (the home-court abjurations, the
  cantrip pop, the Chaos-plane alteration
  ladder at 20/40/60/80, the divination
  alignment-overwhelm, the true-sight
  freezes, the vacant-body rule at 1% per
  layer, the item-plus decay), the PC
  adjustments (the paladin lay-on-hands
  exception, the barbarian comfort), and the
  features (the spell-crystals, the river Styx
  with the 15th-level forget save, the 50%
  dragging, the Charon 1d100-turn transit,
  and the wholesome Oceanus). 13 consts + 10
  bools, prefix ddf, header rules/
  outerplanes.h. SIX flips: gap census
  53/37 -> 59/31. Spec 22,513 bytes, md5
  57f7a97ce714275a99f996f51924d2b4 matched
  exactly first try, 23 inlines. NOTE (the
  census_before class, caught locally
  pre-ritual): the first authoring set
  census_before 499 but the R576 tree
  carries 500 - the engine aborted and
  partially wrote (the R420/R576 write-order
  class); restored from the sha, fixed to
  500, re-ran clean. TWELVE straight
  first-tries (R566-R577). NEXT - R578: the
  named planes begin - Nirvana (pp. 84-86),
  the clockwork plane, then plane by plane
  through the seventeen.
- R578 LANDED 2026-10-17: commit 8dffd144ad8c2edc189562
  edec6a51977a3f3539 (census 501 -> 502,
  pushed 0cbff95..8dffd14), NIRVANA AND
  ARCADIA, printed pp. 84-87, the first two
  named planes in one round (the R572
  multi-plane pattern): Nirvana the clockwork
  plane of ultimate Law (the 500-mile
  interlocking disks, the per-disk gravity
  with the walk-over-the-edge rule, the
  1/100-turn realm pull, the 20-day portal
  cycle, the always-open Concordant
  Opposition portal, the no-illusion rule,
  Primus and the modrons, Anu's Way, and the
  pantheons - Anu, Shang-Ti with the peaches
  and the library of lost knowledge,
  Shan-Hai Ching, Varuna, Rudra, Yama,
  Horus, Utu and Enki); and Arcadia the
  orchard plane (the half-radiant half-black
  day sphere with its dawnless day, the
  three layers, the metallic trees with
  double-strength potion fruit, the
  illusion-piercing watch beasts, the
  ivory/steel archway portals with the
  1-in-10 mist and 90/10 sides, the
  spirit-folk militias, and the Powers -
  Marduk and Clanggedin Silverbeard). 6
  consts + 8 bools, prefix ddg, header
  rules/nirvanaarcadia.h. TWO flips: gap
  census 59/31 -> 61/29. Spec 14,927 bytes,
  md5 432a571b019f6cb763e1cdf5b60bb1fc
  matched exactly first try, 14 inlines -
  the first CLEAN local run (the pre-staged
  rules/ dir from the R576 lesson held).
  THIRTEEN straight first-tries (R566-R578).
  NOTE (delivery, user-set 2026-10-17): the
  post-land paste is now SHORT - just the
  commit sha and the LANDED line; full
  output only for failed runs. NEXT - R579:
  the Seven Heavens (pp. 87-89, the seven
  ascending layers, Lunia to Chronias, the
  archons, Yondalla and Moradin) - the
  Upper Planes continue.
- R579 LANDED 2026-10-17: commit de89310391bc82540ed02
  6b754ca0684d5ab3345 (census 502 -> 503,
  pushed 8dffd14..de89310), THE SEVEN HEAVENS
  AND THE TWIN PARADISES, printed pp. 87-90,
  the next two Upper Planes in one round: the
  Seven Heavens (the seven ascending layers
  with the barrier-at-the-peak illusion,
  Lunia's holy-water surf, Mercuria and
  Bahamut's court, Venya and the Green
  Fields, Solania and Moradin's Soul Forge,
  Mertion's citadels, Jovar's ziggurat
  council rumor, Chronias the Illuminated;
  the five-type archon ladder - Lanterns,
  Hounds, Wardens, Swords, Tomes; the
  granite-color portals; and the Powers -
  Yondalla, Brandobaris, Moradin and
  Berronar, the four-layer Bahamut palace,
  Chung Kuel, Kuan Yin, Vishnu and Surya,
  Ebisu, Girru, the home-plane-benefits-
  anywhere rule); and the Twin Paradises (the
  book with no spine - Dothion and Shurrock
  20 miles apart, upside down to each other,
  the midair Wisdom-check barrier, the cavern
  portal patterns, no additional
  restrictions, and the Powers - the gnomish
  pantheon with Whisperleaf, Ukko's
  blizzards, the wandering titan
  Epinetheus). 4 consts + 7 bools, prefix
  ddh, header rules/heavenstwins.h. TWO
  flips: gap census 61/29 -> 63/27. Spec
  13,772 bytes, md5 2d41b06c644350cd6b43f89c
  66c7f9f7 matched exactly first try, 11
  inlines. FOURTEEN straight first-tries
  (R566-R579). NEXT - R580: Elysium (pp.
  90-91, the four Oceanus layers Amoria,
  Eronia, Bellerin and Thalesis, the phoenix
  and the moon dogs) - the OCR already
  gathered; then the Happy Hunting Grounds
  and Olympus close the Upper Planes.
- R580 LANDED 2026-10-17: commit e2bceb93942a849a579
  60eaff95f441d0ac352f6 (census 503 -> 504,
  pushed de89310..e2bceb9), ELYSIUM AND THE
  HAPPY HUNTING GROUNDS, printed pp. 90-92,
  the next two Upper Planes in one round:
  Elysium (the four Oceanus layers - Amoria,
  Eronia, Bellerin, Thalasia with the Isles
  of the Blessed; the 1d10-day river
  transits; the MOVING realms - Isis with
  the moon-dog patrols, Seker's flying Ro
  Stau, Ishtar's half-mile fighting statue,
  Nanna-Sin's crescent moon-barque; the
  phoenix and the moon dogs) and the
  Beastlands (Krigala's zenith sun, Brux's
  two setting suns, Karasuthra's wandering
  unmoored stars, the hollow-tree portals,
  the sentient spell-casting beasts with the
  d100 ladder, the doubled hit dice and the
  5%-plus-5% magic resistance, the mortals,
  the Beast Lords, Skerrit the Forester).
  ONE AMENDMENT (the R575 class): the
  spell-casting-creatures table the report
  filed under Olympus is the Beastlands
  beasts table of printed p. 92. 5 consts +
  7 bools, prefix ddi, header rules/
  elysiumbeasts.h. THREE flips: gap census
  63/27 -> 66/24. Spec 15,168 bytes, md5
  3de1b2f8f7dfe2841fdcf2bb831abfc5 matched
  exactly first try, 14 inlines. FIFTEEN
  straight first-tries (R566-R580). NEXT -
  R581: Olympus (pp. 92-94, the Greek and
  elvish pantheons, the three layers -
  Olympus/Arvandor, Ossa/Aquallor,
  Pallon/Mithardir, the creature
  modifications, Zeus's marble citadel) -
  OCR already gathered; Gladsheim follows to
  close the Upper Planes.
- R581 LANDED 2026-10-17: commit f8974bd35e8a378224b37
  d7bb32b375ccea94ef2 (census 504 -> 505,
  pushed e2bceb9..f8974bd), OLYMPUS AND
  GLADSHEIM, printed pp. 92-97, the last two
  Upper Planes in one round - THE UPPER
  PLANES ARE CLOSED: Olympus (the three
  layers, the crimson-disk portals, the
  creature modifications - size up, AC 2
  better, claws +2, doubled hit dice, the
  1-in-20 casters; the Greek pantheon from
  Zeus's citadel, twice a common front; the
  elvish Seldarine - Corellon, Evergold
  shared with Aphrodite, the Leaflord, the
  Chosen, Nephthys's lone desert) and
  Gladsheim (the earthberg rivers with their
  radiant undersides, Asgard/Muspelheim/
  Nidavellir, the wells at 80%, the 10-yard
  magic-stripping Bifrost, the 100-day
  unclimbed Yggdrasil, the necromantic
  cowardice ban in Asgard and Vanaheim, the
  giant casters at 1-in-4/1-in-10/1-in-20,
  and the full Asgard realm census). 5
  consts + 7 bools, prefix ddj, header
  rules/olympusgladsheim.h. TWO flips: gap
  census 66/24 -> 68/22. Spec 15,347 bytes,
  md5 891c83e48d7256cdaedcb5c92ea1fabd
  matched exactly first try, 12 inlines.
  SIXTEEN straight first-tries (R566-R581).
  NEXT - R582: the Chaos side opens - Limbo
  (pp. 97-99, the five layers, the random
  entry table, the githzerai and the slaadi)
  and likely Pandemonium (pp. 99-101) as the
  pair.
- R582 LANDED 2026-10-17: commit 5fd1663c4d8b49850745
  5fca0542004384624fa0 (census 505 -> 506,
  pushed f8974bd..5fd1663), LIMBO AND
  PANDEMONIUM, printed pp. 97-101, the first
  two Chaos planes in one round: Limbo
  (chaos supreme - the random-entry d100,
  the Intelligence safe-zone ladder at 10
  feet/10 yards/100 yards/1 mile per point,
  the concentration rule, the 1d10-hour
  semi-permanent matter, the five
  weakly-barriered layers, the 33% three-way
  portals, the slaadi with Ssendam and
  Ygort, the githzerai with the Citadel of
  Gith and the 16/23 wizard-king Zaarith,
  the 6d6 chaos elementals, and the
  floating realms - Indra's Swarga, Agni's
  flame, Susanowo's sea, Huan-Ti's
  unconsuming palace with the 3d6-per-gallon
  steam) and Pandemonium (the howling
  tunnels - the four layers Pandeemos,
  Cocytus with its 10d10-turn insanity,
  the light-halved Phlegethon, bubble-deep
  Agathion with the 50/50 stale-or-vacuum
  prisons; the 10-foot noise rule, the
  100-lb wind lifts, the 20% misrouting
  square portals, and the Powers - Loki's
  Hidden Realm with its Jotenheim
  shortcut, Tuonela and the desire-draining
  Manala, retired Anshar, Hruggek's
  bugbears). 6 consts + 9 bools, prefix ddk,
  header rules/limbopandemonium.h. THREE
  flips: gap census 68/22 -> 71/19. Spec
  17,325 bytes, md5 1262c19cf6d7e6870f3f7
  bcc6cede55a matched exactly first try, 15
  inlines. SEVENTEEN straight first-tries
  (R566-R582). NEXT - R583: the Abyss (pp.
  101-103, Pazunia the Plains of Infinite
  Portals, the terrain d100 table - rows
  already gathered through the Delusion
  layer, the iron fortresses and the
  sieges, the demon princes).
- R583 LANDED 2026-10-17: commit
  833b09329fb7f7459c6bcf5bf5f33f3a6c
  03d571 (census 506 -> 507, pushed
  5fd1663..833b093), THE ABYSS, printed
  pp. 101-103, the 666-layered well of
  chaotic evil: Pazunia the Plains of
  Infinite Portals (the conduit holes,
  the siege-worn iron fortresses with
  their fight-to-the-death guards, the
  reverse Styx waterfalls, no barriers on
  the first layer), the ten-band terrain
  d100 (desert/glacier/spatial/maelstrom/
  rocky/underground/water/normal at 10
  points apiece, the delusion layer, the
  realm band, the 96-00 evil-incarnate
  tail with the bodak transformation), the
  demon-race census (bodaks uncommon,
  shadow demons and hordings rare, the
  MM2 page-35 additions), the eleven
  rumored dwellings of the demon princes
  (Orcus's bone palace, Demogorgon's
  dinosaur jungles, Yeenoghu's rolling
  mansion, Juiblex's rot, Lolth's web,
  Baphomet's maze, Fraz-Urb'Luu's
  deception, Graz'zt's palace-layer,
  Kostchtchie's glacier, Pazuzu the
  well-liked ceded the air, Zuggtmoy's
  fungus) with the Lesser-Powers
  dead-if-slain rule, the servant bonuses
  (AC 1 better, +2 to hit below low
  Intelligence, 10% evil-cleric casting at
  level 1d10), and the Powers (Vaprak's
  trolls, Laogzed's troglodytes, Urdlen's
  hate-carved tunnels, Tou Mu and Lu
  Yueh's Feng-Tu up the How Nai-ho fork
  of the Styx through the Kuei-Men-Kuan,
  Kali's blood-red layer). 7 consts + 6
  bools, prefix ddl, header rules/abyss.h.
  TWO flips: gap census 71/19 -> 73/17
  (the Abyss box and the Abyssal-layers
  terrain table). Spec 19,586 bytes, md5
  545d2f9db7d638c0f2254d29516b22a6
  matched exactly first try, 13 inlines.
  EIGHTEEN straight first-tries
  (R566-R583). NEXT - R584: Tarterus
  (pp. 103-105, the six crimson-pearl
  layers Othrys/Cathrys/Minethys/Colothys/
  Porphatys/Agathys with the layer
  spacings and hazards; page-104 already
  read, page-105.md to read for the
  Tarterus features and the exiled titans).
- R584 LANDED 2026-10-17: commit
  402ab098f0302359e71347907da4f535
  c3e8599f (census 507 -> 508, pushed
  833b093..402ab09), TARTERUS, printed
  pp. 103-105, the six crimson-pearl
  layers between Hades and the Abyss: the
  world-sized glowing orbs with their
  flyable air-gulfs and unspinning
  weather, the six layers with their
  gaps and hazards (Othrys at 100 miles
  with the marsh and the Styx rivers,
  Cathrys at 500 with the 1d10-round
  metal-eating acid, Minethys at 5,000
  with the cloudkill deserts and the
  every-10-days tornado, Colothys at
  half a million with the spiked peaks
  and hell-chasms, Porphatys millions
  apart with the 1d4-per-round acidic
  black snow and the 1d6 feet of water,
  coldest Agathys alone in the pitch
  black), the nested-sphere barriers
  (the fifth-to-sixth underwater,
  anything beyond the sixth beneath
  miles of ice), the obelisk portals
  read by shape (tall to Hades, wide to
  the Abyss, square to Concordant
  Opposition), the demodands - the
  ruling shators with kelubar and
  farastu above the demon-daemon
  insurgency, the shator-made
  vargouilles that ate their master -
  the trapped titans of Kronos on the
  twin 50-mile peaks of Mount Othrys
  with the shattered road of Olympus
  and the wait-and-plan siege mindset,
  and the exile Powers (Surma's open
  graves of walking undead, Kiputyto's
  winds of gout ulcers and plague,
  Grolantor and his feared giant-spirit
  armies). 6 consts + 6 bools, prefix
  ddm, header rules/tarterus.h. ONE
  flip: gap census 73/17 -> 74/16. Spec
  16,076 bytes, md5
  2fd82abe1e6a7758bf0164e177cc219e
  matched exactly first try, 12 inlines.
  NINETEEN straight first-tries
  (R566-R584). NEXT - R585: Hades
  (pp. 105-107, the three grey Glooms
  Oinos/Niflheim/Pluton with the color
  fade and the two-week larva trap, the
  Styx midpoint and the Olympus and
  Yggdrasil roots, the copper-silver-
  gold coin portals; page-106 already
  read, page-107.md still to read for
  the Hades features and the Powers).
- R585 LANDED 2026-10-17: commit
  9973bab85253b1fd2b4f7c72c582e5b1a72
  2cd2d (census 508 -> 509, pushed
  402ab09..9973bab), HADES, printed
  pp. 105-107, the three grey Glooms of
  the evil-between: Oinos the diseased
  first layer (the 10% major disease for
  walkers and Styx-sailors, Anthraxus the
  Oinodaemon), Niflheim the mist-bound
  second at 100 feet (the Yggdrasil, Hel),
  Pluton the grove of Persephone (Olympus
  base, black willows and the single
  white laurel), the color-fade (muted at
  one week, grey at two) and the
  two-week larva trap (save vs. spell or
  fade over a month, rescuable by a pull
  or a wish), the spinning-coin portals
  (copper to Gehenna, silver to Concordant
  Opposition, gold to Tarterus, the
  arcanadaemon iron around them), the
  barriers (to the Yggdrasil roots before
  Hel's feast hall, to Persephone and
  Cerberus), the Khin-Oin (the 20-mile
  Wasting Tower, never stormed, the
  daemon masters unbeatable when united),
  the jailers-turned-prisoners doctrine
  (Law's guardians gone grey, only
  greater gods free to wander), the night
  hags and the larvae medium of exchange,
  and the Powers (Hades's bronze-dented
  gates and the wish-reviving Cerberus,
  Hel's grey einherjar, Nidhogg gnawing
  the World Ash with the brood reborn
  within the year, Nergal's seven-domed
  Nergaltos with the cumulative -2 gate
  saves at -14 by the seventh dome strong
  enough to trap Ishtar, the Indian
  demigoddess of night and thieves,
  Abbathor's Glitterhell with its rumored
  Niflheim barrier, and silent Yurtrus of
  the orcs). 6 consts + 6 bools, prefix
  ddn, header rules/hades.h. ONE flip:
  gap census 74/16 -> 75/15. Spec 16,397
  bytes, md5 f9072114d726c48bf15e36150
  d802e1e matched exactly first try, 12
  inlines. TWENTY straight first-tries
  (R566-R585). NEXT - R586: Gehenna
  (pp. 107-109, the fourfold furnaces -
  Khalas the temperate top with the hidden
  Nine Hells devils, the 45-degree
  gravity, the heat damage, page-108
  already read; page-109.md still to read
  for the deeper layers and the Powers).
- R586 LANDED 2026-10-17: commit
  15ae1569315c0fa96926a5bf1d9b24433
  9dea334 (census 509 -> 510, pushed
  9973bab..15ae156), GEHENNA, printed
  pp. 107-109, the fourfold furnaces of
  the lawful-evil slope: the baseless
  peakless mountains at 45 degrees with
  the tumbling rule, the ground-heat at
  1d8 per turn negated by elemental-Fire
  means, the four layers (Khalas the
  temperate top with the steam waterfalls
  and the Styx cascades and the hidden
  Hells devils, Chamada's lava cascades
  and the blinding acrid cloud within 10
  miles of the surface, Mungoth's ash and
  burning snow with the wet-snow-and-
  burning-rock avalanches, Krangath the
  dead furnaces dark and heatless), the
  black-chasm portals deep beneath the
  surface, the dead-end barriers with the
  5% volcanic-or-sealed-cavern hazard and
  the pyramid supposition, the plane of
  exile overrun by nightmares imps manes
  daemons mephits lesser devils and
  achalera, the barghests - the only true
  natives, petty barons whose wars send
  the young to the Prime - and the sparse
  Powers (Chih-Chiang Fyu-Ya's teardrop
  citadel with the giant-skull judgment
  bell, Loviatar's spell-warded ice
  fortress of cruelty on Mungoth, Shargaas
  the Night Lord of the deep Night Land,
  the only one who might know whether
  Gehenna goes deeper). 5 consts + 6
  bools, prefix ddo, header
  rules/gehenna.h. ONE flip: gap census
  75/15 -> 76/14. Spec 15,492 bytes, md5
  f65eeddfdfd829397c9af318b1e6548b
  matched exactly first try, 11 inlines.
  TWENTY-ONE straight first-tries
  (R566-R586). NEXT - R587: the Nine
  Hells (pp. 109-113, all nine layers -
  Avernus with Tiamat and the fireball
  vapor at 1-in-6 per turn, Dis the Iron
  City, Minauros the sinking city with
  the 13% disease, Phlegethos, Stygia,
  Malbolge, Maladomini, Caina, Nessus;
  pages 110-112 already read, page-113.md
  still to read for the Hells features,
  the rulers and the Styx riddle).
- R587 LANDED 2026-10-17: commit
  fd8e03f59cf609105d316ade2d039a00a
  8d5924a (census 510 -> 511, pushed
  15ae156..fd8e03f), THE NINE HELLS,
  printed pp. 109-113, evil organized:
  the nine infinite layers with the
  barrier rule (lowest point of the
  upper, half a mile above the next, the
  20d6 fall for the flightless), Avernus
  the front parlor (the 1-in-6 fireball
  vapor, 1-in-12 without open flame,
  Tiamat's watchdog lair of abishai and
  dragon spirits), Dis the Iron City of
  Dispater with the stone-and-lead
  sanctum, Minauros Mammon's sinking
  city at 13% disease with the barrier
  30 feet above the palace roofs,
  Phlegethos the liquefied-fire realm of
  Belial and Abriymoch, Stygia's
  three-mile ice pack with the diluted
  Styx and Geryon's Tantlin behind the
  2d6 cold-fire walls, Malbolge Moloch's
  rockfall viceroyalty, Maladomini and
  Baalzebul's thousand-mile million-room
  Malagard, Caina at -60 degrees under
  Mephistopheles, Nessus with the rifts
  descending to Asmodeus's palace on the
  shifting ice lake of the Lethe with
  the triple-strength fire waves), the
  reddish-hoop portals of Avernus
  (Acheron, Gehenna, Concordant
  Opposition, Tiamat's guards and
  traps), the Prime conduits, the
  rumored pre-overlord conduit that
  destroys all evil that touches it, the
  home-layer immunity doctrine, the
  arch-devil census and the three
  factions (Asmodeus with Geryon and
  Tiamat at 1-5-9, Baalzebul with Moloch
  and the recruited Belial at 4-6-7,
  Mephistopheles with Dispater and
  Mammon at 2-3-8, the overlord supreme
  playing both ends through the
  underrated Tiamat), and the non-devil
  Powers (Druaga tolerated beside Dis,
  Set's blazing bone-dry Avernus swath
  and his captive-built pyramid, Hecate
  and Inanna adjacent in Phlegethos,
  Sekolah beneath the Stygian ice
  devouring Geryon's ambassadors,
  Kurtulmak robbing his suitors blind,
  the moving thief No Cha, and the
  false-name devils Dagon and Nergal).
  6 consts + 6 bools, prefix ddp, header
  rules/ninehells.h. ONE flip: gap
  census 76/14 -> 77/13. Spec 22,244
  bytes, md5 931e05e67130b6259d7a157cc
  376e8d1 matched exactly first try, 12
  inlines. TWENTY-TWO straight
  first-tries (R566-R587). NEXT - R588:
  Acheron (pp. 113-114, the iron-shod
  battle plains - Avalas with the Styx
  pits and the spirit legions, the
  hollow scrap-heap blocks of Thuldanin
  with the 0.1% search chance, the
  geometric blocks of Tintibulus, the
  razor squares of Ocanthus, the
  spherical portals and the spinning
  pattern, Lei Kung; page-114 already
  read, page-115.md still to read for
  the rest of the Acheron features and
  the goblinoid legions).
- R588 LANDED 2026-10-17: commit
  cda2afa9eaa04ac6bc4ded97ad3379c4dd
  7b31a6 (census 511 -> 512, pushed
  fd8e03f..cda2afa), ACHERON, printed
  pp. 113-114, the iron-shod battle
  plains of lawful evil bridging the
  Hells and Nirvana's clockwork: the
  four block layers (Avalas with the
  black metal-hard ground, the iron
  citadels and the Styx rising from pit
  to pit, Thuldanin the scrap heap - the
  hollow blocks of stone-turned ships
  and devices at 0.1% per day's search
  and the monthly crushing-blow saves,
  Tintibulus and the fault-fractured
  hexagons of the solid grey volcanic
  blocks, Ocanthus's razor squares from
  inches to miles striking edge-on for
  1d10 dice as a 1d10-hit-die monster
  with no magical-armor benefit), the
  spherical portals hung fixed in space
  and read by their activation sound
  (the harmonious chord to Nirvana, the
  discord to Avernus, the silence to
  Concordant Opposition) with the 20d6
  arrival fall for the flightless, the
  unmoored barriers with the
  18-Intelligence pattern check (one per
  visit), the spirit legions - nations
  of the lawful-evil war dead who lost
  sight of their objectives, leaderless
  and reborn to full strength within 24
  hours - and the Powers (Lei Kung the
  Duke of Thunder alone on his
  cloud-island temple smiting for
  Shang-Ti; Maglubiyet and Gruumsh
  sharing one large spinning block, the
  goblin and orcish legions clashing
  daily, the wandering orcish pantheon
  seeking an Asgard of their own, the
  orbiting holdings of Luthic, Bahgtru
  and Ilneval, both sides waiting to hold
  the layer as the elves hold Arvandor -
  the everlasting war most deities cite
  as the folly of violence for its own
  end). 4 consts + 6 bools, prefix ddr,
  header rules/acheron.h. ONE flip: gap
  census 77/13 -> 78/12. Spec 17,147
  bytes, md5 d3f41796cdd8c4f4d97245d0
  cc9ee591 matched exactly first try,
  10 inlines. TWENTY-THREE straight
  first-tries (R566-R588). NEXT - R589:
  Concordant Opposition (pp. 114-116,
  the odd plane - the definite center,
  the ever-changing face resembling the
  traveler's homeland, the min-damage
  neutralization; PLUS the two gap
  tables: the center table p. 115 and
  the chaotic-destination table p. 116;
  page-115 already read, page-116.md
  still to read for the center mechanics
  and the destination roll).
- R589 LANDED 2026-10-17: commit
  2e271f48d15f57f5ec775baf3a8f2d16
  8a450183 (census 512 -> 513, pushed
  cda2afa..2e271f4), CONCORDANT
  OPPOSITION, printed pp. 114-116, the
  exception plane at the wheel's hub:
  the ever-changing homeland face (a
  different presentation each visit yet
  the special locations constant, the
  first visit a much-larger version of
  the traveler's homeland), the
  minimum-damage rule (the short sword 1,
  the two-handed broadsword 3, cure
  light wounds 1, heal all but 1,
  poisons and bonuses unaffected), the
  unclimbable center with the 100-mile
  spell ladder (9th at 1,000 miles down
  to 1st at 200, clerics starting at
  800; the specials - illusions as gems
  of seeing at 700, astral portals and
  artificial poisons at 600, natural
  poisons and the conduit reach at 500,
  no conjuration and no demi-gods at
  400, no lesser gods at 300, no greater
  gods at 200, chemical reactions dead
  at 100 where neither man nor god may
  come), the 200-mile meeting ground of
  the differing-alignment Greater
  Powers, the ring of white disks at the
  1,000-mile mark (destination by
  concentration, majority rules, the
  color pools beyond 600), the
  chaotic-destination roll (1-80
  intended, 81-90 one plane off, 91-00
  the opposite of the wheel), no native
  races with every outer-plane
  intelligence at home frequencies, and
  the Powers (Dagda's Tir na Og with Mag
  Mell and the Celtic swath, Manannan
  mac Lir's Tir fo Thuiran, Goibhniu's
  Land-of-Youth-only weapons, Ogma's
  negation prison, Thoth and Bes,
  Untamo's Sleeping Lands beside
  Tvashtri's clattering inventions, the
  Modrons' well of souls at the edge of
  the center, Yen-Wang-Yeh the sorter of
  the dead with his one week of misplaced
  spirits, Semuanya, Eadro, Sheela
  Peryroyal, Dumathoin, and Vergadain
  the Bes-similar luck-god). 6 consts +
  6 bools, prefix dds, header
  rules/concordantopposition.h. THREE
  flips: gap census 78/12 -> 81/9 (the
  plane, the center table, the
  chaotic-destination table) - THE
  PLANE-BY-PLANE CENSUS OF THE MANUAL OF
  THE PLANES IS CLOSED, every plane and
  every MotP table box pinned. Spec
  20,894 bytes, md5 cd8038cdf75ee545b40
  1022820068cbb matched exactly first
  try, 12 inlines. TWENTY-FOUR straight
  first-tries (R566-R589). NEXT - R590:
  Beyond the outer planes (p. 116, the
  closing essay - the unexplored realms,
  the possible eighth heaven and third
  paradise, Gladsheim's unreached
  layers, the quasi/para-elemental
  additions, the demi-planes and
  alternate Primes; the last MotP gap
  box, source page-117 already read).
- R590 LANDED 2026-10-17: commit
  1e2f20342d2ea92573cc655e16da37a09
  d0ca2be (census 513 -> 514, pushed
  2e271f4..1e2f203), BEYOND THE OUTER
  PLANES, printed p. 116, the closing
  essay of the Manual of the Planes: the
  summary-not-final-word doctrine (any
  number of realms in a layer, a third
  or fourth pantheon in Olympus/Arvandor,
  a DM's evil power in the Hells), the
  undiscovered layers (an eighth heaven,
  a third paradise unreachable by known
  spells, Gladsheim with as many layers
  as the Abyss but no Abyssal method of
  reaching them), the growing model (the
  quasi- and para-elemental planes and
  Concordant Opposition both late
  additions), the possible new Astral
  forms between the outer planes and
  farther out or within the Opposition's
  center, the finite world-sized
  demi-planes floating in the Ethereal,
  and the alternate Primes - Earth-like
  or not, familiar, hostile, and strange,
  the only limitation the imagination of
  those involved. 0 consts + 6 bools,
  prefix ddt, header
  rules/beyondouterplanes.h. ONE flip:
  gap census 81/9 -> 82/8 (Beyond the
  outer planes) - THE MANUAL OF THE
  PLANES IS FULLY CLOSED: every plane,
  every table, and the closing essay
  pinned, the whole MotP chapter taken
  R566-R590. Spec 10,173 bytes, md5
  b343081bad0430b34aca3d724a3e5121
  matched exactly first try, 6 inlines.
  TWENTY-FIVE straight first-tries
  (R566-R590). NEXT - R591: the gap
  report's eight remaining boxes belong
  to later chapters; consult
  tools/motp_gap_report.md (fetched at
  1e2f203) for the open list and pick
  the next chapter's first box.
- R591 LANDED 2026-10-17: commit
  d1cd2afb4de3019c7a60086441da02ae
  4f3607cd (census 514 -> 515, pushed
  1e2f203..d1cd2af), THE OUTER PLANES
  CHAPTER SEAL, printed pp. 73-116: the
  parent box closed on the census of
  its children - the seventeen named
  planes in wheel order (Nirvana and
  Arcadia, the Seven Heavens, the Twin
  Paradises, Elysium, the Happy Hunting
  Grounds, Olympus and Gladsheim, Limbo
  and Pandemonium, the Abyss, Tarterus,
  Hades, Gehenna, the Nine Hells,
  Acheron, and the Concordant Opposition
  at the hub), the general doctrine of
  R577 with its five tables and
  doctrines, the seventeen plane rounds
  R578-R589 (with the Beastlands casting
  reattribution), and the closing essay
  of R590. 1 const + 2 bools, prefix
  ddu, header rules/outerplanesseal.h.
  ONE flip: gap census 82/8 -> 83/7
  (the chapter umbrella) - THE OUTER
  PLANES CHAPTER IS SEALED. Spec 8,009
  bytes, md5 651ec7802d0210135b2d85fa
  2911c75f matched exactly first try, 3
  inlines. TWENTY-SIX straight
  first-tries (R566-R591). NEXT - R592:
  Appendix I: The Prime Material Planes
  (pp. 117-119, the Alternate Primes
  doctrine with the Prime physical-factor
  table at p. 117 - the 1d10 factor and
  the odd/even sign roll - and the
  Alternate Primes encounter rules at
  p. 119; THREE boxes fall together; the
  parent-plus-children one-round pattern;
  OCR source pages 118-120 already
  gathered).
- R592 LANDED 2026-10-17: commit
  542cc2f73a5e885c92440796a329c25cb
  08f44f9 (census 515 -> 516, pushed
  d1cd2af..542cc2f), APPENDIX I: THE
  PRIME MATERIAL PLANES, printed pp.
  117-119, the Alternate Primes doctrine
  in one round: the Polyverse and the
  three factors (physical magical
  temporal, the home Prime at 0,0,0),
  the reaching (the per-Prime Ethereals
  with the inner-plane relay, the Astral
  direct, the plane shift tuning fork,
  the amulet of the planes and the well
  of many worlds, the guarded gates, the
  psionic probability travel), the
  physical-factor roll (1d10 value, 1d4
  odd-negative/even-positive sign) with
  the +10-to--10 ladder and the comfort
  range of 5 with home abilities retained,
  the magical ladder (the +10 universal
  casting dissolving into mage-ruled
  demi-planes down to the -10 where
  sentient life is impossible, the
  wizard powerless at -6, the pooka
  saving vs. death), the temporal ladder
  (the differently colored suns at +10
  to the millions-of-years -10) with the
  time-travel digression, the class
  rules (the lesser-of-two-factors
  casters, the cleric deity cap at 1st
  and 2nd, druids and rangers within 2,
  barbarians within 1, the paladin's
  sentient mount), the encounter combat
  and magic adaptation, and the (5,-4,5)
  20th-century example. 6 consts + 7
  bools, prefix ddx, header
  rules/appendixiprimes.h. THREE flips:
  gap census 83/7 -> 86/4 (the appendix,
  the physical-factor table, the
  encounter rules). Spec 18,935 bytes,
  md5 28c4edecb934390643126f5468dbc290
  matched exactly first try, 13 inlines.
  TWENTY-SEVEN straight first-tries
  (R566-R592). NEXT - R593: Appendix II:
  Creatures of the Inner Planes (pp.
  120-121, the elemental analogues - the
  modified stats, the no-analogue list,
  the per-element abilities, the
  appearance size-change table; page-121
  already read, page-122.md still to
  read for the treasure types and the
  rest).
- R593 LANDED 2026-10-17: commit
  94ac8ef6319a630b26a486bf0c06765495
  c1b8f6 (census 516 -> 517, pushed
  542cc2f..94ac8ef), APPENDIX II:
  CREATURES OF THE INNER PLANES, printed
  pp. 120-121, the elemental analogues:
  the no-analogue list (no Ethereal/
  Astral/outer natives, no elemental
  undead, none for the PC humanoids, no
  elemental wizards though some cast),
  the stat modifications (movement
  tripled for Air/Smoke/Steam, doubled
  for Water, the 10%-less native and
  10%-more pocket lair percentages), the
  general abilities (movement through
  the adjoining planes as Prime travelers
  in the Ethereal, the Border-Ethereal
  sight, no Prime crossing without
  outside help), the per-element
  immunity and vulnerability rungs for
  all sixteen planes with the
  retained-immunity fire giant of Ash,
  the appearance dies (the 90% invisible
  air creatures, the Fire solids through
  the orbiting 2d6 geometric swarms, the
  crystalline Earth forms that shatter
  into useless shards, the Water
  amoeboids serpents mer-creatures and
  fish, the para-elemental humanoids and
  counterparts, the eight quasi-forms
  from the bolt-legged lightning balls to
  the salt-encrusted duplicates), the
  four-family size-change table with the
  halving and doubling effects (the
  15-foot giant's 60-foot equivalent),
  and the treasure rules (Air's 10%
  coinage in perfume, Fire's 20% in
  melted blocks or protected burnables,
  Earth's metal-and-gems preference,
  Water's doubled potions, the 50/50
  para-rule, the seven-of-eight quasi-
  rule with Vacuum normal, the
  low-intelligence protection, the
  elemental-pocket equivalence). 5 consts
  + 7 bools, prefix ddy, header
  rules/appendixiiinnercreatures.h. ONE
  flip: gap census 86/4 -> 87/3. Spec
  18,793 bytes, md5 fcc089f865cbde82aff
  4858c316045b7 matched exactly first
  try, 12 inlines. TWENTY-EIGHT straight
  first-tries (R566-R593). NEXT - R594:
  Appendix III: Creatures from the Outer
  Planes (pp. 122-123, the
  modification-by-plane tables and the
  outer-planar creature adjustments;
  OCR source pages 123-124 not yet
  read).
- R594 LANDED 2026-10-17: commit
  a1822b3f4c17902ad8e6a000e144bd3b0e
  0b84dd (census 517 -> 518, pushed
  94ac8ef..a1822b3), APPENDIX III:
  CREATURES FROM THE OUTER PLANES,
  printed pp. 122-123, the einheriar
  and their kin: the 10d10 einheriar
  patrol dice and 5% magic per level,
  the class/level d100 einheriar tables
  and the Anu-soldier hosts of Horusyr
  Clanggedin spirit folk Hindari
  Valhalla and the Acheron legions, the
  hourly marut powers, the common archon
  powers, the lantern reformation day
  and the sword gate turn, plus the
  mortal hound-warden and tome rule
  bools. Header rules/appendixiiiouter
  creatures.h, prefix ddz, 11 inlines
  (6 consts 5 bools), one gap flip
  (Appendix III) so 88/2. Spec
  tools/spec_r594.json 14455 bytes md5
  ad3e83f1d1712be754eff86d470e1f57.
  TWENTY-NINE straight first-tries
  (R566-R594). NEXT - R595: Appendix
  IV: Abilities of the Powers, printed
  pp. 124-126, one box, gap 89/1;
  OCR pages 125-127.
- R595 LANDED 2026-10-17: commit
  e344bb2b0a1e85362a0b7bca11d942e2b6
  126a8a (census 518 -> 519, pushed
  a1822b3..e344bb2), APPENDIX IV:
  ABILITIES OF THE POWERS, printed
  pp. 124-126, the divine ladder: the
  four ability types, the sixteen
  at-will standard powers with the cure
  and detect lists, the 30/20/15 magic
  levels and 4/3/2 command durations,
  the 30/20/10 protection radii, the
  Greater six-and-three Lesser
  four-and-two Demi three-and-one daily
  groups, the summon caps (2d6@40HD,
  1d6@30, 1d3@20), the wish limits, and
  the native heights - the
  vapor-reforming Greater, the
  soul-objected Lesser, the cord-cutting
  Demi. Header rules/appendixiv
  abilitiespowers.h, prefix deb (dea
  blocked by deathSpellBudget(), the
  R411 gate; deb is the chronological
  successor to ddz), 20 inlines (12
  consts 8 bools), one gap flip
  (Appendix IV) so 89/1. Spec
  tools/spec_r595.json 18116 bytes md5
  1d4b0634460bec5eea9d19e97621fc80.
  THIRTY straight first-tries
  (R566-R595). NEXT - R596: Indices,
  printed pp. 127-128, ONE box, closes
  the MotP gap report at 90/0; OCR
  pages 128-129; prefix debb or next
  chronological free prefix.
- R596 LANDED 2026-10-17: commit
  13903a82cbf9b7ad29012e9787168c73f
  82d1116 (census 519 -> 520, pushed
  e344bb2..13903a8), INDICES, printed
  pp. 127-128, the closing pair: the
  132-entry subject index of the
  whole book (the five plane
  families, the rivers with
  Mnemosyne restored from the OCR
  Manale, the creatures with
  Cerberus restored from Corberus
  and efreet from Efreel, the
  color pools and conduits) and
  the 89-spell index with its
  unusual-notes purpose, from the
  airy quintet and plane shift to
  the wish. Header rules/indices.h,
  prefix dec, 8 inlines (5 consts
  3 bools), one gap flip (Indices)
  closing the MotP gap report at
  90/0 - the whole 1987 Manual of
  the Planes pinned, 31 straight
  first-tries (R566-R596). Spec
  tools/spec_r596.json 10005 bytes
  md5 a35c97bf1c0c3f3e6282c23f32
  27384c. NEXT - R597: the
  maintenance round at HEAD (the
  census/gap/engine/seed/lint
  audit, then the logging
  reclassification tool round, UA
  to 102/0).
- R598 LANDED 2026-10-18: commit
  4d4793a7b6d01e06f9936b92bb82e5a
  38aac3412 (census 520 -> 521, pushed
  d3b3aaa..4d4793a), ETHER CYCLONE,
  printed p. 17: the one named table
  the R566 full-book scan missed -
  found by the R596-post three-way
  audit (book prose vs gap report vs
  repo). The 50% warning with the
  1d6-round deep-hum herald, the d20
  bands (1-10 the disrupted flow +4h,
  11-15 the random curtain, 16-18 the
  farther curtain +5d12 days, 19-20
  the lowest-level save: success
  +10d12 days to an unexplored
  section, failure the Astral tumble
  as plane shift, no silver cord),
  the Prime fallback saves, the
  inner-plane Border stop, the
  demi-plane of Time caveat. Header
  rules/motpethcyclone.h, prefix
  ded, 17 inlines (11 consts 6
  bools), one NEW gap box (not a
  flip): census grows 90 -> 91 boxes,
  91/0; the spec also seats the R596
  record (R597 the tool round skipped
  the seat). Spec tools/spec_r598.json
  10960 bytes md5 daf10b58e8fac35025
  1e6c70420fea3b. THIRTY-TWO straight
  first-tries (R566-R598). NEXT - R599:
  the DMO arc opener, High-Level
  Campaigns (1995, 192 pp.), the gap
  report landing with the round.
- R599 LANDED 2026-10-18: commit
  9b43c02c636bb5a4ab007a687e51e596
  60b5bd3f (census 521 -> 522, pushed
  4d4793a..9b43c02), THE SEVEN
  MAXIMS, the DMO ARC OPENER (the
  R564 pattern): Dungeon Master
  Option: High-Level Campaigns (1995,
  Skip Williams, 192 pp.) - the round
  lands tools/dmo_gap_report.md in
  the SAME commit as the spec: 96
  boxes, all 52 numbered tables
  enumerated at opener (the R566
  amended-manifest lesson applied
  here), the census-style lossless
  inventory with the two standing arc
  rulings (the 2e cross-book seam
  warning - NOTHING auto-credited
  from the DMG or PHB, a DMO box
  closes only on DMO-text pins with
  the book's own deltas; the
  advisory-prose scope ruling - the
  maxim and adventures chapters
  close on doctrine pins, the 52
  tables on table pins). Pins: the
  seven-principle maxim roster, the
  high-level definitions (the level
  10 floor, the 30th-level cap, the
  level-20 retirement frame), the
  flat-XP breakdown from 9th, the
  Table 1 demographics ladder (the
  1-in-5,000 10th, the
  one-in-a-million 18th, the 1-in-500
  paladin), the foreword previews (the
  true dweomers as 10th-level spells,
  the auto-fail foreshadow). Header
  rules/dmomaxims.h, prefix deg, 13
  inlines (8 consts 5 bools), SIX
  flips: gap census 6/90 (the front
  matter, the Chapter 1 parent, the
  roster, the first maxim, Table 1,
  the epic-scale maxim). Spec
  tools/spec_r599.json 12330 bytes md5
  9837bca89a218e6ec5979b0e7c3459fe
  matched exactly first try. THIRTY-
  THREE straight first-tries
  (R566-R599). NEXT - R600: the
  remaining Chapter 1 maxim boxes
  (Intelligent Adversaries pp. 10-12,
  Minimizing Personal Risks pp. 16-17,
  Control Magic pp. 17-21, Plan Ahead
  pp. 24-26, Share Responsibility pp.
  27-29) in one round; prefixes dej,
  dek, del free.
- R600 LANDED 2026-10-18: commit
  9a4cfff174f3d3085d65964b65c6b
  65298354452 (census 522 -> 523,
  pushed 9b43c02..9a4cfff), THE
  REMAINING MAXIMS, printed pp. 10-29,
  the doctrine round closing DMO
  Chapter 1 - every maxim box of the
  seven is now closed: the
  intelligent-adversary doctrines (act
  as smart as the intelligence says -
  the tiger at Int 2-4 and the
  average-intelligence kobolds; shield
  the weaknesses - the troll regen
  delay 3 rounds, the vampire
  sunlight-and-turning counters;
  maximize the strengths - troll waves,
  the vampire one-on-one; handle
  defeat by motivation with the
  four-option ladder
  surrender/flee/reversal/fight and the
  three-goal leaving-the-field), the
  villain self-preservation rules
  (never be there - project image, the
  magic jar, the bystander pose; bad
  guys don't fight fair - innocents,
  diversions, sentimental targets, the
  hidden advantage), the control-magic
  doctrines (the AC -4 tension floor,
  the bracers +8, the 18-hour study vs
  37-minute cast, the teleport 50-minute
  memorize with 2%/1% risk, no magic
  shops, magic unlike technology, the
  one-item-per-adventure rate), the
  plan-ahead doctrines (villains who
  learn on the six background pillars,
  consequences, the fame ledger), and
  the share-responsibility doctrines
  (the players as the cadre, the goals,
  the allies ledger, the personality
  profile). Header rules/dmocampaign.h,
  prefix dej, 29 inlines (12 consts
  17 bools). FIVE flips: gap census
  11/85 - CHAPTER 1 IS CLOSED. Spec
  tools/spec_r600.json 21913 bytes md5
  f923aae5f4a886dcc0f58926ed530145
  matched exactly first try; the spec
  also seats the R599 record. THIRTY-
  FOUR straight first-tries
  (R566-R600). NEXT - R601: DMO
  Chapter 2 (Adventures) opens - the
  doctrine half in one round; prefixes
  dek, del free.
- R601 LANDED 2026-10-18: commit
  d9cae88972563b4a1dbf2ab8a27ade6
  4b8db89bf (census 523 -> 524,
  pushed 9a4cfff..d9cae88), THE
  ADVENTURE DOCTRINES, printed pp.
  30-45, the doctrine half of DMO
  Chapter 2 in one round: the
  adventure-construction rules (show
  don't tell; prepare, don't
  over-plan; don't force the action -
  the backup plan; enhance, don't
  inflate; gifts vs. rewards;
  multiple threats; don't kill -
  scare; proactive and responsive
  foes; failures not catastrophic;
  the flexible decision-oriented
  plot), the encounter taxonomy (the
  TWELVE types - combat, deception,
  delay, dilemma, event, guardian,
  interaction, obstacle, puzzle,
  skirmish, surprise, trap; the FIVE
  linking methods - chained, ripple,
  interlocked, multi-layered,
  revisited; the FIVE combat-plan
  elements - attack power, mobility,
  organization, information,
  terrain), and the world-hopping
  doctrine (the three world types -
  plane, pocket dimension, demiplane;
  the 18 inner and 17 outer planes;
  the one-Prime correction; the four
  aspects - chronology, magic,
  technology, environment - rated
  2-20 on 2d10 with the 10-12 typical
  band; the polymorphed-lich rules
  springboard with its 60-turn/10-
  hour renewal). Header
  rules/dmoadventures.h, prefix dek,
  34 inlines (14 consts 20 bools).
  THREE flips: gap census 14/82 - the
  doctrine half of Chapter 2 closed.
  Spec tools/spec_r601.json 24435
  bytes md5 bdf31adbc770acf4e00812ac9
  2a14222 matched exactly first try;
  the spec also seats the R600
  record. THIRTY-FIVE straight
  first-tries (R566-R601). NEXT -
  R602: the Chapter 2 rating tables -
  Table 2 Alternate Chronology,
  Table 3 Magic Rating, Table 4
  Technological Level, Table 5
  Environmental Conditions (printed
  pp. 46-53 per the report); the
  monster-doctrine boxes follow;
  prefix del free.
- R602 LANDED 2026-10-18: commit
  394b9aab41f872433e10a91cfebe5cb520
  613286 (census 524 -> 525,
  pushed d9cae88..394b9aa), THE
  WORLD RATINGS, printed pp. 46-54,
  the table half of DMO Chapter 2:
  the Table 2 alternate-chronology
  grid (17 rows, ratings C2-C20, the
  10-12 band one row; base-campaign
  time magnitude + unit code 1-sec
  2-min 3-hr 4-day 5-wk 6-mo 7-yr +
  rating), the Table 3 magic-rating
  grid (17 rows, ratings M2-M20;
  rating, max spell level, cast/PSP
  multiplier, schools-modified range;
  dead-magic M2 pins 0s), the Table 4
  technological ladder pinned as
  eight era-threshold consts per the
  R595 precedent (steel 10, firearm
  14, steam 15, combustion 16,
  nuclear 17, fusion 18, robot 19,
  FTL 20), and the Table 5
  environmental-conditions grid (3
  rows x 5 cols: roll count, die
  size, severe/hostile/deadly period
  codes 1-day 2-hour 3-round; the
  poison save row). Header
  rules/dmoworlds.h, prefix del, 63
  inlines (38 consts, 12 bools, 13
  table columns). FIVE flips: gap
  census 19/77 - the rating tables
  and the quirks boxes closed. Spec
  tools/spec_r602.json 39232 bytes
  md5 7595cd8f1d5fa282db16954bf0086
  f85 matched exactly first try
  (after two pre-gate build fixes:
  col_comments/sentinel added to the
  three grids, inline count 50 ->
  63). THIRTY-SIX straight
  first-tries (R566-R602). NEXT -
  R603: the monster-doctrine boxes -
  the +/-1/2/3 modifier doctrine
  (printed pp. 57-58) and Tables
  6-22 (printed pp. 58-66); prefix
  den free.
- R603 LANDED 2026-10-18: commit
  08891d938a05a4ac30afe4966827e56fd
  cee6079 (census 525 -> 526,
  pushed 394b9aa..08891d9), THE
  LEGENDARY LADDER, printed pp. 57-66,
  the monster tail of DMO Chapter 2 in
  one round - ALL EIGHTEEN boxes flip
  and the chapter is DONE: the
  altering-monsters doctrine (the
  +/-1/2/3 modifier used throughout;
  hit points floored at one a die,
  damage at one a die, saves capped at
  20 and floored at 3, XP floored at
  1-1; movement, Intelligence, alignment
  and morale unchanged; the optional
  three-point size shift), the six
  ability-score grids T6-T11 (13 roll
  bands, the 9-12 band one row; the
  exceptional strengths encoded 1801
  through 1800; the rust monster reads
  ride the checks), and the eleven rank
  tables T12-T22 (AC -4 to -12, HD +5
  to +25 with the x1.5-x3.5 area
  multiplier; breath 26-75 averages with
  cloud/cone/line sizes; disease
  onset/fatality dice with unit codes
  1-round through 6-month; fear 30-50
  ft; crush 3d8-7d8 with the -4/-8 size
  saves; wounding 0-2d6 bleed; melee
  +1 to +3/die with great-elder and
  paragon extra dice and the size
  percentages; movement 20-60 percent;
  gaze -2 to -6 with the existing-
  weapon paragon -8; MR 60-100
  percent; regen 1-4 with the
  lesser-scion three-round delay). The
  rank ability rolls (3d4+4, 2d6+6,
  1d10+8, 1d10+8, 1d8+10) and power
  counts (2-3, 3-4, 3-5, 4-6, 5-7)
  pinned as consts. Header
  rules/dmomonsters.h, prefix den (dem
  was NOT free - the demiHumanTroops
  collision), 167 inlines (75 consts,
  14 bools, 78 table columns, 17
  grids). EIGHTEEN flips: gap census
  37/59 - Chapter 2 closed. Spec
  tools/spec_r603.json 70369 bytes md5
  120c1c5263c18ebc2c40a2b3c6405bef
  matched exactly first try (after two
  pre-gate build fixes: the bool-example
  != 1 form, the den prefix switch).
  THIRTY-SEVEN straight first-tries
  (R566-R603). NEXT - R604: Chapter 3
  (Spells and Magical Items, pp. 68-85)
  - the daily recovery of spells (the
  eight-hour rest, the 10 minutes per
  spell level), the wizard and priest
  spell clarifications, the item-use
  doctrines; prefix dep reserved.
- R604 LANDED 2026-10-18: commit
  35536f1a1cd2dd7540ac1f95b2ac6c22
  aa034ce2 (census 526 -> 527,
  pushed 08891d9..35536f1),
  SPELLS AND MAGICAL ITEMS, printed
  pp. 68-85, DMO Chapter 3 closed
  in one round - FIVE boxes flip
  and the chapter is DONE (gap
  census 42/54): the daily-
  recovery doctrine (the eight-
  hour rest, the ten minutes a
  level, the eight-hour study
  cap, the restart-on-
  distraction), the wizard and
  priest per-spell pins (the
  horrid wilting 16d8 with the
  OCR-misread note, the cone and
  delayed-blast dice, the ESP
  save ladder, the wish aging
  grids with the five races,
  the planar-research 4x5 grid
  with month=4/year=52, the
  plane-shift companions, the
  bag grid, the extradimensional
  portable-hole seam, the
  sphere cap and withering
  ladders), the item-use
  doctrines. Header
  rules/dmospells.h, prefix deq
  (dep NOT free - the depthFt
  collision; dem precedent),
  157 inlines (114 consts, 33
  bools, 10 table columns, 3
  grids T31-T33). Spec
  tools/spec_r604.json 72055
  bytes md5
  63806f24b1a9d4d9b26810a85f992c
  e6 matched exactly first try.
  THIRTY-EIGHT straight first-
  tries (R566-R604). NEXT - R605:
  Chapter 4 (Creating Magical
  Items, pp. 86-95) - the holy
  water font ceremony, the
  materials and processes
  doctrine, Table 23 and Table
  24, the per-type success
  formulas, the Rozmare worked
  examples; prefix der.
- R605 LANDED 2026-10-18: commit
  c3111fd0cccb7c812e10996e3eaa45c
  0807b0452 (census 527 -> 528,
  pushed 35536f1..c3111fd),
  CREATING MAGICAL ITEMS, printed
  pp. 86-95, DMO Chapter 4 closed
  in one round - TEN boxes flip
  (nine children + parent; gap
  census now 52 closed / 44 open)
  - the item-creation economy:
  rules/dmoitems.h, prefix der,
  179 inlines (117 consts, 47
  bools, 15 table columns), 3
  grids (T34 the Table 23
  creation grid 28x6 with the
  material, process, footnote,
  cost and time codes; T35 the
  Table 24 XP grid 27x3 with
  the per-plus, value-sum,
  20-40-percent-share and
  per-spell-level forms; T36 the
  font ladder 9x6 with the
  dice-times-multiplier basin
  costs), the holy water
  ceremony pins (the five-spell
  chain with the reversed
  unholy forms, the eight-hour
  meditations, the -4 combat
  window, the Delsenora recycle
  read at 30 percent of 21,000
  gp), the level thresholds
  (wizard 9-and-11, priest
  7-9-11, specialist +5), the
  70/80/60 per-type success
  bases, the 1d3+1-week potion
  and 1d6+1-week ring research
  windows, the ink ladder, the
  drained-item death rule, the
  24-hour recharge window with
  the -1 save-or-dust risk, the
  96-00 failure with the cursed
  and creator curses, the
  Rozmare reads at 94 and 65
  percent; the potion-rule
  divergence (prints +1 per two
  levels, the example works +26
  at 13th) pinned with the
  banner note. Spec
  tools/spec_r605.json 78591
  bytes md5
  ccd5a18c16bec52582713b0dab9cc5
  eb. THIRTY-NINE straight first-
  tries (R566-R605). NEXT - R606:
  Chapter 5 (Magical Duels, pp.
  96-117) - the arena construction,
  the balance of power, Table 25
  through 27, the spoils ladders;
  prefix des reserved.
- R606 LANDED 2026-10-18: commit
  10a395b32c4cf8625413be92bea8c
  edd3493991e (census 528 -> 529,
  pushed c3111fd..10a395b),
  MAGICAL DUELS, printed pp. 96-117
  (the biggest DMO chapter),
  closed in ONE round - SEVENTEEN
  boxes flip (sixteen children +
  parent; gap census now 69 closed
  / 27 open) - the dueling system:
  rules/dmoduels.h, prefix det (des
  NOT free - 7 collisions), 295
  inlines (146 consts, 126 bools,
  22 table columns, 1 chain), 5
  grids (T37 Table 25 interactions
  5x5; T38 Table 26 movement 5x1;
  T39 Table 27 power scores 5x2
  bonus 0-4 over PS 9-13; T40
  friendly stakes 4x6 and T41
  death stakes 5x8, both with
  sentinel censuses) plus the
  service chain (charm,
  suggestion, geas, domination),
  the arena protocol with the
  consent doctrine, the corridor
  geometry ten-plus-levels
  capped at thirty, the five-type
  doctrine with PR = level + 9,
  the 1d20 combat with the lock
  rules, the counter-spell
  doctrine, the item rules (the
  scroll of protection PR 15 MV
  1, the 6d6/8d6/9d6 leech caps,
  the 14 protection read), the
  specialist gates with the
  opposition-school +1, the
  stakes ladders with the 20 and
  40 percent plane blows and the
  50 percent disintegration, the
  special dueling characteristics
  (the five groups plus the
  quantified individual
  abilities), the Calvin-Delsenora
  worked duel. THREE pre-publish
  fixes (two flip-anchor wrap
  mismatches, one R391-class
  sense inversion) - the
  first-try streak ENDS at 39
  (R566-R605). Spec
  tools/spec_r606.json 123655
  bytes md5
  dcad6af6bd3e754b933849cb3078c7
  c0. NEXT - R607: Chapter 6
  (True Dweomers, pp. 118-141) -
  the 10th-level spell system,
  Tables 28 through 35; prefix
  dev.
- R607 LANDED 2026-10-18: commit
  55ce7ba71ee7b7cddfffea2e6dda476
  0ceb6e438 (census 529 -> 530,
  pushed 10a395b..55ce7ba),
  TRUE DWEOMERS, printed pp.
  118-141, DMO Chapter 6 closed in
  ONE round - TEN boxes flip (nine
  children + parent; gap census now
  79 closed / 17 open) - the
  10th-level spell system:
  rules/dmodweomers.h, prefix dev,
  238 inlines (180 consts, 42
  bools, 16 table columns), 8
  grids (T42 Table 28 true dweomers
  29x3 with sentinel_census [1,1,1]
  for the shadow-shape row; T43
  Table 29 areas 10x4 census
  [0,3,0,0]; T44 Table 30 animated
  objects 6x2; T45 Table 31 ranges
  10x1; T46 Table 32 durations
  11x1; T47 Table 33 prep/cast
  10x2; T48 Table 35 duel types
  29x1; T49 13 known dweomers
  difficulty/final pairs), 30+
  table_checks including the
  Pharjis worked example
  (110->70->35->5->10). DIVERGENCE
  pinned in the banner: the Pharjis
  example reads half-day duration
  at +10 while Table 32 prints 6
  hours at 7 and 12 hours at 10 -
  example arithmetic pinned
  verbatim with note. FIVE
  pre-publish fixes (one `//` in a
  table_check expr, four miskeyed
  table_checks - data right, check
  expressions wrong: Table 28
  easiest-at-20 row indices, Table
  35 duel-type rows, fortify ladder
  via the 30-point base difficulty
  x2/x4, Table 32 one-year row
  index 9) plus one mid-run restore
  (first engine run half-patched the
  gap report; standard repo.tgz
  recovery). Spec tools/
  spec_r607.json 107766 bytes md5
  0e8b7dd5027aaf880091f839ee09362
  d. NEXT - R608: Chapter 7
  (High-Level Characters, pp.
  142-164) - the LAST DMO chapter;
  consult the gap report at new HEAD
  55ce7ba for its boxes; verify next
  prefix free (likely dew family).
  Audit: "R607 DMO true-dweomers
  audit"; include after
  rules/dmoduels.h.
- R608 LANDED 2026-10-18: commit
  a3960f01c2812e4a8bacf4acc691e6b
  979f99444 (census 530 -> 531,
  pushed 55ce7ba..a3960f0),
  HIGH-LEVEL SAVES AND THACO, printed
  pp. 142-144, DMO Chapter 7 round one
  of five per the split plan - FIVE
  boxes flip (all children; the Chapter 7
  parent stays open until R612; gap
  census now 84 closed / 12 open):
  rules/dmohighlevel.h, prefix dew
  (verified free; only regtest hit was
  the word dewberry), 51 inlines (27
  consts, 15 bools, 5 chains, 4 table
  columns), 2 grids (T36 Table 36
  saves-by-caster-level 28x3 in four
  group bands - priest 7, rogue 6,
  warrior 10, wizard 5 - with the
  defender-minus-caster row-band chains
  plus row-base consts for the offset;
  T38 Table 38 penalty ladder 7x1 read
  via the dewT38Band chain), 24
  table_checks (the Wulf 5-3=2 example,
  the band heads and tails, the deity
  ladder descent, the T39 order pins).
  DELIVERY SAGA (three lessons seated
  in Verification lessons): the canvas
  b64 block copied at 15K (clipboard
  clip), the raw-JSON chat route struck
  (Markdown `](` mangling of every expr,
  plus an author-side dev/dew typo in
  examples[30] - both Vibe-side at the
  chat source), repaired in place by
  field/item md5 fingerprinting plus a
  base64 repair blob; the spec md5
  68b21a32ed99892aaba2d53291c912e9
  verified byte-exact before ./rn.
  Spec tools/spec_r608.json 33491
  bytes. NEXT - R609: skills Tables
  40-41 plus Warriors with Table 42
  (pp. 145-156); consult the gap report
  at HEAD a3960f0; verify next prefix
  free (dex family next). Audit:
  "R609 DMO high-level skills audit";
  include after rules/dmohighlevel.h.
- R609 LANDED 2026-10-18: commit
  d92d4d53d94bb405374b2c76163eddad
  1a52c051 (census 531 -> 532,
  pushed a3960f0..d92d4d5),
  HIGH-LEVEL SKILLS AND WARRIORS,
  printed pp. 145-156, DMO Chapter 7
  round two of five per the split
  plan - THREE boxes flip (Table 40,
  Table 41, Warriors; the Chapter 7
  parent stays open until R612; gap
  census now 87 closed / 9 open):
  rules/dmohighskills.h, prefix dey
  (verified free), 293 inlines (110
  consts, 164 bools, 7 chains, 12
  table columns), 3 grids (T40 roster
  33x5 in four class bands - warriors
  0-10, wizards 11-13, priests 14-21,
  rogues 22-32; T41 modifiers 11x1 via
  the deyT41Band chain; T42 warrior
  advancement 11x6), 274 examples,
  29 table_checks, 547-mutant
  battery 0 missed. CONTESTED CELLS
  settled against the physical copy
  (user-confirmed 2026-10-18): Divine
  Voice and Detect Deception cost
  cells are BLANK in print (pinned as
  -99 printed blanks with the
  sentinel census), the bravery
  prerequisite line prints
  "invulnerability" (pinned verbatim,
  both captures + physical agree),
  Table 42 row 20 reads weapon 10,
  nonweapon 9. DELIVERY: raw JSON in
  the canvas (user-set: b64 NOT
  needed anymore), spec 128073 bytes,
  md5 dd57b4ebba4b37c5623c43db948
  02b38 verified byte-exact before
  ./rn. NEXT - R610: Wizards and
  Priests, Tables 43-46 (pp. 156-
  167); consult the gap report at
  HEAD d92d4d5; verify next prefix
  free (dez family next). Audit:
  "R610 DMO wizard-priest audit";
  include after rules/dmohighskills.h.
- R610 LANDED 2026-10-18: commit
  74d21c689276b8ae13e9a406cecab0e
  880c76c8e (census 532 -> 533,
  pushed d92d4d5..74d21c6),
  WIZARDS AND PRIESTS, printed
  pp. 156-167, DMO Chapter 7
  round three of five per the
  split plan - TWO boxes flip
  (Wizards, Priests; gap census
  now 89 closed / 7 open):
  rules/dmohighwizpri.h, prefix
  dez (verified free), 390
  inlines (167 consts, 184
  bools, 7 chains, 32 table
  columns), 5 grids (T43 wizard
  advancement 11x5; T44 wizard
  spell progression 11x10; T45
  priest advancement 11x6; T47
  priest spell progression 11x8;
  loan 4x3), 351 examples, 42
  table_checks, 709-mutant
  battery 0 missed. FOUR
  PRINTED QUIRKS pinned
  verbatim: the priest spell
  progression body caption
  prints Table 47 while both
  ToCs read Table 46 (held per
  body caption); Spell Talisman
  is absent from the Table 40
  roster (pinned from its
  detail section); the eminence
  prose lists divine will among
  its five prerequisites while
  Table 40 reads priest 10+
  without eminence (both
  pinned); the wizard mental
  focus ceiling reads equal to
  or higher vs the priest
  already higher. DELIVERY: raw
  JSON in the canvas (user-set:
  b64 NOT needed), spec 161942
  bytes, md5
  8b212a3800959b0a4264a0f5261
  8801a verified byte-exact
  before ./rn. NEXT
  - R611: Rogues, Tables
  48-52 (pp. 167-171); consult
  the gap report at HEAD
  74d21c6; verify next prefix
  free (dfa family next).
  Audit: "R611 DMO rogues
  audit"; include after
  rules/dmohighwizpri.h.
- R611 LANDED 2026-10-18: commit
  1de9c4b4e71c072964a9c667e08c13db
  2e96a250 (census 533 -> 534,
  pushed 74d21c6..1de9c4b),
  ROGUES, printed pp. 167-177, DMO
  Chapter 7 round four of five per
  the split plan - ONE box flips
  (Rogues; gap census now 90 closed
  / 6 open):
  rules/dmohighrogues.h, prefix dfa
  (verified free), 273 inlines (111
  consts, 117 bools, 6 chains, 39
  table columns), 9 grids (T47r
  rogue advancement 11x5; T49
  racial 5x6; T50 Dexterity-aim 2x10;
  T51 armor 3x3; bribe status 4x2;
  tunneling earth 3x2; T52 bard
  spell progression 11x8; fall
  surface 7x1; featherfoot 3x2),
  228 examples, 42 table_checks,
  478-mutant battery 0 missed. TWO
  CONTESTED CELLS settled against
  the physical copy (user-confirmed
  2026-10-18): the T47 level-30 XP
  reads 4,300,000 (ABBYY; tesseract
  4,500,000, series 4,400,000) with
  the final step only 120K not 220K;
  and the T50 tunneling row prints a
  dash at Dex 17 and +30 at 22
  (tesseract; ABBYY dropped the final
  cell). THREE printed quirks pinned
  verbatim: the rogue advancement
  caption shares printed number 47
  with the priest spell progression
  caption; the T49 halfling
  detect-magic cell prints +5 without
  the percent sign; the rogue
  Con-bonus footnote reads after
  10th level (warrior and wizard read
  9th). All eleven rogue skills pinned
  (adaptation, classify traps,
  evasion, fall/jump with the Jobare
  shaft example, featherfoot,
  improvised attack with its
  save-modifier ladder and trick-hat
  example, inner focus,
  nondetection, sense danger with
  its subskill ladder, shadow
  flight, shadow travel). DELIVERY:
  raw JSON in the canvas (user-set:
  b64 NOT needed), spec 124783
  bytes, md5
  6ebd867df11799adcd4f16361bca6b5d
  verified byte-exact before ./rn.
  NEXT - R612: Demihumans in
  High-Level Play / Demihuman
  Advancement + Beyond 30th Level /
  Divine Ascension (pp. 178-179) -
  the Chapter 7 PARENT flips here;
  consult the gap report at HEAD
  1de9c4b; verify next prefix free
  (dfb family next). Audit: "R612
  DMO demihumans-ascension audit";
  include after rules/dmohighrogues.h.
- R612 LANDED 2026-10-18: commit
  2ff6ba87f1715469ed87c8d6492a93be
  25c1f6b3 (census 534 -> 535,
  pushed 1de9c4b..2ff6ba8), DEMIHUMANS
  AND DIVINE ASCENSION, printed pp. 178-
  179, DMO Chapter 7 round five of five
  per the split plan - THREE boxes flip
  (Demihumans, Beyond 30th / Divine
  Ascension, AND the Chapter 7 PARENT;
  gap census now 93 closed / 3 open;
  Chapter 7 fully closed across
  R608-R612): rules/dmohighascend.h,
  prefix dfb (verified free), 54
  inlines (10 consts, 44 bools, no
  chains or grids - a prose-only round;
  both captures agree on every number,
  only the standing lOth-for-10th OCR
  misread on the transformation and
  imbue spell names, settled per the
  index), 54 examples, 4 table_checks,
  54-mutant battery 0 missed. The
  demihuman doctrine and its four
  solutions (wish or 10th-level
  transformation to human; wish or
  imbue per level beyond the racial
  max with earned XP; Slow Advancement
  with humans pulling ahead from 10th;
  slow-after-max with the racial heroic
  task), the 30th-level ceiling, and
  the full ascension path (seek after
  20th, the sponsor, the gift at the
  XP-total value, the 500K-per-save-
  point benefit to a minimum of three,
  the Table 59 offering roll, the
  heroic task with five examples, no
  ability under 13, the demigod NPC
  ending, heroes not gods). DELIVERY:
  raw JSON in the canvas (user-set:
  b64 NOT needed), spec 30792 bytes,
  md5 7573d01110738825393f70488b2f05fc
  verified byte-exact before ./rn. NEXT
  - R613: the Appendix - Spell Dueling
  Characteristics (pp. 180-188, the
  per-spell PR/MV/A/L/D roster - a big
  grid round) then the Index (pp.
  189-192) closes the DMO arc; consult
  the gap report at HEAD 2ff6ba8;
  verify next prefix free (dfc family
  next). Audit: "R613 DMO dueling
  appendix audit"; include after
  rules/dmohighascend.h.
- R613 LANDED 2026-10-18: commit
  0f6f8e3d01558f33ba2f87e11a66fe46
  8c2966bd (census 535 -> 536,
  pushed 2ff6ba8..0f6f8e3), THE
  SPELL DUELING ROSTER AND INDEX,
  printed pp. 180-192, DMO arc
  closer - the Appendix and Index
  boxes flip (the TRUE census after
  R613 was 95/1; the committed
  96/0 prose claims stood false
  until R613b): rules/
  dmoduelroster.h, prefix dfc
  (verified free), 257 inlines
  (50 consts, 15 bools, 192 table
  columns), 24 letter grids with
  707 roster entries, the usage
  bitmask doctrine (A1 D2 L4 M8
  Any16), Thought Capture pinned
  usage 0 (physical-copy
  confirmed), 38 F-reads pinned as
  leech mask 4, the four printed
  PR exceptions, dagger 209 /
  asterisk 148 by the glyph
  adjudication, 5721-mutant
  battery 0 missed. Spec 144,727
  bytes md5
  7e9be62b7cd92bae7bd72951831a
  7314 (canvas 144,802 bytes md5
  1e1ec74d110e65ffaa1d28d0897bfd
  0f), both published and verified
  byte-exact before ./rn. R613b
  (direct fix, no spec, the R391b
  precedent) flipped the missed
  Chapter 2 parent at HEAD
  8836093: the DMO arc stands
  96/0 true. NEXT - R614: the OA
  arc (Oriental Adventures 1986,
  TSR 1500, 144 pp.) - the gap
  report lands with the opener
  (the R564 pattern); prefix dga;
  include after
  rules/dmoduelroster.h; audit
  "R614 OA opener audit".
- R614 LANDED 2026-10-18: commit
  a7019b4ad63e23afa1a01698d19d1f5
  8b82300c (census 536 -> 537,
  pushed 8836093..a7019b4), THE
  OA ARC OPENER (the R564 MotP
  pattern): the gap report
  tools/oa_gap_report.md lands in
  the same commit as the spec -
  235 boxes at opener (all 88
  numbered tables itemized). OA
  (1986, TSR 1500): the capture
  carries no printed page numbers
  so cites are CAPTURE pages; a
  single-capture arc (contested
  cells settle book-internal,
  then the physical copy).
  RITUAL: an opener with a NEW
  gap report verifies rverify in
  working-tree mode only - the
  sha restore deletes the new
  report (the R564 lesson).
  PINS: rules/oacreating.h,
  prefix dga (verified free), 22
  inlines (7 consts, 15 bools):
  the front-matter doctrine (the
  European monk retired for the
  oriental monk, the Kara-Tur
  naming, the honor thesis), the
  four generation methods, the
  NPC rules, the wish ladder,
  the Strength yardstick (the
  470-lb 18/00 press). Battery
  22 mutants, 0 missed; double-
  run GREEN (applied 8). Gap
  census 0/235 -> 4/231. Spec
  14,829 bytes md5
  75583a1171e018c2145e52ffddc002
  8a (canvas md5
  5d34868f3f88f4f7acd459bda2fc1c
  21); gap report md5 pre-flip
  35136522ec218e19541900bb042298
  5a, post-flip
  2631deaa6196a65f906b45eb108b21
  7d. NEXT - R615: the Chapter 1
  ability tables (Tables 1-8),
  prefix dgb (verify free), audit
  "R615 OA ability tables audit",
  include after
  rules/oacreating.h.
- R615 LANDED 2026-10-18: commit
  79bfb8dba8895ad96d5fa7d9c8c1
  88dc0850b2f (census 537 -> 538,
  pushed a7019b4..79bfb8d), THE
  ABILITY TABLES, capture pp. 7-13
  - all EIGHT Chapter 1 tables flip
  in one round: rules/
  oaabilities.h, prefix dgb (verified
  free), 94 inlines (63 consts, 10
  bools, 1 chain dgbT8Band, 20 table
  columns): 7 grids (T2 16x6 with
  the locked-parenthetical column,
  T3 17x2, T4 16x4 with the warrior
  +3/+4 footnote column, T5 16x2,
  T6 16x1, T7 16x3, T8 9x2), 56
  class/race annotation consts (T1
  pins ENTIRELY on annotations), 10
  rider bools. ADJUDICATIONS: T2 Str
  3 weight prints 0 - pinned as
  printed, flagged for the physical
  copy; the T5 orphaned korobokuru-
  max row merged onto Int 15; Str 19
  "7 in 8" pins as face 7. Battery
  389 mutants, 0 missed; full sha
  rverify GREEN (the gap report now
  tracked). Gap census 4/231 ->
  12/223. Spec 41,599 bytes md5
  3fffbdf6a5acff0d9d79e9ab28fea88
  (canvas 466b3bcaab8f6b688bf500600
  f37ee8a); gap report post-flip md5
  83559aa9327a7d428c9f522aa53401b9.
  NEXT - R616: the six ability prose
  sub-items, prefix dgc (verify
  free), audit "R616 OA ability prose
  audit", include after rules/
  oaabilities.h.
- R616 LANDED 2026-10-18: commit
  5aee1367e139fdec336bf1181241ce1a
  150ad8e2 (census 538 -> 539,
  pushed 79bfb8d..5aee136), THE
  ABILITY PROSE, capture pp. 8-15
  - the six Chapter 1 prose
  sub-items flip and CHAPTER 1
  CLOSES COMPLETE: rules/
  oaabilityprose.h, prefix dgc,
  50 inlines (22 consts, 28 bools)
  - the Con revival ledger, the
  wu jen Int spell gate, the full
  Comeliness system (nine reaction
  bands, the smitten doctrine, the
  magic caps). ADJUDICATION: the
  printed 26-27 band hole pinned
  as printed. TWO RITUAL CATCHES,
  both engine-gated: a Python
  ternary tripped the R426 gate;
  a wrong contiguity check FAILED
  THE AUDIT MIRROR; the abort
  left a mixed tree - cleaned by
  the R420 restore-and-rerun.
  Battery 50 mutants, 0 missed;
  full sha rverify GREEN. Gap
  census 12/223 -> 18/217. Spec
  27,310 bytes md5
  56f3cb0f78562b8ba267516a633a218c
  (canvas md5
  f4a81b5243f4bf07936027ad3c5c615f
  ). NEXT - R617: Chapter 2 opens -
  the class combos prose, Tables 9,
  10, 12 and 13, prefix dgd
  (verify free), audit "R617 OA
  class combos audit", include
  after rules/oaabilityprose.h.
- R617 LANDED 2026-10-18: commit
  0659a83e5b54c666c68e9f764bcee24
  fe9bd34f1 (census 539 -> 540,
  pushed 5aee136..0659a83), CLASS
  AND RACE COMBINATIONS, capture
  pp. 16-23 - the Chapter 2
  opener: rules/oaclasscombos.h,
  prefix dgd (verified free), 65
  inlines (26 consts, 11 bools, 28
  table columns): the combos
  riders, T9 10x5 with the alignment
  TIER COLUMN, T10 6x6, T12 10x12
  with the colon notation SPLIT into
  two columns and the barbarian Wis
  16 MAXIMUM as its own bool, T13
  10x5 with the text-heavy grid
  ENCODED AS TIERS and the LIST-
  COUNT COLUMN (shukenja 16, sohei
  7 exclusions, wu jen 20, monk
  16) plus the three riders. Battery
  293 mutants, 0 missed; full sha
  rverify GREEN. Gap census
  18/217 -> 23/212. Spec 28,743
  bytes md5
  f6390785beed71cd22ba8ba7225aa4d5
  (canvas md5
  8ce7d335c9a699ea25edde7bea604cda
  ). NEXT - R618: the three races
  with Table 11, prefix dge
  (verify free), audit "R618 OA
  races audit", include after rules/
  oaclasscombos.h.
- R618 LANDED 2026-10-18: commit
  7305a1fa0c38e5274e868458c6ea3861b
  e28547c (census 540 -> 541,
  pushed 0659a83..7305a1f), THE
  ORIENTAL RACES, capture pp. 17-22:
  rules/oaraces.h, prefix dge, 70
  inlines - the korobokuru, hengeyokai
  (T11 12x10) and the three spirit folk
  with their life-force ties. THE 4 1/2
  SAGA: the first capture prints 41h;
  THE USER UPLOADED THE 2018 PRINT
  (145 capture pages, DIFFERENT
  PAGINATION - its cites never mix),
  which reads 4 1/2 CLEAN - 41h was a
  transcription artifact, NOT a printed
  misprint; the divisor-2 pin held
  throughout. DOCTRINE: the 2018-print
  capture is the SETTLING SOURCE for
  contested cells. THE R618 v3
  ADJUDICATION AMENDMENT (comment-  only: spec 08fa91d7 -> 9ea88b9e,
  oaraces.h 3786b6c2 -> 615b853c)
  missed the R618 push - FOLDED INTO
  THE R619 PUSH (this round). Battery
  180 mutants, 0 missed; gap census
  23/212 -> 27/208. NEXT - R619: the
  Barbarian and Bushi with Tables
  14-17, prefix dgf (verify free),
  audit "R619 OA barbarian bushi
  audit", include after rules/oaraces.h.
- R619 LANDED 2026-10-18: commit
  96b0682cda3a7922e2a427ca4994e45d1
  3f7bf90 (census 541 -> 542,
  pushed 7305a1f..96b0682), THE
  BARBARIAN AND BUSHI, capture pp. 23-28
  - the class run opens: rules/
  oabarbbushi.h, prefix dgf, 87 inlines
  (50 consts, 23 bools, 14 table columns):
  the barbarian (d12, the +2-per-Con-over-
  14 bonus, T14/T15/T16, the three
  territories, the horde with the
  1 1/2-TIMES-LEVEL max - 1112 settled
  against the 2018 print BEFORE pinning,
  the settling doctrine FIRST LIVE USE),
  the bushi (the AC-step-per-five-levels
  rule, T17). LESSON: THE R618 v3
  AMENDMENT FOLD DID NOT LAND - the rn
  flow staged only the R619 files; the
  landed tree still carries spec_r618 at
  08fa91d7 and oaraces.h at 3786b6c2
  (the v2). THE AMENDMENT IS RE-APPLIED
  TO THE WORKING TREE AND MUST RIDE THE
  R620 PUSH - EXPLICITLY git add
  tools/spec_r618.json rules/oaraces.h
  (a PRIOR-ROUND-FILE fold does not
  happen by itself). Battery 227 mutants,
  0 missed; gap census 27/208 -> 33/202.
  Spec 37,972 bytes md5
  5530686e0626ac064bd7e40f8db981dd. NEXT -
  R620: the Kensai, Tables 18 and 19,
  prefix dgg (verify free), audit "R620
  OA kensai audit", include after rules/
  oabarbbushi.h.
- R620 LANDED 2026-10-18: commit
  36f2d5c330c3ec2bb05ce4c24894b9922
  2c812df (census 542 -> 543,
  pushed 96b0682..36f2d5c), THE
  KENSAI, capture pp. 28-31 - the
  sword saint: rules/oakensai.h,
  prefix dgg (verified free), 58
  inlines (34 consts, 16 bools, 8
  table columns): the Wis/Dex dual
  prime, the NATURAL AC FORMULA
  (23 minus Dex, one step per
  three levels, replacing the Dex
  adjustments), the initiative
  ladder, the ki power (max damage,
  announced pre-roll, level/day),
  the level powers (the dmg/hit
  ladders to +5, meditate at 4th,
  the 1-in-6 surprise at 6th, two
  weapons + fear at 7th, the pupil
  doctrine at 9th, the whirlwind
  at 11th), the restrictions (no
  magic specialty weapon, half-xp
  other weapons), the practice
  debt, the duel doctrine (the
  10-times-level challenge,
  refuse-or-lose, the honor-
  demotion to bushi), T18 12x3,
  T19 12x5 with the special powers
  as a coded column. THE R618 v3
  AMENDMENT LANDED MANUALLY as
  commit 17d2892 (pushed
  36f2d5c..17d2892): spec_r618 md5
  9ea88b9e04b2127bcf2d08572631988a,
  oaraces.h md5
  615b853c9ee3f4fb37963efc6089ea22,
  both confirmed on Termux. STANDING
  LESSON: prior-round folds never
  ride ./rn (it stages only the
  current round's files) and must
  be committed manually (git add
  the two named files). The
  two-miss saga is CLOSED. Battery 146
  mutants, 0 missed; full sha
  rverify GREEN. Gap census
  33/202 -> 36/199. Spec 26,426
  bytes md5
  e903fef69d08823b58aa685bb199adc
  b (canvas md5
  95d69cc0798205bc4aaae125cfeef7e
  9). NEXT - R621: the Monk - the
  discipline ladder, the quirks,
  Tables 20 and 21, prefix dgh
  (verify free), audit "R621 OA
  monk audit", include after rules/
  oakensai.h.
- R621 LANDED 2026-10-18: commit
  9ae052e37815d0baa1accd52e83af4ba914d4b5f
  (census 543 -> 544, pushed
  17d2892..9ae052e), THE MONK, capture
  pp. 31-35: rules/oamonk.h, prefix
  dgh (verified free), 93 inlines (59
  consts, 20 bools, 14 table columns):
  the Str/Wis/Dex 15 and Con 11 minima
  with no prime requisite, the 2d4
  start and 1d4 per level, the ki
  power (save negates at 1st, declared
  even after the roll, half damage on
  a FAILED save from 9th), the
  level-power ladder (speak with
  animals at 3rd, the 20-ft and 30-ft
  falls, the ESP 30-minus-2 ladder
  from 4th, disease and haste/slow at
  5th, cataleptic twice level, the
  2-5-plus-1 heal from 7th, speak with
  plants and the 2-5 followers at 8th,
  the charm 50-plus-5 ladder from 9th,
  the Int-18 mind shield at 10th,
  poison at 11th, geas at 12th, the
  free maneuver at 13th), the free
  Missile Deflection, the material
  restrictions (no property, the
  2-weapon and 3-item caps, the
  DMG rings-or-thieves gate), the
  monastery duel with the three 8ths
  and the 98,001 reset example, T20
  17x3 (xp bounds, accumulated d4 dice
  - the 2-through-18 column header
  SETTLED against the 2018 print -
  and title codes Novice through
  Grand Master of Flowers), T21 17x11
  (the AC/move/surprise ladders, the
  six thief skills, the martial-arts
  attack codes 1/4 through 3/1 and
  the plus-dice damage codes). OCR
  normalization: may riot own horses
  reads as may not; immune to gees
  reads as immune to geas. Battery 317
  mutants, 0 missed; full sha rverify
  GREEN. Gap census 36/199 -> 39/196.
  Spec 38,425 bytes md5
  8ae3a830dc7f489c87fb6a8dfd837c5d
  (canvas md5
  7c5d331fda0ebb6f3142b6115738c036).
  NEXT - R622: the Ninja, capture
  pp. 35-39, Tables 22 and 23, prefix
  dgi (verify free), audit "R622 OA
  ninja audit", include after rules/
  oamonk.h.
- R622 LANDED 2026-10-18: commit
  7efe429eae3143fb3b5e6203f56172fc69089e58
  (census 544 -> 545, pushed
  9ae052e..7efe429), THE NINJA, capture
  pp. 35-39: rules/oaninja.h, prefix
  dgi (verified free), 100 inlines (44
  consts, 37 bools, 19 table columns):
  the human-only split class (Dex 14,
  Cha 14, Int 15 minima, no prime
  requisite), the split xp with the
  DM-skew rider, the 1-2 hp per level
  with the halved round-up other-class
  die and the printed 2-to-7
  bushi/ninja example, the thief
  saves, the honor-free special
  weapons with the cross-slot honor
  loss, the eleven capabilities (the
  nightingale floors, the tightrope
  wind ladder with the -5 fight
  penalty, the pole vault, the
  once-per-level locks), the three ki
  powers (breath at 1st, water walk at
  5th, the wall pass at 12th), the
  family rule, the mission and honor
  mechanics, the nukenin with the
  2-times xp cost, T22 12x2, T23 10x5,
  T24 20x11 with the pole vault in
  half feet. TWO CELLS SETTLED
  AGAINST THE 2018 PRINT BEFORE
  PINNING: the T22 level-2 bound pins
  as 8,000 (the 2018 8,001 cell
  contradicts its own next-row floor);
  the T23 Dex-11 pockets cell pins as
  -5 (the 2018 05 reading lost the
  minus against the ladder). LESSON:
  the settling source settles only
  what is CONSISTENT - a settling
  reading that contradicts its own
  table ladder does not overturn the
  capture cell. OCR normalization: 15
  points reads as 1-5 points;
  infraction reads as infravision;
  1096 reads as 10 percent. Battery
  376 mutants, 0 missed; full sha
  rverify GREEN. Gap census 39/196 ->
  43/192. Spec 44,392 bytes md5
  b9debd1ae731649f66654ae3bc6c6595
  (canvas md5
  6ffd78033f585bdd7d2ae82652250540).
  NEXT - R623: the Samurai, capture
  pp. 39-42, Table 25, prefix dgj
  (verify free), audit "R623 OA
  samurai audit", include after rules/
  oaninja.h.
- R623 LANDED 2026-10-18: commit
  666c85abf6e556a7e86397ed8caf700d09342c76
  (census 545 -> 546, pushed
  7efe429..666c85a), THE SAMURAI, capture
  pp. 39-42: rules/oasamurai.h, prefix
  dgj (verified free), 76 inlines (45
  consts, 27 bools, 4 table columns):
  the Str/Wis/Con 13 and Int 14 minima
  with the fighter tables, the d10
  doctrine with the five slots and the
  MANDATORY KATANA specialization (the
  only two-weapon class - katana and
  daikyu), the caste birth doctrine (the
  +10 Table 38 bonus, the korobokuru
  sponsor rule with the bushi limbo),
  the proficiency deadlines (horsemanship
  2nd, bow 3rd, the three arts 6th), the
  ki power (Str 18/00, one round, level
  per day) and the GREAT KIAI (9th, two
  rounds, the 10-ft paralyzation, once
  daily, never with the ki), the damage
  ladder (+1 at 2nd, one per three
  beyond), the 1-in-6 surprise at 3rd,
  the fear immunity at 5th, the
  appearance fear at 6th, the jito (7th,
  the quarter tax, 10 bushi plus 1-4
  samurai) and shugo (8th, 10d10 bushi,
  the 20 percent ninja infiltrator, one
  per household) stewardships, the 9th
  followers (2d10 samurai, the 2-7
  specialists, the 10 percent spy), the
  bushido precepts, the ronin with the
  2-times xp and the return path, T25
  12x4 (xp bounds, accumulated d10, the
  9-plus-N hp cells - 2 hp beyond 10th -
  the damage ladder). THE T25 GRID SAT
  AS AN EXTRACTED IMAGE in the first
  capture - the cells pin from the
  page-40 continuation, with the 2018
  print confirming every cell and the
  header (10-sided dice). OCR
  normalization: 2d level reads as 2nd
  level; a fitting homes reads as a
  fitting home (prose only). Battery
  120 mutants, 0 missed; full sha
  rverify GREEN. Gap census 43/192 ->
  45/190. Spec 33,806 bytes md5
  51c8f8158fa739d93320fff32ce77ebb
  (canvas md5
  e9ff1694f9e97d008bc68b242ed5bc5d).
  NEXT - R624: the Shukenja, capture
  pp. 42-45, Tables 26, 27 and 28,
  prefix dgk (verify free), audit "R624
  OA shukenja audit", include after
  rules/oasamurai.h.
- R624 LANDED 2026-10-18: commit
  7bbb728da165260b0eb07f84aa32dd9d44b943c1
  (census 546 -> 547, pushed
  666c85a..7bbb728), THE
  SHUKENJA, capture pp. 42-45:
  rules/oashukenja.h, prefix dgk
  (verified free), 63 inlines (31
  consts, 19 bools, 13 table columns):
  the Wis 12 and Str/Con 9 minima
  with the Wis-plus-Con-15 xp bonus,
  the good-alignment requirement, the
  d6 doctrine with the six slots (two
  weapons, religion, calligraphy), the
  cleric tables with the studded-
  leather cap, the three-part training
  (the 5-percent-per-level curse
  ladder, the 75-square-foot sanctify
  circle, the 2-to-1 meditation, the
  free style), the +3 ki save usable
  level times per day before the die,
  the ethos xp rules (half for the
  defeated, full for evil spirits,
  donated treasure only, the 100 xp
  healing award), the no-meat and
  behavior restrictions, the family
  severance, T26 12x3, T27 10x2 with
  the CUMULATIVE SPELL-BONUS CODES
  (none through 12, one 1st at 13-14,
  one 2nd at 15-16, one 3rd at 17, one
  4th at 18) and the failure ladder 20
  down to 0 with the Wis 17/18 spell
  minima footnoted, T28 29x7 with the
  dashes pinned as zeros. TWO
  OCR-MANGLED T26 BOUNDS SETTLED
  AGAINST THE 2018 PRINT BEFORE
  PINNING: row 1 = 1,250 (the capture
  prints 0-1 250) and row 12 =
  1,200,000 (the capture prints
  1,200,00). OCR normalization:
  minimum scares reads as minimum
  scores; principal attitude reads as
  principal attribute; t has failed
  reads as it has failed (prose
  only). Battery 310 mutants, 0
  missed; full sha rverify GREEN. Gap
  census 45/190 -> 49/186. Spec 32,144
  bytes md5
  224708f952814b8b48cc0a781322f3d3
  (canvas md5
  95519e73f67e3c1acfa4923b02aadc01).
  NEXT - R625: the Sohei, capture
  pp. 45-47, Tables 29 and 30, prefix
  dgl (verify free), audit "R625 OA
  sohei audit", include after rules/
  oashukenja.h.
- R625 LANDED 2026-10-18: commit
  9204c4c58ed247ce08775d243de60aeddbfa58bd
  (census 547 -> 548, pushed
  7bbb728..9204c4c), THE SOHEI, capture
  pp. 45-47: rules/oasohei.h, prefix
  dgl (verified free), 53 inlines (33
  consts, 12 bools, 7 table columns):
  the Str 13 and Wis/Con 10 minima
  with the Str-plus-Wis-15 dual-prime
  bonus, the lawful requirement
  independent of the monastery, the
  d10 doctrine with any armor and
  four slots, the cleric tables, the
  shukenja spell gate with the Table
  27 bonuses and failure, the weapon
  of choice, the BERSERK KI at 3rd
  (one turn, once daily, the extra
  attack, the AC/move/hit/save riders,
  the missile deflection), the
  5th-level FANATICISM (fighting to
  -10 with the +2 reserves, then
  death, posthumous honor), the
  6th-level command (10-30 sohei,
  plus 10 per level above 6th,
  replaceable, lost only if all
  slain), the 9th-level commission,
  the less-strict rules (the fish
  rider, the monastery-cause xp), the
  caste and honor doctrine, T29 12x3,
  T30 25x4 with row 0 as the printed
  levels 1-5 blank row (row k is
  level k plus 5) and the dashes
  pinned as zeros. TWO CELLS SETTLED
  AGAINST THE 2018 PRINT BEFORE
  PINNING: the T29 row-4 level cell
  (the capture prints 3 against four
  dice - the 2018 prints 4); the
  fanaticism roll bonus (the capture
  prints +2, KEPT - the 2018 minus 2
  is a lost plus against the sustain-
  himself reading). OCR normalization:
  1stlevel reads as 1st-level (prose
  only). Battery 182 mutants, 0
  missed; full sha rverify GREEN. Gap
  census 49/186 -> 52/183. Spec 26,919
  bytes md5
  cd6733ac0ae78c0b909e0a5708e3c873
  (canvas md5
  2623dc770b5010570b04474e54793724).
  NEXT - R626: the Wu Jen, capture
  pp. 47-51, Table 31, prefix dgm
  (verify free), audit "R626 OA wu
  jen audit", include after rules/
  oasohei.h.
- R626 LANDED 2026-10-18: commit
  5f23689fda6387c0a263f0dd0220183ce5b706a6
  (census 548 -> 549, pushed
  9204c4c..5f23689), THE WU JEN, capture
  pp. 47-51: rules/oawujen.h, prefix
  dgm (verified free), 60 inlines (31
  consts, 14 bools, 15 table columns):
  the Int 13 minimum with the Int-15 xp
  bonus, the NEVER-LAWFUL rule, the d4
  plus 1-per-die doctrine (2-5 hp per
  level), the magic-user tables, the
  favored weapon +1, six slots, the
  UNDERSTAND/KNOW/MEMORIZE doctrine
  with the Int-loss recheck and the
  destroyed scroll, the two ki powers
  (the +3 initiative burst once daily;
  the 4th-level MAXIMUM-EFFECT power,
  any spell three-plus levels lower,
  max range, duration and effect), the
  ELEMENTAL MASTERY (five groups, -1
  enemy saves, +1 damage, +1 own saves,
  lost on new spell levels), the 1d4
  pupils at 10th leaving at half the
  master level and replaced, the
  stronghold-with-lieutenant rule, the
  tengu/oni language with the +20
  reaction, the no-family and light-
  honor doctrine, the taboo ladder
  (one at 1st, one per five levels),
  T31 11x3, T32 7x3 with the printed
  All maximum pinned as the -1 code,
  T33 29x9 with the dashes as zeros.
  THREE CELLS SETTLED AGAINST THE 2018
  PRINT BEFORE PINNING: the T31 row-2
  bound 4,000 (the capture lost the
  comma); the T33 row-5 first-spell
  cell 3 (the capture prints 4 - the
  ladder-consistent reading stands);
  the T33 row-22 ninth-spell cell 1
  (the capture prints 2 - same
  doctrine). OCR normalization:
  konobokuru reads as korobokuru; in
  hit, spell book reads as in his
  spell book; cloud/adder reads as
  cloud ladder (prose only). Battery
  360 mutants, 0 missed; full sha
  rverify GREEN. Gap census 52/183 ->
  56/179. Spec 30,674 bytes md5
  716cd27ccc5e0384d110f565ffd8aa4b
  (canvas md5
  c1661af5761352ffd1951e682237368d).
  NEXT - R627: the Yakuza, capture
  pp. 51-54, Tables 34 and 35, prefix
  dgn (verify free), audit "R627 OA
  yakuza audit", include after rules/
  oawujen.h.
- R627 LANDED 2026-10-19: commit
  db94e62fd73176ba4f77cba6dbda777e63f4a535
  (census 549 -> 550, pushed
  5f23689..db94e62), THE YAKUZA, capture
  pp. 51-54: rules/oayakuza.h, prefix
  dgn (verified free), 62 inlines (36
  consts, 21 bools, 5 table columns):
  the Str 11/Int 15/Dex 15/Cha 16 minima
  with no prime requisite, the ALWAYS-
  LAWFUL rule, the d6 with the thief
  tables, any weapon with the Table 13
  armor and no shields, the family-clan
  requirement with the -5 birth
  modifier, three slots plus the free
  gaming proficiency, the thief skills
  at the ninja chances with hear noise
  as monk, the investigate tiers
  (common 1 day/2d6 fen always
  accurate; uncommon 1-3 days/2d4 yuan
  10 percent; confidential 2d6 days/
  2d10 tael 25 percent; secret 3d6
  days/2d10 ch'ien 40 percent), never
  magical or legendary, the contacts
  doctrine (one per two levels, never
  more than four levels above), the ki
  halves-damage power (round up, once
  per round, level times per day), the
  +10 percent reaction bonus except
  social-status rolls, the adoption
  into the kumi without the Table 39/40
  rolls, the Zingi family honor with
  the 2-ch'ien-per-level monthly
  stipend, the kyodai-bun brethren from
  2nd level (one per level, at least
  one level beneath, never above 8th,
  major enterprises need oyabun
  approval), the tattoos-per-level rule,
  the cast-out non-person doctrine with
  regainable membership, T34 12x3 with
  the 9-plus-N cells and the
  300,000-xp/1-hp notes, T35 21x2 with
  the area covered pinned as the 1-9
  code (1/2/3 blocks; 1 ward 4; 2
  wards 5; 1 district 6; 2 districts 7;
  3 districts 8; province 9). NO
  CONTESTED CELLS THIS ROUND - both
  captures agree on every pinned value.
  OCR normalization: Zing reads Zingi;
  2d level reads 2nd level; hide-out
  and hideout both printed. Battery 135
  mutants, 0 missed; full sha rverify
  GREEN. Gap census 56/179 -> 59/176.
  Spec 29,495 bytes md5
  e2cd4461c78bc8f9fedea94daaf7b701
  (authored-plus-newline md5
  0798e57f3ca5372eec3b2eb9d21f0427;
  canvas md5
  1acd67aa889fd699c3667ff5bccdea5a).
  NEXT - R628: the Character Abilities
  chapter opener, capture pp. 55-59,
  Tables 36 (Multiple Attacks), prefix
  dgo (verify free), audit "R628 OA
  character abilities audit", include
  after rules/oayakuza.h.
- R628 LANDED 2026-10-19: commit
  1b788fead1df9e688032cc6327bbe177b41630c7
  (census 550 -> 551, pushed
  db94e62..1b788fe), THE CHARACTER
  ABILITIES chapter opener, capture
  pp. 55-59: rules/oacharab.h, prefix
  dgo (verified free), 47 inlines (10
  consts, 32 bools, 5 table columns):
  the multiple attacks doctrine (beyond
  fighters, melee only, ninja-weapons
  only with no carry from the other
  class, the proficiency boost, the
  one-per-level versus under-1-HD
  monsters, the split-between-targets
  rule, the 1/1, 3/2, 2/1 and kensai
  5/2 notation read), the dual-class
  doctrine (human only, the 15-in-old
  and 17-or-18-in-new requisites, any
  level, the kept old abilities with
  the xp-to-new-class rule, the
  no-hp-until-surpass rule, the
  restrictions binding until surpass,
  the old-use xp forfeiture, the best
  combat and save tables, the free mix
  after surpass, the weapons
  exception), the alignment doctrine
  (nine alignments, not religion, law
  most common in Kara-Tur, the
  complementary-party encouragement),
  the languages (the home/trade/
  alignment slot ladder, the
  potential-only Table 5 count, the
  75/50 dialect and wild-land
  comprehension, the trade-language
  limits, the 20-minus-Int study
  months with the every-other-day
  doubling and the native-speaker
  halving, the permanent accent), T36
  19x5 with the class column as the
  1-6 code (bushi, kensai, ninja,
  barbarian, samurai, sohei), the
  printed "and up" bands as the -1
  code and the N/D rates as the
  numerator and denominator columns.
  NO CONTESTED CELLS THIS ROUND -
  both captures agree on every pinned
  value. OCR normalization: "lying and
  yang" reads as yin and yang (prose
  only); the ninja asterisk footnote
  appears twice in the second capture
  (the printed footnote stands).
  Battery 137 mutants, 0 missed; full
  sha rverify GREEN. Gap census
  59/176 -> 64/171. Spec 27,422 bytes
  md5 1d6910fd6fa19e0f36883084f43f9c62
  (authored-plus-newline md5
  26e807e289fbdfd705d5c8d643243a33;
  canvas md5
  704d722c51a595c531f657ee44e7ea2d).
  NEXT - R629: the Chapter 3 opener,
  the birth rank prose and the caste
  doctrine, capture pp. 60-62, Table
  37 (Birth Requirements by Class) and
  Table 38 (Character Birth), prefix
  dgp (verify free), audit "R629 OA
  families audit", include after
  rules/oacharab.h.
- R629 LANDED 2026-10-19: commit
  681a99f54cf86a496ac25f9d008ffb438c7b4ba8
  (census 551 -> 552, pushed
  1b788fe..681a99f), THE CHAPTER 3
  opener - the family doctrine, the
  birth rank and the caste doctrine,
  capture pp. 60-62: rules/oabirth.h,
  prefix dgp (verified free), 35
  inlines (10 consts, 12 bools, 10
  table columns): the family doctrine
  (all relations, the ancestors-add-
  honor rule, the adopted-profession
  classes, the shukenja severance),
  the 2d10 birth roll, the NPC
  reaction read (the base-score
  difference as a plus-or-minus, the
  -25 Chang Lui example), the
  family-not-character honor column,
  the korobokuru samurai lowest-rank
  rule with the ninja automatic clan,
  the family structure doctrine (the
  three-row chart, the 1d8 spaces per
  row, the head at position 1, the 70
  percent male chance, the family-
  name-first rule), T37 9x3 with the
  samurai +10 and yakuza -10 birth
  modifiers and the 0/1 requirement
  codes, T38 17x7 with the rank codes
  0-16, the 5-90 reaction scores, the
  ancestry and birthright die codes
  and the 0-35 family honor. ONE
  CONTESTED CELL SETTLED AGAINST THE
  2018 PRINT BEFORE PINNING: the T38
  row-27 ancestry cell d100/8 (the
  first capture printed d100/9). THE
  R629a LESSON: the first run mispinned
  the T38 row count as 18 (17 printed
  rows) and the PREFLIGHT BATTERY
  caught bad 14 - the emitted C++
  audit loop bounds by the count const
  while the expected grid holds the
  data rows, so an inflated count walks
  the sentinel default past the grid
  edge; the Python mirror misses it
  (speclib bounds by len(data)). THE
  GUARD: every gen script now asserts
  each count const equals its grid
  row count. The run-2 abort (the
  missing T38 flip anchor) was run-1
  residue - a RED preflight leaves the
  applied edits in the tree, so a
  retry needs git checkout of the four
  touched files plus rm of the run-1
  header first. Battery 171 mutants, 0
  missed; full sha rverify GREEN;
  preflight GREEN after the fix. Gap
  census 64/171 -> 67/168. Spec 21,576
  bytes md5 5a80540e1f5a8ec91b678985cd
  9df92a (authored-plus-newline md5
  95bdb513386a5d3bf2c56c18e8d08dd3;
  canvas md5
  2a9640fb440f641fe3fb2284ba8f5b7e).
  NEXT - R630: the Family Structure
  and Additional Family Structures
  prose, capture pp. 62-64, the family
  chart rows with the honor-by-
  position doctrine, prefix dgq (verify
  free), audit "R630 OA family
  structures audit", include after
  rules/oabirth.h.
- R630 LANDED 2026-10-19: commit
  9fbb97306d976609d17d947c15ed5f0411ef00b6
  (census 552 -> 553, pushed
  681a99f..9fbb973), THE FAMILY
  STRUCTURE prose - the additional family
  structures, capture pp. 62-64:
  rules/oafamstr.h, prefix dgq
  (verified free), 37 inlines (14
  consts, 23 bools, no tables): the
  1d8-minus-2 children per space with
  the direct-branch-only charts and
  the lineage die rules (closest
  without being less, reroll the
  overflow), the optional marriages
  (the 1-5-on-1d6 read, the PC females
  never required, the usually-outside-
  clan and equal-rank doctrine, the
  +10 percent reaction bonus), the
  adoptions (the 1-in-20 entry chance,
  the 1-2 orphan read, the two-clan
  doctrine, the political cross-rank
  pattern, the +10 percent bonus),
  the polygamy doctrine (legal and not
  unknown, mostly monogamous, the
  grandfather-or-father rule, the
  first-wife inheritance with the
  first-son-of-first-wife rule), the
  further generations with no
  reaction modifiers, the interrelated
  player characters (the DM approval,
  same race with the barbarian and
  samurai matches, same birth rank and
  Head-of-Family spaces, twins-only
  for the same slot, the shared
  ancestry with identical holdings
  and names), the deaths ladder (the
  once-per-year check, the 10/7/5 row
  chances, the 75 percent firstborn
  pass, the head-title succession),
  the player-character re-entry at
  1st level. PINNED FROM THE 2018
  PRINT CAPTURE ALONE - the first
  Mistral-OCR capture session is no
  longer available above p. 33, so
  the cross-capture agreement check
  is impossible for this range (no
  tables, no contested cells; the
  cites span the capture pp. 62-64
  range). OCR normalization:
  splinterhood reads as spinsterhood;
  the deaths bad-feelings sentence
  appears twice in the 2018 print.
  The Master Family Chart prose
  (capture pp. 64-65) is deliberately
  held for the next round. Battery 37
  mutants, 0 missed; full sha rverify
  GREEN. Gap census 67/168 -> 68/167.
  Spec 20,565 bytes md5
  4ec49fb4de7359113d60684f2dc0be09
  (authored-plus-newline md5
  213883ad3ebbd1419f4fa3ab4292e994;
  canvas md5
  d07aecf19cdab317b624270c0aa1c15c).
  NEXT - R631: the Master Family
  Chart and Ancestry prose, capture
  pp. 64-65, Table 39 (Ancestry),
  prefix dgr (verify free), audit
  "R631 OA ancestry audit", include
  after rules/oafamstr.h.
- R631 LANDED 2026-10-19: commit
  f0a630e9d7907375267d65357683c9c90a8d4fc8
  (census 553 -> 554, pushed
  9fbb973..f0a630e), THE MASTER FAMILY
  CHART and ANCESTRY, capture pp. 64-65:
  rules/oaanc.h, prefix dgr (verified
  free), 29 inlines (13 consts, 12
  bools, 4 table columns): the master
  family chart doctrine (the DM chart of
  names, birth ranks, honor, alliances
  and relationships, the emperor at the
  center, the rank-by-distance
  doctrine, the line codes - dashed
  marriage, solid blood, dotted allies,
  arrows enemies), the ancestry doctrine
  (the beyond-ancestors read with the
  cooperative detail, the HONOR-ADDS-
  TO-BIRTH rule, the +20 percent
  alliance and -40 percent feud
  modifiers, the 1-3 social-level
  advantageous marriage, the 10-to-2,000
  property income, the 100-to-1,000
  estate and fleet incomes, the 2-5
  ships, the moneylender extra roll, the
  hereditary-title succession, the
  secret-society contacts, the tragic
  honor, the roll-again doctrine - the
  next larger die, or add 10 at d100),
  T39 46x4 with the die bands pinned as
  the lo and hi bounds (contiguous 1
  through 100, asserted in the gen
  script), the honor column -20 to +15
  and the ancestry results as the 0-34
  code with the roll-again rows at 6,
  10, 20 and 97. PINNED FROM THE 2018
  PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check);
  no contested cells within the single
  source. OCR normalization: the T39
  classic artist reads as the prose
  classical artist; rows 6, 10 and 20
  read "next higher die or + 10" while
  row 97 reads "+ 10 on die roll" (both
  pin as the roll-again code). The
  Assigning Ancestral Holdings and
  Birthrights prose (capture pp. 67-69)
  is deliberately held for the next
  rounds. Battery 209 mutants, 0 missed;
  full sha rverify GREEN; preflight
  GREEN. Gap census 68/167 -> 71/164.
  Spec 20,324 bytes md5
  3335a22b665aca2e7e9f8f1f5be14759
  (authored-plus-newline md5
  29e19f36ed4c96545d0496bb99ffd4d3;
  canvas md5
  7c91f65d18517fe380f3744904bd64a3).
  NEXT - R632: the Assigning Ancestral
  Holdings prose, capture pp. 67-68, the
  head-of-family rule and the NPC-only
  holdings, prefix dgs (verify free),
  audit "R632 OA holdings audit",
  include after rules/oaanc.h.
- R632 LANDED 2026-10-19: commit
  bb00f5aeca9115cc74140583b9c06e63b30130d7
  (census 554 -> 555, pushed
  f0a630e..bb00f5a), THE ASSIGNING
  ANCESTRAL HOLDINGS prose, capture pp.
  67-68: rules/oahold.h, prefix dgs
  (verified free), 11 inlines (11
  bools, no consts, no tables): the
  holdings as the Table 39 property
  results, the automatic NPC ownership
  (never the player character or his
  siblings at career start), the first
  holding to the head of the family,
  the dice-assigned remainder to the
  Head of Family and Father rows by
  the position-determination method,
  the overflow roll to the head, the
  no-automatic-use doctrine (the owner
  permission with the reaction roll and
  the DM refusal). PINNED FROM THE
  2018 PRINT CAPTURE ALONE (the
  settling authority; the first
  Mistral-OCR capture session is
  unavailable above p. 33, so no
  cross-capture check); a pure-prose
  round - no tables, no numeric cells,
  no contested cells. The Birthrights
  prose and Table 40 (capture pp.
  68-69) are deliberately held for the
  next round. Battery 11 mutants,
  0 missed; full sha rverify GREEN;
  preflight GREEN. Gap census 71/164
  -> 72/163. Spec 9,529 bytes md5
  42a8e92c5c7080d9f1544b4f19eb06c5
  (authored-plus-newline md5
  96997b261d2b2b64e2ceabe69fbc5364;
  canvas md5
  4badf29668205d71be12b47e077c961c).
  NEXT - R633: the Birthrights prose
  and Table 40, capture pp. 68-69, the
  property-share, heirloom and
  cash-string doctrines, prefix dgt
  (verify free), audit "R633 OA
  birthrights audit", include after
  rules/oahold.h.
- R633 LANDED 2026-10-19: commit
  91502ba33b87772847a90b3ca77ace2fa69ae287
  (census 555 -> 556, pushed
  bb00f5a..91502ba), BIRTHRIGHTS and
  TABLE 40, capture pp. 68-69:
  rules/oabr.h (oabirth.h is taken by
  R629), prefix dgt (verified free), 30
  inlines (6 consts, 20 bools, 4 table
  columns): the clan-virtue doctrine
  (the shared ownership with the death
  return to the clan and the
  lost-birthright honor loss), the T38
  die and roll doctrine with the
  birth-rank subtraction (the first son
  subtracts one), the personal honor
  read, the 10-to-30 percent property
  share from the father, grandfather
  and head-held lands with the single-
  property 30 percent cap and the
  no-property read, the 100-coin cash
  strings, the heirloom transfer ban
  (the DM armor, the player weapon),
  the +2 magical weapon with the great
  honor loss on losing it, the roll-
  again doctrine, T40 26x4 with the die
  bands pinned as the lo and hi bounds
  (contiguous 1 through 100, asserted
  in the gen script), the personal
  honor column 0 to +4 and the results
  as the 0-11 code with the roll-again
  rows at 4, 7 and 100. PINNED FROM THE
  2018 PRINT CAPTURE ALONE (the
  settling authority; the first
  Mistral-OCR capture session is
  unavailable above p. 33, so no
  cross-capture check); no contested
  cells within the single source. OCR
  normalization: the print
  capitalization varies (Property Share
  at 6 and 17-18, Property share at 8,
  41-45 and 56-60) - all pin as the
  same codes; rows 4 and 7 read "next
  higher die or + 10" while row 100
  reads "with + 10 on die roll" (both
  pin as the roll-again codes 1 and 11).
  The Chapter 4 Honor prose (capture
  pp. 69-73) is deliberately held for
  the next rounds. Battery 130 mutants,
  0 missed; full sha rverify GREEN;
  preflight GREEN. Gap census 72/163
  -> 74/161. Spec 19,617 bytes md5
  fcd1423440807b7fe9b2fe71abc46fed
  (authored-plus-newline md5
  560ac8bba857a9382122a257470366ab;
  canvas md5
  cf99a563f079836d6ac8b17d43c51b2b).
  NEXT - R634: the Honor chapter
  opener, the Gaining and Losing Honor
  prose and Table 41 (Initial Honor),
  capture pp. 69-70, prefix dgu
  (verify free), audit "R634 OA honor
  audit", include after rules/oabr.h.
- R634 LANDED 2026-10-19: commit
  0d6f2cbd6eaf635ab035d2dd9a72bb5c9ead043f
  (census 556 -> 557, pushed
  91502ba..0d6f2cb), HONOR - the
  chapter opener, the starting honor
  doctrine and Table 41, capture pp.
  69-70: rules/oahonor.h, prefix dgu
  (verified free), 21 inlines (2
  consts, 17 bools, 2 table columns):
  the opener doctrine (the family
  reflection with the respect-power-
  influence read, the easier-to-lose
  rule, the dishonor and honor deed
  lists, the reaction and gift
  rewards, the not-alignment read
  with the villain-samurai example,
  the deeds-of-both measure), the
  honor-point tracking (the DM awards
  at the end of an adventure, the
  something-special requirement), the
  starting honor doctrine (the
  birth-rank base with the T39
  adjustments and the 0 floor, the
  birthright and lowest-ability adds,
  the no-clan T41 route), the class
  sensitivity (the samurai
  fluctuation), the DM-judgment
  doctrine with the 100-point cap,
  T41 7x2 with the class rows pinned
  as the base-honor lo and hi bounds
  (shukenja 20, sohei 15, kensai 25,
  bushi 10, hengeyokai 10, wu jen 15,
  the yakuza 1d20 + 20 read as 21
  through 40). PINNED FROM THE 2018
  PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check);
  no contested cells within the single
  source. OCR normalization: none
  required for this range beyond the
  yakuza die read; the opener prose
  carries the printed em dashes. The
  Altering Family Honor and Effects of
  Honor prose and Table 42 (capture
  pp. 70-72) are deliberately held
  for the next rounds. Battery 33
  mutants, 0 missed; full sha rverify
  GREEN; preflight GREEN. Gap census
  74/161 -> 76/159. Spec 15,477 bytes
  md5 cd219445dfdc1bcf03f785201b500453
  (authored-plus-newline md5
  16f0501e89f072817b1e97d52c01765b;
  canvas md5
  599d497bea98244472a054c5b2033fef).
  NEXT - R635: the Altering Family
  Honor prose and the Effects of Honor
  prose with Table 42, capture pp.
  70-72, the family ledger and the
  reaction doctrine, prefix dgv
  (verify free), audit "R635 OA
  effects of honor audit", include
  after rules/oahonor.h.
- R635 LANDED 2026-10-19: commit
  6d3f2b767d379c76eb5e2b7179ea6cd950dbf6b4
  (census 557 -> 558, pushed
  0d6f2cb..6d3f2b7), ALTERING FAMILY
  HONOR, THE EFFECTS OF HONOR and
  TABLE 42, capture pp. 70-72:
  rules/oaeff.h, prefix dgv (verified
  free), 41 inlines (19 consts, 20
  bools, 2 table columns): the family
  ledger (the 10-point raise step with
  the +1 raise, the once-per-group
  bonus, the pinnacle read, the
  5-point single-action blot with the
  -1 family loss, the shared family
  change), the effects doctrine (the
  below-zero elimination with the
  crumpled sheet, the samurai-ronin
  and kensai-bushi status loss, the
  -20 percent family modifier, the +5
  percent per 10 with the harder-to-
  impress read, the 75-point gift,
  the 80-point songs with the 10
  percent weekly boasts and the -10
  refusal loss, the 90-point lord
  invitation with the -10 percent
  refusal penalty, the 95-point great
  hero with the +10/-10 read, the
  successor bonus with the divide-by-
  10, the 3-point cap and the any-
  race-class-family freedom), T42 68x2
  across the ten sections (all
  characters, shukenja, hengeyokai,
  kensai, ninja, samurai, sohei,
  spirit folk, wu jen, yakuza) with
  the points and mark columns (the
  five samurai-doubled stars, the
  single-creature double star), the
  monsters -1 per 2000 x.p. and the
  stolen-goods +1 per 100 ch'ien rate
  consts, the kensai once-per-level
  duel rule. PINNED FROM THE 2018
  PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check);
  no contested cells within the
  single source. OCR normalization:
  the double-star footnote reads
  "defeating a single-creature" with
  a printed em dash (pins as single-
  creature); the awards use the
  printed x.p. abbreviation. The
  Chapter 4: Honor parent box closes
  this round (all five honor boxes
  pinned). Battery 175 mutants,
  0 missed; full sha rverify GREEN;
  preflight GREEN. Gap census 76/159
  -> 80/155. Spec 27,392 bytes md5
  4d54f2eef7e60d1948dc261cb36e5515
  (authored-plus-newline md5
  da23d66c10eb7638973e3fb6a20ce480;
  canvas md5
  ec0c30b55a014671fd99b5af2725937a).
  NEXT - R636: the Chapter 5 Money and
  Equipment opener, the Currency prose
  with Table 43 (Currency Values) and
  Table 44 (Barter Units), capture
  pp. 73-75, prefix dgw (verify
  free), audit "R636 OA money audit",
  include after rules/oaeff.h.
- R636 LANDED 2026-10-19: commit
  482dad2bf247794c9abfa32c3bb33c617e51e610
  (census 558 -> 559, pushed
  6d3f2b7..482dad2), MONEY - the chapter
  opener, the currency systems and Tables
  43-44, capture pp. 73-75:
  rules/oamoney.h, prefix dgw (verified
  free), 32 inlines (17 consts, 13
  bools, 2 table columns): the gold-not-
  currency read (copper, silver and
  paper; gold reserved for art and
  craft), the pierced coins threaded on
  the 50-to-100 cash strings tucked in
  the sleeve, the paper ch'ao with the
  one-ten-100 notes and the 100-fen
  preference, the hoarded ch'ien, the
  noble-spending opener, the four
  monetary systems (established, regular,
  irregular, pure barter) with the Shou
  Lung-to-barbarian spread and the DM
  choice, the barter-unit doctrine with
  the quality-varying value, T43 as the
  coin-value consts (the yuan 5 fen, the
  ch'ao 100 fen or 20 yuan, the tael 100
  fen, 20 yuan or 1 ch'ao with the
  ch'ao-tael equality, the ch'ien 1000
  fen, 200 yuan, 10 ch'ao, 10 tael), T44
  5x2 (the koku 5 ch'ien, the sheep or
  goat 5 tael, the horse 2 ch'ien, the
  common and silk bolts 1 and 3 ch'ien)
  with the koku 5-to-6 bushels and the
  20-yard bolts. PINNED FROM THE 2018
  PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check); no
  contested cells within the single
  source. OCR normalization: the systems
  prose reads "[x]" placeholders for the
  printed blanks - they pin nothing
  numeric. The Chapter 5: Money and
  Equipment parent box opens this round
  (the first pinned child). Battery 40
  mutants, 0 missed; full sha rverify
  GREEN; preflight GREEN. Gap census
  80/155 -> 84/151. Spec 20,744 bytes
  md5 59e3027a1b995ca357186a521c29ee46
  (authored-plus-newline md5
  88df185eb7a7f1cfdaf27e861e9ccb25;
  canvas md5
  40c8004e2fbeb786ba377a3ee5d55b0b).
  NEXT - R637: the Starting Money prose
  and Table 45 (Initial Character
  Funds), capture pp. 75-76, the class
  funds dice, prefix dgx (verify free),
  audit "R637 OA starting money audit",
  include after rules/oamoney.h.
- R637 LANDED 2026-10-19: commit
  1cd70755ae0991a0d8381646c02e37f01d68d2ed
  (census 559 -> 560, pushed
  482dad2..1cd7075), STARTING MONEY - the
  class funds dice and Table 45, capture
  pp. 75-76: rules/oastart.h, prefix dgx
  (verified free), 13 inlines (1 const
  dgxT45RowCount=10, 4 bools, 8 table
  columns): the Starting Money opener
  with the roll-your-funds doctrine, T45
  as the 10 class rows x 8 lo-hi bound
  pairs over the chien, tael, yuan and
  fen components (0-0 pins no such
  component for the class), row codes
  0-9: samurai, shukenja, monk, sohei,
  kensai, barbarian, bushi, wu jen,
  ninja, yakuza, the tael column reading
  as (ch'ao), the ninja no-armor-footnote
  pinned as a bool. PINNED FROM THE 2018
  PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check); no
  contested cells within the single
  source. OCR normalization: none
  material this round. The Gajin and
  Rates of Exchange prose with Table 46
  deliberately left for R638. Battery 85
  mutants, 0 missed; full sha rverify
  GREEN; preflight GREEN. Gap census
  84/151 -> 86/149. Spec 11,765 bytes
  md5 812398901ee3f6a34e8bc59958e67f61
  (authored-plus-newline md5
  27ec6de4b594ea96966b3bce13372da7;
  canvas md5
  4784ddeba4b602cc2a69773e397a1333).
  NEXT - R638: the Gajin and Rates of
  Exchange prose with Table 46 (Currency
  Exchange Rates), capture pp. 76-77,
  the real-value and exchange-rate
  doctrine, prefix dgy (verify free),
  audit "R638 OA exchange audit",
  include after rules/oastart.h.
- R638 LANDED 2026-10-19: commit
  6580845aae3991ceb742dc6190e5e89ced932de8
  (census 560 -> 561, pushed
  1cd7075..6580845), EXCHANGE - the gajin
  rates and Table 46, capture pp. 76-77:
  rules/oaexch.h, prefix dgy (verified
  free), 27 inlines (9 consts, 14 bools,
  4 table columns): the gajin-contact
  exchange need, the caravan-route and
  trading-port moneylenders, the worthless
  ch'ao with the convert advice, the
  gold-not-currency read with the market
  factors (the flooding read), the
  undesired foreign silver, the standard
  copper (one fen per two coppers), the
  export smuggling offense, the Kara-Tur
  coins accepted abroad, the coin
  speculation, the prose street rates
  (the fen one cp, the yuan one cp, the
  tael 4-14 sp as 2d6-2, the gold 2-7
  tael, the silver 1d6+7 fen - the OCR
  "(1d6 - 7)" dash read), T46 as the 9x4
  grid (the fen-based real values with
  every printed multi-value cell agreeing
  in fen, the per-row exchange lo-hi
  bounds, the market-value flags on the
  electrum, gold and platinum rows), the
  notes doctrine (real value, exchange
  value, market price). PINNED FROM THE
  2018 PRINT CAPTURE ALONE (the settling
  authority; the first Mistral-OCR
  capture session is unavailable above
  p. 33, so no cross-capture check); the
  prose street rates and the T46 standard
  rates differ as printed (the yuan one-cp
  street rate vs the five-cp real value,
  the tael 4-14 sp street fetch vs the
  2-12 standard) - both pinned. The
  Equipping the Character prose with
  Table 47 deliberately left for R639.
  Battery 59 mutants, 0 missed; full sha
  rverify GREEN; preflight GREEN. Gap
  census 86/149 -> 88/147. Spec 18,652
  bytes md5 cd6919255dceb0ce362d4ad255befc80
  (authored-plus-newline md5
  d28a57a113096f414a0bf7338760fb7e;
  canvas md5
  4c5d79325b6247796d0b08135ef5ec64).
  NEXT - R639: the Equipping the
  Character prose with Table 47 (Basic
  Equipment and Supplies Cost), capture
  pp. 77-84, the eight cost lists, prefix
  dgz (verify free), audit "R639 OA
  equipment audit", include after
  rules/oaexch.h.
- R639 LANDED 2026-10-19: commit
  f81fe22d0c20e2e355e596145d3e4c008ae2ac7f
  (census 561 -> 562, pushed
  6580845..f81fe22), EQUIPMENT - the
  equipping doctrine and Table 47, capture
  pp. 76-78: rules/oaequip.h, prefix dgz
  (verified free), 50 inlines (11 consts,
  30 table columns, 9 bools): the
  equipping prose (equip-after-creation,
  the not-enough-money adventuring
  reason, the established-currency prices,
  the barter purchase, the incomplete
  list with DM additions, the price
  changes, the area availability), T47
  as the ten printed cost sections - all
  256 rows pinned as cost-unit-star
  triples (the unit code 1 fen, 2 yuan,
  3 tael, 4 ch'ien per the T43 doctrine;
  the star flags pin the printed
  asterisks - the ten armor-piece rows,
  the chijiriki, the five ninja-preferred
  misc rows), the two footnote bools.
  The printed table carries ten sections
  - the eight cost lists the gap box
  names plus the ARMOR and ARMS lists
  that ride the same table; the box
  label's capture pp. 78-84 preserved
  byte-exact in the flip (the table pins
  from printed pp. 39-40). PINNED FROM
  THE 2018 PRINT CAPTURE ALONE (the
  settling authority; the first
  Mistral-OCR capture session is
  unavailable above p. 33, so no
  cross-capture check). OCR
  normalizations: the Kyoketsu-shogi
  "(biaded rope)" reads as bladed rope,
  the stray mid-table separator row is
  an artifact pinning nothing. REPAIR
  NOTE: the first cut used hyphenated
  table tags (T47-Armor) and died at the
  Termux preflight compile (the Python
  engine and battery never compile the
  audit block); tags renamed CamelCase,
  tree reset, re-landed same round
  (the lesson seated in Verification
  lessons). Battery 788 mutants, 0
  missed; full sha rverify GREEN;
  preflight GREEN on the repair run.
  Gap census 88/147 -> 89/146. Spec
  37,296 bytes md5
  b78271721e82be6466fa960dbb0634dd
  (authored-plus-newline md5
  a8f56281524e9a8425786a97a1b2348d;
  canvas md5
  a9968fb857d09c88ac0faff0e91f8d66).
  NEXT - R640: the Weapons prose with
  Table 48 (Weapon Equivalents) and
  Table 49 (Weight and Damage by Weapon
  Type), capture pp. 79-80, the weapon
  equivalents doctrine, prefix dha
  (verify free), audit "R640 OA weapons
  audit", include after rules/oaequip.h.
- R640 LANDED 2026-10-19: commit
  baac37c95564540d3dd84ab9f6064ead6a93c888
  (census 562 -> 563, pushed
  f81fe22..baac37c), WEAPONS - the
  chapter opener with the
  weapon-equivalents prose, Table 48
  (Weapon Equivalents) and Table 49
  (Weight and Damage by Weapon Type),
  capture pp. 79-80: rules/oaweapon.h,
  prefix dha (verified free), 26
  inlines (2 consts, 10 table columns,
  14 bools): the equivalents doctrine
  (the English names, the many-names,
  the appearance-differs/function-same
  rule), the boldface note (the
  boldface set itself lost to OCR),
  the star-set note, the eight
  footnotes a-h, T48 as 16
  equivalent-count rows (the names
  ride the column comment; Axe battle
  11, Dagger/Halberd 4, Spear 1), T49
  as the 69-row weight/damage grid -
  footnote letters as bitmask a=1
  ... h=128 (chain 224, spear 34,
  short sword 132), -99 sentinel for
  the lasso damage dashes and the
  needle's blank vs-L, stars javelin
  19, naginata 36, spear 56, ranges
  spear 40-60, two-handed sword
  150-250 (L 3-18), whip 25-35. The
  footnotes print under T50 on the
  capture page and serve both tables.
  Tags CamelCase (T48Equiv, T49Data)
  per the R639 hyphen lesson; static
  scan of the emitted audit block: 0
  hyphen code tokens. Wrap repair
  pre-publish: the first cut's gap-flip
  annotations were single 201/225-char
  lines violating the gap-report wrap;
  rebuilt via a gap_to() textwrap
  helper in the gen script before
  publish (the user side never saw the
  break). Engine double-run applied 6
  -> already 6; rverify 653 mutants, 0
  missed; preflight GREEN (563 audit
  census, BUILD 0 warnings). Gap
  census 89/146 -> 91/144 (the T48 and
  T49 boxes flip; the
  weapon-descriptions prose box
  capture pp. 84-93 deliberately stays
  open - the descriptions pin later).
  Spec 24,761 bytes md5
  f918ac1b4de364de5244f5f425bc3ed0
  (authored-plus-newline md5
  4ee8116a03cb5a9beee336ceab1d9038;
  canvas md5
  5a9b4d5dfe9718f7244911fbce77c4d9).
  NEXT - R641: Table 50 (Hand Held
  Weapons, General Data and To Hit
  Adjustments), capture p. 80, the
  hand-held AC-adjustment grid, prefix
  dhb (verify free), audit "R641 OA
  handheld audit", include after
  rules/oaweapon.h.
- R641 LANDED 2026-10-19: commit
  739dd573f81b4c839a535ceb98d901e63161de59
  (census 563 -> 564, pushed
  baac37c..739dd57), HAND HELD WEAPONS -
  Table 50 (Hand Held Weapons, General
  Data and To Hit Adjustments), capture
  p. 80: rules/oahandheld.h, prefix dhb
  (verified free), 17 inlines (2 consts,
  14 table columns, 1 bool): the 49-row
  hand-held grid - the speed factor
  bounds (the lone numbers as lo=hi; the
  chijiriki-spear, spear and trident 6-8
  and the whip 5-8 ranges), the
  eleven-column AC 0-10 to-hit adjustment
  ladder, the footnote letters as the
  R640 bitmask (the mace h 128, the
  tetsu-bishi d 8), the chijiriki-chain
  row with the -99 dashes and the
  (see chain) bool, the length and
  space-required cells riding the column
  comments per the T48 doctrine. FIRST
  CROSS-CAPTURE CHECK ABOVE P. 33 (the
  compressed capture OCR'd full this
  turn): the 49-row grid cross-checked
  cell-by-cell between the two passes;
  four cells contest, all settled per the
  print capture - the katana AC-8,
  sword-short AC-8 and tui-fa AC-9 cells
  pin +1 (the compressed -1 dips
  non-monotonically, the R622 doctrine
  kills the class), the jo-stick AC-5
  cell pins -1 (both readings
  ladder-consistent, the settling print
  read stands; flagged for the
  physical-copy check). The footnote
  texts are not re-pinned (the block
  under T50 serves both tables, pinned in
  R640; the d and h lines reprint under
  the T50 tail). Two pre-publish repairs
  the machinery caught: a man-catcher
  transcription slip (the audit-mirror
  sim fired on healthy data - the R391
  gate working as designed), and a
  gap-flip builder bug duplicating the
  box's second label line (caught by
  inspecting the patched gap report; a
  label-uniqueness assert added to the
  builder). rverify GREEN at baac37c,
  689 mutants, 0 missed; preflight GREEN
  (564 audit census, BUILD 0 warnings).
  Gap census 91/144 -> 92/143. Spec
  20,659 bytes md5
  e1bb51477f0b32fc61491f288442251d
  (authored-plus-newline md5
  b16adccc9ff1ad0f869e3f00995ef411 -
  the value the ritual gated and
  matched; canvas md5
  1cf7a2a4fe512c8584b26b2bf035e430).
  NEXT - R642: Table 51 (Hurled Weapons
  and Missiles), capture pp. 80-81, the
  hurled-missile fire-rate and
  AC-adjustment grid, prefix dhc (verify
  free), audit "R642 OA hurled audit",
  include after rules/oahandheld.h.
- R642 LANDED 2026-10-19: commit
  b784a11e74a769a9413c240f29cfc643f5ab6145
  (census 564 -> 565, pushed
  739dd57..b784a11), HURLED WEAPONS AND
  MISSILES - Table 51 (Hurled Weapons and
  Missiles), capture pp. 80-81:
  rules/oahurled.h, prefix dhc (verified
  free), 20 inlines (4 consts, 13 table
  columns, 3 bools): the 28-row hurled grid
  - the eleven-column AC 0-10 to-hit
  adjustment ladder, the -99 sentinels for
  the grenade and metsubishi dash rows, the
  footnote letters as the R640 bitmask (the
  grenade, hankyu and metsubishi d 8, the
  javelin h 128), the star set (metsubishi
  and needle), the fire rates and the
  short/medium/long range bands riding the
  column comments per the T48 doctrine (the
  needle fire rate prints the double star,
  the metsubishi short range prints 3 feet,
  the shuriken-spike and sling-staff
  dashes). The four note lines the print
  pass's OCR dropped entirely were recovered
  from the compressed capture and
  corroborated by the UA sibling doctrine
  (rules/uamissile.h - the aklys feet note,
  the medium -2 and long -5): the star feet
  note, the double-star see-description
  note, the short-range basis note, and the
  medium/long adjust consts. The 28-row grid
  cross-checked cell-by-cell between the two
  passes; six cells contest in two clusters,
  all settled per the print capture - the
  bow-short AC-10 cell pins +3 (the
  compressed +2, both readings
  ladder-consistent; flagged for the
  physical-copy check), and the
  sling-staff-stone ladder pins the print
  row -4,-4,-3,-3,-2,-2,-1 (the compressed
  stone-one-worse-than-bullet pattern is
  design-plausible; flagged likewise). The
  stacked two-line cells (the blow pipe dart
  AC 0-2, the needle AC 0-4) decode cleanly
  in both passes. One pre-publish repair the
  machinery caught: the header_sections shape
  (a named-section dict, not a flat item
  list - the first rverify double-run RED;
  rebuilt before publish, the user side never
  saw the break). rverify GREEN at 739dd57,
  371 mutants, 0 missed; preflight GREEN
  (565 audit census, BUILD 0 warnings). Gap
  census 92/143 -> 93/142. Spec 18,949
  bytes md5
  c2318a7d6bfb34f23facd0ee1c791794
  (authored-plus-newline md5
  f975ce3bc0603408a29bb972716404e2 -
  the value the ritual gated and matched;
  canvas md5
  8822a06b2b1f6fe40fb5fbfb7e2067e0). NEXT -
  R643: Table 52 (Armor Class Table), capture
  p. 94, the armor-class grid, prefix dhd
  (verify free), audit "R643 OA armor audit",
  include after rules/oahurled.h.
- R643 LANDED 2026-10-19: commit
  86110ce4a39d218d2a260ceca762f7b298337e47
  (census 565 -> 566, pushed
  b784a11..86110ce), ARMOR CLASS TABLE -
  Table 52 (Armor Class Table), capture p.
  94: rules/oaarmor.h, prefix dhd (verified
  free), 2 inlines (1 const, 1 table
  column): the 8-row suit grid - the armor
  class rating ladder, 10 through 3 one
  step per row, the -99 default sentinel
  per the T48 single-column precedent, the
  type-of-armor names riding the column
  comment per the T48 doctrine (the
  shield/kote and o-yori spellings as
  printed; the suit rows enumerate multiple
  types per rating). The 8-row table
  cross-checked cell-by-cell between the
  two passes; the numeric ladder agrees -
  zero contested cells; the one contest is
  a name: the AC-4 row third type reads
  branded mail in the print against the
  compressed banded mail - the print's own
  page prose prints banded mail twice in
  the rare-suits sentence, so the row read
  is an OCR slip and the name pins as
  banded mail (a read contradicting its own
  page does not stand). The
  corselet-of-laced-armor prose example
  (AC 7, equal to studded leather)
  cross-checks the row-3 rating; the prose
  stays in the open armor prose box. One
  pre-publish repair the machinery caught:
  the single-line gap label - the first
  gap_to draft duplicated the flipped label
  standalone; the label-uniqueness assert
  (the R641 repair) caught it, the helper
  now extends the flipped line directly.
  rverify GREEN at b784a11, 9 mutants, 0
  missed; preflight GREEN (566 audit
  census, BUILD 0 warnings). Gap census
  93/142 -> 94/141. Spec 8,473 bytes md5
  b74a8e26c2aa4564beeee3f6120a9463
  (authored-plus-newline md5
  546320e7960ddf98d13220880133cf82 - the
  value the ritual gated and matched;
  canvas md5
  d562900b181aaa8213faf59d6f9c888d). NEXT -
  R644: Table 53 (Individual Piece Armor
  Class), capture p. 95, the laced-armor
  piece class steps, prefix dhe (verify
  free), audit "R644 OA piece armor audit",
  include after rules/oaarmor.h.
- R644 LANDED 2026-10-19: commit
  91f1d9505802772b1598a46222ca7a77f88735cd
  (census 566 -> 567, pushed
  86110ce..91f1d95), PIECE ARMOR -
  Table 53 (Individual Piece Armor
  Class), capture p. 95: rules/oapiece.h,
  prefix dhe (verified free), 5 inlines
  (2 consts, 2 table columns, 1 bool):
  the 9-row laced-armor piece grid - the
  armor class steps (2 for do-maru,
  hara-ate and haramaki-do, 1 elsewhere)
  measured from the AC-10 base (the
  definitional sentence under the table),
  the star set (the hara-ate /
  hara-ate-gawa backside pair), the
  backside note as a bool (the starred
  pieces do not cover the backside at
  all - attacks from behind treated as
  AC 10), the piece names riding the
  column comment per the T48 doctrine
  (the hyphenated spellings as printed).
  The 9-row grid cross-checked
  cell-by-cell between the two passes -
  the steps, the star set and the
  backside footnote text agree verbatim,
  zero contested cells. The page worked
  examples cross-check the steps
  arithmetic as table checks (kote alone
  AC 9; kote, do-maru and haidate AC 6).
  First publish clean - no repairs.
  rverify GREEN at 86110ce, 21 mutants,
  0 missed; preflight GREEN (567 audit
  census, BUILD 0 warnings). Gap census
  94/141 -> 95/140. Spec 8,852 bytes
  md5 64144178f6c85f5cb4e038452e6417ac
  (authored-plus-newline md5
  a82279854249f28a44bf7cfde6f9c24c - the
  value the ritual gated and matched;
  canvas md5
  7ec2abad4c816cd9853d17f821edd2ad).
  NEXT - R645: Table 54 (Types of Armor
  & Encumbrance), capture p. 95, the
  armor bulk/weight/movement grid,
  prefix dhf (verify free), audit "R645
  OA encumbrance audit", include after
  rules/oapiece.h.
- R645 LANDED 2026-10-19: commit
  50ada1ab00a3541f1c9f3e3581f9df3c9c592be4
  (census 567 -> 568, pushed
  91f1d95..50ada1a), ARMOR ENCUMBRANCE -
  Table 54 (Types of Armor & Encumbrance),
  capture p. 95: rules/oaencumb.h, prefix
  dhf (verified free), 3 inlines (1 const,
  2 table columns): the 23-row armor type
  grid - the base weight column (pounds,
  the # mark stripped) and the base
  movement column (feet, the prime
  stripped; the seven dash cells - buckler,
  haidate, kote, the two shields, the sode
  pair, sune-ate - pin as -99); the armor
  names, the bulk classes (non/fairly/
  bulky) and the banded/chain
  plus-after-pound marks riding the column
  comments per the T48 doctrine. The
  23-row grid cross-checked cell-by-cell
  between the two passes - the weights and
  movements agree, zero numeric contested
  cells; the textual contests settle per
  the print: the compressed bulk
  trailing-hyphen artifact, the kote
  weight cell blank against the compressed
  dash (both read no base weight, the -99
  sentinel carries it), the movement prime
  against the compressed double-prime.
  First publish clean - no repairs.
  rverify GREEN at 91f1d95, 47 mutants,
  0 missed; preflight GREEN (568 audit
  census, BUILD 0 warnings). Gap census
  95/140 -> 96/139. Spec 9,854 bytes md5
  5f6520ed69f0ede86d068ca3e88c3ff6
  (authored-plus-newline md5
  4ac2cd2919bf7a0fdcc7bbb6897d381c - the
  value the ritual gated and matched;
  canvas md5
  0c4c26c252299a19bdc2065af21d6da8). NEXT -
  R646: Table 55 (Barded Warhorse Base
  Movement Rates), capture p. 98, the
  barding movement grid, prefix dhg
  (verify free), audit "R646 OA barding
  audit", include after rules/oaencumb.h -
  the misc equipment and barding prose
  boxes stay open.
- R646 LANDED 2026-10-19: commit
  6ad968b14ba64ea06b25a77f0927888ae3a170c5
  (census 568 -> 569, pushed
  50ada1a..6ad968b), BARDING - Table 55
  (Barded Warhorse Base Movement Rates),
  capture p. 98: rules/oabarding.h, prefix
  dhg (verified free), 10 inlines (2 consts,
  6 table columns, 2 bools): the 4-row
  barded warhorse grid - the full/half
  movement pairs for the three barding
  materials (padded/leather, metal scale,
  chain; the prime stripped per the R645
  glyph class), the light-horse chain X
  (too heavy) and the elephant blank
  metal/chain cells as -99, the lone
  elephant 12 as the T50 lo=hi convention,
  the note doctrine as two bools (the number
  before the slash is full barding; an X
  means heavier than the horse can bear).
  The 4-row grid cross-checked cell-by-cell
  between the two passes - the pairs agree,
  zero numeric contested cells; the glyph
  artifacts settle per the print (the
  prime, the stray-space 15); the note's
  first word reads Tumber in both passes -
  an OCR slip for "The number", noted.
  First publish clean - no repairs.
  rverify GREEN at 50ada1a, 28 mutants,
  0 missed; preflight GREEN (569 audit
  census, BUILD 0 warnings). Gap census
  96/139 -> 97/138 - the Chapter 5
  armor/equipment tables are all closed.
  Spec 10,201 bytes md5
  2df45213039a6ebc26d2137585b14729
  (authored-plus-newline md5
  de36ad5f26105e74d456c56ec309901e - the
  value the ritual gated and matched;
  canvas md5
  bf7f7df2eb63009ed54ad3294b8b92ab). NEXT -
  R647: the Miscellaneous Equipment
  Descriptions prose box (capture p. 98),
  the grenades prose, prefix dhh (verify
  free), audit "R647 OA misc equipment
  audit", include after rules/oabarding.h -
  the barding prose box stays open beside
  it.
- R647 LANDED 2026-10-19: commit
  9a2f19dbd849209219bb8595159b6c416ebe4a05
  (census 569 -> 570, pushed
  6ad968b..9a2f19d), MISC EQUIPMENT - the
  grenades prose of the equipment
  descriptions, capture p. 98:
  rules/oagrenade.h, prefix dhh (verified
  free), 20 inlines (13 consts, 7 bools,
  no table): the four grenade kinds with
  the save-vs doctrine - pepper (single
  target, save versus poison, incapacitated
  1-6 rounds), dust (the same save,
  blinded 1-6), flash powder (fire source,
  auto-blind 1-3, the maybe-looking save
  versus petrification) and poison smoke
  (fire source, the 5-foot per-round fill,
  save versus poison, 1-2 hp per round, the
  10-foot area, one turn); the to-hit
  doctrine as bools (no armor modifiers -
  the contents burst in a small cloud on
  impact; the eggshell 10-foot fall
  threshold with the save versus crushing
  blow per grenade). The prose
  cross-checked paragraph-by-paragraph
  between the two passes - every printed
  number agrees, zero contested cells; the
  lone glyph artifact is an em-dash class
  (not a pin, noted). First publish clean -
  no repairs. rverify GREEN at 6ad968b,
  20 mutants, 0 missed; preflight GREEN
  (570 audit census, BUILD 0 warnings).
  Gap census 97/138 -> 98/137. Spec
  11,835 bytes md5
  cc67d8391502b1299fd9851f04257449
  (authored-plus-newline md5
  aff6eadcec8612fdcbd87365dfbc4e5c - the
  value the ritual gated and matched;
  canvas md5
  89865ff4113eac060a0ea1750395fd58).
  NEXT - R648: the Barding prose box
  (capture p. 98), the barding AC-factor
  and weight paragraph, prefix dhi (verify
  free), audit "R648 OA barding prose
  audit", include after rules/oagrenade.h -
  the armor descriptions box stays open
  beside it.
- R648 LANDED 2026-10-19: commit
  22d52ad542a3d89aae5d75c3d07eff42ac5a383b
  (census 570 -> 571, pushed
  9a2f19d..22d52ad), BARDING PROSE - the
  barding AC factors and weight doctrine,
  capture pp. 98-99: rules/oabardprose.h,
  prefix dhi (verified free), 13 inlines
  (8 consts, 5 bools, no table): the
  barding AC-factor ladder (leather or
  padded 1 factor 160#, metal scale 2
  factors 250#, chain 3 factors 350#),
  the half-barding doctrine (weighs half
  - the divisor 2 - frontal protection
  only, the rear no bonus, more common
  than full), the plate-never-used rule,
  the must-carry-weight rule
  cross-referencing the R646 Table 55
  grid. The prose cross-checked
  paragraph-by-paragraph between the two
  passes - every printed number agrees,
  zero contested cells. First publish
  clean - no repairs. rverify GREEN at
  9a2f19d, 13 mutants, 0 missed;
  preflight GREEN (571 audit census,
  BUILD 0 warnings). Gap census 98/137
  -> 99/136. Spec 9,786 bytes md5
  8e7445d7a1cfa33b955c721e13e3f211
  (authored-plus-newline md5
  1bd30d7fe9600f84674e5dac6928db4c - the
  value the ritual gated and matched;
  canvas md5
  1af05965804d59c0ccb470e60a9eeba3).
  NEXT - R649: the armor prose and the
  armor descriptions box (capture
  pp. 93-98), the suits-and-pieces
  doctrine and the armor description
  entries, prefix dhj (verify free),
  audit "R649 OA armor descriptions
  audit", include after
  rules/oabardprose.h - the last
  Chapter 5 box.
- R649 LANDED 2026-10-19: commit ffef1f8ff283803a88a8ccab17d5b8de848cf110
  (census 571 -> 572, pushed 22d52ad..ffef1f8), ARMOR PROSE AND DESCRIPTIONS -
  the suits-and-pieces doctrine and the armor description entries, capture pp.
  93-98: rules/oaarmordesc.h, prefix dhj (verified free), 40 inlines (13
  consts, 27 bools, no table): the two-group suits-and-pieces doctrine with
  the common, rare and virtually-unknown suit lists as counts (the names
  riding the comments), the corselet-AC-7 example equal to studded leather and
  the kote-only AC 9 and kote-do-maru-haidate AC 6 printed examples
  (cross-checks of the R643 T52 and R644 T53 grids), the averaging doctrine,
  the one-piece-per-area, no-pieces-with-suits and sode-needs-a-corselet
  rules, and the nineteen description entries - the horo back-missile bonus 1,
  the kabuto head AC 3, the sode one foot square, the o-yoroi six included
  pieces and five smaller, the concealability split, the movement-category
  drop with the o-yoroi floor. The prose cross-checked paragraph-by-paragraph
  between the two passes - every printed number agrees, zero contested cells;
  the shared OCR slips settled per the R643 branded-mail pattern: the print
  Hare-ate and here-ate reads fall to the print pass's own Table 53 (hara-ate,
  compressed-corroborated), the compressed Hanburt falls to the print Hanburi,
  and the print suns-ate, sods, Bode and Kate reads fall to the compressed
  corroboration (sune-ate, sode, kote). One pre-publish repair on the
  authoring side: the rebuilt gap_to wrap dropped the second label line's
  indent (caught inspecting the flip before rverify, the user side never saw
  the break) - the gen script is kept at r649/ and the scratch fetch tree
  rebuilds from the base sha each round. First publish clean. rverify GREEN at
  22d52ad, 40 mutants, 0 missed; preflight GREEN (572 audit census, BUILD 0
  warnings). Gap census 99/136 -> 100/135. Spec 23,990 bytes md5
  8890c2cd244af3f8ffffdf46f42a19cb (authored-plus-newline md5
  4962679107228337f39a14937f6fa961 - the value the ritual gated and matched;
  canvas md5 10f15d4495d1829913a815e7912e6653). NEXT - R650: the Chapter 6
  Proficiencies arc begins - the weapon proficiencies and weapon
  specialization prose (capture pp. 100-101), prefix dhk (verify free), audit
  "R650 OA proficiencies audit", include after rules/oaarmordesc.h - the
  Chapter 6 boxes at HEAD name the exact labels
- R650 LANDED 2026-10-19: commit 689abc769fdd33a284bc877400722a3c0d510a30
  (census 572 -> 573, pushed ffef1f8..689abc7), WEAPON PROFICIENCIES AND
  SPECIALIZATION - the Chapter 6 opener with the slot doctrine and the
  specialist bonuses, capture pp. 99-101: rules/oaweaponspec.h, prefix dhk
  (verified free), 47 inlines (30 consts, 17 bools, no table). THE ARC-OPENER
  PRECEDENT APPLIED: per the R636 pattern the Chapter 6 parent box opens this
  round alongside the first child - two gap flips (the parent with the
  slot-system prose pinned, the weapon proficiencies and specialization prose
  box). The pins: the slot doctrine (the 1st-level slots, the
  weapon-or-peaceful fill, the saveable slots, the never-change rule, one slot
  per weapon proficiency), the specialization doctrine (samurai and bushi
  only, two slots melee or crossbow, three other missiles, the bushi
  one-weapon rule, the samurai katana-and-bow rule with the delayable bow, the
  specific-type rule, the melee specialist +1/+2 with iaijutsu and the
  next-attack-rank rule, the 3/2 and 2/1 attack examples, double
  specialization at one slot more for +3/+3), the bow point-blank band (5-30
  feet, +2/+2, doubled base damage, the ready-arrow auto-fire), the crossbow
  point-blank band (5-60 feet, +1/+1 short, +1 medium, the same benefits), the
  other-missile +1/+2, and the p. 101 restrictions (the class penalty on
  disallowed weapons never kept and carried, the under-5-feet 12-foot bound,
  the under-4-feet daikyu ban, the under-100-pounds heavy-crossbow, 200-gp and
  two-handed-sword bans, overriding the penalty entirely). The prose
  cross-checked paragraph-by-paragraph between the two passes - every printed
  number agrees; one OCR artifact class settled per the R643 pattern: the
  compressed pass systematically renders the specialization bonuses as minuses
  and each read contradicts its own sentence (an increase to a bonus, a
  doubled base damage), so the print + signs stand; the print pocked
  letter-slip settles as nocked. First publish clean - no repairs. rverify
  GREEN at ffef1f8, 47 mutants, 0 missed; preflight GREEN (573 audit census,
  BUILD 0 warnings). Gap census 100/135 -> 102/133. Spec 25,960 bytes md5
  2a3c25c56046abb56ec0614dc1aed8fe (authored-plus-newline md5
  4538b7f51911bec04f71e602f0061a2a - the value the ritual gated and matched;
  canvas md5 6030c661d4703ac2207bfb626512eb3a). NEXT - R651: Table 57 (Missile
  Weapon Specializations), capture p. 100, the specialist attacks-per-round
  grid, prefix dhl (verify free), audit "R651 OA missile specializations
  audit", include after rules/oaweaponspec.h
- R651 LANDED 2026-10-19: commit 4cfbabe427dd5f88becb74d482c7090eeef2f605
  (census 573 -> 574, pushed 689abc7..4cfbabe), TABLE 57 MISSILE
  SPECIALIZATIONS - the specialist attacks-per-round grid, capture p. 100:
  rules/oamslspec.h, prefix dhl (verified free), 17 inlines (3 consts, 14
  table columns, no bools): the grid per the T55 pair precedent - each printed
  num/den attacks pair a numerator and denominator column across the three
  level bands (the band bounds as consts - three bands, tops at 6 and 12), the
  seven printed columns the bow 2/1-3/1-4/1, the light crossbow 1/1-3/2-2/1,
  the pellet bow & heavy crossbow 1/2-1/1-3/2, the lasso & staff sling
  1/1-3/2-2/1, the large shuriken & thrown dagger 3/1-4/1-5/1, the dart &
  small shuriken 4/1-5/1-6/1 and the other column 3/2-2/1-5/2, the table tag
  T57Data identifier-safe per the R639 lesson. The grid cross-checked
  cell-by-cell between the two passes - every printed cell agrees, zero
  contested cells; two column-name reads settled from the print pass's own p.
  100 header fragments plus the compressed corroboration: the p. 101 header
  reads dropped the Pellet and the Large, the names pin as pellet bow & heavy
  crossbow and large shuriken & thrown dagger. One pre-publish repair the
  machinery caught: the first build omitted the table tag/count/comment keys,
  the engine double-run RED - rebuilt before publish, the user side never saw
  the break. rverify GREEN at 689abc7, 45 mutants, 0 missed; preflight GREEN
  (574 audit census, BUILD 0 warnings). Gap census 102/133 -> 103/132. Spec
  13,264 bytes md5 214fb83bc72b8518ea6c98c778c289b9 (authored-plus-newline md5
  864c3c32f6c0c4d43920858c17aea3fc - the value the ritual gated and matched;
  canvas md5 17cd9a5e93fd6c370276f282ad615621). NEXT - R652: the Non-Weapon
  Proficiencies prose with the optional peaceful proficiency bonuses, the
  success-and-failure doctrine and the contests (capture pp. 101-103), prefix
  dhm (verify free), audit "R652 OA non-weapon proficiencies audit", include
  after rules/oamslspec.h
- R652 LANDED 2026-10-19: commit 125647b399484360b77fcc815dfb7182d8a40ef6
  (census 574 -> 575, pushed 4cfbabe..125647b), NON-WEAPON
  PROFICIENCIES - the peaceful-arts prose, capture pp. 101-103:
  rules/oanwprof.h, prefix dhm (verified free), 33 inlines (12
  consts, 21 bools, no tables): the four categories (Common,
  Artisan, Court, Barbarian) with the only-barbarians rule and the
  category learning environments, the no-required-study-times and
  tools-and-guidance learning doctrine, the base-chance rules
  (identical to the to-hit roll, never improving with level), the
  +1-per-slot improvement from 2nd level, the no-limit rule and
  the never-below-3 floor, the magical-only-if-known rule, the
  Akimori calligraphy example (two slots, base 17, 16 at third, 14
  at fourth), the optional +1/+2 player bonuses (strictly
  optional), the success-and-failure doctrine with the always-roll
  proficiencies (weapon-smith, armorer) and the contest rules
  (formal vs impromptu, the elimination resolution, the
  inauspicious all-fail rule, 50 vs 100 times the host's level).
  The compressed plus-as-minus OCR artifact settles per the print
  pass: the compressed renders the slot and optional bonuses as
  minuses where the print prints pluses, and the Akimori
  arithmetic (the chance falling as the modifier rises) reads
  nonsense with genuine minuses - genuine pluses pinned per the
  R650 precedent; zero contested reads otherwise. rverify GREEN at
  4cfbabe, 33 mutants, 0 missed; preflight GREEN (575 audit
  census, BUILD 0 warnings). Gap census 103/132 -> 104/131. Spec
  19,624 bytes md5 20eacc3e7a91ae60c38538835044cac4
  (authored-plus-newline md5 7c7bf524778ba7566ab79930c3cf9c3a -
  the value the ritual gated and matched; canvas md5
  5d3d530d16625de243c26b249ecc8479). NEXT - R653: Table 56
  (Character Proficiencies), capture p. 99, prefix dhn (verify
  free), audit "R653 OA character proficiencies audit", include
  after rules/oanwprof.h
- R653 LANDED 2026-10-19: commit f96f0da050e1cc80244a8f8c0cdf7f78d542024b
  (census 575 -> 576, pushed 125647b..f96f0da), TABLE 56
  CHARACTER PROFICIENCIES - the class grid with the ninja
  rule, capture p. 99: rules/oacharprof.h, prefix dhn
  (verified free), 5 inlines (1 const, 1 bool, 3 table
  columns, tag T56Data): the eight class rows (samurai,
  shukenja, sohei, kensai, o. barbarian, bushi, wu jen,
  ninja) riding the first column comment, with the initial
  proficiencies (5, 6, 4, 3, 9, 4, 6, 2), the levels per
  added proficiency as the 1/N denominators (1, 2, 3, 2,
  3, 2, 2, 3) and the non-proficiency penalties (2, 4, 2,
  3, 2, 2, 5, 4); the ninja weapon-only rule pins as a
  bool (the non-proficiency penalty applies only to ninja
  weapons, all other weapons take the other class
  penalty). Cross-checked cell-by-cell between the two
  passes - every printed cell agrees, zero contested
  cells. One pre-verify repair the machinery caught: the
  first build omitted the tables key so the engine
  emitted no grid (2 inlines instead of 5) - the seating
  assert flagged it, rebuilt before publish, the user side
  never saw the break. rverify GREEN at 125647b, 26
  mutants, 0 missed; preflight GREEN (576 audit census,
  BUILD 0 warnings). Gap census 104/131 -> 105/130. Spec
  9,543 bytes md5 f31c8dd0e2ad0fd2bea406cd0e9b5a49
  (authored-plus-newline md5 62d5839b0ddd9aca2fe1534af6e42376
  - the value the ritual gated and matched; canvas md5
  0cd79fd5a24f9d9e41d90efa2a8582ba). NEXT - R654: Table 58
  (Artisan Proficiencies), capture p. 103, prefix dho
  (verify free), audit "R654 OA artisan proficiencies
  audit", include after rules/oacharprof.h
- R654 LANDED 2026-10-19: commit b7a45cc8a6edae052ee3a230369b1f7123deadc6
  (census 576 -> 577, pushed f96f0da..b7a45cc), TABLE 58
  ARTISAN PROFICIENCIES - the artisan grid with the slot
  costs, base chances and always-roll markers, capture
  p. 103: rules/oaartprof.h, prefix dho (verified
  free), 4 inlines (1 const, 3 table columns, tag
  T58Data, no bools): the eighteen artisan rows (armorer
  through weaver) riding the first column comment, with
  the slot costs (2, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1,
  1, 1, 1, 3, 1), the base chances (16, 14, 15, 16, 15,
  18, 17, 16, 14, 12, 18, 16, 17, 19, 16, 15, 17, 15)
  and the always-roll markers (armorer, bowyer,
  herbalist, navigator, weaponsmith; 0 for the other
  thirteen). Every numeric cell agrees between the
  passes - zero contested numbers. Two footnote-marker
  reads settle against the prose: the print pass drops
  the weaponsmith a and the bowyer asterisk where the
  compressed carries both, and the weaponsmith prose
  mandates the end-of-construction die roll while the
  bowyer explanation section exists - both markers pin
  per the compressed-plus-prose reading, the print drops
  reading as an OCR omission. rverify GREEN at f96f0da,
  55 mutants, 0 missed; preflight GREEN (577 audit
  census, BUILD 0 warnings). Gap census 105/130 ->
  106/129. Spec 9,448 bytes md5
  1376b7e2d286eef204fad313c58619fd
  (authored-plus-newline md5
  8a45a9042aeae83c2d29652278d6e4a5 - the value the
  ritual gated and matched; canvas md5
  27d134328268eeb917aa60e611ae4beb). NEXT - R655: Table
  59 (Barbarian Proficiencies), capture p. 104, prefix
  dhp (verify free), audit "R655 OA barbarian
  proficiencies audit", include after rules/oaartprof.h
- R655 LANDED 2026-10-19: commit 0a7ef34bcaadeae7469d2956773922ef5a1f82f9
  (census 577 -> 578, pushed b7a45cc..0a7ef34), TABLE 59
  BARBARIAN PROFICIENCIES - the barbarian grid with the
  slot costs, base chances and always-roll markers,
  capture p. 104: rules/oabarbprof.h, prefix dhp
  (verified free), 4 inlines (1 const, 3 table columns,
  tag T59Data, no bools): the eight barbarian rows
  (chanting through tracking) riding the first column
  comment, with the slot costs (1, 1, 1, 1, 1, 2, 2,
  3), the base chances (15, 8, 16, 12, 14, 16, 15, 17)
  and the always-roll markers (fire building, running,
  signaling, snare building, sound imitation, tracking;
  chanting and survival unmarked); the asterisk set
  (all but chanting) rides the row comments. Cross-
  checked cell-by-cell between the two passes - zero
  contested cells, marker for marker. SESSION RECOVERY
  NOTE: the original print OCR session was lost to an
  extraction-persistence failure at the R655 open; the
  user re-uploaded the scan, the recovered session
  extracted at 315 pages with pagination aligned to
  the book, its p. 101 cross-checked verbatim against
  the prior session read and its p. 103 corroborating
  the R654 marker reads - the print-pass read route is
  the new session (the compressed session was never
  touched). rverify GREEN at b7a45cc, 25 mutants, 0
  missed; preflight GREEN (578 audit census, BUILD 0
  warnings). Gap census 106/129 -> 107/128. Spec 8,879
  bytes md5 c3455f6a2b4d2aaa83bf03b2febedefc
  (authored-plus-newline md5
  ddfcb8fc91e3ce409aae44e3d4c3b516 - the value the
  ritual gated and matched; canvas md5
  8d4d37c92f79ca10d33fda8c949b0092). NEXT - R656: Table
  60 (Common Proficiencies), capture p. 106, prefix dhq
  (verify free), audit "R656 OA common proficiencies
  audit", include after rules/oabarbprof.h
- R656 LANDED 2026-10-19: commit 19aa44bba03af6497ec88eb0e4c3a4beb57903a3
  (census 578 -> 579, pushed 0a7ef34..19aa44b), TABLE 60
  COMMON PROFICIENCIES - the common grid with the slot
  costs, base chances and always-roll markers, capture
  p. 106: rules/oacomprof.h, prefix dhq (verified
  free), 4 inlines (1 const, 3 table columns, tag
  T60Data, no bools): the seventeen common rows
  (agriculture through swimming) riding the first
  column comment, with the slot costs (animal handling
  2, the rest 1), the base chances (15, 14, 16, 17, 17,
  16, 18, 16, 14, the iaijutsu printed dash as the
  sentinel, 16, 17, 10, 15, 17, 16, 10) and the
  always-roll markers (animal handling, gaming,
  horsemanship, hunting, juggling, swimming). The arc's
  first contested numeric reads: the compressed reads
  fishing 14, juggling 13 and small water craft 13
  against the print 17, 16, 16 - the print pass (the
  settling authority) settles all three, the
  compressed deltas recorded as its OCR artifact; the
  hunting a marker (dropped in print, carried in
  compressed) settles per the compressed-plus-prose
  reading - the hunting prose mandates the die roll,
  the R654 precedent. One pre-verify repair the
  machinery caught: this is the arc's first single-line
  box label and the gap_to helper's two-line assumption
  re-appended the unflipped line as the continuation -
  the engine double-run went RED on the open count
  before any write; fixed (flip the first line, wrap the
  note onto the already-flipped last line), rebuilt,
  double-run GREEN - Table 61's label is single-line
  too, so the fix is proven for R657. rverify GREEN at
  0a7ef34, 52 mutants, 0 missed; preflight GREEN (579
  audit census, BUILD 0 warnings). Gap census 107/128 ->
  108/127. Spec 10,480 bytes md5
  086266104a3aeabd8ae0fecf9cdf014f
  (authored-plus-newline md5
  a1bfec96574daf3fc074b2d35dac3c37 - the value the
  ritual gated and matched; canvas md5
  5c879c09825e8920c01aa432d64bdcb2). NEXT - R657: Table
  61 (Court Proficiencies), capture p. 108, prefix dhr
  (verify free), audit "R657 OA court proficiencies
  audit", include after rules/oacomprof.h
- R657 LANDED 2026-10-19: commit 88168f07084ae63c68066fe079985f9fd6fa60eb
  (census 579 -> 580, pushed 19aa44b..88168f0), TABLE 61
  COURT PROFICIENCIES - the court grid with the slot
  costs, base chances and always-roll markers, capture
  p. 108: rules/oacourtprof.h, prefix dhr (verified
  free), 4 inlines (1 const, 3 table columns, tag
  T61Data, no bools): the twelve court rows
  (calligraphy through tea ceremony) riding the first
  column comment, with the slot costs (calligraphy,
  falconry, tea ceremony 2, the rest 1), the base
  chances (18, 16, 17, 15, 12, 16, 17, 14, 19, 19, 12,
  15) and the always-roll markers (etiquette, falconry,
  heraldry); the asterisk set (calligraphy, etiquette,
  falconry, heraldry, noh, religion, tea ceremony)
  rides the row comments. Cross-checked cell-by-cell
  between the two passes - zero contested cells,
  marker for marker (the grid opening print p. 108,
  the religion and tea ceremony rows at the top of
  print p. 109; the compressed full grid p. 56). The
  R656 single-line-label fix handled this round's
  single-line flip cleanly on the first build. This
  round closes the Chapter 6 proficiencies arc - the
  Table 56 and Tables 58-61 grids plus the weapon,
  missile, non-weapon and character prose all landed.
  rverify GREEN at 19aa44b, 37 mutants, 0 missed;
  preflight GREEN (580 audit census, BUILD 0
  warnings). Gap census 108/127 -> 109/126. Spec
  9,474 bytes md5 a5ffa95047a61f2e30791dce05e2cc12
  (authored-plus-newline md5
  4c1d355bc843417d8d56bc29ac2677ce - the value the
  ritual gated and matched; canvas md5
  42d9bae23dbd21b977c5630092ed0db7). NEXT - R658: the
  Chapter 7 parent opens - Table 62 (Shukenja Spells),
  capture p. 112, the full spell list by level, prefix
  dhs (verify free), audit "R658 OA shukenja spells
  audit", include after rules/oacourtprof.h
- R658 LANDED 2026-10-19: commit 15eda016e1bd92154ee09d20cd55b907829bf4d7
  (census 580 -> 581, pushed 88168f0..15eda01), TABLE 62
  SHUKENJA SPELLS - the spell list by level with the
  sohei and reversible markers, capture p. 112, plus
  the Chapter 7 parent open - the first parent-open
  flip since R650: rules/oashkspells.h, prefix dhs
  (verified free), TWO gap flips this round (parent
  2-line top-level label, no checkbox indent, 2-space
  continuation; child 2-line label), 10 consts, 24
  inlines (grid tag T62Data, 20 rows x 14 cols - 7
  sohei + 7 reversible level columns, sentinel -99
  past the twelve-spell levels 5-7), gap census
  109/126 -> 111/124: the 116 shukenja spells by level
  (20, 20, 20, 20, 12, 12, 12) with the sohei-usable
  markers (26 spells, cross-checked cell-by-cell
  between the passes, zero contested reads; print p.
  112 vs compressed pp. 57-58) and the reversible
  markers (33 spells, print-only - the compressed
  renders no italics; the compressed name garbles
  Purity Food and Drink, Enthral, Smile and the 2d/3d
  Level headers all settle per print). One authoring
  repair: an example pin read L7Rev(11) != -99 where
  index 11 is a real level-7 cell; corrected to
  (11) != 0 and (12) != -99. rverify GREEN at
  88168f0, 290 mutants, 0 missed; preflight GREEN
  (581 audit census, BUILD 0 warnings). Spec 21,816
  bytes md5 f77d870c892522d91e38d7365e4ac765
  (authored-plus-newline md5
  d7e28fe187ab74569202c8aa40dcca9f - the value the
  ritual gated and matched; canvas md5
  44e99ad7644eed23305c7e5467ea8547). NEXT - R659:
  First Level Spells (capture pp. 112-119), prefix dht
  (verify free), audit "R659 OA first level spells
  audit", include after rules/oashkspells.h
- R659 LANDED 2026-10-19: commit e95ea548a13790f5627dbfbd78e241c741c2da16
  (census 581 -> 582, pushed 15eda01..e95ea54), FIRST
  LEVEL SPELLS - the 20 first level shukenja spell
  stat blocks, capture pp. 112-119: rules/oal1spells.h,
  prefix dht (verified free), ONE gap flip (single-line
  child label, the R656 fix), 11 consts, 17 inlines
  (grid tag L1Data, 20 rows x 6 cols - school,
  components V=1 S=2 M=4 bitmask, casting time in
  segments turn=60/round=10, saving throw code 0/1/2,
  reversible, sohei), gap census 111/124 -> 112/123:
  all 20 stat blocks cross-checked spell by spell
  between the passes (print pp. 113-119 vs compressed
  pp. 58-60), zero contested stat reads - ten
  divination spells, twelve VSM / two verbal-only
  (beneficence, omen) / six VS, four one-turn casts,
  two neg. saves (animal companion, calm), two special
  (deflection, know history); the reversible five and
  sohei five match the R658 T62 grid exactly. The
  compressed inch-mark garbles render as degree glyphs
  and stars (its artifact class); the print p. 113
  augury "1 orb per level" garble is prose-only,
  nothing pinned rides it. One authoring repair: the
  engine emits table columns as switches and needs a
  default - added col_default=0 (no sentinel, all 20
  ordinals real). rverify GREEN at 15eda01, 131
  mutants, 0 missed; preflight GREEN (582 audit
  census, BUILD 0 warnings). Spec 17,048 bytes md5
  38006ca7b10ac17d73092a7719854eb3
  (authored-plus-newline md5
  c33b1300f8da56724327bec81b323c45 - the value the
  ritual gated and matched; canvas md5
  949ca5665fdc3f8829d0239b81b560a3). NEXT - R660:
  Second Level Spells (capture pp. 119-126), prefix
  dhu (verify free), audit "R660 OA second level
  spells audit", include after rules/oal1spells.h
- R660 LANDED 2026-10-19: commit 350c96b770e0913a8ccef2a8fcd673fa016b6a88
  (census 582 -> 583, pushed e95ea54..350c96b), SECOND
  LEVEL SPELLS - the 20 second level shukenja spell
  stat blocks, capture pp. 119-126: rules/oal2spells.h,
  prefix dhu (verified free), ONE gap flip (single-line
  child label), 15 consts, 21 inlines (grid tag L2Data,
  20 rows x 6 cols - school with the abjuration code 7
  debuting, components V=1 S=2 M=4 bitmask, casting
  time in segments request=180/slow poison=1, saving
  throw code, reversible, sohei), gap census
  112/123 -> 113/122: all 20 stat blocks cross-checked
  spell by spell between the passes (print pp.
  119-125 vs compressed pp. 60-63), zero contested
  stat reads - thirteen VSM / six VS / dream sight
  the unique S,M no-verbal spell (read in both
  passes); detect charm's components read V, S in
  both passes (the print line breaking at its page
  boundary, the compressed confirming); abjuration
  debuts (protection from spirits, request); aid's
  dual school pins as the primary necromantic 5;
  request takes the longest cast at three turns.
  The reversible three (create spring, detect charm,
  know motivation) and sohei four (chant, messenger,
  slow poison, warning) match the R658 T62 grid
  exactly. rverify GREEN at e95ea54, 135 mutants, 0
  missed - GREEN on the first build, the R659
  col_default lesson carried forward; preflight
  GREEN (583 audit census, BUILD 0 warnings). Spec
  19,105 bytes md5 062062c698ff856d9cd2baa22153116a
  (authored-plus-newline md5
  540f529cc6feb4d0cb7a30154dfb22c3 - the value the
  ritual gated and matched; canvas md5
  18bdea9643625324578df542cf7d6ae7). NEXT - R661:
  Third Level Spells (capture pp. 126-132), prefix
  dhv (verify free), audit "R661 OA third level
  spells audit", include after rules/oal2spells.h
- R661 LANDED 2026-10-19: commit 4590ae7c255039908d6d52aab848ac6bc2cb58c1
  (census 583 -> 584, pushed 350c96b..4590ae7), THIRD
  LEVEL SPELLS - the 20 third level shukenja spell
  stat blocks, capture pp. 126-132: rules/oal3spells.h,
  prefix dhv (verified free), ONE gap flip (single-line
  child label), 19 consts, 25 inlines (grid tag L3Data,
  20 rows x 6 cols - school with invocation 8 and
  illusion/phantasm 9 debuting, components bitmask,
  casting time in segments substitution=180, saving
  throw code, reversible, sohei), gap census
  113/122 -> 114/121: all 20 stat blocks cross-checked
  spell by spell between the passes (print pp.
  126-132 vs compressed pp. 63-66), zero contested
  stat reads - invocation (dream vision) and
  illusion/phantasm (invisibility to spirits) debut,
  both headers reading identically in the two passes;
  abjuration the most common school at seven spells;
  magical vestment's dual conjuration/alteration pins
  as the primary conjuration (the R660 aid
  convention); substitution the longest cast at three
  turns. The reversible seven (cure blindness, cure
  disease, dream vision, know alignment, oath, remove
  curse, remove paralysis) and sohei four (castigate,
  dispel magic, flame walk, prayer) match the R658
  T62 grid exactly. rverify GREEN at 350c96b, 139
  mutants, 0 missed - GREEN on the first build;
  preflight GREEN (584 audit census, BUILD 0
  warnings). Spec 20,727 bytes md5
  cea782690dfe219cc7e672d5ea3542f0
  (authored-plus-newline md5
  cfe8a345215c63f2cf23aba93025ae57 - the value the
  ritual gated and matched; canvas md5
  2a03522fad1f8872d77d680a2c48eeb6). NEXT - R662:
  Fourth Level Spells (capture pp. 132-140), prefix
  dhw (verify free), audit "R662 OA fourth level
  spells audit", include after rules/oal3spells.h
- R662 LANDED 2026-10-19: commit bf5257b872279240b0a96730a05cee7e323578a3
  (census 584 -> 585, pushed 4590ae7..bf5257b), FOURTH
  LEVEL SPELLS - the 20 fourth level shukenja spell
  stat blocks, capture pp. 132-140: rules/oal4spells.h,
  prefix dhw (verified free), ONE gap flip (single-line
  child label), 20 consts, 26 inlines (grid tag L4Data,
  20 rows x 6 cols - school, components bitmask,
  casting time in segments fate=360/exorcise=-1,
  saving throw code with the half 3 debuting,
  reversible, sohei), gap census 114/121 -> 115/120:
  all 20 stat blocks cross-checked spell by spell
  between the passes (print pp. 132-140 vs compressed
  pp. 66-69), zero contested stat reads - exorcise's
  variable 1-100+ turns cast pinned as -1 (the only
  unfixed cast in the chapter); the snake barrier
  half save debuts as code 3 (the print garbling the
  1/2 as 112, the compressed reading it clean);
  polymorph self V-only, endurance S,M, reward V,M -
  three component singles all read identically in
  the two passes; alteration the most common school
  at seven; abjure's dual school pins as the primary
  abjuration; fate the longest fixed cast at six
  turns. The reversible seven (abjure, cure serious
  wounds, detect lie, endurance, neutralize poison,
  protection from evil 10', tongues) and sohei three
  (endurance, penetrate disguise, spell immunity)
  match the R658 T62 grid exactly. rverify GREEN at
  4590ae7, 140 mutants, 0 missed - GREEN on the first
  build; preflight GREEN (585 audit census, BUILD 0
  warnings). Spec 21,140 bytes md5
  5ec09741fbc2f03104be4cb193127064
  (authored-plus-newline md5
  86ed280449cfa08f13cbd7cab89c2f8f - the value the
  ritual gated and matched; canvas md5
  d679d57d6a7b2ccd82408ed43a6eec60). NEXT - R663:
  Fifth Level Spells (capture pp. 140-143), prefix
  dhx (verify free), audit "R663 OA fifth level
  spells audit", include after rules/oal4spells.h
- R663 LANDED 2026-10-19: commit 28d59514e9c97f9a0bc3e775eb1f99420b74eaa4
  (census 585 -> 586, pushed bf5257b..28d5951), FIFTH
  LEVEL SPELLS - the 12 fifth level shukenja spell
  stat blocks, capture pp. 140-143: rules/oal5spells.h,
  prefix dhx (verified free), ONE gap flip (single-line
  child label), 18 consts, 24 inlines (grid tag
  L5Data, 12 rows x 6 cols - the level sizes dropping
  from 20 to 12 per the R658 T62 grid), gap census
  115/120 -> 116/119: all 12 stat blocks cross-checked
  spell by spell between the passes (print pp.
  140-143 vs compressed pp. 68-70), zero contested
  stat reads - alteration and divination tie as the
  most common school at three each, no evocation or
  conjuration this level; advice the V-only single;
  air walk the one-segment cast; three eight-segment
  casts; raise dead and remember the special saves.
  One authoring repair (caught by the data asserts):
  initially five reversible marks, but the R658 T62
  grid settles SIX - raise dead's header reads
  Reversible; the missing pin made the mirror report
  1 bad on the first build, the second build GREEN.
  The reversible six (cure critical wounds, dispel
  evil, mental strength, raise dead, remember, true
  seeing) and sohei four (dispel evil, mental
  strength, strength, true seeing) match the R658
  T62 grid exactly. rverify GREEN at bf5257b, 90
  mutants, 0 missed; preflight GREEN (586 audit
  census, BUILD 0 warnings). Spec 18,373 bytes md5
  7dd46db7a368a73da0973c2042cb8ef1
  (authored-plus-newline md5
  b004457bd723014ab847f5b0154cada8 - the value the
  ritual gated and matched; canvas md5
  b8d1f22985fc9db1fd47ae52743b0c97). NEXT - R664:
  Sixth Level Spells (capture pp. 143-147), prefix
  dhy (verify free), audit "R664 OA sixth level
  spells audit", include after rules/oal5spells.h
- R664 LANDED 2026-10-19: commit c0a5a683535eb2e0028617c47e90969f84983893
  (census 586 -> 587, pushed 28d5951..c0a5a68),
  SIXTH LEVEL SPELLS - the 12 sixth
  level shukenja spell stat blocks,
  capture pp. 143-147: rules/oal6spells.h,
  prefix dhy (verified free), ONE gap flip
  (single-line child label), 15 consts,
  21 inlines (grid tag L6Data, 12 rows x
  6 cols), gap census 116/119 -> 117/118:
  all 12 stat blocks cross-checked spell
  by spell between the passes (print pp.
  143-147 vs compressed pp. 69-72), zero
  contested stat reads - alteration the
  most common school at five spells, the
  other seven appearing schools exactly
  once each (no invocation this level);
  two half saves (force shapechange,
  smite); longevity the one-day cast,
  pinned 8640 segments; instruct the
  three-turn and find the path the
  three-round cast; force shapechange's
  components read V, S, M in the
  compressed, the print line cutting at
  its page boundary (the R660 detect
  charm pattern). The reversible four
  (find the path, heal, immunity to
  weapons, quickgrowth) and sohei four
  (find the path, immunity to weapons,
  smite, speak w/ monsters) match the
  R658 T62 grid exactly. rverify GREEN
  at 28d5951, 87 mutants, 0 missed;
  preflight GREEN (587 audit census,
  BUILD 0 warnings). Spec md5
  ddb798032d4f7b13c3eba2245f851878
  (authored-plus-newline md5
  2e5c95cd304aa579acfe97a23627d02f -
  the value the ritual gated and
  matched; canvas md5
  7c3317399151b06d03d1d645bb742869).
  NEXT - R665: Seventh Level Spells
  (capture pp. 147-152), prefix dhz
  (verify free), audit "R665 OA seventh
  level spells audit", include after
  rules/oal6spells.h
- R665 LANDED 2026-10-19: commit f5652858ad7f7ce01928dba09f90067828dfa29b
  (census 587 -> 588, pushed c0a5a68..f565285),
  SEVENTH LEVEL SPELLS - the 12 seventh
  level shukenja spell stat blocks,
  capture pp. 147-152: rules/oal7spells.h,
  prefix dhz (verified free at c0a5a68), ONE
  gap flip (single-line child label), 16
  consts, 22 inlines (grid tag L7Data, 12
  rows x 6 cols), gap census 117/118 ->
  118/117 - THE SHUKENJA SPELL CHAPTER ROUNDS
  COMPLETE: all 12 stat blocks cross-checked
  spell by spell between the passes (print pp.
  147-152 vs compressed pp. 71-73), zero
  contested stat reads - conjuration/summoning
  and necromantic tie as the most common
  school at three spells each; exaction dual
  Evocation/Alteration pinned primary evocation
  (the abjure and aid precedent); no divination
  or illusion this level. Resurrection alone
  reads Reversible (the destruction reverse) -
  the single mark matching the R658 T62
  reversible column; holy (unholy) word
  carries no reversible marker in either pass
  despite the parenthetical name; ancient curse
  alone sohei-usable, matching the T62 sohei
  column. Astral spell the three-turn cast
  (180), three one-turn casts (divine wind,
  reincarnate, resurrection), five one-round,
  quest eight segments, gate five, holy word
  the single segment; two neg. saves (compel,
  quest), two special (exaction, restore
  spirit - the system shock roll), no half
  saves. One prose divergence outside the stat
  grid: compel's greater-than-150% bracket
  penalty reads +4 in the print against -4 in
  the compressed - the print settles. rverify
  GREEN at c0a5a68, 88 mutants, 0 missed;
  preflight GREEN (588 audit census, BUILD 0
  warnings). Spec md5
  75fe5ba8d0842c437e71e4859a7721a8
  (authored-plus-newline md5
  4861cd156260865fbe1915d9347f8298 - the value
  the ritual gated and matched; canvas md5
  f764ee61f5bfecb47e7cccc74289433f). NEXT -
  R666: Table 63 Divination Results (capture
  p. 117, rides its own box), prefix dia
  (verify free), audit "R666 OA divination
  results audit"
- R666 LANDED 2026-10-19: commit 633d0d8795da665ecbf052708d00f35d502e904f
  (census 588 -> 589, pushed f565285..633d0d8),
  TABLE 63 DIVINATION RESULTS - the
  five omen bands, capture p. 117:
  rules/oat63divination.h, prefix dia
  (the NEW FAMILY - dh exhausted at
  R665; verified free at f565285 by the
  engine's own call-site check), ONE gap
  flip (single-line child label), 14
  consts, 1 chain, 21 inlines (grid tag
  T63Data, 5 rows x 6 cols - the first
  table-band round of the OA arc: the
  chain maps the 1d10 roll to its band,
  1-2 ill omen, 3-4 great danger, 5-7
  neutral, 8-9 favorable, 10 auspicious,
  the neutral band the widest at three
  faces), gap census 118/117 -> 119/116:
  the five band rows cross-checked line
  by line between the passes (print
  p. 117 vs compressed pp. 59-60), zero
  contested reads - the only OCR
  variance typographic (the compressed
  dropping a period on the neutral row
  and a stray quote on the favorable to
  hit line). The grid: party to hit and
  save, foe to hit, encounter
  multiplier, reaction and travel boost
  by band - the ill omen party
  penalties (-1 to hit and saves)
  conditional on ignoring the advice
  (pinned via diaIllOmenIgnorePenalty),
  the doubled encounters and -10 reaction
  applying outright; great danger shares
  those two and adds the adversaries to
  hit at +1; favorable and auspicious
  travel at half again the rate (pinned
  +50 percent) with opponents to hit at
  -1, auspicious stacking the save +1.
  rverify GREEN at f565285, 48 mutants,
  0 missed; preflight GREEN (589 audit
  census, BUILD 0 warnings). Spec md5
  cc7f6a5485481e45808e06dbaa6e87e6
  (authored-plus-newline md5
  512c2a07318c562896e01a57431488a7 -
  the value the ritual gated and
  matched; canvas md5
  31102f49c488d8290fd675ff8aa34a25).
  NEXT - R667: Table 64 Speak with Dead
  (print p. 132), prefix dib (verify
  free), audit "R667 OA speak with dead
  audit", include after
  rules/oat63divination.h; then Table 65
  Fate (print p. 135), then the wu jen
  spell chapter (Chapter 8: Table 66
  and L1-L9)
- R667 LANDED 2026-10-19: commit eb88e69f073f422cee9f0b487af43c7705ce47b0
  (census 589 -> 590, pushed 633d0d8..eb88e69),
  TABLE 64 SPEAK WITH DEAD - the six
  shukenja level bands, capture p. 132:
  rules/oat64speakdead.h, prefix dib
  (verified free at 633d0d8), ONE gap flip
  (single-line child label), 9 consts,
  1 chain, 13 inlines (grid tag T64Data,
  6 rows x 3 cols), gap census 119/116
  -> 120/115: all six band rows
  cross-checked line by line between the
  passes (print p. 132 vs compressed
  pp. 64-65), zero contested reads - the
  one OCR variance the compressed "2 turn"
  on the 13-15 questioning row against the
  print's 2 turns (the print settles). The
  chain maps the shukenja's level to its
  band (6 and below the least band, 7-8,
  9-12, 13-15, 16-20, more than 20 the
  tail); the ladder grid: the maximum dead
  time in days (7 the week, 30 the month,
  365 the year - the 30-day month and
  365-day year conventions - then a
  decade climb per band to the 1000-year
  greatest band pinned 365000), the
  questioning time in segments (10, 30,
  60, 120, 180, 360 - one round to six
  turns, the round=10 and turn=60
  conventions), and the question counts
  climbing one per band from two to seven
  - the band ordinal plus the
  dibT64QuestionsBase pin. rverify GREEN
  at 633d0d8, 32 mutants, 0 missed;
  preflight GREEN (590 audit census,
  BUILD 0 warnings). Spec md5
  c665905d2afd90fd7742c5c604c2eb36
  (authored-plus-newline md5
  3d1a735d8c9fea01fe6936cec20551f7 -
  the value the ritual gated and matched;
  canvas md5
  16fcf3842586d1ef656522337c030503).
  NEXT - R668: Table 65 Fate (print
  p. 135), prefix did (verified free - dic is NOT free: the dice() helpers),
  audit "R668 OA fate audit", include
  after rules/oat64speakdead.h; then the
  wu jen spell chapter (Chapter 8: Table
  66 and L1-L9)
- R668 LANDED 2026-10-20: commit f2ddaaaf29a2e3f0ff642ba408e997403d50babb
  (census 590 -> 591, pushed eb88e69..f2ddaaa),
  TABLE 65 FATE - the twelve fate bands of
  the 1d20 roll, capture p. 135:
  rules/oat65fate.h, prefix did (the
  dic GUESS WAS WRONG - the dice()
  helpers occupy it, caught by the
  engine's prefix gate at the first run;
  did verified free at eb88e69), ONE gap
  flip (single-line child label), 6
  consts, 1 chain, 8 inlines (grid tag
  T65Data, 12 rows x 1 col), gap census
  120/115 -> 121/114 - THE SHUKENJA
  CHAPTER BOXES ALL CLOSED: the twelve
  band rows cross-checked line by line
  between the passes (print p. 135 vs
  compressed p. 66), zero contested reads
  - the outcome prose agrees verbatim.
  The bands pin as a chain (the 1d20
  mapped to its band: rolls 1, 2, 3 the
  single-face bands, 4-5, 6-7, 8-9 and
  16-17 the two-face pairs, 10-12 and
  13-15 the three-face widest bands at
  the ladder middle, 18, 19 and 20 the
  single-face tail) and a one-column
  face-width grid (six single, four
  two-face, two three-face bands summing
  to the twenty die faces); the outcomes
  are DM-adventure prose riding the
  column comment, NOT pinned cells; the
  one-fate-at-a-time rule pins as the
  didT65FateLimit const. SECOND authoring
  repair: a census example using Python
  comprehensions does not survive the
  py-to-C++ audit translation (the
  engine aborted on a split identifier,
  the R426 class) - replaced with plain
  equality chains and subtotals. rverify
  GREEN at eb88e69, 29 mutants, 0
  missed; preflight GREEN (591 audit
  census, BUILD 0 warnings). Spec md5
  0b96e7648637efda1e880a9885128daf
  (authored-plus-newline md5
  2d679b2311d1d3b0e7332f43d25b55dc -
  the value the ritual gated and matched;
  canvas md5
  2aabe785a022e754d048fe847df55945).
  NEXT - R669: the wu jen spell chapter
  OPENS - Table 66 Wu Jen Spells
  (capture p. 153, the full spell list by
  level), prefix die (verify free - the
  dice() lesson: check the engine's
  call-site regex, not just whole-word
  grep), audit "R669 OA wu jen spell
  list audit", include after
  rules/oat65fate.h
- R669 LANDED 2026-10-20: commit f0cdd266503487243703bb2393e29dbfca59ca13
  (census 591 -> 592, pushed f2ddaaa..f0cdd26),
  TABLE 66 WU JEN SPELLS - the full
  wu jen spell list by level, capture
  pp. 153-155: rules/oawjspelllist.h,
  prefix die (verified free at f2ddaaa -
  only comment-word matches, the engine's
  call-site check governs), ONE gap flip
  (the box label spans TWO lines - "the
  full spell list by level" rides the
  second line; the flip replaced both),
  23 consts, 32 inlines (grid tag
  WJT66Data, 30 rows x 9 cols - the R658
  T62 pattern restated for the wu jen:
  the -99 sentinel pads the ordinals
  beyond each level's count, sentinel
  census [0,0,6,6,6,6,18,16,17]), gap
  census 121/114 -> 122/113 - THE WU JEN
  CHAPTER OPENS: all nine level columns
  cross-checked name by name between the
  passes (print pp. 153-155 vs compressed
  pp. 74-75). The roster: 30/30/24/24/24/
  24/12/14/13 - 195 spells total, the
  ordinal max 30. ONE contested name:
  the sixth level Glassee reads Glasses
  in the print OCR against Glassee in
  the compressed - the compressed settles
  the known PHB name (noted in the banner
  and an example note); the other
  variances typographic (Haute for Haste,
  Ventiloquism, the print's stray r on
  Duo-Dimension, the Power Word period
  artifacts). The element census: Earth
  the most common at 16, Air 13, Fire
  11, Water 10, Nature 7, the lone Wood
  mark (warp wood), four All marks
  (elemental burst, scry, elemental
  turning, conjure elemental), the two
  duals (cloudburst Water/Air code 8,
  water to poison Nature/Water code 9)
  - 64 tagged against 131 untagged. The
  memorization doctrine pins as two
  consts: the six hours of restful
  meditation and the 3d6 starting-spell
  roll. rverify GREEN at f2ddaaa, 293
  mutants, 0 missed (the biggest battery
  yet - every cell of the 30x9 grid);
  preflight GREEN (592 audit census,
  BUILD 0 warnings). Spec md5
  7a0ab56a40a3c40a5bb82b5b539e2ea8
  (authored-plus-newline md5
  7fdf1e5c6d06d29ec8baf65c2d852a67 -
  the value the ritual gated and matched;
  canvas md5
  cf8c76b1c807232b279800a9df38c552).
  NEXT - R670: the wu jen First Level
  Spells (capture pp. 155-165, the 30
  stat blocks - school, components,
  casting time, save, the element mark
  riding the R669 grid), prefix dif
  (verify free), audit "R670 OA wu jen
  first level spells audit", include
  after rules/oawjspelllist.h
- R670 LANDED 2026-10-20: commit d50aeaf87b9292c4d97ecf84b2527d45badfc29d
  (census 592 -> 593, pushed f0cdd26..d50aeaf),
  WU JEN FIRST LEVEL SPELLS - the 30
  first level wu jen spell stat
  blocks, capture pp. 155-165:
  rules/oawjl1spells.h, prefix dif
  (verified free at f0cdd26), ONE gap
  flip (single-line child label), 18
  consts, 24 inlines (grid tag
  WJL1Data, 30 rows x 6 cols), gap
  census 122/113 -> 123/112: all 30
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  155-165 vs compressed pp. 75-79),
  zero contested stat reads - the
  variances typographic (the print's
  fumble-lingers against the
  compressed fumble-fingers for the
  prestidigitation reverse, the
  print's pared for para-elemental in
  the melt prose). Alteration-heavy:
  15 of the 30 spells, conjuration
  six, divination three,
  enchantment/charm, evocation and
  illusion two each - no necromantic
  or abjuration. TWO component
  oddities pinned as cells:
  ventriloquism the lone V,M without
  the somatic (bitmask 5), and secret
  signs the Components: Special line
  (bitmask 0, none of the three - the
  component whatever method sends the
  message, the spell castable even
  bound and gagged). Elemental burst
  alone takes the half save (the
  sliver and spark damage halved);
  drowsy insects and hypnotism the
  negation; four special. Casts: 13
  one-segment, 12 one-round, warp
  wood the lone four-segment, fiery
  eyes and ghost light the
  five-segment pair. Six reversible
  (accuracy, comprehend languages,
  prestidigitation, read magic, still
  water, swim). The SIXTH column is
  the NEW wu jen convention: the
  element marks cross-checking the
  R669 dieWJT66L1Element grid - the 12
  tagged cells matching exactly.
  rverify GREEN at f0cdd26, 198
  mutants, 0 missed; preflight GREEN
  (593 audit census, BUILD 0
  warnings). Spec md5
  c74a746b72b3ce7e9fa157bf0f880369
  (authored-plus-newline md5
  df7ba0c6fbdef9490b537b9b375faf44 -
  the value the ritual gated and
  matched; canvas md5
  110000cefc484e7ad5d39cfe6870d050).
  NEXT - R671: the wu jen Second
  Level Spells (capture pp. 165-170,
  the 30 stat blocks), prefix dig
  (verify free), audit "R671 OA wu
  jen second level spells audit",
  include after rules/oawjl1spells.h
- R671 LANDED 2026-10-20: commit 234a53ba34a0be22ad9a93f1b963225802137cb3
  (census 593 -> 594, pushed d50aeaf..234a53b),
  WU JEN SECOND LEVEL SPELLS - the 30
  second level wu jen spell stat
  blocks, capture pp. 165-173:
  rules/oawjl2spells.h, prefix dig
  (verified free at d50aeaf), ONE gap
  flip (single-line child label), 20
  consts, 26 inlines (grid tag
  WJL2Data, 30 rows x 6 cols), gap
  census 123/112 -> 124/111: all 30
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  165-173 vs compressed pp. 79-82),
  zero contested stat reads.
  Alteration-heavy again: 11 of the 30
  spells, evocation six, divination
  and illusion five each, conjuration,
  enchantment/charm and abjuration one
  each (animal companion the lone
  enchantment/charm, protection from
  charm the lone abjuration). TWO
  dual-school prints pinned primary
  alteration (the exaction precedent):
  bind the Alteration/Enchantment dual
  and whispering wind the
  Alteration/Phantasm dual; stinking
  cloud printed Evocation, pinned 3.
  The component census: 19 VSM, seven
  verbal and somatic, hypnotic pattern
  and vocalize the S,M pairs without
  the verbal, omen the lone V,M, knock
  the lone verbal-only oddity. Wind
  breath alone takes the half save
  (the wind damage halved); five
  negation, three special. Casts: 16
  two-segment, seven one-round, FOUR
  one-turn (animal companion, enchanted
  blade, omen, strength), fire shuriken
  and phantasmal force three-segment,
  knock the lone single segment. Two
  reversible (detect evil, locate
  object). The SIXTH column cross-checks
  the R669 dieWJT66L2Element grid - the
  10 tagged cells (six Air, two Water,
  two Fire) matching exactly. rverify
  GREEN at d50aeaf, 200 mutants,
  0 missed. Spec md5
  b5e2b485a21fccd0be87abde0db17d46
  (authored-plus-newline md5
  758efbfae817822006e8460212845f2b -
  the value the ritual gated and
  matched; canvas md5
  5c63deaf787a60efedcc265d05780571).
  NEXT - R672: the wu jen Third Level
  Spells (capture pp. 170-177, the 24
  stat blocks), prefix dih (verified
  free at 234a53b), audit "R672 OA wu
  jen third level spells audit",
  include after rules/oawjl2spells.h
- R672 LANDED 2026-10-20: commit f6b10e54b3174de9a64fc7f1ddfdc0047b775102
  (census 594 -> 595, pushed 234a53b..f6b10e5),
  WU JEN THIRD LEVEL SPELLS - the 24
  third level wu jen spell stat
  blocks, capture pp. 173-181:
  rules/oawjl3spells.h, prefix dih
  (verified free at 234a53b), ONE gap
  flip (single-line child label), 20
  consts, 26 inlines (grid tag
  WJL3Data, 24 rows x 6 cols), gap
  census 124/111 -> 125/110: all 24
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  173-181 vs compressed pp. 82-85),
  zero contested stat reads - the
  variances typographic or prose-only
  (the compressed Scy for scry in the
  header, the print 6-10 against the
  compressed 8-10 for the cloudburst
  large-fire quench, the feign death
  duration sign, the fire rain 1d8
  read as 108 in the compressed).
  Alteration again the most common:
  seven of the 24, enchantment/charm
  and illusion four each, divination
  three, evocation and abjuration two
  each, conjuration and necromantic
  one each (animate fire the lone
  conjuration, feign death the lone
  necromantic). TWO dual-school prints
  pinned primary (the exaction
  precedent): fabricate the
  Enchantment/Alteration dual pinned
  1, face the Illusion/Phantasm;
  Enchantment/Charm dual pinned 9.
  THREE spells take the Casting Time:
  Special line (fabricate, illusionary
  script, memory) pinned -1, the R662
  exorcise convention; four one-turn
  casts, five one-round, seven
  three-segment, cloudburst and fire
  rain five segments, statue the lone
  seven-segment, feign death the lone
  single segment. Components: 19 VSM,
  dispel magic and feign death the VS
  pair, suggestion and tongues the
  V,M pairs, hold person the lone
  verbal-only. Four negation saves,
  four special, fire rain and steam
  breath the two half saves. Four
  reversible (face, magnetism, memory,
  tongues). The SIXTH column
  cross-checks the R669
  dieWJT66L3Element grid - the seven
  tagged cells matching exactly, with
  cloudburst carrying the Water/Air
  dual code 8 (the first dual element
  in a stat grid). rverify GREEN at
  234a53b, 164 mutants, 0 missed.
  Spec md5
  27262a7799827b43ba8c6f8f85dd0164
  (authored-plus-newline md5
  33e415bda31ac72c4d3b5c4a4d162ebc -
  the value the ritual gated and
  matched; canvas md5
  38a0367b457d4af6e552946103d16b8e).
  NEXT - R673: the wu jen Fourth
  Level Spells (capture pp. 177-188,
  the 24 stat blocks), prefix dii
  (verified free at f6b10e5), audit
  "R673 OA wu jen fourth level spells
  audit", include after
  rules/oawjl3spells.h
- R673 LANDED 2026-10-20: commit fba4d3493287cee1363dc6c74ea0358ce879d100
  (census 595 -> 596, pushed f6b10e5..fba4d34),
  WU JEN FOURTH LEVEL SPELLS - the 24
  fourth level wu jen spell stat
  blocks, capture pp. 181-188:
  rules/oawjl4spells.h, prefix dii
  (verified free at f6b10e5), ONE gap
  flip (single-line child label), 21
  consts, 27 inlines (grid tag
  WJL4Data, 24 rows x 6 cols), gap
  census 125/110 -> 126/109: all 24
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  181-188 vs compressed pp. 85-88),
  zero contested stat reads (the
  variances typographic or prose-only -
  the compressed minus signs for the
  spectral force plus signs, the
  degree marks for the inch marks).
  THE INVOCATION SCHOOL DEBUTS for
  the wu jen (dream vision, vengeance,
  both code 8); wall of bones the
  lone conjuration, its dual school
  Conjuration/Necromantic pinned
  primary 4 (the exaction precedent);
  alteration and enchantment/charm tie
  at six each, evocation four,
  abjuration three, illusion two; no
  divination spell this level. THREE
  verbal-only spells (dimension door,
  polymorph self, vengeance), 13 VSM,
  seven VS, shout the lone V,M.
  Casts: seven four-segment (the most
  common), seven one-round, three
  one-turn, four three-segment,
  dimension door and shout the single
  segments, elemental turning the lone
  five. Eight negation saves, three
  special, NO half save - the first
  wu jen level without one. Three
  reversible (dream vision, remove
  curse, reverse flow). The SIXTH
  column cross-checks the R669
  dieWJT66L4Element grid - the seven
  tagged cells matching exactly
  (dimension door Earth, elemental
  turning All, fire enchantment, melt
  metal and wall of fire Fire, plant
  growth and polymorph other Nature).
  ONE rverify RED on the way: a
  casting-time example misindexed
  polymorph other (cast 4) where it
  meant transfix (cast 10) - the
  healthy-base gate caught it, fixed,
  second run GREEN. rverify GREEN at
  f6b10e5, 165 mutants, 0 missed.
  Spec md5
  360c0d66abef99e31c5ff2e7b870fe52
  (authored-plus-newline md5
  da829f84dca0d3c4be8574cb22f01f1b -
  the value the ritual gated and
  matched; canvas md5
  d8dc875318e0e29b3c0e64089e6811e9).
  NEXT - R674: the wu jen Fifth
  Level Spells (capture pp. 189-196,
  the 24 stat blocks), prefix dij
  (verified free at fba4d34), audit
  "R674 OA wu jen fifth level spells
  audit", include after
  rules/oawjl4spells.h
- R674 LANDED 2026-10-20: commit 7cf655dd2108b7f795f94244f18fd14636b90759
  (census 596 -> 597, pushed fba4d34..7cf655d),
  WU JEN FIFTH LEVEL SPELLS - the 24
  fifth level wu jen spell stat
  blocks, capture pp. 189-196:
  rules/oawjl5spells.h, prefix dij
  (verified free at fba4d34), ONE gap
  flip (single-line child label), 18
  consts, 24 inlines (grid tag
  WJL5Data, 24 rows x 6 cols), gap
  census 126/109 -> 127/108: all 24
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  189-196 vs compressed pp. 87-91),
  zero contested stat reads - the
  variances typographic or prose-only
  (the fire breath save printed 1/z
  for the half, the wall of stone
  range garbled X12, the servant
  horde count 2d6 + 1 in the print
  against 2d6 - 1 in the compressed -
  a prose divergence outside the
  grid). Alteration-heavy yet again:
  10 of the 24, evocation eight,
  conjuration two, and FOUR
  lone-school spells - animate dead
  the lone necromantic, aiming at the
  target the lone invocation, shadow
  door the lone illusion, dismissal
  the lone abjuration with its odd
  triple-line print Abjuration)
  Reversible (Conjuration/Summoning)
  pinned primary 7; no divination or
  enchantment/charm spell this level.
  TWO somatic-only spells (aiming at
  the target, shadow door) - the
  first somatic-only spells of the wu
  jen levels; 20 VSM, animal growth
  and telekinesis the VS pair; no
  verbal-only or V,M spell this
  level. Casts: nine five-segment
  (the most common), six one-round,
  three three-segment, two one-turn,
  animate dead the five-ROUND cast
  pinned 50 segments (the longest of
  the level), servant horde the lone
  single segment. Three negation
  saves, cone of cold and fire breath
  the two half saves, no special save
  this level. Four reversible (animal
  growth, dismissal, water to poison,
  wood rot). The SIXTH column
  cross-checks the R669
  dieWJT66L5Element grid - the 13
  tagged cells matching exactly (the
  richest element column yet), with
  water to poison carrying the
  Nature/Water dual code 9 and six
  Earth marks. TWO rverify REDs on
  the way, both one class: stray wrong
  clauses in the school example
  (water to poison indexed as
  evocation) - the healthy-base gate
  caught each, fixed, third run
  GREEN. rverify GREEN at fba4d34,
  162 mutants, 0 missed. Spec md5
  3c44ac8faedb50f97fd1cb7a2f6e0159
  (authored-plus-newline md5
  4e0e9f006195d365579556b588510e03 -
  the value the ritual gated and
  matched; canvas md5
  9d42f37aa4ec6c9113e3bf6780f31bae).
  NEXT - R675: the wu jen Sixth
  Level Spells (capture pp. 196-202,
  the 12 stat blocks), prefix dik
  (verified free at 7cf655d - only
  the comment-word dikes, the R669
  die precedent), audit "R675 OA wu
  jen sixth level spells audit",
  include after rules/oawjl5spells.h
- R675 LANDED 2026-10-20: commit b23dcfea241d5382ce4597804d7a77bfe112b4fc
  (census 597 -> 598, pushed 7cf655d..b23dcfe),
  WU JEN SIXTH LEVEL SPELLS - the 24
  sixth level wu jen spell stat
  blocks, capture pp. 196-203:
  rules/oawjl6spells.h, prefix dik
  (verified free at 7cf655d - only
  the comment-word dikes), ONE gap
  flip (single-line child label), 18
  consts, 24 inlines (grid tag
  WJL6Data, 24 rows x 6 cols), gap
  census 127/108 -> 128/107: all 24
  stat blocks cross-checked spell by
  spell between the passes (print pp.
  196-203 vs compressed pp. 90-93),
  zero contested stat reads - the
  R669-settled Glassee reading clean
  in both stat-block passes. The
  level carries THREE dual-school
  prints (the most of any wu jen
  level yet), all pinned primary (the
  exaction precedent): gambler's luck
  the Invocation; Enchantment/Charm
  dual pinned 8, spiritwrack and
  sword of darkness both pinned 3;
  THREE Casting Time: Special lines
  (enchant an item, move earth,
  spiritwrack) pinned -1, the R662
  exorcise convention; geas the lone
  verbal-only; NO half save this
  level. Schools: nine alteration,
  three illusion, two each of
  invocation, conjuration,
  enchantment/charm, divination and
  evocation, speak with dead the lone
  necromantic, repulsion the lone
  abjuration. Components: 17 VSM,
  three VS (aura, true sight, veil),
  three V,M (mass suggestion,
  repulsion, spiritwrack). Four
  reversible (aura, lower water,
  metal to rust, stone to flesh).
  The element column cross-checks the
  R669 dieWJT66L6Element grid: seven
  tagged cells matching exactly -
  five Earth, two Water. The mid-
  build catch: the generator's own
  sanity assert flagged the round-
  cast census as four; both OCR
  passes settle true sight at 1
  round - FIVE one-round casts (aura,
  glassee, metal to rust, true sight,
  warp stone), alongside six six-
  segment (the most common), five
  one-turn, two single segments. The
  const dikWJL6RoundCasts lands the
  correct 5 (true sight named in its
  comment), but the landed header
  OPENER prose census still reads
  "four one-round" - a one-word
  comment slip the battery cannot
  catch (it tests consts, not prose);
  rverify GREEN first try at 7cf655d,
  162 mutants, 0 missed. R676 should
  amend that header line in the same
  commit as its own round. Spec md5
  76761fd780f23a44c470be1c8b9eab3c
  (authored-plus-newline md5
  f0dd68a22db1cbf2dc966146c91675db -
  the value the ritual gated and
  matched; canvas md5
  d1e314d8cc3b48eb66a06547e999e154).
  NEXT - R676: the wu jen Seventh
  Level Spells (capture pp. 203-207,
  the 12 stat blocks), prefix dil
  (verified free at b23dcfe - the
  R675 regtest diff adds zero dil
  tokens; only the string-literal
  dill, the R669 die precedent),
  audit "R676 OA wu jen seventh
  level spells audit", include after
  rules/oawjl6spells.h
- R676 LANDED 2026-10-20: commit
  343227ea7198171f40c7c1ead459933d87e1a28f
  (census 598 -> 599, pushed b23dcfe..343227e),
  WU JEN SEVENTH LEVEL SPELLS - the
  12 seventh level wu jen spell stat
  blocks, capture pp. 203-207:
  rules/oawjl7spells.h, prefix dil
  (verified free at b23dcfe - only
  the string-literal dill, the R669
  die precedent), ONE gap flip
  (single-line child label), 12
  consts, 18 inlines (grid tag
  WJL7Data, 12 rows x 6 cols), gap
  census 128/107 -> 129/106: all 12
  stat blocks cross-checked spell by
  spell between the passes (print
  pp. 203-207 vs compressed pp.
  93-95), zero contested stat reads -
  the print Components' V typo on
  vanish reading V in both passes;
  body outside body the OA printing
  its near-duplicate of the sixth
  level vessel at the seventh. THREE
  dual-school prints again, all
  pinned primary (the exaction
  precedent): elemental servant the
  Conjuration/Summoning;
  Enchantment/Charm dual pinned 4,
  ice blight the
  Evocation/Summoning dual pinned 3,
  obedience the
  Enchantment/Evocation dual pinned
  1. Conjuration the most common
  school at five; alteration and
  evocation two each; NO illusion,
  invocation or abjuration spell this
  level. FOUR verbal-only spells
  (limited wish, power word stun,
  tool, vanish) - the most of any wu
  jen level yet; withering palm the
  lone V,S and the lone half save;
  limited wish carries BOTH the
  Casting Time: Special line (pinned
  -1, the R662 convention) and the
  special save; ice blight (drought)
  the one reversible, Water the one
  element tag matching the R669
  dieWJT66L7Element grid exactly.
  rverify GREEN first try at b23dcfe,
  84 mutants, 0 missed. LESSONS: the
  sed amendment to the R675 header
  did NOT ride the landing - rn does
  a targeted git add of its own five
  files, so the oawjl6spells.h edit
  stayed uncommitted, landed as the
  R676b follow-up commit 9525d0c
  (verified: four -> five one-round);
  future header amendments need
  their own commit); the user's ./bn 676
  detour (struck per the R516 rule)
  caused no drift - the spec md5
  printed the authored value. The
  canvas delivery itself stumbled this
  round: the first publish did not
  surface for the user, a same-folder
  delete/recreate did not either, and
  only a FRESH canvas folder name
  (r676-spec) rendered - on any
  future publish failure, publish
  under a new name immediately rather
  than rewriting the same folder.
  Spec md5 a024f5b954fa0d94392a67f
  7997e53ec (authored-plus-newline
  md5 e10ccc352abab87d144b62b83090b
  95a - the value the ritual gated
  and matched; canvas md5
  91cd39ddc599622df3ecf0c86ddec459).
  NEXT - R677: the wu jen Eighth
  Level Spells (capture pp. 207-213,
  the 14 stat blocks), prefix dim
  (verify free at 343227e - only the
  comment-words dim, dims, diminish,
  the R669 die precedent), audit
  "R677 OA wu jen eighth level
  spells audit", include after
  rules/oawjl7spells.h
- R677 LANDED 2026-10-20: commit
  3039a769ba35e237e1b93dbc96c9895560b528dd
  (census 599 -> 600, pushed 9525d0c..3039a76),
  WU JEN EIGHTH LEVEL SPELLS - the
  14 eighth level wu jen spell stat
  blocks, capture pp. 207-213:
  rules/oawjl8spells.h, prefix dim
  (verified free at 9525d0c - only
  comment-words, the R669 die
  precedent), ONE gap flip
  (single-line child label), 13
  consts, 19 inlines (grid tag
  WJL8Data, 14 rows x 6 cols), gap
  census 129/106 -> 130/105: all 14
  stat blocks cross-checked spell by
  spell between the passes (print
  pp. 207-213 vs compressed pp.
  95-97), zero contested stat reads -
  the whirlwind print save garbling
  as 112, the compressed pass reading
  1/2, settled as the half save (the
  R674 fire breath precedent class).
  SUMMONING WIND the FIRST
  school-less print of the wu jen
  levels - the bare heading in both
  stat-block passes, the roster
  silent - pinned 0, the grid school
  comment carrying the new code.
  Antipathy/sympathy the six-TURN
  cast pinned 360 segments, the
  longest cast of the wu jen levels
  yet; NO Casting Time: Special line
  this level. TWO duals, both pinned
  primary alteration: finding the
  center (Alteration/Invocation) and
  incendiary cloud
  (Alteration/Evocation), both 6;
  finding the center the lone
  somatic-only, the first since the
  L5 pair. Alteration the most
  common school at seven,
  conjuration four (call, power word
  blind, symbol, whirlwind); no
  divination, necromantic, invocation
  or illusion spell this level. 10
  VSM, mind blank and summoning wind
  the V,S pair, power word blind the
  lone verbal-only. Call the lone
  negation save; antipathy/sympathy,
  polymorph any object and symbol
  special; incendiary cloud and
  whirlwind the two half saves.
  Giant size the one reversible. The
  element column cross-checks the
  R669 dieWJT66L8Element grid: FOUR
  tagged cells matching exactly -
  three Air (cloud trapeze, summoning
  wind, whirlwind), one Fire
  (incendiary cloud), the richest
  Air column of the wu jen levels.
  rverify GREEN first try at 9525d0c,
  97 mutants, 0 missed. PREFIX
  LESSON: din is TAKEN for R678 -
  the dinosaurSubBands( call collides
  with the engine paren gate (the
  first prefix in the di- block lost
  to a real symbol rather than a
  string literal); R678 takes dio.
  Spec md5 84fe33cb6a49e4caadbf1e91
  e5f3fca6 (authored-plus-newline md5
  716a5de00594f378a51f813f94b188ff -
  the value the ritual gated and
  matched; canvas md5
  b03324bd36d3ca05eae8ffe13de13f31,
  the fresh-name publish lesson
  applied and it surfaced on the
  first try). NEXT - R678: the wu
  jen Ninth Level Spells (capture
  pp. 213-216, the 13 stat blocks),
  prefix dio (verified free at
  3039a76), audit "R678 OA wu jen
  ninth level spells audit", include
  after rules/oawjl8spells.h
- R678 LANDED 2026-10-20: commit
  b44639162fbf8227a45070dfd3b28dcf0f059e89
  (census 600 -> 601, pushed 3039a76..b446391),
  WU JEN NINTH LEVEL SPELLS - the
  13 ninth level wu jen spell stat
  blocks, capture pp. 213-216: THE
  WU JEN SPELL BOOK GRID CLOSED -
  all nine levels pinned (R670-R678,
  197 stat blocks).
  rules/oawjl9spells.h, prefix dio
  (din TAKEN - the dinosaurSubBands
  call collides with the engine
  paren gate, the first prefix lost
  to a real symbol), ONE gap flip,
  14 consts, 20 inlines (grid tag
  WJL9Data, 13 rows x 6 cols), gap
  census 130/105 -> 131/104: all 13
  stat blocks cross-checked spell by
  spell between the passes (print
  pp. 213-216 vs compressed pp.
  97-98), zero contested stat reads -
  the roster carrying two garbles
  (Instant Regenerate, Power Word.
  III) against the clean stat-block
  headings in both passes,
  roster-only variances outside the
  grid. SIX nine-segment casts
  (astral spell, crystalbrittle,
  gate, imprisonment, shape change,
  time stop) - the ninth level
  signature, the most common cast of
  the level; the opening quartet
  (astral spell, crystalbrittle,
  gate, imprisonment) all V,S only.
  Wish carries BOTH the lone Special
  cast (pinned -1, the R662
  convention) and the special save;
  power word kill, time stop and
  wish the three verbal-only. Summon
  spirit the lone dual
  (Conjuration/Summoning; Necromantic)
  pinned primary conjuration 4;
  conjuration the most common school
  at five; imprisonment the lone
  abjuration and the one reversible;
  tsunami the lone half save;
  instant regeneration the lone
  necromantic. The element column
  closes the book cross-check:
  crystalbrittle Earth, internal fire
  Fire, tsunami Water, matching the
  R669 dieWJT66L9Element grid
  exactly. rverify GREEN first try at
  3039a76, 92 mutants, 0 missed.
  Spec md5 4539a2084a2a26487f7315b5
  006669af (authored-plus-newline md5
  3981679decea584275e5e8e5c52c59f3 -
  the value the ritual gated and
  matched; canvas md5
  c5f6eb65052a57a412000e75fb1832ab).
  NEXT - R679: the OA Chapter 9
  Combat arc opens - the Summary of
  the Combat Sequence (capture p.
  218), prefix dip (verify free at
  b446391 - only comment-word dips,
  the R669 die precedent), audit
  "R679 OA combat sequence audit",
  include after rules/oawjl9spells.h
- R679 LANDED 2026-10-20: commit
  8bd8801808b4c0fe016925c0c937f72424572b5e
  (census 601 -> 602, pushed b446391..8bd8801),
  OA COMBAT SEQUENCE - the Summary of
  the Combat Sequence, capture p.
  218: rules/oacombatseq.h, prefix
  dip (verified free at b446391),
  ONE gap flip, 6 consts + 10 bools
  (16 inlines, no table - the first
  no-grid doctrine round of the OA
  arc), gap census 131/104 -> 132/
  103. THE PROVENANCE SHIFT: the
  compressed-print capture ends mid
  ninth level spells, so from
  Chapter 9 onward the print pass
  is the SOLE surviving authority -
  single-pass pins, contested reads
  settling book-internal first,
  then against the physical copy;
  the banner and gap-flip text both
  carry it. The five resolution
  steps: (1) surprise 1-2 on 1d6,
  often impossible from visibility,
  surroundings or noise; (2) the
  players state their actions,
  announcing subdue/disarm/unhorse;
  (3) initiative 1d6 only without
  surprise, kensai and wu jen able
  to modify the die roll; (4) the
  kensai/wu jen first-strike, the
  1d20 to hit against the combat
  table, ki stated before the die,
  shukenja ki stated before any
  save, the four damage modifiers
  (strength, magical weapons,
  weapons of quality, ki powers),
  subdual damage recorded
  separately; (5) the initiative
  loser then performs step 4. The
  prose codifies per the R431
  calculus - no printed grid
  needed. rverify GREEN first try
  at b446391, 16 mutants, 0 missed.
  Spec md5 375102a4d772d747f118b560
  bc0d0d66 (authored-plus-newline
  md5 429bee1fc324ae13be158301e821
  be86 - the value the ritual gated
  and matched; canvas md5
  2c6cf060b715ce3b7d30fa50120d6280).
  NEXT - R680: the Surprise and
  Iaijutsu dueling draw doctrine
  (capture p. 218), prefix diq
  (verified free at 8bd8801 - zero
  repo hits), audit "R680 OA
  iaijutsu surprise audit", include
  after rules/oacombatseq.h
- R680 LANDED 2026-10-20: commit
  9f5856273ca8c769b02d43dd362665669c1ec602
  (census 602 -> 603, pushed 8bd8801..9f58562),
  OA SURPRISE AND IAIJUTSU - the
  dueling draw doctrine, capture p.
  218: rules/oaiaijutsu.h, prefix
  diq (verified free at 8bd8801 -
  zero repo hits), ONE gap flip, 2
  consts + 6 bools (8 inlines, no
  table), gap census 132/103 ->
  133/102. The -1 iaijutsu surprise
  modifier applied to the surprise
  die roll of the character WITHOUT
  the proficiency when only one side
  is trained; the both-trained case
  carrying the -1 on BOTH rolls; the
  special-situations scope - the
  noncombat encounter suddenly
  erupting into attack (the
  kneel-beside sheathed-weapons
  negotiation the printed example);
  the two exceptions - no modifier
  when weapons are already drawn,
  none when the attack is expected -
  and the peaceful-eruption clause.
  Single-pass pins per the Chapter 9
  provenance shift. LESSON: examples
  must stay WITHIN-ROUND - the
  rverify model parses only the
  round's own header, so a
  cross-round example referencing
  the R679 surprise-die pin threw a
  KeyError RED; replaced with a
  within-round modifier-shape
  example, second run GREEN. Also:
  dir is TAKEN for future prefixes -
  the comment-words directory,
  direct; R681 takes dis. rverify
  GREEN at 8bd8801, 8 mutants, 0
  missed. Spec md5 edeb900b539795c8
  9845e2b0822232af (authored-plus-
  newline md5 7ecf220289bbe8e486d0a
  4ce837ec4a7 - the value the ritual
  gated and matched; canvas md5
  88bc159f2fa9d887f863ed30e5500315).
  NEXT - R681: the Initiative
  Modifiers (capture p. 218), prefix
  dis (verify free at 9f58562 - only
  file-content substrings outside
  the engine paren gate), audit
  "R681 OA initiative modifiers
  audit", include after
  rules/oaiaijutsu.h
- R681 LANDED 2026-10-20: commit
  eb63a121c4cebd133926e5c810daf9b02f09cc19
  (census 603 -> 604, pushed 9f58562..eb63a12),
  OA INITIATIVE MODIFIERS - the
  quickness doctrine, capture pp.
  218-219: rules/oainitmods.h, prefix
  diu (verified free at 9f58562), ONE
  gap flip, 5 consts + 8 bools (13
  inlines, no table), gap census
  133/102 -> 134/101. The quickness
  frame; the roll still once per side
  with the modifier applied for the
  actions of that character only; the
  round dividing into more than two
  phases; the tie not rerolled, all
  acting in the same instant, the
  effects landing only after the
  action completes; the landslide
  rule; the printed kensai example -
  the PC 3 against the NPC 4, the
  kensai riding the same instant at
  modified 4, the hypothetical NPC
  kensai striking first at modified
  5. Single-pass pins per the Chapter
  9 provenance shift. LESSONS: the
  R426 split-identifier guard fired
  on the long four-const example
  chain - audit examples split into
  four short within-round checks; and
  equality-shaped example pins must
  be spelled != - the audit counts
  bad on true, so an == pin is a
  healthy-base RED (2 bad) until
  respelled. rverify GREEN at
  9f58562, 13 mutants, 0 missed.
  Spec md5 ce3bb077c351cdefaac82c650
  c440869 (authored-plus-newline md5
  83bfd3404470134f052acc68abbeb257 -
  the value the ritual gated and
  matched; canvas md5 dadd355a105b0f
  649f2ecdbae4c15d1c). NEXT - R682:
  the Combat Procedures with the
  missile fire from horseback doctrine
  (capture p. 219), prefix div
  (verify free at eb63a12), audit
  "R682 OA combat procedures audit",
  include after rules/oainitmods.h
- R682 LANDED 2026-10-20: commit
  4080171dd4a20735c444d1691600ac9c8064e6ef
  (census 604 -> 605, pushed eb63a12..4080171),
  OA COMBAT PROCEDURES - the missile fire
  from horseback doctrine, capture p.
  219: rules/oahorsefire.h, prefix div
  (verified free at eb63a12 - zero engine
  gate hits), ONE gap flip, 5 consts + 6
  bools (11 inlines, no table), gap census
  134/101 -> 135/100. The mounted-bowman
  doctrine frame; the unmoving-horse
  freedom - any character, no particular
  skill; the horsemanship gate for the
  moving mount; the two-hands rule with
  the knees guidance; the DM rough-ground
  clause forcing the reins and preventing
  bowfire; the rate of fire halved with
  the printed 2/1 to 1/1 and 3/1 to 3/2
  conversions; the speed-based to-hit
  penalties pointing at Table 67 without
  pinning it - the separate p. 220 gap
  item. Single-pass pins per the Chapter
  9 provenance shift. LESSON: do not
  hand-hyphenate audit comment words
  (profi-ciency) - the engine wraps whole
  tokens itself. Also noted: the seed
  mechanic seats the spec prev_record, so
  the R681 seed record rode this ritual.
  rverify GREEN first try at eb63a12, 11
  mutants, 0 missed. Spec md5 a54f237ab92
  2f0462ecc88e5f658ef4a (authored-plus-
  newline md5 db3ad51bebca5bd8e6b3625694cd
  484f - the value the ritual gated and
  matched; canvas md5 2b0c4c97ccdfb7bf9b16
  2e9009f647fd). NEXT - R683: Table 67
  the horseback bowfire modifiers
  (capture p. 220), prefix diw (verified
  free at 4080171 - zero repo hits), audit
  "R683 OA horseback bowfire modifiers
  audit", include after rules/oahorsefire.h
- R683 LANDED 2026-10-20: commit
  cefc1ba03050db726113124162d8b5df3d6b823b
  (census 605 -> 606, pushed 4080171..cefc1ba),
  OA TABLE 67 - the horseback bowfire
  modifiers, capture p. 220:
  rules/oa67bowfire.h, prefix diw
  (verified free at 4080171), ONE gap
  flip, 2 consts + 3 bools (8 inlines,
  3x3 grid tag OA67Data), gap census
  135/100 -> 136/99. The three speed
  bands read as eighths of the animal's
  normal movement - less than half the
  -1, half to less than three-quarters
  the -3, three-quarters to maximum
  speed the -5, each floor and ceiling
  pinned with a contiguity example; the
  modifiers cumulative with range and
  weapon versus armor; the 30-degree
  slight-turning limit, sharper turns
  preventing the bowfire; the horse-like
  creatures clause. THE FIRST CHAPTER 9
  GRID ROUND - single-pass, no
  compressed cross-check. TWO LESSONS:
  (1) the table count field must be a
  CONST FUNCTION (the R678
  dioWJL9SpellCount precedent) - a bare
  int emits the invalid C++ 'b < 3();',
  invisible to rverify (a python
  mirror) and to the engine syntax gate
  (if-conditions only); the ritual
  build gate caught it, ~500 census
  FAILs were the cascade from the one
  compile error; (2) after a preflight
  RED the tree carries the applied
  patches - the v2 re-run hit the R420
  drift abort until the tree was
  restored (git checkout 4080171 --
  four files + rm the header).
  rverify GREEN at 4080171, 14 mutants,
  0 missed. Spec md5 d7f2e29a3b2b79b6a5c
  fb2af97af85d6 (authored-plus-newline
  md5 25945545f55ff2440c1f5a870d2cfec8 -
  the value the ritual gated and
  matched; canvas md5 a461ee196d0cce6261
  0d75f53b2da7d2, the r683-spec-b folder
  per the R676 fresh-name rule). NEXT -
  R684: the Unhorsing doctrine (capture
  p. 220), prefix dix (verified free at
  cefc1ba - zero engine-gate hits), audit
  "R684 OA unhorsing audit", include
  after rules/oa67bowfire.h
- R684 LANDED 2026-10-20: commit
  5e63625cea248cd415357c5ab2f9220155fd5270
  (census 606 -> 607, pushed cefc1ba..5e63625),
  OA UNHORSING - the dismount doctrine,
  capture pp. 220-221: rules/oaunhorsing.h,
  prefix dix (verified free at cefc1ba),
  ONE gap flip, 22 consts + 12 bools (34
  inlines, no table), gap census 136/99 ->
  137/98. The doctrine frame with the
  slain-mount rule and the no-prize clause;
  the mounted natural-20 unhorsing - 3-
  or-more-feet weapons of another mounted
  character, the automatic fall and 1d3
  without horsemanship, the proficiency
  check with it; the foot-soldier bands -
  5-to-9 feet the same chance as mounted,
  10-or-more the 25 percent 16-20 on 1d20;
  the grapple doctrine - the dive-on, the
  1d6 falls, the hang-on state, the every-
  turn re-roll, the -2 rider penalty; the
  footman pull - the man-sized gate, the
  -2/-4/-6 speed ladder, the -1 per extra
  footman to 4, the eight-men surround, the
  free attacks above 12 feet; the set
  defenses - the stake line: 2d6 per stake,
  1d4-1 per 10 feet of depth, the chain -1
  and plate -2 barding reductions, the
  jump check, the other-creatures clause.
  Single-pass pins per the Chapter 9
  provenance shift. rverify GREEN first try
  at cefc1ba, 34 mutants, 0 missed. Spec
  md5 65353b96203c28eff4d00ad774899242
  (authored-plus-newline md5 681c89fa3edff
  c7729e00be31068795b - the value the
  ritual gated and matched; canvas md5
  11a6ad2d7ff557c7e23c56336672ebe6). NEXT
  - R685: the Disarming doctrine (capture
  p. 221), prefix diy (verify free at
  5e63625), audit "R685 OA disarming
  audit", include after rules/oaunhorsing.h
- R685 LANDED 2026-10-20: commit
  e0bebcbc3a59ac9bcec564dfb9682f5436e5d874
  (census 607 -> 608, pushed 5e63625..e0bebcb),
  OA DISARMING - the disarm doctrine,
  capture p. 221: rules/oadisarming.h,
  prefix diy (verified free at 5e63625),
  ONE gap flip, 4 consts + 7 bools (11
  inlines, no table), gap census 137/98 ->
  138/97. The doctrine frame (the charmed
  party member, the capture without harm);
  the two methods - the parry-out through
  superior weapon skill, the bare-hands
  wrest; the weapon disarm: equal-or-
  greater size, declared at the round
  start, the normal hit with no damage,
  the save versus petrification or the
  weapon knocked loose, the 1d6-feet fall,
  the one-round recovery; the bare-hands
  systems (UA weaponless combat or the
  martial arts) with the any-size knock
  and the +2 victim save; the two-handed
  weapon rule - one hand per success, two
  same-round attempts to disarm, else the
  regrip at the end of the round.
  Single-pass pins per the Chapter 9
  provenance shift. rverify GREEN first try
  at 5e63625, 11 mutants, 0 missed. Spec
  md5 2a9d8aaef126ee8680a0e35fbfd719f0
  (authored-plus-newline md5 7e1a4c9de8e4
  53ee1a5fc8aaf16ef13d - the value the
  ritual gated and matched; canvas md5
  53b1b3908cd214d201da89042b08bfe1). NEXT
  - R686: the Subduing Opponents doctrine
  (capture p. 221), prefix diz (verify free
  at e0bebcb) - THE LAST FREE di- PREFIX;
  from R687 the dj- family opens (djf first
  free if dja through dje collide), audit
  "R686 OA subduing audit", include after
  rules/oadisarming.h
- R686 LANDED 2026-10-20: commit
  c553d0303b1888b87d210c8a446b952d6fd27233
  (census 608 -> 609, pushed e0bebcb..c553d03),
  OA SUBDUING OPPONENTENTS - the subdual
  doctrine, capture pp. 221-222 (the
  section ran past its gap-item page):
  rules/oasubdual.h, prefix diz (verified
  free at e0bebcb) - THE LAST di- PREFIX,
  ONE gap flip, 4 consts + 13 bools (17
  inlines, no table), gap census 138/97 ->
  139/96. The doctrine frame - the shukenja
  forbidden to kill, the live prisoners and
  hostages; the low-intelligence gate with
  the genius voluntary-surrender clause;
  the any-creature scope; the player-choice
  rule (a PC never forced into submission);
  the fight-start declaration with the
  blunt striking surfaces; the quarter
  split - each blow normal, 1/4 hit points,
  3/4 subdual recorded separately, a split-
  integrity example proving the shares sum
  to the whole; the surrender at the
  STARTING hit points; the normal-damage
  voiding (all subdual points gone); the
  subdued state (stop, drop weapons); the
  oath mechanics - the secret honor roll or
  the save versus death, compliance or the
  show of agreement; the captive escape
  clause. Single-pass pins per the Chapter
  9 provenance shift. rverify GREEN first
  try at e0bebcb, 17 mutants, 0 missed.
  Spec md5 c8e102abea0544a982d2c6247c944e
  3d (authored-plus-newline md5 31657627571
  c6975f66459577ff8a19c - the value the
  ritual gated and matched; canvas md5
  9e73d8193447f29bb8ff6ff65b4fd260). NEXT
  - R687: The Psychic Duel (capture pp.
  222-223), prefix dja (verify free at
  c553d03) - THE dj- FAMILY OPENS, audit
  "R687 OA psychic duel audit", include
  after rules/oasubdual.h
- R687 LANDED 2026-10-20: commit
  4c558a35c3afe3b3b8e3d79a85cb33e04ffa9e70
  (census 609 -> 610, pushed c553d03..4c558a3),
  OA THE PSYCHIC DUEL - the wills contest,
  capture pp. 222-223: rules/oapsychicduel.h,
  prefix dja (verified free at c553d03) -
  THE FIRST dj- PREFIX, the family opened
  after diz closed the di- line at R686,
  ONE gap flip, 6 consts + 16 bools (22
  inlines, no table), gap census 139/96 ->
  140/95. The mental-combat frame (any
  race or class, no psionic talent, the
  wills test); the circumstances - the
  human-or-humanoid gate, one-on-one,
  never between friends (3 honor), no
  crossed weapons, no outside attacks;
  the resolution - the 10 feet, the save
  versus death, the kensai +2 against
  non-kensai, the split-outcome win, the
  both-fail inconclusive, the both-make
  continuation, the nerve-break loser;
  the honor awards - 2 higher, 1 equal,
  none lower; the loser's options - the
  retreat losing the equal honor or the
  attack at -1 throughout with no
  surprise. Single-pass pins per the
  Chapter 9 provenance shift. Caught pre-
  rverify: the gap item cites pp. 222-223,
  not p. 222 - flip anchor aligned before
  the first verify. rverify GREEN at
  c553d03, 22 mutants, 0 missed. Spec md5
  c63b31001c731e572230f2b867c77b44
  (authored-plus-newline md5 e9967bb57da8
  438bb3f1d2aa8930eb3b - the value the
  ritual gated and matched; canvas md5
  e9936fe01d8520a2f8b66ecfe1c66087). NEXT
  - R688: the Martial Arts doctrine opener
  (capture pp. 223-224), prefix djb
  (verify free at 4c558a3), audit "R688 OA
  martial arts opener audit", include
  after rules/oapsychicduel.h
- R688 LANDED 2026-10-20: commit
  5d2af58dbe52e06aa64f38cc0fd840ced0adad90
  (census 610 -> 611, pushed 4c558a3..5d2af58),
  OA MARTIAL ARTS OPENER - the doctrine
  prose through the Styles intro, capture
  pp. 223-225: rules/oamartialopen.h,
  prefix djb (verified free at 4c558a3),
  ONE gap flip, 1 const + 18 bools (19
  inlines, no table), gap census 140/95 ->
  141/94. The doctrine frame (the body as
  weapon, unique to the OA lands); the
  training discipline; the three reason
  strands - the nature-forces philosophy,
  the religious divestment, the weapon-
  edict social pressure; the regularized
  art of self-perfection; the style
  proliferation (every land its own, two
  masters of one style in different
  forms); the school challenges with the
  spectators; the primary goal (avoid being
  hurt) with the defensive, aggressive and
  weapon-master schools; the forms
  variety; the unarmed misnomer (the
  tui-fu in the master's hands); the
  rules fit (styles defined by their
  effects); the five style characteristics;
  the poetic names and the use
  identities. Single-pass pins per the
  Chapter 9 provenance shift. Caught pre-
  rverify: the gap anchor is a TWO-LINE
  wrap (pp. then 223-225) - the exact
  lines read before writing the flip, no
  anchor RED. rverify GREEN first try at
  4c558a3, 19 mutants, 0 missed. Spec md5
  b3a970cd02b254b5bff87d48983ea227
  (authored-plus-newline md5 7653d2463844
  b9d6e4ad60ed854e5a3e - the value the
  ritual gated and matched; canvas md5
  63a21d68d60c0abfdb8b6ed77ab9872e). NEXT
  - R689: Table 68 the common martial
  styles grid (capture p. 224), prefix djc
  (verify free at 5d2af58), audit "R689 OA
  common martial styles audit", include
  after rules/oamartialopen.h
- R689 LANDED 2026-10-20: commit
  8d86b06610e73f32e992bb2f9ec0248836efdd26
  (census 611 -> 612, pushed 5d2af58..8d86b06),
  OA TABLE 68 - the common martial styles,
  capture pp. 224-225: rules/oa68styles.h,
  prefix djc (verified free at 5d2af58),
  ONE gap flip, 1 const + 5 bools (12
  inlines, 4x6 grid tag OA68Data - the
  count a CONST FUNCTION per the R683
  lesson), gap census 141/94 -> 142/93.
  The four styles pinned across six
  columns: Karate the 3/1, d6, AC 8, Hand,
  six maneuver ranks; Kung-fu the 2/1, d6,
  AC 6 the best, Hand, eight ranks; Tae
  Kwon Do the 1/1, the lone d8, AC 8, the
  only Foot principal, six ranks; Jujutsu
  the 2/1, d6, AC 7, Hand, the eleven
  ranks - the richest; the maneuver cells
  encoded as rank counts with the full
  lists riding the column comments. The
  p. 225 explanatory prose as five bools.
  Single-pass pins per the Chapter 9
  provenance shift. rverify GREEN first
  try at 5d2af58, 30 mutants, 0 missed.
  Spec md5 88774c5b48b4053e186458c390077
  6e (authored-plus-newline md5 a77f3ee511
  ac20b48d193d94b0309af4 - the value the
  ritual gated and matched; canvas md5
  caeee1910e5978472ec25e1195a8e938). NEXT
  - R690: the Creating a Style doctrine
  (capture pp. 225-228), prefix djd
  (verify free at 8d86b06), audit "R690 OA
  creating a style audit", include after
  rules/oa68styles.h
- R690 LANDED 2026-10-20: commit
  5b21b324e337b519e3a3be167260d774abe3fe27
  (census 612 -> 613, pushed 8d86b06..5b21b32),
  OA CREATING A STYLE - the style-
  construction doctrine, capture pp.
  225-227 prose (Table 69 itself the next
  gap item): rules/oacreatestyle.h,
  prefix djd (verified free at 8d86b06),
  ONE gap flip, 5 consts + 21 bools (26
  inlines, no table), gap census 142/93 ->
  143/92. The creation frame (the DM
  encouraged, the NPC masters); the three
  forms - hard (muscles and bones,
  direct, offensive), soft (the inner
  power, fluid and circular, defensive,
  the attacker's force against him),
  combined (the best of each, physical
  balanced with psychic); the unusual-
  weapons clause; the principal method
  with the other-methods rule (the single
  form the certain defeat); the one-form-
  one-method selection; the Table 69
  mechanics pinned as rules - the AC base
  10 minus the totaled mods, the style-
  specific attacks, the round-up damage
  (6-d6, 4-d4, 5-d6), the free body part;
  the 1d4-minus-two weapons of the
  martial-arts-only list; the Special
  Maneuvers intro - the combat cost
  (attacks) and the movement cost (no
  attacks), the 1d8 first roll and the
  1-3 second roll (the arsenal of
  tactics), the ranking progression with
  the printed Circle Kick 1 Flying Kick 2
  All-Around Sight 2 Backward Kick 3
  example, the gradual learning, the
  any-style Mental and Physical Training.
  Single-pass pins per the Chapter 9
  provenance shift. rverify GREEN first
  try at 8d86b06, 26 mutants, 0 missed.
  Spec md5 8518f6647f489c2fb62ac099bfdf
  d8ac (authored-plus-newline md5 b9433422
  6352a957008faf473e05e366 - the value
  the ritual gated and matched; canvas
  md5 06d9099a4b29509631e5ee24bf673182).
  NEXT - R691: Table 69 the martial style
  combinations grid (capture p. 226),
  prefix dje (verify free at 5b21b32),
  audit "R691 OA style combinations
  audit", include after rules/oacreatestyle.h
- R691 LANDED 2026-10-20: commit
  3a019a93b8145cb4fdd1760fcecb778ac
  396168b (census 613 -> 614, pushed
  5b21b32..3a019a9), OA TABLE 69 - the
  martial style combinations, capture p.
  226 print: rules/oa69combos.h, prefix
  dje (verified free at 5b21b32), ONE gap
  flip, gap census 143/92 -> 144/91. The
  11x4 grid OA69Data: three forms (Hard
  1/1/4, Soft 3/0/2, Hard/Soft 2/1/3,
  body part 0) and eight methods (Kick
  1/1/4 Foot=1, Lock 1/1/2 Body=2,
  Movement 2/1/2 Legs=3, Push 2/1/1
  Hand=4, Strike 1/1/1 Hand=4, Throw
  1/1/2 Body=2, Vital Area 2/1/1
  Hand&Foot=5, Weapon 1/1/0-by-weapon
  Hand&Arm=6 - the by-weapon damage 0
  per the R662 convention); the count
  const function djeOA69RowCount (the
  bare-int hazard of R683 avoided); six
  examples incl. the derived styles
  (Hard+Kick -> AC 8, attacks 2, damage
  8; Soft+Movement -> damage 4).
  Single-pass pins per the Chapter 9
  provenance shift. rverify GREEN first
  try at 5b21b32, 45 mutants, 0 missed.
  Spec md5 3a3457d97bda02355a3fe77582fb
  06c1 (authored-plus-newline md5
  07132a0c6b30f51679e7b7068eb9aefe -
  the value the ritual gated and
  matched; canvas md5 77ffae2df6db2453
  7fbd75934695b16c). NEXT - R692: Table
  70 the martial arts special maneuvers
  grid (capture p. 227), prefix djf
  (verified free at 3a019a9), audit
  "R692 OA special maneuvers audit",
  include after rules/oa69combos.h
- R692 LANDED 2026-10-20: commit
  1393818055009697f6597b226615c76e
  fe60ff6a (census 614 -> 615, pushed
  3a019a9..1393818), OA TABLE 70 - the
  martial arts special maneuvers, capture
  p. 227 print: rules/oa70maneuvers.h,
  prefix djf (verified free at 3a019a9),
  ONE gap flip, gap census 144/91 ->
  145/90. The 36x3 grid OA70Data across
  the nine method columns (Kick 3:
  Circle Kick, Flying Kick, Backward
  Kick; Movement 7 the deepest: Feint,
  Prone Fighting, Immovability, Missile
  Deflection, Leap, Speed, Slow
  Resistance; Strike 3 all hard: Iron
  Fist, Crushing Blow, Eagle Claw;
  Weapon 3: Weapon Catch, Weapon
  Breaker, Steel Cloth; Lock 4: Choke
  Hold, Locking Block, Incapacitator,
  Immobilizing; Throw 4: Fall, Instant
  Stand, Hurl, Great Throw; Mental and
  Physical Training 6 the any-style
  category: Meditation, All-Around
  Sight, Mental Resistance, Blind
  Fighting, Ironskin, Levitation; Push 3
  and Vital Area 3 all soft), the
  method, rank and form columns coded -
  the form tag 0 hard, 1 soft, 2
  hard/soft, crossover allowed, the
  rank progression from 1 on up (the
  printed Circle Kick 1 Flying Kick 2
  All-Around Sight 2 Backward Kick 3
  example); ten consts (the count
  function djfOA70RowCount plus the nine
  per-method counts). The jumbled OCR
  table needed the column
  reconstruction - the Movement ranks
  4-7 scattered across header rows,
  verified against the print. Single-
  pass pins per the Chapter 9
  provenance shift. rverify GREEN first
  try at 3a019a9, 118 mutants, 0
  missed. Spec md5 9587db3426a69ef442
  949eadd1056fa1 (authored-plus-newline
  md5 e80c4c5132259233eccbcd942352e953
  - the value the ritual gated and
  matched; canvas md5 d62f1e99828ab4f1
  42db89f562dcd8c1). NEXT - R693: the
  Principal Methods prose (capture pp.
  228-232), prefix djg (verified free at
  1393818), audit "R693 OA principal
  methods audit", include after
  rules/oa70maneuvers.h
- R693 LANDED 2026-10-20: commit
  269b6c083bc75dc62eea0f766e9a730c9
  da84b78 (census 615 -> 616, pushed
  1393818..269b6c0), OA PRINCIPAL
  METHODS - the eight method
  descriptions, capture pp. 228-232
  print: rules/oamethods.h, prefix djg
  (verified free at 1393818), ONE gap
  flip, gap census 145/90 -> 146/89. 42
  consts + 46 bools (88 inlines, no
  table): kick (Circle Kick double
  damage and the lost next attack,
  Flying Kick triple of the five-foot
  run, Backward Kick miss harmless),
  lock (Choke Hold the -2 escapes and
  the 1-3 round unconsciousness,
  Locking Block feet-only +4 with the
  weapon damage on a miss,
  Incapacitator the double damage and
  the 24-hour limb, Immobilizing the
  -6 escape and the -4 miss),
  movement (Feint +2, the constant
  Prone Fighting, Immovability
  auto-save, Missile Deflection save
  per attack awareness required, Leap
  standing 4/3 running 8/10 plus a
  foot per level, Speed double
  attacks and combat movement only
  once per day five rounds then rest,
  Slow Resistance automatic), push
  (Concentrated Push a foot per level
  with the three-foot save threshold,
  Sticking Touch +2 and AC 2 better,
  One Finger the round's only action),
  strike (Iron Fist 1d10, Crushing
  Blow half-foot wood and quarter-foot
  stone per level, Eagle Claw 3d10 -
  the OCR artifact 3410 resolved,
  corroborated against a 1e OA
  transcription), throw (the constant
  Fall half damage, Instant Stand,
  Hurl 1d4 feet double damage, Great
  Throw six plus a foot per level on a
  charge, triple damage), vital area
  (human and humanoid only - Pain
  Touch -2/+2 for 1-3 rounds, Stun
  1d4 rounds, Paralyze 1d6 turns,
  Distance Death Pain unsavable and
  Stunning at -2 or triple damage),
  weapon (the martial-arts-exclusive
  weapons only - Weapon Catch lock
  and +2 with the disarm on a miss,
  Weapon Breaker melee-only with the
  save vs. crushing blow, Steel Cloth
  six to ten feet spear-like,
  automatic). The stray Distance
  Death line of p. 228 (column bleed)
  folded into the vital area prose,
  not double-pinned. Single-pass pins
  per the Chapter 9 provenance shift.
  rverify GREEN first try at 1393818,
  88 mutants, 0 missed. Spec md5 c0ed
  3a5a6c8659001449c3c2cdd5282e
  (authored-plus-newline md5 bc7c5bc5
  1207a3748444eff4938d3369 - the value
  the ritual gated and matched; canvas
  md5 2abbc206652d119cda23d04dcb5c54e3).
  NEXT - R694: the Mental and Physical
  Training with Stunning and
  Incapacitating prose (capture pp.
  232-233), prefix djh (verified free
  at 269b6c0), audit "R694 OA mental
  and physical training audit",
  include after rules/oamethods.h
- R694 LANDED 2026-10-20: commit
  e9a5608056da7e6942124195ef1fc903c
  063d053 (census 616 -> 617, pushed
  269b6c0..e9a5608), OA MENTAL AND
  PHYSICAL TRAINING - the any-style
  training maneuvers with the stunning
  and incapacitating rules, capture pp.
  232-233 print: rules/oatrain.h,
  prefix djh (verified free at 269b6c0),
  ONE gap flip, gap census 146/89 ->
  147/88. 11 consts + 17 bools (28
  inlines, no table): the training
  category (no principal method, any
  practitioner - Meditation the
  shukenja powers with the shukenja and
  kensai spending no slot; All-Around
  Sight constant, the invisible unseen,
  no strike from behind nor back-attack
  penalty; Mental Resistance the +2
  against charm, illusion and hold;
  Blind Fighting the -1 in darkness,
  blindness or vs the invisible, the
  silence spell with any blinding
  again; Ironskin AC 2 better only
  unarmored; Levitation the rarest -
  one turn of concentration, five feet
  per round, no actions, the broken
  concentration a fall, one round of
  rest); the Stunning and
  Incapacitating - every style's chance
  vs a man-sized opponent, the
  UNMODIFIED 20 forcing the save vs.
  paralyzation, the save made keeping
  the normal damage, the save failed
  comparing the roll to the hit dice or
  level - less the 1d6 round stun,
  greater the 1-3 hour incapacity,
  equal the stun per the printed
  lizard man example (the 2 equal to
  the 2+1 dice), the +4 or greater hit
  dice bonus one extra die - the OCR
  artifact t-3 resolved as 1-3 per the
  example. Single-pass pins per the
  Chapter 9 provenance shift. rverify
  GREEN first try at 269b6c0, 28
  mutants, 0 missed. Spec md5 206cd30a
  b57a12d134b0d1d0ebbf779a
  (authored-plus-newline md5 d788df50
  d157d3f16fdff2416c4542cd - the value
  the ritual gated and matched; canvas
  md5 c3ae2f790976ea835f00e01c09a93105).
  NEXT - R695: the Learning Martial
  Arts with Multiple Styles and
  Combining Styles prose (capture pp.
  233-235), prefix dji (verified free
  at e9a5608 - only djinn prose in
  old headers, no identifiers), audit
  "R695 OA learning martial arts
  audit", include after rules/oatrain.h
- R695 LANDED 2026-10-20: commit
  61d0647bb81a15e75f68845a7a8b724a
  12daaa9d (census 617 -> 618, pushed
  e9a5608..61d0647), OA LEARNING
  MARTIAL ARTS - the master search and
  acceptance, the study obligations
  and slot costs, with the multiple
  styles and the combining of styles,
  capture pp. 233-235 print:
  rules/oalearn.h, prefix dji
  (verified free at e9a5608 - only
  djinn prose in old headers, no
  identifiers), ONE gap flip, gap
  census 147/88 -> 148/87. 8 consts +
  24 bools (32 inlines, no table):
  the master title honorary not a
  class (brilliant, skilled, mediocre
  and incompetent all called master),
  anyone anywhere (the peasant, the
  hermit, the bushi, the teacher, the
  samurai, the priest), the scarcity
  and the secret societies; the 10%
  acceptance at the humble
  presentation, +10% per gift-bearing
  visit until accepted or the master
  offended - the offense permanent;
  the automatically accepted
  challenge, the unknown challenger
  given a student, the subdue
  preferred over the death, the death
  no crime, the victor accepted, the
  loser begging or returning; the
  master's knowledge - the basics
  automatic, the weapons and the
  maneuvers each rolled on the nearest
  die at or above their count, the
  lowest difficulty upward, the master
  fixed; the study - one month then
  one slot for the basics (AC,
  attacks, damage, no maneuvers yet),
  the one hour daily and six master
  hours weekly, the obligation the
  gate; one slot per maneuver or
  weapon, two per style per level the
  cap, the strict difficulty order;
  the outgrown master left; the
  multiple styles - one master each,
  one style fought at a time, the
  constant maneuvers the exception,
  the round-to-round change; the
  combining after all learned - the
  unique style of mixed elements, the
  AC of one with the attacks and
  damage of another, every maneuver
  combined, the creator teaching as a
  master. Chapter 9 closes with this
  round. Single-pass pins per the
  Chapter 9 provenance shift. rverify
  GREEN first try at e9a5608, 32
  mutants, 0 missed. Spec md5 34ee00
  727dbb9514a299c8fadefab15e
  (authored-plus-newline md5 1f849eae
  a64c2565644427a08e56c67c - the value
  the ritual gated and matched; canvas
  md5 110e5a0238fad8a471bbf3646bd70f01).
  NEXT - R696: the Chapter 10 Calendar
  prose (capture p. 236), prefix djj
  (verified free at 61d0647), audit
  "R696 OA calendar audit", include
  after rules/oalearn.h
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
