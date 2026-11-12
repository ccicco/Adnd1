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
        if (sage.fieldCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (sage.fieldLo(i) != kFieldLo[i] ||
                sage.fieldHi(i) != kFieldHi[i] ||
                sage.fieldCategoryCount(i) !=
                    kFieldCat[i] ||
                sage.fieldCategoryFirst(i) !=
                    kFieldFirst[i]) ++bad;
        // the field bands tile 1-100 without gaps
        if (sage.fieldLo(0) != 1 ||
            sage.fieldHi(6) != 100) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.fieldHi(i) + 1 !=
                sage.fieldLo(i + 1)) ++bad;
        // the category block boundaries (first(0)
        // is 0; first(6) + count(6) is 68)
        if (sage.fieldCategoryFirst(0) != 0) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.fieldCategoryFirst(i) +
                sage.fieldCategoryCount(i) !=
                sage.fieldCategoryFirst(i + 1)) ++bad;
        if (sage.fieldCategoryFirst(6) +
            sage.fieldCategoryCount(6) != 68) ++bad;
        // the categories
        if (sage.categoryCount() != 68) ++bad;
        for (int i = 0; i < 68; ++i)
            if (sage.categoryField(i) !=
                kCatField[i]) ++bad;
        // the category edges sit in their fields
        for (int i = 0; i < 7; ++i)
            if (sage.categoryField(
                    sage.fieldCategoryFirst(i)) != i ||
                sage.categoryField(
                    sage.fieldCategoryFirst(i) +
                    sage.fieldCategoryCount(i) -
                    1) != i) ++bad;
        // the field clamps (field -5 humankind,
        // 99 supernatural and unusual)
        if (sage.fieldLo(-5) != 1 ||
            sage.fieldHi(-5) != 30 ||
            sage.fieldLo(99) != 91 ||
            sage.fieldHi(99) != 100 ||
            sage.fieldCategoryCount(-5) != 12 ||
            sage.fieldCategoryCount(99) != 9 ||
            sage.fieldCategoryFirst(-5) != 0 ||
            sage.fieldCategoryFirst(99) != 59 ||
            sage.categoryField(-5) != 0 ||
            sage.categoryField(99) != 6) ++bad;
        // the fields-count table
        if (sage.fieldsBandCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.fieldsBandLo(i) != kBandLo[i] ||
                sage.fieldsBandHi(i) != kBandHi[i] ||
                sage.fieldsBandMinor(i) !=
                    kBandMinor[i] ||
                sage.fieldsBandSpecial(i) !=
                    kBandSpecial[i]) ++bad;
        // the bands tile 1-100
        if (sage.fieldsBandLo(0) != 1 ||
            sage.fieldsBandHi(5) != 100) ++bad;
        for (int i = 0; i < 5; ++i)
            if (sage.fieldsBandHi(i) + 1 !=
                sage.fieldsBandLo(i + 1)) ++bad;
        // the band clamps
        if (sage.fieldsBandLo(-5) != 1 ||
            sage.fieldsBandHi(-5) != 10 ||
            sage.fieldsBandLo(99) != 91 ||
            sage.fieldsBandHi(99) != 100 ||
            sage.fieldsBandMinor(-5) != 1 ||
            sage.fieldsBandMinor(99) != 2 ||
            sage.fieldsBandSpecial(-5) != 2 ||
            sage.fieldsBandSpecial(99) != 4) ++bad;
        // the chance-of-knowing bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (sage.knowLo(s, n) !=
                    kKnowLo[s][n] ||
                    sage.knowHi(s, n) !=
                    kKnowHi[s][n]) ++bad;
        // the none identity (only the
        // out-of-fields exacting cell prints a
        // dash)
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((sage.knowLo(s, n) < 0) !=
                    (sage.knowNone(s, n) == 1)) ++bad;
        // the real bands have lo below hi
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (kKnowLo[s][n] >= 0 &&
                    sage.knowLo(s, n) >=
                    sage.knowHi(s, n)) ++bad;
        // the worked rows: the scrambled major
        // row (61-80, 57-60, 26-35) and the
        // special category column
        if (sage.knowLo(2, 0) != 61 ||
            sage.knowHi(2, 0) != 80 ||
            sage.knowLo(2, 1) != 57 ||
            sage.knowHi(2, 1) != 60 ||
            sage.knowLo(2, 2) != 26 ||
            sage.knowHi(2, 2) != 35 ||
            sage.knowLo(3, 1) != 76 ||
            sage.knowHi(3, 1) != 96 ||
            sage.knowNone(0, 2) != 1 ||
            sage.knowNone(3, 2) != 0) ++bad;
        // the know clamps ((9, 9) the special
        // category exacting cell)
        if (sage.knowLo(-5, -5) != 31 ||
            sage.knowHi(-5, -5) != 50 ||
            sage.knowLo(9, 9) != 61 ||
            sage.knowHi(9, 9) != 80) ++bad;
        // the ability dice rows
        if (sage.abilityCount() != 6) ++bad;
        for (int i = 0; i < 6; ++i)
            if (sage.abilityDice(i) != kDice[i] ||
                sage.abilityDiceCount(i) != kCnt[i] ||
                sage.abilityPlus(i) != kPlus[i]) ++bad;
        // the worked ability rows: STR d8 + 7,
        // INT d4 + 14, WIS d6 + 12, DEX 3d6,
        // CON 2d6 + 3, CHA 2d6 + 2
        if (sage.abilityDice(0) != 8 ||
            sage.abilityDiceCount(0) != 1 ||
            sage.abilityPlus(0) != 7 ||
            sage.abilityDice(1) != 4 ||
            sage.abilityPlus(1) != 14 ||
            sage.abilityDice(2) != 6 ||
            sage.abilityPlus(2) != 12 ||
            sage.abilityDiceCount(3) != 3 ||
            sage.abilityPlus(3) != 0 ||
            sage.abilityDiceCount(4) != 2 ||
            sage.abilityPlus(4) != 3 ||
            sage.abilityPlus(5) != 2) ++bad;
        // the ability clamps
        if (sage.abilityDice(-5) != 8 ||
            sage.abilityDiceCount(-5) != 1 ||
            sage.abilityPlus(-5) != 7 ||
            sage.abilityDice(99) != 6 ||
            sage.abilityDiceCount(99) != 2 ||
            sage.abilityPlus(99) != 2) ++bad;
        // the alignment bands
        if (sage.alignBandCount() != 9) ++bad;
        for (int i = 0; i < 9; ++i)
            if (sage.alignLo(i) != kAlignLo[i] ||
                sage.alignHi(i) != kAlignHi[i]) ++bad;
        if (sage.alignLo(0) != 1 ||
            sage.alignHi(8) != 100) ++bad;
        for (int i = 0; i < 8; ++i)
            if (sage.alignHi(i) + 1 !=
                sage.alignLo(i + 1)) ++bad;
        // the alignment clamps (band -5 the
        // chaotic evil, 99 the neutral good)
        if (sage.alignLo(-5) != 1 ||
            sage.alignHi(-5) != 5 ||
            sage.alignLo(99) != 91 ||
            sage.alignHi(99) != 100) ++bad;
        // the hit points: 8d4
        if (sage.hpDiceCount() != 8 ||
            sage.hpDie() != 4) ++bad;
        // the spell kinds and limits
        if (sage.spellKindCount() != 3) ++bad;
        for (int i = 0; i < 7; ++i)
            if (sage.spellKind(i) !=
                kSpellKind[i]) ++bad;
        if (sage.spellMaxDie() != 4 ||
            sage.spellMaxPlus() != 2 ||
            sage.spellMaxLo() != 3 ||
            sage.spellMaxHi() != 6 ||
            sage.spellPerLevelLo() != 1 ||
            sage.spellPerLevelHi() != 4 ||
            sage.spellReadyPerLevel() != 1) ++bad;
        // the spell kind clamps
        if (sage.spellKind(-5) != 0 ||
            sage.spellKind(99) != 2) ++bad;
        // the offer table
        if (sage.offerCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (sage.offerLo(i) != kOfferLo[i] ||
                sage.offerHi(i) != kOfferHi[i]) ++bad;
        // the offer clamps (row 2 the material
        // minimum)
        if (sage.offerLo(-5) != 200 ||
            sage.offerHi(-5) != 1200 ||
            sage.offerLo(99) != 20000 ||
            sage.offerHi(99) != 20000) ++bad;
        // the efficiency milestones and steps
        if (sage.effMilestoneCount() != 3) ++bad;
        for (int i = 0; i < 3; ++i)
            if (sage.effMilestoneCost(i) !=
                kEffCost[i] ||
                sage.effMilestonePercent(i) !=
                kEffPct[i]) ++bad;
        if (sage.effStepCost() != 1000 ||
            sage.effHighCostPerPercent() != 4000)
            ++bad;
        // the efficiency clamps (the 100,000
        // g.p. full-cost pin)
        if (sage.effMilestoneCost(-5) != 20000 ||
            sage.effMilestonePercent(-5) != 50 ||
            sage.effMilestoneCost(99) != 100000 ||
            sage.effMilestonePercent(99) != 100)
            ++bad;
        // the improvement ladder
        if (sage.improveCount() != 4) ++bad;
        for (int i = 0; i < 4; ++i)
            if (sage.improveCost(i) !=
                    kImproveCost[i] ||
                sage.improveMonths(i) !=
                    kImproveMonths[i] ||
                sage.improveMax(i) !=
                    kImproveMax[i]) ++bad;
        // the improvement clamps
        if (sage.improveCost(-5) != 5000 ||
            sage.improveMonths(-5) != 1 ||
            sage.improveMax(-5) != 5 ||
            sage.improveCost(99) != 200000 ||
            sage.improveMonths(99) != 24 ||
            sage.improveMax(99) != -1) ++bad;
        // the information discovery time bands
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if (sage.timeLo(s, n) !=
                    kTimeLo[s][n] ||
                    sage.timeHi(s, n) !=
                    kTimeHi[s][n] ||
                    sage.timeUnit(s, n) !=
                    kTimeUnit[s][n]) ++bad;
        // the time none identity
        for (int s = 0; s < 4; ++s)
            for (int n = 0; n < 3; ++n)
                if ((sage.timeLo(s, n) < 0) !=
                    (sage.timeNone(s, n) == 1)) ++bad;
        // the worked time rows: the special
        // category specific band is the lone
        // HOURS cell (1-10); the major exacting
        // is 3-30 days
        if (sage.timeLo(3, 1) != 1 ||
            sage.timeHi(3, 1) != 10 ||
            sage.timeUnit(3, 1) != 1 ||
            sage.timeLo(2, 2) != 3 ||
            sage.timeHi(2, 2) != 30 ||
            sage.timeNone(0, 2) != 1 ||
            sage.timeNone(3, 2) != 0) ++bad;
        // the time clamps ((9, 9) the special
        // category exacting cell)
        if (sage.timeLo(9, 9) != 2 ||
            sage.timeHi(9, 9) != 12 ||
            sage.timeUnit(9, 9) != 2 ||
            sage.timeLo(-5, -5) != 1 ||
            sage.timeHi(-5, -5) != 6) ++bad;
        // the cost per day and the free-spread
        // thresholds
        for (int s = 0; s < 4; ++s)
            if (sage.costPerDay(s) != kCostDay[s] ||
                sage.freeSpreadPercent(s) !=
                kFree[s]) ++bad;
        if (sage.costPerDay(-5) != 100 ||
            sage.costPerDay(99) != 200 ||
            sage.freeSpreadPercent(-5) != 20 ||
            sage.freeSpreadPercent(99) != 80) ++bad;
        // the unknown band and the short-term
        // terms
        if (sage.unknownPercentLo() != 51 ||
            sage.unknownPercentHi() != 100 ||
            sage.unknownCostDivisor() != 2 ||
            sage.shortTermCostPerDay() != 100 ||
            sage.shortTermMaxDays() != 7 ||
            sage.shortTermCooldownMonths() != 1 ||
            sage.permanentHireOnly() != 1) ++bad;
        printf("R310 sage subsection audit: bad %d\n", bad);
        if (bad) return 1;
    }
