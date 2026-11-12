    // ---- R310: the sage subsection audit ----
    // The DMG SAGE subsection (rules/dmg/sage.h)
    // walked cell for cell against this local
    // ground truth: the fields-count bands, the
    // seven fields with their 68 special
    // knowledge categories, the chance-of-knowing
    // bands, the sage characteristics (the
    // ability dice, the alignment bands, the
    // spell limits), the offer table, the
    // efficiency milestones, the improvement
    // ladder and the information discovery time
    // and cost table.
    {
        Sage sage;
        int bad = 0;
        static const int kFieldLo[7] = {
               1,   31,   51,   61,   71,   81,   91,
        };
        static const int kFieldHi[7] = {
              30,   50,   60,   70,   80,   90,  100,
        };
        static const int kFieldCat[7] = {
              12,   11,    8,   10,   10,    8,    9,
        };
        static const int kFieldFirst[7] = {
               0,   12,   23,   31,   41,   51,   59,
        };
        static const int kCatField[68] = {
               0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
               0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
               1,    1,    1,    2,    2,    2,    2,    2,    2,    2,
               2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
               3,    4,    4,    4,    4,    4,    4,    4,    4,    4,
               4,    5,    5,    5,    5,    5,    5,    5,    5,    6,
               6,    6,    6,    6,    6,    6,    6,    6,
        };
        static const int kBandLo[6] = {
               1,   11,   31,   51,   71,   91,
        };
        static const int kBandHi[6] = {
              10,   30,   50,   70,   90,  100,
        };
        static const int kBandMinor[6] = {
               1,    1,    1,    2,    2,    2,
        };
        static const int kBandSpecial[6] = {
               2,    3,    4,    2,    3,    4,
        };
        static const int kKnowLo[4][3] = {
            {  31,   11,   -1},
            {  46,   31,   11},
            {  61,   57,   26},
            {  81,   76,   61},
        };
        static const int kKnowHi[4][3] = {
            {  50,   20,   -1},
            {  65,   40,   20},
            {  80,   60,   35},
            { 100,   96,   80},
        };
        static const int kDice[6] = {
               8,    4,    6,    6,    6,    6,
        };
        static const int kCnt[6] = {
               1,    1,    1,    3,    2,    2,
        };
        static const int kPlus[6] = {
               7,   14,   12,    0,    3,    2,
        };
        static const int kAlignLo[9] = {
               1,    6,   11,   21,   31,   41,   61,   81,   91,
        };
        static const int kAlignHi[9] = {
               5,   10,   20,   30,   40,   60,   80,   90,  100,
        };
        static const int kSpellKind[7] = {
               0,    0,    0,    0,    1,    1,    2,
        };
        static const int kOfferLo[3] = {
             200,  200, 20000,
        };
        static const int kOfferHi[3] = {
            1200, 1200, 20000,
        };
        static const int kEffCost[3] = {
            20000, 60000, 100000,
        };
        static const int kEffPct[3] = {
              50,   90,  100,
        };
        static const int kImproveCost[4] = {
            5000, 10000, 100000, 200000,
        };
        static const int kImproveMonths[4] = {
               1,    1,   24,   24,
        };
        static const int kImproveMax[4] = {
               5,    5,    3,   -1,
        };
        static const int kTimeLo[4][3] = {
            {   1,    2,   -1},
            {   1,    2,    5},
            {   1,    1,    3},
            {   1,    1,    2},
        };
        static const int kTimeHi[4][3] = {
            {   6,   24,   -1},
            {   4,   20,   40},
            {   3,   12,   30},
            {   2,   10,   12},
        };
        static const int kTimeUnit[4][3] = {
            {   0,    2,    0},
            {   0,    2,    2},
            {   0,    2,    2},
            {   0,    1,    2},
        };
        static const int kCostDay[4] = {
             100, 1000,  500,  200,
        };
        static const int kFree[4] = {
              20,   20,   20,   80,
        };
        // the fields of study
        if (sage.sageFieldCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (sage.sageFieldLo(i) != kFieldLo[i] ||
                sage.sageFieldHi(i) != kFieldHi[i] ||
                sage.sageFieldCategoryCount(i) !=
                    kFieldCat[i] ||
                sage.sageFieldCategoryFirst(i) !=
                    kFieldFirst[i]) ++bad;
        // the field bands tile 1-100 without gaps
        if (sage.sageFieldLo(0) != 1 ||
            sage.sageFieldHi(6) != 100) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.sageFieldHi(i) + 1 !=
                sage.sageFieldLo(i + 1)) ++bad;
        // the category block boundaries (first(0)
        // is 0; first(6) + count(6) is 68)
        if (sage.sageFieldCategoryFirst(0) != 0) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.sageFieldCategoryFirst(i) +
                sage.sageFieldCategoryCount(i) !=
                sage.sageFieldCategoryFirst(i + 1)) ++bad;
        if (sage.sageFieldCategoryFirst(6) +
            sage.sageFieldCategoryCount(6) != 68) ++bad;
        // the categories
        if (sage.sageCategoryCount() != 68) ++bad;
        for (int i = 0; i < 68; ++i)
            if (sage.sageCategoryField(i) !=
                kCatField[i]) ++bad;
        // the category edges sit in their fields
        for (int i = 0; i < 7; ++i)
            if (sage.sageCategoryField(
                    sage.sageFieldCategoryFirst(i)) != i ||
                sage.sageCategoryField(
                    sage.sageFieldCategoryFirst(i) +
                    sage.sageFieldCategoryCount(i) -
                    1) != i) ++bad;
        // the field clamps (field -5 humankind,
        // 99 supernatural and unusual)
        if (sage.sageFieldLo(-5) != 1 ||
            sage.sageFieldHi(-5) != 30 ||
            sage.sageFieldLo(99) != 91 ||
            sage.sageFieldHi(99) != 100 ||
            sage.sageFieldCategoryCount(-5) != 12 ||
            sage.sageFieldCategoryCount(99) != 9 ||
            sage.sageFieldCategoryFirst(-5) != 0 ||
            sage.sageFieldCategoryFirst(99) != 59 ||
            sage.sageCategoryField(-5) != 0 ||
            sage.sageCategoryField(99) != 6) ++bad;
        // the fields-count table
        if (sage.sageFieldsBandCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.sageFieldsBandLo(i) != kBandLo[i] ||
                sage.sageFieldsBandHi(i) != kBandHi[i] ||
                sage.sageFieldsBandMinor(i) !=
                    kBandMinor[i] ||
                sage.sageFieldsBandSpecial(i) !=
                    kBandSpecial[i]) ++bad;
        // the bands tile 1-100
        if (sage.sageFieldsBandLo(0) != 1 ||
            sage.sageFieldsBandHi(5) != 100) ++bad;
        for (int i = 0; i < 5; ++i)
            if (sage.sageFieldsBandHi(i) + 1 !=
                sage.sageFieldsBandLo(i + 1)) ++bad;
        // the band clamps
        if (sage.sageFieldsBandLo(-5) != 1 ||
            sage.sageFieldsBandHi(-5) != 10 ||
            sage.sageFieldsBandLo(99) != 91 ||
            sage.sageFieldsBandHi(99) != 100 ||
            sage.sageFieldsBandMinor(-5) != 1 ||
            sage.sageFieldsBandMinor(99) != 2 ||
            sage.sageFieldsBandSpecial(-5) != 2 ||
            sage.sageFieldsBandSpecial(99) != 4) ++bad;
        // the chance-of-knowing bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (sage.sageKnowLo(s, n) !=
                    kKnowLo[s][n] ||
                    sage.sageKnowHi(s, n) !=
                    kKnowHi[s][n]) ++bad;
        // the none identity (only the
        // out-of-fields exacting cell prints a
        // dash)
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((sage.sageKnowLo(s, n) < 0) !=
                    (sage.sageKnowNone(s, n) == 1)) ++bad;
        // the real bands have lo below hi
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (kKnowLo[s][n] >= 0 &&
                    sage.sageKnowLo(s, n) >=
                    sage.sageKnowHi(s, n)) ++bad;
        // the worked rows: the scrambled major
        // row (61-80, 57-60, 26-35) and the
        // special category column
        if (sage.sageKnowLo(2, 0) != 61 ||
            sage.sageKnowHi(2, 0) != 80 ||
            sage.sageKnowLo(2, 1) != 57 ||
            sage.sageKnowHi(2, 1) != 60 ||
            sage.sageKnowLo(2, 2) != 26 ||
            sage.sageKnowHi(2, 2) != 35 ||
            sage.sageKnowLo(3, 1) != 76 ||
            sage.sageKnowHi(3, 1) != 96 ||
            sage.sageKnowNone(0, 2) != 1 ||
            sage.sageKnowNone(3, 2) != 0) ++bad;
        // the know clamps ((9, 9) the special
        // category exacting cell)
        if (sage.sageKnowLo(-5, -5) != 31 ||
            sage.sageKnowHi(-5, -5) != 50 ||
            sage.sageKnowLo(9, 9) != 61 ||
            sage.sageKnowHi(9, 9) != 80) ++bad;
        // the ability dice rows
        if (sage.sageAbilityCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.sageAbilityDice(i) != kDice[i] ||
                sage.sageAbilityDiceCount(i) != kCnt[i] ||
                sage.sageAbilityPlus(i) != kPlus[i]) ++bad;
        // the worked ability rows: STR d8 + 7,
        // INT d4 + 14, WIS d6 + 12, DEX 3d6,
        // CON 2d6 + 3, CHA 2d6 + 2
        if (sage.sageAbilityDice(0) != 8 ||
            sage.sageAbilityDiceCount(0) != 1 ||
            sage.sageAbilityPlus(0) != 7 ||
            sage.sageAbilityDice(1) != 4 ||
            sage.sageAbilityPlus(1) != 14 ||
            sage.sageAbilityDice(2) != 6 ||
            sage.sageAbilityPlus(2) != 12 ||
            sage.sageAbilityDiceCount(3) != 3 ||
            sage.sageAbilityPlus(3) != 0 ||
            sage.sageAbilityDiceCount(4) != 2 ||
            sage.sageAbilityPlus(4) != 3 ||
            sage.sageAbilityPlus(5) != 2) ++bad;
        // the ability clamps
        if (sage.sageAbilityDice(-5) != 8 ||
            sage.sageAbilityDiceCount(-5) != 1 ||
            sage.sageAbilityPlus(-5) != 7 ||
            sage.sageAbilityDice(99) != 6 ||
            sage.sageAbilityDiceCount(99) != 2 ||
            sage.sageAbilityPlus(99) != 2) ++bad;
        // the alignment bands
        if (sage.sageAlignBandCount() != 9) ++bad;
        for (int i = 0; i < 9; ++i)
            if (sage.sageAlignLo(i) != kAlignLo[i] ||
                sage.sageAlignHi(i) != kAlignHi[i]) ++bad;
        if (sage.sageAlignLo(0) != 1 ||
            sage.sageAlignHi(8) != 100) ++bad;
        for (int i = 0; i < 8; ++i)
            if (sage.sageAlignHi(i) + 1 !=
                sage.sageAlignLo(i + 1)) ++bad;
        // the alignment clamps (band -5 the
        // chaotic evil, 99 the neutral good)
        if (sage.sageAlignLo(-5) != 1 ||
            sage.sageAlignHi(-5) != 5 ||
            sage.sageAlignLo(99) != 91 ||
            sage.sageAlignHi(99) != 100) ++bad;
        // the hit points: 8d4
        if (sage.sageHpDiceCount() != 8 ||
            sage.sageHpDie() != 4) ++bad;
        // the spell kinds and limits
        if (sage.sageSpellKindCount() != 3) ++bad;
        for (int i = 0; i < 7; ++i)
            if (sage.sageSpellKind(i) !=
                kSpellKind[i]) ++bad;
        if (sage.sageSpellMaxDie() != 4 ||
            sage.sageSpellMaxPlus() != 2 ||
            sage.sageSpellMaxLo() != 3 ||
            sage.sageSpellMaxHi() != 6 ||
            sage.sageSpellPerLevelLo() != 1 ||
            sage.sageSpellPerLevelHi() != 4 ||
            sage.sageSpellReadyPerLevel() != 1) ++bad;
        // the spell kind clamps
        if (sage.sageSpellKind(-5) != 0 ||
            sage.sageSpellKind(99) != 2) ++bad;
        // the offer table
        if (sage.sageOfferCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (sage.sageOfferLo(i) != kOfferLo[i] ||
                sage.sageOfferHi(i) != kOfferHi[i]) ++bad;
        // the offer clamps (row 2 the material
        // minimum)
        if (sage.sageOfferLo(-5) != 200 ||
            sage.sageOfferHi(-5) != 1200 ||
            sage.sageOfferLo(99) != 20000 ||
            sage.sageOfferHi(99) != 20000) ++bad;
        // the efficiency milestones and steps
        if (sage.sageEffMilestoneCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (sage.sageEffMilestoneCost(i) !=
                kEffCost[i] ||
                sage.sageEffMilestonePercent(i) !=
                kEffPct[i]) ++bad;
        if (sage.sageEffStepCost() != 1000 ||
            sage.sageEffHighCostPerPercent() != 4000)
            ++bad;
        // the efficiency clamps (the 100,000
        // g.p. full-cost pin)
        if (sage.sageEffMilestoneCost(-5) != 20000 ||
            sage.sageEffMilestonePercent(-5) != 50 ||
            sage.sageEffMilestoneCost(99) != 100000 ||
            sage.sageEffMilestonePercent(99) != 100)
            ++bad;
        // the improvement ladder
        if (sage.sageImproveCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (sage.sageImproveCost(i) !=
                    kImproveCost[i] ||
                sage.sageImproveMonths(i) !=
                    kImproveMonths[i] ||
                sage.sageImproveMax(i) !=
                    kImproveMax[i]) ++bad;
        // the improvement clamps
        if (sage.sageImproveCost(-5) != 5000 ||
            sage.sageImproveMonths(-5) != 1 ||
            sage.sageImproveMax(-5) != 5 ||
            sage.sageImproveCost(99) != 200000 ||
            sage.sageImproveMonths(99) != 24 ||
            sage.sageImproveMax(99) != -1) ++bad;
        // the information discovery time bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (sage.sageTimeLo(s, n) !=
                    kTimeLo[s][n] ||
                    sage.sageTimeHi(s, n) !=
                    kTimeHi[s][n] ||
                    sage.sageTimeUnit(s, n) !=
                    kTimeUnit[s][n]) ++bad;
        // the time none identity
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((sage.sageTimeLo(s, n) < 0) !=
                    (sage.sageTimeNone(s, n) == 1)) ++bad;
        // the worked time rows: the special
        // category specific band is the lone
        // HOURS cell (1-10); the major exacting
        // is 3-30 days
        if (sage.sageTimeLo(3, 1) != 1 ||
            sage.sageTimeHi(3, 1) != 10 ||
            sage.sageTimeUnit(3, 1) != 1 ||
            sage.sageTimeLo(2, 2) != 3 ||
            sage.sageTimeHi(2, 2) != 30 ||
            sage.sageTimeNone(0, 2) != 1 ||
            sage.sageTimeNone(3, 2) != 0) ++bad;
        // the time clamps ((9, 9) the special
        // category exacting cell)
        if (sage.sageTimeLo(9, 9) != 2 ||
            sage.sageTimeHi(9, 9) != 12 ||
            sage.sageTimeUnit(9, 9) != 2 ||
            sage.sageTimeLo(-5, -5) != 1 ||
            sage.sageTimeHi(-5, -5) != 6) ++bad;
        // the cost per day and the free-spread
        // thresholds
        for (int s = 0; s < 4; ++s)
            if (sage.sageCostPerDay(s) != kCostDay[s] ||
                sage.sageFreeSpreadPercent(s) !=
                kFree[s]) ++bad;
        if (sage.sageCostPerDay(-5) != 100 ||
            sage.sageCostPerDay(99) != 200 ||
            sage.sageFreeSpreadPercent(-5) != 20 ||
            sage.sageFreeSpreadPercent(99) != 80) ++bad;
        // the unknown band and the short-term
        // terms
        if (sage.sageUnknownPercentLo() != 51 ||
            sage.sageUnknownPercentHi() != 100 ||
            sage.sageUnknownCostDivisor() != 2 ||
            sage.sageShortTermCostPerDay() != 100 ||
            sage.sageShortTermMaxDays() != 7 ||
            sage.sageShortTermCooldownMonths() != 1 ||
            sage.sagePermanentHireOnly() != 1) ++bad;
        printf("R310 sage subsection audit: bad %d\n", bad);
        if (bad) return 1;
    }
