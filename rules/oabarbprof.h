// =========================================================================================
// Adnd1 - rules/oabarbprof.h
// TABLE 59 BARBARIAN PROFICIENCIES, printed capture p. 104 - the OA barbarian
// proficiencies round
// census 577 -> 578.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the table -
// the Table 59 grid cross-checked cell-by-cell between the two passes (the
// table opening at the bottom of capture p. 104 of the print pass with the
// eight grid rows printing at the top of p. 105; compressed p. 53 carrying
// the full grid); every printed cell agrees - zero contested cells, marker
// for marker. The print pass read here comes from the recovered capture
// session: the original print OCR session was lost to an extraction failure
// at the R655 open, the re-uploaded scan extracted at 315 pages with its
// pagination aligned to the book (its p. 101 cross-checked verbatim against
// the prior session read, its p. 103 corroborating the R654 marker reads).
// The grid pins as a table: the barbarian rows 0 chanting, 1 fire building, 2
// running, 3 signaling, 4 snare building, 5 sound imitation, 6 survival and 7
// tracking riding the first column comment, three data columns - the
// proficiency slots required (1, 1, 1, 1, 1, 2, 2, 3), the base chance of
// success (15, 8, 16, 12, 14, 16, 15, 17) and the always-roll marker (1 for
// fire building, running, signaling, snare building, sound imitation and
// tracking, 0 for chanting and survival). The asterisk (further-explanation)
// markers ride the row comments - all but chanting carry it; the barbarian
// prose explanations (the fire-building 30 minutes, the running doctrine, the
// tracking terrain modifiers) stay with their own rounds. The table tag
// T59Data identifier-safe per the R639 lesson
//
// the gap census after this round: 107 closed, 128 open - the Table 59 box
// flips (census 577 -> 578); NEXT - R656: Table 60 (Common Proficiencies),
// capture p. 106, prefix dhq (verify free), audit "R656 OA common
// proficiencies audit", include after rules/oabarbprof.h
//
namespace rules {

// ---- the Table 59 grid pins ----

// the eight barbarian proficiencies of the Table 59 grid (capture p. 104 of
// the print pass; compressed p. 53)
inline int dhpT59RowCount()
    { return 8; }

// the proficiency slots required to initially gain the proficiency (capture
// p. 104 of the print pass; compressed p. 53). The barbarian rows ride this
// comment: 0 chanting, 1 fire building, 2 running, 3 signaling, 4 snare
// building, 5 sound imitation, 6 survival, 7 tracking - the printed asterisk
// (further-explanation) marker rides here too: all but chanting carry it
inline int dhpT59Slots(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 3;
        default:
            return -99;
        }
    }

// the base chance of success - the base number for the 1d20 roll (capture p.
// 104 of the print pass; compressed p. 53)
inline int dhpT59Base(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 8;
        case 2:
            return 16;
        case 3:
            return 12;
        case 4:
            return 14;
        case 5:
            return 16;
        case 6:
            return 15;
        case 7:
            return 17;
        default:
            return -99;
        }
    }

// the always-roll marker - 1 where the printed a footnote marks a die roll
// always required to determine success, 0 otherwise (capture p. 104 of the
// print pass; compressed p. 53). The six-marked set: fire building, running,
// signaling, snare building, sound imitation and tracking - chanting and
// survival carry no marker in either pass
inline int dhpT59AlwaysRoll(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 1;
        default:
            return -99;
        }
    }

}   // namespace rules
