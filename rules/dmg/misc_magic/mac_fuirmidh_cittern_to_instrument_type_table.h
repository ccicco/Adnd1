// ====================================================================
// Adnd1 - rules/dmg/misc_magic/mac_fuirmidh_cittern_to_instrument_type_table.h
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
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_mac_fuirmidh_cittern_to_instrument_type_table {
public:
    int mmpCitternMisusePct();
    int mmpCitternDamageMin();
    int mmpCitternDamageMax();
    int mmpCitternLevelGate();
    int mmpCitternCharmBonusPct();
    int mmpCitternSongCount();
    int mmpDossMisusePct();
    int mmpDossDamageMin();
    int mmpDossDamageMax();
    int mmpDossLevelGate();
    int mmpDossCharmBonusPct();
    int mmpDossSongCount();
    int mmpDossProtFireRadiusFeet();
    int mmpCanaithMisusePct();
    int mmpCanaithDamageMin();
    int mmpCanaithDamageMax();
    int mmpCanaithLevelGate();
    int mmpCanaithCharmBonusPct();
    int mmpCanaithSongCount();
    int mmpCanaithProtLightningRadiusFeet();
    int mmpCliMisusePct();
    int mmpCliDamageMin();
    int mmpCliDamageMax();
    int mmpCliLevelGate();
    int mmpCliCharmBonusPct();
    int mmpCliSongCount();
    int mmpAnstruthMisusePct();
    int mmpAnstruthDamageMin();
    int mmpAnstruthDamageMax();
    int mmpAnstruthLevelGate();
    int mmpAnstruthCharmBonusPct();
    int mmpAnstruthSongCount();
    int mmpOllamhDamageMin();
    int mmpOllamhDamageMax();
    int mmpOllamhLevelGate();
    int mmpOllamhCharmBonusPct();
    int mmpOllamhSongCount();
    int mmpInstrumentAbilityCount();
    int mmpInstrumentAbilityRadiusFeet();
    int mmpInstrumentAbilityPerDay();
    int mmpInstrumentActivateSegments();
    int mmpInstrumentCompleteRounds();
    int mmpInstrumentCollegeTurnsMin();
    int mmpInstrumentCollegeTurnsMax();
    int mmpInstrumentMagnusTurns();
    int mmpInstrumentCharmExcessThresholdPct();
    int mmpInstrumentCharmExcessStepPct();
    int mmpInstrumentCharmExcessPenaltyPerStep();
    int mmpInstrumentKindRowCount();
    int mmpInstrumentDieLo(int i);
    int mmpInstrumentDieHi(int i);
};
