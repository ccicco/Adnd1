// =========================================================================================
// Adnd1 - rules/fsc.h
// The fighting sub-classes round - Childers and Kay's Samurai (folio 25) and
// Pickens' Berserker (folio 27)
// census 819 -> 820.
//
// Pinned from The Dragon Vol. 1 No. 3 (October 1976): folio 25, Mike
// Childers' Samurai as modified by Jeff Kay - the Fighting Man sub-class with
// the dexterity-above-15 gate, the daisho and the yumi, the four-grade katana
// and wakizashi critical-hit tables, the three-band critical blow on the
// percentage dice, the five-point dexterity ladder, the five-grade Japanese
// armor run and the judo rules with their 4-level damage and 6-level subdue
// steps; folio 27, John Pickens' Berserker - the highly experimental human
// NEUTRAL with Strength and Constitution above 9 and Intelligence below 9,
// the five lycanthropic clans with their Clanmasters, the wereshape at 6th
// through 10th, the level abilities, the 2-12 Followers with their three
// percentile rolls, and the berserking chance with its cumulative adders. The
// editor's caution rides: the class is highly experimental, be warned.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. The
// 'greater than 15' and 'exceed 9' gates CONVERT to 16 and 10 minimums and
// 'below 9' to an 8 maximum, every conversion noted, never silent; the '00'
// percentile convention CONVERTS to 100; the wakizashi's 1 and 3/4 pounds
// pins as seven quarter-pounds; the blade critical bands pin as their low
// roll with the top always 20; the OCR's duplicate Magic-User Follower row
// and the garbled yumi armor-class grid ride AS SCANNED - the grid's stacked
// modifier tokens carry no figure pixels to check and pin nothing, noted; the
// Samurai and Berserker ride the variant layer against the engine's canon
// class frame, never a rewrite.
//
namespace rules {

// ---- the Samurai (folio 25) ----

// the Samurai requires a dexterity greater than 15 - pinned as 16 minimum,
// the 'greater than' conversion noted (folio 25)
inline int fscSamDexMin()
    { return 16; }

// the Samurai may be of any alignment but tends generally to be neutral
// (folio 25)
inline bool fscSamAnyAlignment()
    { return true; }

// the Samurai preferentially carries the traditional daisho sword pair and
// the Japanese composite longbow (folio 25)
inline bool fscSamPrefersDaisho()
    { return true; }

// a Samurai whose katana is taken will pursue a vendetta against the thief or
// his employers, or commit seppeku - the exact action mutually agreeable
// between player and gamemaster (folio 25)
inline bool fscSamKatanaLossVendetta()
    { return true; }

// the Japanese-style blades are special though non-magical (folio 25)
inline bool fscSamBladesNonMagical()
    { return true; }

// a Samurai of average intelligence or greater - 9+ - can identify blades of
// Japanese type manufacture (folio 25)
inline int fscSamIdBladeIntMin()
    { return 9; }

// a Samurai of higher than average intelligence - 13+ - can tell the exact
// type and character of a Japanese blade by examination (folio 25)
inline int fscSamIdExactIntMin()
    { return 13; }

// four quality grades of Japanese blade - plain through +3 (folio 25)
inline int fscSamBladeGrades()
    { return 4; }

// the hit and damage modifier grade - 0 through +3 (folio 25)
inline int fscKatHitMod(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 9;
        }
    }

// the 'above to hit' number - 8+ down to 5+ (folio 25)
inline int fscKatToHitAbove(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 7;
        case 2:
            return 6;
        case 3:
            return 5;
        default:
            return 9;
        }
    }

// the automatic critical roll band's low roll - 20, then 19-20, 19-20, then
// 18-20; the band top always 20 (folio 25)
inline int fscKatCritMinRoll(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 19;
        case 2:
            return 19;
        case 3:
            return 18;
        default:
            return 9;
        }
    }

// the encumbrance - 50 down to 40 (folio 25)
inline int fscKatEncumbrance(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 45;
        case 2:
            return 40;
        case 3:
            return 40;
        default:
            return 9;
        }
    }

// the value in gold pieces - 18 through 960 (folio 25)
inline int fscKatValueGold(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 240;
        case 2:
            return 480;
        case 3:
            return 960;
        default:
            return 9;
        }
    }

// the katana blade runs approximately 30 inches (folio 25)
inline int fscSamKatanaBladeInches()
    { return 30; }

// the katana weighs approximately 3 pounds (folio 25)
inline int fscSamKatanaWeightLb()
    { return 3; }

// the wakizashi blade runs approximately 24 inches (folio 25)
inline int fscSamWakizashiBladeInches()
    { return 24; }

// the wakizashi weighs approximately 1 and 3/4 pounds - pinned as seven
// quarter-pounds, the conversion noted (folio 25)
inline int fscSamWakizashiWeightQuarterLb()
    { return 7; }

// the hit and damage modifier grade - 0 through +3 (folio 25)
inline int fscWakHitMod(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 9;
        }
    }

// the 'above to hit' number - 8+, 8+, then 7+, 7+ (folio 25)
inline int fscWakToHitAbove(int b)
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
        default:
            return 9;
        }
    }

// the automatic critical roll band's low roll - 20, 20, then 19-20, 19-20;
// the band top always 20 (folio 25)
inline int fscWakCritMinRoll(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 20;
        case 2:
            return 19;
        case 3:
            return 19;
        default:
            return 9;
        }
    }

// the encumbrance - 28 down to 23 (folio 25)
inline int fscWakEncumbrance(int b)
    {
        switch (b) {
        case 0:
            return 28;
        case 1:
            return 25;
        case 2:
            return 23;
        case 3:
            return 23;
        default:
            return 9;
        }
    }

// the value in gold pieces - 16 through 800 (folio 25)
inline int fscWakValueGold(int b)
    {
        switch (b) {
        case 0:
            return 16;
        case 1:
            return 200;
        case 2:
            return 400;
        case 3:
            return 800;
        default:
            return 9;
        }
    }

// all the Japanese blades lose one step in the hands of a non-Samurai (folio
// 25)
inline int fscSamNonSamuraiStepLoss()
    { return 1; }

// the hit and damage modifiers may not be less than zero - the step-loss
// floor (folio 25)
inline int fscSamModFloor()
    { return 0; }

// the swords lose one step when used single-handed, with the same zero
// minimum (folio 25)
inline int fscSamSingleHandedStepLoss()
    { return 1; }

// the Samurai may employ katana and wakizashi at the same time, one in each
// hand, against the same or different targets (folio 25)
inline bool fscSamTwoWeaponsAtOnce()
    { return true; }

// the critical-blow percentile table runs three bands - 01-80, 81-95, 96-00
// (folio 25)
inline int fscSamCritBands()
    { return 3; }

// the percentile band's low roll - 01, 81, 96 (folio 25)
inline int fscCritLoPct(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 81;
        case 2:
            return 96;
        default:
            return 9;
        }
    }

// the percentile band's high roll - 80, 95, 00 pinned as 100, the '00'
// conversion noted (folio 25)
inline int fscCritHiPct(int b)
    {
        switch (b) {
        case 0:
            return 80;
        case 1:
            return 95;
        case 2:
            return 100;
        default:
            return 9;
        }
    }

// the percent of maximum hit points dealt - 25, 50, 100 (folio 25)
inline int fscCritPctMaxHp(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 50;
        case 2:
            return 100;
        default:
            return 9;
        }
    }

// the flat hit-point minimum where greater - 6, 12, then 0 for the instant
// kill, the 'whichever is greater' pairing noted (folio 25)
inline int fscCritMinHp(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 0;
        default:
            return 9;
        }
    }

// the limb-loss code - 1 rolls a 1-4 limb (right arm, left arm, right leg,
// left leg); 0 is no additional loss, the decapitation noted (folio 25)
inline int fscCritLimbRoll(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 9;
        }
    }

// the Samurai adds one dexterity point at five experience points - 8,000
// through 616,000 (folio 25)
inline int fscSamDexBonusLevels()
    { return 5; }

// the first dexterity bonus experience point - 8,000 (folio 25)
inline int fscSamDexXp1()
    { return 8000; }

// the second dexterity bonus experience point - 64,000 (folio 25)
inline int fscSamDexXp2()
    { return 64000; }

// the third dexterity bonus experience point - 184,000 (folio 25)
inline int fscSamDexXp3()
    { return 184000; }

// the fourth dexterity bonus experience point - 368,000 (folio 25)
inline int fscSamDexXp4()
    { return 368000; }

// the fifth dexterity bonus experience point - 616,000 (folio 25)
inline int fscSamDexXp5()
    { return 616000; }

// the Japanese style armor is closely related to European plate in protection
// but lighter - 45 pounds maximum (folio 25)
inline int fscSamArmorMaxWeightLb()
    { return 45; }

// five cost-related armor grades - E through A (folio 25)
inline int fscSamArmorGradeCount()
    { return 5; }

// the grade rank - 1 through 5 for E, D, C, B, A, the letters carried in the
// audit comment (folio 25)
inline int fscArmorGradeRank(int b)
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
        default:
            return 9;
        }
    }

// the armor class - 6 down to 3, with B and A both 3 (folio 25)
inline int fscArmorAc(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 3;
        default:
            return 9;
        }
    }

// the encumbrance - 400, 400, 575, 675, 625 (folio 25)
inline int fscArmorEncumbranceGold(int b)
    {
        switch (b) {
        case 0:
            return 400;
        case 1:
            return 400;
        case 2:
            return 575;
        case 3:
            return 675;
        case 4:
            return 625;
        default:
            return 9;
        }
    }

// the value in gold pieces - 40 through 600 (folio 25)
inline int fscArmorValueGold(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 75;
        case 2:
            return 150;
        case 3:
            return 300;
        case 4:
            return 600;
        default:
            return 9;
        }
    }

// a Samurai very seldom used a shield (folio 25)
inline bool fscSamSeldomShield()
    { return true; }

// judo may be used by a Samurai only if he has no weapon in his hands (folio
// 25)
inline bool fscSamJudoUnarmedOnly()
    { return true; }

// the judo techniques were generally reserved for use against unarmed
// opponents unless necessity dictated otherwise (folio 25)
inline bool fscSamJudoVsUnarmedPreferred()
    { return true; }

// a thrown opponent takes 1 or 2 melee turns to recover his feet - the
// minimum (folio 25)
inline int fscSamJudoRecoverMinTurns()
    { return 1; }

// a thrown opponent takes 1 or 2 melee turns to recover his feet - the
// maximum (folio 25)
inline int fscSamJudoRecoverMaxTurns()
    { return 2; }

// the judo damage die runs 1-4 - the minimum (folio 25)
inline int fscSamJudoDamageMin()
    { return 1; }

// the judo damage die runs 1-4 - the maximum (folio 25)
inline int fscSamJudoDamageMax()
    { return 4; }

// a roll of 19 or 20 lets the Samurai choose to score 1-4 points of damage -
// a 4th level does it on 18-20, an 8th on 17-20 (folio 25)
inline int fscSamJudoDamageRollMin()
    { return 19; }

// for every 4 levels advanced the judo damage probability increases by 5
// percent (folio 25)
inline int fscSamJudoDamageLevelsPerStep()
    { return 4; }

// the judo damage probability step - 5 percent per 4 levels (folio 25)
inline int fscSamJudoDamagePctPerStep()
    { return 5; }

// on a roll of 20 a Samurai may elect to subdue his opponent (folio 25)
inline int fscSamJudoSubdueRollMin()
    { return 20; }

// for every 6 levels advanced the subdue probability increases by 5 percent
// in the same manner as inflicting damage (folio 25)
inline int fscSamJudoSubdueLevelsPerStep()
    { return 6; }

// the subdue probability step - 5 percent per 6 levels (folio 25)
inline int fscSamJudoSubduePctPerStep()
    { return 5; }

// the Japanese composite longbow - the yumi - may be fired standing, kneeling
// or on horseback (folio 25)
inline bool fscSamYumiAnyPosture()
    { return true; }

// the yumi costs 75 gold pieces (folio 25)
inline int fscYumiCostGold()
    { return 75; }

// the yumi's encumbrance is 50 (folio 25)
inline int fscYumiEncumbranceGold()
    { return 50; }

// twenty arrows to a bundle (folio 25)
inline int fscYumiArrowsPerBundle()
    { return 20; }

// a bundle of 20 arrows costs 5 gold pieces (folio 25)
inline int fscYumiArrowBundleCostGold()
    { return 5; }

// the Japanese quiver costs 5 gold pieces (folio 25)
inline int fscYumiQuiverCostGold()
    { return 5; }

// the Japanese quiver's encumbrance is 75 (folio 25)
inline int fscYumiQuiverEncumbranceGold()
    { return 75; }

// ---- the Berserker (folio 27) ----

// the class is highly experimental - only the boys in the 16-plus club are
// likely to do well at this, be warned (folio 27)
inline bool fscBerserkerExperimental()
    { return true; }

// the Berserker is a Fighting Man sub-class of humans (folio 27)
inline bool fscBerserkerHumanOnly()
    { return true; }

// the Berserker must be NEUTRAL (folio 27)
inline bool fscBerserkerNeutralOnly()
    { return true; }

// the Berserker's Strength must exceed 9 - pinned as 10 minimum, the 'exceed'
// conversion noted (folio 27)
inline int fscBerserkerStrMin()
    { return 10; }

// the Berserker's Constitution must exceed 9 - pinned as 10 minimum, the
// 'exceed' conversion noted (folio 27)
inline int fscBerserkerConMin()
    { return 10; }

// the Berserker's Intelligence must be below 9 - pinned as 8 maximum, the
// 'below' conversion noted (folio 27)
inline int fscBerserkerIntMax()
    { return 8; }

// at level 1 the Berserker's maximum allowed armor class is 6 (folio 27)
inline int fscBerserkerMaxAcLevelOne()
    { return 6; }

// the Berserker may use any magical items available to Fighters with the
// exception of armor and shields (folio 27)
inline bool fscBerserkerNoMagicArmorShield()
    { return true; }

// in addition to any strength experience bonuses the Berserker receives
// double points for kills until he earns his wereshape (folio 27)
inline bool fscBerserkerDoubleKillPoints()
    { return true; }

// the Berserker may never develop psionic powers (folio 27)
inline bool fscBerserkerNeverPsionic()
    { return true; }

// five lycanthropic clans - Wererat, Werewolf, Wereboar, Weretiger, Werebear
// (folio 27)
inline int fscBerserkerClanCount()
    { return 5; }

// the clan rank - 1 through 5 for Wererat, Werewolf, Wereboar, Weretiger,
// Werebear (folio 27)
inline int fscClanIndex(int b)
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
        default:
            return 9;
        }
    }

// the advance-as code - 1 Cleric, 2 Druid, 3 Fighter, the words carried in
// the audit comment (folio 27)
inline int fscClanAdvanceCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 3;
        default:
            return 9;
        }
    }

// the level the clan earns its wereshape - 6th through 10th (folio 27)
inline int fscClanWereshapeLevel(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 7;
        case 2:
            return 8;
        case 3:
            return 9;
        case 4:
            return 10;
        default:
            return 9;
        }
    }

// the level the clan gains its Followers - 8th through 12th (folio 27)
inline int fscClanFollowerLevel(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 9;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 12;
        default:
            return 9;
        }
    }

// the clan's maximum hit dice - 9 through 12 (folio 27)
inline int fscClanMaxDice(int b)
    {
        switch (b) {
        case 0:
            return 9;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 11;
        case 4:
            return 12;
        default:
            return 9;
        }
    }

// the Clanmaster's level - 11th through 15th (folio 27)
inline int fscClanmasterLevel(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 12;
        case 2:
            return 13;
        case 3:
            return 14;
        case 4:
            return 15;
        default:
            return 9;
        }
    }

// the Berserker takes his clan's wereshape when berserk, receiving all hit
// and damage bonuses (folio 27)
inline bool fscBerserkerWereshapeBonuses()
    { return true; }

// the Berserker does not receive any of the special characteristics of
// lycanthropes (folio 27)
inline bool fscBerserkerNoLycanthropePowers()
    { return true; }

// while in wereshape the Berserker may melee creatures vulnerable only to
// magical weaponry (folio 27)
inline bool fscBerserkerWereshapeMeleeMagicOnly()
    { return true; }

// insanity will always involve reversion to wereshape (folio 27)
inline bool fscBerserkerInsanityIsWereshape()
    { return true; }

// at wereshape the Berserker gains the lycanthropic language in human form
// and empathic command over normal animals of his clan type (folio 27)
inline bool fscBerserkerSpeaksLycanthropic()
    { return true; }

// at wereshape level horses check reaction at -2 whenever the Berserker
// approaches (folio 27)
inline int fscBerserkerHorseReactionMod()
    { return 2; }

// shieldbrothers will always be friendly and help each other when possible -
// failure means outlawry and open season on the outcast (folio 27)
inline bool fscBerserkerShieldbrothersFriendly()
    { return true; }

// for every two levels achieved the Berserker's armor class is increased by 1
// (folio 27)
inline int fscBerserkerAcPerTwoLevels()
    { return 1; }

// at level 4 the Berserker's chance of being surprised is reduced (folio 27)
inline int fscBerserkerSurpriseLevel()
    { return 4; }

// the level-4 surprise reduction - 1 (folio 27)
inline int fscBerserkerSurpriseStep()
    { return 1; }

// at level 6 the Berserker can detect hidden and invisible enemies (folio 27)
inline int fscBerserkerDetectLevel()
    { return 6; }

// at level 6 the Berserker gains a 4th level Companion who may be any Neutral
// Fighter type or Bard (folio 27)
inline int fscBerserkerCompanionLevel()
    { return 4; }

// at level 10 the Berserker may hire others (folio 27)
inline int fscBerserkerHireLevel()
    { return 10; }

// the Berserker's hirelings are -2 on loyalty (folio 27)
inline int fscBerserkerHireLoyaltyPenalty()
    { return 2; }

// the Berserker's hirelings may never have a loyalty rating higher than 15
// (folio 27)
inline int fscBerserkerHireLoyaltyMax()
    { return 15; }

// the Berserker is joined by 2-12 Followers at the appropriate level - the
// minimum (folio 27)
inline int fscBerserkerFollowerMin()
    { return 2; }

// the Berserker is joined by 2-12 Followers at the appropriate level - the
// maximum (folio 27)
inline int fscBerserkerFollowerMax()
    { return 12; }

// the Followers arrive with a loyalty of 16-plus (folio 27)
inline int fscBerserkerFollowerLoyaltyMin()
    { return 16; }

// one Follower must be a Bard of level 3-6 - the minimum (folio 27)
inline int fscBerserkerBardFollowerMinLevel()
    { return 3; }

// one Follower must be a Bard of level 3-6 - the maximum (folio 27)
inline int fscBerserkerBardFollowerMaxLevel()
    { return 6; }

// if killed, the Berserker's Followers may never be replaced (folio 27)
inline bool fscBerserkerFollowersNeverReplaced()
    { return true; }

// six Follower type rows on the percentile dice, the OCR's duplicate
// Magic-User row pinned as scanned (folio 27)
inline int fscBerserkerFollowerTypeBands()
    { return 6; }

// the percentile band's low roll - the '01' and '00' conventions pinned as 1
// and 100 (folio 27)
inline int fscFtyLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 61;
        case 2:
            return 61;
        case 3:
            return 71;
        case 4:
            return 81;
        case 5:
            return 91;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 27)
inline int fscFtyHi(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 70;
        case 2:
            return 70;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the type code - 1 Fighter, 2 Magic User, 3 Elf, 4 Dwarf, 5 Extraordinary
// (folio 27)
inline int fscFtyCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        default:
            return 9;
        }
    }

// six Follower level bands on the percentile dice (folio 27)
inline int fscBerserkerFollowerLevelBands()
    { return 6; }

// the percentile band's low roll (folio 27)
inline int fscFleLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 66;
        case 3:
            return 81;
        case 4:
            return 91;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 27)
inline int fscFleHi(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 65;
        case 2:
            return 80;
        case 3:
            return 90;
        case 4:
            return 99;
        case 5:
            return 100;
        default:
            return 9;
        }
    }

// the Follower's level - 2nd through 7th (folio 27)
inline int fscFleLevel(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        default:
            return 9;
        }
    }

// eight Extraordinary rows on the percentile dice (folio 27)
inline int fscBerserkerExtraordinaryBands()
    { return 8; }

// the percentile band's low roll (folio 27)
inline int fscExtLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 66;
        case 3:
            return 76;
        case 4:
            return 86;
        case 5:
            return 91;
        case 6:
            return 96;
        case 7:
            return 100;
        default:
            return 9;
        }
    }

// the percentile band's high roll (folio 27)
inline int fscExtHi(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 65;
        case 2:
            return 75;
        case 3:
            return 85;
        case 4:
            return 90;
        case 5:
            return 95;
        case 6:
            return 99;
        case 7:
            return 100;
        default:
            return 9;
        }
    }

// the extraordinary code - 1 Berserker shieldbrother, 2 Lycanthrope weretype,
// 3 Druid level 3-7, 4 Bard, 5 Ranger, 6 Hill Giant, 7 Stone Giant, 8 two
// rolls ignoring 00 (folio 27)
inline int fscExtCode(int b)
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
            return 9;
        }
    }

// the basic chance to go berserk is 10 percent, and a berserk attack may only
// be triggered once per melee (folio 27)
inline int fscBerserkBasePct()
    { return 10; }

// add 20 percent if the Berserker bites his shield - voluntary (folio 27)
inline int fscBerserkShieldBitePct()
    { return 20; }

// add 10 percent per round of melee, cumulative (folio 27)
inline int fscBerserkRoundPct()
    { return 10; }

// add 10 percent per Follower or shieldbrother the Berserker sees die (folio
// 27)
inline int fscBerserkWitnessDeathPct()
    { return 10; }

// the death of the Companion causes an automatic berserk (folio 27)
inline bool fscBerserkCompanionDeathAuto()
    { return true; }

// while berserking all attacks are at +2 in addition to any strength bonuses
// (folio 27)
inline int fscBerserkAttackBonus()
    { return 2; }

// while berserking the Berserker adds 6 to level or key check if wielding a
// magic sword (folio 27)
inline int fscBerserkMagicSwordCheckBonus()
    { return 6; }

// a Berserker may not withdraw from melee while berserk (folio 27)
inline bool fscBerserkerCannotWithdrawBerserk()
    { return true; }

// if still berserk at the end of the melee the Berserker has a 10 percent
// chance of turning on his friends (folio 27)
inline int fscBerserkTurnOnFriendsPct()
    { return 10; }

// the turn-on-friends chance deducts 1 percent per level (folio 27)
inline int fscBerserkTurnOnPerLevelPct()
    { return 1; }

// the turn-on-friends chance deducts to a minimum of 1 percent (folio 27)
inline int fscBerserkTurnOnMinPct()
    { return 1; }

// a Clanmaster's turn-on-friends chance is 0 percent (folio 27)
inline int fscBerserkClanmasterTurnOnPct()
    { return 0; }

// the Berserker must rest a complete turn after each berserk fit (folio 27)
inline int fscBerserkerRestTurns()
    { return 1; }

// Berserkers never cause lycanthropy (folio 27)
inline bool fscBerserkerNeverCauseLycanthropy()
    { return true; }

// the footnote adjustment - Wererat 5 percent (folio 27)
inline int fscBerserkerFootnoteWereratPct()
    { return 5; }

// the footnote adjustment - Werewolf 0 percent (folio 27)
inline int fscBerserkerFootnoteWerewolfPct()
    { return 0; }

// the footnote adjustment - Wereboar 0 percent (folio 27)
inline int fscBerserkerFootnoteWereboarPct()
    { return 0; }

// the footnote adjustment - Weretiger +5 percent (folio 27)
inline int fscBerserkerFootnoteWeretigerPct()
    { return 5; }

// the footnote adjustment - Werebear +10 percent (folio 27)
inline int fscBerserkerFootnoteWerebearPct()
    { return 10; }

}   // namespace rules
