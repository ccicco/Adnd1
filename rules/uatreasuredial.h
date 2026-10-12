// ===========================================================================
// Adnd1 - rules/uatreasuredial.h
// The UA TREASURE DIAL decision
// pins, R374: THE DECISION named
// in the gap report's treasure
// section (the UA random
// determination tables III.A
// through III.H REPLACE the DMG
// tables) resolves RUN BOTH - the
// engine carries the DMG and UA
// tables as switchable
// alternatives behind a dial and
// lets playtesting pick. The
// per-source precedent rides the
// monster file format. The UA pin
// rounds follow; the dial lands
// first, the charge after. The
// R219 and R220 seams ride the
// regtest audit, not here.
namespace rules {

// ---- the dial modes ----
// DMG: the landed audits stay
// authoritative (the default
// until the UA pin rounds land).
inline int uatdModeDmg() { return 0; }

// UA: the revised tables.
inline int uatdModeUa() { return 1; }

// MERGED: both table sets with
// the union rows.
inline int uatdModeMerged() { return 2; }

inline int uatdModeCount() { return 3; }

// The default mode: DMG.
inline int uatdDefaultMode()
    { return uatdModeDmg(); }

// ---- the decision ----
// RUN BOTH - decided.
inline bool uatdRunBothDecided()
    { return true; }

// The printed fact: the UA
// tables replace the DMG tables.
inline bool uatdUaTablesReplaceDmg()
    { return true; }

// The seventy landed DMG audits
// stay authoritative.
inline bool uatdDmgAuditsAuthoritative()
    { return true; }

// The audit rounds span R219
// through R287.
inline int uatdDmgAuditRoundFirst()
    { return 219; }

inline int uatdDmgAuditRoundLast()
    { return 287; }

// The monster file format
// already tracks source per
// record - the per-source
// precedent.
inline bool uatdMonsterFileTracksSource()
    { return true; }

// Playtesting picks.
inline bool uatdPlaytestingPicks()
    { return true; }

// The UA pin rounds have not
// landed yet - the dial lands
// first.
inline bool uatdUaPinRoundsPending()
    { return true; }

// ---- the carrier contract ----
// Both table sets ride: DMG and
// UA.
inline int uatdTableSetCount()
    { return 2; }

// The MERGED mode carries both.
inline bool uatdMergedCarriesBoth()
    { return true; }

}   // namespace rules

