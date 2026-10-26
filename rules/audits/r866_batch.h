    // ---- R866 Sumerian mythos audit ----
    // THE SUMERIAN MYTHOS - the D&DG walk round eighteen, print pp. 125-127:
    // seven stat-block rows - the five greater gods (Enlil, Enki, Inanna, Ki,
    // Utu) and the two lesser (Nanna-Sin, Nin-hursag) - plus the city-temple
    // doctrine of the intro and the pantheon-wide cloud chariots doctrine of
    // print p. 127; every one of the seven beings prints armor class -2, the
    // only uniform-AC pantheon of the walk.
    {
        using namespace rules;
        int bad = 0;
    if (smrRound() != 866
            || smrPrintStart() != 125
            || smrPrintEnd() != 127
            || smrHolyDaySeventh() != 7
            || smrHolyDayFifteenth() != 15
            || smrHolyDayTwentyFifth() != 25
            || smrTroubleLadderCount() != 15
            || smrCloudChariotMove() != 24
            || smrEnlilBoltDmg() != 40
            || smrEnlilBoltRangeMiles() != 1
            || smrEnlilAxeDmg() != 50
            || smrEnlilAxePctTimes() != 10
            || smrEnlilAxePlatePct() != 30
            || smrEnlilTeleportFeet() != 100
            || smrEnlilSpellNegatePct() != 25
            || smrEnkiMaceDmg() != 35
            || smrEnkiNegateSpellBelow() != 6
            || smrEnkiWaterGallons() != 50
            || smrEnkiSummonPerDay() != 1
            || smrInannaAxeDmg() != 25
            || smrInannaLionsCount() != 7
            || smrInannaLionMv() != 30
            || smrKiAnimalCount() != 100
            || smrKiLuckHours() != 24
            || smrNannaSinGlowFeet() != 10
            || smrNannaSinAxePlus() != 3
            || smrNannaSinAxeDmg() != 30
            || smrNinhursagWitherSpellLevel() != 9
            || smrNinhursagWitherCharges() != 3
            || smrUtuGlowRadiusFeet() != 10
            || smrUtuGlowStrikeMod() != 2
            || smrUtuRayCount() != 2
            || smrUtuRayDmg() != 20
            || smrUtuHeatThreshold() != 100
            || smrUtuPolymorphSaveMod() != 3
            || smrUtuSunbitsRangeMiles() != 2
            || smrUtuSunbitsDmg() != 50
            || smrBeingCount() != 7
            || smrGreaterCount() != 5
            || smrLesserCount() != 2
            || smrTableCount() != 4
            || smrChainCount() != 0
            || smrCbtRows() != 7
            || smrClsRows() != 7
            || smrAbiRows() != 7
            || smrRosRows() != 7
            || smrElysiumCount() != 3
            || smrNirvanaCount() != 2
            || smrNineHellsCount() != 1
            || smrPrimeCount() != 1
            || smrPsiNilCount() != 4
            || smrPsiICount() != 2
            || smrPsiVicount() != 1
            || smrUniformAcCount() != 7
            || smrInEachCount() != 5
            || smrDualMoveCount() != 6
            || smrDmgFixedCount() != 5
            || smrWorshipOddCount() != 1
            || !smrCityPatronDeity()
            || !smrKingHighPriest()
            || !smrSteppedPyramidTemples()
            || !smrZigguratRedBrick()
            || !smrSacrificeItemsAltars()
            || !smrClericItemBurning()
            || !smrHumanSacrifice()
            || !smrCondemnedCriminals()
            || !smrInnerShrineImage()
            || !smrAltarTableGifts()
            || !smrCentralCourtyard()
            || !smrSideChapels()
            || !smrRightAngleEntrance()
            || !smrFoodBurntNightly()
            || !smrNewMoonSacrifice()
            || !smrPunishmentGastro()
            || !smrPunishmentTroubles()
            || !smrPunishmentDeath()
            || !smrSacrificeErases()
            || !smrShavenClerics()
            || !smrWhiteKiltRobes()
            || !smrBorderIndicatesPatron()
            || !smrConicalHats()
            || !smrGodsCloseToWorshipers()
            || !smrBabylonianOverlap()
            || !smrCloudChariotsAll()
            || !smrCloudChariotRadiance()
            || !smrCloudChariotImpress()
            || !smrCloudChariotTeleport()
            || !smrCloudChariotIndestructible()
            || !smrCloudChariotCarry()
            || !smrGodsAppearOnChariots()
            || !smrEnlilShapeChange()
            || !smrEnlilEspAnyDistance()
            || !smrEnlilRaiseDead()
            || !smrEnlilLightningImmune()
            || !smrEnlilWarHelmUnaffected()
            || !smrEnlilHelmForcedHit()
            || !smrEnlilHelmChooseTwo()
            || !smrEnlilHelmNoShock()
            || !smrEnlilAxeNoMetalDmg()
            || !smrEnlilAxeDisenchant()
            || !smrEnlilAxeUnbreakable()
            || !smrEnkiAlwaysGreen()
            || !smrEnkiShapeChange()
            || !smrEnkiWaterDeadSummon()
            || !smrEnkiSummonOnceEver()
            || !smrEnkiBlinkDogMove()
            || !smrEnkiHeatImmune()
            || !smrEnkiTeleportWaterOnly()
            || !smrEnkiDemonHater()
            || !smrEnkiStrongestFirst()
            || !smrEnkiMaceEthereal()
            || !smrEnkiMaceNeverHarmLN()
            || !smrEnkiWaterArmorAbsorb()
            || !smrEnkiPatronJewelers()
            || !smrInannaBeautifulWoman()
            || !smrInannaAidBraveWarriors()
            || !smrInannaAidNeverHit()
            || !smrInannaAidAlwaysSave()
            || !smrInannaAidNeverMiss()
            || !smrInannaAidMeleeDuration()
            || !smrInannaShapeChange()
            || !smrInannaAnimateStatues()
            || !smrInannaSummonDeadKilled()
            || !smrInannaAxeArmorDust()
            || !smrInannaAxeNeverSurprised()
            || !smrInannaBreastPlates()
            || !smrInannaFickleWeapons()
            || !smrInannaLionChariot()
            || !smrInannaLionFlight()
            || !smrKiElfinWoman()
            || !smrKiUntouchedByThrown()
            || !smrKiShapeChangeNonMonster()
            || !smrKiLuckOfGods()
            || !smrKiLuckHalfDamage()
            || !smrKiAnimalSummon()
            || !smrKiSpeciesOncePerWeek()
            || !smrKiOneTypeAtATime()
            || !smrKiLocateAnything()
            || !smrKiHalfDamageAlways()
            || !smrKiAlwaysSaves()
            || !smrKiClericsDruids()
            || !smrKiGreatDruidComms()
            || !smrNannaSinBlueGlow()
            || !smrNannaSinNegateHeat()
            || !smrNannaSinNegateCold()
            || !smrNannaSinNegateElectricity()
            || !smrNannaSinNegateLight()
            || !smrNannaSinNegateDarkness()
            || !smrNannaSinSwordOfSharpness()
            || !smrNinhursagDarkSkinnedFemale()
            || !smrNinhursagGravityControl()
            || !smrNinhursagGiftOfFlight()
            || !smrNinhursagWitherHated()
            || !smrNinhursagWitherWishComponents()
            || !smrUtuHumanForm()
            || !smrUtuUndeadWither()
            || !smrUtuRegenerateHeat()
            || !smrUtuPolymorphDirt()
            || !smrUtuAuraMelt()
        )
            ++bad;
        // the the combat grid grid
        int CsmrCbt[7][9] = {
            {-2,0,400,12,36,2,0,50,78},
            {-2,0,388,12,24,3,2,50,72},
            {-2,0,391,12,24,2,0,66,72},
            {-2,0,380,15,36,0,0,90,60},
            {-2,0,339,12,24,2,0,75,72},
            {-2,0,355,9,12,3,2,50,72},
            {-2,0,377,-1,0,3,2,90,72},
            };
        for (int b = 0;
             b < smrCbtRows();
             ++b) {
            int vals[9];
            vals[0] = smrCbtAC(b);
            vals[1] = smrCbtACAlt(b);
            vals[2] = smrCbtHP(b);
            vals[3] = smrCbtMove(b);
            vals[4] = smrCbtMoveAlt(b);
            vals[5] = smrCbtAtN(b);
            vals[6] = smrCbtAtD(b);
            vals[7] = smrCbtMR(b);
            vals[8] = smrCbtSizeIn(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CsmrCbt[b][c])
                    ++bad;
            }
        }
        // the the class grid grid
        int CsmrCls[7][11] = {
            {20,0,0,19,0,15,0,0,0,0,12},
            {20,0,0,0,13,13,13,0,0,0,10},
            {10,10,0,20,0,12,12,15,0,0,10},
            {30,14,0,0,10,20,20,0,0,0,20},
            {13,13,16,0,0,15,15,0,0,0,15},
            {0,13,11,0,0,30,0,0,0,0,0},
            {15,14,0,13,0,15,15,0,0,0,5},
            };
        for (int b = 0;
             b < smrClsRows();
             ++b) {
            int vals[11];
            vals[0] = smrClsClr(b);
            vals[1] = smrClsDrd(b);
            vals[2] = smrClsFtr(b);
            vals[3] = smrClsRng(b);
            vals[4] = smrClsPal(b);
            vals[5] = smrClsMU(b);
            vals[6] = smrClsIll(b);
            vals[7] = smrClsThf(b);
            vals[8] = smrClsAss(b);
            vals[9] = smrClsMnk(b);
            vals[10] = smrClsBrd(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CsmrCls[b][c])
                    ++bad;
            }
        }
        // the the ability grid grid
        int CsmrAbi[7][8] = {
            {25,7,14,25,25,23,25,24},
            {23,5,11,25,24,23,25,23},
            {20,3,8,21,19,25,24,25},
            {25,0,0,23,25,23,25,25},
            {25,7,14,24,25,19,23,25},
            {23,5,11,23,23,23,23,23},
            {24,6,12,20,22,22,24,25},
            };
        for (int b = 0;
             b < smrAbiRows();
             ++b) {
            int vals[8];
            vals[0] = smrAbiS(b);
            vals[1] = smrAbiHit(b);
            vals[2] = smrAbiDmg(b);
            vals[3] = smrAbiI(b);
            vals[4] = smrAbiW(b);
            vals[5] = smrAbiD(b);
            vals[6] = smrAbiC(b);
            vals[7] = smrAbiCH(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CsmrAbi[b][c])
                    ++bad;
            }
        }
        // the the roster grid grid
        int CsmrRos[7][9] = {
            {125,1,0,5,1,0,1,0,0},
            {126,2,0,1,1,0,1,1,0},
            {126,3,0,6,1,1,1,1,1},
            {126,4,0,4,1,1,0,1,0},
            {127,1,0,2,0,0,1,1,0},
            {127,1,0,4,0,0,0,0,0},
            {127,2,0,2,1,6,1,1,0},
            };
        for (int b = 0;
             b < smrRosRows();
             ++b) {
            int vals[9];
            vals[0] = smrRosPage(b);
            vals[1] = smrRosPlane(b);
            vals[2] = smrRosPlaneAlt(b);
            vals[3] = smrRosAlign(b);
            vals[4] = smrRosRank(b);
            vals[5] = smrRosPsi(b);
            vals[6] = smrRosDmgFixed(b);
            vals[7] = smrRosInEach(b);
            vals[8] = smrRosWorshipOdd(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CsmrRos[b][c])
                    ++bad;
            }
        }
        // the census walk (the four grids, the seven beings, the rank, plane,
        // psionic and uniform-AC counts)
    if (smrRound() != 866
            || smrBeingCount() != 7
            || smrTableCount() != 4
            || smrChainCount() != 0
            || smrCbtRows() != 7
            || smrClsRows() != 7
            || smrAbiRows() != 7
            || smrRosRows() != 7
            || smrGreaterCount() != 5
            || smrLesserCount() != 5 - 3
            || smrElysiumCount() != 3
            || smrNirvanaCount() != 2
            || smrNineHellsCount() != 1
            || smrPrimeCount() != 1
            || smrPsiNilCount() != 4
            || smrPsiICount() != 2
            || smrPsiVicount() != 1
            || smrUniformAcCount() != 7
            || smrInEachCount() != 5
            || smrDualMoveCount() != 6
            || smrDmgFixedCount() != 5
            || smrWorshipOddCount() != 1
        )
            ++bad;
        // the combat grid (the uniform armor class, the hit points, the
        // moves, the magic resistance and the sizes)
    if (smrCbtAC(0) != -2
            || smrCbtAC(3) != -2
            || smrCbtAC(6) != -2
            || smrCbtHP(0) != 400
            || smrCbtHP(4) != 339
            || smrCbtMove(0) != 12
            || smrCbtMoveAlt(0) != 36
            || smrCbtMove(5) != 9
            || smrCbtMove(6) != -1
            || smrCbtMoveAlt(3) != 36
            || smrCbtMR(3) != 90
            || smrCbtSizeIn(0) != 78
            || smrCbtSizeIn(3) != 60
            || smrCbtSizeIn(1) != 72
        )
            ++bad;
        // the attacks cells (the three-halves prints, the Ki zero-attacks and
        // the Utu garble)
    if (smrCbtAtN(1) != 3
            || smrCbtAtD(1) != 2
            || smrCbtAtN(5) != 3
            || smrCbtAtD(6) != 2
            || smrCbtAtN(3) != 0
            || smrCbtAtN(0) != 2
            || smrCbtAtD(2) != 0
        )
            ++bad;
        // the class grid (the Enlil cleric and ranger, the Ki triple, the
        // Inanna thief, the Utu bard)
    if (smrClsClr(0) != 20
            || smrClsRng(0) != 19
            || smrClsClr(3) != 30
            || smrClsDrd(3) != 14
            || smrClsPal(3) != 10
            || smrClsThf(2) != 15
            || smrClsBrd(6) != 5
            || smrClsMU(5) != 30
            || smrClsBrd(0) != 12
        )
            ++bad;
        // the in-each pairs (Enki magic-user and illusionist, Inanna cleric
        // and druid, the Nanna-Sin and Utu pairs)
    if (smrClsMU(1) != 13
            || smrClsIll(1) != 13
            || smrClsClr(2) != 10
            || smrClsDrd(2) != 10
            || smrClsMU(2) != 12
            || smrClsIll(2) != 12
            || smrClsClr(4) != 13
            || smrClsMU(6) != 15
            || smrClsIll(6) != 15
            || smrClsFtr(4) != 16
        )
            ++bad;
        // the Enki bard divergence and the Nin-hursag Nil row (the print pins
        // over the L&L voice)
    if (smrClsBrd(1) != 10
            || smrClsBrd(5) != 0
            || smrClsClr(5) != 0
            || smrClsIll(5) != 0
        )
            ++bad;
        // the ability grid (the Enlil print pins, the bonus pairs, the all-23
        // row)
    if (smrAbiS(0) != 25
            || smrAbiHit(0) != 7
            || smrAbiDmg(0) != 14
            || smrAbiD(0) != 23
            || smrAbiCH(0) != 24
            || smrAbiS(3) != 25
            || smrAbiHit(3) != 0
            || smrAbiD(2) != 25
            || smrAbiS(6) != 24
            || smrAbiDmg(6) != 12
            || smrAbiW(5) != 23
            || smrAbiCH(5) != 23
            || smrAbiC(5) != 23
        )
            ++bad;
        // the roster grid (the pages, the planes, the ranks, the Inanna
        // single pipe, the worship-odd print)
    if (smrRosPage(0) != 125
            || smrRosPage(6) != 127
            || smrRosPlane(0) != 1
            || smrRosPlane(1) != 2
            || smrRosPlane(2) != 3
            || smrRosPlane(3) != 4
            || smrRosRank(4) != 0
            || smrRosRank(0) != 1
            || smrRosPsi(2) != 1
            || smrRosPsi(6) != 6
            || smrRosPsi(0) != 0
            || smrRosAlign(2) != 6
            || smrRosAlign(0) != 5
            || smrRosInEach(1) != 1
            || smrRosWorshipOdd(2) != 1
            || smrRosDmgFixed(5) != 0
        )
            ++bad;
        // the Enlil bolts and the raise-dead uniqueness
    if (smrEnlilBoltDmg() != 40
            || smrEnlilBoltRangeMiles() != 1
            || smrEnlilRaiseDead() != 1
            || smrEnlilLightningImmune() != 1
            || smrEnlilEspAnyDistance() != 1
            || smrEnlilShapeChange() != 1
        )
            ++bad;
        // the Enlil war helm (the forced hit, the two-or-more choice)
    if (smrEnlilHelmForcedHit() != 1
            || smrEnlilHelmChooseTwo() != 1
            || smrEnlilHelmNoShock() != 1
            || smrEnlilWarHelmUnaffected() != 1
        )
            ++bad;
        // the Enlil stone axe (the damage, the metal rule, the disenchant,
        // the teleport, the spell negate)
    if (smrEnlilAxeDmg() != 50
            || smrEnlilAxePctTimes() != 10
            || smrEnlilAxePlatePct() != 30
            || smrEnlilAxeNoMetalDmg() != 1
            || smrEnlilAxeDisenchant() != 1
            || smrEnlilAxeUnbreakable() != 1
            || smrEnlilTeleportFeet() != 100
            || smrEnlilSpellNegatePct() != 25
        )
            ++bad;
        // the Enki mace, the water laws and the demon hatred
    if (smrEnkiMaceDmg() != 35
            || smrEnkiNegateSpellBelow() != 6
            || smrEnkiWaterGallons() != 50
            || smrEnkiSummonPerDay() != 1
            || smrEnkiDemonHater() != 1
            || smrEnkiStrongestFirst() != 1
            || smrEnkiHeatImmune() != 1
            || smrEnkiBlinkDogMove() != 1
            || smrEnkiTeleportWaterOnly() != 1
        )
            ++bad;
        // the Enki mace ethics and the water armor
    if (smrEnkiMaceEthereal() != 1
            || smrEnkiMaceNeverHarmLN() != 1
            || smrEnkiWaterArmorAbsorb() != 1
            || smrEnkiAlwaysGreen() != 1
            || smrEnkiShapeChange() != 1
            || smrEnkiWaterDeadSummon() != 1
            || smrEnkiSummonOnceEver() != 1
            || smrEnkiPatronJewelers() != 1
        )
            ++bad;
        // the Inanna axe, statues and the dead she has killed
    if (smrInannaAxeDmg() != 25
            || smrInannaAxeArmorDust() != 1
            || smrInannaAxeNeverSurprised() != 1
            || smrInannaAnimateStatues() != 1
            || smrInannaSummonDeadKilled() != 1
            || smrInannaShapeChange() != 1
            || smrInannaBreastPlates() != 1
        )
            ++bad;
        // the Inanna aid, the fickle altars and the seven flying lions
    if (smrInannaAidBraveWarriors() != 1
            || smrInannaAidNeverHit() != 1
            || smrInannaAidAlwaysSave() != 1
            || smrInannaAidNeverMiss() != 1
            || smrInannaAidMeleeDuration() != 1
            || smrInannaFickleWeapons() != 1
            || smrInannaLionsCount() != 7
            || smrInannaLionMv() != 30
            || smrInannaLionFlight() != 1
        )
            ++bad;
        // the Ki summons, the luck of the gods and the druid clergy
    if (smrKiAnimalCount() != 100
            || smrKiLuckHours() != 24
            || smrKiAnimalSummon() != 1
            || smrKiSpeciesOncePerWeek() != 1
            || smrKiOneTypeAtATime() != 1
            || smrKiLocateAnything() != 1
            || smrKiLuckOfGods() != 1
            || smrKiLuckHalfDamage() != 1
            || smrKiClericsDruids() != 1
            || smrKiGreatDruidComms() != 1
            || smrKiUntouchedByThrown() != 1
            || smrKiShapeChangeNonMonster() != 1
        )
            ++bad;
        // the Nanna-Sin glow, the negations and the jet black axe
    if (smrNannaSinGlowFeet() != 10
            || smrNannaSinBlueGlow() != 1
            || smrNannaSinNegateHeat() != 1
            || smrNannaSinNegateCold() != 1
            || smrNannaSinNegateElectricity() != 1
            || smrNannaSinNegateLight() != 1
            || smrNannaSinNegateDarkness() != 1
            || smrNannaSinAxePlus() != 3
            || smrNannaSinAxeDmg() != 30
            || smrNannaSinSwordOfSharpness() != 1
        )
            ++bad;
        // the Nin-hursag gravity and the withering
    if (smrNinhursagGravityControl() != 1
            || smrNinhursagGiftOfFlight() != 1
            || smrNinhursagWitherHated() != 1
            || smrNinhursagWitherSpellLevel() != 9
            || smrNinhursagWitherCharges() != 3
            || smrNinhursagWitherWishComponents() != 1
            || smrNinhursagDarkSkinnedFemale() != 1
        )
            ++bad;
        // the Utu glow, the light rays and the sun-bits
    if (smrUtuGlowRadiusFeet() != 10
            || smrUtuGlowStrikeMod() != 2
            || smrUtuRayCount() != 2
            || smrUtuRayDmg() != 20
            || smrUtuSunbitsRangeMiles() != 2
            || smrUtuSunbitsDmg() != 50
            || smrUtuUndeadWither() != 1
            || smrUtuRegenerateHeat() != 1
            || smrUtuHeatThreshold() != 100
            || smrUtuPolymorphDirt() != 1
            || smrUtuPolymorphSaveMod() != 3
            || smrUtuAuraMelt() != 1
            || smrUtuHumanForm() != 1
        )
            ++bad;
        // the temple doctrine (the holy days, the punishment ladder, the
        // dress)
    if (smrHolyDaySeventh() != 7
            || smrHolyDayFifteenth() != 15
            || smrHolyDayTwentyFifth() != 25
            || smrTroubleLadderCount() != 15
            || smrPunishmentGastro() != 1
            || smrPunishmentTroubles() != 1
            || smrPunishmentDeath() != 1
            || smrSacrificeErases() != 1
            || smrNewMoonSacrifice() != 1
            || smrFoodBurntNightly() != 1
            || smrShavenClerics() != 1
            || smrWhiteKiltRobes() != 1
            || smrConicalHats() != 1
            || smrBorderIndicatesPatron() != 1
        )
            ++bad;
        // the city-temple structure and the priest-king
    if (smrCityPatronDeity() != 1
            || smrKingHighPriest() != 1
            || smrSteppedPyramidTemples() != 1
            || smrZigguratRedBrick() != 1
            || smrInnerShrineImage() != 1
            || smrAltarTableGifts() != 1
            || smrCentralCourtyard() != 1
            || smrSideChapels() != 1
            || smrRightAngleEntrance() != 1
            || smrClericItemBurning() != 1
            || smrHumanSacrifice() != 1
            || smrCondemnedCriminals() != 1
        )
            ++bad;
        // the cloud chariots (the pantheon-wide doctrine of print p. 127)
    if (smrCloudChariotMove() != 24
            || smrCloudChariotsAll() != 1
            || smrCloudChariotRadiance() != 1
            || smrCloudChariotImpress() != 1
            || smrCloudChariotTeleport() != 1
            || smrCloudChariotIndestructible() != 1
            || smrCloudChariotCarry() != 1
            || smrGodsAppearOnChariots() != 1
        )
            ++bad;
        // the Babylonian overlap note and the close gods
    if (smrBabylonianOverlap() != 1
            || smrGodsCloseToWorshipers() != 1
            || smrSacrificeItemsAltars() != 1
        )
            ++bad;
        printf("R866 Sumerian mythos audit: bad %d\n", bad);
        if (bad) return 1;
    }
