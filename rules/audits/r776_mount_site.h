    // ---- R776 mount site audit ----
    // THE SITE ROUND - the R403 mount layer charges the engine: the Character
    // gains the mount field (the mount actor site), beginCombat reads it (the
    // mounted resolution seam), and the mount layer charge closes with the
    // site. The six feeder seams (R123 movement, R170 followers mounts, R189
    // charge damage, R321 aerial, R328 cavalier, R356 mount spell) stay
    // pinned in their headers - the site reads the layer contract, it does
    // not re-pin the feeders. The R775 fix carries the regtest R403 condition
    // flips: RT file patches ride the in-memory engine text, so the include
    // and this audit block survive alongside the flipped conditions. ONE
    // PATCH PER FILE this round: the multi-patch chaining class (a file
    // patched twice lost the first flip to the stale re-read - the site
    // design exposed it twice, RT and non-RT) means the mountlayer and
    // regtest flips ride single byte-exact span patches, and the generalized
    // chaining fix (a per-file working-text cache) lands as this round's
    // engine self-patch for the future rounds that need it.
    {
        using namespace rules;
        int bad = 0;
    if (dnoMountLayerRound() != 403
            || dnoMountSiteRound() != 776
            || dnoMountedFeederSeams() != 6
            || !dnoCharacterCarriesMount()
            || !dnoCombatOpenReadsMount()
            || !dnoChargeClosedWithSite()
            || !dnoR403AuditFollowsSite()
        )
            ++bad;
        printf("R776 mount site audit: bad %d\n", bad);
        if (bad) return 1;
    }
