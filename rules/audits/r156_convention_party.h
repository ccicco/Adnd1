    // ---- R156: convention party audit --------------------
    // DMG pp.225-226 Appendix P: rollMemberMagic gains its
    // first engine caller - rollConventionParty builds the
    // encounter-shaped party from caller-chosen classes, the
    // band/option level roll, and the R147 kit tables; the
    // member roller also lands the six 4d6-best-of scores.
    {
        int bad = 0;
        // the member roller: the level stays in the band,
        // the six scores stay in 3-18, the kit in 0-3, and
        // the class clamps
        {
            rules::Rng rngC(20261004);
            rules::Dice diceC(rngC);
            for (int b = 0; b < 3; ++b)
                for (int o = 0; o < 3; ++o)
                    for (int c = 0; c < 4; ++c)
                        for (int t = 0; t < 40; ++t) {
                            dm::appendixp::SpurMember m =
                                dm::appendixp::rollSpurMember(
                                    diceC, b, o, c);
                            if (m.classIndex != c) ++bad;
                            if (m.level <
                                    dm::appendixp::bandLevelLo(b, o)
                                || m.level >
                                    dm::appendixp::bandLevelHi(b, o))
                                ++bad;
                            for (int a = 0; a < 6; ++a)
                                if (m.abilities[a] < 3 ||
                                    m.abilities[a] > 18) ++bad;
                            if (m.kit.armorPlus < 0 ||
                                m.kit.armorPlus > 3 ||
                                m.kit.weaponPlus < 0 ||
                                m.kit.weaponPlus > 3 ||
                                m.kit.shieldPlus < 0 ||
                                m.kit.shieldPlus > 3) ++bad;
                        }
            dm::appendixp::SpurMember m9 =
                dm::appendixp::rollSpurMember(diceC, 0, 0, 9);
            if (m9.classIndex != 3) ++bad;
        }
        // the party generator: sizes clamp 1-9, each member
        // maps its replayed spur member (same seed = the
        // same dice stream), levels stay in the band, and a
        // null class list lands fighters
        {
            rules::Rng rngA(424242);
            rules::Dice diceA(rngA);
            int cls[5] = {0, 1, 2, 3, 1};
            dm::CharacterParty p =
                dm::rollConventionParty(diceA, 1, 1, cls, 5);
            if (p.size() != 5) ++bad;
            rules::Rng rngB(424242);
            rules::Dice diceB(rngB);
            for (int i = 0; i < 5; ++i) {
                dm::appendixp::SpurMember s =
                    dm::appendixp::rollSpurMember(
                        diceB, 1, 1, cls[i]);
                const dm::PartyMember& pm = p.members[i];
                if (pm.classIndex != s.classIndex ||
                    pm.level != s.level ||
                    pm.armPlus != s.kit.armorPlus ||
                    pm.wpnPlus != s.kit.weaponPlus ||
                    pm.shdPlus != s.kit.shieldPlus) ++bad;
                if (pm.level < 5 || pm.level > 8) ++bad;
            }
            dm::CharacterParty tiny =
                dm::rollConventionParty(diceA, 2, 2, nullptr, -3);
            if (tiny.size() != 1) ++bad;
            int cls9[12];
            for (int i = 0; i < 12; ++i) cls9[i] = i % 4;
            dm::CharacterParty big =
                dm::rollConventionParty(diceA, 0, 0, cls9, 12);
            if (big.size() != 9) ++bad;
            dm::CharacterParty nul =
                dm::rollConventionParty(diceA, 0, 2, nullptr, 3);
            for (int i = 0; i < 3; ++i)
                if (nul.members[i].classIndex != 0) ++bad;
        }
        printf("R156 convention party audit: bad %d\n", bad);
        if (bad) return 1;
    }
