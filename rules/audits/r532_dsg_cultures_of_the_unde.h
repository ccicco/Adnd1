    // ---- R532 DSG cultures of the underdark audit ----
    // The DSG cultures of the underdark pin the values-and-objectives frame
    // (the proximity-over-alignment trade rule) and the eight race write-ups:
    // the drow matriarchy with the Lolth testing, the kuo-toan Sea Mother and
    // monitors, the duergar discipline and extermination, the mind flayer
    // sun-dousing quest and hybrids, the aboleth water dominion and greater
    // aboleth, the derro war cycle, and the cloaker guerrilla defense.
    {
        using namespace rules;
        int bad = 0;
    if (dncuDrowTestLevel() != 6
            || dncuKuoToaInsanePct() != 5
            || dncuGreaterAbolethMax() != 6
            || dncuGreaterAbolethMult() != 4
            || dncuDerroWarYears() != 20
            || !dncuSegregatedLessTrade()
            || !dncuProximityOverAlignment()
            || !dncuMonsterGuideReferral()
            || !dncuDrowMatriarchal()
            || !dncuDrowLolth()
            || !dncuDrowWebPattern()
            || !dncuDrowCannibalism()
            || !dncuDrowTreatiesBroken()
            || !dncuDrowRuleObjective()
            || !dncuKuoToaPastPrime()
            || !dncuKuoToaSeaMother()
            || !dncuKuoToaMonitors()
            || !dncuKuoToaSlaveTrade()
            || !dncuDuergarDisciplinedEvil()
            || !dncuDuergarDwarfKin()
            || !dncuDuergarSlaves()
            || !dncuDuergarMerciless()
            || !dncuDuergarExterminate()
            || !dncuDuergarCraftTrade()
            || !dncuIllithidAbolethLink()
            || !dncuIllithidBrainHunger()
            || !dncuIllithidDouseSun()
            || !dncuIllithidPracticalRetreat()
            || !dncuIllithidPsionicStatus()
            || !dncuIllithidHybrids()
            || !dncuIllithidImmunityTrade()
            || !dncuAbolethColdlyRuthless()
            || !dncuAbolethWaterDominion()
            || !dncuAbolethIllithidTool()
            || !dncuAbolethNoGod()
            || !dncuAbolethRemoteCities()
            || !dncuDerroChaoticRaiders()
            || !dncuDerroStealNotTrade()
            || !dncuCloakerChildrenOfEarth()
            || !dncuCloakerViolence()
            || !dncuCloakerNoTools()
            || !dncuCloakerGuerrilla()
        )
            ++bad;
        // the culture load-bearing numbers: the 6th-level Lolth test, the 5%
        // kuo-toan insanity, the one-to-six greater aboleth at four-times
        // size, and the 20-year derro war cycle.
    if (dncuDrowTestLevel() != 6
            || dncuKuoToaInsanePct() != 5
            || dncuGreaterAbolethMax() != 6
            || dncuGreaterAbolethMult() != 4
            || dncuDerroWarYears() != 20
        )
            ++bad;
        // the values and objectives frame: the segregated trade, the
        // proximity-over-alignment rule, the monster-guide referral.
    if (dncuSegregatedLessTrade() != 1
            || dncuProximityOverAlignment() != 1
            || dncuMonsterGuideReferral() != 1
        )
            ++bad;
        // the drow write-up: the matriarchy, the Lolth worship, the web
        // pattern, the cannibalism, the broken treaties, the rule objective.
    if (dncuDrowMatriarchal() != 1
            || dncuDrowLolth() != 1
            || dncuDrowWebPattern() != 1
            || dncuDrowCannibalism() != 1
            || dncuDrowTreatiesBroken() != 1
            || dncuDrowRuleObjective() != 1
        )
            ++bad;
        // the kuo-toa write-up: the past-prime race, the Sea Mother dream,
        // the monitors, the slave acquisition.
    if (dncuKuoToaPastPrime() != 1
            || dncuKuoToaSeaMother() != 1
            || dncuKuoToaMonitors() != 1
            || dncuKuoToaSlaveTrade() != 1
        )
            ++bad;
        // the duergar write-up: the disciplined evil, the mercilessness, the
        // extermination tactic, the craft trade.
    if (dncuDuergarDisciplinedEvil() != 1
            || dncuDuergarMerciless() != 1
            || dncuDuergarExterminate() != 1
            || dncuDuergarCraftTrade() != 1
        )
            ++bad;
        // the mind flayer write-up: the sun-dousing goal, the practical
        // retreat, the psionic status, the hybrids, the immunity trade.
    if (dncuIllithidDouseSun() != 1
            || dncuIllithidPracticalRetreat() != 1
            || dncuIllithidPsionicStatus() != 1
            || dncuIllithidHybrids() != 1
            || dncuIllithidImmunityTrade() != 1
        )
            ++bad;
        // the aboleth write-up: the cold ruthlessness, the water dominion,
        // the illithid tool, the godless reverence, the remote cities.
    if (dncuAbolethColdlyRuthless() != 1
            || dncuAbolethWaterDominion() != 1
            || dncuAbolethIllithidTool() != 1
            || dncuAbolethNoGod() != 1
            || dncuAbolethRemoteCities() != 1
        )
            ++bad;
        // the derro and cloaker write-ups: the chaotic raiders, the stealing,
        // the children of the earth, the violence, the toolless culture, the
        // guerrilla defense.
    if (dncuDerroChaoticRaiders() != 1
            || dncuDerroStealNotTrade() != 1
            || dncuCloakerChildrenOfEarth() != 1
            || dncuCloakerViolence() != 1
            || dncuCloakerNoTools() != 1
            || dncuCloakerGuerrilla() != 1
        )
            ++bad;
        printf("R532 DSG cultures of the underdark audit: bad %d\n", bad);
        if (bad) return 1;
    }
