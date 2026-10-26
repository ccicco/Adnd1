// =========================================================================================
// Adnd1 - rules/jpn.h
// the Japanese mythos - the D&DG walk round thirteen, print pp. 81-85:
// thirteen beings from Ama-Tsu-Mara the god of blacksmiths to Yoshi-iye the
// hero whose arrows pierce rocks, the five greater gods (Amaterasu Omikami,
// Daikoku, Raiden, Susanowo, Tsukiyomi), the three lesser gods (Ama-Tsu-Mara,
// Ebisu, Kishijoten), the two demigods (Hachiman, Oh-Kuni-Nushi), and the
// three heroes (Raiko, Yamamoto Date, Yoshi-iye) across seven plane codes.
// census 783 -> 784.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 082-086; the second printing) with
// the column-split tsv dumps; the collation voice: the archive.org 1st-print
// derivative (deities-demigods-1st-print) - the chocr char-level word
// geometry at 600dpi plus the djvu.xml word geometry. The adjudications: the
// digit-split calibration (the narrow 1 splits: Kishijoten 31717 = 311 hp, 17
// = 1 attack; Ebisu 3173 = 313 hp; Hachiman 175th = the 15th assassin), the
// fraction fingerprint (the five X 1/2 cells: Ama-Tsu-Mara 78, Daikoku 66,
// Ebisu 66, Hachiman 78, Susanowo 78), the Ebisu Seven Heavens plane catch
// over the merged-voice Prime Material, the Amaterasu MU/I in-each wrap-line
// catch, the Amaterasu Infinite move -1 sentinel of the Ptah precedent, the
// Susanowo 12/36/48 triple slash of the Ahto precedent, and the two bare-M
// hero size rows pinned 0. Flagged odd prints pinned: Hachiman 28/21,
// Oh-Kuni-Nushi 15/12, Tsukiyomi 12/21, Raiko 29, Yoshi-iye 19.
//
namespace rules {

// ---- the R861 census ----

// the Japanese mythos round: the D&DG walk round thirteen, print pp. 81-85
inline int jpnRound()
    { return 861; }

// the first print page (the folio offset PRINT = PDF - 1)
inline int jpnPrintStart()
    { return 81; }

// the last print page of the mythos
inline int jpnPrintEnd()
    { return 85; }

// the thirteen beings of the Japanese mythos
inline int jpnBeingCount()
    { return 13; }

// the four grids: combat, class, ability, roster
inline int jpnTableCount()
    { return 4; }

// no chains this round
inline int jpnChainCount()
    { return 0; }

// the registry floor holds: zero registry defs touched this round
inline int jpnRegistryFloor()
    { return 995; }

// the combat grid rows (one per being)
inline int jpnCbtRows()
    { return 13; }

// the class grid rows
inline int jpnClsRows()
    { return 13; }

// the ability grid rows
inline int jpnAbiRows()
    { return 13; }

// the roster grid rows
inline int jpnRosRows()
    { return 13; }

// the plane codes: 0 none, 1 Prime Material, 2 Gladsheim, 3 Seven Heavens, 4
// Elysium, 5 Limbo, 6 Elemental Air
inline int jpnPlaneCount()
    { return 7; }

// the greater gods: Amaterasu Omikami, Daikoku, Raiden, Susanowo, Tsukiyomi
inline int jpnGreaterCount()
    { return 5; }

// the lesser gods: Ama-Tsu-Mara, Ebisu, Kishijoten
inline int jpnLesserCount()
    { return 3; }

// the two demigods: Hachiman, Oh-Kuni-Nushi
inline int jpnDemigodCount()
    { return 2; }

// the three heroes: Raiko, Yamamoto Date, Yoshi-iye
inline int jpnHeroCount()
    { return 3; }

// the in-each flags: Amaterasu MU/I 20 and M/B 15, Daikoku MU/I 12,
// Kishijoten MU/I 20, Oh-Kuni-Nushi M/B 10, Raiden MU/I 15, Susanowo C/D 10,
// Tsukiyomi MU/I 15, Yoshi-iye M/B 5
inline int jpnInEachCount()
    { return 8; }

// no enmity flags printed this round
inline int jpnEnmityCount()
    { return 0; }

// the paladin pairs: Ebisu 10, Yamamoto Date 15
inline int jpnPaladinCount()
    { return 2; }

// the psionic classes: I Amaterasu, Ebisu, Hachiman; II Kishijoten; V
// Ama-Tsu-Mara, Oh-Kuni-Nushi, Raiden, Susanowo; VI Daikoku, Tsukiyomi
inline int jpnPsiClassKinds()
    { return 4; }

// the five X 1/2 foot size cells: Ama-Tsu-Mara 78, Daikoku 66, Ebisu 66,
// Hachiman 78, Susanowo 78
inline int jpnHalfFootCount()
    { return 5; }

// no artifacts this round
inline int jpnArtifactCount()
    { return 0; }

// ---- the Japanese pantheon doctrine ----

// the way of the gods is a deep love of the workings of nature
inline bool jpnShintoNatureLove()
    { return true; }

// the temples are built around living trees and gardens
inline bool jpnTemplesTreesGardens()
    { return true; }

// both male and female clerics serve the pantheon
inline bool jpnMaleFemaleClerics()
    { return true; }

// the Shinto religion worships the eight million kami
inline bool jpnEightMillionKami()
    { return true; }

// the temples hold no images of the gods
inline bool jpnNoTempleImages()
    { return true; }

// the shrines face south or east
inline bool jpnShrinesFaceSouthEast()
    { return true; }

// no shrine ever faces north or west
inline bool jpnNeverNorthWest()
    { return true; }

// the torii gateways mark the shrine approaches
inline bool jpnToriiGateways()
    { return true; }

// the three holy symbols: the mirror, the sword, the gemstones
inline bool jpnThreeHolySymbols()
    { return true; }

// the punishment of the gods strips ability points
inline bool jpnPunishmentStripsAbility()
    { return true; }

// the stripped ability points are earned back with service
inline bool jpnAbilityEarnedBack()
    { return true; }

// the kami are a universal concept of spirits
inline bool jpnKamiUniversalConcept()
    { return true; }

// the kami materialize as a druid or illusionist when the place is threatened
inline bool jpnKamiMaterializeDruid()
    { return true; }

// ---- Ama-Tsu-Mara ----

// the double-edged axe does 45 points of damage
inline int jpnAmaTsuAxeDamage()
    { return 45; }

// the double-edged axe is 12 feet long
inline int jpnAmaTsuAxeFeet()
    { return 12; }

// the 2 percent chance a weapon gains the +4 blessing
inline int jpnAmaTsuBlessingPct()
    { return 2; }

// Ama-Tsu-Mara makes any magical weapon in one week
inline int jpnAmaTsuWeaponWeek()
    { return 1; }

// the smith god makes the dancing swords
inline bool jpnAmaTsuDancingSwords()
    { return true; }

// the axe slays any fire-type creature on contact
inline bool jpnAmaTsuAxeSlaysFire()
    { return true; }

// ---- Amaterasu Omikami ----

// her fist does 1 to 100 points of damage
inline int jpnAmaterasuFistDamageHi()
    { return 100; }

// the polymorph touch saves at minus 8
inline int jpnAmaterasuPolymorphSavePenalty()
    { return 8; }

// the mother of the Japanese pantheon
inline bool jpnAmaterasuMotherOfPantheon()
    { return true; }

// the trinity with Susanowo and Tsukiyomi
inline bool jpnAmaterasuTrinity()
    { return true; }

// the weapons hurled at her turn into small birds
inline bool jpnAmaterasuWeaponsToBirds()
    { return true; }

// she radiates continual light
inline bool jpnAmaterasuContinualLight()
    { return true; }

// ---- Daikoku ----

// the wooden mallet does 20 points of damage
inline int jpnDaikokuMalletDamage()
    { return 20; }

// the mallet shrinks a victim to half size
inline int jpnDaikokuMalletShrinkPct()
    { return 50; }

// the patron of farmers
inline bool jpnDaikokuPatronFarmers()
    { return true; }

// he controls the weather at will
inline bool jpnDaikokuWeatherControl()
    { return true; }

// he controls plant and animal growth
inline bool jpnDaikokuGrowthControl()
    { return true; }

// he wanders the Ethereal Plane
inline bool jpnDaikokuEtherealWanderer()
    { return true; }

// the sacrificed wealth is rewarded to the descendants
inline bool jpnDaikokuWealthReward()
    { return true; }

// the mallet negates miscellaneous magic items
inline bool jpnDaikokuNegatesMiscMagic()
    { return true; }

// the mallet transports its master to safety
inline bool jpnDaikokuMalletSafety()
    { return true; }

// ---- Ebisu ----

// the staff of striking does 3 to 30 points of damage
inline int jpnEbisuStaffDamageHi()
    { return 30; }

// he appears as an elderly male
inline bool jpnEbisuElderlyMale()
    { return true; }

// he rewards those who work hard
inline bool jpnEbisuRewardsHardWorkers()
    { return true; }

// he always makes his saving throws
inline bool jpnEbisuAlwaysSaves()
    { return true; }

// his attackers take half damage back
inline bool jpnEbisuAttackersHalfDamage()
    { return true; }

// his attackers miss every other hit
inline bool jpnEbisuMissEveryOtherHit()
    { return true; }

// the 10th level paladin pair
inline bool jpnEbisuPaladin()
    { return true; }

// ---- Hachiman ----

// the red dragon form reverts after 48 hours
inline int jpnHachimanDragonRevertHours()
    { return 48; }

// the dragon can fight for up to 100 melee rounds
inline int jpnHachimanDragonRounds()
    { return 100; }

// the two-handed sword does 4 to 40 points of damage
inline int jpnHachimanSwordDamageHi()
    { return 40; }

// the open hand does 5 to 20 points of damage
inline int jpnHachimanOpenHandDamageHi()
    { return 20; }

// he shape changes at will
inline bool jpnHachimanShapeChange()
    { return true; }

// immune to spells of 7th level and less
inline bool jpnHachimanImmuneLowSpells()
    { return true; }

// immune to illusions
inline bool jpnHachimanImmuneIllusions()
    { return true; }

// the throwing knife turns into an ancient red dragon
inline bool jpnHachimanThrowingKnifeDragon()
    { return true; }

// the two-handed sword that only he can lift
inline bool jpnHachimanSwordOnlyHeLifts()
    { return true; }

// the sword acts as a sword of sharpness
inline bool jpnHachimanSwordOfSharpness()
    { return true; }

// ---- Kishijoten ----

// the 2 percent chance she favors a character with luck
inline int jpnKishijotenLuckPct()
    { return 2; }

// she takes human form when struggles involve mortals
inline bool jpnKishijotenHumanForm()
    { return true; }

// she shape changes at will
inline bool jpnKishijotenShapeChange()
    { return true; }

// she always makes her saving throws
inline bool jpnKishijotenAlwaysSaves()
    { return true; }

// she summons one good creature once a month
inline bool jpnKishijotenMonthlyGoodSummon()
    { return true; }

// the summoned creature has free will
inline bool jpnKishijotenSummonFreeWill()
    { return true; }

// she never fights herself
inline bool jpnKishijotenNeverFights()
    { return true; }

// ---- Oh-Kuni-Nushi ----

// the red two-handed sword does 3 to 30 points of damage
inline int jpnOhKuniSwordDamageHi()
    { return 30; }

// the red two-handed sword damage bonus
inline int jpnOhKuniSwordPlus()
    { return 8; }

// the Land Master can converse with, heal and grow natural creatures
inline bool jpnOhKuniLandMaster()
    { return true; }

// the ground speaks to him of who passed and what is hidden
inline bool jpnOhKuniGroundSpeaks()
    { return true; }

// his clerics need heroic acts to gain each level
inline bool jpnOhKuniClericsHeroicActs()
    { return true; }

// ---- Raiden ----

// the scaled skin talons do 2 to 24 points of damage
inline int jpnRaidenTalonDamageHi()
    { return 24; }

// the lightning bolts do 25 points of damage
inline int jpnRaidenBoltDamage()
    { return 25; }

// the jet black mace bonus
inline int jpnRaidenMacePlus()
    { return 3; }

// the mace does 2 to 20 points of damage
inline int jpnRaidenMaceDamageHi()
    { return 20; }

// the black splint mail bonus
inline int jpnRaidenSplintPlus()
    { return 3; }

// the shield bonus
inline int jpnRaidenShieldPlus()
    { return 4; }

// the shield stops one weapon per round
inline int jpnRaidenShieldWeaponStops()
    { return 1; }

// the ten arrows of slaying mortals
inline int jpnRaidenSlayingArrows()
    { return 10; }

// the scaled skin with the 2 to 24 talons
inline bool jpnRaidenScaledSkin()
    { return true; }

// he shape changes at will
inline bool jpnRaidenShapeChange()
    { return true; }

// he controls the weather at will
inline bool jpnRaidenWeatherControl()
    { return true; }

// the mace disenchants weapons it strikes
inline bool jpnRaidenMaceDisenchants()
    { return true; }

// the wind storm blocks missile fire
inline bool jpnRaidenWindStormBlocksMissiles()
    { return true; }

// the shadowy aura negates magic-user spells of 8th level and less
inline bool jpnRaidenAuraNegatesSpells()
    { return true; }

// the drums of panic at double strength
inline bool jpnRaidenDrumsOfPanic()
    { return true; }

// the patron of fletchers
inline bool jpnRaidenFletcherPatron()
    { return true; }

// the arrows of slaying mortals are undetectable
inline bool jpnRaidenArrowsUndetectable()
    { return true; }

// ---- Raiko ----

// the longbow shoots double distance and damage
inline int jpnRaikoLongbowMultiplier()
    { return 2; }

// the hero favored of the gods
inline bool jpnRaikoFavoredOfGods()
    { return true; }

// the fighter of enchanted monsters
inline bool jpnRaikoEnchantedMonsterFighter()
    { return true; }

// the greater endurance and speed
inline bool jpnRaikoGreaterEndurance()
    { return true; }

// the magically swifter sword
inline bool jpnRaikoSwifterSword()
    { return true; }

// also known as Yorimitsu
inline bool jpnRaikoAkaYorimitsu()
    { return true; }

// ---- Susanowo ----

// the lightning bolts do 30 points of damage
inline int jpnSusanowoBoltDamage()
    { return 30; }

// the elemental summons run 1 to 10
inline int jpnSusanowoElementalsLo()
    { return 1; }

// the air and water elemental summon ceiling
inline int jpnSusanowoElementalsHi()
    { return 10; }

// the flight removal lasts one week with no save
inline int jpnSusanowoFlightLossDays()
    { return 7; }

// the yellow splint mail heat blasts do 20 points of damage
inline int jpnSusanowoSplintDamage()
    { return 20; }

// the heat blast radius in feet
inline int jpnSusanowoSplintBlastFeet()
    { return 10; }

// the yellow sword does 3 to 30 points of damage
inline int jpnSusanowoSwordDamageHi()
    { return 30; }

// the bearded god
inline bool jpnSusanowoBearded()
    { return true; }

// the thunder cloud follows him
inline bool jpnSusanowoThunderCloud()
    { return true; }

// he shape changes at will
inline bool jpnSusanowoShapeChange()
    { return true; }

// he removes flight for one week with no save
inline bool jpnSusanowoRemovesFlight()
    { return true; }

// the yellow sword deflects blows to the nearest enemy
inline bool jpnSusanowoSwordDeflects()
    { return true; }

// his magic resistance is 100 percent in water
inline bool jpnSusanowoFullMrInWater()
    { return true; }

// the sea creatures shield him in the water
inline bool jpnSusanowoSeaCreaturesShield()
    { return true; }

// ---- Tsukiyomi ----

// the flying creature summons per day
inline int jpnTsukiyomiFlyingSummonsPerDay()
    { return 5; }

// the unbreakable pike does 40 points of damage
inline int jpnTsukiyomiPikeDamage()
    { return 40; }

// the light blue skin
inline bool jpnTsukiyomiLightBlueSkin()
    { return true; }

// he shape changes at will
inline bool jpnTsukiyomiShapeChange()
    { return true; }

// he summons flying creatures five times a day
inline bool jpnTsukiyomiSummonFlying()
    { return true; }

// he summons any object seen to his hand with a magic save
inline bool jpnTsukiyomiObjectToHand()
    { return true; }

// the pike is unbreakable
inline bool jpnTsukiyomiPikeUnbreakable()
    { return true; }

// immune to poison and petrification
inline bool jpnTsukiyomiImmunePoisonPetrif()
    { return true; }

// immune to the magic jar
inline bool jpnTsukiyomiImmuneMagicJar()
    { return true; }

// ---- Yamamoto Date ----

// the disguise skill of an 11th level assassin
inline int jpnYamamotoDisguiseLevel()
    { return 11; }

// the son of the emperor
inline bool jpnYamamotoEmperorSon()
    { return true; }

// the disguise skill of an 11th level assassin
inline bool jpnYamamotoDisguiseSkill()
    { return true; }

// the magic sword of dragon slaying
inline bool jpnYamamotoDragonSlayingSword()
    { return true; }

// the sword acts as a sword of sharpness
inline bool jpnYamamotoSwordSharpness()
    { return true; }

// the speed with any blade
inline bool jpnYamamotoBladeSpeed()
    { return true; }

// ---- Yoshi-iye ----

// Hachiman answers his prayers personally
inline bool jpnYoshiiyeHachimanAnswers()
    { return true; }

// mighty with any weapon
inline bool jpnYoshiiyeMightyAnyWeapon()
    { return true; }

// the legendary bow
inline bool jpnYoshiiyeLegendaryBow()
    { return true; }

// the arrows pierce rocks
inline bool jpnYoshiiyeArrowsPierceRocks()
    { return true; }

// ---- the combat grid ----

// The armor class cells (Kishijoten the minus 10 best, Amaterasu and
// Tsukiyomi the minus sevens; the three heroes 2 and -1 the worst)
inline int jpnCbtAC(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -7;
        case 2:
            return 2;
        case 3:
            return -5;
        case 4:
            return 1;
        case 5:
            return -10;
        case 6:
            return -4;
        case 7:
            return -8;
        case 8:
            return -1;
        case 9:
            return -4;
        case 10:
            return -7;
        case 11:
            return 2;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The range ceiling cells (0 = a single printed armor class; all thirteen
// read single this round)
inline int jpnCbtACAlt(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The hit point cells (the three 400s of Amaterasu, Susanowo and Tsukiyomi;
// down to Yoshi-iye 109; the digit-split decode Kishijoten 311 and Ebisu 313)
inline int jpnCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 299;
        case 1:
            return 400;
        case 2:
            return 350;
        case 3:
            return 313;
        case 4:
            return 300;
        case 5:
            return 311;
        case 6:
            return 200;
        case 7:
            return 337;
        case 8:
            return 180;
        case 9:
            return 400;
        case 10:
            return 400;
        case 11:
            return 189;
        case 12:
            return 109;
        default:
            return 0;
        }
    }

// The primary move cells (Amaterasu the Infinite -1 sentinel of the Ptah
// precedent; the flagged odd prints pinned: Raiko 29 and Yoshi-iye 19 without
// a slash, Hachiman the 28/21 descending pair)
inline int jpnCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return -1;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 28;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 12;
        case 8:
            return 29;
        case 9:
            return 12;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 19;
        default:
            return 0;
        }
    }

// The secondary move cells (the Susanowo 12/36 of the printed 12/36/48 triple
// slash, the 48 in this comment per the klv Ahto precedent; Oh-Kuni-Nushi the
// flagged 15/12 descending pair, Tsukiyomi 12/21; 0 = the single-printed
// moves)
inline int jpnCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 21;
        case 5:
            return 12;
        case 6:
            return 12;
        case 7:
            return 24;
        case 8:
            return 0;
        case 9:
            return 36;
        case 10:
            return 21;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The attack count cells (Ama-Tsu-Mara, Tsukiyomi and Yoshi-iye the 3/2 rows;
// Kishijoten the digit-split single; 0 = none)
inline int jpnCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 3;
        default:
            return 0;
        }
    }

// The attack alternative cells (the three 3/2 slash denominators:
// Ama-Tsu-Mara, Tsukiyomi, Yoshi-iye)
inline int jpnCbtAtD(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The magic resistance cells (Kishijoten the 100 ceiling, Raiden 80,
// Amaterasu 75; 0 = the printed Standard of the three heroes)
inline int jpnCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 75;
        case 2:
            return 20;
        case 3:
            return 50;
        case 4:
            return 35;
        case 5:
            return 100;
        case 6:
            return 20;
        case 7:
            return 80;
        case 8:
            return 0;
        case 9:
            return 30;
        case 10:
            return 30;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The size cells in inches (the five pixel-verified X 1/2 foot fractions:
// Ama-Tsu-Mara 78, Daikoku 66, Ebisu 66, Hachiman 78, Susanowo 78; the two
// bare M hero rows print no height, 0: Yamamoto Date, Yoshi-iye)
inline int jpnCbtSizeIn(int b)
    {
        switch (b) {
        case 0:
            return 78;
        case 1:
            return 60;
        case 2:
            return 66;
        case 3:
            return 66;
        case 4:
            return 78;
        case 5:
            return 60;
        case 6:
            return 72;
        case 7:
            return 84;
        case 8:
            return 72;
        case 9:
            return 78;
        case 10:
            return 84;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (Ebisu the 30th level ceiling, Tsukiyomi 20,
// Amaterasu 20; Hachiman, Oh-Kuni-Nushi and the three heroes Nil)
inline int jpnClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 10;
        case 3:
            return 30;
        case 4:
            return 0;
        case 5:
            return 25;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 10;
        case 10:
            return 20;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The druid level cells (Amaterasu and Daikoku the printed 14th druid pairs;
// Susanowo the 10 in-each pair)
inline int jpnClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 14;
        case 2:
            return 14;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 10;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The lower fighter level cells (the two paladin pairs: Ebisu 10, Yamamoto
// Date 15; the plain fighters Ama-Tsu-Mara 12, Daikoku 12, Oh-Kuni-Nushi 18,
// Raiden 13)
inline int jpnClsFighterLo(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 18;
        case 7:
            return 13;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 15;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The upper fighter level cells (the paladin hi cells; all other fighters
// single-printed, 0)
inline int jpnClsFighterHi(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 15;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells (the Nth level ranger prints on the FIGHTER lines:
// Hachiman 20, Raiko 18, Susanowo 13, Tsukiyomi 12, Yoshi-iye 13)
inline int jpnClsRanger(int b)
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
            return 20;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 18;
        case 9:
            return 13;
        case 10:
            return 12;
        case 11:
            return 0;
        case 12:
            return 13;
        default:
            return 0;
        }
    }

// The magic-user level cells (Ama-Tsu-Mara the printed 20th level magic-user
// single; the MU/I in-each pairs: Amaterasu 20, Daikoku 12, Kishijoten 20,
// Raiden 15, Tsukiyomi 15)
inline int jpnClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 12;
        case 3:
            return 25;
        case 4:
            return 0;
        case 5:
            return 20;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 20;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The illusionist level cells (the in-each mirrors; 0 = the named magic-user
// single prints)
inline int jpnClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 20;
        case 6:
            return 0;
        case 7:
            return 15;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The thief level cells (none printed this round)
inline int jpnClsThief(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells (Hachiman the digit-split 15th, Raiko 12,
// Tsukiyomi 15)
inline int jpnClsAssassin(int b)
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
            return 15;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The monk level cells (the MONK/BARD in-each pairs new this round: Amaterasu
// 15, Oh-Kuni-Nushi 10, Yoshi-iye 5; Hachiman the printed 14th monk; Raiko
// 15)
inline int jpnClsMonk(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 15;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 14;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 5;
        default:
            return 0;
        }
    }

// The bard level cells (the in-each mirrors of Amaterasu, Oh-Kuni-Nushi and
// Yoshi-iye; the named bard prints: Ama-Tsu-Mara 8, Daikoku 10, Ebisu 10,
// Kishijoten 15, Tsukiyomi 10)
inline int jpnClsBard(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 15;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 0;
        case 12:
            return 5;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (the four 25s of Ama-Tsu-Mara, Amaterasu, Susanowo,
// Tsukiyomi; Raiko the 18(00), Yoshi-iye the 18(89))
inline int jpnAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 22;
        case 3:
            return 23;
        case 4:
            return 20;
        case 5:
            return 15;
        case 6:
            return 20;
        case 7:
            return 24;
        case 8:
            return 18;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 17;
        case 12:
            return 18;
        default:
            return 0;
        }
    }

// The strength to-hit bonuses (0 = the no-printed-bracket row: Kishijoten)
inline int jpnAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 3;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 1;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The strength damage bonuses (the four 14s; Yamamoto the 1/1 mortal row)
inline int jpnAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 14;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 8;
        case 5:
            return 0;
        case 6:
            return 8;
        case 7:
            return 12;
        case 8:
            return 6;
        case 9:
            return 14;
        case 10:
            return 14;
        case 11:
            return 1;
        case 12:
            return 4;
        default:
            return 0;
        }
    }

// The intelligence cells (the 25s of Amaterasu, Ebisu, Kishijoten; Hachiman
// 21)
inline int jpnAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 25;
        case 2:
            return 23;
        case 3:
            return 25;
        case 4:
            return 21;
        case 5:
            return 25;
        case 6:
            return 20;
        case 7:
            return 22;
        case 8:
            return 18;
        case 9:
            return 24;
        case 10:
            return 23;
        case 11:
            return 17;
        case 12:
            return 17;
        default:
            return 0;
        }
    }

// The wisdom cells (Amaterasu, Ebisu, Kishijoten the 25s; Oh-Kuni-Nushi the
// 10)
inline int jpnAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 25;
        case 4:
            return 17;
        case 5:
            return 25;
        case 6:
            return 10;
        case 7:
            return 19;
        case 8:
            return 11;
        case 9:
            return 20;
        case 10:
            return 23;
        case 11:
            return 11;
        case 12:
            return 15;
        default:
            return 0;
        }
    }

// The dexterity cells (the 25s of Amaterasu, Hachiman, Susanowo, Tsukiyomi)
inline int jpnAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 25;
        case 2:
            return 24;
        case 3:
            return 22;
        case 4:
            return 25;
        case 5:
            return 20;
        case 6:
            return 20;
        case 7:
            return 24;
        case 8:
            return 19;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 19;
        case 12:
            return 19;
        default:
            return 0;
        }
    }

// The constitution cells (the 25s of Amaterasu, Hachiman, Susanowo,
// Tsukiyomi)
inline int jpnAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 23;
        case 4:
            return 25;
        case 5:
            return 24;
        case 6:
            return 20;
        case 7:
            return 24;
        case 8:
            return 18;
        case 9:
            return 25;
        case 10:
            return 25;
        case 11:
            return 18;
        case 12:
            return 19;
        default:
            return 0;
        }
    }

// The charisma cells (Amaterasu and Tsukiyomi 25; Kishijoten 25; Yamamoto the
// 17 mortal row)
inline int jpnAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 25;
        case 2:
            return 20;
        case 3:
            return 24;
        case 4:
            return 21;
        case 5:
            return 25;
        case 6:
            return 20;
        case 7:
            return 19;
        case 8:
            return 18;
        case 9:
            return 22;
        case 10:
            return 25;
        case 11:
            return 17;
        case 12:
            return 18;
        default:
            return 0;
        }
    }

// The psionic score cells (0 = every being reads the R849 class table this
// round; no point scores printed)
inline int jpnAbiPsi(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Ama-Tsu-Mara through Yoshi-iye)
inline int jpnRosOrd(int b)
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
            return 11;
        case 12:
            return 12;
        default:
            return 0;
        }
    }

// The print page cells (81-85, the folio offset PRINT = PDF - 1)
inline int jpnRosPage(int b)
    {
        switch (b) {
        case 0:
            return 81;
        case 1:
            return 81;
        case 2:
            return 81;
        case 3:
            return 82;
        case 4:
            return 82;
        case 5:
            return 82;
        case 6:
            return 83;
        case 7:
            return 83;
        case 8:
            return 84;
        case 9:
            return 84;
        case 10:
            return 84;
        case 11:
            return 85;
        case 12:
            return 85;
        default:
            return 0;
        }
    }

// The alignment cells (0 LG, 1 NG, 2 CG, 3 LN, 4 N, 5 CN, 6 LE, 7 NE, 8 CE -
// the R852 code scheme)
inline int jpnRosAlign(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The rank cells (0 lesser, 1 greater, 2 demigod, 3 hero - no titans, no
// monsters this round)
inline int jpnRosRank(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 3;
        default:
            return 0;
        }
    }

// The psionic class cells (the chocr glyph-width decode at 600dpi: single
// pipe w10 Amaterasu, Ebisu, Hachiman; II w30 Kishijoten; V w36 Ama-Tsu-Mara,
// Oh-Kuni-Nushi, Raiden, Susanowo; VI w49 Daikoku, Tsukiyomi; 0 the Nil
// heroes)
inline int jpnRosPsiClass(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 6;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The plane cells (0 none of the three heroes, 1 Prime Material of
// Ama-Tsu-Mara, Amaterasu, Daikoku, Kishijoten, 2 Gladsheim of Hachiman and
// Oh-Kuni-Nushi, 3 the Seven Heavens of Ebisu the pixel catch, 4 Elysium of
// Tsukiyomi, 5 Limbo of Susanowo, 6 the Elemental Plane of Air of Raiden)
inline int jpnRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 6;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 4;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The fixed-damage flags (1 = the printed numeric damage; 0 = the Raiko
// by-weapon row and the Yoshi-iye arrow-or-weapon row)
inline int jpnRosDmgFixed(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The in-each flags (the printed Nth level in each cells: Amaterasu MU/I 20
// and M/B 15, Daikoku MU/I 12, Kishijoten MU/I 20, Oh-Kuni-Nushi M/B 10,
// Raiden MU/I 15, Susanowo C/D 10, Tsukiyomi MU/I 15, Yoshi-iye M/B 5 - the
// MONK/BARD in-each pairs new this round)
inline int jpnRosInEach(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The enmity flags (none printed this round: zero flags)
inline int jpnRosEnmity(int b)
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
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
