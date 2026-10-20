// =========================================================================================
// Adnd1 - rules/oawjl9spells.h
// WU JEN NINTH LEVEL SPELLS, printed capture pp. 213-216 - the OA wu jen
// ninth level spells round, the wu jen spell book closer
// census 600 -> 601.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 213-216; compressed pp. 97-98); all 13 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the roster pages
// carrying two garbles against the stat blocks (Instant Regenerate and Power
// Word. III for the Instant Regeneration and Power Word, Kill the stat-block
// headings print in both passes, roster-only variances outside the grid), and
// the crystalbrittle print running the Duration and save lines together with
// the save reading Special in both passes. SIX nine-segment casts - astral
// spell, crystalbrittle, gate, imprisonment, shape change, time stop - the
// ninth level signature and the most common cast of the level; the opening
// quartet astral spell, crystalbrittle, gate and imprisonment all take verbal
// and somatic only. Conjuration the most common school at five spells (gate,
// planar call, power word kill, summon spirit, wish); alteration three,
// evocation three; imprisonment the lone abjuration and the one reversible
// spell, instant regeneration the lone necromantic; NO enchantment/charm,
// divination, invocation or illusion spell this level - ONE dual-school
// print, summon spirit the Conjuration/Summoning; Necromantic dual pinned
// primary conjuration 4, the exaction precedent. Wish carries BOTH the
// Casting Time: Special line (pinned -1, the R662 exorcise convention) and
// the special save; power word kill, time stop and wish the three verbal-only
// spells; three one-turn casts (planar call, summon spirit, tsunami); instant
// regeneration and internal fire the one-round casts; power word kill the
// lone single segment. Summon spirit the lone negation save; crystalbrittle,
// planar call and wish special; tsunami the lone half save. The element
// column cross-checks the R669 dieWJT66L9Element grid: the THREE tagged cells
// matching exactly - crystalbrittle Earth, internal fire Fire, tsunami Water
// - the cross-check column closing the wu jen spell book grid
//
// the gap census after this round: 131 closed, 104 open - the wu jen Ninth
// Level Spells box flips (census 600 -> 601), the WU JEN SPELL BOOK GRID
// CLOSED - all nine levels pinned; NEXT - R679: the OA Chapter 9 Combat arc
// opens - the Summary of the Combat Sequence (capture p. 218), prefix dip
// (verify free - only the comment-word dips, the R669 die precedent), audit
// "R679 OA combat sequence audit"
//
namespace rules {

// ---- the spell count pins ----

// the 13 ninth level wu jen spells (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9SpellCount()
    { return 13; }

// the five conjuration ninth level wu jen spells - gate, planar call, power
// word kill, summon spirit, wish; the most common school of the level (print
// pp. 213-216; compressed pp. 97-98)
inline int dioWJL9ConjurationCount()
    { return 5; }

// the one dual-school ninth level wu jen print - summon spirit the
// Conjuration/Summoning; Necromantic dual pinned primary conjuration 4, the
// exaction precedent (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9DualSchoolCount()
    { return 1; }

// the six nine-segment ninth level wu jen casts - astral spell,
// crystalbrittle, gate, imprisonment, shape change, time stop; the ninth
// level signature, the most common cast of the level (print pp. 213-216;
// compressed pp. 97-98)
inline int dioWJL9NineSegmentCasts()
    { return 6; }

// the four verbal and somatic ninth level wu jen spells - the opening quartet
// astral spell, crystalbrittle, gate, imprisonment; the bitmask reads 3
// (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9VSCount()
    { return 4; }

// the six ninth level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9VSMCount()
    { return 6; }

// the three verbal-only ninth level wu jen spells - power word kill, time
// stop, wish (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9VerbalOnlyCount()
    { return 3; }

// the one ninth level wu jen spell with the Casting Time: Special line -
// wish; pinned -1, the R662 exorcise variable-cast convention (print pp.
// 213-216; compressed pp. 97-98)
inline int dioWJL9SpecialCasts()
    { return 1; }

// the three ninth level wu jen spells with a one-turn casting time - planar
// call, summon spirit, tsunami (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9TurnCasts()
    { return 3; }

// the one ninth level wu jen spell with a negation saving throw - summon
// spirit (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9NegSaves()
    { return 1; }

// the three ninth level wu jen spells with a special saving throw -
// crystalbrittle, planar call, wish (print pp. 213-216; compressed pp. 97-98)
inline int dioWJL9SpecialSaves()
    { return 3; }

// the one ninth level wu jen spell with a half saving throw - tsunami (print
// pp. 213-216; compressed pp. 97-98)
inline int dioWJL9HalfSaves()
    { return 1; }

// the one reversible ninth level wu jen spell - imprisonment (print pp.
// 213-216; compressed pp. 97-98)
inline int dioWJL9ReversibleCount()
    { return 1; }

// the three element-tagged ninth level wu jen spells - crystalbrittle Earth,
// internal fire Fire, tsunami Water - matching the R669 dieWJT66L9Element
// grid exactly, one each of three elements (print pp. 213-216; compressed pp.
// 97-98)
inline int dioWJL9ElementCount()
    { return 3; }

// ---- the stat grid pins ----

// the wu jen 9th level spell schools by ordinal (print pp. 213-216;
// compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal
// fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the school codes: 1 enchantment/charm,
// 2 divination, 3 evocation, 4 conjuration (the printed Conjuration and
// Conjuration/Summoning both pinned 4), 5 necromantic, 6 alteration, 7
// abjuration, 8 invocation, 9 illusion/phantasm - conjuration the most common
// school at five spells (gate, planar call, power word kill, summon spirit,
// wish); alteration three (crystalbrittle, shape change, time stop);
// evocation three (astral spell, internal fire, tsunami); imprisonment the
// lone abjuration, instant regeneration the lone necromantic; NO
// enchantment/charm, divination, invocation or illusion spell this level -
// ONE dual-school print, summon spirit the Conjuration/Summoning; Necromantic
// dual pinned primary conjuration 4, the exaction precedent
inline int dioWJL9School(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 7;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 6;
        case 9:
            return 4;
        case 10:
            return 6;
        case 11:
            return 3;
        case 12:
            return 4;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell components by ordinal (print pp. 213-216;
// compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal
// fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the component codes a bitmask: verbal
// 1, somatic 2, material 4 - the opening quartet astral spell,
// crystalbrittle, gate and imprisonment the verbal and somatic (3); six take
// all three (7); power word kill, time stop and wish the verbal-only three
// (1); NO somatic-only or V,M spell this level
inline int dioWJL9Components(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 7;
        case 6:
            return 7;
        case 7:
            return 1;
        case 8:
            return 7;
        case 9:
            return 7;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell casting times by ordinal (print pp. 213-216;
// compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal
// fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the casting time in segments - 1 round
// = 10 segments, 1 turn = 60 segments, -1 the Casting Time: Special line (the
// R662 exorcise convention): SIX nine-segment casts (astral spell,
// crystalbrittle, gate, imprisonment, shape change, time stop) - the ninth
// level signature and the most common cast of the level; three one-turn
// (planar call, summon spirit, tsunami); instant regeneration and internal
// fire the one-round casts; power word kill the lone single segment; wish the
// lone Special cast
inline int dioWJL9CastTime(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 9;
        case 2:
            return 9;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 60;
        case 7:
            return 1;
        case 8:
            return 9;
        case 9:
            return 60;
        case 10:
            return 9;
        case 11:
            return 60;
        case 12:
            return -1;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell saving throws by ordinal (print pp. 213-216;
// compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal
// fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the saving throw codes: 0 none, 1 neg.,
// 2 special, 3 half - summon spirit the lone negation save; crystalbrittle,
// planar call and wish special (the crystalbrittle print running the Duration
// and save lines together, the save reading Special in both passes); tsunami
// the lone half save; the other eight none
inline int dioWJL9Save(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell reversible markers by ordinal (print pp.
// 213-216; compressed pp. 97-98). The spell list rides this comment: 1 astral
// spell, 2 crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6
// internal fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon
// spirit, 11 time stop, 12 tsunami, 13 wish - the cell is 1 where the printed
// header reads Reversible - imprisonment the one
inline int dioWJL9Reversible(int b)
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
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 9th level spell element marks by ordinal (print pp. 213-216;
// compressed pp. 97-98). The spell list rides this comment: 1 astral spell, 2
// crystalbrittle, 3 gate, 4 imprisonment, 5 instant regeneration, 6 internal
// fire, 7 planar call, 8 power word kill, 9 shape change, 10 summon spirit,
// 11 time stop, 12 tsunami, 13 wish - the element codes of the R669 T66 grid:
// 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6 Wood, 7 All - the
// THREE tagged spells (crystalbrittle Earth, internal fire Fire, tsunami
// Water) matching the R669 dieWJT66L9Element pins exactly, one each of three
// elements - the cross-check column closing the wu jen spell book grid
inline int dioWJL9Element(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 4;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
