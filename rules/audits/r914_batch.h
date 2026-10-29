    // ---- R914 issue-10 opener audit ----
    // THE DRAGON ISSUE-10 OPENER ROUND, PART ONE - three adjudicated chains.
    // The Pickens Orgies Inc. article (folios 5-6): the
    // experience-only-as-spent doctrine with the level divisor capped at the
    // class hit dice, the five expenditure classes - the weekly sacrifice
    // with its 100-GP-per-level favor option, the lawful-only philanthropy,
    // the 250-GP-per-level-day research, the no-withdrawal clan hoards and
    // the 500-GP-per-level-night orgy with its constitution-days cycle - the
    // hireling halving, the fief and mill economics, the 60-40 house edge
    // with the halved winnings, and the psionic appendix at 20 GP per point
    // and 100 GP per ability roll. The Clifton wilderness article (folio 7):
    // the four-foot-square convention, the river and ford at 10% each, the
    // swimmer and road doctrines, the 75% slope turn, the five terrain
    // feature bands with their grades and roll-again tables, the run courses
    // and slope facings, the dense-woods doubled surprise at 20-120 feet, the
    // light-woods 20-100 yard sighting, the halved surprise at maximum
    // sighting, the opposite-corner placement and the grade heights. The
    // Crabaugh Random Monsters article (folios 9-10): the 20-level dungeon
    // basis, the type and intelligence bands, the hit-dice modifier and AC
    // tables, the level-offset column, the undead turning at HD/2 with the
    // vampire threshold at 17, and the weapon-or-bite damage doctrine.
    {
        using namespace rules;
        int bad = 0;
    if (dtnOrgyMaxGpPerLevel() != 500
            || dtnOrgyRecuperatingMaxGp() != 250
            || dtnResearchGpPerLevelDay() != 250
            || dtnSacrificeFavorGpPerLevel() != 100
            || dtnSpecialistFiefDivisor() != 10
            || dtnFiefExampleXp() != 3400
            || dtnFiefExampleNeed() != 240000
            || dtnMillCostGp() != 500
            || dtnMillAnnualMinGp() != 100
            || dtnMillAnnualMaxGp() != 600
            || dtnMillPeoplePer() != 100
            || dtnHouseMinEdgePct() != 60
            || dtnPsionicGpPerPoint() != 20
            || dtnPsionicGpPerAbilityRoll() != 100
            || dtnPsionicAbilityLossPct() != 10
            || dtnPsionicAbilityRegenPoints() != 100
            || dtnRiverAcrossFieldPct() != 10
            || dtnRiverFordChancePct() != 10
            || dtnSlopeTurnsToWaterPct() != 75
            || dtnDenseWoodsSightingMinFt() != 20
            || dtnDenseWoodsSightingMaxFt() != 120
            || dtnLightWoodsSightingMinYds() != 20
            || dtnLightWoodsSightingMaxYds() != 100
            || dtnGentleGradeLevels() != 1
            || dtnSteepGradeLevels() != 3
            || dtnRiverRunDirections() != 4
            || dtnRMDungeonLevels() != 20
            || dtnRMUndeadTurnDivisor() != 2
            || dtnRMVampireAtLevel() != 17
            || dtnRMUndeadACBonus() != 1
            || dtnRMHDBands() != 4
            || dtnRMACBands() != 6
            || dtnRMLevelBands() != 6
            || !dtnLawfulGoodEquivalence()
            || !dtnXpOnlyAsSpent()
            || !dtnXpDivisorIsLevelCappedAtHD()
            || !dtnDivisorTreasureXpOnly()
            || !dtnSacrificeWeeklyWindow()
            || !dtnPhilanthropyLawfulOnly()
            || !dtnResearchMuAlchemistOnly()
            || !dtnClanHoardsClannishOnly()
            || !dtnOrgyClassesOnly()
            || !dtnOrgyConstitutionDays()
            || !dtnHirelingXpHalved()
            || !dtnNoXpForUpkeep()
            || !dtnFourFootSquareEncounter()
            || !dtnSwimmerForcesRiver()
            || !dtnRoadBridgesRiver()
            || !dtnDenseWoodsDoubleSurprise()
            || !dtnClearHalveSurprise()
            || !dtnOppositeCorners()
            || !dtnLargerAreaFewerFeatures()
            || !dtnRMIntelligentWeaponDamage()
        )
            ++bad;
        // the Ward hit-dice modifier bands, four d6 bands from +2 to -1
        // (folio 9)
        int CRh[4][1] = {
            {2},
            {1},
            {0},
            {-1},
            };
        for (int b = 0;
             b < dtnRMHDBands();
             ++b) {
            int vals[1];
            vals[0] = dtnRMHDMod(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CRh[b][c])
                    ++bad;
            }
        }
        // the Crabaugh hit-dice AC table - six d12 bands, mammal AC 3 to 8,
        // reptile AC 2 to 6 with the row-12 reptile cell garbled, sentinel -1
        // (folio 9)
        int CRa[6][2] = {
            {3,2},
            {4,3},
            {5,4},
            {6,5},
            {7,6},
            {8,-1},
            };
        int nRa[2] = {0,0};
        int eRa[2] = {0,1};
        for (int b = 0;
             b < dtnRMACBands();
             ++b) {
            int vals[2];
            vals[0] = dtnRMACMammal(b);
            vals[1] = dtnRMACReptile(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CRa[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nRa[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nRa[c] != eRa[c])
                ++bad;
        // the level-offset column - six d12 bands from +3 at die 1 to -2 at
        // die 12 (folio 9)
        int CRl[6][1] = {
            {3},
            {2},
            {1},
            {0},
            {-1},
            {-2},
            };
        for (int b = 0;
             b < dtnRMLevelBands();
             ++b) {
            int vals[1];
            vals[0] = dtnRMLevelOffset(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CRl[b][c])
                    ++bad;
            }
        }
        // the dtnClearFeature band-for boundaries
    if (dtnClearFeature(69) != 0
            || dtnClearFeature(70) != 0
            || dtnClearFeature(77) != 1
            || dtnClearFeature(71) != 1
            || dtnClearFeature(82) != 2
            || dtnClearFeature(78) != 2
            || dtnClearFeature(84) != 3
            || dtnClearFeature(83) != 3
            || dtnClearFeature(88) != 4
            || dtnClearFeature(85) != 4
            || dtnClearFeature(93) != 5
            || dtnClearFeature(89) != 5
            || dtnClearFeature(97) != 6
            || dtnClearFeature(94) != 6
            || dtnClearFeature(98) != 7
        )
            ++bad;
        // the dtnRoughFeature band-for boundaries
    if (dtnRoughFeature(24) != 0
            || dtnRoughFeature(25) != 0
            || dtnRoughFeature(45) != 1
            || dtnRoughFeature(26) != 1
            || dtnRoughFeature(60) != 2
            || dtnRoughFeature(46) != 2
            || dtnRoughFeature(70) != 3
            || dtnRoughFeature(61) != 3
            || dtnRoughFeature(77) != 4
            || dtnRoughFeature(71) != 4
            || dtnRoughFeature(85) != 5
            || dtnRoughFeature(78) != 5
            || dtnRoughFeature(89) != 6
            || dtnRoughFeature(86) != 6
            || dtnRoughFeature(91) != 7
            || dtnRoughFeature(90) != 7
            || dtnRoughFeature(95) != 8
            || dtnRoughFeature(92) != 8
            || dtnRoughFeature(96) != 9
        )
            ++bad;
        // the dtnMountainFeature band-for boundaries
    if (dtnMountainFeature(14) != 0
            || dtnMountainFeature(15) != 0
            || dtnMountainFeature(55) != 1
            || dtnMountainFeature(16) != 1
            || dtnMountainFeature(60) != 2
            || dtnMountainFeature(56) != 2
            || dtnMountainFeature(70) != 3
            || dtnMountainFeature(61) != 3
            || dtnMountainFeature(75) != 4
            || dtnMountainFeature(71) != 4
            || dtnMountainFeature(87) != 5
            || dtnMountainFeature(76) != 5
            || dtnMountainFeature(95) != 6
            || dtnMountainFeature(88) != 6
            || dtnMountainFeature(96) != 7
        )
            ++bad;
        // the dtnWoodedFeature band-for boundaries
    if (dtnWoodedFeature(4) != 0
            || dtnWoodedFeature(5) != 0
            || dtnWoodedFeature(40) != 1
            || dtnWoodedFeature(6) != 1
            || dtnWoodedFeature(60) != 2
            || dtnWoodedFeature(41) != 2
            || dtnWoodedFeature(65) != 3
            || dtnWoodedFeature(61) != 3
            || dtnWoodedFeature(68) != 4
            || dtnWoodedFeature(66) != 4
            || dtnWoodedFeature(75) != 5
            || dtnWoodedFeature(69) != 5
            || dtnWoodedFeature(89) != 6
            || dtnWoodedFeature(76) != 6
            || dtnWoodedFeature(91) != 7
            || dtnWoodedFeature(90) != 7
            || dtnWoodedFeature(95) != 8
            || dtnWoodedFeature(92) != 8
            || dtnWoodedFeature(96) != 9
        )
            ++bad;
        // the dtnMarshyFeature band-for boundaries
    if (dtnMarshyFeature(4) != 0
            || dtnMarshyFeature(5) != 0
            || dtnMarshyFeature(25) != 1
            || dtnMarshyFeature(6) != 1
            || dtnMarshyFeature(55) != 2
            || dtnMarshyFeature(26) != 2
            || dtnMarshyFeature(65) != 3
            || dtnMarshyFeature(56) != 3
            || dtnMarshyFeature(80) != 4
            || dtnMarshyFeature(66) != 4
            || dtnMarshyFeature(85) != 5
            || dtnMarshyFeature(81) != 5
            || dtnMarshyFeature(93) != 6
            || dtnMarshyFeature(86) != 6
            || dtnMarshyFeature(98) != 7
            || dtnMarshyFeature(94) != 7
            || dtnMarshyFeature(99) != 8
        )
            ++bad;
        // the dtnClearGrade band-for boundaries
    if (dtnClearGrade(59) != 0
            || dtnClearGrade(60) != 0
            || dtnClearGrade(90) != 1
            || dtnClearGrade(61) != 1
            || dtnClearGrade(98) != 2
            || dtnClearGrade(91) != 2
            || dtnClearGrade(99) != 3
        )
            ++bad;
        // the dtnRoughGrade band-for boundaries
    if (dtnRoughGrade(34) != 0
            || dtnRoughGrade(35) != 0
            || dtnRoughGrade(75) != 1
            || dtnRoughGrade(36) != 1
            || dtnRoughGrade(95) != 2
            || dtnRoughGrade(76) != 2
            || dtnRoughGrade(96) != 3
        )
            ++bad;
        // the dtnMountainGrade band-for boundaries
    if (dtnMountainGrade(4) != 0
            || dtnMountainGrade(5) != 0
            || dtnMountainGrade(30) != 1
            || dtnMountainGrade(6) != 1
            || dtnMountainGrade(85) != 2
            || dtnMountainGrade(31) != 2
            || dtnMountainGrade(86) != 3
        )
            ++bad;
        // the dtnWoodedGrade band-for boundaries
    if (dtnWoodedGrade(49) != 0
            || dtnWoodedGrade(50) != 0
            || dtnWoodedGrade(85) != 1
            || dtnWoodedGrade(51) != 1
            || dtnWoodedGrade(96) != 2
            || dtnWoodedGrade(86) != 2
            || dtnWoodedGrade(97) != 3
        )
            ++bad;
        // the dtnClearExtra band-for boundaries
    if (dtnClearExtra(89) != 0
            || dtnClearExtra(90) != 0
            || dtnClearExtra(95) != 1
            || dtnClearExtra(91) != 1
            || dtnClearExtra(96) != 2
        )
            ++bad;
        // the dtnRoughExtra band-for boundaries
    if (dtnRoughExtra(59) != 0
            || dtnRoughExtra(60) != 0
            || dtnRoughExtra(75) != 1
            || dtnRoughExtra(61) != 1
            || dtnRoughExtra(81) != 2
            || dtnRoughExtra(76) != 2
            || dtnRoughExtra(94) != 3
            || dtnRoughExtra(82) != 3
            || dtnRoughExtra(95) != 4
        )
            ++bad;
        // the dtnMountainExtra band-for boundaries
    if (dtnMountainExtra(59) != 0
            || dtnMountainExtra(60) != 0
            || dtnMountainExtra(70) != 1
            || dtnMountainExtra(61) != 1
            || dtnMountainExtra(77) != 2
            || dtnMountainExtra(71) != 2
            || dtnMountainExtra(91) != 3
            || dtnMountainExtra(78) != 3
            || dtnMountainExtra(92) != 4
        )
            ++bad;
        // the dtnWoodedExtra band-for boundaries
    if (dtnWoodedExtra(14) != 0
            || dtnWoodedExtra(15) != 0
            || dtnWoodedExtra(60) != 1
            || dtnWoodedExtra(16) != 1
            || dtnWoodedExtra(90) != 2
            || dtnWoodedExtra(61) != 2
            || dtnWoodedExtra(94) != 3
            || dtnWoodedExtra(91) != 3
            || dtnWoodedExtra(95) != 4
        )
            ++bad;
        // the dtnMarshyExtra band-for boundaries
    if (dtnMarshyExtra(4) != 0
            || dtnMarshyExtra(5) != 0
            || dtnMarshyExtra(50) != 1
            || dtnMarshyExtra(6) != 1
            || dtnMarshyExtra(70) != 2
            || dtnMarshyExtra(51) != 2
            || dtnMarshyExtra(80) != 3
            || dtnMarshyExtra(71) != 3
            || dtnMarshyExtra(93) != 4
            || dtnMarshyExtra(81) != 4
            || dtnMarshyExtra(94) != 5
        )
            ++bad;
        // the dtnRiverCourse band-for boundaries
    if (dtnRiverCourse(1) != 0
            || dtnRiverCourse(2) != 0
            || dtnRiverCourse(4) != 1
            || dtnRiverCourse(3) != 1
            || dtnRiverCourse(5) != 2
        )
            ++bad;
        // the dtnSlopeFacing band-for boundaries
    if (dtnSlopeFacing(1) != 0
            || dtnSlopeFacing(2) != 0
            || dtnSlopeFacing(3) != 1
        )
            ++bad;
        // the dtnRMTypeBand band-for boundaries
    if (dtnRMTypeBand(3) != 0
            || dtnRMTypeBand(4) != 0
            || dtnRMTypeBand(7) != 1
            || dtnRMTypeBand(5) != 1
            || dtnRMTypeBand(8) != 2
        )
            ++bad;
        // the dtnRMIntelligenceBand band-for boundaries
    if (dtnRMIntelligenceBand(2) != 0
            || dtnRMIntelligenceBand(3) != 0
            || dtnRMIntelligenceBand(5) != 1
            || dtnRMIntelligenceBand(4) != 1
            || dtnRMIntelligenceBand(6) != 2
        )
            ++bad;
        // the expenditure rates - the orgy at 500 GP per level per night, 250
        // recuperating, the research at 250 GP per level per day, the
        // sacrifice favor at 100 GP per level (folios 5-6)
    if (dtnOrgyMaxGpPerLevel() != 500
            || dtnResearchGpPerLevelDay() != 250
            || dtnSacrificeFavorGpPerLevel() != 100
            || dtnOrgyRecuperatingMaxGp() != 250
        )
            ++bad;
        // the appendix II psionic rules - 20 GP per point, 100 GP per 10%
        // ability-loss roll, an ability back per 100 points regained (folio
        // 6)
    if (dtnPsionicGpPerPoint() != 20
            || dtnPsionicGpPerAbilityRoll() != 100
            || dtnPsionicAbilityLossPct() != 10
            || dtnPsionicAbilityRegenPoints() != 100
        )
            ++bad;
        // the fief economics - the 500-GP mill at 100-600 per 100 people, the
        // 60-40 house edge, the specialist divisor of 10 (folio 6)
    if (dtnMillCostGp() != 500
            || dtnMillAnnualMinGp() != 100
            || dtnMillAnnualMaxGp() != 600
            || dtnHouseMinEdgePct() != 60
            || dtnSpecialistFiefDivisor() != 10
        )
            ++bad;
        // the river at 10% with the ford at 10% more, the 75% slope turn, the
        // 20-120 foot dense-woods sighting and the 20-100 yard light-woods
        // sighting (folio 7)
    if (dtnRiverAcrossFieldPct() != 10
            || dtnRiverFordChancePct() != 10
            || dtnSlopeTurnsToWaterPct() != 75
            || dtnDenseWoodsSightingMaxFt() != 120
            || dtnLightWoodsSightingMaxYds() != 100
        )
            ++bad;
        // the terrain feature band boundaries - the clear 71-77 hill band,
        // the rough 46-60 rough-ground band, the marshy 94-98 light-woods
        // band, the wooded 6-40 dense-woods band (folio 7)
    if (dtnClearFeature(70) != 0
            || dtnClearFeature(71) != 1
            || dtnRoughFeature(60) != 2
            || dtnMarshyFeature(98) != 7
            || dtnWoodedFeature(40) != 1
        )
            ++bad;
        // the grade bands - the clear gentle 1-60, the mountainous sheer
        // 86-00 (folio 7)
    if (dtnClearGrade(60) != 0
            || dtnClearGrade(61) != 1
            || dtnMountainGrade(5) != 0
            || dtnMountainGrade(86) != 3
        )
            ++bad;
        // the Random Monsters basis - the 20-level dungeon, the undead
        // turning at HD/2, the vampire threshold at 17, the undead AC at
        // (1-8)+1 (folios 9-10)
    if (dtnRMDungeonLevels() != 20
            || dtnRMUndeadTurnDivisor() != 2
            || dtnRMVampireAtLevel() != 17
            || dtnRMUndeadACBonus() != 1
        )
            ++bad;
        // the type band - mammal 1-4, reptile 5-7, undead 8 - and the
        // intelligence band, highly 1-3 through unintelligent 6 (folio 9)
    if (dtnRMTypeBand(4) != 0
            || dtnRMTypeBand(5) != 1
            || dtnRMTypeBand(8) != 2
            || dtnRMIntelligenceBand(3) != 0
            || dtnRMIntelligenceBand(6) != 2
        )
            ++bad;
        // the hit-dice modifier bands - +2 at 1, +1 at 2-3, 0 at 4-5, -1 at 6
        // (folio 9)
    if (dtnRMHDMod(0) != 2
            || dtnRMHDMod(1) != 1
            || dtnRMHDMod(2) != 0
            || dtnRMHDMod(3) != -1
        )
            ++bad;
        // the hit-dice AC table - mammal AC 3 at die 1 to 8 at die 12,
        // reptile AC 6 at die 10-11, the row-12 reptile cell riding sentinel
        // (folio 9)
    if (dtnRMACMammal(0) != 3
            || dtnRMACMammal(5) != 8
            || dtnRMACReptile(4) != 6
            || dtnRMACReptile(5) != -1
        )
            ++bad;
        // the level-offset column - +3 at die 1, level at 6-9, -2 at die 12
        // (folio 9)
    if (dtnRMLevelOffset(0) != 3
            || dtnRMLevelOffset(3) != 0
            || dtnRMLevelOffset(5) != -2
        )
            ++bad;
        // the band census - four hit-dice modifier bands, six AC bands, six
        // level-offset bands (folio 9)
    if (dtnRMHDBands() != 4
            || dtnRMACBands() != 6
            || dtnRMLevelBands() != 6
        )
            ++bad;
        printf("R914 issue-10 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
