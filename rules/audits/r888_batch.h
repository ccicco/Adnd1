    // ---- R888 Dragon small variants audit ----
    // THE DRAGON SMALL VARIANTS - the combined issue-1 round, three chains on
    // the variant layer. LANGUAGES (Gold, folios 9-10): the 20-percent Common
    // doctrine, the personal-tongue rules (a native tongue beside Common,
    // thinking in it), and mutual comprehensibility by percentage - the
    // Cavish/Morloch 60-percent encounter is the anecdote-grade example.
    // ELDER (Smith, folio 30): the Noldor elf rides no level restriction, all
    // spell ranges and effects at x1.5 (pinned as the 150-percent 1e
    // conversion), and the Blackmoor-borne doctrine that all elves are immune
    // to any and all sickness and disease - variants against the engine's 1e
    // elf canon (races.h, elf.lua), never core rewrites. THE BULETTE (folio
    // 19): the original Landshark appearance, pinned as LORE and PROVENANCE
    // against the existing MM2 def monsters/monsters/b/bulette.lua - the def
    // is untouched, the stem holds, no competing def ever: the two
    // semi-vulnerable spots (the eyes AC 4, the raised-crest underside AC 6),
    // the never-underground doctrine, the six-die smallest, the
    // scales-as-shields and pairs-territorial lore. HONEST BOUNDARIES: all
    // three chains are OD&D-era variant ink, converted, noted, never silent;
    // Gold's doctrine is prose with one printed number; the Eldar multipliers
    // are the only numeric conversions; the Bulette pins never touch the
    // def's own fields. The Ives gap box flips this round - the dragon
    // report's first flip.
    {
        using namespace rules;
        int bad = 0;
    if (drgCommonPct() != 20
            || drgMutualPctExample() != 60
            || drgNoldorRangePct() != 150
            || drgNoldorEffectPct() != 150
            || drgBulWeakSpots() != 2
            || drgBulEyeAc() != 4
            || drgBulUndersideAc() != 6
            || drgBulSmallestDice() != 6
            || !drgHumansPersonalTongue()
            || !drgPersonalTongueThinking()
            || !drgMutualByPct()
            || !drgNoldorNoLevelCap()
            || !drgElfDiseaseImmune()
            || !drgBulNeverUnderground()
            || !drgBulScalesAsShields()
            || !drgBulPairsTerritorial()
        )
            ++bad;
        // the Rules' 20 percent - some other creatures and monsters know
        // Common (Gold, folio 9)
    if (drgCommonPct() != 20
        )
            ++bad;
        // the Morloch encounter - the Cavish read 60 percent mutually
        // comprehensible, enough to learn they were Neutrals and pay the wine
        // tribute (folio 10)
    if (drgMutualPctExample() != 60
        )
            ++bad;
        // the personal-tongue doctrine - humans carry one and think in it,
        // the telepathy point (folio 10)
    if (drgHumansPersonalTongue() != 1
            || drgPersonalTongueThinking() != 1
        )
            ++bad;
        // mutual comprehensibility goes by percentage - the Gold precedent
        // (folio 10)
    if (drgMutualByPct() != 1
        )
            ++bad;
        // the Noldor elf - all spell ranges and effects at x1.5, the
        // 150-percent conversion (folio 30)
    if (drgNoldorRangePct() != 150
            || drgNoldorEffectPct() != 150
        )
            ++bad;
        // a 6-inch spell range reads 9 under the Noldor multiplier - the
        // conversion example
    if (6 * drgNoldorRangePct() / 100 != 9
        )
            ++bad;
        // the Eldar variants - no level restriction, and the Blackmoor-borne
        // disease immunity for all elves (folio 30)
    if (drgNoldorNoLevelCap() != 1
            || drgElfDiseaseImmune() != 1
        )
            ++bad;
        // the Bulette's two semi-vulnerable spots - the eyes AC 4, the
        // raised-crest underside AC 6 (folio 19)
    if (drgBulWeakSpots() != 2
            || drgBulEyeAc() != 4
            || drgBulUndersideAc() != 6
        )
            ++bad;
        // NEVER found underground - the Dragon lore doctrine rides against
        // the untouched MM2 def (folio 19)
    if (drgBulNeverUnderground() != 1
        )
            ++bad;
        // the smallest ever seen are of the six-die variety; no young have
        // ever been sighted (folio 19)
    if (drgBulSmallestDice() != 6
        )
            ++bad;
        // the Bulette provenance - scales prized as shields, teeth valuable,
        // only mated pairs share territory (folio 19)
    if (drgBulScalesAsShields() != 1
            || drgBulPairsTerritorial() != 1
        )
            ++bad;
        printf("R888 Dragon small variants audit: bad %d\n", bad);
        if (bad) return 1;
    }
