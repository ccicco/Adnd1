    // ---- R964 issue-26 commentary set audit ----
    // the four-chain commentary set audit - the lich recipe with the jar law
    // and the nine ingredient potion, the impromptu party system with the
    // Gonzo example and the robe patches, the barghest whelp growth and the
    // city thief doctrine
    {
        using namespace rules;
        int bad = 0;
    if (k26LichMinLevel() != 14
            || k26LichFloorLevel() != 10
            || k26LichJarValue() != 2000
            || k26LichEnchantHours() != 18
            || k26LichTrapBase() != 50
            || k26LichTrapPerLevel() != 6
            || k26LichSpellsErased() != 3
            || k26LichCorpseRangeFeet() != 90
            || k26LichCorpseMaxDays() != 30
            || k26LichOwnCorpsePenalty() != 10
            || k26LichCorpseMaxHd() != 4
            || k26LichEvilChoateAdj() != 6
            || k26LichPotionIngredients() != 9
            || k26LichFeeblemindKillPct() != 10
            || k26LichDexLossPct() != 30
            || k26LichPotionDeathLo() != 97
            || k26PartyAbilityDice() != 4
            || k26PartyLowLevelHi() != 4
            || k26PartyMidLevelHi() != 9
            || k26PartyHighLevelHi() != 12
            || k26PartySurplusThreshold() != 90
            || k26PartyAboveAvgPct() != 1
            || k26PartyGonzoLevel() != 9
            || k26PartyGonzoChainPct() != 135
            || k26PartyGonzoPlusTwoPct() != 54
            || k26PartyMiscItemsHi() != 4
            || k26PartyMiscListCount() != 16
            || k26PartyRobePatchesLo() != 7
            || k26PartyRobePatchesHi() != 12
            || k26PartyRobePatchListCount() != 23
            || k26PartyPotionTypesCount() != 10
            || k26BarghestWhelpDice() != 6
            || k26BarghestLitter() != 6
            || k26BarghestAcLo() != 2
            || k26BarghestAcHi() != -4
            || k26BarghestLevelsPerDie() != 8
            || k26BarghestMresPerHd() != 5
            || k26BarghestCanineMove() != 30
            || k26BarghestMotionlessUnnoticed() != 75
            || k26BarghestSurprisePct() != 50
            || k26BarghestWhelpXpLo() != 1275
            || k26BarghestAdultXpLo() != 7300
            || k26BarghestAdultLevel() != 9
            || k26BarghestAtWillSpells() != 5
            || k26BarghestPayment() != 20
            || k26ThiefDungeonCeiling() != 10
            || k26ThiefVictimTypes() != 3
            || k26ThiefSpiceMerchantLevel() != 27
            || k26ThiefStashPlaces() != 2
            || !k26LichWoodBanned()
            || !k26LichJarAllObstacles()
            || !k26LichWightishBody()
            || !k26LichRemainsEaten()
            || !k26LichOwnBodyDisintegrateOnly()
            || !k26LichNoScrollsTouchItems()
            || !k26LichJarReturnCost()
            || !k26LichZeroHpDestroyed()
            || !k26LichNoRadiatePrepared()
            || !k26LichPotionFullMoon()
            || !k26PartyAlignmentFilter()
            || !k26PartyMulticlassRound()
            || !k26PartyEquipmentCheck()
            || !k26PartyArmorOneSort()
            || !k26PartyPlusThreeCheck()
            || !k26PartySpecialFeatures()
            || !k26PartyBoltsDoubling()
            || !k26PartyOwnPotionRule()
            || !k26PartyThiefMuScrolls()
            || !k26PartyLowPowerKey()
            || !k26BarghestGehennaDeodand()
            || !k26BarghestGoblinWorship()
            || !k26BarghestZeroLevelPrey()
            || !k26BarghestAcClimb()
            || !k26BarghestStormGiantPeak()
            || !k26BarghestPlusOneRequired()
            || !k26BarghestFireNoDamage()
            || !k26BarghestWeakReturnDoom()
            || !k26BarghestDogHate()
            || !k26BarghestOfficialMonsters()
            || !k26ThiefCityDoctrine()
            || !k26ThiefDisguiseRule()
            || !k26ThiefRooftopTravel()
            || !k26ThiefAmbushShadows()
            || !k26ThiefVictimSelection()
            || !k26ThiefScapegoatPlant()
            || !k26ThiefPursuitEscape()
            || !k26ThiefAlibiMethod()
            || !k26ThiefPlayerTargets()
            || !k26ThiefRichestFun()
        )
            ++bad;
        // the frame - the 14th level life minimum, the 10th level floor, the
        // 2000 gold piece jar with the eighteen hour enchant and the wood
        // ban, the trap the soul base and climb the lich blueprint (print 36)
    if (k26LichMinLevel() != 14
            || k26LichFloorLevel() != 10
            || k26LichJarValue() != 2000
            || k26LichEnchantHours() != 18
            || k26LichTrapBase() != 50
            || k26LichTrapPerLevel() != 6
            || k26LichWoodBanned() != 1
        )
            ++bad;
        // the jar law - the erased top three, the ninety foot corpse range,
        // the thirty day limit, the own corpse minus ten, the four die cap
        // and the wightish body the lich blueprint (print 36)
    if (k26LichSpellsErased() != 3
            || k26LichCorpseRangeFeet() != 90
            || k26LichCorpseMaxDays() != 30
            || k26LichOwnCorpsePenalty() != 10
            || k26LichCorpseMaxHd() != 4
            || k26LichEvilChoateAdj() != 6
            || k26LichJarAllObstacles() != 1
            || k26LichWightishBody() != 1
        )
            ++bad;
        // the lich fate - the remains eaten, the disintegrate only body, the
        // scroll and touch bans, the level toll with the zero point doom and
        // the secrecy the lich blueprint (print 36)
    if (k26LichRemainsEaten() != 1
            || k26LichOwnBodyDisintegrateOnly() != 1
            || k26LichNoScrollsTouchItems() != 1
            || k26LichJarReturnCost() != 1
            || k26LichZeroHpDestroyed() != 1
            || k26LichNoRadiatePrepared() != 1
        )
            ++bad;
        // the nine ingredient potion - the feeblemind ten percent, the
        // paralysis dexterity gamble, the 97-00 death band and the full moon
        // brewing the lich blueprint (print 36)
    if (k26LichPotionIngredients() != 9
            || k26LichFeeblemindKillPct() != 10
            || k26LichDexLossPct() != 30
            || k26LichPotionDeathLo() != 97
            || k26LichPotionFullMoon() != 1
        )
            ++bad;
        // the system frame - the 4d4 abilities with the low die dropped, the
        // three level bands to twelve, the alignment gate, the multi class
        // math and the equipment check the impromptu party system (print 37 +
        // 39)
    if (k26PartyAbilityDice() != 4
            || k26PartyLowLevelHi() != 4
            || k26PartyMidLevelHi() != 9
            || k26PartyHighLevelHi() != 12
            || k26PartyAlignmentFilter() != 1
            || k26PartyMulticlassRound() != 1
            || k26PartyEquipmentCheck() != 1
        )
            ++bad;
        // the above average rules - the ninety percent surplus, the one
        // percent per level, the Gonzo ninth level ranger with his 135
        // percent chain and fifty four percent plus two, the plus three
        // check, the one sort armor, the special features and the bolt
        // doubling the impromptu party system (print 37 + 39)
    if (k26PartySurplusThreshold() != 90
            || k26PartyAboveAvgPct() != 1
            || k26PartyGonzoLevel() != 9
            || k26PartyGonzoChainPct() != 135
            || k26PartyGonzoPlusTwoPct() != 54
            || k26PartyPlusThreeCheck() != 1
            || k26PartyArmorOneSort() != 1
            || k26PartySpecialFeatures() != 1
            || k26PartyBoltsDoubling() != 1
        )
            ++bad;
        // the kits - the one to four award off the sixteen item list, the
        // robe with its seven to twelve patches off the twenty three, the ten
        // potion types with the own choice license, the thief magic user
        // scrolls and the low power key the impromptu party system (print 37
        // + 39)
    if (k26PartyMiscItemsHi() != 4
            || k26PartyMiscListCount() != 16
            || k26PartyRobePatchesLo() != 7
            || k26PartyRobePatchesHi() != 12
            || k26PartyRobePatchListCount() != 23
            || k26PartyPotionTypesCount() != 10
            || k26PartyOwnPotionRule() != 1
            || k26PartyThiefMuScrolls() != 1
            || k26PartyLowPowerKey() != 1
        )
            ++bad;
        // the whelp frame - the six plus six dice, the litter of six, the
        // armor class band, the magic resistance per die, the five at will
        // powers, the Gehenna rift and the goblin worship the Dragon Bestiary
        // barghest (print 44)
    if (k26BarghestWhelpDice() != 6
            || k26BarghestLitter() != 6
            || k26BarghestAcLo() != 2
            || k26BarghestAcHi() != -4
            || k26BarghestMresPerHd() != 5
            || k26BarghestAtWillSpells() != 5
            || k26BarghestGehennaDeodand() != 1
            || k26BarghestGoblinWorship() != 1
        )
            ++bad;
        // the feeding law - eight levels a die, the thirty foot canine move
        // with the motionless seventy five and the fifty percent ambush, the
        // zero level prey, the climb and the storm giant peak the Dragon
        // Bestiary barghest (print 44)
    if (k26BarghestLevelsPerDie() != 8
            || k26BarghestCanineMove() != 30
            || k26BarghestMotionlessUnnoticed() != 75
            || k26BarghestSurprisePct() != 50
            || k26BarghestZeroLevelPrey() != 1
            || k26BarghestAcClimb() != 1
            || k26BarghestStormGiantPeak() != 1
        )
            ++bad;
        // the barghest fate - the plus one steel gate, the fire immunity with
        // the return doom, the dog tell, the official stamp, the experience
        // ladder from 1275 to 7300 and the twenty dollar column pay the
        // Dragon Bestiary barghest (print 44)
    if (k26BarghestPlusOneRequired() != 1
            || k26BarghestFireNoDamage() != 1
            || k26BarghestWeakReturnDoom() != 1
            || k26BarghestDogHate() != 1
            || k26BarghestOfficialMonsters() != 1
            || k26BarghestWhelpXpLo() != 1275
            || k26BarghestAdultXpLo() != 7300
            || k26BarghestAdultLevel() != 9
            || k26BarghestPayment() != 20
        )
            ++bad;
        // the city doctrine - the ten foot dungeon ceiling, the disguise, the
        // rooftops and the ambush shadows, the three victim trades with the
        // selection law and the 27th level spice merchant warning the city
        // thief doctrine (print 46)
    if (k26ThiefCityDoctrine() != 1
            || k26ThiefDungeonCeiling() != 10
            || k26ThiefDisguiseRule() != 1
            || k26ThiefRooftopTravel() != 1
            || k26ThiefAmbushShadows() != 1
            || k26ThiefVictimTypes() != 3
            || k26ThiefVictimSelection() != 1
            || k26ThiefSpiceMerchantLevel() != 27
        )
            ++bad;
        // the thief ops - the scapegoat plants, the pursuit breaks, the two
        // stashes with the alibi, the player targets and the richest payoff
        // the city thief doctrine (print 46)
    if (k26ThiefScapegoatPlant() != 1
            || k26ThiefPursuitEscape() != 1
            || k26ThiefAlibiMethod() != 1
            || k26ThiefStashPlaces() != 2
            || k26ThiefPlayerTargets() != 1
            || k26ThiefRichestFun() != 1
        )
            ++bad;
        printf("R964 issue-26 commentary set audit: bad %d\n", bad);
        if (bad) return 1;
    }
