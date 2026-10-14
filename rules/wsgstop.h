// =========================================================================================
// Adnd1 - rules/wsgstop.h
// The WSG STOPPING A FALL, R439: Table 19 (the chance of stopping a fall or
// tumble - the four surface rows x the non-slippery, slightly slippery and
// slippery conditions, each entry a fraction of the Climbing Rating: gentle
// 7/8, 3/4, 2/3; moderate 3/4, 2/3, 1/2; severe 2/3, 1/2, 1/4; cliff face
// 1/2, 1/4 and the slippery dash - no chance at all) with the prose rules: a
// character can attempt to halt his descent and reduce the damage, the
// chances much greater tumbling down a gentle slope than in free fall; the DM
// either requires the attempt announced before it becomes impossible or
// allows an automatic attempt right after the fall begins (holding a sword
// and shield means no attempt unless dropped); only one attempt may be made,
// within the first 50 feet from a cliff or severe slope, 75 feet down a
// moderate slope or 100 feet down a gentle slope - past the window the
// velocity is too great; the cliff and severe attempt only succeeds if a
// protrusion exists to grab, while a moderate or gentle tumble presses arms
// and legs against the slope itself; a stopped fall still takes impact and/or
// abrasion damage for the distance fallen, but an immediate successful
// hands-free attempt can halt a moderate or gentle tumble before any damage -
// the round continues the movement-across-special-terrain section. Census 363
// -> 364.
// census 363 -> 364.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 36; the
// user own copy OCR cross-checked against the archive djvu word layer (the
// djvu table zone is heavily garbled - only the cliff slightly-slippery 1/4
// cell legible there) and the IIIF full-resolution eye-reads (two independent
// reads of the full table; every value matched the user copy exactly). The
// fraction-of-rating worked example (3/4 of 60) is written cross-multiplied,
// division-free.
//
// Each Table 19 entry is the chance of stopping a fall or tumble as a
// fraction of the Climbing Rating, by the surface fallen from and the
// condition of the surface. The cliff face slippery cell is the printed dash
// - no chance at all. Only one attempt may be made, within the 50/75/100-foot
// windows.
//
namespace rules {

// ---- the stopping prose rules ----

// The Table 19 row count (the gentle, moderate and severe slopes and the
// cliff face).
inline int wsfSurfaceCount()
    { return 4; }

// The Table 19 entries are the chance of stopping a fall or tumble, expressed
// as a fraction of the character Climbing Rating.
inline bool wsfChanceIsFractionOfRating()
    { return true; }

// The chances of success are much greater for a character tumbling down a
// gentle slope than for a character in free fall.
inline bool wsfGentleEasierThanFreeFall()
    { return true; }

// The DM can either require the player to announce the attempt before it
// becomes impossible, or simply allow any character an automatic attempt
// right after the fall begins, as long as the character is able to make it.
inline bool wsfAnnounceOrAutomatic()
    { return true; }

// Someone who begins to tumble down a gentle slope and insists on holding his
// sword and shield cannot try to stop his fall unless he drops what he is
// holding.
inline bool wsfHandsMustBeFree()
    { return true; }

// Only one attempt to stop the fall may be made.
inline bool wsfOneAttemptOnly()
    { return true; }

// The stop attempt must be made within the first 50 feet of a fall from a
// cliff face or down a severe slope.
inline int wsfAttemptCliffSevereFt()
    { return 50; }

// The stop attempt must be made within the first 75 feet of a fall down a
// moderate slope.
inline int wsfAttemptModerateFt()
    { return 75; }

// The stop attempt must be made within the first 100 feet of a fall down a
// gentle slope.
inline int wsfAttemptGentleFt()
    { return 100; }

// If the attempt is not made before the fall or tumble exceeds the indicated
// distance, it cannot be made at all - the character velocity is too great to
// make the attempt worthwhile.
inline bool wsfTooLateAfterWindow()
    { return true; }

// In a fall from a cliff or a severe slope, the attempt can only succeed if
// some protrusion exists for the character to grab onto.
inline bool wsfProtrusionRequired()
    { return true; }

// Tumbling down a moderate or gentle slope, the character can use the slope
// itself to halt his fall by pressing down against it with his arms and legs.
inline bool wsfSlopeSelfHalt()
    { return true; }

// A character who stops his fall still takes impact and/or abrasion damage
// for the distance fallen, if such damage applies.
inline bool wsfStopStillTakesDamage()
    { return true; }

// It is entirely possible to halt a tumble down a moderate or gentle slope
// before suffering any damage, if the hands are free and the attempt is made
// successfully immediately after the tumble starts.
inline bool wsfCanHaltBeforeDamage()
    { return true; }

// ---- Table 19: the stop fractions ----

// The numerator of the non-slippery stop fraction, by surface row (the
// gentle, moderate and severe slopes and the cliff face; the fraction is of
// the Climbing Rating).
inline int wsfNumN(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// The numerator of the slightly slippery stop fraction.
inline int wsfNumS(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

// The numerator of the slippery stop fraction (0 for the cliff face - the
// printed dash, no chance).
inline int wsfNumV(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The denominator of the non-slippery stop fraction.
inline int wsfDenN(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// The denominator of the slightly slippery stop fraction.
inline int wsfDenS(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 4;
        default:
            return 0;
        }
    }

// The denominator of the slippery stop fraction (0 for the cliff face - the
// printed dash, no chance).
inline int wsfDenV(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
