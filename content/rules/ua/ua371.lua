-- ua371: promoted from rules/ua/uaarmor.h (the The UA EXPANDED ARMOR (pp. 75-76));
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 371,
  "prefix" = "ua371",
  "banner" = {
      "title" = "The UA EXPANDED ARMOR (pp. 75-76)",
      "provenance" = "pins, R371: the armor and encumbrance table rows (the costs, the weights, the base movement, the bulk column, the shield rows) and the four new armor descriptions - bronze plate (the AC 4 with the +2 rear-attack exposure and the rust immunity), elfin chain (the thief-wearable read), field plate (the 1 point per die absorption, the 12 point cap, the repair costs), full plate.  Pin-era pattern (R322): pinned data only - no engine site exists. Cross-checks the landed R191 seam (rules/phb/armorratings.h - the plate mail AC 3 the bronze plate reads one worse than), the R334 seam (rules/ua/thiefarmor.h - the elfin chain rows) and the R370 seam (the elfin-chain barding weight read).  JUDGMENTs (the decode method): - the table rows print clean for banded, bronze plate, field plate, full plate, ring, scale, splint and studded leather; the elfin chain cost cell garbles - which confirms the clean footnote (never on the open market) rather than contradicting it; some weight cells carry the OCR crosshatch - the weights pinned where clean, flagged where not. - the four descriptions print clean throughout.",
    },
  "consts" = { {
      "name" = "uaarmBandedWeight",
      "value" = 35,
      "comment" = "---- the expanded armor table (p. 75) ---- Banded: bulky, 35 pounds, 9 inches, 90 gp.",
    }, {
      "name" = "uaarmBandedMove",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uaarmBandedCost",
      "value" = 90,
      "comment" = "",
    }, {
      "name" = "uaarmBronzePlateWeight",
      "value" = 45,
      "comment" = "Bronze plate: bulky, 45 pounds, 6 inches, 100 gp.",
    }, {
      "name" = "uaarmBronzePlateMove",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaarmBronzePlateCost",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateWeight",
      "value" = 55,
      "comment" = "Field plate: fairly bulky, 55 pounds, 6 inches, 2000 gp.",
    }, {
      "name" = "uaarmFieldPlateMove",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateCost",
      "value" = 2000,
      "comment" = "",
    }, {
      "name" = "uaarmFullPlateWeight",
      "value" = 65,
      "comment" = "Full plate: fairly bulky, 65 pounds, 6 inches, 4000 gp.",
    }, {
      "name" = "uaarmFullPlateMove",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaarmFullPlateCost",
      "value" = 4000,
      "comment" = "",
    }, {
      "name" = "uaarmRingMailWeight",
      "value" = 25,
      "comment" = "Ring mail: fairly bulky, 25 pounds, 9 inches, 30 gp.",
    }, {
      "name" = "uaarmRingMailMove",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uaarmRingMailCost",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uaarmScaleMailWeight",
      "value" = 40,
      "comment" = "Scale mail: fairly bulky, 40 pounds, 6 inches, 45 gp.",
    }, {
      "name" = "uaarmScaleMailMove",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaarmScaleMailCost",
      "value" = 45,
      "comment" = "",
    }, {
      "name" = "uaarmSplintMailWeight",
      "value" = 40,
      "comment" = "Splint mail: fairly bulky, 40 pounds, 6 inches, 80 gp.",
    }, {
      "name" = "uaarmSplintMailMove",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uaarmSplintMailCost",
      "value" = 80,
      "comment" = "",
    }, {
      "name" = "uaarmStuddedLeatherWeight",
      "value" = 20,
      "comment" = "Studded leather: fairly bulky, 20 pounds, 9 inches, 15 gp.",
    }, {
      "name" = "uaarmStuddedLeatherMove",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uaarmStuddedLeatherCost",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uaarmShieldBucklerWeight",
      "value" = 3,
      "comment" = "---- the shield rows ----",
    }, {
      "name" = "uaarmShieldBucklerCost",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uaarmShieldLargeWeight",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaarmShieldLargeCost",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uaarmShieldSmallWeight",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uaarmShieldSmallCost",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uaarmBronzeAc",
      "value" = 4,
      "comment" = "---- the bronze plate description ---- AC 4 (the regular plate mail AC 3), the rear attacks at +2, the rust-monster immunity.",
    }, {
      "name" = "uaarmBronzeRearAttackBonus",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateAbsorbPerDie",
      "value" = 1,
      "comment" = "---- the field plate description ---- Absorbs 1 point per die of damage (a die roll of 1 takes no damage); after 12 absorbed points the armor is damaged.",
    }, {
      "name" = "uaarmFieldPlateAbsorbCap",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateRepairCostPerPoint",
      "value" = 100,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateRepairDaysPerPoint",
      "value" = 1,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uaarmBandedBulky",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmBronzePlateBulky",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateFairlyBulky",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmFullPlateFairlyBulky",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmElfinNeverOnOpenMarket",
      "value" = true,
      "comment" = "---- the elfin chain footnote ---- The clean footnote: never available on the open market (the cost cell garbles, which confirms the read).",
    }, {
      "name" = "uaarmBronzeRustImmune",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmBronzeEarlierCheaperVersion",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmElfinElvenMade",
      "value" = true,
      "comment" = "---- the elfin chain description ----",
    }, {
      "name" = "uaarmElfinExtremelyRare",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmElfinThiefWearable",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmElfinSomewhatImpairsThiefAbilities",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateFittedToWearer",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmFieldPlateBulkyAsChain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uaarmFullPlateInterlockedBackedWithChain",
      "value" = true,
      "comment" = "---- the full plate description ----",
    }, {
      "name" = "uaarmFullPlateBulkyAsChain",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uaarmBandedWeight']() != 35  or m['uaarmBandedMove']() != 9  or m['uaarmBandedCost']() != 90  or  m['uaarmBandedBulky']() != 1  or m['uaarmBronzePlateWeight']() != 45  or m['uaarmBronzePlateMove']() != 6  or m['uaarmBronzePlateCost']() != 100  or  m['uaarmBronzePlateBulky']() != 1  or m['uaarmFieldPlateWeight']() != 55  or m['uaarmFieldPlateMove']() != 6  or m['uaarmFieldPlateCost']() != 2000  or  m['uaarmFieldPlateFairlyBulky']() != 1  or m['uaarmFullPlateWeight']() != 65  or m['uaarmFullPlateMove']() != 6  or m['uaarmFullPlateCost']() != 4000  or  m['uaarmFullPlateFairlyBulky']() != 1  or m['uaarmRingMailWeight']() != 25  or m['uaarmRingMailMove']() != 9  or m['uaarmRingMailCost']() != 30  or m['uaarmScaleMailWeight']() != 40  or m['uaarmScaleMailMove']() != 6  or m['uaarmScaleMailCost']() != 45  or m['uaarmSplintMailWeight']() != 40  or m['uaarmSplintMailMove']() != 6  or m['uaarmSplintMailCost']() != 80  or m['uaarmStuddedLeatherWeight']() != 20  or m['uaarmStuddedLeatherMove']() != 9  or m['uaarmStuddedLeatherCost']() != 15  or  m['uaarmElfinNeverOnOpenMarket']() != 1  or m['uaarmShieldBucklerWeight']() != 3  or m['uaarmShieldBucklerCost']() != 5  or m['uaarmShieldLargeWeight']() != 10  or m['uaarmShieldLargeCost']() != 15  or m['uaarmShieldSmallWeight']() != 5  or m['uaarmShieldSmallCost']() != 10  or 2 *m['uaarmFieldPlateCost']() !=m['uaarmFullPlateCost']()  or m['uaarmBronzePlateMove']() !=m['uaarmFieldPlateMove']()  or m['uaarmBandedMove']() !=m['uaarmRingMailMove']()",
      "note" = "---- the table rows ----",
    }, {
      "expr" = "m['uaarmBronzeAc']() != 4  or m['uaarmBronzeRearAttackBonus']() != 2  or  m['uaarmBronzeRustImmune']() != 1  or  m['uaarmBronzeEarlierCheaperVersion']() != 1  or  m['uaarmElfinElvenMade']() != 1  or  m['uaarmElfinExtremelyRare']() != 1  or  m['uaarmElfinThiefWearable']() != 1  or  m['uaarmElfinSomewhatImpairsThiefAbilities']() != 1  or m['uaarmFieldPlateAbsorbPerDie']() != 1  or m['uaarmFieldPlateAbsorbCap']() != 12  or m['uaarmFieldPlateRepairCostPerPoint']() != 100  or m['uaarmFieldPlateRepairDaysPerPoint']() != 1  or  m['uaarmFieldPlateFittedToWearer']() != 1  or  m['uaarmFieldPlateBulkyAsChain']() != 1  or  m['uaarmFullPlateInterlockedBackedWithChain']() != 1  or  m['uaarmFullPlateBulkyAsChain']() != 1  or m['uaarmFieldPlateRepairCostPerPoint']() *m['uaarmFieldPlateAbsorbCap']() != 1200  or m['uaarmFullPlateWeight']() <=m['uaarmFieldPlateWeight']()",
      "note" = "---- the descriptions ----",
    }, {
      "expr" = "m['armorRatingAc'](10) != 3  or m['armorRatingAc'](10) + 1 !=m['uaarmBronzeAc']()  or strcmp(m['armorRatingName'](10), \"plate mail\") != 0",
      "note" = "---- the R191 seam ----",
    }, {
      "expr" = "m['thiefArmorElfinUnderNormalClothing']() != 1",
      "note" = "---- the R334 seam ----",
    }, {
      "expr" = "m['uasm1UnicornGriffonElfinWeightAsLeather']() != 1",
      "note" = "---- the R370 seam ----",
    } },
  "audit" = {
      "label" = "R371: the UA expanded armor pin audit",
      "comment" = "The UA expanded armor (pp. 75-76): the armor and encumbrance table rows (banded through studded leather, the shield rows, the never-sold elfin chain footnote) and the four descriptions - the bronze plate (the AC 4, the +2 rear-attack exposure, the rust immunity), the elfin chain (the thief-wearable read), the field plate (the 1 point per die absorption, the 12 point cap, the 100 gp per point repair), the full plate. The R191 seam cross-checks the plate AC ladder, the R334 seam the thief elfin rows, the R370 seam the barding weight read. Two items flip CLOSED; the census 297 -> 298.",
    },
}
