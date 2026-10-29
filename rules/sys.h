// =========================================================================================
// Adnd1 - rules/sys.h
// The systems round - Pickens' D&D Option: Weapon Damage (folio 30) and
// Seaton's Monkish Combat in the Arena of Promotion (folios 4-5)
// census 815 -> 816.
//
// Pinned from The Dragon Vol. 1 No. 2 (August 1976): folio 30, Jon Pickens'
// Weapon Damage option - the expertise system replacing the Greyhawk damage
// tables, the seventeen-weapon Normal/Expert grid with the space
// requirements; folios 4-5, John M. Seaton's Monkish promotion combat - the
// DPT/DPG frame, the set-and-unit structure, the recovery doctrine, and the
// strike-block-kick matrix, playtested by the Missouri Mercenary Group.
// OD&D-era ink converted per the walk doctrine: the pin IS the conversion,
// noted, never silent.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// Weapon Damage option rides against the engine's canon damage tables as a
// noted variant, never a rewrite; the monk matrix codes are CONVERTED to
// integers for the grid - 0 normal DPG, 1 blocked, 2 double DPG, 3 triple
// DPG, 4 sweep succeeds, 5 grab, 6 not applicable - the legend pinned beside
// the grid, the conversion noted, never silent; the five-eighths roll of
// dexterity is pinned as scanned.
//
namespace rules {

// ---- the Weapon Damage option (folio 30) ----

// for every THREE levels a Fighter advances he masters one additional weapon,
// scoring the Expert damage (folio 30)
inline int sysFighterLevelsPerWeapon()
    { return 3; }

// the Thief masters one weapon per FOUR levels, and only sword, dagger, a
// combination of these, or the sling (folio 30)
inline int sysThiefLevelsPerWeapon()
    { return 4; }

// the Thief's expertise list runs four: sword, dagger, the combination, the
// sling (folio 30)
inline int sysThiefWeaponCount()
    { return 4; }

// a Fighter or Thief with dexterity 13 or better may take a two one-handed
// weapon combination instead of a single expertise (folio 30)
inline int sysTwoWeaponDexMin()
    { return 13; }

// Sword and Sword, or Flail and Morning Star, require dexterity 16 -
// especially difficult to master; only one Morning Star and/or Flail per
// combination (folio 30)
inline int sysHardComboDexMin()
    { return 16; }

// the 2-Handed Sword requires Strength 16 (folio 30)
inline int sysTwoHandedStrMin()
    { return 16; }

// the 2-Handed Sword also requires dexterity 9 (folio 30)
inline int sysTwoHandedDexMin()
    { return 9; }

// the Military Pick or Battle Axe may be wielded one-handed at Strength 16
// and dexterity 9 (folio 30)
inline int sysOneHandStrMin()
    { return 16; }

// the one-handed pick or axe dexterity floor - 9 (folio 30)
inline int sysOneHandDexMin()
    { return 9; }

// the weapon grid runs seventeen rows, Dagger through Sling Stone (folio 30)
inline int sysWeaponRows()
    { return 17; }

// the two-weapon wielder strikes once with each weapon, or once with either
// and counts as shielded (folio 30)
inline bool sysTwoWeaponShielded()
    { return true; }

// no expertise bonus while employing the two-weapon option, even if the
// wielder has it for either weapon (folio 30)
inline bool sysNoExpertiseInCombo()
    { return true; }

// only one Morning Star and/or Flail may be used in a combination (folio 30)
inline bool sysOneFlailMorningStar()
    { return true; }

// the Normal damage floor per weapon - Dagger 1 through Pike 1
inline int sysWpnNormMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        default:
            return 0;
        }
    }

// the Normal damage ceiling - Dagger 4 through the 2-Handed Sword and Mounted
// Lance 12
inline int sysWpnNormMax(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 8;
        case 9:
            return 10;
        case 10:
            return 12;
        case 11:
            return 10;
        case 12:
            return 12;
        case 13:
            return 12;
        case 14:
            return 12;
        case 15:
            return 6;
        case 16:
            return 4;
        default:
            return 0;
        }
    }

// the Expert damage floor - most stay at 1, the spears and 2-Handed Sword
// rise to 2 and 3
inline int sysWpnExpMin(int b)
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
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        default:
            return 0;
        }
    }

// the Expert damage ceiling - Dagger 5 through the Mounted Lance 24
inline int sysWpnExpMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 12;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 12;
        case 9:
            return 16;
        case 10:
            return 12;
        case 11:
            return 12;
        case 12:
            return 18;
        case 13:
            return 24;
        case 14:
            return 12;
        case 15:
            return 6;
        case 16:
            return 6;
        default:
            return 0;
        }
    }

// the space the weapon needs on each side of the user - 0 for none, 4 or 5
// feet for the starred, 6 feet for the triple-starred
inline int sysWpnSpace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 0;
        case 5:
            return 6;
        case 6:
            return 5;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 0;
        case 16:
            return 0;
        default:
            return 0;
        }
    }

// ---- the promotion arena frame (folios 4-5) ----

// Damage Points Taken = strength x constitution, plus 10 times the monk's
// level (folio 4)
inline int sysDptLevelMult()
    { return 10; }

// Damage Points Given = strength + dexterity + half intelligence (folio 4)
inline int sysDpgIntDiv()
    { return 2; }

// each combat turn runs 10 sets (folio 4)
inline int sysSetsPerTurn()
    { return 10; }

// each set runs 6 written units of combat (folio 4)
inline int sysUnitsPerSet()
    { return 6; }

// below three-quarters of his DPT, all the combatant's succeeding blows land
// at half strength (folio 4)
inline int sysHalfStrengthPct()
    { return 75; }

// the half-strength divisor (folio 4)
inline int sysHalfStrengthDiv()
    { return 2; }

// changing an order after a unit is read takes a five-eighths roll of
// dexterity, pinned as scanned (folio 4)
inline int sysChangeRollNum()
    { return 5; }

// the roll's denominator - eighths (folio 4)
inline int sysChangeRollDen()
    { return 8; }

// up to three of the same type kicks may be used in a row (folio 4)
inline int sysKickRowMax()
    { return 3; }

// when kicking, the hands are used in one or two blocks (folio 4)
inline int sysKickHandBlocksMax()
    { return 2; }

// Jump Back and Jump Forward each move one leg length (folio 5)
inline int sysJumpLegs()
    { return 1; }

// a successful sweep puts the opponent down for three units - he gets up and
// cannot strike; blows struck while down do normal damage (folio 4)
inline int sysSweepDownUnits()
    { return 3; }

// the Stamp can be used only after a successful sweep and has no effect
// otherwise (folio 4) - pinned as the no-effect zero
inline int sysStampAfterSweep()
    { return 0; }

// the grab: the attacker's next three units all tell at normal value, the
// opponent unable to count strikes until the third unit; the blows may be
// blocked (folio 5)
inline int sysGrabUnits()
    { return 3; }

// recovery - for each 10 DPT lost, cure light wounds (folio 4)
inline int sysLightWoundDpt()
    { return 10; }

// for each 50 DPT lost, cure serious wounds (folio 4)
inline int sysSeriousWoundDpt()
    { return 50; }

// for every 150 DPT lost, the combatant must be wished to health (folio 4)
inline int sysWishDpt()
    { return 150; }

// without magic, days of recovery = DPT lost times one half (folio 4)
inline int sysNaturalRecoveryDiv()
    { return 2; }

// kicks will not work within arm's length (folio 4)
inline bool sysKickArmLength()
    { return true; }

// a strike cannot connect outside arm's length - matches start at kicking
// distance (folio 4)
inline bool sysStrikeArmLength()
    { return true; }

// the X-Blocks are two-handed (folio 4)
inline bool sysXBlockTwoHanded()
    { return true; }

// when striking, both feet are grounded (folio 4)
inline bool sysStrikeFeetGrounded()
    { return true; }

// except for the X-Block, both hands may attack, or one attack and one defend
// (folio 4)
inline bool sysHandsSplit()
    { return true; }

// after the initial set, at least one Rest must appear in each remaining set
// (folios 4-5)
inline bool sysRestEachSet()
    { return true; }

// first strike goes to the combatant with the higher DPT at the time (folio
// 4)
inline bool sysFirstStrikeHighDpt()
    { return true; }

// a combatant killed by a first strike gets a return blow only if he beats
// his last DPT score on the five-eighths roll (folio 4)
inline bool sysReturnBlowRoll()
    { return true; }

// a combatant may concede between blows at any time - combat stops and the
// victor is recognized; the advancement challenge is not to kill, though it
// can (folio 4)
inline bool sysConcedeStops()
    { return true; }

// the Duck brings the body mostly below high and middle strikes and kicks
// (folio 5)
inline bool sysDuckHighMiddle()
    { return true; }

// monks will not make an advancement challenge to another while that one is
// recovering (folio 4)
inline bool sysNoChallengeWhileRecovering()
    { return true; }

// ---- the strike-block-kick matrix (folio 5) ----

// the matrix runs eight attack rows - Reverse Punch, Back Fist, Knife Hand,
// Front Kick, Head Kick, Side Kick, Sweep, Stamp (folio 5)
inline int sysMatrixRows()
    { return 8; }

// vs the High Block - shoulders and head
inline int sysVsHB(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Middle Block - shoulders to beltline
inline int sysVsMB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 5;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Low Block - beltline to knees
inline int sysVsLB(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 2;
        default:
            return 9;
        }
    }

// vs the X-Block High - two-handed, the grab column
inline int sysVsXBH(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 2;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 5;
        default:
            return 9;
        }
    }

// vs the X-Block Low - chest to thighs, the grab column
inline int sysVsXBL(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 5;
        default:
            return 9;
        }
    }

// vs the Knee Block - beltline to knee
inline int sysVsKB(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs Rest
inline int sysVsR(int b)
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
            return 5;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 3;
        default:
            return 9;
        }
    }

// vs Jump Back
inline int sysVsJB(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
        case 6:
            return 1;
        case 7:
            return 6;
        default:
            return 9;
        }
    }

// vs Jump Forward
inline int sysVsJF(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        default:
            return 9;
        }
    }

// vs the Duck
inline int sysVsD(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        default:
            return 9;
        }
    }

// vs the Reverse Punch - chest or face
inline int sysVsRP(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Back Fist - head or chest
inline int sysVsBF(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Knife Hand - side, abdomen or head
inline int sysVsKH(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Front Kick - chest or abdomen
inline int sysVsFK(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Head Kick
inline int sysVsHK(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Side Kick - abdomen or chest
inline int sysVsSK(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

// vs the Sweep - the trip
inline int sysVsSW(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 2;
        default:
            return 9;
        }
    }

// vs the Stamp - only after a successful sweep
inline int sysVsST(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 0;
        default:
            return 9;
        }
    }

}   // namespace rules
