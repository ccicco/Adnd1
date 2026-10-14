// =========================================================================================
// Adnd1 - rules/wsganimal.h
// The WSG LAND-BASED ANIMALS, R433: Table 13 (the encumbrance limits and
// movement rates for animals - the 18 rows from the ape to the yak x the
// normal load, the maximum load and the unencumbered/encumbered movement
// rates over normal, rugged and very rugged terrain) with the two-designation
// rules (the normal load is unencumbered, the maximum load still moves), the
// forced-move stamina rules (the hours equal half the rate, capped at 12; the
// cumulative fatigue chance 20/35/50 percent by terrain; the book own light
// and medium warhorse examples) and the accelerated no-rest +1/3 spillover
// from the Table 12 section (16 + 5 = 21) - the round continues the
// encumbrance-and-movement chapter. Census 357 -> 358.
// census 357 -> 358.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 31-32;
// the user own copy OCR cross-checked against the archive djvu word layer (16
// of 18 rows) and the IIIF full-resolution eye-reads (the Sheep and Yak rows
// and the light-war very-rugged cell, absent from the djvu text layer, read
// 250/500 9/6 6/3 6/3, 2250/3500 12/6 9/6 6/3 and 6/3 at full resolution);
// every number matched. The camel footnote markers point forward to the
// Mounts and Beasts of Burden section (out of this slice).
//
// The Table 13 movement columns read unencumbered/encumbered: the left figure
// applies at the normal load or less, the right figure when encumbered (over
// the normal load up to the maximum); a 0 means the animal cannot move or be
// moved into that terrain under that encumbrance. The forced-move hours are
// the current rate over 2, up to 12; past that the fatigue chance is
// cumulative per hour.
//
namespace rules {

// ---- the two designations ----

// The Table 13 animal-row count.
inline int wamAnimalCount()
    { return 18; }

// The character encumbrance categories do not apply to mounts and pack
// animals.
inline bool wamCharCategoriesDontApply()
    { return true; }

// Only two designations matter for an animal: the normal load and the maximum
// load.
inline bool wamTwoDesignationsOnly()
    { return true; }

// The normal load is what an animal carries without being encumbered.
inline bool wamNormalLoadUnencumbered()
    { return true; }

// The maximum load is the greatest encumbrance the animal can carry and still
// be able or willing to move.
inline bool wamMaxLoadStillMoves()
    { return true; }

// An animal's large-scale rate varies with terrain, as a character's does.
inline bool wamRateVariesWithTerrain()
    { return true; }

// The rate of a mount or beast of burden also indicates its stamina.
inline bool wamRateIndicatesStamina()
    { return true; }

// ---- Table 13: the animal limits and rates ----

// The normal load in gp by animal row (unencumbered at this or less).
inline int wamNormLoad(int b)
    {
        switch (b) {
        case 0:
            return 2000;
        case 1:
            return 3000;
        case 2:
            return 4000;
        case 3:
            return 4000;
        case 4:
            return 3000;
        case 5:
            return 1500;
        case 6:
            return 5000;
        case 7:
            return 5000;
        case 8:
            return 4000;
        case 9:
            return 5000;
        case 10:
            return 3000;
        case 11:
            return 4000;
        case 12:
            return 3000;
        case 13:
            return 5000;
        case 14:
            return 2000;
        case 15:
            return 2500;
        case 16:
            return 250;
        case 17:
            return 2250;
        default:
            return 0;
        }
    }

// The maximum load in gp by animal row (the greatest load that still moves).
inline int wamMaxLoad(int b)
    {
        switch (b) {
        case 0:
            return 4000;
        case 1:
            return 6000;
        case 2:
            return 6000;
        case 3:
            return 6000;
        case 4:
            return 6000;
        case 5:
            return 2500;
        case 6:
            return 10000;
        case 7:
            return 10000;
        case 8:
            return 8000;
        case 9:
            return 7500;
        case 10:
            return 5000;
        case 11:
            return 6500;
        case 12:
            return 6000;
        case 13:
            return 7500;
        case 14:
            return 3000;
        case 15:
            return 4000;
        case 16:
            return 500;
        case 17:
            return 3500;
        default:
            return 0;
        }
    }

// The unencumbered rate, normal terrain (rows: ape, bear, bactrian,
// dromedary, dog sled, donkey, the African and Asiatic elephants, the draft,
// heavy-war, light-war, medium-war and wild horses, mule, pony, ram, sheep,
// yak).
inline int wamMvNormU(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 18;
        case 3:
            return 21;
        case 4:
            return 12;
        case 5:
            return 12;
        case 6:
            return 15;
        case 7:
            return 12;
        case 8:
            return 12;
        case 9:
            return 15;
        case 10:
            return 24;
        case 11:
            return 18;
        case 12:
            return 24;
        case 13:
            return 12;
        case 14:
            return 12;
        case 15:
            return 15;
        case 16:
            return 9;
        case 17:
            return 12;
        default:
            return 0;
        }
    }

// The encumbered rate, normal terrain.
inline int wamMvNormE(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 9;
        case 4:
            return 9;
        case 5:
            return 6;
        case 6:
            return 9;
        case 7:
            return 9;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 12;
        case 11:
            return 9;
        case 12:
            return 12;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 9;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return 0;
        }
    }

// The unencumbered rate, rugged terrain.
inline int wamMvRugU(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 12;
        case 4:
            return 6;
        case 5:
            return 9;
        case 6:
            return 9;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 12;
        case 11:
            return 9;
        case 12:
            return 12;
        case 13:
            return 9;
        case 14:
            return 6;
        case 15:
            return 12;
        case 16:
            return 6;
        case 17:
            return 9;
        default:
            return 0;
        }
    }

// The encumbered rate, rugged terrain.
inline int wamMvRugE(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 3;
        case 15:
            return 9;
        case 16:
            return 3;
        case 17:
            return 6;
        default:
            return 0;
        }
    }

// The unencumbered rate, very rugged terrain (0 = cannot move there).
inline int wamMvVrU(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 3;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        default:
            return 0;
        }
    }

// The encumbered rate, very rugged terrain (0 = cannot move there).
inline int wamMvVrE(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 0;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        default:
            return 0;
        }
    }

// The left figure of a slash pair is the rate at the normal load or less.
inline bool wamLeftIsUnencumbered()
    { return true; }

// The right figure of a slash pair is the rate when encumbered, over the
// normal load up to the maximum.
inline bool wamRightIsEncumbered()
    { return true; }

// A 0 entry means the animal cannot move or be moved into that terrain under
// that encumbrance.
inline bool wamZeroCannotMove()
    { return true; }

// The table does not include every conceivable animal; an animal friendship
// or charm spell can work wonders.
inline bool wamTableNotExhaustive()
    { return true; }

// For a new animal the DM weighs its size, strength and rate and compares it
// to a similar listed beast (the tiger vs the yak).
inline bool wamDmComparesSimilarBeast()
    { return true; }

// ---- the forced-move stamina rules ----

// An animal can be forced to move for hours equal to half its current
// movement rate (the denominator).
inline int wamForcedHoursDen()
    { return 2; }

// The forced-move window caps at 12 hours.
inline int wamForcedHoursMax()
    { return 12; }

// The fatigue chance past the forced-move window is cumulative per hour.
inline bool wamFatigueCumulative()
    { return true; }

// The cumulative fatigue chance per hour past the window, normal terrain.
inline int wamFatNormPct()
    { return 20; }

// The cumulative fatigue chance per hour, rugged terrain.
inline int wamFatRugPct()
    { return 35; }

// The cumulative fatigue chance per hour, very rugged terrain.
inline int wamFatVrPct()
    { return 50; }

// ---- the accelerated no-rest spillover ----

// Keeping the accelerated pace without the rest stops adds 1/3 of the given
// amount (numerator).
inline int wamAccelNorestNum()
    { return 1; }

// The accelerated no-rest denominator (rounded to the nearest whole).
inline int wamAccelNorestDen()
    { return 3; }

}   // namespace rules
