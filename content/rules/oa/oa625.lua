-- oa625: promoted from rules/oa/oasohei.h (the THE SOHEI, printed capture pp. 45-47 - the OA sohei round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 625,
  "prefix" = "oa625",
  "banner" = {
      "title" = "THE SOHEI, printed capture pp. 45-47 - the OA sohei round",
      "provenance" = "census 547 -> 548.  verified against capture pp. 45-47 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). Two cells settled against the 2018 print BEFORE pinning, per the settling doctrine: the T29 row-4 level cell (the capture prints 3 against four dice; the 2018 prints 4) and the fanaticism roll bonus (the capture prints plus 2; the 2018 prints minus 2, a lost plus against the sustain-himself reading). The T30 row 0 covers the printed levels 1-5 blank row; row k is level k plus 5. The dashes pin as zeros. OCR normalization: 1stlevel reads as 1st-level (prose only)  the gap census after this round: 52 closed, 183 open - the sohei boxes with Tables 29 and 30 flip (census 547 -> 548); NEXT - R626: the Wu Jen, capture pp. 47-51, Table 31, prefix dgm (verify free), audit \"R626 OA wu jen audit\", include after rules/oa/oasohei.h",
    },
  "consts" = { {
      "name" = "dglSoheiMinStr",
      "value" = 13,
      "comment" = "Sohei prose (capture p. 46): the Strength minimum",
    }, {
      "name" = "dglSoheiMinWis",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 46): the Wisdom minimum",
    }, {
      "name" = "dglSoheiMinCon",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 46): the Constitution minimum",
    }, {
      "name" = "dglSoheiBonusStat",
      "value" = 15,
      "comment" = "Sohei prose (capture p. 46): both Strength and Wisdom 15 or greater earn the 10 percent experience bonus",
    }, {
      "name" = "dglSoheiBonusPct",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 46): the bonus value",
    }, {
      "name" = "dglSoheiHitDie",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 46): the 10-sided hit die, one per level",
    }, {
      "name" = "dglSoheiSlots",
      "value" = 4,
      "comment" = "Sohei prose (capture p. 46): four proficiency slots at the beginning, any allowed weapon or peaceful art",
    }, {
      "name" = "dglSoheiWeaponChoiceBonus",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): the weapon of choice earns +1 on to hit and damage rolls",
    }, {
      "name" = "dglSoheiKiLevel",
      "value" = 3,
      "comment" = "Sohei prose (capture p. 47): the berserk ki focus at 3rd level",
    }, {
      "name" = "dglSoheiKiDurationTurns",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): the berserk state lasts one turn",
    }, {
      "name" = "dglSoheiKiPerDay",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): the berserk ki once per day",
    }, {
      "name" = "dglSoheiKiExtraAttacks",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): one extra attack per round in the berserk state",
    }, {
      "name" = "dglSoheiKiAcBonus",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): the Armor Class improves by 1 in the berserk state",
    }, {
      "name" = "dglSoheiKiMoveBonus",
      "value" = 3,
      "comment" = "Sohei prose (capture p. 47): the movement increases by 3 feet in the berserk state",
    }, {
      "name" = "dglSoheiKiRollBonus",
      "value" = 1,
      "comment" = "Sohei prose (capture p. 47): an additional +1 on to hit, damage and saving throw rolls in the berserk state",
    }, {
      "name" = "dglSoheiFanaticLevel",
      "value" = 5,
      "comment" = "Sohei prose (capture p. 47): the fanaticism at 5th level - fighting on after 0 hit points",
    }, {
      "name" = "dglSoheiFanaticDeathHp",
      "value" = -10,
      "comment" = "Sohei prose (capture p. 47): the fight continues until -10 hit points or the enemy is defeated",
    }, {
      "name" = "dglSoheiFanaticRollBonus",
      "value" = 2,
      "comment" = "Sohei prose (capture p. 47): the +2 on to hit and damage rolls from the final ki reserves - the 2018 print lost the plus",
    }, {
      "name" = "dglSoheiCommandLevel",
      "value" = 6,
      "comment" = "Sohei prose (capture p. 47): the command over other sohei at 6th level",
    }, {
      "name" = "dglSoheiCommandMin",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 47): command over 10-30 other sohei, all 1st level",
    }, {
      "name" = "dglSoheiCommandMax",
      "value" = 30,
      "comment" = "Sohei prose (capture p. 47): the command upper bound",
    }, {
      "name" = "dglSoheiCommandStep",
      "value" = 10,
      "comment" = "Sohei prose (capture p. 47): the command grows by 10 sohei per level above 6th",
    }, {
      "name" = "dglSoheiCommissionLevel",
      "value" = 9,
      "comment" = "Sohei prose (capture p. 47): the monastery commission at 9th level",
    }, {
      "name" = "dglSoheiOffCauseXpDiv",
      "value" = 2,
      "comment" = "Sohei prose (capture p. 47): full experience only for the monastery cause - one-half otherwise",
    }, {
      "name" = "dglT29RowCount",
      "value" = 12,
      "comment" = "Table 29 (capture p. 45): twelve rows, levels 1-12",
    }, {
      "name" = "dglT29XpBeyond",
      "value" = 200000,
      "comment" = "Table 29 note (capture pp. 45-46): 200,000 experience points are required for each level beyond 12th",
    }, {
      "name" = "dglT29HpBeyond",
      "value" = 1,
      "comment" = "Table 29 note (capture p. 46): sohei gain 1 hp per level beyond 9th",
    }, {
      "name" = "dglT30RowCount",
      "value" = 25,
      "comment" = "Table 30 (capture p. 46): the levels 1-5 blank row plus the 6th through 29th rows - row 0 covers levels 1-5, row k is level k plus 5",
    }, {
      "name" = "dglT30SpellLevels",
      "value" = 4,
      "comment" = "Table 30 (capture p. 46): four spell-level columns, 1st through 4th",
    }, {
      "name" = "dglT30FirstSpellLevel",
      "value" = 6,
      "comment" = "Table 30 (capture p. 46): no spells until 6th level",
    }, {
      "name" = "dglT30MaxCastable",
      "value" = 7,
      "comment" = "Table 30 (capture p. 46): the maximum castable per spell level - seven 1st through six 4th",
    } },
  "bools" = { {
      "name" = "dglSoheiDualPrime",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): two prime requisites - Strength and Wisdom",
    }, {
      "name" = "dglSoheiLawfulOnly",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): must be lawful - good, neutral or evil, regardless of the home monastery alignment",
    }, {
      "name" = "dglSoheiClericTables",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): the combat and saving throw tables of clerics",
    }, {
      "name" = "dglSoheiAnyArmor",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): allowed any armor and the Table 13 weapons",
    }, {
      "name" = "dglSoheiCastShukenjaSpells",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): at higher levels casts shukenja spells - only the listed ones, with the same Table 27 bonuses and failure chances",
    }, {
      "name" = "dglSoheiMilitant",
      "value" = true,
      "comment" = "Sohei prose (capture p. 46): more militant than holy, subject to the leader of the temple, defending the monastery and advancing its claims",
    }, {
      "name" = "dglSoheiWeaponChoiceProficiency",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the weapon of choice must be one with which he already has proficiency",
    }, {
      "name" = "dglSoheiKiMissileDeflection",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): in the berserk state he can dodge or deflect missile weapons with a successful save vs breath weapon",
    }, {
      "name" = "dglSoheiFanaticFinalAct",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the fanaticism is a final act - no other actions, then collapse and death, earning posthumous honor",
    }, {
      "name" = "dglSoheiCommandReplaceable",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the fallen in the command are always replaced by additional 1st-level sohei",
    }, {
      "name" = "dglSoheiCommandLostIfSlain",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the command is lost only if all within it other than the commander are slain",
    }, {
      "name" = "dglSoheiCommissionCommander",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the commission makes him the commander of all sohei at the new monastery, still subject to the parent",
    }, {
      "name" = "dglSoheiFishAllowed",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): the less-strict rules - no meat but fish is allowed, no excess; no injunction against killing or violence though outright murder is a sin",
    }, {
      "name" = "dglSoheiAnyCaste",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): any caste, no Table 38 roll required - the monastery is the new family",
    }, {
      "name" = "dglSoheiHonorImportant",
      "value" = true,
      "comment" = "Sohei prose (capture p. 47): affected by honor more than a shukenja, but never gains honor for the actions of his monastery",
    } },
  "switches" = { {
      "name" = "dglT29XpMax",
      "values" = { 2000, 4000, 7000, 13000, 24000, 48000, 85000, 150000, 350000, 550000, 750000, 950000 },
      "default" = -99,
      "comment" = "the experience column: the upper xp bound of each level, 2,000 at 1st to 950,000 at 12th (capture p. 45).",
    }, {
      "name" = "dglT29Dice",
      "values" = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9 },
      "default" = -99,
      "comment" = "the accumulated d10 dice column: one per level through 9th, then held at 9 - the row-4 level cell OCR-mangled in the capture (3 against four dice) and settled against the 2018 print as level 4 (capture p. 45).",
    }, {
      "name" = "dglT29HpBonus",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 },
      "default" = -99,
      "comment" = "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 45).",
    }, {
      "name" = "dglT30S1",
      "values" = { 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7 },
      "default" = -99,
      "comment" = "the 1st-level spells column: the row 0 levels 1-5 blank, then 1 at 6th to 7 at 29th - the row index is the level minus 5 (capture p. 46).",
    }, {
      "name" = "dglT30S2",
      "values" = { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7 },
      "default" = -99,
      "comment" = "the 2nd-level spells column: none until 7th, then 1 to 7 at 29th (capture p. 46).",
    }, {
      "name" = "dglT30S3",
      "values" = { 0, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6 },
      "default" = -99,
      "comment" = "the 3rd-level spells column: none until 10th, then 1 to 6 at 29th (capture p. 46).",
    }, {
      "name" = "dglT30S4",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6 },
      "default" = -99,
      "comment" = "the 4th-level spells column: none until 15th, then 1 to 6 at 29th (capture p. 46).",
    } },
  "tables" = { {
      "name" = "dglT29Grid",
      "tag" = "T29",
      "count" = "dglT29RowCount",
      "sentinel" = -99,
      "cols" = { "dglT29XpMax", "dglT29Dice", "dglT29HpBonus" },
      "data" = { { 2000, 1, 0 }, { 4000, 2, 0 }, { 7000, 3, 0 }, { 13000, 4, 0 }, { 24000, 5, 0 }, { 48000, 6, 0 }, { 85000, 7, 0 }, { 150000, 8, 0 }, { 350000, 9, 0 }, { 550000, 9, 1 }, { 750000, 9, 2 }, { 950000, 9, 3 } },
      "comment" = "the Table 29 sohei advancement grid (capture p. 45)",
      "col_comments" = { "the experience column: the upper xp bound of each level, 2,000 at 1st to 950,000 at 12th (capture p. 45).", "the accumulated d10 dice column: one per level through 9th, then held at 9 - the row-4 level cell OCR-mangled in the capture (3 against four dice) and settled against the 2018 print as level 4 (capture p. 45).", "the hit-point bonus column: the printed 9-plus-N cells - 1 hp per level beyond 9th: 0 through 9th, then 1, 2, 3 (capture p. 45)." },
      "audit_comment" = "the Table 29 grid: the xp bounds and the accumulated dice plus bonus (capture p. 45)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dglT30Grid",
      "tag" = "T30",
      "count" = "dglT30RowCount",
      "sentinel" = -99,
      "cols" = { "dglT30S1", "dglT30S2", "dglT30S3", "dglT30S4" },
      "data" = { { 0, 0, 0, 0 }, { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 2, 1, 0, 0 }, { 2, 2, 0, 0 }, { 2, 2, 1, 0 }, { 3, 2, 1, 0 }, { 3, 2, 2, 0 }, { 3, 3, 2, 0 }, { 3, 3, 3, 0 }, { 3, 3, 3, 1 }, { 3, 3, 3, 2 }, { 4, 3, 3, 2 }, { 4, 4, 3, 2 }, { 4, 4, 4, 3 }, { 5, 4, 4, 3 }, { 5, 5, 4, 3 }, { 5, 5, 4, 4 }, { 5, 5, 5, 4 }, { 6, 5, 5, 4 }, { 6, 6, 5, 4 }, { 6, 6, 5, 5 }, { 6, 6, 6, 5 }, { 6, 6, 6, 6 }, { 7, 7, 6, 6 } },
      "comment" = "the Table 30 sohei spells usable by level grid (capture p. 46)",
      "col_comments" = { "the 1st-level spells column: the row 0 levels 1-5 blank, then 1 at 6th to 7 at 29th - the row index is the level minus 5 (capture p. 46).", "the 2nd-level spells column: none until 7th, then 1 to 7 at 29th (capture p. 46).", "the 3rd-level spells column: none until 10th, then 1 to 6 at 29th (capture p. 46).", "the 4th-level spells column: none until 15th, then 1 to 6 at 29th (capture p. 46)." },
      "audit_comment" = "the Table 30 grid: the four spell-level columns, levels 1-29 (capture p. 46)",
      "sentinel_census" = { 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dglSoheiMinStr']() != 13  or m['dglSoheiMinWis']() != 10  or m['dglSoheiMinCon']() != 10  or m['dglSoheiBonusStat']() != 15  or m['dglSoheiBonusPct']() != 10  or m['dglSoheiHitDie']() != 10  or m['dglSoheiSlots']() != 4  or m['dglSoheiWeaponChoiceBonus']() != 1  or m['dglSoheiKiLevel']() != 3  or m['dglSoheiKiDurationTurns']() != 1  or m['dglSoheiKiPerDay']() != 1  or m['dglSoheiKiExtraAttacks']() != 1  or m['dglSoheiKiAcBonus']() != 1  or m['dglSoheiKiMoveBonus']() != 3  or m['dglSoheiKiRollBonus']() != 1  or m['dglSoheiFanaticLevel']() != 5  or m['dglSoheiFanaticDeathHp']() != -10  or m['dglSoheiFanaticRollBonus']() != 2  or m['dglSoheiCommandLevel']() != 6  or m['dglSoheiCommandMin']() != 10  or m['dglSoheiCommandMax']() != 30  or m['dglSoheiCommandStep']() != 10  or m['dglSoheiCommissionLevel']() != 9  or m['dglSoheiOffCauseXpDiv']() != 2  or m['dglT29RowCount']() != 12  or m['dglT29XpBeyond']() != 200000  or m['dglT29HpBeyond']() != 1  or m['dglT30RowCount']() != 25  or m['dglT30SpellLevels']() != 4  or m['dglT30FirstSpellLevel']() != 6  or m['dglT30MaxCastable']() != 7  or  m['dglSoheiLawfulOnly']() != 1  or  m['dglSoheiDualPrime']() != 1  or  m['dglSoheiClericTables']() != 1  or  m['dglSoheiAnyArmor']() != 1  or  m['dglSoheiCastShukenjaSpells']() != 1  or  m['dglSoheiMilitant']() != 1  or  m['dglSoheiWeaponChoiceProficiency']() != 1  or  m['dglSoheiKiMissileDeflection']() != 1  or  m['dglSoheiFanaticFinalAct']() != 1  or  m['dglSoheiCommandReplaceable']() != 1  or  m['dglSoheiCommandLostIfSlain']() != 1  or  m['dglSoheiCommissionCommander']() != 1  or  m['dglSoheiFishAllowed']() != 1  or  m['dglSoheiAnyCaste']() != 1  or  m['dglSoheiHonorImportant']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dglSoheiMinStr']() != 13",
      "note" = "the dglSoheiMinStr pin",
    }, {
      "expr" = "m['dglSoheiMinWis']() != 10",
      "note" = "the dglSoheiMinWis pin",
    }, {
      "expr" = "m['dglSoheiMinCon']() != 10",
      "note" = "the dglSoheiMinCon pin",
    }, {
      "expr" = "m['dglSoheiBonusStat']() != 15",
      "note" = "the dglSoheiBonusStat pin",
    }, {
      "expr" = "m['dglSoheiBonusPct']() != 10",
      "note" = "the dglSoheiBonusPct pin",
    }, {
      "expr" = "m['dglSoheiHitDie']() != 10",
      "note" = "the dglSoheiHitDie pin",
    }, {
      "expr" = "m['dglSoheiSlots']() != 4",
      "note" = "the dglSoheiSlots pin",
    }, {
      "expr" = "m['dglSoheiWeaponChoiceBonus']() != 1",
      "note" = "the dglSoheiWeaponChoiceBonus pin",
    }, {
      "expr" = "m['dglSoheiKiLevel']() != 3",
      "note" = "the dglSoheiKiLevel pin",
    }, {
      "expr" = "m['dglSoheiKiDurationTurns']() != 1",
      "note" = "the dglSoheiKiDurationTurns pin",
    }, {
      "expr" = "m['dglSoheiKiPerDay']() != 1",
      "note" = "the dglSoheiKiPerDay pin",
    }, {
      "expr" = "m['dglSoheiKiExtraAttacks']() != 1",
      "note" = "the dglSoheiKiExtraAttacks pin",
    }, {
      "expr" = "m['dglSoheiKiAcBonus']() != 1",
      "note" = "the dglSoheiKiAcBonus pin",
    }, {
      "expr" = "m['dglSoheiKiMoveBonus']() != 3",
      "note" = "the dglSoheiKiMoveBonus pin",
    }, {
      "expr" = "m['dglSoheiKiRollBonus']() != 1",
      "note" = "the dglSoheiKiRollBonus pin",
    }, {
      "expr" = "m['dglSoheiFanaticLevel']() != 5",
      "note" = "the dglSoheiFanaticLevel pin",
    }, {
      "expr" = "m['dglSoheiFanaticDeathHp']() != -10",
      "note" = "the dglSoheiFanaticDeathHp pin",
    }, {
      "expr" = "m['dglSoheiFanaticRollBonus']() != 2",
      "note" = "the dglSoheiFanaticRollBonus pin",
    }, {
      "expr" = "m['dglSoheiCommandLevel']() != 6",
      "note" = "the dglSoheiCommandLevel pin",
    }, {
      "expr" = "m['dglSoheiCommandMin']() != 10",
      "note" = "the dglSoheiCommandMin pin",
    }, {
      "expr" = "m['dglSoheiCommandMax']() != 30",
      "note" = "the dglSoheiCommandMax pin",
    }, {
      "expr" = "m['dglSoheiCommandStep']() != 10",
      "note" = "the dglSoheiCommandStep pin",
    }, {
      "expr" = "m['dglSoheiCommissionLevel']() != 9",
      "note" = "the dglSoheiCommissionLevel pin",
    }, {
      "expr" = "m['dglSoheiOffCauseXpDiv']() != 2",
      "note" = "the dglSoheiOffCauseXpDiv pin",
    }, {
      "expr" = "m['dglT29RowCount']() != 12",
      "note" = "the dglT29RowCount pin",
    }, {
      "expr" = "m['dglT29XpBeyond']() != 200000",
      "note" = "the dglT29XpBeyond pin",
    }, {
      "expr" = "m['dglT29HpBeyond']() != 1",
      "note" = "the dglT29HpBeyond pin",
    }, {
      "expr" = "m['dglT30RowCount']() != 25",
      "note" = "the dglT30RowCount pin",
    }, {
      "expr" = "m['dglT30SpellLevels']() != 4",
      "note" = "the dglT30SpellLevels pin",
    }, {
      "expr" = "m['dglT30FirstSpellLevel']() != 6",
      "note" = "the dglT30FirstSpellLevel pin",
    }, {
      "expr" = "m['dglT30MaxCastable']() != 7",
      "note" = "the dglT30MaxCastable pin",
    }, {
      "expr" = "m['dglSoheiLawfulOnly']() != 1",
      "note" = "the dglSoheiLawfulOnly pin",
    }, {
      "expr" = "m['dglSoheiDualPrime']() != 1",
      "note" = "the dglSoheiDualPrime pin",
    }, {
      "expr" = "m['dglSoheiClericTables']() != 1",
      "note" = "the dglSoheiClericTables pin",
    }, {
      "expr" = "m['dglSoheiAnyArmor']() != 1",
      "note" = "the dglSoheiAnyArmor pin",
    }, {
      "expr" = "m['dglSoheiCastShukenjaSpells']() != 1",
      "note" = "the dglSoheiCastShukenjaSpells pin",
    }, {
      "expr" = "m['dglSoheiMilitant']() != 1",
      "note" = "the dglSoheiMilitant pin",
    }, {
      "expr" = "m['dglSoheiWeaponChoiceProficiency']() != 1",
      "note" = "the dglSoheiWeaponChoiceProficiency pin",
    }, {
      "expr" = "m['dglSoheiKiMissileDeflection']() != 1",
      "note" = "the dglSoheiKiMissileDeflection pin",
    }, {
      "expr" = "m['dglSoheiFanaticFinalAct']() != 1",
      "note" = "the dglSoheiFanaticFinalAct pin",
    }, {
      "expr" = "m['dglSoheiCommandReplaceable']() != 1",
      "note" = "the dglSoheiCommandReplaceable pin",
    }, {
      "expr" = "m['dglSoheiCommandLostIfSlain']() != 1",
      "note" = "the dglSoheiCommandLostIfSlain pin",
    }, {
      "expr" = "m['dglSoheiCommissionCommander']() != 1",
      "note" = "the dglSoheiCommissionCommander pin",
    }, {
      "expr" = "m['dglSoheiFishAllowed']() != 1",
      "note" = "the dglSoheiFishAllowed pin",
    }, {
      "expr" = "m['dglSoheiAnyCaste']() != 1",
      "note" = "the dglSoheiAnyCaste pin",
    }, {
      "expr" = "m['dglSoheiHonorImportant']() != 1",
      "note" = "the dglSoheiHonorImportant pin",
    }, {
      "expr" = "m['dglT29XpMax'](0) != 2000  or m['dglT29Dice'](0) != 1  or m['dglT29HpBonus'](0) != 0",
      "note" = "the T29 first row - 2,000 xp, one die (capture p. 45)",
    }, {
      "expr" = "m['dglT29XpMax'](3) != 13000  or m['dglT29Dice'](3) != 4  or m['dglT29Dice'](4) != 5",
      "note" = "the T29 row-4 cell settled - 13,000 xp is level 4 with four dice, the capture printed 3 (capture p. 45)",
    }, {
      "expr" = "m['dglT29XpMax'](11) != 950000  or m['dglT29Dice'](11) != 9  or m['dglT29HpBonus'](11) != 3",
      "note" = "the T29 capstone - 950,000 xp, nine dice plus three (capture p. 45)",
    }, {
      "expr" = "m['dglT29Dice'](9) != 9  or m['dglT29HpBonus'](9) != 1",
      "note" = "the T29 9-plus-N cells open on the 10th-level row (capture p. 45)",
    }, {
      "expr" = "m['dglT30S1'](0) != 0  or m['dglT30S4'](0) != 0",
      "note" = "the T30 row 0 - the levels 1-5 blank (capture p. 46)",
    }, {
      "expr" = "m['dglT30S1'](1) != 1  or m['dglT30S2'](2) != 1  or m['dglT30S3'](5) != 1  or m['dglT30S4'](10) != 1",
      "note" = "the T30 openings - the 1st at 6th, the 2nd at 7th, the 3rd at 10th, the 4th at 15th (capture p. 46)",
    }, {
      "expr" = "m['dglT30S1'](24) != 7  or m['dglT30S2'](24) != 7  or m['dglT30S3'](24) != 6  or m['dglT30S4'](24) != 6",
      "note" = "the T30 capstone - the 29th-level row (capture p. 46)",
    }, {
      "expr" = "m['dglSoheiKiExtraAttacks']() != 1  or m['dglSoheiKiAcBonus']() != 1  or m['dglSoheiKiMoveBonus']() != 3  or m['dglSoheiKiRollBonus']() != 1",
      "note" = "the berserk ki riders - the extra attack, AC, movement and roll bonuses (capture p. 47)",
    }, {
      "expr" = "m['dglSoheiFanaticDeathHp']() != -10  or m['dglSoheiFanaticRollBonus']() != 2",
      "note" = "the fanaticism bounds - the -10 death floor with the +2 reserves (capture p. 47)",
    }, {
      "expr" = "m['dglSoheiCommandMin']() != 10  or m['dglSoheiCommandMax']() != 30  or m['dglSoheiCommandStep']() != 10",
      "note" = "the command ladder - 10-30 sohei plus 10 per level above 6th (capture p. 47)",
    } },
  "audit" = {
      "label" = "R625 OA sohei audit",
      "comment" = "OA round twelve (capture pp. 45-47): the sohei - the minima, the ki powers, the command doctrine, and the advancement and spell grids",
    },
}
