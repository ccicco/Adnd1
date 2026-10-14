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
## Knowledge maintenance

- Each land appends ONE entry to Round state above (date,
  commit, census, what landed, the lessons) - terse; the repo
  carries the code and the gap reports.
- When this file balloons past ~100KB, run the fresh start
  again (v3): backup + seed + continuation prompt saved to
  doc/vibe/ with a v3 suffix and committed BEFORE wiping
  knowledge and chats - the v2 process is the template.
