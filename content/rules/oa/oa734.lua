-- oa734: promoted from rules/oa/oa105randtres.h (the OA TREASURE - THE RANDOM TREASURE DETERMINATION PROSE, printed capture p.);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 734,
  "prefix" = "oa734",
  "banner" = {
      "title" = "OA TREASURE - THE RANDOM TREASURE DETERMINATION PROSE, printed capture p.",
      "provenance" = "285 - the procedure round census 656 -> 657.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 187 closed, 48 open - the random treasure prose box flips (census 656 -> 657); NEXT - R735: Table 74: Monetary Treasure And Magical Items (capture p. 286), prefix dkw (verify free at the landing), audit \"R735 OA Table 74 monetary treasure audit\", include after rules/oa/oa105randtres.h",
    },
  "consts" = { {
      "name" = "dkvDMGProcedureUsed",
      "value" = 1,
      "comment" = "the procedure - the DMG procedure used to randomly determine treasures and magical items (print capture p. 285)",
    }, {
      "name" = "dkvExceptedTable74",
      "value" = 74,
      "comment" = "the excepted table number - the Table 74 Monetary Treasure And Magical Items, the one DMG exception of the procedure (print capture p. 285)",
    }, {
      "name" = "dkvTable74TheException",
      "value" = 1,
      "comment" = "the exception - the Table 74 Monetary Treasure And Magical Items excepted from the DMG procedure (print capture p. 285)",
    }, {
      "name" = "dkvUseVersionsGivenHere",
      "value" = 1,
      "comment" = "the replacement rule - roll on the versions given here, not the tables printed in the DMG (print capture p. 285)",
    }, {
      "name" = "dkvOrientalItemsTable86",
      "value" = 86,
      "comment" = "the additional table number - the Table 86 Oriental Magical Items of this book (print capture p. 285)",
    }, {
      "name" = "dkvAdditionalTable86",
      "value" = 1,
      "comment" = "the additional table - the Table 86 Oriental Magical Items for randomly selecting the magical items described in this book (print capture p. 285)",
    }, {
      "name" = "dkvDMGPageTableIIA",
      "value" = 120,
      "comment" = "the DMG page of Table II.A. - the 120 replaced by Table II.A. (ORIENT) (print capture p. 285)",
    }, {
      "name" = "dkvDMGPageTableIII",
      "value" = 121,
      "comment" = "the DMG page of Table III - the 121 replaced by Table III (ORIENT) (print capture p. 285)",
    }, {
      "name" = "dkvIIAOrientReplacesDMG",
      "value" = 1,
      "comment" = "the II.A. replacement - the Table II.A. (ORIENT) replacing the DMG Table II.A. (print capture p. 285)",
    }, {
      "name" = "dkvIIIOrientReplacesDMG",
      "value" = 1,
      "comment" = "the III replacement - the Table III (ORIENT) replacing the DMG Table III (print capture p. 285)",
    }, {
      "name" = "dkvReplacementsInOAWorld",
      "value" = 1,
      "comment" = "the scope - the replacements applying in the world of Oriental Adventures (print capture p. 285)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkvExceptedTable74']() != 74  or m['dkvOrientalItemsTable86']() != 86  or m['dkvDMGPageTableIIA']() != 120  or m['dkvDMGPageTableIII']() != 121  or  m['dkvDMGProcedureUsed']() != 1  or  m['dkvTable74TheException']() != 1  or  m['dkvUseVersionsGivenHere']() != 1  or  m['dkvAdditionalTable86']() != 1  or  m['dkvIIAOrientReplacesDMG']() != 1  or  m['dkvIIIOrientReplacesDMG']() != 1  or  m['dkvReplacementsInOAWorld']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkvDMGProcedureUsed']() != 1  or m['dkvTable74TheException']() != 1  or m['dkvUseVersionsGivenHere']() != 1  or m['dkvAdditionalTable86']() != 1  or m['dkvIIAOrientReplacesDMG']() != 1  or m['dkvIIIOrientReplacesDMG']() != 1  or m['dkvReplacementsInOAWorld']() != 1",
      "note" = "the prose - the Random Treasure Determination paragraph, healthy values, each condition false",
    }, {
      "expr" = "m['dkvExceptedTable74']() != 74  or m['dkvOrientalItemsTable86']() != 86  or m['dkvDMGPageTableIIA']() != 120  or m['dkvDMGPageTableIII']() != 121",
      "note" = "the table numbers and the DMG pages, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R734 OA random treasure prose audit",
      "comment" = "OA round one hundred twenty-one (capture p. 285): the Chapter 13 Random Treasure Determination prose - the DMG procedure carried over whole, the Table 74 exception with the use-the-versions-here rule, the additional Table 86 Oriental Magical Items, the Table II.A. (ORIENT) and Table III (ORIENT) replacements of the DMG pages 120 and 121, single-pass pins per the Chapter 9 provenance shift",
    },
}
