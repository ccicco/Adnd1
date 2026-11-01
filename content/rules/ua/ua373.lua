-- ua373: promoted from rules/uacomnote.h (the The UA COMELINESS CREATION NOTE);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 373,
  "prefix" = "ua373",
  "banner" = {
      "title" = "The UA COMELINESS CREATION NOTE",
      "provenance" = "(p. 74) pins, R373: the DM pointer in the DM section's CHARACTER ABILITIES - the attribute fully described on pages 6 and 7 of this volume, while it might more properly be called a characteristic, it does have effects (in game terms) upon those viewing or reacting to the character. The creation ride: the R322 pins carry the roll and the adjustments - checked in the regtest audit, not here. The trailing sentence of the printed note garbles in the extract - flagged.",
    },
  "consts" = { {
      "name" = "uacmPointerFirstPage",
      "value" = 6,
      "comment" = "The pointer pages of this volume.",
    }, {
      "name" = "uacmPointerSecondPage",
      "value" = 7,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uacmFullyDescribedOnPointerPages",
      "value" = true,
      "comment" = "The attribute is fully described on the pointer pages.",
    }, {
      "name" = "uacmMoreProperlyCharacteristic",
      "value" = true,
      "comment" = "While it might more properly be called a characteristic.",
    }, {
      "name" = "uacmAffectsViewers",
      "value" = true,
      "comment" = "It does have effects in game terms upon those viewing the character.",
    }, {
      "name" = "uacmAffectsReactors",
      "value" = true,
      "comment" = "... upon those reacting to the character.",
    }, {
      "name" = "uacmShownAboveForHumans",
      "value" = true,
      "comment" = "\"As shown above, human player\" - the human example opens before the extract garbles.",
    }, {
      "name" = "uacmTrailingSentenceGarbles",
      "value" = true,
      "comment" = "The trailing sentence garbles beyond decode - a hole awaiting the PDF.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uacmPointerFirstPage']() != 6  or m['uacmPointerSecondPage']() != 7  or  m['uacmFullyDescribedOnPointerPages']() != 1  or  m['uacmMoreProperlyCharacteristic']() != 1  or  m['uacmAffectsViewers']() != 1  or  m['uacmAffectsReactors']() != 1  or  m['uacmShownAboveForHumans']() != 1  or  m['uacmTrailingSentenceGarbles']() != 1",
      "note" = "---- the note pins ----",
    }, {
      "expr" = "m['uaComelinessBaseDieCount']() != 3  or m['uaComelinessBaseDieSides']() != 6  or m['uaComelinessChaAdj'](2) != -8  or m['uaComelinessChaAdj'](3) != -5  or m['uaComelinessChaAdj'](4) != -3  or m['uaComelinessChaAdj'](8) != -1  or m['uaComelinessChaAdj'](9) != 0  or m['uaComelinessChaAdj'](15) != 1  or m['uaComelinessChaAdj'](16) != 2  or m['uaComelinessChaAdj'](17) != 2  or m['uaComelinessChaAdj'](18) != 3  or m['uaComelinessChaAdj'](19) != 5  or m['uaComelinessBand'](-16) != 0  or m['uaComelinessBand'](-9) != 1  or m['uaComelinessBand'](0) != 2  or m['uaComelinessBand'](30) != 9",
      "note" = "---- the R322 seam ----",
    }, {
      "expr" = "m['uanwCount']() != 16  or m['uanwInGapItemList'](i)) ++inList; if (inList != 14  or strcmp(m['uanwName'](0), \"Aklys\") != 0  or strcmp(m['uanwName'](4), \"Crossbow, Hand-held\") != 0  or strcmp(m['uanwName'](13), \"Sword, Falchion\") != 0  or strcmp(m['uanwName'](15), \"Whip\") != 0  or m['uanwHookFauchardDismountPct']() != 20  or m['uanwManCatcherPoleCuttingDmg']() != 6  or  m['uanwStaffSlingMediumOrLongOnly']() != 1",
      "note" = "---- the R340 seam ----",
    }, {
      "expr" = "!hook  or  !mc  or  !lasso  or  !harp",
      "note" = "---- the R337 seam ----",
    } },
  "audit" = {
      "label" = "R373: the UA comeliness note pin audit",
      "comment" = "The UA comeliness creation note (p. 74): the DM pointer - the attribute fully described on pages 6 and 7 of this volume, while it might more properly be called a characteristic, it does have effects in game terms upon those viewing or reacting to the character. The item rides the R322 pins; the weapon descriptions item rides the R340 pins. The R322 seam cross-checks the creation roll and the charisma ladder; the R340 seam the 16-entry roster with the 14 item-list types; the R337 seam the pole-arm rows; two items flip CLOSED; the census 299 -> 300.",
    },
}
