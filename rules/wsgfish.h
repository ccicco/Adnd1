// =========================================================================================
// Adnd1 - rules/wsgfish.h
// R465: the WSG HUNTING PROFICIENCY AND FISHING slice - the hunting
// proficiency (the one-hit size M kill, the two-hit size L kill, the 50%
// distance kill of a wounded size M with a single attempt, the single-hit
// wounded size L with multiple attempts, the successful Proficiency Check
// before the 1d6 roll, the missile-weapon requirement, no boost to the
// encounter chance or the prey size, the repeatable expeditions), fishing
// (the one-hour baited hook-and-line base, the net +50%, the zero-or-lower
// no-fish gate, the proficiency +2 in fair or good spots only, the cumulative
// -1 per extra group member, the cumulative -2 per hour beyond the first in
// the same spot, the fished-out rule, the spot-quality guidelines) and Table
// 32 (the spot-by-time dice grid), printed p. 57 with the spot-guideline tail
// on p. 58.
// census 389 -> 390.
//
// Ground truth three-way: the archive djvu word layer vs the pixel reads of
// the native decode of the printed p. 57 image (a pure-Python JPEG decoder,
// 1179x1516) vs vision reads of contrast-stretched cell crops. The text layer
// drops the Fair-Day cell and garbles four Good cells; the pixels settled
// them: Fair-Day 1d6-2 (glyph holes=1, the canonical 6 template at 0.947),
// Good-Day 1d8-2 (the digit shows the stacked-loop waist of an 8, template
// 0.775 vs 0.738 for the 6), Good-Night 1d6+2 (proven by the book own A/B/C
// example: 1d6+4 for the proficient A = 1d6+2 + 2), Good-Dawn 1d8+2 (the same
// 8 waist; the plus vertical stroke survives as faint 158-238 grayscale
// traces through the bar while the true minus on the same page shows pure
// background around its bar). The Fair and Good row labels are
// pixel-and-vision confirmed. The p. 58 tail completes the p. 57 sentence:
// fish congregate where they can be shaded by trees or overhanging terrain;
// such a spot is fair or good while an unshaded spot nearby on the same body
// of water is a poor one.
//
// All 18 Table 32 cells pinned (the die and the modifier per row per time
// band); the hunting proficiency and fishing mechanics are audit examples,
// including the book own A/B/C three-fisherman hour-by-hour example.
//
namespace rules {

// ---- The hunting proficiency ----

// hits to kill with hunting proficiency by size band: one for size S, one for
// size M (instead of two), two for size L (instead of four)
inline int wfsProfHitsToKill(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 2;
        }
    }

// a proficient hunter has a 50% chance of killing a wounded size M creature
// from a distance instead of closing with it
inline int wfsProfWoundedMDistancePct()
    { return 50; }

// only one distance-kill attempt on a wounded size M creature; if it fails,
// the creature has escaped
inline bool wfsProfWoundedMOneAttempt()
    { return true; }

// a proficient hunter kills a wounded size L creature with a single hit
// instead of the two or three a group might need
inline int wfsProfWoundedLHits()
    { return 1; }

// multiple attempts are permitted on a wounded size L creature if it is not
// dispatched on the first attempt
inline bool wfsProfWoundedLMultipleAttempts()
    { return true; }

// the hunting proficiency feats require a successful Proficiency Check when
// game is encountered, before the 1d6 size-and-number roll
inline bool wfsProfCheckBeforeRoll()
    { return true; }

// the proficiency feats require a missile weapon of the appropriate sort
inline bool wfsProfNeedsMissile()
    { return true; }

// a proficient hunter does not increase the chance of encountering game, nor
// affect the size of the prey encountered
inline bool wfsProfNoEncounterBoost()
    { return true; }

// hunting expeditions may be undertaken as often as desired - animals are not
// rooted, and the same area can be searched again
inline bool wfsProfRepeatable()
    { return true; }

// ---- Table 32: the fishing success grid ----

// the Table 32 row count: the poor, fair and good spot-quality rows
inline int wfsRowCount()
    { return 3; }

// the Table 32 daytime die
inline int wfsDayDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 0;
        }
    }

// the Table 32 daytime modifier
inline int wfsDayMod(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -2;
        default:
            return 0;
        }
    }

// the Table 32 night die
inline int wfsNightDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 6;
        default:
            return 0;
        }
    }

// the Table 32 night modifier
inline int wfsNightMod(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// the Table 32 dawn/dusk die
inline int wfsDawnDie(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        default:
            return 0;
        }
    }

// the Table 32 dawn/dusk modifier
inline int wfsDawnMod(int b)
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

// ---- The fishing rules ----

// a net increases the take to 50% more than the modified die roll
inline int wfsNetBonusPct()
    { return 50; }

// a die-roll result of zero or lower catches no fish regardless of the gear
// used
inline bool wfsZeroNoFish()
    { return true; }

// a character with fishing proficiency gets a +2 modifier in any fair or good
// area
inline int wfsProfBonus()
    { return 2; }

// the fishing proficiency bonus applies only in fair or good areas - prowess
// does not help in a poor spot
inline bool wfsProfBonusFairGoodOnly()
    { return true; }

// each extra member of the fishing group takes a cumulative -1: -1 for the
// second character, -2 for the third, and so on
inline int wfsGroupPenalty()
    { return 1; }

// each hour beyond the first spent in the same spot takes a further
// cumulative -2 per hour
inline int wfsSpotHourPenalty()
    { return 2; }

// a spot is fished out as soon as every fisherman gets a result of zero or
// lower in the same hour
inline bool wfsFishedOutAllZero()
    { return true; }

// a fished-out spot will not yield any more fish for at least one day
inline int wfsFishedOutDays()
    { return 1; }

// fishing from a boat moored in the middle of a body of water is better than
// fishing from shore
inline bool wfsBoatBetterThanShore()
    { return true; }

// in hot or sunny weather fish congregate where they can be shaded by trees
// or overhanging terrain, or in rain; such a spot is fair or good
inline bool wfsShadedSpotFairGood()
    { return true; }

// an unshaded spot nearby on the same body of water will be a poor one
inline bool wfsUnshadedSpotPoor()
    { return true; }

// a swamp or bog is generally a poor place for fishing
inline bool wfsSwampBogPoor()
    { return true; }

// a stagnant, shallow creek is a poor place for fishing
inline bool wfsStagnantCreekPoor()
    { return true; }

}   // namespace rules
