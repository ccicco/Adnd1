    // ---- R490 WSG mounts and beasts pin audit ----
    // The mounts and beasts of burden chapter, CLOSING it. The catalog: the
    // gorilla - highest intelligence, befriended and trained for instructions
    // and transport, the point man, no stealth with the at-least-1-in-6
    // surprise cut, the 50-degree floor, the 50-50 lethargic-or-aggressive
    // desertion on prohibited terrain, 10x food (plants) and 8x water with
    // the 25 percent foraging no-return; the brown bear - magic to carry
    // reliably, the 30 percent monthly nonmagical reversion, any terrain but
    // swamp and desert, claw sure-footedness against smooth inclined slopes,
    // omnivorous, 8x food and 6x water; the camel - the dromedary hot-desert
    // exclusive with no mountains, forests or swamps and no severe slope,
    // weak below 50 degrees for over two days, the bactrian smaller feet on
    // rocky ground, the two-week fast off the humps with the second-week half
    // capacity and the two-week feeding deadline, the empty camel at 10x food
    // and 20x water reduced proportionately after a shorter fast; the sled
    // dog - the 40-degree ceiling with 2-3 inches of snow, a man's ration
    // daily, the two-day cannibalism bar at 50 percent with the preemptive
    // cull, the seven-dog optimum with the 200 and 300 gold piece losses per
    // dog short and the 3-inch rate cut per three dogs short, the four-dog
    // 9/6/3 rates and the single-dog 6/3 with the rugged ban; the donkey as
    // the mule; the elephant - trained only on command words, the 50-degree
    // floor, no severe slope without a level pass, the 3-inch forage
    // slowdown, fifty food and thirty water rations, the
    // 50-percent-every-six-hours bolt after two unfed days; the horse - the
    // fragile overloaded exception with the one-turn rest per six turns, the
    // half-ration bit with the unloaded back, the 2 percent lame chance per
    // eight rugged hours (1 for the draft) with the 01 temporary at 12 hours
    // of rest and the 02 permanent, four food and four water rations; the
    // mule - hardier but slower, the half-hour stubborn root with the
    // Strength Check and the three-fourths rations for three days; the pony -
    // the horse statements, the mountain breeding, the 2 percent lame per
    // eight hours, three rations; the giant ram - the trained charge, the
    // 70-degree ceiling, the flat dry persuasion but no forests or swamps, 6
    // food and 4 water rising to 6 water above the 50-degree daily high; the
    // sheep - the two-dozen capacity, no proficiency to shepherd, six per
    // handler with another per additional six, the 50-percent-per-hour
    // unsupervised bolt, the 70-degree ceiling, 2 food and 2 water, the
    // nondurable-supplies food value; the yak - the ram-like mountainous
    // arctic exclusive at the 30-degree ceiling, 6 food and 4 water. Animals
    // as individuals: bit players or unique non-player characters, the
    // reputable former-owner information, the sure-footed hates-wet-feet
    // example, the wild-captured trial and error, the controlled exposure,
    // calmness and stability, the instinctive fire fear with the innate
    // weather sense, the acute smell and hearing with the not-capricious
    // note. Table 42: the 14-animal reaction grid on 1d12 across fire,
    // weather, noise, odor and other - leftmost noticed, second agitated,
    // third panicked, the bare trailing slash pinned as the sentinel 13
    // meaning no panic. The bands: the two-round calm window, the
    // trust-the-instinct advice, the panicked irrational flight
    // uncontrollable for 2d3 turns or until far enough away, the fire
    // commentary with the lava and magical-heat extension and the faerie fire
    // exception, the campfire association, the
    // never-comfortable-near-large-blaze rule, the quarter-mile large-blaze
    // and one-mile conflagration sensing, the weather sense with the
    // drastic-and-imminent panic bar, the noise habituation with the
    // simulated combat training, the sharp hearing that never panics at the
    // inaudible, the odor pungency bar with the faint-odor exception, and the
    // other-quirk menagerie. Calming: anyone may try, the proficient with
    // above-average wisdom every round, the nonproficient straight 20 percent
    // with two attempts, movement only while calming, the motion-state
    // persistence with the 50-50 split, the soothe-a-mover requirement, the
    // agitated and panicked proficient-only with the +2 and +4 modifiers, and
    // the re-excitement under an evident condition. Understanding: the animal
    // lore educated guess, the nonproficient sensory guesswork, and the
    // proficient certainty that rules out the rest.
    {
        using namespace rules;
        int bad = 0;
    if (wmbApeSurpriseMin() != 1
            || wmbApeMinTempF() != 50
            || wmbApeDesertChancePct() != 50
            || wmbApeFoodMult() != 10
            || wmbApeWaterMult() != 8
            || wmbApeForageFailPct() != 25
            || wmbBearRevertPct() != 30
            || wmbBearFoodMult() != 8
            || wmbBearWaterMult() != 6
            || wmbCamelMinTempF() != 50
            || wmbCamelWeakDays() != 2
            || wmbCamelMaxDepriveWeeks() != 2
            || wmbCamelDeprivedCapPct() != 50
            || wmbCamelFeedWeeks() != 2
            || wmbCamelEmptyFoodMult() != 10
            || wmbCamelEmptyWaterMult() != 20
            || wmbDogMaxTempF() != 40
            || wmbDogSnowMinIn() != 2
            || wmbDogSnowMaxIn() != 3
            || wmbDogStarveDays() != 2
            || wmbDogCannibalPct() != 50
            || wmbDogTeamFull() != 7
            || wmbDogNormalLossGp() != 200
            || wmbDogMaxLossGp() != 300
            || wmbDogRateStepDogs() != 3
            || wmbDogRateLossIn() != 3
            || wmbDogFourNormalIn() != 9
            || wmbDogFourFullIn() != 6
            || wmbDogFourRuggedIn() != 3
            || wmbDogOneNormalIn() != 6
            || wmbDogOneFullIn() != 3
            || wmbEleMinTempF() != 50
            || wmbEleForageSlowIn() != 3
            || wmbEleFoodRations() != 50
            || wmbEleWaterRations() != 30
            || wmbEleBoltDays() != 2
            || wmbEleBoltCheckHours() != 6
            || wmbEleBoltPct() != 50
            || wmbHorseLoadRestTurns() != 1
            || wmbHorseLoadTravelTurns() != 6
            || wmbHorseBitPct() != 50
            || wmbHorseLamePct() != 2
            || wmbHorseLameHours() != 8
            || wmbDraftLamePct() != 1
            || wmbHorseRecoverHours() != 12
            || wmbHorseFoodRations() != 4
            || wmbHorseWaterRations() != 4
            || wmbMuleStubbornMin() != 30
            || wmbMuleShortRationPct() != 75
            || wmbMuleShortRationDays() != 3
            || wmbPonyLamePct() != 2
            || wmbPonyLameHours() != 8
            || wmbPonyRations() != 3
            || wmbRamMaxTempF() != 70
            || wmbRamFoodRations() != 6
            || wmbRamWaterRations() != 4
            || wmbRamHotWaterRations() != 6
            || wmbRamHotTempF() != 50
            || wmbSheepPerHandler() != 6
            || wmbSheepStepPerHandler() != 6
            || wmbSheepUnsupervisedPct() != 50
            || wmbSheepMaxTempF() != 70
            || wmbSheepFoodRations() != 2
            || wmbSheepWaterRations() != 2
            || wmbYakMaxTempF() != 30
            || wmbYakFoodRations() != 6
            || wmbYakWaterRations() != 4
            || wmbT42AnimalCount() != 14
            || wmbReactDie() != 12
            || wmbReactCalmRounds() != 2
            || wmbReactPanicDice() != 2
            || wmbReactPanicDie() != 3
            || wmbFireBonfireMiNum() != 1
            || wmbFireBonfireMiDen() != 4
            || wmbFireConflagrationMi() != 1
            || wmbCalmNonprofPct() != 20
            || wmbCalmNonprofAttempts() != 2
            || wmbCalmMovePct() != 50
            || wmbCalmAgitatedMod() != 2
            || wmbCalmPanickedMod() != 4
            || !wmbCatalogIntro()
            || !wmbCatalogCrossRefs()
            || !wmbApeHighestInt()
            || !wmbApeBefriendTrain()
            || !wmbApePointMan()
            || !wmbApeNotStealthy()
            || !wmbApeProhibitedDeserts()
            || !wmbBearNeedsMagic()
            || !wmbBearNonmagicRevert()
            || !wmbBearTerrain()
            || !wmbBearClaws()
            || !wmbBearOmnivorous()
            || !wmbCamelDromedaryDesert()
            || !wmbCamelNoMove()
            || !wmbCamelNoSevereSlope()
            || !wmbCamelBactrian()
            || !wmbCamelSecondWeekHalf()
            || !wmbCamelProportionate()
            || !wmbDogColdAdapted()
            || !wmbDogRation()
            || !wmbDogCannibalDetail()
            || !wmbDogFourDogRates()
            || !wmbDogSingleDog()
            || !wmbDonkeySameAsMule()
            || !wmbEleTrainedOnly()
            || !wmbEleNoSlope()
            || !wmbEleForageSlower()
            || !wmbHorseFragile()
            || !wmbHorseStaminaException()
            || !wmbHorseRestBit()
            || !wmbHorseLameSusceptible()
            || !wmbHorseLameTemporary()
            || !wmbHorseLamePermanent()
            || !wmbMuleHardier()
            || !wmbMuleStubborn()
            || !wmbMuleStrengthCheck()
            || !wmbMuleSameAsHorse()
            || !wmbPonyLikeHorse()
            || !wmbPonyMountainBred()
            || !wmbRamChargeTrained()
            || !wmbRamHabitat()
            || !wmbRamPersuadedTerrain()
            || !wmbRamNoForestSwamp()
            || !wmbSheepPackUse()
            || !wmbSheepHerding()
            || !wmbSheepNoProfNeeded()
            || !wmbSheepExtraHandlers()
            || !wmbSheepClimate()
            || !wmbSheepNondurable()
            || !wmbYakLikeRam()
            || !wmbYakMountainous()
            || !wmbYakNormalTerrainNote()
            || !wmbIndivBitPlayers()
            || !wmbIndivNpcTreatment()
            || !wmbIndivFormerOwner()
            || !wmbIndivSurefootedExample()
            || !wmbIndivWildTrial()
            || !wmbIndivControlledExposure()
            || !wmbIndivCalmStability()
            || !wmbIndivFireFear()
            || !wmbIndivWeatherSense()
            || !wmbIndivStartleNoiseSmell()
            || !wmbIndivAcuteSenses()
            || !wmbIndivNotCapricious()
            || !wmbReactNoticed()
            || !wmbReactAgitated()
            || !wmbReactTrustInstinct()
            || !wmbReactPanicked()
            || !wmbReactPanicDuration()
            || !wmbReactNoThirdNoPanic()
            || !wmbFireGreatest()
            || !wmbFireCampfireHabit()
            || !wmbFireNeverComfortableLarge()
            || !wmbFireSensing()
            || !wmbWeatherSenseDetail()
            || !wmbNoiseDetail()
            || !wmbSharpHearing()
            || !wmbOdorDetail()
            || !wmbOtherQuirks()
            || !wmbCalmAnyoneTries()
            || !wmbCalmProfChance()
            || !wmbCalmProfEveryRound()
            || !wmbCalmOnlyMove()
            || !wmbCalmMotionState()
            || !wmbCalmSootheMoving()
            || !wmbCalmAgitatedProfOnly()
            || !wmbCalmReexcite()
            || !wmbUnderstandProf()
            || !wmbUnderstandNonprof()
            || !wmbUnderstandCertainty()
        )
            ++bad;
        // the Table 42 reactions grid: each entry is two or three numbers,
        // each a possible result on a roll of 1d12 when the animal is exposed
        // to the condition - the leftmost is noticed, the second agitated,
        // the third panicked; the sentinel 13 marks the cells whose printed
        // entry ends in a bare trailing slash with no third number, meaning
        // the animal will not become panicked from that condition
        int CT42[14][15] = {
            {8,10,12,6,12,13,8,12,13,9,11,12,8,10,12},
            {4,8,10,6,11,12,6,11,12,5,9,11,5,8,11},
            {6,9,11,6,10,12,6,11,12,4,10,12,6,10,12},
            {4,9,11,6,10,12,4,10,12,4,10,12,5,10,12},
            {4,10,12,6,10,12,6,10,12,6,10,12,6,10,12},
            {4,9,11,7,12,13,8,12,13,8,11,12,8,11,12},
            {5,11,12,8,10,12,4,10,12,7,10,12,6,10,12},
            {4,10,12,5,11,12,6,10,12,7,10,12,5,9,12},
            {4,9,11,5,10,12,4,10,12,6,10,12,6,10,12},
            {6,11,13,6,12,13,6,11,13,7,12,13,6,10,12},
            {4,9,11,5,10,12,4,10,12,6,10,12,6,10,12},
            {6,10,12,8,11,12,8,11,12,6,12,13,6,10,12},
            {4,10,12,7,10,12,8,10,12,8,10,12,6,10,12},
            {7,10,12,7,10,12,8,11,12,6,10,12,7,10,12},
            };
        int nT42[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int eT42[15] = {0,0,1,0,0,3,0,0,3,0,0,2,0,0,0};
        for (int b = 0;
             b < wmbT42AnimalCount();
             ++b) {
            int vals[15];
            vals[0] = wmbT42FireN(b);
            vals[1] = wmbT42FireA(b);
            vals[2] = wmbT42FireP(b);
            vals[3] = wmbT42WeatherN(b);
            vals[4] = wmbT42WeatherA(b);
            vals[5] = wmbT42WeatherP(b);
            vals[6] = wmbT42NoiseN(b);
            vals[7] = wmbT42NoiseA(b);
            vals[8] = wmbT42NoiseP(b);
            vals[9] = wmbT42OdorN(b);
            vals[10] = wmbT42OdorA(b);
            vals[11] = wmbT42OdorP(b);
            vals[12] = wmbT42OtherN(b);
            vals[13] = wmbT42OtherA(b);
            vals[14] = wmbT42OtherP(b);
            for (int c = 0; c < 15;
                 ++c) {
                if (vals[c] != CT42[b][c])
                    ++bad;
                if (vals[c] == 13)
                    ++nT42[c];
            }
        }
        for (int c = 0; c < 15; ++c)
            if (nT42[c] != eT42[c])
                ++bad;
        // the Table 42 band order: noticed strictly below agitated and
        // agitated strictly below panicked for the ape, bear, camel, dog and
        // donkey rows across all five conditions
    if (wmbT42FireN(0) >= wmbT42FireA(0)
            || wmbT42WeatherA(0) >= wmbT42WeatherP(0)
            || wmbT42NoiseN(1) >= wmbT42NoiseA(1)
            || wmbT42OdorA(2) >= wmbT42OdorP(2)
            || wmbT42OtherN(3) >= wmbT42OtherA(3)
            || wmbT42FireA(4) >= wmbT42FireP(4)
        )
            ++bad;
        // the sentinel placement: the mule row carries the
        // bare-trailing-slash sentinel in exactly its fire, weather, noise
        // and odor panic cells, and the ram odor cell, never in a noticed or
        // agitated cell
    if (wmbT42FireP(9) != 13
            || wmbT42WeatherP(9) != 13
            || wmbT42NoiseP(9) != 13
            || wmbT42OdorP(9) != 13
            || wmbT42OtherP(9) != 12
            || wmbT42OdorP(11) != 13
            || wmbT42FireN(9) == 13
            || wmbT42FireA(11) == 13
        )
            ++bad;
        // the ape and elephant no-panic cells: weather and noise end in the
        // sentinel with their exact threshold values
    if (wmbT42WeatherN(0) != 6
            || wmbT42WeatherP(0) != 13
            || wmbT42NoiseN(0) != 8
            || wmbT42NoiseP(0) != 13
            || wmbT42WeatherN(5) != 7
            || wmbT42NoiseN(5) != 8
            || wmbT42WeatherP(5) != 13
            || wmbT42NoiseP(5) != 13
        )
            ++bad;
        // the donkey uniform row: every condition shares agitated 10 and
        // panicked 12 with noticed 4 or 6
    if (wmbT42FireN(4) != 4
            || wmbT42WeatherN(4) != 6
            || wmbT42FireA(4) != 10
            || wmbT42WeatherA(4) != 10
            || wmbT42NoiseA(4) != 10
            || wmbT42OdorA(4) != 10
            || wmbT42OtherA(4) != 10
            || wmbT42OtherP(4) != 12
        )
            ++bad;
        // the boundary rows: the bear fire band 4/8/10, the horse-wild other
        // band 5/9/12, and the yak fire band 7/10/12
    if (wmbT42FireN(1) != 4
            || wmbT42FireA(1) != 8
            || wmbT42FireP(1) != 10
            || wmbT42OtherN(7) != 5
            || wmbT42OtherA(7) != 9
            || wmbT42OtherP(7) != 12
            || wmbT42FireN(13) != 7
            || wmbT42FireA(13) != 10
        )
            ++bad;
        // the animal count and the die: fourteen animals in the grid, the
        // reaction roll on 1d12, with the calm window of two rounds and the
        // panic duration of 2d3 turns
    if (wmbT42AnimalCount() != 14
            || wmbReactDie() != 12
            || wmbReactCalmRounds() != 2
            || wmbReactPanicDice() != 2
            || wmbReactPanicDie() != 3
        )
            ++bad;
        // the fire sensing distances: the large blaze at one-quarter mile and
        // the conflagration at one mile
    if (wmbFireBonfireMiNum() != 1
            || wmbFireBonfireMiDen() != 4
            || wmbFireConflagrationMi() != 1
        )
            ++bad;
        // the ape needs and risks: the 1-in-6 surprise cut, the 50-degree
        // floor, the 50 percent lethargic-or-aggressive split, the 10x food
        // and 8x water multipliers, and the 25 percent foraging failure
        // chance
    if (wmbApeSurpriseMin() != 1
            || wmbApeMinTempF() != 50
            || wmbApeDesertChancePct() != 50
            || wmbApeFoodMult() != 10
            || wmbApeWaterMult() != 8
            || wmbApeForageFailPct() != 25
        )
            ++bad;
        // the bear and camel needs: the bear 30 percent reversion with 8x
        // food and 6x water, the camel 50-degree floor with two-day weakness
        // and the two-week fast halving capacity at the 10x and 20x empty
        // refueling
    if (wmbBearRevertPct() != 30
            || wmbBearFoodMult() != 8
            || wmbBearWaterMult() != 6
            || wmbCamelMinTempF() != 50
            || wmbCamelWeakDays() != 2
            || wmbCamelDeprivedCapPct() != 50
            || wmbCamelEmptyFoodMult() != 10
            || wmbCamelEmptyWaterMult() != 20
        )
            ++bad;
        // the sled dog team: the 40-degree ceiling with 2-3 inches of snow,
        // the two-day cannibalism bar at 50 percent, the seven-dog optimum
        // with the 200 and 300 gold piece losses and the 3-inch rate cut per
        // three dogs short
    if (wmbDogMaxTempF() != 40
            || wmbDogSnowMinIn() != 2
            || wmbDogSnowMaxIn() != 3
            || wmbDogStarveDays() != 2
            || wmbDogCannibalPct() != 50
            || wmbDogTeamFull() != 7
            || wmbDogNormalLossGp() != 200
            || wmbDogMaxLossGp() != 300
            || wmbDogRateStepDogs() != 3
            || wmbDogRateLossIn() != 3
        )
            ++bad;
        // the sled rates: the four-dog 9/6/3 and the single-dog 6/3 with the
        // rugged ban
    if (wmbDogFourNormalIn() != 9
            || wmbDogFourFullIn() != 6
            || wmbDogFourRuggedIn() != 3
            || wmbDogOneNormalIn() != 6
            || wmbDogOneFullIn() != 3
        )
            ++bad;
        // the elephant needs: the 50-degree floor, the 3-inch forage
        // slowdown, the fifty and thirty rations, and the bolt check at 50
        // percent every six hours after two unfed days
    if (wmbEleMinTempF() != 50
            || wmbEleForageSlowIn() != 3
            || wmbEleFoodRations() != 50
            || wmbEleWaterRations() != 30
            || wmbEleBoltDays() != 2
            || wmbEleBoltCheckHours() != 6
            || wmbEleBoltPct() != 50
        )
            ++bad;
        // the horse rules: the overloaded one-turn rest per six turns, the
        // bit at half a man's daily ration, the 2 percent lame chance per
        // eight rugged hours (1 percent for the draft), the 12-hour recovery,
        // and the four food and four water rations
    if (wmbHorseLoadRestTurns() != 1
            || wmbHorseLoadTravelTurns() != 6
            || wmbHorseBitPct() != 50
            || wmbHorseLamePct() != 2
            || wmbHorseLameHours() != 8
            || wmbDraftLamePct() != 1
            || wmbHorseRecoverHours() != 12
            || wmbHorseFoodRations() != 4
            || wmbHorseWaterRations() != 4
        )
            ++bad;
        // the mule and pony: the half-hour stubborn root with the
        // three-fourths rations for three days, and the pony 2 percent lame
        // per eight hours with three rations daily
    if (wmbMuleStubbornMin() != 30
            || wmbMuleShortRationPct() != 75
            || wmbMuleShortRationDays() != 3
            || wmbPonyLamePct() != 2
            || wmbPonyLameHours() != 8
            || wmbPonyRations() != 3
        )
            ++bad;
        // the ram, sheep and yak: the ram 70-degree ceiling with 6 food and 4
        // water rising to 6 above the 50-degree daily high, the sheep six per
        // handler with the 50 percent per hour unsupervised bolt and the
        // 70-degree ceiling, and the yak 30-degree ceiling
    if (wmbRamMaxTempF() != 70
            || wmbRamFoodRations() != 6
            || wmbRamWaterRations() != 4
            || wmbRamHotWaterRations() != 6
            || wmbRamHotTempF() != 50
            || wmbSheepPerHandler() != 6
            || wmbSheepUnsupervisedPct() != 50
            || wmbSheepMaxTempF() != 70
            || wmbYakMaxTempF() != 30
            || wmbYakFoodRations() != 6
            || wmbYakWaterRations() != 4
        )
            ++bad;
        // the calming rules: the straight 20 percent nonproficient chance
        // with two attempts, the 50-50 motion split, and the +2 agitated and
        // +4 panicked proficiency modifiers
    if (wmbCalmNonprofPct() != 20
            || wmbCalmNonprofAttempts() != 2
            || wmbCalmMovePct() != 50
            || wmbCalmAgitatedMod() != 2
            || wmbCalmPanickedMod() != 4
        )
            ++bad;
        // the calming modifiers scale with the condition: the panicked
        // modifier double the agitated modifier
    if (wmbCalmPanickedMod() != 2 * wmbCalmAgitatedMod()
        )
            ++bad;
        printf("R490 WSG mounts and beasts pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
