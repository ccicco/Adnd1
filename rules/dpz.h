// =========================================================================================
// Adnd1 - rules/dpz.h
// The DDG lua promotion, batch seven - 42 full-field defs (the Norse mythos
// and the Sumerian mythos) generated ONLY from the adjudicated pin headers,
// the registry floor 1291 -> 1333.
// census 808 -> 809.
//
// Generated from rules/nrs.h and rules/smr.h at a187f50: the four grids x
// rows (combat, class, ability, roster) per mythos, the being name orders
// locked by the pinned cross-references (the Odin-through-Valkyries and
// Enlil-through-Utu print orders) and verified against the 2nd-print ink (the
// tesseract tsv voice) with the 1eonline L&L pages as the parity voice; the
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

// the DDG lua promotion round, batch seven: the Norse and Sumerian mythoi
// (Curtiss 2026-10-27: the print-order batches)
inline int dpzRound()
    { return 886; }

// the audit census at a187f50 (the R885 land)
inline int dpzCensusBefore()
    { return 808; }

// the audit census after this round (one new audit line, the batch-seven
// promotion audit)
inline int dpzCensusAfter()
    { return 809; }

// the promoted defs this round, one per adjudicated stat-block row (Odin
// through the Valkyries, then Enlil through Utu, the print orders)
inline int dpzDefs()
    { return 42; }

// the mythoi of batch seven (the print order: the Norse mythos, the Sumerian
// mythos)
inline int dpzMythoi()
    { return 2; }

// the registry floor at a187f50 (the batch-six promotion land)
inline int dpzFloorBefore()
    { return 1291; }

// the registry floor after this round (1291 + 42)
inline int dpzFloorAfter()
    { return 1333; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpzFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (the pin nrsMonsterCount 11 - the eleven
// MM-style blocks wording against the ten rank-5 grid rows, the pin-internal
// flag; Hugin and Munin, Sleipner, Freke and Gere, the Fenris Wolf,
// Fossergrim, Blodug-Hofi, Gullin-Bursti, Garm, Jormungandr and the Thor
// goats all promote)
inline int dpzMonsterRows()
    { return 11; }

// the hit-dice rows promoted (the Fossergrim 5 HD print - the CbtHP 5 cell is
// hit dice, not points, the lone Norse hit-dice row)
inline int dpzHitDiceRows()
    { return 1; }

// the fixed-damage cells emitted (the verbatim print figures cross-checked
// against the strength-bonus grids; nrs 27, smr 5 - the Fossergrim by-weapon
// print against its DmgFixed 1 and the Nin-hursag 2-20 dice print against its
// 0 ride the pin-internal flags, both emitting the n/a sentinel)
inline int dpzPinnedDamage()
    { return 32; }

// the grid code for the printed See below (no class cells carry it this batch
// - the Norse 99s are the literal prints: the Fjalar and Skirnir 99 hit
// points and the Fenris Wolf and Jormungandr 99 magic resistances)
inline int dpzSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch seven - the print-order
// continuation (the Norse and Sumerian mythoi)
inline bool dpzPromotionBatchSeven()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the nrs and
// smr grids and consts; the pin rounds are the firewall)
inline bool dpzFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// R865 and R866 walk records; the Odin-through-Valkyries and
// Enlil-through-Utu print orders)
inline bool dpzNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpzFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine: n/a for strings, -1 for ints,
// distinct from every real print value; the printed See below, Standard, Nil,
// None and Infinite are REAL values and stay
inline bool dpzSentinelsDistinct()
    { return true; }

// the prose stays contract-side: text, specials, symbols, areas of control
// and worshipper alignments emit the sentinels (unpinned this batch - the
// Inanna warriors-and-lovers odd cell rides the boundary noted)
inline bool dpzProseContractSide()
    { return true; }

// damage emits ONLY the fixed-damage rows (the verbatim print cells
// cross-checked against the strength-bonus grids); every by-weapon, Nil,
// Special, See below and Variable cell emits the sentinel
inline bool dpzDamagePinnedOnly()
    { return true; }

// the symbols and areas of control stay n/a (no symbol grids pinned for these
// mythoi, though the prints carry the lines)
inline bool dpzSymbolsUnpinned()
    { return true; }

// the worshipper alignments stay n/a (no RosWorship alignment grids pinned -
// the smrRosWorshipOdd Inanna cell flags the warriors-and-lovers line without
// pinning an alignment; the batch-three boundary carried forward)
inline bool dpzWorshipUnpinned()
    { return true; }

// the normalizer census reads the promoted defs: every DDG def full-field,
// the DDG column and the floor refreshed by the census patch
inline bool dpzNormalizerDdgAware()
    { return true; }

// ---- the batch-seven grids ----

// The mythos ordinals (0-1, the print order: the Norse mythos, the Sumerian
// mythos)
inline int dpzMythOrd(int b)
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
inline int dpzMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 113;
        case 1:
            return 125;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpzMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 124;
        case 1:
            return 127;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpzMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 7;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpzKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 42)
inline int dpzKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 42;
        case 1:
            return 42;
        case 2:
            return 42;
        case 3:
            return 42;
        case 4:
            return 42;
        case 5:
            return 42;
        case 6:
            return 42;
        case 7:
            return 42;
        case 8:
            return 42;
        case 9:
            return 42;
        case 10:
            return 42;
        case 11:
            return 42;
        case 12:
            return 42;
        case 13:
            return 42;
        case 14:
            return 42;
        case 15:
            return 42;
        case 16:
            return 42;
        case 17:
            return 42;
        case 18:
            return 42;
        case 19:
            return 42;
        case 20:
            return 42;
        case 21:
            return 42;
        case 22:
            return 42;
        case 23:
            return 42;
        case 24:
            return 42;
        case 25:
            return 42;
        case 26:
            return 42;
        case 27:
            return 42;
        case 28:
            return 42;
        case 29:
            return 42;
        case 30:
            return 42;
        case 31:
            return 42;
        case 32:
            return 42;
        case 33:
            return 42;
        case 34:
            return 42;
        case 35:
            return 42;
        case 36:
            return 42;
        case 37:
            return 42;
        case 38:
            return 42;
        case 39:
            return 42;
        case 40:
            return 42;
        case 41:
            return 42;
        case 42:
            return 42;
        case 43:
            return 42;
        case 44:
            return 42;
        case 45:
            return 42;
        case 46:
            return 42;
        case 47:
            return 42;
        case 48:
            return 42;
        case 49:
            return 42;
        case 50:
            return 42;
        case 51:
            return 42;
        case 52:
            return 42;
        case 53:
            return 42;
        case 54:
            return 42;
        case 55:
            return 42;
        case 56:
            return 42;
        default:
            return -1;
        }
    }

}   // namespace rules
