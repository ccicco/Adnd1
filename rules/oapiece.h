// =========================================================================================
// Adnd1 - rules/oapiece.h
// TABLE 53 (INDIVIDUAL PIECE ARMOR CLASS), printed capture p. 95 - the OA
// piece armor round
// census 566 -> 567.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the page - the
// nine-row grid cross-checked cell-by-cell between the two passes; the steps
// agree (2 for do-maru, hara-ate and haramaki-do, 1 elsewhere), the star set
// agrees (the hara-ate and hara-ate-gawa pair), and the backside footnote
// text agrees verbatim - zero contested cells. The definitional sentence
// under the table pins the steps semantics: the amount of improvement from AC
// 10 the piece provides; the page worked examples cross-check the arithmetic
// (kote alone AC 9; kote, do-maru and haidate AC 6). The backside star note
// pins as a bool (the starred pieces do not cover the backside at all -
// attacks from behind are treated as against armor class 10). The piece names
// are textual and ride the column comment per the T48 doctrine (the
// hyphenated spellings as printed). The one-piece-per-area rule, the
// pieces-not-with-suits rule and the o-yoroi full-suit note stay in the open
// armor prose box; Table 54 (capture p. 95) is deliberately left for the next
// round
//
// the gap census after this round: 95 closed, 140 open - the Table 53 box
// flips (census 566 -> 567); NEXT - R645: Table 54 (Types of Armor &
// Encumbrance), capture p. 95, the armor bulk/weight/movement grid, prefix
// dhf (verify free), audit "R645 OA encumbrance audit", include after
// rules/oapiece.h
//
namespace rules {

// ---- the Table 53 piece armor grid ----

// Table 53 (capture p. 95): nine laced-armor piece rows
inline int dheT53RowCount()
    { return 9; }

// the definitional sentence under Table 53: the steps measure the amount of
// improvement from armor class 10 the piece provides (capture p. 95)
inline int dheT53AcBase()
    { return 10; }

// the armor class steps, by piece row (capture p. 95). The armor piece names
// ride this comment: 0 Do-maru, 1 Haidate, 2 Hara-ate, 3 Hara-ate-gawa, 4
// Haramaki, 5 Haramaki-do, 6 Kote, 7 Sode, 8 Suneate - the spellings as
// printed, the hara-ate pair carrying the star; a row index outside the table
// returns the -99 sentinel (capture p. 95).
inline int dheT53Steps(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        default:
            return -99;
        }
    }

// the star footnote markers: the hara-ate and hara-ate-gawa rows carry the
// star (the pieces that do not cover the backside), 0 elsewhere (capture p.
// 95).
inline int dheT53Star(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
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
        default:
            return -99;
        }
    }

// the star note under Table 53: the starred pieces do not cover the backside
// at all - attacks from behind are treated as against armor class 10 (capture
// p. 95)
inline bool dheT53StarBacksideNote()
    { return true; }

}   // namespace rules
