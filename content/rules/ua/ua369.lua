-- ua369: promoted from rules/ua/uacantacq.h (the The UA ACQUISITION OF CANTRIPS,);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 369,
  "prefix" = "ua369",
  "banner" = {
      "title" = "The UA ACQUISITION OF CANTRIPS,",
      "provenance" = "MAGIC-USERS (p. 79) pins, R369: the known-count rules - the useful category one known per point of intelligence by free choice, the five random categories (reversed 2-8, legerdemain 2-5, person-affecting 2-8, personal 2-8, haunting-sound 2-5), the three developed cantrips cap with the DM review, and the read-as-spell / recorded-as-spell notes.  Pin-era pattern (R322): pinned data only - no engine site exists. Cross-checks the landed R365 seam (rules/ua/uailacquisition.h - the illusionist bands deliberately differ, the documented divergence) and the R366 spell-book seam (cantrips count as 1st-level spells).  JUDGMENTs (the decode method): - the useful-per-intelligence sentence garbles in the extract; the read - one known per point of intelligence, free choice - is decoded from the surviving fragments and matches the gap report standing reading; flagged pending the PDF. - the five random bands and the developed-cap sentence print clean. - the 0-level per-day tier (p. 45) rides its own item (the cantrips category); no pin here.",
    },
  "consts" = { {
      "name" = "uacaqUsefulPerIntelligencePoint",
      "value" = 1,
      "comment" = "---- the useful category ---- One known per point of intelligence, free choice - the decode flagged above.",
    }, {
      "name" = "uacaqCategoryCount",
      "value" = 6,
      "comment" = "---- the category count ---- Six MU categories; the illusionist seventh (minor illusion) is R365 territory.",
    }, {
      "name" = "uacaqReversedKnownMin",
      "value" = 2,
      "comment" = "---- the five random categories ----",
    }, {
      "name" = "uacaqReversedKnownMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uacaqLegerdemainKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uacaqLegerdemainKnownMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uacaqPersonAffectingKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uacaqPersonAffectingKnownMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uacaqPersonalKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uacaqPersonalKnownMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uacaqHauntingSoundKnownMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uacaqHauntingSoundKnownMax",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uacaqMaxDevelopedCantrips",
      "value" = 3,
      "comment" = "---- the developed-cantrips cap ----",
    } },
  "bools" = { {
      "name" = "uacaqUsefulFreeChoice",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacaqUsefulReadDecoded",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacaqDevelopedRequiresDmReview",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uacaqReadAsSpell",
      "value" = true,
      "comment" = "---- the spell-procedure notes ---- Cantrips are read as spells and recorded in books or scrolls by the spell procedure.",
    }, {
      "name" = "uacaqRecordedAsSpell",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uacaqUsefulPerIntelligencePoint']() != 1  or  m['uacaqUsefulFreeChoice']() != 1  or  m['uacaqUsefulReadDecoded']() != 1  or m['uacaqCategoryCount']() != 6  or m['uacaqReversedKnownMin']() != 2  or m['uacaqReversedKnownMax']() != 8  or m['uacaqLegerdemainKnownMin']() != 2  or m['uacaqLegerdemainKnownMax']() != 5  or m['uacaqPersonAffectingKnownMin']() != 2  or m['uacaqPersonAffectingKnownMax']() != 8  or m['uacaqPersonalKnownMin']() != 2  or m['uacaqPersonalKnownMax']() != 8  or m['uacaqHauntingSoundKnownMin']() != 2  or m['uacaqHauntingSoundKnownMax']() != 5  or m['uacaqMaxDevelopedCantrips']() != 3  or  m['uacaqDevelopedRequiresDmReview']() != 1  or  m['uacaqReadAsSpell']() != 1  or  m['uacaqRecordedAsSpell']() != 1",
      "note" = "---- the pinned cells ----",
    }, {
      "expr" = "m['uacaqReversedKnownMax']() ==m['uailaReversedKnownMax']()  or m['uacaqLegerdemainKnownMin']() ==m['uailaLegerdemainKnownMin']()  or m['uacaqPersonAffectingKnownMax']() ==m['uailaPersonAffectingKnownMax']()  or m['uacaqPersonalKnownMax']() ==m['uailaPersonalKnownMax']()  or m['uacaqHauntingSoundKnownMax']() ==m['uailaHauntingSoundKnownMax']()  or m['uacaqUsefulPerIntelligencePoint']() * 18 -m['uailaUsefulCapAtInt18']() !=m['uailaUsefulCapIntMinus']()  or  m['uailaHasAllMuCantrips']() != 1  or  m['uailaMuCantripPropertiesOtherwiseApply']() != 1  or m['uacaqCategoryCount']() + 1 != 7",
      "note" = "---- the R365 illusionist seam ----",
    }, {
      "expr" = "m['uabkCantripsCountAsFirstLevel']() != 1  or m['uabkStandardCantripsCapacity']() != 36",
      "note" = "---- the R366 spell-book seam ----",
    } },
  "audit" = {
      "label" = "R369: the UA cantrip acquisition pin audit",
      "comment" = "The UA ACQUISITION OF CANTRIPS, MAGIC-USERS (p. 79): the known-count rules pinned - the useful category one per point of intelligence by free choice (the decode flagged), the five random bands (reversed 2-8, legerdemain 2-5, person-affecting 2-8, personal 2-8, haunting-sound 2-5), the 3 developed cap with the DM review, the read-as-spell and recorded-as-spell notes. The R365 seam cross-checks the illusionist bands (the documented divergence); the R366 seam the book counts. The item flips CLOSED; the census 295 -> 296.",
    },
}
