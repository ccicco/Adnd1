    // ---- R766 OA Daily Life Food audit ----
    // OA round one hundred fifty-three (capture p. 307): the Chapter 15
    // daily-life opener, Food - the rice constant, the eaten-rice greeting,
    // the poor man millet, the soy sauce and tofu, the garden vegetables, the
    // water products, single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmbRiceUsesCount() != 7
            || dmbBeanVarietiesCount() != 4
            || !dmbRiceTheConstant()
            || !dmbEatenRiceGreeting()
            || !dmbRiceStuffOfLife()
            || !dmbPoorMansSubstitutes()
            || !dmbBeansWithRice()
            || !dmbBeanPasteVariety()
            || !dmbSoyPreparedFoods()
            || !dmbTofuFromSoyMilk()
            || !dmbSoySauceProcess()
            || !dmbVegetablesNextToRice()
            || !dmbVegetablesRarelyRaw()
            || !dmbGardenVariety()
            || !dmbPickledPreparations()
            || !dmbWaterProductsImportant()
            || !dmbFishHundredsOfVarieties()
            || !dmbDelicaciesAndDangers()
            || !dmbKelpHarvested()
            || !dmbSeaFullyUsed()
        )
            ++bad;
        // the rice example
    if (dmbRiceUsesCount() != 7
            || dmbRiceTheConstant() != 1
            || dmbEatenRiceGreeting() != 1
        )
            ++bad;
        // the life example
    if (dmbRiceStuffOfLife() != 1
            || dmbPoorMansSubstitutes() != 1
        )
            ++bad;
        // the beans example
    if (dmbBeanVarietiesCount() != 4
            || dmbBeansWithRice() != 1
            || dmbBeanPasteVariety() != 1
        )
            ++bad;
        // the soy example
    if (dmbSoyPreparedFoods() != 1
            || dmbTofuFromSoyMilk() != 1
            || dmbSoySauceProcess() != 1
        )
            ++bad;
        // the garden example
    if (dmbVegetablesNextToRice() != 1
            || dmbVegetablesRarelyRaw() != 1
            || dmbGardenVariety() != 1
        )
            ++bad;
        // the pickles example
    if (dmbPickledPreparations() != 1
        )
            ++bad;
        // the water example
    if (dmbWaterProductsImportant() != 1
            || dmbFishHundredsOfVarieties() != 1
            || dmbDelicaciesAndDangers() != 1
        )
            ++bad;
        // the sea example
    if (dmbKelpHarvested() != 1
            || dmbSeaFullyUsed() != 1
        )
            ++bad;
        printf("R766 OA Daily Life Food audit: bad %d\n", bad);
        if (bad) return 1;
    }
