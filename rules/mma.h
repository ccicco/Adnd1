// =========================================================================================
// Adnd1 - rules/mma.h
// THE MM2 ARC OPENER - the front-matter doctrine, the five flips, and the
// lossless MM2 gap report
// census 718 -> 719.
//
// Round zero of the Monster Manual II arc (the user Go call, 2026-10-23). The
// opener capture is the Curtiss PDF upload (the front matter, pp. 1-7, clean
// text); the archive.org dual scans are the structural source for the A-Z
// roster and the table groups. The report mirrors the book with the A-Z
// sub-censuses deferred to pin time per the R792 census-correction lesson.
// The round pins the how-to-use doctrine as consts and bools - the frequency
// percentages, the magic resistance base and step, the hit-die sides, the
// intelligence ladder floor for godlike, the page anchors of the five book
// parts - and flips the five front-matter boxes. Registry 478 live,
// unchanged; the battery census reads loaded 478, errors 0.
//
namespace rules {

// ---- the MM2 opener consts (the R796 front matter) ----

// The MM2 arc opener: round zero of the Monster Manual II book (the user Go
// call)
inline int mmaOpenerRound()
    { return 796; }

// The printed page count of MM2 (1983, TSR 2021, Gary Gygax, preface dated
// October 1982)
inline int mmaBookPages()
    { return 156; }

// The Monsters from A-Z first printed page
inline int mmaAZFirstPage()
    { return 8; }

// The Monsters from A-Z last printed page
inline int mmaAZLastPage()
    { return 132; }

// The Random Encounter Tables first printed page (to 155; the Index rides at
// 156)
inline int mmaTablesFirstPage()
    { return 133; }

// Frequency doctrine: very rare is a 3 percent chance of occurrence
inline int mmaFreqVeryRarePct()
    { return 3; }

// Frequency doctrine: rare is 7 percent
inline int mmaFreqRarePct()
    { return 7; }

// Frequency doctrine: uncommon is 20 percent
inline int mmaFreqUncommonPct()
    { return 20; }

// Frequency doctrine: common is 65 percent
inline int mmaFreqCommonPct()
    { return 65; }

// Frequency doctrine: unique means only one of the creatures exists
inline int mmaFreqUniqueCount()
    { return 1; }

// Magic resistance base: the percentage is against an 11th-level caster
inline int mmaMagicResistBaseLevel()
    { return 11; }

// Magic resistance step: 5 percent per level below or above the 11th-level
// base
inline int mmaMagicResistStepPct()
    { return 5; }

// Hit dice are 8-sided unless stated otherwise; the plus adds hit points
// after the roll
inline int mmaHitDieSides()
    { return 8; }

// The intelligence ladder floor for godlike intelligence (the ladder rides
// from 0 non-intelligent)
inline int mmaIntelGodlikeLow()
    { return 21; }

// ---- the MM2 opener bools (the R796 front matter) ----

// The first meaning of monster is generic - any creature encountered, human,
// humanoid or beast, hostile or not
inline bool mmaMonsterTermIsGeneric()
    { return true; }

// The frequency percentages are pinned as consts and reflected in the
// encounter tables within statistical limits
inline bool mmaFrequencyPercentsPinned()
    { return true; }

// The move notation carries the modes: slash flying, double slash swimming,
// parentheses burrowing, star web, at-sign trees
inline bool mmaMoveNotationMultiMode()
    { return true; }

// The maneuverability classes A through E are explained in the DMG, not
// restated here
inline bool mmaManeuverabilityFromDMG()
    { return true; }

// Hit dice are 8-sided by default; low-hit creatures roll smaller dice by
// hit-point range notation
inline bool mmaHitDiceEightSidedDefault()
    { return true; }

// Treasure types refer to the MM1 treasure tables; incidental treasure is
// noted as the accidental kind
inline bool mmaTreasureTypesFromMM1()
    { return true; }

// Magic resistance is stated at the 11th-level base with the 5-percent
// per-level adjustment, and saving throws still apply
inline bool mmaMagicResistanceElevenBase()
    { return true; }

// Humans and the demihuman types always use the human attack matrices,
// monster or player character
inline bool mmaHumanMatrixForDemiHumans()
    { return true; }

// The intelligence ratings correspond to character intelligence bands, from
// non-intelligent 0 to godlike 21-plus
inline bool mmaIntelligenceLadderIQ()
    { return true; }

// The special entries are the plane line and the class lines: cleric/druid,
// fighter, magic-user/illusionist, thief/assassin, monk/bard
inline bool mmaSpecialEntriesPlaneAndClass()
    { return true; }

// Size is three bands: S smaller than human, M human-sized, L larger - size
// feeds weapon damage
inline bool mmaSizeBandsAreThree()
    { return true; }

// Level and experience point values follow the DMG method; varying hit dice
// show each value
inline bool mmaLevelXpRideDMGMethod()
    { return true; }

}   // namespace rules
