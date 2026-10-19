// =========================================================================================
// Adnd1 - rules/oacomprof.h
// TABLE 60 COMMON PROFICIENCIES, printed capture p. 106 - the OA common
// proficiencies round
// census 578 -> 579.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the table -
// the Table 60 grid cross-checked cell-by-cell between the two passes (the
// table printing on capture p. 106 of the print pass; compressed p. 55
// carrying the full grid). The arc's first contested numeric reads: the
// compressed pass reads the fishing base 14 against the print 17, and the
// juggling and small water craft bases 13 against the print 16 - the print
// pass is the settling authority, the three bases pin per the print (17, 16,
// 16) with the compressed deltas recorded as its OCR artifact. One
// footnote-marker read settles against the prose: the print pass drops the
// hunting a marker where the compressed carries it and the hunting prose
// mandates the die roll, so the marker pins per the compressed-plus-prose
// reading, the print drop reading as an OCR omission - the R654 precedent.
// Every other cell agrees - zero further contested reads. The grid pins as a
// table: the common rows 0 agriculture through 16 swimming riding the first
// column comment, three data columns - the proficiency slots required (animal
// handling 2, the rest 1), the base chance of success (15, 14, 16, 17, 17,
// 16, 18, 16, 14, the iaijutsu printed dash as the sentinel, 16, 17, 10, 15,
// 17, 16, 10) and the always-roll marker (1 for animal handling, gaming,
// horsemanship, hunting, juggling and swimming, 0 for the other eleven). The
// iaijutsu dash pins as the sentinel - a weapon skill listed among the common
// proficiencies but with no peaceful base chance. The asterisk
// (further-explanation) markers ride the row comments; the common prose
// explanations stay with their own rounds. The table tag T60Data
// identifier-safe per the R639 lesson
//
// the gap census after this round: 108 closed, 127 open - the Table 60 box
// flips (census 578 -> 579); NEXT - R657: Table 61 (Court Proficiencies),
// capture p. 108, prefix dhr (verify free), audit "R657 OA court
// proficiencies audit", include after rules/oacomprof.h
//
namespace rules {

// ---- the Table 60 grid pins ----

// the seventeen common proficiencies of the Table 60 grid (capture p. 106 of
// the print pass; compressed p. 55)
inline int dhqT60RowCount()
    { return 17; }

// the proficiency slots required to initially gain the proficiency (capture
// p. 106 of the print pass; compressed p. 55). The common rows ride this
// comment: 0 agriculture, 1 animal handling, 2 cooking, 3 dance, 4 fishing, 5
// gaming, 6 horsemanship, 7 hunting, 8 husbandry, 9 iaijutsu, 10 juggling, 11
// music, 12 reading/writing, 13 sailing craft, 14 singing, 15 small water
// craft, 16 swimming - the printed asterisk (further-explanation) marker
// rides here too: all but agriculture, cooking, dance, husbandry, music and
// singing carry it
inline int dhqT60Slots(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
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
            return 1;
        default:
            return -99;
        }
    }

// the base chance of success - the base number for the 1d20 roll, the
// sentinel standing in for the iaijutsu printed dash (a weapon skill with no
// peaceful base chance; capture p. 106 of the print pass; compressed p. 55)
inline int dhqT60Base(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 14;
        case 2:
            return 16;
        case 3:
            return 17;
        case 4:
            return 17;
        case 5:
            return 16;
        case 6:
            return 18;
        case 7:
            return 16;
        case 8:
            return 14;
        case 9:
            return -99;
        case 10:
            return 16;
        case 11:
            return 17;
        case 12:
            return 10;
        case 13:
            return 15;
        case 14:
            return 17;
        case 15:
            return 16;
        case 16:
            return 10;
        default:
            return -99;
        }
    }

// the always-roll marker - 1 where the printed a footnote marks a die roll
// always required to determine success, 0 otherwise (capture p. 106 of the
// print pass; compressed p. 55). The six-marked set: animal handling, gaming,
// horsemanship, hunting, juggling and swimming - the print pass drops the
// hunting marker where the compressed carries it and the hunting prose
// mandates the die roll, so the marker pins per the compressed-plus-prose
// reading
inline int dhqT60AlwaysRoll(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
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
        default:
            return -99;
        }
    }

}   // namespace rules
