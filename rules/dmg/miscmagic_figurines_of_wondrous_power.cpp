// R-refactor: split from miscmagic_figurines_of_wondrous_power.h - definitions
#include "rules/dmg/miscmagic_figurines_of_wondrous_power.h"

int Miscmagic_figurines_of_wondrous_power::mmpFigTypeCount() {
    // the printed figurine type table rows
    return 7;
}

int Miscmagic_figurines_of_wondrous_power::mmpFigStatuetteInchesHigh() {
    // a statuette of small size, an inch or so
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpFigTypeLo(int i) {
    // the printed type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 16, 31, 41, 56, 66, 86,
    };
    return t[i];
}

int Miscmagic_figurines_of_wondrous_power::mmpFigTypeHi(int i) {
    // the printed type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        15, 30, 40, 55, 65, 85, 100,
    };
    return t[i];
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyAc() {
    // the ebony fly armor class
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyHitDiceBase() {
    // 4 + 4 hit dice: the base
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyHitDiceExtra() {
    // 4 + 4 hit dice: the plus
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyAirManeuverClass() {
    // air maneuverability class C, the 3rd letter
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlySpeedUnladenInches() {
    // flies at 48 inches without a rider
    return 48;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlySpeedLadenInches() {
    // 36 inches carrying up to 210 pounds
    return 36;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlySpeedMaxLoadInches() {
    // 24 inches carrying from 211 to 350 pounds
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyLadenMaxPounds() {
    // the 36 inch band carries up to 210 pounds
    return 210;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyMaxLoadPounds() {
    // the 24 inch band carries up to 350 pounds
    return 350;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyUsesPerWeek() {
    // a maximum of 3 times per week
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpFlyHoursPerDay() {
    // 12 hours per day
    return 12;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionCount() {
    // the pair becomes 2 adult male lions
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionAcFront() {
    // lion armor class 5/6: the front
    return 5;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionAcRear() {
    // lion armor class 5/6: the rear
    return 6;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionHitDiceBase() {
    // 5 + 2 hit dice: the base
    return 5;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionHitDiceExtra() {
    // 5 + 2 hit dice: the plus
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionSlainReturnWeeks() {
    // slain: no statuette return for 1 full week
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpLionUseDays() {
    // otherwise usable once every day
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatCount() {
    // the trio of statuettes
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatUsesBeforeBurnout() {
    // after 3 uses each goat loses its magic
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelAc() {
    // the travelling mount armor class
    return 6;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelHp() {
    // the travelling mount hit points
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelAttacks() {
    // 2 attacks, the horns
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelHornDmgMin() {
    // horns for 1-8 each
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelHornDmgMax() {
    // horns for 1-8 each
    return 8;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelHitDice() {
    // consider as a 4 hit dice monster
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelMoveInches() {
    // moves at 48 inches
    return 48;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelMaxLoadPounds() {
    // bearing 280 pounds or less
    return 280;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelPoundsPerMoveLoss() {
    // minus 1 inch per 14 extra pounds
    return 14;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelHoursPerWeek() {
    // 1 day each week, totalling 24 hours
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravelRestDays() {
    // small form for not less than 1 day
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHoofDmgMin() {
    // sharp hooves 4-10/4-10
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHoofDmgMax() {
    // sharp hooves 4-10/4-10
    return 10;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailBiteDmgMin() {
    // the vicious bite 2-8
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailBiteDmgMax() {
    // the vicious bite 2-8
    return 8;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHornDmgMin() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHornDmgMax() {
    // the horns 2-12/2-12 (print: 2- 12)
    return 12;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailChargeBonus() {
    // charging: +6 damage added to each hit
    return 6;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailChargeHornMin() {
    // charging horns: 8-18 per horn
    return 8;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailChargeHornMax() {
    // charging horns: 8-18 per horn
    return 18;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailAc() {
    // armor class 0
    return 0;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHp() {
    // 96 hit points
    return 96;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailHitDice() {
    // attacks as a 16 hit dice monster
    return 16;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailUsesPerMonth() {
    // called to life but once per month
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTravailMoveInches() {
    // it moves 24 inches
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorMoveInches() {
    // the destrier-like mount moves 36 inches
    return 36;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorAc() {
    // armor class 2
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorHp() {
    // 48 hit points
    return 48;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorHornSpearBonus() {
    // one horn as a +3 spear (lance)
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorHornSwordBonus() {
    // the other horn as a +6 sword
    return 6;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorRadiusInches() {
    // radiates terror in a 3 inch radius
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorStrengthLossPct() {
    // save or lose 50 percent of strength
    return 50;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorHitPenalty() {
    // and at least -3 on to hit dice
    return -3;
}

int Miscmagic_figurines_of_wondrous_power::mmpGoatTerrorIntervalWeeks() {
    // used once every 2 weeks
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpElephantTypeLo(int i) {
    // the elephant type band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 51, 91, 94,
    };
    return t[i];
}

int Miscmagic_figurines_of_wondrous_power::mmpElephantTypeHi(int i) {
    // the elephant type band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        50, 90, 93, 100,
    };
    return t[i];
}

int Miscmagic_figurines_of_wondrous_power::mmpElephantHoursPerUse() {
    // 24 hours at a time
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpElephantUsesPerMonth() {
    // 4 times per month
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpSteadGoodRiderPct() {
    // good rider: 10 percent per use to Hades
    return 10;
}

int Miscmagic_figurines_of_wondrous_power::mmpSteadHoursPerUse() {
    // a 24 hour period maximum
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpSteadUsesPerWeek() {
    // once per week
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogIntMin() {
    // intelligence of 8-10: the low
    return 8;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogIntMax() {
    // intelligence of 8-10: the high
    return 10;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogScentFreshPct() {
    // scents a known trail 100 percent if fresh
    return 100;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogScentFreshHours() {
    // fresh means 1 hour or less old
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogScentDecayPctPerHour() {
    // minus 10 percent per hour thereafter
    return 10;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogInfravisionFeet() {
    // 90 feet range infravision
    return 90;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogSpotHiddenPct() {
    // spots hidden things 80 percent
    return 80;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogSpotInvisiblePct() {
    // spots invisible things 65 percent
    return 65;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogSpotPhasedPct() {
    // notes astral, ethereal, out-of-phase 50 percent
    return 50;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogHoursPerUse() {
    // up to 6 continuous hours
    return 6;
}

int Miscmagic_figurines_of_wondrous_power::mmpDogUsesPerWeek() {
    // once per week
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlAc() {
    // the normal-sized horned owl AC
    return 7;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlMoveInches() {
    // 24 inch move
    return 24;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlHpMin() {
    // 2-4 hit points: the low
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlHpMax() {
    // 2-4 hit points: the high
    return 4;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlDmgMin() {
    // 1-2/1-2 damage: the low
    return 1;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlDmgMax() {
    // 1-2/1-2 damage: the high
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlGiantUses() {
    // the giant owl form limited to 3 times
    return 3;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlSilencePct() {
    // the normal form moves with 95 percent silence
    return 95;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlInfravisionFeet() {
    // infravision to 90 feet
    return 90;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlDarkVisionFactor() {
    // sees dark as full light, twice a human
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlHearMouseFeet() {
    // detects a mouse moving at 60 feet
    return 60;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlCounterStealthPct() {
    // silent movement vs the owl reduced 50 percent
    return 50;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlIntMin() {
    // low 2-4 intelligence: the low
    return 2;
}

int Miscmagic_figurines_of_wondrous_power::mmpOwlIntMax() {
    // low 2-4 intelligence: the high
    return 4;
}
