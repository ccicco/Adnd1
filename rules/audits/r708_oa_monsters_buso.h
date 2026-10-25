    // ---- R708 OA monsters Buso audit ----
    // OA round ninety-five (capture pp. 256-257): the Chapter 12 monster
    // roster - the Buso, the first two-column monster of the roster, the stat
    // block and the description riding together, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djvBusoTypesCount() != 2
            || djvBusoNoAppearingMin() != 1
            || djvBusoNoAppearingMax() != 6
            || djvBusoTigbanuaAC() != 4
            || djvBusoMove() != 12
            || djvBusoTigbanuaHDNum() != 8
            || djvBusoTigbanuaHDMod() != 2
            || djvBusoAttacks() != 3
            || djvBusoTigbanuaDmgMin() != 1
            || djvBusoTigbanuaDmgMid() != 6
            || djvBusoTigbanuaDmgMax() != 10
            || djvBusoTigbanuaXPBase() != 1400
            || djvBusoTigbanuaXPPerHP() != 12
            || djvBusoTagamalingAC() != 5
            || djvBusoTagamalingDmgMin() != 1
            || djvBusoTagamalingDmgMid() != 4
            || djvBusoTagamalingDmgMax() != 8
            || djvTigbanuaFearRadiusFt() != 10
            || djvTagamalingTransformChancePct() != 1
            || djvTagamalingIncurablePct() != 100
            || !djvBusoUncommon()
            || !djvBusoLairNil()
            || !djvBusoTreasureNil()
            || !djvBusoMRStandard()
            || !djvBusoIntAnimal()
            || !djvBusoChaoticEvil()
            || !djvBusoSizeM()
            || !djvBusoPsionicNil()
            || !djvBusoGhoulLike()
            || !djvBusoCemeteryHabitat()
            || !djvBusoOnceFriendlyNowEnemies()
            || !djvBusoNightPredators()
            || !djvBusoTallLean()
            || !djvBusoSingleEye()
            || !djvTigbanuaFerocious()
            || !djvTigbanuaFearAura()
            || !djvTigbanuaLessThanOneHDAutoParalyzed()
            || !djvTigbanuaSaveVsParalyzation()
            || !djvTigbanuaParalyzedUntilOutOfRadius()
            || !djvTigbanuaSaveGrantsEncounterImmunity()
            || !djvTigbanuaClawsAndFangs()
            || !djvTigbanuaClawDisease()
            || !djvTigbanuaSaveVsDeathOrInfected()
            || !djvTigbanuaInfectedBecomeTagamaling()
            || !djvTigbanuaLowIntelligence()
            || !djvTagamalingInfectedPerson()
            || !djvTagamalingNightlyTransformation()
            || !djvTagamalingSavageMindless()
            || !djvTagamalingSameHDHPAsPerson()
            || !djvTagamalingHDVariable()
            || !djvTagamalingPowersUnusable()
            || !djvTagamalingNoMemory()
            || !djvTagamalingNightlyAtLimit()
        )
            ++bad;
        // the stat block - the two types, the uncommon, the 1-6, the tigbanua
        // AC 4 the move 12 the 8 + 2 the 3 attacks of 1-6/1-6/1-10 the
        // VII/1,400 + 12/hp, the tagamaling AC 5 the 3 attacks of
        // 1-4/1-4/1-8, the Nil lair, the Nil treasure, the animal, the
        // chaotic evil, the M, the Nil psionics
    if (djvBusoTypesCount() != 2
            || djvBusoNoAppearingMin() != 1
            || djvBusoNoAppearingMax() != 6
            || djvBusoTigbanuaAC() != 4
            || djvBusoMove() != 12
            || djvBusoTigbanuaHDNum() != 8
            || djvBusoTigbanuaHDMod() != 2
            || djvBusoAttacks() != 3
            || djvBusoTigbanuaDmgMin() != 1
            || djvBusoTigbanuaDmgMid() != 6
            || djvBusoTigbanuaDmgMax() != 10
            || djvBusoTigbanuaXPBase() != 1400
            || djvBusoTigbanuaXPPerHP() != 12
            || djvBusoTagamalingAC() != 5
            || djvBusoTagamalingDmgMin() != 1
            || djvBusoTagamalingDmgMid() != 4
            || djvBusoTagamalingDmgMax() != 8
            || djvBusoUncommon() != 1
            || djvBusoLairNil() != 1
            || djvBusoTreasureNil() != 1
            || djvBusoMRStandard() != 1
            || djvBusoIntAnimal() != 1
            || djvBusoChaoticEvil() != 1
            || djvBusoSizeM() != 1
            || djvBusoPsionicNil() != 1
        )
            ++bad;
        // the buso nature - the ghoul-like, the cemetery and forest and
        // rocky-mountain habitat, the once-friendly now-enemies history, the
        // night predation, the tall lean build, the single red or yellow eye
    if (djvBusoGhoulLike() != 1
            || djvBusoCemeteryHabitat() != 1
            || djvBusoOnceFriendlyNowEnemies() != 1
            || djvBusoNightPredators() != 1
            || djvBusoTallLean() != 1
            || djvBusoSingleEye() != 1
        )
            ++bad;
        // the tigbanua - the ferocious, the 10-foot fear aura, the under-1-HD
        // auto-paralysis, the save vs. paralyzation, the paralyzed until out
        // of radius, the save-granted encounter immunity, the claws and
        // fangs, the claw disease, the save vs. death or infected, the
        // infected become tagamaling, the low intelligence
    if (djvTigbanuaFearRadiusFt() != 10
            || djvTigbanuaFerocious() != 1
            || djvTigbanuaFearAura() != 1
            || djvTigbanuaLessThanOneHDAutoParalyzed() != 1
            || djvTigbanuaSaveVsParalyzation() != 1
            || djvTigbanuaParalyzedUntilOutOfRadius() != 1
            || djvTigbanuaSaveGrantsEncounterImmunity() != 1
            || djvTigbanuaClawsAndFangs() != 1
            || djvTigbanuaClawDisease() != 1
            || djvTigbanuaSaveVsDeathOrInfected() != 1
            || djvTigbanuaInfectedBecomeTagamaling() != 1
            || djvTigbanuaLowIntelligence() != 1
        )
            ++bad;
        // the tagamaling - the infected person, the 1% cumulative nightly
        // chance, the savage mindless devouring, the same HD and HP as the
        // person, the variable stat-block hit dice, the powers unusable, the
        // no memory, the 100% incurable limit with the every-night
        // transformation
    if (djvTagamalingTransformChancePct() != 1
            || djvTagamalingIncurablePct() != 100
            || djvTagamalingInfectedPerson() != 1
            || djvTagamalingNightlyTransformation() != 1
            || djvTagamalingSavageMindless() != 1
            || djvTagamalingSameHDHPAsPerson() != 1
            || djvTagamalingHDVariable() != 1
            || djvTagamalingPowersUnusable() != 1
            || djvTagamalingNoMemory() != 1
            || djvTagamalingNightlyAtLimit() != 1
        )
            ++bad;
        printf("R708 OA monsters Buso audit: bad %d\n", bad);
        if (bad) return 1;
    }
