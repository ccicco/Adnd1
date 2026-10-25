    // ---- R800 MM2 letter D part 2 audit ----
    // THE MM2 LETTER D PART 2 - the deva turn of the Monster Manual II arc
    // (the user Go call on the landed letter D part 1). The pin-time walk
    // from the print finds THREE entries on pp. 42-44: the astral deva, the
    // monadic deva and the movanic deva. THREE defs ride the R791 data_files
    // extension in the MM1 registry schema - no form splits in the deva
    // family. THE GRID: the 3-row DevaStats stat grid (every armor class,
    // hit-dice, hit, xp, lair, move and magic-resistance cell of the three
    // stat blocks). THE SETTLED READS: the monadic ARMOR: -4 capture line is
    // the armor class line; the monadic and movanic LEVEL prints IX (the
    // capture 1X is the OCR misread); the astral LEVEL prints the roman X;
    // the movanic size keeps the print 6 1/2 inches form. NO GAP FLIPS (the
    // Letter D box flips only when all the D parts land - the R791 no-flip
    // precedent). NO XP-AUDIT PATCH (mm2_print rides the allowed-source list
    // since R797). The live def walk (the one file-patch site block, no
    // census marker) cross-checks all 3 defs against the DevaStats grid and
    // the registry census floor 563 -> 566.
    {
        using namespace rules;
        int bad = 0;
    if (mm2dvRound() != 800
            || mm2dvEntryCount() != 3
            || mm2dvDefCount() != 3
            || mm2dvFirstPage() != 42
            || mm2dvLastPage() != 44
            || mm2dvRegistryBefore() != 563
            || mm2dvRegistryAfter() != 566
            || mm2dvDevaStatRows() != 3
            || mm2dvAstralXpLevel() != 10
            || mm2dvMonadicXpLevel() != 9
            || mm2dvMovanicXpLevel() != 9
            || mm2dvAstralXpValue() != 11775
            || mm2dvMonadicXpValue() != 9300
            || mm2dvMovanicXpValue() != 8786
            || mm2dvDevaCureDiseasePerDay() != 3
            || mm2dvDevaCureLightWoundsPerDay() != 7
            || mm2dvDevaCureSeriousWoundsPerDay() != 3
            || mm2dvDevaDetectTrapsPerDay() != 7
            || mm2dvDevaDispelMagicPerDay() != 7
            || mm2dvDevaHealPerDay() != 1
            || mm2dvDevaSpiritRegainYears() != 10
            || mm2dvDevaInvisibilityRadiusFeet() != 10
            || mm2dvAstralMaceBonus() != 3
            || mm2dvAstralKnockDamageThreshold() != 20
            || mm2dvAstralKnockSenselessRounds() != 14
            || mm2dvAstralDisruptionClericLevel() != 9
            || mm2dvAstralLightRadiusLo() != 4
            || mm2dvAstralLightRadiusHi() != 40
            || mm2dvAstralPfeRadiusFeet() != 10
            || mm2dvAstralPfePower() != 2
            || mm2dvAstralBladeBarrierTurns() != 7
            || mm2dvAstralPsionicAbility() != 210
            || mm2dvAstralWisdom() != 20
            || mm2dvAstralCharismaEffect() != 20
            || mm2dvMonadicRodBonus() != 2
            || mm2dvMonadicRodRangeFeet() != 10
            || mm2dvMonadicLightRadiusLo() != 3
            || mm2dvMonadicLightRadiusHi() != 30
            || mm2dvMonadicPfeRadiusFeet() != 15
            || mm2dvMonadicPfePower() != 1
            || mm2dvMonadicHoldMonsterRounds() != 8
            || mm2dvMonadicHoldMonsterPerDay() != 3
            || mm2dvMonadicProjectImagePerDay() != 1
            || mm2dvMonadicWisdom() != 19
            || mm2dvMonadicCharismaEffect() != 19
            || mm2dvMovanicSwordBonus() != 1
            || mm2dvMovanicLightRadiusLo() != 2
            || mm2dvMovanicLightRadiusHi() != 20
            || mm2dvMovanicPfeRadiusFeet() != 10
            || mm2dvMovanicPfePower() != 1
            || mm2dvMovanicNeutralizePoisonPerDay() != 3
            || mm2dvMovanicWisdom() != 18
            || mm2dvMovanicCharismaEffect() != 18
            || !mm2dvDevaUpperPlanesOfGood()
            || !mm2dvDevaMessengersOfGoodDeities()
            || !mm2dvDevaNotMostPowerful()
            || !mm2dvDevaTravelPlanesOfGood()
            || !mm2dvDevaCanBecomeEthereal()
            || !mm2dvOnlyAstralTravelsAstrallyUncommanded()
            || !mm2dvDevaAnyEnvironmentIncludingWater()
            || !mm2dvDevaMaterialBodyOnlyOnPrimeAndElemental()
            || !mm2dvDevaOnOtherPlanesSubjectToDeath()
            || !mm2dvDevaNeverNegotiateWithEvil()
            || !mm2dvNonlawfulDevasBargainWithNonevilNeutrals()
            || !mm2dvDevaEvaluatesOpponents()
            || !mm2dvDevaDividesAttacksPerRound()
            || !mm2dvDevaCommonSpellLikeList()
            || !mm2dvDevaColdImmune()
            || !mm2dvDevaElectricityImmune()
            || !mm2dvDevaMagicMissileImmune()
            || !mm2dvDevaPetrificationImmune()
            || !mm2dvDevaPoisonImmune()
            || !mm2dvDevaNormalFireImmune()
            || !mm2dvDevaGasImmune()
            || !mm2dvDevaFireHalfDamage()
            || !mm2dvMonadicFireImmuneOfAnySort()
            || !mm2dvDevaAcidFullDamage()
            || !mm2dvDevaIronAndSilverNoDamage()
            || !mm2dvDevaMagicWeaponsFullDamage()
            || !mm2dvDevaHitOnlyByPlusOneOrBetter()
            || !mm2dvAstralNeverSurprised()
            || !mm2dvAstralVacuumNoHarm()
            || !mm2dvAstralImmuneLifeLevelLoss()
            || !mm2dvAstralSoulCannotBeTrapped()
            || !mm2dvAstralImmuneDeathSpells()
            || !mm2dvAstralGoldSkinAndWings()
            || !mm2dvMonadicDenseDoubleDamageSecondHit()
            || !mm2dvMonadicImmuneLifeLevelLoss()
            || !mm2dvMonadicImmuneDeathMagic()
            || !mm2dvMonadicSilverySheenWings()
            || !mm2dvMovanicFlameTongueSword()
            || !mm2dvMovanicPlantsCannotHarm()
            || !mm2dvMovanicAnimalsWillNotAttack()
            || !mm2dvMovanicImmuneDeathMagic()
            || !mm2dvMovanicUnaffectedByEnergyPlanes()
        )
            ++bad;
        // THE DEVA GRID: the 3-row DevaStats stat grid (every armor class,
        // hit-dice, hit, xp, lair, move and magic-resistance cell of the
        // three deva stat blocks)
        int CDevaStats[3][10] = {
            {-6,9,36,67,2,10100,25,0,18,65},
            {-4,8,32,60,2,8100,20,0,15,60},
            {-5,7,28,52,3,7850,18,0,12,55},
            };
        for (int b = 0;
             b < mm2dvDevaStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2dvDevaStatAC(b);
            vals[1] = mm2dvDevaStatHd(b);
            vals[2] = mm2dvDevaStatHdBonus(b);
            vals[3] = mm2dvDevaStatAvgHp(b);
            vals[4] = mm2dvDevaStatAttacks(b);
            vals[5] = mm2dvDevaStatXp(b);
            vals[6] = mm2dvDevaStatXpHp(b);
            vals[7] = mm2dvDevaStatLairPct(b);
            vals[8] = mm2dvDevaStatMove(b);
            vals[9] = mm2dvDevaStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CDevaStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2dvRegistryAfter() - mm2dvRegistryBefore() != mm2dvDefCount()
            || mm2dvDefCount() != 3
            || mm2dvEntryCount() != 3
        )
            ++bad;
        // each grid xp tile equals its pinned full kill xp (the xpValue
        // formula, pin-vs-pin)
    if (mm2dvDevaStatXp(0) + mm2dvDevaStatXpHp(0) * mm2dvDevaStatAvgHp(0) !=
        mm2dvAstralXpValue()
            || mm2dvDevaStatXp(1) + mm2dvDevaStatXpHp(1) *
            mm2dvDevaStatAvgHp(1) != mm2dvMonadicXpValue()
            || mm2dvDevaStatXp(2) + mm2dvDevaStatXpHp(2) *
            mm2dvDevaStatAvgHp(2) != mm2dvMovanicXpValue()
        )
            ++bad;
        // the settled LEVEL reads: the astral X and the monadic/movanic IX
        // (the capture 1X is the OCR misread)
    if (mm2dvAstralXpLevel() != 10
            || mm2dvMonadicXpLevel() != 9
            || mm2dvMovanicXpLevel() != 9
        )
            ++bad;
        // the protection from evil spheres: the radii and the powers
    if (mm2dvAstralPfeRadiusFeet() != 10
            || mm2dvAstralPfePower() != 2
            || mm2dvMonadicPfeRadiusFeet() != 15
            || mm2dvMonadicPfePower() != 1
            || mm2dvMovanicPfeRadiusFeet() != 10
            || mm2dvMovanicPfePower() != 1
        )
            ++bad;
        // the light radius ranges
    if (mm2dvAstralLightRadiusLo() != 4
            || mm2dvAstralLightRadiusHi() != 40
            || mm2dvMonadicLightRadiusLo() != 3
            || mm2dvMonadicLightRadiusHi() != 30
            || mm2dvMovanicLightRadiusLo() != 2
            || mm2dvMovanicLightRadiusHi() != 20
        )
            ++bad;
        // the per-day power counts
    if (mm2dvDevaCureDiseasePerDay() != 3
            || mm2dvDevaCureLightWoundsPerDay() != 7
            || mm2dvDevaCureSeriousWoundsPerDay() != 3
            || mm2dvDevaDetectTrapsPerDay() != 7
            || mm2dvDevaDispelMagicPerDay() != 7
            || mm2dvDevaHealPerDay() != 1
            || mm2dvMonadicHoldMonsterPerDay() != 3
            || mm2dvMonadicProjectImagePerDay() != 1
            || mm2dvMovanicNeutralizePoisonPerDay() != 3
        )
            ++bad;
        // the wisdom, charisma, psionic and spirit-decade effects
    if (mm2dvAstralWisdom() != 20
            || mm2dvAstralCharismaEffect() != 20
            || mm2dvMonadicWisdom() != 19
            || mm2dvMonadicCharismaEffect() != 19
            || mm2dvMovanicWisdom() != 18
            || mm2dvMovanicCharismaEffect() != 18
            || mm2dvAstralPsionicAbility() != 210
            || mm2dvDevaSpiritRegainYears() != 10
            || mm2dvDevaInvisibilityRadiusFeet() != 10
        )
            ++bad;
        // the weapon and power tiles
    if (mm2dvAstralMaceBonus() != 3
            || mm2dvAstralKnockDamageThreshold() != 20
            || mm2dvAstralKnockSenselessRounds() != 14
            || mm2dvAstralDisruptionClericLevel() != 9
            || mm2dvAstralBladeBarrierTurns() != 7
            || mm2dvMonadicRodBonus() != 2
            || mm2dvMonadicRodRangeFeet() != 10
            || mm2dvMonadicHoldMonsterRounds() != 8
            || mm2dvMovanicSwordBonus() != 1
        )
            ++bad;
        printf("R800 MM2 letter D part 2 audit: bad %d\n", bad);
        if (bad) return 1;
    }
