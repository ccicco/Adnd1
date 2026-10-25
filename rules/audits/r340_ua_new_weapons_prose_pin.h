    // ---- R340: the UA new weapons prose pin audit ----
    // The UA DESCRIPTIONS OF NEW WEAPON TYPES (pp. 26-28)
    // - the 16 printed entries (the 14 types the gap item
    // names plus the hand-held crossbow and falchion
    // prose), every readable number pinned; the garbled
    // cells (the harpoon failure die, the hand-crossbow
    // poison sentence, the lasso severing mechanics, the
    // caltrop trigger, the khopesh leverage sentence) are
    // documented holes; the DM pp. 77-79 half is DMG
    // material absent from the UA extract - the item
    // stays open.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the roster
        {
            if (uanwCount() != 16) ++bad;
            if (strcmp(uanwName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uanwName(4),
                "Crossbow, Hand-held") != 0) ++bad;
            if (strcmp(uanwName(9), "Man Catcher")
                != 0) ++bad;
            if (strcmp(uanwName(13),
                "Sword, Falchion") != 0) ++bad;
            if (strcmp(uanwName(15), "Whip") != 0)
                ++bad;
            // the item names 14; the hand crossbow and
            // the falchion are extra prose
            if (uanwInGapItemList(4)) ++bad;
            if (uanwInGapItemList(13)) ++bad;
            int listed = 0;
            for (int i = 0; i < 16; ++i)
                if (uanwInGapItemList(i)) ++listed;
            if (listed != 14) ++bad;
        }
        // U2: the aklys, the atlatl, the blowgun
        {
            if (uanwAklysEntangleHitPct() != 5) ++bad;
            if (!uanwAklysEntangleRollOf20()) ++bad;
            if (uanwAklysThongFeet() != 10) ++bad;
            if (uanwAklysThongSeverCuttingDmg()
                != 2) ++bad;
            if (uanwAklysDisentangleRounds() != 1)
                ++bad;
            if (!uanwAtlatlJavelinDamageSame()) ++bad;
            if (!uanwBlowgunBattlefieldImpossible())
                ++bad;
            if (!uanwBlowgunPoisonNeedles()) ++bad;
        }
        // U3: the caltrop
        {
            if (uanwCaltropProngCountLow() != 4) ++bad;
            if (uanwCaltropProngCountHigh() != 6) ++bad;
            if (uanwCaltropDiameterInches() != 6) ++bad;
            if (uanwCaltropPointInches() != 3) ++bad;
            if (uanwCaltropPointAngleLow() != 70) ++bad;
            if (uanwCaltropPointAngleHigh() != 90)
                ++bad;
            if (uanwCaltropAwareMoveFactorPct() != 50)
                ++bad;
            // the check: a 1+1 HD monster per square yard
            if (uanwCaltropCheckHdDice() != 1) ++bad;
            if (uanwCaltropCheckHdPlus() != 1) ++bad;
            if (uanwCaltropHitSlowPct() != 25) ++bad;
            if (uanwCaltropHitSlowMovePct() != 25)
                ++bad;
            if (uanwCaltropHitSlowDays() != 4) ++bad;
            // the garbled trigger: the 8 days readable
            if (uanwCaltropTwoHitNoMoveDays() != 8)
                ++bad;
            if (uanwCaltropMinProngInches() != 2) ++bad;
            if (!uanwCaltropNoProficiencyNeeded())
                ++bad;
        }
        // U4: the hand-held crossbow, the garrot
        {
            if (!uanwHandXbowOneHandFire()) ++bad;
            if (uanwHandXbowPoisonSaveMod() != -4)
                ++bad;
            if (uanwHandXbowSurfaceCostGp() != 300)
                ++bad;
            if (uanwHandXbowDrowCostGp() != 30) ++bad;
            if (uanwHandXbowDrowQuarrelGp() != 10)
                ++bad;
            if (!uanwGarrotStrikeFromBehind()) ++bad;
            if (uanwGarrotNeckMaxFeetAboveShoulder()
                != 1) ++bad;
            if (uanwGarrotDeflectDmg() != 1) ++bad;
            if (uanwGarrotVictimAttackMod() != -2)
                ++bad;
            if (uanwGarrotSlayAtEndOfRounds() != 1)
                ++bad;
            if (!uanwGarrotBendBarsBreaks()) ++bad;
        }
        // U5: the harpoon, the hook fauchard, the lasso
        {
            if (uanwHarpoonSaveMinInt() != 2) ++bad;
            if (!uanwHarpoonSaveVsPoison()) ++bad;
            if (uanwHarpoonDragInches() != 1) ++bad;
            if (uanwHookFauchardDismountPct() != 20)
                ++bad;
            if (uanwHookFauchardSizeReqPct() != 50)
                ++bad;
            if (!uanwLassoDamageless()) ++bad;
            if (uanwLassoDismountPct() != 75) ++bad;
            if (uanwLassoPullOffFeetPct() != 25) ++bad;
            if (uanwLassoTargetMaxPct() != 50) ++bad;
        }
        // U6: the man catcher, the sap, the spiked
        // buckler, the staff sling
        {
            if (uanwManCatcherSizeBandPct() != 50)
                ++bad;
            if (!uanwManCatcherLosesShieldAndDex())
                ++bad;
            if (uanwManCatcherPushPullDmgMin() != 1)
                ++bad;
            if (uanwManCatcherPushPullDmgMax() != 2)
                ++bad;
            if (uanwManCatcherPullOffFeetPct() != 25)
                ++bad;
            if (!uanwManCatcherBreakoutBendBars())
                ++bad;
            if (uanwManCatcherAttemptDmgMin() != 1)
                ++bad;
            if (uanwManCatcherAttemptDmgMax() != 4)
                ++bad;
            if (uanwManCatcherPoleCuttingDmg() != 6)
                ++bad;
            if (!uanwSapHeadUncoveredRequired()) ++bad;
            if (uanwSapUnconsciousPctPerStr() != 5)
                ++bad;
            if (uanwSapNonHeadDamageFactorPct() != 50)
                ++bad;
            if (uanwSpikedBucklerExtraAttacksPerRound()
                != 1) ++bad;
            if (uanwSpikedBucklerSecondModeMod() != -2)
                ++bad;
            if (uanwStaffSlingPoleMinFeet() != 4) ++bad;
            if (!uanwStaffSlingMediumOrLongOnly())
                ++bad;
            if (!uanwStaffSlingUsesGrenadeTable()) ++bad;
        }
        // U7: the falchion, the khopesh
        {
            if (uanwFalchionMagicBroadswordPct() != 25)
                ++bad;
            if (uanwKhopeshHandleInches() != 6) ++bad;
            if (uanwKhopeshStraightBladeFeet() != 2)
                ++bad;
            if (uanwKhopeshSickleBladeFeet() != 2) ++bad;
            // the 1 1/2 feet extension (15 tenths)
            if (uanwKhopeshEffectiveExtendsTenthsFeet()
                != 15) ++bad;
            if (uanwKhopeshSnagNoAttackSegments() != 10)
                ++bad;
            if (uanwKhopeshSnagSizePct() != 50) ++bad;
            // the snagged split sums to 100
            if (uanwKhopeshSnaggedGroundPct()
                    + uanwKhopeshSnaggedImpededPct()
                != 100) ++bad;
            if (uanwKhopeshSnaggedGroundPct() != 25)
                ++bad;
            if (uanwKhopeshOpponentSnagOnHitPct() != 5)
                ++bad;
            if (uanwKhopeshWeaponSnagOnMissPct() != 5)
                ++bad;
            if (uanwKhopeshWeaponTornPct() != 10) ++bad;
            if (uanwKhopeshMagicScimitarPct() != 10)
                ++bad;
            if (!uanwKhopeshDruidicalIdeal()) ++bad;
        }
        // U8: the whip
        {
            if (uanwWhipEntangleNonProfPct() != 5) ++bad;
            if (uanwWhipEntangleProfPctPerLevel() != 5)
                ++bad;
            // the entanglement distribution sums to 100
            if (uanwWhipEntangleOneLimbPct()
                    + uanwWhipEntangleTwoLimbsPct()
                    + uanwWhipEntangleWeaponArmPct()
                    + uanwWhipEntangleHeadPct()
                != 100) ++bad;
            if (uanwWhipEntangleOneLimbPct() != 50)
                ++bad;
            if (uanwWhipEntangleTwoLimbsPct() != 10)
                ++bad;
            if (uanwWhipEntangleWeaponArmPct() != 20)
                ++bad;
            if (uanwWhipEntangleHeadPct() != 20) ++bad;
            if (uanwWhipEntangleHeadNoWeaponPct() != 40)
                ++bad;
            if (uanwWhipNoAttackSegments() != 10) ++bad;
            if (uanwWhipTwoLimbPronePct() != 25) ++bad;
            if (uanwWhipWeaponLostPct() != 10) ++bad;
            if (uanwWhipEdgedSeveredPct() != 50) ++bad;
            // the 3d6 minus 2 disentangle roll
            if (uanwWhipDisentangle3d6Minus() != 2) ++bad;
            if (uanwWhipVictimPullPct() != 5) ++bad;
            if (uanwWhipVictimPullPctPerStr() != 1) ++bad;
        }
        printf("R340 UA new weapons prose pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
