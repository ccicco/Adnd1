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
      R80/R130/R131; caster aging R129. THE INT
      TABLE II chance-to-know repin R196:
      spells.cpp chanceToLearnPct was DIVERGENT
      (the engine read 10 35, 16 70, 17 85,
      18 95; the print reads 10-12 45, 15-16 65,
      17 75, 18 85, 19+ 95) - repinned; the two
      unmodeled columns pin as minSpellsPerLevel
      and maxSpellsPerLevel (All = -1); the live
      callers (party spell learning, town study)
      now read the printed percents.
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

## The wiring arc (OPENED R227 - the engine-call pass)

The R179-R187 subclass layers and the DMG
pin rounds landed DATA; the engine-call
pass wires what has zero callers outside
regtest. The founding read found: the
Wisdom Table I magical defense adjustment
unwired, the subclass registry playable by
no character, the druid and illusionist
rosters outside the SpellId enum, and the
multi/dual-class layers data-only. The
arc boxes:

- [x] R227 the Wisdom Table I save wire - WIRED:
      rules/wisdom.h gains the mental-form
      gate seam wisMentalSaveAdj (the gated
      ladder, flat 0 on non-mental forms);
      spells::spellSaveModWis delegates to it
      (it existed with zero callers); the
      spelleffects TargetDesc gains saveWis
      (10 default - monsters read no
      adjustment, a character table);
      resolveSpell folds the gate into
      saveBonus - the field the TargetDesc
      comment always reserved for the WIS
      magic adj - so every spell save through
      the chokepoint pays the ladder;
      Actor::asTarget sets it for characters.
      Charm person and charm monster are the
      registry mental forms today; fear,
      hypnosis, suggestion and phantasmal
      forces ride the flag when their rows
      arrive. Census 143.
- [x] R228 the druid roster joins the SpellId
      registry - WIRED: 77 DR_ ids appended after
      CL_RESURRECTION (saved knownSpells indices
      stay valid); SPELL_DRUID joins SpellClass;
      77 kSpells rows with the PHB spell-description
      header parameters (casting time in segments:
      a printed turn 60, a round 10, Special 0;
      range in tens of feet, Touch 0; duration the
      base rounds of a per-level scale, Permanent/
      Special 0; save Neg./half = spells 4, none
      -1; aoe the radius in tens where the print
      gives a circle, diameter halved round-up;
      paths/cubes/miles pin 0); the parameters
      also land as the evaluable seam in
      rules/druidspells.h (eight clamped accessors,
      the grenade.h pattern) and
      spellSlots(SPELL_DRUID, ...) delegates to
      the R182 druidSpellSlots (levels 1-14,
      spell 1-7 clamped). Effects stay
      known-cast-pending (the R80 convention);
      the R80 battery walk extends to the druid
      rows and checks them against the R182 roster
      cell by cell. Eight OCR-scattered blocks
      pinned as JUDGMENTs: Entangle (table-form
      header), Invisibility To Animals, Faerie
      Fire, Insect Plague (cleric q.v.: ct 5, no
      save), Conjure Fire Elemental (ct 6 rounds
      = 60, no save), Weather Summoning (ct 1
      turn = 60, the control-weather q.v.),
      Animate Rock (ct 1 turn = 60, no save),
      Conjure Earth Elemental (ct 9 segments, no
      save). Three spell descriptions print a
      Level: divergent from the roster (Sticks to
      Snakes 5, Transmute Rock to Mud 5,
      Confusion 7) - the printed TABLE (R182)
      wins. Census 144.
- [x] R229 the illusionist roster joins the
      SpellId registry - WIRED: 61 IL_ ids appended after
      DR_TRANSMUTE_METAL_TO_WOOD (saved knownSpells
      indices stay valid); SPELL_ILLUSIONIST joins
      SpellClass; 61 kSpells rows with the PHB
      illusionist spell-description header parameters
      (the R228 druid conventions); the parameters
      also land as the evaluable seam in
      rules/illusionspells.h (seven clamped accessors -
      no reversible markers in the illusionist print)
      and spellSlots(SPELL_ILLUSIONIST, ...) delegates
      to the R183 illusionistSpellSlots (levels 1-26,
      spell 1-7 clamped). Effects stay
      known-cast-pending (the R80 convention); the R80
      battery walk extends to the illusionist rows and
      checks them against the R183 roster cell by cell.
      Thirteen OCR-scattered blocks pinned as JUDGMENTs
      (the section interleaves neighbors; the q.v. MU/
      cleric prints close the chains); six blocks print
      a Level: divergent from the roster (Dispel
      Illusion 3, Fear 3, Hallucinatory Terrain 3,
      Illusionary Script 3, Improved Invisibility 4,
      Massmorph 4) - the printed TABLE wins. Census 145.
- [x] R230 the subclass creation gates -
      WIRED: rules/subclassgates.h gains the
      creation seam (the runtime base-class map -
      the monk rides fighter, the JUDGMENT - the
      con class, the starting-age band, the
      two-dice flag, the subclass hit die, the
      player-eligibility gate, the Table II
      effective cap with the footnote-8 gnome
      conditional); creation gains the
      CR_SUBCLASS stage (the base class, then
      its registry subclasses; the monk rides
      the fighter list), the eligibility gate
      (adjusted minimums + Race Table I),
      makeSubclassMember (the subclass hit die,
      the ranger/monk two dice each with the
      per-die con adjustment, the
      druid/illusionist slot fills, the
      illusionist L1 book, the monk kit), the
      save/load subclass line (v1-compatible),
      the restoreSlots druid/illusionist
      branches, and the member class-name
      display. The alignment gates stay
      data-only (no alignment concept yet) and
      the bard (Appendix II) stays
      uncreatable; leveling, the specials hooks
      and multi/dual-class are the next arc
      items. Census 146.
- [x] R231 the subclass leveling wire - WIRED:
      rules/subclassgates.h gains the leveling seam
      (subclassXpToAttain - the printed XP attain
      rows with the adders, a private flat copy
      per the R230 EVAL NOTE; subclassFixedHpLevel;
      subclassHpBeyondFixed; subclassLevelStop (the
      R179 levelCap pins - the name-cap analog, the
      druid 14 hierarchy ceiling);
      subclassLevelCapTotal - the leveling stop
      minus a positive Table II race cap and the
      footnote-8 gnome conditional); gainXp queues
      promotions on the registry
      ladder and applies the printed +10%
      subclass experience bonus when the R180 rule
      is earned (the illusionist, assassin and
      monk print none); trainNext promotes on the
      registry ladder (the subclass hit die and
      con class, the fixed hp past the fixed-hp
      level, the illusionist studying from the
      R229 roster); the energy-drain trick resets
      to the registry level start. The base-class
      convention stands for plain members (the
      engine stops them at the name cap) and the
      henchman stays base-class. Census 147.
- [x] R232 the per-subclass specials hooks -
      WIRED: ai::Actor carries the registry
      subclass (toActor copies it); the monk
      reads the R181 open-hand ladder (the
      attack rate and the Monks Table II damage;
      the to-hit never modified by strength -
      the R181 pin; the engine carries no
      combat-form command, so the open hand is
      the class signature and the staff rides
      the pack - the JUDGMENT); the thief group
      (thief and assassin) backstabs a
      surprised foe in round one (+4 on the
      die, the x2..x5 multiplier - the
      surprise segment is the from-behind
      reading, the JUDGMENT); the ranger adds
      the giant-class damage bonus (+1 hp per
      level vs the 11 listed creatures,
      family-name matching the R184 caller
      concern); the paladin lays on hands
      (2 hp per level, once per career day,
      the [F] town key, the most-wounded
      member, the v1-compatible layhands save
      line). The monk stun/kill and quivering
      palm, and the ranger/paladin surprise
      and turn-undead numbers, stay data (the
      R187 records) - a combat-form command
      round owns them. Census 148.
- [x] R233 the multi-class engine - WIRED: the
      R185 combo table is playable - the [M]
      creation stage (the race printed combos,
      the eligibility gates: every class passes
      its own minimum on the ADJUSTED prime and
      Race Table I, the subclass bits their R180
      minimums and player-eligibility, the
      half-elf multi-class cleric WIS 13), the
      member factory (every class die rolls with
      its con adjustment and reads the quotient
      - the R185 rule; the kit rides the most
      restrictive armor allowance and the
      all-allow shield gate - the JUDGMENT); the
      member rides the PRIMARY class - the first
      set bit (the fighter bit when the combo
      carries it - the best melee class on the
      swing - the JUDGMENT; every printed combo
      rides a base-class primary); the ranger,
      assassin and illusionist bits roll their
      R231 subclass dice on promotion; the
      requisites average
      (PHB p.20), the combo earns no
      single-class bonus, the promotions queue
      on the primary ladder and roll every
      UNSTALLED class die (a class at its name
      cap contributes none - the R185 stalled
      pin), reading the quotient; the
      v1-compatible multi save line; the R233
      battery audit. Simplifications recorded:
      the roster display shows the primary class
      name; the caster slots fill from the
      primary caster (no slot-summing).
      Census 150.
- [x] R234 the dual-class engine - WIRED: the
      human class change is playable - the guild
      command (the [K] town key; the first member
      who meets the gates switches to the first
      qualifying base class - the deterministic
      pick), the gates (human only, 15+ in the
      ADJUSTED prime of the old class, 17+ in the
      new, one switch only, a plain single-classed
      member), the switch itself (the hit dice and
      hit points RETAINED, all functions at 1st
      level of the new class, the kit rides the new
      profession, the caster slots and the MU book
      restart at 1st level), the resort stance
      (the [U] town key - while held the member
      earns no experience, the print: reversion
      negates it; free once the new level EXCEEDS
      the old), and the promotion die (no die at or
      below the old level; the engine canonical
      new-class die once exceeded). Simplifications
      recorded: the resort stance is a standing
      town toggle (the engine has no per-adventure
      XP boundary), the switch targets the base
      classes only (the printed paladin and ranger
      combinations stay future work), the roster
      prints the F6>M1 line. Census 152.
- [x] R235 the bard engine - WIRED: the
      Appendix II career is playable - the guild
      studies (the [A] town key; the first member
      who meets the gates begins), the gates (a
      fighter-turned-thief inside BOTH printed
      windows - fighter 5th-7th, then thief 5th-9th
      - human or half-elf, the ability minimums
      STR WIS DEX CHA 15+, INT 12, CON 10), the
      studies (the hit dice and hit points
      RETAINED, all functions at 1st level, the
      Table III kit - leather, no shield, a bard
      weapon - and the Table I level-1 druid
      slots), the leveling (the Table I XP ladder,
      bard XP only, capped at the 23rd; the Table
      I d6 promotion column with the druidical con
      adjustment), the combat castable list (the
      druid roster from the Table I slot columns,
      levels 1-5), the B roster line and the
      v1-compatible bard save line. Simplifications
      recorded: the alignment pin (always neutral)
      stays data-only (no alignment concept yet),
      the poetics layers, the colleges, the
      henchmen ladder and the musical item bonuses
      stay data-only (the R186 pins), the engine
      has no scimitar (the kit rides the long
      sword - a permitted Table III arm), the
      druid spell EFFECTS resolve on the generic
      combat layer. Census 154.

- [x] R236 the bard specials - WIRED: the
      Appendix II poetics and lore go live -
      the ferocity (a living bard in the
      company who has sung past the 2 printed
      rounds grants the party +1 on melee
      to-hit rolls in resolveMelee; the morale
      half is void - the party is
      MORALE_FANATIC; the 1-turn duration is
      simplified to while the bard lives; melee
      only - the R232 precedent), the item
      knowledge (the [X] town key - the finest
      living bard studies the front
      unidentified find on a Table II legend
      lore roll; a miss leaves the item queued,
      retryable, no cost; a hit resolves like
      the identify scroll - the same taker
      logic, else sold for 200 gp), and the
      college announcement (the studies-begin
      message names the first college).
      Simplifications recorded: the henchmen
      ladder and the musical item bonuses stay
      data-only (the R186 pins; no
      bard-henchmen concept, no musical items
      in the registry), and the song never
      negates (no harpies or shriekers in the
      monster special set). Census 155.

## R296 the unrecorded-sections pass (the second
scope round)

R296 SCOPE PASS. Diffing the PHB upload section
list against this ledger found five sections
the report never explicitly pinned or marked
OUT. They are recorded here, per the R177
convention that a scope decision gets written
down. A report round adds no audit; the battery
census stays 213.

## Open items (the R296 additions)

- [x] **Weapon Proficiency Table (the WEAPONS
      section) - PINNED R297:**
      rules/weaponprof.h CREATED - the ten
      printed rows (the initial slots, the
      non-proficiency penalty, the added-slot
      cadence) with the engine mapping
      (wpfRowFor: the base-class pair to the
      printed row; the subclass row wins when
      the registry subclass is set, the
      fighter default matches attackNumber),
      the slot-at-level walker wpfSlotsAt
      (the printed cleric example: 2 at 1st,
      3 at 5th, 4 at 9th, 5 at 13th) and the
      printed notes (the same-type magical
      subsumption, the missile-or-melee reach,
      the levels-above-the-1st cadence).
      WIRED: the penalty seam wpfNonProfHitAdj
      folds into Actor::hitAdjustment
      (ai/actor.cpp) - a held weapon outside a
      RECORDED slot list pays the class
      penalty (-2 to -5); the empty list =
      the pre-R297 convention (unrecorded
      choices never pay), and the monk open
      hand stays flat 0 (the R181/R232 pins).
      The kitNpc NPCs record their kit weapons
      (game/state_combat.cpp). Simplifications
      recorded: the party roster recordings are
      the R299 kit grant (the R299 section
      below), the slot COUNTS stay data (the
      engine sizes no lists beyond the kit
      grant) and the ranged slot records with
      the thief kit (R299). The R297 battery
      audit walks the three columns row by
      row, the clamps, the mapping pair probes
      and the seam identity. Census 214.
- [x] **Thief Function Take table and DEXTERITY
      TABLE II (the THIEF and DEXTERITY
      sections) - PINNED R298:**
      rules/thieffunc.h CREATED (a DATA-ONLY
      pin, the R186 poetics precedent - the
      engine performs no thief rolls; the
      seam waits for a future roll round) -
      the take table (upload line 1620) runs
      thief levels 1 through 17 across the
      eight functions (pick pockets, open
      locks, find/remove traps, move
      silently, hide in shadows, hear noise,
      climb walls, read languages), pinned
      in TENTHS of a percent (the printed
      climb walls column carries a decimal
      from the 11th level: 99.1% reads 991;
      the read languages dash at levels 1-3
      reads 0); the six racial adjustment
      rows beneath (upload lines 1645-1650;
      the human default reads 0) keyed to
      the rules/races.h enum; and DEXTERITY
      TABLE II (upload line 400), the five
      thief adjustment columns for scores 9
      through 18 (below the 9 reads the 9
      row, above the 18 the 18 row - the
      character.h DEX Table I convention;
      hear noise, climb walls and read
      languages print no column and read
      0). The seam thfChanceTenths folds
      base + race + DEX (the adjustments
      additional pluses). The printed notes
      pinned: the percentile roll (equal or
      less succeeds), the 21% pick pockets
      notice band, the 5% victim cut above
      the 3rd (the printed 12th-level
      half-elf example: 120 - 45 = 75) and
      the locks/traps one-try rules. The
      R298 battery audit walks the take
      table cell by cell, the racial and DEX
      rows, the clamps and the printed
      example. Census 215.

## R299 the party recordings round (the third
scope pass rides)

R299 WIRED the party roster into the R297
penalty seam - the R297 simplification note
above is amended (the future round landed).
The kit grant at creation is the initial
proficiency choice set:

- [x] **The party kit weapon recordings -
      WIRED R299:** the Character gains
      profWeaponIds (game/party.h); the grant
      method grantKitProficiencies records
      the class kit - the melee arm every
      kit carries, plus the ranged slot
      where the kit carries a missile (the
      thief rows: the short sword and the R28
      sling; the monk records the R230 staff;
      the bard the Appendix II long sword).
      The grant lands at creation
      (makeMember), the subclass overlay
      (makeSubclassMember - the monk staff),
      the profession switch (the old choices
      do not persist), the bard studies and
      the save load rebuild (the R33 v1
      convention - the recordings are not
      saved; a loaded member re-reads the
      kit). toActor copies the list to the
      combat Actor - a held weapon outside a
      NON-EMPTY list now pays the class
      penalty LIVE (a fighter with a claimed
      battle axe pays -2; a magic-user with
      a staff pays -5). Simplifications
      recorded: the added-slot choices stay a
      future choice round (the counts are
      data), the grant ids are the engine
      canon kits (the kit switches and the
      grant agree - pinned by the engine
      audit) and the henchman keeps the
      empty-list convention. The rules seam
      (wpfKitRecordsMelee,
      wpfKitRecordsRanged, wpfKitGrantCount -
      rules/weaponprof.h) pins the slot-count
      convention; the R299 battery audit pair
      walks the seam (evaluable) and the
      engine wiring (the R233a/R233
      precedent). Census 217.

R299 SCOPE PASS (the third pass, riding this
round): the upload sections diffed against
this ledger again. Recorded: the HENCHMEN
prose (the about-50% henchman award note)
matches the R45 engine convention (cited
DMG p.86; the PHB section carries no table
to pin); the SILENT MOVEMENT prose reads the
R298 move silently column (the surprise link
rides the future thief roll round); the
weather tables live inside the control
weather spell prose (the registry is the
engine spell layer). ONE new open item
found and opened below.

## Open items (the R299 addition)

- [x] **The equipment cost columns (the BASIC
      EQUIPMENT AND SUPPLIES COSTS tables,
      upload line 2113; the reference-sheet
      repeats at upload line 13432)** - PINNED
      R300: rules/equipcosts.h CREATED - the
      52 arms rows and the 14 armor rows
      pinned cell by cell (eqcArmsGold,
      eqcArmsSilver, eqcArmorGold and the
      name arrays; exactly one coin unit
      nonzero per arms row; the six silver
      rows are the ammo prices - the single
      arrow 2 s.p., the dart 5, the javelin
      10, the light quarrel 1, the dozen
      sling and bullets 15 and the score of
      sling bullets 10) and the monetary pin
      20 s.p. = 1 g.p. (eqcSilverPerGold).
      Both upload copies read: the reference
      sheet is legible, the equipment copy
      interleaves - it resolves the empty
      glaive cell to 6 g.p. and confirms the
      left rows 1-28 and the right rows
      1-24. The ENGINE items.cpp costGp
      column REPINNED where it diverged
      (9 repins: hand axe 4 to 1, battle axe
      7 to 5, flail 15 to 3, morning star 10
      to 5, spear 3 to 1, short bow 25 to 15,
      long bow 40 to 60, light crossbow 10
      to 12, scale mail 50 to 45) - the
      printed-table-wins debt paid.
      JUDGMENTs recorded: the generic mace
      and flail read the printed footman
      rows (8 and 3 g.p.); the quarterstaff
      and club are not in the print (0 stays
      ENGINE CONVENTION); the sling keeps
      the 2 g.p. engine price (the print
      prices the dozen-bullet bundle); the
      shield file-static 10 g.p. equals the
      print Shield, small row (no accessor -
      recorded, not audited); the banded row
      prints Bonded in one copy (the
      standard banded mail, 90 g.p.). The
      helmet rows and the ammo prices carry
      no engine layer (dead data - no shop
      charges them; the town stores price
      canonically). The R300a battery audit
      walks the seam (evaluable - verified
      by audit_eval) and the R300 engine
      audit maps every items weapon and
      armor id to its printed row.
      Census 219. The ledger holds ZERO
      open items.

## Out of engine scope (the R296 additions)

- Money changing, banks, loans and jewelers
  (the MONETARY SYSTEM section) - the engine
  economy is gold-only (starting money R190,
  the town ledger R93, taxation R207); no
  exchange or credit layer exists or is
  wanted.
- Appendix V (the suggested agreements for
  division of treasure) - the party division
  agreements are player-side; the mechanical
  share machinery is R93/R103.
- Appendix IV (the known planes of
  existence) - the engine has no planar
  layer; the planar references that matter
  (the artifact prose) are DMG-side and
  pinned there. R299: the full planar
  material arrives with the Manual of the
  Planes (the user decision); the pin
  round waits for that source.

The R178 subclass-arc precedent: OPEN the
scope items first, pin them in following
rounds, flip the boxes in the same commits.
The two R296 open items follow that shape -
the proficiency table first (it is live
to-hit wiring), the thief tables after
(data-only).
