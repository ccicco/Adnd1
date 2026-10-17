// =========================================================================================
// Adnd1 - rules/dsgplay2.h
// The DSG IMPROVING-PLAY TAIL: FIGHTING, DIVERSIONS, SPEEDING PLAY, SPELL
// USE, LANGUAGES, MAPPING, R529: printed pp. 60-63 (pdf 61-64) - the fighting
// effectively: characters fight better together long (experience and trust,
// but cooperative techniques practicable from the start), the well-organized
// party defining roles (the low-AC fighters between the monsters and the
// rest), the retreat plans (the rear guard, the pursuit-discouraging
// magic-user spell, the safe-path scout), the mini-teams (the fighter
// bodyguarding the mage who casts for the group; the diversion fighter
// drawing attention while the thief sneaks behind), and surprise probably the
// single most important tactic (scouting to avoid it, silent no-light
// movement to cause it; rangers least susceptible and most likely to cause
// it, human rangers grievously disadvantaged underground by their lack of
// infravision, half-elven rangers very effective); the creating diversions: a
// distraction can substitute for concealment (fires demanding immediate
// attention, collapsing bridges/tunnels/dams, the rope-topped statue),
// monsters not automatically falling for it - the low-Intelligence reasoning
// monsters like orcs and ogres distracted 1d4 rounds, the medium-to-high
// Intelligence allowed a saving throw vs. spell, the genius-level fooled only
// by very clever diversions concealing the PCs' presence, and player
// characters never saving against monster diversions (purely role playing);
// the speeding play: pace as group taste but wasted time a bane to all
// (squabbling, non-cooperation, DM-arguing, indecision), fixed by standard
// procedures - the door-opening drill (a sketch with each character's role,
// declared as "door opening drill #2"), the standard marching orders
// (corridor widths, open areas, weapons carried, changes communicated), the
// caller re-examined for frustrated groups (delegating to one member,
// rotating every session), and the bossy player best handled by peer
// pressure; the creative underground spell use: the balanced selection across
// offensive, defensive, restorative, investigatigative and scouting spells
// with reverses considered, the sleep protections (magic mouth, glyphs of
// warding, fire traps, rope tricks), the underground-deadly
// cloudkill/stinking cloud/dig/transmute rock to mud/disintegrate with
// augury/divination/find the path useful, the raise-water flood from high
// terrain and lower water against enemy boaters, the enlarge/reduce/warp wood
// passage tricks, the silence coin carried for the party and thrown among
// enemy spellcasters, the darkness against infravision creatures (dramatic
// with blindfighting proficiency), the telekinesis-positioned slime pots
// dropped as missiles or left in the path and broken with shatter, the
// charm-aided questioning of captives, and the toppling walls of
// stone/ice/iron with the ricocheting lightning bolt; the languages of the
// underdark: the UA undercommon and sign language plus the tapping language
// of the subterranean races (clicking stones, drum beats, sharp-sound
// patterns), the underground reverberations amplifying drum communication
// over very long distances, the roughly 10-times-slower pace, and the
// underground-native PCs knowing it; and the mapping techniques: the detailed
// 10-foot-block graphing standard (accurate but slow in game and real time,
// the mapper's light source exposing the party, the 10-to-20-foot map errors
// agonized over against teleport-trap worries), the exit-purpose rule making
// elaborate maps overkill, and the line-drawing alternative (lines for
// corridors, door symbols, guesswork distances, the
// explored-versus-unexplored display, the 100-foot sketch with temporary
// light, sufficient everywhere except mazes and convoluted cavern networks)
// census 452 -> 453.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~7848-8160) with the pdf Acrobat-Capture layer as the second read (idx
// 139-143 = the printed pp. 60-63 windows); the compiled-tables appendix has
// no reprint of this prose. A CLEAN-READ ROUND: both machine reads agree on
// every load-bearing number - the 1d4-round diversion distraction, the 10x
// tapping-language slowness, the 10-ft graphing blocks, the 10-or-20-ft map
// error, and the 100-ft sketch window. The only garbles are the standing
// glyph classes (the UA-lead djvu noise, the "5096"-class absent here).
// SEAMS: the Unearthed Arcana undercommon and sign language (cross-book), the
// blindfighting proficiency (R506), the ranger infravision (PHB class), the
// R518 water travel, and the R511 surprise rules. WITH THIS ROUND THE
// IMPROVING-PLAY CHAPTER CLOSES (all children 142-150 flipped, the parent 141
// closeable at the next census check) - and the player half of the book
// through printed p. 63 is fully pinned. The DM's section (pp. 64-120,
// re-grained at R503) starts the NEXT round. Nothing auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the 1d4-round diversion distraction, the 10x tapping-language
// multiplier, and the mapping numbers (the 10-ft blocks, the 10/20-ft error
// pair, the 100-ft sketch). The rest pins as prose bools: the fighting rules
// (the togetherness, the low-AC placement, the retreat plans, the mini-teams,
// the surprise paramountcy with the ranger note), the diversion tiers (the
// fire/sabotage/remote-control set, the low-Int 1d4, the mid/high save, the
// genius standard, the PC no-save), the speeding-play procedures (the drills,
// the marching orders, the caller rotation, the peer pressure), the creative
// spell tactics (the balanced selection, the sleep protections, the deadly
// set, the water spells, the passage tricks, the silence coin, the darkness,
// the slime pots, the charm, the toppling walls), the tapping language (the
// drum amplification, the native-PC knowledge), and the mapping styles (the
// graphing weaknesses, the exit purpose, the line-drawing alternative and its
// limits). The UA/R506/R511/R518 seams are noted; nothing auto-credits.
//
namespace rules {

// ---- the fighting effectively section ----

// characters fight more effectively if they have been together for a long
// time - a natural outgrowth of experience revealing strengths and
// weaknesses, and trust as companions learn to rely on each other; but
// cooperative techniques can be practiced from the very start.
inline bool dnpmFightTogetherLonger()
    { return true; }

// a well-organized party defines combat roles suited to strengths - at the
// most basic level, keeping the fighters with low Armor Class between the
// monsters and the rest of the party.
inline bool dnpmLowAcInFront()
    { return true; }

// sophisticated planning includes simple tactical plans: who takes the rear
// guard in a retreat, what magic-user spell confuses or discourages pursuit,
// who scouts the safe path of retreat.
inline bool dnpmRetreatPlans()
    { return true; }

// characters benefit from mini-teams within the party: a fighter bodyguarding
// the magic-user who then casts for the group's benefit, or a fighter
// creating a diversion at combat's start while a thief waits to sneak behind
// the foe.
inline bool dnpmMiniTeams()
    { return true; }

// probably no single tactic is as important as surprise: effective scouting
// best avoids being surprised, and moving silently without light sources is
// the best way to surprise an opponent.
inline bool dnpmSurpriseParamount()
    { return true; }

// ranger characters are the least susceptible to surprise and the most likely
// to cause it - but human rangers underground suffer grievous disadvantages
// from their lack of infravision, while half-elven rangers are very effective
// in this environment.
inline bool dnpmRangerInfravisionNote()
    { return true; }

// ---- the creating diversions section ----

// surprise depends on keeping presence secret, but a diversion created or
// taken advantage of can distract a foe so thoroughly that the PCs can
// approach with little regard for stealth - fires (needing immediate
// attention), sabotage like collapsing a bridge, tunnel, or dam, and
// remote-control tricks like the rope-tied statue yanked to topple.
inline bool dnpmDiversionNoConceal()
    { return true; }

// the low-Intelligence distraction roll is one die.
inline int dnpmDivertDice()
    { return 1; }

// monsters with reasoning ability but generally low Intelligence, such as
// orcs and ogres, direct their attention toward a diversion for 1d4 rounds
// unless something else attracts them.
inline int dnpmDivertSides()
    { return 4; }

// monsters - particularly intelligent ones - do not automatically fall for
// diversions.
inline bool dnpmIntelligentMonstersWary()
    { return true; }

// monsters of medium to high Intelligence are allowed a saving throw vs.
// spell to see whether they are fooled by a diversion.
inline bool dnpmMidHighIntSave()
    { return true; }

// monsters of genius-level Intelligence can only be fooled by very clever
// diversions in which the PCs' presence is not easily discerned.
inline bool dnpmGeniusNeedsClever()
    { return true; }

// player characters never get a saving throw if a monster uses a diversion
// against them - whether the PCs fall for it is purely a matter of role
// playing.
inline bool dnpmPcNoSaveVsDiversion()
    { return true; }

// ---- the speeding play section ----

// the pace of a gaming session is a matter of group taste - rapid
// plot-advancers and savor-every-decision players alike - a healthy diversity
// and a strength of role-playing gaming.
inline bool dnpmPaceGroupTaste()
    { return true; }

// wasted time is a bane to all campaigns: squabbling among players, failure
// to cooperate, incessant arguing with the DM, and failure to decide on a
// course of action.
inline bool dnpmWastedTimeBane()
    { return true; }

// the rate of play increases with standard procedures: door-opening drills
// adopted and standardized, with a rough sketch of each PC's location and
// each character's role (guarding the rear, picking the lock, ready to shoot)
// defined for the DM - then a simple declaration ("door opening drill #2")
// suffices.
inline bool dnpmDoorDrills()
    { return true; }

// standard marching orders for common environments should be prepared and
// sketched: corridors of various widths, large open areas, and standard
// weapons carried while marching - changes simply communicated to the DM.
inline bool dnpmMarchingOrders()
    { return true; }

// the caller idea (the character declaring the whole group's actions) should
// be re-examined if players are frustrated with the pace - experienced
// players delegate easily, the caller keeps the party moving through decision
// lulls, and the task works best rotating through the group every game
// session.
inline bool dnpmCallerRotation()
    { return true; }

// if a player attempts to dominate play, peer pressure is probably the most
// effective method - the other players and the DM pointing out the effect of
// the bossy player's pronouncements.
inline bool dnpmBossyPeerPressure()
    { return true; }

// ---- the creative underground spell use section ----

// all spellcasters should briefly discuss selections so the party winds up
// balanced across offensive, defensive, restorative, investigatigative, and
// scouting spells, considering the applications of reverses of reversible
// spells.
inline bool dnpmBalancedSpellSelection()
    { return true; }

// the protective benefits of magic mouth, glyphs of warding, fire traps, and
// rope tricks should not be overlooked when preparing to sleep.
inline bool dnpmSleepProtections()
    { return true; }

// in an underground environment cloudkill, stinking cloud, dig, transmute
// rock to mud, and disintegrate can all prove deadly to an enemy - and
// augury, divination, and find the path are very useful underground.
inline bool dnpmDeadlyUndergroundSpells()
    { return true; }

// from the high terrain a timely raise water spell can call down a sizable
// flood, and lower water can cause serious problems for enemy boaters.
inline bool dnpmWaterSpells()
    { return true; }

// enlarge spells often effectively block a passageway, reduce can remove a
// barrier, and warp wood has a similar effect on doors.
inline bool dnpmEnlargeReduceWarp()
    { return true; }

// a silence spell cast upon a coin or small gem benefits the party when
// carried - and in an encounter the coin can be thrown among enemy
// spellcasters to silence their spell use.
inline bool dnpmSilenceCoin()
    { return true; }

// darkness is effective when humans without a light source encounter
// creatures with infravision - and if characters are proficient in
// blindfighting, the darkness spell (which blinds infravision as well) can be
// quite dramatic.
inline bool dnpmDarknessVsInfravision()
    { return true; }

// green slimes and other deadly creatures sealed into clay or wax pots can be
// positioned with telekinesis over the enemy and dropped as missiles - or the
// pots left in the attacker's path and broken with shatter spells, or hurled
// without any spell.
inline bool dnpmTelekinesisPots()
    { return true; }

// the use of charm spells can immeasurably aid the questioning of captured
// monsters and other enemies.
inline bool dnpmCharmQuestioning()
    { return true; }

// walls of stone, ice, and iron can be cast so they immediately topple and
// crush monsters within the area of effect, and ricocheting a lightning bolt
// can cause dramatic if somewhat unpredictable results.
inline bool dnpmTopplingWallsRicochet()
    { return true; }

// ---- the languages of the underdark section ----

// in addition to the Unearthed Arcana undercommon and sign language, the
// subterranean races have evolved a language based on patterns of tapping -
// expressed by clicking stones together, beating on a drum, or any pattern of
// sharp sounds.
inline bool dnpmTappingLanguage()
    { return true; }

// communication in the tapping language takes approximately 10 times as long
// as with any spoken language.
inline int dnpmTapLangMult()
    { return 10; }

// because underground passages create amplified reverberations, the tapping
// language enables communication over very long distances when drums are used
// - and player characters from the underground know this language.
inline bool dnpmDrumAmplification()
    { return true; }

// ---- the mapping techniques section ----

// the common mapping style is the detailed graphing of each 10-foot block of
// corridor explored or room entered.
inline int dnpmMapBlockFt()
    { return 10; }

// the detailed 10-foot-block graphing style, while usually providing a
// reasonable copy of the DM's map, requires a great deal of game and real
// time (carefully paced dimensions, accurate recording), and forces a light
// source for the mapper that makes the party easier to spot.
inline bool dnpmGraphingWeaknesses()
    { return true; }

// when a room overlaps a mapped corridor, the most likely explanation is that
// the map is off by 10 or 20 feet - not teleport traps.
inline int dnpmMapErrLowFt()
    { return 10; }

// the upper end of the likely 10-to-20-foot map error.
inline int dnpmMapErrHighFt()
    { return 20; }

// players tend to agonize over minor map errors - a room overlapping a mapped
// corridor provokes teleport-trap worries when the most likely explanation is
// a 10-or-20-foot map error.
inline bool dnpmOverlapAgonizing()
    { return true; }

// the main purpose of the map is showing the characters the way out of the
// dungeon after the adventure - elaborate illustration is overkill unless
// careful attention to dimensions is necessary for some reason.
inline bool dnpmMapPurposeExit()
    { return true; }

// a line-drawing map works very well when exact dimensions do not matter: the
// mapper draws a line for the corridor path, standard symbols for doors,
// additional lines for branches, and educated guesswork for distances -
// serving admirably for retracing steps and displaying explored versus
// unexplored areas.
inline bool dnpmLineDrawingMap()
    { return true; }

// with a line-drawing map the light is shone temporarily while the mapper
// quickly sketches in the last 100 feet of corridor, then extinguished while
// the party advances.
inline int dnpmSketchFt()
    { return 100; }

// a line-drawing map provides insufficient information in an extremely
// complicated or confusing area such as a maze or a convoluted network of
// caverns - other than these cases, every bit as effective and a lot more
// convenient than the graph paper masterpiece.
inline bool dnpmLineMapLimits()
    { return true; }

}   // namespace rules
