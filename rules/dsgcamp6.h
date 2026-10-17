// =========================================================================================
// Adnd1 - rules/dsgcamp6.h
// THE DSG HELP FROM THE PLAYERS, R555: printed p. 113 - the delegation
// doctrine ending at the MAPPING YOUR SETTINGS head: the overburdened-DM head
// (many DMs concealing die rolls and secretly tracking hit points and
// statistics; the essential mystery - but the overburdened DM frustrated and
// the underoccupied players bored; the tasks depending on your desires, the
// players' maturity, and the game type; the more-allowed rule - the more
// things the players do, the smoother the game; no DM ever bored for lack of
// things to do; the supervision spectrum - tournaments and competitive
// campaigns demanding more, mature trustworthy PCs taking on
// responsibilities); Rolling Up Player Characters (usually fun, the
// cooperative party needing little DM involvement; the supervised dice rolls
// and the understood generation procedure; the time gained - the new
// campaign's final setting details, the ongoing campaign's other details; the
// new players briefed by the others, the veterans teaching classes and races
// and leading the novices, the DM left free); Providing Ideas for Adventures
// (the think-ahead tactic; the category ask between adventures - the players
// suggesting the general type, the DM the details; the drow kingdom example -
// the long underground expedition, the route to the vast realms and wealth,
// the clues leading to the dungeon entrance and the tortuous maze; the
// advance ask aligning the story with the players' desires; the live feedback
// - adjusting the story to expectations as you go); Character Class
// Responsibilities (the obligations from rules or campaign considerations,
// primarily PC responsibility; the cleric's treasure donation - fairly
// universal though varying, the thief's guild dues; the players making the
// calculations - no recording at every adventure's end; the occasional
// guildmaster or high cleric investigation made an interesting encounter, not
// bookkeeping; the spell components - the deducted money, the noted gains,
// the adjudicated purchases, the druid's quest for greater mistletoe as a
// short adventure); and Controlling Henchmen, Hirelings, and other NPCs (the
// player control unless the NPCs are taken advantage of; the DM's right to
// step in, done only when necessary; the takeover technique - imparting
// information and protecting from danger; the detailed personas - the selfish
// whiny henchman portrayed as such; the tracked locations - Olaf of the Black
// Tooth at the Shaggy Mammoth Inn remembered by the players; the
// player-stocked campaign - the assumed blacksmith, the probability by
// community size and availability) - the round closing the Campaign
// Considerations chapter's content rounds.
// census 478 -> 479.
//
// djvu lines 14726-14879 with the Capture-layer pdf 113-114 cross-read (the
// pure-python extractor, parser page = printed page). The two reads agree
// across the round; no OCR-failure cells. The Help from the Players section
// sits entirely on printed p. 113, with the MAPPING YOUR SETTINGS head
// opening p. 114 - the boundary clean in both reads. A CLEAN-READ ROUND. A
// ZERO-FLIP ROUND: the pp. 99-113 Campaign Considerations child stays open.
//
// The campaign chapter: R550 the opener, R551 the worlds tail, R552 plot and
// counterplot, R553 the story elements tail, R554 the techniques, R555 help
// from the players; next the pp. 99-113 Campaign Considerations child flip
// (zero pins, the gap report IN the git add), then the mapping chapter pp.
// 114-127.
//
namespace rules {

// ---- the doctrine head section ----

// many DMs handle nearly all game mechanics, concealing die rolls and
// secretly tracking PC hit points and statistics - but a certain amount of
// mystery is essential to a good game
inline bool dchMysteryEssential()
    { return true; }

// the overburdened DM with underoccupied players becomes frustrated while
// they become bored
inline bool dchOverburdened()
    { return true; }

// the exact tasks the players can help with depend on your desires, the
// players' level of maturity, and the type of game you wish to run
inline bool dchTaskNature()
    { return true; }

// as a rule, the more things you allow the players to do, the more smoothly
// your game progresses - no DM was ever bored for lack of things to do during
// a gaming session
inline bool dchMoreAllowed()
    { return true; }

// tournament play or highly competitive campaigns require more DM
// supervision; mature and trustworthy PCs may take on many responsibilities
// of running the game
inline bool dchSupervision()
    { return true; }

// ---- the rolling up section ----

// rolling up player characters is usually fun; with a cooperative party, PC
// creation should require little or no DM involvement
inline bool dchRollingFun()
    { return true; }

// players may supervise each other's dice rolls, and you should be sure they
// understand which PC generation procedure the campaign uses
inline bool dchRollingProcedure()
    { return true; }

// the time gained at a new campaign's start adds final setting details; in an
// ongoing campaign the generation time still attends to other details
inline bool dchRollingTimeGained()
    { return true; }

// new players are briefed by the others on the adventure's circumstances;
// experienced players teach the classes and races and lead novices through
// generation, leaving the DM free
inline bool dchRollingNovices()
    { return true; }

// ---- the adventure ideas section ----

// employing the players' ideas for adventures is a helpful tactic, but it
// needs thinking ahead at least to the next gaming session
inline bool dchIdeasThinkAhead()
    { return true; }

// ask between adventures or at a story line's end what type of adventure they
// would like next; the players suggest the general category, you create the
// details
inline bool dchIdeasAskCategory()
    { return true; }

// the drow kingdom example: the preference for a long underground expedition,
// the route to the vast realms and wealth, the clues leading to the dungeon
// entrance and the tortuous maze
inline bool dchIdeasDrowExample()
    { return true; }

// the tactic is handy when adventures fall flat; asking in advance aligns the
// story with the players' desires
inline bool dchIdeasInAdvance()
    { return true; }

// player feedback works during the game too - consider adjusting your story
// to meet the players' expectations as you go along
inline bool dchIdeasLiveFeedback()
    { return true; }

// ---- the class responsibilities section ----

// characters of different classes may have obligations from game rules or
// campaign considerations - primarily an area of PC responsibility, with the
// DM ensuring understanding and the occasional reminder
inline bool dchClassObligations()
    { return true; }

// the cleric's treasure donation to his deity varies per campaign but is
// fairly universal; the thief joins the local guild and donates a portion of
// his gains to its coffers
inline bool dchClassDonations()
    { return true; }

// the players make the donation calculations and inform you of the amounts -
// the DM should not record donations at the end of every adventure
inline bool dchClassBookkeeping()
    { return true; }

// an occasional investigation by the guildmaster or high cleric keeps tabs on
// the characters, made into an interesting game encounter rather than routine
// bookkeeping
inline bool dchClassInvestigations()
    { return true; }

// PCs are responsible for acquiring spellcasting components, deducting the
// money spent and noting the newly gained components; hard-to-buy components
// are adjudicated - the druid's quest for greater mistletoe as an interesting
// short adventure
inline bool dchClassComponents()
    { return true; }

// ---- the henchmen section ----

// players should control their own henchmen and hirelings unless those NPCs
// are being taken advantage of; the DM may step in and run them at any time,
// but only when necessary
inline bool dchHenchmenControl()
    { return true; }

// taking over henchman actions is a technique for imparting information to
// the players and protecting the NPCs from unusually dangerous situations;
// otherwise the players handle things well
inline bool dchHenchmenTakeover()
    { return true; }

// detail these NPCs as much as possible when generated - once a player knows
// his henchman is selfish and whiny, he portrays that NPC as selfish and
// whiny
inline bool dchHenchmenDetail()
    { return true; }

// require players to keep track of NPCs and their usual locations: Olaf of
// the Black Tooth met at the Shaggy Mammoth Inn is remembered by the players,
// not the DM
inline bool dchHenchmenTrack()
    { return true; }

// players aid in stocking the campaign with NPCs: the sought blacksmith
// assumed to exist with a persona created on the spot; when not necessarily
// present, assign a probability by community size and NPC availability and
// roll the dice
inline bool dchHenchmenStocking()
    { return true; }

}   // namespace rules
