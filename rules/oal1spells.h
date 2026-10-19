// =========================================================================================
// Adnd1 - rules/oal1spells.h
// FIRST LEVEL SPELLS, printed capture pp. 112-119 - the OA first level spells
// round
// census 581 -> 582.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read - the 20 first
// level spell stat blocks cross-checked spell by spell between the passes
// (print pp. 113-119; compressed pp. 58-60); all 20 schools, component sets,
// casting times and saving throws agree, zero contested stat reads. The
// compressed renders its inch marks as degree glyphs and stars (recorded as
// its OCR artifact class) and the print p. 113 augury prose garbles 1% per
// level as 1 orb per level - prose-only, nothing pinned rides it. The
// reversible flags agree between the passes (the compressed prints Reversible
// in the headers); the sohei-usable marks ride the R658 T62 grid, settled the
// round before. The stat grid pins as a table: 20 rows the spell ordinals,
// six columns - school, components (a V=1 S=2 M=4 bitmask), casting time in
// segments (1 round = 10, 1 turn = 60), saving throw code (0 none, 1 neg., 2
// special), reversible and sohei markers. The spell names ride the column
// comments, the prose descriptions and the Table 63 divination results close
// in their own rounds. The table tag L1Data identifier-safe per the R639
// lesson
//
// the gap census after this round: 112 closed, 123 open - the First Level
// Spells box flips (census 581 -> 582); NEXT - R660: the Second Level Spells
// (capture pp. 119-126), prefix dhu (verify free), audit "R660 OA second
// level spells audit", include after rules/oal1spells.h
//
namespace rules {

// ---- the spell count pins ----

// the 20 first level shukenja spells (print pp. 113-119; compressed pp.
// 58-60)
inline int dhtL1SpellCount()
    { return 20; }

// the five first level spells usable by sohei - animal companion, bless,
// deflection, resist, weapon bless
inline int dhtL1SoheiCount()
    { return 5; }

// the five reversible first level spells - bless, cure light wounds,
// deflection, detect evil, purify food & drink
inline int dhtL1ReversibleCount()
    { return 5; }

// the ten divination first level spells - the most common school by half
inline int dhtL1DivinationCount()
    { return 10; }

// the twelve first level spells taking all three components - the bitmask
// reads 7
inline int dhtL1VSMCount()
    { return 12; }

// the two first level spells taking the verbal component only - beneficence
// and omen
inline int dhtL1VerbalOnlyCount()
    { return 2; }

// the four first level spells with a one-turn casting time - animal
// companion, detect harmony, omen, weapon bless
inline int dhtL1TurnCasts()
    { return 4; }

// the twelve first level spells with a one-round casting time
inline int dhtL1RoundCasts()
    { return 12; }

// the four first level spells with a five-segment casting time - beneficence,
// calm, cure light wounds, snake charm
inline int dhtL1SegmentCasts()
    { return 4; }

// the two first level spells with a negation saving throw - animal companion
// and calm
inline int dhtL1NegSaves()
    { return 2; }

// the two first level spells with a special saving throw - deflection and
// know history
inline int dhtL1SpecialSaves()
    { return 2; }

// ---- the stat grid pins ----

// the shukenja 1st level spell schools by ordinal (print pp. 113-119;
// compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the school codes: 1 enchantment/charm, 2 divination, 3 evocation, 4
// conjuration/summoning, 5 necromantic, 6 alteration; divination the most
// common at ten spells
inline int dhtL1School(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 5;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 6;
        case 16:
            return 6;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 4;
        default:
            return 0;
        }
    }

// the shukenja 1st level spell components by ordinal (print pp. 113-119;
// compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the component codes a bitmask: verbal 1, somatic 2, material 4 - twelve
// spells take all three (7), beneficence and omen take the verbal only (1),
// six take verbal and somatic (3)
inline int dhtL1Components(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 7;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 7;
        case 5:
            return 3;
        case 6:
            return 3;
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
        case 12:
            return 7;
        case 13:
            return 7;
        case 14:
            return 1;
        case 15:
            return 3;
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

// the shukenja 1st level spell casting times by ordinal (print pp. 113-119;
// compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the casting time in segments - 1 round = 10 segments, 1 turn = 60; four
// spells take a turn (animal companion, detect harmony, omen, weapon bless),
// four take five segments (beneficence, calm, cure light wounds, snake
// charm), the rest a round
inline int dhtL1CastTime(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 10;
        case 9:
            return 60;
        case 10:
            return 10;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 10;
        case 14:
            return 60;
        case 15:
            return 10;
        case 16:
            return 10;
        case 17:
            return 5;
        case 18:
            return 10;
        case 19:
            return 60;
        default:
            return 0;
        }
    }

// the shukenja 1st level spell saving throws by ordinal (print pp. 113-119;
// compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the saving throw codes: 0 none, 1 neg., 2 special - animal companion and
// calm are neg., deflection and know history are special, the other sixteen
// none
inline int dhtL1Save(int b)
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
            return 2;
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
            return 2;
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

// the shukenja 1st level spell reversible markers by ordinal (print pp.
// 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the cell is 1 where the printed header reads Reversible - bless, cure
// light wounds, deflection, detect evil, purify food & drink; the five
// matching the R658 T62 reversible column
inline int dhtL1Reversible(int b)
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
            return 1;
        case 6:
            return 1;
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

// the shukenja 1st level spell sohei-usable markers by ordinal (print pp.
// 113-119; compressed pp. 58-60). The spell list rides this comment: 1 animal
// companion, 2 augury, 3 beneficence, 4 bless, 5 calm, 6 cure light wounds, 7
// deflection, 8 detect disease, 9 detect evil, 10 detect harmony, 11 detect
// magic, 12 detect poison, 13 divining rod, 14 know history, 15 omen, 16
// purify food & drink, 17 resist, 18 snake charm, 19 trance, 20 weapon bless
// - the cell is 1 where the printed asterisk marks the spell usable by sohei
// - animal companion, bless, deflection, resist, weapon bless; the five
// matching the R658 T62 sohei column
inline int dhtL1Sohei(int b)
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
            return 1;
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
            return 1;
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

}   // namespace rules
