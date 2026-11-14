#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1035_splice.py  (R1035)
# The city/town encounter table de-wire, the R1032/R1033/R1034 shape:
# the retired R64 city family of dm/encounters.cpp - the CITY/TOWN
# ENCOUNTER MATRIX (kCityMatrix, 46 rows, day/night percentile bands,
# DMG Appendix C Premium reprint p.190-192), the printed encounter
# numbers (cityCountFor's dice expressions, incl. the dead bard entry
# preserved per the quirk doctrine), the p.192 protection device
# subtable (rollProtectionDevice's 11 bands), the p.192 CHANCE PER
# LEVEL FOR MAGIC ITEM table (the 4x3 percent-per-level array of
# rollCityMagicItems) and the R146/R174 city flavor bands
# (kDrunkKinds 20, kHarlotKinds 12, kNobleKinds 2, kSedanKinds 2,
# kRuffianKinds 6) - are extracted into content/tables/
# encounters_city/*.lua (a sibling of encounters/, encounters_water/
# and encounters_outdoor/, so the R1032/R1033/R1034 file pins stay
# untouched) and load through dm::EncounterTableRegistry, extended
# here with the city family (matrix rows, band tables, count dice
# and magic chances). The mechanics stay in the engine: the classed
# character-party builds (rollCityParty, verbatim), the
# second-percentile splits, the nycadaemon/mezzadaemon re-roll
# advice, plusForLevel, and the PROT_* device enum mapping.
# rollCityEncounter(), cityEncounterKeys(), cityCountFor(),
# rollProtectionDevice(), rollCityMagicItems(), cityDrunkKind(),
# cityHarlotKind(), cityNobleKind(), cityNoblewomanSedan() and
# cityRuffianKind() keep their signatures and behavior - they read
# registry-backed views. DISPATCH LESSON (R1034): the city family
# uses exact-key branches (city_matrix / city_counts / city_magic)
# plus the exception-free city_band_ prefix - the predicates do not
# overlap, and the fragment carries negative has-pins for both
# sides. This script is the only writer of the lua files and the
# R1035 battery fragment; it is idempotent (run twice = "applied 0").
# ============================================================================

import hashlib
import os
import re
import sys

ROOT = os.getcwd()
ENC = os.path.join(ROOT, "dm", "encounters.cpp")
REG_H = os.path.join(ROOT, "dm", "EncounterTableRegistry.h")
REG_CPP = os.path.join(ROOT, "dm", "EncounterTableRegistry.cpp")
REGTEST = os.path.join(ROOT, "regtest.cpp")
LUA_DIR = os.path.join(ROOT, "content", "tables", "encounters_city")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1035_city_encounter_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory, asserted against the source at parse time
# ---------------------------------------------------------------------------

# kCityMatrix rows are PARSED from the region; these are the expected
# counts the parse must produce (the print-fidelity record).
MATRIX_ROWS = 46

# cityCountFor's dice, in printed order (key, (n, d, plus) | fixed,
# optional night (n, d, plus)). The bard entry is DEAD CODE in the
# retired engine (monk_or_bard resolves on the party path first) -
# preserved verbatim per the R1032 quirk doctrine, documented in
# the lua header. ghoul/ghast share one C++ branch -> two entries.
COUNTS = [
    ("bandit",      (1, 10, 2), None),
    ("beggar",      (1, 2, 0), None),
    ("doppelganger",(1, 4, 2), None),
    ("giant_rat",   (2, 4, 0), (1, 24, 1)),
    ("ghoul",       (1, 13, 4), None),
    ("ghast",       (1, 13, 4), None),
    ("drunk",       (1, 4, 0), None),
    ("gentleman",   (1, 5, 0), None),
    ("laborer",     (1, 11, 2), None),
    ("peddler",     "fixed1", None),
    ("mercenary",   (1, 11, 2), None),
    ("merchant",    (1, 3, 0), None),
    ("bard",        "fixed1", None),     # dead entry, preserved
    ("night_hag",   (1, 2, 0), None),
    ("noble",       "fixed1", None),
    ("pilgrim",     (1, 11, 2), None),
    ("press_gang",  (1, 16, 1), None),
    ("rakshasa",    (1, 3, 0), None),
    ("ruffian",     (1, 6, 6), None),
    ("shadow",      (1, 7, 2), None),
    ("spectre",     (1, 3, 0), None),
    ("tradesman",   (2, 4, 0), None),
    ("wererat",     (1, 4, 2), None),
    ("weretiger",   (1, 2, 0), None),
    ("werewolf",    (1, 4, 2), None),
    ("wight",       (1, 4, 2), None),
    ("will_o_wisp", (1, 2, 0), None),
    ("wraith",      (1, 4, 0), None),
]

# the 14 classed/service keys that resolve as character parties
PARTY_KEYS = ["assassin", "cleric", "druid", "fighter", "illusionist",
              "magic_user", "monk", "paladin", "ranger", "thief",
              "rake", "city_guard", "city_official", "city_watchman"]

# the p.192 protection device subtable (rollProtectionDevice bands)
PROTECTION = [
    (1, 25,   "prot_ring1"),
    (26, 30,  "prot_ring2"),
    (31, 31,  "prot_ring3"),
    (32, 32,  "prot_amulet"),
    (33, 55,  "prot_bracers6"),
    (56, 70,  "prot_bracers4"),
    (71, 75,  "prot_bracers2"),
    (76, 82,  "prot_displacement"),
    (83, 95,  "prot_cloak1"),
    (96, 99,  "prot_cloak2"),
    (100, 100,"prot_cloak3"),
]

# the p.192 CHANCE PER LEVEL FOR MAGIC ITEM table (percent per
# level, groups 0/1/2 = fighter-ish / cleric / magic-user)
MAGIC = [
    ("sword",       [10, 0, 0]),
    ("misc_weapon", [5, 10, 5]),
    ("armor",       [10, 10, 0]),
    ("protection",  [2, 2, 10]),
]

# the R146/R174 flavor band tables: (C++ array, registry key, rows)
FLAVOR = [
    ("kDrunkKinds",    "city_band_drunk",    20),
    ("kHarlotKinds",   "city_band_harlot",   12),
    ("kNobleKinds",    "city_band_noble",    2),
    ("kSedanKinds",    "city_band_sedan",    2),
    ("kRuffianKinds",  "city_band_ruffian",  6),
]

# every source substring the retired code must still carry (the
# parse-time tie between this inventory and the C++ record)
ASSERTS = [
    'static const CityRow kCityMatrix[] = {',
    'int cityCountFor(rules::Dice& dice, const std::string& key, bool night) {',
    'dice.roll(1, 10, 0)',
    'dice.roll(1, 2, 0)',
    'dice.roll(1, 4, 0)',
    'dice.roll(1, 24, 0)',
    'dice.roll(1, 13, 0)',
    'dice.roll(1, 5, 0)',
    'dice.roll(1, 11, 0)',
    'dice.roll(1, 3, 0)',
    'dice.roll(1, 16, 0)',
    'dice.roll(1, 6, 0)',
    'dice.roll(1, 7, 0)',
    'dice.roll(2, 4, 0)',
    'static int rollProtectionDevice(rules::Dice& dice) {',
    'if (p <= 25) return PROT_RING1;',
    'if (p == 31) return PROT_RING3;',
    'if (p <= 55) return PROT_BRACERS6;',
    'if (p <= 82) return PROT_DISPLACEMENT;',
    'return PROT_CLOAK3;',
    'const int sword   [3] = { 10,  0,  0 };',
    'const int miscWpn [3] = {  5, 10,  5 };',
    'const int armor   [3] = { 10, 10,  0 };',
    'const int protect [3] = {  2,  2, 10 };',
    'static CharacterParty rollCityParty(rules::Dice& dice,',
    'DungeonEncounter rollCityEncounter(',
    'std::vector<std::string> cityEncounterKeys(',
    'const char* cityDrunkKind(int pctile) {',
    'const char* cityHarlotKind(int pctile) {',
    'const char* cityNobleKind(int pctile) {',
    'const char* cityNoblewomanSedan(int pctile) {',
    'const char* cityRuffianKind(int pctile) {',
]


def die(msg):
    sys.stderr.write("r1035_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the retired region out of dm/encounters.cpp
# ---------------------------------------------------------------------------

REGION_START = "// R64: the CITY/TOWN ENCOUNTER MATRIX"
REGION_END = "// R65: the ASTRAL & ETHEREAL encounter tables"
SEP = "// ----------------------------------------------------------------------------"


def parse_city_region(src):
    if "kCityMatrix" not in src:
        die("kCityMatrix not found (already spliced?)")
    i0 = src.index(REGION_START)
    i0 = src.rindex(SEP, 0, i0)
    i1 = src.index(REGION_END)
    i1 = src.rindex(SEP, i0, i1)
    region = src[i0:i1]

    for a in ASSERTS:
        if a not in region:
            die("assertion failed, the retired region must carry %r" % a)

    # the matrix
    m = re.search(r"static const CityRow kCityMatrix\[\] = \{(.*?)\};",
                  region, re.S)
    if not m:
        die("kCityMatrix array not found")
    rows = re.findall(r'\{(\d+),(\d+),(\d+),(\d+),"([a-z_]+)"\}', m.group(1))
    if len(rows) != MATRIX_ROWS:
        die("parsed %d matrix rows (expected %d)" % (len(rows), MATRIX_ROWS))
    matrix = [(int(a), int(b), int(c), int(d), k) for a, b, c, d, k in rows]

    # the flavor band tables
    flavor = []
    for arr, key, want in FLAVOR:
        fm = re.search(re.escape(arr) + r"\[\] = \{(.*?)\};",
                       region, re.S)
        if not fm:
            die("%s array not found" % arr)
        bands = re.findall(r'\{\s*(\d+),\s*(\d+),\s*"([^"]*)"\s*\}',
                          fm.group(1))
        if len(bands) != want:
            die("parsed %d %s bands (expected %d)" % (len(bands), arr, want))
        flavor.append((key, [(int(a), int(b), k) for a, b, k in bands]))

    # the three verbatim comment blocks (provenance, kept in the seam)
    c64 = region[:region.index("namespace {")].rstrip() + "\n"
    r146 = region[region.index("// R146: the city flavor subtables"):]
    r146 = r146[:r146.index("namespace {")].rstrip() + "\n"
    r174 = region[region.index("// R174: the two remaining R64 city"):]
    r174 = r174[:r174.index("// p.191-192: the noble gender coin")].rstrip() + "\n"

    return i0, i1, matrix, flavor, c64, r146, r174


# ---------------------------------------------------------------------------
# 2. gate data: everything the sim and the fragment pin
# ---------------------------------------------------------------------------

def gate_data(matrix, flavor):
    problems = []

    # day/night chains: populated bands chain 1 -> 100 in row order
    for col, lo_i, hi_i in (("day", 0, 1), ("night", 2, 3)):
        prev = 0
        for r in matrix:
            lo, hi = r[lo_i], r[hi_i]
            if lo == 0 and hi == 0:
                continue
            if lo != prev + 1 or hi < lo or hi > 100:
                problems.append("matrix %s band %r at %s" % (col, r, r[4]))
            prev = hi
        if prev != 100:
            problems.append("matrix %s chain ends at %d" % (col, prev))

    # flavor band chains
    for key, bands in flavor:
        prev = 0
        for lo, hi, kind in bands:
            if lo != prev + 1 or hi < lo or hi > 100:
                problems.append("%s band %r" % (key, (lo, hi, kind)))
            prev = hi
        if prev != 100:
            problems.append("%s chain ends at %d" % (key, prev))

    # protection chain
    prev = 0
    for lo, hi, kind in PROTECTION:
        if lo != prev + 1 or hi < lo or hi > 100:
            problems.append("protection band %r" % ((lo, hi, kind),))
        prev = hi
    if prev != 100:
        problems.append("protection chain ends at %d" % prev)

    return problems


# the python twin of the rollCityEncounter key path (splits fixed at
# their thresholds; demon/devil rows re-roll, modeled as skip)
def resolve_city_key(matrix, pctile, pctile2, night):
    col = (2, 3) if night else (0, 1)
    for r in matrix:
        lo, hi = r[col[0]], r[col[1]]
        if lo > 0 and pctile >= lo and pctile <= hi:
            key = r[4]
            if key in ("demon_or_nycadaemon", "devil_or_mezzadaemon"):
                return "REROLL"
            if key == "laborer_or_peddler":
                return "laborer" if pctile2 <= 50 else "peddler"
            if key == "monk_or_bard":
                return "monk" if pctile2 <= 60 else "bard"
            if key == "ghoul_or_ghast":
                return "ghoul" if pctile2 <= 30 else "ghast"
            if key == "vampire_or_lich":
                return "vampire" if pctile2 <= 75 else "lich"
            if key == "brigand":
                return "bandit"
            return key
    return None


def count_bounds(key, night):
    for k, dice, nd in COUNTS:
        if k != key:
            continue
        if dice == "fixed1":
            return (1, 1)
        n, d, plus = dice
        if nd is not None and night:
            n, d, plus = nd
        return (plus + n, plus + n * d)
    return (1, 1)   # one specimen fallthrough


def expected_keys(matrix):
    out = []
    def push(k):
        if k not in out:
            out.append(k)
    for r in matrix:
        key = r[4]
        if key == "laborer_or_peddler":
            push("laborer"); push("peddler"); continue
        if key == "monk_or_bard":
            push("monk"); push("bard"); continue
        if key == "ghoul_or_ghast":
            push("ghoul"); push("ghast"); continue
        if key == "vampire_or_lich":
            push("vampire"); push("lich"); continue
        if key == "brigand":
            push("bandit"); continue
        if key in ("demon_or_nycadaemon", "devil_or_mezzadaemon"):
            continue
        push(key)
    return out


def simulate_roll_path(matrix):
    bad = 0
    keys = expected_keys(matrix)
    if len(keys) != 47:
        die("expected_keys computed %d (expected 47)" % len(keys))
    for night in (False, True):
        for pct in range(1, 101):
            for p2 in (1, 25, 50, 60, 75, 90, 100):
                key = resolve_city_key(matrix, pct, p2, night)
                if key is None:
                    die("no matrix row for pctile %d (%s)"
                        % (pct, "night" if night else "day"))
                if key == "REROLL":
                    continue
                if key not in keys:
                    die("resolved key %r not in companion" % key)
    # count bounds sane for every count-path key
    for k, dice, nd in COUNTS:
        if k == "bard":
            continue      # dead entry: never reaches the count path
        lo, hi = count_bounds(k, False)
        if lo < 1 or hi < lo or hi > 200:
            die("count bounds %r for %s" % ((lo, hi), k))
        lo2, hi2 = count_bounds(k, True)
        if lo2 < 1 or hi2 < lo2 or hi2 > 200:
            die("night count bounds %r for %s" % ((lo2, hi2), k))
    return len(keys)


# ---------------------------------------------------------------------------
# 3. lua emission + round-trip
# ---------------------------------------------------------------------------

LUA_HDR = """-- encounter table def: %(key)s
-- The R64 city family (R1035 de-wire): extracted verbatim from
-- the retired %(what)s of dm/encounters.cpp (DMG Appendix C
-- Premium reprint p.190-192, OCR-verified; the R146/R174 flavor
-- records 1eonline.info-verified). %(note)s
-- DO NOT hand-edit: tools/r1035_splice.py is the only writer.

"""


def matrix_lua_text(matrix):
    out = [LUA_HDR % dict(
        key="city_matrix", what="kCityMatrix",
        note="rows carry the day and night percentile bands; "
             "-1,-1 = night-only row (the book prints \"-\").")]
    out.append("return {\n")
    out.append('  key = "city_matrix",\n')
    out.append("  rows = {\n")
    for loD, hiD, loN, hiN, k in matrix:
        d = "{%d,%d}" % (loD, hiD) if loD or hiD else "{-1,-1}"
        n = "{%d,%d}" % (loN, hiN) if loN or hiN else "{-1,-1}"
        out.append('    { key = "%s", day = %s, night = %s },\n'
                   % (k, d, n))
    out.append("  },\n}\n")
    return "".join(out)


def counts_lua_text():
    out = [LUA_HDR % dict(
        key="city_counts", what="cityCountFor dice expressions",
        note="dice = {n, d, plus} rolls plus + nDd; nightDice "
             "replaces dice at night; fixed = a printed constant; "
             "an absent key rolls one specimen (the engine "
             "fallthrough). The bard entry is dead code in the "
             "retired engine (monk_or_bard resolves on the party "
             "path first) - preserved verbatim, documented.")]
    out.append("return {\n")
    out.append('  key = "city_counts",\n')
    out.append("  rows = {\n")
    for k, dice, nd in COUNTS:
        if dice == "fixed1":
            out.append('    { key = "%s", fixed = 1 },\n' % k)
            continue
        n, d, plus = dice
        line = '    { key = "%s", dice = {%d,%d,%d}' % (k, n, d, plus)
        if nd is not None:
            line += ", nightDice = {%d,%d,%d}" % nd
        out.append(line + " },\n")
    out.append("  },\n}\n")
    return "".join(out)


def magic_lua_text():
    out = [LUA_HDR % dict(
        key="city_magic", what="rollCityMagicItems chance arrays",
        note="one row per p.192 magic category; groups = the "
             "percent-per-level chance for group 0 (fighter-ish), "
             "1 (cleric/druid), 2 (magic-user).")]
    out.append("return {\n")
    out.append('  key = "city_magic",\n')
    out.append("  rows = {\n")
    for cat, groups in MAGIC:
        out.append('    { category = "%s", groups = {%d,%d,%d} },\n'
                   % (cat, groups[0], groups[1], groups[2]))
    out.append("  },\n}\n")
    return "".join(out)


def band_lua_text(key, what, bands, note=""):
    out = [LUA_HDR % dict(key=key, what=what,
                          note=note or "band = the percentile band, "
                          "kind = the printed result.")]
    out.append("return {\n")
    out.append('  key = "%s",\n' % key)
    out.append("  rows = {\n")
    for lo, hi, kind in bands:
        out.append('    { band = {%d,%d}, kind = "%s" },\n'
                   % (lo, hi, kind))
    out.append("  },\n}\n")
    return "".join(out)


LUA_FILES = {
    "city_matrix.lua": lambda d: matrix_lua_text(d["matrix"]),
    "city_counts.lua": lambda d: counts_lua_text(),
    "city_magic.lua": lambda d: magic_lua_text(),
    "city_band_drunk.lua": lambda d: band_lua_text(
        "city_band_drunk", "kDrunkKinds (R146)", d["flavor"][0][1],
        "the p.191 drunk identity table (fiction-only "
        "descriptors; the app's cityFlavor strings dress the "
        "drunk rows with them)."),
    "city_band_harlot.lua": lambda d: band_lua_text(
        "city_band_harlot", "kHarlotKinds (R146)", d["flavor"][1][1],
        "the p.192 harlot type table (fiction-only descriptors)."),
    "city_band_noble.lua": lambda d: band_lua_text(
        "city_band_noble", "kNobleKinds (R174)", d["flavor"][2][1],
        "the p.191-192 noble gender coin (fiction-only)."),
    "city_band_sedan.lua": lambda d: band_lua_text(
        "city_band_sedan", "kSedanKinds (R174)", d["flavor"][3][1],
        "the p.192 noblewoman ride (fiction-only)."),
    "city_band_ruffian.lua": lambda d: band_lua_text(
        "city_band_ruffian", "kRuffianKinds (R174)", d["flavor"][4][1],
        "the p.191 ruffian 1-in-4 matrix footnote, banded as "
        "five equal fifths of the quarter (fiction-only)."),
    "city_band_protection.lua": lambda d: band_lua_text(
        "city_band_protection", "rollProtectionDevice bands",
        PROTECTION,
        "the p.192 protection device subtable; the PROT_* enum "
        "mapping stays in the engine (the bracers/cloak "
        "mechanics are engine code)."),
}


def emit_lua(data):
    os.makedirs(LUA_DIR, exist_ok=True)
    for name in sorted(LUA_FILES):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(LUA_FILES[name](data))


def lua_roundtrip(data):
    """parse the emitted lua back and prove byte-exact equality"""
    # matrix
    t = open(os.path.join(LUA_DIR, "city_matrix.lua")).read()
    rows = re.findall(
        r'\{ key = "([a-z_]+)", day = \{(-?\d+),(-?\d+)\}, '
        r'night = \{(-?\d+),(-?\d+)\} \}', t)
    if len(rows) != MATRIX_ROWS:
        die("round-trip: %d matrix rows" % len(rows))
    def norm(v):
        return 0 if int(v) == -1 else int(v)
    got = [(norm(a), norm(b), norm(c), norm(d), k)
           for k, a, b, c, d in rows]
    if got != data["matrix"]:
        die("round-trip: city_matrix mismatch")
    # counts
    t = open(os.path.join(LUA_DIR, "city_counts.lua")).read()
    got = []
    for m in re.finditer(
            r'\{ key = "([a-z_]+)"(?:, dice = \{(\d+),(\d+),(\d+)\})?'
            r'(?:, nightDice = \{(\d+),(\d+),(\d+)\})?'
            r'(?:, fixed = (\d+))? \}', t):
        k = m.group(1)
        if m.group(2):
            dice = (int(m.group(2)), int(m.group(3)), int(m.group(4)))
            nd = None
            if m.group(5):
                nd = (int(m.group(5)), int(m.group(6)), int(m.group(7)))
            got.append((k, dice, nd))
        else:
            got.append((k, "fixed%d" % int(m.group(8)), None))
    if got != COUNTS:
        die("round-trip: city_counts mismatch")
    # magic
    t = open(os.path.join(LUA_DIR, "city_magic.lua")).read()
    got = [(m.group(1),
            [int(m.group(2)), int(m.group(3)), int(m.group(4))])
           for m in re.finditer(
               r'\{ category = "([a-z_]+)", groups = '
               r'\{(\d+),(\d+),(\d+)\} \}', t)]
    if got != MAGIC:
        die("round-trip: city_magic mismatch")
    # bands
    for key, bands in data["flavor"]:
        name = key + ".lua"
        t = open(os.path.join(LUA_DIR, name)).read()
        got = [(int(a), int(b), k) for a, b, k in re.findall(
            r'\{ band = \{(\d+),(\d+)\}, kind = "([^"]*)" \}', t)]
        if got != bands:
            die("round-trip: %s mismatch" % key)
    t = open(os.path.join(LUA_DIR, "city_band_protection.lua")).read()
    got = [(int(a), int(b), k) for a, b, k in re.findall(
        r'\{ band = \{(\d+),(\d+)\}, kind = "([^"]*)" \}', t)]
    if got != PROTECTION:
        die("round-trip: city_band_protection mismatch")


# ---------------------------------------------------------------------------
# 4. the registry extension (dm/EncounterTableRegistry.h / .cpp)
# ---------------------------------------------------------------------------

H_COMMENT_OLD = """// tools/r1032_splice.py (dungeon family),
// tools/r1033_splice.py (water family) and
// tools/r1034_splice.py (outdoor family) are the only writers."""
H_COMMENT_NEW = """// tools/r1032_splice.py (dungeon family),
// tools/r1033_splice.py (water family),
// tools/r1034_splice.py (outdoor family) and
// tools/r1035_splice.py (city family) are the only writers."""

H_STRUCT_ANCHOR = """// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""
H_STRUCT_ADD = """// R1035: the city family. One matrix row carries the day and
// night percentile bands of the DMG p.191 city matrix
// (-1 = the book prints no band there); the flavor and
// protection band tables share EncounterCityBand; the printed
// encounter numbers roll plus + nDd (fixed >= 0 overrides);
// the p.192 magic chances carry one percent-per-level entry
// per group (0 fighter-ish, 1 cleric, 2 magic-user).
struct EncounterCityRow {
    std::string key;
    int loDay = -1, hiDay = -1;
    int loNight = -1, hiNight = -1;
};
struct EncounterCityBand {
    int lo = 0, hi = 0;
    std::string kind;
};
struct EncounterCityCount {
    int n = 0, d = 0, plus = 0;
    int nN = 0, dN = 0, plusN = 0;
    bool hasNight = false;
    int fixed = -1;             // -1: dice path; >= 0: printed constant
};
struct EncounterCityMagic {
    std::string category;
    int groups[3] = { 0, 0, 0 };
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""

H_GETTER_ANCHOR = """    const std::vector<std::string>& list(const std::string& set) const;"""
H_GETTER_ADD = """    const std::vector<std::string>& list(const std::string& set) const;
    // R1035: the city family views. cityBandLookup clamps the
    // percentile to 1-100 and returns false when no band matches
    // (the flavorKindFor contract). cityCount returns nullptr for
    // an absent key - the caller rolls one specimen.
    bool hasCityMatrix() const;
    const std::vector<EncounterCityRow>& cityRows() const;
    bool hasCityBands(const std::string& name) const;
    const std::vector<EncounterCityBand>& cityBands(
        const std::string& name) const;
    bool cityBandLookup(const std::string& name, int pctile,
                        std::string* kind) const;
    const EncounterCityCount* cityCount(const std::string& key) const;
    const std::vector<EncounterCityMagic>& cityMagic() const;"""

H_MEMBER_ANCHOR = """    std::map<std::string, std::vector<std::string>> m_lists;"""
H_MEMBER_ADD = """    std::map<std::string, std::vector<std::string>> m_lists;
    // R1035: the city family (one matrix, the band tables, the
    // count dice and the magic chances).
    std::vector<EncounterCityRow> m_city;
    std::map<std::string, std::vector<EncounterCityBand>> m_cityBands;
    std::map<std::string, EncounterCityCount> m_cityCounts;
    std::vector<EncounterCityMagic> m_cityMagic;"""

CPP_KEYS_ANCHOR = """const char* const kOutdoorSetKeys[] =
    { "key", "ki_rin", "leprechaun", "porcupine", "iguanodon",
      "lammasu", "wolf_dog", nullptr };"""
CPP_KEYS_ADD = """const char* const kOutdoorSetKeys[] =
    { "key", "ki_rin", "leprechaun", "porcupine", "iguanodon",
      "lammasu", "wolf_dog", nullptr };
// R1035: the city family file/row keys. The dispatch uses exact
// keys (city_matrix/city_counts/city_magic) plus the exception-free
// city_band_ prefix - the predicates do not overlap (the R1034
// dispatch-order lesson).
const char* const kCityFileKeys[]  = { "key", "rows", nullptr };
const char* const kCityRowKeys[]   = { "key", "day", "night", nullptr };
const char* const kCityCountKeys[] =
    { "key", "dice", "nightDice", "fixed", nullptr };
const char* const kCityMagicKeys[] = { "category", "groups", nullptr };
const char* const kCityBandKeys[]  = { "band", "kind", nullptr };"""

CPP_ISANCHOR = """// R1034: the outdoor family file keys. NOTE: outdoor_sets is
// excluded - it must fall through to its own shape branch (the
// outdoor_sets pick-set loader), not the STRICT rows loader.
bool isOutdoorKey(const std::string& k) {
    return k.rfind("outdoor_", 0) == 0 && k != "outdoor_sets";
}"""
CPP_ISADD = """// R1034: the outdoor family file keys. NOTE: outdoor_sets is
// excluded - it must fall through to its own shape branch (the
// outdoor_sets pick-set loader), not the STRICT rows loader.
bool isOutdoorKey(const std::string& k) {
    return k.rfind("outdoor_", 0) == 0 && k != "outdoor_sets";
}

// R1035: the city family. The three exact keys and the prefix are
// mutually exclusive by construction - no exceptions anywhere.
bool isCityKey(const std::string& k) {
    return k == "city_matrix" || k == "city_counts" || k == "city_magic";
}
bool isCityBandKey(const std::string& k) {
    return k.rfind("city_band_", 0) == 0;
}"""

CPP_BRANCH_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""
CPP_BRANCH_ADD = """    } else if (key == "city_matrix") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kCityFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterCityRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i)
                        + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kCityRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterCityRow row;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                for (int pass = 0; pass < 2; ++pass) {
                    lua_getfield(L, rt, pass == 0 ? "day" : "night");
                    if (!lua_istable(L, -1)
                        || (int)lua_rawlen(L, -1) != 2) {
                        err = std::string(pass == 0 ? "day" : "night")
                            + " must be a {lo, hi} pair";
                        goto bad;
                    }
                    long long v[2];
                    for (int j = 0; j < 2; ++j) {
                        lua_rawgeti(L, -1, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "band pair field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);
                    const int clo = (int)v[0], chi = (int)v[1];
                    if (clo == -1 && chi == -1) {
                        // no band in this column (legal)
                    } else if (clo >= 1 && clo <= 100
                               && chi >= clo && chi <= 100) {
                        if (pass == 0) { row.loDay = clo; row.hiDay = chi; }
                        else { row.loNight = clo; row.hiNight = chi; }
                    } else {
                        err = "band pair outside 01-00";
                        goto bad;
                    }
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (!m_city.empty()) { err = "duplicate def key"; goto bad; }
            m_city = rows;
        }
    } else if (key == "city_counts") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kCityFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::map<std::string, EncounterCityCount> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)
                    || !checkAllowedKeys(L, rt, kCityCountKeys,
                        key + " rows[" + std::to_string(i) + "]", &err)) {
                    if (lua_istable(L, rt))
                        lua_pop(L, 1);
                    goto bad;
                }
                EncounterCityCount c;
                std::string ck;
                if (!getStr(L, rt, "key", &ck, &err)) goto bad;
                if (rows.count(ck)) { err = "duplicate count key";
                                      goto bad; }
                bool haveDice = false, haveFixed = false;
                lua_getfield(L, rt, "dice");
                if (!lua_isnil(L, -1)) {
                    if (!lua_istable(L, -1)
                        || (int)lua_rawlen(L, -1) != 3) {
                        err = "dice must be {n, d, plus}";
                        lua_pop(L, 1);
                        goto bad;
                    }
                    long long v[3];
                    for (int j = 0; j < 3; ++j) {
                        lua_rawgeti(L, -1, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "dice field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);
                    if (v[0] < 1 || v[1] < 1 || v[2] < 0) {
                        err = "dice outside n>=1, d>=1, plus>=0";
                        goto bad;
                    }
                    c.n = (int)v[0]; c.d = (int)v[1];
                    c.plus = (int)v[2];
                    haveDice = true;
                } else {
                    lua_pop(L, 1);
                }
                lua_getfield(L, rt, "nightDice");
                if (!lua_isnil(L, -1)) {
                    if (!haveDice) {
                        err = "nightDice without dice";
                        lua_pop(L, 1);
                        goto bad;
                    }
                    if (!lua_istable(L, -1)
                        || (int)lua_rawlen(L, -1) != 3) {
                        err = "nightDice must be {n, d, plus}";
                        lua_pop(L, 1);
                        goto bad;
                    }
                    long long v[3];
                    for (int j = 0; j < 3; ++j) {
                        lua_rawgeti(L, -1, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "nightDice field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);
                    if (v[0] < 1 || v[1] < 1 || v[2] < 0) {
                        err = "nightDice outside n>=1, d>=1, plus>=0";
                        goto bad;
                    }
                    c.nN = (int)v[0]; c.dN = (int)v[1];
                    c.plusN = (int)v[2];
                    c.hasNight = true;
                } else {
                    lua_pop(L, 1);
                }
                lua_getfield(L, rt, "fixed");
                if (!lua_isnil(L, -1)) {
                    if (!lua_isinteger(L, -1)) {
                        err = "'fixed' is not an integer";
                        lua_pop(L, 1);
                        goto bad;
                    }
                    const long long fv = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (fv < 1 || fv > 100) {
                        err = "'fixed' outside 1-100";
                        goto bad;
                    }
                    if (haveDice) {
                        err = "dice and fixed are mutually exclusive";
                        goto bad;
                    }
                    c.fixed = (int)fv;
                    haveFixed = true;
                } else {
                    lua_pop(L, 1);
                }
                if (!haveDice && !haveFixed) {
                    err = "row needs dice or fixed";
                    goto bad;
                }
                rows[ck] = c;
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_cityCounts.size()) { err = "duplicate def key";
                                       goto bad; }
            m_cityCounts = rows;
        }
    } else if (key == "city_magic") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kCityFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterCityMagic> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i)
                        + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kCityMagicKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterCityMagic row;
                if (!getStr(L, rt, "category", &row.category, &err))
                    goto bad;
                if (row.category != "sword"
                    && row.category != "misc_weapon"
                    && row.category != "armor"
                    && row.category != "protection") {
                    err = "unknown magic category '" + row.category + "'";
                    goto bad;
                }
                for (const auto& prev : rows)
                    if (prev.category == row.category) {
                        err = "duplicate magic category";
                        goto bad;
                    }
                lua_getfield(L, rt, "groups");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 3) {
                    err = "groups must carry 3 chances";
                    goto bad;
                }
                for (int j = 0; j < 3; ++j) {
                    lua_rawgeti(L, -1, j + 1);
                    if (!lua_isinteger(L, -1)) {
                        err = "groups field is not an integer";
                        goto bad;
                    }
                    const long long v = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (v < 0 || v > 100) {
                        err = "groups chance outside 0-100";
                        goto bad;
                    }
                    row.groups[j] = (int)v;
                }
                lua_pop(L, 1);            // groups
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_cityMagic.size()) { err = "duplicate def key";
                                      goto bad; }
            m_cityMagic = rows;
        }
    } else if (isCityBandKey(key)) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kCityFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterCityBand> rows;
            int prev = 0;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)
                    || !checkAllowedKeys(L, rt, kCityBandKeys,
                        key + " rows[" + std::to_string(i) + "]", &err)) {
                    if (lua_istable(L, rt))
                        lua_pop(L, 1);
                    goto bad;
                }
                lua_getfield(L, rt, "band");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 2) {
                    err = "band must be a {lo, hi} pair";
                    goto bad;
                }
                long long v[2];
                for (int j = 0; j < 2; ++j) {
                    lua_rawgeti(L, -1, j + 1);
                    if (!lua_isinteger(L, -1)) {
                        err = "band field is not an integer";
                        goto bad;
                    }
                    v[j] = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                const int clo = (int)v[0], chi = (int)v[1];
                // STRICT: the flavor tables chain 1 -> 100 with no
                // holes (every R1035 band table is a full chain)
                if (clo != prev + 1 || chi < clo || chi > 100) {
                    err = "band breaks the 1-100 chain";
                    goto bad;
                }
                prev = chi;
                EncounterCityBand row;
                row.lo = clo;
                row.hi = chi;
                if (!getStr(L, rt, "kind", &row.kind, &err)) goto bad;
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (prev != 100) { err = "bands do not reach 100"; goto bad; }
            if (m_cityBands.count(key)) { err = "duplicate def key";
                                          goto bad; }
            m_cityBands[key] = rows;
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_ACC_ANCHOR = """const std::vector<EncounterOutdoorRow>&
EncounterTableRegistry::outdoorRows(
    const std::string& name) const {"""
# the accessor tail is located dynamically (see extend_registry)
CPP_ACC_TAIL_ANCHOR = """    auto it = m_outdoors.find(name);
    return it == m_outdoors.end() ? none : it->second;
}"""

CPP_ACC_ADD = """    auto it = m_outdoors.find(name);
    return it == m_outdoors.end() ? none : it->second;
}

// ----------------------------------------------------------------------------
// R1035: the city family accessors.
// ----------------------------------------------------------------------------

bool EncounterTableRegistry::hasCityMatrix() const {
    return !m_city.empty();
}

const std::vector<EncounterCityRow>&
EncounterTableRegistry::cityRows() const {
    return m_city;
}

bool EncounterTableRegistry::hasCityBands(
    const std::string& name) const {
    return m_cityBands.count(name) != 0;
}

const std::vector<EncounterCityBand>&
EncounterTableRegistry::cityBands(const std::string& name) const {
    static const std::vector<EncounterCityBand> none;
    auto it = m_cityBands.find(name);
    return it == m_cityBands.end() ? none : it->second;
}

bool EncounterTableRegistry::cityBandLookup(
    const std::string& name, int pctile, std::string* kind) const {
    if (pctile < 1)   pctile = 1;
    if (pctile > 100) pctile = 100;
    for (const auto& b : cityBands(name))
        if (pctile >= b.lo && pctile <= b.hi) {
            if (kind) *kind = b.kind;
            return true;
        }
    return false;
}

const EncounterCityCount*
EncounterTableRegistry::cityCount(const std::string& key) const {
    auto it = m_cityCounts.find(key);
    return it == m_cityCounts.end() ? nullptr : &it->second;
}

const std::vector<EncounterCityMagic>&
EncounterTableRegistry::cityMagic() const {
    return m_cityMagic;
}"""


def replace_once(text, old, new, where):
    if text.count(old) != 1:
        die("anchor in %s must occur exactly once (found %d)"
            % (where, text.count(old)))
    return text.replace(old, new, 1)


def extend_registry():
    h = open(REG_H).read()
    if "EncounterCityRow" in h:
        return False
    h = replace_once(h, H_COMMENT_OLD, H_COMMENT_NEW, "registry header comment")
    h = replace_once(h, H_STRUCT_ANCHOR, H_STRUCT_ADD, "registry h struct")
    h = replace_once(h, H_GETTER_ANCHOR, H_GETTER_ADD, "registry h getters")
    h = replace_once(h, H_MEMBER_ANCHOR, H_MEMBER_ADD, "registry h members")
    with open(REG_H, "w") as f:
        f.write(h)

    c = open(REG_CPP).read()
    c = replace_once(c, CPP_KEYS_ANCHOR, CPP_KEYS_ADD, "registry cpp keys")
    c = replace_once(c, CPP_ISANCHOR, CPP_ISADD, "registry cpp predicates")
    c = replace_once(c, CPP_BRANCH_ANCHOR, CPP_BRANCH_ADD,
                     "registry cpp dispatch")
    c = replace_once(c, CPP_ACC_TAIL_ANCHOR, CPP_ACC_ADD,
                     "registry cpp accessors")
    with open(REG_CPP, "w") as f:
        f.write(c)
    return True


# ---------------------------------------------------------------------------
# 5. the dm/encounters.cpp seam
# ---------------------------------------------------------------------------

ENC_LOAD_OLD = """        // R1034: the outdoor family joined likewise (the R1033
        // audit pins 9 files in encounters_water/).
        reg.loadDirectory("content/tables/encounters_outdoor");
    }"""
ENC_LOAD_NEW = """        // R1034: the outdoor family joined likewise (the R1033
        // audit pins 9 files in encounters_water/).
        reg.loadDirectory("content/tables/encounters_outdoor");
        // R1035: the city family joined likewise (the R1034
        // audit pins 21 files in encounters_outdoor/).
        reg.loadDirectory("content/tables/encounters_city");
    }"""


def city_body(c64, r146, r174):
    """the registry-native replacement region"""
    parts = []
    parts.append(c64)
    parts.append(r"""
namespace {

// R1035 (the registry-native de-wire, the R1032-R1034 shape): the
// matrix rows retired into content/tables/encounters_city/
// city_matrix.lua; the printed count dice into city_counts.lua (the
// dead bard entry preserved, documented); the p.192 protection
// subtable into city_band_protection.lua; the p.192 chance-per-
// level table into city_magic.lua; the R146/R174 flavor bands
// into city_band_drunk/_harlot/_noble/_sedan/_ruffian.lua. The
// registry loads the directory (encReg() above). What stays here
// is the mechanics: the classed party builds (rollCityParty,
// verbatim below), the second-percentile splits, the nycadaemon/
// mezzadaemon re-roll advice (p.191), plusForLevel and the PROT_*
// device enum mapping. Signatures and behavior are unchanged -
// the views are registry-backed.
int cityCountFor(rules::Dice& dice, const std::string& key, bool night) {
    const dm::EncounterCityCount* c = dm::encReg().cityCount(key);
    if (!c)
        // one specimen (ghost, ghoul's kin, vampire, lich,
        // doppelganger's kin, goodwife, harlot, paladin-less
        // singles)
        return 1;
    if (c->fixed >= 0)
        return c->fixed;
    if (c->hasNight && night)
        return c->plusN + (int)dice.roll(c->nN, c->dN, 0);
    return c->plus + (int)dice.roll(c->n, c->d, 0);
}

// p.192 protection device subtable: the bands retired to the
// registry (city_band_protection); the enum and the mechanical
// mapping stay here (the R1034 PROT semantics unchanged).
enum { PROT_RING1, PROT_RING2, PROT_RING3, PROT_AMULET,
       PROT_BRACERS6, PROT_BRACERS4, PROT_BRACERS2,
       PROT_DISPLACEMENT, PROT_CLOAK1, PROT_CLOAK2, PROT_CLOAK3 };

static int protectionDeviceFromKind(const std::string& k) {
    if (k == "prot_ring1")        return PROT_RING1;
    if (k == "prot_ring2")        return PROT_RING2;
    if (k == "prot_ring3")        return PROT_RING3;
    if (k == "prot_amulet")       return PROT_AMULET;
    if (k == "prot_bracers6")     return PROT_BRACERS6;
    if (k == "prot_bracers4")     return PROT_BRACERS4;
    if (k == "prot_bracers2")     return PROT_BRACERS2;
    if (k == "prot_displacement") return PROT_DISPLACEMENT;
    if (k == "prot_cloak1")       return PROT_CLOAK1;
    if (k == "prot_cloak2")       return PROT_CLOAK2;
    if (k == "prot_cloak3")       return PROT_CLOAK3;
    return PROT_AMULET;   // unreachable: the bands chain to 100
}

static int rollProtectionDevice(rules::Dice& dice) {
    std::string kind;
    dm::encReg().cityBandLookup("city_band_protection",
                                (int)dice.roll(1, 100, 0), &kind);
    return protectionDeviceFromKind(kind);
}

// "The power of the item must be commensurate with the level of
// the possessor" (p.192): +1 at 1st-5th, +2 at 6th-11th, +3 at
// 12th and above (documented approximation, R55's ladder spirit)
static int plusForLevel(int level) {
    if (level >= 12) return 3;
    if (level >= 6)  return 2;
    return 1;
}

} // namespace

// R1035: the matrix view, cached once (the R1032 levelView shape).
static const std::vector<dm::EncounterCityRow>& cityView() {
    static std::vector<dm::EncounterCityRow> cache;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        cache = dm::encReg().cityRows();
    }
    return cache;
}
""")
    parts.append(r146)
    parts.append(r"""
namespace {

// R1035: the flavor band scan (the retired R146/R174 helper,
// registry-backed; the clamp contract unchanged).
static const char* cityKindFor(const char* table, int pctile) {
    if (pctile < 1)   pctile = 1;
    if (pctile > 100) pctile = 100;
    const auto& bands = dm::encReg().cityBands(table);
    for (const auto& b : bands)
        if (pctile >= b.lo && pctile <= b.hi)
            return b.kind.c_str();
    return "";
}

}   // namespace

const char* cityDrunkKind(int pctile) {
    return cityKindFor("city_band_drunk", pctile);
}

const char* cityHarlotKind(int pctile) {
    return cityKindFor("city_band_harlot", pctile);
}

""")
    parts.append(r174)
    parts.append(r"""
const char* cityNobleKind(int pctile) {
    return cityKindFor("city_band_noble", pctile);
}

const char* cityNoblewomanSedan(int pctile) {
    return cityKindFor("city_band_sedan", pctile);
}

const char* cityRuffianKind(int pctile) {
    return cityKindFor("city_band_ruffian", pctile);
}
""")
    return "".join(parts)


# rollCityMagicItems / rollCityParty / rollCityEncounter /
# cityEncounterKeys - the kept mechanics, registry-backed where
# the retired arrays stood. The bodies are the R64 semantics
# verbatim (the magic chances now read the registry).
CITY_ROLL = r"""
// R64: p.192 CHANCE PER LEVEL FOR MAGIC ITEM - one percentile
// roll per category at (chance x level), the chances read from
// the registry (city_magic.lua; the retired 4x3 array's values
// unchanged). Group 0: assassin, fighter, thief, etc.; group 1:
// cleric, druid; group 2: magic-user. The printed monk column
// has no engine class (monks resolve as fighters per R53) -
// documented. Potions, scrolls, rings, wands/staffs/rods and
// misc magic exist in the fiction but have no mechanical effect
// here (R55).
static void rollCityMagicItems(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // 0-level men: hp is all they need

    int group = (m.classIndex == rules::CLASS_CLERIC) ? 1
              : (m.classIndex == rules::CLASS_MAGIC_USER) ? 2 : 0;

    const auto& magic = dm::encReg().cityMagic();
    auto chance = [&](const char* category) -> int {
        for (const auto& r : magic)
            if (r.category == category)
                return r.groups[group];
        return 0;
    };

    int lvl = m.level;
    if ((int)dice.roll(1, 100, 0) <= chance("sword") * lvl)
        m.wpnPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= chance("misc_weapon") * lvl)
        m.rngPlus = plusForLevel(lvl);
    if ((int)dice.roll(1, 100, 0) <= chance("armor") * lvl) {
        m.armPlus = plusForLevel(lvl);
        // "Armor &/or Shield" - the shield is a coin-flip half
        // of the category (documented split)
        if ((int)dice.roll(1, 2, 0) == 2)
            m.shdPlus = plusForLevel(lvl);
    }
    if ((int)dice.roll(1, 100, 0) <= chance("protection") * lvl) {
        switch (rollProtectionDevice(dice)) {
            case PROT_RING1: case PROT_CLOAK1: m.shdPlus += 1; break;
            case PROT_RING2: case PROT_CLOAK2: m.shdPlus += 2; break;
            case PROT_RING3: case PROT_CLOAK3: m.shdPlus += 3; break;
            // bracers replace armor: the AC-6/4/2 sets read as
            // +2/+4/+6 unarmored (documented approximation)
            case PROT_BRACERS6: m.armPlus = (m.armPlus > 2) ? m.armPlus : 2; break;
            case PROT_BRACERS4: m.armPlus = (m.armPlus > 4) ? m.armPlus : 4; break;
            case PROT_BRACERS2: m.armPlus = (m.armPlus > 6) ? m.armPlus : 6; break;
            // cloak of displacement: -2 AC in the MM
            case PROT_DISPLACEMENT: m.shdPlus += 2; break;
            case PROT_AMULET:
            default: break;   // fiction only
        }
    }
}

// R64: build a city party to the p.191-192 explanations.
// asterisk = rollNpcRace (R62); unasterisked classed types are
// human (1e class restrictions). Followers and leaders are
// henchmen; 0-level guardsmen are men-at-arms (R53 shapes).
// VERBATIM (R1035 kept the mechanics; only the tables retired).
static CharacterParty rollCityParty(rules::Dice& dice,
                                    const char* type, bool night) {
    CharacterParty p;
    const std::string t(type);

    auto add = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
        return m;
    };
    auto addHench = [&](int classIndex, int level, bool asterisk) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.henchman = true;
        m.race = asterisk ? rollNpcRace(dice, classIndex)
                          : RACE_HUMAN;
        rollCityMagicItems(dice, m);
        p.members.push_back(m);
    };
    auto addMan = [&](int n) {
        for (int i = 0; i < n; ++i) {
            PartyMember m;
            m.manAtArms = true;               // 0-level men (R53)
            m.classIndex = rules::CLASS_FIGHTER;
            m.level = 0;
            m.race = RACE_HUMAN;
            p.members.push_back(m);
        }
    };

    if (t == "assassin") {
        // 1-3 assassins; the book prints no level here - the
        // 5th-8th ruffian bodyguard range, the only city
        // assassin range printed, is used (documented)
        int n = (int)dice.roll(1, 3, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_THIEF, 4 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "cleric") {
        // cleric 6th-11th (d6+5) + 0-5 lesser clerics (d4 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        int n = (int)dice.roll(1, 6, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
    } else if (t == "druid") {
        // druid 6th-11th; 50% 0-3 lesser druids (d4 level),
        // else 1-4 fighters (d6 level)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 6, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_CLERIC, (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "fighter") {
        // fighter 6th-12th (2d4+4) + 0-3 henchmen (d4 level)
        add(rules::CLASS_FIGHTER,
            4 + (int)dice.roll(2, 4, 0), true);
        int n = (int)dice.roll(1, 4, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER, (int)dice.roll(1, 4, 0), true);
    } else if (t == "illusionist") {
        // illusionist 7th-10th (d4+6); 50% 0-3 apprentices
        // (d4 level), else 1-3 fighter guards (d6 level)
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 4, 0), true);
        if ((int)dice.roll(1, 2, 0) == 1) {
            int n = (int)dice.roll(1, 4, 0) - 1;
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 4, 0), true);
        } else {
            int n = (int)dice.roll(1, 3, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         (int)dice.roll(1, 6, 0), true);
        }
    } else if (t == "magic_user") {
        // magic-user 7th-12th (d6+6) + 1-4 henchmen: 45%
        // apprentices (d6 level), 30% fighter guards (d4+3),
        // 25% a mixture "providing 2 or 4 henchmen" - the
        // count is forced to 2 or 4 and split evenly
        add(rules::CLASS_MAGIC_USER,
            6 + (int)dice.roll(1, 6, 0), true);
        int roll = (int)dice.roll(1, 100, 0);
        if (roll <= 45) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_MAGIC_USER,
                         (int)dice.roll(1, 6, 0), true);
        } else if (roll <= 75) {
            int n = (int)dice.roll(1, 4, 0);
            for (int i = 0; i < n; ++i)
                addHench(rules::CLASS_FIGHTER,
                         3 + (int)dice.roll(1, 4, 0), true);
        } else {
            int n = ((int)dice.roll(1, 2, 0) == 1) ? 2 : 4;
            for (int i = 0; i < n; ++i)
                addHench((i % 2 == 0) ? rules::CLASS_MAGIC_USER
                                      : rules::CLASS_FIGHTER,
                         (i % 2 == 0) ? (int)dice.roll(1, 6, 0)
                                      : 3 + (int)dice.roll(1, 4, 0),
                         true);
        }
    } else if (t == "monk") {
        // one monk, 7th-10th (d4+6); monks resolve as fighters
        // (R53 closest-approximation), human (no asterisk)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "paladin") {
        // one paladin, 6th-9th (d4+5); human (1e requirement)
        add(rules::CLASS_FIGHTER, 5 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "ranger") {
        // one ranger, 7th-10th (d4+6), race-checked (*)
        add(rules::CLASS_FIGHTER, 6 + (int)dice.roll(1, 4, 0), true);
    } else if (t == "thief") {
        // thief 8th-11th (d4+7) + 0-2 apprentices (d4 level)
        add(rules::CLASS_THIEF, 7 + (int)dice.roll(1, 4, 0), true);
        int n = (int)dice.roll(1, 3, 0) - 1;
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_THIEF, (int)dice.roll(1, 4, 0), true);
    } else if (t == "rake") {
        // 2-5 young gentlemen fighters, 5th-10th (d6+4)
        int n = 1 + (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            add(rules::CLASS_FIGHTER,
                4 + (int)dice.roll(1, 6, 0), false);
    } else if (t == "city_guard") {
        // 2-16 0-level guardsmen; 1 leader (2 if more than 8,
        // 3 if more than 12) of 2nd-5th (d4+1); plus an
        // indentured magic-user of 1st-4th - all race-checked
        // (the matrix asterisks the City guard)
        int n = 1 + (int)dice.roll(1, 16, 0);
        addMan(n);
        int leaders = (n > 12) ? 3 : (n > 8) ? 2 : 1;
        for (int i = 0; i < leaders; ++i)
            addHench(rules::CLASS_FIGHTER,
                     1 + (int)dice.roll(1, 4, 0), true);
        addHench(rules::CLASS_MAGIC_USER,
                 (int)dice.roll(1, 4, 0), true);
    } else if (t == "city_watchman") {
        // day: 5 men + 1st-3rd sergeant; night: double numbers
        // plus a 4th/5th-level lieutenant; always accompanied
        // by an indentured cleric of 2nd-5th (d4+1)
        addMan(night ? 10 : 5);
        addHench(rules::CLASS_FIGHTER,
                 (int)dice.roll(1, 3, 0), false);   // sergeant
        if (night)
            addHench(rules::CLASS_FIGHTER,
                     3 + (int)dice.roll(1, 2, 0), false);  // lieutenant
        addHench(rules::CLASS_CLERIC,
                 1 + (int)dice.roll(1, 4, 0), false);
    } else if (t == "city_official") {
        // a minor bureaucrat (10% a major official with 2-8
        // guards); always 1-4 personal fighters (d4 level).
        // The official is fiction - a man-at-arms shape - the
        // guards are classed. No asterisk: human.
        addMan(1);
        bool major = (int)dice.roll(1, 10, 0) == 10;
        if (major)
            addMan(1 + (int)dice.roll(1, 8, 0));
        int n = (int)dice.roll(1, 4, 0);
        for (int i = 0; i < n; ++i)
            addHench(rules::CLASS_FIGHTER,
                     (int)dice.roll(1, 4, 0), false);
    }
    (void)add;
    return p;
}

DungeonEncounter rollCityEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2, CityTime time) {
    DungeonEncounter e;
    const std::vector<dm::EncounterCityRow>& matrix = cityView();

    for (int attempt = 0; attempt < 24; ++attempt) {
        const dm::EncounterCityRow* row = nullptr;
        for (size_t i = 0; i < matrix.size(); ++i) {
            int lo, hi;
            if (time == CITY_DAY) { lo = matrix[i].loDay;  hi = matrix[i].hiDay;  }
            else                  { lo = matrix[i].loNight; hi = matrix[i].hiNight; }
            if (lo > 0 && pctile >= lo && pctile <= hi)
                { row = &matrix[i]; break; }
        }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key = row->key;

        // the book's own advice: "they may be ignored entirely
        // if desirable ... treat these encounters as highly
        // special" (p.191); nycadaemon/mezzadaemon are
        // unimplemented (R52) - ignore & re-roll
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon") {
            pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
            pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
            continue;
        }

        // printed 50/50 - 75/25 splits (second percentile)
        if (key == "laborer_or_peddler")
            key = (pctile2 <= 50) ? "laborer" : "peddler";
        else if (key == "monk_or_bard")
            key = (pctile2 <= 60) ? "monk" : "bard";
        else if (key == "ghoul_or_ghast")
            key = (pctile2 <= 30) ? "ghoul" : "ghast";
        else if (key == "vampire_or_lich")
            key = (pctile2 <= 75) ? "vampire" : "lich";
        else if (key == "brigand")
            key = "bandit";   // "the same as bandit encounters"

        // classed / service encounters: character parties
        if (key == "assassin" || key == "cleric" || key == "druid" ||
            key == "fighter" || key == "illusionist" ||
            key == "magic_user" || key == "monk" || key == "paladin" ||
            key == "ranger" || key == "thief" || key == "rake" ||
            key == "city_guard" || key == "city_official" ||
            key == "city_watchman") {
            e.party = rollCityParty(dice, key.c_str(),
                                    time == CITY_NIGHT);
            e.isParty = true;
            e.key = key;
            e.count = e.party.size();
            return e;
        }

        e.key = key;
        e.count = cityCountFor(dice, key,
                               time == CITY_NIGHT);
        (void)reg;   // fiction keys may not be registry keys;
                     // the regtest companion lists both
        return e;
    }
    return e;
}

// Every result key the matrix can produce - registry keys for
// the monsters, fiction keys for the civilians, party-type
// keys for the classed and service encounters (resolved as
// character parties). The regtest companion of
// rollCityEncounter.
std::vector<std::string> cityEncounterKeys(
        const monsters::MonsterRegistry& reg) {
    std::vector<std::string> out;
    const std::vector<dm::EncounterCityRow>& matrix = cityView();
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::string key = matrix[i].key;
        if (key == "laborer_or_peddler") {
            pushUnique(out, "laborer");
            pushUnique(out, "peddler");
            continue;
        }
        if (key == "monk_or_bard") {
            pushUnique(out, "monk");
            pushUnique(out, "bard");
            continue;
        }
        if (key == "ghoul_or_ghast") {
            pushUnique(out, "ghoul");
            pushUnique(out, "ghast");
            continue;
        }
        if (key == "vampire_or_lich") {
            pushUnique(out, "vampire");
            pushUnique(out, "lich");
            continue;
        }
        if (key == "brigand") {
            pushUnique(out, "bandit");
            continue;
        }
        if (key == "demon_or_nycadaemon" ||
            key == "devil_or_mezzadaemon")
            continue;   // ignored & re-rolled (documented)
        pushUnique(out, key.c_str());
    }
    (void)reg;
    return out;
}
"""


def splice_encounters(src, start, end, body):
    # the kept mechanics slot in after the R174 flavor functions
    body = body.replace(
        'return cityKindFor("city_band_ruffian", pctile);\n}\n',
        'return cityKindFor("city_band_ruffian", pctile);\n}\n'
        + CITY_ROLL)
    new = src[:start] + body + src[end:]
    new = replace_once(new, ENC_LOAD_OLD, ENC_LOAD_NEW,
                       "encReg directory loads")
    return new


# ---------------------------------------------------------------------------
# 6. the R1035 battery fragment
# ---------------------------------------------------------------------------

def build_fragment():
    L = []
    A = L.append
    A("// ============================================================================")
    A("// Adnd1 - rules/audits/r1035_city_encounter_registry.h  (R1035)")
    A("// The city/town encounter family battery audit, the")
    A("// R1032-R1034 shape: the registry load, exact table counts,")
    A("// band coverage, row/dice/chance spot pins against the retired")
    A("// print-fidelity record, the flavor engine parity, the key")
    A("// companion vs the matrix, and the rollCityEncounter() path.")
    A("// Expected values: 9 city files - the 46-row city matrix")
    A("// (day/night percentile bands), 28 count-dice entries, the")
    A("// 4x3 magic chances and the six band tables (drunk 20,")
    A("// harlot 12, noble 2, sedan 2, ruffian 6, protection 11) -")
    A("// all from the R64/R146/R174 city record (Premium reprint")
    A("// p.190-192) the splice parsed. The city keys are fiction-")
    A("// heavy: party-type and civilian keys carry no bestiary")
    A("// record by design, so the companion is checked against the")
    A("// matrix expansion, not reg.find().")
    A("// ============================================================================")
    A("{")
    A("")
    A("    static const char* const kBands[6] = {")
    A('        "city_band_drunk", "city_band_harlot",')
    A('        "city_band_noble", "city_band_sedan",')
    A('        "city_band_ruffian", "city_band_protection" };')
    A("    static const int kBandRows[6] = { 20, 12, 2, 2, 6, 11 };")
    A("")
    A("    int bad = 0;")
    A("    dm::EncounterTableRegistry ereg;")
    A("")
    A("    // -- 1. load: 9 city files, zero errors, all dirs one reg --")
    A("    bad = 0;")
    A("    {")
    A("        const int cf = ereg.loadDirectory(")
    A('            "content/tables/encounters_city");')
    A("        if (cf != 9) ++bad;")
    A("        if (!ereg.errors().empty()) ++bad;")
    A("        const int of = ereg.loadDirectory(")
    A('            "content/tables/encounters_outdoor");')
    A("        if (of != 21) ++bad;")
    A("        const int df = ereg.loadDirectory(")
    A('            "content/tables/encounters");')
    A("        if (df != 20) ++bad;")
    A("        const int wf = ereg.loadDirectory(")
    A('            "content/tables/encounters_water");')
    A("        if (wf != 9) ++bad;")
    A("        if (!ereg.hasCityMatrix()) ++bad;")
    A('        if (!ereg.hasCityBands("city_band_drunk")) ++bad;')
    A('        if (!ereg.hasCityBands("city_band_harlot")) ++bad;')
    A('        if (!ereg.hasCityBands("city_band_noble")) ++bad;')
    A('        if (!ereg.hasCityBands("city_band_sedan")) ++bad;')
    A('        if (!ereg.hasCityBands("city_band_ruffian")) ++bad;')
    A('        if (!ereg.hasCityBands("city_band_protection")) ++bad;')
    A("        // negative pins (the R1034 dispatch-order lesson:")
    A("        // the exact keys and the prefix must stay exclusive)")
    A('        if (ereg.hasCityBands("city_matrix")) ++bad;')
    A('        if (ereg.hasCityBands("outdoor_sets")) ++bad;')
    A('        if (ereg.hasOutdoor("city_matrix")) ++bad;')
    A('        if (ereg.hasWater("city_band_drunk")) ++bad;')
    A('        if (ereg.hasCityBands("")) ++bad;')
    A("    }")
    A('    printf("R1035 city encounter registry load audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 2. counts: the matrix, bands, dice and chances -----")
    A("    bad = 0;")
    A("    {")
    A("        if ((int)ereg.cityRows().size() != 46) ++bad;")
    A("        int bandTotal = 0;")
    A("        for (int i = 0; i < 6; ++i) {")
    A("            const int n = (int)ereg.cityBands(kBands[i]).size();")
    A("            if (n != kBandRows[i]) ++bad;")
    A("            bandTotal += n;")
    A("        }")
    A("        if (bandTotal != 53) ++bad;")
    A("        static const char* const kCountKeys[28] = {")
    A('            "bandit", "beggar", "doppelganger", "giant_rat",')
    A('            "ghoul", "ghast", "drunk", "gentleman", "laborer",')
    A('            "peddler", "mercenary", "merchant", "bard",')
    A('            "night_hag", "noble", "pilgrim", "press_gang",')
    A('            "rakshasa", "ruffian", "shadow", "spectre",')
    A('            "tradesman", "wererat", "weretiger", "werewolf",')
    A('            "wight", "will_o_wisp", "wraith" };')
    A("        int countTotal = 0;")
    A("        for (int i = 0; i < 28; ++i)")
    A("            if (ereg.cityCount(kCountKeys[i])) ++countTotal;")
    A("            else ++bad;")
    A("        if (countTotal != 28) ++bad;")
    A("        // fallthrough keys roll one specimen")
    A('        if (ereg.cityCount("ghost")) ++bad;')
    A('        if (ereg.cityCount("vampire")) ++bad;')
    A('        if (ereg.cityCount("harlot")) ++bad;')
    A('        if (ereg.cityCount("assassin")) ++bad;   // party path')
    A("        if ((int)ereg.cityMagic().size() != 4) ++bad;")
    A("    }")
    A('    printf("R1035 city encounter registry counts audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 3. bands: day/night chains + every flavor table ---")
    A("    bad = 0;")
    A("    {")
    A("        for (int pass = 0; pass < 2; ++pass) {")
    A("            int prev = 0;")
    A("            for (const auto& r : ereg.cityRows()) {")
    A("                const int lo = pass == 0 ? r.loDay : r.loNight;")
    A("                const int hi = pass == 0 ? r.hiDay : r.hiNight;")
    A("                if (lo < 0) continue;")
    A("                if (lo != prev + 1 || hi < lo || hi > 100) ++bad;")
    A("                prev = hi;")
    A("            }")
    A("            if (prev != 100) ++bad;")
    A("        }")
    A("        for (int i = 0; i < 6; ++i) {")
    A("            int prev = 0;")
    A("            for (const auto& b : ereg.cityBands(kBands[i])) {")
    A("                if (b.lo != prev + 1 || b.hi < b.lo || b.hi > 100)")
    A("                    ++bad;")
    A("                prev = b.hi;")
    A("            }")
    A("            if (prev != 100) ++bad;")
    A("        }")
    A("    }")
    A('    printf("R1035 city encounter registry bands audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 4. pins: matrix rows, dice, chances (the record) ---")
    A("    bad = 0;")
    A("    {")
    A("        const auto& m = ereg.cityRows();")
    A('        if (m[0].key != "assassin") ++bad;')
    A("        if (m[0].loDay != 1 || m[0].hiDay != 1) ++bad;")
    A("        if (m[0].loNight != 1 || m[0].hiNight != 3) ++bad;")
    A('        if (m[8].key != "demon_or_nycadaemon") ++bad;')
    A("        if (m[8].loDay != -1 || m[8].hiDay != -1) ++bad;")
    A("        if (m[8].loNight != 23 || m[8].hiNight != 23) ++bad;")
    A('        if (m[40].key != "weretiger") ++bad;')
    A("        if (m[40].loDay != 99 || m[40].hiDay != 99) ++bad;")
    A("        if (m[40].loNight != 94 || m[40].hiNight != 94) ++bad;")
    A('        if (m[45].key != "vampire_or_lich") ++bad;')
    A("        if (m[45].loDay != -1 || m[45].hiDay != -1) ++bad;")
    A("        if (m[45].loNight != 100 || m[45].hiNight != 100) ++bad;")
    A("        // dice pins (the printed numbers, code behavior)")
    A("        const auto* c = ereg.cityCount(\"bandit\");")
    A("        if (!c || c->n != 1 || c->d != 10 || c->plus != 2) ++bad;")
    A("        c = ereg.cityCount(\"giant_rat\");")
    A("        if (!c || !c->hasNight) ++bad;")
    A("        else {")
    A("            if (c->n != 2 || c->d != 4 || c->plus != 0) ++bad;")
    A("            if (c->nN != 1 || c->dN != 24 || c->plusN != 1) ++bad;")
    A("        }")
    A("        c = ereg.cityCount(\"press_gang\");")
    A("        if (!c || c->n != 1 || c->d != 16 || c->plus != 1) ++bad;")
    A("        c = ereg.cityCount(\"peddler\");")
    A("        if (!c || c->fixed != 1) ++bad;")
    A("        // the dead bard entry, preserved")
    A("        c = ereg.cityCount(\"bard\");")
    A("        if (!c || c->fixed != 1) ++bad;")
    A("        // magic chance pins")
    A("        int sawSword = 0, sawProt = 0;")
    A("        for (const auto& r : ereg.cityMagic()) {")
    A('            if (r.category == "sword") {')
    A("                sawSword = 1;")
    A("                if (r.groups[0] != 10 || r.groups[1] != 0")
    A("                    || r.groups[2] != 0) ++bad;")
    A("            }")
    A('            if (r.category == "protection") {')
    A("                sawProt = 1;")
    A("                if (r.groups[0] != 2 || r.groups[1] != 2")
    A("                    || r.groups[2] != 10) ++bad;")
    A("            }")
    A("        }")
    A("        if (!sawSword || !sawProt) ++bad;")
    A("        // protection band pins")
    A("        std::string kind;")
    A('        if (!ereg.cityBandLookup("city_band_protection", 1, &kind))')
    A("            ++bad;")
    A('        else if (kind != "prot_ring1") ++bad;')
    A('        if (!ereg.cityBandLookup("city_band_protection", 100, &kind))')
    A("            ++bad;")
    A('        else if (kind != "prot_cloak3") ++bad;')
    A("    }")
    A('    printf("R1035 city encounter registry pins audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 5. flavor: the R146/R174 engine parity --------------")
    A("    bad = 0;")
    A("    {")
    A("        static const char* const kFunc[6][2] = {")
    A('            { "city_band_drunk", "drunk" },')
    A('            { "city_band_harlot", "harlot" },')
    A('            { "city_band_noble", "noble" },')
    A('            { "city_band_sedan", "sedan" },')
    A('            { "city_band_ruffian", "ruffian" },')
    A('            { "city_band_protection", "prot" } };')
    A("        for (int f = 0; f < 5; ++f)")
    A("            for (int pct = 1; pct <= 100; ++pct) {")
    A("                std::string want;")
    A("                ereg.cityBandLookup(kFunc[f][0], pct, &want);")
    A("                const char* got =")
    A("                    f == 0 ? dm::cityDrunkKind(pct)")
    A("                    : f == 1 ? dm::cityHarlotKind(pct)")
    A("                    : f == 2 ? dm::cityNobleKind(pct)")
    A("                    : f == 3 ? dm::cityNoblewomanSedan(pct)")
    A("                    : dm::cityRuffianKind(pct);")
    A("                if (got == nullptr || want != got) ++bad;")
    A("            }")
    A("        // the clamp contract (the retired flavorKindFor)")
    A('        if (dm::cityDrunkKind(0)[0] == 0) ++bad;   // clamp, not empty')
    A("        const char* at0 = dm::cityDrunkKind(0);")
    A("        const char* at1 = dm::cityDrunkKind(1);")
    A("        if (std::string(at0) != std::string(at1)) ++bad;")
    A("        const char* at101 = dm::cityDrunkKind(101);")
    A("        const char* at100 = dm::cityDrunkKind(100);")
    A("        if (std::string(at101) != std::string(at100)) ++bad;")
    A("    }")
    A('    printf("R1035 city encounter registry flavor audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 6. keys: the companion vs the matrix expansion ----")
    A("    bad = 0;")
    A("    {")
    A("        const auto got = dm::cityEncounterKeys(reg);")
    A("        std::vector<std::string> want;")
    A("        auto pushU = [&](const std::string& k) {")
    A("            for (const auto& w : want)")
    A("                if (w == k) return;")
    A("            want.push_back(k);")
    A("        };")
    A("        for (const auto& r : ereg.cityRows()) {")
    A("            const std::string k = r.key;")
    A('            if (k == "laborer_or_peddler")')
    A('                { pushU("laborer"); pushU("peddler"); continue; }')
    A('            if (k == "monk_or_bard")')
    A('                { pushU("monk"); pushU("bard"); continue; }')
    A('            if (k == "ghoul_or_ghast")')
    A('                { pushU("ghoul"); pushU("ghast"); continue; }')
    A('            if (k == "vampire_or_lich")')
    A('                { pushU("vampire"); pushU("lich"); continue; }')
    A('            if (k == "brigand")')
    A('                { pushU("bandit"); continue; }')
    A('            if (k == "demon_or_nycadaemon" ||')
    A('                k == "devil_or_mezzadaemon")')
    A("                continue;")
    A("            pushU(k);")
    A("        }")
    A("        if (got.size() != want.size() || want.size() != 47) ++bad;")
    A("        for (const auto& k : got) {")
    A("            bool hit = false;")
    A("            for (const auto& w : want)")
    A("                if (k == w) { hit = true; break; }")
    A("            if (!hit) { ++bad; break; }")
    A("        }")
    A("        for (const auto& k : want) {")
    A("            bool hit = false;")
    A("            for (const auto& g : got)")
    A("                if (k == g) { hit = true; break; }")
    A("            if (!hit) { ++bad; break; }")
    A("        }")
    A("    }")
    A('    printf("R1035 city encounter registry keys audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 7. roll: the city path, sweep + smoke -------------")
    A("    bad = 0;")
    A("    {")
    A("        rules::Rng rng(1035);")
    A("        rules::Dice dice(rng);")
    A("        int produced = 0;")
    A("        const auto companion = dm::cityEncounterKeys(reg);")
    A("        auto inCompanion = [&](const std::string& k) {")
    A("            for (const auto& c : companion)")
    A("                if (c == k) return true;")
    A("            return false;")
    A("        };")
    A("        auto isParty = [&](const std::string& k) {")
    A('            return k == "assassin" || k == "cleric" || k == "druid"')
    A('                || k == "fighter" || k == "illusionist"')
    A('                || k == "magic_user" || k == "monk"')
    A('                || k == "paladin" || k == "ranger" || k == "thief"')
    A('                || k == "rake" || k == "city_guard"')
    A('                || k == "city_official" || k == "city_watchman";')
    A("        };")
    A("        // count-path bounds (the printed numbers, code behavior)")
    A("        auto countInRange = [&](const std::string& k, int v,")
    A("                                bool night) -> bool {")
    A("            const auto* c = ereg.cityCount(k);")
    A("            if (!c) return v == 1;")
    A("            if (c->fixed >= 0) return v == c->fixed;")
    A("            int n = c->n, d = c->d, plus = c->plus;")
    A("            if (c->hasNight && night)")
    A("                { n = c->nN; d = c->dN; plus = c->plusN; }")
    A("            return v >= plus + n && v <= plus + n * d;")
    A("        };")
    A("        for (int nightI = 0; nightI < 2; ++nightI)")
    A("            for (int pct = 1; pct <= 100; ++pct) {")
    A("                const dm::CityTime t =")
    A("                    nightI ? dm::CITY_NIGHT : dm::CITY_DAY;")
    A("                const int p2 = 1 + (pct * 37) % 100;")
    A("                dm::DungeonEncounter e = dm::rollCityEncounter(")
    A("                    reg, dice, pct, p2, t);")
    A("                if (e.key.empty()) { ++bad; continue; }")
    A("                ++produced;")
    A("                if (!inCompanion(e.key)) ++bad;")
    A("                if (e.count < 1) ++bad;")
    A("                if (isParty(e.key)) {")
    A("                    if (!e.isParty) ++bad;")
    A("                    if ((int)e.party.members.size() != e.count)")
    A("                        ++bad;")
    A("                } else {")
    A("                    if (e.isParty) ++bad;")
    A("                    if (!countInRange(e.key, e.count,")
    A("                                     nightI == 1)) ++bad;")
    A("                }")
    A("            }")
    A("        // rng smoke: 4000 rolls, outcomes must be legal")
    A("        for (int i = 0; i < 4000; ++i) {")
    A("            const dm::CityTime t =")
    A("                (i % 2) ? dm::CITY_NIGHT : dm::CITY_DAY;")
    A("            dm::DungeonEncounter e = dm::rollCityEncounter(")
    A("                reg, dice, 1 + i % 100, 1 + (i * 53) % 100, t);")
    A("            if (e.key.empty()) { ++bad; continue; }")
    A("            if (!inCompanion(e.key)) ++bad;")
    A("            if (e.count < 1) ++bad;")
    A("            if (isParty(e.key) != e.isParty) ++bad;")
    A("        }")
    A("        if (produced < 180) ++bad;   // both sweeps resolve broadly")
    A("    }")
    A('    printf("R1035 city encounter registry roll audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("}")
    return "\n".join(L) + "\n"


REGTEST_OLD = """    #include "rules/audits/r1034_outdoor_encounter_registry.h"  // R1034"""
REGTEST_NEW = """    #include "rules/audits/r1034_outdoor_encounter_registry.h"  // R1034
    #include "rules/audits/r1035_city_encounter_registry.h"  // R1035"""


# ---------------------------------------------------------------------------
# 7. census + static sanity
# ---------------------------------------------------------------------------

def census_count():
    n = 0
    audit_dir = os.path.join(ROOT, "rules", "audits")
    for fn in sorted(os.listdir(audit_dir)):
        if fn.endswith(".h"):
            with open(os.path.join(audit_dir, fn)) as f:
                n += f.read().count("audit: bad %d")
    with open(REGTEST) as f:
        n += f.read().count("audit: bad %d")
    return n


def brace_balance(path):
    text = open(path).read()
    return text.count("{") - text.count("}")


def main():
    # idempotency gate
    reg_h = open(REG_H).read()
    enc = open(ENC).read()
    applied = "EncounterCityRow" in reg_h
    if applied:
        if "kCityMatrix" in enc:
            die("half-spliced state: registry extended but the city "
                "arrays still stand in dm/encounters.cpp - recover "
                "with git checkout and re-run")
        if census_count() != 969:
            die("already applied but census is %d (expected 969)"
                % census_count())
        n_lua = len([f for f in os.listdir(LUA_DIR)
                     if f.endswith(".lua")])
        if n_lua != 9:
            die("already applied but %d city lua files (expected 9)"
                % n_lua)
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    pre_census = census_count()
    if pre_census != 962:
        die("pristine census is %d (expected 962)" % pre_census)

    src = enc
    pre_lines = src.count("\n")

    # 1. parse
    start, end, matrix, flavor, c64, r146, r174 = parse_city_region(src)
    problems = gate_data(matrix, flavor)
    if problems:
        die("gate data problems: %s" % "; ".join(problems[:5]))
    flavor_sizes = [len(b) for _, b in flavor]
    print("parsed: matrix 46 rows, flavor bands %r, counts %d "
          "entries, protection 11, magic 4x3"
          % (flavor_sizes, len(COUNTS)))

    # 2. sim the roll path against the python twin
    n_keys = simulate_roll_path(matrix)
    print("roll-path sim: day/night sweeps clean, %d companion keys, "
          "count bounds within printed ranges" % n_keys)

    # 3. emit lua + round-trip
    data = {"matrix": matrix, "flavor": flavor}
    emit_lua(data)
    lua_roundtrip(data)
    print("round-trip: 9 lua files parse back byte-exact")

    # 4. registry extension
    extend_registry()

    # 5. the encounters.cpp seam
    body = city_body(c64, r146, r174)
    new = splice_encounters(src, start, end, body)
    post_lines = new.count("\n")
    for retired in ("kCityMatrix", "kDrunkKinds", "kHarlotKinds",
                    "kNobleKinds", "kSedanKinds", "kRuffianKinds",
                    "const FlavorBand*", "flavorKindFor"):
        if retired in new:
            die("retired token still present after splice: %r"
                % retired)
    with open(ENC, "w") as f:
        f.write(new)
    print("spliced dm/encounters.cpp (%d -> %d lines)"
          % (pre_lines, post_lines))

    # 6. the fragment + the regtest include
    with open(FRAG, "w") as f:
        f.write(build_fragment())
    rt = open(REGTEST).read()
    rt = replace_once(rt, REGTEST_OLD, REGTEST_NEW, "regtest include")
    with open(REGTEST, "w") as f:
        f.write(rt)
    print("regtest.cpp: R1035 fragment included")

    # 7. static sanity
    for p in (ENC, REG_H, REG_CPP, FRAG, REGTEST):
        b = brace_balance(p)
        if b != 0:
            die("brace imbalance %d in %s" % (b, p))

    # 8. census
    post_census = census_count()
    if post_census != 969:
        die("post-splice census is %d (expected 969)" % post_census)
    print("census: %d -> %d audit printf patterns"
          % (pre_census, post_census))

    print("applied 1, rewrote 4 tracked files, wrote 10 new files")
    print("SPLICE OK")


main()
