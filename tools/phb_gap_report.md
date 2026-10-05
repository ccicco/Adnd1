# PHB Gap Report - the book vs the repo

R177 CREATION. THE SECOND BOOK, WHOLE. The DMG gap
report (tools/dmg_gap_report.md) covers the Dungeon
Masters Guide; this sibling report inventories the
Players Handbook (the Premium 1e OCR upload)
against the same engine, end to end. Engine scope:
four classes (fighter, magic-user, cleric, thief),
the six ability tables, the weapon, armor and
encumbrance layers, and the 54-spell registry.
Everything else the book carries is out of engine
scope, noted at the foot.

Conventions as the DMG report: [x] verified
against the book text (with the round); [~]
verified DIVERGENT - fix-round candidates, ranked;
[ ] open item (worth having); a round closes an
item by flipping the box in the SAME commit. Page
cites are the book own page numbers where earlier
rounds set them; otherwise sections are cited by
their printed table names.

FOUNDING READ FINDING: the five ability tables
other than STR are transcribed from project notes
and DIVERGE from the print - the same finding
class as the R162 XP rows (repinned R176). Five
divergences are verified below, and the prime
requisite ladder is an open verify item. A report
round adds no audit; the battery census stays 94
until the first PHB fix round lands.

R178c CLOSED divergences 1 and 2 (the live bugs
first, per the arc ordering rule): the DEX
reaction ladder and the CON columns repinned to
the print; the unsourced CON poison-save accessor
retired. Census 95. The WIS, INT and CHA
divergences (3, 4, 5) remain ranked fix rounds.

## Verified against the book

- [x] **STR Table II (p.9, ability adjustments)** -
      pinned R153: hit probability, damage, the
      weight allowance, open doors and bend bars or
      lift gates for the whole 3-18/00 run.
- [x] **Race Tables I-III (pp.15-18)** - pinned
      R154: class limitations, the footnoted level
      caps, ability minimums and maximums (male and
      female columns), infravision, the
      sleep-and-charm resistances, the CON
      magic-save bonus (the R147 shape).
- [x] **Racial preferences table (the CHARACTER
      RACES section)** - the acceptability matrix
      pinned R169.
- [x] **Class tables (pp.20-31)** - the level
      title ladders pinned R162 (the cleric level 5
      blank cell carries Curate down); the XP
      boundary columns pinned R176 (band lower
      bound - 1; the printed adders); hit dice and
      the HP_BEYOND_CAP convention print-verified in
      passing (R162).
- [x] **Followers by class (the class description
      sections)** - pinned R170.
- [x] **Weapon data (speed factors, the per-weapon
      charts)** - R158 (speed) and R144 (the to-hit
      adjustment rows, from the repo-trusted
      compilation); the book-verify pass is the
      open item below, now payable.
- [x] **Spells (the SPELL TABLES and the spell
      explanations, engine classes)** - the
      54-spell registry, the by-level slot tables
      and the L4-6 casting gates pinned
      R80/R130/R131; caster aging R129.
- [x] **Death and revival (the CON resurrection
      survival column in use)** - R82; the audit
      range check covers the printed 40-100 column,
      so the coming repin passes it unchanged.

## Verified DIVERGENT (fix-round candidates, ranked)

- [x] 1. **DEX Table I, reaction and attacking
      adjustment (the DEXTERITY TABLE I page)** -
      CLOSED R178c: the ladder repinned to the
      print (dex 3 -3, dex 4 -2, dex 18 +3; the
      defensive ladder re-noted, already the
      print). The live callers - missile attacks
      (ai/actor) and the surprise roll
      (rules/turn) - now read the printed cells;
      the R178c battery audit walks both ladders.
- [x] 2. **CON table, the system shock and
      resurrection survival columns (the
      CONSTITUTION TABLE page)** -
      CLOSED R178c: both columns repinned to the
      print cell by cell (shock 35 through 99;
      resurrection survival 40 through 100 - the
      LIVE raise-dead roll now reads the printed
      values); the CON 6 hit-point cell repinned
      -1; the unsourced poison-save accessor
      (conPoisonSaveAdj) RETIRED - not in the 1e
      print, and unused. The R178c battery audit
      walks all three repinned columns.
- [~] 3. **WIS Table I, magical attack adjustment
      (the WISDOM TABLE I page)** - the engine reads
      -2 through +2; the print reads 3 -3, 4 -2,
      5-7 -1, 8-14 none, 15 +1, 16 +2, 17 +3,
      18 +4. Currently unwired (the saves.h note
      points at it; the save rolls do not call it).
- [~] 4. **INT Table I, additional languages (the
      INTELLIGENCE TABLE I page)** - the engine
      ladder diverges at every score above 3; the
      print reads 3-7 none, 8-9 one, 10-11 two,
      12-13 three, 14-15 four, 16 five, 17 six,
      18 seven. Currently display-only.
- [~] 5. **CHA table (reaction adjustment, loyalty
      base, henchmen - the CHARISMA TABLE page)** -
      the engine reaction adjustment is a flat -4
      through +4 ladder against the printed percent
      ladder (-25 at 3 through +35 at 18); the
      loyalty base reads 1 through 15 against the
      printed -30 through +40 percent; the henchmen
      count diverges at cha 4 (engine 2, print 1)
      and cha 12 (engine 4, print 5). The reaction
      accessor is LIVE and feeds the d100 reaction
      bands (dm.cpp rollReaction) - the fix round
      must re-scale to the printed percents.

## Open items (worth having)

- [ ] **Prime requisite XP adjustment (the class
      sections)** - the engine ladder reads +10, +5,
      0, -10, -20 percent by prime requisite score;
      the print carries the +10 percent
      high-prime-requisite notes in the class
      sections. The remaining rungs are unsourced
      against the 1e print - verify, then repin or
      record as convention.
- [ ] **The PHB book-verify pass for the weapon
      tables** - R144/R158 pinned from the
      1eonline.info compilation; the PHB upload now
      supplies the print charts (WEIGHT AND DAMAGE
      BY WEAPON TYPE; WEAPON TYPES, GENERAL DATA AND
      TO HIT ADJUSTMENTS) - a verify round can close
      the standing compile-vs-print note.
- [ ] **Starting money by class (the EQUIPPING THE
      CHARACTER section)** - the print: cleric 3d6
      (30-180 gp), fighter 5d4 (50-200), magic-user
      2d4 (20-80), thief 2d6 (20-120). The engine
      party-creation convention is unverified
      against the print.
- [ ] **Armor Class table (the ARMOR section)** -
      the printed AC ratings (none 10 through plate
      and shield 2, magic pluses lowering AC)
      deserve a cell-by-cell verify against the
      items armor rows (R101 pinned the plate kit).
- [x] **Fighter attacks per melee round (the class
      tables section)** - PINNED R181: the engine
      convention verified and repinned - the printed
      bands now live in rules/attacksround.h and
      rules/turn.cpp (meleeAttacksPerRound was the
      unsourced level-8+ original note).
- [ ] **Wisdom Table II, cleric bonus spells and
      spell failure** - unwired; a wiring candidate
      if engine scope wants it.

## Out of engine scope (recorded, not defects)

- The subclasses (paladin, ranger, druid,
  illusionist, assassin, monk) and the multi-class
  and two-class rules - OPENED R178: the subclass
  arc (the scope decisions and round queue below).
- Alignment machinery (the ALIGNMENT section) -
  player-side.
- Language lists (the CHARACTER LANGUAGES section) -
  display only.
- The psionic sections.
- The druid and illusionist spell lists - OPENED
  R178: the subclass arc (they join the spell
  registry in the arc spell layers).
- Stronghold and tower construction economics (the
  class description sections) - the engine
  stronghold machinery is DMG-side (R106 and kin).

## The subclass arc (OPENED R178 - the scope round)

SCOPE DECISIONS (the user, 2026-10-05): the engine
grows full subclass support - all six subclasses
(paladin, ranger, druid, illusionist, assassin,
monk) plus the bard (Appendix II - the seventh
path, a fighter-then-thief-then-druid
progression), multi-class and dual-class
(two-class) characters, and the full spell
lists. The druid
and illusionist lists bring spells beyond the
current 54-spell registry; paladin and ranger
progress through the existing cleric and
magic-user lists.

The arc plan (each round flips its box HERE in the
same commit, and adds its battery audit - the
census grows with the arc):

- [x] R179 the six subclass foundations - PINNED:
      rules/subclasses.h CREATED (the data-driven
      registry - a future class lands as one
      appended row): struct SubclassDef with the
      base-class map (paladin/ranger fighter,
      druid cleric, illusionist MU, assassin
      thief, monk none), the caps with the
      fixed-hp-past-cap convention (paladin 9/+3,
      ranger 10/+2, druid 9/+2, illusionist 10/+1,
      assassin 10/+2, monk 17 rolls through), the
      hit dice (d10/d8/d8/d4/d6/d4), the XP attain
      rows cell by cell from the printed tables
      (the R176 convention), the adders (350k
      paladin past the 11th, 325k ranger past the
      12th, 220k illusionist past the 12th; the
      druid, assassin and monk print none -
      ceiling rows), and the full title ladders
      (11/12/14/12/15/17 titles). JUDGMENTs: the
      ranger and monk level 1 carries two dice
      (the printed accumulated column reads 2);
      the ranger primes STR+INT+WIS, the monk
      STR+WIS+DEX, the druid WIS+CHA (the primary
      returned). The R179 battery audit walks
      every row, title, cap and clamp. Census 96.
- [x] R180 the qualification and race gates - PINNED:
      rules/subclassgates.h CREATED: the ability
      minimums (paladin 12/9/13/-/9/17, ranger
      13/13/14/-/14/-, druid WIS 12 CHA 15,
      illusionist INT 15 DEX 16, assassin
      12/11/-/12/-/-, monk 15/-/15/15/11/-), the
      Table I alignment letters (LG paladin, G
      ranger, N druid, A illusionist, E assassin,
      L monk), the XP bonus rules (paladin STR and
      WIS over 15, ranger STR INT WIS, druid WIS
      CHA; the illusionist, assassin and monk
      print none - the assassin class text is
      explicit), Race Table I cell by cell (the
      paladin and monk human only, the ranger and
      druid half-elf and human, the illusionist
      gnome and human, the assassin all but
      halfling), and Race Table II with the
      parentheses-equal-NPC-only convention (the
      halfling druid (6); ranger half-elf 8;
      illusionist gnome 7 with the footnote-8
      conditional accessor; assassin 9/10/8/11
      dwarf/elf/gnome/half-elf, unlimited
      half-orc and human). The R180 battery audit
      walks every cell, the footnote and the
      meets-min and bonus probes. Census 97.
- [x] R181 the attacks per melee round - PINNED:
      rules/attacksround.h CREATED: the fighters,
      paladins and rangers table (1/1, 3/2 at the
      mid band, 2/1 at the high band; fighter and
      paladin 7/13 edges, ranger 8/15 edges, any
      thrusting or striking weapon), the table note
      (one attack per fighter experience level per
      round against creatures under one d8 and
      non-exceptional 0-level humans and
      semi-humans), the monk unarmed ladder cell by
      cell (Monks Table II: AC class 10 to -3,
      movement 15 to 32, the attacks slash column
      1/1 to 4/1, open-hand damage 1-3 to 8-32),
      and the monk weapon-damage bonus (half a hit
      point per level, doubled form; the monk
      attacks on the thief table, strength never
      modifies the monk to-hit - recorded for the
      specials rounds). rules/turn.cpp repinned:
      meleeAttacksPerRound was fighters level 8+
      from unsourced original notes - now the
      heavy round of the printed cycle (the 3/2
      band opens at 7th for the fighter base
      class; the actor layer carries base classes).
      The R181 battery audit walks every band, every
      monk cell and the repin. Census 98.
- [x] R182 the druid spell layer - PINNED:
      rules/druidspells.h CREATED: the SPELLS
      USABLE BY CLASS AND LEVEL - DRUIDS table
      (14 druid levels x 7 spell levels, every
      printed cell: level 1 reads two first-
      level slots, the 14th reads 6/6/6/6/5/4/3,
      the dashes pin as 0, past-14th queries clamp
      to the 14th row) and the full roster - 77
      spells with the printed level and the 16
      reversible flags (per-level counts
      12/12/12/12/8/12/9; Animal Friendship
      through Transmute Metal To Wood, the
      printed alphabetical order within each
      level). The mistletoe component rules are
      flavor (display concern). The R182 battery
      audit walks every slot cell, every roster
      row and name spot-checks. Census 99.
- R183 the illusionist spell layer - the
      illusionist list likewise.
- R184 the paladin and ranger spell layers - the
      spell progressions and the shared-list
      wiring (lay on hands, curing, the ranger
      giant-kind bonuses follow here).
- R185 multi-class and dual-class - the split
      experience machinery, the hit-dice and
      hit-point conventions, and the two-class
      rules.
- R186 the bard (Appendix II) - the progression
      gates (fighter to 5th-7th, thief to
      5th-9th, then the bard), the ability
      minimums (STR WIS DEX CHA 15+, INT 12,
      CON 10), human or half-elf, always
      neutral; Bards Table I (23 levels, bard XP
      only, hit dice added to those already
      earned, the druid spell slots capped at
      12th-level druid ability until the 23rd),
      Table II (colleges, the language gains,
      the charm and legend lore percents) and
      Table III (armor and weapons); the poetics
      morale and ferocity layers, the song
      negation, the musical charming rules, the
      item knowledge lists, and the
      most-favorite-table saves. Lands after
      R185 - the bard builds on the fighter and
      thief layers, the druid spell layer and
      the dual-class machinery.
- R187+ the per-subclass specials that remain -
      the assassin fees and disguise layer, the
      monk special abilities, backstab for the
      assassin, thief-skill sharing.

Until a round lands, each subclass stays out of
engine scope; the boxes flip per round. The
ability-table divergences (the ranked list above)
stay queued BEFORE the arc rounds - the live DEX
and CON bugs first.
