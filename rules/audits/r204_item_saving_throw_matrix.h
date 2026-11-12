    // ---- R204: the item saving throw matrix audit ----
    // DMG p.80 matrix III: all 154 cells (14 materials x
    // 11 attack forms) transcribed, plus the modifiers -
    // the magical ladder, the own-mode +5, the fall surface
    // and distance adjustments, the cold-strike footnote,
    // the normal-fire exposure rounds - and the R157
    // cross-checks: the grenade break saves must equal the
    // matrix cells (ceramic flask 18/12, crystal vial
    // 19/14).
    {
        Grenade grenade;
        Itemsavethrow itemsavethrow;
        int bad = 0;
        static const int kCells[14][11] = {
            { 11, 16, 10, 20,  6, 17,  9,  3,  2,  8, 1 },
            {  4, 18, 12, 19, 11,  5,  3,  2,  4,  2, 1 },
            { 12,  6,  3, 20,  2, 20, 16, 13,  1, 18, 1 },
            {  6, 19, 14, 20, 13, 10,  6,  3,  7, 15, 5 },
            {  5, 20, 15, 20, 14, 11,  7,  4,  6, 17, 1 },
            { 10,  4,  2, 20,  1, 13,  6,  4,  3, 13, 1 },
            { 15,  0,  0, 20,  0, 15, 14, 13, 12, 18, 15 },
            {  7,  6,  2, 17,  2,  6,  2,  1,  1,  1, 1 },
            { 13, 14,  9, 19,  4, 18, 13,  5,  1,  6, 1 },
            { 12, 20, 15, 20, 13, 14,  9,  5,  6, 18, 1 },
            { 16, 11,  6, 20,  0, 25, 21, 18,  2, 20, 1 },
            {  3, 17,  7, 18,  4,  7,  3,  2,  1, 14, 2 },
            {  9, 13,  6, 20,  2, 15, 11,  9,  1, 10, 1 },
            {  8, 10,  3, 19,  1, 11,  7,  5,  1, 12, 1 },
        };
        for (int m = 0; m < ISM_COUNT; ++m)
            for (int f = 0; f < ISF_COUNT; ++f)
                if (itemsavethrow.itemSaveTarget(
                        (ItemSaveMaterial)m,
                        (ItemSaveForm)f)
                        != kCells[m][f]) ++bad;
        // names present for every row and form
        for (int m = 0; m < ISM_COUNT; ++m)
            if (!*itemsavethrow.itemSaveMaterialName(
                    (ItemSaveMaterial)m)) ++bad;
        for (int f = 0; f < ISF_COUNT; ++f)
            if (!*itemsavethrow.itemSaveFormName(
                    (ItemSaveForm)f)) ++bad;
        // the R157 cross-checks: the grenade break saves
        // are the matrix BLOW cells - ceramic flasks
        // (acid, oil) the ceramic row, crystal vials (holy
        // or unholy water, poison) the crystal row
        if (itemsavethrow.itemSaveTarget(ISM_CERAMIC,
                ISF_BLOW_CRUSHING)
                != grenade.grenadeBreakSaveCrushing(
                      GREN_ACID)) ++bad;
        if (itemsavethrow.itemSaveTarget(ISM_CERAMIC,
                ISF_BLOW_NORMAL)
                != grenade.grenadeBreakSaveNormal(
                      GREN_OIL)) ++bad;
        if (itemsavethrow.itemSaveTarget(ISM_CRYSTAL_VIAL,
                ISF_BLOW_CRUSHING)
                != grenade.grenadeBreakSaveCrushing(
                      GREN_HOLY_WATER)) ++bad;
        if (itemsavethrow.itemSaveTarget(ISM_CRYSTAL_VIAL,
                ISF_BLOW_NORMAL)
                != grenade.grenadeBreakSaveNormal(
                      GREN_POISON)) ++bad;
        // the liquid row: no save vs blow, fall, normal fire
        if (itemsavethrow.itemSaveTarget(ISM_LIQUID,
                ISF_BLOW_CRUSHING) != 0) ++bad;
        if (itemsavethrow.itemSaveTarget(ISM_LIQUID,
                ISF_FALL) != 0) ++bad;
        if (itemsavethrow.itemSaveTarget(ISM_LIQUID,
                ISF_FIRE_NORMAL) != 13) ++bad;
        // the magical ladder: +1 saves at +2, +2 at +3,
        // +3 at +4, a +5 sword at +6; non-magical 0
        if (itemsavethrow.itemSaveMagicalBonus(0) != 0 ||
            itemsavethrow.itemSaveMagicalBonus(1) != 2 ||
            itemsavethrow.itemSaveMagicalBonus(2) != 3 ||
            itemsavethrow.itemSaveMagicalBonus(3) != 4 ||
            itemsavethrow.itemSaveMagicalBonus(5) != 6) ++bad;
        if (itemsavethrow.itemSaveOwnModeBonus() != 5) ++bad;
        // the fall surfaces: hard 0, wood-like +1, fleshy +5
        if (itemsavethrow.itemSaveFallSurfaceAdj(
                ISFS_HARD) != 0 ||
            itemsavethrow.itemSaveFallSurfaceAdj(
                ISFS_WOODLIKE) != 1 ||
            itemsavethrow.itemSaveFallSurfaceAdj(
                ISFS_FLESHY) != 5) ++bad;
        // the fall distance: through 5 feet free, each 5
        // past the first costs 1
        if (itemsavethrow.itemSaveFallDistanceAdj(5) != 0 ||
            itemsavethrow.itemSaveFallDistanceAdj(9) != 0 ||
            itemsavethrow.itemSaveFallDistanceAdj(10) != -1 ||
            itemsavethrow.itemSaveFallDistanceAdj(25) != -4 ||
            itemsavethrow.itemSaveFallDistanceAdj(100) != -19) ++bad;
        // the cold-strike footnote: -10 on the die
        if (itemsavethrow.itemSaveHardMetalColdStrikePenalty() != 10)
            ++bad;
        // normal-fire exposure: parchment 1, cloth 2, bone 3;
        // the unprinted tail reads 0 (caller-side)
        if (itemsavethrow.itemSaveNormalFireRoundsToAffect(
                ISM_PARCHMENT_PAPER) != 1 ||
            itemsavethrow.itemSaveNormalFireRoundsToAffect(
                ISM_CLOTH) != 2 ||
            itemsavethrow.itemSaveNormalFireRoundsToAffect(
                ISM_BONE_IVORY) != 3 ||
            itemsavethrow.itemSaveNormalFireRoundsToAffect(
                ISM_GLASS) != 0) ++bad;
        // the save convention: SAVES on roll + adj >= target
        if (!itemsavethrow.itemSavesOn(17, 18, 2)) ++bad;
        if (itemsavethrow.itemSavesOn(15, 18, 2)) ++bad;
        if (!itemsavethrow.itemSavesOn(18, 18, 0)) ++bad;
        if (itemsavethrow.itemSavesOn(17, 18, 0)) ++bad;
        printf("R204 item saving throw matrix audit: bad %d\n", bad);
        if (bad) return 1;
    }
