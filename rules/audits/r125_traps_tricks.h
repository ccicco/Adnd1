    // ---- R125: traps and tricks audit (App G/H) ----
    {
        int bad = 0;
        {
            namespace AG = dm::appendixg;
            namespace AH = dm::appendixh;
            // band continuity: the 46 bands tile 1-100 with
            // no gaps and no overlaps (the band edges chain)
            int lo = 1;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                if (AG::trapBandLo(k) != lo) ++bad;
                if (AG::trapBandHi(k) < AG::trapBandLo(k)) ++bad;
                lo = AG::trapBandHi(k) + 1;
            }
            if (lo != 101) ++bad;
            // spot pins from the printed page (p.216)
            if (AG::trapFor(3) != AG::TRAP_ARROW) ++bad;
            if (AG::trapFor(6) != AG::TRAP_ARROW_POISONED) ++bad;
            if (AG::trapFor(9) != AG::TRAP_CALTROPS) ++bad;
            if (AG::trapFor(19) != AG::TRAP_DOOR_ONE_WAY) ++bad;
            if (AG::trapFor(24) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(30) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(46) != AG::TRAP_GAS_OBSCURING) ++bad;
            if (AG::trapFor(57) != AG::TRAP_LIGHTNING_BOLT) ++bad;
            if (AG::trapFor(63) != AG::TRAP_PIT) ++bad;
            if (AG::trapFor(70) != AG::TRAP_PIT_SPIKES) ++bad;
            if (AG::trapFor(72) != AG::TRAP_PIT_POISONED_SPIKES) ++bad;
            if (AG::trapFor(77) != AG::TRAP_BARS_FALLING) ++bad;
            if (AG::trapFor(83) != AG::TRAP_SCYTHE) ++bad;
            if (AG::trapFor(87) != AG::TRAP_SPEAR) ++bad;
            if (AG::trapFor(88) != AG::TRAP_SPEAR_POISONED) ++bad;
            if (AG::trapFor(91) != AG::TRAP_TELEPORTER) ++bad;
            if (AG::trapFor(92) != AG::TRAP_VENT_ACID) ++bad;
            if (AG::trapFor(95) != AG::TRAP_VENT_GAS) ++bad;
            if (AG::trapFor(100) != AG::TRAP_VENT_GAS) ++bad;
            // counts, and every name nonempty and pure ASCII
            if (AG::TRAP_KIND_COUNT != 46) ++bad;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                const char* nm = AG::trapName(k);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // Appendix H: the feature (37) and attribute
            // (65) dressing lists, same name discipline
            if (AH::TRICK_FEATURE_COUNT != 37) ++bad;
            if (AH::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
            for (int f = 0; f < AH::TRICK_FEATURE_COUNT; ++f) {
                const char* nm = AH::trickFeatureName(f);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            for (int a = 0; a < AH::TRICK_ATTRIBUTE_COUNT; ++a) {
                const char* nm = AH::trickAttributeName(a);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // every d% face lands in range (full loop)
            for (int r = 1; r <= 100; ++r)
                if (AG::trapFor(r) < 0 ||
                    AG::trapFor(r) >= AG::TRAP_KIND_COUNT) ++bad;
            // the dressing combo smoke
            if (AH::trickSummary(AH::TF_ALTAR, AH::TA_ANIMATED)
                    != "Altar (Animated)") ++bad;
        }
        printf("R125 traps and tricks audit: bad %d\n", bad);
        if (bad) return 1;
    }
