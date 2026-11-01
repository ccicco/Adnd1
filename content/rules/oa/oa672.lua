-- oa672: promoted from rules/oawjl3spells.h (the WU JEN THIRD LEVEL SPELLS, printed capture pp. 173-181 - the OA wu jen);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 672,
  "prefix" = "oa672",
  "banner" = {
      "title" = "WU JEN THIRD LEVEL SPELLS, printed capture pp. 173-181 - the OA wu jen",
      "provenance" = "third level spells round census 594 -> 595.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print pp. 173-181; compressed pp. 82-85); all 24 stat blocks cross-checked spell by spell between the passes, zero contested stat reads - the variances typographic or prose-only (the compressed Scy for scry in the header, the print 6-10 against the compressed 8-10 for the cloudburst large-fire quench, the feign death duration sign, the fire rain 1d8 read as 108 in the compressed - none of them grid cells). The level is alteration-heavy again: seven of the 24 spells, enchantment/charm and illusion four each, divination three, evocation and abjuration two each, conjuration and necromantic one each (animate fire the lone conjuration, feign death the lone necromantic). TWO dual-school prints pin the primary (the exaction precedent): fabricate the Enchantment/Alteration dual pinned 1, face the Illusion/Phantasm; Enchantment/Charm dual pinned 9. The component census: 19 VSM, dispel magic and feign death the verbal and somatic pair, suggestion and tongues the V,M pairs, hold person the lone verbal-only. THREE spells take the Casting Time: Special line (fabricate, illusionary script, memory) pinned -1, the R662 exorcise variable-cast convention; four one-turn casts (commune with lesser spirit, disguise, face, scry), five one-round, seven three-segment, cloudburst and fire rain five segments, statue the lone seven-segment cast, feign death the lone single segment. Four negation saves, four special, fire rain and steam breath the two half saves (the damage halved). Four spells read Reversible (face, magnetism, memory, tongues). The sixth column cross-checks the R669 element grid: the seven tagged cells matching the landed dieWJT66L3Element pins exactly - animate fire Fire, cloudburst the Water/Air dual code 8, magnetism and statue Earth, steam breath Air, scry All, wood shape Nature. The stat grid pins as a table: 24 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, -1 the special cast), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and element markers. The spell names ride the column comments, the prose descriptions close in their own rounds. The table tag WJL3Data identifier-safe per the R639 lesson  the gap census after this round: 125 closed, 110 open - the wu jen Third Level Spells box flips (census 594 -> 595); NEXT - R673: the wu jen Fourth Level Spells (capture pp. 177-188, the 24 stat blocks), prefix dii (verify free), audit \"R673 OA wu jen fourth level spells audit\"",
    },
  "consts" = { {
      "name" = "dihWJL3SpellCount",
      "value" = 24,
      "comment" = "the 24 third level wu jen spells (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3AlterationCount",
      "value" = 7,
      "comment" = "the seven alteration third level wu jen spells - cloudburst, fire wings, haste, magnetism, statue, tongues, wood shape; the most common school (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3EnchantmentCount",
      "value" = 4,
      "comment" = "the four enchantment/charm third level wu jen spells - fabricate, hold person, memory, suggestion (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3IllusionCount",
      "value" = 4,
      "comment" = "the four illusion third level wu jen spells - disguise, face, illusionary script, improved phantasmal force (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3DivinationCount",
      "value" = 3,
      "comment" = "the three divination third level wu jen spells - commune with lesser spirit, detect shapechanger, scry (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3ReversibleCount",
      "value" = 4,
      "comment" = "the four reversible third level wu jen spells - face (lose face), magnetism (demagnetize), memory (erasement), tongues (its reverse) (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3VSMCount",
      "value" = 19,
      "comment" = "the 19 third level wu jen spells taking all three components - the bitmask reads 7 (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3VSCount",
      "value" = 2,
      "comment" = "the two third level wu jen spells taking verbal and somatic - dispel magic, feign death; the bitmask reads 3 (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3VMCount",
      "value" = 2,
      "comment" = "the two third level wu jen spells taking verbal and material without the somatic - suggestion, tongues; the bitmask reads 5 (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3VerbalOnlyCount",
      "value" = 1,
      "comment" = "the one third level wu jen spell taking the verbal component only - hold person (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3SpecialCasts",
      "value" = 3,
      "comment" = "the three third level wu jen spells with the Casting Time: Special line - fabricate, illusionary script, memory; pinned -1, the R662 exorcise variable-cast convention (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3TurnCasts",
      "value" = 4,
      "comment" = "the four third level wu jen spells with a one-turn casting time - commune with lesser spirit, disguise, face, scry (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3RoundCasts",
      "value" = 5,
      "comment" = "the five third level wu jen spells with a one-round casting time - animate fire, detect shapechanger, fire wings, steam breath, wood shape (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3ThreeSegmentCasts",
      "value" = 7,
      "comment" = "the seven third level wu jen spells with a three-segment casting time - dispel magic, haste, hold person, magnetism, protection from normal missiles, suggestion, tongues; the most common fixed cast of the level (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3FiveSegmentCasts",
      "value" = 2,
      "comment" = "the two third level wu jen spells with a five-segment casting time - cloudburst, fire rain (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3SevenSegmentCasts",
      "value" = 1,
      "comment" = "the one third level wu jen spell with a seven-segment casting time - statue (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3NegSaves",
      "value" = 4,
      "comment" = "the four third level wu jen spells with a negation saving throw - hold person, magnetism, memory, suggestion (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3SpecialSaves",
      "value" = 4,
      "comment" = "the four third level wu jen spells with a special saving throw - disguise, face, improved phantasmal force, statue (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3HalfSaves",
      "value" = 2,
      "comment" = "the two third level wu jen spells with the half saving throw code - fire rain, steam breath, the damage halved on a successful save (print pp. 173-181; compressed pp. 82-85)",
    }, {
      "name" = "dihWJL3ElementCount",
      "value" = 7,
      "comment" = "the seven element-tagged third level wu jen spells - animate fire Fire, cloudburst the Water/Air dual, magnetism and statue Earth, steam breath Air, scry All, wood shape Nature - matching the R669 dieWJT66L3Element grid exactly (print pp. 173-181; compressed pp. 82-85)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dihWJL3School",
      "values" = { 4, 6, 2, 2, 9, 7, 1, 9, 5, 3, 6, 6, 1, 9, 9, 6, 1, 7, 3, 2, 6, 1, 6, 6 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell schools by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 9 illusion/phantasm - alteration the most common school at seven spells (cloudburst, fire wings, haste, magnetism, statue, tongues, wood shape); enchantment/charm and illusion four each (fabricate, hold person, memory, suggestion; disguise, face, illusionary script, improved phantasmal force); divination three; evocation and abjuration two each; conjuration and necromantic one each (animate fire the lone conjuration, feign death the lone necromantic) - TWO dual-school prints pin the primary (the exaction precedent): fabricate the Enchantment/Alteration dual pinned 1, face the Illusion/Phantasm; Enchantment/Charm dual pinned 9",
    }, {
      "name" = "dihWJL3Components",
      "values" = { 7, 7, 7, 7, 7, 3, 7, 7, 3, 7, 7, 7, 1, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 7 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell components by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the component codes a bitmask: verbal 1, somatic 2, material 4 - 19 spells take all three (7), two verbal and somatic (3): dispel magic, feign death; suggestion and tongues the verbal and material without the somatic (5); hold person the lone verbal only (1)",
    }, {
      "name" = "dihWJL3CastTime",
      "values" = { 10, 5, 60, 10, 60, 3, -1, 60, 1, 5, 10, 3, 3, -1, 2, 3, -1, 3, 10, 60, 7, 3, 3, 10 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell casting times by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the casting time in segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the Casting Time: Special line (the R662 exorcise convention): three special casts (fabricate, illusionary script, memory), four a full turn (commune with lesser spirit, disguise, face, scry), five a full round (animate fire, detect shapechanger, fire wings, steam breath, wood shape), seven three segments (the most common fixed cast), cloudburst and fire rain five segments, statue the lone seven-segment cast, improved phantasmal force two segments, feign death the lone single segment",
    }, {
      "name" = "dihWJL3Save",
      "values" = { 0, 0, 0, 0, 2, 0, 0, 2, 0, 3, 0, 0, 1, 0, 2, 1, 1, 0, 3, 0, 2, 1, 0, 0 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell saving throws by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - hold person, magnetism, memory and suggestion neg.; disguise, face, improved phantasmal force and statue special; fire rain and steam breath the half code (the damage halved on a successful save); the other 14 none",
    }, {
      "name" = "dihWJL3Reversible",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell reversible markers by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the cell is 1 where the printed header reads Reversible - face (lose face), magnetism (demagnetize), memory (erasement), tongues (its reverse); the four",
    }, {
      "name" = "dihWJL3Element",
      "values" = { 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 7, 2, 0, 0, 5 },
      "default" = 0,
      "comment" = "the wu jen 3rd level spell element marks by ordinal (print pp. 173-181; compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst) - the seven tagged spells (animate fire Fire, cloudburst the dual 8, magnetism and statue Earth, steam breath Air, scry All, wood shape Nature) matching the R669 dieWJT66L3Element pins exactly - the cross-check column",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dihWJL3SpellCount']() != 24  or m['dihWJL3AlterationCount']() != 7  or m['dihWJL3EnchantmentCount']() != 4  or m['dihWJL3IllusionCount']() != 4  or m['dihWJL3DivinationCount']() != 3  or m['dihWJL3ReversibleCount']() != 4  or m['dihWJL3VSMCount']() != 19  or m['dihWJL3VSCount']() != 2  or m['dihWJL3VMCount']() != 2  or m['dihWJL3VerbalOnlyCount']() != 1  or m['dihWJL3SpecialCasts']() != 3  or m['dihWJL3TurnCasts']() != 4  or m['dihWJL3RoundCasts']() != 5  or m['dihWJL3ThreeSegmentCasts']() != 7  or m['dihWJL3FiveSegmentCasts']() != 2  or m['dihWJL3SevenSegmentCasts']() != 1  or m['dihWJL3NegSaves']() != 4  or m['dihWJL3SpecialSaves']() != 4  or m['dihWJL3HalfSaves']() != 2  or m['dihWJL3ElementCount']() != 7",
      "note" = "",
    }, {
      "expr" = "m['dihWJL3SpellCount']() != 24  or m['dihWJL3AlterationCount']() != 7  or m['dihWJL3EnchantmentCount']() != 4  or m['dihWJL3IllusionCount']() != 4  or m['dihWJL3DivinationCount']() != 3  or m['dihWJL3ReversibleCount']() != 4",
      "note" = "the count pins - 24 spells, seven alteration, four enchantment/charm, four illusion, three divination, four reversible",
    }, {
      "expr" = "m['dihWJL3VSMCount']() != 19  or m['dihWJL3VSCount']() != 2  or m['dihWJL3VMCount']() != 2  or m['dihWJL3VerbalOnlyCount']() != 1",
      "note" = "the component pins - 19 VSM, two VS, suggestion and tongues the V,M pairs, hold person the verbal only",
    }, {
      "expr" = "m['dihWJL3SpecialCasts']() != 3  or m['dihWJL3TurnCasts']() != 4  or m['dihWJL3RoundCasts']() != 5  or m['dihWJL3ThreeSegmentCasts']() != 7  or m['dihWJL3FiveSegmentCasts']() != 2  or m['dihWJL3SevenSegmentCasts']() != 1",
      "note" = "the casting time pins - three Special casts (-1), four turn casts, five round casts, seven three-segment, two five-segment, statue the seven",
    }, {
      "expr" = "m['dihWJL3NegSaves']() != 4  or m['dihWJL3SpecialSaves']() != 4  or m['dihWJL3HalfSaves']() != 2  or m['dihWJL3ElementCount']() != 7",
      "note" = "the saving throw pins - four neg., four special, fire rain and steam breath the two half",
    }, {
      "expr" = "m['dihWJL3School'](8) != 5  or m['dihWJL3School'](0) != 4  or m['dihWJL3School'](5) != 7  or m['dihWJL3School'](17) != 7  or m['dihWJL3School'](9) != 3  or m['dihWJL3School'](18) != 3  or m['dihWJL3School'](2) != 2  or m['dihWJL3School'](3) != 2  or m['dihWJL3School'](19) != 2  or m['dihWJL3School'](6) != 1  or m['dihWJL3School'](12) != 1  or m['dihWJL3School'](16) != 1  or m['dihWJL3School'](21) != 1  or m['dihWJL3School'](4) != 9  or m['dihWJL3School'](7) != 9  or m['dihWJL3School'](13) != 9  or m['dihWJL3School'](14) != 9  or m['dihWJL3School'](1) != 6  or m['dihWJL3School'](10) != 6  or m['dihWJL3School'](11) != 6  or m['dihWJL3School'](22) != 6",
      "note" = "the school pins - feign death the lone necromantic; animate fire the lone conjuration; dispel magic and protection from normal missiles abjuration; fire rain and steam breath evocation; commune, detect shapechanger and scry divination; the four enchantment/charm; the four illusion; cloudburst, fire wings, haste and tongues among the seven alteration",
    }, {
      "expr" = "m['dihWJL3Components'](12) != 1  or m['dihWJL3Components'](21) != 5  or m['dihWJL3Components'](22) != 5  or m['dihWJL3Components'](5) != 3  or m['dihWJL3Components'](8) != 3  or m['dihWJL3Components'](0) != 7  or m['dihWJL3Components'](1) != 7  or m['dihWJL3Components'](19) != 7  or m['dihWJL3Components'](20) != 7  or m['dihWJL3Components'](23) != 7",
      "note" = "the component cell pins - the verbal-only hold person, the V,M suggestion and tongues, the VS dispel magic and feign death, and the VSM spots",
    }, {
      "expr" = "m['dihWJL3CastTime'](6) != -1  or m['dihWJL3CastTime'](13) != -1  or m['dihWJL3CastTime'](16) != -1  or m['dihWJL3CastTime'](2) != 60  or m['dihWJL3CastTime'](4) != 60  or m['dihWJL3CastTime'](7) != 60  or m['dihWJL3CastTime'](19) != 60  or m['dihWJL3CastTime'](20) != 7  or m['dihWJL3CastTime'](1) != 5  or m['dihWJL3CastTime'](9) != 5  or m['dihWJL3CastTime'](8) != 1  or m['dihWJL3CastTime'](14) != 2",
      "note" = "the casting time cell pins - the three Special casts at -1, the turn casts, statue the seven, cloudburst and fire rain the five, feign death the lone segment",
    }, {
      "expr" = "m['dihWJL3Save'](12) != 1  or m['dihWJL3Save'](15) != 1  or m['dihWJL3Save'](16) != 1  or m['dihWJL3Save'](21) != 1  or m['dihWJL3Save'](4) != 2  or m['dihWJL3Save'](7) != 2  or m['dihWJL3Save'](14) != 2  or m['dihWJL3Save'](20) != 2  or m['dihWJL3Save'](9) != 3  or m['dihWJL3Save'](18) != 3  or m['dihWJL3Save'](0) != 0",
      "note" = "the saving throw cell pins - the four negation saves, the four special saves, the two half, animate fire none",
    }, {
      "expr" = "m['dihWJL3Reversible'](7) != 1  or m['dihWJL3Reversible'](15) != 1  or m['dihWJL3Reversible'](16) != 1  or m['dihWJL3Reversible'](22) != 1  or m['dihWJL3Reversible'](11) != 0  or m['dihWJL3Reversible'](5) != 0  or m['dihWJL3Reversible'](8) != 0  or m['dihWJL3Reversible'](0) != 0",
      "note" = "the reversible pins - face, magnetism, memory and tongues marked; haste, dispel magic and feign death not",
    }, {
      "expr" = "m['dihWJL3Element'](0) != 3  or m['dihWJL3Element'](1) != 8  or m['dihWJL3Element'](15) != 2  or m['dihWJL3Element'](20) != 2  or m['dihWJL3Element'](18) != 1  or m['dihWJL3Element'](19) != 7  or m['dihWJL3Element'](23) != 5  or m['dihWJL3Element'](11) != 0  or m['dihWJL3Element'](6) != 0",
      "note" = "the element cross-check pins - the seven tagged cells matching the R669 dieWJT66L3Element grid: animate fire Fire, cloudburst the Water/Air dual 8, magnetism and statue Earth, steam breath Air, scry All, wood shape Nature; haste untagged",
    } },
  "audit" = {
      "label" = "R672 OA wu jen third level spells audit",
      "comment" = "OA round fifty-nine (capture pp. 173-181): the wu jen third level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and element markers, cross-checked spell by spell between the passes",
    },
}
