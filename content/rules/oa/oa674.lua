-- oa674: promoted from rules/oawjl5spells.h (the WU JEN FIFTH LEVEL SPELLS, printed capture pp. 189-196 - the OA wu jen);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 674,
  "prefix" = "oa674",
  "banner" = {
      "title" = "WU JEN FIFTH LEVEL SPELLS, printed capture pp. 189-196 - the OA wu jen",
      "provenance" = "fifth level spells round census 596 -> 597.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print pp. 189-196; compressed pp. 87-91); all 24 stat blocks cross-checked spell by spell between the passes, zero contested stat reads - the variances typographic or prose-only (the fire breath save printed 1/z for the half, the wall of stone range garbled X12, the servant horde count 2d6 + 1 in the print against 2d6 - 1 in the compressed - a prose divergence outside the grid). The level is alteration-heavy yet again: 10 of the 24 spells, evocation eight, conjuration two, and FOUR lone-school spells - animate dead the lone necromantic, aiming at the target the lone invocation, shadow door the lone illusion, dismissal the lone abjuration with its odd triple-line print Abjuration Reversible (Conjuration/Summoning) pinned primary 7; no divination or enchantment/charm spell this level. The component census: 20 VSM, and TWO somatic-only spells (aiming at the target, shadow door) - the first somatic-only spells of the wu jen levels; animal growth and telekinesis the verbal and somatic pair; no verbal-only or V,M spell this level. The casting times: nine five-segment (the most common cast), six one-round, three three-segment, conjure elemental and major creation one-turn, animate dead the five-ROUND cast pinned 50 segments (the longest of the level), servant horde the lone single segment, shadow door two, sword of deception four. Three negation saves, cone of cold and fire breath the two half saves, no special save this level. Four spells read Reversible (animal growth, dismissal, water to poison, wood rot). The sixth column cross-checks the R669 element grid: the 13 tagged cells - the richest element column yet - matching the landed dieWJT66L5Element pins exactly, with water to poison carrying the Nature/Water dual code 9. The stat grid pins as a table: 24 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and element markers. The spell names ride the column comments, the prose descriptions close in their own rounds. The table tag WJL5Data identifier-safe per the R639 lesson  the gap census after this round: 127 closed, 108 open - the wu jen Fifth Level Spells box flips (census 596 -> 597); NEXT - R675: the wu jen Sixth Level Spells (capture pp. 196-202, the 12 stat blocks), prefix dik (verify free - only comment-word matches expected, the R669 die precedent), audit \"R675 OA wu jen sixth level spells audit\"",
    },
  "consts" = { {
      "name" = "dijWJL5SpellCount",
      "value" = 24,
      "comment" = "the 24 fifth level wu jen spells (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5AlterationCount",
      "value" = 10,
      "comment" = "the 10 alteration fifth level wu jen spells - animal growth, ironwood, major creation, mass, metal skin, passwall, spirit self, stone shape, telekinesis, water to poison; the most common school (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5EvocationCount",
      "value" = 8,
      "comment" = "the eight evocation fifth level wu jen spells - cone of cold, creeping darkness, fire breath, sword of deception, wall of force, wall of iron, wall of stone, wood rot (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5ReversibleCount",
      "value" = 4,
      "comment" = "the four reversible fifth level wu jen spells - animal growth (animal diminution), dismissal (beckon), water to poison (poison to water), wood rot (prevent rot) (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5VSMCount",
      "value" = 20,
      "comment" = "the 20 fifth level wu jen spells taking all three components - the bitmask reads 7 (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5SomaticOnlyCount",
      "value" = 2,
      "comment" = "the two fifth level wu jen spells taking the somatic component only - aiming at the target, shadow door; the bitmask reads 2, the first somatic-only spells of the wu jen levels (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5VSCount",
      "value" = 2,
      "comment" = "the two fifth level wu jen spells taking verbal and somatic - animal growth, telekinesis; the bitmask reads 3 (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5FiveSegmentCasts",
      "value" = 9,
      "comment" = "the nine fifth level wu jen spells with a five-segment casting time - animal growth, cone of cold, creeping darkness, metal skin, passwall, telekinesis, wall of force, wall of iron, wall of stone; the most common cast of the level (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5RoundCasts",
      "value" = 6,
      "comment" = "the six fifth level wu jen spells with a one-round casting time - dismissal, fire breath, ironwood, mass, stone shape, water to poison (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5ThreeSegmentCasts",
      "value" = 3,
      "comment" = "the three fifth level wu jen spells with a three-segment casting time - aiming at the target, spirit self, wood rot (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5TurnCasts",
      "value" = 2,
      "comment" = "the two fifth level wu jen spells with a one-turn casting time - conjure elemental, major creation (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5FiveRoundCast",
      "value" = 1,
      "comment" = "the one fifth level wu jen spell with a five-round casting time - animate dead, pinned 50 segments (1 round = 10), the longest cast of the level (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5OneSegmentCasts",
      "value" = 1,
      "comment" = "the one fifth level wu jen spell with a one-segment casting time - servant horde (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5TwoSegmentCasts",
      "value" = 1,
      "comment" = "the one fifth level wu jen spell with a two-segment casting time - shadow door (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5FourSegmentCasts",
      "value" = 1,
      "comment" = "the one fifth level wu jen spell with a four-segment casting time - sword of deception (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5NegSaves",
      "value" = 3,
      "comment" = "the three fifth level wu jen spells with a negation saving throw - dismissal, mass, wood rot (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5HalfSaves",
      "value" = 2,
      "comment" = "the two fifth level wu jen spells with the half saving throw code - cone of cold, fire breath, the damage halved on a successful save (print pp. 189-196; compressed pp. 87-91)",
    }, {
      "name" = "dijWJL5ElementCount",
      "value" = 13,
      "comment" = "the 13 element-tagged fifth level wu jen spells - six Earth (mass, metal skin, passwall, stone shape, wall of iron, wall of stone), conjure elemental All, creeping darkness Air, cone of cold Water, fire breath Fire, ironwood and wood rot Nature, water to poison the Nature/Water dual 9 - matching the R669 dieWJT66L5Element grid exactly (print pp. 189-196; compressed pp. 87-91)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dijWJL5School",
      "values" = { 8, 6, 5, 3, 4, 3, 7, 3, 6, 6, 6, 6, 6, 4, 9, 6, 6, 3, 6, 3, 3, 3, 6, 3 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell schools by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the school codes: 3 evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - alteration the most common school at 10 spells (animal growth, ironwood, major creation, mass, metal skin, passwall, spirit self, stone shape, telekinesis, water to poison); evocation eight; conjuration two (conjure elemental, servant horde); animate dead the lone necromantic, aiming at the target the lone invocation, shadow door the lone illusion, dismissal the lone abjuration - its odd triple-line print Abjuration Reversible (Conjuration/Summoning) pinned primary abjuration 7; no divination or enchantment/charm spell this level",
    }, {
      "name" = "dijWJL5Components",
      "values" = { 2, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 7, 7, 7, 3, 7, 7, 7, 7, 7 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell components by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the component codes a bitmask: verbal 1, somatic 2, material 4 - 20 spells take all three (7), TWO somatic-only spells (2): aiming at the target and shadow door, the first somatic-only spells of the wu jen levels; animal growth and telekinesis the verbal and somatic pair (3); no verbal-only or V,M spell this level",
    }, {
      "name" = "dijWJL5CastTime",
      "values" = { 3, 5, 50, 5, 60, 5, 10, 10, 10, 60, 10, 5, 5, 1, 2, 3, 10, 4, 5, 5, 5, 5, 10, 3 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell casting times by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the casting time in segments - 1 round = 10 segments, 1 turn = 60 segments: nine spells five segments (the most common cast of the level), six a full round (dismissal, fire breath, ironwood, mass, stone shape, water to poison), three three segments, conjure elemental and major creation a full turn, animate dead the five-ROUND cast pinned 50 segments (the longest of the level), servant horde the lone single segment, shadow door two, sword of deception four",
    }, {
      "name" = "dijWJL5Save",
      "values" = { 0, 0, 0, 3, 0, 0, 1, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell saving throws by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - dismissal, mass and wood rot neg.; cone of cold and fire breath the half code (the damage halved on a successful save); no special save this level; the other 19 none",
    }, {
      "name" = "dijWJL5Reversible",
      "values" = { 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell reversible markers by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the cell is 1 where the printed header reads Reversible - animal growth (animal diminution), dismissal (beckon), water to poison (poison to water), wood rot (prevent rot); the four",
    }, {
      "name" = "dijWJL5Element",
      "values" = { 0, 0, 0, 4, 7, 1, 0, 3, 5, 0, 2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 9, 5 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell element marks by ordinal (print pp. 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 9 the Nature/Water dual (water to poison) - the 13 tagged spells (cone of cold Water, conjure elemental All, creeping darkness Air, fire breath Fire, ironwood and wood rot Nature, mass, metal skin, passwall, stone shape, wall of iron and wall of stone Earth, water to poison the dual 9) matching the R669 dieWJT66L5Element pins exactly - the cross-check column, the richest yet",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dijWJL5SpellCount']() != 24  or m['dijWJL5AlterationCount']() != 10  or m['dijWJL5EvocationCount']() != 8  or m['dijWJL5ReversibleCount']() != 4  or m['dijWJL5VSMCount']() != 20  or m['dijWJL5SomaticOnlyCount']() != 2  or m['dijWJL5VSCount']() != 2  or m['dijWJL5FiveSegmentCasts']() != 9  or m['dijWJL5RoundCasts']() != 6  or m['dijWJL5ThreeSegmentCasts']() != 3  or m['dijWJL5TurnCasts']() != 2  or m['dijWJL5FiveRoundCast']() != 1  or m['dijWJL5OneSegmentCasts']() != 1  or m['dijWJL5TwoSegmentCasts']() != 1  or m['dijWJL5FourSegmentCasts']() != 1  or m['dijWJL5NegSaves']() != 3  or m['dijWJL5HalfSaves']() != 2  or m['dijWJL5ElementCount']() != 13",
      "note" = "",
    }, {
      "expr" = "m['dijWJL5SpellCount']() != 24  or m['dijWJL5AlterationCount']() != 10  or m['dijWJL5EvocationCount']() != 8  or m['dijWJL5ReversibleCount']() != 4  or m['dijWJL5ElementCount']() != 13",
      "note" = "the count pins - 24 spells, 10 alteration, eight evocation, four reversible, 13 element-tagged",
    }, {
      "expr" = "m['dijWJL5VSMCount']() != 20  or m['dijWJL5SomaticOnlyCount']() != 2  or m['dijWJL5VSCount']() != 2",
      "note" = "the component pins - 20 VSM, the two somatic-only spells, animal growth and telekinesis the VS pair",
    }, {
      "expr" = "m['dijWJL5FiveSegmentCasts']() != 9  or m['dijWJL5RoundCasts']() != 6  or m['dijWJL5FiveRoundCast']() != 1  or m['dijWJL5TurnCasts']() != 2  or m['dijWJL5ThreeSegmentCasts']() != 3  or m['dijWJL5OneSegmentCasts']() != 1  or m['dijWJL5TwoSegmentCasts']() != 1  or m['dijWJL5FourSegmentCasts']() != 1",
      "note" = "the casting time pins - nine five-segment, six round casts, animate dead the five-round 50, two turn casts, three three-segment, servant horde the lone segment",
    }, {
      "expr" = "m['dijWJL5NegSaves']() != 3  or m['dijWJL5HalfSaves']() != 2",
      "note" = "the saving throw pins - three neg., cone of cold and fire breath the two half, no special save this level",
    }, {
      "expr" = "m['dijWJL5School'](2) != 5  or m['dijWJL5School'](0) != 8  or m['dijWJL5School'](14) != 9  or m['dijWJL5School'](6) != 7  or m['dijWJL5School'](4) != 4  or m['dijWJL5School'](13) != 4  or m['dijWJL5School'](3) != 3  or m['dijWJL5School'](5) != 3  or m['dijWJL5School'](7) != 3  or m['dijWJL5School'](17) != 3  or m['dijWJL5School'](19) != 3  or m['dijWJL5School'](20) != 3  or m['dijWJL5School'](21) != 3  or m['dijWJL5School'](23) != 3  or m['dijWJL5School'](8) != 6  or m['dijWJL5School'](9) != 6  or m['dijWJL5School'](10) != 6  or m['dijWJL5School'](11) != 6  or m['dijWJL5School'](12) != 6  or m['dijWJL5School'](15) != 6  or m['dijWJL5School'](16) != 6  or m['dijWJL5School'](18) != 6  or m['dijWJL5School'](22) != 6",
      "note" = "the school pins - animate dead the lone necromantic; aiming at the target the lone invocation; shadow door the lone illusion; dismissal the lone abjuration with its triple-line print pinned primary 7; conjure elemental and servant horde conjuration; sword of deception, wall of force and creeping darkness among the eight evocation; ironwood and telekinesis among the 10 alteration",
    }, {
      "expr" = "m['dijWJL5Components'](0) != 2  or m['dijWJL5Components'](14) != 2  or m['dijWJL5Components'](1) != 3  or m['dijWJL5Components'](18) != 3  or m['dijWJL5Components'](2) != 7  or m['dijWJL5Components'](3) != 7  or m['dijWJL5Components'](4) != 7  or m['dijWJL5Components'](13) != 7  or m['dijWJL5Components'](22) != 7  or m['dijWJL5Components'](23) != 7",
      "note" = "the component cell pins - the two somatic-only spells, the VS pair, and the VSM spots",
    }, {
      "expr" = "m['dijWJL5CastTime'](2) != 50  or m['dijWJL5CastTime'](4) != 60  or m['dijWJL5CastTime'](9) != 60  or m['dijWJL5CastTime'](13) != 1  or m['dijWJL5CastTime'](14) != 2  or m['dijWJL5CastTime'](17) != 4  or m['dijWJL5CastTime'](0) != 3  or m['dijWJL5CastTime'](15) != 3  or m['dijWJL5CastTime'](23) != 3  or m['dijWJL5CastTime'](1) != 5  or m['dijWJL5CastTime'](11) != 5  or m['dijWJL5CastTime'](19) != 5",
      "note" = "the casting time cell pins - animate dead the 50, the turn casts, servant horde the lone segment, shadow door the two, sword of deception the four, the three-segment spots",
    }, {
      "expr" = "m['dijWJL5Save'](6) != 1  or m['dijWJL5Save'](10) != 1  or m['dijWJL5Save'](23) != 1  or m['dijWJL5Save'](3) != 3  or m['dijWJL5Save'](7) != 3  or m['dijWJL5Save'](19) != 0  or m['dijWJL5Save'](0) != 0",
      "note" = "the saving throw cell pins - the three negation saves, the two half saves, wall of force none",
    }, {
      "expr" = "m['dijWJL5Reversible'](1) != 1  or m['dijWJL5Reversible'](6) != 1  or m['dijWJL5Reversible'](22) != 1  or m['dijWJL5Reversible'](23) != 1  or m['dijWJL5Reversible'](8) != 0  or m['dijWJL5Reversible'](9) != 0  or m['dijWJL5Reversible'](18) != 0",
      "note" = "the reversible pins - animal growth, dismissal, water to poison and wood rot marked; ironwood, major creation and telekinesis not",
    }, {
      "expr" = "m['dijWJL5Element'](3) != 4  or m['dijWJL5Element'](4) != 7  or m['dijWJL5Element'](5) != 1  or m['dijWJL5Element'](7) != 3  or m['dijWJL5Element'](8) != 5  or m['dijWJL5Element'](23) != 5  or m['dijWJL5Element'](10) != 2  or m['dijWJL5Element'](11) != 2  or m['dijWJL5Element'](12) != 2  or m['dijWJL5Element'](16) != 2  or m['dijWJL5Element'](20) != 2  or m['dijWJL5Element'](21) != 2  or m['dijWJL5Element'](22) != 9  or m['dijWJL5Element'](19) != 0  or m['dijWJL5Element'](0) != 0",
      "note" = "the element cross-check pins - the 13 tagged cells matching the R669 dieWJT66L5Element grid: cone of cold Water, conjure elemental All, creeping darkness Air, fire breath Fire, ironwood and wood rot Nature, the six Earth marks, water to poison the Nature/Water dual 9; wall of force untagged",
    } },
  "audit" = {
      "label" = "R674 OA wu jen fifth level spells audit",
      "comment" = "OA round sixty-one (capture pp. 189-196): the wu jen fifth level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and element markers, cross-checked spell by spell between the passes",
    },
}
