// =========================================================================================
// Adnd1 - rules/dpt.h
// The DDG lua promotion, batch two - 68 full-field defs (Central American 14,
// Chinese 18, Cthulhu 15, Egyptian 21) generated ONLY from the adjudicated
// pin headers, the registry floor 1050 -> 1118.
// census 803 -> 804.
//
// Generated from rules/dgf.h, dgg.h, cth.h and egp.h at 22f9d1b: the four
// grids x rows (combat, class, ability, roster), the being name orders locked
// by the pinned cross-references and verified against the primary ink extract
// pages; the legend tables decode verbatim from the header comments; the
// unpinned cells emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil, None and Infinite are REAL values and stay. The audits read
// the sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch two: the Central American, Chinese,
// Cthulhu and Egyptian mythoi (Curtiss 2026-10-27: the print-order batches)
inline int dptRound()
    { return 881; }

// the audit census at 22f9d1b (the R880 land)
inline int dptCensusBefore()
    { return 803; }

// the audit census after this round (one new audit line, the batch-two
// promotion audit)
inline int dptCensusAfter()
    { return 804; }

// the promoted defs this round: 14 + 18 + 15 + 21, one per adjudicated
// stat-block row
inline int dptDefs()
    { return 68; }

// the mythoi of batch two (the print order: Central American, Chinese,
// Cthulhu, Egyptian)
inline int dptMythoi()
    { return 4; }

// the registry floor at 22f9d1b (the batch-one promotion land)
inline int dptFloorBefore()
    { return 1050; }

// the registry floor after this round (1050 + 68)
inline int dptFloorAfter()
    { return 1118; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dptFullFieldKeys()
    { return 57; }

// the monster-format rows promoted (Ma Yuan and the Spirits, the seven
// Cthulhu races, Apep, the Flame Snake, the Phoenix and the Minions of Set)
inline int dptMonsterRows()
    { return 13; }

// the hit-dice rows promoted (the seven Cthulhu races and the Flame Snake;
// the other monsters print hit points)
inline int dptHitDiceRows()
    { return 8; }

// the fixed-damage cells emitted (the pinned const figures and the
// primary-ink-verified cells; the Spirits of the Air figure is garbled in
// both voices and stays sentinel - flagged)
inline int dptPinnedDamage()
    { return 50; }

// the grid code for the printed See below (the magic-user cells, Cthugha,
// Isis, Kuan Yin)
inline int dptSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch two - the print-order
// continuation of batch one (Central American through Egyptian)
inline bool dptPromotionBatchTwo()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the dgf,
// dgg, cth and egp grids and consts; the pin rounds are the firewall)
inline bool dptFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// summon-list flags, the Set-enmity flags, the twin pairs, the Minion and
// Phoenix size and hit-point cells, the primary ink extract pages)
inline bool dptNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dptFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine unchanged: n/a strings, -1 ints,
// distinct from every real print value
inline bool dptSentinelsDistinct()
    { return true; }

// the prose fields (text, familyText, the specials) stay sentinel - the walk
// rounds pin the grids and the doctrine, not the prose
inline bool dptProseContractSide()
    { return true; }

// the damage field emits the adjudicated fixed-damage cells only: the pinned
// const figures and the primary-ink-verified cells; the Spirits garble stays
// sentinel - flagged for a pin amendment
inline bool dptDamagePinnedOnly()
    { return true; }

// the symbol and areaOfControl fields stay sentinel this batch - the walk
// rounds pinned no symbol grids for these four mythoi
inline bool dptSymbolsUnpinned()
    { return true; }

// the worshippersAlignment field stays sentinel this batch - the dgf, dgg,
// cth and egp headers pin no worshipper-alignment grids (the prints read All
// alignments, Warriors, Chaotics of all types and the like) - flagged for a
// pin amendment
inline bool dptWorshipUnpinned()
    { return true; }

// tools/normalize_registry.py accepts the DDG source book (the R880 book_of
// patch) - the census and the idempotent rewrite cover the promoted defs
inline bool dptNormalizerDdgAware()
    { return true; }

// ---- the batch-two grids ----

// The mythos ordinals (0-3, the print order: Central American, Chinese,
// Cthulhu, Egyptian)
inline int dptMythOrd(int b)
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
        default:
            return -1;
        }
    }

// The first print page of the mythos (the folio offset PRINT = PDF - 1)
inline int dptMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 32;
        case 1:
            return 37;
        case 2:
            return 43;
        case 3:
            return 49;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dptMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 36;
        case 1:
            return 42;
        case 2:
            return 47;
        case 3:
            return 55;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dptMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 18;
        case 2:
            return 15;
        case 3:
            return 21;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dptKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 68)
inline int dptKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 68;
        case 1:
            return 68;
        case 2:
            return 68;
        case 3:
            return 68;
        case 4:
            return 68;
        case 5:
            return 68;
        case 6:
            return 68;
        case 7:
            return 68;
        case 8:
            return 68;
        case 9:
            return 68;
        case 10:
            return 68;
        case 11:
            return 68;
        case 12:
            return 68;
        case 13:
            return 68;
        case 14:
            return 68;
        case 15:
            return 68;
        case 16:
            return 68;
        case 17:
            return 68;
        case 18:
            return 68;
        case 19:
            return 68;
        case 20:
            return 68;
        case 21:
            return 68;
        case 22:
            return 68;
        case 23:
            return 68;
        case 24:
            return 68;
        case 25:
            return 68;
        case 26:
            return 68;
        case 27:
            return 68;
        case 28:
            return 68;
        case 29:
            return 68;
        case 30:
            return 68;
        case 31:
            return 68;
        case 32:
            return 68;
        case 33:
            return 68;
        case 34:
            return 68;
        case 35:
            return 68;
        case 36:
            return 68;
        case 37:
            return 68;
        case 38:
            return 68;
        case 39:
            return 68;
        case 40:
            return 68;
        case 41:
            return 68;
        case 42:
            return 68;
        case 43:
            return 68;
        case 44:
            return 68;
        case 45:
            return 68;
        case 46:
            return 68;
        case 47:
            return 68;
        case 48:
            return 68;
        case 49:
            return 68;
        case 50:
            return 68;
        case 51:
            return 68;
        case 52:
            return 68;
        case 53:
            return 68;
        case 54:
            return 68;
        case 55:
            return 68;
        case 56:
            return 68;
        default:
            return -1;
        }
    }

}   // namespace rules
