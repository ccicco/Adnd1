// =========================================================================================
// Adnd1 - rules/rsc.h
// The registry schema - the maintenance-arc opener: the FINAL post-DDG schema
// (57 keys) lands with the uniform loader coercers and the idempotent
// normalize_registry.py tool; the book rounds then rewrite all 995 defs
// full-field, sentinel doctrine (n/a strings, -1 ints, distinct from print),
// ahead of the DDG lua promotion from the adjudicated pin headers.
// census 801 -> 802.
//
// Verified at HEAD 7f44709: the live registry holds 995 defs (MM1 408, MM2
// 332, FF 185, OA 47, WSG 15, MOP 8), SPARSE emission - the 40-key mm2lua
// FIELD_ORDER plus the eight adjustment keys the promotion seams added
// (saveAs, saveAsBonus, loadNormal, loadMax, rank, plane, transform,
// wsgRoles); the pre-normalization key census is pinned in the key-census
// grid. The DDG keys ride as schema adjustments per the doctrine (the DMO
// rank-field precedent; class levels raw + cooked; hit POINTS not dice). The
// queue per Curtiss 2026-10-27: the maintenance arc FIRST, then the DDG lua
// promotion.
//
// The sentinels are distinct from every real print value: n/a for strings, -1
// for ints; the printed Nil and None are REAL values and stay. The audits
// read the sentinels exactly, so fail-on-wrong stays honest.
//
namespace rules {

// ---- the maintenance-arc census ----

// the registry schema round: the maintenance-arc opener - the D&DG walk is
// complete (24/0, R878), the queue is the arc first, the DDG lua promotion
// after (Curtiss 2026-10-27)
inline int rscRound()
    { return 879; }

// the battery census before the round
inline int rscCensusBefore()
    { return 801; }

// the battery census after the round
inline int rscCensusAfter()
    { return 802; }

// the FINAL post-DDG schema: 57 keys, the one shape every def of every book
// normalizes to
inline int rscSchemaKeys()
    { return 57; }

// the mm2lua.py base field order (MM1)
inline int rscFieldOrderBase()
    { return 40; }

// the schema-adjustment keys the promotion seams added: saveAs, saveAsBonus,
// loadNormal, loadMax, rank, plane, transform, wsgRoles
inline int rscAdjustmentKeys()
    { return 8; }

// the DDG keys the deity promotion feeds: divineRank, worshippersAlignment,
// symbol, areaOfControl, classLevelsRaw, classLevelsCooked, hitPointsRaw,
// hitPoints, hitPointsNote
inline int rscDdgKeys()
    { return 9; }

// the int-valued keys of the schema (the string keys take the n/a sentinel,
// these take -1)
inline int rscIntKeys()
    { return 13; }

// the registry floor at HEAD 7f44709: zero registry defs touched by the D&DG
// rounds R849-R878
inline int rscRegistryFloor()
    { return 995; }

// the books in the live registry: MM1, MM2, FF, OA, WSG, MOP
inline int rscBookCount()
    { return 6; }

// ---- the schema doctrine ----

// this round OPENS the maintenance arc: the schema lands, the coercers land,
// the normalizer tool lands; the book rounds then rewrite the defs one book
// at a time
inline bool rscArcOpener()
    { return true; }

// full-field emission: every def of every book carries every key - the census
// audit gate closes at the tail book round
inline bool rscFullFieldEmission()
    { return true; }

// the defs at HEAD are SPARSE (the pre-normalization census is pinned in the
// key-census grid and doc/data/registry_census.txt); the book rounds erase
// the sparsity
inline bool rscSparseAtHead()
    { return true; }

// the sentinels are distinct from every real print value: n/a for strings, -1
// for ints; the printed Nil and None are REAL values and stay
inline bool rscSentinelsDistinct()
    { return true; }

// the new-field coercers ride the arc - one uniform pass in MonsterRegistry,
// no per-book special-casing in the coercers
inline bool rscLoaderUniform()
    { return true; }

// the normalizer is byte-stable and idempotent: a second run over a
// normalized def changes nothing (the DO-NOT-HAND-EDIT doctrine holds)
inline bool rscNormalizerByteStable()
    { return true; }

// the DDG defs generate ONLY from the adjudicated pin headers (the
// promotion-from-headers doctrine) - never straight from extraction; the pin
// rounds are the firewall
inline bool rscPromotionFromHeaders()
    { return true; }

// the pin headers stay the print-fidelity record; this round touches zero of
// them
inline bool rscPinHeadersUntouched()
    { return true; }

// zero DDG defs exist at HEAD; the promotion rounds create them after the
// book rounds close the schema pass
inline bool rscDdgDefsPending()
    { return true; }

// ---- the book census ----

// The book ordinals (0-5: MM1, MM2, FF, OA, WSG, MOP)
inline int rscBookOrd(int b)
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
        default:
            return -1;
        }
    }

// The def counts at HEAD 7f44709 (the registry floor 995)
inline int rscBookDefs(int b)
    {
        switch (b) {
        case 0:
            return 408;
        case 1:
            return 332;
        case 2:
            return 185;
        case 3:
            return 47;
        case 4:
            return 15;
        case 5:
            return 8;
        default:
            return -1;
        }
    }

// ---- the key census ----

// The key ordinals (0-56, the FIELD_ORDER walk)
inline int rscKOrd(int b)
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

// MM1: the defs carrying the key at HEAD
inline int rscKMm1(int b)
    {
        switch (b) {
        case 0:
            return 408;
        case 1:
            return 10;
        case 2:
            return 408;
        case 3:
            return 408;
        case 4:
            return 408;
        case 5:
            return 185;
        case 6:
            return 408;
        case 7:
            return 50;
        case 8:
            return 10;
        case 9:
            return 408;
        case 10:
            return 306;
        case 11:
            return 306;
        case 12:
            return 306;
        case 13:
            return 408;
        case 14:
            return 400;
        case 15:
            return 408;
        case 16:
            return 408;
        case 17:
            return 365;
        case 18:
            return 346;
        case 19:
            return 288;
        case 20:
            return 408;
        case 21:
            return 1;
        case 22:
            return 408;
        case 23:
            return 408;
        case 24:
            return 408;
        case 25:
            return 408;
        case 26:
            return 408;
        case 27:
            return 408;
        case 28:
            return 408;
        case 29:
            return 408;
        case 30:
            return 408;
        case 31:
            return 408;
        case 32:
            return 408;
        case 33:
            return 408;
        case 34:
            return 408;
        case 35:
            return 408;
        case 36:
            return 270;
        case 37:
            return 181;
        case 38:
            return 0;
        case 39:
            return 34;
        case 40:
            return 5;
        case 41:
            return 1;
        case 42:
            return 3;
        case 43:
            return 3;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 3;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

// MM2: the defs carrying the key at HEAD
inline int rscKMm2(int b)
    {
        switch (b) {
        case 0:
            return 332;
        case 1:
            return 0;
        case 2:
            return 332;
        case 3:
            return 332;
        case 4:
            return 332;
        case 5:
            return 0;
        case 6:
            return 332;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 331;
        case 10:
            return 332;
        case 11:
            return 331;
        case 12:
            return 331;
        case 13:
            return 332;
        case 14:
            return 331;
        case 15:
            return 0;
        case 16:
            return 332;
        case 17:
            return 328;
        case 18:
            return 328;
        case 19:
            return 328;
        case 20:
            return 332;
        case 21:
            return 0;
        case 22:
            return 331;
        case 23:
            return 331;
        case 24:
            return 331;
        case 25:
            return 0;
        case 26:
            return 331;
        case 27:
            return 331;
        case 28:
            return 331;
        case 29:
            return 331;
        case 30:
            return 331;
        case 31:
            return 331;
        case 32:
            return 331;
        case 33:
            return 331;
        case 34:
            return 331;
        case 35:
            return 331;
        case 36:
            return 332;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 5;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

// FF: the defs carrying the key at HEAD
inline int rscKFf(int b)
    {
        switch (b) {
        case 0:
            return 185;
        case 1:
            return 0;
        case 2:
            return 185;
        case 3:
            return 185;
        case 4:
            return 185;
        case 5:
            return 0;
        case 6:
            return 185;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 185;
        case 10:
            return 185;
        case 11:
            return 185;
        case 12:
            return 185;
        case 13:
            return 185;
        case 14:
            return 185;
        case 15:
            return 0;
        case 16:
            return 185;
        case 17:
            return 185;
        case 18:
            return 185;
        case 19:
            return 185;
        case 20:
            return 185;
        case 21:
            return 0;
        case 22:
            return 185;
        case 23:
            return 185;
        case 24:
            return 185;
        case 25:
            return 0;
        case 26:
            return 185;
        case 27:
            return 185;
        case 28:
            return 185;
        case 29:
            return 185;
        case 30:
            return 185;
        case 31:
            return 185;
        case 32:
            return 185;
        case 33:
            return 185;
        case 34:
            return 185;
        case 35:
            return 185;
        case 36:
            return 185;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

// OA: the defs carrying the key at HEAD
inline int rscKOa(int b)
    {
        switch (b) {
        case 0:
            return 47;
        case 1:
            return 0;
        case 2:
            return 47;
        case 3:
            return 47;
        case 4:
            return 47;
        case 5:
            return 0;
        case 6:
            return 47;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 47;
        case 10:
            return 45;
        case 11:
            return 45;
        case 12:
            return 44;
        case 13:
            return 47;
        case 14:
            return 47;
        case 15:
            return 0;
        case 16:
            return 47;
        case 17:
            return 47;
        case 18:
            return 47;
        case 19:
            return 47;
        case 20:
            return 47;
        case 21:
            return 0;
        case 22:
            return 47;
        case 23:
            return 47;
        case 24:
            return 47;
        case 25:
            return 0;
        case 26:
            return 47;
        case 27:
            return 47;
        case 28:
            return 47;
        case 29:
            return 47;
        case 30:
            return 47;
        case 31:
            return 47;
        case 32:
            return 47;
        case 33:
            return 47;
        case 34:
            return 47;
        case 35:
            return 47;
        case 36:
            return 47;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

// WSG: the defs carrying the key at HEAD
inline int rscKWsg(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 0;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 0;
        case 6:
            return 15;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
        case 10:
            return 15;
        case 11:
            return 15;
        case 12:
            return 15;
        case 13:
            return 15;
        case 14:
            return 15;
        case 15:
            return 0;
        case 16:
            return 15;
        case 17:
            return 15;
        case 18:
            return 15;
        case 19:
            return 15;
        case 20:
            return 15;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 15;
        case 24:
            return 15;
        case 25:
            return 0;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 15;
        case 29:
            return 15;
        case 30:
            return 15;
        case 31:
            return 15;
        case 32:
            return 15;
        case 33:
            return 15;
        case 34:
            return 15;
        case 35:
            return 15;
        case 36:
            return 15;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 15;
        case 43:
            return 15;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 15;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

// MOP: the defs carrying the key at HEAD
inline int rscKMop(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 0;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 0;
        case 6:
            return 8;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 8;
        case 10:
            return 8;
        case 11:
            return 8;
        case 12:
            return 8;
        case 13:
            return 8;
        case 14:
            return 8;
        case 15:
            return 0;
        case 16:
            return 8;
        case 17:
            return 8;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 8;
        case 21:
            return 0;
        case 22:
            return 8;
        case 23:
            return 8;
        case 24:
            return 8;
        case 25:
            return 0;
        case 26:
            return 8;
        case 27:
            return 8;
        case 28:
            return 8;
        case 29:
            return 8;
        case 30:
            return 8;
        case 31:
            return 8;
        case 32:
            return 8;
        case 33:
            return 8;
        case 34:
            return 8;
        case 35:
            return 8;
        case 36:
            return 8;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 8;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        default:
            return -1;
        }
    }

}   // namespace rules
