// =========================================================================================
// Adnd1 - rules/oacourtprof.h
// TABLE 61 COURT PROFICIENCIES, printed capture p. 108 - the OA court
// proficiencies round
// census 579 -> 580.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the table -
// the Table 61 grid cross-checked cell-by-cell between the two passes (the
// grid opening on capture p. 108 of the print pass with the religion and tea
// ceremony rows printing at the top of p. 109; compressed p. 56 carrying the
// full grid); every printed cell agrees, marker for marker - zero contested
// cells. The grid pins as a table: the court rows 0 calligraphy, 1 etiquette,
// 2 falconry, 3 flower arranging, 4 heraldry, 5 landscape gardening, 6 noh, 7
// origami, 8 painting, 9 poetry, 10 religion and 11 tea ceremony riding the
// first column comment, three data columns - the proficiency slots required
// (calligraphy, falconry and tea ceremony 2, the rest 1), the base chance of
// success (18, 16, 17, 15, 12, 16, 17, 14, 19, 19, 12, 15) and the
// always-roll marker (1 for etiquette, falconry and heraldry, 0 for the other
// nine). The asterisk (further-explanation) markers ride the row comments -
// calligraphy, etiquette, falconry, heraldry, noh, religion and tea ceremony
// carry it; the court prose explanations stay with their own rounds. The
// table tag T61Data identifier-safe per the R639 lesson. This round closes
// the Chapter 6 proficiencies arc - the Table 56 and Tables 58-61 grids plus
// the weapon, missile, non-weapon and character prose all landed
//
// the gap census after this round: 109 closed, 126 open - the Table 61 box
// flips (census 579 -> 580), the Chapter 6 proficiencies arc closes; NEXT -
// R658: the Chapter 7 parent opens - Table 62 (Shukenja Spells), capture p.
// 112, the full spell list by level, prefix dhs (verify free), audit "R658 OA
// shukenja spells audit", include after rules/oacourtprof.h
//
namespace rules {

// ---- the Table 61 grid pins ----

// the twelve court proficiencies of the Table 61 grid (capture p. 108 of the
// print pass; compressed p. 56)
inline int dhrT61RowCount()
    { return 12; }

// the proficiency slots required to initially gain the proficiency (capture
// p. 108 of the print pass; compressed p. 56). The court rows ride this
// comment: 0 calligraphy, 1 etiquette, 2 falconry, 3 flower arranging, 4
// heraldry, 5 landscape gardening, 6 noh, 7 origami, 8 painting, 9 poetry, 10
// religion, 11 tea ceremony - the printed asterisk (further-explanation)
// marker rides here too: calligraphy, etiquette, falconry, heraldry, noh,
// religion and tea ceremony carry it
inline int dhrT61Slots(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        default:
            return -99;
        }
    }

// the base chance of success - the base number for the 1d20 roll (capture p.
// 108 of the print pass; compressed p. 56)
inline int dhrT61Base(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 16;
        case 2:
            return 17;
        case 3:
            return 15;
        case 4:
            return 12;
        case 5:
            return 16;
        case 6:
            return 17;
        case 7:
            return 14;
        case 8:
            return 19;
        case 9:
            return 19;
        case 10:
            return 12;
        case 11:
            return 15;
        default:
            return -99;
        }
    }

// the always-roll marker - 1 where the printed a footnote marks a die roll
// always required to determine success, 0 otherwise (capture p. 108 of the
// print pass; compressed p. 56). The three-marked set: etiquette, falconry
// and heraldry
inline int dhrT61AlwaysRoll(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
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
        default:
            return -99;
        }
    }

}   // namespace rules
