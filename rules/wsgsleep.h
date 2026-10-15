// =========================================================================================
// Adnd1 - rules/wsgsleep.h
// R473: the WSG PORTABLE SHELTER MECHANICS and REST AND COMFORT slice with
// TABLE 37 - the shelter kits (the poor covering loosely stitched of several
// pieces with wind through the seams and no anchoring gear or rope provided,
// what an unskilled maker ends up with; the adequate kit of at least two
// poles - a backbone ridgepole and a cross-brace - with tighter stitching and
// stakes driven through the covering edges; the good kit of at least four
// poles with the covering pieces stitched tightly and overlapped like
// shingles so no seams are exposed and reinforced edge holes for damage-free
// anchoring; the superior kit of at least six poles making a strong frame, a
// tailored covering of as few pieces as possible with reinforced seams - a
// true structure, the next best thing to a miner's shack), the occupancy (a
// small shelter one human-sized or two smaller characters plus all their
// gear, twice as many in close quarters; a medium two human-sized, twice as
// many close; a large four by design, five or six sleeping with gear stored
// outside, seven or eight in close quarters and no more than eight), the
// setup and takedown discipline (a second character reducing setup by 1 turn;
// a rope use proficient character halving the setup time rounded up with or
// without help; the 1/2/3-turn setup minimums by size; the takedown in 1 turn
// less than setup regardless of helpers, halved by rope use proficiency, with
// the 5-round/1-turn/2-turn minimums; the poor and adequate kits assuming the
// characters bring their own rope), the moisture rule (precip heavier than
// the value gets through as a storm one step lighter; a superior shelter
// protecting from even a downpour unless the wind is too strong or the storm
// separates it from its moorings), the wind rules (the greatest velocity
// withstood without leaking; every 10 mph above the number a 5 mph wind felt
// inside; above twice the number a 25% chance per 10 mph each hour of wind
// damage leaving the shelter useless until repaired; the book example of the
// 20-mph poor shelter feeling 5/10/15/20 mph at 30/40/50/60 with 25% then 50%
// damage per hour), the life span (the shelter's hit points: 1 point per
// three times put up, 1 per non-damaging over-wind exposure, 2 per
// equal-intensity precip, 4 per greater; a superior, good or adequate shelter
// dropping to the next category's maximum treated as that category; a poor
// shelter useless at half its points, 40 down to 20; the hailstorm and
// cracked-pole mishaps aging a shelter before its time), the rest and comfort
// rules (no more than 16 hours per day in active adventuring, fatigue stops
// not counting as rest; camp chores in three hours at most; five hours of
// sleep every 24 hours to avoid the risk of ill effects that may not show up
// right away) and TABLE 37 EFFECTS OF LACK OF SLEEP (the five bands less than
// 5/4/3/2/1 hours average rest per day: Dexterity Checks at +1/+2/+3/+4/+5;
// Strength at +1/+2/+3/+4 from the second band; Wisdom at +1/+2/+3 from the
// third; Constitution at +1/+2 in the bottom two; to-hit -1/-1/-2/-3;
// Climbing Rating -10/-20/-30 percent; Movement Rate -25/-33/-50 percent;
// Weight Allowance -50 and -100 x Strength), printed pp. 63-64.
// census 397 -> 398.
//
// Ground truth two-way on the prose, three-way on the contested grid cells,
// no physical-page reads: the user-run Termux tesseract text of printed pp.
// 63-64 (p63_full.txt, p64_full.txt) vs the pdf embedded text layer
// (pdftotext -layout, pdf pages 64-65, p63_64_pdfy.txt). The two readers
// AGREE on all prose numbers: the 2/4/6 pole minimums, the occupancy counts,
// the 1-turn helper saving, the 1/2/3-turn setup minimums, the one-turn-less
// takedown with the 5-round/1-turn/2-turn minimums, the 10-mph/5-mph wind
// leak step, the twice-threshold 25% damage chance, the 1/3-use and 1/2/4
// life span point rates, the poor 40-to-20 collapse, the 16/3/5-hour rules,
// the two-day trigger, the one-night negation and the 12-to-6 movement
// example. For the TABLE 37 GRID the tesseract TSV geometry and full text
// carry every cell EXCEPT the LESS-THAN-2 DEXTERITY AND STRENGTH cells, which
// tesseract garbles into low-confidence noise: the pdf layer reads them as
// Dexterity Checks at +4 and Strength Checks at +3, and a VISION READ of the
// uploaded page image (pg-001-2.png) SECOND-CONFIRMS the full grid including
// those two contested cells - the R471 vision-on-png combo as the standing
// contested-cell settler. The grid is also internally consistent: each
// ability ladder steps exactly one per band, and the less-than-5 band carries
// the Dexterity entry alone.
//
// All 40 Table 37 cells pinned (the five bands by eight effect columns); the
// shelter kit mechanics, the setup and takedown discipline, the wind and
// moisture semantics, the life span economy, the rest and sleep rules and the
// book's own worked wind and movement examples are audit examples.
//
namespace rules {

// ---- The shelter kits ----

// the poor shelter "single piece" covering is actually several pieces loosely
// stitched with rawhide or cord neither particularly strong nor durable: wind
// easily finds its way in through the seams, and the covering does not
// completely keep out rain or snow because of its loose construction
inline bool wrsPoorKitLooseStitching()
    { return true; }

// the poor kit provides no special anchoring equipment and no rope: the edges
// must be anchored with rocks or other weights at hand or handmade stakes
// whittled from branches, the characters provide their own rope, and an
// unskilled character manufacturing a portable shelter ends up with this
// quality
inline bool wrsPoorKitBringYourOwn()
    { return true; }

// the adequate covering is made of multiple sections just as a poor one, but
// the edges are more closely matched and the stitching tighter and stronger:
// it does not let in wind or precipitation as easily, and its wooden or metal
// stakes are driven through the edges into the ground
inline bool wrsAdequateKitTighter()
    { return true; }

// the good covering pieces are not only stitched tightly together but
// overlapped like shingles so no seams are directly exposed on the outer
// surface, and the edges contain reinforced holes through which a stake can
// be driven or a rope strung to anchor without damaging the material
inline bool wrsGoodKitShingled()
    { return true; }

// the superior covering is extremely well waterproofed, made of as few
// separate pieces as possible with joined seams reinforced by another
// thickness of material: a true structure keeping out all but the strongest
// wind and heaviest precipitation, the next best thing to finding a miner's
// shack
inline bool wrsSuperiorKitStructure()
    { return true; }

// the adequate shelter kit includes at least two poles: one for a backbone
// (ridgepole) and one for a cross-brace
inline int wrsAdequateMinPoles()
    { return 2; }

// the good kit: at least four poles - a ridgepole, a cross-brace and two side
// poles for added strength and stability
inline int wrsGoodMinPoles()
    { return 4; }

// the superior kit: at least six poles, enough to actually make a simple but
// strong frame for the cover
inline int wrsSuperiorMinPoles()
    { return 6; }

// ---- The occupancy ----

// a small shelter comfortably holds one human-sized character (or two smaller
// ones) plus all their personal gear
inline int wrsSmallComfort()
    { return 1; }

// the small shelter can be used to shelter up to twice as many occupants in
// close quarters
inline bool wrsSmallCloseQuarters()
    { return true; }

// a medium shelter easily accommodates two human-sized characters, or the
// equivalent in smaller characters
inline int wrsMediumComfort()
    { return 2; }

// the medium shelter holds up to twice as many in close quarters
inline bool wrsMediumCloseQuarters()
    { return true; }

// a large shelter is designed to hold four human-sized characters
inline int wrsLargeDesign()
    { return 4; }

// a large shelter can sleep five or six men if the group stores some of its
// gear outside
inline int wrsLargeSleepMax()
    { return 6; }

// a large shelter holds seven or eight men in close quarters, and no more
// than eight can sleep inside it
inline int wrsLargeCloseMax()
    { return 8; }

// no more than eight can sleep inside a large shelter without some of the
// occupants being literally on top of others
inline bool wrsLargeCloseQuartersOnly8()
    { return true; }

// ---- The setup and takedown ----

// the poor and adequate setup times assume the characters have rope and, for
// a poor shelter, some objects with which to anchor the cover
inline bool wrsSetupAssumesRope()
    { return true; }

// a second character assisting with the setup reduces the time by 1 turn
inline int wrsSetupHelperSaving()
    { return 1; }

// a character with proficiency in rope use sets up the shelter, with or
// without help, in half the time (rounded up) indicated by the die roll
inline bool wrsRopeUseHalvesSetup()
    { return true; }

// it takes at least 1 turn to set up a small shelter
inline int wrsSetupMinSmallTurns()
    { return 1; }

// a medium shelter takes at least 2 turns to set up
inline int wrsSetupMinMediumTurns()
    { return 2; }

// a large shelter takes at least 3 turns to set up
inline int wrsSetupMinLargeTurns()
    { return 3; }

// taking down the shelter and re-packing it takes 1 turn less than it took to
// put up
inline int wrsTakedownSavingTurns()
    { return 1; }

// the takedown time is 1 turn less than the setup time regardless of how many
// characters assist
inline bool wrsTakedownNoHelperBonus()
    { return true; }

// a character with proficiency in rope use can dismantle and properly pack a
// shelter in half the time it takes a nonproficient character
inline bool wrsRopeUseHalvesTakedown()
    { return true; }

// at least five rounds to dismantle and pack a small shelter
inline int wrsTakedownMinSmallRounds()
    { return 5; }

// at least 1 turn to dismantle and pack a medium shelter
inline int wrsTakedownMinMediumTurns()
    { return 1; }

// at least 2 turns to dismantle and pack a large shelter
inline int wrsTakedownMinLargeTurns()
    { return 2; }

// ---- The moisture and wind rules ----

// precipitation heavier than the moisture resistance value gets through the
// shelter and falls on the occupants as though they were in a storm one step
// lighter in intensity (a poor shelter douses its occupants in a moderate
// storm as if they were in the open during a light one)
inline bool wrsMoistureOneStepLighter()
    { return true; }

// a superior shelter protects those inside from even a downpour, as long as
// the wind is not too strong and the force of the storm does not separate the
// shelter from its moorings
inline bool wrsSuperiorDownpourCaveat()
    { return true; }

// the wind resistance number is the greatest wind velocity the shelter
// withstands without leaking, and the effective temperature inside changes
// with the leaked breeze
inline bool wrsWindLeakRule()
    { return true; }

// for every 10 mph of actual wind velocity greater than the indicated number
inline int wrsWindStepMph()
    { return 10; }

// those inside the tent feel a wind of 5 mph for each 10 mph step above the
// rating
inline int wrsWindLeakMph()
    { return 5; }

// the wind damage chance applies if the velocity exceeds twice the indicated
// number
inline int wrsWindDamageThresholdMult()
    { return 2; }

// a 25% chance for each 10 mph of additional velocity, checked each hour,
// that the wind damages the shelter
inline int wrsWindDamagePctPerStep()
    { return 25; }

// a wind-damaged shelter is useless until it is repaired
inline bool wrsWindDamageUseless()
    { return true; }

// the book wind example: a poor shelter provides complete protection up to 20
// mph
inline int wrsWindExPoorRes()
    { return 20; }

// the book example: at 30 mph those inside feel a breeze of 5 mph
inline int wrsWindEx30Leak()
    { return 5; }

// the book example: at 40 mph the breeze inside is 10 mph
inline int wrsWindEx40Leak()
    { return 10; }

// the book example: at 50 mph the breeze inside is 15 mph
inline int wrsWindEx50Leak()
    { return 15; }

// the book example: at 60 mph the breeze inside has reached a hefty 20 mph
inline int wrsWindEx60Leak()
    { return 20; }

// the book example: at 50 mph a 25% chance per hour of wind damage
inline int wrsWindEx50DamagePct()
    { return 25; }

// the book example: at 60 mph a 50% chance per hour of wind damage
inline int wrsWindEx60DamagePct()
    { return 50; }

// ---- The life span ----

// life span may be thought of as the shelter's hit points: a new or freshly
// repaired shelter has the indicated number of life span points
inline bool wrsLifespanAsHitPoints()
    { return true; }

// 1 life span point deducted for each three times the shelter is put up
inline int wrsLifespanSetupsPerPoint()
    { return 3; }

// 1 point for each exposure to wind speeds above its wind resistance that
// does no actual damage
inline int wrsLifespanWindPoints()
    { return 1; }

// 2 points for each exposure to precipitation equal in intensity to its
// moisture resistance value
inline int wrsLifespanEqualPrecipPoints()
    { return 2; }

// 4 points for each exposure to precipitation greater in intensity than its
// moisture resistance value
inline int wrsLifespanGreaterPrecipPoints()
    { return 4; }

// when a superior, good or adequate shelter loses enough points to bring it
// down to the maximum value of the next lower category, it is treated as a
// shelter of that category until it deteriorates completely or is repaired
inline bool wrsCategoryDegradation()
    { return true; }

// a poor shelter starts with 40 life span points
inline int wrsPoorLifespanMax()
    { return 40; }

// a poor shelter losing half its maximum points (from 40 to 20) is useless
// until repaired
inline int wrsPoorUselessAt()
    { return 20; }

// repair costs and availability are in the province of the DM, but hauling a
// dilapidated poor shelter into town to be fixed would cost more effort and
// time than it is worth: cut up the cover and make it into sacks or saddle
// blankets
inline bool wrsPoorHalfUseless()
    { return true; }

// the life span does not account for mishaps that age a shelter early: a
// hailstorm may at the DM discretion punch holes or weaken the seams, a tent
// pole cracked flailing on a wild bear will not hold the cover in a stiff
// wind, but barring such occurrences most shelters serve well for an
// adventure or two or longer
inline bool wrsLifespanHazards()
    { return true; }

// ---- Rest and comfort ----

// a character should spend no more than 16 hours per day in active
// adventuring pursuits
inline int wrsMaxActiveHours()
    { return 16; }

// the 16-hour active time includes rest stops taken to avoid fatigue, which
// do not count as actual rest for these rules; the remainder of the day is
// set aside for making camp, eating and sleeping
inline bool wrsActiveTimeCap()
    { return true; }

// setting up a shelter, hunting and foraging, and cooking the nighttime meal
// should all be done in three hours at most
inline int wrsCampChoreHours()
    { return 3; }

// a character needs five hours of sleep every 24 hours to avoid the risk of
// ill effects from lack of rest
inline int wrsSleepHoursNeeded()
    { return 5; }

// an improperly rested character's ill effects may not show up right away,
// might not manifest themselves at all if he is lucky, or might come back to
// haunt him at a very inopportune time
inline bool wrsSleepRiskHidden()
    { return true; }

// ---- Table 37: the effects of lack of sleep ----

// the Table 37 average-rest bands: less than 5, 4, 3, 2 and 1 hours
inline int wrsSleepBands()
    { return 5; }

// the Table 37 row count
inline int wrsRowCount()
    { return 5; }

// the Table 37 Dexterity Check modifier on the die roll
inline int wrsDexCheck(int b)
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
        default:
            return 0;
        }
    }

// the Table 37 Strength Check modifier on the die roll
inline int wrsStrCheck(int b)
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
        default:
            return 0;
        }
    }

// the Table 37 Wisdom Check modifier on the die roll
inline int wrsWisCheck(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        default:
            return 0;
        }
    }

// the Table 37 Constitution Check modifier on the die roll
inline int wrsConCheck(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        default:
            return 0;
        }
    }

// the Table 37 to-hit penalty
inline int wrsToHit(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -2;
        case 4:
            return -3;
        default:
            return 0;
        }
    }

// the Table 37 Climbing Rating reduction percent
inline int wrsClimbPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -10;
        case 3:
            return -20;
        case 4:
            return -30;
        default:
            return 0;
        }
    }

// the Table 37 Movement Rate reduction percent
inline int wrsMovePct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -25;
        case 3:
            return -33;
        case 4:
            return -50;
        default:
            return 0;
        }
    }

// the Table 37 Weight Allowance penalty, a multiple of the character's
// Strength
inline int wrsWtMult(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 50;
        case 4:
            return 100;
        default:
            return 0;
        }
    }

// ---- The lack-of-sleep discipline ----

// the lack-of-sleep effects do not set in until a character has gone two days
// without at least five hours of sleep during one of them
inline int wrsTriggerDays()
    { return 2; }

// a character can stay up all night and function normally throughout the next
// day, but if he does not get at least five hours of sleep on the following
// night then the effects begin at sunrise or when he awakens
inline bool wrsTwoDayTrigger()
    { return true; }

// average rest per day is calculated on a day-by-day basis whenever a
// character goes two or more consecutive days without getting at least five
// hours of sleep during one of those days
inline bool wrsDayByDayCalc()
    { return true; }

// as soon as he gets five hours of sleep in a single day, any and all effects
// are negated: the character is replenished by one good night's sleep even
// after several deprived days in a row
inline bool wrsOneNightNegation()
    { return true; }

// the table modifiers are applied to the die roll whenever an Ability Check
// or a Proficiency Check related to the indicated ability is called for
inline bool wrsCheckModifierOnRoll()
    { return true; }

// the movement rate entries reduce the character's normal large-scale
// movement rate, taken after all other adjustments for terrain and
// encumbrance are accounted for
inline bool wrsMoveReductionAfterAdjustments()
    { return true; }

// the book movement example: a character with a normal movement rate of 12
inline int wrsExMoveRate()
    { return 12; }

// the book movement example: operating with less than 1 hour of sleep he can
// travel only 6 miles per half-day on foot
inline int wrsExHalfDayMiles()
    { return 6; }

// the movement penalty does not apply in combat situations or other
// feet-per-round movement: ambushed while travelling 6 miles per half-day,
// the character still moves at his full rate while the combat episode is
// resolved
inline bool wrsCombatMoveExempt()
    { return true; }

}   // namespace rules
