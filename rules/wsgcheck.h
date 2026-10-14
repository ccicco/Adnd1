// =========================================================================================
// Adnd1 - rules/wsgcheck.h
// The WSG CLIMBING CHECKS, R436: Table 16 (the modifiers to the non-thief
// Climbing Rating - the same 13 surface rows as Table 15 x the non-slippery,
// slightly slippery and slippery adjustments, from the +70 rough gentle
// non-slippery bonus down to the -50 cliff smooth no-ledges slippery penalty)
// with the prose rules: the modifier is added to the non-thief Climbing
// Rating, a final rating of 100 percent or greater means no chance of falling
// and a final rating of 5 percent or lower is treated as 5 percent; the other
// modifiers (encumbrance: moderate -5, heavy -10, severe -20; race: dwarf -5,
// gnome -10, halfling -5, half-orc +5; armor: chain/splint/scale/banded -15,
// studded leather or padded -5, anything heavier than chain cannot climb a
// severe slope or cliff and climbs all else at -20; strength: +5 per full
// point over 15 on severe slopes or cliffs only, exceptional as 18; hands:
// both hands free on severe slopes and cliffs, one hand at -5 on a moderate
// slope, gentle slopes never need hands); the thief modifiers (a +30 or
// greater Table 16 value needs no check, the slightly slippery falling chance
// is doubled, the slippery chance quadrupled, the 5 percent floor shared);
// and the climbing checks (the 10-foot Initial Check - failure falls back to
// the start; the optional Intermediate Check past 100 feet or on smooth,
// slippery or severe surfaces, always recommended when traveling laterally,
// brief lateral stretches ignored; the always-made Final Check at the start
// of the completing round at +20 - failure falls to the bottom on a severe
// slope or cliff, and a same-round initial check stands alone with no bonus)
// - the round continues the movement-across-special-terrain section. Census
// 360 -> 361.
// census 360 -> 361.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 35; the
// user own copy OCR cross-checked against the archive djvu word layer (nine
// of thirteen rows clean; the normal moderate, normal severe and both cliff
// smooth rows are absent from the djvu text layer and the smooth gentle row
// is garbled there) and the IIIF full-resolution eye-reads (four independent
// reads of the disputed rows - every value matched the user copy exactly:
// +50/+25/+10, +30/+15/+0, -10/-25/-40, -20/-35/-50).
//
// The Table 16 numbers are percentage modifiers added to a non-thief Climbing
// Rating by the three conditions of the surface; the same 13 surface rows as
// Table 15. A final rating of 100 percent or greater means no chance of
// falling; a final rating of 5 percent or lower is treated as 5 percent. The
// Final Climbing Check is made at a +20 percent modifier.
//
namespace rules {

// ---- the Table 16 prose rules ----

// The Table 16 surface-row count - the same 13 surface rows as Table 15 (the
// nine slope rows and the four cliff rows).
inline int wckSurfaceCount()
    { return 13; }

// A final adjusted Climbing Rating of 100 percent or greater means the
// surface is negotiated with no chance of falling.
inline int wckNoFallRating()
    { return 100; }

// A final adjusted Climbing Rating of 5 percent or lower (when the character
// is not specifically prohibited from the surface) is treated as 5 percent.
inline int wckMinRatingFloor()
    { return 5; }

// The appropriate Table 16 number is added to the Climbing Rating for a
// non-thief when determining the chance of falling.
inline bool wckModifierAddedToRating()
    { return true; }

// ---- Table 16: the climbing rating modifiers ----

// The non-slippery condition modifier added to a non-thief Climbing Rating,
// by surface row (the same 13 rows as Table 15: the rough, normal and smooth
// slopes at the gentle, moderate and severe tilts, then the cliff faces by
// roughness and ledges).
inline int wckModN(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 60;
        case 2:
            return 40;
        case 3:
            return 60;
        case 4:
            return 50;
        case 5:
            return 30;
        case 6:
            return 50;
        case 7:
            return 30;
        case 8:
            return 10;
        case 9:
            return 0;
        case 10:
            return -10;
        case 11:
            return -10;
        case 12:
            return -20;
        default:
            return 0;
        }
    }

// The slightly slippery condition modifier to the non-thief Climbing Rating.
inline int wckModS(int b)
    {
        switch (b) {
        case 0:
            return 55;
        case 1:
            return 40;
        case 2:
            return 20;
        case 3:
            return 40;
        case 4:
            return 25;
        case 5:
            return 15;
        case 6:
            return 25;
        case 7:
            return 10;
        case 8:
            return 0;
        case 9:
            return -10;
        case 10:
            return -20;
        case 11:
            return -25;
        case 12:
            return -35;
        default:
            return 0;
        }
    }

// The slippery condition modifier to the non-thief Climbing Rating.
inline int wckModV(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 20;
        case 2:
            return 10;
        case 3:
            return 20;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 10;
        case 7:
            return 0;
        case 8:
            return -10;
        case 9:
            return -20;
        case 10:
            return -30;
        case 11:
            return -40;
        case 12:
            return -50;
        default:
            return 0;
        }
    }

// ---- the other modifiers for non-thieves ----

// The climbing rating encumbrance penalty for a moderate load.
inline int wckEncModeratePenalty()
    { return 5; }

// The climbing rating encumbrance penalty for a heavy load.
inline int wckEncHeavyPenalty()
    { return 10; }

// The climbing rating encumbrance penalty for a severe load.
inline int wckEncSeverePenalty()
    { return 20; }

// A light or no encumbrance applies no climbing rating penalty.
inline bool wckEncLightNoPenalty()
    { return true; }

// The dwarf climbing rating adjustment.
inline int wckDwarfPenalty()
    { return 5; }

// The gnome climbing rating adjustment.
inline int wckGnomePenalty()
    { return 10; }

// The halfling climbing rating adjustment.
inline int wckHalflingPenalty()
    { return 5; }

// The half-orc climbing rating adjustment.
inline int wckHalfOrcBonus()
    { return 5; }

// A human, elf or half-elf applies no climbing rating adjustment.
inline bool wckRaceHumanNoAdjust()
    { return true; }

// The climbing rating penalty for chain, splint, scale or banded armor.
inline int wckChainArmorPenalty()
    { return 15; }

// The climbing rating penalty for studded leather or padded armor.
inline int wckStuddedArmorPenalty()
    { return 5; }

// A character outfitted in anything heavier than chain mail climbs all
// surfaces other than severe slopes and cliffs at a 20 percent penalty.
inline int wckHeavierThanChainPenalty()
    { return 20; }

// A character outfitted in anything heavier than chain mail cannot climb any
// severe slope or cliff.
inline bool wckHeavierThanChainNoSevereCliff()
    { return true; }

// The strength climbing rating bonus per full point greater than 15, on
// severe slopes or cliffs only.
inline int wckStrengthBonus()
    { return 5; }

// The strength bonus counts full points greater than 15; an exceptional score
// counts as 18.
inline int wckStrengthBase()
    { return 15; }

// The strength bonus applies on severe slopes or cliffs only.
inline bool wckStrengthSevereCliffOnly()
    { return true; }

// An exceptional strength score counts as 18 for the climbing bonus.
inline bool wckStrengthExceptionalAs18()
    { return true; }

// A character cannot climb a severe slope or cliff while carrying a shield
// and/or a weapon at the ready - both hands must be free to grip the surface.
inline bool wckBothHandsFreeSevereCliff()
    { return true; }

// Climbing a moderate slope with one hand holding a shield or weapon applies
// a 5 percent penalty to the Climbing Rating.
inline int wckOneHandPenalty()
    { return 5; }

// One hand can hold a shield or a weapon while climbing a moderate slope, at
// the one-hand penalty.
inline bool wckOneHandModeratePenalized()
    { return true; }

// It is not necessary to use one hands when climbing a gentle slope, and a
// character with both hands full is not penalized in such a case.
inline bool wckGentleHandsFreeNotPenalized()
    { return true; }

// ---- the thief modifiers ----

// A thief traveling across terrain with a Table 16 value of +30 or greater
// needs no Climbing Check at all.
inline int wckThiefAutoThreshold()
    { return 30; }

// On a slightly slippery surface a thief chance of falling is twice as great
// as on a nonslippery surface.
inline int wckThiefFallMultSlightly()
    { return 2; }

// On a slippery surface a thief chance of falling is four times as great as
// on a nonslippery surface.
inline int wckThiefFallMultSlippery()
    { return 4; }

// A thief climb walls score can never be less than 5 percent as the result of
// the slippery modifiers.
inline int wckThiefScoreFloor()
    { return 5; }

// A thief on terrain with a Table 16 value of +30 or greater automatically
// negotiates the surface - his natural ability needs no Climbing Check.
inline bool wckThiefAutoAboveThreshold()
    { return true; }

// Below the +30 threshold a thief must make a successful Climbing Check -
// rolling his climb walls score or lower on percentile dice - to keep from
// falling.
inline bool wckThiefCheckBelowThreshold()
    { return true; }

// As with non-thieves Climbing Ratings, a thief climb walls score can never
// drop below the 5 percent floor from these modifiers - anyone who wants to
// try should be given a chance, if he feels lucky.
inline bool wckThiefScoreFloorApplies()
    { return true; }

// ---- the climbing checks ----

// A Climbing Check is required to ascend or descend a non-horizontal surface
// when the total distance to be traveled is at least 10 feet.
inline int wckCheckMinDistance()
    { return 10; }

// The Initial Climbing Check comes after traveling 10 feet from the start of
// the climb.
inline int wckInitialCheckDistance()
    { return 10; }

// A character who begins a climb must make a successful Initial Climbing
// Check after traveling 10 feet to be able to continue climbing.
inline bool wckInitialCheckRequired()
    { return true; }

// Failure on the Initial Climbing Check indicates the character has fallen
// back to the point from which the climb started.
inline bool wckInitialFailBackToStart()
    { return true; }

// An Intermediate Climbing Check may be called for when the current ascent or
// descent covers a substantial distance - more than 100 feet.
inline int wckIntermediateDistance()
    { return 100; }

// Depending on the length and difficulty of the climb, the DM may require an
// Intermediate Climbing Check at the midpoint of the current ascent or
// descent.
inline bool wckIntermediateOptional()
    { return true; }

// The Intermediate Climbing Check may be called for when the current ascent
// or descent covers more than 100 feet.
inline bool wckIntermediateOver100Feet()
    { return true; }

// The Intermediate Climbing Check may also be called for when the surface is
// smooth, slippery, severe, or a combination of those qualities.
inline bool wckIntermediateSmoothSlipperySevere()
    { return true; }

// It is recommended an intermediate check always be made when a character is
// traveling laterally and any of the above conditions apply.
inline bool wckLateralAlwaysCheck()
    { return true; }

// Brief stretches of lateral movement do not count for this determination, as
// long as the character principal direction is either up or down.
inline bool wckLateralBriefIgnored()
    { return true; }

// The Final Climbing Check is made with a +20 percent modifier to the
// Climbing Rating.
inline int wckFinalCheckBonus()
    { return 20; }

// A Final Climbing Check is always made at the beginning of the round in
// which the character will complete the climb if he does not fall.
inline bool wckFinalCheckAlways()
    { return true; }

// Failure on the Final Climbing Check indicates the character has fallen -
// and if the fall occurs while on a severe slope or a cliff, he will not stop
// until he hits bottom.
inline bool wckFinalFailFallsToBottom()
    { return true; }

// If the distance of the climb and the movement rate put the Final Climbing
// Check in the same round as the Initial Climbing Check, then the initial
// check with no bonus applied is the only one that must be made.
inline bool wckFinalSameRoundInitialOnly()
    { return true; }

}   // namespace rules
