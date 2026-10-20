// =========================================================================================
// Adnd1 - rules/oat65fate.h
// TABLE 65 FATE, printed capture p. 135 - the OA fate round
// census 590 -> 591.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print p. 135;
// compressed p. 66); the twelve band rows cross-checked line by line between
// the passes, zero contested reads - the outcome prose agrees verbatim. The
// table answers the fourth level fate spell, rolled when the DM knows of no
// particular event that will occur to the character. The outcomes are
// DM-adventure seeds - general statements whose value is narrative, so the
// cells pin the band STRUCTURE, not the prose: the bands pin as a chain (the
// 1d20 roll mapped to its band: rolls 1, 2, 3 the single-face bands, 4-5,
// 6-7, 8-9 and 16-17 the two-face pairs, 10-12 and 13-15 the three-face
// widest bands at the ladder middle, 18, 19 and 20 the single-face tail) and
// a one-column grid of the band face widths - six single-face, four two-face
// and two three-face bands summing to the twenty faces of the die. The
// one-fate-at-a-time rule pins as the didT65FateLimit const. The outcome
// names ride the column comment, the fate prose closes in its own round. The
// table tag T65Data identifier-safe per the R639 lesson
//
// the gap census after this round: 121 closed, 114 open - the Table 65 Fate
// box flips (census 590 -> 591); the shukenja chapter boxes are ALL CLOSED -
// NEXT - R669: the wu jen spell chapter opens, Table 66 Wu Jen Spells
// (capture p. 153, the full spell list by level), prefix did (verified free -
// dic is NOT free: the dice() helpers), audit "R669 OA wu jen spell list
// audit"
//
namespace rules {

// ---- the band count pins ----

// the twelve fate bands (print p. 135; compressed p. 66)
inline int didT65BandCount()
    { return 12; }

// the fate roll is 1d20, the table consulted when the DM knows of no
// particular event that will occur to the character (print p. 135; compressed
// p. 66)
inline int didT65DieFaces()
    { return 20; }

// the six single-face bands - rolls 1, 2, 3, 18, 19 and 20 (print p. 135;
// compressed p. 66)
inline int didT65SingleFaceBands()
    { return 6; }

// the four two-face bands - rolls 4-5, 6-7, 8-9 and 16-17 (print p. 135;
// compressed p. 66)
inline int didT65TwoFaceBands()
    { return 4; }

// the face width of the two widest bands - rolls 10-12 and 13-15, three faces
// each (print p. 135; compressed p. 66)
inline int didT65WidestBands()
    { return 3; }

// a character can only have one fate at a time - once determined, the nature
// of the event cannot be changed (print p. 135; compressed p. 66)
inline int didT65FateLimit()
    { return 1; }

// ---- the fate band chain ----

// the 1d20 fate roll mapped to its band (print p. 135; compressed p. 66): 1
// band 0, 2 band 1, 3 band 2, 4-5 band 3, 6-7 band 4, 8-9 band 5, 10-12 band
// 6, 13-15 band 7, 16-17 band 8, 18 band 9, 19 band 10, 20 band 11
inline int didT65FateBand(int d)
    {
        if (d <= 1) return 0;
        if (d <= 2) return 1;
        if (d <= 3) return 2;
        if (d <= 5) return 3;
        if (d <= 7) return 4;
        if (d <= 9) return 5;
        if (d <= 12) return 6;
        if (d <= 15) return 7;
        if (d <= 17) return 8;
        if (d <= 18) return 9;
        if (d <= 19) return 10;
        return 11;
    }

// ---- the band width grid ----

// the fate band face widths by ordinal (print p. 135; compressed p. 66). The
// band list rides this comment: 0 roll 1, 1 roll 2, 2 roll 3, 3 rolls 4-5, 4
// rolls 6-7, 5 rolls 8-9, 6 rolls 10-12, 7 rolls 13-15, 8 rolls 16-17, 9 roll
// 18, 10 roll 19, 11 roll 20 - the widths sum to the twenty faces of the die:
// six single-face bands at the ladder ends (rolls 1, 2, 3, 18, 19, 20), four
// two-face bands (rolls 4-5, 6-7, 8-9, 16-17) and the two three-face widest
// bands at the ladder middle (rolls 10-12 and 13-15). The outcomes themselves
// are prose - the DM-adventure seeds riding the printed table, not pinned
// cells
inline int didT65Faces(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
