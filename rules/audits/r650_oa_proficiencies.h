    // ---- R650 OA proficiencies audit ----
    // OA round thirty-seven (capture pp. 99-101): the Chapter 6 opener - the
    // proficiency slot system and the weapon specialization doctrine with the
    // weapon restrictions
    {
        using namespace rules;
        int bad = 0;
    if (dhkSlotsAtFirstLevel() != 1
            || dhkWeaponProfSlotCost() != 1
            || dhkSpecMeleeSlots() != 2
            || dhkSpecMissileSlots() != 3
            || dhkMeleeSpecHit() != 1
            || dhkMeleeSpecDmg() != 2
            || dhkDoubleSpecSlotCost() != 1
            || dhkDoubleSpecHit() != 3
            || dhkDoubleSpecDmg() != 3
            || dhkBowPointBlankMin() != 5
            || dhkBowPointBlankMax() != 30
            || dhkBowPointBlankHit() != 2
            || dhkBowPointBlankDmg() != 2
            || dhkBowShortHit() != 1
            || dhkXbowPointBlankMin() != 5
            || dhkXbowPointBlankMax() != 60
            || dhkXbowShortHit() != 1
            || dhkXbowShortDmg() != 1
            || dhkXbowMediumHit() != 1
            || dhkOtherMissileHit() != 1
            || dhkOtherMissileDmg() != 2
            || dhkSpecFirstAttNum() != 3
            || dhkSpecFirstAttDen() != 2
            || dhkSpecFifthAttNum() != 2
            || dhkSpecFifthAttDen() != 1
            || dhkHeightLimitFeet() != 5
            || dhkWeaponLenLimitFeet() != 12
            || dhkDaikyuHeightFeet() != 4
            || dhkBodyWeightPounds() != 100
            || dhkHeavyWeaponGp() != 200
            || !dhkPeacefulAsImportant()
            || !dhkSlotsWeaponOrPeaceful()
            || !dhkSlotsSaveable()
            || !dhkNoChangeAfterSelection()
            || !dhkUnarmedNeedsMaster()
            || !dhkOnlySamuraiBushiSpec()
            || !dhkBushiOneWeapon()
            || !dhkSamuraiKatanaBow()
            || !dhkSpecSpecificType()
            || !dhkSpecGivesIaijutsu()
            || !dhkSpecNextAttackRank()
            || !dhkBowPointBlankDmgDoubled()
            || !dhkBowNoBonusBeyond()
            || !dhkBowReadyFiresFirst()
            || !dhkXbowPointBlankSame()
            || !dhkClassNonprofApplies()
            || !dhkProhibitionsOverride()
        )
            ++bad;
        // the slot-system pins - the 1st-level slots and the one-slot weapon
        // proficiency cost
    if (dhkSlotsAtFirstLevel() != 1
            || dhkWeaponProfSlotCost() != 1
        )
            ++bad;
        // the slot-rule pins - the fill, the saving and the no-change
        // doctrine
    if (dhkPeacefulAsImportant() != 1
            || dhkSlotsWeaponOrPeaceful() != 1
            || dhkSlotsSaveable() != 1
            || dhkNoChangeAfterSelection() != 1
        )
            ++bad;
        // the specialization slot-cost pins - two for melee or crossbow,
        // three for other missiles
    if (dhkSpecMeleeSlots() != 2
            || dhkSpecMissileSlots() != 3
        )
            ++bad;
        // the eligibility pins - samurai and bushi only, the unarmed master
        // rule, the bushi one-weapon rule, the katana-and-bow rule, the
        // specific-type rule
    if (dhkOnlySamuraiBushiSpec() != 1
            || dhkUnarmedNeedsMaster() != 1
            || dhkBushiOneWeapon() != 1
            || dhkSamuraiKatanaBow() != 1
            || dhkSpecSpecificType() != 1
        )
            ++bad;
        // the melee specialist bonus pins - +1 to hit, +2 damage
    if (dhkMeleeSpecHit() != 1
            || dhkMeleeSpecDmg() != 2
        )
            ++bad;
        // the attack-example pins - 3/2 at first level, 2/1 at fifth level
    if (dhkSpecFirstAttNum() != 3
            || dhkSpecFirstAttDen() != 2
            || dhkSpecFifthAttNum() != 2
            || dhkSpecFifthAttDen() != 1
        )
            ++bad;
        // the iaijutsu and next-attack-rank pins
    if (dhkSpecGivesIaijutsu() != 1
            || dhkSpecNextAttackRank() != 1
        )
            ++bad;
        // the double-specialization pins - one slot more, +3 to hit and
        // damage
    if (dhkDoubleSpecSlotCost() != 1
            || dhkDoubleSpecHit() != 3
            || dhkDoubleSpecDmg() != 3
        )
            ++bad;
        // the bow point-blank band pins - 5 to 30 feet, +2 to hit and damage
    if (dhkBowPointBlankMin() != 5
            || dhkBowPointBlankMax() != 30
            || dhkBowPointBlankHit() != 2
            || dhkBowPointBlankDmg() != 2
        )
            ++bad;
        // the bow doctrine pins - +1 at short range, the doubled base damage,
        // no bonus beyond, the ready auto-fire
    if (dhkBowShortHit() != 1
            || dhkBowPointBlankDmgDoubled() != 1
            || dhkBowNoBonusBeyond() != 1
            || dhkBowReadyFiresFirst() != 1
        )
            ++bad;
        // the crossbow pins - 5 to 60 feet point blank, +1/+1 short, +1
        // medium, the same benefits
    if (dhkXbowPointBlankMin() != 5
            || dhkXbowPointBlankMax() != 60
            || dhkXbowShortHit() != 1
            || dhkXbowShortDmg() != 1
            || dhkXbowMediumHit() != 1
            || dhkXbowPointBlankSame() != 1
        )
            ++bad;
        // the other-missile specialist pins - +1 to hit, +2 damage
    if (dhkOtherMissileHit() != 1
            || dhkOtherMissileDmg() != 2
        )
            ++bad;
        // the weapon-restriction pins - the class penalty applies and the
        // prohibitions override
    if (dhkClassNonprofApplies() != 1
            || dhkProhibitionsOverride() != 1
        )
            ++bad;
        // the bound pins - 5 feet against 12 feet, the 4-foot daikyu ban, 100
        // pounds against 200 gp
    if (dhkHeightLimitFeet() != 5
            || dhkWeaponLenLimitFeet() != 12
            || dhkDaikyuHeightFeet() != 4
            || dhkBodyWeightPounds() != 100
            || dhkHeavyWeaponGp() != 200
        )
            ++bad;
        printf("R650 OA proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
