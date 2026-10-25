    // ---- R233: the multi-class engine audit ----
    // The toActor primary convention, the creation
    // gates and the member factory (an engine audit -
    // the R174/R232 convention; the C++ battery is
    // the gate).
    {
        int bad = 0;
        // the Character + toActor primary convention
        {
            Character c;
            if (c.multiMask != 0) ++bad;
            c.multiMask = 11;   // F/MU/T
            ai::Actor a = c.toActor();
            if (a.classIndex != 0) ++bad;
            if (a.subclass != -1) ++bad;
            c.multiMask = 24;   // I/T: thief primary
            a = c.toActor();
            if (a.classIndex != 3) ++bad;
            if (a.subclass != -1) ++bad;
            c.multiMask = 68;   // C/A: cleric primary
            a = c.toActor();
            if (a.classIndex != 2) ++bad;
            if (a.subclass != -1) ++bad;
        }
        // the creation gates + the member factory
        {
            CreationState cr;
            cr.racePick = 4;   // half-elf
            cr.rolled.str = 12; cr.rolled.int_ = 12;
            cr.rolled.wis = 12; cr.rolled.dex = 12;
            cr.rolled.con = 12; cr.rolled.cha = 12;
            // the half-elf multi-class cleric WIS 13
            if (cr.multiEligible(5)) ++bad;   // WIS 12
            cr.rolled.wis = 13;
            if (!cr.multiEligible(5)) ++bad;   // C/F
            if (!cr.multiEligible(3)) ++bad;   // F/MU
            if (cr.multiEligible(24)) ++bad;   // I/T: no elf bit here
            // the factory: F/MU - the fighter primary,
            // the hp quotient bounds (d10 + d4 at
            // CON 12, quotients 1..7), the MU kit
            Character mc = cr.makeMultiMember(3);
            if (mc.multiMask != 3) ++bad;
            if (mc.classIndex != 0) ++bad;
            if (mc.subclass != -1) ++bad;
            if (mc.hp < 1 || mc.hp > 7) ++bad;
            if (mc.armor.id != items::ARMOR_NONE_EQUIPPED)
                ++bad;
            if (mc.shield) ++bad;
            // the dwarf F/T - the thief kit
            cr.racePick = 1;
            cr.rolled.str = 12; cr.rolled.dex = 12;
            Character dt = cr.makeMultiMember(9);
            if (dt.multiMask != 9) ++bad;
            if (dt.armor.id != items::ARMOR_LEATHER) ++bad;
            if (dt.shield) ++bad;
            // the half-orc C/A - the assassin primary
            cr.racePick = 6;
            cr.rolled.wis = 13;
            Character ca = cr.makeMultiMember(68);
            if (ca.subclass != -1) ++bad;
            if (ca.classIndex != 2) ++bad;
        }
        printf("R233 multi-class engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
