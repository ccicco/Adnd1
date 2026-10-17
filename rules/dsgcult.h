// =========================================================================================
// Adnd1 - rules/dsgcult.h
// THE DSG CULTURES OF THE UNDERDARK, R532: printed pp. 73-74 (pdf 74-75) -
// the third DM-section child: the values and objectives frame (the races
// relying less on trade and interaction than the surface races, the
// environment forcibly segregating them; trade governed more often by
// proximity than by alignment - an evil race more likely to trade with a
// nearby neutral race than a distant evil one; and the monster-encyclopedia
// referral), and the eight race write-ups: the drow (the strongly matriarchal
// society with females holding all power in government, military and home;
// the Lolth worship with the 6th-level-and-higher testing and the drider
// failures; the spider-like scorpions, pedipalp and solifugud; the
// web-pattern buildings with the traps channeling prey to the center; the
// aged-only cannibalism under population pressure; the treaty-breaking making
// alliances reluctant; and the long-term objective of ruling all subterranean
// races and controlling underworld access), the kuo-toa (the race past its
// prime struggling to retain its holdings, its inability to cooperate making
// it susceptible to conquest; the Sea Mother worship as the one unifying
// element with the holy-war dream; the 5% insanity breeding the monitor
// class; and the slave-acquiring brute force, treachery or barter), the
// duergar (the disciplined and orderly evil allowing dominance; the
// mountain-and-hill-dwarf kinship in mining and metal-and-stone work; the
// fiendish imprisoning traps with slow painful deaths; the slave labor with
// complete disregard for welfare; the mercilessness and torture love; the
// extermination over driving off to eliminate reprisal; and the
// sculpture-and-metalworking craft trade for slaves and devices), the mind
// flayers (the aboleth the only non-hostile race with the sinister-connection
// legends; the brain hunger leaving bodies to the scavengers; the racial
// quest to douse the fires of the sun itself; the probability-travel escape
// from difficult odds; the rigidly psionic-ranked society with slave labor
// and slave food; the life-form experiments with their hostile hybrids; and
// the immunity-bought-with-slaves trade and the temporary aboleth pacts), the
// aboleth (the most alien culture from the human point of view, coldly
// ruthless with torture serving no rational purpose; the intended complete
// control of the underworld beginning with the underground waters - the main
// reason for the kuo-toan waning; the obscene mind flayer pacts with the
// illithid as a temporary tool; the godless reverence of the greater aboleth,
// one to six per city at four times the size and Hit Dice, the repositories
// of the alien knowledge; and the remote casually-guarded slave cities), the
// derro (the small savage bands never in large communities, raiding near the
// surface; the chaos and intraracial violence; the stealing over working and
// the short-lived duergar and drow pacts; and the 20-year savant war cycle
// ending in utter defeat but recovered by the high reproductive rate), and
// the cloakers (the true children of the earth with the Elemental Plane of
// Earth ties; the most intelligent of their type over the lurkers, miners,
// trappers and mantari servants; the violence answering all contact attempts;
// the toolless structureless culture with its instinctive community sense;
// and the guerrilla warfare and kin-sacrificing defense)
// census 455 -> 456.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~9268-9460) with the pdf Acrobat-Capture layer as the second read (idx
// 172-174 = the printed pp. 73-74 windows; the odd image-heavy interleaves
// hold no text in Capture); the compiled-tables appendix has no reprint of
// this prose. A CLEAN-READ ROUND: both machine reads agree on every
// load-bearing number - the 6th-level Lolth test, the 5% kuo-toan insanity,
// the one-to-six greater aboleth at four times the size and Hit Dice, and the
// 20-year derro war cycle; the only garbles are the standing glyph classes
// (the FIEND FOLIO and Monster Manual II titles garbled in both layers - the
// references settled by the chapter context, Monster Manual II for duergar,
// aboleth, derro and cloakers, the Fiend Folio for drow and kuo-toa, the
// Monster Manual for illithids). SEAMS: the Fiend Folio drow and kuo-toa, the
// Monster Manual II duergar, aboleth, derro and cloakers, the Monster Manual
// mind flayer, the R530-R531 environment and geography rounds (the kuo-toan
// waning and the water dominion), and the R503 re-grain. Nothing
// auto-credits.
//
// A prose round: no tables pin. The numbers pin as consts per the R508
// convention: the 6th-level Lolth test, the 5% kuo-toan insanity, the
// one-to-six greater aboleth per city, the four-times size-and-Hit-Dice
// multiplier, and the 20-year derro war cycle. The rest pins as prose bools:
// the values-and-objectives frame and the eight race write-ups (drow,
// kuo-toa, duergar, mind flayers, aboleth, derro, cloakers). The
// FF/MM/MMII/R530-R531/R503 seams are noted; nothing auto-credits.
//
namespace rules {

// ---- the values and objectives section ----

// the Underdark races rely less on trade and interaction than surface races -
// the underground environment forcibly segregates the creatures living there;
// some trade occurs among them, and with the surface less frequently.
inline bool dncuSegregatedLessTrade()
    { return true; }

// trade is more often governed by proximity than by alignment: an evil race
// would most likely trade with a nearby neutral race than with a more distant
// evil race.
inline bool dncuProximityOverAlignment()
    { return true; }

// each major race is covered in detail in TSRs monster encyclopedia; this
// section expands on the material previously presented, especially as regards
// the societies and cultures of these races.
inline bool dncuMonsterGuideReferral()
    { return true; }

// ---- the drow section ----

// drow society has developed along strongly matriarchal lines - females hold
// all positions of power and responsibility in government, the military and
// at home; males are effective fighters and can become low-level magic-users
// or clerics, but are rarely encountered unless under the command of
// higher-ranking females.
inline bool dncuDrowMatriarchal()
    { return true; }

// the drow worship the spider god Lolth and many aspects of their culture
// reflect this - spider-like creatures such as scorpions, pedipalp and
// solifugud commonly found among their communities.
inline bool dncuDrowLolth()
    { return true; }

// drow of 6th level or higher are often tested by Lolth; those that fail
// become driders - half-drow, half-spider outcasts found around the fringes
// of drow realms.
inline int dncuDrowTestLevel()
    { return 6; }

// the drow emulate spider characteristics: their buildings and cavern
// networks are often created in a web pattern, with traps channeling
// creatures toward the center of the web.
inline bool dncuDrowWebPattern()
    { return true; }

// in times of severe population pressure the drow practice cannibalism,
// weeding out the weaker members - the victims always the aged, since the
// safety of the young is very important to the drow.
inline bool dncuDrowCannibalism()
    { return true; }

// the drow culture is perhaps the most widespread and firmly entrenched of
// all underground cultures; the drow make treaties when it serves their
// interests but are quick to break them if the terms no longer seem
// advantageous - making other races reluctant to enter alliances with them.
inline bool dncuDrowTreatiesBroken()
    { return true; }

// the long-term drow objective is to rule over all other subterranean races
// and control all access to and from the underworld - unlikely in the near
// future, but the drow endorse any proposal moving them closer without
// endangering their current dominant position.
inline bool dncuDrowRuleObjective()
    { return true; }

// ---- the kuo-toa section ----

// the kuo-toa have passed their prime as a race and struggle simply to retain
// their holdings and some degree of cultural integrity - many communities
// remain, but their inability to cooperate in the face of threats makes them
// susceptible to conquest by more disciplined races.
inline bool dncuKuoToaPastPrime()
    { return true; }

// worship of the Sea Mother is the one unifying element of kuo-toan culture;
// a few of the oldest and wisest clerics dream of joining the chaotic and
// feuding factions into one mighty army and carrying forth a great holy war
// in her name - not likely, but the believers constantly work the plan
// forward.
inline bool dncuKuoToaSeaMother()
    { return true; }

// as many as 5% of all men-fish suffer from mental imbalance and are prone to
// go berserk at the slightest provocation - the cause of the kuo-toan monitor
// class.
inline int dncuKuoToaInsanePct()
    { return 5; }

// the dramatic decline of the race has resulted in the high insanity
// incidence - and the monitor class of elite kuo-toans charged with
// controlling the members of their race that succumb.
inline bool dncuKuoToaMonitors()
    { return true; }

// kuo-toans rarely trade with other races, having no industries and little to
// offer - but they are always interested in acquiring slaves and will work
// out any means to do so: brute force, treachery, or bartering a rare useful
// item.
inline bool dncuKuoToaSlaveTrade()
    { return true; }

// ---- the duergar section ----

// the duergar, or gray ones, practice their evil in a disciplined and orderly
// fashion - allowing the race to prosper and dominate where more numerous
// creatures have failed; hard workers and tenacious combatants.
inline bool dncuDuergarDisciplinedEvil()
    { return true; }

// the duergar culture resembles that of their higher cousins the mountain and
// hill dwarves: all rely heavily on mining, all skilled at working metals and
// stone; the gray dwarves are particularly adept at fiendish traps that
// imprison unwary prey and inflict slow, painful deaths.
inline bool dncuDuergarDwarfKin()
    { return true; }

// the duergar differ from their cousins in the frequent employment of slave
// labor and their complete disregard for the welfare of those slaves.
inline bool dncuDuergarSlaves()
    { return true; }

// arrayed for battle the duergar make a formidable force, known for complete
// mercilessness on the battlefield and their love of torture - captives
// unsuitable for slavery put to death in the most fiendish, macabre and
// time-consuming methods imaginable.
inline bool dncuDuergarMerciless()
    { return true; }

// the duergar seem to have no major ambitions of conquest, but fight fiercely
// to preserve what they have and to gain any appealing subterranean portion -
// usually where precious metals or gems are found outside their realms; they
// prefer to exterminate their foes rather than drive them off, eliminating
// threats of reprisal.
inline bool dncuDuergarExterminate()
    { return true; }

// many duergar become skilled craftsmen, particularly in sculpture and
// metalworking, trading their work with neighboring races for slaves and
// technological devices beyond their capabilities.
inline bool dncuDuergarCraftTrade()
    { return true; }

// ---- the mind flayers section ----

// the mind flayers are as alien and evil a race as exists in the Underdark,
// with the possible exception of the aboleth - the only other race toward
// whom the illithid are not actively hostile; ancient legends suggest a
// sinister connection between the two.
inline bool dncuIllithidAbolethLink()
    { return true; }

// the mind flayers do not pursue expansion or subjugation; any human,
// humanoid or demi-human unlucky enough to fall into their tentacles soon
// loses his brain to satisfy their fiendish hunger, his body left to the
// plentiful subterranean scavengers.
inline bool dncuIllithidBrainHunger()
    { return true; }

// the mind flayer racial goal: loathing daylight and hating the confining
// chambers, they quest to destroy that which bars them from the surface world
// - to douse the fires of the sun itself, their genius-level Intelligence and
// psionic powers giving hope of someday achieving it.
inline bool dncuIllithidDouseSun()
    { return true; }

// the mind flayers are a formidable military force, but if a battle goes
// against them they use their probability travel psionic ability to escape -
// far too practical to fight against difficult odds.
inline bool dncuIllithidPracticalRetreat()
    { return true; }

// mind flayer society is rigidly organized, with status assigned according to
// psionic ability; slaves of all human and humanoid races are employed for
// most physical tasks and used as food.
inline bool dncuIllithidPsionicStatus()
    { return true; }

// the illithid experiment with the development of life forms: their
// communities are surrounded by unidentifiable crosses between humans and
// loathsome monsters - slow, stupid and horrible, but often endowed with
// savagery, poison or other special features, and bearing no love for their
// creators.
inline bool dncuIllithidHybrids()
    { return true; }

// mind flayers trade very little, needing few material possessions; other
// races buy immunity from their raids by providing a steady supply of slaves,
// and the mind flayers and aboleth occasionally enter temporary truces or
// pacts of cooperation to achieve some mutual goal - the subjugation of a
// weak community, for example.
inline bool dncuIllithidImmunityTrade()
    { return true; }

// ---- the aboleth section ----

// from a human point of view the aboleth are doubtless the most alien
// underground culture: actions nearly always calculated to advance their race
// with no regard for others; not interested in torture since it serves no
// rational purpose, but quick to kill any creature unlikely to serve as a
// useful slave.
inline bool dncuAbolethColdlyRuthless()
    { return true; }

// the aboleth intend to eventually gain complete control over the realms of
// the underworld; most effective in water, they first attempt to hold sway
// over all underground lakes, rivers and seas - their growing power one of
// the main reasons for the waning of the kuo-toan race.
inline bool dncuAbolethWaterDominion()
    { return true; }

// the aboleth occasionally enter obscene pacts with the mind flayers, always
// to the detriment of some hapless race - but the illithid will also be
// exterminated when their time comes; for now the aboleth use them as a
// convenient tool.
inline bool dncuAbolethIllithidTool()
    { return true; }

// the aboleth are not known to worship any god, but huge and loathsome
// examples of the species command deep respect - the greater aboleth, the
// repositories of the vast alien knowledge collected by the race.
inline bool dncuAbolethNoGod()
    { return true; }

// each aboleth city has from one to six greater aboleth - huge, loathsome
// creatures commanding the deep respect of the others.
inline int dncuGreaterAbolethMax()
    { return 6; }

// the greater aboleth can be up to four times the size and Hit Dice of a
// normal aboleth; they are the repositories of the vast alien knowledge
// collected by the race.
inline int dncuGreaterAbolethMult()
    { return 4; }

// aboleth society is well ordered, the position of each individual rigidly
// defined; numerous slaves populate the cities, only casually guarded since
// the cities are usually so remote that escape is impossible.
inline bool dncuAbolethRemoteCities()
    { return true; }

// ---- the derro and cloakers section ----

// the savage little derro are found in many places throughout the Underdark
// but never in large communities, often living near enough to the surface to
// raid for slaves and food there; their society is very chaotic and
// intraracial violence is commonplace.
inline bool dncuDerroChaoticRaiders()
    { return true; }

// the derro perform little work and thus do not trade much with other races -
// they prefer to steal the possessions of others rather than make anything
// themselves; occasionally they enter an uneasy alliance with the duergar or
// the drow, but these pacts are always short lived and usually end in
// violence.
inline bool dncuDerroStealNotTrade()
    { return true; }

// once every 20 or so years the derro savants unite their race and embark
// upon a vicious war of raid and plunder - always ending in utter defeat, but
// the high reproductive rate allows recovery.
inline int dncuDerroWarYears()
    { return 20; }

// the cloakers are referred to as the true children of the earth - probably
// native to the Prime Plane but with strong ties to the Elemental Plane of
// Earth; they are the most intelligent variety of their type, which includes
// lurkers, miners, trappers and mantari, the others often accompanying them
// seemingly as servants.
inline bool dncuCloakerChildrenOfEarth()
    { return true; }

// cloakers resist all contact with other races - attempts to deal with them
// always result in violence and bloodshed.
inline bool dncuCloakerViolence()
    { return true; }

// cloaker culture appears to have little organization: they neither use tools
// nor build permanent structures, and when danger threatens a community each
// cloaker seems to sense what it should do to further the best interests of
// the community.
inline bool dncuCloakerNoTools()
    { return true; }

// cloaker territories are easily conquered by organized foes, but savage
// guerrilla warfare often convinces the conquerors to relinquish their gains;
// cloakers sacrifice their less-intelligent kin in great numbers to defeat an
// enemy.
inline bool dncuCloakerGuerrilla()
    { return true; }

}   // namespace rules
