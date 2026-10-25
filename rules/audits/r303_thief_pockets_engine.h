    // ---- R303: the thief pockets engine audit ----
    // The wired street roll on pinned seeds (the
    // R301/R302 replica convention - the splice
    // sandbox compiles nothing; the replica walked
    // every draw first): the first living thief
    // draws the passerby trade and level, one
    // printed percentile, and the branch lands -
    // the R190 purse lift on success (the trade
    // dice), the quiet fail, the watch fine on a
    // noticed fail (the seed 127 passerby reads
    // 6th level: the cut fires - without it the
    // seed reads the quiet band). The gates ride
    // too: no living thief, the mode gate, the
    // dead-thief skip.
    {
        int bad = 0;
        // no living thief - the fallen Rook draws
        // nothing; the gate line reads
        {
            AppState st;
            st.mode = MODE_CITY;
            Character f;
            f.name = "Fighter";
            f.classIndex = 0; f.level = 1;
            f.hp = 30; f.maxHp = 30;
            st.party.members.push_back(f);
            Character d;
            d.name = "Rook";
            d.classIndex = 3; d.level = 7;
            d.hp = 0; d.maxHp = 30;
            st.party.members.push_back(d);
            st.party.formed = true;
            st.rng.seed(1);
            st.cityPickPockets();
            if (st.log.get(0).find("No thief walks")
                == std::string::npos) ++bad;
            if (st.party.gold != 0) ++bad;
        }
        // the mode gate - MODE_TOWN reads nothing
        // (the same seed would lift 140 with the
        // gate broken)
        {
            AppState st;
            st.mode = MODE_TOWN;
            Character t;
            t.name = "Sly";
            t.classIndex = 3; t.level = 17;
            t.race = 0;
            t.abilities.dex = 18;
            t.hp = 30; t.maxHp = 30;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.rng.seed(21);
            st.cityPickPockets();
            if (st.log.get(0).find("lifts")
                != std::string::npos) ++bad;
            if (st.party.gold != 0) ++bad;
        }
        // seed 21: success - the passerby reads a
        // fighter trade (the 5d4 x 10 purse), the
        // percentile 955 lands under the 1350
        // tenths chance (level 17 human 18 dex)
        {
            AppState st;
            st.mode = MODE_CITY;
            Character t;
            t.name = "Sly";
            t.classIndex = 3; t.level = 17;
            t.race = 0;
            t.abilities.dex = 18;
            t.hp = 30; t.maxHp = 30;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.rng.seed(21);
            st.cityPickPockets();
            if (st.party.gold != 140) ++bad;
            if (st.log.get(0).find("lifts 140 gp")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("watch")
                != std::string::npos) ++bad;
        }
        // seed 19: the quiet fail at the boundary -
        // the percentile 150 reads exactly the
        // 150 tenths chance (level 1 human dex 9,
        // the passerby 1st): a fail, under the
        // notice band
        {
            AppState st;
            st.mode = MODE_CITY;
            Character t;
            t.name = "Sly";
            t.classIndex = 3; t.level = 1;
            t.race = 0;
            t.abilities.dex = 9;
            t.hp = 30; t.maxHp = 30;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.party.gold = 777;
            st.rng.seed(19);
            st.cityPickPockets();
            if (st.party.gold != 777) ++bad;
            if (st.log.get(0).find(
                    "fails, but nobody notices")
                == std::string::npos) ++bad;
        }
        // seed 127: the noticed fail with the cut
        // firing - the passerby reads 6th level,
        // the cut drives the 150 base to 0 and
        // the percentile 256 reads noticed; the
        // watch fine takes a tenth of 5000
        {
            AppState st;
            st.mode = MODE_CITY;
            Character t;
            t.name = "Sly";
            t.classIndex = 3; t.level = 1;
            t.race = 0;
            t.abilities.dex = 9;
            t.hp = 30; t.maxHp = 30;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.party.gold = 5000;
            st.rng.seed(127);
            st.cityPickPockets();
            if (st.party.gold != 4500) ++bad;
            if (st.log.get(0).find(
                    "the watch takes 500 gp")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("lifts")
                != std::string::npos) ++bad;
        }
        // seed 11: the fallen Rook skips, Sly rolls
        // - the passerby reads a magic-user trade
        // (the 2d4 x 10 purse) and the percentile
        // 21 lands under the cut chance 1200 (the
        // 6th level passerby cuts the 1350)
        {
            AppState st;
            st.mode = MODE_CITY;
            Character d;
            d.name = "Rook";
            d.classIndex = 3; d.level = 7;
            d.hp = 0; d.maxHp = 30;
            st.party.members.push_back(d);
            Character t;
            t.name = "Sly";
            t.classIndex = 3; t.level = 17;
            t.race = 0;
            t.abilities.dex = 18;
            t.hp = 30; t.maxHp = 30;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.rng.seed(11);
            st.cityPickPockets();
            if (st.party.gold != 60) ++bad;
            if (st.log.get(0).find("Sly lifts 60 gp")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("Rook")
                != std::string::npos) ++bad;
        }
        printf("R303 thief pockets engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
