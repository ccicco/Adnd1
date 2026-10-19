// =========================================================================================
// Adnd1 - rules/oahandheld.h
// TABLE 50 (HAND HELD WEAPONS, GENERAL DATA AND TO HIT ADJUSTMENTS), printed
// capture p. 80 - the OA hand-held weapons round
// census 563 -> 564.
//
// pinned from the 2018 print capture (the settling authority), with the
// cross-capture check available for the first time above p. 33: the
// compressed-print capture OCR'd full this turn gives a second independent
// read of the page - the 49-row grid cross-checked cell-by-cell between the
// two passes; four cells contest and all settle per the print capture (the
// katana AC-8, sword-short AC-8 and tui-fa AC-9 cells read +1 in the print
// against the compressed -1, a non-monotonic dip that contradicts its own
// ladder - the R622 doctrine kills the compressed class; the jo-stick AC-5
// cell reads -1 in the print against the compressed -2 - both
// ladder-consistent, the settling print read stands, the cell flags for the
// physical-copy check). T50 pins as the 49-row hand-held grid: the speed
// factor bounds (the lone numbers as lo=hi; the chijiriki-spear, spear and
// trident 6-8 and the whip 5-8 as printed ranges), the eleven-column AC 0-10
// to-hit adjustment ladder, the footnote letters as the R640 bitmask (the
// mace h 128, the tetsu-bishi d 8), and the chijiriki-chain row - its printed
// dashes pin as -99 and its (see chain) cross-reference pins as a bool; the
// length and space-required columns are textual and ride the column comments
// per the T48 doctrine. The footnote texts are not re-pinned: the block
// printed under T50 serves both tables and was pinned in R640; the d and h
// lines reprint under the T50 tail serving the two marker rows. OCR
// normalizations: the names and lengths pin as printed (the kawanga spelling
// per the R640 settle; the compressed pass's 2* tetsu-bishi length reads as
// 2'; the plus-after-prime cells print as N + and pin as printed; the
// half-foot glyph rides the comment). The weapons descriptions prose box
// stays open; Table 51 (capture pp. 80-81) is deliberately left for the next
// round
//
// the gap census after this round: 92 closed, 143 open - the Table 50 box
// flips (census 563 -> 564); NEXT - R642: Table 51 (Hurled Weapons and
// Missiles), capture pp. 80-81, the hurled-missile fire-rate and
// AC-adjustment grid, prefix dhc (verify free), audit "R642 OA hurled audit",
// include after rules/oahandheld.h
//
namespace rules {

// ---- the Table 50 hand-held grid ----

// Table 50 (capture p. 80): forty-nine hand held weapon rows
inline int dhbT50RowCount()
    { return 49; }

// the AC adjustment ladder - armor classes 0 through 10, eleven columns
// (capture p. 80)
inline int dhbT50AcCount()
    { return 11; }

// the speed factor lower bound, by weapon row - 0 Axe, battle, 1 Axe, hand, 2
// Bo stick, 3 Boku-toh, 4 Chain, 5 Chijiriki, spear, 6 Chijiriki, chain, 7
// Chopsticks, 8 Club, 9 Dagger, 10 Fang, 11 Gunsen, 12 Halberd, 13 Jitte, 14
// Jo stick, 15 Katana, 16 Kau sin ke, 17 Kawanga, 18 Kiseru, 19 Kumade, 20
// Kusari-gama, 21 Kyoketsu-shogi, 22 Lajatang, 23 Lance (light), 24 Lasso, 25
// Mace, 26 Man catcher, 27 Nagimaki, 28 Naginata, 29 Nekode, 30 Ninja-to, 31
// Nunchaku, 32 Parang, 33 Sai, 34 Sang kauw, 35 Siangkam, 36 Sode garami, 37
// Spear, 38 Sword, broad, 39 Sword, long, 40 Sword, short, 41 Sword,
// two-handed, 42 Tetsu-bishi, 43 Tetsubo, 44 Three-piece rod, 45 Trident, 46
// Tui-fa (Tonfa), 47 Wakizashi, 48 Whip; a lone number prints as lo=hi, the
// chijiriki-spear, spear and trident 6-8 and the whip 5-8 print as ranges,
// the chijiriki-chain dashes pin as -99 (capture p. 80).
inline int dhbT50SpeedLo(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return -99;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 9;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 4;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 6;
        case 21:
            return 5;
        case 22:
            return 6;
        case 23:
            return 7;
        case 24:
            return 10;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 6;
        case 28:
            return 7;
        case 29:
            return 2;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 4;
        case 33:
            return 2;
        case 34:
            return 7;
        case 35:
            return 3;
        case 36:
            return 7;
        case 37:
            return 6;
        case 38:
            return 5;
        case 39:
            return 5;
        case 40:
            return 3;
        case 41:
            return 10;
        case 42:
            return 4;
        case 43:
            return 7;
        case 44:
            return 7;
        case 45:
            return 6;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 5;
        default:
            return -99;
        }
    }

// the speed factor upper bound; the printed length and space-required cells
// ride this comment as length-by-space pairs: c. 4' by 4', c. 1.5' by 1', c.
// 5'-7' by 3', c. 3' by 3', 5'-10' by 5', c. 7'-10' by 1', the
// chijiriki-chain dashes, half-foot by half-foot, c. 3' by 1'-3', 1'-1.5' by
// 1', c. 3' by 1', 1' by 1', 5' + by 5', 1'-1.5' by 1', c. 3' by 2', c. 3' by
// 3', 4'-6' by 4', 8' + by 5', 2' by 1', 6' by 3', 2' + by 2' +, 6' + by 5',
// c. 5' by 3', 10' by 1', 10'-20' by 8' +, c. 3' by 4', 8' + by 2.5', 5'-8'
// by 1', 8' + by 1', half-foot by 1', c. 2' by 1', c. 3' by 4', c. 2' by 3',
// 1'-1.5' by 1', 3'-5' by 3', 1' by 3', 6' + by 5', 5'-10' by 1', c. 3.5' by
// 4', c. 3.5' by 3', c. 2' by 1', c. 6' by 6', 2' by 0, c. 4' by 5', c. 6' by
// 4', 4'-8' + by 1', 2' by 1', 2'-3' by 1', 8'-20' by 8'-20' - the textual
// cells pin nothing numeric, the roster order carries them (capture p. 80)
inline int dhbT50SpeedHi(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 8;
        case 6:
            return -99;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 9;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 4;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 6;
        case 21:
            return 5;
        case 22:
            return 6;
        case 23:
            return 7;
        case 24:
            return 10;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 6;
        case 28:
            return 7;
        case 29:
            return 2;
        case 30:
            return 3;
        case 31:
            return 3;
        case 32:
            return 4;
        case 33:
            return 2;
        case 34:
            return 7;
        case 35:
            return 3;
        case 36:
            return 7;
        case 37:
            return 8;
        case 38:
            return 5;
        case 39:
            return 5;
        case 40:
            return 3;
        case 41:
            return 10;
        case 42:
            return 4;
        case 43:
            return 7;
        case 44:
            return 7;
        case 45:
            return 8;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 8;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 0 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac0(int b)
    {
        switch (b) {
        case 0:
            return -5;
        case 1:
            return -5;
        case 2:
            return -13;
        case 3:
            return -7;
        case 4:
            return -8;
        case 5:
            return -2;
        case 6:
            return -99;
        case 7:
            return -16;
        case 8:
            return -7;
        case 9:
            return -4;
        case 10:
            return -5;
        case 11:
            return -14;
        case 12:
            return 0;
        case 13:
            return -4;
        case 14:
            return -10;
        case 15:
            return -5;
        case 16:
            return 3;
        case 17:
            return -8;
        case 18:
            return -7;
        case 19:
            return -6;
        case 20:
            return -3;
        case 21:
            return -8;
        case 22:
            return -3;
        case 23:
            return -3;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return -3;
        case 28:
            return -2;
        case 29:
            return -8;
        case 30:
            return -5;
        case 31:
            return -8;
        case 32:
            return -5;
        case 33:
            return -4;
        case 34:
            return -7;
        case 35:
            return -8;
        case 36:
            return -10;
        case 37:
            return -2;
        case 38:
            return -5;
        case 39:
            return -4;
        case 40:
            return -5;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 2;
        case 44:
            return -2;
        case 45:
            return -4;
        case 46:
            return -8;
        case 47:
            return -5;
        case 48:
            return -14;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 1 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac1(int b)
    {
        switch (b) {
        case 0:
            return -4;
        case 1:
            return -4;
        case 2:
            return -11;
        case 3:
            return -6;
        case 4:
            return -8;
        case 5:
            return -2;
        case 6:
            return -99;
        case 7:
            return -14;
        case 8:
            return -6;
        case 9:
            return -4;
        case 10:
            return -4;
        case 11:
            return -12;
        case 12:
            return 1;
        case 13:
            return -3;
        case 14:
            return -9;
        case 15:
            return -4;
        case 16:
            return 3;
        case 17:
            return -8;
        case 18:
            return -6;
        case 19:
            return -6;
        case 20:
            return -2;
        case 21:
            return -8;
        case 22:
            return -3;
        case 23:
            return -3;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 0;
        case 27:
            return -3;
        case 28:
            return -2;
        case 29:
            return -7;
        case 30:
            return -4;
        case 31:
            return -7;
        case 32:
            return -5;
        case 33:
            return -3;
        case 34:
            return -6;
        case 35:
            return -7;
        case 36:
            return -9;
        case 37:
            return -2;
        case 38:
            return -4;
        case 39:
            return -3;
        case 40:
            return -4;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 2;
        case 44:
            return -2;
        case 45:
            return -3;
        case 46:
            return -8;
        case 47:
            return -4;
        case 48:
            return -12;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 2 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac2(int b)
    {
        switch (b) {
        case 0:
            return -3;
        case 1:
            return -3;
        case 2:
            return -9;
        case 3:
            return -5;
        case 4:
            return -7;
        case 5:
            return -2;
        case 6:
            return -99;
        case 7:
            return -12;
        case 8:
            return -5;
        case 9:
            return -3;
        case 10:
            return -3;
        case 11:
            return -10;
        case 12:
            return 1;
        case 13:
            return -2;
        case 14:
            return -8;
        case 15:
            return -3;
        case 16:
            return 2;
        case 17:
            return -8;
        case 18:
            return -5;
        case 19:
            return -5;
        case 20:
            return -1;
        case 21:
            return -8;
        case 22:
            return -3;
        case 23:
            return -2;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return -2;
        case 28:
            return -1;
        case 29:
            return -7;
        case 30:
            return -3;
        case 31:
            return -6;
        case 32:
            return -4;
        case 33:
            return -2;
        case 34:
            return -5;
        case 35:
            return -6;
        case 36:
            return -9;
        case 37:
            return -2;
        case 38:
            return -3;
        case 39:
            return -2;
        case 40:
            return -3;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return -2;
        case 45:
            return -3;
        case 46:
            return -6;
        case 47:
            return -3;
        case 48:
            return -10;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 3 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac3(int b)
    {
        switch (b) {
        case 0:
            return -2;
        case 1:
            return -2;
        case 2:
            return -7;
        case 3:
            return -4;
        case 4:
            return -7;
        case 5:
            return -1;
        case 6:
            return -99;
        case 7:
            return -10;
        case 8:
            return -4;
        case 9:
            return -3;
        case 10:
            return -2;
        case 11:
            return -8;
        case 12:
            return 1;
        case 13:
            return -1;
        case 14:
            return -6;
        case 15:
            return -2;
        case 16:
            return 2;
        case 17:
            return -6;
        case 18:
            return -4;
        case 19:
            return -5;
        case 20:
            return -1;
        case 21:
            return -6;
        case 22:
            return -2;
        case 23:
            return -2;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return -2;
        case 28:
            return -1;
        case 29:
            return -6;
        case 30:
            return -2;
        case 31:
            return -4;
        case 32:
            return -4;
        case 33:
            return -1;
        case 34:
            return -4;
        case 35:
            return -5;
        case 36:
            return -8;
        case 37:
            return -1;
        case 38:
            return -2;
        case 39:
            return -1;
        case 40:
            return -2;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return -1;
        case 45:
            return -2;
        case 46:
            return -6;
        case 47:
            return -2;
        case 48:
            return -8;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 4 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac4(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -2;
        case 2:
            return -5;
        case 3:
            return -3;
        case 4:
            return -5;
        case 5:
            return -1;
        case 6:
            return -99;
        case 7:
            return -8;
        case 8:
            return -3;
        case 9:
            return -2;
        case 10:
            return -1;
        case 11:
            return -6;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return -4;
        case 15:
            return -1;
        case 16:
            return 1;
        case 17:
            return -6;
        case 18:
            return -3;
        case 19:
            return -3;
        case 20:
            return -1;
        case 21:
            return -6;
        case 22:
            return -2;
        case 23:
            return -1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return -1;
        case 28:
            return 0;
        case 29:
            return -5;
        case 30:
            return -1;
        case 31:
            return -2;
        case 32:
            return -3;
        case 33:
            return 0;
        case 34:
            return -3;
        case 35:
            return -4;
        case 36:
            return -6;
        case 37:
            return -1;
        case 38:
            return -1;
        case 39:
            return 0;
        case 40:
            return -1;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return -1;
        case 45:
            return -1;
        case 46:
            return -4;
        case 47:
            return -1;
        case 48:
            return -6;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 5 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac5(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -3;
        case 3:
            return -2;
        case 4:
            return -5;
        case 5:
            return -1;
        case 6:
            return -99;
        case 7:
            return -6;
        case 8:
            return -2;
        case 9:
            return -2;
        case 10:
            return 0;
        case 11:
            return -4;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return -1;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return -4;
        case 18:
            return -2;
        case 19:
            return -2;
        case 20:
            return 1;
        case 21:
            return -4;
        case 22:
            return -1;
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
        case 28:
            return 0;
        case 29:
            return -4;
        case 30:
            return 0;
        case 31:
            return -2;
        case 32:
            return -1;
        case 33:
            return 0;
        case 34:
            return -2;
        case 35:
            return -3;
        case 36:
            return -6;
        case 37:
            return -1;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 2;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return -1;
        case 46:
            return -2;
        case 47:
            return 0;
        case 48:
            return -4;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 6 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac6(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -2;
        case 5:
            return 0;
        case 6:
            return -99;
        case 7:
            return -4;
        case 8:
            return -1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return -3;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return -1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return -4;
        case 18:
            return -1;
        case 19:
            return -2;
        case 20:
            return 1;
        case 21:
            return -4;
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
        case 28:
            return 0;
        case 29:
            return -3;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return -1;
        case 35:
            return -2;
        case 36:
            return -4;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 3;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return -2;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 7 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac7(int b)
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
            return -99;
        case 7:
            return -2;
        case 8:
            return -1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return -2;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return -2;
        case 18:
            return -1;
        case 19:
            return -1;
        case 20:
            return 1;
        case 21:
            return -2;
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
        case 28:
            return 0;
        case 29:
            return -2;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return -1;
        case 36:
            return -3;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 3;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return -1;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 8 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac8(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return -99;
        case 7:
            return -1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return -1;
        case 18:
            return 0;
        case 19:
            return -1;
        case 20:
            return 0;
        case 21:
            return -1;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return -1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return -1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 0;
        case 40:
            return 1;
        case 41:
            return 3;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 1;
        case 46:
            return 0;
        case 47:
            return 1;
        case 48:
            return 1;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 9 (capture p. 80); the chijiriki-chain
// row printed dash pins as -99.
inline int dhbT50Ac9(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return -1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return -99;
        case 7:
            return -1;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return -1;
        case 12:
            return 1;
        case 13:
            return -2;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return -2;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return -1;
        case 21:
            return -2;
        case 22:
            return 1;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return -2;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 1;
        case 33:
            return -2;
        case 34:
            return 0;
        case 35:
            return -1;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 0;
        case 41:
            return 1;
        case 42:
            return 0;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 0;
        case 46:
            return 1;
        case 47:
            return 0;
        case 48:
            return 0;
        default:
            return -99;
        }
    }

// the to-hit adjustment vs armor class 10 (capture p. 80); the
// chijiriki-chain row printed dash pins as -99.
inline int dhbT50Ac10(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return -99;
        case 7:
            return -1;
        case 8:
            return 1;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return -1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 3;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return -1;
        case 26:
            return -3;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 2;
        case 31:
            return 3;
        case 32:
            return 2;
        case 33:
            return 0;
        case 34:
            return 1;
        case 35:
            return 0;
        case 36:
            return 2;
        case 37:
            return 0;
        case 38:
            return 2;
        case 39:
            return 2;
        case 40:
            return 2;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return -1;
        case 44:
            return 0;
        case 45:
            return 1;
        case 46:
            return 2;
        case 47:
            return 0;
        case 48:
            return 3;
        default:
            return -99;
        }
    }

// the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32,
// g=64, h=128 per the R640 doctrine; the mace row carries h 128 and the
// tetsu-bishi d 8, 0 elsewhere (capture p. 80).
inline int dhbT50LNote(int b)
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
            return 0;
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
            return 128;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 8;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        default:
            return -99;
        }
    }

// the chijiriki, chain row prints dashes and directs to the chain row (see
// chain) - the chain row grid data serves (capture p. 80)
inline bool dhbT50ChijirikiSeeChain()
    { return true; }

}   // namespace rules
