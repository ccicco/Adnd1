-- oa630: promoted from rules/oa/oafamstr.h (the FAMILY STRUCTURE AND ADDITIONAL FAMILY STRUCTURES, printed capture pp.);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 630,
  "prefix" = "oa630",
  "banner" = {
      "title" = "FAMILY STRUCTURE AND ADDITIONAL FAMILY STRUCTURES, printed capture pp.",
      "provenance" = "62-64 - the OA family structures round census 552 -> 553.  pinned from the 2018 print capture alone for this range (the settling authority per the R629 ruling): the first Mistral-OCR capture session is no longer available above p. 33, so the cross-capture agreement check is impossible for pp. 62-64. No tables this round, so no contested cells. Cites are the capture pp. 62-64 range (the per-fact printed pages cannot be isolated without the first capture). OCR normalization: splinterhood reads as spinsterhood; the deaths bad-feelings sentence appears twice in the 2018 print (the second occurrence stands as printed); the Master Family Chart prose (capture pp. 64-65) is deliberately left for the next round  the gap census after this round: 68 closed, 167 open - the Family Structure + Additional Family Structures box flips (census 552 -> 553); NEXT - R631: the Master Family Chart and Ancestry prose, capture pp. 64-65, Table 39 (Ancestry), prefix dgr (verify free), audit \"R631 OA ancestry audit\", include after rules/oa/oafamstr.h",
    },
  "consts" = { {
      "name" = "dgqChildrenDiceSides",
      "value" = 8,
      "comment" = "Family structure prose (capture pp. 62-64): the children per space roll 1d8",
    }, {
      "name" = "dgqChildrenDiceMod",
      "value" = -2,
      "comment" = "Family structure prose (capture pp. 62-64): the minus-2 on the children roll - negatives and zero mean no offspring",
    }, {
      "name" = "dgqMarriageDiceSides",
      "value" = 6,
      "comment" = "Marriages prose (capture pp. 62-64): the marriage check die 1d6",
    }, {
      "name" = "dgqMarriageRollMax",
      "value" = 5,
      "comment" = "Marriages prose (capture pp. 62-64): a female member marries on 1-5 on 1d6",
    }, {
      "name" = "dgqMarriageBonusPct",
      "value" = 10,
      "comment" = "Marriages prose (capture pp. 62-64): the +10 percent reaction bonus from marriage-related NPCs",
    }, {
      "name" = "dgqAdoptChancePct",
      "value" = 5,
      "comment" = "Adoptions prose (capture pp. 62-64): the 1-in-20 chance that any person entered the clan by adoption",
    }, {
      "name" = "dgqAdoptDiceSides",
      "value" = 6,
      "comment" = "Adoptions prose (capture pp. 62-64): the orphan check die 1d6",
    }, {
      "name" = "dgqAdoptOrphanMax",
      "value" = 2,
      "comment" = "Adoptions prose (capture pp. 62-64): an adopted member is an orphan on 1-2 on 1d6",
    }, {
      "name" = "dgqAdoptBonusPct",
      "value" = 10,
      "comment" = "Adoptions prose (capture pp. 62-64): the +10 percent reaction bonus with the adopted clan",
    }, {
      "name" = "dgqDeathCheckPerYear",
      "value" = 1,
      "comment" = "Deaths prose (capture pp. 62-64): the fate check once per game year",
    }, {
      "name" = "dgqDeathHeadPct",
      "value" = 10,
      "comment" = "Deaths prose (capture pp. 62-64): the Head of Family row death chance, 10 percent",
    }, {
      "name" = "dgqDeathFatherPct",
      "value" = 7,
      "comment" = "Deaths prose (capture pp. 62-64): the Father row death chance, 7 percent",
    }, {
      "name" = "dgqDeathSiblingPct",
      "value" = 5,
      "comment" = "Deaths prose (capture pp. 62-64): the Siblings row death chance, 5 percent",
    }, {
      "name" = "dgqDeathFirstbornPct",
      "value" = 75,
      "comment" = "Deaths prose (capture pp. 62-64): the possessions pass to the firstborn son 75 percent of the time",
    } },
  "bools" = { {
      "name" = "dgqChartDirectBranchOnly",
      "value" = true,
      "comment" = "Family structure prose (capture pp. 62-64): the chart is only needed for the branch leading to the player character",
    }, {
      "name" = "dgqLineageDieClosestNotLess",
      "value" = true,
      "comment" = "Family structure prose (capture pp. 62-64): the lineage die most closely matches the spaces without being less - five spaces means 1d6",
    }, {
      "name" = "dgqLineageRerollOverflow",
      "value" = true,
      "comment" = "Family structure prose (capture pp. 62-64): a lineage die roll greater than the spaces means roll again",
    }, {
      "name" = "dgqComplicationsOptional",
      "value" = true,
      "comment" = "Additional structures prose (capture pp. 62-64): the complications are optional and fleshed out gradually",
    }, {
      "name" = "dgqPcFemalesNeverRequired",
      "value" = true,
      "comment" = "Marriages prose (capture pp. 62-64): player character females are never required to be married",
    }, {
      "name" = "dgqMarriageUsuallyOutsideClan",
      "value" = true,
      "comment" = "Marriages prose (capture pp. 62-64): the marriages are usually outside the family clan",
    }, {
      "name" = "dgqMarriageEqualRank",
      "value" = true,
      "comment" = "Marriages prose (capture pp. 62-64): the marriages are usually between families of approximately equal rank",
    }, {
      "name" = "dgqAdoptOrphansRelatedOnlyClan",
      "value" = true,
      "comment" = "Adoptions prose (capture pp. 62-64): orphans are related only to the members of their adoptive family clan",
    }, {
      "name" = "dgqAdoptTwoClansWhenAlive",
      "value" = true,
      "comment" = "Adoptions prose (capture pp. 62-64): an adoption with the hereditary family alive leaves two family clans",
    }, {
      "name" = "dgqAdoptOftenPolitical",
      "value" = true,
      "comment" = "Adoptions prose (capture pp. 62-64): the adoptions often cross birth ranks and are politically motivated",
    }, {
      "name" = "dgqPolygamyLegal",
      "value" = true,
      "comment" = "Polygamy prose (capture pp. 62-64): polygamy is legal and not unknown in the OA societies",
    }, {
      "name" = "dgqPolygamyMostMonogamous",
      "value" = true,
      "comment" = "Polygamy prose (capture pp. 62-64): most marriages are monogamous",
    }, {
      "name" = "dgqPolygamyGrandfatherFatherOnly",
      "value" = true,
      "comment" = "Polygamy prose (capture pp. 62-64): only a polygamous grandfather or father has any effect",
    }, {
      "name" = "dgqFirstWifeChildrenInherit",
      "value" = true,
      "comment" = "Polygamy prose (capture pp. 62-64): the first wife is most favored - her children are eligible for direct inheritance",
    }, {
      "name" = "dgqInheritanceFirstSonFirstWife",
      "value" = true,
      "comment" = "Polygamy prose (capture pp. 62-64): as a rule the inheritance passes to the first son of the first wife",
    }, {
      "name" = "dgqFurtherGenerationsNoModifier",
      "value" = true,
      "comment" = "Further generations prose (capture pp. 62-64): the ancestors beyond three generations give no reaction modifiers",
    }, {
      "name" = "dgqInterrelatedDmApproval",
      "value" = true,
      "comment" = "Interrelated prose (capture pp. 62-64): the interrelated player characters need the DM agreement",
    }, {
      "name" = "dgqInterrelatedSameRace",
      "value" = true,
      "comment" = "Interrelated prose (capture pp. 62-64): the interrelated characters must be of the same race - barbarians only with barbarians, samurai only with samurai",
    }, {
      "name" = "dgqInterrelatedSameBirthRank",
      "value" = true,
      "comment" = "Interrelated prose (capture pp. 62-64): the interrelated characters share the birth rank and the Head of Family spaces",
    }, {
      "name" = "dgqInterrelatedTwinsOnly",
      "value" = true,
      "comment" = "Interrelated prose (capture pp. 62-64): the same chart slot only for twins - and one must be older",
    }, {
      "name" = "dgqInterrelatedSharedAncestry",
      "value" = true,
      "comment" = "Interrelated prose (capture pp. 62-64): one Ancestry roll set for both, the holdings and names identical",
    }, {
      "name" = "dgqPcReentryFirstLevel",
      "value" = true,
      "comment" = "Deaths prose (capture pp. 62-64): a dead player character re-enters as a brother or sister, no property, normal birthright rolls, at 1st level",
    }, {
      "name" = "dgqHeadTitleSuccession",
      "value" = true,
      "comment" = "Deaths prose (capture pp. 62-64): the head title passes to the next brother, else the eldest son",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgqChildrenDiceSides']() != 8  or m['dgqChildrenDiceMod']() != -2  or m['dgqMarriageDiceSides']() != 6  or m['dgqMarriageRollMax']() != 5  or m['dgqMarriageBonusPct']() != 10  or m['dgqAdoptChancePct']() != 5  or m['dgqAdoptDiceSides']() != 6  or m['dgqAdoptOrphanMax']() != 2  or m['dgqAdoptBonusPct']() != 10  or m['dgqDeathCheckPerYear']() != 1  or m['dgqDeathHeadPct']() != 10  or m['dgqDeathFatherPct']() != 7  or m['dgqDeathSiblingPct']() != 5  or m['dgqDeathFirstbornPct']() != 75  or  m['dgqChartDirectBranchOnly']() != 1  or  m['dgqLineageDieClosestNotLess']() != 1  or  m['dgqLineageRerollOverflow']() != 1  or  m['dgqComplicationsOptional']() != 1  or  m['dgqPcFemalesNeverRequired']() != 1  or  m['dgqMarriageUsuallyOutsideClan']() != 1  or  m['dgqMarriageEqualRank']() != 1  or  m['dgqAdoptOrphansRelatedOnlyClan']() != 1  or  m['dgqAdoptTwoClansWhenAlive']() != 1  or  m['dgqAdoptOftenPolitical']() != 1  or  m['dgqPolygamyLegal']() != 1  or  m['dgqPolygamyMostMonogamous']() != 1  or  m['dgqPolygamyGrandfatherFatherOnly']() != 1  or  m['dgqFirstWifeChildrenInherit']() != 1  or  m['dgqInheritanceFirstSonFirstWife']() != 1  or  m['dgqFurtherGenerationsNoModifier']() != 1  or  m['dgqInterrelatedDmApproval']() != 1  or  m['dgqInterrelatedSameRace']() != 1  or  m['dgqInterrelatedSameBirthRank']() != 1  or  m['dgqInterrelatedTwinsOnly']() != 1  or  m['dgqInterrelatedSharedAncestry']() != 1  or  m['dgqPcReentryFirstLevel']() != 1  or  m['dgqHeadTitleSuccession']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgqChildrenDiceSides']() != 8",
      "note" = "the dgqChildrenDiceSides pin",
    }, {
      "expr" = "m['dgqChildrenDiceMod']() != -2",
      "note" = "the dgqChildrenDiceMod pin",
    }, {
      "expr" = "m['dgqMarriageDiceSides']() != 6",
      "note" = "the dgqMarriageDiceSides pin",
    }, {
      "expr" = "m['dgqMarriageRollMax']() != 5",
      "note" = "the dgqMarriageRollMax pin",
    }, {
      "expr" = "m['dgqMarriageBonusPct']() != 10",
      "note" = "the dgqMarriageBonusPct pin",
    }, {
      "expr" = "m['dgqAdoptChancePct']() != 5",
      "note" = "the dgqAdoptChancePct pin",
    }, {
      "expr" = "m['dgqAdoptDiceSides']() != 6",
      "note" = "the dgqAdoptDiceSides pin",
    }, {
      "expr" = "m['dgqAdoptOrphanMax']() != 2",
      "note" = "the dgqAdoptOrphanMax pin",
    }, {
      "expr" = "m['dgqAdoptBonusPct']() != 10",
      "note" = "the dgqAdoptBonusPct pin",
    }, {
      "expr" = "m['dgqDeathCheckPerYear']() != 1",
      "note" = "the dgqDeathCheckPerYear pin",
    }, {
      "expr" = "m['dgqDeathHeadPct']() != 10",
      "note" = "the dgqDeathHeadPct pin",
    }, {
      "expr" = "m['dgqDeathFatherPct']() != 7",
      "note" = "the dgqDeathFatherPct pin",
    }, {
      "expr" = "m['dgqDeathSiblingPct']() != 5",
      "note" = "the dgqDeathSiblingPct pin",
    }, {
      "expr" = "m['dgqDeathFirstbornPct']() != 75",
      "note" = "the dgqDeathFirstbornPct pin",
    }, {
      "expr" = "m['dgqChartDirectBranchOnly']() != 1",
      "note" = "the dgqChartDirectBranchOnly pin",
    }, {
      "expr" = "m['dgqLineageDieClosestNotLess']() != 1",
      "note" = "the dgqLineageDieClosestNotLess pin",
    }, {
      "expr" = "m['dgqLineageRerollOverflow']() != 1",
      "note" = "the dgqLineageRerollOverflow pin",
    }, {
      "expr" = "m['dgqComplicationsOptional']() != 1",
      "note" = "the dgqComplicationsOptional pin",
    }, {
      "expr" = "m['dgqPcFemalesNeverRequired']() != 1",
      "note" = "the dgqPcFemalesNeverRequired pin",
    }, {
      "expr" = "m['dgqMarriageUsuallyOutsideClan']() != 1",
      "note" = "the dgqMarriageUsuallyOutsideClan pin",
    }, {
      "expr" = "m['dgqMarriageEqualRank']() != 1",
      "note" = "the dgqMarriageEqualRank pin",
    }, {
      "expr" = "m['dgqAdoptOrphansRelatedOnlyClan']() != 1",
      "note" = "the dgqAdoptOrphansRelatedOnlyClan pin",
    }, {
      "expr" = "m['dgqAdoptTwoClansWhenAlive']() != 1",
      "note" = "the dgqAdoptTwoClansWhenAlive pin",
    }, {
      "expr" = "m['dgqAdoptOftenPolitical']() != 1",
      "note" = "the dgqAdoptOftenPolitical pin",
    }, {
      "expr" = "m['dgqPolygamyLegal']() != 1",
      "note" = "the dgqPolygamyLegal pin",
    }, {
      "expr" = "m['dgqPolygamyMostMonogamous']() != 1",
      "note" = "the dgqPolygamyMostMonogamous pin",
    }, {
      "expr" = "m['dgqPolygamyGrandfatherFatherOnly']() != 1",
      "note" = "the dgqPolygamyGrandfatherFatherOnly pin",
    }, {
      "expr" = "m['dgqFirstWifeChildrenInherit']() != 1",
      "note" = "the dgqFirstWifeChildrenInherit pin",
    }, {
      "expr" = "m['dgqInheritanceFirstSonFirstWife']() != 1",
      "note" = "the dgqInheritanceFirstSonFirstWife pin",
    }, {
      "expr" = "m['dgqFurtherGenerationsNoModifier']() != 1",
      "note" = "the dgqFurtherGenerationsNoModifier pin",
    }, {
      "expr" = "m['dgqInterrelatedDmApproval']() != 1",
      "note" = "the dgqInterrelatedDmApproval pin",
    }, {
      "expr" = "m['dgqInterrelatedSameRace']() != 1",
      "note" = "the dgqInterrelatedSameRace pin",
    }, {
      "expr" = "m['dgqInterrelatedSameBirthRank']() != 1",
      "note" = "the dgqInterrelatedSameBirthRank pin",
    }, {
      "expr" = "m['dgqInterrelatedTwinsOnly']() != 1",
      "note" = "the dgqInterrelatedTwinsOnly pin",
    }, {
      "expr" = "m['dgqInterrelatedSharedAncestry']() != 1",
      "note" = "the dgqInterrelatedSharedAncestry pin",
    }, {
      "expr" = "m['dgqPcReentryFirstLevel']() != 1",
      "note" = "the dgqPcReentryFirstLevel pin",
    }, {
      "expr" = "m['dgqHeadTitleSuccession']() != 1",
      "note" = "the dgqHeadTitleSuccession pin",
    }, {
      "expr" = "m['dgqChildrenDiceSides']() != 8  or m['dgqChildrenDiceMod']() != -2  or m['dgqChildrenDiceSides']() +m['dgqChildrenDiceMod']() != 6",
      "note" = "the children doctrine - 1d8 minus 2, the negatives and zero mean no offspring (capture pp. 62-64)",
    }, {
      "expr" = "m['dgqDeathHeadPct']() != 10  or m['dgqDeathFatherPct']() != 7  or m['dgqDeathSiblingPct']() != 5",
      "note" = "the deaths ladder - 10, 7 and 5 percent by row (capture pp. 62-64)",
    }, {
      "expr" = "m['dgqDeathCheckPerYear']() != 1  or m['dgqDeathFirstbornPct']() != 75",
      "note" = "the death read - once per game year, the 75 percent firstborn pass (capture pp. 62-64)",
    }, {
      "expr" = "m['dgqMarriageDiceSides']() != 6  or m['dgqMarriageRollMax']() != 5  or m['dgqMarriageBonusPct']() != 10",
      "note" = "the marriage read - 1-5 on 1d6 with the +10 bonus (capture pp. 62-64)",
    }, {
      "expr" = "m['dgqAdoptChancePct']() != 5  or m['dgqAdoptDiceSides']() != 6  or m['dgqAdoptOrphanMax']() != 2  or m['dgqAdoptBonusPct']() != 10",
      "note" = "the adoption read - the 5 percent entry, the 1-2 orphan check, the +10 bonus (capture pp. 62-64)",
    } },
  "audit" = {
      "label" = "R630 OA family structures audit",
      "comment" = "OA round seventeen (capture pp. 62-64): the family structure and the additional structures - the marriages, adoptions, polygamy, interrelated characters and the deaths ladder",
    },
}
