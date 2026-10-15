// =========================================================================================
// Adnd1 - rules/wsgfuel.h
// R475: the WSG PRECAUTIONS AND PERILS slice with TABLE 39, printed p. 66 -
// the fifth camping-arc round and the fifth TABLE ROUND of the arc, riding
// the Table 38 column semantics seam unpinned by R474 (whose boxes covered
// only the p. 65 grids): the start discipline (2d20 rounds for a character
// without the fire-building proficiency assuming tools, dry fuel and a breeze
// of no more than 15 mph; wind over 15 mph or wet fuel means 3d20; no start
// without tools for the unproficient; no start in wind over 30 mph without
// magic), the refuel semantics (a fire not refueled in time shrinks to the
// next lower size; a small fire never goes out within three turns but
// provides no warmth), the wind resistance semantics (unprotected fires only;
// falter and flicker with no warmth over the rated velocity; the spread
// chance to an uncontrollable fire), the capacity semantics (six men at 10
// feet from a small fire, doubling per additional 10 feet to 12 men at 20;
// clustering diminishes by one-third at five feet, one-half at three feet and
// two-thirds at one foot: 4, 3 and 2 characters), the visibility semantics
// (yards in moonlight or darkness, one-third off in twilight and one-half off
// in daylight; the 540-yard large-fire flame; the glow through moderately
// dense forest; the steep-hill blockage; the smoke reveal), the warmth
// semantics (the 80-degree minimum safe distance, five segments to move away,
// three feet from a medium fire and five from a large, the 10-mph calm
// assumption, windward warmth minus 5 degrees per 10 mph or fraction, leeward
// safe distance plus 10 feet or one increment whichever is less, and the book
// own 30-mph medium-fire example: 20 degrees at 20 feet on the windward side
// instead of 30, 10 feet on the leeward side instead of 3), Table 39 in TWO
// grids (availability of fuel by terrain and season for a temperate climate:
// desert 20/20/20/20, forest 70/100/100/100, hills 40/70/70/60, plains
// 50/70/80/70, swamp 40/30/30/40; and the climate modifiers: desert
// -20/-10/-10/-20, forest -100/-30/+30/+30, hills -30/-20/+10/+20, mountains
// -40/-30/+20/+30, plains -60/-40/+20/+20, swamp -40/-20/+10/+20), the
// every-two-turns further checks, and the start of precautions and perils (no
// safe fire, the untended conflagration, the cardinal rules, the first rule:
// no fire on combustibles, 1-3 turns to clear, sparks 100 feet in a strong
// wind), printed p. 66.
// census 399 -> 400.
//
// Ground truth two-way on the prose and the uncontested Table 39 cells, no
// physical-page reads: the user-run Termux tesseract text of printed p. 66
// (p66_full.txt, p66_tsv.tsv) vs the pdf embedded text layer (pdftotext
// -layout, pdf page 67, p66_pdfy.txt). The two readers AGREE on all prose
// numbers: the 15-mph start breeze and the 3d20-instead-of-2d20 escalation,
// the 30-mph magical bar, the three-turn small-fire refuel grace, the 10-foot
// capacity base with the doubling to 12 men and the one-third, one-half and
// two-thirds clustering cuts with the 4/3/2 example, the 540-yard large-fire
// visibility with the one-third twilight and one-half daylight reductions,
// the 80-degree safe distance with the five segments and the 3-foot medium
// and 5-foot large burns, the 10-mph warmth assumption with the
// 5-degrees-per-10-mph windward cut and the 10-feet-or-one-increment leeward
// add, the full 30-mph worked example (20 degrees at 20 feet windward instead
// of 30, 10 feet leeward instead of 3), the temperate fuel grid for desert,
// forest, plains and swamp, the climate modifier grid for desert, forest,
// mountains, plains and swamp, the every-two-turns recheck and the 1-3 turn
// clearing time with 100-foot spark carry. CONTESTED: the HILLS rows of BOTH
// Table 39 grids - the pdf text layer DROPPED the hills rows from both grids
// entirely, and tesseract garbles them (the temperate autumn cell as a wide
// low-confidence blob, the four modifier cells as near-zero-confidence
// noise). The standing vision-on-png settler was applied TWICE with
// independent prompts, and BOTH reads AGREE EXACTLY: temperate hills
// 40/70/70/60 and climate modifiers -30/-20/+10/+20 - the R471/R473
// two-vision-read precedent, with the second read calibrated against the
// neighboring rows. A web search for an independent online copy of the table
// found none. The settled rows are also plausible against their neighbors:
// the hills arctic -30 sits between forest -100 and mountains -40, and the
// hills modifiers match swamp on the three warmer columns.
//
// All 44 Table 39 cells pinned (the 20 temperate cells and the 24
// climate-modifier cells, both hills rows vision-settled); the Table 38
// column semantics, the worked wind example and the fire safety prose are
// audit examples.
//
namespace rules {

// ---- The start discipline ----

// the start discipline assumes the fire is exposed to a breeze of no more
// than 15 mph
inline int wflStartBreezeMax()
    { return 15; }

// the start roll die: d20
inline int wflStartDie()
    { return 20; }

// a character without the fire-building proficiency starts a fire in 2d20
// rounds
inline int wflStartDice()
    { return 2; }

// in wind over 15 mph or with wet fuel the time needed to start the fire is
// 3d20 instead
inline int wflHardStartDice()
    { return 3; }

// no character can start a fire in a wind of more than 30 mph without magical
// assistance
inline int wflNoStartWindMax()
    { return 30; }

// the start discipline assumes the character has the tools for fire-starting
// (flint and steel, and a tinderbox) and the fuel is dry and easy to ignite
inline bool wflStartAssumesTools()
    { return true; }

// if the wind velocity is greater than 15 mph or the fuel is wet, the time
// needed to start the fire is 3d20 instead of 2d20, plus the extra time for a
// medium or large fire
inline bool wflHardStartOnWindOrWet()
    { return true; }

// a character without proficiency in fire-building cannot start a fire
// without the aid of tools
inline bool wflUnskilledNeedsTools()
    { return true; }

// ---- The refuel and wind resistance ----

// a small fire will not go out if it is not refueled within three turns
inline int wflSmallRefuelGrace()
    { return 3; }

// refuel, expressed in turns, is how often a fire fuel must be replenished
// for it to remain at a certain size
inline bool wflRefuelKeepsSize()
    { return true; }

// a fire not refueled at least this often will shrink to a fire of the next
// lower size
inline bool wflUnrefueledShrinks()
    { return true; }

// a small fire will not go out within three turns, but it will get so small
// that it provides no warmth
inline bool wflSmallFireLingersCold()
    { return true; }

// wind resistance pertains only to unprotected fires or those built in front
// of shelters that do not keep out all the wind
inline bool wflWindResUnprotectedOnly()
    { return true; }

// in a wind greater than the indicated velocity the fire will falter and
// flicker, providing no warmth
inline bool wflOverRatedWindFalters()
    { return true; }

// there is a chance the wind will spread the fire to nearby combustible
// materials and may start a larger, uncontrollable fire
inline bool wflWindMaySpreadFire()
    { return true; }

// ---- The capacity semantics ----

// capacity is measured for characters bedded down at 10 feet from the fire
inline int wflCapBaseFeet()
    { return 10; }

// six men can bed down in a rough circle 10 feet away from a small fire
inline int wflSmallCapAt10()
    { return 6; }

// the same small fire will warm 12 men equally at 20 feet
inline int wflSmallCapAt20()
    { return 12; }

// a fire capacity doubles for each additional 10 feet of distance
inline int wflCapStepFeet()
    { return 10; }

// clustering at five feet diminishes capacity by one-third: numerator
inline int wflDimFiveNum()
    { return 1; }

// clustering at five feet diminishes capacity by one-third: denominator
inline int wflDimFiveDen()
    { return 3; }

// clustering at three feet diminishes capacity by one-half: numerator
inline int wflDimThreeNum()
    { return 1; }

// clustering at three feet diminishes capacity by one-half: denominator
inline int wflDimThreeDen()
    { return 2; }

// clustering at one foot diminishes capacity by two-thirds: numerator
inline int wflDimOneNum()
    { return 2; }

// clustering at one foot diminishes capacity by two-thirds: denominator
inline int wflDimOneDen()
    { return 3; }

// four characters can bed down within five feet of a small fire
inline int wflClusterFiveMax()
    { return 4; }

// three characters can cluster within three feet of the fire
inline int wflClusterThreeMax()
    { return 3; }

// two characters can be within one foot of a small fire at the same time
inline int wflClusterOneMax()
    { return 2; }

// a fire capacity doubles for each additional 10 feet of distance
inline bool wflCapDoublesPerStep()
    { return true; }

// if characters cluster around a fire at less than 10 feet, the fire capacity
// diminishes by one-third at five feet, one-half at three feet and two-thirds
// at one foot
inline bool wflCapClustersDiminish()
    { return true; }

// ---- The visibility semantics ----

// the flame of a large fire is easily visible at night from 540 yards away on
// a flat, featureless plain
inline int wflLargeVisYards()
    { return 540; }

// in twilight conditions the visibility figure is reduced by one-third:
// numerator
inline int wflTwilightNum()
    { return 1; }

// the twilight visibility reduction: denominator
inline int wflTwilightDen()
    { return 3; }

// in daylight the visibility figure is reduced by one-half: numerator
inline int wflDaylightNum()
    { return 1; }

// the daylight visibility reduction: denominator
inline int wflDaylightDen()
    { return 2; }

// visibility gives the distance in yards at which a fire of the given size is
// visible in moonlight or darkness
inline bool wflVisMoonlightOrDarkness()
    { return true; }

// in twilight conditions the visibility figure is reduced by one-third
inline bool wflVisTwilightReduction()
    { return true; }

// in daylight the visibility figure is reduced by one-half
inline bool wflVisDaylightReduction()
    { return true; }

// in all cases the viewer line of sight must be relatively unobstructed
inline bool wflVisNeedsClearLine()
    { return true; }

// the glow of the fire will be seen from an equal distance even if viewed
// through a moderately dense forest
inline bool wflGlowThroughDenseForest()
    { return true; }

// the fire will not be visible from a very long distance away if the viewer
// and the fire are on opposite sides of a steep hill
inline bool wflHillBlocksLongSight()
    { return true; }

// in twilight or daylight the flame may not be visible from the indicated
// distance, but the smoke will reveal its presence nonetheless
inline bool wflSmokeRevealsInDaylight()
    { return true; }

// ---- The warmth and wind semantics ----

// the minimum safe distance is the distance at which the air temperature is
// raised by 80 degrees
inline int wflSafeWarmthDegrees()
    { return 80; }

// a character closer than the safe distance must move away promptly, within
// five segments, or may suffer damage
inline int wflMoveAwaySegments()
    { return 5; }

// an unprotected character cannot remain closer than three feet from a medium
// fire without being burned
inline int wflMediumSafeFt()
    { return 3; }

// an unprotected character cannot remain closer than five feet from a large
// fire without being burned
inline int wflLargeSafeFt()
    { return 5; }

// the warming capabilities assume the fire is not exposed to wind of more
// than 10 mph
inline int wflWarmCalmWindMax()
    { return 10; }

// on the side facing the wind the warmth is reduced by 5 degrees per step
inline int wflWindwardDegStep()
    { return 5; }

// the windward warmth reduction applies for every 10 mph or fraction thereof
// of additional velocity
inline int wflWindwardMphStep()
    { return 10; }

// on the side facing away from the wind the safe distance is increased by 10
// feet or one table increment, whichever is less
inline int wflLeewardFeetStep()
    { return 10; }

// the worked example: a medium fire blazing away in a 30-mph north wind
inline int wflExWindMph()
    { return 30; }

// the windward-side sleeper 20 feet away benefits from only a 20-degree
// increase
inline int wflExWindwardDeg()
    { return 20; }

// the calm-wind warmth of the medium fire at 20 feet is 30 degrees
inline int wflExCalmDeg()
    { return 30; }

// the leeward-side sleeper must be at least 10 feet away in the example
inline int wflExLeewardFt()
    { return 10; }

// the calm-wind safe distance for a medium fire is 3 feet
inline int wflExCalmSafeFt()
    { return 3; }

// the minimum safe distance for a certain fire is the distance at which the
// air temperature is raised by 80 degrees
inline bool wflSafeDistanceIs80Degrees()
    { return true; }

// an entry of a dash on the table indicates the unsafe case: an unprotected
// character cannot remain closer without being burned
inline bool wflDashMeansBurned()
    { return true; }

// the warming capabilities assume the fire is not exposed to wind of more
// than 10 mph
inline bool wflWarmthAssumesCalm()
    { return true; }

// if the wind on the fire is greater than 10 mph, the warmth on the side
// facing the wind is reduced by 5 degrees for every 10 mph or fraction
// thereof of additional velocity
inline bool wflWindwardWarmthCut()
    { return true; }

// on the side facing away from the wind the safe distance is increased by 10
// feet or one increment on the table, whichever is less, for every 10 mph or
// fraction thereof over 10 mph
inline bool wflLeewardSafeAdd()
    { return true; }

// ---- Table 39: the availability of fuel ----

// the temperate Table 39 grid covers five terrains: desert, forest, hills,
// plains and swamp
inline int wflTerrainCount()
    { return 5; }

// the climate modifier grid covers six terrains: desert, forest, hills,
// mountains, plains and swamp
inline int wflClimateTerrainCount()
    { return 6; }

// when moving in hopes of a better camp spot, the DM allows further fuel
// checks every two turns
inline int wflRecheckTurns()
    { return 2; }

// the Table 39 grids give the percentage chance that characters will be able
// to gather fuel (wood) for a fire from their immediate surroundings
inline bool wflFuelIsWood()
    { return true; }

// the temperate grid assumes the given terrain is in a temperate climate,
// with the second grid supplying the modifiers for other climates
inline bool wflTemperateAssumed()
    { return true; }

// if a fuel check indicates none can be scavenged and characters keep moving
// in hopes of a better spot, the DM should allow further checks every two
// turns
inline bool wflMovingAllowsRechecks()
    { return true; }

// the Table 39 temperate winter fuel availability percent
inline int wflFuelWinter(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 70;
        case 2:
            return 40;
        case 3:
            return 50;
        case 4:
            return 40;
        default:
            return 0;
        }
    }

// the Table 39 temperate spring fuel availability percent
inline int wflFuelSpring(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 70;
        case 3:
            return 70;
        case 4:
            return 30;
        default:
            return 0;
        }
    }

// the Table 39 temperate summer fuel availability percent
inline int wflFuelSummer(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 70;
        case 3:
            return 80;
        case 4:
            return 30;
        default:
            return 0;
        }
    }

// the Table 39 temperate autumn fuel availability percent
inline int wflFuelAutumn(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 100;
        case 2:
            return 60;
        case 3:
            return 70;
        case 4:
            return 40;
        default:
            return 0;
        }
    }

// the Table 39 arctic climate modifier
inline int wflArcticMod(int b)
    {
        switch (b) {
        case 0:
            return -20;
        case 1:
            return -100;
        case 2:
            return -30;
        case 3:
            return -40;
        case 4:
            return -60;
        case 5:
            return -40;
        default:
            return 0;
        }
    }

// the Table 39 subarctic climate modifier
inline int wflSubarcticMod(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return -30;
        case 2:
            return -20;
        case 3:
            return -30;
        case 4:
            return -40;
        case 5:
            return -20;
        default:
            return 0;
        }
    }

// the Table 39 subtropical climate modifier
inline int wflSubtropicalMod(int b)
    {
        switch (b) {
        case 0:
            return -10;
        case 1:
            return 30;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 20;
        case 5:
            return 10;
        default:
            return 0;
        }
    }

// the Table 39 tropical climate modifier
inline int wflTropicalMod(int b)
    {
        switch (b) {
        case 0:
            return -20;
        case 1:
            return 30;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 20;
        case 5:
            return 20;
        default:
            return 0;
        }
    }

// ---- Precautions and perils ----

// it takes from 1 turn for a single character to clear an area
inline int wflClearMinTurns()
    { return 1; }

// up to 3 turns, at the Dungeon Master discretion, to clear an area before
// building a fire
inline int wflClearMaxTurns()
    { return 3; }

// in a reasonably strong wind sparks and ash from a fire can be carried as
// far as 100 feet away
inline int wflSparkCarryFeet()
    { return 100; }

// in the outdoors there is no such thing as a safe fire
inline bool wflNoSafeFire()
    { return true; }

// a campfire left untended for more than a few minutes or not properly
// extinguished can spread with amazing speed into a conflagration that may be
// impossible to bring back under control
inline bool wflUntendedFireSpreads()
    { return true; }

// the cardinal rules of fire safety are the same in the game universe as they
// are in the real world
inline bool wflCardinalRulesRealWorld()
    { return true; }

// the first cardinal rule: do not build a fire on top of combustible material
// - find a large patch of bare ground, or clear the area of all living and
// dead vegetation, before building
inline bool wflNoFireOnCombustibles()
    { return true; }

}   // namespace rules
