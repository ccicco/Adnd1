// =========================================================================================
// Adnd1 - rules/k23.h
// The Dragon issue-23 opener part three - the six-chain commentary set
// census 874 -> 875.
//
// The part-three round of the issue-23 four-round shape - six of the ten
// Curtiss-called chains pinned as the commentary set: the gaming-hobby
// trade-show report (print 6), the armor-weights polemic (print 14), the
// permanent-damage charts (print 19-20), the dungeon-as-prison formula (print
// 21), the Origins scheduling critique (print 4 and 21) and the Niall
// sword-and-sorcery tale (print 8-9 and 22-30, Gardner Fox and the witchwoman
// Sosaria Thota). All pinned from The Dragon Vol. III No. 9 (March 1979) at
// extract/dragon/023, PRINT FOLIO = PDF PAGE this issue, the transcript of
// the Curtiss-provided scan. The two inherited watches - the Sullin levels
// 7-9 and the brawling sequel - print nowhere in issue 23 and ride to TD 24.
//
namespace rules {

// ---- the gaming-hobby trade-show report (print 6) ----

// the forty-second Annual Hobby Industry Convention and Trade Show the
// gaming-hobby trade-show report (print 6)
inline int k23HobbyShowNumber()
    { return 42; }

// the near five hundred exhibits the St. Louis convention center housed the
// gaming-hobby trade-show report (print 6)
inline int k23ShowExhibits()
    { return 500; }

// the four days of the trade show the gaming-hobby trade-show report (print
// 6)
inline int k23ShowDays()
    { return 4; }

// the third time running TSR attended the same show the gaming-hobby
// trade-show report (print 6)
inline int k23TsrShowCount()
    { return 3; }

// the sixteen gaming-hobby exhibitors from the Armory through TSR Hobbies the
// gaming-hobby trade-show report (print 6)
inline int k23ExhibitorRoster()
    { return 16; }

// the ten years since Avalon Hill was the only exhibitor showing games the
// gaming-hobby trade-show report (print 6)
inline int k23DecadeYears()
    { return 10; }

// the California site year, Anaheim expected to top St. Louis the
// gaming-hobby trade-show report (print 6)
inline int k23AnaheimYear()
    { return 1980; }

// ten years ago The Avalon Hill Company was the only exhibitor showing games
// the gaming-hobby trade-show report (print 6)
inline bool k23AvalonHillOnlyThen()
    { return true; }

// gaming is now recognized as a full-fledged member of the hobby industry the
// gaming-hobby trade-show report (print 6)
inline bool k23GamingFullFledged()
    { return true; }

// St. Louis proved an excellent spot for a show despite snow and cold the
// gaming-hobby trade-show report (print 6)
inline bool k23StLouisSnowCold()
    { return true; }

// the Shanghai Inn recommended for superb Chinese food at reasonable prices
// the gaming-hobby trade-show report (print 6)
inline bool k23ShanghaiInn()
    { return true; }

// Anthony s recommended for elegance to those who do not mind blowing the
// family fortune the gaming-hobby trade-show report (print 6)
inline bool k23Anthonys()
    { return true; }

// the print catch - the contents list Good News For The Gaming Hobby at
// eighteen while the article prints at six as GOOD NEWS FOR GAMING the
// gaming-hobby trade-show report (print 6)
inline bool k23GoodNewsBylineCatch()
    { return true; }

// ---- the armor-weights polemic (print 14) ----

// the floor of the extra pounds D and D adds to plate armor the armor-weights
// polemic (print 14)
inline int k23DndPlatePoundsMin()
    { return 15; }

// the ceiling of the extra pounds D and D adds to plate armor the
// armor-weights polemic (print 14)
inline int k23DndPlatePoundsMax()
    { return 20; }

// the denominator of the Chivalry and Sorcery claim that full plate weighs
// two thirds of the wearer body weight the armor-weights polemic (print 14)
inline int k23CsPlateDivisor()
    { return 3; }

// the Nickel full-suit floor of about fifty pounds the armor-weights polemic
// (print 14)
inline int k23ArmorWeightMin()
    { return 50; }

// the Nickel full-suit ceiling of sixty pounds, no more than a modern soldier
// battle pack the armor-weights polemic (print 14)
inline int k23ArmorWeightMax()
    { return 60; }

// the cuirassier armor of 1620-1630 at sixty-nine pounds the armor-weights
// polemic (print 14)
inline int k23CuirassPounds()
    { return 69; }

// the cuirassier armor ounces of five, the Churburg 130 piece the
// armor-weights polemic (print 14)
inline int k23CuirassOunces()
    { return 5; }

// the plate field battle armor of circa 1525 at forty-one pounds, the Wallace
// 763 piece the armor-weights polemic (print 14)
inline int k23BattleArmorPounds()
    { return 41; }

// the battle armor ounces of thirteen and a half, pinned in tenths the
// armor-weights polemic (print 14)
inline int k23BattleArmorTenths()
    { return 135; }

// the Milanese plate of circa 1450 at sixty point four pounds, pinned in
// tenths, the Churburg 20 piece the armor-weights polemic (print 14)
inline int k23MilaneseTenths()
    { return 604; }

// the German mid-thigh mail shirt at twenty pounds the armor-weights polemic
// (print 14)
inline int k23MailPounds()
    { return 20; }

// the mail shirt ounces of eleven, the Churburg 2 piece the armor-weights
// polemic (print 14)
inline int k23MailOunces()
    { return 11; }

// the Italian barbut helmet of circa 1440 at five pounds the armor-weights
// polemic (print 14)
inline int k23BarbutPounds()
    { return 5; }

// the barbut ounces of fourteen, the W.C.L. 39 piece the armor-weights
// polemic (print 14)
inline int k23BarbutOunces()
    { return 14; }

// the one-handed sword floor of two pounds, the Oakeshott average the
// armor-weights polemic (print 14)
inline int k23SwordPoundsMin()
    { return 2; }

// the one-handed sword ceiling of three pounds, the Oakeshott average the
// armor-weights polemic (print 14)
inline int k23SwordPoundsMax()
    { return 3; }

// the hand-and-a-half or bastard sword floor of three and a half pounds,
// pinned in tenths the armor-weights polemic (print 14)
inline int k23BastardTenthsMin()
    { return 35; }

// the bastard sword ceiling of five and a half pounds, pinned in tenths the
// armor-weights polemic (print 14)
inline int k23BastardTenthsMax()
    { return 55; }

// the Chivalry and Sorcery seven-pound sword, a far cry from the real weights
// the armor-weights polemic (print 14)
inline int k23CsSwordPounds()
    { return 7; }

// the SPI statement floor of five pounds, the S and T 68 citation the
// armor-weights polemic (print 14)
inline int k23SpiPoundsMin()
    { return 5; }

// the SPI statement ceiling of ten pounds the armor-weights polemic (print
// 14)
inline int k23SpiPoundsMax()
    { return 10; }

// the Oakeshott page twelve of the average-weight statement the armor-weights
// polemic (print 14)
inline int k23SwordBookPage()
    { return 12; }

// the Helmut Nickel Warriors and Worthies citation at page fifty-seven the
// armor-weights polemic (print 14)
inline int k23NickelPage()
    { return 57; }

// the Claude Blair European Armor citation at page one hundred ninety-one the
// armor-weights polemic (print 14)
inline int k23BlairPage()
    { return 191; }

// the three-foot chasm a plate-armored character was once told he could not
// leap across the armor-weights polemic (print 14)
inline int k23ChasmFeet()
    { return 3; }

// the Helmut Nickel quote - the Curator of Arms and Armor for the
// Metropolitan Museum of Art the armor-weights polemic (print 14)
inline bool k23NickelQuote()
    { return true; }

// the Claude Blair quote - the Deputy Keeper at the Victoria and Albert
// Museum the armor-weights polemic (print 14)
inline bool k23BlairQuote()
    { return true; }

// the perfect knight expected to vault into the saddle in full armor without
// using the stirrups the armor-weights polemic (print 14)
inline bool k23VaultWithoutStirrups()
    { return true; }

// the Blair finding that an untrained man in a properly-fitted harness can
// mount, lie down and rise, bend, stoop and move freely the armor-weights
// polemic (print 14)
inline bool k23HarnessFreedom()
    { return true; }

// the print catch - the cuirassier provenance prints Augsberg for Augsburg
// the armor-weights polemic (print 14)
inline bool k23AugsbergCatch()
    { return true; }

// the print catch - the contents prints It Weighs WHAT! exclamation-question
// while the byline prints WHAT three-question the armor-weights polemic
// (print 14)
inline bool k23TitlePunctCatch()
    { return true; }

// the print catch - the Oakeshott publisher prints Fredrick A. Praeger for
// Frederick the armor-weights polemic (print 14)
inline bool k23FredrickCatch()
    { return true; }

// the print catch - the mid-sentence capital, I would like at this time to
// Quote Claude Blair the armor-weights polemic (print 14)
inline bool k23QuoteCapitalCatch()
    { return true; }

// ---- the permanent-damage charts (print 19-20) ----

// the percentile one-to-fifty band of no permanent damage after healing the
// permanent-damage charts (print 19-20)
inline int k23PermHealMax()
    { return 50; }

// the magical-aid band floor of fifty-one the permanent-damage charts (print
// 19-20)
inline int k23MagicalAidLo()
    { return 51; }

// the magical-aid band ceiling of seventy the permanent-damage charts (print
// 19-20)
inline int k23MagicalAidHi()
    { return 70; }

// the maimed band floor of seventy-one the permanent-damage charts (print
// 19-20)
inline int k23MaimedLo()
    { return 71; }

// the fifth level or better clerical healing that undoes maiming, or a wish
// the permanent-damage charts (print 19-20)
inline int k23MaimedHealLevel()
    { return 5; }

// the trunk poison-save penalty of minus two, multiplying at every occurrence
// the permanent-damage charts (print 19-20)
inline int k23PoisonSavePenalty()
    { return 2; }

// the trunk speed loss of ten yards per melee turn per occasion the
// permanent-damage charts (print 19-20)
inline int k23SpeedLossYards()
    { return 10; }

// the legs strength loss of three hundred gold pieces of carrying ability per
// occasion the permanent-damage charts (print 19-20)
inline int k23CarryLossGold()
    { return 300; }

// the reduced-state speed drop of twenty yards a melee turn the
// permanent-damage charts (print 19-20)
inline int k23FatigueSpeedYards()
    { return 20; }

// the reduced-state arms strength drop of two points the permanent-damage
// charts (print 19-20)
inline int k23ArmsStrengthDrop()
    { return 2; }

// the hands dexterity loss that cuts thief extra abilities by ten percent the
// permanent-damage charts (print 19-20)
inline int k23ThiefAbilityLoss()
    { return 10; }

// the reduced-state arms drop of twenty percent in all thieving abilities the
// permanent-damage charts (print 19-20)
inline int k23ThiefDropTwenty()
    { return 20; }

// the reduced-state legs carrying-ability drop of six hundred gold pieces the
// permanent-damage charts (print 19-20)
inline int k23CarryLossDouble()
    { return 600; }

// the reduced-state legs extra-ability drop of twenty percent the
// permanent-damage charts (print 19-20)
inline int k23LegsAbilityDrop()
    { return 20; }

// the hearing-loss surprise roll of one to three, a point added per new
// occasion the permanent-damage charts (print 19-20)
inline int k23SurpriseDieMax()
    { return 3; }

// the sight-loss blinding of one to four melee turns from bright light or
// full daylight the permanent-damage charts (print 19-20)
inline int k23BlindTurnsMax()
    { return 4; }

// the hands inability to fight on a roll of one to three with a six sided die
// the permanent-damage charts (print 19-20)
inline int k23WrongHandRoll()
    { return 3; }

// the reduced-state feet drop of fifty percent in the ability to move and
// carry the permanent-damage charts (print 19-20)
inline int k23FeetMoveDrop()
    { return 50; }

// the fatigue floor of two hit points, the reduced-to state the
// permanent-damage charts (print 19-20)
inline int k23FatigueHighMin()
    { return 2; }

// the fatigue ceiling of ten hit points, the reduced-from state the
// permanent-damage charts (print 19-20)
inline int k23FatigueLowMax()
    { return 10; }

// the over-twenty-hit-points-to-start-with rule of thumb the permanent-damage
// charts (print 19-20)
inline int k23HitPointFloor()
    { return 20; }

// the tenth fighter who could have ten hit points, the good-sense example the
// permanent-damage charts (print 19-20)
inline int k23TenthFighterHp()
    { return 10; }

// the weapons subtable sword-type floor of sixty-one the permanent-damage
// charts (print 19-20)
inline int k23WeaponsSwordLo()
    { return 61; }

// the weapons subtable sword-type ceiling of ninety-five the permanent-damage
// charts (print 19-20)
inline int k23WeaponsSwordHi()
    { return 95; }

// the six damaged body areas - head, trunk, arms, legs, hands and feet the
// permanent-damage charts (print 19-20)
inline int k23DamageAreaCount()
    { return 6; }

// the six rows of the damaged-body-area percentile table the permanent-damage
// charts (print 19-20)
inline int k23DamageAreaRows()
    { return 6; }

// the wish or the fifth level clerical healing spell that undoes maiming the
// permanent-damage charts (print 19-20)
inline bool k23WishHeals()
    { return true; }

// the trunk poison-save situation that multiplies itself at every occurrence
// the permanent-damage charts (print 19-20)
inline bool k23PoisonSavesMultiply()
    { return true; }

// the dexterity impairments that cost thieves the ability to climb walls the
// permanent-damage charts (print 19-20)
inline bool k23ThievesLoseClimb()
    { return true; }

// the ed note - Herve Villechaize as Tattoo and Arnold Schwarzenegger the
// proposed Conan the permanent-damage charts (print 19-20)
inline bool k23HerveArnoldNote()
    { return true; }

// the ed note - the AD and D hit-point rationale of the ability to evade a
// fatal blow the permanent-damage charts (print 19-20)
inline bool k23AddRationaleNote()
    { return true; }

// the closing advice - bards losing the ability to sing, robots functioning
// illogically the permanent-damage charts (print 19-20)
inline bool k23BardsRobotsNote()
    { return true; }

// the print catch - the arm damage bands overlap at twenty-five,
// one-to-twenty-five and twenty-five-to-fifty the permanent-damage charts
// (print 19-20)
inline bool k23ArmsOverlapCatch()
    { return true; }

// the print catch - the reduced-state line prints reduced to from ten to two
// hit points left the permanent-damage charts (print 19-20)
inline bool k23ReducedToFromCatch()
    { return true; }

// the print catch - the body-area legs band seventy-five-to-seventy-nine is
// only five wide the permanent-damage charts (print 19-20)
inline bool k23LegsBandCatch()
    { return true; }

// the print catch - the asterisks on the hearing-loss and speed-decreased
// lines carry no footnote the permanent-damage charts (print 19-20)
inline bool k23UnfootedAsteriskCatch()
    { return true; }

// the percentile floor of the damaged body area
inline int k23AreaLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 15;
        case 2:
            return 50;
        case 3:
            return 75;
        case 4:
            return 80;
        case 5:
            return 95;
        default:
            return -99;
        }
    }

// the percentile ceiling of the damaged body area
inline int k23AreaHi(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 49;
        case 2:
            return 74;
        case 3:
            return 79;
        case 4:
            return 94;
        case 5:
            return 100;
        default:
            return -99;
        }
    }

// the body area ordinal - head, trunk, arms, legs, hands, feet
inline int k23AreaBody(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return -99;
        }
    }

// ---- the dungeon-as-prison formula (print 21) ----

// the Elrohir cubical cell two hundred feet below the lowest dungeon level
// the dungeon-as-prison formula (print 21)
inline int k23CellDepthFeet()
    { return 200; }

// the five layers of true lead sealing the cell the dungeon-as-prison formula
// (print 21)
inline int k23LeadLayers()
    { return 5; }

// the two-inch shaft through which food canisters drop and air is blown the
// dungeon-as-prison formula (print 21)
inline int k23ShaftInches()
    { return 2; }

// the around twenty tons of granite blocking the entry shaft, lead sheets
// interspersed the dungeon-as-prison formula (print 21)
inline int k23GraniteTons()
    { return 20; }

// the pile of rust that was the key, twenty feet from the cell door the
// dungeon-as-prison formula (print 21)
inline int k23KeyDistanceFeet()
    { return 20; }

// the steel doors that latch solidly when they close, catching unwary
// adventurers the dungeon-as-prison formula (print 21)
inline bool k23SteelDoorsLatch()
    { return true; }

// the chivalrous offer - the ruler dungeon champion in single combat, with no
// guarantee the deal is honored the dungeon-as-prison formula (print 21)
inline bool k23ChampionDuel()
    { return true; }

// the killed super-character who typically surrounds himself with patriarchs
// to bring him back to life the dungeon-as-prison formula (print 21)
inline bool k23PatriarchRevival()
    { return true; }

// the Dungeon-busters every campaign winds up with, the no-tears formula for
// removing them the dungeon-as-prison formula (print 21)
inline bool k23Dungeonbusters()
    { return true; }

// ---- the Origins scheduling critique (print 4+21) ----

// the scant three weeks between MichiCon and the combined PennCon Origins the
// Origins scheduling critique (print 4+21)
inline int k23MichiConWeeks()
    { return 3; }

// the full eight weeks between PennCon Origins and GenCon the Origins
// scheduling critique (print 4+21)
inline int k23GenConWeeks()
    { return 8; }

// GenCon beginning again for the twelfth year the Origins scheduling critique
// (print 4+21)
inline int k23GenConNumber()
    { return 12; }

// the princely-sum floor of two thousand dollars the Origins scheduling
// critique (print 4+21)
inline int k23OriginsProfitLow()
    { return 2000; }

// the princely-sum ceiling of three thousand dollars the Origins scheduling
// critique (print 4+21)
inline int k23OriginsProfitHigh()
    { return 3000; }

// the man-hours floor an Origins-size convention requires the Origins
// scheduling critique (print 4+21)
inline int k23ManHoursLow()
    { return 3000; }

// the man-hours ceiling an Origins-size convention requires the Origins
// scheduling critique (print 4+21)
inline int k23ManHoursHigh()
    { return 4000; }

// the one dollar per hour return, ridiculously low the Origins scheduling
// critique (print 4+21)
inline int k23DollarPerHour()
    { return 1; }

// the first two Origins shows put on by Interest Group Baltimore the Origins
// scheduling critique (print 4+21)
inline int k23FirstShows()
    { return 2; }

// the NFL Eagles training at Widener from July on, locking the campus the
// Origins scheduling critique (print 4+21)
inline int k23EaglesMonth()
    { return 7; }

// the PennCon group formerly known as PhilCon the Origins scheduling critique
// (print 4+21)
inline bool k23PennConPhilCon()
    { return true; }

// the only college that would even consider hosting Origins in the area was
// Widener, in Chester PA the Origins scheduling critique (print 4+21)
inline bool k23WidenerOnly()
    { return true; }

// the closing verdict - major conventions should be run and sponsored by the
// industry the Origins scheduling critique (print 4+21)
inline bool k23MajorConsIndustry()
    { return true; }

// Interest Group Baltimore used as the example with no slur meant, only to
// ridicule the contention the Origins scheduling critique (print 4+21)
inline bool k23IgbExample()
    { return true; }

// the print catch - the thanks note prints you now who you are for you know
// the Origins scheduling critique (print 4+21)
inline bool k23YouNowWhoCatch()
    { return true; }

// the print catch - the thanks note prints I know find myself for I now find
// the Origins scheduling critique (print 4+21)
inline bool k23IKnowFindCatch()
    { return true; }

// ---- the Niall sword-and-sorcery tale (print 8-9+22-30) ----

// the five thousand centuries Sosaria Thota slept, five hundred thousand
// years the Niall sword-and-sorcery tale (print 8-9+22-30)
inline int k23CenturiesThousand()
    { return 5; }

// the eleven hells of Emalkartha the Evil the Niall sword-and-sorcery tale
// (print 8-9+22-30)
inline int k23NiallHells()
    { return 11; }

// the three eyes of Alphanor, brilliant with evil the Niall sword-and-sorcery
// tale (print 8-9+22-30)
inline int k23BirdEyes()
    { return 3; }

// the four horses - one for each and two more to carry the witchwoman things
// the Niall sword-and-sorcery tale (print 8-9+22-30)
inline int k23HorsesSaddled()
    { return 4; }

// Lylthia standing a dozen feet away at the tale end the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline int k23LylthiaFeet()
    { return 12; }

// the sword Blood-drinker blazing with crimson light against the blue ball
// the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23BloodDrinker()
    { return true; }

// Emalkartha the Evil whose other self is Lylthia, whispered into Niall mind
// the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23EmalkarthaLylthia()
    { return true; }

// the vilaspa light that ate Lylthia at the window, white and joyous the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23VilaspaLight()
    { return true; }

// Messarib the whispering blue-ball messenger slain by the crimson blade the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Messarib()
    { return true; }

// Alphanor the winged bird-being of the outer darknesses the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Alphanor()
    { return true; }

// Xinthius the throne dreamer who refused, content with his dreamings the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Xinthius()
    { return true; }

// Abaddon the Black One, the Dark Destroyer, father of all demons the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Abaddon()
    { return true; }

// the lost garden land of Thilmagia, Sosaria Thota home, now dead sand the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Thilmagia()
    { return true; }

// the wild hordes of Pugarsk kept at distance by the Urgrik forts the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23Pugarsk()
    { return true; }

// the ring of shattered matter encircling the world, the post-cataclysm sky
// the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23RingOfShatteredMatter()
    { return true; }

// the fifth year of the Bear in the Cycle of the Twelve Sigils the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23BearCycle()
    { return true; }

// the footnote to THE DRAGON Vol. II No. 7, The Stolen Sacrifice the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23StolenSacrificeRef()
    { return true; }

// the footnote to THE DRAGON number 2 Vol. I, The Shadow of a Demon the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23ShadowOfDemonRef()
    { return true; }

// the Orravian dagger Niall hurls through the glass globe the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23OrravianDagger()
    { return true; }

// the red Kallarian wine in the commissary goblets the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23KallarianWine()
    { return true; }

// Niall running as swiftly as any Thort deer the Niall sword-and-sorcery tale
// (print 8-9+22-30)
inline bool k23ThortDeer()
    { return true; }

// the black hair dark as Corassian ebony the Niall sword-and-sorcery tale
// (print 8-9+22-30)
inline bool k23CorassianEbony()
    { return true; }

// the robber kingdoms along the shores of the Azlilic Sea the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23AzlilicSea()
    { return true; }

// the vast steppes between Urgrik and the lands of Noradden the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23NoraddenSteppes()
    { return true; }

// the print catch - the desert prints Bakakanian on page eight and
// Baklakanian on pages twenty-two through thirty the Niall sword-and-sorcery
// tale (print 8-9+22-30)
inline bool k23BakakanianCatch()
    { return true; }

// the print catch - the king prints Lurlyr Manakor through page nine and
// Luryr Manakor on pages twenty-two and thirty the Niall sword-and-sorcery
// tale (print 8-9+22-30)
inline bool k23LurlyrCatch()
    { return true; }

// the print catch - the eyes of Sosaria Thota print calm grey and then green
// within the same pages the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23SosariaEyesCatch()
    { return true; }

// the print catch - swordhill for swordhilt on the wallwalk the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23SwordhillCatch()
    { return true; }

// the print catch - Niall shrugging his brawney shoulders for brawny the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23BrawneyCatch()
    { return true; }

// the print catch - croached printed twice where crouched or squatted is
// meant the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23CroachedCatch()
    { return true; }

// the print catch - you had many serants for servants the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23SerantsCatch()
    { return true; }

// the print catch - Lythia for Lylthia in the dead-world scene the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23LythiaCatch()
    { return true; }

// the print catch - the witchwoman shock her head for shook the Niall
// sword-and-sorcery tale (print 8-9+22-30)
inline bool k23ShockCatch()
    { return true; }

// the print catch - the amanatlon device, the rods-and-stars machine name the
// Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23AmanatlonCatch()
    { return true; }

// the print catch - the dagger prints Orravian on page twenty-nine and
// Orra-vian on page thirty the Niall sword-and-sorcery tale (print 8-9+22-30)
inline bool k23OrravianHyphenCatch()
    { return true; }

}   // namespace rules
