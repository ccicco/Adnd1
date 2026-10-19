// =========================================================================================
// Adnd1 - rules/oaencumb.h
// TABLE 54 (TYPES OF ARMOR & ENCUMBRANCE), printed capture p. 95 - the OA
// armor encumbrance round
// census 567 -> 568.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the page - the
// 23-row grid cross-checked cell-by-cell between the two passes; the base
// weights and the base movement rates agree in both passes - zero numeric
// contested cells. The contests are textual: the bulk classes read
// non/fairly/bulky in the print against the compressed non-/fairly/bulky (the
// trailing hyphen a cell-edge artifact, the print read stands); the kote
// weight cell reads blank in the print against the compressed dash - both
// read no base weight given, the -99 sentinel carries it; the movement glyph
// reads prime (feet) in the print against the compressed double-prime (the
// feet read stands, the numeric column strips the unit). The banded and chain
// plus-after-pound marks print as 35# + and 30# + (the R640 plus-after-prime
// class, riding the comments). The armor type names and the bulk classes are
// textual and ride the column comments per the T48 doctrine; the movement
// dash cells (the buckler, haidate, kote, the two shields, the sode pair and
// the sune-ate) pin as -99. The armor descriptions prose box stays open;
// Table 55 (capture p. 98) is deliberately left for the next round
//
// the gap census after this round: 96 closed, 139 open - the Table 54 box
// flips (census 567 -> 568); NEXT - R646: Table 55 (Barded Warhorse Base
// Movement Rates), capture p. 98, the barding movement grid, prefix dhg
// (verify free), audit "R646 OA barding audit", include after
// rules/oaencumb.h - the misc equipment and barding prose boxes stay open
//
namespace rules {

// ---- the Table 54 armor encumbrance grid ----

// Table 54 (capture p. 95): twenty-three armor type rows
inline int dhfT54RowCount()
    { return 23; }

// the base weight in pounds, by armor type row (capture p. 95). The armor
// type names with the bulk classes ride this comment: 0 Banded (bulky; 35#
// +), 1 Buckler (non; 3#), 2 Chain (fairly; 30# +), 3 Do-maru (fairly; 20#),
// 4 Haidate (fairly; 10#), 5 Hara-ate (non; 10#), 6 Hara-ate-gawa (non; 10#),
// 7 Haramaki (non; 15#), 8 Haramaki-do (fairly; 20#), 9 Hide (fairly; 25#),
// 10 Kote (non; no weight printed), 11 Leather (non; 15#), 12 O-yori (great
// armor) (bulky; 40#), 13 Padded (fairly; 10#), 14 Ring (fairly; 25#), 15
// Scale, leather (fairly; 20#), 16 Scale, metal (fairly; 40#), 17 Shield,
// large (bulky; 10#), 18 Shield, medium (fairly; 5#), 19 Sode, pair (non;
// 3#), 20 Splinted (bulky; 40#), 21 Studded (fairly; 20#), 22 Sune-ate (non;
// 5#) - the bulk classes print non/fairly/bulky (the compressed pass
// trailing-hyphen artifact settled per the print); the banded and chain
// plus-after-pound marks as the R640 plus class; the kote weight cell prints
// blank against the compressed dash - both read no base weight, the -99
// sentinel carries it (capture p. 95).
inline int dhfT54Weight(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 3;
        case 2:
            return 30;
        case 3:
            return 20;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 20;
        case 9:
            return 25;
        case 10:
            return -99;
        case 11:
            return 15;
        case 12:
            return 40;
        case 13:
            return 10;
        case 14:
            return 25;
        case 15:
            return 20;
        case 16:
            return 40;
        case 17:
            return 10;
        case 18:
            return 5;
        case 19:
            return 3;
        case 20:
            return 40;
        case 21:
            return 20;
        case 22:
            return 5;
        default:
            return -99;
        }
    }

// the base movement in feet, by armor type row (capture p. 95); the dash
// cells (the buckler, haidate, kote, the large and medium shields, the sode
// pair and the sune-ate) pin as -99 - the pieces and shields give no base
// movement; the movement prints with the prime glyph in the print capture
// against the compressed double-prime - the feet read stands (capture p. 95).
inline int dhfT54Move(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return -99;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return -99;
        case 5:
            return 9;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return 9;
        case 9:
            return 9;
        case 10:
            return -99;
        case 11:
            return 12;
        case 12:
            return 6;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 9;
        case 16:
            return 6;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return 6;
        case 21:
            return 9;
        case 22:
            return -99;
        default:
            return -99;
        }
    }

}   // namespace rules
