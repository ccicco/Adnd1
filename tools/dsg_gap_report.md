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
- [x] **Overview of the Underdark** (pp. 7-11) - R503: the three natural cave types (limestone, sea, lava) with the living/dead cave split, the geothermal side, the unnatural locale taxonomy (dungeons, mines, burrows, realms) and the five hazard families (cave-ins, floods, fires, poisonous gases, volcanoes)
  - [x] Natural underground locales (pp. 7-9) - R503: the limestone cave (acid erosion, the water-table drain, the inlet and sinkhole entrances, the drip formations, the living-cave glisten/mud vs the dead-cave brittle dust/rubble, the smooth water-filled passages), the smaller smooth sea caves with their relic likelihood, the dry hidden lava caves, the quake and fault chambers, the geothermal ladder (lava 1,800 F, crust, steam, hot water, warm air)
  - [x] Unnatural underground locales (pp. 9-11) - R503: the purpose-built dungeons (soft-rock excavation, 10-foot dirt shoring, the jail/treasure/lair/defense purposes, the stronger-than-castles note), the mine networks (active guarded, inactive laired), the creator-sized burrows with the umber-hulk stone exception, and the realms deeper than a mile (nation-scale caverns, seas with islands, wilderness-to-cities)
  - [x] Hazards of the underearth (p. 11) - R503: the survey - cave-ins (the shoring split between dungeons, caverns and realms), floods (no room to disperse), fires (the combustibles-and-oxygen double threat, the wood scarcity), poisonous gases (the confinement multiplier) and volcanoes (lava, steam, closed passages)
- [x] **Movement rules for underground play** (pp. 12-22) - R505: the whole movement chapter now pinned in two rounds - R504 the check frames, swimming, breath, moving water, climbing, rappelling, jumping and the rope system; R505 the bridges, the expanded falling rules, spelunking, excavation, fatigue/exhaustion, darkness movement and slippery surfaces
  - [x] Ability and proficiency checks (p. 12) - R504: the 1d20 frames - ability checks succeed equal-or-less with the dice substitution rule, proficiency checks strictly less than the rating
  - [x] Swimming (p. 12) - R504: the proficiency gate, the 1/3 monster chance, the three functions and Table 1 (verified const-for-const against rules/wsgswim.h), the endurance, speed and dive rules; the strength speed bonus pins on the DAMAGE bonus, a WSG divergence (both cap +3)
  - [x] Holding one's breath (p. 12) - R504: the 1/3-con breath with the cumulative halvings and the one-round floor, the -2 cumulative con checks after, the +1 nonswimming round (verified against rules/wsgbreath.h)
  - [x] Moving in water (p. 13) - R504: the proficiency/afloat rules, the 4/3-inch base speeds, the underwater 2/3 cut, the Table 1 effects and the dive/surfacing ladders with the printed dive-example tension noted
  - [x] Effects of moving water (p. 14) - R504: the relative-speed rule with the 40-foot stream example, the waterfall half damage with the breath save and the 100-foot/1-10 plunge split, the 1-10 danger-rating cadence with the 1d6 failed-check damage (verified against rules/wsgmwater.h)
  - [x] Climbing (pp. 14-16) - R504: the surface taxonomy with Table 2 (nine rows, thieves at half for others), the surface and condition definitions with the 2x/10x fall multipliers, the encumbrance halving and the 40 percent non-thief rating with the equal-or-less check (verified against rules/wsgclimb.h)
  - [x] Climbing modifiers (p. 16) - R504: the armor ladder (plate barred, -15 chain/splint/scale/banded, -5 studded/padded, leather free), the race modifiers (-5/-10/-5/+5) and the surface bonuses (+40/+25/+20/+40)
  - [x] Climbing tools (p. 16) - R504: the spikes (1d4 rounds, the 10 percent arrest failure, the 15 percent ice-slip), the grapple throw (1/3 strength x 10, the noise ladder, Table 3, the 1d6 catch-and-slip) and the rope-broken half-damage fall
  - [x] Rappelling (p. 16) - R504: the +50 climbing check, the +30 free-hang modifier, the 120 feet-per-round rate and the full-distance failure fall (verified against rules/wsgrapp.h)
  - [x] Jumping for non-acrobats (p. 17) - R504: the 20-foot head start, the one-segment jumps, Table 4 (the seven bands) with the encumbrance and race modifiers and the 2-foot floor; the encumbered -4 jump allowed here where the WSG forbids severe jumps, a pinned divergence
  - [x] Jumping movement (p. 17) - R504: the one-segment movement rule and the no-backward, no-extended-position limits for non-acrobats
  - [x] Using rope (pp. 17-19) - R504: the rope system pinned whole - the chasm crossing (Tables 5-6), the swing, the belay and the roping-together cascade (verified against rules/wsgchasm.h, rules/wsgbelay.h and rules/wsgtog.h)
  - [x] Crossing a chasm on a rope (p. 17) - R504: the anchor problem, the 50 percent protrusion chance, Table 5, the thrown loop (the 20 percent base, +1 percent per foot, Table 6, the halved range without the 10-foot radius) and the +30 crossing check each round (verified against rules/wsgchasm.h)
  - [x] Swinging across (p. 18) - R504: the pendulum, the -5-percent-per-10-feet hold check, and the 1d6 per 20-foot rope section with the dropped fractions
  - [x] Belaying (p. 18) - R504: the belay check with the rope-length bound, the second check with the 3-foot edge rule, the -10 per additional faller, the spike anchor and the both-ends crossing (verified against rules/wsgbelay.h)
  - [x] Roping together (p. 19) - R504: the 20-30 feet of slack, the slowest-rate march, the both-sides checks with the -10 two-faller cascade and the end-character single check (verified against rules/wsgtog.h - the cascade step pins at -10)
  - [x] Bridges (p. 19) - R505: the maintained no-check rule, the suspension 25-percent-per-character give-way with the one-hand catch at -25, the anchor sabotage 1d8 rounds thief-only to detect, the sawed rope one round and visible, the wooden 5-percent-per-year rot with the 1d20+20-year beams and the 50-percent rotten step, the stone impervious with the transmute-rock-to-mud arch collapse 1d4 rounds and the instant foundation collapse, the rope bridge +50 with the -20 sabotaged cling, and the log bridge +40/+20 sloped/+80 crawling with the 10/20/30/40-50 move-log ladder
  - [x] Falling (expanded rules) (pp. 19-20) - R505: the cumulative 1d6-per-10-feet dice (6d6 at 30 feet), the 20d6 cap, the 10d6 waterfall cap, the 1,000-feet-per-round rate, the 50-foot stop window with the 1/2 and 1/4 catch chances and the slippery bar, the landing ladder (rough x2, the 1d6 and 3d6 spike groupings, soft 1/2, the very-soft save, the water 1d6 per 100 feet rounded up with the no-catch-same-round rule), and the slope slide (20 feet free, 1d6 per 10 feet, the 1d6-per-40-feet landing, the slippery double landing) (verified const-for-const against rules/wsgfall.h and rules/wsgstop.h - the 6d6-at-30, the 20d6 cap and the 50-foot window agree)
  - [x] Spelunking (p. 20) - R505: the 2/3-ceiling upright 2/3 rate, the hands-and-knees 1/2 rate with -5 attacks and no Dexterity/shield AC, the prone 1/4 rate with -8 attacks and the further weapon limits, the dragged pack, and Table 7
  - [x] Excavation (p. 21) - R505: the 1d4-feet-per-turn rubble clearance to the Table 7 width, the 2d4 partial-block rate, and the solid barriers at the Table 27 rates with the 1/4 non-pick tool penalty
  - [x] Fatigue and exhaustion (pp. 21-22) - R505: the 4-turns-work/2-rest cycle, the 6-turn Constitution Check with the +5 then the shrinking interval to every turn, the -2 attribute and attack/damage/save effects for 12 turns, the every-turn fatigued checks against the revised Constitution, the exhausted -4 instead of the fatigue -2 (a WSG divergence - the WSG frames it as an additional -2; both total -4), and the 6-turn recoveries (verified const-for-const against the WSG fatigue pins rules/wsgfatig.h)
  - [x] Movement effects of darkness (p. 22) - R505: the Dexterity Check on unseen obstacles, the 1/3 safe probing rate, the straight-line impossibility without a guide, the secret d12 course roll every 3 turns with the -1-per-short-turn, the rough-floor Dexterity Checks with the 1-point falls, the 1/6 cautious rate, and Table 9
  - [x] Movement on slippery horizontal surfaces (p. 22) - R505: the straight-line safety, the Dexterity Check on turns, stops and runs with the no-damage one-round fall, the 1/2-rate free turn and the one-round slowdown, the every-attack melee check with the +4 AC fall penalty and the -4 fight-from-ground attacks, and the crampons with the 2x noise and 1d6-mile wear (verified const-for-const against rules/wsgslip.h)
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
- [ ] **Dungeon Master's section** (pp. 64-120) - the DM half, re-grained at R503 from the DM table of contents on printed p. 64: the underground environment chapter, the cultures, the Deepearth campaign lands, the adventure-design craft and the mapping system
  - [x] The DM's table of contents (p. 64) - R503: pulled at the extraction round (pdf 65, the reads ride the r503-extraction branch); the DM boxes re-grained from it
  - [ ] The underground environment, DM chapter (pp. 65-72) - features of the underground game (p. 65), the nature of the underground environment and its denizens (p. 66), a brief history of underground cultures (p. 68)
  - [ ] Underground geography: domains in three dimensions (p. 69) - surface terrain (p. 69), temperature, humidity, size, origin, access and egress (p. 70)
  - [ ] Theories on the nature of the underground (pp. 70-71) - the hollow earth, Swiss cheese, isolated pockets and partial connection theories
  - [ ] The cultures of the underdark (pp. 73-74) - values and objectives (p. 73), drow (p. 73), kuo-toa (p. 73), duergar (p. 73), mind flayers (p. 74), aboleth (p. 74), derro (p. 74), cloakers (p. 74)
  - [ ] Lands of Deepearth (pp. 75-98) - connecting passages (p. 75), area details (p. 75), the map (pp. 76-77), the individual area key (pp. 78-98): all 31 areas from the Great Lake through the fungus forest, the illithid outpost, the drow realm and the dark realms to darksea
  - [ ] Underground adventures: campaign considerations (pp. 99-113) - challenges for the DM (p. 100), the fine art of juggling (p. 100), designing the adventure and the world (p. 100), plot and counterplot (pp. 103-106), techniques of story and campaign design (pp. 109-110), running the game (pp. 111-113)
  - [ ] Mapping your settings (pp. 114-117) - basic mapping considerations (p. 114), perspective mapping (p. 114), selecting a grid (p. 114), selecting a starting point (p. 115), drawing the map (p. 115), mapping symbols (p. 115), splitting the grid (p. 115), horizon lines (p. 117), geomorphic mapping and using geomorphs (p. 117)
- [ ] **Compiled tables** (p. 121) - the book's own table reprint pages
- [ ] **Perspective maps** (pp. 124-127) - the 3-D map plates, a DM-TOC section the player's contents page missed
- [ ] **Index** (p. 128)

## The tables manifest (the book's own Tables index - every named table gets its own line)

- [x] Table 1: Swimming Effects of Encumbrance (p. 13) - R504
- [x] Table 2: Rates of Climbing (p. 14) - R504
- [x] Table 3: Grappling Success (p. 15) - R504
- [x] Table 4: Broad Jumping (p. 16) - R504
- [x] Table 5: Crossing With a Grapple (p. 17) - R504
- [x] Table 6: Thrown Loop Ranges (p. 17) - R504
- [x] Table 7: Minimum Passageway Sizes (p. 21) - R505
- [x] Table 8: Armor Effects on Character Width (p. 21) - R505
- [x] Table 9: Course Changes in Darkness (p. 22) - R505
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
