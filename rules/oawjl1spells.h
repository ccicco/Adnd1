// =========================================================================================
// Adnd1 - rules/oawjl1spells.h
// WU JEN FIRST LEVEL SPELLS, printed capture pp. 155-165 - the OA wu jen
// first level spells round
// census 592 -> 593.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 155-165; compressed pp. 75-79); all 30 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the variances are
// typographic (the print's fumble-lingers against the compressed
// fumble-fingers for the prestidigitation reverse, the print's pared for
// para-elemental in the melt prose). The level is alteration-heavy: 15 of the
// 30 spells, conjuration six, divination three, enchantment/charm, evocation
// and illusion two each - no necromantic or abjuration. The component census
// carries two oddities pinned as cells: ventriloquism the lone V,M without
// the somatic (bitmask 5), and secret signs the Components: Special line
// (bitmask 0, none of the three - the component is whatever method sends the
// message, the spell castable even bound and gagged). Elemental burst alone
// takes the half save (the sliver and spark damage halved); drowsy insects
// and hypnotism the negation saves; four the special. The casting times run
// 13 one-segment up through 12 one-round, with warp wood the lone
// four-segment and fiery eyes and ghost light the five-segment pair. Six
// spells read Reversible (accuracy, comprehend languages, prestidigitation,
// read magic, still water, swim). The sixth column cross-checks the R669
// element grid: the 12 tagged cells matching the landed dieWJT66L1Element
// pins exactly. The stat grid pins as a table: 30 rows the spell ordinals,
// six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in
// segments (1 round = 10), saving throw code (0 none, 1 neg., 2 special, 3
// half), reversible and element markers. The spell names ride the column
// comments, the prose descriptions close in their own rounds. The table tag
// WJL1Data identifier-safe per the R639 lesson
//
// the gap census after this round: 123 closed, 112 open - the wu jen First
// Level Spells box flips (census 592 -> 593); NEXT - R671: the wu jen Second
// Level Spells (capture pp. 165-170, the 30 stat blocks), prefix dig (verify
// free), audit "R671 OA wu jen second level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 30 first level wu jen spells (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1SpellCount()
    { return 30; }

// the six reversible first level wu jen spells - accuracy, comprehend
// languages, prestidigitation, read magic, still water, swim (print pp.
// 155-165; compressed pp. 75-79)
inline int difWJL1ReversibleCount()
    { return 6; }

// the 15 alteration first level wu jen spells - half the level, the most
// common school (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1AlterationCount()
    { return 15; }

// the three divination first level wu jen spells - detect magic, know
// history, read magic (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1DivinationCount()
    { return 3; }

// the six conjuration first level wu jen spells - drowsy insects, elemental
// burst, ghost light, hail of stone, prestidigitation, unseen servant
// (printed Conjuration or Conjuration/Summoning, both pinned code 4) (print
// pp. 155-165; compressed pp. 75-79)
inline int difWJL1ConjurationCount()
    { return 6; }

// the 20 first level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1VSMCount()
    { return 20; }

// the seven first level wu jen spells taking verbal and somatic - detect
// magic, elemental burst, fiery eyes, hypnotism, know history, magic missile,
// shield; the bitmask reads 3 (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1VSCount()
    { return 7; }

// the one first level wu jen spell taking the verbal component only - hold
// portal (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1VerbalOnlyCount()
    { return 1; }

// the one first level wu jen spell taking verbal and material without the
// somatic - ventriloquism; the bitmask reads 5 (print pp. 155-165; compressed
// pp. 75-79)
inline int difWJL1VMCount()
    { return 1; }

// the one first level wu jen spell with the Components: Special line - secret
// signs, the component being whatever method sends the message; pinned
// bitmask 0, none of the three (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1SpecialCompCount()
    { return 1; }

// the 12 first level wu jen spells with a one-round casting time (print pp.
// 155-165; compressed pp. 75-79)
inline int difWJL1RoundCasts()
    { return 12; }

// the 13 first level wu jen spells with a one-segment casting time - the most
// common cast of the level (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1OneSegmentCasts()
    { return 13; }

// the two first level wu jen spells with a three-segment casting time -
// elemental burst, prestidigitation (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1ThreeSegmentCasts()
    { return 2; }

// the one first level wu jen spell with a four-segment casting time - warp
// wood (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1FourSegmentCasts()
    { return 1; }

// the two first level wu jen spells with a five-segment casting time - fiery
// eyes, ghost light (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1FiveSegmentCasts()
    { return 2; }

// the two first level wu jen spells with a negation saving throw - drowsy
// insects, hypnotism (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1NegSaves()
    { return 2; }

// the four first level wu jen spells with a special saving throw - know
// history, melt, prestidigitation, still water (print pp. 155-165; compressed
// pp. 75-79)
inline int difWJL1SpecialSaves()
    { return 4; }

// the one first level wu jen spell with the half saving throw code -
// elemental burst, the sliver and spark damage halved on a successful save
// (print pp. 155-165; compressed pp. 75-79)
inline int difWJL1HalfSaves()
    { return 1; }

// ---- the stat grid pins ----

// the wu jen 1st level spell schools by ordinal (print pp. 155-165;
// compressed pp. 75-79). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the school codes: 1 enchantment/charm, 2
// divination, 3 evocation, 4 conjuration (the printed Conjuration and
// Conjuration/Summoning both pinned 4), 6 alteration, 9 illusion/phantasm -
// alteration the most common school at 15 spells (animate wood, cloud ladder,
// comprehend languages, fiery eyes, hold portal, melt, message, secret signs,
// spider climb, still water, swim, wall of fog, warp wood, water protection,
// wizard mark); conjuration six, divination three; enchantment/charm,
// evocation and illusion two each; no necromantic or abjuration spell this
// level
inline int difWJL1School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 9;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 6;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 6;
        case 20:
            return 3;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 4;
        case 25:
            return 9;
        case 26:
            return 6;
        case 27:
            return 6;
        case 28:
            return 6;
        case 29:
            return 6;
        default:
            return 0;
        }
    }

// the wu jen 1st level spell components by ordinal (print pp. 155-165;
// compressed pp. 75-79). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the component codes a bitmask: verbal 1,
// somatic 2, material 4 - 20 spells take all three (7), seven verbal and
// somatic (3): detect magic, elemental burst, fiery eyes, hypnotism, know
// history, magic missile, shield; hold portal the verbal only (1);
// ventriloquism the verbal and material without the somatic (5); secret signs
// the Components: Special oddity (0, none of the three - the component is
// whatever method sends the message, the spell castable even bound and
// gagged)
inline int difWJL1Components(int b)
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
            return 3;
        case 8:
            return 3;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 3;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 5;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 7;
        case 29:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 1st level spell casting times by ordinal (print pp. 155-165;
// compressed pp. 75-79). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the casting time in segments - 1 round = 10
// segments: 12 spells a round, 13 a single segment (the most common cast of
// the level), elemental burst and prestidigitation three segments, fiery eyes
// and ghost light five, warp wood four
inline int difWJL1CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 1;
        case 6:
            return 10;
        case 7:
            return 3;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 10;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 10;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 10;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 10;
        case 23:
            return 10;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 4;
        case 28:
            return 10;
        case 29:
            return 1;
        default:
            return 0;
        }
    }

// the wu jen 1st level spell saving throws by ordinal (print pp. 155-165;
// compressed pp. 75-79). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the saving throw codes: 0 none, 1 neg., 2
// special, 3 half - drowsy insects and hypnotism neg.; know history, melt,
// prestidigitation and still water special; elemental burst the lone half
// code (the sliver and spark damage halved on a successful save); the other
// 23 none
inline int difWJL1Save(int b)
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
            return 1;
        case 7:
            return 3;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 2;
        case 14:
            return 0;
        case 15:
            return 2;
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
            return 2;
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

// the wu jen 1st level spell reversible markers by ordinal (print pp.
// 155-165; compressed pp. 75-79). The spell list rides this comment: 1
// accuracy, 2 animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend
// languages, 6 detect magic, 7 drowsy insects, 8 elemental burst, 9 fiery
// eyes, 10 ghost light, 11 hail of stone, 12 hold portal, 13 hypnotism, 14
// know history, 15 magic missile, 16 melt, 17 message, 18 prestidigitation,
// 19 read magic, 20 secret signs, 21 shield, 22 spider climb, 23 still water,
// 24 swim, 25 unseen servant, 26 ventriloquism, 27 wall of fog, 28 warp wood,
// 29 water protection, 30 wizard mark - the cell is 1 where the printed
// header reads Reversible - accuracy (inaccuracy), comprehend languages
// (confuse languages), prestidigitation (fumble-fingers), read magic
// (unreadable magic), still water (turbulence), swim (sinking); the six
inline int difWJL1Reversible(int b)
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
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 1;
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

// the wu jen 1st level spell element marks by ordinal (print pp. 155-165;
// compressed pp. 75-79). The spell list rides this comment: 1 accuracy, 2
// animate wood, 3 chameleon, 4 cloud ladder, 5 comprehend languages, 6 detect
// magic, 7 drowsy insects, 8 elemental burst, 9 fiery eyes, 10 ghost light,
// 11 hail of stone, 12 hold portal, 13 hypnotism, 14 know history, 15 magic
// missile, 16 melt, 17 message, 18 prestidigitation, 19 read magic, 20 secret
// signs, 21 shield, 22 spider climb, 23 still water, 24 swim, 25 unseen
// servant, 26 ventriloquism, 27 wall of fog, 28 warp wood, 29 water
// protection, 30 wizard mark - the element codes of the R669 T66 grid: 0
// none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the 12
// tagged spells (animate wood and drowsy insects Nature, cloud ladder and
// wall of fog Air, elemental burst All, fiery eyes and melt Fire, hail of
// stone Earth, still water, swim and water protection Water, warp wood the
// lone Wood mark) matching the R669 dieWJT66L1Element pins exactly - the
// cross-check column
inline int difWJL1Element(int b)
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

}   // namespace rules
