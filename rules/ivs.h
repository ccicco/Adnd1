// =========================================================================================
// Adnd1 - rules/ivs.h
// The Ives attribute tables - the Dragon Magazine walk opens at issue #1
// folio 7: the Wesley D. Ives non-prime-requisite adjudication system, the
// arc's first variant-layer pin
// census 809 -> 810.
//
// Pinned from The Dragon Vol. 1 No. 1 (June 1976), folio 7, by Wesley D.
// Ives; the voice is the chat-side OCR transcript at
// extract/dragon/001/p007_full.txt (all 32 issue pages and the pre-flip
// dragon gap report ride this round as data files). OD&D-era ink converted
// per the walk doctrine: the pin IS the conversion, provenance noted, never
// silent.
//
// The variant-layer doctrine: Dragon ink is never core 1e canon - the marks
// here are 0/1 use flags and band indices, distinct from every core print
// value; the honest boundaries (the 18-super-90 glyph, the fighters-only
// ladder) ride the audit comment and the gap report.
//
namespace rules {

// ---- the ivs doctrine ----

// the d100 floor - generate 1-100, always add the tested score
inline int ivsRollMin()
    { return 1; }

// the d100 ceiling (the score-added total may exceed it - the band chain
// tails)
inline int ivsRollMax()
    { return 100; }

// the adjusted total (the d100 roll plus the score in question) selects the
// die band
inline bool ivsScoreAddedToRoll()
    { return true; }

// the success chance is the band die roll times the tested score, read as a
// percent
inline bool ivsPercentIsRollTimesScore()
    { return true; }

// the extraordinary-strength ladder serves fighters only (the Grod doctrine)
inline bool ivsLadderIsFightersExStr()
    { return true; }

// ---- the ivs banding ----

// the die band - the adjusted total picks the band: 1-20 band 0, 21-40 band
// 1, 41-60 band 2, 61-80 band 3, 81 and up band 4
inline int ivsDieBand(int total)
    {
        if (total <= 20) return 0;
        if (total <= 40) return 1;
        if (total <= 60) return 2;
        if (total <= 80) return 3;
        return 4;
    }

// the extraordinary-strength ladder band - the 18/xx percentile picks the
// band: 1-20 band 0 through 96-99 band 7, 18/00 (100) band 8
inline int ivsExStrLadder(int pct)
    {
        if (pct <= 20) return 0;
        if (pct <= 40) return 1;
        if (pct <= 60) return 2;
        if (pct <= 70) return 3;
        if (pct <= 80) return 4;
        if (pct <= 90) return 5;
        if (pct <= 95) return 6;
        if (pct <= 99) return 7;
        return 8;
    }

// ---- the ivs band switches ----

// the band die - band 0 the d4, band 1 the d6, band 2 the d8, band 3 the d10,
// band 4 the d12
inline int ivsDieSides(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        default:
            return 12;
        }
    }

// the ladder's effective strengths - 18/01-18/20 reads 18 through 18/91-18/99
// reads 25, 18/00 reads 27 (the ink's 18-super-90 glyph, pinned as scanned)
inline int ivsLadderStr(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 19;
        case 2:
            return 20;
        case 3:
            return 21;
        case 4:
            return 22;
        case 5:
            return 23;
        case 6:
            return 24;
        case 7:
            return 25;
        case 8:
            return 27;
        default:
            return 27;
        }
    }

// ---- the ivs use grid ----

// the use grid rows - STR INT WIS CON DEX CHA
inline int ivsUseCount()
    { return 6; }

// the use grid, strength - any extraordinary physical exertion
inline int ivsUseExertion(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// the use grid, devices - INT operation, WIS function recognition, DEX manual
// manipulation
inline int ivsUseDevice(int b)
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
        default:
            return 0;
        }
    }

// the use grid, constitution stamina - swimming, running, staying awake,
// going hungry
inline int ivsUseStamina(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// the use grid, dexterity hands - manipulation, balance and climbing, tying
// and untying knots
inline int ivsUseManipulation(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// the use grid, charisma - believability, persuasiveness, the morale of
// followers
inline int ivsUsePersuasion(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 1;
        default:
            return 0;
        }
    }

// the use grid, intelligence learning - patterns, cause and effect, lair
// types, languages and skills
inline int ivsUseLearning(int b)
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
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
