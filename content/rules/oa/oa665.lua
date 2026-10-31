-- oa665: promoted from rules/oal7spells.h (the SEVENTH LEVEL SPELLS, printed capture pp. 147-152 - the OA seventh level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 665,
  "prefix" = "oa665",
  "banner" = {
      "title" = "SEVENTH LEVEL SPELLS, printed capture pp. 147-152 - the OA seventh level",
      "provenance" = "spells round census 587 -> 588.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read - the 12 seventh level spell stat blocks cross-checked spell by spell between the passes (print pp. 147-152; compressed pp. 71-73); all 12 schools, component sets, casting times and saving throws agree, zero contested stat reads. The level closes the shukenja spell list: astral spell takes the three-turn cast (180 segments, the longest of the level), three spells a turn (divine wind, reincarnate, resurrection), five a round, quest eight segments, gate five, and holy (unholy) word casts in a single segment. Two spells take the negation save (compel, quest) and two the special (exaction, restore spirit - the system shock roll); no half saves this level. Conjuration/summoning and necromantic tie as the most common school at three spells each; exaction dual Evocation/Alteration pinned primary evocation per the dual-school convention (the abjure and aid precedent); no divination or illusion this level. Resurrection alone reads Reversible (the destruction reverse) - the single reversible mark matching the R658 T62 grid; holy (unholy) word carries no reversible marker in either pass despite its parenthetical name, and ancient curse alone is sohei-usable - the T62 grid settles both. One prose divergence noted outside the stat grid: compel's save penalty for the greater-than-150% bracket reads +4 in the print against -4 in the compressed - the print settles. The stat grid pins as a table: 12 rows the spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, 3 turns = 180), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and sohei markers. The spell names ride the column comments, the prose descriptions close in their own rounds. The table tag L7Data identifier-safe per the R639 lesson  the gap census after this round: 118 closed, 117 open - the Seventh Level Spells box flips (census 587 -> 588); the shukenja spell chapter rounds are COMPLETE - NEXT - R666: the Table 63 Divination Results (capture p. 117, rides its own box), prefix to verify free, audit \"R666 OA divination results audit\"",
    },
  "consts" = { {
      "name" = "dhzL7SpellCount",
      "value" = 12,
      "comment" = "the 12 seventh level shukenja spells (print pp. 147-152; compressed pp. 71-73)",
    }, {
      "name" = "dhzL7SoheiCount",
      "value" = 1,
      "comment" = "the one seventh level spell usable by sohei - ancient curse",
    }, {
      "name" = "dhzL7ReversibleCount",
      "value" = 1,
      "comment" = "the one reversible seventh level spell - resurrection (the destruction reverse)",
    }, {
      "name" = "dhzL7ConjurationCount",
      "value" = 3,
      "comment" = "the three conjuration/summoning seventh level spells - the joint most common school: divine wind, gate, holy (unholy) word",
    }, {
      "name" = "dhzL7NecromanticCount",
      "value" = 3,
      "comment" = "the three necromantic seventh level spells - the joint most common school: reincarnate, restore spirit, resurrection",
    }, {
      "name" = "dhzL7VSMCount",
      "value" = 8,
      "comment" = "the eight seventh level spells taking all three components - the bitmask reads 7",
    }, {
      "name" = "dhzL7VSCount",
      "value" = 2,
      "comment" = "the two seventh level spells taking verbal and somatic - astral spell, gate; the bitmask reads 3",
    }, {
      "name" = "dhzL7VerbalOnlyCount",
      "value" = 2,
      "comment" = "the two seventh level spells taking the verbal component only - ancient curse, holy (unholy) word",
    }, {
      "name" = "dhzL7RoundCasts",
      "value" = 5,
      "comment" = "the five seventh level spells with a one-round casting time - ancient curse, compel, exaction, restore spirit, wind walk",
    }, {
      "name" = "dhzL7TurnCasts",
      "value" = 3,
      "comment" = "the three seventh level spells with a one-turn casting time - divine wind, reincarnate, resurrection",
    }, {
      "name" = "dhzL7ThreeTurnCasts",
      "value" = 1,
      "comment" = "the one seventh level spell with a three-turn casting time - astral spell, the longest cast of the level at 180 segments",
    }, {
      "name" = "dhzL7OneSegmentCasts",
      "value" = 1,
      "comment" = "the one seventh level spell with a one-segment casting time - holy (unholy) word",
    }, {
      "name" = "dhzL7FiveSegmentCasts",
      "value" = 1,
      "comment" = "the one seventh level spell with a five-segment casting time - gate",
    }, {
      "name" = "dhzL7EightSegmentCasts",
      "value" = 1,
      "comment" = "the one seventh level spell with an eight-segment casting time - quest",
    }, {
      "name" = "dhzL7NegSaves",
      "value" = 2,
      "comment" = "the two seventh level spells with a negation saving throw - compel, quest",
    }, {
      "name" = "dhzL7SpecialSaves",
      "value" = 2,
      "comment" = "the two seventh level spells with a special saving throw - exaction, restore spirit (the system shock roll)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhzL7School",
      "values" = { 7, 6, 7, 4, 3, 4, 4, 1, 5, 5, 5, 6 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell schools by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7 abjuration, 9 illusion/phantasm - conjuration/summoning and necromantic tie as the most common school at three spells each (divine wind, gate, holy (unholy) word; reincarnate, restore spirit, resurrection); abjuration and alteration take two each (ancient curse, compel; astral spell, wind walk); quest the one enchantment/charm and exaction the one evocation - exaction dual Evocation/Alteration pinned primary per the dual-school convention; no divination or illusion spell this level",
    }, {
      "name" = "dhzL7Components",
      "values" = { 1, 3, 7, 7, 7, 3, 1, 7, 7, 7, 7, 7 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell components by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the component codes a bitmask: verbal 1, somatic 2, material 4 - eight spells take all three (7), two take verbal and somatic (3): astral spell, gate; ancient curse and holy (unholy) word take the verbal only (1)",
    }, {
      "name" = "dhzL7CastTime",
      "values" = { 10, 180, 10, 60, 10, 5, 1, 8, 60, 10, 60, 10 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell casting times by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the casting time in segments - 1 round = 10 segments, 1 turn = 60, 3 turns = 180: astral spell takes three turns, three spells a turn (divine wind, reincarnate, resurrection), five a round (ancient curse, compel, exaction, restore spirit, wind walk), quest eight segments, gate five, and holy (unholy) word casts in a single segment",
    }, {
      "name" = "dhzL7Save",
      "values" = { 0, 0, 1, 0, 2, 0, 0, 1, 0, 2, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell saving throws by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - compel and quest are neg., exaction and restore spirit are special, the other eight none; no half saves this level",
    }, {
      "name" = "dhzL7Reversible",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell reversible markers by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the cell is 1 where the printed header reads Reversible - resurrection alone (the destruction reverse); the one matching the R658 T62 reversible column - holy (unholy) word carries no reversible marker in either pass",
    }, {
      "name" = "dhzL7Sohei",
      "values" = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the shukenja 7th level spell sohei-usable markers by ordinal (print pp. 147-152; compressed pp. 71-73). The spell list rides this comment: 1 ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection, 12 wind walk - the cell is 1 where the printed asterisk marks the spell usable by sohei - ancient curse alone; the one matching the R658 T62 sohei column",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhzL7SpellCount']() != 12  or m['dhzL7SoheiCount']() != 1  or m['dhzL7ReversibleCount']() != 1  or m['dhzL7ConjurationCount']() != 3  or m['dhzL7NecromanticCount']() != 3  or m['dhzL7VSMCount']() != 8  or m['dhzL7VSCount']() != 2  or m['dhzL7VerbalOnlyCount']() != 2  or m['dhzL7RoundCasts']() != 5  or m['dhzL7TurnCasts']() != 3  or m['dhzL7ThreeTurnCasts']() != 1  or m['dhzL7OneSegmentCasts']() != 1  or m['dhzL7FiveSegmentCasts']() != 1  or m['dhzL7EightSegmentCasts']() != 1  or m['dhzL7NegSaves']() != 2  or m['dhzL7SpecialSaves']() != 2",
      "note" = "",
    }, {
      "expr" = "m['dhzL7SpellCount']() != 12  or m['dhzL7SoheiCount']() != 1  or m['dhzL7ReversibleCount']() != 1  or m['dhzL7ConjurationCount']() != 3  or m['dhzL7NecromanticCount']() != 3  or m['dhzL7VSMCount']() != 8  or m['dhzL7VSCount']() != 2  or m['dhzL7VerbalOnlyCount']() != 2",
      "note" = "the count pins - twelve seventh level spells, one sohei-usable, one reversible, three conjuration and three necromantic",
    }, {
      "expr" = "m['dhzL7School'](0) != 7  or m['dhzL7School'](2) != 7  or m['dhzL7School'](1) != 6  or m['dhzL7School'](11) != 6  or m['dhzL7School'](3) != 4  or m['dhzL7School'](5) != 4  or m['dhzL7School'](6) != 4  or m['dhzL7School'](7) != 1  or m['dhzL7School'](4) != 3  or m['dhzL7School'](8) != 5  or m['dhzL7School'](9) != 5  or m['dhzL7School'](10) != 5",
      "note" = "the school pins - ancient curse and compel abjuration; astral spell and wind walk alteration; divine wind, gate and holy (unholy) word conjuration; quest enchantment/charm; exaction evocation (the dual Evocation/Alteration pinned primary); reincarnate, restore spirit and resurrection necromantic",
    }, {
      "expr" = "m['dhzL7Components'](0) != 1  or m['dhzL7Components'](6) != 1  or m['dhzL7Components'](1) != 3  or m['dhzL7Components'](5) != 3  or m['dhzL7Components'](2) != 7  or m['dhzL7Components'](3) != 7  or m['dhzL7Components'](4) != 7  or m['dhzL7Components'](7) != 7  or m['dhzL7Components'](8) != 7  or m['dhzL7Components'](9) != 7  or m['dhzL7Components'](10) != 7  or m['dhzL7Components'](11) != 7",
      "note" = "the component pins - ancient curse and holy (unholy) word the verbal-only pair; astral spell and gate the verbal and somatic; the eight all-component with compel, divine wind, exaction, quest, reincarnate, restore spirit, resurrection and wind walk pinned",
    }, {
      "expr" = "m['dhzL7CastTime'](1) != 180  or m['dhzL7CastTime'](3) != 60  or m['dhzL7CastTime'](8) != 60  or m['dhzL7CastTime'](10) != 60  or m['dhzL7CastTime'](0) != 10  or m['dhzL7CastTime'](2) != 10  or m['dhzL7CastTime'](4) != 10  or m['dhzL7CastTime'](9) != 10  or m['dhzL7CastTime'](11) != 10  or m['dhzL7CastTime'](7) != 8  or m['dhzL7CastTime'](5) != 5  or m['dhzL7CastTime'](6) != 1",
      "note" = "the casting time pins - astral spell the three-turn cast 180 (the longest of the level); the three one-turn casts; the five one-round casts; quest eight segments; gate five; holy (unholy) word the single segment",
    }, {
      "expr" = "m['dhzL7Save'](2) != 1  or m['dhzL7Save'](7) != 1  or m['dhzL7Save'](4) != 2  or m['dhzL7Save'](9) != 2  or m['dhzL7Save'](0) != 0  or m['dhzL7Save'](1) != 0  or m['dhzL7Save'](3) != 0  or m['dhzL7Save'](5) != 0  or m['dhzL7Save'](6) != 0  or m['dhzL7Save'](8) != 0  or m['dhzL7Save'](10) != 0  or m['dhzL7Save'](11) != 0",
      "note" = "the saving throw pins - compel and quest neg.; exaction and restore spirit special; the other eight none; no half saves this level",
    }, {
      "expr" = "m['dhzL7Reversible'](10) != 1  or m['dhzL7Reversible'](0) != 0  or m['dhzL7Reversible'](1) != 0  or m['dhzL7Reversible'](6) != 0  or m['dhzL7Reversible'](11) != 0",
      "note" = "the reversible pins - resurrection marked (the destruction reverse); ancient curse, astral spell, holy (unholy) word and wind walk not - the one matching the R658 T62 reversible column",
    }, {
      "expr" = "m['dhzL7Sohei'](0) != 1  or m['dhzL7Sohei'](6) != 0  or m['dhzL7Sohei'](10) != 0  or m['dhzL7Sohei'](3) != 0",
      "note" = "the sohei pins - ancient curse marked; holy (unholy) word, compel and resurrection not - the one matching the R658 T62 sohei column",
    }, {
      "expr" = "m['dhzL7RoundCasts']() != 5  or m['dhzL7TurnCasts']() != 3  or m['dhzL7ThreeTurnCasts']() != 1  or m['dhzL7OneSegmentCasts']() != 1  or m['dhzL7FiveSegmentCasts']() != 1  or m['dhzL7EightSegmentCasts']() != 1  or m['dhzL7NegSaves']() != 2  or m['dhzL7SpecialSaves']() != 2",
      "note" = "the grid-sum pins - five one-round, three one-turn and one three-turn casts; the one-segment, five-segment and eight-segment singles; two neg. and two special saves",
    } },
  "audit" = {
      "label" = "R665 OA seventh level spells audit",
      "comment" = "OA round fifty-two (capture pp. 147-152): the seventh level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and sohei-usable markers, cross-checked spell by spell between the passes",
    },
}
