// ====================================================================
// Adnd1 - rules/miscprose10.h
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

namespace rules {

inline int mmpFigTypeCount() {
    // the printed figurine type table rows
    return 7;
}

inline int mmpFigStatuetteInchesHigh() {
    // a statuette of small size, an inch or so
    return 1;
}

inline int mmpFigTypeLo(int i) {
    // the printed type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 16, 31, 41, 56, 66, 86,
    };
    return t[i];
}

inline int mmpFigTypeHi(int i) {
    // the printed type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        15, 30, 40, 55, 65, 85, 100,
    };
    return t[i];
}

inline int mmpFlyAc() {
    // the ebony fly armor class
    return 4;
}

inline int mmpFlyHitDiceBase() {
    // 4 + 4 hit dice: the base
    return 4;
}

inline int mmpFlyHitDiceExtra() {
    // 4 + 4 hit dice: the plus
    return 4;
}

inline int mmpFlyAirManeuverClass() {
    // air maneuverability class C, the 3rd letter
    return 3;
}

inline int mmpFlySpeedUnladenInches() {
    // flies at 48 inches without a rider
    return 48;
}

inline int mmpFlySpeedLadenInches() {
    // 36 inches carrying up to 210 pounds
    return 36;
}

inline int mmpFlySpeedMaxLoadInches() {
    // 24 inches carrying from 211 to 350 pounds
    return 24;
}

inline int mmpFlyLadenMaxPounds() {
    // the 36 inch band carries up to 210 pounds
    return 210;
}

inline int mmpFlyMaxLoadPounds() {
    // the 24 inch band carries up to 350 pounds
    return 350;
}

inline int mmpFlyUsesPerWeek() {
    // a maximum of 3 times per week
    return 3;
}

inline int mmpFlyHoursPerDay() {
    // 12 hours per day
    return 12;
}

inline int mmpLionCount() {
    // the pair becomes 2 adult male lions
    return 2;
}

inline int mmpLionAcFront() {
    // lion armor class 5/6: the front
    return 5;
}

inline int mmpLionAcRear() {
    // lion armor class 5/6: the rear
    return 6;
}

inline int mmpLionHitDiceBase() {
    // 5 + 2 hit dice: the base
    return 5;
}

inline int mmpLionHitDiceExtra() {
    // 5 + 2 hit dice: the plus
    return 2;
}

inline int mmpLionSlainReturnWeeks() {
    // slain: no statuette return for 1 full week
    return 1;
}

inline int mmpLionUseDays() {
    // otherwise usable once every day
    return 1;
}

inline int mmpGoatCount() {
    // the trio of statuettes
    return 3;
}

inline int mmpGoatUsesBeforeBurnout() {
    // after 3 uses each goat loses its magic
    return 3;
}

inline int mmpGoatTravelAc() {
    // the travelling mount armor class
    return 6;
}

inline int mmpGoatTravelHp() {
    // the travelling mount hit points
    return 24;
}

inline int mmpGoatTravelAttacks() {
    // 2 attacks, the horns
    return 2;
}

inline int mmpGoatTravelHornDmgMin() {
    // horns for 1-8 each
    return 1;
}

inline int mmpGoatTravelHornDmgMax() {
    // horns for 1-8 each
    return 8;
}

inline int mmpGoatTravelHitDice() {
    // consider as a 4 hit dice monster
    return 4;
}

inline int mmpGoatTravelMoveInches() {
    // moves at 48 inches
    return 48;
}

inline int mmpGoatTravelMaxLoadPounds() {
    // bearing 280 pounds or less
    return 280;
}

inline int mmpGoatTravelPoundsPerMoveLoss() {
    // minus 1 inch per 14 extra pounds
    return 14;
}

inline int mmpGoatTravelHoursPerWeek() {
    // 1 day each week, totalling 24 hours
    return 24;
}

inline int mmpGoatTravelRestDays() {
    // small form for not less than 1 day
    return 1;
}

inline int mmpGoatTravailHoofDmgMin() {
    // sharp hooves 4-10/4-10
    return 4;
}

inline int mmpGoatTravailHoofDmgMax() {
    // sharp hooves 4-10/4-10
    return 10;
}

inline int mmpGoatTravailBiteDmgMin() {
    // the vicious bite 2-8
    return 2;
}

inline int mmpGoatTravailBiteDmgMax() {
    // the vicious bite 2-8
    return 8;
}

inline int mmpGoatTravailHornDmgMin() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 2;
}

inline int mmpGoatTravailHornDmgMax() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 12;
}

inline int mmpGoatTravailChargeBonus() {
    // charging: +6 damage added to each hit
    return 6;
}

inline int mmpGoatTravailChargeHornMin() {
    // charging horns: 8-18 per horn
    return 8;
}

inline int mmpGoatTravailChargeHornMax() {
    // charging horns: 8-18 per horn
    return 18;
}

inline int mmpGoatTravailAc() {
    // armor class 0
    return 0;
}

inline int mmpGoatTravailHp() {
    // 96 hit points
    return 96;
}

inline int mmpGoatTravailHitDice() {
    // attacks as a 16 hit dice monster
    return 16;
}

inline int mmpGoatTravailUsesPerMonth() {
    // called to life but once per month
    return 1;
}

inline int mmpGoatTravailMoveInches() {
    // it moves 24 inches
    return 24;
}

inline int mmpGoatTerrorMoveInches() {
    // the destrier-like mount moves 36 inches
    return 36;
}

inline int mmpGoatTerrorAc() {
    // armor class 2
    return 2;
}

inline int mmpGoatTerrorHp() {
    // 48 hit points
    return 48;
}

inline int mmpGoatTerrorHornSpearBonus() {
    // one horn as a +3 spear (lance)
    return 3;
}

inline int mmpGoatTerrorHornSwordBonus() {
    // the other horn as a +6 sword
    return 6;
}

inline int mmpGoatTerrorRadiusInches() {
    // radiates terror in a 3 inch radius
    return 3;
}

inline int mmpGoatTerrorStrengthLossPct() {
    // save or lose 50 percent of strength
    return 50;
}

inline int mmpGoatTerrorHitPenalty() {
    // and at least -3 on to hit dice
    return -3;
}

inline int mmpGoatTerrorIntervalWeeks() {
    // used once every 2 weeks
    return 2;
}

inline int mmpElephantTypeLo(int i) {
    // the elephant type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 91, 94,
    };
    return t[i];
}

inline int mmpElephantTypeHi(int i) {
    // the elephant type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 90, 93, 100,
    };
    return t[i];
}

inline int mmpElephantHoursPerUse() {
    // 24 hours at a time
    return 24;
}

inline int mmpElephantUsesPerMonth() {
    // 4 times per month
    return 4;
}

inline int mmpSteadGoodRiderPct() {
    // good rider: 10 percent per use to Hades
    return 10;
}

inline int mmpSteadHoursPerUse() {
    // a 24 hour period maximum
    return 24;
}

inline int mmpSteadUsesPerWeek() {
    // once per week
    return 1;
}

inline int mmpDogIntMin() {
    // intelligence of 8-10: the low
    return 8;
}

inline int mmpDogIntMax() {
    // intelligence of 8-10: the high
    return 10;
}

inline int mmpDogScentFreshPct() {
    // scents a known trail 100 percent if fresh
    return 100;
}

inline int mmpDogScentFreshHours() {
    // fresh means 1 hour or less old
    return 1;
}

inline int mmpDogScentDecayPctPerHour() {
    // minus 10 percent per hour thereafter
    return 10;
}

inline int mmpDogInfravisionFeet() {
    // 90 feet range infravision
    return 90;
}

inline int mmpDogSpotHiddenPct() {
    // spots hidden things 80 percent
    return 80;
}

inline int mmpDogSpotInvisiblePct() {
    // spots invisible things 65 percent
    return 65;
}

inline int mmpDogSpotPhasedPct() {
    // notes astral, ethereal, out-of-phase 50 percent
    return 50;
}

inline int mmpDogHoursPerUse() {
    // up to 6 continuous hours
    return 6;
}

inline int mmpDogUsesPerWeek() {
    // once per week
    return 1;
}

inline int mmpOwlAc() {
    // the normal-sized horned owl AC
    return 7;
}

inline int mmpOwlMoveInches() {
    // 24 inch move
    return 24;
}

inline int mmpOwlHpMin() {
    // 2-4 hit points: the low
    return 2;
}

inline int mmpOwlHpMax() {
    // 2-4 hit points: the high
    return 4;
}

inline int mmpOwlDmgMin() {
    // 1-2/1-2 damage: the low
    return 1;
}

inline int mmpOwlDmgMax() {
    // 1-2/1-2 damage: the high
    return 2;
}

inline int mmpOwlGiantUses() {
    // the giant owl form limited to 3 times
    return 3;
}

inline int mmpOwlSilencePct() {
    // the normal form moves with 95 percent silence
    return 95;
}

inline int mmpOwlInfravisionFeet() {
    // infravision to 90 feet
    return 90;
}

inline int mmpOwlDarkVisionFactor() {
    // sees dark as full light, twice a human
    return 2;
}

inline int mmpOwlHearMouseFeet() {
    // detects a mouse moving at 60 feet
    return 60;
}

inline int mmpOwlCounterStealthPct() {
    // silent movement vs the owl reduced 50 percent
    return 50;
}

inline int mmpOwlIntMin() {
    // low 2-4 intelligence: the low
    return 2;
}

inline int mmpOwlIntMax() {
    // low 2-4 intelligence: the high
    return 4;
}

}  // namespace rules