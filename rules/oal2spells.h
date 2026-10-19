// =========================================================================================
// Adnd1 - rules/oal2spells.h
// SECOND LEVEL SPELLS, printed capture pp. 119-126 - the OA second level
// spells round
// census 582 -> 583.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 20 second
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 119-125; compressed pp. 60-63); all 20 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. Two reads
// worth the note: detect charm's components read V, S in both passes (the
// print line breaking at its page boundary, the compressed confirming), and
// dream sight takes the somatic and material components only - the level's
// unique no-verbal spell. The abjuration school debuts this level (protection
// from spirits, request), and aid's dual school necromantic/conjuration pins
// as the primary necromantic. Request takes the longest cast in the level at
// three turns. The reversible flags agree between the passes; the
// sohei-usable marks ride the R658 T62 grid, settled two rounds before. The
// stat grid pins as a table: 20 rows the spell ordinals, six columns -
// school, components (a V=1 S=2 M=4 bitmask), casting time in segments (1
// round = 10, 1 turn = 60, 3 turns = 180), saving throw code (0 none, 1 neg.,
// 2 special), reversible and sohei markers. The spell names ride the column
// comments, the prose descriptions close in their own rounds. The table tag
// L2Data identifier-safe per the R639 lesson
//
// the gap census after this round: 113 closed, 122 open - the Second Level
// Spells box flips (census 582 -> 583); NEXT - R661: the Third Level Spells
// (capture pp. 126-132), prefix dhv (verify free), audit "R661 OA third level
// spells audit", include after rules/oal2spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 20 second level shukenja spells (print pp. 119-125; compressed pp.
// 60-63)
inline int dhuL2SpellCount()
    { return 20; }

// the four second level spells usable by sohei - chant, messenger, slow
// poison, warning
inline int dhuL2SoheiCount()
    { return 4; }

// the three reversible second level spells - create spring, detect charm,
// know motivation
inline int dhuL2ReversibleCount()
    { return 3; }

// the five divination second level spells - commune with lesser spirit,
// detect charm, detect life, know motivation, warning
inline int dhuL2DivinationCount()
    { return 5; }

// the four enchantment/charm second level spells - enthrall, hold person,
// messenger, snake summoning
inline int dhuL2EnchCharmCount()
    { return 4; }

// the five alteration second level spells - create spring, dream sight,
// obscurement, speak w/ animals, withdraw
inline int dhuL2AlterationCount()
    { return 5; }

// the two abjuration second level spells - protection from spirits and
// request; the school debuting this level
inline int dhuL2AbjurationCount()
    { return 2; }

// the thirteen second level spells taking all three components - the bitmask
// reads 7
inline int dhuL2VSMCount()
    { return 13; }

// the six second level spells taking verbal and somatic - the bitmask reads 3
inline int dhuL2VSCount()
    { return 6; }

// the one second level spell taking somatic and material only - dream sight,
// the unique no-verbal spell
inline int dhuL2SMCount()
    { return 1; }

// the three second level spells with a one-turn casting time - chant, commune
// with lesser spirit, holy symbol
inline int dhuL2TurnCasts()
    { return 3; }

// the one second level spell with a three-turn casting time - request, the
// longest cast in the level
inline int dhuL2ThreeTurnCasts()
    { return 1; }

// the nine second level spells with a one-round casting time
inline int dhuL2RoundCasts()
    { return 9; }

// the four second level spells with a negation saving throw - enthrall, hold
// person, messenger, request
inline int dhuL2NegSaves()
    { return 4; }

// the two second level spells with a special saving throw - protection from
// spirits, snake summoning
inline int dhuL2SpecialSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 2nd level spell schools by ordinal (print pp. 119-125;
// compressed pp. 60-63). The spell list rides this comment: 1 aid, 2 chant, 3
// commune w/ lesser spirit, 4 create spring, 5 detect charm, 6 detect life, 7
// dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11 know motivation,
// 12 messenger, 13 obscurement, 14 protection from spirits, 15 request, 16
// slow poison, 17 snake summoning, 18 speak w/ animals, 19 warning, 20
// withdraw - the school codes: 1 enchantment/charm, 2 divination, 3
// evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7
// abjuration - the abjuration code debuting this level (protection from
// spirits, request); five divination, five alteration and four
// enchantment/charm spells; aid pins its dual school necromantic/conjuration
// as the primary 5
inline int dhuL2School(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 6;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 5;
        case 16:
            return 1;
        case 17:
            return 6;
        case 18:
            return 2;
        case 19:
            return 6;
        default:
            return 0;
        }
    }

// the shukenja 2nd level spell components by ordinal (print pp. 119-125;
// compressed pp. 60-63). The spell list rides this comment: 1 aid, 2 chant, 3
// commune w/ lesser spirit, 4 create spring, 5 detect charm, 6 detect life, 7
// dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11 know motivation,
// 12 messenger, 13 obscurement, 14 protection from spirits, 15 request, 16
// slow poison, 17 snake summoning, 18 speak w/ animals, 19 warning, 20
// withdraw - the component codes a bitmask: verbal 1, somatic 2, material 4 -
// thirteen spells take all three (7), six take verbal and somatic (3), and
// dream sight takes the somatic and material only (6), the unique no-verbal
// spell; detect charm reads V, S in both passes (the print line breaking at
// its page boundary)
inline int dhuL2Components(int b)
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
            return 3;
        case 5:
            return 7;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 3;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 3;
        case 18:
            return 3;
        case 19:
            return 7;
        default:
            return 0;
        }
    }

// the shukenja 2nd level spell casting times by ordinal (print pp. 119-125;
// compressed pp. 60-63). The spell list rides this comment: 1 aid, 2 chant, 3
// commune w/ lesser spirit, 4 create spring, 5 detect charm, 6 detect life, 7
// dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11 know motivation,
// 12 messenger, 13 obscurement, 14 protection from spirits, 15 request, 16
// slow poison, 17 snake summoning, 18 speak w/ animals, 19 warning, 20
// withdraw - the casting time in segments - 1 round = 10 segments, 1 turn =
// 60, 3 turns = 180: request takes the three turns (the longest cast in the
// level), chant, commune with lesser spirit and holy symbol take a turn, nine
// take a round, and the level runs down to slow poison's single segment
// (warning two, withdraw three, aid and obscurement four, hold person and
// speak w/ animals five)
inline int dhuL2CastTime(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 60;
        case 2:
            return 60;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 5;
        case 9:
            return 60;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 4;
        case 13:
            return 10;
        case 14:
            return 180;
        case 15:
            return 1;
        case 16:
            return 10;
        case 17:
            return 5;
        case 18:
            return 2;
        case 19:
            return 3;
        default:
            return 0;
        }
    }

// the shukenja 2nd level spell saving throws by ordinal (print pp. 119-125;
// compressed pp. 60-63). The spell list rides this comment: 1 aid, 2 chant, 3
// commune w/ lesser spirit, 4 create spring, 5 detect charm, 6 detect life, 7
// dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11 know motivation,
// 12 messenger, 13 obscurement, 14 protection from spirits, 15 request, 16
// slow poison, 17 snake summoning, 18 speak w/ animals, 19 warning, 20
// withdraw - the saving throw codes: 0 none, 1 neg., 2 special - enthrall,
// hold person, messenger and request are neg., protection from spirits and
// snake summoning are special, the other fourteen none
inline int dhuL2Save(int b)
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
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 2;
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

// the shukenja 2nd level spell reversible markers by ordinal (print pp.
// 119-125; compressed pp. 60-63). The spell list rides this comment: 1 aid, 2
// chant, 3 commune w/ lesser spirit, 4 create spring, 5 detect charm, 6
// detect life, 7 dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11
// know motivation, 12 messenger, 13 obscurement, 14 protection from spirits,
// 15 request, 16 slow poison, 17 snake summoning, 18 speak w/ animals, 19
// warning, 20 withdraw - the cell is 1 where the printed header reads
// Reversible - create spring, detect charm, know motivation; the three
// matching the R658 T62 reversible column
inline int dhuL2Reversible(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
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
        default:
            return 0;
        }
    }

// the shukenja 2nd level spell sohei-usable markers by ordinal (print pp.
// 119-125; compressed pp. 60-63). The spell list rides this comment: 1 aid, 2
// chant, 3 commune w/ lesser spirit, 4 create spring, 5 detect charm, 6
// detect life, 7 dream sight, 8 enthrall, 9 hold person, 10 holy symbol, 11
// know motivation, 12 messenger, 13 obscurement, 14 protection from spirits,
// 15 request, 16 slow poison, 17 snake summoning, 18 speak w/ animals, 19
// warning, 20 withdraw - the cell is 1 where the printed asterisk marks the
// spell usable by sohei - chant, messenger, slow poison, warning; the four
// matching the R658 T62 sohei column
inline int dhuL2Sohei(int b)
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
            return 1;
        case 19:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
