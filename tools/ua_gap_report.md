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
- [ ] **Cavaliers Table I** (p. 15) -
      the XP ladder, the level titles
      (Horseman to Cavalier Commander),
      the 3 hp per level after 10th, the
      300000 xp per level past 12th;
      reads clean.
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
- [ ] **The barbarian** (pp. 18-21) -
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
- [ ] **The ranger expansion** (pp.
      21-22) - the tracking rules, the
      giant-class combat bonus, the
      spell progression (druidic from
      8th to 3rd-level spells, MU from
      9th to 2nd-level spells).
- [ ] **Thieves Table II** (p. 22) -
      the armor-effects penalties on
      thieving functions (non-leather
      armor, the elfin chain read); the
      **Attacks Per Melee Round Table**
      (p. 22) pairs with it.
- [ ] **The thief-acrobat** (pp. 23-25)
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
- [ ] **Money for cavaliers** (p. 25) -
      the starting gear by social class.

### Equipping the character (pp. 25-28)

- [ ] **The Armor Class Table** (p. 26)
      - the expanded AC-by-armor table.
- [ ] **The Equipment and Supplies
      Costs table** (p. 26).
- [ ] **Weapons, Weight and Damage by
      Type** (p. 26).
- [ ] **Weapons, hand-held, general
      data and to-hit adjustments** (p.
      27) - the speed factors, the
      size-class damage, the strength
      adjustment rows.
- [ ] **Weapons, hurled and missile,
      general data** (p. 28).
- [ ] **The Weapon Proficiency Table**
      (p. 26) - pairs with the R299
      layer.
- [ ] **The new weapons** (pp. 26-28
      and DM pp. 77-79) - the aklys,
      atlatl, blowgun, caltrop, garrot,
      harpoon, hook fauchard, khopesh,
      lasso, man catcher, sap, spiked
      buckler, staff sling, whip (14
      named types, each with its own
      data row).

### Character spells (pp. 28-73)

- [ ] **The spell tables** (pp. 28-31) -
      clerics 28-29, druids 29,
      magic-users 30-31, illusionists 31;
      the cantrip columns are the first
      spell-table appearance of the new
      tier; reads clean; the R80 registry
      is data-driven.
- [ ] **The new cleric spells** (pp.
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
- [ ] **The new druid spells** (pp.
      42-45) - 1st (ceremony, detect
      balance, detect poison,
      precipitation), 2nd (flame blade,
      goodberry, reflecting pool, slow
      poison), 3rd (cloudburst, know
      alignment, spike growth,
      starshine), 5th (moonbeam, spike
      stones), 6th (liveoak, transmute
      water to dust), 7th (changestaff).
- [ ] **The new magic-user spells**
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
- [ ] **The new illusionist spells**
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
- [ ] **The cantrip acquisition rules**
      (DM pp. 79-80) - cross-ref to the
      DM section item; the apprentice
      may develop at most 3 new
      cantrips.

## Dungeon masters section (pp. 73-105)

### Creating the player character (pp. 74-75)

- [ ] **Method V** (p. 74) - the
      class-first generation, humans
      only; the dice-count table (the
      9d6 fighter strength, the Com
      column) reads clean; the minimum
      and maximum clamps.
- [ ] **Starting hit-point minimums**
      (p. 74) - cavalier 6, paladin 6,
      cleric 5, druid 5, fighter 6,
      barbarian 7, ranger 9, magic-user
      3, illusionist 3, thief 4,
      assassin 4, monk 5.
- [ ] **The comeliness creation note**
      (p. 74) - the DM pointer; rides
      the R322 pins.

### Character classes (pp. 74-75)

- [ ] **The cavalier follower tables**
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
- [ ] **The henchman rules** (p. 75) -
      the charisma +3 (good) or +1
      (else) bonus; the alignment-based
      henchman-type table; the retainer
      ladder (Armigers/Scutifers at 4th,
      the Esquire at 6th, the Horseman
      herald and Lancer guard at 7th,
      the extra man-at-arms at 8th); the
      paladin retainer rules.

### Armor, armor class and weapons (pp. 75-79)

- [ ] **The expanded armor table** (p.
      75) - reads clean: banded 90 gp,
      bronze plate 100 gp, field plate
      2000 gp, full plate 4000 gp, the
      bulk and movement columns, the
      shield rows, elfin chain never
      sold.
- [ ] **The new armor descriptions**
      (pp. 75-76) - bronze plate (AC 4,
      +2 rear-attack exposure, rust
      immunity), elfin chain (thief-
      wearable), field plate (the 1
      point per die absorption, the 12
      point cap, the repair costs),
      full plate.
- [ ] **Warhorses and barding** (p. 76)
      - the barded movement rate table.
- [ ] **The new weapon descriptions**
      (pp. 77-79) - the 14 named types
      (see the players section item);
      the pole-arm cross-refs point to
      Appendix T.

### Character spells (pp. 79-83)

- [ ] **Cantrip acquisition, MU** (p.
      79) - the known-count rules (the
      useful-per-intelligence read; the
      2-8/2-5 random counts; the 3
      developed cantrips cap).
- [ ] **The spell book rules** (pp.
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
- [ ] **Illusionist spell acquisition**
      (p. 80) - the starting list table;
      the illusionist book differences.
- [ ] **The cost of spell casting** (pp.
      80-81).
- [ ] **The spell explanations - the
      referee commentary** (pp. 81-82) -
      the permanency list and the rest.
- [ ] **Underwater spell use** (pp.
      81-83) - the per-spell underwater
      reads (the salt cantrip, the
      firewater float, the acid arrow
      washout, the chain lightning
      change, the mansion option, the
      sink read, and the rest of the
      list).
- [ ] **The effects of darkness** (p.
      82) - the combat effects ladder.

### The campaign (pp. 82-83)

- [ ] **Social class and rank** (p. 82)
      - the Social Class Table; extends
      the R208 tables.
- [ ] **Circumstances of birth** (p.
      83) - the Birth Table (the
      12-child ladder), the Parents
      Marital Status Table (the
      one-class-lower read for the
      unmarried).

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
- [ ] **The new potions** (p. 90).
- [ ] **The new scrolls** (pp. 91-93).
- [ ] **The new rings** (pp. 92-94).
- [ ] **The new rods and staves** (pp.
      94-96).
- [ ] **The new wands** (pp. 96-97).
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
