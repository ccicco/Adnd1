// =========================================================================================
// Adnd1 - rules/dpy.h
// The DDG lua promotion, batch six - 49 full-field defs (the Nehwon mythos
// and the Nonhumans' Deities) generated ONLY from the adjudicated pin
// headers, the registry floor 1242 -> 1291.
// census 807 -> 808.
//
// Generated from rules/nhw.h and rules/nhg.h at d838c9a: the four grids x
// rows (combat, class, ability, roster) per mythos, the being name orders
// locked by the pinned cross-references (the Fafhrd-through-Water-Cobra and
// Hruggek-through-Laogzed print orders) and verified against the 2nd-print
// ink (the tesseract tsv voice) with the 1eonline L&L pages as the parity
// voice; the legend tables decode verbatim from the header comments; the
// unpinned cells emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil, None and Infinite are REAL values and stay. The audits read
// the sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch six: the Nehwon mythos and the
// Nonhumans' Deities (Curtiss 2026-10-27: the print-order batches)
inline int dpyRound()
    { return 885; }

// the audit census at d838c9a (the R884 land)
inline int dpyCensusBefore()
    { return 807; }

// the audit census after this round (one new audit line, the batch-six
// promotion audit)
inline int dpyCensusAfter()
    { return 808; }

// the promoted defs this round, one per adjudicated stat-block row (Fafhrd
// through the Water Cobra, then Hruggek through Laogzed, the print orders)
inline int dpyDefs()
    { return 49; }

// the mythoi of batch six (the print order: Nehwon, the Nonhumans' Deities)
inline int dpyMythoi()
    { return 2; }

// the registry floor at d838c9a (the batch-five promotion land)
inline int dpyFloorBefore()
    { return 1242; }

// the registry floor after this round (1242 + 49)
inline int dpyFloorAfter()
    { return 1291; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpyFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (the Astral Wolf, the Behemoth, the Bird
// of Tyaa, the Cold Woman, the Devourer, the Nehwon Ghoul, the Leviathan, the
// Snow Serpent, the Salt Spider, the Water Cobra - the Nehwon ten; the
// Nonhumans' Deities rows are all divine)
inline int dpyMonsterRows()
    { return 10; }

// the hit-dice rows promoted (the Astral Wolf 3, the Behemoth 15, the Nehwon
// Ghoul 3, the Leviathan 40, the Snow Serpent 10, the Salt Spider 3, the
// Water Cobra 3 with the +3 bonus - the first DDG hit-dice bonus cell)
inline int dpyHitDiceRows()
    { return 7; }

// the fixed-damage cells emitted (the verbatim print figures cross-checked
// against the strength-bonus grids; nhw 17, nhg 17 - the ghoul by-weapon
// print and the earth god 5-50 ride the pin-internal flags, both emitting the
// n/a sentinel)
inline int dpyPinnedDamage()
    { return 34; }

// the grid code for the printed See below (the Hate MU/I pair and the Lolth
// clr/drd and mu/ill pairs)
inline int dpySeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch six - the print-order
// continuation (the Nehwon mythos and the Nonhumans' Deities)
inline bool dpyPromotionBatchSix()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the nhw and
// nhg grids and consts; the pin rounds are the firewall)
inline bool dpyFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// R863 and R864 walk records; the Fafhrd-through-Water-Cobra and
// Hruggek-through-Laogzed print orders)
inline bool dpyNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpyFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine: n/a for strings, -1 for ints,
// distinct from every real print value; the printed See below, Standard, Nil,
// None and Infinite are REAL values and stay
inline bool dpySentinelsDistinct()
    { return true; }

// the prose stays contract-side: text, specials, symbols, areas of control
// and worshipper alignments emit the sentinels (unpinned this batch)
inline bool dpyProseContractSide()
    { return true; }

// damage emits ONLY the fixed-damage rows (the verbatim print cells
// cross-checked against the strength-bonus grids); every by-weapon, Nil,
// Special, See below and Variable cell emits the sentinel
inline bool dpyDamagePinnedOnly()
    { return true; }

// the symbols and areas of control stay n/a (no symbol grids pinned for these
// mythoi, though the prints carry the lines)
inline bool dpySymbolsUnpinned()
    { return true; }

// the worshipper alignments stay n/a (no RosWorship grids pinned - the
// batch-three boundary carried forward)
inline bool dpyWorshipUnpinned()
    { return true; }

// the normalizer census reads the promoted defs: every DDG def full-field,
// the DDG column and the floor refreshed by the census patch
inline bool dpyNormalizerDdgAware()
    { return true; }

// ---- the batch-six grids ----

// The mythos ordinals (0-1, the print order: Nehwon, the Nonhumans' Deities)
inline int dpyMythOrd(int b)
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
inline int dpyMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 96;
        case 1:
            return 105;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpyMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 104;
        case 1:
            return 112;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpyMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 29;
        case 1:
            return 20;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpyKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 49)
inline int dpyKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 49;
        case 1:
            return 49;
        case 2:
            return 49;
        case 3:
            return 49;
        case 4:
            return 49;
        case 5:
            return 49;
        case 6:
            return 49;
        case 7:
            return 49;
        case 8:
            return 49;
        case 9:
            return 49;
        case 10:
            return 49;
        case 11:
            return 49;
        case 12:
            return 49;
        case 13:
            return 49;
        case 14:
            return 49;
        case 15:
            return 49;
        case 16:
            return 49;
        case 17:
            return 49;
        case 18:
            return 49;
        case 19:
            return 49;
        case 20:
            return 49;
        case 21:
            return 49;
        case 22:
            return 49;
        case 23:
            return 49;
        case 24:
            return 49;
        case 25:
            return 49;
        case 26:
            return 49;
        case 27:
            return 49;
        case 28:
            return 49;
        case 29:
            return 49;
        case 30:
            return 49;
        case 31:
            return 49;
        case 32:
            return 49;
        case 33:
            return 49;
        case 34:
            return 49;
        case 35:
            return 49;
        case 36:
            return 49;
        case 37:
            return 49;
        case 38:
            return 49;
        case 39:
            return 49;
        case 40:
            return 49;
        case 41:
            return 49;
        case 42:
            return 49;
        case 43:
            return 49;
        case 44:
            return 49;
        case 45:
            return 49;
        case 46:
            return 49;
        case 47:
            return 49;
        case 48:
            return 49;
        case 49:
            return 49;
        case 50:
            return 49;
        case 51:
            return 49;
        case 52:
            return 49;
        case 53:
            return 49;
        case 54:
            return 49;
        case 55:
            return 49;
        case 56:
            return 49;
        default:
            return -1;
        }
    }

}   // namespace rules
