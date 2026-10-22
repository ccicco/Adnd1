// =========================================================================================
// Adnd1 - rules/oa116table76.h
// OA TREASURE - TABLE 76, MAGICAL ARMOR PROPERTIES, printed capture pp.
// 289-290 - the property grid round
// census 667 -> 668.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 198 closed, 37 open - the Table 76 box
// flips (census 667 -> 668); NEXT - R746: Table 77: Special Properties
// (capture p. 290), prefix dlh (verify free at the landing), audit "R746 OA
// Table 77 special audit", include after rules/oa116table76.h
//
namespace rules {

// ---- the Table 76 grid ----

// the property row count - the seven d100 bands of the Table 76 property grid
// (print capture p. 289)
inline int dlgPropRowCount()
    { return 7; }

// the armor piece plus - the +1 taken by an individual armor piece in place
// of the row plus (print capture p. 290)
inline int dlgPiecePlus()
    { return 1; }

// the d100 band minimum - the low roll of the row (print capture p. 289)
inline int dlgPropRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 66;
        case 3:
            return 81;
        case 4:
            return 86;
        case 5:
            return 89;
        case 6:
            return 91;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 290)
inline int dlgPropRollMax(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 65;
        case 2:
            return 80;
        case 3:
            return 85;
        case 4:
            return 88;
        case 5:
            return 90;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// the property code - 0 the armor of quality (the 0 the no plus); 1 the +1; 2
// the +2 (the +1 if an armor piece); 3 the +3 (the +1 if an armor piece); 4
// the +4 (the +1 if an armor piece); 5 the +5 (the +1 if an armor piece); 6
// the special property, rolled again on the Table 77 (print capture p. 290)
inline int dlgPropPlus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        default:
            return 0;
        }
    }

// ---- the caption and footnote ----

// the caption quirk - the caption printing the Table 76. with a period (print
// capture p. 289)
inline int dlgCaptionPeriod()
    { return 1; }

// the quality asterisk - the armor of quality row carrying the asterisk of
// the footnote (print capture p. 289)
inline int dlgQualityAsterisk()
    { return 1; }

// the special reroll - the 91-100 band rolling again on the Table 77, its
// asterisk carried (print capture p. 290)
inline int dlgSpecialRerollTable77()
    { return 1; }

// the footnote - the armor of quality and the pieces of armor can never have
// a special property (print capture p. 290)
inline int dlgFootnoteNoSpecialProperty()
    { return 1; }

}   // namespace rules
