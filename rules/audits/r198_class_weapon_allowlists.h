    // ---- R198: the class weapon allowlists audit ----
    // The CHARACTER CLASSES TABLE II weapons column, cell
    // for cell: the any-weapon rows, the limited lists, the
    // family expansions, the thief sword footnote, the monk
    // pole-arm family and the crossbow.
    {
        int bad = 0;
        // the any-weapon rows
        if (!rules::classUsesAnyWeapon(2)) ++bad;   // fighter
        if (!rules::classUsesAnyWeapon(3)) ++bad;   // paladin
        if (!rules::classUsesAnyWeapon(4)) ++bad;   // ranger
        if (!rules::classUsesAnyWeapon(8)) ++bad;   // assassin
        if (rules::classUsesAnyWeapon(0)) ++bad;    // cleric
        if (rules::classUsesAnyWeapon(1)) ++bad;    // druid
        if (rules::classUsesAnyWeapon(5)) ++bad;    // MU
        if (rules::classUsesAnyWeapon(6)) ++bad;    // illusionist
        if (rules::classUsesAnyWeapon(7)) ++bad;    // thief
        if (rules::classUsesAnyWeapon(9)) ++bad;    // monk
        // the counts
        static const int kCount[10] = {
             7,  9, -1, -1, -1,  3,  3,  8, -1, 24
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classAllowedWeaponCount(c)
                != kCount[c]) ++bad;
        }
        // the monk list, the ten printed weapons
        if (!rules::weaponAllowedForClass(9, "bo stick")) ++bad;
        if (!rules::weaponAllowedForClass(9, "club")) ++bad;
        if (!rules::weaponAllowedForClass(9, "crossbow")) ++bad;
        if (!rules::weaponAllowedForClass(9, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(9, "hand axe")) ++bad;
        if (!rules::weaponAllowedForClass(9, "javelin")) ++bad;
        if (!rules::weaponAllowedForClass(9, "jo stick")) ++bad;
        if (!rules::weaponAllowedForClass(9, "spear")) ++bad;
        if (!rules::weaponAllowedForClass(9, "quarterstaff"))
            ++bad;
        // the monk pole-arm family, all 15 rows
        static const char* const kPoleArm[15] = {
            "bardiche", "bec de corbin", "bill-guisarme",
            "fauchard", "fauchard-fork", "military fork",
            "glaive", "glaive-guisarme", "guisarme",
            "guisarme-voulge", "halberd", "partisan",
            "ransseur", "spetum", "voulge"
        };
        for (int i = 0; i < 15; ++i) {
            if (!rules::weaponAllowedForClass(9, kPoleArm[i]))
                ++bad;
            // the family is the monk print - not the MU or thief
            if (rules::weaponAllowedForClass(5, kPoleArm[i]))
                ++bad;
            if (rules::weaponAllowedForClass(7, kPoleArm[i]))
                ++bad;
        }
        // what the monk denies
        if (rules::weaponAllowedForClass(9, "battle axe")) ++bad;
        if (rules::weaponAllowedForClass(9, "long sword")) ++bad;
        if (rules::weaponAllowedForClass(9, "morning star")) ++bad;
        // the cleric list, the family expansions
        if (!rules::weaponAllowedForClass(0, "club")) ++bad;
        if (!rules::weaponAllowedForClass(0, "footman flail"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "horseman flail"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "hammer")) ++bad;
        if (!rules::weaponAllowedForClass(0, "footman mace"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "horseman mace"))
            ++bad;
        if (!rules::weaponAllowedForClass(0, "quarterstaff")) ++bad;
        // the cleric denies
        if (rules::weaponAllowedForClass(0, "dagger")) ++bad;
        if (rules::weaponAllowedForClass(0, "short sword")) ++bad;
        if (rules::weaponAllowedForClass(0, "scimitar")) ++bad;
        if (rules::weaponAllowedForClass(0, "lucern hammer")) ++bad;
        // the druid list
        if (!rules::weaponAllowedForClass(1, "scimitar")) ++bad;
        if (!rules::weaponAllowedForClass(1, "spear")) ++bad;
        if (!rules::weaponAllowedForClass(1, "hammer")) ++bad;
        if (!rules::weaponAllowedForClass(1, "sling bullet"))
            ++bad;
        if (!rules::weaponAllowedForClass(1, "sling stone")) ++bad;
        if (!rules::weaponAllowedForClass(1, "quarterstaff")) ++bad;
        if (rules::weaponAllowedForClass(1, "footman mace")) ++bad;
        if (rules::weaponAllowedForClass(1, "long sword")) ++bad;
        // the MU and illusionist lists
        if (!rules::weaponAllowedForClass(5, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(5, "dart")) ++bad;
        if (!rules::weaponAllowedForClass(5, "quarterstaff"))
            ++bad;
        if (rules::weaponAllowedForClass(5, "club")) ++bad;
        if (rules::weaponAllowedForClass(5, "long sword")) ++bad;
        if (!rules::weaponAllowedForClass(6, "dagger")) ++bad;
        if (rules::weaponAllowedForClass(6, "battle axe")) ++bad;
        // the thief list and the sword footnote
        if (!rules::weaponAllowedForClass(7, "club")) ++bad;
        if (!rules::weaponAllowedForClass(7, "dagger")) ++bad;
        if (!rules::weaponAllowedForClass(7, "dart")) ++bad;
        if (!rules::weaponAllowedForClass(7, "sling stone")) ++bad;
        if (!rules::weaponAllowedForClass(7, "short sword")) ++bad;
        if (!rules::weaponAllowedForClass(7, "broad sword")) ++bad;
        if (!rules::weaponAllowedForClass(7, "long sword")) ++bad;
        if (rules::weaponAllowedForClass(7, "bastard sword"))
            ++bad;
        if (rules::weaponAllowedForClass(7, "two-handed sword"))
            ++bad;
        if (rules::weaponAllowedForClass(7, "spear")) ++bad;
        // the crossbow is the monk print alone
        if (rules::weaponAllowedForClass(7, "crossbow")) ++bad;
        if (rules::weaponAllowedForClass(5, "crossbow")) ++bad;
        if (rules::weaponAllowedForClass(0, "crossbow")) ++bad;
        // the any-weapon rows take everything asked
        if (!rules::weaponAllowedForClass(2, "two-handed sword"))
            ++bad;
        if (!rules::weaponAllowedForClass(3, "bastard sword"))
            ++bad;
        if (!rules::weaponAllowedForClass(4, "halberd")) ++bad;
        if (!rules::weaponAllowedForClass(8, "morning star")) ++bad;
        // the list walk agrees with the membership test
        for (int c = 0; c < 10; ++c) {
            int n = rules::classAllowedWeaponCount(c);
            if (n <= 0) continue;
            for (int i = 0; i < n; ++i) {
                if (!rules::weaponAllowedForClass(
                        c, rules::classAllowedWeaponName(c, i)))
                    ++bad;
            }
        }
        printf("R198 class weapon allowlists audit: bad %d\n", bad);
        if (bad) return 1;
    }
