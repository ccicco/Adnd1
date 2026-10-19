// =========================================================================================
// Adnd1 - rules/oafamstr.h
// FAMILY STRUCTURE AND ADDITIONAL FAMILY STRUCTURES, printed capture pp.
// 62-64 - the OA family structures round
// census 552 -> 553.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority per the R629 ruling): the first Mistral-OCR capture session is no
// longer available above p. 33, so the cross-capture agreement check is
// impossible for pp. 62-64. No tables this round, so no contested cells.
// Cites are the capture pp. 62-64 range (the per-fact printed pages cannot be
// isolated without the first capture). OCR normalization: splinterhood reads
// as spinsterhood; the deaths bad-feelings sentence appears twice in the 2018
// print (the second occurrence stands as printed); the Master Family Chart
// prose (capture pp. 64-65) is deliberately left for the next round
//
// the gap census after this round: 68 closed, 167 open - the Family Structure
// + Additional Family Structures box flips (census 552 -> 553); NEXT - R631:
// the Master Family Chart and Ancestry prose, capture pp. 64-65, Table 39
// (Ancestry), prefix dgr (verify free), audit "R631 OA ancestry audit",
// include after rules/oafamstr.h
//
namespace rules {

// ---- the family chart doctrine pins ----

// Family structure prose (capture pp. 62-64): the children per space roll 1d8
inline int dgqChildrenDiceSides()
    { return 8; }

// Family structure prose (capture pp. 62-64): the minus-2 on the children
// roll - negatives and zero mean no offspring
inline int dgqChildrenDiceMod()
    { return -2; }

// Family structure prose (capture pp. 62-64): the chart is only needed for
// the branch leading to the player character
inline bool dgqChartDirectBranchOnly()
    { return true; }

// Family structure prose (capture pp. 62-64): the lineage die most closely
// matches the spaces without being less - five spaces means 1d6
inline bool dgqLineageDieClosestNotLess()
    { return true; }

// Family structure prose (capture pp. 62-64): a lineage die roll greater than
// the spaces means roll again
inline bool dgqLineageRerollOverflow()
    { return true; }

// ---- the marriage and adoption pins ----

// Marriages prose (capture pp. 62-64): the marriage check die 1d6
inline int dgqMarriageDiceSides()
    { return 6; }

// Marriages prose (capture pp. 62-64): a female member marries on 1-5 on 1d6
inline int dgqMarriageRollMax()
    { return 5; }

// Marriages prose (capture pp. 62-64): the +10 percent reaction bonus from
// marriage-related NPCs
inline int dgqMarriageBonusPct()
    { return 10; }

// Adoptions prose (capture pp. 62-64): the 1-in-20 chance that any person
// entered the clan by adoption
inline int dgqAdoptChancePct()
    { return 5; }

// Adoptions prose (capture pp. 62-64): the orphan check die 1d6
inline int dgqAdoptDiceSides()
    { return 6; }

// Adoptions prose (capture pp. 62-64): an adopted member is an orphan on 1-2
// on 1d6
inline int dgqAdoptOrphanMax()
    { return 2; }

// Adoptions prose (capture pp. 62-64): the +10 percent reaction bonus with
// the adopted clan
inline int dgqAdoptBonusPct()
    { return 10; }

// Additional structures prose (capture pp. 62-64): the complications are
// optional and fleshed out gradually
inline bool dgqComplicationsOptional()
    { return true; }

// Marriages prose (capture pp. 62-64): player character females are never
// required to be married
inline bool dgqPcFemalesNeverRequired()
    { return true; }

// Marriages prose (capture pp. 62-64): the marriages are usually outside the
// family clan
inline bool dgqMarriageUsuallyOutsideClan()
    { return true; }

// Marriages prose (capture pp. 62-64): the marriages are usually between
// families of approximately equal rank
inline bool dgqMarriageEqualRank()
    { return true; }

// Adoptions prose (capture pp. 62-64): orphans are related only to the
// members of their adoptive family clan
inline bool dgqAdoptOrphansRelatedOnlyClan()
    { return true; }

// Adoptions prose (capture pp. 62-64): an adoption with the hereditary family
// alive leaves two family clans
inline bool dgqAdoptTwoClansWhenAlive()
    { return true; }

// Adoptions prose (capture pp. 62-64): the adoptions often cross birth ranks
// and are politically motivated
inline bool dgqAdoptOftenPolitical()
    { return true; }

// ---- the polygamy pins ----

// Polygamy prose (capture pp. 62-64): polygamy is legal and not unknown in
// the OA societies
inline bool dgqPolygamyLegal()
    { return true; }

// Polygamy prose (capture pp. 62-64): most marriages are monogamous
inline bool dgqPolygamyMostMonogamous()
    { return true; }

// Polygamy prose (capture pp. 62-64): only a polygamous grandfather or father
// has any effect
inline bool dgqPolygamyGrandfatherFatherOnly()
    { return true; }

// Polygamy prose (capture pp. 62-64): the first wife is most favored - her
// children are eligible for direct inheritance
inline bool dgqFirstWifeChildrenInherit()
    { return true; }

// Polygamy prose (capture pp. 62-64): as a rule the inheritance passes to the
// first son of the first wife
inline bool dgqInheritanceFirstSonFirstWife()
    { return true; }

// ---- the generations and interrelation pins ----

// Further generations prose (capture pp. 62-64): the ancestors beyond three
// generations give no reaction modifiers
inline bool dgqFurtherGenerationsNoModifier()
    { return true; }

// Interrelated prose (capture pp. 62-64): the interrelated player characters
// need the DM agreement
inline bool dgqInterrelatedDmApproval()
    { return true; }

// Interrelated prose (capture pp. 62-64): the interrelated characters must be
// of the same race - barbarians only with barbarians, samurai only with
// samurai
inline bool dgqInterrelatedSameRace()
    { return true; }

// Interrelated prose (capture pp. 62-64): the interrelated characters share
// the birth rank and the Head of Family spaces
inline bool dgqInterrelatedSameBirthRank()
    { return true; }

// Interrelated prose (capture pp. 62-64): the same chart slot only for twins
// - and one must be older
inline bool dgqInterrelatedTwinsOnly()
    { return true; }

// Interrelated prose (capture pp. 62-64): one Ancestry roll set for both, the
// holdings and names identical
inline bool dgqInterrelatedSharedAncestry()
    { return true; }

// Deaths prose (capture pp. 62-64): a dead player character re-enters as a
// brother or sister, no property, normal birthright rolls, at 1st level
inline bool dgqPcReentryFirstLevel()
    { return true; }

// ---- the deaths pins ----

// Deaths prose (capture pp. 62-64): the fate check once per game year
inline int dgqDeathCheckPerYear()
    { return 1; }

// Deaths prose (capture pp. 62-64): the Head of Family row death chance, 10
// percent
inline int dgqDeathHeadPct()
    { return 10; }

// Deaths prose (capture pp. 62-64): the Father row death chance, 7 percent
inline int dgqDeathFatherPct()
    { return 7; }

// Deaths prose (capture pp. 62-64): the Siblings row death chance, 5 percent
inline int dgqDeathSiblingPct()
    { return 5; }

// Deaths prose (capture pp. 62-64): the possessions pass to the firstborn son
// 75 percent of the time
inline int dgqDeathFirstbornPct()
    { return 75; }

// Deaths prose (capture pp. 62-64): the head title passes to the next
// brother, else the eldest son
inline bool dgqHeadTitleSuccession()
    { return true; }

}   // namespace rules
