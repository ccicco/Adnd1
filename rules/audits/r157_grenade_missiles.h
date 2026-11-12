    // ---- R157: grenade-like missiles audit ---------------
    // DMG pp.64-65: the thrown-flask layer - container
    // sizes, the effect table (direct-hit and splash dice
    // pairs), the 3-inch range bands, the item-save break
    // rule (the p.80 matrix rows: ceramic flask 18/12,
    // crystal vial 19/14), the 3-foot splash-save radius,
    // the d6/d8 miss tables (the direction cone), the p.65
    // holy/unholy water targeting, the flaming-oil
    // crossing damage, the 2-5 gp vial cost and the p.64
    // boulder drops.
    {
        Grenade grenade;
        int bad = 0;
        // sizes and names
        static const int kOz[5] = { 8, 4, 4, 16, 4 };
        for (int k = 0; k < 5; ++k) {
            Grenade grenade;
            if (grenade.sizeOz((GrenadeKind)k)
                != kOz[k]) ++bad;
            if (!*grenade.name((GrenadeKind)k))
                ++bad;
        }
        // the effect table
        static const int kDLo[5] = { 2, 2, 2, 2, 0 };
        static const int kDHi[5] = { 8, 7, 7, 12, 0 };
        static const int kDia[5] = { 1, 1, 1, 3, 1 };
        static const int kSLo[5] = { 1, 2, 2, 1, 0 };
        static const int kSHi[5] = { 1, 2, 2, 3, 0 };
        for (int k = 0; k < 5; ++k) {
            Grenade grenade;
            int lo, hi;
            grenade.directHit((GrenadeKind)k, lo, hi);
            if (lo != kDLo[k] || hi != kDHi[k]) ++bad;
            grenade.splashDamage(
                (GrenadeKind)k, lo, hi);
            if (lo != kSLo[k] || hi != kSHi[k]) ++bad;
            if (grenade.splashDiameterFeet(
                    (GrenadeKind)k) != kDia[k]) ++bad;
        }
        // oil: the second-round burn + the segment burn
        int olo, ohi;
        grenade.oilSecondRound(olo, ohi);
        if (olo != 1 || ohi != 6) ++bad;
        if (grenade.oilBurnSegmentsMax() != 3 ||
            grenade.oilBurnDamagePerSegment() != 1)
            ++bad;
        // the splash-save radius
        if (grenade.splashRadiusFeet() != 3) ++bad;
        // range bands
        if (grenade.rangeMaxInches() != 3) ++bad;
        if (grenade.rangeToHitAdj(1) != 0 ||
            grenade.rangeToHitAdj(2) != -2 ||
            grenade.rangeToHitAdj(3) != -5) ++bad;
        // the break saves (the p.80 matrix rows)
        static const int kCrush[5] = { 18, 19, 19, 18, 19 };
        static const int kNorm[5]  = { 12, 14, 14, 12, 14 };
        for (int k = 0; k < 5; ++k) {
            Grenade grenade;
            if (grenade.breakSaveCrushing(
                    (GrenadeKind)k) != kCrush[k] ||
                grenade.breakSaveNormal(
                    (GrenadeKind)k) != kNorm[k]) ++bad;
        }
        // the miss tables: distance dice + direction cone
        {
            Grenade grenade;
            rules::Rng rngG(20261005);
            rules::Dice diceG(rngG);
            for (int t = 0; t < 500; ++t) {
                Grenade grenade;
                int d6 = grenade.missDistance(diceG, false);
                int d4 = grenade.missDistance(diceG, true);
                int dir = grenade.missDirection(diceG);
                if (d6 < 1 || d6 > 6) ++bad;
                if (d4 < 1 || d4 > 4) ++bad;
                if (dir < 1 || dir > 8) ++bad;
                if (!*grenade.missDirectionName(dir))
                    ++bad;
            }
            std::string n1 = grenade.missDirectionName(1);
            std::string n4 = grenade.missDirectionName(4);
            std::string n5 = grenade.missDirectionName(5);
            std::string n8 = grenade.missDirectionName(8);
            if (n1 != "long right" || n4 != "short (before)" ||
                n5 != "short left" || n8 != "long (over)")
                ++bad;
        }
        // holy/unholy water targeting (p.65)
        if (!grenade.holyWaterAffects(true, true, true) ||
            !grenade.holyWaterAffects(true, false, true) ||
            !grenade.holyWaterAffects(false, true, true) ||
            grenade.holyWaterAffects(false, false, true) ||
            grenade.holyWaterAffects(true, true, false))
            ++bad;
        if (!grenade.unholyWaterAffects(true, true) ||
            grenade.unholyWaterAffects(false, true) ||
            grenade.unholyWaterAffects(true, false))
            ++bad;
        // crossing flaming oil + the vial cost
        int wlo, whi;
        grenade.flamingOilWalkDamage(wlo, whi);
        if (wlo != 1 || whi != 6) ++bad;
        if (grenade.vialCostLo() != 2 ||
            grenade.vialCostHi() != 5) ++bad;
        // boulders: diameters + the drop window
        if (grenade.boulderDiameterFeet(false) != 1 ||
            grenade.boulderDiameterFeet(true) != 2)
            ++bad;
        if (grenade.boulderDropDamage(14, 10) != 10 ||
            grenade.boulderDropDamage(14, 60) != 60 ||
            grenade.boulderDropDamage(14, 100) != 60 ||
            grenade.boulderDropDamage(28, 30) != 60 ||
            grenade.boulderDropDamage(14, 5) != 10 ||
            grenade.boulderDropDamage(13, 60) != 0)
            ++bad;
        // roller smoke: bounds sweeps
        {
            rules::Rng rngH(777);
            rules::Dice diceH(rngH);
            for (int t = 0; t < 400; ++t) {
                Grenade grenade;
                for (int k = 0; k < 5; ++k) {
                    Grenade grenade;
                    int lo, hi;
                    grenade.directHit(
                        (GrenadeKind)k, lo, hi);
                    int v = grenade.rollGrenadeDirectHit(
                        diceH, (GrenadeKind)k);
                    if (v < lo || v > hi) ++bad;
                    grenade.splashDamage(
                        (GrenadeKind)k, lo, hi);
                    int s = grenade.rollGrenadeSplashDamage(
                        diceH, (GrenadeKind)k);
                    if (s < lo || s > hi) ++bad;
                }
                int o = grenade.rollGrenadeOilSecondRound(diceH);
                if (o < 1 || o > 6) ++bad;
                int w = grenade.rollFlamingOilWalkDamage(diceH);
                if (w < 1 || w > 6) ++bad;
                int b = grenade.rollGrenadeBoulderFlatDamage(
                    diceH, 28);
                if (b < 2 || b > 12) ++bad;
                if (grenade.rollGrenadeBoulderFlatDamage(
                        diceH, 13) != 0) ++bad;
            }
        }
        printf("R157 grenade missiles audit: bad %d\n", bad);
        if (bad) return 1;
    }
