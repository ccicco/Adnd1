// =========================================================================================
// Adnd1 - rules/wsgclimb.h
// The WSG CLIMBING, R435: Table 15 (the climbing movement rates - the 13
// surface rows x the non-slippery, slightly slippery and slippery
// feet-per-round rates for a thief, with the asterisked cells climbable only
// by a thief or a mountaineering-proficient character using special tools)
// with the prose rules: all characters can climb, the non-thief moves at half
// rate, the dexterity Reaction/Attacking Adjustment applies, no special tools
// are assumed and the cracks and protuberances are assumed except on the
// gentle nonslippery slope, the encumbrance modifications (severe: the gentle
// nonslippery or slightly slippery slope at half; heavy or moderate: the
// gentle or moderate nonslippery or slightly slippery slope at half; light:
// any slope at full; the cliff face needs an unencumbered climber), the
// surface types (the gentle, moderate and severe degree bands and elevation
// changes, the cliff past 70 degrees, the overhang treated the same) and the
// chance of falling (100 minus the Climbing Rating; the non-thief 40 percent,
// the mountaineer with tools 80 percent on the restricted surfaces; the
// percentile roll at or under the rating succeeds) - the round opens the
// movement-across-special-terrain section. Census 359 -> 360.
// census 359 -> 360.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 33-34;
// the user own copy OCR cross-checked against the archive djvu word layer
// (every rate cell clean except the cliff smooth with-ledges row, where the
// djvu reads 16* for the non-slippery cell) and the IIIF full-resolution
// eye-reads (two eye-reads settle 15* - the 16* is an OCR artifact); every
// number matched.
//
// The Table 15 movement figures are feet per round for a thief; every other
// character moves at half the indicated rate. The three rate columns are the
// non-slippery, slightly slippery and slippery conditions of the surface; the
// three flag columns carry the asterisk restriction. The chance of falling is
// 100 minus the Climbing Rating.
//
namespace rules {

// ---- the climbing prose rules ----

// The Table 15 surface-row count (the nine slope rows and the four cliff
// rows).
inline int wcsSurfaceCount()
    { return 13; }

// The Table 15 rates are expressed in feet per round for a thief.
inline bool wcsRateFeetPerRound()
    { return true; }

// All characters, not just thieves, have a chance to ascend, descend or move
// laterally across most non-horizontal natural surfaces.
inline bool wcsAllCharactersCanClimb()
    { return true; }

// Every character other than a thief moves at one-half the indicated rate.
inline bool wcsNonThievesHalfRate()
    { return true; }

// A character with exceptionally low or high dexterity applies his
// Reaction/Attacking Adjustment as a penalty or bonus to the climbing
// movement rate.
inline bool wcsDexAdjustmentApplies()
    { return true; }

// In all cases the climber is assumed to use no special tools other than a
// rope, which is of limited use for direct climbing unless used with other
// mountaineering equipment.
inline bool wcsNoSpecialToolsAssumed()
    { return true; }

// The surface is assumed to contain cracks or protuberances used as handholds
// and footholds.
inline bool wcsHandholdsAssumed()
    { return true; }

// On a gentle, nonslippery surface such aids are not necessary and do not
// have to be used even if present.
inline bool wcsGentleNonslipAidsOptional()
    { return true; }

// Thieves are the only characters who can negotiate a surface completely
// devoid of handholds and footholds.
inline bool wcsThievesOnlyDevoidSurfaces()
    { return true; }

// The asterisked Table 15 cells can be climbed only by a thief, or by a
// character with mountaineering proficiency who is using special tools.
inline bool wcsRestrictedThiefOrMountaineer()
    { return true; }

// ---- the encumbrance modifications ----

// A severely encumbered character can climb only a gentle nonslippery or
// slightly slippery slope, at one-half his normal climbing rate.
inline bool wcsSevereEncGentleOnlyHalf()
    { return true; }

// A heavily or moderately encumbered character can climb only a gentle or
// moderate nonslippery or slightly slippery slope, at one-half his normal
// climbing rate.
inline bool wcsHeavyModerateEncGentleModerateHalf()
    { return true; }

// A lightly encumbered character can climb any slope (but not a cliff face)
// at his full normal climbing rate.
inline bool wcsLightEncAnySlopeFull()
    { return true; }

// To climb a cliff face a thief or mountaineering-proficient character must
// be not encumbered - the gear carried must total less than the lower figure
// given for light encumbrance on the Encumbrance Limits for Characters Table.
inline bool wcsCliffRequiresUnencumbered()
    { return true; }

// ---- Table 15: the climbing rates and restrictions ----

// The slope rows begin at index 0 (the rough, normal and smooth surfaces at
// gentle, moderate and severe tilts).
inline int wcsSlopeRowBase()
    { return 0; }

// The cliff rows begin at index 9 (rough and smooth, each with and without
// ledges).
inline int wcsCliffRowBase()
    { return 9; }

// The non-slippery condition rate in feet per round for a thief by surface
// row (the rough, normal and smooth slopes at the gentle, moderate and severe
// tilts, then the cliff faces by roughness and ledges).
inline int wcsRateN(int b)
    {
        switch (b) {
        case 0:
            return 90;
        case 1:
            return 80;
        case 2:
            return 60;
        case 3:
            return 80;
        case 4:
            return 60;
        case 5:
            return 50;
        case 6:
            return 60;
        case 7:
            return 40;
        case 8:
            return 20;
        case 9:
            return 25;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 10;
        default:
            return 0;
        }
    }

// The slightly slippery condition rate in feet per round for a thief (0 = the
// same restricted meaning as the flags).
inline int wcsRateS(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 50;
        case 2:
            return 40;
        case 3:
            return 45;
        case 4:
            return 30;
        case 5:
            return 20;
        case 6:
            return 30;
        case 7:
            return 20;
        case 8:
            return 10;
        case 9:
            return 15;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 5;
        default:
            return 0;
        }
    }

// The slippery condition rate in feet per round for a thief.
inline int wcsRateV(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 25;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 15;
        case 5:
            return 5;
        case 6:
            return 15;
        case 7:
            return 10;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 5;
        default:
            return 0;
        }
    }

// The restricted flag for the non-slippery cell (1 = the asterisked cell: a
// thief or a mountaineering-proficient character with special tools only).
inline int wcsResN(int b)
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
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The restricted flag for the slightly slippery cell.
inline int wcsResS(int b)
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
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The restricted flag for the slippery cell.
inline int wcsResV(int b)
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
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// ---- the surface types ----

// A gentle slope tilts at least 15 degrees.
inline int wcsGentleMinDeg()
    { return 15; }

// A gentle slope tilts at most 30 degrees.
inline int wcsGentleMaxDeg()
    { return 30; }

// The least extreme gentle slope rises 2 feet per 10 feet of horizontal
// distance.
inline int wcsGentleRiseMin()
    { return 2; }

// The most extreme gentle slope rises 5 feet per 10 feet of horizontal
// distance.
inline int wcsGentleRiseMax()
    { return 5; }

// A moderate slope tilts from 31 degrees.
inline int wcsModerateMinDeg()
    { return 31; }

// A moderate slope tilts through 50 degrees.
inline int wcsModerateMaxDeg()
    { return 50; }

// The most extreme moderate slope rises 12 feet per 10 feet of horizontal
// distance.
inline int wcsModerateRiseMax()
    { return 12; }

// A severe slope tilts from 51 degrees.
inline int wcsSevereMinDeg()
    { return 51; }

// A severe slope tilts through 70 degrees.
inline int wcsSevereMaxDeg()
    { return 70; }

// The most extreme severe slope rises 35 feet per 10 feet of horizontal
// distance.
inline int wcsSevereRiseMax()
    { return 35; }

// A cliff is any slope past 70 degrees.
inline int wcsCliffMinDeg()
    { return 71; }

// The elevation changes are measured per 10 feet of horizontal distance on a
// line cutting through the slope.
inline int wcsHorizontalDist()
    { return 10; }

// A tilt of less than 15 degrees is not a slope at all for these rules, and
// is moved across at the same speed as flat terrain.
inline bool wcsUnderFifteenNotSlope()
    { return true; }

// A cliff rising past 90 degrees is properly called an overhang, but it is
// not treated any differently.
inline bool wcsOverhangSameRules()
    { return true; }

// ---- the chance of falling ----

// The non-thief without mountaineering proficiency has a Climbing Rating of
// 40 percent.
inline int wcsNonThiefRating()
    { return 40; }

// The non-thief with mountaineering proficiency has a Climbing Rating of 80
// percent when using his tools on a restricted surface.
inline int wcsMountaineerRating()
    { return 80; }

// The chance of falling while climbing is 100 minus the Climbing Rating.
inline int wcsFallBase()
    { return 100; }

// The chance of falling while climbing is a percentage equal to 100 minus the
// Climbing Rating.
inline bool wcsFallIs100MinusRating()
    { return true; }

// A thief Climbing Rating is the same as his climb walls score.
inline bool wcsThiefRatingIsClimbWalls()
    { return true; }

// The mountaineering 80 percent rating applies only when the tools are being
// used on a surface that only he (or a thief) is capable of climbing.
inline bool wcsMountaineer80RestrictedOnly()
    { return true; }

// For each Climbing Check a percentile roll greater than the Climbing Rating
// fails, and a roll equal to or less than the Climbing Rating succeeds.
inline bool wcsCheckRollUnderOrEqual()
    { return true; }

}   // namespace rules
