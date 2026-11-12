    // ---- R958 issue-25 opener set audit ----
    // the three-chain opener set audit - the Gygax social class essay with
    // the bands, the forms and the profession gates, the Condotierre and
    // Papacy commentary with the White Company brackets, and the Harrop orc
    // taxonomy with the height brackets and the guides
    {
        using namespace rules;
        int bad = 0;
    if (t25CommonBand() != 75
            || t25AristocratBandHi() != 95
            || t25UpperClassBandHi() != 100
            || t25GovernmentForms() != 19
            || t25LowestClassPct() != 5
            || t25LaboringClassPct() != 10
            || t25FreemenClassPct() != 30
            || t25GentleClassPct() != 50
            || t25LesserNoblePct() != 5
            || t25WhiteCompanyLongbowmen() != 2000
            || t25WhiteCompanyMenAtArms() != 2000
            || t25FrenchInvasionYear() != 1490
            || t25EvilFamilyRaces() != 5
            || t25OrkusSpecies() != 3
            || t25KoboldusMaxFt() != 4
            || t25OgrusMinFt() != 6
            || t25GoblinFtLo() != 3
            || t25GoblinFtHi() != 5
            || t25HobgoblinFtLo() != 5
            || t25HobgoblinFtHi() != 7
            || t25LesserOrcMaxFt() != 4
            || t25GreatOrcFtLo() != 4
            || t25GreatOrcFtHi() != 6
            || t25ManOrcFtLo() != 5
            || t25ManOrcFtHi() != 6
            || t25PaintingGuides() != 10
            || t25GamingGuides() != 4
            || !t25BirthTablesRejected()
            || !t25ThievesLowestTwo()
            || !t25ClericsAboveLowestTwo()
            || !t25MagicUsersThreeHighest()
            || !t25PaladinsHighest()
            || !t25FighterLateApprenticeship()
            || !t25DmWorldPrerogative()
            || !t25ClassWillTell()
            || !t25RansomOverBlood()
            || !t25StradiotDragoon()
            || !t25CrossbowAnswer()
            || !t25MachiavelliArtOfWar()
            || !t25SwissPapalGuard()
            || !t25WhiteCompanyLivery()
            || !t25HomusBredTribes()
            || !t25KoboldGnomeFeud()
            || !t25GoblinDwarfFeud()
            || !t25SunlightMorale()
            || !t25TribalFeuds()
            || !t25FormationOrcs()
            || !t25WargCavalry()
        )
            ++bad;
        // the background bands and the government list - the common,
        // aristocratic and upper class rolls with the nineteen forms the
        // Gygax social class essay (print 12-13)
    if (t25CommonBand() != 75
            || t25AristocratBandHi() != 95
            || t25UpperClassBandHi() != 100
            || t25GovernmentForms() != 19
        )
            ++bad;
        // the adventurer distribution - five, ten, thirty, fifty and five
        // percent by class the Gygax social class essay (print 12-13)
    if (t25LowestClassPct() != 5
            || t25LaboringClassPct() != 10
            || t25FreemenClassPct() != 30
            || t25GentleClassPct() != 50
            || t25LesserNoblePct() != 5
        )
            ++bad;
        // the profession gates - the thief, cleric, magic user and paladin
        // class restrictions the Gygax social class essay (print 12-13)
    if (t25ThievesLowestTwo() != 1
            || t25ClericsAboveLowestTwo() != 1
            || t25MagicUsersThreeHighest() != 1
            || t25PaladinsHighest() != 1
        )
            ++bad;
        // the White Company and the Papacy - the Hawkwood bracket counts and
        // the Swiss guard the Armies of the Renaissance Part III commentary
        // (print 17)
    if (t25WhiteCompanyLongbowmen() != 2000
            || t25WhiteCompanyMenAtArms() != 2000
            || t25FrenchInvasionYear() != 1490
            || t25SwissPapalGuard() != 1
        )
            ++bad;
        // the family and the genus - the five race family with the three
        // orkus species and the size brackets the Harrop orc taxonomy guide
        // (print 18-19)
    if (t25EvilFamilyRaces() != 5
            || t25OrkusSpecies() != 3
            || t25KoboldusMaxFt() != 4
            || t25OgrusMinFt() != 6
            || t25LesserOrcMaxFt() != 4
        )
            ++bad;
        // the height ladder - the goblin, hobgoblin, great orc and man orc
        // brackets the Harrop orc taxonomy guide (print 18-19)
    if (t25GoblinFtLo() != 3
            || t25GoblinFtHi() != 5
            || t25HobgoblinFtLo() != 5
            || t25HobgoblinFtHi() != 7
            || t25GreatOrcFtLo() != 4
            || t25GreatOrcFtHi() != 6
            || t25ManOrcFtLo() != 5
            || t25ManOrcFtHi() != 6
        )
            ++bad;
        // the guide counts - ten painting and four gaming guides with the
        // sunlight and formation rules the Harrop orc taxonomy guide (print
        // 18-19)
    if (t25PaintingGuides() != 10
            || t25GamingGuides() != 4
            || t25SunlightMorale() != 1
            || t25FormationOrcs() != 1
            || t25WargCavalry() != 1
        )
            ++bad;
        printf("R958 issue-25 opener set audit: bad %d\n", bad);
        if (bad) return 1;
    }
