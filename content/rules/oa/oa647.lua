-- oa647: promoted from rules/oagrenade.h (the MISCELLANEOUS EQUIPMENT DESCRIPTIONS (THE GRENADES PROSE), printed capture);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 647,
  "prefix" = "oa647",
  "banner" = {
      "title" = "MISCELLANEOUS EQUIPMENT DESCRIPTIONS (THE GRENADES PROSE), printed capture",
      "provenance" = "p. 98 - the OA misc equipment round census 569 -> 570.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the page - the grenades prose cross-checked paragraph-by-paragraph between the two passes; every printed number agrees - zero contested cells. The lone glyph artifact is the em-dash class (the print hyphen against the compressed em-dash in the not-modern-sense clause - not a pin, noted). The grenades are blown-out eggshells (nutshells and paper packets also used) filled with powders - four kinds pin: pepper-filled (single target, save versus poison or incapacitated 1-6 rounds by choking and sneezing), dust-filled (the same save, blinded 1-6 rounds), flash powder (thrown onto a fire source, all looking automatically blinded 1-3 rounds, the may-or-may-not-looking allowed a save versus petrification) and poison smoke (cast onto a fire source, fills five feet by five feet per round, save versus poison or blinded and incapacitated, 1-2 hit points per round within, enough powder for a 10-foot by 10-foot area, remains one turn or until the wind). The to-hit doctrine pins as a bool pair: no armor modifiers (the contents burst in a small cloud on impact) and the eggshell fragility (a fall of 10 feet or more with damage forces a save versus crushing blow per grenade carried). The barding prose box and the armor descriptions box stay open  the gap census after this round: 98 closed, 137 open - the Miscellaneous Equipment Descriptions box flips (census 569 -> 570); NEXT - R648: the Barding prose box (capture p. 98), the barding AC-factor and weight paragraph, prefix dhi (verify free), audit \"R648 OA barding prose audit\", include after rules/oagrenade.h - the armor descriptions box stays open beside it",
    },
  "consts" = { {
      "name" = "dhhGrenadeKindCount",
      "value" = 4,
      "comment" = "the four grenade kinds - pepper-filled, dust-filled, flash powder and poison smoke (capture p. 98)",
    }, {
      "name" = "dhhPepperIncapLo",
      "value" = 1,
      "comment" = "the pepper grenade incapacitation lower bound, in rounds - save versus poison or incapacitated by choking and sneezing (capture p. 98)",
    }, {
      "name" = "dhhPepperIncapHi",
      "value" = 6,
      "comment" = "the pepper grenade incapacitation upper bound, in rounds (capture p. 98)",
    }, {
      "name" = "dhhDustBlindLo",
      "value" = 1,
      "comment" = "the dust grenade blinding lower bound, in rounds - the same save-versus-poison way as pepper (capture p. 98)",
    }, {
      "name" = "dhhDustBlindHi",
      "value" = 6,
      "comment" = "the dust grenade blinding upper bound, in rounds (capture p. 98)",
    }, {
      "name" = "dhhFlashBlindLo",
      "value" = 1,
      "comment" = "the flash powder blinding lower bound, in rounds - all looking at the flare are blinded automatically (capture p. 98)",
    }, {
      "name" = "dhhFlashBlindHi",
      "value" = 3,
      "comment" = "the flash powder blinding upper bound, in rounds (capture p. 98)",
    }, {
      "name" = "dhhSmokeFillFeet",
      "value" = 5,
      "comment" = "the poison smoke per-round fill - a five foot by five foot area each round (capture p. 98)",
    }, {
      "name" = "dhhSmokeDmgLo",
      "value" = 1,
      "comment" = "the poison smoke damage lower bound, hit points per round to all within the smoke (capture p. 98)",
    }, {
      "name" = "dhhSmokeDmgHi",
      "value" = 2,
      "comment" = "the poison smoke damage upper bound, hit points per round (capture p. 98)",
    }, {
      "name" = "dhhSmokeAreaFeet",
      "value" = 10,
      "comment" = "the poison smoke total fill - each grenade holds enough powder for a 10 foot by 10 foot area (capture p. 98)",
    }, {
      "name" = "dhhSmokeTurns",
      "value" = 1,
      "comment" = "the poison smoke duration, in turns - remains one turn or until the wind blows it away (capture p. 98)",
    }, {
      "name" = "dhhEggshellFallFeet",
      "value" = 10,
      "comment" = "the eggshell grenade fragility threshold - a fall of 10 feet or more that suffers damage forces the save (capture p. 98)",
    } },
  "bools" = { {
      "name" = "dhhGrenadeNoAcMod",
      "value" = true,
      "comment" = "the to-hit doctrine: no armor modifiers - the contents burst in a small cloud on impact (capture p. 98)",
    }, {
      "name" = "dhhPepperSingleTarget",
      "value" = true,
      "comment" = "pepper-filled grenades only affect a single target (capture p. 98)",
    }, {
      "name" = "dhhFlashNeedsFire",
      "value" = true,
      "comment" = "flash powder grenades must be thrown onto a fire source, exploding in a brilliant flare of light (capture p. 98)",
    }, {
      "name" = "dhhFlashPetrifySave",
      "value" = true,
      "comment" = "the flash powder save - characters who may or may not be looking are allowed a save versus petrification; a success means unaffected (capture p. 98)",
    }, {
      "name" = "dhhSmokeNeedsFire",
      "value" = true,
      "comment" = "poison smoke grenades must also be cast onto a fire source to work (capture p. 98)",
    }, {
      "name" = "dhhSmokePoisonSave",
      "value" = true,
      "comment" = "the poison smoke save - all within the area must save versus poison or be blinded and incapacitated by the foul, acidic stench (capture p. 98)",
    }, {
      "name" = "dhhEggshellCrushSave",
      "value" = true,
      "comment" = "the eggshell fragility save - a saving throw versus crushing blow must be made for each grenade carried after the threshold fall (capture p. 98)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhhGrenadeKindCount']() != 4  or m['dhhPepperIncapLo']() != 1  or m['dhhPepperIncapHi']() != 6  or m['dhhDustBlindLo']() != 1  or m['dhhDustBlindHi']() != 6  or m['dhhFlashBlindLo']() != 1  or m['dhhFlashBlindHi']() != 3  or m['dhhSmokeFillFeet']() != 5  or m['dhhSmokeDmgLo']() != 1  or m['dhhSmokeDmgHi']() != 2  or m['dhhSmokeAreaFeet']() != 10  or m['dhhSmokeTurns']() != 1  or m['dhhEggshellFallFeet']() != 10  or  m['dhhGrenadeNoAcMod']() != 1  or  m['dhhPepperSingleTarget']() != 1  or  m['dhhFlashNeedsFire']() != 1  or  m['dhhFlashPetrifySave']() != 1  or  m['dhhSmokeNeedsFire']() != 1  or  m['dhhSmokePoisonSave']() != 1  or  m['dhhEggshellCrushSave']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhhGrenadeKindCount']() != 4",
      "note" = "the grenade kind count pin",
    }, {
      "expr" = "m['dhhPepperIncapLo']() != 1  or m['dhhPepperIncapHi']() != 6",
      "note" = "the pepper incapacitation bounds pin - 1-6 rounds",
    }, {
      "expr" = "m['dhhDustBlindLo']() != 1  or m['dhhDustBlindHi']() != 6",
      "note" = "the dust blinding bounds pin - 1-6 rounds",
    }, {
      "expr" = "m['dhhFlashBlindLo']() != 1  or m['dhhFlashBlindHi']() != 3",
      "note" = "the flash blinding bounds pin - 1-3 rounds",
    }, {
      "expr" = "m['dhhSmokeFillFeet']() != 5  or m['dhhSmokeDmgLo']() != 1  or m['dhhSmokeDmgHi']() != 2  or m['dhhSmokeAreaFeet']() != 10  or m['dhhSmokeTurns']() != 1",
      "note" = "the poison smoke numbers pin - the 5-foot fill, the 1-2 damage, the 10-foot area, the one turn",
    }, {
      "expr" = "m['dhhEggshellFallFeet']() != 10",
      "note" = "the eggshell fall threshold pin - 10 feet",
    }, {
      "expr" = "m['dhhGrenadeNoAcMod']() != 1",
      "note" = "the no-armor-modifier doctrine pin",
    }, {
      "expr" = "m['dhhPepperSingleTarget']() != 1",
      "note" = "the pepper single-target pin",
    }, {
      "expr" = "m['dhhFlashNeedsFire']() != 1  or m['dhhFlashPetrifySave']() != 1",
      "note" = "the flash fire-source and petrification-save pins",
    }, {
      "expr" = "m['dhhSmokeNeedsFire']() != 1  or m['dhhSmokePoisonSave']() != 1",
      "note" = "the smoke fire-source and poison-save pins",
    }, {
      "expr" = "m['dhhEggshellCrushSave']() != 1",
      "note" = "the eggshell crushing-blow save pin",
    } },
  "audit" = {
      "label" = "R647 OA misc equipment audit",
      "comment" = "OA round thirty-four (capture p. 98): the miscellaneous equipment descriptions - the grenades prose (pepper, dust, flash powder and poison smoke)",
    },
}
