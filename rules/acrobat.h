// ===========================================================================
// Adnd1 - rules/acrobat.h
// The UA thief-acrobat (pp. 23-25) pins (R335).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The registry rows and the creation-flow gates ride their own rounds.
//
// Scope = the gap-report item: the split class at 6th, the Function
// Table, Table I and Tables II-IV, the jump and extension rules, the
// evasion 60% cap.
//
// JUDGMENTs:
//   - the split class runs the 6th-12th thief levels (Table I prints
//     rows 6-12 with titles and the past-12th addendum).
//   - the Function Table's pole vault, high jump and broad jump
//     distance cells lost their decimal points and foot marks to the
//     OCR (4a', 5%", 9%', 10o, 11%", 12', 13', A) - no consistent
//     decode; they read as documented holes pending the PDF.
//   - the tumbling attack column decodes as level-capped-20: rows
//     8-23 print exactly level% (8,9,10...20) with the 20% cap at
//     20th-23rd; the row-6 cell prints "8%" but that row's LEVEL
//     cell itself prints "8" where 6 belongs - the same 6-to-8 slip
//     - so the 6th reads 6% under the decode, documented here.
//   - the tightrope column reads 75/80/85/90/95 then 100 at 11th
//     and up; the 16th, 19th and 21st cells are OCR-blank but every
//     readable row at 11th or above prints 100 - the ladder pins as
//     75+5 per level capped at 100, the blanks documented.
//   - the falling column pins only the extract-verified and
//     prose-verified cells (acrobatFallingChanceKnown); the 20-foot
//     band past 9th, the 30-foot band's start and completion, the
//     40-foot band's 100% cell and the row-12 garbage cell are
//     holes. The 10-foot band completes at 9th per the prose.
//   - the racial adjustments row, Table II (strength) and Table IV's
//     two columns (merged by the OCR into single cells) are
//     OCR-lost - holes; Table IV's readable fragments (450-550,
//     570, 600, 625, 650, 660, 670 gp) and the two prose carry
//     reads (the 14th's extra 1,000 gp, the 22nd's 400-pound
//     person) are documented here, not pinned as data.
//   - the five wind/carry footnotes read clean and pin as the
//     carry matrix; -1 marks the wind-handling grants (footnote 1
//     handles a moderate wind, footnote 2 a strong wind).
//   - Table III (dexterity) reads clean and pins in full.
// ===========================================================================

#pragma once

namespace rules {

// ---- the conversion (p. 23) ----
// STR 15, DEX 16; the decision after rising through 5th, effective
// at 6th; the four frozen skills stay at the 5th-level scores; read
// magic is never gained; trainer of at least 10th level, 6 weeks.
inline int acrobatMinStrength()
    { return 15; }

inline int acrobatMinDexterity()
    { return 16; }

inline int acrobatConvertFromLevel()
    { return 6; }

inline int acrobatSkillsFrozenAtLevel()
    { return 5; }

inline int acrobatFrozenSkillCount()
    { return 4; }

inline const char* acrobatFrozenSkillName(int i) {
    static const char* const k[4] = {
        "Find Traps", "Pick Pockets",
        "Open Locks", "Remove Traps"
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

inline bool acrobatReadMagicNeverGained()
    { return true; }

inline int acrobatRetainedSkillCount()
    { return 4; }

inline const char* acrobatRetainedSkillName(int i) {
    static const char* const k[4] = {
        "Move Silently", "Hide in Shadows",
        "Hear Noise", "Read Languages"
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

inline bool acrobatClimbWallsStillImproves()
    { return true; }

inline bool acrobatAnyRaceAllowed()
    { return true; }

inline int acrobatXpBonusPercent()
    { return 10; }

inline int acrobatXpBonusAbilityMin()
    { return 16; }

inline int acrobatTrainerMinLevel()
    { return 10; }

inline int acrobatTrainingWeeks()
    { return 6; }

// ---- Table I (p. 23): the split ladder ----
// The thief-acrobat levels 6-12; 250,000 xp per level past the
// 12th. XP-to-attain per the R176 lower-bound-minus-one convention.
inline int acrobatSplitLevelLow()
    { return 6; }

inline int acrobatSplitLevelHigh()
    { return 12; }

inline int acrobatXpToAttain(int level) {
    static const int k[7] = {
        20000, 45000, 75000, 125000,
        180000, 250000, 500000
    };
    if (level < 6) return 0;
    if (level > 12) return 500000;
    return k[level - 6];
}

inline int acrobatXpPerLevelPast12()
    { return 250000; }

inline const char* acrobatTitle(int level) {
    switch (level) {
        case 6: return "Burglar-Acrobat";
        case 7: return "Second-Story Thief";
        case 8: return "Cat Burglar";
        case 9: return "Master Cat Burglar";
        case 10: return "Thief-Acrobat";
        case 11: return "Master Thief-Acrobat";
        case 12: return
            "Master Thief-Acrobat (12th)";
        default: return "";
    }
}

// ---- tightrope walking (p. 23) ----
// Ascent to about 45 degrees (maximum), descent slightly steeper;
// up to 60 feet per crossing, further distance needs extra checks;
// 60 feet per round; moderate wind -10%, strong -20%, strong gusty
// always 5% failure; a balance pole +10% in non-windy conditions;
// non-acrobats walk at base 20% and move no faster than 30 feet
// per round.
inline int acrobatTightropeAscentMaxAngle()
    { return 45; }

inline int acrobatTightropeMaxDistance()
    { return 60; }

inline int acrobatTightropeMoveRate()
    { return 60; }

inline int acrobatTightropeModerateWindPenalty()
    { return 10; }

inline int acrobatTightropeStrongWindPenalty()
    { return 20; }

inline int acrobatTightropeGustyFailure()
    { return 5; }

inline int acrobatBalancePoleBonus()
    { return 10; }

inline int acrobatNonAcrobatTightropeBase()
    { return 20; }

inline int acrobatNonAcrobatTightropeRate()
    { return 30; }

// ---- pole vaulting (p. 23) ----
// Any leverage device (teeter board, springboard, pole); at least a
// 30-foot running start; the pole at least 4 feet taller than the
// vaulter; the pole drops at the vault; landing on the feet in 1
// segment; non-acrobats cannot effectively vault.
inline int acrobatVaultRunStart()
    { return 30; }

inline int acrobatVaultPoleExtraHeight()
    { return 4; }

inline bool acrobatNonAcrobatsCannotVault()
    { return true; }

inline int acrobatLandingSegments()
    { return 1; }

// ---- high jumping (p. 23) ----
// Requires a running start; the landing surface no more than 4 feet
// above the jump level, or 2 feet under the normal maximum height,
// whichever is greater; the feet in 1 segment.
inline bool acrobatHighJumpNeedsRun()
    { return true; }

inline int acrobatHighJumpLandAboveMax()
    { return 4; }

inline int acrobatHighJumpLandBelowMax()
    { return 2; }

// ---- broad jumping (p. 24) ----
// A jump takes a single segment; a running broad jump needs a
// 20-foot run; standing: forward to the maximum, backward to half.
// The extensions: 2 feet gained but prone, 2 segments to recover;
// 3 feet: 25% failure, 3 segments; 4 feet: 50%, 4 segments;
// 5 feet: 75%, 5 segments. Non-acrobats: 4 feet standing, 8 running,
// always prone, a full round to recover. No extra weight or bulky
// armor.
inline int acrobatJumpSegments()
    { return 1; }

inline int acrobatRunningBroadMinRun()
    { return 20; }

inline bool acrobatStandingBackwardHalf()
    { return true; }

inline int acrobatExtensionFailurePercent(int feet) {
    // feet 2-5; the 2-foot extension
    // never fails (it lands prone
    // instead)
    static const int k[4] = {0, 25, 50, 75};
    if (feet < 2) feet = 2;
    if (feet > 5) feet = 5;
    return k[feet - 2];
}

inline int acrobatExtensionRecoverySegments(int feet) {
    static const int k[4] = {2, 3, 4, 5};
    if (feet < 2) feet = 2;
    if (feet > 5) feet = 5;
    return k[feet - 2];
}

inline int acrobatNonAcrobatStandingBroad()
    { return 4; }

inline int acrobatNonAcrobatRunningBroad()
    { return 8; }

inline bool acrobatJumpBulkyArmorBanned()
    { return true; }

// ---- the Function Table (p. 24) ----
// Levels 6-23. The tightrope, tumbling attack, evasion and falling
// columns pin below; the vault/jump distance cells are the
// documented OCR holes.
inline int acrobatFunctionRowCount()
    { return 18; }

inline int acrobatFunctionLevelLow()
    { return 6; }

inline int acrobatTightropePercent(int level) {
    // 75 at 6th, +5 per level, capped
    // at 100 from 11th; the 16th, 19th
    // and 21st cells are OCR-blank
    // (the readable rows fix the
    // ladder)
    if (level < 6) return 0;
    int p = 75 + 5 * (level - 6);
    return p > 100 ? 100 : p;
}

inline int acrobatTumblingAttackPercent(int level) {
    // level-capped-20 (rows 8-23 print
    // exactly level% with the 20 cap;
    // the row-6 6-to-8 slip documented
    // in the header comment)
    if (level < 6) return 0;
    return level > 20 ? 20 : level;
}

inline int acrobatEvasionPercent(int level) {
    // 10 at 6th, +5 per level to 50 at
    // 14th, +2 to 60 at 19th, capped
    // (all 18 rows read clean)
    if (level < 6) return 0;
    if (level >= 19) return 60;
    if (level <= 14) return 10 + 5 * (level - 6);
    return 50 + 2 * (level - 14);
}

inline int acrobatEvasionBaseCap()
    { return 60; }

inline bool acrobatEvasionRequiresInitiative()
    { return true; }

inline int acrobatEvasionSegments()
    { return 1; }

inline bool acrobatTumblingAttackIsPummeling()
    { return true; }

inline bool acrobatNonAcrobatsNoTumblingBenefit()
    { return true; }

inline bool acrobatFallingDamageConverse()
    { return true; }

inline bool acrobatFallingPastSafeAddsDice()
    { return true; }

inline int acrobatFallingChanceKnown(
        int level, int feet) {
    // the extract- and prose-verified
    // cells; -1 = a documented hole
    static const int cells[17][3] = {
        {6, 10, 25},    // the prose
        {7, 10, 50},
        {8, 10, 75},
        {9, 10, 100},   // the prose
        {9, 20, 25},    // the prose
        {13, 30, 50},
        {14, 30, 75},
        {15, 40, 20},
        {16, 40, 40},
        {17, 40, 60},
        {18, 40, 80},
        {19, 50, 20},
        {20, 50, 40},
        {21, 50, 60},
        {22, 50, 80},
        {23, 50, 100},  // the prose
        {23, 60, 20}    // the prose
    };
    for (int i = 0; i < 17; ++i)
        if (cells[i][0] == level
            && cells[i][1] == feet)
            return cells[i][2];
    return -1;
}

// ---- the wind/carry footnotes (p. 24) ----
// fn 1-5, wind 0 = none, 1 = moderate, 2 = strong. -1 = the
// footnote handles that wind with no carry penalty instead.
inline int acrobatFootnoteCarryGp(int fn, int wind) {
    static const int k[5][3] = {
        {1000, -1, 0},
        {2000, 1000, -1},
        {0, 2000, 1000},
        {3000, 2000, 1000},
        {4000, 3000, 2000}
    };
    if (fn < 1) fn = 1;
    if (fn > 5) fn = 5;
    if (wind < 0) wind = 0;
    if (wind > 2) wind = 2;
    return k[fn - 1][wind];
}

// ---- the equipment reads (p. 25) ----
inline bool acrobatNoBackpackExceptTightrope()
    { return true; }

inline bool acrobatTightropeCarriedEvenlyBalanced()
    { return true; }

// ---- Table III: the dexterity
// adjustments (p. 25) ----
inline int acrobatDexTightropeBonus(int dex) {
    static const int k[4] = {5, 10, 15, 20};
    if (dex < 16) return 0;
    if (dex > 19) dex = 19;
    return k[dex - 16];
}

inline int acrobatDexPoleVaultBonus(int dex) {
    static const int k[4] = {0, 5, 10, 15};
    if (dex < 16) return 0;
    if (dex > 19) dex = 19;
    return k[dex - 16];
}

inline int acrobatDexAttackBonus(int dex) {
    static const int k[4] = {1, 2, 3, 4};
    if (dex < 16) return 0;
    if (dex > 19) dex = 19;
    return k[dex - 16];
}

inline int acrobatDexEvasionBonus(int dex) {
    static const int k[4] = {2, 3, 5, 8};
    if (dex < 16) return 0;
    if (dex > 19) dex = 19;
    return k[dex - 16];
}

inline int acrobatDexFallingBonus(int dex) {
    static const int k[4] = {0, 0, 5, 10};
    if (dex < 16) return 0;
    if (dex > 19) dex = 19;
    return k[dex - 16];
}

}   // namespace rules