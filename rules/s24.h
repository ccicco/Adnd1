// =========================================================================================
// Adnd1 - rules/s24.h
// The Dragon issue-24 opener part two - the alignment pantheon
// census 877 -> 878.
//
// The part-two round of the issue-24 four-round shape - the single chain of
// the Schick Design Forum alignment variant, the table round of the walk:
// choir practice at the First Church of Lawful Evil (Orthodox), The
// Ramifications of Alignment - the eighteen prime alignments across Law,
// Neutrality and Chaos, the twenty-one prime deities with the four elemental
// lords at two hundred hit points, the five sons of Thakta Tylden and the
// Headsman of Marly, the fourteen-spell standard god list, the gods created
// and maintained by their believers worship. Pinned from The Dragon Vol. III
// No. 10, April 1979, number 24, print 34 and 36 through 39 - print 35 is the
// In Search of the Unknown module advertisement.
//
namespace rules {

// ---- the alignment pantheon variant (print 34+36-39) ----

// the eighteen prime alignments - six Law, six Neutrality and six Chaos, a
// few more than the nine the alignment pantheon variant (print 34+36-39)
inline int s24PrimeAlignments()
    { return 18; }

// the Law slots - Absolute Order, Harmony, Justice, Knowledge, Evolution and
// War the alignment pantheon variant (print 34+36-39)
inline int s24LawSlots()
    { return 6; }

// the Neutrality slots - Preserve the Balance, Ambition, Nature, Esthetics,
// the Four Elements and Battle Glory the alignment pantheon variant (print
// 34+36-39)
inline int s24NeutralSlots()
    { return 6; }

// the Chaos slots - Absolute Randomness, Ambition, Life and Fertility, Evil
// and Death, Devolution and War the alignment pantheon variant (print
// 34+36-39)
inline int s24ChaosSlots()
    { return 6; }

// the twenty-one prime deities - seventeen singles plus the four elemental
// lords the alignment pantheon variant (print 34+36-39)
inline int s24PrimeDeities()
    { return 21; }

// the four elemental lords - Gungger the earth Overlord, Hara the air Queen,
// Zkracl the fire Tyrant, Shaliroi the water King the alignment pantheon
// variant (print 34+36-39)
inline int s24ElementalLords()
    { return 4; }

// the five sons of Thakta Tylden - Lakunth, Pakunth, Rakunth, Quakunth and
// Dakunth, the fifth printing on page 39 the alignment pantheon variant
// (print 34+36-39)
inline int s24SonsOfThakta()
    { return 5; }

// the standard god magic list - Gate, ESP, Mind Blank, Reincarnation, Wish,
// Curse and Remove Curse, Permanency, all Healing and Resurrection spells,
// Polymorph Any Object, Comprehend Languages, Geas, Teleport Others, Teleport
// and Change Characters Abilities the alignment pantheon variant (print
// 34+36-39)
inline int s24StandardSpellList()
    { return 14; }

// in battle the prime gods always hit their targets unless they roll a one on
// a d20 the alignment pantheon variant (print 34+36-39)
inline int s24GodHitMissRoll()
    { return 1; }

// the pantheon roster row count the alignment pantheon variant (print
// 34+36-39)
inline int s24PantheonCount()
    { return 21; }

// the sons roster row count the alignment pantheon variant (print 34+36-39)
inline int s24SonsCount()
    { return 5; }

// the alignment roster row count the alignment pantheon variant (print
// 34+36-39)
inline int s24AlignsCount()
    { return 18; }

// the prime deity hit points - three hundred for every prime god, Sedjima
// included the alignment pantheon variant (print 34+36-39)
inline int s24GodBaseHp()
    { return 300; }

// the elemental lord hit points - two hundred each, the one departure from
// the prime three hundred the alignment pantheon variant (print 34+36-39)
inline int s24ElementalHp()
    { return 200; }

// the Morilirom presence - all Chaotic creatures must flee or be turned to
// stone within two hundred feet the alignment pantheon variant (print
// 34+36-39)
inline int s24MoriliromTurnRange()
    { return 200; }

// the white gelded pegasus Whickerwind hit points the alignment pantheon
// variant (print 34+36-39)
inline int s24WhickerwindHp()
    { return 40; }

// the Whickerwind move, in flight the alignment pantheon variant (print
// 34+36-39)
inline int s24WhickerwindMove()
    { return 56; }

// Cyrullia often appears accompanied by half-a-dozen unicorns the alignment
// pantheon variant (print 34+36-39)
inline int s24CyrulliaUnicorns()
    { return 6; }

// in extremity the chance any Cyrullia priest above the level can call for a
// miracle the alignment pantheon variant (print 34+36-39)
inline int s24CyrulliaMiraclePct()
    { return 5; }

// the miracle call level - priests above seventh level the alignment pantheon
// variant (print 34+36-39)
inline int s24CyrulliaMiracleLevel()
    { return 7; }

// the chance Marly rewards a meritorious avenger with a talisman of
// protection, usually against reprisals the alignment pantheon variant (print
// 34+36-39)
inline int s24MarlyTalismanPct()
    { return 10; }

// the chance Marly sends material aid to anyone engaged on a righteous
// mission of vengeance the alignment pantheon variant (print 34+36-39)
inline int s24MarlyAidPct()
    { return 5; }

// the non-Lawful vengeance aid chance - one percent instead of five the
// alignment pantheon variant (print 34+36-39)
inline int s24MarlyNonLawfulAidPct()
    { return 1; }

// the Headsman hit points the alignment pantheon variant (print 34+36-39)
inline int s24HeadsmanHp()
    { return 150; }

// the Headsman armor class the alignment pantheon variant (print 34+36-39)
inline int s24HeadsmanAc()
    { return -2; }

// the Headsman magic resistance - one hundred percent the alignment pantheon
// variant (print 34+36-39)
inline int s24HeadsmanMr()
    { return 100; }

// the Headsman plus-five two-handed vorpal axe the alignment pantheon variant
// (print 34+36-39)
inline int s24HeadsmanAxeBonus()
    { return 5; }

// the eight-foot tall heavily-muscled Headsman, in black trousers and cowl
// the alignment pantheon variant (print 34+36-39)
inline int s24HeadsmanHeight()
    { return 8; }

// the Sedjima Augury and Divination bonus - one and a half percent per level
// of cleric, pinned in half-percent units the alignment pantheon variant
// (print 34+36-39)
inline int s24SedjimaAuguryHalfPct()
    { return 3; }

// the Sedjima Contact Other Plane bonus - two percent better per level for
// his Magic-users the alignment pantheon variant (print 34+36-39)
inline int s24SedjimaContactPct()
    { return 2; }

// the Slarsken Obel battle attacks - striking four times per round the
// alignment pantheon variant (print 34+36-39)
inline int s24SlarskenHits()
    { return 4; }

// the Slarsken Obel damage bonus - plus ten with any weapon he chooses the
// alignment pantheon variant (print 34+36-39)
inline int s24SlarskenDamageAdd()
    { return 10; }

// in the presence of Tholtanooma all Lawful warriors fight at plus four the
// alignment pantheon variant (print 34+36-39)
inline int s24TholtanoomaLawfulAdd()
    { return 4; }

// in the presence of Tholtanooma all Chaotics fight at minus four the
// alignment pantheon variant (print 34+36-39)
inline int s24TholtanoomaChaoticSub()
    { return 4; }

// the Tholtanooma Paladin Bodyguard armor class the alignment pantheon
// variant (print 34+36-39)
inline int s24BodyguardAc()
    { return -2; }

// the Tholtanooma Paladin Bodyguard level, armed with Holy Swords the
// alignment pantheon variant (print 34+36-39)
inline int s24BodyguardLevel()
    { return 10; }

// the chance Tholtanooma rewards a mighty deed of Lawful valor with a
// powerful magical weapon or a potion of Temporary Near-Invulnerability the
// alignment pantheon variant (print 34+36-39)
inline int s24TholtanoomaRewardPct()
    { return 5; }

// the chance Tholtanooma instills courage in any Lawful warrior stricken with
// Fear the alignment pantheon variant (print 34+36-39)
inline int s24TholtanoomaCouragePct()
    { return 5; }

// from the right pan of the balance Manturin throws fifteen-dice lightning
// bolts the alignment pantheon variant (print 34+36-39)
inline int s24ManturinLightningDice()
    { return 15; }

// the left-pan stars are eight-pointed the alignment pantheon variant (print
// 34+36-39)
inline int s24ManturinStarPoints()
    { return 8; }

// the left-pan eight-pointed stars explode into ten-dice fireballs the
// alignment pantheon variant (print 34+36-39)
inline int s24ManturinFireballDice()
    { return 10; }

// the Manturin aid - Javelins of Lightning granting twenty points the
// alignment pantheon variant (print 34+36-39)
inline int s24ManturinJavelinPoints()
    { return 20; }

// the Manturin fireball stars grant fifteen points the alignment pantheon
// variant (print 34+36-39)
inline int s24ManturinStarGrant()
    { return 15; }

// Rillifloham appears as a forty-foot treant the alignment pantheon variant
// (print 34+36-39)
inline int s24RilliflohamHeight()
    { return 40; }

// the Rillifloham treant summon floor the alignment pantheon variant (print
// 34+36-39)
inline int s24RilliflohamSummonLo()
    { return 3; }

// the Rillifloham treant summon ceiling the alignment pantheon variant (print
// 34+36-39)
inline int s24RilliflohamSummonHi()
    { return 18; }

// the chance Rillifloham rewards meritorious actions on Nature behalf with a
// wooden artifact of great power or an animal familiar the alignment pantheon
// variant (print 34+36-39)
inline int s24RilliflohamRewardPct()
    { return 10; }

// the Rasan Korya fireballs are of ten-dice value the alignment pantheon
// variant (print 34+36-39)
inline int s24RasanFireballDice()
    { return 10; }

// the chance a favor is done for worshippers who have contributed enough at
// the Rasan Korya shrines the alignment pantheon variant (print 34+36-39)
inline int s24RasanFavorPct()
    { return 5; }

// the Demyuritas annoy-teleport floor - hexes in a random direction, once per
// round, no saving throw the alignment pantheon variant (print 34+36-39)
inline int s24DemyuritasTeleportLo()
    { return 1; }

// the Demyuritas annoy-teleport ceiling in hexes the alignment pantheon
// variant (print 34+36-39)
inline int s24DemyuritasTeleportHi()
    { return 20; }

// the elemental lord summon floor the alignment pantheon variant (print
// 34+36-39)
inline int s24ElementalSummonLo()
    { return 1; }

// the elemental lord summon ceiling - one to twelve elementals each the
// alignment pantheon variant (print 34+36-39)
inline int s24ElementalSummonHi()
    { return 12; }

// Hara hits six times per round the alignment pantheon variant (print
// 34+36-39)
inline int s24HaraHits()
    { return 6; }

// the Zkracl fireball - twenty dice every round, save versus spells for half
// damage the alignment pantheon variant (print 34+36-39)
inline int s24ZkraclFireballDice()
    { return 20; }

// the Bleskuta servant aid floor - werebbar or others of his servants the
// alignment pantheon variant (print 34+36-39)
inline int s24BleskutaServantsLo()
    { return 1; }

// the Bleskuta servant aid ceiling the alignment pantheon variant (print
// 34+36-39)
inline int s24BleskutaServantsHi()
    { return 6; }

// the chance Bleskuta sends his servants in extremity the alignment pantheon
// variant (print 34+36-39)
inline int s24BleskutaServantsPct()
    { return 3; }

// the Temanamat clerics healing spells are ten percent more effective per
// level of cleric the alignment pantheon variant (print 34+36-39)
inline int s24TemanamatHealingPct()
    { return 10; }

// the Golod four clawed hands, hitting three to thirty each plus paralysis
// the alignment pantheon variant (print 34+36-39)
inline int s24GolodClaws()
    { return 4; }

// the chance Golod sends his Legion of the Undead when his followers are in
// dire need the alignment pantheon variant (print 34+36-39)
inline int s24GolodUndeadPct()
    { return 5; }

// the chance Golod rewards some particularly evil deed with the gift of some
// terrible artifact or weapon the alignment pantheon variant (print 34+36-39)
inline int s24GolodRewardPct()
    { return 5; }

// the Sog-Morthoth amorphous body is about forty feet in diameter, oozing
// greenish slime the alignment pantheon variant (print 34+36-39)
inline int s24SogDiameter()
    { return 40; }

// the Sog-Morthoth permanent Fear radiates in a one-hundred-foot radius,
// saved against each round the alignment pantheon variant (print 34+36-39)
inline int s24SogFearRadius()
    { return 100; }

// the chance Sog-Morthoth aids his worshippers by temporarily doubling their
// strength and or the effectiveness of their spells the alignment pantheon
// variant (print 34+36-39)
inline int s24SogAidPct()
    { return 5; }

// the Sog-Morthoth doubling duration floor in rounds the alignment pantheon
// variant (print 34+36-39)
inline int s24SogAidLo()
    { return 1; }

// the Sog-Morthoth doubling duration ceiling in rounds the alignment pantheon
// variant (print 34+36-39)
inline int s24SogAidHi()
    { return 10; }

// the single Karnawenn tentacle on the prime material plane contains ten
// percent of his hit points the alignment pantheon variant (print 34+36-39)
inline int s24KarnawennTentaclePct()
    { return 10; }

// the Whip of Chaos strikes up to three opponents at once the alignment
// pantheon variant (print 34+36-39)
inline int s24ThaktaWhipTargets()
    { return 3; }

// the chance Thakta Tylden rewards valuable service with a mighty weapon or
// powerful destructive wand the alignment pantheon variant (print 34+36-39)
inline int s24ThaktaWeaponPct()
    { return 10; }

// the chance an occasional feat of great valor and prowess catches the Hisk
// attention, especially in his name the alignment pantheon variant (print
// 34+36-39)
inline int s24HiskAttentionPct()
    { return 5; }

// the Rakunth attack to-hit bonus - three attacks per round at plus six the
// alignment pantheon variant (print 34+36-39)
inline int s24RakunthHitAdd()
    { return 6; }

// the Rakunth attack damage bonus - plus eight the alignment pantheon variant
// (print 34+36-39)
inline int s24RakunthDmgAdd()
    { return 8; }

// a large percentage of players simply equate Law with good and Chaos with
// evil, despite the perpendicular axes the alignment pantheon variant (print
// 34+36-39)
inline bool s24LawEquatedGood()
    { return true; }

// the advanced rules explain that morality and Law versus Chaos are on
// separate, perpendicular axes the alignment pantheon variant (print
// 34+36-39)
inline bool s24PerpendicularAxes()
    { return true; }

// a subtle, perhaps unintentional favoritism in the rules assumes player
// characters will be Lawful or at least Neutral the alignment pantheon
// variant (print 34+36-39)
inline bool s24RulesLawFavoritism()
    { return true; }

// the new nine alignments are a good attempt at standardization but do not
// really resolve the Law and Chaos problems the alignment pantheon variant
// (print 34+36-39)
inline bool s24NineFail()
    { return true; }

// on inspection Good or Evil usually boils down to Nice or Nasty the
// alignment pantheon variant (print 34+36-39)
inline bool s24NiceNasty()
    { return true; }

// the old idea - temporal gods are created and maintained by their believers
// worship the alignment pantheon variant (print 34+36-39)
inline bool s24GodsWorshipMade()
    { return true; }

// a continual battle between religions for quantity and quality of
// worshippers the alignment pantheon variant (print 34+36-39)
inline bool s24WorshipContest()
    { return true; }

// since every religion thinks they are right, morality has to be regarded as
// flexible the alignment pantheon variant (print 34+36-39)
inline bool s24MoralityFlexible()
    { return true; }

// non-orthodox and splinter alignments with correspondingly weaker gods are
// probably quite common the alignment pantheon variant (print 34+36-39)
inline bool s24SplinterAlignments()
    { return true; }

// the pantheon deals the death to the idea of alignment tongues, except
// possibly in the cases of High Law, Chaos and Neutrality the alignment
// pantheon variant (print 34+36-39)
inline bool s24NoAlignmentTongues()
    { return true; }

// unless stated otherwise all gods can cast the standard magical spells as
// often as they wish the alignment pantheon variant (print 34+36-39)
inline bool s24StandardSpellsAtWill()
    { return true; }

// the prime gods always hit their targets in battle unless they roll a one
// the alignment pantheon variant (print 34+36-39)
inline bool s24GodsAutoHit()
    { return true; }

// gods cannot really be killed while they have sufficient worshippers -
// losing all hit points merely banishes them temporarily from the physical
// plane the alignment pantheon variant (print 34+36-39)
inline bool s24GodsBanished()
    { return true; }

// the article note - for the bi- or non-gendered deities he has been used as
// a pronoun of convenience, no sexism intended or implied the alignment
// pantheon variant (print 34+36-39)
inline bool s24PronounNote()
    { return true; }

// the italic introduction - the author challenged at Gen-Con XI to elucidate
// the alignment problems the editor enjoyed the alignment pantheon variant
// (print 34+36-39)
inline bool s24GenConChallenge()
    { return true; }

// MORILIROM spelled Moriliroom twice in the running text - the High Law
// indifference paragraph and the Slarsken Obel covet the alignment pantheon
// variant (print 34+36-39)
inline bool s24MoriliroomTwice()
    { return true; }

// the move drift - Hisk, Bleskuta, Temanamat, Golod, Sog-Morthoth and Thakta
// Tylden print move in feet against the inch moves of the rest the alignment
// pantheon variant (print 34+36-39)
inline bool s24FeetMoveDrift()
    { return true; }

// the white gelded pegasus Whickerwind as printed - the Cyrullia steed the
// alignment pantheon variant (print 34+36-39)
inline bool s24WhickerwindPrint()
    { return true; }

// richly-apparelated for appareled at the Rasan Korya appearance the
// alignment pantheon variant (print 34+36-39)
inline bool s24RichlyApparelated()
    { return true; }

// werebbar for werebear twice - the Bleskuta Frost-Giant size and the servant
// aid band the alignment pantheon variant (print 34+36-39)
inline bool s24WerebbarTwice()
    { return true; }

// psuedopods for pseudopods at the Sog-Morthoth tentacles the alignment
// pantheon variant (print 34+36-39)
inline bool s24Psuedopods()
    { return true; }

// civilization-topping for toppling in the Chaos War tenets the alignment
// pantheon variant (print 34+36-39)
inline bool s24CivilizationTopping()
    { return true; }

// THOLTANOOMA in the stat header against Tholtanooma in the running text the
// alignment pantheon variant (print 34+36-39)
inline bool s24TholtanoomaHeader()
    { return true; }

// Morilirom cannot be harmed by physical weaponry the alignment pantheon
// variant (print 34+36-39)
inline bool s24MoriliromPhysicalProof()
    { return true; }

// Morilirom cannot be insulted or flattered - the indifference makes him
// utterly fair the alignment pantheon variant (print 34+36-39)
inline bool s24MoriliromBeyondFlattery()
    { return true; }

// the Cyrullia white-ash staff heals all wounds instantly at one end and
// reopens every wound of a lifetime with all diseases relapsing at the other
// the alignment pantheon variant (print 34+36-39)
inline bool s24CyrulliaStaffDuality()
    { return true; }

// Cyrullia Paladins can call upon him personally for aid once in their
// lifetimes the alignment pantheon variant (print 34+36-39)
inline bool s24CyrulliaOnceCall()
    { return true; }

// the Marly spies are everywhere, and for everyone he has a list of good and
// evil deeds the alignment pantheon variant (print 34+36-39)
inline bool s24MarlySpies()
    { return true; }

// the Sedjima participation in human affairs is quite passive - encouragement
// and cryptic advice through oracles the alignment pantheon variant (print
// 34+36-39)
inline bool s24SedjimaPassive()
    { return true; }

// Slarsken Obel appears as a woman in matriarchies the alignment pantheon
// variant (print 34+36-39)
inline bool s24SlarskenMatriarch()
    { return true; }

// Slarsken Obel secretly covets the Moriliroom power the alignment pantheon
// variant (print 34+36-39)
inline bool s24SlarskenCovets()
    { return true; }

// Tholtanooma prefers to send one of his Paladin Bodyguard rather than appear
// himself the alignment pantheon variant (print 34+36-39)
inline bool s24TholtanoomaBodyguard()
    { return true; }

// incautious supplicants may find Manturin aiding their enemies - he always
// carefully considers all the factors the alignment pantheon variant (print
// 34+36-39)
inline bool s24ManturinAidEnemies()
    { return true; }

// Neutral Paladinhood is possible in the Manturin service to those
// sufficiently dedicated to the Balance the alignment pantheon variant (print
// 34+36-39)
inline bool s24ManturinNeutralPaladins()
    { return true; }

// fire does only normal damage against Rillifloham the alignment pantheon
// variant (print 34+36-39)
inline bool s24RilliflohamFireNormal()
    { return true; }

// the Rillifloham enemies find all the living things of the wild conspiring
// against them the alignment pantheon variant (print 34+36-39)
inline bool s24RilliflohamWildConspire()
    { return true; }

// Rasan Korya is always scheming to usurp the power of other gods - several
// minor, forgotten deities have been his victims the alignment pantheon
// variant (print 34+36-39)
inline bool s24RasanUsurper()
    { return true; }

// Rasan Korya only looks with favor on those who can manage without his help
// the alignment pantheon variant (print 34+36-39)
inline bool s24RasanWeaklings()
    { return true; }

// Bards are always a favorite with Demyuritas the alignment pantheon variant
// (print 34+36-39)
inline bool s24DemyuritasBards()
    { return true; }

// Gungger can cross water without trouble the alignment pantheon variant
// (print 34+36-39)
inline bool s24GunggerCrossesWater()
    { return true; }

// Hara cannot be touched by projectiles launched into the air the alignment
// pantheon variant (print 34+36-39)
inline bool s24HaraProjectileProof()
    { return true; }

// it is said that Zkracl can spy through any fire - many hearths and forges
// have shrines to him the alignment pantheon variant (print 34+36-39)
inline bool s24ZkraclSpiesFires()
    { return true; }

// Zkracl is not affected by water the alignment pantheon variant (print
// 34+36-39)
inline bool s24ZkraclWaterProof()
    { return true; }

// Shaliroi is not affected by heat the alignment pantheon variant (print
// 34+36-39)
inline bool s24ShaliroiHeatProof()
    { return true; }

// any sort of weapon Hisk wants will instantly appear in his hands the
// alignment pantheon variant (print 34+36-39)
inline bool s24HiskWeaponsAppear()
    { return true; }

// Hisk rarely appears on the Prime Material plane - he is too involved in the
// great battles and contests of Gallarna, his kingdom in the clouds the
// alignment pantheon variant (print 34+36-39)
inline bool s24HiskGallarna()
    { return true; }

// the sight of Karnawenn in his actual form drives mortals instantly mad, no
// saving throw the alignment pantheon variant (print 34+36-39)
inline bool s24KarnawennMadness()
    { return true; }

// no more than one of the Karnawenn tentacles can appear on the prime
// material plane, and it must take some kind of a form, usually human the
// alignment pantheon variant (print 34+36-39)
inline bool s24KarnawennOneTentacle()
    { return true; }

// Bleskuta is careful to appear stupider and much less cunning than he is,
// and has walked the earth in many different guises the alignment pantheon
// variant (print 34+36-39)
inline bool s24BleskutaGuises()
    { return true; }

// Temanamat usually uses Satyrs as her messengers and agents the alignment
// pantheon variant (print 34+36-39)
inline bool s24TemanamatSatyrs()
    { return true; }

// tattooed on the Golod chest is the Yellow Sign the alignment pantheon
// variant (print 34+36-39)
inline bool s24GolodYellowSign()
    { return true; }

// Golod can only be appeased by human sacrifice, and looks most favorably
// upon those who have sent him the most lives the alignment pantheon variant
// (print 34+36-39)
inline bool s24GolodSacrifice()
    { return true; }

// those who serve Golod in life can expect to serve him afterwards as members
// of the undead the alignment pantheon variant (print 34+36-39)
inline bool s24GolodUndeadService()
    { return true; }

// those in the Sog-Morthoth service tend to gradually become less human and
// more bestial, prefer subterranean living and may actually develop
// infravision the alignment pantheon variant (print 34+36-39)
inline bool s24SogBestialServants()
    { return true; }

// it is extremely rare for Thakta Tylden to appear at anything less than
// Armageddon-sized battles the alignment pantheon variant (print 34+36-39)
inline bool s24ThaktaArmageddon()
    { return true; }

// the cowardly Thakta Tylden followers may be turned into Kobolds the
// alignment pantheon variant (print 34+36-39)
inline bool s24ThaktaCowardKobolds()
    { return true; }

// Marly is always accompanied by The Headsman the alignment pantheon variant
// (print 34+36-39)
inline bool s24HeadsmanAlways()
    { return true; }

// the Ambition alignment on both axes - the Neutrality of Rasan Korya and the
// Chaos of Bleskuta the alignment pantheon variant (print 34+36-39)
inline bool s24AmbitionTwice()
    { return true; }

// the War alignment on both axes - the Law of Tholtanooma and the Chaos of
// Thakta Tylden the alignment pantheon variant (print 34+36-39)
inline bool s24WarTwice()
    { return true; }

// the armor class - negative better, the Morilirom irrelevant armor class
// carried as the sentinel
inline int s24GodAc(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -4;
        case 2:
            return -4;
        case 3:
            return 0;
        case 4:
            return -5;
        case 5:
            return -6;
        case 6:
            return -5;
        case 7:
            return -3;
        case 8:
            return -4;
        case 9:
            return -2;
        case 10:
            return -4;
        case 11:
            return -2;
        case 12:
            return -2;
        case 13:
            return -2;
        case 14:
            return -5;
        case 15:
            return -6;
        case 16:
            return -5;
        case 17:
            return -1;
        case 18:
            return -4;
        case 19:
            return -2;
        case 20:
            return -6;
        default:
            return -99;
        }
    }

// the hit points - the prime three hundred, the elemental lords two hundred
inline int s24GodHp(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 300;
        case 2:
            return 300;
        case 3:
            return 300;
        case 4:
            return 300;
        case 5:
            return 300;
        case 6:
            return 300;
        case 7:
            return 300;
        case 8:
            return 300;
        case 9:
            return 300;
        case 10:
            return 200;
        case 11:
            return 200;
        case 12:
            return 200;
        case 13:
            return 200;
        case 14:
            return 300;
        case 15:
            return 300;
        case 16:
            return 300;
        case 17:
            return 300;
        case 18:
            return 300;
        case 19:
            return 300;
        case 20:
            return 300;
        default:
            return -99;
        }
    }

// the printed move - the Hisk, Bleskuta, Temanamat, Golod, Sog-Morthoth and
// Thakta Tylden feet marks against the inch moves of the rest, the Morilirom
// and Karnawenn instantaneous moves carried as the sentinel
inline int s24GodMove(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 18;
        case 2:
            return 24;
        case 3:
            return 12;
        case 4:
            return 36;
        case 5:
            return 24;
        case 6:
            return 24;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 24;
        case 10:
            return 12;
        case 11:
            return 72;
        case 12:
            return 36;
        case 13:
            return 12;
        case 14:
            return 21;
        case 15:
            return -99;
        case 16:
            return 18;
        case 17:
            return 12;
        case 18:
            return 24;
        case 19:
            return 18;
        case 20:
            return 24;
        default:
            return -99;
        }
    }

// the second printed move - the Shaliroi thirty-six in water, the sentinel
// otherwise
inline int s24GodMove2(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return -99;
        case 3:
            return -99;
        case 4:
            return -99;
        case 5:
            return -99;
        case 6:
            return -99;
        case 7:
            return -99;
        case 8:
            return -99;
        case 9:
            return -99;
        case 10:
            return -99;
        case 11:
            return -99;
        case 12:
            return -99;
        case 13:
            return 36;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return -99;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return -99;
        default:
            return -99;
        }
    }

// the damage low die - the Marly staff, the Tholtanooma hammer, the Rasan
// Korya sword, the Rillifloham fists, the Gungger fists, the Hara hands, the
// Zkracl hands, the Shaliroi hands, the Bleskuta club, the Golod claws and
// the Thakta Tylden whip, the sentinel where the article prints no damage
// pair
inline int s24GodDmgLo(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 4;
        case 3:
            return -99;
        case 4:
            return -99;
        case 5:
            return 10;
        case 6:
            return -99;
        case 7:
            return 5;
        case 8:
            return 8;
        case 9:
            return -99;
        case 10:
            return 10;
        case 11:
            return 3;
        case 12:
            return 5;
        case 13:
            return 3;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return 6;
        case 17:
            return -99;
        case 18:
            return 3;
        case 19:
            return -99;
        case 20:
            return 4;
        default:
            return -99;
        }
    }

// the damage high die - the same printed pairs, the sentinel where the
// article prints none
inline int s24GodDmgHi(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 40;
        case 3:
            return -99;
        case 4:
            return -99;
        case 5:
            return 100;
        case 6:
            return -99;
        case 7:
            return 50;
        case 8:
            return 80;
        case 9:
            return -99;
        case 10:
            return 100;
        case 11:
            return 30;
        case 12:
            return 50;
        case 13:
            return 30;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return 60;
        case 17:
            return -99;
        case 18:
            return 30;
        case 19:
            return -99;
        case 20:
            return 40;
        default:
            return -99;
        }
    }

// the son armor class - the Lakunth minus one through the Pakunth four
inline int s24SonAc(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 4;
        case 2:
            return -2;
        case 3:
            return 2;
        case 4:
            return 2;
        default:
            return -99;
        }
    }

// the son hit points - the seventy-five through the ninety
inline int s24SonHp(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 45;
        case 2:
            return 60;
        case 3:
            return 45;
        case 4:
            return 90;
        default:
            return -99;
        }
    }

// the son magic resistance - the Pakunth fifty and the Dakunth eighty-five
// printed, the sentinel for the three without a printed resistance
inline int s24SonMr(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 50;
        case 2:
            return -99;
        case 3:
            return -99;
        case 4:
            return 85;
        default:
            return -99;
        }
    }

// the son level - the Lakunth fifteenth, the Quakunth tenth and the Dakunth
// twentieth printed, the sentinel for the giant and the demi-god
inline int s24SonLevel(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return -99;
        case 2:
            return -99;
        case 3:
            return 10;
        case 4:
            return 20;
        default:
            return -99;
        }
    }

// the son attacks per round - only the Rakunth three printed, the sentinel
// for the rest
inline int s24SonAttacks(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return -99;
        case 2:
            return 3;
        case 3:
            return -99;
        case 4:
            return -99;
        default:
            return -99;
        }
    }

// the axis - Law zero, Neutrality one, Chaos two
inline int s24AlignAxis(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        default:
            return -99;
        }
    }

// the slot within the axis - A zero through F five
inline int s24AlignSlot(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 5;
        default:
            return -99;
        }
    }

// the prime deity index into the pantheon grid - the Four Elements pointing
// at the Gungger row, Battle Glory at the Hisk row
inline int s24AlignDeity(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 14;
        case 12:
            return 15;
        case 13:
            return 16;
        case 14:
            return 17;
        case 15:
            return 18;
        case 16:
            return 19;
        case 17:
            return 20;
        default:
            return -99;
        }
    }

}   // namespace rules
