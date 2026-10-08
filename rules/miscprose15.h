// ====================================================================
// Adnd1 - rules/miscprose15.h
// R271: the III.E misc magic explanation prose part 15
// (DMG p.142-148) - Mac-Fuirmidh Cittern through the
// general properties and the type table,
// part2 lines 686-764 (global = 11065 + part2
// line). The slice closes the Instrument of the
// Bards item (the kMisc3 row 26 quadruple
// quadruple asterisk, 1,000 xp / 5,000 gp per level of
// instrument). The upload DROPS the TREASURE page headers
// across the instruments run (none between 674 and 792) -
// the page attribution rides the compilation TOC anchor
// (the instruments at pp.147-148); NO seam restored this
// round, the slice carries no page header. The instrument
// facts verified against the 1eonline.info compilation page
// instrumentofthebards.htm (the R175 precedent source);
// the level gates (5th, 8th, 11th, 14th, 17th, 20th) match
// the bard.h Table II college ladder.
// 51 accessors: 49 scalars + 2 array walkers (the type
// die table), no name collisions with miscprose1.h
// through miscprose14.h. Pure data + helpers,
// header-only (the grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpCitternMisusePct() {
    // 50 percent likely to deliver the damage to any
    // non-bard or bard under 5th level
    return 50;
}

inline int mmpCitternDamageMin() {
    // the misuse delivers 3-12 hit points
    return 3;
}

inline int mmpCitternDamageMax() {
    // the upper edge of the 3-12 damage
    return 12;
}

inline int mmpCitternLevelGate() {
    // a bard of 5th or higher level uses it safely
    return 5;
}

inline int mmpCitternCharmBonusPct() {
    // a 15 percent better chance of charming
    return 15;
}

inline int mmpCitternSongCount() {
    // three songs once per day
    return 3;
}

inline int mmpDossMisusePct() {
    // 60 percent likely, any non-bard or bard under
    // 8th level
    return 60;
}

inline int mmpDossDamageMin() {
    // the misuse delivers 4-16 hit points
    return 4;
}

inline int mmpDossDamageMax() {
    // the upper edge of the 4-16 damage
    return 16;
}

inline int mmpDossLevelGate() {
    // an 8th or higher level bard plays the lute
    return 8;
}

inline int mmpDossCharmBonusPct() {
    // a 20 percent better chance of charming
    return 20;
}

inline int mmpDossSongCount() {
    // three magical songs once per day
    return 3;
}

inline int mmpDossProtFireRadiusFeet() {
    // the protection from fire song in a 10 feet
    // radius
    return 10;
}

inline int mmpCanaithMisusePct() {
    // 70 percent likely, any non-bard or bard under
    // the 11th level
    return 70;
}

inline int mmpCanaithDamageMin() {
    // the misuse causes 5-20 hit points
    return 5;
}

inline int mmpCanaithDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

inline int mmpCanaithLevelGate() {
    // an 11th or higher level bard employs it
    return 11;
}

inline int mmpCanaithCharmBonusPct() {
    // adds 25 percent to the charming ability
    return 25;
}

inline int mmpCanaithSongCount() {
    // three spells once per day
    return 3;
}

inline int mmpCanaithProtLightningRadiusFeet() {
    // the protection from lightning song in a 10
    // feet radius
    return 10;
}

inline int mmpCliMisusePct() {
    // 80 percent likely, any non-bard or bard of
    // less than the 14th level
    return 80;
}

inline int mmpCliDamageMin() {
    // the misuse causes 6-24 hit points
    return 6;
}

inline int mmpCliDamageMax() {
    // the upper edge of the 6-24 damage
    return 24;
}

inline int mmpCliLevelGate() {
    // a 14th or higher level bard plays the lyre
    return 14;
}

inline int mmpCliCharmBonusPct() {
    // adds 30 percent to charming ability
    return 30;
}

inline int mmpCliSongCount() {
    // three songs once each per day
    return 3;
}

inline int mmpAnstruthMisusePct() {
    // 90 percent likely, any non-bard or bard of
    // less than 17th level
    return 90;
}

inline int mmpAnstruthDamageMin() {
    // the misuse causes 8-32 hit points
    return 8;
}

inline int mmpAnstruthDamageMax() {
    // the upper edge of the 8-32 damage
    return 32;
}

inline int mmpAnstruthLevelGate() {
    // a 17th or higher level bard strums it
    return 17;
}

inline int mmpAnstruthCharmBonusPct() {
    // adds 35 percent to charming abilities
    return 35;
}

inline int mmpAnstruthSongCount() {
    // three spells, one each per day
    return 3;
}

inline int mmpOllamhDamageMin() {
    // a non-bard or bard under 20th level: it
    // WILL inflict 10-40 hit points (no percent
    // printed, the harm is certain)
    return 10;
}

inline int mmpOllamhDamageMax() {
    // the upper edge of the certain 10-40 damage
    return 40;
}

inline int mmpOllamhLevelGate() {
    // a bard of 20th or higher level plays it
    return 20;
}

inline int mmpOllamhCharmBonusPct() {
    // adds 40 percent to the charming abilities
    return 40;
}

inline int mmpOllamhSongCount() {
    // three spells, one each daily
    return 3;
}

inline int mmpInstrumentAbilityCount() {
    // four abilities: protection from evil,
    // invisibility, levitate, fly
    return 4;
}

inline int mmpInstrumentAbilityRadiusFeet() {
    // the protection from evil in a 10 feet radius
    return 10;
}

inline int mmpInstrumentAbilityPerDay() {
    // each ability once per day
    return 1;
}

inline int mmpInstrumentActivateSegments() {
    // each ability takes 5 segments to activate
    return 5;
}

inline int mmpInstrumentCompleteRounds() {
    // and not less than 1 full round to complete
    return 1;
}

inline int mmpInstrumentCollegeTurnsMin() {
    // the abilities last as many turns as the
    // college order, the low edge of 1-7
    return 1;
}

inline int mmpInstrumentCollegeTurnsMax() {
    // the high edge of the college order turns
    return 7;
}

inline int mmpInstrumentMagnusTurns() {
    // a magnus alumni sings for 8 turns with any
    // of the 7
    return 8;
}

inline int mmpInstrumentCharmExcessThresholdPct() {
    // when the charming ability exceeds 100
    // percent with the instrument bonus
    return 100;
}

inline int mmpInstrumentCharmExcessStepPct() {
    // the saving throw penalty per every 5
    // percent above, 3-4 rounding to the next 5
    return 5;
}

inline int mmpInstrumentCharmExcessPenaltyPerStep() {
    // the creature saves at -1 for every step
    // above 100 percent
    return 1;
}

inline int mmpInstrumentKindRowCount() {
    // the type table has 7 rows
    return 7;
}

inline int mmpInstrumentDieLo(int i) {
    // the type die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 10, 13, 16, 18, 20,
    };
    return t[i];
}

inline int mmpInstrumentDieHi(int i) {
    // the type die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 9, 12, 15, 17, 19, 20,
    };
    return t[i];
}

}  // namespace rules