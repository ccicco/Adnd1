// =========================================================================================
// Adnd1 - rules/dpx.h
// The DDG lua promotion, batch five - 33 full-field defs (the Melnibonean
// mythos) generated ONLY from the adjudicated pin headers, the registry floor
// 1209 -> 1242.
// census 806 -> 807.
//
// Generated from rules/mlb.h at e1bb817: the four grids x rows (combat,
// class, ability, roster), the being name order locked by the pinned
// cross-references (the Elric-through-Yyrkoon print order) and verified
// against the 2nd-print ink (the tesseract tsv voice; the junk-swallowed
// Moonglum, Nnuurrr and Nuru-ah columns read from the full-text voice); the
// legend tables decode verbatim from the header comments; the unpinned cells
// emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil, None and Infinite are REAL values and stay. The audits read
// the sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch five: the Melnibonean mythos (Curtiss
// 2026-10-27: the print-order batches)
inline int dpxRound()
    { return 884; }

// the audit census at e1bb817 (the R883 land)
inline int dpxCensusBefore()
    { return 806; }

// the audit census after this round (one new audit line, the batch-five
// promotion audit)
inline int dpxCensusAfter()
    { return 807; }

// the promoted defs this round, one per adjudicated stat-block row (Elric
// through Yyrkoon, the print order)
inline int dpxDefs()
    { return 33; }

// the mythos of batch five (the print order: Melnibonean)
inline int dpxMythoi()
    { return 1; }

// the registry floor at e1bb817 (the batch-four promotion land)
inline int dpxFloorBefore()
    { return 1209; }

// the registry floor after this round (1209 + 33)
inline int dpxFloorAfter()
    { return 1242; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpxFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (the Assassinator, the Clakar, the Dharzi
// hunting dog, the Elenoin, the Grahuk, the Kelmain, the Mist Giant, the
// Mordagz, the Myyrrhn, the Nihrain horse, the Oonai, the Quaolnargn, the
// vampire trees, the vulture lion)
inline int dpxMonsterRows()
    { return 14; }

// the hit-dice rows promoted (the Clakar 6, the Dharzi 2, the Mist Giant 12,
// the Myyrrhn 3, the Nihrain horse 7, the Oonai 7, the vampire trees 8, the
// vulture lion 9 - the cyclops shape, not the Cerberus points-only)
inline int dpxHitDiceRows()
    { return 8; }

// the fixed-damage cells emitted (the verbatim print figures cross-checked
// against the strength-bonus grids; the rows without a fixed print - by
// weapon, Variable, Nil, See below - stay n/a)
inline int dpxPinnedDamage()
    { return 26; }

// the grid code for the printed See below (the Grome, Kakatal, Misha,
// Straasha and Nuru-ah cells)
inline int dpxSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch five - the print-order
// continuation (the Melnibonean mythos)
inline bool dpxPromotionBatchFive()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the mlb
// grids and consts; the pin rounds are the firewall)
inline bool dpxFromHeadersOnly()
    { return true; }

// the being-to-row name order is locked by the pinned cross-references (the
// Elenoin-Grahuk enmity pair, the in-each MU/I cells, the See-below pairs of
// Grome, Kakatal, Misha, Straasha and Nuru-ah, the Arioch Variable size) and
// verified against the 2nd-print ink (the tesseract tsv voice; the
// junk-swallowed Moonglum, Nnuurrr and Nuru-ah columns read from the
// full-text voice)
inline bool dpxNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpxFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine: n/a for strings, -1 for ints,
// distinct from every real print value; the printed See below, Standard, Nil,
// None and Variable are REAL values and stay
inline bool dpxSentinelsDistinct()
    { return true; }

// the prose stays contract-side: text, specials, symbols, areas of control
// and worshipper alignments emit the sentinels (no prose grids pinned this
// round)
inline bool dpxProseContractSide()
    { return true; }

// damage emits ONLY the fixed-damage rows (the verbatim print cells
// cross-checked against the strength-bonus grids); the by-weapon, Variable,
// Nil and See-below rows stay n/a
inline bool dpxDamagePinnedOnly()
    { return true; }

// the symbols and areas of control stay n/a (no symbol grids pinned for this
// mythos, though the print carries them - a possible future pin round)
inline bool dpxSymbolsUnpinned()
    { return true; }

// the worshipper alignments stay n/a (no RosWorship grids pinned - the
// batch-three boundary carried forward)
inline bool dpxWorshipUnpinned()
    { return true; }

// the normalizer census reads the promoted defs: every DDG def full-field,
// the DDG column and the floor refreshed (the R880 book_of contract)
inline bool dpxNormalizerDdgAware()
    { return true; }

// ---- the batch-five grids ----

// The mythos ordinals (0-0, the print order: Melnibonean)
inline int dpxMythOrd(int b)
    {
        switch (b) {
        case 0:
            return 0;
        default:
            return -1;
        }
    }

// The first print page of the mythos (the folio offset PRINT = PDF - 1)
inline int dpxMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 86;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpxMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 95;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpxMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 33;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpxKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 33)
inline int dpxKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 33;
        case 1:
            return 33;
        case 2:
            return 33;
        case 3:
            return 33;
        case 4:
            return 33;
        case 5:
            return 33;
        case 6:
            return 33;
        case 7:
            return 33;
        case 8:
            return 33;
        case 9:
            return 33;
        case 10:
            return 33;
        case 11:
            return 33;
        case 12:
            return 33;
        case 13:
            return 33;
        case 14:
            return 33;
        case 15:
            return 33;
        case 16:
            return 33;
        case 17:
            return 33;
        case 18:
            return 33;
        case 19:
            return 33;
        case 20:
            return 33;
        case 21:
            return 33;
        case 22:
            return 33;
        case 23:
            return 33;
        case 24:
            return 33;
        case 25:
            return 33;
        case 26:
            return 33;
        case 27:
            return 33;
        case 28:
            return 33;
        case 29:
            return 33;
        case 30:
            return 33;
        case 31:
            return 33;
        case 32:
            return 33;
        case 33:
            return 33;
        case 34:
            return 33;
        case 35:
            return 33;
        case 36:
            return 33;
        case 37:
            return 33;
        case 38:
            return 33;
        case 39:
            return 33;
        case 40:
            return 33;
        case 41:
            return 33;
        case 42:
            return 33;
        case 43:
            return 33;
        case 44:
            return 33;
        case 45:
            return 33;
        case 46:
            return 33;
        case 47:
            return 33;
        case 48:
            return 33;
        case 49:
            return 33;
        case 50:
            return 33;
        case 51:
            return 33;
        case 52:
            return 33;
        case 53:
            return 33;
        case 54:
            return 33;
        case 55:
            return 33;
        case 56:
            return 33;
        default:
            return -1;
        }
    }

}   // namespace rules
