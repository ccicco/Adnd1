#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1036_splice.py  (R1036)
# The R65 astral/ethereal planar encounter de-wire, the
# R1032/R1033/R1034/R1035 shape: the retired R65 family of
# dm/encounters.cpp - the ASTRAL & ETHEREAL encounter tables
# (kAstralTable/kEtherealTable, percentile bands + the printed
# Numbers column, DMG Appendix C Premium reprint p.181), the
# seven demon/devil/titan pick-sets (kDemonMinor 6, kDemonMajor
# 10, kDevilGreater 3, kDevilLesser 4, kTitanElder/Lesser/Major
# 2 each - the R52 kPrinces/kArchDevils pools stay engine-side,
# retained verbatim above the region), and the PSYCHIC WIND /
# ETHER CYCLONE d20 band tables (p.181, day ranges printed;
# the save-vs-magic logic stays in the engine) - are extracted
# into content/tables/encounters_planar/*.lua (a sibling of
# encounters/, encounters_water/, encounters_outdoor/ and
# encounters_city/, so the R1032-R1035 file pins stay
# untouched) and load through dm::EncounterTableRegistry,
# extended here with the planar family (the two row tables,
# the pick-set lists, the two d20 band tables). The mechanics
# stay in the engine: the (*) prime-material footnote re-roll,
# the second-percentile pick-set modulo selection, the printed
# Numbers column count, the ** modified Human Subtable
# traveller party (rollPlanarTravellerParty, verbatim), the
# wind/cyclone save logic and the cord/astral fiction flags.
# rollPlanarEncounter(), planarEncounterKeys(),
# rollPsychicWind() and rollEtherCyclone() keep their
# signatures and behavior - they read registry-backed views.
# DISPATCH (the R1034 lesson): the planar family uses exact
# keys only (planar_astral / planar_ethereal / planar_picks /
# planar_wind / planar_cyclone) - no prefix, no exceptions, and
# the fragment carries negative has-pins for every side. This
# script is the only writer of the lua files and the R1036
# battery fragment; it is idempotent (run twice = "applied 0").
# ============================================================================

import glob
import hashlib
import os
import re
import sys

ROOT = os.getcwd()
ENC = os.path.join(ROOT, "dm", "encounters.cpp")
REG_H = os.path.join(ROOT, "dm", "EncounterTableRegistry.h")
REG_CPP = os.path.join(ROOT, "dm", "EncounterTableRegistry.cpp")
REGTEST = os.path.join(ROOT, "regtest.cpp")
LUA_DIR = os.path.join(ROOT, "content", "tables", "encounters_planar")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1036_planar_encounter_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory, asserted against the source at parse time
# ---------------------------------------------------------------------------

# the two row tables are PARSED from the region; these are the
# expected counts the parse must produce (the print-fidelity
# record - computed from the region, never recalled: the R1035
# m[44] lesson).
ASTRAL_ROWS = 24
ETHEREAL_ROWS = 27

# the seven local pick-sets: (C++ array, registry set key,
# expected size). The R52 kPrinces/kArchDevils pools are NOT
# here - they are retained verbatim engine-side (shared with
# the dungeon family) and stay out of the lua.
PICK_SETS = [
    ("kDemonMinor",  "demon_minor",  6),
    ("kDemonMajor",  "demon_major",  10),
    ("kDevilGreater", "devil_greater", 3),
    ("kDevilLesser", "devil_lesser", 4),
    ("kTitanElder",  "titan_elder",   2),
    ("kTitanLesser", "titan_lesser", 2),
    ("kTitanMajor",  "titan_major",   2),
]

# the PSYCHIC WIND bands (d20, p.181): (lo, hi, effect key,
# printed day range or None). The engine maps the effect key to
# the PsychicWindEffect enum and applies the save logic (storm:
# save -> days, failure -> cordBroken).
WIND = [
    (1, 12,  "slowed",       None),
    (13, 16, "lost_return",  (2, 20)),
    (17, 19, "off_course",   None),
    (20, 20, "storm",        (4, 40)),
]

# the ETHER CYCLONE bands (d20, p.181): (lo, hi, effect key,
# printed day range or None). storm_astral: days always; save
# failure -> blownToAstral.
CYCLONE = [
    (1, 10,  "blown_about",     None),
    (11, 15, "different_plane", None),
    (16, 18, "lost_new_plane",  (5, 60)),
    (19, 20, "storm_astral",    (10, 120)),
]

# every source substring the retired code must still carry (the
# parse-time tie between this inventory and the C++ record)
ASSERTS = [
    'static const PlanarRow kAstralTable[] = {',
    'static const PlanarRow kEtherealTable[] = {',
    'static const char* const kDemonMinor[] = {',
    'static const char* const kDemonMajor[] = {',
    'static const char* const kDevilGreater[] = {',
    'static const char* const kDevilLesser[] = {',
    'static const char* const kTitanElder[]',
    'static const char* const kTitanLesser[]',
    'static const char* const kTitanMajor[]',
    'static CharacterParty rollPlanarTravellerParty(rules::Dice& dice) {',
    'DungeonEncounter rollPlanarEncounter(',
    'std::vector<std::string> planarEncounterKeys(',
    'PsychicWindResult rollPsychicWind(rules::Dice& dice, int d20,',
    'EtherCycloneResult rollEtherCyclone(rules::Dice& dice, int d20,',
    '(row->flags & PF_PRIME_ONLY) && !primeAdjacent',
    'kDemonMinor[pctile2 % 6]',
    'kDemonMajor[pctile2 % 10]',
    'kPrinces[pctile2 % 4]',
    'kArchDevils[pctile2 % 4]',
    'kDevilGreater[pctile2 % 3]',
    'kDevilLesser[pctile2 % 4]',
    'kTitanElder[pctile2 % 2]',
    'kTitanLesser[pctile2 % 2]',
    'kTitanMajor[pctile2 % 2]',
    'attempt < 24',
    'dice.roll(1, 6, 0)',
    'dice.roll(1, 19, 0)',
    'dice.roll(1, 37, 0)',
    'dice.roll(1, 56, 0)',
    'dice.roll(1, 111, 0)',
    'if (d20 <= 12)',
    'if (d20 <= 16)',
    'if (d20 <= 19)',
    'if (d20 <= 10)',
    'if (d20 <= 15)',
    'if (d20 <= 18)',
    'e.key = "planar_traveller_party"',
    'PLANAR_TRAVELLER',
    'PF_PRIME_ONLY',
]


def die(msg):
    sys.stderr.write("r1036_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the retired region out of dm/encounters.cpp
# ---------------------------------------------------------------------------

REGION_START = "// R65: the ASTRAL & ETHEREAL encounter tables"
REGION_END = "// R66: the PSIONIC ENCOUNTER TABLE"
SEP = "// ----------------------------------------------------------------------------"


def parse_planar_region(src):
    if "kAstralTable" not in src:
        die("kAstralTable not found (already spliced?)")
    i0 = src.index(REGION_START)
    i0 = src.rindex(SEP, 0, i0)
    i1 = src.index(REGION_END)
    i1 = src.rindex(SEP, i0, i1)
    region = src[i0:i1]

    for a in ASSERTS:
        if a not in region:
            die("assertion failed, the retired region must carry %r" % a)

    # the two row tables: (lo, hi, key, nMin, nMax, primeOnly)
    def parse_table(name, want):
        m = re.search(r"static const PlanarRow " + re.escape(name)
                      + r"\[\] = \{(.*?)\};", region, re.S)
        if not m:
            die("%s array not found" % name)
        rows = re.findall(
            r"\{(\d+),\s*(\d+),\s*\"([A-Za-z_0-9]+)\","
            r"\s*(\d+),\s*(\d+)(\s*\|\s*PF_PRIME_ONLY)?\s*\}",
            m.group(1))
        if len(rows) != want:
            die("parsed %d %s rows (expected %d)"
                % (len(rows), name, want))
        return [(int(a), int(b), k, int(c), int(d),
                 bool(f)) for a, b, k, c, d, f in rows]

    astral = parse_table("kAstralTable", ASTRAL_ROWS)
    ethereal = parse_table("kEtherealTable", ETHEREAL_ROWS)

    # the pick-sets
    picks = []
    for arr, set_key, want in PICK_SETS:
        m = re.search(r"static const char\* const " + re.escape(arr)
                      + r"\[\]\s*=\s*\{(.*?)\};", region, re.S)
        if not m:
            die("%s array not found" % arr)
        vals = re.findall(r'"([a-z_0-9]+)"', m.group(1))
        if len(vals) != want:
            die("parsed %d %s members (expected %d)"
                % (len(vals), arr, want))
        if len(set(vals)) != want:
            die("%s carries duplicate members" % arr)
        picks.append((set_key, vals))

    # the two verbatim comment blocks + the traveller function
    # (provenance and mechanics, kept in the seam)
    c65 = region[:region.index("namespace {")].rstrip() + "\n"
    tv = region[region.index("// R65: the ** modified Human Subtable"):]
    tv = tv[:tv.index("DungeonEncounter rollPlanarEncounter")]
    tv = tv.rstrip() + "\n"
    wind_hdr = region[region.index("// R65: PSYCHIC WIND"):]
    wind_hdr = wind_hdr[:wind_hdr.index(
        "PsychicWindResult rollPsychicWind")].rstrip() + "\n"

    return i0, i1, astral, ethereal, picks, c65, tv, wind_hdr


# ---------------------------------------------------------------------------
# 2. gate data: everything the sim and the fragment pin
# ---------------------------------------------------------------------------

# pseudo-key -> (set key or None for the retained engine pools,
# modulo count, member list or None)
def pick_map(picks):
    pm = {}
    for set_key, vals in picks:
        pm[set_key] = vals
    return pm


PRINCES = ["demogorgon", "juiblex", "orcus", "yeenoghu"]
ARCH_DEVILS = ["asmodeus", "baalzebul", "dispater", "geryon"]


def gate_data(astral, ethereal, picks):
    problems = []
    for name, table in (("astral", astral), ("ethereal", ethereal)):
        prev = 0
        for lo, hi, key, nMin, nMax, prime in table:
            if lo != prev + 1 or hi < lo or hi > 100:
                problems.append("%s band %r at %s"
                                % (name, (lo, hi), key))
            if nMin < 0 or nMax < nMin or nMax > 100:
                problems.append("%s numbers %r at %s"
                                % (name, (nMin, nMax), key))
            prev = hi
        if prev != 100:
            problems.append("%s chain ends at %d" % (name, prev))
    for name, bands, top in (("wind", WIND, 20), ("cyclone", CYCLONE, 20)):
        prev = 0
        for lo, hi, eff, days in bands:
            if lo != prev + 1 or hi < lo or hi > top:
                problems.append("%s band %r" % (name, (lo, hi)))
            if days is not None and (days[0] < 1
                                      or days[1] < days[0]):
                problems.append("%s days %r" % (name, days))
            prev = hi
        if prev != top:
            problems.append("%s chain ends at %d" % (name, prev))
    for set_key, vals in picks:
        if len(vals) < 2:
            problems.append("%s set smaller than a modulo pick" % set_key)
    return problems


# the python twin of the planarEncounterKeys expansion (the
# reg.find gate is modeled as "every plain key present": the
# battery's real registry gates the same way)
def expected_keys(table, picks):
    pm = pick_map(picks)
    out = []
    def push(k):
        if k not in out:
            out.append(k)
    for lo, hi, key, nMin, nMax, prime in table:
        if key == "PLANAR_DEMON_MINOR":
            for v in pm["demon_minor"]: push(v)
        elif key == "PLANAR_DEMON_MAJOR":
            for v in pm["demon_major"]: push(v)
        elif key == "PLANAR_DEMON_PRINCE":
            for v in PRINCES: push(v)
        elif key == "PLANAR_DEVIL_ARCH":
            for v in ARCH_DEVILS: push(v)
        elif key == "PLANAR_DEVIL_GREATER":
            for v in pm["devil_greater"]: push(v)
        elif key == "PLANAR_DEVIL_LESSER":
            for v in pm["devil_lesser"]: push(v)
        elif key == "PLANAR_TITAN_ELDER":
            for v in pm["titan_elder"]: push(v)
        elif key == "PLANAR_TITAN_LESSER":
            for v in pm["titan_lesser"]: push(v)
        elif key == "PLANAR_TITAN_MAJOR":
            for v in pm["titan_major"]: push(v)
        elif key == "PLANAR_TRAVELLER":
            push("planar_traveller_party")
        else:
            push(key)
    return out


def simulate_roll_path(astral, ethereal, picks):
    keys_a = expected_keys(astral, picks)
    keys_e = expected_keys(ethereal, picks)
    if len(keys_a) != 52:
        die("astral companion computed %d (expected 52)" % len(keys_a))
    if len(keys_e) != 27:
        die("ethereal companion computed %d (expected 27)"
            % len(keys_e))
    for name, table, keys in (("astral", astral, keys_a),
                              ("ethereal", ethereal, keys_e)):
        for prime in (False, True):
            for pct in range(1, 101):
                row = None
                for lo, hi, key, nMin, nMax, p in table:
                    if pct >= lo and pct <= hi:
                        row = (key, p)
                        break
                if row is None:
                    die("no %s row for pctile %d" % (name, pct))
                if row[1] and not prime:
                    continue   # the (*) footnote re-roll
                if row[0] == "PLANAR_TRAVELLER":
                    continue   # party path
                # expand the pseudo-key through the pick-sets /
                # engine pools, then check every member
                expanded = expected_keys([(0, 0, row[0],
                                           0, 0, False)], picks)
                if not expanded:
                    die("%s key %r expanded to nothing"
                        % (name, row[0]))
                for k in expanded:
                    if k not in keys:
                        die("%s key %r not in companion"
                            % (name, k))
    # the pseudo-keys never leak into the companion
    for k in keys_a + keys_e:
        if k.startswith("PLANAR_"):
            die("pseudo-key %r leaked into the companion" % k)
    return len(keys_a), len(keys_e)


# ---------------------------------------------------------------------------
# 3. lua emission + round-trip
# ---------------------------------------------------------------------------

LUA_HDR = """-- encounter table def: %(key)s
-- The R65 planar family (R1036 de-wire): %(what)s
-- (DMG Appendix C Premium reprint p.181, OCR-verified).
-- %(note)s
-- DO NOT hand-edit: tools/r1036_splice.py is the only writer.

"""


def rows_lua_text(name, what, note, table):
    out = [LUA_HDR % dict(key=name, what=what, note=note)]
    out.append("return {\n")
    out.append('  key = "%s",\n' % name)
    out.append("  rows = {\n")
    for lo, hi, key, nMin, nMax, prime in table:
        out.append('    { band = {%d,%d}, key = "%s", '
                   'numbers = {%d,%d}, primeOnly = %s },\n'
                   % (lo, hi, key, nMin, nMax,
                      "true" if prime else "false"))
    out.append("  },\n}\n")
    return "".join(out)


def picks_lua_text(picks):
    out = [LUA_HDR % dict(
        key="planar_picks",
        what="the seven demon/devil/titan pick-sets",
        note="extracted verbatim from the retired arrays of "
             "dm/encounters.cpp; a set resolves on the second "
             "percentile modulo the set size (the R52 style). "
             "The demon-prince and arch-devil pools stay "
             "engine-side (the R52 record, shared with the "
             "dungeon family).")]
    out.append("return {\n")
    out.append('  key = "planar_picks",\n')
    for set_key, vals in picks:
        out.append('  %s = { "%s" },\n' % (set_key, '", "'.join(vals)))
    out.append("}\n")
    return "".join(out)


def bands_lua_text(name, what, note, bands):
    out = [LUA_HDR % dict(key=name, what=what, note=note)]
    out.append("return {\n")
    out.append('  key = "%s",\n' % name)
    out.append("  rows = {\n")
    for lo, hi, eff, days in bands:
        d = "{%d,%d}" % days if days else "{-1,-1}"
        out.append('    { band = {%d,%d}, effect = "%s", '
                   'days = %s },\n' % (lo, hi, eff, d))
    out.append("  },\n}\n")
    return "".join(out)


LUA_FILES = {
    "planar_astral.lua": None,     # filled in emit_lua (data order)
    "planar_ethereal.lua": None,
    "planar_picks.lua": None,
    "planar_wind.lua": None,
    "planar_cyclone.lua": None,
}


def emit_lua(data):
    os.makedirs(LUA_DIR, exist_ok=True)
    texts = {
        "planar_astral.lua": rows_lua_text(
            "planar_astral", "the ASTRAL encounter table",
            "band = the percentile column; key = the bestiary "
            "key or the printed pseudo-key (the PLANAR_* rows "
            "resolve through the pick-sets); numbers = the "
            "printed Numbers column (uniform lo..hi; 0,0 marks "
            "the traveller, which builds a party instead); "
            "primeOnly = the (*) footnote: prime-material "
            "perception creatures appear only when the "
            "encounter allows effect to extend from the Prime "
            "Material Plane - the caller re-rolls otherwise.",
            data["astral"]),
        "planar_ethereal.lua": rows_lua_text(
            "planar_ethereal", "the ETHEREAL encounter table",
            "band = the percentile column; key = the bestiary "
            "key or the printed pseudo-key (the PLANAR_* rows "
            "resolve through the pick-sets); numbers = the "
            "printed Numbers column (uniform lo..hi; 0,0 marks "
            "the traveller, which builds a party instead); "
            "primeOnly = the (*) footnote: prime-material "
            "perception creatures appear only when the "
            "encounter allows effect to extend from the Prime "
            "Material Plane - the caller re-rolls otherwise.",
            data["ethereal"]),
        "planar_picks.lua": picks_lua_text(data["picks"]),
        "planar_wind.lua": bands_lua_text(
            "planar_wind", "the PSYCHIC WIND d20 table",
            "band = the d20 roll; effect = the printed result "
            "(the engine maps it to the wind enum); days = the "
            "printed day range, -1,-1 when the result prints "
            "none. The saving throw versus magic (a storm save "
            "failure snaps the silver cord) is the caller's, "
            "passed in as saveMade - the engine's logic.",
            WIND),
        "planar_cyclone.lua": bands_lua_text(
            "planar_cyclone", "the ETHER CYCLONE d20 table",
            "band = the d20 roll; effect = the printed result "
            "(the engine maps it to the cyclone enum); days = "
            "the printed day range, -1,-1 when the result "
            "prints none. A storm save failure blows the "
            "traveller to the astral plane - the engine's "
            "logic, saveMade passed in by the caller.",
            CYCLONE),
    }
    for name in sorted(texts):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(texts[name])


def lua_roundtrip(data):
    """parse the emitted lua back and prove byte-exact equality"""
    for name, table in (("planar_astral.lua", data["astral"]),
                        ("planar_ethereal.lua", data["ethereal"])):
        t = open(os.path.join(LUA_DIR, name)).read()
        got = [(int(a), int(b), k, int(c), int(d), f == "true")
               for a, b, k, c, d, f in re.findall(
            r'\{ band = \{(\d+),(\d+)\}, key = "([A-Za-z_0-9]+)", '
            r'numbers = \{(\d+),(\d+)\}, primeOnly = '
            r'(true|false) \}', t)]
        if got != table:
            die("round-trip: %s mismatch" % name)
    t = open(os.path.join(LUA_DIR, "planar_picks.lua")).read()
    got = []
    for set_key, want in data["picks"]:
        m = re.search(re.escape(set_key)
                      + r' = \{ (.*?) \},\n', t)
        if not m:
            die("round-trip: %s set missing" % set_key)
        vals = re.findall(r'"([a-z_0-9]+)"', m.group(1))
        if vals != want:
            die("round-trip: %s set mismatch" % set_key)
        got.append((set_key, vals))
    if got != data["picks"]:
        die("round-trip: planar_picks mismatch")
    for name, bands in (("planar_wind.lua", WIND),
                        ("planar_cyclone.lua", CYCLONE)):
        t = open(os.path.join(LUA_DIR, name)).read()
        got = []
        for a, b, eff, d1, d2 in re.findall(
            r'\{ band = \{(\d+),(\d+)\}, effect = "([a-z_]+)", '
            r'days = \{(-?\d+),(-?\d+)\} \}', t):
            days = (int(d1), int(d2)) if int(d1) >= 1 else None
            got.append((int(a), int(b), eff, days))
        if got != bands:
            die("round-trip: %s mismatch" % name)


# ---------------------------------------------------------------------------
# 4. the registry extension (dm/EncounterTableRegistry.h / .cpp)
# ---------------------------------------------------------------------------

def replace_once(text, old, new, where):
    n = text.count(old)
    if n != 1:
        die("%s: anchor appears %d times (expected 1)"
            % (where, n))
    return text.replace(old, new, 1)


H_COMMENT_OLD = """// tools/r1032_splice.py (dungeon family),
// tools/r1033_splice.py (water family),
// tools/r1034_splice.py (outdoor family) and
// tools/r1035_splice.py (city family) are the only writers."""
H_COMMENT_NEW = """// tools/r1032_splice.py (dungeon family),
// tools/r1033_splice.py (water family),
// tools/r1034_splice.py (outdoor family),
// tools/r1035_splice.py (city family) and
// tools/r1036_splice.py (planar family) are the only writers."""

H_STRUCT_ANCHOR = """// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""
H_STRUCT_ADD = """// R1036: the planar family. One row carries the percentile
// band, the bestiary key or the printed pseudo-key (the
// PLANAR_* rows resolve through the pick-set lists), the
// printed Numbers column (uniform lo..hi; 0,0 = the traveller
// party) and the (*) prime-material footnote flag. The
// wind/cyclone band rows carry the d20 band, the printed
// effect key and the printed day range (-1 = no printed days).
struct EncounterPlanarRow {
    std::string key;
    int lo = 0, hi = 0;
    int nMin = 0, nMax = 0;
    bool primeOnly = false;
};
struct EncounterPlanarBand {
    int lo = 0, hi = 0;
    std::string effect;
    int dMin = -1, dMax = -1;    // -1: no printed days
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""

H_GETTER_ANCHOR = """    const std::vector<std::string>& list(const std::string& set) const;"""
H_GETTER_ADD = """    const std::vector<std::string>& list(const std::string& set) const;
    // R1036: the planar family views. planarRows/planarBands
    // return an empty vector for an absent table (the callers'
    // defensive paths re-roll).
    bool hasPlanar(const std::string& name) const;
    const std::vector<EncounterPlanarRow>& planarRows(
        const std::string& name) const;
    bool hasPlanarBands(const std::string& name) const;
    const std::vector<EncounterPlanarBand>& planarBands(
        const std::string& name) const;"""

H_MEMBER_ANCHOR = """    std::vector<EncounterCityMagic> m_cityMagic;"""
H_MEMBER_ADD = """    std::vector<EncounterCityMagic> m_cityMagic;
    // R1036: the planar family (the two row tables and the two
    // d20 band tables; the pick-sets ride m_lists above).
    std::map<std::string, std::vector<EncounterPlanarRow>> m_planar;
    std::map<std::string, std::vector<EncounterPlanarBand>>
        m_planarBands;"""

CPP_KEYS_ANCHOR = """const char* const kCityBandKeys[]  = { "band", "kind", nullptr };"""
CPP_KEYS_ADD = """const char* const kCityBandKeys[]  = { "band", "kind", nullptr };
// R1036: the planar family file/row keys. Exact keys only -
// no prefix, no exceptions (the R1034 dispatch-order lesson).
const char* const kPlanarFileKeys[]  = { "key", "rows", nullptr };
const char* const kPlanarRowKeys[]   =
    { "band", "key", "numbers", "primeOnly", nullptr };
const char* const kPlanarPickKeys[] =
    { "key", "demon_minor", "demon_major", "devil_greater",
      "devil_lesser", "titan_elder", "titan_lesser",
      "titan_major", nullptr };
const char* const kPlanarBandFileKeys[] = { "key", "rows", nullptr };
const char* const kPlanarBandKeys[] =
    { "band", "effect", "days", nullptr };
const char* const kWindEffects[] =
    { "slowed", "lost_return", "off_course", "storm", nullptr };
const char* const kCycloneEffects[] =
    { "blown_about", "different_plane", "lost_new_plane",
      "storm_astral", nullptr };"""

CPP_BRANCH_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""
CPP_BRANCH_ADD = """    } else if (key == "planar_astral"
               || key == "planar_ethereal") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kPlanarFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterPlanarRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)
                    || !checkAllowedKeys(L, rt, kPlanarRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err)) {
                    if (lua_istable(L, rt))
                        lua_pop(L, 1);
                    goto bad;
                }
                EncounterPlanarRow row;
                lua_getfield(L, rt, "band");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 2) {
                    err = "band must be a {lo, hi} pair";
                    lua_pop(L, 1);
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
                if (v[0] < 1 || v[0] > 100
                    || v[1] < v[0] || v[1] > 100) {
                    err = "band outside 01-00";
                    goto bad;
                }
                row.lo = (int)v[0]; row.hi = (int)v[1];
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                lua_getfield(L, rt, "numbers");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 2) {
                    err = "numbers must be {nMin, nMax}";
                    lua_pop(L, 1);
                    goto bad;
                }
                for (int j = 0; j < 2; ++j) {
                    lua_rawgeti(L, -1, j + 1);
                    if (!lua_isinteger(L, -1)) {
                        err = "numbers field is not an integer";
                        goto bad;
                    }
                    v[j] = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                if (v[0] < 0 || v[1] < v[0] || v[1] > 100) {
                    err = "numbers outside 0-100";
                    goto bad;
                }
                row.nMin = (int)v[0]; row.nMax = (int)v[1];
                lua_getfield(L, rt, "primeOnly");
                if (!lua_isboolean(L, -1)) {
                    err = "primeOnly is not a boolean";
                    lua_pop(L, 1);
                    goto bad;
                }
                row.primeOnly = lua_toboolean(L, -1) != 0;
                lua_pop(L, 1);
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_planar.count(key)) { err = "duplicate def key";
                                       goto bad; }
            m_planar[key] = rows;
        }
    } else if (key == "planar_picks") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kPlanarPickKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "planar_picks") { err = "def key mismatch";
                                       goto bad; }
        }
        {
            static const char* const names[7] = { "demon_minor",
                "demon_major", "devil_greater", "devil_lesser",
                "titan_elder", "titan_lesser", "titan_major" };
            for (int i = 0; i < 7; ++i) {
                lua_getfield(L, t, names[i]);
                if (!lua_istable(L, -1)) {
                    err = std::string("'") + names[i]
                        + "' is not a table";
                    goto bad;
                }
                const int cnt = (int)lua_rawlen(L, -1);
                if (cnt < 2) {
                    err = std::string("'") + names[i]
                        + "' must carry at least two keys";
                    goto bad;
                }
                std::vector<std::string> vals;
                for (int j = 1; j <= cnt; ++j) {
                    lua_rawgeti(L, -1, j);
                    if (!lua_isstring(L, -1)) {
                        err = std::string("'") + names[i]
                            + "' element is not a string";
                        goto bad;
                    }
                    size_t len = 0;
                    const char* s = lua_tolstring(L, -1, &len);
                    vals.push_back(std::string(s, len));
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                const std::string setKey =
                    std::string(names[i]) + "_set";
                if (m_lists.count(setKey)) {
                    err = "duplicate def key";
                    goto bad;
                }
                m_lists[setKey] = vals;
            }
        }
    } else if (key == "planar_wind" || key == "planar_cyclone") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kPlanarBandFileKeys, key, &err))
            goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const char* const* effects = key == "planar_wind"
                ? kWindEffects : kCycloneEffects;
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterPlanarBand> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)
                    || !checkAllowedKeys(L, rt, kPlanarBandKeys,
                        key + " rows[" + std::to_string(i) + "]", &err)) {
                    if (lua_istable(L, rt))
                        lua_pop(L, 1);
                    goto bad;
                }
                EncounterPlanarBand row;
                lua_getfield(L, rt, "band");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 2) {
                    err = "band must be a {lo, hi} pair";
                    lua_pop(L, 1);
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
                if (v[0] < 1 || v[0] > 20
                    || v[1] < v[0] || v[1] > 20) {
                    err = "band outside the d20 range";
                    goto bad;
                }
                row.lo = (int)v[0]; row.hi = (int)v[1];
                lua_getfield(L, rt, "effect");
                if (!lua_isstring(L, -1)) {
                    err = "effect is not a string";
                    lua_pop(L, 1);
                    goto bad;
                }
                size_t len = 0;
                const char* s = lua_tolstring(L, -1, &len);
                row.effect = std::string(s, len);
                lua_pop(L, 1);
                bool okEff = false;
                for (int e = 0; effects[e]; ++e)
                    if (row.effect == effects[e])
                        { okEff = true; break; }
                if (!okEff) {
                    err = "unknown effect '" + row.effect + "'";
                    goto bad;
                }
                lua_getfield(L, rt, "days");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 2) {
                    err = "days must be a {lo, hi} pair";
                    lua_pop(L, 1);
                    goto bad;
                }
                for (int j = 0; j < 2; ++j) {
                    lua_rawgeti(L, -1, j + 1);
                    if (!lua_isinteger(L, -1)) {
                        err = "days pair field is not an integer";
                        goto bad;
                    }
                    v[j] = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                }
                lua_pop(L, 1);
                const bool none = v[0] == -1 && v[1] == -1;
                if (!none && (v[0] < 1 || v[1] < v[0]
                              || v[1] > 200)) {
                    err = "days outside 1-200 or {-1,-1}";
                    goto bad;
                }
                row.dMin = (int)v[0]; row.dMax = (int)v[1];
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_planarBands.count(key)) { err = "duplicate def key";
                                            goto bad; }
            m_planarBands[key] = rows;
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_GETTER_ANCHOR = """const std::vector<EncounterCityMagic>&
EncounterTableRegistry::cityMagic() const {
    return m_cityMagic;
}"""
CPP_GETTER_ADD = """const std::vector<EncounterCityMagic>&
EncounterTableRegistry::cityMagic() const {
    return m_cityMagic;
}

bool EncounterTableRegistry::hasPlanar(
    const std::string& name) const {
    return m_planar.count(name) != 0;
}

const std::vector<EncounterPlanarRow>&
EncounterTableRegistry::planarRows(
    const std::string& name) const {
    static const std::vector<EncounterPlanarRow> none;
    auto it = m_planar.find(name);
    return it == m_planar.end() ? none : it->second;
}

bool EncounterTableRegistry::hasPlanarBands(
    const std::string& name) const {
    return m_planarBands.count(name) != 0;
}

const std::vector<EncounterPlanarBand>&
EncounterTableRegistry::planarBands(
    const std::string& name) const {
    static const std::vector<EncounterPlanarBand> none;
    auto it = m_planarBands.find(name);
    return it == m_planarBands.end() ? none : it->second;
}"""


def extend_registry():
    h = open(REG_H).read()
    h = replace_once(h, H_COMMENT_OLD, H_COMMENT_NEW, "registry h comment")
    h = replace_once(h, H_STRUCT_ANCHOR, H_STRUCT_ADD, "registry h structs")
    h = replace_once(h, H_GETTER_ANCHOR, H_GETTER_ADD, "registry h getters")
    h = replace_once(h, H_MEMBER_ANCHOR, H_MEMBER_ADD, "registry h members")
    with open(REG_H, "w") as f:
        f.write(h)

    c = open(REG_CPP).read()
    c = replace_once(c, CPP_KEYS_ANCHOR, CPP_KEYS_ADD, "registry cpp keys")
    c = replace_once(c, CPP_BRANCH_ANCHOR, CPP_BRANCH_ADD,
                    "registry cpp dispatch")
    c = replace_once(c, CPP_GETTER_ANCHOR, CPP_GETTER_ADD,
                     "registry cpp getters")
    with open(REG_CPP, "w") as f:
        f.write(c)


# ---------------------------------------------------------------------------
# 5. the encounters.cpp seam (registry-backed views, mechanics
#    kept verbatim)
# ---------------------------------------------------------------------------

SEAM_NOTE = """
// R1036 (the registry-native de-wire, the R1032-R1035 shape):
// the astral/ethereal rows retired into content/tables/
// encounters_planar/planar_astral.lua and planar_ethereal.lua
// (band = the percentile, key = the bestiary key or the printed
// pseudo-key, numbers = the printed Numbers column, primeOnly
// = the (*) footnote); the seven demon/devil/titan pick-sets
// into planar_picks.lua (the demon-prince and arch-devil pools
// stay engine-side, retained verbatim above); the psychic wind
// and ether cyclone d20 bands into planar_wind.lua and
// planar_cyclone.lua. The registry loads the directory (encReg()
// above). What stays here is the mechanics: the (*) footnote
// re-roll, the second-percentile pick-set modulo selection, the
// printed Numbers column count, the ** modified Human Subtable
// traveller party (verbatim below), and the wind/cyclone save
// logic (a storm save failure snaps the cord / blows the
// traveller to the astral plane). Signatures and behavior are
// unchanged - the views are registry-backed. The R66 psionic
// table's (*) demon/devil rows resolved through the retired
// arrays below; they are rewired to the same planarSetView
// (mechanics unchanged, modulo the pinned set sizes).

namespace {

// the registry-backed static caches (the R1032-R1035 idiom)
static const std::vector<dm::EncounterPlanarRow>& planarView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterPlanarRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, dm::encReg().planarRows(name)).first;
    return it->second;
}

static const std::vector<dm::EncounterPlanarBand>& planarBandView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterPlanarBand>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, dm::encReg().planarBands(name)).first;
    return it->second;
}

// the seven pick-sets (planar_picks.lua -> the registry lists)
static const std::vector<std::string>& planarSetView(
        const char* set) {
    static const char* const kNames[7] = {
        "demon_minor", "demon_major", "devil_greater",
        "devil_lesser", "titan_elder", "titan_lesser",
        "titan_major" };
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* s : kNames)
            m[std::string(s) + "_set"] =
                dm::encReg().list(std::string(s) + "_set");
    }
    static const std::vector<std::string> none;
    auto it = m.find(set);
    return it == m.end() ? none : it->second;
}

} // namespace
"""

ROLL_FN = """
DungeonEncounter rollPlanarEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        PlanarBody body, bool primeAdjacent) {
    DungeonEncounter e;

    const char* tableName =
        body == PB_ASTRAL ? "planar_astral" : "planar_ethereal";
    const std::vector<dm::EncounterPlanarRow>& t =
        planarView(tableName);

    for (int attempt = 0; attempt < 24; ++attempt) {
        const dm::EncounterPlanarRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi)
                { row = &r; break; }
        if (!row) return e;   // defensive: columns cover 01-00

        // * footnote: prime-material perception creatures
        // "otherwise, ignore the encounter result and roll
        // again"
        if (row->primeOnly && !primeAdjacent) {
            pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
            pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
            continue;
        }

        auto pick = [&](const char* set) -> std::string {
            const auto& v = planarSetView(set);
            return v.empty() ? std::string()
                             : v[pctile2 % (int)v.size()];
        };
        std::string key = row->key;
        if      (key == "PLANAR_DEMON_MINOR")
            key = pick("demon_minor_set");
        else if (key == "PLANAR_DEMON_MAJOR")
            key = pick("demon_major_set");
        else if (key == "PLANAR_DEMON_PRINCE")
            key = kPrinces[pctile2 % 4];
        else if (key == "PLANAR_DEVIL_ARCH")
            key = kArchDevils[pctile2 % 4];
        else if (key == "PLANAR_DEVIL_GREATER")
            key = pick("devil_greater_set");
        else if (key == "PLANAR_DEVIL_LESSER")
            key = pick("devil_lesser_set");
        else if (key == "PLANAR_TITAN_ELDER")
            key = pick("titan_elder_set");
        else if (key == "PLANAR_TITAN_LESSER")
            key = pick("titan_lesser_set");
        else if (key == "PLANAR_TITAN_MAJOR")
            key = pick("titan_major_set");
        if (key.empty()) return e;   // a missing set file

        if (key == "PLANAR_TRAVELLER") {
            // ** modified Human Subtable party
            e.party = rollPlanarTravellerParty(dice);
            e.isParty = true;
            e.key = "planar_traveller_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            // printed Numbers column (uniform lo..hi; single
            // results skip the roll)
            e.count = (row->nMin == row->nMax)
                ? row->nMin
                : row->nMin + (int)dice.roll(
                      1, (uint32_t)(row->nMax - row->nMin + 1), 0) - 1;
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

// Every result key the table can produce - the regtest-style
// companion of rollPlanarEncounter. Footnote (*) creatures
// appear only when the encounter allows prime-material
// effect; they are listed regardless (R60 precedent) and the
// caller gates on primeAdjacent.
std::vector<std::string> planarEncounterKeys(
        const monsters::MonsterRegistry& reg, PlanarBody body) {
    std::vector<std::string> out;
    const char* tableName =
        body == PB_ASTRAL ? "planar_astral" : "planar_ethereal";
    for (const auto& r : planarView(tableName)) {
        const std::string key = r.key;
        if      (key == "PLANAR_DEMON_MINOR")
            for (const auto& k : planarSetView("demon_minor_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_DEMON_MAJOR")
            for (const auto& k : planarSetView("demon_major_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_DEMON_PRINCE")
            for (const char* k : kPrinces) pushUnique(out, k);
        else if (key == "PLANAR_DEVIL_ARCH")
            for (const char* k : kArchDevils) pushUnique(out, k);
        else if (key == "PLANAR_DEVIL_GREATER")
            for (const auto& k : planarSetView("devil_greater_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_DEVIL_LESSER")
            for (const auto& k : planarSetView("devil_lesser_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_TITAN_ELDER")
            for (const auto& k : planarSetView("titan_elder_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_TITAN_LESSER")
            for (const auto& k : planarSetView("titan_lesser_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_TITAN_MAJOR")
            for (const auto& k : planarSetView("titan_major_set"))
                pushUnique(out, k.c_str());
        else if (key == "PLANAR_TRAVELLER")
            pushUnique(out, "planar_traveller_party");
        else if (reg.find(key))
            pushUnique(out, key.c_str());
    }
    return out;
}
"""

EFFECT_FNS = """namespace {

// the band effect key -> the engine enum (the enum is the
// engine's contract; the band table is the data)
PsychicWindEffect windEffectFor(const std::string& e) {
    if (e == "slowed") return PsychicWindEffect::Slowed;
    if (e == "lost_return") return PsychicWindEffect::LostReturn;
    if (e == "off_course") return PsychicWindEffect::OffCourse;
    return PsychicWindEffect::Storm;   // validated at load
}

EtherCycloneEffect cycloneEffectFor(const std::string& e) {
    if (e == "blown_about")
        return EtherCycloneEffect::BlownAbout;
    if (e == "different_plane")
        return EtherCycloneEffect::DifferentPlane;
    if (e == "lost_new_plane")
        return EtherCycloneEffect::LostNewPlane;
    return EtherCycloneEffect::StormAstral;   // validated at load
}

} // namespace

PsychicWindResult rollPsychicWind(rules::Dice& dice, int d20,
                                  bool saveMade) {
    // {} value-init: the result struct carries no default
    // members, and the retired code left untraveled fields
    // (days/cordBroken off their paths) indeterminate - the
    // parity audit requires deterministic untouched fields
    PsychicWindResult r{};
    for (const auto& b : planarBandView("planar_wind")) {
        if (d20 < b.lo || d20 > b.hi) continue;
        r.effect = windEffectFor(b.effect);
        // uniform over the printed day range (the retired
        // expressions produced the same spread); a storm save
        // failure snaps the cord instead of costing days
        if (b.dMin >= 1
            && (r.effect != PsychicWindEffect::Storm || saveMade))
            r.days = b.dMin + (int)dice.roll(
                1, (uint32_t)(b.dMax - b.dMin + 1), 0) - 1;
        if (r.effect == PsychicWindEffect::Storm && !saveMade)
            r.cordBroken = true;
        // no-cord projection: lost AND different destination
        // (p.181 note) - the caller reads cordBroken plus
        // OffCourse semantics; fiction, documented
        return r;
    }
    return r;   // defensive: the bands cover 1-20
}


EtherCycloneResult rollEtherCyclone(rules::Dice& dice, int d20,
                                    bool saveMade) {
    // {} value-init: same as the wind roll above
    EtherCycloneResult r{};
    for (const auto& b : planarBandView("planar_cyclone")) {
        if (d20 < b.lo || d20 > b.hi) continue;
        r.effect = cycloneEffectFor(b.effect);
        // uniform over the printed day range (the retired
        // expressions produced the same spread)
        if (b.dMin >= 1)
            r.days = b.dMin + (int)dice.roll(
                1, (uint32_t)(b.dMax - b.dMin + 1), 0) - 1;
        if (r.effect == EtherCycloneEffect::StormAstral)
            r.blownToAstral = !saveMade;   // save: random
                                           // ether-touched plane
        return r;
    }
    return r;   // defensive: the bands cover 1-20
}
"""

ENC_LOAD_ANCHOR = '        reg.loadDirectory("content/tables/encounters_city");'
ENC_LOAD_ADD = ('        reg.loadDirectory("content/tables/encounters_city");\n'
                '        reg.loadDirectory("content/tables/encounters_planar");')

# the R66 PSIONIC table's (*) rows resolved through the retired
# pick arrays; rewired to the registry-backed views (the
# seam defines planarSetView above the R66 region). Roll
# sites: the guard mirrors the ROLL_FN pick lambda (an empty
# set leaves the pseudo-key; the ignore-&-reroll loop
# handles it). The companion loops iterate the view.
R66_ROLL_REWIRES = [
    ("key = kDemonMajor[pctile2 % 10];",
     "{\n            const auto& v =\n"
                "                planarSetView(\"demon_major_set\");\n"
                "            if (!v.empty())\n"
                "                key = v[pctile2 % (int)v.size()];\n"
                "        }"),
    ("key = kDemonMinor[pctile2 % 6];",
     "{\n            const auto& v =\n"
                "                planarSetView(\"demon_minor_set\");\n"
                "            if (!v.empty())\n"
                "                key = v[pctile2 % (int)v.size()];\n"
                "        }"),
    ("key = kDevilGreater[pctile2 % 3];",
     "{\n            const auto& v =\n"
                "                planarSetView(\"devil_greater_set\");\n"
                "            if (!v.empty())\n"
                "                key = v[pctile2 % (int)v.size()];\n"
                "        }"),
]
R66_KEYS_REWIRES = [
    ("            for (const char* k : kDemonMajor) pushUnique(out, k);",
     "            for (const auto& k :\n"
                "                 planarSetView(\"demon_major_set\"))\n"
                "                pushUnique(out, k.c_str());"),
    ("            for (const char* k : kDemonMinor) pushUnique(out, k);",
     "            for (const auto& k :\n"
                "                 planarSetView(\"demon_minor_set\"))\n"
                "                pushUnique(out, k.c_str());"),
    ("            for (const char* k : kDevilGreater) pushUnique(out, k);",
     "            for (const auto& k :\n"
                "                 planarSetView(\"devil_greater_set\"))\n"
                "                pushUnique(out, k.c_str());"),
]

REGTEST_OLD = ('    #include "rules/audits/r1035_city_encounter_registry.h"'
               '  // R1035')
REGTEST_NEW = ('    #include "rules/audits/r1035_city_encounter_registry.h"'
               '  // R1035\n'
               '    #include "rules/audits/r1036_planar_encounter_registry.h"'
               '  // R1036')


def seam_body(c65, tv, wind_hdr):
    # c65 (verbatim provenance) + seam note + views, then the
    # traveller party (verbatim slice), the roll/keys functions,
    # the wind/cyclone comment (verbatim) and the band-backed
    # wind/cyclone rolls. Blank-line discipline: one blank line
    # between every block, one blank line before the region-end
    # separator.
    return (c65 + SEAM_NOTE + "\n" + tv + ROLL_FN
            + "\n" + wind_hdr + "\n" + EFFECT_FNS + "\n")


def splice_encounters(src, start, end, body):
    new = src[:start] + body + src[end:]
    return new


# ---------------------------------------------------------------------------
# 6. the battery fragment (rules/audits/r1036_planar_encounter_
#    registry.h) - 7 sections, pins DERIVED from the parsed data
#    (the R1035 m[44] lesson: never a recalled index)
# ---------------------------------------------------------------------------

def build_fragment(astral, ethereal, picks):
    def idx(table, key):
        for i, r in enumerate(table):
            if r[2] == key:
                return i
        die("fragment pin: %r not in the parsed table" % key)

    ia_base = idx(astral, "aerial_servant")
    ia_bas = idx(astral, "basilisk")
    ia_tit = idx(astral, "PLANAR_TITAN_MAJOR")
    ie_base = idx(ethereal, "aerial_servant")
    ie_cou = idx(ethereal, "couatl")
    ie_xorn = idx(ethereal, "xorn")
    na = len(astral)
    ne = len(ethereal)
    pm = dict(picks)

    L = []
    def A(s=""):
        L.append(s)

    A("// ============================================================================")
    A("// Adnd1 - rules/audits/r1036_planar_encounter_registry.h  (R1036)")
    A("// The R65 astral/ethereal planar family battery audit, the")
    A("// R1032-R1035 shape: the registry load, exact table counts,")
    A("// band coverage, row/pick/band spot pins against the")
    A("// print-fidelity record, the wind/cyclone engine parity,")
    A("// the key companion vs the table expansion, and the")
    A("// rollPlanarEncounter() path. Expected: 5 planar files -")
    A("// the %d-row astral and %d-row ethereal tables (band," % (na, ne))
    A("// key, the printed Numbers column, the (*) footnote flag)," )
    A("// the 7 pick-sets (%s)," %
      "/".join(str(len(v)) for _, v in picks))
    A("// and the wind/cyclone d20 band tables - all from the")
    A("// R65 record (Premium reprint p.181) the splice parsed.")
    A("// The demon-prince/arch-devil pools are engine-side (the")
    A("// R52 record); the (*) footnote creatures are listed in")
    A("// the companion regardless (R60 precedent) and gated on")
    A("// primeAdjacent at roll time.")
    A("// ============================================================================")
    A("{")
    A("")
    A("    static const char* const kPlanarTables[2] = {")
    A('        "planar_astral", "planar_ethereal" };')
    A("    static const char* const kPlanarSets[7] = {")
    A('        "demon_minor_set", "demon_major_set", "devil_greater_set",')
    A('        "devil_lesser_set", "titan_elder_set", "titan_lesser_set",')
    A('        "titan_major_set" };')
    A("    static const int kPlanarSetSizes[7] = { %s };"
      % ", ".join(str(len(v)) for _, v in picks))
    A("    static const char* const kPlanarBands[2] = {")
    A('        "planar_wind", "planar_cyclone" };')
    A("    static const char* const kFragPrinces[4] = {")
    A('        "demogorgon", "juiblex", "orcus", "yeenoghu" };')
    A("    static const char* const kFragArchDevils[4] = {")
    A('        "asmodeus", "baalzebul", "dispater", "geryon" };')
    A("")
    A("    int bad = 0;")
    A("    dm::EncounterTableRegistry ereg;")
    A("")
    A("    // -- 1. load: 5 planar files, zero errors, one reg --")
    A("    bad = 0;")
    A("    {")
    A('        const int pf = ereg.loadDirectory(')
    A('            "content/tables/encounters_planar");')
    A("        if (pf != 5) ++bad;")
    A("        if (!ereg.errors().empty()) ++bad;")
    A('        const int df = ereg.loadDirectory(')
    A('            "content/tables/encounters");')
    A("        if (df != 20) ++bad;")
    A('        const int wf = ereg.loadDirectory(')
    A('            "content/tables/encounters_water");')
    A("        if (wf != 9) ++bad;")
    A('        const int of = ereg.loadDirectory(')
    A('            "content/tables/encounters_outdoor");')
    A("        if (of != 21) ++bad;")
    A('        const int cf = ereg.loadDirectory(')
    A('            "content/tables/encounters_city");')
    A("        if (cf != 9) ++bad;")
    A('        if (!ereg.hasPlanar("planar_astral")) ++bad;')
    A('        if (!ereg.hasPlanar("planar_ethereal")) ++bad;')
    A('        if (!ereg.hasPlanarBands("planar_wind")) ++bad;')
    A('        if (!ereg.hasPlanarBands("planar_cyclone")) ++bad;')
    A("        // negative pins (the R1034 dispatch-order lesson:")
    A("        // the exact keys stay exclusive on every side)")
    A('        if (ereg.hasPlanar("planar_picks")) ++bad;')
    A('        if (ereg.hasPlanar("planar_wind")) ++bad;   // band file')
    A('        if (ereg.hasPlanarBands("planar_astral")) ++bad;')
    A('        if (ereg.hasPlanar("city_matrix")) ++bad;')
    A('        if (ereg.hasPlanar("outdoor_sets")) ++bad;')
    A('        if (ereg.hasCityBands("planar_wind")) ++bad;')
    A('        if (ereg.hasOutdoor("planar_astral")) ++bad;')
    A('        if (ereg.hasWater("planar_ethereal")) ++bad;')
    A('        if (ereg.hasPlanar("")) ++bad;')
    A('        if (ereg.hasPlanarBands("")) ++bad;')
    A("        // the pick-set lists rode m_lists")
    A('        if ((int)ereg.list("demon_minor_set").size() != %d) ++bad;'
      % len(pm["demon_minor"]))
    A('        if ((int)ereg.list("demon_major_set").size() != %d) ++bad;'
      % len(pm["demon_major"]))
    A("    }")
    A('    printf("R1036 planar encounter registry load audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 2. counts: rows, sets, bands ---------------------")
    A("    bad = 0;")
    A("    {")
    A('        if ((int)ereg.planarRows("planar_astral").size() != %d) ++bad;' % na)
    A('        if ((int)ereg.planarRows("planar_ethereal").size() != %d) ++bad;' % ne)
    A("        for (int i = 0; i < 7; ++i) {")
    A("            const int n = (int)ereg.list(kPlanarSets[i]).size();")
    A("            if (n != kPlanarSetSizes[i]) ++bad;")
    A("        }")
    A('        if ((int)ereg.planarBands("planar_wind").size() != 4) ++bad;')
    A('        if ((int)ereg.planarBands("planar_cyclone").size() != 4) ++bad;')
    A("        // the absent-table contract: empty, never a crash")
    A('        if (!ereg.planarRows("planar_picks").empty()) ++bad;')
    A('        if (!ereg.planarBands("planar_astral").empty()) ++bad;')
    A("    }")
    A('    printf("R1036 planar encounter registry counts audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 3. bands: percentile and d20 chains -------------")
    A("    bad = 0;")
    A("    {")
    A("        for (int t = 0; t < 2; ++t) {")
    A("            int prev = 0;")
    A("            for (const auto& r : ereg.planarRows(kPlanarTables[t])) {")
    A("                if (r.lo != prev + 1 || r.hi < r.lo")
    A("                    || r.hi > 100) ++bad;")
    A("                prev = r.hi;")
    A("            }")
    A("            if (prev != 100) ++bad;")
    A("        }")
    A("        for (int b = 0; b < 2; ++b) {")
    A("            int prev = 0;")
    A("            for (const auto& r : ereg.planarBands(kPlanarBands[b])) {")
    A("                if (r.lo != prev + 1 || r.hi < r.lo")
    A("                    || r.hi > 20) ++bad;")
    A("                prev = r.hi;")
    A("            }")
    A("            if (prev != 20) ++bad;")
    A("        }")
    A("    }")
    A('    printf("R1036 planar encounter registry bands audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 4. pins: rows, picks, wind/cyclone bands ---------")
    A("    bad = 0;")
    A("    {")
    A('        const auto& ma = ereg.planarRows("planar_astral");')
    A('        const auto& me = ereg.planarRows("planar_ethereal");')
    ra = astral[ia_base]; rbas = astral[ia_bas]; rtan = astral[ia_tit]
    ea = ethereal[ie_base]; ecou = ethereal[ie_cou]; exorn = ethereal[ie_xorn]
    A('        if (ma[%d].key != "%s" || ma[%d].lo != %d'
      % (ia_base, ra[2], ia_base, ra[0]))
    A("            || ma[%d].hi != %d || ma[%d].nMin != %d"
      % (ia_base, ra[1], ia_base, ra[3]))
    A("            || ma[%d].nMax != %d || ma[%d].primeOnly)"
      % (ia_base, ra[4], ia_base))
    A("            ++bad;")
    A('        if (ma[%d].key != "basilisk" || !ma[%d].primeOnly) ++bad;'
      % (ia_bas, ia_bas))
    A('        if (ma[%d].key != "PLANAR_TITAN_MAJOR") ++bad;' % ia_tit)
    A("        if (ma[%d].lo != %d || ma[%d].hi != %d"
      % (ia_tit, rtan[0], ia_tit, rtan[1]))
    A("            || ma[%d].nMin != %d || ma[%d].nMax != %d) ++bad;"
      % (ia_tit, rtan[3], ia_tit, rtan[4]))
    A('        if (me[%d].key != "%s" || me[%d].lo != %d'
      % (ie_base, ea[2], ie_base, ea[0]))
    A("            || me[%d].hi != %d || me[%d].primeOnly)"
      % (ie_base, ea[1], ie_base))
    A("            ++bad;")
    A('        if (me[%d].key != "%s" || me[%d].lo != %d'
      % (ie_cou, ecou[2], ie_cou, ecou[0]))
    A("            || me[%d].hi != %d || me[%d].nMin != %d"
      % (ie_cou, ecou[1], ie_cou, ecou[3]))
    A("            || me[%d].nMax != %d || me[%d].primeOnly) ++bad;"
      % (ie_cou, ecou[4], ie_cou))
    A('        if (me[%d].key != "%s" || me[%d].lo != %d'
      % (ie_xorn, exorn[2], ie_xorn, exorn[0]))
    A("            || me[%d].hi != %d || me[%d].nMin != %d"
      % (ie_xorn, exorn[1], ie_xorn, exorn[3]))
    A("            || me[%d].nMax != %d) ++bad;"
      % (ie_xorn, exorn[4]))
    A("        // the pick sets (verbatim members, first/last spot)")
    A('        const auto& dminor = ereg.list("demon_minor_set");')
    A('        if (dminor.empty() || dminor.front() != "%s") ++bad;'
      % pm["demon_minor"][0])
    A('        if (dminor.back() != "%s") ++bad;'
      % pm["demon_minor"][-1])
    A('        const auto& dmaj = ereg.list("demon_major_set");')
    A('        if (dmaj.empty() || dmaj.front() != "%s") ++bad;'
      % pm["demon_major"][0])
    A('        if (dmaj.back() != "%s") ++bad;'
      % pm["demon_major"][-1])
    A('        const auto& telder = ereg.list("titan_elder_set");')
    A('        if (telder.size() != 2 || telder.front() != "%s") ++bad;'
      % pm["titan_elder"][0])
    A('        if (telder.back() != "%s") ++bad;'
      % pm["titan_elder"][-1])
    A('        const auto& dgreater = ereg.list("devil_greater_set");')
    A('        if (dgreater.size() != 3 || dgreater.front() != "%s") ++bad;'
      % pm["devil_greater"][0])
    A("        // the wind/cyclone bands (d20, printed day ranges)")
    A('        const auto& wb = ereg.planarBands("planar_wind");')
    A("        if (wb[0].lo != %d || wb[0].hi != %d) ++bad;"
      % (WIND[0][0], WIND[0][1]))
    A('        if (wb[0].effect != "%s" || wb[0].dMin != -1) ++bad;'
      % WIND[0][2])
    A("        if (wb[3].lo != %d || wb[3].hi != %d) ++bad;"
      % (WIND[3][0], WIND[3][1]))
    A('        if (wb[3].effect != "%s" || wb[3].dMin != %d'
      % (WIND[3][2], WIND[3][3][0]))
    A("            || wb[3].dMax != %d) ++bad;" % WIND[3][3][1])
    A('        const auto& cb = ereg.planarBands("planar_cyclone");')
    A("        if (cb[0].lo != %d || cb[0].hi != %d) ++bad;"
      % (CYCLONE[0][0], CYCLONE[0][1]))
    A('        if (cb[0].effect != "%s" || cb[0].dMin != -1) ++bad;'
      % CYCLONE[0][2])
    A("        if (cb[2].lo != %d || cb[2].hi != %d) ++bad;"
      % (CYCLONE[2][0], CYCLONE[2][1]))
    A('        if (cb[2].effect != "%s" || cb[2].dMin != %d'
      % (CYCLONE[2][2], CYCLONE[2][3][0]))
    A("            || cb[2].dMax != %d) ++bad;" % CYCLONE[2][3][1])
    A('        if (cb[3].effect != "%s" || cb[3].dMin != %d'
      % (CYCLONE[3][2], CYCLONE[3][3][0]))
    A("            || cb[3].dMax != %d) ++bad;" % CYCLONE[3][3][1])
    A("    }")
    A('    printf("R1036 planar encounter registry pins audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 5. parity: the wind/cyclone engine vs the bands -")
    A("    bad = 0;")
    A("    {")
    A("        rules::Rng rng(1036);")
    A("        rules::Dice dice(rng);")
    A("        for (int d20 = 1; d20 <= 20; ++d20)")
    A("            for (int s = 0; s < 2; ++s) {")
    A("                const bool save = s != 0;")
    A("                dm::PsychicWindResult w =")
    A("                    dm::rollPsychicWind(dice, d20, save);")
    A("                const dm::EncounterPlanarBand* b = nullptr;")
    A('                for (const auto& cand : ereg.planarBands("planar_wind"))')
    A("                    if (d20 >= cand.lo && d20 <= cand.hi)")
    A("                        { b = &cand; break; }")
    A("                if (!b) { ++bad; continue; }")
    A('                if (b->effect == "slowed") {')
    A("                    if (w.effect != dm::PsychicWindEffect::Slowed")
    A("                        || w.days != 0 || w.cordBroken) ++bad;")
    A('                } else if (b->effect == "lost_return") {')
    A("                    if (w.effect != dm::PsychicWindEffect::LostReturn")
    A("                        || w.days < b->dMin || w.days > b->dMax")
    A("                        || w.cordBroken) ++bad;")
    A('                } else if (b->effect == "off_course") {')
    A("                    if (w.effect != dm::PsychicWindEffect::OffCourse")
    A("                        || w.days != 0 || w.cordBroken) ++bad;")
    A("                } else {")
    A("                    if (w.effect != dm::PsychicWindEffect::Storm)")
    A("                        ++bad;")
    A("                    if (save) {")
    A("                        if (w.days < b->dMin || w.days > b->dMax")
    A("                            || w.cordBroken) ++bad;")
    A("                    } else {")
    A("                        if (!w.cordBroken) ++bad;")
    A("                    }")
    A("                }")
    A("                dm::EtherCycloneResult c =")
    A("                    dm::rollEtherCyclone(dice, d20, save);")
    A("                const dm::EncounterPlanarBand* cb = nullptr;")
    A('                for (const auto& cand :')
    A('                     ereg.planarBands("planar_cyclone"))')
    A("                    if (d20 >= cand.lo && d20 <= cand.hi)")
    A("                        { cb = &cand; break; }")
    A("                if (!cb) { ++bad; continue; }")
    A('                if (cb->effect == "blown_about") {')
    A("                    if (c.effect != dm::EtherCycloneEffect::BlownAbout")
    A("                        || c.days != 0 || c.blownToAstral) ++bad;")
    A('                } else if (cb->effect == "different_plane") {')
    A("                    if (c.effect !=")
    A("                            dm::EtherCycloneEffect::DifferentPlane")
    A("                        || c.days != 0 || c.blownToAstral) ++bad;")
    A('                } else if (cb->effect == "lost_new_plane") {')
    A("                    if (c.effect != dm::EtherCycloneEffect::LostNewPlane")
    A("                        || c.days < cb->dMin")
    A("                        || c.days > cb->dMax")
    A("                        || c.blownToAstral) ++bad;")
    A("                } else {")
    A("                    if (c.effect !=")
    A("                            dm::EtherCycloneEffect::StormAstral)")
    A("                        ++bad;")
    A("                    if (c.days < cb->dMin || c.days > cb->dMax)")
    A("                        ++bad;")
    A("                    if (c.blownToAstral == save) ++bad;")
    A("                }")
    A("            }")
    A("    }")
    A('    printf("R1036 planar encounter registry parity audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 6. keys: the companion vs the table expansion ---")
    A("    bad = 0;")
    A("    {")

    A("        for (int t = 0; t < 2; ++t) {")
    A("            const auto got = dm::planarEncounterKeys(")
    A("                reg, t ? dm::PB_ETHEREAL : dm::PB_ASTRAL);")
    A("            std::vector<std::string> want;")
    A("            auto pushU = [&](const std::string& k) {")
    A("                for (const auto& w : want)")
    A("                    if (w == k) return;")
    A("                want.push_back(k);")
    A("            };")
    A("            for (const auto& r : ereg.planarRows(kPlanarTables[t])) {")
    A("                const std::string k = r.key;")
    A('                if (k == "PLANAR_DEMON_MINOR") {')
    A('                    for (const auto& s : ereg.list("demon_minor_set"))')
    A("                        pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_DEMON_MAJOR") {')
    A('                    for (const auto& s : ereg.list("demon_major_set"))')
    A("                        pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_DEMON_PRINCE") {')
    A("                    for (const char* s : kFragPrinces) pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_DEVIL_ARCH") {')
    A("                    for (const char* s : kFragArchDevils)")
    A("                        pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_DEVIL_GREATER") {')
    A('                    for (const auto& s :')
    A('                         ereg.list("devil_greater_set"))')
    A("                        pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_DEVIL_LESSER") {')
    A('                    for (const auto& s :')
    A('                         ereg.list("devil_lesser_set"))')
    A("                        pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_TITAN_ELDER"')
    A('                    || k == "PLANAR_TITAN_LESSER"')
    A('                    || k == "PLANAR_TITAN_MAJOR") {')
    A('                    const std::string set =')
    A('                        k == "PLANAR_TITAN_ELDER"')
    A('                        ? "titan_elder_set"')
    A('                        : k == "PLANAR_TITAN_LESSER"')
    A('                        ? "titan_lesser_set" : "titan_major_set";')
    A("                    for (const auto& s : ereg.list(set)) pushU(s);")
    A("                    continue;")
    A("                }")
    A('                if (k == "PLANAR_TRAVELLER") {')
    A('                    pushU("planar_traveller_party");')
    A("                    continue;")
    A("                }")
    A("                if (reg.find(k)) pushU(k);")
    A("            }")
    A("            // both directions, then the structural pins")
    A("            if (got.size() != want.size()) ++bad;")
    A("            for (const auto& k : got) {")
    A("                bool hit = false;")
    A("                for (const auto& w : want)")
    A("                    if (k == w) { hit = true; break; }")
    A("                if (!hit) { ++bad; break; }")
    A("            }")
    A("            for (const auto& k : want) {")
    A("                bool hit = false;")
    A("                for (const auto& g : got)")
    A("                    if (k == g) { hit = true; break; }")
    A("                if (!hit) { ++bad; break; }")
    A("            }")
    A("            auto has = [&](const char* k) {")
    A("                for (const auto& g : got)")
    A("                    if (g == k) return true;")
    A("                return false;")
    A("            };")
    A('            if (!has("planar_traveller_party")) ++bad;')
    A("            if (t == 0) {")
    A("                // the astral-only structural pins (the")
    A("                // ethereal table carries no demon/devil/")
    A("                // titan rows - table-scoped, not global)")
    A('                if (!has("type_vi_demon_balor")) ++bad;')
    A('                if (!has("pit_fiend")) ++bad;')
    A('                if (!has("demogorgon")) ++bad;')
    A('                if (!has("asmodeus")) ++bad;')
    A('                if (!has("elder_titan_ac_2")) ++bad;')
    A('                if (!has("major_titan_ac_1")) ++bad;')
    A("                // R60 precedent: the (*) footnote creatures")
    A("                // are listed regardless, gated at roll time")
    A('                if (!has("basilisk") || !has("cockatrice")')
    A('                    || !has("gorgon") || !has("medusa")) ++bad;')
    A('                if (!has("shedu")) ++bad;')
    A("                if ((int)got.size() < 40) ++bad;")
    A("            } else {")
    A('                if (!has("xorn") || !has("wind_walker")) ++bad;')
    A('                if (!has("couatl")) ++bad;')
    A("                if ((int)got.size() < 25) ++bad;")
    A("            }")
    A("        }")
    A("    }")
    A('    printf("R1036 planar encounter registry keys audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 7. roll: the planar path, sweep + smoke ---------")
    A("    bad = 0;")
    A("    {")
    A("        rules::Rng rng(1036);")
    A("        rules::Dice dice(rng);")
    A("        // expanded key -> the widest printed numbers range")
    A("        std::map<std::string, std::pair<int,int>> nums;")
    A("        for (int t = 0; t < 2; ++t)")
    A("            for (const auto& r :")
    A("                 ereg.planarRows(kPlanarTables[t])) {")
    A("                std::vector<std::string> kk;")
    A("                const std::string& k = r.key;")
    A('                if      (k == "PLANAR_DEMON_MINOR")')
    A('                    kk = ereg.list("demon_minor_set");')
    A('                else if (k == "PLANAR_DEMON_MAJOR")')
    A('                    kk = ereg.list("demon_major_set");')
    A('                else if (k == "PLANAR_DEMON_PRINCE")')
    A("                    for (const char* x : kFragPrinces)")
    A("                        kk.push_back(x);")
    A('                else if (k == "PLANAR_DEVIL_ARCH")')
    A("                    for (const char* x : kFragArchDevils)")
    A("                        kk.push_back(x);")
    A('                else if (k == "PLANAR_DEVIL_GREATER")')
    A('                    kk = ereg.list("devil_greater_set");')
    A('                else if (k == "PLANAR_DEVIL_LESSER")')
    A('                    kk = ereg.list("devil_lesser_set");')
    A('                else if (k == "PLANAR_TITAN_ELDER")')
    A('                    kk = ereg.list("titan_elder_set");')
    A('                else if (k == "PLANAR_TITAN_LESSER")')
    A('                    kk = ereg.list("titan_lesser_set");')
    A('                else if (k == "PLANAR_TITAN_MAJOR")')
    A('                    kk = ereg.list("titan_major_set");')
    A('                else if (k != "PLANAR_TRAVELLER")')
    A("                    kk.push_back(k);")
    A("                for (const auto& x : kk) {")
    A("                    auto& p = nums[x];")
    A("                    if (r.nMax > p.second)")
    A("                        p = { r.nMin, r.nMax };")
    A("                }")
    A("            }")
    A("        for (int t = 0; t < 2; ++t) {")
    A("            const auto companion = dm::planarEncounterKeys(")
    A("                reg, t ? dm::PB_ETHEREAL : dm::PB_ASTRAL);")
    A("            auto inCompanion = [&](const std::string& k) {")
    A("                for (const auto& c : companion)")
    A("                    if (c == k) return true;")
    A("                return false;")
    A("            };")
    A("            for (int primeI = 0; primeI < 2; ++primeI)")
    A("                for (int pct = 1; pct <= 100; ++pct) {")
    A("                    const int p2 = 1 + (pct * 37) % 100;")
    A("                    dm::DungeonEncounter e =")
    A("                        dm::rollPlanarEncounter(")
    A("                            reg, dice, pct, p2,")
    A("                            t ? dm::PB_ETHEREAL : dm::PB_ASTRAL,")
    A("                            primeI != 0);")
    A('                    if (e.key.empty()) { ++bad; continue; }')
    A("                    if (!inCompanion(e.key)) ++bad;")
    A('                    if (e.key == "planar_traveller_party") {')
    A("                        if (!e.isParty) ++bad;")
    A("                        if ((int)e.party.members.size()")
    A("                            != e.count) ++bad;")
    A("                        if (e.count < 1 || e.count > 6) ++bad;")
    A("                    } else {")
    A("                        if (e.isParty) ++bad;")
    A("                        const auto it = nums.find(e.key);")
    A("                        if (it == nums.end()) ++bad;")
    A("                        else if (e.count < it->second.first")
    A("                              || e.count > it->second.second)")
    A("                            ++bad;")
    A("                    }")
    A("                    if (!primeI) {")
    A("                        // the (*) footnote: never produced")
    A("                        // when no prime-material effect")
    A('                        if (e.key == "basilisk"')
    A('                            || e.key == "cockatrice"')
    A('                            || e.key == "gorgon"')
    A('                            || e.key == "medusa") ++bad;')
    A("                    }")
    A("                }")
    A("        }")
    A("        // rng smoke: 4000 rolls, outcomes must be legal")
    A("        for (int i = 0; i < 4000; ++i) {")
    A("            dm::DungeonEncounter e = dm::rollPlanarEncounter(")
    A("                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,")
    A("                (i % 2) ? dm::PB_ETHEREAL : dm::PB_ASTRAL,")
    A("                (i % 3) != 0);")
    A('            if (e.key.empty()) { ++bad; continue; }')
    A('            if (e.key == "planar_traveller_party") {')
    A("                if (!e.isParty) ++bad;")
    A("                if ((int)e.party.members.size() != e.count)")
    A("                    ++bad;")
    A("                if (e.count < 1 || e.count > 6) ++bad;")
    A("            } else {")
    A("                if (e.isParty) ++bad;")
    A("                if (e.count < 1) ++bad;")
    A("            }")
    A("        }")
    A("    }")
    A('    printf("R1036 planar encounter registry roll audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("}")
    return "\n".join(L) + "\n"


# ---------------------------------------------------------------------------
# 7. census + brace balance + main
# ---------------------------------------------------------------------------

CENSUS_PRE = 969
CENSUS_POST = 976
COMPANION_ASTRAL = 52
COMPANION_ETHEREAL = 27

# full-declaration tokens only: the retained c65 provenance
# comment mentions PF_PRIME_ONLY verbatim and the R66 comments
# say "R65 kDemonMajor," - bare array names would false-trip
RETIRED_TOKENS = [
    "kAstralTable",
    "kEtherealTable",
    "struct PlanarRow",
    "planarTable(",
    "static const char* const kDemonMinor",
    "static const char* const kDemonMajor",
    "static const char* const kDevilGreater",
    "static const char* const kDevilLesser",
    "static const char* const kTitanElder",
    "static const char* const kTitanLesser",
    "static const char* const kTitanMajor",
]


def census_count():
    n = 0
    for p in (glob.glob(os.path.join(ROOT, "rules/audits/*.h"))
              + [REGTEST]):
        if not os.path.isfile(p):
            continue
        with open(p, encoding="utf-8") as f:
            n += f.read().count("audit: bad %d")
    return n


def brace_balance(path):
    with open(path, encoding="utf-8") as f:
        t = f.read()
    t = re.sub(r"//[^\n]*", "", t)
    t = re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    t = re.sub(r'"(?:\\.|[^"\\])*"', '""', t)
    return t.count("{") - t.count("}")


def main():
    if not os.path.isfile(ENC):
        die("run from the Adnd1 repo root (dm/encounters.cpp "
            "not found under %s)" % ROOT)

    # -- idempotence: the applied state is the registry header --
    with open(REG_H, encoding="utf-8") as f:
        reg_h = f.read()
    if "EncounterPlanarRow" in reg_h:
        if "kAstralTable" in open(ENC, encoding="utf-8").read():
            die("half-spliced state: the registry is extended "
                "but the R65 region is still wired - inspect "
                "dm/encounters.cpp")
        for name in ("planar_astral", "planar_ethereal",
                     "planar_picks", "planar_wind",
                     "planar_cyclone"):
            if not os.path.isfile(os.path.join(LUA_DIR,
                                              name + ".lua")):
                die("half-spliced state: %s.lua missing" % name)
        c = census_count()
        if c != CENSUS_POST:
            die("census drift: %d audit patterns (expected %d)"
                % (c, CENSUS_POST))
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    pre = census_count()
    if pre != CENSUS_PRE:
        die("pre-splice census is %d (expected %d) - the tree "
            "has drifted from main@14fc2780" % (pre, CENSUS_PRE))

    # -- parse the R65 record out of the retired region --
    with open(ENC, encoding="utf-8") as f:
        src = f.read()
    i0, i1, astral, ethereal, picks, c65, tv, wind_hdr = \
        parse_planar_region(src)
    problems = gate_data(astral, ethereal, picks)
    if problems:
        die("data gate: " + "; ".join(problems[:4]))
    na_keys, ne_keys = simulate_roll_path(astral, ethereal, picks)
    print("parsed: astral %d rows, ethereal %d rows, 7 pick-sets "
          "(%s), wind %d bands, cyclone %d bands"
          % (len(astral), len(ethereal),
             "/".join(str(len(v)) for _, v in picks),
             len(WIND), len(CYCLONE)))
    print("roll-path sim: pct sweeps clean, companion keys "
          "astral %d / ethereal %d, counts within printed ranges"
          % (na_keys, ne_keys))

    # -- emit + round-trip the five lua files --
    data = {"astral": astral, "ethereal": ethereal,
            "picks": picks}
    emit_lua(data)
    lua_roundtrip(data)
    print("round-trip: 5 lua files parse back byte-exact")

    # -- the registry extension (h + cpp, anchor-checked) --
    extend_registry()

    # -- the cpp seam: region out, registry-backed code in --
    body = seam_body(c65, tv, wind_hdr)
    new_enc = splice_encounters(src, i0, i1, body)
    new_enc = replace_once(new_enc, ENC_LOAD_ANCHOR,
                           ENC_LOAD_ADD, "encReg planar load")
    for tok in RETIRED_TOKENS:
        if tok in new_enc:
            die("retired token survived the splice: %r" % tok)

    # -- R66 rewiring: the psionic (*) pick rows ride the views --
    for old6, new6 in R66_ROLL_REWIRES + R66_KEYS_REWIRES:
        new_enc = replace_once(new_enc, old6, new6, "R66 rewire")
    for tok in ("kDemonMajor[", "kDemonMinor[", "kDevilGreater["):
        if tok in new_enc:
            die("R66 pick array use survived the rewire: %r" % tok)

    # -- the fragment + the regtest include --
    frag_text = build_fragment(astral, ethereal, picks)
    if frag_text.count("audit: bad %d") != 7:
        die("fragment census math wrong")
    with open(REGTEST, encoding="utf-8") as f:
        rt = f.read()
    rt = replace_once(rt, REGTEST_OLD, REGTEST_NEW,
                      "regtest include")

    # -- write the tracked files --
    with open(ENC, "w", encoding="utf-8") as f:
        f.write(new_enc)
    with open(FRAG, "w", encoding="utf-8") as f:
        f.write(frag_text)
    with open(REGTEST, "w", encoding="utf-8") as f:
        f.write(rt)

    # -- final gates --
    for p in (REG_H, REG_CPP, ENC, REGTEST, FRAG):
        b = brace_balance(p)
        if b != 0:
            die("brace imbalance %d in %s" % (b, p))
    post = census_count()
    if post != CENSUS_POST:
        die("census is %d (expected %d)" % (post, CENSUS_POST))
    print("census: %d -> %d audit printf patterns" % (pre, post))

    print("applied 1, rewrote 4 tracked files, wrote 5 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
