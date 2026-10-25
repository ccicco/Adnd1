    // ---- R170: followers by class audit ----------------
    // DMG pp.16-18: the cleric, fighter, ranger,
    // thief and assassin recruitment tables,
    // the multi-class tables, the Grandfather
    // ladder, the arrival timing and the
    // paladin warhorse, cell by cell.
    {
        int bad = 0;
        // the cleric categories: 7, roll for
        // each, all 0 level men-at-arms
        if (rules::folClericCategoryCount() != 7 ||
            !rules::folClericRollForEachCategory() ||
            !rules::folClericAllZeroLevel() ||
            !rules::folPoleArmRandomOrAssigned())
            ++bad;
        static const int kClMin[7] =
            { 2, 3, 5, 5, 5, 5, 10 };
        static const int kClMax[7] =
            { 8, 12, 30, 20, 30, 30, 60 };
        for (int i = 0; i < 7; ++i) {
            if (rules::folClericUnit(i).nMin != kClMin[i] ||
                rules::folClericUnit(i).nMax != kClMax[i])
                ++bad;
        }
        if (std::string(rules::folClericUnit(0).kind)
                != "heavy cavalry" ||
            std::string(rules::folClericUnit(0).armor)
                != "plate mail and shield" ||
            std::string(rules::folClericUnit(0).weapons)
                != "lance, broad sword, mace" ||
            std::string(rules::folClericUnit(2).weapons)
                != "light crossbow, pick" ||
            std::string(rules::folClericUnit(6).kind)
                != "light infantry" ||
            std::string(rules::folClericUnit(6).weapons)
                != "spear, club")
            ++bad;
        // the fighter leader: 4 bands, levels
        // 5, 6, 6, 7
        static const int kLvl[4] = { 5, 6, 6, 7 };
        if (rules::folFighterLeaderBandCount() != 4 ||
            !rules::folFighterRollOnceLeaderOnceTroops())
            ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::folFighterLeader(i).level != kLvl[i])
                ++bad;
        if (rules::folFighterLeaderForD100(40) != 0 ||
            rules::folFighterLeaderForD100(41) != 1 ||
            rules::folFighterLeaderForD100(76) != 2 ||
            rules::folFighterLeaderForD100(96) != 3)
            ++bad;
        if (std::string(rules::folFighterLeader(0).gear)
                != "plate mail and shield, +2 magic battle axe" ||
            std::string(rules::folFighterLeader(3).gear)
                != "+1 plate mail and +1 shield, +2 magic sword (no special abilities), rides a heavy warhorse with horseshoes of speed")
            ++bad;
        // the fighter troops: 4 bands
        if (rules::folFighterTroopsBandCount() != 4)
            ++bad;
        if (rules::folFighterTroopsForD100(50) != 0 ||
            rules::folFighterTroopsForD100(51) != 1 ||
            rules::folFighterTroopsForD100(91) != 3)
            ++bad;
        if (std::string(rules::folFighterTroops(1).text)
                != "80 heavy infantry, 20 with splint mail, 60 with leather armor, 20 with morning star and hand axe, 60 with pike and short sword")
            ++bad;
        if (std::string(rules::folFighterTroops(2).text)
                != "60 crossbowmen, chain mail, 40 with heavy crossbow and short sword, 20 with light crossbow and military fork")
            ++bad;
        // the ranger: 2d12, the adjustment ladder
        static const int kRAdj[9] =
            { 25, 15, 10, 5, 0, -5, -10, -20, -30 };
        if (rules::folRangerCountDice() != 2 ||
            rules::folRangerCountDieSides() != 12 ||
            rules::folRangerAdjustBandCount() != 9 ||
            rules::folRangerSpecialThreshold() != 70 ||
            !rules::folRangerOneGroupPerCategory() ||
            !rules::folRangerRerollImpermissibleOrUnder01())
            ++bad;
        for (int i = 0; i < 9; ++i) {
            int roll = rules::folRangerAdjust(i).lo;
            if (rules::folRangerAdjustFor2d12(roll)
                    != kRAdj[i])
                ++bad;
            if (rules::folRangerAdjustFor2d12(
                    rules::folRangerAdjust(i).hi) != kRAdj[i])
                ++bad;
        }
        // +10 and +5 apply to the first roll only
        if (!rules::folRangerAdjustFirstRollOnly(4) ||
            !rules::folRangerAdjustFirstRollOnly(5) ||
            rules::folRangerAdjustFirstRollOnly(2) ||
            rules::folRangerAdjustFirstRollOnly(21))
            ++bad;
        // the thief: 4d6, the level ladder
        static const int kTAdj[6] =
            { 20, 15, 5, 0, -5, -10 };
        if (rules::folThiefCountDice() != 4 ||
            rules::folThiefCountDieSides() != 6 ||
            rules::folThiefLevelAdjustBandCount() != 6)
            ++bad;
        for (int i = 0; i < 6; ++i) {
            if (rules::folThiefLevelAdjustFor4d6(
                    rules::folThiefLevelAdjust(i).lo)
                != kTAdj[i])
                ++bad;
            if (rules::folThiefLevelAdjustFor4d6(
                    rules::folThiefLevelAdjust(i).hi)
                != kTAdj[i])
                ++bad;
        }
        // the thief category bands
        if (rules::folThiefCategoryForD100(50) != 1 ||
            rules::folThiefCategoryForD100(51) != 2 ||
            rules::folThiefCategoryForD100(71) != 3 ||
            rules::folThiefCategoryForD100(81) != 4 ||
            rules::folThiefCategoryForD100(91) != 5 ||
            rules::folThiefCategoryForD100(96) != 6)
            ++bad;
        // the race of thief: 7 bands, edges probed
        if (rules::folThiefRaceBandCount() != 7)
            ++bad;
        static const char* kTRace[7] = {
            "dwarven", "elven", "gnomish", "half-elven",
            "halfling", "half-orcish", "human"
        };
        for (int i = 0; i < 7; ++i)
            if (std::string(rules::folThiefRace(i).name)
                    != kTRace[i])
                ++bad;
        if (rules::folThiefRaceForD100(10) != 0 ||
            rules::folThiefRaceForD100(11) != 1 ||
            rules::folThiefRaceForD100(55) != 5 ||
            rules::folThiefRaceForD100(56) != 6 ||
            rules::folThiefRaceForD100(100) != 6)
            ++bad;
        // the level of thief: 7 bands
        if (rules::folThiefLevelBandCount() != 7)
            ++bad;
        if (rules::folThiefLevelForD100(20) != 0 ||
            rules::folThiefLevelForD100(21) != 1 ||
            rules::folThiefLevelForD100(96) != 6 ||
            rules::folThiefLevelBand(0).level != 1 ||
            rules::folThiefLevelBand(6).level != 7 ||
            rules::folThiefLevelBand(0).star != 1)
            ++bad;
        // the humans table I: 5 classes
        if (rules::folHumanClassBandCount() != 5)
            ++bad;
        if (std::string(rules::folHumanClass(0).cls)
                != "cleric" ||
            rules::folHumanClass(0).lvMin != 1 ||
            rules::folHumanClass(0).lvMax != 4 ||
            std::string(rules::folHumanClass(1).cls)
                != "druid" ||
            rules::folHumanClass(1).lvMin != 2 ||
            rules::folHumanClass(1).lvMax != 5 ||
            std::string(rules::folHumanClass(2).cls)
                != "fighter" ||
            rules::folHumanClass(2).lvMax != 6 ||
            std::string(rules::folHumanClass(3).cls)
                != "ranger" ||
            rules::folHumanClass(3).lvMax != 3 ||
            std::string(rules::folHumanClass(4).cls)
                != "magic-user" ||
            rules::folHumanClass(4).lvMax != 3)
            ++bad;
        // the demi-humans table II: 12 rows,
        // every band edge probed
        if (rules::folDemiHumanBandCount() != 12)
            ++bad;
        static const int kDHNum[12] =
            { 2, 1, 2, 1, 1, 3, 1, 1, 1, 1, 3, 1 };
        for (int i = 0; i < 12; ++i)
            if (rules::folDemiHuman(i).number != kDHNum[i])
                ++bad;
        if (std::string(rules::folDemiHuman(0).raceClass)
                != "dwarf fighter" ||
            rules::folDemiHuman(0).lvMin != 1 ||
            rules::folDemiHuman(0).lvMax != 4 ||
            std::string(rules::folDemiHuman(2).raceClass)
                != "elf fighter" ||
            rules::folDemiHuman(2).lvMin != 2 ||
            rules::folDemiHuman(2).lvMax != 5 ||
            std::string(rules::folDemiHuman(4).raceClass)
                != "elf fighter/magic-user/thief" ||
            std::string(rules::folDemiHuman(6).raceClass)
                != "gnome fighter/illusionist" ||
            std::string(rules::folDemiHuman(7).raceClass)
                != "half-elf cleric/ranger" ||
            std::string(rules::folDemiHuman(11).raceClass)
                != "halfling fighter/thief")
            ++bad;
        // the multi-class thief professions (d6)
        if (std::string(rules::folThiefOtherProfession(0, 3))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(1, 3))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(1, 4))
                != "magic-user" ||
            std::string(rules::folThiefOtherProfession(1, 6))
                != "fighter/magic-user" ||
            std::string(rules::folThiefOtherProfession(2, 5))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(2, 6))
                != "illusionist" ||
            std::string(rules::folThiefOtherProfession(3, 6))
                != "fighter/magic-user" ||
            std::string(rules::folThiefOtherProfession(4, 2))
                != "fighter" ||
            std::string(rules::folThiefOtherProfession(5, 3))
                != "cleric" ||
            std::string(rules::folThiefOtherProfession(5, 4))
                != "fighter" ||
            !rules::folThiefFollowersAlwaysNeutralGood())
            ++bad;
        // the animals, mounts, creatures and special
        // tables: band edges and numbers
        if (rules::folAnimalBandCount() != 5 ||
            rules::folMountBandCount() != 3 ||
            rules::folCreatureBandCount() != 5 ||
            rules::folSpecialBandCount() != 5)
            ++bad;
        if (std::string(rules::folAnimal(0).name)
                != "bear, black" ||
            rules::folAnimal(0).nMin != 1 ||
            std::string(rules::folAnimal(2).name)
                != "blink dog" ||
            rules::folAnimal(2).nMin != 2 ||
            rules::folAnimal(2).nMax != 2 ||
            std::string(rules::folAnimal(4).name)
                != "owl, giant")
            ++bad;
        if (std::string(rules::folMount(0).name)
                != "centaur" ||
            rules::folMount(0).nMin != 1 ||
            rules::folMount(0).nMax != 3 ||
            std::string(rules::folMount(2).name)
                != "pegasus" ||
            rules::folMount(2).nMax != 1)
            ++bad;
        if (std::string(rules::folCreature(0).name)
                != "brownie" ||
            rules::folCreature(0).nMin != 1 ||
            rules::folCreature(0).nMax != 2 ||
            std::string(rules::folCreature(1).name)
                != "pixie" ||
            rules::folCreature(1).nMax != 4 ||
            std::string(rules::folCreature(2).name)
                != "pseudo-dragon")
            ++bad;
        if (std::string(rules::folSpecial(0).name)
                != "copper dragon" ||
            rules::folSpecial(0).star != 1 ||
            std::string(rules::folSpecial(1).name)
                != "giant, storm" ||
            std::string(rules::folSpecial(2).name)
                != "treant" ||
            rules::folSpecial(2).nMin != 2 ||
            rules::folSpecial(2).nMax != 5 ||
            std::string(rules::folSpecial(3).name)
                != "werebear" ||
            rules::folSpecial(4).nMax != 2)
            ++bad;
        // the assassin: 7d4, 75 percent desert,
        // newcomers 1st level
        if (rules::folAssassinCountDice() != 7 ||
            rules::folAssassinCountDieSides() != 4 ||
            !rules::folAssassinAdjustForPopulation() ||
            rules::folAssassinDesertChance() != 75 ||
            !rules::folAssassinNewcomersFirstLevel())
            ++bad;
        // the race of assassin: 6 bands including
        // the half-orcish 26-50 (the OCR gap,
        // pinned as the print)
        if (rules::folAssassinRaceBandCount() != 6)
            ++bad;
        if (rules::folAssassinRaceForD100(5) != 0 ||
            rules::folAssassinRaceForD100(6) != 1 ||
            rules::folAssassinRaceForD100(16) != 3 ||
            rules::folAssassinRaceForD100(26) != 4 ||
            rules::folAssassinRaceForD100(50) != 4 ||
            rules::folAssassinRaceForD100(51) != 5 ||
            std::string(rules::folAssassinRace(4).name)
                != "half-orcish")
            ++bad;
        // the level of assassin: 8 bands
        if (rules::folAssassinLevelBandCount() != 8)
            ++bad;
        if (rules::folAssassinLevelForD100(15) != 0 ||
            rules::folAssassinLevelForD100(16) != 1 ||
            rules::folAssassinLevelBand(0).level != 1 ||
            rules::folAssassinLevelBand(0).star != 1 ||
            rules::folAssassinLevelBand(1).star != 1 ||
            rules::folAssassinLevelBand(7).level != 8 ||
            rules::folAssassinLevelForD100(96) != 7 ||
            rules::folAssassinMultiClassChance() != 25)
            ++bad;
        // the multi-classed assassin professions
        if (std::string(rules::folAssassinOtherProfession(0, 3))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(1, 5))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(2, 4))
                != "fighter" ||
            std::string(rules::folAssassinOtherProfession(2, 5))
                != "illusionist" ||
            std::string(rules::folAssassinOtherProfession(3, 2))
                != "no other class permitted" ||
            std::string(rules::folAssassinOtherProfession(4, 2))
                != "fighter" ||
            std::string(rules::folAssassinOtherProfession(4, 3))
                != "cleric")
            ++bad;
        // the Grandfather/Grandmother ladder
        {
            int total = 0;
            for (int i = 0; i < 7; ++i)
                total += rules::folGrandfatherCountAt(i);
            if (total != 28) ++bad;
        }
        if (rules::folGrandfatherCountAt(0) != 1 ||
            rules::folGrandfatherLevelAt(0) != 8 ||
            rules::folGrandfatherCountAt(6) != 7 ||
            rules::folGrandfatherLevelAt(6) != 2 ||
            rules::folGrandfatherTotalMidLevel() != 28 ||
            rules::folGrandfatherFirstLevelMin() != 4 ||
            rules::folGrandfatherFirstLevelMax() != 16 ||
            rules::folGrandfatherDisplacedLeaveChance() != 75 ||
            rules::folGrandfatherNewLeaderMax() != 44)
            ++bad;
        // the arrival timing
        if (rules::folArrivalTensAdjust(1) != 0 ||
            rules::folArrivalTensAdjust(2) != 0 ||
            rules::folArrivalTensAdjust(3) != 10 ||
            rules::folArrivalTensAdjust(4) != 10 ||
            rules::folArrivalTensAdjust(5) != 20 ||
            rules::folArrivalTensAdjust(6) != 20 ||
            rules::folArrivalDayMax() != 30 ||
            rules::folArrivalIntervalDaysMin() != 1 ||
            rules::folArrivalIntervalDaysMax() != 8 ||
            rules::folArrivalWaitDaysMin() != 1 ||
            rules::folArrivalWaitDaysMax() != 4 ||
            !rules::folArrivalUnreceivedGoneForever() ||
            !rules::folHenchmanOrServantMayReceive())
            ++bad;
        // the paladin warhorse
        if (rules::folPaladinWarhorseMinLevel() != 4 ||
            rules::folPaladinJourneyMaxDaysRide() != 7 ||
            rules::folPaladinTaskWeeksMin() != 2 ||
            rules::folPaladinWarhorseServiceYears() != 10 ||
            !rules::folPaladinWarhorseMayBeWild() ||
            !rules::folPaladinGuardedByEvilFighterSameLevel())
            ++bad;
        printf("R170 followers by class audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r171_appendices_k_l_and_m.h"  // R833: migrated
    #include "rules/audits/r175_appendix_l_5_and_up_tabl.h"  // R833: migrated
