// =========================================================================================
// Adnd1 - rules/wsgencum.h
// The WSG ENCUMBRANCE AND MOVEMENT, R432: Table 11 (the encumbrance limits
// for characters - the 14 strength rows x the Light/Moderate/Heavy/Severe
// ranges, each category begins at the previous one over) and Table 12 (the
// character movement on foot - the encumbrance category x the
// normal/rugged/very-rugged terrain class, the normal and the accelerated
// miles per half-day) with the bulk rule-of-thumb, the terrain definitions
// and the large-scale overland movement rules - the round opens the
// encumbrance-and-movement chapter. Census 356 -> 357.
// census 356 -> 357.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed pp. 30-31;
// the user own copy OCR cross-checked against the archive djvu word layer and
// the IIIF eye-read; the disputed 18/01-50 severe cell read 1751-2500 at full
// resolution (the half-resolution vision 2250 was the artifact); every number
// matched.
//
// The Table 11 light range begins at the light-column low number; each
// heavier category begins at the previous category over; below the light low
// number the character is not encumbered, above the severe high number he
// cannot move. Table 12 reads normal/accelerated miles per half-day for a
// base 12-inch character, scaled down for slower ones.
//
namespace rules {

// ---- the encumbrance value rules ----

// The standard conversion: a weight of 10 gp is one pound.
inline int wemGpPerPound()
    { return 10; }

// The rule of thumb: a non-bulky item rates its own weight in gp (equal to,
// or only slightly greater).
inline int wemBulkNonFactor()
    { return 1; }

// A bulky object rates at least two times its weight.
inline int wemBulkyFactorMin()
    { return 2; }

// A bulky object rates two or three times its weight (the upper bound).
inline int wemBulkyFactorMax()
    { return 3; }

// A very bulky object rates at least five times its weight.
inline int wemVeryBulkyFactor()
    { return 5; }

// The bulk of an object may matter more than its weight (the 20-pound sack of
// feathers).
inline bool wemBulkMayExceedWeight()
    { return true; }

// The Dungeon Master frequently rules on the encumbrance value of objects.
inline bool wemEncValueDmRuling()
    { return true; }

// Any DM deviation must keep the movement rates and the encumbrance limits in
// proportion to one another.
inline bool wemDeviationKeepProportions()
    { return true; }

// One set of normal, light clothing adds no encumbrance.
inline bool wemOneSetClothingFree()
    { return true; }

// Heavy and bulky cold-weather outerwear is not the free set of clothing.
inline bool wemColdOuterwearCounts()
    { return true; }

// Thieves' picks and tools, or any similar small item, add no encumbrance
// when carried alone.
inline bool wemSoleSmallItemFree()
    { return true; }

// Material components for spells, when not large or bulky, add no
// encumbrance.
inline bool wemSmallComponentsFree()
    { return true; }

// A helmet (but not a great helmet) worn with armor adds no encumbrance.
inline bool wemHelmetWithArmorFree()
    { return true; }

// A great helmet is not the free helmet.
inline bool wemGreatHelmetCounts()
    { return true; }

// ---- Table 11: the encumbrance limits ----

// The Table 11 strength-row count.
inline int wemEncRowCount()
    { return 14; }

// The light-column low number by strength row (below it: not encumbered).
inline int wemEncLightMin(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 50;
        case 2:
            return 60;
        case 3:
            return 90;
        case 4:
            return 120;
        case 5:
            return 140;
        case 6:
            return 160;
        case 7:
            return 170;
        case 8:
            return 180;
        case 9:
            return 190;
        case 10:
            return 200;
        case 11:
            return 210;
        case 12:
            return 220;
        case 13:
            return 250;
        default:
            return 0;
        }
    }

// The light-column high number by strength row.
inline int wemEncLightMax(int b)
    {
        switch (b) {
        case 0:
            return 100;
        case 1:
            return 150;
        case 2:
            return 200;
        case 3:
            return 350;
        case 4:
            return 450;
        case 5:
            return 550;
        case 6:
            return 700;
        case 7:
            return 850;
        case 8:
            return 1000;
        case 9:
            return 1100;
        case 10:
            return 1200;
        case 11:
            return 1300;
        case 12:
            return 1400;
        case 13:
            return 1500;
        default:
            return 0;
        }
    }

// The moderate-column high number by strength row (the range begins at the
// light high over).
inline int wemEncModMax(int b)
    {
        switch (b) {
        case 0:
            return 350;
        case 1:
            return 450;
        case 2:
            return 550;
        case 3:
            return 700;
        case 4:
            return 800;
        case 5:
            return 900;
        case 6:
            return 1050;
        case 7:
            return 1200;
        case 8:
            return 1400;
        case 9:
            return 1450;
        case 10:
            return 1500;
        case 11:
            return 1600;
        case 12:
            return 1700;
        case 13:
            return 1900;
        default:
            return 0;
        }
    }

// The heavy-column high number by strength row.
inline int wemEncHvMax(int b)
    {
        switch (b) {
        case 0:
            return 700;
        case 1:
            return 800;
        case 2:
            return 900;
        case 3:
            return 1050;
        case 4:
            return 1150;
        case 5:
            return 1250;
        case 6:
            return 1400;
        case 7:
            return 1550;
        case 8:
            return 1700;
        case 9:
            return 1750;
        case 10:
            return 1800;
        case 11:
            return 2000;
        case 12:
            return 2200;
        case 13:
            return 2400;
        default:
            return 0;
        }
    }

// The severe-column high number by strength row (above it: cannot move).
inline int wemEncSevMax(int b)
    {
        switch (b) {
        case 0:
            return 1150;
        case 1:
            return 1250;
        case 2:
            return 1350;
        case 3:
            return 1500;
        case 4:
            return 1600;
        case 5:
            return 1700;
        case 6:
            return 1850;
        case 7:
            return 2000;
        case 8:
            return 2250;
        case 9:
            return 2500;
        case 10:
            return 2750;
        case 11:
            return 3000;
        case 12:
            return 3500;
        case 13:
            return 4500;
        default:
            return 0;
        }
    }

// The plain-strength row dispatch for Table 11: 3 -> 0, 4-5 -> 1, 6-7 -> 2,
// 8-11 -> 3, 12-13 -> 4, 14-15 -> 5, 16 -> 6, 17 -> 7, 18 -> 8; a percentile
// strength reads the percentile rows instead (wemPctRowFor plus
// wemPctRowBase).
inline int wemStrRowFor(int s)
    {
        if (s <= 3) return 0;
        if (s <= 5) return 1;
        if (s <= 7) return 2;
        if (s <= 11) return 3;
        if (s <= 13) return 4;
        if (s <= 15) return 5;
        if (s <= 16) return 6;
        if (s <= 17) return 7;
        return 8;
    }

// The percentile-row offset within Table 11: 18/01-50 -> 0, 18/51-75 -> 1,
// 18/76-90 -> 2, 18/91-99 -> 3, 18/00 (read the percentile as 100) -> 4.
inline int wemPctRowFor(int p)
    {
        if (p <= 50) return 0;
        if (p <= 75) return 1;
        if (p <= 90) return 2;
        if (p <= 99) return 3;
        return 4;
    }

// The first percentile row index in Table 11 (the 18/01-50 row).
inline int wemPctRowBase()
    { return 9; }

// Below the light-column low number the character is not encumbered.
inline bool wemBelowLightNotEncumbered()
    { return true; }

// Above the severe-column high number a character cannot move, engage in
// combat or perform any other physical activity.
inline bool wemAboveSevereCannotMove()
    { return true; }

// An overburdened character may, at the DM discretion, suffer damage.
inline bool wemAboveSevereDmDamage()
    { return true; }

// ---- the terrain definitions ----

// The terrain classes for movement rate: normal, rugged, very rugged.
inline int wemTerrainClassCount()
    { return 3; }

// A well-kept path or roadway through topographically consistent normal or
// rugged terrain counts as normal terrain.
inline bool wemConsistentPathIsNormal()
    { return true; }

// A well-kept path or roadway through very rugged terrain counts as rugged.
inline bool wemPathInVRuggedIsRugged()
    { return true; }

// Normal terrain under 5 to 10 inches of snow counts as rugged (the low
// bound).
inline int wemSnowRuggedMinIn()
    { return 5; }

// Normal terrain under 5 to 10 inches of snow counts as rugged (the high
// bound).
inline int wemSnowRuggedMaxIn()
    { return 10; }

// Normal terrain with more than 10 inches of snow counts as very rugged.
inline int wemSnowVRuggedNormalIn()
    { return 10; }

// Rugged terrain with more than 5 inches of snow counts as very rugged.
inline int wemSnowVRuggedRuggedIn()
    { return 5; }

// Streams crossed one every 3-4 hours make the terrain rugged (the low
// bound).
inline int wemRuggedStreamMinHrs()
    { return 3; }

// Streams crossed one every 3-4 hours make the terrain rugged (the high
// bound).
inline int wemRuggedStreamMaxHrs()
    { return 4; }

// Rivers or streams crossed one every 2 hours or less make the terrain very
// rugged.
inline int wemVRuggedStreamHrs()
    { return 2; }

// ---- the large-scale overland movement ----

// Large-scale movement: each 1 inch of movement rate is that many miles per
// half-day.
inline int wemMilesPerInchHalfDay()
    { return 1; }

// One half-day of movement is eight hours.
inline int wemHalfDayHours()
    { return 8; }

// A prolonged rest period is at least one hour.
inline int wemRestHoursMin()
    { return 1; }

// Past eight hours without a prolonged rest: 3/4 of the normal maximum speed
// (numerator).
inline int wemOver8hNum()
    { return 3; }

// The past-eight-hours reduction denominator.
inline int wemOver8hDen()
    { return 4; }

// Past 16 hours without stopping to eat and rest: 1/3 of the normal maximum
// rate (numerator).
inline int wemOver16hNum()
    { return 1; }

// The past-16-hours reduction denominator.
inline int wemOver16hDen()
    { return 3; }

// The large-scale scale assumes a lightly encumbered character moving over
// rugged terrain.
inline bool wemLargeScaleAssumesLightRugged()
    { return true; }

// ---- Table 12: the character movement on foot ----

// The Table 12 encumbrance-category count.
inline int wemT12RowCount()
    { return 5; }

// Table 12 assumes a base movement rate of 12 inches.
inline int wemT12BaseMove()
    { return 12; }

// The normal maximum miles per half-day, normal terrain, by encumbrance row
// (none, light, moderate, heavy, severe).
inline int wemMvNormNorm(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 12;
        case 2:
            return 10;
        case 3:
            return 7;
        case 4:
            return 5;
        default:
            return 0;
        }
    }

// The accelerated miles per half-day, normal terrain.
inline int wemMvAccelNorm(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 16;
        case 2:
            return 12;
        case 3:
            return 10;
        case 4:
            return 7;
        default:
            return 0;
        }
    }

// The normal maximum miles per half-day, rugged terrain.
inline int wemMvNormRug(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 12;
        case 2:
            return 9;
        case 3:
            return 6;
        case 4:
            return 3;
        default:
            return 0;
        }
    }

// The accelerated miles per half-day, rugged terrain.
inline int wemMvAccelRug(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 15;
        case 2:
            return 11;
        case 3:
            return 8;
        case 4:
            return 5;
        default:
            return 0;
        }
    }

// The normal maximum miles per half-day, very rugged terrain.
inline int wemMvNormVr(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 2;
        default:
            return 0;
        }
    }

// The accelerated miles per half-day, very rugged terrain.
inline int wemMvAccelVr(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 6;
        case 3:
            return 5;
        case 4:
            return 3;
        default:
            return 0;
        }
    }

// A slower base movement rate scales the Table 12 figures down accordingly.
inline bool wemT12ScaleForSlower()
    { return true; }

// The accelerated rate requires periodic rests to avoid fatigue; the rest
// stops are built into the figures.
inline bool wemAccMoveNeedsRest()
    { return true; }

}   // namespace rules
