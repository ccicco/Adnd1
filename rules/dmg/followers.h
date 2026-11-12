// ====================================================================
// Adnd1 - rules/dmg/followers.h
// R170: followers for upper level player characters
// by class (DMG pp.16-18) - the cleric, fighter,
// ranger, thief and assassin recruitment tables,
// the multi-class tables, the Grandfather ladder,
// the arrival timing and the paladin warhorse.
//
// Pure data, header-only (the grenade.h pattern:
// the caller rolls the dice and builds the rosters).
//
// The pp.16-18 print is summarized in the R170
// splice header and the gap report note; the
// JUDGMENTs: (a) the re-upload OCR drops the
// half-orcish 26-50 band of the RACE OF
// ASSASSIN table - pinned as the print runs;
// (b) in the MULTI-CLASSED ASSASSIN table the
// dwarf, elf and half-elf rows each print no
// other class permitted; (c) the printed
// asterisks ride as flags (the OCR shows no
// footnotes for them).
// ====================================================================

#pragma once



// ----------------------------------------------------------------------------
// Cleric followers (p.16): roll for each category,
// all 0 level men-at-arms
// ----------------------------------------------------------------------------
struct FollowerClericUnit {
    const char* kind;
    const char* armor;
    const char* weapons;
    int nMin;
    int nMax;
};



// ----------------------------------------------------------------------------
// Fighter followers (p.16): roll once for the
// leader, once for the troops
// ----------------------------------------------------------------------------
struct FollowerFighterLeader {
    int lo, hi;
    int level;
    const char* gear;
};


struct FollowerFighterTroops {
    int lo, hi;
    const char* text;
};



// ----------------------------------------------------------------------------
// Ranger followers (p.16): 2d12 count and the
// d% adjustment ladder
// ----------------------------------------------------------------------------
struct FollowerRangerAdjust {
    int lo, hi;
    int adj;        // percent, applied to each roll
    int firstOnly;  // nonzero: first roll only
};



// ----------------------------------------------------------------------------
// Thief followers (pp.16-17): 4d6 count, the
// level modifier, the category bands and the
// race and level tables
// ----------------------------------------------------------------------------
struct FollowerThiefLevelAdjust {
    int lo, hi;
    int adj;
};



// RACE OF THIEF (7 bands; the star rides as a
// flag - the OCR shows no footnote).
struct FollowerThiefRace {
    int lo, hi;
    const char* name;
    int star;
};



// LEVEL OF THIEF (7 bands; the level 1 star
// rides as a flag).
struct FollowerThiefLevel {
    int lo, hi;
    int level;
    int star;
};



// HUMANS, TABLE I: class and level range.
struct FollowerHumanClass {
    int lo, hi;
    const char* cls;
    int lvMin, lvMax;
};



// DEMI-HUMANS, TABLE II: race and class, level
// range, number arriving (12 rows).
struct FollowerDemiHuman {
    int lo, hi;
    const char* raceClass;
    int lvMin, lvMax;
    int number;
};



// ----------------------------------------------------------------------------
// The ranger/thief creature tables (p.17)
// ----------------------------------------------------------------------------
struct FollowerCreature {
    int lo, hi;
    const char* name;
    int nMin, nMax;
    int star;
};



// LEVEL OF ASSASSIN (8 bands; the 1st and 2nd
// level stars ride as flags).
struct FollowerAssassinLevel {
    int lo, hi;
    int level;
    int star;
};

// R-refactor: namespace rules -> class Followers (instance methods)
class Followers {
public:
    int folClericCategoryCount();
    const FollowerClericUnit& folClericUnit(int i);
    bool folClericRollForEachCategory();
    bool folClericAllZeroLevel();
    bool folPoleArmRandomOrAssigned();
    int folFighterLeaderBandCount();
    const FollowerFighterLeader& folFighterLeader( int i);
    int folFighterLeaderForD100(int d100);
    int folFighterTroopsBandCount();
    const FollowerFighterTroops& folFighterTroops( int i);
    int folFighterTroopsForD100(int d100);
    bool folFighterRollOnceLeaderOnceTroops();
    int folRangerAdjustBandCount();
    const FollowerRangerAdjust& folRangerAdjust( int i);
    int folRangerAdjustFor2d12(int roll);
    bool folRangerAdjustFirstRollOnly(int roll);


// Roll again if an adjustment falls within a
// category no longer permissible, or if a
// subtraction results in a score under 01.
    bool folRangerRerollImpermissibleOrUnder01();


// All scores over 70 are special, and the
// ranger attracts one follower/creature group
// only from each category.
    int folRangerSpecialThreshold();
    bool folRangerOneGroupPerCategory();
    int folRangerCountDice();
    int folRangerCountDieSides();
    int folThiefLevelAdjustBandCount();
    const FollowerThiefLevelAdjust& folThiefLevelAdjust(int i);
    int folThiefLevelAdjustFor4d6(int roll);
    int folThiefCountDice();
    int folThiefCountDieSides();


// The category bands: which table the d%
// roll selects (I humans through VI special).
    int folThiefCategoryForD100(int d100);
    int folThiefRaceBandCount();
    const FollowerThiefRace& folThiefRace(int i);
    int folThiefRaceForD100(int d100);
    int folThiefLevelBandCount();
    const FollowerThiefLevel& folThiefLevelBand( int i);
    int folThiefLevelForD100(int d100);
    int folHumanClassBandCount();
    const FollowerHumanClass& folHumanClass( int i);
    int folDemiHumanBandCount();
    const FollowerDemiHuman& folDemiHuman( int i);


// MULTI-CLASS THIEF FOLLOWER TABLE: the other
// profession by d6, per race (0 dwarf, 1 elf,
// 2 gnome, 3 half-elf, 4 halfling,
// 5 half-orc).
    const char* folThiefOtherProfession( int raceIdx, int d6);


// The printed note: followers with the
// professed class of thief are always neutral
// good.
    bool folThiefFollowersAlwaysNeutralGood();


// ANIMALS, TABLE III (one roll only).
    int folAnimalBandCount();
    const FollowerCreature& folAnimal(int i);


// MOUNTS, TABLE IV (one roll only).
    int folMountBandCount();
    const FollowerCreature& folMount(int i);


// CREATURES, TABLE V (one roll only).
    int folCreatureBandCount();
    const FollowerCreature& folCreature(int i);


// SPECIAL CREATURES, TABLE VI (one roll only;
// the copper dragon star rides as a flag).
    int folSpecialBandCount();
    const FollowerCreature& folSpecial(int i);


// ----------------------------------------------------------------------------
// Assassin followers (p.18)
// ----------------------------------------------------------------------------
    int folAssassinCountDice();
    int folAssassinCountDieSides();
    bool folAssassinAdjustForPopulation();
    int folAssassinDesertChance();
    bool folAssassinNewcomersFirstLevel();


// RACE OF ASSASSIN (6 bands; the half-orcish
// 26-50 band is dropped by the re-upload OCR
// and pinned as the print runs).
    int folAssassinRaceBandCount();
    const FollowerThiefRace& folAssassinRace( int i);
    int folAssassinRaceForD100(int d100);
    int folAssassinLevelBandCount();
    const FollowerAssassinLevel& folAssassinLevelBand(int i);
    int folAssassinLevelForD100(int d100);


// 1st and 2nd level non-human (or part human)
// assassins have a 25 percent chance of being
// multi-classed.
    int folAssassinMultiClassChance();


// MULTI-CLASSED ASSASSIN TABLE: the other
// profession by d6 (0 dwarf, 1 elf, 2 gnome,
// 3 half-elf, 4 half-orc); the dwarf, elf and
// half-elf rows print no other class
// permitted.
    const char* folAssassinOtherProfession( int raceIdx, int d6);


// ----------------------------------------------------------------------------
// The Grandfather/Grandmother of Assassins
// ----------------------------------------------------------------------------

// The 28 mid-level followers: at index i
// (0-6) there are i+1 assassins of level 8-i.
    int folGrandfatherCountAt(int i);
    int folGrandfatherLevelAt(int i);
    int folGrandfatherTotalMidLevel();
    int folGrandfatherFirstLevelMin();
    int folGrandfatherFirstLevelMax();
    int folGrandfatherDisplacedLeaveChance();
    int folGrandfatherNewLeaderMax();


// ----------------------------------------------------------------------------
// Arrival timing (p.18)
// ----------------------------------------------------------------------------

// The first follower appears d10 (with d6 tens:
// 1-2 add nothing, 3-4 add 10, 5-6 add 20)
// days after the requirements are met.
    int folArrivalTensAdjust(int d6);
    int folArrivalDayMax();


// Thereafter followers arrive at intervals of
// 1-8 days; if no one is available to receive
// them they wait 1-4 days and then depart
// forever.
    int folArrivalIntervalDaysMin();
    int folArrivalIntervalDaysMax();
    int folArrivalWaitDaysMin();
    int folArrivalWaitDaysMax();
    bool folArrivalUnreceivedGoneForever();
    bool folHenchmanOrServantMayReceive();


// ----------------------------------------------------------------------------
// The paladin warhorse (p.18)
// ----------------------------------------------------------------------------
    int folPaladinWarhorseMinLevel();
    int folPaladinJourneyMaxDaysRide();
    int folPaladinTaskWeeksMin();
    int folPaladinWarhorseServiceYears();
    bool folPaladinWarhorseMayBeWild();
    bool folPaladinGuardedByEvilFighterSameLevel();
};
