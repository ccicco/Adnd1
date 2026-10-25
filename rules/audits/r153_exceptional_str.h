    // ---- R153: exceptional strength audit -------------------------------
    // The PHB p.9 STR Table II, all five printed columns
    // pinned for the full 3-18/00 table: hit probability,
    // damage adjustment, weight allowance in g.p., open
    // doors on a d6 (with the locked/barred/held
    // parentheticals on 18/91-99 and 18/00) and bend
    // bars/lift gates. This is the DIVERGENCE FIX round:
    // the original ex bands carried unsourced carry and
    // press numbers and misread the 18/91-99 hit/damage
    // and 18/51-75 damage cells - the printed values
    // replace them, named in character.h and the gap
    // report.
    {
        int bad = 0;
        namespace RS = rules;
        // the 15 printed rows: score, ex flag, pct, hit,
        // dmg, weight g.p., open doors, locked doors,
        // bend bars percent
        static const struct {
            int str; bool ex; int pct;
            int hit, dmg, wt, door, locked, bend;
        } kT2[] = {
            {  3, false,   0, -3, -1, -350, 1, 0,  0 },
            {  5, false,   0, -2, -1, -250, 1, 0,  0 },
            {  7, false,   0, -1,  0, -150, 1, 0,  0 },
            {  9, false,   0,  0,  0,    0, 2, 0,  1 },
            { 11, false,   0,  0,  0,    0, 2, 0,  2 },
            { 13, false,   0,  0,  0,  100, 2, 0,  4 },
            { 15, false,   0,  0,  0,  200, 2, 0,  7 },
            { 16, false,   0,  0,  1,  350, 3, 0, 10 },
            { 17, false,   0,  1,  1,  500, 3, 0, 13 },
            { 18, false,   0,  1,  2,  750, 3, 0, 16 },
            { 18, true,  25,  1,  3, 1000, 3, 0, 20 },
            { 18, true,  60,  2,  3, 1250, 4, 0, 25 },
            { 18, true,  85,  2,  4, 1500, 4, 0, 30 },
            { 18, true,  95,  2,  5, 2000, 4, 1, 35 },
            { 18, true, 100,  3,  6, 3000, 5, 2, 40 },
        };
        for (size_t i = 0; i < sizeof(kT2)/sizeof(kT2[0]); ++i) {
            RS::ExceptionalStrength ex;
            ex.has = kT2[i].ex; ex.pct = kT2[i].pct;
            if (RS::strHitAdj(kT2[i].str, ex) != kT2[i].hit)
                ++bad;
            if (RS::strDmgAdj(kT2[i].str, ex) != kT2[i].dmg)
                ++bad;
            if (RS::strWeightAllowGp(kT2[i].str, ex)
                != kT2[i].wt) ++bad;
            if (RS::strOpenDoorsMax(kT2[i].str, ex)
                != kT2[i].door) ++bad;
            if (RS::strOpenDoorsLockedMax(kT2[i].str, ex)
                != kT2[i].locked) ++bad;
            if (RS::strBendBarsPct(kT2[i].str, ex)
                != kT2[i].bend) ++bad;
        }
        // the percentile fold edges, both sides of each
        RS::ExceptionalStrength ex; ex.has = true;
        ex.pct = 50;
        if (ex.hitAdj() != 1 || ex.dmgAdj() != 3
            || ex.weightAllowGp() != 1000
            || ex.openDoorsMax() != 3
            || ex.bendBarsPct() != 20) ++bad;
        ex.pct = 51;  if (ex.hitAdj() != 2) ++bad;
        ex.pct = 75;  if (ex.dmgAdj() != 3
            || ex.weightAllowGp() != 1250
            || ex.bendBarsPct() != 25) ++bad;
        ex.pct = 76;  if (ex.dmgAdj() != 4
            || ex.weightAllowGp() != 1500
            || ex.openDoorsMax() != 4
            || ex.bendBarsPct() != 30) ++bad;
        ex.pct = 90;  if (ex.hitAdj() != 2
            || ex.dmgAdj() != 4) ++bad;
        ex.pct = 91;  if (ex.dmgAdj() != 5
            || ex.weightAllowGp() != 2000
            || ex.bendBarsPct() != 35
            || ex.openDoorsLockedMax() != 1) ++bad;
        ex.pct = 99;  if (ex.hitAdj() != 2
            || ex.openDoorsLockedMax() != 1) ++bad;
        ex.pct = 100; if (ex.hitAdj() != 3 || ex.dmgAdj() != 6
            || ex.weightAllowGp() != 3000
            || ex.openDoorsMax() != 5
            || ex.openDoorsLockedMax() != 2
            || ex.bendBarsPct() != 40) ++bad;
        // exceptional strength replaces the plain 18 row,
        // it does not add to it (PHB p.9)
        if (RS::strHitAdj(18, ex) != 3
            || RS::strDmgAdj(18, ex) != 6
            || RS::strBendBarsPct(18, ex) != 40) ++bad;
        printf("R153 exceptional strength audit: bad %d\n", bad);
        if (bad) return 1;
    }
