    // ---- R446 WSG mountaineering pin audit ----
    // The mountaineering slice pins the essential tools and skills (pitons -
    // metal spikes pounded into cracks for a line anchor, never handholds or
    // footholds; the special hammer, a weapon hammer will not do; the
    // placement knowledge only a mountaineer has), the mountaineer-led roped
    // ascent (one mountaineer enables the whole group on a surface they could
    // not climb, if all are roped together and he leads), the piton-as-anchor
    // uses (a belayer backup, a rappel anchor, a chasm-crossing tie point),
    // and the piton loosen rules (a 10% come-loose chance, checked the first
    // time it supports 100 pounds or more; a passed check stays lodged until
    // a mountaineer dislodges it; a 10% chance a secured piton cannot be
    // dislodged and must be left behind) (rules/wsgmntnr.h, prefix wmt);
    // census 370 -> 371.
    {
        using namespace rules;
        int bad = 0;
    if (wmtLoosenPct() != 10
            || wmtFirstCheckLbs() != 100
            || wmtStuckPct() != 10
            || !wmtSlightlyBetterWithoutGear()
            || !wmtLifeAndDeathOnDifficult()
            || !wmtPitonsAreAnchorsNotHolds()
            || !wmtSpecialHammerRequired()
            || !wmtPlacementKnowledge()
            || !wmtLeadsRopedGroup()
            || !wmtPitonBackupForBelayer()
            || !wmtPassedCheckStaysLodged()
            || !wmtStuckMustBeLeftBehind()
        )
            ++bad;
        // the two piton chances: a 10% come-loose chance on the first load,
        // and a 10% cannot-be-dislodged chance on removal
    if (wmtLoosenPct() != 10
            || wmtStuckPct() != 10
        )
            ++bad;
        // the first-check threshold: the loosen chance is checked the first
        // time the piton supports 100 pounds or more
    if (wmtFirstCheckLbs() != 100
        )
            ++bad;
        // the piton arithmetic anchor: the two chances are equal at 10, and
        // the 100-pound threshold is ten times the loosen percentage
    if (wmtLoosenPct() != wmtStuckPct()
            || wmtFirstCheckLbs() != 10 * wmtLoosenPct()
        )
            ++bad;
        // all three piton numbers are positive: a real chance, a real chance,
        // a real threshold
    if (wmtLoosenPct() <= 0
            || wmtStuckPct() <= 0
            || wmtFirstCheckLbs() <= 0
        )
            ++bad;
        // the printed pair: the 10% chance at the 100-pound check - both
        // digits exactly as the book prints them
    if (wmtLoosenPct() != 10
            || wmtFirstCheckLbs() != 100
        )
            ++bad;
        printf("R446 WSG mountaineering pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
