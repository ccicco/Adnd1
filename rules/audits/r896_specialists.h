    // ---- R896 specialists audit ----
    // THE SPECIALISTS ROUND - round B of the issue-3 walk. Hettlestad's
    // Healer: the prerequisites (15 each in intelligence, wisdom and
    // dexterity, lawful or neutral only, a chaotic becoming a mere fighter),
    // no armor or shield, any weapons and magical items, the books that only
    // hurt; the level-unlock abilities - detect molds and slimes at 40 feet
    // at 4th, determine potions at 8th, read magical and clerical scrolls at
    // 12th, four 1st-level magic-user spells at 16th, four 2nd-level at 20th;
    // the twenty-five-level ladder (Apprentice through Doctor 25th) with the
    // 8-sided hit dice split from the printed 10+N forms and the seven-column
    // spell-progression grid, the dashes converted to zeros; the racial caps
    // - Medic 10th for Dwarves, Doctor 14th for Hobbit, Half-Elf and Elf; the
    // spell list deltas - Detect Poison and Disease at 30 feet, Detect Phase
    // for 6 turns, Cure Blindness and Lycanthropy, Energy, Wake Spell, Cure
    // Insanity and Paralysis, Longevity at 10 game-years, Teleport and Size
    // Control, Sterilize to 5 hit die, Neutralize Gas, Remove Charm at 3
    // inches, Cure Deafness, Improved Cure Serious Wounds at 4d6+1 per die
    // for 8 to 24, Talk to Plants, Speak with Animals and Monsters. Mumper's
    // Scribe: the curse on magical writing (permanent, incurable insanity for
    // any but the counter-spell-knowing Scribe, Remove Curse
    // notwithstanding), the two vocations, the 10-percent-a-week cumulative
    // find chance, the specialist hire rate of 100-600 gold a week and the
    // 1000-5000 gold a month fee, the six-grade ability ladder with the
    // mistake percents within and above abilities and the above-abilities
    // insanity, the alignment bands by vocation pinned as scanned with the
    // sentinel for the clerical missing neutral band, the 100-percent mistake
    // of the insane Scribe detectable only by ESP, the alignment mismatch
    // multipliers of two and three, the 5-spells-by-2-points growth, the
    // 5-percent cumulative monthly leave chance, and the uncorrectable
    // mistakes at referee discretion. HONEST BOUNDARIES: the alignment block
    // and the mistake pairs ride as scanned, no figure pixels to check; both
    // specialists ride the variant layer, NPC-recommended per the editor's
    // caution.
    {
        using namespace rules;
        int bad = 0;
    if (sprHealerLevels() != 25
            || sprHealStatMin() != 15
            || sprHealHitDieSides() != 8
            || sprHealDwarfMaxLevel() != 10
            || sprHealDemiHumanMaxLevel() != 14
            || sprHealDetectRangeFeet() != 40
            || sprHealDetectPoisonRangeFeet() != 30
            || sprHealDetectDiseaseRangeFeet() != 30
            || sprHealDetectPhaseTurns() != 6
            || sprHealMuSpellCount() != 4
            || sprHealMuSpellLevelOne() != 1
            || sprHealMuSpellLevelTwo() != 2
            || sprHealRemoveCharmRangeInches() != 3
            || sprHealLongevityYears() != 10
            || sprHealSterilizeHdCap() != 5
            || sprHealIcswDice() != 4
            || sprHealIcswDieSides() != 6
            || sprHealIcswBonusPerDie() != 1
            || sprHealIcswMinDamage() != 8
            || sprHealIcswMaxDamage() != 24
            || sprScribeVocations() != 2
            || sprScribeGrades() != 6
            || sprScribeFindPct() != 10
            || sprScribeLeavePct() != 5
            || sprScribeCostMinGold() != 100
            || sprScribeCostMaxGold() != 600
            || sprScribeFeeMinGold() != 1000
            || sprScribeFeeMaxGold() != 5000
            || sprScribeInsanityMistakePct() != 100
            || sprScribeAlignmentDouble() != 2
            || sprScribeAlignmentTriple() != 3
            || sprScribeGrowthSpells() != 5
            || sprScribeGrowthPoints() != 2
            || !sprHealerLawfulNeutralOnly()
            || !sprHealerNoArmorShield()
            || !sprHealBooksOnlyHurt()
            || !sprScribeCurseOnWriting()
            || !sprScribeInsanityEspOnly()
            || !sprScribeMistakesUncorrectable()
            || !sprScribeFreelanceSearch()
        )
            ++bad;
        // the Healer ladder - Apprentice, Frosh, Sophomore, Junior, Senior,
        // Intern, Resident, Senior Resident, Practitioner, Medic, then Doctor
        // 11th through Doctor 25th, with the spell-progression grid (folios
        // 22-23)
        int CSprHea[25][10] = {
            {0,1,0,1,0,0,0,0,0,0},
            {5000,2,0,1,0,0,0,0,0,0},
            {10000,3,0,1,1,1,0,0,0,0},
            {15000,4,0,2,1,1,1,0,0,0},
            {25000,5,0,2,2,1,1,1,0,0},
            {50000,6,0,2,2,2,1,1,1,0},
            {100000,7,0,3,2,2,2,1,1,1},
            {200000,8,0,3,3,2,2,2,1,1},
            {300000,9,0,3,3,3,2,2,2,1},
            {400000,10,0,4,3,3,3,2,2,2},
            {500000,10,1,4,4,3,3,3,2,2},
            {600000,10,2,4,4,4,3,3,3,2},
            {700000,10,3,5,4,4,4,3,3,3},
            {800000,10,4,5,5,4,4,4,3,3},
            {900000,10,5,5,5,5,4,4,4,3},
            {1000000,10,6,6,5,5,5,4,4,4},
            {1100000,10,7,6,6,5,5,5,4,4},
            {1200000,10,8,6,6,6,5,5,5,4},
            {1300000,10,9,7,6,6,6,5,5,5},
            {1400000,10,10,7,7,6,6,6,5,5},
            {1500000,10,11,7,7,7,6,6,6,5},
            {1600000,10,12,8,7,7,7,6,6,6},
            {1700000,10,13,8,8,7,7,7,6,6},
            {1800000,10,14,8,8,8,7,7,7,6},
            {1900000,10,15,9,8,8,8,7,7,7},
            };
        for (int b = 0;
             b < sprHealerLevels();
             ++b) {
            int vals[10];
            vals[0] = sprHealXp(b);
            vals[1] = sprHealHitBase(b);
            vals[2] = sprHealHitBonus(b);
            vals[3] = sprHealSp1(b);
            vals[4] = sprHealSp2(b);
            vals[5] = sprHealSp3(b);
            vals[6] = sprHealSp4(b);
            vals[7] = sprHealSp5(b);
            vals[8] = sprHealSp6(b);
            vals[9] = sprHealSp7(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CSprHea[b][c])
                    ++bad;
            }
        }
        // the Scribe ability ladder on the percentile dice - 01-25, 26-50,
        // 51-75, 76-85, 86-95, 96-00; the mistake pair reads as
        // within-abilities over above-abilities, pinned as scanned (folio 23)
        int CSprScr[6][4] = {
            {3,25,75,35},
            {5,15,45,25},
            {6,10,30,20},
            {7,5,15,15},
            {8,2,6,10},
            {9,1,3,5},
            };
        for (int b = 0;
             b < sprScribeGrades();
             ++b) {
            int vals[4];
            vals[0] = sprScrSpellMax(b);
            vals[1] = sprScrMistakeNormal(b);
            vals[2] = sprScrMistakeAbove(b);
            vals[3] = sprScrInsanityAbove(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CSprScr[b][c])
                    ++bad;
            }
        }
        // the Scribe alignment bands by vocation - Magical and Clerical; the
        // alignment block garbles in OCR, pinned as scanned with the sentinel
        // marking the clerical missing neutral band (folio 23)
        int CSprAlg[2][3] = {
            {70,90,100},
            {80,9,100},
            };
        for (int b = 0;
             b < sprScribeVocations();
             ++b) {
            int vals[3];
            vals[0] = sprScrLawfulMax(b);
            vals[1] = sprScrNeutralMax(b);
            vals[2] = sprScrChaoticMax(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CSprAlg[b][c])
                    ++bad;
            }
        }
        // the Healer prerequisites - 15 in each of three stats, lawful or
        // neutral only, no armor or shield (folio 22)
    if (sprHealStatMin() != 15
            || sprHealerLawfulNeutralOnly() != 1
            || sprHealerNoArmorShield() != 1
        )
            ++bad;
        // the ladder bookends - Apprentice 0, Medic 400000, Doctor 25th
        // 1900000 (folio 22)
    if (sprHealXp(0) != 0
            || sprHealXp(9) != 400000
            || sprHealXp(24) != 1900000
        )
            ++bad;
        // the hit-dice split - 1 at Apprentice, 10+1 at Doctor 11th, 10+15 at
        // 25th (folio 22)
    if (sprHealHitBase(0) != 1
            || sprHealHitBonus(10) != 1
            || sprHealHitBonus(24) != 15
        )
            ++bad;
        // the 8-sided hit dice, base 10 flat from Medic on (folio 22)
    if (sprHealHitDieSides() != 8
            || sprHealHitBase(9) != 10
        )
            ++bad;
        // the first-level spell column - 1 at Apprentice, 7 at Doctor 20th, 9
        // at 25th (folio 22)
    if (sprHealSp1(0) != 1
            || sprHealSp1(19) != 7
            || sprHealSp1(24) != 9
        )
            ++bad;
        // the seventh-level spell column - 1 at Resident, 3 at Doctor 13th, 7
        // at 25th (folio 22)
    if (sprHealSp7(6) != 1
            || sprHealSp7(12) != 3
            || sprHealSp7(24) != 7
        )
            ++bad;
        // the third at Sophomore, the fourth at Senior, the fifth at Intern -
        // each opens with 1 (folio 22)
    if (sprHealSp3(2) != 1
            || sprHealSp4(4) != 1
            || sprHealSp5(5) != 1
        )
            ++bad;
        // the grid midpoints - Doctor 14th five second-level, Doctor 21st six
        // sixth-level and seven fourth-level (folio 22)
    if (sprHealSp2(13) != 5
            || sprHealSp6(20) != 6
            || sprHealSp4(21) != 7
        )
            ++bad;
        // the Resident row - 3,2,2,2,1,1,1 (folio 22)
    if (sprHealSp1(6) != 3
            || sprHealSp2(6) != 2
            || sprHealSp3(6) != 2
            || sprHealSp4(6) != 2
        )
            ++bad;
        // the racial caps - Medic 10th for the Dwarf, Doctor 14th for Hobbit,
        // Half-Elf or Elf (folio 22)
    if (sprHealDwarfMaxLevel() != 10
            || sprHealDemiHumanMaxLevel() != 14
        )
            ++bad;
        // the 4th-level mold and slime detection at 40 feet; the books only
        // hurt (folio 22)
    if (sprHealDetectRangeFeet() != 40
            || sprHealBooksOnlyHurt() != 1
        )
            ++bad;
        // the detection spells - poison and disease at 30 feet, phase for 6
        // turns (folio 23)
    if (sprHealDetectPoisonRangeFeet() != 30
            || sprHealDetectDiseaseRangeFeet() != 30
            || sprHealDetectPhaseTurns() != 6
        )
            ++bad;
        // the 16th-level unlock - four 1st-level MU spells, then four 2nd at
        // 20th (folio 22)
    if (sprHealMuSpellCount() != 4
            || sprHealMuSpellLevelOne() != 1
            || sprHealMuSpellLevelTwo() != 2
        )
            ++bad;
        // the Improved Cure Serious Wounds - four 6-siders plus 1 per die
        // (folio 23)
    if (sprHealIcswDice() != 4
            || sprHealIcswDieSides() != 6
            || sprHealIcswBonusPerDie() != 1
        )
            ++bad;
        // the healing range - 8 to 24 hit points (folio 23)
    if (sprHealIcswMinDamage() != 8
            || sprHealIcswMaxDamage() != 24
        )
            ++bad;
        // Longevity takes 10 game-years, Sterilize caps at 5 hit die, Remove
        // Charm at 3 inches (folio 23)
    if (sprHealLongevityYears() != 10
            || sprHealSterilizeHdCap() != 5
            || sprHealRemoveCharmRangeInches() != 3
        )
            ++bad;
        // the two vocations, the free-lance search at 10 percent a week,
        // cumulative (folio 23)
    if (sprScribeVocations() != 2
            || sprScribeFreelanceSearch() != 1
            || sprScribeFindPct() != 10
        )
            ++bad;
        // the curse on magical writing and the ESP-only insanity detection
        // (folios 23, 25)
    if (sprScribeCurseOnWriting() != 1
            || sprScribeInsanityEspOnly() != 1
        )
            ++bad;
        // the grade ceilings - 1-3 spells, 1-6 at 51-75, 1-9 at 96-00 (folio
        // 23)
    if (sprScrSpellMax(0) != 3
            || sprScrSpellMax(2) != 6
            || sprScrSpellMax(5) != 9
        )
            ++bad;
        // the within-abilities mistake percent - 25 at the bottom grade, 1 at
        // the top (folio 23)
    if (sprScrMistakeNormal(0) != 25
            || sprScrMistakeNormal(5) != 1
        )
            ++bad;
        // the above-abilities mistake percent - 75 down to 3 (folio 23)
    if (sprScrMistakeAbove(0) != 75
            || sprScrMistakeAbove(3) != 15
            || sprScrMistakeAbove(5) != 3
        )
            ++bad;
        // the above-abilities insanity percent - 35 down to 5 (folio 23)
    if (sprScrInsanityAbove(0) != 35
            || sprScrInsanityAbove(4) != 10
            || sprScrInsanityAbove(5) != 5
        )
            ++bad;
        // the magical vocation bands - lawful 01-70, neutral 71-90, chaotic
        // 91-00 (folio 23)
    if (sprScrLawfulMax(0) != 70
            || sprScrNeutralMax(0) != 90
            || sprScrChaoticMax(0) != 100
        )
            ++bad;
        // the clerical vocation - lawful 01-80, chaotic 81-00, no neutral
        // band pinned as the sentinel (folio 23)
    if (sprScrLawfulMax(1) != 80
            || sprScrChaoticMax(1) != 100
            || sprScrNeutralMax(1) != 9
        )
            ++bad;
        // the insane Scribe mistakes 100 percent of the time, and mistakes
        // may not be corrected (folio 25)
    if (sprScribeInsanityMistakePct() != 100
            || sprScribeMistakesUncorrectable() != 1
        )
            ++bad;
        // the alignment mismatch multipliers - doubles
        // lawful-chaotic/neutral, triples lawful/chaotic (folio 25)
    if (sprScribeAlignmentDouble() != 2
            || sprScribeAlignmentTriple() != 3
        )
            ++bad;
        // every 5 spells transcribed raises the ability by 2 (folio 25)
    if (sprScribeGrowthSpells() != 5
            || sprScribeGrowthPoints() != 2
        )
            ++bad;
        // the 5 percent cumulative monthly chance the Scribe leaves (folio
        // 25)
    if (sprScribeLeavePct() != 5
        )
            ++bad;
        // the specialist hire rate - 100 to 600 gold pieces a week (folio 23)
    if (sprScribeCostMinGold() != 100
            || sprScribeCostMaxGold() != 600
        )
            ++bad;
        // the Scribe fee - 1000 to 5000 gold pieces a month (folio 25)
    if (sprScribeFeeMinGold() != 1000
            || sprScribeFeeMaxGold() != 5000
        )
            ++bad;
        // the grid deep end - Doctor 25th seven fifth-level, Doctor 24th
        // seven sixth-level, Doctor 23rd eight second-level (folio 22)
    if (sprHealSp5(24) != 7
            || sprHealSp6(23) != 7
            || sprHealSp2(22) != 8
        )
            ++bad;
        printf("R896 specialists audit: bad %d\n", bad);
        if (bad) return 1;
    }
