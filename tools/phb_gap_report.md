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
every founding-read divergence is closed (R178c 1-2,
R193 5, R194 3, R195 4) - all six PHB ability
tables now read the print.

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
- [x] 3. **WIS Table I, magical attack adjustment
      (the WISDOM TABLE I page)** -
      CLOSED R194: rules/character.cpp wisMagDefAdj
      repinned to the print (3 -3, 4 -2, 5-7 -1,
      8-14 0, 15 +1, 16 +2, 17 +3, 18 +4) by
      DELEGATING to rules::wisMagicalAttackAdj
      (the R192 header pin - one ladder, not two).
      The saves.h modifier note repins: the
      adjustment applies only to mental attack
      forms involving will force (beguiling,
      charming, fear, hypnosis, illusion, magic
      jarring, mass charming, phantasmal forces,
      possession, rulership, suggestion, telepathy)
      - the save rolls still do not call it; the
      caller assembles the modifier (the per-spell
      mental-form flag is not yet engine data).
      The R194 battery audit walks the ladder and
      the delegation. Census 111.
- [x] 4. **INT Table I, additional languages (the
      INTELLIGENCE TABLE I page)** -
      CLOSED R195: rules/character.cpp
      intExtraLanguages repinned to the print (3-7
      none, 8-9 one, 10-11 two, 12-13 three, 14-15
      four, 16 five, 17 six, 18 seven). The engine
      convention diverged at every score above 3
      (4-5 one, 6-8 two, 9-12 three, 13-15 four,
      16-17 five, 18 six). Display-only accessor,
      no other callers. The R195 battery audit
      walks the column cell for cell. Census 112.
      THE FOUNDING-READ DIVERGENCE LIST IS NOW
      EMPTY - every PHB ability table is pinned to
      the print (STR R153, DEX R178c, CON R178c,
      INT R195, WIS R194, CHA R193).
- [x] 5. **CHA table (reaction adjustment, loyalty
      base, henchmen - the CHARISMA TABLE page)** -
      CLOSED R193: all three accessors repinned
      cell for cell. chaReactionAdj is now the
      printed PERCENT ladder (-25 at 3 through
      +35 at 18; 13 +5, 14 +10, 15 +15, 16 +25,
      17 +30) - the live d100 reaction bands
      (dm.cpp rollReaction, five party call sites)
      read the printed percents directly, no band
      re-carving needed. chaLoyaltyBase is the
      printed percent ladder (-30 through +40;
      14 +5, 15 +15, 16 +20, 17 +30). The henchmen
      column repinned at its two divergent cells
      (cha 4 = 1, cha 12 = 5) - the rest already
      matched the print. The character.h range
      comments repinned with them. The R193
      battery audit walks all three columns, all
      16 scores. Census 110.

## Open items (worth having)

- [x] **Prime requisite XP adjustment - PINNED R188:**
      rules/xpadjust.h CREATED: the printed per-class
      +10% of earned experience gates (fighter STR,
      magic-user INT, cleric WIS, thief DEX; paladin
      STR and WIS, ranger STR INT and WIS, druid WIS
      and CHA - each 16 or more; illusionist,
      assassin and monk never) and the worked-example
      rounding (975 -> +98 -> 1073, fractions round
      up). The verify: the engine ladder +10 rung is
      the printed rule; the +5, 0, -10 and -20 rungs
      are ENGINE CONVENTION, unsourced - the PHB
      class sections carry only the +10 percent
      notes, the DMG adjustment section has no
      prime-requisite ladder and the phrase does not
      appear in the DMG at all. The character.cpp
      comment records the verify. The R188 battery
      audit walks every gate and the rounding. Census
      105.
- [x] **The PHB book-verify pass for the weapon tables -
      PINNED R189:** rules/weapontables.h CREATED:
      the WEIGHT AND DAMAGE BY WEAPON TYPE chart (50
      rows, every cell: the weight in gold pieces,
      the S/M and L damage ranges; the spear weight
      40-60 pinned as a range). The verify: every
      readable speed-factor cell of the WEAPON TYPES
      chart confirms the R158 engine ladder row for
      row (18 named weapons; the spear default 7 sits
      inside the printed 6-8; the horseman flail cell
      is OCR-mangled - the engine 6 stays recorded
      convention). The R144/R145 p.38 AC-adjustment
      standing note CLOSES: R149 verified 8 of the 15
      engine rows cell for cell against this upload;
      the remaining AC cells are OCR-mangled (digit
      runs where single modifiers belong) and stay
      pinned to the 1eonline compilation. The printed
      notes pin: the lances double from a charging
      mount (rows 24-26), the spear set doubles, the
      +2 back / +4 stunned-prone-motionless combat
      note; the italics set-weapon roster is not
      recoverable from this OCR - recorded. The R189
      battery audit walks all 50 rows and the speed
      cross-verify. Census 106.
- [x] **Starting money by class (the MONEY section) -
      PINNED R190:** rules/startmoney.h CREATED -
      the printed STARTING MONEY table: cleric 3d6
      (30-180 gp), fighter 5d4 (50-200), magic-user
      2d4 (20-80), thief 2d6 (20-120), every class
      row a dice roll TIMES 10 gold pieces, plus the
      printed MONK row 5-20 gp (5d4) - the one entry
      with NO x10 (the DMG MONEY section explains:
      monks are ascetics). The DMG companion rule
      pins with it: not less than 100 gp per level
      per month support cost. The engine has NO
      party-creation money code (verified
      repo-wide) - the unverified-convention worry
      resolves to a fresh pin; subclass starting
      money is not printed (recorded). The R190
      battery audit walks all five rows. Census
      107.
- [x] **Armor Class table (the ARMOR section) -
      PINNED R191:** rules/armorratings.h CREATED -
      the printed ARMOR CLASS TABLE ladder (none 10,
      shield only 9, through plate mail + shield 2),
      the shield step, the magic rule (each +1
      lowers AC 1; a +1 converts to a 5% lesser
      likelihood of being hit), the flank/rear
      shield negation and magic-armor-weightless
      notes. The verify found ONE divergence: the
      engine None armor row read baseAc 9 against
      the printed 10 - REPINNED in items/items.cpp
      (the repin also matches the engine p.38
      worked examples, Balto unarmored AC 10; the
      shield-only composite now reads the printed
      9). The other nine rows verified cell for
      cell: padded 8, leather 8, studded 7, ring 7,
      scale 6, chain 5, splinted 4, banded 4, plate
      3. The effectiveAc cap at 10 stays engine
      convention (the p.38 columns run 0-10; a DEX
      penalty cannot push effective AC past 10 -
      recorded). The R191 battery audit walks the
      engine rows, the composites and the worked
      examples. Census 108.
- [x] **Fighter attacks per melee round (the class
      tables section)** - PINNED R181: the engine
      convention verified and repinned - the printed
      bands now live in rules/attacksround.h and
      rules/turn.cpp (meleeAttacksPerRound was the
      unsourced level-8+ original note).
- [x] **Wisdom Table II, cleric bonus spells and
      spell failure - PINNED R192:** rules/wisdom.h
      CREATED - Wisdom Table I (the magical attack
      adjustment ladder 3 -3 through 18 +4, mental
      attack forms only; the high-circle gates - 17
      is the minimum wisdom for 6th level spells, 18
      for 7th) and Wisdom Table II (the CUMULATIVE
      bonus ladder - wis 13 one 1st through 18 two
      1st, two 2nd, one 3rd, one 4th; the failure
      ladder 20/15/10/5/0 at wis 9-13). WIRED in
      spells/spells.cpp: clericSpellSlotsWithWis
      (base slots + bonus, granted only when
      entitled - the printed note; the Wis-17/18
      gates close the R130 documented engine
      limit; the printed L16 ** row already grants
      the 7th at 16, the gate is wisdom-side) and
      rollClericSpellFailure (d100 equal or less:
      the spell is expended with no effect). The
      R192 battery audit walks both tables cell
      for cell and the wiring. Census 109.

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
- [x] R183 the illusionist spell layer - PINNED:
      rules/illusionspells.h CREATED: the SPELLS
      USABLE BY CLASS AND LEVEL - ILLUSIONISTS
      table (26 illusionist levels x 7 spell
      levels, every printed cell: level 1 reads
      one first-level slot, the 26th reads
      7/7/7/7/6/6/6, the dashes pin as 0,
      past-26th queries clamp to the 26th row)
      and the full roster - 61 spells in the
      printed book order (per-level counts
      8/16/11/5/12/4/5; Audible Glamer through
      Vision). JUDGMENT: the illusionist section
      prints NO Reversible markers (Continual
      Darkness and Continual Light are separate
      listed spells), so the roster carries no
      reversible flag. The R183 battery audit
      walks every slot cell, every roster row and
      name spot-checks. Census 100.
- [x] R184 the paladin and ranger spell layers - PINNED:
      rules/palrangerspells.h CREATED: the
      SPELLS USABLE BY CLASS AND LEVEL - PALADINS
      table (levels 9-20 x 4 clerical spell
      levels, every cell: 9th 1/1st, the 20th
      3/3/3/3 max ability; below 9th no slots,
      past 20th clamps) and the RANGERS table
      (levels 8-17 x druidic 1-3 + MU 1-2,
      every cell: 8th one druidic 1st, 9th adds
      MU 1st, the 17th 2/2/2/2/2 max ability;
      below 8th no slots, past 17th clamps),
      the shared-list wiring (paladin: the cleric
      list, never clerical scrolls; ranger: the
      R182 druid roster levels 1-3 and the
      magic-user list levels 1-2, learn-checked
      as if a magic-user, no scrolls), and the
      printed specials: lay on hands (2 hp per
      level, once per day), cure disease (once
      per week per five levels), the giant-class
      damage bonus (+1 hp per ranger level vs
      the 11 listed creatures: bugbear through
      troll). The ranger surprise numbers and
      the paladin turn-undead ladder are
      recorded for R187+. The R184 battery audit
      walks every cell and ladder. Census 101.
- [x] R185 multi-class and dual-class - PINNED:
      rules/multiclass.h CREATED: the per-race
      MULTI-CLASS combination table (dwarf 1,
      elf 4, gnome 3, half-elf 8, halfling 1,
      half-orc 5, human 0 - every printed combo
      as a class bitmask), the hit-point
      quotient (sum the dice, adjust for CON,
      divide by the class count, drop fractions
      under 1/2, round 1/2 and up), the even XP
      split, the stalled-hit-dice rule (a class
      at its cap gives no further dice), the
      thief-armor limitation, the cleric
      edged-weapons allowance, the half-elf
      multi-class cleric WIS 13, and the
      human-only dual-class gates (15+ old
      prime, 17+ new prime; the retained hit
      dice, the 1st-level functions, the
      negated XP on old-class use and the
      level-exceeds mechanics recorded in the
      header comments for the engine rounds).
      The R185 battery audit walks every combo
      cell, ladder and gate. Census 102.
- [x] R186 the bard (Appendix II) - PINNED:
      rules/bard.h CREATED: the gates (fighter
      5th-7th, thief 5th-9th, then the druid
      studies; STR WIS DEX CHA 15+, INT 12,
      CON 10; human or half-elf; always
      neutral), Bards Table I (23 levels: the
      XP thresholds 0 through 3,000,001, the
      titles Rhymer through M. Bard 23rd, the
      hit dice 0* then 1-10 then 10+1 through
      10+12 added to the retained fighter and
      thief dice, the druid spell slots 1-5
      every cell, the cast level capped at 12th
      druid ability until the 23rd casts at
      13th - the row-20 boundary pins as
      1,800,001, the strictly increasing
      sequence over the upload OCR 1,000,001),
      Bards Table II (the colleges Probationer
      through Magna Alumnae, the language
      gains, the charm 15-95 and legend lore
      0-99 percents, every cell), Bards Table
      III (leather or magical chainmail, no
      shield, the nine permitted weapons, oil
      yes, poison never except by neutral evil
      bards), the combat-as-fighter /
      thief-functions / most-favorable-saves
      wiring, the poetics layers (morale +10%,
      hit +1, 2 rounds, 1 turn), the song
      negation, the musical charming rules, the
      item knowledge lists, the henchmen ladder
      (1 at 5th through any number at 23rd) and
      the musical item bonuses. The R186
      battery audit walks every cell of both
      tables. Census 103.
- [x] R187 the per-subclass specials - PINNED:
      rules/subclassspecials.h CREATED: the
      MINIMUM FEES FOR ASSASSINATION table (15
      rows x 8 victim bands, every cell, dashes
      as 0; the noble-victim multiplier is a
      referee judgment recorded in comments),
      the disguise spotting layer (base 2% per
      day, +2% per pose difference, max 8%; the
      observer INT+WIS adjustment below 24 and
      above 30), the backstab multipliers
      (double through quintuple per four
      levels, hit +20%/+4), the thief-skill
      sharing (the assassin two levels below,
      backstab at full level; the monk at
      identical level with the six listed
      abilities - open locks is the numbering
      head the OCR swallowed), the monk surprise
      ladder (33 at 1st, 32 at 2nd, down 2% per
      level), the monk specials A-K (one per
      level 3rd-13th: speak with animals, ESP
      masking, disease immunity, catalepsy,
      healing, speak with plants, charm
      resistance, mind blast as 18 INT, poison
      immunity, geas immunity, the quivering
      palm), the open-hand stun and kill rules
      (stun at 5+ over the needed roll, 1-6
      rounds; kill percent AC + one per level
      above 7th), the monk save advantages, the
      ranger surprise numbers (surprises on d6
      1-3, surprised on 1) and the paladin
      turn-undead ladder (a cleric of paladin
      level minus two, from 3rd; wraps the R147
      matrix III) - the R184 records paid off.
      The R187 battery audit walks every fee cell
      and ladder. Census 104.

Until a round lands, each subclass stays out of
engine scope; the boxes flip per round. The
ability-table divergences (the ranked list above)
stay queued BEFORE the arc rounds - the live DEX
and CON bugs first.
