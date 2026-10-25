    // ---- R233a: the multi-class seam audit ----
    // The combo bit helpers (the pure-expression
    // seam), the R185 quotient/stalled machinery,
    // and the combo table joins the engine reads
    // (an evaluable block - verified by audit_eval).
    {
        int bad = 0;
        // the bit helpers: count, ordered bits, the
        // base-class and subclass maps
        if (rules::multiClassCount(0) != 0) ++bad;
        if (rules::multiClassCount(3) != 2) ++bad;
        if (rules::multiClassCount(11) != 3) ++bad;
        if (rules::multiClassCount(127) != 7) ++bad;
        if (rules::multiClassCount(6) != 2) ++bad;
        if (rules::multiClassCount(48) != 2) ++bad;
        if (rules::multiClassBitAt(11, 0) != 1) ++bad;
        if (rules::multiClassBitAt(11, 1) != 2) ++bad;
        if (rules::multiClassBitAt(11, 2) != 8) ++bad;
        if (rules::multiClassBitAt(5, 1) != 4) ++bad;
        if (rules::multiClassBitAt(36, 1) != 32) ++bad;
        if (rules::multiClassBitAt(6, 0) != 2) ++bad;
        if (rules::multiClassBitAt(6, 1) != 4) ++bad;
        if (rules::multiClassBitAt(48, 0) != 16) ++bad;
        if (rules::multiClassBitAt(48, 1) != 32) ++bad;
        if (rules::multiClassBitAt(36, 0) != 4) ++bad;
        if (rules::multiClassBitAt(24, 0) != 8) ++bad;
        if (rules::multiClassBitAt(24, 1) != 16) ++bad;
        if (rules::multiClassBitAt(68, 0) != 4) ++bad;
        if (rules::multiClassBitAt(68, 1) != 64) ++bad;
        if (rules::multiClassBaseOfBit(1) != 0) ++bad;
        if (rules::multiClassBaseOfBit(16) != 1) ++bad;
        if (rules::multiClassBaseOfBit(32) != 0) ++bad;
        if (rules::multiClassBaseOfBit(64) != 3) ++bad;
        if (rules::multiClassSubOfBit(1) != -1) ++bad;
        if (rules::multiClassSubOfBit(16) != 3) ++bad;
        if (rules::multiClassSubOfBit(32) != 1) ++bad;
        if (rules::multiClassSubOfBit(64) != 4) ++bad;
        // the quotient and stalled rules (R185)
        if (rules::multiclassHpQuotient(5, 2) != 3) ++bad;
        if (rules::multiclassHpQuotient(3, 2) != 2) ++bad;
        if (rules::multiclassHpQuotient(1, 2) != 1) ++bad;
        if (!rules::multiclassHitDieStalled(9, 9)) ++bad;
        if (rules::multiclassHitDieStalled(8, 9)) ++bad;
        // the combo table joins (the R185 rows the
        // engine reads)
        if (rules::multiClassComboCount(4) != 8) ++bad;
        if (rules::multiClassCombo(4, 0) != 5) ++bad;
        if (rules::multiClassCombo(6, 2) != 68) ++bad;
        printf("R233a multi-class seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
