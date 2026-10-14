// =========================================================================================
// Adnd1 - rules/wsgheat.h
// The WSG DAMAGE FROM HEAT AND COLD, R430: the data slice of the
// heat-and-cold section - Table 9 (the temperature damage to characters) and
// Table 10 (the frostbite damage to characters) with the adjustment,
// hypothermia, frostbite and heatstroke prose pins.
// census 354 -> 355.
//
// Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed
// pp. 25-27, cross-checked against the user own copy and the user eye-read of
// the Table 10 combination rows (the Frostbite Occurs At cells are blank in
// print).
//
// Sentinel: 99 = the printed dash (no Con Check); 0 in Table 10 = blank in
// print. Table 10 shares pin in sixths (2/3 = 4, 1/3 = 2, 1/2 = 3, all = 6,
// absent = 0); thresholds only on the single-part rows (Feet 4, Ears 6, Hands
// 8 pts).
//
namespace rules {

// ---- Table 9: the temperature damage ----

// The Table 9 band count.
inline int wshDmgBandCount()
    { return 25; }

// The Con modifier, unprotected.
inline int wshHeatConUnprot(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 13;
        case 2:
            return 12;
        case 3:
            return 11;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 9;
        case 7:
            return 8;
        case 8:
            return 7;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 4;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 99;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 5;
        case 24:
            return 6;
        default:
            return 99;
        }
    }

// The maximum damage, unprotected.
inline int wshHeatDmgUnprot(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 7;
        case 3:
            return 7;
        case 4:
            return 6;
        case 5:
            return 6;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 99;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 5;
        case 24:
            return 6;
        default:
            return 99;
        }
    }

// The Con modifier, protected.
inline int wshHeatConProt(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 8;
        case 2:
            return 7;
        case 3:
            return 6;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 99;
        case 12:
            return 99;
        case 13:
            return 99;
        case 14:
            return 99;
        case 15:
            return 99;
        case 16:
            return 99;
        case 17:
            return 99;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        default:
            return 99;
        }
    }

// The maximum damage, protected.
inline int wshHeatDmgProt(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 99;
        case 12:
            return 99;
        case 13:
            return 99;
        case 14:
            return 99;
        case 15:
            return 99;
        case 16:
            return 99;
        case 17:
            return 99;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 4;
        default:
            return 99;
        }
    }

// The Table 9 dash census, unprotected: 2 cells.
inline int wshT9DashUnprotCensus()
    { return 2; }

// The Table 9 dash census, protected: 14 cells.
inline int wshT9DashProtCensus()
    { return 14; }

// The temperature damage band dispatch (Table 9 row), -60 or lower up to 120
// or higher.
inline int wshHeatBandFor(int t)
    {
        if (t <= -60) return 0;
        if (t <= -50) return 1;
        if (t <= -40) return 2;
        if (t <= -30) return 3;
        if (t <= -25) return 4;
        if (t <= -20) return 5;
        if (t <= -15) return 6;
        if (t <= -10) return 7;
        if (t <= -5) return 8;
        if (t <= 0) return 9;
        if (t <= 5) return 10;
        if (t <= 10) return 11;
        if (t <= 15) return 12;
        if (t <= 20) return 13;
        if (t <= 25) return 14;
        if (t <= 30) return 15;
        if (t <= 84) return 16;
        if (t <= 89) return 17;
        if (t <= 94) return 18;
        if (t <= 99) return 19;
        if (t <= 104) return 20;
        if (t <= 109) return 21;
        if (t <= 114) return 22;
        if (t <= 119) return 23;
        return 24;
    }

// ---- Table 10: the frostbite damage ----

// The Table 10 row count.
inline int wshFrostRowCount()
    { return 7; }

// The feet share in sixths.
inline int wshFrostFeetShare(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The ears share in sixths.
inline int wshFrostEarsShare(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 6;
        case 2:
            return 0;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The hands share in sixths.
inline int wshFrostHandsShare(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 6;
        case 3:
            return 3;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 2;
        default:
            return 0;
        }
    }

// The single-part threshold in points, 0 = blank in print.
inline int wshFrostPts(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        default:
            return 0;
        }
    }

// The Table 10 blank threshold census: 4 cells.
inline int wshT10BlankCensus()
    { return 4; }

// Frostbite risk at effective temperature 0 or lower.
inline int wshFrostbiteTempMax()
    { return 0; }

// Severe frostbite at +4 points past onset.
inline int wshSevereFrostPlus()
    { return 4; }

// The Table 10 combination rows carry no separate threshold cell - blank in
// print.
inline bool wshFrostComboNoThreshold()
    { return true; }

// ---- the check and damage rules ----

// A Constitution Check every 3 turns.
inline int wshConCheckEveryTurns()
    { return 3; }

// The damage alternative: 10 percent of current hit points.
inline int wshDmgHpPct()
    { return 10; }

// Damage 1-7 rolls 1d8, reroll an 8.
inline int wshDmgRerollDie()
    { return 8; }

// A damage adjustment needs 1 full non-normal turn of the 3.
inline int wshAdjTurnsMin()
    { return 1; }

// Multiple activity categories: the least favorable one applies.
inline bool wshLeastFavorableAdj()
    { return true; }

// Heat/cold hit points recover at 1 per hour.
inline int wshRecoverHpPerHour()
    { return 1; }

// The hourly recovery needs a tolerable temperature and rest or minimal
// activity.
inline bool wshRecoverNeedsTolerable()
    { return true; }

// The Con Check adj, level 4-6.
inline int wshConAdjL46()
    { return -1; }

// The Con Check adj, level 7-9.
inline int wshConAdjL79()
    { return -2; }

// The Con Check adj, level 10-12.
inline int wshConAdjL1012()
    { return -3; }

// The Con Check adj, level 13-15.
inline int wshConAdjL1315()
    { return -4; }

// The Con Check adj, level 16 and up.
inline int wshConAdjL16()
    { return -5; }

// ---- the damage adjustments ----

// Stationary, cold: +1 to +3 damage.
inline int wshStatColdMin()
    { return 1; }

// The stationary cold maximum.
inline int wshStatColdMax()
    { return 3; }

// Stationary, hot: -1 to -3 damage.
inline int wshStatHotMin()
    { return -3; }

// The stationary hot maximum.
inline int wshStatHotMax()
    { return -1; }

// Strenuous, cold: +1 to +2 damage.
inline int wshStrenColdMin()
    { return 1; }

// The strenuous cold maximum.
inline int wshStrenColdMax()
    { return 2; }

// Strenuous, hot: +1 to +4 damage.
inline int wshStrenHotMin()
    { return 1; }

// The strenuous hot maximum.
inline int wshStrenHotMax()
    { return 4; }

// Fatigued and not resting: +1 to +6 damage.
inline int wshFatigMin()
    { return 1; }

// The fatigued maximum.
inline int wshFatigMax()
    { return 6; }

// ---- the hypothermia rules ----

// Hypothermia: 3 consecutive fails, unprotected.
inline int wshHypoUnprotFails()
    { return 3; }

// Hypothermia: 6 consecutive fails, protected.
inline int wshHypoProtFails()
    { return 6; }

// Hypothermia: 1 physical score point per turn.
inline int wshHypoPhysPerTurn()
    { return 1; }

// Hypothermia: 1 wisdom point every 2 turns.
inline int wshHypoWisPerTurns()
    { return 2; }

// The hypothermia score floor: 3.
inline int wshHypoScoreFloor()
    { return 3; }

// Two physical scores at 3: incapacitated.
inline int wshHypoIncapScores()
    { return 2; }

// Unconscious in 1d3 turns.
inline int wshHypoUnconcDie()
    { return 3; }

// Death in 2d4 turns after.
inline int wshHypoDeathDie()
    { return 4; }

// Hypothermia recovery: 1 point per category per hour.
inline int wshHypoRecoverPerHour()
    { return 1; }

// A relapse chance after re-entering the cold: 50 percent.
inline int wshHypoRelapsePct()
    { return 50; }

// The hypothermia death comes regardless of hit points left.
inline bool wshHypoDeathRegardlessHp()
    { return true; }

// ---- the frostbite extremity rules ----

// Frostbitten ears: -1 on initiative.
inline int wshFrostEarInitPenalty()
    { return -1; }

// Frostbitten ears: surprise chance +1 in 6.
inline int wshFrostEarSurpriseDen()
    { return 6; }

// Severe ear frostbite treated within 2 turns or permanent damage.
inline int wshFrostEarTreatTurns()
    { return 2; }

// Frostbitten feet: half normal move (numerator).
inline int wshFrostFeetMoveNum()
    { return 1; }

// The feet move denominator.
inline int wshFrostFeetMoveDen()
    { return 2; }

// Frostbitten feet: a two-step AC penalty.
inline int wshFrostFeetAcPenalty()
    { return 2; }

// Severe foot frostbite treated within 1 turn or permanent damage.
inline int wshFrostFeetTreatTurns()
    { return 1; }

// Frostbitten hands: -6 with a missile weapon.
inline int wshFrostHandsMissile()
    { return -6; }

// Frostbitten hands: -4 with a melee weapon.
inline int wshFrostHandsMelee()
    { return -4; }

// Severely frostbitten hands: the melee penalty lessens to -2.
inline int wshFrostHandsSevereMelee()
    { return -2; }

// Severe hand frostbite treated within 2 turns or permanent damage.
inline int wshFrostHandsTreatTurns()
    { return 2; }

// Riding or carried: no feet move or AC penalty.
inline bool wshFrostRidingNoMovePenalty()
    { return true; }

// Severely frostbitten ears are numb: the penalties no longer apply.
inline bool wshFrostSevereEarsNoPenalty()
    { return true; }

// Severely frostbitten feet: normal speed again, the AC penalty stays.
inline bool wshFrostSevereFeetNormalMove()
    { return true; }

// ---- the heatstroke rules ----

// Heatstroke collapse: 50 percent unconscious.
inline int wshHeatstrokeUnconcPct()
    { return 50; }

// Untreated heatstroke: 3 turns, then Con loss.
inline int wshHeatstrokeOnsetTurns()
    { return 3; }

// Heatstroke Con loss: 1 point per turn.
inline int wshHeatstrokeConPerTurn()
    { return 1; }

// The heatstroke recovery numerator: two-thirds rounded up.
inline int wshHeatstrokeRegainNum()
    { return 2; }

// The heatstroke denominator.
inline int wshHeatstrokeRegainDen()
    { return 3; }

// Heatstroke: all Constitution Checks automatically fail.
inline bool wshHeatstrokeAutoFail()
    { return true; }

// Heatstroke: maximum damage whenever heat damage is indicated.
inline bool wshHeatstrokeMaxDamage()
    { return true; }

// Heatstroke: Con 0 means death.
inline bool wshHeatstrokeConZeroDies()
    { return true; }

}   // namespace rules
