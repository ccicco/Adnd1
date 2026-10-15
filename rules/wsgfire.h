// =========================================================================================
// Adnd1 - rules/wsgfire.h
// R474: the WSG GOOD SLEEP VS BAD SLEEP and FIRE slice with TABLE 38 - the
// rest-quality penalty ladder (not prone or relaxed 1; bare ground 1, waived
// for a plate wearer; personal temperature below 0 one hour and above 90 two
// hours; wind of 20 mph or greater with no shelter 2, likewise waived; light
// or moderate precipitation with no shelter 3, likewise waived; any metal
// armor except plate 3; any plate armor 4) with the DM-summed reduction, the
// no-rest threshold when the total penalty exceeds the time spent trying to
// sleep, the extreme-weather bar (no sleep in a lightning storm, a hailstorm
// or a sandstorm unless inside a shelter, and even then the commotion may
// keep him awake), the longer-sleep compensation (a plate wearer five-hour
// night buys one hour of good rest, nine hours refresh like five), the
// sleep-in-armor prudence with the one-night-in-two rule, the armor donning
// discipline (9 minus AC rounds, plus 2 for any plate, plus 5 more unaided
// for field or full plate: leather 1, banded 5, full plate 11 helped or 16
// solo, doffing in half the time with 8 rounds to shed full plate alone) and
// the fire function (cooking incidental, warmth primary, three sizes) with
// Table 38 (fuel 6/12/18 turns for an eight-hour burn, start 2d20 plus
// 0/5/10, refuel 3/6/9, wind resistance 20/30/40, capacity 6/10/15,
// visibility 240/360/540, and the warmth-at-distance ladder by size and
// range), printed p. 65.
// census 398 -> 399.
//
// Ground truth two-way on the prose and the Table 38 top grid, no
// physical-page reads: the user-run Termux tesseract text of printed p. 65
// (p65_full.txt, p65_tsv.tsv) vs the pdf embedded text layer (pdftotext
// -layout, pdf page 66, p65_pdfy.txt). The two readers AGREE on all prose
// numbers: the eight penalty values (tesseract garbles only the minus signs
// on four of the eight lines, never the digits), the DM-summed reduction and
// the no-rest threshold, the three storm types, the 5/1 and 9/5 plate-sleep
// figures, the one-night-in-two rule, the 9-minus-AC donning base with the 2
// and 5 round adds, the 1/5/11/16 donning figures with the half-time doffing
// at 8 rounds, the cooking-incidental and warmth-primary prose, and the Table
// 38 top grid (fuel 6/12/18, start 2d20 +0/+5/+10, refuel 3/6/9, res
// 20/30/40, cap 6/10/15, vis 240/360/540). For the WARMTH-AT-DISTANCE grid
// tesseract garbles four cells into low-confidence noise: the Small row at 50
// and 60 yards (reading 00 and 10) and the Large row at 20 and 60 yards
// (reading 4 and O). The pdf layer reads them as 0, 0, 40 and 0, and the TSV
// WORD-BOX GEOMETRY (the R467 workflow) settles them: the Small at-60 box is
// 20 pixels wide like every single-digit cell (a true 10 is 39 wide), the
// Large at-20 box is 40 pixels wide exactly like every two-digit 40 cell (a
// lone 4 is 19 wide), and the Large at-60 box is a single glyph. The grid is
// also internally consistent: every row decays monotonically with distance,
// and at every shared distance a larger fire warms at least as much as a
// smaller one. NOTE: the standing vision-on-png contested-cell settler was
// tried twice on this page and failed both times - each vision read
// contradicted the two agreeing text layers on uncontested cells (reading the
// refuel column as the start dice and inventing dashes mid-row), so the TSV
// geometry plus monotonicity is the settler of record this round.
//
// All 27 warmth-grid cells pinned (the three sizes by nine distances, with
// 999 marking the three printed dashes as no warmth at that distance: a
// medium fire provides none at 1, a large fire none at 1 or 3); the 24
// top-grid cells, the eight penalties, the armor timing figures and the book
// own plate-sleep and donning examples are audit examples.
//
namespace rules {

// ---- Good sleep vs bad sleep ----

// the rest-quality penalty for a character not prone or in a relaxed
// position: 1 hour of good rest lost
inline int wgfPenNotProne()
    { return 1; }

// the penalty for lying on bare ground with no bedding or padding: 1 hour
// lost (waived for a plate-armor wearer)
inline int wgfPenBareGround()
    { return 1; }

// the penalty for personal temperature below 0 degrees: 1 hour lost
inline int wgfPenTempBelow0()
    { return 1; }

// the penalty for personal temperature above 90 degrees: 2 hours lost
inline int wgfPenTempAbove90()
    { return 2; }

// the penalty for wind of 20 mph or greater with no shelter: 2 hours lost
// (waived for a plate-armor wearer)
inline int wgfPenWindNoShelter()
    { return 2; }

// the penalty for light or moderate precipitation with no shelter: 3 hours
// lost (waived for a plate-armor wearer)
inline int wgfPenPrecipNoShelter()
    { return 3; }

// the penalty for wearing any metal armor except plate: 3 hours lost
inline int wgfPenMetalArmor()
    { return 3; }

// the penalty for wearing any kind of plate armor: 4 hours lost
inline int wgfPenPlateArmor()
    { return 4; }

// a good night rest speaks to the quality of the rest, not the night
inline bool wgfQualityNotNight()
    { return true; }

// to fully benefit from his sleeping time a character must be able to rest in
// comfort, which is not always easy in the wilderness
inline bool wgfComfortRequired()
    { return true; }

// the Dungeon Master adds up all of the penalties that apply and reduces the
// hours of sleep by the indicated amount
inline bool wgfPenaltiesSummed()
    { return true; }

// if the total penalty exceeds the time the character spends trying to sleep,
// the resting did him no good at all
inline bool wgfNoRestWhenExceeded()
    { return true; }

// the starred penalties (bare ground, wind and precipitation) do not apply to
// a character wearing plate armor
inline bool wgfStarPenaltiesSkipPlate()
    { return true; }

// it is impossible to sleep in extreme weather such as a lightning storm, a
// hailstorm or a sandstorm unless the character is inside a shelter
inline bool wgfExtremeWeatherNoSleep()
    { return true; }

// even inside a shelter the commotion caused by the storm may keep him awake
inline bool wgfStormCommotionCaveat()
    { return true; }

// the Dungeon Master may expand the penalty list to account for other
// circumstances where good-quality rest is difficult or impossible
inline bool wgfDmMayExpandPenalties()
    { return true; }

// ---- The longer-sleep compensation ----

// the plate-armor sleeper bedding down for a typical night of five hours
inline int wgfPlateTypicalNight()
    { return 5; }

// a five-hour night in plate armor yields the equivalent of one hour of
// actual rest
inline int wgfPlateNightGoodRest()
    { return 1; }

// sleeping nine hours in plate armor instead
inline int wgfPlateLongSleep()
    { return 9; }

// nine hours in plate refreshes like five hours with the armor off
inline int wgfPlateLongRefresh()
    { return 5; }

// one way to compensate for bad rest is to spend a longer time sleeping
inline bool wgfLongerSleepCompensates()
    { return true; }

// if characters might be set upon during the night, sleeping in full armor is
// probably more prudent than taking it off
inline bool wgfArmorSleepPrudent()
    { return true; }

// because the lack-of-sleep penalties do not go into effect until after the
// second night of deprivation, enough sleep on one night out of every two is
// sufficient
inline bool wgfOneNightInTwoSuffices()
    { return true; }

// ---- The armor donning and doffing ----

// the armor donning base: subtract the armor class from 9 to get the rounds
// to put it on
inline int wgfDonBase()
    { return 9; }

// any plate armor (bronze plate mail, plate mail, field plate or full plate)
// adds 2 rounds to the calculated figure
inline int wgfPlateAddRounds()
    { return 2; }

// field plate or full plate donned without help adds an extra 5 rounds
inline int wgfUnaidedAddRounds()
    { return 5; }

// leather armor is AC 8
inline int wgfLeatherAC()
    { return 8; }

// leather armor (AC 8) can be donned in one round
inline int wgfLeatherDonRounds()
    { return 1; }

// banded mail is AC 4
inline int wgfBandedAC()
    { return 4; }

// banded mail (AC 4) requires five rounds
inline int wgfBandedDonRounds()
    { return 5; }

// full plate armor is AC 0
inline int wgfFullPlateAC()
    { return 0; }

// full plate armor (AC 0) needs 11 rounds with the help of a comrade
inline int wgfFullPlateHelpedRounds()
    { return 11; }

// full plate armor needs 16 rounds singlehandedly
inline int wgfFullPlateSoloRounds()
    { return 16; }

// taking off a suit of full plate armor without help takes 8 rounds (half of
// 16)
inline int wgfFullPlateSoloDoffRounds()
    { return 8; }

// the donning time in rounds is 9 minus the armor class of the armor being
// worn
inline bool wgfDonIsNineMinusAC()
    { return true; }

// any plate armor adds 2 rounds to the calculated donning figure
inline bool wgfPlateAddTwoRounds()
    { return true; }

// field plate or full plate donned without help takes an extra 5 rounds
inline bool wgfUnaidedAddFiveRounds()
    { return true; }

// taking off armor can be done in half the time required to put it on
inline bool wgfDoffHalfTime()
    { return true; }

// a character gets out of his leather gear in one half of one round
inline bool wgfLeatherDoffHalfRound()
    { return true; }

// ---- Table 38: the campfire characteristics ----

// a campfire can be built in one of three sizes
inline int wgfFireSizes()
    { return 3; }

// the fuel values gather enough material to keep a fire of that size burning
// for eight hours
inline int wgfBurnHours()
    { return 8; }

// a campfire is not an integral part of a campsite, though characters usually
// want a small fire when they stop for the night
inline bool wgfFireNotIntegral()
    { return true; }

// the cooking function of a fire is incidental for these rules: food from
// hunting or foraging is just as edible raw
inline bool wgfCookingIncidental()
    { return true; }

// some plants are poisonous unless they are cooked, so characters who do not
// habitually cook may regret their indiscretion
inline bool wgfPlantsPoisonousRaw()
    { return true; }

// the primary function of a campfire is to provide warmth
inline bool wgfWarmthPrimary()
    { return true; }

// the warmth of a campfire can sometimes make the difference between life and
// death
inline bool wgfWarmthLifeOrDeath()
    { return true; }

// the fuel value is how many turns a single character needs to gather enough
// wood or other combustible material for an eight-hour burn
inline bool wgfFuelGatherTurns()
    { return true; }

// the fuel values assume that firewood is available in the environment
inline bool wgfAssumesFirewood()
    { return true; }

// the Table 38 fuel: turns for one character to gather material for an
// eight-hour burn
inline int wgfFuel(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 18;
        default:
            return 0;
        }
    }

// the Table 38 start die
inline int wgfStartDie(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

// the Table 38 start die count
inline int wgfStartCount(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// the Table 38 start modifier
inline int wgfStartMod(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// the Table 38 refuel interval
inline int wgfRefuel(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 9;
        default:
            return 0;
        }
    }

// the Table 38 wind resistance value
inline int wgfWindRes(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 40;
        default:
            return 0;
        }
    }

// the Table 38 capacity value
inline int wgfCapacity(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 10;
        case 2:
            return 15;
        default:
            return 0;
        }
    }

// the Table 38 visibility value
inline int wgfVisibility(int b)
    {
        switch (b) {
        case 0:
            return 240;
        case 1:
            return 360;
        case 2:
            return 540;
        default:
            return 0;
        }
    }

// ---- The warmth-at-distance grid ----

// the Table 38 warmth at distance 1 (999 = the printed dash: no warmth at
// this distance)
inline int wgfWarmAt1(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 999;
        case 2:
            return 999;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 3 (999 = the printed dash: no warmth at
// this distance)
inline int wgfWarmAt3(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 80;
        case 2:
            return 999;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 5
inline int wgfWarmAt5(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 60;
        case 2:
            return 80;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 10
inline int wgfWarmAt10(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 40;
        case 2:
            return 60;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 20
inline int wgfWarmAt20(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 40;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 30
inline int wgfWarmAt30(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 30;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 40
inline int wgfWarmAt40(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 50
inline int wgfWarmAt50(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// the Table 38 warmth at distance 60
inline int wgfWarmAt60(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
