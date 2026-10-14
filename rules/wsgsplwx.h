// =========================================================================================
// Adnd1 - rules/wsgsplwx.h
// The WSG SPECIAL WEATHER, R429: the data slice of the special-weather
// section - Table 6 (the hurricane damage to structures), Table 7 (the
// tornado damage to structures) and Table 8 (the hailstorm damage to
// characters) with the hurricane, gale, tornado and sandstorm prose pins.
// census 353 -> 354.
//
// Provenance: the WSG scan (archive.org item pdfy-B3Fz83tZ3TV7zOc8), printed
// pp. 23-24; the three grids read from the IIIF page images and verified
// against the text layer and the letter-code and dice prose.
//
// Sentinel: 0 = a dash cell. Table 6 damage doubles to half-points (1 = 1/2
// point, 2 = 1 point); Table 7 codes 0, 1, 2 = none, damaged, destroyed;
// Table 8 cells are the 1dN die size with 0 = no damage.
//
namespace rules {

// ---- Table 6: the hurricane damage ----

// The Table 6 intensity count.
inline int wswHurrIntensityCount()
    { return 3; }

// The damage vs wood, doubled to half-points.
inline int wswHurrWood(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        default:
            return 0;
        }
    }

// The damage vs earth, doubled to half-points.
inline int wswHurrEarth(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        default:
            return 0;
        }
    }

// The damage vs soft stone, doubled to half-points.
inline int wswHurrSoftStone(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// The damage vs hard rock, doubled to half-points.
inline int wswHurrHardRock(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        default:
            return 0;
        }
    }

// The Table 6 dash census: 3 cells.
inline int wswHurrDashCensus()
    { return 3; }

// ---- Table 7: the tornado damage ----

// The Table 7 structure count.
inline int wswTornadoStructCount()
    { return 6; }

// The roll-1 code: 0 none, 1 damaged, 2 destroyed.
inline int wswTornadoRoll1(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The roll-2 code.
inline int wswTornadoRoll2(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The roll-3 code.
inline int wswTornadoRoll3(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The roll-4 code.
inline int wswTornadoRoll4(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            return 0;
        }
    }

// The roll-5 code.
inline int wswTornadoRoll5(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        default:
            return 0;
        }
    }

// The roll-6 code.
inline int wswTornadoRoll6(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        default:
            return 0;
        }
    }

// The Table 7 dash census: 12 cells.
inline int wswTornadoNoneCensus()
    { return 12; }

// ---- Table 8: the hailstorm damage ----

// The Table 8 armor count.
inline int wswHailArmorCount()
    { return 4; }

// The small-hail die (up to 1/2 inch), 1dN size.
inline int wswHailDieSmall(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 0;
        default:
            return 0;
        }
    }

// The medium-hail die (up to 1 1/2 inches), 1dN size.
inline int wswHailDieMedium(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 2;
        default:
            return 0;
        }
    }

// The large-hail die (over 1 1/2 inches), 1dN size.
inline int wswHailDieLarge(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 3;
        default:
            return 0;
        }
    }

// The Table 8 dash census: 1 cell.
inline int wswHailNoneCensus()
    { return 1; }

// The hailstone size dispatch (Table 8 column) in half-inches: 1 = 1/2 small,
// 3 = 1 1/2 medium, over = large.
inline int wswHailSizeBandFor(int s)
    {
        if (s <= 1) return 0;
        if (s <= 3) return 1;
        return 2;
    }

// ---- the hurricane and gale rules ----

// The structural damage check: once every 3 turns.
inline int wswHurrCheckEveryTurns()
    { return 3; }

// The structural damage chance per check: 50 percent.
inline int wswHurrCheckChancePct()
    { return 50; }

// A light hurricane: winds of at least 80 mph.
inline int wswHurrLightWindMin()
    { return 80; }

// A normal hurricane: winds from 100 mph.
inline int wswHurrNormalWindMin()
    { return 100; }

// A normal hurricane: winds up to 140 mph.
inline int wswHurrNormalWindMax()
    { return 140; }

// A heavy hurricane: winds as great as 200 mph.
inline int wswHurrHeavyWindMax()
    { return 200; }

// Blown across the ground: 50 percent of 1d3 damage.
inline int wswHurrUnshelteredDie()
    { return 3; }

// Thrown to the ground in the wind: 1d6 damage.
inline int wswHurrThrownDie()
    { return 6; }

// A gale: from 46 mph.
inline int wswGaleWindMin()
    { return 46; }

// A gale: up to 79 mph.
inline int wswGaleWindMax()
    { return 79; }

// A structure collapses when the damage reaches its defensive point value.
inline bool wswHurrStructCollapseAtDpv()
    { return true; }

// A severe gale may be treated as a light hurricane for structural damage.
inline bool wswGaleAsLightHurr()
    { return true; }

// ---- the tornado rules ----

// Caught in the open: 4d20 debris damage.
inline int wswTornadoDebrisDice()
    { return 4; }

// The tornado debris die: d20.
inline int wswTornadoDebrisDie()
    { return 20; }

// The lift height: 1d6 x 10 feet.
inline int wswTornadoLiftDie()
    { return 6; }

// The lift height multiplier.
inline int wswTornadoLiftMult()
    { return 10; }

// The carry: 1d6 x 100 yards (100-600).
inline int wswTornadoCarryMult()
    { return 100; }

// Occupant debris damage: 3d10 destroyed, 3d6 damaged.
inline int wswTornadoOccDice()
    { return 3; }

// Structure destroyed: 3d10 to each occupant.
inline int wswTornadoStructDestroyedDie()
    { return 10; }

// Structure damaged: 3d6 to each occupant.
inline int wswTornadoStructDamagedDie()
    { return 6; }

// A destroyed structure: 1 in 10 one character lifted.
inline int wswTornadoLiftChanceDen()
    { return 10; }

// Inside in the storm: 1 in 6 unnoticed by day.
inline int wswTornadoUnnoticedDayNum()
    { return 1; }

// Inside in the storm: 2 in 6 unnoticed at night.
inline int wswTornadoUnnoticedNightNum()
    { return 2; }

// The unnoticed chance die: d6.
inline int wswTornadoUnnoticedDen()
    { return 6; }

// Anything flimsier than light wood is destroyed by a tornado.
inline bool wswTornadoFlimsyAutoDestroys()
    { return true; }

// ---- the sandstorm rules ----

// Unshielded eyes: blinded on 1, partial on 2-3, 1d6.
inline int wswSandBlindDie()
    { return 6; }

// The blindness check: once every 3 rounds.
inline int wswSandCheckEveryRounds()
    { return 3; }

// A partial victim blinds 3 rounds later unaided.
inline int wswSandPartialWindow()
    { return 3; }

// Vs a blinded victim: +4 to hit, +4 melee damage.
inline int wswSandBlindMeleeBonus()
    { return 4; }

// Vs a partial victim: +2 to hit, no damage bonus.
inline int wswSandPartialHitBonus()
    { return 2; }

// Unprotected nose and mouth: a 1 in 6 choking fit per round.
inline int wswSandChokeDen()
    { return 6; }

// The fit worsens next round on 3 in 6.
inline int wswSandChokeWorsenNum()
    { return 3; }

// The worsened fit: 1d3 damage.
inline int wswSandChokeWorsenDie()
    { return 3; }

// The third round: disabled on 4 in 6.
inline int wswSandChokeThirdNum()
    { return 4; }

// Eyes washed with water: recovered in 2d4 hours.
inline int wswSandWashedDice()
    { return 2; }

// The washed-eye recovery die.
inline int wswSandWashedDie()
    { return 4; }

// An unwashed partial victim recovers in 12 hours.
inline int wswSandPartialRecoverHours()
    { return 12; }

// An unwashed blind victim recovers to partial in 24 hours.
inline int wswSandBlindRecoverHours()
    { return 24; }

// A blinded character cannot attack (or attacks at a substantial penalty at
// the DM option).
inline bool wswSandBlindCannotAttack()
    { return true; }

// Vs a partial victim the +2 is to hit only, never to damage.
inline bool wswSandPartialNoDamageBonus()
    { return true; }

// Any treatment fails unless the eyes stay closed and covered for the healing
// period.
inline bool wswSandEyesMustStayCovered()
    { return true; }

// Blowing-snow blindness recovers in 1d6 turns; nonmagical efforts do not
// hasten it.
inline bool wswSnowNonmagicNoHasten()
    { return true; }

// ---- the hailstorm rules ----

// Unprotected in hail: 50 percent per round.
inline int wswHailChancePct()
    { return 50; }

// AC 4 or better plus cover: no hail damage.
inline int wswHailArmorAcMax()
    { return 4; }

// No precautions: +1d2 per round of damage taken.
inline int wswHailUnprotectedDie()
    { return 2; }

// A small shield halves the damage, minimum 1.
inline int wswHailShieldFloor()
    { return 1; }

// Squatting in AC 4 or better avoids hail damage entirely.
inline bool wswHailAcSquatAvoids()
    { return true; }

// The hail-protection posture makes a character easier to hit.
inline bool wswHailEasierTarget()
    { return true; }

// A small shield in the protected position halves hail damage.
inline bool wswHailShieldHalves()
    { return true; }

// An ice or sleet storm does no damage with precautions taken and the body
// kept moving.
inline bool wswIceSleetNoDamageMoving()
    { return true; }

}   // namespace rules
