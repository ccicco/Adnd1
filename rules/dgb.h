// =========================================================================================
// Adnd1 - rules/dgb.h
// the American Indian mythos - the D&DG walk round two, print pp. 12-16: the
// North American pantheon, fourteen beings from the Raven to Tobadzistsini,
// the pantheon doctrine and the sacred bundle.
// census 772 -> 773.
//
// primary ink: the extract/ddg tesseract pass (commit cd645b4, pNNN_full.txt
// + pNNN_tsv.tsv, print = pdf - 1, pages 013-017); the four-voice collation
// adjudications (the TSV word geometry and the archive.org 1st-print
// derivative): Heng, Hotoru and Yanauluha attacks printed 3/2 (the 47-48px
// three-glyph width matches the known-good Qagwaaz/Stoneribs 3/2, against the
// Termux dropped-glyph 3.2), Coyote psionic class III and Hastsezini II (the
// IA geometry 47px), Hastsezini CH -1 (both voices read CH:-], five glyphs,
// the horror-table doctrine), Shakak CH 6 (both voices, four glyphs), the
// Thunder Bird X/22,600 xp line (both voices), and Stoneribs size 5 and one
// half feet (66 inches).
//
// the 0 sentinels: MoveAlt 0 = a single printed move; AtD 0 = a single
// printed attacks figure; the magic resistance 0 = the printed Standard
// (Hiawatha, Qagwaaz, Stoneribs); the ability-grid Thunder Bird row is all 0
// (the monster-format being prints no ability line); the class-grid 0 = Nil
// or none printed (Hastsezini magic-user 0 = the printed See below - the
// 30th-level fire spells ride the consts); roster Plane 0 = none printed (the
// heroes), worship 0 = none printed, lair percent 0 = none printed, XP 0 =
// none printed (the Thunder Bird row carries 22600).
//
namespace rules {

// ---- the R850 census ----

// the American Indian mythos round: the D&DG walk round two, print pp. 12-16
inline int dgbRound()
    { return 850; }

// the walk opens at print p. 12 (the Raven doctrine page)
inline int dgbPrintStart()
    { return 12; }

// the walk closes at print p. 16 (the Tobadzistsini block)
inline int dgbPrintEnd()
    { return 16; }

// the fourteen beings of the American Indian mythos
inline int dgbBeingCount()
    { return 14; }

// the four grids: combat, class, ability, roster
inline int dgbTableCount()
    { return 4; }

// no chains this round - the grids and the prose pins carry the walk
inline int dgbChainCount()
    { return 0; }

// zero registry defs touched - the MM1 live registry floor holds at 995
inline int dgbRegistryFloor()
    { return 995; }

// the psionic class ceiling VI (the front-matter psionic class table)
inline int dgbPsiClassMax()
    { return 6; }

// the combat grid row count (one row per being)
inline int dgbCbtRows()
    { return 14; }

// the class grid row count
inline int dgbClsRows()
    { return 14; }

// the ability grid row count
inline int dgbAbiRows()
    { return 14; }

// the roster grid row count
inline int dgbRosRows()
    { return 14; }

// ---- the pantheon doctrine ----

// the gods will always prefer to appear in the form of a creature of the land
inline bool dgbGodsPreferCreatureForm()
    { return true; }

// human-form appearances require great energy and may last only a short time
inline bool dgbHumanFormCostly()
    { return true; }

// a controlling ritual must have part of the thing already (the rain-summon
// sprinkling)
inline bool dgbControlRequiresPart()
    { return true; }

// a quest spell needs a part of the being - hair, used clothing, or the like
inline bool dgbQuestNeedsPart()
    { return true; }

// no charm spell works on an Indian priest without knowledge of that priest's
// name
inline bool dgbNameBlocksCharm()
    { return true; }

// all rituals involving demons or devils require a large fire for control
inline bool dgbDemonControlNeedsFire()
    { return true; }

// the season ebb is the sacrifice time - food, jewelry, battle weapons burned
// for the tribe
inline bool dgbSeasonalSacrifice()
    { return true; }

// Indian clerics are expected apart from the tribe daily in meditation with
// the patron deity
inline bool dgbClericMeditatesApart()
    { return true; }

// when great evil comes it is the cleric who protects the tribe, by action or
// sacrifice
inline bool dgbClericTribeProtector()
    { return true; }

// the fortified magical symbols and relics are buried with the cleric at
// death
inline bool dgbRelicsBuriedWithCleric()
    { return true; }

// the relic selection is personal, from visions received at the career start
inline bool dgbRelicsFromVisions()
    { return true; }

// one symbol always reflects the patron deity's symbol
inline bool dgbPatronSymbolReflected()
    { return true; }

// young Indian clerics enter battle alongside the warriors
inline bool dgbYoungClericsFight()
    { return true; }

// the older clerics enlist the help of the tribal gods for the battle
inline bool dgbOldClericsEnlistGods()
    { return true; }

// the tribal priest makes the warpaint and blesses the men and weapons before
// battle
inline bool dgbPriestBlessesWarpaint()
    { return true; }

// the cleric tent or lodge is taboo to the tribe, guarded by strong spirits
inline bool dgbLodgeTabooSpirits()
    { return true; }

// worship of most deities is held in the open
inline bool dgbWorshipInTheOpen()
    { return true; }

// the sacred bundle: +2 on all saving throws
inline int dgbBundleSaveBonus()
    { return 2; }

// the bundle owner is surprised only on a roll of 1 in 6
inline int dgbBundleSurpriseDen()
    { return 6; }

// the bundle owner has armor class 2
inline int dgbBundleAC()
    { return 2; }

// one point subtracted from each die of damage done to the owner in battle
inline int dgbBundleDmgPerDie()
    { return 1; }

// a sacred bundle always holds at least 5 items
inline int dgbBundleMinItems()
    { return 5; }

// a sacred bundle never holds more than 10 items
inline int dgbBundleMaxItems()
    { return 10; }

// the bundle items are indicated by a summoned spirit as sacred to that
// Indian
inline bool dgbBundleSpiritAdvised()
    { return true; }

// the tribal priest demands the last offering placed in the bag be of his own
// choosing
inline bool dgbBundlePriestFinalItem()
    { return true; }

// ---- the Raven walk ----

// the Raven damage/attack die 1 low (3-18)
inline int dgbRavenDmg1Lo()
    { return 3; }

// the Raven damage/attack die 1 high
inline int dgbRavenDmg1Hi()
    { return 18; }

// the Raven damage/attack die 2 low (3-18)
inline int dgbRavenDmg2Lo()
    { return 3; }

// the Raven damage/attack die 2 high
inline int dgbRavenDmg2Hi()
    { return 18; }

// the Raven damage/attack die 3 low (3-30)
inline int dgbRavenDmg3Lo()
    { return 3; }

// the Raven damage/attack die 3 high
inline int dgbRavenDmg3Hi()
    { return 30; }

// the Raven polymorph-others special attack: -3 to save
inline int dgbRavenPolySaveMod()
    { return 3; }

// the great transformer-trickster, responsible for the
// creation/transformation of the world
inline bool dgbRavenTransformer()
    { return true; }

// he will fight only as a last resort and then only as a giant raven
inline bool dgbRavenFightsAsGiantRaven()
    { return true; }

// besides a raven he may appear as a fox, a jay or the moon
inline bool dgbRavenExtraForms()
    { return true; }

// known as the great provider for mankind, including the giving of fire
inline bool dgbRavenGreatProvider()
    { return true; }

// the most successful appeal is by offerings of food; he intervenes for his
// worshipers in need
inline bool dgbRavenFoodOfferings()
    { return true; }

// ---- the Coyote walk ----

// the Coyote bite damage low (3-30 when cornered)
inline int dgbCoyoteBiteLo()
    { return 3; }

// the Coyote bite damage high
inline int dgbCoyoteBiteHi()
    { return 30; }

// Coyote is responsible for teaching arts, crafts and the use of light and
// fire
inline bool dgbCoyoteTaughtArtsAndFire()
    { return true; }

// he is primarily a bullying, greedy trickster, difficult to understand
inline bool dgbCoyoteBullyingGreedy()
    { return true; }

// as a trickster he is usually accompanied by a giant wolf, sometimes a fox,
// wildcat, badger or porcupine
inline bool dgbCoyoteBeastCompanions()
    { return true; }

// often his tricks will backfire on him
inline bool dgbCoyoteTricksBackfire()
    { return true; }

// his role is primarily that of a cowardly thief
inline bool dgbCoyoteCowardlyThiefRole()
    { return true; }

// Coyote can polymorph himself once per day but is limited to the animal
// kingdom
inline bool dgbCoyotePolymorphOnceDaily()
    { return true; }

// Coyote will flee combat whenever possible, but when cornered he will fight
inline bool dgbCoyoteFleesWhenPossible()
    { return true; }

// in trickery his two favorite spells are invisibility and animate object
inline bool dgbCoyoteFavoriteSpells()
    { return true; }

// his followers appeal to him to improve thieving abilities or for
// illusionist tricks of fire, light or darkness
inline bool dgbCoyoteThievingAppeals()
    { return true; }

// ---- the fire god walk (Hastsezini) ----

// the flame-wreath heat aura damage low (2-20)
inline int dgbHastseAuraLo()
    { return 2; }

// the flame-wreath heat aura damage high
inline int dgbHastseAuraHi()
    { return 20; }

// the aura reaches all within 10 yards
inline int dgbHastseAuraRange()
    { return 10; }

// he is aware of anything happening within 50 yards of any fire
inline int dgbHastseFireSense()
    { return 50; }

// he uses a +5 shield in battle that no other being can wield
inline int dgbHastseShieldPlus()
    { return 5; }

// the fire-bow shaft damage low (1-10)
inline int dgbHastseBowLo()
    { return 1; }

// the fire-bow shaft damage high
inline int dgbHastseBowHi()
    { return 10; }

// the hand axe damage low (2-20)
inline int dgbHastseAxeLo()
    { return 2; }

// the hand axe damage high
inline int dgbHastseAxeHi()
    { return 20; }

// the lance of fire damage low (3-30)
inline int dgbHastseLanceLo()
    { return 3; }

// the lance of fire damage high
inline int dgbHastseLanceHi()
    { return 30; }

// when hard-pressed by more than 5 enemies he turns to fire spells
inline int dgbHastsePressCount()
    { return 5; }

// the fire spells of any type, cast as a 30th level spell caster
inline int dgbHastsePressLevel()
    { return 30; }

// jet black and extremely ugly, always wreathed in flames
inline bool dgbHastseBlackUglyFlames()
    { return true; }

// he cannot be attacked from behind
inline bool dgbHastseNoBehindAttack()
    { return true; }

// fond of destroying by fire the villages that do not sacrifice to him
inline bool dgbHastseBurnsVillages()
    { return true; }

// fearing tribes sacrifice food and fresh meat by burning at high noon,
// especially in the dry season
inline bool dgbHastseNoonOfferings()
    { return true; }

// the fire bow's range is line of sight
inline bool dgbHastseBowLineOfSight()
    { return true; }

// he often throws the hand axe at the strongest enemy he faces
inline bool dgbHastseAxeAtStrongest()
    { return true; }

// he never throws the lance of fire
inline bool dgbHastseLanceNeverThrown()
    { return true; }

// his cleric/druid spells are offensive spells only
inline bool dgbHastseOffensiveOnly()
    { return true; }

// ---- the racing god walk (Hastseltsi) ----

// the giant maroon horse armor class 5
inline int dgbHastseltsiHorseAC()
    { return 5; }

// the giant maroon horse hit dice 15
inline int dgbHastseltsiHorseHD()
    { return 15; }

// the giant maroon horse hit points 70
inline int dgbHastseltsiHorseHP()
    { return 70; }

// the giant maroon horse attacks: 2-20/2-20/1-12
inline int dgbHastseltsiHorseAtN()
    { return 3; }

// the horse damage die 1 low (2-20)
inline int dgbHastseltsiHorseDmg1Lo()
    { return 2; }

// the horse damage die 1 high
inline int dgbHastseltsiHorseDmg1Hi()
    { return 20; }

// the horse damage die 3 low (1-12)
inline int dgbHastseltsiHorseDmg3Lo()
    { return 1; }

// the horse damage die 3 high
inline int dgbHastseltsiHorseDmg3Hi()
    { return 12; }

// his hand axe damage low (2-12, a +3 weapon)
inline int dgbHastseltsiAxeLo()
    { return 2; }

// his hand axe damage high
inline int dgbHastseltsiAxeHi()
    { return 12; }

// the hand axe +3
inline int dgbHastseltsiAxePlus()
    { return 3; }

// his throwing knife damage low (1-10, a +2 weapon)
inline int dgbHastseltsiKnifeLo()
    { return 1; }

// his throwing knife damage high
inline int dgbHastseltsiKnifeHi()
    { return 10; }

// the throwing knife +2
inline int dgbHastseltsiKnifePlus()
    { return 2; }

// the damage/attack strength modifier (+14: 2-12 (+14) or 1-10 (+14))
inline int dgbHastseltsiDmgMod()
    { return 14; }

// appears as a man, all of whose equipment is red
inline bool dgbHastseltsiRedEquipment()
    { return true; }

// he enters a tribal area because he desires to race, with any person and in
// any way
inline bool dgbHastseltsiRacesAnyone()
    { return true; }

// he never shows his godlike abilities, always running just a little faster
// than his opponent
inline bool dgbHastseltsiHidesPower()
    { return true; }

// the horse is enchanted to run faster than anything it competes against
inline bool dgbHastseltsiHorseEnchanted()
    { return true; }

// Hastseltsi cannot be hurt by any projectile or aerial attack
inline bool dgbHastseltsiNoProjectileHurt()
    { return true; }

// sometimes symbolized by a massively-muscled running horse, on his priests'
// lodges and shields
inline bool dgbHastseltsiSymbolOnLodges()
    { return true; }

// the printed THIEF/ASSASSIN line reads 12th level assassin - no thief level
// is printed
inline bool dgbHastseltsiAssassinTrained()
    { return false; }

// ---- the thunder spirit walk (Heng) ----

// the lightning bow damage low (6-60 per strike)
inline int dgbHengBowLo()
    { return 6; }

// the lightning bow damage high
inline int dgbHengBowHi()
    { return 60; }

// the bow range is 30 miles
inline int dgbHengBowRangeMiles()
    { return 30; }

// the lance damage low (3-30, used only when closely pressed)
inline int dgbHengLanceLo()
    { return 3; }

// the lance damage high
inline int dgbHengLanceHi()
    { return 30; }

// the warrior he copies gets +2 to hit enemies for the whole year
inline int dgbHengLuckBonus()
    { return 2; }

// the damage/attack strength modifier (+12: 6-60 or 3-30 (+12))
inline int dgbHengDmgMod()
    { return 12; }

// his priests must sprinkle large quantities of water on the ground to
// attract his attention for rain
inline bool dgbHengPriestsSprinkleWater()
    { return true; }

// if he answers he appears in a rolling thunder cloud as a braided warrior of
// the summoning tribe
inline bool dgbHengThunderCloudForm()
    { return true; }

// favored among all the Indian tribes - relied upon to bring rain to those
// that suffer and luck to those that hurt
inline bool dgbHengFavoredOfTribes()
    { return true; }

// ---- the hero walks (Hiawatha, Qagwaaz, Stoneribs) ----

// the bear-hug damage low (2-20 per melee round)
inline int dgbHiawathaHugLo()
    { return 2; }

// the bear-hug damage high
inline int dgbHiawathaHugHi()
    { return 20; }

// the FIGHTER line reads 15th level paladin (over) 10th level ranger
inline bool dgbHiawathaPaladin()
    { return true; }

// possibly the greatest of all Indian heroes, found with many other names in
// many cultures of America
inline bool dgbHiawathaManyNames()
    { return true; }

// he travels the rivers on a canoe that moves by itself
inline bool dgbHiawathaSelfMovingCanoe()
    { return true; }

// the animals of the area talk to him, warning him of possible dangers
inline bool dgbHiawathaAnimalsWarn()
    { return true; }

// a loner who transcends tribal feuds, helps all people in trouble, a great
// peacemaker and defender of the weak
inline bool dgbHiawathaPeacemaker()
    { return true; }

// he fought the great bear of death and won through hand-to-hand combat
inline bool dgbHiawathaGreatBear()
    { return true; }

// found chasing and capturing horses and buffalo on the plains for sport
inline bool dgbQagwaazPlainsSport()
    { return true; }

// enters villages to test his strength against the best warriors there
inline bool dgbQagwaazStrengthTests()
    { return true; }

// he fights with a huge wooden club, letting his strength do the talking
inline bool dgbQagwaazWoodenClub()
    { return true; }

// a hero of the plains, existing to set an example for the best warriors of
// any given tribe
inline bool dgbQagwaazExampleForWarriors()
    { return true; }

// always the first in battle and a favorite among women
inline bool dgbQagwaazFirstInBattle()
    { return true; }

// his size is 5 and one half feet - encoded as 66 inches (the adjudicated
// garbled-size cell)
inline int dgbStoneribsSizeIn()
    { return 66; }

// his cloak enables him to turn into a halibut at will
inline bool dgbStoneribsHalibutCloak()
    { return true; }

// he can shrink to any size he chooses
inline bool dgbStoneribsShrinksAtWill()
    { return true; }

// he attacks with a bow or club
inline bool dgbStoneribsBowOrClub()
    { return true; }

// famed for great strength, he wanders from tribe to tribe and fights the
// best each tribe has
inline bool dgbStoneribsTribesChampion()
    { return true; }

// when he loses he stays with the tribe for one year and fights in their
// battles
inline bool dgbStoneribsYearService()
    { return true; }

// ---- the wind god walk (Hotoru) ----

// he casts three lightning bolts per round
inline int dgbHotoruBoltsPerRound()
    { return 3; }

// the lightning bolt damage low (2-20 each)
inline int dgbHotoruBoltLo()
    { return 2; }

// the lightning bolt damage high
inline int dgbHotoruBoltHi()
    { return 20; }

// the lightning bolt range is 900 yards
inline int dgbHotoruBoltRange()
    { return 900; }

// while he wears the chief's form, that chief gains +1 on all saving throws
inline int dgbHotoruChiefSaveBonus()
    { return 1; }

// sometimes influenced by human needs for weather or crop growth - and can
// destroy the same for any slight to his priesthood
inline bool dgbHotoruWeatherCrops()
    { return true; }

// he takes on the form of the chief of any village he is near
inline bool dgbHotoruChiefForm()
    { return true; }

// if lightning does not work he will use any fallen weapon he can pick up in
// battle
inline bool dgbHotoruFallenWeapons()
    { return true; }

// ---- the winter spirit walk (Shakak) ----

// the cold aura: 20 points of damage per melee round within 30 yards, no
// saving throw
inline int dgbShakakAuraDmg()
    { return 20; }

// the cold aura range in yards
inline int dgbShakakAuraRange()
    { return 30; }

// the ice spear damage low (3-30 per strike)
inline int dgbShakakSpearLo()
    { return 3; }

// the ice spear damage high
inline int dgbShakakSpearHi()
    { return 30; }

// below freezing he regenerates 10 points per melee round
inline int dgbShakakRegenPerRound()
    { return 10; }

// the damage/attack strength modifier (+9: 3-30 (+9))
inline int dgbShakakDmgMod()
    { return 9; }

// this white-skinned deity can bring on any kind of cold weather at will
inline bool dgbShakakColdAtWill()
    { return true; }

// those that sacrifice to him can often lessen the force of winter
inline bool dgbShakakSacrificeLessensWinter()
    { return true; }

// no one prays to this evil being for fear that he will come
inline bool dgbShakakNonePrayForFear()
    { return true; }

// sacrifices always take the form of burning precious possessions during the
// dead of winter
inline bool dgbShakakBurnPossessions()
    { return true; }

// his form is usually human but his face is demonic with fangs and blazing
// white eyes
inline bool dgbShakakDemonicFace()
    { return true; }

// his body radiates cold: 20 points per melee round within 30 yards, no
// saving throw
inline bool dgbShakakColdAuraNoSave()
    { return true; }

// his spear is made of ice
inline bool dgbShakakIceSpear()
    { return true; }

// when the temperature is below freezing he regenerates 10 points per melee
// round
inline bool dgbShakakRegenBelowFreezing()
    { return true; }

// ---- the serpent god walk (Snake-Man) ----

// he always wears 75,000 gold pieces worth of jewelry
inline int dgbSnakemanJewelryGP()
    { return 75000; }

// the snake summons low (5-500 random snakes, once per day)
inline int dgbSnakemanSummonLo()
    { return 5; }

// the snake summons high
inline int dgbSnakemanSummonHi()
    { return 500; }

// appears in the shape of a man with rainbow-colored skin
inline bool dgbSnakemanRainbowSkin()
    { return true; }

// he ages at will, often visibly turning younger or older in long
// conversations
inline bool dgbSnakemanAgesAtWill()
    { return true; }

// he can control all reptiles
inline bool dgbSnakemanControlsReptiles()
    { return true; }

// no reptile type will attack him, even if magically controlled
inline bool dgbSnakemanReptilesNeverAttack()
    { return true; }

// the defense extends to fantastic reptilian beings - certain devils, demons,
// dragons and the like
inline bool dgbSnakemanFantasticReptilians()
    { return true; }

// never known to attack beings with other than spells
inline bool dgbSnakemanSpellsOnly()
    { return true; }

// against magic-impervious creatures he summons snakes to fight for him
// instead
inline bool dgbSnakemanSnakesVsImpervious()
    { return true; }

// ---- the Thunder Bird walk ----

// it can cast one lightning bolt per round
inline int dgbTbirdBoltsPerRound()
    { return 1; }

// each bolt does 30 points of damage (save for half)
inline int dgbTbirdBoltDmg()
    { return 30; }

// the bolt range low, 50 yards
inline int dgbTbirdBoltRangeLo()
    { return 50; }

// the bolt range high, 300 yards
inline int dgbTbirdBoltRangeHi()
    { return 300; }

// the beak bite damage low (1-10)
inline int dgbTbirdBeakLo()
    { return 1; }

// the beak bite damage high
inline int dgbTbirdBeakHi()
    { return 10; }

// the wing bludgeon damage low (2-20)
inline int dgbTbirdWingLo()
    { return 2; }

// the wing bludgeon damage high
inline int dgbTbirdWingHi()
    { return 20; }

// frequency: unique, number appearing 1 - the monster-format being of the
// mythos
inline bool dgbTbirdUnique()
    { return true; }

// its intelligence is Genius
inline bool dgbTbirdIntGenius()
    { return true; }

// never surprised because of the warning its superb senses give
inline bool dgbTbirdNeverSurprised()
    { return true; }

// when ready to attack its wings beat together and thunder sounds
inline bool dgbTbirdThunderWings()
    { return true; }

// never invoked; always comes of its own will and does not leave until the
// battle is done, known to die and appear again years later
inline bool dgbTbirdComesOfOwnWill()
    { return true; }

// ---- the first priest walk (Yanauluha) ----

// a 10 percent chance at each occurrence that he appears and personally helps
inline int dgbYanaAppearPct()
    { return 10; }

// the first of all tribal clerics
inline bool dgbYanaFirstCleric()
    { return true; }

// able to summon any spirit (god) of this pantheon to his people
inline bool dgbYanaSummonsPantheon()
    { return true; }

// now classified as a friendly spirit
inline bool dgbYanaFriendlySpirit()
    { return true; }

// invoked by Indian priests whenever they need an especially large boon from
// the gods
inline bool dgbYanaInvokedForBoons()
    { return true; }

// not worshiped as a god, though sacrifices in the form of magic items are
// made to him
inline bool dgbYanaNotWorshiped()
    { return true; }

// appears as an old man in rich Indian garb who talks very slowly
inline bool dgbYanaOldManForm()
    { return true; }

// the only Neutral being of the fourteen (the roster grid Law/Good 0,0)
inline bool dgbYanaNeutral()
    { return true; }

// ---- the war spirit walk (Tobadzistsini) ----

// his arrows strike for 1-10 points of damage
inline int dgbTobadArrowLo()
    { return 1; }

// the arrow damage high
inline int dgbTobadArrowHi()
    { return 10; }

// his spear strikes for 3-30, hand-to-hand combat only
inline int dgbTobadSpearLo()
    { return 3; }

// the spear damage high
inline int dgbTobadSpearHi()
    { return 30; }

// the damage/attack strength modifier (+14: 1-10/3-30 (+14))
inline int dgbTobadDmgMod()
    { return 14; }

// usually appears as a massively built male
inline bool dgbTobadBuiltMaleForm()
    { return true; }

// he can shape change at will
inline bool dgbTobadShapeChange()
    { return true; }

// occasionally on a whim he enters battles between tribes that interest him
inline bool dgbTobadWhimsicalBattles()
    { return true; }

// either by personally taking a hand or increasing the abilities of one side
// or another
inline bool dgbTobadBoostsOneSide()
    { return true; }

// the spear is used only for hand-to-hand combat
inline bool dgbTobadSpearHandToHand()
    { return true; }

// worshiping warriors promise him kills in battle, which are burned after the
// victory
inline bool dgbTobadKillsBurned()
    { return true; }

// ---- the combat grid ----

// The armor class cells
inline int dgbCbtAC(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return -3;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return -2;
        case 7:
            return 6;
        case 8:
            return -2;
        case 9:
            return -2;
        case 10:
            return 6;
        case 11:
            return -2;
        case 12:
            return 3;
        case 13:
            return -2;
        default:
            return 0;
        }
    }

// The hit point cells (the Thunder Bird hit dice/points 200 rides here)
inline int dgbCbtHP(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 330;
        case 2:
            return 320;
        case 3:
            return 320;
        case 4:
            return 250;
        case 5:
            return 200;
        case 6:
            return 200;
        case 7:
            return 150;
        case 8:
            return 390;
        case 9:
            return 350;
        case 10:
            return 150;
        case 11:
            return 200;
        case 12:
            return 200;
        case 13:
            return 344;
        default:
            return 0;
        }
    }

// The primary move cells (inches)
inline int dgbCbtMove(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 21;
        case 3:
            return 24;
        case 4:
            return 12;
        case 5:
            return 15;
        case 6:
            return 12;
        case 7:
            return 15;
        case 8:
            return 12;
        case 9:
            return 12;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 12;
        case 13:
            return 15;
        default:
            return 0;
        }
    }

// The alternate move cells (0 = a single printed move; the 24/48, 12/24,
// 12/18 and 15/24 dual moves)
inline int dgbCbtMoveAlt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 48;
        case 4:
            return 24;
        case 5:
            return 0;
        case 6:
            return 24;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 18;
        case 10:
            return 0;
        case 11:
            return 24;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The attacks-per-round numerator cells
inline int dgbCbtAtN(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 2;
        default:
            return 0;
        }
    }

// The attacks-per-round denominator cells (0 = a single printed figure; Heng,
// Hotoru, Qagwaaz, Stoneribs and Yanauluha read the printed 3/2 - the 47-48px
// three-glyph width matches the known-good Qagwaaz/Stoneribs 3/2, against the
// Termux dropped-glyph 3.2)
inline int dgbCbtAtD(int b)
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
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 2;
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
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance percent cells (0 = the printed Standard; Shakak 90 is
// versus fire only)
inline int dgbCbtMR(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 75;
        case 2:
            return 45;
        case 3:
            return 50;
        case 4:
            return 20;
        case 5:
            return 0;
        case 6:
            return 30;
        case 7:
            return 0;
        case 8:
            return 90;
        case 9:
            return 75;
        case 10:
            return 0;
        case 11:
            return 32;
        case 12:
            return 30;
        case 13:
            return 30;
        default:
            return 0;
        }
    }

// The size letter cells (0 = M, 1 = L)
inline int dgbCbtSize(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// ---- the class grid ----

// The cleric level cells (0 = Nil or none printed; Yanauluha reads 13th level
// druid over 20th level cleric - cleric 20, druid 13)
inline int dgbClsCleric(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 14;
        case 2:
            return 12;
        case 3:
            return 10;
        case 4:
            return 10;
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
            return 20;
        case 13:
            return 10;
        default:
            return 0;
        }
    }

// The druid level cells
inline int dgbClsDruid(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 14;
        case 2:
            return 12;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 8;
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
            return 13;
        case 13:
            return 10;
        default:
            return 0;
        }
    }

// The fighter level cells (Hiawatha 15 is the 15th level paladin half of his
// line)
inline int dgbClsFighter(int b)
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
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The ranger level cells
inline int dgbClsRanger(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 10;
        case 11:
            return 0;
        case 12:
            return 10;
        case 13:
            return 18;
        default:
            return 0;
        }
    }

// The magic-user level cells (Hastsezini 0 = the printed See below - the
// 30th-level fire spells ride the consts)
inline int dgbClsMagUser(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 14;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 15;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 9;
        case 13:
            return 10;
        default:
            return 0;
        }
    }

// The illusionist level cells
inline int dgbClsIllus(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 17;
        case 2:
            return 0;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 9;
        case 13:
            return 10;
        default:
            return 0;
        }
    }

// The thief level cells
inline int dgbClsThief(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 18;
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
            return 8;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The assassin level cells
inline int dgbClsAssassin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 12;
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
        case 13:
            return 10;
        default:
            return 0;
        }
    }

// The monk level cells (0 = Nil)
inline int dgbClsMonk(int b)
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
        case 13:
            return 8;
        default:
            return 0;
        }
    }

// The bard level cells (0 = Nil)
inline int dgbClsBard(int b)
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
            return 5;
        case 8:
            return 0;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// ---- the ability grid ----

// The strength cells (0 = none printed)
inline int dgbAbiStr(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 20;
        case 2:
            return 24;
        case 3:
            return 25;
        case 4:
            return 24;
        case 5:
            return 21;
        case 6:
            return 23;
        case 7:
            return 19;
        case 8:
            return 21;
        case 9:
            return 24;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 14;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The parenthesized strength to-hit bonus cells (0 = none printed)
inline int dgbAbiStrHit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 7;
        default:
            return 0;
        }
    }

// The parenthesized strength damage bonus cells
inline int dgbAbiStrDmg(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 8;
        case 2:
            return 12;
        case 3:
            return 14;
        case 4:
            return 12;
        case 5:
            return 9;
        case 6:
            return 11;
        case 7:
            return 7;
        case 8:
            return 9;
        case 9:
            return 0;
        case 10:
            return 7;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 14;
        default:
            return 0;
        }
    }

// The intelligence cells
inline int dgbAbiInt(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 24;
        case 2:
            return 20;
        case 3:
            return 19;
        case 4:
            return 23;
        case 5:
            return 18;
        case 6:
            return 23;
        case 7:
            return 18;
        case 8:
            return 19;
        case 9:
            return 24;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 20;
        default:
            return 0;
        }
    }

// The wisdom cells
inline int dgbAbiWis(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 19;
        case 2:
            return 19;
        case 3:
            return 18;
        case 4:
            return 23;
        case 5:
            return 18;
        case 6:
            return 20;
        case 7:
            return 19;
        case 8:
            return 19;
        case 9:
            return 19;
        case 10:
            return 14;
        case 11:
            return 0;
        case 12:
            return 20;
        case 13:
            return 19;
        default:
            return 0;
        }
    }

// The dexterity cells (the printed D: column)
inline int dgbAbiDex(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 24;
        case 2:
            return 23;
        case 3:
            return 25;
        case 4:
            return 22;
        case 5:
            return 19;
        case 6:
            return 23;
        case 7:
            return 18;
        case 8:
            return 20;
        case 9:
            return 23;
        case 10:
            return 18;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The constitution cells
inline int dgbAbiCon(int b)
    {
        switch (b) {
        case 0:
            return 23;
        case 1:
            return 21;
        case 2:
            return 24;
        case 3:
            return 24;
        case 4:
            return 24;
        case 5:
            return 19;
        case 6:
            return 23;
        case 7:
            return 18;
        case 8:
            return 24;
        case 9:
            return 24;
        case 10:
            return 19;
        case 11:
            return 0;
        case 12:
            return 19;
        case 13:
            return 25;
        default:
            return 0;
        }
    }

// The charisma cells (Hastsezini reads CH -1 - both voices, five glyphs, the
// horror-table doctrine; Shakak reads CH 6 - both voices, four glyphs)
inline int dgbAbiCha(int b)
    {
        switch (b) {
        case 0:
            return 22;
        case 1:
            return 16;
        case 2:
            return -1;
        case 3:
            return 22;
        case 4:
            return 20;
        case 5:
            return 18;
        case 6:
            return 20;
        case 7:
            return 18;
        case 8:
            return 6;
        case 9:
            return 20;
        case 10:
            return 15;
        case 11:
            return 0;
        case 12:
            return 18;
        case 13:
            return 20;
        default:
            return 0;
        }
    }

// The psionic class cells (0 = Nil or none printed, 1-6 the printed I-VI;
// Coyote III and Hastsezini II are the IA-geometry 47px adjudications against
// the Termux dropped-glyph reads)
inline int dgbAbiPsi(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 6;
        case 5:
            return 0;
        case 6:
            return 6;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 4;
        default:
            return 0;
        }
    }

// ---- the roster grid ----

// The roster ordinal cells (the print order, Raven to Tobadzistsini)
inline int dgbRosOrd(int b)
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
        case 13:
            return 13;
        default:
            return 0;
        }
    }

// The rank cells (0 greater god, 1 lesser god, 2 hero, 3 unique creature, 4
// the first-priest friendly spirit)
inline int dgbRosRank(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The print page cells (12-16, the folio offset PRINT = PDF - 1)
inline int dgbRosPage(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 13;
        case 4:
            return 13;
        case 5:
            return 14;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 15;
        case 9:
            return 15;
        case 10:
            return 15;
        case 11:
            return 16;
        case 12:
            return 16;
        case 13:
            return 16;
        default:
            return 0;
        }
    }

// The plane cells (0 none printed, 1 Prime Material, 2 Elemental Plane of
// Air, 3 Elemental Plane of Fire)
inline int dgbRosPlane(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The alignment lawful axis cells (1 lawful, 0 neutral, -1 chaotic)
inline int dgbRosLaw(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        default:
            return 0;
        }
    }

// The alignment good axis cells (1 good, 0 neutral, -1 evil)
inline int dgbRosGood(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return -1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return -1;
        default:
            return 0;
        }
    }

// The worshiper-alignment cells (0 none printed, 1 all alignments, 2 thieves
// and chaotic neutrals, 3 see below, 4 good alignments, 5 chaotic good, 6
// warriors)
inline int dgbRosWorship(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 6;
        default:
            return 0;
        }
    }

// The in-lair percent cells (0 = none printed; the Thunder Bird 25)
inline int dgbRosLairPct(int b)
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
            return 25;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

// The experience-value cells (0 = none printed; the Thunder Bird X/22,600
// rides as 22600 - both voices)
inline int dgbRosXP(int b)
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
            return 22600;
        case 12:
            return 0;
        case 13:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
