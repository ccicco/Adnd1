// =========================================================================================
// Adnd1 - rules/oahurled.h
// TABLE 51 (HURLED WEAPONS AND MISSILES), printed capture pp. 80-81 - the OA
// hurled round
// census 564 -> 565.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the spread -
// the 28-row grid cross-checked cell-by-cell between the two passes; six
// cells contest in two clusters and all settle per the print capture: the
// bow-short AC-10 cell reads +3 in the print against the compressed +2 (both
// readings ladder-consistent, the settling print read stands, flagged for the
// physical-copy check) and the sling-staff-stone ladder reads -4, -4, -3, -3,
// -2, -2, -1 in the print against the compressed -6, -5, -4, -3, -2, -1, 0
// (the compressed stone-one-worse-than-bullet pattern is design-plausible,
// but the settling print read stands, flagged for the physical-copy check).
// The four note lines the print pass OCR dropped entirely were recovered from
// the compressed capture and corroborated by the UA sibling doctrine
// (rules/uamissile.h - the aklys feet note, the medium -2 and long -5): the
// star feet note (range is 10 feet, not 10 yards), the double-star
// see-description note on the needle fire rate, the short-range basis note
// and the medium/long adjust pins. T51 pins as the 28-row hurled grid: the
// eleven-column AC 0-10 to-hit adjustment ladder, the footnote letters as the
// R640 bitmask (the grenade, hankyu and metsubishi d 8, the javelin h 128),
// the star set (metsubishi and needle), -99 sentinels for the grenade and
// metsubishi dashes; the two stacked two-line cells (the blow pipe dart AC
// 0-2, the needle AC 0-4) decode cleanly in both passes; the fire rates and
// the short/medium/long range bands are textual and ride the column comments
// per the T48 doctrine. The weapon descriptions prose box stays open; Table
// 52 (capture p. 94) is deliberately left for the next round
//
// the gap census after this round: 93 closed, 142 open - the Table 51 box
// flips (census 564 -> 565); NEXT - R643: Table 52 (Armor Class Table),
// capture p. 94, the armor-class grid, prefix dhd (verify free), audit "R643
// OA armor audit", include after rules/oahurled.h
//
namespace rules {

// ---- the Table 51 hurled grid ----

// Table 51 (capture pp. 80-81): twenty-eight hurled weapon and missile rows
inline int dhcT51RowCount()
    { return 28; }

// the AC adjustment ladder - armor classes 0 through 10, eleven columns
// (capture pp. 80-81)
inline int dhcT51AcCount()
    { return 11; }

// the grid note under Table 51: adjust by -2 at all medium ranges (capture p.
// 81)
inline int dhcT51MediumAdjust()
    { return -2; }

// the grid note under Table 51: adjust by -5 at all long ranges (capture p.
// 81)
inline int dhcT51LongAdjust()
    { return -5; }

// the to-hit adjustment vs armor class 0 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99. The weapon roster with the
// fire rate and the short/medium/long range bands rides this comment: 0 Axe,
// hand (rate 1; ranges 1/2/3), 1 Blow pipe dart (rate 2; ranges 1/2/3), 2
// Bow, composite short (rate 2; ranges 5/10/18), 3 Bow, short (rate 2; ranges
// 5/10/15), 4 Chu-ko-nu (repeating crossbow) (rate 2; ranges 5/10/15), 5
// Club, thrown (rate 1; ranges 2/4/6), 6 Crossbow, heavy (rate 1/2; ranges
// 8/16/24), 7 Crossbow, light (rate 1; ranges 6/12/18), 8 Dagger, thrown
// (rate 2; ranges 1/2/3), 9 Daikyu (great bow) (rate 2; ranges 7/14/21), 10
// Dart (rate 3; ranges 1.5/3/4.5), 11 Grenade (rate 3; ranges 1/1.5/2), 12
// Hankyu (little bow) (rate 2; ranges 5/10/15), 13 Javelin (rate 1; ranges
// 2/4/6), 14 Lasso (rate 1/2; ranges 1/2/3), 15 Metsubishi (rate 1/3; ranges
// 3'/-/-), 16 Needle (rate **; ranges 1/2/1/2), 17 Pellet bow (rate 1; ranges
// 6/12/18), 18 Shaken (rate 2; ranges 1/2/3), 19 Shuriken, spike (rate 2;
// ranges 1/-/-), 20 Shuriken, star, large (rate 3; ranges 1/2/1/2), 21
// Shuriken, star, small (rate 4; ranges 1/2/1/2), 22 Sling (bullet) (rate 1;
// ranges 5/10/20), 23 Sling (stone) (rate 1; ranges 4/8/16), 24 Sling, staff
// (bullet) (rate 1/2; ranges -/3-6/9), 25 Sling, staff (stone) (rate 1/2;
// ranges -/3-6/9), 26 Spear (rate 1; ranges 1/2/3), 27 Uchi-ne (rate 2;
// ranges 1/2/3); the needle fire rate prints the double star (see weapon
// description), the metsubishi short range prints 3 feet with dashes beyond,
// the shuriken-spike and sling-staff short cells and the shuriken-spike
// medium/long cells print dashes, the sling-staff medium/long print 3-6/9
// (capture pp. 80-81).
inline int dhcT51Ac0(int b)
    {
        switch (b) {
        case 0:
            return -6;
        case 1:
            return -14;
        case 2:
            return -4;
        case 3:
            return -7;
        case 4:
            return -4;
        case 5:
            return -9;
        case 6:
            return -2;
        case 7:
            return -3;
        case 8:
            return -7;
        case 9:
            return -1;
        case 10:
            return -7;
        case 11:
            return -99;
        case 12:
            return -5;
        case 13:
            return -7;
        case 14:
            return 9;
        case 15:
            return -99;
        case 16:
            return -16;
        case 17:
            return -3;
        case 18:
            return -7;
        case 19:
            return -7;
        case 20:
            return -7;
        case 21:
            return -7;
        case 22:
            return -3;
        case 23:
            return -7;
        case 24:
            return -5;
        case 25:
            return -4;
        case 26:
            return -4;
        case 27:
            return -7;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 1 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac1(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -12;
        case 2:
            return -4;
        case 3:
            return -6;
        case 4:
            return -3;
        case 5:
            return -8;
        case 6:
            return -1;
        case 7:
            return -2;
        case 8:
            return -6;
        case 9:
            return 0;
        case 10:
            return -6;
        case 11:
            return -99;
        case 12:
            return -5;
        case 13:
            return -6;
        case 14:
            return 8;
        case 15:
            return -99;
        case 16:
            return -14;
        case 17:
            return -2;
        case 18:
            return -6;
        case 19:
            return -6;
        case 20:
            return -6;
        case 21:
            return -6;
        case 22:
            return -3;
        case 23:
            return -6;
        case 24:
            return -4;
        case 25:
            return -4;
        case 26:
            return -4;
        case 27:
            return -6;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 2 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac2(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -10;
        case 2:
            return -3;
        case 3:
            return -5;
        case 4:
            return -3;
        case 5:
            return -7;
        case 6:
            return -1;
        case 7:
            return -2;
        case 8:
            return -5;
        case 9:
            return 0;
        case 10:
            return -5;
        case 11:
            return -99;
        case 12:
            return -4;
        case 13:
            return -5;
        case 14:
            return 7;
        case 15:
            return -99;
        case 16:
            return -12;
        case 17:
            return -2;
        case 18:
            return -5;
        case 19:
            return -5;
        case 20:
            return -5;
        case 21:
            return -5;
        case 22:
            return -2;
        case 23:
            return -5;
        case 24:
            return -3;
        case 25:
            return -3;
        case 26:
            return -3;
        case 27:
            return -5;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 3 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac3(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -8;
        case 2:
            return -3;
        case 3:
            return -4;
        case 4:
            return -2;
        case 5:
            return -5;
        case 6:
            return 0;
        case 7:
            return -1;
        case 8:
            return -4;
        case 9:
            return 0;
        case 10:
            return -4;
        case 11:
            return -99;
        case 12:
            return -4;
        case 13:
            return -4;
        case 14:
            return 6;
        case 15:
            return -99;
        case 16:
            return -10;
        case 17:
            return -1;
        case 18:
            return -4;
        case 19:
            return -4;
        case 20:
            return -4;
        case 21:
            return -4;
        case 22:
            return -2;
        case 23:
            return -4;
        case 24:
            return -2;
        case 25:
            return -3;
        case 26:
            return -3;
        case 27:
            return -4;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 4 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac4(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -6;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -3;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return -3;
        case 9:
            return 0;
        case 10:
            return -3;
        case 11:
            return -99;
        case 12:
            return -2;
        case 13:
            return -3;
        case 14:
            return 5;
        case 15:
            return -99;
        case 16:
            return -10;
        case 17:
            return 0;
        case 18:
            return -3;
        case 19:
            return -3;
        case 20:
            return -3;
        case 21:
            return -3;
        case 22:
            return -1;
        case 23:
            return -2;
        case 24:
            return -1;
        case 25:
            return -2;
        case 26:
            return -2;
        case 27:
            return -3;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 5 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac5(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -4;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return -2;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return -2;
        case 9:
            return 1;
        case 10:
            return -2;
        case 11:
            return -99;
        case 12:
            return -1;
        case 13:
            return -2;
        case 14:
            return 4;
        case 15:
            return -99;
        case 16:
            return -8;
        case 17:
            return 0;
        case 18:
            return -2;
        case 19:
            return -2;
        case 20:
            return -2;
        case 21:
            return -2;
        case 22:
            return 0;
        case 23:
            return -1;
        case 24:
            return 0;
        case 25:
            return -2;
        case 26:
            return -2;
        case 27:
            return -2;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 6 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac6(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -2;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return -1;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return -1;
        case 9:
            return 2;
        case 10:
            return -1;
        case 11:
            return -99;
        case 12:
            return 0;
        case 13:
            return -1;
        case 14:
            return 3;
        case 15:
            return -99;
        case 16:
            return -6;
        case 17:
            return 1;
        case 18:
            return -1;
        case 19:
            return -1;
        case 20:
            return -1;
        case 21:
            return -1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return -1;
        case 26:
            return -1;
        case 27:
            return -1;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 7 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac7(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return -1;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return -1;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return -99;
        case 12:
            return 0;
        case 13:
            return -1;
        case 14:
            return 2;
        case 15:
            return -99;
        case 16:
            return -4;
        case 17:
            return 2;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 8 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac8(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return -1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return -1;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return -99;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return -99;
        case 16:
            return -2;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 9 (capture pp. 80-81); the grenade and
// metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac9(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return -99;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return -99;
        case 16:
            return -3;
        case 17:
            return 3;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 10 (capture pp. 80-81); the grenade
// and metsubishi rows print dashes and pin as -99.
inline int dhcT51Ac10(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return -99;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return -1;
        case 15:
            return -99;
        case 16:
            return 0;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        default:
            return -99;
        }
    }

// the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32,
// g=64, h=128 per the R640 doctrine; the grenade, hankyu and metsubishi rows
// carry d 8 and the javelin h 128, 0 elsewhere (capture pp. 80-81).
inline int dhcT51LNote(int b)
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 128;
        case 14:
            return 0;
        case 15:
            return 8;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return -99;
        }
    }

// the star footnote markers: the metsubishi and needle rows carry the star, 0
// elsewhere - the star note reads range is 10 feet, not 10 yards (capture p.
// 81).
inline int dhcT51Star(int b)
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return -99;
        }
    }

// the grid note: the armor class adjustment is based on the weapon or missile
// being discharged at short range (capture p. 81)
inline bool dhcT51AcAtShortRange()
    { return true; }

// the star note under Table 51: range is 10 feet, not 10 yards (capture p.
// 81)
inline bool dhcT51StarFeetNote()
    { return true; }

// the double-star note on the needle fire rate: see weapon description
// (capture p. 81)
inline bool dhcT51DoubleStarSeeDescription()
    { return true; }

}   // namespace rules
