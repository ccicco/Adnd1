-- ua377: promoted from rules/ua/uaprotscr.h (the The UA TREASURE (SCROLLS));
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 377,
  "prefix" = "ua377",
  "banner" = {
      "title" = "The UA TREASURE (SCROLLS)",
      "provenance" = "protection prose pins, R377: the eleven clean protection-scroll types (pp. 91-93) - acid, breath weapons (dragon and non-dragon), fire, gas, illusions, paralyzation, plants, poison, the traps trio (50 mechanical, 30 magical, 20 any), water. The four PDF-gated types (cold, electricity, the two weapons scrolls) the R397 clean read filled - the gap item closed. The potions and skeleton seams ride in the regtest audit, not here.",
    },
  "consts" = { {
      "name" = "uapsAcidReadingSegs",
      "value" = 5,
      "comment" = "---- the acid scroll ---- Reading 5 segments; the damage limit 20 hit dice or the time limit 9-12 turns (d4 + 8), whichever comes first - three 6-HD black dragon breaths ride inside the limit.",
    }, {
      "name" = "uapsAcidDamageLimitHd",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uapsAcidDurationLoTurns",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uapsAcidDurationHiTurns",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uapsAcidExampleBreaths",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsAcidExampleHdPerBreath",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uapsBwDragonReadingRounds",
      "value" = 1,
      "comment" = "---- the breath weapon scrolls ---- Dragon: reading 1 round, the individual only, all forms of dragon breath, 6-12 rounds (2d4 + 4).",
    }, {
      "name" = "uapsBwDragonDurationLoRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uapsBwDragonDurationHiRounds",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uapsBwNonDragonReadingSegs",
      "value" = 1,
      "comment" = "Non-dragon: reading 1 segment, the individual only, 5-8 rounds (d4 + 4).",
    }, {
      "name" = "uapsBwNonDragonDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsBwNonDragonDurationHiRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsFireReadingSegs",
      "value" = 8,
      "comment" = "---- the fire scroll ---- Reading 8 segments; a 3\" sphere; flame and heat of the hottest sort, even magical or elemental; 5-8 turns (d4 + 4).",
    }, {
      "name" = "uapsFireSphereDiamIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsFireDurationLoTurns",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsFireDurationHiTurns",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsGasReadingSegs",
      "value" = 3,
      "comment" = "---- the gas scroll ---- Reading 3 segments; a 1\" sphere; immune to any form of gas; 5-8 rounds (d4 + 4).",
    }, {
      "name" = "uapsGasSphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsGasDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsGasDurationHiRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsIllusionsReadingSegs",
      "value" = 7,
      "comment" = "---- the illusions scroll ---- Reading 7 segments; the individual only; any illusion/phantasm magic witnessed; 5-30 rounds (5d6).",
    }, {
      "name" = "uapsIllusionsDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsIllusionsDurationHiRounds",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uapsParalReadingRounds",
      "value" = 1,
      "comment" = "---- the paralyzation scroll ---- Reading 1 round; the reader only; all forms of paralyzation, a hold spell will not work, nor gas paralysis; 2-5 turns (d4 + 1).",
    }, {
      "name" = "uapsParalDurationLoTurns",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uapsParalDurationHiTurns",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsPlantsReadingRounds",
      "value" = 1,
      "comment" = "---- the plants scroll ---- Reading 1 round; a 1\" sphere; vegetable life, fungi, slimes, molds cannot penetrate; 5-8 turns (d4 + 4).",
    }, {
      "name" = "uapsPlantsSphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsPlantsDurationLoTurns",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsPlantsDurationHiTurns",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsPoisonReadingSegs",
      "value" = 3,
      "comment" = "---- the poison scroll ---- Reading 3 segments; the reader only; no form of poison affects, and any poison in the system is permanently neutralized; 3-12 rounds (d10 + 2).",
    }, {
      "name" = "uapsPoisonDurationLoRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsPoisonDurationHiRounds",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uapsTrapMechanicalPct",
      "value" = 50,
      "comment" = "---- the traps scrolls ---- Three forms: mechanical 50%, magical 30%, any form 20%. None reveal the traps they defeat.",
    }, {
      "name" = "uapsTrapMagicalPct",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "uapsTrapAnyPct",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uapsTrapMechReadingSegs",
      "value" = 4,
      "comment" = "Mechanical: reading 4 segments; the reader only; 5-20 rounds (5d4).",
    }, {
      "name" = "uapsTrapMechDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsTrapMechDurationHiRounds",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "uapsTrapMagReadingSegs",
      "value" = 8,
      "comment" = "Magical: reading 8 segments; a 1\" sphere; 3-12 rounds (d10 + 2).",
    }, {
      "name" = "uapsTrapMagSphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsTrapMagDurationLoRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsTrapMagDurationHiRounds",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uapsTrapAnyReadingRounds",
      "value" = 1,
      "comment" = "Any trap: reading 1 round; a 1\" sphere; 2-8 rounds (2d4).",
    }, {
      "name" = "uapsTrapAnySphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsTrapAnyDurationLoRounds",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uapsTrapAnyDurationHiRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsWaterReadingSegs",
      "value" = 6,
      "comment" = "---- the water scroll ---- Reading 6 segments; a 1\" sphere; liquid, solid, and vapor water cannot touch the protected; 5-8 turns (d4 + 4).",
    }, {
      "name" = "uapsWaterSphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsWaterDurationLoTurns",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsWaterDurationHiTurns",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsColdReadingSegs",
      "value" = 3,
      "comment" = "---- the protection from cold scroll (the R397 clean read) ---- Reading 3 segments; a 3\" sphere; normal cold resisted down to absolute zero.",
    }, {
      "name" = "uapsColdSphereDiamIn",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsColdMagicalSaveBonus",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uapsColdDurationLoTurns",
      "value" = 5,
      "comment" = "The duration 5-8 turns (d4 + 4).",
    }, {
      "name" = "uapsColdDurationHiTurns",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsElecReadingSegs",
      "value" = 5,
      "comment" = "---- the protection from electricity scroll (the R397 clean read) ---- Reading 5 segments; a 2\" sphere; immunity to any electrical attacks and associated effects; 3-12 rounds (3d4).",
    }, {
      "name" = "uapsElecSphereDiamIn",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uapsElecDurationLoRounds",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uapsElecDurationHiRounds",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uapsWeapMagReadingRounds",
      "value" = 1,
      "comment" = "---- the protection from weapons, magical scroll (the R397 clean read) ---- Reading 1 round; the reader only; the indicated magic weapon cannot touch or harm; missile protection does NOT extend to missiles created by spell casting (such as magic missile) or a spell-like power; 5-8 rounds (d4 + 4).",
    }, {
      "name" = "uapsWeapMagDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsWeapMagDurationHiRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsWeapNonMagReadingRounds",
      "value" = 1,
      "comment" = "---- the protection from weapons, non-magic scroll (the R397 clean read) ---- Reading 1 round; a 1\" sphere; the indicated non-magical weapon cannot touch or harm; missile protection does NOT extend to normal missiles of large size (catapult projectiles, objects hurled by giants); 5-8 rounds (d4 + 4).",
    }, {
      "name" = "uapsWeapNonMagSphereDiamIn",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uapsWeapNonMagDurationLoRounds",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uapsWeapNonMagDurationHiRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uapsCleanCount",
      "value" = 15,
      "comment" = "",
    }, {
      "name" = "uapsGarbledCount",
      "value" = 0,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uapsBwDragonIndividualOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsBwNonDragonIndividualOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsIllusionsIndividualOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsParalBlocksHold",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsParalBlocksGas",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsParalReaderOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsPoisonReaderOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsPoisonNeutralizesInSystem",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsTrapMechReaderOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsTrapMechNotRevealed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsTrapMagNotRevealed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsTrapAnyNotRevealed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsColdNormalToAbsoluteZero",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsColdActsAsResistCold",
      "value" = true,
      "comment" = "Against magical cold the scroll acts as the clerical resist cold spell with enhanced benefits.",
    }, {
      "name" = "uapsColdNoSaveDmgQuarter",
      "value" = true,
      "comment" = "Magical cold damages one-quarter normal without a save, one-eighth with one.",
    }, {
      "name" = "uapsColdSavedDmgEighth",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsElecImmuneAll",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsWeapMagReaderOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsWeapMagExemptsSpellMissiles",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uapsWeapNonMagExemptsLargeMissiles",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['uapsAcidReadingSegs']() != 5  or m['uapsAcidDamageLimitHd']() != 20  or m['uapsAcidDurationLoTurns']() != 9  or m['uapsAcidDurationHiTurns']() != 12  or m['uapsAcidExampleBreaths']() != 3  or m['uapsAcidExampleHdPerBreath']() != 6  or m['uapsAcidDurationLoTurns']() +m['uapsAcidDurationHiTurns']() != 21",
      "note" = "---- the acid scroll ----",
    }, {
      "expr" = "m['uapsBwDragonReadingRounds']() != 1  or m['uapsBwDragonDurationLoRounds']() != 6  or m['uapsBwDragonDurationHiRounds']() != 12  or  m['uapsBwDragonIndividualOnly']() != 1  or m['uapsBwNonDragonReadingSegs']() != 1  or m['uapsBwNonDragonDurationLoRounds']() != 5  or m['uapsBwNonDragonDurationHiRounds']() != 8  or  m['uapsBwNonDragonIndividualOnly']() != 1",
      "note" = "---- the breath weapon scrolls ----",
    }, {
      "expr" = "m['uapsFireReadingSegs']() != 8  or m['uapsFireSphereDiamIn']() != 3  or m['uapsFireDurationLoTurns']() != 5  or m['uapsFireDurationHiTurns']() != 8",
      "note" = "---- the fire scroll ----",
    }, {
      "expr" = "m['uapsGasReadingSegs']() != 3  or m['uapsGasSphereDiamIn']() != 1  or m['uapsGasDurationLoRounds']() != 5  or m['uapsGasDurationHiRounds']() != 8",
      "note" = "---- the gas scroll ----",
    }, {
      "expr" = "m['uapsIllusionsReadingSegs']() != 7  or m['uapsIllusionsDurationLoRounds']() != 5  or m['uapsIllusionsDurationHiRounds']() != 30  or  m['uapsIllusionsIndividualOnly']() != 1",
      "note" = "---- the illusions scroll ----",
    }, {
      "expr" = "m['uapsParalReadingRounds']() != 1  or m['uapsParalDurationLoTurns']() != 2  or m['uapsParalDurationHiTurns']() != 5  or  m['uapsParalBlocksHold']() != 1  or  m['uapsParalBlocksGas']() != 1  or  m['uapsParalReaderOnly']() != 1",
      "note" = "---- the paralyzation scroll ----",
    }, {
      "expr" = "m['uapsPlantsReadingRounds']() != 1  or m['uapsPlantsSphereDiamIn']() != 1  or m['uapsPlantsDurationLoTurns']() != 5  or m['uapsPlantsDurationHiTurns']() != 8",
      "note" = "---- the plants scroll ----",
    }, {
      "expr" = "m['uapsPoisonReadingSegs']() != 3  or m['uapsPoisonDurationLoRounds']() != 3  or m['uapsPoisonDurationHiRounds']() != 12  or  m['uapsPoisonReaderOnly']() != 1  or  m['uapsPoisonNeutralizesInSystem']() != 1",
      "note" = "---- the poison scroll ----",
    }, {
      "expr" = "m['uapsTrapMechanicalPct']() != kTrap[0]  or m['uapsTrapMagicalPct']() != kTrap[1]  or m['uapsTrapAnyPct']() != kTrap[2]  or kTrap[0] + kTrap[1] + kTrap[2] != 100  or m['uapsTrapMechReadingSegs']() != 4  or m['uapsTrapMechDurationLoRounds']() != 5  or m['uapsTrapMechDurationHiRounds']() != 20  or  m['uapsTrapMechReaderOnly']() != 1  or  m['uapsTrapMechNotRevealed']() != 1  or m['uapsTrapMagReadingSegs']() != 8  or m['uapsTrapMagSphereDiamIn']() != 1  or m['uapsTrapMagDurationLoRounds']() != 3  or m['uapsTrapMagDurationHiRounds']() != 12  or  m['uapsTrapMagNotRevealed']() != 1  or m['uapsTrapAnyReadingRounds']() != 1  or m['uapsTrapAnySphereDiamIn']() != 1  or m['uapsTrapAnyDurationLoRounds']() != 2  or m['uapsTrapAnyDurationHiRounds']() != 8  or  m['uapsTrapAnyNotRevealed']() != 1",
      "note" = "---- the traps scrolls ----",
    }, {
      "expr" = "m['uapsWaterReadingSegs']() != 6  or m['uapsWaterSphereDiamIn']() != 1  or m['uapsWaterDurationLoTurns']() != 5  or m['uapsWaterDurationHiTurns']() != 8",
      "note" = "---- the water scroll ----",
    }, {
      "expr" = "m['uapsCleanCount']() != 15  or m['uapsGarbledCount']() != 0  or m['uapsCleanCount']() +m['uapsGarbledCount']() != 15",
      "note" = "---- the extract ledger ----",
    }, {
      "expr" = "m['uappPartCleanCount']() != 19  or m['uappPartGarbledCount']() != 0",
      "note" = "---- the R376 potions seam ----",
    }, {
      "expr" = "m['uadsScrollSplitLo']() != 85  or  m['uadsScrollSecondTableIsIIB2']() != 1  or m['uadsRowBodiesGarble']()",
      "note" = "---- the R375 skeleton seam ----",
    } },
  "audit" = {
      "label" = "R377: the UA new scrolls protection prose pin audit",
      "comment" = "The eleven clean protection-scroll types (pp. 91-93): acid, breath weapons (dragon and non-dragon), fire, gas, illusions, paralyzation, plants, poison, the traps trio (50 mechanical, 30 magical, 20 any), water. The four garbled types (cold, electricity, the two weapons scrolls) filled by the R397 clean read. The R376 seam cross-checks the potions ledger, the R375 seam the scroll splits; the census 303 -> 304.",
    },
}
