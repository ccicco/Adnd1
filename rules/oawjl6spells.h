// =========================================================================================
// Adnd1 - rules/oawjl6spells.h
// WU JEN SIXTH LEVEL SPELLS, printed capture pp. 196-203 - the OA wu jen
// sixth level spells round
// census 597 -> 598.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read (print pp.
// 196-203; compressed pp. 90-93); all 24 stat blocks cross-checked spell by
// spell between the passes, zero contested stat reads - the R669-settled
// Glassee name riding clean in both stat-block passes here (the Glasses
// misread lived on the spell-list pages, not these). The level carries THREE
// dual-school prints, the most of any wu jen level yet, all pinned primary
// (the exaction precedent): gambler's luck the Invocation; Enchantment/Charm
// dual pinned 8, spiritwrack the Evocation/Abjuration dual and sword of
// darkness the Evocation/Necromantic dual both pinned 3. Alteration the most
// common school at nine spells, illusion three, and invocation, conjuration,
// enchantment/charm, divination and evocation two each; speak with dead the
// lone necromantic, repulsion the lone abjuration. The component census: 17
// VSM, three verbal and somatic (aura, true sight, veil), three V,M (mass
// suggestion, repulsion, spiritwrack), geas the lone verbal-only. THREE
// spells take the Casting Time: Special line (enchant an item, move earth,
// spiritwrack) pinned -1, the R662 exorcise convention; six six-segment (the
// most common cast), five one-turn, five one-round, gambler's luck and pain
// the single segments. Three negation saves, five special, NO half save this
// level. Four spells read Reversible (aura, lower water, metal to rust, stone
// to flesh). The sixth column cross-checks the R669 element grid: the seven
// tagged cells matching the landed dieWJT66L6Element pins exactly - five
// Earth (glassee, metal to rust, move earth, stone to flesh, warp stone) and
// two Water (lower water, part water). The stat grid pins as a table: 24 rows
// the spell ordinals, six columns - school, components (a V=1 S=2 M=4
// bitmask), casting time in segments (1 round = 10, 1 turn = 60, -1 the
// special cast), saving throw code (0 none, 1 neg., 2 special, 3 half),
// reversible and element markers. The spell names ride the column comments,
// the prose descriptions close in their own rounds. The table tag WJL6Data
// identifier-safe per the R639 lesson
//
// the gap census after this round: 128 closed, 107 open - the wu jen Sixth
// Level Spells box flips (census 597 -> 598); NEXT - R676: the wu jen Seventh
// Level Spells (capture pp. 203-207, the 12 stat blocks), prefix dil (verify
// free - only the string-literal dill, the R669 die precedent), audit "R676
// OA wu jen seventh level spells audit"
//
namespace rules {

// ---- the spell count pins ----

// the 24 sixth level wu jen spells (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6SpellCount()
    { return 24; }

// the nine alteration sixth level wu jen spells - control weather,
// disintegrate, glassee, lower water, metal to rust, move earth, part water,
// stone to flesh, warp stone; the most common school (print pp. 196-203;
// compressed pp. 90-93)
inline int dikWJL6AlterationCount()
    { return 9; }

// the three illusion sixth level wu jen spells - permanent illusion,
// programmed illusion, veil (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6IllusionCount()
    { return 3; }

// the two invocation sixth level wu jen spells - gambler's luck, pain (print
// pp. 196-203; compressed pp. 90-93)
inline int dikWJL6InvocationCount()
    { return 2; }

// the three dual-school sixth level wu jen prints, all pinned primary (the
// exaction precedent) - gambler's luck the Invocation; Enchantment/Charm dual
// pinned 8, spiritwrack the Evocation/Abjuration dual and sword of darkness
// the Evocation/Necromantic dual both pinned 3 (print pp. 196-203; compressed
// pp. 90-93)
inline int dikWJL6DualSchoolCount()
    { return 3; }

// the four reversible sixth level wu jen spells - aura (mask), lower water
// (raise water), metal to rust (rust to metal), stone to flesh (flesh to
// stone) (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6ReversibleCount()
    { return 4; }

// the 17 sixth level wu jen spells taking all three components - the bitmask
// reads 7 (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6VSMCount()
    { return 17; }

// the three sixth level wu jen spells taking verbal and somatic - aura, true
// sight, veil; the bitmask reads 3 (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6VSCount()
    { return 3; }

// the three sixth level wu jen spells taking verbal and material without the
// somatic - mass suggestion, repulsion, spiritwrack; the bitmask reads 5
// (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6VMCount()
    { return 3; }

// the one sixth level wu jen spell taking the verbal component only - geas
// (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6VerbalOnlyCount()
    { return 1; }

// the three sixth level wu jen spells with the Casting Time: Special line -
// enchant an item, move earth, spiritwrack; pinned -1, the R662 exorcise
// variable-cast convention (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6SpecialCasts()
    { return 3; }

// the six sixth level wu jen spells with a six-segment casting time -
// disintegrate, mass suggestion, permanent illusion, programmed illusion,
// repulsion, stone to flesh; the most common cast of the level (print pp.
// 196-203; compressed pp. 90-93)
inline int dikWJL6SixSegmentCasts()
    { return 6; }

// the five sixth level wu jen spells with a one-turn casting time - control
// weather, lower water, part water, speak with dead, vessel (print pp.
// 196-203; compressed pp. 90-93)
inline int dikWJL6TurnCasts()
    { return 5; }

// the five sixth level wu jen spells with a one-round casting time - aura,
// glassee, metal to rust, true sight, warp stone (print pp. 196-203;
// compressed pp. 90-93)
inline int dikWJL6RoundCasts()
    { return 5; }

// the two sixth level wu jen spells with a one-segment casting time -
// gambler's luck, pain (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6OneSegmentCasts()
    { return 2; }

// the three sixth level wu jen spells with a negation saving throw -
// disintegrate, enchant an item, mass suggestion (print pp. 196-203;
// compressed pp. 90-93)
inline int dikWJL6NegSaves()
    { return 3; }

// the five sixth level wu jen spells with a special saving throw - metal to
// rust, permanent illusion, programmed illusion, spiritwrack, stone to flesh
// (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6SpecialSaves()
    { return 5; }

// the seven element-tagged sixth level wu jen spells - five Earth (glassee,
// metal to rust, move earth, stone to flesh, warp stone) and two Water (lower
// water, part water) - matching the R669 dieWJT66L6Element grid exactly
// (print pp. 196-203; compressed pp. 90-93)
inline int dikWJL6ElementCount()
    { return 7; }

// ---- the stat grid pins ----

// the wu jen 6th level spell schools by ordinal (print pp. 196-203;
// compressed pp. 90-93). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the school
// codes: 1 enchantment/charm, 2 divination, 3 evocation, 4 conjuration (the
// printed Conjuration and Conjuration/Summoning both pinned 4), 5
// necromantic, 6 alteration, 7 abjuration, 8 invocation, 9 illusion/phantasm
// - alteration the most common school at nine spells (control weather,
// disintegrate, glassee, lower water, metal to rust, move earth, part water,
// stone to flesh, warp stone); illusion three; invocation, conjuration,
// enchantment/charm, divination and evocation two each; speak with dead the
// lone necromantic, repulsion the lone abjuration - THREE dual-school prints,
// all pinned primary (the exaction precedent): gambler's luck the Invocation;
// Enchantment/Charm dual pinned 8, spiritwrack the Evocation/Abjuration dual
// and sword of darkness the Evocation/Necromantic dual both pinned 3
inline int dikWJL6School(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 4;
        case 4:
            return 8;
        case 5:
            return 1;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 8;
        case 12:
            return 6;
        case 13:
            return 9;
        case 14:
            return 9;
        case 15:
            return 7;
        case 16:
            return 5;
        case 17:
            return 3;
        case 18:
            return 6;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 9;
        case 22:
            return 4;
        case 23:
            return 6;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell components by ordinal (print pp. 196-203;
// compressed pp. 90-93). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the
// component codes a bitmask: verbal 1, somatic 2, material 4 - 17 spells take
// all three (7), three verbal and somatic (3): aura, true sight, veil; three
// verbal and material without the somatic (5): mass suggestion, repulsion,
// spiritwrack; geas the lone verbal only (1)
inline int dikWJL6Components(int b)
    {
        switch (b) {
        case 0:
            return 3;
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
            return 7;
        case 8:
            return 5;
        case 9:
            return 7;
        case 10:
            return 7;
        case 11:
            return 7;
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 5;
        case 16:
            return 7;
        case 17:
            return 5;
        case 18:
            return 7;
        case 19:
            return 7;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 7;
        case 23:
            return 7;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell casting times by ordinal (print pp. 196-203;
// compressed pp. 90-93). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the casting
// time in segments - 1 round = 10 segments, 1 turn = 60 segments, -1 the
// Casting Time: Special line (the R662 exorcise convention): three special
// casts (enchant an item, move earth, spiritwrack), six six-segment (the most
// common cast of the level), five a full turn (control weather, lower water,
// part water, speak with dead, vessel), five a full round (aura, glassee,
// metal to rust, true sight, warp stone), gambler's luck and pain the single
// segments, geas four, sword of darkness five, veil three
inline int dikWJL6CastTime(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 60;
        case 2:
            return 6;
        case 3:
            return -1;
        case 4:
            return 1;
        case 5:
            return 4;
        case 6:
            return 10;
        case 7:
            return 60;
        case 8:
            return 6;
        case 9:
            return 10;
        case 10:
            return -1;
        case 11:
            return 1;
        case 12:
            return 60;
        case 13:
            return 6;
        case 14:
            return 6;
        case 15:
            return 6;
        case 16:
            return 60;
        case 17:
            return -1;
        case 18:
            return 6;
        case 19:
            return 5;
        case 20:
            return 10;
        case 21:
            return 3;
        case 22:
            return 60;
        case 23:
            return 10;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell saving throws by ordinal (print pp. 196-203;
// compressed pp. 90-93). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the saving
// throw codes: 0 none, 1 neg., 2 special, 3 half - disintegrate, enchant an
// item and mass suggestion neg.; metal to rust, permanent illusion,
// programmed illusion, spiritwrack and stone to flesh special; the other 16
// none - NO half save this level
inline int dikWJL6Save(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 1;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell reversible markers by ordinal (print pp.
// 196-203; compressed pp. 90-93). The spell list rides this comment: 1 aura,
// 2 control weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6
// geas, 7 glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11
// move earth, 12 pain, 13 part water, 14 permanent illusion, 15 programmed
// illusion, 16 repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to
// flesh, 20 sword of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp
// stone - the cell is 1 where the printed header reads Reversible - aura
// (mask), lower water (raise water), metal to rust (rust to metal), stone to
// flesh (flesh to stone); the four
inline int dikWJL6Reversible(int b)
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
            return 1;
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
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// the wu jen 6th level spell element marks by ordinal (print pp. 196-203;
// compressed pp. 90-93). The spell list rides this comment: 1 aura, 2 control
// weather, 3 disintegrate, 4 enchant an item, 5 gambler's luck, 6 geas, 7
// glassee, 8 lower water, 9 mass suggestion, 10 metal to rust, 11 move earth,
// 12 pain, 13 part water, 14 permanent illusion, 15 programmed illusion, 16
// repulsion, 17 speak with dead, 18 spiritwrack, 19 stone to flesh, 20 sword
// of darkness, 21 true sight, 22 veil, 23 vessel, 24 warp stone - the element
// codes of the R669 T66 grid: 0 none, 1 Air, 2 Earth, 3 Fire, 4 Water, 5
// Nature, 6 Wood, 7 All - the seven tagged spells (glassee, metal to rust,
// move earth, stone to flesh and warp stone Earth; lower water and part water
// Water) matching the R669 dieWJT66L6Element pins exactly - the cross-check
// column
inline int dikWJL6Element(int b)
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
            return 2;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 0;
        case 12:
            return 4;
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
            return 2;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 2;
        default:
            return 0;
        }
    }

}   // namespace rules
