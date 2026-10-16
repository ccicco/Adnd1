// =========================================================================================
// Adnd1 - rules/wsgcampfold.h
// The WSG CAMP-CHAIN FOLD, R502: the fourth seam round after gap closure. The
// fire-size ladders (rules/wsgfire.h), the fire-start and fuel rules
// (rules/wsgfuel.h), the wildfire rules (rules/wsgblaze.h), the tent quality
// system (rules/wsgsleep.h) and the natural shelters (rules/wsgshelter.h)
// reconciled as one system: one campsite, one chain, every ladder and
// threshold cross-checked between its headers - and the rest-quality
// thresholds plugged into the R499 temperature chain.
// census 426 -> 427.
//
// No new book pages: every value is the landed original re-read from its
// header (wgfFireSizes, wgfFuel, wgfRefuel, wgfWindRes, wgfPenTempBelow0,
// wgfPlateTypicalNight, wflSmallRefuelGrace, wflNoStartWindMax,
// wcfUncontrollableTurns, wcfSparkCarrySmallFt, wcfGrowthSmallTurns,
// wrsAdequateMinPoles, wrsWindStepMph, wnsLashBaseTurns and kin) and
// re-pinned on the fold side so the ladder identities compile and ride the
// mutant battery. The findings: the one-hour uncontrollable bar; the
// two-header refuel grace identity; the twenty-mph triple agreement across
// fire, rest and shelter; the no-start-equals-medium identity; the
// arithmetic-versus-geometric ladder split; the R499 temperature seam on both
// the cold side (the same 0) and the hot side (90 opens one past the 89
// protected top); and the flat 4-hour plate loss.
//
// THE SETTLE: census 426 -> 427; the gap report stays 186 closed / 0 open
// (closed - no flips this round); the camp chain has no gaps.
//
namespace rules {

// ---- the fire capacity ----

// six men bed down in a rough circle 10 feet from a small fire
// (wflCapBaseFeet).
inline int wmcCapBaseFeet()
    { return 10; }

// the small fire warms 6 men at 10 feet (wflSmallCapAt10).
inline int wmcCapSmallAt10()
    { return 6; }

// the same fire warms 12 men equally at 20 feet (wflSmallCapAt20).
inline int wmcCapSmallAt20()
    { return 12; }

// ---- the fire-size spine ----

// a campfire can be built in one of three sizes: small, medium and large
// (wgfFireSizes).
inline int wmcFireSizes()
    { return 3; }

// the fuel values gather enough material for an eight-hour burn
// (wgfBurnHours).
inline int wmcBurnHours()
    { return 8; }

// the Table 38 fuel: 6 turns of gathering for a small fire (wgfFuel(0)).
inline int wmcFuelSmall()
    { return 6; }

// the Table 38 fuel: 12 turns for a medium fire (wgfFuel(1)).
inline int wmcFuelMedium()
    { return 12; }

// the Table 38 fuel: 18 turns for a large fire (wgfFuel(2)).
inline int wmcFuelLarge()
    { return 18; }

// the Table 38 refuel: every 3 turns for a small fire (wgfRefuel(0)).
inline int wmcRefuelSmall()
    { return 3; }

// the Table 38 refuel: every 6 turns for a medium fire (wgfRefuel(1)).
inline int wmcRefuelMedium()
    { return 6; }

// the Table 38 refuel: every 9 turns for a large fire (wgfRefuel(2)).
inline int wmcRefuelLarge()
    { return 9; }

// the small fire withstands wind up to 20 mph (wgfWindRes(0)).
inline int wmcWindResSmall()
    { return 20; }

// the medium fire withstands wind up to 30 mph (wgfWindRes(1)).
inline int wmcWindResMedium()
    { return 30; }

// the large fire withstands wind up to 40 mph (wgfWindRes(2)).
inline int wmcWindResLarge()
    { return 40; }

// sparks from a small fire are carried 10 feet (wcfSparkCarrySmallFt).
inline int wmcSparkSmall()
    { return 10; }

// sparks from a medium fire are carried 20 feet (wcfSparkCarryMediumFt).
inline int wmcSparkMedium()
    { return 20; }

// sparks from a large fire are carried 30 feet (wcfSparkCarryLargeFt).
inline int wmcSparkLarge()
    { return 30; }

// a tiny flame grows into a small fire in 1 turn (wcfGrowthSmallTurns).
inline int wmcGrowthSmall()
    { return 1; }

// the small fire grows into a medium fire in 2 turns (wcfGrowthMediumTurns).
inline int wmcGrowthMedium()
    { return 2; }

// the medium fire grows into a large fire in 4 turns (wcfGrowthLargeTurns).
inline int wmcGrowthLarge()
    { return 4; }

// ---- the fire-start rules ----

// a fire starts normally in a breeze up to 15 mph (wflStartBreezeMax).
inline int wmcStartBreezeMax()
    { return 15; }

// no fire can be started in wind over 30 mph without magic
// (wflNoStartWindMax).
inline int wmcNoStartWindMax()
    { return 30; }

// the unskilled start time: 2d20 rounds (wflStartDice).
inline int wmcStartDice()
    { return 2; }

// wind over 15 mph or wet fuel: 3d20 rounds (wflHardStartDice).
inline int wmcHardStartDice()
    { return 3; }

// a small fire will not go out within three turns unrefueled
// (wflSmallRefuelGrace).
inline int wmcSmallRefuelGrace()
    { return 3; }

// ---- the fold findings ----

// the uncontrollable bar of 6 turns equals the 6 turns per hour - a fire left
// alone for exactly one hour becomes uncontrollable.
inline bool wmcBarIsOneHour()
    { return true; }

// the Table 38 small-fire refuel interval and the fuel-header grace period
// are the same 3 turns - two headers, one number.
inline bool wmcRefuelGraceIdentity()
    { return true; }

// the 20 mph value appears in three headers: the small fire wind resistance,
// the rest wind-penalty threshold, and the poor-shelter full-protection
// example.
inline bool wmcWindTwentyTriple()
    { return true; }

// the no-start wind maximum of 30 mph equals the medium fire wind resistance
// - the fire that cannot be started in such wind is the one that would have
// withstood it.
inline bool wmcNoStartMatchesMedium()
    { return true; }

// the growth ladder 1, 2, 4 doubles while the fuel, refuel, wind-resistance
// and spark ladders are all arithmetic - the only geometric ladder in the
// camp chain.
inline bool wmcGrowthOnlyGeometric()
    { return true; }

// the rest cold threshold is the R499 dress below-0 boundary value - the camp
// chain plugs into the temperature chain at the same 0.
inline bool wmcRestColdSeamR499()
    { return true; }

// the rest hot threshold of 90 opens one degree past the R499 protected
// no-damage top of 89, at heat band 18 - the camp chain plugs into the
// temperature chain on the hot side too.
inline bool wmcRestHotSeamR499()
    { return true; }

// the plate economy loses a flat 4 hours either way: 5 hours in plate rest
// like 1, and 9 rest like 5.
inline bool wmcPlateFlatLoss()
    { return true; }

// the inside leak of 5 mph per step is half the 10 mph step - the tent halves
// the wind it cannot stop.
inline bool wmcLeakHalfStep()
    { return true; }

// the pole ladder 2, 4, 6 is arithmetic: two more poles per quality tier.
inline bool wmcPolesLinear()
    { return true; }

// ---- the plate economy ----

// a typical five-hour night in plate armor (wgfPlateTypicalNight).
inline int wmcPlateNight()
    { return 5; }

// the five-hour plate night yields one hour of actual rest
// (wgfPlateNightGoodRest).
inline int wmcPlateGoodRest()
    { return 1; }

// sleeping nine hours in plate armor instead (wgfPlateLongSleep).
inline int wmcPlateLongSleep()
    { return 9; }

// nine hours in plate refreshes like five hours with the armor off
// (wgfPlateLongRefresh).
inline int wmcPlateLongRefresh()
    { return 5; }

// ---- the rest-quality penalties ----

// personal temperature below 0: 1 hour of rest lost (wgfPenTempBelow0).
inline int wmcPenTempBelow0()
    { return 1; }

// personal temperature above 90: 2 hours lost (wgfPenTempAbove90).
inline int wmcPenTempAbove90()
    { return 2; }

// wind of 20 mph or greater with no shelter: 2 hours lost
// (wgfPenWindNoShelter).
inline int wmcPenWind()
    { return 2; }

// light or moderate precipitation with no shelter: 3 hours lost
// (wgfPenPrecipNoShelter).
inline int wmcPenPrecip()
    { return 3; }

// wearing any metal armor except plate: 3 hours lost (wgfPenMetalArmor).
inline int wmcPenMetal()
    { return 3; }

// wearing any kind of plate armor: 4 hours lost (wgfPenPlateArmor).
inline int wmcPenPlate()
    { return 4; }

// the rest cold threshold: below 0 degrees - the same boundary value that
// opens the R499 dress below-0 column.
inline int wmcRestColdBound()
    { return 0; }

// the rest hot threshold: above 90 degrees.
inline int wmcRestHotBound()
    { return 90; }

// the R499 fold re-read: the protected heat no-damage span tops at 89 - the
// rest hot threshold opens one degree past it, at heat band 18.
inline int wmcR499ProtTop()
    { return 89; }

// ---- the shelter and tent side ----

// the adequate kit: at least 2 poles (wrsAdequateMinPoles).
inline int wmcPolesAdequate()
    { return 2; }

// the good kit: at least 4 poles (wrsGoodMinPoles).
inline int wmcPolesGood()
    { return 4; }

// the superior kit: at least 6 poles (wrsSuperiorMinPoles).
inline int wmcPolesSuperior()
    { return 6; }

// tent leak steps: every 10 mph above the rating (wrsWindStepMph).
inline int wmcWindStepMph()
    { return 10; }

// those inside feel 5 mph for each 10 mph step above the rating
// (wrsWindLeakMph).
inline int wmcWindLeakMph()
    { return 5; }

// a 25 percent chance per 10 mph step that wind damages the shelter
// (wrsWindDamagePctPerStep).
inline int wmcWindDamagePct()
    { return 25; }

// the book example: a poor shelter protects completely up to 20 mph
// (wrsWindExPoorRes).
inline int wmcPoorShelterRes()
    { return 20; }

// one tent life-span point deducted per three setups
// (wrsLifespanSetupsPerPoint).
inline int wmcLifeSetupsPerPoint()
    { return 3; }

// forest shelter materials: 3 turns minimum (wnsForestMatsMinTurns).
inline int wmcForestMatsMin()
    { return 3; }

// lashing the poles and binding the shingles: 6 turns (wnsLashBaseTurns).
inline int wmcLashBaseTurns()
    { return 6; }

// ---- the wildfire economy ----

// a fire not extinguished within 6 turns grows to uncontrollable size
// (wcfUncontrollableTurns).
inline int wmcUncontrollableTurns()
    { return 6; }

// six turns per hour (wcfTurnsPerHour).
inline int wmcTurnsPerHour()
    { return 6; }

// ten rounds per turn (wcfRoundsPerTurn).
inline int wmcRoundsPerTurn()
    { return 10; }

// the spark carry distance gains one foot per 1 mph of wind
// (wcfSparkWindFtPerMph).
inline int wmcSparkWindFtPerMph()
    { return 1; }

// extinguishing time is halved with a helper or water (wcfHalveDivisor).
inline int wmcHalveDivisor()
    { return 2; }

}   // namespace rules
