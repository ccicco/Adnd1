// =========================================================================================
// Adnd1 - rules/wsgvehicle.h
// The WSG LAND-BASED VEHICLES, R434: Table 14 (the movement of vehicles - the
// 21 cart, chariot and wagon rows by the animal team x the normal and rugged
// terrain rates and the maximum load in gp; a 0 in the rugged column means
// the vehicle cannot go there) with the prose rules: the rates are miles per
// half-day, no vehicle can be taken into very rugged terrain (progress
// effectively negligible), the rates assume flat featureless ground or a path
// or roadway, and without such a path the terrain counts as one category more
// rugged for the vehicle (the lightly-forested example) - the round continues
// the encumbrance-and-movement chapter. Census 358 -> 359.
// census 358 -> 359.
//
// the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed p. 33; the
// user own copy OCR cross-checked against the archive djvu word layer (17 of
// 21 rows clean) and the IIIF full-resolution eye-reads (the chariot
// small/medium horse and the wagon rows garbled in the djvu; the eye-read
// values matched the user copy exactly); every number matched. The
// compiled-tables copy reads the cart medium/pony rugged cell as 6 - a djvu
// OCR error; the body text and the user copy both read 0.
//
// The Table 14 movement figures are miles per half-day over normal and rugged
// terrain; a 0 rugged entry means the vehicle cannot be taken onto rugged
// terrain. The maximum load is the gp encumbrance value the vehicle and team
// can haul.
//
namespace rules {

// ---- the vehicle prose rules ----

// The Table 14 vehicle-row count.
inline int wvvVehicleCount()
    { return 21; }

// The Table 14 rates are expressed in miles per half-day.
inline bool wvvRateMilesPerHalfDay()
    { return true; }

// None of the vehicles can be taken into very rugged terrain - or, if they
// are, progress is so slow as to make large-scale movement effectively
// negligible.
inline bool wvvNoVeryRugged()
    { return true; }

// The given rates assume flat, featureless ground or a path or roadway.
inline bool wvvAssumesFlatOrPath()
    { return true; }

// Without a path smooth and wide enough for the vehicle, treat the terrain as
// one category more rugged than it actually is.
inline bool wvvPathlessOneCategoryWorse()
    { return true; }

// The lightly-forested example: normal terrain for a character on foot or
// mounted, but rugged for a vehicle without a suitable path.
inline bool wvvLightForestVehicleRugged()
    { return true; }

// Carts and wagons transport equipment (and possibly characters) over long
// distances.
inline bool wvvCartsWagonsHaulGear()
    { return true; }

// Chariots are used mainly to transport characters; the larger ones can also
// haul equipment.
inline bool wvvChariotsMainlyCharacters()
    { return true; }

// The maximum load column is the gp encumbrance value the vehicle and team
// can haul.
inline bool wvvMaxLoadIsGp()
    { return true; }

// ---- Table 14: the vehicle rates and loads ----

// The cart rows begin at index 0 (small and medium carts, 8 rows).
inline int wvvCartRowBase()
    { return 0; }

// The chariot rows begin at index 8 (small and large chariots, 6 rows).
inline int wvvChariotRowBase()
    { return 8; }

// The wagon rows begin at index 14 (small and large wagons, 7 rows).
inline int wvvWagonRowBase()
    { return 14; }

// The normal-terrain rate in miles per half-day by vehicle row (the carts,
// the chariots and the wagons by their animal teams).
inline int wvvMvNorm(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 10;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 10;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 12;
        case 12:
            return 14;
        case 13:
            return 16;
        case 14:
            return 8;
        case 15:
            return 10;
        case 16:
            return 12;
        case 17:
            return 10;
        case 18:
            return 12;
        case 19:
            return 14;
        case 20:
            return 16;
        default:
            return 0;
        }
    }

// The rugged-terrain rate in miles per half-day (0 = cannot be taken onto
// rugged terrain).
inline int wvvMvRug(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 3;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 10;
        case 14:
            return 3;
        case 15:
            return 6;
        case 16:
            return 9;
        case 17:
            return 6;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 10;
        default:
            return 0;
        }
    }

// The maximum load in gp of encumbrance value.
inline int wvvMaxLoad(int b)
    {
        switch (b) {
        case 0:
            return 3500;
        case 1:
            return 5500;
        case 2:
            return 6000;
        case 3:
            return 6000;
        case 4:
            return 4000;
        case 5:
            return 6500;
        case 6:
            return 7500;
        case 7:
            return 7500;
        case 8:
            return 3000;
        case 9:
            return 4000;
        case 10:
            return 4000;
        case 11:
            return 5500;
        case 12:
            return 5500;
        case 13:
            return 5500;
        case 14:
            return 7500;
        case 15:
            return 8500;
        case 16:
            return 9000;
        case 17:
            return 12000;
        case 18:
            return 13500;
        case 19:
            return 13500;
        case 20:
            return 15000;
        default:
            return 0;
        }
    }

}   // namespace rules
