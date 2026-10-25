    // ---- R480 WSG injuries treatment pin audit ----
    // The injuries and treatment rules: the broken bone (the splint aligns
    // the ends and makes healing possible, no hit points regained until
    // splinted, using the injured extremity even while splinted costs an
    // immediate 1d6 and neutralizes all healing to that time, the broken bone
    // heals last, most other injuries heal before it is mended), the minor
    // burn (deprive the area of air by immersing in water for at least two
    // turns or wrapping tightly with a clean cloth for normal 1-per-day
    // healing, otherwise a -1 pain penalty on attacks and saves and healing
    // at half speed), the major burn (more than half the body burned, treated
    // as above plus rest until at least half the lost hit points are
    // regained, voluntary activity forfeits all regained points and costs 1d4
    // per round, the pain penalty is -3 instead of -1, the victim can still
    // ride or be carried), the major wound (an edged melee weapon with an
    // unmodified damage roll of 6 or higher, at the DM discretion or on a 25%
    // chance an artery struck, 2-4 as 1d3+1 hit points per round of severe
    // bleeding until tended, pressure applied directly for 2-7 consecutive
    // rounds as 1d6+1 at 1 hit point lost per round meanwhile, wrapping halts
    // the bleeding but recovery needs a healer with the healing proficiency,
    // releasing the pressure early negates the first aid and the bleeding
    // begins again for another 2-7 rounds with the DM free to use the
    // original result or roll again), and the minor wound (any skin-breaking
    // wound is assumed bandaged at the first available opportunity).
    {
        using namespace rules;
        int bad = 0;
    if (wtrInjuryTypeCount() != 5
            || wtrBurnImmerseMinTurns() != 2
            || wtrHealPerDay() != 1
            || wtrMinorPainPenalty() != 1
            || wtrMajorPainPenalty() != 3
            || wtrHalfNum() != 1
            || wtrHalfDen() != 2
            || wtrMajorActivityDice() != 1
            || wtrMajorActivitySides() != 4
            || wtrSplintUseDice() != 1
            || wtrSplintUseSides() != 6
            || wtrArteryMinDamage() != 6
            || wtrArteryChance() != 25
            || wtrBleedMin() != 2
            || wtrBleedMax() != 4
            || wtrBleedDice() != 1
            || wtrBleedSides() != 3
            || wtrBleedPlus() != 1
            || wtrPressureMin() != 2
            || wtrPressureMax() != 7
            || wtrPressureDice() != 1
            || wtrPressureSides() != 6
            || wtrPressurePlus() != 1
            || wtrPressureHpLoss() != 1
            || !wtrFirstAidCommonKnowledge()
            || !wtrDmRulesSpecificInjury()
            || !wtrSplintAlignsBone()
            || !wtrSplintRequiredToHeal()
            || !wtrSplintUseExtraDamage()
            || !wtrSplintUseNeutralizesHealing()
            || !wtrBrokenBoneHealsLast()
            || !wtrBurnAirDeprivedHeals()
            || !wtrMinorBurnHalfHealUnprotected()
            || !wtrMajorBurnRestRequired()
            || !wtrMajorBurnForfeitRegained()
            || !wtrMajorBurnCanBeCarried()
            || !wtrMajorWoundEdgedOnly()
            || !wtrMajorWoundDmDiscretion()
            || !wtrBleedingStemmedByPressure()
            || !wtrWrappingHaltsButNeedsHealer()
            || !wtrPressureReleaseNegates()
            || !wtrDmMayRerollPressure()
            || !wtrMinorWoundBandageAssumed()
        )
            ++bad;
        // the five injuries, and the major burn bar: more than half the body,
        // rest until half the points
    if (wtrInjuryTypeCount() != 5
            || wtrHalfDen() != 2 * wtrHalfNum()
        )
            ++bad;
        // the severe bleeding: 2-4 hit points per round as 1d3 + 1
    if (wtrBleedDice() + wtrBleedPlus() != wtrBleedMin()
            || wtrBleedSides() + wtrBleedPlus() != wtrBleedMax()
        )
            ++bad;
        // the pressure duration: 2-7 consecutive rounds as 1d6 + 1
    if (wtrPressureDice() + wtrPressurePlus() != wtrPressureMin()
            || wtrPressureSides() + wtrPressurePlus() != wtrPressureMax()
        )
            ++bad;
        // the pain penalties: the major burn is -3, exactly three times the
        // minor -1
    if (wtrMajorPainPenalty() != 3 * wtrMinorPainPenalty()
            || wtrMinorPainPenalty() != 1
        )
            ++bad;
        // the artery trigger: an unmodified damage roll of 6 or higher, on a
        // 25% chance
    if (wtrArteryMinDamage() != 6
            || wtrArteryChance() != 25
        )
            ++bad;
        // the treatment clocks: two turns of immersion, 1 point per day of
        // healing, 1 point lost per round of applied pressure, the 1d6 and
        // the 1d4
    if (wtrBurnImmerseMinTurns() != 2
            || wtrHealPerDay() != 1
            || wtrPressureHpLoss() != 1
            || wtrSplintUseDice() != 1
            || wtrSplintUseSides() != 6
            || wtrMajorActivityDice() != 1
            || wtrMajorActivitySides() != 4
        )
            ++bad;
        printf("R480 WSG injuries treatment pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
