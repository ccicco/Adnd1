-- oa659: promoted from rules/oal1spells.h (the FIRST LEVEL SPELLS, printed capture pp. 112-119 - the OA first level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 659,
  "prefix" = "oa659",
  "banner" = {
      "title" = "FIRST LEVEL SPELLS, printed capture pp. 112-119 - the OA first level spells",
      "provenance" = "round census 581 -> 582.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 20 first level spell stat blocks cross-checked spell by spell between the passes (print pp. 113-119; compressed pp. 58-60); all 20 schools, component sets, casting times and saving throws agree, zero contested stat reads. The compressed renders its inch marks as degree glyphs and stars (recorded as its OCR artifact class) and the print p. 113 augury prose garbles 1% per level as 1 orb per level - prose-only, nothing pinned rides it. The reversible flags agree between the passes (the compressed prints Reversible in the headers); the sohei-usable marks ride the R658 T62 grid, settled the round before. The stat grid pins as a table: 20 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1 neg., 2 special), reversible and sohei markers. The spell names ride the column comments, the prose descriptions and the Table 63 divination results close in their own rounds. The table tag L1Data identifier-safe per the R639 lesson  the gap census after this round: 112 closed, 123 open - the First Level Spells box flips (census 581 -> 582); NEXT - R660: the Second Level Spells (capture pp. 119-126), prefix dhu (verify free), audit \"R660 OA second level spells audit\", include after rules/oal1spells.h",
    },
  "consts" = { {
      "name" = "dhtL1SpellCount",
      "value" = 20,
      "comment" = "the 20 first level shukenja spells (print pp. 113-119; compressed pp. 58-60)",
    }, {
      "name" = "dhtL1SoheiCount",
      "value" = 5,
      "comment" = "the five first level spells usable by sohei - animal companion, bless, deflection, resist, weapon bless",
    }, {
      "name" = "dhtL1ReversibleCount",
      "value" = 5,
      "comment" = "the five reversible first level spells - bless, cure light wounds, deflection, detect evil, purify food & drink",
    }, {
      "name" = "dhtL1DivinationCount",
      "value" = 10,
      "comment" = "the ten divination first level spells - the most common school by half",
    }, {
      "name" = "dhtL1VSMCount",
      "value" = 12,
      "comment" = "the twelve first level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhtL1VerbalOnlyCount",
      "value" = 2,
      "comment" = "the two first level spells taking the verbal component only - beneficence and omen",
    }, {
      "name" = "dhtL1TurnCasts",
      "value" = 4,
      "comment" = "the four first level spells with a one-turn casting time - animal companion, detect harmony, omen, weapon bless",
    }, {
      "name" = "dhtL1RoundCasts",
      "value" = 12,
      "comment" = "the twelve first level spells with a one-round casting time",
    }, {
      "name" = "dhtL1SegmentCasts",
      "value" = 4,
      "comment" = "the four first level spells with a five-segment casting time - beneficence, calm, cure light wounds, snake charm",
    }, {
      "name" = "dhtL1NegSaves",
      "value" = 2,
      "comment" = "the two first level spells with a negation saving throw - animal companion and calm",
    }, {
      "name" = "dhtL1SpecialSaves",
      "value" = 2,
      "comment" = "the two first level spells with a special saving throw - deflection and know history",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhtL1School",
      "values" = { 1, 2, 3, 4, 1, 5, 3, 2, 2, 2, 2, 2, 2, 2, 2, 6, 6, 1, 2, 4 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell schools by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration; divination the most common at ten spells",
    }, {
      "name" = "dhtL1Components",
      "values" = { 7, 7, 1, 3, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 1, 3, 7, 3, 3, 7 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell components by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the component codes a bitmask: verbal 1, somatic 2, material 4 - twelve spells take all three (7), beneficence and omen take the verbal only (1), six take verbal and somatic (3)",
    }, {
      "name" = "dhtL1CastTime",
      "values" = { 60, 10, 5, 10, 5, 5, 10, 10, 10, 60, 10, 10, 10, 10, 60, 10, 10, 5, 10, 60 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell casting times by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the casting time in segments - 1 round = 10 segments, 1 turn = 60; four spells take a turn (animal companion, detect harmony, omen, weapon bless), four take five segments (beneficence, calm, cure light wounds, snake charm), the rest a round",
    }, {
      "name" = "dhtL1Save",
      "values" = { 1, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell saving throws by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the saving throw codes: 0 none, 1 neg., 2 special - animal companion and calm are neg., deflection and know history are special, the other sixteen none",
    }, {
      "name" = "dhtL1Reversible",
      "values" = { 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell reversible markers by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the cell is 1 where the printed header reads Reversible - bless, cure light wounds, deflection, detect evil, purify food & drink; the five matching the R658 T62 reversible column",
    }, {
      "name" = "dhtL1Sohei",
      "values" = { 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
      "default" = 0,
      "comment" = "the shukenja 1st level spell sohei-usable markers by ordinal (print pp. 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7 deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16 purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless - the cell is 1 where the printed asterisk marks the spell usable by sohei - animal companion, bless, deflection, resist, weapon bless; the five matching the R658 T62 sohei column",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhtL1SpellCount']() != 20  or m['dhtL1SoheiCount']() != 5  or m['dhtL1ReversibleCount']() != 5  or m['dhtL1DivinationCount']() != 10  or m['dhtL1VSMCount']() != 12  or m['dhtL1VerbalOnlyCount']() != 2  or m['dhtL1TurnCasts']() != 4  or m['dhtL1RoundCasts']() != 12  or m['dhtL1SegmentCasts']() != 4  or m['dhtL1NegSaves']() != 2  or m['dhtL1SpecialSaves']() != 2",
      "note" = "",
    }, {
      "expr" = "m['dhtL1SpellCount']() != 20  or m['dhtL1SoheiCount']() != 5  or m['dhtL1ReversibleCount']() != 5  or m['dhtL1DivinationCount']() != 10",
      "note" = "the count pins - twenty first level spells, five sohei-usable, five reversible, ten divination",
    }, {
      "expr" = "m['dhtL1School'](0) != 1  or m['dhtL1School'](1) != 2  or m['dhtL1School'](2) != 3  or m['dhtL1School'](3) != 4  or m['dhtL1School'](4) != 1  or m['dhtL1School'](5) != 5  or m['dhtL1School'](6) != 3  or m['dhtL1School'](18) != 2  or m['dhtL1School'](19) != 4",
      "note" = "the school pins - animal companion, calm and snake charm enchantment/charm; augury through trance the divination run; beneficence and deflection evocation; bless and weapon bless conjuration/summoning; cure light wounds necromantic; purify food & drink and resist alteration",
    }, {
      "expr" = "m['dhtL1Components'](0) != 7  or m['dhtL1Components'](1) != 7  or m['dhtL1Components'](2) != 1  or m['dhtL1Components'](3) != 3  or m['dhtL1Components'](9) != 7  or m['dhtL1Components'](13) != 7  or m['dhtL1Components'](14) != 1  or m['dhtL1Components'](15) != 3  or m['dhtL1Components'](17) != 3  or m['dhtL1Components'](19) != 7",
      "note" = "the component pins - the twelve all-component spells (animal companion, augury, calm, the five detects, divining rod, know history, resist, weapon bless); beneficence and omen verbal only; bless, cure light wounds, deflection, purify, snake charm and trance verbal and somatic",
    }, {
      "expr" = "m['dhtL1CastTime'](0) != 60  or m['dhtL1CastTime'](2) != 5  or m['dhtL1CastTime'](4) != 5  or m['dhtL1CastTime'](9) != 60  or m['dhtL1CastTime'](14) != 60  or m['dhtL1CastTime'](17) != 5  or m['dhtL1CastTime'](19) != 60  or m['dhtL1CastTime'](1) != 10  or m['dhtL1CastTime'](18) != 10",
      "note" = "the casting time pins - the one-turn casts (animal companion, detect harmony, omen, weapon bless); the five-segment casts (beneficence, calm, cure light wounds, snake charm); the rest one round",
    }, {
      "expr" = "m['dhtL1Save'](0) != 1  or m['dhtL1Save'](4) != 1  or m['dhtL1Save'](6) != 2  or m['dhtL1Save'](13) != 2  or m['dhtL1Save'](1) != 0  or m['dhtL1Save'](15) != 0  or m['dhtL1Save'](19) != 0",
      "note" = "the saving throw pins - animal companion and calm neg., deflection and know history special, the sixteen others none",
    }, {
      "expr" = "m['dhtL1Reversible'](3) != 1  or m['dhtL1Reversible'](5) != 1  or m['dhtL1Reversible'](6) != 1  or m['dhtL1Reversible'](8) != 1  or m['dhtL1Reversible'](15) != 1  or m['dhtL1Reversible'](1) != 0  or m['dhtL1Reversible'](4) != 0  or m['dhtL1Reversible'](19) != 0",
      "note" = "the reversible pins - bless, cure light wounds, deflection, detect evil and purify food & drink marked; augury, calm and weapon bless not - the five matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhtL1Sohei'](0) != 1  or m['dhtL1Sohei'](3) != 1  or m['dhtL1Sohei'](6) != 1  or m['dhtL1Sohei'](16) != 1  or m['dhtL1Sohei'](19) != 1  or m['dhtL1Sohei'](1) != 0  or m['dhtL1Sohei'](5) != 0",
      "note" = "the sohei pins - animal companion, bless, deflection, resist and weapon bless marked; augury and cure light wounds not - the five matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhtL1VSMCount']() != 12  or m['dhtL1RoundCasts']() != 12  or m['dhtL1VerbalOnlyCount']() != 2  or m['dhtL1SegmentCasts']() != 4  or m['dhtL1TurnCasts']() != 4  or m['dhtL1NegSaves']() != 2  or m['dhtL1SpecialSaves']() != 2",
      "note" = "the grid-sum pins - twelve VSM components, twelve one-round casts, sixteen none saves",
    } },
  "audit" = {
      "label" = "R659 OA first level spells audit",
      "comment" = "OA round forty-six (capture pp. 112-119): the first level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
