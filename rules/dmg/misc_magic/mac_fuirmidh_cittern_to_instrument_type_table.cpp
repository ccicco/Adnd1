// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/mac_fuirmidh_cittern_to_instrument_type_table.h"

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternMisusePct() {
    // 50 percent likely to deliver the damage to any
    // non-bard or bard under 5th level
    return 50;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternDamageMin() {
    // the misuse delivers 3-12 hit points
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternDamageMax() {
    // the upper edge of the 3-12 damage
    return 12;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternLevelGate() {
    // a bard of 5th or higher level uses it safely
    return 5;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternCharmBonusPct() {
    // a 15 percent better chance of charming
    return 15;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCitternSongCount() {
    // three songs once per day
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossMisusePct() {
    // 60 percent likely, any non-bard or bard under
    // 8th level
    return 60;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossDamageMin() {
    // the misuse delivers 4-16 hit points
    return 4;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossDamageMax() {
    // the upper edge of the 4-16 damage
    return 16;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossLevelGate() {
    // an 8th or higher level bard plays the lute
    return 8;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossCharmBonusPct() {
    // a 20 percent better chance of charming
    return 20;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossSongCount() {
    // three magical songs once per day
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpDossProtFireRadiusFeet() {
    // the protection from fire song in a 10 feet
    // radius
    return 10;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithMisusePct() {
    // 70 percent likely, any non-bard or bard under
    // the 11th level
    return 70;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithDamageMin() {
    // the misuse causes 5-20 hit points
    return 5;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithDamageMax() {
    // the upper edge of the 5-20 damage
    return 20;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithLevelGate() {
    // an 11th or higher level bard employs it
    return 11;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithCharmBonusPct() {
    // adds 25 percent to the charming ability
    return 25;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithSongCount() {
    // three spells once per day
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCanaithProtLightningRadiusFeet() {
    // the protection from lightning song in a 10
    // feet radius
    return 10;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliMisusePct() {
    // 80 percent likely, any non-bard or bard of
    // less than the 14th level
    return 80;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliDamageMin() {
    // the misuse causes 6-24 hit points
    return 6;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliDamageMax() {
    // the upper edge of the 6-24 damage
    return 24;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliLevelGate() {
    // a 14th or higher level bard plays the lyre
    return 14;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliCharmBonusPct() {
    // adds 30 percent to charming ability
    return 30;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpCliSongCount() {
    // three songs once each per day
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthMisusePct() {
    // 90 percent likely, any non-bard or bard of
    // less than 17th level
    return 90;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthDamageMin() {
    // the misuse causes 8-32 hit points
    return 8;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthDamageMax() {
    // the upper edge of the 8-32 damage
    return 32;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthLevelGate() {
    // a 17th or higher level bard strums it
    return 17;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthCharmBonusPct() {
    // adds 35 percent to charming abilities
    return 35;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpAnstruthSongCount() {
    // three spells, one each per day
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpOllamhDamageMin() {
    // a non-bard or bard under 20th level: it
    // WILL inflict 10-40 hit points (no percent
    // printed, the harm is certain)
    return 10;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpOllamhDamageMax() {
    // the upper edge of the certain 10-40 damage
    return 40;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpOllamhLevelGate() {
    // a bard of 20th or higher level plays it
    return 20;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpOllamhCharmBonusPct() {
    // adds 40 percent to the charming abilities
    return 40;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpOllamhSongCount() {
    // three spells, one each daily
    return 3;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentAbilityCount() {
    // four abilities: protection from evil,
    // invisibility, levitate, fly
    return 4;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentAbilityRadiusFeet() {
    // the protection from evil in a 10 feet radius
    return 10;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentAbilityPerDay() {
    // each ability once per day
    return 1;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentActivateSegments() {
    // each ability takes 5 segments to activate
    return 5;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCompleteRounds() {
    // and not less than 1 full round to complete
    return 1;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCollegeTurnsMin() {
    // the abilities last as many turns as the
    // college order, the low edge of 1-7
    return 1;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCollegeTurnsMax() {
    // the high edge of the college order turns
    return 7;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentMagnusTurns() {
    // a magnus alumni sings for 8 turns with any
    // of the 7
    return 8;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCharmExcessThresholdPct() {
    // when the charming ability exceeds 100
    // percent with the instrument bonus
    return 100;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCharmExcessStepPct() {
    // the saving throw penalty per every 5
    // percent above, 3-4 rounding to the next 5
    return 5;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentCharmExcessPenaltyPerStep() {
    // the creature saves at -1 for every step
    // above 100 percent
    return 1;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentKindRowCount() {
    // the type table has 7 rows
    return 7;
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentDieLo(int i) {
    // the type die band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 6, 10, 13, 16, 18, 20,
    };
    return t[i];
}

int Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table::mmpInstrumentDieHi(int i) {
    // the type die band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        5, 9, 12, 15, 17, 19, 20,
    };
    return t[i];
}
