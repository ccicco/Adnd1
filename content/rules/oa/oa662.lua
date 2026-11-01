-- oa662: promoted from rules/oal4spells.h (the FOURTH LEVEL SPELLS, printed capture pp. 132-140 - the OA fourth level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 662,
  "prefix" = "oa662",
  "banner" = {
      "title" = "FOURTH LEVEL SPELLS, printed capture pp. 132-140 - the OA fourth level",
      "provenance" = "spells round census 584 -> 585.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 20 fourth level spell stat blocks cross-checked spell by spell between the passes (print pp. 132-140; compressed pp. 66-69); all 20 schools, component sets, casting times and saving throws agree, zero contested stat reads. Three component singles dot the level: polymorph self takes the verbal only, endurance the somatic and material, reward the verbal and material - all three read identically in the two passes. Two new encodings debut: the exorcise cast is variable (1-100+ turns, the only unfixed cast in the chapter) and pins as -1, and the snake barrier save reads 1/2 - the print garbling it as 112, the compressed reading it clean - pinning as the new half code 3. Fate takes the longest fixed cast at six turns. Alteration is the most common school at seven spells; abjure's dual school abjuration/conjuration pins as the primary abjuration. The reversible flags agree between the passes; the sohei-usable marks ride the R658 T62 grid. The stat grid pins as a table: 20 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, 6 turns = 360, -1 the variable cast), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and sohei markers. The spell names ride the column comments, the prose descriptions and the Table 65 fate grid close in their own rounds. The table tag L4Data identifier-safe per the R639 lesson  the gap census after this round: 115 closed, 120 open - the Fourth Level Spells box flips (census 584 -> 585); NEXT - R663: the Fifth Level Spells (capture pp. 140-143), prefix dhx (verify free), audit \"R663 OA fifth level spells audit\", include after rules/oal4spells.h",
    },
  "consts" = { {
      "name" = "dhwL4SpellCount",
      "value" = 20,
      "comment" = "the 20 fourth level shukenja spells (print pp. 132-140; compressed pp. 66-69)",
    }, {
      "name" = "dhwL4SoheiCount",
      "value" = 3,
      "comment" = "the three fourth level spells usable by sohei - endurance, penetrate disguise, spell immunity",
    }, {
      "name" = "dhwL4ReversibleCount",
      "value" = 7,
      "comment" = "the seven reversible fourth level spells - abjure, cure serious wounds, detect lie, endurance, neutralize poison, protection from evil 10', tongues",
    }, {
      "name" = "dhwL4AlterationCount",
      "value" = 7,
      "comment" = "the seven alteration fourth level spells - the most common school of the level: endurance, neutralize poison, pacify, polymorph self, speak w/ plants, sustain, tongues",
    }, {
      "name" = "dhwL4AbjurationCount",
      "value" = 5,
      "comment" = "the five abjuration fourth level spells - abjure, exorcise, protection from evil 10', remorse, spell immunity",
    }, {
      "name" = "dhwL4DivinationCount",
      "value" = 4,
      "comment" = "the four divination fourth level spells - detect lie, detect shapechanger, fate, penetrate disguise",
    }, {
      "name" = "dhwL4NecromanticCount",
      "value" = 2,
      "comment" = "the two necromantic fourth level spells - cure serious wounds, reanimation",
    }, {
      "name" = "dhwL4ConjurationCount",
      "value" = 1,
      "comment" = "the one conjuration fourth level spell - reward",
    }, {
      "name" = "dhwL4EvocationCount",
      "value" = 1,
      "comment" = "the one evocation fourth level spell - snake barrier",
    }, {
      "name" = "dhwL4VSMCount",
      "value" = 12,
      "comment" = "the twelve fourth level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhwL4VSCount",
      "value" = 5,
      "comment" = "the five fourth level spells taking verbal and somatic - the bitmask reads 3",
    }, {
      "name" = "dhwL4VerbalOnlyCount",
      "value" = 1,
      "comment" = "the one fourth level spell taking the verbal component only - polymorph self",
    }, {
      "name" = "dhwL4SMCount",
      "value" = 1,
      "comment" = "the one fourth level spell taking somatic and material only - endurance",
    }, {
      "name" = "dhwL4VMCount",
      "value" = 1,
      "comment" = "the one fourth level spell taking verbal and material - reward",
    }, {
      "name" = "dhwL4TurnCasts",
      "value" = 3,
      "comment" = "the three fourth level spells with a one-turn casting time - endurance, reward, speak w/ plants",
    }, {
      "name" = "dhwL4SixTurnCasts",
      "value" = 1,
      "comment" = "the one fourth level spell with a six-turn casting time - fate, the longest fixed cast in the level",
    }, {
      "name" = "dhwL4VariableCasts",
      "value" = 1,
      "comment" = "the one fourth level spell with a variable casting time - exorcise at 1-100+ turns, the only unfixed cast in the chapter, pinned as -1",
    }, {
      "name" = "dhwL4RoundCasts",
      "value" = 6,
      "comment" = "the six fourth level spells with a one-round casting time",
    }, {
      "name" = "dhwL4NegSaves",
      "value" = 3,
      "comment" = "the three fourth level spells with a negation saving throw - abjure, penetrate disguise, remorse",
    }, {
      "name" = "dhwL4HalfSaves",
      "value" = 1,
      "comment" = "the one fourth level spell with the half saving throw code - snake barrier; the code debuting this level (the print garbling the 1/2 as 112, the compressed reading it clean)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhwL4School",
      "values" = { 7, 5, 2, 2, 6, 7, 2, 6, 6, 2, 6, 7, 5, 7, 4, 3, 6, 7, 6, 6 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell schools by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration - alteration the most common at seven spells; abjure pins its dual school abjuration/conjuration as the primary abjuration",
    }, {
      "name" = "dhwL4Components",
      "values" = { 7, 3, 7, 7, 6, 7, 7, 3, 3, 3, 1, 7, 7, 7, 5, 7, 7, 7, 7, 3 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell components by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the component codes a bitmask: verbal 1, somatic 2, material 4 - twelve spells take all three (7), five take verbal and somatic (3), and three singles dot the level: polymorph self the verbal only (1), endurance the somatic and material (6), reward the verbal and material (5)",
    }, {
      "name" = "dhwL4CastTime",
      "values" = { 10, 7, 7, 10, 60, -1, 360, 7, 4, 20, 3, 7, 10, 10, 60, 4, 60, 10, 10, 7 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell casting times by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 6 turns = 360, and the exorcise cast is variable (1-100+ turns, the only unfixed cast in the chapter) pinned as -1: fate takes the six turns, three spells take a turn (endurance, reward, speak w/ plants), penetrate disguise takes two rounds, six a round, five take seven segments, pacify and snake barrier four, polymorph self three",
    }, {
      "name" = "dhwL4Save",
      "values" = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell saving throws by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - the half code debuting on snake barrier (the print garbling the 1/2 as 112, the compressed reading it clean; a successful save halves the damage); abjure, penetrate disguise and remorse are neg., reanimation special, the other fifteen none",
    }, {
      "name" = "dhwL4Reversible",
      "values" = { 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell reversible markers by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the cell is 1 where the printed header reads Reversible - abjure, cure serious wounds, detect lie, endurance, neutralize poison, protection from evil 10', tongues; the seven matching the R658 T62 reversible column",
    }, {
      "name" = "dhwL4Sohei",
      "values" = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 4th level spell sohei-usable markers by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the cell is 1 where the printed asterisk marks the spell usable by sohei - endurance, penetrate disguise, spell immunity; the three matching the R658 T62 sohei column (tongues reversible but not sohei-usable)",
    } },
  "tables" = { {
      "name" = "dhwL4Grid",
      "tag" = "L4Data",
      "count" = "dhwL4SpellCount",
      "col_default" = 0,
      "cols" = { "dhwL4School", "dhwL4Components", "dhwL4CastTime", "dhwL4Save", "dhwL4Reversible", "dhwL4Sohei" },
      "col_comments" = { "the shukenja 4th level spell schools by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration - alteration the most common at seven spells; abjure pins its dual school abjuration/conjuration as the primary abjuration", "the shukenja 4th level spell components by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the component codes a bitmask: verbal 1, somatic 2, material 4 - twelve spells take all three (7), five take verbal and somatic (3), and three singles dot the level: polymorph self the verbal only (1), endurance the somatic and material (6), reward the verbal and material (5)", "the shukenja 4th level spell casting times by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 6 turns = 360, and the exorcise cast is variable (1-100+ turns, the only unfixed cast in the chapter) pinned as -1: fate takes the six turns, three spells take a turn (endurance, reward, speak w/ plants), penetrate disguise takes two rounds, six a round, five take seven segments, pacify and snake barrier four, polymorph self three", "the shukenja 4th level spell saving throws by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - the half code debuting on snake barrier (the print garbling the 1/2 as 112, the compressed reading it clean; a successful save halves the damage); abjure, penetrate disguise and remorse are neg., reanimation special, the other fifteen none", "the shukenja 4th level spell reversible markers by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the cell is 1 where the printed header reads Reversible - abjure, cure serious wounds, detect lie, endurance, neutralize poison, protection from evil 10', tongues; the seven matching the R658 T62 reversible column", "the shukenja 4th level spell sohei-usable markers by ordinal (print pp. 132-140; compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19 sustain, 20 tongues - the cell is 1 where the printed asterisk marks the spell usable by sohei - endurance, penetrate disguise, spell immunity; the three matching the R658 T62 sohei column (tongues reversible but not sohei-usable)" },
      "data" = { { 7, 7, 10, 1, 1, 0 }, { 5, 3, 7, 0, 1, 0 }, { 2, 7, 7, 0, 1, 0 }, { 2, 7, 10, 0, 0, 0 }, { 6, 6, 60, 0, 1, 1 }, { 7, 7, -1, 0, 0, 0 }, { 2, 7, 360, 0, 0, 0 }, { 6, 3, 7, 0, 1, 0 }, { 6, 3, 4, 0, 0, 0 }, { 2, 3, 20, 1, 0, 1 }, { 6, 1, 3, 0, 0, 0 }, { 7, 7, 7, 0, 1, 0 }, { 5, 7, 10, 2, 0, 0 }, { 7, 7, 10, 1, 0, 0 }, { 4, 5, 60, 0, 0, 0 }, { 3, 7, 4, 3, 0, 0 }, { 6, 7, 60, 0, 0, 0 }, { 7, 7, 10, 0, 0, 1 }, { 6, 7, 10, 0, 0, 0 }, { 6, 3, 7, 0, 1, 0 } },
      "comment" = "the Table 62 fourth level spell stat grid (print pp. 132-140; compressed pp. 66-69)",
      "audit_comment" = "the fourth level stat grid: the school, component, casting time and saving throw codes with the reversible and sohei markers by spell ordinal",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhwL4SpellCount']() != 20  or m['dhwL4SoheiCount']() != 3  or m['dhwL4ReversibleCount']() != 7  or m['dhwL4AlterationCount']() != 7  or m['dhwL4AbjurationCount']() != 5  or m['dhwL4DivinationCount']() != 4  or m['dhwL4NecromanticCount']() != 2  or m['dhwL4ConjurationCount']() != 1  or m['dhwL4EvocationCount']() != 1  or m['dhwL4VSMCount']() != 12  or m['dhwL4VSCount']() != 5  or m['dhwL4VerbalOnlyCount']() != 1  or m['dhwL4SMCount']() != 1  or m['dhwL4VMCount']() != 1  or m['dhwL4TurnCasts']() != 3  or m['dhwL4SixTurnCasts']() != 1  or m['dhwL4VariableCasts']() != 1  or m['dhwL4RoundCasts']() != 6  or m['dhwL4NegSaves']() != 3  or m['dhwL4HalfSaves']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhwL4SpellCount']() != 20  or m['dhwL4SoheiCount']() != 3  or m['dhwL4ReversibleCount']() != 7  or m['dhwL4AlterationCount']() != 7  or m['dhwL4AbjurationCount']() != 5  or m['dhwL4DivinationCount']() != 4  or m['dhwL4NecromanticCount']() != 2  or m['dhwL4ConjurationCount']() != 1  or m['dhwL4EvocationCount']() != 1",
      "note" = "the count pins - twenty fourth level spells, three sohei-usable, seven reversible, seven alteration",
    }, {
      "expr" = "m['dhwL4School'](0) != 7  or m['dhwL4School'](1) != 5  or m['dhwL4School'](12) != 5  or m['dhwL4School'](6) != 2  or m['dhwL4School'](9) != 2  or m['dhwL4School'](14) != 4  or m['dhwL4School'](15) != 3  or m['dhwL4School'](10) != 6  or m['dhwL4School'](18) != 6",
      "note" = "the school pins - abjure the dual school primary abjuration 7; cure serious wounds and reanimation necromantic; fate and penetrate disguise divination; reward conjuration; snake barrier evocation; polymorph self and sustain alteration",
    }, {
      "expr" = "m['dhwL4Components'](10) != 1  or m['dhwL4Components'](4) != 6  or m['dhwL4Components'](14) != 5  or m['dhwL4Components'](0) != 7  or m['dhwL4Components'](5) != 7  or m['dhwL4Components'](17) != 7  or m['dhwL4Components'](1) != 3  or m['dhwL4Components'](19) != 3",
      "note" = "the component pins - the component singles: polymorph self the verbal only (1), endurance the somatic and material (6), reward the verbal and material (5); the twelve all-component spells with abjure, exorcise and spell immunity pinned; cure serious wounds and tongues verbal and somatic",
    }, {
      "expr" = "m['dhwL4CastTime'](5) != -1  or m['dhwL4CastTime'](6) != 360  or m['dhwL4CastTime'](9) != 20  or m['dhwL4CastTime'](4) != 60  or m['dhwL4CastTime'](14) != 60  or m['dhwL4CastTime'](16) != 60  or m['dhwL4CastTime'](1) != 7  or m['dhwL4CastTime'](11) != 7  or m['dhwL4CastTime'](19) != 7  or m['dhwL4CastTime'](8) != 4  or m['dhwL4CastTime'](15) != 4  or m['dhwL4CastTime'](10) != 3",
      "note" = "the casting time pins - exorcise the variable 1-100+ turns cast pinned as -1 (the only unfixed cast in the chapter); fate the six-turn cast; penetrate disguise two rounds; the three one-turn casts (endurance, reward, speak w/ plants); the seven-segment casts (cure serious wounds, detect lie, neutralize poison, protection from evil 10', tongues); pacify and snake barrier four, polymorph self three",
    }, {
      "expr" = "m['dhwL4Save'](0) != 1  or m['dhwL4Save'](9) != 1  or m['dhwL4Save'](13) != 1  or m['dhwL4Save'](12) != 2  or m['dhwL4Save'](15) != 3  or m['dhwL4Save'](1) != 0  or m['dhwL4Save'](6) != 0  or m['dhwL4Save'](19) != 0",
      "note" = "the saving throw pins - abjure, penetrate disguise and remorse neg.; reanimation special; snake barrier the debuting half code 3 (the print 112 garble settling per the compressed 1/2); the fifteen others none",
    }, {
      "expr" = "m['dhwL4Reversible'](0) != 1  or m['dhwL4Reversible'](1) != 1  or m['dhwL4Reversible'](2) != 1  or m['dhwL4Reversible'](4) != 1  or m['dhwL4Reversible'](7) != 1  or m['dhwL4Reversible'](11) != 1  or m['dhwL4Reversible'](19) != 1  or m['dhwL4Reversible'](5) != 0  or m['dhwL4Reversible'](6) != 0  or m['dhwL4Reversible'](15) != 0",
      "note" = "the reversible pins - the seven marks (abjure, cure serious wounds, detect lie, endurance, neutralize poison, protection from evil 10', tongues); exorcise, fate and snake barrier not - the seven matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhwL4Sohei'](4) != 1  or m['dhwL4Sohei'](9) != 1  or m['dhwL4Sohei'](17) != 1  or m['dhwL4Sohei'](0) != 0  or m['dhwL4Sohei'](6) != 0  or m['dhwL4Sohei'](19) != 0",
      "note" = "the sohei pins - endurance, penetrate disguise and spell immunity marked; abjure, fate and tongues not - the three matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhwL4VSMCount']() != 12  or m['dhwL4VSCount']() != 5  or m['dhwL4VerbalOnlyCount']() != 1  or m['dhwL4SMCount']() != 1  or m['dhwL4VMCount']() != 1  or m['dhwL4TurnCasts']() != 3  or m['dhwL4SixTurnCasts']() != 1  or m['dhwL4VariableCasts']() != 1  or m['dhwL4RoundCasts']() != 6  or m['dhwL4NegSaves']() != 3  or m['dhwL4HalfSaves']() != 1",
      "note" = "the grid-sum pins - twelve VSM, five VS and the three component singles; three one-turn, one six-turn and one variable casts; three neg. and one half saves",
    } },
  "audit" = {
      "label" = "R662 OA fourth level spells audit",
      "comment" = "OA round forty-nine (capture pp. 132-140): the fourth level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
