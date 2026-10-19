// =========================================================================================
// Adnd1 - rules/oal4spells.h
// FOURTH LEVEL SPELLS, printed capture pp. 132-140 - the OA fourth level
// spells round
// census 584 -> 585.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 20 fourth
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 132-140; compressed pp. 66-69); all 20 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. Three
// component singles dot the level: polymorph self takes the verbal only,
// endurance the somatic and material, reward the verbal and material - all
// three read identically in the two passes. Two new encodings debut: the
// exorcise cast is variable (1-100+ turns, the only unfixed cast in the
// chapter) and pins as -1, and the snake barrier save reads 1/2 - the print
// garbling it as 112, the compressed reading it clean - pinning as the new
// half code 3. Fate takes the longest fixed cast at six turns. Alteration is
// the most common school at seven spells; abjure's dual school
// abjuration/conjuration pins as the primary abjuration. The reversible flags
// agree between the passes; the sohei-usable marks ride the R658 T62 grid.
// The stat grid pins as a table: 20 rows the spell ordinals, six columns -
// school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1
// round = 10, 1 turn = 60, 6 turns = 360, -1 the variable cast), saving throw
// code (0 none, 1 neg., 2 special, 3 half), reversible and sohei markers. The
// spell names ride the column comments, the prose descriptions and the Table
// 65 fate grid close in their own rounds. The table tag L4Data
// identifier-safe per the R639 lesson
//
// the gap census after this round: 115 closed, 120 open - the Fourth Level
// Spells box flips (census 584 -> 585); NEXT - R663: the Fifth Level Spells
// (capture pp. 140-143), prefix dhx (verify free), audit "R663 OA fifth level
// spells audit", include after rules/oal4spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 20 fourth level shukenja spells (print pp. 132-140; compressed pp.
// 66-69)
inline int dhwL4SpellCount()
    { return 20; }

// the three fourth level spells usable by sohei - endurance, penetrate
// disguise, spell immunity
inline int dhwL4SoheiCount()
    { return 3; }

// the seven reversible fourth level spells - abjure, cure serious wounds,
// detect lie, endurance, neutralize poison, protection from evil 10', tongues
inline int dhwL4ReversibleCount()
    { return 7; }

// the seven alteration fourth level spells - the most common school of the
// level: endurance, neutralize poison, pacify, polymorph self, speak w/
// plants, sustain, tongues
inline int dhwL4AlterationCount()
    { return 7; }

// the five abjuration fourth level spells - abjure, exorcise, protection from
// evil 10', remorse, spell immunity
inline int dhwL4AbjurationCount()
    { return 5; }

// the four divination fourth level spells - detect lie, detect shapechanger,
// fate, penetrate disguise
inline int dhwL4DivinationCount()
    { return 4; }

// the two necromantic fourth level spells - cure serious wounds, reanimation
inline int dhwL4NecromanticCount()
    { return 2; }

// the one conjuration fourth level spell - reward
inline int dhwL4ConjurationCount()
    { return 1; }

// the one evocation fourth level spell - snake barrier
inline int dhwL4EvocationCount()
    { return 1; }

// the twelve fourth level spells taking all three components - the bitmask
// reads 7
inline int dhwL4VSMCount()
    { return 12; }

// the five fourth level spells taking verbal and somatic - the bitmask reads
// 3
inline int dhwL4VSCount()
    { return 5; }

// the one fourth level spell taking the verbal component only - polymorph
// self
inline int dhwL4VerbalOnlyCount()
    { return 1; }

// the one fourth level spell taking somatic and material only - endurance
inline int dhwL4SMCount()
    { return 1; }

// the one fourth level spell taking verbal and material - reward
inline int dhwL4VMCount()
    { return 1; }

// the three fourth level spells with a one-turn casting time - endurance,
// reward, speak w/ plants
inline int dhwL4TurnCasts()
    { return 3; }

// the one fourth level spell with a six-turn casting time - fate, the longest
// fixed cast in the level
inline int dhwL4SixTurnCasts()
    { return 1; }

// the one fourth level spell with a variable casting time - exorcise at
// 1-100+ turns, the only unfixed cast in the chapter, pinned as -1
inline int dhwL4VariableCasts()
    { return 1; }

// the six fourth level spells with a one-round casting time
inline int dhwL4RoundCasts()
    { return 6; }

// the three fourth level spells with a negation saving throw - abjure,
// penetrate disguise, remorse
inline int dhwL4NegSaves()
    { return 3; }

// the one fourth level spell with the half saving throw code - snake barrier;
// the code debuting this level (the print garbling the 1/2 as 112, the
// compressed reading it clean)
inline int dhwL4HalfSaves()
    { return 1; }

// ---- the stat grid pins ----

// the shukenja 4th level spell schools by ordinal (print pp. 132-140;
// compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure
// serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6
// exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11
// polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15
// reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19
// sustain, 20 tongues - the school codes: 1 enchantment/charm, 2 divination,
// 3 evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7
// abjuration - alteration the most common at seven spells; abjure pins its
// dual school abjuration/conjuration as the primary abjuration
inline int dhwL4School(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 5;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 2;
        case 7:
            return 6;
        case 8:
            return 6;
        case 9:
            return 2;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 5;
        case 13:
            return 7;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 6;
        case 17:
            return 7;
        case 18:
            return 6;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// the shukenja 4th level spell components by ordinal (print pp. 132-140;
// compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure
// serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6
// exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11
// polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15
// reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19
// sustain, 20 tongues - the component codes a bitmask: verbal 1, somatic 2,
// material 4 - twelve spells take all three (7), five take verbal and somatic
// (3), and three singles dot the level: polymorph self the verbal only (1),
// endurance the somatic and material (6), reward the verbal and material (5)
inline int dhwL4Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 5;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 3;
        default:
            return 0;
        }
    }

// the shukenja 4th level spell casting times by ordinal (print pp. 132-140;
// compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure
// serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6
// exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11
// polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15
// reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19
// sustain, 20 tongues - the casting time in segments - 1 round = 10 segments,
// 1 turn = 60, 6 turns = 360, and the exorcise cast is variable (1-100+
// turns, the only unfixed cast in the chapter) pinned as -1: fate takes the
// six turns, three spells take a turn (endurance, reward, speak w/ plants),
// penetrate disguise takes two rounds, six a round, five take seven segments,
// pacify and snake barrier four, polymorph self three
inline int dhwL4CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 7;
        case 2:
            return 7;
        case 3:
            return 10;
        case 4:
            return 60;
        case 5:
            return -1;
        case 6:
            return 360;
        case 7:
            return 7;
        case 8:
            return 4;
        case 9:
            return 20;
        case 10:
            return 3;
        case 11:
            return 7;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 60;
        case 15:
            return 4;
        case 16:
            return 60;
        case 17:
            return 10;
        case 18:
            return 10;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// the shukenja 4th level spell saving throws by ordinal (print pp. 132-140;
// compressed pp. 66-69). The spell list rides this comment: 1 abjure, 2 cure
// serious wounds, 3 detect lie, 4 detect shapechanger, 5 endurance, 6
// exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate disguise, 11
// polymorph self, 12 protection from evil 10', 13 reanimation, 14 remorse, 15
// reward, 16 snake barrier, 17 speak w/ plants, 18 spell immunity, 19
// sustain, 20 tongues - the saving throw codes: 0 none, 1 neg., 2 special, 3
// half - the half code debuting on snake barrier (the print garbling the 1/2
// as 112, the compressed reading it clean; a successful save halves the
// damage); abjure, penetrate disguise and remorse are neg., reanimation
// special, the other fifteen none
inline int dhwL4Save(int b)
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
        case 12:
            return 2;
        case 13:
            return 1;
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
        default:
            return 0;
        }
    }

// the shukenja 4th level spell reversible markers by ordinal (print pp.
// 132-140; compressed pp. 66-69). The spell list rides this comment: 1
// abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5
// endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate
// disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation,
// 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell
// immunity, 19 sustain, 20 tongues - the cell is 1 where the printed header
// reads Reversible - abjure, cure serious wounds, detect lie, endurance,
// neutralize poison, protection from evil 10', tongues; the seven matching
// the R658 T62 reversible column
inline int dhwL4Reversible(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
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
            return 1;
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
            return 1;
        default:
            return 0;
        }
    }

// the shukenja 4th level spell sohei-usable markers by ordinal (print pp.
// 132-140; compressed pp. 66-69). The spell list rides this comment: 1
// abjure, 2 cure serious wounds, 3 detect lie, 4 detect shapechanger, 5
// endurance, 6 exorcise, 7 fate, 8 neutralize poison, 9 pacify, 10 penetrate
// disguise, 11 polymorph self, 12 protection from evil 10', 13 reanimation,
// 14 remorse, 15 reward, 16 snake barrier, 17 speak w/ plants, 18 spell
// immunity, 19 sustain, 20 tongues - the cell is 1 where the printed asterisk
// marks the spell usable by sohei - endurance, penetrate disguise, spell
// immunity; the three matching the R658 T62 sohei column (tongues reversible
// but not sohei-usable)
inline int dhwL4Sohei(int b)
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
            return 1;
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
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
