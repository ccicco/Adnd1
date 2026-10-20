// =========================================================================================
// Adnd1 - rules/oawjl3spells.h
// WU JEN THIRD LEVEL SPELLS, printed capture pp. 173-181 - the OA wu jen
// third level spells round
// census 594 -> 595.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 173-181; compressed pp. 82-85); all 24 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the variances
// typographic or prose-only (the compressed Scy for scry in the header, the
// print 6-10 against the compressed 8-10 for the cloudburst large-fire
// quench, the feign death duration sign, the fire rain 1d8 read as 108 in the
// compressed - none of them grid cells). The level is alteration-heavy again:
// seven of the 24 spells, enchantment/charm and illusion four each,
// divination three, evocation and abjuration two each, conjuration and
// necromantic one each (animate fire the lone conjuration, feign death the
// lone necromantic). TWO dual-school prints pin the primary (the exaction
// precedent): fabricate the Enchantment/Alteration dual pinned 1, face the
// Illusion/Phantasm; Enchantment/Charm dual pinned 9. The component census:
// 19 VSM, dispel magic and feign death the verbal and somatic pair,
// suggestion and tongues the V,M pairs, hold person the lone verbal-only.
// THREE spells take the Casting Time: Special line (fabricate, illusionary
// script, memory) pinned -1, the R662 exorcise variable-cast convention; four
// one-turn casts (commune with lesser spirit, disguise, face, scry), five
// one-round, seven three-segment, cloudburst and fire rain five segments,
// statue the lone seven-segment cast, feign death the lone single segment.
// Four negation saves, four special, fire rain and steam breath the two half
// saves (the damage halved). Four spells read Reversible (face, magnetism,
// memory, tongues). The sixth column cross-checks the R669 element grid: the
// seven tagged cells matching the landed dieWJT66L3Element pins exactly -
// animate fire Fire, cloudburst the Water/Air dual code 8, magnetism and
// statue Earth, steam breath Air, scry All, wood shape Nature. The stat grid
// pins as a table: 24 rows the spell ordinals, six columns - school,
// components (a V=1 S=2 M=4 bitmask), casting time in segments (1 round = 10,
// 1 turn = 60, -1 the special cast), saving throw code (0 none, 1 neg., 2
// special, 3 half), reversible and element markers. The spell names ride the
// column comments, the prose descriptions close in their own rounds. The
// table tag WJL3Data identifier-safe per the R639 lesson
//
// the gap census after this round: 125 closed, 110 open - the wu jen Third
// Level Spells box flips (census 594 -> 595); NEXT - R673: the wu jen Fourth
// Level Spells (capture pp. 177-188, the 24 stat blocks), prefix dii (verify
// free), audit "R673 OA wu jen fourth level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 24 third level wu jen spells (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3SpellCount()
    { return 24; }

// the seven alteration third level wu jen spells - cloudburst, fire wings,
// haste, magnetism, statue, tongues, wood shape; the most common school
// (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3AlterationCount()
    { return 7; }

// the four enchantment/charm third level wu jen spells - fabricate, hold
// person, memory, suggestion (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3EnchantmentCount()
    { return 4; }

// the four illusion third level wu jen spells - disguise, face, illusionary
// script, improved phantasmal force (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3IllusionCount()
    { return 4; }

// the three divination third level wu jen spells - commune with lesser
// spirit, detect shapechanger, scry (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3DivinationCount()
    { return 3; }

// the four reversible third level wu jen spells - face (lose face), magnetism
// (demagnetize), memory (erasement), tongues (its reverse) (print pp.
// 173-181; compressed pp. 82-85)
inline int dihWJL3ReversibleCount()
    { return 4; }

// the 19 third level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3VSMCount()
    { return 19; }

// the two third level wu jen spells taking verbal and somatic - dispel magic,
// feign death; the bitmask reads 3 (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3VSCount()
    { return 2; }

// the two third level wu jen spells taking verbal and material without the
// somatic - suggestion, tongues; the bitmask reads 5 (print pp. 173-181;
// compressed pp. 82-85)
inline int dihWJL3VMCount()
    { return 2; }

// the one third level wu jen spell taking the verbal component only - hold
// person (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3VerbalOnlyCount()
    { return 1; }

// the three third level wu jen spells with the Casting Time: Special line -
// fabricate, illusionary script, memory; pinned -1, the R662 exorcise
// variable-cast convention (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3SpecialCasts()
    { return 3; }

// the four third level wu jen spells with a one-turn casting time - commune
// with lesser spirit, disguise, face, scry (print pp. 173-181; compressed pp.
// 82-85)
inline int dihWJL3TurnCasts()
    { return 4; }

// the five third level wu jen spells with a one-round casting time - animate
// fire, detect shapechanger, fire wings, steam breath, wood shape (print pp.
// 173-181; compressed pp. 82-85)
inline int dihWJL3RoundCasts()
    { return 5; }

// the seven third level wu jen spells with a three-segment casting time -
// dispel magic, haste, hold person, magnetism, protection from normal
// missiles, suggestion, tongues; the most common fixed cast of the level
// (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3ThreeSegmentCasts()
    { return 7; }

// the two third level wu jen spells with a five-segment casting time -
// cloudburst, fire rain (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3FiveSegmentCasts()
    { return 2; }

// the one third level wu jen spell with a seven-segment casting time - statue
// (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3SevenSegmentCasts()
    { return 1; }

// the four third level wu jen spells with a negation saving throw - hold
// person, magnetism, memory, suggestion (print pp. 173-181; compressed pp.
// 82-85)
inline int dihWJL3NegSaves()
    { return 4; }

// the four third level wu jen spells with a special saving throw - disguise,
// face, improved phantasmal force, statue (print pp. 173-181; compressed pp.
// 82-85)
inline int dihWJL3SpecialSaves()
    { return 4; }

// the two third level wu jen spells with the half saving throw code - fire
// rain, steam breath, the damage halved on a successful save (print pp.
// 173-181; compressed pp. 82-85)
inline int dihWJL3HalfSaves()
    { return 2; }

// the seven element-tagged third level wu jen spells - animate fire Fire,
// cloudburst the Water/Air dual, magnetism and statue Earth, steam breath
// Air, scry All, wood shape Nature - matching the R669 dieWJT66L3Element grid
// exactly (print pp. 173-181; compressed pp. 82-85)
inline int dihWJL3ElementCount()
    { return 7; }

// ---- the stat grid pins ----

// the wu jen 3rd level spell schools by ordinal (print pp. 173-181;
// compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the school codes: 1 enchantment/charm, 2 divination, 3
// evocation, 4 conjuration (the printed Conjuration and Conjuration/Summoning
// both pinned 4), 5 necromantic, 6 alteration, 7 abjuration, 9
// illusion/phantasm - alteration the most common school at seven spells
// (cloudburst, fire wings, haste, magnetism, statue, tongues, wood shape);
// enchantment/charm and illusion four each (fabricate, hold person, memory,
// suggestion; disguise, face, illusionary script, improved phantasmal force);
// divination three; evocation and abjuration two each; conjuration and
// necromantic one each (animate fire the lone conjuration, feign death the
// lone necromantic) - TWO dual-school prints pin the primary (the exaction
// precedent): fabricate the Enchantment/Alteration dual pinned 1, face the
// Illusion/Phantasm; Enchantment/Charm dual pinned 9
inline int dihWJL3School(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 9;
        case 5:
            return 7;
        case 6:
            return 1;
        case 7:
            return 9;
        case 8:
            return 5;
        case 9:
            return 3;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 6;
        case 16:
            return 1;
        case 17:
            return 7;
        case 18:
            return 3;
        case 19:
            return 2;
        case 20:
            return 6;
        case 21:
            return 1;
        case 22:
            return 6;
        case 23:
            return 6;
        default:
            return 0;
        }
    }

// the wu jen 3rd level spell components by ordinal (print pp. 173-181;
// compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the component codes a bitmask: verbal 1, somatic 2,
// material 4 - 19 spells take all three (7), two verbal and somatic (3):
// dispel magic, feign death; suggestion and tongues the verbal and material
// without the somatic (5); hold person the lone verbal only (1)
inline int dihWJL3Components(int b)
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
            return 7;
        case 5:
            return 3;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 3;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 1;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 5;
        case 22:
            return 5;
        case 23:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 3rd level spell casting times by ordinal (print pp. 173-181;
// compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the casting time in segments - 1 round = 10 segments, 1
// turn = 60 segments, -1 the Casting Time: Special line (the R662 exorcise
// convention): three special casts (fabricate, illusionary script, memory),
// four a full turn (commune with lesser spirit, disguise, face, scry), five a
// full round (animate fire, detect shapechanger, fire wings, steam breath,
// wood shape), seven three segments (the most common fixed cast), cloudburst
// and fire rain five segments, statue the lone seven-segment cast, improved
// phantasmal force two segments, feign death the lone single segment
inline int dihWJL3CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 5;
        case 2:
            return 60;
        case 3:
            return 10;
        case 4:
            return 60;
        case 5:
            return 3;
        case 6:
            return -1;
        case 7:
            return 60;
        case 8:
            return 1;
        case 9:
            return 5;
        case 10:
            return 10;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return -1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return -1;
        case 17:
            return 3;
        case 18:
            return 10;
        case 19:
            return 60;
        case 20:
            return 7;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 10;
        default:
            return 0;
        }
    }

// the wu jen 3rd level spell saving throws by ordinal (print pp. 173-181;
// compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the saving throw codes: 0 none, 1 neg., 2 special, 3 half -
// hold person, magnetism, memory and suggestion neg.; disguise, face,
// improved phantasmal force and statue special; fire rain and steam breath
// the half code (the damage halved on a successful save); the other 14 none
inline int dihWJL3Save(int b)
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
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 3;
        case 19:
            return 0;
        case 20:
            return 2;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 3rd level spell reversible markers by ordinal (print pp.
// 173-181; compressed pp. 82-85). The spell list rides this comment: 1
// animate fire, 2 cloudburst, 3 commune with lesser spirit, 4 detect
// shapechanger, 5 disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign
// death, 10 fire rain, 11 fire wings, 12 haste, 13 hold person, 14
// illusionary script, 15 improved phantasmal force, 16 magnetism, 17 memory,
// 18 protection from normal missiles, 19 steam breath, 20 scry, 21 statue, 22
// suggestion, 23 tongues, 24 wood shape - the cell is 1 where the printed
// header reads Reversible - face (lose face), magnetism (demagnetize), memory
// (erasement), tongues (its reverse); the four
inline int dihWJL3Reversible(int b)
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
            return 0;
        case 7:
            return 1;
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
            return 1;
        case 16:
            return 1;
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
            return 1;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 3rd level spell element marks by ordinal (print pp. 173-181;
// compressed pp. 82-85). The spell list rides this comment: 1 animate fire, 2
// cloudburst, 3 commune with lesser spirit, 4 detect shapechanger, 5
// disguise, 6 dispel magic, 7 fabricate, 8 face, 9 feign death, 10 fire rain,
// 11 fire wings, 12 haste, 13 hold person, 14 illusionary script, 15 improved
// phantasmal force, 16 magnetism, 17 memory, 18 protection from normal
// missiles, 19 steam breath, 20 scry, 21 statue, 22 suggestion, 23 tongues,
// 24 wood shape - the element codes of the R669 T66 grid: 0 none, 1 Air, 2
// Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 8 the Water/Air dual
// (cloudburst) - the seven tagged spells (animate fire Fire, cloudburst the
// dual 8, magnetism and statue Earth, steam breath Air, scry All, wood shape
// Nature) matching the R669 dieWJT66L3Element pins exactly - the cross-check
// column
inline int dihWJL3Element(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
