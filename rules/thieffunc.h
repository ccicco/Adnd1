// ====================================================================
// Adnd1 - rules/thieffunc.h
// R298: the PHB Thief Function Take table
// (the THIEF section, Premium 1e OCR
// upload line 1620) and DEXTERITY TABLE II
// (upload line 400) - a DATA-ONLY pin (the
// R186 poetics precedent): the engine
// performs no thief rolls; the tables, the
// walkers and the adjusted-chance seam are
// data for the future roll round.
//
// The take table: the base chance to perform
// each of the eight thief functions (pick
// pockets, open locks, find/remove traps,
// move silently, hide in shadows, hear
// noise, climb walls, read languages) at
// thief levels 1 through 17, with the six
// racial adjustment rows beneath (dwarf,
// elf, gnome, half-elf, halfling, half-orc;
// the human prints no row and reads 0),
// keyed to the engine race enum
// (rules/races.h, the printed order).
//
// Conventions:
//   - the BASE CHANCES are pinned in TENTHS
//     of a percent: the printed climb walls
//     column carries one decimal place from
//     the 11th level (99.1% reads 991) and
//     every printed whole percent reads x10
//     (30% reads 300);
//   - the RACIAL and DEXTERITY adjustments
//     are whole percent (the printed rows
//     carry nothing finer);
//   - the read languages dash at levels 1
//     through 3 pins as 0 (no chance);
//   - the level clamps 1..17, the function
//     clamps 0..7, the race clamps 0..6 and
//     the dexterity clamps onto the printed
//     band: below 9 reads the 9 row, above
//     18 the 18 row (the character.h DEX
//     Table I convention);
//   - DEXTERITY TABLE II prints five columns
//     (picking pockets, opening locks,
//     locating/removing traps, moving
//     silently, hiding in shadows); hear
//     noise, climb walls and read languages
//     carry no DEX column and read 0.
// ====================================================================

#pragma once

namespace rules {

// The printed function order (the table top to bottom).
enum ThfFn {
    THF_PICK_POCKETS = 0,
    THF_OPEN_LOCKS,
    THF_TRAPS,
    THF_MOVE_SILENTLY,
    THF_HIDE_SHADOWS,
    THF_HEAR_NOISE,
    THF_CLIMB_WALLS,
    THF_READ_LANGUAGES
};

inline int thfFunctionCount() {
    // the eight printed functions
    return 8;
}

inline int thfLevelCount() {
    // the take table prints thief levels 1
    // through 17
    return 17;
}

inline int thfTakeTenths(int fn, int level) {
    // the printed base chance in TENTHS of a
    // percent; fn clamps 0..7, level 1..17
    if (fn < 0) fn = 0;
    if (fn > 7) fn = 7;
    if (level < 1) level = 1;
    if (level > 17) level = 17;
    static const int t[17][8] = {
        {  300,  250,  200,  150,  100,  100,  850,    0 },
        {  350,  290,  250,  210,  150,  100,  860,    0 },
        {  400,  330,  300,  270,  200,  150,  870,    0 },
        {  450,  370,  350,  330,  250,  150,  880,  200 },
        {  500,  420,  400,  400,  310,  200,  900,  250 },
        {  550,  470,  450,  470,  370,  200,  920,  300 },
        {  600,  520,  500,  550,  430,  250,  940,  350 },
        {  650,  570,  550,  620,  490,  250,  960,  400 },
        {  700,  620,  600,  700,  560,  300,  980,  450 },
        {  800,  670,  650,  780,  630,  300,  990,  500 },
        {  900,  720,  700,  860,  700,  350,  991,  550 },
        { 1000,  770,  750,  940,  770,  350,  992,  600 },
        { 1050,  820,  800,  990,  850,  400,  993,  650 },
        { 1100,  870,  850,  990,  930,  400,  994,  700 },
        { 1150,  920,  900,  990,  990,  500,  995,  750 },
        { 1250,  970,  950,  990,  990,  500,  996,  800 },
        { 1250,  990,  990,  990,  990,  550,  997,  800 },
    };
    return t[level - 1][fn];
}

inline int thfRaceAdj(int race, int fn) {
    // the six printed racial adjustment rows
    // (upload lines 1645-1650) in whole
    // percent, keyed to the rules/races.h enum
    // (the human prints no row and reads 0);
    // fn clamps 0..7
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (fn < 0) fn = 0;
    if (fn > 7) fn = 7;
    static const int t[7][8] = {
        {   0,   0,   0,   0,   0,   0,   0,   0 },  // human
        {   0,  10,  15,   0,   0,   0, -10,  -5 },  // dwarf
        {   5,  -5,   0,   5,  10,   5,   0,   0 },  // elf
        {   0,   5,  10,   5,   5,  10, -15,   0 },  // gnome
        {  10,   0,   0,   0,   5,   0,   0,   0 },  // half-elf
        {   5,   5,   5,  10,  15,   5, -15,  -5 },  // halfling
        {  -5,   5,   5,   0,   0,   5,   5, -10 },  // half-orc
    };
    return t[race][fn];
}

inline int thfDexAdj(int dex, int fn) {
    // DEXTERITY TABLE II (upload line 400):
    // the five printed adjustment columns
    // (picking pockets, opening locks,
    // locating/removing traps, moving
    // silently, hiding in shadows) for
    // scores 9 through 18, whole percent;
    // below the printed band reads the 9 row,
    // above it the 18 row (the character.h
    // DEX Table I convention); hear noise,
    // climb walls and read languages print
    // no column and read 0
    if (dex < 9) dex = 9;
    if (dex > 18) dex = 18;
    if (fn < 0) fn = 0;
    if (fn > 7) fn = 7;
    static const int t[10][5] = {
        { -15, -10, -10, -20, -10 },  // 9
        { -10,  -5, -10, -15,  -5 },  // 10
        {  -5,   0,  -5, -10,   0 },  // 11
        {   0,   0,   0,  -5,   0 },  // 12
        {   0,   0,   0,   0,   0 },  // 13
        {   0,   0,   0,   0,   0 },  // 14
        {   0,   0,   0,   0,   0 },  // 15
        {   0,   5,   0,   0,   0 },  // 16
        {   5,  10,   0,   5,   5 },  // 17
        {  10,  15,   5,  10,  10 },  // 18
    };
    if (fn == THF_HEAR_NOISE) return 0;
    if (fn == THF_CLIMB_WALLS) return 0;
    if (fn == THF_READ_LANGUAGES) return 0;
    return t[dex - 9][fn];
}

inline int thfChanceTenths(int fn, int level,
                           int race, int dex) {
    // the adjusted chance seam: the printed
    // base plus the racial and dexterity
    // adjustments (the printed notes: the
    // adjustments are additional pluses; a
    // percentile roll at or below the chance
    // succeeds). DATA-ONLY - nothing calls
    // this seam yet (the engine performs no
    // thief rolls; a future round wires them)
    return thfTakeTenths(fn, level) + 10 *
        (thfRaceAdj(race, fn) + thfDexAdj(dex, fn));
}

inline int thfNotePercentileRoll() {
    // percentile dice decide; a score equal
    // to or less than the chance succeeds
    return 1;
}

inline int thfNotePocketsNoticeBand() {
    // a pick pockets score 21% or more ABOVE
    // the chance means the victim notices
    // the attempt
    return 21;
}

inline int thfNotePocketsVictimCut() {
    // the victim cuts the pick pockets chance
    // 5% per level above the 3rd
    return 5;
}

inline int thfNoteLocksOneTry() {
    // opening locks: one try per lock (a
    // retry waits for a higher level)
    return 1;
}

inline int thfNoteTrapsSeparate() {
    // finding and removing traps roll
    // separately; a trap must be located
    // before removal; one try each
    return 1;
}

inline int thfNoteRacialAdditional() {
    // the racial adjustments are additional
    // pluses on the adjusted base
    return 1;
}

}  // namespace rules
