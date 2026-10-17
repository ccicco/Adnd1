// =========================================================================================
// Adnd1 - rules/astralplane.h
// THE ASTRAL PLANE - printed pp. 60-72, the whole chapter in one round: the
// barren vault between the Primes and the outer planes - the silver cords,
// the color pools, the thought-movement, the psychic wind, the weightless
// combat, the magic limits, and the githyanki with their silver swords.
// census 499 -> 500.
//
// verified against printed pp. 60-72 of the uploaded motp.pdf OCR; the
// chapter pins carry the projection/physical travel split, the cord and pool
// mechanics, the encounter and wind tables, and the school-by-school magic
// limits exactly as printed.
//
// the gap census after this round: 53 closed, 37 open - ELEVEN boxes fall
// (the chapter parent, the eight section children, the encounter check, the
// sample charts); the outer planes general doctrine opens the final arc next.
//
namespace rules {

// ---- the astral plane pins ----

// the Astral time ratio: the effects of time slow by 365,000 to 1 (170 true
// days to one subjective round) - the slowest subjective time of all the
// known major planes; spells run their normal duration in true time; aging
// attacks (ghosts, staff of withering) have no effect.
inline int ddeTimeRatio()
    { return 365000; }

// the silver cord snap: the astral form dissolves in 1d10 turns, the Prime
// body perishes irrecoverable save wishes, artifacts return intact - but
// reaching a color pool and forming a new body before the clock runs out
// averts death; the same 1d10-turn clock rules a slain physical body (the
// cord disappears, the character dies).
inline int ddeCordDissolveTurns()
    { return 10; }

// the slain-astral-form coma: 1d4+1 (5) days, awakened only by a full wish or
// alter reality; then a system shock roll - failure is death, success wakes
// at 1 hit point, no spellcasting, half movement and -4 attacks until half
// hit points are regained WITHOUT magic (true time).
inline int ddeAstralComaDays()
    { return 5; }

// the possession danger: a 1% chance per venture into the Astral that an
// extradimensional creature (magic jar class) possesses the abandoned
// physical body - the cord is NOT cut, visible to true seeing; the owner
// cannot re-enter until the intruder leaves or is exorcised.
inline int ddePossessionPct()
    { return 1; }

// mental movement: 10 yards per minute (30 feet per melee round) per point of
// Intelligence, at will with free stops and turns; groups move at the lowest
// Intelligence; encumbrance costs 10 feet per round per 10 lbs (100 gp),
// magical items weigh nothing; physical push-off movement is the clumsy
// fallback (10 feet per round off a large object, Strength-based off small
// ones).
inline int ddeMentalMoveBase()
    { return 10; }

// the Astral encounter check: 1d10 rolled on entrance and every four true
// hours thereafter - a 1 means an encounter; type split 1-75 creature, 76-85
// color pool, 86-95 astral item, 96-00 psychic wind; pool viewing adds a 5%
// chance per check that the portal opens beside an astral-affecting native.
inline int ddeEncounterCheckHours()
    { return 4; }

// the astral conduits (wormholes): 80% have functioning gates at both ends
// (50% chance each way out, never to a plane holding the projector's body);
// the other 20% are one-way (being spun or sundered); unlike pools they reach
// the DEEPER layers - the only safe road into the lower Abyss.
inline int ddeConduitBothEndsPct()
    { return 80; }

// the conduit attraction: within 1,000 yards a wormhole pulls travelers at
// 120 yards per round; those who cannot outpace it (Intelligence 11 or less)
// are dragged in and transported; cord-severed travelers sucked in do NOT die
// - they gain a new body where they land.
inline int ddeConduitPullYards()
    { return 120; }

// the psychic wind wake: 1d4+2 (6) hours added to travel (astral) or 1d4+2
// hours unable to leave save by color pool (physical) - the 1-12 band of the
// 1d20 group roll; 13-16 lost for 2d10 true days, 17-19 cross-current (50%
// wrong pool or within 1,000 yards of a wormhole), 20 the storm - save vs.
// spell or the cord snaps.
inline int ddeWindDelayHours()
    { return 6; }

// the color pool traffic rule: only 15% of pools are two-way (movable, and so
// often eliminated or controlled); of those, 5% are FIXED portals -
// permanent, undisppellable, same spot, set exit, surface layers only;
// one-way pools vanish after passage (recreatable from the far side).
inline int ddePoolTwoWayPct()
    { return 15; }

// the astral searcher danger: a failed restoration of spirit to a body (raise
// dead, magic jar) draws a searcher at 5 times the body's previously highest
// level on percentile dice (an 18th-level magic-user's failed raise dead =
// 90%); the searcher gains the body's hit points and physical abilities but
// not its class knowledge.
inline int ddeSearcherLevelMult()
    { return 5; }

// the panorama stun: true sight and gems of seeing reveal the infinite Astral
// - the stun chance is 100% minus 5% per level, immobilizing for the spell's
// duration (1d8 true turns via device); also detect magic: the whole plane
// radiates magic, normal enchantments discerned only 5% of the time.
inline int ddeTrueSightStunBase()
    { return 100; }

// the conjuration/summoning caps: clerical spells of 4th level or higher do
// not function; druidical 3rd or higher; magic-user and illusionist 5th or
// higher - save spells linked with abjuration (prismatic wall) or purely
// verbal (power word, death spell exception); Power-intervention spells work
// only for Astral-native powers (Anubis).
inline int ddeClericConjLevelCap()
    { return 4; }

// the druidical summoning cap: 3rd level or higher does not work (animal
// summoning fails, fire seeds works - conjuration only); summoning cantrips
// never operate; druidical spell recovery needs an Astral-resident deity or a
// faster-time haven, save the cleric's meditative true-time rest.
inline int ddeDruidConjLevelCap()
    { return 3; }

// the magic-user/illusionist summoning cap: 5th level or higher fails unless
// abjuration-linked or verbal-only; combination spells take BOTH restrictions
// except abjuration-plus-conjuration/summoning (the conjuration limits
// ignored).
inline int ddeMuConjLevelCap()
    { return 5; }

// the silver cord: visible 10 feet behind the astral form then invisible and
// intangible, stretched to any length; severed only by the psychic wind at
// its most powerful, githyanki silver swords, or the will of a Lesser/Greater
// Power; the astral form is a solid translucent white body - magical items
// and enchanted gear come along, the rest stays; voluntary return takes 1d100
// melee rounds (delayable by psychic wind); group cords chain through the
// caster - his cord dooms all.
inline bool ddeSilverCordRule()
    { return true; }

// the color pools: 10-60 foot rippling disks, one-sided (a 1-in-10
// per-encounter blind-side miss without detect invisible); the d20 color
// table (Concordant Opposition leather brown to Ethereal spiraling white)
// with silver ALWAYS the home Prime; viewing needs concentration within 30
// feet - the point rides 1d4x100 yards above the surface, location by
// percentile (1-50 on target, 96-00 way off), fixed for one Prime day, moving
// at 10 times Intelligence in yards per round, forward only, slowed to 10
// yards per turn in magic-rich areas.
inline bool ddeColorPoolDoctrine()
    { return true; }

// the pool battle: gaze creatures (basilisks, gorgons, cockatrices) perceive
// portals and strike through them - physical attackers strike the viewing
// point at AC 0, all viewers within 30 feet save vs. petrification or be
// affected (astral forms become astral stone); a dispel magic from the far
// side (50% plus the level difference) sucks viewers through; the pool viewer
// is otherwise immune to the viewed plane.
inline bool ddePoolAttackRule()
    { return true; }

// the survival: no breathing (respiratory attacks like cloudkill useless;
// gorgon breath and insinuative poison still work), no food or drink (hunger
// at ~300 subjective years), potions permanent while on the plane, vision
// 1,000-2,000 yards (infravision dead, ultravision doubled), no gravity or
// direction - motion continues till it hits something.
inline bool ddeSurvivalDoctrine()
    { return true; }

// the combat: astral base AC 8 (nonmagical armor gives nothing, magical
// pluses reduced by 1), Intelligence gives the to-hit and damage mods (PH
// Strength table) and Wisdom the AC and bow mods (PH Dexterity table),
// Strength and Dexterity are irrelevant; attacks from above negate shields
// (helm saves), from below count as rear attacks (backstabs); missiles fly
// flat - doubled range, -2 for the first 2-5 shots; natural healing is
// suspended for non-natives.
inline bool ddeWeightlessCombat()
    { return true; }

// the liquid and poison rules: weightless liquids film the whole body -
// double damage, and a filmed victim drowns in 1d4 melee rounds if he speaks
// (no verbal spells without water breathing); poison saves are rolled but
// effects suspend until the victim reaches a faster-time plane (insinuative
// poisons the worst); potions in vials take 1d4 rounds to drink with a 5%
// choke, wineskins drink in one round.
inline bool ddeLiquidAndPoisonRule()
    { return true; }

// the void doctrine: the Astral has NO extradimensional space - rope trick,
// vanish, deep pockets fail; a portable hole either does not open (50%) or
// becomes a huge ordinary bag (50%); no egress to the Ethereal or inner
// planes save ether cyclones, so Ethereal-touching spells fail; flat spell
// areas become spheres of the lesser dimension, walls become hollow spheres
// of 10 feet plus 2.5 per level.
inline bool ddeExtradimensionalVoid()
    { return true; }

// the illusion and necromancy rules: phantasms without illusionary components
// fail (phantom wind, phantom speed); phantasmal forces work and read MORE
// believable; necromantics function normally - a failed raise dead draws an
// astral searcher; a clone grows at 1 day per 1,000 subjective years
// (useless); animate-object alterations give the object Intelligence 0
// movement but it can strike.
inline bool ddeIllusionNecromancyRule()
    { return true; }

// the Bigby hands vs mental movers: interposing hand stops the less
// intelligent and halves the rest; forceful hand's push resolves by the
// Intelligence difference (equal = no movement); grasping hand interposes
// when the caster is dimmer, repels double-strength when brighter; clenched
// fist and crushing hand function normally - the hands carry the caster's own
// hit points and Armor Class.
inline bool ddeBigbyHandRule()
    { return true; }

// the PC adjustments: thieves keep abilities - the plane self-lights so few
// shadows exist, hear noise +10%, move silently -10%, climb walls unpenalized
// on solids; rangers lose their surprise-protection but keep the 3-in-6
// surprise, tracking only on solid islands; barbarian abilities fail (only
// 6th level or higher come willingly); monks hold AC 7 or better astrally and
// move at 18 Intelligence from 10th level; cavaliers and paladins ride
// ki-rin, dragon horses and nightmares.
inline bool ddeThiefAdjustments()
    { return true; }

// the githyanki: the silver swords (+3 two-handed) and special silver swords
// (+5, vocal) are the ONLY physical weapons that sever cords - hit the cord
// at AC 0, then a 20% sever chance (mind bar blocks silver, not special);
// their 96 movement and continual probability travel make their own color
// pools unusable to them; knights are evil cavaliers, cities reach 1,000
// souls, and the lich-queen (24th-30th level) is a Demi-Power who cannot yet
// grant spells.
inline bool ddeGithyankiSilverSwords()
    { return true; }

// the permanent conduits: Yggdrasil the World Ash runs Gladsheim to Niflheim
// (the Glooms of Hades), Mount Olympus links the plane of Olympus to the
// Primes with exits into lower Gehenna, Hades and Tarterus - solid,
// permanent, weathering the fortunes of gods, ending in fixed-portal pools;
// Anubis is the only Power making his home in the Astral.
inline bool ddeYggdrasilOlympus()
    { return true; }

}   // namespace rules
