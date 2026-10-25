    // ---- R235: the bard engine audit ----
    // The career gates, the retained hit dice,
    // the 1st-level restart, the Table I queue and
    // the promotion die (an engine audit - the C++
    // battery is the gate).
    {
        int bad = 0;
        {
            Character c;
            c.race = 0;   // human
            c.abilities.str = 15;
            c.abilities.wis = 15;
            c.abilities.dex = 15;
            c.abilities.cha = 15;
            c.abilities.int_ = 12;
            c.abilities.con = 10;
            c.classIndex = 3;   // the thief leg
            c.level = 6;
            c.dualOldClass = 0;   // the fighter leg
            c.dualOldLevel = 6;
            c.hp = c.maxHp = 30;
            if (!c.canBeginBardStudies()) ++bad;
            // the refusals: wrong race, fighter
            // window, thief window, low CHA, a
            // plain class, already a bard
            c.race = 1;
            if (c.canBeginBardStudies()) ++bad;
            c.race = 0;
            c.dualOldLevel = 4;
            if (c.canBeginBardStudies()) ++bad;
            c.dualOldLevel = 6;
            c.level = 10;
            if (c.canBeginBardStudies()) ++bad;
            c.level = 6;
            c.abilities.cha = 14;
            if (c.canBeginBardStudies()) ++bad;
            c.abilities.cha = 15;
            c.classIndex = 0;
            if (c.canBeginBardStudies()) ++bad;
            c.classIndex = 3;
            // the studies: hit dice kept, 1st-level
            // restart, the Table III kit, the
            // Table I level-1 slots
            c.beginBardStudies();
            if (!c.bard) ++bad;
            if (c.classIndex != 2) ++bad;
            if (c.subclass != -1) ++bad;
            if (c.level != 1) ++bad;
            if (c.xp != 0) ++bad;
            if (c.hp != 30 || c.maxHp != 30) ++bad;
            if (c.dualOldClass != -1) ++bad;
            if (c.armor.id != items::ARMOR_LEATHER) ++bad;
            if (c.shield) ++bad;
            if (c.slotsByLevel[0] != 1) ++bad;
            if (c.slotsByLevel[1] != 0) ++bad;
            if (c.slotsByLevel[5] != 0) ++bad;
            if (c.canBeginBardStudies()) ++bad;
        }
        // the Table I queue and the promotion die,
        // on a live party train loop
        {
            Party p;
            Character c;
            c.name = "Rhymer";
            c.bard = true;
            c.classIndex = 2;
            c.level = 1;
            c.hp = c.maxHp = 30;
            p.members.push_back(c);
            rules::Rng r{7};
            rules::Dice d(r);
            MessageLog log;
            p.gainXp(2500, d, log);
            if (p.members[0].xp != 2500) ++bad;
            if (p.trainNext(d, log) < 0) ++bad;
            if (p.members[0].level != 2) ++bad;
            if (p.members[0].maxHp <= 30) ++bad;
        }
        printf("R235 bard engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
