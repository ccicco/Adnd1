-- oa663: promoted from rules/oa/oal5spells.h (the FIFTH LEVEL SPELLS, printed capture pp. 140-143 - the OA fifth level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 663,
  "prefix" = "oa663",
  "banner" = {
      "title" = "FIFTH LEVEL SPELLS, printed capture pp. 140-143 - the OA fifth level spells",
      "provenance" = "round census 585 -> 586.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 12 fifth level spell stat blocks cross-checked spell by spell between the passes (print pp. 140-143; compressed pp. 68-70); all 12 schools, component sets, casting times and saving throws agree, zero contested stat reads. The level lists twelve spells (the R658 T62 grid settled the size); advice takes the verbal component only; air walk casts in a single segment; three spells take the eight-segment cast (cure critical wounds, dispel evil, true seeing); raise dead and remember carry the special saves. Alteration and divination tie as the most common school at three spells each, with no evocation or conjuration spell this level. The reversible flags agree between the passes; the sohei-usable marks ride the R658 T62 grid, settled five rounds before. The stat grid pins as a table: 12 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and sohei markers. The spell names ride the column comments, the prose descriptions close in their own rounds. The table tag L5Data identifier-safe per the R639 lesson  the gap census after this round: 116 closed, 119 open - the Fifth Level Spells box flips (census 585 -> 586); NEXT - R664: the Sixth Level Spells (capture pp. 143-147), prefix dhy (verify free), audit \"R664 OA sixth level spells audit\", include after rules/oa/oal5spells.h",
    },
  "consts" = { {
      "name" = "dhxL5SpellCount",
      "value" = 12,
      "comment" = "the 12 fifth level shukenja spells (print pp. 140-143; compressed pp. 68-70)",
    }, {
      "name" = "dhxL5SoheiCount",
      "value" = 4,
      "comment" = "the four fifth level spells usable by sohei - dispel evil, mental strength, strength, true seeing",
    }, {
      "name" = "dhxL5ReversibleCount",
      "value" = 6,
      "comment" = "the six reversible fifth level spells - cure critical wounds, dispel evil, mental strength, raise dead, remember, true seeing",
    }, {
      "name" = "dhxL5AlterationCount",
      "value" = 3,
      "comment" = "the three alteration fifth level spells - air walk, mental strength, strength",
    }, {
      "name" = "dhxL5DivinationCount",
      "value" = 3,
      "comment" = "the three divination fifth level spells - commune w/ greater spirit, remember, true seeing; tied with alteration as the most common school",
    }, {
      "name" = "dhxL5EnchCharmCount",
      "value" = 2,
      "comment" = "the two enchantment/charm fifth level spells - advice, possess",
    }, {
      "name" = "dhxL5AbjurationCount",
      "value" = 2,
      "comment" = "the two abjuration fifth level spells - atonement, dispel evil",
    }, {
      "name" = "dhxL5NecromanticCount",
      "value" = 2,
      "comment" = "the two necromantic fifth level spells - cure critical wounds, raise dead",
    }, {
      "name" = "dhxL5VSMCount",
      "value" = 9,
      "comment" = "the nine fifth level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhxL5VSCount",
      "value" = 2,
      "comment" = "the two fifth level spells taking verbal and somatic - cure critical wounds, raise dead; the bitmask reads 3",
    }, {
      "name" = "dhxL5VerbalOnlyCount",
      "value" = 1,
      "comment" = "the one fifth level spell taking the verbal component only - advice",
    }, {
      "name" = "dhxL5TurnCasts",
      "value" = 5,
      "comment" = "the five fifth level spells with a one-turn casting time - atonement, commune w/ greater spirit, possess, remember, strength",
    }, {
      "name" = "dhxL5RoundCasts",
      "value" = 1,
      "comment" = "the one fifth level spell with a one-round casting time - raise dead",
    }, {
      "name" = "dhxL5EightSegmentCasts",
      "value" = 3,
      "comment" = "the three fifth level spells with an eight-segment casting time - cure critical wounds, dispel evil, true seeing",
    }, {
      "name" = "dhxL5FiveSegmentCasts",
      "value" = 2,
      "comment" = "the two fifth level spells with a five-segment casting time - advice, mental strength",
    }, {
      "name" = "dhxL5OneSegmentCasts",
      "value" = 1,
      "comment" = "the one fifth level spell with a one-segment casting time - air walk",
    }, {
      "name" = "dhxL5NegSaves",
      "value" = 3,
      "comment" = "the three fifth level spells with a negation saving throw - advice, dispel evil, possess",
    }, {
      "name" = "dhxL5SpecialSaves",
      "value" = 2,
      "comment" = "the two fifth level spells with a special saving throw - raise dead, remember",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhxL5School",
      "values" = { 1, 6, 7, 2, 5, 7, 6, 1, 5, 2, 6, 2 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell schools by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the school codes: 1 enchantment/charm, 2 divination, 5 necromantic, 6 alteration, 7 abjuration - alteration and divination the most common at three spells each; no evocation or conjuration spell this level",
    }, {
      "name" = "dhxL5Components",
      "values" = { 1, 7, 7, 7, 3, 7, 7, 7, 3, 7, 7, 7 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell components by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the component codes a bitmask: verbal 1, somatic 2, material 4 - nine spells take all three (7), cure critical wounds and raise dead take the verbal and somatic (3), and advice takes the verbal only (1)",
    }, {
      "name" = "dhxL5CastTime",
      "values" = { 5, 1, 60, 60, 8, 8, 5, 60, 10, 60, 60, 8 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell casting times by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the casting time in segments - 1 round = 10 segments, 1 turn = 60: five spells take a turn (atonement, commune w/ greater spirit, possess, remember, strength), raise dead a round, three take eight segments (cure critical wounds, dispel evil, true seeing), advice and mental strength five, and air walk the single segment",
    }, {
      "name" = "dhxL5Save",
      "values" = { 1, 0, 0, 0, 0, 1, 0, 1, 2, 2, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell saving throws by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - advice, dispel evil and possess are neg., raise dead and remember are special, the other seven none",
    }, {
      "name" = "dhxL5Reversible",
      "values" = { 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell reversible markers by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed header reads Reversible - cure critical wounds, dispel evil, mental strength, raise dead, remember, true seeing; the six matching the R658 T62 reversible column",
    }, {
      "name" = "dhxL5Sohei",
      "values" = { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1 },
      "default" = 0,
      "comment" = "the shukenja 5th level spell sohei-usable markers by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed asterisk marks the spell usable by sohei - dispel evil, mental strength, strength, true seeing; the four matching the R658 T62 sohei column",
    } },
  "tables" = { {
      "name" = "dhxL5Grid",
      "tag" = "L5Data",
      "count" = "dhxL5SpellCount",
      "col_default" = 0,
      "cols" = { "dhxL5School", "dhxL5Components", "dhxL5CastTime", "dhxL5Save", "dhxL5Reversible", "dhxL5Sohei" },
      "col_comments" = { "the shukenja 5th level spell schools by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the school codes: 1 enchantment/charm, 2 divination, 5 necromantic, 6 alteration, 7 abjuration - alteration and divination the most common at three spells each; no evocation or conjuration spell this level", "the shukenja 5th level spell components by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the component codes a bitmask: verbal 1, somatic 2, material 4 - nine spells take all three (7), cure critical wounds and raise dead take the verbal and somatic (3), and advice takes the verbal only (1)", "the shukenja 5th level spell casting times by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the casting time in segments - 1 round = 10 segments, 1 turn = 60: five spells take a turn (atonement, commune w/ greater spirit, possess, remember, strength), raise dead a round, three take eight segments (cure critical wounds, dispel evil, true seeing), advice and mental strength five, and air walk the single segment", "the shukenja 5th level spell saving throws by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - advice, dispel evil and possess are neg., raise dead and remember are special, the other seven none", "the shukenja 5th level spell reversible markers by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed header reads Reversible - cure critical wounds, dispel evil, mental strength, raise dead, remember, true seeing; the six matching the R658 T62 reversible column", "the shukenja 5th level spell sohei-usable markers by ordinal (print pp. 140-143; compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed asterisk marks the spell usable by sohei - dispel evil, mental strength, strength, true seeing; the four matching the R658 T62 sohei column" },
      "data" = { { 1, 1, 5, 1, 0, 0 }, { 6, 7, 1, 0, 0, 0 }, { 7, 7, 60, 0, 0, 0 }, { 2, 7, 60, 0, 0, 0 }, { 5, 3, 8, 0, 1, 0 }, { 7, 7, 8, 1, 1, 1 }, { 6, 7, 5, 0, 1, 1 }, { 1, 7, 60, 1, 0, 0 }, { 5, 3, 10, 2, 1, 0 }, { 2, 7, 60, 2, 1, 0 }, { 6, 7, 60, 0, 0, 1 }, { 2, 7, 8, 0, 1, 1 } },
      "comment" = "the Table 62 fifth level spell stat grid (print pp. 140-143; compressed pp. 68-70)",
      "audit_comment" = "the fifth level stat grid: the school, component, casting time and saving throw codes with the reversible and sohei markers by spell ordinal",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhxL5SpellCount']() != 12  or m['dhxL5SoheiCount']() != 4  or m['dhxL5ReversibleCount']() != 6  or m['dhxL5AlterationCount']() != 3  or m['dhxL5DivinationCount']() != 3  or m['dhxL5EnchCharmCount']() != 2  or m['dhxL5AbjurationCount']() != 2  or m['dhxL5NecromanticCount']() != 2  or m['dhxL5VSMCount']() != 9  or m['dhxL5VSCount']() != 2  or m['dhxL5VerbalOnlyCount']() != 1  or m['dhxL5TurnCasts']() != 5  or m['dhxL5RoundCasts']() != 1  or m['dhxL5EightSegmentCasts']() != 3  or m['dhxL5FiveSegmentCasts']() != 2  or m['dhxL5OneSegmentCasts']() != 1  or m['dhxL5NegSaves']() != 3  or m['dhxL5SpecialSaves']() != 2",
      "note" = "",
    }, {
      "expr" = "m['dhxL5SpellCount']() != 12  or m['dhxL5SoheiCount']() != 4  or m['dhxL5ReversibleCount']() != 6  or m['dhxL5AlterationCount']() != 3  or m['dhxL5DivinationCount']() != 3  or m['dhxL5EnchCharmCount']() != 2  or m['dhxL5AbjurationCount']() != 2  or m['dhxL5NecromanticCount']() != 2",
      "note" = "the count pins - twelve fifth level spells, four sohei-usable, six reversible, the alteration and divination tie at three",
    }, {
      "expr" = "m['dhxL5School'](0) != 1  or m['dhxL5School'](7) != 1  or m['dhxL5School'](1) != 6  or m['dhxL5School'](6) != 6  or m['dhxL5School'](10) != 6  or m['dhxL5School'](2) != 7  or m['dhxL5School'](5) != 7  or m['dhxL5School'](3) != 2  or m['dhxL5School'](9) != 2  or m['dhxL5School'](11) != 2  or m['dhxL5School'](4) != 5  or m['dhxL5School'](8) != 5",
      "note" = "the school pins - advice and possess enchantment/charm; air walk, mental strength and strength alteration; atonement and dispel evil abjuration; commune w/ greater spirit, remember and true seeing divination; cure critical wounds and raise dead necromantic",
    }, {
      "expr" = "m['dhxL5Components'](0) != 1  or m['dhxL5Components'](4) != 3  or m['dhxL5Components'](8) != 3  or m['dhxL5Components'](1) != 7  or m['dhxL5Components'](2) != 7  or m['dhxL5Components'](11) != 7  or m['dhxL5Components'](6) != 7  or m['dhxL5Components'](10) != 7",
      "note" = "the component pins - advice the verbal only (1); cure critical wounds and raise dead the verbal and somatic (3); air walk, atonement and true seeing the all-component (7)",
    }, {
      "expr" = "m['dhxL5CastTime'](2) != 60  or m['dhxL5CastTime'](3) != 60  or m['dhxL5CastTime'](7) != 60  or m['dhxL5CastTime'](9) != 60  or m['dhxL5CastTime'](10) != 60  or m['dhxL5CastTime'](8) != 10  or m['dhxL5CastTime'](4) != 8  or m['dhxL5CastTime'](5) != 8  or m['dhxL5CastTime'](11) != 8  or m['dhxL5CastTime'](0) != 5  or m['dhxL5CastTime'](6) != 5  or m['dhxL5CastTime'](1) != 1",
      "note" = "the casting time pins - the five one-turn casts (atonement, commune w/ greater spirit, possess, remember, strength); raise dead the round; the eight-segment casts (cure critical wounds, dispel evil, true seeing); advice and mental strength five; air walk the single segment",
    }, {
      "expr" = "m['dhxL5Save'](0) != 1  or m['dhxL5Save'](5) != 1  or m['dhxL5Save'](7) != 1  or m['dhxL5Save'](8) != 2  or m['dhxL5Save'](9) != 2  or m['dhxL5Save'](1) != 0  or m['dhxL5Save'](2) != 0  or m['dhxL5Save'](11) != 0",
      "note" = "the saving throw pins - advice, dispel evil and possess neg.; raise dead and remember special; the seven others none",
    }, {
      "expr" = "m['dhxL5Reversible'](4) != 1  or m['dhxL5Reversible'](5) != 1  or m['dhxL5Reversible'](6) != 1  or m['dhxL5Reversible'](8) != 1  or m['dhxL5Reversible'](9) != 1  or m['dhxL5Reversible'](11) != 1  or m['dhxL5Reversible'](0) != 0  or m['dhxL5Reversible'](1) != 0  or m['dhxL5Reversible'](10) != 0",
      "note" = "the reversible pins - cure critical wounds, dispel evil, mental strength, raise dead, remember and true seeing marked; advice, air walk and strength not - the six matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhxL5Sohei'](5) != 1  or m['dhxL5Sohei'](6) != 1  or m['dhxL5Sohei'](10) != 1  or m['dhxL5Sohei'](11) != 1  or m['dhxL5Sohei'](0) != 0  or m['dhxL5Sohei'](2) != 0  or m['dhxL5Sohei'](8) != 0",
      "note" = "the sohei pins - dispel evil, mental strength, strength and true seeing marked; advice, atonement and raise dead not - the four matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhxL5VSMCount']() != 9  or m['dhxL5VSCount']() != 2  or m['dhxL5VerbalOnlyCount']() != 1  or m['dhxL5TurnCasts']() != 5  or m['dhxL5RoundCasts']() != 1  or m['dhxL5EightSegmentCasts']() != 3  or m['dhxL5FiveSegmentCasts']() != 2  or m['dhxL5OneSegmentCasts']() != 1  or m['dhxL5NegSaves']() != 3  or m['dhxL5SpecialSaves']() != 2",
      "note" = "the grid-sum pins - nine VSM, two VS and the advice verbal only; five one-turn and three eight-segment casts; three neg. and two special saves",
    } },
  "audit" = {
      "label" = "R663 OA fifth level spells audit",
      "comment" = "OA round fifty (capture pp. 140-143): the fifth level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
