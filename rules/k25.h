// =========================================================================================
// Adnd1 - rules/k25.h
// The Dragon issue-25 opener part three - the commentary set
// census 882 -> 883.
//
// The part-three round of the issue-25 four-round shape - three of the eight
// Curtiss-called chains as the commentary set: the William B. Fawcett War of
// Flowers commentary (print 35-37) - the tribute empire, the three-delegation
// declaration ritual with the twenty day waits, the command ladder from the
// Tlacatechth to the twenty man platoon, the house of darts and the knights
// orders - the Bob Bledsaw To Select a Mythos guide (print 43) on the
// campaign mythos - the nexus gates, the clean slate and the system fits -
// and the Michael H. Kluwer Arms and Armor of the Conquistadores commentary
// (print 44-45) - the Cortez and Pizarro expedition numbers, the half armor
// and the morion, the pike, arquebus and crossbow notes. All pinned from The
// Dragon Vol. III No. 11 (May 1979) print 35-37 and 43-45 at
// extract/dragon/025, PRINT FOLIO = PDF PAGE this issue, the single-voice
// transcript of the Curtiss-provided scan - the contents printing Mike H.
// Kleuvor for Michael H. Kluwer, the part-three heading joined from the scan.
// The Flower Wars and Conquistadores chains stayed in at the R960
// adjudication per the standing eight-chain call; the flip rides R961. The
// two inherited watches - the Sullin levels 7-9 and the brawling sequel -
// print nowhere in issue 25 and ride to TD 26.
//
namespace rules {

// ---- the War of Flowers commentary (print 35-37) ----

// the ritual wait - a declaration delegation camps one Aztec month of twenty
// days for the reply the War of Flowers commentary (print 35-37)
inline int s25AztecMonthDays()
    { return 20; }

// the declaration ritual - three State visits before the armies meet the War
// of Flowers commentary (print 35-37)
inline int s25WarDelegations()
    { return 3; }

// the clan seats - four phratries to the city, a Tlacola atop each the War of
// Flowers commentary (print 35-37)
inline int s25PhratriesCount()
    { return 4; }

// the company - two hundred to four hundred men, the largest unit under
// tactical control once the battle began the War of Flowers commentary (print
// 35-37)
inline int s25CompanyMenLo()
    { return 200; }

// the company high end - the four hundred man ceiling the War of Flowers
// commentary (print 35-37)
inline int s25CompanyMenHi()
    { return 400; }

// the platoon - twenty men, the flag glyph the symbol for twenty the War of
// Flowers commentary (print 35-37)
inline int s25PlatoonMen()
    { return 20; }

// the main weapons - the obsidian club, the javelin with the atl-atl, the
// bow, the heavy lance the War of Flowers commentary (print 35-37)
inline int s25MainWeapons()
    { return 4; }

// the house of darts - an arsenal to each city quarter, the weapons for five
// clans, one phratry the War of Flowers commentary (print 35-37)
inline int s25ArsenalClans()
    { return 5; }

// the knights orders - the Eagle, the Ocelot and the less common Arrow the
// War of Flowers commentary (print 35-37)
inline int s25KnightOrders()
    { return 3; }

// the conquest result - tribute and economic sanctions, never absorption the
// War of Flowers commentary (print 35-37)
inline bool s25TributeNotAbsorption()
    { return true; }

// the tribute gap - no hostage system ever devised to guarantee the payment
// the War of Flowers commentary (print 35-37)
inline bool s25NoTributeGuarantee()
    { return true; }

// the levy - all males soldiers, the weapons part of the schooling the War of
// Flowers commentary (print 35-37)
inline bool s25AllMalesSoldiers()
    { return true; }

// the drill absence - no drills, the swarm tactics of biblical times the War
// of Flowers commentary (print 35-37)
inline bool s25NoUnitDrills()
    { return true; }

// the season ban - no campaign in the planting and harvest seasons, the army
// the work force the War of Flowers commentary (print 35-37)
inline bool s25CampaignSeasonBan()
    { return true; }

// the siege gap - no evidence of siege weapons developed or used to any
// extent the War of Flowers commentary (print 35-37)
inline bool s25NoSiegeWeapons()
    { return true; }

// the victory measure - the captured count, not the killed the War of Flowers
// commentary (print 35-37)
inline bool s25CaptivesOverKills()
    { return true; }

// the apprenticeship - a new warrior attached to a veteran, the squire
// parallel the War of Flowers commentary (print 35-37)
inline bool s25NewWarriorApprenticed()
    { return true; }

// the warrior heaven - slain in battle or sacrificed, the greatest honor a
// defeated warrior could receive the War of Flowers commentary (print 35-37)
inline bool s25WarriorsHeavenGuarantee()
    { return true; }

// the cotton adoption - the conquistadores took the quilted armor, effective
// and cooler than steel the War of Flowers commentary (print 35-37)
inline bool s25CottonArmorAdopted()
    { return true; }

// ---- the To Select a Mythos guide (print 43) ----

// the drawn mythologies - Greek, Celtic and Eastern, molded to the living
// legends the To Select a Mythos guide (print 43)
inline int s25MythosDraws()
    { return 3; }

// the common trait - every good campaign a well developed mythos the To
// Select a Mythos guide (print 43)
inline bool s25WellDevelopedMythos()
    { return true; }

// the nexus points - only the persistent search finds a gate, the access
// limited and well defended the To Select a Mythos guide (print 43)
inline bool s25NexusGatesLimited()
    { return true; }

// the design preference - a clean slate to begin extrapolating upon the To
// Select a Mythos guide (print 43)
inline bool s25CleanSlatePreference()
    { return true; }

// the restraints cast off - a mythos designed without reality limits the To
// Select a Mythos guide (print 43)
inline bool s25NoRealityRestraints()
    { return true; }

// the system fit - a Mayan mythos or any non-gunpowder mythos under the D&D
// rules the To Select a Mythos guide (print 43)
inline bool s25DndNonGunpowderFit()
    { return true; }

// the exclusions - the living world faiths never used in the campaign the To
// Select a Mythos guide (print 43)
inline bool s25RealFaithsExcluded()
    { return true; }

// the gods call - nothing sacrilegious about introducing gods, even ones the
// players defeat the To Select a Mythos guide (print 43)
inline bool s25GodsInCampaignOk()
    { return true; }

// the guideline tables - inspiration for the judge, never religion the To
// Select a Mythos guide (print 43)
inline bool s25TablesNotDogma()
    { return true; }

// ---- the Conquistadores commentary (print 44-45) ----

// the Cortez sail - fifteen eighteen out of Hispaniola the Conquistadores
// commentary (print 44-45)
inline int s25CortezSailYear()
    { return 1518; }

// the Cortez sail - six hundred men for the Aztec Empire the Conquistadores
// commentary (print 44-45)
inline int s25CortezSailMen()
    { return 600; }

// the Cortez sail - seventeen horses the Conquistadores commentary (print
// 44-45)
inline int s25CortezSailHorses()
    { return 17; }

// the Cortez sail - ten cannon the Conquistadores commentary (print 44-45)
inline int s25CortezSailCannon()
    { return 10; }

// the Cozumel review - five hundred eight soldiers on the rolls the
// Conquistadores commentary (print 44-45)
inline int s25CozumelSoldiers()
    { return 508; }

// the Cozumel review - thirty two crossbowmen the Conquistadores commentary
// (print 44-45)
inline int s25CozumelCrossbowmen()
    { return 32; }

// the Cozumel review - thirteen arquebusiers the Conquistadores commentary
// (print 44-45)
inline int s25CozumelArquebusiers()
    { return 13; }

// the Cozumel review - one hundred sailors beside the soldiers the
// Conquistadores commentary (print 44-45)
inline int s25CozumelSailors()
    { return 100; }

// the later count - forty cavalry under six hundred total the Conquistadores
// commentary (print 44-45)
inline int s25CortezLaterCavalry()
    { return 40; }

// the later count - eighty crossbowmen and arquebusiers the Conquistadores
// commentary (print 44-45)
inline int s25CortezLaterGunners()
    { return 80; }

// the Pizarro landing - fifteen thirty one at Atahualpa the Conquistadores
// commentary (print 44-45)
inline int s25PizarroLandYear()
    { return 1531; }

// the Pizarro landing - one hundred eighty men the Conquistadores commentary
// (print 44-45)
inline int s25PizarroLandingMen()
    { return 180; }

// the Pizarro landing - twenty seven horses the Conquistadores commentary
// (print 44-45)
inline int s25PizarroLandingHorses()
    { return 27; }

// the Pizarro landing - two cannon the Conquistadores commentary (print
// 44-45)
inline int s25PizarroLandingCannon()
    { return 2; }

// the march against the Inca - sixty two cavalry the Conquistadores
// commentary (print 44-45)
inline int s25PizarroMarchCavalry()
    { return 62; }

// the march against the Inca - one hundred two infantry the Conquistadores
// commentary (print 44-45)
inline int s25PizarroMarchInfantry()
    { return 102; }

// the ceiling - never more than one thousand men afield the Conquistadores
// commentary (print 44-45)
inline int s25ExpeditionMenMax()
    { return 1000; }

// the victory span - three hundred years before the taste of freedom again
// the Conquistadores commentary (print 44-45)
inline int s25EmpireYears()
    { return 300; }

// the pike - twelve to eighteen feet, the spearhead short with long side
// straps the Conquistadores commentary (print 44-45)
inline int s25PikeLengthLoFt()
    { return 12; }

// the pike high end - the eighteen foot reach the Conquistadores commentary
// (print 44-45)
inline int s25PikeLengthHiFt()
    { return 18; }

// the halberd custom - one of every ten or twenty pikemen so armed the
// Conquistadores commentary (print 44-45)
inline int s25HalberdRatioLo()
    { return 10; }

// the halberd custom high end - one of every twenty the Conquistadores
// commentary (print 44-45)
inline int s25HalberdRatioHi()
    { return 20; }

// the matchlock - three pounds of older weapon the Conquistadores commentary
// (print 44-45)
inline int s25ArquebusWeightLbs()
    { return 3; }

// the matchlock barrel - three feet or more the Conquistadores commentary
// (print 44-45)
inline int s25ArquebusBarrelFt()
    { return 3; }

// the matchlock rate - one shot a minute when everything favors the
// Conquistadores commentary (print 44-45)
inline int s25ArquebusShotsPerMin()
    { return 1; }

// the accurate range - one hundred to two hundred yards the Conquistadores
// commentary (print 44-45)
inline int s25ArquebusRangeLoYds()
    { return 100; }

// the accurate range high end - two hundred yards the Conquistadores
// commentary (print 44-45)
inline int s25ArquebusRangeHiYds()
    { return 200; }

// the crossbow - accurate to one hundred twenty yards, the higher rate and
// the lesser misfire the Conquistadores commentary (print 44-45)
inline int s25CrossbowRangeYds()
    { return 120; }

// the pike share - half to three quarters of the battle the Conquistadores
// commentary (print 44-45)
inline int s25PikemenPctLo()
    { return 50; }

// the pike share high end - three quarters of the battle the Conquistadores
// commentary (print 44-45)
inline int s25PikemenPctHi()
    { return 75; }

// the morion comb - up to four inches, the cut spread and the skull spared
// the Conquistadores commentary (print 44-45)
inline int s25MorionCombInches()
    { return 4; }

// the buckler - a small round iron shield, about two feet across the
// Conquistadores commentary (print 44-45)
inline int s25BucklerDiaFt()
    { return 2; }

// the armor shift - full suits to half suits in twenty five years, the
// cavalry and pikemen the wearers the Conquistadores commentary (print 44-45)
inline bool s25HalfArmorAge()
    { return true; }

// the proof mark - the armorer bullet dent fired to test the breastplate the
// Conquistadores commentary (print 44-45)
inline bool s25BreastplateProofed()
    { return true; }

// the matchlock rest - the forked mount, the smouldering fiber clipped to the
// cock the Conquistadores commentary (print 44-45)
inline bool s25ArquebusMatchRest()
    { return true; }

// the arquebus flaw - wet weather and windy days the havoc the Conquistadores
// commentary (print 44-45)
inline bool s25ArquebusWeatherFolly()
    { return true; }

// the crossbow bow - steel, drawn by cord and pulley or rack and pinion the
// Conquistadores commentary (print 44-45)
inline bool s25CrossbowSteelLath()
    { return true; }

// the quarrel at close range - the armor penetrated the Conquistadores
// commentary (print 44-45)
inline bool s25QuarrelPiercesArmor()
    { return true; }

// the sword centers - Toledo and Valencia, the curved guards catching the
// blade the Conquistadores commentary (print 44-45)
inline bool s25ToledoSwordmakers()
    { return true; }

// the battle order - the arquebusiers at the corners, the fired rank cycling
// to the rear to reload the Conquistadores commentary (print 44-45)
inline bool s25BattleCorners()
    { return true; }

// the pikemen stand - they hold the ground, shoulder to shoulder when the
// enemy ranks break the Conquistadores commentary (print 44-45)
inline bool s25PikemenHoldGround()
    { return true; }

// the Cortez open - the cavalry charge first when the numbers allow the
// Conquistadores commentary (print 44-45)
inline bool s25CavalryChargeOpens()
    { return true; }

}   // namespace rules
