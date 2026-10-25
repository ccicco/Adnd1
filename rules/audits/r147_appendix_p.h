    // ---- R147: Appendix P audit ----
    // DMG pp.225-226: every table cell pinned (level
    // bands, protective + weapon percentages per class,
    // potion rows), Gonzo's worked example (15%/level
    // chain at 9th = 135; +2 chance 9 + 45 = 54, rolled
    // 51 -> at least +2; +3 check 9, rolled 99 -> just
    // +2), band sweeps, and the kit smoke (2000 members,
    // level 9, class i%4, seed 20261003 - floors arm
    // 1200 / shield 600 / weapon 1500).
    {
        int bad = 0;
        static const int kLo[3][3] = {
            { 1, 1, 2 }, { 5, 5, 7 }, { 8, 8, 9 },
        };
        static const int kHi[3][3] = {
            { 2, 3, 4 }, { 7, 8, 9 }, { 10, 11, 12 },
        };
        for (int b = 0; b < 3; ++b)
            for (int o = 0; o < 3; ++o) {
                if (dm::appendixp::bandLevelLo(b, o)
                    != kLo[b][o]) ++bad;
                if (dm::appendixp::bandLevelHi(b, o)
                    != kHi[b][o]) ++bad;
            }
        static const int kProt[4][7] = {
            { 10, 6, 8, 10, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 15, 4 },
            { 10, 5, 6, 8, 0, 2, 0 },
            { 0, 0, 0, 0, 10, 4, 0 },
        };
        for (int c = 0; c < 4; ++c)
            for (int k = 0; k < 7; ++k)
                if (dm::appendixp::protectivePct(c, k)
                    != kProt[c][k]) ++bad;
        static const int kWpn[4][7] = {
            { 10, 10, 0, 7, 8, 1, 10 },
            { 15, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 12, 0, 0, 0, 0 },
            { 12, 11, 0, 0, 0, 0, 0 },
        };
        for (int c = 0; c < 4; ++c)
            for (int k = 0; k < 7; ++k)
                if (dm::appendixp::weaponPct(c, k)
                    != kWpn[c][k]) ++bad;
        static const int kPot[4][2] = {
            { 8, 1 }, { 10, 3 }, { 6, 1 }, { 9, 2 },
        };
        for (int c = 0; c < 4; ++c) {
            if (dm::appendixp::potionPct(c)
                != kPot[c][0]) ++bad;
            if (dm::appendixp::potionMax(c)
                != kPot[c][1]) ++bad;
        }
        for (int p = 1; p <= 10; ++p)
            if (!*dm::appendixp::potionType(p)) ++bad;
        if (dm::appendixp::itemChancePct(15, 9)
            != 135) ++bad;
        if (dm::appendixp::plusTwoChancePct(15, 9)
            != 54) ++bad;
        if (dm::appendixp::plusThreeChancePct(9)
            != 9) ++bad;
        {
            rules::Rng rngP(20261003);
            rules::Dice diceP(rngP);
            for (int i = 0; i < 200; ++i) {
                int v = dm::appendixp::abilityRoll(diceP);
                if (v < 3 || v > 18) ++bad;
            }
            int items = 0, plus2 = 0, plus3 = 0;
            for (int i = 0; i < 4000; ++i) {
                int p = dm::appendixp::rollItemPlus(
                    diceP, 15, 9);
                if (p > 0) ++items;
                if (p >= 2) ++plus2;
                if (p == 3) ++plus3;
            }
            if (items != 4000) ++bad;
            if (plus2 < 1900 || plus2 > 2420) ++bad;
            if (plus3 < 100 || plus3 > 300) ++bad;
            int arm = 0, shd = 0, wpn = 0;
            for (int i = 0; i < 2000; ++i) {
                dm::appendixp::MemberMagic m =
                    dm::appendixp::rollMemberMagic(
                        diceP, i % 4, 9);
                if (m.armorPlus > 0) ++arm;
                if (m.shieldPlus > 0) ++shd;
                if (m.weaponPlus > 0) ++wpn;
            }
            if (arm < 1200) ++bad;
            if (shd < 600) ++bad;
            if (wpn < 1500) ++bad;
        }
        printf("R147 Appendix P audit: bad %d\n", bad);
        if (bad) return 1;
    }
