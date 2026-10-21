// =========================================================================================
// Adnd1 - rules/oa105randtres.h
// OA TREASURE - THE RANDOM TREASURE DETERMINATION PROSE, printed capture p.
// 285 - the procedure round
// census 656 -> 657.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 187 closed, 48 open - the random treasure
// prose box flips (census 656 -> 657); NEXT - R735: Table 74: Monetary
// Treasure And Magical Items (capture p. 286), prefix dkw (verify free at the
// landing), audit "R735 OA Table 74 monetary treasure audit", include after
// rules/oa105randtres.h
//
namespace rules {

// ---- the procedure ----

// the procedure - the DMG procedure used to randomly determine treasures and
// magical items (print capture p. 285)
inline int dkvDMGProcedureUsed()
    { return 1; }

// the excepted table number - the Table 74 Monetary Treasure And Magical
// Items, the one DMG exception of the procedure (print capture p. 285)
inline int dkvExceptedTable74()
    { return 74; }

// the exception - the Table 74 Monetary Treasure And Magical Items excepted
// from the DMG procedure (print capture p. 285)
inline int dkvTable74TheException()
    { return 1; }

// the replacement rule - roll on the versions given here, not the tables
// printed in the DMG (print capture p. 285)
inline int dkvUseVersionsGivenHere()
    { return 1; }

// ---- the replacements ----

// the additional table number - the Table 86 Oriental Magical Items of this
// book (print capture p. 285)
inline int dkvOrientalItemsTable86()
    { return 86; }

// the additional table - the Table 86 Oriental Magical Items for randomly
// selecting the magical items described in this book (print capture p. 285)
inline int dkvAdditionalTable86()
    { return 1; }

// the DMG page of Table II.A. - the 120 replaced by Table II.A. (ORIENT)
// (print capture p. 285)
inline int dkvDMGPageTableIIA()
    { return 120; }

// the DMG page of Table III - the 121 replaced by Table III (ORIENT) (print
// capture p. 285)
inline int dkvDMGPageTableIII()
    { return 121; }

// the II.A. replacement - the Table II.A. (ORIENT) replacing the DMG Table
// II.A. (print capture p. 285)
inline int dkvIIAOrientReplacesDMG()
    { return 1; }

// the III replacement - the Table III (ORIENT) replacing the DMG Table III
// (print capture p. 285)
inline int dkvIIIOrientReplacesDMG()
    { return 1; }

// the scope - the replacements applying in the world of Oriental Adventures
// (print capture p. 285)
inline int dkvReplacementsInOAWorld()
    { return 1; }

}   // namespace rules
