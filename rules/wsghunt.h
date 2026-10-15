// =========================================================================================
// Adnd1 - rules/wsghunt.h
// R464: the WSG HUNTING AND STALKING slice - hunting (the four-turn check,
// the -5% per party member beyond the first, the -10% midday shift, the
// missile-weapon requirement, the 1d10 hit procedure), stalking a wounded
// animal (the enraged size L charge and the panicked size M flight) and Table
// 31 (the 33-row terrain-by-season hunting success grid), printed pp. 55-56.
// census 388 -> 389.
//
// Ground truth three-way: the archive djvu word layer vs the pixel reads of
// the leaf 0055 spread (the full native 2444x3176 decode) vs vision reads of
// upscaled cell sheets. The two text layers garble four Table 31 cells; the
// pixels settled them (temperate mountains winter 25, not 15; arctic desert
// spring 5, not 30; tropical mountains summer and autumn 40, not 10). The
// game-encounter list row 6 is pixel-confirmed as size L, 1d3 creatures at
// 60-80 yards - the djvu 50-60 is a garble. NOTED BOOK DISCREPANCY: the p. 56
// example prints a 35% chance for three hunters in a tropical forest, but
// Table 31 prints 50 and the party rule takes it to 40; the rule is pinned as
// printed and only the internally consistent examples are pinned.
//
// All 132 grid cells and all 30 encounter list cells pinned; the hunting
// mechanics (the four-turn check, the party and midday modifiers, the 1d10
// hit procedure, the charge and flight rules) are audit examples.
//
namespace rules {

// ---- Table 31: the hunting success grid ----

// the Table 31 terrain row count: 5 arctic rows, 7 rows in each of the other
// four climate regions
inline int whnRowCount()
    { return 33; }

// the Table 31 winter column
inline int whnWin(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 10;
        case 13:
            return 30;
        case 14:
            return 25;
        case 15:
            return 25;
        case 16:
            return 25;
        case 17:
            return 20;
        case 18:
            return 20;
        case 19:
            return 10;
        case 20:
            return 50;
        case 21:
            return 50;
        case 22:
            return 35;
        case 23:
            return 50;
        case 24:
            return 50;
        case 25:
            return 40;
        case 26:
            return 5;
        case 27:
            return 50;
        case 28:
            return 50;
        case 29:
            return 40;
        case 30:
            return 50;
        case 31:
            return 50;
        case 32:
            return 50;
        default:
            return 0;
        }
    }

// the Table 31 spring column
inline int whnSpr(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 10;
        case 8:
            return 5;
        case 9:
            return 10;
        case 10:
            return 15;
        case 11:
            return 10;
        case 12:
            return 5;
        case 13:
            return 50;
        case 14:
            return 40;
        case 15:
            return 30;
        case 16:
            return 40;
        case 17:
            return 40;
        case 18:
            return 35;
        case 19:
            return 5;
        case 20:
            return 50;
        case 21:
            return 50;
        case 22:
            return 35;
        case 23:
            return 50;
        case 24:
            return 50;
        case 25:
            return 50;
        case 26:
            return 5;
        case 27:
            return 50;
        case 28:
            return 50;
        case 29:
            return 40;
        case 30:
            return 50;
        case 31:
            return 50;
        case 32:
            return 50;
        default:
            return 0;
        }
    }

// the Table 31 summer column
inline int whnSum(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 15;
        case 8:
            return 10;
        case 9:
            return 15;
        case 10:
            return 20;
        case 11:
            return 15;
        case 12:
            return 5;
        case 13:
            return 50;
        case 14:
            return 40;
        case 15:
            return 30;
        case 16:
            return 50;
        case 17:
            return 50;
        case 18:
            return 50;
        case 19:
            return 5;
        case 20:
            return 50;
        case 21:
            return 50;
        case 22:
            return 35;
        case 23:
            return 50;
        case 24:
            return 50;
        case 25:
            return 50;
        case 26:
            return 5;
        case 27:
            return 50;
        case 28:
            return 50;
        case 29:
            return 40;
        case 30:
            return 50;
        case 31:
            return 50;
        case 32:
            return 50;
        default:
            return 0;
        }
    }

// the Table 31 autumn column
inline int whnAut(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 5;
        case 6:
            return 5;
        case 7:
            return 15;
        case 8:
            return 5;
        case 9:
            return 15;
        case 10:
            return 20;
        case 11:
            return 10;
        case 12:
            return 10;
        case 13:
            return 50;
        case 14:
            return 40;
        case 15:
            return 30;
        case 16:
            return 50;
        case 17:
            return 50;
        case 18:
            return 50;
        case 19:
            return 5;
        case 20:
            return 50;
        case 21:
            return 50;
        case 22:
            return 35;
        case 23:
            return 50;
        case 24:
            return 50;
        case 25:
            return 50;
        case 26:
            return 5;
        case 27:
            return 50;
        case 28:
            return 50;
        case 29:
            return 40;
        case 30:
            return 50;
        case 31:
            return 50;
        case 32:
            return 50;
        default:
            return 0;
        }
    }

// ---- The hunting check ----

// a hunting check covers four turns of hunting
inline int whnCheckTurns()
    { return 4; }

// each party member beyond the first lowers the encounter chance by 5%,
// cumulative
inline int whnPartyPenaltyPct()
    { return 5; }

// from mid-morning to mid-evening the encounter chance drops by 10% (the
// table assumes early morning or late evening)
inline int whnMiddayPenaltyPct()
    { return 10; }

// hunting at night is impossible without infravision or ultravision (with
// them, use the table as given)
inline bool whnNightNeedsVision()
    { return true; }

// a hunting missile weapon must average at least 3 hp of damage against size
// L (a bow qualifies; a thrown dagger or club does not)
inline int whnMissileMinAvgDamage()
    { return 3; }

// a melee weapon may be used only to finish off a wounded kill, never for the
// hunting shot
inline bool whnMeleeFinishOnly()
    { return true; }

// ---- The game encounter list ----

// the game-encounter list row count: the 1d6 dispatch
inline int whnEncRowCount()
    { return 6; }

// the encounter size band: 0 = S, 1 = M, 2 = L
inline int whnEncSize(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        default:
            return 0;
        }
    }

// the creature-count dice
inline int whnEncDice(int b)
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
            return 1;
        case 5:
            return 1;
        default:
            return 0;
        }
    }

// the creature-count die size
inline int whnEncDie(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 6;
        case 2:
            return 10;
        case 3:
            return 6;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return 0;
        }
    }

// the minimum encounter range in yards
inline int whnEncRangeMin(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 40;
        case 4:
            return 40;
        case 5:
            return 60;
        default:
            return 0;
        }
    }

// the maximum encounter range in yards
inline int whnEncRangeMax(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 40;
        case 2:
            return 40;
        case 3:
            return 60;
        case 4:
            return 60;
        case 5:
            return 80;
        default:
            return 0;
        }
    }

// the DM rolls 1d10 repeatedly; a result greater than the creature-count roll
// is a hit
inline int whnHitDieSize()
    { return 10; }

// hits to kill by size band: one for size S, two for size M, four for size L
inline int whnHitsToKill(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 4;
        default:
            return 4;
        }
    }

// hits are applied one animal at a time until it is dead or wounded
inline bool whnHitsOneAnimalAtATime()
    { return true; }

// when the encounter is negated because no missile weapon reaches the range,
// the group may hunt again after 4 more turns
inline int whnRetryTurns()
    { return 4; }

// ---- Stalking a wounded animal ----

// a wounded animal is finished off by a missile fired from 20 feet or less,
// or hand-to-hand
inline int whnStalkRangeFeet()
    { return 20; }

// the enraged wounded size L animal charges one character - the closest, or a
// random one if two are equidistant
inline bool whnWoundedLChargesClosest()
    { return true; }

// a wounded size L animal charges: 50% chance it inflicts damage before any
// retaliation
inline int whnWoundedLChargePct()
    { return 50; }

// the enraged size L charge inflicts 1d8 damage
inline int whnWoundedLChargeDie()
    { return 8; }

// to hit a wounded animal in the stalk, strike against AC 5
inline int whnWoundedAC()
    { return 5; }

// a panicked wounded size M animal flees at 18 inches per round
inline int whnWoundedMFleeRate()
    { return 18; }

// the panicked size M flight direction on 1d4: 1 toward the hunters band 0,
// 2-3 perpendicular band 1, 4 directly away band 2
inline int whnWoundedMFleeBand(int r)
    {
        if (r <= 1) return 0;
        if (r <= 3) return 1;
        return 2;
    }

// a fleeing wounded size M animal is killed if a character gets within 20
// feet and hits against AC 5
inline int whnWoundedMKillRangeFeet()
    { return 20; }

// a fleeing wounded size M animal escapes if no character hits on the first
// available opportunity round
inline bool whnWoundedMEscapesOnFirstMiss()
    { return true; }

}   // namespace rules
