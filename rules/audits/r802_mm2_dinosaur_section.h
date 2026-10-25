    // ---- R802 MM2 dinosaur section audit ----
    // THE MM2 LETTER D PART 4 - the diakk and the DINOSAUR family of the
    // Monster Manual II arc (the user Go call on the landed devil section).
    // The pin-time walk from the print finds TWENTY entries on pp. 49-55: the
    // diakk at the foot of p. 49 running onto p. 50, the DINOSAUR family head
    // on p. 50 (doctrine only, no stat block), and the 19 dinosaur form stat
    // blocks - Ankisaurus, Camptosaurus, Compsognathus, Dacentrurus,
    // Deinonychus, Dilophosaurus, Dimetrodon, Euparkeria, Kentrosaurus,
    // Mamenchisaurus, Massopondylus, Nothosaurus, Ornitholestes, Phororhacos,
    // Podokesaurus, the giant pterosaur, Struthiomimus, Tanystropheus and
    // Tennodontosaurus. TWENTY defs ride the R791 data_files extension in the
    // MM1 registry schema, registry 583 -> 603. THE GRID: the 20-row
    // DinoStats stat grid (armor class, hit dice, bonus, avgHp, attacks, xp,
    // xp/hp, lair, move, magic resistance). THE SETTLED READS (capture
    // primary, the 1eonline transcription and the archive.org djvu the
    // cross-check voices): the nothosaurus xp/hp 18 (the transcription 12 its
    // own annotation); the struthiomimus tail 2-8 (the transcription 1-8 its
    // own error); the Nighthags word (the capture Nightbags the misread); the
    // podokesaurus prints no prose - its paragraph prints under the
    // struthiomimus block, the print quirk pinned verbatim; the ranged
    // hit-dice cells read the low end (the camptosaurus 1-3 and the
    // dimetrodon 3-to-5, the kuei precedent); the diakk or-forms read the
    // broad max 8+8; the camptosaurus printed 0 attacks clamp to 1 in the
    // loader. NO GAP FLIPS (the letter D box flips only when all the D parts
    // land - the R791 no-flip precedent). NO XP-AUDIT PATCH (mm2_print rides
    // the allowed-source list since R797). The live def walk (the one
    // file-patch site block, no census marker) cross-checks all 20 defs
    // against the DinoStats grid, the loader attack semantics, the
    // podokesaurus print quirk and the registry census floor 583 -> 603.
    {
        using namespace rules;
        int bad = 0;
    if (mm2dnRound() != 802
            || mm2dnRegistryBefore() != 583
            || mm2dnRegistryAfter() != 603
            || mm2dnDefCount() != 20
            || mm2dnEntryCount() != 20
            || mm2dnDinosaurFormCount() != 19
            || mm2dnDinoStatRows() != 20
            || mm2dnDiakkTallHitDiceNum() != 6
            || mm2dnDiakkTallHitDiceBonus() != 6
            || mm2dnDiakkBroadHitDiceNum() != 8
            || mm2dnDiakkBroadHitDiceBonus() != 8
            || mm2dnDiakkCirclingDanceRounds() != 4
            || mm2dnDiakkCirclingDanceMinimum() != 4
            || mm2dnDiakkEnfeeblementCasterLevel() != 13
            || mm2dnDiakkEnfeeblementStrengthLossPct() != 40
            || mm2dnDiakkEnfeeblementDurationRounds() != 13
            || mm2dnDiakkLairBandMin() != 13
            || mm2dnDiakkLairBandMax() != 16
            || mm2dnDiakkWeaknessPerDay() != 1
            || mm2dnDiakkJumpPerDay() != 2
            || mm2dnDiakkAudibleGlamorPerDay() != 1
            || mm2dnDiakkXpValue() != 1732
            || mm2dnDiakkXpLevel() != 7
            || mm2dnAnkisaurusXpValue() != 34
            || mm2dnAnkisaurusXpLevel() != 1
            || mm2dnCamptosaurusXpValue() != 8
            || mm2dnCamptosaurusXpLevel() != 2
            || mm2dnCamptosaurusStampedeRate() != 18
            || mm2dnCamptosaurusHitDiceRangeLow() != 1
            || mm2dnCamptosaurusHitDiceRangeHigh() != 3
            || mm2dnCompsognathusXpValue() != 7
            || mm2dnCompsognathusXpLevel() != 1
            || mm2dnCompsognathusSurpriseMin() != 1
            || mm2dnCompsognathusSurpriseMax() != 3
            || mm2dnDacentrurusXpValue() != 1390
            || mm2dnDacentrurusXpLevel() != 6
            || mm2dnDacentrurusAcThreePct() != 75
            || mm2dnDacentrurusNeckCounterPct() != 25
            || mm2dnDacentrurusNeckDamageMax() != 8
            || mm2dnDeinonychusXpValue() != 205
            || mm2dnDeinonychusXpLevel() != 3
            || mm2dnDeinonychusTalonToHitBonus() != 2
            || mm2dnDeinonychusTalonDamageMin() != 2
            || mm2dnDeinonychusTalonDamageMax() != 12
            || mm2dnDilophosaurusXpValue() != 960
            || mm2dnDilophosaurusXpLevel() != 6
            || mm2dnDimetrodonXpValue() != 105
            || mm2dnDimetrodonXpLevel() != 3
            || mm2dnDimetrodonHitDiceRangeLow() != 3
            || mm2dnDimetrodonHitDiceRangeHigh() != 5
            || mm2dnEuparkeriaXpValue() != 28
            || mm2dnEuparkeriaXpLevel() != 1
            || mm2dnEuparkeriaManSizePackMinimum() != 3
            || mm2dnKentrosaurusXpValue() != 2608
            || mm2dnKentrosaurusXpLevel() != 7
            || mm2dnKentrosaurusAcTwoPct() != 80
            || mm2dnKentrosaurusRearAttackPct() != 25
            || mm2dnKentrosaurusRearDamageMax() != 8
            || mm2dnMamenchisaurusXpValue() != 4575
            || mm2dnMamenchisaurusXpLevel() != 7
            || mm2dnMamenchisaurusNeckFeet() != 35
            || mm2dnMamenchisaurusTrampleDamageMin() != 3
            || mm2dnMamenchisaurusTrampleDamageMax() != 24
            || mm2dnMassopondylusXpValue() != 417
            || mm2dnMassopondylusXpLevel() != 4
            || mm2dnNothosaurusXpValue() != 2682
            || mm2dnNothosaurusXpLevel() != 7
            || mm2dnNothosaurusXpPerHp() != 18
            || mm2dnOrnitholestesXpValue() != 34
            || mm2dnOrnitholestesXpLevel() != 1
            || mm2dnPhororhacosXpValue() != 910
            || mm2dnPhororhacosXpLevel() != 6
            || mm2dnPhororhacosJumpClawDamageMin() != 2
            || mm2dnPhororhacosJumpClawDamageMax() != 8
            || mm2dnPodokesaurusXpValue() != 62
            || mm2dnPodokesaurusXpLevel() != 3
            || mm2dnGiantPterosaurXpValue() != 566
            || mm2dnGiantPterosaurXpLevel() != 5
            || mm2dnPterosaurDiveSurpriseOnD6() != 3
            || mm2dnPterosaurSwoopChanceToHit() != 4
            || mm2dnPterosaurCarryMultipleMin() != 3
            || mm2dnPterosaurCarryMultipleMax() != 4
            || mm2dnPterosaurWeightPounds() != 75
            || mm2dnStruthiomimusXpValue() != 417
            || mm2dnStruthiomimusXpLevel() != 4
            || mm2dnStruthiomimusTailDamageMin() != 2
            || mm2dnStruthiomimusTailDamageMax() != 8
            || mm2dnTanystropheusXpValue() != 645
            || mm2dnTanystropheusXpLevel() != 5
            || mm2dnTanystropheusSurpriseOnD6() != 5
            || mm2dnTanystropheusSurpriseToHitBonus() != 2
            || mm2dnTanystropheusDragUnderPounds() != 500
            || mm2dnTennodontosaurusXpValue() != 1990
            || mm2dnTennodontosaurusXpLevel() != 7
            || mm2dnTennodontosaurusSecondChancePct() != 10
            || mm2dnTennodontosaurusTailDamageMin() != 2
            || mm2dnTennodontosaurusTailDamageMax() != 12
            || !mm2dnDiakkEnfeeblementIgnoresMagicResistance()
            || !mm2dnDiakkDanceIsAreaRayOfEnfeeblement()
            || !mm2dnDiakkPrimeMaterialBySummoningOnly()
            || !mm2dnDiakkNightHagGuards()
            || !mm2dnDiakkSpeaksHadesTongueAndOwn()
            || !mm2dnDinosaursExtremelyStupid()
            || !mm2dnDinosaurMotivationPrimarilyHunger()
            || !mm2dnPredatoryDinosaursFerociousVoracious()
            || !mm2dnHerbivorousDinosaursInsatiable()
            || !mm2dnHerbivoresIgnoreOrFlee()
            || !mm2dnSomePlantEatersAggressiveInDefense()
            || !mm2dnMarineDinosaursOverturnVessels()
            || !mm2dnLandCarnivoresPursueUntilOutOfGrasp()
            || !mm2dnStampedeCarriesSmallerSlowerWeaker()
            || !mm2dnSeveralNotTrueDinosaurs()
            || !mm2dnAnkisaurusClimbsToEscape()
            || !mm2dnCamptosaurusStampedeSaveVsDeathRay()
            || !mm2dnCompsognathusNocturnal()
            || !mm2dnDilophosaurusPrefersOpenAreas()
            || !mm2dnDimetrodonSwimQuestionable()
            || !mm2dnMassopondylusBitesThenRunsAway()
            || !mm2dnNothosaurusFrenzyFlippersSoft()
            || !mm2dnOrnitholestesOutnumberToAttack()
            || !mm2dnPhororhacosAlwaysJumpsInitially()
            || !mm2dnPodokesaurusPrintsNoProse()
            || !mm2dnPterosaurSwoopDoubleDamage()
        )
            ++bad;
        // THE DINOSAUR GRID: the 20-row DinoStats stat grid (every armor
        // class, hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the diakk and the 19 dinosaur form stat
        // blocks, in print order)
        int CDinoStats[20][10] = {
            {0,8,8,36,2,1300,12,25,21,30},
            {7,2,0,7,1,20,2,0,12,0},
            {7,1,0,3,1,5,1,0,9,0},
            {5,1,-1,2,1,5,1,0,10,0},
            {3,10,0,35,1,900,14,0,9,0},
            {4,4,1,15,3,130,5,0,21,0},
            {5,8,2,30,3,600,12,0,18,0},
            {4,3,0,10,1,65,4,0,12,0},
            {5,1,1,4,1,20,2,0,15,0},
            {2,11,0,38,1,2000,16,0,9,0},
            {7,18,0,63,1,3000,25,0,6,0},
            {5,7,0,24,1,225,8,0,15,0},
            {6,14,0,49,3,1800,18,0,3,0},
            {4,2,0,7,1,20,2,0,24,0},
            {6,7,7,31,3,600,10,0,15,0},
            {4,2,2,9,3,35,3,0,21,0},
            {5,6,6,27,1,350,8,0,3,0},
            {6,6,3,24,3,225,8,0,18,0},
            {5,6,6,27,1,375,10,0,6,0},
            {4,10,0,35,2,1500,14,0,24,0},
            };
        for (int b = 0;
             b < mm2dnDinoStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2dnDinoStatAC(b);
            vals[1] = mm2dnDinoStatHd(b);
            vals[2] = mm2dnDinoStatHdBonus(b);
            vals[3] = mm2dnDinoStatAvgHp(b);
            vals[4] = mm2dnDinoStatAttacks(b);
            vals[5] = mm2dnDinoStatXp(b);
            vals[6] = mm2dnDinoStatXpHp(b);
            vals[7] = mm2dnDinoStatLairPct(b);
            vals[8] = mm2dnDinoStatMove(b);
            vals[9] = mm2dnDinoStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CDinoStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count (the census walk)
    if (mm2dnRegistryAfter() - mm2dnRegistryBefore() != mm2dnDefCount()
            || mm2dnDefCount() != 20
            || mm2dnEntryCount() != 20
            || mm2dnDinosaurFormCount() != 19
            || mm2dnDinoStatRows() != 20
        )
            ++bad;
        // each grid xp tile equals its pinned full kill xp (the xpValue
        // formula, pin-vs-pin)
    if (mm2dnDinoStatXp(0) + mm2dnDinoStatXpHp(0) * mm2dnDinoStatAvgHp(0) !=
        mm2dnDiakkXpValue()
            || mm2dnDinoStatXp(1) + mm2dnDinoStatXpHp(1) *
            mm2dnDinoStatAvgHp(1) != mm2dnAnkisaurusXpValue()
            || mm2dnDinoStatXp(2) + mm2dnDinoStatXpHp(2) *
            mm2dnDinoStatAvgHp(2) != mm2dnCamptosaurusXpValue()
            || mm2dnDinoStatXp(3) + mm2dnDinoStatXpHp(3) *
            mm2dnDinoStatAvgHp(3) != mm2dnCompsognathusXpValue()
            || mm2dnDinoStatXp(4) + mm2dnDinoStatXpHp(4) *
            mm2dnDinoStatAvgHp(4) != mm2dnDacentrurusXpValue()
            || mm2dnDinoStatXp(5) + mm2dnDinoStatXpHp(5) *
            mm2dnDinoStatAvgHp(5) != mm2dnDeinonychusXpValue()
            || mm2dnDinoStatXp(6) + mm2dnDinoStatXpHp(6) *
            mm2dnDinoStatAvgHp(6) != mm2dnDilophosaurusXpValue()
            || mm2dnDinoStatXp(7) + mm2dnDinoStatXpHp(7) *
            mm2dnDinoStatAvgHp(7) != mm2dnDimetrodonXpValue()
            || mm2dnDinoStatXp(8) + mm2dnDinoStatXpHp(8) *
            mm2dnDinoStatAvgHp(8) != mm2dnEuparkeriaXpValue()
            || mm2dnDinoStatXp(9) + mm2dnDinoStatXpHp(9) *
            mm2dnDinoStatAvgHp(9) != mm2dnKentrosaurusXpValue()
            || mm2dnDinoStatXp(10) + mm2dnDinoStatXpHp(10) *
            mm2dnDinoStatAvgHp(10) != mm2dnMamenchisaurusXpValue()
            || mm2dnDinoStatXp(11) + mm2dnDinoStatXpHp(11) *
            mm2dnDinoStatAvgHp(11) != mm2dnMassopondylusXpValue()
            || mm2dnDinoStatXp(12) + mm2dnDinoStatXpHp(12) *
            mm2dnDinoStatAvgHp(12) != mm2dnNothosaurusXpValue()
            || mm2dnDinoStatXp(13) + mm2dnDinoStatXpHp(13) *
            mm2dnDinoStatAvgHp(13) != mm2dnOrnitholestesXpValue()
            || mm2dnDinoStatXp(14) + mm2dnDinoStatXpHp(14) *
            mm2dnDinoStatAvgHp(14) != mm2dnPhororhacosXpValue()
            || mm2dnDinoStatXp(15) + mm2dnDinoStatXpHp(15) *
            mm2dnDinoStatAvgHp(15) != mm2dnPodokesaurusXpValue()
            || mm2dnDinoStatXp(16) + mm2dnDinoStatXpHp(16) *
            mm2dnDinoStatAvgHp(16) != mm2dnGiantPterosaurXpValue()
            || mm2dnDinoStatXp(17) + mm2dnDinoStatXpHp(17) *
            mm2dnDinoStatAvgHp(17) != mm2dnStruthiomimusXpValue()
            || mm2dnDinoStatXp(18) + mm2dnDinoStatXpHp(18) *
            mm2dnDinoStatAvgHp(18) != mm2dnTanystropheusXpValue()
            || mm2dnDinoStatXp(19) + mm2dnDinoStatXpHp(19) *
            mm2dnDinoStatAvgHp(19) != mm2dnTennodontosaurusXpValue()
        )
            ++bad;
        // the printed LEVEL cells (the roman ladder walk, pin-vs-print)
    if (mm2dnDiakkXpLevel() != 7
            || mm2dnAnkisaurusXpLevel() != 1
            || mm2dnCamptosaurusXpLevel() != 2
            || mm2dnCompsognathusXpLevel() != 1
            || mm2dnDacentrurusXpLevel() != 6
            || mm2dnDeinonychusXpLevel() != 3
            || mm2dnDilophosaurusXpLevel() != 6
            || mm2dnDimetrodonXpLevel() != 3
            || mm2dnEuparkeriaXpLevel() != 1
            || mm2dnKentrosaurusXpLevel() != 7
            || mm2dnMamenchisaurusXpLevel() != 7
            || mm2dnMassopondylusXpLevel() != 4
            || mm2dnNothosaurusXpLevel() != 7
            || mm2dnOrnitholestesXpLevel() != 1
            || mm2dnPhororhacosXpLevel() != 6
            || mm2dnPodokesaurusXpLevel() != 3
            || mm2dnGiantPterosaurXpLevel() != 5
            || mm2dnStruthiomimusXpLevel() != 4
            || mm2dnTanystropheusXpLevel() != 5
            || mm2dnTennodontosaurusXpLevel() != 7
        )
            ++bad;
        // the settled reads (the nothosaurus 18 xp/hp, the struthiomimus 2-8
        // tail, the nighthags word, the podokesaurus print quirk)
    if (mm2dnNothosaurusXpPerHp() != 18
            || mm2dnStruthiomimusTailDamageMin() != 2
            || mm2dnStruthiomimusTailDamageMax() != 8
            || mm2dnDiakkNightHagGuards() != 1
            || mm2dnPodokesaurusPrintsNoProse() != 1
            || mm2dnPterosaurSwoopChanceToHit() != 4
        )
            ++bad;
        // the diakk doctrine tiles
    if (mm2dnDiakkCirclingDanceRounds() != 4
            || mm2dnDiakkCirclingDanceMinimum() != 4
            || mm2dnDiakkEnfeeblementCasterLevel() != 13
            || mm2dnDiakkEnfeeblementStrengthLossPct() != 40
            || mm2dnDiakkEnfeeblementDurationRounds() != 13
            || mm2dnDiakkLairBandMin() != 13
            || mm2dnDiakkLairBandMax() != 16
            || mm2dnDiakkWeaknessPerDay() != 1
            || mm2dnDiakkJumpPerDay() != 2
            || mm2dnDiakkAudibleGlamorPerDay() != 1
            || mm2dnDiakkTallHitDiceNum() != 6
            || mm2dnDiakkBroadHitDiceNum() != 8
            || mm2dnDiakkEnfeeblementIgnoresMagicResistance() != 1
        )
            ++bad;
        // the dinosaur family doctrine and the form mechanic tiles
    if (mm2dnDinosaursExtremelyStupid() != 1
            || mm2dnStampedeCarriesSmallerSlowerWeaker() != 1
            || mm2dnSeveralNotTrueDinosaurs() != 1
            || mm2dnCamptosaurusStampedeRate() != 18
            || mm2dnCompsognathusSurpriseMin() != 1
            || mm2dnCompsognathusSurpriseMax() != 3
            || mm2dnDacentrurusAcThreePct() != 75
            || mm2dnDacentrurusNeckCounterPct() != 25
            || mm2dnKentrosaurusAcTwoPct() != 80
            || mm2dnKentrosaurusRearAttackPct() != 25
            || mm2dnMamenchisaurusNeckFeet() != 35
            || mm2dnMamenchisaurusTrampleDamageMax() != 24
            || mm2dnDeinonychusTalonToHitBonus() != 2
            || mm2dnTanystropheusSurpriseOnD6() != 5
            || mm2dnTanystropheusDragUnderPounds() != 500
            || mm2dnTennodontosaurusSecondChancePct() != 10
            || mm2dnPterosaurDiveSurpriseOnD6() != 3
            || mm2dnEuparkeriaManSizePackMinimum() != 3
        )
            ++bad;
        // the grid loader-semantics spot tiles (the camptosaurus clamp, the
        // compsognathus minus-1, the ranged low-end reads, the or-form max)
    if (mm2dnDinoStatAttacks(2) != 1
            || mm2dnDinoStatHdBonus(3) != -1
            || mm2dnDinoStatAvgHp(3) != 2
            || mm2dnDinoStatHd(2) != 1
            || mm2dnDinoStatHd(7) != 3
            || mm2dnDinoStatAvgHp(7) != 10
            || mm2dnDinoStatAttacks(0) != 2
            || mm2dnDinoStatHd(0) != 8
            || mm2dnDinoStatAvgHp(0) != 36
            || mm2dnDinoStatAttacks(12) != 3
            || mm2dnDinoStatAttacks(19) != 2
            || mm2dnDinoStatMove(13) != 24
            || mm2dnDinoStatMove(19) != 24
            || mm2dnDinoStatMr(0) != 30
            || mm2dnDinoStatLairPct(0) != 25
        )
            ++bad;
        printf("R802 MM2 dinosaur section audit: bad %d\n", bad);
        if (bad) return 1;
    }
