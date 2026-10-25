    // ---- R616 OA ability prose audit ----
    // OA round three (capture pp. 8-15): the six ability prose sub-items -
    // the prime requisites and column explanations, the Constitution revival
    // ledger, the Comeliness reaction bands with the smitten doctrine and the
    // magic caps.
    {
        using namespace rules;
        int bad = 0;
    if (dgcComBaseDie() != 3
            || dgcComHumanMin() != -2
            || dgcComHumanMax() != 23
            || dgcComRacialKorobokuru() != -2
            || dgcComRacialHengeyokai() != -1
            || dgcComRacialSpiritFolk() != 1
            || dgcBandHorrorMax() != -16
            || dgcBandDisgustMax() != -9
            || dgcBandAversionMax() != 0
            || dgcBandUglyMax() != 6
            || dgcBandHomelyMax() != 9
            || dgcBandPlainMax() != 13
            || dgcBandGoodlookingMin() != 14
            || dgcBandGoodlookingMax() != 17
            || dgcBandBeautifulMin() != 18
            || dgcBandBeautifulMax() != 21
            || dgcBandBeautifulPct() != 150
            || dgcBandStunningMin() != 22
            || dgcBandStunningMax() != 25
            || dgcBandUnearthlyMin() != 28
            || dgcBandUnearthlyMax() != 30
            || dgcComPolymorphCap() != 2
            || !dgcDexPrime()
            || !dgcDexMissileAndSurprise()
            || !dgcDexDefensiveDodge()
            || !dgcConRevivalLimit()
            || !dgcConRestoreNoRefund()
            || !dgcConShockSecondRoll()
            || !dgcConResurrectionFail()
            || !dgcIntPrime()
            || !dgcIntSpellGate()
            || !dgcWisPrime()
            || !dgcWisBonusSpells()
            || !dgcChaHenchmenPaid()
            || !dgcComCharismaTracks()
            || !dgcComRacialOtherRaceOnly()
            || !dgcBandGoodlookingReactionAdd()
            || !dgcBandBeautifulSmitten()
            || !dgcBandRejectionHalfNegative()
            || !dgcBandStunningReactionTwice()
            || !dgcBandStunningSmitten()
            || !dgcBandUnearthlySave()
            || !dgcSmittenFascinate()
            || !dgcSmittenNonmagical()
            || !dgcSmittenOrderRoll()
            || !dgcSmittenNotPuppet()
            || !dgcSmittenBadTreatmentNegative()
            || !dgcComTemporary()
            || !dgcComIllusionCapOne()
            || !dgcComShapechangeFull()
        )
            ++bad;
        // the dgcDexPrime pin
    if (dgcDexPrime() != 1
        )
            ++bad;
        // the dgcDexMissileAndSurprise pin
    if (dgcDexMissileAndSurprise() != 1
        )
            ++bad;
        // the dgcDexDefensiveDodge pin
    if (dgcDexDefensiveDodge() != 1
        )
            ++bad;
        // the dgcConRevivalLimit pin
    if (dgcConRevivalLimit() != 1
        )
            ++bad;
        // the dgcConRestoreNoRefund pin
    if (dgcConRestoreNoRefund() != 1
        )
            ++bad;
        // the dgcConShockSecondRoll pin
    if (dgcConShockSecondRoll() != 1
        )
            ++bad;
        // the dgcConResurrectionFail pin
    if (dgcConResurrectionFail() != 1
        )
            ++bad;
        // the dgcIntPrime pin
    if (dgcIntPrime() != 1
        )
            ++bad;
        // the dgcIntSpellGate pin
    if (dgcIntSpellGate() != 1
        )
            ++bad;
        // the dgcWisPrime pin
    if (dgcWisPrime() != 1
        )
            ++bad;
        // the dgcWisBonusSpells pin
    if (dgcWisBonusSpells() != 1
        )
            ++bad;
        // the dgcChaHenchmenPaid pin
    if (dgcChaHenchmenPaid() != 1
        )
            ++bad;
        // the dgcComBaseDie pin
    if (dgcComBaseDie() != 3
        )
            ++bad;
        // the dgcComHumanMin pin
    if (dgcComHumanMin() != -2
        )
            ++bad;
        // the dgcComHumanMax pin
    if (dgcComHumanMax() != 23
        )
            ++bad;
        // the dgcComCharismaTracks pin
    if (dgcComCharismaTracks() != 1
        )
            ++bad;
        // the dgcComRacialOtherRaceOnly pin
    if (dgcComRacialOtherRaceOnly() != 1
        )
            ++bad;
        // the dgcComRacialKorobokuru pin
    if (dgcComRacialKorobokuru() != -2
        )
            ++bad;
        // the dgcComRacialHengeyokai pin
    if (dgcComRacialHengeyokai() != -1
        )
            ++bad;
        // the dgcComRacialSpiritFolk pin
    if (dgcComRacialSpiritFolk() != 1
        )
            ++bad;
        // the dgcBandHorrorMax pin
    if (dgcBandHorrorMax() != -16
        )
            ++bad;
        // the dgcBandDisgustMax pin
    if (dgcBandDisgustMax() != -9
        )
            ++bad;
        // the dgcBandAversionMax pin
    if (dgcBandAversionMax() != 0
        )
            ++bad;
        // the dgcBandUglyMax pin
    if (dgcBandUglyMax() != 6
        )
            ++bad;
        // the dgcBandHomelyMax pin
    if (dgcBandHomelyMax() != 9
        )
            ++bad;
        // the dgcBandPlainMax pin
    if (dgcBandPlainMax() != 13
        )
            ++bad;
        // the dgcBandGoodlookingMin pin
    if (dgcBandGoodlookingMin() != 14
        )
            ++bad;
        // the dgcBandGoodlookingMax pin
    if (dgcBandGoodlookingMax() != 17
        )
            ++bad;
        // the dgcBandGoodlookingReactionAdd pin
    if (dgcBandGoodlookingReactionAdd() != 1
        )
            ++bad;
        // the dgcBandBeautifulMin pin
    if (dgcBandBeautifulMin() != 18
        )
            ++bad;
        // the dgcBandBeautifulMax pin
    if (dgcBandBeautifulMax() != 21
        )
            ++bad;
        // the dgcBandBeautifulPct pin
    if (dgcBandBeautifulPct() != 150
        )
            ++bad;
        // the dgcBandBeautifulSmitten pin
    if (dgcBandBeautifulSmitten() != 1
        )
            ++bad;
        // the dgcBandRejectionHalfNegative pin
    if (dgcBandRejectionHalfNegative() != 1
        )
            ++bad;
        // the dgcBandStunningMin pin
    if (dgcBandStunningMin() != 22
        )
            ++bad;
        // the dgcBandStunningMax pin
    if (dgcBandStunningMax() != 25
        )
            ++bad;
        // the dgcBandStunningReactionTwice pin
    if (dgcBandStunningReactionTwice() != 1
        )
            ++bad;
        // the dgcBandStunningSmitten pin
    if (dgcBandStunningSmitten() != 1
        )
            ++bad;
        // the dgcBandUnearthlyMin pin
    if (dgcBandUnearthlyMin() != 28
        )
            ++bad;
        // the dgcBandUnearthlyMax pin
    if (dgcBandUnearthlyMax() != 30
        )
            ++bad;
        // the dgcBandUnearthlySave pin
    if (dgcBandUnearthlySave() != 1
        )
            ++bad;
        // the dgcSmittenFascinate pin
    if (dgcSmittenFascinate() != 1
        )
            ++bad;
        // the dgcSmittenNonmagical pin
    if (dgcSmittenNonmagical() != 1
        )
            ++bad;
        // the dgcSmittenOrderRoll pin
    if (dgcSmittenOrderRoll() != 1
        )
            ++bad;
        // the dgcSmittenNotPuppet pin
    if (dgcSmittenNotPuppet() != 1
        )
            ++bad;
        // the dgcSmittenBadTreatmentNegative pin
    if (dgcSmittenBadTreatmentNegative() != 1
        )
            ++bad;
        // the dgcComTemporary pin
    if (dgcComTemporary() != 1
        )
            ++bad;
        // the dgcComIllusionCapOne pin
    if (dgcComIllusionCapOne() != 1
        )
            ++bad;
        // the dgcComPolymorphCap pin
    if (dgcComPolymorphCap() != 2
        )
            ++bad;
        // the dgcComShapechangeFull pin
    if (dgcComShapechangeFull() != 1
        )
            ++bad;
        // the disgust band spans its seven scores above the horror floor
        // (capture pp. 13-14)
    if (dgcBandDisgustMax() - dgcBandHorrorMax() != 7
        )
            ++bad;
        // the printed 150 percent beautiful-band reaction (capture p. 14)
    if (dgcBandBeautifulPct() != 150
        )
            ++bad;
        // the stunning band doubles the score - the printed 22-to-44 example
        // (capture p. 14)
    if (dgcBandStunningMin() * 2 != 44
        )
            ++bad;
        // the human Comeliness range spans the ladder (capture p. 13)
    if (dgcComHumanMax() - dgcComHumanMin() != 25
        )
            ++bad;
        // the polymorph cap doubles the illusion cap (capture p. 15)
    if (dgcComPolymorphCap() != dgcComIllusionCapOne() * 2
        )
            ++bad;
        // the unearthly band sits above the stunning band with the printed
        // 26-27 hole (capture p. 14)
    if (dgcBandUnearthlyMin() - dgcBandStunningMax() != 3
        )
            ++bad;
        printf("R616 OA ability prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
