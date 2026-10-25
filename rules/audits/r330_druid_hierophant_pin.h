    // ---- R330: the druid hierophant pin
    // audit ----
    // The UA druid hierophant ladder
    // (pp. 16-18) - the pin-era pattern:
    // the hierarchy (Great/Grand Druid,
    // the Archdruids), the abdication,
    // the Table I ladder (the xp band
    // lows, the titles, the hp formula),
    // the spell abilities, the
    // 16th-level powers, the plane-entry
    // and conjure ladders, the five
    // conjuring tables, the desire
    // override. The OCR holes (the
    // earth 01-85 HD cell, the L21
    // title) are documented in-header.
    // The R327 druid-limit seam
    // cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the hierarchy
        {
            if (greatDruidLevel() != 14) ++bad;
            if (greatDruidXpLow() != 1500001)
                ++bad;
            if (grandDruidLevel() != 15) ++bad;
            if (grandDruidXpLow() != 3000001)
                ++bad;
            if (grandDruidAttendantCount() != 9)
                ++bad;
            if (grandDruidSpellsPerLevel() != 6)
                ++bad;
            if (grandDruidBonusSpellLevels()
                != 6) ++bad;
            if (archDruidCount() != 3) ++bad;
            if (archDruidLevel() != 13) ++bad;
            if (archDruidBonusSpellLevels()
                != 4) ++bad;
        }
        // U2: the abdication
        {
            if (druidAbdicateXpTotal()
                != 3500001) ++bad;
            if (druidAbdicateAdditionalXp()
                != 500000) ++bad;
            if (druidAbdicateXpAfter() != 1)
                ++bad;
            if (druidAbdicateBonusRelinquished()
                != 6) ++bad;
        }
        // U3: the Table I ladder - the
        // band lows, the titles, the hp
        // formula
        {
            static const int lo[8] = {
                1, 500001, 1000001, 1500001,
                2000001, 2500001, 3000001,
                3500001
            };
            if (hierophantFirstLevel() != 16)
                ++bad;
            if (hierophantTopLevel() != 23)
                ++bad;
            for (int l = 16; l <= 23; ++l)
                if (hierophantXpBandLow(l)
                    != lo[l - 16]) ++bad;
            if (hierophantXpBandLow(15) != 0)
                ++bad;
            if (hierophantHitDice() != 15)
                ++bad;
            for (int l = 16; l <= 23; ++l)
                if (hierophantHpBonus(l)
                    != l - 15) ++bad;
            if (hierophantHpBonus(15) != 0)
                ++bad;
            if (strcmp(hierophantTitleKnown(14),
                "Great Druid") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(15),
                "Grand Druid") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(16),
                "Hierophant Druid") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(17),
                "Hierophant Initiate")
                != 0) ++bad;
            if (strcmp(hierophantTitleKnown(18),
                "Hierophant Adept") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(19),
                "Hierophant Master") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(20),
                "Numinous Hierophant")
                != 0) ++bad;
            if (hierophantTitleKnown(21)[0]
                != 0) ++bad;
            if (strcmp(hierophantTitleKnown(22),
                "Arcane Hierophant") != 0) ++bad;
            if (strcmp(hierophantTitleKnown(23),
                "Hierophant of the Cabal")
                != 0) ++bad;
        }
        // U4: the spell abilities and the
        // 16th-level powers
        {
            if (hierophantSpellMaxPerLevel()
                != 6) ++bad;
            if (hierophantSpellMaxSpellLevel()
                != 7) ++bad;
            if (hierophantCastingLevelCap()
                != 15) ++bad;
            if (hierophantPoisonImmunityLevel()
                != 16) ++bad;
            if (hierophantLongevityDecades(16)
                != 16) ++bad;
            if (hierophantLongevityDecades(23)
                != 23) ++bad;
            if (hierophantAppearanceAlterLevel()
                != 16) ++bad;
            if (hierophantHibernateLevel()
                != 17) ++bad;
        }
        // U5: the plane-entry ladder
        {
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_EARTH) != 17)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_FIRE) != 18)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_WATER) != 19)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_AIR) != 20)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_PARA) != 21)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_SHADOW) != 22)
                ++bad;
            if (hierophantPlaneEnterLevel(
                HIEROPH_PLANE_INNER) != 23)
                ++bad;
            if (hierophantPlaneTransferenceRounds()
                != 1) ++bad;
        }
        // U6: the conjure ladder, the
        // desire override, the hp bonus
        {
            if (hierophantConjureLevel(
                HIEROPH_CONJ_WATER) != 17) ++bad;
            if (hierophantConjureLevel(
                HIEROPH_CONJ_AIR) != 18) ++bad;
            if (hierophantConjureLevel(
                HIEROPH_CONJ_MAGMA_SMOKE) != 19)
                ++bad;
            if (hierophantConjureLevel(
                HIEROPH_CONJ_ICE_OOZE) != 20)
                ++bad;
            if (hierophantConjureUsesPerDay()
                != 1) ++bad;
            if (hierophantConjureDesirePercent(20)
                != 20) ++bad;
            if (hierophantConjureHpBonus(23)
                != 23) ++bad;
        }
        // U7: the conjuring tables - the
        // bounds and the names (the earth
        // row-0 HD hole reads as the
        // creature only)
        {
            static const int lo[5] = {
                1, 86, 95, 99, 0
            };
            static const int hi[5] = {
                85, 94, 98, 100, 0
            };
            for (int t = 0; t < 4; ++t)
                if (hierophantConjureRowCount(t)
                    != 4) ++bad;
            if (hierophantConjureRowCount(4)
                != 3) ++bad;
            for (int t = 0; t < 4; ++t) {
                for (int r = 0; r < 4; ++r) {
                    if (hierophantConjureLow(t, r)
                        != lo[r]) ++bad;
                    if (hierophantConjureHigh(
                        t, r) != hi[r]) ++bad;
                }
            }
            if (hierophantConjureLow(4, 0) != 1
                || hierophantConjureHigh(4, 0)
                    != 85) ++bad;
            if (hierophantConjureLow(4, 1) != 86
                || hierophantConjureHigh(4, 1)
                    != 95) ++bad;
            if (hierophantConjureLow(4, 2) != 96
                || hierophantConjureHigh(4, 2)
                    != 100) ++bad;
            if (strcmp(hierophantConjureName(0, 0),
                "16 HD fire elemental")
                != 0) ++bad;
            if (strcmp(hierophantConjureName(0, 1),
                "2-4 salamanders") != 0) ++bad;
            if (strcmp(hierophantConjureName(0, 2),
                "1 efreeti") != 0) ++bad;
            if (strcmp(hierophantConjureName(0, 3),
                "21-24 HD fire elemental")
                != 0) ++bad;
            if (strcmp(hierophantConjureName(1, 0),
                "earth elemental") != 0) ++bad;
            if (strcmp(hierophantConjureName(1, 1),
                "2-4 xorn") != 0) ++bad;
            if (strcmp(hierophantConjureName(1, 2),
                "1 dao") != 0) ++bad;
            if (strcmp(hierophantConjureName(1, 3),
                "21-24 HD earth elemental")
                != 0) ++bad;
            if (strcmp(hierophantConjureName(2, 1),
                "7-12 tritons on hippocampi")
                != 0) ++bad;
            if (strcmp(hierophantConjureName(2, 2),
                "1 marid") != 0) ++bad;
            if (strcmp(hierophantConjureName(3, 1),
                "2-4 invisible stalkers")
                != 0) ++bad;
            if (strcmp(hierophantConjureName(3, 2),
                "1 djinni") != 0) ++bad;
            if (strcmp(hierophantConjureName(4, 1),
                "special") != 0) ++bad;
            if (hierophantConjureSpecialCount()
                != 4) ++bad;
            if (strcmp(
                hierophantConjureSpecialName(0),
                "5-8 lava children") != 0) ++bad;
            if (strcmp(
                hierophantConjureSpecialName(1),
                "5-8 winter wolves") != 0) ++bad;
            if (strcmp(
                hierophantConjureSpecialName(2),
                "21-24 mudmen") != 0) ++bad;
            if (strcmp(
                hierophantConjureSpecialName(3),
                "21-24 vapor rats") != 0) ++bad;
        }
        // U8: the R327 druid-limit seam
        {
            if (druidClassLevelLimit() != 23)
                ++bad;
            if (hierophantTopLevel()
                != druidClassLevelLimit()) ++bad;
        }
        printf("R330 druid hierophant pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
