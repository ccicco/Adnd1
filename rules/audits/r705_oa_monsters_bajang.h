    // ---- R705 OA monsters Bajang audit ----
    // OA round ninety-two (capture pp. 253-254): the Chapter 12 monster
    // roster opener - the Bajang (Lesser Spirit), the stat block and the
    // description riding together, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djsBajangFrequencyClass() != 1
            || djsBajangNoAppearing() != 1
            || djsBajangAC() != 2
            || djsBajangMove() != 12
            || djsBajangHD() != 6
            || djsBajangLairPct() != 20
            || djsBajangAttacks() != 2
            || djsBajangDmgMin() != 1
            || djsBajangDmgMax() != 4
            || djsBajangMRPct() != 10
            || djsBajangSpellUsesPerDay() != 3
            || djsBajangSpellCount() != 8
            || djsBajangAncientCursePerDay() != 1
            || djsBajangPoisonPenalty() != 1
            || djsBajangPoisonMinRounds() != 2
            || djsBajangPoisonMaxRounds() != 7
            || djsBajangXPBase() != 500
            || djsBajangXPPerHP() != 6
            || djsBajangLangCount() != 3
            || !djsBajangLesserSpirit()
            || !djsBajangTropicalJungle()
            || !djsBajangTrueFormHumanoid()
            || !djsBajangWildcatShapeCommon()
            || !djsBajangPoisonCumulative()
            || !djsBajangTreeLifeforce()
            || !djsBajangNightVillagePredator()
            || !djsBajangEvilSorcererFamiliar()
            || !djsBajangIntelligentDevious()
        )
            ++bad;
        // the stat block - the very rare, the 1, the AC 2, the move 12, the
        // HD 6, the 20% lair, the treasure P, the 2 attacks of 1-4, the
        // spells and poison, the 10% MR, the XP 500 + 6 per hp
    if (djsBajangFrequencyClass() != 1
            || djsBajangNoAppearing() != 1
            || djsBajangAC() != 2
            || djsBajangMove() != 12
            || djsBajangHD() != 6
            || djsBajangLairPct() != 20
            || djsBajangAttacks() != 2
            || djsBajangDmgMin() != 1
            || djsBajangDmgMax() != 4
            || djsBajangMRPct() != 10
            || djsBajangXPBase() != 500
            || djsBajangXPPerHP() != 6
        )
            ++bad;
        // the spells - the eight cast three per day, the ancient curse once
        // per day
    if (djsBajangSpellCount() != 8
            || djsBajangSpellUsesPerDay() != 3
            || djsBajangAncientCursePerDay() != 1
        )
            ++bad;
        // the claw poison - the -1 penalty, the 2-7 rounds, the cumulative
        // effect
    if (djsBajangPoisonPenalty() != 1
            || djsBajangPoisonMinRounds() != 2
            || djsBajangPoisonMaxRounds() != 7
            || djsBajangPoisonCumulative() != 1
        )
            ++bad;
        // the nature - the lesser spirit, the tropical jungle, the humanoid
        // true form, the wildcat the common shape, the tree lifeforce, the
        // night predation, the sorcerer familiar, the devious intelligence,
        // the languages
    if (djsBajangLesserSpirit() != 1
            || djsBajangTropicalJungle() != 1
            || djsBajangTrueFormHumanoid() != 1
            || djsBajangWildcatShapeCommon() != 1
            || djsBajangTreeLifeforce() != 1
            || djsBajangNightVillagePredator() != 1
            || djsBajangEvilSorcererFamiliar() != 1
            || djsBajangIntelligentDevious() != 1
            || djsBajangLangCount() != 3
        )
            ++bad;
        printf("R705 OA monsters Bajang audit: bad %d\n", bad);
        if (bad) return 1;
    }
