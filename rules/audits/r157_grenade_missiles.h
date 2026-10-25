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
        int bad = 0;
        // sizes and names
        static const int kOz[5] = { 8, 4, 4, 16, 4 };
        for (int k = 0; k < 5; ++k) {
            if (rules::grenadeSizeOz((rules::GrenadeKind)k)
                != kOz[k]) ++bad;
            if (!*rules::grenadeName((rules::GrenadeKind)k))
                ++bad;
        }
        // the effect table
        static const int kDLo[5] = { 2, 2, 2, 2, 0 };
        static const int kDHi[5] = { 8, 7, 7, 12, 0 };
        static const int kDia[5] = { 1, 1, 1, 3, 1 };
        static const int kSLo[5] = { 1, 2, 2, 1, 0 };
        static const int kSHi[5] = { 1, 2, 2, 3, 0 };
        for (int k = 0; k < 5; ++k) {
            int lo, hi;
            rules::grenadeDirectHit((rules::GrenadeKind)k, lo, hi);
            if (lo != kDLo[k] || hi != kDHi[k]) ++bad;
            rules::grenadeSplashDamage(
                (rules::GrenadeKind)k, lo, hi);
            if (lo != kSLo[k] || hi != kSHi[k]) ++bad;
            if (rules::grenadeSplashDiameterFeet(
                    (rules::GrenadeKind)k) != kDia[k]) ++bad;
        }
        // oil: the second-round burn + the segment burn
        int olo, ohi;
        rules::grenadeOilSecondRound(olo, ohi);
        if (olo != 1 || ohi != 6) ++bad;
        if (rules::grenadeOilBurnSegmentsMax() != 3 ||
            rules::grenadeOilBurnDamagePerSegment() != 1)
            ++bad;
        // the splash-save radius
        if (rules::grenadeSplashRadiusFeet() != 3) ++bad;
        // range bands
        if (rules::grenadeRangeMaxInches() != 3) ++bad;
        if (rules::grenadeRangeToHitAdj(1) != 0 ||
            rules::grenadeRangeToHitAdj(2) != -2 ||
            rules::grenadeRangeToHitAdj(3) != -5) ++bad;
        // the break saves (the p.80 matrix rows)
        static const int kCrush[5] = { 18, 19, 19, 18, 19 };
        static const int kNorm[5]  = { 12, 14, 14, 12, 14 };
        for (int k = 0; k < 5; ++k) {
            if (rules::grenadeBreakSaveCrushing(
                    (rules::GrenadeKind)k) != kCrush[k] ||
                rules::grenadeBreakSaveNormal(
                    (rules::GrenadeKind)k) != kNorm[k]) ++bad;
        }
        // the miss tables: distance dice + direction cone
        {
            rules::Rng rngG(20261005);
            rules::Dice diceG(rngG);
            for (int t = 0; t < 500; ++t) {
                int d6 = rules::grenadeMissDistance(diceG, false);
                int d4 = rules::grenadeMissDistance(diceG, true);
                int dir = rules::grenadeMissDirection(diceG);
                if (d6 < 1 || d6 > 6) ++bad;
                if (d4 < 1 || d4 > 4) ++bad;
                if (dir < 1 || dir > 8) ++bad;
                if (!*rules::grenadeMissDirectionName(dir))
                    ++bad;
            }
            std::string n1 = rules::grenadeMissDirectionName(1);
            std::string n4 = rules::grenadeMissDirectionName(4);
            std::string n5 = rules::grenadeMissDirectionName(5);
            std::string n8 = rules::grenadeMissDirectionName(8);
            if (n1 != "long right" || n4 != "short (before)" ||
                n5 != "short left" || n8 != "long (over)")
                ++bad;
        }
        // holy/unholy water targeting (p.65)
        if (!rules::holyWaterAffects(true, true, true) ||
            !rules::holyWaterAffects(true, false, true) ||
            !rules::holyWaterAffects(false, true, true) ||
            rules::holyWaterAffects(false, false, true) ||
            rules::holyWaterAffects(true, true, false))
            ++bad;
        if (!rules::unholyWaterAffects(true, true) ||
            rules::unholyWaterAffects(false, true) ||
            rules::unholyWaterAffects(true, false))
            ++bad;
        // crossing flaming oil + the vial cost
        int wlo, whi;
        rules::flamingOilWalkDamage(wlo, whi);
        if (wlo != 1 || whi != 6) ++bad;
        if (rules::grenadeVialCostLo() != 2 ||
            rules::grenadeVialCostHi() != 5) ++bad;
        // boulders: diameters + the drop window
        if (rules::grenadeBoulderDiameterFeet(false) != 1 ||
            rules::grenadeBoulderDiameterFeet(true) != 2)
            ++bad;
        if (rules::grenadeBoulderDropDamage(14, 10) != 10 ||
            rules::grenadeBoulderDropDamage(14, 60) != 60 ||
            rules::grenadeBoulderDropDamage(14, 100) != 60 ||
            rules::grenadeBoulderDropDamage(28, 30) != 60 ||
            rules::grenadeBoulderDropDamage(14, 5) != 10 ||
            rules::grenadeBoulderDropDamage(13, 60) != 0)
            ++bad;
        // roller smoke: bounds sweeps
        {
            rules::Rng rngH(777);
            rules::Dice diceH(rngH);
            for (int t = 0; t < 400; ++t) {
                for (int k = 0; k < 5; ++k) {
                    int lo, hi;
                    rules::grenadeDirectHit(
                        (rules::GrenadeKind)k, lo, hi);
                    int v = rules::rollGrenadeDirectHit(
                        diceH, (rules::GrenadeKind)k);
                    if (v < lo || v > hi) ++bad;
                    rules::grenadeSplashDamage(
                        (rules::GrenadeKind)k, lo, hi);
                    int s = rules::rollGrenadeSplashDamage(
                        diceH, (rules::GrenadeKind)k);
                    if (s < lo || s > hi) ++bad;
                }
                int o = rules::rollGrenadeOilSecondRound(diceH);
                if (o < 1 || o > 6) ++bad;
                int w = rules::rollFlamingOilWalkDamage(diceH);
                if (w < 1 || w > 6) ++bad;
                int b = rules::rollGrenadeBoulderFlatDamage(
                    diceH, 28);
                if (b < 2 || b > 12) ++bad;
                if (rules::rollGrenadeBoulderFlatDamage(
                        diceH, 13) != 0) ++bad;
            }
        }
        printf("R157 grenade missiles audit: bad %d\n", bad);
        if (bad) return 1;
    }
