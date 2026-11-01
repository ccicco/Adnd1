-- oa676: promoted from rules/oawjl7spells.h (the WU JEN SEVENTH LEVEL SPELLS, printed capture pp. 203-207 - the OA wu jen);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 676,
  "prefix" = "oa676",
  "banner" = {
      "title" = "WU JEN SEVENTH LEVEL SPELLS, printed capture pp. 203-207 - the OA wu jen",
      "provenance" = "seventh level spells round census 598 -> 599.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print pp. 203-207; compressed pp. 93-95); all 12 stat blocks cross-checked spell by spell between the passes, zero contested stat reads - the print Components apostrophe-s V typo on the vanish block reading V in both passes, and body outside body the OA printing its near-duplicate of the sixth level vessel at the seventh (the same duplicate-creating spell at both levels). The level carries THREE dual-school prints again, all pinned primary (the exaction precedent): elemental servant the Conjuration/Summoning; Enchantment/Charm dual pinned 4, ice blight the Evocation/Summoning dual pinned 3, obedience the Enchantment/Evocation dual pinned 1. Conjuration the most common school at five spells; alteration and evocation two each; commune with greater spirit the lone divination, reanimation the lone necromantic, obedience the lone enchantment/charm; NO illusion, invocation or abjuration spell this level. The component census: seven VSM, FOUR verbal-only spells (limited wish, power word stun, tool, vanish) - the most verbal-only of any wu jen level yet - and withering palm the lone verbal and somatic; no V,M spell this level. Limited wish carries BOTH the Casting Time: Special line (pinned -1, the R662 exorcise convention) and the special save; three one-turn casts (commune with greater spirit, elemental servant, ice blight), three single segments (body outside body, power word stun, tool), obedience and reanimation the one-round casts, duo-dimension seven, vanish two, withering palm four segments. Two negation saves (elemental servant, obedience), two special (limited wish, reanimation), withering palm the lone half save. One reversible spell (ice blight, drought). The element column cross-checks the R669 dieWJT66L7Element grid: the ONE tagged cell (ice blight Water) matching the landed pin exactly  the gap census after this round: 129 closed, 106 open - the wu jen Seventh Level Spells box flips (census 598 -> 599); NEXT - R677: the wu jen Eighth Level Spells (capture pp. 207-213, the 14 stat blocks), prefix dim (verify free - only the comment-words dim, dims, diminish, the R669 die precedent), audit \"R677 OA wu jen eighth level spells audit\"",
    },
  "consts" = { {
      "name" = "dilWJL7SpellCount",
      "value" = 12,
      "comment" = "the 12 seventh level wu jen spells (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7ConjurationCount",
      "value" = 5,
      "comment" = "the five conjuration seventh level wu jen spells - body outside body, elemental servant, limited wish, power word stun, tool; the most common school of the level (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7DualSchoolCount",
      "value" = 3,
      "comment" = "the three dual-school seventh level wu jen prints, all pinned primary (the exaction precedent) - elemental servant the Conjuration/Summoning; Enchantment/Charm dual pinned 4, ice blight the Evocation/Summoning dual pinned 3, obedience the Enchantment/Evocation dual pinned 1 (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7ReversibleCount",
      "value" = 1,
      "comment" = "the one reversible seventh level wu jen spell - ice blight (drought) (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7VSMCount",
      "value" = 7,
      "comment" = "the seven seventh level wu jen spells taking all three components - the bitmask reads 7 (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7VerbalOnlyCount",
      "value" = 4,
      "comment" = "the four seventh level wu jen spells taking the verbal component only - limited wish, power word stun, tool, vanish; the most verbal-only spells of any wu jen level yet (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7SpecialCasts",
      "value" = 1,
      "comment" = "the one seventh level wu jen spell with the Casting Time: Special line - limited wish; pinned -1, the R662 exorcise variable-cast convention (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7TurnCasts",
      "value" = 3,
      "comment" = "the three seventh level wu jen spells with a one-turn casting time - commune with greater spirit, elemental servant, ice blight (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7OneSegmentCasts",
      "value" = 3,
      "comment" = "the three seventh level wu jen spells with a one-segment casting time - body outside body, power word stun, tool (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7NegSaves",
      "value" = 2,
      "comment" = "the two seventh level wu jen spells with a negation saving throw - elemental servant, obedience (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7SpecialSaves",
      "value" = 2,
      "comment" = "the two seventh level wu jen spells with a special saving throw - limited wish, reanimation (print pp. 203-207; compressed pp. 93-95)",
    }, {
      "name" = "dilWJL7ElementCount",
      "value" = 1,
      "comment" = "the one element-tagged seventh level wu jen spell - ice blight Water - matching the R669 dieWJT66L7Element grid exactly (print pp. 203-207; compressed pp. 93-95)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dilWJL7School",
      "values" = { 4, 2, 6, 4, 3, 4, 1, 4, 5, 4, 6, 3 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell schools by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - conjuration the most common school at five spells (body outside body, elemental servant, limited wish, power word stun, tool); alteration two (duo-dimension, vanish); evocation two (ice blight, withering palm); commune with greater spirit the lone divination, reanimation the lone necromantic, obedience the lone enchantment/charm; NO illusion, invocation or abjuration spell this level - THREE dual-school prints, all pinned primary (the exaction precedent): elemental servant the Conjuration/Summoning; Enchantment/Charm dual pinned 4, ice blight the Evocation/Summoning dual pinned 3, obedience the Enchantment/Evocation dual pinned 1",
    }, {
      "name" = "dilWJL7Components",
      "values" = { 7, 7, 7, 7, 7, 1, 7, 1, 7, 1, 1, 3 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell components by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the component codes a bitmask: verbal 1, somatic 2, material 4 - seven spells take all three (7); FOUR verbal-only spells (1): limited wish, power word stun, tool, vanish - the most verbal-only of any wu jen level yet; withering palm the lone verbal and somatic (3); no V,M spell this level",
    }, {
      "name" = "dilWJL7CastTime",
      "values" = { 1, 60, 7, 60, 60, -1, 10, 1, 10, 1, 2, 4 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell casting times by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the casting time in segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the Casting Time: Special line (the R662 exorcise convention): limited wish the lone Special cast; three one-turn (commune with greater spirit, elemental servant, ice blight); three single segments (body outside body, power word stun, tool); obedience and reanimation the one-round casts; duo-dimension seven, vanish two, withering palm four segments",
    }, {
      "name" = "dilWJL7Save",
      "values" = { 0, 0, 0, 1, 0, 2, 1, 0, 2, 0, 0, 3 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell saving throws by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - elemental servant and obedience neg.; limited wish and reanimation special; withering palm the lone HALF save of the level; the other seven none",
    }, {
      "name" = "dilWJL7Reversible",
      "values" = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell reversible markers by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the cell is 1 where the printed header reads Reversible - ice blight (drought) the one",
    }, {
      "name" = "dilWJL7Element",
      "values" = { 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell element marks by ordinal (print pp. 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the ONE tagged spell (ice blight Water) matching the R669 dieWJT66L7Element pin exactly - the cross-check column",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dilWJL7SpellCount']() != 12  or m['dilWJL7ConjurationCount']() != 5  or m['dilWJL7DualSchoolCount']() != 3  or m['dilWJL7ReversibleCount']() != 1  or m['dilWJL7VSMCount']() != 7  or m['dilWJL7VerbalOnlyCount']() != 4  or m['dilWJL7SpecialCasts']() != 1  or m['dilWJL7TurnCasts']() != 3  or m['dilWJL7OneSegmentCasts']() != 3  or m['dilWJL7NegSaves']() != 2  or m['dilWJL7SpecialSaves']() != 2  or m['dilWJL7ElementCount']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dilWJL7SpellCount']() != 12  or m['dilWJL7ConjurationCount']() != 5  or m['dilWJL7DualSchoolCount']() != 3  or m['dilWJL7ReversibleCount']() != 1  or m['dilWJL7ElementCount']() != 1",
      "note" = "the count pins - 12 spells, five conjuration, three dual-school prints, one reversible, one element-tagged",
    }, {
      "expr" = "m['dilWJL7VSMCount']() != 7  or m['dilWJL7VerbalOnlyCount']() != 4",
      "note" = "the component pins - seven VSM, FOUR verbal-only spells (the most of any wu jen level yet)",
    }, {
      "expr" = "m['dilWJL7SpecialCasts']() != 1  or m['dilWJL7TurnCasts']() != 3  or m['dilWJL7OneSegmentCasts']() != 3",
      "note" = "the casting time pins - limited wish the lone Special cast (-1), three one-turn, three single segments",
    }, {
      "expr" = "m['dilWJL7NegSaves']() != 2  or m['dilWJL7SpecialSaves']() != 2",
      "note" = "the saving throw pins - two neg., two special, withering palm the lone half save",
    }, {
      "expr" = "m['dilWJL7School'](0) != 4  or m['dilWJL7School'](1) != 2  or m['dilWJL7School'](2) != 6  or m['dilWJL7School'](3) != 4  or m['dilWJL7School'](4) != 3  or m['dilWJL7School'](5) != 4  or m['dilWJL7School'](6) != 1  or m['dilWJL7School'](7) != 4  or m['dilWJL7School'](8) != 5  or m['dilWJL7School'](9) != 4  or m['dilWJL7School'](10) != 6  or m['dilWJL7School'](11) != 3",
      "note" = "the school column - the three duals pinned primary: elemental servant 4, ice blight 3, obedience 1; conjuration five; commune with greater spirit the lone divination, reanimation the lone necromantic",
    }, {
      "expr" = "m['dilWJL7Components'](0) != 7  or m['dilWJL7Components'](1) != 7  or m['dilWJL7Components'](2) != 7  or m['dilWJL7Components'](3) != 7  or m['dilWJL7Components'](4) != 7  or m['dilWJL7Components'](5) != 1  or m['dilWJL7Components'](6) != 7  or m['dilWJL7Components'](7) != 1  or m['dilWJL7Components'](8) != 7  or m['dilWJL7Components'](9) != 1  or m['dilWJL7Components'](10) != 1  or m['dilWJL7Components'](11) != 3",
      "note" = "the component column - the four verbal-only spells (limited wish, power word stun, tool, vanish), withering palm the lone V,S, the other seven VSM",
    }, {
      "expr" = "m['dilWJL7CastTime'](0) != 1  or m['dilWJL7CastTime'](1) != 60  or m['dilWJL7CastTime'](2) != 7  or m['dilWJL7CastTime'](3) != 60  or m['dilWJL7CastTime'](4) != 60  or m['dilWJL7CastTime'](5) != -1  or m['dilWJL7CastTime'](6) != 10  or m['dilWJL7CastTime'](7) != 1  or m['dilWJL7CastTime'](8) != 10  or m['dilWJL7CastTime'](9) != 1  or m['dilWJL7CastTime'](10) != 2  or m['dilWJL7CastTime'](11) != 4",
      "note" = "the casting time column - limited wish the lone Special (-1), the three one-turn casts, the three single segments, obedience and reanimation the one-round casts, duo-dimension seven, vanish two, withering palm four segments",
    }, {
      "expr" = "m['dilWJL7Save'](0) != 0  or m['dilWJL7Save'](1) != 0  or m['dilWJL7Save'](2) != 0  or m['dilWJL7Save'](3) != 1  or m['dilWJL7Save'](4) != 0  or m['dilWJL7Save'](5) != 2  or m['dilWJL7Save'](6) != 1  or m['dilWJL7Save'](7) != 0  or m['dilWJL7Save'](8) != 2  or m['dilWJL7Save'](9) != 0  or m['dilWJL7Save'](10) != 0  or m['dilWJL7Save'](11) != 3",
      "note" = "the saving throw column - elemental servant and obedience neg., limited wish and reanimation special, withering palm the lone half save, the other seven none",
    }, {
      "expr" = "m['dilWJL7Reversible'](4) != 1  or m['dilWJL7Reversible'](0) != 0  or m['dilWJL7Reversible'](3) != 0  or m['dilWJL7Reversible'](5) != 0  or m['dilWJL7Reversible'](11) != 0",
      "note" = "the reversible column - ice blight (drought) the one reversible spell of the level",
    }, {
      "expr" = "m['dilWJL7Element'](4) != 4  or m['dilWJL7Element'](0) != 0  or m['dilWJL7Element'](3) != 0  or m['dilWJL7Element'](5) != 0  or m['dilWJL7Element'](11) != 0",
      "note" = "the element column - ice blight Water the one tagged cell, matching the R669 dieWJT66L7Element pin exactly",
    }, {
      "expr" = "m['dilWJL7CastTime'](5) != -1  or m['dilWJL7Save'](5) != 2  or m['dilWJL7Components'](5) != 1  or m['dilWJL7School'](5) != 4",
      "note" = "the limited wish line - the lone Special cast pinned -1 AND the special save, verbal-only, conjuration school",
    } },
  "audit" = {
      "label" = "R676 OA wu jen seventh level spells audit",
      "comment" = "OA round sixty-three (capture pp. 203-207): the wu jen seventh level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and element markers, cross-checked spell by spell between the passes",
    },
}
