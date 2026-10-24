// =========================================================================================
// Adnd1 - rules/mm2q.h
// THE MM2 LETTER Q WALK - THE QUASI-ELEMENTAL LIGHTNING, QUICKLING AND
// QUICKWOOD TURNS (the quasi-elemental lightning and the quickling p. 103,
// the quickling prose onto p. 104, the quickwood (spy tree) p. 104), promoted
// to the live registry; the Q-FLIP round, the Letter Q gap box flips to
// closed
// census 733 -> 734.
//
// Round sixteen of the MM2 arc, the FIFTH single-letter pass (Curtiss Go call
// on the landed letter P walk; the letter Q pin-time walk found THREE
// entries, all with stat blocks - no doctrine-only family heads; the MM1
// registry already owns the quasit print, so no prior-owned index entries
// ride this round)
//
// The pin headers stay the print-fidelity record; the three .lua defs ride
// the R791 data_files extension in the MM1 registry schema (the defensive
// coercers load the verbatim print cells, the QStats grid carries the loader
// values)
//
namespace rules {

// ---- the MM2 letter Q walk round pins (the R811 census) ----

// The MM2 letter Q walk round: the quasi-elemental lightning to quickwood
// turns, the FIFTH single-letter pass (Curtiss Go call on the landed letter P
// walk)
inline int mm2qRound()
    { return 811; }

// The registry census before the R811 promotion (the landed R810 count)
inline int mm2qRegistryBefore()
    { return 723; }

// The registry census after the R811 promotion (3 defs)
inline int mm2qRegistryAfter()
    { return 726; }

// The def count of the R811 walk (the quasi-elemental lightning, the
// quickling and the quickwood)
inline int mm2qDefCount()
    { return 3; }

// The pin-time entry census (3 print entries, all with stat blocks, no
// doctrine-only family heads in the letter Q walk)
inline int mm2qEntryCount()
    { return 3; }

// The stat-block heading census of the walk (every letter Q entry pins a stat
// block)
inline int mm2qStatBlockHeadings()
    { return 3; }

// The doctrine-only family head census (no letter Q family head - no
// GIANT-style doctrine block rides the walk)
inline int mm2qDoctrineHeads()
    { return 0; }

// The letter Q heading census (the quasi-elemental lightning through the
// quickwood)
inline int mm2qLetterQHeadings()
    { return 3; }

// The QStats grid row count (one row per def)
inline int mm2qQStatRows()
    { return 3; }

// The MM2 gap report closed box count after the Q-flip (the R810 census 21 +
// the Letter Q box)
inline int mm2qGapClosed()
    { return 22; }

// The MM2 gap report open box count after the Q-flip (the R810 census 16 -
// the Letter Q box)
inline int mm2qGapOpen()
    { return 15; }

// The prior-owned letter Q index entries (none - the MM1 registry quasit
// print is an MM1 walk, not an MM2 letter Q page)
inline int mm2qPriorOwnedEntries()
    { return 0; }

// ---- the quasi-elemental lightning pins (the R811 MM2 letter Q walk) ----

// The small quasi-elemental strength (6 hit dice, the most common sort on the
// Prime Material Plane)
inline int mm2qQuasiLightningSmallHd()
    { return 6; }

// The medium quasi-elemental strength (9 hit dice)
inline int mm2qQuasiLightningMidHd()
    { return 9; }

// The largest quasi-elemental strength (12 or more hit dice)
inline int mm2qQuasiLightningLargeHd()
    { return 12; }

// The Prime Material Plane encounter percentage (60% small, 30% medium, 10%
// large)
inline int mm2qQuasiLightningPmpSmallPct()
    { return 60; }

// The Prime Material Plane medium-size percentage
inline int mm2qQuasiLightningPmpMidPct()
    { return 30; }

// The Prime Material Plane largest-size percentage
inline int mm2qQuasiLightningPmpLargePct()
    { return 10; }

// The Elemental Plane encounter percentages reversed (10% small)
inline int mm2qQuasiLightningPlaneSmallPct()
    { return 10; }

// The Elemental Plane medium-size percentage
inline int mm2qQuasiLightningPlaneMidPct()
    { return 30; }

// The Elemental Plane largest-size percentage
inline int mm2qQuasiLightningPlaneLargePct()
    { return 60; }

// The leaping arc range in inches (up to 6" to any grounded or metallic
// object of mass greater than 50 gp)
inline int mm2qQuasiLightningArcLeapInches()
    { return 6; }

// The arc target mass threshold in gp
inline int mm2qQuasiLightningArcMassGp()
    { return 50; }

// The ball lightning trigger range in feet (large mass or conductive metal
// within 5 feet)
inline int mm2qQuasiLightningBallTriggerFeet()
    { return 5; }

// The large-mass trigger threshold in gp (2000 or more)
inline int mm2qQuasiLightningBallMassGp()
    { return 2000; }

// The ball lightning damage minimum (1-4, 1-6 or 1-8 by size)
inline int mm2qQuasiLightningBallDamageMin()
    { return 1; }

// The ball lightning damage maximum
inline int mm2qQuasiLightningBallDamageMax()
    { return 8; }

// The ball lightning discharge rounds minimum (6, 9 or 12 rounds depending on
// hit dice)
inline int mm2qQuasiLightningBallRoundsMin()
    { return 6; }

// The ball lightning discharge rounds maximum
inline int mm2qQuasiLightningBallRoundsMax()
    { return 12; }

// The conductive-weapon wielder damage minimum (1-4 per strike)
inline int mm2qQuasiLightningConductionDamageMin()
    { return 1; }

// The conductive-weapon wielder damage maximum
inline int mm2qQuasiLightningConductionDamageMax()
    { return 4; }

// The water attack damage minimum per gallon (1-8)
inline int mm2qQuasiLightningWaterDamageMin()
    { return 1; }

// The water attack damage maximum per gallon
inline int mm2qQuasiLightningWaterDamageMax()
    { return 8; }

// The falling-rain damage per 1/10th inch of precipitation
inline int mm2qQuasiLightningRainDamagePerTenthInch()
    { return 2; }

// Lightning quasi-elementals can be harmed only by +1 or better magic weapons
inline bool mm2qQuasiLightningWeaponFloorPlus1()
    { return true; }

// Lightning and electrical attacks do no damage
inline bool mm2qQuasiLightningImmuneToLightning()
    { return true; }

// Fire and acid do only half-normal damage
inline bool mm2qQuasiLightningFireAcidHalfDamage()
    { return true; }

// Cold does full damage
inline bool mm2qQuasiLightningColdFullDamage()
    { return true; }

// Water attacks do double full normal damage
inline bool mm2qQuasiLightningWaterDoubleDamage()
    { return true; }

// It is generally not possible to conjure quasi-elementals, although powerful
// magic-users have been known to do so
inline bool mm2qQuasiLightningRarelyConjured()
    { return true; }

// The quasi-elemental lightning xpValue (the 1000 + 15/hp block: 1000 +
// 15x21)
inline int mm2qQuasiLightningXpValue()
    { return 1315; }

// The quasi-elemental lightning experience level (the roman VII)
inline int mm2qQuasiLightningXpLevel()
    { return 7; }

// ---- the quickling pins (the R811 MM2 letter Q walk) ----

// The 3-hit-dice individuals in any group (1)
inline int mm2qQuicklingThreeHdInGroup()
    { return 1; }

// The 3-hit-dice individuals in a group of more than 10 (2)
inline int mm2qQuicklingThreeHdInLargeGroup()
    { return 2; }

// The leader hit dice num (a 4-1/2 hit dice leader)
inline int mm2qQuicklingLeaderHdNum()
    { return 4; }

// The leader hit dice bonus (the half die reads +2 hp on the quarter-die
// scale, the loader 1.5 hit-dice settle)
inline int mm2qQuicklingLeaderHdBonus()
    { return 2; }

// The leaders 75% likely to have a poison causing a drugged slumber (save vs.
// poison after each hit)
inline int mm2qQuicklingLeaderPoisonPct()
    { return 75; }

// The 90% likely to be visible when moving, due to speed
inline int mm2qQuicklingVisibleMovingPct()
    { return 90; }

// The quickling save matrix (as 19th-level clerics)
inline int mm2qQuicklingSaveAsClericLevel()
    { return 19; }

// The once-per-day spell-like powers (ventriloquism, forget, levitate,
// shatter, dig, and fire charm)
inline int mm2qQuicklingSpellLikePowers()
    { return 6; }

// The quickling dexterity (18)
inline int mm2qQuicklingDexterity()
    { return 18; }

// The maturity age minimum in years (1 or 2)
inline int mm2qQuicklingMatureYearsMin()
    { return 1; }

// The maturity age maximum in years
inline int mm2qQuicklingMatureYearsMax()
    { return 2; }

// The quickling death age minimum in years (12 to 15)
inline int mm2qQuicklingDeathYearsMin()
    { return 12; }

// The quickling death age maximum in years
inline int mm2qQuicklingDeathYearsMax()
    { return 15; }

// It is impossible to surprise a quickling
inline bool mm2qQuicklingNeverSurprised()
    { return true; }

// When motionless in natural cover they are totally invisible
inline bool mm2qQuicklingInvisibleInNaturalCover()
    { return true; }

// When attacking, quicklings can be seen only as a blur
inline bool mm2qQuicklingSeenOnlyAsBlur()
    { return true; }

// Because of their amazing speed, quicklings have an excellent armor class
inline bool mm2qQuicklingExcellentArmorClassFromSpeed()
    { return true; }

// The quickling xpValue (the 200 + 3/hp block: 200 + 3x5)
inline int mm2qQuicklingXpValue()
    { return 215; }

// The quickling experience level (the roman IV)
inline int mm2qQuicklingXpLevel()
    { return 4; }

// ---- the quickwood pins (the R811 MM2 letter Q walk) ----

// The face 90% unlikely to be noticed unless within 30 feet
inline int mm2qQuickwoodFaceMissPct()
    { return 90; }

// The face notice range in feet
inline int mm2qQuickwoodFaceNoticeFeet()
    { return 30; }

// The face notice range in feet when concealing its sensory organs
inline int mm2qQuickwoodFaceConcealFeet()
    { return 10; }

// The root movement rate (3" per round through the loose top soil)
inline int mm2qQuickwoodRootMoveInches()
    { return 3; }

// The root hit points each (treat roots as large, with 10 hit points each)
inline int mm2qQuickwoodRootHp()
    { return 10; }

// The severed-root allowance (only 6 before it withdraws the others)
inline int mm2qQuickwoodRootSeverLimit()
    { return 6; }

// The other roots minimum (7-12)
inline int mm2qQuickwoodRootCountMin()
    { return 7; }

// The other roots maximum
inline int mm2qQuickwoodRootCountMax()
    { return 12; }

// The root hold weight limit in pounds (under 1000)
inline int mm2qQuickwoodRootWeightLimitPounds()
    { return 1000; }

// The root range in yards (the roots themselves do no damage)
inline int mm2qQuickwoodRootRangeYards()
    { return 30; }

// The host oaks minimum (a mature spy tree causes 2-8 other normal oaks to
// serve as hosts)
inline int mm2qQuickwoodHostsMin()
    { return 2; }

// The host oaks maximum
inline int mm2qQuickwoodHostsMax()
    { return 8; }

// The host control range in inches (up to 36")
inline int mm2qQuickwoodControlRangeInches()
    { return 36; }

// The quickwood infravision in feet (120)
inline int mm2qQuickwoodInfravisionFeet()
    { return 120; }

// The mouthlike opening damage minimum (3-12)
inline int mm2qQuickwoodMawDamageMin()
    { return 3; }

// The mouthlike opening damage maximum
inline int mm2qQuickwoodMawDamageMax()
    { return 12; }

// The spell-energy fear radius in feet per spell level
inline int mm2qQuickwoodFearRadiusFeetPerLevel()
    { return 10; }

// The hollow drumming sound heard for a mile or more
inline int mm2qQuickwoodDrumRangeMiles()
    { return 1; }

// A quickwood is never surprised
inline bool mm2qQuickwoodNeverSurprised()
    { return true; }

// The creature is able to perspire, drenching itself in water so fire does
// not harm it
inline bool mm2qQuickwoodFireImmune()
    { return true; }

// Lightning is harmlessly channeled off
inline bool mm2qQuickwoodLightningChanneled()
    { return true; }

// Poisons and gases do not harm a quickwood
inline bool mm2qQuickwoodPoisonGasImmune()
    { return true; }

// Disintegrate will certainly destroy one of these things
inline bool mm2qQuickwoodDisintegrateDestroys()
    { return true; }

// Mind-affecting spells do not affect a quickwood
inline bool mm2qQuickwoodMindAffectingImmune()
    { return true; }

// It is possible to use plant effective spells against a quickwood, but most
// others do not work
inline bool mm2qQuickwoodPlantSpellsWork()
    { return true; }

// The roots are too strong to be broken, and blunt weapons do not damage them
inline bool mm2qQuickwoodRootsTooStrongToBreak()
    { return true; }

// The quickwood xpValue (the 350 + 10/hp block: 350 + 10x25)
inline int mm2qQuickwoodXpValue()
    { return 600; }

// The quickwood experience level (the roman V)
inline int mm2qQuickwoodXpLevel()
    { return 5; }

// ---- the QStats grid pins (the R811 MM2 letter Q walk) ----

// The armor class cells (the quickling -3 rides an unquoted number - the R806
// hollyphant -4 precedent)
inline int mm2qQStatAc(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return -3;
        case 2:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice num cells (the quasi-elemental 6, 9, or 12 first-number 6 read
// - the MM1 earth elemental precedent; the quickling 1-1/2 reads 1 die; the
// quickwood 5-10 reads the base 5)
inline int mm2qQStatHd(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 1;
        case 2:
            return 5;
        default:
            return 0;
        }
    }

// The hit dice bonus cells (the quickling half die reads +2 hp on the
// quarter-die scale - the loader 1.5 hit-dice settle, the hitDice = hdNum +
// bonus/4 form)
inline int mm2qQStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// The avgHp cells (the floor(3.5 x hd + bonus) formula: the quasi-elemental
// 21, the quickling 5; the quickwood 25 is the 5-per-die read - 5 dice x 5 hp
// - the flat exception pinned verbatim)
inline int mm2qQStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 21;
        case 1:
            return 5;
        case 2:
            return 25;
        default:
            return 0;
        }
    }

// The attack cells (the loader semantics: the quickwood Special floor at 1)
inline int mm2qQStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 1;
        default:
            return 0;
        }
    }

// The xp base cells (the quasi-elemental VII/1000, the quickling IV/200, the
// quickwood V/350)
inline int mm2qQStatXp(int b)
    {
        switch (b) {
        case 0:
            return 1000;
        case 1:
            return 200;
        case 2:
            return 350;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the quasi-elemental 15, the quickling 3, the
// quickwood 10)
inline int mm2qQStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 3;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

// The in-lair percentage cells (the quasi-elemental Nil reads 0; the
// quickwood 100)
inline int mm2qQStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10;
        case 2:
            return 100;
        default:
            return 0;
        }
    }

// The move cells (the ground move reads: the quasi-elemental 18, the
// quickling 96, the quickwood 1)
inline int mm2qQStatMove(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 96;
        case 2:
            return 1;
        default:
            return 0;
        }
    }

// The magic resistance cells (every See below and every Save-as matrix II.C
// note reads 0 - the R155 class)
inline int mm2qQStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
