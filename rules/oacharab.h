// =========================================================================================
// Adnd1 - rules/oacharab.h
// THE CHARACTER ABILITIES, printed capture pp. 55-59 - the OA chapter opener
// round
// census 550 -> 551.
//
// verified against capture pp. 55-59 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). No contested cells this
// round - both captures agree on every pinned value. The T36 class column
// pins as the 1-6 code (bushi, kensai, ninja, barbarian, samurai, sohei); the
// printed "and up" bands pin as the -1 code; the attack rates pin as the
// numerator and denominator of the printed N/D notation. OCR normalization:
// "lying and yang" reads as yin and yang (prose only); "human (or human)"
// reads as the printed text (prose only); the ninja asterisk footnote appears
// twice in the second capture (the printed footnote stands)
//
// the gap census after this round: 64 closed, 171 open - the Character
// Abilities, Multi-Class and Dual-Class, Alignment, Languages and Table 36
// boxes flip (census 550 -> 551); NEXT - R629: the Chapter 3 opener, the
// birth rank prose and the caste doctrine, capture pp. 60-62, Table 37 (Birth
// Requirements by Class) and Table 38 (Character Birth), prefix dgp (verify
// free), audit "R629 OA families audit", include after rules/oacharab.h
//
namespace rules {

// ---- the multiple attacks pins ----

// Table 36 (capture p. 55): nineteen level-band rows
inline int dgoT36RowCount()
    { return 19; }

// Multiple attacks prose (capture p. 55): the ability extends beyond fighters
// and fighter sub-classes
inline bool dgoT36ExtendsBeyondFighters()
    { return true; }

// Table 36 footnote (capture p. 55): ninja multiple attacks only with ninja
// weapons
inline bool dgoT36NinjaNinjaWeaponsOnly()
    { return true; }

// Table 36 footnote (capture p. 55): the other class attack rate never
// applies to ninja weapons
inline bool dgoT36NinjaOtherClassNoCarry()
    { return true; }

// Multiple attacks prose (capture p. 55): the rates apply only to melee
// weapons, never missile
inline bool dgoT36MeleeOnly()
    { return true; }

// Multiple attacks prose (capture p. 55): proficiencies increase attacks with
// both melee and missile weapons
inline bool dgoT36ProficiencyIncreases()
    { return true; }

// Multiple attacks prose (capture p. 55): versus monsters under 1 hit die,
// one melee attack per level
inline bool dgoT36OnePerLevelVsWeak()
    { return true; }

// Multiple attacks prose (capture p. 55): multiple attacks divide between
// targets as the player sees fit
inline bool dgoT36SplitBetweenTargets()
    { return true; }

// ---- the dual-class pins ----

// Dual-class prose (capture p. 56): 15 or more in the prime requisites of the
// original class
inline int dgoDualOldClassReqMin()
    { return 15; }

// Dual-class prose (capture p. 56): 17 or 18 in the prime requisites of the
// new class
inline int dgoDualNewClassReqMin()
    { return 17; }

// Dual-class prose (capture p. 56): no non-human character can have more than
// one class
inline bool dgoDualHumanOnly()
    { return true; }

// Dual-class prose (capture p. 56): a character can become dual-class at any
// level
inline bool dgoDualAnyLevel()
    { return true; }

// Dual-class prose (capture p. 56): the old-class abilities are never lost
inline bool dgoDualKeepsOldAbilities()
    { return true; }

// Dual-class prose (capture p. 56): considered a 1st-level character in the
// new class
inline bool dgoDualNewClassFirstLevel()
    { return true; }

// Dual-class prose (capture p. 56): all later experience applies to the new
// class
inline bool dgoDualXpToNewClass()
    { return true; }

// Dual-class prose (capture p. 56): the old profession can never be advanced
// again
inline bool dgoDualNeverAdvanceOld()
    { return true; }

// Dual-class prose (capture p. 56): no new hit points until the old-class
// level is surpassed
inline bool dgoDualNoHpUntilSurpass()
    { return true; }

// Dual-class prose (capture p. 56): the new-class restrictions bind until the
// old level is surpassed
inline bool dgoDualRestrictionsUntilSurpass()
    { return true; }

// Dual-class prose (capture p. 56): using an old-class ability forfeits the
// adventure experience
inline bool dgoDualOldUseForfeitsXp()
    { return true; }

// Dual-class prose (capture p. 56): always the most advantageous combat and
// saving throw tables
inline bool dgoDualBestTables()
    { return true; }

// Dual-class prose (capture p. 56): the two classes mix freely after
// surpassing the old level
inline bool dgoDualFreeMixAfterSurpass()
    { return true; }

// Dual-class prose (capture p. 56): any weapon of either class without
// restriction
inline bool dgoDualWeaponsException()
    { return true; }

// ---- the alignment pins ----

// Alignment prose (capture p. 56): nine different alignments
inline int dgoAlignCount()
    { return 9; }

// Alignment prose (capture p. 56): alignment is not religion; differing
// alignments share one religion
inline bool dgoAlignNotReligion()
    { return true; }

// Alignment prose (capture p. 57): law is by far the most common alignment in
// Kara-Tur
inline bool dgoAlignLawMostCommon()
    { return true; }

// Alignment prose (capture p. 58): players encouraged to select complementary
// alignments
inline bool dgoAlignEncourageComplement()
    { return true; }

// ---- the language pins ----

// Language prose (capture p. 59): the first slot is the home country language
inline int dgoLangSlotHome()
    { return 1; }

// Language prose (capture p. 59): the second tongue is the trade language
inline int dgoLangSlotTrade()
    { return 2; }

// Language prose (capture p. 59): the third slot is the alignment language
inline int dgoLangSlotAlignment()
    { return 3; }

// Language prose (capture p. 58): the Table 5 count is the learnable
// potential, not the starting knowledge
inline bool dgoLangPotentialOnly()
    { return true; }

// Language prose (capture p. 59): the home language counts as one of the
// learnable languages
inline bool dgoLangHomeCounts()
    { return true; }

// Language prose (capture p. 59): the second tongue is the trade language
// unless wholly isolated
inline bool dgoLangSecondIsTrade()
    { return true; }

// Language prose (capture p. 59): the third slot is the alignment language
inline bool dgoLangThirdIsAlignment()
    { return true; }

// Language prose (capture p. 59): the trade language suits business and
// common needs, few abstractions
inline bool dgoLangTradeBusinessOnly()
    { return true; }

// Language prose (capture p. 59): non-humans often speak additional
// specialized racial languages
inline bool dgoLangNonHumanSpecial()
    { return true; }

// Language prose (capture p. 59): dialect speakers understand each other 75
// percent of the time
inline int dgoLangDialectComprehension()
    { return 75; }

// Language prose (capture p. 59): barbarian and wild-land dialect
// comprehension limited to 50 percent
inline int dgoLangWildComprehension()
    { return 50; }

// Language prose (capture p. 59): study months with daily contact, 20 minus
// the Intelligence
inline int dgoLangStudyMonthsBase()
    { return 20; }

// Language prose (capture p. 59): seeing the teacher every other day doubles
// the study time
inline bool dgoLangEveryOtherDayDoubles()
    { return true; }

// Language prose (capture p. 59): living among native speakers halves the
// learning time
inline bool dgoLangNativeSpeakersHalve()
    { return true; }

// Language prose (capture p. 59): the student always retains a foreigner
// accent
inline bool dgoLangAlwaysAccent()
    { return true; }

// Language prose (capture p. 59): only native speakers or the early-trained
// grasp every nuance
inline bool dgoLangNuancesNativeOnly()
    { return true; }

// ---- the Table 36 grid ----

// the class column, pinned as the 1-6 code: bushi 1, kensai 2, ninja 3,
// barbarian 4, samurai 5, sohei 6 (capture p. 55).
inline int dgoT36Class(int b)
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
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 6;
        default:
            return -99;
        }
    }

// the level-band lower bound column (capture p. 55).
inline int dgoT36LevelLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 8;
        case 6:
            return 15;
        case 7:
            return 1;
        case 8:
            return 7;
        case 9:
            return 15;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 13;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 9;
        case 16:
            return 1;
        case 17:
            return 7;
        case 18:
            return 13;
        default:
            return -99;
        }
    }

// the level-band upper bound column: the printed "and up" bands pin as the -1
// code - bushi 11, kensai 15, ninja 15, barbarian 13, samurai 9, sohei 13
// (capture p. 55).
inline int dgoT36LevelHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return -1;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 14;
        case 6:
            return -1;
        case 7:
            return 6;
        case 8:
            return 14;
        case 9:
            return -1;
        case 10:
            return 6;
        case 11:
            return 12;
        case 12:
            return -1;
        case 13:
            return 4;
        case 14:
            return 8;
        case 15:
            return -1;
        case 16:
            return 6;
        case 17:
            return 12;
        case 18:
            return -1;
        default:
            return -99;
        }
    }

// the attacks numerator column: the first number of the printed N/D rate
// (capture p. 55).
inline int dgoT36AtkNum(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 3;
        case 15:
            return 2;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 2;
        default:
            return -99;
        }
    }

// the attacks denominator column: the melee rounds of the printed N/D rate -
// 1/1, 3/2, 2/1, kensai 5/2 (capture p. 55).
inline int dgoT36AtkDen(int b)
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
            return 2;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 1;
        default:
            return -99;
        }
    }

}   // namespace rules
