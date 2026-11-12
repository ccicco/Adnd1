    // ---- R960 issue-25 commentary set audit ----
    // the three-chain commentary set audit - the War of Flowers with the
    // declaration ritual and the command ladder, the To Select a Mythos guide
    // with the mythos calls, and the Conquistadores with the expedition
    // numbers and the weapon notes
    {
        using namespace rules;
        int bad = 0;
    if (s25AztecMonthDays() != 20
            || s25WarDelegations() != 3
            || s25PhratriesCount() != 4
            || s25CompanyMenLo() != 200
            || s25CompanyMenHi() != 400
            || s25PlatoonMen() != 20
            || s25MainWeapons() != 4
            || s25ArsenalClans() != 5
            || s25KnightOrders() != 3
            || s25MythosDraws() != 3
            || s25CortezSailYear() != 1518
            || s25CortezSailMen() != 600
            || s25CortezSailHorses() != 17
            || s25CortezSailCannon() != 10
            || s25CozumelSoldiers() != 508
            || s25CozumelCrossbowmen() != 32
            || s25CozumelArquebusiers() != 13
            || s25CozumelSailors() != 100
            || s25CortezLaterCavalry() != 40
            || s25CortezLaterGunners() != 80
            || s25PizarroLandYear() != 1531
            || s25PizarroLandingMen() != 180
            || s25PizarroLandingHorses() != 27
            || s25PizarroLandingCannon() != 2
            || s25PizarroMarchCavalry() != 62
            || s25PizarroMarchInfantry() != 102
            || s25ExpeditionMenMax() != 1000
            || s25EmpireYears() != 300
            || s25PikeLengthLoFt() != 12
            || s25PikeLengthHiFt() != 18
            || s25HalberdRatioLo() != 10
            || s25HalberdRatioHi() != 20
            || s25ArquebusWeightLbs() != 3
            || s25ArquebusBarrelFt() != 3
            || s25ArquebusShotsPerMin() != 1
            || s25ArquebusRangeLoYds() != 100
            || s25ArquebusRangeHiYds() != 200
            || s25CrossbowRangeYds() != 120
            || s25PikemenPctLo() != 50
            || s25PikemenPctHi() != 75
            || s25MorionCombInches() != 4
            || s25BucklerDiaFt() != 2
            || !s25TributeNotAbsorption()
            || !s25NoTributeGuarantee()
            || !s25AllMalesSoldiers()
            || !s25NoUnitDrills()
            || !s25CampaignSeasonBan()
            || !s25NoSiegeWeapons()
            || !s25CaptivesOverKills()
            || !s25NewWarriorApprenticed()
            || !s25WarriorsHeavenGuarantee()
            || !s25CottonArmorAdopted()
            || !s25WellDevelopedMythos()
            || !s25NexusGatesLimited()
            || !s25CleanSlatePreference()
            || !s25NoRealityRestraints()
            || !s25DndNonGunpowderFit()
            || !s25RealFaithsExcluded()
            || !s25GodsInCampaignOk()
            || !s25TablesNotDogma()
            || !s25HalfArmorAge()
            || !s25BreastplateProofed()
            || !s25ArquebusMatchRest()
            || !s25ArquebusWeatherFolly()
            || !s25CrossbowSteelLath()
            || !s25QuarrelPiercesArmor()
            || !s25ToledoSwordmakers()
            || !s25BattleCorners()
            || !s25PikemenHoldGround()
            || !s25CavalryChargeOpens()
        )
            ++bad;
        // the frame - the twenty day waits, the three delegations, the four
        // phratries, the twenty man platoon, the four weapons, the five clan
        // arsenal and the three knights orders the the War of Flowers
        // commentary (print 35-37)
    if (s25AztecMonthDays() != 20
            || s25WarDelegations() != 3
            || s25PhratriesCount() != 4
            || s25PlatoonMen() != 20
            || s25MainWeapons() != 4
            || s25ArsenalClans() != 5
            || s25KnightOrders() != 3
        )
            ++bad;
        // the company band with the tribute, drill, season and siege gaps the
        // the War of Flowers commentary (print 35-37)
    if (s25CompanyMenLo() != 200
            || s25CompanyMenHi() != 400
            || s25TributeNotAbsorption() != 1
            || s25NoTributeGuarantee() != 1
            || s25NoUnitDrills() != 1
            || s25CampaignSeasonBan() != 1
            || s25NoSiegeWeapons() != 1
        )
            ++bad;
        // the warrior ethos - captives over kills, the veteran attachment,
        // the heaven guarantee and the cotton adoption the the War of Flowers
        // commentary (print 35-37)
    if (s25CaptivesOverKills() != 1
            || s25NewWarriorApprenticed() != 1
            || s25WarriorsHeavenGuarantee() != 1
            || s25CottonArmorAdopted() != 1
        )
            ++bad;
        // the mythos craft - the three drawn mythologies, the common trait,
        // the gates, the clean slate and the system fit the the To Select a
        // Mythos guide (print 43)
    if (s25MythosDraws() != 3
            || s25WellDevelopedMythos() != 1
            || s25NexusGatesLimited() != 1
            || s25CleanSlatePreference() != 1
            || s25DndNonGunpowderFit() != 1
        )
            ++bad;
        // the mythos calls - the restraints cast off, the exclusions, the
        // gods and the tables the the To Select a Mythos guide (print 43)
    if (s25NoRealityRestraints() != 1
            || s25RealFaithsExcluded() != 1
            || s25GodsInCampaignOk() != 1
            || s25TablesNotDogma() != 1
        )
            ++bad;
        // the Cortez expedition - the sail year, the six hundred, the horses,
        // the cannon and the Cozumel review the the Conquistadores commentary
        // (print 44-45)
    if (s25CortezSailYear() != 1518
            || s25CortezSailMen() != 600
            || s25CortezSailHorses() != 17
            || s25CortezSailCannon() != 10
            || s25CozumelSoldiers() != 508
            || s25CozumelCrossbowmen() != 32
            || s25CozumelArquebusiers() != 13
            || s25CozumelSailors() != 100
        )
            ++bad;
        // the later Cortez count and the Pizarro landing and march the the
        // Conquistadores commentary (print 44-45)
    if (s25CortezLaterCavalry() != 40
            || s25CortezLaterGunners() != 80
            || s25PizarroLandYear() != 1531
            || s25PizarroLandingMen() != 180
            || s25PizarroLandingHorses() != 27
            || s25PizarroLandingCannon() != 2
            || s25PizarroMarchCavalry() != 62
            || s25PizarroMarchInfantry() != 102
        )
            ++bad;
        // the ceilings - the thousand man max, the three hundred year span,
        // the pike and halberd bands the the Conquistadores commentary (print
        // 44-45)
    if (s25ExpeditionMenMax() != 1000
            || s25EmpireYears() != 300
            || s25PikeLengthLoFt() != 12
            || s25PikeLengthHiFt() != 18
            || s25HalberdRatioLo() != 10
            || s25HalberdRatioHi() != 20
        )
            ++bad;
        // the gun notes - the matchlock weight, barrel, rate and range with
        // the crossbow to one hundred twenty the the Conquistadores
        // commentary (print 44-45)
    if (s25ArquebusWeightLbs() != 3
            || s25ArquebusBarrelFt() != 3
            || s25ArquebusShotsPerMin() != 1
            || s25ArquebusRangeLoYds() != 100
            || s25ArquebusRangeHiYds() != 200
            || s25CrossbowRangeYds() != 120
        )
            ++bad;
        // the armor and gun craft - the pike share, the morion comb, the
        // buckler, the proofed breastplate, the rest, the weather flaw, the
        // steel lath and the quarrel the the Conquistadores commentary (print
        // 44-45)
    if (s25PikemenPctLo() != 50
            || s25PikemenPctHi() != 75
            || s25MorionCombInches() != 4
            || s25BucklerDiaFt() != 2
            || s25HalfArmorAge() != 1
            || s25BreastplateProofed() != 1
            || s25ArquebusMatchRest() != 1
            || s25ArquebusWeatherFolly() != 1
            || s25CrossbowSteelLath() != 1
            || s25QuarrelPiercesArmor() != 1
        )
            ++bad;
        // the sword centers and the battle order - the corners, the standing
        // pikemen and the opening charge the the Conquistadores commentary
        // (print 44-45)
    if (s25ToledoSwordmakers() != 1
            || s25BattleCorners() != 1
            || s25PikemenHoldGround() != 1
            || s25CavalryChargeOpens() != 1
        )
            ++bad;
        printf("R960 issue-25 commentary set audit: bad %d\n", bad);
        if (bad) return 1;
    }
