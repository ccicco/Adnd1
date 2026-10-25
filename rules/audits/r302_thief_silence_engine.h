    // ---- R302: the thief silence engine audit ----
    // The wired surprise roll on pinned seeds: the
    // party side reads the best living DEX
    // reaction adjustment, the first living thief
    // rolls ONE move silently percentile, the
    // monster side takes the -2 step on success.
    // Expected values from the xorshift64* replica
    // (the R301 convention - the splice sandbox
    // compiles nothing; the replica walked every
    // draw first). Each scenario asserts BOTH
    // segments, so a shifted draw count, a wrong
    // adjustment source or a missed silence step
    // all fire.
    {
        int bad = 0;
        // the scenario driver: one stock monster,
        // the wired call, both segments checked
        auto silScenario = [](
                const std::vector<ai::Actor>& pt,
                uint64_t seed, int wantA,
                int wantB, int* badp) {
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1;
            m.hitDice = 1;
            m.hp = 6;
            m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, seed);
            int sa = -1, sb = -1;
            enc.rollSurpriseWired(sa, sb);
            if (sa != wantA || sb != wantB) ++*badp;
        };
        auto silMk = [](int cls, int level,
                       int race, int dex, int hp) {
            ai::Actor a;
            a.isCharacter = true;
            a.classIndex = cls;
            a.level = level;
            a.pcRace = race;
            a.dex = (uint8_t)dex;
            a.hp = hp;
            a.maxHp = hp > 0 ? hp : 30;
            return a;
        };
        // seed 3: no thief, dex 10 - the plain pair
        // (party 6, monsters 6 -> 1 segment each)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(0, 1, 0, 10, 30));
            silScenario(pt, 3, 1, 1, &bad);
        }
        // seed 2: dex 18 - the +3 lands (the party
        // roll 4 reads 7: 1 segment, not the plain 2)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(0, 1, 0, 18, 30));
            silScenario(pt, 2, 1, 0, &bad);
        }
        // seed 1: dex 3 - the -3 lands (the party
        // roll 8 reads 5: 2 segments, not 0)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(0, 1, 0, 3, 30));
            silScenario(pt, 1, 2, 1, &bad);
        }
        // seed 66: a level 1 human dex 9 thief -
        // the printed chance reads -50, so the
        // percentile (42) fails and the silence
        // step never lands (monsters 7 -> 1)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(3, 1, 0, 9, 30));
            silScenario(pt, 66, 0, 1, &bad);
        }
        // seed 4: a level 10 human dex 13 thief -
        // the percentile 761 reads under 780:
        // silenced; the monster pair rolls 8 and
        // the -2 step lands 1 segment (0 plain)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(3, 10, 0, 13, 30));
            silScenario(pt, 4, 1, 1, &bad);
        }
        // seed 5: two thieves - ONE percentile
        // (492, under 780), not two: the pair
        // lands (party 5 -> 2, monsters 9 with
        // the step -> 1)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(3, 10, 0, 13, 30));
            pt.push_back(silMk(3, 10, 0, 13, 30));
            silScenario(pt, 5, 2, 1, &bad);
        }
        // seed 2: the dead thief (hp 0, dex 18)
        // draws nothing and feeds no adjustment;
        // the living fighter dex 10 reads pAdj 0
        // (party 4 -> 2 segments, monsters 10 -> 0)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(3, 10, 0, 18, 0));
            pt.push_back(silMk(0, 1, 0, 10, 30));
            silScenario(pt, 2, 2, 0, &bad);
        }
        // seed 1: dex 3 + dex 18 + a level 1
        // halfling dex 13 thief (chance 250, the
        // percentile 165 succeeds) - pAdj reads
        // the BEST living member (+3: the party
        // roll 8 reads 11 -> 0) and the monster
        // side takes the step (7 reads 5 -> 2)
        {
            std::vector<ai::Actor> pt;
            pt.push_back(silMk(0, 1, 0, 3, 30));
            pt.push_back(silMk(0, 1, 0, 18, 30));
            pt.push_back(silMk(3, 1, 5, 13, 30));
            silScenario(pt, 1, 0, 2, &bad);
        }
        printf("R302 thief silence engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
