// =========================================================================================
// Adnd1 - rules/oal3spells.h
// THIRD LEVEL SPELLS, printed capture pp. 126-132 - the OA third level spells
// round
// census 583 -> 584.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 20 third
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 126-132; compressed pp. 63-66); all 20 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. Two
// school codes debut this level: invocation (dream vision) and
// illusion/phantasm (invisibility to spirits) - both headers read identically
// in the two passes. Abjuration becomes the most common school at seven
// spells (castigate, cure blindness, cure disease, dispel magic, oath, remove
// curse, remove paralysis); magical vestment's dual school
// conjuration/alteration pins as the primary conjuration, the aid convention
// from the second level. Substitution takes the longest cast in the level at
// three turns. The reversible flags agree between the passes; the
// sohei-usable marks ride the R658 T62 grid, settled three rounds before. The
// stat grid pins as a table: 20 rows the spell ordinals, six columns -
// school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1
// round = 10, 1 turn = 60, 3 turns = 180), saving throw code (0 none, 1 neg.,
// 2 special), reversible and sohei markers. The spell names ride the column
// comments, the prose descriptions and the Table 64 speak with dead grid
// close in their own rounds. The table tag L3Data identifier-safe per the
// R639 lesson
//
// the gap census after this round: 114 closed, 121 open - the Third Level
// Spells box flips (census 583 -> 584); NEXT - R662: the Fourth Level Spells
// (capture pp. 132-140), prefix dhw (verify free), audit "R662 OA fourth
// level spells audit", include after rules/oal3spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 20 third level shukenja spells (print pp. 126-132; compressed pp.
// 63-66)
inline int dhvL3SpellCount()
    { return 20; }

// the four third level spells usable by sohei - castigate, dispel magic,
// flame walk, prayer
inline int dhvL3SoheiCount()
    { return 4; }

// the seven reversible third level spells - cure blindness, cure disease,
// dream vision, know alignment, oath, remove curse, remove paralysis
inline int dhvL3ReversibleCount()
    { return 7; }

// the seven abjuration third level spells - the most common school of the
// level: castigate, cure blindness, cure disease, dispel magic, oath, remove
// curse, remove paralysis
inline int dhvL3AbjurationCount()
    { return 7; }

// the three divination third level spells - detect curse, divination, know
// alignment
inline int dhvL3DivinationCount()
    { return 3; }

// the three alteration third level spells - flame walk, levitate,
// substitution
inline int dhvL3AlterationCount()
    { return 3; }

// the two conjuration third level spells - magical vestment (its dual school
// pinned as the primary conjuration) and prayer
inline int dhvL3ConjurationCount()
    { return 2; }

// the two necromantic third level spells - death's door, speak w/ dead
inline int dhvL3NecromanticCount()
    { return 2; }

// the one invocation third level spell - dream vision; the school debuting
// this level
inline int dhvL3InvocationCount()
    { return 1; }

// the one illusion/phantasm third level spell - invisibility to spirits; the
// school debuting this level
inline int dhvL3IllusionCount()
    { return 1; }

// the one enchantment/charm third level spell - possess animal
inline int dhvL3EnchCharmCount()
    { return 1; }

// the fourteen third level spells taking all three components - the bitmask
// reads 7
inline int dhvL3VSMCount()
    { return 14; }

// the six third level spells taking verbal and somatic - the bitmask reads 3
inline int dhvL3VSCount()
    { return 6; }

// the five third level spells with a one-turn casting time - cure disease,
// divination, dream vision, invisibility to spirits, speak w/ dead
inline int dhvL3TurnCasts()
    { return 5; }

// the one third level spell with a three-turn casting time - substitution,
// the longest cast in the level
inline int dhvL3ThreeTurnCasts()
    { return 1; }

// the six third level spells with a one-round casting time
inline int dhvL3RoundCasts()
    { return 6; }

// the four third level spells with a six-segment casting time - dispel magic,
// prayer, remove curse, remove paralysis
inline int dhvL3SixSegmentCasts()
    { return 4; }

// the three third level spells with a negation saving throw - levitate, oath,
// possess animal
inline int dhvL3NegSaves()
    { return 3; }

// the two third level spells with a special saving throw - castigate, remove
// curse
inline int dhvL3SpecialSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 3rd level spell schools by ordinal (print pp. 126-132;
// compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2
// cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel
// magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to
// spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15
// possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak
// w/ dead, 20 substitution - the school codes: 1 enchantment/charm, 2
// divination, 3 evocation, 4 conjuration/summoning, 5 necromantic, 6
// alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - invocation
// and illusion/phantasm debuting this level (dream vision, invisibility to
// spirits); abjuration the most common at seven spells; magical vestment pins
// its dual school conjuration/alteration as the primary 4
inline int dhvL3School(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 5;
        case 4:
            return 2;
        case 5:
            return 7;
        case 6:
            return 2;
        case 7:
            return 8;
        case 8:
            return 6;
        case 9:
            return 9;
        case 10:
            return 2;
        case 11:
            return 6;
        case 12:
            return 4;
        case 13:
            return 7;
        case 14:
            return 1;
        case 15:
            return 4;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 5;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// the shukenja 3rd level spell components by ordinal (print pp. 126-132;
// compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2
// cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel
// magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to
// spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15
// possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak
// w/ dead, 20 substitution - the component codes a bitmask: verbal 1, somatic
// 2, material 4 - fourteen spells take all three (7), six take verbal and
// somatic (3): cure blindness, cure disease, dispel magic, know alignment,
// remove curse, remove paralysis
inline int dhvL3Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 3;
        case 2:
            return 3;
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
            return 7;
        case 9:
            return 7;
        case 10:
            return 3;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 7;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// the shukenja 3rd level spell casting times by ordinal (print pp. 126-132;
// compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2
// cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel
// magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to
// spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15
// possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak
// w/ dead, 20 substitution - the casting time in segments - 1 round = 10
// segments, 1 turn = 60, 3 turns = 180: substitution takes the three turns
// (the longest cast in the level), five spells take a turn (cure disease,
// divination, dream vision, invisibility to spirits, speak w/ dead), six a
// round, four take six segments (dispel magic, prayer, remove curse, remove
// paralysis), and the level runs down to levitate's two segments (castigate
// three, death's door and flame walk five)
inline int dhvL3CastTime(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 10;
        case 2:
            return 60;
        case 3:
            return 5;
        case 4:
            return 10;
        case 5:
            return 6;
        case 6:
            return 60;
        case 7:
            return 60;
        case 8:
            return 5;
        case 9:
            return 60;
        case 10:
            return 10;
        case 11:
            return 2;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 10;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 6;
        case 18:
            return 60;
        case 19:
            return 180;
        default:
            return 0;
        }
    }

// the shukenja 3rd level spell saving throws by ordinal (print pp. 126-132;
// compressed pp. 63-66). The spell list rides this comment: 1 castigate, 2
// cure blindness, 3 cure disease, 4 death's door, 5 detect curse, 6 dispel
// magic, 7 divination, 8 dream vision, 9 flame walk, 10 invisibility to
// spirits, 11 know alignment, 12 levitate, 13 magical vestment, 14 oath, 15
// possess animal, 16 prayer, 17 remove curse, 18 remove paralysis, 19 speak
// w/ dead, 20 substitution - the saving throw codes: 0 none, 1 neg., 2
// special - levitate, oath and possess animal are neg., castigate and remove
// curse are special, the other fifteen none
inline int dhvL3Save(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 1;
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
        default:
            return 0;
        }
    }

// the shukenja 3rd level spell reversible markers by ordinal (print pp.
// 126-132; compressed pp. 63-66). The spell list rides this comment: 1
// castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect
// curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10
// invisibility to spirits, 11 know alignment, 12 levitate, 13 magical
// vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove
// paralysis, 19 speak w/ dead, 20 substitution - the cell is 1 where the
// printed header reads Reversible - cure blindness, cure disease, dream
// vision, know alignment, oath, remove curse, remove paralysis; the seven
// matching the R658 T62 reversible column
inline int dhvL3Reversible(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
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
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
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
        default:
            return 0;
        }
    }

// the shukenja 3rd level spell sohei-usable markers by ordinal (print pp.
// 126-132; compressed pp. 63-66). The spell list rides this comment: 1
// castigate, 2 cure blindness, 3 cure disease, 4 death's door, 5 detect
// curse, 6 dispel magic, 7 divination, 8 dream vision, 9 flame walk, 10
// invisibility to spirits, 11 know alignment, 12 levitate, 13 magical
// vestment, 14 oath, 15 possess animal, 16 prayer, 17 remove curse, 18 remove
// paralysis, 19 speak w/ dead, 20 substitution - the cell is 1 where the
// printed asterisk marks the spell usable by sohei - castigate, dispel magic,
// flame walk, prayer; the four matching the R658 T62 sohei column
inline int dhvL3Sohei(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
