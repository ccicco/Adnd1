// =========================================================================================
// Adnd1 - rules/oahold.h
// ASSIGNING ANCESTRAL HOLDINGS, printed capture pp. 67-68 - the OA holdings
// round
// census 554 -> 555.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. A pure-prose round
// with no tables and no numeric cells, so no contested cells can arise within
// the single source; every doctrine of the two capture paragraphs is pinned
// as a bool (the R431 prose codifies insight: no section is unpinnable). The
// Birthrights prose and Table 40 (capture pp. 68-69) are deliberately left
// for the next round
//
// the gap census after this round: 72 closed, 163 open - the Assigning
// Ancestral Holdings box flips (census 554 -> 555); NEXT - R633: the
// Birthrights prose and Table 40, capture pp. 68-69, the property-share,
// heirloom and cash-string doctrines, prefix dgt (verify free), audit "R633
// OA birthrights audit", include after rules/oahold.h
//
namespace rules {

// ---- the holdings ownership pins ----

// Ancestral holdings prose (capture pp. 67-68): the holdings are the property
// results gained on Table 39: Ancestry
inline bool dgsHoldingsAreT39Property()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): the holdings are
// automatically owned by some NPC of the family
inline bool dgsNpcAutoOwnership()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): never owned by a player
// character or his siblings at the start of the career
inline bool dgsNeverPcOwnedAtStart()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): the first ancestral holding
// is automatically held by the head of the family
inline bool dgsFirstHoldingToHead()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): any remaining holdings are
// assigned by random dice roll to NPCs on the Head of Family and Father rows
// of the Family Chart
inline bool dgsRemainderDiceAssignment()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): the assignment uses the
// method described for determining the character's position in the family
inline bool dgsPositionMethodUsed()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): a die roll greater than the
// number of spaces gives the property to the head of the family
inline bool dgsOverflowToHead()
    { return true; }

// ---- the holdings-use pins ----

// Ancestral holdings prose (capture pp. 67-68): clan ownership does not
// automatically grant the player character use of the property
inline bool dgsNoAutomaticPcUse()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): the player character must
// request permission of the NPC owner
inline bool dgsOwnerPermissionRequired()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): a reaction roll must still be
// made
inline bool dgsReactionRollStillMade()
    { return true; }

// Ancestral holdings prose (capture pp. 67-68): the DM can refuse requests
// not in keeping with his campaign
inline bool dgsDmMayRefuse()
    { return true; }

}   // namespace rules
