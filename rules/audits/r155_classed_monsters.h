    // ---- R155: classed monsters audit ------------------------
    // DMG p.80 matrix II.C: a monster with class abilities
    // saves on its MOST FAVORABLE matrix (footnotes 1-2). The
    // five MM1 classed write-ups (brownie, dolphin, displacer
    // beast, couatl, ki-rin) pin the saveAs data pass: the Lua
    // key parses into class bits + per-class levels, the +2
    // displacer die bonus rides the actor saveBonus, and the
    // displacer magicResistance no longer misreads as 12% MR.
    // Judgment left for a later lane: ixitxachitl (clerical,
    // per-leader) and the humanoid classed LEADERS are
    // per-encounter extras, not base-monster data.
    {
        int bad = 0;
        // the couatl cell: MU 5 AND cleric 7 vs a fighter-6
        // base - matrix I rows: F6 {11,13,12,13,14}, MU5
        // {14,11,13,15,12}, C7 {7,11,10,13,12}; min
        // {7,11,10,13,12}
        int lvls[4] = {0, 5, 7, 0};
        static const int kCouatl[5] = { 7, 11, 10, 13, 12 };
        for (int c = 0; c < 5; ++c)
            if (rules::mostFavorableSaveTarget(
                    rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC,
                    lvls, 0, 6,
                    (rules::SaveCategory)c) != kCouatl[c])
                ++bad;
        // the brownie cell: cleric 9 beats a fighter-3 base
        // (F3 = the 1-2 band row {13,15,14,16,16})
        int bl[4] = {0, 0, 9, 0};
        static const int kBrownie[5] = { 7, 11, 10, 13, 12 };
        for (int c = 0; c < 5; ++c) {
            if (rules::mostFavorableSaveTarget(
                    rules::SAVE_AS_CLERIC, bl, 0, 3,
                    (rules::SaveCategory)c) != kBrownie[c])
                ++bad;
            if (rules::mostFavorableSaveTarget(0, bl, 0, 3,
                    (rules::SaveCategory)c) !=
                    rules::saveTarget(0, 3, (rules::SaveCategory)c))
                ++bad;
        }
        // the zero-bit skip: a set bit with level 0 must not
        // tighten the fighter 0-level row (spells 19)
        int z[4] = {0, 0, 0, 0};
        if (rules::mostFavorableSaveTarget(
                rules::SAVE_AS_THIEF, z, 0, 0,
                rules::SAVE_SPELLS) != 19)
            ++bad;
        // the five MM1 write-ups, via the registry
        const monsters::MonsterDef* d = reg.find("brownie");
        if (!d || d->saveAsMask != rules::SAVE_AS_CLERIC ||
                d->saveAsLevels[2] != 9 || d->saveAsBonus != 0)
            ++bad;
        d = reg.find("dolphin");
        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||
                d->saveAsLevels[0] != 4)
            ++bad;
        d = reg.find("displacer_beast");
        if (!d || d->saveAsMask != rules::SAVE_AS_FIGHTER ||
                d->saveAsLevels[0] != 12 || d->saveAsBonus != 2 ||
                d->magicResist != 0)
            ++bad;
        d = reg.find("couatl");
        if (!d || d->saveAsMask !=
                (rules::SAVE_AS_MAGIC_USER | rules::SAVE_AS_CLERIC)
            || d->saveAsLevels[1] != 5 || d->saveAsLevels[2] != 7)
            ++bad;
        d = reg.find("ki_rin");
        if (!d || d->saveAsMask != rules::SAVE_AS_MAGIC_USER ||
                d->saveAsLevels[1] != 18)
            ++bad;
        // and the actor carry: the displacer holds the +2 die
        // bonus and the fighter-12 bits. asTarget() lives in
        // ai/actor.cpp, outside the battery link (step 2 links
        // no ai TU) - the header fields are checked here; the
        // carry itself rides the syntax gate (step 1 compiles
        // ai/actor.cpp), the R147 convention.
        {
            rules::Rng rngX(1);
            rules::Dice diceX(rngX);
            ai::Actor a = reg.toActor("displacer_beast", diceX);
            if (a.saveAsMask != rules::SAVE_AS_FIGHTER ||
                    a.saveAsBonus != 2 || a.saveAsLevels[0] != 12)
                ++bad;
        }
        printf("R155 classed monsters audit: bad %d\n", bad);
        if (bad) return 1;
    }
