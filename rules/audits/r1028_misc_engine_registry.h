// ============================================================================
// Adnd1 - rules/audits/r1028_misc_engine_registry.h
// R1028: the misc magic ENGINE de-wire - the five hardcoded kMisc
// ItemRow arrays in dm/treasure.cpp are retired; the engine now rolls
// (pickMiscRow) and pins (magicTablePin) from registry-native rows:
// the 166 def rows at content/magic_items/<letter>/<stem>.lua loaded
// through items::MiscItemRegistry, plus the one A1-ruling survivor,
// the hardcoded "Artifact or Relic" dispatch row (band 17-17 of
// table 1, the trigger for the Special artifact table).
//
// This fragment cross-checks the engine's public pin API against
// the footnote accessors (rules::mNRowLo/mNRowHi, an independent
// record), against the registry rows themselves, and a roll smoke.
// Expected counts: 33/30/33/36/35 (166 def rows + 1 artifact row),
// bands contiguous 1..100 per table - the R122 pin audits read the
// same table through the same API, so they stay green unchanged.
// ============================================================================

{
    // -- load: 166 defs, no registry errors ------------------------------
    int bad = 0;
    items::MiscItemRegistry mreg;
    int loaded = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string dir = "content/magic_items/";
        dir.push_back(c);
        int m = mreg.loadDirectory(dir);
        if (m > 0) loaded += m;
    }
    if (loaded != 166) ++bad;
    if (!mreg.errors().empty()) ++bad;
    printf("R1028 misc engine registry load audit: bad %d\n", bad);
    if (bad) return 1;

    // -- counts: pin counts 33/30/33/36/35 == mNRowCount() ---------------
    bad = 0;
    const int kExpect[6] = { 0, 33, 30, 33, 36, 35 };
    if (dm::treasure::magicTablePinCount(4) != kExpect[1]) ++bad;
    if (dm::treasure::magicTablePinCount(5) != kExpect[2]) ++bad;
    if (dm::treasure::magicTablePinCount(6) != kExpect[3]) ++bad;
    if (dm::treasure::magicTablePinCount(7) != kExpect[4]) ++bad;
    if (dm::treasure::magicTablePinCount(8) != kExpect[5]) ++bad;
    if (dm::treasure::magicTablePinCount(4) != rules::m1RowCount()) ++bad;
    if (dm::treasure::magicTablePinCount(5) != rules::m2RowCount()) ++bad;
    if (dm::treasure::magicTablePinCount(6) != rules::m3RowCount()) ++bad;
    if (dm::treasure::magicTablePinCount(7) != rules::m4RowCount()) ++bad;
    if (dm::treasure::magicTablePinCount(8) != rules::m5RowCount()) ++bad;
    printf("R1028 misc engine registry counts audit: bad %d\n", bad);
    if (bad) return 1;

    // -- bands: contiguous, ordered, 1..100 per table ---------------------
    bad = 0;
    for (int cat = 4; cat <= 8; ++cat) {
        int n = dm::treasure::magicTablePinCount(cat);
        int expect = 1;
        for (int i = 0; i < n; ++i) {
            dm::treasure::TablePin p;
            if (!dm::treasure::magicTablePin(cat, i, &p)) { ++bad; break; }
            if (p.lo != expect) ++bad;
            expect = p.hi + 1;
        }
        if (expect != 101) ++bad;
    }
    printf("R1028 misc engine registry bands audit: bad %d\n", bad);
    if (bad) return 1;

    // -- parity vs the footnote accessors (independent record) -----------
    bad = 0;
    for (int i = 0; i < rules::m1RowCount(); ++i) {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(4, i, &p)) { ++bad; continue; }
        if (p.lo != rules::m1RowLo(i) || p.hi != rules::m1RowHi(i)) ++bad;
    }
    for (int i = 0; i < rules::m2RowCount(); ++i) {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(5, i, &p)) { ++bad; continue; }
        if (p.lo != rules::m2RowLo(i) || p.hi != rules::m2RowHi(i)) ++bad;
    }
    for (int i = 0; i < rules::m3RowCount(); ++i) {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(6, i, &p)) { ++bad; continue; }
        if (p.lo != rules::m3RowLo(i) || p.hi != rules::m3RowHi(i)) ++bad;
    }
    for (int i = 0; i < rules::m4RowCount(); ++i) {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(7, i, &p)) { ++bad; continue; }
        if (p.lo != rules::m4RowLo(i) || p.hi != rules::m4RowHi(i)) ++bad;
    }
    for (int i = 0; i < rules::m5RowCount(); ++i) {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(8, i, &p)) { ++bad; continue; }
        if (p.lo != rules::m5RowLo(i) || p.hi != rules::m5RowHi(i)) ++bad;
    }
    printf("R1028 misc engine registry parity audit: bad %d\n", bad);
    if (bad) return 1;

    // -- artifact: the one injected row, at table 1 index 7 --------------
    bad = 0;
    {
        dm::treasure::TablePin p;
        if (!dm::treasure::magicTablePin(4, 7, &p)) ++bad;
        else if (std::string(p.name) != "Artifact or Relic"
                 || p.lo != 17 || p.hi != 17) ++bad;
    }
    if (!rules::m1IsArtifactRelicRow(7)) ++bad;
    for (int i = 0; i < rules::m1RowCount(); ++i)
        if (i != 7 && rules::m1IsArtifactRelicRow(i)) ++bad;
    printf("R1028 misc engine registry artifact audit: bad %d\n", bad);
    if (bad) return 1;

    // -- rows: every def row appears in its pin table, values equal ------
    bad = 0;
    for (const auto& kv : mreg.all())
        for (const auto& r : kv.second.rows) {
            const int cat = r.set == "kMisc1" ? 4 : r.set == "kMisc2" ? 5
                          : r.set == "kMisc3" ? 6 : r.set == "kMisc4" ? 7
                          : r.set == "kMisc5" ? 8 : -1;
            if (cat < 0) { ++bad; continue; }
            const int n = dm::treasure::magicTablePinCount(cat);
            bool found = false;
            for (int i = 0; i < n && !found; ++i) {
                dm::treasure::TablePin q;
                if (!dm::treasure::magicTablePin(cat, i, &q)) { ++bad; break; }
                if (std::string(q.name) == r.name) {
                    found = true;
                    if (q.lo != r.bandLo || q.hi != r.bandHi
                        || q.xp != r.xp || q.xpHi != r.xpHi
                        || q.gp != r.gp || q.gpHi != r.gpHi
                        || q.qtyLo != r.qtyLo || q.qtyHi != r.qtyHi) ++bad;
                }
            }
            if (!found) ++bad;
        }
    printf("R1028 misc engine registry rows audit: bad %d\n", bad);
    if (bad) return 1;

    // -- roll smoke: every misc-category roll lands on a pinned row name --
    bad = 0;
    {
        rules::Rng rng(2028);
        rules::Dice dice(rng);
        int hits = 0;
        int seenCat[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        for (int i = 0; i < 40000; ++i) {
            dm::treasure::MagicItem m =
                dm::treasure::rollMagicItem(dice);
            const int cat = m.category;
            if (cat < 4 || cat > 8) continue;
            ++hits;
            ++seenCat[cat];
            const int n = dm::treasure::magicTablePinCount(cat);
            bool found = false;
            for (int j = 0; j < n && !found; ++j) {
                dm::treasure::TablePin q;
                if (!dm::treasure::magicTablePin(cat, j, &q)) { ++bad; break; }
                if (std::string(q.name) == m.name) found = true;
            }
            if (!found) {
                // adjustSpecial renames three rows after the roll: the
                // two value-scaled rows (Bracers of Defense (AC N),
                // Cloak of Protection +N) and the artifact dispatch
                // (band 17-17 of table 1 rolls an artifact name; the
                // artifact table pins are category 12)
                if (m.name.compare(0, 23, "Bracers of Defense (AC ") == 0
                    || m.name.compare(0, 21, "Cloak of Protection +") == 0)
                    found = true;
                else {
                    const int na = dm::treasure::magicTablePinCount(12);
                    for (int j = 0; j < na && !found; ++j) {
                        dm::treasure::TablePin q;
                        if (!dm::treasure::magicTablePin(12, j, &q)) break;
                        if (std::string(q.name) == m.name) found = true;
                    }
                }
            }
            if (!found) ++bad;
        }
        if (hits < 100) ++bad;
        for (int c = 4; c <= 8; ++c)
            if (seenCat[c] == 0) ++bad;
    }
    printf("R1028 misc engine registry roll audit: bad %d\n", bad);
    if (bad) return 1;
}
