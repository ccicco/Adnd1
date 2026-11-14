#!/usr/bin/env python3
# r1038_splice.py - R1038: the R67 patrol and CASTLE/FORTRESS
# tables de-wire (the R1032-R1037 shape; census 983 -> 990).
#
# The R67 region of dm/encounters.cpp (separator above
# "R67: the PATROL and CASTLE/FORTRESS tables" through the
# "// ==== R74" header) retires its five printed tables into
# content/tables/encounters_castle/: CASTLE TABLE I
# (size class and type, 9 rows) into castle_type.lua, the
# three per-size CASTLE TABLE II inhabitants sub-tables (4
# rows each) into castle_inh_small/medium/large.lua,
# SUB-TABLE II.A (humans are, 4 rows, bestiary keys) into
# castle_humans.lua, SUB-TABLE II.B (the master's class and
# level, 11 rows incl. the corrected Assassin/Monk/Bard
# overlap) into castle_master.lua, and the ARTILLERY table
# (8 rows keyed by type) into castle_artillery.lua. One new
# registry row shape (EncounterCastleRow) carries all five;
# enums ride as printed tokens (small/medium/large, the
# inhabitant categories, the profession names) mapped
# engine-side in the seam. The functions keep their public
# signatures (game/state_overland.cpp calls them): the
# percentile lookups rewrite onto castleView; castleHumans-
# Count, rollCastleHenchmen, castleAwareness and rollPatrol
# (no table) stay verbatim; kPrinces-style mechanics - the
# leader/lieutenant/sergeant/men-at-arms construction, the
# 40%/60% cleric-or-magic-user split, the henchman ladder -
# stay engine-side. Fragment: rules/audits/
# r1038_castle_encounter_registry.h (7 sections, census +7).
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
LUA_DIR = os.path.join(ROOT, "content", "tables",
                       "encounters_castle")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1038_castle_encounter_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory (asserted against the source at parse time)
# ---------------------------------------------------------------------------

N_TYPE = 9
N_INH = 4        # rows per size table
N_HUMANS = 4
N_MASTER = 11
N_ARTILLERY = 8
FILES = 7        # lua files in encounters_castle/

SIZES = ["small", "medium", "large"]
CATS = ["totally_deserted", "deserted_monster",
        "humans", "character_types"]
PROFS = ["cleric", "druid", "fighter", "paladin", "ranger",
         "magic_user", "illusionist", "thief", "assassin",
         "monk_bard"]
SIZE_TOKENS = {"CASTLE_SMALL": "small",
               "CASTLE_MEDIUM": "medium",
               "CASTLE_LARGE": "large"}
CAT_TOKENS = {"CASTLE_TOTALLY_DESERTED": "totally_deserted",
              "CASTLE_DESERTED_MONSTER": "deserted_monster",
              "CASTLE_HUMANS": "humans",
              "CASTLE_CHARACTER_TYPES": "character_types"}
PROF_TOKENS = {"PROF_CLERIC": "cleric", "PROF_DRUID": "druid",
               "PROF_FIGHTER": "fighter",
               "PROF_PALADIN": "paladin",
               "PROF_RANGER": "ranger", "PROF_MU": "magic_user",
               "PROF_ILLUSIONIST": "illusionist",
               "PROF_THIEF": "thief",
               "PROF_ASSASSIN": "assassin",
               "PROF_MONK_BARD": "monk_bard"}

# the printed tables, PARSED from the region; these expected
# shapes gate the parse (the R1035 never-recall lesson)
WANT_TYPE = [
    (1, 10, "small", "small shell keep"),
    (11, 25, "small", "tower"),
    (26, 35, "small", "moat house or friary"),
    (36, 45, "medium", "large shell keep"),
    (46, 65, "medium", "small walled castle with keep"),
    (66, 80, "medium", "medium walled castle with keep"),
    (81, 88, "large", "concentric castle"),
    (89, 95, "large", "large walled castle with keep"),
    (96, 100, "large", "fortress complex"),
]
WANT_INH = {
    "small":   [(1, 45, "totally_deserted"),
                (46, 60, "deserted_monster"),
                (61, 70, "humans"),
                (71, 100, "character_types")],
    "medium":  [(1, 30, "totally_deserted"),
                (31, 50, "deserted_monster"),
                (51, 65, "humans"),
                (66, 100, "character_types")],
    "large":   [(1, 15, "totally_deserted"),
                (16, 40, "deserted_monster"),
                (41, 60, "humans"),
                (61, 100, "character_types")],
}
WANT_HUMANS = [(1, 25, "bandit"), (26, 85, "bandit"),
               (86, 97, "berserker"), (98, 100, "dervish")]
WANT_MASTER = [
    (1, 18, "cleric", 9, 12),
    (19, 20, "druid", 12, 13),
    (21, 65, "fighter", 9, 12),
    (66, 66, "paladin", 9, 10),
    (67, 68, "ranger", 10, 13),
    (69, 80, "magic_user", 11, 14),
    (81, 85, "illusionist", 10, 13),
    (86, 93, "thief", 10, 14),
    (94, 96, "assassin", 14, 14),
    (97, 99, "monk_bard", 9, 12),      # monk (the OCR fix)
    (100, 100, "monk_bard", 23, 23),   # bard, 23rd
]
WANT_ARTILLERY = [
    ("moat house or friary", 2, 0, 1),
    ("tower", 1, 0, 1),
    ("shell keep", 0, 1, 2),
    ("small walled castle with keep", 1, 1, 2),
    ("medium walled castle with keep", 2, 2, 5),
    ("concentric castle", 4, 2, 6),
    ("large walled castle with keep", 4, 4, 8),
    ("fortress complex", 4, 4, 8),
]

# every source substring the retired region must carry
ASSERTS = [
    'struct CastleTypeRow',
    'static const CastleTypeRow kCastleTypeTable[] = {',
    'static const CastleInhRow kCastleInhSmall[] = {',
    'static const CastleInhRow kCastleInhMedium[] = {',
    'static const CastleInhRow kCastleInhLarge[] = {',
    'kCastleHumansAre[] = {',
    'static const CastleMasterRow kCastleMaster[] = {',
    'static const ArtilleryRow kCastleArtillery[] = {',
    'CastleType rollCastleType(int pctile) {',
    'CastleInhabitants castleInhabitants(int pctile, CastleSize size) {',
    'const char* castleHumansType(int pctile) {',
    'int castleHumansCount(const monsters::MonsterRegistry& reg,',
    'PartyMember rollCastleMaster(rules::Dice& dice, int pctile) {',
    'CharacterParty rollCastleHenchmen(rules::Dice& dice,',
    'CastleArtillery castleArtillery(const CastleType& castle) {',
    'CastleAwareness castleAwareness(int surpriseDie) {',
    'CharacterParty rollPatrol(rules::Dice& dice, bool rangerLeader) {',
    'def->noAppearingMin',
    'classForProf(row->prof)',
    'rollNpcRace(dice, m.classIndex)',
    'rollMagicItemsFor(dice, m)',
    'henchmanLevelFor(master.level)',
    'raceAllowsClass(master.race, m.classIndex)',
    'std::string(castle.type).find("shell keep")',
    'dice.roll(1, 100, 0) <= 40',
    '12 + (int)dice.roll(1, 12, 0)',
]

# full-declaration tokens only (the R1036 lesson): the
# retained c67 provenance comment mentions the function names
RETIRED_TOKENS = [
    "kCastleTypeTable",
    "kCastleInhSmall",
    "kCastleInhMedium",
    "kCastleInhLarge",
    "kCastleHumansAre",
    "kCastleMaster",
    "kCastleArtillery",
    "struct CastleTypeRow",
    "struct CastleInhRow",
    "struct CastleMasterRow",
    "struct ArtilleryRow",
    "sizeof kCastleTypeTable",
    "sizeof kCastleInhSmall",
    "sizeof kCastleInhMedium",
    "sizeof kCastleInhLarge",
    "sizeof kCastleHumansAre",
    "sizeof kCastleMaster",
    "sizeof kCastleArtillery",
]


def die(msg):
    sys.stderr.write("r1038_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the retired region out of dm/encounters.cpp
# ---------------------------------------------------------------------------

REGION_START = "// R67: the PATROL and CASTLE/FORTRESS tables"
REGION_END = "// ==== R74: MM-frequency encounter generator"
SEP = "// ----------------------------------------------------------------------------"


def parse_castle_region(src):
    if "kCastleTypeTable" not in src:
        die("kCastleTypeTable not found (already spliced?)")
    i0 = src.index(REGION_START)
    i0 = src.rindex(SEP, 0, i0)
    i1 = src.index(REGION_END)
    region = src[i0:i1]

    for a in ASSERTS:
        if a not in region:
            die("assertion failed, the retired region must "
                "carry %r" % a)

    def arr(name):
        m = re.search(r"static const %s\[\] = \{(.*?)\};"
                      % re.escape(name), region, re.S)
        if not m:
            die("array %s not found" % name)
        return m.group(1)

    # CASTLE TABLE I
    ctype = re.findall(
        r"\{(\d+),\s*(\d+),\s*(CASTLE_\w+),\s*\"([^\"]+)\"\s*\}",
        arr("CastleTypeRow kCastleTypeTable"))
    if len(ctype) != N_TYPE:
        die("parsed %d castle type rows (expected %d)"
            % (len(ctype), N_TYPE))
    table_type = [(int(a), int(b), SIZE_TOKENS[c], d)
                  for a, b, c, d in ctype]
    if table_type != WANT_TYPE:
        die("castle type table drifted from the record")

    # CASTLE TABLE II (per size)
    table_inh = {}
    for size, arrname in (("small", "CastleInhRow kCastleInhSmall"),
                          ("medium", "CastleInhRow kCastleInhMedium"),
                          ("large", "CastleInhRow kCastleInhLarge")):
        rows = re.findall(
            r"\{(\d+),\s*(\d+),\s*(CASTLE_\w+)\s*\}",
            arr(arrname))
        if len(rows) != N_INH:
            die("parsed %d %s inhabitant rows (expected %d)"
                % (len(rows), size, N_INH))
        got = [(int(a), int(b), CAT_TOKENS[c])
               for a, b, c in rows]
        if got != WANT_INH[size]:
            die("castle inhabitants (%s) drifted from the "
                "record" % size)
        table_inh[size] = got

    # SUB-TABLE II.A
    rows = re.findall(
        r"\{(\d+),\s*(\d+),\s*\"([a-z]+)\"\s*\}",
        arr("struct { short lo, hi; const char* key; } "
            "kCastleHumansAre"))
    if len(rows) != N_HUMANS:
        die("parsed %d humans-are rows (expected %d)"
            % (len(rows), N_HUMANS))
    table_humans = [(int(a), int(b), c) for a, b, c in rows]
    if table_humans != WANT_HUMANS:
        die("castle humans table drifted from the record")

    # SUB-TABLE II.B
    rows = re.findall(
        r"\{(\d+),\s*(\d+),\s*(PROF_\w+),\s*(\d+),\s*(\d+)",
        arr("CastleMasterRow kCastleMaster"))
    if len(rows) != N_MASTER:
        die("parsed %d master rows (expected %d)"
            % (len(rows), N_MASTER))
    table_master = [(int(a), int(b), PROF_TOKENS[c], int(d),
                     int(e)) for a, b, c, d, e in rows]
    if table_master != WANT_MASTER:
        die("castle master table drifted from the record")

    # ARTILLERY
    rows = re.findall(
        r"\{\"([^\"]+)\",\s*(\d+),\s*(\d+),\s*(\d+)\s*\}",
        arr("ArtilleryRow kCastleArtillery"))
    if len(rows) != N_ARTILLERY:
        die("parsed %d artillery rows (expected %d)"
            % (len(rows), N_ARTILLERY))
    table_artillery = [(a, int(b), int(c), int(d))
                       for a, b, c, d in rows]
    if table_artillery != WANT_ARTILLERY:
        die("castle artillery table drifted from the record")

    # the verbatim provenance header (kept in the seam)
    c67 = region[:region.index("namespace {")].rstrip() + "\n"
    # the whitespace between the region tail and the R74
    # header, preserved byte-exact
    tail_ws = region[region.rindex("}") + 1:]
    return (i0, i1, table_type, table_inh, table_humans,
            table_master, table_artillery, c67, tail_ws)


# ---------------------------------------------------------------------------
# 2. gate data + lua emission + round-trip
# ---------------------------------------------------------------------------

def gate_band_chain(rows, what):
    problems = []
    prev = 0
    for r in rows:
        lo, hi = r[0], r[1]
        if lo != prev + 1 or hi < lo or hi > 100:
            problems.append("%s band %r" % (what, (lo, hi)))
        prev = hi
    if prev != 100:
        problems.append("%s chain ends at %d" % (what, prev))
    return problems


def gate_data(table_type, table_inh, table_humans,
              table_master, table_artillery):
    problems = gate_band_chain(table_type, "castle type")
    for size in SIZES:
        problems += gate_band_chain(table_inh[size],
                                    "inh " + size)
    problems += gate_band_chain(table_humans, "humans")
    problems += gate_band_chain(table_master, "master")
    for lo, hi, size, typ in table_type:
        if size not in SIZES:
            problems.append("size token %r" % size)
    for size in SIZES:
        for lo, hi, cat in table_inh[size]:
            if cat not in CATS:
                problems.append("cat token %r" % cat)
    for lo, hi, key in table_humans:
        if key not in ("bandit", "berserker", "dervish"):
            problems.append("humans key %r" % key)
    for lo, hi, prof, a, b in table_master:
        if prof not in PROFS:
            problems.append("prof token %r" % prof)
        if a < 1 or b < a or b > 23:
            problems.append("master level %r" % ((a, b),))
    types = [t for _, _, _, t in table_type]
    for typ, n1, n2, n3 in table_artillery:
        if n1 < 0 or n2 < 0 or n3 < 0:
            problems.append("artillery counts %r" % (typ,))
    # the artillery rows must key onto the type strings
    for typ, n1, n2, n3 in table_artillery:
        if typ != "shell keep" and typ not in types:
            problems.append("artillery type %r not a castle "
                            "type" % typ)
    return problems


LUA_HDR = """-- encounter table def: %(key)s
-- The R67 castle family (R1038 de-wire): %(what)s
-- (DMG Appendix C Premium reprint p.182-183, OCR-verified).
-- %(note)s
-- DO NOT hand-edit: tools/r1038_splice.py is the only writer.

"""


def lua_file(key, what, note, body):
    return (LUA_HDR % dict(key=key, what=what, note=note)
            + "return {\n"
            + '  key = "%s",\n' % key
            + body
            + "}\n")


def emit_lua(table_type, table_inh, table_humans,
             table_master, table_artillery):
    os.makedirs(LUA_DIR, exist_ok=True)
    texts = {}

    b = "  rows = {\n"
    for lo, hi, size, typ in table_type:
        b += ('    { band = {%d,%d}, size = "%s", '
              'type = "%s" },\n' % (lo, hi, size, typ))
    b += "  },\n"
    texts["castle_type.lua"] = lua_file(
        "castle_type", "CASTLE TABLE I, size class and type",
        "band = the percentile column; size = the size class "
        "token (small/medium/large); type = the printed castle "
        "type string (the artillery rows key onto it).", b)

    for size in SIZES:
        b = "  rows = {\n"
        for lo, hi, cat in table_inh[size]:
            b += ('    { band = {%d,%d}, cat = "%s" },\n'
                  % (lo, hi, cat))
        b += "  },\n"
        texts["castle_inh_%s.lua" % size] = lua_file(
            "castle_inh_%s" % size,
            "CASTLE TABLE II, the %s castle inhabitants"
            % size,
            "band = the percentile column; cat = the printed "
            "category token (totally_deserted / "
            "deserted_monster / humans / character_types).", b)

    b = "  rows = {\n"
    for lo, hi, key in table_humans:
        b += ('    { band = {%d,%d}, key = "%s" },\n'
              % (lo, hi, key))
    b += "  },\n"
    texts["castle_humans.lua"] = lua_file(
        "castle_humans",
        "CASTLE SUB-TABLE II.A, humans are",
        "band = the percentile column; key = the bestiary key "
        "(brigand -> bandit, the R63 substitution; berserker; "
        "dervish) - numbers come from the registry's "
        "noAppearing (the R60 convention).", b)

    b = "  rows = {\n"
    for lo, hi, prof, a, b2 in table_master:
        b += ('    { band = {%d,%d}, prof = "%s", '
              'level = {%d,%d} },\n' % (lo, hi, prof, a, b2))
    b += "  },\n"
    texts["castle_master.lua"] = lua_file(
        "castle_master",
        "CASTLE SUB-TABLE II.B, the master's class and level",
        "band = the percentile column; prof = the printed "
        "profession token; level = the printed level range. "
        "The OCR overlap (printed Assassin 94-96 / Monk 94-99) "
        "is corrected to Assassin 94-96 / Monk 97-99 / Bard 00 "
        "(documented); monk and bard share the monk_bard token "
        "- the bard row's level (23) is its tell.", b)

    b = "  rows = {\n"
    for typ, n1, n2, n3 in table_artillery:
        b += ('    { type = "%s", ballistae = %d, '
              'lightCatapults = %d, oilCauldrons = %d },\n'
              % (typ, n1, n2, n3))
    b += "  },\n"
    texts["castle_artillery.lua"] = lua_file(
        "castle_artillery",
        "the ARTILLERY table, per fortress type",
        "No percentile column - the rows key onto the Table I "
        "type strings; both shell-keep rows key \"shell keep\" "
        "(documented). ballistae / lightCatapults / "
        "oilCauldrons = the printed counts.", b)

    if len(texts) != FILES:
        die("emitted %d lua files (expected %d)"
            % (len(texts), FILES))
    for name in sorted(texts):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(texts[name])


def lua_roundtrip(table_type, table_inh, table_humans,
                  table_master, table_artillery):
    def read(name):
        with open(os.path.join(LUA_DIR, name)) as f:
            return f.read()

    t = read("castle_type.lua")
    got = re.findall(
        r'\{ band = \{(\d+),(\d+)\}, size = "(\w+)", '
        r'type = "([^"]+)" \}', t)
    got = [(int(a), int(b), c, d) for a, b, c, d in got]
    if got != table_type:
        die("round-trip: castle_type mismatch")

    for size in SIZES:
        t = read("castle_inh_%s.lua" % size)
        got = re.findall(
            r'\{ band = \{(\d+),(\d+)\}, cat = "(\w+)" \}', t)
        got = [(int(a), int(b), c) for a, b, c in got]
        if got != table_inh[size]:
            die("round-trip: castle_inh_%s mismatch" % size)

    t = read("castle_humans.lua")
    got = re.findall(
        r'\{ band = \{(\d+),(\d+)\}, key = "(\w+)" \}', t)
    got = [(int(a), int(b), c) for a, b, c in got]
    if got != table_humans:
        die("round-trip: castle_humans mismatch")

    t = read("castle_master.lua")
    got = re.findall(
        r'\{ band = \{(\d+),(\d+)\}, prof = "(\w+)", '
        r'level = \{(\d+),(\d+)\} \}', t)
    got = [(int(a), int(b), c, int(d), int(e))
           for a, b, c, d, e in got]
    if got != table_master:
        die("round-trip: castle_master mismatch")

    t = read("castle_artillery.lua")
    got = re.findall(
        r'\{ type = "([^"]+)", ballistae = (\d+), '
        r'lightCatapults = (\d+), oilCauldrons = (\d+) \}', t)
    got = [(a, int(b), int(c), int(d)) for a, b, c, d in got]
    if got != table_artillery:
        die("round-trip: castle_artillery mismatch")


# ---------------------------------------------------------------------------
# 3. the registry extension (.h struct + accessors + members,
#    .cpp keys + loader branch + accessor definitions)
# ---------------------------------------------------------------------------

def replace_once(text, old, new, where):
    n = text.count(old)
    if n != 1:
        die("%s: anchor appears %d times (expected 1)"
            % (where, n))
    return text.replace(old, new, 1)


H_COMMENT_OLD = """// tools/r1034_splice.py (outdoor family),
// tools/r1035_splice.py (city family),
// tools/r1036_splice.py (planar family) and
// tools/r1037_splice.py (psionic family) are the only writers."""
H_COMMENT_NEW = """// tools/r1034_splice.py (outdoor family),
// tools/r1035_splice.py (city family),
// tools/r1036_splice.py (planar family),
// tools/r1037_splice.py (psionic family) and
// tools/r1038_splice.py (castle family) are the only writers."""

H_STRUCT_ANCHOR = """struct EncounterPlanarBand {
    int lo = 0, hi = 0;
    std::string effect;
    int dMin = -1, dMax = -1;    // -1: no printed days
};"""
H_STRUCT_NEW = H_STRUCT_ANCHOR + """

// R1038: the castle family row (the R67 de-wire). The five
// printed tables ride one row shape: lo/hi = the percentile
// band (0,0 = the artillery table, which keys by type);
// size = the Table I size-class token (small/medium/large);
// cat = the Table II inhabitants token; key = the II.A
// bestiary key; type = the Table I / artillery type string;
// prof = the II.B profession token; lvlLo/lvlHi = the
// master's printed level range; n1/n2/n3 = the artillery
// counts (ballistae/lightCatapults/oilCauldrons). Unused
// columns stay empty - the per-file key lists in the loader
// keep each file strict (the R1034 dispatch-order lesson).
struct EncounterCastleRow {
    int lo = 0, hi = 0;
    std::string size;
    std::string cat;
    std::string key;
    std::string type;
    std::string prof;
    int lvlLo = 0, lvlHi = 0;
    int n1 = 0, n2 = 0, n3 = 0;
};"""

H_ACC_ANCHOR = """    const std::vector<EncounterPlanarBand>& planarBands(
        const std::string& name) const;"""
H_ACC_NEW = H_ACC_ANCHOR + """
    // R1038: the castle family views. name: castle_type /
    // castle_inh_small / castle_inh_medium / castle_inh_large /
    // castle_humans / castle_master / castle_artillery.
    bool hasCastle(const std::string& name) const;
    const std::vector<EncounterCastleRow>& castleRows(
        const std::string& name) const;"""

H_MEM_ANCHOR = """    std::map<std::string, std::vector<EncounterPlanarBand>>
        m_planarBands;"""
H_MEM_NEW = H_MEM_ANCHOR + """
    // R1038: the castle family (the five printed R67 tables;
    // the artillery rows ride the same shape, unbanded).
    std::map<std::string, std::vector<EncounterCastleRow>>
        m_castle;"""

CPP_KEYS_ANCHOR = """const char* const kPsionicSpellKeys[] =
    { "key", "exact", "family", nullptr };"""
CPP_KEYS_NEW = CPP_KEYS_ANCHOR + """
// R1038: the castle family file/row keys. Exact keys only -
// no prefix, no exceptions (the R1034 dispatch-order
// lesson); the per-table row key lists below keep each
// file's shape strict.
const char* const kCastleFileKeys[] = { "key", "rows", nullptr };
const char* const kCastleTypeKeys[]  =
    { "band", "size", "type", nullptr };
const char* const kCastleInhKeys[]   = { "band", "cat", nullptr };
const char* const kCastleHumansKeys[] =
    { "band", "key", nullptr };
const char* const kCastleMasterKeys[] =
    { "band", "prof", "level", nullptr };
const char* const kCastleArtilleryKeys[] =
    { "type", "ballistae", "lightCatapults", "oilCauldrons",
      nullptr };"""

CPP_ELSE_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_BRANCH = """    } else if (key == "castle_type"
               || key == "castle_inh_small"
               || key == "castle_inh_medium"
               || key == "castle_inh_large"
               || key == "castle_humans"
               || key == "castle_master"
               || key == "castle_artillery") {
        const int t = lua_gettop(L);
        const char* const* rowKeys = kCastleInhKeys;
        bool banded = true;
        if      (key == "castle_type")   rowKeys = kCastleTypeKeys;
        else if (key == "castle_humans") rowKeys = kCastleHumansKeys;
        else if (key == "castle_master")
            rowKeys = kCastleMasterKeys;
        else if (key == "castle_artillery") {
            rowKeys = kCastleArtilleryKeys;
            banded = false;       // keyed by type, not band
        }
        if (!checkAllowedKeys(L, t, kCastleFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key mismatch";
                                         goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterCastleRow> rows;
            int prev = 0;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)
                    || !checkAllowedKeys(L, rt, rowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err)) {
                    if (lua_istable(L, rt))
                        lua_pop(L, 1);
                    goto bad;
                }
                EncounterCastleRow row;
                if (banded) {
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
                    prev = row.hi;
                }
                if (key == "castle_type") {
                    if (!getStr(L, rt, "size", &row.size, &err))
                        goto bad;
                    if (row.size != "small"
                        && row.size != "medium"
                        && row.size != "large") {
                        err = "unknown size token '" + row.size + "'";
                        goto bad;
                    }
                    if (!getStr(L, rt, "type", &row.type, &err))
                        goto bad;
                    if (row.type.empty()) {
                        err = "empty castle type";
                        goto bad;
                    }
                } else if (key == "castle_humans") {
                    if (!getStr(L, rt, "key", &row.key, &err))
                        goto bad;
                    if (row.key.empty()) {
                        err = "empty humans key";
                        goto bad;
                    }
                } else if (key == "castle_master") {
                    if (!getStr(L, rt, "prof", &row.prof, &err))
                        goto bad;
                    static const char* const kProfs[] = {
                        "cleric", "druid", "fighter", "paladin",
                        "ranger", "magic_user", "illusionist",
                        "thief", "assassin", "monk_bard",
                        nullptr };
                    bool ok = false;
                    for (int p = 0; kProfs[p]; ++p)
                        if (row.prof == kProfs[p]) { ok = true; break; }
                    if (!ok) {
                        err = "unknown profession token '" + row.prof + "'";
                        goto bad;
                    }
                    lua_getfield(L, rt, "level");
                    if (!lua_istable(L, -1)
                        || (int)lua_rawlen(L, -1) != 2) {
                        err = "level must be a {lo, hi} pair";
                        lua_pop(L, 1);
                        goto bad;
                    }
                    long long lv[2];
                    for (int j = 0; j < 2; ++j) {
                        lua_rawgeti(L, -1, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "level pair field is not an integer";
                            goto bad;
                        }
                        lv[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);
                    if (lv[0] < 1 || lv[1] < lv[0] || lv[1] > 23) {
                        err = "level outside 1-23";
                        goto bad;
                    }
                    row.lvlLo = (int)lv[0]; row.lvlHi = (int)lv[1];
                } else if (key == "castle_artillery") {
                    if (!getStr(L, rt, "type", &row.type, &err))
                        goto bad;
                    if (row.type.empty()) {
                        err = "empty artillery type";
                        goto bad;
                    }
                    static const char* const kCounts[3] = {
                        "ballistae", "lightCatapults",
                        "oilCauldrons" };
                    long long cv[3];
                    for (int j = 0; j < 3; ++j) {
                        lua_getfield(L, rt, kCounts[j]);
                        if (!lua_isinteger(L, -1)) {
                            err = std::string(kCounts[j])
                                + " is not an integer";
                            goto bad;
                        }
                        cv[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                        if (cv[j] < 0 || cv[j] > 100) {
                            err = std::string(kCounts[j])
                                + " outside 0-100";
                            goto bad;
                        }
                    }
                    row.n1 = (int)cv[0];
                    row.n2 = (int)cv[1];
                    row.n3 = (int)cv[2];
                } else {
                    // castle_inh_small / medium / large
                    if (!getStr(L, rt, "cat", &row.cat, &err))
                        goto bad;
                    if (row.cat != "totally_deserted"
                        && row.cat != "deserted_monster"
                        && row.cat != "humans"
                        && row.cat != "character_types") {
                        err = "unknown category token '" + row.cat + "'";
                        goto bad;
                    }
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (banded && prev != 100) { err = "bands do not reach 100";
                                         goto bad; }
            if (m_castle.count(key)) { err = "duplicate def key";
                                       goto bad; }
            m_castle[key] = rows;
        }
"""

CPP_ACC_ANCHOR = """EncounterTableRegistry::planarBands(
    const std::string& name) const {
    static const std::vector<EncounterPlanarBand> none;
    auto it = m_planarBands.find(name);
    return it == m_planarBands.end() ? none : it->second;
}"""
CPP_ACC_NEW = CPP_ACC_ANCHOR + """

bool EncounterTableRegistry::hasCastle(
    const std::string& name) const {
    return m_castle.count(name) != 0;
}

const std::vector<EncounterCastleRow>&
EncounterTableRegistry::castleRows(
    const std::string& name) const {
    static const std::vector<EncounterCastleRow> none;
    auto it = m_castle.find(name);
    return it == m_castle.end() ? none : it->second;
}"""


def extend_registry():
    with open(REG_H, encoding="utf-8") as f:
        h = f.read()
    h = replace_once(h, H_COMMENT_OLD, H_COMMENT_NEW,
                     "registry .h writers comment")
    h = replace_once(h, H_STRUCT_ANCHOR, H_STRUCT_NEW,
                     "registry .h struct anchor")
    h = replace_once(h, H_ACC_ANCHOR, H_ACC_NEW,
                     "registry .h accessor anchor")
    h = replace_once(h, H_MEM_ANCHOR, H_MEM_NEW,
                     "registry .h member anchor")
    with open(REG_H, "w", encoding="utf-8") as f:
        f.write(h)

    with open(REG_CPP, encoding="utf-8") as f:
        cpp = f.read()
    cpp = replace_once(cpp, CPP_KEYS_ANCHOR, CPP_KEYS_NEW,
                       "registry .cpp keys anchor")
    cpp = replace_once(cpp, CPP_ELSE_ANCHOR,
                       CPP_BRANCH + CPP_ELSE_ANCHOR,
                       "registry .cpp loader anchor")
    cpp = replace_once(cpp, CPP_ACC_ANCHOR, CPP_ACC_NEW,
                       "registry .cpp accessor anchor")
    with open(REG_CPP, "w", encoding="utf-8") as f:
        f.write(cpp)


# ---------------------------------------------------------------------------
# 4. the encounters.cpp seam + the two load/include anchors
# ---------------------------------------------------------------------------

ENC_LOAD_ANCHOR = ('        reg.loadDirectory('
                   '"content/tables/encounters_psionic");')
ENC_LOAD_NEW = (ENC_LOAD_ANCHOR + '\n'
                '        reg.loadDirectory('
                '"content/tables/encounters_castle");')

REGTEST_OLD = ('    #include "rules/audits/'
               'r1037_psionic_encounter_registry.h"  // R1037')
REGTEST_NEW = (REGTEST_OLD + '\n'
               '    #include "rules/audits/'
               'r1038_castle_encounter_registry.h"  // R1038')


def seam_note():
    return """// R1038 (the registry-native de-wire, the R1032-R1037
// shape): the five printed tables retired into
// content/tables/encounters_castle/ - CASTLE TABLE I
// (size class and type) into castle_type.lua, the per-size
// CASTLE TABLE II into castle_inh_small/medium/large.lua,
// SUB-TABLE II.A into castle_humans.lua, SUB-TABLE II.B
// into castle_master.lua, the ARTILLERY table into
// castle_artillery.lua. One registry row shape
// (EncounterCastleRow) carries all five; the enums ride as
// printed tokens, mapped here. The public signatures are
// unchanged (game/state_overland.cpp calls them); what
// stays here is the mechanics: the percentile lookups
// (rewritten onto castleView), the registry noAppearing
// fallback (R60), the master/henchmen construction
// (R53/R55/R62), the shell-keep artillery fallback, the
// surprise-die awareness mapping, and the patrol
// construction (no table).

namespace {

// the registry-backed static cache (the R1032-R1037 idiom)
static const std::vector<dm::EncounterCastleRow>& castleView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterCastleRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, dm::encReg().castleRows(name)).first;
    return it->second;
}

// the printed tokens -> the engine enums. The defensive
// defaults mirror the retired fallbacks: the large
// inhabitants table served the retired default case, an
// unknown category reads as totally deserted, an unknown
// profession reads as fighter (the classForProf default).
static CastleSize sizeForToken(const std::string& t) {
    if (t == "small") return CASTLE_SMALL;
    if (t == "medium") return CASTLE_MEDIUM;
    return CASTLE_LARGE;
}

static CastleInhabitants catForToken(const std::string& t) {
    if (t == "deserted_monster") return CASTLE_DESERTED_MONSTER;
    if (t == "humans") return CASTLE_HUMANS;
    if (t == "character_types") return CASTLE_CHARACTER_TYPES;
    return CASTLE_TOTALLY_DESERTED;
}

static int profForToken(const std::string& t) {
    if (t == "cleric")       return PROF_CLERIC;
    if (t == "druid")        return PROF_DRUID;
    if (t == "paladin")      return PROF_PALADIN;
    if (t == "ranger")       return PROF_RANGER;
    if (t == "magic_user")   return PROF_MU;
    if (t == "illusionist")  return PROF_ILLUSIONIST;
    if (t == "thief")        return PROF_THIEF;
    if (t == "assassin")     return PROF_ASSASSIN;
    if (t == "monk_bard")    return PROF_MONK_BARD;
    return PROF_FIGHTER;
}

} // namespace

CastleType rollCastleType(int pctile) {
    CastleType t{};
    for (const auto& r : castleView("castle_type"))
        if (pctile >= r.lo && pctile <= r.hi) {
            t.size = sizeForToken(r.size);
            t.type = r.type.c_str();
            return t;
        }
    return t;   // defensive: column covers 01-00
}

CastleInhabitants castleInhabitants(int pctile, CastleSize size) {
    const char* table = "castle_inh_large";
    if (size == CASTLE_SMALL)       table = "castle_inh_small";
    else if (size == CASTLE_MEDIUM) table = "castle_inh_medium";
    for (const auto& r : castleView(table))
        if (pctile >= r.lo && pctile <= r.hi)
            return catForToken(r.cat);
    return CASTLE_TOTALLY_DESERTED;   // defensive
}

const char* castleHumansType(int pctile) {
    for (const auto& r : castleView("castle_humans"))
        if (pctile >= r.lo && pctile <= r.hi)
            return r.key.c_str();
    return "bandit";   // defensive
}

int castleHumansCount(const monsters::MonsterRegistry& reg,
                      rules::Dice& dice, const char* key) {
    // "Numbers and other details of these humans are given in
    // the MONSTER MANUAL under the heading of MEN" - registry
    // noAppearing (R60 convention; 0/0 -> single specimen)
    const monsters::MonsterDef* def = reg.find(key);
    if (!def) return 1;
    if (def->noAppearingMin > 0) {
        int lo = def->noAppearingMin;
        int hi = def->noAppearingMax < lo ? lo : def->noAppearingMax;
        return (lo == hi)
            ? lo
            : lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
    }
    return 1;
}

// the stronghold's master per Sub-Table II.B - class by
// percentile, level uniform over the printed range, race per
// R62, magic items per the R55 ladder (the book's Character
// Subtable pointer).
PartyMember rollCastleMaster(rules::Dice& dice, int pctile) {
    PartyMember m;
    const dm::EncounterCastleRow* row = nullptr;
    for (const auto& r : castleView("castle_master"))
        if (pctile >= r.lo && pctile <= r.hi)
            { row = &r; break; }
    if (!row) return m;   // defensive: column covers 01-00
    m.classIndex = classForProf(profForToken(row->prof));
    m.level = (row->lvlLo == row->lvlHi)
        ? row->lvlLo
        : row->lvlLo + (int)dice.roll(
              1, (uint32_t)(row->lvlHi - row->lvlLo + 1), 0) - 1;
    m.race = rollNpcRace(dice, m.classIndex);   // R62
    rollMagicItemsFor(dice, m);                 // R55
    return m;
}

// the master's henchmen - "from 2-5 henchmen found
// within a fortress," levels and magic items per the
// Character Subtable (henchmanLevelFor, one-third of
// the master's, R53; R62 race follows the master's folk where
// the class allows - the R63 convention).
CharacterParty rollCastleHenchmen(rules::Dice& dice,
                                  const PartyMember& master) {
    CharacterParty p;
    int n = 1 + (int)dice.roll(1, 4, 0);           // 2-5
    for (int i = 0; i < n; ++i) {
        PartyMember m;
        m.henchman = true;
        m.classIndex = master.classIndex;   // the master's own
        m.level = henchmanLevelFor(master.level);
        m.race = raceAllowsClass(master.race, m.classIndex)
               ? master.race
               : rollNpcRace(dice, m.classIndex);
        rollMagicItemsFor(dice, m);               // R55
        p.members.push_back(m);
    }
    return p;
}

// the artillery of the fortress, per the printed table.
// The book's eight rows group the nine castle types; the
// engine maps by nearest type (concentric -> the medium
// concentric row; large walled / fortress complex -> the
// large castle row), documented.
CastleArtillery castleArtillery(const CastleType& castle) {
    const auto& rows = castleView("castle_artillery");
    for (const auto& r : rows)
        if (r.type == castle.type)
            return { r.n1, r.n2, r.n3 };
    // shell keeps share a row keyed "shell keep" (documented)
    if (std::string(castle.type).find("shell keep") !=
        std::string::npos)
        for (const auto& r : rows)
            if (r.type == "shell keep")
                return { r.n1, r.n2, r.n3 };
    return { 0, 0, 0 };
}

// fortress detection per the p.183 rule - "roll a
// surprise die ... if they are surprised, then the fortress
// occupants know they are there - if surprise is 2 or
// greater, the occupants are actually outside the place and
// within normal surprise distance." The standard 1e
// surprise die is 1d6; 1 = surprised (occupants aware),
// 2 = surprised and the occupants are outside, 3+ = not
// detected.
CastleAwareness castleAwareness(int surpriseDie) {
    if (surpriseDie <= 1) return CASTLE_OCCUPANTS_AWARE;
    if (surpriseDie == 2) return CASTLE_OCCUPANTS_OUTSIDE;
    return CASTLE_UNDETECTED;
}

// build a patrol per the p.182 text - fighter (or
// ranger) leader 6th-8th, lieutenant 4th-5th, sergeant
// 2nd-3rd, 3-4 1st-level men, 13-24 men-at-arms, plus a
// cleric 6th-7th (40%) or magic-user 5th-8th (60%). Classed
// members roll R62 races and R55 magic items (the book's
// Character Subtable pointer); men-at-arms are 0-level
// humans (R53). Arms/armor fiction is not itemized
// (documented).
CharacterParty rollPatrol(rules::Dice& dice, bool rangerLeader) {
    CharacterParty p;
    auto add = [&](int classIndex, int level) {
        PartyMember m;
        m.classIndex = classIndex;
        m.level = level;
        m.race = rollNpcRace(dice, classIndex);   // R62
        rollMagicItemsFor(dice, m);               // R55
        p.members.push_back(m);
    };
    auto addMan = [&](int level, int count) {
        for (int i = 0; i < count; ++i) {
            PartyMember m;
            m.manAtArms = true;
            m.classIndex = rules::CLASS_FIGHTER;
            m.level = level;
            m.race = RACE_HUMAN;   // R53 convention
            p.members.push_back(m);
        }
    };

    // leader: fighter 6-8 (or ranger where applicable)
    int leadLvl = 5 + (int)dice.roll(1, 3, 0);
    add(rangerLeader ? rules::CLASS_FIGHTER : rules::CLASS_FIGHTER,
        leadLvl);   // ranger kit not carried by classIndex (R53)
    // lieutenant 4-5, sergeant 2-3
    add(rules::CLASS_FIGHTER, 3 + (int)dice.roll(1, 2, 0));
    add(rules::CLASS_FIGHTER, 1 + (int)dice.roll(1, 2, 0));
    // 3-4 1st-level men
    addMan(1, 2 + (int)dice.roll(1, 2, 0));
    // 13-24 men-at-arms (0-level, R53 shapes)
    addMan(0, 12 + (int)dice.roll(1, 12, 0));
    // cleric 6-7 (40%) or magic-user 5-8 (60%)
    if ((int)dice.roll(1, 100, 0) <= 40)
        add(rules::CLASS_CLERIC, 5 + (int)dice.roll(1, 2, 0));
    else
        add(rules::CLASS_MAGIC_USER, 4 + (int)dice.roll(1, 4, 0));
    return p;
}

"""


def seam_body(c67, tail_ws):
    # seam_note ends with the brace line's own newline plus
    # one blank line; rstrip + tail_ws preserves the retired
    # region's byte-exact spacing before the R74 header
    return (c67 + "\n" + seam_note().rstrip("\n")
            + tail_ws)


# ---------------------------------------------------------------------------
# 5. the fragment (7 sections, derived pins)
# ---------------------------------------------------------------------------

CAT_CPP = {"totally_deserted": "dm::CASTLE_TOTALLY_DESERTED",
           "deserted_monster": "dm::CASTLE_DESERTED_MONSTER",
           "humans": "dm::CASTLE_HUMANS",
           "character_types": "dm::CASTLE_CHARACTER_TYPES"}
SIZE_CPP = {"small": "dm::CASTLE_SMALL",
            "medium": "dm::CASTLE_MEDIUM",
            "large": "dm::CASTLE_LARGE"}
CLASS_CPP = {"cleric": "rules::CLASS_CLERIC",
             "druid": "rules::CLASS_CLERIC",
             "magic_user": "rules::CLASS_MAGIC_USER",
             "illusionist": "rules::CLASS_MAGIC_USER",
             "thief": "rules::CLASS_THIEF",
             "assassin": "rules::CLASS_THIEF",
             "monk_bard": "rules::CLASS_THIEF",
             "fighter": "rules::CLASS_FIGHTER",
             "paladin": "rules::CLASS_FIGHTER",
             "ranger": "rules::CLASS_FIGHTER"}


def idx_of(table, pos):
    for i, r in enumerate(table):
        if pos == r[0] or pos == r[1]:
            return i
    die("pin index not derivable at %r" % (pos,))


def build_fragment(table_type, table_inh, table_humans,
                   table_master, table_artillery):
    L = []
    A = L.append

    # -- derived pin lines (plain appends only - the R1037
    #    %% leak lesson: no % formatting of template blocks) --
    def pin_row(view, i, lo, hi, checks):
        s = "        { const int i = %d; const auto& r = %s[i];\n" \
            % (i, view)
        s += "          if (r.lo != %d || r.hi != %d) ++bad;\n" \
             % (lo, hi)
        for c in checks:
            s += "          if (%s) ++bad;\n" % c
        s += "        }\n"
        return s

    type_pins = "".join(
        pin_row("rt", idx_of(table_type, lo), lo, hi,
                ['r.size != "%s"' % size,
                 'r.type != "%s"' % typ])
        for lo, hi, size, typ in
        (table_type[0], table_type[2], table_type[6],
         table_type[8]))
    master_pins = "".join(
        pin_row("rm", idx_of(table_master, lo), lo, hi,
                ['r.prof != "%s"' % prof,
                 "r.lvlLo != %d || r.lvlHi != %d" % (a, b)])
        for lo, hi, prof, a, b in
        (table_master[8], table_master[9], table_master[10],
         table_master[0], table_master[5]))
    humans_pins = "".join(
        pin_row("rh", idx_of(table_humans, lo), lo, hi,
                ['r.key != "%s"' % key])
        for lo, hi, key in table_humans)
    art_pins = "".join(
        "        { const auto& r = ra[%d];\n"
        "          if (r.type != \"%s\") ++bad;\n"
        "          if (r.n1 != %d || r.n2 != %d || r.n3 != %d)"
        " ++bad; }\n" % (i, typ, n1, n2, n3)
        for i, (typ, n1, n2, n3) in enumerate(table_artillery)
        if typ in ("moat house or friary", "shell keep",
                   "fortress complex"))

    # the per-size inhabitants expectation lines (derived)
    inh_pins = ""
    for size in SIZES:
        for lo, hi, cat in table_inh[size]:
            inh_pins += (
                "        if (dm::castleInhabitants(%d, "
                "%s) != %s) ++bad;\n"
                % (lo, SIZE_CPP[size], CAT_CPP[cat]))
            inh_pins += (
                "        if (dm::castleInhabitants(%d, "
                "%s) != %s) ++bad;\n"
                % (hi, SIZE_CPP[size], CAT_CPP[cat]))

    # the type -> expected artillery mapping (derived, incl.
    # the shell-keep fallback)
    art_of = {}
    for typ, n1, n2, n3 in table_artillery:
        art_of[typ] = (n1, n2, n3)
    art_expect = []
    for lo, hi, size, typ in table_type:
        if typ in art_of:
            art_expect.append((lo, hi, typ,
                               art_of[typ]))
        else:
            # "small shell keep" / "large shell keep" -> the
            # shared "shell keep" row (documented)
            art_expect.append((lo, hi, typ,
                               art_of["shell keep"]))
    art_map_pins = "".join(
        "        { dm::CastleType t = "
        "dm::rollCastleType(%d);\n"
        "          dm::CastleArtillery a = "
        "dm::castleArtillery(t);\n"
        "          if (a.ballistae != %d"
        " || a.lightCatapults != %d"
        " || a.oilCauldrons != %d) ++bad; }\n"
        % (lo, n1, n2, n3)
        for lo, hi, typ, (n1, n2, n3) in art_expect)

    # the master expectation lines (derived)
    master_roll = "".join(
        "        { dm::PartyMember m = "
        "dm::rollCastleMaster(dice, %d);\n"
        "          if (m.level < %d || m.level > %d) ++bad;\n"
        "          if (m.classIndex != %s) ++bad; }\n"
        % (lo, a, b, CLASS_CPP[prof])
        for lo, hi, prof, a, b in table_master)

    A("""// ============================================================================
// Adnd1 - rules/audits/r1038_castle_encounter_registry.h  (R1038)
// The R67 castle family battery audit, the R1032-R1037
// shape: the registry load, exact table counts and the
// percentile chains, derived row spot pins (incl. the
// corrected Assassin/Monk/Bard overlap), the per-size
// inhabitants mapping, the master's class and level, the
// artillery and awareness mapping, and the roll/patrol
// path. Expected: 7 castle files - CASTLE TABLE I (9
// rows), the three per-size TABLE II sub-tables (4 rows
// each), SUB-TABLE II.A (4 rows), SUB-TABLE II.B (11
// rows) and the ARTILLERY table (8 rows) - all derived
// from the DMG record (Premium reprint p.182-183) the
// splice parsed. The enums ride as printed tokens; the
// master/henchmen/patrol construction (R53/R55/R62) and
// the noAppearing fallback (R60) stay engine-side.
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 7 castle files, zero errors, one reg --
    bad = 0;
    {
        const int kf = ereg.loadDirectory(
            "content/tables/encounters_castle");
        if (kf != 7) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int df = ereg.loadDirectory(
            "content/tables/encounters");
        if (df != 20) ++bad;
        const int wf = ereg.loadDirectory(
            "content/tables/encounters_water");
        if (wf != 9) ++bad;
        const int of = ereg.loadDirectory(
            "content/tables/encounters_outdoor");
        if (of != 21) ++bad;
        const int cf = ereg.loadDirectory(
            "content/tables/encounters_city");
        if (cf != 9) ++bad;
        const int xf = ereg.loadDirectory(
            "content/tables/encounters_planar");
        if (xf != 5) ++bad;
        const int pf = ereg.loadDirectory(
            "content/tables/encounters_psionic");
        if (pf != 2) ++bad;
        if (!ereg.hasCastle("castle_type")) ++bad;
        if (!ereg.hasCastle("castle_inh_small")) ++bad;
        if (!ereg.hasCastle("castle_inh_medium")) ++bad;
        if (!ereg.hasCastle("castle_inh_large")) ++bad;
        if (!ereg.hasCastle("castle_humans")) ++bad;
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasCastle("castle_artillery")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys stay exclusive on every side)
        if (ereg.hasCastle("")) ++bad;
        if (ereg.hasCastle("castle_picks")) ++bad;
        if (ereg.hasPlanar("castle_type")) ++bad;
        if (ereg.hasPlanarBands("castle_type")) ++bad;
        if (ereg.hasWater("castle_type")) ++bad;
        if (ereg.hasOutdoor("castle_type")) ++bad;
        if (ereg.hasCityBands("castle_type")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1038 castle encounter registry load audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed columns --------
    bad = 0;
    {
        if ((int)ereg.castleRows("castle_type").size() != 9)
            ++bad;
        if ((int)ereg.castleRows("castle_inh_small").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_inh_medium").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_inh_large").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_humans").size()
            != 4) ++bad;
        if ((int)ereg.castleRows("castle_master").size()
            != 11) ++bad;
        if ((int)ereg.castleRows("castle_artillery").size()
            != 8) ++bad;
        // one row per percentile, per percentile table
        const char* const banded[6] = {
            "castle_type", "castle_inh_small",
            "castle_inh_medium", "castle_inh_large",
            "castle_humans", "castle_master" };
        for (int b = 0; b < 6; ++b) {
            const auto& rs = ereg.castleRows(banded[b]);
            int lo = 1;
            for (const auto& r : rs) {
                if (r.lo != lo) ++bad;          // contiguous
                if (r.hi < r.lo || r.hi > 100) ++bad;
                lo = r.hi + 1;
            }
            if (lo != 101) ++bad;                // 01-00
        }
        // the master's level ranges stay printed
        for (const auto& r :
             ereg.castleRows("castle_master"))
            if (r.lvlLo < 1 || r.lvlHi < r.lvlLo
                || r.lvlHi > 23) ++bad;
        // the artillery counts stay non-negative
        for (const auto& r :
             ereg.castleRows("castle_artillery"))
            if (r.n1 < 0 || r.n2 < 0 || r.n3 < 0) ++bad;
    }
    printf("R1038 castle encounter registry counts audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 3. pins: spot pins derived from the parsed record
    bad = 0;
    {
        const auto& rt = ereg.castleRows("castle_type");
        const auto& rm = ereg.castleRows("castle_master");
        const auto& rh = ereg.castleRows("castle_humans");
        const auto& ra = ereg.castleRows("castle_artillery");
""")
    A(type_pins)
    A(master_pins)
    A(humans_pins)
    A(art_pins)
    A("""    }
    printf("R1038 castle encounter registry pins audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 4. inhabitants: the per-size mapping -----------
    bad = 0;
    {
""")
    A(inh_pins)
    A("""        // the defensive fallbacks (the retired defaults)
        if (dm::castleInhabitants(101,
                dm::CASTLE_SMALL)
            != dm::CASTLE_TOTALLY_DESERTED) ++bad;
    }
    printf("R1038 castle encounter registry inhabitants audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 5. master: class and level per the record ------
    bad = 0;
    {
        rules::Rng rng(1038);
        rules::Dice dice(rng);
""")
    A(master_roll)
    A("""        // the OCR-corrected rows are the pins: assassin
        // 94-96 (level 14), monk 97-99 (9-12), bard 00
        // (level 23 exactly)
        { dm::PartyMember a = dm::rollCastleMaster(dice, 95);
          if (a.level != 14) ++bad;
          if (a.classIndex != rules::CLASS_THIEF) ++bad; }
        { dm::PartyMember m = dm::rollCastleMaster(dice, 98);
          if (m.level < 9 || m.level > 12) ++bad; }
        { dm::PartyMember b = dm::rollCastleMaster(dice, 100);
          if (b.level != 23) ++bad;
          if (b.classIndex != rules::CLASS_THIEF) ++bad; }
        // henchmen: 2-5, all flagged, the master's class
        { dm::PartyMember m = dm::rollCastleMaster(dice, 21);
          dm::CharacterParty h =
              dm::rollCastleHenchmen(dice, m);
          if ((int)h.members.size() < 2
              || (int)h.members.size() > 5) ++bad;
          for (const auto& x : h.members) {
              if (!x.henchman) ++bad;
              if (x.classIndex != m.classIndex) ++bad;
          } }
    }
    printf("R1038 castle encounter registry master audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 6. artillery + awareness -----------------------
    bad = 0;
    {
""")
    A(art_map_pins)
    A("""        // the shell-keep fallback: both shell rows share
        // the "shell keep" artillery row (documented)
        { dm::CastleType t;
          t.size = dm::CASTLE_SMALL;
          t.type = "small shell keep";
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 1
              || a.oilCauldrons != 2) ++bad; }
        // an unknown type carries no artillery
        { dm::CastleType t;
          t.size = dm::CASTLE_LARGE;
          t.type = "windmill";
          dm::CastleArtillery a = dm::castleArtillery(t);
          if (a.ballistae != 0 || a.lightCatapults != 0
              || a.oilCauldrons != 0) ++bad; }
        // awareness: 1 = aware, 2 = outside, 3+ = undetected
        if (dm::castleAwareness(1) !=
            dm::CASTLE_OCCUPANTS_AWARE) ++bad;
        if (dm::castleAwareness(0) !=
            dm::CASTLE_OCCUPANTS_AWARE) ++bad;
        if (dm::castleAwareness(2) !=
            dm::CASTLE_OCCUPANTS_OUTSIDE) ++bad;
        if (dm::castleAwareness(3) !=
            dm::CASTLE_UNDETECTED) ++bad;
        if (dm::castleAwareness(6) !=
            dm::CASTLE_UNDETECTED) ++bad;
    }
    printf("R1038 castle encounter registry artillery audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 7. roll: the sweep + the patrol smoke ----------
    bad = 0;
    {
        rules::Rng rng(1038);
        rules::Dice dice(rng);
        // rollCastleType sweep: every percentile produces
        // the row that carries it
        for (const auto& r :
             ereg.castleRows("castle_type"))
            for (int pct = r.lo; pct <= r.hi; ++pct) {
                dm::CastleType t =
                    dm::rollCastleType(pct);
                if (std::string(t.type) != r.type) ++bad;
                if (t.size !=
                    (r.size == "small"
                     ? dm::CASTLE_SMALL
                     : (r.size == "medium"
                        ? dm::CASTLE_MEDIUM
                        : dm::CASTLE_LARGE))) ++bad;
            }
        // castleHumansType sweep: the three bestiary keys,
        // all resolvable in the registry
        for (const auto& r :
             ereg.castleRows("castle_humans"))
            for (int pct = r.lo; pct <= r.hi; ++pct) {
                const char* key =
                    dm::castleHumansType(pct);
                if (std::string(key) != r.key) ++bad;
                if (!reg.find(key)) ++bad;
            }
        // castleHumansCount: the registry noAppearing
        // range (the R60 convention), dynamic
        for (const auto& r :
             ereg.castleRows("castle_humans")) {
            const monsters::MonsterDef* def =
                reg.find(r.key);
            if (!def) { ++bad; continue; }
            for (int i = 0; i < 40; ++i) {
                const int c = dm::castleHumansCount(
                    reg, dice, r.key.c_str());
                if (def->noAppearingMin > 0) {
                    const int lo = def->noAppearingMin;
                    const int hi =
                        def->noAppearingMax < lo
                        ? lo : def->noAppearingMax;
                    if (c < lo || c > hi) ++bad;
                } else if (c != 1) ++bad;
            }
        }
        // rollPatrol smoke: the printed shape
        for (int i = 0; i < 200; ++i) {
            dm::CharacterParty p =
                dm::rollPatrol(dice, i % 2 != 0);
            const int n = (int)p.members.size();
            if (n < 20 || n > 34) ++bad;
            if (p.members[0].level < 6
                || p.members[0].level > 8) ++bad;
            if (p.members[0].classIndex
                != rules::CLASS_FIGHTER) ++bad;
            if (p.members[1].level < 4
                || p.members[1].level > 5) ++bad;
            if (p.members[2].level < 2
                || p.members[2].level > 3) ++bad;
            int men = 0;
            for (const auto& m : p.members)
                if (m.manAtArms) ++men;
            if (men < 16 || men > 28) ++bad;
        }
        // rollCastleMaster smoke: levels stay printed
        for (int i = 0; i < 2000; ++i) {
            dm::PartyMember m = dm::rollCastleMaster(
                dice, 1 + i % 100);
            if (m.level < 9 || m.level > 23) ++bad;
        }
    }
    printf("R1038 castle encounter registry roll audit: bad %d\\n", bad);
    if (bad) return 1;

}
""")
    text = "".join(L)
    n = text.count("audit: bad %d")
    if n != 7:
        die("fragment carries %d census patterns (expected 7)"
            % n)
    return text


# ---------------------------------------------------------------------------
# 6. census + brace balance + main
# ---------------------------------------------------------------------------

CENSUS_PRE = 983
CENSUS_POST = 990


def census_count():
    n = 0
    files = sorted(glob.glob(os.path.join(
        ROOT, "rules", "audits", "*.h")))
    files.append(REGTEST)
    for p in files:
        with open(p, encoding="utf-8") as f:
            n += f.read().count("audit: bad %d")
    return n


def brace_balance(path):
    with open(path, encoding="utf-8") as f:
        src = f.read()
    # strip line comments, string and char literals, then
    # the braces must balance (the R1035 gate)
    src = re.sub(r"//[^\n]*", "", src)
    src = re.sub(r'"(?:\\.|[^"\\])*"', '""', src)
    src = re.sub(r"'(?:\\.|[^'\\])*'", "''", src)
    a, b = src.count("{"), src.count("}")
    if a != b:
        die("%s: brace balance %d vs %d"
            % (os.path.basename(path), a, b))


def main():
    # -- idempotence gate ----------------------------------
    with open(REG_H, encoding="utf-8") as f:
        h = f.read()
    if ("// tools/r1038_splice.py (castle family)"
            in h):
        # already applied: verify the landing state
        with open(ENC, encoding="utf-8") as f:
            enc = f.read()
        if "kCastleTypeTable" in enc:
            die("already applied but kCastleTypeTable is "
                "still in dm/encounters.cpp")
        if census_count() != CENSUS_POST:
            die("already applied but census is %d "
                "(expected %d)"
                % (census_count(), CENSUS_POST))
        for name in ("castle_type.lua", "castle_inh_small.lua",
                     "castle_inh_medium.lua", "castle_inh_large.lua",
                     "castle_humans.lua", "castle_master.lua",
                     "castle_artillery.lua"):
            if not os.path.isfile(os.path.join(LUA_DIR,
                                               name)):
                die("already applied but %s is missing"
                    % name)
        print("applied 0, already 1")
        print("SPLICE OK")
        return
    if census_count() != CENSUS_PRE:
        die("pre-census is %d (expected %d)"
            % (census_count(), CENSUS_PRE))

    # -- parse + gates --------------------------------------
    with open(ENC, encoding="utf-8") as f:
        src = f.read()
    (i0, i1, table_type, table_inh, table_humans,
     table_master, table_artillery, c67, tail_ws) = \
        parse_castle_region(src)
    problems = gate_data(table_type, table_inh,
                        table_humans, table_master,
                        table_artillery)
    if problems:
        die("data gate: %s" % "; ".join(problems))
    print("parsed: castle type %d rows, inhabitants "
          "4/4/4, humans %d, master %d, artillery %d"
          % (len(table_type), len(table_humans),
             len(table_master), len(table_artillery)))

    # -- lua + registry -------------------------------------
    emit_lua(table_type, table_inh, table_humans,
             table_master, table_artillery)
    lua_roundtrip(table_type, table_inh, table_humans,
                  table_master, table_artillery)
    print("round-trip: %d lua files parse back byte-exact"
          % FILES)
    extend_registry()

    # -- the encounters.cpp seam ----------------------------
    new_enc = (src[:i0] + seam_body(c67, tail_ws)
               + src[i1:])
    new_enc = replace_once(new_enc, ENC_LOAD_ANCHOR,
                           ENC_LOAD_NEW, "enc load anchor")
    for tok in RETIRED_TOKENS:
        if tok in new_enc:
            die("retired token %r survived the splice"
                % tok)
    with open(ENC, "w", encoding="utf-8") as f:
        f.write(new_enc)

    # -- the fragment + the regtest include -----------------
    frag = build_fragment(table_type, table_inh,
                         table_humans, table_master,
                         table_artillery)
    with open(FRAG, "w", encoding="utf-8") as f:
        f.write(frag)
    with open(REGTEST, encoding="utf-8") as f:
        rt = f.read()
    rt = replace_once(rt, REGTEST_OLD, REGTEST_NEW,
                     "regtest include")
    with open(REGTEST, "w", encoding="utf-8") as f:
        f.write(rt)

    # -- gates ----------------------------------------------
    for p in (ENC, REG_H, REG_CPP, REGTEST, FRAG):
        brace_balance(p)
    post = census_count()
    if post != CENSUS_POST:
        die("post-census is %d (expected %d)"
            % (post, CENSUS_POST))
    print("census: %d -> %d audit printf patterns"
          % (CENSUS_PRE, post))
    print("applied 1, rewrote 4 tracked files, "
          "wrote %d new files" % FILES)
    print("SPLICE OK")


if __name__ == "__main__":
    main()
