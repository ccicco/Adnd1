-- oa669: promoted from rules/oa/oawjspelllist.h (the TABLE 66 WU JEN SPELLS, printed capture pp. 153-155 - the OA wu jen spell);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 669,
  "prefix" = "oa669",
  "banner" = {
      "title" = "TABLE 66 WU JEN SPELLS, printed capture pp. 153-155 - the OA wu jen spell",
      "provenance" = "list round census 591 -> 592.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read (print pp. 153-155; compressed pp. 74-75); all nine level columns cross-checked name by name between the passes. The roster: 30 first and second level spells, 24 each at the third through sixth, 12 seventh, 14 eighth and 13 ninth - 195 spells total, the ordinal max 30. One contested name: the sixth level Glassee reads Glasses in the print OCR against Glassee in the compressed - the compressed settles the known PHB spell name. The other OCR variances are typographic (the compressed Haute for Haste, Ventiloquism for Ventriloquism, the print's stray r on Duo-Dimension and the Power Word period artifacts). The distinctive wu jen structure pins as a 30 x 9 element grid, the R658 T62 pattern with elemental marks in place of the sohei and reversible columns: the codes 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the cloudburst Water/Air dual and 9 the water to poison Nature/Water dual - the -99 sentinel padding the ordinals beyond each level's count. Earth is the most common element at 16 spells, Air 13, Fire 11, Water 10, Nature 7, the lone Wood mark (warp wood), four All marks (elemental burst, scry, elemental turning, conjure elemental) and the two duals - 64 tagged spells against 131 untagged. The spell names ride the column comments with the per-level tagged lists, the spell descriptions close in their own rounds. The memorization doctrine pins as the two consts: the six hours of restful meditation and the 3d6 starting-spell roll. The table tag WJT66Data identifier-safe per the R639 lesson  the gap census after this round: 122 closed, 113 open - the Table 66 Wu Jen Spells box flips (census 591 -> 592); NEXT - R670: the wu jen First Level Spells (capture pp. 155-165, the 30 stat blocks), prefix dif (verify free), audit \"R670 OA wu jen first level spells audit\"",
    },
  "consts" = { {
      "name" = "dieWJT66LevelCount",
      "value" = 9,
      "comment" = "the nine wu jen spell levels (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66SpellTotal",
      "value" = 195,
      "comment" = "the 195 wu jen spells across the nine levels (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66OrdinalMax",
      "value" = 30,
      "comment" = "the greatest per-level spell count - 30, the first and second levels (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L1Spells",
      "value" = 30,
      "comment" = "the 30 first level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L2Spells",
      "value" = 30,
      "comment" = "the 30 second level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L3Spells",
      "value" = 24,
      "comment" = "the 24 third level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L4Spells",
      "value" = 24,
      "comment" = "the 24 fourth level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L5Spells",
      "value" = 24,
      "comment" = "the 24 fifth level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L6Spells",
      "value" = 24,
      "comment" = "the 24 sixth level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L7Spells",
      "value" = 12,
      "comment" = "the 12 seventh level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L8Spells",
      "value" = 14,
      "comment" = "the 14 eighth level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66L9Spells",
      "value" = 13,
      "comment" = "the 13 ninth level wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66AirCount",
      "value" = 13,
      "comment" = "the 13 Air-marked wu jen spells - the joint second most common element (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66EarthCount",
      "value" = 16,
      "comment" = "the 16 Earth-marked wu jen spells - the most common element (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66FireCount",
      "value" = 11,
      "comment" = "the 11 Fire-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66WaterCount",
      "value" = 10,
      "comment" = "the 10 Water-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66NatureCount",
      "value" = 7,
      "comment" = "the 7 Nature-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66WoodCount",
      "value" = 1,
      "comment" = "the one Wood-marked wu jen spell - warp wood, the only Wood mark in the list (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66AllCount",
      "value" = 4,
      "comment" = "the four All-marked wu jen spells - elemental burst, scry, elemental turning, conjure elemental - one per level from 1 through 5 except the fourth taking elemental turning (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66DualCount",
      "value" = 2,
      "comment" = "the two dual-marked wu jen spells - cloudburst (Water/Air) and water to poison (Nature/Water) (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66UntaggedCount",
      "value" = 131,
      "comment" = "the 131 wu jen spells carrying no element mark - the majority of the list (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66MemorizeHours",
      "value" = 6,
      "comment" = "the wu jen needs at least six hours of restful meditation and study with his scrolls to memorize a spell (print pp. 153-155; compressed pp. 74-75)",
    }, {
      "name" = "dieWJT66StartRoll",
      "value" = 3,
      "comment" = "the starting number of first level spells known is rolled 3d6, clamped to the intelligence minimum and maximum (print pp. 153-155; compressed pp. 74-75)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dieWJT66L1Element",
      "values" = { 0, 5, 0, 1, 0, 0, 5, 7, 3, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 1, 6, 4, 0 },
      "default" = 0,
      "comment" = "the wu jen 1th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 accuracy, 2 animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light, 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water protection, 30 wizard mark - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 12 tagged spells this level: 2 animate wood, 4 cloud ladder, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 11 hail of stone, 16 melt, 23 still water, 24 swim, 27 wall of fog, 28 warp wood, 29 water protection",
    }, {
      "name" = "dieWJT66L2Element",
      "values" = { 0, 0, 4, 0, 0, 0, 0, 0, 3, 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 3, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0 },
      "default" = 0,
      "comment" = "the wu jen 2th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 animal companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11 hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24 stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29 whispering wind, 30 wizard lock - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 10 tagged spells this level: 3 animate water, 9 fire shuriken, 10 fog cloud, 12 ice knife, 20 pyrotechnics, 22 smoke shape, 23 smoky form, 24 stinking cloud, 27 wind breath, 29 whispering wind",
    }, {
      "name" = "dieWJT66L3Element",
      "values" = { 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 7, 2, 0, 0, 5, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 3th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 1 animate fire, 2 cloudburst, 16 magnetism, 19 steam breath, 20 scry, 21 statue, 24 wood shape",
    }, {
      "name" = "dieWJT66L4Element",
      "values" = { 0, 0, 0, 2, 0, 0, 7, 0, 3, 0, 3, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 4th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 bargain, 2 confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14 polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of bones, 24 wall of fire - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 4 dimension door, 7 elemental turning, 9 fire enchantment, 11 melt metal, 13 plant growth, 14 polymorph other, 24 wall of fire",
    }, {
      "name" = "dieWJT66L5Element",
      "values" = { 0, 0, 0, 4, 7, 1, 0, 3, 5, 0, 2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 9, 5, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 5th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 13 tagged spells this level: 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 8 fire breath, 9 ironwood, 11 mass, 12 metal skin, 13 passwall, 17 stone shape, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot",
    }, {
      "name" = "dieWJT66L6Element",
      "values" = { 0, 0, 0, 0, 0, 0, 2, 4, 0, 2, 2, 0, 4, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 6th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 aura, 2 control weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7 glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth, 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16 repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 7 glassee, 8 lower water, 10 metal to rust, 11 move earth, 13 part water, 19 stone to flesh, 24 warp stone",
    }, {
      "name" = "dieWJT66L7Element",
      "values" = { 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 7th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word, stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 1 tagged spells this level: 5 ice blight",
    }, {
      "name" = "dieWJT66L8Element",
      "values" = { 0, 0, 1, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 1, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 8th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any object, 10 power word, blind, 11 summoning wind, 12 surelife, 13 symbol, 14 whirlwind - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 4 tagged spells this level: 3 cloud trapeze, 6 incendiary cloud, blind, 13 symbol",
    }, {
      "name" = "dieWJT66L9Element",
      "values" = { 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 4, 0, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99 },
      "default" = 0,
      "comment" = "the wu jen 9th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regenerate, 6 internal fire, 7 planar call, 8 power word, kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 3 tagged spells this level: 2 crystalbrittle, 6 internal fire, 11 time stop",
    } },
  "tables" = { {
      "name" = "dieWJT66Grid",
      "tag" = "WJT66Data",
      "count" = "dieWJT66OrdinalMax",
      "sentinel" = -99,
      "sentinel_census" = { 0, 0, 6, 6, 6, 6, 18, 16, 17 },
      "col_default" = 0,
      "cols" = { "dieWJT66L1Element", "dieWJT66L2Element", "dieWJT66L3Element", "dieWJT66L4Element", "dieWJT66L5Element", "dieWJT66L6Element", "dieWJT66L7Element", "dieWJT66L8Element", "dieWJT66L9Element" },
      "col_comments" = { "the wu jen 1th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 accuracy, 2 animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light, 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water protection, 30 wizard mark - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 12 tagged spells this level: 2 animate wood, 4 cloud ladder, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 11 hail of stone, 16 melt, 23 still water, 24 swim, 27 wall of fog, 28 warp wood, 29 water protection", "the wu jen 2th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 animal companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11 hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24 stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29 whispering wind, 30 wizard lock - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 10 tagged spells this level: 3 animate water, 9 fire shuriken, 10 fog cloud, 12 ice knife, 20 pyrotechnics, 22 smoke shape, 23 smoky form, 24 stinking cloud, 27 wind breath, 29 whispering wind", "the wu jen 3th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory, 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues, 24 wood shape - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 1 animate fire, 2 cloudburst, 16 magnetism, 19 steam breath, 20 scry, 21 statue, 24 wood shape", "the wu jen 4th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 bargain, 2 confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14 polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of bones, 24 wall of fire - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 4 dimension door, 7 elemental turning, 9 fire enchantment, 11 melt metal, 13 plant growth, 14 polymorph other, 24 wall of fire", "the wu jen 5th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 aiming at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10 major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15 shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19 telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 13 tagged spells this level: 4 cone of cold, 5 conjure elemental, 6 creeping darkness, 8 fire breath, 9 ironwood, 11 mass, 12 metal skin, 13 passwall, 17 stone shape, 21 wall of iron, 22 wall of stone, 23 water to poison, 24 wood rot", "the wu jen 6th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 aura, 2 control weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7 glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth, 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16 repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 7 tagged spells this level: 7 glassee, 8 lower water, 10 metal to rust, 11 move earth, 13 part water, 19 stone to flesh, 24 warp stone", "the wu jen 7th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 body outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word, stun, 9 reanimation, 10 tool, 11 vanish, 12 withering palm - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 1 tagged spells this level: 5 ice blight", "the wu jen 8th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any object, 10 power word, blind, 11 summoning wind, 12 surelife, 13 symbol, 14 whirlwind - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 4 tagged spells this level: 3 cloud trapeze, 6 incendiary cloud, blind, 13 symbol", "the wu jen 9th level spell elements by ordinal (print pp. 153-155; compressed pp. 74-75). The spell list rides this comment: 1 astral spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regenerate, 6 internal fire, 7 planar call, 8 power word, kill, 9 shape change, 10 summon spirit, 11 time stop, 12 tsunami, 13 wish - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) - the printed marks. The 3 tagged spells this level: 2 crystalbrittle, 6 internal fire, 11 time stop" },
      "data" = { { 0, 0, 3, 0, 0, 0, 0, 0, 0 }, { 5, 0, 8, 0, 0, 0, 0, 0, 2 }, { 0, 4, 0, 0, 0, 0, 0, 1, 0 }, { 1, 0, 0, 2, 4, 0, 0, 0, 0 }, { 0, 0, 0, 0, 7, 0, 4, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0, 3, 3 }, { 5, 0, 0, 7, 0, 2, 0, 0, 0 }, { 7, 0, 0, 0, 3, 4, 0, 0, 0 }, { 3, 3, 0, 3, 5, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 2, 0, 0, 0 }, { 2, 0, 0, 3, 2, 2, 0, 1, 0 }, { 0, 4, 0, 0, 2, 0, 0, 0, 4 }, { 0, 0, 0, 5, 2, 4, -99, 0, 0 }, { 0, 0, 0, 5, 0, 0, -99, 1, -99 }, { 0, 0, 0, 0, 0, 0, -99, -99, -99 }, { 3, 0, 2, 0, 0, 0, -99, -99, -99 }, { 0, 0, 0, 0, 2, 0, -99, -99, -99 }, { 0, 0, 0, 0, 0, 0, -99, -99, -99 }, { 0, 0, 1, 0, 0, 2, -99, -99, -99 }, { 0, 3, 7, 0, 0, 0, -99, -99, -99 }, { 0, 0, 2, 0, 2, 0, -99, -99, -99 }, { 0, 1, 0, 0, 2, 0, -99, -99, -99 }, { 4, 1, 0, 0, 9, 0, -99, -99, -99 }, { 4, 1, 5, 3, 5, 2, -99, -99, -99 }, { 0, 0, -99, -99, -99, -99, -99, -99, -99 }, { 0, 0, -99, -99, -99, -99, -99, -99, -99 }, { 1, 1, -99, -99, -99, -99, -99, -99, -99 }, { 6, 0, -99, -99, -99, -99, -99, -99, -99 }, { 4, 1, -99, -99, -99, -99, -99, -99, -99 }, { 0, 0, -99, -99, -99, -99, -99, -99, -99 } },
      "comment" = "the Table 66 wu jen spell list element grid (print pp. 153-155; compressed pp. 74-75)",
      "audit_comment" = "the wu jen spell list grid: the elemental marks by spell ordinal and level",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dieWJT66LevelCount']() != 9  or m['dieWJT66SpellTotal']() != 195  or m['dieWJT66OrdinalMax']() != 30  or m['dieWJT66L1Spells']() != 30  or m['dieWJT66L2Spells']() != 30  or m['dieWJT66L3Spells']() != 24  or m['dieWJT66L4Spells']() != 24  or m['dieWJT66L5Spells']() != 24  or m['dieWJT66L6Spells']() != 24  or m['dieWJT66L7Spells']() != 12  or m['dieWJT66L8Spells']() != 14  or m['dieWJT66L9Spells']() != 13  or m['dieWJT66AirCount']() != 13  or m['dieWJT66EarthCount']() != 16  or m['dieWJT66FireCount']() != 11  or m['dieWJT66WaterCount']() != 10  or m['dieWJT66NatureCount']() != 7  or m['dieWJT66WoodCount']() != 1  or m['dieWJT66AllCount']() != 4  or m['dieWJT66DualCount']() != 2  or m['dieWJT66UntaggedCount']() != 131  or m['dieWJT66MemorizeHours']() != 6  or m['dieWJT66StartRoll']() != 3",
      "note" = "",
    }, {
      "expr" = "m['dieWJT66LevelCount']() != 9  or m['dieWJT66SpellTotal']() != 195  or m['dieWJT66OrdinalMax']() != 30  or m['dieWJT66L1Spells']() != 30  or m['dieWJT66L2Spells']() != 30  or m['dieWJT66L3Spells']() != 24  or m['dieWJT66L4Spells']() != 24  or m['dieWJT66L5Spells']() != 24  or m['dieWJT66L6Spells']() != 24  or m['dieWJT66L7Spells']() != 12  or m['dieWJT66L8Spells']() != 14  or m['dieWJT66L9Spells']() != 13",
      "note" = "the count pins - nine levels, 195 spells total, the ordinal max 30, and the per-level counts",
    }, {
      "expr" = "m['dieWJT66L1Spells']() +m['dieWJT66L2Spells']() +m['dieWJT66L3Spells']() +m['dieWJT66L4Spells']() != 108  or m['dieWJT66L5Spells']() +m['dieWJT66L6Spells']() +m['dieWJT66L7Spells']() +m['dieWJT66L8Spells']() +m['dieWJT66L9Spells']() != 87  or m['dieWJT66SpellTotal']() != 108 + 87",
      "note" = "the level-sum identity pins - the per-level counts sum to the spell total",
    }, {
      "expr" = "m['dieWJT66AirCount']() != 13  or m['dieWJT66EarthCount']() != 16  or m['dieWJT66FireCount']() != 11  or m['dieWJT66WaterCount']() != 10  or m['dieWJT66NatureCount']() != 7  or m['dieWJT66WoodCount']() != 1  or m['dieWJT66AllCount']() != 4  or m['dieWJT66DualCount']() != 2  or m['dieWJT66UntaggedCount']() != 131",
      "note" = "the element census pins - Earth the most common at 16, Air 13, Fire 11, Water 10, Nature 7, the single Wood mark, the four All marks, the two duals and the 131 untagged",
    }, {
      "expr" = "m['dieWJT66AirCount']() +m['dieWJT66EarthCount']() +m['dieWJT66FireCount']() +m['dieWJT66WaterCount']() +m['dieWJT66NatureCount']() +m['dieWJT66WoodCount']() +m['dieWJT66AllCount']() +m['dieWJT66DualCount']() +m['dieWJT66UntaggedCount']() !=m['dieWJT66SpellTotal']()",
      "note" = "the element-sum identity pins - the tagged elements plus the untagged sum to the spell total",
    }, {
      "expr" = "m['dieWJT66L1Element'](1) != 5  or m['dieWJT66L1Element'](6) != 5  or m['dieWJT66L1Element'](3) != 1  or m['dieWJT66L1Element'](26) != 1  or m['dieWJT66L1Element'](7) != 7  or m['dieWJT66L1Element'](8) != 3  or m['dieWJT66L1Element'](15) != 3  or m['dieWJT66L1Element'](10) != 2  or m['dieWJT66L1Element'](22) != 4  or m['dieWJT66L1Element'](23) != 4  or m['dieWJT66L1Element'](28) != 4  or m['dieWJT66L1Element'](27) != 6  or m['dieWJT66L1Element'](0) != 0  or m['dieWJT66L1Element'](14) != 0",
      "note" = "the first level element pins - animate wood and drowsy insects Nature, cloud ladder and wall of fog Air, elemental burst All, fiery eyes and melt Fire, hail of stone Earth, still water, swim and water protection Water, warp wood the lone Wood mark, accuracy and the other eleven untagged",
    }, {
      "expr" = "m['dieWJT66L2Element'](9) != 1  or m['dieWJT66L2Element'](21) != 1  or m['dieWJT66L2Element'](22) != 1  or m['dieWJT66L2Element'](23) != 1  or m['dieWJT66L2Element'](26) != 1  or m['dieWJT66L2Element'](28) != 1  or m['dieWJT66L2Element'](2) != 4  or m['dieWJT66L2Element'](11) != 4  or m['dieWJT66L2Element'](8) != 3  or m['dieWJT66L2Element'](19) != 3",
      "note" = "the second level element pins - the six Air marks (fog cloud, smoke shape, smoky form, stinking cloud, wind breath, whispering wind), animate water and ice knife Water, fire shuriken and pyrotechnics Fire",
    }, {
      "expr" = "m['dieWJT66L3Element'](1) != 8  or m['dieWJT66L5Element'](22) != 9  or m['dieWJT66L6Element'](6) != 2  or m['dieWJT66L3Element'](19) != 7  or m['dieWJT66L4Element'](6) != 7  or m['dieWJT66L5Element'](4) != 7",
      "note" = "the middle level element pins - cloudburst the Water/Air dual 8, water to poison the Nature/Water dual 9, glassee Earth (the print OCR reading Glasses, the compressed Glassee settling the PHB name), the All marks at scry, elemental turning and conjure elemental",
    }, {
      "expr" = "m['dieWJT66L7Element'](4) != 4  or m['dieWJT66L8Element'](2) != 1  or m['dieWJT66L8Element'](10) != 1  or m['dieWJT66L8Element'](13) != 1  or m['dieWJT66L8Element'](5) != 3  or m['dieWJT66L9Element'](1) != 2  or m['dieWJT66L9Element'](5) != 3  or m['dieWJT66L9Element'](11) != 4",
      "note" = "the high level element pins - ice blight the lone seventh level mark, the three Air marks and incendiary cloud Fire at the eighth, crystalbrittle Earth, internal fire Fire and tsunami Water at the ninth",
    }, {
      "expr" = "m['dieWJT66MemorizeHours']() != 6  or m['dieWJT66StartRoll']() != 3",
      "note" = "the memorization pins - the six hours of restful meditation and the 3d6 starting spell roll",
    } },
  "audit" = {
      "label" = "R669 OA wu jen spell list audit",
      "comment" = "OA round fifty-six (capture pp. 153-155): Table 66 - the wu jen spell list by level, the per-level spell counts with the elemental marks, cross-checked level by level between the passes",
    },
}
