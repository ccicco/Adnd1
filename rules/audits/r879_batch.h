    // ---- R879 registry schema audit ----
    // THE REGISTRY SCHEMA - the maintenance-arc opener: the FINAL post-DDG
    // schema (57 keys: the 40-key mm2lua base, the eight promotion-seam
    // adjustment keys, the nine DDG keys) lands with the uniform
    // MonsterRegistry coercers (one pass, no per-book special-casing) and the
    // idempotent byte-stable normalize_registry.py tool. The
    // pre-normalization key census is pinned: the sparse state of all 995
    // defs (MM1 408, MM2 332, FF 185, OA 47, WSG 15, MOP 8) at HEAD 7f44709.
    // The sentinel doctrine: n/a for strings, -1 for ints, distinct from
    // every real print value (Nil and None are real and stay). The book
    // rounds then rewrite every def full-field, and the DDG lua promotion
    // generates the deity defs only from the adjudicated pin headers (Curtiss
    // 2026-10-27: the arc first, the promotion after).
    {
        using namespace rules;
        int bad = 0;
    if (rscRound() != 879
            || rscCensusBefore() != 801
            || rscCensusAfter() != 802
            || rscSchemaKeys() != 57
            || rscFieldOrderBase() != 40
            || rscAdjustmentKeys() != 8
            || rscDdgKeys() != 9
            || rscIntKeys() != 13
            || rscRegistryFloor() != 995
            || rscBookCount() != 6
            || !rscArcOpener()
            || !rscFullFieldEmission()
            || !rscSparseAtHead()
            || !rscSentinelsDistinct()
            || !rscLoaderUniform()
            || !rscNormalizerByteStable()
            || !rscPromotionFromHeaders()
            || !rscPinHeadersUntouched()
            || !rscDdgDefsPending()
        )
            ++bad;
        // the the book census grid grid
        int CrscBooks[6][2] = {
            {0,408},
            {1,332},
            {2,185},
            {3,47},
            {4,15},
            {5,8},
            };
        for (int b = 0;
             b < rscBookCount();
             ++b) {
            int vals[2];
            vals[0] = rscBookOrd(b);
            vals[1] = rscBookDefs(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CrscBooks[b][c])
                    ++bad;
            }
        }
        // the the key census grid grid
        int CrscKeys[57][7] = {
            {0,408,332,185,47,15,8},
            {1,10,0,0,0,0,0},
            {2,408,332,185,47,15,8},
            {3,408,332,185,47,15,8},
            {4,408,332,185,47,15,8},
            {5,185,0,0,0,0,0},
            {6,408,332,185,47,15,8},
            {7,50,0,0,0,0,0},
            {8,10,0,0,0,0,0},
            {9,408,331,185,47,15,8},
            {10,306,332,185,45,15,8},
            {11,306,331,185,45,15,8},
            {12,306,331,185,44,15,8},
            {13,408,332,185,47,15,8},
            {14,400,331,185,47,15,8},
            {15,408,0,0,0,0,0},
            {16,408,332,185,47,15,8},
            {17,365,328,185,47,15,8},
            {18,346,328,185,47,15,8},
            {19,288,328,185,47,15,8},
            {20,408,332,185,47,15,8},
            {21,1,0,0,0,0,0},
            {22,408,331,185,47,15,8},
            {23,408,331,185,47,15,8},
            {24,408,331,185,47,15,8},
            {25,408,0,0,0,0,0},
            {26,408,331,185,47,15,8},
            {27,408,331,185,47,15,8},
            {28,408,331,185,47,15,8},
            {29,408,331,185,47,15,8},
            {30,408,331,185,47,15,8},
            {31,408,331,185,47,15,8},
            {32,408,331,185,47,15,8},
            {33,408,331,185,47,15,8},
            {34,408,331,185,47,15,8},
            {35,408,331,185,47,15,8},
            {36,270,332,185,47,15,8},
            {37,181,0,0,0,0,0},
            {38,0,0,0,0,0,0},
            {39,34,0,0,0,0,0},
            {40,5,0,0,0,0,0},
            {41,1,0,0,0,0,0},
            {42,3,0,0,0,15,0},
            {43,3,0,0,0,15,0},
            {44,0,0,0,0,0,0},
            {45,0,5,0,0,0,8},
            {46,0,0,0,0,0,0},
            {47,3,0,0,0,15,0},
            {48,0,0,0,0,0,0},
            {49,0,0,0,0,0,0},
            {50,0,0,0,0,0,0},
            {51,0,0,0,0,0,0},
            {52,0,0,0,0,0,0},
            {53,0,0,0,0,0,0},
            {54,0,0,0,0,0,0},
            {55,0,0,0,0,0,0},
            {56,0,0,0,0,0,0},
            };
        for (int b = 0;
             b < rscSchemaKeys();
             ++b) {
            int vals[7];
            vals[0] = rscKOrd(b);
            vals[1] = rscKMm1(b);
            vals[2] = rscKMm2(b);
            vals[3] = rscKFf(b);
            vals[4] = rscKOa(b);
            vals[5] = rscKWsg(b);
            vals[6] = rscKMop(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CrscKeys[b][c])
                    ++bad;
            }
        }
        // the round walk (the arc opener, the census step)
    if (rscRound() != 879
            || rscCensusBefore() != 801
            || rscCensusAfter() != 802
        )
            ++bad;
        // the schema arithmetic (base + adjustments + the DDG keys)
    if (rscSchemaKeys() != 57
            || rscFieldOrderBase() + rscAdjustmentKeys() + rscDdgKeys() != 57
            || rscIntKeys() != 13
        )
            ++bad;
        // the registry floor (the books walk, every def counted)
    if (rscBookDefs(0) + rscBookDefs(1) + rscBookDefs(2) + rscBookDefs(3) +
        rscBookDefs(4) + rscBookDefs(5) != 995
            || rscBookOrd(5) != 5
        )
            ++bad;
        // the book census (MM1, MM2, FF, OA, WSG, MOP)
    if (rscBookDefs(0) != 408
            || rscBookDefs(1) != 332
            || rscBookDefs(2) != 185
            || rscBookDefs(3) != 47
            || rscBookDefs(4) != 15
            || rscBookDefs(5) != 8
        )
            ++bad;
        // the key-census anchors (name on every def; the DDG keys on none;
        // wsgRoles on the WSG defs and the MM1 mounts)
    if (rscKMm1(0) != 408
            || rscKMop(56) != 0
            || rscKWsg(47) != 15
            || rscKMm1(47) != 3
            || rscKOrd(56) != 56
        )
            ++bad;
        // the schema doctrine (the sentinel, loader and promotion bools)
    if (rscFullFieldEmission() != 1
            || rscSentinelsDistinct() != 1
            || rscLoaderUniform() != 1
            || rscPromotionFromHeaders() != 1
        )
            ++bad;
        // the arc mechanics (the opener, the normalizer, the pin headers, the
        // pending DDG defs)
    if (rscArcOpener() != 1
            || rscNormalizerByteStable() != 1
            || rscPinHeadersUntouched() != 1
            || rscDdgDefsPending() != 1
            || rscSparseAtHead() != 1
        )
            ++bad;
        printf("R879 registry schema audit: bad %d\n", bad);
        if (bad) return 1;
    }
