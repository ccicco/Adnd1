// =========================================================================================
// Adnd1 - rules/dpu.h
// The DDG lua promotion, batch three - 60 full-field defs (Finnish 20, Greek
// 40) generated ONLY from the adjudicated pin headers, the registry floor
// 1118 -> 1178.
// census 804 -> 805.
//
// Generated from rules/klv.h and grk.h at 7dc48c2: the four grids x rows
// (combat, class, ability, roster), the being name orders locked by the
// pinned cross-references and verified against the primary ink extract pages;
// the legend tables decode verbatim from the header comments; the unpinned
// cells emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil, None and Infinite are REAL values and stay. The audits read
// the sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch three: the Finnish and Greek mythoi
// (Curtiss 2026-10-27: the print-order batches)
inline int dpuRound()
    { return 882; }

// the audit census at 7dc48c2 (the R881 land)
inline int dpuCensusBefore()
    { return 804; }

// the audit census after this round (one new audit line, the batch-three
// promotion audit)
inline int dpuCensusAfter()
    { return 805; }

// the promoted defs this round: 20 + 40, one per adjudicated stat-block row
inline int dpuDefs()
    { return 60; }

// the mythoi of batch three (the print order: Finnish, Greek)
inline int dpuMythoi()
    { return 2; }

// the registry floor at 7dc48c2 (the batch-two promotion land)
inline int dpuFloorBefore()
    { return 1118; }

// the registry floor after this round (1118 + 60)
inline int dpuFloorAfter()
    { return 1178; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpuFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (the eagle, Antaeus, Cerberus, Circe,
// Enceladus, the Furies, the Hecatoncheire)
inline int dpuMonsterRows()
    { return 7; }

// the hit-dice rows promoted (the greater and lesser cyclopes; the other
// monsters print hit points)
inline int dpuHitDiceRows()
    { return 2; }

// the fixed-damage cells emitted (the verbatim print figures cross-checked
// against the strength-bonus grids; the Apollo, Poseidon and Prometheus cells
// are garbled or worded in both voices and stay sentinel - flagged)
inline int dpuPinnedDamage()
    { return 44; }

// the grid code for the printed See below (the Nike magic-user and
// illusionist cells)
inline int dpuSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch three - the print-order
// continuation (the Finnish and Greek mythoi)
inline bool dpuPromotionBatchThree()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the klv and
// grk grids and consts; the pin rounds are the firewall)
inline bool dpuFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// Pohjola-enmity flags, the Tuonetar negative charisma, the Ukko 400 hit
// points, the Odysseus inch cell, the Nike See-below pair, the Hecatoncheire
// ten fists, the paladin pairs of Perseus and Theseus) and verified against
// the primary ink extract pages
inline bool dpuNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpuFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine: n/a for strings, -1 for ints,
// distinct from every real print value; the printed See below, Standard, Nil,
// None and Infinite are REAL values and stay
inline bool dpuSentinelsDistinct()
    { return true; }

// the prose stays contract-side: text, specials, symbols, areas of control
// and worshipper alignments emit the sentinels (no prose grids pinned this
// round)
inline bool dpuProseContractSide()
    { return true; }

// damage emits ONLY the fixed-damage rows (the verbatim print cells
// cross-checked against the strength-bonus grids); the by-weapon and
// See-below rows and the three flagged cells stay n/a
inline bool dpuDamagePinnedOnly()
    { return true; }

// the symbols and areas of control stay n/a (no symbol grids pinned for these
// mythoi, though the print carries them - a possible future pin round)
inline bool dpuSymbolsUnpinned()
    { return true; }

// the worshipper alignments stay n/a (no RosWorship grids pinned - the
// batch-two boundary carried forward)
inline bool dpuWorshipUnpinned()
    { return true; }

// the normalizer census reads the promoted defs: every DDG def full-field,
// the DDG column and the floor refreshed (the R880 book_of contract)
inline bool dpuNormalizerDdgAware()
    { return true; }

// ---- the batch-three grids ----

// The mythos ordinals (0-1, the print order: Finnish, Greek)
inline int dpuMythOrd(int b)
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
inline int dpuMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 57;
        case 1:
            return 63;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpuMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 62;
        case 1:
            return 74;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpuMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 40;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpuKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 60)
inline int dpuKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 60;
        case 2:
            return 60;
        case 3:
            return 60;
        case 4:
            return 60;
        case 5:
            return 60;
        case 6:
            return 60;
        case 7:
            return 60;
        case 8:
            return 60;
        case 9:
            return 60;
        case 10:
            return 60;
        case 11:
            return 60;
        case 12:
            return 60;
        case 13:
            return 60;
        case 14:
            return 60;
        case 15:
            return 60;
        case 16:
            return 60;
        case 17:
            return 60;
        case 18:
            return 60;
        case 19:
            return 60;
        case 20:
            return 60;
        case 21:
            return 60;
        case 22:
            return 60;
        case 23:
            return 60;
        case 24:
            return 60;
        case 25:
            return 60;
        case 26:
            return 60;
        case 27:
            return 60;
        case 28:
            return 60;
        case 29:
            return 60;
        case 30:
            return 60;
        case 31:
            return 60;
        case 32:
            return 60;
        case 33:
            return 60;
        case 34:
            return 60;
        case 35:
            return 60;
        case 36:
            return 60;
        case 37:
            return 60;
        case 38:
            return 60;
        case 39:
            return 60;
        case 40:
            return 60;
        case 41:
            return 60;
        case 42:
            return 60;
        case 43:
            return 60;
        case 44:
            return 60;
        case 45:
            return 60;
        case 46:
            return 60;
        case 47:
            return 60;
        case 48:
            return 60;
        case 49:
            return 60;
        case 50:
            return 60;
        case 51:
            return 60;
        case 52:
            return 60;
        case 53:
            return 60;
        case 54:
            return 60;
        case 55:
            return 60;
        case 56:
            return 60;
        default:
            return -1;
        }
    }

}   // namespace rules
