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

// R402: the UA pin rounds HAVE
// landed (R375, R395, R397) -
// the dial rides; the charge
// follows.
inline bool uatdUaPinRoundsPending()
    { return false; }

// ---- the carrier contract ----
// Both table sets ride: DMG and
// UA.
inline int uatdTableSetCount()
    { return 2; }

// The MERGED mode carries both.
inline bool uatdMergedCarriesBoth()
    { return true; }

// ---- R402: the runtime dial ----
// The mode state rides a static
// (the DMG default until
// playtesting picks); the setter
// gates on the validity.
inline int& uatdModeRef() {
    static int m = uatdDefaultMode();
    return m;
}

// The current dial mode.
inline int uatdMode()
    { return uatdModeRef(); }

inline bool uatdModeValid(int m)
    { return m >= 0 &&
      m < uatdModeCount(); }

// Set the dial (an invalid ask
// falls back to the default).
inline void uatdSetMode(int m) {
    if (!uatdModeValid(m))
        m = uatdDefaultMode();
    uatdModeRef() = m;
}

inline const char* uatdModeName(int m) {
    static const char* const k[3] = {
        "DMG", "UA", "MERGED"
    };
    if (m < 0) m = 0;
    if (m > 2) m = 2;
    return k[m];
}

// R402: the dial governs the
// random determination dispatch
// (the magic item roll); the
// landed DMG audits stay
// authoritative under the
// default mode.
inline bool uatdDialLanded()
    { return true; }

}   // namespace rules

