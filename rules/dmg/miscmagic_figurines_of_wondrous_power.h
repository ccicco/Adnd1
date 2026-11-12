// ====================================================================
// Adnd1 - rules/dmg/miscmagic_figurines_of_wondrous_power.h
// R266: the III.E misc magic explanation prose part 10
// (DMG p.135-136) - Figurines of Wondrous Power, part2
// lines 433-479 (global = 11065 + part2 line). ONE page
// header strips (477, the TREASURE page) cutting the
// Serpentine Owl paragraph mid-sentence (one seam,
// restored); the compilation also wraps the Goat of
// Travelling paragraph at a bare blank line (450/452,
// no page header) - one wrap artifact, restored. 90
// accessors: 86 scalars + 4 array walkers (the figurine
// type and marble elephant type tables), no name
// collisions with miscprose1.h through miscprose9.h.
// The slice pins kMisc3 row 0 (the Figurine band
// 01-15, the single asterisk, per hit die values).
// Pure data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_figurines_of_wondrous_power (instance methods)
class Miscmagic_figurines_of_wondrous_power {
public:
    int mmpFigTypeCount();
    int mmpFigStatuetteInchesHigh();
    int mmpFigTypeLo(int i);
    int mmpFigTypeHi(int i);
    int mmpFlyAc();
    int mmpFlyHitDiceBase();
    int mmpFlyHitDiceExtra();
    int mmpFlyAirManeuverClass();
    int mmpFlySpeedUnladenInches();
    int mmpFlySpeedLadenInches();
    int mmpFlySpeedMaxLoadInches();
    int mmpFlyLadenMaxPounds();
    int mmpFlyMaxLoadPounds();
    int mmpFlyUsesPerWeek();
    int mmpFlyHoursPerDay();
    int mmpLionCount();
    int mmpLionAcFront();
    int mmpLionAcRear();
    int mmpLionHitDiceBase();
    int mmpLionHitDiceExtra();
    int mmpLionSlainReturnWeeks();
    int mmpLionUseDays();
    int mmpGoatCount();
    int mmpGoatUsesBeforeBurnout();
    int mmpGoatTravelAc();
    int mmpGoatTravelHp();
    int mmpGoatTravelAttacks();
    int mmpGoatTravelHornDmgMin();
    int mmpGoatTravelHornDmgMax();
    int mmpGoatTravelHitDice();
    int mmpGoatTravelMoveInches();
    int mmpGoatTravelMaxLoadPounds();
    int mmpGoatTravelPoundsPerMoveLoss();
    int mmpGoatTravelHoursPerWeek();
    int mmpGoatTravelRestDays();
    int mmpGoatTravailHoofDmgMin();
    int mmpGoatTravailHoofDmgMax();
    int mmpGoatTravailBiteDmgMin();
    int mmpGoatTravailBiteDmgMax();
    int mmpGoatTravailHornDmgMin();
    int mmpGoatTravailHornDmgMax();
    int mmpGoatTravailChargeBonus();
    int mmpGoatTravailChargeHornMin();
    int mmpGoatTravailChargeHornMax();
    int mmpGoatTravailAc();
    int mmpGoatTravailHp();
    int mmpGoatTravailHitDice();
    int mmpGoatTravailUsesPerMonth();
    int mmpGoatTravailMoveInches();
    int mmpGoatTerrorMoveInches();
    int mmpGoatTerrorAc();
    int mmpGoatTerrorHp();
    int mmpGoatTerrorHornSpearBonus();
    int mmpGoatTerrorHornSwordBonus();
    int mmpGoatTerrorRadiusInches();
    int mmpGoatTerrorStrengthLossPct();
    int mmpGoatTerrorHitPenalty();
    int mmpGoatTerrorIntervalWeeks();
    int mmpElephantTypeLo(int i);
    int mmpElephantTypeHi(int i);
    int mmpElephantHoursPerUse();
    int mmpElephantUsesPerMonth();
    int mmpSteadGoodRiderPct();
    int mmpSteadHoursPerUse();
    int mmpSteadUsesPerWeek();
    int mmpDogIntMin();
    int mmpDogIntMax();
    int mmpDogScentFreshPct();
    int mmpDogScentFreshHours();
    int mmpDogScentDecayPctPerHour();
    int mmpDogInfravisionFeet();
    int mmpDogSpotHiddenPct();
    int mmpDogSpotInvisiblePct();
    int mmpDogSpotPhasedPct();
    int mmpDogHoursPerUse();
    int mmpDogUsesPerWeek();
    int mmpOwlAc();
    int mmpOwlMoveInches();
    int mmpOwlHpMin();
    int mmpOwlHpMax();
    int mmpOwlDmgMin();
    int mmpOwlDmgMax();
    int mmpOwlGiantUses();
    int mmpOwlSilencePct();
    int mmpOwlInfravisionFeet();
    int mmpOwlDarkVisionFactor();
    int mmpOwlHearMouseFeet();
    int mmpOwlCounterStealthPct();
    int mmpOwlIntMin();
    int mmpOwlIntMax();
};
