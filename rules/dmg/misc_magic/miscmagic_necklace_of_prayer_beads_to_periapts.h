// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_necklace_of_prayer_beads_to_periapts.h
// R275: the III.E misc magic explanation prose part 19
// (DMG p.152-153) - the Necklace of Prayer Beads, the
// Necklace of Strangulation, the Nets of Entrapment and
// Snaring, Nolzurs Marvelous Pigments, the Pearls of
// Power and Wisdom and the Periapts of Foul Rotting,
// Health, Proof Against Poison and Wound Closure,
// part2 lines 905-969 (global = 11065 + part2 line),
// pinning the kMisc4 rows 19-29 of the 36-row III.E.4
// table. ONE mid-sentence break inside the slice: the
// pearl of power paragraph splits between a pearl of
// power (933) and enables the possessor (935), the
// upload prints no running head at the break - ONE
// seam restored this round; the slice rides the
// pp.152-153 attribution on the R274-established p.152
// base (the TREASURE running head at 903). The upload
// quirks this round: the bead table rows are split
// across multiple table lines (the karma and summons
// beads span three each); the part1 pigments row
// misplaces the apostrophe after the s; the net of
// entrapment prints the one-quarter character (mesh)
// and an en-dash (AC -10) - pinned as plain digits,
// apostrophe-free here. 49 accessors: 41 scalars + 8
// walkers (the bead die bands; the pearl die bands
// and spell levels; the periapt plus ladder), no name
// collisions with miscprose1.h through miscprose18.h.
// Pure data + helpers, header-only (the grenade.h
// pattern).
// ---- re-split from miscmagic_alchemy_jug_to_wings_of_flying.h (the R257-R279 merge) ----
// ====================================================================
#pragma once

class Miscmagic_necklace_of_prayer_beads_to_periapts {
public:
    int mmpBeadStoneMin();
    int mmpBeadStoneMax();
    int mmpBeadSemiPreciousPct();
    int mmpBeadFancyPct();
    int mmpBeadPetitionBonusPct();
    int mmpBeadSpecialMin();
    int mmpBeadSpecialMax();
    int mmpBeadGemBaseGp();
    int mmpBeadUsesPerDay();
    int mmpBeadKarmaLevels();
    int mmpBeadSummonsPct();
    int mmpBeadRowLo(int i);
    int mmpBeadRowHi(int i);
    int mmpStrangleDamagePerRound();
    int mmpEntrapMinStrength();
    int mmpEntrapCutAc();
    int mmpEntrapSizeFeet();
    int mmpEntrapMeshQuarterFeet();
    int mmpEntrapThrowFeet();
    int mmpEntrapCloseCubeFeet();
    int mmpSnareRangeInches();
    int mmpPigPotCubicFeet();
    int mmpPigDepictSquareFeet();
    int mmpPigContainersMin();
    int mmpPigContainersMax();
    int mmpPigInstrumentFeet();
    int mmpPigDepictTurns();
    int mmpPowerRecallPerDay();
    int mmpPowerSpellsRecalled();
    int mmpPowerReverseOneIn();
    int mmpPowerDoubleMin();
    int mmpPowerDoubleMaxLevel();
    int mmpPowerDoubleDieSides();
    int mmpPowerRowLo(int i);
    int mmpPowerRowHi(int i);
    int mmpPowerSpellLevel(int i);
    int mmpWisdomGain();
    int mmpWisdomMonths();
    int mmpWisdomDays();
    int mmpWisdomReverseOneIn();
    int mmpRotAbilityLossPerWeek();
    int mmpRotStartWeek();
    int mmpRotAbilityCount();
    int mmpRotDeathScore();
    int mmpPoisonSavePctPerPlus();
    int mmpPoisonRowLo(int i);
    int mmpPoisonRowHi(int i);
    int mmpPoisonPlus(int i);
    int mmpWoundHealRateMult();
};
