    // ---- R299: the party kit recordings engine audit ----
    // The Character kit grant (the makeMember,
    // makeSubclassMember, switchProfession and bard
    // factories), the grant-seam count agreement,
    // the toActor copy and the live proficiency
    // gate (an engine audit - the C++ battery is
    // the gate; the save load rebuild calls the
    // same method - recorded).
    {
        int bad = 0;
        // the base kits: the grant records the kit
        // arm and the count agrees with the seam
        {
            CreationState cr;
            cr.racePick = 0;   // human
            cr.rolled.str = 12; cr.rolled.int_ = 12;
            cr.rolled.wis = 12; cr.rolled.dex = 12;
            cr.rolled.con = 12; cr.rolled.cha = 12;
            Character f = cr.makeMember(0);
            if (f.profWeaponIds.size() != 1) ++bad;
            if (f.profWeaponIds[0] !=
                (int)items::WPN_LONG_SWORD) ++bad;
            if ((int)f.profWeaponIds.size() !=
                rules::wpfKitGrantCount(0, -1)) ++bad;
            Character m = cr.makeMember(1);
            if (m.profWeaponIds.size() != 1 ||
                m.profWeaponIds[0] !=
                (int)items::WPN_DAGGER) ++bad;
            if ((int)m.profWeaponIds.size() !=
                rules::wpfKitGrantCount(1, -1)) ++bad;
            Character cl = cr.makeMember(2);
            if (cl.profWeaponIds.size() != 1 ||
                cl.profWeaponIds[0] !=
                (int)items::WPN_MACE) ++bad;
            if ((int)cl.profWeaponIds.size() !=
                rules::wpfKitGrantCount(2, -1)) ++bad;
            Character t = cr.makeMember(3);
            if (t.profWeaponIds.size() != 2) ++bad;
            if (t.profWeaponIds[0] !=
                (int)items::WPN_SHORT_SWORD ||
                t.profWeaponIds[1] !=
                (int)items::WPN_SLING) ++bad;
            if ((int)t.profWeaponIds.size() !=
                rules::wpfKitGrantCount(3, -1)) ++bad;
        }
        // the subclass overlays: the monk staff,
        // the assassin thief kit (the sling rides)
        {
            CreationState cr;
            cr.racePick = 0;
            cr.rolled.str = 12; cr.rolled.int_ = 12;
            cr.rolled.wis = 12; cr.rolled.dex = 12;
            cr.rolled.con = 12; cr.rolled.cha = 12;
            Character mo =
                cr.makeSubclassMember(rules::SUB_MONK);
            if (mo.subclass != rules::SUB_MONK) ++bad;
            if (mo.profWeaponIds.size() != 1 ||
                mo.profWeaponIds[0] !=
                (int)items::WPN_QUARTERSTAFF) ++bad;
            if ((int)mo.profWeaponIds.size() !=
                rules::wpfKitGrantCount(0,
                                       rules::SUB_MONK)) ++bad;
            Character as =
                cr.makeSubclassMember(rules::SUB_ASSASSIN);
            if (as.classIndex != 3) ++bad;
            if (as.profWeaponIds.size() != 2 ||
                as.profWeaponIds[1] !=
                (int)items::WPN_SLING) ++bad;
            if ((int)as.profWeaponIds.size() !=
                rules::wpfKitGrantCount(3,
                                       rules::SUB_ASSASSIN)) ++bad;
        }
        // the profession switch: the new kit is
        // the new recording (the old choices do
        // not persist) - the printed fighter to
        // magic-user example
        {
            Character sw;
            sw.race = 0;
            sw.abilities.str = 15;
            sw.abilities.int_ = 17;
            sw.classIndex = 0;
            sw.level = 6;
            sw.hp = sw.maxHp = 40;
            rules::Rng r{1};
            rules::Dice d(r);
            if (!sw.switchProfession(1, d)) ++bad;
            if (sw.profWeaponIds.size() != 1 ||
                sw.profWeaponIds[0] !=
                (int)items::WPN_DAGGER) ++bad;
        }
        // the thief switch: the sling records with
        // the thief kit
        {
            Character sw;
            sw.race = 0;
            sw.abilities.str = 15;
            sw.abilities.dex = 17;
            sw.classIndex = 0;
            sw.level = 6;
            sw.hp = sw.maxHp = 40;
            rules::Rng r{2};
            rules::Dice d(r);
            if (!sw.switchProfession(3, d)) ++bad;
            if (sw.profWeaponIds.size() != 2) ++bad;
            if (sw.profWeaponIds[0] !=
                (int)items::WPN_SHORT_SWORD ||
                sw.profWeaponIds[1] !=
                (int)items::WPN_SLING) ++bad;
        }
        // the bard studies: the long sword kit
        {
            Character bd;
            bd.race = 0;
            bd.classIndex = 3;
            bd.level = 6;
            bd.dualOldClass = 0;
            bd.dualOldLevel = 6;
            bd.abilities.str = 15;
            bd.abilities.wis = 15;
            bd.abilities.dex = 15;
            bd.abilities.cha = 15;
            bd.abilities.int_ = 12;
            bd.abilities.con = 10;
            if (!bd.canBeginBardStudies()) ++bad;
            bd.beginBardStudies();
            if (bd.bard != true) ++bad;
            if (bd.profWeaponIds.size() != 1 ||
                bd.profWeaponIds[0] !=
                (int)items::WPN_LONG_SWORD) ++bad;
        }
        // the load rebuild method: a bare member
        // re-reads the class kit (state_core.cpp
        // calls this on load - the R33 convention)
        {
            Character rb;
            rb.classIndex = 3;
            rb.grantKitProficiencies();
            if (rb.profWeaponIds.size() != 2 ||
                rb.profWeaponIds[0] !=
                (int)items::WPN_SHORT_SWORD) ++bad;
            rb.subclass = rules::SUB_MONK;
            rb.grantKitProficiencies();
            if (rb.profWeaponIds.size() != 1 ||
                rb.profWeaponIds[0] !=
                (int)items::WPN_QUARTERSTAFF) ++bad;
            rb.bard = true;
            rb.grantKitProficiencies();
            if (rb.profWeaponIds.size() != 1 ||
                rb.profWeaponIds[0] !=
                (int)items::WPN_LONG_SWORD) ++bad;
        }
        // the toActor copy: the list travels and
        // the proficiency gate reads it live
        {
            Character e;
            ai::Actor ae = e.toActor();
            if (!ae.profWeaponIds.empty()) ++bad;
            // the empty list: the pre-R297
            // convention (no penalty paid)
            if (!ae.proficientWithWeapon(
                    (int)items::WPN_MACE)) ++bad;
            Character t2;
            t2.classIndex = 3;
            t2.grantKitProficiencies();
            ai::Actor at = t2.toActor();
            if (at.profWeaponIds.size() != 2) ++bad;
            if (!at.proficientWithWeapon(
                    (int)items::WPN_SHORT_SWORD) ||
                !at.proficientWithWeapon(
                    (int)items::WPN_SLING)) ++bad;
            if (at.proficientWithWeapon(
                    (int)items::WPN_MACE)) ++bad;
        }
        printf("R299 party kit recordings engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
