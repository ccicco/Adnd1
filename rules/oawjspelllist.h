// =========================================================================================
// Adnd1 - rules/oawjspelllist.h
// TABLE 66 WU JEN SPELLS, printed capture pp. 153-155 - the OA wu jen spell
// list round
// census 591 -> 592.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 153-155; compressed pp. 74-75); all nine level columns cross-checked name
// by name between the passes. The roster: 30 first and second level spells,
// 24 each at the third through sixth, 12 seventh, 14 eighth and 13 ninth -
// 195 spells total, the ordinal max 30. One contested name: the sixth level
// Glassee reads Glasses in the print OCR against Glassee in the compressed -
// the compressed settles the known PHB spell name. The other OCR variances
// are typographic (the compressed Haute for Haste, Ventiloquism for
// Ventriloquism, the print's stray r on Duo-Dimension and the Power Word
// period artifacts). The distinctive wu jen structure pins as a 30 x 9
// element grid, the R658 T62 pattern with elemental marks in place of the
// sohei and reversible columns: the codes 0 none, 1 Air, 2 Earth, 3 Fire, 4
// Water, 5 Nature, 6 Wood, 7 All, 8 the cloudburst Water/Air dual and 9 the
// water to poison Nature/Water dual - the -99 sentinel padding the ordinals
// beyond each level's count. Earth is the most common element at 16 spells,
// Air 13, Fire 11, Water 10, Nature 7, the lone Wood mark (warp wood), four
// All marks (elemental burst, scry, elemental turning, conjure elemental) and
// the two duals - 64 tagged spells against 131 untagged. The spell names ride
// the column comments with the per-level tagged lists, the spell descriptions
// close in their own rounds. The memorization doctrine pins as the two
// consts: the six hours of restful meditation and the 3d6 starting-spell
// roll. The table tag WJT66Data identifier-safe per the R639 lesson
//
// the gap census after this round: 122 closed, 113 open - the Table 66 Wu Jen
// Spells box flips (census 591 -> 592); NEXT - R670: the wu jen First Level
// Spells (capture pp. 155-165, the 30 stat blocks), prefix dif (verify free),
// audit "R670 OA wu jen first level spells audit"
//
namespace rules {

// ---- the level count pins ----

// the nine wu jen spell levels (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66LevelCount()
    { return 9; }

// the 195 wu jen spells across the nine levels (print pp. 153-155; compressed
// pp. 74-75)
inline int dieWJT66SpellTotal()
    { return 195; }

// the greatest per-level spell count - 30, the first and second levels (print
// pp. 153-155; compressed pp. 74-75)
inline int dieWJT66OrdinalMax()
    { return 30; }

// the 30 first level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L1Spells()
    { return 30; }

// the 30 second level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L2Spells()
    { return 30; }

// the 24 third level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L3Spells()
    { return 24; }

// the 24 fourth level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L4Spells()
    { return 24; }

// the 24 fifth level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L5Spells()
    { return 24; }

// the 24 sixth level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L6Spells()
    { return 24; }

// the 12 seventh level wu jen spells (print pp. 153-155; compressed pp.
// 74-75)
inline int dieWJT66L7Spells()
    { return 12; }

// the 14 eighth level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L8Spells()
    { return 14; }

// the 13 ninth level wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66L9Spells()
    { return 13; }

// the 13 Air-marked wu jen spells - the joint second most common element
// (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66AirCount()
    { return 13; }

// the 16 Earth-marked wu jen spells - the most common element (print pp.
// 153-155; compressed pp. 74-75)
inline int dieWJT66EarthCount()
    { return 16; }

// the 11 Fire-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66FireCount()
    { return 11; }

// the 10 Water-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66WaterCount()
    { return 10; }

// the 7 Nature-marked wu jen spells (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66NatureCount()
    { return 7; }

// the one Wood-marked wu jen spell - warp wood, the only Wood mark in the
// list (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66WoodCount()
    { return 1; }

// the four All-marked wu jen spells - elemental burst, scry, elemental
// turning, conjure elemental - one per level from 1 through 5 except the
// fourth taking elemental turning (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66AllCount()
    { return 4; }

// the two dual-marked wu jen spells - cloudburst (Water/Air) and water to
// poison (Nature/Water) (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66DualCount()
    { return 2; }

// the 131 wu jen spells carrying no element mark - the majority of the list
// (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66UntaggedCount()
    { return 131; }

// the wu jen needs at least six hours of restful meditation and study with
// his scrolls to memorize a spell (print pp. 153-155; compressed pp. 74-75)
inline int dieWJT66MemorizeHours()
    { return 6; }

// the starting number of first level spells known is rolled 3d6, clamped to
// the intelligence minimum and maximum (print pp. 153-155; compressed pp.
// 74-75)
inline int dieWJT66StartRoll()
    { return 3; }

// ---- the element grid ----

// the wu jen 1th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the element codes: 0 none, 1 Air, 2 Earth, 3
// Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst),
// 9 the Nature/Water dual (water to poison) - the printed marks. The 12
// tagged spells this level: 2 animate wood, 4 cloud ladder, 7 drowsy insects,
// 8 elemental burst, 9 fiery eyes, 11 hail of stone, 16 melt, 23 still water,
// 24 swim, 27 wall of fog, 28 warp wood, 29 water protection
inline int dieWJT66L1Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 5;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 5;
        case 7:
            return 7;
        case 8:
            return 3;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 3;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 6;
        case 28:
            return 4;
        case 29:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 2th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the element codes: 0 none, 1 Air, 2
// Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual
// (cloudburst), 9 the Nature/Water dual (water to poison) - the printed
// marks. The 10 tagged spells this level: 3 animate water, 9 fire shuriken,
// 10 fog cloud, 12 ice knife, 20 pyrotechnics, 22 smoke shape, 23 smoky form,
// 24 stinking cloud, 27 wind breath, 29 whispering wind
inline int dieWJT66L2Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 3;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 1;
        case 29:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 3th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water,
// 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the
// Nature/Water dual (water to poison) - the printed marks. The 7 tagged
// spells this level: 1 animate fire, 2 cloudburst, 16 magnetism, 19 steam
// breath, 20 scry, 21 statue, 24 wood shape
inline int dieWJT66L3Element(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 8;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 2;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 7;
        case 20:
            return 2;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 5;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 4th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire,
// 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the
// Nature/Water dual (water to poison) - the printed marks. The 7 tagged
// spells this level: 4 dimension door, 7 elemental turning, 9 fire
// enchantment, 11 melt metal, 13 plant growth, 14 polymorph other, 24 wall of
// fire
inline int dieWJT66L4Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        case 12:
            return 5;
        case 13:
            return 5;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 3;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire,
// 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the
// Nature/Water dual (water to poison) - the printed marks. The 13 tagged
// spells this level: 4 cone of cold, 5 conjure elemental, 6 creeping
// darkness, 8 fire breath, 9 ironwood, 11 mass, 12 metal skin, 13 passwall,
// 17 stone shape, 21 wall of iron, 22 wall of stone, 23 water to poison, 24
// wood rot
inline int dieWJT66L5Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 4;
        case 4:
            return 7;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 5;
        case 9:
            return 0;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 9;
        case 23:
            return 5;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the element
// codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8
// the Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison)
// - the printed marks. The 7 tagged spells this level: 7 glassee, 8 lower
// water, 10 metal to rust, 11 move earth, 13 part water, 19 stone to flesh,
// 24 warp stone
inline int dieWJT66L6Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 2;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 7th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word, stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the element codes: 0
// none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the
// Water/Air dual (cloudburst), 9 the Nature/Water dual (water to poison) -
// the printed marks. The 1 tagged spells this level: 5 ice blight
inline int dieWJT66L7Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return -99;
        case 13:
            return -99;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return -99;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return -99;
        case 21:
            return -99;
        case 22:
            return -99;
        case 23:
            return -99;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 8th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word, blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the element codes: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5
// Nature, 6 Wood, 7 All, 8 the Water/Air dual (cloudburst), 9 the
// Nature/Water dual (water to poison) - the printed marks. The 4 tagged
// spells this level: 3 cloud trapeze, 6 incendiary cloud, blind, 13 symbol
inline int dieWJT66L8Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return -99;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return -99;
        case 21:
            return -99;
        case 22:
            return -99;
        case 23:
            return -99;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell elements by ordinal (print pp. 153-155;
// compressed pp. 74-75). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regenerate, 6 internal
// fire, 7 planar call, 8 power word, kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the element codes: 0 none, 1 Air, 2
// Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual
// (cloudburst), 9 the Nature/Water dual (water to poison) - the printed
// marks. The 3 tagged spells this level: 2 crystalbrittle, 6 internal fire,
// 11 time stop
inline int dieWJT66L9Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 0;
        case 13:
            return -99;
        case 14:
            return -99;
        case 15:
            return -99;
        case 16:
            return -99;
        case 17:
            return -99;
        case 18:
            return -99;
        case 19:
            return -99;
        case 20:
            return -99;
        case 21:
            return -99;
        case 22:
            return -99;
        case 23:
            return -99;
        case 24:
            return -99;
        case 25:
            return -99;
        case 26:
            return -99;
        case 27:
            return -99;
        case 28:
            return -99;
        case 29:
            return -99;
        default:
            return 0;
        }
    }

}   // namespace rules
