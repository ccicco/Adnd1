    // ---- R185: the multi-class and dual-class audit ----
    // Every race x combo cell, the quotient and split
    // ladders, the allowances and the dual-class gates.
    {
        int bad = 0;
        // the combo counts (human 0, dwarf 1, elf 4,
        // gnome 3, half-elf 8, halfling 1, half-orc 5)
        static const int kCount[7] = {
            0,
            1,
            4,
            3,
            8,
            1,
            5,
        };
        for (int r = 0; r < 7; ++r)
            if (rules::multiClassComboCount(r)
                != kCount[r]) ++bad;
        // every printed combo, positive
        if (!rules::multiClassAllowed(1, 9)) ++bad;
        if (!rules::multiClassAllowed(2, 3)) ++bad;
        if (!rules::multiClassAllowed(2, 9)) ++bad;
        if (!rules::multiClassAllowed(2, 10)) ++bad;
        if (!rules::multiClassAllowed(2, 11)) ++bad;
        if (!rules::multiClassAllowed(3, 17)) ++bad;
        if (!rules::multiClassAllowed(3, 9)) ++bad;
        if (!rules::multiClassAllowed(3, 24)) ++bad;
        if (!rules::multiClassAllowed(4, 5)) ++bad;
        if (!rules::multiClassAllowed(4, 36)) ++bad;
        if (!rules::multiClassAllowed(4, 6)) ++bad;
        if (!rules::multiClassAllowed(4, 3)) ++bad;
        if (!rules::multiClassAllowed(4, 9)) ++bad;
        if (!rules::multiClassAllowed(4, 10)) ++bad;
        if (!rules::multiClassAllowed(4, 7)) ++bad;
        if (!rules::multiClassAllowed(4, 11)) ++bad;
        if (!rules::multiClassAllowed(5, 9)) ++bad;
        if (!rules::multiClassAllowed(6, 5)) ++bad;
        if (!rules::multiClassAllowed(6, 12)) ++bad;
        if (!rules::multiClassAllowed(6, 68)) ++bad;
        if (!rules::multiClassAllowed(6, 9)) ++bad;
        if (!rules::multiClassAllowed(6, 65)) ++bad;
        // the negative probes: unprinted combos
        if (rules::multiClassAllowed(0,
            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        if (rules::multiClassPossible(0)) ++bad;
        if (rules::multiClassAllowed(1,
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (rules::multiClassAllowed(2,
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiClassAllowed(3,
            rules::MC_FIGHTER | rules::MC_RANGER)) ++bad;
        if (rules::multiClassAllowed(5,
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (rules::multiClassAllowed(6,
            rules::MC_FIGHTER | rules::MC_ILLUSIONIST)) ++bad;
        if (rules::multiClassAllowed(4, 0)) ++bad;
        if (rules::multiClassAllowed(4, 1)) ++bad;
        // the clamped reads: index past the list
        // reads the last combo
        if (rules::multiClassCombo(4, 8)
            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER
               | rules::MC_THIEF)) ++bad;
        if (rules::multiClassCombo(4, 99)
            != (rules::MC_FIGHTER | rules::MC_MAGIC_USER
               | rules::MC_THIEF)) ++bad;
        if (rules::multiClassCombo(0, 3) != 0) ++bad;
        if (rules::multiClassCombo(1, 7)
            != (rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        // the hit-point quotient ladder: fractions
        // under one half drop, one half and up
        // rounds up
        if (rules::multiclassHpQuotient(7, 2) != 4) ++bad;
        if (rules::multiclassHpQuotient(6, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(4, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(10, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(11, 3) != 4) ++bad;
        if (rules::multiclassHpQuotient(13, 3) != 4) ++bad;
        if (rules::multiclassHpQuotient(14, 3) != 5) ++bad;
        if (rules::multiclassHpQuotient(9, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(8, 3) != 3) ++bad;
        if (rules::multiclassHpQuotient(0, 0) != 0) ++bad;
        // the even XP split
        if (rules::multiclassXpShare(3000, 2) != 1500) ++bad;
        if (rules::multiclassXpShare(900, 3) != 300) ++bad;
        if (rules::multiclassXpShare(3000, 3) != 1000) ++bad;
        if (rules::multiclassXpShare(0, 2) != 0) ++bad;
        // the stalled-hit-dice rule
        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;
        if (!rules::multiclassHitDieStalled(11, 9)) ++bad;
        if (rules::multiclassHitDieStalled(8, 9)) ++bad;
        if (rules::multiclassHitDieStalled(0, 9)) ++bad;
        // the allowances
        if (!rules::multiclassThiefLimited(
            rules::MC_FIGHTER | rules::MC_THIEF)) ++bad;
        if (rules::multiclassThiefLimited(
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiclassThiefLimited(
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        if (!rules::multiclassClericEdgedOk(
            rules::MC_CLERIC | rules::MC_FIGHTER)) ++bad;
        if (rules::multiclassClericEdgedOk(
            rules::MC_FIGHTER | rules::MC_MAGIC_USER)) ++bad;
        // the half-elf cleric WIS minimum
        if (rules::halfelfClericWisMin() != 13) ++bad;
        // the dual-class gates
        if (!rules::dualClassRaceAllowed(0)) ++bad;
        if (rules::dualClassRaceAllowed(1)) ++bad;
        if (rules::dualClassRaceAllowed(2)) ++bad;
        if (rules::dualClassRaceAllowed(3)) ++bad;
        if (rules::dualClassRaceAllowed(4)) ++bad;
        if (rules::dualClassRaceAllowed(5)) ++bad;
        if (rules::dualClassRaceAllowed(6)) ++bad;
        if (!rules::dualClassPrimeGate(15, 17)) ++bad;
        if (!rules::dualClassPrimeGate(16, 18)) ++bad;
        if (rules::dualClassPrimeGate(14, 17)) ++bad;
        if (rules::dualClassPrimeGate(15, 16)) ++bad;
        if (rules::dualClassPrimeGate(9, 9)) ++bad;
        if (rules::DUAL_CLASS_OLD_PRIME_MIN != 15) ++bad;
        if (rules::DUAL_CLASS_NEW_PRIME_MIN != 17) ++bad;
        printf("R185 multi-class and dual-class audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r186_bard.h"  // R827: migrated
    #include "rules/audits/r187_per_subclass_specials.h"  // R827: migrated
