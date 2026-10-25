    // ---- R145: PHB p.38 weapon table audit ----
    // The per-weapon 'to hit' adjustment rows - PHB p.38,
    // both charts (melee weapons from the first, bows,
    // crossbow, and sling from the hurled/missile chart),
    // transcribed from the 1eonline.info compilation,
    // the repo-trusted source; the PHB re-upload still
    // owes the book-verify pass. Column order is the
    // book's: AC 0..10. The 3-class approximation R144
    // named closes here - the engine now carries the real
    // rows; the old rules::weaponVsAcAdjustment class
    // table stays pinned by the R144 audit (fallback).
    {
        int bad = 0;
        // every cell of every row (19 x 11 = 209 pins)
        static const int kRows[items::WPN_COUNT][11] = {
            // Dagger
            {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 },
            // Hand Axe
            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 },
            // Short Sword
            {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 },
            // Long Sword
            {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 },
            // Battle Axe
            {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 },
            // Mace
            {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 },
            // Flail
            {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 },
            // Morning Star
            { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 },
            // Spear
            {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 },
            // Quarterstaff
            {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 },
            // Club
            {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 },
            // Short Bow
            {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 },
            // Long Bow
            {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 },
            // Light Crossbow
            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },
            // Sling
            {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 },
            // Deep Crossbow (fights as the light
            // crossbow - the R314 special)
            {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 },
            // Lance, Light/Medium/Heavy Horse - R781:
            // the 1eonline.info compilation rows (the
            // R779 zero-row JUDGMENT is struck)
            {-3,-3,-2,-2,-1, 0, 0, 0, 0, 0, 0 },
            {-1, 0, 0,+1,+1,+1,+1, 0, 0, 0, 0 },
            {+4,+4,+3,+3,+2,+2,+2,+1,+1, 0, 0 },
        };
        for (int i = 0; i < items::WPN_COUNT; ++i) {
            const items::WeaponDef& w =
                items::weapon((items::WeaponId)i);
            for (int ac = 0; ac <= 10; ++ac)
                if (w.acAdj[ac] != kRows[i][ac]) ++bad;
        }
        // the clamps: the table runs AC 0..10
        if (items::weaponAcAdjustment(
                items::WPN_DAGGER, -3) != -4) ++bad;
        if (items::weaponAcAdjustment(
                items::WPN_DAGGER, 12) != 3) ++bad;
        // composition: STR 17 (+1), a +1 dagger, and the
        // p.38 row - vs. AC 10 (+3) that is +5; vs. AC 0
        // (-4) that is -2
        {
            items::WeaponInstance w;
            w.id = items::WPN_DAGGER;
            w.plus = 1;
            rules::ExceptionalStrength noEx;
            if (items::attackAdjustment(w, noEx, 17, 10)
                != 5) ++bad;
            if (items::attackAdjustment(w, noEx, 17, 0)
                != -2) ++bad;
        }
        // the p.71 closure: the sling bullet's +3 vs. no
        // armor - a named R144 approximation - is now the
        // engine's own row
        if (items::weaponAcAdjustment(
                items::WPN_SLING, 10) != 3) ++bad;
        // and the p.71 example's axe '+1 vs. no armor' is
        // one of the book's editorial errors: the p.38
        // battle axe row reads +2, and the engine follows
        // p.38 (Gygax: the example 'slipped past and never
        // got corrected')
        if (items::weaponAcAdjustment(
                items::WPN_BATTLE_AXE, 10) != 2) ++bad;
        printf("R145 weapon table audit: bad %d\n", bad);
        if (bad) return 1;
    }
