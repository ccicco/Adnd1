    // ---- R952 issue-23 commentary set audit ----
    // THE SIX-CHAIN COMMENTARY SET AUDIT - the issue-23 part-three round: the
    // trade-show roster, the armor and sword weights, the permanent-damage
    // charts with their percentile bands, the Elrohir prison formula, the
    // Kask Origins verdict and the Niall tale through the amanatlon device,
    // print 6, 14, 19-20, 21, 4 plus 21 and 8-9 plus 22-30.
    {
        using namespace rules;
        int bad = 0;
    if (k23HobbyShowNumber() != 42
            || k23ShowExhibits() != 500
            || k23ShowDays() != 4
            || k23TsrShowCount() != 3
            || k23ExhibitorRoster() != 16
            || k23DecadeYears() != 10
            || k23AnaheimYear() != 1980
            || k23DndPlatePoundsMin() != 15
            || k23DndPlatePoundsMax() != 20
            || k23CsPlateDivisor() != 3
            || k23ArmorWeightMin() != 50
            || k23ArmorWeightMax() != 60
            || k23CuirassPounds() != 69
            || k23CuirassOunces() != 5
            || k23BattleArmorPounds() != 41
            || k23BattleArmorTenths() != 135
            || k23MilaneseTenths() != 604
            || k23MailPounds() != 20
            || k23MailOunces() != 11
            || k23BarbutPounds() != 5
            || k23BarbutOunces() != 14
            || k23SwordPoundsMin() != 2
            || k23SwordPoundsMax() != 3
            || k23BastardTenthsMin() != 35
            || k23BastardTenthsMax() != 55
            || k23CsSwordPounds() != 7
            || k23SpiPoundsMin() != 5
            || k23SpiPoundsMax() != 10
            || k23SwordBookPage() != 12
            || k23NickelPage() != 57
            || k23BlairPage() != 191
            || k23ChasmFeet() != 3
            || k23PermHealMax() != 50
            || k23MagicalAidLo() != 51
            || k23MagicalAidHi() != 70
            || k23MaimedLo() != 71
            || k23MaimedHealLevel() != 5
            || k23PoisonSavePenalty() != 2
            || k23SpeedLossYards() != 10
            || k23CarryLossGold() != 300
            || k23FatigueSpeedYards() != 20
            || k23ArmsStrengthDrop() != 2
            || k23ThiefAbilityLoss() != 10
            || k23ThiefDropTwenty() != 20
            || k23CarryLossDouble() != 600
            || k23LegsAbilityDrop() != 20
            || k23SurpriseDieMax() != 3
            || k23BlindTurnsMax() != 4
            || k23WrongHandRoll() != 3
            || k23FeetMoveDrop() != 50
            || k23FatigueHighMin() != 2
            || k23FatigueLowMax() != 10
            || k23HitPointFloor() != 20
            || k23TenthFighterHp() != 10
            || k23WeaponsSwordLo() != 61
            || k23WeaponsSwordHi() != 95
            || k23DamageAreaCount() != 6
            || k23CellDepthFeet() != 200
            || k23LeadLayers() != 5
            || k23ShaftInches() != 2
            || k23GraniteTons() != 20
            || k23KeyDistanceFeet() != 20
            || k23MichiConWeeks() != 3
            || k23GenConWeeks() != 8
            || k23GenConNumber() != 12
            || k23OriginsProfitLow() != 2000
            || k23OriginsProfitHigh() != 3000
            || k23ManHoursLow() != 3000
            || k23ManHoursHigh() != 4000
            || k23DollarPerHour() != 1
            || k23FirstShows() != 2
            || k23EaglesMonth() != 7
            || k23CenturiesThousand() != 5
            || k23NiallHells() != 11
            || k23BirdEyes() != 3
            || k23HorsesSaddled() != 4
            || k23LylthiaFeet() != 12
            || k23DamageAreaRows() != 6
            || !k23AvalonHillOnlyThen()
            || !k23GamingFullFledged()
            || !k23StLouisSnowCold()
            || !k23ShanghaiInn()
            || !k23Anthonys()
            || !k23GoodNewsBylineCatch()
            || !k23NickelQuote()
            || !k23BlairQuote()
            || !k23VaultWithoutStirrups()
            || !k23HarnessFreedom()
            || !k23AugsbergCatch()
            || !k23TitlePunctCatch()
            || !k23FredrickCatch()
            || !k23QuoteCapitalCatch()
            || !k23WishHeals()
            || !k23PoisonSavesMultiply()
            || !k23ThievesLoseClimb()
            || !k23HerveArnoldNote()
            || !k23AddRationaleNote()
            || !k23BardsRobotsNote()
            || !k23ArmsOverlapCatch()
            || !k23ReducedToFromCatch()
            || !k23LegsBandCatch()
            || !k23UnfootedAsteriskCatch()
            || !k23SteelDoorsLatch()
            || !k23ChampionDuel()
            || !k23PatriarchRevival()
            || !k23Dungeonbusters()
            || !k23PennConPhilCon()
            || !k23WidenerOnly()
            || !k23MajorConsIndustry()
            || !k23IgbExample()
            || !k23YouNowWhoCatch()
            || !k23IKnowFindCatch()
            || !k23BloodDrinker()
            || !k23EmalkarthaLylthia()
            || !k23VilaspaLight()
            || !k23Messarib()
            || !k23Alphanor()
            || !k23Xinthius()
            || !k23Abaddon()
            || !k23Thilmagia()
            || !k23Pugarsk()
            || !k23RingOfShatteredMatter()
            || !k23BearCycle()
            || !k23StolenSacrificeRef()
            || !k23ShadowOfDemonRef()
            || !k23OrravianDagger()
            || !k23KallarianWine()
            || !k23ThortDeer()
            || !k23CorassianEbony()
            || !k23AzlilicSea()
            || !k23NoraddenSteppes()
            || !k23BakakanianCatch()
            || !k23LurlyrCatch()
            || !k23SosariaEyesCatch()
            || !k23SwordhillCatch()
            || !k23BrawneyCatch()
            || !k23CroachedCatch()
            || !k23SerantsCatch()
            || !k23LythiaCatch()
            || !k23ShockCatch()
            || !k23AmanatlonCatch()
            || !k23OrravianHyphenCatch()
        )
            ++bad;
        // the area-of-the-body-damaged-permanently table - head
        // one-to-fourteen through feet ninety-five-to-double-zero, the legs
        // band only five wide the permanent-damage charts (print 19-20)
        int CDa[6][3] = {
            {1,14,1},
            {15,49,2},
            {50,74,3},
            {75,79,4},
            {80,94,5},
            {95,100,6},
            };
        for (int b = 0;
             b < k23DamageAreaRows();
             ++b) {
            int vals[3];
            vals[0] = k23AreaLo(b);
            vals[1] = k23AreaHi(b);
            vals[2] = k23AreaBody(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CDa[b][c])
                    ++bad;
            }
        }
        // the trade-show frame - the forty-second show, the near five hundred
        // exhibits, the four days, the third TSR year
    if (k23HobbyShowNumber() != 42
            || k23ShowExhibits() != 500
            || k23ShowDays() != 4
            || k23TsrShowCount() != 3
        )
            ++bad;
        // the exhibitor roster - sixteen houses from the Armory to TSR, the
        // decade since Avalon Hill stood alone, the Anaheim catch
    if (k23ExhibitorRoster() != 16
            || k23DecadeYears() != 10
            || k23AnaheimYear() != 1980
            || k23GoodNewsBylineCatch() != 1
        )
            ++bad;
        // the armor-weights frame - the D and D extra pounds, the Chivalry
        // and Sorcery two-thirds claim, the Nickel fifty-to-sixty
    if (k23DndPlatePoundsMin() != 15
            || k23DndPlatePoundsMax() != 20
            || k23CsPlateDivisor() != 3
            || k23ArmorWeightMax() != 60
        )
            ++bad;
        // the surviving armors - the cuirassier sixty-nine, the Milanese
        // sixty point four, the battle forty-one, the mail twenty, the barbut
        // five
    if (k23CuirassPounds() != 69
            || k23MilaneseTenths() != 604
            || k23BattleArmorPounds() != 41
            || k23MailPounds() != 20
            || k23BarbutPounds() != 5
        )
            ++bad;
        // the sword weights - the Oakeshott two-to-three pound average, the
        // bastard three-and-a-half to five-and-a-half
    if (k23SwordPoundsMin() != 2
            || k23SwordPoundsMax() != 3
            || k23BastardTenthsMin() != 35
            || k23BastardTenthsMax() != 55
        )
            ++bad;
        // the sword polemic - the seven-pound C and S sword, the SPI
        // five-to-ten claim, the Augsberg, punctuation and Fredrick catches
    if (k23CsSwordPounds() != 7
            || k23SpiPoundsMin() != 5
            || k23SpiPoundsMax() != 10
            || k23AugsbergCatch() != 1
            || k23TitlePunctCatch() != 1
            || k23FredrickCatch() != 1
        )
            ++bad;
        // the permanency percentile - the fifty heal band, the seventy-one
        // maimed band, the fifth-level clerical out
    if (k23PermHealMax() != 50
            || k23MagicalAidHi() != 70
            || k23MaimedLo() != 71
            || k23MaimedHealLevel() != 5
        )
            ++bad;
        // the permanent impairments - the minus-two saves, the ten and twenty
        // yard speed losses, the surprise and blinding bands
    if (k23PoisonSavePenalty() != 2
            || k23SpeedLossYards() != 10
            || k23FatigueSpeedYards() != 20
            || k23SurpriseDieMax() != 3
            || k23BlindTurnsMax() != 4
        )
            ++bad;
        // the reduced-state drops - the three hundred and six hundred
        // gold-piece carries, the thief percent, the feet fifty
    if (k23CarryLossGold() != 300
            || k23CarryLossDouble() != 600
            || k23ThiefAbilityLoss() != 10
            || k23FeetMoveDrop() != 50
        )
            ++bad;
        // the fatigue state - reduced to from ten to two, the wrong-hand roll
        // of three, the overlap and five-wide catches
    if (k23FatigueHighMin() != 2
            || k23FatigueLowMax() != 10
            || k23WrongHandRoll() != 3
            || k23ReducedToFromCatch() != 1
            || k23ArmsOverlapCatch() != 1
            || k23LegsBandCatch() != 1
        )
            ++bad;
        // the weapons subtable - the sword band sixty-one to ninety-five, the
        // unfooted asterisks, the Tattoo-and-Conan ed note
    if (k23WeaponsSwordLo() != 61
            || k23WeaponsSwordHi() != 95
            || k23UnfootedAsteriskCatch() != 1
            || k23HerveArnoldNote() != 1
        )
            ++bad;
        // the Elrohir cell - two hundred feet below, five layers of true
        // lead, the two-inch shaft, the twenty tons of granite
    if (k23CellDepthFeet() != 200
            || k23LeadLayers() != 5
            || k23ShaftInches() != 2
            || k23GraniteTons() != 20
        )
            ++bad;
        // the prison doctrine - the rust-pile key, the latching steel doors,
        // the champion duel, the patriarchs
    if (k23KeyDistanceFeet() != 20
            || k23SteelDoorsLatch() != 1
            || k23ChampionDuel() != 1
            || k23PatriarchRevival() != 1
        )
            ++bad;
        // the July gap - the three weeks to PennCon Origins, the eight weeks
        // to the twelfth GenCon, the Eagles locking Widener
    if (k23MichiConWeeks() != 3
            || k23GenConWeeks() != 8
            || k23GenConNumber() != 12
            || k23EaglesMonth() != 7
        )
            ++bad;
        // the Origins verdict - the princely three thousand, the four
        // thousand man-hours, the dollar an hour, the two thanks-note catches
    if (k23OriginsProfitHigh() != 3000
            || k23ManHoursHigh() != 4000
            || k23DollarPerHour() != 1
            || k23YouNowWhoCatch() != 1
            || k23IKnowFindCatch() != 1
        )
            ++bad;
        // the tale numbers - the five thousand centuries, the eleven hells,
        // the three bird eyes, the four horses, the dozen feet
    if (k23CenturiesThousand() != 5
            || k23NiallHells() != 11
            || k23BirdEyes() != 3
            || k23HorsesSaddled() != 4
            || k23LylthiaFeet() != 12
        )
            ++bad;
        // the tale dramatis - the crimson blade, the eating light, the
        // blue-ball messenger, the Black One, the throne dreamer
    if (k23BloodDrinker() != 1
            || k23VilaspaLight() != 1
            || k23Messarib() != 1
            || k23Abaddon() != 1
            || k23Xinthius() != 1
        )
            ++bad;
        // the tale catch quartet - the Bakakanian desert, the Lurlyr king,
        // the grey and green eyes, the amanatlon
    if (k23BakakanianCatch() != 1
            || k23LurlyrCatch() != 1
            || k23SosariaEyesCatch() != 1
            || k23AmanatlonCatch() != 1
        )
            ++bad;
        // the tale catch roll - swordhill, brawney, croached, serants,
        // Lythia, shock and the dagger hyphen
    if (k23SwordhillCatch() != 1
            || k23BrawneyCatch() != 1
            || k23CroachedCatch() != 1
            || k23SerantsCatch() != 1
            || k23LythiaCatch() != 1
            || k23ShockCatch() != 1
            || k23OrravianHyphenCatch() != 1
        )
            ++bad;
        // the body-area spot check - the head one-to-fourteen, the legs
        // seventy-five-to-seventy-nine, the feet to double zero
    if (k23AreaLo(0) != 1
            || k23AreaHi(0) != 14
            || k23AreaBody(0) != 1
            || k23AreaLo(3) != 75
            || k23AreaHi(3) != 79
            || k23AreaBody(5) != 6
            || k23AreaHi(5) != 100
        )
            ++bad;
        printf("R952 issue-23 commentary set audit: bad %d\n", bad);
        if (bad) return 1;
    }
