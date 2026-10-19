// =========================================================================================
// Adnd1 - rules/oal7spells.h
// SEVENTH LEVEL SPELLS, printed capture pp. 147-152 - the OA seventh level
// spells round
// census 587 -> 588.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 12 seventh
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 147-152; compressed pp. 71-73); all 12 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. The level
// closes the shukenja spell list: astral spell takes the three-turn cast (180
// segments, the longest of the level), three spells a turn (divine wind,
// reincarnate, resurrection), five a round, quest eight segments, gate five,
// and holy (unholy) word casts in a single segment. Two spells take the
// negation save (compel, quest) and two the special (exaction, restore spirit
// - the system shock roll); no half saves this level. Conjuration/summoning
// and necromantic tie as the most common school at three spells each;
// exaction dual Evocation/Alteration pinned primary evocation per the
// dual-school convention (the abjure and aid precedent); no divination or
// illusion this level. Resurrection alone reads Reversible (the destruction
// reverse) - the single reversible mark matching the R658 T62 grid; holy
// (unholy) word carries no reversible marker in either pass despite its
// parenthetical name, and ancient curse alone is sohei-usable - the T62 grid
// settles both. One prose divergence noted outside the stat grid: compel's
// save penalty for the greater-than-150% bracket reads +4 in the print
// against -4 in the compressed - the print settles. The stat grid pins as a
// table: 12 rows the spell ordinals, six columns - school, components (a V=1
// S=2 M=4 bitmask), casting time in segments (1 round = 10, 1 turn = 60, 3
// turns = 180), saving throw code (0 none, 1 neg., 2 special, 3 half),
// reversible and sohei markers. The spell names ride the column comments, the
// prose descriptions close in their own rounds. The table tag L7Data
// identifier-safe per the R639 lesson
//
// the gap census after this round: 118 closed, 117 open - the Seventh Level
// Spells box flips (census 587 -> 588); the shukenja spell chapter rounds are
// COMPLETE - NEXT - R666: the Table 63 Divination Results (capture p. 117,
// rides its own box), prefix to verify free, audit "R666 OA divination
// results audit"
//
namespace rules {

// ---- the spell count pins ----

// the 12 seventh level shukenja spells (print pp. 147-152; compressed pp.
// 71-73)
inline int dhzL7SpellCount()
    { return 12; }

// the one seventh level spell usable by sohei - ancient curse
inline int dhzL7SoheiCount()
    { return 1; }

// the one reversible seventh level spell - resurrection (the destruction
// reverse)
inline int dhzL7ReversibleCount()
    { return 1; }

// the three conjuration/summoning seventh level spells - the joint most
// common school: divine wind, gate, holy (unholy) word
inline int dhzL7ConjurationCount()
    { return 3; }

// the three necromantic seventh level spells - the joint most common school:
// reincarnate, restore spirit, resurrection
inline int dhzL7NecromanticCount()
    { return 3; }

// the eight seventh level spells taking all three components - the bitmask
// reads 7
inline int dhzL7VSMCount()
    { return 8; }

// the two seventh level spells taking verbal and somatic - astral spell,
// gate; the bitmask reads 3
inline int dhzL7VSCount()
    { return 2; }

// the two seventh level spells taking the verbal component only - ancient
// curse, holy (unholy) word
inline int dhzL7VerbalOnlyCount()
    { return 2; }

// the five seventh level spells with a one-round casting time - ancient
// curse, compel, exaction, restore spirit, wind walk
inline int dhzL7RoundCasts()
    { return 5; }

// the three seventh level spells with a one-turn casting time - divine wind,
// reincarnate, resurrection
inline int dhzL7TurnCasts()
    { return 3; }

// the one seventh level spell with a three-turn casting time - astral spell,
// the longest cast of the level at 180 segments
inline int dhzL7ThreeTurnCasts()
    { return 1; }

// the one seventh level spell with a one-segment casting time - holy (unholy)
// word
inline int dhzL7OneSegmentCasts()
    { return 1; }

// the one seventh level spell with a five-segment casting time - gate
inline int dhzL7FiveSegmentCasts()
    { return 1; }

// the one seventh level spell with an eight-segment casting time - quest
inline int dhzL7EightSegmentCasts()
    { return 1; }

// the two seventh level spells with a negation saving throw - compel, quest
inline int dhzL7NegSaves()
    { return 2; }

// the two seventh level spells with a special saving throw - exaction,
// restore spirit (the system shock roll)
inline int dhzL7SpecialSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 7th level spell schools by ordinal (print pp. 147-152;
// compressed pp. 71-73). The spell list rides this comment: 1 ancient curse,
// 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy
// (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection,
// 12 wind walk - the school codes: 1 enchantment/charm, 2 divination, 3
// evocation, 4 conjuration/summoning, 5 necromantic, 6 alteration, 7
// abjuration, 9 illusion/phantasm - conjuration/summoning and necromantic tie
// as the most common school at three spells each (divine wind, gate, holy
// (unholy) word; reincarnate, restore spirit, resurrection); abjuration and
// alteration take two each (ancient curse, compel; astral spell, wind walk);
// quest the one enchantment/charm and exaction the one evocation - exaction
// dual Evocation/Alteration pinned primary per the dual-school convention; no
// divination or illusion spell this level
inline int dhzL7School(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        default:
            return 0;
        }
    }

// the shukenja 7th level spell components by ordinal (print pp. 147-152;
// compressed pp. 71-73). The spell list rides this comment: 1 ancient curse,
// 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy
// (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection,
// 12 wind walk - the component codes a bitmask: verbal 1, somatic 2, material
// 4 - eight spells take all three (7), two take verbal and somatic (3):
// astral spell, gate; ancient curse and holy (unholy) word take the verbal
// only (1)
inline int dhzL7Components(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 7;
        case 5:
            return 3;
        case 6:
            return 1;
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
        default:
            return 0;
        }
    }

// the shukenja 7th level spell casting times by ordinal (print pp. 147-152;
// compressed pp. 71-73). The spell list rides this comment: 1 ancient curse,
// 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy
// (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection,
// 12 wind walk - the casting time in segments - 1 round = 10 segments, 1 turn
// = 60, 3 turns = 180: astral spell takes three turns, three spells a turn
// (divine wind, reincarnate, resurrection), five a round (ancient curse,
// compel, exaction, restore spirit, wind walk), quest eight segments, gate
// five, and holy (unholy) word casts in a single segment
inline int dhzL7CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 180;
        case 2:
            return 10;
        case 3:
            return 60;
        case 4:
            return 10;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 8;
        case 8:
            return 60;
        case 9:
            return 10;
        case 10:
            return 60;
        case 11:
            return 10;
        default:
            return 0;
        }
    }

// the shukenja 7th level spell saving throws by ordinal (print pp. 147-152;
// compressed pp. 71-73). The spell list rides this comment: 1 ancient curse,
// 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate, 7 holy
// (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11 resurrection,
// 12 wind walk - the saving throw codes: 0 none, 1 neg., 2 special, 3 half -
// compel and quest are neg., exaction and restore spirit are special, the
// other eight none; no half saves this level
inline int dhzL7Save(int b)
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
            return 2;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
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

// the shukenja 7th level spell reversible markers by ordinal (print pp.
// 147-152; compressed pp. 71-73). The spell list rides this comment: 1
// ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate,
// 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11
// resurrection, 12 wind walk - the cell is 1 where the printed header reads
// Reversible - resurrection alone (the destruction reverse); the one matching
// the R658 T62 reversible column - holy (unholy) word carries no reversible
// marker in either pass
inline int dhzL7Reversible(int b)
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
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// the shukenja 7th level spell sohei-usable markers by ordinal (print pp.
// 147-152; compressed pp. 71-73). The spell list rides this comment: 1
// ancient curse, 2 astral spell, 3 compel, 4 divine wind, 5 exaction, 6 gate,
// 7 holy (unholy) word, 8 quest, 9 reincarnate, 10 restore spirit, 11
// resurrection, 12 wind walk - the cell is 1 where the printed asterisk marks
// the spell usable by sohei - ancient curse alone; the one matching the R658
// T62 sohei column
inline int dhzL7Sohei(int b)
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
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
