    // ---- R925 issue-14 opener audit ----
    // THE DRAGON ISSUE-14 OPENER ROUND - both engine-relevant chains in one
    // round, the two-chain issue-11 walk pattern. CHAIN ONE, the Name That
    // Monster Contest #1 winners (folio 3, PDF 5), the harvest that slipped
    // from issue 13 - the Jarnkung (armor class 3, move 9, the hit-dice cell
    // printing the =) bar garble in the djvu OCR and resolving at the
    // full-res scan to 5, 15 percent lair, 20 percent magic resistance, magic
    // weapons only, the 2-12 tail, the 250-years-ago wizard origin), the
    // Cursed Crimson Crawler (armor class 7, move 60 feet per turn as
    // printed, the hit-dice prose 3d8 + 1d4 = 3 1/2 with the fraction garbled
    // to 3 percent in the OCR and resolved at the full-res scan, pinned as
    // the dice and the 7-halves total, the 1-6 attacks, the 1-12 rocks at 10
    // feet per hit point, the 30-foot hatred death-burst raging 1-4 melee
    // rounds with saves as poison) and the Ulik (armor class 4, move 14, hit
    // dice 4+2, the hypnotic eyes at 90 surprised / 50 aware, the tender tail
    // mace lasting 10-40 blows and regrowing in 6-8 months). CHAIN TWO, the
    // Gregory Rihn lycanthropy variant The Progress of the Disease (folios
    // 29-32, PDF 31, 33-34): the 50 percent bite catch, the 30-60 day onset,
    // the 95 percent first-change panic, the 10 percent insane subjugation,
    // the 5 percent sleep reversion, the 2500-point will-revert threshold,
    // the ten-level experience grid with the row-4 cell printing 1000 where
    // the worked example gives 10,000 - pinned as-scanned, the dropped zero
    // noted never silent - the predominance ladder DECREASING 10 through 01
    // with control, the species-speech ladder 0 through 100, the change-time
    // pinned in halves, the wereshape limits (no human speech, no human
    // weapons, passive items retained, poison working, the wererat poison
    // save reduced), the class rulings (the 4th-level fighter example
    // fighting as a 4-hit-dice monster, the cured 50 percent experience, the
    // thief benefit, the ranger-as-fighter, the bard charisma loss, the
    // halved turn-undead option) and the cures. The folio offset noted: PRINT
    // FOLIO = PDF PAGE MINUS TWO in issue 14, verified at the TOC alignments.
    // Scoped out per the adjudication: the SPACE MARINES article, the M-A
    // Variant and the Total Person charts (another systems), the reviews, the
    // Rust Monster interview (humor, IDEAS USABLE), the Monty Haul satire,
    // the editorial, the comics and the ads; report 014 ships pre-flip with
    // both boxes open, the closing round to flip them.
    {
        using namespace rules;
        int bad = 0;
    if (lycProgressRows() != 10
            || lycBiteCatchPercent() != 50
            || lycOnsetMinDays() != 30
            || lycOnsetMaxDays() != 60
            || lycFirstChangePanicPercent() != 95
            || lycSubjugationPercent() != 10
            || lycSleepRevertPercent() != 5
            || lycRevertWillXp() != 2500
            || lycVoluntaryChangesPerDay() != 1
            || lycInducedChangeRestDays() != 1
            || lycFighterExampleLevel() != 4
            || lycFighterExampleHitDice() != 4
            || lycExampleChangeRounds() != 6
            || lycRoundTwoPenalty() != 2
            || lycRoundThreePenalty() != 4
            || lycCuredXpPercent() != 50
            || lycHereditaryChanceMin() != 1
            || lycHereditaryChanceMax() != 5
            || lycJarnkungAc() != 3
            || lycJarnkungMoveInches() != 9
            || lycJarnkungHitDice() != 5
            || lycJarnkungLairPercent() != 15
            || lycJarnkungMagicResistance() != 20
            || lycJarnkungAppearingMin() != 1
            || lycJarnkungAppearingMax() != 6
            || lycJarnkungLairAppearingMin() != 2
            || lycJarnkungLairAppearingMax() != 12
            || lycJarnkungTailDamageMin() != 2
            || lycJarnkungTailDamageMax() != 12
            || lycJarnkungWizardYearsAgo() != 250
            || lycCrawlerMoveFeetPerTurn() != 60
            || lycCrawlerHdEights() != 3
            || lycCrawlerHdFours() != 1
            || lycCrawlerHdHalves() != 7
            || lycCrawlerAc() != 7
            || lycCrawlerAttacks() != 2
            || lycCrawlerDamageMin() != 1
            || lycCrawlerDamageMax() != 6
            || lycCrawlerRockDamageMin() != 1
            || lycCrawlerRockDamageMax() != 12
            || lycCrawlerRockRangeFeetPerHp() != 10
            || lycCrawlerRageRadiusFeet() != 30
            || lycCrawlerRageMinRounds() != 1
            || lycCrawlerRageMaxRounds() != 4
            || lycUlikAc() != 4
            || lycUlikMoveInches() != 14
            || lycUlikHitDice() != 4
            || lycUlikHitDicePlus() != 2
            || lycUlikLairPercent() != 20
            || lycUlikAppearingMin() != 1
            || lycUlikAppearingMax() != 6
            || lycUlikHypnotizeSurprisedPercent() != 90
            || lycUlikHypnotizeAwarePercent() != 50
            || lycUlikTailBlowMin() != 10
            || lycUlikTailBlowMax() != 40
            || lycUlikTailRegrowMinMonths() != 6
            || lycUlikTailRegrowMaxMonths() != 8
            || !lycAbilityLossProgressive()
            || !lycChildrenInheritCondition()
            || !lycFirstTransformationAtPuberty()
            || !lycAnimalShapeSterile()
            || !lycNoHumanSpeechInAnimalShape()
            || !lycNoHumanWeaponsInAnimalShape()
            || !lycWereratPoisonSaveReduced()
            || !lycCureDiseaseOrCureLycanthropyPermanent()
            || !lycCuredRecoveryTimeEqualsLossTime()
            || !lycWerebearMostUsableForPCs()
            || !lycNpcWerebearsUsuallyLawful()
            || !lycArmorDoesNotVanish()
            || !lycTransformationNotInstantaneous()
            || !lycThievesMayBenefit()
            || !lycRangersFunctionAsFighters()
            || !lycBardsLoseCharisma()
            || !lycClericTurnUndeadMayHalve()
            || !lycJarnkungMagicWeaponsOnly()
            || !lycJarnkungEspRumoredPsionics()
            || !lycCrawlerHatredBurstOnDeath()
            || !lycUlikHypnoticEyes()
            || !lycUlikTailGrowthFallsOff()
            || !lycContestWinnersThree()
        )
            ++bad;
        // the lycanthrope experience grid - ten levels of the Rihn
        // progression, every cell resolved clean at the full-res scan
        // cross-validated against the djvu OCR; the row-4 experience cell
        // prints 1000 where the article worked example gives 10,000 for the
        // werebear of the fourth - pinned as-scanned, the dropped zero noted
        // never silent (folio 32)
        int CLP[10][8] = {
            {0,1,50,50,0,10,0,12},
            {2500,1,50,50,50,9,10,12},
            {5000,2,25,25,60,8,20,8},
            {1000,2,25,10,75,7,30,8},
            {20000,3,10,10,80,6,50,4},
            {35000,3,5,5,85,5,75,4},
            {50000,4,5,5,90,4,90,2},
            {100000,4,0,5,95,3,95,2},
            {150000,5,0,2,99,2,99,1},
            {200000,5,0,1,99,1,100,1},
            };
        int nLP[8] = {0,0,0,0,0,0,0,0};
        int eLP[8] = {0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < lycProgressRows();
             ++b) {
            int vals[8];
            vals[0] = lycExperience(b);
            vals[1] = lycChangesPerDay(b);
            vals[2] = lycInvoluntaryCombPercent(b);
            vals[3] = lycInvoluntarySleepPercent(b);
            vals[4] = lycChangeBackPercent(b);
            vals[5] = lycBeastPredominancePercent(b);
            vals[6] = lycSpeakLanguagePercent(b);
            vals[7] = lycChangeTimeHalves(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CLP[b][c])
                    ++bad;
                if (vals[c] == -1)
                    ++nLP[c];
            }
        }
        for (int c = 0; c < 8; ++c)
            if (nLP[c] != eLP[c])
                ++bad;
        // the Jarnkung block - armor class 3, move 9, hit dice 5 (the =) bar
        // garble resolved at the full-res scan), 15 percent lair, 20 percent
        // magic resistance, magic weapons only (folio 3)
    if (lycJarnkungAc() != 3
            || lycJarnkungMoveInches() != 9
            || lycJarnkungHitDice() != 5
            || lycJarnkungLairPercent() != 15
            || lycJarnkungMagicResistance() != 20
            || lycJarnkungMagicWeaponsOnly() != 1
        )
            ++bad;
        // the Jarnkung numbers - 1-6 appearing, 2-12 in lair, the 2-12 tail,
        // the 250-years-ago wizard origin (folio 3)
    if (lycJarnkungAppearingMin() != 1
            || lycJarnkungAppearingMax() != 6
            || lycJarnkungLairAppearingMin() != 2
            || lycJarnkungLairAppearingMax() != 12
            || lycJarnkungTailDamageMin() != 2
            || lycJarnkungTailDamageMax() != 12
            || lycJarnkungWizardYearsAgo() != 250
        )
            ++bad;
        // the Cursed Crimson Crawler block - armor class 7, move 60 feet per
        // turn as printed, the hit-dice prose 3d8 + 1d4 = 3 1/2 pinned as the
        // dice and the 7-halves total, 2 attacks (folio 3)
    if (lycCrawlerAc() != 7
            || lycCrawlerMoveFeetPerTurn() != 60
            || lycCrawlerHdEights() != 3
            || lycCrawlerHdFours() != 1
            || lycCrawlerHdHalves() != 7
            || lycCrawlerAttacks() != 2
        )
            ++bad;
        // the Crawler attacks - 1-6 per attack, the 1-12 rocks at 10 feet per
        // hit point, the 30-foot hatred burst raging 1-4 melee rounds with
        // saves as poison (folio 3)
    if (lycCrawlerDamageMin() != 1
            || lycCrawlerDamageMax() != 6
            || lycCrawlerRockDamageMin() != 1
            || lycCrawlerRockDamageMax() != 12
            || lycCrawlerRockRangeFeetPerHp() != 10
            || lycCrawlerRageRadiusFeet() != 30
            || lycCrawlerRageMinRounds() != 1
            || lycCrawlerRageMaxRounds() != 4
            || lycCrawlerHatredBurstOnDeath() != 1
        )
            ++bad;
        // the Ulik block - armor class 4, move 14, hit dice 4+2, 20 percent
        // lair, 1-6 appearing, treasure type I (folio 3)
    if (lycUlikAc() != 4
            || lycUlikMoveInches() != 14
            || lycUlikHitDice() != 4
            || lycUlikHitDicePlus() != 2
            || lycUlikLairPercent() != 20
            || lycUlikAppearingMin() != 1
            || lycUlikAppearingMax() != 6
        )
            ++bad;
        // the Ulik ways - the hypnotic eyes at 90 surprised / 50 aware, the
        // tender tail mace lasting 10-40 blows and regrowing in 6-8 months
        // (folio 3)
    if (lycUlikHypnotizeSurprisedPercent() != 90
            || lycUlikHypnotizeAwarePercent() != 50
            || lycUlikTailBlowMin() != 10
            || lycUlikTailBlowMax() != 40
            || lycUlikTailRegrowMinMonths() != 6
            || lycUlikTailRegrowMaxMonths() != 8
            || lycUlikHypnoticEyes() != 1
            || lycUlikTailGrowthFallsOff() != 1
        )
            ++bad;
        // the onset - the 50 percent bite catch, the 30-60 day incubation,
        // the 95 percent first-change animal panic, the 10 percent insane
        // subjugation (folio 29)
    if (lycBiteCatchPercent() != 50
            || lycOnsetMinDays() != 30
            || lycOnsetMaxDays() != 60
            || lycFirstChangePanicPercent() != 95
            || lycSubjugationPercent() != 10
        )
            ++bad;
        // the reversion rules - the 5 percent sleep revert, the 2500-point
        // will-revert threshold, one voluntary change per day, the induced
        // change needing a full day of rest, the progressive ability loss
        // (folios 29-30)
    if (lycSleepRevertPercent() != 5
            || lycRevertWillXp() != 2500
            || lycVoluntaryChangesPerDay() != 1
            || lycInducedChangeRestDays() != 1
            || lycAbilityLossProgressive() != 1
        )
            ++bad;
        // the grid level 1 - 0 experience, one change, 50 percent involuntary
        // in combat or sleep, no voluntary reversion, 10 percent
        // predominance, no species speech, 6 melee rounds to change (folio
        // 32)
    if (lycExperience(0) != 0
            || lycChangesPerDay(0) != 1
            || lycInvoluntaryCombPercent(0) != 50
            || lycInvoluntarySleepPercent(0) != 50
            || lycChangeBackPercent(0) != 0
            || lycBeastPredominancePercent(0) != 10
            || lycSpeakLanguagePercent(0) != 0
            || lycChangeTimeHalves(0) != 12
        )
            ++bad;
        // the grid level 4 - the experience cell printing 1000 as-scanned
        // (the worked example giving 10,000, the dropped zero noted), 25
        // combat / 10 sleep involuntary, 75 reversion, 30 percent speech
        // (folio 32)
    if (lycExperience(3) != 1000
            || lycInvoluntaryCombPercent(3) != 25
            || lycInvoluntarySleepPercent(3) != 10
            || lycChangeBackPercent(3) != 75
            || lycSpeakLanguagePercent(3) != 30
        )
            ++bad;
        // the grid level 10 - 200000 experience, five changes, no combat
        // involuntary, 1 percent sleep, 99 reversion, 1 percent predominance,
        // 100 percent speech, the half-round change (folio 32)
    if (lycExperience(9) != 200000
            || lycChangesPerDay(9) != 5
            || lycInvoluntaryCombPercent(9) != 0
            || lycInvoluntarySleepPercent(9) != 1
            || lycChangeBackPercent(9) != 99
            || lycBeastPredominancePercent(9) != 1
            || lycSpeakLanguagePercent(9) != 100
            || lycChangeTimeHalves(9) != 1
        )
            ++bad;
        // the class rulings - the 4th-level fighter example fighting as a
        // 4-hit-dice monster, the cured 50 percent experience, the thief
        // benefit, the ranger-as-fighter, the bard charisma loss (folios
        // 30-32)
    if (lycFighterExampleLevel() != 4
            || lycFighterExampleHitDice() != 4
            || lycCuredXpPercent() != 50
            || lycThievesMayBenefit() != 1
            || lycRangersFunctionAsFighters() != 1
            || lycBardsLoseCharisma() != 1
        )
            ++bad;
        // the transformation combat - the 6-round worked example at minus 2
        // then minus 4, the non-instantaneous change, the armor that does not
        // vanish (folio 32)
    if (lycExampleChangeRounds() != 6
            || lycRoundTwoPenalty() != 2
            || lycRoundThreePenalty() != 4
            || lycTransformationNotInstantaneous() != 1
            || lycArmorDoesNotVanish() != 1
        )
            ++bad;
        // the cure and the wereshape - the permanent cure in animal form, the
        // recovery time equaling the loss time, the halved turn undead
        // option, the wererat poison save, the no-speech no-weapons wereshape
        // (folios 30-32)
    if (lycCureDiseaseOrCureLycanthropyPermanent() != 1
            || lycCuredRecoveryTimeEqualsLossTime() != 1
            || lycClericTurnUndeadMayHalve() != 1
            || lycWereratPoisonSaveReduced() != 1
            || lycNoHumanSpeechInAnimalShape() != 1
            || lycNoHumanWeaponsInAnimalShape() != 1
        )
            ++bad;
        // the contest harvest landed - three winners in full, the 1-5 percent
        // hereditary option, the bloodline rules, the lawful NPC werebears
        // the most usable player chain (folios 3, 30-32)
    if (lycContestWinnersThree() != 1
            || lycHereditaryChanceMin() != 1
            || lycHereditaryChanceMax() != 5
            || lycChildrenInheritCondition() != 1
            || lycFirstTransformationAtPuberty() != 1
            || lycAnimalShapeSterile() != 1
            || lycNpcWerebearsUsuallyLawful() != 1
            || lycWerebearMostUsableForPCs() != 1
        )
            ++bad;
        // the experience ladder clean rows - 2500, 5000, 20000, 35000, 50000,
        // 100000, 150000, the row-4 1000 noted as-scanned (folio 32)
    if (lycExperience(1) != 2500
            || lycExperience(2) != 5000
            || lycExperience(4) != 20000
            || lycExperience(5) != 35000
            || lycExperience(6) != 50000
            || lycExperience(7) != 100000
            || lycExperience(8) != 150000
        )
            ++bad;
        // the predominance ladder DECREASING with control, printed with
        // leading zeros - 10 through 01 percent (folio 32)
    if (lycBeastPredominancePercent(1) != 9
            || lycBeastPredominancePercent(2) != 8
            || lycBeastPredominancePercent(3) != 7
            || lycBeastPredominancePercent(4) != 6
            || lycBeastPredominancePercent(5) != 5
            || lycBeastPredominancePercent(6) != 4
            || lycBeastPredominancePercent(7) != 3
            || lycBeastPredominancePercent(8) != 2
        )
            ++bad;
        // the species-speech ladder - 10 through 99 percent rising to 100 at
        // level 10 (folio 32)
    if (lycSpeakLanguagePercent(1) != 10
            || lycSpeakLanguagePercent(2) != 20
            || lycSpeakLanguagePercent(3) != 30
            || lycSpeakLanguagePercent(4) != 50
            || lycSpeakLanguagePercent(5) != 75
            || lycSpeakLanguagePercent(6) != 90
            || lycSpeakLanguagePercent(7) != 95
            || lycSpeakLanguagePercent(8) != 99
        )
            ++bad;
        // the cadence and the halves - two changes at level 3, the 4-round
        // rows at 8 halves, the 2-round rows at 4, the 1-round and half-round
        // rows at 2 and 1 (folio 32)
    if (lycChangesPerDay(2) != 2
            || lycChangesPerDay(4) != 3
            || lycChangesPerDay(6) != 4
            || lycChangesPerDay(8) != 5
            || lycChangeTimeHalves(2) != 8
            || lycChangeTimeHalves(4) != 4
            || lycChangeTimeHalves(6) != 2
            || lycChangeTimeHalves(8) != 1
        )
            ++bad;
        // the reversion ladder - 0, 50, 60, 75, 80, 85, 90, 95, 99, 99
        // percent (folio 32)
    if (lycChangeBackPercent(1) != 50
            || lycChangeBackPercent(3) != 75
            || lycChangeBackPercent(5) != 85
            || lycChangeBackPercent(7) != 95
            || lycChangeBackPercent(8) != 99
        )
            ++bad;
        // the involuntary splits - level 5 at 10 and 10, level 7 at 5 and 5,
        // level 8 no combat risk, level 9 at 2 in sleep (folio 32)
    if (lycInvoluntaryCombPercent(4) != 10
            || lycInvoluntaryCombPercent(6) != 5
            || lycInvoluntaryCombPercent(7) != 0
            || lycInvoluntarySleepPercent(4) != 10
            || lycInvoluntarySleepPercent(8) != 2
        )
            ++bad;
        printf("R925 issue-14 opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
