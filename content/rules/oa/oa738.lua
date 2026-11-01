-- oa738: promoted from rules/oa109itemmods.h (the OA TREASURE - THE MODIFICATIONS TO STANDARD MAGICAL ITEMS, printed capture);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 738,
  "prefix" = "oa738",
  "banner" = {
      "title" = "OA TREASURE - THE MODIFICATIONS TO STANDARD MAGICAL ITEMS, printed capture",
      "provenance" = "p. 286 - the occidental items round census 660 -> 661.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 191 closed, 44 open - the item mods box flips (census 660 -> 661); NEXT - R739: Potions (capture p. 287), prefix dla (verify free at the landing), audit \"R739 OA potions audit\", include after rules/oa109itemmods.h",
    },
  "consts" = { {
      "name" = "dkzMajorityAvailable",
      "value" = 1,
      "comment" = "the majority - most of the DMG magical items available throughout the world of the Orient (print capture p. 286)",
    }, {
      "name" = "dkzSomeParticularlyOccidental",
      "value" = 1,
      "comment" = "the exceptions - some items particularly occidental (print capture p. 286)",
    }, {
      "name" = "dkzDoNotAppearNormally",
      "value" = 1,
      "comment" = "the appearance rule - the occidental items do not appear normally in the Oriental world (print capture p. 286)",
    }, {
      "name" = "dkzOrSomewhatDifferent",
      "value" = 1,
      "comment" = "the difference rule - if they do appear, they are somewhat different from those listed in the DMG (print capture p. 286)",
    }, {
      "name" = "dkzLittleOrNoUse",
      "value" = 1,
      "comment" = "the use clause - there may be little or no use for the items in the Oriental setting (print capture p. 286)",
    }, {
      "name" = "dkzNotWithinCulture",
      "value" = 1,
      "comment" = "the culture clause - they may not be items found within the culture (print capture p. 286)",
    }, {
      "name" = "dkzNotToSayCannotAppear",
      "value" = 1,
      "comment" = "the allowance - this is not to say they cannot appear (print capture p. 286)",
    }, {
      "name" = "dkzConstructionFarFromCommon",
      "value" = 1,
      "comment" = "the commonness - only that their construction and use is far from common (print capture p. 286)",
    }, {
      "name" = "dkzGeneralRuleIfAsPresented",
      "value" = 1,
      "comment" = "the general rule - if any of the items below appear as presented in the DMG in an Oriental setting (print capture p. 286)",
    }, {
      "name" = "dkzGajinThreshold",
      "value" = 3,
      "comment" = "the gajin count - the three sources of an item appearing as printed in the DMG in an Oriental setting: the gajin bringing it in, the import as a curiosity, the inspired or deranged spell caster assembling it (print capture p. 286)",
    }, {
      "name" = "dkzBroughtInByGajin",
      "value" = 1,
      "comment" = "the gajin source - brought in by gajin, the capture misreading the gaijin (print capture p. 286)",
    }, {
      "name" = "dkzImportedAsCuriosities",
      "value" = 1,
      "comment" = "the import source - imported as curiosities (print capture p. 286)",
    }, {
      "name" = "dkzAssembledByInspiredCaster",
      "value" = 1,
      "comment" = "the caster source - assembled by some inspired or deranged spell caster (print capture p. 286)",
    }, {
      "name" = "dkzGenerallyOccidentalForm",
      "value" = 1,
      "comment" = "the form - the DMG items generally, although not always, occidental in form and function (print capture p. 286)",
    }, {
      "name" = "dkzFormChangeCount",
      "value" = 4,
      "comment" = "the form change count - the four examples of the occidental form taking an Oriental shape: the lyre, cloak, boots, and bags (print capture p. 286)",
    }, {
      "name" = "dkzLyreSamisenOrFlute",
      "value" = 1,
      "comment" = "the lyre example - a known instrument in occidental lands taking the form of a samisen or flute in the Orient (print capture p. 286)",
    }, {
      "name" = "dkzCloakRobeOrJacket",
      "value" = 1,
      "comment" = "the cloak example - a cloak becoming a robe or jacket (print capture p. 286)",
    }, {
      "name" = "dkzBootsSandals",
      "value" = 1,
      "comment" = "the boots example - boots becoming sandals (print capture p. 286)",
    }, {
      "name" = "dkzBagsBoxes",
      "value" = 1,
      "comment" = "the bags example - bags becoming boxes (print capture p. 286)",
    }, {
      "name" = "dkzDMDecidesForm",
      "value" = 1,
      "comment" = "the decision - it is the DM's decision to alter the form of any item, the capture misreading after for the alter (print capture p. 286)",
    }, {
      "name" = "dkzFunctionUnaffected",
      "value" = 1,
      "comment" = "the function clause - this does not affect the function of the item in any way (print capture p. 286)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dkzGajinThreshold']() != 3  or m['dkzFormChangeCount']() != 4  or  m['dkzMajorityAvailable']() != 1  or  m['dkzSomeParticularlyOccidental']() != 1  or  m['dkzDoNotAppearNormally']() != 1  or  m['dkzOrSomewhatDifferent']() != 1  or  m['dkzLittleOrNoUse']() != 1  or  m['dkzNotWithinCulture']() != 1  or  m['dkzNotToSayCannotAppear']() != 1  or  m['dkzConstructionFarFromCommon']() != 1  or  m['dkzGeneralRuleIfAsPresented']() != 1  or  m['dkzBroughtInByGajin']() != 1  or  m['dkzImportedAsCuriosities']() != 1  or  m['dkzAssembledByInspiredCaster']() != 1  or  m['dkzGenerallyOccidentalForm']() != 1  or  m['dkzLyreSamisenOrFlute']() != 1  or  m['dkzCloakRobeOrJacket']() != 1  or  m['dkzBootsSandals']() != 1  or  m['dkzBagsBoxes']() != 1  or  m['dkzDMDecidesForm']() != 1  or  m['dkzFunctionUnaffected']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dkzMajorityAvailable']() != 1  or m['dkzSomeParticularlyOccidental']() != 1  or m['dkzDoNotAppearNormally']() != 1  or m['dkzOrSomewhatDifferent']() != 1  or m['dkzLittleOrNoUse']() != 1  or m['dkzNotWithinCulture']() != 1  or m['dkzNotToSayCannotAppear']() != 1  or m['dkzConstructionFarFromCommon']() != 1",
      "note" = "the first paragraph - the occidental items rule, healthy values, each condition false",
    }, {
      "expr" = "m['dkzGeneralRuleIfAsPresented']() != 1  or m['dkzBroughtInByGajin']() != 1  or m['dkzImportedAsCuriosities']() != 1  or m['dkzAssembledByInspiredCaster']() != 1  or m['dkzGajinThreshold']() != 3",
      "note" = "the three sources - the gajin, the curiosity, and the caster, healthy values, each condition false",
    }, {
      "expr" = "m['dkzGenerallyOccidentalForm']() != 1  or m['dkzLyreSamisenOrFlute']() != 1  or m['dkzCloakRobeOrJacket']() != 1  or m['dkzBootsSandals']() != 1  or m['dkzBagsBoxes']() != 1  or m['dkzDMDecidesForm']() != 1  or m['dkzFunctionUnaffected']() != 1  or m['dkzFormChangeCount']() != 4",
      "note" = "the second paragraph - the form changes and the function clause, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R738 OA standard item mods audit",
      "comment" = "OA round one hundred twenty-five (capture p. 286): the Modifications to Standard Magical Items prose - the occidental items rule with the gajin, curiosity, and caster sources, the form changes of the lyre, cloak, boots, and bags, the DM form decision leaving function untouched, the capture misreads pinned against the print, single-pass pins per the Chapter 9 provenance shift",
    },
}
