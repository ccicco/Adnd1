// =========================================================================================
// Adnd1 - rules/oawjl5spells.h
// WU JEN FIFTH LEVEL SPELLS, printed capture pp. 189-196 - the OA wu jen
// fifth level spells round
// census 596 -> 597.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 189-196; compressed pp. 87-91); all 24 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the variances
// typographic or prose-only (the fire breath save printed 1/z for the half,
// the wall of stone range garbled X12, the servant horde count 2d6 + 1 in the
// print against 2d6 - 1 in the compressed - a prose divergence outside the
// grid). The level is alteration-heavy yet again: 10 of the 24 spells,
// evocation eight, conjuration two, and FOUR lone-school spells - animate
// dead the lone necromantic, aiming at the target the lone invocation, shadow
// door the lone illusion, dismissal the lone abjuration with its odd
// triple-line print Abjuration Reversible (Conjuration/Summoning) pinned
// primary 7; no divination or enchantment/charm spell this level. The
// component census: 20 VSM, and TWO somatic-only spells (aiming at the
// target, shadow door) - the first somatic-only spells of the wu jen levels;
// animal growth and telekinesis the verbal and somatic pair; no verbal-only
// or V,M spell this level. The casting times: nine five-segment (the most
// common cast), six one-round, three three-segment, conjure elemental and
// major creation one-turn, animate dead the five-ROUND cast pinned 50
// segments (the longest of the level), servant horde the lone single segment,
// shadow door two, sword of deception four. Three negation saves, cone of
// cold and fire breath the two half saves, no special save this level. Four
// spells read Reversible (animal growth, dismissal, water to poison, wood
// rot). The sixth column cross-checks the R669 element grid: the 13 tagged
// cells - the richest element column yet - matching the landed
// dieWJT66L5Element pins exactly, with water to poison carrying the
// Nature/Water dual code 9. The stat grid pins as a table: 24 rows the spell
// ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting
// time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1
// neg., 2 special, 3 half), reversible and element markers. The spell names
// ride the column comments, the prose descriptions close in their own rounds.
// The table tag WJL5Data identifier-safe per the R639 lesson
//
// the gap census after this round: 127 closed, 108 open - the wu jen Fifth
// Level Spells box flips (census 596 -> 597); NEXT - R675: the wu jen Sixth
// Level Spells (capture pp. 196-202, the 12 stat blocks), prefix dik (verify
// free - only comment-word matches expected, the R669 die precedent), audit
// "R675 OA wu jen sixth level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 24 fifth level wu jen spells (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5SpellCount()
    { return 24; }

// the 10 alteration fifth level wu jen spells - animal growth, ironwood,
// major creation, mass, metal skin, passwall, spirit self, stone shape,
// telekinesis, water to poison; the most common school (print pp. 189-196;
// compressed pp. 87-91)
inline int dijWJL5AlterationCount()
    { return 10; }

// the eight evocation fifth level wu jen spells - cone of cold, creeping
// darkness, fire breath, sword of deception, wall of force, wall of iron,
// wall of stone, wood rot (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5EvocationCount()
    { return 8; }

// the four reversible fifth level wu jen spells - animal growth (animal
// diminution), dismissal (beckon), water to poison (poison to water), wood
// rot (prevent rot) (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5ReversibleCount()
    { return 4; }

// the 20 fifth level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5VSMCount()
    { return 20; }

// the two fifth level wu jen spells taking the somatic component only -
// aiming at the target, shadow door; the bitmask reads 2, the first
// somatic-only spells of the wu jen levels (print pp. 189-196; compressed pp.
// 87-91)
inline int dijWJL5SomaticOnlyCount()
    { return 2; }

// the two fifth level wu jen spells taking verbal and somatic - animal
// growth, telekinesis; the bitmask reads 3 (print pp. 189-196; compressed pp.
// 87-91)
inline int dijWJL5VSCount()
    { return 2; }

// the nine fifth level wu jen spells with a five-segment casting time -
// animal growth, cone of cold, creeping darkness, metal skin, passwall,
// telekinesis, wall of force, wall of iron, wall of stone; the most common
// cast of the level (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5FiveSegmentCasts()
    { return 9; }

// the six fifth level wu jen spells with a one-round casting time -
// dismissal, fire breath, ironwood, mass, stone shape, water to poison (print
// pp. 189-196; compressed pp. 87-91)
inline int dijWJL5RoundCasts()
    { return 6; }

// the three fifth level wu jen spells with a three-segment casting time -
// aiming at the target, spirit self, wood rot (print pp. 189-196; compressed
// pp. 87-91)
inline int dijWJL5ThreeSegmentCasts()
    { return 3; }

// the two fifth level wu jen spells with a one-turn casting time - conjure
// elemental, major creation (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5TurnCasts()
    { return 2; }

// the one fifth level wu jen spell with a five-round casting time - animate
// dead, pinned 50 segments (1 round = 10), the longest cast of the level
// (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5FiveRoundCast()
    { return 1; }

// the one fifth level wu jen spell with a one-segment casting time - servant
// horde (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5OneSegmentCasts()
    { return 1; }

// the one fifth level wu jen spell with a two-segment casting time - shadow
// door (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5TwoSegmentCasts()
    { return 1; }

// the one fifth level wu jen spell with a four-segment casting time - sword
// of deception (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5FourSegmentCasts()
    { return 1; }

// the three fifth level wu jen spells with a negation saving throw -
// dismissal, mass, wood rot (print pp. 189-196; compressed pp. 87-91)
inline int dijWJL5NegSaves()
    { return 3; }

// the two fifth level wu jen spells with the half saving throw code - cone of
// cold, fire breath, the damage halved on a successful save (print pp.
// 189-196; compressed pp. 87-91)
inline int dijWJL5HalfSaves()
    { return 2; }

// the 13 element-tagged fifth level wu jen spells - six Earth (mass, metal
// skin, passwall, stone shape, wall of iron, wall of stone), conjure
// elemental All, creeping darkness Air, cone of cold Water, fire breath Fire,
// ironwood and wood rot Nature, water to poison the Nature/Water dual 9 -
// matching the R669 dieWJT66L5Element grid exactly (print pp. 189-196;
// compressed pp. 87-91)
inline int dijWJL5ElementCount()
    { return 13; }

// ---- the stat grid pins ----

// the wu jen 5th level spell schools by ordinal (print pp. 189-196;
// compressed pp. 87-91). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the school codes: 3 evocation, 4 conjuration (the
// printed Conjuration and Conjuration/Summoning both pinned 4), 5
// necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm
// - alteration the most common school at 10 spells (animal growth, ironwood,
// major creation, mass, metal skin, passwall, spirit self, stone shape,
// telekinesis, water to poison); evocation eight; conjuration two (conjure
// elemental, servant horde); animate dead the lone necromantic, aiming at the
// target the lone invocation, shadow door the lone illusion, dismissal the
// lone abjuration - its odd triple-line print Abjuration Reversible
// (Conjuration/Summoning) pinned primary abjuration 7; no divination or
// enchantment/charm spell this level
inline int dijWJL5School(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 4;
        case 14:
            return 9;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 6;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 6;
        case 23:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell components by ordinal (print pp. 189-196;
// compressed pp. 87-91). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the component codes a bitmask: verbal 1, somatic
// 2, material 4 - 20 spells take all three (7), TWO somatic-only spells (2):
// aiming at the target and shadow door, the first somatic-only spells of the
// wu jen levels; animal growth and telekinesis the verbal and somatic pair
// (3); no verbal-only or V,M spell this level
inline int dijWJL5Components(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 2;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 3;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell casting times by ordinal (print pp. 189-196;
// compressed pp. 87-91). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the casting time in segments - 1 round = 10
// segments, 1 turn = 60 segments: nine spells five segments (the most common
// cast of the level), six a full round (dismissal, fire breath, ironwood,
// mass, stone shape, water to poison), three three segments, conjure
// elemental and major creation a full turn, animate dead the five-ROUND cast
// pinned 50 segments (the longest of the level), servant horde the lone
// single segment, shadow door two, sword of deception four
inline int dijWJL5CastTime(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 50;
        case 3:
            return 5;
        case 4:
            return 60;
        case 5:
            return 5;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 60;
        case 10:
            return 10;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 10;
        case 17:
            return 4;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 5;
        case 22:
            return 10;
        case 23:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell saving throws by ordinal (print pp. 189-196;
// compressed pp. 87-91). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the saving throw codes: 0 none, 1 neg., 2 special,
// 3 half - dismissal, mass and wood rot neg.; cone of cold and fire breath
// the half code (the damage halved on a successful save); no special save
// this level; the other 19 none
inline int dijWJL5Save(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 3;
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
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 1;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell reversible markers by ordinal (print pp.
// 189-196; compressed pp. 87-91). The spell list rides this comment: 1 aiming
// at the target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the cell is 1 where the printed header reads
// Reversible - animal growth (animal diminution), dismissal (beckon), water
// to poison (poison to water), wood rot (prevent rot); the four
inline int dijWJL5Reversible(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 1;
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
            return 1;
        case 23:
            return 1;
        default:
            return 0;
        }
    }

// the wu jen 5th level spell element marks by ordinal (print pp. 189-196;
// compressed pp. 87-91). The spell list rides this comment: 1 aiming at the
// target, 2 animal growth, 3 animate dead, 4 cone of cold, 5 conjure
// elemental, 6 creeping darkness, 7 dismissal, 8 fire breath, 9 ironwood, 10
// major creation, 11 mass, 12 metal skin, 13 passwall, 14 servant horde, 15
// shadow door, 16 spirit self, 17 stone shape, 18 sword of deception, 19
// telekinesis, 20 wall of force, 21 wall of iron, 22 wall of stone, 23 water
// to poison, 24 wood rot - the element codes of the R669 T66 grid: 0 none, 1
// Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All, 9 the Nature/Water
// dual (water to poison) - the 13 tagged spells (cone of cold Water, conjure
// elemental All, creeping darkness Air, fire breath Fire, ironwood and wood
// rot Nature, mass, metal skin, passwall, stone shape, wall of iron and wall
// of stone Earth, water to poison the dual 9) matching the R669
// dieWJT66L5Element pins exactly - the cross-check column, the richest yet
inline int dijWJL5Element(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
