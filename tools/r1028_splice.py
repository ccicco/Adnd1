#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1028_splice.py
# R1028: the misc magic ENGINE de-wire - splice the registry-native misc
# tables into dm/treasure.cpp (the five hardcoded kMisc ItemRow arrays
# retire; rolls and pins read registry views), and seat the
# rules/audits/r1028_misc_engine_registry.h fragment in regtest.cpp.
#
# Anchored edits only; every edit has a before-gate (the anchor must be
# found exactly once) and the file gets an after-gate (counts of retired
# vs new markers). Idempotent-by-refusal: if any anchor is missing the
# script aborts with SPLICE ABORT and touches nothing.
# ============================================================================

import re
import sys

TREASURE = "dm/treasure.cpp"
REGTEST = "regtest.cpp"


def fail(msg):
    print("SPLICE ABORT: %s" % msg)
    sys.exit(1)


def gate(text, needle, what, count=1):
    n = text.count(needle)
    if n != count:
        fail("%s: expected %d x %r, found %d" % (what, count, needle, n))


# ---------------------------------------------------------------------------
# 1. dm/treasure.cpp
# ---------------------------------------------------------------------------
src = open(TREASURE).read()

# before-gates
gate(src, 'static const ItemRow kMisc1[] = {', TREASURE)
gate(src, 'static const ItemRow kMisc5[] = {', TREASURE)
gate(src, "#include \"../rules/ua/uadetrows.h\"", TREASURE)
gate(src, "case 4:  return adjustSpecial(dice,", TREASURE)
gate(src, "case 4:  *n = COUNT_OF(kMisc1);     return kMisc1;", TREASURE)
gate(src, "    if (category == 1)\n        return COUNT_OF(kSpellScrolls) + 9;",
     TREASURE)
gate(src, "    if (!out || category == 1) return false;", TREASURE)
gate(src, "// ---- III.E.1 Miscellaneous Magic", TREASURE)
gate(src, "// ---- III.E. Special: Artifacts", TREASURE)

# (1a) includes: the registry header + <algorithm> for the view sort
src = src.replace(
    '#include "../rules/ua/uadetrows.h"\n',
    '#include "../rules/ua/uadetrows.h"\n'
    '#include "items/MiscItemRegistry.h"\n'
    '\n'
    '#include <algorithm>\n',
    1)

# (1b) replace the five kMisc arrays (and their banner comments) with the
# registry machinery block: from the III.E.1 banner through the kMisc5
# closing brace, i.e. everything up to (not including) the Artifacts
# banner.
start = src.index("// ---- III.E.1 Miscellaneous Magic")
end = src.index("// ---- III.E. Special: Artifacts")
block = src[start:end]
gate(block, "static const ItemRow kMisc", "retired block", 5)
gate(block, '"Artifact or Relic", 0,0, 0,0, 0,0 }', "retired artifact row")

machinery = '''// ---- III.E.1-5 Miscellaneous Magic (R1028: registry-native) ---------------------
// The five hardcoded kMisc ItemRow arrays are retired: the tables are the
// 166 def rows at content/magic_items/<letter>/<stem>.lua, loaded through
// items::MiscItemRegistry. The one hardcoded survivor is the Artifact or
// Relic dispatch row (band 17-17 of table 1): it is the trigger for the
// Special artifact table, so the A1 ruling keeps it out of the defs and it
// is injected into the view below; adjustSpecial dispatches on its exact
// printed name.
static items::MiscItemRegistry& miscReg() {
    // One-time lazy load (adnd1.cpp is a Win32 shell TU that preflight
    // skips, so the engine loads its own registries; R71fix letter-dir
    // loop: a missing letter dir is normal, loadDirectory returns -1).
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (char c = 'a'; c <= 'z'; ++c) {
            std::string dir = "content/magic_items/";
            dir.push_back(c);
            reg.loadDirectory(dir);
        }
    }
    return reg;
}

// Per-table views of the registry rows, band-sorted (registry key order
// is alphabetical, NOT band order). Counts: 33/30/33/36/35 (the 166
// def rows + the injected artifact row), matching mNRowCount() and the
// retired arrays, so the R122 pin audits read the same table.
static const std::vector<items::MiscItemRow>& miscView(int n) {
    static std::vector<items::MiscItemRow> v[6];
    static bool built = false;
    if (!built) {
        built = true;
        for (const auto& kv : miscReg().all())
            for (const auto& r : kv.second.rows)
                if (r.set.size() == 6 && r.set.compare(0, 5, "kMisc") == 0
                    && r.set[5] >= '1' && r.set[5] <= '5')
                    v[r.set[5] - '0'].push_back(r);
        items::MiscItemRow art;   // the A1-ruling dispatch row
        art.name = "Artifact or Relic";
        art.set = "kMisc1";
        art.bandLo = art.bandHi = 17;
        v[1].push_back(art);
        for (int i = 1; i <= 5; ++i)
            std::sort(v[i].begin(), v[i].end(),
                      [](const items::MiscItemRow& a,
                         const items::MiscItemRow& b) {
                          return a.bandLo < b.bandLo;
                      });
    }
    return v[n];
}

static MagicItem makeMiscItem(rules::Dice& dice,
                              const items::MiscItemRow& r) {
    MagicItem m;
    m.name = r.name;
    m.xp = valIn(dice, r.xp, r.xpHi);
    m.gp = valIn(dice, r.gp, r.gpHi);
    if (r.qtyHi > 0) m.qty = inRange(dice, r.qtyLo, r.qtyHi);
    return m;
}

// The pickRow semantics on registry rows: linear band scan on 1+d100,
// fallback the last row.
static MagicItem pickMiscRow(rules::Dice& dice,
                             const std::vector<items::MiscItemRow>& rows) {
    int r = 1 + d100(dice);
    for (const auto& row : rows)
        if (r >= row.bandLo && r <= row.bandHi)
            return makeMiscItem(dice, row);
    return makeMiscItem(dice, rows.back());
}

'''
src = src[:start] + machinery + src[end:]

# (1c) rollFromCategoryUnset cases 4-8 -> registry views
old_cases = '''        case 4:  return adjustSpecial(dice,
                     pickRow(dice, kMisc1, COUNT_OF(kMisc1)));
        case 5:  return adjustSpecial(dice,
                     pickRow(dice, kMisc2, COUNT_OF(kMisc2)));
        case 6:  return adjustSpecial(dice,
                     pickRow(dice, kMisc3, COUNT_OF(kMisc3)));
        case 7:  return adjustSpecial(dice,
                     pickRow(dice, kMisc4, COUNT_OF(kMisc4)));
        case 8:  return adjustSpecial(dice,
                     pickRow(dice, kMisc5, COUNT_OF(kMisc5)));
'''
new_cases = '''        case 4:  return adjustSpecial(dice, pickMiscRow(dice, miscView(1)));
        case 5:  return adjustSpecial(dice, pickMiscRow(dice, miscView(2)));
        case 6:  return adjustSpecial(dice, pickMiscRow(dice, miscView(3)));
        case 7:  return adjustSpecial(dice, pickMiscRow(dice, miscView(4)));
        case 8:  return adjustSpecial(dice, pickMiscRow(dice, miscView(5)));
'''
gate(src, old_cases, "roll cases")
src = src.replace(old_cases, new_cases, 1)

# (1d) pinTableFor: the misc cases retire (the pin API reads the views)
old_pin = '''        case 4:  *n = COUNT_OF(kMisc1);     return kMisc1;
        case 5:  *n = COUNT_OF(kMisc2);     return kMisc2;
        case 6:  *n = COUNT_OF(kMisc3);     return kMisc3;
        case 7:  *n = COUNT_OF(kMisc4);     return kMisc4;
        case 8:  *n = COUNT_OF(kMisc5);     return kMisc5;
'''
new_pin = '''        // 4-8 (the misc tables) are registry-native: magicTablePinCount
        // and magicTablePin read the miscView() rows directly
'''
gate(src, old_pin, "pin cases")
src = src.replace(old_pin, new_pin, 1)

# (1e) magicTablePinCount: misc categories read the views
old_cnt = '''    if (category == 1)
        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse
    int n = 0;'''
new_cnt = '''    if (category == 1)
        return COUNT_OF(kSpellScrolls) + 9;  // + protection & curse
    if (category >= 4 && category <= 8)     // registry-native misc tables
        return (int)miscView(category - 3).size();
    int n = 0;'''
gate(src, old_cnt, "pin count")
src = src.replace(old_cnt, new_cnt, 1)

# (1f) magicTablePin: misc categories read the views
old_get = '''    if (!out || category == 1) return false;
    int n = 0;'''
new_get = '''    if (!out || category == 1) return false;
    if (category >= 4 && category <= 8) {    // registry-native misc tables
        const auto& rows = miscView(category - 3);
        if (row < 0 || row >= (int)rows.size()) return false;
        const auto& r = rows[row];           // views are static: name lives
        out->lo = r.bandLo;  out->hi = r.bandHi;
        out->name = r.name.c_str();
        out->xp = r.xp;      out->xpHi = r.xpHi;
        out->gp = r.gp;      out->gpHi = r.gpHi;
        out->qtyLo = r.qtyLo; out->qtyHi = r.qtyHi;
        return true;
    }
    int n = 0;'''
gate(src, old_get, "pin get")
src = src.replace(old_get, new_get, 1)

# after-gates: every retired marker gone, every new marker present
for g in ("static const ItemRow kMisc", "pickRow(dice, kMisc",
          "COUNT_OF(kMisc"):
    if g in src:
        fail("treasure.cpp after-gate: retired marker still present: %r" % g)
for g in ("miscReg()", "miscView(", "pickMiscRow(", "makeMiscItem("):
    if g not in src:
        fail("treasure.cpp after-gate: new marker missing: %r" % g)

open(TREASURE, "w").write(src)
print("treasure.cpp: spliced (kMisc arrays retired, registry views wired)")

# ---------------------------------------------------------------------------
# 2. regtest.cpp: seat the fragment after the r1027 fragment
# ---------------------------------------------------------------------------
rt = open(REGTEST).read()
anchor = '#include "rules/audits/r1027_misc_magic_registry.h"  // R1027: migrated\n'
gate(rt, anchor, REGTEST)
gate(rt, '#include "rules/audits/r1028_misc_engine_registry.h"', REGTEST, 0)
rt = rt.replace(
    anchor,
    anchor + '    #include "rules/audits/r1028_misc_engine_registry.h"  // R1028\n',
    1)
open(REGTEST, "w").write(rt)
print("regtest.cpp: fragment seated after the R1027 fragment")

# ---------------------------------------------------------------------------
# 3. census: printf audit patterns must total 941 (934 + 7 new labels)
# ---------------------------------------------------------------------------
# ---------------------------------------------------------------------------
# 3. census: mirror the R112c preflight gate exactly - the audit printf
# patterns in regtest.cpp + rules/audits/*.h must total 941 (934 + 7).
# ---------------------------------------------------------------------------
import glob
pats = set()
for path in [REGTEST] + sorted(glob.glob("rules/audits/*.h")):
    for line in open(path):
        if 'printf("' not in line:
            continue
        for m in re.findall(r'[^"]*audit: bad %d', line):
            pats.add(m[:-2])
if len(pats) != 941:
    fail("census gate: expected 941 unique audit printf patterns, "
          "counted %d" % len(pats))
new = [p for p in pats if p.startswith("R1028 misc engine registry")]
if len(new) != 7:
    fail("census gate: expected 7 R1028 labels among patterns, found %d"
         % len(new))
print("census: 941 unique audit printf patterns (934 + 7 R1028 labels)")

print("SPLICE OK")
