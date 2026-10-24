// =========================================================================================
// Adnd1 - rules/mm2dg.h
// THE MM2 LETTER D PART 5 - THE DRACOLISK, DRAGON AND DUSTDIGGER TURNS (the
// dracolisk and the DRAGON family head pp. 55-56, the four true dragons, the
// giant dragonfly, the dragon horse, the dragonnel, the drelb, the drider,
// the duergar and the dustdigger pp. 55-61), promoted to the live registry
// census 725 -> 726.
//
// Round seven of the MM2 arc, the fifth PART-LETTER walk (the user Go call on
// the landed dinosaur walk: the letter D closes with the dracolisk, the
// dragon doctrine and the eleven remaining D stat blocks pp. 55-61 - the
// D-FLIP round, the Letter D gap box flips to closed). The capture is the
// Curtiss PDF upload cross-checked against the independent transcription and
// the archive.org djvu OCR, the contested cells settled: the giant dragonfly
// hit dice line "7 (8+1-8)" verbatim; the dragonnel size in feet not inches;
// the duergar treasure letters; the duergar "know" print typo kept; the
// dragon ancient "(40+ years)" print typo kept
//
namespace rules {

// ---- the MM2 letter D part 5 round pins (the R803 census) ----

// The MM2 letter D part 5 round: the dracolisk, dragon and dustdigger turns,
// the D-flip round (the user Go call on the landed dinosaur walk)
inline int mm2dgRound()
    { return 803; }

// The registry census before the R803 promotion (the landed R802 count)
inline int mm2dgRegistryBefore()
    { return 603; }

// The registry census after the R803 promotion (603 + the 12 promoted defs)
inline int mm2dgRegistryAfter()
    { return 615; }

// The R803 def count (the 12 letter-D-part-5 stat blocks)
inline int mm2dgDefCount()
    { return 12; }

// The R803 pin-time entry count (the 12 stat blocks plus the doctrine-only
// DRAGON family head)
inline int mm2dgEntryCount()
    { return 13; }

// The DgStats grid row count (the 12 stat-block defs, print order)
inline int mm2dgDgStatRows()
    { return 12; }

// The faerie color grid row count (the 8 age colors)
inline int mm2dgFaerieColorRows()
    { return 8; }

// The faerie age grid row count (the 8 growth stages)
inline int mm2dgFaerieAgeRows()
    { return 8; }

// The gap report closed count after the R803 flip (the Letter D box closes)
inline int mm2dgGapClosed()
    { return 9; }

// The gap report open count after the R803 flip (29 - 1)
inline int mm2dgGapOpen()
    { return 28; }

// ---- the dragon family head doctrine pins (the R803 letter D part 5) ----

// The dragon size determination die (an 8-sided die: 1-2 small, 3-7 average,
// 8 huge)
inline int mm2dgDragonSizeDie()
    { return 8; }

// The size roll small floor (1-2 = small)
inline int mm2dgDragonSizeSmallMin()
    { return 1; }

// The size roll small ceiling
inline int mm2dgDragonSizeSmallMax()
    { return 2; }

// The size roll average floor (3-7)
inline int mm2dgDragonSizeAvgMin()
    { return 3; }

// The size roll average ceiling
inline int mm2dgDragonSizeAvgMax()
    { return 7; }

// The size roll huge (an 8)
inline int mm2dgDragonSizeHuge()
    { return 8; }

// The dragon growth stages (very young through ancient, 1-8)
inline int mm2dgDragonAgeStages()
    { return 8; }

// The stage-1 hit points per die (very young, 1-5 years)
inline int mm2dgDragonHatchlingHpPerDie()
    { return 1; }

// The stage-8 hit points per die (ancient; the print reads "(40+ years)" -
// the genuine print typo pinned verbatim)
inline int mm2dgDragonAncientHpPerDie()
    { return 8; }

// The dragon infravision range in feet (all dragons see equally well in
// daylight or darkness)
inline int mm2dgDragonInfravisionFeet()
    { return 60; }

// The hidden-or-invisible detection range per age level (1" per age level)
inline int mm2dgDragonDetectInchesPerAgeLevel()
    { return 1; }

// The age category the fear aura begins (adult and older)
inline int mm2dgDragonFearAuraFromAge()
    { return 5; }

// The panic rout duration floor (4-24 turns)
inline int mm2dgDragonFearRoutTurnsMin()
    { return 4; }

// The panic rout duration ceiling
inline int mm2dgDragonFearRoutTurnsMax()
    { return 24; }

// The under-3-hit-dice fear split (paralyzed with fear 50%, panic 50%)
inline int mm2dgDragonFearSplitPct()
    { return 50; }

// The 3-or-more-hit-dice fear to-hit penalty unless save vs. spell
inline int mm2dgDragonFearToHitPenalty()
    { return -1; }

// The hit dice that automatically disregard the aura effect (6 or more)
inline int mm2dgDragonFearImmuneHitDice()
    { return 6; }

// The adult-dragon aura save bonus (+5)
inline int mm2dgDragonAuraAdultSaveBonus()
    { return 5; }

// The old-dragon aura save bonus (+3)
inline int mm2dgDragonAuraOldSaveBonus()
    { return 3; }

// The very-old-dragon aura save bonus (+1)
inline int mm2dgDragonAuraVeryOldSaveBonus()
    { return 1; }

// The hit points per die that switch the save formula on (5 or more)
inline int mm2dgDragonSaveHpPerDieThreshold()
    { return 5; }

// The saving-throw hit point divisor (total hit points divided by 4)
inline int mm2dgDragonSaveDivisor()
    { return 4; }

// The very young treasure chance (10% for one-quarter)
inline int mm2dgDragonVeryYoungTreasureChancePct()
    { return 10; }

// The very young treasure share (one-quarter)
inline int mm2dgDragonVeryYoungTreasurePct()
    { return 25; }

// The young treasure chance (25% for one-quarter)
inline int mm2dgDragonYoungTreasureChancePct()
    { return 25; }

// The subadult treasure chance (50% for one-half)
inline int mm2dgDragonSubadultTreasureChancePct()
    { return 50; }

// The subadult treasure share (one-half)
inline int mm2dgDragonSubadultTreasurePct()
    { return 50; }

// The very old treasure chance (50% for 150%)
inline int mm2dgDragonVeryOldTreasureChancePct()
    { return 50; }

// The very old treasure share (150%)
inline int mm2dgDragonVeryOldTreasurePct()
    { return 150; }

// The ancient treasure chance (75% for 200%)
inline int mm2dgDragonAncientTreasureChancePct()
    { return 75; }

// The ancient treasure share (200%)
inline int mm2dgDragonAncientTreasurePct()
    { return 200; }

// The size categorization is determined by an 8-sided die roll
inline bool mm2dgDragonSizeByDieRoll()
    { return true; }

// The age (and hit points per die) is determined by an 8-sided die roll
inline bool mm2dgDragonAgeHpPerDieByDieRoll()
    { return true; }

// All creatures under 1 hit die and noncarnivorous untrained creatures flee
// in panic under the aura
inline bool mm2dgDragonAuraPanicsUnderOneHitDie()
    { return true; }

// Creatures with fewer than 3 hit dice save vs. spell or are paralyzed with
// fear (50%) or panic (50%)
inline bool mm2dgDragonAuraParalysisOrPanic()
    { return true; }

// Creatures with 3 or more hit dice fight at -1 unless they save vs. spell
inline bool mm2dgDragonAuraPenalizesThreeHitDice()
    { return true; }

// Creatures with 6 or more hit dice automatically disregard the aura effect
inline bool mm2dgDragonAuraIgnoredAtSixHitDice()
    { return true; }

// At 5 or more hit points per die the saving throw is the total hit points
// divided by 4
inline bool mm2dgDragonToughnessRaisesSave()
    { return true; }

// Even a very young dragon uses its actual hit dice for determining save
// scores
inline bool mm2dgDragonYoungKeepsFullHitDiceForSaves()
    { return true; }

// ---- the MM2 letter D part 5 stat grid (the R803 wiring) ----

// The armor class cells (the cloud and mist or-form cells read their gaseous
// best value, -3 and -2)
inline int mm2dgDgStatAC(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return -3;
        case 2:
            return 5;
        case 3:
            return -2;
        case 4:
            return -2;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        default:
            return 0;
        }
    }

// The hit dice num cells (the cloud, mist and shadow ranged cells read the
// low end - the kuei precedent)
inline int mm2dgDgStatHd(int b)
    {
        switch (b) {
        case 0:
            return 7;
        case 1:
            return 12;
        case 2:
            return 4;
        case 3:
            return 9;
        case 4:
            return 4;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 1;
        case 11:
            return 4;
        default:
            return 0;
        }
    }

// The hit dice bonus points (the shadow always-on +1 per die rides here)
inline int mm2dgDgStatHdBonus(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 6;
        case 10:
            return 2;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The book-average hit points (the floor(num x 3.5) + bonus formula)
inline int mm2dgDgStatAvgHp(int b)
    {
        switch (b) {
        case 0:
            return 27;
        case 1:
            return 42;
        case 2:
            return 14;
        case 3:
            return 31;
        case 4:
            return 15;
        case 5:
            return 24;
        case 6:
            return 28;
        case 7:
            return 32;
        case 8:
            return 20;
        case 9:
            return 27;
        case 10:
            return 5;
        case 11:
            return 14;
        default:
            return 0;
        }
    }

// The attack cells (the duergar "1 (or more)" reads its max 1 in the loader)
inline int mm2dgDgStatAttacks(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        default:
            return 0;
        }
    }

// The base xp cells (the duergar Variable reads 0 - the by_level carry)
inline int mm2dgDgStatXp(int b)
    {
        switch (b) {
        case 0:
            return 2200;
        case 1:
            return 6100;
        case 2:
            return 280;
        case 3:
            return 3450;
        case 4:
            return 245;
        case 5:
            return 525;
        case 6:
            return 1275;
        case 7:
            return 600;
        case 8:
            return 800;
        case 9:
            return 875;
        case 10:
            return 0;
        case 11:
            return 165;
        default:
            return 0;
        }
    }

// The xp per hit point cells (the duergar variable reads 0)
inline int mm2dgDgStatXpHp(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 10;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 5;
        case 5:
            return 8;
        case 6:
            return 10;
        case 7:
            return 12;
        case 8:
            return 6;
        case 9:
            return 8;
        case 10:
            return 0;
        case 11:
            return 4;
        default:
            return 0;
        }
    }

// The percent in lair cells (the drelb 100; every Nil reads 0)
inline int mm2dgDgStatLairPct(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 25;
        case 2:
            return 25;
        case 3:
            return 35;
        case 4:
            return 40;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 10;
        case 8:
            return 100;
        case 9:
            return 0;
        case 10:
            return 5;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The primary move cells in print inches (the first number of the print move
// line, the parseIntRange floor)
inline int mm2dgDgStatMove(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 18;
        case 5:
            return 1;
        case 6:
            return 24;
        case 7:
            return 12;
        case 8:
            return 6;
        case 9:
            return 12;
        case 10:
            return 6;
        case 11:
            return 3;
        default:
            return 0;
        }
    }

// The magic resistance cells (the cloud 50 and mist 30 or-forms read their
// percent; every Standard and the faerie See-below and dragonfly save-as read
// 0)
inline int mm2dgDgStatMr(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 50;
        case 2:
            return 0;
        case 3:
            return 30;
        case 4:
            return 20;
        case 5:
            return 0;
        case 6:
            return 25;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 15;
        case 10:
            return 0;
        case 11:
            return 0;
        default:
            return 0;
        }
    }

// The magic resistance cells by color (red 12% through purple 96%)
inline int mm2dgFaerieColorMr(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 24;
        case 2:
            return 35;
        case 3:
            return 48;
        case 4:
            return 60;
        case 5:
            return 72;
        case 6:
            return 84;
        case 7:
            return 96;
        default:
            return 0;
        }
    }

// The magic-user level cells by color (2 through 16)
inline int mm2dgFaerieColorMuLevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 14;
        case 7:
            return 16;
        default:
            return 0;
        }
    }

// The druid level cells by color (3 through 14)
inline int mm2dgFaerieColorDruidLevel(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        case 3:
            return 6;
        case 4:
            return 8;
        case 5:
            return 10;
        case 6:
            return 12;
        case 7:
            return 14;
        default:
            return 0;
        }
    }

// The level cells (1 through 8)
inline int mm2dgFaerieAgeLevel(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        default:
            return 0;
        }
    }

// The hit point floor cells (1 through 15)
inline int mm2dgFaerieAgeHpMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 7;
        case 4:
            return 9;
        case 5:
            return 11;
        case 6:
            return 13;
        case 7:
            return 15;
        default:
            return 0;
        }
    }

// The hit point ceiling cells (2 through 16)
inline int mm2dgFaerieAgeHpMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 6;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 12;
        case 6:
            return 14;
        case 7:
            return 16;
        default:
            return 0;
        }
    }

// ---- the dracolisk pins (the R803 MM2 letter D part 5) ----

// The dracolisk full kill xp (2200 + 12/hp over 27 avg)
inline int mm2dgDracoliskXpValue()
    { return 2524; }

// The dracolisk xp level (VII)
inline int mm2dgDracoliskXpLevel()
    { return 7; }

// The acid spit range (a 1/2" wide stream up to 3")
inline int mm2dgDracoliskAcidRangeInches()
    { return 3; }

// The acid spit damage floor (4-24, 4d6)
inline int mm2dgDracoliskAcidDamageMin()
    { return 4; }

// The acid spit damage ceiling
inline int mm2dgDracoliskAcidDamageMax()
    { return 24; }

// The acid spit uses per day (half damage on a save vs. breath weapon)
inline int mm2dgDracoliskAcidPerDay()
    { return 3; }

// The gaze petrify range (any opponent within 20 feet)
inline int mm2dgDracoliskGazePetrifyFeet()
    { return 20; }

// The imperviousness to its own reflected gaze (the hooded eyes with
// nictating membranes)
inline int mm2dgDracoliskGazeImperviousPct()
    { return 90; }

// The to-hit penalty for opponents meleeing while avoiding the gaze
inline int mm2dgDracoliskGazeAvoidMeleePenalty()
    { return -4; }

// The gaze chance for a completely surprised character (9 in 10)
inline int mm2dgDracoliskGazeCompletelySurprised()
    { return 9; }

// The gaze chance for a surprised character (7 in 10)
inline int mm2dgDracoliskGazeSurprised()
    { return 7; }

// The gaze chance for a character viewing the monster (5 in 10)
inline int mm2dgDracoliskGazeViewing()
    { return 5; }

// The gaze chance for a character attacking normally (3 in 10)
inline int mm2dgDracoliskGazeAttacking()
    { return 3; }

// The gaze chance for a character avoiding the gaze (1 in 10)
inline int mm2dgDracoliskGazeAvoiding()
    { return 1; }

// The gaze chance add for a man-sized gaze creature (add 1)
inline int mm2dgDracoliskGazeManSizedBonus()
    { return 1; }

// The gaze chance add for a small gaze creature (add 2)
inline int mm2dgDracoliskGazeSmallBonus()
    { return 2; }

// Dracolisks cannot use spells
inline bool mm2dgDracoliskCannotUseSpells()
    { return true; }

// Dracolisks speak only a very limited type of black dragon language
inline bool mm2dgDracoliskSpeaksLimitedBlackDragonTongue()
    { return true; }

// If a dracolisk is surprised it is because the creature is sleeping
inline bool mm2dgDracoliskSurprisedOnlyWhenSleeping()
    { return true; }

// A dracolisk can never be subdued
inline bool mm2dgDracoliskNeverSubdued()
    { return true; }

// The dracolisk gaze extends into the Astral and Ethereal Planes just as does
// that of a basilisk
inline bool mm2dgDracoliskGazeReachesAstralEthereal()
    { return true; }

// ---- the cloud dragon pins (the R803 MM2 letter D part 5) ----

// The cloud dragon full kill xp (6100 + 10/hp over 42 avg)
inline int mm2dgCloudXpValue()
    { return 6520; }

// The cloud dragon xp level (X)
inline int mm2dgCloudXpLevel()
    { return 10; }

// The lone-encounter share (95% of all encounters)
inline int mm2dgCloudLonerPct()
    { return 95; }

// The cloud island dwellers share (most lair there)
inline int mm2dgCloudCloudIslandPct()
    { return 75; }

// The gaseous (cloud) form armor class
inline int mm2dgCloudGaseousArmorClass()
    { return -3; }

// The solid form armor class
inline int mm2dgCloudSolidArmorClass()
    { return 0; }

// The airblast uses per day
inline int mm2dgCloudAirblastPerDay()
    { return 3; }

// The airblast width (3")
inline int mm2dgCloudAirblastWidthInches()
    { return 3; }

// The airblast depth (3")
inline int mm2dgCloudAirblastDepthInches()
    { return 3; }

// The airblast length floor (12-14" by hit dice)
inline int mm2dgCloudAirblastLengthMinInches()
    { return 12; }

// The airblast length ceiling
inline int mm2dgCloudAirblastLengthMaxInches()
    { return 14; }

// The blow-around weight limit (10 pounds times the hit points)
inline int mm2dgCloudAirblastWeightPoundsPerHp()
    { return 10; }

// The tumbling and wind damage (1 point per hit point of the dragon)
inline int mm2dgCloudAirblastDamagePerHp()
    { return 1; }

// The tumble-back floor (1-6 feet per hit die)
inline int mm2dgCloudTumbleFeetPerDieMin()
    { return 1; }

// The tumble-back ceiling
inline int mm2dgCloudTumbleFeetPerDieMax()
    { return 6; }

// The xp bonus threshold (100 xp/hp over 48 hit points - the print rider
// pinned)
inline int mm2dgCloudXpBonusHpThreshold()
    { return 48; }

// The xp bonus per hit point over the threshold (the print rider; the base
// 6100 + 10/hp rides the def)
inline int mm2dgCloudXpBonusPerHpOver()
    { return 100; }

// The spell uses per day (each age-category spell twice per day, at a level
// equal to the hit dice)
inline int mm2dgCloudSpellsPerDayEach()
    { return 2; }

// The top spell age category (8-control winds)
inline int mm2dgCloudTopSpellAge()
    { return 8; }

// The only attacks while in cloud form are spells
inline bool mm2dgCloudGaseousFormSpellAttacksOnly()
    { return true; }

// Solid form negates the innate magic resistance
inline bool mm2dgCloudSolidFormNegatesInnateMr()
    { return true; }

// Cloud dragons have their own dialect of draconian speech and converse with
// all other sorts of dragons
inline bool mm2dgCloudSpeaksDraconianDialect()
    { return true; }

// All cloud dragons can converse, if but haltingly, in the human common
// tongue
inline bool mm2dgCloudSpeaksCommonHaltingly()
    { return true; }

// ---- the faerie dragon pins (the R803 MM2 letter D part 5) ----

// The faerie dragon full kill xp (280 + 4/hp over 14 avg)
inline int mm2dgFaerieXpValue()
    { return 336; }

// The faerie dragon xp level (V)
inline int mm2dgFaerieXpLevel()
    { return 5; }

// The armor class when invisible (the stat block prints AC 5, AC 1 when
// invisible)
inline int mm2dgFaerieInvisibleArmorClass()
    { return 1; }

// The faerie dragon attacks as 4 hit dice monsters (the "See below" hit dice
// read)
inline int mm2dgFaerieHitDiceNum()
    { return 4; }

// The bite damage ceiling (biting for 1-2 points)
inline int mm2dgFaerieBiteDamageMax()
    { return 2; }

// The euphoria gas wander floor (3-12 rounds)
inline int mm2dgFaerieEuphoriaRoundsMin()
    { return 3; }

// The euphoria gas wander ceiling
inline int mm2dgFaerieEuphoriaRoundsMax()
    { return 12; }

// The euphoria armor class worsening (an effective armor class 10% worse than
// normal)
inline int mm2dgFaerieEuphoriaAcPenaltyPct()
    { return 10; }

// The chance of speaking (90%)
inline int mm2dgFaerieSpeakingPct()
    { return 90; }

// The chance of magic use (100%)
inline int mm2dgFaerieMagicUsePct()
    { return 100; }

// The chance of sleeping (40%)
inline int mm2dgFaerieSleepingPct()
    { return 40; }

// The magic-user spell share (65% magic-user, 35% druid)
inline int mm2dgFaerieMagicUserPct()
    { return 65; }

// The druid spell share
inline int mm2dgFaerieDruidPct()
    { return 35; }

// The telepathic communication range (up to 2 miles)
inline int mm2dgFaerieTelepathyMiles()
    { return 2; }

// The faerie dragon never attacks directly unless cornered or defending its
// lair
inline bool mm2dgFaerieAttacksOnlyWhenCorneredOrLair()
    { return true; }

// Faerie dragons can hover and are maneuverability class A
inline bool mm2dgFaerieHoverManeuverabilityA()
    { return true; }

// A faerie dragon will never have damage to the victim as its aim
inline bool mm2dgFaerieNeverAimsDamage()
    { return true; }

// Faerie dragons can become invisible at will and attack or employ magic or
// breath weapons when invisible
inline bool mm2dgFaerieInvisibleAtWill()
    { return true; }

// ---- the mist dragon pins (the R803 MM2 letter D part 5) ----

// The mist dragon full kill xp (3450 + 5/hp over 31 avg)
inline int mm2dgMistXpValue()
    { return 3605; }

// The mist dragon xp level (VIII)
inline int mm2dgMistXpLevel()
    { return 8; }

// The chance of sleeping (20%)
inline int mm2dgMistSleepingPct()
    { return 20; }

// The mated pair encounter chance (10%)
inline int mm2dgMistMatedPairPct()
    { return 10; }

// The mist (gaseous) form armor class
inline int mm2dgMistMistFormArmorClass()
    { return -2; }

// The mist form magic resistance (30%)
inline int mm2dgMistMistFormMrPct()
    { return 30; }

// The solid form armor class (with standard magic resistance)
inline int mm2dgMistSolidArmorClass()
    { return 1; }

// The mist breath uses per day
inline int mm2dgMistBreathPerDay()
    { return 3; }

// The mist cloud width (3")
inline int mm2dgMistCloudWidthInches()
    { return 3; }

// The mist cloud length (9")
inline int mm2dgMistCloudLengthInches()
    { return 9; }

// The mist cloud depth (3")
inline int mm2dgMistCloudDepthInches()
    { return 3; }

// The cloud blinding floor (1-4 rounds)
inline int mm2dgMistBlindRoundsMin()
    { return 1; }

// The cloud blinding ceiling
inline int mm2dgMistBlindRoundsMax()
    { return 4; }

// The drowning damage floor (3-12 per round)
inline int mm2dgMistDrownDamageMin()
    { return 3; }

// The drowning damage ceiling
inline int mm2dgMistDrownDamageMax()
    { return 12; }

// The drowning damage ceiling on a successful save (1-4 per round)
inline int mm2dgMistDrownSaveDamageMax()
    { return 4; }

// The mist persistence floor (5-8 rounds by wind)
inline int mm2dgMistPersistsRoundsMin()
    { return 5; }

// The mist persistence ceiling
inline int mm2dgMistPersistsRoundsMax()
    { return 8; }

// The xp bonus threshold (50 xp/hp over 36 hit points - the print rider
// pinned)
inline int mm2dgMistXpBonusHpThreshold()
    { return 36; }

// The xp bonus per hit point over the threshold (the print rider; the base
// 3450 + 5/hp rides the def)
inline int mm2dgMistXpBonusPerHpOver()
    { return 50; }

// The spell uses per day (each age-category spell twice per day, at a level
// equal to the hit dice)
inline int mm2dgMistSpellsPerDayEach()
    { return 2; }

// The top spell age category (8=airy water)
inline int mm2dgMistTopSpellAge()
    { return 8; }

// Only spells can be cast in gaseous (mist) form
inline bool mm2dgMistSpellsOnlyInMistForm()
    { return true; }

// A mist dragon is not affected by such a cloud
inline bool mm2dgMistImmuneToOwnCloud()
    { return true; }

// Mist dragons resemble gold dragons in body form
inline bool mm2dgMistResemblesGoldDragons()
    { return true; }

// ---- the shadow dragon pins (the R803 MM2 letter D part 5) ----

// The shadow dragon full kill xp (245 + 5/hp over 15 avg)
inline int mm2dgShadowXpValue()
    { return 320; }

// The shadow dragon xp level (IV)
inline int mm2dgShadowXpLevel()
    { return 4; }

// The clutch size floor (5-8 eggs)
inline int mm2dgShadowEggsMin()
    { return 5; }

// The clutch size ceiling
inline int mm2dgShadowEggsMax()
    { return 8; }

// The small size share (25%, all female)
inline int mm2dgShadowSmallPct()
    { return 25; }

// The average size share (50%)
inline int mm2dgShadowAveragePct()
    { return 50; }

// The large size share (25%, all male)
inline int mm2dgShadowLargePct()
    { return 25; }

// The always-on hit point bonus per die (a shadow dragon always has +1 per
// die)
inline int mm2dgShadowHpPerDieBonus()
    { return 1; }

// The hatchling pips per die (a very young dragon has 2 pips per die)
inline int mm2dgShadowHatchlingPipsPerDie()
    { return 2; }

// The ancient pips per die (9 pips per die)
inline int mm2dgShadowAncientPipsPerDie()
    { return 9; }

// The very superior infravision range (180 feet)
inline int mm2dgShadowInfravisionFeet()
    { return 180; }

// The illusionist spell intelligence floor (17-18)
inline int mm2dgShadowIllusionistMinIntelligence()
    { return 17; }

// The illusionist spell intelligence ceiling
inline int mm2dgShadowIllusionistMaxIntelligence()
    { return 18; }

// The illusionist spell ceiling (3rd-4th levels)
inline int mm2dgShadowIllusionistTopSpellLevel()
    { return 4; }

// The illusionist spells per level (2 spells per level)
inline int mm2dgShadowIllusionistSpellsPerLevel()
    { return 2; }

// The illusionist spell age floor (attained from adult age)
inline int mm2dgShadowIllusionistFromAge()
    { return 5; }

// The darkness cloud length (40-feet long)
inline int mm2dgShadowBreathLengthFeet()
    { return 40; }

// The darkness cloud width (30-feet wide)
inline int mm2dgShadowBreathWidthFeet()
    { return 30; }

// The darkness cloud height (20-feet high)
inline int mm2dgShadowBreathHeightFeet()
    { return 20; }

// The life energy left after the cloud (25% of usual vitality; 50% on a save)
inline int mm2dgShadowVitalityLeftPct()
    { return 25; }

// The life energy left on a successful save
inline int mm2dgShadowVitalitySavePct()
    { return 50; }

// The hide in shadows thief level (a 10th level thief)
inline int mm2dgShadowHideAsThiefLevel()
    { return 10; }

// The hoard gem floor (10-80 gems of opaque substance)
inline int mm2dgShadowHoardGemsMin()
    { return 10; }

// The hoard gem ceiling
inline int mm2dgShadowHoardGemsMax()
    { return 80; }

// The shadow dragon is nocturnal, subterranean, or found on planes of dimness
// such as Shadowland
inline bool mm2dgShadowNocturnal()
    { return true; }

// The first egg to hatch quickly devours the others
inline bool mm2dgShadowFirstHatchlingDevoursRest()
    { return true; }

// Due to their nature and substance they can be harmed only by magic weapons
inline bool mm2dgShadowHarmedOnlyByMagicWeapons()
    { return true; }

// They are immune to life level loss of all types
inline bool mm2dgShadowImmuneToLifeLevelLoss()
    { return true; }

// Shadow dragons cannot be subdued and sold
inline bool mm2dgShadowCannotBeSubduedAndSold()
    { return true; }

// Spells are lost permanently from the darkness cloud exposure until
// relearned or regained normally
inline bool mm2dgShadowBreathCostsSpellsUntilRelearned()
    { return true; }

// ---- the giant dragonfly pins (the R803 MM2 letter D part 5) ----

// The giant dragonfly full kill xp (525 + 8/hp over 24 avg)
inline int mm2dgDragonflyXpValue()
    { return 717; }

// The giant dragonfly xp level (VI)
inline int mm2dgDragonflyXpLevel()
    { return 6; }

// The initiative check bonus (+2)
inline int mm2dgDragonflyInitiativeBonus()
    { return 2; }

// The missile penalty with initiative (-4)
inline int mm2dgDragonflyMissilePenaltyWithInitiative()
    { return -4; }

// The missile penalty without initiative (-2)
inline int mm2dgDragonflyMissilePenaltyWithoutInitiative()
    { return -2; }

// The skin value (up to 600 gp per square foot)
inline int mm2dgDragonflySkinGpPerSquareFoot()
    { return 600; }

// The takeable skin (about 6 square feet from a normal specimen)
inline int mm2dgDragonflySkinSquareFeet()
    { return 6; }

// The save-as level (save as a 16th-level magic-user - the R155 save-as read,
// no innate percent)
inline int mm2dgDragonflySaveAsLevel()
    { return 16; }

// With initiative they cannot be effectively combatted with hand-held weapons
inline bool mm2dgDragonflyInitiativeImmuneToHandWeapons()
    { return true; }

// Giant dragonflies are dangerous predators known to hunt humans
inline bool mm2dgDragonflyHuntsHumans()
    { return true; }

// ---- the dragon horse pins (the R803 MM2 letter D part 5) ----

// The dragon horse full kill xp (1275 + 10/hp over 28 avg)
inline int mm2dgDragonHorseXpValue()
    { return 1555; }

// The dragon horse xp level (VII)
inline int mm2dgDragonHorseXpLevel()
    { return 7; }

// The encountered-elsewhere share (seldom, 5%)
inline int mm2dgDragonHorseElsewherePct()
    { return 5; }

// The breath uses per turn (once per turn, at will)
inline int mm2dgDragonHorseBreathPerTurn()
    { return 1; }

// The cone of cold base (1" diameter base)
inline int mm2dgDragonHorseConeBaseInches()
    { return 1; }

// The cone length (2")
inline int mm2dgDragonHorseConeLengthInches()
    { return 2; }

// The cone damage floor (4d8)
inline int mm2dgDragonHorseConeDamageMin()
    { return 4; }

// The cone damage ceiling
inline int mm2dgDragonHorseConeDamageMax()
    { return 32; }

// The flying-or-rearing damage floor (+2 per hit, 3-10/3-10)
inline int mm2dgDragonHorseRearingDamageMin()
    { return 3; }

// The flying-or-rearing damage ceiling
inline int mm2dgDragonHorseRearingDamageMax()
    { return 10; }

// The keen senses multiple (triple normal)
inline int mm2dgDragonHorseSensesMultiple()
    { return 3; }

// The maturation process length (20 years)
inline int mm2dgDragonHorseMaturationYears()
    { return 20; }

// These creatures are never surprised
inline bool mm2dgDragonHorseNeverSurprised()
    { return true; }

// Their visual capabilities include aura detection, so they sense the
// alignment of creatures they encounter
inline bool mm2dgDragonHorseDetectsAlignmentAura()
    { return true; }

// Dragon horses can travel the Astral and Ethereal Planes
inline bool mm2dgDragonHorseTravelsAstralEthereal()
    { return true; }

// The creature must be a willing companion and associate
inline bool mm2dgDragonHorseWillingCompanionOnly()
    { return true; }

// ---- the dragonnel pins (the R803 MM2 letter D part 5) ----

// The dragonnel full kill xp (600 + 12/hp over 32 avg)
inline int mm2dgDragonnelXpValue()
    { return 984; }

// The dragonnel xp level (VI)
inline int mm2dgDragonnelXpLevel()
    { return 6; }

// Although as large as a small dragon, a dragonnel has no breath weapon
inline bool mm2dgDragonnelHasNoBreathWeapon()
    { return true; }

// In the Pomarj the monsters have been caught, tamed, and are used as steeds
// by evil humans
inline bool mm2dgDragonnelTamedAsSteedsInPomarj()
    { return true; }

// ---- the drelb pins (the R803 MM2 letter D part 5) ----

// The drelb full kill xp (800 + 6/hp over 20 avg)
inline int mm2dgDrelbXpValue()
    { return 920; }

// The drelb xp level (VI)
inline int mm2dgDrelbXpLevel()
    { return 6; }

// The nether chill duration (the following round, no saving throw)
inline int mm2dgDrelbChillRounds()
    { return 1; }

// The retreating-illusion trick success (90% likely to give the viewers the
// impression that the drelb is retreating)
inline int mm2dgDrelbIllusionTrickPct()
    { return 90; }

// The psionic imitation/reflection range (any power used within 30 feet)
inline int mm2dgDrelbPsionicReflectFeet()
    { return 30; }

// Although drelb resemble undead, they are not and cannot be turned
inline bool mm2dgDrelbNotUndeadCannotBeTurned()
    { return true; }

// Magic weapons are needed to harm drelb; silver has no effect
inline bool mm2dgDrelbMagicWeaponsToHarm()
    { return true; }

// Magicked silver causes double damage
inline bool mm2dgDrelbMagickedSilverDoubleDamage()
    { return true; }

// Magic which draws a drelb to the Prime Material Plane is likely to function
// only from sunset to sunrise
inline bool mm2dgDrelbDrawnSunsetToSunrise()
    { return true; }

// ---- the drider pins (the R803 MM2 letter D part 5) ----

// The drider full kill xp (875 + 8/hp over 27 avg)
inline int mm2dgDriderXpValue()
    { return 1091; }

// The drider xp level (VI)
inline int mm2dgDriderXpLevel()
    { return 6; }

// In combat all driders fight as 7 hit dice monsters
inline int mm2dgDriderFightAsHitDice()
    { return 7; }

// The female share (60% of those encountered)
inline int mm2dgDriderFemalePct()
    { return 60; }

// The female cleric level floor (6th or 7th level)
inline int mm2dgDriderFemaleClericMinLevel()
    { return 6; }

// The female cleric level ceiling
inline int mm2dgDriderFemaleClericMaxLevel()
    { return 7; }

// The male magic-user level floor (6th, 7th, or 8th level)
inline int mm2dgDriderMaleMagicUserMinLevel()
    { return 6; }

// The male magic-user level ceiling
inline int mm2dgDriderMaleMagicUserMaxLevel()
    { return 8; }

// The bite damage ceiling (1-4 points of damage)
inline int mm2dgDriderBiteDamageMax()
    { return 4; }

// The bite save penalty (save vs. poison at -2)
inline int mm2dgDriderPoisonSavePenalty()
    { return -2; }

// The spittle paralysis floor (1-2 turns)
inline int mm2dgDriderParalysisTurnsMin()
    { return 1; }

// The spittle paralysis ceiling
inline int mm2dgDriderParalysisTurnsMax()
    { return 2; }

// The huge spider companion floor (2-12, 10% of the time)
inline int mm2dgDriderSpiderCompanionsMin()
    { return 2; }

// The huge spider companion ceiling
inline int mm2dgDriderSpiderCompanionsMax()
    { return 12; }

// The huge spider companion chance
inline int mm2dgDriderSpiderChancePct()
    { return 10; }

// The Lolth test level (when drow of promising ability reach 6th level or
// slightly higher)
inline int mm2dgDriderTestFromLevel()
    { return 6; }

// The drow that fail Lolth's specially-devised test become driders
inline bool mm2dgDriderDrowFailedLolthTest()
    { return true; }

// Driders are outcasts from drow communities and thus bear them no great love
inline bool mm2dgDriderOutcastFromDrow()
    { return true; }

// A drider has the natural spell ability of a drow, each spell once per day
inline bool mm2dgDriderDrowSpellsOncePerDay()
    { return true; }

// ---- the duergar pins (the R803 MM2 letter D part 5) ----

// The duergar hit dice num (1+2)
inline int mm2dgDuergarHitDiceNum()
    { return 1; }

// The duergar hit dice bonus
inline int mm2dgDuergarHitDiceBonus()
    { return 2; }

// The duergar book-average hit points
inline int mm2dgDuergarAvgHp()
    { return 5; }

// The 2nd-level chance (for every 4 normal duergar there will be 1 with
// double hit dice, i.e., 1 in 4 is 2nd level)
inline int mm2dgDuergarDoubleLevelChance()
    { return 4; }

// The leader trigger (if 9 are encountered outside their lair)
inline int mm2dgDuergarLeaderAtCount()
    { return 9; }

// The leader level floor (3rd or 4th level)
inline int mm2dgDuergarLeaderMinLevel()
    { return 3; }

// The leader level ceiling
inline int mm2dgDuergarLeaderMaxLevel()
    { return 4; }

// The surprise die read (duergar surprise on 3 in 6)
inline int mm2dgDuergarSurpriseOnD6()
    { return 3; }

// The surprised die read (they are surprised only 1 in 10)
inline int mm2dgDuergarSurprisedOnD10()
    { return 1; }

// The save vs. magical attacks bonus (+4)
inline int mm2dgDuergarSaveBonus()
    { return 4; }

// The psionic ability floor (71-90, 2/level)
inline int mm2dgDuergarPsionicMinPct()
    { return 71; }

// The psionic ability ceiling
inline int mm2dgDuergarPsionicMaxPct()
    { return 90; }

// The psionic disciplines (expansion, invisibility, molecular attraction, and
// reduction; performance level equal to hit dice of experience)
inline int mm2dgDuergarPsionicDisciplines()
    { return 4; }

// The infravision range (12")
inline int mm2dgDuergarInfravisionInches()
    { return 12; }

// The noncombatant young share (10% of the normal fighters)
inline int mm2dgDuergarYoungPct()
    { return 10; }

// The lair guardian monster chance (25%)
inline int mm2dgDuergarGuardianChancePct()
    { return 25; }

// The slave-holding probability (75%)
inline int mm2dgDuergarSlaveChancePct()
    { return 75; }

// The slave count floor (10-40)
inline int mm2dgDuergarSlaveMin()
    { return 10; }

// The slave count ceiling
inline int mm2dgDuergarSlaveMax()
    { return 40; }

// The duergar xp is variable by level (the print "Variable/variable" - the
// dervish and dwarf by_level precedent, no fixed xp fields)
inline bool mm2dgDuergarXpByLevel()
    { return true; }

// They are immune to paralysis and poison
inline bool mm2dgDuergarImmuneParalysisPoison()
    { return true; }

// Spells of the illusion/phantasm category do not affect duergar
inline bool mm2dgDuergarIllusionPhantasmDoNotAffect()
    { return true; }

// The duergar lair will always be subterranean, extensive, and full of secret
// areas
inline bool mm2dgDuergarSubterraneanLair()
    { return true; }

// ---- the dustdigger pins (the R803 MM2 letter D part 5) ----

// The dustdigger full kill xp (165 + 4/hp over 14 avg)
inline int mm2dgDustdiggerXpValue()
    { return 221; }

// The dustdigger xp level (IV)
inline int mm2dgDustdiggerXpLevel()
    { return 4; }

// The front side armor class (the back is armor class 4; the front side is
// only armor class 7)
inline int mm2dgDustdiggerFrontArmorClass()
    { return 7; }

// The arm count (giant starfish with 5 arms around a central maw)
inline int mm2dgDustdiggerArms()
    { return 5; }

// The born illusion talent share (20% project a pool of bubbling water)
inline int mm2dgDustdiggerIllusionTalentPct()
    { return 20; }

// The deflating sinkhole ambush slows the escape of its prey
inline bool mm2dgDustdiggerSinkholeAmbush()
    { return true; }

// They travel above ground only at night and never for longer than a few
// minutes at a time
inline bool mm2dgDustdiggerNightTravelOnly()
    { return true; }

// Once the dustdigger has folded up its prey is caught and cannot attack
inline bool mm2dgDustdiggerCaughtPreyCannotAttack()
    { return true; }

}   // namespace rules
