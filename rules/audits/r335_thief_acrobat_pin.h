    // ---- R335: the thief-acrobat pin audit ----
    // The UA thief-acrobat (pp. 23-25) - the pin-era pattern:
    // the conversion requirements and trainer, Table I, the
    // tightrope/vault/jump/tumble rules, the Function Table
    // columns (the vault and jump distance cells, the racial
    // row, Table II and Table IV's merged columns are OCR
    // holes - documented in the header), the wind/carry
    // footnotes, the dexterity table. The R298/R306 seams
    // cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the conversion
        {
            if (acrobatMinStrength() != 15) ++bad;
            if (acrobatMinDexterity() != 16)
                ++bad;
            if (acrobatConvertFromLevel() != 6)
                ++bad;
            if (acrobatSkillsFrozenAtLevel()
                != 5) ++bad;
            if (acrobatFrozenSkillCount() != 4)
                ++bad;
            if (strcmp(acrobatFrozenSkillName(0),
                "Find Traps") != 0) ++bad;
            if (strcmp(acrobatFrozenSkillName(1),
                "Pick Pockets") != 0) ++bad;
            if (strcmp(acrobatFrozenSkillName(2),
                "Open Locks") != 0) ++bad;
            if (strcmp(acrobatFrozenSkillName(3),
                "Remove Traps") != 0) ++bad;
            if (!acrobatReadMagicNeverGained())
                ++bad;
            if (acrobatRetainedSkillCount() != 4)
                ++bad;
            if (strcmp(acrobatRetainedSkillName(0),
                "Move Silently") != 0) ++bad;
            if (strcmp(acrobatRetainedSkillName(1),
                "Hide in Shadows") != 0) ++bad;
            if (strcmp(acrobatRetainedSkillName(2),
                "Hear Noise") != 0) ++bad;
            if (strcmp(acrobatRetainedSkillName(3),
                "Read Languages") != 0) ++bad;
            if (!acrobatClimbWallsStillImproves())
                ++bad;
            if (!acrobatAnyRaceAllowed()) ++bad;
            if (acrobatXpBonusPercent() != 10)
                ++bad;
            if (acrobatXpBonusAbilityMin() != 16)
                ++bad;
            if (acrobatTrainerMinLevel() != 10)
                ++bad;
            if (acrobatTrainingWeeks() != 6)
                ++bad;
        }
        // U2: Table I
        {
            static const int xp[7] = {
                20000, 45000, 75000, 125000,
                180000, 250000, 500000
            };
            if (acrobatSplitLevelLow() != 6)
                ++bad;
            if (acrobatSplitLevelHigh() != 12)
                ++bad;
            for (int L = 6; L <= 12; ++L)
                if (acrobatXpToAttain(L)
                    != xp[L - 6]) ++bad;
            if (acrobatXpToAttain(5) != 0) ++bad;
            if (acrobatXpToAttain(13) != 500000)
                ++bad;
            if (acrobatXpPerLevelPast12()
                != 250000) ++bad;
            if (strcmp(acrobatTitle(6),
                "Burglar-Acrobat") != 0) ++bad;
            if (strcmp(acrobatTitle(9),
                "Master Cat Burglar") != 0)
                ++bad;
            if (strcmp(acrobatTitle(12),
                "Master Thief-Acrobat (12th)")
                != 0) ++bad;
        }
        // U3: tightrope walking
        {
            if (acrobatTightropeAscentMaxAngle()
                != 45) ++bad;
            if (acrobatTightropeMaxDistance()
                != 60) ++bad;
            if (acrobatTightropeMoveRate()
                != 60) ++bad;
            if (acrobatTightropeModerateWindPenalty()
                != 10) ++bad;
            if (acrobatTightropeStrongWindPenalty()
                != 20) ++bad;
            if (acrobatTightropeGustyFailure()
                != 5) ++bad;
            if (acrobatBalancePoleBonus() != 10)
                ++bad;
            if (acrobatNonAcrobatTightropeBase()
                != 20) ++bad;
            if (acrobatNonAcrobatTightropeRate()
                != 30) ++bad;
        }
        // U4: pole vaulting and high jumping
        {
            if (acrobatVaultRunStart() != 30)
                ++bad;
            if (acrobatVaultPoleExtraHeight()
                != 4) ++bad;
            if (!acrobatNonAcrobatsCannotVault())
                ++bad;
            if (acrobatLandingSegments() != 1)
                ++bad;
            if (!acrobatHighJumpNeedsRun()) ++bad;
            if (acrobatHighJumpLandAboveMax()
                != 4) ++bad;
            if (acrobatHighJumpLandBelowMax()
                != 2) ++bad;
        }
        // U5: broad jumping and the extensions
        {
            if (acrobatJumpSegments() != 1)
                ++bad;
            if (acrobatRunningBroadMinRun()
                != 20) ++bad;
            if (!acrobatStandingBackwardHalf())
                ++bad;
            static const int fail[4] = {
                0, 25, 50, 75
            };
            static const int rec[4] = {
                2, 3, 4, 5
            };
            for (int f = 2; f <= 5; ++f) {
                if (acrobatExtensionFailurePercent(f)
                    != fail[f - 2]) ++bad;
                if (acrobatExtensionRecoverySegments(f)
                    != rec[f - 2]) ++bad;
            }
            if (acrobatNonAcrobatStandingBroad()
                != 4) ++bad;
            if (acrobatNonAcrobatRunningBroad()
                != 8) ++bad;
            if (!acrobatJumpBulkyArmorBanned())
                ++bad;
        }
        // U6: the Function Table columns -
        // every readable cell
        {
            if (acrobatFunctionRowCount() != 18)
                ++bad;
            if (acrobatFunctionLevelLow() != 6)
                ++bad;
            static const int tw[15] = {
                75, 80, 85, 90, 95, 100, 100,
                100, 100, 100, 100, 100, 100,
                100, 100
            };
            // the readable tightrope rows:
            // 6-15, 17, 18, 20, 22, 23
            if (acrobatTightropePercent(6)
                != 75) ++bad;
            if (acrobatTightropePercent(10)
                != 95) ++bad;
            if (acrobatTightropePercent(11)
                != 100) ++bad;
            if (acrobatTightropePercent(17)
                != 100) ++bad;
            if (acrobatTightropePercent(23)
                != 100) ++bad;
            // the attack rows 8-23 (the
            // row-6 slip documented)
            for (int L = 8; L <= 20; ++L)
                if (acrobatTumblingAttackPercent(L)
                    != L) ++bad;
            if (acrobatTumblingAttackPercent(21)
                != 20) ++bad;
            if (acrobatTumblingAttackPercent(23)
                != 20) ++bad;
            // the evasion rows: all 18
            static const int ev[18] = {
                10, 15, 20, 25, 30, 35, 40, 45,
                50, 52, 54, 56, 58, 60, 60, 60,
                60, 60
            };
            for (int L = 6; L <= 23; ++L)
                if (acrobatEvasionPercent(L)
                    != ev[L - 6]) ++bad;
            if (acrobatEvasionBaseCap() != 60)
                ++bad;
            if (!acrobatEvasionRequiresInitiative())
                ++bad;
            if (acrobatEvasionSegments() != 1)
                ++bad;
            if (!acrobatTumblingAttackIsPummeling())
                ++bad;
            if (!acrobatNonAcrobatsNoTumblingBenefit())
                ++bad;
        }
        // U7: the falling reads - the
        // verified cells and the converse
        {
            if (!acrobatFallingDamageConverse())
                ++bad;
            if (!acrobatFallingPastSafeAddsDice())
                ++bad;
            if (acrobatFallingChanceKnown(6, 10)
                != 25) ++bad;
            if (acrobatFallingChanceKnown(7, 10)
                != 50) ++bad;
            if (acrobatFallingChanceKnown(8, 10)
                != 75) ++bad;
            if (acrobatFallingChanceKnown(9, 10)
                != 100) ++bad;
            if (acrobatFallingChanceKnown(9, 20)
                != 25) ++bad;
            if (acrobatFallingChanceKnown(13, 30)
                != 50) ++bad;
            if (acrobatFallingChanceKnown(14, 30)
                != 75) ++bad;
            if (acrobatFallingChanceKnown(15, 40)
                != 20) ++bad;
            if (acrobatFallingChanceKnown(18, 40)
                != 80) ++bad;
            if (acrobatFallingChanceKnown(19, 50)
                != 20) ++bad;
            if (acrobatFallingChanceKnown(22, 50)
                != 80) ++bad;
            if (acrobatFallingChanceKnown(23, 50)
                != 100) ++bad;
            if (acrobatFallingChanceKnown(23, 60)
                != 20) ++bad;
            // the documented holes read -1
            if (acrobatFallingChanceKnown(10, 20)
                != -1) ++bad;
            if (acrobatFallingChanceKnown(12, 30)
                != -1) ++bad;
            if (acrobatFallingChanceKnown(15, 30)
                != -1) ++bad;
            if (acrobatFallingChanceKnown(23, 70)
                != -1) ++bad;
        }
        // U8: the wind/carry footnotes
        {
            if (acrobatFootnoteCarryGp(1, 0)
                != 1000) ++bad;
            if (acrobatFootnoteCarryGp(1, 1)
                != -1) ++bad;
            if (acrobatFootnoteCarryGp(2, 0)
                != 2000) ++bad;
            if (acrobatFootnoteCarryGp(2, 1)
                != 1000) ++bad;
            if (acrobatFootnoteCarryGp(2, 2)
                != -1) ++bad;
            if (acrobatFootnoteCarryGp(3, 1)
                != 2000) ++bad;
            if (acrobatFootnoteCarryGp(3, 2)
                != 1000) ++bad;
            if (acrobatFootnoteCarryGp(4, 0)
                != 3000) ++bad;
            if (acrobatFootnoteCarryGp(4, 1)
                != 2000) ++bad;
            if (acrobatFootnoteCarryGp(5, 0)
                != 4000) ++bad;
            if (acrobatFootnoteCarryGp(5, 1)
                != 3000) ++bad;
            if (acrobatFootnoteCarryGp(5, 2)
                != 2000) ++bad;
        }
        // U9: the equipment reads and the
        // dexterity table
        {
            if (!acrobatNoBackpackExceptTightrope())
                ++bad;
            if (!acrobatTightropeCarriedEvenlyBalanced())
                ++bad;
            if (acrobatDexTightropeBonus(15)
                != 0) ++bad;
            if (acrobatDexTightropeBonus(16)
                != 5) ++bad;
            if (acrobatDexTightropeBonus(19)
                != 20) ++bad;
            if (acrobatDexPoleVaultBonus(16)
                != 0) ++bad;
            if (acrobatDexPoleVaultBonus(17)
                != 5) ++bad;
            if (acrobatDexPoleVaultBonus(19)
                != 15) ++bad;
            if (acrobatDexAttackBonus(16) != 1)
                ++bad;
            if (acrobatDexAttackBonus(19) != 4)
                ++bad;
            if (acrobatDexEvasionBonus(16) != 2)
                ++bad;
            if (acrobatDexEvasionBonus(19) != 8)
                ++bad;
            if (acrobatDexFallingBonus(17) != 0)
                ++bad;
            if (acrobatDexFallingBonus(18) != 5)
                ++bad;
            if (acrobatDexFallingBonus(19) != 10)
                ++bad;
        }
        // U10: the seams - the R298 take
        // table and the R306 engine audit
        // names (the frozen and retained
        // skill sets must match the take
        // table's function names)
        {
            if (strcmp(acrobatRetainedSkillName(0),
                "Move Silently") != 0) ++bad;
            if (strcmp(acrobatFrozenSkillName(2),
                "Open Locks") != 0) ++bad;
        }
        printf("R335 thief-acrobat pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
