// =========================================================================================
// Adnd1 - rules/oawjl4spells.h
// WU JEN FOURTH LEVEL SPELLS, printed capture pp. 181-188 - the OA wu jen
// fourth level spells round
// census 595 -> 596.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 181-188; compressed pp. 85-88); all 24 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the variances
// typographic or prose-only (the compressed minus signs for the spectral
// force plus signs, the degree marks for the inch marks). Alteration and
// enchantment/charm tie as the most common schools at six spells each,
// evocation four, abjuration three, invocation and illusion two each - THE
// INVOCATION SCHOOL DEBUTING for the wu jen (dream vision, vengeance); wall
// of bones the lone conjuration, its dual school Conjuration/Necromantic
// pinned primary 4 (the exaction precedent); no divination spell this level.
// The component census: 13 VSM, seven verbal and somatic, THREE verbal-only
// spells (dimension door, polymorph self, vengeance), shout the lone V,M. The
// casting times: seven four-segment (the most common cast), seven one-round,
// three one-turn (dream vision, minor creation, reverse flow), four
// three-segment, dimension door and shout the single segments, elemental
// turning the lone five-segment. Eight negation saves, three special, NO half
// save - the first wu jen level without one. Three spells read Reversible
// (dream vision, remove curse, reverse flow). The sixth column cross-checks
// the R669 element grid: the seven tagged cells matching the landed
// dieWJT66L4Element pins exactly - dimension door Earth, elemental turning
// All, fire enchantment, melt metal and wall of fire Fire, plant growth and
// polymorph other Nature. The stat grid pins as a table: 24 rows the spell
// ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting
// time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1
// neg., 2 special, 3 half), reversible and element markers. The spell names
// ride the column comments, the prose descriptions close in their own rounds.
// The table tag WJL4Data identifier-safe per the R639 lesson
//
// the gap census after this round: 126 closed, 109 open - the wu jen Fourth
// Level Spells box flips (census 595 -> 596); NEXT - R674: the wu jen Fifth
// Level Spells (capture pp. 189-196, the 24 stat blocks), prefix dij (verify
// free), audit "R674 OA wu jen fifth level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 24 fourth level wu jen spells (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4SpellCount()
    { return 24; }

// the six alteration fourth level wu jen spells - dimension door, minor
// creation, plant growth, polymorph other, polymorph self, reverse flow
// (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4AlterationCount()
    { return 6; }

// the six enchantment/charm fourth level wu jen spells - bargain, confusion,
// emotion, fire enchantment, quell, transfix (print pp. 181-188; compressed
// pp. 85-88)
inline int diiWJL4EnchantmentCount()
    { return 6; }

// the four evocation fourth level wu jen spells - dancing blade, melt metal,
// shout, wall of fire (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4EvocationCount()
    { return 4; }

// the three abjuration fourth level wu jen spells - dispel illusion,
// elemental turning, remove curse (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4AbjurationCount()
    { return 3; }

// the two invocation fourth level wu jen spells - dream vision, vengeance;
// the invocation school debuting for the wu jen (print pp. 181-188;
// compressed pp. 85-88)
inline int diiWJL4InvocationCount()
    { return 2; }

// the two illusion fourth level wu jen spells - improved invisibility,
// spectral force (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4IllusionCount()
    { return 2; }

// the three reversible fourth level wu jen spells - dream vision, remove
// curse, reverse flow (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4ReversibleCount()
    { return 3; }

// the 13 fourth level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4VSMCount()
    { return 13; }

// the seven fourth level wu jen spells taking verbal and somatic - dispel
// illusion, emotion, improved invisibility, plant growth, quell, remove
// curse, reverse flow; the bitmask reads 3 (print pp. 181-188; compressed pp.
// 85-88)
inline int diiWJL4VSCount()
    { return 7; }

// the three fourth level wu jen spells taking the verbal component only -
// dimension door, polymorph self, vengeance (print pp. 181-188; compressed
// pp. 85-88)
inline int diiWJL4VerbalOnlyCount()
    { return 3; }

// the one fourth level wu jen spell taking verbal and material without the
// somatic - shout; the bitmask reads 5 (print pp. 181-188; compressed pp.
// 85-88)
inline int diiWJL4VMCount()
    { return 1; }

// the seven fourth level wu jen spells with a four-segment casting time -
// confusion, emotion, improved invisibility, plant growth, polymorph other,
// remove curse, wall of fire; the most common cast of the level (print pp.
// 181-188; compressed pp. 85-88)
inline int diiWJL4FourSegmentCasts()
    { return 7; }

// the seven fourth level wu jen spells with a one-round casting time -
// bargain, dancing blade, fire enchantment, melt metal, transfix, vengeance,
// wall of bones (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4RoundCasts()
    { return 7; }

// the three fourth level wu jen spells with a one-turn casting time - dream
// vision, minor creation, reverse flow (print pp. 181-188; compressed pp.
// 85-88)
inline int diiWJL4TurnCasts()
    { return 3; }

// the four fourth level wu jen spells with a three-segment casting time -
// dispel illusion, polymorph self, quell, spectral force (print pp. 181-188;
// compressed pp. 85-88)
inline int diiWJL4ThreeSegmentCasts()
    { return 4; }

// the two fourth level wu jen spells with a one-segment casting time -
// dimension door, shout (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4OneSegmentCasts()
    { return 2; }

// the one fourth level wu jen spell with a five-segment casting time -
// elemental turning (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4FiveSegmentCasts()
    { return 1; }

// the eight fourth level wu jen spells with a negation saving throw -
// bargain, elemental turning, emotion, fire enchantment, polymorph other,
// quell, shout, transfix (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4NegSaves()
    { return 8; }

// the three fourth level wu jen spells with a special saving throw -
// confusion, remove curse, spectral force (print pp. 181-188; compressed pp.
// 85-88)
inline int diiWJL4SpecialSaves()
    { return 3; }

// the seven element-tagged fourth level wu jen spells - dimension door Earth,
// elemental turning All, fire enchantment, melt metal and wall of fire Fire,
// plant growth and polymorph other Nature - matching the R669
// dieWJT66L4Element grid exactly (print pp. 181-188; compressed pp. 85-88)
inline int diiWJL4ElementCount()
    { return 7; }

// ---- the stat grid pins ----

// the wu jen 4th level spell schools by ordinal (print pp. 181-188;
// compressed pp. 85-88). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the school codes: 1 enchantment/charm, 2
// divination, 3 evocation, 4 conjuration (the printed Conjuration and
// Conjuration/Summoning both pinned 4), 6 alteration, 7 abjuration, 8
// invocation, 9 illusion/phantasm - alteration and enchantment/charm tied as
// the most common schools at six spells each (dimension door, minor creation,
// plant growth, polymorph other, polymorph self, reverse flow; bargain,
// confusion, emotion, fire enchantment, quell, transfix); evocation four;
// abjuration three; invocation and illusion two each - the invocation school
// DEBUTING for the wu jen (dream vision, vengeance); wall of bones the lone
// conjuration, its dual school Conjuration/Necromantic pinned primary 4 (the
// exaction precedent); no divination or necromantic spell this level
inline int diiWJL4School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 7;
        case 5:
            return 8;
        case 6:
            return 7;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 9;
        case 10:
            return 3;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 1;
        case 16:
            return 7;
        case 17:
            return 6;
        case 18:
            return 3;
        case 19:
            return 9;
        case 20:
            return 1;
        case 21:
            return 8;
        case 22:
            return 4;
        case 23:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 4th level spell components by ordinal (print pp. 181-188;
// compressed pp. 85-88). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the component codes a bitmask: verbal 1, somatic
// 2, material 4 - 13 spells take all three (7), seven verbal and somatic (3):
// dispel illusion, emotion, improved invisibility, plant growth, quell,
// remove curse, reverse flow; THREE verbal-only spells (1): dimension door,
// polymorph self, vengeance; shout the lone verbal and material without the
// somatic (5)
inline int diiWJL4Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 3;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 3;
        case 13:
            return 7;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 5;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 1;
        case 22:
            return 7;
        case 23:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 4th level spell casting times by ordinal (print pp. 181-188;
// compressed pp. 85-88). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the casting time in segments - 1 round = 10
// segments, 1 turn = 60 segments: seven spells four segments (the most common
// cast of the level), seven a full round (bargain, dancing blade, fire
// enchantment, melt metal, transfix, vengeance, wall of bones), three a full
// turn (dream vision, minor creation, reverse flow), four three segments,
// dimension door and shout the single segments, elemental turning the lone
// five-segment cast
inline int diiWJL4CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 4;
        case 2:
            return 10;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 60;
        case 6:
            return 5;
        case 7:
            return 4;
        case 8:
            return 10;
        case 9:
            return 4;
        case 10:
            return 10;
        case 11:
            return 60;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 3;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 60;
        case 18:
            return 1;
        case 19:
            return 3;
        case 20:
            return 10;
        case 21:
            return 10;
        case 22:
            return 10;
        case 23:
            return 4;
        default:
            return 0;
        }
    }

// the wu jen 4th level spell saving throws by ordinal (print pp. 181-188;
// compressed pp. 85-88). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the saving throw codes: 0 none, 1 neg., 2 special,
// 3 half - eight negation (bargain, elemental turning, emotion, fire
// enchantment, polymorph other, quell, shout, transfix), three special
// (confusion, remove curse, spectral force), the other 13 none - NO half save
// this level, the first wu jen level without one
inline int diiWJL4Save(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
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
            return 1;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 4th level spell reversible markers by ordinal (print pp.
// 181-188; compressed pp. 85-88). The spell list rides this comment: 1
// bargain, 2 confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion,
// 6 dream vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10
// improved invisibility, 11 melt metal, 12 minor creation, 13 plant growth,
// 14 polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18
// reverse flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23
// wall of bones, 24 wall of fire - the cell is 1 where the printed header
// reads Reversible - dream vision, remove curse, reverse flow; the three
inline int diiWJL4Reversible(int b)
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
            return 1;
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
            return 0;
        case 16:
            return 1;
        case 17:
            return 1;
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
        default:
            return 0;
        }
    }

// the wu jen 4th level spell element marks by ordinal (print pp. 181-188;
// compressed pp. 85-88). The spell list rides this comment: 1 bargain, 2
// confusion, 3 dancing blade, 4 dimension door, 5 dispel illusion, 6 dream
// vision, 7 elemental turning, 8 emotion, 9 fire enchantment, 10 improved
// invisibility, 11 melt metal, 12 minor creation, 13 plant growth, 14
// polymorph other, 15 polymorph self, 16 quell, 17 remove curse, 18 reverse
// flow, 19 shout, 20 spectral force, 21 transfix, 22 vengeance, 23 wall of
// bones, 24 wall of fire - the element codes of the R669 T66 grid: 0 none, 1
// Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the seven tagged
// spells (dimension door Earth, elemental turning All, fire enchantment, melt
// metal and wall of fire Fire, plant growth and polymorph other Nature)
// matching the R669 dieWJT66L4Element pins exactly - the cross-check column
inline int diiWJL4Element(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
