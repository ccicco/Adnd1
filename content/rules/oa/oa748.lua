-- oa748: promoted from rules/oa119weaponsprose.h (the OA TREASURE - THE WEAPONS PROSE, printed capture pp. 291-294 - the weapons);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 748,
  "prefix" = "oa748",
  "banner" = {
      "title" = "OA TREASURE - THE WEAPONS PROSE, printed capture pp. 291-294 - the weapons",
      "provenance" = "flow round census 670 -> 671.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 201 closed, 34 open - the weapons prose box flips (census 670 -> 671); NEXT - R749: Table 78: Magical Weapons (capture p. 291), prefix dlk (verify free at the landing), audit \"R749 OA Table 78 weapons audit\", include after rules/oa119weaponsprose.h",
    },
  "consts" = { {
      "name" = "dljRolledOnTableIII",
      "value" = 1,
      "comment" = "the trigger - the magical weapon rolled on the Table III of the DMG (print capture p. 291)",
    }, {
      "name" = "dljGeneralTypeTable",
      "value" = 78,
      "comment" = "the general type table - the Table 78 rolled to determine the general type of weapon (print capture p. 291)",
    }, {
      "name" = "dljStepOneGeneralType",
      "value" = 1,
      "comment" = "the first step - roll on the Table 78 to determine the general type of weapon (print capture p. 291)",
    }, {
      "name" = "dljPropertyTable",
      "value" = 79,
      "comment" = "the property table - the Table 79 rolled to find the magical property of the weapon (print capture p. 291)",
    }, {
      "name" = "dljStepTwoProperty",
      "value" = 1,
      "comment" = "the second step - roll on the Table 79 to find the magical property of the weapon (print capture p. 291)",
    }, {
      "name" = "dljSpecificTableFirst",
      "value" = 80,
      "comment" = "the first specific table - the Table 80 opening the range of the specific type tables (print capture p. 291)",
    }, {
      "name" = "dljSpecificTableLast",
      "value" = 85,
      "comment" = "the last specific table - the Table 85 closing the range of the specific type tables (print capture p. 291)",
    }, {
      "name" = "dljStepThreeSpecificType",
      "value" = 1,
      "comment" = "the third step - roll on the appropriate table of the Tables 80-85 to determine the specific type of weapon (print capture p. 291)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dljGeneralTypeTable']() != 78  or m['dljPropertyTable']() != 79  or m['dljSpecificTableFirst']() != 80  or m['dljSpecificTableLast']() != 85  or  m['dljRolledOnTableIII']() != 1  or  m['dljStepOneGeneralType']() != 1  or  m['dljStepTwoProperty']() != 1  or  m['dljStepThreeSpecificType']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dljRolledOnTableIII']() != 1  or m['dljStepOneGeneralType']() != 1  or m['dljStepTwoProperty']() != 1  or m['dljStepThreeSpecificType']() != 1",
      "note" = "the prose - the trigger and the three steps, healthy values, each condition false",
    }, {
      "expr" = "m['dljGeneralTypeTable']() != 78  or m['dljPropertyTable']() != 79  or m['dljSpecificTableFirst']() != 80  or m['dljSpecificTableLast']() != 85",
      "note" = "the table numbers - the 78, 79, and the 80-85 range of the flow, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R748 OA weapons prose audit",
      "comment" = "OA round one hundred thirty-five (capture p. 291): the Weapons section prose - the Table III trigger, the Table 78 general type step, the Table 79 property step, the Tables 80-85 specific type step, single-pass pins per the Chapter 9 provenance shift",
    },
}
