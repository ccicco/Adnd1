// =========================================================================================
// Adnd1 - rules/t24.h
// The Dragon issue-24 opener part one - the variant triptych
// census 876 -> 877.
//
// The opener of the issue-24 four-round shape - three of the fourteen
// Curtiss-called chains pinned as the variant triptych, the alignment
// pantheon riding its own part-two table round, the ten-chain commentary set
// at part three and the flip to follow. All pinned from The Dragon Vol. III
// No. 10 (April 1979) print 5-11 at extract/dragon/024, PRINT FOLIO = PDF
// PAGE this issue, the single-voice transcript of the Curtiss-provided scan -
// the issue runs 48 pages, the Kask editorial printing the paper-strike
// economy cut from 56. The intake seats the gap report and all forty-eight
// transcripts; the two inherited watches - the Sullin levels 7-9 and the
// brawling long-term-effects sequel - print nowhere in issue 24 and ride to
// TD 25.
//
namespace rules {

// ---- the lost civilizations Source of the Nile variant (print 5-6) ----

// the lost-city discovery roll - two dice, a two or three indicates a city
// has been discovered the lost civilizations Source of the Nile variant
// (print 5-6)
inline int t24LostCityRollHi()
    { return 3; }

// the organization roll - one die, one through three a warrior-king who is
// always a tyrant the lost civilizations Source of the Nile variant (print
// 5-6)
inline int t24TyrantBandHi()
    { return 3; }

// the tyrant army count - the product of three dice plus ten warriors the
// lost civilizations Source of the Nile variant (print 5-6)
inline int t24TyrantWarriorAdd()
    { return 10; }

// the priest city count - four through six rules the evil high priest and the
// beautiful white goddess, the product of three dice plus five the lost
// civilizations Source of the Nile variant (print 5-6)
inline int t24PriestWarriorAdd()
    { return 5; }

// the reaction modifier - attitude two or three adds nine to the number the
// lost civilizations Source of the Nile variant (print 5-6)
inline int t24ReactionAdd()
    { return 9; }

// the white goddess adds one - white goddesses are always interested in
// strangers the lost civilizations Source of the Nile variant (print 5-6)
inline int t24GoddessReactionBonus()
    { return 1; }

// a guide from a neighboring hex subtracts one - lost civilizations are
// usually at war with neighboring tribes the lost civilizations Source of the
// Nile variant (print 5-6)
inline int t24GuideReactionPenalty()
    { return 1; }

// the musket volley - the askaris shoot killing one warrior the lost
// civilizations Source of the Nile variant (print 5-6)
inline int t24AskariKill()
    { return 1; }

// the explorer kills two warriors with his musket the lost civilizations
// Source of the Nile variant (print 5-6)
inline int t24ExplorerKill()
    { return 2; }

// the missionary only kills one - the Modified Gygax rule the lost
// civilizations Source of the Nile variant (print 5-6)
inline int t24MissionaryKill()
    { return 1; }

// half the bearers drop their loads and run when the warriors close the lost
// civilizations Source of the Nile variant (print 5-6)
inline int t24BearersFleeDivisor()
    { return 2; }

// the prison-break reward - one hundred dollars in gold, five hundred in
// diamonds for a geologist the lost civilizations Source of the Nile variant
// (print 5-6)
inline int t24EscapeGold()
    { return 100; }

// the duel and flight rewards - five hundred dollars in diamonds or gold and
// gems at the volcano the lost civilizations Source of the Nile variant
// (print 5-6)
inline int t24EscapeDiamonds()
    { return 500; }

// the triumph escape - one thousand dollars in diamonds into an adjacent hex
// of the player choice the lost civilizations Source of the Nile variant
// (print 5-6)
inline int t24TriumphDiamonds()
    { return 1000; }

// the desert city looted - a bag of gems worth one thousand dollars the lost
// civilizations Source of the Nile variant (print 5-6)
inline int t24DesertLootGems()
    { return 1000; }

// each bearer carries off golden treasure worth two hundred dollars, equal to
// twenty gifts, discarding all other loads the lost civilizations Source of
// the Nile variant (print 5-6)
inline int t24BearerGold()
    { return 200; }

// publication as a work of fiction nets the explorer an additional five
// hundred dollars the lost civilizations Source of the Nile variant (print
// 5-6)
inline int t24NovelistFee()
    { return 500; }

// the desert curse - each turn roll one die and subtract two men dead,
// drained bloodless with terror frozen on their faces the lost civilizations
// Source of the Nile variant (print 5-6)
inline int t24CurseDiePenalty()
    { return 2; }

// an explorer re-entering a lost city he previously explored adds one to all
// his die rolls the lost civilizations Source of the Nile variant (print 5-6)
inline int t24ReenterBonus()
    { return 1; }

// if his wife the white goddess accompanies him he adds two - she takes all
// the risks and can count as an askari the lost civilizations Source of the
// Nile variant (print 5-6)
inline int t24WifeBonus()
    { return 2; }

// the Lord Underdog saga - the zoologist raised seven hundred dollars for the
// Zambezi expedition the lost civilizations Source of the Nile variant (print
// 5-6)
inline int t24UnderdogStake()
    { return 700; }

// Underdog earned a grand total of five points - the danger and excitement of
// nineteenth-century exploration the lost civilizations Source of the Nile
// variant (print 5-6)
inline int t24UnderdogPoints()
    { return 5; }

// the fantasy supplement frame - the encounters Allan Quartermain or Lord
// Greystoke would have had, Haggard and Burroughs the lost civilizations
// Source of the Nile variant (print 5-6)
inline bool t24SotnFantasySupplement()
    { return true; }

// the desert lost city is uninhabited and legendary - the bearers know it as
// a city of demons and try to desert the lost civilizations Source of the
// Nile variant (print 5-6)
inline bool t24DesertCityUninhabited()
    { return true; }

// every other hex holds survivors of lost Atlantis with bronze weapons and
// ornaments of gold decorated with rubies and diamonds the lost civilizations
// Source of the Nile variant (print 5-6)
inline bool t24AtlantisSurvivors()
    { return true; }

// some of the ruling class can speak ancient Greek - the explorer had a
// classical education himself the lost civilizations Source of the Nile
// variant (print 5-6)
inline bool t24AncientGreekSpeech()
    { return true; }

// the accepted expedition draws no disaster card, is fed by the city and the
// priests cure the sick the lost civilizations Source of the Nile variant
// (print 5-6)
inline bool t24GuestsOfTheCity()
    { return true; }

// a surprised expedition has no chance to shoot their muskets - the warriors
// close for hand to hand combat the lost civilizations Source of the Nile
// variant (print 5-6)
inline bool t24SurpriseMuskets()
    { return true; }

// the sacred pool - a mosasaurus, the gigantic aquatic dinosaur miraculously
// surviving the eons, devours prisoners the lost civilizations Source of the
// Nile variant (print 5-6)
inline bool t24MosasaurusPool()
    { return true; }

// the tyrant city holds a young noble aspirant offering help in return for
// support in a forthcoming rebellion the lost civilizations Source of the
// Nile variant (print 5-6)
inline bool t24RebelAspirant()
    { return true; }

// the white goddess falls in love with the explorer and gets him released
// from the dungeon under guard the lost civilizations Source of the Nile
// variant (print 5-6)
inline bool t24GoddessLovesExplorer()
    { return true; }

// the duel of magic and faith - gunpowder, a magnet and a magnifying lens
// against the Atlanean science of the high priest the lost civilizations
// Source of the Nile variant (print 5-6)
inline bool t24DuelOfMagic()
    { return true; }

// the curse kills guides first, then bearers, then askaris and finally the
// explorer until a civilized coastal hex the lost civilizations Source of the
// Nile variant (print 5-6)
inline bool t24DesertCurseRides()
    { return true; }

// the city may be re-entered only by the discovering explorer - any other
// explorer finds merely an uninhabited hex the lost civilizations Source of
// the Nile variant (print 5-6)
inline bool t24ExclusiveReturn()
    { return true; }

// ---- the Chinese dragons variant roster (print 8-9) ----

// a sixty percent chance of finding them in their lair - but they never sleep
// the Chinese dragons variant roster (print 8-9)
inline int t24LairPct()
    { return 60; }

// all Chinese dragons are psionic class six the Chinese dragons variant
// roster (print 8-9)
inline int t24PsionicClass()
    { return 6; }

// ESP at a radius of five times the age level of the dragon the Chinese
// dragons variant roster (print 8-9)
inline int t24EspRadiusMult()
    { return 5; }

// the Scaly Command duration floor - two to twelve hours the Chinese dragons
// variant roster (print 8-9)
inline int t24ScalyCommandHoursLo()
    { return 2; }

// the Scaly Command duration ceiling - the command cannot be dispelled the
// Chinese dragons variant roster (print 8-9)
inline int t24ScalyCommandHoursHi()
    { return 12; }

// Water Fire disappears for twenty rounds after real fire contact the Chinese
// dragons variant roster (print 8-9)
inline int t24WaterFireRoundsLo()
    { return 20; }

// the Water Fire absence ceiling - one hundred twenty rounds, none recreated
// until the end of that period the Chinese dragons variant roster (print 8-9)
inline int t24WaterFireRoundsHi()
    { return 120; }

// the Tien Lung breath - fire in a nine-by-three cone six times per day,
// damage of the hit dice times the age level the Chinese dragons variant
// roster (print 8-9)
inline int t24TienFirePerDay()
    { return 6; }

// the Tien Lung throws Control Weather at two times the age level number of
// times per day the Chinese dragons variant roster (print 8-9)
inline int t24TienControlMult()
    { return 2; }

// old and older Tien Lung - a fifty percent chance of one to six Wind
// Walkers, Aerial Servants or Spirits of the Air the Chinese dragons variant
// roster (print 8-9)
inline int t24TienServantPct()
    { return 50; }

// the Shen Lung cast three times a day - Control Weather or Ice Storm in any
// combination the Chinese dragons variant roster (print 8-9)
inline int t24ShenSpellPerDay()
    { return 3; }

// the Shen Lung ordinary attacks - two claws one to four, one bite two to
// twenty-four, one tail spike one to eight the Chinese dragons variant roster
// (print 8-9)
inline int t24ShenBiteHi()
    { return 24; }

// the Shen Lung Water Fire for two to twelve hits, Scaly Command for two to
// twenty creatures times the age level the Chinese dragons variant roster
// (print 8-9)
inline int t24ShenWaterFireHi()
    { return 12; }

// no insect, arachnid or arthropod may approach a Shen Lung within a radius
// of six feet the Chinese dragons variant roster (print 8-9)
inline int t24ShenInsectRadius()
    { return 6; }

// the Li Lung Earthquake - width and length each three times the age level,
// once a day without a chance of being dispelled the Chinese dragons variant
// roster (print 8-9)
inline int t24LiQuakeMult()
    { return 3; }

// the Li Lung attacks - two claws one to five and one bite one to twenty the
// Chinese dragons variant roster (print 8-9)
inline int t24LiBiteHi()
    { return 20; }

// the Pan Lung grasp - the bite of two to sixteen holds, the automatic bite
// for one to eight and the tail constricts for two to twelve more the Chinese
// dragons variant roster (print 8-9)
inline int t24PanConstrictHi()
    { return 12; }

// the Pan Lung throw Charm Monster three times per day the Chinese dragons
// variant roster (print 8-9)
inline int t24PanCharmPerDay()
    { return 3; }

// the Pan Lung Scaly Command for one to ten creatures, Water Fire for one to
// six points of damage the Chinese dragons variant roster (print 8-9)
inline int t24PanScalyHi()
    { return 10; }

// the Lung Wang breathe steam three times per day in a ten-by-five cone the
// Chinese dragons variant roster (print 8-9)
inline int t24WangSteamPerDay()
    { return 3; }

// the Lung Wang attacks - two claws one to twelve and one bite six to
// thirty-six the Chinese dragons variant roster (print 8-9)
inline int t24WangBiteHi()
    { return 36; }

// the Lung Wang Scaly Command at four to forty creatures times the age level
// the Chinese dragons variant roster (print 8-9)
inline int t24WangScalyHi()
    { return 40; }

// rolling up Yu Lung - bring all age levels of five or above down to adult
// the Chinese dragons variant roster (print 8-9)
inline int t24YuAdultCap()
    { return 5; }

// the Yu Lung emerge awkwardly onto land for up to one hour the Chinese
// dragons variant roster (print 8-9)
inline int t24YuLandHour()
    { return 1; }

// the six Chinese dragon types of the summary roster the Chinese dragons
// variant roster (print 8-9)
inline int t24DragonTypeCount()
    { return 6; }

// any alignment and any color - white red yellow blue green or black - the
// powers vary solely with the type the Chinese dragons variant roster (print
// 8-9)
inline bool t24PowersByType()
    { return true; }

// only the Yu Lung can be subdued - age and size rolled as for a normal
// dragon the Chinese dragons variant roster (print 8-9)
inline bool t24OnlyYuSubduable()
    { return true; }

// all except the Yu Lung polymorph at will into human form and back the
// Chinese dragons variant roster (print 8-9)
inline bool t24PolymorphHuman()
    { return true; }

// an invisible dragon becomes visible when attacking the Chinese dragons
// variant roster (print 8-9)
inline bool t24VisibleWhenAttacking()
    { return true; }

// no scaly creature of the water willingly attacks a Scaly Command dragon,
// and all dragons are themselves immune to the power the Chinese dragons
// variant roster (print 8-9)
inline bool t24ScalyCommandImmune()
    { return true; }

// no saving throw against the Scaly Command - creatures already under one
// dragon cannot fall under another the Chinese dragons variant roster (print
// 8-9)
inline bool t24ScalyCommandNoSave()
    { return true; }

// all Chinese dragons are immune to Water Fire - the unearthly stuff
// surrounds the body like the flame of a demon the Chinese dragons variant
// roster (print 8-9)
inline bool t24WaterFireImmune()
    { return true; }

// the Tien Lung are wingless but can still fly - the Imperial Dragons
// frequent the same haunts as Silver Dragons the Chinese dragons variant
// roster (print 8-9)
inline bool t24TienWinglessFlight()
    { return true; }

// the Shen Lung have no breath weapon the Chinese dragons variant roster
// (print 8-9)
inline bool t24ShenNoBreath()
    { return false; }

// the Shen Lung take no damage from lightning the Chinese dragons variant
// roster (print 8-9)
inline bool t24ShenLightningImmune()
    { return true; }

// the Shen Lung take double damage from fire - they love arsenic, bamboo and
// swallows the Chinese dragons variant roster (print 8-9)
inline bool t24ShenDoubleFire()
    { return true; }

// the Shen Lung are immune to poison the Chinese dragons variant roster
// (print 8-9)
inline bool t24ShenPoisonImmune()
    { return true; }

// the Li Lung are never harmed by any Earthquake though they may be
// inconvenienced by digging out of the rubble the Chinese dragons variant
// roster (print 8-9)
inline bool t24LiQuakeImmune()
    { return true; }

// the powerful claws of the Li Lung enable them to tunnel like Umber Hulks
// the Chinese dragons variant roster (print 8-9)
inline bool t24LiHulkTunnel()
    { return true; }

// the Pan Lung have no tail spike - the succeeding-turn grasp carries the
// automatic bite and the constrict the Chinese dragons variant roster (print
// 8-9)
inline bool t24PanGraspConstrict()
    { return true; }

// the Lung Wang rule large bodies of water and demand tribute from every
// passing ship the Chinese dragons variant roster (print 8-9)
inline bool t24WangTribute()
    { return true; }

// the Yu Lung cannot fly, polymorph or turn invisible the Chinese dragons
// variant roster (print 8-9)
inline bool t24YuNoPolymorph()
    { return false; }

// there are no older Yu Lung - they have achieved their hearts desire and
// metamorphosized into some other kind of Chinese dragon the Chinese dragons
// variant roster (print 8-9)
inline bool t24YuMetamorphosis()
    { return true; }

// the appearing floor - solitary Tien Lung and Lung Wang, one to four for the
// rest
inline int t24DgAppearLo(int b)
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
        default:
            return -99;
        }
    }

// the appearing ceiling - four for the common sorts
inline int t24DgAppearHi(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 4;
        default:
            return -99;
        }
    }

// the hit dice floor - five for the Carp, eleven for the two ruling sorts
inline int t24DgHdLo(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 9;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 11;
        case 5:
            return 5;
        default:
            return -99;
        }
    }

// the hit dice ceiling - thirteen at the top, eight for the small Pan Lung
inline int t24DgHdHi(int b)
    {
        switch (b) {
        case 0:
            return 13;
        case 1:
            return 11;
        case 2:
            return 9;
        case 3:
            return 8;
        case 4:
            return 13;
        case 5:
            return 7;
        default:
            return -99;
        }
    }

// the armor class - minus two for the Celestial, three for the Carp
inline int t24DgAc(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return 1;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 3;
        default:
            return -99;
        }
    }

// the walk rate - three for the sea brute, twelve for the marsh and river
// sorts
inline int t24DgWalk(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 3;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// the fly rate - forty-eight for the wingless Celestial, the sentinel for the
// Lung Wang and Yu Lung
inline int t24DgFly(int b)
    {
        switch (b) {
        case 0:
            return 48;
        case 1:
            return 12;
        case 2:
            return 24;
        case 3:
            return 12;
        case 4:
            return -99;
        case 5:
            return -99;
        default:
            return -99;
        }
    }

// the swim rate - six for the Tien and Li, eighteen for the Carp
inline int t24DgSwim(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 9;
        case 2:
            return 6;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 18;
        default:
            return -99;
        }
    }

// ---- the lycanthropy infection variant (print 10-11) ----

// any warm-blooded being seriously injured - fifty percent or more of the
// damage they can take - stands a good chance of infection the lycanthropy
// infection variant (print 10-11)
inline int t24InfectionThresholdPct()
    { return 50; }

// the type A onset - the change occurs within one to eight days of being
// bitten the lycanthropy infection variant (print 10-11)
inline int t24OnsetAHi()
    { return 8; }

// the type B onset - within three to thirty-six turns the lycanthropy
// infection variant (print 10-11)
inline int t24OnsetBHi()
    { return 36; }

// the type C onset - within two to twenty-four turns of being infected the
// lycanthropy infection variant (print 10-11)
inline int t24OnsetCHi()
    { return 24; }

// the type D onset - beginning one to twelve turns after infection the
// lycanthropy infection variant (print 10-11)
inline int t24OnsetDHi()
    { return 12; }

// the type E and F onset - beginning two to sixteen turns after infection the
// lycanthropy infection variant (print 10-11)
inline int t24OnsetEfHi()
    { return 16; }

// the type G onset - beginning one to ten turns after being bitten the
// lycanthropy infection variant (print 10-11)
inline int t24OnsetGHi()
    { return 10; }

// the type C cure - a Cure Disease or Remove Curse from a cleric of at least
// seventh level the lycanthropy infection variant (print 10-11)
inline int t24CureClericCLevel()
    { return 7; }

// the type G cure - a cleric of at least eighth level the lycanthropy
// infection variant (print 10-11)
inline int t24CureClericGLevel()
    { return 8; }

// the full-moon change chance for type G - ninety-five percent the
// lycanthropy infection variant (print 10-11)
inline int t24FullMoonPct()
    { return 95; }

// the base forty percent chance under great stress, added to or subtracted
// from according to the type of stress the lycanthropy infection variant
// (print 10-11)
inline int t24StressBasePct()
    { return 40; }

// the changed form holds for two to twelve turns or until the stress or the
// full moon is gone, whichever comes last the lycanthropy infection variant
// (print 10-11)
inline int t24FormDurationHi()
    { return 12; }

// the G-form split - about one half of the player abilities and one half of
// the real lycanthrope powers the lycanthropy infection variant (print 10-11)
inline int t24HalvedPowersDivisor()
    { return 2; }

// the halved rat summon - a Were-Rat of the G type could summon five to fifty
// rats, not the usual ten to one hundred the lycanthropy infection variant
// (print 10-11)
inline int t24TypeGRatSummonHi()
    { return 50; }

// a ten percent chance the player keeps his shield in lycanthrope form - only
// were-rats, were-bears and type G lycanthropes can use one the lycanthropy
// infection variant (print 10-11)
inline int t24ShieldKeepPct()
    { return 10; }

// the player creature armor class one lower than usual - a were-wolf with a
// shield would be armor class four the lycanthropy infection variant (print
// 10-11)
inline int t24WerewolfShieldAc()
    { return 4; }

// a base sixty-five percent chance the lycanthrope drops all supplies and
// possessions at the first change the lycanthropy infection variant (print
// 10-11)
inline int t24DropSuppliesPct()
    { return 65; }

// the type G drop chance - forty percent, and zero for the physical types C
// and F the lycanthropy infection variant (print 10-11)
inline int t24DropTypeGPct()
    { return 40; }

// past maximum level they gain only one third of the hit point adds per
// level, rounding off to the next highest whole number the lycanthropy
// infection variant (print 10-11)
inline int t24MaxLevelDivisor()
    { return 3; }

// the worked save - a player needing twelve against poison needs only nine in
// were-wolf form, the minus three wolf row the lycanthropy infection variant
// (print 10-11)
inline int t24PoisonSaveExample()
    { return 9; }

// the seven infection bands A through G of the dice-roll table the
// lycanthropy infection variant (print 10-11)
inline int t24LycanBandCount()
    { return 7; }

// the nine rows of the alignment comparison matrix the lycanthropy infection
// variant (print 10-11)
inline int t24LycanAlignCount()
    { return 9; }

// the five rows of the attribute modifier table - the printed duplicate Boar
// row reads the bear line the lycanthropy infection variant (print 10-11)
inline int t24LycanAttrCount()
    { return 5; }

// several varieties of lycanthropy not covered before - the percentage dice
// rolled when the person is first bitten the lycanthropy infection variant
// (print 10-11)
inline bool t24SevenInfectionTypes()
    { return true; }

// the type A infected turns into the creature which hit him, mentally and
// physically, even his alignment changing the lycanthropy infection variant
// (print 10-11)
inline bool t24TypeANewCharacter()
    { return true; }

// the type B stays in human form with the lycanthrope mentality and lower
// intelligence - a type of insanity for curses the lycanthropy infection
// variant (print 10-11)
inline bool t24TypeBMentalOnly()
    { return true; }

// the type C keeps his own mentality and gains the physical characteristics
// of the lycanthrope which bit him the lycanthropy infection variant (print
// 10-11)
inline bool t24TypeCPhysicalOnly()
    { return true; }

// the types D E and F change only under a full moon or under great stress,
// like the type G the lycanthropy infection variant (print 10-11)
inline bool t24MoonStressTypes()
    { return true; }

// the G change - a sort of part man part monster being, the general idea of
// the Incredible Hulk the lycanthropy infection variant (print 10-11)
inline bool t24PartManPartMonster()
    { return true; }

// the resulting alignment is discovered the first change and always remains
// the same unless the player changes his own the lycanthropy infection
// variant (print 10-11)
inline bool t24AlignmentFixedFirst()
    { return true; }

// if the creature is lawful it will be lawful good - if chaotic, chaotic evil
// the lycanthropy infection variant (print 10-11)
inline bool t24LawfulGoodChaoticEvil()
    { return true; }

// a separate character sheet attached to the regular one for the lycanthrope
// form the lycanthropy infection variant (print 10-11)
inline bool t24SeparateSheet()
    { return true; }

// the G type is actually an advantage when the alignments match - the
// creature is stronger and has more hitpoints the lycanthropy infection
// variant (print 10-11)
inline bool t24GFormAdvantage()
    { return true; }

// the were-bear is the only lycanthrope which is ever lawful good - the
// servants and companions of good Wizards and patriarchs the lycanthropy
// infection variant (print 10-11)
inline bool t24WerebearLawfulGood()
    { return true; }

// an odd sensation just before turning gives time to take off armor to keep
// it from getting wrecked the lycanthropy infection variant (print 10-11)
inline bool t24ArmorSense()
    { return true; }

// the level and experience of the player creature stay those of the player,
// going up in the same steps the lycanthropy infection variant (print 10-11)
inline bool t24LevelStepsUnchanged()
    { return true; }

// the creature automatically speaks its own language and any others the
// altered intelligence permits the lycanthropy infection variant (print
// 10-11)
inline bool t24LanguagesAutomatic()
    { return true; }

// the Dungeonmaster can change these charts to fit his game as long as
// balance is maintained the lycanthropy infection variant (print 10-11)
inline bool t24DungeonmasterFinalWord()
    { return true; }

// the band floor - one through the type A, twenty-six at the type D
inline int t24LyLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 21;
        case 3:
            return 26;
        case 4:
            return 51;
        case 5:
            return 61;
        case 6:
            return 71;
        default:
            return -99;
        }
    }

// the band ceiling - fifty at D, sixty at E, seventy at F, one hundred at G
inline int t24LyHi(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 20;
        case 2:
            return 25;
        case 3:
            return 50;
        case 4:
            return 60;
        case 5:
            return 70;
        case 6:
            return 100;
        default:
            return -99;
        }
    }

// the lawful column - one hundred at the matched lawful row, forty-five where
// a neutral creature bites a lawful player
inline int t24AlLawful(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 60;
        case 2:
            return 20;
        case 3:
            return 45;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the neutral column - one hundred at the matched neutral row, sixty at both
// lawful-chaotic crosses
inline int t24AlNeutral(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 40;
        case 2:
            return 60;
        case 3:
            return 55;
        case 4:
            return 100;
        case 5:
            return 55;
        case 6:
            return 60;
        case 7:
            return 40;
        case 8:
            return 0;
        default:
            return -99;
        }
    }

// the chaotic column - one hundred at the matched chaotic row, forty-five
// where a neutral creature bites a chaotic player
inline int t24AlChaotic(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 45;
        case 6:
            return 20;
        case 7:
            return 60;
        case 8:
            return 100;
        default:
            return -99;
        }
    }

// the intelligence column - minus four for the boar, the rat and bear rows
// reading zero
inline int t24AtInt(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -4;
        case 3:
            return -3;
        case 4:
            return -1;
        default:
            return -99;
        }
    }

// the strength column - plus six at the printed duplicate Boar row, plus five
// for the tiger
inline int t24AtStr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        default:
            return -99;
        }
    }

// the constitution column - plus five for the wolf, the bear justification
// printed at the note
inline int t24AtCon(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 4;
        default:
            return -99;
        }
    }

// the wisdom column - minus four for the boar, minus three for the tiger
inline int t24AtWis(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -2;
        case 2:
            return -4;
        case 3:
            return -3;
        case 4:
            return -1;
        default:
            return -99;
        }
    }

// the charisma column - minus five for the boar, minus three for the rat
inline int t24AtCha(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -3;
        case 2:
            return -5;
        case 3:
            return -4;
        case 4:
            return -2;
        default:
            return -99;
        }
    }

// the dexterity column - plus four for the rat, plus three for the wolf
inline int t24AtDex(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
