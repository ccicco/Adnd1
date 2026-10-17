// =========================================================================================
// Adnd1 - rules/dsgboat.h
// The DSG UNDERGROUND WATER TRAVEL, R518: printed pp. 46-48 (pdf 47-49) - the
// water travel opener (the deepening riverbeds lifting old access tunnels a
// dozen or more feet above the water, the low ceiling making boat travel
// impossible, the absent weather against the winding passages, the folding
// boat and the weaker collapsible boats and the creature boats of inhabited
// regions, and the scale cut-out model for tight bends), the Table 21
// movement rates grid (the eight boat types from the small rowboat 90/120
// through the large barge 20/30 to the small canoe and kayak at 120/180,
// subject to water flow, with maximum speed counting as hard work), the Table
// 22 standstill grid (1/3 rounds for the small rowboat up to 5/10 for the
// large barge), the movement-relative-to-water-only rule with the 60-ft
// stream and 90-ft canoe netting 30 upstream and 150 downstream, the Table 23
// draught and ceilings grid (from the 1/2-ft small rowboat under a 2-ft
// ceiling to the 1-ft large barge under 4 ft), the Table 24 nonproficiency
// penalties (the -30/-15/-15/-10/-5/-60/-30/-60 movement modifiers and the
// 5/10/0/0/0/20/10/25 capsize chances), the one-proficient-stops-capsize and
// half-proficient-stops-penalty exemptions, the collision rules (the lantern
// and beacon and infravision, the vision-range rule, the d100 blind-travel
// check), the Table 25 collision probability grid (narrow 1-5-20/10-20-40,
// average 0-2-10/5-10-20, wide 0-0-4/1-4-8 proficient/nonproficient), the
// 5%-per-30-ft damage math with the 15% example and the difference-reading
// hull damage, the Table 26 boat damage grid (the eight percent bands from
// the 01-05 slight leak through the 45-60 hull split to the 99-00 no damage),
// the drop-off rules (5% per foot for damage and capsize, the 99/00
// miraculous survival, the Proficiency Check save), the bailing rules
// (strenuous exercise, one character canceling one small hole), and the
// capsizing rules (the loose objects, the 1d4-round refloat, the
// float-downstream rescue, and the boatwright repair seam)
// census 441 -> 442.
//
// the DSG scan (archive.org item advanced-dungeons-dragons-1st-edition), pdf
// = printed + 1; the text read from the IA djvu OCR (djvu.txt lines
// ~5963-6300) with the pdf Acrobat-Capture layer as the second read (idx
// 63-65 = printed pp. 46-48) - every numeric cell dual-confirmed: the six
// tables reconstructed positionally from the Capture Tm coordinates where the
// djvu columns garble (Oar/Paddie, ftir, bargelraft, 1/28, 112ft, 114 ft, 113
// ft, lft, 4%, dlOO, 4100 = d100, 2096 = 20%, 1096/1596 = 10%/15%). The
// Tables 21-24 share one boat key order (small rowboat, coracle, large
// rowboat, small barge/raft, large barge, small canoe, large canoe, kayak).
// The DMG page 54 movement seam and the DSG page 25 boatwright seam are
// noted. The Mining section (Where to Mine, p. 48) starts the NEXT round per
// the content-density rule.
//
// Six tables pin in one round, the most since the cave-in arcs: Table 21 (8x2
// speeds), Table 22 (8x2 standstill rounds), Table 23 (8x2 with the fractions
// pinned as whole units - draught in inches, ceiling in half-feet - so 1/3 ft
// pins as 4 inches and 1 1/2 ft as 3 half-feet), Table 24 (8x2 with the
// movement penalties as positive magnitudes, minus in the name and comment
// per the R514 convention), Table 25 (9 rows keyed width x 3 + flow,
// proficient and nonproficient percents), and Table 26 (8 lo/hi bands with 00
// read as 100; the hull-split band pins as 45-60 exactly as printed,
// overlapping the 21-45 large-holes band at 45 - the R517 overlap lesson: pin
// as printed, never repair the book). Every effect die pins as dice + sides
// consts per the R508 convention (1d6 hours, 2d4+2 turns, 2d4, 1d6 rounds,
// 1d6 pieces, 1d4 refloat rounds). The DMG page 54 and DSG page 25 seams are
// noted; nothing auto-credits.
//
namespace rules {

// ---- the water travel opener ----

// the torrents of rushing water gouge their channels, so riverbeds grow
// deeper and access tunnels that once fed into a river below its surface may
// now end a dozen or more feet above the water.
inline bool dnuRiverbedDeepeningRaisesTunnels()
    { return true; }

// the water might be deep enough for the heaviest of boats, but if the
// ceiling drops to within a few feet of the water, travel by boat is quite
// impossible.
inline bool dnuLowCeilingBlocksBoatTravel()
    { return true; }

// the dangers presented by weather are generally absent from the underground;
// low ceilings and tortuously winding passages create the replacement
// problems.
inline bool dnuWeatherAbsentUnderground()
    { return true; }

// enchanted vessels such as the folding boat are ideal for dungeon
// adventuring, since they can easily be carried through narrow passages and
// down stairways.
inline bool dnuFoldingBoatIdeal()
    { return true; }

// collapsible boats, while expensive and weaker than normal boats, provide
// another means of traversing underground waters.
inline bool dnuCollapsibleBoatsWeaker()
    { return true; }

// in inhabited or heavily traveled regions characters might find boats used
// by underground creatures - borrowed, bought, or otherwise acquired.
inline bool dnuCreatureBoatsAcquirable()
    { return true; }

// when carrying a boat into a dungeon the DM must note the boat dimensions
// against the passage sizes; in tight series of turns a scale cut-out model
// of the boat over a detailed corridor map shows whether it fits.
inline bool dnuScaleModelForTightBends()
    { return true; }

// ---- the Table 21 movement rates grid ----

// the Table 21 boat movement rates grid carries eight boat types.
inline int dnuT21RowCount()
    { return 8; }

// the normal oar/paddle speed in feet per round, subject to the speed and
// direction of water flow: 0 small rowboat 90, 1 coracle 30, 2 large rowboat
// 45, 3 small barge/raft 30, 4 large barge 20, 5 small canoe 120, 6 large
// canoe 90, 7 kayak 120.
inline int dnuT21NormalFt(int b)
    {
        switch (b) {
        case 0:
            return 90;
        case 1:
            return 30;
        case 2:
            return 45;
        case 3:
            return 30;
        case 4:
            return 20;
        case 5:
            return 120;
        case 6:
            return 90;
        case 7:
            return 120;
        default:
            return -99;
        }
    }

// the maximum oar/paddle speed in feet per round: 0 small rowboat 120, 1
// coracle 45, 2 large rowboat 60, 3 small barge/raft 45, 4 large barge 30, 5
// small canoe 180, 6 large canoe 120, 7 kayak 180.
inline int dnuT21MaxFt(int b)
    {
        switch (b) {
        case 0:
            return 120;
        case 1:
            return 45;
        case 2:
            return 60;
        case 3:
            return 45;
        case 4:
            return 30;
        case 5:
            return 180;
        case 6:
            return 120;
        case 7:
            return 180;
        default:
            return -99;
        }
    }

// ---- the Table 22 standstill grid ----

// the Table 22 standstill grid carries the same eight boat types.
inline int dnuT22RowCount()
    { return 8; }

// rounds to reach normal speed from a standstill: 0 small rowboat 1, 1
// coracle 1, 2 large rowboat 2, 3 small barge/raft 2, 4 large barge 5, 5
// small canoe 1, 6 large canoe 1, 7 kayak 1.
inline int dnuT22ToNormalRounds(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

// rounds to reach maximum speed from a standstill: 0 small rowboat 3, 1
// coracle 3, 2 large rowboat 5, 3 small barge/raft 6, 4 large barge 10, 5
// small canoe 2, 6 large canoe 3, 7 kayak 2.
inline int dnuT22ToMaxRounds(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 10;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 2;
        default:
            return -99;
        }
    }

// ---- the relative movement and proficiency rules ----

// boat movement is relative to the water only; the rate must be combined with
// (added to or subtracted from) the water movement to get the movement
// relative to land.
inline bool dnuMovementRelativeToWaterOnly()
    { return true; }

// a character propelling a boat at maximum speed is considered to be working
// hard for purposes of the fatigue and exhaustion rules.
inline bool dnuMaxSpeedIsHardWork()
    { return true; }

// the acceleration procedure applies in reverse to determine how long a boat
// continues coasting forward when its crew attempts to stop it.
inline bool dnuCoastingReverseOfAcceleration()
    { return true; }

// the worked example: a stream flowing 60 feet per round.
inline int dnuExampleStreamFtPerRound()
    { return 60; }

// a canoe traveling upstream at 90 feet per round in that stream.
inline int dnuExampleCanoeFtPerRound()
    { return 90; }

// the upstream canoe is actually only moving 30 feet per round past the bank
// - boat movement is relative to the water only.
inline int dnuExampleUpstreamNetFt()
    { return 30; }

// the same canoe traveling downstream streaks along at 150 feet per round
// relative to the stream's bank.
inline int dnuExampleDownstreamFt()
    { return 150; }

// the listed movement rates assume at least one character helping to propel
// the boat has boating proficiency.
inline bool dnuRatesAssumeProficientCrew()
    { return true; }

// ---- the Table 23 draught and ceilings grid ----

// the Table 23 draught and ceilings grid carries the same eight boat types.
inline int dnuT23RowCount()
    { return 8; }

// the depth of water required below the surface, pinned in inches: 0 small
// rowboat 1/2 ft = 6, 1 coracle 1/2 ft = 6, 2 large rowboat 3/4 ft = 9, 3
// small barge/raft 3/4 ft = 9, 4 large barge 1 ft = 12, 5 small canoe 1/4 ft
// = 3, 6 large canoe 1/3 ft = 4, 7 kayak 1/4 ft = 3.
inline int dnuT23DraughtInches(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 12;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// the minimum ceiling needed to pass unimpeded, pinned in half-feet: 0 small
// rowboat 2 ft = 4, 1 coracle 3 ft = 6, 2 large rowboat 3 ft = 6, 3 small
// barge/raft 3 ft = 6, 4 large barge 4 ft = 8, 5 small canoe 1 1/2 ft = 3, 6
// large canoe 2 ft = 4, 7 kayak 1 1/2 ft = 3.
inline int dnuT23CeilingHalfFeet(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 8;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// ---- the Table 24 nonproficiency grid and rules ----

// the Table 24 nonproficiency grid carries the same eight boat types.
inline int dnuT24RowCount()
    { return 8; }

// the nonproficiency movement modifier pinned as a positive magnitude with
// the minus in this name and comment, applied each round at normal or maximum
// speed: 0 small rowboat -30, 1 coracle -15, 2 large rowboat -15, 3 small
// barge/raft -10, 4 large barge -5, 5 small canoe -60, 6 large canoe -30, 7
// kayak -60.
inline int dnuT24MovePenaltyFtPerRound(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 60;
        case 6:
            return 30;
        case 7:
            return 60;
        default:
            return -99;
        }
    }

// the capsize chance percent, rolled on entering or leaving the boat and
// other risky occasions: 0 small rowboat 5%, 1 coracle 10%, 2 large rowboat
// 0, 3 small barge/raft 0, 4 large barge 0, 5 small canoe 20% (the djvu
// garble 2096 = 20%), 6 large canoe 10%, 7 kayak 25%.
inline int dnuT24CapsizePct(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 20;
        case 6:
            return 10;
        case 7:
            return 25;
        default:
            return -99;
        }
    }

// the nonproficiency movement modifier is applied to each round of operation
// at normal or maximum speed.
inline bool dnuMoveModifierEachRound()
    { return true; }

// the capsize chance is rolled each time a character enters or leaves the
// boat and on any other occasions the DM feels are risky - turning around in
// a mild current, retrieving something from the water, standing up.
inline bool dnuCapsizeOnEntryExitAndRisky()
    { return true; }

// if at least one person with boating proficiency is present in the boat, the
// capsize chance does not apply.
inline bool dnuOneProficientStopsCapsize()
    { return true; }

// if at least half of the characters paddling or rowing have boating
// proficiency, the movement penalties do not apply.
inline bool dnuHalfProficientStopsPenalty()
    { return true; }

// all of the nonproficiency penalties assume the boat moves through water of
// medium flow or slower; riding rapids or cascades is much more challenging.
inline bool dnuPenaltiesAssumeMediumOrSlower()
    { return true; }

// ---- the collision rules and the Table 25 grid ----

// a boat that carries a lantern or beacon can light the water before it
// sufficiently to avoid collisions due to darkness; if the light is snuffed
// or the progress is especially fast, the danger of smashing into a rock
// becomes very real.
inline bool dnuLanternAvoidsDarkCollisions()
    { return true; }

// obstacles can be avoided if the range of vision of the characters on board
// is greater than the distance the boat travels in one round.
inline bool dnuVisionRuleAvoidsCollisions()
    { return true; }

// infravision is sufficiently sensitive to the differences between the water
// and its bed to navigate a boat.
inline bool dnuInfravisionCanNavigate()
    { return true; }

// if vision does not extend far enough, the craft must check each round it
// travels blind, rolling d100 against the Table 25 collision percentage (the
// djvu garble 4100 = d100, settled by the Capture dlOO read).
inline bool dnuBlindTravelChecksEachRound()
    { return true; }

// the Table 25 collision probability grid carries nine cells: the three
// waterway widths against the placid, medium and rapid flow bands.
inline int dnuT25RowCount()
    { return 9; }

// the collision percent with boating proficiency (the number before the
// slash), rows 0-2 narrow / 3-5 average / 6-8 wide against placid, medium and
// rapid flow: narrow 1/5/20, average 0/2/10, wide 0/0/4.
inline int dnuT25ProfPct(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 5;
        case 2:
            return 20;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 4;
        default:
            return -99;
        }
    }

// the collision percent without boating proficiency (the number after the
// slash): narrow 10/20/40, average 5/10/20, wide 1/4/8.
inline int dnuT25NonprofPct(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 40;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 8;
        default:
            return -99;
        }
    }

// ---- the collision damage math ----

// the base chance of suffering collision damage is 5% for each
// 30-feet-per-round slice of the boat's speed.
inline int dnuDamageBasePctPerSlice()
    { return 5; }

// the speed slice of the collision damage formula: 30 feet per round.
inline int dnuDamageSpeedSliceFt()
    { return 30; }

// the worked example: a boat traveling 90 feet per round has a damage
// probability of 15%.
inline int dnuExampleDamagePct()
    { return 15; }

// when a collision is indicated, roll d100 again and compare to the damage
// probability; a result equal to or less means the boat sustains damage.
inline bool dnuDamageCheckIsD100()
    { return true; }

// the exact extent of collision damage is the difference between the die roll
// and the damage probability, expressed as a percent of the boat's hull
// strength.
inline bool dnuHullDamageIsDifference()
    { return true; }

// the worked example: a damage roll of 05 against the 15% probability is 10%
// less, so the boat's hull has suffered 10% damage - the hull damage is the
// difference between the die roll and the damage probability.
inline int dnuExampleHullDamagePct()
    { return 10; }

// ---- the Table 26 damage grid and effects ----

// the Table 26 boat damage grid carries eight percent-damage bands.
inline int dnuT26RowCount()
    { return 8; }

// the low end of the percent-damage band: 0 leaks slightly at 01, 1 small
// hole at 06, 2 many holes at 11, 3 large holes at 21, 4 hull splits at 45, 5
// breaks into 1d6 pieces at 61, 6 splinters at 81, 7 no damage at 99.
inline int dnuT26Lo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 21;
        case 4:
            return 45;
        case 5:
            return 61;
        case 6:
            return 81;
        case 7:
            return 99;
        default:
            return -99;
        }
    }

// the high end of the percent-damage band with 00 read as 100: 05, 10, 20,
// 45, 60, 80, 98, 100.
inline int dnuT26Hi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 45;
        case 4:
            return 60;
        case 5:
            return 80;
        case 6:
            return 98;
        case 7:
            return 100;
        default:
            return -99;
        }
    }

// the 01-05 band: the boat leaks slightly and will founder after 1d6 hours.
inline int dnuT26SlightLeakHoursDice()
    { return 1; }

// the sides of the 1d6-hour slight-leak roll.
inline int dnuT26SlightLeakHoursSides()
    { return 6; }

// the 06-10 band: water pours in from a small hole and the boat founders in
// 2d4 + 2 turns.
inline int dnuT26SmallHoleTurnsDice()
    { return 2; }

// the sides of the 2d4-turn small-hole roll.
inline int dnuT26SmallHoleTurnsSides()
    { return 4; }

// the +2 turns added to the small-hole 2d4 foundering roll.
inline int dnuT26SmallHoleBonusTurns()
    { return 2; }

// the 11-20 band: water pours in from 2d4 small holes and the boat founders
// in 2d4 turns - both rolls share the 2d4 shape.
inline int dnuT26ManyHolesDice()
    { return 2; }

// the sides of the 2d4 rolls for the many-holes band.
inline int dnuT26ManyHolesSides()
    { return 4; }

// the 21-45 band: large holes in the hull, the boat founders in 1d6 rounds.
inline int dnuT26LargeHoleRoundsDice()
    { return 1; }

// the sides of the 1d6-round large-hole roll.
inline int dnuT26LargeHoleRoundsSides()
    { return 6; }

// the 61-80 band: the boat breaks into 1d6 pieces.
inline int dnuT26PiecesDice()
    { return 1; }

// the sides of the 1d6-pieces roll.
inline int dnuT26PiecesSides()
    { return 6; }

// ---- the drop-off and capsize rules ----

// a boat plunging over a drop-off checks for damage just as in a collision,
// but the chance is 5% per one foot of the drop-off, not based upon the
// boat's speed.
inline int dnuDropoffDamagePctPerFoot()
    { return 5; }

// the chance of capsizing over a drop-off is also 5% per one foot of
// drop-off.
inline int dnuDropoffCapsizePctPerFoot()
    { return 5; }

// any time the drop-off damage roll is made and the result is 99 or 00, the
// boat miraculously survives the fall undamaged.
inline bool dnuDropoffMiraculousSurvival()
    { return true; }

// if a drop-off capsize is indicated but a character with boating proficiency
// is aboard, any one such character can attempt a Proficiency Check; success
// means the capsize was prevented.
inline bool dnuCapsizeProficiencyCheckPrevents()
    { return true; }

// it takes 1d4 rounds to refloat a capsized boat.
inline int dnuRefloatRoundsDice()
    { return 1; }

// the sides of the 1d4-round refloating roll, pinned as dice + sides consts
// per the R508 convention.
inline int dnuRefloatRoundsSides()
    { return 4; }

// ---- the bailing and capsizing rules ----

// characters not rowing or steering can bail water from a ruptured hull;
// bailing is strenuous exercise for the fatigue and exhaustion rules unless
// the boat is only leaking slightly.
inline bool dnuBailingStrenuousUnlessSlight()
    { return true; }

// a single character can bail enough water to cancel the effects of one small
// hole in the hull, given a suitable container and all of his time devoted to
// bailing.
inline bool dnuBailingCancelsOneSmallHole()
    { return true; }

// a capsized boat tips over and fills with water; all loose objects fall free
// and must be recovered individually.
inline bool dnuCapsizeDropsLooseObjects()
    { return true; }

// in rapidly moving water, recovery of scattered items is usually impossible.
inline bool dnuRecoveryImpossibleInRapidWater()
    { return true; }

// capsized boats do not sink, so characters unable to get their footing can
// hang onto the boat and float downstream until they can refloat it.
inline bool dnuCapsizedBoatsDoNotSink()
    { return true; }

// if the boat was damaged when it capsized, the holes must be repaired before
// refloating (see the boatwright proficiency on DSG page 25).
inline bool dnuDamageRequiresRepairBeforeRefloat()
    { return true; }

}   // namespace rules
