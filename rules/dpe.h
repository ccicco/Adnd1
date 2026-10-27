// =========================================================================================
// Adnd1 - rules/dpe.h
// The DDG lua promotion, batch one - 55 full-field defs (American Indian 14,
// Arthurian 15, Babylonian 10, Celtic 16) generated ONLY from the adjudicated
// pin headers, the registry floor 995 -> 1050.
// census 802 -> 803.
//
// Generated from rules/dgb.h, dgc.h, dgd.h and dge.h at dbe3170: the four
// grids x rows (combat, class, ability, roster), the being name orders locked
// by the pinned cross-references and verified against the primary ink extract
// pages; the legend tables decode verbatim from the header comments; the
// unpinned cells emit the sentinels.
//
// The sentinels ride the R879 doctrine unchanged: n/a for strings, -1 for
// ints, distinct from every real print value; the printed See below,
// Standard, Nil and Infinite are REAL values and stay. The audits read the
// sentinels exactly, so fail-on-wrong stays the rule.
//
namespace rules {

// ---- the promotion census ----

// the DDG lua promotion round, batch one: the American Indian, Arthurian,
// Babylonian and Celtic mythoi (Curtiss 2026-10-27: the promotion after the
// arc opener)
inline int dpeRound()
    { return 880; }

// the audit census at dbe3170 (the R879 land)
inline int dpeCensusBefore()
    { return 802; }

// the audit census after this round (one new audit line, the batch-one
// promotion audit)
inline int dpeCensusAfter()
    { return 803; }

// the promoted defs this round: 14 + 15 + 10 + 16, one per adjudicated
// stat-block row
inline int dpeDefs()
    { return 55; }

// the mythoi of batch one (the print order: American Indian, Arthurian,
// Babylonian, Celtic)
inline int dpeMythoi()
    { return 4; }

// the registry floor at dbe3170 (the arc opener touched zero defs)
inline int dpeFloorBefore()
    { return 995; }

// the registry floor after this round (995 + 55)
inline int dpeFloorAfter()
    { return 1050; }

// ---- the promotion doctrine ----

// every DDG def carries every key of the final schema (the R879 57-key
// FIELD_ORDER)
inline int dpeFullFieldKeys()
    { return 57; }

// the pinned fixed-damage figures emitted (the dgb strength bonuses ride the
// damage field one-for-one; Merlin and Morgan; the six Babylonian figures)
inline int dpePinnedDamage()
    { return 8; }

// the grid code for the printed See below (the magic-user cells, Nergal magic
// resistance, Bernlad armor class)
inline int dpeSeeBelowCode()
    { return 99; }

// this round is the DDG lua promotion, batch one - the first registry growth
// since the 995 floor
inline bool dpePromotionBatchOne()
    { return true; }

// every value is generated ONLY from the adjudicated pin headers (the dgb,
// dgc, dgd and dge grids and consts; the pin rounds are the firewall)
inline bool dpeFromHeadersOnly()
    { return true; }

// the being-to-row name orders are locked by the pinned cross-references (the
// 3/2 attacks comment, the Standard magic-resistance trio, the CH -1 and CH 6
// cells, the Thunder Bird xp, the primary ink extract pages)
inline bool dpeNameOrdersLocked()
    { return true; }

// every promoted def is full-field: all 57 keys, the sentinels where the
// print or the headers pin nothing
inline bool dpeFullFieldDdg()
    { return true; }

// the sentinels ride the R879 doctrine unchanged: n/a strings, -1 ints,
// distinct from every real print value
inline bool dpeSentinelsDistinct()
    { return true; }

// the prose fields (text, familyText, the specials) stay sentinel - the walk
// rounds pin the grids and the doctrine, not the prose
inline bool dpeProseContractSide()
    { return true; }

// the damage field emits only the pinned figures; an unpinned stat-block
// figure stays the sentinel (the eleven Celtic figures were never adjudicated
// into the header)
inline bool dpeDamagePinnedOnly()
    { return true; }

// the symbol and areaOfControl fields stay sentinel this batch - the walk
// rounds pinned no symbol grids for these four mythoi
inline bool dpeSymbolsUnpinned()
    { return true; }

// ---- the grid widths ----

// the class-grid columns the classLevels fields cook (cleric through bard)
inline int dpeClassGridCols()
    { return 10; }

// the ability-grid columns (the strength triplet, the six scores, the psionic
// cells)
inline int dpeAbilityGridCols()
    { return 9; }

// tools/normalize_registry.py accepts the DDG source book (the book_of patch)
// - the census and the idempotent rewrite cover the promoted defs
inline bool dpeNormalizerDdgAware()
    { return true; }

// tools/splice_engine.py makedirs before a data-file write (the R851 lesson:
// the lettered registry subdirectories of the promoted defs are new paths)
inline bool dpeEngineMakedirs()
    { return true; }

// ---- the batch-one grids ----

// The mythos ordinals (0-3, the print order: American Indian, Arthurian,
// Babylonian, Celtic)
inline int dpeMythOrd(int b)
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
inline int dpeMythPageLo(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 17;
        case 2:
            return 22;
        case 3:
            return 26;
        default:
            return -1;
        }
    }

// The last print page of the mythos
inline int dpeMythPageHi(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 21;
        case 2:
            return 25;
        case 3:
            return 31;
        default:
            return -1;
        }
    }

// The promoted defs of the mythos (one per adjudicated stat-block row)
inline int dpeMythDefs(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 15;
        case 2:
            return 10;
        case 3:
            return 16;
        default:
            return -1;
        }
    }

// The key ordinals (0-56, the R879 FIELD_ORDER walk)
inline int dpeKeyOrd(int b)
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

// The DDG defs carrying the key (every def full-field: 57 x 55)
inline int dpeKeyDdgCount(int b)
    {
        switch (b) {
        case 0:
            return 55;
        case 1:
            return 55;
        case 2:
            return 55;
        case 3:
            return 55;
        case 4:
            return 55;
        case 5:
            return 55;
        case 6:
            return 55;
        case 7:
            return 55;
        case 8:
            return 55;
        case 9:
            return 55;
        case 10:
            return 55;
        case 11:
            return 55;
        case 12:
            return 55;
        case 13:
            return 55;
        case 14:
            return 55;
        case 15:
            return 55;
        case 16:
            return 55;
        case 17:
            return 55;
        case 18:
            return 55;
        case 19:
            return 55;
        case 20:
            return 55;
        case 21:
            return 55;
        case 22:
            return 55;
        case 23:
            return 55;
        case 24:
            return 55;
        case 25:
            return 55;
        case 26:
            return 55;
        case 27:
            return 55;
        case 28:
            return 55;
        case 29:
            return 55;
        case 30:
            return 55;
        case 31:
            return 55;
        case 32:
            return 55;
        case 33:
            return 55;
        case 34:
            return 55;
        case 35:
            return 55;
        case 36:
            return 55;
        case 37:
            return 55;
        case 38:
            return 55;
        case 39:
            return 55;
        case 40:
            return 55;
        case 41:
            return 55;
        case 42:
            return 55;
        case 43:
            return 55;
        case 44:
            return 55;
        case 45:
            return 55;
        case 46:
            return 55;
        case 47:
            return 55;
        case 48:
            return 55;
        case 49:
            return 55;
        case 50:
            return 55;
        case 51:
            return 55;
        case 52:
            return 55;
        case 53:
            return 55;
        case 54:
            return 55;
        case 55:
            return 55;
        case 56:
            return 55;
        default:
            return -1;
        }
    }

}   // namespace rules
