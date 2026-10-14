// =========================================================================================
// Adnd1 - rules/wsggrap.h
// The WSG USE OF GRAPPLING HOOKS, R444: the hook prose and Table 20 - the
// other piece of equipment any climber can use (thief or non-thief,
// mountaineer or not) is a grappling hook, a three- or four-pronged metal
// hook attached to the end of a rope and thrown toward a protrusion in hopes
// it catches and holds. Hooks are normally needed only for severe slopes and
// cliff faces but expedite a moderate slope, especially a slippery one. A
// character throws a hook upward a maximum of 1/3 of his strength score
// (rounded up) times 10 feet - strength 8 reaches 30 feet above the head. A
// horizontal throw (a 30-degree-or-less incline) matches the vertical
// distance unless the thrower is in a secure position with a 10-foot whirling
// radius, in which case he throws twice as far. A throw takes one round; a
// miss costs the next 1d4 rounds coiling the rope. A missed throw at a target
// directly above with a roll of 01-05 hits the thrower for 1d6 damage.
// Climbing an anchored rope gives a 3-foot bonus to the climbing movement
// rate if lightly or not encumbered, otherwise no movement benefit. Table 20
// pairs the Chance of Protrusion (a percentile roll at or above the first
// number means a protrusion exists; at or above the second it is solid and
// holds indefinitely; between the two it gives way after 1d6 rounds of
// climbing) with the condition catch chances (a second percentile roll at or
// above the number means the throw succeeded); with no protrusion in range,
// recheck after traveling 10 feet vertically or horizontally. Census 368 ->
// 369.
// census 368 -> 369.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 38; the
// user own copy OCR cross-checked against the archive djvu word layer
// (Guide_0038.djvu) with IIIF eye-reads - the djvu is garbled at the last
// Table 20 row (it reads 60/90 m 96 99), at the strength fraction and at the
// climb bonus; two independent eye-reads of each zone matched the user copy
// exactly: the last row is 80/90 with 92/99/99, the throw is 1/3 of strength
// rounded up times 10 feet, and the bonus is a 3-FOOT bonus (the OCR inch
// mark resolved to the printed foot mark, no plus sign). Every other cell and
// number matched the djvu clean.
//
// The hook throw: 1/3 of strength (rounded up) times 10 feet, one round per
// attempt, 1d4 rounds to re-coil a miss, 01-05 on a missed throw directly
// above hits the thrower for 1d6. The Table 20 last row (cliff, smooth, no
// ledges): protrusion 80/90, catching at 92/99/99 - and a not-solid
// protrusion gives way after 1d6 rounds of climbing.
//
namespace rules {

// ---- the grappling-hook prose rules ----

// The grappling hook can be used by any climber - thief or non-thief,
// mountaineer or non-mountaineer.
inline bool wghAnyClimberCanUse()
    { return true; }

// A grappling hook is a three- or four-pronged metal hook attached to the end
// of a rope and thrown toward a protrusion, in hopes that it catches and
// holds.
inline bool wghThreeOrFourProngs()
    { return true; }

// Hooks are normally only needed for severe slopes and cliff faces, but
// expedite movement up a moderate slope, especially a slippery or slightly
// slippery one.
inline bool wghNeededSevereHandyModerate()
    { return true; }

// The maximum upward throw is 1/3 of the character strength score, rounded
// up, times 10 feet.
inline int wghStrengthDivisor()
    { return 3; }

// The rounded-up third of the strength score is multiplied by 10 feet - the
// example strength of 8 throws 30 feet.
inline int wghFeetPerStrengthUnit()
    { return 10; }

// A character with a strength of 8 can throw the hook toward a protrusion as
// far as 30 feet above his head.
inline int wghStr8ThrowFt()
    { return 30; }

// A throw on an incline of 30 degrees or less is horizontal.
inline int wghHorizontalInclineDeg()
    { return 30; }

// A horizontal throw (an incline of 30 degrees or less) has the same maximum
// distance as a vertical toss, unless the thrower is secure with room to
// whirl.
inline bool wghHorizontalSameAsVertical()
    { return true; }

// A secure thrower needs a 10-foot radius of space around himself to whirl
// the hook in a circle before letting it go.
inline int wghSecureWhirlRadiusFt()
    { return 10; }

// From a secure position, the horizontal throw goes twice as far as the
// maximum vertical throw.
inline int wghSecureHorizontalMult()
    { return 2; }

// In a secure position with a 10-foot whirling radius, the horizontal throw
// goes twice as far as the maximum vertical throw.
inline bool wghSecurePositionDoubles()
    { return true; }

// It takes one round to make a throwing attempt with a grappling hook,
// regardless of the type of throw.
inline int wghThrowRounds()
    { return 1; }

// If the hook misses, the character must spend the next 1d4 rounds coiling
// the rope, whether for another attempt or to stow the equipment.
inline int wghRecoilRoundsDice()
    { return 4; }

// It can be dangerous to throw a hook toward a target directly above oneself
// - a missed throw rolling 01-05 hits the thrower for 1d6 damage.
inline bool wghAboveSelfDangerous()
    { return true; }

// Throwing at a target directly above oneself: if the throw misses and the
// die roll was 01-05, the thrower is hit by the hook.
inline int wghSelfHitRollMax()
    { return 5; }

// The thrower hit by his own hook takes 1d6 points of damage.
inline int wghSelfHitDamageDice()
    { return 6; }

// A climber can climb up a rope anchored by a grappling hook at a 3-foot
// bonus to his normal climbing movement rate if lightly encumbered or not
// encumbered.
inline int wghClimbBonusFt()
    { return 3; }

// The 3-foot climb bonus on an anchored rope applies only if the climber is
// lightly encumbered or not encumbered.
inline bool wghClimbBonusLightOnly()
    { return true; }

// In other cases the rope affords no benefit to movement - except, perhaps,
// to make upward movement possible where it was not possible before.
inline bool wghNoMovementBenefitOtherwise()
    { return true; }

// ---- the Table 20 grapple success grid ----

// Table 20 has ten terrain rows: the three moderate slopes, the three severe
// slopes and the four cliff types.
inline int wghTerrainCount()
    { return 10; }

// The first Chance of Protrusion number, by terrain row: a percentile roll at
// or above it means a protrusion exists within throwing range.
inline int wghProtrusionFirst(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 50;
        case 2:
            return 70;
        case 3:
            return 30;
        case 4:
            return 50;
        case 5:
            return 70;
        case 6:
            return 20;
        case 7:
            return 40;
        case 8:
            return 60;
        case 9:
            return 80;
        default:
            return 0;
        }
    }

// The second Chance of Protrusion number: a roll at or above it means the
// protrusion is solid and the hook holds indefinitely; between the two
// numbers it is not solid and gives way after 1d6 rounds of climbing.
inline int wghProtrusionSecond(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 70;
        case 2:
            return 85;
        case 3:
            return 40;
        case 4:
            return 60;
        case 5:
            return 80;
        case 6:
            return 40;
        case 7:
            return 60;
        case 8:
            return 80;
        case 9:
            return 90;
        default:
            return 0;
        }
    }

// The chance of catching the thrown hook on a protrusion on a non-slippery
// surface (a second percentile roll at or above the number succeeds).
inline int wghCatchNonSlippery(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 60;
        case 2:
            return 64;
        case 3:
            return 68;
        case 4:
            return 72;
        case 5:
            return 76;
        case 6:
            return 80;
        case 7:
            return 84;
        case 8:
            return 88;
        case 9:
            return 92;
        default:
            return 0;
        }
    }

// The catch chance on a slightly slippery surface.
inline int wghCatchSlightlySlippery(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 72;
        case 2:
            return 76;
        case 3:
            return 80;
        case 4:
            return 84;
        case 5:
            return 88;
        case 6:
            return 92;
        case 7:
            return 96;
        case 8:
            return 98;
        case 9:
            return 99;
        default:
            return 0;
        }
    }

// The catch chance on a slippery surface.
inline int wghCatchSlippery(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 84;
        case 2:
            return 86;
        case 3:
            return 88;
        case 4:
            return 90;
        case 5:
            return 92;
        case 6:
            return 94;
        case 7:
            return 96;
        case 8:
            return 98;
        case 9:
            return 99;
        default:
            return 0;
        }
    }

// A protrusion roll at or above the second Chance of Protrusion number is
// solid: if the character snags it, the hook will hold indefinitely.
inline bool wghSolidHoldsIndefinitely()
    { return true; }

// A protrusion roll at or above the first number but less than the second is
// not solid: if snagged, the hook gives way after 1d6 rounds spent climbing
// up the rope.
inline bool wghNotSolidGivesWay()
    { return true; }

// A protrusion between the two Chance of Protrusion numbers is not solid: if
// snagged, the hook gives way after 1d6 rounds are spent climbing up the
// rope.
inline int wghNonSolidGiveWayDice()
    { return 6; }

// The Condition of Terrain numbers are the chance of catching a thrown hook
// on a protrusion, assuming one exists: a second percentile roll at or above
// the number means the throw was successful.
inline bool wghSecondRollCatches()
    { return true; }

// With no protrusion within throwing range, a character can check for
// protrusions again after traveling 10 feet vertically or horizontally.
inline bool wghRecheckAfter10Ft()
    { return true; }

// If no protrusion exists within throwing range, a character can check for
// protrusions again after traveling a distance of 10 feet vertically or
// horizontally.
inline int wghRecheckDistanceFt()
    { return 10; }

}   // namespace rules
