    // ---- R905 witch remainders audit ----
    // THE WITCH REMAINDERS AND THE FRIEDMAN ELF TABLE - the might-be-usable
    // micro-round from the 2026-10-29 issue-5 ledger review. The familiars
    // (folio 8): the six-sided die - 1,2 basilisk, 3 wyvern, 4 warlock with
    // one ring and one wand, 5,6 one undead character with no vampires, the
    // familiars cooperating over the entire circle, the good witches exempt
    // from the guard. The items (folios 7-9): the Assassin's Eyes at 12
    // inches per turn, invisible and immaterial, the one-turn kill window,
    // the Charm Person or Death Ray with saving throws; the Leech Dust - the
    // 2-inch Cloudkill-dimension cloud, weak at two turns, paralyzed at
    // three, dead at four, plate armor prolonging death two, holy water the
    // only removal and a week of rest after; the Mountain Seeds swelling to a
    // castle; the Witch Wand's 30-foot ESP medallion and the lycanthrope,
    // undead and elemental shield like scrolls; the three-wand canon with the
    // Illusion Wand restricted to witches and magic-users; the Ivy Bracelet's
    // plant control and fragility; the Locket of Satan - 7 inches, 3 chaotic
    // creatures, no saving throws, the two-turn 15-percent lawful corruption,
    // no effect on clerics; the Snake Belt - 3 feet, 6 feet per turn, 1 die,
    // killed only by fire and lightning; the Skull of Death's repeatable
    // Finger of Death and Animate Dead; the Luck Charm remainder - the
    // 70-percent single wish or two limited weekly, the 10-percent
    // lair-finding bonus, the per-category treasure enhancement of 20 percent
    // (at 75 percent chance) or 50 percent; the Potion Cauldron - witches
    // only, one duplicate per hour, the Treasure-Finding blood pledge with
    // prompt cursing on a broken word. The spell effect details (folios 4-7):
    // the 12-hit-dice elemental one turn late and gone with the
    // concentration; the 50-foot Wither; the Weight spell over 1-10 targets
    // at triple or one-third; the Volcanic Circle flowing 4 feet per turn
    // behind a 10-foot line for 10 dice to ground creatures; the two-turn
    // Reflections returning everything but Banish, Disintegrate and the sense
    // magics; the Solidify's true-matter rock, porous for breathing, beyond
    // Dispel and Dissipation; the Undead Control over 1-6 undead with the
    // crystal-ball maintenance; the Curse - no immediate death, the
    // 75-percent silver enclosure; the Poison Touch - 3 objects or the 4-by-4
    // surface, death at two turns of contact, Neutralize Poison the cure; the
    // Curtain Wall - the 10-foot curtain before the 10-by-20 room, two
    // control agents required simultaneously; the Fire Box's 10-foot cube
    // destroyed by cold, rain or magic; the Diminish halving ladder; the
    // 25-foot Circle of Blindness with the Djinn, Efreet, Cleric and witch
    // exceptions. The Friedman elf sub-race table (folio 14): the d20 - 1-16
    // Silvan, 17-19 Sindar, 20 Noldor, editorially endorsed in print, the
    // Tolkien-names boundary pinned as the honest provenance. The R904 record
    // seats in the seed via prev_record.
    {
        using namespace rules;
        int bad = 0;
    if (wrmFamiliarBasiliskMin() != 1
            || wrmFamiliarBasiliskMax() != 2
            || wrmFamiliarWyvernRoll() != 3
            || wrmFamiliarWarlockRoll() != 4
            || wrmFamiliarUndeadMin() != 5
            || wrmFamiliarUndeadMax() != 6
            || wrmAssassinEyesSpeed() != 12
            || wrmAssassinEyesVictimTurns() != 1
            || wrmLeechDustRange() != 2
            || wrmLeechDustUnableTurns() != 2
            || wrmLeechDustParalyzeTurns() != 3
            || wrmLeechDustDeathTurns() != 4
            || wrmLeechDustPlateBonusTurns() != 2
            || wrmWandEspRange() != 30
            || wrmLocketSatanRange() != 7
            || wrmLocketSatanCommandMax() != 3
            || wrmLocketSatanCorruptTurns() != 2
            || wrmLocketSatanCorruptPct() != 15
            || wrmSnakeBeltLengthFeet() != 3
            || wrmSnakeBeltSpeed() != 6
            || wrmSnakeBeltDamageDice() != 1
            || wrmLuckCharmWishPct() != 70
            || wrmLuckCharmLimitedWishes() != 2
            || wrmLuckCharmLairBonusPct() != 10
            || wrmLuckCharmTreasure20Pct() != 75
            || wrmLuckCharmTreasureBonus20() != 20
            || wrmLuckCharmTreasureBonus50() != 50
            || wrmPotionDupPerHour() != 1
            || wrmWitchElementalHd() != 12
            || wrmWitchElementalDelayTurns() != 1
            || wrmWitherCircleFeet() != 50
            || wrmWeightAffectedMin() != 1
            || wrmWeightAffectedMax() != 10
            || wrmWeightFactor() != 3
            || wrmVolcanicFlowFeet() != 4
            || wrmVolcanicLineFeet() != 10
            || wrmVolcanicDamageDice() != 10
            || wrmReflectionsTurns() != 2
            || wrmUndeadControlMin() != 1
            || wrmUndeadControlMax() != 6
            || wrmCurseSilverPct() != 75
            || wrmPoisonTouchObjects() != 3
            || wrmPoisonTouchDeathAfterTurns() != 2
            || wrmCurtainWidthFeet() != 10
            || wrmCurtainRoomDepthFeet() != 20
            || wrmFireBoxCubeFeet() != 10
            || wrmBlindnessRadiusFeet() != 25
            || wrmElfSubraceCount() != 3
            || wrmElfTableDieSides() != 20
            || !wrmFamiliarNoVampires()
            || !wrmFamiliarsCooperate()
            || !wrmGoodWitchNoGuardFamiliar()
            || !wrmAssassinEyesImmaterial()
            || !wrmAssassinEyesCharmOrDeath()
            || !wrmLeechDustHolyWaterOnly()
            || !wrmMountainSeedCastleSize()
            || !wrmWandLycanthropeShield()
            || !wrmWitchThreeWands()
            || !wrmIllusionWandRestricted()
            || !wrmIvyBraceletPlantControl()
            || !wrmIvyBraceletFragile()
            || !wrmLocketSatanClericImmune()
            || !wrmSnakeBeltFireLightningOnly()
            || !wrmSkullPowersRepeatable()
            || !wrmPotionCauldronWitchesOnly()
            || !wrmTreasureFindingDoctrine()
            || !wrmWitchElementalConcentration()
            || !wrmReflectionsExceptions()
            || !wrmSolidifyTrueMatter()
            || !wrmUndeadControlCrystalBall()
            || !wrmCurseNoImmediateDeath()
            || !wrmPoisonTouchNeutralizable()
            || !wrmCurtainTwoAgents()
            || !wrmFireBoxElements()
            || !wrmDiminishHalving()
            || !wrmBlindnessExceptions()
            || !wrmElfTableEditorEndorsed()
            || !wrmElfTableTolkienNames()
        )
            ++bad;
        // the Friedman elf sub-race table on the 20-sided die - 1-16 Silvan
        // (Wood), 17-19 Sindar (Grey), 20 Noldor (High), editorially endorsed
        // in print (folio 14)
        int CElfS[3][2] = {
            {1,16},
            {17,19},
            {20,20},
            };
        for (int b = 0;
             b < wrmElfSubraceCount();
             ++b) {
            int vals[2];
            vals[0] = wrmElfSubraceMin(b);
            vals[1] = wrmElfSubraceMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CElfS[b][c])
                    ++bad;
            }
        }
        // the witch familiar die - 1,2 basilisk; 3 wyvern; 4 warlock with
        // ring and wand; 5,6 one undead (folio 8)
    if (wrmFamiliarBasiliskMin() != 1
            || wrmFamiliarBasiliskMax() != 2
            || wrmFamiliarWyvernRoll() != 3
            || wrmFamiliarWarlockRoll() != 4
            || wrmFamiliarUndeadMin() != 5
            || wrmFamiliarUndeadMax() != 6
        )
            ++bad;
        // the familiar doctrines - no vampires, the cooperating guard, the
        // good witch exemption (folio 8)
    if (wrmFamiliarNoVampires() != 1
            || wrmFamiliarsCooperate() != 1
            || wrmGoodWitchNoGuardFamiliar() != 1
        )
            ++bad;
        // the Assassin's Eyes - 12 inches per turn, invisible and immaterial,
        // the one-turn window, the Charm or Death Ray attack (folio 7)
    if (wrmAssassinEyesSpeed() != 12
            || wrmAssassinEyesVictimTurns() != 1
            || wrmAssassinEyesImmaterial() != 1
            || wrmAssassinEyesCharmOrDeath() != 1
        )
            ++bad;
        // the Leech Dust ladder - weak at two, paralyzed at three, dead at
        // four, the plate-armor two-turn reprieve, holy water only; the
        // Mountain Seeds castle-size swell (folio 7)
    if (wrmLeechDustRange() != 2
            || wrmLeechDustUnableTurns() != 2
            || wrmLeechDustParalyzeTurns() != 3
            || wrmLeechDustDeathTurns() != 4
            || wrmLeechDustPlateBonusTurns() != 2
            || wrmLeechDustHolyWaterOnly() != 1
            || wrmMountainSeedCastleSize() != 1
        )
            ++bad;
        // the Witch Wand extras - the 30-foot ESP medallion, the
        // lycanthrope/undead/elemental shield, the three-wand canon, the
        // Illusion Wand restriction (folios 8, 9)
    if (wrmWandEspRange() != 30
            || wrmWandLycanthropeShield() != 1
            || wrmWitchThreeWands() != 1
            || wrmIllusionWandRestricted() != 1
        )
            ++bad;
        // the Ivy Bracelet and the Locket of Satan - the plant control and
        // fragility, the 7-inch 3-creature command, the two-turn 15-percent
        // corruption, the cleric immunity (folio 9)
    if (wrmIvyBraceletPlantControl() != 1
            || wrmIvyBraceletFragile() != 1
            || wrmLocketSatanRange() != 7
            || wrmLocketSatanCommandMax() != 3
            || wrmLocketSatanCorruptTurns() != 2
            || wrmLocketSatanCorruptPct() != 15
            || wrmLocketSatanClericImmune() != 1
        )
            ++bad;
        // the Snake Belt - 3 feet, 6 feet per turn, 1 die, fire and lightning
        // only; the Skull of Death's repeatable Finger of Death and Animate
        // Dead (folios 7, 9)
    if (wrmSnakeBeltLengthFeet() != 3
            || wrmSnakeBeltSpeed() != 6
            || wrmSnakeBeltDamageDice() != 1
            || wrmSnakeBeltFireLightningOnly() != 1
            || wrmSkullPowersRepeatable() != 1
        )
            ++bad;
        // the Luck Charm remainder - the 70-percent wish, the two limited
        // wishes weekly, the 10-percent lair bonus, the 20/50 per-category
        // treasure enhancement at 75 percent (folio 28)
    if (wrmLuckCharmWishPct() != 70
            || wrmLuckCharmLimitedWishes() != 2
            || wrmLuckCharmLairBonusPct() != 10
            || wrmLuckCharmTreasure20Pct() != 75
            || wrmLuckCharmTreasureBonus20() != 20
            || wrmLuckCharmTreasureBonus50() != 50
        )
            ++bad;
        // the Potion Cauldron - one duplicate per hour, witches only, the
        // Treasure-Finding blood-pledge doctrine (folio 8)
    if (wrmPotionDupPerHour() != 1
            || wrmPotionCauldronWitchesOnly() != 1
            || wrmTreasureFindingDoctrine() != 1
        )
            ++bad;
        // the witch's Summon Elemental - 12 hit dice, one turn late, gone if
        // the concentration breaks (folio 4)
    if (wrmWitchElementalHd() != 12
            || wrmWitchElementalDelayTurns() != 1
            || wrmWitchElementalConcentration() != 1
        )
            ++bad;
        // the Group B effects - the 50-foot Wither circle, the Weight spell
        // over 1-10 targets at triple or one-third (folio 7)
    if (wrmWitherCircleFeet() != 50
            || wrmWeightAffectedMin() != 1
            || wrmWeightAffectedMax() != 10
            || wrmWeightFactor() != 3
        )
            ++bad;
        // the Volcanic Circle - 4 feet per turn, 10-foot line, 10 dice under
        // the flow; the two-turn Reflections with its Banish/Disintegrate
        // exceptions; the Solidify true-matter doctrine (folio 7)
    if (wrmVolcanicFlowFeet() != 4
            || wrmVolcanicLineFeet() != 10
            || wrmVolcanicDamageDice() != 10
            || wrmReflectionsTurns() != 2
            || wrmReflectionsExceptions() != 1
            || wrmSolidifyTrueMatter() != 1
        )
            ++bad;
        // the Undead Control over 1-6 undead with the crystal-ball range
        // doctrine; the Curse - no immediate death, the 75-percent silver
        // enclosure (folio 5)
    if (wrmUndeadControlMin() != 1
            || wrmUndeadControlMax() != 6
            || wrmUndeadControlCrystalBall() != 1
            || wrmCurseSilverPct() != 75
            || wrmCurseNoImmediateDeath() != 1
        )
            ++bad;
        // the Poison Touch - 3 objects or a 4-by-4 surface, dead at two turns
        // of contact, Neutralize Poison the cure; the Curtain Wall - 10 feet
        // wide, 20 feet deep, two control agents (folio 5)
    if (wrmPoisonTouchObjects() != 3
            || wrmPoisonTouchDeathAfterTurns() != 2
            || wrmPoisonTouchNeutralizable() != 1
            || wrmCurtainWidthFeet() != 10
            || wrmCurtainRoomDepthFeet() != 20
            || wrmCurtainTwoAgents() != 1
        )
            ++bad;
        // the Fire Box 10-foot cube with its element weaknesses, the Diminish
        // halving ladder, the 25-foot Circle of Blindness with its exceptions
        // (folio 5)
    if (wrmFireBoxCubeFeet() != 10
            || wrmFireBoxElements() != 1
            || wrmDiminishHalving() != 1
            || wrmBlindnessRadiusFeet() != 25
            || wrmBlindnessExceptions() != 1
        )
            ++bad;
        // the elf sub-race band, row 0 of 3 - the Silvan 1-16, the Sindar
        // 17-19, the Noldor 20 on the d20 (folio 14)
    if (wrmElfSubraceMin(0) != 1
            || wrmElfSubraceMax(0) != 16
            || wrmElfSubraceCount() != 3
            || wrmElfTableDieSides() != 20
        )
            ++bad;
        // the elf sub-race band, row 1 of 3 - the Silvan 1-16, the Sindar
        // 17-19, the Noldor 20 on the d20 (folio 14)
    if (wrmElfSubraceMin(1) != 17
            || wrmElfSubraceMax(1) != 19
        )
            ++bad;
        // the elf sub-race band, row 2 of 3 - the Silvan 1-16, the Sindar
        // 17-19, the Noldor 20 on the d20 (folio 14)
    if (wrmElfSubraceMin(2) != 20
            || wrmElfSubraceMax(2) != 20
        )
            ++bad;
        // the elf table doctrines - the editorial endorsement in print, the
        // Tolkien-names boundary noted (folio 14)
    if (wrmElfTableEditorEndorsed() != 1
            || wrmElfTableTolkienNames() != 1
        )
            ++bad;
        printf("R905 witch remainders audit: bad %d\n", bad);
        if (bad) return 1;
    }
