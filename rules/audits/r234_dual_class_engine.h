    // ---- R234: the dual-class engine audit ----
    // The switch gates, the retained hit dice, the
    // 1st-level restart, the XP negation and the
    // exceeded-level die (an engine audit - the C++
    // battery is the gate).
    {
        int bad = 0;
        {
            Character c;
            c.race = 0;   // human
            c.abilities.str = 15;
            c.abilities.int_ = 17;
            c.classIndex = 0;   // the printed example: fighter
            c.level = 6;
            c.hp = c.maxHp = 40;
            if (!c.canSwitchProfession(1)) ++bad;
            // the refusals: same class, wrong race,
            // low old prime, low new prime
            if (c.canSwitchProfession(0)) ++bad;
            c.race = 1;
            if (c.canSwitchProfession(1)) ++bad;
            c.race = 0;
            c.abilities.str = 14;
            if (c.canSwitchProfession(1)) ++bad;
            c.abilities.str = 15;
            c.abilities.int_ = 16;
            if (c.canSwitchProfession(1)) ++bad;
            c.abilities.int_ = 17;
            // the switch: hit dice kept, 1st-level
            // restart, the MU kit
            rules::Rng r{1};
            rules::Dice d(r);
            if (!c.switchProfession(1, d)) ++bad;
            if (c.dualOldClass != 0) ++bad;
            if (c.dualOldLevel != 6) ++bad;
            if (c.classIndex != 1) ++bad;
            if (c.level != 1) ++bad;
            if (c.xp != 0) ++bad;
            if (c.hp != 40 || c.maxHp != 40) ++bad;
            if (c.armor.id != items::ARMOR_NONE_EQUIPPED)
                ++bad;
            if (c.shield) ++bad;
            // one switch only
            if (c.canSwitchProfession(2)) ++bad;
        }
        // the XP negation and the exceeded die, on a
        // live party train loop
        {
            Party p;
            Character c;
            c.name = "Swit";
            c.race = 0;
            c.abilities.str = 15;
            c.abilities.int_ = 17;
            c.classIndex = 0;
            c.level = 2;
            c.hp = c.maxHp = 12;
            rules::Rng r{7};
            rules::Dice d(r);
            if (!c.switchProfession(1, d)) ++bad;
            p.members.push_back(c);
            MessageLog log;
            // the resort stance negates the award
            p.members[0].oldClassUse = true;
            p.gainXp(1000, d, log);
            if (p.members[0].xp != 0) ++bad;
            // strict: the award flows and queues
            p.members[0].oldClassUse = false;
            p.gainXp(1000, d, log);
            if (p.members[0].xp <= 0) ++bad;
            p.members[0].xp = 100000;
            // no die at or below the old level
            int hpAtOld = p.members[0].maxHp;
            p.gainXp(0, d, log);
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 2) ++bad;
            if (p.members[0].maxHp != hpAtOld) ++bad;
            // the new-class die once exceeded
            p.gainXp(0, d, log);
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 3) ++bad;
            if (p.members[0].maxHp <= hpAtOld) ++bad;
        }
        printf("R234 dual-class engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
