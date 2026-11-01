-- oa743: promoted from rules/oa114armorprose.h (the OA TREASURE - THE ARMOR AND SHIELD PROSE, printed capture p. 289 - the);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 743,
  "prefix" = "oa743",
  "banner" = {
      "title" = "OA TREASURE - THE ARMOR AND SHIELD PROSE, printed capture p. 289 - the",
      "provenance" = "armor determination round census 665 -> 666.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift  the gap census after this round: 196 closed, 39 open - the armor prose box flips (census 665 -> 666); NEXT - R744: Table 75: Magical Armor (capture p. 289), prefix dlf (verify free at the landing), audit \"R744 OA Table 75 armor audit\", include after rules/oa114armorprose.h",
    },
  "consts" = { {
      "name" = "dleDetermineTypeAndProperties",
      "value" = 1,
      "comment" = "the purpose - to determine the type of magical armor found and its properties (print capture p. 289)",
    }, {
      "name" = "dleRollOrSelect",
      "value" = 1,
      "comment" = "the freedom - the DM randomly rolls on the following tables or selects from the tables the features he wants (print capture p. 289)",
    }, {
      "name" = "dleTypeTable",
      "value" = 75,
      "comment" = "the type table number - the Table 75 Magical Armor rolled first to determine the armor type (print capture p. 289)",
    }, {
      "name" = "dlePropertyTableFirst",
      "value" = 76,
      "comment" = "the first property table - the Table 76 Magical Armor Properties rolled after the type (print capture p. 289)",
    }, {
      "name" = "dlePropertyTableSecond",
      "value" = 77,
      "comment" = "the second property table - the Table 77 Special Properties of the armor (print capture p. 289)",
    }, {
      "name" = "dleFirstStepRollTable75",
      "value" = 1,
      "comment" = "the first step - roll on the Table 75 to determine the armor type (print capture p. 289)",
    }, {
      "name" = "dleThenRollTables76And77",
      "value" = 1,
      "comment" = "the second step - after determining the type of armor, roll on the Tables 76 and 77 to determine its properties (print capture p. 289)",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dleTypeTable']() != 75  or m['dlePropertyTableFirst']() != 76  or m['dlePropertyTableSecond']() != 77  or  m['dleDetermineTypeAndProperties']() != 1  or  m['dleRollOrSelect']() != 1  or  m['dleFirstStepRollTable75']() != 1  or  m['dleThenRollTables76And77']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dleDetermineTypeAndProperties']() != 1  or m['dleRollOrSelect']() != 1  or m['dleFirstStepRollTable75']() != 1  or m['dleThenRollTables76And77']() != 1",
      "note" = "the prose - the determination and the two steps, healthy values, each condition false",
    }, {
      "expr" = "m['dleTypeTable']() != 75  or m['dlePropertyTableFirst']() != 76  or m['dlePropertyTableSecond']() != 77",
      "note" = "the table numbers - the 75, 76, and 77 of the type and property rolls, healthy values, each condition false",
    } },
  "audit" = {
      "label" = "R743 OA armor shield audit",
      "comment" = "OA round one hundred thirty (capture p. 289): the Armor and Shield section prose - the DM roll-or-select freedom, the Table 75 first step for the armor type, the Tables 76 and 77 second step for the properties, single-pass pins per the Chapter 9 provenance shift",
    },
}
