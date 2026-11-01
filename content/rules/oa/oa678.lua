-- oa678: promoted from rules/oawjl9spells.h (the WU JEN NINTH LEVEL SPELLS, printed capture pp. 213-216 - the OA wu jen);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 678,
  "prefix" = "oa678",
  "banner" = {
      "title" = "WU JEN NINTH LEVEL SPELLS, printed capture pp. 213-216 - the OA wu jen",
      "provenance" = "ninth level spells round, the wu jen spell book closer census 600 -> 601.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print pp. 213-216; compressed pp. 97-98); all 13 stat blocks cross-checked spell by spell between the passes, zero contested stat reads - the roster pages carrying two garbles against the stat blocks (Instant Regenerate and Power Word. III for the Instant Regeneration and Power Word, Kill the stat-block headings print in both passes, roster-only variances outside the grid), and the crystalbrittle print running the Duration and save lines together with the save reading Special in both passes. SIX nine-segment casts - astral spell, crystalbrittle, gate, imprisonment, shape change, time stop - the ninth level signature and the most common cast of the level; the opening quartet astral spell, crystalbrittle, gate and imprisonment all take verbal and somatic only. Conjuration the most common school at five spells (gate, planar call, power word kill, summon spirit, wish); alteration three, evocation three; imprisonment the lone abjuration and the one reversible spell, instant regeneration the lone necromantic; NO enchantment/charm, divination, invocation or illusion spell this level - ONE dual-school print, summon spirit the Conjuration/Summoning; Necromantic dual pinned primary conjuration 4, the exaction precedent. Wish carries BOTH the Casting Time: Special line (pinned -1, the R662 exorcise convention) and the special save; power word kill, time stop and wish the three verbal-only spells; three one-turn casts (planar call, summon spirit, tsunami); instant regeneration and internal fire the one-round casts; power word kill the lone single segment. Summon spirit the lone negation save; crystalbrittle, planar call and wish special; tsunami the lone half save. The element column cross-checks the R669 dieWJT66L9Element grid: the THREE tagged cells matching exactly - crystalbrittle Earth, internal fire Fire, tsunami Water - the cross-check column closing the wu jen spell book grid  the gap census after this round: 131 closed, 104 open - the wu jen Ninth Level Spells box flips (census 600 -> 601), the WU JEN SPELL BOOK GRID CLOSED - all nine levels pinned; NEXT - R679: the OA Chapter 9 Combat arc opens - the Summary of the Combat Sequence (capture p. 218), prefix dip (verify free - only the comment-word dips, the R669 die precedent), audit \"R679 OA combat sequence audit\"",
    },
  "consts" = { {
      "name" = "dioWJL9SpellCount",
      "value" = 13,
      "comment" = "the 13 ninth level wu jen spells (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9ConjurationCount",
      "value" = 5,
      "comment" = "the five conjuration ninth level wu jen spells - gate, planar call, power word kill, summon spirit, wish; the most common school of the level (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9DualSchoolCount",
      "value" = 1,
      "comment" = "the one dual-school ninth level wu jen print - summon spirit the Conjuration/Summoning; Necromantic dual pinned primary conjuration 4, the exaction precedent (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9NineSegmentCasts",
      "value" = 6,
      "comment" = "the six nine-segment ninth level wu jen casts - astral spell, crystalbrittle, gate, imprisonment, shape change, time stop; the ninth level signature, the most common cast of the level (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9VSCount",
      "value" = 4,
      "comment" = "the four verbal and somatic ninth level wu jen spells - the opening quartet astral spell, crystalbrittle, gate, imprisonment; the bitmask reads 3 (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9VSMCount",
      "value" = 6,
      "comment" = "the six ninth level wu jen spells taking all three components - the bitmask reads 7 (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9VerbalOnlyCount",
      "value" = 3,
      "comment" = "the three verbal-only ninth level wu jen spells - power word kill, time stop, wish (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9SpecialCasts",
      "value" = 1,
      "comment" = "the one ninth level wu jen spell with the Casting Time: Special line - wish; pinned -1, the R662 exorcise variable-cast convention (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9TurnCasts",
      "value" = 3,
      "comment" = "the three ninth level wu jen spells with a one-turn casting time - planar call, summon spirit, tsunami (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9NegSaves",
      "value" = 1,
      "comment" = "the one ninth level wu jen spell with a negation saving throw - summon spirit (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9SpecialSaves",
      "value" = 3,
      "comment" = "the three ninth level wu jen spells with a special saving throw - crystalbrittle, planar call, wish (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9HalfSaves",
      "value" = 1,
      "comment" = "the one ninth level wu jen spell with a half saving throw - tsunami (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9ReversibleCount",
      "value" = 1,
      "comment" = "the one reversible ninth level wu jen spell - imprisonment (print pp. 213-216; compressed pp. 97-98)",
    }, {
      "name" = "dioWJL9ElementCount",
      "value" = 3,
      "comment" = "the three element-tagged ninth level wu jen spells - crystalbrittle Earth, internal fire Fire, tsunami Water - matching the R669 dieWJT66L9Element grid exactly, one each of three elements (print pp. 213-216; compressed pp. 97-98)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dioWJL9School",
      "values" = { 3, 6, 4, 7, 5, 3, 4, 4, 6, 4, 6, 3, 4 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell schools by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - conjuration the most common school at five spells (gate, planar call, power word kill, summon spirit, wish); alteration three (crystalbrittle, shape change, time stop); evocation three (astral spell, internal fire, tsunami); imprisonment the lone abjuration, instant regeneration the lone necromantic; NO enchantment/charm, divination, invocation or illusion spell this level - ONE dual-school print, summon spirit the Conjuration/Summoning; Necromantic dual pinned primary conjuration 4, the exaction precedent",
    }, {
      "name" = "dioWJL9Components",
      "values" = { 3, 3, 3, 3, 7, 7, 7, 1, 7, 7, 1, 7, 1 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell components by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the component codes a bitmask: verbal 1, somatic 2, material 4 - the opening quartet astral spell, crystalbrittle, gate and imprisonment the verbal and somatic (3); six take all three (7); power word kill, time stop and wish the verbal-only three (1); NO somatic-only or V,M spell this level",
    }, {
      "name" = "dioWJL9CastTime",
      "values" = { 9, 9, 9, 9, 10, 10, 60, 1, 9, 60, 9, 60, -1 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell casting times by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the casting time in segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the Casting Time: Special line (the R662 exorcise convention): SIX nine-segment casts (astral spell, crystalbrittle, gate, imprisonment, shape change, time stop) - the ninth level signature and the most common cast of the level; three one-turn (planar call, summon spirit, tsunami); instant regeneration and internal fire the one-round casts; power word kill the lone single segment; wish the lone Special cast",
    }, {
      "name" = "dioWJL9Save",
      "values" = { 0, 2, 0, 0, 0, 0, 2, 0, 0, 1, 0, 3, 2 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell saving throws by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - summon spirit the lone negation save; crystalbrittle, planar call and wish special (the crystalbrittle print running the Duration and save lines together, the save reading Special in both passes); tsunami the lone half save; the other eight none",
    }, {
      "name" = "dioWJL9Reversible",
      "values" = { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell reversible markers by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the cell is 1 where the printed header reads Reversible - imprisonment the one",
    }, {
      "name" = "dioWJL9Element",
      "values" = { 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 0 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell element marks by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the THREE tagged spells (crystalbrittle Earth, internal fire Fire, tsunami Water) matching the R669 dieWJT66L9Element pins exactly, one each of three elements - the cross-check column closing the wu jen spell book grid",
    } },
  "tables" = { {
      "name" = "dioWJL9Grid",
      "tag" = "WJL9Data",
      "count" = "dioWJL9SpellCount",
      "col_default" = 0,
      "cols" = { "dioWJL9School", "dioWJL9Components", "dioWJL9CastTime", "dioWJL9Save", "dioWJL9Reversible", "dioWJL9Element" },
      "col_comments" = { "the wu jen 9th level spell schools by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - conjuration the most common school at five spells (gate, planar call, power word kill, summon spirit, wish); alteration three (crystalbrittle, shape change, time stop); evocation three (astral spell, internal fire, tsunami); imprisonment the lone abjuration, instant regeneration the lone necromantic; NO enchantment/charm, divination, invocation or illusion spell this level - ONE dual-school print, summon spirit the Conjuration/Summoning; Necromantic dual pinned primary conjuration 4, the exaction precedent", "the wu jen 9th level spell components by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the component codes a bitmask: verbal 1, somatic 2, material 4 - the opening quartet astral spell, crystalbrittle, gate and imprisonment the verbal and somatic (3); six take all three (7); power word kill, time stop and wish the verbal-only three (1); NO somatic-only or V,M spell this level", "the wu jen 9th level spell casting times by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the casting time in segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the Casting Time: Special line (the R662 exorcise convention): SIX nine-segment casts (astral spell, crystalbrittle, gate, imprisonment, shape change, time stop) - the ninth level signature and the most common cast of the level; three one-turn (planar call, summon spirit, tsunami); instant regeneration and internal fire the one-round casts; power word kill the lone single segment; wish the lone Special cast", "the wu jen 9th level spell saving throws by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the saving throw codes: 0 none, 1 neg., 2 special, 3 half - summon spirit the lone negation save; crystalbrittle, planar call and wish special (the crystalbrittle print running the Duration and save lines together, the save reading Special in both passes); tsunami the lone half save; the other eight none", "the wu jen 9th level spell reversible markers by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the cell is 1 where the printed header reads Reversible - imprisonment the one", "the wu jen 9th level spell element marks by ordinal (print pp. 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the THREE tagged spells (crystalbrittle Earth, internal fire Fire, tsunami Water) matching the R669 dieWJT66L9Element pins exactly, one each of three elements - the cross-check column closing the wu jen spell book grid" },
      "data" = { { 3, 3, 9, 0, 0, 0 }, { 6, 3, 9, 2, 0, 2 }, { 4, 3, 9, 0, 0, 0 }, { 7, 3, 9, 0, 1, 0 }, { 5, 7, 10, 0, 0, 0 }, { 3, 7, 10, 0, 0, 3 }, { 4, 7, 60, 2, 0, 0 }, { 4, 1, 1, 0, 0, 0 }, { 6, 7, 9, 0, 0, 0 }, { 4, 7, 60, 1, 0, 0 }, { 6, 1, 9, 0, 0, 0 }, { 3, 7, 60, 3, 0, 4 }, { 4, 1, -1, 2, 0, 0 } },
      "comment" = "the wu jen 9th level spell stat grid (print pp. 213-216; compressed pp. 97-98). The spell list rides the column comments: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - 13 rows the spell ordinals, six columns: school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, -1 the special cast), saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and element markers; the element cells cross-check the R669 T66 grid (crystalbrittle Earth, internal fire Fire, tsunami Water the three tagged cells). The table tag WJL9Data identifier-safe per the R639 lesson",
      "audit_comment" = "the stat grid - one cell per spell and column, every grid cell pinned from the stat blocks cross-checked between the passes",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dioWJL9SpellCount']() != 13  or m['dioWJL9ConjurationCount']() != 5  or m['dioWJL9DualSchoolCount']() != 1  or m['dioWJL9NineSegmentCasts']() != 6  or m['dioWJL9VSCount']() != 4  or m['dioWJL9VSMCount']() != 6  or m['dioWJL9VerbalOnlyCount']() != 3  or m['dioWJL9SpecialCasts']() != 1  or m['dioWJL9TurnCasts']() != 3  or m['dioWJL9NegSaves']() != 1  or m['dioWJL9SpecialSaves']() != 3  or m['dioWJL9HalfSaves']() != 1  or m['dioWJL9ReversibleCount']() != 1  or m['dioWJL9ElementCount']() != 3",
      "note" = "",
    }, {
      "expr" = "m['dioWJL9SpellCount']() != 13  or m['dioWJL9ConjurationCount']() != 5  or m['dioWJL9DualSchoolCount']() != 1  or m['dioWJL9ReversibleCount']() != 1  or m['dioWJL9ElementCount']() != 3",
      "note" = "the count pins - 13 spells, five conjuration, one dual-school print, one reversible, three element-tagged",
    }, {
      "expr" = "m['dioWJL9NineSegmentCasts']() != 6  or m['dioWJL9TurnCasts']() != 3  or m['dioWJL9SpecialCasts']() != 1",
      "note" = "the casting time pins - SIX nine-segment casts (the ninth level signature), three one-turn, wish the lone Special cast",
    }, {
      "expr" = "m['dioWJL9VSCount']() != 4  or m['dioWJL9VSMCount']() != 6  or m['dioWJL9VerbalOnlyCount']() != 3",
      "note" = "the component pins - the opening V,S quartet, six VSM, three verbal-only, no somatic-only or V,M spell",
    }, {
      "expr" = "m['dioWJL9NegSaves']() != 1  or m['dioWJL9SpecialSaves']() != 3  or m['dioWJL9HalfSaves']() != 1",
      "note" = "the saving throw pins - summon spirit the lone neg., three special, tsunami the lone half save",
    }, {
      "expr" = "m['dioWJL9School'](0) != 3  or m['dioWJL9School'](1) != 6  or m['dioWJL9School'](2) != 4  or m['dioWJL9School'](3) != 7  or m['dioWJL9School'](4) != 5  or m['dioWJL9School'](5) != 3  or m['dioWJL9School'](6) != 4  or m['dioWJL9School'](7) != 4  or m['dioWJL9School'](8) != 6  or m['dioWJL9School'](9) != 4  or m['dioWJL9School'](10) != 6  or m['dioWJL9School'](11) != 3  or m['dioWJL9School'](12) != 4",
      "note" = "the school column - the five conjurations, the three alterations, the three evocations, imprisonment the lone abjuration, instant regeneration the lone necromantic, summon spirit the dual pinned 4",
    }, {
      "expr" = "m['dioWJL9Components'](0) != 3  or m['dioWJL9Components'](1) != 3  or m['dioWJL9Components'](2) != 3  or m['dioWJL9Components'](3) != 3  or m['dioWJL9Components'](4) != 7  or m['dioWJL9Components'](5) != 7  or m['dioWJL9Components'](6) != 7  or m['dioWJL9Components'](7) != 1  or m['dioWJL9Components'](8) != 7  or m['dioWJL9Components'](9) != 7  or m['dioWJL9Components'](10) != 1  or m['dioWJL9Components'](11) != 7  or m['dioWJL9Components'](12) != 1",
      "note" = "the component column - the opening V,S quartet, the six VSM spells, the three verbal-only",
    }, {
      "expr" = "m['dioWJL9CastTime'](0) != 9  or m['dioWJL9CastTime'](1) != 9  or m['dioWJL9CastTime'](2) != 9  or m['dioWJL9CastTime'](3) != 9  or m['dioWJL9CastTime'](4) != 10  or m['dioWJL9CastTime'](5) != 10  or m['dioWJL9CastTime'](6) != 60  or m['dioWJL9CastTime'](7) != 1  or m['dioWJL9CastTime'](8) != 9  or m['dioWJL9CastTime'](9) != 60  or m['dioWJL9CastTime'](10) != 9  or m['dioWJL9CastTime'](11) != 60  or m['dioWJL9CastTime'](12) != -1",
      "note" = "the casting time column - the six nine-segment casts, the three one-turn, the one-round pair, power word kill the single segment, wish -1",
    }, {
      "expr" = "m['dioWJL9Save'](0) != 0  or m['dioWJL9Save'](1) != 2  or m['dioWJL9Save'](2) != 0  or m['dioWJL9Save'](3) != 0  or m['dioWJL9Save'](4) != 0  or m['dioWJL9Save'](5) != 0  or m['dioWJL9Save'](6) != 2  or m['dioWJL9Save'](7) != 0  or m['dioWJL9Save'](8) != 0  or m['dioWJL9Save'](9) != 1  or m['dioWJL9Save'](10) != 0  or m['dioWJL9Save'](11) != 3  or m['dioWJL9Save'](12) != 2",
      "note" = "the saving throw column - crystalbrittle, planar call and wish special, summon spirit neg., tsunami the lone half, the other eight none",
    }, {
      "expr" = "m['dioWJL9Reversible'](3) != 1  or m['dioWJL9Reversible'](0) != 0  or m['dioWJL9Reversible'](2) != 0  or m['dioWJL9Reversible'](8) != 0  or m['dioWJL9Reversible'](12) != 0",
      "note" = "the reversible column - imprisonment the one reversible spell of the level",
    }, {
      "expr" = "m['dioWJL9Element'](1) != 2  or m['dioWJL9Element'](5) != 3  or m['dioWJL9Element'](11) != 4  or m['dioWJL9Element'](0) != 0  or m['dioWJL9Element'](4) != 0  or m['dioWJL9Element'](9) != 0  or m['dioWJL9Element'](12) != 0",
      "note" = "the element column - the three tagged cells matching the R669 dieWJT66L9Element grid exactly: crystalbrittle Earth, internal fire Fire, tsunami Water",
    }, {
      "expr" = "m['dioWJL9CastTime'](12) != -1  or m['dioWJL9Save'](12) != 2  or m['dioWJL9Components'](12) != 1  or m['dioWJL9School'](12) != 4",
      "note" = "the wish line - the lone Special cast pinned -1 AND the special save, verbal-only, conjuration school",
    } },
  "audit" = {
      "label" = "R678 OA wu jen ninth level spells audit",
      "comment" = "OA round sixty-five (capture pp. 213-216): the wu jen ninth level spell stat blocks - the school, component, casting time and saving throw codes with the reversible and element markers, cross-checked spell by spell between the passes - the round closing the wu jen spell book grid",
    },
}
