    // ---- R932 issue-17 wizard article part two audit ----
    // THE DRAGON ISSUE-17 OPENER PART TWO - A Wizard With A Difference by
    // James M. Ward (print 10-13, PDF 12-15, the Movement explanations riding
    // print 15, PDF 17), the eight specialized wizard variants: the
    // chance-of-making grid (100, 85, 75, 50, 40, 30, 20, 10 at First through
    // Eighth Level, plus 5 percent per caster level over the first, two
    // spells picked per level, the worked fifth-level heat-ray example with
    // its +20 and the 1-50 roll), the spell-offer count grid (the eight types
    // by the eight level bands, 206 spells offered, the Movement fifth-level
    // row never printing, the unlabeled three-spell Control overflow row, 22
    // changed spells and 54 new spells under the printed one-star and
    // two-star legend), and the explanation doctrines: the wizard of
    // aggression (the Magic Missile extra arrow per level, the Hold Person
    // 1-6 over 1-4, the Magic Spear three-plus-one per four levels, the
    // Dancing Magic Sword plus 1 for four turns, the Melt red-hot-in-one-turn
    // melt-the-next with the plate-mail mass limit), the wizard of defense
    // (Shield AC 2 for five turns plus level, the chaotic minus-one
    // Protection from Evil for six turns, the sword and edged-weapon and
    // all-weapons protections with the save-to-hit doctrine, the Repulsion
    // Field, the Etherialness, the No Punctures with its instant unfelt
    // healing), the wizard of all things rustic (the ten-turn communicates,
    // the 20-die thinking earth elemental that vanishes rather than turns on
    // a lapsing caster, the feline, canine and avian summons with the Roc
    // excluded and the one-full-turn vanish), the wizard of control (the
    // Sleep draws of two beings at five dice and one at six, the
    // staff-of-commanding once, the Charm Golems cutting golem protection
    // down to the 14th-level save), the wizard of tenaciousness (the
    // two-dispel wizard lock, the 60-yard sword and crossbow holds at 2-20,
    // the 3-30 staffs and rings, the 1-10 monster hold stopping regeneration
    // and breath, the 30-yard six-turn Stop Magic, the 12-being group hold,
    // the 40-by-30 foot openings lasting 24 hours with the caster free to
    // leave, the one-hour dispel-only locked openings, the End Arcane Walls),
    // the wizard of detection (the 1-4-plus-level Find Traps, the
    // 1-6-plus-level End Surprise, the 24-hour Reveal the Way and Divine Any
    // Object, the Transport to the Spot carrying 1-6 beings within 20 feet
    // after the over-six-hour study), the wizard of fire (the +1 per die fire
    // ball that never touches its caster but does his equipment, the 10-die
    // wall persisting 1-4, the 20-die thinking elemental, Fire Resistance
    // 1-10, the 10-dice Heat Ray striking even fire types, the 10-yard 1-10
    // Fire Immunity, the five-dice-per-turn Combustion, the 5-50 Fire
    // Vision), and the wizard of movement (the Water Travel five full turns,
    // the Negate Fly 1-5, the Negate Water 1-6, the run-toward-the-fled
    // Negate, the 20-being Mass Teleport, the three-plus-level Etherialness,
    // the twice-printed End All Barriers with both its 1-10 vanish and its
    // giant-disintegrate readings pinned, the Safe Teleport that never comes
    // high or low). The pin IS the conversion: OD&D-era ink adjudicated to 1e
    // terms, noted never silent; the as-scanned garbles ride the data file
    // and the comments.
    {
        using namespace rules;
        int bad = 0;
    if (wzdChanceLevels() != 8
            || wzdChanceRows() != 8
            || wzdNormalSpellLevels() != 9
            || wzdWizardTypes() != 8
            || wzdSpellsPerLevel() != 2
            || wzdChanceBonusPerLevel() != 5
            || wzdChangedSpellMarkStars() != 1
            || wzdNewSpellMarkStars() != 2
            || wzdExampleWizardLevel() != 5
            || wzdExampleSpellLevel() != 6
            || wzdExampleBonusPercent() != 20
            || wzdExampleBasePercent() != 30
            || wzdExampleRollMax() != 50
            || wzdExampleFailMin() != 51
            || wzdOfferRows() != 8
            || wzdTotalSpellsOffered() != 206
            || wzdCtlOverflowCount() != 3
            || wzdMarkedChanged() != 22
            || wzdMarkedNew() != 54
            || wzdAggMagicMissileArrowsPerLevel() != 1
            || wzdAggHoldPersonMax() != 6
            || wzdAggHoldPersonOldMax() != 4
            || wzdAggMagicSpearBase() != 3
            || wzdAggMagicSpearPerBand() != 1
            || wzdAggMagicSpearLevelsPerBand() != 4
            || wzdAggDancingSwordPlus() != 1
            || wzdAggDancingSwordTurns() != 4
            || wzdAggMeltHotTurn() != 1
            || wzdAggMeltMeltTurn() != 2
            || wzdDefShieldArmorClass() != 2
            || wzdDefShieldTurns() != 5
            || wzdDefProtEvilToHitPenalty() != 1
            || wzdDefProtEvilTurns() != 6
            || wzdDefProtSwordsTurns() != 4
            || wzdDefRepulsionTurns() != 2
            || wzdDefEtherialnessTurns() != 3
            || wzdDefNoPuncturesTurns() != 3
            || wzdRusCommuneTurns() != 10
            || wzdRusEarthElementalDice() != 20
            || wzdRusSummonVanishTurns() != 1
            || wzdRusCommandStaffUses() != 1
            || wzdCtlSleepTwoBeings() != 2
            || wzdCtlSleepFiveDice() != 5
            || wzdCtlSleepOneBeing() != 1
            || wzdCtlSleepSixDice() != 6
            || wzdCtlGolemSaveLevel() != 14
            || wzdCtlStaffUses() != 1
            || wzdTenWizardLockDispels() != 2
            || wzdTenHoldRadiusYards() != 60
            || wzdTenHoldSwordsTurnsMin() != 2
            || wzdTenHoldSwordsTurnsMax() != 20
            || wzdTenHoldStaffTurnsMin() != 3
            || wzdTenHoldStaffTurnsMax() != 30
            || wzdTenHoldMonsterTurnsMin() != 1
            || wzdTenHoldMonsterTurnsMax() != 10
            || wzdTenStopMagicRadiusYards() != 30
            || wzdTenStopMagicTurns() != 6
            || wzdTenHoldGroupsMaxBeings() != 12
            || wzdTenOpeningsHeightFeet() != 40
            || wzdTenOpeningsWidthFeet() != 30
            || wzdTenOpeningsHours() != 24
            || wzdTenLockOpeningsHours() != 1
            || wzdDetFindTrapsTurnsMin() != 1
            || wzdDetFindTrapsTurnsMax() != 4
            || wzdDetEndSurpriseTurnsMin() != 1
            || wzdDetEndSurpriseTurnsMax() != 6
            || wzdDetRevealHours() != 24
            || wzdDetDivineHours() != 24
            || wzdDetTransportBeingsMin() != 1
            || wzdDetTransportBeingsMax() != 6
            || wzdDetTransportRangeFeet() != 20
            || wzdDetStudyHours() != 6
            || wzdFireBallBonusPerDie() != 1
            || wzdFireWallDice() != 10
            || wzdFireWallTurnsMin() != 1
            || wzdFireWallTurnsMax() != 4
            || wzdFireElementalDice() != 20
            || wzdFireResistTurnsMin() != 1
            || wzdFireResistTurnsMax() != 10
            || wzdFireHeatRayDice() != 10
            || wzdFireHeatRayTurns() != 1
            || wzdFireImmunityRadiusYards() != 10
            || wzdFireImmunityTurnsMin() != 1
            || wzdFireImmunityTurnsMax() != 10
            || wzdFireCombustTurnsMin() != 1
            || wzdFireCombustTurnsMax() != 6
            || wzdFireCombustDicePerTurn() != 5
            || wzdFireVisionTurnsMin() != 5
            || wzdFireVisionTurnsMax() != 50
            || wzdMovWaterTravelTurns() != 5
            || wzdMovNegateFlyTurnsMin() != 1
            || wzdMovNegateFlyTurnsMax() != 5
            || wzdMovNegateWaterTurnsMin() != 1
            || wzdMovNegateWaterTurnsMax() != 6
            || wzdMovMassTeleportBeings() != 20
            || wzdMovEtherialnessTurns() != 3
            || wzdMovEndBarrierTurnsMin() != 1
            || wzdMovEndBarrierTurnsMax() != 10
            || !wzdSameLevelProgression()
            || !wzdFasterSpellUse()
            || !wzdBetterSpellLowerChance()
            || !wzdExampleSpellLostOnFail()
            || !wzdEdNoteNpcBedevilment()
            || !wzdCtlOverflowRowUnlabeled()
            || !wzdMovFifthLevelRowAbsent()
            || !wzdAggMeltMagicSaveApplicable()
            || !wzdAggMeltPlateMailMassLimit()
            || !wzdDefShieldPlusLevel()
            || !wzdDefProtEvilChaoticOnly()
            || !wzdDefProtEvilRadiusSameAsBase()
            || !wzdDefProtSwordsSaveToHit()
            || !wzdDefProtSwordsPlusLevel()
            || !wzdDefProtEdgedAsSwordSpell()
            || !wzdDefRepulsionPlusLevel()
            || !wzdDefRepulsionStopsPhysical()
            || !wzdDefEtherialnessPlusLevel()
            || !wzdDefEtherialnessAsPotion()
            || !wzdDefNoPuncturesHealsInstantly()
            || !wzdDefProtAllWeaponsAsSwordSpell()
            || !wzdRusLightFullDay()
            || !wzdRusCommuneReptilesAsMammals()
            || !wzdRusConjureElementalThinks()
            || !wzdRusSummonSeenTypesOnly()
            || !wzdRusSummonCaninesAsFelines()
            || !wzdRusSummonAviansRocExcluded()
            || !wzdRusCharmInsectAnyTypeSize()
            || !wzdRusCharmSnakeMammalAsInsect()
            || !wzdRusInsectPlagueAsCleric()
            || !wzdCtlGolemCutsProtection()
            || !wzdCtlSleepNormalOtherwise()
            || !wzdTenHoldPortalAsWizardLock()
            || !wzdTenWizardLockKnockWorks()
            || !wzdTenKnockOpensBlocked()
            || !wzdTenHoldSwordsUndrawnOnly()
            || !wzdTenHoldCrossbowsWhileConcentrating()
            || !wzdTenHoldMonsterSaveStops()
            || !wzdTenStopMagicSaveStops()
            || !wzdTenHoldGroupsMixed()
            || !wzdTenOpeningsCasterMayLeave()
            || !wzdTenOpeningsTakesDamage()
            || !wzdTenLockOpeningsDispelOnly()
            || !wzdTenEndArcaneAllMagicalWalls()
            || !wzdTenHoldCubeRingsWandsDurations()
            || !wzdDetFindTrapsPlusLevel()
            || !wzdDetFindSecretDoorsAsTraps()
            || !wzdDetEndSurprisePlusLevel()
            || !wzdDetFindPathAsCleric()
            || !wzdDetRevealFootstepsGlow()
            || !wzdDetRevealFlightPathGlow()
            || !wzdDetDivineWillowWand()
            || !wzdDetTransportMustStudy()
            || !wzdFireBallNeverAffectsCaster()
            || !wzdFireBallEquipmentNotProtected()
            || !wzdFireIllusionsFireOnly()
            || !wzdFireNegationDestroysContactedFire()
            || !wzdFireControlRedirectOnSave()
            || !wzdFireConjureElementalThinks()
            || !wzdFireBodyInfernoCasterDice()
            || !wzdFireHeatRayHitsFireTypes()
            || !wzdFireImmunityAllBeingsInRadius()
            || !wzdFireVisionNeedsLitFire()
            || !wzdMovNegateRunTowardFled()
            || !wzdMovMassTeleportAsTeleport()
            || !wzdMovEtherialnessPlusLevel()
            || !wzdMovEndBarrierPrintedTwice()
            || !wzdMovEndBarrierGiantDisintegrate()
            || !wzdMovSafeTeleportNoHighLow()
            || !wzdMovWaterTravelCastOnOthers()
        )
            ++bad;
        // the chance-of-making-per-level grid - one row per spell level band,
        // First through Eighth, the percent chance a first-level area wizard
        // has of working a spell of that level: 100, 85, 75, 50, 40, 30, 20,
        // 10 (print 10, PDF 12)
        int CWc[8][2] = {
            {1,100},
            {2,85},
            {3,75},
            {4,50},
            {5,40},
            {6,30},
            {7,20},
            {8,10},
            };
        for (int b = 0;
             b < wzdChanceRows();
             ++b) {
            int vals[2];
            vals[0] = wzdChanceLevel(b);
            vals[1] = wzdChancePercent(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CWc[b][c])
                    ++bad;
            }
        }
        // the spell-offer count grid - one row per wizard type in article
        // order (Aggression, Defense, Tenaciousness, Detection, Fire,
        // Movement, All Things Rustic, Control), one column per spell level
        // band, the count of spells offered at that level; the Movement
        // fifth-level cell pins 0 - its row never prints; the Control
        // overflow row rides wzdCtlOverflowCount; the totals pin 206 offered,
        // 22 changed, 54 new (print 10-15)
        int CWo[8][8] = {
            {3,2,4,5,2,2,4,3},
            {2,3,7,2,3,3,3,6},
            {1,2,3,4,7,3,2,3},
            {3,4,4,3,2,2,1,1},
            {2,2,2,2,2,2,2,2},
            {3,4,2,5,0,4,3,3},
            {3,4,8,5,8,5,3,3},
            {3,3,3,2,3,4,5,5},
            };
        for (int b = 0;
             b < wzdOfferRows();
             ++b) {
            int vals[8];
            vals[0] = wzdOfferL1(b);
            vals[1] = wzdOfferL2(b);
            vals[2] = wzdOfferL3(b);
            vals[3] = wzdOfferL4(b);
            vals[4] = wzdOfferL5(b);
            vals[5] = wzdOfferL6(b);
            vals[6] = wzdOfferL7(b);
            vals[7] = wzdOfferL8(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CWo[b][c])
                    ++bad;
            }
        }
        // the chance grid - 100 at first, 85, 75, 50, 40, 30, 20 down to 10
        // at eighth (print 10)
    if (wzdChanceLevel(0) != 1
            || wzdChancePercent(0) != 100
            || wzdChancePercent(1) != 85
            || wzdChancePercent(2) != 75
            || wzdChancePercent(3) != 50
            || wzdChancePercent(4) != 40
            || wzdChancePercent(5) != 30
            || wzdChancePercent(6) != 20
            || wzdChancePercent(7) != 10
            || wzdChanceLevels() != 8
        )
            ++bad;
        // the Ward worked example - a fifth-level fire wizard casting a
        // sixth-level heat ray: +20 percent, base 30, the 1-50 roll, 51
        // fails, the +5 per level over first and the two-spells-per-level
        // pick (print 10)
    if (wzdExampleWizardLevel() != 5
            || wzdExampleSpellLevel() != 6
            || wzdExampleBonusPercent() != 20
            || wzdExampleBasePercent() != 30
            || wzdExampleRollMax() != 50
            || wzdExampleFailMin() != 51
            || wzdChanceBonusPerLevel() != 5
            || wzdSpellsPerLevel() != 2
        )
            ++bad;
        // the offer grid edges - aggression three at first and three at
        // eighth, defense six at eighth, tenaciousness three at third, the
        // movement fifth-level zero and its five at fourth, rustic eight at
        // third, control three at fifth (print 10-12)
    if (wzdOfferL1(0) != 3
            || wzdOfferL8(0) != 3
            || wzdOfferL8(1) != 6
            || wzdOfferL3(2) != 3
            || wzdOfferL5(5) != 0
            || wzdOfferL3(6) != 8
            || wzdOfferL5(7) != 3
            || wzdOfferL4(5) != 5
        )
            ++bad;
        // the roster census - 206 spells offered across the eight lists, the
        // unlabeled three-spell Control overflow row, 22 changed with the
        // single star, 54 new with the double star (print 10-15)
    if (wzdTotalSpellsOffered() != 206
            || wzdCtlOverflowCount() != 3
            || wzdMarkedChanged() != 22
            || wzdMarkedNew() != 54
            || wzdWizardTypes() != 8
            || wzdChangedSpellMarkStars() != 1
            || wzdNewSpellMarkStars() != 2
        )
            ++bad;
        // the aggression explanations - the extra missile arrow per level,
        // Hold Person 1-6 over the old 1-4, the Magic Spear three-plus-one
        // per four levels, the Dancing Magic Sword plus 1 for four turns, the
        // Melt red-hot in one turn melting the next (print 12)
    if (wzdAggMagicMissileArrowsPerLevel() != 1
            || wzdAggHoldPersonMax() != 6
            || wzdAggHoldPersonOldMax() != 4
            || wzdAggMagicSpearBase() != 3
            || wzdAggMagicSpearPerBand() != 1
            || wzdAggMagicSpearLevelsPerBand() != 4
            || wzdAggDancingSwordPlus() != 1
            || wzdAggDancingSwordTurns() != 4
            || wzdAggMeltHotTurn() != 1
            || wzdAggMeltMeltTurn() != 2
        )
            ++bad;
        // the defense explanations - Shield AC 2 for five turns plus level,
        // Protection from Evil minus one to hit for six turns, Protection
        // from Swords four turns plus level, Repulsion Field two plus level,
        // Etherialness three plus level, No Punctures three (print 12)
    if (wzdDefShieldArmorClass() != 2
            || wzdDefShieldTurns() != 5
            || wzdDefProtEvilToHitPenalty() != 1
            || wzdDefProtEvilTurns() != 6
            || wzdDefProtSwordsTurns() != 4
            || wzdDefRepulsionTurns() != 2
            || wzdDefEtherialnessTurns() != 3
            || wzdDefNoPuncturesTurns() != 3
        )
            ++bad;
        // the control and rustic explanations - the Sleep draws two beings at
        // five dice and one at six, the golem saving as a 14th level wizard,
        // the staff commands once, the 20 die earth elemental, the ten-turn
        // communicates, the summons vanishing after one full turn (print 13)
    if (wzdCtlSleepTwoBeings() != 2
            || wzdCtlSleepFiveDice() != 5
            || wzdCtlSleepOneBeing() != 1
            || wzdCtlSleepSixDice() != 6
            || wzdCtlGolemSaveLevel() != 14
            || wzdCtlStaffUses() != 1
            || wzdRusEarthElementalDice() != 20
            || wzdRusCommuneTurns() != 10
            || wzdRusSummonVanishTurns() != 1
            || wzdRusCommandStaffUses() != 1
        )
            ++bad;
        // the tenaciousness explanations - two dispels on the wizard lock,
        // the 60 yard holds at 2-20, the 3-30 staff and rings, the 1-10
        // monster hold, Stop Magic at 30 yards for six turns, the 12-being
        // group hold, the 40 by 30 foot openings for 24 hours, the locked
        // openings one hour (print 13)
    if (wzdTenWizardLockDispels() != 2
            || wzdTenHoldRadiusYards() != 60
            || wzdTenHoldSwordsTurnsMin() != 2
            || wzdTenHoldSwordsTurnsMax() != 20
            || wzdTenHoldStaffTurnsMin() != 3
            || wzdTenHoldStaffTurnsMax() != 30
            || wzdTenHoldMonsterTurnsMin() != 1
            || wzdTenHoldMonsterTurnsMax() != 10
            || wzdTenStopMagicRadiusYards() != 30
            || wzdTenStopMagicTurns() != 6
            || wzdTenHoldGroupsMaxBeings() != 12
            || wzdTenOpeningsHeightFeet() != 40
            || wzdTenOpeningsWidthFeet() != 30
            || wzdTenOpeningsHours() != 24
            || wzdTenLockOpeningsHours() != 1
        )
            ++bad;
        // the detection explanations - Find Traps 1-4 plus level, End
        // Surprise 1-6 plus level, the 24-hour Reveal and Divine, the
        // Transport carrying 1-6 beings within 20 feet, the over-6-hours
        // study (print 13)
    if (wzdDetFindTrapsTurnsMin() != 1
            || wzdDetFindTrapsTurnsMax() != 4
            || wzdDetEndSurpriseTurnsMin() != 1
            || wzdDetEndSurpriseTurnsMax() != 6
            || wzdDetRevealHours() != 24
            || wzdDetDivineHours() != 24
            || wzdDetTransportBeingsMin() != 1
            || wzdDetTransportBeingsMax() != 6
            || wzdDetTransportRangeFeet() != 20
            || wzdDetStudyHours() != 6
        )
            ++bad;
        // the fire explanations - the +1 per die fire ball, the 10 die wall
        // persisting 1-4, the 20 die elemental, Fire Resistance 1-10, the
        // 10-dice Heat Ray in one turn, Immunity over 10 yards for 1-10, the
        // five dice per turn Combustion, the 5-50 Fire Vision (print 13)
    if (wzdFireBallBonusPerDie() != 1
            || wzdFireWallDice() != 10
            || wzdFireWallTurnsMin() != 1
            || wzdFireWallTurnsMax() != 4
            || wzdFireElementalDice() != 20
            || wzdFireResistTurnsMin() != 1
            || wzdFireResistTurnsMax() != 10
            || wzdFireHeatRayDice() != 10
            || wzdFireHeatRayTurns() != 1
            || wzdFireImmunityRadiusYards() != 10
            || wzdFireCombustDicePerTurn() != 5
            || wzdFireVisionTurnsMin() != 5
            || wzdFireVisionTurnsMax() != 50
        )
            ++bad;
        // the movement explanations - Water Travel five full turns, Negate
        // Fly 1-5, Negate Water 1-6, the 20-being Mass Teleport, Etherialness
        // three plus level, End All Barriers 1-10 (print 15)
    if (wzdMovWaterTravelTurns() != 5
            || wzdMovNegateFlyTurnsMin() != 1
            || wzdMovNegateFlyTurnsMax() != 5
            || wzdMovNegateWaterTurnsMin() != 1
            || wzdMovNegateWaterTurnsMax() != 6
            || wzdMovMassTeleportBeings() != 20
            || wzdMovEtherialnessTurns() != 3
            || wzdMovEndBarrierTurnsMin() != 1
            || wzdMovEndBarrierTurnsMax() != 10
        )
            ++bad;
        // the aggression row - 3, 2, 4, 5, 2, 2, 4, 3 across the eight bands
        // (print 10-12)
    if (wzdOfferL1(0) != 3
            || wzdOfferL2(0) != 2
            || wzdOfferL3(0) != 4
            || wzdOfferL4(0) != 5
            || wzdOfferL5(0) != 2
            || wzdOfferL6(0) != 2
            || wzdOfferL7(0) != 4
            || wzdOfferL8(0) != 3
        )
            ++bad;
        // the defense row - 2, 3, 7, 2, 3, 3, 3, 6, the seven-spell third
        // band and the six-spell eighth (print 10-12)
    if (wzdOfferL1(1) != 2
            || wzdOfferL2(1) != 3
            || wzdOfferL3(1) != 7
            || wzdOfferL4(1) != 2
            || wzdOfferL5(1) != 3
            || wzdOfferL6(1) != 3
            || wzdOfferL7(1) != 3
            || wzdOfferL8(1) != 6
        )
            ++bad;
        // the fire row - two spells at every band, the flat roster (print
        // 10-12)
    if (wzdOfferL1(4) != 2
            || wzdOfferL2(4) != 2
            || wzdOfferL3(4) != 2
            || wzdOfferL4(4) != 2
            || wzdOfferL5(4) != 2
            || wzdOfferL6(4) != 2
            || wzdOfferL7(4) != 2
            || wzdOfferL8(4) != 2
        )
            ++bad;
        // the rustic row - 3, 4, 8, 5, 8, 5, 3, 3, the heaviest list (print
        // 10-12)
    if (wzdOfferL1(6) != 3
            || wzdOfferL2(6) != 4
            || wzdOfferL3(6) != 8
            || wzdOfferL4(6) != 5
            || wzdOfferL5(6) != 8
            || wzdOfferL6(6) != 5
            || wzdOfferL7(6) != 3
            || wzdOfferL8(6) != 3
        )
            ++bad;
        // the control row - 3, 3, 3, 2, 3, 4, 5, 5 plus the three-spell
        // unlabeled overflow row (print 10-14)
    if (wzdOfferL1(7) != 3
            || wzdOfferL2(7) != 3
            || wzdOfferL3(7) != 3
            || wzdOfferL4(7) != 2
            || wzdOfferL5(7) != 3
            || wzdOfferL6(7) != 4
            || wzdOfferL7(7) != 5
            || wzdOfferL8(7) != 5
        )
            ++bad;
        printf("R932 issue-17 wizard article part two audit: bad %d\n", bad);
        if (bad) return 1;
    }
