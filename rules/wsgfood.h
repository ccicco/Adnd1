// =========================================================================================
// Adnd1 - rules/wsgfood.h
// R462: the WSG FOOD AND WATER chapter opener - going without food (Table
// 28), going without water, the effects on animals, the minimum daily
// requirement of food and the minimum daily requirement of water (Table 29),
// printed pp. 50-53.
// census 386 -> 387.
//
// Ground truth three-way: the user Drive PDF OCR (Wilderness Survival
// Guide.pdf pp. 50-53) vs the archive djvu word layer vs IIIF eye-reads of
// leaves 0050-0053 - Table 28 settled on the image (the djvu garbles the
// 4/5/6/7/8/10 ladder), the +2/+4 example modifiers, the 1.5-times animal
// multiple, the cumulative -4 recovery modifier and the water encumbrance
// sentence eye-read; Table 29 clean in both text layers.
//
// All fractions pinned cross-multiplied (division-free); the book examples
// (Str 12 + Con 14 = 26, the +2/+4 checks, the ration packs, the 56-pint
// cubic foot) are audit examples.
//
namespace rules {

// ---- The Table 28 tolerance ladder ----

// the combined Str+Con band: 15 or less 0, 16-19 1, 20-24 2, 25-30 3, 31-35
// 4, 36 or more 5
inline int wnfBandFor(int sc)
    {
        if (sc <= 15) return 0;
        if (sc <= 19) return 1;
        if (sc <= 24) return 2;
        if (sc <= 30) return 3;
        if (sc <= 35) return 4;
        return 5;
    }

// the Table 28 tolerance days per combined Str+Con band
inline int wnfToleranceDays(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 5;
        case 2:
            return 6;
        case 3:
            return 7;
        case 4:
            return 8;
        case 5:
            return 10;
        default:
            return 0;
        }
    }

// the Table 28 band count (six combined Str+Con bands)
inline int wnfBandCount()
    { return 6; }

// ---- Going without food: the check ladder ----

// past tolerance: a Str or Con check (higher score) every 12 hours to remain
// unaffected
inline int wnfCheckEveryHours()
    { return 12; }

// every check after the first: a cumulative +1 on the die roll (+1 second, +2
// third, and so on)
inline int wnfCheckIncumPerCheck()
    { return 1; }

// after the first failed check: subsequent checks at a cumulative +2 on the
// die roll
inline int wnfWeakCheckIncum()
    { return 2; }

// weakened: -1 on attack rolls and dodging or reaction saving throws the
// first day
inline int wnfWeakAtkPenaltyFirstDay()
    { return 1; }

// while weakened the penalty worsens by -1 per day
inline int wnfWeakPenaltyWorsenPerDay()
    { return 1; }

// eating at least one full meal per day: the condition improves by two steps
// per day
inline int wnfRecoveryStepsPerDay()
    { return 2; }

// incapacitated: accumulated penalties retained or worsened to -4 if they
// were not that low already
inline int wnfIncapPenaltyFloor()
    { return 4; }

// incapacitated recovers only via solid nourishment for at least two
// consecutive days (at least two full meals, spaced one day apart)
inline int wnfIncapRecoveryMinMeals()
    { return 2; }

// if the incapacitated recovery check fails and he keeps eating one meal a
// day: subsequent daily checks at a cumulative -4 until one succeeds
inline int wnfIncapFailedCheckIncum()
    { return 4; }

// incapacitated without eating within 12 hours: hit points lost at 1d6 per
// hour, death at zero
inline int wnfIncapHpLossPerHourDie()
    { return 6; }

// nourishment while alive: hit points regained at 1d4 per hour
inline int wnfIncapHpRegainPerHourDie()
    { return 4; }

// an additional -1 on attack rolls and saving throws for each hour of
// hit-point loss
inline int wnfIncapPenaltyPerHour()
    { return 1; }

// distressed: no more than two turns of strenuous activity before a Con
// check, a fail means automatic exhaustion (not merely fatigued)
inline int wnfDistressStrenuousTurnLimit()
    { return 2; }

// no ill effects from going without food only with an adequate supply of
// drinking water
inline bool wnfFoodToleranceRequiresWater()
    { return true; }

// a distressed character failing the strenuous Con check becomes
// automatically exhausted, not merely fatigued
inline bool wnfDistressFailExhaustedNotFatigued()
    { return true; }

// an incapacitated character is incapable of any voluntary physical activity
inline bool wnfIncapNoVoluntaryActivity()
    { return true; }

// ---- Going without water: the modifier set ----

// general rule: no character goes without liquid nourishment more than three
// days before adverse effects
inline int wnfWaterBaseTolerance()
    { return 3; }

// +2 days if food with a high water content is eaten (standard rations, green
// plants, raw meat, fruits, vegetables)
inline int wnfWaterModHighWaterFood()
    { return 2; }

// +1 day if body weight over 200 pounds, above average weight for the race,
// or average weight and below average height
inline int wnfWaterModHeavy()
    { return 1; }

// +1 day if female
inline int wnfWaterModFemale()
    { return 1; }

// +1 day without strenuous activity the entire period (a once-per-day very
// short burst allowable)
inline int wnfWaterModNoStrenuous()
    { return 1; }

// -1 day if the effective temperature reaches or exceeds 90 degrees even
// once, magical or natural
inline int wnfWaterModHot90()
    { return -1; }

// -1 day without at least one meal per day
inline int wnfWaterModLessMeal()
    { return -1; }

// -1 day if strength or constitution under 8
inline int wnfWaterModLowStrCon()
    { return -1; }

// negative modifiers can never reduce the water tolerance level below one day
inline int wnfWaterToleranceFloor()
    { return 1; }

// one turn of strenuous activity during a day loses the no-strenuous-activity
// benefit
inline int wnfWaterNoStrenuousLossTurns()
    { return 1; }

// "water" is any liquid swallowed without harmful effects - the same benefit
// as pure water
inline bool wnfWaterAnyDrinkableLiquid()
    { return true; }

// standard rations have a high water content
inline bool wnfStandardRationsHighWater()
    { return true; }

// iron rations do NOT have a high water content
inline bool wnfIronRationsHighWater()
    { return false; }

// green plants, raw meat, fruits and vegetables have a high water content
inline bool wnfGreenPlantsRawMeatHighWater()
    { return true; }

// tree bark is edible but has no high water content, nor dried or cooked
// meat, nor bread
inline bool wnfTreeBarkHighWater()
    { return false; }

// the water tolerance modifiers are all cumulative
inline bool wnfWaterModsCumulative()
    { return true; }

// weakened, distressed and incapacitated from lack of water follow the
// going-without-food conditions and transitions
inline bool wnfWaterDeprivationUsesFoodConditions()
    { return true; }

// without food AND water: after the water tolerance onset, a failed check
// means immediate incapacitation
inline bool wnfTotalDeprivationIncapOnFail()
    { return true; }

// not enough water is just as bad as none: less than a full ration triggers
// the tolerance clock
inline bool wnfNotEnoughWaterAsBadAsNone()
    { return true; }

// ---- Effects on animals ----

// a weakened animal: movement and carrying capacity both reduced to one-half
// (divide by two)
inline int wnfAnimalHalveFactor()
    { return 2; }

// a weakened animal forced to work hard longer than three turns in a day:
// incapacitated at the end of the third turn
inline int wnfAnimalHardWorkTurns()
    { return 3; }

// the incapacitation multiple numerator: 1.5 times the tolerance level
// (rounded down)
inline int wnfAnimalIncapMultNum()
    { return 3; }

// the incapacitation multiple denominator (3/2)
inline int wnfAnimalIncapMultDen()
    { return 2; }

// a weakened animal fed or watered: back to full strength after 13-24 hours
// of rest
inline int wnfAnimalRestMinHours()
    { return 13; }

// the rest window upper end (1d12 + 12)
inline int wnfAnimalRestMaxHours()
    { return 24; }

// the recovery rest die (1d12 + 12)
inline int wnfAnimalRestDieSides()
    { return 12; }

// the recovery rest die bonus
inline int wnfAnimalRestDieBonus()
    { return 12; }

// an incapacitated animal dies if forced to expend appreciable energy for as
// little as one turn
inline int wnfAnimalEffortDeathTurns()
    { return 1; }

// an incapacitated animal dies after one day in the condition even if
// unencumbered and stationary
inline int wnfAnimalIncapIdleDeathDays()
    { return 1; }

// a weakened animal has movement and carrying capacity halved
inline bool wnfAnimalMoveCarryHalved()
    { return true; }

// animals recover rather quickly from food or water deprivation
inline bool wnfAnimalsRecoverQuickly()
    { return true; }

// ---- The minimum daily requirement of food ----

// a human, dwarf, half-orc or half-elf needs 1-2 pounds of solid nourishment
// per day: the floor
inline int wnfFoodHumanMinLb()
    { return 1; }

// the daily food requirement ceiling in pounds
inline int wnfFoodHumanMaxLb()
    { return 2; }

// an elf needs three-fourths of a human-sized ration: the numerator
inline int wnfFoodElfNum()
    { return 3; }

// the elf ration fraction denominator (3/4)
inline int wnfFoodElfDen()
    { return 4; }

// a gnome or halfling gets along on half a human ration: the numerator
inline int wnfFoodSmallNum()
    { return 1; }

// the small race fraction (1/2)
inline int wnfFoodSmallDen()
    { return 2; }

// a ration pack feeds one human for one week (seven days)
inline int wnfRationWeekDays()
    { return 7; }

// the standard rations pack encumbrance value in gold pieces
inline int wnfStdRationEncGp()
    { return 200; }

// the standard rations pack actual weight in pounds (140 gp)
inline int wnfStdRationWeightLb()
    { return 14; }

// the standard rations pack bulk accounts for the other 60 gp
inline int wnfStdRationBulkGp()
    { return 60; }

// the minimum daily requirement of standard rations: two pounds
inline int wnfStdRationDailyLb()
    { return 2; }

// the iron rations pack encumbrance value
inline int wnfIronRationEncGp()
    { return 75; }

// the iron rations bulk: perhaps as little as 5 gp
inline int wnfIronRationBulkGp()
    { return 5; }

// the iron rations actual weight: 70 gp = 7 pounds
inline int wnfIronRationWeightLb()
    { return 7; }

// the minimum daily requirement of iron rations: one pound
inline int wnfIronRationDailyLb()
    { return 1; }

// one pound of meat provides the nourishment of two pounds of vegetables
inline int wnfMeatVegNourishRatio()
    { return 2; }

// a character should eat at least twice a day (after a night rest, at the end
// of the day)
inline int wnfMealsPerDayMin()
    { return 2; }

// a missed meal: the DM may assign -1 "to hit"
inline int wnfMissedMealToHitMod()
    { return -1; }

// a missed meal: +1 on Strength or Constitution checks, until the next
// nourishment
inline int wnfMissedMealCheckMod()
    { return 1; }

// cheating by half the recommended amount: the numerator (1/2)
inline int wnfHalfRationCheatNum()
    { return 1; }

// the cheat fraction denominator
inline int wnfHalfRationCheatDen()
    { return 2; }

// half rations sustain normal activity for 1.5 times the tolerance level
// rounded down: the numerator
inline int wnfHalfRationDaysNum()
    { return 3; }

// the half-ration days multiple denominator (3/2)
inline int wnfHalfRationDaysDen()
    { return 2; }

// overeating offers no significant benefit in game terms
inline bool wnfOvereatingNoBenefit()
    { return true; }

// one full ration on any single day offsets the half-ration weakness
inline bool wnfHalfRationFullMealRecovers()
    { return true; }

// without significant physical activity a character subsists on half rations
// indefinitely
inline bool wnfHalfRationIndefiniteIfIdle()
    { return true; }

// below-average strength or constitution is especially susceptible to a
// missed meal
inline bool wnfMissedMealBelowAvgSusceptible()
    { return true; }

// ---- The minimum daily requirement of water ----

// the effective temperature band: below 50 0, 50-70 1, 71-90 2, above 90 3
inline int wnfTempBandFor(int t)
    {
        if (t <= 49) return 0;
        if (t <= 70) return 1;
        if (t <= 90) return 2;
        return 3;
    }

// the Table 29 inactive pints per temperature band
inline int wnfWaterPintInact(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 8;
        default:
            return 0;
        }
    }

// the light activity pints
inline int wnfWaterPintLight(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 10;
        default:
            return 0;
        }
    }

// the moderate activity pints
inline int wnfWaterPintMod(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 9;
        case 2:
            return 10;
        case 3:
            return 12;
        default:
            return 0;
        }
    }

// the heavy activity pints
inline int wnfWaterPintHeavy(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 12;
        case 3:
            return 16;
        default:
            return 0;
        }
    }

// the Table 29 temperature band count (below 50, 50-70, 71-90, above 90)
inline int wnfTempBandCount()
    { return 4; }

// elves need one-fourth less water: the numerator
inline int wnfElfWaterRedNum()
    { return 1; }

// the elf water reduction fraction (1/4, rounded up to the nearest half-pint)
inline int wnfElfWaterRedDen()
    { return 4; }

// dwarves, gnomes and halflings need one-third less water: the numerator
inline int wnfDemiWaterRedNum()
    { return 1; }

// the demihuman water reduction fraction (1/3, rounded up to the nearest pint
// or half-pint)
inline int wnfDemiWaterRedDen()
    { return 3; }

// high-water-content food covers one-fourth to one-third of the daily water
// requirement: the lower numerator
inline int wnfHighWaterFoodMinNum()
    { return 1; }

// the lower fraction denominator (1/4)
inline int wnfHighWaterFoodMinDen()
    { return 4; }

// the upper fraction numerator
inline int wnfHighWaterFoodMaxNum()
    { return 1; }

// the upper fraction denominator (1/3)
inline int wnfHighWaterFoodMaxDen()
    { return 3; }

// inactive: one hour or less of significant physical activity in the day
inline int wnfInactHourLimit()
    { return 1; }

// light activity: more than one hour on non-sedentary pursuits
inline int wnfLightHourOver()
    { return 1; }

// moderate activity: more than two hours
inline int wnfModerateHourOver()
    { return 2; }

// heavy activity: more than four hours
inline int wnfHeavyHourOver()
    { return 4; }

// one cubic foot of water contains seven gallons
inline int wnfCubicFootGallons()
    { return 7; }

// there are eight pints in a gallon
inline int wnfGallonPints()
    { return 8; }

// water has an encumbrance value of 50 gp per gallon
inline int wnfWaterEncPerGallon()
    { return 50; }

// plus an extra 50 gp for every three gallons transported in a single
// container
inline int wnfContainerEncPerGallons()
    { return 3; }

// the per-container-bulk charge in gold pieces
inline int wnfContainerEncGp()
    { return 50; }

// a typical waterskin holds one gallon
inline int wnfWaterskinGallons()
    { return 1; }

}   // namespace rules
