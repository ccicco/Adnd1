// =========================================================================================
// Adnd1 - rules/oat64speakdead.h
// TABLE 64 SPEAK WITH DEAD, printed capture p. 132 - the OA speak with dead
// round
// census 589 -> 590.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print p. 132;
// compressed pp. 64-65); the six band rows cross-checked line by line between
// the passes, zero contested reads - the one OCR variance is the compressed 2
// turn on the 13-15 questioning row against the print's 2 turns (the print
// settles). The table answers the third level speak with dead spell: the
// number of questions is dependent on level. The bands pin as a chain (the
// shukenja's level mapped to its band: 6 and below the least band, 7-8, 9-12,
// 13-15, 16-20, more than 20 the tail) and a three-column grid: the maximum
// dead time in days (the 7-day week, the 30-day month and the 365-day year
// conventions, then a decade climb per band up to the 1000-year greatest band
// pinned 365000), the questioning time in segments (one round, three rounds,
// one turn, two turns, three turns, six turns - the round = 10 and turn = 60
// conventions) and the question counts climbing one per band from two to
// seven - the band ordinal plus the dibT64QuestionsBase pin. The band names
// ride the column comments, the spell prose closes in its own round. The
// table tag T64Data identifier-safe per the R639 lesson
//
// the gap census after this round: 120 closed, 115 open - the Table 64 Speak
// with Dead box flips (census 589 -> 590); NEXT - R668: the Table 65 Fate
// (print p. 135), prefix dic (verify free), audit "R668 OA fate audit"
//
namespace rules {

// ---- the band count pins ----

// the six speak with dead level bands (print p. 132; compressed pp. 64-65)
inline int dibT64BandCount()
    { return 6; }

// the question count ladder base - each band grants its band ordinal plus two
// questions, from two in the least band to seven in the greatest (print p.
// 132; compressed pp. 64-65)
inline int dibT64QuestionsBase()
    { return 2; }

// the greatest question count - the more-than-20th level band (print p. 132;
// compressed pp. 64-65)
inline int dibT64MaxQuestions()
    { return 7; }

// the least band's maximum dead time - one week, pinned as seven days (print
// p. 132; compressed pp. 64-65)
inline int dibT64DeadWeekDays()
    { return 7; }

// the second band's maximum dead time - one month, pinned as 30 days (the
// 30-day month convention) (print p. 132; compressed pp. 64-65)
inline int dibT64DeadMonthDays()
    { return 30; }

// the third band's maximum dead time - one year, pinned as 365 days (the
// 365-day year convention) (print p. 132; compressed pp. 64-65)
inline int dibT64DeadYearDays()
    { return 365; }

// the greatest maximum dead time - the 1000 years of the more-than-20th band,
// pinned as 365000 days, the ladder climbing a decade per band from the
// one-year band (print p. 132; compressed pp. 64-65)
inline int dibT64LongestDeadDays()
    { return 365000; }

// the least band's questioning time - one round, pinned as 10 segments (print
// p. 132; compressed pp. 64-65)
inline int dibT64ShortestQuestionSegments()
    { return 10; }

// the greatest questioning time - the six turns of the more-than-20th band,
// pinned as 360 segments (the turn = 60 convention) (print p. 132; compressed
// pp. 64-65)
inline int dibT64LongestQuestionSegments()
    { return 360; }

// ---- the level band chain ----

// the shukenja's level mapped to its band (print p. 132; compressed pp.
// 64-65): level 6 and below the least band 0, 7-8 band 1, 9-12 band 2, 13-15
// band 3, 16-20 band 4, more than 20 the tail band 5
inline int dibT64LevelBand(int lvl)
    {
        if (lvl <= 6) return 0;
        if (lvl <= 8) return 1;
        if (lvl <= 12) return 2;
        if (lvl <= 15) return 3;
        if (lvl <= 20) return 4;
        return 5;
    }

// ---- the band ladder grid ----

// the maximum length of time the subject has been dead by band, pinned in
// days (print p. 132; compressed pp. 64-65). The band list rides this
// comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3 levels 13-15, 4
// levels 16-20, 5 more than 20 - the ladder: one week (7 days), one month
// (30, the 30-day month convention), one year (365, the 365-day year
// convention), then a decade climb per band - 10 years (3650), 100 years
// (36500) and 1000 years (365000)
inline int dibT64DeadDays(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 30;
        case 2:
            return 365;
        case 3:
            return 3650;
        case 4:
            return 36500;
        case 5:
            return 365000;
        default:
            return 0;
        }
    }

// the questioning time by band, pinned in segments (print p. 132; compressed
// pp. 64-65). The band list rides this comment: 0 less than 7, 1 levels 7-8,
// 2 levels 9-12, 3 levels 13-15, 4 levels 16-20, 5 more than 20 - the ladder:
// one round (10 segments, the round = 10 convention), three rounds (30), one
// turn (60), two turns (120), three turns (180) and six turns (360, the turn
// = 60 convention)
inline int dibT64QuestionSegments(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 30;
        case 2:
            return 60;
        case 3:
            return 120;
        case 4:
            return 180;
        case 5:
            return 360;
        default:
            return 0;
        }
    }

// the number of questions by band (print p. 132; compressed pp. 64-65). The
// band list rides this comment: 0 less than 7, 1 levels 7-8, 2 levels 9-12, 3
// levels 13-15, 4 levels 16-20, 5 more than 20 - the count climbs one per
// band from two in the least band to seven in the greatest - the band ordinal
// plus the dibT64QuestionsBase pin
inline int dibT64Questions(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        default:
            return 0;
        }
    }

}   // namespace rules
