// =========================================================================================
// Adnd1 - rules/oawjl2spells.h
// WU JEN SECOND LEVEL SPELLS, printed capture pp. 165-173 - the OA wu jen
// second level spells round
// census 593 -> 594.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 165-173; compressed pp. 79-82); all 30 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads. The level is
// alteration-heavy: 11 of the 30 spells, evocation six, divination and
// illusion five each, conjuration, enchantment/charm and abjuration one each
// (animal companion the lone enchantment/charm, protection from charm the
// lone abjuration). TWO dual-school prints pin the primary alteration: bind
// the Alteration/Enchantment dual and whispering wind the Alteration/Phantasm
// dual (the exaction precedent); stinking cloud printed Evocation, pinned 3.
// The component census: 19 VSM, seven verbal and somatic, hypnotic pattern
// and vocalize the S,M pairs without the verbal, omen the lone V,M, knock the
// lone verbal-only oddity. Wind breath alone takes the half save (the wind
// damage halved); five negation, three special. The casting times run 16
// two-segment up through seven one-round and four one-turn (animal companion,
// enchanted blade, omen, strength), fire shuriken and phantasmal force three
// segments, knock the lone single segment. Two spells read Reversible (detect
// evil, locate object). The sixth column cross-checks the R669 element grid:
// the 10 tagged cells (six Air, two Water, two Fire) matching the landed
// dieWJT66L2Element pins exactly. The stat grid pins as a table: 30 rows the
// spell ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask),
// casting time in segments (1 round = 10, 1 turn = 60), saving throw code (0
// none, 1 neg., 2 special, 3 half), reversible and element markers. The spell
// names ride the column comments, the prose descriptions close in their own
// rounds. The table tag WJL2Data identifier-safe per the R639 lesson
//
// the gap census after this round: 124 closed, 111 open - the wu jen Second
// Level Spells box flips (census 593 -> 594); NEXT - R672: the wu jen Third
// Level Spells (capture pp. 170-177, the 24 stat blocks), prefix dih (verify
// free), audit "R672 OA wu jen third level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 30 second level wu jen spells (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2SpellCount()
    { return 30; }

// the two reversible second level wu jen spells - detect evil, locate object
// (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2ReversibleCount()
    { return 2; }

// the 11 alteration second level wu jen spells - the most common school
// (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2AlterationCount()
    { return 11; }

// the five divination second level wu jen spells - detect evil, detect
// invisibility, ESP, locate object, omen (print pp. 165-173; compressed pp.
// 79-82)
inline int digWJL2DivinationCount()
    { return 5; }

// the six evocation second level wu jen spells - enchanted blade, fire
// shuriken, ice knife, stinking cloud, wind breath, whip (print pp. 165-173;
// compressed pp. 79-82)
inline int digWJL2EvocationCount()
    { return 6; }

// the five illusion second level wu jen spells - apparition, hypnotic
// pattern, invisibility, misdirection, phantasmal force (print pp. 165-173;
// compressed pp. 79-82)
inline int digWJL2IllusionCount()
    { return 5; }

// the 19 second level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2VSMCount()
    { return 19; }

// the seven second level wu jen spells taking verbal and somatic - detect
// evil, fog cloud, misdirection, pyrotechnics, smoke shape, whispering wind,
// wizard lock; the bitmask reads 3 (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2VSCount()
    { return 7; }

// the two second level wu jen spells taking somatic and material without the
// verbal - hypnotic pattern, vocalize; the bitmask reads 6 (print pp.
// 165-173; compressed pp. 79-82)
inline int digWJL2SMCount()
    { return 2; }

// the one second level wu jen spell taking verbal and material without the
// somatic - omen; the bitmask reads 5 (print pp. 165-173; compressed pp.
// 79-82)
inline int digWJL2VMCount()
    { return 1; }

// the one second level wu jen spell taking the verbal component only - knock
// (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2VerbalOnlyCount()
    { return 1; }

// the 16 second level wu jen spells with a two-segment casting time - the
// most common cast of the level (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2TwoSegmentCasts()
    { return 16; }

// the seven second level wu jen spells with a one-round casting time -
// apparition, animate water, ice knife, smoke shape, smoky form, vocalize,
// wind breath (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2RoundCasts()
    { return 7; }

// the four second level wu jen spells with a one-turn casting time - animal
// companion, enchanted blade, omen, strength (print pp. 165-173; compressed
// pp. 79-82)
inline int digWJL2TurnCasts()
    { return 4; }

// the two second level wu jen spells with a three-segment casting time - fire
// shuriken, phantasmal force (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2ThreeSegmentCasts()
    { return 2; }

// the one second level wu jen spell with a one-segment casting time - knock
// (print pp. 165-173; compressed pp. 79-82)
inline int digWJL2OneSegmentCasts()
    { return 1; }

// the five second level wu jen spells with a negation saving throw - animal
// companion, apparition, hypnotic pattern, ice knife, misdirection (print pp.
// 165-173; compressed pp. 79-82)
inline int digWJL2NegSaves()
    { return 5; }

// the three second level wu jen spells with a special saving throw -
// phantasmal force, stinking cloud, whip (print pp. 165-173; compressed pp.
// 79-82)
inline int digWJL2SpecialSaves()
    { return 3; }

// the one second level wu jen spell with the half saving throw code - wind
// breath, the wind damage halved on a successful save (print pp. 165-173;
// compressed pp. 79-82)
inline int digWJL2HalfSaves()
    { return 1; }

// the 10 element-tagged second level wu jen spells - six Air (fog cloud,
// smoke shape, smoky form, stinking cloud, wind breath, whispering wind), two
// Water (animate water, ice knife), two Fire (fire shuriken, pyrotechnics) -
// matching the R669 dieWJT66L2Element grid exactly (print pp. 165-173;
// compressed pp. 79-82)
inline int digWJL2ElementCount()
    { return 10; }

// ---- the stat grid pins ----

// the wu jen 2nd level spell schools by ordinal (print pp. 165-173;
// compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the school codes: 1 enchantment/charm, 2
// divination, 3 evocation, 4 conjuration (the printed Conjuration and
// Conjuration/Summoning both pinned 4), 6 alteration, 7 abjuration, 9
// illusion/phantasm - alteration the most common school at 11 spells (bind,
// fog cloud, knock, pyrotechnics, rope trick, smoke shape, smoky form,
// strength, vocalize, whispering wind, wizard lock); evocation six;
// divination and illusion five each; conjuration, enchantment/charm and
// abjuration one each (animal companion the lone enchantment/charm,
// protection from charm the lone abjuration) - the two dual-school prints pin
// the primary: bind the Alteration/Enchantment dual and whispering wind the
// Alteration/Phantasm dual both pinned 6 alteration (the exaction precedent);
// stinking cloud printed Evocation, pinned 3
inline int digWJL2School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 9;
        case 2:
            return 4;
        case 3:
            return 6;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 9;
        case 11:
            return 3;
        case 12:
            return 9;
        case 13:
            return 6;
        case 14:
            return 2;
        case 15:
            return 9;
        case 16:
            return 2;
        case 17:
            return 9;
        case 18:
            return 7;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 3;
        case 24:
            return 6;
        case 25:
            return 6;
        case 26:
            return 3;
        case 27:
            return 3;
        case 28:
            return 6;
        case 29:
            return 6;
        default:
            return 0;
        }
    }

// the wu jen 2nd level spell components by ordinal (print pp. 165-173;
// compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the component codes a bitmask: verbal 1,
// somatic 2, material 4 - 19 spells take all three (7), seven verbal and
// somatic (3): detect evil, fog cloud, misdirection, pyrotechnics, smoke
// shape, whispering wind, wizard lock; hypnotic pattern and vocalize the
// somatic and material without the verbal (6); omen the verbal and material
// without the somatic (5); knock the lone verbal only (1)
inline int digWJL2Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 3;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 3;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 1;
        case 14:
            return 7;
        case 15:
            return 3;
        case 16:
            return 5;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 3;
        case 20:
            return 7;
        case 21:
            return 3;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 6;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 3;
        case 29:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 2nd level spell casting times by ordinal (print pp. 165-173;
// compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the casting time in segments - 1 round =
// 10 segments, 1 turn = 60 segments: 16 spells two segments (the most common
// cast of the level), seven a full round (apparition, animate water, ice
// knife, smoke shape, smoky form, vocalize, wind breath), four a full turn
// (animal companion, enchanted blade, omen, strength), fire shuriken and
// phantasmal force three segments, knock the lone single segment
inline int digWJL2CastTime(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 60;
        case 8:
            return 3;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 10;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 60;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 2;
        case 24:
            return 60;
        case 25:
            return 10;
        case 26:
            return 10;
        case 27:
            return 2;
        case 28:
            return 2;
        case 29:
            return 2;
        default:
            return 0;
        }
    }

// the wu jen 2nd level spell saving throws by ordinal (print pp. 165-173;
// compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the saving throw codes: 0 none, 1 neg., 2
// special, 3 half - animal companion, apparition, hypnotic pattern, ice knife
// and misdirection neg.; phantasmal force, stinking cloud and whip special;
// wind breath the lone half code (the wind damage halved on a successful
// save); the other 21 none
inline int digWJL2Save(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
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
            return 1;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 2;
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
            return 2;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 3;
        case 27:
            return 2;
        case 28:
            return 0;
        case 29:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 2nd level spell reversible markers by ordinal (print pp.
// 165-173; compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the cell is 1 where the printed header
// reads Reversible - detect evil (detect good) and locate object (obscure
// object); the two
inline int digWJL2Reversible(int b)
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
            return 1;
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
            return 1;
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
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 2nd level spell element marks by ordinal (print pp. 165-173;
// compressed pp. 79-82). The spell list rides this comment: 1 animal
// companion, 2 apparition, 3 animate water, 4 bind, 5 detect evil, 6 detect
// invisibility, 7 ESP, 8 enchanted blade, 9 fire shuriken, 10 fog cloud, 11
// hypnotic pattern, 12 ice knife, 13 invisibility, 14 knock, 15 locate
// object, 16 misdirection, 17 omen, 18 phantasmal force, 19 protection from
// charm, 20 pyrotechnics, 21 rope trick, 22 smoke shape, 23 smoky form, 24
// stinking cloud, 25 strength, 26 vocalize, 27 wind breath, 28 whip, 29
// whispering wind, 30 wizard lock - the element codes of the R669 T66 grid: 0
// none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the 10
// tagged spells (animate water and ice knife Water, fire shuriken and
// pyrotechnics Fire, fog cloud, smoke shape, smoky form, stinking cloud, wind
// breath and whispering wind Air) matching the R669 dieWJT66L2Element pins
// exactly - the cross-check column
inline int digWJL2Element(int b)
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

}   // namespace rules
