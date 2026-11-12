    // ---- R915 issue-10 opener audit ----
    // THE DRAGON ISSUE-10 OPENER ROUND, PART TWO - three adjudicated chains
    // and the part-one flip. The Gilbert Let There Be A Method To Your
    // Madness article (folios 11-14): the builders-mindset doctrine with the
    // organized-origins rule, the misread-rooms doctrine, the builder-traits
    // decree, the storage-room rule, the two-views drawing scale at 200 feet
    // to the inch, the keep-it-simple doctrine, the rich-builder doctrine and
    // the Nappo example - 120 years of life, 275 years dead, three facets
    // generating fifteen levels. The Crabaugh Weights & Measures article
    // (folios 19-20): the 3d6 Size and d6 Build with the hit-per-die bonuses
    // at 16 and penalties at 5, the pound at 10 GP, the armor fractions at
    // 15, 30 and 60 percent of body mass, the female +2 Constitution and +1
    // Dexterity, the carrying-capacity grid in tenths with the elf column
    // mirroring the human, the speed ladder at 3, 6, 9 and 12, the male and
    // female height-and-weight grids across the sixteen Size rows, and the
    // appearance bands - eyes, hair, skin, voice, handedness, expression and
    // hair length, males at 30% bearded. The Holsinger Gaining a New
    // Experience Level article (folios 20-21): the four-part ritual, the
    // sacrifice total at double the new level with each creature at least
    // half, the conscious-sacrifice rule, the 50/50 and 60/40 notice chances
    // with the 50% temple-rite kill, the mistletoe and tree sacrifices at 10
    // and 1 hit dice, the drunken-stupor emissaries, the demihuman liquor
    // toughness, the 7th-level militia ejection and the guild halls, and the
    // spell learning and forgetting rules. The part-one box in report 010
    // flips closed (1 closed / 1 open).
    {
        using namespace rules;
        int bad = 0;
    if (dtnGilNappoLevels() != 15
            || dtnGilNappoFacets() != 3
            || dtnGilScaleFtPerInch() != 200
            || dtnGilNappoLifespanYears() != 120
            || dtnGilNappoDeadYears() != 275
            || dtnWmPoundGp() != 10
            || dtnWmLeatherPct() != 15
            || dtnWmChainPct() != 30
            || dtnWmPlatePct() != 60
            || dtnWmFemaleConBonus() != 2
            || dtnWmFemaleDexBonus() != 1
            || dtnWmSizeBonusMin() != 16
            || dtnWmSizePenaltyMax() != 5
            || dtnWmSizeHpMod() != 1
            || dtnWmSpeedFull() != 3
            || dtnWmSpeedTwoThirds() != 6
            || dtnWmSpeedOneThird() != 9
            || dtnWmSpeedLightest() != 12
            || dtnWmMaleBeardPct() != 30
            || dtnWmSizeBands() != 16
            || dtnWmCarryBands() != 16
            || dtnHolsSacrificeTotalFactor() != 2
            || dtnHolsSacrificeEachMinHalf() != 2
            || dtnHolsNeutralSacrificePct() != 50
            || dtnHolsEvilSacrificeNothingPct() != 50
            || dtnHolsGoodSacrilegeRightPct() != 60
            || dtnHolsWrongGodsPct() != 40
            || dtnHolsTempleRiteKillPct() != 50
            || dtnHolsCastleLevel() != 7
            || dtnHolsTreeHD() != 1
            || dtnHolsMistletoeHD() != 10
            || dtnHolsTreeMinFt() != 10
            || !dtnGilBuildersMindset()
            || !dtnGilOrganizedOrigins()
            || !dtnGilRoomsMisread()
            || !dtnGilBuilderTraitsDecree()
            || !dtnGilStorageRoomsRule()
            || !dtnGilTwoViewsRule()
            || !dtnGilKeepItSimple()
            || !dtnGilRichBuilderRichDungeon()
            || !dtnWmSizeThreeDice()
            || !dtnWmBuildFunctionalHumans()
            || !dtnWmElfMirrorsHuman()
            || !dtnWmFemaleLighterCapacity()
            || !dtnWmMusculatureVsForce()
            || !dtnWmAppearanceHumanOnly()
            || !dtnHolsFourPartRitual()
            || !dtnHolsGoodFastingPrayer()
            || !dtnHolsSacrificeConsciousRule()
            || !dtnHolsGoodNoNeutralHumans()
            || !dtnHolsNeutralMistletoeRite()
            || !dtnHolsClericIntercession()
            || !dtnHolsClericsExpectPay()
            || !dtnHolsExhaustionStuporRule()
            || !dtnHolsDemiHumanLiquorToughness()
            || !dtnHolsMilitiaEjects7th()
            || !dtnHolsGuildHalls()
            || !dtnHolsSpellLearningRitual()
            || !dtnHolsForgettingSpells()
        )
            ++bad;
        // the male human height and weight grid - sixteen Size rows, height
        // 5-1 to 6-4, light 120 to 175, medium 135 to 195 with the Size-4 row
        // as scanned at 185, heavy 145 to 215 (folio 19)
        int CWm[16][4] = {
            {61,120,135,145},
            {62,120,185,150},
            {63,125,140,155},
            {64,130,145,155},
            {65,130,145,160},
            {66,135,150,165},
            {67,140,155,170},
            {68,140,160,175},
            {69,145,160,180},
            {70,150,165,185},
            {71,155,170,190},
            {72,160,175,195},
            {73,160,180,200},
            {74,165,185,205},
            {75,170,190,210},
            {76,175,195,215},
            };
        for (int b = 0;
             b < dtnWmSizeBands();
             ++b) {
            int vals[4];
            vals[0] = dtnWmMaleHeightIn(b);
            vals[1] = dtnWmMaleLightLb(b);
            vals[2] = dtnWmMaleMedLb(b);
            vals[3] = dtnWmMaleHvyLb(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CWm[b][c])
                    ++bad;
            }
        }
        // the female human height and weight grid - sixteen Size rows, height
        // 4-10 to 6-1 with the Size-15 cell riding sentinel, light 100 to
        // 150, medium 110 to 165, heavy 120 to 185 (folio 19)
        int CWf[16][4] = {
            {58,100,110,120},
            {59,105,115,125},
            {60,105,115,130},
            {61,110,120,130},
            {62,110,125,135},
            {63,115,125,140},
            {64,115,130,140},
            {65,120,130,145},
            {66,120,135,150},
            {67,125,140,155},
            {68,130,145,155},
            {69,130,145,160},
            {-1,135,150,165},
            {71,140,155,170},
            {72,145,160,175},
            {73,150,165,185},
            };
        int nWf[4] = {0,0,0,0};
        int eWf[4] = {1,0,0,0};
        for (int b = 0;
             b < dtnWmSizeBands();
             ++b) {
            int vals[4];
            vals[0] = dtnWmFemaleHeightIn(b);
            vals[1] = dtnWmFemaleLightLb(b);
            vals[2] = dtnWmFemaleMedLb(b);
            vals[3] = dtnWmFemaleHvyLb(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CWf[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nWf[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nWf[c] != eWf[c])
                ++bad;
        // the carrying-capacity grid - sixteen Strength rows, the human 1.0
        // to 3.0, the dwarf 1.5 to 3.5 with the Strength-16 cell riding
        // sentinel, the hobbit 2.0 to 4.0, all in tenths of body weight, the
        // elf mirroring the human (folio 20)
        int CWc[16][3] = {
            {10,15,20},
            {12,17,22},
            {13,18,23},
            {14,19,24},
            {16,20,26},
            {17,22,27},
            {18,23,28},
            {20,25,30},
            {20,25,30},
            {22,27,32},
            {23,28,33},
            {24,29,34},
            {26,31,36},
            {27,-1,37},
            {28,33,38},
            {30,35,40},
            };
        int nWc[3] = {0,0,0};
        int eWc[3] = {0,1,0};
        for (int b = 0;
             b < dtnWmCarryBands();
             ++b) {
            int vals[3];
            vals[0] = dtnWmCarryHuman(b);
            vals[1] = dtnWmCarryDwarf(b);
            vals[2] = dtnWmCarryHobbit(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CWc[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nWc[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nWc[c] != eWc[c])
                ++bad;
        // the dtnWmBuildBand band-for boundaries
    if (dtnWmBuildBand(0) != 0
            || dtnWmBuildBand(1) != 0
            || dtnWmBuildBand(5) != 1
            || dtnWmBuildBand(2) != 1
            || dtnWmBuildBand(6) != 2
        )
            ++bad;
        // the dtnWmEyesBand band-for boundaries
    if (dtnWmEyesBand(6) != 0
            || dtnWmEyesBand(7) != 0
            || dtnWmEyesBand(13) != 1
            || dtnWmEyesBand(8) != 1
            || dtnWmEyesBand(17) != 2
            || dtnWmEyesBand(14) != 2
            || dtnWmEyesBand(19) != 3
            || dtnWmEyesBand(18) != 3
            || dtnWmEyesBand(20) != 4
        )
            ++bad;
        // the dtnWmHairBand band-for boundaries
    if (dtnWmHairBand(7) != 0
            || dtnWmHairBand(8) != 0
            || dtnWmHairBand(10) != 1
            || dtnWmHairBand(9) != 1
            || dtnWmHairBand(16) != 2
            || dtnWmHairBand(11) != 2
            || dtnWmHairBand(17) != 3
            || dtnWmHairBand(17) != 3
            || dtnWmHairBand(19) != 4
            || dtnWmHairBand(18) != 4
            || dtnWmHairBand(20) != 5
        )
            ++bad;
        // the dtnWmSkinBand band-for boundaries
    if (dtnWmSkinBand(2) != 0
            || dtnWmSkinBand(3) != 0
            || dtnWmSkinBand(6) != 1
            || dtnWmSkinBand(4) != 1
            || dtnWmSkinBand(11) != 2
            || dtnWmSkinBand(7) != 2
            || dtnWmSkinBand(14) != 3
            || dtnWmSkinBand(12) != 3
            || dtnWmSkinBand(16) != 4
            || dtnWmSkinBand(15) != 4
            || dtnWmSkinBand(18) != 5
            || dtnWmSkinBand(17) != 5
            || dtnWmSkinBand(19) != 6
        )
            ++bad;
        // the dtnWmVoiceBand band-for boundaries
    if (dtnWmVoiceBand(0) != 0
            || dtnWmVoiceBand(1) != 0
            || dtnWmVoiceBand(3) != 1
            || dtnWmVoiceBand(2) != 1
            || dtnWmVoiceBand(4) != 2
        )
            ++bad;
        // the dtnWmHandednessBand band-for boundaries
    if (dtnWmHandednessBand(1) != 0
            || dtnWmHandednessBand(2) != 0
            || dtnWmHandednessBand(4) != 1
            || dtnWmHandednessBand(3) != 1
            || dtnWmHandednessBand(5) != 2
        )
            ++bad;
        // the dtnWmExpressionBand band-for boundaries
    if (dtnWmExpressionBand(1) != 0
            || dtnWmExpressionBand(2) != 0
            || dtnWmExpressionBand(3) != 1
            || dtnWmExpressionBand(3) != 1
            || dtnWmExpressionBand(6) != 2
            || dtnWmExpressionBand(4) != 2
            || dtnWmExpressionBand(8) != 3
            || dtnWmExpressionBand(7) != 3
            || dtnWmExpressionBand(9) != 4
            || dtnWmExpressionBand(9) != 4
            || dtnWmExpressionBand(10) != 5
            || dtnWmExpressionBand(10) != 5
            || dtnWmExpressionBand(11) != 6
            || dtnWmExpressionBand(11) != 6
            || dtnWmExpressionBand(12) != 7
            || dtnWmExpressionBand(12) != 7
            || dtnWmExpressionBand(13) != 8
            || dtnWmExpressionBand(13) != 8
            || dtnWmExpressionBand(14) != 9
            || dtnWmExpressionBand(14) != 9
            || dtnWmExpressionBand(16) != 10
            || dtnWmExpressionBand(15) != 10
            || dtnWmExpressionBand(18) != 11
            || dtnWmExpressionBand(17) != 11
            || dtnWmExpressionBand(19) != 12
            || dtnWmExpressionBand(19) != 12
            || dtnWmExpressionBand(20) != 13
        )
            ++bad;
        // the dtnWmHairLengthMaleBand band-for boundaries
    if (dtnWmHairLengthMaleBand(4) != 0
            || dtnWmHairLengthMaleBand(5) != 0
            || dtnWmHairLengthMaleBand(9) != 1
            || dtnWmHairLengthMaleBand(6) != 1
            || dtnWmHairLengthMaleBand(10) != 2
        )
            ++bad;
        // the dtnWmHairLengthFemaleBand band-for boundaries
    if (dtnWmHairLengthFemaleBand(1) != 0
            || dtnWmHairLengthFemaleBand(2) != 0
            || dtnWmHairLengthFemaleBand(7) != 1
            || dtnWmHairLengthFemaleBand(3) != 1
            || dtnWmHairLengthFemaleBand(8) != 2
        )
            ++bad;
        // the weights and measures - the pound at 10 GP, leather 15, chain
        // 30, plate 60 percent of body mass (folio 19)
    if (dtnWmPoundGp() != 10
            || dtnWmLeatherPct() != 15
            || dtnWmChainPct() != 30
            || dtnWmPlatePct() != 60
        )
            ++bad;
        // the Size bonuses at 16 and up, the penalties at 5 and down, the
        // female +2 Con and +1 Dex (folio 19)
    if (dtnWmSizeBonusMin() != 16
            || dtnWmSizePenaltyMax() != 5
            || dtnWmSizeHpMod() != 1
            || dtnWmFemaleConBonus() != 2
            || dtnWmFemaleDexBonus() != 1
        )
            ++bad;
        // the carrying speed ladder - 3 at maximum, 6 at two-thirds, 9 at
        // one-third, 12 at the lightest fraction (folio 20)
    if (dtnWmSpeedFull() != 3
            || dtnWmSpeedTwoThirds() != 6
            || dtnWmSpeedOneThird() != 9
            || dtnWmSpeedLightest() != 12
        )
            ++bad;
        // the Build band - light at 1, normal 2-5, heavy at 6 - and the
        // handedness band - ambidextrous at 2, right at 5-12 (folios 19, 21)
    if (dtnWmBuildBand(1) != 0
            || dtnWmBuildBand(2) != 1
            || dtnWmBuildBand(6) != 2
            || dtnWmHandednessBand(2) != 0
            || dtnWmHandednessBand(5) != 2
        )
            ++bad;
        // the appearance bands - blue eyes from 8, golden at 20, oriental
        // complexion at 19-20, amused at 20 (folios 20-21)
    if (dtnWmEyesBand(7) != 0
            || dtnWmEyesBand(8) != 1
            || dtnWmEyesBand(20) != 4
            || dtnWmSkinBand(19) != 6
            || dtnWmExpressionBand(20) != 13
        )
            ++bad;
        // the Holsinger chances - the double-level sacrifice total, the 50/50
        // neutral notice, the 60/40 sacrilege split and the 50% temple-rite
        // kill (folios 20-21)
    if (dtnHolsSacrificeTotalFactor() != 2
            || dtnHolsNeutralSacrificePct() != 50
            || dtnHolsGoodSacrilegeRightPct() != 60
            || dtnHolsWrongGodsPct() != 40
            || dtnHolsTempleRiteKillPct() != 50
        )
            ++bad;
        // the ritual pins - the castle at the 7th level, the tree at 1 hit
        // die, the mistletoe at 10, the tree at ten feet (folios 20-21)
    if (dtnHolsCastleLevel() != 7
            || dtnHolsTreeHD() != 1
            || dtnHolsMistletoeHD() != 10
            || dtnHolsTreeMinFt() != 10
        )
            ++bad;
        // the Nappo dig - three facets and fifteen levels, the
        // 200-feet-to-the-inch scale, 120 years of life, 275 years dead
        // (folios 12-14)
    if (dtnGilNappoLevels() != 15
            || dtnGilNappoFacets() != 3
            || dtnGilScaleFtPerInch() != 200
            || dtnGilNappoLifespanYears() != 120
            || dtnGilNappoDeadYears() != 275
        )
            ++bad;
        // the male grid - 5-1 at Size 3 to 6-4 at 18, the Size-4 medium cell
        // as scanned at 185, the heavy at 215 (folio 19)
    if (dtnWmMaleHeightIn(0) != 61
            || dtnWmMaleHeightIn(15) != 76
            || dtnWmMaleMedLb(1) != 185
            || dtnWmMaleHvyLb(15) != 215
        )
            ++bad;
        // the female grid - 4-10 at Size 3 to 6-1 at 18, the Size-15 height
        // riding sentinel, the heavy at 185 (folio 19)
    if (dtnWmFemaleHeightIn(0) != 58
            || dtnWmFemaleHeightIn(12) != -1
            || dtnWmFemaleMedLb(15) != 165
            || dtnWmFemaleHvyLb(15) != 185
        )
            ++bad;
        // the carrying grid - human 1.0 to 3.0, dwarf 1.5 at Strength 3, the
        // Strength-16 dwarf cell riding sentinel, hobbit 4.0 at 18, all in
        // tenths (folio 20)
    if (dtnWmCarryHuman(0) != 10
            || dtnWmCarryHuman(15) != 30
            || dtnWmCarryDwarf(0) != 15
            || dtnWmCarryDwarf(13) != -1
            || dtnWmCarryHobbit(15) != 40
        )
            ++bad;
        // the band census - sixteen Size rows per grid, sixteen carrying
        // Strength rows (folios 19-20)
    if (dtnWmSizeBands() != 16
            || dtnWmCarryBands() != 16
        )
            ++bad;
        // the appearance pins - white hair at 17, gray at 18-19, the low
        // voice at 4, the long male hair at 10 (folios 20-21)
    if (dtnWmHairBand(17) != 3
            || dtnWmHairBand(18) != 4
            || dtnWmVoiceBand(4) != 2
            || dtnWmHairLengthMaleBand(10) != 2
        )
            ++bad;
        printf("R915 issue-10 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
