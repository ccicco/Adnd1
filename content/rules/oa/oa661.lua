-- oa661: promoted from rules/oal3spells.h (the THIRD LEVEL SPELLS, printed capture pp. 126-132 - the OA third level spells);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 661,
  "prefix" = "oa661",
  "banner" = {
      "title" = "THIRD LEVEL SPELLS, printed capture pp. 126-132 - the OA third level spells",
      "provenance" = "round census 583 -> 584.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 20 third level spell stat blocks cross-checked spell by spell between the passes (print pp. 126-132; compressed pp. 63-66); all 20 schools, component sets, casting times and saving throws agree, zero contested stat reads. Two school codes debut this level: invocation (dream vision) and illusion/phantasm (invisibility to spirits) - both headers read identically in the two passes. Abjuration becomes the most common school at seven spells (castigate, cure blindness, cure disease, dispel magic, oath, remove curse, remove paralysis); magical vestment's dual school conjuration/alteration pins as the primary conjuration, the aid convention from the second level. Substitution takes the longest cast in the level at three turns. The reversible flags agree between the passes; the sohei-usable marks ride the R658 T62 grid, settled three rounds before. The stat grid pins as a table: 20 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, 3 turns = 180), saving throw code (0 none, 1 neg., 2 special), reversible and sohei markers. The spell names ride the column comments, the prose descriptions and the Table 64 speak with dead grid close in their own rounds. The table tag L3Data identifier-safe per the R639 lesson  the gap census after this round: 114 closed, 121 open - the Third Level Spells box flips (census 583 -> 584); NEXT - R662: the Fourth Level Spells (capture pp. 132-140), prefix dhw (verify free), audit \"R662 OA fourth level spells audit\", include after rules/oal3spells.h",
    },
  "consts" = { {
      "name" = "dhvL3SpellCount",
      "value" = 20,
      "comment" = "the 20 third level shukenja spells (print pp. 126-132; compressed pp. 63-66)",
    }, {
      "name" = "dhvL3SoheiCount",
      "value" = 4,
      "comment" = "the four third level spells usable by sohei - castigate, dispel magic, flame walk, prayer",
    }, {
      "name" = "dhvL3ReversibleCount",
      "value" = 7,
      "comment" = "the seven reversible third level spells - cure blindness, cure disease, dream vision, know alignment, oath, remove curse, remove paralysis",
    }, {
      "name" = "dhvL3AbjurationCount",
      "value" = 7,
      "comment" = "the seven abjuration third level spells - the most common school of the level: castigate, cure blindness, cure disease, dispel magic, oath, remove curse, remove paralysis",
    }, {
      "name" = "dhvL3DivinationCount",
      "value" = 3,
      "comment" = "the three divination third level spells - detect curse, divination, know alignment",
    }, {
      "name" = "dhvL3AlterationCount",
      "value" = 3,
      "comment" = "the three alteration third level spells - flame walk, levitate, substitution",
    }, {
      "name" = "dhvL3ConjurationCount",
      "value" = 2,
      "comment" = "the two conjuration third level spells - magical vestment (its dual school pinned as the primary conjuration) and prayer",
    }, {
      "name" = "dhvL3NecromanticCount",
      "value" = 2,
      "comment" = "the two necromantic third level spells - death's door, speak w/ dead",
    }, {
      "name" = "dhvL3InvocationCount",
      "value" = 1,
      "comment" = "the one invocation third level spell - dream vision; the school debuting this level",
    }, {
      "name" = "dhvL3IllusionCount",
      "value" = 1,
      "comment" = "the one illusion/phantasm third level spell - invisibility to spirits; the school debuting this level",
    }, {
      "name" = "dhvL3EnchCharmCount",
      "value" = 1,
      "comment" = "the one enchantment/charm third level spell - possess animal",
    }, {
      "name" = "dhvL3VSMCount",
      "value" = 14,
      "comment" = "the fourteen third level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhvL3VSCount",
      "value" = 6,
      "comment" = "the six third level spells taking verbal and somatic - the bitmask reads 3",
    }, {
      "name" = "dhvL3TurnCasts",
      "value" = 5,
      "comment" = "the five third level spells with a one-turn casting time - cure disease, divination, dream vision, invisibility to spirits, speak w/ dead",
    }, {
      "name" = "dhvL3ThreeTurnCasts",
      "value" = 1,
      "comment" = "the one third level spell with a three-turn casting time - substitution, the longest cast in the level",
    }, {
      "name" = "dhvL3RoundCasts",
      "value" = 6,
      "comment" = "the six third level spells with a one-round casting time",
    }, {
      "name" = "dhvL3SixSegmentCasts",
      "value" = 4,
      "comment" = "the four third level spells with a six-segment casting time - dispel magic, prayer, remove curse, remove paralysis",
    }, {
      "name" = "dhvL3NegSaves",
      "value" = 3,
      "comment" = "the three third level spells with a negation saving throw - levitate, oath, possess animal",
    }, {
      "name" = "dhvL3SpecialSaves",
      "value" = 2,
      "comment" = "the two third level spells with a special saving throw - castigate, remove curse",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhvL3School",
      "values" = { 7, 7, 7, 5, 2, 7, 2, 8, 6, 9, 2, 6, 4, 7, 1, 4, 7, 7, 5, 6 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell schools by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - invocation and illusion/phantasm debuting this level (dream vision, invisibility to spirits); abjuration the most common at seven spells; magical vestment pins its dual school conjuration/alteration as the primary 4",
    }, {
      "name" = "dhvL3Components",
      "values" = { 7, 3, 3, 7, 7, 3, 7, 7, 7, 7, 3, 7, 7, 7, 7, 7, 3, 3, 7, 7 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell components by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the component codes a bitmask: verbal 1, somatic 2, material 4 - fourteen spells take all three (7), six take verbal and somatic (3): cure blindness, cure disease, dispel magic, know alignment, remove curse, remove paralysis",
    }, {
      "name" = "dhvL3CastTime",
      "values" = { 3, 10, 60, 5, 10, 6, 60, 60, 5, 60, 10, 2, 10, 10, 10, 6, 6, 6, 60, 180 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell casting times by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 3 turns = 180: substitution takes the three turns (the longest cast in the level), five spells take a turn (cure disease, divination, dream vision, invisibility to spirits, speak w/ dead), six a round, four take six segments (dispel magic, prayer, remove curse, remove paralysis), and the level runs down to levitate's two segments (castigate three, death's door and flame walk five)",
    }, {
      "name" = "dhvL3Save",
      "values" = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 2, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell saving throws by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the saving throw codes: 0 none, 1 neg., 2 special - levitate, oath and possess animal are neg., castigate and remove curse are special, the other fifteen none",
    }, {
      "name" = "dhvL3Reversible",
      "values" = { 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell reversible markers by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the cell is 1 where the printed header reads Reversible - cure blindness, cure disease, dream vision, know alignment, oath, remove curse, remove paralysis; the seven matching the R658 T62 reversible column",
    }, {
      "name" = "dhvL3Sohei",
      "values" = { 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 3rd level spell sohei-usable markers by ordinal (print pp. 126-132; compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak w/ dead, 20 substitution - the cell is 1 where the printed asterisk marks the spell usable by sohei - castigate, dispel magic, flame walk, prayer; the four matching the R658 T62 sohei column",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhvL3SpellCount']() != 20  or m['dhvL3SoheiCount']() != 4  or m['dhvL3ReversibleCount']() != 7  or m['dhvL3AbjurationCount']() != 7  or m['dhvL3DivinationCount']() != 3  or m['dhvL3AlterationCount']() != 3  or m['dhvL3ConjurationCount']() != 2  or m['dhvL3NecromanticCount']() != 2  or m['dhvL3InvocationCount']() != 1  or m['dhvL3IllusionCount']() != 1  or m['dhvL3EnchCharmCount']() != 1  or m['dhvL3VSMCount']() != 14  or m['dhvL3VSCount']() != 6  or m['dhvL3TurnCasts']() != 5  or m['dhvL3ThreeTurnCasts']() != 1  or m['dhvL3RoundCasts']() != 6  or m['dhvL3SixSegmentCasts']() != 4  or m['dhvL3NegSaves']() != 3  or m['dhvL3SpecialSaves']() != 2",
      "note" = "",
    }, {
      "expr" = "m['dhvL3SpellCount']() != 20  or m['dhvL3SoheiCount']() != 4  or m['dhvL3ReversibleCount']() != 7  or m['dhvL3AbjurationCount']() != 7  or m['dhvL3InvocationCount']() != 1  or m['dhvL3IllusionCount']() != 1  or m['dhvL3ConjurationCount']() != 2  or m['dhvL3NecromanticCount']() != 2",
      "note" = "the count pins - twenty third level spells, four sohei-usable, seven reversible, seven abjuration",
    }, {
      "expr" = "m['dhvL3School'](0) != 7  or m['dhvL3School'](3) != 5  or m['dhvL3School'](5) != 7  or m['dhvL3School'](7) != 8  or m['dhvL3School'](9) != 9  or m['dhvL3School'](12) != 4  or m['dhvL3School'](14) != 1  or m['dhvL3School'](19) != 6  or m['dhvL3School'](18) != 5",
      "note" = "the school pins - castigate abjuration; death's door and speak w/ dead necromantic; dispel magic abjuration; dream vision the debuting invocation 8; flame walk, levitate and substitution alteration; invisibility to spirits the debuting illusion/phantasm 9; magical vestment the dual school primary conjuration 4; possess animal enchantment/charm",
    }, {
      "expr" = "m['dhvL3Components'](0) != 7  or m['dhvL3Components'](7) != 7  or m['dhvL3Components'](19) != 7  or m['dhvL3Components'](1) != 3  or m['dhvL3Components'](5) != 3  or m['dhvL3Components'](17) != 3  or m['dhvL3Components'](4) != 7  or m['dhvL3Components'](11) != 7",
      "note" = "the component pins - the fourteen all-component spells with castigate, dream vision and substitution pinned; the six verbal and somatic with cure blindness, dispel magic and remove paralysis pinned",
    }, {
      "expr" = "m['dhvL3CastTime'](19) != 180  or m['dhvL3CastTime'](2) != 60  or m['dhvL3CastTime'](6) != 60  or m['dhvL3CastTime'](9) != 60  or m['dhvL3CastTime'](18) != 60  or m['dhvL3CastTime'](5) != 6  or m['dhvL3CastTime'](15) != 6  or m['dhvL3CastTime'](16) != 6  or m['dhvL3CastTime'](11) != 2  or m['dhvL3CastTime'](0) != 3  or m['dhvL3CastTime'](3) != 5  or m['dhvL3CastTime'](8) != 5",
      "note" = "the casting time pins - substitution the three-turn cast (the longest in the level); the five one-turn casts (cure disease, divination, dream vision, invisibility to spirits, speak w/ dead); the six-segment casts (dispel magic, prayer, remove curse, remove paralysis); levitate the two-segment, castigate the three-segment, death's door and flame walk the five-segment casts",
    }, {
      "expr" = "m['dhvL3Save'](11) != 1  or m['dhvL3Save'](13) != 1  or m['dhvL3Save'](14) != 1  or m['dhvL3Save'](0) != 2  or m['dhvL3Save'](16) != 2  or m['dhvL3Save'](1) != 0  or m['dhvL3Save'](19) != 0  or m['dhvL3Save'](9) != 0",
      "note" = "the saving throw pins - levitate, oath and possess animal neg.; castigate and remove curse special; the fifteen others none",
    }, {
      "expr" = "m['dhvL3Reversible'](1) != 1  or m['dhvL3Reversible'](2) != 1  or m['dhvL3Reversible'](7) != 1  or m['dhvL3Reversible'](10) != 1  or m['dhvL3Reversible'](13) != 1  or m['dhvL3Reversible'](16) != 1  or m['dhvL3Reversible'](17) != 1  or m['dhvL3Reversible'](0) != 0  or m['dhvL3Reversible'](11) != 0  or m['dhvL3Reversible'](19) != 0",
      "note" = "the reversible pins - the seven marks (cure blindness, cure disease, dream vision, know alignment, oath, remove curse, remove paralysis); castigate, levitate and substitution not - the seven matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhvL3Sohei'](0) != 1  or m['dhvL3Sohei'](5) != 1  or m['dhvL3Sohei'](8) != 1  or m['dhvL3Sohei'](15) != 1  or m['dhvL3Sohei'](3) != 0  or m['dhvL3Sohei'](6) != 0  or m['dhvL3Sohei'](11) != 0",
      "note" = "the sohei pins - castigate, dispel magic, flame walk and prayer marked; death's door, divination and levitate not - the four matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhvL3VSMCount']() != 14  or m['dhvL3VSCount']() != 6  or m['dhvL3TurnCasts']() != 5  or m['dhvL3ThreeTurnCasts']() != 1  or m['dhvL3RoundCasts']() != 6  or m['dhvL3SixSegmentCasts']() != 4  or m['dhvL3NegSaves']() != 3  or m['dhvL3SpecialSaves']() != 2  or m['dhvL3DivinationCount']() != 3  or m['dhvL3AlterationCount']() != 3  or m['dhvL3EnchCharmCount']() != 1",
      "note" = "the grid-sum pins - fourteen VSM and six VS components; five one-turn and one three-turn casts; four six-segment casts; three neg. and two special saves",
    } },
  "audit" = {
      "label" = "R661 OA third level spells audit",
      "comment" = "OA round forty-eight (capture pp. 126-132): the third level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
