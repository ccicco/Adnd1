    // ---- R779 lance charge audit ----
    // THE LANCE CHARGE - the R189 feeder goes live. The three lances (light,
    // medium, heavy horse - the chart rows 24-26) join the weapon registry
    // riding the pinned R189 cells (the weights and dice), the one printed
    // arms price (6 g.p., the equipcosts row) shared by all three; the combat
    // Actor carries the mount field and toActor copies it; the rider's
    // round-one lance strike doubles its damage (the chart asterisk). The
    // p.38 weapon-vs-AC chart lists no lance - the zero adjustment row is the
    // no-adjustment JUDGMENT (the R145 audit rows extended). The R158 speed
    // ladder names no lance - the speed rides the unknown default,
    // contract-side. The spear set-to-receive needs a charging FOE - no
    // monster charge concept exists; the R189 double-asterisk pin stays
    // contract-side
    {
        using namespace rules;
        int bad = 0;
    if (lncChargeFeederRound() != 189
            || lncLanceChargeRound() != 779
            || lncLanceRowCount() != 3
            || lncLanceChargeMultiplier() != 2
            || lncLancePriceGold() != 6
            || !lncLancesDoubleFromChargingMount()
            || !lncRiderRoundOneReadsAsTheCharge()
            || !lncActorCarriesTheMount()
            || !lncToActorCopiesTheMount()
            || !lncLanceRowsRideTheR189Cells()
            || !lncP38CarriesNoLanceRow()
            || !lncLanceSpeedStaysUnknown()
            || !lncSpearSetReceivesContractSide()
        )
            ++bad;
        printf("R779 lance charge audit: bad %d\n", bad);
        if (bad) return 1;
    }
