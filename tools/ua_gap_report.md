# UA Gap Report - the book vs the repo

R322 ARC OPENER. The standing scope (the
seed, 2026-10-05) names Unearthed Arcana.
This report inventories the whole UA book
against the engine and is, by design,
lossless: it mirrors the book own
structure (the players section pp. 5-73,
the dungeon masters section pp. 73-105,
the appendices pp. 106-129), every named
table and chart from each section own
index gets its own line item (the
manifest - nothing can be skipped
silently), and every load-bearing prose
mechanic is its own sub-item rather than
a clause in a paragraph. Cantrips are
their own top-level category, separate
from the spells, per the standing
decision. Engine scope unchanged: the
data-driven class and spell registries
(append a row, not a re-carve), the
rules/ pin headers, the battery audits.
Closure criterion: a box closes when
the feature PLAYS right - compiling is
not the test; the game-level logging
layer is the instrument. The universe:
this book, the landed DMG and PHB
reports, and - named for the future -
the house-rules and third-party arcs;
the engine ingests any source the same
way (survey, gap report, pins,
provenance).

Conventions as the DMG report: [x]
verified against the book text (with the
round); [~] verified DIVERGENT; [ ] open
item; DEFERRED for wants gated on an
engine layer not yet built. A round
closes an item by flipping the box in the
SAME commit. Page cites are the printed book
pages (the PDF OCR file page is the
printed page plus one).

## The OCR grain

The markdown extract gives clean prose
but mangled grids. The PDF OCR (130
pages) is the better source and reads
CLEAN for every load-bearing grid: Race
Table I, the Race Table II sub-tables,
Classes Tables I and II, the Racial
Preferences matrix, Cavaliers Table I,
Barbarians Table I, the specialization
table, the thief-acrobat function table,
the Method V dice table, the follower and
henchman tables, the armor table, the
weapon data tables, the treasure tables
III.A through III.H. Only the printed
page 73 illustration sheet OCRs as
blurry images; it carries no rules. Where
the two sources disagree the PDF wins
(the comeliness band-6 reaction, 100
percent, and the +6 hazardous order
modifier were two such fixes, already
pinned).

## Players section (pp. 5-73)

### Character abilities (p. 6-7)

- [x] **Comeliness** - CLOSED R322: the
      3d6 base roll after the six
      attributes; the charisma adjustment
      ladder (-8, -5, -3, -1, 0, +1, +2,
      +3, +5); the viewed-race adjustments
      with the same-race pairs (the
      engine elf carries the +1 sylvan
      read; the +2 gray/high subrace
      grain pins in the R323 subrace
      layer); the ten reaction bands; the
      100/150/200 initial-reaction
      multipliers; the fascinate wisdom
      floors (50 percent, two-thirds, 75
      percent, the 18/20 sought minimums,
      the 19 save); the illusion
      one-point cap; the polymorph
      two-point and the shapechange
      full-form read; the 3d6 order roll;
      the point-for-point charisma
      coupling. rules/comeliness.h,
      pinned data only - no engine site
      exists (no comeliness field; the
      R117 reaction table has no callers)
      - the pin-era pattern: pin now, wire
      when a site exists. The battery
      census moves 248 -> 249 with the
      R322 audit.

### Character races (pp. 7-12)

- [x] **Race Table I** (p. 7, the
      class-limit matrix, 15 racial
      types against the 14 UA classes)
      - CLOSED R323: the CharSubRace
      and UaClass enums, the matrix
      and the alignment-requirements
      column, rules/subraces.h; the
      R323 seam audit.
- [x] **Race Table II** (pp. 8-9, the level-limit
sub-tables) - CLOSED R324: the six sub-tables - II.A
dwarves, II.B gnomes, II.C elves (both printed blocks),
II.D half-elves, II.E halflings, II.F half-orcs (the
print letters; the earlier report letters were off by the
print) - the 47 columns with the dark-elf sex split and
the 18/01-18/00 exception rows, the U reads, the
footnoted ability gates (the ranger INT/ WIS riders with
the OR footnote, the assassin INT/DEX riders, the druid
CHA riders) and the escalation riders, the below-
first-row floor rule, the +2 single-class rule;
rules/subracelevels.h; the R324 audit (census 251). The
leveling wiring CLOSED R325: the
level-up fold (rules/subracecap.h;
uaLevelCap at the gainXp queue and
the trainer, the uaSubrace field
with its save line; the R325 audit,
census 252).
 The creation round CLOSED R326:
the sub-race picker stage (the
CR_SUBRACE offer), the female
field with its save line, the
dark-elf sex split live at the
fold; the R326 audit, census 253.
- [x] **The sub-races** (pp. 10-12) -
      CLOSED R323: the SubRaceTraits
      records - the duergar immunities,
      surprise and daylight ladder;
      the gray/valley +1 INT max 19;
      the wood +1 STR/-1 INT; the
      grugach +2 STR, the 90 traps,
      the fighter/thief gate; the drow
      +2 magic saves, the sex-split
      movement, the two-weapon read,
      the innate spell lists, the
      light penalties; the svirfneblin
      saves, the camouflage, the
      earth elemental table, the
      innate spells; the half-elf
      ancestries with the grugach
      no-instances read; the halfling
      strains with the mixed-blood
      stout read - rules/subraces.h.
- [x] **The Racial Preferences matrix**
      (p. 12) - CLOSED R323: the 17x17
      letter matrix (the P/G/T/N/A/H
      codes), the diagonal-P check and
      the print asymmetries pinned; the
      half-elf footnote (elves react as
      the worse of half-elf or the
      ancestor) named for the caller;
      rules/subraces.h; pin-only until
      the reaction site exists.

### Character classes (pp. 12-25)

- [x] **Classes Table I** (p. 12, the
      hit dice and level limits: cavalier
      d10, barbarian d12, ranger 2d8,
      monk 2d4, druid limit 23 hierophant)
      and **Table II** (p. 13, the armor
      and weapons permitted per class,
      with the cavalier/paladin station
      notes) - CLOSED R327: the pin round
      (rules/classtables.h): the
      hit-die column with the two-dice
      first levels, the note-1
      social-standing generators (3d4+1
      or d10+3), the ranger 11-dice and
      monk 18-dice maxima, the druid 23,
      the spell-ability legs (paladin
      clerical 9th-4th, ranger druidic
      8th-3rd and MU 9th-2nd, the thief
      10th and assassin 12th scroll
      reads), the Table II footnotes
      (the station armor and weapon
      bans, the oil siege exception,
      the acrobat as-thief-plus row);
      the weapon and oil/poison columns
      ride the landed R198/R199 pins;
      the cavalier and barbarian level
      ladders ride their own class
      rounds; the R327 audit (census
      254).
- [x] **The cavalier** (pp. 14-16) - the
      minima (STR/DEX/CON 15, INT/WIS 10,
      good alignment); the social-class
      gate (Upper Class direct entry; the
      sponsored lower classes via the
      0-level track); **the 0-level track**
      (Horseman -1500 xp with 1d4+1 hp,
      Lancer -500 xp, then Armiger; the
      Armiger 1d10+3 vs the track 3d4+1
      hit dice read); the race limits
      (human; gray/dark/high elf and such
      half-elf stock, noble sponsorship);
      **the weapons of choice ladder**
      (mounted lance +1 at 1st/+2 at 7th/
      +3 at 13th with the level damage
      bonus mounted and +1 dismounted;
      broad/long/scimitar +1 at 3rd/+2
      at 9th; mace/flail/pick +1 at 5th/
      +2 at 11th; same weapon carried up
      the ladder; the attacks as 5 levels
      higher with a weapon of choice, 3
      per round at 16th+); the lance
      dismounted reads (heavy = awl pike,
      medium/light = spear); **the parry
      rules** (weapon parry subtracts all
      to-hit bonuses; shield parry -1
      minus the magic plus on the second
      opponent); **the armor preference
      order** (plate > plate mail >
      banded/splint > chain > scale >
      ring; never leather/studded/padded;
      holds for magic armor); the human
      mounted +1 level; the 85 percent
      saddle/fall chance +1 percent per
      level above 1st; **the horsemanship
      ladder** (3rd vault, 4th the female
      elf unicorn, 5th the +2 speed for 6
      turns, 7th pegasus, 9th hippogriff,
      11th griffon); the steed-worth
      estimate and the +2 hp per die;
      **the percentile growth** (STR/
      DEX/CON percentiles rolled at 1st,
      +2d10 per level, over 100 raises the
      main score by 1, cap 18/00, lost on
      level loss); the training rule (a
      trainer of 4th or 2 higher until
      6th); **the saves and immunities**
      (fear immunity plus the 1 protection
      from fear aura for allies; 90
      percent resistance to mind-affecting
      powers - beguiling, charm,
      domination, hold, hypnosis, magic
      jar, possession, sleep, suggestion,
      the psionic mind blast - but not
      comeliness; +2 versus illusion); the
      good-alignment negative-hit-point
      window (to minus the 1st-level hp
      total) with the 1-4 per week healing
      bonus; the pennon at 4th; the
      hospitality read; **the chivalric
      code** (the eight virtues, the
      twelve-point code, the knighting
      ceremony, the revocation read - the
      weapons of choice survive it).
      - CLOSED R328: the pin round
      (rules/cavalier.h): the minima,
      the good-alignment gate, the
      0-level track, the race gate,
      the weapons-of-choice ladder
      and the preferred weapons, the
      parry and armor reads, the
      mounted and horsemanship
      ladders, the steed reads, the
      percentile growth, the
      training rule, the saves and
      immunities, the negative-hp
      window, the chivalric code
      facts, the Table I XP ladder
      and the known title cells (the
      5, 6, 11 and 12 holes stay
      open with the Cavaliers Table
      I item); the R328 audit
      (census 255).
- [x] **Cavaliers Table I** (p. 15) -
      the XP ladder, the level titles
      (Horseman to Cavalier Commander),
      the 3 hp per level after 10th, the
      300000 xp per level past 12th;
      reads clean.
      - CLOSED R368: the pin round
        (rules/uacavtable.h) - the two
        0-level rows, the 1st-level
        footnote, the printed XP bands
        (the level-11 band decoded from
        its neighbors), the cumulative
        dice column, the titles: the
        11th and 12th cells newly
        readable (two of the four R328
        holes close), the level-5 grid
        Knight with the prose conflict
        flagged, the 3 hp per level
        past 10th, the 300,000 xp past
        12th; the level-6 title cell
        and the 12-sided header cell
        stay holes pending the PDF;
        the R328 seam cross-checks;
        CLOSED.
- [x] **The paladin re-parented under
      the cavalier** (p. 16) - the R184
      touches landed; the cavalier-side
      abilities ride the cavalier charge;
      the retainer rules differ (DM p.
      75); paladins take no weapon
      specialization.
      - CLOSED R329: the pin round
      (rules/paladin.h): the
      re-parenting (cavalier
      sub-class, no longer
      fighter), the minima (the
      R328 requisites plus WIS
      13 and CHA 17), the
      lawful-good gate with the
      stray read, the social
      station with the 0-level
      track delegation, the
      no-prime-requisite and
      no-specialization reads,
      the cavalier charge (the
      five abilities), the CHA
      percentile growth, the
      retainer cross-reference
      (DM p. 75); the R329 audit
      (census 256).
- [x] **The druid hierophant ladder**
      (pp. 16-18) - Druids Table I (p.
      17): the expanded ladder to 23rd
      (Hierophant of the Cabal), the
      15th-23rd special abilities, the
      bonus spell levels, the elemental
      conjuring tables (the fire/earth/
      water/air dice rows).
      - CLOSED R330: the pin round
      (rules/hierophant.h): the
      hierarchy (Great Druid 14th,
      Grand Druid 15th with the
      9 attendants and the 6
      bonus spell levels, the 3
      Archdruids), the abdication
      (500,000 more, xp resets
      to 1), the Table I ladder
      (the band lows, the
      titles, the 15+N hp
      formula), the spell
      abilities, the 16th-level
      powers, the plane-entry
      and conjure ladders, the
      five conjuring tables, the
      desire override; the earth
      01-85 HD cell and the L21
      title cell are OCR-lost
      (documented in-header;
      revisit with the PDF);
      the R330 audit (census
      257).
- [ ] **Weapon specialization** (pp.
      18-19) - fighter and ranger only,
      chosen at creation; the slot costs
      (2 slots melee; a bow costs a
      third); melee +1 to hit/+2 damage;
      **the Weapon Specialization Table**
      (the attacks per round by level
      band for melee, bow, light and
      heavy crossbow, lasso and staff
      sling, thrown dagger and dart,
      other missiles); the bow point
      blank (6-30, +2 and double damage,
      the nocked-arrow pre-initiative
      shot, short range +1); the
      crossbow point blank (6-60, the
      aimed shot); the double
      specialization (+3/+3, melee only,
      no pole arms or two-handed sword);
      the bonuses are not magical.
      - R331: the prose pinned
      (rules/weaponspec.h) - the
      class gate, the slot costs,
      the melee/bow/crossbow
      reads, the double, the table
      structure with the cleanly
      readable cells; the
      table's fraction cells are
      OCR-mangled (no consistent
      decode) - stays open pending
      the PDF read.
- [x] **The barbarian** (pp. 18-21) -
      the ability requirements and the
      wisdom maximum; **Barbarians Table
      I** (p. 19: d12, 11 levels, +4 hp
      after 8th, 500000 xp per level past
      11th); the magic detestation (no
      magic items used at low level, the
      XP award for destroying them, the
      shaman-cleric exception); the
      natural attack progression (hits
      +1-required creatures at 4th, +2
      at 6th, +3 at 8th, +4 at 10th, +5
      at 12th); the saves (+4 poison, +3
      paralyzation and death and
      petrification and polymorph, +2
      rod/staff/wand and breath, +1 per
      four levels versus spell); the
      primary abilities (climb as a
      thief; hide in familiar natural
      surroundings as a thief 3 levels
      higher; the magic detection bands,
      5 percent per level, 90 cap, the
      illusion-only second detection;
      the leadership read on other
      barbarians); the secondary
      abilities (survival, first aid
      with the 2x healing and the 10
      percent cure, outdoor craft as a
      3rd-level druid, outdoor tracking
      as a ranger); the tertiary skills
      (animal handling, horsemanship,
      long-distance signaling, running,
      small craft paddled and rowed,
      sound imitation, snare building).
      - CLOSED R332: the pin round
      (rules/barbarian.h) - the
      requirements and the wisdom
      maximum, Barbarians Table I, the
      magic detestation, the natural
      attack progression, the saves,
      the primary/secondary/tertiary
      ability ladders. The
      running-leap formula and the
      detestation award tail are OCR
      holes (documented in-header).
      The horde and the level-actions
      summary ride their own rounds.
- [x] **The ranger expansion** (pp.
      21-22) - the tracking rules, the
      giant-class combat bonus, the
      spell progression (druidic from
      8th to 3rd-level spells, MU from
      9th to 2nd-level spells).
      - CLOSED R333: the pin round
      (rules/uaranger.h) - the
      tracking base and terrain
      ladders, the indoor reads, the
      identification ladder, the
      giant-class roster expansion
      11 -> 22 (gnoll decoded from
      the garbled cell). The spell
      progression cross-checked
      against the landed R327/R184
      pins (the UA prose is
      OCR-lost). The ranger weapons
      rules ride a later round.
- [ ] **Thieves Table II** (p. 22) -
      the armor-effects penalties on
      thieving functions (non-leather
      armor, the elfin chain read); the
      **Attacks Per Melee Round Table**
      (p. 22) pairs with it.
      - R334: the fragment-verified
      cells pinned (rules/thiefarmor.h)
      - the armor columns, the eight
      functions, the sign-carries-
      column decode, the footnotes,
      the attacks classes, band edges
      and verified rates; the Open
      Locks cells, the missing
      no-armor cells, the attacks
      high-band rate and the
      footnote-1 tail are OCR-lost -
      stays open pending the PDF read.
- [x] **The thief-acrobat** (pp. 23-25)
      - the split class at 6th (the
      5th-level thief may convert); the
      **Function Table** (p. 24, reads
      clean: tightrope, pole vault, high
      jump, standing and running broad
      jump, the tumbling attack/evasion/
      falling percentages by level with
      the racial adjustments); **Table
      I** (p. 23, the conversion
      requirements) and **Tables II-IV**
      (p. 25, the pole vault and
      tightrope specifics); the jump and
      extension rules (the 2-5 foot
      extensions with the failure and
      recovery bands); the evasion 60
      percent cap.
      - CLOSED R335: the pin round
        (rules/acrobat.h) - the split
        class at 6th, the Function
        Table columns (the tumbling
        attack and evasion ladders
        pinned cell-by-cell, the
        falling column pinned where
        OCR survives), the tightrope
        walk, the pole vault and high
        jump bands, the broad jump and
        extensions, the footnotes, the
        Table III dex bonuses. The
        vault/jump distance cells, the
        racial adjustments row, Table II
        and Table IV stay open pending
        the PDF read.
- [x] **Money for cavaliers** (p. 25) -
      the starting gear by social class.
      - CLOSED R336: the pin round
        (rules/cavmoney.h) - the six
        stations in social-ladder
        order, the gold ranges, the
        printed formulas verified
        times-ten against the printed
        ranges and the R190 seam, the
        equipment lists item-by-item
        as printed, the tack and
        esquire prose. The paladin
        exception noted at DMG
        pp. 88-89 but not detailed -
        a hole pending the PDF read.

### Equipping the character (pp. 25-28)

- [ ] **The Armor Class Table** (p. 26)
      - the expanded AC-by-armor table.
- [ ] **The Equipment and Supplies
      Costs table** (p. 26).
- [ ] **Weapons, Weight and Damage by
      Type** (p. 26).
      - R337: the fragment-verified
      cells pinned (rules/uaweapontable.h)
      - the 67-row roster, all 50 PHB
      rows cell-verified against the
      R189 seam (the hyphen-loss
      pattern proven row by row),
      the 17 new-weapon rows pinned
      where printed or
      pattern-decoded, the merged
      rows split by seam; the
      atlatl/harpoon/falchion
      weights, the lasso damage
      and the unattributable
      garbled quarrel row are
      OCR-lost - stays open
      pending the PDF read.
- [ ] **Weapons, hand-held, general
      data and to-hit adjustments** (p.
      27) - the speed factors, the
      size-class damage, the strength
      adjustment rows.
- [ ] **Weapons, hurled and missile,
      general data** (p. 28).
      - R338: the fragment-verified
      cells pinned (rules/uamissile.h)
      - the 24-row roster, the range
      column (the long range in tens
      of feet, PHB-seam verified),
      the AC-adjustment ladders
      minus-loss decoded (the
      pattern seam-proven on the
      bow, crossbow and sling rows
      against the R145 rows); the
      rate column, the S/M range
      cells and the tail AC cells
      of the short rows are
      OCR-lost - stays open
      pending the PDF read.
- [x] **The Weapon Proficiency Table**
      (p. 26) - pairs with the R299
      layer.
      - CLOSED R339: the pin round
        (rules/uaprof.h) - the 14-row
        roster, seven rows cell-verified
        against the R297 PHB seam, the
        UA-new rows (cavalier, barbarian,
        acrobat, bard), the attributed
        fragment rows (illusionist, thief,
        assassin), the paladin and ranger
        deviations pinned as printed. The
        cavalier penalty, the paladin and
        assassin initials and the
        facing-page notes are OCR-lost -
        noted pending the PDF read.
- [ ] **The new weapons** (pp. 26-28
      and DM pp. 77-79) - the aklys,
      atlatl, blowgun, caltrop, garrot,
      harpoon, hook fauchard, khopesh,
      lasso, man catcher, sap, spiked
      buckler, staff sling, whip (14
      named types, each with its own
      data row).
      - R340: the fragment-verified
        prose pinned
        (rules/uanewweapons.h) - the
        16 printed descriptions (the
        14 item-named types plus the
        hand-crossbow and falchion
        prose), the khopesh slash-loss
        and whip 3d6 decodes; the
        harpoon failure die, the
        hand-crossbow poison
        sentence, the lasso severing
        mechanics, the caltrop
        trigger and the khopesh
        leverage sentence are
        OCR-lost, and the DM pp.
        77-79 half is DMG material
        absent from the UA extract -
        stays open pending the
        PDF/DMG read.

### Character spells (pp. 28-73)

- [x] **The spell tables** (pp. 28-31) -
      clerics 28-29, druids 29,
      magic-users 30-31, illusionists 31;
      the cantrip columns are the first
      spell-table appearance of the new
      tier; reads clean; the R80 registry
      is data-driven.
      - R341: the readable tables
        pinned (rules/uaspelltables.h)
        - the cleric 1st-3rd table
        (20 rows, seam-verified against
        the R80 registry), the cleric
        4th-7th fragments, the druid
        tables (the four readable rows
        seam-decoded as the 1st-level
        roster, the Insect P| fragment
        seam-decoded as Insect Plague)
        and the MU cantrip table (64
        names, the Gather/Polish merge
        decoded); the MU spells tables
        and the illusionist spell table
        are OCR-scrambled - stays open
        pending the PDF read.
      - CLOSED R342: part 2 pinned
        (rules/uaspelltables2.h) - the
        MU 1st-5th columns
        (35/30/28/28/28 readable names,
        every garble position-decoded),
        the MU 7th-9th continued table
        (7/11/2) and the illusionist
        table (5/4/1). The 6th column,
        the fragment cells, the
        illusionist cantrip and
        3rd-6th columns are OCR-lost -
        noted pending the PDF read.
- [x] **The new cleric spells** (pp.
      32-42) - one item per level: 1st
      (p. 33-35: endure cold/heat,
      invisibility to undead, magic
      stone, penetrate disguise, portent,
      precipitation), 2nd (p. 35-36:
      aid, detect life, dust devil,
      enthrall, holy symbol, messenger,
      withdraw, wyvern watch), 3rd (p.
      36-38: cloudburst, deaths door,
      flame walk, magical vestment, meld
      into stone, negative plane
      protection, remove paralysis,
      water walk), 4th (p. 38-39: abjure,
      cloak of fear, giant insect, imbue
      with spell ability, spell immunity,
      spike growth), 5th (p. 40-41: air
      walk, animate dead monsters,
      golem, magic font, rainbow), 6th
      (p. 41), 7th (p. 42: exaction,
      succor).
      - R343: the 1st level pinned
        (rules/uaclericspells1.h) - the
        eight spell descriptions with the
        digit-garble family (the four
        "Level: 7" cells) decoded, the
        ceremony variety ladder, the
        portent 1d12/1d6 mechanics and
        the magic stone ladder; the R341
        table hole at row 13 decodes as
        portent; the 2nd-7th levels stay
        open.
      - R344: the 2nd level pinned
        (rules/uaclericspells2.h) -
        aid, detect life, dust
        devil, enthrall, holy
        symbol, messenger, withdraw
        (the segments = level + 1
        formula) and wyvern watch;
        the digit-garble family
        decodes the five 7s as 1;
        the R341 table hole at row
        18 (the "draw" fragment)
        decodes as withdraw; the
        aid casting-time and
        components cells and the
        messenger range cell are
        OCR holes - noted pending
        the PDF; the 3rd-7th levels
        stay open.
      - R345: the 3rd level pinned
        (rules/uaclericspells3.h) -
        cloudburst, death's door,
        flame walk, magical
        vestment, meld into stone,
        negative plane
        protection, remove
        paralysis and water walk;
        the digit-garble family
        decodes the six 7s as 1
        (the negative plane
        protection duration is
        corroborated by its clean
        prose); the R341
        3rd-level column is fully
        readable - no hole decode
        this round; the cloudburst
        range cell, the flame walk
        lead sentence and the
        water walk casting-time
        numeral are OCR holes -
        noted pending the PDF; the
        4th-7th levels stay open.
      - R346: the 4th level pinned
        (rules/uaclericspells4.h) -
        abjure, cloak of fear,
        giant insect (the count
        and hit-dice ladders),
        imbue with spell ability,
        spell immunity and spike
        growth; the digit-garble
        family decodes the five
        7s as 1 (the cloak
        duration corroborated by
        its clean prose; the spike
        growth casting and
        duration decodes stay
        verbatim with doubt); the
        R341 continued table
        prints only fragments for
        the 4th level - the six
        names pin from the prose;
        the abjure range cell and
        the spike growth Level
        cell are OCR holes -
        noted pending the PDF; the
        5th-7th levels stay open.
      - R347: the 5th level pinned
        (rules/uaclericspells5.h) -
        air walk, animate dead
        monsters, golem (the four
        material ladders), magic
        font, rainbow (the four
        applications, the seven
        colors and draughts) and
        spike stones (the prose
        prints in the cleric
        chapter; the druid item
        seam-checks here); the
        digit-garble family decodes
        the three stat-cell 7s as
        1; the rainbow 7-missiles
        and the golem 7-foot
        ceiling stay genuine; the
        R341 table prints seven
        fragments - magic font
        seam-checks; the animate
        dead monsters and rainbow
        Range cells and the straw
        golem SD decode are OCR
        holes - noted pending the
        PDF; the 6th-7th levels
        stay open.
      - R348: the 6th level pinned
        (rules/uaclericspells6.h) -
        forbiddance (the name header
        never prints - identified by
        the 2e descendant text) and
        heroes feast (the twelve-hour
        benefits); the family decodes
        the two 7s as 1 (both
        corroborated); the R341 table
        prints four fragments - neither
        name seam-checks; the name
        header and the two prose
        fragment regions are OCR
        holes - noted pending the PDF;
        the 7th level stays open.
      - R349: the 7th level pinned
        (rules/uaclericspells7.h) -
        exaction (the duty or quest
        with the alignment gates and
        the bargain consequences) and
        succor (the prepared-object
        dweomer with the summons
        reverse); the family decodes
        the two 7s as 1; the exaction
        range position-decodes from
        the interleave; the R341
        7th-level column prints no
        fragments - both names pin
        from the prose; the opener
        word, the creature-example
        garble and the two prose
        shatters are OCR holes -
        noted pending the PDF.
      - CLOSED R349: the item closed -
        all seven levels pinned
        (R343-R348 plus this round).
- [x] **The new druid spells** (pp.
      42-45) - 1st (ceremony, detect
      balance, detect poison,
      precipitation), 2nd (flame blade,
      goodberry, reflecting pool, slow
      poison), 3rd (cloudburst, know
      alignment, spike growth,
      starshine), 5th (moonbeam, spike
      stones), 6th (liveoak, transmute
      water to dust), 7th (changestaff).
      - R350: the 1st level pinned
        (rules/uadruidspells1.h) - the
        four spell descriptions
        (ceremony with the nine
        varieties and the cast-out
        permission ladder, detect
        balance, detect poison with
        the yew leaf, precipitation
        with the name header lost -
        identified via the R343
        clerical pin); the family
        decodes the three 7s as 1
        (detect balance prints the
        clean 1); the R341 druid
        table prints the four PHB
        names - none of the new
        names seam-checks; the 2nd
        through 7th levels stay open.
      - R351: the 2nd level pinned
        (rules/uadruidspells2.h) - the
        four spell descriptions
        (flame blade with the undead
        and fire damage modifiers,
        goodberry with the name
        header lost, the reflecting
        pool behind the "Pool ion -"
        name garble with the
        scrying mechanics, slow
        poison with the herbal
        antidote chance); the family
        decodes the three 7s as 1
        (flame blade prints the
        clean 2); the R341 druid
        table prints no 2nd-level
        roster - all four names pin
        from the prose; the 3rd
        through 7th levels stay open.
      - R352: the 3rd level pinned
        (rules/uadruidspells3.h) - the
        four spell descriptions
        (cloudburst with the stat-
        block interleave and the
        call lightning exclusion,
        know alignment with the
        five-creature cap and the
        no-reverse gate, spike
        growth with the material
        interleave, starshine with
        the school tail lost); the
        family decodes the 7 as 1
        and the cloudburst
        duration decodes from the
        "1 ro" + "vol" fragments;
        starshine seam-checks
        against the R351 reflecting
        pool pin; the R341 druid
        table prints no 3rd-level
        roster - all four names pin
        from the prose; the 5th
        through 7th levels stay open
        (the UA prints no 4th-level
        druid section).
      - R353: the 5th level pinned
        (rules/uadruidspells5.h) - the
        two spell descriptions (moonbeam
        with the movable spotlight beam
        and the color and vision
        effects, spike stones identical
        to the clerical); the family
        decodes the 7 as 1 (moonbeam
        prints the clean 5); the spike
        stones stat cells seam-check
        against the R347 clerical pin
        (the school cell prints
        Enhancement where the clerical
        reads Enchantment - flagged; the
        casting time cell lost); the R341
        druid 5th table prints six PHB
        names - neither new name
        seam-checks there; the 6th and
        7th levels stay open.
      - R354: the 6th level pinned
        (rules/uadruidspells6.h) - the
        two spell descriptions (liveoak
        with the triggered treant and
        the 3-inch movement decode,
        water to dust behind the name
        garble with the muddy
        multipliers and the
        water-native save gate); the
        family decodes the 7 as 1
        (water to dust prints the
        clean 6 and 8); the R341 druid
        6th table prints five PHB
        names - neither new name
        seam-checks there; the 7th
        level stays open.
      - R355: the 7th level pinned
        (rules/uadruidspells7.h) -
        the two spell descriptions
        (changestaff behind the
        lost name header with the
        hit-die ladder and the
        wish-only recovery, sunray
        with the blindness tiers
        and the undead damage
        split); the family decodes
        the 7 round as 1; the item
        header lists only
        changestaff - the section
        prints two spells, sunray
        joins the pin; the R341
        table pins stop at the
        druid 6th - no 7th table
        seam exists; the item
        closes.
      - CLOSED R355: the item
        closed - all printed
        levels pinned (R350-R354
        plus this round).
- [x] **The new magic-user spells**
      (pp. 51-66) - one item per level:
      1st (alarm, armor, firewater,
      grease, melt, mount, precipitation,
      run, taunt, wizard mark), 2nd
      (bind, deeppockets, flaming
      sphere, irritation, know
      alignment, the Melf acid arrow,
      preserve, protection from
      cantrips, the Tasha laughter,
      vocalize, whip, zephyr), 3rd
      (cloudburst, detect illusion, item,
      material, the Melf minute meteors,
      secret page, sepia snake sigil,
      wind wall), 4th (dispel illusion,
      the Evard tentacles, the Leomund
      secure shelter, magic mirror, the
      Otiluke resilient sphere, shout,
      stoneskin, ultravision), 5th
      (avoidance, dismissal, dolor,
      fabricate, the Leomund
      belabourment, sending), 6th (chain
      lightning, contingency,
      ensnarement, eyebite, the
      Mordenkainen lucubration,
      transmute water to dust), 7th
      (banishment, forcecage, the
      Mordenkainen magnificent mansion,
      sequester, teleport without error,
      torment, truename, volley), 8th
      (binding, demand, the Otiluke
      telekinetic sphere, sink), 9th
      (crystalbrittle, energy drain, the
      Mordenkainen disjunction, succor).
      - R356: the 1st level pinned
        (rules/uamuspells1.h) - the
        ten spell descriptions
        (alarm with the lost range
        and door-value cells, armor,
        firewater, grease, melt
        behind the run interleave,
        mount with the level ladder,
        precipitation seam-checking
        the R343 clerical pin minus
        the holy symbol, run, taunt
        behind the scrambled opener,
        wizard mark); the family
        decodes the seven level-cell
        and casting-time 7s as 1
        (mount, run and taunt print
        the clean 1); the R341
        tables pin only cantrip
        ranges - no 1st-level MU
        table seam exists; the 2nd
        through 9th levels stay
        open.
      - R357: the 2nd level pinned
        (rules/uamuspells2.h) - the
        twelve spell descriptions
        (bind, deeppockets behind
        the lost name header,
        flaming sphere, irritation
        with the two versions, know
        alignment reversible behind
        the lost range cell, the
        Melf acid arrow, preserve
        behind the lost area number,
        protection from cantrips
        behind the From Cantrips
        header garble, the Tasha
        laughter with the
        intelligence save ladder,
        vocalize, whip behind the
        lost level cell, zephyr);
        the family decodes the
        casting-time and duration
        7s as 1; the R342 MU table
        seam: eight of the twelve
        names print there, the four
        absent are noted; the 3rd
        through 9th levels stay
        open.
      - R358: the 3rd level pinned
        (rules/uamuspells3.h) - the
        eight spell descriptions
        (cloudburst seam-checking
        the R352 druid pin minus
        the holy symbol, with the 3
        diam. print flagged against
        the druid 4; detect
        illusion behind the lost
        name tail and area length;
        item; material behind the
        degree range; the Melf
        minute meteors behind the
        empty range and the sepia
        interleave; secret page
        behind the 4th-heading
        interleave; the sepia snake
        sigil behind the lost
        casting-time head; wind
        wall behind the truncated
        components cell); the family
        decodes the 7s as 1; the
        R342 MU table seam: four of
        the eight names print
        there, the four absent are
        noted; the 4th through 9th
        levels stay open.
      - R359: the 4th level pinned
        (rules/uamuspells4.h) - the
        eight spell descriptions
        (dispel illusion behind the
        lost name tail and the
        garbled half-inch range,
        the Evard black tentacles
        behind the lost level and
        range cells with the stray
        gf line, the Leomund
        secure shelter with the
        scrambled wind sentence,
        magic mirror with the
        scrambled component list,
        the Otiluke resilient
        sphere with the lost globe
        sentence, shout with the
        scrambled area tail,
        stoneskin behind the lost
        level and range cells,
        ultravision with the tail
        past the 5th heading); the
        family decodes the 7s as 1;
        the R342 MU table seam:
        seven of the eight names
        print there, the Dispel
        fragment cell reads as a
        hole; the 5th through 9th
        levels stay open.
      - R360: the 5th and 6th levels
        pinned (rules/uamuspells5.h
        and rules/uamuspells6.h) - the
        six 5th-level descriptions
        (avoidance behind the lost
        name header, dismissal behind
        the belabourment interleave,
        dolor with the range as
        printed, fabricate, the Leomund
        belabourment behind the lost
        name header, sending) and the
        six 6th-level descriptions
        (chain lightning behind the
        truncated range tail and the
        garbled save fraction,
        contingency behind the lost
        casting cells, ensnarement
        behind the lost name header,
        eyebite behind the garbled
        school tail, the Mordenkainen
        lucubration behind the lost
        name header, transmute water
        to dust seam-checking the
        druid pin minus the mistletoe
        with the 6-segment print
        flagged against the druid 8);
        the family decodes the casting
        and duration 7s as 1 with the
        range 7s staying as printed;
        the R342 MU table seam prints
        four of the 5th-level names,
        avoidance and dolor absent,
        and the 6th-level column is
        wholly lost; the 7th through
        9th levels stay open.
      - R361: the 7th level pinned
        (rules/uamuspells7.h) - the
        eight spell descriptions
        (banishment with the
        scrambled stat head and
        the range interleaved,
        forcecage with the stat
        tail interleaved and the
        gap fraction garbled, the
        Mordenkainen magnificent
        mansion behind the garbled
        name header with the level
        cell lost, sequester behind
        the lost name header,
        teleport without error with
        the stat cells scrambled,
        torment with the range cell
        lost and the save ladder
        pinned, truename with the
        stat tail interleaved and
        the save fragment
        unattributed, volley with
        the Explanation line lost
        and the stat cells holes,
        the volley and truename
        sections printing past the
        8th-level table page); the
        family decodes the casting
        and duration 7s as 1; the
        R342 MU table seam prints
        only the seven PHB
        fragments, none of the new
        names seam-checks; the 8th
        and 9th levels stay open.
      - R362: the 8th and 9th levels
        pinned (rules/uamuspells8.h
        and rules/uamuspells9.h) - the
        four 8th-level descriptions
        (binding with the lost range
        and duration cells and the six
        forms with the save ladder,
        demand behind the garbled
        components cell, the Otiluke
        telekinetic sphere behind the
        garbled name header with the
        lost range cell, sink with the
        lost level cell and the
        sinking ladder) and the four
        9th-level descriptions
        (crystalbrittle with the item
        save ladder, succor with the
        interleaved stat tail, energy
        drain with the displaced casting
        cell, the Mordenkainen
        disjunction behind the garbled
        name header with the artifact
        chances); the R342 MU table
        seam checks demand at index 0
        and sink at index 8 with
        binding and the sphere absent,
        and only the two PHB 9th names
        print; the item closes.
      - CLOSED R362: the item closed
        - all printed levels pinned
        (R356-R361 plus this round).
- [x] **The new illusionist spells**
      (pp. 66-73) - the cantrips are
      their own category (below); 1st:
      the chromatic orb (p. 66-67,
      with the color-by-level ladder);
      2nd (alter self, delude,
      fascinate, phantom armor, read
      illusionist magic, spook,
      wraithform); 4th (dispel magic,
      rainbow pattern, solid fog,
      vacancy); 5th (advanced illusion,
      dream, magic mirror, tempus
      fugit); 6th (death fog, mislead,
      phantasmagoria); 7th (mirage
      arcane, shadow walk, weird). The
      3rd level adds nothing new per
      the headers - the round that
      charges verifies against the
      spell table (p. 31) first.
      - R363: the cantrips and the
        1st and 2nd levels pinned
        (rules/uailcantrips.h,
        rules/uailspells1.h and
        rules/uailspells2.h) - the
        eight cantrip descriptions,
        the chromatic orb with the
        color-by-level ladder,
        phantom armor, read magic,
        spook, alter self and
        fascinate plus the
        ultravision and wind
        reprints; the print places
        phantom armor at 1st (a
        clean Level: 1 cell) and
        carries delude and
        wraithform in the third-
        level section - the
        divergence from the item
        list flagged pending the
        PDF; the R342 IL table seam
        prints only PHB names in
        the readable columns, none
        of the new names seam-
        checks; the 3rd through 7th
        levels stay open.
      - R364: the 3rd, 4th and 5th
        levels pinned
        (rules/uailspells3.h,
        rules/uailspells4.h and
        rules/uailspells5.h) - delude
        and wraithform pinned at the
        printed 3rd (the Level: 3
        cells; the item-list 2nd
        divergence stands, pending
        the PDF); phantom steed and
        phantom wind, absent from
        the item list, pinned as
        the print adds them under
        the Third Level Spells
        header; dispel magic,
        rainbow pattern, solid fog
        and vacancy at 4th (the
        vacancy Level: 4 cell
        matches the item list; the
        solid fog level cell lost,
        pinned from the section
        header); the advanced
        illusion named from the
        item list (the name header
        garbles), dream, magic
        mirror and tempus fugit at
        5th; the bare-7 cells read
        as holes pending the PDF;
        the R342 IL table 3rd-6th
        columns stay lost; the 6th
        and 7th levels pin in the
        next round.
      - CLOSED R365: the 6th and
        7th levels pinned
        (rules/uailspells6.h and
        rules/uailspells7.h) - death
        fog with the acid ladder,
        mislead with the invisibility
        cloak, phantasmagoria (the
        level cell lost, pinned from
        the section header), the
        mirage arcane at the printed
        6th (the item-list 7th
        divergence flagged pending
        the PDF), shadow walk with
        the plane reads and weird
        with the lost prose; all
        printed levels now pinned
        (R363-R365) - the item
        CLOSED; the acquisition
        rules and the cantrip tier
        seam ride their own items.

## Cantrips (a category of their own)

A NEW tier BELOW 1st level - kept as
its own top-level category, separate
from the spells, by standing decision.
The book treats them as spells in all
acquisition respects (read as spells,
recorded in books and scrolls as
spells) but they carry their own
categories, their own known-count
rules, their own book capacity, and a
dedicated protection spell (protection
from cantrips, MU 2nd). The R80 spell
registry has no tier slot for a
sub-1st level; a cantrip-tier seam is
the gateway charge.

- [ ] **The magic-user cantrips** (pp.
      30-31 headers, 45-52 descriptions)
      - six categories: useful (20
      named: chill, clean, color,
      dampen, dry, dust, exterminate,
      flavor, freshen, gather, polish,
      salt, shine, spice, sprout,
      stitch, sweeten, tie, warm, wrap;
      one known per point of
      intelligence, free choice);
      reversed (12 named: curdle, dirty,
      dusty, hairy, knot, ravel, sour,
      spill, tangle, tarnish, untie,
      wilt; 2-8 known); legerdemain (6
      named: change, distract, hide,
      mute, palm, present; 2-5 known);
      person-affecting (10 named:
      belch, blink, cough, giggle, nod,
      scratch, sneeze, twitch, wink,
      yawn; 2-8 known); personal (10
      named: bee, bluelight, bug,
      firefinger, gnats, mouse,
      smokepuff, spider, tweak, unlock;
      2-8 known); haunting-sound (8
      named: creak, footfall, groan,
      moan, rattle, tap, thump,
      whistle; 2-5 known). The casting
      rules (the segment costs, the
      verbal/somatic color) ride the
      descriptions.
- [ ] **The illusionist cantrips** (pp.
      65-66) - the minor-illusion
      category: colored lights, dim,
      haze, mask, mirage, noise, rainbow
      (7 named).
      - R363: the eight cantrip
        descriptions pinned
        (rules/uailcantrips.h) -
        colored lights with the
        globe ladder, dim with the
        half-radiance round, haze
        with the missile and save
        adjustments, mask, mirage,
        noise, rainbow, and the
        eighth the print adds
        behind the item list (the
        two-d illusion); the
        casting-time cells print
        fraction garbles - holes
        pending the PDF; the box
        stays open on the cantrip
        tier seam (the registry
        charge), the descriptions
        are pinned.
- [ ] **The cantrip acquisition rules**
      (DM pp. 79-80) - cross-ref to the
      DM section item; the apprentice
      may develop at most 3 new
      cantrips.

## Dungeon masters section (pp. 73-105)

### Creating the player character (pp. 74-75)

- [x] **Method V** (p. 74) - the
      class-first generation, humans
      only; the dice-count table (the
      9d6 fighter strength, the Com
      column) reads clean; the minimum
      and maximum clamps.
      - CLOSED R370: the pin round
        (rules/uasmalls1.h) - the
        class-first humans-only
        prose, the best-three-of-N
        roll with the DM approval,
        the minimum and maximum
        clamps and the 9d6 fighter
        strength example pin clean;
        the dice-count table cells
        extract empty - the cell
        body a hole in-header
        pending the PDF; CLOSED.
- [x] **Starting hit-point minimums**
      (p. 74) - cavalier 6, paladin 6,
      cleric 5, druid 5, fighter 6,
      barbarian 7, ranger 9, magic-user
      3, illusionist 3, thief 4,
      assassin 4, monk 5.
      - CLOSED R370: the pin round
        (rules/uasmalls1.h) - the 12
        class minimums (cavalier 6
        to ranger 9), the
        multi-class average rounded
        up with the fighter/magic-
        user 5 example, the
        constitution adjustment
        with the con-17 fighter 9
        example; the R368 seam
        cross-checks the cavalier
        d10 floor; CLOSED.
- [x] **The comeliness creation note**
      (p. 74) - the DM pointer; rides
      the R322 pins.
      - CLOSED R373: the pin round
        (rules/uacomnote.h) - the DM
        pointer to pages 6 and 7, the
        characteristic read, the
        effects on viewers and
        reactors; the R322 seam
        cross-checks the creation
        roll and the charisma
        ladder; the trailing
        sentence garbles - flagged;
        CLOSED.

### Character classes (pp. 74-75)

- [x] **The cavalier follower tables**
      (p. 74) - the men-at-arms dice per
      level (1-4 at 4th through 48-192
      at 10th, non-cumulative, no gain
      if the roll is not higher); the
      equipment percentile rows; the
      leader rules (a 5th-level fighter
      per 20 troops, a 6th per 60, the
      3rd-level lieutenant); the
      neutral and evil follower rules;
      the 1 percent per level monster
      follower.
      - CLOSED R372: the pin round
        (rules/uafollowers.h) - the
        dice ladder (all d4, the
        min-count max-times-four
        invariant), the four
        equipment percentile rows
        with both outfits each, the
        leader and lieutenant
        rules, the neutral-cause
        and evil-bandit reads, the
        1 and 5 percent monster
        chances; the R371 seam
        cross-checks the armor
        costs; CLOSED.
- [x] **The henchman rules** (p. 75) -
      the charisma +3 (good) or +1
      (else) bonus; the alignment-based
      henchman-type table; the retainer
      ladder (Armigers/Scutifers at 4th,
      the Esquire at 6th, the Horseman
      herald and Lancer guard at 7th,
      the extra man-at-arms at 8th); the
      paladin retainer rules.
      - CLOSED R372: the pin round
        (rules/uafollowers.h) - the
        +3/+1 henchman bonus, the
        alignment type table (the
        paladin, thief and assassin
        cells), the retainer ladder
        (the prose Knight at 6th
        flagged against the R368
        grid's Knight at 5th), the
        care-and-upkeep service, the
        paladin cavalier-only
        retainers; the R368 seam
        cross-checks the title
        cells; CLOSED.

### Armor, armor class and weapons (pp. 75-79)

- [x] **The expanded armor table** (p.
      75) - reads clean: banded 90 gp,
      bronze plate 100 gp, field plate
      2000 gp, full plate 4000 gp, the
      bulk and movement columns, the
      shield rows, elfin chain never
      sold.
      - CLOSED R371: the pin round
        (rules/uaarmor.h) - the
        banded, bronze plate, field
        plate, full plate, ring,
        scale, splint and studded
        leather rows (the costs,
        weights, movements and bulk
        flags) and the three shield
        rows pin clean; the elfin
        chain cost cell garbles -
        which confirms the clean
        never-sold footnote; the
        R191 seam cross-checks the
        plate AC ladder; CLOSED.
- [x] **The new armor descriptions**
      (pp. 75-76) - bronze plate (AC 4,
      +2 rear-attack exposure, rust
      immunity), elfin chain (thief-
      wearable), field plate (the 1
      point per die absorption, the 12
      point cap, the repair costs),
      full plate.
      - CLOSED R371: the pin round
        (rules/uaarmor.h) - the four
        descriptions pin clean: the
        bronze plate AC 4 with the
        +2 rear bonus and the rust
        immunity, the elfin chain
        thief-wearable read, the
        field plate absorption with
        the cap and the repair
        costs, the full plate
        construction; the R334 seam
        cross-checks the elfin
        chain thief rows and the
        R370 seam the barding
        weight read; CLOSED.
- [x] **Warhorses and barding** (p. 76)
      - the barded movement rate table.
      - CLOSED R370: the pin round
        (rules/uasmalls1.h) - the
        movement rate table (light
        21/15, medium 17/15, heavy
        14/13/12) with the medium
        scale and heavy leather
        cells lost (flagged), the
        endurance rule, the
        magical barding costs and
        percentages, the flying and
        aquatic steeds rules; the
        percentage sums
        cross-check; CLOSED.
- [x] **The new weapon descriptions**
      (pp. 77-79) - the 14 named types
      (see the players section item);
      the pole-arm cross-refs point to
      Appendix T.
      - CLOSED R373: rides the R340
        pins (rules/uanewweapons.h) -
        the 16-entry roster with the
        14 item-list types marked; the
        R337 seam cross-checks the
        pole-arm rows (the hook
        fauchard, the man catcher,
        the lasso, the harpoon); the
        residual OCR holes (the
        harpoon failure-damage cell,
        the khopesh leverage
        sentence, the lasso severing
        mechanics) await the PDF -
        flagged; CLOSED.

### Character spells (pp. 79-83)

- [x] **Cantrip acquisition, MU** (p.
      79) - the known-count rules (the
      useful-per-intelligence read; the
      2-8/2-5 random counts; the 3
      developed cantrips cap).
      - CLOSED R369: the pin round
        (rules/uacantacq.h) - the five
        random bands (reversed 2-8,
        legerdemain 2-5, person-
        affecting 2-8, personal 2-8,
        haunting-sound 2-5) and the 3
        developed cap with the DM
        review and the spell-procedure
        notes pin clean; the useful one
        per point of intelligence by
        free choice is decoded from the
        garbled sentence (flagged
        pending the PDF); the R365 seam
        cross-checks the illusionist
        bands (the documented
        divergence), the R366 seam the
        book counts; CLOSED.
- [x] **The spell book rules** (pp.
      79-80) - the standard book
      capacities (36 cantrips, 24 spells
      of 1st-3rd, 16 of 4th-6th, 8 of
      7th-9th), the travelling book
      (9/6/4/2), the costs (1000 gp plus
      100 gp per spell level, cantrips
      as 1st; travelling 500 gp), the
      4-7 week composition, the physical
      aspects (the size, the 150 gp
      weight, the 450 gp encumbrance,
      the leather-book saves with +2).
      - CLOSED R366: the pin round
        (rules/uaspellbooks.h) - the
        capacities with the one-fourth
        travelling read, the costs with
        the master-borne start, the
        composition weeks, the physical
        aspects with the +2 saves, the
        values, the direct-casting
        destroys and the learning
        hours; the section opening, the
        encumbrance cell and the
        travelling thickness/weight
        cells garble - holes
        in-header, revisit with the PDF.
- [ ] **Illusionist spell acquisition**
      (p. 80) - the starting list table;
      the illusionist book differences.
      - R365: the fragment-verified
        cells pinned
        (rules/uailacquisition.h) -
        the three-group start, the
        five defensive rows, the
        misc fragments, the DM
        three-option note, the book
        differences (24/16/8 and 6/4/2
        with the MU first-level
        book), the illusionist cantrip
        counts; the offensive/misc row
        boundaries garble - stays
        open pending the PDF read.
- [x] **The cost of spell casting** (pp.
      80-81).
      - CLOSED R365: the pin round
        (rules/uaspellcost.h) - the
        200 gp per level basic fee with
        the doubled components, the
        10 percent/3x and 100
        percent/3x surcharges, the
        danger and aging clauses, the
        item-payment and hostile-caster
        reads; the section prints
        clean - CLOSED.
- [x] **The spell explanations - the
      referee commentary** (pp. 81-82) -
      the permanency list and the rest.
      - CLOSED R366: the pin round
        (rules/uaspellcomment.h) - the
        personal permanency list (the six
        detects and protections), the
        22-name object/area list, the 5
        percent vs 100 percent
        constitution-loss reads, the
        Serten's immunity commentary (the
        24 names with the +9/+7/+5
        bonuses - the band assignment
        detaches in the print, flagged
        pending the PDF); CLOSED.
- [x] **Underwater spell use** (pp.
      81-83) - the per-spell underwater
      reads (the salt cantrip, the
      firewater float, the acid arrow
      washout, the chain lightning
      change, the mansion option, the
      sink read, and the rest of the
      list).
      - CLOSED R366: the pin round
        (rules/uauwspelluse.h) - the
        cannot-use rosters (cleric,
        druid, magic-user, the
        illusionist fragment) with the
        airy-water footnote, the
        altered-effects reads (the water
        walk bob, the magic font globe,
        the transmute hole, the salt,
        firewater, acid arrow, chain
        lightning, mansion and sink, the
        hippocampus steed); the MU
        cantrip row and the MU/IL list
        boundary garble - flagged
        in-header, revisit with the PDF.
- [x] **The effects of darkness** (p.
      82) - the combat effects ladder.
      - CLOSED R366: the pin round
        (rules/uadarkness.h) - the -4
        unseen and -2 vague ladder, the
        illumination exception, the
        infravision converse with the
        sub-race cross-refs, the faerie
        fire conditions, the DM
        moderation closer; the section
        prints clean - CLOSED.

### The campaign (pp. 82-83)

- [x] **Social class and rank** (p. 82)
      - the Social Class Table; extends
      the R208 tables.
      - CLOSED R367: the pin round
        (rules/uasocialclass.h) - the
        nine-band dice ladder with the
        occupation rosters per band, the
        no-effect-on-starting-money note
        with the cavalier/paladin
        exception, the non-human
        placements, the one-rank-below
        profession rule; the LLC label
        cell garbles and the halfling
        ULC parenthetical divergence
        flagged pending the PDF; the
        R336 seam cross-checks the
        cavalier money stations.
- [x] **Circumstances of birth** (p.
      83) - the Birth Table (the
      12-child ladder), the Parents
      Marital Status Table (the
      one-class-lower read for the
      unmarried).
      - CLOSED R367: the pin round
        (rules/uabirth.h) - the 13-row
        birth ladder, the marital
        status split with the
        one-class-below-the-father
        read, the racial modifiers
        (the half-orc +10/+75 split);
        the section intro garbles and
        the high-elf sign cell lost -
        flagged in-header pending the
        PDF.

### Treasure (pp. 84-106) - THE DECISION

The UA random determination tables III.A
through III.H REPLACE the DMG tables. The
engine carries roughly seventy landed DMG
treasure audits (R219 through R287 and
neighbors). THE NAMED DECISION:
reconcile, reverse, or RUN BOTH. The
entertain-both read (the first-iteration
lesson): the engine can carry the DMG and
UA tables as switchable alternatives (a
DMG / UA / merged dial) and let
playtesting pick - and the monster file
format already tracks source per record,
so per-source data has a landed
precedent. The decision needs its own
round before any treasure charge lands.

DECIDED R374: RUN BOTH - the engine
      carries the DMG and UA tables as
      switchable alternatives behind a
      dial (rules/uatreasuredial.h):
      DMG (the default - the landed
      audits stay authoritative), UA,
      MERGED; playtesting picks; the
      per-source precedent rides the
      monster file format. The UA pin
      rounds follow - the dial lands
      first, the charge after.

- [ ] **The random determination
      tables** (pp. 84-89) - the
      revised III.A (potions), III.B
      (scrolls), III.C (rings), III.D
      (rods/staves/wands), III.E
      (miscellaneous magic, two
      sub-tables), III.F (armor and
      shield), III.G (swords), III.H
      (miscellaneous weapons); all read
      clean.
      - AMENDED R375: the skeleton
        pin round (rules/uadetskel.h)
        - the top-level bands and
        sub-table splits pin clean;
        the misc magic carries SEVEN
        visible sub-bands (not two -
        six named, the seventh
        garbles); the scroll
        footnotes pin (the 30 and 25
        and 10 percents, the DMG p.
        121 cross-ref); the row
        bodies of all eight tables
        OCR-scramble (dropped dice
        bands, orphaned value rows,
        merged columns) - the "all
        read clean" claim corrected;
        the item stays OPEN,
        PDF-gated.
- [ ] **The new potions** (p. 90).
      - AMENDED R376: the new
        potions prose part 1 pin
        round (rules/uapotprose.h)
        - TWELVE of the nineteen
        descriptions pin clean
        (the four elixirs of
        health, life, madness,
        youth; the potion of
        fire breath; the oils of
        fiery burning,
        fumbling, sharpness,
        timelessness; the
        potions of rainbow
        hues, ventriloquism,
        vitality); SEVEN
        descriptions
        OCR-scramble (acid
        resistance,
        disenchantment,
        elemental, impact,
        the philters of beauty
        and glibness,
        stammering) - the item
        stays OPEN, PDF-gated
        for the garbled
        remainder.
- [ ] **The new scrolls** (pp. 91-93).
      - AMENDED R377: the new
        scrolls protection prose
        pin round
        (rules/uaprotscr.h) -
        ELEVEN of the fifteen
        protection-scroll types
        pin clean (acid, breath
        weapons dragon and
        non-dragon, fire, gas,
        illusions,
        paralyzation, plants,
        poison, the traps trio
        at 50 percent mechanical
        / 30 magical / 20 any,
        water); FOUR types
        OCR-scramble (cold,
        electricity, the two
        weapons scrolls) - the
        item stays OPEN,
        PDF-gated for the
        garbled remainder.
- [ ] **The new rings** (pp. 92-94).
      - AMENDED R378: the new
        rings prose pin round
        (rules/uaringprose.h) -
        SIX of the thirteen
        new-ring descriptions
        pin clean (animal
        friendship, anything,
        blinking, jumping,
        mind shielding,
        truth); SEVEN
        descriptions
        OCR-scramble (boccob's
        save list, chameleon's
        detection tail,
        clumsiness' power
        table, faerie's
        fraction cells, ram's
        adjustment tail,
        shocking grasp's
        opening, sustenance's
        reattune) - the item
        stays OPEN, PDF-gated
        for the garbled
        remainder.
- [ ] **The new rods and staves** (pp.
      94-96).
      - AMENDED R379: the new
        rods and staves prose pin
        round (rules/uarodstave.h)
        - FOUR of the eleven
        new descriptions pin
        clean (the rod of
        alertness, the rod of
        security, the
        staff-mace, the staff
        of slinging); SEVEN
        descriptions
        OCR-scramble (flailing,
        passage, splendor,
        staff-spear, swarming
        insects, thunder and
        lightning, woodlands) -
        the item stays OPEN,
        PDF-gated for the
        garbled remainder.
- [ ] **The new wands** (pp. 96-97).
      - AMENDED R380: the new
        wands prose pin round
        (rules/uawandprose.h) -
        SEVEN of the twelve new
        wand types pin: FIVE
        fully clean (anything,
        fireballs, flame
        extinguishing, ice
        storms, lightning
        bolts) plus TWO
        mechanics-clean with
        flagged holes
        (defoliation's opening
        sentence, metal
        command's dropped
        verb); FIVE types
        OCR-scramble (buckler's
        activation sentence,
        earth and stone's
        charge mapping,
        force's third-function
        cost, size alteration's
        effect magnitude,
        steam and vapor's cone
        dimensions) - the item
        stays OPEN, PDF-gated
        for the garbled
        remainder.
- [ ] **The new miscellaneous magic
      items** (pp. 97-104) - the named
      additions: the Egg of Reason, the
      Girdle of Many Pouches, the
      Gloves of Missile Snaring, the
      Hat of Difference, the Heward
      haversack, the Horn of Fog, the
      Prison of Zagyg, the Quiver of
      Ehlonna, the Robe of Stars, the
      Scarab versus Golems, the Shadow
      Lanthorn, the Sheet of Smallness.
- [ ] **The new armor and shields and
      swords** (pp. 104-105) - the
      anything sword (the 3-form limit
      and the dweomer loss), the Final
      Word broadswords (the nine named,
      the +3 strikes-last read).
- [ ] **The new miscellaneous weapons**
      (pp. 105-106) - the Axe of
      Hurling (the return, the double
      hurled damage, the d20 bonus
      table, the 1500 XP and 15000 gp
      per plus) and the rest; the XP and
      GP value tables read clean.

### DM tables and charts (the manifest)

Every named table from the DM section
own index, one item each:

- [ ] Armor, Types and Encumbrance (p.
      75) - the armor table item above.
- [ ] Barded Warhorse Movement Rate (p.
      76).
- [ ] Birth Table (p. 83).
- [ ] Character Generation Method V (p.
      74).
- [ ] Clerical Quick Reference Chart,
      non-human deities (pp. 121-122) -
      rides the Appendix S OUT.
- [ ] Hit Points, Starting (p. 74).
- [ ] Illusionist Spells, Starting List
      (p. 80).
- [ ] Overbearing, Armor Class
      Adjustments (p. 108).
- [ ] Parents Marital Status Table (p.
      83).
- [ ] Pummeling Table, Chance of
      Stunning (p. 107).
- [ ] Social Class Table (p. 82).
- [ ] Treasure Table III: Magic Items
      (p. 84) - the umbrella table; the
      sub-tables are the III.A-III.H
      item above.

## Appendices (pp. 106-129)

- [ ] **Appendix Q: weaponless combat**
      (pp. 106-108) - the pummeling,
      wrestling and overbearing systems,
      the Pummeling Table and the
      Overbearing AC Adjustments;
      overlaps the R160 pin - reconcile
      before charging.
- [ ] **Appendix R: non-lethal combat**
      (pp. 109-110) - the subdual rules
      (the intelligence bands, the flat
      and butt requirement), the
      grappling and disarming systems,
      the vanquishing read, the footing
      AC.
- [ ] **Appendix S: non-human deities**
      (pp. 109-122) - DEFERRED on a
      deity layer: the demi-human
      pantheon prose, the clerical
      quick-reference charts. A deity
      layer is engineerable (the
      mission: everything includeable).
- [ ] **Appendix T: pole-arm
      nomenclature** (pp. 123-129) - the
      taxonomy (the bill hook, the
      fauchard-guisarme, the voulge, the
      pike, the axe family); a data
      charge that pairs with the new
      weapon tables.

## Players tables and charts (the manifest)

Every named table from the players
section own index, one item each:

- [ ] Armor Class Table (p. 26).
- [ ] Attacks Per Melee Round Table (p.
      22).
- [ ] Barbarians (Fighters) Table I (p.
      19).
- [ ] Cavaliers Table I (p. 15).
- [ ] Character Class Limitations
      (Character Race Table I) (p. 7).
- [ ] Character Level Limitations
      (Character Race Table II) (pp.
      8-9, the six sub-tables).
- [ ] Character Hit Dice, Spell Ability,
      Class Level Limit (Character
      Classes Table I) (p. 12).
- [ ] Character Armor and Weapons
      Permitted (Character Classes Table
      II) (p. 13).
- [ ] Druids (Clerics) Table I (p. 17).
- [ ] Equipment and Supplies Costs (p.
      26).
- [ ] Racial Preferences Table (p. 12).
- [ ] Spell Tables (pp. 28-31): clerics
      28-29, druids 29, magic-users
      30-31, illusionists 31.
- [ ] Thief-Acrobat Function Table (p.
      24).
- [ ] Thief-Acrobat Table I (p. 23),
      Table II (p. 25), Table III (p.
      25), Table IV (p. 25).
- [ ] Thieves Table II (p. 22).
- [ ] Weapon Proficiency Table (p. 26).
- [ ] Weapon Specialization Table for
      Fighters and Rangers (p. 18).
- [ ] Weapons, Weight and Damage by
      Type (p. 26).
- [ ] Weapons, Hand-held, General Data
      and To-Hit Adjustments (p. 27).
- [ ] Weapons, Hurled and Missile,
      General Data and To-Hit
      Adjustments (p. 28).

## Deferred (wanted, gated on a layer)

- DEFERRED: the psionic expansions (a
  psionics seam; the duergar doubled
  chance rides it).
- DEFERRED: the comeliness ENGINE site
  (no comeliness field on Character -
  the R322 pins charge when the site
  exists).
- DEFERRED: the mounted-combat rules (a
  mount layer; the R321 aerial precedent
  - the pins would precede any site).
- DEFERRED: Appendix S (a deity layer;
  see the appendices item).

## Deferred engine seams (the gates)

The dependency graph: each seam gates
the items named with it. A seam round
lands before the items it gates.

- [x] The subrace layer - CLOSED R323
      (rules/subraces.h; the R323 seam
      audit, census 250). Race Table
      II and the wiring (the race
      selection site, the R117
      reactions) remain its open
      dependents.
- [ ] The cantrip tier seam - a
      sub-1st registry tier; gates the
      cantrip category.
- [ ] The treasure system dial - the
      reconcile/reverse/run-both switch;
      gates the treasure section.
- [ ] The deity layer - gates Appendix
      S.
- [ ] The psionics seam - gates the
      psionic expansions.
- [ ] The mount layer - gates the
      mounted-combat rules.
- [ ] The comeliness site (a Character
      field, the reaction callers) -
      wires the R322 and R117 pins.
- [ ] The code-level logging layer -
      bug and missing-functionality
      discovery at the code level.
- [ ] The game-level logging layer -
      playtest evidence; the closure
      criterion instrument.

Categories:
- [x] = verified against the book text
- [~] = verified DIVERGENT
- [ ] = open item (worth having; a round
      should close it)
- DEFERRED = wanted; gated on an engine
      layer not yet built
- OUT = never; empty by design - filling
      it takes an explicit ruling
