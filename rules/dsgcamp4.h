// =========================================================================================
// Adnd1 - rules/dsgcamp4.h
// THE DSG STORY ELEMENTS TAIL, R553: printed pp. 107-108 - the foreshadowing
// tail (the variety principle - corridor after corridor of bloody writing
// loses impact; the player-given invitations, the augury casting an
// invitation to the DM for clues; dreams effective but heavy-handed; the
// fortune-teller's dire warning; the anonymous message; town rumors); Mystery
// (the unknown as a great motivator of curiosity, the answers a major
// satisfying reward; the neglected who-done-it structure used successfully;
// the secret antagonist with a dropped clue every so often - the vampire-lair
// example with bats and wolves, the slain character with the broken mirror
// and the pouchful of garlic, the fresh corpse with the distinctive fang
// marks; the campaign mysteries - the unknown parentage, the vanished
// community; the long-standing background questions with only a general idea
// needed, the intriguing hint dropped to launch a fresh story line - the
// ragged dying messenger of Eric of Calrede; the speak-with-dead caveat);
// Challenge (the challenges shaped to the players' mental and physical
// interests - combat for Adventurers with an occasional mental problem,
// negotiation for Role-Players; the player feedback; the game-balance role of
// the encounter - random and introductory encounters light, climactic and
// milestone encounters to the players' utmost limits; the Hit Dice and
// average-damage rough balance against the tactics, positions, and luck; the
// intelligent-play sufficiency with logical solutions given a chance; the
// changeable devastating die roll behind the screen); Reward (based on the
// level of accomplishment, the count tracked; the tremendous wealth or power
// destroying campaign balance; the variety of types; the during-adventure
// rewards - key clues, small treasures, needed equipment); Magical items (one
// or two permanent items per level; generous with potions and scrolls; the
// class-directed items - leather armor to the thief, the mace +3 to the
// cleric; the lid on distribution - mid-level characters armed to the teeth
// with potent magic killing the campaign; the described and named swords with
// crest or script; the Sathas Sundown and Black Tower sage; the limitations
// on every permanent item - the evil-fighting glowing sword, the
// flame-vulnerable wax statue; the story-part doctrine); Wealth (the taxes,
// thievery, tolls, and prices as drains; the XP for lost wealth kept; the
// low-value bulks and encumbrance; gemstones rare until a few levels; the
// spending sprees with the cleaned-out week); Discoveries (information as
// reward - advancing story lines, warning of traps; the pieced-together clues
// the key); Gratitude (the high king's debt; the sincere majority; the
// case-by-case extent - the paid rescue owing nothing, the careful evaluation
// of motivations; the explicit promises against requests; the beggar and
// barmaid favors; selfless motives binding more); Accomplishment (the
// difficult objective as its own reward for Role-Players; the good-deed
// cleric; the DM's zero effort; the immediately apparent success or failure);
// Experience Points (the DMG amounts adjustable - the troll-holding fighter;
// the landslide village earning no XP and even a penalty; the tentative
// design awards - 1,000 XP per burned pirate ship, undisclosed until after;
// the restructured award system for non-treasure objectives; the optional
// magic-item XP, never for found-and-sold items); and Moral (the
// storyteller's meaningful lesson, unnoticed if not heavy-handed; the
// actions-with-consequences doctrine; the social structure's expectations;
// the cooperation example; the killer consequences - jail, hanging, the
// fugitive ire, justice catching up; the accomplishment-merits-reward moral;
// the story-for-a-moral with its 'It's not wise to fool the king' exemplars)
// - the round ending at the TECHNIQUES OF STORY AND CAMPAIGN DESIGN head.
// census 476 -> 477.
//
// djvu lines 13752-14246 with the Capture-layer pdf 108-109 cross-read (the
// pure-python extractor, parser page = printed page). The two reads agree
// across the round; no OCR-failure cells. The djvu OCR quirks (the Cyrillic
// DM, 'moncv' for money, 'general!' for general, a broken 'an occa-') all
// settle by the capture cross-read; the two-column Capture pages interleave
// in extraction but every load-bearing claim matched sentence-for-sentence
// against the djvu. The Moral section runs to the bottom of p. 108, its tail
// sharing the capture page with the Techniques head - the boundary noted, the
// section pinned whole. A CLEAN-READ ROUND. A ZERO-FLIP ROUND: the pp. 99-113
// Campaign Considerations child stays open.
//
// The campaign chapter: R550 the opener, R551 the worlds tail, R552 plot and
// counterplot, R553 the story elements tail; next the techniques of story and
// campaign design pp. 109-112, help from the players p. 113, then the child
// flip.
//
namespace rules {

// ---- the foreshadowing tail section ----

// use variety in the type of foreshadowing; corridor after corridor of bloody
// writing soon loses its impact
inline bool dcfForeshadowVariety()
    { return true; }

// the players themselves give opportunities for foreshadowing; the casting of
// an augury is an invitation to the DM for a few clues about the future
inline bool dcfForeshadowPlayerInvitation()
    { return true; }

// dreams are an effective, albeit somewhat heavy-handed, tactic of
// foreshadowing
inline bool dcfForeshadowDreams()
    { return true; }

// the PCs could encounter a fortune-teller who pronounces a dire warning
inline bool dcfForeshadowFortuneteller()
    { return true; }

// the PCs could receive an anonymous message from some mysterious source
inline bool dcfForeshadowAnonymousMessage()
    { return true; }

// rumors picked up in town can also foreshadow events of the story
inline bool dcfForeshadowRumors()
    { return true; }

// ---- the mystery section ----

// mystery is simply the unknown; curiosity is a great motivator, and
// discovering the answers can be a major and satisfying reward for all types
// of players
inline bool dcfMysteryMotivates()
    { return true; }

// the who-done-it structure is often neglected by DMs but can be used quite
// successfully
inline bool dcfMysteryWhodunit()
    { return true; }

// keep the antagonist's identity secret for much of the game, dropping a clue
// every so often so clever players eventually identify the foe
inline bool dcfMysteryUnknownFoe()
    { return true; }

// the vampire-lair example: bats and wolves attack, a slain character with a
// broken mirror and a pouchful of garlic, a fresh corpse with the distinctive
// fang marks - the knowledge is much more chilling when gained by discovery
inline bool dcfMysteryVampireLair()
    { return true; }

// mystery as a campaign feature: the character who does not know his
// parentage, the vanished community raising questions for many sessions to
// come
inline bool dcfMysteryCampaign()
    { return true; }

// long-standing questions can lurk in the background; you need not have all
// the answers, though a general idea helps; drop an intriguing hint to launch
// a fresh story line
inline bool dcfMysteryBackground()
    { return true; }

// the dying-messenger example: the ragged battered stranger gasping out a
// message from Eric of Calrede's father before dying
inline bool dcfMysteryDyingMessenger()
    { return true; }

// if dealing with PCs who can speak with dead, a different technique is
// needed for the mystery
inline bool dcfMysterySpeakWithDead()
    { return true; }

// ---- the challenge section ----

// challenges should be shaped to fit the players' mental and physical
// interests and abilities
inline bool dcfChallengeFit()
    { return true; }

// with Adventurers rely primarily on combat encounters and physical
// challenges, but include an occasional mental problem such as a complicated
// trap or riddle
inline bool dcfChallengeCombat()
    { return true; }

// Role-Players often find negotiating sessions or conversations with NPCs
// challenging
inline bool dcfChallengeNegotiation()
    { return true; }

// pay attention to player feedback and modify game challenges accordingly
inline bool dcfChallengeFeedback()
    { return true; }

// a randomly generated encounter or introductory trap should not challenge
// the PCs too strongly, while a climactic encounter or major milestone should
// challenge the players to their utmost limits
inline bool dcfChallengeBalanceRole()
    { return true; }

// a simple comparison of Hit Dice and average damage gives rough ideas of
// encounter balance, but battles are decided by tactics, relative positions,
// and luck
inline bool dcfChallengeHDBalance()
    { return true; }

// plan encounters so that intelligent PC play is sufficient to overcome the
// challenge; logical solutions developed by the players should have a chance
// to succeed
inline bool dcfChallengeIntelligentPlay()
    { return true; }

// if you roll dice behind a screen, you always have the option of changing
// any die roll that is particularly devastating to the outcome
inline bool dcfChallengeScreenDice()
    { return true; }

// ---- the reward head section ----

// rewards should be based on the level of the PCs' accomplishments, and the
// DM should keep track of the number of rewards granted
inline bool dcfRewardAccomplishment()
    { return true; }

// characters with tremendous wealth or power can destroy the balance of an
// entire campaign, just as an excessively powerful monster destroys the
// balance of an encounter
inline bool dcfRewardBalance()
    { return true; }

// use different types of rewards for different types of accomplishments, and
// do not neglect any one type in deference to the others
inline bool dcfRewardVariety()
    { return true; }

// rewards should be handed out during the adventure as well as at the end:
// key clues showing the players they are on the right track, small treasures,
// or equipment needed later
inline bool dcfRewardDuringAdventure()
    { return true; }

// ---- the magical items section ----

// the magical-item lid: no more than one or two permanent magical items
// gained per level of experience - the minimum
inline int dcfPermanentPerLevelMin()
    { return 1; }

// the magical-item lid: no more than one or two permanent magical items
// gained per level of experience - the maximum
inline int dcfPermanentPerLevelMax()
    { return 2; }

// magical items are always welcomed and can be one of the best forms of
// reward, if used sparingly; be more generous with disposable rewards such as
// potions and scrolls
inline bool dcfMagicSparingly()
    { return true; }

// choose items best utilized by deserving characters, either items usable by
// only one character class or items likely given to certain classes: leather
// armor to a thief, a mace +3 to a cleric
inline bool dcfMagicClassDirected()
    { return true; }

// keeping a lid on magical-item distribution cannot be stressed too much:
// mid-level characters armed to the teeth with potent magic kill the campaign
// and the DM's enthusiasm
inline bool dcfMagicLid()
    { return true; }

// permanent magical items should be described in detail; magical swords can
// be named, inscribed with a crest or script telling of the sword's past or
// its rightful bearer
inline bool dcfMagicDescribed()
    { return true; }

// the sage example: an old sage declares 'You carry the blade of Sathas
// Sundown! You are destined to bring down the evil of the Black Tower!' - the
// sword's destiny carrying it to a more cooperative bearer
inline bool dcfMagicSageExample()
    { return true; }

// assign limitations to every permanent item to maintain balance: a sword
// that glows in the dark and only operates fully when fighting evil, an
// animated wax statue vulnerable to flame
inline bool dcfMagicLimitations()
    { return true; }

// make magical items more than high-powered additions to the PC arsenal: a
// meaningful part of the story, advancing the story and adding to the detail
// of the campaign world
inline bool dcfMagicStoryPart()
    { return true; }

// ---- the wealth section ----

// wealth is a standard category of reward, and unlike magical items it is
// fairly easy to remove excess wealth from the PCs without long-lasting hard
// feelings
inline bool dcfWealthStandard()
    { return true; }

// balance the wealth the PCs collect with the expense they encounter: taxes,
// thievery, heavy tolls, and outrageous prices for goods and supplies reduce
// the cash characters carry
inline bool dcfWealthDrains()
    { return true; }

// experience points for wealth that is gained and then lost are granted
// normally and not lost with the money; DMs must retain a measure of control
inline bool dcfWealthXPKept()
    { return true; }

// place monetary rewards in large bulks of low-value coins such as silver or
// copper; carried fortunes encumber, and gemstones should be found only
// rarely until the characters have advanced a few levels
inline bool dcfWealthLowValueBulks()
    { return true; }

// the principle of variety applies to wealth: occasional chances to spend
// money like it's going out of style, with the characters cleaned out a week
// later and forced into adventuring for room and board
inline bool dcfWealthSpendingSprees()
    { return true; }

// ---- the discoveries section ----

// information can be an extremely effective reward: advancing story lines,
// answering players' questions, pointing out solutions, and warning about
// nasty traps or encounters
inline bool dcfDiscoveryInfo()
    { return true; }

// the key to information as a reward: not completely defined for the players
// - most valuable when they must use clues to piece it together themselves,
// adding enjoyment and familiarity
inline bool dcfDiscoveryPieced()
    { return true; }

// story details and thoroughly designed primary adversaries generate a wealth
// of information for the players to uncover as the adventure progresses
inline bool dcfDiscoveryDesign()
    { return true; }

// ---- the gratitude section ----

// NPC friendship or gratitude can reward PCs; the high king owing a debt does
// not harm a character's position, and appropriate situations grow out of the
// story; in most cases gratitude is sincere
inline bool dcfGratitudeDebt()
    { return true; }

// the extent of the benefit is case-by-case: a king who paid for a rescue may
// rule no debt is owed, while unpurchased heroism earns reward and debt;
// resolve by careful evaluation of motivations
inline bool dcfGratitudeCaseByCase()
    { return true; }

// a debt may be spelled out clearly ('Anytime you need anything, do not
// hesitate to call on me!'); without such a promise a request is less likely
// to be automatically granted, and the king may change his mind
inline bool dcfGratitudePromise()
    { return true; }

// debts of gratitude are not limited to kings and nobles: a beggar or barmaid
// spared a threat returns the favor; selfless motives bind more than
// reward-seeking ones
inline bool dcfGratitudeHumble()
    { return true; }

// ---- the accomplishment section ----

// for good players, accomplishing a difficult objective can become a reward
// in itself, particularly in a campaign with Role-Player participants
inline bool dcfAccomplishmentIntrinsic()
    { return true; }

// a Role-Player's good cleric gains a sense of reward simply from performing
// good deeds; this intangible is usually best as an occasional alternative to
// treasure and magical rewards
inline bool dcfAccomplishmentGoodDeeds()
    { return true; }

// the DM does not have to do anything other than run the adventure to
// implement this reward; create adventures challenging the PCs to acts they
// perceive as valuable, with success or failure immediately apparent
inline bool dcfAccomplishmentFree()
    { return true; }

// ---- the experience points section ----

// the tentative design award: an additional 1,000 XP for each pirate ship
// burned while on the base
inline int dcfPirateShipXP()
    { return 1000; }

// experience points are a game mechanic whose major function is to reward
// players; the primary measure of level readiness, their distribution
// requires careful DM planning and adjudication
inline bool dcfXPMechanic()
    { return true; }

// the DMG's XP amounts may always be adjusted up or down by level of play and
// accomplishments: the fighter holding off trolls single-handedly earns
// points for heroism
inline bool dcfXPAdjustable()
    { return true; }

// the landslide example: characters who wipe out an entire village to slay a
// single thief get no experience points, particularly if of good alignment -
// an XP penalty is even possible
inline bool dcfXPLandslide()
    { return true; }

// tentatively assign XP to potential PC actions as you design an adventure,
// disclosing such awards only after the adventure, rewarding ingenuity in
// thinking of the action
inline bool dcfXPTentative()
    { return true; }

// where treasure-gathering and monster-slaying are not the primary
// objectives, completely restructure the experience point award system for
// that adventure; reward good play
inline bool dcfXPRestructure()
    { return true; }

// whether to award XP for magical items discovered is each DM's decision; if
// awarded for items found and used, they should not be awarded for items
// found and sold
inline bool dcfXPMagicOptional()
    { return true; }

// ---- the moral section ----

// the moral makes many DMs uncomfortable but using it greatly strengthens a
// story line; the storyteller shares a meaningful lesson, unnoticed if not
// heavy-handed
inline bool dcfMoralStrengthens()
    { return true; }

// the moral simply put: player characters' actions should have proper
// consequences; the social structure places expectations on its members, and
// anti-social behavior meets an appropriate consequence
inline bool dcfMoralConsequences()
    { return true; }

// the most important example is player cooperation within the party: a party
// unable to agree expends more time and energy fighting each other than
// fighting monsters
inline bool dcfMoralCooperation()
    { return true; }

// societies frown upon taking innocent lives; killers must face society's
// wrath or flee it - jail terms, hanging, the ire of populace and gendarmerie
// - and justice eventually catches repeat murderers
inline bool dcfMoralKillers()
    { return true; }

// the challenge-and-reward interaction theme: the moral most DMs impart is
// that accomplishment merits reward, a lesson quickly lost among treasure
// gained at little risk or cost
inline bool dcfMoralAccomplishmentMerits()
    { return true; }

// create a story for the sake of its moral: select the message ahead of time
// and prove the point - 'It's not wise to fool the king,' 'A thief shouldn't
// flaunt his wealth in front of those he has robbed,' 'Things are not always
// as they seem'
inline bool dcfMoralStoryForMoral()
    { return true; }

}   // namespace rules
