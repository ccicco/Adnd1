-- oa664: promoted from rules/oa/oal6spells.h (the SIXTH LEVEL SPELLS, printed capture pp. 143-147 - the OA sixth level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 664,
  "prefix" = "oa664",
  "banner" = {
      "title" = "SIXTH LEVEL SPELLS, printed capture pp. 143-147 - the OA sixth level spells",
      "provenance" = "round census 586 -> 587.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 12 sixth level spell stat blocks cross-checked spell by spell between the passes (print pp. 143-147; compressed pp. 69-72); all 12 schools, component sets, casting times and saving throws agree, zero contested stat reads. Force shapechange's components read V, S, M in the compressed, the print line cutting at its page boundary - the R660 detect charm pattern. The level runs the widest cast spread in the chapter: three single-segment casts (force shapechange, immunity to weapons, smite) up through longevity's one-day cast, pinned as 8640 segments (60 per turn, 144 turns per day, the turn=60 convention) - and instruct takes three turns, find the path three rounds. Two spells take the half save (force shapechange, smite), longevity the special. Alteration is the most common school at five spells, with the other seven appearing schools exactly once each (no invocation this level). The reversible flags agree between the passes; the sohei-usable marks ride the R658 T62 grid. The stat grid pins as a table: 12 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, 3 turns = 180, 1 day = 8640), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and sohei markers. The spell names ride the column comments, the prose descriptions close in their own rounds. The table tag L6Data identifier-safe per the R639 lesson  the gap census after this round: 117 closed, 118 open - the Sixth Level Spells box flips (census 586 -> 587); NEXT - R665: the Seventh Level Spells (capture pp. 147-152), prefix dhz (verify free), audit \"R665 OA seventh level spells audit\", include after rules/oa/oal6spells.h",
    },
  "consts" = { {
      "name" = "dhyL6SpellCount",
      "value" = 12,
      "comment" = "the 12 sixth level shukenja spells (print pp. 143-147; compressed pp. 69-72)",
    }, {
      "name" = "dhyL6SoheiCount",
      "value" = 4,
      "comment" = "the four sixth level spells usable by sohei - find the path, immunity to weapons, smite, speak w/ monsters",
    }, {
      "name" = "dhyL6ReversibleCount",
      "value" = 4,
      "comment" = "the four reversible sixth level spells - find the path, heal, immunity to weapons, quickgrowth",
    }, {
      "name" = "dhyL6AlterationCount",
      "value" = 5,
      "comment" = "the five alteration sixth level spells - the most common school of the level: immunity to weapons, longevity, plane shift, quickgrowth, speak w/ monsters",
    }, {
      "name" = "dhyL6VSMCount",
      "value" = 8,
      "comment" = "the eight sixth level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhyL6VSCount",
      "value" = 3,
      "comment" = "the three sixth level spells taking verbal and somatic - heal, immunity to weapons, speak w/ monsters; the bitmask reads 3",
    }, {
      "name" = "dhyL6VerbalOnlyCount",
      "value" = 1,
      "comment" = "the one sixth level spell taking the verbal component only - instruct",
    }, {
      "name" = "dhyL6DayCasts",
      "value" = 1,
      "comment" = "the one sixth level spell with a one-day casting time - longevity, the longest cast in the chapter, pinned as 8640 segments (60 per turn, 144 turns per day)",
    }, {
      "name" = "dhyL6ThreeTurnCasts",
      "value" = 1,
      "comment" = "the one sixth level spell with a three-turn casting time - instruct",
    }, {
      "name" = "dhyL6ThreeRoundCasts",
      "value" = 1,
      "comment" = "the one sixth level spell with a three-round casting time - find the path",
    }, {
      "name" = "dhyL6RoundCasts",
      "value" = 4,
      "comment" = "the four sixth level spells with a one-round casting time - heal, inanimate servant, invisibility to enemies, quickgrowth",
    }, {
      "name" = "dhyL6OneSegmentCasts",
      "value" = 3,
      "comment" = "the three sixth level spells with a one-segment casting time - force shapechange, immunity to weapons, smite",
    }, {
      "name" = "dhyL6NegSaves",
      "value" = 2,
      "comment" = "the two sixth level spells with a negation saving throw - instruct, plane shift",
    }, {
      "name" = "dhyL6SpecialSaves",
      "value" = 1,
      "comment" = "the one sixth level spell with a special saving throw - longevity (the system shock roll)",
    }, {
      "name" = "dhyL6HalfSaves",
      "value" = 2,
      "comment" = "the two sixth level spells with the half saving throw code - force shapechange, smite; a successful save halving the damage",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhyL6School",
      "values" = { 2, 7, 5, 6, 4, 1, 9, 6, 6, 6, 3, 6 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell schools by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration, 9 illusion/phantasm - alteration the most common at five spells (immunity to weapons, longevity, plane shift, quickgrowth, speak w/ monsters); the other seven schools appear exactly once each; no invocation spell this level",
    }, {
      "name" = "dhyL6Components",
      "values" = { 7, 7, 3, 3, 7, 1, 7, 7, 7, 7, 7, 3 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell components by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the component codes a bitmask: verbal 1, somatic 2, material 4 - eight spells take all three (7), three take verbal and somatic (3): heal, immunity to weapons, speak w/ monsters; instruct takes the verbal only (1); force shapechange reads V, S, M in the compressed (the print line cutting at its page boundary)",
    }, {
      "name" = "dhyL6CastTime",
      "values" = { 30, 1, 10, 1, 10, 180, 10, 8640, 8, 10, 1, 9 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell casting times by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 3 turns = 180, 3 rounds = 30, and longevity's 1 day pinned as 8640 (60 segments per turn, 144 turns per day, the turn=60 convention): find the path takes three rounds, instruct three turns, four spells a round (heal, inanimate servant, invisibility to enemies, quickgrowth), plane shift eight segments, speak w/ monsters nine, and three cast in a single segment (force shapechange, immunity to weapons, smite)",
    }, {
      "name" = "dhyL6Save",
      "values" = { 0, 3, 0, 0, 0, 1, 0, 2, 1, 0, 3, 0 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell saving throws by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - instruct and plane shift are neg., longevity is special, force shapechange and smite take the half code (a successful save halving the damage), the other seven none",
    }, {
      "name" = "dhyL6Reversible",
      "values" = { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell reversible markers by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the printed header reads Reversible - find the path, heal, immunity to weapons, quickgrowth; the four matching the R658 T62 reversible column",
    }, {
      "name" = "dhyL6Sohei",
      "values" = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
      "default" = 0,
      "comment" = "the shukenja 6th level spell sohei-usable markers by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the printed asterisk marks the spell usable by sohei - find the path, immunity to weapons, smite, speak w/ monsters; the four matching the R658 T62 sohei column",
    } },
  "tables" = { {
      "name" = "dhyL6Grid",
      "tag" = "L6Data",
      "count" = "dhyL6SpellCount",
      "col_default" = 0,
      "cols" = { "dhyL6School", "dhyL6Components", "dhyL6CastTime", "dhyL6Save", "dhyL6Reversible", "dhyL6Sohei" },
      "col_comments" = { "the shukenja 6th level spell schools by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration, 9 illusion/phantasm - alteration the most common at five spells (immunity to weapons, longevity, plane shift, quickgrowth, speak w/ monsters); the other seven schools appear exactly once each; no invocation spell this level", "the shukenja 6th level spell components by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the component codes a bitmask: verbal 1, somatic 2, material 4 - eight spells take all three (7), three take verbal and somatic (3): heal, immunity to weapons, speak w/ monsters; instruct takes the verbal only (1); force shapechange reads V, S, M in the compressed (the print line cutting at its page boundary)", "the shukenja 6th level spell casting times by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 3 turns = 180, 3 rounds = 30, and longevity's 1 day pinned as 8640 (60 segments per turn, 144 turns per day, the turn=60 convention): find the path takes three rounds, instruct three turns, four spells a round (heal, inanimate servant, invisibility to enemies, quickgrowth), plane shift eight segments, speak w/ monsters nine, and three cast in a single segment (force shapechange, immunity to weapons, smite)", "the shukenja 6th level spell saving throws by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - instruct and plane shift are neg., longevity is special, force shapechange and smite take the half code (a successful save halving the damage), the other seven none", "the shukenja 6th level spell reversible markers by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the printed header reads Reversible - find the path, heal, immunity to weapons, quickgrowth; the four matching the R658 T62 reversible column", "the shukenja 6th level spell sohei-usable markers by ordinal (print pp. 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the printed asterisk marks the spell usable by sohei - find the path, immunity to weapons, smite, speak w/ monsters; the four matching the R658 T62 sohei column" },
      "data" = { { 2, 7, 30, 0, 1, 1 }, { 7, 7, 1, 3, 0, 0 }, { 5, 3, 10, 0, 1, 0 }, { 6, 3, 1, 0, 1, 1 }, { 4, 7, 10, 0, 0, 0 }, { 1, 1, 180, 1, 0, 0 }, { 9, 7, 10, 0, 0, 0 }, { 6, 7, 8640, 2, 0, 0 }, { 6, 7, 8, 1, 0, 0 }, { 6, 7, 10, 0, 1, 0 }, { 3, 7, 1, 3, 0, 1 }, { 6, 3, 9, 0, 0, 1 } },
      "comment" = "the Table 62 sixth level spell stat grid (print pp. 143-147; compressed pp. 69-72)",
      "audit_comment" = "the sixth level stat grid: the school, component, casting time and saving throw codes with the reversible and sohei markers by spell ordinal",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhyL6SpellCount']() != 12  or m['dhyL6SoheiCount']() != 4  or m['dhyL6ReversibleCount']() != 4  or m['dhyL6AlterationCount']() != 5  or m['dhyL6VSMCount']() != 8  or m['dhyL6VSCount']() != 3  or m['dhyL6VerbalOnlyCount']() != 1  or m['dhyL6DayCasts']() != 1  or m['dhyL6ThreeTurnCasts']() != 1  or m['dhyL6ThreeRoundCasts']() != 1  or m['dhyL6RoundCasts']() != 4  or m['dhyL6OneSegmentCasts']() != 3  or m['dhyL6NegSaves']() != 2  or m['dhyL6SpecialSaves']() != 1  or m['dhyL6HalfSaves']() != 2",
      "note" = "",
    }, {
      "expr" = "m['dhyL6SpellCount']() != 12  or m['dhyL6SoheiCount']() != 4  or m['dhyL6ReversibleCount']() != 4  or m['dhyL6AlterationCount']() != 5  or m['dhyL6VSMCount']() != 8  or m['dhyL6VSCount']() != 3  or m['dhyL6VerbalOnlyCount']() != 1",
      "note" = "the count pins - twelve sixth level spells, four sohei-usable, four reversible, five alteration",
    }, {
      "expr" = "m['dhyL6School'](0) != 2  or m['dhyL6School'](1) != 7  or m['dhyL6School'](2) != 5  or m['dhyL6School'](4) != 4  or m['dhyL6School'](5) != 1  or m['dhyL6School'](6) != 9  or m['dhyL6School'](10) != 3  or m['dhyL6School'](3) != 6  or m['dhyL6School'](7) != 6  or m['dhyL6School'](8) != 6  or m['dhyL6School'](9) != 6  or m['dhyL6School'](11) != 6",
      "note" = "the school pins - find the path divination; force shapechange abjuration; heal necromantic; inanimate servant conjuration; instruct enchantment/charm; invisibility to enemies illusion/phantasm; smite evocation; immunity to weapons, longevity, plane shift, quickgrowth and speak w/ monsters alteration",
    }, {
      "expr" = "m['dhyL6Components'](2) != 3  or m['dhyL6Components'](3) != 3  or m['dhyL6Components'](11) != 3  or m['dhyL6Components'](5) != 1  or m['dhyL6Components'](0) != 7  or m['dhyL6Components'](1) != 7  or m['dhyL6Components'](7) != 7  or m['dhyL6Components'](10) != 7  or m['dhyL6Components'](4) != 7  or m['dhyL6Components'](9) != 7",
      "note" = "the component pins - the three verbal and somatic (heal, immunity to weapons, speak w/ monsters); instruct the verbal only; the eight all-component with find the path, force shapechange, longevity and smite pinned",
    }, {
      "expr" = "m['dhyL6CastTime'](7) != 8640  or m['dhyL6CastTime'](5) != 180  or m['dhyL6CastTime'](0) != 30  or m['dhyL6CastTime'](2) != 10  or m['dhyL6CastTime'](4) != 10  or m['dhyL6CastTime'](6) != 10  or m['dhyL6CastTime'](9) != 10  or m['dhyL6CastTime'](8) != 8  or m['dhyL6CastTime'](11) != 9  or m['dhyL6CastTime'](1) != 1  or m['dhyL6CastTime'](3) != 1  or m['dhyL6CastTime'](10) != 1",
      "note" = "the casting time pins - longevity the one-day cast 8640 (the longest in the chapter); instruct three turns; find the path three rounds; the four one-round casts; plane shift eight segments; speak w/ monsters nine; the three single-segment casts (force shapechange, immunity to weapons, smite)",
    }, {
      "expr" = "m['dhyL6Save'](5) != 1  or m['dhyL6Save'](8) != 1  or m['dhyL6Save'](7) != 2  or m['dhyL6Save'](1) != 3  or m['dhyL6Save'](10) != 3  or m['dhyL6Save'](0) != 0  or m['dhyL6Save'](2) != 0  or m['dhyL6Save'](11) != 0",
      "note" = "the saving throw pins - instruct and plane shift neg.; longevity special; force shapechange and smite the half code; the seven others none",
    }, {
      "expr" = "m['dhyL6Reversible'](0) != 1  or m['dhyL6Reversible'](2) != 1  or m['dhyL6Reversible'](3) != 1  or m['dhyL6Reversible'](9) != 1  or m['dhyL6Reversible'](1) != 0  or m['dhyL6Reversible'](7) != 0  or m['dhyL6Reversible'](10) != 0",
      "note" = "the reversible pins - find the path, heal, immunity to weapons and quickgrowth marked; force shapechange, longevity and smite not - the four matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhyL6Sohei'](0) != 1  or m['dhyL6Sohei'](3) != 1  or m['dhyL6Sohei'](10) != 1  or m['dhyL6Sohei'](11) != 1  or m['dhyL6Sohei'](2) != 0  or m['dhyL6Sohei'](5) != 0  or m['dhyL6Sohei'](7) != 0",
      "note" = "the sohei pins - find the path, immunity to weapons, smite and speak w/ monsters marked; heal, instruct and longevity not - the four matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhyL6DayCasts']() != 1  or m['dhyL6ThreeTurnCasts']() != 1  or m['dhyL6ThreeRoundCasts']() != 1  or m['dhyL6RoundCasts']() != 4  or m['dhyL6OneSegmentCasts']() != 3  or m['dhyL6NegSaves']() != 2  or m['dhyL6SpecialSaves']() != 1  or m['dhyL6HalfSaves']() != 2",
      "note" = "the grid-sum pins - eight VSM, three VS and the instruct verbal only; the one-day, three-turn and three-round casts; four one-round and three one-segment casts; two neg., one special and two half saves",
    } },
  "audit" = {
      "label" = "R664 OA sixth level spells audit",
      "comment" = "OA round fifty-one (capture pp. 143-147): the sixth level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
