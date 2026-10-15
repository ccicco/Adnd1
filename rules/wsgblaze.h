// =========================================================================================
// Adnd1 - rules/wsgblaze.h
// R476: the WSG UNCONTROLLABLE FIRES slice, printed p. 67 - the sixth
// camping-arc round, riding the precautions-and-perils seam unpinned by R475
// (whose box stopped at the first cardinal rule): the four cardinal rules of
// fire discipline (the do-not-oversize rule with the two-small-fires advice;
// the never-leave-untended rule with the sentry spark watch), the spark
// semantics (sparks and ash once every 1d3 turns, carried downwind 10-30 feet
// by fire size plus one foot per 1 mph of wind, a 1 in 6 catch chance on
// combustible material, the wild fire that may grow into a blaze charring the
// terrain for several miles), the spread adjudication (minutes in strong wind
// on dry fuel, self-death in calm on sparse or wet material), the
// average-case growth ladder (tiny flame to small fire in 1 turn, to medium
// in 2, to large in 4, uncontrollable within 6 turns - one hour - either by
// height or by area), the extinguishing discipline (5 rounds for a small fire
// on bare ground, 1 turn for a medium, 2 turns for a large, halved by a
// second character or by 1, 2 or 4 gallons of water, doubled on combustible
// material, a 1 in 10 residual chance, and the 2d4-turn flare-up of a
// campfire left alive), and the uncontrollable fires prose (the spread while
// in contact with fuel, the rainstorm-or-created-water stop, the rough circle
// that strings out into a line or wall of fire advancing with the wind, and
// the animals and wise characters fleeing ahead), printed p. 67.
// census 400 -> 401.
//
// Ground truth two-way clean on every number, no contested cells, no
// physical-page reads: the user-run Termux tesseract text of printed p. 67
// (p67_full.txt, p67_tsv.tsv) vs the pdf embedded text layer (pdftotext
// -layout, pdf page 68, p67_pdfy.txt). The two readers AGREE on all prose
// numbers: the 1d3 spark cadence with the 10-20-30 foot carry ladder and the
// 1-foot-per-mph wind add, the 1 in 6 catch chance, the 1-2-4 growth ladder
// with the 6-turn (one hour) uncontrollable bar, the 5-rounds-1-turn-2-turns
// extinguishing times with the halving rule and the 1-2-4 gallon water
// amounts, the doubled time on combustible material with the 1 in 10 residual
// chance, and the 2d4-turn flare-up. The page carries NO table (the user
// confirmed the earlier two-table report was an off-by-one against the
// neighbouring page), so no vision-on-png settler was needed this round.
//
// All prose numbers of printed p. 67 pinned (the spark cadence, the carry
// ladder, the catch chance, the growth ladder, the extinguishing times, the
// water amounts, the residual and flare-up chances); the cardinal rules, the
// spread adjudication and the uncontrollable-fire prose are audit examples.
//
namespace rules {

// ---- The four rules of fire discipline ----

// the second cardinal rule: do not build a larger fire than you need
inline bool wcfNoOversizeRule()
    { return true; }

// it is usually better to build two small fires instead of one medium fire
inline bool wcfTwoSmallFiresBetter()
    { return true; }

// smaller fires are easier to control and can be extinguished more quickly
inline bool wcfSmallerEasierControl()
    { return true; }

// the third cardinal rule: never leave a fire untended
inline bool wcfNeverLeaveUntended()
    { return true; }

// the primary duty of a sentry is to be alert for threats, including sparks
// and bits of glowing ash
inline bool wcfSentryWatchesFire()
    { return true; }

// ---- The sparks and the wild fire ----

// a campfire throws off sparks and ash once every 1d3 turns
inline int wcfSparkDieSides()
    { return 3; }

// the bits of flame from a small fire are carried 10 feet
inline int wcfSparkCarrySmallFt()
    { return 10; }

// the bits of flame from a medium fire are carried 20 feet
inline int wcfSparkCarryMediumFt()
    { return 20; }

// the bits of flame from a large fire are carried 30 feet
inline int wcfSparkCarryLargeFt()
    { return 30; }

// the carry distance gains one foot for every 1 mph of wind velocity
inline int wcfSparkWindFtPerMph()
    { return 1; }

// sparks landing on combustible material catch on fire on a roll of 1
inline int wcfCatchRoll()
    { return 1; }

// on 1d6: a 1 in 6 chance the material catches on fire
inline int wcfCatchDie()
    { return 6; }

// a wild fire not extinguished promptly may grow into a large blaze charring
// the terrain for several miles
inline bool wcfWildFireCanGrow()
    { return true; }

// how quickly and how far a fire spreads is determined by the Dungeon Master
// depending on the circumstances
inline bool wcfDmAdjudicatesSpread()
    { return true; }

// with very strong wind, very dry combustible material and plenty of fuel the
// fire reaches uncontrollable proportions in a matter of minutes
inline bool wcfStrongWindMinutes()
    { return true; }

// with calm wind and very sparse or very wet material the fire may go out by
// itself
inline bool wcfCalmMayDie()
    { return true; }

// ---- The growth ladder ----

// in an average case a tiny flame grows into a small fire in 1 turn
inline int wcfGrowthSmallTurns()
    { return 1; }

// the small fire grows into a medium fire in 2 turns
inline int wcfGrowthMediumTurns()
    { return 2; }

// the medium fire grows into a large fire in 4 turns
inline int wcfGrowthLargeTurns()
    { return 4; }

// a fire not extinguished within 6 turns grows to uncontrollable size
inline int wcfUncontrollableTurns()
    { return 6; }

// the six turns of the uncontrollable bar are one hour: six turns per hour
inline int wcfTurnsPerHour()
    { return 6; }

// ten rounds per turn, the small-fire extinguishing unit boundary
inline int wcfRoundsPerTurn()
    { return 10; }

// uncontrollable size comes either from the height of the blaze or from the
// area it covers
inline bool wcfUncontrollableByHeightOrArea()
    { return true; }

// ---- Extinguishing a fire ----

// a single character extinguishes a small fire on bare ground in 5 rounds
inline int wcfExtinguishSmallRounds()
    { return 5; }

// a medium fire is extinguished in the same way in 1 turn
inline int wcfExtinguishMediumTurns()
    { return 1; }

// a large fire is put out in 2 turns
inline int wcfExtinguishLargeTurns()
    { return 2; }

// the extinguishing time is cut in half with a helper or water
inline int wcfHalveDivisor()
    { return 2; }

// extinguishing means stirring and separating the ashes, stamping on the
// larger burning pieces and covering the remains with dirt
inline bool wcfExtinguishMethod()
    { return true; }

// the extinguishing time is cut in half if a second character assists
inline bool wcfHelperHalvesTime()
    { return true; }

// the extinguishing time is also cut in half if a sufficient amount of water
// is sprinkled or poured on the embers
inline bool wcfWaterHalvesTime()
    { return true; }

// 1 gallon of water suffices for a small fire
inline int wcfWaterSmallGal()
    { return 1; }

// 2 gallons of water suffice for a medium fire
inline int wcfWaterMediumGal()
    { return 2; }

// 4 gallons of water suffice for a large fire
inline int wcfWaterLargeGal()
    { return 4; }

// a fire built on top of combustible material takes twice as long to
// extinguish
inline int wcfCombustibleTimeMult()
    { return 2; }

// the time needed to extinguish a fire built on combustible material is twice
// as long, because the material beneath must also be separated and stirred
inline bool wcfCombustibleDoublesTime()
    { return true; }

// even with all proper precautions a combustible-built fire may not be fully
// out on a 1
inline int wcfResidualRoll()
    { return 1; }

// on 1d10: a 1 in 10 chance of incomplete extinguishing
inline int wcfResidualDie()
    { return 10; }

// even with all proper precautions there is a 1 in 10 chance a fire built on
// combustible material is not completely extinguished
inline bool wcfResidualRisk()
    { return true; }

// a campfire left alive flares up in 2d4 turns
inline int wcfFlareDice()
    { return 2; }

// the flare-up die is d4
inline int wcfFlareDieSides()
    { return 4; }

// a campfire left alive flares up after the characters leave the area and may
// spread to the surrounding terrain
inline bool wcfLeftAliveFlares()
    { return true; }

// ---- Uncontrollable fires ----

// an out-of-control fire spreads and grows as long as it remains in contact
// with fuel
inline bool wcfSpreadWhileFuelContact()
    { return true; }

// the spread continues until an outside force such as a rainstorm or
// magically created water slows it or puts it out
inline bool wcfOutsideForceStops()
    { return true; }

// the fire fans out from where it started, at first burning in a rough circle
inline bool wcfRoughCircleFirst()
    { return true; }

// the fire gradually strings out until it becomes a line or wall of fire
// advancing in the direction of the wind
inline bool wcfStringsOutToWall()
    { return true; }

// animals and wise characters flee from the path of the fire, running ahead
// of it
inline bool wcfWiseFlee()
    { return true; }

}   // namespace rules
