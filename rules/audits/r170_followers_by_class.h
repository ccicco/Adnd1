    // ---- R170: followers by class audit ----------------
    // DMG pp.16-18: the cleric, fighter, ranger,
    // thief and assassin recruitment tables,
    // the multi-class tables, the Grandfather
    // ladder, the arrival timing and the
    // paladin warhorse, cell by cell.
    {
        Followers followers;
        int bad = 0;
        // the cleric categories: 7, roll for
        // each, all 0 level men-at-arms
        if (followers.folClericCategoryCount() != 7 ||
            !followers.folClericRollForEachCategory() ||
            !followers.folClericAllZeroLevel() ||
            !followers.folPoleArmRandomOrAssigned())
            ++bad;
        static const int kClMin[7] =
            { 2, 3, 5, 5, 5, 5, 10 };
        static const int kClMax[7] =
            { 8, 12, 30, 20, 30, 30, 60 };
        for (int i = 0; i < 7; ++i) {
            Followers followers;
            if (followers.folClericUnit(i).nMin != kClMin[i] ||
                followers.folClericUnit(i).nMax != kClMax[i])
                ++bad;
        }
        if (std::string(followers.folClericUnit(0).kind)
                != "heavy cavalry" ||
            std::string(followers.folClericUnit(0).armor)
                != "plate mail and shield" ||
            std::string(followers.folClericUnit(0).weapons)
                != "lance, broad sword, mace" ||
            std::string(followers.folClericUnit(2).weapons)
                != "light crossbow, pick" ||
            std::string(followers.folClericUnit(6).kind)
                != "light infantry" ||
            std::string(followers.folClericUnit(6).weapons)
                != "spear, club")
            ++bad;
        // the fighter leader: 4 bands, levels
        // 5, 6, 6, 7
        static const int kLvl[4] = { 5, 6, 6, 7 };
        if (followers.folFighterLeaderBandCount() != 4 ||
            !followers.folFighterRollOnceLeaderOnceTroops())
            ++bad;
        for (int i = 0; i < 4; ++i)
            if (followers.folFighterLeader(i).level != kLvl[i])
                ++bad;
        if (followers.folFighterLeaderForD100(40) != 0 ||
            followers.folFighterLeaderForD100(41) != 1 ||
            followers.folFighterLeaderForD100(76) != 2 ||
            followers.folFighterLeaderForD100(96) != 3)
            ++bad;
        if (std::string(followers.folFighterLeader(0).gear)
                != "plate mail and shield, +2 magic battle axe" ||
            std::string(followers.folFighterLeader(3).gear)
                != "+1 plate mail and +1 shield, +2 magic sword (no special abilities), rides a heavy warhorse with horseshoes of speed")
            ++bad;
        // the fighter troops: 4 bands
        if (followers.folFighterTroopsBandCount() != 4)
            ++bad;
        if (followers.folFighterTroopsForD100(50) != 0 ||
            followers.folFighterTroopsForD100(51) != 1 ||
            followers.folFighterTroopsForD100(91) != 3)
            ++bad;
        if (std::string(followers.folFighterTroops(1).text)
                != "80 heavy infantry, 20 with splint mail, 60 with leather armor, 20 with morning star and hand axe, 60 with pike and short sword")
            ++bad;
        if (std::string(followers.folFighterTroops(2).text)
                != "60 crossbowmen, chain mail, 40 with heavy crossbow and short sword, 20 with light crossbow and military fork")
            ++bad;
        // the ranger: 2d12, the adjustment ladder
        static const int kRAdj[9] =
            { 25, 15, 10, 5, 0, -5, -10, -20, -30 };
        if (followers.folRangerCountDice() != 2 ||
            followers.folRangerCountDieSides() != 12 ||
            followers.folRangerAdjustBandCount() != 9 ||
            followers.folRangerSpecialThreshold() != 70 ||
            !followers.folRangerOneGroupPerCategory() ||
            !followers.folRangerRerollImpermissibleOrUnder01())
            ++bad;
        for (int i = 0; i < 9; ++i) {
            Followers followers;
            int roll = followers.folRangerAdjust(i).lo;
            if (followers.folRangerAdjustFor2d12(roll)
                    != kRAdj[i])
                ++bad;
            if (followers.folRangerAdjustFor2d12(
                    followers.folRangerAdjust(i).hi) != kRAdj[i])
                ++bad;
        }
        // +10 and +5 apply to the first roll only
        if (!followers.folRangerAdjustFirstRollOnly(4) ||
            !followers.folRangerAdjustFirstRollOnly(5) ||
            followers.folRangerAdjustFirstRollOnly(2) ||
            followers.folRangerAdjustFirstRollOnly(21))
            ++bad;
        // the thief: 4d6, the level ladder
        static const int kTAdj[6] =
            { 20, 15, 5, 0, -5, -10 };
        if (followers.folThiefCountDice() != 4 ||
            followers.folThiefCountDieSides() != 6 ||
            followers.folThiefLevelAdjustBandCount() != 6)
            ++bad;
        for (int i = 0; i < 6; ++i) {
            Followers followers;
            if (followers.folThiefLevelAdjustFor4d6(
                    followers.folThiefLevelAdjust(i).lo)
                != kTAdj[i])
                ++bad;
            if (followers.folThiefLevelAdjustFor4d6(
                    followers.folThiefLevelAdjust(i).hi)
                != kTAdj[i])
                ++bad;
        }
        // the thief category bands
        if (followers.folThiefCategoryForD100(50) != 1 ||
            followers.folThiefCategoryForD100(51) != 2 ||
            followers.folThiefCategoryForD100(71) != 3 ||
            followers.folThiefCategoryForD100(81) != 4 ||
            followers.folThiefCategoryForD100(91) != 5 ||
            followers.folThiefCategoryForD100(96) != 6)
            ++bad;
        // the race of thief: 7 bands, edges probed
        if (followers.folThiefRaceBandCount() != 7)
            ++bad;
        static const char* kTRace[7] = {
            "dwarven", "elven", "gnomish", "half-elven",
            "halfling", "half-orcish", "human"
        };
        for (int i = 0; i < 7; ++i)
            if (std::string(followers.folThiefRace(i).name)
                    != kTRace[i])
                ++bad;
        if (followers.folThiefRaceForD100(10) != 0 ||
            followers.folThiefRaceForD100(11) != 1 ||
            followers.folThiefRaceForD100(55) != 5 ||
            followers.folThiefRaceForD100(56) != 6 ||
            followers.folThiefRaceForD100(100) != 6)
            ++bad;
        // the level of thief: 7 bands
        if (followers.folThiefLevelBandCount() != 7)
            ++bad;
        if (followers.folThiefLevelForD100(20) != 0 ||
            followers.folThiefLevelForD100(21) != 1 ||
            followers.folThiefLevelForD100(96) != 6 ||
            followers.folThiefLevelBand(0).level != 1 ||
            followers.folThiefLevelBand(6).level != 7 ||
            followers.folThiefLevelBand(0).star != 1)
            ++bad;
        // the humans table I: 5 classes
        if (followers.folHumanClassBandCount() != 5)
            ++bad;
        if (std::string(followers.folHumanClass(0).cls)
                != "cleric" ||
            followers.folHumanClass(0).lvMin != 1 ||
            followers.folHumanClass(0).lvMax != 4 ||
            std::string(followers.folHumanClass(1).cls)
                != "druid" ||
            followers.folHumanClass(1).lvMin != 2 ||
            followers.folHumanClass(1).lvMax != 5 ||
            std::string(followers.folHumanClass(2).cls)
                != "fighter" ||
            followers.folHumanClass(2).lvMax != 6 ||
            std::string(followers.folHumanClass(3).cls)
                != "ranger" ||
            followers.folHumanClass(3).lvMax != 3 ||
            std::string(followers.folHumanClass(4).cls)
                != "magic-user" ||
            followers.folHumanClass(4).lvMax != 3)
            ++bad;
        // the demi-humans table II: 12 rows,
        // every band edge probed
        if (followers.folDemiHumanBandCount() != 12)
            ++bad;
        static const int kDHNum[12] =
            { 2, 1, 2, 1, 1, 3, 1, 1, 1, 1, 3, 1 };
        for (int i = 0; i < 12; ++i)
            if (followers.folDemiHuman(i).number != kDHNum[i])
                ++bad;
        if (std::string(followers.folDemiHuman(0).raceClass)
                != "dwarf fighter" ||
            followers.folDemiHuman(0).lvMin != 1 ||
            followers.folDemiHuman(0).lvMax != 4 ||
            std::string(followers.folDemiHuman(2).raceClass)
                != "elf fighter" ||
            followers.folDemiHuman(2).lvMin != 2 ||
            followers.folDemiHuman(2).lvMax != 5 ||
            std::string(followers.folDemiHuman(4).raceClass)
                != "elf fighter/magic-user/thief" ||
            std::string(followers.folDemiHuman(6).raceClass)
                != "gnome fighter/illusionist" ||
            std::string(followers.folDemiHuman(7).raceClass)
                != "half-elf cleric/ranger" ||
            std::string(followers.folDemiHuman(11).raceClass)
                != "halfling fighter/thief")
            ++bad;
        // the multi-class thief professions (d6)
        if (std::string(followers.folThiefOtherProfession(0, 3))
                != "fighter" ||
            std::string(followers.folThiefOtherProfession(1, 3))
                != "fighter" ||
            std::string(followers.folThiefOtherProfession(1, 4))
                != "magic-user" ||
            std::string(followers.folThiefOtherProfession(1, 6))
                != "fighter/magic-user" ||
            std::string(followers.folThiefOtherProfession(2, 5))
                != "fighter" ||
            std::string(followers.folThiefOtherProfession(2, 6))
                != "illusionist" ||
            std::string(followers.folThiefOtherProfession(3, 6))
                != "fighter/magic-user" ||
            std::string(followers.folThiefOtherProfession(4, 2))
                != "fighter" ||
            std::string(followers.folThiefOtherProfession(5, 3))
                != "cleric" ||
            std::string(followers.folThiefOtherProfession(5, 4))
                != "fighter" ||
            !followers.folThiefFollowersAlwaysNeutralGood())
            ++bad;
        // the animals, mounts, creatures and special
        // tables: band edges and numbers
        if (followers.folAnimalBandCount() != 5 ||
            followers.folMountBandCount() != 3 ||
            followers.folCreatureBandCount() != 5 ||
            followers.folSpecialBandCount() != 5)
            ++bad;
        if (std::string(followers.folAnimal(0).name)
                != "bear, black" ||
            followers.folAnimal(0).nMin != 1 ||
            std::string(followers.folAnimal(2).name)
                != "blink dog" ||
            followers.folAnimal(2).nMin != 2 ||
            followers.folAnimal(2).nMax != 2 ||
            std::string(followers.folAnimal(4).name)
                != "owl, giant")
            ++bad;
        if (std::string(followers.folMount(0).name)
                != "centaur" ||
            followers.folMount(0).nMin != 1 ||
            followers.folMount(0).nMax != 3 ||
            std::string(followers.folMount(2).name)
                != "pegasus" ||
            followers.folMount(2).nMax != 1)
            ++bad;
        if (std::string(followers.folCreature(0).name)
                != "brownie" ||
            followers.folCreature(0).nMin != 1 ||
            followers.folCreature(0).nMax != 2 ||
            std::string(followers.folCreature(1).name)
                != "pixie" ||
            followers.folCreature(1).nMax != 4 ||
            std::string(followers.folCreature(2).name)
                != "pseudo-dragon")
            ++bad;
        if (std::string(followers.folSpecial(0).name)
                != "copper dragon" ||
            followers.folSpecial(0).star != 1 ||
            std::string(followers.folSpecial(1).name)
                != "giant, storm" ||
            std::string(followers.folSpecial(2).name)
                != "treant" ||
            followers.folSpecial(2).nMin != 2 ||
            followers.folSpecial(2).nMax != 5 ||
            std::string(followers.folSpecial(3).name)
                != "werebear" ||
            followers.folSpecial(4).nMax != 2)
            ++bad;
        // the assassin: 7d4, 75 percent desert,
        // newcomers 1st level
        if (followers.folAssassinCountDice() != 7 ||
            followers.folAssassinCountDieSides() != 4 ||
            !followers.folAssassinAdjustForPopulation() ||
            followers.folAssassinDesertChance() != 75 ||
            !followers.folAssassinNewcomersFirstLevel())
            ++bad;
        // the race of assassin: 6 bands including
        // the half-orcish 26-50 (the OCR gap,
        // pinned as the print)
        if (followers.folAssassinRaceBandCount() != 6)
            ++bad;
        if (followers.folAssassinRaceForD100(5) != 0 ||
            followers.folAssassinRaceForD100(6) != 1 ||
            followers.folAssassinRaceForD100(16) != 3 ||
            followers.folAssassinRaceForD100(26) != 4 ||
            followers.folAssassinRaceForD100(50) != 4 ||
            followers.folAssassinRaceForD100(51) != 5 ||
            std::string(followers.folAssassinRace(4).name)
                != "half-orcish")
            ++bad;
        // the level of assassin: 8 bands
        if (followers.folAssassinLevelBandCount() != 8)
            ++bad;
        if (followers.folAssassinLevelForD100(15) != 0 ||
            followers.folAssassinLevelForD100(16) != 1 ||
            followers.folAssassinLevelBand(0).level != 1 ||
            followers.folAssassinLevelBand(0).star != 1 ||
            followers.folAssassinLevelBand(1).star != 1 ||
            followers.folAssassinLevelBand(7).level != 8 ||
            followers.folAssassinLevelForD100(96) != 7 ||
            followers.folAssassinMultiClassChance() != 25)
            ++bad;
        // the multi-classed assassin professions
        if (std::string(followers.folAssassinOtherProfession(0, 3))
                != "no other class permitted" ||
            std::string(followers.folAssassinOtherProfession(1, 5))
                != "no other class permitted" ||
            std::string(followers.folAssassinOtherProfession(2, 4))
                != "fighter" ||
            std::string(followers.folAssassinOtherProfession(2, 5))
                != "illusionist" ||
            std::string(followers.folAssassinOtherProfession(3, 2))
                != "no other class permitted" ||
            std::string(followers.folAssassinOtherProfession(4, 2))
                != "fighter" ||
            std::string(followers.folAssassinOtherProfession(4, 3))
                != "cleric")
            ++bad;
        // the Grandfather/Grandmother ladder
        {
            Followers followers;
            int total = 0;
            for (int i = 0; i < 7; ++i)
                total += followers.folGrandfatherCountAt(i);
            if (total != 28) ++bad;
        }
        if (followers.folGrandfatherCountAt(0) != 1 ||
            followers.folGrandfatherLevelAt(0) != 8 ||
            followers.folGrandfatherCountAt(6) != 7 ||
            followers.folGrandfatherLevelAt(6) != 2 ||
            followers.folGrandfatherTotalMidLevel() != 28 ||
            followers.folGrandfatherFirstLevelMin() != 4 ||
            followers.folGrandfatherFirstLevelMax() != 16 ||
            followers.folGrandfatherDisplacedLeaveChance() != 75 ||
            followers.folGrandfatherNewLeaderMax() != 44)
            ++bad;
        // the arrival timing
        if (followers.folArrivalTensAdjust(1) != 0 ||
            followers.folArrivalTensAdjust(2) != 0 ||
            followers.folArrivalTensAdjust(3) != 10 ||
            followers.folArrivalTensAdjust(4) != 10 ||
            followers.folArrivalTensAdjust(5) != 20 ||
            followers.folArrivalTensAdjust(6) != 20 ||
            followers.folArrivalDayMax() != 30 ||
            followers.folArrivalIntervalDaysMin() != 1 ||
            followers.folArrivalIntervalDaysMax() != 8 ||
            followers.folArrivalWaitDaysMin() != 1 ||
            followers.folArrivalWaitDaysMax() != 4 ||
            !followers.folArrivalUnreceivedGoneForever() ||
            !followers.folHenchmanOrServantMayReceive())
            ++bad;
        // the paladin warhorse
        if (followers.folPaladinWarhorseMinLevel() != 4 ||
            followers.folPaladinJourneyMaxDaysRide() != 7 ||
            followers.folPaladinTaskWeeksMin() != 2 ||
            followers.folPaladinWarhorseServiceYears() != 10 ||
            !followers.folPaladinWarhorseMayBeWild() ||
            !followers.folPaladinGuardedByEvilFighterSameLevel())
            ++bad;
        printf("R170 followers by class audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "r171_appendices_k_l_and_m.h"  // R833: migrated
    #include "r175_appendix_l_5_and_up_tabl.h"  // R833: migrated
