// =========================================================================================
// Adnd1 - rules/dsgcamp.h
// THE DSG CAMPAIGN CONSIDERATIONS OPENER, R550: printed pp. 99-100 (pdf
// 100-101) - the chapter frame and the DM-facing campaign craft: the myriad
// ingredients of a successful campaign (the skilled DM with time, energy and
// the talent to communicate settings; the willing players sharing common
// goals; the hack-and-slash vs plot-structuring mismatch warning); the three
// player types - the Adventurers (combat above all, characters judged by the
// magic they bring to bear, slain characters quickly replaced, treasure alone
// enough to draw them underground, the easiest gamers to DM for, kept fresh
// by clever monster tactics, monster variations, wronged-monster retribution,
// varied treasure hiding, limited magic items with odd twists and
// restrictions, planning-gated major encounters, difficult character recovery
// with no instant death and several chances for drama, and the veterans'
// occasional return), the Problem-Solvers (the campaign as a great puzzle,
// the twisted and convoluted plot the better, battles only as tactical
// problems, rules creativity demanding a creative and consistent DM, the
// routine fatigue, the challenge balance - hard enough to challenge, easy
// enough to solve with effort - the borrowed tricks and traps, the motivating
// backgrounds with player-devised objectives, the random encounters as
// mysteries and clues, the carefully defined NPCs with motivations, and the
// mystery story line relished clue by clue), and the Role-Players (every
// character detail down to ancestry and minor possessions, the full shopping
// role-play with the copper-piece haggling, adventures as growth
// opportunities, the believability faults, the personality and motivation
// discipline, the NPC and PC interaction with talking over force, and the
// personal-stakes motivations - the family name, the vengeance, the kidnapped
// loved one, anything the characters value); Challenges for the DM (most
// players a blend of the three with one emphasis; the successful campaign
// challenges all three); the Fine Art of Juggling (the tailored fun for
// single-type groups, the juggling for mixed groups, the feedback key -
// watching and listening, the facial expressions - the restless-Adventurer
// random encounter, the dying-bandit clue and the search-discovery juggle for
// the Problem-Solvers, the talk-to-each-player cadence reading between the
// lines, the boredom signal, the per-style rewards keeping the game fresh);
// Designing the Adventure and the World (the settings and the story line as
// the other crucial ingredients, the setting definition - the locations, the
// denizens, their relationships - the deferred orc detail, the rough story
// sketch drawing all types, the no-total-advance-preparation rule with its
// semblance techniques, the preparation payoff and the anticipated-conflicts
// stability); and Worlds of Adventure: The Importance of Setting (the DM's
// unique creation as a blend of factors, the scope determined first, the
// surface-minimal underground campaign with its surface base for
// surface-dweller PCs, the dungeons-caverns-realms scope and relationships
// with the consistent captured-deep-dweller answers, the deferred race
// placements - the drow here, the duergar there, later - with races easy to
// add and hard to remove, and the social-structure split: the admittedly
// unrealistic clearly-defined good and evil, easier to design with
// friend-and-foe ease, against the complex realistic societies with good and
// evil opposed within the same society).
// census 473 -> 474.
//
// djvu lines 12711-13012 with the Capture-layer pdf pages 99-100 cross-read
// (the staging rebuild used a pure-python Capture-layer extractor - no
// poppler in the sandbox - reading the Tj/TJ text layer of the same IA pdf,
// with the parser page number equal to the printed page). The two reads agree
// across the round; the one settled garble: the djvu OCR prints NPC as NPO
// twice (settled as NPCs by the Capture read). The societies contrast
// sentence breaks across the pp. 100-101 page boundary - the contrast pins
// whole with the break noted here. The three-types taxonomy confirmed by the
// Capture read ('Most players fit into one of three general types:
// Adventurers, Problem Solvers, or Role-Players'). A CLEAN-READ ROUND. A
// ZERO-FLIP ROUND: the pp. 99-113 Campaign Considerations child stays open
// until the whole chapter lands (challenges p. 100, juggling p. 100,
// designing p. 100, plot and counterplot pp. 103-106, techniques pp. 109-110,
// running the game pp. 111-113).
//
// The campaign chapter: R550 the opener, the rest of Worlds of Adventure pp.
// 101-103, plot and counterplot pp. 103-106, the techniques pp. 109-112, help
// from the players p. 113, then the child flip.
//
namespace rules {

// ---- the Adventurers section ----

// Adventurers enjoy combat above all other types of gaming activities
inline bool dccCombatSupreme()
    { return true; }

// Adventurers prefer adventures where the obstacles are physical and
// dangerous and must be overcome by force
inline bool dccPhysicalObstacles()
    { return true; }

// Adventurers judge characters on the magical bonuses brought to bear in
// combat, not on deep moral or philosophical concerns
inline bool dccMagicBonusJudge()
    { return true; }

// slain Adventurer characters are replaced quickly, the disappointment being
// the lost magical items
inline bool dccQuickReplacement()
    { return true; }

// Adventurer characters are usually motivated to enter a dungeon simply by
// the prospect of treasure to plunder
inline bool dccTreasureDraws()
    { return true; }

// the Adventurer is the easiest gamer to DM for: a few monsters of increasing
// toughness with hoarded treasure entertains the group for weeks
inline bool dccEasiestToDM()
    { return true; }

// keep Adventurers fresh: clever monster tactics played intelligently, new
// variations on easily-overcome monsters (poison, magic use), and retribution
// sought by wronged monsters
inline bool dccMonsterIntelligence()
    { return true; }

// vary the treasure-hiding approaches; limit the number of magical items;
// potent items carry odd twists and restrictions - limited charges, or
// operation only in a particular environment
inline bool dccItemDiscipline()
    { return true; }

// PCs should not succeed at major encounters unless they use careful planning
inline bool dccPlanningGatesSuccess()
    { return true; }

// make recovering slain characters difficult, but avoid instant death
// situations - drama and tension increase when a character has several
// chances to avoid a terrible fate
inline bool dccNoInstantDeath()
    { return true; }

// even experienced gamers who generally play in the other categories
// occasionally enjoy a return to the Adventurer style of play
inline bool dccVeteranReturn()
    { return true; }

// ---- the Challenges for the DM section ----

// most players represent a blend of the three types with an emphasis in one
// area; the categories are useful for determining the general thrust of the
// game
inline bool dccBlendTypical()
    { return true; }

// a successful campaign must provide challenges for all three types of
// players
inline bool dccAllThreeServed()
    { return true; }

// ---- the Designing the Adventure and the World section ----

// the other crucial ingredients the DM must provide are the settings and the
// story line for the campaign
inline bool dccTwoIngredients()
    { return true; }

// settings include all locations the PCs are allowed to adventure in, the
// NPCs and creatures that may be encountered there, and the relationships
// among the denizens of the dungeon
inline bool dccSettingDefinition()
    { return true; }

// not all items need great detail at the beginning - 'orcs live here'
// suffices, with the hows and whys worked out later, presumably before the
// PCs decimate the orcs
inline bool dccDeferredDetail()
    { return true; }

// a story line should be roughly worked out ahead of time; a good story can
// draw all types of players into a game
inline bool dccStorySketch()
    { return true; }

// neither the story nor the setting must be prepared entirely in advance -
// the techniques give the players the semblance of a thoroughly designed
// world while letting the DM create features as the campaign develops
inline bool dccNoAdvanceRequirement()
    { return true; }

// the underground game benefits from careful preparation - the more time the
// DM spends in preparation, the better the result is likely to be
inline bool dccPrepPays()
    { return true; }

// anticipated conflicts and locales mean fewer on-the-spot decisions,
// maintaining the players' impression of a consistent and reasonably
// believable fantasy world
inline bool dccAnticipatedStability()
    { return true; }

// ---- the Fine Art of Juggling section ----

// all-Adventurer groups want a series of challenging, exciting action
// encounters with appropriate rewards; all-Role-Player groups want
// interesting NPCs and opportunities for interaction
inline bool dccTypeTailoredFun()
    { return true; }

// groups of more than one basic type need juggling to make sure each player
// is entertained
inline bool dccMixedJuggling()
    { return true; }

// the key to successful juggling is feedback - information gained by watching
// and listening to players; boredom and frustration show in the facial
// expressions while the adventure runs
inline bool dccFeedbackKey()
    { return true; }

// restless Adventurers while the Role-Players enjoy a chance meeting: time
// for a random encounter
inline bool dccRestlessRandom()
    { return true; }

// challenge Problem-Solvers inside the same encounter - a bandit expiring
// murmurs an obscure clue to the party's mystery, or an unusual observation
// or search discovery
inline bool dccDyingClue()
    { return true; }

// make it a point to talk to each player every few minutes, listening
// carefully to the responses, reading between the lines if necessary
inline bool dccTalkRegularly()
    { return true; }

// any time a player sounds listless or bored, it is time to juggle something
// challenging into their path
inline bool dccBoredomSignal()
    { return true; }

// the key: reward players for each style of play during an encounter - the
// variety of player types and DM challenges keeps the game fresh and inspired
inline bool dccRewardEachStyle()
    { return true; }

// through successful juggling a campaign including players of all three types
// can be run smoothly
inline bool dccSmoothAllThree()
    { return true; }

// ---- the Problem-Solvers section ----

// Problem-Solvers see the campaign as a great puzzle, their purpose to put
// all the pieces together
inline bool dccPuzzleFrame()
    { return true; }

// for Problem-Solvers the story becomes very important - the more twisted and
// convoluted the plot, the better
inline bool dccConvolutionBest()
    { return true; }

// battles interest Problem-Solvers only from the standpoint of the tactical
// problems they present
inline bool dccTacticalBattles()
    { return true; }

// Problem-Solvers are very creative with the rules, devising new equipment
// and magical items, and require a DM who is creative and consistent
inline bool dccRulesCreativity()
    { return true; }

// Problem-Solvers are enthusiastic about unique, challenging sessions and
// quickly tire of routine campaigns - tough to referee, bored with anything
// that does not seem new
inline bool dccRoutineBoredom()
    { return true; }

// Problem-Solver adventures must be hard enough to be challenging, but easy
// enough to be solved with sufficient effort
inline bool dccChallengeBalance()
    { return true; }

// do not hesitate to borrow tricks, traps, and encounter ideas from books and
// other sources
inline bool dccBorrowFreely()
    { return true; }

// give PCs motivating backgrounds, let players devise their own objectives,
// use random encounters to present mysteries and clues, and define NPCs with
// care and motivations
inline bool dccMotivationToolkit()
    { return true; }

// Problem-Solvers relish a story line presenting a mystery, eagerly seeking
// clues and assembling plot elements; the course-of-action debates are great
// fun for all concerned
inline bool dccMysteryStory()
    { return true; }

// ---- the Role-Players section ----

// Role-Players enjoy creating every detail of their characters' lives, down
// to ancestry and minor possessions
inline bool dccTotalDetail()
    { return true; }

// Role-Players want to role-play the whole shopping experience, haggling over
// copper pieces with the shopkeeper
inline bool dccShoppingRoleplay()
    { return true; }

// Role-Players view adventures as opportunities for their characters to grow,
// sometimes developed to almost painful detail
inline bool dccGrowthFrame()
    { return true; }

// Role-Players almost always include one or more faults among their PCs'
// characteristics, adding believability
inline bool dccBelievableFaults()
    { return true; }

// each PC's personality matters - players react as their characters would;
// Role-Players enjoy interaction with NPCs and other PCs and often talk their
// way out of problems others solve with force
inline bool dccInteractionTalk()
    { return true; }

// for Role-Players the adventure motivation must be something important to
// the characters
inline bool dccPersonalStakes()
    { return true; }

// anything affecting what the characters value sends them into the dungeon:
// the family name hoisted to glory or saved from the mud, vengeance for harm
// suffered, rescuing a kidnapped person close to them
inline bool dccValueHooks()
    { return true; }

// ---- the Worlds of Adventure section ----

// a campaign world is a DM's unique creation - much work, great enjoyment;
// successful world design is a blend of many factors
inline bool dccUniqueCreation()
    { return true; }

// the scope of the campaign must be determined first, so the DM knows what to
// define
inline bool dccScopeFirst()
    { return true; }

// an underground campaign requires little detailing of surface continents,
// seas, and nations; a city, town, or village base is still necessary if the
// PCs are surface dwellers
inline bool dccSurfaceMinimal()
    { return true; }

// with many dungeons, connecting caverns, and underground realms, the DM must
// determine their general scope and relationships - whether realm creatures
// visit the dungeons, what civilizations lie deep
inline bool dccRelationshipScope()
    { return true; }

// those questions need not be answered in great detail, but considered - so a
// captured deep-dweller gets consistent answers under interrogation
inline bool dccConsistentCaptives()
    { return true; }

// at first it is not even necessary to place races exactly - 'the drow over
// here, the duergar down there' can wait; as long as the race types are
// known, exact locations can be assigned later
inline bool dccPlacementDeferred()
    { return true; }

// more races can be added later as the game develops
inline bool dccRacesAddLater()
    { return true; }

// it is much more difficult to remove a race that has been thoughtlessly
// located somewhere, so consider these placements carefully
inline bool dccRemovalHard()
    { return true; }

// the general social structure of the campaign setting also requires thought
inline bool dccSocialThought()
    { return true; }

// societies of clearly defined good and evil alignments and practices are
// admittedly unrealistic, but easier and less time-consuming to design, and
// let players identify friend and foe with relative ease
inline bool dccClearSplitEasy()
    { return true; }

// complex realistic societies put good and evil in opposition within the same
// society, requiring players to carefully plan and implement their
// interactions
inline bool dccComplexRealistic()
    { return true; }

// ---- the campaign frame section ----

// the three general player types: Adventurers, Problem Solvers, Role-Players
inline int dccPlayerTypes()
    { return 3; }

// the ingredients of a successful campaign are myriad and cannot be
// exhaustively listed; even the most experienced DM benefits from other
// referees' experience
inline bool dccIngredientsMyriad()
    { return true; }

// the most important ingredient: a skilled DM with the time and energy to
// carefully define and create his world, and the talent to communicate
// settings effectively
inline bool dccSkilledDMFirst()
    { return true; }

// the next most important ingredients: willing players who share common goals
// with the DM
inline bool dccWillingPlayersNext()
    { return true; }

// players interested in hack-and-slash should not be matched with a DM
// interested in careful plot structuring and detailed mystery solving
inline bool dccTypeMismatch()
    { return true; }

}   // namespace rules
