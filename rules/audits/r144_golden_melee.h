    // ---- R144: p.71 golden melee audit ----
    // The book's own worked fight, transcribed from the
    // 1eonline.info compilation (the DMG re-upload's OCR
    // died in the preface - the book-verify debt stands).
    // The engine matches every printed matrix cell, the
    // STR 17 adjustments, the fighter save, and the mace-
    // vs-plate row. The example's other weapon numbers are
    // the book's own editorial errors (Gygax, on the
    // example: 'added by the editors, thus slipped past
    // and never got corrected') or per-weapon rows beyond
    // the engine's 3-class p.38 approximation - both
    // pinned here AS the engine's values, both named in
    // the gap report.
    {
        int bad = 0;
        // Aggro the Axe, F4, vs. Balto unarmored (AC 10):
        // the book - 'Aggro needs a base 8 to hit Balto'
        if (rules::attackNumber(0, 4, 10) != 8) ++bad;
        // Arlanni, T2, sling vs. Blastum unarmored:
        // 'would usually need an 11 to hit'
        if (rules::attackNumber(3, 2, 10) != 11) ++bad;
        // Gutboy Barrelhouse, F6 dwarf, hammer vs. Arkayn
        // in scale mail and shield (AC 5): '11 before
        // bonuses'
        if (rules::attackNumber(0, 6, 5) != 11) ++bad;
        // Barjin, F4 side of the 4/5 F/MU, sword vs. the
        // same cleric: 'needs a 13 or better to hit'
        if (rules::attackNumber(0, 4, 5) != 13) ++bad;
        // Arkayn, C4, mace vs. Gutboy's effective AC 1:
        // 'Arkayn needs a base 17 to hit AC 1'
        if (rules::attackNumber(2, 4, 1) != 17) ++bad;
        // Balto the monk, staff vs. Aggro in plate and
        // shield (AC 2): the book's base 18 - the engine
        // has no monk class (4 classes), so the pin rides
        // the fighter L1 approximation, and the number
        // still agrees
        if (rules::attackMatrixFighter(1, 2) != 18) ++bad;
        // Gutboy's STR 17: '+l to hit due to strength'
        // and '1 point of bonus damage from strength'
        {
            rules::ExceptionalStrength noEx;
            if (rules::strHitAdj(17, noEx) != 1) ++bad;
            if (rules::strDmgAdj(17, noEx) != 1) ++bad;
        }
        // Gutboy's save vs. Arkayn's command: the book -
        // 'he therefore needs a 10 or better to save
        // (instead of a 14)' - a 6th-level fighter's
        // spell save is the printed 14
        if (rules::saveTarget(0, 6, rules::SAVE_SPELLS)
            != 14) ++bad;
        // Arkayn's mace vs. Gutboy's splint mail (the
        // book's AC type 3): '+1 armor class adjustment,
        // so he really only needs a 16 or better' - the
        // engine's bludgeoning-vs-plate row is the same
        // +1, so 17 - 1 = 16
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_PLATE) != 1) ++bad;
        if (rules::attackNumber(2, 4, 1) -
            rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_PLATE) != 16) ++bad;
        // THE DIVERGENCES - pinned as the engine's values,
        // with the book's numbers in the comments:
        // Aggro's axe: the book gives the specific-weapon
        // row '+1 to hit vs. no armor' (base 8 - 1 magic -
        // 1 axe = 6); the engine's 3-class approximation
        // is slashing-neutral vs. no armor (8 - 1 magic =
        // 7). Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_SLASHING,
                rules::AC_TYPE_NONE) != 0) ++bad;
        // Arlanni's sling bullet: the book's row is +3 vs.
        // no armor (11 - 3 = 8 needed); the engine's
        // piercing class is neutral vs. no armor (11
        // needed). Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_PIERCING,
                rules::AC_TYPE_NONE) != 0) ++bad;
        // Gutboy's hammer vs. scale mail: the book's row
        // is +1 (11 - 1 STR - 1 hammer = 9); the engine's
        // bludgeoning class is neutral vs. leather/scale.
        // Named approximation, gap report.
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_LEATHER) != 0) ++bad;
        // Balto's staff: the book's '-7 armor class
        // adjustment' (18 + 7 = 20 needed) is one of the
        // example's editorial errors - the same sentence
        // even names 'sword vs. plate mail and shield'
        // for a staff attack, and Gygax confirmed the
        // example 'slipped past and never got corrected'.
        // The engine's staff (bludgeoning) vs. Aggro's
        // plate (AC 2 = the chain column) is neutral. The
        // engine does NOT copy the book's error.
        if (rules::attackNumber(0, 1, 2) != 18) ++bad;
        if (rules::weaponVsAcAdjustment(
                rules::WCLASS_BLUDGEONING,
                rules::AC_TYPE_CHAIN) != 0) ++bad;
        // Gutboy the dwarf's CON 16 save bonus: the book
        // applies '+4' to the spell save (14 - 4 = 10);
        // the engine models the CON adjustment only vs.
        // poison, not the dwarf's magic saves. Named gap,
        // gap report.
        // (no engine hook to pin - the gap is the pin)
        printf("R144 golden melee audit: bad %d\n", bad);
        if (bad) return 1;
    }
