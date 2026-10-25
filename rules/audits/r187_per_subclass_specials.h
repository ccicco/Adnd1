    // ---- R187: the per-subclass specials audit ----
    // Every fee cell, the disguise ladder, backstab,
    // the skill sharing, the monk specials A-K, the
    // stun/kill rules, the ranger numbers, the
    // paladin turn ladder.
    {
        int bad = 0;
        // the fee table, cell by cell (15 x 8)
        static const int kFees[15][8] = {
            { 50, 100, 150, 200, 250, 0, 0, 0 },
            { 60, 120, 175, 250, 300, 350, 0, 0 },
            { 75, 150, 225, 300, 400, 500, 0, 0 },
            { 100, 200, 300, 450, 600, 750, 1000, 0 },
            { 150, 300, 450, 700, 900, 1100, 1300, 1500 },
            { 250, 500, 750, 1000, 1300, 1600, 2000, 2500 },
            { 400, 800, 1200, 1600, 2000, 2500, 3500, 4500 },
            { 600, 1200, 1800, 2400, 3000, 3750, 5000, 7500 },
            { 850, 1700, 2600, 3500, 4400, 6000, 7500, 10000 },
            { 1200, 2400, 3600, 4800, 6000, 8000, 10000, 15000 },
            { 1700, 3500, 5100, 7000, 9000, 12000, 15000, 20000 },
            { 2500, 5000, 7500, 10000, 13000, 17500, 20000, 25000 },
            { 3500, 7000, 11000, 15000, 19000, 25000, 32500, 40000 },
            { 5000, 10000, 15000, 20000, 27500, 35000, 45000, 60000 },
            { 10000, 20000, 35000, 50000, 75000, 100000, 150000, 250000 },
        };
        for (int al = 1; al <= 15; ++al)
            for (int b = 0; b < 8; ++b)
                if (rules::assassinMinimumFee(al, b)
                    != kFees[al-1][b]) ++bad;
        // the dash cells pin as 0
        if (rules::assassinMinimumFee(1, 5) != 0) ++bad;
        if (rules::assassinMinimumFee(1, 6) != 0) ++bad;
        if (rules::assassinMinimumFee(1, 7) != 0) ++bad;
        if (rules::assassinMinimumFee(4, 7) != 0) ++bad;
        // the clamps: level and band
        if (rules::assassinMinimumFee(0, 0) != 50) ++bad;
        if (rules::assassinMinimumFee(99, 7) != 250000) ++bad;
        if (rules::assassinMinimumFee(15, 99) != 250000) ++bad;
        if (rules::assassinMinimumFee(15, -5) != 10000) ++bad;
        // the victim bands
        if (rules::assassinVictimBand(0) != 0) ++bad;
        if (rules::assassinVictimBand(2) != 1) ++bad;
        if (rules::assassinVictimBand(3) != 2) ++bad;
        if (rules::assassinVictimBand(6) != 3) ++bad;
        if (rules::assassinVictimBand(9) != 4) ++bad;
        if (rules::assassinVictimBand(12) != 5) ++bad;
        if (rules::assassinVictimBand(15) != 6) ++bad;
        if (rules::assassinVictimBand(16) != 7) ++bad;
        if (rules::assassinVictimBand(99) != 7) ++bad;
        if (rules::assassinVictimBand(-5) != 0) ++bad;
        // the disguise ladder: base 2, +2 per pose,
        // max 8, then the observer adjustment
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 24) != 2) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, false, false, 24) != 4) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, false, 24) != 6) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 24) != 8) ++bad;
        // the print example: INT+WIS 20 reduces the
        // chance by 4%
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 20) != -2) ++bad;
        // INT+WIS above 30 increases by 1% per point
        if (rules::assassinDisguiseSpotPercent(
                false, false, false, 36) != 8) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 18) != 2) ++bad;
        if (rules::assassinDisguiseSpotPercent(
                true, true, true, 31) != 9) ++bad;
        // backstab: the multiplier ladder
        if (rules::backstabMultiplier(1) != 2) ++bad;
        if (rules::backstabMultiplier(4) != 2) ++bad;
        if (rules::backstabMultiplier(5) != 3) ++bad;
        if (rules::backstabMultiplier(8) != 3) ++bad;
        if (rules::backstabMultiplier(9) != 4) ++bad;
        if (rules::backstabMultiplier(12) != 4) ++bad;
        if (rules::backstabMultiplier(13) != 5) ++bad;
        if (rules::backstabMultiplier(16) != 5) ++bad;
        if (rules::backstabMultiplier(17) != 5) ++bad;
        if (rules::backstabMultiplier(0) != 2) ++bad;
        if (rules::backstabHitBonusPercent() != 20) ++bad;
        if (rules::backstabHitBonusDie() != 4) ++bad;
        // the thief-skill sharing
        if (rules::assassinThiefSkillLevel(3) != 1) ++bad;
        if (rules::assassinThiefSkillLevel(4) != 2) ++bad;
        if (rules::assassinThiefSkillLevel(15) != 13) ++bad;
        if (rules::assassinThiefSkillLevel(1) != 1) ++bad;
        if (rules::assassinThiefSkillLevel(2) != 1) ++bad;
        if (rules::assassinBackstabLevel(3) != 3) ++bad;
        if (rules::assassinBackstabLevel(15) != 15) ++bad;
        if (rules::assassinBackstabLevel(1) != 1) ++bad;
        if (rules::monkThiefSkillLevel(1) != 1) ++bad;
        if (rules::monkThiefSkillLevel(7) != 7) ++bad;
        if (rules::monkThiefSkillLevel(17) != 17) ++bad;
        if (rules::monkThiefAbilityCount() != 6) ++bad;
        if (std::string(rules::monkThiefAbilityName(0))
            != "open locks") ++bad;
        if (std::string(rules::monkThiefAbilityName(5))
            != "climb walls") ++bad;
        // the monk surprise ladder
        if (rules::monkSurprisedPercent(1) != 33) ++bad;
        if (rules::monkSurprisedPercent(2) != 32) ++bad;
        if (rules::monkSurprisedPercent(3) != 30) ++bad;
        if (rules::monkSurprisedPercent(4) != 28) ++bad;
        if (rules::monkSurprisedPercent(5) != 26) ++bad;
        if (rules::monkSurprisedPercent(13) != 10) ++bad;
        if (rules::monkSurprisedPercent(17) != 2) ++bad;
        if (rules::monkSurprisedPercent(18) != 0) ++bad;
        if (rules::monkSurprisedPercent(0) != 33) ++bad;
        // the specials ladder A-K
        if (rules::monkSpecialsCount(1) != 0) ++bad;
        if (rules::monkSpecialsCount(2) != 0) ++bad;
        if (rules::monkSpecialsCount(3) != 1) ++bad;
        if (rules::monkSpecialsCount(7) != 5) ++bad;
        if (rules::monkSpecialsCount(13) != 11) ++bad;
        if (rules::monkSpecialsCount(17) != 11) ++bad;
        if (rules::monkSpecialLetter(0) != 'A') ++bad;
        if (rules::monkSpecialLetter(10) != 'K') ++bad;
        if (rules::monkSpecialLetter(99) != 'K') ++bad;
        if (rules::monkSpecialLevel(0) != 3) ++bad;
        if (rules::monkSpecialLevel(10) != 13) ++bad;
        // the individual specials
        if (rules::monkSpeakWithAnimalsLevel() != 3) ++bad;
        if (rules::monkEspSuccessPercent(3) != 100) ++bad;
        if (rules::monkEspSuccessPercent(4) != 30) ++bad;
        if (rules::monkEspSuccessPercent(5) != 28) ++bad;
        if (rules::monkEspSuccessPercent(6) != 26) ++bad;
        if (rules::monkEspSuccessPercent(20) != 0) ++bad;
        if (rules::monkDiseaseImmuneLevel() != 5) ++bad;
        if (rules::monkCatalepsyTurns(5) != 0) ++bad;
        if (rules::monkCatalepsyTurns(6) != 12) ++bad;
        if (rules::monkCatalepsyTurns(7) != 14) ++bad;
        if (rules::monkHealBonusPerDay(6) != 0) ++bad;
        if (rules::monkHealBonusPerDay(7) != 1) ++bad;
        if (rules::monkHealBonusPerDay(8) != 2) ++bad;
        if (rules::monkHealBonusPerDay(9) != 3) ++bad;
        if (rules::monkSpeakWithPlantsLevel() != 8) ++bad;
        if (rules::monkCharmAffectPercent(8) != 100) ++bad;
        if (rules::monkCharmAffectPercent(9) != 50) ++bad;
        if (rules::monkCharmAffectPercent(10) != 45) ++bad;
        if (rules::monkCharmAffectPercent(11) != 40) ++bad;
        if (rules::monkCharmAffectPercent(19) != 0) ++bad;
        if (rules::monkMindBlastLevel() != 10) ++bad;
        if (rules::monkMindBlastEffectiveInt() != 18) ++bad;
        if (rules::monkPoisonImmuneLevel() != 11) ++bad;
        if (rules::monkGeasImmuneLevel() != 12) ++bad;
        if (rules::monkQuiveringPalmLevel() != 13) ++bad;
        if (rules::monkQuiveringPalmAttemptsPerWeek()
            != 1) ++bad;
        if (rules::monkQuiveringPalmTouchRounds() != 3) ++bad;
        if (rules::monkQuiveringPalmHpCapPercent() != 200) ++bad;
        // the stun and kill rules
        if (rules::monkStunMargin() != 5) ++bad;
        if (rules::monkStunRoundsDie() != 6) ++bad;
        // the print example: AC -1 at 7th is a
        // negative chance; a 9th-level monk vs
        // AC 5 is 7%
        if (rules::monkKillPercent(-1, 7) != -1) ++bad;
        if (rules::monkKillPercent(5, 9) != 7) ++bad;
        if (rules::monkKillPercent(5, 7) != 5) ++bad;
        if (rules::monkKillPercent(0, 10) != 3) ++bad;
        if (rules::monkKillPercent(3, 1) != 3) ++bad;
        if (rules::monkHalfDamageOnFailedSaveLevel()
            != 9) ++bad;
        // the ranger surprise numbers
        if (!rules::rangerSurpriseOnD6(1)) ++bad;
        if (!rules::rangerSurpriseOnD6(3)) ++bad;
        if (rules::rangerSurpriseOnD6(4)) ++bad;
        if (rules::rangerSurpriseOnD6(0)) ++bad;
        if (rules::rangerSurpriseOnD6(7)) ++bad;
        if (!rules::rangerSurprisedOnD6(1)) ++bad;
        if (rules::rangerSurprisedOnD6(2)) ++bad;
        if (rules::rangerSurprisedOnD6(0)) ++bad;
        // the paladin turn ladder: cleric of
        // level minus two, from 3rd
        if (rules::paladinTurnClericLevel(2) != 0) ++bad;
        if (rules::paladinTurnClericLevel(3) != 1) ++bad;
        if (rules::paladinTurnClericLevel(4) != 2) ++bad;
        if (rules::paladinTurnClericLevel(5) != 3) ++bad;
        if (rules::paladinTurnClericLevel(11) != 9) ++bad;
        if (rules::paladinTurnClericLevel(0) != 0) ++bad;
        printf("R187 per-subclass specials audit: bad %d\n", bad);
        if (bad) return 1;
    }
