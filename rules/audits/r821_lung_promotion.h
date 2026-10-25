    // ---- R821 lung promotion audit ----
    // THE LUNG PROMOTION - the queued R818 discovery closed (the lung dragon
    // cross-ref cells the R818 aquatic walk left keyless): the MM2 index
    // settles the three cells as FF crossrefs (Sea Dragon (Lung Wang), Spirit
    // Dragon (Shan Lung)) - the promotion comes from the FF print,
    // superseding the OA-seam expectation the R818 prose recorded. THE DEFS:
    // the keys lung_wang and shen_lung, the first FF defs in the registry
    // (the new ff_print xp class, the R73 allowed list patched to carry it).
    // The Lung Wang (Sea Dragon) block, FF print p. 28: AC 0, HD 11-13 (the
    // book-average 38), MOVE 3//9 swim, 3 attacks 1-12/1-12/6-36, treasure
    // H(x2), 60 percent lair, level VIII XP 4,550 + 16/hp (the full kill XP
    // 5,158), very intelligence, neutral, size L (up to 30 diameter). The
    // Shen Lung (Spirit Dragon) block, p. 29: AC 1, HD 9-11 (31), MOVE
    // 12/12//9, 4 attacks 1-4/1-4/2-24/1-8, treasure H, 60 percent lair,
    // level VII XP 1,400 + 12/hp (1,772), high intelligence, chaotic neutral,
    // size L (43 long). THE TWO-VOICE SETTLES: the MM2 index OCR reads Shan
    // Lung - the FF print header reads Shen Lung (the chiang lung prose
    // agrees) and Shen wins; the lung wang block OCR reads the bite 5-36 -
    // the prose reads 6-36 and the prose wins. THE REWIRE: the three R818
    // keyless aquatic cells (CFS die 19 and CSD die 20 sea dragon, RFD die 18
    // spirit dragon) rekey lung_wang/lung_wang/shen_lung - the src cells stay
    // 0, the R818 source census unchanged; the walk-key census bumps 189 ->
    // 192 (the mm2enca.h const, the R818 audit chain, the walk-key census
    // expression, and the lung row check all ride as file patches, the
    // LungDragonRows const stays 3). THE REGISTRY: 810 -> 812 defs, FF 0 ->
    // 2; the R817-R820 registry-floor consts stand as their own round
    // snapshots. THE DOCTRINE: the lung wang steam cone 100 x 50 up to 3 per
    // day (damage equal to current hit points), the scaly command 4-40 x age
    // level, no water fire, the tribute demand; the shen lung no breath
    // weapon, bless and curse 1 per day each, control weather and ice storm 3
    // per day each, no lightning damage but double fire damage, water fire
    // 2-12, immune to poison, no insect within 60 feet, manoeuvrability class
    // E, the language shared with the pan lung. NO gap boxes flip this round
    // (the MM2 arc gap stays 37 closed 0 open).
    {
        using namespace rules;
        int bad = 0;
    if (lungpRound() != 821
            || lungpWangPrintPage() != 28
            || lungpShenPrintPage() != 29
            || lungpWangStatArmorClass() != 0
            || lungpWangStatHitDice() != 11
            || lungpWangStatAvgHp() != 38
            || lungpWangStatNumAttacks() != 3
            || lungpWangStatXp() != 4550
            || lungpWangStatXpPerHp() != 16
            || lungpWangStatXpValue() != 5158
            || lungpWangLairPct() != 60
            || lungpWangScalyCommandMin() != 4
            || lungpWangScalyCommandMax() != 40
            || lungpWangSteamConeLengthFt() != 100
            || lungpWangSteamConeWidthFt() != 50
            || lungpWangSteamPerDay() != 3
            || lungpShenStatArmorClass() != 1
            || lungpShenStatHitDice() != 9
            || lungpShenStatAvgHp() != 31
            || lungpShenStatNumAttacks() != 4
            || lungpShenStatXp() != 1400
            || lungpShenStatXpPerHp() != 12
            || lungpShenStatXpValue() != 1772
            || lungpShenLairPct() != 60
            || lungpShenScalyCommandMin() != 2
            || lungpShenScalyCommandMax() != 20
            || lungpShenWaterFireMax() != 12
            || lungpShenNoInsectRadiusFt() != 60
            || lungpShenBlessCursePerDay() != 1
            || lungpShenWeatherIcePerDay() != 3
            || lungpRegistryBefore() != 810
            || lungpRegistryAfter() != 812
            || lungpFfDefsBefore() != 0
            || lungpFfDefsAfter() != 2
            || lungpCellsRewired() != 3
            || lungpCellCfsRow() != 17
            || lungpCellCsdRow() != 18
            || lungpCellRfdRow() != 16
            || lungpWalkKeyRowsBefore() != 189
            || lungpWalkKeyRowsAfter() != 192
            || !lungpPromotedFromFfPrint()
            || !lungpIndexFrefsPointAtFf()
            || !lungpShanShenSettled()
            || !lungpWangDamageSettled()
            || !lungpWangTurtleBodied()
            || !lungpWangDemandsTribute()
            || !lungpWangNoWaterFire()
            || !lungpShenNoBreathWeapon()
            || !lungpShenLightningFirePoison()
            || !lungpShenManoeuvrabilityE()
            || !lungpSourceCellsUnchanged()
            || !lungpFloorConstsStaySnapshots()
            || !lungpNoGapBoxesFlip()
        )
            ++bad;
        // the lung wang xpValue formula (the band base plus per-hp)
    if (lungpWangStatXpValue() != lungpWangStatXp() + lungpWangStatAvgHp() *
        lungpWangStatXpPerHp()
        )
            ++bad;
        // the shen lung xpValue formula (the band base plus per-hp)
    if (lungpShenStatXpValue() != lungpShenStatXp() + lungpShenStatAvgHp() *
        lungpShenStatXpPerHp()
        )
            ++bad;
        // the registry arithmetic (two defs promoted, the FF class opens)
    if (lungpRegistryAfter() != lungpRegistryBefore() + 2
            || lungpFfDefsAfter() != lungpFfDefsBefore() + 2
            || lungpFfDefsAfter() != 2
        )
            ++bad;
        // the hit dice arithmetic (the book averages)
    if (lungpWangStatAvgHp() != 38
            || lungpShenStatAvgHp() != 31
            || lungpWangStatHitDice() != 11
            || lungpShenStatHitDice() != 9
        )
            ++bad;
        // the walk-key rewire (the 3 cells)
    if (lungpWalkKeyRowsAfter() != lungpWalkKeyRowsBefore() +
        lungpCellsRewired()
            || lungpWalkKeyRowsAfter() != 192
        )
            ++bad;
        // the rewired cell rows (the die arithmetic rides the row + 2)
    if (lungpCellCfsRow() != 17
            || lungpCellCsdRow() != 18
            || lungpCellRfdRow() != 16
            || lungpCellsRewired() != 3
        )
            ++bad;
        // the stat block cells (the FF folios)
    if (lungpWangPrintPage() != 28
            || lungpShenPrintPage() != 29
            || lungpWangStatArmorClass() != 0
            || lungpShenStatArmorClass() != 1
        )
            ++bad;
        // the doctrine cells (the steam cone and the scaly command)
    if (lungpWangSteamConeLengthFt() != 100
            || lungpWangSteamConeWidthFt() != 50
            || lungpWangSteamPerDay() != 3
            || lungpWangScalyCommandMax() != 40
        )
            ++bad;
        // the shen lung doctrine (the spell cadence, the water fire, the
        // radius)
    if (lungpShenBlessCursePerDay() != 1
            || lungpShenWeatherIcePerDay() != 3
            || lungpShenWaterFireMax() != 12
            || lungpShenNoInsectRadiusFt() != 60
        )
            ++bad;
        printf("R821 lung promotion audit: bad %d\n", bad);
        if (bad) return 1;
    }
