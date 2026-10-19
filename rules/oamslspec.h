// =========================================================================================
// Adnd1 - rules/oamslspec.h
// TABLE 57 MISSILE SPECIALIZATIONS, printed capture pp. 100-101 - the OA
// missile specializations round
// census 573 -> 574.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the section -
// the Table 57 grid cross-checked cell-by-cell between the two passes (the
// table opens on capture p. 100 of the print pass with the Number of Attacks
// Per Round With header and its column-name fragments, the full grid printing
// on p. 101; compressed p. 52); every printed cell agrees - zero contested
// cells. The grid pins per the T55 pair precedent: each printed num/den
// attacks pair becomes a numerator and a denominator column, the level rows 0
// the 1-6 band, 1 the 7-12 band and 2 the 13-and-up band riding the first
// column comment, and the level-band bounds pin as consts (three bands, tops
// at 6 and 12). The seven printed columns: the bow (2/1, 3/1, 4/1 up the
// bands), the light crossbow (1/1, 3/2, 2/1), the pellet bow and heavy
// crossbow (1/2, 1/1, 3/2), the lasso and staff sling (1/1, 3/2, 2/1), the
// large shuriken and thrown dagger (3/1, 4/1, 5/1), the dart and small
// shuriken (4/1, 5/1, 6/1) and the other column (3/2, 2/1, 5/2). Two
// column-name reads settle from the print pass's own p. 100 header fragments
// plus the compressed corroboration: the p. 101 header reads Bow & Heavy
// Crossbow and Shuriken, Thrown Dagger, dropping the Pellet and Large that
// the p. 100 fragments carry - the names pin as pellet bow & heavy crossbow
// and large shuriken & thrown dagger. The specialist-prose cross-references
// stay with R650; the grid completes the weapon proficiencies arc of Chapter
// 6
//
// the gap census after this round: 103 closed, 132 open - the Table 57 box
// flips (census 573 -> 574); NEXT - R652: the Non-Weapon Proficiencies prose
// with the optional peaceful proficiency bonuses, the success-and-failure
// doctrine and the contests (capture pp. 101-103), prefix dhm (verify free),
// audit "R652 OA non-weapon proficiencies audit", include after
// rules/oamslspec.h
//
namespace rules {

// ---- the Table 57 grid pins ----

// the three level bands of the specialist grid - 1 through 6, 7 through 12,
// and 13 and up (capture p. 100 of the print pass; compressed p. 52)
inline int dhlT57BandCount()
    { return 3; }

// the first level band runs 1 through 6 (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhlT57FirstBandTop()
    { return 6; }

// the second level band runs 7 through 12, the third band 13 and up (capture
// p. 100 of the print pass; compressed p. 52)
inline int dhlT57SecondBandTop()
    { return 12; }

// the bow specialist attacks-per-round numerator by level band (capture p.
// 100 of the print pass; compressed p. 52). The level rows ride this comment:
// 0 the 1-6 band, 1 the 7-12 band, 2 the 13-and-up band - the printed cell is
// the num/den attacks pair, carried per the T55 full/half pair precedent
inline int dhlT57BowNum(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        default:
            return -99;
        }
    }

// the bow specialist attacks-per-round denominator - the number after the
// slash (capture p. 100 of the print pass; compressed p. 52)
inline int dhlT57BowDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the light crossbow specialist attacks-per-round numerator (capture p. 100
// of the print pass; compressed p. 52)
inline int dhlT57LightNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the light crossbow denominator (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhlT57LightDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the pellet bow and heavy crossbow specialist attacks-per-round numerator -
// the column name settles from the print p. 100 header fragment Pellet plus
// the compressed corroboration, the print p. 101 header read dropping it
// (capture pp. 100-101 of the print pass; compressed p. 52)
inline int dhlT57PelletHeavyNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        default:
            return -99;
        }
    }

// the pellet bow and heavy crossbow denominator (capture p. 100 of the print
// pass; compressed p. 52)
inline int dhlT57PelletHeavyDen(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the lasso and staff sling specialist attacks-per-round numerator (capture
// p. 100 of the print pass; compressed p. 52)
inline int dhlT57LassoNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

// the lasso and staff sling denominator (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhlT57LassoDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the large shuriken and thrown dagger specialist attacks-per-round numerator
// - the column name settles from the print p. 100 header fragment Large plus
// the compressed corroboration (capture pp. 100-101 of the print pass;
// compressed p. 52)
inline int dhlT57ShurikenNum(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        default:
            return -99;
        }
    }

// the large shuriken and thrown dagger denominator (capture p. 100 of the
// print pass; compressed p. 52)
inline int dhlT57ShurikenDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the dart and small shuriken specialist attacks-per-round numerator (capture
// p. 100 of the print pass; compressed p. 52)
inline int dhlT57DartNum(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 6;
        default:
            return -99;
        }
    }

// the dart and small shuriken denominator (capture p. 100 of the print pass;
// compressed p. 52)
inline int dhlT57DartDen(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return -99;
        }
    }

// the other missile weapons column attacks-per-round numerator (capture p.
// 100 of the print pass; compressed p. 52)
inline int dhlT57OtherNum(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 5;
        default:
            return -99;
        }
    }

// the other column denominator (capture p. 100 of the print pass; compressed
// p. 52)
inline int dhlT57OtherDen(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return -99;
        }
    }

}   // namespace rules
