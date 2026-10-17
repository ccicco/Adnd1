// =========================================================================================
// Adnd1 - rules/dsgcamp3.h
// THE DSG PLOT AND COUNTERPLOT, R552: printed pp. 103-106 (pdf 104-107) - the
// storytelling doctrine: the chapter head (the story just as important as the
// world setting, perhaps the most important campaign element; the DM as bard
// or storyteller creating heroic fantasy with a few imaginative players, many
// DMs leaving room for improvement); The Story Structure (unchanged since
// writing developed, the ancient hearth storytellers exploiting it; the
// exposition introducing location and circumstances with main-conflict hints,
// arousing curiosity and motivating participation; the development with its
// gradual plot learning and rising tension, long stories carrying several
// climaxes; the climax resolving the major conflicts, the showdown with the
// evil source, satisfactory only after lesser challenges lead closer; the
// denouement as short retrospection - victors spoils, vanquished losses, PCs
// asking questions, basking in glory; all elements present with the timing to
// the storyteller); Exposition (the long-NPC-speech mistake boring the
// players into a bad start; the acted-out encounter with questions; the maps,
// characters and documents handouts; involvement beating passive reception;
// the information cards read aloud with the format fit - the parliament
// speaker roles - kept as references; the immediate combat opener especially
// for Adventurer-types, forcing teamwork, the attackers revealing vague clues
// during the attack or through prisoner confessions; combat before the
// speech, players more willing to listen; the between-session advance
// information a few days ahead for ahead-of-time plans); Development
// (occupying more game time than all other elements combined, ideally
// multiple techniques; the minion encounters teaching the opposition -
// creature types, enthusiasm, training and equipment, motivation to serve the
// master; the noncombat prods - sages, seers, beggars, puzzling notes,
// cipher-concealed maps; not all development encounters advancing the plot,
// the random encounters as sudden challenge and combat, feedback deciding
// when combat is needed; combat eventually pointing to the climax, a
// semi-climactic encounter for the final combat of the evening making each
// session a short story); Climax (careful planning with game balance the
// primary requirement, no fiddling, the intelligently-run PCs holding a
// reasonable chance with escape possibilities on failure; more than a
// straight melee - mental with the physical, facing the adversary who
// controlled the evil forces, typically in its lair but not necessarily; the
// possibility of claiming character lives even in victory, no character
// needing to perish but sufficient challenge requiring deadly potential; the
// adversary tactics tailored to leader intelligence, the fight as important
// to them, the special aid against well-equipped PCs, the emergency escape
// route - neither villains nor heroes necessarily dying, the
// always-escaping-villain campaigns; several potential solutions, creative
// responses allowed, more than one route to success; the staging with
// dramatic visual effects, perilous terrain, portentous occasion - the evil
// temple or the fiery-chasm bridge against the random corridor; make it
// dramatic - threatened and exhilarated, tense with the outcome in doubt to
// the end, failure still significant unless through poor play or lack of
// cooperation, the key goal that everybody has fun); Denouement (tying up
// loose ends; perusing the foe's area, the choice magic item or two, the
// clues answering questions, the rescued grateful prisoners; the time of
// safety, the minor encounter anticlimactic, the arrogant PCs surprised as a
// reminder, nothing cast in stone; the next-adventure lead, the related
// adversary, avoiding the inn-and-mysterious- stranger opening); Multiple
// Story Lines (more than one story at a time, tailored to the player types,
// the long-running framework with per-session stories, lines dropped and
// resumed; the sequential series sharing a grand purpose - the heroic epic, a
// single story with many episodes, the fine noble broad purpose: saving a
// world or nation, defending a god or religion, exploring a vast uncharted
// realm; the good-aligned main characters and the good-sanctioned cause, the
// participants changed usually for the better, the purpose gained at some
// cost; the years-spanning conflict, the isolated challenges as sessions, the
// level advancement, the small victories as rewards beyond gold and magic;
// the momentum demand - the session-ending plot climax, the major objective
// every 3-4 sessions; the cliffhanger with its remarkably low player
// tolerance, used rarely and only after a successful session climax; the
// periodic changes - the new epic every year or so, the occasional unrelated
// side encounter with a meaningful reward, the periodic clues that the epic
// goal grows closer); and the Story Elements head with The Villains (the
// antagonist as any blocking force including weather, most often a living
// being, possibly several; the unintelligent foes worthy of single-session
// stories, the minimal-intelligence foes more rewarding with more tactical
// options and epic length; the villain hierarchy with its minor antagonists
// and the chief's identity as an early objective, all levels attended; the
// unique villain NPCs beyond the biggest orc; the familiarization without
// confrontation - hirelings naming him, the discovered messages, the victims'
// tales; the personal confrontation relished as culmination; the bumbling
// buffoon as the low-ranking exception; the main antagonist equal to the
// party together or protected by bodyguards, traps, fortifications,
// disguises; the surviving villain - the last-minute escape, the return
// promise, the rising-from-the-dead, the future structure and built-in
// motivation, the returning villain's power increased to maintain game
// balance) and the Foreshadowing opener (the vague hints, portents, dreams
// and clues that something is going to happen; the suspense and mystery; the
// warning use with the deadly trap foreshadowed - the black-hole message
// scrawled in blood, the exact nature unrevealed, the PCs on guard; the
// Problem-Solver affinity, the variety discipline, the augury invitation -
// the section crossing the pp. 106-107 boundary and completing next round).
// census 475 -> 476.
//
// djvu lines 13327-13752 with the Capture-layer pdf 104-107 cross-read (the
// pure-python extractor, parser page = printed page). The two reads agree
// across the round; no OCR-failure cells. The two-column Capture pages
// interleave in extraction but every load-bearing claim matched
// sentence-for-sentence against the djvu. The Foreshadowing section begins on
// p. 106 and its discussion crosses onto p. 107 (the capture page break and
// the djvu page marker disagree by a few lines there) - the section pins
// whole with the boundary noted. A CLEAN-READ ROUND. A ZERO-FLIP ROUND: the
// pp. 99-113 Campaign Considerations child stays open.
//
// The campaign chapter: R550 the opener, R551 the worlds tail, R552 plot and
// counterplot; next the rest of the Story Elements pp. 107-108, the
// techniques pp. 109-112, help from the players p. 113, then the child flip.
//
namespace rules {

// ---- the climax section ----

// the climactic encounter carefully planned with game balance the primary
// requirement - no fiddling necessary; balanced so intelligently-run PCs have
// a reasonable chance of overcoming, with possibilities for escape if they
// fail
inline bool dceBalancePrimary()
    { return true; }

// the climax should involve more than a straight sword-swinging spell-casting
// melee - mental as well as physical challenges, facing the adversary who
// controlled the evil forces, typically in its lair but not necessarily
inline bool dceMentalPhysical()
    { return true; }

// a climactic encounter should include the possibility of claiming one or
// more characters' lives even if the party wins; no character need perish,
// but sufficient challenge requires a foe with deadly potential
inline bool dceDeadlyPotential()
    { return true; }

// tailor the adversary tactics to the leaders' intelligence; the fight as
// important to them as to the PCs; allow special aid against well-equipped
// PCs; the emergency escape route - neither villains nor heroes must
// necessarily die
inline bool dceAdversaryTactics()
    { return true; }

// some of the most enjoyable long-running campaigns center on PCs trying to
// finish off a powerful villain who always seems to escape at the last minute
inline bool dceEscapingVillain()
    { return true; }

// the climactic encounter should allow several potential solutions; be
// flexible with creative responses; a given encounter should have more than
// one route to success
inline bool dceMultipleSolutions()
    { return true; }

// consider the staging - dramatic visual effects, perilous terrain,
// portentous occasion; the evil temple or the bridge swaying over a fiery
// chasm beats a randomly generated corridor
inline bool dceStagingDrama()
    { return true; }

// make it dramatic: the PCs threatened and exhilarated, the outcome in doubt
// to the very end; even failure significant unless through poor play or lack
// of cooperation; the setting adds to the drama; the key goal is that
// everybody has fun
inline bool dceDramatic()
    { return true; }

// ---- the denouement section ----

// the denouement ties up loose ends: perusing the foe's area, perhaps a
// choice magical item or two, clues answering questions, the newly rescued
// grateful prisoners as sources
inline bool dceLooseEnds()
    { return true; }

// a time of safety - the major foe overthrown, a minor encounter
// anticlimactic; not cast in stone: overly arrogant PCs can receive a sudden
// surprise attack as a reminder of their limitations
inline bool dceSafety()
    { return true; }

// the denouement often provides information leading to the next adventure -
// the related adversary keeping the plot moving, avoiding the same old
// gathered-at-the-inn mysterious-stranger opening
inline bool dceNextAdventure()
    { return true; }

// ---- the development section ----

// development occupies more game time than all other structural elements put
// together; ideally the DM employs more than one technique
inline bool dceDevelopmentLongest()
    { return true; }

// encounters bearing a relationship to the primary villain develop the story
// - battling the foe's minions teaches the opposition: creature types,
// enthusiasm, training and equipment, motivation to serve the master
inline bool dceMinionsTeach()
    { return true; }

// sages, seers, beggars and other NPCs serve as gentle prods toward the right
// direction; puzzling notes and cipher-concealed maps provide clues
inline bool dceNoncombatProds()
    { return true; }

// not all developmental encounters need advance the plot; random encounters
// create sudden challenge and combat; feedback decides when a combat
// encounter is necessary
inline bool dceRandomBalance()
    { return true; }

// combat eventually points the characters toward the climax; arrange a
// semi-climactic encounter for the final combat of the evening, making each
// gaming session a short story in its own right
inline bool dceSemimax()
    { return true; }

// ---- the exposition section ----

// the common mistake: a long detailed NPC speech the PCs must sit through and
// obey - players almost always find it boring and the DM is off to a bad
// start
inline bool dceSpeechMistake()
    { return true; }

// instead of reading an introduction, act out an encounter with an important
// NPC, giving players the opportunity to ask questions
inline bool dceActOutEncounter()
    { return true; }

// distribute maps, characters, documents, or other handouts to the players
inline bool dceHandouts()
    { return true; }

// PCs involved in the exposition enjoy it much more than passively receiving
// the same information
inline bool dceInvolvementBeatsPassive()
    { return true; }

// the information cards read aloud at the game's start, the players
// introducing each other to the story; the format fit - each player assuming
// a speaker's role at a parliament or town council; the cards kept as handy
// references
inline bool dceInformationCards()
    { return true; }

// engage the PCs in a combat encounter immediately - especially effective
// with Adventurer-types; it forces teamwork and immediate involvement; the
// attackers reveal vague clues during the attack or through prisoner
// confessions
inline bool dceCombatOpener()
    { return true; }

// after a combat encounter the DM can spend more time on exposition; precede
// the long speech with combat - players more willing to listen
inline bool dceCombatBeforeSpeech()
    { return true; }

// when players and DM can communicate between sessions, provide expository
// information a few days ahead; the players make plans ahead of time
inline bool dceAdvanceInformation()
    { return true; }

// ---- the foreshadowing section ----

// foreshadowing means vague hints, portents, dreams, or other clues that
// something is going to happen; it builds suspense and increases mystery
// while familiarizing players with the obstacles in their path
inline bool dceForeshadowDefines()
    { return true; }

// foreshadowing as warning: a very deadly trap's existence and some means of
// recognizing it foreshadowed - the 'Beware the chamber of the black hole'
// message scrawled in blood, the exact nature unrevealed, the PCs on guard
inline bool dceForeshadowWarning()
    { return true; }

// foreshadowing is particularly effective for Problem-Solver players - many
// opportunities for challenging puzzles and riddles; vary the type (corridor
// after corridor of bloody writing loses its impact); players themselves
// invite it - an augury spell is an invitation to foreshadow
inline bool dceForeshadowPuzzlers()
    { return true; }

// ---- the multiple story lines section ----

// a good campaign usually relies on more than one story at a time, tailored
// to the player types; a long-running story frameworks the campaign while
// each session tells a story within itself; lines dropped and resumed
inline bool dceMultipleLines()
    { return true; }

// sequential stories sharing one grand purpose emulate the heroic epic: a
// single story with many episodes, each interrelated adventure bringing the
// fine noble purpose closer - broad scope like saving a world or nation,
// defending a god or religion, exploring a vast uncharted realm
inline bool dceEpicForm()
    { return true; }

// epic main characters are traditionally good-aligned; the grand purpose
// good-sanctioned; participants often changed for the better; the purpose, if
// achieved, gained at some cost to the heroes
inline bool dceEpicGood()
    { return true; }

// an epic provides an overriding conflict lasting years of play; the isolated
// challenges make ideal one-or-several-session adventures; PCs advance in
// level; the small victories become rewards beyond gold and magical items
inline bool dceEpicYears()
    { return true; }

// an epic must move along or the goal seems unattainable; the objectives
// challenging and dramatic; each session ideally ends with some sort of plot
// climax
inline bool dceEpicMomentum()
    { return true; }

// a major objective accomplished every 3-4 sessions, the minimum
inline int dceObjectiveSessionsMin()
    { return 3; }

// a major objective accomplished every 3-4 sessions, the maximum
inline int dceObjectiveSessionsMax()
    { return 4; }

// the cliffhanger alternative places the PCs in an unresolved predicament;
// players have remarkably low tolerance, so use it rarely and only after a
// successful session climax
inline bool dceCliffhangerRare()
    { return true; }

// keep the game exciting: a new epic every year or so; the occasional side
// encounter unrelated to the epic but carrying a meaningful reward; periodic
// clues showing the epic goal gradually growing closer
inline bool dcePeriodicChanges()
    { return true; }

// keep the game exciting with periodic changes: create a new epic every year
// or so
inline int dceEpicRefreshYears()
    { return 1; }

// ---- the story structure section ----

// the story designed for the players is just as important as the world
// setting; the story line may be the most important element in the campaign
inline bool dceStoryEqualWorld()
    { return true; }

// the DM's function may be viewed as a bard or storyteller creating heroic
// fantasy with a few imaginative players; many DMs leave room for
// improvement, and the suggestions improve the skill and the fun
inline bool dceDMAsBard()
    { return true; }

// standard story structure has changed little since writing developed; the
// ancient hearth storytellers understood and exploited it; the wise DM uses
// the time-honored technique
inline bool dceStructureAncient()
    { return true; }

// the exposition introduces location and circumstances, often hints the
// story's main conflict, arouses the players' curiosity and motivates them to
// take part
inline bool dceExpositionDefines()
    { return true; }

// development lets the players gradually learn the plot with rising tension
// as the stakes or danger become clear; a long story should have several
// climaxes along the way
inline bool dceDevelopmentTension()
    { return true; }

// the climax resolves one or more major conflicts - the showdown between the
// PCs and the evil source they faced; satisfactory only after the characters
// overcame lesser challenges leading closer
inline bool dceClimaxDefines()
    { return true; }

// the denouement is a short retrospection: victors enjoy spoils and review
// accomplishments, the vanquished count losses; the PCs ask questions,
// basking in glory before the next challenge
inline bool dceDenouementDefines()
    { return true; }

// all the structural elements should be present in a DM's story; the exact
// timing and placement is left to the storyteller's judgment
inline bool dceAllElementsPresent()
    { return true; }

// ---- the villains section ----

// the antagonist is any force blocking the PCs' goals - weather or natural
// phenomena included - most often a living being, possibly represented by
// more than one creature
inline bool dceAntagonistAnyForce()
    { return true; }

// unintelligent foes - a marauding band of cave bears - make worthy opponents
// for short, single-session stories
inline bool dceUnintelligentFoes()
    { return true; }

// a foe of at least minimal intelligence is more interesting and rewarding,
// presenting many more tactical options and supporting stories of
// considerable, even epic, length
inline bool dceMinimalIntelligence()
    { return true; }

// long stories and epics need a villain hierarchy: early adventures against
// minor antagonists, learning the chief bad guy's identity a rewarding early
// objective; attend to all levels, not just the top
inline bool dceVillainHierarchy()
    { return true; }

// make villains unique NPCs - the orc chieftain developed beyond 'the biggest
// orc in the dungeon', with unique appearance and personality characteristics
inline bool dceUniqueVillains()
    { return true; }

// familiarize the PCs with the villain without confrontation: hirelings
// naming him in combat or captivity, discovered messages revealing his
// nature, victims' tales of terror and woe
inline bool dceFamiliarization()
    { return true; }

// familiarization adds the personal touch making the final confrontation very
// exciting - an individual sought over time and relished as culmination, not
// miscellaneous monsters
inline bool dcePersonalConfrontation()
    { return true; }

// not all villains need be menacing foci of evil power - a bumbling buffoon
// can occasionally serve as an effective low-ranking villain
inline bool dceBuffoon()
    { return true; }

// the main antagonist should be equal in power to the party of PCs taken
// together, or protected by an extensive series of bodyguards, traps,
// fortifications, or disguises; vanquishing him a challenging and dangerous
// encounter
inline bool dceMainVillainPower()
    { return true; }

// the villain need not be slain to be vanquished: the last-minute escape
// leaving henchmen and holdings in shambles with a promise to return, or even
// returning from the dead; a ready-made future structure and built-in
// motivation; the returning villain's power increased to maintain the
// established game balance
inline bool dceVillainSurvives()
    { return true; }

}   // namespace rules
