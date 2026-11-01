-- wgr: promoted from tools/spec_r496.json (the The WSG GAP RECONCILIATION, R496: the bookkeeping round that closes the distance between the gap report and the landed pins. The WSG arc rounds R425-R495 pinned every section of the book, but twenty-four boxes were never ticked: eleven chapter parents whose children all closed, nine manifest table lines whose grids landed with their chapter rounds, and the four movement items that pin inside the R435/R434/R432 headers.);
-- DO NOT hand-edit; the spec JSON stays the adjudicated record.
return {
  "round" = 496,
  "prefix" = "wgr",
  "banner" = {
      "title" = "The WSG GAP RECONCILIATION, R496: the bookkeeping round that closes the distance between the gap report and the landed pins. The WSG arc rounds R425-R495 pinned every section of the book, but twenty-four boxes were never ticked: eleven chapter parents whose children all closed, nine manifest table lines whose grids landed with their chapter rounds, and the four movement items that pin inside the R435/R434/R432 headers.",
      "provenance" = "This round pins no new book material: every flipped box is verified against its landed original (rules/wsgenvfx.h, wsgencum.h, wsgvehicle.h, wsgclimb.h, wsggrap.h, wsgchasm.h, wsgjump.h, wsgvis.h, wsgswim.h, wsgvessels.h, wsgcapsizing.h, wsgflymounts.h, wsgmount.h and the chapter headers). What remains open after this round: the overview chapter (pp. 7-10, eleven boxes - the seven terrain descriptions, the hierarchy of terrain, the bodies of water, the climate) and the wilderness proficiencies prose (pp. 11-17, four boxes - the nonweapon list, the choosing-skills rules, the proficiency descriptions).",
      "sentinel" = "THE SETTLE: the gap report lands at 171 closed / 15 open, every open box a genuinely un-pinned prose stretch; census 420 -> 421.",
    },
  "consts" = { {
      "name" = "wgrClosedBefore",
      "value" = 147,
      "comment" = "the gap report at the R495 landing reads 147 closed boxes.",
    }, {
      "name" = "wgrOpenBefore",
      "value" = 39,
      "comment" = "the gap report at the R495 landing reads 39 open boxes.",
    }, {
      "name" = "wgrFlippedCount",
      "value" = 24,
      "comment" = "this round flips twenty-four boxes that were already pinned by earlier rounds but never ticked.",
    }, {
      "name" = "wgrClosedAfter",
      "value" = 171,
      "comment" = "after this round the report reads 171 closed boxes.",
    }, {
      "name" = "wgrOpenAfter",
      "value" = 15,
      "comment" = "after this round the report reads 15 open boxes - every one a genuinely un-pinned prose stretch.",
    }, {
      "name" = "wgrCensusBefore",
      "value" = 420,
      "comment" = "the audit census at the R495 landing.",
    }, {
      "name" = "wgrCensusAfter",
      "value" = 421,
      "comment" = "the audit census after this round.",
    }, {
      "name" = "wgrChapterParents",
      "value" = 11,
      "comment" = "eleven chapter parents flip - each with every child already closed by a landed round.",
    }, {
      "name" = "wgrManifestLines",
      "value" = 9,
      "comment" = "nine manifest table lines flip - Tables 20-27 and 42, each pinned with its chapter round.",
    }, {
      "name" = "wgrClimbItems",
      "value" = 3,
      "comment" = "three climbing items flip - the surface types, the surface conditions and the chance of falling.",
    }, {
      "name" = "wgrSpecialTerrainItems",
      "value" = 1,
      "comment" = "the movement across special terrain item flips - the vehicle and snow rules of R434/R432.",
    }, {
      "name" = "wgrOverviewOpen",
      "value" = 11,
      "comment" = "the overview chapter keeps eleven open boxes - the parent and its ten children (pp. 7-10).",
    }, {
      "name" = "wgrProficienciesOpen",
      "value" = 4,
      "comment" = "the wilderness proficiencies chapter keeps four open boxes - the parent, the nonweapon list, the choosing rules and the descriptions (pp. 11-17).",
    } },
  "bools" = { {
      "name" = "wgrEnvFxParentOk",
      "value" = true,
      "comment" = "effects of the environment: every child closed by R427, R429, R430 and R431.",
    }, {
      "name" = "wgrEncumMoveParentOk",
      "value" = true,
      "comment" = "encumbrance and movement: every child closed by R432 through R450 (and the four R496 flips below).",
    }, {
      "name" = "wgrFoodWaterParentOk",
      "value" = true,
      "comment" = "food and water: every child closed by R462 through R470.",
    }, {
      "name" = "wgrCampParentOk",
      "value" = true,
      "comment" = "camping and campfires: every child closed by R471 through R477.",
    }, {
      "name" = "wgrMedicineParentOk",
      "value" = true,
      "comment" = "medicine and first aid: every child closed by R478 through R481.",
    }, {
      "name" = "wgrVisionParentOk",
      "value" = true,
      "comment" = "vision and visibility: every child closed by R482 through R485.",
    }, {
      "name" = "wgrHazardsParentOk",
      "value" = true,
      "comment" = "natural hazards: every child closed by R486 and R487.",
    }, {
      "name" = "wgrCombatParentOk",
      "value" = true,
      "comment" = "wilderness combat: every child closed by R488 and R489.",
    }, {
      "name" = "wgrFatigueParentOk",
      "value" = true,
      "comment" = "fatigue and exhaustion: every child closed by R489.",
    }, {
      "name" = "wgrMountsParentOk",
      "value" = true,
      "comment" = "mounts and beasts of burden: every child closed by R490.",
    }, {
      "name" = "wgrMagicParentOk",
      "value" = true,
      "comment" = "magic in the wilderness: every child closed by R491.",
    }, {
      "name" = "wgrT20Pinned",
      "value" = true,
      "comment" = "Table 20 pins with the grappling-hook round R444 (rules/wsggrap.h - the ten terrain rows with the catch chances).",
    }, {
      "name" = "wgrT21Pinned",
      "value" = true,
      "comment" = "Table 21 pins with the chasm-crossing round R445 (rules/wsgchasm.h - the five level-band ranges).",
    }, {
      "name" = "wgrT22Pinned",
      "value" = true,
      "comment" = "Table 22 pins with the jumping round R448 (rules/wsgjump.h - the seven distance bands).",
    }, {
      "name" = "wgrT23Pinned",
      "value" = true,
      "comment" = "Table 23 pins with the reduced-visibility round R449 (rules/wsgvis.h - the three light rows by the five conditions).",
    }, {
      "name" = "wgrT24Pinned",
      "value" = true,
      "comment" = "Table 24 pins with the swimming round R450 (rules/wsgswim.h - the five encumbrance rows by the four functions).",
    }, {
      "name" = "wgrT25Pinned",
      "value" = true,
      "comment" = "Table 25 pins with the waterborne-vehicles round R455 (rules/wsgvessels.h - the eight vessels by the ten characteristics).",
    }, {
      "name" = "wgrT26Pinned",
      "value" = true,
      "comment" = "Table 26 pins with the capsizing round R456 (rules/wsgcapsizing.h - the eight vessels by the four conditions).",
    }, {
      "name" = "wgrT27Pinned",
      "value" = true,
      "comment" = "Table 27 pins with the flying-mounts round R460 (rules/wsgflymounts.h - the 41 creatures by the seven columns).",
    }, {
      "name" = "wgrT42Pinned",
      "value" = true,
      "comment" = "Table 42 pins with the mounts round R490 (rules/wsgmount.h - the reaction grid).",
    }, {
      "name" = "wgrSurfaceTypesPinned",
      "value" = true,
      "comment" = "the surface types pin with R435: the gentle (15-30 degrees), moderate (31-50), severe (51-70) and cliff (71-plus) bands with the rise rates.",
    }, {
      "name" = "wgrSurfaceConditionsPinned",
      "value" = true,
      "comment" = "the surface conditions pin with R435: the non-slippery, slightly slippery and slippery rate columns of the climbing grid.",
    }, {
      "name" = "wgrFallChancePinned",
      "value" = true,
      "comment" = "the chance of falling pins with R435: 100 minus the Climbing Rating, the non-thief base rating 40 and the mountaineering 80 with tools on a restricted surface.",
    }, {
      "name" = "wgrSpecialTerrainPinned",
      "value" = true,
      "comment" = "the movement across special terrain pins with R434 and R432: the no-very-rugged vehicle bar, the pathless one-category-worse rule and the snow-depth thresholds.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "note" = "the round counts",
      "expr" = "m['wgrClosedBefore']() != 147 or m['wgrOpenBefore']() != 39 or m['wgrFlippedCount']() != 24 or m['wgrClosedAfter']() != 171 or m['wgrOpenAfter']() != 15",
    }, {
      "note" = "the census moves by exactly one",
      "expr" = "m['wgrCensusBefore']() != 420 or m['wgrCensusAfter']() != 421",
    }, {
      "note" = "the flipped classes sum to the flip count",
      "expr" = "m['wgrChapterParents']() + m['wgrManifestLines']() + m['wgrClimbItems']() + m['wgrSpecialTerrainItems']() != m['wgrFlippedCount']()",
    }, {
      "note" = "the open boxes conserve: 39 open minus 24 flipped is 15",
      "expr" = "m['wgrOpenBefore']() - m['wgrFlippedCount']() != m['wgrOpenAfter']()",
    }, {
      "note" = "the closed boxes conserve: 147 plus 24 flipped is 171",
      "expr" = "m['wgrClosedBefore']() + m['wgrFlippedCount']() != m['wgrClosedAfter']()",
    }, {
      "note" = "the open remainder sums to 15",
      "expr" = "m['wgrOverviewOpen']() + m['wgrProficienciesOpen']() != m['wgrOpenAfter']()",
    }, {
      "note" = "eleven chapter parents and nine manifest lines flip",
      "expr" = "m['wgrChapterParents']() != 11 or m['wgrManifestLines']() != 9",
    }, {
      "note" = "three climbing items and one special-terrain item flip",
      "expr" = "m['wgrClimbItems']() != 3 or m['wgrSpecialTerrainItems']() != 1",
    }, {
      "note" = "wgrEnvFxParentOk - every child closed before the parent flips",
      "expr" = "m['wgrEnvFxParentOk']() != 1",
    }, {
      "note" = "wgrEncumMoveParentOk - every child closed before the parent flips",
      "expr" = "m['wgrEncumMoveParentOk']() != 1",
    }, {
      "note" = "wgrFoodWaterParentOk - every child closed before the parent flips",
      "expr" = "m['wgrFoodWaterParentOk']() != 1",
    }, {
      "note" = "wgrCampParentOk - every child closed before the parent flips",
      "expr" = "m['wgrCampParentOk']() != 1",
    }, {
      "note" = "wgrMedicineParentOk - every child closed before the parent flips",
      "expr" = "m['wgrMedicineParentOk']() != 1",
    }, {
      "note" = "wgrVisionParentOk - every child closed before the parent flips",
      "expr" = "m['wgrVisionParentOk']() != 1",
    }, {
      "note" = "wgrHazardsParentOk - every child closed before the parent flips",
      "expr" = "m['wgrHazardsParentOk']() != 1",
    }, {
      "note" = "wgrCombatParentOk - every child closed before the parent flips",
      "expr" = "m['wgrCombatParentOk']() != 1",
    }, {
      "note" = "wgrFatigueParentOk - every child closed before the parent flips",
      "expr" = "m['wgrFatigueParentOk']() != 1",
    }, {
      "note" = "wgrMountsParentOk - every child closed before the parent flips",
      "expr" = "m['wgrMountsParentOk']() != 1",
    }, {
      "note" = "wgrMagicParentOk - every child closed before the parent flips",
      "expr" = "m['wgrMagicParentOk']() != 1",
    }, {
      "note" = "wgrT20Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT20Pinned']() != 1",
    }, {
      "note" = "wgrT21Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT21Pinned']() != 1",
    }, {
      "note" = "wgrT22Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT22Pinned']() != 1",
    }, {
      "note" = "wgrT23Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT23Pinned']() != 1",
    }, {
      "note" = "wgrT24Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT24Pinned']() != 1",
    }, {
      "note" = "wgrT25Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT25Pinned']() != 1",
    }, {
      "note" = "wgrT26Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT26Pinned']() != 1",
    }, {
      "note" = "wgrT27Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT27Pinned']() != 1",
    }, {
      "note" = "wgrT42Pinned - the manifest line matches its landed pin",
      "expr" = "m['wgrT42Pinned']() != 1",
    }, {
      "note" = "wgrSurfaceTypesPinned - the item is pinned in an earlier header",
      "expr" = "m['wgrSurfaceTypesPinned']() != 1",
    }, {
      "note" = "wgrSurfaceConditionsPinned - the item is pinned in an earlier header",
      "expr" = "m['wgrSurfaceConditionsPinned']() != 1",
    }, {
      "note" = "wgrFallChancePinned - the item is pinned in an earlier header",
      "expr" = "m['wgrFallChancePinned']() != 1",
    }, {
      "note" = "wgrSpecialTerrainPinned - the item is pinned in an earlier header",
      "expr" = "m['wgrSpecialTerrainPinned']() != 1",
    } },
  "audit" = {
      "label" = "R496 WSG gap reconciliation audit",
      "comment" = "The WSG gap reconciliation: twenty-four boxes that were already pinned by earlier rounds flip in this same commit. The eleven chapter parents (effects of the environment R427-R431, encumbrance and movement R432-R450, food and water R462-R470, camping R471-R477, medicine R478-R481, vision R482-R485, hazards R486-R487, combat R488-R489, fatigue R489, mounts R490, magic R491). The nine manifest lines (Tables 20-27 and 42, pinned R444-R490). The four movement items (the surface types, the surface conditions and the chance of falling inside wsgclimb.h R435; the movement across special terrain inside wsgvehicle.h and wsgencum.h R434/R432). The report now reads 171 closed and 15 open; the fifteen are the overview prose (pp. 7-10) and the proficiency descriptions (pp. 11-17).",
    },
}
