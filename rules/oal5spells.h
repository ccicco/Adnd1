// =========================================================================================
// Adnd1 - rules/oal5spells.h
// FIFTH LEVEL SPELLS, printed capture pp. 140-143 - the OA fifth level spells
// round
// census 585 -> 586.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 12 fifth
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 140-143; compressed pp. 68-70); all 12 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. The level
// lists twelve spells (the R658 T62 grid settled the size); advice takes the
// verbal component only; air walk casts in a single segment; three spells
// take the eight-segment cast (cure critical wounds, dispel evil, true
// seeing); raise dead and remember carry the special saves. Alteration and
// divination tie as the most common school at three spells each, with no
// evocation or conjuration spell this level. The reversible flags agree
// between the passes; the sohei-usable marks ride the R658 T62 grid, settled
// five rounds before. The stat grid pins as a table: 12 rows the spell
// ordinals, six columns - school, components (a V=1 S=2 M=4 bitmask), casting
// time in segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1
// neg., 2 special, 3 half), reversible and sohei markers. The spell names
// ride the column comments, the prose descriptions close in their own rounds.
// The table tag L5Data identifier-safe per the R639 lesson
//
// the gap census after this round: 116 closed, 119 open - the Fifth Level
// Spells box flips (census 585 -> 586); NEXT - R664: the Sixth Level Spells
// (capture pp. 143-147), prefix dhy (verify free), audit "R664 OA sixth level
// spells audit", include after rules/oal5spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 12 fifth level shukenja spells (print pp. 140-143; compressed pp.
// 68-70)
inline int dhxL5SpellCount()
    { return 12; }

// the four fifth level spells usable by sohei - dispel evil, mental strength,
// strength, true seeing
inline int dhxL5SoheiCount()
    { return 4; }

// the six reversible fifth level spells - cure critical wounds, dispel evil,
// mental strength, raise dead, remember, true seeing
inline int dhxL5ReversibleCount()
    { return 6; }

// the three alteration fifth level spells - air walk, mental strength,
// strength
inline int dhxL5AlterationCount()
    { return 3; }

// the three divination fifth level spells - commune w/ greater spirit,
// remember, true seeing; tied with alteration as the most common school
inline int dhxL5DivinationCount()
    { return 3; }

// the two enchantment/charm fifth level spells - advice, possess
inline int dhxL5EnchCharmCount()
    { return 2; }

// the two abjuration fifth level spells - atonement, dispel evil
inline int dhxL5AbjurationCount()
    { return 2; }

// the two necromantic fifth level spells - cure critical wounds, raise dead
inline int dhxL5NecromanticCount()
    { return 2; }

// the nine fifth level spells taking all three components - the bitmask reads
// 7
inline int dhxL5VSMCount()
    { return 9; }

// the two fifth level spells taking verbal and somatic - cure critical
// wounds, raise dead; the bitmask reads 3
inline int dhxL5VSCount()
    { return 2; }

// the one fifth level spell taking the verbal component only - advice
inline int dhxL5VerbalOnlyCount()
    { return 1; }

// the five fifth level spells with a one-turn casting time - atonement,
// commune w/ greater spirit, possess, remember, strength
inline int dhxL5TurnCasts()
    { return 5; }

// the one fifth level spell with a one-round casting time - raise dead
inline int dhxL5RoundCasts()
    { return 1; }

// the three fifth level spells with an eight-segment casting time - cure
// critical wounds, dispel evil, true seeing
inline int dhxL5EightSegmentCasts()
    { return 3; }

// the two fifth level spells with a five-segment casting time - advice,
// mental strength
inline int dhxL5FiveSegmentCasts()
    { return 2; }

// the one fifth level spell with a one-segment casting time - air walk
inline int dhxL5OneSegmentCasts()
    { return 1; }

// the three fifth level spells with a negation saving throw - advice, dispel
// evil, possess
inline int dhxL5NegSaves()
    { return 3; }

// the two fifth level spells with a special saving throw - raise dead,
// remember
inline int dhxL5SpecialSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 5th level spell schools by ordinal (print pp. 140-143;
// compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air
// walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6
// dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11
// strength, 12 true seeing - the school codes: 1 enchantment/charm, 2
// divination, 5 necromantic, 6 alteration, 7 abjuration - alteration and
// divination the most common at three spells each; no evocation or
// conjuration spell this level
inline int dhxL5School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 7;
        case 6:
            return 6;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 2;
        case 10:
            return 6;
        case 11:
            return 2;
        default:
            return 0;
        }
    }

// the shukenja 5th level spell components by ordinal (print pp. 140-143;
// compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air
// walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6
// dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11
// strength, 12 true seeing - the component codes a bitmask: verbal 1, somatic
// 2, material 4 - nine spells take all three (7), cure critical wounds and
// raise dead take the verbal and somatic (3), and advice takes the verbal
// only (1)
inline int dhxL5Components(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 3;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        default:
            return 0;
        }
    }

// the shukenja 5th level spell casting times by ordinal (print pp. 140-143;
// compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air
// walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6
// dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11
// strength, 12 true seeing - the casting time in segments - 1 round = 10
// segments, 1 turn = 60: five spells take a turn (atonement, commune w/
// greater spirit, possess, remember, strength), raise dead a round, three
// take eight segments (cure critical wounds, dispel evil, true seeing),
// advice and mental strength five, and air walk the single segment
inline int dhxL5CastTime(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 1;
        case 2:
            return 60;
        case 3:
            return 60;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 5;
        case 7:
            return 60;
        case 8:
            return 10;
        case 9:
            return 60;
        case 10:
            return 60;
        case 11:
            return 8;
        default:
            return 0;
        }
    }

// the shukenja 5th level spell saving throws by ordinal (print pp. 140-143;
// compressed pp. 68-70). The spell list rides this comment: 1 advice, 2 air
// walk, 3 atonement, 4 commune w/ greater spirit, 5 cure critical wounds, 6
// dispel evil, 7 mental strength, 8 possess, 9 raise dead, 10 remember, 11
// strength, 12 true seeing - the saving throw codes: 0 none, 1 neg., 2
// special, 3 half - advice, dispel evil and possess are neg., raise dead and
// remember are special, the other seven none
inline int dhxL5Save(int b)
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
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// the shukenja 5th level spell reversible markers by ordinal (print pp.
// 140-143; compressed pp. 68-70). The spell list rides this comment: 1
// advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure
// critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead,
// 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed
// header reads Reversible - cure critical wounds, dispel evil, mental
// strength, raise dead, remember, true seeing; the six matching the R658 T62
// reversible column
inline int dhxL5Reversible(int b)
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
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 1;
        default:
            return 0;
        }
    }

// the shukenja 5th level spell sohei-usable markers by ordinal (print pp.
// 140-143; compressed pp. 68-70). The spell list rides this comment: 1
// advice, 2 air walk, 3 atonement, 4 commune w/ greater spirit, 5 cure
// critical wounds, 6 dispel evil, 7 mental strength, 8 possess, 9 raise dead,
// 10 remember, 11 strength, 12 true seeing - the cell is 1 where the printed
// asterisk marks the spell usable by sohei - dispel evil, mental strength,
// strength, true seeing; the four matching the R658 T62 sohei column
inline int dhxL5Sohei(int b)
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
            return 1;
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
