# DSG Gap Report - the book vs the repo

DSG ARC OPENER, ROUND ZERO. The dungeoneering arc names the
Dungeoneer's Survival Guide (1986, Douglas Niles, 128 pp.).
This report inventories the whole DSG book against the engine
and is, by design, lossless: it mirrors the book's own
structure (the Player's Section chapters, the DM section, the
compiled tables, the index), every named table from the book's
own Tables index gets its own line item (the manifest -
nothing can be skipped silently), and every load-bearing prose
mechanic is its own sub-item rather than a clause in a
paragraph. Engine scope unchanged: the rules/ pin headers, the
battery audits, the census. Closure criterion: a box closes
when the feature PLAYS right - compiling is not the test; a
round closes an item by flipping the box in the SAME commit.
The universe: this book, the landed WSG/UA/DMG/PHB reports,
and the engine pins they carry.

Conventions as the WSG report: [x] verified against the book
text (with the round); [~] verified DIVERGENT; [ ] open item.
Page cites are the PRINTED book pages from the book's own
table of contents; the pdf-page offset gets pinned at the
extraction round (the WSG offset was printed + 1).

CROSS-BOOK SEAM WARNING (standing rule for this arc): the DSG
movement chapters are the upstream source of the WSG
climbing/swimming/rope material already pinned as
rules/wsgclimb.h and kin, and the DSG proficiency system is
the upstream source of the WSG proficiency system pinned by
R425/R498. NOTHING is auto-credited. A DSG box may only close
[x] against an existing header after the round mechanically
verifies the DSG's own printed values const-for-const against
that header; where the books diverge, the DSG value pins under
its own DSG prefix (ds*) even if a WSG twin exists.

The DM section (pp. 64-120) boxes are coarse by design - the
book's own DM table of contents lives on printed p. 64 and
gets pulled at the extraction round; the DM boxes get
re-grained then, before any DM pin round.

## The chapters (the book's own Table of Contents hierarchy)

- [ ] **Dungeoneer's Survival Guide: what is it?** (p. 6) - the chapter frame: the mystery of the underdark, the new rules for underground play, the denizens of the underdark, the underground campaign and the using-this-information player/DM split
  - [ ] The Mystery of the Underdark (p. 6)
  - [ ] New Rules for Underground Play (p. 6)
  - [ ] The Denizens of the Underdark (p. 6)
  - [ ] The Underground Campaign (p. 6)
  - [ ] Using This Information (p. 6)
- [ ] **Overview of the Underdark** (pp. 7-11) - the natural locales (the three cave types, the living/dead cave split, the formations), the unnatural locales and the hazards of the underearth
  - [ ] Natural underground locales (pp. 7-9) - limestone caves (the sinkhole entrances, stalactites/stalagmites, draperies, flowstone, gypsum flowers, the living-cave mud), sea caves, lava tubes, the living vs dead cave split
  - [ ] Unnatural underground locales (p. 9) - the carved/dug/built formations and the made-by-creatures taxonomy
  - [ ] Hazards of the underearth (p. 11) - the hazard survey the later chapters detail
- [ ] **Movement rules for underground play** (pp. 12-22) - the swimming/holding-breath/moving-water rules, the climbing rates and tools for non-thieves, jumping, the rope system (chasm, swing, belay, roping together), bridges, the expanded falling rules, spelunking, excavation, fatigue/exhaustion, darkness movement and slippery surfaces
  - [ ] Ability and proficiency checks (p. 12) - the check frame the chapter's rules ride on
  - [ ] Swimming (p. 12) - the rate rules with Table 1, the cross-book seam against rules/wsgswim.h
  - [ ] Holding one's breath (p. 12) - the breath economy, the cross-book seam against rules/wsgbreath.h
  - [ ] Moving in water (p. 13) - the underwater movement rules
  - [ ] Effects of moving water (p. 14) - the current/flow hazards, the cross-book seam against rules/wsgmwater.h
  - [ ] Climbing (pp. 14-16) - the climbing success rates for non-thieves with Table 2, the encumbrance and armor effects, the surface ladder; the cross-book seam against rules/wsgclimb.h
  - [ ] Climbing modifiers (p. 16) - the condition/situation modifiers
  - [ ] Climbing tools (p. 16) - the gear effects on rates and checks
  - [ ] Rappelling (p. 16) - the descent rules, the cross-book seam against rules/wsgrapp.h
  - [ ] Jumping for non-acrobats (p. 17) - the broad/high jump floors with Table 4, the running-start rules
  - [ ] Jumping movement (p. 17) - the mid-air and landing rules
  - [ ] Using rope (pp. 17-19) - the rope-use proficiency system: crossing a chasm on a rope, swinging across, belaying, roping together
  - [ ] Crossing a chasm on a rope (p. 17) - the anchor and loop rules with Tables 5-6, the cross-book seam against rules/wsgchasm.h
  - [ ] Swinging across (p. 18) - the pendulum crossing rules
  - [ ] Belaying (p. 18) - the belay sequence and checks, the cross-book seam against rules/wsgbelay.h
  - [ ] Roping together (p. 19) - the roped-party cascade rules, the cross-book seam against rules/wsgtog.h
  - [ ] Bridges (p. 19) - the permanent and impromptu bridge rules
  - [ ] Falling (expanded rules) (pp. 19-20) - stopping a fall, landing, sliding down slopes; the cross-book seam against rules/wsgfall.h and rules/wsgstop.h
  - [ ] Spelunking (p. 20) - the tight-squeeze rules with Table 7
  - [ ] Excavation (p. 21) - the rubble clearance and solid-barrier digging rules with Table 8
  - [ ] Fatigue and exhaustion (pp. 21-22) - the effects ladders, the cross-book seam against the WSG fatigue pins
  - [ ] Movement effects of darkness (p. 22) - the blind movement rules with Table 9
  - [ ] Movement on slippery horizontal surfaces (p. 22) - the slip/dex-check rules, the cross-book seam against rules/wsgslip.h
- [ ] **Proficiencies** (pp. 23-29) - the expanded nonweapon proficiency system: the check system, the artisan/craftsman and adventuring lists, the optional bonuses, the NPC training rules and the XP-for-proficiencies option; the cross-book seam against R425 (rules/wsgprof.h) and R498 (rules/wsgprofd.h)
  - [ ] Nonweapon proficiencies (p. 23) - the system frame and the success/failure rules with Table 10
  - [ ] Costs and counts (p. 23) - the slot/counts economy
  - [ ] Artisans, craftsmen and other NPCs (p. 24) - the NPC-training and NPC-craft rules
  - [ ] Optional bonuses (p. 24) - the bonus-rule option
  - [ ] Craftsman proficiencies (pp. 25-26) - the list with Table 11, weapon making with Table 12
  - [ ] Adventuring proficiencies (pp. 26-29) - the list with Table 13
  - [ ] Experience points for proficiencies (p. 29) - the XP option
- [ ] **Combat rules for underground play** (pp. 30-33) - the sheer-surface combat, bridge/ledge combat, grabbing an enemy, water combat, narrow-passage combat, darkness combat, spellcasting in darkness and mounted combat with Table 14
  - [ ] Fighting on walls and other sheer surfaces (p. 30)
  - [ ] Fighting on bridges and ledges (p. 30)
  - [ ] Grabbing an enemy (p. 30)
  - [ ] Fighting in water (p. 30)
  - [ ] Fighting in narrow passages (p. 31)
  - [ ] Fighting in darkness (p. 31)
  - [ ] Spellcasting in darkness (p. 32)
  - [ ] Rules for mounted combat (p. 32) - mounted bow fire with Table 14
- [ ] **Battlesystem options underground** (pp. 34-35) - the mass-combat adaptation: narrow frontages, combat modifiers, formation modifiers, morale effects, ventilation effects, flying effects, line-of-sight effects and battlefield cave-ins
  - [ ] Extremely narrow frontages (p. 34)
  - [ ] Combat modifiers (p. 34)
  - [ ] Formation modifiers (p. 34)
  - [ ] Morale effects (p. 34)
  - [ ] Ventilation effects (p. 34)
  - [ ] Flying effects (p. 34)
  - [ ] Line-of-sight effects (p. 35)
  - [ ] Cave-ins on a battlefield (p. 35)
- [ ] **The underground environment** (pp. 36-55) - the big chapter: air supply, cave-ins, defensive point values, hypothermia, the lodestone, long-adventure NPC reactions, structural decay, the underground waterways, water travel, the full mining system, and the natural/unnatural hazards
  - [ ] Air supply duration (pp. 36-37) - the per-character air economy and the party-rate rules
  - [ ] Fire and smoke underground (p. 37) - the smoke buildup rules
  - [ ] Poisonous and noxious gases (p. 37) - the gas types and effects
  - [ ] Ventilation (p. 37) - the airflow rules
  - [ ] Odor detection (pp. 37-38) - Tables 15-16 (the detection and wind-effect grids)
  - [ ] Causes of cave-ins (p. 38) - the triggers
  - [ ] Random occurrences of cave-ins (pp. 38-39) - Table 17 (the location grid)
  - [ ] Cave-in chain reactions (pp. 39-40) - Table 18 (the chain grid)
  - [ ] Effects of cave-ins (p. 40) - the damage/burial rules
  - [ ] Defensive point values of underground formations (pp. 40-42) - Table 19 (the structure DPV grid)
  - [ ] Hypothermia, optional rule (p. 42) - the cold-water rules, the cross-book seam against rules/wsgheat.h
  - [ ] Magnetic effects of lodestone (p. 42) - the compass/needle rules
  - [ ] NPC reactions to long underground adventures (pp. 42-43) - Table 20 (the unsteady-reactions grid)
  - [ ] Structural decay (p. 43) - the aging-of-worked-stone rules
  - [ ] Underground waterways (pp. 43-46) - standing water, flowing water, water temperature, access to underground waterways
  - [ ] Underground water travel (pp. 46-48) - Tables 21-26 (boat movement rates, standstill movement, draught and ceilings, nonproficiency penalties, collision probability, boat damage)
  - [ ] Mining: where to mine (p. 48) - the prospecting rules
  - [ ] Mining: types of mines (p. 49) - the vein/placer taxonomy
  - [ ] Mining: excavating a mine tunnel (p. 49) - Table 27 (the rates grid)
  - [ ] Mining: mineral vein direction and path alterations (p. 49) - Tables 28-29
  - [ ] Mining: shoring a tunnel (p. 50) - the support rules
  - [ ] Mining: products of a mine (p. 50) - Table 30 (the metals/gems grids, Tables 31-32)
  - [ ] Mining: quality of mining products (pp. 50-51) - Tables 33-34 (the ore/gemstone quality grids)
  - [ ] Mining: calculating the value of a placer mine (p. 53)
  - [ ] Mining: smelting (p. 53)
  - [ ] Mining: finishing (p. 53) - the gem-cutting rules
  - [ ] Mining: duration of a mining claim (p. 53)
  - [ ] Mining: inherent hazards of mining (p. 53)
  - [ ] Mining: the claim (p. 53) - the staking rules
  - [ ] Mining: hireling loyalty (p. 54)
  - [ ] Natural hazards (p. 55) - the underground hazard survey
  - [ ] Unnatural hazards (p. 55) - the made hazards
- [ ] **New equipment** (pp. 56-58) - the cost/weight grid with Table 35, the new-item descriptions, the transportation equipment and the proficiency equipment
  - [ ] Equipment costs and weight (p. 56) - Table 35
  - [ ] New equipment descriptions (pp. 56-57)
  - [ ] Transportation equipment (p. 57)
  - [ ] Equipment for proficiencies (p. 57)
- [ ] **Improving play** (pp. 59-63) - the DM-craft chapter: expedition planning, beasts of burden, watercraft, fighting effectively, diversions, speeding play, creative spell use, the languages of the underdark and mapping techniques
  - [ ] Expedition planning (p. 59)
  - [ ] Using beasts of burden (p. 59)
  - [ ] Using watercraft (p. 60)
  - [ ] Fighting effectively (p. 60)
  - [ ] Creating diversions (p. 60)
  - [ ] Speeding play (p. 61)
  - [ ] Creative underground spell use (p. 61)
  - [ ] Languages of the underdark (p. 62)
  - [ ] Mapping techniques (p. 62)
- [ ] **Dungeon Master's section** (pp. 64-120) - the DM half: the underground campaign craft, the 3-D mapping system, the cultures of the underdark (the drow, kuo-toa, duergar, mind flayers, aboleth, derro, cloakers), the location and encounter generators and the Lands of Deepearth sample campaign; boxes re-grained at the extraction round from the DM table of contents on printed p. 64
  - [ ] The DM's table of contents (p. 64) - the re-graining source for this section's boxes
  - [ ] The cultures of the underdark (pp. 66+): values and objectives, drow, kuo-toa, duergar, mind flayers, aboleth, derro, cloakers
  - [ ] The underground campaign craft: adventure design, storytelling, stocking, 3-D mapping
  - [ ] The random location and encounter generators
  - [ ] Lands of Deepearth: connecting passages, area details, the map, the individual area keys (the Great Lake, the surface lands, the upper caverns, the cathedral caverns and the rest)
- [ ] **Compiled tables** (p. 121) - the book's own table reprint pages
- [ ] **Index** (p. 128)

## The tables manifest (the book's own Tables index - every named table gets its own line)

- [ ] Table 1: Swimming Effects of Encumbrance (p. 13)
- [ ] Table 2: Rates of Climbing (p. 14)
- [ ] Table 3: Grappling Success (p. 15)
- [ ] Table 4: Broad Jumping (p. 16)
- [ ] Table 5: Crossing With a Grapple (p. 17)
- [ ] Table 6: Thrown Loop Ranges (p. 17)
- [ ] Table 7: Minimum Passageway Sizes (p. 21)
- [ ] Table 8: Armor Effects on Character Width (p. 21)
- [ ] Table 9: Course Changes in Darkness (p. 22)
- [ ] Table 10: Character Proficiencies (p. 23)
- [ ] Table 11: Craftsman Proficiencies (p. 25)
- [ ] Table 12: Weapon Making (p. 26)
- [ ] Table 13: Adventuring Proficiencies (p. 26)
- [ ] Table 14: Mounted Bow Fire (p. 32)
- [ ] Table 15: Odor Detection (p. 38)
- [ ] Table 16: Wind Effects on Odors (p. 38)
- [ ] Table 17: Cave-in Location (p. 39)
- [ ] Table 18: Cave-in Chain Reaction (p. 40)
- [ ] Table 19: Underground Structure Defensive Point Value (p. 42)
- [ ] Table 20: Unsteady NPC Reactions (p. 43)
- [ ] Table 21: Boat Movement Rates (p. 46)
- [ ] Table 22: Movement From a Standstill Position (p. 46)
- [ ] Table 23: Boat Draught and Ceilings (p. 46)
- [ ] Table 24: Nonproficiency Penalties for Boat-Use (p. 47)
- [ ] Table 25: Collision Probability (p. 48)
- [ ] Table 26: Boat Damage (p. 48)
- [ ] Table 27: Mining Rates (p. 49)
- [ ] Table 28: Mineral Vein Direction (p. 49)
- [ ] Table 29: Vein Path Alterations (p. 49)
- [ ] Table 30: Mining Products (p. 50)
- [ ] Table 31: Metals (p. 50)
- [ ] Table 32: Gemstones (p. 50)
- [ ] Table 33: Ore Quality (p. 50)
- [ ] Table 34: Gemstone Quality (p. 51)
- [ ] Table 35: Equipment Cost and Weight (p. 56)
