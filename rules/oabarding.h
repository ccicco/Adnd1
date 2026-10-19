// =========================================================================================
// Adnd1 - rules/oabarding.h
// TABLE 55 (BARDED WARHORSE BASE MOVEMENT RATES), printed capture p. 98 - the
// OA barding round
// census 568 -> 569.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the page - the
// 4-row grid cross-checked cell-by-cell between the two passes; the movement
// pairs agree in both passes - zero numeric contested cells. The artifacts
// are glyph and word class: the movement prints with the prime glyph (feet)
// in the print capture against the compressed double-prime (the R645 class,
// the feet read stands, the numeric columns strip the unit) and the
// light-horse metal-scale pair prints 15 with a stray space before the prime
// in the print pass (an OCR cell artifact, the value stands). The note under
// the table reads Tumber before the slash in BOTH passes - an OCR slip for
// The number, noted; the note doctrine pins as two bools: the number before
// the slash is for full barding, the number after for half-barding, and an X
// indicates the barding is heavier than the horse can bear. The light-horse
// chain full cell prints X and the elephant metal and chain cells print blank
// - both classes pin as -99, distinguished by the column comments; the
// elephant padded cell prints a lone 12 without the full/half slash - the T50
// lone-number lo=hi convention carries it. The warhorse names ride the column
// comments per the T48 doctrine. The barding prose box (the AC-factor and
// weight paragraph) and the misc equipment prose box stay open
//
// the gap census after this round: 97 closed, 138 open - the Table 55 box
// flips (census 568 -> 569); NEXT - R647: the Miscellaneous Equipment
// Descriptions prose box (capture p. 98), the grenades prose, prefix dhh
// (verify free), audit "R647 OA misc equipment audit", include after
// rules/oabarding.h - the barding prose box stays open beside it
//
namespace rules {

// ---- the Table 55 barding grid ----

// Table 55 (capture p. 98): four barded warhorse rows - light, medium, heavy
// and elephant
inline int dhgT55RowCount()
    { return 4; }

// the three barding materials - padded/leather, metal scale and chain
// (capture p. 98)
inline int dhgT55MatCount()
    { return 3; }

// the base movement rate in feet under full padded/leather barding, by
// warhorse row (capture p. 98). The warhorse rows ride this comment: 0 Light,
// 1 Medium, 2 Heavy, 3 Elephant - the elephant padded cell prints a lone 12
// without the full/half slash, the T50 lone-number lo=hi convention carries
// it (capture p. 98).
inline int dhgT55PaddedFull(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 17;
        case 2:
            return 15;
        case 3:
            return 12;
        default:
            return -99;
        }
    }

// the base movement rate in feet under half padded/leather barding (capture
// p. 98); the elephant cell rides the lone-print lo=hi convention.
inline int dhgT55PaddedHalf(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 18;
        case 2:
            return 15;
        case 3:
            return 12;
        default:
            return -99;
        }
    }

// the base movement rate in feet under full metal scale barding (capture p.
// 98); the elephant cell prints blank - no barding given, pin as -99.
inline int dhgT55MetalFull(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 14;
        case 3:
            return -99;
        default:
            return -99;
        }
    }

// the base movement rate in feet under half metal scale barding (capture p.
// 98); the elephant cell prints blank - pin as -99.
inline int dhgT55MetalHalf(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 17;
        case 2:
            return 15;
        case 3:
            return -99;
        default:
            return -99;
        }
    }

// the base movement rate in feet under full chain barding (capture p. 98);
// the light-horse cell prints X - the barding heavier than the horse can
// bear, pin as -99; the elephant cell prints blank - pin as -99.
inline int dhgT55ChainFull(int b)
    {
        switch (b) {
        case 0:
            return -99;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return -99;
        default:
            return -99;
        }
    }

// the base movement rate in feet under half chain barding (capture p. 98);
// the light horse carries the 15 half-barding rate beside its too-heavy X;
// the elephant cell prints blank - pin as -99.
inline int dhgT55ChainHalf(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return -99;
        default:
            return -99;
        }
    }

// the note under Table 55: the number before the slash is for full barding,
// the number after the slash for half-barding (capture p. 98)
inline bool dhgT55FullBeforeSlash()
    { return true; }

// the note under Table 55: an X indicates the barding is heavier than the
// horse can bear (capture p. 98)
inline bool dhgT55XTooHeavy()
    { return true; }

}   // namespace rules
