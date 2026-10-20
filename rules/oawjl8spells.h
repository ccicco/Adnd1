// =========================================================================================
// Adnd1 - rules/oawjl8spells.h
// WU JEN EIGHTH LEVEL SPELLS, printed capture pp. 207-213 - the OA wu jen
// eighth level spells round
// census 599 -> 600.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 207-213; compressed pp. 95-97); all 14 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the whirlwind print
// save garbling as 112 with the compressed pass reading 1/2, the half settled
// by the R674 fire breath precedent class, and summoning wind the FIRST
// school-less print of the wu jen levels, the bare heading in both stat-block
// passes and the roster silent, pinned 0 with the grid school comment
// carrying the code. The level carries TWO dual-school prints, both pinned
// primary alteration (the exaction precedent): finding the center the
// Alteration/Invocation dual and incendiary cloud the Alteration/Evocation
// dual both pinned 6. Alteration the most common school at seven spells,
// conjuration four (call, power word blind, symbol, whirlwind);
// antipathy/sympathy the lone enchantment/charm, mind blank the lone
// abjuration; NO divination, necromantic, invocation or illusion spell this
// level. The component census: 10 VSM, mind blank and summoning wind the
// verbal and somatic pair, power word blind the lone verbal-only, finding the
// center the lone SOMATIC-only - the first since the fifth level aiming at
// the target and shadow door pair. The casts: antipathy/sympathy the six-TURN
// cast pinned 360 segments, the longest of the wu jen levels yet; four
// one-turn (call, giant size, summoning wind, whirlwind); permanency the
// two-round cast pinned 20; polymorph any object and surelife the one-round
// casts; symbol eight segments, cloud trapeze five, incendiary cloud two,
// three single segments (finding the center, mind blank, power word blind);
// NO Casting Time: Special line this level. Call the lone negation save;
// antipathy/sympathy, polymorph any object and symbol special; incendiary
// cloud and whirlwind the two half saves. One reversible spell (giant size).
// The element column cross-checks the R669 dieWJT66L8Element grid: the FOUR
// tagged cells matching exactly - three Air (cloud trapeze, summoning wind,
// whirlwind) and one Fire (incendiary cloud), the richest Air column of the
// wu jen levels
//
// the gap census after this round: 130 closed, 105 open - the wu jen Eighth
// Level Spells box flips (census 599 -> 600); NEXT - R678: the wu jen Ninth
// Level Spells (capture pp. 213-216, the 13 stat blocks), prefix dio (verify
// free - din is TAKEN, the dinosaurSubBands call colliding with the engine
// paren gate), audit "R678 OA wu jen ninth level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 14 eighth level wu jen spells (print pp. 207-213; compressed pp. 95-97)
inline int dimWJL8SpellCount()
    { return 14; }

// the seven alteration eighth level wu jen spells - cloud trapeze, finding
// the center, giant size, incendiary cloud, permanency, polymorph any object,
// surelife; the most common school of the level (print pp. 207-213;
// compressed pp. 95-97)
inline int dimWJL8AlterationCount()
    { return 7; }

// the four conjuration eighth level wu jen spells - call, power word blind,
// symbol, whirlwind (print pp. 207-213; compressed pp. 95-97)
inline int dimWJL8ConjurationCount()
    { return 4; }

// the two dual-school eighth level wu jen prints, both pinned primary
// alteration (the exaction precedent) - finding the center the
// Alteration/Invocation dual, incendiary cloud the Alteration/Evocation dual,
// both pinned 6 (print pp. 207-213; compressed pp. 95-97)
inline int dimWJL8DualSchoolCount()
    { return 2; }

// the 10 eighth level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 207-213; compressed pp. 95-97)
inline int dimWJL8VSMCount()
    { return 10; }

// the one somatic-only eighth level wu jen spell - finding the center, the
// lone S of the wu jen levels since the fifth level pair (print pp. 207-213;
// compressed pp. 95-97)
inline int dimWJL8SomaticOnlyCount()
    { return 1; }

// the one verbal-only eighth level wu jen spell - power word blind (print pp.
// 207-213; compressed pp. 95-97)
inline int dimWJL8VerbalOnlyCount()
    { return 1; }

// the one reversible eighth level wu jen spell - giant size (print pp.
// 207-213; compressed pp. 95-97)
inline int dimWJL8ReversibleCount()
    { return 1; }

// the antipathy/sympathy six-turn casting time pinned 360 segments - the
// longest cast of the wu jen levels yet (print pp. 207-213; compressed pp.
// 95-97)
inline int dimWJL8SixTurnCast()
    { return 360; }

// the four eighth level wu jen spells with a one-turn casting time - call,
// giant size, summoning wind, whirlwind (print pp. 207-213; compressed pp.
// 95-97)
inline int dimWJL8TurnCasts()
    { return 4; }

// the three eighth level wu jen spells with a special saving throw -
// antipathy/sympathy, polymorph any object, symbol (print pp. 207-213;
// compressed pp. 95-97)
inline int dimWJL8SpecialSaves()
    { return 3; }

// the two eighth level wu jen spells with a half saving throw - incendiary
// cloud and whirlwind (the whirlwind print save garbling as 112, the
// compressed pass reading 1/2 - the R674 fire breath precedent class) (print
// pp. 207-213; compressed pp. 95-97)
inline int dimWJL8HalfSaves()
    { return 2; }

// the four element-tagged eighth level wu jen spells - three Air (cloud
// trapeze, summoning wind, whirlwind) and one Fire (incendiary cloud) -
// matching the R669 dieWJT66L8Element grid exactly, the richest Air column of
// the wu jen levels (print pp. 207-213; compressed pp. 95-97)
inline int dimWJL8ElementCount()
    { return 4; }

// ---- the stat grid pins ----

// the wu jen 8th level spell schools by ordinal (print pp. 207-213;
// compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the school codes: 0 the school-less print, 1 enchantment/charm,
// 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and
// Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7
// abjuration, 8 invocation, 9 illusion/phantasm - alteration the most common
// school at seven spells (cloud trapeze, finding the center, giant size,
// incendiary cloud, permanency, polymorph any object, surelife); conjuration
// four (call, power word blind, symbol, whirlwind); antipathy/sympathy the
// lone enchantment/charm, mind blank the lone abjuration; NO divination,
// necromantic, invocation or illusion spell this level - TWO dual-school
// prints, both pinned primary (the exaction precedent): finding the center
// the Alteration/Invocation dual and incendiary cloud the
// Alteration/Evocation dual both pinned 6 - and summoning wind the FIRST
// school-less print of the wu jen levels, the bare heading in both passes and
// the roster silent, pinned 0
inline int dimWJL8School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 0;
        case 11:
            return 6;
        case 12:
            return 4;
        case 13:
            return 4;
        default:
            return 0;
        }
    }

// the wu jen 8th level spell components by ordinal (print pp. 207-213;
// compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the component codes a bitmask: verbal 1, somatic 2, material 4
// - 10 spells take all three (7); mind blank and summoning wind the verbal
// and somatic pair (3); power word blind the lone verbal-only (1); finding
// the center the lone SOMATIC-only (2), the first since the fifth level
// aiming at the target and shadow door pair
inline int dimWJL8Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 2;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 3;
        case 7:
            return 7;
        case 8:
            return 7;
        case 9:
            return 1;
        case 10:
            return 3;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 8th level spell casting times by ordinal (print pp. 207-213;
// compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the casting time in segments - 1 segment to 1 turn = 60
// segments: antipathy/sympathy the six-TURN cast pinned 360, the longest cast
// of the wu jen levels yet; four one-turn (call, giant size, summoning wind,
// whirlwind); permanency the two-round cast pinned 20; polymorph any object
// and surelife the one-round casts; symbol eight segments, cloud trapeze
// five, incendiary cloud two; finding the center, mind blank and power word
// blind the single segments - NO Casting Time: Special line this level
inline int dimWJL8CastTime(int b)
    {
        switch (b) {
        case 0:
            return 360;
        case 1:
            return 60;
        case 2:
            return 5;
        case 3:
            return 1;
        case 4:
            return 60;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 20;
        case 8:
            return 10;
        case 9:
            return 1;
        case 10:
            return 60;
        case 11:
            return 10;
        case 12:
            return 8;
        case 13:
            return 60;
        default:
            return 0;
        }
    }

// the wu jen 8th level spell saving throws by ordinal (print pp. 207-213;
// compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the saving throw codes: 0 none, 1 neg., 2 special, 3 half -
// call the lone negation save; antipathy/sympathy, polymorph any object and
// symbol special; incendiary cloud and whirlwind the two HALF saves (the
// whirlwind print garbling the save as 112, the compressed pass reading 1/2 -
// the R674 fire breath precedent class); the other eight none
inline int dimWJL8Save(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
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
            return 2;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 2;
        case 13:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 8th level spell reversible markers by ordinal (print pp.
// 207-213; compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the cell is 1 where the printed header reads Reversible - giant
// size the one
inline int dimWJL8Reversible(int b)
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
        default:
            return 0;
        }
    }

// the wu jen 8th level spell element marks by ordinal (print pp. 207-213;
// compressed pp. 95-97). The spell list rides this comment: 1
// antipathy/sympathy, 2 call, 3 cloud trapeze, 4 finding the center, 5 giant
// size, 6 incendiary cloud, 7 mind blank, 8 permanency, 9 polymorph any
// object, 10 power word blind, 11 summoning wind, 12 surelife, 13 symbol, 14
// whirlwind - the element codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth,
// 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the FOUR tagged spells (cloud
// trapeze, summoning wind and whirlwind Air; incendiary cloud Fire) matching
// the R669 dieWJT66L8Element pins exactly, the richest Air column of the wu
// jen levels - the cross-check column
inline int dimWJL8Element(int b)
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
        default:
            return 0;
        }
    }

}   // namespace rules
