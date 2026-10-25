    // ---- R310: the sage subsection audit ----
    // The DMG SAGE subsection (rules/sage.h)
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
        if (rules::sageFieldCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::sageFieldLo(i) != kFieldLo[i] ||
                rules::sageFieldHi(i) != kFieldHi[i] ||
                rules::sageFieldCategoryCount(i) !=
                    kFieldCat[i] ||
                rules::sageFieldCategoryFirst(i) !=
                    kFieldFirst[i]) ++bad;
        // the field bands tile 1-100 without gaps
        if (rules::sageFieldLo(0) != 1 ||
            rules::sageFieldHi(6) != 100) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::sageFieldHi(i) + 1 !=
                rules::sageFieldLo(i + 1)) ++bad;
        // the category block boundaries (first(0)
        // is 0; first(6) + count(6) is 68)
        if (rules::sageFieldCategoryFirst(0) != 0) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::sageFieldCategoryFirst(i) +
                rules::sageFieldCategoryCount(i) !=
                rules::sageFieldCategoryFirst(i + 1)) ++bad;
        if (rules::sageFieldCategoryFirst(6) +
            rules::sageFieldCategoryCount(6) != 68) ++bad;
        // the categories
        if (rules::sageCategoryCount() != 68) ++bad;
        for (int i = 0; i < 68; ++i)
            if (rules::sageCategoryField(i) !=
                kCatField[i]) ++bad;
        // the category edges sit in their fields
        for (int i = 0; i < 7; ++i)
            if (rules::sageCategoryField(
                    rules::sageFieldCategoryFirst(i)) != i ||
                rules::sageCategoryField(
                    rules::sageFieldCategoryFirst(i) +
                    rules::sageFieldCategoryCount(i) -
                    1) != i) ++bad;
        // the field clamps (field -5 humankind,
        // 99 supernatural and unusual)
        if (rules::sageFieldLo(-5) != 1 ||
            rules::sageFieldHi(-5) != 30 ||
            rules::sageFieldLo(99) != 91 ||
            rules::sageFieldHi(99) != 100 ||
            rules::sageFieldCategoryCount(-5) != 12 ||
            rules::sageFieldCategoryCount(99) != 9 ||
            rules::sageFieldCategoryFirst(-5) != 0 ||
            rules::sageFieldCategoryFirst(99) != 59 ||
            rules::sageCategoryField(-5) != 0 ||
            rules::sageCategoryField(99) != 6) ++bad;
        // the fields-count table
        if (rules::sageFieldsBandCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::sageFieldsBandLo(i) != kBandLo[i] ||
                rules::sageFieldsBandHi(i) != kBandHi[i] ||
                rules::sageFieldsBandMinor(i) !=
                    kBandMinor[i] ||
                rules::sageFieldsBandSpecial(i) !=
                    kBandSpecial[i]) ++bad;
        // the bands tile 1-100
        if (rules::sageFieldsBandLo(0) != 1 ||
            rules::sageFieldsBandHi(5) != 100) ++bad;
        for (int i = 0; i < 5; ++i)
            if (rules::sageFieldsBandHi(i) + 1 !=
                rules::sageFieldsBandLo(i + 1)) ++bad;
        // the band clamps
        if (rules::sageFieldsBandLo(-5) != 1 ||
            rules::sageFieldsBandHi(-5) != 10 ||
            rules::sageFieldsBandLo(99) != 91 ||
            rules::sageFieldsBandHi(99) != 100 ||
            rules::sageFieldsBandMinor(-5) != 1 ||
            rules::sageFieldsBandMinor(99) != 2 ||
            rules::sageFieldsBandSpecial(-5) != 2 ||
            rules::sageFieldsBandSpecial(99) != 4) ++bad;
        // the chance-of-knowing bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (rules::sageKnowLo(s, n) !=
                    kKnowLo[s][n] ||
                    rules::sageKnowHi(s, n) !=
                    kKnowHi[s][n]) ++bad;
        // the none identity (only the
        // out-of-fields exacting cell prints a
        // dash)
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((rules::sageKnowLo(s, n) < 0) !=
                    (rules::sageKnowNone(s, n) == 1)) ++bad;
        // the real bands have lo below hi
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (kKnowLo[s][n] >= 0 &&
                    rules::sageKnowLo(s, n) >=
                    rules::sageKnowHi(s, n)) ++bad;
        // the worked rows: the scrambled major
        // row (61-80, 57-60, 26-35) and the
        // special category column
        if (rules::sageKnowLo(2, 0) != 61 ||
            rules::sageKnowHi(2, 0) != 80 ||
            rules::sageKnowLo(2, 1) != 57 ||
            rules::sageKnowHi(2, 1) != 60 ||
            rules::sageKnowLo(2, 2) != 26 ||
            rules::sageKnowHi(2, 2) != 35 ||
            rules::sageKnowLo(3, 1) != 76 ||
            rules::sageKnowHi(3, 1) != 96 ||
            rules::sageKnowNone(0, 2) != 1 ||
            rules::sageKnowNone(3, 2) != 0) ++bad;
        // the know clamps ((9, 9) the special
        // category exacting cell)
        if (rules::sageKnowLo(-5, -5) != 31 ||
            rules::sageKnowHi(-5, -5) != 50 ||
            rules::sageKnowLo(9, 9) != 61 ||
            rules::sageKnowHi(9, 9) != 80) ++bad;
        // the ability dice rows
        if (rules::sageAbilityCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::sageAbilityDice(i) != kDice[i] ||
                rules::sageAbilityDiceCount(i) != kCnt[i] ||
                rules::sageAbilityPlus(i) != kPlus[i]) ++bad;
        // the worked ability rows: STR d8 + 7,
        // INT d4 + 14, WIS d6 + 12, DEX 3d6,
        // CON 2d6 + 3, CHA 2d6 + 2
        if (rules::sageAbilityDice(0) != 8 ||
            rules::sageAbilityDiceCount(0) != 1 ||
            rules::sageAbilityPlus(0) != 7 ||
            rules::sageAbilityDice(1) != 4 ||
            rules::sageAbilityPlus(1) != 14 ||
            rules::sageAbilityDice(2) != 6 ||
            rules::sageAbilityPlus(2) != 12 ||
            rules::sageAbilityDiceCount(3) != 3 ||
            rules::sageAbilityPlus(3) != 0 ||
            rules::sageAbilityDiceCount(4) != 2 ||
            rules::sageAbilityPlus(4) != 3 ||
            rules::sageAbilityPlus(5) != 2) ++bad;
        // the ability clamps
        if (rules::sageAbilityDice(-5) != 8 ||
            rules::sageAbilityDiceCount(-5) != 1 ||
            rules::sageAbilityPlus(-5) != 7 ||
            rules::sageAbilityDice(99) != 6 ||
            rules::sageAbilityDiceCount(99) != 2 ||
            rules::sageAbilityPlus(99) != 2) ++bad;
        // the alignment bands
        if (rules::sageAlignBandCount() != 9) ++bad;
        for (int i = 0; i < 9; ++i)
            if (rules::sageAlignLo(i) != kAlignLo[i] ||
                rules::sageAlignHi(i) != kAlignHi[i]) ++bad;
        if (rules::sageAlignLo(0) != 1 ||
            rules::sageAlignHi(8) != 100) ++bad;
        for (int i = 0; i < 8; ++i)
            if (rules::sageAlignHi(i) + 1 !=
                rules::sageAlignLo(i + 1)) ++bad;
        // the alignment clamps (band -5 the
        // chaotic evil, 99 the neutral good)
        if (rules::sageAlignLo(-5) != 1 ||
            rules::sageAlignHi(-5) != 5 ||
            rules::sageAlignLo(99) != 91 ||
            rules::sageAlignHi(99) != 100) ++bad;
        // the hit points: 8d4
        if (rules::sageHpDiceCount() != 8 ||
            rules::sageHpDie() != 4) ++bad;
        // the spell kinds and limits
        if (rules::sageSpellKindCount() != 3) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::sageSpellKind(i) !=
                kSpellKind[i]) ++bad;
        if (rules::sageSpellMaxDie() != 4 ||
            rules::sageSpellMaxPlus() != 2 ||
            rules::sageSpellMaxLo() != 3 ||
            rules::sageSpellMaxHi() != 6 ||
            rules::sageSpellPerLevelLo() != 1 ||
            rules::sageSpellPerLevelHi() != 4 ||
            rules::sageSpellReadyPerLevel() != 1) ++bad;
        // the spell kind clamps
        if (rules::sageSpellKind(-5) != 0 ||
            rules::sageSpellKind(99) != 2) ++bad;
        // the offer table
        if (rules::sageOfferCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::sageOfferLo(i) != kOfferLo[i] ||
                rules::sageOfferHi(i) != kOfferHi[i]) ++bad;
        // the offer clamps (row 2 the material
        // minimum)
        if (rules::sageOfferLo(-5) != 200 ||
            rules::sageOfferHi(-5) != 1200 ||
            rules::sageOfferLo(99) != 20000 ||
            rules::sageOfferHi(99) != 20000) ++bad;
        // the efficiency milestones and steps
        if (rules::sageEffMilestoneCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::sageEffMilestoneCost(i) !=
                kEffCost[i] ||
                rules::sageEffMilestonePercent(i) !=
                kEffPct[i]) ++bad;
        if (rules::sageEffStepCost() != 1000 ||
            rules::sageEffHighCostPerPercent() != 4000)
            ++bad;
        // the efficiency clamps (the 100,000
        // g.p. full-cost pin)
        if (rules::sageEffMilestoneCost(-5) != 20000 ||
            rules::sageEffMilestonePercent(-5) != 50 ||
            rules::sageEffMilestoneCost(99) != 100000 ||
            rules::sageEffMilestonePercent(99) != 100)
            ++bad;
        // the improvement ladder
        if (rules::sageImproveCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (rules::sageImproveCost(i) !=
                    kImproveCost[i] ||
                rules::sageImproveMonths(i) !=
                    kImproveMonths[i] ||
                rules::sageImproveMax(i) !=
                    kImproveMax[i]) ++bad;
        // the improvement clamps
        if (rules::sageImproveCost(-5) != 5000 ||
            rules::sageImproveMonths(-5) != 1 ||
            rules::sageImproveMax(-5) != 5 ||
            rules::sageImproveCost(99) != 200000 ||
            rules::sageImproveMonths(99) != 24 ||
            rules::sageImproveMax(99) != -1) ++bad;
        // the information discovery time bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (rules::sageTimeLo(s, n) !=
                    kTimeLo[s][n] ||
                    rules::sageTimeHi(s, n) !=
                    kTimeHi[s][n] ||
                    rules::sageTimeUnit(s, n) !=
                    kTimeUnit[s][n]) ++bad;
        // the time none identity
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((rules::sageTimeLo(s, n) < 0) !=
                    (rules::sageTimeNone(s, n) == 1)) ++bad;
        // the worked time rows: the special
        // category specific band is the lone
        // HOURS cell (1-10); the major exacting
        // is 3-30 days
        if (rules::sageTimeLo(3, 1) != 1 ||
            rules::sageTimeHi(3, 1) != 10 ||
            rules::sageTimeUnit(3, 1) != 1 ||
            rules::sageTimeLo(2, 2) != 3 ||
            rules::sageTimeHi(2, 2) != 30 ||
            rules::sageTimeNone(0, 2) != 1 ||
            rules::sageTimeNone(3, 2) != 0) ++bad;
        // the time clamps ((9, 9) the special
        // category exacting cell)
        if (rules::sageTimeLo(9, 9) != 2 ||
            rules::sageTimeHi(9, 9) != 12 ||
            rules::sageTimeUnit(9, 9) != 2 ||
            rules::sageTimeLo(-5, -5) != 1 ||
            rules::sageTimeHi(-5, -5) != 6) ++bad;
        // the cost per day and the free-spread
        // thresholds
        for (int s = 0; s < 4; ++s)
            if (rules::sageCostPerDay(s) != kCostDay[s] ||
                rules::sageFreeSpreadPercent(s) !=
                kFree[s]) ++bad;
        if (rules::sageCostPerDay(-5) != 100 ||
            rules::sageCostPerDay(99) != 200 ||
            rules::sageFreeSpreadPercent(-5) != 20 ||
            rules::sageFreeSpreadPercent(99) != 80) ++bad;
        // the unknown band and the short-term
        // terms
        if (rules::sageUnknownPercentLo() != 51 ||
            rules::sageUnknownPercentHi() != 100 ||
            rules::sageUnknownCostDivisor() != 2 ||
            rules::sageShortTermCostPerDay() != 100 ||
            rules::sageShortTermMaxDays() != 7 ||
            rules::sageShortTermCooldownMonths() != 1 ||
            rules::sagePermanentHireOnly() != 1) ++bad;
        printf("R310 sage subsection audit: bad %d\n", bad);
        if (bad) return 1;
    }
