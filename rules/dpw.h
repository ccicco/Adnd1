// =========================================================================================
// Adnd1 - rules/dpw.h
// The DDG lua promotion, batch four - 31 full-field defs (Indian 18, Japanese
// 13) generated ONLY from the adjudicated pin headers, the registry floor
// 1178 -> 1209.
// census 805 -> 806.
//
// Generated from rules/idn.h and jpn.h at 2c96981: the four grids x rows
// (combat, class, ability, roster), the being name orders locked by the
// pinned cross-references and verified against the 1st-print ink geometry
// (the archive.org djvu word voice - the Termux tsv folds are unusable on
// these pages, the R860/R861 lesson); the legend tables decode verbatim from
// the header comments; the unpinned cells emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil, None and Infinite are REAL values and stay. The audits read
// the sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch four: the Indian and Japanese mythoi
// (Curtiss 2026-10-27: the print-order batches)
inline int dpwRound()
    { return 883; }

// the audit census at 2c96981 (the R882 land)
inline int dpwCensusBefore()
    { return 805; }

// the audit census after this round (one new audit line, the batch-four
// promotion audit)
inline int dpwCensusAfter()
    { return 806; }

// the promoted defs this round: 18 + 13, one per adjudicated stat-block row
inline int dpwDefs()
    { return 31; }

// the mythoi of batch four (the print order: Indian, Japanese)
inline int dpwMythoi()
    { return 2; }

// the registry floor at 2c96981 (the batch-three promotion land)
inline int dpwFloorBefore()
    { return 1178; }

// the registry floor after this round (1178 + 31)
inline int dpwFloorAfter()
    { return 1209; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpwFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (the elephant, the peacock, the marut,
// Garuda, the water buffalo)
inline int dpwMonsterRows()
    { return 5; }

// no hit-dice rows this round: every monster prints hit points (the Cerberus
// points-only precedent, not the cyclops)
inline int dpwHitDiceRows()
    { return 0; }

// the fixed-damage cells emitted (the verbatim print figures cross-checked
// against the strength-bonus grids; the Ama-Tsu-Mara, Daikoku and Tsukiyomi
// cells print fixed points)
inline int dpwPinnedDamage()
    { return 26; }

// the grid code for the printed See below (the Agni and Yama magic-user and
// illusionist cells)
inline int dpwSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch four - the print-order
// continuation (the Indian and Japanese mythoi)
inline bool dpwPromotionBatchFour()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the idn and
// jpn grids and consts; the pin rounds are the firewall)
inline bool dpwFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// Kali assassin-monk pair, the paladin pairs of Surya, Varuna, Vishnu, Ebisu
// and Yamamoto, the Agni and Yama See-below pairs, the Amaterasu infinite
// move, the fixed-points damage cells) and verified against the 1st-print ink
// geometry (the archive.org djvu word voice - the Termux tsv folds are
// unusable on these pages, the R860/R861 lesson)
inline bool dpwNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpwFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine: n/a for strings, -1 for ints,
// distinct from every real print value; the printed See below, Standard, Nil,
// None and Infinite are REAL values and stay
inline bool dpwSentinelsDistinct()
    { return true; }

// the prose stays contract-side: text, specials, symbols, areas of control
// and worshipper alignments emit the sentinels (no prose grids pinned this
// round)
inline bool dpwProseContractSide()
    { return true; }

// damage emits ONLY the fixed-damage rows (the verbatim print cells
// cross-checked against the strength-bonus grids); the by-weapon and Nil rows
// stay n/a
inline bool dpwDamagePinnedOnly()
    { return true; }

// the symbols and areas of control stay n/a (no symbol grids pinned for these
// mythoi, though the print carries them - a possible future pin round)
inline bool dpwSymbolsUnpinned()
    { return true; }

// the worshipper alignments stay n/a (no RosWorship grids pinned - the
// batch-three boundary carried forward)
inline bool dpwWorshipUnpinned()
    { return true; }

// the normalizer census reads the promoted defs: every DDG def full-field,
// the DDG column and the floor refreshed (the R880 book_of contract)
inline bool dpwNormalizerDdgAware()
    { return true; }

// ---- the batch-four grids ----

// The mythos ordinals (0-1, the print order: Indian, Japanese)
inline int dpwMythOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return -1;
        }
    }

// The first print page of the mythos (the folio offset PRINT = PDF - 1)
inline int dpwMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 75;
        case 1:
            return 81;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpwMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 85;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpwMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 13;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpwKeyOrd(int b)
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
        case 7:
            return 7;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 20;
        case 21:
            return 21;
        case 22:
            return 22;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 25;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 28;
        case 29:
            return 29;
        case 30:
            return 30;
        case 31:
            return 31;
        case 32:
            return 32;
        case 33:
            return 33;
        case 34:
            return 34;
        case 35:
            return 35;
        case 36:
            return 36;
        case 37:
            return 37;
        case 38:
            return 38;
        case 39:
            return 39;
        case 40:
            return 40;
        case 41:
            return 41;
        case 42:
            return 42;
        case 43:
            return 43;
        case 44:
            return 44;
        case 45:
            return 45;
        case 46:
            return 46;
        case 47:
            return 47;
        case 48:
            return 48;
        case 49:
            return 49;
        case 50:
            return 50;
        case 51:
            return 51;
        case 52:
            return 52;
        case 53:
            return 53;
        case 54:
            return 54;
        case 55:
            return 55;
        case 56:
            return 56;
        default:
            return -1;
        }
    }

// The DDG defs carrying the key (every def full-field: 57 x 31)
inline int dpwKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 31;
        case 1:
            return 31;
        case 2:
            return 31;
        case 3:
            return 31;
        case 4:
            return 31;
        case 5:
            return 31;
        case 6:
            return 31;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 31;
        case 10:
            return 31;
        case 11:
            return 31;
        case 12:
            return 31;
        case 13:
            return 31;
        case 14:
            return 31;
        case 15:
            return 31;
        case 16:
            return 31;
        case 17:
            return 31;
        case 18:
            return 31;
        case 19:
            return 31;
        case 20:
            return 31;
        case 21:
            return 31;
        case 22:
            return 31;
        case 23:
            return 31;
        case 24:
            return 31;
        case 25:
            return 31;
        case 26:
            return 31;
        case 27:
            return 31;
        case 28:
            return 31;
        case 29:
            return 31;
        case 30:
            return 31;
        case 31:
            return 31;
        case 32:
            return 31;
        case 33:
            return 31;
        case 34:
            return 31;
        case 35:
            return 31;
        case 36:
            return 31;
        case 37:
            return 31;
        case 38:
            return 31;
        case 39:
            return 31;
        case 40:
            return 31;
        case 41:
            return 31;
        case 42:
            return 31;
        case 43:
            return 31;
        case 44:
            return 31;
        case 45:
            return 31;
        case 46:
            return 31;
        case 47:
            return 31;
        case 48:
            return 31;
        case 49:
            return 31;
        case 50:
            return 31;
        case 51:
            return 31;
        case 52:
            return 31;
        case 53:
            return 31;
        case 54:
            return 31;
        case 55:
            return 31;
        case 56:
            return 31;
        default:
            return -1;
        }
    }

}   // namespace rules
