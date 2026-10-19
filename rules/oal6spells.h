// =========================================================================================
// Adnd1 - rules/oal6spells.h
// SIXTH LEVEL SPELLS, printed capture pp. 143-147 - the OA sixth level spells
// round
// census 586 -> 587.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 12 sixth
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 143-147; compressed pp. 69-72); all 12 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. Force
// shapechange's components read V, S, M in the compressed, the print line
// cutting at its page boundary - the R660 detect charm pattern. The level
// runs the widest cast spread in the chapter: three single-segment casts
// (force shapechange, immunity to weapons, smite) up through longevity's
// one-day cast, pinned as 8640 segments (60 per turn, 144 turns per day, the
// turn=60 convention) - and instruct takes three turns, find the path three
// rounds. Two spells take the half save (force shapechange, smite), longevity
// the special. Alteration is the most common school at five spells, with the
// other seven appearing schools exactly once each (no invocation this level).
// The reversible flags agree between the passes; the sohei-usable marks ride
// the R658 T62 grid. The stat grid pins as a table: 12 rows the spell
// ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting
// time in segments (1 round = 10, 1 turn = 60, 3 turns = 180, 1 day = 8640),
// saving throw code (0 none, 1 neg., 2 special, 3 half), reversible and sohei
// markers. The spell names ride the column comments, the prose descriptions
// close in their own rounds. The table tag L6Data identifier-safe per the
// R639 lesson
//
// the gap census after this round: 117 closed, 118 open - the Sixth Level
// Spells box flips (census 586 -> 587); NEXT - R665: the Seventh Level Spells
// (capture pp. 147-152), prefix dhz (verify free), audit "R665 OA seventh
// level spells audit", include after rules/oal6spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 12 sixth level shukenja spells (print pp. 143-147; compressed pp.
// 69-72)
inline int dhyL6SpellCount()
    { return 12; }

// the four sixth level spells usable by sohei - find the path, immunity to
// weapons, smite, speak w/ monsters
inline int dhyL6SoheiCount()
    { return 4; }

// the four reversible sixth level spells - find the path, heal, immunity to
// weapons, quickgrowth
inline int dhyL6ReversibleCount()
    { return 4; }

// the five alteration sixth level spells - the most common school of the
// level: immunity to weapons, longevity, plane shift, quickgrowth, speak w/
// monsters
inline int dhyL6AlterationCount()
    { return 5; }

// the eight sixth level spells taking all three components - the bitmask
// reads 7
inline int dhyL6VSMCount()
    { return 8; }

// the three sixth level spells taking verbal and somatic - heal, immunity to
// weapons, speak w/ monsters; the bitmask reads 3
inline int dhyL6VSCount()
    { return 3; }

// the one sixth level spell taking the verbal component only - instruct
inline int dhyL6VerbalOnlyCount()
    { return 1; }

// the one sixth level spell with a one-day casting time - longevity, the
// longest cast in the chapter, pinned as 8640 segments (60 per turn, 144
// turns per day)
inline int dhyL6DayCasts()
    { return 1; }

// the one sixth level spell with a three-turn casting time - instruct
inline int dhyL6ThreeTurnCasts()
    { return 1; }

// the one sixth level spell with a three-round casting time - find the path
inline int dhyL6ThreeRoundCasts()
    { return 1; }

// the four sixth level spells with a one-round casting time - heal, inanimate
// servant, invisibility to enemies, quickgrowth
inline int dhyL6RoundCasts()
    { return 4; }

// the three sixth level spells with a one-segment casting time - force
// shapechange, immunity to weapons, smite
inline int dhyL6OneSegmentCasts()
    { return 3; }

// the two sixth level spells with a negation saving throw - instruct, plane
// shift
inline int dhyL6NegSaves()
    { return 2; }

// the one sixth level spell with a special saving throw - longevity (the
// system shock roll)
inline int dhyL6SpecialSaves()
    { return 1; }

// the two sixth level spells with the half saving throw code - force
// shapechange, smite; a successful save halving the damage
inline int dhyL6HalfSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 6th level spell schools by ordinal (print pp. 143-147;
// compressed pp. 69-72). The spell list rides this comment: 1 find the path,
// 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6
// instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10
// quickgrowth, 11 smite, 12 speak w/ monsters - the school codes: 1
// enchantment/charm, 2 divination, 3 evocation, 4 conjuration/summoning, 5
// necromantic, 6 alteration, 7 abjuration, 9 illusion/phantasm - alteration
// the most common at five spells (immunity to weapons, longevity, plane
// shift, quickgrowth, speak w/ monsters); the other seven schools appear
// exactly once each; no invocation spell this level
inline int dhyL6School(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 7;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 4;
        case 5:
            return 1;
        case 6:
            return 9;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 6;
        case 10:
            return 3;
        case 11:
            return 6;
        default:
            return 0;
        }
    }

// the shukenja 6th level spell components by ordinal (print pp. 143-147;
// compressed pp. 69-72). The spell list rides this comment: 1 find the path,
// 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6
// instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10
// quickgrowth, 11 smite, 12 speak w/ monsters - the component codes a
// bitmask: verbal 1, somatic 2, material 4 - eight spells take all three (7),
// three take verbal and somatic (3): heal, immunity to weapons, speak w/
// monsters; instruct takes the verbal only (1); force shapechange reads V, S,
// M in the compressed (the print line cutting at its page boundary)
inline int dhyL6Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 1;
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
            return 3;
        default:
            return 0;
        }
    }

// the shukenja 6th level spell casting times by ordinal (print pp. 143-147;
// compressed pp. 69-72). The spell list rides this comment: 1 find the path,
// 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6
// instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10
// quickgrowth, 11 smite, 12 speak w/ monsters - the casting time in segments
// - 1 round = 10 segments, 1 turn = 60, 3 turns = 180, 3 rounds = 30, and
// longevity's 1 day pinned as 8640 (60 segments per turn, 144 turns per day,
// the turn=60 convention): find the path takes three rounds, instruct three
// turns, four spells a round (heal, inanimate servant, invisibility to
// enemies, quickgrowth), plane shift eight segments, speak w/ monsters nine,
// and three cast in a single segment (force shapechange, immunity to weapons,
// smite)
inline int dhyL6CastTime(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 1;
        case 2:
            return 10;
        case 3:
            return 1;
        case 4:
            return 10;
        case 5:
            return 180;
        case 6:
            return 10;
        case 7:
            return 8640;
        case 8:
            return 8;
        case 9:
            return 10;
        case 10:
            return 1;
        case 11:
            return 9;
        default:
            return 0;
        }
    }

// the shukenja 6th level spell saving throws by ordinal (print pp. 143-147;
// compressed pp. 69-72). The spell list rides this comment: 1 find the path,
// 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate servant, 6
// instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift, 10
// quickgrowth, 11 smite, 12 speak w/ monsters - the saving throw codes: 0
// none, 1 neg., 2 special, 3 half - instruct and plane shift are neg.,
// longevity is special, force shapechange and smite take the half code (a
// successful save halving the damage), the other seven none
inline int dhyL6Save(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 3;
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
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// the shukenja 6th level spell reversible markers by ordinal (print pp.
// 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find
// the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate
// servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift,
// 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the
// printed header reads Reversible - find the path, heal, immunity to weapons,
// quickgrowth; the four matching the R658 T62 reversible column
inline int dhyL6Reversible(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
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
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// the shukenja 6th level spell sohei-usable markers by ordinal (print pp.
// 143-147; compressed pp. 69-72). The spell list rides this comment: 1 find
// the path, 2 force shapechange, 3 heal, 4 immunity to weapons, 5 inanimate
// servant, 6 instruct, 7 invisibility to enemies, 8 longevity, 9 plane shift,
// 10 quickgrowth, 11 smite, 12 speak w/ monsters - the cell is 1 where the
// printed asterisk marks the spell usable by sohei - find the path, immunity
// to weapons, smite, speak w/ monsters; the four matching the R658 T62 sohei
// column
inline int dhyL6Sohei(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
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
        default:
            return 0;
        }
    }

}   // namespace rules
