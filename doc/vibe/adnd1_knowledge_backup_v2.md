---
name: adnd1-delivery
description: How Adnd1 splice rounds reach Termux - the delivery format, the run ritual with md5 gates, and the hard-won lessons (R34-R311 era, dmg gap report closed; the underwater seam era is open)
---

# Adnd1 delivery protocol (current practice, R171b/R172 era)

Supersedes the old chunked-heredoc format (cat >> chunks, CHUNK-N
markers, PYTHONDONTWRITEBYTECODE, wc -l ladder). That was the original
format; it is DEAD. Current practice:

## Delivery format

- The splice is delivered as a code canvas (e.g. the r172-splice
  canvas). The user opens it, selects all, copies, and pastes ONCE
  into nano: `nano tools/rNNN_splice.py`.
- The assistant delivers the run ritual as ONE code block, with the
  expected values as inline # comments (the R171b/R172 style).
  ORDER MATTERS (R173 correction): in the final reply, the ritual
  must appear AFTER the splice code block / canvas is presented -
  never before it.

  (the paste itself happens on the Termux side in nano before the
  ritual; R175 lesson enforced: never write the paste step as a
  ritual command, and keep all paths repo-root relative ./tools/...)

  md5sum ./tools/rNNN_splice.py      # expect <md5> (ADVISORY - see note)
  python3 -m py_compile ./tools/rNNN_splice.py && echo COMPILE-OK
  python3 ./tools/rNNN_splice.py     # expect: ALL OK (applied N, already 0) + note
  python3 ./tools/rNNN_splice.py     # expect: ALL OK (applied 0, already N)
  md5sum rules/<created file>        # expect <md5> - THE REAL GATE (if a file is created)
  ./tools/preflight.sh               # expect: GREEN + new audit bad 0 + AUDIT CENSUS: N
  git add -A && git commit -m "RNNN: ..." && git push

- md5 note (R172 finding): the PASTED splice md5 drifts (both R172
  attempts mismatched, likely CRLF/newline artifacts from nano paste)
  yet the land is unaffected - the splice writes all created content
  programmatically with chr(10), so created files are byte-exact.
  The splice md5 is advisory only; the REAL gates are: py_compile,
  "applied N, already 0" counts, the created-file md5, and preflight.

## Recovery ritual (re-running a FIXED splice after a bad land)

- FIRST rm the created file (e.g. `rm rules/herbs.h`): the idempotence
  marker makes a broken file report "already" and stay broken (the
  R172 lesson). Then expect "applied 1, already N-1" on rerun.

## Acid-test checklist (assistant side, before delivering any splice)

- Fresh tarball md5 must match HEAD before work.
- Idempotent (marker-based); assert after EVERY patch; tail ALWAYS
  prints; ZERO backslash chars; no literal apostrophe inside
  single-quoted content strings (build with chr(39) as Q).
- Apply twice on a fresh tree (applied N/already 0, then 0/N);
  fresh-clone reproducibility: virgin tarball + splice = identical.
- Every static audit array: declared size == initializer count AND
  every initializer line comma-terminated (R171b count lesson + R172
  separator lesson - a bool array without commas passed the static
  count and segfaulted preflight).
- Simulate the audit walk in Python against ground truth (bad 0).
- R207c (THE gate that replaced sim-from-intent): run
  `python3 tools/audit_eval.py RNNN` and demand "verified bad
  0" - not UNVERIFIED - before delivery. The tool parses the
  ACTUAL generated rules/*.h bodies and the ACTUAL audit block
  and executes every assertion literally; it never re-implements
  a rule from intent, and anything unparseable fails (YELLOW =
  RED). New seams are written in the grenade.h evaluable subset
  (pure inline helpers: constants, ternaries, clamp chains,
  tables, ref out-params; no structs/classes/engine objects).
  Proven in the sandbox: replanting the R207b inverted ternary
  reports bad 1, replanting the R206b missing bang + dropped
  +10 reports bad 2 - the exact failures the old sim blessed.
- Brace/paren delta 0/0 vs pristine on every touched .cpp/.h.
- Census line exactly once; Census N+1 note; all gap-report markers
  exactly once; diff vs pristine shows only expected files.

## Round state (update each land)

- R172 landed 2026-10-04: commit bd4382f, census 90, Appendix J pinned
  (rules/herbs.h, 171 rows: the compilation's dropped turnip row and
  truncated celery uses restored from print).
- R173 landed 2026-10-04: commit 3e55136, census 91, secondary skills
  pinned (rules/secondary.h, 23 bands per DMG p.12; paste md5 drifted
  as expected, created-file md5 matched exactly).
- R174 landed 2026-10-05: commit 9eb9368, census 92, the R146 fiction
  leftovers pinned (noble gender coin 75/25, noblewoman 75% sedan-chair
  detail, ruffian 1-in-4 half-orc/humanoid note - cityNobleKind /
  cityNoblewomanSedan / cityRuffianKind in dm/encounters.cpp, wired in
  game/state_sea.cpp, R174 battery audit; no new rules file, splice md5
  advisory, paste md5 drifted as expected). R146 fiction box is CLOSED.
  Also: the round was built against the GitHub repo directly (public
  raw URLs readable via web open; tarball codeload download works) -
  the Termux tarball ritual is not the only way to read the land.
- R175 landed 2026-10-05: commit 9eb6d8a, census 93, the R171 Appendix
  L 5-and-up OCR debt CLOSED. The 1eonline.info compilation is ALIVE
  (was believed dark): https://1eonline.info/2ph/conjureanimals.htm
  carries the full 5-and-up section the book upload drops. The R171
  20-name roster (klmConjHigherRosterCount/Name) was INCOMPLETE
  (buffalo, skunk giant, lion, bear cave, boar giant missing) and was
  replaced by rules/klm.h struct ConjHigherRow{cat,lo,hi,name,cost} +
  klmConjHigherCount()==26 + klmConjHigherRow(i): categories 5-14, 26
  rows; bandless cats 9/11/13/14 pinned lo/hi 0; compilation spelling
  "woolly" corrects the pinned "wooly". Only regtest.cpp used the old
  accessors (verified repo-wide). New R175 audit walks bands
  (first lo 1, contiguous, last hi 100), bandless zeros, clamps, and
  re-pins whale cap 36 + water-swimmers note. Lessons reinforced: the
  p4_old printf %d string was built with a stray no-op .replace() -
  this exact bug class (dropped/mangled %d in old-side anchors) bit
  R174 first attempt, so old-side anchor lines get built PLAIN.
- R176 landed 2026-10-05: commit ac7a292, census 94, the R162 XP-row
  divergence CLOSED - the gap report now has ZERO open items. The PHB
  upload DOES carry the four printed XP boundary columns (the R162
  round had read the title columns only). rules/classes.cpp: all four
  xpForLevel rows repinned to the print, convention = printed band
  lower bound - 1 (fighter L5: 18,001-35,000 gives 18000, the old row
  read 16000); fighter ...250000, 500000, 750000, then 250k past the
  11th; MU ...135000, 250000, 375000, 750000, 1125000, then 375k past
  the 12th; cleric ...225000, 450000, 675000, then 225k past the 11th;
  thief ...160000, 220000, 440000, 660000, then 220k past the 12th.
  The engine linear-beyond convention kept, anchored on the printed
  adders (probes at L14/L15 in the audit). Ritual lesson: the paste
  (nano) step is NOT a ritual command - it bit twice before sticking
  (R175 twice, R176 once); the ritual starts at the md5 gate.
- R177 landed 2026-10-05: commit f681b1e, census 94
  (report round - no audit added), the PHB gap report
  CREATED (tools/phb_gap_report.md; created-file md5
  matched the advisory exactly). The PHB arc is now
  open: founding read verified FIVE ability-table
  divergences (rules/character.cpp ladders from
  project notes - the R162 XP finding class): DEX
  reaction cells 3/4/18; CON system shock AND
  resurrection survival (every score); WIS ladder
  (engine -2..+2 vs print -3..+4); INT languages;
  CHA percent scale (-4..+4 flat vs printed
  -25..+35, feeds dm.cpp d100 reaction bands - the
  fix must re-scale) + henchmen cells cha 4 and 12.
  LIVE divergences first: DEX (missiles, surprise)
  and CON resurrection (raise-dead). Open items:
  prime-requisite rungs, weapon-table book-verify
  (now payable), starting money, armor AC, fighter
  attacks/round, Wisdom Table II wiring. Next round
  queue: R178 = DEX + CON repin (both live).
- R178 landed 2026-10-05: commit 0b0efe4, census 94
  (scope round - no audit), the SUBCLASS ARC OPENED per
  user scope decision: all six subclasses (paladin,
  ranger, druid, illusionist, assassin, monk),
  multi-class AND dual-class, and the FULL spell lists
  (druid/illusionist lists join the registry). Arc
  plan in tools/phb_gap_report.md (subclass arc
  section): R179 foundations (registry, caps, XP,
  titles) / R180 qualification+race gates / R181
  attacks-per-round / R182-184 spell layers (druid,
  illusionist, paladin+ranger) / R185 multi+dual
  class / R186+ per-subclass specials. ORDERING RULE
  the arc section pins: the live DEX+CON ability-table
  fixes come BEFORE R179 (build on correct ladders);
  so the next engine round is the DEX+CON repin
  (numbered within the arc sequence when delivered).
- R178b landed 2026-10-05: commit 9ed56b0, census 94
  (scope amendment - no audit), THE BARD JOINS THE ARC
  as R186 (the user caught the PHB Appendix II gap).
  The 1e bard: NOT a starting class - fighter to
  5th-7th, thief to 5th-9th, then druidical study as
  a bard; human or half-elf, always neutral, hit
  dice ADDED to those already earned; Bards Tables
  I (23 levels, bard-XP-only, druid spell slots
  capped at 12th-level druid ability until 23rd),
  II (colleges, charm + legend lore percents), III
  (armor/weapons); poetics morale + ferocity, song
  negation, musical charming, item knowledge,
  most-favorable-table saves. Slots AFTER R185
  (builds on fighter, thief, druid spell layer and
  dual-class machinery); per-subclass specials
  renumbered R187+. Arc queue now: DEX+CON repin
  first, then R179 foundations, R180 gates, R181
  attacks/round, R182-184 spell layers, R185
  multi/dual-class, R186 bard, R187+ specials.
- STANDING SCOPE (user, 2026-10-05): more classes
  will come later from Dragon Magazine, other 1e
  sourcebooks (Unearthed Arcana cavalier, barbarian,
  thief-acrobat), campaigns, and box sets. R179
  foundations must build the class registry
  DATA-DRIVEN and open-ended (append a row, not
  re-carve): new classes land as registry rows +
  spell-list mappings in future rounds. When the
  PHB arc closes, the gap-report pattern extends:
  a sourcebook gets its own gap report against the
  same engine conventions.
- R178c landed 2026-10-05: commit 592e215, census 95,
  the PHB divergences 1 and 2 CLOSED (the live bugs
  first, per the arc ordering rule). rules/character.cpp:
  DEX reaction ladder repinned (3 -3, 4 -2, 18 +3;
  missile attacks + surprise now read the print);
  CON system shock repinned 35-99, resurrection
  survival 40-100 (the raise-dead roll); CON 6 HP
  cell repinned -1; the unsourced conPoisonSaveAdj
  RETIRED (not in the 1e print, zero callers). ACID
  TEST LESSON: patch 3 idempotence marker was a
  SUBSTRING OF THE ORIGINAL array text (the old
  resurrection row contains 35,40,45...), causing
  marker collision - "applied 8, already 1" on a
  FRESH tree. Rule: markers must be verified absent
  from the PRE-patch file, not just present in the
  patch; prefer a marker unique to the NEW text
  (e.g. the new final array line). Remaining PHB
  divergences: 3 (WIS), 4 (INT), 5 (CHA - needs the
  d100 re-scale in dm.cpp rollReaction). Then R179
  foundations (data-driven registry per the standing
  scope).
- R179 + R179b landed 2026-10-05: commit 43d917b
  (one commit - R179 preflight RED, fixed by R179b
  before any push), census 96. rules/subclasses.h
  CREATED - the data-driven registry: SubclassDef
  {base, group, levelCap, hpBeyondCap, hitDie,
  twoDiceFirstLevel, xpRows, xpAdder, titles, prime}
  with the six PHB subclasses pinned from the printed
  tables (R176 attain convention): paladin (fighter,
  cap 9/+3, d10, 11 rows, 350k adder past 11th),
  ranger (fighter, 10/+2, d8, 12 rows, 325k, TWO
  dice at level 1, primes STR+INT+WIS), druid (cleric,
  9/+2, d8, 14 rows, ceiling, WIS+CHA), illusionist
  (MU, 10/+1, d4, 12 rows, 220k), assassin (thief,
  10/+2, d6, 15 rows, ceiling), monk (NO base, 17
  levels roll through, d4, two dice at level 1,
  STR+WIS+DEX). Full title ladders (11/12/14/12/15/
  17). accessors subclassCount/subclassDef/
  subclassXpFor/subclassTitle (clamped).
- R179 LESSON (the land caught it): the splice
  created subclasses.h and added a regtest audit
  referencing rules::subclassCount() WITHOUT the
  include - preflight RED, 20 errors, census failed
  downstream of the missing binary. R179b added
  #include "rules/subclasses.h". LESSON RECORDED IN
  THE GAP REPORT: the acid test must SYNTAX-CHECK
  touched TUs (clang++ -fsyntax-only) whenever a
  round adds code regtest includes - a header
  verified in isolation is not a build. Note: the
  sandbox has no C++ compiler; the compile proof
  is the Termux preflight itself. Also: the splice
  working copy in /home/user/Adnd1 can be WIPED by
  turn-start re-downloads - canvases are the
  durable copies; recover from the canvas body
  (tail -n +7 CANVAS.md).
- R180 + R180b landed 2026-10-05: commit 9ab690e
  (one commit - R180 preflight RED with ONE compile
  error, fixed by R180b before push), census 97.
  rules/subclassgates.h CREATED - the qualification
  and race gates: the class-section ability minimums
  (6x6 in Ability enum order; 0 = none), the Table I
  alignment letters (enum SubAlignReq: any/LG-only/
  good-only/true-neutral/evil-only/lawful-only), the
  XP bonus rules (enum SubXpBonusRule: paladin
  STR+WIS>15, ranger STR+INT+WIS, druid WIS+CHA;
  illusionist/assassin/monk NONE - the assassin
  class text is explicit: no bonuses), Race Table I
  (6x7 allowed matrix, CharRace column order human
  first) and Race Table II (6x7 caps: 0 forbidden,
  -1 unlimited, positive = player cap, negative
  n>=2 = NPC-only cap n - the halfling druid (6)),
  plus illusionistGnomeCap(int,dex) for footnote 8
  (either score under 17 -> 5, both 17+ -> 6; the
  printed base 7 never survives the footnote -
  pinned as JUDGMENT, matrix keeps the printed 7).
  Accessors subclassAbilityMin, meetsAbilityMin,
  raceAllowed, raceCap, capIsNpcOnly, alignReq,
  bonusRule, bonusEarned (all clamped).
- R180b LESSON (second bite of R179): the audit
  probed rules::RACE_HALFELF but rules/races.h
  spells it RACE_HALF_ELF - preflight RED with ONE
  error, the census failures all downstream of the
  missing binary (a wall of ~95 CENSUS FAILs with
  ONE compile error above means: fix the compile,
  not the census). ROOT CAUSE: the enum spelling was
  inferred from a comment instead of reading the
  header. RULE: copy every engine identifier
  character-for-character from the actual header
  (grep the enum), never from comments or memory;
  and the paste/nano step was again wrongly put in
  a delivered ritual (third bite) - it is NEVER a
  ritual command. Next round: R181 attacks per
  melee round (fighter-group table, monk unarmed
  ladder, under-one-hit-die note).
- R181 landed 2026-10-05: commit 903d1e3, census
  98, GREEN on the FIRST preflight (no b-round
  needed). rules/attacksround.h CREATED - attacks
  per melee round: struct AtkRate{attacks,rounds};
  fighterGroupAttacks(kind,level) - kind 0
  fighter / 1 paladin / 2 ranger, band edges
  fighter+paladin 7 and 13, ranger 8 and 15,
  rates 1/1, 3/2, 2/1 (any thrusting or striking
  weapon); fighterAttacksVsSubOneHitDice(level)
  - the table note: one attack per fighter level
  vs creatures under one d8 and non-exceptional
  0-level humans/semi-humans; the monk unarmed
  ladder kMonkLadder[17] (Monks Table II cell by
  cell: AC class 10..-3, move 15..32, attacks
  slash 1/1,1/1,1/1,5/4,5/4,3/2,3/2,3/2,2/1,2/1,
  5/2,5/2,5/2,3/1,3/1,4/1,4/1, damage 1-3..8-32)
  with monkLadderRow clamped;
  monkWeaponDamageBonus2x(level) - the half-hp-
  per-level weapon bonus, doubled form. Monk
  combat notes recorded for R187+ specials:
  attacks on the thief table, to-hit never
  strength-modified, no DEX AC adjustment.
  rules/turn.cpp meleeAttacksPerRound REPINNED -
  was the unsourced level-8+ original note, now
  the HEAVY round of the printed cycle via
  fighterGroupAttacks(0,level): attacks>=2 -> 2
  else 1 (so 7th level opens the second routine,
  the print). This CLOSED the PHB open item
  (fighter attacks per melee round).
- R181 ACID LESSON (caught pre-delivery, the
  simulation earned its keep): the first
  delegation returned 1 in the 3/2 band (the
  rounds==1 guard) and the simulated audit walk
  flagged it - simulate EVERY accessor the audit
  probes, including patched engine functions,
  not just the new tables. Also two
  marker-spans-newline bugs fixed pre-delivery
  (the R178c rule again: a marker must be a
  single line of the NEW text). Next: R182 the
  druid spell layer.
- R182 landed 2026-10-05: commit be76481, census
  99, GREEN on the first preflight. The druid
  spell layer: rules/druidspells.h CREATED -
  druidSpellSlots(druidLevel, spellLevel): the
  full SPELLS USABLE BY CLASS AND LEVEL - DRUIDS
  table, 14x7 cells (level 1: 2/1st only; the
  14th: 6/6/6/6/5/4/3; dashes pin as 0; past-14th
  clamps to the 14th row - the hierarchy top);
  the 77-spell roster kDruidSpells[77] with
  struct DruidSpell{level, name, reversible}:
  per-level counts 12/12/12/12/8/12/9, 16
  reversible, printed alphabetical order within
  each level, Animal Friendship (0) through
  Transmute Metal To Wood (76); druidSpellTotal /
  druidSpell / druidSpellCountByLevel. Names with
  apostrophes built with Q = chr(39) (Control
  Temperature, 10' Radius). The illusionist
  layer (R183) lands the same shape.
- R182 EXTRACTION LESSON: the PHB upload OCR
  level headers (## DRUID SPELLS (nTH LEVEL))
  are UNRELIABLE - duplicated and misplaced (a
  naive pass mis-filed whole level rosters). The
  prose headers (## First Level Spells:, etc.)
  are the true boundaries; the spell names
  follow with the school tag in parens. Also
  three roster spot-check indices were wrong
  pre-delivery (Tree 34 not 35, Chariot 71 not
  72, the reversible probe 69 not 64) - the
  splice-side pre-asserts caught them; ALWAYS
  pre-assert every roster index the audit
  probes, and simulate clamp probes against the
  clamped table (druidSpellSlots(14,8) clamps
  to spell level 7 -> 3). Next: R183 the
  illusionist spell layer.
- R183 landed 2026-10-05: commit 60fd034, census
  100, GREEN on the first preflight, and the
  FIRST round with zero pre-delivery bugs - the
  R182 lessons were built into the splice itself
  (roster indices pre-asserted, clamp probes
  simulated against the clamped table before
  patching). The illusionist spell layer:
  rules/illusionspells.h CREATED -
  illusionistSpellSlots(level, spellLevel): the
  SPELLS USABLE BY CLASS AND LEVEL - ILLUSIONISTS
  table, 26x7 cells (level 1: one 1st-level slot;
  the 26th: 7/7/7/7/6/6/6; dashes 0; past-26th
  clamps to the 26th row); the 61-spell roster
  kIllusionistSpells[61] in the printed BOOK
  order (not alphabetical): per-level counts
  8/16/11/5/12/4/5, Audible Glamer (0) through
  Vision (60). JUDGMENT: the illusionist section
  prints NO Reversible markers (Continual
  Darkness and Continual Light are separate
  listed spells) - the roster carries no
  reversible flag, unlike the druid layer.
  REUSABLE PATTERN now proven twice: roster
  header = struct + count + accessor +
  countByLevel; the bard druidical layer (R186)
  and future UA spell lists land the same shape.
  Next: R184 the paladin and ranger spell layers
  (progressions + shared-list wiring; lay on
  hands, curing, ranger giant-kind bonuses).
- R184 + R184b landed 2026-10-05: commit b882388
  (one commit - R184 preflight RED, R184b fixed
  the audit before the push), census 101. The
  paladin and ranger spell layers:
  rules/palrangerspells.h CREATED -
  paladinSpellSlots(level, spellLevel): the
  PALADINS table, 12 rows x 4 clerical levels
  (opens at 9th with one 1st; the 20th reads
  3/3/3/3 max ability; below 9th zero; past 20th
  clamps); rangerSpellSlots(level, kind, sl):
  the RANGERS table, 10 rows x 5 columns
  (druidic 1-3 kind 0, MU 1-2 kind 1; druidic
  opens 8th, MU 9th; the 17th reads 2/2/2/2/2;
  below 8th zero; past 17th clamps). Wiring:
  paladin casts the cleric list (never clerical
  scrolls); ranger casts the R182 druid roster
  levels 1-3 and the MU list 1-2, learn-checked
  as if a magic-user, no scrolls. Specials:
  paladinLayOnHandsHp = 2 x level once per day;
  paladinCureDiseasePerWeek = (level+4)/5;
  the giant-class roster (11 names: bugbear,
  ettin, giant, gnoll, goblin, hobgoblin,
  kobold, ogre, ogre mage, orc, troll) with an
  EXACT-MATCH predicate (std::string equality,
  so ogre does not false-match ogre mage) and
  rangerGiantClassBonus = +1 hp per level.
  Ranger surprise numbers and the paladin
  turn-undead ladder (cleric of level-2 from
  3rd) recorded for R187+.
- R184b LESSON (preflight caught it): the audit
  probed rangerIsGiantClass("ogre") expecting
  FALSE - but "ogre" IS one of the 11 printed
  giant-class creatures; the predicate was
  right, the probe was wrong (renamed to
  "lizard man"). RULE: every NEGATIVE probe
  name must be verified ABSENT from the list it
  probes - the mirror of the positive-probe
  pre-assert rule. The user caught that my
  delivered ritual had AGAIN swallowed the
  paste/nano line into the first md5sum line
  (terminal paste collision, not my formatting
  per se - but the lesson stands: the ritual
  block must start on a fresh line after the
  paste). Also recurring: the
  marker-spans-newline bug in gap-report
  patches (bit R181, R184 - ALWAYS choose a
  single-line marker of the NEW text).
  Next: R185 multi-class and dual-class.
- R185 landed 2026-10-05: commit c0e1463
  (first-try GREEN, no b-round), census 102.
  The multi-class and dual-class rules:
  rules/multiclass.h CREATED - the class-bit
  alphabet (MC_FIGHTER 1, MC_MAGIC_USER 2,
  MC_CLERIC 4, MC_THIEF 8, MC_ILLUSIONIST 16,
  MC_RANGER 32, MC_ASSASSIN 64; paladin, druid,
  monk never multi-class) and the per-race
  combination table in CharRace order (human
  0; dwarf 1: fighter/thief; elf 4: F/MU, F/T,
  MU/T, F/MU/T; gnome 3: F/I, F/T, I/T;
  half-elf 8: C/F, C/R, C/MU, F/MU, F/T, MU/T,
  C/F/MU, F/MU/T; halfling 1: F/T; half-orc 5:
  C/F, C/T, C/A, F/T, F/A - 22 combos total):
  multiClassComboCount(race), multiClassCombo(
  race, i) (index clamps to the list),
  multiClassAllowed(race, mask), multiClass-
  Possible(race). Machinery: multiclassHp-
  Quotient(total, n) = (2*total+n)/(2*n) (drop
  under 1/2, round 1/2 up - pre-asserted
  ladder), multiclassXpShare = total/n (even
  XP split), multiclassHitDieStalled(level,
  cap) = level >= cap. Allowances: thief
  functions bound to thief armor/weaponry
  when the THIEF bit is set; cleric may use
  edged weapons when the CLERIC bit is set;
  halfelfClericWisMin() = 13. Dual-class
  (human only): dualClassRaceAllowed (race 0
  only), dualClassPrimeGate(oldPrime >= 15 &&
  newPrime >= 17) with the DUAL_CLASS_*_MIN
  constants exposed; the retained hit dice,
  1st-level functions, negated-XP-on-old-use
  and level-exceeds mechanics pinned as header
  COMMENTS only (engine rounds consume them).
  Audit: 22 positive combo probes, 8 negative
  probes (human none, dwarf no F/MU, elf no
  C/F, gnome no F/R, halfling no F/MU,
  half-orc no F/I, mask 0 and mask 1 rejected),
  clamp probes vs the clamped table (index 8
  and 99 read the last half-elf combo, human
  index reads 0), quotient/XP/stalled
  ladders, the allowances, the WIS 13 and the
  dual-class gates. LESSON: C++ precedence -
  a bitmask composed with | must be
  PARENTHESIZED in a != comparison (!= binds
  tighter than |; caught pre-delivery, not by
  the compile gate). The advisory md5 changed
  (2f7571021e...) because the user nano-pasted
  the splice, but the REAL GATE held:
  rules/multiclass.h = 677a615be03124be1d474-
  9fd1280b0a7. Next: R186 the bard (Appendix
  II) - progression gates, ability minimums,
  human or half-elf, always neutral, Bards
  Table I (23 levels).
- R186 landed 2026-10-05: commit d88c499
  (first-try GREEN, no b-round), census 103.
  The bard, PHB Appendix II: rules/bard.h
  CREATED - the gates (bardFighterWindow:
  fighter 5-7, change before 8th;
  bardThiefWindow: thief 5-9; bardAbilityGate:
  STR WIS DEX CHA 15+, INT 12, CON 10;
  bardRaceAllowed: human or half-elf;
  always neutral), Bards Table I (23 rows:
  bardXpForLevel 0 through 3,000,001, the
  titles Rhymer through M. Bard 23rd,
  bardHitDice 0* then 1-10 then 10+1 through
  10+12 added to the retained fighter/thief
  dice, bardDruidSlots 1-5 every cell,
  bardDruidCastLevel capped at 12th druid
  ability until the 23rd casts at 13th),
  Bards Table II (the colleges Probationer
  through Magna Alumnae, the language gains -
  sum 15 new tongues, bardLanguages;
  bardCharmPercent 15-95; bardLegendLore-
  Percent 0-99), Bards Table III (nine
  weapons club dagger dart javelin sling
  scimitar spear staff sword via
  bardWeaponAllowed lowercase-match; leather
  or magical chainmail, no shield, oil yes,
  poison never except by neutral evil bards),
  the poetics layers (BARD_POETIC_ROUNDS 2,
  1 turn, morale +10%, hit +1), the henchmen
  ladder (bardHenchmen: 1 at 5th, 2 at 8th,
  3 at 11th, 4 at 14th, 5 at 17th, 6 at 20th,
  999 = any number at 23rd) and the musical
  item bonuses (Drums of Panic save -1, Horn
  of Blasting 150%, Lyre of Building x2,
  Pipes of the Sewer rats x2 in half time).
  JUDGMENT: Table I row 20 lower bound pins
  as 1,800,001 - the upload OCR reads
  1,000,001 which would fall below the 19th
  row; the strictly increasing sequence
  1.4/1.6/1.8/2.0 million wins. LESSONS:
  (1) the Q-vs-DQ bug - generating C++
  string literals with Q (apostrophes)
  instead of DQ (chr(34)) produced
  'Rhymer' not "Rhymer"; the header
  apostrophe check caught it pre-delivery
  (add DQ = chr(34) next to Q and use DQ
  for every C++ string literal). (2) the
  box-anchor pre-assert must be
  CONDITIONAL on the marker being absent -
  an unconditional assert t.count(box_old)
  == 1 breaks the second idempotent run
  (the R181 already-pattern generalized:
  every pre-assert in an idempotent splice
  must tolerate the already-patched state).
  Real gate held: rules/bard.h = dca75378-
  57886a16e123bb0982e992e8347. Next: the
  phb_gap_report names the next round after
  R186 - check the box list below the R186
  entry for the standing order.
- R187 landed 2026-10-05: commit 1a40004
  (first-try GREEN), census 104. The
  per-subclass specials: rules/subclass-
  specials.h CREATED - the MINIMUM FEES FOR
  ASSASSINATION table (15 x 8 victim bands,
  dashes as 0; assassinVictimBand: 0, 1-2,
  3-4, 5-6, 7-9, 10-12, 13-15, 16+), the
  disguise spotting layer (base 2% per day,
  +2% per pose difference - class, race,
  opposite sex - max 8%; observer INT+WIS
  adjustment -1% per point below 24, +1%
  per point above 30, result may go
  negative), backstab (multiplier 1 +
  (level+3)/4 clamped 1-16 = double through
  quintuple; hit +20%/+4), the thief-skill
  sharing (assassin at level-2 except
  backstab at full level; monk at identical
  level, the six abilities - open locks is
  the OCR-swallowed list head), the monk
  surprise ladder (33 at 1st, 32 at 2nd,
  then 36-2xlevel floored at 0), the monk
  specials A-K (one per level 3rd-13th:
  speak with animals 3rd, ESP masking 30% at
  4th -2%/level, disease+haste/slow
  immunity 5th, catalepsy 2xlevel turns
  from 6th, healing d4+1 at 7th +1/level
  once per day, speak with plants 8th,
  charm resistance 50% at 9th +5%/level,
  mind blast as 18 INT at 10th, poison
  immunity 11th, geas/quest immunity 12th,
  quivering palm 13th - once per week,
  touch within 3 rounds, victim HD <= monk
  HD and HP <= 200%, command within one
  day per level), the open-hand stun/kill
  (stun at 5+ over needed, d6 rounds; kill
  % = victim AC + one per level above 7th,
  may be negative), the monk save
  advantages (missile dodge on petrification
  save, no damage on save, half damage on
  failed save from 9th), the ranger surprise
  numbers (d6 1-3 / surprised on 1) and the
  paladin turn ladder (cleric of paladin
  level - 2, from 3rd; wraps the R147
  matrix III) - the R184 records paid off.
  LESSON: C++ char literals need Q
  (apostrophes) not DQ - the mirror of the
  R186 Q-vs-DQ bug; check the TARGET type
  (char vs const char*) before picking the
  quote helper. Real gate: rules/subclass-
  specials.h = 295038623acd45abc3cc5e48427-
  6cef9. Next: the queued boxes (the
  subclass arc complete).
- R188 landed 2026-10-05: commit 4dc0119
  (first-try GREEN), census 105. The prime
  requisite XP adjustment - the QUEUED-BOX
  VERIFY pattern, first of the five
  remaining unchecked phb boxes:
  rules/xpadjust.h CREATED - the printed
  per-class +10% of earned experience gates
  (fighter STR 16+, magic-user INT 16+,
  cleric WIS 16+, thief DEX 16+; paladin
  STR and WIS both 16+, ranger STR INT and
  WIS all 16+, druid WIS and CHA both 16+;
  illusionist, assassin and monk NEVER -
  all printed) and the worked-example
  rounding (975 -> +98 -> 1073, fractions
  round UP, formula (xp+9)/10). The verify
  duty: the engine ladder primeRequisitePct
  in character.cpp (+10, +5, 0, -10, -20
  by score) - the +10 rung at 16+ is the
  printed rule; the +5/0/-10/-20 rungs are
  ENGINE CONVENTION, unsourced (the PHB
  class sections carry only the +10 notes,
  the DMG ADJUSTMENT AND DIVISION section
  has no prime-requisite ladder, and the
  phrase prime requisite does not appear in
  the DMG at all). The character.cpp comment
  is REPLACED (comment-only patch, code
  lines verified unchanged by strip-diff)
  to record the convention. Six patches this
  round (the comment patch is the 6th).
  LESSON: the marker-spans-newline bug bit
  AGAIN (R181, R184, now R188) - the
  character.cpp marker crossed a line break
  in the new text; the post-patch assert
  caught it. RULE now carved in stone: the
  patch() marker MUST be a single line of
  the NEW text, checked at write time.
  Real gate: rules/xpadjust.h = a92aa3f15-
  03f9a3d5d9b167d9a568a6d. The four queued
  boxes left: the PHB weapon-table
  book-verify pass (R144/R158 vs the print),
  starting money by class, the Armor Class
  table verify, Wisdom Table II wiring.
- R189 landed 2026-10-05: commit f9eb6a7
  (first-try GREEN), census 106. The
  weapon-tables book-verify pass - the
  R144/R158 vs print check, second of the
  queued boxes: rules/weapontables.h CREATED
  - the PHB WEIGHT AND DAMAGE BY WEAPON
  TYPE chart (50 rows: weight gp, S/M and
  L damage ranges; spear weight kept as
  the printed 40-60 RANGE), the speed-
  factor cross-verify (18 named weapons -
  every readable cell confirms the R158
  engine ladder row-for-row; horseman flail
  speed 6 stays the R158 convention since
  its OCR cell is mangled), the printed
  notes (lances double from a charging
  mount, spear set to receive doubles,
  +2 attacking from rear / +4 vs stunned
  or prone). The R144/R145 p.38
  AC-adjustment standing note CLOSED:
  R149 verified 8 of 15 rows; remaining
  cells OCR-mangled (digit runs like
  -1000000), stay pinned to the 1eonline
  compilation. New audit line: R189
  weapon tables verify audit: bad 0.
  Real gate: rules/weapontables.h =
  01111df378f3d61f9f4fe84edabe2ac5;
  splice advisory a51a1479fdd22478d9ac682-
  45be2a7ae. Three queued boxes left:
  starting money by class (likely R190),
  the Armor Class table verify, Wisdom
  Table II / cleric bonus spells wiring.
- R190 landed 2026-10-05: commit bd8de78
  (first-try GREEN), census 107. The starting
  money by class - second of the queued
  boxes: rules/startmoney.h CREATED - the
  printed STARTING MONEY table (cleric 3d6
  30-180 gp, fighter 5d4 50-200, magic-user
  2d4 20-80, thief 2d6 20-120, every class
  row a dice roll x10 gp) plus the printed
  MONK row 5-20 gp (5d4) - the one entry
  with NO x10 (the DMG MONEY section: monks
  are ascetics) - and the DMG companion
  pin: the PLAYER CHARACTER EXPENSES rule,
  not less than 100 gp per level per month
  (pcMonthlySupportCost). The engine has NO
  party-creation money code (verified
  repo-wide) - the box resolves to a fresh
  pin; subclass starting money not printed
  (header comments record it). New audit:
  R190 starting money audit: bad 0. Real
  gate: rules/startmoney.h = 9b53967c598c-
  6805567e7c06d800473f. LESSON: the
  create-marker for the header was a
  two-line comment span - the R181/R184/
  R188/R189 newline-marker bug bit AGAIN,
  caught pre-acid-test; use a single-line
  marker (e.g. the #ifndef line) for
  created files too. Two queued boxes left:
  the Armor Class table verify, Wisdom
  Table II / cleric bonus spells wiring.
- R191 landed 2026-10-05: commit 172ef32
  (first-try GREEN), census 108. The Armor
  Class table verify - third of the queued
  boxes, and the verify caught a REAL
  DIVERGENCE: the engine None armor row read
  baseAc 9 against the printed ARMOR CLASS
  TABLE (None 10, shield only 9) - REPINNED
  in items/items.cpp (the repin also matches
  the engine p.38 worked examples, Balto
  unarmored AC 10; the items.h convention
  comment repinned with it). The other nine
  rows verified cell for cell (padded 8,
  leather 8, studded 7, ring 7, scale 6,
  chain 5, splinted 4, banded 4, plate 3).
  rules/armorratings.h CREATED - the printed
  composite ladder (none 10 through plate
  mail + shield 2), the shield step (one
  class better), the magic rule (each +1
  lowers AC 1; a +1 converts to a 5% lesser
  likelihood of being hit), the flank/rear
  shield negation and magic-armor-weightless
  notes. New audit: R191 armor class ratings
  audit: bad 0. Real gate: rules/armor-
  ratings.h = 3dd0435806a03eab1dc76f0b02cee-
  ece. LESSON: the audit probe assumed the
  ladder was LINEAR (10 - i) - it is not
  (leather 8 and studded 7 share columns);
  pre-delivery simulation caught it; the
  audit kLad array must be explicit. One
  queued box left: Wisdom Table II / cleric
  bonus spells wiring (likely R192).
- R192 + R192b landed 2026-10-05: commit
  4774f83 (R192 preflight RED - 4 compile
  errors in the battery audit, fixed by
  R192b before push), census 109. The
  wisdom wiring - the LAST QUEUED PHB BOX:
  rules/wisdom.h CREATED - Wisdom Table I
  (the magical attack adjustment ladder 3
  -3 through 18 +4, mental attack forms
  only; the Table I gates: Wis 17 is the
  minimum for 6th level spells, 18 for 7th)
  and Wisdom Table II (the CUMULATIVE
  cleric bonus-spell ladder - wis 13 one
  1st through 18 two 1st, two 2nd, one
  3rd, one 4th; the spell failure ladder
  20/15/10/5/0 at wis 9-12). WIRED in
  spells/spells.cpp: clericSpellSlotsWith-
  Wis (base slots + bonus, entitlement-
  gated - the printed note; the Wis-17/18
  gates close the R130 wisdom-not-modeled
  engine limit; the printed L16 ** row
  already grants the 7th at 16, the gate
  is wisdom-side) and rollClericSpell-
  Failure (d100 equal or less: the spell
  is expended with no effect).
  R192b LESSON (the R180b lesson AGAIN):
  the audit invented a Dice API (default
  constructor + seed()) - rules::Dice wraps
  a rules::Rng& and the RNG OWNS THE SEED
  (explicit Dice(Rng&), Rng(seed)); the
  established regtest idiom is
  rules::Rng r(seed); rules::Dice d(r);
  with separate Rng locals for each
  independent roll. The census wall (100+
  FAILs) was all downstream of the missing
  binary. Also pre-delivery: a wrong
  engine-row probe (L5 cleric 2nd base is
  3, not 1 - moved to L3) caught by the
  simulation. Real gate: rules/wisdom.h =
  3cc849758d35f6cb937a2e1bc3ad435a. THE
  PHB QUEUED-BOX LIST IS NOW EMPTY (R188
  prime requisites, R189 weapon tables,
  R190 starting money, R191 armor class,
  R192 wisdom) - the gap report names what
  comes next.
- R193 landed 2026-10-05: commit 1802907
  (first-try GREEN), census 110. The CHA
  table repin - PHB divergence 5 of the
  R177 founding read, the LIVE one: rules/
  character.cpp chaReactionAdj repinned
  from the flat -4..+4 ladder to the
  printed PERCENT ladder (3 -25, 4 -20,
  5 -15, 6 -10, 7 -5, 8-12 0, 13 +5,
  14 +10, 15 +15, 16 +25, 17 +30, 18
  +35) - all five party call sites feed
  dm.cpp rollReaction (d100 + adj), so
  the printed percents land on the d100
  reaction bands directly, no band
  re-carving needed; chaLoyaltyBase
  repinned to the printed percent ladder
  (-30 through +40); chaHenchmenMax
  repinned at its two divergent cells
  (cha 4 = 1, cha 12 = 5). character.h
  range comments repinned with them.
  LESSON: pre-delivery review caught a
  mangled string-hack in the reaction
  patch AND all three audit arrays with
  miscounted tails (the 13-18 cells) -
  the arrays are now pre-asserted in the
  splice itself against the printed spot
  cells. New audit: R193 charisma table
  audit: bad 0. Remaining PHB divergences:
  3 (WIS ladder -2..+2 vs print -3..+4,
  the print already pinned in rules/
  wisdom.h R192, the character.cpp
  wisMagDefAdj ladder remains) and
  4 (INT languages).
- R194 landed 2026-10-05: commit b7e1d40
  (first-try GREEN), census 111. The WIS
  Table I repin - PHB divergence 3 of the
  R177 founding read: rules/character.cpp
  wisMagDefAdj repinned from the engine
  -2..+2 convention to the printed ladder
  (3 -3, 4 -2, 5-7 -1, 8-14 0, 15 +1,
  16 +2, 17 +3, 18 +4) BY DELEGATING to
  rules::wisMagicalAttackAdj (the R192
  header pin) - one ladder, not two
  copies that can drift; the saves.h note
  repins (mental attack forms involving
  will force only; the save rolls still
  do not call it - the caller assembles
  the modifier, the per-spell mental-form
  flag is not yet engine data). New
  audit: R194 wisdom defense repin audit:
  bad 0. LESSON: the saves.h marker
  spanned a newline (the recurring
  marker bug, sixth bite) - caught
  pre-acid-test. Also: an acid test run
  on a HALF-PATCHED tree reported
  "applied 5, already 3" (leftovers from
  a failed first run) - ALWAYS re-run
  from a fresh pristine copy after any
  splice failure. Remaining: divergence 4
  (INT languages) - the LAST founding-
  read divergence.
- R195 landed 2026-10-05: commit 20834f6
  (first-try GREEN), census 112. The INT
  Table I repin - the LAST founding-read
  divergence (4): rules/character.cpp
  intExtraLanguages repinned to the
  printed INTELLIGENCE TABLE I column
  (3-7 none, 8-9 one, 10-11 two, 12-13
  three, 14-15 four, 16 five, 17 six,
  18 seven); the engine convention had
  diverged at every score above 3.
  Display-only accessor. New audit: R195
  INT languages repin audit: bad 0.
  LESSON: the paren-balance sweep flagged
  an unclosed paren inside an audit
  COMMENT line ((the R177 read: with the
  closer on the next line) - comments
  cannot break the compile, but the sweep
  holds the whole file to balance; reword
  the comment rather than carve an
  exception. MILESTONE: THE FOUNDING-READ
  LIST IS EMPTY - all six PHB ability
  tables read the print (STR R153, DEX
  R178c, CON R178c, INT R195, WIS R194,
  CHA R193); both gap reports record it.
  The PHB arc stands: subclass arc
  R179-R187, verify boxes R188-R192,
  divergences R193-R195 all closed. Next:
  the gap reports name the next round
  (candidate seams: the remaining
  not-yet-engine-data flags such as the
  per-spell mental-form flag, the monk
  weapon-damage notes, the p.38
  OCR-limited cells).
- R196 landed 2026-10-05: commit df7ea63,
  census 113 - but it took TWO fix rounds
  (R196b, R196c), the first rounds ever
  to ship RED twice. The INT Table II
  repin: spells/spells.cpp
  chanceToLearnPct repinned from the
  engine ladder (divergent at 10, 16, 17,
  18) to the print (9 35, 10-12 45, 13-14
  55, 15-16 65, 17 75, 18 85, 19+ 95);
  new minSpellsPerLevel/maxSpellsPerLevel
  accessors (4/6, 5/7, 6/9, 7/11, 8/14,
  9/18, 10/All; All = -1, the repo
  unlimited convention); declarations +
  comment repin in spells.h. New audit:
  R196 INT table II audit: bad 0. Six
  patches, then:
  R196b LESSON (the big one): patch 3
  anchored the accessor block on
  rollChanceToLearn's OPENING line -
  nesting minSpellsPerLevel and
  maxSpellsPerLevel INSIDE its body.
  Braces stayed balanced so the hygiene
  sweep passed; only the Termux preflight
  compile caught it ("function definition
  is not allowed here"). RULE: a patch
  that inserts after a function must
  anchor on the function CLOSING line or
  a following landmark, never the opening
  line. Brace balance does not catch
  nesting - add a brace-DEPTH scan to the
  acid test (new symbols must land at the
  same depth as their neighbors).
  R196b LESSON 2 (marker collision, the
  R178c class): the first R196b draft
  used a marker that ALREADY existed in
  the broken text (a reorder leaves every
  line present, just moved) - patch()
  reported "already 1" on both runs and
  silently did nothing. RULE: when the
  new text is a pure reorder, add a
  distinguishing comment line to the new
  block and use THAT as the marker;
  always grep the pre-patch file for the
  marker.
  R196c LESSON: the audit's band-shape
  loop (lo <= hi for i 9..25) counted
  the 19+ row's -1 sentinel as a
  violation - exactly bad 7 (i = 19..25),
  a perfect diagnostic signature: a
  nonzero bad whose value equals the
  count of edge-row scores points at the
  check, not the data. RULE: pre-asserting
  the audit ARRAYS is not enough -
  SIMULATE the audit's full LOGIC (loops,
  probes, edge rows, sentinels) in Python
  against the engine pins before shipping.
  RULE (ritual): the delivery ritual
  contains GATES ONLY - md5 advisory,
  py_compile, run twice, preflight,
  commit/push. The paste step (tail -n +7
  from the canvas, nano) is NEVER part of
  the ritual; do not write nano into it
  (violated once this round, corrected).
  Next: mine seams - the per-spell
  mental-form flag for WIS save wiring,
  the monk weapon-damage notes, the p.38
  OCR-limited AC cells.
- R197 landed 2026-10-05: commit b6ce031
  (first-try GREEN), census 114. The
  per-spell mental-form flag - the R194
  seam: the printed Wisdom Table I note
  (magical defense adjustment applies only
  to mental attack forms involving will
  force) finally has per-spell engine
  data. spells::spellIsMentalForm flags
  the registry's two will-force forms
  (charm person - charming; charm monster
  - mass charming); spellSaveModWis(id,
  wis) assembles the WIS magical defense
  adjustment via wisMagicalAttackAdj (the
  R194 ladder) on those, 0 on everything
  else. JUDGMENT: the holds are NOT
  will-force forms - the PHB Serten spell
  immunity print groups hold with command,
  domination, fear and scare, apart from
  beguiling/charm/suggestion; fear,
  hypnosis, suggestion, phantasmal forces
  ride the flag when their registry rows
  arrive. 3 patches (spells.cpp impl,
  spells.h declarations, regtest.cpp
  audit); save rolls stay caller-
  assembled (rules/saves.h design). New
  audit: R197 mental-form flag audit: bad
  0. The acid test now runs the full
  post-R196 battery: brace-depth scan on
  every new function (R196b), per-line
  paren balance (R195), single-line
  markers absent pre-patch and grepped
  (R196b/R178c), full audit-logic
  simulation (R196c), diff -rq scope
  check, audit printf count = census.
  Next seams: the monk weapon-damage
  notes, the p.38 OCR-limited AC cells.
- R198 landed 2026-10-05: commit 12afe74
  (first-try GREEN), census 115. The class
  weapon allowlists - the CHARACTER CLASSES
  TABLE II weapons column, the monk list's
  home. The engine had the weight/damage
  chart (R189) and speed factors (R158) but
  NO class-allowance data. rules/weapontables.
  h now pins the print cell for cell:
  classUsesAnyWeapon (fighter, paladin,
  ranger, assassin), the limited lists
  (cleric 7 chart rows, druid 9, MU/
  illusionist 3, thief 8, monk 24), and
  weaponAllowedForClass - the engine
  question. JUDGMENTs recorded: the family
  words expand to chart variants (flail/
  mace = footman + horseman, staff =
  quarterstaff, sling = bullet + stone,
  hammer = the plain hammer, NOT the lucern
  - it is a pole arm); thief sword = short/
  broad/long per the printed footnote, never
  bastard/two-handed; monk pole arm = the
  chart 15 pole-arm rows (pikes and picks
  out); crossbow pins by name for the monk
  alone (the chart prints only its quarrels).
  2 patches (weapontables.h, regtest.cpp
  audit ~90 probes). LESSON: the acid test
  caught TWO draft bugs pre-delivery - (1) a
  shadowing bug, the rowFn loop variable
  named `comment` overwrote the header
  comment block, so the marker went missing
  and patch() failed its post-assert (the
  assert EARNED its keep - a splice with no
  post-assert would have shipped a "monk"
  string as the header comment); (2) an
  illegal array-from-array C++ init
  (`static const char* const k[7] = kCleric;`
  - not legal; index the named array
  directly per branch). Also: the paren
  sweep must exempt multi-line CODE
  signatures (unbalanced parens on
  continuation lines are legal; the R195
  rule is about COMMENT lines). Next: the
  PHB p.38 OCR-limited AC cells stay closed
  (R149); next seams - the poison-use
  columns (TABLE II oil/poison), the
  monk/cleric thief-ability sharing rows,
  or the remaining flagged-as-engine-limit
  items per the gap reports.
- R199 landed 2026-10-05: commit 57e1584
  (first-try GREEN), census 116. The oil and
  poison columns of the CHARACTER CLASSES
  TABLE II - the two columns right of the
  weapons column R198 pinned. The table is
  now complete in the engine. The three-
  valued allowance encoding (1 yes, 0 never,
  -1 referee discretion), both columns:
  classOilUse - yes for every class but the
  monk (the prose: not even flaming oil is
  usable by them); classPoisonUse - cleric
  never, paladin never, assassin yes, the
  rest the question mark; the evil-cleric
  footnote as its own modifier,
  classPoisonUseForAlignment - the
  prohibition is strictly for clerics NOT
  of evil alignment, so an evil cleric
  reads the referee discretion; the
  paladin never is unconditional. 2 patches
  (weapontables.h, regtest.cpp audit).
  Next: TABLE II is fully pinned - next
  seams from the gap reports: the monk/
  cleric thief-ability sharing rows
  (subclassspecials.h names the OCR-swallowed
  list item 1), the NPC monk alignment split
  (50/35/15 lawful good/neutral/evil), or
  the DMG-only tables still unpinned.
- R200 landed 2026-10-05: commit d646d69
  (first-try GREEN), census 117. The monk
  falling-while-climbing ladder - the
  print rows under the thief-ability
  paragraph: 4th (Disciple) fall up to 20
  feet within 1 of a wall, 6th (Master)
  30 within 4, 13th (Master of Winter) any
  distance within 8, with the wall-contact
  rule (damage-free only when periodic
  contact is possible; tree trunk, cliff
  face serve). rules/subclassspecials.h:
  monkWallAssistedFallFeet (0/20/30/-1-
  any), monkWallAssistedFallProximityFeet
  (0/1/4/8), monkWallAssistedFallRequires-
  Contact. 2 patches. LESSON (the R196c
  rule earning its keep again): the audit
  array wrote EIGHT 30s (levels 6-13) but
  13th reads -1 - the 6th-12th band is
  SEVEN levels; the full-logic simulation
  flagged bad 2 and pinpointed the band
  boundary pre-delivery. RULE: when an
  audit array encodes a band ladder, count
  the band sizes out loud (4-5 two, 6-12
  seven, 13+ five of the 17) before
  writing the initializer. Round 200. Next
  seams: the NPC monk alignment split
  (50/35/15), the DMG-only tables still
  unpinned.
- R201 landed 2026-10-05: commit 4a040a7
  (first-try GREEN), census 118. The NPC
  monk alignment split - the monk prose
  pin: NPC monks align 50% lawful good,
  35% lawful neutral, 15% lawful evil.
  rules/subclassspecials.h: the three
  percent accessors plus
  monkNpcAlignRollRange(index, lo, hi) -
  the cumulative d100 bands (LG 1-50, LN
  51-85, LE 86-100; out-of-range index
  the 0-100 miss band). The PC side stays
  gated by SUB_ALIGN_LAWFUL_ONLY. 2
  patches. NOTE: the depth scan reads 1
  on one-line accessors ({ return 50; }
  closes its own brace on the declaration
  line) - not a nesting bug; final depth 0
  is the real balance gate. The monk
  prose seam is now fully mined (surprise
  ladder, stun/kill, quivering palm, save
  advantages, falling ladder R200, NPC
  alignment split R201). Next: the DMG-
  only tables still unpinned per the gap
  reports.
- R202 landed 2026-10-05: commit 58cba6a
  (first-try GREEN), census stays 118 - a
  REPORT-SYNC round, no audit. The gap-
  report convention (a round's log entry
  lands in the SAME commit) had slipped:
  R197 through R201 - five first-try-GREEN
  engine rounds - shipped with no log
  entries. The round pays the documentation
  debt: the five entries appended to the
  round log in tools/dmg_gap_report.md
  (where the PHB round log lives too - the
  R193-R196 precedent), in the established
  style, with the Next: chain flowing
  through them and closing with the seam
  status (the monk prose seam fully mined).
  RULE (carved): the log entry is part of
  the round - if a sprint runs multiple
  engine rounds back to back, run a report-
  sync round before the seam drifts; five
  entries owed was the upper bound. Next:
  the DMG-only tables still unpinned per
  the gap reports.
- R203 landed 2026-10-05: commit f9fafc8
  (first-try GREEN), census 119 - the
  apparent armor AC repin, closing the
  R144/R145 named approximation. The DMG
  p.38 note: the weapon-type adjustments
  are "for weapons versus specific types
  of armor, not necessarily against actual
  armor class" - the p.38 row keys the
  armor WORN (base + shield), never the
  magic/DEX-shifted effective AC.
  items::apparentArmorAc(armor, shield)
  is the new key; the to-hit target still
  reads full effectiveAc; the two actor.cpp
  callers (melee hitAdjustment, missile
  path) pass it. Audit pins the apparent
  cells (None 10/9, Leather 8/7, Plate
  3/2), plus-ignored, the contrast (plate
  +2/shield/DEX18: eff -4 vs app 2), the
  dagger row keyed each way (col 0 -4 old
  fold vs col 2 -3 repin), and the shield-
  only +1. LESSON (carved, mid-round
  patch-count drift): the patch-count
  assert caught a 6-vs-5 drift before
  delivery - always re-run the full gate
  battery after ANY post-acid-test splice
  edit. The R202 log convention held
  first-try: the round-log entry rode the
  same commit as a 7th patch. Next: the
  DMG-only tables still unpinned per the
  gap reports.
- R204 landed 2026-10-05: commit bbef7d3
  (first-try GREEN), census 120 - the
  Item Saving Throw Matrix (DMG p.80,
  matrix III), the DMG-only sweep's first
  catch: the lane grenade.h named and
  deferred since R157. rules/
  itemsavethrow.h (new file, the
  grenade.h pattern): the 14 material
  rows x 11 attack forms, all 154 cells;
  the ceramic 18/12 and crystal 19/14
  BLOW cells independently confirmed by
  the R157 break-save pins (the
  cross-check lives in the audit). The
  modifiers: the magical ladder (+2 and
  +1 per plus above +1), the own-mode
  +5, the fall surfaces (hard 0,
  wood-like +1, fleshy +5) with the
  per-5-feet distance penalty, the hard-
  metal cold-strike -10 footnote, the
  normal-fire exposure rounds (parchment
  1, cloth 2, bone 3). Save: d20 + adj
  >= cell (the R157 convention). The
  4-patch splice (new file, include,
  audit, log entry). LESSON (relearned,
  cheap): a splice run that CRASHES
  mid-way dirties the tree (this round:
  NameError after two patches applied) -
  recreate pristine from the tarball and
  rerun the FULL battery; never read a
  partial-run "already N" as a clean
  count. Next: the DMG-only sweep
  continues per the gap reports.
- R205 landed 2026-10-05: commit 526cf72
  (first-try GREEN), census 121 - the
  spying tables (DMG pp.19-20, the
  SPYING section after the assassin
  guild tables), the lane
  rules/assassinate.h named and
  deferred in R164. rules/spying.h
  (new file, the grenade.h pattern):
  the ASSASSIN SPYING TABLE (spy
  level 1-17 x simple/difficult/
  extraordinary, all 51 cells), the
  mission days (1-8 / 5-40 / as
  required), the discovery formula
  (cumulative 1 percent per day capped
  at 10, minus the spy level, floor 1
  percent) with the four precaution
  tiers (none flat 1 percent per week;
  minimal the modified percent per
  week; moderate twice per week; strong
  doubled twice per week; a leading
  spy reads none) and the tenfold
  20-50-day post-capture window; the
  five-band SPY FAILURE TABLE (doubling
  as the discovery table) with the
  modifiers (difficult +10,
  extraordinary -5, discovered +25);
  the torture outcomes (1-2 dead, 3-4
  revealed, 5-6 turncoat); the
  fanatical rule; the hired-spy
  8th-level cap. 4-patch splice (new
  file, include, audit, log entry).
  LESSON (cheap, caught pre-delivery):
  the gap-report anchor must match the
  file's ACTUAL line-wrap breaks - grep
  the anchor with cat -A or fail the
  splice; recreate pristine after any
  crashed run. Next: the DMG-only sweep
  continues per the gap reports.
- R206 landed 2026-10-05: commit e107d00
  (GREEN after one preflight-RED fix),
  census 122 - pursuit and evasion of
  pursuit (DMG pp.67-69), a seam with no
  prior coverage anywhere. rules/
  pursuit.h (new file, the grenade.h
  pattern): underground - the pursuit
  likelihood ladder (semi-intelligent
  motivated 80; low intelligence 20/40/80
  by numbers, 100 when the outnumbering
  pursuers feel greatly superior), the
  three end-condition cases by relative
  speed (100/50 feet/5 rounds; 150/80/1
  turn; 200 feet/no cap), the food and
  treasure distraction arithmetic, the
  multiple-choice rule and the detection
  radii (corner 60; metal 90, boots 60,
  quiet 30), the movement procedure (3
  phases = 1 round, contact at 10 feet);
  outdoor - the BASE CHANCE OF EVADING
  PURSUIT table (base 80, every speed/
  terrain/size/light row), the surprise
  rule and the hourly recheck (0 or less
  = immediate confrontation). R206b fix
  rode the same commit (3 audit-block
  patches; pursuit.h unchanged). TWO
  LESSONS (carved): (1) the acid-test
  simulation must mirror the audit
  ASSERTIONS including polarity and every
  arithmetic comment - the sim model
  silently fixed a missing bang
  (foodDistractionSucceeds(100,1) IS
  true: at 100 percent the print spares
  the second d10) and the Termux
  preflight caught bad 2 the sim blessed;
  (2) assembly arithmetic: sum EVERY row
  before pinning (the +10 over-24-pursuer
  band was dropped; true cell 10, not 0).
  Also: the battery halts at the first
  nonzero audit, so a CENSUS FAIL cascade
  below the bad line means "stopped
  there", not "broken census". Next: the
  DMG-only sweep continues per the gap
  reports.
- R207 landed 2026-10-05: commit
  a8e63a9 (GREEN after one
  preflight-RED fix), census 123 - the
  town taxation system (DMG p.90, the
  print worked example town, duties/
  excises/fees/tariffs/taxes/tithes/
  tolls), a seam with no prior coverage.
  rules/taxation.h (new file, the
  grenade.h pattern): import duty 1
  percent, doubled for foreigners; luxury
  tariff 5 on sale; entry fee 1 cp a
  citizen, 5 a non-citizen (per head or
  wheel); annual head tax 1 cp peasant,
  1 sp freeman, 1 gp gentleman/noble;
  foreigner sales tax 10, no service tax;
  tithe pledge; property tax 5;
  citizenship 30 days + 10 gp; foreign
  coin - merchant fine 5, exchange 90
  (integer division: 1 foreign cp gives
  0), 100-noble limit, 50 over-limit fine,
  24h money-changer grace when bound for
  the changers, 10 gem surtax; toll
  evasion confiscation + imprisonment. 4
  patch splice (file, include, audit, gap
  log entry). R207b fix rode the same
  commit (1 patch, taxation.h only): the
  bad 1 was the entry-fee POLARITY - the
  helper declared the flag "citizen"
  (true = 1) while the audit and the
  duty-helper convention read it
  nonCitizen (true = 5); the audit was
  correct, the header was repinned.
  LESSON (carved, third strike on the
  same theme): the audit simulation must
  LITERALLY execute each assertion
  against the ACTUAL header source, not
  an assumed body - the R206b sim flaw
  repeated: I re-implemented the helper
  from intent, and the inverted ternary
  sailed through. Read the generated C++
  line by line and evaluate it as C++
  would. Also: the user pasted the r207b
  splice as tools/r297b_splice.py (name
  typo, harmless - applied fine); confirm
  the filename in the hygiene NOTE before
  worrying about a wrong-round file.
  Next: the DMG-only sweep continues -
  social class/rank, government forms,
  titles, town social structure (DMG
  pp.88-89 area).
- R207c landed 2026-10-05: commit ce0a324, the
  audit_eval.py tool - the fix for the repeated
  sim-blesses-a-bad-audit issue (R206b, R207b, both carved
  lessons). The tool lives in the repo at tools/audit_eval.py
  (so the tarball carries it and the sandbox reset can no
  longer lose it) and reads the ACTUAL generated C++: it
  parses every inline helper body in rules/*.h (constants,
  ternaries, clamp chains, local tables with enum dims,
  enum return types, braced ifs, ref out-params, cross
  calls, C truncating division) and executes every audit
  assertion in regtest.cpp against those bodies, literally.
  Anything outside the subset prints UNVERIFIED and fails
  the run - it never silently passes. Gate semantics: named
  blocks only count (python3 tools/audit_eval.py RNNN);
  the pre-R205 blocks (structs, classes, engine objects)
  are outside the subset and stay UNVERIFIED by design.
  md5 8d2a44f7309e2896d712633283bed8b9 - and unlike the
  splices (where the md5 is advisory because content is
  written programmatically), THIS file is pasted whole
  into nano, so the md5 is the REAL gate: a mismatch means
  the paste was mangled; re-paste with soft-wrap off.
  LESSON (process): the acid test now ends with the
  audit_eval gate, and a preflight RED after an audit_eval
  GREEN is the one case that means the tool's C subset
  missed a construct - extend the tool, never bypass it.
  Also in the commit: the R207c gate splice
  (tools/r207c_splice.py, 1 patch to
  tools/preflight.sh) - the hygiene gate now
  knows the tool-only round shape (untracked
  plain tools/*.py, never a *splice*.py, no
  tracked modification = NOTE, not the
  7a86ee7 FAIL). The user first hit a false
  RED: the tool-only delivery tripped the
  never-ran-splice FAIL, because the gate
  was born of a splice round. LESSON: when a
  new round SHAPE arrives (tool-only, no
  splice), teach the gate the shape - never
  stage files to dodge it. Note: the
  audit_eval md5 drifted on the user paste
  (8d55443d vs 8d2a44) yet ran perfectly -
  the CRLF artifact again; for paste-whole
  TOOLS the md5 is the first check but the
  run is the real gate (all three blocks
  verified, GREEN).
- R208 landed 2026-10-06: commit 57b86ab, census 124, GREEN on the
  first preflight (no b-round). The DMG pp.88-89 SOCIAL CLASS AND
  RANK seam pinned: rules/socialrank.h CREATED - the government
  forms table (enum GovForm, 19 forms; enum GovTrait mirrors the
  form order as an identity table; semantic pins via distinctive
  trait comparisons, e.g. GOV_GYNARCHY->GOVT_FEMALES_ONLY), the
  worked example aristocracy (CONJUNCTIVE: military service AND
  100+ acres AND 10+ gp tax, with the merchant waiver service AND
  20+ gp with the land requirement waived - rationale in the
  header comment: the waiver would be vacuous under an or-reading),
  the town/city social structure (TOWN_* classes, offices, the
  townProvidesLesserOfficials helper), knights and the noble
  titles - the northern title ladder pins the print's odd order:
  Duke precedes Prince (10 secular titles, Emperor 0 ... Knight
  9); German equivalents table as raw ints mapped to GT_* enum
  values, -1 for unmapped rows. All helpers in the audit_eval
  evaluable subset (int/bool/enum only, no strings). The R207c
  audit_eval gate was run as the ACID CLOSE on a FRESH tarball:
  verified bad 0 (47 asserts), R205-R208 all verified together,
  and the mutation test (flip townProvidesLesserOfficials
  TOWN_MIDDLE->TOWN_LOWER) reported bad 1 RED, restored GREEN -
  the gate has teeth. Fresh-tarball reproducibility diff clean
  (only socialrank.h new + regtest.cpp + dmg_gap_report.md
  changed); brace/paren 0/0; census 124; paste md5 drifted as
  expected (advisory only). Next: the DMG-only sweep continues.
- R209 landed 2026-10-06: commit 19ea2f6, census 125, GREEN on
  the first preflight (no b-round). The NPC personae FACTS
  seam (DMG pp.114-115) pinned: rules/npcpersonae.h CREATED -
  the classed NPC ability dice adjustments (10 classes in print
  list order; the as-fighter ranger/paladin rows expanded in
  place, the as-thief assassin row adding strength +1; the
  druid 12/14, ranger 12, paladin 17, illusionist 15/15, monk
  12/15/15 minimums), the three occupations (laborer strength
  +1 to +3, level-0 mercenary strength +1 CON +3 with 4 minimum
  hit points, merchant 12/12 INT/CHA), the DMG demi-human
  adjustment table (its OWN table, not the PHB race table), and
  the FACTS TABLES: alignment d10, possessions d10, appearance
  age and general d10s, sanity d10 with the insane/maniacal
  asterisk reroll rule, plus the p.11 die rules (general
  characters 1->3 and 6->4; special characters +1 per die under
  6) and the three-tendency floor. Ground truth: the book
  upload OCR is SCRAMBLED at the personae table boundaries
  (headers duplicated/misplaced, the class-adj and dress lists
  run together) - verified against the live 1eonline.info
  compilation (3dmg/npc.htm), which also carries compilation
  annotations NOT in the print (wealth x2/x3/x4 multipliers,
  sanity reaction percents) - excluded.
  TWO audit_eval LESSONS (both caught by the R207c gate itself,
  no land damage): (1) the tool parses table initializers as
  raw digits ONLY (re.findall of -?\d+) - enum-named cells
  (ABILITY_WIS, NPCA_LG) yield an empty flat array and either
  EVAL ERROR index-out-of-range or unknown-identifier; ALL
  table cells, header AND audit-side expected arrays, must be
  raw ints in the engine Ability enum order (0 STR 1 INT 2 WIS
  3 DEX 4 CON 5 CHA, 6 = ABILITY_COUNT as the none marker) -
  the R208 convention extends to ability codes too. Also: the
  tool does NOT parse "enum Ability : int" (typed enums) from
  character.h, so rules::ABILITY_* cannot appear in an audit
  at all; raw codes only. (2) for-walk bodies must be a
  SINGLE braceless if(...)++bad; even nested-for with braces
  fails - merge the inner ifs with || into one condition, keep
  the nested braceless fors. Mutation test: halfling CON cell
  flipped 4->5, bad 1 RED, restored GREEN; census 125;
  fresh-tarball reproducibility clean. Next: the DMG-only
  sweep continues - the personae TRAITS tables (pp.115-116,
  the d12/d6 General Tendencies, the personality/interests/
  disposition/intellect/collections/nature/materialism/honesty/
  bravery/energy/thrift/morals/piety tables) are the natural
  next seam.
- R210 landed 2026-10-06: commit ffae453, census 126, GREEN on
  the first preflight (no b-round). The NPC personae TRAITS
  seam (DMG pp.115-116) pinned: rules/npctraits.h CREATED - the
  24 General Tendencies (d12 with the d6 half split: 1-3 rows
  1-12, 4-6 rows 13-24), the three-column Personality (d8 d8:
  1-5 average, 6-7 extroverted, 8 introverted; the shared
  words - friendly, aloof, hostile, rude, diplomatic - are
  PER-COLUMN enum codes, one code per cell), the 24 Interests
  (d6 halves; the four collector rows are enum codes 16-19,
  the collectors of Collections d12), Disposition, Intellect
  (dreaming through brilliant modify the INT rating),
  Collections, Nature, Materialism, Honesty, Bravery, Energy,
  Thrift, Morals (perverted/sadistic/depraved asterisk reroll -
  same shape as the R209 sanity rule) and Piety, plus the
  PRINT encounter/offer reaction adjustment percents (neurotic
  the print asymmetry: -1 to +6; insane 1-10; maniacal 1-20;
  disposition 1-6; nature 1-4; tendencies 1-8; bravery 1-20;
  personality 1-8; materialism 1-20). Ground truth: the upload
  OCR scrambles the two-column traits tables AGAIN (the
  upload's "Personality 6-7 Extroverted / 8 Introverted /
  1-5 Average" headers and the Interests 13-24 run interleaved
  with Collections) - verified against 1eonline.info/3dmg/
  npc.htm, which also annotates per-word percents NOT in the
  print (excluded) and a Q&A-note reading of the General
  Tendencies (d6, d12) header - the print reads (d12, d6) but
  the compilation's table layout is the true shape (d12 row
  number, d6 half).
  THE GATE EARNED ITS KEEP AGAIN, pre-delivery: audit_eval
  caught a REAL off-by-one in the d6-half helpers (they
  returned 1-based indexes against 0-based enums: tendency(4,1)
  read 13, not 12) plus an interest probe and a morals-resolve
  expectation - bad 8 then bad 6, fixed to bad 0 before the
  canvas was built. LESSON (folded into the standing sim
  discipline): when the helper computes an INDEX into an
  enum-ordered table, write the audit probes as raw expected
  indexes FIRST and check the helper returns index-1 (the
  enums are 0-based, the dice are 1-based); and simulate the
  whole audit in Python BEFORE the first splice run, not
  after the first RED. Mutation test: materialism reaction
  max 20->25, bad 1 RED, restored GREEN; census 126; braces
  0/0; zero apostrophes in the header; fresh-tarball
  reproducibility clean. Next: the DMG-only sweep continues -
  the height and weight tables and determination, and the
  language determination table (DMG pp.102-103 area of the
  print, upload lines ~7816+).
- R211 landed 2026-10-06: commit 4ca9348, census 127, GREEN on
  the first preflight (no b-round), and the first round GREEN
  on the FIRST audit_eval run - the R210 lesson (simulate the
  whole audit in Python BEFORE the first splice run) held.
  The NPC body and language seam (DMG pp.115-116, personae
  chapter tail) pinned: rules/npcbody.h CREATED - the MALES and
  FEMALES height/weight tables (7 races in print order; the
  under/over dice as packed count*100+sides - 212 = 2d12, 410
  = 4d10, 512 = 5d12; npcDieCount/npcDieSides unpack), the
  HEIGHT AND WEIGHT DETERMINATION percent bands (per race,
  both sexes: the under/average/over edges - dwarf 15/80 and
  20/65, human 20/80 and 25/75, etc.), and the RANDOM LANGUAGE
  DETERMINATION TABLE - a flat 100-face table, 55 kinds: the
  ten dragon faces each a kind, the eight giant faces (hill on
  31-33 as three faces of ONE kind), the three naga faces
  each a kind, 86-00 human foreign or other (the campaign
  footnote - the caller names the language).
  GROUND TRUTH NOTE (inverted from R209/R210): here the
  UPLOAD is authoritative and the live compilation
  EDITIALIZES the seam - it splits Human into NPC and PC rows
  with d20x10/(d12x10)-style entries, cites OSRIC, and reads
  the half-orc male over-weight as d20 (vs the print 4-40 =
  4d10) and the human male over-weight as 5d6 (vs 5-60 =
  5d12). RULE (the general one, now proven both ways): the
  BOOK UPLOAD is the print; the compilation is a secondary
  reading - when they disagree, pin the upload and record the
  compilation divergence in the header, unless the upload's
  OCR is itself scrambled (the R209/R210 personae tables
  case), where the compilation is the recovery source.
  Mutation test: half-orc male over-weight 4d10 -> 4d20,
  bad 1 RED, restored GREEN; census 127; braces 0/0; zero
  apostrophes; fresh-tarball reproducibility clean. Next:
  the DMG-only sweep continues - the special roles of the DM,
  hiring NPCs to cast spells (the cleric and druid spell
  request costs), monsters and organization (the DMG
  pp.116-118 area, upload lines ~7895+).
- R212 landed 2026-10-06: commit 89d260e (4ca9348..89d260e), census
  128, GREEN first preflight, first-attempt audit_eval GREEN (the
  R210 sim discipline held a second round running). The hiring
  NPCs to cast spells and non-human troops seam (DMG pp.116-118)
  pinned: rules/hirecost.h CREATED - the 40 cleric spell hire
  prices (18-row first table astral spell through earthquake
  PLUS the 22-row second table exorcise through true seeing;
  the upload OCR split names and costs into two separate lists -
  they pair BY ORDER, 22 and 22, self-consistent and pinned;
  glyph of warding heal is one OCR-glued line, two spells),
  each price as base + rate x unit-quantity (9 unit codes:
  flat, per person, per caster level, per recipient level, per
  person per caster level, per point healed, base plus per
  question, base plus per caster level, base plus per recipient
  level; the restoration like-amount clause read as 10000 +
  1000 per recipient level); the travel x2 not-at-risk and
  x5-or-refuse at-risk factors, the 25% charm-opposite rule,
  the deliberate attack-spell omission (none priced) and
  no-accompanying rule, the interruption clause; and the USE OF
  NON-HUMAN TROOPS control table 7 races x 3 columns (bugbear
  30/50/80, gnoll 30/40/80, goblin 40/50/90, hobgoblin
  20/40/90, kobold 25/50/95, lizard man 10/60/100, orc
  20/50/90) plus the 25% friendly-humans fight chance, the
  weak-leader-plus-officers impossibility (pinned 0), the
  high-pay-is-weakness clause, and the demi-human-master rule.
  NOT re-pinned: the HUMANOID RACIAL PREFERENCES matrix
  (already R169) - grep confirmed no overlap. Skipped as prose:
  MONSTERS AND ORGANIZATION (six S1/S2 examples - not table
  material).
  MODEL NOTE: the unit-quantity selector helper
  (hireQuantity) uses a chain of if-q-assignment statements,
  not a switch - audit_eval has NO switch support; the audit
  pins the table via 40-cell raw-int arrays plus worked
  sample prices (astral 4 persons = 20000, commune 3
  questions = 2500, raise dead cl9 = 5500, restoration cl8
  = 18000, heal 15 points = 3000, atonement lvl7 = 3500) and
  clamp probes. Mutation test: lizard man officers-strong
  100 -> 90, bad 2 RED, restored GREEN; census 128; braces
  0/0; zero backslashes and apostrophes; fresh-tarball
  reproducibility clean. Next: the DMG-only sweep continues -
  construction, siege and the underworld (the DMG pp.119+
  area, upload lines ~8170+).
- R213 landed 2026-10-06: commit 70d77a7 (89d260e..70d77a7), census
  129, first-attempt audit_eval GREEN (112 asserts) and first
  preflight GREEN - the third consecutive first-attempt round under
  the R210 simulate-first discipline (with one sim catch: the
  slave-efficiency band expectations were wrong in the probe list,
  12-15 workers/foreman is 60 and 8-11 is 70 - the sim caught it
  before the splice was written). The CONSTRUCTION & SIEGE economics
  seam (the print TOC: mining p.106, construction time pp.106-107,
  constructions p.107, siege engines pp.108-110) pinned:
  rules/construct.h CREATED - the MINING cubic volume table (8 miner
  groups x 3 rock types, cubic feet per 8h per miner, stone giant
  500/350/175 at the top), the linear multiple-workers volume, the
  max miners per 10-foot shaft (16/12/8/6/4 by group), the 24-hour
  shifts with the 8-hour worker cap, the natural cave chances
  (limestone 1 in 10, other sedimentary 1 in 50, lava 1 in 20, other
  igneous 1 in 100 - pinned as percents), the slave efficiency bands
  (foreman ratio 1:16/1:12/1:8/1:4 = 50/60/70/80 percent) with the
  1-guard-per-4-workers minimum, the CONSTRUCTION TIME pins (ditch
  3-4 men six weeks, heavy clay x2; stone one week per 10-foot cube;
  150 percent cost = 2x rate, 250 percent = 3x MAXIMUM; stone
  buildings four months, wood half; hoardings 10 feet per day; the
  four castle estimates 1yr+2-8mo / 2yr+1-6mo / 3yr+2-8mo /
  5yr+1-12mo; citizen labor -50 percent), the 44-row CONSTRUCTIONS
  cost table (arrow slit 3 gp through barred window 10 gp, print
  order), the per-square-foot adjustments (iron door 2 gp,
  secret door 5 gp larger, trap door 1 sp, wooden door 2 sp,
  reinforced 5 sp, drawbridge 2 gp, portcullis 2 gp), the stone
  course formula (base + base/10 per extra course; the worked
  example 500 gp at 10 courses = 950 gp), the tunnel ground factors
  (soft 1x, hard earth 2x, solid rock 5x), the rampart-above-ditch
  20 percent, the battlement composition (14 feet = two 4-foot
  merlons + two 3-foot embrasures), buttress 3 sections per 20
  feet, and the 12 siege engine costs (ballista 75 through
  trebuchet 500, siege tower 800). Compilation cross-check (uc.htm,
  constructiontime.htm, construction.htm) matched the upload
  everywhere visible.
  PAGE-LABEL CORRECTION (recorded in the gap report too): the real
  DMG TOC places the personae/hiring/troops seams at pp.100-106
  (height of characters p.102, non-human soldiers pp.105-106) - the
  R211 pp.115-116 and R212 pp.116-118 include-comment labels read
  high; the pinned content is unaffected. LESSON: derive page cites
  from the DMG TOC (the 1eonline dmg.htm index) not from
  chapter-order guesses in the upload stream.
  DELIBERATELY DEFERRED to R214: the WAR MACHINE FIRE TABLES (the
  crew column OCR is scrambled in the upload), the SIEGE ATTACK
  VALUES matrix (damage against wood/earth/soft stone/hard rock),
  and the CONSTRUCTION DEFENSIVE VALUES - all three need the
  compilation as the recovery source (the R209/R210 scrambled-OCR
  rule).
  Mutation test: hoist cost 150 -> 155, bad 1 RED, restored GREEN;
  census 129; braces 0/0; zero backslashes; fresh-tarball
  reproducibility clean. LESSON (splice authoring, both hit this
  round): patch() requires the marker to be a SINGLE line with no
  newline - multi-line header-comment phrases must be clipped to a
  one-line fragment; and the gap-report anchor must be copied from
  the CURRENT tail text exactly (the R212 entry ends with no blank
  line between phrases - read the tail before writing old4). Next:
  R214 - the war machine fire tables, siege attack values, and
  construction defensive values (pp.108-110, upload lines ~8400+,
  compilation cross-read required).
- R214 landed 2026-10-06: commit dc73011 (70d77a7..dc73011), census
  130, fourth consecutive first-attempt GREEN (176 asserts; pre-sim
  clean on first run). The war machine fire / siege attack /
  defensive values seam (DMG pp.108-110, the CONSTRUCTION & SIEGE
  tail) pinned: rules/siegefire.h CREATED - the six firing devices
  (ballista, heavy and light catapult, ram, sow, trebuchet): field
  of fire 45/15/30/-/-/10 degrees, ranges pinned in quarter-inch
  units x4 (ballista 1 to 128 = 1/4 to 32 inches, trebuchet 96 to
  192), S-M and L damage edges, rate of fire in hundredths
  (ballista 25 to 50 - the max crew doubles it; catapults and
  trebuchet 25; ram and sow 50), crew 2/4 through 10/20 (ram and
  sow), the below-minimum 50 percent rule with the ballista-only
  max-crew x2; hit determination (artillerist requirement, crew
  chief level picks the R111 matrix column, all targets AC 0,
  ballista targets AC 10 if exposed); the d20 modifier stack
  (stationary +3, move under 3" 0, 3-12" -3; man -2, horse 0,
  giant/small bldg +2, medium bldg +4, large bldg/castle wall +6;
  subsequent stationary shots +4; ship weather +1/0/-2/-4; direct
  fire +4); trajectory/cover (flat ballista blocked by
  intervening objects, arched fire passes over; unseen targets
  use the R157 grenade scatter, ballista unseen fire impossible;
  small catapult missiles 1 foot, trebuchet 2 feet - the R157
  cross-link); the 22 x 4 SIEGE ATTACK VALUES matrix pinned in
  QUARTER-POINT units x4 (0 = no effect; Bigby fist 4/0/2/1 = the
  print 1/-/1/2-/1/4* per round; horn of blasting 72/24/32/16 =
  18/6/8/4; dig earth 40 = 10; move earth 80 = 20; earthquake row
  pinned as separate dice arrays 5-60/5-30/5-60/5-30, not table
  cells; fireball and lightning bolt per caster level with the
  green-hides/wet 50 percent clause; the sow earth value only
  with a screw); the 26-row CONSTRUCTION DEFENSIVE VALUES
  min/max (building wood 8-16, drawbridge 10-15, gate 8-12,
  palisade 6-12, tower round 40-80, tower square 30-50) with the
  barbican/supports/rampart/curtain-wall footnotes; the 12-device
  MHP table (the ram catcher carries NO value in the print -
  pinned 0 with the note); and the additional attack forms
  (mining breach 10 feet or 10 points, sapping = sow damage but
  per TURN).
  GROUND TRUTH NOTE (the R209/R210 recovery rule, second use):
  the upload OCR scrambles the crew column and interleaves the
  fire columns of the WAR MACHINE FIRE table; the 1eonline
  compilation (seadow.htm) is the recovery source and MATCHES the
  upload cell values everywhere else - both sources agree on the
  attack matrix (horn 18/6/8/4) and the defensive tables. UNIT
  ENCODING LESSON: fractional print cells (1/4, 1/2 ranges and
  rates, quarter-point damage) pin cleanly as x4/x100 integer
  encodings with the convention named in the header comment - the
  audit then walks raw ints. Marker lesson repeated (and now
  standing): multi-line header comments need a SINGLE-LINE
  marker fragment for the new-file patch assert.
  Mutation test: sow MHP 12 -> 9 (bad 2 RED - both the walk and
  the spot pin), restored GREEN; census 130; braces 0/0; zero
  backslashes; fresh-tarball reproducibility clean. Next: R215 -
  the CONDUCTING THE GAME chapter (dice control, troublesome
  players, player integration, multiple characters, deity
  intervention percent tables, DMG pp.110-112, upload lines
  ~8560+, mostly prose - the pin material is the deity
  intervention modifiers and any percent bands).
- R215 landed 2026-10-06: commit e3ba862 (dc73011..e3ba862), census
  131, fifth consecutive first-attempt GREEN (26 asserts - a light
  round, as predicted for the prose-heavy chapter). The CONDUCTING
  THE GAME pins (DMG pp.110-112) landed: rules/conduct.h CREATED -
  the divine intervention procedure (the exemplary first-time asker
  10 percent creature-sent chance; the 00 roll: the deity-itself
  chance equals the character level; the six modifiers with EACH
  PREVIOUS INTERVENTION STACKING -5 as a COUNT, not a flag - the
  pre-sim caught the flag misread - and no floor on the total, the
  print sets none), the planes rule (Prime/Astral/Ethereal yes,
  Elemental DM option, Outer/Positive/Negative no, the
  elemental-gods block), the 7 secret-roll kinds, the untouchable
  system shock roll (never tampered, failure forever dead), the
  integration numbers (the d4+1 averaging die 2-5, works to an
  8th-level average, 4th+ above it, the neophyte full-cooperation
  level 3), the multiple characters rules (no prohibition, no
  free interchange), and the troublesome-player measures (the
  charisma point loss, the always-surprising ethereal mummy).
  Boot Hill / Gamma World conversions (pp.112-114) stay OUT by
  design. Compilation cross-check: the DDG divine intervention
  page matches the upload, adding only the asked-for-not-received
  note. NOTE ON THE LANDING: the user ran the full ritual a second
  time over the already-committed round (first splice run reported
  already 4, git nothing-to-commit) - verified against GitHub
  HEAD that e3ba862 was correct and the committed splice
  regenerates it exactly. LESSON: a first-run "(applied 0, already
  4)" plus a no-untracked-files hygiene block means the round is
  already landed - check the remote log before assuming a paste
  failure. Mutation test: proximate service +25 -> +20, bad 2 RED,
  restored GREEN; census 131; braces 0/0; zero backslashes;
  fresh-tarball reproducibility clean. Next: R216 - the ongoing
  campaign / campaign milieu seams (upload lines ~8720+, the
  likely pin material is the AD&D campaign tables after the Boot
  Hill / Gamma World OUT block, pp.112+).

R216 (landed 2026-10-06, commit 997556d, push e3ba862..997556d)
landed the magical research pins (DMG pp.114-119,
upload lines ~8900-9120). rules/magres.h (the
grenade.h pattern): the five-metal holy/unholy water
receptacle tables (copper/silver/electrum/gold/
platinum - capacity 6/10/18/32/50 vials, basin
ranges 130-180/1900-2400/8000-12000/19000-22000/
110000-200000 gp, fonts 200/500/1000/1500/2000 gp,
vials 2-5 gp, font build 4-10 weeks, once/week, 8 h
rest, one font per edifice, defilement remake 20-50
percent over 4-6 weeks, lycanthropy delay 1-4 turns
per vial, mixed metals interpolate capacity - the
print copper/silver 50/50 = 8 vials, rounded to
nearest); the spell research economics (200 gp per
level per week + 100-400 variable, no library x10,
min weeks level + 1, interruption day = week lost,
8 h/day, chance 10 + 10 per extra 2000 gp per level
capped 50 + INT/WIS + level - 2 x spell level,
impossible beyond MU 9th / cleric 7th, combo spells
sum + 1, library gathering 1 week per level); the
manufacture gates (cleric 11, wizard 12,
illusionist 11; books/artifacts/relics and the
dwarven/elven specials DM-only); and the potion
rules (MU 7th with alchemist, 11th optional at -50
percent, one at a time, lab 200-1000 gp + 10
percent monthly, cost and days = the XP award, each
100 gp or fraction one day, no-XP base 200 gp,
assassin poison 9th, delusion failure 5-20 percent).
The sr.htm page is a Dragon editorial and stays OUT
per the ground-truth rule; the upload is the sole
source at this seam. Gate notes: the pre-sim probe
expectations for the capped chance formula were
wrong (the helper correctly yields 61, not 51 - do
not pre-subtract the spell-level term); audit_eval
does NOT parse the compound-assign operator *= in
headers - write `base = base * k` (clamp-chain
form) instead. Mutation test: platinum font 2000
-> 1500, bad 2 RED, restored GREEN; audit_eval 24
asserts GREEN; census 132; braces/parens 0/0; zero
backslashes; fresh-tarball reproducibility clean.
Next: R217 - the scroll manufacture seam (upload
lines ~9100+, DMG pp.119+), the natural continuation
of the magic item manufacture material.

R217 (landed 2026-10-06, commit 68389e1, push
997556d..68389e1) landed the scroll manufacture
and fabrication pins (DMG pp.118-121, upload
lines ~9110-9280). rules/scrollfab.h (the
grenade.h pattern): the inscription gates
(cleric, druid, magic-user, illusionist at 7th
or higher, the spell one the inscriber can
employ; the protection scroll split - clerical
devils/possession/undead vs magic-user demons/
elementals/lycanthropes/magic/petrification,
curse scrolls by any spell user), the
materials (papyrus 2 gp and up +5 percent,
parchment 4 gp and up +/-0, vellum 8 gp and up
-5 percent; a fresh virgin quill per spell from
the 6 named strange creatures; giant squid
sepia / giant octopus ink base, a different ink
per spell), the preparation (one full day per
spell level, continuous - leaving breaks the
magic), the failure chance (20 + spell level -
character level + material modifier; the print
example: 14th level cleric, 7th spell,
parchment = 13; a percentile roll over the
chance is success, no floor), multiple spells
(one failure blocks further spells, 7 per
scroll max), transcription off a scroll (read
magic + the same time, the spell then
disappears; own scrolls need no read magic),
the fabrication of other items (enchant an
item - save clerical items; rest one day per
100 gp of XP value, 2000 xp = 20 days, no
adventuring or spell use; permanency for
permanent dweomers, not chargeable items), the
cleric/druid retreat (fortnight, sennight fast,
a day of purification, cumulative 1 percent
per day empowerment, 24 hours to charge), the
illusionist gates (scrolls 7th, one-shot and
charged 11th with major creation and the
16-hour instilling window, permanent dweomers
14th with alter reality and the unflawed
10000 gp gem), and the charmed or enslaved
maker rule (totally unable, attempts fruitless).
TWO NEW GATE LESSONS: (1) ENUM COLLISIONS -
audit_eval keeps ONE GLOBAL enum table across
all headers; the SM_ prefix for scroll
materials collided with R214 siegefire.h
(siegefire loads later and overwrote
SM_COUNT), producing a mysterious bad-1 in the
audit - grep rules/*.h for any new enum prefix
BEFORE landing it (scroll materials are now
SCM_). Debug aid: a patched audit_eval copy
that prints the failing condition inside the
assert branch catches these instantly. (2) the
marker must be a single-line fragment of the
header comment - multi-word markers that wrap
across the comment line (R217: the scroll
manufacture and fabrication pins) fail the
create-if-absent assert; use a prefix that
sits on one line (R217: the scroll manufacture
and). Mutation test: scroll max spells 7 -> 6,
bad 1 RED, restored GREEN; audit_eval 29
asserts GREEN; census 133; braces/parens 0/0;
zero backslashes; fresh-tarball reproducibility
clean. NOTE: /home/user was wiped again before
this round - /home/user/Adnd1/tools was
recreated; the splice template lives in the
r216/r217 canvases. Next: R218 - the USE OF
MAGIC ITEMS seam: command words, crystal balls
and scrying, drinking potions (d4+1 segments)
and applying oils, and the potion miscibility
tables (upload lines ~9320+, DMG pp.121+).

R218 (landed 2026-10-06, commit b83cec7,
push 68389e1..b83cec7) landed the use of
magic items and energy draining pins
(DMG pp.119-122, upload lines ~9200-9305).
rules/energydrain.h (the grenade.h pattern):
drinking potions (one segment to open and
consume, then a d4+1 = 2-5 segment delay),
applying oils (one segment to decant, 2-5
to spread), command words (a rod, staff or
wand usually needs one - possessor,
records, or the three informational spells:
contact other plane, legend lore, speak
with dead), crystal balls and scrying
(detectable; a spell-user target checks
the DETECTION OF INVISIBILITY table each
round; darkness stops viewing for the
spell duration, dispel magic for a full
day), the energy drain mechanics (hit
points of the level including the CON
bonus, all abilities, XP to the mid-point
of the next lower level; below 1st is a
0 level person never capable of gaining
again; a 0 level individual drained is
dead), the multiclass drain rules (always
the highest level, ties to the
greatest-XP class, a two-level drain
splits one level per class), and the
drained-all fate (an undead of the same
sort as the slayer, lesser undead at half
hit dice controlled by their master, the
lesser vampire at half the former
professional level - the print example: an
8th level thief returns as a 4th level
thief vampire; odd levels round down, a
judgment the print does not address - and
the full-hit-dice regain upon the slayer
destruction). SCOPE NOTE: the potion
miscibility table sits inside this chapter
but was already pinned by R165 and stays
OUT - check the gap report before choosing
a round scope. Gate: sim BAD 0 first try;
audit_eval 10 asserts GREEN; mutation test
lesser vampire level/2 -> level/2+1, bad 1
RED, restored GREEN; census 134;
braces/parens 0/0; zero backslashes;
fresh-tarball reproducibility clean. Next:
R219 - the TREASURE RANDOM DETERMINATION
tables (I. map or magic, II. the map table
with outdoor distance and containment
sub-tables, II.A monetary, II.B magic,
II.C combined hoard, upload lines ~9330+,
DMG pp.122-125).

R219 (landed 2026-10-06, commit 60672ef,
push b83cec7..60672ef) landed the treasure
random determination tables pins (DMG
pp.120-123, upload lines ~9330-9480).
SCOPE CORRECTION: the gap report claimed
treasure determination pp.120-125 was closed,
but R122 closed only the III.A-H item tables
and the lair types; the top-level
determination tables existed nowhere - the
lesson is to VERIFY what a claimed closure
actually covers before trusting a gap-report
[x] box (grep the code, not just the report).
rules/treasdet.h (the grenade.h pattern):
Table I map or magic (01-10 map, 11-00
magic), Table II the map table (01-05 false,
06-70 monetary, 71-90 magic, 91-00 combined;
a map never lists its treasure), the outdoor
destination sub-table (01-20 lair caves,
21-60 5-8 miles, 61-90 10-40, 91-00 50-500;
direction d8 with 1 north), the containment
sub-table (01-10 buried unguarded, 11-20
water, 21-70 lair, 71-80 ruins, 81-90 crypt,
91-00 town), Table II.A monetary (9 d20
rows: cp 2d4 x 10k = 20-80k, sp d4+1 x 10k =
20-50k, ep 5d6 x 1k = 5-30k, gp 3d6 x 1k =
3-18k, pp 5d4 x 100 = 500-2000, gems d10 x
10 = 10-100, jewelry 5d10 = 5-50 pieces;
row 18 twice, row 19 thrice discounting above
17; row 20 each item above = rows 1-17), and
Table II.B magic (1-5 item + 4 potions; 6-8
two items; 9-12 sword + armor/shield + misc
weapon; 13-14 three items no sword/potions;
15-18 6 potions + 6 scrolls; 19 four items w
ring + rod; 20 five items w rod + misc magic)
plus the design notes (theft chance DM-set,
low-value less guarded, magic table
deliberately weighted). GATE LESSONS:
audit_eval cannot parse else-chains in audit
blocks - write the d100 walk expectations as
NESTED TERNARIES inside a single
if-cond-++bad loop body (the run_loops
branch); and the debug-instrumented eval copy
(printing the failing condition) caught a
fallthrough bug where monetaryBandLo/Hi
returned the row index instead of the die
result for rows 6-8. Sim BAD 0 first try;
audit_eval 341 asserts GREEN (three full
d100 walks); mutation test monetaryBandHi
row-5 edge 17 -> 16, bad 1 RED, restored
GREEN; census 135; braces/parens 0/0; zero
backslashes; fresh-tarball reproducibility
clean. ENUM PREFIXES: MT_/MCON_ (MC_ collides
with rules/multiclass.h, TD_ with
dm/appendixa.h). Next: R220 - the II.C
combined hoard table (ten percentile rows
mixing constrained monetary and magic
sub-rolls with map leads, DMG p.123, upload
lines ~9440-9470).
- R220 landed 2026-10-06: commit f5c7381, census
  136, GREEN on the first Termux preflight (no
  b-round). The II.C combined hoard table
  pinned (rules/hoard.h, DMG p.123): ten
  percentile bands (1-20/21-40/41-55/56-65/
  66-75/76-80/81-85/86-90/91-96/97-100) via
  hoardBandCount/hoardBandOfRoll (clamped:
  0 and 999 -> 0/9); the on-hand monetary
  references hoardMonetaryRowCount/
  hoardMonetaryRow (per-band row counts
  1,1,2,3,2,4,1,1,0,0; rows index the R219
  monetary bands 0-8; padded arrays clamp i
  to count-1, so audit k-arrays duplicate the
  last valid row in padded columns); the
  on-hand magic references hoardMagicCount/
  hoardMagicRow (2-wide rows indexing the
  R219 magic bands 0-6, same clamp); bands
  6-7 are map-to-magic (m0/m7), bands 8-9
  map-to-monetary ([0,1]/[3,4]). Sim BAD 0;
  audit_eval 245 asserts GREEN; census 136;
  braces/parens 0/0; zero apostrophes/
  backslashes; mutation test band-5 row
  {1,2,3,5} -> {1,2,3,6} bad 1 RED, restored
  GREEN; fresh-tarball reproducibility
  clean. TWO GATE LESSONS: (1) audit_eval
  rejects MULTI-LINE TERNARY LADDERS in loop
  bodies (the 1-100 band walk failed as
  "unsupported loop body") - table-valued
  checks must use a FLAT k-array lookup
  (kBand[100]), not a nested ternary;
  (2) the first mutation probe hit a PADDED
  column the count-clamp never reads and
  stayed GREEN - mutation probes must target
  a LIVE column (verify the row count first).
  Padded-row audit convention: duplicate the
  last valid row so clamped reads are still
  pinned. Next: R221 - the III.A potions
  table prose rules (DMG pp.125-126, upload
  lines ~9480-9520: fighter-only marks,
  delusion/poison DM-misleading notes,
  control-type die rolls).
- R221 landed 2026-10-06: commit 351420f, census
  137, GREEN on the first Termux preflight (no
  b-round). The III.A potions prose pins
  (rules/potions.h, DMG pp.125-126): the
  three footnotes that frame the III.A
  POTIONS table, keyed to the 35 die bands
  of the engine III.A table (dm/treasure.cpp
  kPotions order) - the * control potions
  (Animal, Dragon, Giant, Giant Strength,
  Human, Undead Control: effectiveness on
  the type of creature controlled must be
  determined by die roll; consult the item
  explanation); the ** DM-misleading potions
  (Delusion, Poison: the DM must mislead
  the holder so as to convince him the
  potion is not harmful); the (F)
  fighter-only potions (Giant Strength,
  Heroism, Invulnerability, Super-Heroism).
  JUDGMENTS: Plant Control prints with NO
  star (unlike every other control potion)
  and is pinned control-less as printed;
  Giant Strength prints BOTH * and (F).
  SCOPE FINDING: the row VALUES and
  dice-band continuity were already pinned
  by the R122 line-diff audit (magicTablePin
  in the R145 battery), so this round pins
  only the footnote flags plus a re-pin of
  the band edges - grep the code first; the
  gap report's framing can overstate what
  is missing. Accessors: potionRowCount,
  potionRowLo/Hi (clamped), potionIsControl/
  Mislead/FighterOnly, potion*Count. Sim
  BAD 0 (a hand-typed F-array had an
  off-by-one at index 13 - build flag
  literals programmatically, not by hand);
  audit_eval 112 asserts GREEN first try;
  census 137; braces/parens 0/0; zero
  apostrophes/backslashes; mutation test
  potionIsControl row 0 (Animal Control)
  1 -> 0 RED, restored GREEN (note: the
  restore sed must target the ORIGINAL
  text, not echo the mutated line);
  fresh-tarball reproducibility clean.
  Next: R222 - the III.B scrolls footnotes
  and prose (DMG pp.126-127, upload lines
  ~9525+), or the first un-pinned III.A-H
  surrounding prose seam.
- R222 landed 2026-10-06: commit 820973e, census
  138, GREEN on the first Termux preflight (no
  b-round). The III.B scrolls prose pins
  (rules/scrollpins.h, DMG pp.126-127): the
  16 spell-scroll rows (dice bands 01-60,
  spell counts, level ranges, plus the
  printed ILLUSIONIST ALTERNATIVE RANGES -
  the or X-Y* halves on the 17-19, 25-27,
  33-35, 40-42, 47-49, 53-54 and 60 bands;
  JUDGMENT: pinned as data even though the
  engine roller reads only the main range,
  as the print gives no dice split for which
  half a found scroll uses; alt lo = main
  lo, alt hi lower on every alt row); the 8
  protection scroll rows with their
  table-printed x.p. values (2500, 2500,
  1500, 1000, 1500, 2000, 2000, 1500); the
  8-row curse sub-table (01-25 polymorph to
  equal-level attacking monster, 26-30
  liquid, 31-40 transported 200-1,200 miles
  random direction, 41-50 another planet/
  plane/continuum, 51-75 fatal disease in
  2-8 turns unless cured, 76-90 explosive
  runes, 91-99 nearby item de-magicked, 00
  random spell at 12th level of magic-use);
  the prose (100 x.p. per spell level
  awarded only to characters who can use the
  spell; 3x open-market sale for spell
  scrolls, 5x for protection; the DM must do
  his utmost to convince players a cursed
  scroll should be read - duplicity,
  coercion and threat; unread scrolls may
  fade in normal air; a curse takes effect
  immediately). The engine III.B structure
  (kSpellScrolls, the protection list, the
  cursed-scroll name) was already in
  dm/treasure.cpp and faithful - grep the
  engine first; only the never-pinned pieces
  became this round. ANCHOR LESSON (caught
  pre-delivery): the gap-report log anchor
  must survive LINE WRAPPING - the R221 entry
  wrapped the phrase across two lines, so
  the composite anchor matched zero
  occurrences; anchor on the unwrapped tail
  (surrounding prose seam. + blank +
  Categories:) and END each round's log with
  an unwrappable unique tail line. Sim BAD 0
  (one inverted property check fixed: the
  alt-range relation is lo-equal/hi-lower,
  not lo-lower); audit_eval 90 asserts GREEN;
  census 138; braces/parens 0/0; zero
  apostrophes/backslashes; mutation test
  protection row 3 xp 1000 -> 1100 RED,
  restored GREEN; fresh-tarball
  reproducibility clean. Next: R223 - the
  III.C rings footnotes (the (M)
  magic-user-only mark on Ring of Wizardry
  and the charge-limited double-dagger rows,
  DMG p.127, upload lines ~9600-9640), or
  the next un-pinned III.A-H surrounding
  prose seam.
- R223 landed 2026-10-06: commit ea600b2,
  census 139, GREEN on the first Termux
  preflight (no b-round). The III.C rings
  footnote pins (rules/rings.h, DMG p.127):
  the two footnotes that frame the III.C
  RINGS table, keyed to the 24 die bands of
  the engine III.C table (dm/treasure.cpp
  kRings order): the double-dagger
  charge-limited rings (Djinni Summoning,
  Human Influence, Mammal Control, Multiple
  Wishes, Telekinesis, Three Wishes,
  Wizardry - the most powerful magical
  abilities, possibly only a limited number
  of charges before depletion, at the DM
  option) and the (M) ring (Wizardry:
  magic-user use only). JUDGMENT: Ring of
  Wizardry prints BOTH the double-dagger
  and the (M); both flags set. Accessors:
  ringRowCount, ringRowLo/Hi, ringIsMuOnly,
  ringIsChargeLimited, ringMuOnlyCount,
  ringChargeLimitedCount (all clamped).
  Sim BAD 0 after correcting two
  clamp-flag probe expectations (the
  clamped reads land on Contrariness and
  X-Ray Vision, both unmarked - trust the
  helper formula, not hand-traced
  expectations); audit_eval 57 asserts
  GREEN; census 139; braces/parens 0/0;
  zero apostrophes/backslashes; mutation
  test Three Wishes charge flag 1 -> 0 RED,
  restored GREEN (LESSON: grep the ACTUAL
  generated array lines before writing a
  mutation - the first probe guessed the
  line layout from memory and matched
  nothing); fresh-tarball reproducibility
  clean. Next: R224 - the III.D rods,
  staves and wands footnotes (the
  point-value asterisk on the column
  headers, the per-row class marks C/M/F/T/
  any, and the charge notes, DMG pp.127-
  128, upload lines ~9625+), or the next
  un-pinned III.A-H surrounding prose seam.
- R224 landed 2026-10-06: commit 874f902,
  census 140, GREEN on the first Termux
  preflight (no b-round). The III.D
  rods/staves/wands footnote pins
  (rules/rodswands.h, DMG pp.127-128): the
  class-usable marks keyed to the 30 die
  bands of the engine III.D table
  (dm/treasure.cpp kRods order) - (C)
  cleric-only x10, (M) magic-user-only x14,
  (F) fighter-only x2 (Lordly Might,
  Smiting), (T) thief-only x1 (Beguiling),
  (any) x10 - JUDGMENT: the (any) flag and
  the four class flags are mutually
  exclusive per row, verified both ways in
  the audit; plus the column-header
  asterisk: the x.p. and g.p. values
  assume FULL charges are in the item
  (rswFullChargesAssumed). Accessors:
  rswRowCount, rswRowLo/Hi, rswUsableBy{C,
  M, F, T}, rswAnyClass (all clamped).
  Enum prefix RSW_ free (grepped). ANCHOR
  LESSONS (two bites, both caught
  pre-delivery): the patch-1 and patch-4
  MARKERS each wrapped across a line break
  of their target text - always verify the
  marker is a single-line fragment of the
  ACTUAL generated/comment text before the
  run. STABLE ANCHOR FOUND: the gap-report
  log anchor is now simply Categories:
  (line-unique, verified) - the line-wrap
  fragility of composite tail anchors is
  over; keep this anchor in future rounds.
  Sim BAD 0 first try; audit_eval 130
  asserts GREEN; census 140; braces/parens
  0/0; zero apostrophes/backslashes;
  mutation test Beguiling thief mark 1->0
  RED, restored GREEN; fresh-tarball
  reproducibility clean. Next: R225 - the
  III.E miscellaneous magic table 1 class
  marks and footnotes (DMG p.128, upload
  lines ~9665+), or the next un-pinned
  III.A-H surrounding prose seam.
- R225 landed 2026-10-06: commit 3119b0b,
  census 141, GREEN on the first Termux
  preflight (no b-round). The III.E table 1
  footnote pins (rules/miscmagic1.h, DMG
  p.128): the class marks and special rows
  keyed to the 33 die bands of the engine
  III.E.1 table (dm/treasure.cpp kMisc1
  order): the (C) marks (Book of Exalted
  Deeds, Book of Vile Darkness), the (M)
  marks (Bowl Commanding Water Elementals,
  Bowl of Watery Death, Brazier Commanding
  Fire Elementals, Brazier of Sleep Smoke
  - FOUR, not six; count from the table,
  not memory), the Artifact or Relic row
  (17, no values - see the Special table
  hereafter), the Bracers of Defense
  asterisk (60-79: per ARMOR CLASS POINT
  above 10 - AC 6 worth 2,000 x.p. /
  12,000 g.p., four points;
  m1BracersPerAcXp=500 / m1BracersPerAcGp=
  3000), and Bucknard Everfull Purse
  (99-00) as the tiered-values row (the
  R122-pinned 1500-4000 / 15000-40000
  ranges match the printed 1,500/2,500/
  4,000 tiers). Accessors: m1RowCount,
  m1RowLo/Hi, m1UsableByMagicUser/Cleric,
  m1IsArtifactRelicRow, m1IsPerAcPoint-
  Valued, m1IsTieredPurseRow, counts (all
  clamped). Enum prefix M1 grepped free.
  The Categories: gap-report anchor (the
  R224 stable anchor) worked first try -
  no anchor issues this round. Sim BAD 0
  after the count fix; audit_eval 75
  asserts GREEN; census 141; braces/
  parens 0/0; zero apostrophes/
  backslashes; mutation test Brazier
  Fire Elementals (M) mark 1->0 RED,
  restored GREEN; fresh-tarball
  reproducibility clean. Next: R226 -
  the III.E table 2 class marks and the
  Cloak of Protection and Crystal Ball
  asterisk/notes (DMG p.128, upload lines
  ~9724-9760), or the next un-pinned
  III.A-H surrounding prose seam.
- R226 landed 2026-10-06: commit 8b82e3e,
  census 142, GREEN on the first Termux
  preflight (no b-round). The III.E table 2
  footnote pins (rules/miscmagic2.h, DMG
  p.128): the class marks and asterisk rows
  keyed to the 30 die bands of the engine
  III.E.2 table (dm/treasure.cpp kMisc2
  order): the (C) mark (Candle of
  Invocation); the (M) marks (the two
  Censers, Crystal Ball, Crystal Hypnosis
  Ball, Eyes of Charming); the Cloak of
  Protection per-plus asterisk (33-55:
  1,000 x.p. / 10,000 g.p. PER PLUS - a +2
  cloak is 2,000/20,000); the Crystal Ball
  double asterisk (56-60: base 1,000 x.p. /
  5,000 g.p., add 100% for each additional
  feature - two extra features = 3,000);
  and the Eyes of Petrification triple
  star (00: ---*** both columns).
  Accessors: m2RowCount, m2RowLo/Hi,
  m2UsableByCleric/MagicUser,
  m2IsPerPlusValued, m2HasFeatureAsterisk,
  m2IsTripleStar, counts + the value
  constants (all clamped). Enum prefix M2
  grepped free. HYGIENE FLAG: the commit
  accidentally included a stray EMPTY file
  named main at the repo root (0 bytes,
  likely a shell redirect typo on Termux;
  5 files changed instead of 4) - cleanup
  pending: rm main + commit. LESSONS: (1)
  a raw percent in a splice comment broke
  the generator percent-format - reword, do
  not embed raw percent signs in template
  text; (2) the first mutation probe
  matched a NON-UNIQUE array line and
  silently modified nothing while printing
  mutated - the mutation gate now requires
  an md5 CHANGE and a RED result before a
  mutation counts; context-anchor mutations
  to the whole function block. Sim BAD 0
  first try; audit_eval 70 asserts GREEN;
  census 142; braces/parens 0/0; zero
  apostrophes/backslashes; mutation test
  Candle (C) mark 1->0 RED, restored
  GREEN; fresh-tarball reproducibility
  clean. Next: R227 - the III.E table 3
  footnotes (the Figurine of Wondrous
  Power per-hit-die asterisk and the Gaunt-
  lets class marks, DMG p.129, upload
  lines ~9765+), or the next un-pinned
  III.A-H surrounding prose seam.
- R227 + R227b landed 2026-10-06: commit
  0874ba8, census 143. THE WIRING ARC
  OPENED (user approved scoping+wire of
  the PHB gaps found: the data layers
  with zero engine callers). R227: the
  Wisdom Table I magical defense
  adjustment WIRED - spellSaveModWis
  existed with no caller; now
  rules/wisdom.h gains the evaluable gate
  seam wisMentalSaveAdj(wis, mentalForm)
  (the gated ladder, flat 0 on non-mental
  forms); spellSaveModWis delegates to
  it; the spelleffects TargetDesc gains
  saveWis (10 default - monsters read no
  adjustment, a character table);
  resolveSpell folds the gate into
  saveBonus per target (t now a copy) -
  the field the descriptor comment always
  reserved for the WIS magic adj - so
  trySave pays it with every other
  caller-side modifier, NO signature
  change anywhere; Actor::asTarget sets
  it for characters. Registry mental
  forms today: charm person, charm
  monster; fear/hypnosis/suggestion/
  phantasmal forces ride the flag when
  their rows arrive. The PHB gap report
  gained a NEW SECTION "The wiring arc
  (OPENED R227)" with open boxes: R228
  the druid+illusionist rosters join the
  SpellId registry (139 spells, dead
  data; largest, may split); subclass
  creation gates (no character can BE a
  subclass yet); specials hooks;
  multi/dual-class runtime. The stray
  root file main rm-ed and the deletion
  rode this commit (9 files changed,
  R226 hygiene flag CLOSED; note the
  push was 7682361..0874ba8 - the user
  had a cleanup commit between R226 and
  R227).
- R227 LESSON (the land caught it -
  preflight RED, ONE compile error, the
  full ~110-line CENSUS FAIL wall
  downstream of the missing binary, the
  R179b/R180b pattern): the zero-back-
  slash hygiene rule applies to the
  SPLICE FILE; the generated C++ must
  carry the REAL escape - built by
  PYTHON-SIDE concatenation (BS + "n")
  so the splice stays backslash-free
  while the OUTPUT line reads %d-back-
  slash-n. R227 wrote printf("...%d" +
  BS + "n", bad); literally - leaking
  the Python constant into the C++
  (undeclared identifier BS). RULE:
  grep the GENERATED audit block for
  "+ BS +" and for "chr(92)" before
  delivery - the sandbox has no C++
  compiler, so this bug class only
  surfaces at the Termux preflight; the
  grep is the cheap pre-delivery proxy.
  R227b (one patch, marker = the fixed
  line) replaced it with the proper
  python-side-built line; fresh-tree
  r227+r227b audit_eval R227 GREEN.
  Acid gate otherwise: pre-sim BAD 0;
  idempotent 7/0 then 0/7; 29 asserts
  verified bad 0; mutation Wis 15 cell
  ->2 RED with md5 change, restored
  GREEN; third virgin tarball repro
  clean; braces/parens 0/0 on all six
  touched files.
- R228+R228b landed 2026-10-06: commit
  dd44588 (push 0874ba8..dd44588),
  census 144, the druid roster joined
  the SpellId registry - 77 DR_ ids
  after CL_RESURRECTION, SPELL_DRUID in
  SpellClass, 77 kSpells rows (PHB
  spell-description header parameters:
  ct in SEGMENTS turn 60 / round 10 /
  Special 0, range tens Touch 0, dur
  base rounds Permanent/Special 0, aoe
  radius tens diameter-halved
  round-up, save Neg./half 4 none -1,
  target per AoE text), the eight-
  accessor clamped seam in
  rules/druidspells.h (grenade.h
  pattern), spellSlots(SPELL_DRUID,...)
  delegates to druidSpellSlots, R80
  battery walk extended to the druid
  rows vs the R182 roster cellwise,
  R228 audit_eval seam block (163
  asserts verified bad 0). Split
  held: R228 = druids only; R229 =
  illusionists (61). Acid: two-pass
  12/0 then 0/12; mutation kSave row 0
  4->-1 RED bad 1 md5 change, restore
  md5-identical GREEN; two virgin
  tarballs REPRO-CLEAN; hygiene
  braces/parens balanced, census 144.
  R228b (the land caught it, the
  R227 lesson GENERALIZED): the R129
  caster aging audit still pinned
  SPELL_COUNT 54 and MU 31/CL 23;
  the grown registry printed bad 2 and
  the battery HALTED at R129 - the
  R100-R113 blocks vanished and the
  R112c census FAIL wall was pure
  downstream. Five regtest.cpp
  patches (census 131, walk counts
  SPELL_DRUID as dr, pins MU 31 /
  CL 23 / DR 77). LESSON: any consumer
  that pins a REGISTRY CENSUS must
  ride the roster round - and the
  consumer grep must include
  regtest.cpp battery blocks, which
  audit_eval cannot cover when they
  use std::string/spells:: (outside
  its subset). Also caught pre-land
  by static cross-check: the cstr()
  apostrophe helper leaked Python
  concat ("+ Q +", then a stray quote)
  into the "Control Temperature, 10'
  Radius" C++ row - the R227 "+ BS +"
  bug class via a SECOND channel; the
  leak-grep now covers registry rows,
  not just audit blocks. Next: R229 -
  the illusionist roster joins the
  registry (61 spells, same seam
  shape).
- R229 landed 2026-10-06: commit
  1bb80e8 (via 14e8e63, see below),
  census 145, the illusionist roster
  joined the SpellId registry - 61
  IL_ ids after DR_WORST or the druid
  tail, SPELL_ILLUSIONIST in
  SpellClass, 61 kSpells rows
  (parameters from the PHB illusionist
  section; 13 JUDGMENTs pinned via
  q.v. MU/cleric prints; six Level-
  divergent blocks where the R183
  roster wins: Dispel Illusion 3,
  Fear 3, Hallucinatory Terrain 3,
  Illusionary Script 3, Improved
  Invisibility 4, Massmorph 4), the
  seven-accessor clamped seam in
  rules/illusionspells.h (array BEFORE
  clamps, same R228 shape), spellSlots
  (SPELL_ILLUSIONIST,...) delegates to
  illusionistSpellSlots, R80 battery
  walk extended (sclass check, il
  counter, cellwise walk vs the R183
  roster, printf IL - line now "192
  spells (MU 31, CL 23, DR 77, IL
  61)"), R129 census pin 192 with
  MU 31/CL 23/DR 77/IL 61, R229
  audit_eval block 131 asserts bad 0,
  gap-report R229 box flipped. Acid:
  two-pass 14/0 then 0/14; mutation
  kSaveCat row 0 -1->4 RED bad 1 md5
  change, restore md5-identical GREEN;
  three virgin trees + one fresh-tree
  rebuild all REPRO-CLEAN byte-
  identical; hygiene braces/parens
  0/0 on all five touched files,
  census 145, zero leaks, splice zero
  backslashes; SPELL_COUNT consumer
  sweep safe (loops/bounds only, no
  SpellClass switches). LESSONS:
  (a) the R228 "+ Q +" leak class
  REPRODUCED in runtime lit() for
  "Invisibility, 10' Radius" -
  apostrophes are legal inside C++
  double-quoted strings, never split
  them; (b) marker-based idempotence
  (R228 pattern) is MANDATORY -
  containment-based patch() broke
  4/14 patches; (c) read slot-table
  probes carefully, e.g.
  illusionistSpellSlots(5,2)=2 not 1;
  (d) TERMUX LAND TRAP: first land
  attempt committed ONLY the splice
  script (1 file, 627 insertions,
  "r229_spline.py" - filename typo) -
  the splice had never been applied to
  the tree; always check the commit
  stat for the PATCHED files
  (regtest.cpp, spells.h/cpp,
  illusionspells.h, gap report) and
  the filename, not just push success.
  Next arc (gap report "The wiring
  arc"): subclass creation gates (no
  character can BE a subclass yet),
  then specials hooks, multi/dual-
  class runtime.
- R230 landed 2026-10-06: commit
  1701912, census 146, the subclass
  creation gates WIRED - a character
  can now BE a paladin, ranger,
  druid, illusionist, assassin or
  monk at creation. The creation
  seam in rules/subclassgates.h
  (subclassRuntimeBase /
  ConClass / StartAgeBase /
  TwoDiceFirstLevel / HitDie /
  PlayerAllowed / LevelCapFor,
  appended before the namespace
  close); creation gains the
  CR_SUBCLASS stage (class ->
  subclass offer -> name; the
  offer lists the base class plus
  its registry subclasses),
  subclassEligible (base class
  qualifies + R180 ability
  minimums on the ADJUSTED scores
  + Race Table I),
  makeSubclassMember (the subclass
  hit die; ranger/monk TWO dice at
  level 1, each die with its con
  adjustment; the druid/illusionist
  slot fills; the illusionist L1
  book per the R33 convention; the
  monk quarterstaff/no-armor kit);
  Character.subclass (int, -1 =
  plain) with the optional
  save/load "subclass" line
  (v1-compatible); restoreSlots
  branches the druid/illusionist
  to their R228/R229 tables;
  memberClassName for the roster
  and join-log display; the R230
  battery audit (90 asserts,
  verified bad 0); the gap-report
  box flip. Acid: two-pass 18/0
  then 0/18; mutation kDie 10->12
  RED bad 2, restore md5-identical
  GREEN; t1==t2==t3 REPRO-CLEAN;
  hygiene 0/0 on all 7 touched
  files; seam Table I/II copies
  cross-checked cellwise vs the
  R180 matrices. LESSONS: (a)
  audit_eval cannot parse ": int"
  underlying-type enums (its enum
  regex is enum Name {...} only) -
  a new seam that must be
  evaluable uses PLAIN INTS and
  private flat copies of the
  matrices (documented in the seam
  header), never SUB_* / RACE_*
  enum constants; (b) audit blocks
  with an if-assert inside a BRACED
  for body are UNVERIFIED - one
  for-walk per if-assert, no
  nested brace blocks; (c) a
  marker that is a PREFIX of a
  later patch's marker content
  (memberClassName(c), before
  memberClassName(c), c.startAge))
  makes the later patch count
  "already" on pass 1 - order the
  patches so the longer/anchored
  marker comes first; (d) clamp
  probes must account for the
  clamp TARGET row (the clamped
  subclassPlayerAllowed(99,99)
  reads the MONK row: human-only,
  expect 0, not 1). JUDGMENTs:
  the monk rides CLASS_FIGHTER at
  runtime and on the fighter offer
  list (con class CLASS_THIEF -
  not the fighter CON bonus
  group); alignment gates stay
  data-only (no alignment concept
  yet); the bard (Appendix II)
  stays uncreatable. The commit
  stat showed all 8 files (the
  R229 land trap did not recur).
  Next arc items: leveling under
  the subclass XP tables (the
  engine levels by base-class
  xpForLevel), then the specials
  hooks (lay on hands, giant-class
  bonus, monk unarmed ladder,
  backstab multipliers), then
  multi/dual-class runtime.
- R231 landed 2026-10-06: commit
  1ca4fd2, census 147, the subclass
  leveling wire - registry subclass
  members now level on their printed
  XP ladders. The leveling seam in
  rules/subclassgates.h
  (subclassXpToAttain - all 81
  printed XP rows + the adders,
  private flat copies per the R230
  EVAL NOTE; subclassFixedHpLevel -
  the PRINT pins, druid fixed-hp
  from the 9th; subclassHpBeyondFixed;
  subclassLevelStop - the R179
  levelCap pins, the name-cap analog,
  druid 14 the hierarchy ceiling;
  subclassLevelCapTotal - the stop
  lowered by a positive Table II cap,
  footnote-8 included); gainXp queues
  on the registry ladder and applies
  the printed +10% subclass XP bonus
  when the R180 rule is earned
  (illusionist/assassin/monk none);
  trainNext promotes on the registry
  ladder (the subclass hit die + con
  class; fixed hp past the fixed-hp
  level; the illusionist studies from
  the R229 roster); the energy-drain
  trick resets to the registry level
  start; the R231 battery audit (120
  asserts verified bad 0); the
  gap-report box flip. Acid: 11/0
  then 0/11; mutation paladin row-2
  2750->2751 RED bad 2, restore
  md5-identical GREEN; XP rows
  cross-checked cellwise vs the R179
  registry; hygiene 0/0 on all touched
  files (a stray COMMENT paren was
  caught by the delta check and
  fixed); t1==t2==t3 REPRO-CLEAN.
  LESSON: the druid pins SPLIT - the
  registry levelCap 14 (the hierarchy
  ceiling - leveling runs there) is
  NOT the fixed-hp level 9 (the
  print pin - hp goes fixed there);
  a leveling wire needs BOTH pins
  (subclassLevelStop vs
  subclassFixedHpLevel); read the
  R179 registry row carefully before
  reusing its fields. JUDGMENTs: the
  +10% bonus amount (the R180 layer
  pins rules, not amounts); the
  prime-requisite % keeps the
  base-class ladder (the subclass
  primes match their base primes);
  the henchman stays base-class.
  Next arc items: the per-subclass
  specials hooks (lay on hands,
  giant-class bonus, the monk unarmed
  ladder, backstab multipliers),
  then multi/dual-class runtime.
- R232 landed 2026-10-06: commit
  f5ef2aa (1ca4fd2..f5ef2aa, 14
  files, THREE b-rounds), census 148,
  the per-subclass specials hooks
  WIRED. ai::Actor carries the
  registry subclass (toActor copies
  it; the -1 default); the monk reads
  the R181 open-hand ladder -
  attacksPerRound heavy-round of the
  printed cycle, Monks Table II damage
  on BOTH bare-fist and armed paths,
  hitAdjustment flat 0 (the R181 pin,
  strength never modifies the monk
  to-hit); the thief group backstabs a
  surprised foe in round one (+4 die,
  x2..x5 multiplier; the surprise
  segment is the from-behind reading -
  JUDGMENT, no facing in the engine);
  the ranger +1hp/level vs the 11
  R184 giant-class names
  (giantClassFamilyMatch - lowercase
  exact or trailing-word, word-
  boundary guarded); the paladin lays
  on hands ([F] town key, 2hp/level,
  once per career day, most-wounded
  member, layhands v1-compatible save
  line). The monk stun/kill,
  quivering palm, and the surprise/
  turn-undead numbers stay data - a
  combat-form command round owns
  them. Audit: R232 battery block is
  an ENGINE audit (Character ctor -
  the R174 class), UNVERIFIED in
  audit_eval by design; the C++
  battery is the gate (proved bad 0
  on Termux). Acid: pins cross-check
  simmed vs the parsed rules headers;
  mutation monkLadderRow(13) dmgHi
  17->18 RED bad 1, restore
  md5-identical; hygiene 0/0; t1==t2
  ==t3 REPRO-CLEAN.
- R232 LESSON SET (three land-caught
  b-rounds, all one failure family -
  the sandbox cannot compile C++):
  (b) the splice INVENTED an API -
  a.encounterDice() does not exist,
  the dice live on the Encounter
  (m_dice, in scope in resolveMelee);
  the helper was dropped and the
  ladder span rolled on m_dice at
  both call sites. EVERY method a
  splice calls must be grepped
  against the base headers before
  delivery - eyeball is not proof.
  (c) the R232 audit was the FIRST
  regtest block to call an
  ai::Actor member - the battery
  build line in tools/preflight.sh
  never linked ai/actor.cpp; an
  engine-audit round must verify the
  BATTERY BUILD LINE links every TU
  the audit touches, not just the
  census count. (d) new TUs drag
  their TRANSITIVE closure: actor.cpp
  -> spelleffects/spelleffects.cpp
  (a whole top-level directory the
  battery line predates; the game
  binary always linked it). The
  Termux PROBE RUN found the whole
  closure in one shot: g++ with the
  per-directory globs (minus _test
  files, minus rules_test.cpp which
  has its own main; $TMPDIR not /tmp -
  Termux /tmp is not writable) then
  run the binary and grep the audit
  lines - now a standard acid-battery
  step for any round that extends
  the battery line. Also: the
  gap-patch marker must be a line
  that LITERALLY appears in the
  replaced text (the trailing comma
  in the marker string killed the
  first 16/17 run - the pre-assert
  caught it, the tree was partially
  patched, fresh-tree rerun landed
  17/0).
  Next arc item: the multi-class and
  dual-class engine (R185 data, no
  runtime).
- R233 landed 2026-10-06: commit d78951e, census 150,
  GREEN on the first preflight (no b-round), the
  MULTI-CLASS ENGINE WIRED - the R185 combos are
  playable. 23 patches over 6 files + the splice:
  rules/multiclass.h (the MC constants became a
  NAMED enum McBits so audit_eval can read them - a
  static const int is invisible to the enum scanner;
  the R233 seam: multiClassCount/multiClassBitAt/
  multiClassBaseOfBit/multiClassSubOfBit - pure
  modulo-ladder expressions, no bitwise ops),
  game/party.h (multiMask field; toActor primary =
  the FIRST set bit; gainXp prime-average PHB p.20
  + no single-class bonus; trainNext/queue primary
  ladder; promotion rolls every UNSTALLED class die,
  quotient by class count - multiclassHpQuotient,
  a stalled class contributes no die), game/
  appstate.h (CR_MULTI stage, multiMask, multiOffer
  Count/At, multiEligible, makeMultiMember), adnd1.cpp
  ([M] keydown + CR_MULTI panel), game/state_core.cpp
  (the v1-compatible `multi %d` save line + load
  branch, range-gated 0..127), regtest.cpp (R233a
  seam audit EVALUABLE - verified bad 0 over 36
  asserts - plus the R233 engine audit, UNVERIFIED
  by design, battery-proved bad 0). The dual-class
  engine stays the next arc box (gap report flipped,
  census 150).
- R233 LESSON SET (four acid catches pre-delivery,
  all in the sandbox):
  (a) the multiClassAllowed body is a braceless
  for+if the audit_eval parser cannot walk - EVAL
  ERROR; the membership asserts were dropped (the
  table is fully pinned by combo count/row probes
  instead). Check every rules/*.h function an
  evaluable audit reaches stays in the evaluable
  subset - not just the new seam.
  (b) the seam itself had a REAL BUG audit_eval
  caught: multiClassBaseOfBit missed the assassin
  branch (bit 64 -> thief base 3) - the sim alone
  had blessed it because the sim mirrored the same
  intent; audit_eval executes the ACTUAL generated
  body. Also caught: the save-load patch ended
  without its closing brace - `c.multiMask = mm;
  else if` - a syntax error a raw brace-DELTA check
  (the old +2/+1 delta tolerance) would have waved
  through; the whole-file brace-DEPTH scan is the
  reliable hygiene gate, raw deltas are not.
  (c) the mutation test first PASSED (mutation not
  caught): every probe mask carried bit0, so a
  multiClassCount bit1 mutation was invisible. Add
  probe masks WITHOUT bit0 (6, 48, 36) - then the
  mutation goes RED bad 3, restored byte-identical.
  Design the mutation test around the actual probe
  coverage, and widen the probes until it bites.
  (d) the splice's own printed commit line said
  census 149 - the true census is 150 (148 + the two
  new audit blocks R233a + R233). Pre-assert the
  census arithmetic inside the splice (gap-patch
  Census count check) AND grep the splice's printed
  strings for stale numbers before delivery.
  Next arc item: the dual-class engine (the human
  class-change runtime).
- R234 landed 2026-10-07: commit c25cd9e, census 152,
  GREEN on the first preflight (no b-round), THE DUAL-
  CLASS ENGINE WIRED - the human class change is
  playable; the subclass/multi/dual arc is now FULLY
  CLOSED. 15 patches over 8 files + the splice:
  rules/multiclass.h (the R234 evaluable seam:
  dualClassNewDieDue - the new die begins when the new
  level EXCEEDS the old; dualClassXpNegated - the
  resort stance negates XP until exceeded; the R185
  DUAL_CLASS_* constants became enum DualClassMins -
  the R233 McBits convention), game/party.h
  (dualOldClass/dualOldLevel/oldClassUse fields;
  canSwitchProfession - human only, 15+ old prime and
  17+ new prime on the ADJUSTED scores, one switch
  only, plain single-classed; switchProfession - the
  hit dice and hp RETAINED, 1st-level restart, the
  new-profession kit, caster slots + MU book restart,
  exceptional-strength re-roll on a fighter switch;
  gainXp negation; trainNext dual die - no die at or
  below the old level), town runtime (the [K] guild
  key - deterministic first-qualifying pick; the [U]
  resort toggle; the F6>M1 roster line), state_core
  (v1-compatible dual/olduse save lines, range-gated),
  regtest (R234a seam audit EVALUABLE verified bad 0
  over 15 asserts; R234 engine audit battery-proved
  bad 0), gap box flipped (Census 152). Simplifications
  recorded: the resort stance is a standing town
  toggle (no per-adventure XP boundary), the switch
  targets base classes only (printed paladin/ranger
  combos stay future work).
- R234 LESSON (one): the splice PRE-CHECKS now accept
  the pristine OR the fully-patched tree (gap census
  150-or-152, box open-or-flipped, regtest census
  150-or-152) - the ritual's second run prints
  "already 15" instead of aborting on the pre-check;
  a wrong base still fails. Splice-pre-checks should
  be written two-state from the start.
  Next arc: the subclass/multi/dual arc is complete -
  the standing scope (Dragon/UA classes: cavalier,
  barbarian, thief-acrobat) is the open frontier.
- TABLEOCR PIPELINE (2026-10-07, ~/tableocr on Termux): the
  direct-from-scan extraction project replacing the unreliable
  book uploads (the R182 lesson: upload OCR headers are
  untrustworthy). tools/reextract.py: pdftoppm renders each
  page (300dpi gray, temp dir) -> tesseract TSV (word bboxes)
  -> reconstruct() clusters lines by y and splits table columns
  by x-gap (adaptive default: 5 x mean char width; --col-gap
  overrides). PAGE-IMAGE BUG FIXED: the temp glob matched the
  WRONG page image (one page's text emitted as another); the
  glob now filters to the exact page number - distinct per-page
  char counts are the regression signal.
  OFFSETS PINNED: PHB print->PDF +4 (Preface verified);
  DMG print->PDF +4 (Preface verified, p.4; print 108-116 =
  PDF 112-120 - the war-machine/BOOT HILL victims).
  WINNING OCR RECIPE (locked via A/B on the fire-table page,
  DMG PDF 114): --oem 0 (LEGACY engine beats LSTM decisively
  on 1978 phototypeset typography - LSTM merged 6-7->67,
  2-3->23 and dropped minus signs -1/-2; legacy reads both
  correctly and even 1/2 for the half glyph) + --oem 0
  whitelist "A-Za-z0-9 -*/.[half]%(),:'&". Both flags are
  patched into reextract.py (targs call site ~line 260).
  ACCEPTANCE: full victim range DMG PDF 112-120 ran clean -
  fire table (First Shot Determination, both tables) fully
  paired and sign-correct, the named interlacing victim class
  DEAD at the OCR level. KNOWN LIMIT (reconstruct v2 work,
  NOT OCR): two side-by-side tables sharing baseline rows
  (GAMMA WORLD armor conversions, PDF 115) merge into paired
  but interleaved rows - readable, values intact. Residual
  normalizable noise: O->0 and A->4 in digit cells, j<->u
  swaps (Adiustment, shieId) - postpass targets. col-gap 15
  proved WRONG (shatters header words); fixed small gaps fight
  the adaptive default - keep the adaptive default unless a
  specific page proves otherwise.
- R235 + R235b landed 2026-10-07: commit 45ee74a
  (one commit - the R179b/R234 precedent), census
  154, THE BARD ENGINE WIRED - the Appendix II
  career (fighter 5th-7th -> thief 5th-9th -> the
  druidical studies) is playable on the R234
  dual-class machinery. 21 patches over 8 files +
  the splice: rules/bard.h (the R235 career seam
  bardCareerGate - both printed windows; the BARD_*
  constants became enum BardPins - the McBits
  convention), game/party.h (the bard field;
  canBeginBardStudies - a fighter-turned-thief of
  the R234 career, human or half-elf, STR WIS DEX
  CHA 15+, INT 12, CON 10; beginBardStudies - hit
  dice/hp RETAINED, 1st-level restart, the Table
  III kit, the Table I level-1 druid slots; the
  Table I XP queue in gainXp, bard XP only, capped
  23rd; the promotion die - the Table I d6 column
  with the druidical con adjustment), the guild
  [A] town key, the B roster line, the druid-roster
  castable list, restoreSlots on the Table I slot
  columns, the v1-compatible bard save line, the
  R235a seam audit (EVALUABLE, verified bad 0 over
  45 asserts) + the R235 engine audit
  (battery-proved bad 0). Gap box flipped
  (Census 154). Simplifications recorded: the
  alignment pin and the poetics/colleges/henchmen/
  musical-item layers stay data-only (the R186
  pins), no scimitar in the engine (the kit rides
  the long sword), the druid EFFECTS resolve on
  the generic combat layer.
- R235b LESSON SET (the Termux battery caught the
  bug; a b-round was needed - the first RED
  preflight since R232):
  (a) the R235 gainXp bard branch queued the
  promotion but never AWARDED the XP - the
  continue skipped the c.xp += amount line, so a
  bard earned NOTHING; bad 4 was the exact
  cascade (xp 0 -> stale queue entry -> no
  promotion -> no die), and the ~90 CENSUS FAILs
  were all downstream of the audit early-return.
  LESSON: an engine audit that traces the award
  path must walk award -> queue -> promote in the
  ACTUAL C++ execution, not a Python mirror; the
  sim mirror blessed the queue while the award
  line was missing. When an inserted early-return
  block sits INSIDE a loop that awards below it,
  trace where the award happens for the new class.
  (b) two splice-pre-check lessons: a pre-check
  count must use a marker UNIQUE to the target
  block (if (c.bard) { appears 3x in party.h -
  int bcap = 23; is the unique one), and a
  "FAIL: already applied" pre-check CONTRADICTS
  the patch-loop idempotence - never add it; the
  new-text idempotence signal is the whole story.
  (c) the acid-side R235a slot probes were MY
  wrong expectations (levels 14/15) - the R186
  header table was the truth; audit_eval caught
  them pre-delivery. When probing a PINNED table,
  re-read the pinned cells from the header, never
  from memory of the print.
  Next arc: the bard runtime is playable; the
  UA/Dragon classes (cavalier, barbarian,
  thief-acrobat) stay queued until the Unearthed
  Arcana PDF arrives.
- R236 landed 2026-10-07: commit 67049fc, census
  155, the bard specials WIRED (all PHB classes
  now playable AND their Appendix II specials
  live). 10 patches over 7 files: rules/bard.h
  (the poetics constants became enum BardPoetics +
  the pure-expression helpers bardPoeticsHitBonus
  (BARD_HIT_BONUS, +1) / bardPoeticsRoundsRequired
  (2) / bardPoeticsActive(round, bardAlive) -
  nested-ternary gate round >= 1 + 2, so the
  ferocity holds from ROUND 3 on with m_round
  starting 0), ai/actor.cpp (the resolveMelee
  poetics ferocity: a living bard in m_party
  grants the party +1 melee to-hit after the
  backstab block; melee only, the R232 precedent;
  morale void - party is MORALE_FANATIC; the turn
  window simplified to while the bard lives),
  game/state_town.cpp (townBardicLore - the [X]
  town key: the finest living bard studies the
  front unidentified find on a Table II legend
  lore roll; miss = item STAYS queued, retryable,
  no cost; hit = the useIdentifyScroll taker
  logic verbatim, else sold 200 gp; plus the
  studies-begin message names the college via
  bardCollege(1)), game/appstate.h (decl),
  adnd1.cpp (the [X] key - verified unbound in
  the town switch; GUILD help line + [X] lore),
  regtest.cpp (ONE evaluable R236 audit, verified
  bad 0 over 28 asserts: poetics seam boundaries,
  lore cells incl. the as-printed 55@14, charm,
  languages, hit dice), gap box flipped
  (Census 155). Stays data-only: henchmen ladder,
  musical items, song negation (no
  bard-henchmen concept, no musical items in the
  registry, no harpies/shriekers).
  R236 acid catches (both pre-delivery, both MY
  probe bugs): (a) charm@14 is 60 not 63 - when
  probing a pinned table re-read the header cells
  (the R235b (c) lesson again - it is now
  second-nature); (b) the poetics boundary - with
  m_round 0-based the gate round >= 1 + 2 lights
  at round 3, so simulate the round arithmetic
  against the engine convention, not the print
  prose. Also caught: the seam helper referenced
  BARD_POETIC_HIT_BONUS while the enum member is
  BARD_HIT_BONUS (kept for the R186 references) -
  audit_eval flagged the unknown identifier; the
  R233 convention holds: enum member names must
  match the helper bodies character-for-character.
  Ritual note: the paste step snuck back into a
  delivered ritual AGAIN (the nano line, fourth
  bite) - the ritual starts at the md5 gate,
  and the user pastes the canvas themselves.
  Next: the PHB special arc is complete; the
  UA/Dragon classes (cavalier, barbarian,
  thief-acrobat) stay queued until the Unearthed
  Arcana PDF arrives in uploads.
- R237 landed 2026-10-07: commit 0cc0d9d,
  census 156, GREEN on the first Termux
  preflight (no b-round). The DMG magic-item
  tables arc RESUMED (the queue held since
  R226 - R227 had pivoted to the Wisdom wire):
  the III.E table 3 footnote pins (DMG p.129,
  upload lines ~9765-9825). rules/miscmagic3.h
  CREATED (the grenade.h pattern), keyed to
  the 33 die bands of the engine III.E.3
  table (kMisc3 order): the (C, F, T) marks
  (Gauntlets of Ogre Power 21-22, Gauntlets of
  Swimming and Climbing 23-25, Girdle of
  Femininity/Masculinity 28, Girdle of Giant
  Strength 29); the (C, F) Horn of the Tritons
  50-53; the (C) Incenses 66-70 and 71; the (F)
  Javelins 81-85 and 86-90; NO (M) rows ride
  this table. The ASTERISK LADDER (a single
  m3StarCount walk array instead of R226-style
  per-row booleans): Figurine 1 star (100 x.p. /
  1,000 g.p. PER HIT DIE of the figurine),
  Horn of Valhalla 2 stars (double bronze,
  triple iron), Ioun Stones 3 stars (per
  stone), Instrument of the Bards 4 stars
  (1,000 / 5,000 per level of instrument for
  bards - THE FOURTH FOOTNOTE THE BOOK UPLOAD
  DROPS, restored from the 1eonline.info
  compilation page 3e3.htm, the R175
  precedent); plus the Jewel of Flawlessness
  92 per-facet row (no x.p., 1,000 g.p. per
  facet). Accessors m3RowCount/RowLo/RowHi/
  UsableByCleric/Fighter/Thief/StarCount/
  IsPerFacetValued + counts 7/7/4 + the value
  constants. R237 audit verified bad 0 over
  80 asserts (walks + mark probes + the
  arithmetic probes: 4-hit-die figurine 400/
  4,000, bronze horn 2,000/30,000, iron horn
  3,000/45,000, Doss instrument 3,000/15,000,
  facet x3 3,000). Created-file md5
  8ef501698a610675d16fd9c2a2b6e466
  (byte-identical across three fresh trees -
  the real gate; splice md5 advisory). Acid:
  two-pass 4/0 then 0/4; mutation walk-cell
  RED bad 2 + value-constant RED bad 1, both
  restored md5-identical GREEN; brace/paren
  0/0; all 7 arrays 33 cells comma-terminated;
  INDEPENDENT ground-truth parse of the upload
  table re-derived all 33 bands and marks
  before delivery; audit_eval GREEN first try.
  LESSON (my own R235b sin re-committed and
  caught by the two-pass): the splice briefly
  carried a "FAIL: already rides the tree"
  pre-check on the R237 audit line - it
  CONTRADICTS patch-loop idempotence (the
  exact R235b (b) rule); the only pre-checks
  are the two-state census gates.
  Next: R238 - the III.E table 4 footnotes
  (the Libram/Manual class marks, the Necklace
  of Missiles per-hit-die asterisk, the
  Medallion dual values, the Pearl of Power
  per-spell-level star, DMG p.129-130, upload
  lines ~9827+), or the next un-pinned III.A-H
  surrounding prose seam.
- R238 landed 2026-10-07: commit 87e7218,
  census 157, GREEN on the first Termux
  preflight (no b-round). The III.E table 4
  footnote pins (DMG p.129-130, upload lines
  ~9817-9898). rules/miscmagic4.h CREATED
  (the grenade.h pattern), keyed to the 36
  die bands of the engine III.E.4 table
  (kMisc4 order): the (M) marks (the three
  Librams, Manual of Golems with C, Mirror of
  Life Trapping, Pearl of Power - count 6);
  the (C) marks (Manual of Golems with M,
  Necklace of Prayer Beads, Pearl of Wisdom,
  the two Nets with F and T, the three
  Phylacteries - count 8); the (F) marks
  (Manual of Puissant Skill at Arms, Mattock
  of the Titans, the Nets - count 4); the
  (T) marks (Manual of Stealthy Pilfering,
  the Nets - count 3). The asterisk ladder
  (m4StarCount, the R237 pattern):
  Necklace of Missiles 1 star (50/200 PER HIT
  DIE of each missile), Prayer Beads 2 stars
  (PER SPECIAL BEAD 500/3,000), Marvelous
  Pigments 3 stars (PER POT 500/3,000), Pearl
  of Power 4 stars (PER LEVEL OF SPELL
  200/2,000) - all four footnotes ride the
  upload this time, no restoration needed.
  NEW THIS ROUND: the DUAL-VALUE walk flag
  m4IsDualValued (the R225 tiered-purse
  analog) - the Medallion of ESP 13-15
  (1,000/3,000 x.p., 10,000/30,000 g.p.)
  and the Feather Token 86-00 (500/1,000
  x.p., 2,000/7,000 g.p.), with the 8 lo/hi
  value constants. R238 audit verified bad 0
  over 95 asserts (8 walk arrays + mark
  probes + arithmetic probes: 5-hit-die
  missile 250/1,000, two beads 1,000/6,000,
  two pots 1,000/6,000, 3rd-level spell
  pearl 600/6,000 + the dual-row constants
  and clamps). Created-file md5
  6683729535996df221309f6d28629b75
  (byte-identical across three fresh trees);
  splice md5 advisory. Acid: two-pass 4/0
  then 0/4; walk-cell mutation RED bad 2 +
  Pearl constant RED bad 1, restored
  byte-identical GREEN; brace/paren 0/0; all
  8 arrays 36 cells comma-terminated;
  audit_eval GREEN first try (10 verified
  blocks total).
  GROUND-TRUTH PARSER LESSONS (three
  artifacts, all parser bugs NOT pin bugs):
  (a) the band regex reads 86-00 as hi=0 -
  00 pins as 100 (the R122 convention),
  patch the parser; (b) an empty-band
  continuation row (| empty | Attention (C)
  | --- | 2,000 |) is killed by the
  empty-set subset filter - wrapped names
  carry their class marks on the SECOND
  line (the Phylactery of Monstrous
  Attention (C) was the one); (c) dual-value
  rows print both fractions merged into the
  x.p. cell (1,000/3,000 10,000/30,000 in
  ONE cell) - detect dual by the slash in
  EITHER cell. Cross-check vs the
  1eonline.info compilation (3e4.htm): it
  DROPS the Manual of Golems (C, M) and
  Prayer Beads (C) marks the upload carries -
  the upload is the book-text source (the
  R225/R226 convention); the compilation
  stays useful for the star footnotes (its
  superscripts render as digits: 501 =
  50-star).
  Next: R239 - the III.E table 5 footnotes
  (the Robe and Rug (M) marks, the Saw and
  Spade (F) marks, the Trident class marks,
  the Talisman (C)/(M) marks, DMG p.130,
  upload lines ~9898+), or the next un-pinned
  III.A-H surrounding prose seam.
- R239 landed 2026-10-07: commit db4b81b,
  census 158, the III.E table 5 footnote
  pins (DMG p.130, upload lines ~9898-9915,
  the LAST of the III.E sub-tables).
  rules/miscmagic5.h CREATED (the
  grenade.h pattern), keyed to the 35 die
  bands of the engine III.E.5 table
  (kMisc5 order): (M) count 8 (Robes of
  Archmagi/Eyes/Powerlessness/Scintillating
  with C/Useful Items, Rug of Welcome,
  Sphere of Annihilation, Talisman of the
  Sphere); (C) count 5 (Scintillating
  with M, Talismans of Pure Good/Ultimate
  Evil, Tridents of Fish Command/Warning
  with F and T); (F) count 5 (Saw of
  Mighty Cutting, Spade of Colossal
  Excavation, Trident of Submission, the
  two command/warning Tridents); (T) count
  2 (the two shared Tridents). VERIFIED:
  table 5 has NO asterisk rows, NO
  dual-value rows, NO footnotes - the
  print runs straight from 91-00 Wings of
  Flying to the Special artifacts table,
  so this was a pure class-marks round
  (the R224 rods shape; 11 accessors: 6
  walk arrays + 4 count constants + the
  namespace, NO star/dual helpers).
  R239 audit verified bad 0 over 84
  asserts. Created-file md5
  a1c818256344e29a453b6594295f75e5
  (byte-identical across three fresh
  trees); splice md5 advisory. Acid:
  two-pass 4/0 then 0/4; walk-cell
  mutation RED bad 2 + m5MagicUserCount
  8->7 RED bad 1, restored byte-identical
  GREEN; brace/paren 0/0; all 6 arrays 35
  cells comma-terminated; audit_eval GREEN
  (11 verified blocks total); ground
  truth: independent parse of the upload
  LEFT column only (right column is III.F
  armor in the two-column layout), with
  the R238 parser lessons applied - all
  match, stars/duals all zero confirmed.
  TWO LESSONS THIS ROUND:
  (a) the post-condition accessor count
  said 10 but there are 11 (m5MagicUser-
  Count miscounted) - count the accessors
  by list, not by eyeball; the failed-run
  state stayed idempotent (re-run already
  4/4) so the fix was cheap.
  (b) TERMUX GIT-STATE REPLAY: the user
  re-ran the whole ritual AFTER the land
  was already committed+pushed (db4b81b on
  HEAD and origin/main). Symptom set:
  first splice run reports "already 4"
  instead of "applied 4", preflight RED
  at hygiene with "untracked file(s)
  present but NO tracked file modified" -
  that RED means the patches are ALREADY in
  HEAD (or staged), NOT a broken land.
  Diagnosis: git log --oneline -3 first;
  if HEAD carries the RNNN message and
  origin matches, the land is done - just
  clean strays and push if needed. Stray
  this time: an EMPTY 0-byte "main" file
  at repo root (misfire artifact) - rm it
  before any future git add -A sweep.
  Next: R240 - the III.E Special
  artifacts table pins (artifact names and
  printed g.p. sale values, the no-x.p.
  convention, DMG p.130-131, upload lines
  ~9917+, engine table kArtifacts in
  dm/treasure.cpp), or the next un-pinned
  III.A-H surrounding prose seam (the III.F
  armor footnote "65% man-sized..." and
  III.G swords also still unpinned).
- R240 landed 2026-10-07: commit 04356c7,
  census 159, GREEN (no b-round). The III.E
  Special artifacts pins (DMG p.130-131,
  upload lines ~9917-9946) - the artifact
  g.p. sale value table that CLOSES the
  III.E magic item block end to end.
  rules/specart.h CREATED (the grenade.h
  pattern, sa prefix), keyed to the 29 die
  bands of the engine Special artifacts
  table (kArtifacts order, the Axe of the
  Dwarvish Lords 01 through the Wand of
  Orcus 00): 26 single-value rows (Axe
  55,000, Jacinth 100,000, Mighty Servant
  of Leuk-O 185,000, Sceptre 150,000,
  Sword of Kas 97,000, ...); the Orb of
  the Dragonkind 41-47 prints the RANGE
  10-80,000 (read 10,000-80,000) - a
  uniform roll (saSaleGpHi, the R225
  dual-value analog, count 1); the Teeth
  of Dahlver-Nar 93-98 at 5,000 PER TOOTH
  (count 1); the Throne of the Gods 99
  prints NO sale value (priceless, 0 g.p.,
  count 1); the no-x.p. convention - the
  table footnote reads These items bring
  no experience points. (saXpValue, all
  29 rows zero); the Wand of Orcus rides
  the 00 band - pinned as 100. The row
  NAMES were already pinned by the R122
  line-diff audit. R240 audit verified
  bad 0 over 66 asserts (GREEN first try;
  35 verified blocks total). Created-file
  md5 3d3323d23e96e428089fdc2ad0a3cd38
  (byte-identical across three fresh
  trees); splice md5 advisory. Acid:
  two-pass 4/0 then 0/4; walk-cell
  mutation (55000->54000) RED bad 3 +
  saDualRangeCount 1->2 RED bad 1,
  restored byte-identical GREEN;
  brace/paren 0/0; all 10 arrays (5
  header + 5 audit) 29 cells comma-
  terminated; 10 accessors counted by
  list (the R239 (a) lesson held).
  GROUND-TRUTH PARSER LESSONS (two, both
  parser bugs NOT pin bugs): (a) the
  range cell 10-80,000 abbreviates the
  lower bound comma - 10 means 10,000
  (scale the lower by 1000 when the
  upper carries a comma and the lower
  does not); (b) a LONE 00 band parses
  lo=0 - a single-band 00 is band 100
  on BOTH edges.
  BUILD CATCH: a dropped closing quote
  and comma in the splice audit list
  (the implicit string-concat trap -
  Python would have merged two C++ lines
  silently, or broken the string) caught
  by py_compile BEFORE any tree run; the
  sed near-miss at R239 was the same
  class. py_compile stays first in the
  ritual for a reason.
  Next: R241 - the III.F armor and shield
  table pins (DMG p.129-130; the armor
  size footnote: 65% of all armor is
  man-sized, 20% elf-sized, 10% dwarf-
  sized, 5% gnome or halfling sized,
  upload lines ~9902+), or the III.G
  swords seam / the next un-pinned
  III.A-H surrounding prose seam.
- R241 landed 2026-10-07: commit 28621b4,
  census 160, GREEN (no b-round). The III.F
  armor and shield pins (DMG p.129-130,
  upload lines ~9870-9902, the RIGHT column
  of the two-column print). rules/armorshield.h
  CREATED (the grenade.h pattern, as
  prefix), keyed to the 26 die bands of the
  engine III.F table (kArmor order, Chain
  Mail +1 01-05 through Shield -1 missile
  attractor 98-00): the x.p. point values
  and g.p. sale values of every row; the
  TWO cursed no-x.p. rows (Plate Mail of
  Vulnerability 40-44 and Shield -1 missile
  attractor 98-00 print --- - asNoXpCount
  2, the R240 convention on just two rows);
  the armor SIZE footnote: 65% man-sized,
  20% elf-sized, 10% dwarf-sized, 5% gnome
  or halfling sized (asManSizedPct etc.,
  sum probed to 100). NO class marks,
  asterisks or dual-value rows. R241 audit
  verified bad 0 over 63 asserts (36
  verified blocks total). Created-file md5
  b2c9affdc3a7869f955b882cad5e4a8a
  (byte-identical across three fresh
  trees); splice md5 advisory. Acid:
  two-pass 4/0 then 0/4; walk-cell mutation
  RED bad 3 + asNoXpCount 2->3 RED bad 1,
  restored byte-identical GREEN; brace/
  paren 0/0; all 4+4 arrays 26 cells
  comma-terminated; 10 accessors.
  THE R241 LESSON (the contiguity assert
  earned its keep): the FIRST splice draft
  had a hand-transcription typo - Studded
  Leather +1 upper edge typed as 70 where
  the print says 70-75 - and the CONTIGUITY
  assert (lo[i] == hi[i-1] + 1) caught it
  in the sandbox: audit_eval RED bad 1 with
  lo[19]=76 vs hi[18]+1=71. Two fixes now
  standing: (a) the band-contiguity loop
  stays mandatory in every table audit;
  (b) NEW GATE: derive the header arrays
  from the engine/ground-truth parse
  programmatically and diff them against
  the splice arrays (the DERIVED-CHECK) -
  never trust hand-typed cells, even after
  a clean ground-truth parse.
  BUILD CATCH (the R240 class, round two):
  nine list lines again dropped the closing
  quote+comma (all in multi-line || probe
  continuations) - now caught BEFORE
  compile by an ast scan for implicit-concat
  strings inside lists; the scan runs
  before every tree pass.
  Next: R242 - the III.G swords table pins
  (DMG p.131; the sword size note: 70%
  longswords, 20% broadswords, 5% short
  swords, 4% bastard swords, 1% two-handed;
  the three cursed swords print --- g.p.
  sale values, upload lines ~9917+), or the
  III.H misc weapons seam / the next
  un-pinned III.A-H surrounding prose seam.
- R242 landed 2026-10-07: commit 81f935b,
  census 161, GREEN on the first Termux
  preflight (no b-round). The III.G swords
  pins (DMG p.131, upload lines ~9906-9947,
  the RIGHT column of the two-column
  print). rules/swords.h CREATED (the
  grenade.h pattern, sw prefix - no clash
  with rsw in rodswands.h), keyed to the
  26 die bands of the engine III.G table
  (kSwords order, Sword +1 01-25 through
  Sword, Cursed Berserking 96-00): the
  x.p. point values and g.p. sale values;
  the THREE cursed swords print --- g.p.
  (Sword +1 Cursed 86-90, Sword -2 Cursed
  91-95, Cursed Berserking 96-00 -
  swNoSaleCount 3, pinned as 0 g.p.); the
  sword SIZE note: 70% longswords, 20%
  broadswords, 5% short (small) swords, 4%
  bastard swords, 1% two-handed (five
  constants, sum probed to 100); and the
  TWO tiered-bonus wrapped rows: Flame
  Tongue +2 vs. regenerating, +3 vs.
  cold-using/inflammable/avian, +4 vs.
  undead; Frost Brand +6 vs. fire
  using/dwelling (swFlameVsRegenBonus etc.
  + an arithmetic ladder probe). NO class
  marks or asterisks; the no-x.p. footnote
  printed after the table belongs to the
  III.E Special table (pinned R240).
  R242 audit verified bad 0 over the
  full block (37 verified blocks total).
  Created-file md5
  21edda11a94c25cee4cd71dccd7c3b9a
  (byte-identical across three fresh
  trees); splice md5 advisory. Acid:
  two-pass 4/0 then 0/4; walk-cell
  mutation RED bad 2 + swNoSaleCount 3->4
  RED bad 1, restored byte-identical
  GREEN; DERIVED-CHECK vs the parsed
  kSwords rows ALL MATCH (the R241 gate
  held); implicit-concat ast scan clean
  BEFORE compile this time; brace/paren
  0/0; all arrays 26 cells
  comma-terminated; 15 accessors.
  GROUND-TRUTH PARSER EXTENSIONS (two,
  both parser-side): (a) wrapped-name rows
  where the values ride the continuation
  line now MERGE the continuation name
  text into the row name (the R238 (b)
  lesson extended: attach values AND
  merge names); (b) a prose note that
  starts in a table cell and finishes on
  a bare line gets reconstructed by cell +
  continuation, while the footnote after
  it (no-x.p.) is attributed to the
  OTHER table correctly.
  Next: R243 - the III.H misc weapons
  table pins (DMG p.131-132; the quantity
  ranges ride the arrow/bolt rows - the
  ItemRow qlo/qhi fields - upload lines
  ~9949+; note rows 57-60 and 61-62 are
  BOTH printed Hammer +2 with different
  values, Curtiss-verified against
  p.125), or the next un-pinned III.A-H
  surrounding prose seam.
- R243 landed 2026-10-07: commit b0aa679,
  census 162, GREEN on the first Termux
  preflight (no b-round). The III.H misc
  weapons pins (DMG p.131-132, upload
  lines ~9949-9987, single-column table).
  rules/mweapons.h CREATED (the grenade.h
  pattern, mw prefix - no clash with
  weaponChart in weapontables.h), keyed
  to the 36 die bands of the engine III.H
  table (kWeapons order, Arrow +1 01-08
  through Trident (Military Fork) +3 00):
  the x.p. point values and g.p. sale
  values; the FOUR ammo quantity ranges
  printed as the N-M in number suffixes
  (Arrow +1 2-24, Arrow +2 2-16, Arrow +3
  2-12, Bolt +2 2-20 - mwQtyLo/mwQtyHi
  walks, 0/0 = a single item,
  mwQtyRangeCount 4); the TWO duplicate
  Hammer +2 rows (57-60 at 300/2,500 and
  61-62 at 650/6,000, both printed
  verbatim, Curtiss-verified against
  p.125 - mwDuplicateNameCount 2); the
  cursed Spear, Cursed Backbiter 98-99
  prints --- x.p. (mwNoXpCount 1). NO
  class marks or asterisks. R243 audit
  verified bad 0 on the first pass (38
  verified blocks total). Created-file
  md5 c256394f46b53964762db62f8ebc6fe4
  (byte-identical across three fresh
  trees); splice md5 advisory. Acid:
  two-pass 4/0 then 0/4; walk-cell
  mutation (mwQtyHi 24->25) RED bad 2 +
  mwQtyRangeCount 4->5 RED bad 1,
  restored byte-identical GREEN;
  DERIVED-CHECK vs the parsed kWeapons
  rows ALL MATCH (lo/hi/xp/gp/qlo/qhi all
  six walks); implicit-concat scan clean;
  brace/paren 0/0; all 6+6 arrays 36
  cells comma-terminated; 10 accessors.
  MILESTONE: the whole III.A-H magic
  item TABLE block is now fully pinned -
  potions, scrolls, rings, rods/staves/
  wands, misc tables 1-5, the Special
  artifacts, armor and shields, swords,
  misc weapons. The next arc: the
  EXPLANATIONS AND DESCRIPTIONS prose
  that follows the tables (upload lines
  ~9995+): potions prose was pinned
  R221, scrolls prose R222, rings
  footnotes R223 - the candidate seams
  are the rods/staves/wands explanation
  prose and the misc item explanation
  prose (the long per-item descriptions),
  or the next ranked gap in the dmg_gap_
  report ranked list.
  Next: R244 - the rods/staves/wands
  explanation prose seam (upload III.C
  EXPLANATIONS section), or the next
  ranked gap.
- R244 landed 2026-10-07: commit 0ef2b69,
  census 163, GREEN on the first Termux
  preflight (no b-round). The III.D rods
  explanation prose pins - the FIRST prose
  round of the EXPLANATIONS AND
  DESCRIPTIONS section (DMG pp.141-142,
  upload lines ~10562-10687; pages derived
  from the running-head page count, the
  section starts p.133 after the p.132
  table block - Curtiss spot-check still
  pending). rules/rodsprose.h CREATED
  (grenade.h pattern, rp prefix, 74
  accessors): the section conventions
  (rods 50 charges minus 0-9/d10-1, staves
  25 minus 0-5/d6-1, wands 100 minus
  0-19/d20-1; drained item crumbles to
  powder; distance-discharge command-word
  rule; magical silence stops the device)
  and the SEVEN rods - Absorption (50
  spell levels, 1-segment casting, never
  recharged), Beguiling (2" radius,
  intelligence 1+, no save, 1 turn per
  charge, rechargeable - the only rod
  that prints it), Cancellation (the
  11-row item saving throw table: potion
  20, scroll 19, ring 17, rod 14, staff
  13, wand 15, misc magic 12,
  artifact/relic 3, armor/shield 11 (8
  if +5), sword 9 (7 holy), misc weapon
  10; drained items never restorable, the
  rod goes brittle), Lordly Might (10 lb,
  16 Str, 3 spell-like functions at 1
  charge, fear 6", drain 2-8 hp; 4 weapon
  forms +2/+1/+4/+3, spear 6-15 ft,
  handle 12 ft; 3 mundane uses, pole 5 ft
  per segment to 50 ft, 4,000 lb, doors at
  30 ft, storm giant force; weapon
  functions 2 and 3 die with the
  charges), Resurrection (once per day;
  11-class charges cleric 1 through bard
  2, 7-race charges dwarf 3 through
  human 1, multi-classed least
  favorable), Rulership (12", 200-500
  HD, save at int 15 and 12 HD, 5
  segments, 1 turn per charge), Smiting
  (+3, 4-11, golems 8-22 with 20+
  destroy and 1 charge per hit,
  outer-planar 20+ draws 1 charge and
  triples damage). Cross-checked in the
  audit: the 7 rods are the first 7 rows
  of engine kRods, bands 01-19, staff
  rows from 20 (vs the R224 rodswands.h
  bands). Created-file md5
  e420824ff857099621c32a0b64fdaac4
  (byte-identical across three fresh
  trees); splice md5 12c114fa4ee44788
  caaaa5f91cc2ce85 advisory. Acid:
  two-pass 4/0 then 0/4; audit_eval R244
  verified bad 0 (54 asserts), full
  sweep 39 verified all bad 0 (124
  unverified engine class as always);
  DERIVED-CHECK header vs ground-truth
  parse ALL MATCH (70 scalars + 4
  arrays); walk-cell mutation (staff save
  13->14) RED bad 1 with md5 change,
  count-constant mutation (the two 11s
  -> 12) RED bad 3, restored GREEN.
  Battery lesson: the mutation-RESTORE
  sed over-matched the legit return-12
  accessors (spear handle, rulership
  radius and save HD), so the test tree
  was rebuilt fresh from base instead of
  patching debris - byte-identical
  reproduce, GREEN again. The edit-tool
  regex corruption struck AGAIN in
  sandbox scripts this round (twice in
  groundtruth.py) - full write_file
  rewrites remain the fix. Next: R245 -
  the staves explanation prose (upload
  ~10688-10785: the 8th-level
  conventions, 2-segment discharge/8
  recharge, 8d6 damage, and the seven
  staves Command/Curing/Magi/Power/
  Serpent/Striking/Withering), then
  R246 the wands (~10786-10948, incl.
  the wand of wonder effect table). The
  potions/scrolls/rings explanation prose
  (upload ~9998-10561) and the misc magic
  item explanations (~10949+) are also
  still open.
- R245 landed 2026-10-07: commit 12f6b08,
  census 164, GREEN on the first Termux
  preflight (no b-round). The III.D staves
  explanation prose pins - the second
  EXPLANATIONS prose round (DMG pp.142-143,
  running-head page count, same pending
  Curtiss spot-check as R244). rules/
  stavesprose.h CREATED (grenade.h pattern,
  stf prefix, 76 accessors): the staff
  conventions (8th level of magic-use,
  2 segments to discharge and 8 to build up
  again, nominal damage 8d6) and the SEVEN
  staves - Command (3 functions, only 2 for
  a magic-user; 1 charge per suggestion or
  charm, 1 per turn of control, 1 per 1"
  square of plants per turn), Curing (4
  functions, cure wounds 6-21 hp = 3d6+3,
  once per person per day, max twice per
  function, 8 uses per 24 hours), the Magi
  (5 free powers, 10 at 1 charge counted
  programmatically from the print lines,
  4 at 2 charges; elementals 8 hit dice,
  telekinesis 200 lb, +2 saves,
  rechargeable only by absorption), the
  retributive strike (globe 3", damage
  8/6/4 times the spell levels 1-25 by
  distance band, save for half, 50% plane
  travel, 2 items capable - shared magi/
  power accessor set), Power (6 one-charge
  and 3 two-charge powers - the book
  prints these lists in merged two-column
  lines, counts pinned, names in comments;
  +2 AC and saves, smite +2 3-8, 1 charge
  doubles but 2 do NOT triple,
  paralyzation cone 4" x 2"), the Serpent
  (python +2 3-8, snake 25 ft AC 3 49 hp 9"
  move, constriction 4-10 per round; adder
  +1 2-4, head AC 5 20 hp 1 turn, save vs
  poison or die; no charges, 60% pythons),
  Striking (+3, 4-9 = d6+3, bonus 3/6/9 at
  1/2/3 charges, max 3 per strike),
  Withering (+1, 2-5, 2 charges age 10
  years, 3 wither a limb, ageless immune -
  NO recharge statement printed, so no
  accessor). Cross-checked in the audit:
  the 7 staves are engine kRods rows 8-14,
  bands 20-33, wand rows from 34 (vs the
  R224 rodswands.h bands). Created-file
  md5 123f66eefebbdbe339bf8f5d8983ac1a
  (byte-identical across three fresh
  trees); splice md5 a6671fcab9387910dbd9
  aab4dac6decd advisory. Acid: two-pass
  4/0 then 0/4; audit_eval R245 verified
  bad 0, full sweep 40 verified all bad 0;
  DERIVED-CHECK ALL MATCH (74 scalars + 2
  arrays); walk-cell mutation (striking
  bonus 9->8) RED bad 2 with md5 change;
  count-constant mutation (magi 10->11)
  RED bad 3 - context-anchored because
  return 10 prints 3 times in the header;
  the R244 restore lesson applied in
  advance: fresh-tree rebuild restored
  byte-identical GREEN. Next: R246 - the
  wands explanation prose (upload
  ~10786-10948: 6th level of experience
  convention, 1% backfire trap, the
  fifteen wands - Conjuration, Enemy
  Detection, Fear, Fire, Frost,
  Illumination, Illusion, Lightning,
  Magic Detection, Metal and Mineral
  Detection, Magic Missiles, Negation,
  Paralyzation, Polymorphing, Secret Door
  and Trap Location, and the wand of
  wonder effect table ~30 rows). After
  that: the potions/scrolls/rings
  explanation prose (upload ~9998-10561)
  and the misc magic item explanations
  (~10949+).
- R246 landed 2026-10-07: commit 9b05e62,
  census 165, GREEN on the first Termux
  preflight (no b-round). The III.D wands
  explanation prose pins, part 1 of 3
  (DMG pp.143-144, running-head page
  count). rules/wandsprose.h CREATED
  (grenade.h pattern, wd prefix, 65 SCALAR
  accessors - no arrays this round, so
  both mutation classes were scalar
  mutations): the section conventions
  (wands perform at 6th level of
  experience; at DM option 1% of all
  wands are trapped to backfire) and the
  FIRST FIVE wands - Conjuration (11
  recognized conjuration/summoning spells
  counted programmatically from print;
  monster summoning max 6 charges at 1
  per level, 5 segments; curtain of
  blackness 600 sq ft at 2 charges;
  prismatic sphere 1 charge per color;
  each function 5 segments, 1 per round),
  Enemy Detection (6" sphere, 1 charge
  per turn), Fear (cone 6" x 2", 1
  segment flash, flee 6 rounds, once per
  round), Fire (4 functions: burning
  hands 10 ft wide 12 ft long 6 hp,
  pyrotechnics 2 segments 1 charge,
  fireball range 16" 2 segments 2 charges
  6 dice with 1s as 2s = 12-36, wall of
  fire 12 square" 6 rounds 8-18/2-8/1-4
  by distance, ring circle 2.25 inch
  diameter PINNED AS 9 QUARTER-INCHES -
  the first fractional-value workaround),
  Frost (3 functions: ice storm 6" 1
  segment 1 charge, wall of ice 6 inches
  thick 6" square 2 segments 1 charge,
  cone of cold 6" long 2" terminal, 2
  segments, c. -100 F, 6 dice 12-36, 2
  charges). All five rechargeable.
  Cross-checked in the audit: the five
  wands are engine kRods wand rows 1-5,
  bands 34-47, illumination from 48 (vs
  the R224 rodswands.h bands). Engine
  lesson: kRods has 16 wand rows (15
  wands + the wonder) - 30 rows total.
  Created-file md5 8964301dee5d3b8de53b
  bcd9659f5fb (byte-identical across
  three fresh trees); splice md5
  e34dc66988e047c04a4f1de5bda39a0d
  advisory. Acid: two-pass 4/0 then 0/4;
  audit_eval R246 verified bad 0, full
  sweep 41 verified all bad 0; DERIVED-
  CHECK ALL MATCH (65 scalars); value
  mutation (fireball damage hi 36->37)
  RED bad 1 with md5 change, count
  mutation (fire function count 4->5)
  RED bad 1, both context-anchored;
  fresh-tree rebuild restored
  byte-identical GREEN. Next: R247 - the
  remaining ten wands (upload
  ~10828-10865: Illumination 4 functions
  incl. sunburst 12" range globe 4"
  undead 6-36 blind 2-12 segments 3
  charges, Illusion 14" 3 segments,
  Lightning shock 1-10 + bolt 12-36,
  Magic Detection 3" 2% malfunction,
  Metal and Mineral Detection 3", Magic
  Missiles 2-5 max 2 per round,
  Negation 100/75 percent NOT
  rechargeable, Paralyzation 6" 5-20
  rounds, Polymorphing 6", Secret Door
  and Trap 1.5"/3"), then R248 the wand
  of wonder effect table (upload
  ~10867-10947, 19 bands, 1 charge per
  function, not rechargeable) - that
  closes the whole III.D section. The
  potions/scrolls/rings explanation prose
  (upload ~9998-10561) and the misc magic
  item explanations (~10949+) remain
  open.

R247 landed the III.D wands explanation
prose part 2 (DMG pp.144-145, upload
~10828-10865) in TWO pushes: 088f090
then the R247b fix-up f0e0109. The
first push landed ONLY the splice
script (1 file changed) because the
canvas copy was saved with a filename
typo (tools/r247_sploce.py) and the
splice was never run - the pins were
not in the repo. NEW LESSON (the R247
gates): check the COMMIT SHAPE, not
just the push - a lands-clean round
shows 4 files changed (new header +
regtest + gap report + splice); 1
file changed means the splice did not
run. The fix-up ritual was mechanical:
mv the typo, run the splice twice
(4/0 then 0/4), created-file md5
01d11e0b8ceae25f3fbaa9a41fe22253, then
commit; the paste also added one
trailing blank line to the script
(823 vs 822 lines) - verified harmless
byte-diff, and a reason the advisory
splice md5 differs from the landed
file md5. Content: rules/wandsprose2.h,
73 scalar accessors (grenade.h
pattern, wd prefix, no arrays): the
remaining TEN wands - Illumination (4
functions; dancing lights 1 seg 1 chg,
light 2 seg 1 chg, continual light 2
seg 2 chg, sunburst 12" range 1/10 sec
pinned as 1 tenth, globe 4", undead
6-36 no save, blind 2-12 seg, 3 seg 3
chg), Illusion (14" 3 seg 1 chg + 1
per round), Lightning (shock 1-10 hp
metallic-discount AC 10 1 chg; bolt
12-36 6d6 1s-as-2s 2 chg 2 seg; 1 per
round), Magic Detection (3" 1 round 1
chg per turn 2% cumulative), Metal and
Mineral Detection (3" 1 round 1 chg
per turn), Magic Missiles (2-5 hp 3 seg
1 chg max 2 per round), Negation (100%
wands 75% devices 1 seg once per round
1 chg; the ONLY wand of the ten that
cannot be recharged), Paralyzation (6"
ray 5-20 rounds 3 seg 1 chg once per
round), Polymorphing (6" ray 3 seg 1
chg 1 per round), Secret Door and Trap
Location (1.5" secret doors pinned as
3 HALF-INCHES - first half-inch pin
since the R246 quarter-inch - 3"
traps 1 round 1 chg). All but Negation
rechargeable. Engine cross-check in
the audit: rswRowLo(19)=48 rswRowHi(28)
=94 (the ten), rswRowLo(29)=95
rswRowHi(29)=100 (the wonder) vs the
R224 rodswands.h bands. Splice md5
advisory ad5ee210f229f1d160aa12f3d5055
7e9; one splice bug caught in-battery:
the pass-2 idempotence marker initially
spanned a header-comment line break
(fixed to contiguous text). Acid: two-
pass 4/0 then 0/4; audit_eval R247
verified bad 0 (11 asserts), full sweep
42 verified all bad 0; DERIVED-CHECK
ALL MATCH (73/73 names + values, every
accessor audited once); value mutation
(sunburst range 12->13) RED bad 1 md5
3e51811b..., count mutation (illum
function count 4->5) RED bad 1 md5
40cb3dd7..., fresh-tree rebuild
restored byte-identical GREEN. Census
165 -> 166 at f0e0109. Next: R248 -
the wand of wonder effect table (upload
~10867-10947: 19 bands 01-10 through
98-00, 1 charge per function, may not
be recharged, engine bands 95-100, plus
effect numeric facts like 600
butterflies, 16" square grass, 1,000 lb
vanish, 10-40 gems, 5d4 hits) - that
closes the whole III.D wands arc. The
potions/scrolls/rings explanation prose
(upload ~9998-10561) and the misc magic
item explanations (~10949+) remain
open.

R248 landed the III.D wand of
wonder effect table (DMG p.145,
upload ~10867-10947) in ONE clean
push 1c72cda - commit shape checked
first: 4 files changed, rules/
wonder.h created, census 167 (the
R247 lesson held). THIS CLOSES THE
ENTIRE III.D wands arc: rods R244,
staves R245, wands prose R246-R247,
wonder R248. rules/wonder.h (the
grenade.h pattern, wonder prefix,
42 accessors - 3 table + 39
scalars, the FIRST ARRAY HEADER
SINCE R224): the 19 die bands
01-10 through 98-00 (ground-truth
parse verified they tile 01-100
with no gaps or overlaps; the
terminal 98-00 band shares its
line with the flesh-to-stone
effect, and the 10-40 gems effect
line is NOT a band - the parser
distinguishes lone band lines
from the inline terminal band),
plus the effect facts: slow 1
turn, delude wielder 1 round
(second die roll), gust double
force, stinking cloud 3", heavy
rain 1 round in 6" radius, summon
rhino 1-25 / elephant 26-50 /
mouse 51-00, lightning bolt 7" x
0.5" as wand (width pinned as 1
HALF-INCH, second half-inch pin
after the R247 secret-door 3
half-inches), 600 large butterflies
2 rounds blinding everyone
including the wielder, enlarge
within 6", darkness 3" diameter
hemisphere at 3" center distance,
grass 16" square or 10 times
normal size, vanish non-living
1,000 pounds and 30 cubic feet,
diminish wielder to 1" height,
fireball as wand, invisibility
covers the wielder, leaves within
6", 10-40 gems of 1 g.p. base
value in a 3" stream each 1 h.p.
with 5d4 for the number of hits
(5d4 gives 5-20 hits - the gem
count and the hit roll are
separate facts), shimmering colors
4" x 3" blinded 1-6 rounds, flesh
to stone or reverse within 6". 1
charge per function, may not be
recharged. Engine cross-check in
the audit: the wonder is kRods row
30, rswRowLo(29)=95 rswRowHi(29)
=100 vs the R224 rodswands.h pins;
audit shape follows the VERIFIED
R224 style (static const kLo/kHi
tables + for-loop cell walks +
continuity + clamp checks) -
audit_eval expands it to 52
asserts, verified bad 0. Splice
md5 advisory a23e78c728de6cb2a90
604194fedec2; created-file md5
98a350b5542cfb7e7ec4244c04eb4a1b
(byte-identical across three
fresh trees). Ground truth ALL
MATCH before any pin was written
(the bands parsed independently
from the upload; the 98-00/10-40
parse traps were caught by the
ground truth itself, not the
splice). Acid: two-pass 4/0 then
0/4; full sweep 43 verified all
bad 0; DERIVED-CHECK bad 0 (40/40
scalars + both band arrays vs the
fact table, audit kLo/kHi match,
marker-contiguity pre-flight now
standard after the R247 bug);
value mutation (vanish mass
1000->1001) RED bad 1 md5
2ce19b2d..., count mutation (row
count 19->20) RED bad 1 md5
dd842000..., fresh-tree rebuild
restored byte-identical GREEN.
Census 166 -> 167 at 1c72cda. THE
III.D EXPLANATION PROSE IS NOW
FULLY PINNED. Remaining open
seams: the potions/scrolls/rings
explanation prose (upload
~9998-10561) and the misc magic
item explanations (~10949+, the
III.E section: the TABLE (III.E.)
1. headings begin at ~10962).
R249 landed the III.A potions
explanation prose part 1 of 3 (DMG
pp.133-134, upload ~9998-10062):
the general conventions (duration
4 turns + 1-4 d4, onset 2-5
segments) and the first NINE
potions, Animal Control through
Extra-Healing, at 9d0215f,
census 168. ANOTHER SPLOCE FIRST:
the advisory was saved as tools/
r249_sploce.py (1 file changed
caught by the commit shape check -
the R247 lesson held again),
recovered clean via mv to
r249_splice.py, verify advisory
md5, rerun the ritual, amend
d4148e5 into 9d0215f, push
--force-with-lease: 4 files
changed, rules/potionsprose.h
created. rules/potionsprose.h
(the grenade.h pattern, pot
prefix): 56 accessors - 51
scalars + 5 array walkers
(potAnimalTypeLo/Hi, potClimb-
ArmorPercent, potDragonTypeLo/Hi).
Engine cross-check vs the R221
pins: potionRowLo(0)=1,
potionRowHi(8)=26,
potionRowLo(9)=27, kPotions rows
1-9, bands 01-26, fire resistance
from 27. SEAM DISCOVERY: the
TREASURE headings sprinkled
inside upload ~9998-10561 are the
BOOK RUNNING PAGE HEADERS, not
tables - ignore them in every
potions/scrolls/rings prose
ground-truth parse. Ground-truth
ALL MATCH before any pin, and it
caught three scratch-parse traps
itself: sub-table regexes must be
section-bounded, the dragon rows
have band and name in SEPARATE
pipe cells, the engine bands need
a \s* after the comma. Acid:
two-pass 4/0 then 0/4 on
t1/t2/t3; REPRO-CLEAN; audit_eval
R249 verified bad 0 (55 asserts);
full sweep 44 verified all bad 0
(124 unverified = accepted engine
class); both mutations RED (pot-
DeludeAgreePercent 90->91 md5
cc24ac71..., potDragonType-
RowCount 12->13 md5 db819044...);
fresh rebuild restored
byte-identical GREEN; DERIVED-
CHECK bad 0 (marker contiguous,
51/51 scalars, all 5 arrays,
audit refs complete, depth 0/0).
Splice advisory md5 4edbbfd18403
f34ea0dbb16593afe268; REAL GATE
rules/potionsprose.h ba533cde893
4c7fd6aa2b4a03c26eacc; regtest
ea43579bee4bf6e961748990620a569d;
gap report 05e3809b081e17ec9124de7
afff5f31e; splice 685 lines.
Census 167 -> 168 at 9d0215f.
Next: R250 - potions part 2, Fire
Resistance through Invisibility
(upload ~10063-10128, includes
the Giant Control d20 table and
the Giant Strength damage/rock
tables), then R251 potions part
3 Invulnerability through Water
Breathing (~10129-10189), then the
scrolls explanations (~10191-
10280) and the rings explanations
(~10282-10561, X-Ray Vision ends
10561). Remaining open seams after
the potions arc: misc magic item
explanations III.E at ~10949+.
R250 landed the III.A potions
explanation prose pins, part 2 of 3
(DMG pp.134-136, upload ~10063-10128):
potions 10 through 19, Fire
Resistance through Invisibility, in
ONE clean push dc1cab5 - commit
shape checked first: 4 files changed,
rules/potionsprose2.h created (the
wandsprose2.h part-2 pattern, the pot
prefix continues, no sploce this
time). rules/potionsprose2.h: 53
accessors - 38 scalars + 15 array
walkers. Fire Resistance (-2 per
die, save +4; half dose -1/+2; 1
turn or 5 rounds), Flying (fly spell,
3rd level), Gaseous Form (3" per
round, whirlwind double damage),
Giant Control (1-2 giants, save -4
if 1 / +2 if 2; 6-row d20 type
sub-table hill 1-5 through storm 20;
5-30 5d6 rounds), Giant Strength (the
6-row die table: weight allowances
4500-12000, damage bonuses +7 through
+12, rock base ranges 8/16/10/12/14/
16 inches, rock damage 1-6/1-12/1-8/
1-8/1-10/1-12, bend bars/lift gates
50-100), Growth (6 feet per quarter,
24 full), Healing (4-10 2d4+2),
Heroism (below 10 levels; 3-row
consumer table, energy levels 3/2/1,
accumulated damage 3+1/2+2/1+3 on
d10), Human Control (32 levels/hit
dice; 8-row d20 type table; 5-30
rounds), Invisibility (gulp 1/8,
3-6 turns). Engine cross-check now
band-by-band: kPotions rows 10-19,
bands 27-54, invulnerability 55, the
audit loops potionRowLo/Hi(9..18)
against the R221 pins. Ground-truth
ALL MATCH before any pin, and it
caught the R250 parse traps itself:
the upload Giant Strength table is
CELL-MANGLED (each row parses by
band regex + weight + bonus + range
+ rock + bend on the raw line, rock
damage found AFTER the die-band
match), the human control 20 row has
band and name in separate pipe cells
(the R249 dragon lesson applies
again), and the stray 04 4 heroism row
is paste noise - skipped by the
ordinal-suffix row regex. Acid:
two-pass 4/0 then 0/4 on t1/t2/t3;
REPRO-CLEAN byte-identical across
three fresh trees; audit_eval R250
verified bad 0 (65 asserts); full
sweep 45 verified all bad 0 (124
unverified = accepted engine class);
both mutations RED (potHumanLevels-
Total 32->33 md5 d1023420752ae1d991a
e1f0f1942ff8e, potGiantTypeRowCount
6->7 md5 ad880b3d49b9d7626de33645aa
e20afc); fresh rebuild restored
byte-identical GREEN; DERIVED-CHECK
bad 0 (marker contiguous, 38/38
scalars, all 15 arrays, audit refs
complete, depth 0/0, census 169, no
apostrophes, no literal backslash).
Splice advisory md5 8e3672903f5ab1
496ce75d67de6abb0b; REAL GATE
rules/potionsprose2.h f0736dfbad0a5
e895f7ab0b5a2366501; regtest
52824b8d2793798b749b28368af2120c;
gap report 86105d072e245b1b8cd28b6bb
964e965; splice 800 lines. Census
168 -> 169 at dc1cab5. Next: R251 -
potions part 3, Invulnerability
through Water Breathing (upload
~10129-10189, closes the potions
arc: engine kPotions rows 20-35,
bands 55-100), then the scrolls
explanations (~10191-10280) and the
rings explanations (~10282-10561),
then the misc magic item
explanations III.E at ~10949+.
R251 landed the III.A potions
explanation prose pins, part 3 of 3
(DMG pp.136-137, upload ~10129-10189):
the final sixteen potions,
Invulnerability through Water
Breathing, in ONE clean push d3aa1d2
- commit shape checked first: 4 files
changed, rules/potionsprose3.h created.
THIS CLOSES THE III.A POTIONS ARC END
TO END: the R249 conventions through
the R251 final row, engine bands
01-100, all 35 kPotions rows now
have both table pins (R122/R221) and
prose pins. rules/potionsprose3.h: 69
accessors - 64 scalars + 5 array
walkers. Invulnerability (4 hit dice
floor, armor class +2 classes, saves
+2, 5-20 rounds), Levitation (2nd
level spell, 6,000 g.p.), Longevity
(1-12 years, 1% cumulative reversal),
Oil of Etherealness (3 rounds onset,
4 + 1-4 turns), Oil of Slipperiness
(95% per round floor slip, 8 hours),
Philter of Love (charm 4 + 1-4
turns), Philter of Persuasiveness
(+25% reaction dice, suggest once per
turn within 3"), Plant Control
(intelligence 5+ save, 2" x 2"
square, range 9", 5-20 rounds),
Poison (weak +1/+4, deadly -1/-4 or
more, neutralize 40%), Polymorph self
(4th level spell), Speed (+100%, 9"
becomes 18", ages 1 year, 5-20
rounds), Super-Heroism (below 13
levels; the 4-row consumer table -
energy levels 5/4/3/2, accumulated
damage 4+1/3+2/2+3/1+4 on d10; 5-30
melee rounds), Sweet Water (100,000
cubic feet water, 1,000 acid,
initial 5-20 rounds), Treasure
Finding (within 24", 10,000 copper or
100 gems, 5-20 rounds), Undead Control
(16 hit dice, saves -2, 5-20 rounds;
the 10-row d10 undead type table,
the printed 0 row pinned as the 10
face), Water Breathing (75% two
doses, 25% four, one hour per dose
plus 1-10 rounds). Engine
cross-check band-by-band rows 20-35,
bands 55-100, the table closing at
100, plus the full 35-row tiling
check. Ground-truth ALL MATCH before
any pin, and it caught the R251 parse
traps itself: the TREASURE (POTIONS)
running page header SPLITS the Oil of
Slipperiness paragraph mid-sentence at
~10138 (stripped in preprocessing, the
R249 page-header lesson proven out),
the undead type table is cell-mangled
(the band digit and the name share a
cell with NO space on some rows,
1Ghasts / 0Zombies, other rows split),
the Super-Heroism 06 5 row is the same
paste-noise pattern as the Heroism
04 4 row, and the Polymorph prose has
a magic- user OCR hyphen artifact.
Acid: two-pass 4/0 then 0/4 on
t1/t2/t3; REPRO-CLEAN byte-identical
across three fresh trees; audit_eval
R251 verified bad 0 (57 asserts); full
sweep 46 verified all bad 0 (124
unverified = accepted engine class);
both mutations RED (potUndeadMaxHit-
Dice 16->17 md5 fb6e845ab69324829ac29
d15536493fe, potSHeroRowCount 4->5 md5
c8743733648f606511f56caf0f72b6d2);
fresh rebuild restored byte-identical
GREEN; DERIVED-CHECK bad 0 (marker
contiguous, 64/64 scalars, all 5
arrays, audit refs complete, depth
0/0, census 170). Splice advisory md5
3c35c449eaa71c68ba1856d1a07b84d6;
REAL GATE rules/potionsprose3.h
583c20b78a67c167238990858317fe68;
regtest f9a3887ff43e223c38bab21c853c
9b15; gap report 2c943ade1e5d3c9628bd
4608c1ddebf8; splice 853 lines. Census
169 -> 170 at d3aa1d2. III.E SCOPE
(done during R251): the misc magic
prose begins at part1 ~10948, runs to
part1 line 11067 MID-SENTENCE, and
continues seamlessly into part2 line 3
- global line is roughly 11065 + part2
line, the TREASURE (MISCELLANEOUS
MAGIC) headers there are running page
headers mid-paragraph; that seam spans
both upload parts and will need a
two-part-file ground truth, likely
several rounds. Next: R252 - the
scrolls explanations (upload
~10191-10280, the III.B arc opener:
protection scrolls, 4-7 scroll spells
at 25% miscast chance, cursed and
artifact scrolls), then the rings
explanations (~10282-10561, likely 3
parts), then III.E.
R252 landed the III.B scrolls
explanation prose pins (DMG
pp.137-139, upload ~10191-10280) in
ONE clean push 16fc4e4 - commit shape
checked first: 4 files changed,
rules/scrollsprose.h and
tools/r252_splice.py created.
rules/scrollsprose.h: scp prefix, 88
accessors - 81 scalars + 7 array
walkers, 568 lines. THE MECHANICS:
the class table (first roll 01-70
magic-user, then 01-10 illusionist;
71-00 cleric, then 01-25 druid);
unread scrolls 5-30% likely to fade
with the d6 option; scroll spells
written 1 level above usable, floor
6th (a sixth-level spell at 13th, a
seventh at 15th); a scroll fireball
or lightning bolt is 6d6; spell
failure 5% per level difference (the
wish example 18-1=17 x 5% = 85%);
the 6-row level-difference table
(diff step 3, total 95/85/75/65/
50/30, harmful 5/15/25/35/50/70);
a scroll of 7 spells becomes a
scroll of 6. THE EIGHT PROTECTION
SCROLLS: Demons (1 full round all, 7
segments type VI or lower, 3 segments
type III or lower, 10 ft radius,
5-20 5d4 rounds), Devils (1 round
all, 7 segments greater, 3 segments
lesser), Elementals (6 segments;
the 5-variety table air 01-15
through all 61-00; 10 ft radius; 24
hit dice specific, 16 all; 5-40 5d8
rounds), Lycanthropes (4 segments;
the 7-type table werebears 01-05
through shape-changers 99-00; 10 ft
radius; 49 hit dice, pluses rounded
down unless they exceed +2; 5-30
rounds), Magic (8 segments; 5 ft
radius; 50% drain, save 11 or better
on d20; 5-30 5d6 rounds),
Petrification (5 segments; 10 ft
radius; 5-20 5d4 rounds), Possession
(1 round; 10 ft radius; 10-60 rounds
in 90% of scrolls, 10% have 10-60
turns but are stationary), Undead (4
segments; 5 ft radius; the 10 undead
types, cross-pinning the R251
potUndeadTypeRowCount; 35 hit dice
levels; 10-80 10d8 rounds). ENGINE
CROSS-CHECK: rollScroll prot rows
61-97 vs the R222 scrollpins.h
arrays, band by band, plus the engine
class-split comment (30% clerical,
25% druidical, 10% illusionist) vs
the prose class-table band widths.
PARSE TRAPS (ground-truth scratch
fixes, splice content untouched): the
TREASURE (RINGS) running page header
at ~10274 SPLITS the Possession
paragraph mid-sentence (stripped in
preprocessing, the R249 page-header
lesson proven out again); the
class-table row regex has SIX capture
groups - the second class name is
group 6, not group 5 (the first write
of the parse read the hi band digit
as the name and only the check
caught it); the engine 30/25/10
comment WRAPS across two source lines
(25% then newline then // druidical)
so the engine text needs a
newline-plus-comment normalization
before regexing. SPLICE FIX THIS
ROUND, caught by the battery BEFORE
delivery (the R247 marker lesson
re-caught live): the splice
originally split the marker R252:
the III.B scrolls explanation prose
across two header comment lines, so
the second pass failed with exists
without the marker; fix = reflow the
header comment so the full marker
sits on one line. ALWAYS run the
second pass before delivering. Acid:
two-pass 4/0 then 0/4 on t1/t2/t3;
REPRO-CLEAN byte-identical across
three fresh trees; audit_eval R252
verified bad 0 (57 asserts); full
sweep 47 verified all bad 0 (124
unverified = accepted engine class,
pristine baseline 46); both mutations
RED (scpLycaHitDice 49->50 md5
9e87323b8fc00dd8d69223a7618dc591,
scpElemVarietyRowCount 5->6 md5
9c122ce675955deb715196789ddc1733);
fresh rebuild restored byte-identical
GREEN; DERIVED-CHECK bad 0 (marker
contiguous, 81 scalars + 7 arrays =
88, audit refs 88/88, brace depth 0,
census 171). Splice advisory md5
e61c4c23f475f0d8a2d687121855bc76;
REAL GATE rules/scrollsprose.h
18854c61b54a3410f2ca97c5fc400223;
regtest 4fc60fac4d3a81d0b103af99fa
964958; gap report ab7fdf4d46f84349
9edffdf798d3e409; splice 980 lines.
Census 170 -> 171 at 16fc4e4. Next:
R253 - the rings explanations part 1
(upload ~10282-10561, likely 3
parts), then the misc magic item
explanations III.E (part1 ~10948-
11067 continuing seamlessly into
part2; global line = part1 line or
~11065 + part2 line).
R253 landed the III.C rings
explanation prose part 1 of 3 (DMG
pp.137-138, upload ~10281-10392) in
ONE clean push 57c09fd - commit shape
checked first: 4 files changed,
rules/ringsprose.h and
tools/r253_splice.py created.
rules/ringsprose.h: the rgp prefix
(distinct from the R223 ring prefix),
47 accessors - 44 scalars + 3 array
walkers. THE MECHANICS: max 2 rings
worn (none function if more), max 1
per hand (a 2nd makes both useless),
spell-like abilities at 12th level
of magic use, 20% per-use malfunction
for gnomes/dwarves/halflings, the 3
cursed rings named (contrariness,
delusion, weakness), the
double-dagger most-powerful note.
THE FOUR LEAD RINGS: Contrariness
(removable only via remove curse; the
6-band additional-properties table
01-20 Flying, 21-40 Invisibility,
41-60 Levitation, 61-70 Shocking
Grasp once per round, 71-80 Spell
Turning, 81-00 Strength 18/00; a
cumulative remove curse must equal
or exceed 00 = 100%), Delusion
(removable at any time), Djinni
Summoning (the djinni appears the
next round; a killed servant makes
the ring worthless), Elemental
Command (4 types; elementals kept 5
feet away, charm attempt elemental
save -2; plane creatures attack at
-1, wearer damage -1 per hit die,
saves +2, attacks +4, elemental
saves -4, +6 damage total; the
4-plane save penalty list Air fire /
Earth petrification / Fire
water-or-cold / Water
lightning-electricity, all -2; only
one power at a time; the four power
lists Air 5 gust-of-wind fly
wall-of-force control-winds
invisibility, Earth 6 stone-tell
passwall wall-of-stone
stone-to-flesh move-earth
feather-fall, Fire 5 burning-hands
pyrotechnics wall-of-fire
flame-strike fire-resistance,
Water 8 purify create water
(water breathing 5 foot radius)
wall of ice airy water lower water
part water water walking, with every
once/twice per round/turn/day/week
frequency pinned; the lesser-ring
disguises invisibility / feather
falling / fire resistance / water
walking; closing 12th level, powers
5 segments). ENGINE CROSS-CHECK: the
four kRings rows 1-15 vs the R223
rings.h band edges, the djinni
double-dagger cross-pinning the
ringIsChargeLimited row 2 (count
7). PARSE TRAPS (one ground-truth
scratch fix, splice content
untouched): the TREASURE (RINGS)
running page header at ~10369 SPLITS
the Earth power list mid-list
(stripped, the R249 lesson held
again); the plane anchors MIX hyphen
and em dashes (- Air: but em-dash
Earth and Fire); the save-penalty
list uses the U+2212 MINUS SIGN
which cannot feed int() - capture
the digits and negate; the
contrariness table is cell-mangled
(bands and property names in
separate line groups, the note
paragraph split mid-sentence by the
name column, ending If + names +
a-ring-of-contrariness-turns-spells).
THE R252 MARKER LESSON HELD: the
marker was contiguous on one header
line from the start, two-pass caught
nothing. NEW LESSON (the advisory
md5, now proven twice): the landed
tools/r253_splice.py is
byte-identical to the delivered
canvas body EXCEPT one trailing
newline appended by nano (27561 vs
27560 bytes; R252 was 33221 vs
33220, same nano artifact). The
advisory md5 the user pastes will
therefore differ from the
assistant-side advisory - this is
BENIGN when the REAL GATE md5 (the
generated header) matches; verified
by tarball diff at both rounds. The
binding gate is the header, not the
splice source file. Acid: two-pass
4/0 then 0/4 on t1/t2/t3;
REPRO-CLEAN byte-identical across
three fresh trees; audit_eval R253
verified bad 0 (22 asserts - one per
if-statement: 8 ifs + 3 for-walks of
4/6/4 iterations; a compound if
counts once, but bad 0 proves every
sub-comparison); full sweep 48
verified all bad 0 (124 unverified
= accepted engine class, pristine
baseline 47); both mutations RED
(rgpElemCommandKeepAwayFeet 5->6
md5 186154fa39f7f16a68f6badb2b7fd0d1,
rgpContrarinessPropertyRowCount 6->7
md5 43217c64bb0cc07bdb5e0e89a184f22d);
fresh rebuild restored byte-identical
GREEN; DERIVED-CHECK bad 0 (marker
contiguous, 44 scalars + 3 arrays =
47, audit refs 47/47, brace depth 0,
census 172). Splice advisory md5
(canvas body, 749 lines)
81b22e2d469173a1c356b947ac9c8470
(landed file 57481cff29be21604827c68
1d736407a, the +1 newline); REAL GATE
rules/ringsprose.h
dcf41cf95a1c53c06b66ead20b6a4cb0
(388 lines); regtest 1972ffe7d17074
80e1d74d860713d9c; gap report
7fd6aa7ebe87760a00c06a21513b3afc.
Census 171 -> 172 at 57c09fd. Next:
R254 - rings part 2 (upload
~10393-10457: Feather Falling 5 feet,
Fire Resistance (10 per round very
hot fires, +4 saves exceptionally
hot, -2 per die floor 1, the 24 hp
rule of thumb), Free Action, Human
Influence (charisma 18, 21 levels,
once per day, 3 segments),
Invisibility (10% inaudibility),
Mammal Control (intelligence 4 or
less, 30 hit dice), Multiple Wishes
(2-8 2d4), Protection (+1 AC and
saves, the non-cumulative list),
Regeneration (1 hp per turn, the
01-90 / 91-00 vampiric split),
Shooting Stars (2 modes, the night
function table)), then part 3
(~10458-10561: Spell Storing d4+1
and the level table, Spell Turning
(3 exceptions, the percentile
tables, the 09-or-less/91-or-more
save note), Swimming (21 inch base,
50 foot dive, 4 rounds), Telekinesis
(the weight table), Three Wishes
(25% limited), Warmth (+2 saves,
-1 per die), Water Walking,
Weakness (1 point per turn to 3,
the invisible doubling, 5% berserk
reversal), Wizardry (the doubling
table), X-Ray Vision (20 feet, the
penetration depths)), then III.E.
R254 landed the III.C rings
explanation prose part 2 of 3 (DMG
pp.138-139, upload ~10393-10457,
Feather Falling through Shooting
Stars) in ONE clean push 57c09fd ->
299d538 - commit shape checked
first: 4 files changed, 1648
insertions, rules/ringsprose2.h and
tools/r254_splice.py created.
ringsprose2.h: the rgp prefix again,
67 accessors - 61 scalars + 6 array
walkers (the protection 7-row table
x5 + ball lightning charge balls).
THE SLICE: Feather Falling (5 feet),
Fire Resistance (10 per round very
large fires, 1 per segment, +4 saves
exceptionally hot, -2 per die floor
1, very hot up to 24 hp, exceptional
25+), Free Action, Human Influence
(charisma 18, 21 levels, once per
day, 3 segments), Invisibility (10%
inaudibility), Mammal Control
(intelligence 4 or less, 30 hit
dice), Multiple Wishes (2-8 2d4),
Protection (the 7-row value table,
one mangled upload line: lo/hi
bands, AC 1/2/2/3/3/4/6, saves
1/2/2/3/3/2/1, radius rows 83+91,
5 foot saves-only radius),
Regeneration (1 hp per turn, the
01-90/91-00 vampiric split),
Shooting Stars (2 night modes,
dancing lights per hour, light per
night, ball lightning, the 2/4/7
inch missile functions, faerie fire
2/day + spark shower 1/day, 5
segments). The TREASURE (RINGS)
running page header at upload 10432
splits the ball lightning sentence
mid-stream - stripped per the R249
lesson. Upload drops the ball
lightning charge die bands - counts
only (4/3/2/1), no bands pinned.
THE CRITICAL DISCOVERY (ground truth
FIRST, as designed): the landed R223
rings.h ringIsChargeLimited flags
Protection (row 11) and NOT Mammal
Control (row 9) - but the R223 header
comment names Mammal Control, and the
part-2 prose has the double-dagger on
Mammal Control only. R254 pins the
prose, asserts ONLY the consistent
rows (7 Human Influence, 10 Multiple
Wishes, count 7), and documents the
divergence in the gap report as the
ranked fix candidate. R255 = the
dedicated fix round: swap rows 9/11
in rings.h AND in the R223 regtest
audit (the kChg array + per-index
asserts), flip the gap [~] note -
3 files changed. Battery: ground
truth ALL MATCH first run (61
scalars + 6 arrays; engine kRings
rows 16-63 vs R223 rings.h OK;
dagger cross-pins 7/10 OK;
divergence documented as landed
state); two-pass 4/0 -> 0/4 on
t1/t2/t3; REPRO-CLEAN byte-identical
across trees; audit_eval R254
verified bad 0 (29 asserts); full
sweep 49 verified all bad 0 (124
unverified = accepted engine class,
pristine baseline 48 - exactly +1);
both mutations RED single-site
(rgpBallLightningDiameterFeet 3->4,
rgpProtectionRowCount 7->8); fresh
rebuild t4 byte-identical GREEN;
DERIVED-CHECK ALL OK (61 scalars +
6 arrays = 67 refs 67/67, census
173, marker contiguous, brace depth
0/0, no apostrophe/backslash/double
comma; note: the derived-check gap
apostrophe scan must bound to the
R254 entry - the pre-existing
Categories legend carries an old
apostrophe). Splice advisory md5
(canvas body, 927 lines)
94d9f97242b11c3182c14fe304a9424b
(landed file
a2c10ed96c7a5fe8cb718da0284b32a6,
exactly the +1 newline - verified
by md5 arithmetic on the delivered
body); REAL GATE ringsprose2.h
136b33c0486ff4fb599ef772908c50aa
(499 lines); regtest
fde35be9757a51b61d0863fc01b8ba70;
gap report
3f26af5cc066eace07279a4267c010c6.
Census 172 -> 173 at 299d538.
Next: R255 - the rings.h
charge-limited fix round (swap rows
9/11 + the R223 audit block + the
gap note, 3 files changed), then
R256 - rings part 3 (~10458-10561:
Spell Storing d4+1 and the level
table, Spell Turning (3 exceptions,
the percentile tables, the
09-or-less/91-or-more save note),
Swimming (21 inch base, 50 foot
dive, 4 rounds), Telekinesis (the
weight table), Three Wishes (25%
limited), Warmth (+2 saves, -1 per
die), Water Walking, Weakness (1
point per turn to 3, the invisible
doubling, 5% berserk reversal),
Wizardry (the doubling table),
X-Ray Vision (20 feet, the
penetration depths)), then III.E
misc magic (part1 ~10948-11067
seamless into part2; global line =
part1 line or ~11065 + part2 line,
TREASURE (MISCELLANEOUS MAGIC)
headers are running page headers).
R255 landed the
ringIsChargeLimited fix (the R223
divergence resolved - DMG p.137
table, upload ~9590-9617: the
double-dagger rows are Djinni
Summoning, Human Influence, MAMMAL
CONTROL, Multiple Wishes,
Telekinesis, Three Wishes,
Wizardry; the landed array wrongly
flagged Protection row 11 instead
of Mammal Control row 9) in ONE
clean push 299d538 -> ac6b557 -
commit shape checked first: 5
files changed, 457 insertions,
24 deletions, tools/r255_splice.py
created. THE SCOPE: grew past the
planned 3 content files because
ringsprose2.h carries three
divergence comments (header
banner, Mammal Control dagger
flag, Protection dagger flag)
that would have gone stale - the
fix round leaves no fix-candidate
text behind. 9 patches: rings.h
ringIsChargeLimited array (row 9
0->1, row 11 1->0, count stays 7,
comment names the fix); the three
ringsprose2.h comments; regtest
R223 audit kChg array + the
truthy assert list now
2/7/9/10/17/18/22 + the negative
list gains 11; regtest R254 audit
NOTE rewritten, its cross-pin if
now asserts rows 9 and 11 both
ways; the gap divergence note
flipped to RESOLVED by R255; the
R255 gap log entry. No new audit
line; census stays 173. BATTERY
VALIDATED THE PROTOCOL TWICE: (1)
the ground truth run FIRST against
the pristine tree showed exactly
the 8 expected divergences, then
CAUGHT A REAL BUG in the first
splice draft - a dropped zero in
the array line (row 16 flagged,
row 18 cleared) - fixed before
delivery; (2) the first battery
run caught a wrapped post-
condition string (the R247 marker
lesson re-caught: count the
wrapped two-line form, not the
contiguous phrase). Also verified
by baseline comparison: assert
counts are if-statement based -
R223 stays 57 and R254 stays 29
(extended comparisons do not
change the count; the gap entry
was corrected before delivery).
Ground truth vs fixed tree ALL
MATCH (book table 24 rows parsed,
flags derived from the marks;
ringsprose2 dagger flags; count
comment names the seven; no stale
text). Two-pass 9/0 -> 0/9 on
t1/t2/t3; REPRO-CLEAN rings.h
064c2c017675143c3cc69294f0c6d819,
ringsprose2.h
b7c026b92e6c1b908222ebac0c4b1570,
regtest
aaa0622b5c70bee09f05aef9c06980d2,
gap report
7a57976dfde3603e3b3c72846a5080d1
- identical across trees;
audit_eval R223/R253/R254 all
verified bad 0 (57/22/29); full
sweep 49 verified all bad 0 (124
unverified, unchanged - no new
block); both mutations RED
single-site (rings.h row 9
reverted to 0: R223 bad 2 + R254
bad 1 - the fix is triple-guarded;
kChg row 11 reverted to 1: R223
bad 1 - the audit-vs-header
mismatch is caught); fresh rebuild
t4 byte-identical GREEN;
DERIVED-CHECK ALL OK (arrays ==
book want, truthy list
2/7/9/10/17/18/22, negative has
11, cross-pins 9/11, census 173,
R255 comments 1/3/2 across
rings.h/ringsprose2/regtest, no
stale fix-candidate text, no
apostrophes in the new spans).
Splice advisory md5 (canvas body,
370 lines)
186d223157d34e136e97fb537a94079d
(landed file
5a88ee802579e82ff3c957707bb53cb0,
exactly the +1 newline - verified
by md5 arithmetic). REAL GATE
rings.h
064c2c017675143c3cc69294f0c6d819;
also exact: ringsprose2.h
b7c026b92e6c1b908222ebac0c4b1570,
regtest
aaa0622b5c70bee09f05aef9c06980d2,
gap report
7a57976dfde3603e3b3c72846a5080d1.
Census stays 173 at ac6b557. THE
R223 DIVERGENCE STORY IS CLOSED:
found by the R254 ground truth
before any pin, documented as the
ranked fix candidate, fixed by
R255, asserted both ways by two
independent audit blocks. Next:
R256 - rings explanation prose
part 3 of 3 (~10458-10561: Spell
Storing d4+1 and the level table,
Spell Turning (3 exceptions, the
percentile tables, the
09-or-less/91-or-more save note),
Swimming (21 inch base, 50 foot
dive, 4 rounds), Telekinesis (the
weight table), Three Wishes (25%
limited), Warmth (+2 saves, -1 per
die), Water Walking, Weakness (1
point per turn to 3, the invisible
doubling, 5% berserk reversal),
Wizardry (the doubling table),
X-Ray Vision (20 feet, the
penetration depths)), then III.E
misc magic (part1 ~10948-11067
continuing seamlessly into part2;
global line = part1 line or
~11065 + part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers are
running page headers mid-
paragraph).
R256 landed the III.C rings
explanation prose part 3 of 3 (DMG
pp.139-140, upload ~10458-10561,
Spell Storing through X-Ray Vision)
in ONE clean push ac6b557 ->
1dcc2f0 - commit shape checked
first: 4 files changed, 1887
insertions, rules/ringsprose3.h and
tools/r256_splice.py created.
ringsprose3.h: the rgp prefix again,
89 accessors - 78 scalars + 11
array walkers (resonant 2,
telekinesis 3, wizardry 4, x-ray
2). THE SLICE: Spell Storing (2-5
d4+1, cleric d6-to-d4 on 6,
magic-user d8-to-d6 on 8, druid and
illusionist as cleric, the 12th
level MU restores 6th level example,
5 segments), Spell Turning (3
exceptions - area, touch, devices,
scroll is not a device; rounding
1-5 down 6-9 up, 05 = 0% and
96 = 100%; saves +1 per 10% below
100% (80% = +2 ... 10% = +9); the
09-or-less / 91-or-more band
excludes the special save; 5% per
10% turned, 11-19 needs 20; the
maze example 34% / 15% / 30% on
15-20; remove to receive; psionics
are not spell casting; the 4-row
resonating field table 01-70 /
71-80 / 81-97 / 98-00), Swimming
(21 inch base, 50 foot dive, 1.5
feet depth per 10 feet = 18 inches,
4 rounds breath, 4 hours + 1 hour
rest), Telekinesis (5-row weight
table 250/500/1000/2000/4000 gp,
1 segment, dagger flag), Three
Wishes (3 wishes, 25% 01-25
limited, dagger flag), Warmth (1
hp per turn, cold saves +2, -1 per
die), Water Walking (1200 pounds,
1.5 foot by 1 inch depressions per
100 pounds), Weakness (1 point
per turn to 3, invisible-at-will
doubles the loss, remove curse +
dispel magic, 5% berserk reversal
to 18s at 1 per turn then always
melee, rest 1 day per point),
Wizardry (8-row doubling table,
MU-only flag + dagger flag), X-Ray
Vision (20 feet, 5-substance
penetration table 4 feet / 2.5
feet / 1 foot / 1 inch / nil per
round with 20/20/10 feet / 10
inches / nil maxima, 100 sq ft per
round, 90% secret doors, 1 CON
drain more than once per 6 turns,
2 points at 3 turns per hour, 3 at
4, 2 points recovery per day,
exhausted at 2, resume at 3).
ENGINE CROSS-CHECK: kRings rows
64-100 vs the R223 band pins;
dagger cross-pins Telekinesis /
Three Wishes / Wizardry against
the R255-FIXED charge array;
Weakness (21) and X-Ray (23)
asserted unflagged - the III.C
rings section is now fully pinned
(R253 + R254 + R256 over the R223
tables, with the R255 fix
underneath). Upload notes: the
TREASURE (RINGS) page header at
10531 splits the Water Walking
paragraph mid-sentence (stripped,
the R249 lesson); the Spell
Turning damage example table is
mangled in the upload (only
fragment lines 2-8 / 2-12 /
5-20 / 4-48 survive) - the
rounding facts are pinned, the
dropped table is not. BATTERY:
the ground truth caught its own
parser before delivery - the
array() regex was greedy (it
swallowed comment digits and the
array dim); bound the capture to
the accessor closing brace and
re-extract the t[N] initializer.
Then ALL MATCH first run (78
scalars + 11 arrays; engine rows
14-23; dagger cross-pins 17/18/22
flagged, 21/23 unflagged). Two-pass
4/0 -> 0/4 on t1/t2/t3;
REPRO-CLEAN ringsprose3.h
99576a5795f168de5b535bb777113978
(599 lines), regtest
a6ae308c4ac7418087bd0d4edeeeaa6f,
gap report
5edf843b2e105ffe0c17dbf02ffd4e65
- identical across trees;
audit_eval R256 verified bad 0
(43 asserts); full sweep 50
verified all bad 0 (124
unverified, pristine baseline 49 -
exactly +1); both mutations RED
single-site (rgpSwimmingBaseSpeed
Inches 21->22, rgpTelekinesisRowGp
4000->4001); fresh rebuild t4
byte-identical GREEN; DERIVED-CHECK
ALL OK (78 + 11 = 89 refs 89/89,
census 174, marker contiguous,
brace depth 0/0, clean text).
Splice advisory md5 (canvas body,
1033 lines)
b0e68223d287a24d29c3bbf7ba7c1c28
(landed file
8fe13684ea807ec4e19cedefc7b6c7f3,
exactly the +1 newline - verified
by md5 arithmetic). REAL GATE
ringsprose3.h
99576a5795f168de5b535bb777113978;
regtest and gap report also exact.
Census 173 -> 174 at 1dcc2f0.
Next: III.E misc magic
explanations (part1 ~10948-11067
continuing seamlessly into part2;
global line = part1 line or
~11065 + part2 line, the TREASURE
(MISCELLANEOUS MAGIC) headers are
running page headers mid-
paragraph). NOTE: III.E needs the
first TWO-PART-FILE ground truth -
dmg-part1.md ends mid-section, the
prose continues in dmg-part2.md;
the ground truth must stitch the
seam explicitly and pin the
stitch line so the boundary
cannot drift.
- R257 landed 2026-10-08: commit
  28864b8, census 175, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 1 - the
  FIRST TWO-PART-FILE round. The
  seam pinned exactly: dmg-part1
  has 11067 lines, last content
  line 11065 ends IT HAS A 5%
  (Bag of Devouring mid-sentence);
  part2 line 1 is the TREASURE
  (MISCELLANEOUS MAGIC) page
  header, line 3 completes the
  sentence; the stitch is
  part1[11064] + space +
  part2[2]; global line = part1
  line or 11065 + part2 line.
  Slice: part1 10949-11065 plus
  the stitched completion - the
  section intro (not more than 2
  or 3 duplicates; books: a
  second wish for exact
  contents), Alchemy Jug (11
  liquids, 16 gallons salt water
  down to 4 drams cyanide; 1
  kind / 7 pourings per day),
  the four Amulets (Inescapable
  Location, Life Protection, the
  Planes 17-row + alt 22/23/24,
  Proof), Apparatus of Kwalish
  (900 feet), Arrow of
  Direction, Bag of Beans, Bag
  of Devouring (90/60/75 base,
  +1 = -5, str 18 65 / str 5
  80; 30 cubic feet; 5% per
  turn, 7 segments - the seam
  sentence). rules/miscprose1.h,
  mmp prefix, 65 accessors: 60
  scalars + 5 array walkers. The
  TABLE (III.E.) 1. header at
  10962 is a running page header,
  stripped (the R249 lesson).
  THE CATCH (ground truth FIRST
  earned its keep): the plan
  facts said kMisc1 has 36 rows
  and row 10 = Bag of Devouring
  (21,21) - the engine AND the
  printed III.E.1 table say 33
  rows; Bag of Devouring is row
  9 (21), row 10 is Bag of
  Holding (22-26), row 7 is the
  Artifact or Relic row. The
  splice audit was asserting all
  three wrong values (would have
  gone RED on Termux); fixed in
  the splice audit + gap entry
  before delivery. Also fixed
  in the ground truth: the
  split-tail artifact (split of
  11067 lines gives 11068
  elements - the count check now
  documents it), and a mutation
  sed that hit 7 return-5 sites
  (restored, then single-site by
  line number). BATTERY:
  two-pass 4/0 -> 0/4 on
  t1/t2/t3; REPRO-CLEAN
  miscprose1.h
  147f8e2947cdade3ec19c28e0d12abef,
  regtest
  28858dd2e9eaa737d7e43d6bf575a2e0,
  gap report
  bf4cc5866bcb7b912f62af57712b0339
  - identical across trees;
  groundtruth ALL MATCH (60
  scalars + 5 arrays; kMisc1
  rows 0-6/8/9 cross-checked;
  the seam stitch); audit_eval
  R257 verified bad 0 (48
  asserts); full sweep 51
  verified all bad 0 (124
  unverified, pristine baseline
  50 - exactly +1); both
  mutations RED single-site
  (mmpKwalishMaxDepthFeet
  900->901, mmpDevouring-
  SwallowPctPerTurn 5->6);
  fresh rebuild t4
  byte-identical GREEN;
  DERIVED-CHECK ALL OK (65 refs
  65/65, census 175, marker
  contiguous, brace depth 0/0,
  gap apostrophe scan bound to
  Categories:, the R254
  lesson). Splice advisory md5
  40230cd18a07c0073f9813d8f4223c4c
  (canvas body; NOTE the canvas
  platform re-quotes frontmatter
  and inserts a leading blank
  line after it - body minus
  that leading newline is the
  advisory; landed file
  da18a89bef15516fbccaaa718cf75286
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 28864b8 - landed splice,
  header, regtest and gap report
  all byte-exact). REAL GATE
  miscprose1.h
  147f8e2947cdade3ec19c28e0d12abef.
  Census 174 -> 175 at 28864b8
  (pushed 1dcc2f0..28864b8, 4
  files changed, 1343
  insertions, miscprose1.h +
  r257_splice.py created). Next:
  R258 III.E part 2 - Bag of
  Holding onward in part2 from
  line 5, global = 11065 +
  part2 line.
- R258 landed 2026-10-08: commit
  b430356, census 176, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 2 -
  part2 lines 5-66 (global =
  11065 + part2 line), Bag of
  Holding through Book of
  Exalted Deeds, all inside
  dmg-part2.md. NO page headers
  inside the slice - the nearest
  TREASURE page header is at
  part2 line 70, inside the Book
  of Infinite Spells section
  (R259 scope). rules/miscprose2.h
  (the mmp prefix again, 83
  accessors: 74 scalars + 9 array
  walkers, no name collisions
  with miscprose1.h): Bag of
  Holding (the 4-row quality
  table 01-30 15/250/30 through
  91-00 60/1500/250; overload or
  sharp pierce ruptures,
  contents lost in nilspace),
  Bag of Transmuting (one of the
  4 quality types, 2-5 proper
  uses, metals and gems to no
  worth, magic items to
  lead/glass/wood no save),
  Bag of Tricks (toss 1-20 feet,
  d10 type bands 1-5/6-8/9-0,
  8 animals each - ONLY the
  bands and counts pinned, the
  per-animal stat columns are
  mangled in the upload, the
  R256 lesson; 1 drawn at a
  time, slain or 1 turn then
  ordered back, 10 per week),
  Beaker of Plentiful Potions
  (2-5 doses of 2-5 potions,
  d4+1 count, 1 round pours of 1
  dose, delusion and poison
  possible, 2: 1/day 3/week,
  3: 1/day 2/week, 4-5: 1/week,
  1 type lost per month), Boat,
  Folding (box 12/6/6 inches,
  boat 10x4x2 with 1 pair of
  oars holds 3-4, ship 24x8x6
  with 5 oar sets carries 15,
  3 command words), Book of
  Exalted Deeds (1 week perusal,
  +1 wisdom halfway XP, neutral
  20,000-80,000, evil -1 level
  plus 50% for 2-5 adventures,
  MU -1 int or 2,000-20,000,
  thief 5-30 hp -1 dex 10-60%
  convert at wisdom 15, assassin
  5-40 hp, vanishes after
  perusal). ENGINE CROSS-CHECK:
  kMisc1 rows 10-15 (Holding
  22-26, Transmuting 27, Tricks
  28-29, Beaker 30-31, Boat 32,
  Exalted 33) plus the Exalted
  (C) class mark at row 15 with
  Boat row 14 as the negative
  control, against the R225 m1
  pins. BATTERY: the ground
  truth caught its own parser
  twice before any splice was
  written (the tricks-table
  segment split found the first
  Type header as its own
  boundary, [0,8,8]; the third
  table ran past the parse
  window, [8,8,4] - fixed by
  anchoring pos at the first
  header and widening the window
  to line 58). Then ALL MATCH
  first run on t1 and t4 (74
  scalars + 9 arrays; the audit
  tables OK). Two-pass 4/0 -> 0/4
  on t1/t2/t3; REPRO-CLEAN
  miscprose2.h
  99fae07999882cdcb375f860adbd76b4,
  regtest
  a45b5591f9af2e7839d0be6d6791ca2f,
  gap report
  865c02e673617f7bdcea91b72be350d1
  - identical across trees;
  audit_eval R258 verified bad 0
  (25 asserts); full sweep 52
  verified all bad 0 (124
  unverified, pristine baseline
  51 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (mmpBoatShipPersons
  15->16, mmpExaltedNeutral-
  XpLossMax 80000->80001 - both
  also caught by the ground
  truth); fresh rebuild t4
  byte-identical GREEN;
  DERIVED-CHECK ALL OK (83 refs
  83/83, census 176, marker
  contiguous, brace depth 0/0,
  no collisions with part 1, gap
  apostrophe scan bound to
  Categories:). Splice advisory
  md5 032d2fec44e7ccbdea5cf4a289fc8361
  (canvas body; the platform
  again re-quotes frontmatter
  and inserts a leading blank
  line after it - body minus
  that leading newline is the
  advisory); landed file
  edadb0e3cb6816d0f798076765f5c9a5
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at b430356 - landed splice,
  header, regtest and gap report
  all byte-exact; audit_eval on
  the landed tree GREEN. REAL
  GATE miscprose2.h
  99fae07999882cdcb375f860adbd76b4.
  Census 175 -> 176 at b430356
  (pushed 28864b8..b430356, 4
  files changed, 1609
  insertions, miscprose2.h +
  r258_splice.py created). Next:
  R259 III.E part 3 - Book of
  Infinite Spells onward in
  part2 from line 67 (global =
  11065 + part2 line; the
  TREASURE page header at line
  70 splits its page table,
  strip it per the R249 lesson;
  the page-turn chance table and
  Book of Vile Darkness follow).
- R259 landed 2026-10-08: commit
  5f73ec0, census 177, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 3 -
  part2 lines 67-108 (global =
  11065 + part2 line), Book of
  Infinite Spells through Boots
  of Striding and Springing. TWO
  page headers inside the slice,
  both stripped (the R249
  lesson): line 70 splits the
  page table from the Infinite
  Spells intro, line 102 splits
  the Boots of Levitation
  paragraph mid-sentence - the
  seam pinned exactly (line 100
  ends the ascent/descent speed
  phrase, line 104 continues
  ROUND (MINUTE); the stray
  table-title line 83 is a
  duplicated header, noted not
  pinned). rules/miscprose3.h
  (the mmp prefix again, 76
  accessors: 73 scalars + 3
  array walkers, no name
  collisions with parts 1-2):
  Book of Infinite Spells (5-20
  hp, d12 for magic-user, 8-10 /
  10-12 reroll to d6 / d8; 1
  cast per day, 4 if already
  castable; the 10/20/25/30
  page-turn ladder; vanishes at
  the last page), Book of Vile
  Darkness (1 week, +1 wisdom
  halfway XP; neutral
  30,000-120,000 or turn evil,
  50% either; good clerics 2
  saves then 250,000 less 10,000
  per wisdom; other good 5-30 hp
  with 80% night hag; neutral
  5-20 hp), Boots of Dancing
  (the other 4 useful types
  until melee or fleeing, AC
  penalty 4, remove curse only),
  Boots of Elvenkind (95% worst,
  100% best), Boots of
  Levitation (20 inches per
  round; d20 in 14 pound
  increments over 280 base, 294
  to 560), Boots of Speed (24
  inch base, 1 inch per 10
  pounds over 200, the 180/60
  example at 20, the 500 coin
  sack at 5, 1 rest hour per
  move hour, 8 hours max, AC
  +2), Boots of Striding and
  Springing (12 inch base, 12
  hours + 12 recharge; 3 foot
  paces, 30/9/15 jumps; 20%
  stumble less 3% per dex above
  12, the 17/14/11/8/5/2
  ladder; AC +1). ENGINE
  CROSS-CHECK: kMisc1 rows
  16-22 (Infinite 34, Vile 35,
  Dancing 36, Elvenkind 37-42,
  Levitation 43-47, Speed
  48-51, Striding 52-55) plus
  the Vile (C) class mark at
  row 17 with Infinite row 16
  as the negative control,
  against the R225 m1 pins.
  BATTERY: the ground truth
  caught its own parser-bug
  class once before delivery -
  the rows 16-22 gap-phrase
  check assumed contiguous text
  across the ~30-char house
  wrapping (the gap report wraps
  between rows and 16-22);
  fixed by flattening the gap
  entry with whitespace
  normalization before the
  phrase check. Then ALL MATCH
  first run on t1 and t4 (73
  scalars + 3 arrays). Two-pass
  4/0 -> 0/4 on t1/t2/t3;
  REPRO-CLEAN miscprose3.h
  1e46efec47bbffee1129574ac9335614,
  regtest
  af285a14e6f00e98a4784f55602de68c,
  gap report
  5b23de12aed57d75d5170fb01b0ebbc7
  - identical across trees;
  audit_eval R259 verified bad 0
  (27 asserts); full sweep 53
  verified all bad 0 (124
  unverified, pristine baseline
  52 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER
  (mmpLevitationSpeedInchesPerRound
  20->21, mmpStridingStumbleBasePct
  20->21 - the first sed hit
  line 295, a comment line, and
  changed nothing; the
  diff-vs-t1 single-site check
  caught it at once and the
  retry on 296 verified); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN (76
  accessors, marker contiguous,
  census 177, include after the
  R258 line, no collisions with
  parts 1-2, gap apostrophe
  scan bound to Categories:).
  Splice advisory md5
  73ebc959325a764bbd7788998e0075c8
  (canvas body byte-for-byte);
  landed file
  50e930b6602904a2086e3c963f01b5e1
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 5f73ec0 - landed splice,
  header, regtest and gap report
  all byte-exact, miscprose2.h
  unchanged, audit_eval on the
  landed tree GREEN. REAL GATE
  miscprose3.h
  1e46efec47bbffee1129574ac9335614.
  LANDING NOTES: preflight was
  initially skipped mid-ritual -
  harmless, preflight is
  order-independent as long as
  it runs before the commit
  (R259 ran it after the header
  gate, before the push); one
  pasted ritual line carried the
  prompt prefix and bash
  reported a directory error,
  also harmless - LESSON: the
  R260 ritual block goes out
  prompt-free (commands only)
  so the whole block can be
  pasted in one go. Census
  176 -> 177 at 5f73ec0 (pushed
  b430356..5f73ec0, 4 files
  changed, 1431 insertions,
  miscprose3.h + r259_splice.py
  created). Next: R260 III.E
  part 4 - Bowl Commanding Water
  Elementals onward in part2
  from line 110 (global 11175).
- R260 landed 2026-10-08: commit
  b5c0b23, census 178, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 4 -
  part2 lines 110-153 (global =
  11065 + part2 line), Bowl
  Commanding Water Elementals
  through Bucknard Everfull
  Purse - completing the kMisc1
  table rows 23-32. ONE page
  header inside the slice
  (line 127, the TREASURE page),
  stripped (the R249 lesson);
  no mid-sentence seam.
  rules/miscprose4.h (the mmp
  prefix again, 53 accessors:
  48 scalars + 5 array walkers,
  no name collisions with parts
  1-3): Bowl Commanding Water
  Elementals (12 HD; words 1
  round; fresh or salt; salt +2
  per die, max 8 hp per die;
  1 foot across, half deep),
  Bowl of Watery Death (save
  versus magic or shrunk to ant
  size; salt save at minus 2;
  drowns in 3-8 rounds; freed
  only by animal growth,
  enlarge or wish; growth potion
  the same; sweet water another
  save; death permanent, even a
  wish fails), Bracers of
  Defense (the 7-row AC table
  01-05:8 through 86-00:2;
  useless with armor, stack
  with other protections),
  Bracers of Defenselessness
  (serves until attacked in
  anger by a dangerous enemy;
  AC 10, negates all
  protections and dex bonuses;
  remove curse only), Brazier
  Commanding Fire Elementals
  (12 HD; fire lit 1 round;
  sulphur +1 per die, 2-9 hp per
  die), Brazier of Sleep Smoke
  (1 inch radius cloud; save or
  deep sleep; a 12 HD fire
  elemental attacks the nearest
  creature; dispel magic or
  remove curse awakens), Brooch
  of Shielding (90% without
  gems; absorbs 101 hp of magic
  missile damage, then melts),
  Broom of Animated Attack
  (loop-the-loop dumps the
  rider 6-9 feet; attacks
  twice per round as a 4 HD
  monster; straw end blinds 1
  round; handle 1-3 damage; AC
  7, 18 hp to destroy), Broom
  of Flying (30 inch speed; 182
  pounds; 14 pounds per 1 inch
  slow; 30 degree climb or
  dive; fetches at 30 inches),
  Bucknard Everfull Purse (26
  coins per type the next
  morning; the 3 type bands
  01-50 / 51-90 / 91-00;
  emptied kills the magic; gems
  base 10 gp max 100 gp;
  abilities never change; the
  spice design note - the
  mangled coin columns noted
  not pinned, the R256 lesson).
  ENGINE CROSS-CHECK: kMisc1
  rows 23-32 (Bowl Cmd 56-58,
  Watery 59, Bracers 60-79,
  Defenseless 80-81, Brazier
  Fire 82-84, Sleep Smoke 85,
  Brooch 86-92, Broom Attack
  93, Broom Fly 94-98, Purse
  99-00) plus the (M) class
  marks on the two Bowls and
  two Braziers against the R225
  m1 pins. ENGINE FIX (the
  ground-truth pass found it
  BEFORE any splice ran): the
  R225 per-AC asterisk
  off-by-one - m1IsPerAcPoint
  Valued flagged row 26 (80-81
  Defenselessness) and its R225
  audit agreed with itself, but
  the printed asterisk row is
  60-79 Bracers of Defense
  (row 25, part1 line 9706:
  500-star / 3,000-star; the
  Defenselessness row is flat
  2,000). The splice moved the
  flag to row 25, fixed the R225
  audit kBrac table and its
  direct assertions (26/27 to
  25/26), and the R260 audit
  pins the printed AC 6 example
  (2000 xp / 12000 gp, four
  points above 10). LESSON:
  when an engine table and its
  audit agree with each other,
  verify BOTH against the
  printed table before trusting
  either. BATTERY: the ground
  truth caught its own bugs
  first (band edges 00 parsed as
  0 not 100; the purse can
  contain: title lives at the
  tail of line 141 not on its
  own line; the assertion-pair
  check matched the R260 audit
  block too - scoped to exact
  two-line pairs; and an
  assistant part1 line-number
  off-by-one caught by direct
  string dump). Then ALL MATCH
  first run on t1 and t4 (48
  scalars + 5 arrays). Hygiene
  caught 4 implicit
  string-concat list elements
  spanning lines - flattened to
  one line each before the
  battery. Two-pass 7/0 -> 0/7
  on t1/t2/t3; REPRO-CLEAN
  miscprose4.h
  aaddbd87dbcc000b483c4c02f7409f40,
  miscmagic1.h
  05987e7509049aa810404276eead58ee,
  regtest
  bdcf4eb8136af8faf0363a216f1002c5,
  gap report
  0f2a13201194e6fd49e8d5f85ff11185
  - identical across trees;
  audit_eval R260 verified bad 0
  (32 asserts), R225 still
  GREEN post-fix; full sweep 54
  verified all bad 0 (124
  unverified, pristine baseline
  53 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (mmpBroochAbsorbHp
  101->102, mmpBroomFlyCapacity
  Pounds 182->183); fresh rebuild
  t4 byte-identical; DERIVED-CHECK
  GREEN (53 accessors, census
  178, include after R259, no
  collisions parts 1-3, the flag
  and kBrac agree on row 25).
  Splice advisory md5
  9b00de657743f17f48ef29561b9d476b
  (canvas body byte-for-byte);
  landed file
  4cb1ba4bb01a08f90112bc4d5d284288
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at b5c0b23 - landed splice,
  miscprose4.h, miscmagic1.h,
  regtest and gap report all
  byte-exact; audit_eval on the
  landed tree GREEN (R260, R225,
  sweep 54). REAL GATE
  miscprose4.h
  aaddbd87dbcc000b483c4c02f7409f40.
  The prompt-free paste-safe
  ritual block (no ~/Adnd1 dollar
  prefixes) worked first try.
  Census 177 -> 178 at b5c0b23
  (pushed 5f73ec0..b5c0b23, 5
  files changed, 1273
  insertions, 4 deletions,
  miscprose4.h + r260_splice.py
  created). Next: R261 III.E
  part 5 - Candle of Invocation
  onward in part2 from line 155
  (global 11220; the TABLE
  (III.E.) 2. header at 155 and
  the TREASURE header at 159
  both strip; the Candle seam:
  line 157 ends one of the, line
  161 continues nine
  alignments).

- R261 landed 2026-10-08: commit
  c0ffe76, census 179, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 5 -
  part2 lines 155-220 (global =
  11065 + part2 line), Candle of
  Invocation through Cloak of
  Protection - completing the
  kMisc2 table rows 0-10. THREE
  page headers inside the slice
  (155 TABLE (III.E.) 2., 159
  and 183 both the TREASURE
  page), all stripped; TWO
  seams pin exactly: the Candle
  (line 157 ends one of the,
  line 161 continues nine
  alignments) and the Cloak of
  Displacement (line 180 ends
  with such as spells,, line 185
  continues gaze weapon
  attacks). rules/miscprose5.h
  (the mmp prefix, 60 accessors:
  50 scalars + 10 array walkers,
  no name collisions with parts
  1-4): Candle of Invocation
  (4 hours; aligned 25 percent
  bonus, opposing 25 penalty on
  saves/contact; invokes a
  4 HD aligned elemental for 6
  turns if the cone is broken),
  Censer of Air (summons a 12 HD
  air elemental 6 turns; whirl
  sweep melee once), Censer of
  Water (12 HD water elemental 6
  turns), Chime of Opening (20
  to 80 charges, 20 + d6 x 10;
  knocks per a knock spell,
  stuck at higher level counts
  multiple d6), Chime of
  Weather (cumulative -2 saves
  after 3+ sounds), Cloak of
  Displacement (projected image
  2 to 5 feet; attacks against
  the wearer roll as though
  1 inch - actually 2 - 5 feet
  farther away; the mental save
  tier pins), Cloak of Elvenkind
  (95 percent unseen stationary,
  moving -5 percent per 10 feet
  moved; -10 percent per
  additional viewer), Cloak of
  Manta Ray (swim 18, breathe
  water freely; no armor
  penalties underwater), Cloak
  of Poisonousness (save versus
  poison or die; revive 1-4
  turns inside an hour, raise
  dead -30 percent, restoration
  -30 percent if revived;
  neutralize poison no effect,
  remove curse destroys), Cloak
  of Protection (the 3-plus AC
  shield band, 500-star / 1000
  / 2000 gp per plus ... the
  per-plus table pinned via
  mmpCloakPerPlusXp 1000 / gp
  10000). ENGINE CROSS-CHECK:
  kMisc2 rows 0-10 lo 1, 7, 9,
  11, 12, 14, 15, 19, 28, 31,
  33 hi 6, 8, 10, 11, 13, 14,
  18, 27, 30, 32, 55 - the (C)
  mark on the Candle (row 0),
  the (M) marks on the two
  Censers (rows 2, 3), and the
  per-plus asterisk on row 10
  (Cloak of Protection 33-55)
  all VERIFIED CORRECT - the
  R226 pin already sat on row
  10, no R260-style off-by-one
  fix this round. The R261
  audit cross-pins the +2 cloak
  example (1000 xp / 10000 gp
  per plus -> 2000 / 20000).
  BATTERY: ground truth first
  (parser bugs caught before
  the splice: bandhi 00 edges
  parsed as 0 not 100; ordinal
  regex needed st nd rd th; the
  manta em-dash is U+2014 not
  the minus U+2212; one bracket
  typo). ALL MATCH first run on
  t1 and t4. Hygiene clean
  (apostrophes 0, backslashes 0,
  list-comma bad 0). Two-pass
  4/0 -> 0/4 on t1 t2 t3;
  REPRO-CLEAN miscprose5.h
  267498c3ec2feb19c8d823e8c3d458fc
  (identical t1 t2 t3), regtest
a9e92010ab713746a3bc14126093d50e,
  gap report
38b1e95b213f083782ad274f82f0d01b;
  audit_eval R261 verified bad 0;
  full sweep 55 verified all bad
  0 (124 unverified, pristine
  baseline 54 - exactly +1);
  both mutations RED single-site
  by LINE NUMBER (mmpCandleBurn-
  Hours 4->5 line 39,
  mmpChimeOpenChargesMax 80->81
  line 124, diff-verified vs t1,
  both verified bad 1); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (60 accessors contiguous, no
  collisions parts 1-4, census
  179, include after R260, gap
  entry apostrophe scan bounded
  to Categories:). Splice
  advisory md5
  4129006b61777f61be3c23116bcb7198
  (canvas body byte-for-byte);
  landed file
  75ee985f0f186151fea71a3c04fe4ddb
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at c0ffe76 - landed splice,
  miscprose5.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R261 bad 0, sweep 55).
  REAL GATE miscprose5.h
267498c3ec2feb19c8d823e8c3d458fc.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 178 -> 179 at c0ffe76
  (pushed b5c0b23..c0ffe76, 4
  files changed, 1393
  insertions, miscprose5.h +
  r261_splice.py created). Next:
  R262 III.E part 6 - Crystal
  Ball onward in part2 from
  line 222 (global 11287; the
  Crystal Ball locating chance
  table and the Crystal
  Hypnosis Ball follow; the
  double-asterisk feature row
  56-60 is R226-pinned).

- R262 landed 2026-10-08: commit
  8082cab, census 180, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 6 -
  part2 lines 222-283 (global =
  11065 + part2 line), Crystal
  Ball and Crystal Hypnosis Ball
  - completing the kMisc2 rows
  11-12. ONE page header inside
  the slice (279, the TREASURE
  page), stripped. The slice is
  table-dense: the locating
  chance table (well known 100,
  slightly 85, pictured 50, part
  50, garment 25, informed 25,
  slightly informed 20, other
  plane -25), the viewing period
  table (1 hour 3 times a day
  down to 1/6 hour once), the
  additional powers table (01-50
  plain, 51-75 clairaudience,
  76-90 ESP, 91-00 telepathy,
  communication only), the
  notice-by-class table (Fighter
  2, Thief 6, Paladin 6,
  Assassin 5, Ranger 4, Monk 1,
  Bard 3). Spell function 10th
  level; notice needs int 12 or
  better; the int ladder 1, 3,
  6, 10, 15, 21 at int 13-18
  plus 1 percent per level;
  dispel magic shuts the ball 1
  day; spell-user detection uses
  the page 60 table; clerics and
  druids may take water basin or
  mirror scriers. Crystal
  Hypnosis Ball: cursed,
  indistinguishable, radiates
  magic not evil; the gazer gets
  a telepathic suggestion and
  slides under the influence
  (magic-user, lich, or
  other-planar power; servant,
  tool, or possession object),
  gradual or sudden at the
  referee call.
  rules/miscprose6.h (the mmp
  prefix, 45 accessors: 36
  scalars + 9 array walkers, no
  name collisions with parts
  1-5). ENGINE CROSS-CHECK:
  kMisc2 rows 11-12 (Crystal
  Ball lo 56 hi 60, Hypnosis lo
  61 hi 61), the (M) marks on
  both rows (negative controls
  rows 10 and 13), and the
  double-asterisk row 11 all
  VERIFIED CORRECT - the R226
  pin already sat on row 11, no
  off-by-one fix this round. The
  R262 audit cross-pins the
  ball values: 1000 xp / 5000 gp
  base, +100 percent per
  additional feature -
  clairaudience 2000/10000, ESP
  3000/15000, telepathy
  4000/20000. BATTERY: ground
  truth first (144 checks; the
  parser bug caught before the
  splice: the feature table has
  its | --- | separator INSIDE
  the slice, the row scan had to
  skip it). ALL MATCH first run
  on t1 and t4; pristine shows
  only the documented
  missing-header fail. Hygiene
  clean (apostrophes 0,
  backslashes 0, list-comma bad
  0). Two-pass 4/0 -> 0/4 on t1
  t2 t3; REPRO-CLEAN
  miscprose6.h
9f8ec0b0bc298676438c6f0953e816ac,
  regtest
38e22d94cbdf0ad98e9194098b7cd759,
  gap report
  594eadf30fd3d8fc5f79557e8233ff92
  - identical across trees;
  audit_eval R262 verified bad 0;
  full sweep 56 verified all bad
  0 (124 unverified, pristine
  baseline 55 - exactly +1);
  both mutations RED single-site
  by LINE NUMBER
  (mmpCrystalBallLocatingKnown-
  SlightlyPct 85->86 line 43,
  mmpCrystalBallSpellFunction-
  Level 10->11 line 114,
  diff-verified vs t1, both
  verified bad 1); fresh rebuild
  t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (45 accessors contiguous, no
  collisions parts 1-5, census
  180, include after R261, gap
  entry apostrophe scan bounded
  to Categories:). Splice
  advisory md5
  6e3c414ce63f1709ea9a849509dd687b
  (canvas body byte-for-byte);
  landed file
  5c2824a68c27b3ba6318e1c49a93645f
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 8082cab - landed splice,
  miscprose6.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R262 bad 0, sweep 56).
  REAL GATE miscprose6.h
9f8ec0b0bc298676438c6f0953e816ac.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 179 -> 180 at 8082cab
  (pushed c0ffe76..8082cab, 4
  files changed, 1131
  insertions, miscprose6.h +
  r262_splice.py created). Next:
  R263 III.E part 7 - Cube of
  Force onward in part2 from
  line 285 (global 11350; the
  cube of force 36-charge
  restore-daily face table and
  the attack-form surcharge
  table follow; the cube sits on
  kMisc2 row 13, 62-63).

- R263 landed 2026-10-08: commit
  f128b7d, census 181, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 7 -
  part2 lines 285-322 (global =
  11065 + part2 line), Cube of
  Force through Decanter of
  Endless Water - completing the
  kMisc2 rows 13-17. ZERO page
  headers inside the slice (a
  first); ONE seam pins exactly
  (the Daern: line 314 ends but
  the person or, line 316
  continues persons nearby).
  rules/miscprose7.h (the mmp
  prefix, 45 accessors: 42
  scalars + 3 array walkers, no
  name collisions with parts
  1-6): Cube of Force (36
  charges restored daily; wall
  of force 1 inch per side; the
  6-face table 1/1, 2/8, 3/6,
  4/4, 6/3, 0/normal; the
  14-form attack surcharge table
  catapult-like 1 through wall of
  fire 2, row-major print order;
  no casting into or out; hard
  mineral, ivory or bone), Cube
  of Frost Resistance (65
  degrees F inside; absorbs cone
  of cold, ice storm, dragon
  breath; over 50 hp of cold per
  turn collapses it, renews
  after 1 hour, over 100 hp
  destroys it; minus 40 F
  withstands only 42 hp - the
  2-per-minus-10 math), Cubic
  Gate (carnelian; 6 sides, 1
  always Prime Material, 5
  chosen; 1 press opens a nexus,
  10 percent per turn something
  comes through; 2 presses draw
  all within 5 feet; max 1
  link), Daern Instant Fortress
  (20 foot square, 30 high, 10
  into ground; owner-only door,
  knock notwithstanding; walls
  ignore all but catapults; 200
  hp collapse, damage
  cumulative, wish restores 10;
  springs up in 1 round, the
  growth catches for 10-100 hp),
  Decanter of Endless Water
  (stream 1 gallon per round,
  fountain 5 foot at 5, geyser
  20 foot at 30; fresh or salt
  as ordered; geyser knocks the
  holder over and kills small
  animals; ceases on command).
  ENGINE CROSS-CHECK: kMisc2
  rows 13-17 (62-63, 64-65,
  66-67, 68-69, 70-72) and the
  NEGATIVE-CONTROL stretch - no
  (C), no (M), no asterisk rows
  on 13-17; row 12 still carries
  its (M) as the positive
  control. BATTERY: ground truth
  first (161 checks; the print
  parsed clean; the one bug was
  MINE - the R263 gap-tail
  anchor was guessed from memory
  instead of read from the
  landed R262 gap report, and the
  splice assertion caught it;
  LESSON: always grep the landed
  tail, never reconstruct it).
  t1 needed a recovery run
  (applied 1, already 3 after the
  fixed splice) but converged;
  ALL MATCH on t1 and t4;
  pristine shows only the
  documented missing-header fail.
  Hygiene clean (apostrophes 0,
  backslashes 0, list-comma bad
  0). Two-pass 4/0 -> 0/4 on t2
  t3; REPRO-CLEAN miscprose7.h
4cb7898fdaea218049ae8af346b60cef,
  regtest
9b25623bd94a5e8a157292e2e092be87,
  gap report
  5511fa02259627b39af16df71c94b208
  - identical across trees;
  audit_eval R263 verified bad 0;
  full sweep 57 verified all bad
  0 (124 unverified, pristine
  baseline 56 - exactly +1);
  both mutations RED single-site
  by LINE NUMBER
  (mmpCubeForceCharges 36->37
  line 29, mmpCubeFrostTempF
  65->66 line 64, diff-verified
  vs t1, both verified bad 1);
  fresh rebuild t4
  byte-identical; DERIVED-CHECK
  GREEN on t1/t4 (45 accessors
  contiguous, no collisions parts
  1-6, census 181, include after
  R262, gap entry apostrophe scan
  bounded to Categories:).
  Splice advisory md5
  c4fe4ed7d9692a864fc7b780993800d5
  (canvas body byte-for-byte);
  landed file
  e6125c2b59c422a167efc03c6eb50489
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at f128b7d - landed splice,
  miscprose7.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R263 bad 0, sweep 57).
  REAL GATE miscprose7.h
4cb7898fdaea218049ae8af346b60cef.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 180 -> 181 at f128b7d
  (pushed 8082cab..f128b7d, 4
  files changed, 981 insertions,
  miscprose7.h + r263_splice.py
  created). Next: R264 III.E
  part 8 - Deck of Many Things
  onward in part2 from line 324
  (global 11389; the 22-plaque
  table and the per-plaque
  explanations follow; the deck
  sits on kMisc2 row 18, 73-76).

- R264 landed 2026-10-08: commit
  2333240, census 182, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 8 - the
  Deck of Many Things, part2
  lines 324-400 (global =
  11065 + part2 line), pinning
  kMisc2 row 18, 73-76, no
  class marks. 48 accessors (45
  scalars + 3 walkers
  mmpDeckPlaqueAsterisk,
  BoldFace, Discarded, all
  t[22]). ONE page header strips
  (360 TREASURE); ZERO
  mid-sentence seams - a first.
  Ground truth caught a row-26
  assistant index error
  pre-splice (the fifth M mark
  is Eyes of Charming row 26,
  not 25); the print was clean.
  Lesson: audit_eval supports
  ONLY single-if for-loops - no
  braced bodies, no ++ counters
  (the first splice draft had
  both; fixed to static-table
  comparisons + a 13+9==22
  arithmetic check, and hygiene
  then caught an orphaned nstar
  fragment and a 2-line printf
  string concat). Battery:
  groundtruth ALL MATCH t1 (162
  checks), pristine only the
  documented missing-header
  fail; hygiene 0/0/0; two-pass
  4/0 -> 0/4 on t1 t2 t3;
  REPRO-CLEAN miscprose8.h
efe40bd8e4b35da7f6419c69ffdccaab,
  regtest
b61a6d614432d45b8a12e5e1590a699e,
  gap report
1971733bb9c90aecbe99d407c26c7c09
  - identical across trees;
  audit_eval R264 verified bad 0
  (30 asserts); full sweep 58
  verified all bad 0 (124
  unverified, pristine baseline
  57 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (Sun 50000->50001
  line 84, Skull hp 33->34 line
  219, diff-verified vs t1, both
  verified bad 1); fresh rebuild
  t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (48 accessors, no collisions
  parts 1-7, census 182, include
  after R263, gap entry apostrophe
  scan bounded to Categories:).
  Splice advisory md5
284a84e0e5c81f01879e343f2aa5d02f
  (canvas body byte-for-byte);
  landed file
0d3114e57c3c78c10bd6be46385815b7
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 2333240 - landed splice,
  miscprose8.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R264 bad 0, sweep 58).
  REAL GATE miscprose8.h
efe40bd8e4b35da7f6419c69ffdccaab.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 181 -> 182 at 2333240
  (pushed f128b7d..2333240, 4
  files changed, 1005 insertions,
  miscprose8.h + r264_splice.py
  created). Next: R265 III.E
  part 9 - Drums of Deafening
  onward in part2 from line 402
  (global 11467; the two drums,
  the four dusts, the bottles
  and the eyes follow; rows 19+).

- R265 landed 2026-10-08: commit
  22f84b5, census 183, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 9 -
  Drums of Deafening through Eyes
  of Petrification plus the
  eye-mix note, part2 lines
  402-429 (global = 11065 +
  part2 line), pinning kMisc2
  rows 19-29 - the slice that
  COMPLETES the 30-row table
  (Candle of Invocation through
  Eyes of Petrification). ONE
  page header strips (417, the
  TREASURE page) cutting the
  Eversmoking Bottle paragraph
  mid-sentence (one seam,
  restored). The R264 pointer
  said four dusts; the print
  shows three (Appearance,
  Disappearance, Sneezing and
  Choking). 50 scalar accessors
  (no walkers this round), no
  collisions parts 1-8. Engine
  rows 19-29: 77, 78-79, 80-85,
  86-91, 92, 93, 94, 95, 96-97,
  98-99, 100; only Eyes of
  Charming carries (M); row 29
  the triple star. Battery:
  groundtruth ALL MATCH t1 (163
  checks), pristine only the
  documented missing-header
  fail; hygiene 0/0/0; two-pass
  4/0 -> 0/4 on t1 t2 t3;
  REPRO-CLEAN miscprose9.h
16751d1bf1a4feea987ece9ca95bd9e3,
  regtest
495a2217deaa5e22bc6ab8cf7701722b,
  gap report
278dac8881bb21103714a306c6017ac1
  - identical across trees;
  audit_eval R265 verified bad 0
  (36 asserts); full sweep 59
  verified all bad 0 (124
  unverified, pristine baseline
  58 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (Eversmoke first
  round 50000->50001 line 189,
  max 120000->120001 line 199,
  diff-verified vs t1, both
  verified bad 2 - each scalar
  feeds its direct assert AND
  the arithmetic cross-check);
  fresh rebuild t4
  byte-identical; DERIVED-CHECK
  GREEN on t1/t4 (50 accessors,
  no collisions parts 1-8,
  census 183, include after
  R264, gap entry 100 lines,
  apostrophe scan bounded to
  Categories:). Splice advisory
  md5
f329d054cbffb1d47f57922a8bc355da
  (canvas body byte-for-byte);
  landed file
ec21fa19a3982114ed5d4748a0e18a0d
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 22f84b5 - landed splice,
  miscprose9.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R265 bad 0, sweep 59).
  REAL GATE miscprose9.h
16751d1bf1a4feea987ece9ca95bd9e3.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 182 -> 183 at 22f84b5
  (pushed 2333240..22f84b5, 4
  files changed, 1077 insertions,
  miscprose9.h + r265_splice.py
  created). Next: R266 III.E
  part 10 - Figurines of
  Wondrous Power onward in
  part2 from line 433 (global
  11498; TABLE III.E. 3, the
  kMisc3 rows, begins; the
  figurines, gauntlets and
  girdles follow).

- R266 landed 2026-10-08: commit
  552720e, census 184, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 10 -
  Figurines of Wondrous Power,
  part2 lines 433-479 (global =
  11065 + part2 line), pinning
  the kMisc3 row 0 (the Figurine
  band 01-15, the single asterisk,
  per hit die values 100 xp /
  1000 gp, no class marks). ONE
  page header strips (477, the
  TREASURE page) cutting the
  Serpentine Owl paragraph
  mid-sentence (one seam,
  restored); the compilation also
  wraps the Goat of Travelling
  paragraph at a bare blank line
  (450/452, no page header) - a
  wrap artifact, restored. The
  figurine type table: 01-15
  ebony fly, 16-30 golden lions,
  31-40 ivory goats, 41-55 marble
  elephant, 56-65 obsidian steed,
  66-85 onyx dog, 86-00
  serpentine owl. 90 accessors:
  86 scalars + 4 walkers (the
  figurine type and elephant type
  tables), every accessor audited
  (the audit/HDR set equality is
  now a derived_check invariant),
  no collisions parts 1-9. The
  travail charge arithmetic: the
  horn plus the +6 bonus equals
  the printed 8-18. Battery:
  groundtruth ALL MATCH t1 (132
  checks), pristine only the
  documented missing-header
  fail; hygiene 0/0/0; two-pass
  4/0 -> 0/4 on t1 t2 t3;
  REPRO-CLEAN miscprose10.h
a27f8bd7fa59ea23fe3c0bdc7db891bd,
  regtest
5cc56d1f6a52d1693870208faed924d7,
  gap report
ae9a1385c2c551cb1f5509aa452d9a82
  - identical across trees;
  audit_eval R266 verified bad 0
  (35 asserts); full sweep 60
  verified all bad 0 (124
  unverified, pristine baseline
  59 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (Travail hp 96->97
  line 261, Fly laden 210->211
  line 91, diff-verified vs t1,
  both verified bad 1); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (90 accessors, census 184,
  include after R265, gap entry
  114 lines, apostrophe scan
  bounded to Categories:).
  Splice advisory md5
606bee6d4dccb834c3aac65f0ae81243
  (canvas body byte-for-byte);
  landed file
9e6718b7423f76eaaa8e97c3713274e7
  = advisory + the 1 newline,
  verified by md5 arithmetic AND
  by fetching the landed tarball
  at 552720e - landed splice,
  miscprose10.h, regtest and gap
  report all byte-exact;
  audit_eval on the landed tree
  GREEN (R266 bad 0, sweep 60).
  REAL GATE miscprose10.h
a27f8bd7fa59ea23fe3c0bdc7db891bd.
  The prompt-free paste-safe
  ritual block worked first try.
  Census 183 -> 184 at 552720e
  (pushed 22f84b5..552720e, 4
  files changed, 1625 insertions,
  miscprose10.h + r266_splice.py
  created). Next: R267 III.E
  part 11 - Flask of Curses
  onward in part2 from line 481
  (global 11546; the gauntlets,
  gems, girdles and helms follow;
  kMisc3 rows 1+).
- R267 landed 2026-10-08: commit
  5c5eb0d, census 185, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 11 -
  Flask of Curses through the
  Girdle of Giant Strength,
  part2 lines 481-530 (global =
  11065 + part2 line), pinning
  kMisc3 rows 1-9 (the C F T
  marks riding rows 4, 5, 8,
  9). ONE page header strips
  (493, the TREASURE page)
  cutting the Gem of Brightness
  paragraph mid-sentence (one
  seam, restored). 63 accessors:
  49 scalars + 14 walkers (the
  giant strength and rock
  hurling tables; the strength,
  damage and bend-bars ladders
  are arithmetic checks), no
  name collisions parts 1-10.
  Battery: groundtruth ALL
  MATCH t1 (154 checks),
  pristine only the documented
  missing-header fail (152
  checks); hygiene 0/0/0;
  two-pass 4/0 -> 0/4 on t1 t2
  t3; REPRO-CLEAN miscprose11.h
15442b81c6de1bb0f982d2328559a51d,
  regtest
8248eeef366a191e42140766bf06c4a0,
  gap report
6e5e4fa0c6fe1d507db9e96879312f1e
  - identical across trees;
  audit_eval R267 verified bad 0
  (51 asserts); full sweep 61
  verified all bad 0 (124
  unverified, pristine baseline
  60 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (swim climb
  995->996 line 108, gem
  cursory area 200->201 line
  223, diff-verified vs t1,
  both verified bad 1); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (44 checks: 63 accessors,
  audit/HDR set equality,
  census 185, includes 1-11
  contiguous, gap entry next
  pointer, apostrophe scan
  bounded to Categories:).
  LESSON (groundtruth, caught
  pre-delivery): the generated
  header comment WRAPS phrases
  across lines, so a check for
  a multi-word substring of the
  comment can never match (the
  girdle check failed on t1);
  print-fact checks against
  header comments must use
  wrap-proof fragments. Splice
  advisory md5
d70570107ac00eadea4e2bb818fbfae7
  (canvas body byte-for-byte);
  landed file
3fb34000d0049e9ee495e84005c2427a
  = advisory + the 1 newline -
  this round the terminal paste
  matched the prediction
  EXACTLY (md5 arithmetic, the
  paste and the landed tarball
  all agree, a first);
  landed splice, miscprose11.h,
  regtest and gap report all
  byte-exact fetched at 5c5eb0d;
  audit_eval on the landed tree
  GREEN (R267 bad 0, sweep 61).
  REAL GATE miscprose11.h
15442b81c6de1bb0f982d2328559a51d.
  Census 184 -> 185 at 5c5eb0d
  (pushed 552720e..5c5eb0d, 4
  files changed, 1457 insertions,
  miscprose11.h + r267_splice.py
  created). Next: R268 III.E
  part 12 - Helm of Brilliance
  onward in part2 from line 532
  (global 11597; the helm jewel
  functions, horns, horseshoes,
  incenses and instruments
  follow; kMisc3 rows 10+).
- R268 landed 2026-10-08: commit
  18b6ed6, census 186, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 12 -
  Helm of Brilliance through the
  Horn of Bubbles, part2 lines
  532-579 (global = 11065 +
  part2 line), pinning kMisc3
  rows 10-17, NO class marks and
  NO asterisks ride these rows.
  ONE page header inside the
  slice (the 541 TREASURE page)
  falls between the jewel
  functions table and the Each
  gem paragraph of the
  Brilliance item - restored.
  The jewel functions table: the
  book upload flattens the four
  gem rows into the Diamond cell
  (the Ruby, Fire Opal and Opal
  cells empty) - the four-row
  table restored from the
  1eonline.info compilation (the
  R175 precedent): Diamond
  prismatic spray (7th
  illusionist), Ruby wall of
  fire (5th druid), Fire Opal
  fireball (3rd magic-user),
  Opal light (1st cleric). 91
  accessors: 87 scalars + 4
  walkers (the jewel functions
  table), no name collisions
  parts 1-11. Battery:
  groundtruth ALL MATCH t1 (172
  checks), pristine only the
  documented missing-header
  fail (168 checks); hygiene
  0/0/0; two-pass 4/0 -> 0/4 on
  t1 t2 t3; REPRO-CLEAN
  miscprose12.h
3bc1accfbf02b0842e411d1b6fb4a3c9,
  regtest
0173b0a16c1e45893373487218a77d79,
  gap report
60581e05506b1d0e78ffc779a2dc38f5
  - identical across trees;
  audit_eval R268 verified bad 0
  (52 asserts); full sweep 62
  verified all bad 0 (124
  unverified, pristine baseline
  61 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (comprehend
  strange 90->91 line 235, both
  the scalar and the 90=80+10
  ladder tripped, bad 2;
  structural 18->19 line 525,
  bad 1; diff-verified vs t1);
  fresh rebuild t4
  byte-identical; DERIVED-CHECK
  GREEN on t1/t4 (50 checks: 91
  accessors, audit/HDR set
  equality, census 186,
  includes 1-12 contiguous, gap
  entry next pointer, apostrophe
  scan bounded to Categories:).
  LESSON (audit_eval, caught
  pre-delivery): the first
  draft carried a HALLUCINATED
  cross-ladder (level + stones
  = 17, true only for the
  diamond row) and audit_eval
  reported bad 3 before any
  delivery - arithmetic ladder
  checks must be verified
  against the actual tables,
  never composed from pattern
  intuition. Splice advisory md5
6af4985657829ceef98351e04207ff2e
  (canvas body byte-for-byte);
  landed file
18ce7185dea4d9162184c0c3377ff67e
  = advisory + the 1 newline -
  the terminal paste matched the
  md5 prediction EXACTLY (the
  second round in a row);
  landed splice, miscprose12.h,
  regtest and gap report all
  byte-exact fetched at
  18b6ed6; audit_eval on the
  landed tree GREEN (R268 bad 0,
  sweep 62). REAL GATE
  miscprose12.h
3bc1accfbf02b0842e411d1b6fb4a3c9.
  Census 185 -> 186 at 18b6ed6
  (pushed 5c5eb0d..18b6ed6, 4
  files changed, 2013 insertions,
  miscprose12.h + r268_splice.py
  created). Next: R269 III.E
  part 13 - Horn of Collapsing
  onward in part2 from line 581
  (global 11646; the tritons,
  Valhalla, horseshoes, incenses
  and instruments follow; kMisc3
  rows 18+).
- R269 landed 2026-10-08: commit
  8a9c468, census 187, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 13 - Horn
  of Collapsing through the
  Incense of Meditation, part2
  lines 581-626 (global = 11065 +
  part2 line), pinning kMisc3 rows
  18-23: the (C, F) mark on the
  Horn of the Tritons (row 19),
  the (C) mark on the Incense of
  Meditation (row 23), the
  Valhalla double asterisk (row
  20: bronze doubles, iron
  triples). ONE page header
  inside the slice (592, the
  TREASURE page) cuts the
  Collapsing proper-use
  paragraph mid-sentence -
  restored. ONE OCR artifact
  restored from the 1eonline.info
  compilation (the R175
  precedent): the meditation
  survival clause reads (rounded
  down), the upload prints
  grounded down). 73 accessors:
  60 scalars + 13 walkers (4
  triton summon: die bands 1-2,
  3-5, 6 with counts 5-20, 5-30,
  1-10; 9 Valhalla: dice, count,
  level, usable-by-class), no
  name collisions parts 1-12.
  Battery: groundtruth ALL MATCH
  t1 (109 checks), pristine only
  the documented missing-header
  fail (105 checks); hygiene
  0/0/0; two-pass 4/0 -> 0/4 on
  t1 t2 t3; REPRO-CLEAN
  miscprose13.h
9da52452e93ff92c60e496abe3dc5002
  , regtest
c98372d8c4bd002743d848e02cf524e0
  , gap report
b7b9f5cb5b7c9b9dece0358f82fc49f7
  - identical across trees;
  audit_eval R269 verified bad 0
  (44 asserts) - the panic
  rounds = turns x rounds-per-turn
  PRODUCT ladder verified, the
  first proven * use in an audit
  (the docs claim held in
  practice, no additive fallback
  needed); full sweep 63 verified
  all bad 0 (124 unverified,
  pristine baseline 62 - exactly
  +1); both mutations RED
  single-site by LINE NUMBER
  (return 180->181 line 218
  tripped the scalar and product
  ladder, bad 1; return 200->201
  line 383 tripped bad 2 - the
  horseshoes 200 also rides a sum
  ladder; diff-verified vs t1);
  fresh rebuild t4
  byte-identical; DERIVED-CHECK
  GREEN on t1/t4 (58 checks:
  73 accessors, audit/HDR set
  equality, census 187, includes
  1-13 contiguous, gap entry
  next pointer, apostrophe scan
  bounded to Categories:).
  LESSON (the splice self-assert,
  caught pre-battery): the first
  draft audit block never probed
  mmpHornTritonSummonKindCount
  (the loop hardcoded 3) - the
  accessor-set equality assert
  fired before any tree was
  touched, fixed by a scalar
  probe line. Splice advisory
  md5
a3f7557e3e2504d616f5aa413c01a844
  (canvas body byte-for-byte);
  landed file
a524db3c3519fa7d4f5ecced0e89e0a5
  = advisory + the 1 newline -
  the terminal paste matched the
  md5 prediction EXACTLY (the
  third round in a row); landed
  splice, miscprose13.h,
  regtest and gap report all
  byte-exact fetched at
  8a9c468; audit_eval on the
  landed tree GREEN (R269 bad 0,
  sweep 63). REAL GATE
  miscprose13.h
9da52452e93ff92c60e496abe3dc5002
  . Census 186 -> 187 at 8a9c468
  (pushed 18b6ed6..8a9c468, 4
  files changed, 1801
  insertions, miscprose13.h +
  r269_splice.py created). Next:
  R270 III.E part 14 - Incense
  of Obsession onward in
  part2 from line 630 (global
  11695; the ioun stones and
  instruments follow; kMisc3
  rows 24+).
- R270 landed 2026-10-08: commit
  65e1b64, census 188, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 14 -
  Incense of Obsession through
  the Fochlucan Bandore, part2
  lines 630-684 (DMG p.141-142,
  global = 11065 + part2 line),
  pinning kMisc3 rows 24-26: the
  (C) mark on the Incense of
  Obsession (row 24), the triple
  asterisk on the Ioun Stones
  (row 25, 300 xp / 5,000 gp per
  stone), the quadruple asterisk
  on the Instrument of the Bards
  (rows 73-78, 1,000 xp / 5,000
  gp base per level of
  instrument). ONE page header
  inside the slice (674, the
  TREASURE page) falls between
  the bandore paragraph and its
  song list - restored. The ioun
  stone property table: the
  upload mangles rows 3, 5 and 12
  (the shape cells folded into
  the roll and color cells, the
  missing space in 5pink) and
  wraps the regeneration cell
  across rows - the 15-row table
  restored from the 1eonline.info
  compilation page iounstone.htm
  (the R175 precedent, fetched
  and verified; it also confirms
  the obsession page: Class C,
  500 gp per group of 2-8). 47
  accessors: 41 scalars + 6
  walkers (the stone property
  table: roll lo/hi, adds-stat,
  absorb level, burnout min/max),
  no name collisions parts 1-13.
  Battery: groundtruth ALL MATCH
  t1 (77 checks), pristine only
  the documented missing-header
  fail (72 checks); hygiene
  0/0/0; two-pass 4/0 -> 0/4 on
  t1 t2 t3; REPRO-CLEAN
  miscprose14.h
4b102564a3ca29051710e788455b7d92
  , regtest
79297c2c7cc0dad78e919706514c4c59
  , gap report
e135ac5a0064aff6769ea6e0dc4a21a6
  - identical across trees;
  audit_eval R270 verified bad 0
  (49 asserts) - GREEN on the
  first run, no self-assert
  catches this round; full sweep
  64 verified all bad 0 (124
  unverified, pristine baseline
  63 - exactly +1); both
  mutations RED single-site by
  LINE NUMBER (obsession
  duration 24->25 line 32, bad 1;
  bandore mishap 70->71 line
  309, bad 2 - the 70 also rides
  the 30+70 = 100 sum ladder;
  diff-verified vs t1); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (60 checks). Splice advisory
  md5
587940bdfc87ada5fbc3feb2a8fb3540
  (canvas body byte-for-byte);
  landed file
c517934e3a0a4af0a9f0fec5a0119329
  = advisory + the 1 newline -
  the terminal paste matched the
  md5 prediction EXACTLY (the
  fourth round in a row); landed
  splice, miscprose14.h,
  regtest and gap report all
  byte-exact fetched at
  65e1b64; audit_eval on the
  landed tree GREEN (R270 bad 0,
  sweep 64). REAL GATE
  miscprose14.h
4b102564a3ca29051710e788455b7d92
  . Census 187 -> 188 at 65e1b64
  (pushed 8a9c468..65e1b64, 4
  files changed, 1258
  insertions, miscprose14.h +
  r270_splice.py created). Next:
  R271 III.E part 15 - the
  Mac-Fuirmidh Cittern onward in
  part2 from line 686 (global
  11751; the doss lute, canooth
  and the remaining instruments
  follow; kMisc3 row 26
  continues).
- R271 landed 2026-10-08: commit
  c73d948, census 189, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 15 -
  Mac-Fuirmidh Cittern through
  the general properties and the
  type table, part2 lines 686-764
  (DMG p.142-148, global = 11065
  + part2 line), closing the
  Instrument of the Bards item
  (the kMisc3 row 26 quadruple
  asterisk, 1,000 xp / 5,000 gp
  per level of instrument). NO
  page header seam this round -
  the upload DROPS the TREASURE
  headers across the instruments
  run (none between 674 and 792),
  so the page attribution rides
  the compilation TOC anchor
  (the instruments at pp.147-148);
  the instrument facts verified
  against the 1eonline.info page
  instrumentofthebards.htm; the
  level gates (5th, 8th, 11th,
  14th, 17th, 20th) cross-check
  the bard.h Table II college
  ladder; the Ollamh harp prints
  NO misuse percent (harm is
  certain, only 5 scalars). 51
  accessors: 49 scalars + 2
  walkers (the type die table
  twins), no name collisions
  parts 1-14. Battery: TWO
  mid-battery fixes (the header
  rewrapped so part2 lines
  686-764 reads contiguously -
  groundtruth caught it; the gap
  next-pointer rewrapped so Iron
  Flask reads contiguously - the
  derived check caught it), then
  groundtruth ALL MATCH t1 (89
  checks), pristine only the
  documented missing-header fail
  (84 checks); hygiene 0/0/0;
  two-pass 4/0 -> 0/4 on t1-t4;
  REPRO-CLEAN miscprose15.h
2b0a53f6271a9aa5fefa2e5f7226bcc4
  , regtest
8b5969bd754677ee8ed5a6ff271b13ba
  , gap report
c8a182dda5c65f43a4b6c7a1de0cc38f
  - identical across trees;
  audit_eval R271 verified bad 0
  (28 asserts); full sweep 65
  verified (124 unverified,
  pristine baseline 64 - exactly
  +1, label diff the R271 line
  only); both mutations RED
  single-site by LINE NUMBER
  (cittern charm 15->16 line 52,
  bad 2 - literal plus the +5
  charm ladder; anstruth gate
  17->18 line 183, bad 2 -
  literal plus the +3 gate
  ladder; diff-verified vs t1,
  restored byte-exact); fresh
  rebuild t4 byte-identical;
  DERIVED-CHECK GREEN on t1/t4
  (94 checks). Splice advisory
  md5
cc2fc697fe86afc6d3a6ab1cc98b0e0a
  (canvas body byte-for-byte);
  landed file
689fc59103b0e7037e07818edf2d619b
  = advisory + the 1 newline -
  the terminal paste matched the
  md5 prediction EXACTLY (the
  fifth round in a row); landed
  splice, miscprose15.h,
  regtest and gap report all
  byte-exact fetched at
  c73d948 (miscprose14.h
  untouched 4b102564a3ca29051710
  788455b7d92); audit_eval on
  the landed tree GREEN (R271
  bad 0, sweep 65). REAL GATE
  miscprose15.h
2b0a53f6271a9aa5fefa2e5f7226bcc4
  . Census 188 -> 189 at
  c73d948 (pushed 65e1b64..
  c73d948, 4 files changed,
  1188 insertions, miscprose15.h
  + r271_splice.py created).
  Next: R272 III.E part 16 -
  Iron Flask onward in part2
  from line 766 (global 11831;
  the javelins, jewels and
  Keoghtom ointment follow;
  kMisc3 rows 27+ begin).
- R272 landed 2026-10-09: commit
  2ab05f9, census 190, GREEN on
  the first Termux preflight (no
  b-round). The III.E misc magic
  explanation prose part 16 -
  Iron Flask through Keoghtom
  ointment, part2 lines 766-802
  (DMG p.148-149, global = 11065
  + part2 line), the slice
  completing the kMisc3 rows
  27-32, the 33-row III.E.3
  table COMPLETE. ONE page
  header inside the slice (792,
  the TREASURE page) falls inside
  the javelin of lightning
  paragraph between 1-6 hit and
  points of damage - ONE seam
  restored; the page attribution
  rides the 1eonline.info
  compilation TOC (the jewels,
  magical at p.149). The flask
  contents table: the upload
  drops the pipe in three rows
  (82-83 mezzodaemon, 94-97
  water elemental, 98-99 wind
  walker) - the 19-row d100
  table pinned with the printed
  00 row as the d100 100 (the
  engine kMisc3 93-00
  precedent). The items: Iron
  Flask (range 6 inches, one
  creature at a time, 1 turn or
  1 hour of minor service, +2
  save on a second attempt),
  Javelin of Lightning (+2
  weapon, 9 inch range,
  half-by-3 inch stroke, 1-6
  plus 20 electrical, back
  stroke 20 or 10, from 2-5,
  consumed), Javelin of Piercing
  (6 inch range, +6 to hit, 7-12
  damage, from 2-8, one throw),
  Jewel of Attacks (100 percent
  wandering and 100 percent
  pursuit, remove curse or
  atonement), Jewel of
  Flawlessness (100 percent
  boost, 1 in 10 to 2 in 10,
  10-100 facets, a roll of 2 on
  d10 burns 1 facet, then a
  spherical stone of no value),
  Keoghtom ointment (a 3 by 1
  inch jar, 5 applications,
  heals 9-12, from 1-3 jars).
  43 accessors: 41 scalars + 2
  walkers (the flask contents
  die table twins), no name
  collisions parts 1-15.
  Battery: ONE mid-battery fix
  (the gap entry rewrapped so
  rows 27-32 reads contiguously -
  the derived check caught it),
  then groundtruth ALL MATCH t1
  (93 checks), pristine only the
  documented missing-header fail
  (86 checks); hygiene 0/0/0;
  two-pass 4/0 -> 0/4 on t1-t4;
  REPRO-CLEAN miscprose16.h
da41ce434467041b2689529033e1c4c7
  , regtest
8964c37eab3cef9dde5ee391a3fd0c17
  , gap report
4830438053a93f0eb3e50ed37f420ce6
  - identical across trees;
  audit_eval R272 verified bad 0
  (50 asserts); full sweep 66
  verified (124 unverified,
  pristine baseline 65 - exactly
  +1, label diff the R272 line
  only); both mutations RED
  single-site by LINE NUMBER
  (flask row count 19->20 line
  56, bad 1; piercing damage
  min 7->8 line 153, bad 1;
  diff-verified vs t1, restored
  byte-exact); fresh rebuild t4
  byte-identical; brace and
  paren deltas 0/0 on the
  added regtest lines;
  DERIVED-CHECK GREEN on t1/t4
  (99 checks). Splice advisory
  md5
39e860e2228223f5c5b0ff3b5dd79586
  (canvas body byte-for-byte);
  landed file
3eb5dd8a1a037e44505d861479d6ea94
  = advisory + the 1 newline -
  the terminal paste matched the
  md5 prediction EXACTLY (the
  sixth round in a row); landed
  splice, miscprose16.h,
  regtest and gap report all
  byte-exact fetched at
  2ab05f9 (miscprose15.h
  untouched 2b0a53f6271a9aa5fe
  fa2e5f7226bcc4); audit_eval
  on the landed tree GREEN (R272
  bad 0, sweep 66). REAL GATE
  miscprose16.h
da41ce434467041b2689529033e1c4c7
  . Census 189 -> 190 at
  2ab05f9 (pushed c73d948..
  2ab05f9, 4 files changed,
  1039 insertions, miscprose16.h
  + r272_splice.py created).
  Next: R273 III.E part 17 -
  the Libram of Gainful
  Conjuration onward in part2
  from line 806 (global 11871;
  the librams, lyre of building
  and manuals follow).
R273 landed the III.E misc
magic explanation prose part 17
(part2 lines 806-841, DMG
p.149-150), the three Librams,
the Lyre of Building and the
Manuals of Bodily Health,
Gainful Exercise, Golems,
Puissant Skill at Arms and
Quickness of Action - the
slice pinning the kMisc4
rows 0-8 of the 36-row III.E.4
table. ONE seam restored: the
TREASURE page header at 839
falls inside the quickness
paragraph between Only after
and the month of training; the
attribution rides the TOC
index on the p.149 base. The
upload drops the pipe in part1
rows 02 (Ineffable Damnation)
and 08 (Puissant Skill) and
carries a stray apostrophe
after manual (pinned as
printed). 47 accessors: 43
scalars + 4 golem walkers.
Battery: hygiene 0/0/0; four
fresh trees two-pass 4/0 then
0/4; REPRO-CLEAN byte-identical;
groundtruth 94 pristine (the
one documented fail) and 100
ALL MATCH t1; audit R273 bad 0
(27 asserts); sweep 67 vs 66,
label diff R273 only; RED
mutations t2 118 (24 to 25)
and t3 93 (100 to 101) each
bad 1, restored GREEN; derived
check 104 checks GREEN t1/t4.
The GAP rewrap (R272 lesson
pre-emptive) changed only the
gap report: new md5
e448a7e8bdc55ef1ad57d0a63791b4a9
. Splice advisory md5
060bbed8d2dea726af776779fe32fda5
(canvas body byte-for-byte);
landed file
e45d3d7b72cc7f8e62343b601d711fdc
= advisory + the 1 newline -
the terminal paste matched
the md5 prediction EXACTLY;
landed splice, miscprose17.h,
regtest and gap report all
byte-exact fetched at
6553f04 (R272 gate
da41ce434467041b2689529033e1c4c7
unchanged); audit_eval on the
landed tree GREEN (R273 bad 0,
sweep 67). REAL GATE
miscprose17.h
1dc580b64478b30907ec6f81996062ef
. Census 190 -> 191 at
6553f04 (pushed 2ab05f9..
6553f04, 4 files changed,
1181 insertions, miscprose17.h
+ r273_splice.py created).
Next: R274 III.E part 18 - the
Manual of Stealthy Pilfering
onward in part2 from line 843
(global 11908; the mattock,
maul, medallions and mirrors
follow; kMisc4 rows 9+
continue).
R274 landed the III.E misc
magic explanation prose part 18
(part2 lines 843-900, DMG
p.150-151), the Manual of
Stealthy Pilfering, the Mattock
and Maul of the Titans, the
Medallions of ESP and Thought
Projection, the Mirrors of Life
Trapping, Mental Prowess and
Opposition and the Necklaces of
Adaptation and Missiles - the
slice pinning the kMisc4
rows 9-18 of the 36-row III.E.4
table. ONE mid-sentence break:
the mirror of life trapping
paragraph splits between not a
(863) and factor (865), the
upload prints no running head at
the break - ONE seam restored
this round; the slice rides the
pp.150-151 attribution on the
R273-established p.150 base.
The upload quirks: the necklace
of missiles table is badly
mangled (pipes misplaced,
fragments in the wrong cells),
the dash-separated count
ladders reconstruct it and
cross-check against the printed
9-12 example (one 7-dice, two
5-dice, four 3-dice - the
columns are the 11-dice down to
2-dice ladder, cells the
counts, rows the die bands
1-4, 5-8, 9-12, 13-16, 17-18,
19, 20); the stray apostrophe
artifact after the word manual
recurs (a like manual) beside a
printed magic- users with a
space; the medallion table
prints clean. 67 accessors: 59
scalars + 8 walkers (the
medallion bands, ranges and
empathy; the necklace bands,
hit dice columns and the
flattened 70-cell count
table). Battery: hygiene 0/0/0;
four fresh trees two-pass 4/0
then 0/4; REPRO-CLEAN
byte-identical; groundtruth 126
pristine (the one documented
fail) and 166 ALL MATCH t1;
audit R274 bad 0 (192 asserts);
sweep 68 vs 67, label diff R274
only; RED mutations t2 232
(EspMaxWidthFeet 11 to 12) and
t3 157 (MaulMinStrength 21 to
22) each bad 1, restored GREEN;
derived check 35 checks GREEN
t1/t4. Splice advisory md5
2683548fc162286c0f967700bfa390d0
(canvas body byte-for-byte);
landed file
c24bcb3914b5e50b781ba0eb266472f4
= advisory + the 1 newline -
the terminal paste matched the
md5 prediction EXACTLY (the
second round in a row); landed
splice, miscprose18.h, regtest
and gap report all byte-exact
fetched at 0dbcef6 (R273 gate
1dc580b64478b30907ec6f81996062ef
unchanged); audit_eval on the
landed tree GREEN (R274 bad 0
over 192 asserts, sweep 68).
REAL GATE miscprose18.h
feb3789734c8236a5c467a0f12ebadfa
. Census 191 -> 192 at 0dbcef6
(pushed 6553f04..0dbcef6,
4 files changed, 1749
insertions, miscprose18.h +
r274_splice.py created).
Next: R275 III.E part 19 - the
Necklace of Prayer Beads
onward in part2 from line 905
(global 11970; the
strangulation necklace, nets,
pigments, pearls and periapts
follow; kMisc4 rows 19+
continue).
R275 landed the III.E misc
magic explanation prose part
19 (part2 lines 905-969;
global = 11065 + part2 line),
the Necklace of Prayer Beads,
the Necklace of Strangulation,
the Nets of Entrapment and
Snaring, Nolzurs Marvelous
Pigments, the Pearls of Power
and Wisdom and the Periapts of
Foul Rotting, Health, Proof
Against Poison and Wound
Closure (DMG p.152-153) -
the slice pinning the kMisc4
rows 19-29 of the 36-row
III.E.4 table; ONE seam
restored (the pearl of power
paragraph splits between a
pearl of power at 933 and
enables the possessor at
935, no running head at the
break). The upload quirks
this round: the bead table
rows are split across
multiple table lines (the
karma and summons beads
span three each); the part1
pigments row misplaces the
apostrophe after the s; the
net of entrapment prints
the one-quarter character
(mesh) and an en-dash (AC
-10) - pinned as plain
digits. 49 accessors: 41
scalars + 8 walkers (the
bead, pearl and periapt die
bands, the pearl spell
levels and the periapt plus
ladder). Battery: hygiene
0/0/0; four fresh trees
two-pass 4/0 then 0/4;
REPRO-CLEAN byte-identical;
groundtruth 128 pristine
(the one documented fail)
and 168 ALL MATCH t1;
audit R275 bad 0 (143
asserts); sweep 69 vs 68,
label diff R275 only; RED
mutations t2 (strangle
damage 6 to 7) and t3 (the
summons bead 90 to 91) each
bad 1, restored GREEN; fresh
t4 rebuild byte-identical;
the R272 frag lesson
pre-applied - the gap frags
part 19, line 971 and 49
accessors: 41 rewrapped
contiguous (only the gap
report changed, the header
and regtest md5s stable);
derived check 74 checks
GREEN t1/t4. Splice
advisory md5
d1c60b7e3920364df036540b4c564fd9
(canvas body
byte-for-byte); landed file
64b08864bb53facfb6231881917525d8
= advisory + the 1 newline -
the terminal paste matched
the md5 prediction EXACTLY
(the third round in a row);
landed splice, miscprose19.h,
regtest and gap report all
byte-exact fetched at
02eb198 (R274 gate
feb3789734c8236a5c467a0f12ebadfa
unchanged); audit_eval on the
landed tree GREEN (R275 bad
0 over 143 asserts, sweep
69). REAL GATE
miscprose19.h
76605f41a59d4a389a3821a291d49120
. Census 192 -> 193 at
02eb198 (pushed
0dbcef6..02eb198, 4 files
changed, 1494 insertions,
miscprose19.h +
r275_splice.py created).
Next: R276 III.E part 20 -
the Phylactery of
Faithfulness onward in
part2 from line 971 (global
12036; the long years and
monstrous attention
phylacteries, the pipes,
the portable hole and the
feather token follow;
kMisc4 rows 30+ continue).
R276 landed the III.E misc
magic explanation prose part
20 (part2 lines 971-998;
global = 11065 + part2 line),
the Phylactery of Faithfulness,
the Phylactery of Long Years,
the Phylactery of Monstrous
Attention, the Pipes of the
Sewers, the Portable Hole and
Quaals Feather Token (DMG
p.153-154) - the slice pinning
the kMisc4 rows 30-35 of the
36-row III.E.4 table, closing
the table; no seam this round
(the slice runs paragraph-
complete between the 970 and
999 blanks). The upload quirks:
the OCR splits three
hyphenated words with a space
(one- quarter, re- establish
and non- dimensional); curly
apostrophes in deitys,
pipers, tokens and the Quaals
item name (the engine spells
the item with the straight
mark); curly quotes around
picked up, hole and to hit;
curly foot and inch primes;
two multiplication signs on
the rat dice; em-dash token
rows. The part1 quirks: the
Monstrous Attention row splits
across part1 9851-9852 with
--- in the x.p. column; the
Feather Token row prints both
dual value pairs in the x.p.
column. The Phylactery of
Faithfulness carries no
accessor (numberless prose,
like the Periapt of Health in
part 19). 44 accessors: 42
scalars + 2 walkers (the
token die bands). Battery:
hygiene 0/0/0; four fresh
trees two-pass 4/0 then 0/4;
REPRO-CLEAN byte-identical;
groundtruth 80 pristine (the
one documented fail) and 137
ALL MATCH t1; audit R276 bad
0 (70 asserts); sweep 70 vs
69, label diff R276 only; RED
mutations t2 (pipe obey 95 to
96) and t3 (swan speed 24 to
25) each bad 1, restored
GREEN; fresh t4 rebuild
byte-identical; braces and
parens 0/0 over the 123 added
regtest lines; derived check
78 checks GREEN t1/t4. Two
in-flight lessons: the audit
loop bodies started braced
and audit_eval flagged the
block UNVERIFIED (restructured
brace-less, regtest md5 only
- the known audit_eval
constraint, relearned); the
R272 frag lesson is now a
splice self-assert (per-line
contiguity caught one split
frag before the trees ran).
Splice advisory md5
dde9f10a121faec8b69f3e05deb6a485
(canvas body
byte-for-byte); landed file
068561702287c91fb1ae210001802629
= advisory + the 1 newline -
the terminal paste matched
the md5 prediction EXACTLY
(the fourth round in a row);
landed splice, miscprose20.h,
regtest and gap report all
byte-exact fetched at
ad85153 (R275 gate
76605f41a59d4a389a3821a291d49120
unchanged); audit_eval on the
landed tree GREEN (R276 bad 0
over 70 asserts, sweep 70).
REAL GATE miscprose20.h
fd40f97d2cbd99be89ee1a6d5c81ed1f
. Census 193 -> 194 at
ad85153 (pushed
02eb198..ad85153, 4 files
changed, 1207 insertions,
miscprose20.h +
r276_splice.py created).
Next: R277 III.E part 21 - the
Robe of the Archmagi onward in
part2 from line 1002 (global
12067; the five robes, the
three ropes, the two rugs,
the saw, the four scarabs and
the spade follow; the kMisc5
rows 1+ continue).
R277 landed the III.E misc
magic explanation prose part
21 (part2 lines 1002-1052;
global = 11065 + part2 line),
the Robe of the Archmagi, the
Robe of Blending, the Robe of
Eyes, the Robe of Powerlessness,
the Robe of Scintillating
Colors and the Robe of Useful
Items (DMG p.153-154) - the
slice pinning the kMisc5
rows 0-5 of the 35-row III.E.5
table, opening it; one seam
this round (the Powerlessness
paragraph splits between the
1018 and becomes tail and the
1021 weak as well head across
the 1019-1020 blank pair - the
page break with no running
head, seam restored). The
upload quirks: the OCR splits
magic- user and language/
noise with a space; curly
apostrophes in the robe and
wearer possessives; curly
quotes around see, eyes and
flowing; curly foot and inch
primes; the true minus sign in
20%/minus 4; one-half and
multiplication signs on the
coffer and window rows; em-
dash door and window rows. The
part1 quirks: the six robe rows
print side-by-side with armor-
table columns (part1
9875-9880); the Powerlessness
row prints --- in the x.p.
column; the Scintillating row
misplaces 2,750 after the
(C, M) marks; the useful items
table flattens its two header
rows and prints 13 die bands,
pinned as the twin walkers. 67
accessors: 65 scalars + 2
walkers (the useful item die
bands). Battery: hygiene
0/0/0; four fresh trees
two-pass 4/0 then 0/4;
REPRO-CLEAN byte-identical;
groundtruth 85 pristine (the
one documented fail) and 165
ALL MATCH t1; audit R277 bad 0
(81 asserts); sweep 71 vs 70,
label diff R277 only; RED
mutations t2 (archmagi white
45 to 46, bad 2 - the color-
sum assert trips too) and t3
(clash xp 18000 to 18001, bad
1), restored GREEN; fresh t4
rebuild byte-identical; braces
and parens 0/0 over the
153-line audit block plus the
include (154 regtest lines);
derived check 101 checks GREEN
t1/t4. Two in-flight lessons:
the builder collapsed the
printf BS join into a plain
string element (hygiene count
c caught it before any tree
ran - the emitted line would
have been broken C++; emit
printf lines as a real
str + BS + str source
expression); hygiene.py and
derived_check.py were rebuilt
fresh after the workspace wipe
(hygiene now allows the
BS-as-Name join, joined
length at most 80; the gap
entry carries a trailing
blank line before
Categories: - strip it
before tail checks).
Splice advisory md5
236b1738c68127ef616d606067907ad0
(canvas body
byte-for-byte); landed
file md5
f2cee2e855b7fb1dd0067ffde5a318ab
= advisory + the 1 newline -
the terminal paste matched
the md5 prediction EXACTLY
(the fifth round in a row);
landed splice, miscprose21.h,
regtest and gap report all
byte-exact fetched at
8263899 (the R276 gates
unchanged - regtest
4b2981336932521ad01f864aa4352550
miscprose20.h
fd40f97d2cbd99be89ee1a6d5c81ed1f
gap report
8232350243bc9c831b2189294cbba7cc
); audit_eval on the
landed tree GREEN (R277 bad 0
over 81 asserts, sweep 71).
REAL GATE miscprose21.h
7728c16747e0c423f19c3d94ee8d13fa
. Census 194 -> 195 at
8263899 (pushed
ad85153..8263899, 4 files
changed, 1544 insertions,
miscprose21.h +
r277_splice.py created).
Next: R278 III.E part 22 -
the Rope of Climbing onward
in part2 from line 1054
(global 12119; the three
ropes, the rope note, the
two rugs, the saw, the four
scarabs and the spade follow;
the kMisc5 rows 7+
continue).
R278 landed the III.E misc
magic explanation prose part
22 (part2 lines 1054-1081;
DMG p.154-156; the Rope of
Climbing, the Rope of
Constriction, the Rope of
Entanglement, the rope note,
the Rug of Smothering, the
Rug of Welcome, the Saw of
Mighty Cutting, the four
Scarabs and the Spade of
Colossal Excavation; kMisc5
rows 6-16; 85 accessors: 84
scalars + the walker
mmpEntangleManUnits [1,2,
3,4,6,8,10,12,16]; two
seams: the Constriction
split at the p.154-155
break and the running head
at the p.155-156 break) at
388edf5 (pushed
8263899..388edf5, 4 files
changed, 1897 insertions,
miscprose22.h +
r278_splice.py created).
The user paste matched the
md5 prediction EXACTLY
(the sixth round in a row);
landed splice, miscprose22.h,
regtest and gap report all
byte-exact fetched at
388edf5 (the R277 gates
unchanged - miscprose21.h
7728c16747e0c423f19c3d94ee8d13fa
regtest
3df493d9da633a68f8038ded29b3d4ee
gap report
39977bd88b00677e0ae44a147fe0313e
); audit_eval on the
landed tree GREEN (R278
verified bad 0 over 120
asserts, sweep 72). LESSON:
the audit men equal the max
assert used walker index 6
elves 10 instead of index
5 men 8; groundtruth
passed it (180 checks ALL
MATCH - it checks the
array, not the audit
index) and only audit_eval
caught it (bad 1 over
120); always cross check
walker indices in audit
bodies against the walker
chain. Census 195 -> 196
at 388edf5. REAL GATE
miscprose22.h
adc749e5869e213f8270021e2e5a0b71
. Next: R279 III.E part 23
- the Sphere of
Annihilation onward in
part2 from line 1083
(global 12148; the sphere
control table, the three
stones and the four
talismans follow; the
kMisc5 rows 17+
continue).
R279 landed the III.E misc
magic explanation prose
part 23 (part2 lines 1083-1149;
global = 11065 + part2 line),
the Sphere of Annihilation, the
Stone of Controlling Earth
Elementals, the Stone of Good
Luck, the Stone of Weight, the
Talisman of Pure Good, the
Talisman of the Sphere, the
Talisman of Ultimate Evil, the
Talisman of Zagy, the Tome of
Clear Thought, the Tome of
Leadership and Influence, the
Tome of Understanding, the
Trident of Fish Command, the
Trident of Submission, the
Trident of Warning, the Trident
of Yearning, the Vacuous
Grimoire, the Well of Many
Worlds and the Wings of Flying
(DMG p.156-158) - the closing
slice pinning the kMisc5 rows
17-34 of the 35-row III.E.5
table (rows 0-5 by part 21 and
6-16 by part 22; the III.E.5
prose series is closed at all
35 rows). Two seams restored:
seam A the p.156-157 page break
between the Stone of Weight
tail (1108) and the Pure Good
head (1113), blank pair
1109-1110, TREASURE
(MISCELLANEOUS MAGIC) running
head 1111, blank 1112; seam B
the Fish Command split, 1127
tail (but they will not) /
1129 head (approach closer),
single 1128 blank, the
p.157-158 break, headless.
110 accessors: 104 scalars + 6
walkers (the nine-row sphere
control grid level/move/percent
and the three-entry wings
turns/inches list); the R278
walker-index lesson held - the
audit verified bad 0 on the
first pass (201 asserts). The
user paste matched the md5
prediction EXACTLY (the
seventh round in a row);
landed splice, miscprose23.h,
regtest and gap report all
byte-exact fetched at
e7c43ae (the R278 gates
unchanged - regtest
3df493d9da633a68f8038ded29b3d4ee
miscprose22.h
adc749e5869e213f8270021e2e5a0b71
gap report
39977bd88b00677e0ae44a147fe0313e
); audit_eval on the landed
tree GREEN (R279 verified bad
0 over 201 asserts, sweep 73).
REAL GATE miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
. Census 196 -> 197 at e7c43ae
(pushed 388edf5..e7c43ae,
4 files changed, 2505
insertions, miscprose23.h +
r279_splice.py created). Next:
R280 III.E Special - the Notes
Regarding Artifacts and Relics
onward in part2 from line
1153 (global 12218; the
artifact and relic notes and
the powers/side-effects tables
follow; the III.E Special prose
continue).
R280 landed the III.E Special
artifacts and relics explanation
prose part 1 (part2 lines
1153-1182; global = 11065 +
part2 line), the Notes Regarding
Artifacts and Relics (DMG
p.158-159) - the series opener
before the 29 artifact
descriptions: the one-of-each
rule, the listing crossed off
when placed or found (a clue
substituted or the result
ignored), the powers only
partially described with the DM
assigning the major powers, lore
not found by chance, the balance
and nemesis-creature caution, the
5 tables of powers and side
effects after the descriptions,
the three hireling behaviors
(evil destroys or escapes,
neutral dominates, good defects
with the item), the 10-30
percent loyalty drop, destruction
by a single means, the deface
save versus magic at minus 5
with failure equal to death, the
four corruption traits and the
permanent effects with the deity
exception. One seam restored: the
p.158-159 page break splits the
opening paragraph between the
1153 tail (only 1 of each may
exist. As) and the 1158 head
(each is placed by you) across
the blank pair at 1154-1155, the
TREASURE (ARTIFACTS & RELICS)
running head at 1156 and the
1157 post-head blank. 20
accessors: 20 scalars and no
walkers - the new specartprose.h
series, prefix sap, opens beside
the R240 specart.h sa sale table
accessors, and the audit
cross-pins saRowCount 29. The
user paste matched the md5
prediction EXACTLY (the eighth
round in a row); landed splice,
specartprose.h, regtest and gap
report all byte-exact fetched at
20ad4f0 (the R279 gates
unchanged - miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
); audit_eval on the landed tree
GREEN (R280 verified bad 0 over
6 asserts, sweep 74). REAL GATE
specartprose.h
0f6e3b68e40088474daa9b98f9194a81
. Census 197 -> 198 at 20ad4f0
(pushed e7c43ae..20ad4f0, 4
files changed, 770 insertions,
specartprose.h + r280_splice.py
created). Next: R281 III.E
Special part 2 - the Axe of the
Dwarvish Lords onward in part2
from line 1184 (global 12249;
the Baba Yaga Hut, the Codex of
the Infinite Planes and the other
descriptions follow; the III.E
Special prose continue).
R281 landed the III.E Special
artifacts explanation prose part
2 (part2 lines 1184-1235; global =
11065 + part2 line), the Axe of
the Dwarvish Lords, the Baba
Yaga Hut and the Codex of the
Infinite Planes (DMG p.159-160)
- the new specartprose2.h series,
prefix sap, 37 accessors: 33
scalars and 4 walkers
(sapAxePowerCount,
sapHutPowerCount,
sapCodexPowerCount,
sapHutMoveInches 48,36,12). One
seam restored: the p.159-160
page break splits the Codex
paragraph between the 1216 tail
(the work will destroy
instantly any) and the 1221
head (character under 11th
level) across the blank pair
1217-1218, the TREASURE
(ARTIFACTS & RELICS) running
head 1219 and the 1220 blank.
The audit cross-pins the R240
sale table: Axe band 01,
Hut band 02, Codex band 03-04
(saSaleGp, saRowLo/Hi in
specart.h). HARD LESSON: the
first draft cross-pinned the
Codex as band 05-20 and the
Hut as 02-04 from memory -
WRONG; audit_eval caught it
pre-delivery. Never infer die
bands from memory - read the
part1 sale table (dmg-part1.md
lines 9916-9919); groundtruth
now re-derives the bands from
the part1 table. The user paste
matched the md5 prediction
EXACTLY (the ninth round in a
row); landed splice, regtest
and gap report byte-exact
fetched at cbcf68a, the R280
gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
e032fedc4b21747a31bf489b3b2c62a0
); audit_eval on the landed
tree GREEN (R281 verified bad 0
over 31 asserts, sweep 75).
REAL GATE specartprose2.h
005801553fd5196bdc0aecedacf40162
. Census 197 -> 198 -> 199 at
cbcf68a (pushed 20ad4f0..cbcf68a,
4 files changed, 1166
insertions, specartprose2.h +
r281_splice.py created). Next:
R282 III.E Special part 3 -
the Crown of Might onward in
part2 from line 1237 (global
12302; the Crystal of the Ebon
Flame, the Cup and Talisman of
Al Akbar and the other
descriptions follow; the III.E
Special prose continue).
R282 landed the III.E Special
artifacts explanation prose part
3 (part2 lines 1237-1268; global =
11065 + part2 line), the Crown of
Might (DMG p.160) - the fourth of
the 29 artifact descriptions, the
first item of the regalia sets of
Might: a crown, an orb and a
sceptre per champion of the 3
ethic alignments (Evil, Good,
Neutrality), the 3 complete sets
scattered and lost over the
centuries, mere possession
benefiting a same-ethos
character, a wrong-ethos touch
dealing 5-30 hit points with save
versus magic or instant death,
the alignment table 01-06 Evil,
07-14 Good, 15-20 Neutrality, the
wearer raised 1 experience level
with worn powers 2 of table I and
1 each of II and III, an off-ethos
Orb or Sceptre touch dealing the
same damage and save with 1
malevolent power from table IV on
a successful save, the same-ethos
2nd item of the set adding 1 each
of tables I and II, the 3rd item
adding 1 each of I, II, IV, V and
VI, examination revealing no
difference and detection not the
ethic alignment, a slender gold
diadem set with 3 precious stones
of great size worth 50,000 or
more gold pieces if openly sold.
21 accessors: 16 scalars + 5
walkers (the alignment band lo/hi
walkers, the worn power walker,
the set 2nd item walker and the
set 3rd item walker), no name
collisions with the miscprose and
specart headers; the audit
cross-pins the R240 sale table row
- the Crown band 05-20 at 50000,
re-derived from the part1 table
itself (the R281 lesson held). NO
seam this round, a first: the
slice lies wholly on p.160 - the
p.160-161 break splits the Hand
of Vecna paragraph (a later
round). The upload quirks: the
power tables print the counts as
N x table with the true
multiplication sign, 10 of them,
in markdown tables of blank fills;
the ethic alignment dashes print
as true em-dashes; the wearer
level line prints the curly
apostrophe - all pinned as plain
digits and words, apostrophe-free
here. The user paste matched the
md5 prediction EXACTLY (the tenth
round in a row); landed splice,
regtest and gap report
byte-exact fetched at fa4b1a9,
the R281 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
e032fedc4b21747a31bf489b3b2c62a0
); audit_eval on the landed tree
GREEN (R282 verified bad 0 over
29 asserts, sweep 76). REAL GATE
specartprose2.h
e2e6f457ab88bf85a0f01533d9e3682f
. Census 197 -> 198 -> 199 -> 200
at fa4b1a9 (pushed
cbcf68a..fa4b1a9, 4 files
changed, 806 insertions,
r282_splice.py created). Next:
R283 III.E Special part 4 - the
Crystal of the Ebon Flame onward
in part2 from line 1270 (global
12335; the Cup and Talisman of
Al Akbar, the Eye and the Hand
of Vecna and the other
descriptions follow; the III.E
Special prose continue).
R283 landed the III.E Special
artifacts explanation prose part
4 (part2 lines 1270-1316;
global = 11065 + part2 line),
the Crystal of the Ebon Flame and
the Cup and Talisman of Al Akbar
(DMG p.160) - the fifth and sixth
of the 29 artifact descriptions.
The Crystal: origin and
whereabouts entirely unknown, a
diamond-hard mineral the size of a
hand, touched it sends rays of
light with a black flame leaping
in the jewel heart, all creatures
within 30 feet save versus magic
or charmed as if by a fire charm
spell, the possessor draws powers
by gazing at the Ebon Flame at its
center; powers 4 of table I, 2 of
II, 1 each of III-VI. The Cup and
Talisman: a pair of holy relics
given by the gods of the Paynims
to their most exalted high priest
of lawful good alignment in the
days following the Invoked
Devastation (the same era the Axe
was lost in), lost to demi-human
raiders, last rumored in the
Southeastern Bandit Kingdoms;
the Cup of hammered gold and
silver filigree set with 12 great
gems in electrum settings, a
jewelry value of 75,000 or more
gold pieces, not radiating magic,
powers 4 of table I and 1 of
III; the Talisman of hammered
platinum, a star of 8 points with
a small gem tipping each point
hung from a gold and electrum
chain of 8 sets of 3 silver
beads, a jewelry value of 10,000
or more gold pieces, not
radiating magic either, powers 2
of table II and 1 of IV; a
cleric, druid, paladin or ranger
possessing both may fill the cup
with holy water, immerse the
talisman and create a potion once
per week - the d20 potion table
1-5 healing, 6-10 extra healing,
11-15 poison antidote balm,
16-17 cure disease salve, 18-19
remove curse ointment, 20 raise
dead balm - and the possessor
gains 1 each of tables V and VI
from both. 32 accessors: 26
scalars + 6 walkers (the crystal
power walker, the cup, talisman
and both power walkers and the
potion band lo/hi walkers), no
name collisions with the
miscprose and specart headers;
the audit cross-pins the R240 sale
table rows - the Crystal band 21
at 75000, the Cup and Talisman
band 22 at 85000, the cup jewelry
value 75000 NOT its sale value
(the R281 lesson held; the
jewelry value differs from the
sale value).
No seam this round either: both
descriptions lie wholly on
p.160 - the p.160-161 break splits
the Hand of Vecna paragraph (a
later round). The upload quirks:
the power lines print the counts
as N x table with the true
multiplication sign, 12 of them;
the 30 feet prime prints as the
curly right single quote, as does
the Al Akbar apostrophe; the
jewelry value dashes print as
true em-dashes; the cup 1 of III
and the talisman 1 of IV power
lines carry asterisk footnote
markers; the potion table prints
the 1-5 band split from its
healing word - all pinned as
plain digits and words,
apostrophe-free here. LESSONS this
round: audit_eval cannot parse a
braced for-loop body in an audit
block - one if per unbraced for;
a groundtruth regex period
matched a space (escape literal
periods); the audit probes the
R281 Axe Invoked Devastation
flag as the cross-round era pin,
so the full-coverage assert now
allows exactly that one extra
probe. The user paste matched the
md5 prediction EXACTLY (the
eleventh round in a row); landed
splice, regtest and gap report
byte-exact fetched at a9964ae,
the R282/R281 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
e032fedc4b21747a31bf489b3b2c62a0
); audit_eval on the landed tree
GREEN (R283 verified bad 0 over
47 asserts, sweep 77). REAL GATE
specartprose2.h
c36d9af3157f0db44ee56bb8ed31c55e
. Census 197 -> 198 -> 199 -> 200
-> 201 at a9964ae (pushed
fa4b1a9..a9964ae, 4 files
changed, 1062 insertions,
r283_splice.py created). Next:
R284 III.E Special part 5 - the
Eye of Vecna onward in part2
from line 1318 (global 12383;
the Hand of Vecna with the
p.160-161 seam and the other
descriptions follow; the III.E
Special prose continue).
R284 landed the III.E Special
artifacts explanation prose part
5 (part2 lines 1318-1357, DMG
p.160-161) - the Eye of Vecna
and the Hand of Vecna (Eye powers
2,2,0,1,1 total 6; Hand powers
10,5,2,2,2,1 total 22), 28
accessors (26 scalars + 2
walkers), one seam restored (the
p.160-161 page break splits the
severing paragraph between the
1332 tail and the 1337 head),
the audit cross-pins the R240
sale rows (Eye band 23-24 at
35000 row 6, Hand band 25 at
60000 row 7), strict audited
equals defs restored (no
cross-round probes). Two
pre-land self-assert frag-wrap
bugs as usual: the GAP
hand-wrap drifted to 35-36
chars on 10 lines (fixed with a
programmatic 34-char rewrap that
treats the contiguity frags as
atomic tokens - a token glued to
following punctuation, as in
1318-1357;, must count as its
restored length); the AUDIT
contiguity assert needed
capital-T The Hand of Vecna on
one comment line. RED targets
return 100 and return 18, both
unique, both fired bad 2
(each accessor probed twice).
The user paste matched the md5
prediction EXACTLY (the twelfth
round in a row); landed splice,
regtest and gap report
byte-exact fetched at e137088,
the R283/R281 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
e032fedc4b21747a31bf489b3b2c62a0
); audit_eval on the landed tree
GREEN (R284 verified bad 0 over
22 asserts, sweep 78). REAL GATE
specartprose2.h
1d6826183d3156ffffe234ba83d43de7
. Census 197 -> ... -> 202 at
e137088 (pushed a9964ae..e137088,
4 files changed, 899 insertions,
r284_splice.py created). Next:
R285 III.E Special part 6 - the
Mystical Organ of Heward onward
in part2 from line 1359 (global
12424; the Horn of Change, the
Invulnerable Coat of Arnd and
the other descriptions follow;
the III.E
Special prose continue).
R285 landed the III.E Special
artifacts explanation prose part
6 (part2 lines 1359-1403, DMG
p.161-162) - the Mystical Organ of
Heward, the Horn of Change and
the Invulnerable Coat of Arnd, the
ninth through the 11th of the 29
descriptions (Organ powers
7,7,3,7,7,3 total 34; Horn blasts
1,2,5 power and 3,6,4 effect
tables, 75/25 split; Coat powers
3,2,2,1,1,1 total 10), 33
accessors: 29 scalars + 4
walkers. No page break inside the
slice - a seam-free round. First
try clean on the pre-land
self-asserts: the GAP was
wrapped programmatically from the
start (the R284 lesson, protected
frags as atomic tokens with
restored-length counting). RED
targets return 77 and return 75,
both unique; 77 fired bad 1, and
75 fired bad 2 because the audit
checks the 75+25=100 sum. The
audit cross-pins the R240 sale
rows: the Organ band 26 at 25000
row 8, the Horn band 27 at 20000
row 9, the Coat band 28-29 at
47500 row 10. The user paste
matched the md5 prediction
EXACTLY (the 13th round in a
row); landed splice, regtest and
gap report byte-exact fetched at
b764adc, the R284/R281 gates
unchanged (specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
3aceba461b4642e8446770db5474b498
); audit_eval on the landed tree
GREEN (R285 verified bad 0 over
29 asserts, sweep 79). REAL GATE
specartprose2.h
5a1c14f33eb4bb14bbe189cb7d67245f
. Census 197 -> ... -> 203 at
b764adc (pushed e137088..b764adc,
4 files changed, 968 insertions,
r285_splice.py created). Next:
R286 III.E Special part 7 - the
Iron Flask of Tuerny the
Merciless onward in part2 from
line 1405 (global 12470; the
Jacinth of Inestimable Beauty,
Johydees Mask and the other
descriptions follow; the III.E
Special prose continue).
R286 landed the III.E Special
artifacts explanation prose part
7 (part2 lines 1405-1451, DMG
p.162-163) - the Iron Flask of
Tuerny the Merciless, the
Jacinth of Inestimable Beauty
and Johydees Mask, the 12th
through the 14th of the 29
descriptions (Flask powers
3,0,1,0,1,1 total 6, 3 words and
5 prisoners; Jacinth powers
2,2,1,1,1,1 total 8, the 20 foot
charm save; Mask powers
2,1,0,0,0,1 total 4, the gaze
trio), 27 accessors: 24 scalars
+ 3 walkers. One seam restored:
the p.162-163 page break falls
between the Mask power table
and the Kuroth Quill opener -
nothing severed this time. One
pre-land self-assert bug: the
AUDIT comment first split One
seam restored across two lines
(fixed by rewrapping the comment
block). RED targets: return 20
(unique scalar, bad 1) and - new
this round, since no second
unique scalar existed - the
Mask walker table entry mutated
(bad 2, probed by both the loop
and the sum). The audit
cross-pins the R240 sale rows:
the Flask band 30-31 at 50000
row 11, the Jacinth band 32 at
100000 row 12, the Mask band 33
at 40000 row 13. The user paste
matched the md5 prediction
EXACTLY (the 14th round in a
row); landed splice, regtest and
gap report byte-exact fetched at
3c65ded, the R285/R281 gates
unchanged (specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
87921ef21e89279f13a5c4f7ac7f151c
); audit_eval on the landed tree
GREEN (R286 verified bad 0 over
28 asserts, sweep 80). REAL GATE
specartprose2.h
8dfa320a3b692c2e9cca2173d9c18ed6
. Census 197 -> ... -> 204 at
3c65ded (pushed b764adc..3c65ded,
4 files changed, 891 insertions,
r286_splice.py created). Next:
R287 III.E Special part 8 -
Kuroths Quill onward in part2
from line 1452 (global 12517;
the Mace of Cuthbert, the
Machine of Lum the Mad and the
other descriptions follow; the
III.E Special prose continue).
R287 landed the III.E Special
artifacts explanation prose part
8 (part2 lines 1452-1497, DMG
p.163) - Kuroths Quill, the Mace
of Cuthbert and the Machine of
Lum the Mad, the 15th through
the 17th of the 29 descriptions
(Quill powers 2,0,1,1,0,1 total
5, the potion of treasure
finding 1 time per month; Mace
powers 3,2,0,0,0,1 total 6, the
+5 bonus, the 18 strength
requirement; Machine powers
15,15,10,10,15,5 total 70, 60
levers, 40 dials, 20 switches,
one-half of the 120 still
function, 5,500 pounds, the 1-4
jolt destruction, the booth for
4), 31 accessors: 28 scalars + 3
walkers. No seam restored this
time - the p.162-163 break fell
in R286 and no page break falls
within the 46 lines. One
pre-land self-assert bug: the
AUDIT comment first split No
seam restored across two lines
(fixed by rewrapping the comment
block). RED targets: return 70
and return 5500, both unique
scalars this time (bad 2 and bad
1, no walker mutation needed).
The audit cross-pins the R240
sale rows: the Quill band 34-35
at 27500 row 14, the Mace band
36-37 at 35000 row 15, the
Machine band 38 at 72500 row 16.
The user paste matched the md5
prediction EXACTLY (the 15th
round in a row); landed splice,
regtest and gap report
byte-exact fetched at d800fb5,
the R286/R281 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
0e1390826d3b75bbfee3d030baac0232
); audit_eval on the landed tree
GREEN (R287 verified bad 0 over
29 asserts, sweep 81). REAL GATE
specartprose2.h
7e8bdce288cc12a430fc8e0ec741c187
. Census 204 -> 205 at d800fb5
(pushed 3c65ded..d800fb5,
4 files changed, 942 insertions,
r287_splice.py created). Next:
R288 III.E Special part 9 - the
Mighty Servant of Leuk-O onward
in part2 from line 1498 (global
12563; the Orb of Dragonkind and
the other descriptions follow;
the III.E Special prose
continue).
R288 landed the III.E Special
artifacts explanation prose part
9 (part2 lines 1498-1517, DMG
p.163) - the Mighty Servant of
Leuk-O, the 18th of the 29
descriptions (a towering
automaton of crystal, unknown
metals and fibrous material, 9
feet tall, 6 deep, 4 and
one-half wide; armor class
minus 1, 60 hit points, weapons
at 50 percent, regen 2 per
round, magic resistance 100
percent, 6 elements immune,
electrical only 20 percent;
speed 3 inches, 12 hours of
operation then 1 hour of rest;
panic within 12 inches, save at
+2; 1 attack per round, base 15
percent to hit, minus 2 and
one-half percent per dexterity
point above 14; a hit does
10-100 hit points; powers
6,6,1,2,0,2 total 17), 29
accessors: 28 scalars + 1
walker. No seam restored this
time - no page break falls
within the 20 lines. One
pre-land self-assert catch: the
first draft cross-referenced the
R287 Machine lever accessor and
the strict audit-probe equality
assert rejected it (prior rounds
cross-pin only non-sap rows);
replaced with an in-round frame
sum. RED lesson: the mutation
value must not exist elsewhere
in the header (mutating 17 to 18
and 9 to 8 collided with 2 and 5
pre-existing returns, caught by
the restore md5 mismatch; redone
as 1701 and 909, bad 2 and bad
1, restores byte-exact). The
audit cross-pins the R240 sale
row: the Servant band 39-40 at
185000 row 17. The user paste
matched the md5 prediction
EXACTLY (the 16th round in a
row); landed splice, regtest and
gap report byte-exact fetched at
b4a8d17, the R287/R281 gates
unchanged (specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
a9790bdea2ed01bbd6fe4b286ac1aab9
); audit_eval on the landed tree
GREEN (R288 verified bad 0 over
16 asserts, sweep 82). REAL GATE
specartprose2.h
d307a50d19d22c632f6719d25ab3d352
. Census 205 -> 206 at b4a8d17
(pushed d800fb5..b4a8d17,
4 files changed, 814 insertions,
r288_splice.py created). Next:
R289 III.E Special part 10 - the
Orb of Dragonkind onward in
part2 from line 1518 (global
12583; the 8 jade globes, the
notes and the other
descriptions follow; the III.E
Special prose continue).
R289 landed the III.E Special
artifacts explanation prose part
10 (part2 lines 1518-1556) - the
Orb of Dragonkind intro and its
1st through 5th globes (the
Hatchling, the Wyrmkin, the
Dragonette, the Dragon and the
Great Serpent), the first half
of the 19th of the 29
descriptions (8 white jade
globes, 1 per dragon age, 3 to
10 inches, the deities and
demons origin; the intelligence
and ego ladder 9/9, 10/10,
11/11, 12/12, 13/13, pinned
with 4 ladder asserts; powers
3,0,0,0,0,0 (3), 2,1,0,0,0,0
(3), 3,1,1,0,0,0 (5),
4,1,1,0,0,0 (6), 3,2,1,0,0,1
(7)), 28 accessors: 23 scalars
+ 5 walkers. One break absorbed:
the extra blank pair at
1555-1556 between globes 5 and
6; no page seam claimed (no
running heads between upload
lines 1450 and 1797). No
pre-land self-assert bug - the
two-pass ran clean first try.
No unique scalar RED targets
existed (every candidate value
pre-exists or the INT and ego
pairs double them), so both RED
targets were walker table
mutations (the R286 precedent):
the dragonette VI entry 0 to 8
and the great serpent VI entry 1
to 9, both bad 2 (loop plus
sum), mutation values verified
absent pre-mutation (the R288
lesson), restores byte-exact.
The audit cross-pins the R240
sale row - the Dragonkind band
41-47 at 10000 to 80000, the
only range row, its high bound
carried by saSaleGpHi (first
use); part1 names it Orb of
the Dragonkind, a the-quirk. The
user paste matched the md5
prediction EXACTLY (the 17th
round in a row); landed splice,
regtest and gap report
byte-exact fetched at 6f5afdc,
the R288/R281 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
3b7cf36b10dcdcad2f9157261bbcabee
); audit_eval on the landed tree
GREEN (R289 verified bad 0 over
47 asserts, sweep 83). REAL GATE
specartprose2.h
170e324a9e765b4bf3bb8525df61f22b
. Census 206 -> 207 at 6f5afdc
(pushed b4a8d17..6f5afdc,
4 files changed, 952 insertions,
r289_splice.py created). Next:
R290 III.E Special part 11 -
the Orb of Dragonkind continues
with its 6th through 8th globes
and the notes, in part2 from
line 1557 (global 12622; the
Firedrake, the Elder Wyrm, the
Eternal Grand Dragon and the
notes follow; the III.E Special
prose continue).
R290 landed the III.E Special
artifacts explanation prose
part 11 - the expanded-scope
round (the user chose the modest
expansion): the Orb of Dragonkind
globes 6 through 8, the notes and
the full Orb of Might, part2
lines 1557-1624 (global = 11065
+ part2 line), the second half of
the 19th and the 20th of the 29
descriptions. Globe 6, the
Firedrake: charms any old dragon,
14 and 14; powers 3,3,2,0,0,1
total 9. Globe 7, the Elder Wyrm:
very old dragons, 16 and 16;
powers 4,3,2,1,1,1 total 12.
Globe 8, the Eternal Grand
Dragon: ancient dragons, 18 and
18, +8 saves, attacks and damage
vs Tiamat or Bahamut; powers
4,3,2,1,2,1 total 13. The ladder
rises by two, 14 through 18. The
notes: strong evil component;
neutral or good possessors save
versus magic to resist charming;
range 5 inches, 1 full round,
awake and aware; evil automatic,
neutral -4, good -2; 50 percent
wisdom charmed; feeblemind 3
intelligence, insanity 50
percent; an active and awake
mind only; sacrifice destruction.
The Orb of Might: source the
foregoing Crown of Might; 3 Orbs;
ethos 01-06 evil, 07-14 good,
15-20 neutrality; another ethos
touching saves versus magic or
dies, 4-24 on success; Crown
and/or Sceptre invokes Table IV;
platinum, gem-encrusted, 100000
or more gold pieces; a Gem of
Brightness; powers 2,0,1,0,0,0
total 3 per ethos over 3 columns.
No break absorbed - the round
closes on the standard blank at
1624; no page seam claimed (no
running heads between lines 1450
and 1797). The quirks: the globe
heads keep the while the Might
head drops it; 18 true
multiplication signs; the range
mark prints as the curly right
double quote; the save penalties
print with the true minus sign;
the Might table prints its good
and neutrality III slots as
backslash continuation rows - all
pinned as plain digits and words.
48 accessors: 44 scalars + 4
walkers. The groundtruth pass
earned its keep pre-delivery -
the ethos column count swallowed
the alignment-table labels
(6 vs 3); fixed before the
splice left the bench. RED
targets: the scalar
sapOrbMightValueGp 100000 to
1000000, its value absent
pre-mutation (bad 1); the eternal
walker VI 1 to 9, a unique line
(bad 2); restores byte-exact. The
audit cross-pins the R240 sale
row 19 - the Might band 48-63 at
100000, a fixed row, its zero
high bound carried by saSaleGpHi,
in contrast with the
Dragonkind range row. The user
paste matched the md5
prediction EXACTLY (the 18th
round in a row); landed splice,
regtest and gap report
byte-exact fetched at eeb76af,
the R289 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
b5164c4f991f40699977c3c097be7ad6
); audit_eval on the landed tree
GREEN (R290 verified bad 0 over
38 asserts, sweep 84). REAL GATE
specartprose2.h
5ed21bae1c1273175316dd4376d98842
. Census 207 -> 208 at eeb76af
(pushed 6f5afdc..eeb76af,
4 files changed, 1180 insertions,
r290_splice.py created). Next:
R291 III.E Special part 12 -
Queen Ehlissas Marvelous
Nightingale in part2 from
line 1625 (global 12690; the
Recorder of YeCind and the other
descriptions follow; the III.E
Special prose continue).
R291 landed the III.E Special
artifacts explanation prose
part 12 - the Nightingale, the
Recorder of YeCind and the Ring
of Gaxx pinned in part2 lines
1625-1676 (global 12690-12741),
the 21st, 22nd and 23rd of the
29 descriptions; no break
absorbed (the round closes on
the standard blank at 1676); no
page seam (no running heads
between 1450 and 1797). Queen
Ehlissas Marvelous Nightingale:
Xagy made it with the volcano
goddess Joramy, Mordenkainen
dated it 17 centuries back;
Ehlissa bent all to her will;
never escaped its confinement;
a fine mesh of golden wires;
wings open, hops to the perch,
performs; eyes shoot colored
rays; songs work magical
wonders; rays and songs
combined weave spells; sphere
radius 30 feet blocking
detection, magic and psionic
intrusion; within it none
hunger or thirst; powers
4,0,1,1,1,1 total 8. The
Recorder of YeCind: needs no
musician, plays the most
complicated airs on command,
stolen-goods alarm radius 30
feet, alarms for itself stolen
as well, information through
clue-word songs, rumored to
cast spells with its notes;
powers 5,2,1,1,1,1 total 11 -
it prints its slots before its
count lines. The Ring of Gaxx:
origin totally alien, platinum
loop about a fine spinel,
workmanship unique, gem
unknown, donned on a finger to
discover powers, nine facets,
each facet powers when faced
to the top, turns itself off,
on, or when asleep, a random
facet each day secret to the
DM, one known facing reveals
the order, unmarkable - even a
wish will not help; powers
3,2,1,1,1,1 total 9, equal to
its facet count. The radii
agree - the Nightingale sphere
and the Recorder alarm both 30
feet. The quirks: Ehlissas and
YeCind drop their curly
apostrophes; the feet marks
print curly; 17 true
multiplication signs; an em
dash in Gaxx; 3 backslash
continuation rows (1635, 1651
and 1657); the Gaxx III to VI
rows carry trailing commas -
all pinned as plain digits and
words. 35 accessors: 32
scalars + 3 walkers. RED
targets: the scalar
sapNightingaleMadeCenturiesAgo
17 to 170000, block-targeted -
a pre-existing return 17;
sits elsewhere and the value
absent pre-mutation (bad 1);
the Gaxx walker IV 1 to 8, a
unique line (bad 2, the loop
and the sum both catch it);
restores byte-exact. The audit
cross-pins the R240 sale rows
20, 21 and 22 - the
Nightingale band 64/64 at
112500, the Recorder band
65/66 at 80000, the Gaxx band
67/68 at 17500, all fixed rows,
zero high bounds carried by
saSaleGpHi, each pinned against
specart.h AND the part1
upload. The user paste matched
the md5 prediction EXACTLY
(the 19th round in a row);
landed splice, regtest and gap
report byte-exact fetched at
8d51ba7, the R290 gates
unchanged (specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
a35c72df8409267e47365f4043740097
); audit_eval on the landed
tree GREEN (R291 verified bad 0
over 29 asserts, sweep 85).
REAL GATE specartprose2.h
56db7b254dcdbd6833883baa4f92712b
. Census 208 -> 209 at 8d51ba7
(pushed eeb76af..8d51ba7,
4 files changed, 991
insertions, r291_splice.py
created). Next: R292 III.E
Special part 13 - the Rod of
Seven Parts solo in part2 from
line 1677 (global 12842; the
Sceptre of Might and the Sword
of Kas follow; the III.E
Special prose continue).
R292 landed the III.E Special
artifacts explanation prose
part 13 - the Rod of Seven Parts
solo (the 24th of the 29
descriptions), part2 lines
1677-1707 (global 12742-12772;
the R291 gap next pointer had
misstated the global as 12842 -
this round documents the
correction). The Wind Dukes of
Aaqa built it for the great
battle of Pesh where Chaos and
Law contended; shattered there,
its parts scattered, yet nothing
could destroy it; the sections
joined in the correct order give
a weapon of surpassing power.
The 7 parts differ - the first
largest in length and diameter,
the seventh smallest; no single
part has any power alone; each a
short bar or baton, the seventh
much like a short metal wand. The
first senses the direction of the
second, only when thought of as a
fraction of a whole; a found
section leads only to the next
higher numbered; an out-of-order
touch teleports the higher piece
100 to 1,000 miles; assembled it
is almost 5 feet. Three fitted
sections and the possessor cannot
let go while living, until all
parts join; part powers are
cumulative, full powers need
every part; no disassembly by the
possessor, and each prime power
use risks a 1 in 20 (5 percent)
breakup, the pieces teleporting
100-1200 miles. The assembly
table: joints 1-2 table III, 2-3
table I, 3-4 table I, 4-5 table
IV, 5-6 table II, 6-7 table VI,
one use each (walker 3,1,1,4,2,6,
total 6). The complete rod
powers: I once, II once, III
twice, V twice, IV once (walker
1,1,2,1,2,0, total 7) - V prints
before IV, and no VI slot though
the assembly has one. Out of
order the powers are not
cumulative - only the last piece
joined stays active, prior
negated. No break absorbed (the
round closes on the standard
blank at 1707); no page seam (no
running heads between 1450 and
1797; the 1684 and 1694 heads
are the description own
sub-heads). The quirks: the 5
feet mark prints curly; nine em
dashes; eleven true
multiplication signs; the out-
of-order hyphen wraps across the
1677 line break; 100 to 1,000
prints with comma and to, the
1682 range as plain 100-1200; 13
blank underscore runs of 11 each,
DM-filled. 41 accessors: 38
scalars + 3 walkers. RED
targets: the scalar
sapRodBreakupTeleportMaxMiles
1200 to 12000, block-targeted,
its value absent pre-mutation
(bad 1); the complete walker III
2 to 9, a unique line (bad 2,
the loop and the sum both catch
it); restores byte-exact. The
audit cross-pins the R240 sale
row 23 - the Rod band 69-74 at
25000, a range row, its price
fixed by the zero saSaleGpHi,
pinned against specart.h AND the
part1 upload. The user paste
matched the md5 prediction
EXACTLY (the 20th round in a
row); landed splice, regtest and
gap report byte-exact fetched at
1157643, the R291 gates
unchanged (specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
505af443380eb358812bc00c56ec4623
); audit_eval on the landed tree
GREEN (R292 verified bad 0 over
the R292 block, sweep 86). REAL
GATE specartprose2.h
fc2a7d1b2e89fccf2ee1075ad5e04545
. Census 209 -> 210 at 1157643
(pushed 8d51ba7..1157643,
4 files changed, 1066
insertions, r292_splice.py
created). Next: R293 III.E
Special part 14 - the Sceptre of
Might and the Sword of Kas in
part2 from line 1708 (global
12773; the Teeth of Dahlver-Nar
and the other descriptions
follow; the III.E
Special prose continue).
R293 landed the III.E Special
artifacts explanation prose
part 14 - the Sceptre of Might
and the Sword of Kas (the 25th
and 26th of the 29 descriptions),
part2 lines 1708-1743 (global
12773-12808). The Sceptre: 3 of
them, sourced to the foregoing
Crown of Might section; ethos
bands 1-6 evil, 7-14 good,
15-20 neutrality, agreeing with
the R290 Orb die bands; a
foreign-ethos touch works the
Crown effects; bronze inlaid
with silver and many fine gems,
a huge precious stone tipping
its 2 feet length; value 150000
or more gold pieces on the open
market; it functions as a Rod of
Beguiling; powers one use each
of tables I, II and VI (walker
1,1,0,0,0,1, total 3); combo
powers with a same-ethos Crown
or Orb - see Crown of Might.
The Sword of Kas: the Vecna
legend - Kas the most evil and
ruthless lieutenant, bodyguard
and right hand; a long and thin
flatchet of dull gray metal,
unsurpassed hardness, sharp
point, keen edges, magical
properties; he served
faithfully, his hubris grew, the
Sword urging him on - greater
than Vecna, he could rule in
Vecna stead; legend: Kas and
his Sword destroyed Vecna, but
Vecna wrought the lieutenant
doom too, the world made
brighter. A +6 defender, double
damage against creatures from
planes other than the Prime
Material, but only normal damage
when on any plane other than
it; a short sword, highly evil
and chaotic; 15 intelligence,
19 ego, and it will attempt to
control whoever takes it;
powers 5 of I, 2 of II, 1 of
III, 2 of IV, 2 of V, 1 of VI
(walker 5,2,1,2,2,1, total 13),
printed in order I through VI,
unlike the Rod complete list.
No break absorbed - the round
closes on the standard blank at
1743; no page seam (no running
heads between 1450 and 1797).
The quirks: the Vecna quote
prints inside curly double
quotes, its three curly
apostrophes dropped here
(characters, Vecnas,
lieutenants); the 2 feet mark
prints curly; nine true
multiplication signs; one plus
sign in +6; the Sceptre table
prints its Evil cells empty,
double blanks under Good and
single blanks under Neutrality -
9 underscore runs of 15; the
Kas slots print 13 runs of 11,
one per use. 45 accessors: 43
scalars + 2 walkers. RED
targets: the scalar sapKasEgo
19 to 190, block-targeted, its
value absent pre-mutation (bad
1); the Kas walker III 1 to 9,
a unique line (bad 2, the loop
and the sum both catch it);
restores byte-exact. The audit
cross-pins the R240 sale rows 24
and 25 - the Sceptre band 75-91
at 150000, a range row, its
price fixed and equal to its
open market value; the Kas band
92 at 97000, a fixed single-die
row; zero high bounds carried by
saSaleGpHi, pinned against
specart.h AND the part1 upload.
The user paste matched the md5
prediction EXACTLY (the 21st
round in a row); landed splice,
regtest and gap report
byte-exact fetched at f02b7e6,
the R292 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
f4eb51efa4d11891669418c1bf0022ee
); audit_eval on the landed tree
GREEN (R293 verified bad 0,
sweep 87). REAL GATE
specartprose2.h
2c0b5bc03b87983eba69239d544c071e
. Census 210 -> 211 at f02b7e6
(pushed 1157643..f02b7e6,
4 files changed, 1061
insertions, r293_splice.py
created). Next: R294 III.E
Special part 15 - the Teeth of
Dahlver-Nar solo in part2 from
line 1744 (global 12809; the
Throne of the Gods and the other
descriptions follow; the III.E
Special prose continue).
R294 landed the III.E Special
artifacts explanation prose
part 15 - the Teeth of
Dahlver-Nar solo (the 27th of
the 29 descriptions), part2
lines 1744-1781 (global
12809-12846). The cleric of
legend: if any was more
powerful than the renowned
Dahlver-Nar, histories do not
tell us; the gods themselves
gave him special powers,
passed on by the great relics -
his teeth; each Tooth has some
power; a full quarter, half,
or all brings other grand
benefits; a tooth grafts into
the mouth in place of a like
missing tooth, never removed
once emplaced short of the
demise of the possessor; the
powers and effects are
cumulative. The tooth table:
32 teeth in 16 two-column rows,
per-table counts 21, 4, 4, 1,
0, 2 (walker 21,4,4,1,0,2,
total 32); the lone IV is tooth
21; the VI teeth are 7 and 14;
the II teeth are 2, 16, 24 and
28; the III teeth are 3, 9, 26
and 29. The set table: 8
two-column pair rows - the
quarters 1-8 at II+VI, 9-16 at
II+IV, 17-24 at II+III, 25-32
at II+III - then the halves
repeat those four rows
verbatim; 3 table V rows
(1-16, 17-32, 1-32); the
right-column walker
0,0,4,2,0,2 totals the 8 pair
rows. The quirks: the cleanest
section yet - zero apostrophes,
zero em dashes, zero
backslashes, zero percent
signs; 51 true x-signs and 51
blank runs of exactly 14
underscores, the x-sign count
equal to the blank count, both
pinned and the identities
audited (blanks equal the uses
plus twice the pair rows plus
the V rows; both columns sum to
the pair rows plus the V rows).
37 accessors: 35 scalars + 2
walkers (defs 435 -> 472); RED
1 the UnderscoreRunLen scalar
14 -> 1400 (block-targeted, the
value absent pre-splice, bad
1); RED 2 the SetRightUse
walker slot 5: 2 -> 8 (unique
line, bad 2 - the loop and the
sum both catch it); restores
byte-exact. The audit
cross-pins the R240 sale row 26
- the Teeth band 93-98 at
5,000/tooth, a range row, its
part1 price suffix stripped,
zero high bound via saSaleGpHi,
pinned against specart.h AND
the part1 upload. The user
paste matched the md5
prediction EXACTLY (the 22nd
round in a row); landed splice,
regtest and gap report
byte-exact fetched at 3854201,
the R293 gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
5f5790bfffd9ecd59038061f09da90c9
); audit_eval on the landed
tree GREEN (R294 verified bad
0, sweep 88). REAL GATE
specartprose2.h
f51346257168c2d285345287bb9e1fe9
. Census 211 -> 212 at 3854201
(pushed f02b7e6..3854201,
4 files changed, 958
insertions, r294_splice.py
created). Next: R295 III.E
Special part 16 - the Throne of
the Gods and the Wand of Orcus
in part2 from line 1782 (global
12847; the last of the plan; the
III.E Special prose continue).
R295 landed the III.E Special
artifacts explanation prose
part 16 - the Throne of the
Gods and the Wand of Orcus
(the 28th and 29th of the 29
descriptions), part2 lines
1782-1814 (global 12847-12879)
- the last of the plan, the
III.E Special set now
COMPLETE. The Throne: carven
from the heart of a majestic
mountain, a massive stone
chair inlaid with mosaics of
ivory and precious metals and
set about with gems, a throne
upon which certain gods
actually sat when they walked
the world; within a great
cavern, part of the mountain
core, immobile and immovable;
anyone daring to seat himself
or herself is subject to the
effects; certain, per fables,
to gain a magic item, but with
a malevolent effect too; the
item gain cannot repeat, but
the Throne can still affect
the seated one if the proper
words and gestures are known
and followed - the seated one
grasps either arm, both, or
none (3 options) and utters a
command; powers 3 of I, 3 of
II, 2 of III, 2 of IV, 2 of
V, 2 of VI (walker
3,3,2,2,2,2, total 14). The
Wand of Orcus: the ghastly
weapon, property of the demon
prince Orcus, at times allowed
to pass into the Prime
Material Plane to wreak chaos
and evil on all living things
there; see MONSTER MANUAL,
Demon, Orcus; the wielder
lacks the full death-dealing
power - the victim saves
versus magic to avoid death or
annihilation; six ranks
unaffected at all: gods,
godlings, demon lords, greater
devils, saints, demi-gods;
powers 4 of I, 2 of II, 2 of
III, 1 of IV, 1 of VI, no
table V (walker 4,2,2,1,0,1,
total 10). The quirks: 11 true
x-signs, 24 blank runs of
exactly 14 underscores; the
Throne lines carry no bullets
but the Wand prints all 5
table lines with leading -
bullets; the Wand 4 x I line
joins runs 3 and 4 with a
space, not a comma - 4 runs, 2
commas; 2 curly apostrophes
(the mountain core, the Throne
magic), zero ASCII
apostrophes, zero em dashes,
all dropped here; the page
seam absorbed at 1797 (a
running head inside the
round); the round closes on
the standard blank at 1814
and the head at 1815 sits
outside it; No break absorbed.
51 accessors: 49 scalars + 2
walkers (defs 472 -> 523); RED
1 the WandImmuneCount scalar 6
-> 63 (block-targeted, the
value absent pre-splice, bad
1); RED 2 the ThroneTableUse
walker slot 5: 2 -> 8 (unique
line, bad 2 - the loop and the
sum both catch it); restores
byte-exact. The audit
cross-pins the R240 sale rows
27 and 28 - the Throne band 99
priced --- (zero gold pieces),
the Wand band 00, the d100
wraps to row value 100, at
10,000; zero high bounds via
saSaleGpHi, pinned against
specart.h AND the part1
upload. The user paste
matched the md5 prediction
EXACTLY (the 23rd round in a
row); landed splice, regtest
and gap report byte-exact
fetched at 680188e, the R294
gates unchanged
(specartprose.h
0f6e3b68e40088474daa9b98f9194a81
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, splice
dec5ae07708c0e76512de2c44b3dcb86
); audit_eval on the landed
tree GREEN (R295 verified bad
0, sweep 89). REAL GATE
specartprose2.h
7be15a8a79e40e93658cea7c247df348
. Census 212 -> 213 at 680188e
(pushed 3854201..680188e,
4 files changed, 1190
insertions, r295_splice.py
created). The 29 descriptions
landed across the 16 splice
rounds R280-R295 (census 198
-> 213); the
plan is COMPLETE - no further
round scheduled; the III.E
Special prose COMPLETE).
R296 landed the PHB gap report
scope round at fe69167 (pushed
680188e..fe69167, 3 files
changed, 350 insertions,
tools/r296_splice.py created).
The user asked: are there any
missing wirings from the PHB?
The ledger read green - zero
open items - but diffing the
PHB upload against it found
five sections never explicitly
pinned or marked OUT. The
report round (the R177
template) records them: two
OPENED - the Weapon
Proficiency Table (ten class
rows: initial slots, the -2 to
-5 non-proficiency penalty,
the added-slot cadence 1/2 to
1/6 levels; UNWIRED, the R297
pin candidate) and the Thief
Function Take table plus DEX
Table II (levels 1-17, eight
functions, six racial rows,
scores 9-18; the engine pins
the six shared ability names
in subclassspecials.h but no
percentages; a data-only R298
candidate, the R186 poetics
precedent) - and three
recorded OUT: money changing,
banks, loans and jewelers (the
gold-only economy), Appendix
V (the treasure division
agreements, player-side) and
Appendix IV (the known planes
- no planar layer). Two
patches: the R296 SCOPE PASS
section appended to
tools/phb_gap_report.md (the
R178 precedent: open first,
pin in following rounds, flip
the boxes in the same
commits) and the round note
inserted into
tools/dmg_gap_report.md
between the R295 entry tail
and the Categories anchor. A
report round adds NO audit;
the census stays 213; the real
gate is the patched
phb_gap_report.md md5. Landed
gates at fe69167:
phb_gap_report.md
a9b9e21154ad16276c3883b41ae69032
(REAL GATE),
dmg_gap_report.md
98eb7667643be1320559915ac4cd9b32
, splice
6760169743abb7aecef625788400f911
; specartprose2.h
7be15a8a79e40e93658cea7c247df348
, regtest.cpp
3ac8f516087a6a284b2a7202258bcb7d
and miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
all unchanged; audit sweep
89 verified, 213 labels,
identical to 680188e; the
derived check rebuilt on the
landed tree GREEN (proficiency
rows 10/10 parsed from the
upload, take table 17 levels
plus 6 racial rows, DEX II
9-18, the three OUT sections
found in the upload). The
user paste matched the md5
prediction EXACTLY (the 24th
round in a row). One ritual
hitch: the first paste
included the shell prompt
prefix on every line, so bash
failed each line (nothing
executed, nothing landed);
the one-block ritual with
pure commands only worked.
Next candidates: R297 the
proficiency table pin (live
to-hit wiring), R298 the
thief tables (data-only).

R297 landed at a0f0694
(pushed fe69167..a0f0694).
A full pin round: the
weapon proficiency table,
the item R296 opened, now
pinned live. 7 files
changed, 1099 insertions,
25 deletions; created
rules/weaponprof.h and
tools/r297_splice.py.

Round contents. The new
header rules/weaponprof.h
holds the 10 printed rows
(cleric 2 -3 1-4, druid
2 -4 1-5, fighter 4 -2
1-3, paladin 3 -2 1-3,
ranger 3 -2 1-3,
magic-user 1 -5 1-6,
illusionist 1 -5 1-6,
thief 2 -3 1-4, assassin
3 -2 1-4, monk 1 -3 1-2
levels), the wpfRowFor
class-to-row mapping, the
wpfSlotsAt added-slot
walker, and the
wpfNonProfHitAdj seam.
Wiring is live in the
engine: Actor hit
adjustment folds the
non-proficiency penalty
(an empty proficiency
list keeps the pre-R297
convention, monk open
hand stays 0), and kitNpc
records kit weapons. The
regtest battery gained
the R297 weapon
proficiency table pins
audit (census 213 to
214). The phb ledger
item flipped to PINNED
R297, Census 214.

Gates at a0f0694:
rules/weaponprof.h
abe3e9884289b852bee81b25c6e91d02
(REAL GATE), splice
a34f6c17a675a256088a285c1f442248
(advisory EXACT, the
25th round in a row),
regtest.cpp
486e499a251b73ffb617c84f2668b172
, phb_gap_report.md
dab3b044c98eb2f02612fb42618366bc
, ai/actor.h
13b48e87a82c47820308924328ed3402
, ai/actor.cpp
34126dfca07f2c6268b9004dcd36d4be
, game/state_combat.cpp
b0e32880d624c74a5f6b7dc04f669850
; untouched:
specartprose2.h
7be15a8a79e40e93658cea7c247df348
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, subclassspecials.h
54baec9bbe1bbde1872a3891a875f771
, dmg_gap_report.md
98eb7667643be1320559915ac4cd9b32
.

Battery on the landed
tree: audit_eval R297
GREEN bad 0, sweep 90
verified (prior 89 plus
1), census 214; the
derived check rebuilt on
the landed tree GREEN
(upload rows 10/10 match
the header arrays in
printed order, cleric
walker math, wiring
intact, ledger flip); RED
1 (scalar block
mutation) bad 1 and RED
2 (walker line
mutation) bad 3,
restored byte-exact;
label diff vs fe69167
the new line only; the
canvas body plus newline
equals the landed splice
byte-exact.

The ledger now holds ONE
open item: R298, the
thief function take table
plus DEXTERITY TABLE II
(data-only pin, the R186
poetics precedent), at
upload lines 1620, 1643
to 1650 and 400.

R298 landed at 16c96f2
(pushed a0f0694..16c96f2).
A DATA-ONLY pin round (the
R186 precedent): the Thief
Function Take table and
DEXTERITY TABLE II - the
LAST open phb ledger item.
The phb gap report now
holds ZERO open items (the
R176 dmg moment, phb side).
4 files changed, 1034
insertions, 18 deletions;
created rules/thieffunc.h
and tools/r298_splice.py.

Round contents. The new
header rules/thieffunc.h
holds the take table
(upload line 1620): 17
levels x 8 functions
pinned in TENTHS of a
percent (the climb walls
column carries a decimal
from the 11th level:
99.1% reads 991; the read
languages dash at levels
1-3 reads 0), the six
racial rows (upload lines
1645-1650) keyed to the
races.h enum (the human
prints no row and reads
0), DEX Table II (upload
line 400): five columns,
scores 9-18, the band
clamp reads the 9 row
below and the 18 row
above (the character.h DEX
I convention), hear noise
+ climb walls + read
languages print no column
and read 0, the seam
thfChanceTenths = base +
10 x (race adj + dex adj),
and the printed notes
(percentile roll equal or
less succeeds, the 21%
pockets notice band, the
5% victim cut per level
above the 3rd, the locks
and traps one-try rules).
The regtest battery gained
the R298 pins audit
(census 214 -> 215); the
ledger item flipped to
PINNED R298, Census 215.

JUDGMENT (the derived
check caught it): the
dwarf racial row was first
pinned from assistant
memory as HN -10, CW -5,
RL 0; the upload OCR token
sequence AND the 1eonline
compilation (column-exact,
9 cells) both read MS 0,
HS 0, HN 0, CW -10, RL
-5. Sources win; pinned
0, 10, 15, 0, 0, 0, -10,
-5. The 3-way check
(upload == compilation ==
header == audit) is now
standard for table pins.

LESSON (RED 2): a level
clamp mutation 17 -> 16
SURVIVED the first clamp
probes - levels 16 and 17
print identical PP and RL
values, so probes on
those columns cannot see a
slipped upper clamp. The
audit gained an open locks
clamp probe (thfTakeTenths
(1, 99) must read 990;
L16 reads 970) and the
mutation then fired bad 1.
Clamp probes must target a
column where the band
edges differ.

Gates at 16c96f2:
rules/thieffunc.h
b5fc0394cd764eabea9e081c86336829
(REAL GATE), splice
7f9ca254c2406ada57b05ca9ce3692cb
(advisory EXACT, the 26th
round in a row),
regtest.cpp
05617ce854708c1cd1aa33171f39ccc7
, phb_gap_report.md
4c0190c80afc49e6b17b313ef1871d44
; untouched: weaponprof.h
abe3e9884289b852bee81b25c6e91d02
, r297_splice.py
a34f6c17a675a256088a285c1f442248
, actor.h
13b48e87a82c47820308924328ed3402
, actor.cpp
34126dfca07f2c6268b9004dcd36d4be
, state_combat.cpp
b0e32880d624c74a5f6b7dc04f669850
, specartprose2.h
7be15a8a79e40e93658cea7c247df348
, miscprose23.h
9e0eb3d74e5d6f9e93a5ba377039bcee
, subclassspecials.h
54baec9bbe1bbde1872a3891a875f771
, dmg_gap_report.md
98eb7667643be1320559915ac4cd9b32
.

Battery on the landed
tree: audit_eval R298
GREEN bad 0 (270 asserts),
sweep 91 verified (prior
90 plus 1), census 215;
the derived check rebuilt
on the landed tree GREEN
(17 take rows, 7 racial
rows, 10 DEX rows match
the upload; the printed
example 100 + 10 + 10 -
45 = 75); RED 1 (scalar
991 -> 990) bad 1; RED 2
(clamp 17 -> 16) bad 1
after the probe fix; the
commit shape predicted
exactly (4 files, 1034
insertions, 18 deletions);
the canvas body plus
newline equals the landed
splice byte-exact.

The ledger is CLOSED. The
next rounds are wiring or
fresh scope: the thief
rolls (thfChanceTenths has
no callers yet), the party
roster proficiency
recordings, the ranged
slot, or a new gap pass.

R299 landed. The party kit
weapon recordings wired and
the third scope pass. Commit
e34da70 (pushed 16c96f2..
e34da70), 8 files, 1380
insertions, 14 deletions.
Paste streak 27 (md5
1e23b9ccbb2b5d9aa9501de7adc
fc538). Two-pass applied 7 /
already 7. REAL GATE
rules/weaponprof.h
846239289409abec7b43eb4183a2
8676 = prediction; all seven
touched md5s matched
(party.h 50cc0eb4, appstate.h
a42b4a4b, state_core.cpp
4166e0c6, actor.h 9ab2e6cd,
regtest.cpp f503bbfa,
phb_gap_report.md cccd85e8);
guards byte-stable
(thieffunc.h b5fc0394,
r298_splice.py 7f9ca254,
actor.cpp 34126dfc,
state_combat.cpp b0e32880,
dmg_gap_report 98eb7667).

Battery: preflight GREEN,
census 215 -> 217, both new
audits bad 0 AT BATTERY -
the R299 engine audit ran
live, so the runtime wiring
is verified (the factories,
the switches, the toActor
copy, the live proficiency
gate). audit_eval R299a
verified bad 0 (21 asserts);
sweep 91 -> 92 verified.
Derived check on the landed
tree GREEN: 5 grant call
sites, the kit ids agree
across the three switches
(makeMember, the switch, the
grant), the thief case
pushes exactly 2, census 217,
the ledger holds ONE open
item, guards byte-stable,
the scope claims verified
against the upload.

LESSONS R299:
1. The commit shape was
predicted 1379, landed 1380:
the splice file ends with
TWO trailing newlines, and
wc counts BOTH - predict the
splice line count AFTER
appending the final blank.
2. audit_eval matches
blocks by SUBSTRING: a named
run R299 would catch both
blocks and the engine block
reads UNVERIFIED -> RED.
Name the evaluable seam
RNNNa and the engine block
RNNN (the R233a/R233
precedent, now confirmed for
a wiring round).
3. The grant records the
CLASS CANON kit, not the
current gear: the save-load
rebuild must never bless a
claimed weapon (a thief with
a magic bow still records
the kit sling).
4. The recordings are NOT
saved: the load rebuild
re-reads the kit (the R33
v1 precedent). New save
tags stay unnecessary.
5. weaponprof.h cannot
include subclassgates.h
(include order: actor.cpp
includes weaponprof.h
alone), so the seam maps
the subclass base INLINE -
a duplication; the R299a
audit pins the agreement
with subclassRuntimeBase.
6. LIVE behavior change: a
held weapon outside the
recorded list now pays the
class penalty for party
members (a fighter with a
claimed battle axe pays
-2). Intended R297 seam
work; empty list keeps the
never-pays convention
(loaded v1 saves, the
henchman).
7. Gap-report checks can
hit line-wrapped text: the
assert Manual of the Planes
failed because the content
wraps mid-phrase. Assert a
fragment on ONE line
(Planes (the user
decision)).

Scope pass three: HENCHMEN
and SILENT MOVEMENT recorded
clean (R45 convention, R298
column); the planes deferral
(Manual of the Planes
source) written into the
Appendix IV entry; ONE new
open item - the equipment
cost columns (items costGp
is dead data; no shop
charges it) - the R300
candidate.

Next: R300 the equipment
cost columns (data-only, the
R190 precedent), then the
thief rolls wiring (the
thfChanceTenths seam), or a
fresh gap pass.

R300 landed. The equipment
cost columns pinned and the
engine costs repinned.
Commit 2e422c0 (pushed
e34da70..2e422c0), 5 files,
1094 insertions, 27
deletions - the shape
predicted exactly. Paste
streak 28 (md5
f713d75b8a1759d7b76a55cad654
9476 - no drift this time).
Two-pass applied 4 /
already 4. REAL GATE
rules/equipcosts.h
7acaec9b185317fa85fec9d67ff8
6719 = prediction; all five
touched md5s matched
(items.cpp 6f4bf1f5,
regtest.cpp 089c9a33,
phb_gap_report.md 62d7b706,
r300_splice.py f713d75b).

Battery: preflight GREEN,
census 217 -> 219, both new
audits bad 0 AT BATTERY
(the R300 engine audit ran
live). audit_eval R300a
verified bad 0 (175
asserts); sweep 92 -> 93
verified.

R300 content: the R299 open
item CLOSED - the phb
ledger holds ZERO open
items again.
rules/equipcosts.h CREATED:
52 arms rows + 14 armor
rows, the gold/silver
columns (exactly one unit
nonzero per arms row), the
name arrays, eqcSilverPerGold
20 s.p. = 1 g.p. The
equipment-section copy
resolves the empty
reference-sheet glaive
cell (6 g.p.) and confirms
left rows 1-28 / right
rows 1-24. items.cpp
costGp REPINNED - 9
repins: hand axe 1,
battle axe 5, flail 3,
morning star 5, spear 1,
short bow 15, long bow 60,
light crossbow 12, scale
mail 45; the
printed-table-wins debt
paid. JUDGMENTs: the
generic mace and flail
read the printed footman
rows; quarterstaff and
club 0 ENGINE CONVENTION;
the sling keeps 2 g.p.
(the print prices the
dozen-bullet bundle,
15 s.p.); the shield
file-static 10 g.p. =
the print Shield small row
(no accessor - recorded,
not audited); banded
prints Bonded in one copy
(the standard banded
mail, 90 g.p.).

Post-landing: fetched main
at 2e422c0, all five md5s
byte-exact, R300a GREEN,
sweep 93, census 219, ZERO
open items. Derived check
rebuilt fresh and GREEN:
both upload copies decoded
(the ref sheet 28 left +
24 right rows per line;
the section interleave 52
prices walked against the
ref truth with fragment
chains), header + audit
arrays == truth,
kRow[15]/kArow[10] OK,
engine rows OK, canvas
body + NL == the landed
splice. RED x2 confirmed:
equipcosts.h banded 90 to
91 and items.cpp scale 45
to 50 both fire.

LESSONS R300:
1. The pre-delivery bugs
were all caught by the
splice asserts: the
accessor count, the costGp
comment count, and marker
strings that must exist in
the NEW text - the R178c
rule again: assert
markers against the
created content, not the
patch intent.
2. Four items.cpp anchor
lines had wrong
whitespace (3-space vs
4-space indent) - anchor
lines must be extracted
byte-exact from the file,
never retyped.

Next: the thief rolls
wiring (the thfChanceTenths
seam has no callers - the
standing successor), or a
fresh gap pass (the scope
holds the Unearthed Arcana
and Dragon Magazine
rounds).

R301 landed 2026-10-10: commit
346964b, census 221, GREEN on
the first Termux preflight (no
b-round). The thief trap rolls
wired - the R298 seam gains
its first callers and the R45
springTrap its first caller
ever (the dungeon traps never
sprang).

7 patches: (a) thieffunc.h -
thfPercentileSucceeds (the
printed equal-or-less
convention on the 0-999
tenths band; a whole-percent
chance owns its exact
thousandth slice, the 99.1
climb walls decimal reads
true) + thfAttemptSucceeds
(the fold over
thfChanceTenths); (b)
state_dungeon.cpp - the flat
1-in-3 disarm retired: the
printed find roll then the
remove roll (two percentile
draws, one try each; the
too-late line when located
but not removed) + the new
checkTrapOnEntry (the
movement wire); (c)
appstate.h; (d) adnd1.cpp
(the shell step wire); (e)
regtest.cpp - the R301a seam
audit (evaluable, 8 asserts)
+ the R301 engine audit
(every springTrap branch on
seeded sequences); (f)
preflight.sh - the battery
build now LINKS the game
state TUs + MonsterXp.cpp
(the engine audit calls
live AppState methods); the
syntax gate shrinks to the
complement; (g) the gap
report wiring-arc box, ZERO
open items.

Ritual note: gate on R301a
ONLY - audit_eval named runs
match by SUBSTRING, a bare
R301 run would also catch
the engine block and end
UNVERIFIED (RED). The paste
md5 4e6dc357b601e02673b0530
87c49e70 matched exactly (no
created file this round; the
advisory was the only md5
gate).

Post-landing: fetched main
at 346964b, all 8 md5s
byte-exact (7 patched files
+ the splice), R301a GREEN,
sweep 94, census 221.

LESSONS R301:
1. Content self-checks must
exempt bytes the anchors
themselves carry: the R125
book-name comment in
state_dungeon.cpp embeds an
apostrophe and the regtest
printf lines embed a
backslash - clean() gained
allow_apos and the R300
printf BS-count per-line
check is the pattern (BS
only on printf lines, one
per line).
2. Idempotency markers are
case-sensitive against the
NEW text: the first draft
checked lowercase "the
thief trap rolls wired"
against a capital-The box
head - a re-run would have
re-applied and crashed.
3. Engine scenarios MUST set
party.formed - alive() reads
it and reports a spurious
GAME OVER.
4. audit_eval reads no
underlying-type enums
(enum CharRace : int) -
evaluable audits use plain
int race codes with
comments.
5. No compiler in the
sandbox: the engine audit
expectations were verified
by a seed-for-seed Python
replica of the new
springTrap (33 checks, draws
below(1000)/below(20)/
below(6) replicated) BEFORE
the splice was written; the
Termux preflight was the
first real compile - GREEN
first try.
6. The landed splice ends
with TWO trailing newlines
(canvas body + the paste
newline) - R298/R299/R300
all show this shape; the
canvas body + NL == splice
bytes check is the delivery
gate.

Next: the remaining thief
functions stay data (no
engine site rolls pick
pockets, open locks, move
silently, hide in shadows,
hear noise, climb walls,
read languages - a town shop
or stealth round would wire
them), or a fresh gap pass
(the scope holds the
Unearthed Arcana and Dragon
Magazine rounds).
R302 landed 2026-10-10: commit
14eb8e3 (push 346964b..14eb8e3),
census 223, GREEN on the first
Termux preflight (no b-round).
The thief silence wired - the move
silently column gains its first
engine site and the surprise roll
its first adjustments ever (both
DEX adjustments were hardcoded 0
since R7).

6 patches: (a) thieffunc.h -
thfSilenceSurpriseAdj (one roll
step of the DMG p.62 2d6 ladder -
JUDGMENT: the SILENT MOVEMENT
print gives no ladder modifier;
the PHB d6 form doubles surprise
faces, one 2d6 band = the step) +
thfNoteSilenceEachMove (the
printed note; the site rolls it
ONCE per encounter - the movement
granularity simplification); (b)
actor.h - Actor.pcRace (the PC
CharRace for the percentile;
Actor.race stays dm::NpcRace) +
Encounter.rollSurpriseWired; (c)
actor.cpp - the party side reads
the best living member
dexReactionAdj (the DMG p.62
most-favorable-member reading;
the DEX surprise note is
individual-only and the engine
keeps no per-member clocks), the
first living thief rolls ONE
percentile (success -> the
monster side takes the -2 step);
stepRound wired, log lines and
the R232 backstab gate unchanged;
(d) party.h toActor copies
pcRace; (e) regtest.cpp - the
R302a seam audit (7 asserts,
evaluable) + the R302 engine
audit (8 seeded scenarios); (f)
the phb gap box (the R298 box
head amended; the elven/halfling
racial surprise prose stays
data; ZERO open items).

Ritual note: gate audit_eval on
R302a ONLY (a bare R302 matches
the engine block too and ends
UNVERIFIED). The paste md5
2403954e9185ad55b7b6d436828d3b1
0 matched exactly. No preflight
patch this round (ai/actor.cpp
already in the battery build).

Post-landing: fetched main at
14eb8e3, all 7 md5s byte-exact,
R302a GREEN, sweep 95, census
223, splice 0/6 on the landed
tree.

LESSONS R302:
1. The census assert caught the
regtest replacement DROPPING the
R301 printf tail (the anchor
included it, the new text did
not reproduce it): RT_NEW must
carry the whole anchor prefix,
not just the inserted blocks.
2. Grep-count pre-asserts must
count WRAPPED instances: the
R300 gap box wraps holds ZERO
open items across a line break,
so the pristine file carries
ONE, not two - the count read
1 + the new box = 2.
3. Engine-audit seeds were
CHOSEN to discriminate: every
scenario seed was checked in
the replica against its wrong
counterfactuals (a wrongly-drawn
percentile shifts the 2d6 pair;
a wrongly-fed dead-thief DEX
shifts pAdj; an unsigned misread
of a negative chance flips the
band) before the C++ was
written - the exact asserts all
bite. First-attempt preflight
GREEN on a round whose engine
audit constructs Encounter
objects (the first regtest use
of ai::Encounter).

Next: the remaining thief
functions stay data (pick
pockets, open locks, hide in
shadows, hear noise, climb
walls, read languages - a town
shop or portal round would wire
them), or a fresh gap pass (the
scope holds the Unearthed
Arcana and Dragon Magazine
rounds).

R303 landed 2026-10-10: commit
7ca3a5f (push 14eb8e3..7ca3a5f),
census 225, GREEN on the first
Termux preflight (no b-round).
The thief pockets wired - the
pick pockets column gains its
first engine site, the city
street command [P] (MODE_CITY).

6 patches: (a) thieffunc.h -
thfPocketsChanceTenths (the
printed base folded with the
printed victim cut, 5 percent
per level above the 3rd - the
cut may cross zero) +
thfPocketsVictimNotices (the
printed 21 percent notice
band); (b) appstate.h - the
cityPickPockets declaration;
(c) state_sea.cpp - the roll:
the FIRST living thief draws
the passerby trade (d4) and
level (d6), then one printed
percentile. JUDGMENTS (the
print leaves them open): the
purse reads the R190 starting
money dice of the trade (the
startmoney pin gains its first
engine caller; the printed
random item has no stranger
inventory), and a noticed
attempt costs a watch fine of
a tenth of the company purse
(the R133 greed convention);
enterCity keys [P]; (d)
adnd1.cpp - the switch case,
the comment and the screen
line; (e) regtest.cpp - the
R303a seam audit (6 asserts,
evaluable; the printed worked
example walks live: 1200 cut
to 750, noticed from 960) and
the R303 engine audit (6
seeded scenarios: no living
thief, the mode gate, the
fighter purse 140 success, the
quiet fail AT the roll==chance
boundary seed 19, the noticed
fail seed 127 - the vlevel 6
cut fires, the no-cut read is
the quiet band - and the
dead-thief skip, Sly lifts 60
not Rook); audit_eval named
run R303a ONLY (a bare R303
matches the engine block too
and ends UNVERIFIED); (f) the
gap report box - the remaining
functions stay data (open
locks, hide in shadows, hear
noise, climb walls, read
languages; hear noise keeps
the R120 portal listen
convention). The paste md5
6060b33cd0de7971a895a4132851
ae60 matched exactly. No
preflight patch this round
(state_sea.cpp already in the
battery build).

Post-landing: fetched main at
7ca3a5f, all 7 md5s byte-exact,
R303a GREEN, sweep 96, census
225, splice 0/6 on the landed
tree.

LESSONS R303:
1. The post-landing md5 check
caught MY OWN expectation
typo, not a repo problem: the
appstate.h md5 was hand-copied
into the chat prose as
c720...00df where the true
value reads c720...02df, and
the landed tree was byte-exact
all along (proven by diffing
against a fresh R302 tree
re-spliced with the landed
splice - IDENTICAL). LESSON:
never hand-copy md5s into
prose; write the expect file
from the recorded output, and
on a FAILED, re-derive the
expected bytes before
suspecting the landed repo.
2. The adnd1.cpp case labels
were the first NEW-content
apostrophes since R182 - built
via Q = chr(39) with allow_apos
(the R301 anchor precedent
generalizes to content); and a
global count assert cannot gate
case labels (five other mode
switches already own the
case P label) - assert the
three-line call sequence
instead.
3. Engine-audit seeds were
CHOSEN to discriminate: seed
19 sits exactly AT the strict
less-than boundary (roll 150
vs chance 150), seed 127 reads
noticed only WITH the vlevel 6
cut (the no-cut counterfactual
lands in the quiet band), and
the purse seeds were screened
so every wrong-trade dice
hypothesis differs from the
expectation. First attempt
GREEN preflight on a round with
shell-file edits (adnd1.cpp,
the R99/R107 syntax-gate
complement).

Next: the remaining thief
functions stay data (open
locks - a town shop round
would carry lock data first;
hide in shadows, climb walls,
read languages - no engine
site yet), or a fresh gap pass
(the scope holds the Unearthed
Arcana and Dragon Magazine
rounds).

R304 user correction (repeat
offense, DO NOT DO AGAIN): the
R304 delivery ritual block
AGAIN included a nano line
(paste the code into nano) - the
SECOND time after the R122-era
lesson (lines 927-928: the
paste/nano step is NEVER part of
the ritual). The ritual block
starts at the md5sum line: the
user pastes the splice on their
own, however they choose. LESSON:
before emitting ANY delivery
ritual, scan it for the nano/edit/
paste verb - none of them belong;
the first command is the advisory
md5sum, then py_compile, splice
twice, audit_eval RNNNa,
preflight, commit/push.

Next: R304 landed? then the
post-landing verify (expect file
from the acid-run md5 record,
NEVER hand-copied) and this
append. Otherwise the same
delivery with the corrected
ritual.

R304 ritual FORMAT correction
(the user showed the canonical
shape, the R303 block): plain
commands, NO ~/Adnd1 $ prompt
prefixes, and the paste step is
ONE leading comment line
reading: # paste the canvas code
into tools/rNNN_splice.py, save
- never named as an editor, never
a command line. Then md5sum
(advisory + its value),
py_compile,
splice twice, audit_eval RNNNa,
preflight, commit/push - each
commented with its expected
output.

R304 landed 2026-10-10: commit
2b8f764 (push 7ca3a5f..2b8f764),
census 227, GREEN on the first
Termux preflight (second round
running). Landed tarball md5
2fc7f307c9aef264d91941477e782698.

The locked door wired - the
open locks column gains its
first engine site, the dungeon
door (MODE_EXPLORE movement).

8 patches: (a) rules/locktime.h
CREATED - the DMG THIEF
ABILITIES time pins (the pick
takes 1-10 rounds on the
complexity, most locks 1-4;
the traps roll rides the locks
time) plus the FIRST DUNGEON
ADVENTURE doors prose (wooden
doors always metal bound,
metal doors usually locked) and
the per-delve count judgment
(one door; the print carries
no count); (b) appstate.h - the
LockedDoor struct (x, y,
opened, tryLevel), the
lockedDoors member and the
placeLockedDoors /
lockedDoorAt / bumpLockedDoor
declarations; (c)
state_dungeon.cpp - the site:
placeLockedDoors (the R45 scan
pattern - a TILE_WALL slot with
open tiles on BOTH sides of one
axis, FLOOR or CORR counting as
open; the tile flips to
TILE_DOOR at placement), and
bumpLockedDoor: the bump spends
the turn (the searchExplore
convention, tickActivity 1),
the FIRST living thief draws
the time (min + below(max-min+1))
then ONE printed percentile
(thfAttemptSucceeds,
THF_OPEN_LOCKS), one try per
lock (tryLevel gates the
retry: same level reads the
refuse line with NO time or
percentile draw), the wander
check rides every branch end;
(d) state_core.cpp - the
newDungeN call after
placeSecretDoors; (e) adnd1.cpp
- the movement gate before the
walkable check (lockedDoorAt
non-null -> bump and return;
the tile is a visible TILE_DOOR
the company sees but cannot
pass until picked); (f)
regtest.cpp - the R304a seam
audit (8 asserts, evaluable:
the time pins, the band fold
max-min+1==10, and four
open-locks percentile
boundaries - lvl1 human dex9
150, lvl10 halfling dex13 720,
lvl12 dwarf dex18 1020 every
draw, lvl1 elf dex18 350) and
the R304 engine audit (5 seeded
scenarios, replica-walked:
placement seed 1 door at x33
y10, the one-sided-floor map
places nothing, the no-thief
bump seed 1 spends the turn but
no try, the dead-thief skip +
level 17 pick seed 1 (6
rounds, opens), and the
one-try ladder seed 23 - the
roll 167 fails only WITH the
dex 9 fold, the same-level bump
reads the refuse line, the
level 2 bump retries and the
roll 299 resists again);
audit_eval named run R304a ONLY;
(g) phb_gap_report.md - the
wiring-arc box + the R298 head
amend (the remaining functions
stay data: hide in shadows,
climb walls, read languages;
hear noise keeps the R120
convention); (h)
dmg_gap_report.md - the
chronicle paragraph (the DMG
pins recorded; the legend
stays the only checkbox). The
paste md5
0318ecccd0570181d1f2058096c70
daf matched exactly. Census
225 -> 227 (the R304a + R304
printf lines).

Post-landing: the work dir was
wiped at turn start (the expect
file went with it), so the
byte-exactness was re-proven
the R303 way: fetch the
pre-R304 tree at 7ca3a5f, apply
the landed splice, diff -r
against the fresh landed tree -
IDENTICAL; all 9 md5s match the
acid-run record, R304a GREEN,
sweep 97, census 227, splice
0/8 on the landed tree.

LESSONS R304:
1. The ritual format bit TWICE
in one delivery - first a nano
line again (the R122-era
lesson, lines 927-928), then
prompt prefixes and a missing
paste comment. The canonical
block (the user showed it):
plain commands, NO ~/Adnd1 $
prefixes, and ONE leading
comment line reading "# paste
the canvas code into
tools/rNNN_splice.py, save",
then md5sum, py_compile, splice
twice, audit_eval RNNNa,
preflight, commit/push - each
commented with its expected
output. Emit exactly that
shape; scan any ritual for
nano/edit/paste verbs before
sending.
2. The replica drew the exact
placement coordinate from the
R45 scan idiom copied first
(x below 62, then y below 62),
and the engine audit pinned it
(x 33 y 10) - copying the draw
order from the existing
function BEFORE writing the
replica kept the seeded
expectations true first try.
3. tickActivity draws NOTHING
(checked before modeling the
bump draws - a draw inside it
would have shifted every
replica expectation); the
wander d12 rides EVERY branch
end of bumpLockedDoor, so the
replica consumes it on all
paths and the seeds were
screened for d12 above 1.

Next: the thief function arc
is down to three data columns
(hide in shadows, climb walls,
read languages - no engine
sites yet; hear noise keeps the
R120 convention), or a fresh
gap pass (the scope holds the
Unearthed Arcana and Dragon
Magazine rounds), or a new
engine seam of the user
choosing.

R305 the locked door forced:
the DMG FIRST DUNGEON
ADVENTURE doors prose pinned
(rules/doorforce.h, the
grenade.h pattern): the
typical 1-2 d6 band, the
very-heavy halves, the
simultaneous-1s rule
(JUDGMENT: the print reads
two or even three - the
band pins at two), the
width caps (three at a
standard door, one at a
narrow), the wood-break
turn with its three noise
checks and the knock-only
metal door (the band, the
halves and the break lane
stay data - no site). The
site: [O] in the dungeon
spends the turn and up to
three living members roll
the d6 against the R153
parentheticals (the wrench
once ever per door, the
LockedDoor exTried flag)
or two simultaneous 1s tear
the lock out; the wander
check rides every path.
adnd1.cpp keys [O] (town
keeps [O] for overland - a
different switch). The
R305a seam audit walks the
nine pins and their folds
and the R305 engine audit
walks the parentheticals
plus seven seeded
scenarios (replica-walked:
no-door seed 1, diagonal
seed 1, dead-skip plus
simultaneous seed 77,
retry seed 63, width-cap
seed 17 - the
counterfactual fourth
roll reads 1, wrench seed
1, once-ever seed 2). The
paste md5
911285c1197e9c49ff621262b
0d92882 matched exactly.
Census 227 -> 229 (the
R305a + R305 printf
lines).

Landed and verified: the
fresh landed tree at
02a4df7 (push 2b8f764 ->
02a4df7) matches the
pre-R305 tree at 2b8f764
plus the landed splice
byte for byte (diff -r,
the R303 way - the work
dir was wiped at turn
start); all eight md5s
match the acid-run record,
R305a GREEN, sweep 98,
census 229, splice 0/7 on
the landed tree.

LESSONS R305:
1. The replica print lines
carried index bugs (the
search returns a seed plus
result pair - the S1 and
S4 prints read r[2], and
the S6 predicate crashed
on seeds where the first
call opened the door and
the second call had no
roll); total predicates
and guarded prints kept
the seed screen honest and
all seven seeds matched
the design record.
2. Post-asserts must count
what the comments also
say: the function header
names doorWidthStandard
Attempts and doorLocked
SimultaneousOnes, so the
helper counts land at two,
not one; and gap-report
phrases the asserts count
(WIRED R305, holds ZERO
open items) must stay on
one line - a wrap splits
the phrase and the count
silently misses.
3. The ritual format landed
clean on the first send
(the R304 lesson held:
plain commands, the one
paste comment line, no
editor verbs).

Next: the thief function
arc is down to three data
columns (hide in shadows,
climb walls, read
languages - no engine
sites yet; hear noise
keeps the R120 convention)
with the STR parenthetical
site now spent, or a fresh
gap pass (the scope holds
the Unearthed Arcana and
Dragon Magazine rounds),
or a new engine seam of
the user choosing.

R306 landed: the thief
functions wired (commit
0c74c5b, push 02a4df7..
0c74c5b, preflight GREEN,
census 231, sweep 99).
The last three take-table
columns gained sites: [I]
hide (the flag absorbs one
wanderer at the spawn
gate), the pit trap haul
(climb walls; a miss still
hauls but costs the turn)
and the lair script (read
languages, one try per
delve, a 2d6 cache x
level). Ten patches, no
new files; R306a GREEN (9
asserts); the first R306
gate sits in
state_combat.cpp (the
spawn head line runs 81
cols - cleaned at 90, the
R300 convention). All 11
md5s verified post-
landing (thieffunc.h
a717a947, appendixgh.h
76563f79, appstate.h
f3ad3b52, state_dungeon
8e7c64f2, state_core
ce28be98, state_combat
4b97ba42, adnd1.cpp
e9244445, regtest.cpp
55077302, phb f015b89d,
dmg 1647e9b4, splice
49845327); pre + landed
splice == landed tree,
byte identical.

Next: the thief arc is
CLOSED (all eight columns
wired or conventioned; the
phb ledger holds ZERO open
items) - a fresh gap pass
(the scope holds the
Unearthed Arcana and
Dragon Magazine rounds), or
a new engine seam of the
user choosing.

R307 LANDED (the fresh gap
pass, a report round; commit
27dc00c, pushed). The
upload section lists diffed
against both ledgers, the
R296 convention. Opened 3:
the DMG hirelings cost
tables (upload lines 1817
and 1873 - the R121 officers
slice and the R212 spell
prices never carried them),
the DMG sage subsection
(line 2110, the fields and
knowledge chances) and the
PHB general equipment cost
lists (lines 2344-2430,
Clothing Herbs Livestock
Provisions Transport - R300
pinned only arms and
armor). Bookkeeping repair:
the patrols fortresses and
castle tables turn out
pinned since R67
(dm/encounters.cpp, wired
R68) - the report never
carried the receipt.
Recorded OUT: the helmet
head-AC rule, peasants
serfs and slaves, the
Appendix C appearance
family, glossary and
afterword, the PHB vision
appendix, the PHB
end-of-book DM advice
sections. No engine code;
census stays 231. Five
patches, both ledgers; the
R305 lesson bit twice
(assert phrases must sit on
one line - OPENED R307 and
the census phrase wrapped
pre-splice; fixed in the
canvas, not landed). Splice
b00eabef, phb 851fb2e9,
dmg a851501c - all three
verified post-landing; pre
+ landed splice == landed
tree, byte identical.

Next: the ledgers hold 3
open items (hirelings,
sage, the PHB equipment
lists) - pin rounds, or a
new engine seam of the
user choosing.

R308 LANDED (the general
equipment cost lists pin, the
R307 PHB open item paid; commit
9a6861d, push 27dc00c..9a6861d,
preflight GREEN on the first
run, census 232). The
equipcosts.h general section:
99 rows across the EIGHT
printed lists (clothing 11,
herbs 3, livestock 21, misc 29,
provisions 10, religious 6,
tack 9, transport 10), each a
name plus THREE coin columns
(11 copper, 29 silver, 59 gold -
exactly one nonzero per row;
the reference sheet resolves
the scrambled herbs cells and
the eight transport cells the
equipment copy drops), the
list-count and first-row
helpers, and the copper
monetary pins (10 cp = 1 sp,
200 cp = 1 gp, joining the R300
silver pin). No engine site
charges them yet (the town
stores price canonically); the
R308 battery audit walks every
cell, the boundaries, the
clamps, the herbs cells, worked
rows and the monetary pins;
the phb box flips to PINNED -
the ledger holds ZERO open
items again. LESSONS: (1) the
R300 pairwise coin identity
((gold==0)==(silver==0)) reads
FALSE on copper rows once a
THIRD coin column exists (gold
and silver both sit at zero) -
audit_eval caught it
pre-delivery (bad 40, the exact
gold-zero row count); with
three columns the identity
walk must COUNT nonzeros
((g>0)+(s>0)+(c>0)!=1).
(2) The delivered ritual AGAIN
opened with the nano paste
line (the R196c gates-only
carve, repeat bite) - the user
corrected it; the ritual
starts at the md5 gate,
ALWAYS. Verified post-landing:
splice 5a7e9b85 matched the
paste exactly, equipcosts
0df9fb34 (the REAL GATE),
regtest 225aa161, phb 68c00278
- the pre-tree plus the landed
splice == the landed tree,
byte identical. Mutation test:
galley large 25000 -> 25001,
bad 2 RED, restored GREEN;
audit_eval 409 asserts GREEN.

Next: the two DMG opens from
R307 (the hirelings cost
tables, the sage subsection) -
pin rounds, or a new engine
seam of the user choosing.

R309 LANDED (the hirelings
cost tables pin, the first of
the two R307 DMG open items
paid; commit ab67ab0, push
9a6861d..ab67ab0, preflight
GREEN on the first run, census
233). rules/hirelings.h CREATED
(the R300 pattern): the STANDARD
HIRELINGS TABLE OF DAILY AND
MONTHLY COSTS - 10 rows, daily
in silver pieces, monthly in
the printed coin (exactly one
monthly column nonzero; the
craft percent flags on
carpenter, leather worker,
tailor) - and the EXPERT
HIRELINGS TABLE OF MONTHLY
COSTS IN GOLD PIECES - 33 rows
(the 19-row mercenary soldier
block at rows 7-25; the eight
negotiated rows pinned -1:
captain, lieutenant, serjeant,
sage, ship crew, ship master,
spy, steward/castellan; the
asterisk rows are exactly the
four 100 g.p. rows - armorer,
engineer-architect,
jeweler-gemcutter, weapon
maker). The standard employment
bands ride (1 in 6 long-term,
3 in 6 with a double or treble
daily-wage bonus; a single
daily wage is too small). The
description prose (armorer
skill bands and manufacture
times, blacksmith output,
jeweler bands, race
multipliers) rides as recorded
notes. GROUND TRUTH: the
compilation (sh.htm/eh.htm)
agrees on every cell but adds
two OSRIC-sourced rows (cook,
groom) - excluded per the R211
rule. The ritual format held
first-try (gates only, no
nano). Verified post-landing:
splice d5dd94a4 matched the
paste exactly, hirelings.h
a905d9b9 (the REAL GATE),
regtest 00d3d57c, dmg report
a3f33d3d - the pre-tree plus
the landed splice == the
landed tree, byte identical.
Mutation test: alchemist 300
-> 301, RED, restored GREEN;
audit_eval 222 asserts GREEN
on the first run. LESSON: the
splice-side post-asserts
counted function names wrong
twice before the acid run
(the char* name accessors are
not inline int; a cross-call
counts as an extra
occurrence) - build
post-assert counts FROM the
generated text, not from the
design sketch.

Next: the LAST open item is
the DMG sage subsection
(upload line 2110, the fields
of study and the exact versus
learned question chances) -
the pin round, or a new engine
seam of the user choosing.

R310 LANDED (the sage
subsection pin, the LAST R307
open item paid - the dmg gap
report holds ZERO open items;
commit 58b07c3, push
ab67ab0..58b07c3, preflight
GREEN on the first run, census
234). rules/sage.h CREATED
(the grenade.h pattern, 61
accessors: 58 inline int + 3
char* name arrays,
DATA-DRIVEN): the
fields-count table (6 dice
bands tiling 1-100; minor
1,1,1,2,2,2 / special
2,3,4,2,3,4); the SAGE FIELDS
OF STUDY - 7 percent bands
carrying 68 special knowledge
categories (Humankind 12,
Demi-Humankind 11, Humanoids
and Giantkind 8, Physical
Universe(s) 10, Fauna 10,
Flora 8, Supernatural and
Unusual 9); the CHANCE OF
KNOWING table (4 scopes x 3
natures, the out-of-fields
exacting none cell pinned -1
the print dash, the scrambled
major row 61-80/57-60/26-35
recovered); the sage
characteristics (STR d8+7,
INT d4+14, WIS d6+12, DEX 3d6,
CON 2d6+3, CHA 2d6+2, nine
alignment bands, 8d4 hp, spell
kinds 0000112, max level d4+2
the 3-6 band, 1-4 spells per
level 1 ready); the offer
table (200-1200 twice, 20000
the material minimum - the
200 to 1,200 g.p. orphans were
the offer table, 2d6 hundred
g.p. salary and grants);
efficiency (20000/50, 60000/90,
100000/100; steps 1000 and
4000 per +1 percent);
improvement ladder (5000/1/5,
10000/1/5, 100000/24/3,
200000/24/-1); the information
discovery time and cost table
(units rounds/hours/days, the
lone HOURS cell the
special-category specific
1-10, cost per day
100/1000/500/200, free spread
20/20/20/80, unknown 51-100
percent at half cost,
short-term 100 g.p. per day 7
days max 1-month cooldown,
permanent offers lifetime
only). GROUND TRUTH: the
upload print + the
1eonline.info compilation
(sage.htm) + a third
transcription agree on every
cell; the OCR seven-column
interleave resolved (HISTORY
HISTORY reads History, HISTORY
CHEMISTRY restores Chemistry
to the physical universes,
INSECTS TREES restores Trees
to flora). The hiring and
location and spell prose rides
as recorded notes; no engine
site charges them yet (no sage
consultation layer exists).
Verified post-landing: splice
8e30f952 matched the paste
exactly, sage.h bbdd1cb4 (THE
REAL GATE), regtest 5a68b446,
dmg report 91988d46; the
remote commit 58b07c3
confirmed via the GitHub
connector (4 files,
+2836/-11). Acid: idempotent
twice, two virgin extracts
byte-identical, audit_eval 241
asserts GREEN, mutation RED
on both probes (know-hi 96-97
bad 4; eff pct 50-51 bad 2)
restored GREEN. LESSON: the
eval caught two real author
errors pre-delivery (the
accessor count 59 vs 58 - the
name accessors are not inline
int; the DEX probe needed
DiceCount(3) with Dice(2) !=
6 added) - build the audit
walk and its counts from the
generated text, never from the
design sketch (the R309 rule,
held). DELIVERY LESSON: an
oversized single-call canvas
write can be reverted by a
persisted-folder guard once
auto tool-result caches
accumulate - seed the canvas
with a small frontmatter-only
write, grow it with edit calls
appending ~2-3KB chunks behind
a unique marker line, keep the
tool-results cache cleaned
between writes, and byte-verify
the finished canvas (cmp/md5)
against the acid-tested target
before delivery.

Next: the DMG arc is COMPLETE
(the dmg gap report holds ZERO
open items; the battery census
stands at 234). The next round
is the user choosing: a new
engine seam, or the standing
scope - a new sourcebook gets
its own gap report against the
same engine conventions.

R311 landed 2026-10-10: commit
04454c9 (push 58b07c3..
04454c9), census 235, GREEN on
the first Termux preflight. The
underwater environment pinned -
the FIRST round past the closed
dmg ledger (the user chose the
new seam from the options
comparison). rules/
underwater.h CREATED (the
grenade.h pattern, 49 pure
inline int accessors, all in the
evaluable subset, no structs):
the surface SWIMMING paragraph
(metal armor impossible except
magic armor - the dog paddle
only; leather and padded at 5
percent drown per hour, +2 per
5 pounds of possessions beyond
the armor, negatives clamped;
winds above 35 mph at 75
percent), the underwater
MOVEMENT (swim impossible in
armor heavier than leather or
above 20 pounds of equipment -
the cap moves 1 pound per 100
g.p. of strength adjustment,
CALLER-FED: no engine STR
weight-allowance accessor
exists; dungeon speeds and
encumbrance ratios; free action
at 3x dungeon rate; the
vertical at the same rate), the
underwater VISION (50 feet
fresh, 100 salt, the depth
limit the distance limit; the
optional decay 10 feet per 10
feet to 0 at 60 fresh and 110
salt, clamped both ends; the
light spell 30 feet or +10
under 60, whichever greater;
the helm quintuples distance
AND depth; infravision as
dungeons; ultravision halved at
100, zero below 200; seaweed
and grass to 10 feet or nil,
the shoals total, the mud
d6+6 rounds), and the underwater
COMBAT (thrusting only; aquatic
first strike; free action any
weapon with no penalty; nets 1
foot per strength point, the
races 15, sahuagin 20,
untrained -4; missiles out
except the special crossbow at
10x price and half range). The
underwater spell lists ride R168
(rules/uwspells.h) - NOT
re-pinned; the breathing aids,
the dagger-between-teeth and
the keep-dry prose ride as
recorded notes. 4 patches: the
header CREATED, the include,
the R311 battery audit (68
asserts: the constants plus
five walks - drown, cap, decay,
light, ultravision - and the
print identities), the chronicle
paragraph (NO box flip - the
dmg ledger stays at ZERO open;
the only checkbox left is the
legend). Verified post-landing:
splice 13a55fe advisory (the
paste drifted to 2a3b3a4f - the
R172 md5-note class, harmless),
underwater.h 4d9f861b (THE REAL
GATE, matched exactly), regtest
0f377ba7, dmg report fa5721cc;
the remote commit 04454c9
confirmed via the GitHub
connector (4 files, +1561:
underwater.h 375, splice 960,
regtest 185, dmg report 41).
Acid: idempotent twice, two
virgin extracts byte-identical,
audit_eval R311 verified bad 0
(68 asserts), mutation RED on
THREE probes (wind 35-36 bad 1;
salt decay 110-111 bad 11; the
AUDIT-SIDE kDrownPct 25-26 RED
- the audit is not tautological)
restored GREEN, census 235
exactly once, brace/paren
balance held on every touched
file. ACID LESSONS: (1) the
idempotence marker must be a
ZERO-PARAM accessor line - the
first choice uwVisionBaseFt()
takes a param, so the already
path never matched and run 2
died at patch-a counts;
(2) arrlines per must fit the
76-column budget - 11-value
arrays at 11 per line ran past
it, 6 per line fits; (3) do not
assert the round number absent
from regtest.cpp in patch c
when patch b already wrote it
into the include line. DELIVERY
NOTE: the canvas went up
byte-exact in ONE bash copy
this turn (no guard revert,
unlike R310) - the chunked-edit
fallback stays in the protocol
anyway; the canvas is at
r311-splice (md5 bb249b1a).
The advisory splice md5 is the
pre-nano paste; nano drifted it
by one byte class as usual -
the REAL GATE held.

Next: R311 founds the post-
ledger seam era - the underwater
pin is data with no engine site
yet (no state_underwater layer;
a future round would wire swim
caps, vision decay and
underwater combat into the
dungeon walker, and a strength
weight-allowance accessor would
un-caller-feed the cap). The
next round is user choice: wire
the underwater layer, or
another fresh seam / sourcebook
gap report per the standing
scope.
R312 + R312b landed 2026-10-10:
commit 8661437, census 237, GREEN
after one b-round fix (both
splices in ONE commit, the
R179/R180b pattern). THE
FLOODED CROSSING - the first
ENGINE SITE the R311 underwater
pins charge (the R304 locked-
door precedent scaled to the
surface SWIMMING paragraph):
rules/swimcross.h CREATED (the
grenade.h evaluable subset, 8
accessors): swimArmorSwims (ids
0/1/2 swim, 3+ bar - studded
leather reads METAL, the studs;
the JUDGMENT: the engine
ARMOR_LEATHER weight class is
the class-restriction grain,
not the swim gate),
swimMagicArmorSwims (the dog
paddle), swimCanSwim (plus > 0
dog paddles, plain reads the
ban), swimLoadBeyondArmorLbs
(1 lb = 10 g.p., the worn
armor EXCLUDED, C truncation,
clamp), swimDrownRollPerCrossing
(the per-hour print percent
condensed to ONE roll per
living member per water entry -
JUDGMENT), floodPerDelveCount
(one per delve, the R304
convention), floodSideMin/Max
(2-3). ENGINE: world/map.h
TILE_WATER = 5, walkable;
newDungeon calls placeFlood
AFTER placeLockedDoors (draw
order preserved); placeFlood
draws a 2-3 x 2-3 tile ALL-
FLOOR sheet clear of
stairsX/stairsY and
dungeon.entryX/entryY (guard
500, draw order x,y,w,h
FIXED); enterWater gates on
the FIRST living member
failing swimCanSwim (bump
convention: ++turnCount,
tickActivity(1), the cannot-
swim log, wanderCheck ->
spawn, return false; success
logs the plunge, then each
living swimmer rolls
rng.below(100) against
uwSurfaceDrownPct(loadLbs)
- hp 0 and the goes-under
log; the step itself is the
normal pace cost); adnd1.cpp
gates dry-land -> water only
(water -> water steps free)
and paints the water brush
RGB(30,60,120). AUDITS:
R312a seam (audit_eval
verified bad 0, 16 asserts)
+ R312 engine (7 seeded
scenarios replica-walked in
Python first: placement seed
3 lands x 6 y 22 2x2 on the
first draw; the stairs-guard
2x2 pocket seed 4 places
nothing; the blocker seed 1
spends the bump with the
wander d12 reading 2; the
dog-paddle seed 60 rolls 7;
the drown boundary seeds 69
(roll 4 goes under) and 180
(roll 5 holds) pin the bare
leather load at 2 lbs = 5
percent; the dead plate
wearer seed 91 does not
block). Census 235 -> 237.
R312b LESSON (the third
include-chain bite, now a
RULE): preflight RED with
ONE compile error (the census
wall downstream - the R180b
pattern) - state_dungeon.cpp
called rules::uwSurfaceDrownPct
in enterWater but included
only swimcross.h; appstate.h
does NOT carry underwater.h
transitively. RULE: every
rules:: accessor a new TU
calls needs its header IN
that TU - grep the include
chain for each called
accessor, never assume
transitivity (the R179b/R180b
lesson generalized past enum
spelling). The underwater
MOVEMENT, VISION and COMBAT
paragraphs stay data (no
underwater combat layer, no
vision radius mechanic); the
chronicle paragraph landed
with the round (no box flip -
the dmg ledger holds zero
open). Canvases r312-splice
and r312b-splice; the real
gate held (swimcross.h md5
8b07825b), pastes drifted as
usual.

Next: the seam era continues
user-choice: a deeper
underwater layer (the vision
decay, the uw combat pins, a
breathing mechanic), or
another fresh seam /
sourcebook gap report per the
standing scope.
