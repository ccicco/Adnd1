// =========================================================================================
// Adnd1 - rules/dsgcamp5.h
// THE DSG TECHNIQUES OF STORY AND CAMPAIGN DESIGN, R554: printed pp. 109-112
// - the chapter head (the story line a DM chooses affects the gaming
// environment he creates; three types of adventure design, each related to
// plot development); The Linear Adventure (the encounters played in a certain
// order with little choice between them; the dungeon as the linear setting -
// the one-route map and the predetermined locations; the outdoor difficulty
// with the thorn walls and impassable water; the no-wasted-design-time
// advantage; the difficulty as the PCs gain magical power - the high-level
// spells defeating the corridors; the tournament fit; the general
// undesirability - the railroading frustration; the directed play with the
// illusion of choice); The Open Campaign (the de-emphasized story with the PC
// choices determining the course; the interesting world to explore; the
// preparation burden - the detailed countryside seeded with conflicts; the
// Adventurer fun continuing indefinitely - dungeons, wars, new worlds; the
// greater Problem-Solver and Role-Player workload - the mental diet, the
// unique NPCs, the national-scope problems, the nomadic NPCs; the entire
// world setting built over time; the story-structure difficulty - the players
// developing it themselves or taking perverse delight in the opposite; the
// Events technique - the dragon's lair placed in the path with logic; the
// ask-ahead shortcut; the background conflicts - the wars with the met
// principals, the endless winter and the man-eating plants as continuing
// threads); The Matrix Campaign (the detailed story with the player choice;
// the goal or goals motivating the PCs - the linear-open compromise, the epic
// and the string of stories; the short exposition opening options - the evil
// cleric sect with the arrested peasants and the raided temples; the guided
// options north, east, and south with the headquarters to the west bided; the
// prepared courses - the raid, the sage interview, the prisoner rescue; the
// expanding branches steering toward the headquarters climax - the prisoners
// led as an army, the quest for the item of power; the plot events - the
// significant NPCs, the visions and dreams, the social changes, the quick
// scenes; the soft border of the hapless waifs and the stranger's gems; the
// hard border of the cliff, the sea, the desert, the escalating army, the
// quest and geas as the last resort; the several approaches to the final
// encounter, never doomed for a wrong choice; the lost players shown the path
// gently but firmly - the henchman speaking up, the plain-language sage; the
// foreshadowed track with the ill omens); the Running the Game head (the
// second responsibility beginning at the table - the story presented so the
// PCs are drawn in by their own motivations, the mechanics refereed to move
// the story along); Preparing For Play (the lists - eight NPC names rolled on
// 1d8, the personality traits, the appearance characteristics; the coded
// notes - AC, HD, hp, MV, damage, the own maps and symbols, the fewer words
// the better; the THACO shorthand with the ogre example - 15 to hit AC 0, 9
// against AC 6, 19 against AC -4; the map symbols; the anticipated surprises
// - steering back or expanding; the treasure decisions - the wealth, the
// balance impact, the matched challenge); and The Dungeon Master as Master
// Storyteller (the role most obvious during play; the pace - the minutes per
// melee and the story rate, the variety of intensity and rest, the discarded
// slow rules, the optional Weapons vs. AC and spell-component systems, the
// preparation, the pertinent-rules review; the voice - the tone of the tragic
// ruin and the jolly inn, the volume of the unexpected, the varied rate with
// the occasional pause; the colorful word choice - the door crashing inward
// in a blast of splinters; the NPC voices from the old men to the heroic
// leaders, augmented by the facial expressions and hand gestures) - the round
// ending at the HELP FROM THE PLAYERS head.
// census 477 -> 478.
//
// djvu lines 14247-14725 with the Capture-layer pdf 109-113 cross-read (the
// pure-python extractor, parser page = printed page). The two reads agree
// across the round; no OCR-failure cells. The chapter tail and the HELP FROM
// THE PLAYERS head share the p. 112-113 boundary cleanly in the capture: the
// storyteller section closes p. 112 and Help from the Players opens p. 113. A
// CLEAN-READ ROUND. A ZERO-FLIP ROUND: the pp. 99-113 Campaign Considerations
// child stays open.
//
// The campaign chapter: R550 the opener, R551 the worlds tail, R552 plot and
// counterplot, R553 the story elements tail, R554 the techniques; next help
// from the players pp. 113-114, then the child flip.
//
namespace rules {

// ---- the linear adventure section ----

// a linear adventure advances through encounters that must be played in a
// certain order, the PCs given little or no choice between encounters
inline bool dcgLinearDefines()
    { return true; }

// dungeons work well for linear designs - a map leaving one possible route,
// each encounter planned with the PCs' predetermined locations known
inline bool dcgLinearDungeons()
    { return true; }

// outdoor linear adventures are harder to control, though thorn walls or
// impassable water occasionally limit PC choice
inline bool dcgLinearOutdoor()
    { return true; }

// the linear advantage: design time is never wasted on areas the PCs do not
// use
inline bool dcgLinearNoWaste()
    { return true; }

// linear design becomes harder as the PCs gain magical power - high-level
// mage and cleric spells defeat even dungeon corridors
inline bool dcgLinearMagicPower()
    { return true; }

// linear adventures work well for tournament play, all players meeting the
// same challenges
inline bool dcgLinearTournament()
    { return true; }

// for less structured play linear design is generally undesirable - players
// feel railroaded by the absence of choice
inline bool dcgLinearUndesirable()
    { return true; }

// directed play with the illusion of choice can succeed while actually being
// linear - players feel they control their own destiny
inline bool dcgLinearIllusion()
    { return true; }

// ---- the open campaign section ----

// the open campaign de-emphasizes the DM's story, relying on PC choices; the
// DM's job is an interesting world to explore
inline bool dcgOpenDefines()
    { return true; }

// open-campaign preparation: detail the countryside all around and seed the
// entire area with conflicts so challenges are found wherever the PCs go
inline bool dcgOpenPrep()
    { return true; }

// open campaigns are fun especially for Adventurers - indefinite play
// plundering dungeons, stumbling into wars, discovering new worlds
inline bool dcgOpenAdventurers()
    { return true; }

// Problem-Solvers and Role-Players demand even more work - steady mental
// challenges and new unique NPCs; national-scope problems put rumors
// everywhere; nomadic NPCs are re-encountered
inline bool dcgOpenMentalDiet()
    { return true; }

// open campaigns demand great design time, but after enough adventures you
// have created and detailed an entire world setting
inline bool dcgOpenWorldBuilding()
    { return true; }

// the open campaign makes a structured story hard (exposition, development,
// climax); players may develop the structure themselves if clues lead them
inline bool dcgOpenStoryHard()
    { return true; }

// some players take perverse delight in the opposite of what you want;
// without reverse-psychology expertise a coherent story needs exceptional
// inventiveness
inline bool dcgOpenPerverse()
    { return true; }

// Events: encounters as events occur wherever the PCs are - place the
// dragon's lair in their path when wanted, with logic
inline bool dcgOpenEvents()
    { return true; }

// the time-management shortcut: ask players ahead what they feel like doing
// the next few sessions - general answers leave the details to you
inline bool dcgOpenAskPlayers()
    { return true; }

// large-scale background conflicts anchor the open campaign: wars (meeting
// the principals on each side) and disasters - the endless winter, the plague
// of man-eating plants - as continuing threads
inline bool dcgOpenBackgroundConflicts()
    { return true; }

// ---- the matrix campaign section ----

// the matrix campaign allows a detailed story with developed plot while the
// players still choose where they go and how they deal with challenges
inline bool dcgMatrixDefines()
    { return true; }

// the key is a goal or series of goals the PCs are motivated to accomplish; a
// compromise between linear and open, effective for epics or strings of
// connecting stories
inline bool dcgMatrixGoals()
    { return true; }

// the matrix opening: a chosen location, a short exposition and clues opening
// options - the evil cleric sect with arrested peasants and raided temples
inline bool dcgMatrixExposition()
    { return true; }

// the next move is up to the players with guidance: the temple to the north,
// the great temple of good to the east, the peasants enslaved to the south -
// the headquarters to the west bided
inline bool dcgMatrixGuidance()
    { return true; }

// be prepared for a few courses of action: the temple raid, the sage
// interview, the prisoner rescue mission
inline bool dcgMatrixPrepared()
    { return true; }

// expand the matrix or point the clues toward the heart: the rescued
// prisoners led as an army, the good temple sending a quest for the item of
// great power
inline bool dcgMatrixExpand()
    { return true; }

// all the branches eventually steer the PCs toward the headquarters where the
// story's climax takes place
inline bool dcgMatrixBranches()
    { return true; }

// to move the plot along, schedule events wherever the PCs are: significant
// NPCs, visions and dreams, social or political changes, quick scenes showing
// a pertinent fact
inline bool dcgMatrixPlotEvents()
    { return true; }

// a matrix campaign must eventually meet a border beyond which the PCs are
// discouraged from passing - soft or hard
inline bool dcgMatrixBorders()
    { return true; }

// the soft border turns the PCs back through their own motivations: the
// hapless waifs appealing to decency, the mysterious stranger's gems for
// evidence of the sect's destruction
inline bool dcgMatrixSoftBorder()
    { return true; }

// the hard boundary for the unyielding: a cliff, stormy sea, or trackless
// desert, an army with escalating encounters; quest or geas spells only as a
// last resort
inline bool dcgMatrixHardBorder()
    { return true; }

// the matrix should hold several approaches to the final encounter and
// several means of dealing with it - never doomed for a wrong choice
inline bool dcgMatrixMultiplePaths()
    { return true; }

// prepare for players who have no idea what is going on: gently but firmly
// show the path - the henchman speaking up, the wise sage in plain language
inline bool dcgMatrixLostPlayers()
    { return true; }

// foreshadowing shows whether the PCs are on the right track - ill omens do
// not discourage but can indicate the way
inline bool dcgMatrixForeshadowTrack()
    { return true; }

// ---- the running the game head section ----

// the DM's second responsibility begins at the table: presenting the story so
// the PCs are drawn in through their own motivations, and refereeing the
// mechanics so they move the story along rather than hinder it
inline bool dcgRunningDefines()
    { return true; }

// ---- the preparing for play section ----

// the NPC-name list: eight names provide most of the new NPCs encountered in
// a gaming session
inline int dcgNPCNameTable()
    { return 8; }

// the NPC-name roll: roll 1d8 (or select) from the list when someone is met
inline int dcgNPCNameDie()
    { return 8; }

// the THACO example: an ogre with 4+1 Hit Dice strikes an AC 0 opponent on a
// roll of 15 or better
inline int dcgOgreTHACO()
    { return 15; }

// the more preparation time, the smoother the game; streamlining with lists
// when time is short
inline bool dcgPrepSmoother()
    { return true; }

// the random-generation lists: eight NPC names (roll 1d8), personality
// traits, and appearance characteristics - a ready-made expandable NPC
// generation system
inline bool dcgPrepLists()
    { return true; }

// the coded notes: AC, HD, hp, MV, and damage for encounters; your own maps
// and symbols for areas - the fewer words the better
inline bool dcgPrepCodedNotes()
    { return true; }

// THACO - To Hit Armor Class 0 - recorded per monster and NPC, frees you from
// consulting the combat tables during play; subtract the foe's AC from the
// THACO
inline bool dcgPrepTHACO()
    { return true; }

// develop map symbols for new location types - the more information on the
// map, the better the descriptions (the mapping section, p. 114)
inline bool dcgPrepMapSymbols()
    { return true; }

// anticipate unexpected PC actions: one or two surprises thought through can
// save the story line - steer the PCs back or expand the adventure in their
// direction
inline bool dcgPrepSurprises()
    { return true; }

// treasure placement decisions are too important for the last minute: the
// wealth placed, the magic items' impact on balance, the challenge matched to
// the value
inline bool dcgPrepTreasure()
    { return true; }

// ---- the master storyteller section ----

// the storyteller role is most obvious during play: describing settings,
// running the many NPCs, springing dramatic surprises - the listeners'
// involvement drives it home
inline bool dcgStorytellerDefines()
    { return true; }

// storytelling improves by applying proven principles, incorporated with no
// advance preparation
inline bool dcgStorytellerPrinciples()
    { return true; }

// pace affects both game mechanics and story development - the minutes per
// melee and the story rate are functions of pace, under the DM's great
// control
inline bool dcgPaceDefines()
    { return true; }

// pace variety: moments of dramatic suspense and intensity broken by periods
// of rest and security for discussing options and making plans
inline bool dcgPaceVariety()
    { return true; }

// discard rules that significantly slow the pace - streamlined versions or
// simple DM decree
inline bool dcgPaceDiscardRules()
    { return true; }

// Weapons vs. Armor Class Modifications and detailed spell-component
// recording suit detail-lovers; role-playing-centered players may proceed
// smoothly without them
inline bool dcgPaceOptionalSystems()
    { return true; }

// preparation gives pace control - detailed notes prevent wasted thought
// during the game and snap decisions that destroy the campaign's balance
inline bool dcgPacePreparation()
    { return true; }

// review the pertinent rules before critical situations: a complicated new
// monster, or a watery environment's swimming and boating rules
inline bool dcgPaceRulesReview()
    { return true; }

// voice is the DM's primary tool - information, mood, and the emotions of
// surprise, anger, triumph, and fear; tone, volume, rate, and word choice
inline bool dcgVoicePrimary()
    { return true; }

// tone conveys many emotions best: the aura of sadness for the tragically
// abandoned ruin, the laughter and jolliness of the friendly inn
inline bool dcgVoiceTone()
    { return true; }

// volume conveys the sudden and shocking, but beware overdoing it - a loud
// outburst is only effective if unexpected
inline bool dcgVoiceVolume()
    { return true; }

// vary the rate of speech for intensity - the occasional pause lets listeners
// absorb an impact or ponder the unknown
inline bool dcgVoiceRate()
    { return true; }

// colorful word choice through practice and reading - 'The door crashes
// inward in a blast of splinters!'; written passages read aloud before use
inline bool dcgWordChoice()
    { return true; }

// develop a variety of NPC voices - old men, women, children, witches,
// pirates, greedy merchants, suspicious guards, gloating villains, heroic
// leaders - augmented by facial expressions and hand gestures
inline bool dcgNPCVoices()
    { return true; }

}   // namespace rules
