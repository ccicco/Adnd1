// =========================================================================================
// Adnd1 - rules/oawjl7spells.h
// WU JEN SEVENTH LEVEL SPELLS, printed capture pp. 203-207 - the OA wu jen
// seventh level spells round
// census 598 -> 599.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 203-207; compressed pp. 93-95); all 12 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the print Components
// apostrophe-s V typo on the vanish block reading V in both passes, and body
// outside body the OA printing its near-duplicate of the sixth level vessel
// at the seventh (the same duplicate-creating spell at both levels). The
// level carries THREE dual-school prints again, all pinned primary (the
// exaction precedent): elemental servant the Conjuration/Summoning;
// Enchantment/Charm dual pinned 4, ice blight the Evocation/Summoning dual
// pinned 3, obedience the Enchantment/Evocation dual pinned 1. Conjuration
// the most common school at five spells; alteration and evocation two each;
// commune with greater spirit the lone divination, reanimation the lone
// necromantic, obedience the lone enchantment/charm; NO illusion, invocation
// or abjuration spell this level. The component census: seven VSM, FOUR
// verbal-only spells (limited wish, power word stun, tool, vanish) - the most
// verbal-only of any wu jen level yet - and withering palm the lone verbal
// and somatic; no V,M spell this level. Limited wish carries BOTH the Casting
// Time: Special line (pinned -1, the R662 exorcise convention) and the
// special save; three one-turn casts (commune with greater spirit, elemental
// servant, ice blight), three single segments (body outside body, power word
// stun, tool), obedience and reanimation the one-round casts, duo-dimension
// seven, vanish two, withering palm four segments. Two negation saves
// (elemental servant, obedience), two special (limited wish, reanimation),
// withering palm the lone half save. One reversible spell (ice blight,
// drought). The element column cross-checks the R669 dieWJT66L7Element grid:
// the ONE tagged cell (ice blight Water) matching the landed pin exactly
//
// the gap census after this round: 129 closed, 106 open - the wu jen Seventh
// Level Spells box flips (census 598 -> 599); NEXT - R677: the wu jen Eighth
// Level Spells (capture pp. 207-213, the 14 stat blocks), prefix dim (verify
// free - only the comment-words dim, dims, diminish, the R669 die precedent),
// audit "R677 OA wu jen eighth level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 12 seventh level wu jen spells (print pp. 203-207; compressed pp.
// 93-95)
inline int dilWJL7SpellCount()
    { return 12; }

// the five conjuration seventh level wu jen spells - body outside body,
// elemental servant, limited wish, power word stun, tool; the most common
// school of the level (print pp. 203-207; compressed pp. 93-95)
inline int dilWJL7ConjurationCount()
    { return 5; }

// the three dual-school seventh level wu jen prints, all pinned primary (the
// exaction precedent) - elemental servant the Conjuration/Summoning;
// Enchantment/Charm dual pinned 4, ice blight the Evocation/Summoning dual
// pinned 3, obedience the Enchantment/Evocation dual pinned 1 (print pp.
// 203-207; compressed pp. 93-95)
inline int dilWJL7DualSchoolCount()
    { return 3; }

// the one reversible seventh level wu jen spell - ice blight (drought) (print
// pp. 203-207; compressed pp. 93-95)
inline int dilWJL7ReversibleCount()
    { return 1; }

// the seven seventh level wu jen spells taking all three components - the
// bitmask reads 7 (print pp. 203-207; compressed pp. 93-95)
inline int dilWJL7VSMCount()
    { return 7; }

// the four seventh level wu jen spells taking the verbal component only -
// limited wish, power word stun, tool, vanish; the most verbal-only spells of
// any wu jen level yet (print pp. 203-207; compressed pp. 93-95)
inline int dilWJL7VerbalOnlyCount()
    { return 4; }

// the one seventh level wu jen spell with the Casting Time: Special line -
// limited wish; pinned -1, the R662 exorcise variable-cast convention (print
// pp. 203-207; compressed pp. 93-95)
inline int dilWJL7SpecialCasts()
    { return 1; }

// the three seventh level wu jen spells with a one-turn casting time -
// commune with greater spirit, elemental servant, ice blight (print pp.
// 203-207; compressed pp. 93-95)
inline int dilWJL7TurnCasts()
    { return 3; }

// the three seventh level wu jen spells with a one-segment casting time -
// body outside body, power word stun, tool (print pp. 203-207; compressed pp.
// 93-95)
inline int dilWJL7OneSegmentCasts()
    { return 3; }

// the two seventh level wu jen spells with a negation saving throw -
// elemental servant, obedience (print pp. 203-207; compressed pp. 93-95)
inline int dilWJL7NegSaves()
    { return 2; }

// the two seventh level wu jen spells with a special saving throw - limited
// wish, reanimation (print pp. 203-207; compressed pp. 93-95)
inline int dilWJL7SpecialSaves()
    { return 2; }

// the one element-tagged seventh level wu jen spell - ice blight Water -
// matching the R669 dieWJT66L7Element grid exactly (print pp. 203-207;
// compressed pp. 93-95)
inline int dilWJL7ElementCount()
    { return 1; }

// ---- the stat grid pins ----

// the wu jen 7th level spell schools by ordinal (print pp. 203-207;
// compressed pp. 93-95). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the school codes: 1
// enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the printed
// Conjuration and Conjuration/Summoning both pinned 4), 5 necromantic, 6
// alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm - conjuration
// the most common school at five spells (body outside body, elemental
// servant, limited wish, power word stun, tool); alteration two
// (duo-dimension, vanish); evocation two (ice blight, withering palm);
// commune with greater spirit the lone divination, reanimation the lone
// necromantic, obedience the lone enchantment/charm; NO illusion, invocation
// or abjuration spell this level - THREE dual-school prints, all pinned
// primary (the exaction precedent): elemental servant the
// Conjuration/Summoning; Enchantment/Charm dual pinned 4, ice blight the
// Evocation/Summoning dual pinned 3, obedience the Enchantment/Evocation dual
// pinned 1
inline int dilWJL7School(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 1;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 4;
        case 10:
            return 6;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 7th level spell components by ordinal (print pp. 203-207;
// compressed pp. 93-95). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the component codes a
// bitmask: verbal 1, somatic 2, material 4 - seven spells take all three (7);
// FOUR verbal-only spells (1): limited wish, power word stun, tool, vanish -
// the most verbal-only of any wu jen level yet; withering palm the lone
// verbal and somatic (3); no V,M spell this level
inline int dilWJL7Components(int b)
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
            return 1;
        case 6:
            return 7;
        case 7:
            return 1;
        case 8:
            return 7;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 7th level spell casting times by ordinal (print pp. 203-207;
// compressed pp. 93-95). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the casting time in
// segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the Casting
// Time: Special line (the R662 exorcise convention): limited wish the lone
// Special cast; three one-turn (commune with greater spirit, elemental
// servant, ice blight); three single segments (body outside body, power word
// stun, tool); obedience and reanimation the one-round casts; duo-dimension
// seven, vanish two, withering palm four segments
inline int dilWJL7CastTime(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 60;
        case 2:
            return 7;
        case 3:
            return 60;
        case 4:
            return 60;
        case 5:
            return -1;
        case 6:
            return 10;
        case 7:
            return 1;
        case 8:
            return 10;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 4;
        default:
            return 0;
        }
    }

// the wu jen 7th level spell saving throws by ordinal (print pp. 203-207;
// compressed pp. 93-95). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the saving throw
// codes: 0 none, 1 neg., 2 special, 3 half - elemental servant and obedience
// neg.; limited wish and reanimation special; withering palm the lone HALF
// save of the level; the other seven none
inline int dilWJL7Save(int b)
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
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// the wu jen 7th level spell reversible markers by ordinal (print pp.
// 203-207; compressed pp. 93-95). The spell list rides this comment: 1 body
// outside body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental
// servant, 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the cell is 1 where
// the printed header reads Reversible - ice blight (drought) the one
inline int dilWJL7Reversible(int b)
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
        default:
            return 0;
        }
    }

// the wu jen 7th level spell element marks by ordinal (print pp. 203-207;
// compressed pp. 93-95). The spell list rides this comment: 1 body outside
// body, 2 commune with greater spirit, 3 duo-dimension, 4 elemental servant,
// 5 ice blight, 6 limited wish, 7 obedience, 8 power word stun, 9
// reanimation, 10 tool, 11 vanish, 12 withering palm - the element codes of
// the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5 Nature, 6
// Wood, 7 All - the ONE tagged spell (ice blight Water) matching the R669
// dieWJT66L7Element pin exactly - the cross-check column
inline int dilWJL7Element(int b)
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
            return 4;
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
