// =========================================================================================
// Adnd1 - rules/oaarmor.h
// TABLE 52 (ARMOR CLASS TABLE), printed capture p. 94 - the OA armor round
// census 565 -> 566.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the page - the
// eight-row table cross-checked cell-by-cell between the two passes; the
// numeric rating ladder agrees in both passes (10 through 3, one step per
// row, no contested cells). The one contest is a name, not a number: the AC-4
// row third type reads branded mail in the print pass against the compressed
// banded mail - the print capture own page prose prints banded mail twice in
// the rare-suits sentence, so the row read is an OCR slip and the name pins
// as banded mail (a read contradicting its own page does not stand). The
// type-of-armor names are textual and ride the column comment per the T48
// doctrine (the kote and o-yori spellings as printed; the suit rows enumerate
// multiple types per rating). The corselet-of-laced-armor prose example
// (armor class 7, equal to studded leather) cross-checks the row-3 rating -
// the prose itself stays in the open armor prose box. The suits-versus-pieces
// doctrine and the averaging paragraph stay open; Table 53 (capture p. 95) is
// deliberately left for the next round
//
// the gap census after this round: 94 closed, 141 open - the Table 52 box
// flips (census 565 -> 566); NEXT - R644: Table 53 (Individual Piece Armor
// Class), capture p. 95, the laced-armor piece class steps, prefix dhe
// (verify free), audit "R644 OA piece armor audit", include after
// rules/oaarmor.h
//
namespace rules {

// ---- the Table 52 armor class grid ----

// Table 52 (capture p. 94): eight suit armor rows
inline int dhdT52RowCount()
    { return 8; }

// the armor class rating, by suit row (capture p. 94). The type-of-armor
// names ride this comment: 0 None, 1 Shield/kote, 2 Leather or padded armor,
// 3 Leather, padded armor, & shield/studded leather/leather scale/ring mail,
// 4 Studded leather, ring mail, leather scale & shield/hide/metal
// scale/brigandine, 5 Hide, metal scale, brigandine & shield/chain mail, 6
// Chain mail & shield/splint mail/banded mail, 7 Splint or banded mail &
// shield/o-yori - the ratings run 10 through 3, one step per row; the row-6
// third type pins as banded mail (the print pass branded read is an OCR slip
// against its own page prose); a row index outside the table returns the -99
// sentinel (capture p. 94).
inline int dhdT52Ac(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 9;
        case 2:
            return 8;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

}   // namespace rules
