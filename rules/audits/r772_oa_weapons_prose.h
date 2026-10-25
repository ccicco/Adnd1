    // ---- R772 OA Weapons prose audit ----
    // OA round one hundred fifty-nine (capture pp. 84-93): the weapons prose
    // - the forty-seven weapon descriptions pinned as the
    // essence-of-the-weapon doctrines, the tool-and-weapon duality, the ninja
    // concealment thread, and the mechanics consts of the chu-ko-nu magazine,
    // the needle burst die, the lasso pulls, the man catcher, the metsubishi,
    // the nekode climb bonus, the shuriken star points, and the tetsu-bishi
    // area rules (the descriptions re-captured at pp. 42-51 of the
    // compressed-3 re-upload)
    {
        using namespace rules;
        int bad = 0;
    if (dnjChuKoNuMagazineQuarrels() != 10
            || dnjChuKoNuReloadPerRound() != 2
            || dnjChuKoNuFullReloadRounds() != 5
            || dnjNeedleMouthCarryMax() != 20
            || dnjNeedleAllFiredDieSides() != 20
            || dnjShurikenStarPointMinimum() != 3
            || dnjNekodeClimbBonusPercent() != 5
            || dnjLassoLineCuttingDamage() != 2
            || dnjLassoBipedalPullPercent() != 25
            || dnjLassoExtraPullerBonusPercent() != 20
            || dnjManCatcherOffFeetPercent() != 25
            || dnjManCatcherHaftCuttingDamage() != 6
            || dnjMetsubishiIncapacitationMaxRounds() != 6
            || dnjTetsubishiBaseCount() != 10
            || dnjTetsubishiBaseAreaSquareFeet() != 25
            || dnjTetsubishiHalfCountSavePenalty() != 4
            || dnjTetsubishiPerFiveExtraSavePenalty() != 2
            || dnjTetsubishiStepDamageMax() != 4
            || dnjTetsubishiLameDurationHours() != 24
            || !dnjArrowsDoctrine()
            || !dnjBoStickDoctrine()
            || !dnjBokuTohDoctrine()
            || !dnjChainDoctrine()
            || !dnjChijirikiDoctrine()
            || !dnjChopsticksDoctrine()
            || !dnjChuKoNuDoctrine()
            || !dnjDaikyuDoctrine()
            || !dnjFangDoctrine()
            || !dnjGunsenDoctrine()
            || !dnjJitteDoctrine()
            || !dnjJoStickDoctrine()
            || !dnjKamaDoctrine()
            || !dnjKatanaDoctrine()
            || !dnjKatanaHonorDoctrine()
            || !dnjKauSinKeDoctrine()
            || !dnjKawanagaDoctrine()
            || !dnjKiseruDoctrine()
            || !dnjKumadeDoctrine()
            || !dnjKusariGamaDoctrine()
            || !dnjKyoketsuogiDoctrine()
            || !dnjLajatangDoctrine()
            || !dnjLassoDoctrine()
            || !dnjManCatcherDoctrine()
            || !dnjMetsubishiDoctrine()
            || !dnjNagimakiDoctrine()
            || !dnjNaginataDoctrine()
            || !dnjNeedleDoctrine()
            || !dnjNekodeDoctrine()
            || !dnjNinjaToDoctrine()
            || !dnjNunchakuDoctrine()
            || !dnjParangDoctrine()
            || !dnjPelletBowDoctrine()
            || !dnjSaiDoctrine()
            || !dnjSangKauwDoctrine()
            || !dnjShakenDoctrine()
            || !dnjShakujoYariDoctrine()
            || !dnjShikomiZueDoctrine()
            || !dnjShurikenDoctrine()
            || !dnjSiangkamDoctrine()
            || !dnjSodeGaramiDoctrine()
            || !dnjTetsubishiDoctrine()
            || !dnjTetsuboDoctrine()
            || !dnjThreePieceRodDoctrine()
            || !dnjTuiFaDoctrine()
            || !dnjUchiNeDoctrine()
            || !dnjWakizashiDoctrine()
            || !dnjWhipDoctrine()
        )
            ++bad;
        // the chu-ko-nu reload math - five rounds at two per round fills the
        // ten-quarrel magazine
    if (dnjChuKoNuFullReloadRounds() * dnjChuKoNuReloadPerRound() !=
        dnjChuKoNuMagazineQuarrels()
        )
            ++bad;
        // the needle burst die - all twenty fired at once roll the
        // twenty-sided die
    if (dnjNeedleAllFiredDieSides() != dnjNeedleMouthCarryMax()
        )
            ++bad;
        // the lasso pull math - the base chance minus the extra-puller bonus
        // is five
    if (dnjLassoBipedalPullPercent() - dnjLassoExtraPullerBonusPercent() != 5
        )
            ++bad;
        // the pull chances agree - the lasso and the man catcher both pull at
        // twenty-five
    if (dnjManCatcherOffFeetPercent() != dnjLassoBipedalPullPercent()
        )
            ++bad;
        // the tetsu-bishi save math - the halved-count penalty plus the
        // per-five penalty is six
    if (dnjTetsubishiHalfCountSavePenalty() +
        dnjTetsubishiPerFiveExtraSavePenalty() != 6
        )
            ++bad;
        // the tetsu-bishi lame watch - twenty-four hours is six times the
        // step damage maximum
    if (dnjTetsubishiLameDurationHours() != dnjTetsubishiStepDamageMax() * 6
        )
            ++bad;
        printf("R772 OA Weapons prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
