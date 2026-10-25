    // ---- R89: pace audit ----
    {
        int bad = 0;
        // the coin share: 10 coins per gp unit, split across
        // the living only
        {
            Party p;
            if (coinWeightShare(p) != 0) ++bad;   // no gold
            p.gold = 4000;
            if (coinWeightShare(p) != 0) ++bad;   // nobody living
            Character a, b2, c2, d2;
            a.hp = 10; b2.hp = 10; c2.hp = 10; d2.hp = 10;
            p.members.push_back(a);
            p.members.push_back(b2);
            p.members.push_back(c2);
            p.members.push_back(d2);
            if (coinWeightShare(p) != 100) ++bad;  // 4000/10/4
            p.members[3].hp = 0;                   // the dead
            if (coinWeightShare(p) != 133) ++bad;  // 4000/10/3
            p.gold = 4999;                         // floor
            if (coinWeightShare(p) != 166) ++bad;  // 4999/30
        }
        // the true load: kit + cargo + coin share
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            // default kit: dagger 20 gp
            if (memberLoad(p, c) != 20) ++bad;
            p.gold = 1000;
            if (memberLoad(p, c) != 120) ++bad;    // +100 coin
            PackItem sw{};
            sw.kind = 0;
            sw.id = (int)items::WPN_LONG_SWORD;
            c.pack.push_back(sw);
            if (memberLoad(p, c) != 195) ++bad;    // +75 cargo
        }
        // the pace cost: 120'->10, 90'->13, 60'->20, 30'->40
        if (paceStepTenths(120) != 10) ++bad;
        if (paceStepTenths(90)  != 13) ++bad;
        if (paceStepTenths(60)  != 20) ++bad;
        if (paceStepTenths(30)  != 40) ++bad;
        // coins slow the company: a lone STR 10 member hauling
        // 20,000 gp carries 2000 wt -> HEAVY -> 30' -> four
        // wander bites per step
        {
            Party p;
            Character c;
            c.hp = 10;
            p.members.push_back(c);
            if (partyMoveRate(p) != 120) ++bad;
            p.gold = 20000;
            if (partyMoveRate(p) != 30) ++bad;
            if (paceStepTenths(partyMoveRate(p)) != 40) ++bad;
            // spending it all in town is instant relief
            p.gold = 0;
            if (partyMoveRate(p) != 120) ++bad;
        }
        printf("R89 pace audit: bad %d\n", bad);
        if (bad) return 1;
    }
