// =========================================================================================
// Adnd1 - rules/oaartprof.h
// TABLE 58 ARTISAN PROFICIENCIES, printed capture p. 103 - the OA artisan
// proficiencies round
// census 576 -> 577.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the table -
// the Table 58 grid cross-checked cell-by-cell between the two passes (the
// table printing on capture p. 103 of the print pass; compressed p. 53);
// every numeric cell agrees - zero contested numbers. The grid pins as a
// table: the artisan rows 0 armorer, 1 blacksmith, 2 bowyer, 3 brewer, 4
// carpenter, 5 civil engineer, 6 herbalist, 7 jeweler, 8 masseur, 9
// navigator, 10 paper-maker, 11 potter, 12 seamstress/tailor, 13 silk maker,
// 14 stonemason, 15 tanner/leatherworker, 16 weaponsmith and 17 weaver riding
// the first column comment, three data columns - the proficiency slots
// required (2, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1), the base
// chance of success (16, 14, 15, 16, 15, 18, 17, 16, 14, 12, 18, 16, 17, 19,
// 16, 15, 17, 15) and the always-roll marker (1 for armorer, bowyer,
// herbalist, navigator and weaponsmith, 0 for the other thirteen). Two
// footnote-marker reads settle against the prose: the print pass drops the
// weaponsmith a marker where the compressed carries it and the weaponsmith
// prose mandates the end-of-construction die roll, and the print pass drops
// the bowyer asterisk where the compressed carries it and the bowyer
// explanation section exists - both markers pin per the compressed-plus-prose
// reading, the print drops reading as an OCR omission. The asterisk
// (further-explanation) markers ride the row comments, not the grid; the
// artisan prose explanations stay with their own rounds. The table tag
// T58Data identifier-safe per the R639 lesson
//
// the gap census after this round: 106 closed, 129 open - the Table 58 box
// flips (census 576 -> 577); NEXT - R655: Table 59 (Barbarian Proficiencies),
// capture p. 104, prefix dhp (verify free), audit "R655 OA barbarian
// proficiencies audit", include after rules/oaartprof.h
//
namespace rules {

// ---- the Table 58 grid pins ----

// the eighteen artisan proficiencies of the Table 58 grid (capture p. 103 of
// the print pass; compressed p. 53)
inline int dhoT58RowCount()
    { return 18; }

// the proficiency slots required to initially gain the proficiency (capture
// p. 103 of the print pass; compressed p. 53). The artisan rows ride this
// comment: 0 armorer, 1 blacksmith, 2 bowyer, 3 brewer, 4 carpenter, 5 civil
// engineer, 6 herbalist, 7 jeweler, 8 masseur, 9 navigator, 10 paper-maker,
// 11 potter, 12 seamstress/tailor, 13 silk maker, 14 stonemason, 15
// tanner/leatherworker, 16 weaponsmith, 17 weaver
inline int dhoT58Slots(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 3;
        case 17:
            return 1;
        default:
            return -99;
        }
    }

// the base chance of success - the base number for the 1d20 roll (capture p.
// 103 of the print pass; compressed p. 53)
inline int dhoT58Base(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 14;
        case 2:
            return 15;
        case 3:
            return 16;
        case 4:
            return 15;
        case 5:
            return 18;
        case 6:
            return 17;
        case 7:
            return 16;
        case 8:
            return 14;
        case 9:
            return 12;
        case 10:
            return 18;
        case 11:
            return 16;
        case 12:
            return 17;
        case 13:
            return 19;
        case 14:
            return 16;
        case 15:
            return 15;
        case 16:
            return 17;
        case 17:
            return 15;
        default:
            return -99;
        }
    }

// the always-roll marker - 1 where the printed a footnote marks a die roll
// always required to determine success, 0 otherwise (capture p. 103 of the
// print pass; compressed p. 53). The four-marked set: armorer, bowyer,
// herbalist, navigator and weaponsmith - the print pass drops the weaponsmith
// a marker, the compressed carries it and the weaponsmith prose mandates the
// roll, so the marker pins per the compressed-plus-prose reading
inline int dhoT58AlwaysRoll(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
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
            return 1;
        case 17:
            return 0;
        default:
            return -99;
        }
    }

}   // namespace rules
