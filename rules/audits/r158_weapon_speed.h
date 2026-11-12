    // ---- R158: weapon speed factors audit ---------------
    // DMG p.66 + the PHB p.38 factor column: the tie order
    // (lower factor first), the extra-attacks windows, and
    // the weapon-vs-spell strike segment (factor minus the
    // losing initiative die, negatives as positive).
    {
        Weaponspeed weaponspeed;
        int bad = 0;
        // the named factor table (PHB p.38 + the DMG examples)
        static const char* const kN[9] = {
            "fist", "dagger", "short sword", "hammer",
            "long sword", "broad sword", "two-handed sword",
            "pike", "quarterstaff"
        };
        static const int kSf[9] = { 1, 2, 3, 4, 5, 5, 10, 13, 4 };
        for (int i = 0; i < 9; ++i) {
            Weaponspeed weaponspeed;
            if (weaponspeed.weaponSpeedFactor(kN[i]) != kSf[i])
                ++bad;
        }
        static const char* const kN2[8] = {
            "club", "hand axe", "scimitar", "horseman mace",
            "horseman flail", "footman mace", "footman flail",
            "morning star"
        };
        static const int kSf2[8] = { 4, 4, 4, 6, 6, 7, 7, 7 };
        for (int i = 0; i < 8; ++i) {
            Weaponspeed weaponspeed;
            if (weaponspeed.weaponSpeedFactor(kN2[i]) != kSf2[i])
                ++bad;
        }
        if (weaponspeed.weaponSpeedFactor("spear") != 7) ++bad;
        if (weaponspeed.weaponSpeedFactor("no such weapon") != 0)
            ++bad;
        // R780: the three lances ride the ladder (the
        // PHB p.38 speed cells, checked against the
        // header pins)
        if (weaponspeed.weaponSpeedFactor(
                "lance, light horse")
            != rules::lspLightLanceSpeedFactor()) ++bad;
        if (weaponspeed.weaponSpeedFactor(
                "lance, medium horse")
            != rules::lspMediumLanceSpeedFactor())
            ++bad;
        if (weaponspeed.weaponSpeedFactor(
                "lance, heavy horse")
            != rules::lspHeavyLanceSpeedFactor()) ++bad;
        // the spear 6-8 print range
        int rlo, rhi;
        weaponspeed.spearSpeedFactorRange(rlo, rhi);
        if (rlo != 6 || rhi != 8) ++bad;
        // case 1: the DMG example chain (lower strikes first)
        if (weaponspeed.speedFactorFirst(1, 2) != -1 ||
            weaponspeed.speedFactorFirst(2, 3) != -1 ||
            weaponspeed.speedFactorFirst(3, 4) != -1 ||
            weaponspeed.speedFactorFirst(4, 1) != 1 ||
            weaponspeed.speedFactorFirst(5, 5) != 0) ++bad;
        // case 2: the extra-attack windows
        if (weaponspeed.speedFactorAttacksBefore(1, 2) != 1 ||
            weaponspeed.speedFactorAttacksBefore(2, 4) != 1 ||
            weaponspeed.speedFactorAttacksBefore(1, 4) != 2 ||
            weaponspeed.speedFactorAttacksBefore(3, 10) != 2 ||
            weaponspeed.speedFactorAttacksBefore(5, 10) != 2 ||
            weaponspeed.speedFactorAttacksBefore(2, 13) != 3 ||
            weaponspeed.speedFactorAttacksBefore(2, 12) != 3 ||
            weaponspeed.speedFactorAttacksBefore(5, 5) != 1) ++bad;
        // case 2: closing/charging exemption
        if (weaponspeed.speedFactorApplies(true) ||
            !weaponspeed.speedFactorApplies(false)) ++bad;
        // case 3: the strike segment (negatives as positive)
        if (weaponspeed.weaponVsActivitySegment(5, 1) != 4 ||
            weaponspeed.weaponVsActivitySegment(5, 2) != 3 ||
            weaponspeed.weaponVsActivitySegment(5, 3) != 2 ||
            weaponspeed.weaponVsActivitySegment(5, 5) != 0 ||
            weaponspeed.weaponVsActivitySegment(2, 3) != 1 ||
            weaponspeed.weaponVsActivitySegment(2, 4) != 2 ||
            weaponspeed.weaponVsActivitySegment(2, 5) != 3 ||
            weaponspeed.weaponVsActivitySegment(10, 1) != 9 ||
            weaponspeed.weaponVsActivitySegment(10, 6) != 4) ++bad;
        // case 3: the fireball example (casting 3 segments)
        if (weaponspeed.weaponVsActivityOrder(4, 3) != 1 ||
            weaponspeed.weaponVsActivityOrder(3, 3) != 0 ||
            weaponspeed.weaponVsActivityOrder(2, 3) != -1 ||
            weaponspeed.weaponVsActivityOrder(1, 3) != -1 ||
            weaponspeed.weaponVsActivityOrder(0, 3) != -1 ||
            weaponspeed.weaponVsActivityOrder(9, 3) != 1) ++bad;
        // simultaneous: no factor modification
        if (weaponspeed.speedFactorModifiedWhenSimultaneous())
            ++bad;
        printf("R158 weapon speed factors audit: bad %d\n", bad);
        if (bad) return 1;
    }
