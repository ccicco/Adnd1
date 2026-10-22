// =========================================================================================
// Adnd1 - rules/saddle.h
// THE SADDLE ACQUISITION - the town stable writes the mount, the save carries
// the line
// census 699 -> 700.
//
// The R776 site left mountKind a seam nothing writes. This round wires the
// writer: the town stable sells the pinned R300 livestock horse rows (heavy
// war, medium war, light war, riding, pony - the cells eqcGeneralGold already
// pins, read by name plus the tack saddle) best-affordable-first to the first
// living member afoot; the save format gains the optional "mount" line (the
// v1 compat rule: absent line loads afoot); and the kind ladder is pinned
// here (0 afoot, 1 draft, 2 light war, 3 medium war, 4 heavy war, 5 riding, 6
// pony). The grant path is honestly out: no cavalier or paladin class exists
// in the engine, so the flying-steed grants (mml 7/9/11) stay contract-side
// until a class round lands. All four touched TUs ride the preflight battery
// build, so every line is compile-gated
//
// Zero new book pages: the prices and rows ride the already-pinned R300/R308
// equipment cells
//
namespace rules {

// ---- the saddle acquisition (the R777 wiring) ----

// The kind ladder: 0 afoot plus the six mounts (draft, light war, medium war,
// heavy war, riding, pony).
inline int sddMountKindCount()
    { return 7; }

// The draft horse (not stocked - a cart animal, stable-unworthy but
// ladder-real).
inline int sddKindDraft()
    { return 1; }

// The light war horse.
inline int sddKindLightWar()
    { return 2; }

// The medium war horse.
inline int sddKindMediumWar()
    { return 3; }

// The heavy war horse.
inline int sddKindHeavyWar()
    { return 4; }

// The light riding horse.
inline int sddKindRiding()
    { return 5; }

// The pony.
inline int sddKindPony()
    { return 6; }

// The stable stocks five kinds (heavy war first, pony last - the
// best-affordable-first scan).
inline int sddStableStockCount()
    { return 5; }

// townBuyMount sells to the first living member afoot (appstate.h declares
// it).
inline bool sddTownStableSellsMounts()
    { return true; }

// The price reads the pinned equipcosts cells by NAME (eqcGeneralGold plus
// the tack saddle), never a hardcode.
inline bool sddStableReadsPinnedCells()
    { return true; }

// The save writes the optional "mount" line only when riding (the v1 compat
// rule).
inline bool sddSaveCarriesMountLine()
    { return true; }

// A v1 save carries no mount line and loads as afoot; a corrupt value outside
// the ladder dies at load.
inline bool sddV1SaveLoadsAfoot()
    { return true; }

}   // namespace rules
