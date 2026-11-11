// =========================================================================================
// Adnd1 - rules/ddg/legends_lore_parity.h
// The deity seam close - the Legends & Lore 1984 parity voice adjudicated in
// full, the seam leaves the queue with NO divergence round
// census 948 -> 949.
//
// The seam close (the R1025 registry close leaves the deity seam as the one
// standing queue item, the arc plan's at-go check now run): the L&L parity
// inventory swept the pin headers in full - 130 parity notes across the
// mythos grids (cqc through cqc8, nrs, smr, nhg, nhw, tpl, pln, dga, deities,
// elysiumbeasts, dpy, dpz) and every one falls into an adjudicated class -
// pinned by print over the L&L read, the print garbles restored from the L&L
// voice, the eyeball flags deliberate pin-internal, the tesseract-geometry
// cells verified, ZERO open divergences; the collation voice throughout was
// the 1eonline L&L per-deity chart rows, so NO archive.org derivative
// tesseract pass is needed - the primary ink (the ddg.pdf second printing,
// the 310 extract/ddg voices on disk) plus the chart rows carried the whole
// arc; the at-most-one divergence round is NOT needed and L&L stands as a
// parity voice, not a second book. The DDG gap report holds 24 boxes closed,
// zero open; the 338 DDG defs ride canonical full-field since R1025 - the
// registry 1338 of 1338. THE DEITY SEAM CLOSES.
//
namespace rules {

// ---- the seam frame ----

// the deity seam close - the queue's one standing item after the R1025
// registry close
inline int ll1Round()
    { return 1026; }

// the DDG defs riding canonical full-field since R1025 - the whole 17-mythoi
// promotion
inline int ll1DdgDefsCanonical()
    { return 338; }

// the registry canonical at the seam close - every def of the census carries
// the full-field emission
inline int ll1RegistryCanonical()
    { return 1338; }

// ---- the parity census ----

// the L&L parity notes across the pin headers - the 1eonline chart-row voice
// cited per adjudication
inline int ll1ParityNotes()
    { return 130; }

// the print garbles restored from the L&L voice - the jade green, the laurel
// wreath, the kilt, the name glyph restorations
inline int ll1PrintRestores()
    { return 8; }

// the eyeball flags - deliberate pin-internal flags, adjudicated in place
// (the Seker row duplicate, the bare-cell reads)
inline int ll1EyeballFlags()
    { return 3; }

// the parity notes adjudicated - every note pinned by print, restored,
// flagged or geometry-verified, NONE left open
inline int ll1ParityAdjudicated()
    { return 130; }

// the open divergences - NONE, the at-most-one divergence round NOT needed
inline int ll1OpenDivergences()
    { return 0; }

// the archive.org derivative tesseract voices needed - ZERO, the primary ink
// plus the 1eonline chart rows carried the arc
inline int ll1DerivativeVoices()
    { return 0; }

// ---- the seam close ----

// THE DEITY SEAM CLOSES - L&L a parity voice, not a second book; the queue
// stands empty
inline bool ll1SeamClosed()
    { return true; }

// the divergence round not needed - zero open divergences in the full
// 130-note inventory
inline bool ll1NoDivergenceRound()
    { return true; }

// the D&DG second-printing primary ink intact - the 310 extract/ddg voices on
// disk, the 24 gap boxes closed, the census verified at HEAD
inline bool ll1PrimaryInkIntact()
    { return true; }

}   // namespace rules
