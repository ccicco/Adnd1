// =========================================================================================
// Adnd1 - rules/oa111scrolls.h
// OA TREASURE - SCROLLS, printed capture p. 288 - the scroll notes round
// census 662 -> 663.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 193 closed, 42 open - the scrolls box
// flips (census 662 -> 663); NEXT - R741: Rods, Staves, and Wands (capture p.
// 288), prefix dlc (verify free at the landing), audit "R741 OA rods staves
// wands audit", include after rules/oa111scrolls.h
//
namespace rules {

// ---- the type determination ----

// the type determination - use the standard rules given in the DMG for the
// type of scroll found (print capture p. 288)
inline int dlbUseStandardDMGRules()
    { return 1; }

// the first mapping - treating magic-users as wu jen (print capture p. 288)
inline int dlbMagicUsersAsWuJen()
    { return 1; }

// the second mapping - treating clerics as shukenja (print capture p. 288)
inline int dlbClericsAsShukenja()
    { return 1; }

// ---- the gajin spells ----

// the gajin scroll percent - the 5% of all scrolls found containing gajin
// spells (print capture p. 288)
inline int dlbGajinScrollPct()
    { return 5; }

// the gajin spells - the 5% of all scrolls found containing gajin spells,
// either magic-user or clerical (print capture p. 288)
inline int dlbGajinSpellsFivePct()
    { return 1; }

// the usability - such spells usable by wu jen and shukenja respectively
// (print capture p. 288)
inline int dlbGajinUsedByWuJenShukenja()
    { return 1; }

// the spell books - the gajin spells even addable to the spell books in the
// case of the wu jen (print capture p. 288)
inline int dlbGajinAddedToSpellBooks()
    { return 1; }

// ---- the protection scrolls ----

// the protection from devils scroll - not commonly found in Oriental lands,
// the result rerolled (print capture p. 288)
inline int dlbProtectionFromDevilsRerolled()
    { return 1; }

// the protection from shapechangers scroll - including all hengeyokai and the
// spirit creatures able to change their form (print capture p. 288)
inline int dlbProtectionFromShapechangersScope()
    { return 1; }

// the protection from undead scroll - not commonly found in Oriental lands,
// the result rerolled (print capture p. 288)
inline int dlbProtectionFromUndeadRerolled()
    { return 1; }

}   // namespace rules
