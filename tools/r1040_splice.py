#!/usr/bin/env python3
# r1040_splice.py - R1040: the DMG Appendix P convention-party
# kit tables de-wire (the R1032-R1039 shape; census 997 -> 1004).
#
# dm/appendixp.h (header-only, the R147/R156 convention-party
# module) retires its eight printed tables into
# content/tables/appendixp/: the three-band level options
# (p.225, 3x3 lo/hi) into appendixp_band_level.lua, the
# PROTECTIVE ITEMS and WEAPONS per-class chance columns
# (p.225-226, 4x7 each, transposed to one row per printed
# column) into appendixp_protective.lua and
# appendixp_weapons.lua, the POTION chance/max columns (p.226)
# into appendixp_potions.lua, the ten printed potion types
# into appendixp_potion_types.lua, and the kit builder's
# armor/weapon/shield chances into appendixp_kit.lua. One new
# registry row shape (EncounterAppendixPRow) carries all six
# files. The seam is header-only like the module: an inline
# apReg() singleton (function-local statics in inline
# functions are shared across TUs) self-loads the directory -
# encReg() in encounters.cpp is file-static and stays
# untouched, so no ENC_LOAD line. Every public signature
# stays (rules/audits/r147_appendix_p.h and
# r156_convention_party.h pin them); the mechanics stay
# verbatim: abilityRoll, the itemChance chain (incl. the
# Gonzo worked example), rollItemPlus, MemberMagic,
# SpurMember and rollSpurMember. Fragment: rules/audits/
# r1040_appendixp_registry.h (7 sections, census +7).
import glob
import hashlib
import os
import re
import sys

ROOT = os.getcwd()
AP = os.path.join(ROOT, "dm", "appendixp.h")
REG_H = os.path.join(ROOT, "dm", "EncounterTableRegistry.h")
REG_CPP = os.path.join(ROOT, "dm", "EncounterTableRegistry.cpp")
REGTEST = os.path.join(ROOT, "regtest.cpp")
LUA_DIR = os.path.join(ROOT, "content", "tables", "appendixp")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1040_appendixp_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory (asserted against the source at parse time)
# ---------------------------------------------------------------------------

N_BAND = 9          # 3 bands x 3 options
N_GEAR = 7          # printed columns per gear table
N_POTIONS = 4       # classes
N_TYPES = 10
N_KIT = 4
FILES = 6           # lua files in appendixp/

# the printed tables, PARSED from the header; these expected
# shapes gate the parse (the R1035 never-recall lesson)
WANT_BAND = [
    (1, 1, 1, 2), (1, 2, 1, 3), (1, 3, 2, 4),
    (2, 1, 5, 7), (2, 2, 5, 8), (2, 3, 7, 9),
    (3, 1, 8, 10), (3, 2, 8, 11), (3, 3, 9, 12),
]
WANT_PROTECTIVE = [
    (1, 10, 0, 10, 0), (2, 6, 0, 5, 0), (3, 8, 0, 6, 0),
    (4, 10, 0, 8, 0), (5, 0, 0, 0, 10), (6, 0, 15, 2, 4),
    (7, 0, 4, 0, 0),
]
WANT_WEAPONS = [
    (1, 10, 15, 0, 12), (2, 10, 0, 0, 11), (3, 0, 0, 12, 0),
    (4, 7, 0, 0, 0), (5, 8, 0, 0, 0), (6, 1, 0, 0, 0),
    (7, 10, 0, 0, 0),
]
WANT_POTIONS = [(1, 8, 1), (2, 10, 3), (3, 6, 1), (4, 9, 2)]
WANT_TYPES = [
    "Climbing", "Diminution", "Extra-Healing",
    "Fire Resistance", "Flying", "Gaseous Form", "Growth",
    "Healing", "Invisibility", "Polymorph Self",
]
WANT_KIT = [
    (1, 10, 10, 10), (2, 15, 15, 0), (3, 8, 12, 10),
    (4, 10, 11, 0),
]

# every source substring the retired header must carry
ASSERTS = [
    'inline int bandLevelLo(int band, int option) {',
    'inline int bandLevelHi(int band, int option) {',
    'static const int lo[3][3] = {',
    'static const int hi[3][3] = {',
    'inline int protectivePct(int classIndex, int col) {',
    'inline int weaponPct(int classIndex, int col) {',
    'inline int potionPct(int classIndex) {',
    'inline int potionMax(int classIndex) {',
    'inline const char* potionType(int roll) {',
    'static const char* const k[10] = {',
    'inline MemberMagic rollMemberMagic(rules::Dice& dice,',
    'static const int kArmor[4]',
    'static const int kWeapon[4]',
    'inline SpurMember rollSpurMember(rules::Dice& dice, int band,',
]

# full-declaration tokens: none may survive anywhere in the header
RETIRED_TOKENS = [
    "lo[3][3]",
    "hi[3][3]",
    "t[4][7]",
    "static const int t[4]",
    "k[10]",
    "kArmor",
    "kWeapon",
]


def die(msg):
    sys.stderr.write("r1040_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the printed tables out of dm/appendixp.h
# ---------------------------------------------------------------------------

def parse_appendixp(src):
    if "kArmor" not in src:
        die("kArmor not found (already spliced?)")
    for a in ASSERTS:
        if a not in src:
            die("assertion failed, dm/appendixp.h must "
                "carry %r" % a)

    def block(name):
        m = re.search(r"%s[^{]*\{(.*?)\n    \};" % re.escape(name),
                      src, re.S)
        if not m:
            die("table %s not found" % name)
        return m.group(1)

    # the printed arrays are 3 rows (bands) x 3 options
    def band_rows(name):
        rows = re.findall(r"\{\s*(\d+),\s*(\d+),\s*(\d+)\s*\}",
                         block(name))
        if len(rows) != 3:
            die("parsed %d %s band rows (expected 3)"
                % (len(rows), name))
        return [[int(x) for x in r] for r in rows]

    lo = band_rows("static const int lo[3][3]")
    hi = band_rows("static const int hi[3][3]")
    band = [(b + 1, o + 1, lo[b][o], hi[b][o])
            for b in range(3) for o in range(3)]
    if band != WANT_BAND:
        die("band level table drifted from the record")

    # the gear tables are 4 rows x 7 cols in the source; the
    # printed column is the transpose axis
    t_blocks = re.findall(
        r"static const int t\[4\]\[7\] = \{(.*?)\n    \};",
        src, re.S)
    if len(t_blocks) != 2:
        die("parsed %d t[4][7] tables (expected 2)"
            % len(t_blocks))

    def cols_of(blocktext):
        rows = re.findall(r"\{([^}]+)\}", blocktext)
        if len(rows) != 4:
            die("gear table: %d class rows (expected 4)"
                % len(rows))
        cols = []
        for c in range(7):
            v = []
            for r in rows:
                nums = [int(x) for x in re.findall(r"-?\d+", r)]
                if len(nums) != 7:
                    die("gear row carries %d values (expected 7)"
                        % len(nums))
                v.append(nums[c])
            cols.append((c + 1, v[0], v[1], v[2], v[3]))
        return cols

    protective = cols_of(t_blocks[0])
    weapons = cols_of(t_blocks[1])
    if protective != WANT_PROTECTIVE:
        die("protective table drifted from the record")
    if weapons != WANT_WEAPONS:
        die("weapons table drifted from the record")

    pot_blocks = re.findall(
        r"static const int t\[4\] = \{([^}]*)\};", src)
    if len(pot_blocks) != 2:
        die("parsed %d t[4] potion tables (expected 2)"
            % len(pot_blocks))
    pct = [int(x) for x in pot_blocks[0].split(",")]
    mx = [int(x) for x in pot_blocks[1].split(",")]
    potions = [(i + 1, pct[i], mx[i]) for i in range(4)]
    if potions != WANT_POTIONS:
        die("potion table drifted from the record")

    m = re.search(r"static const char\* const k\[10\] = \{(.*?)\};",
                  src, re.S)
    if not m:
        die("potion type table not found")
    types = re.findall(r'"([^"]+)"', m.group(1))
    if types != WANT_TYPES:
        die("potion types drifted from the record")

    m = re.search(r"static const int kArmor\[4\]\s*=\s*\{([^}]*)\};",
                  src)
    if not m:
        die("kArmor not parseable")
    armor = [int(x) for x in m.group(1).split(",")]
    m = re.search(r"static const int kWeapon\[4\]\s*=\s*\{([^}]*)\};",
                  src)
    if not m:
        die("kWeapon not parseable")
    weapon = [int(x) for x in m.group(1).split(",")]
    kit = [(i + 1, armor[i], weapon[i],
            10 if i in (0, 2) else 0) for i in range(4)]
    if kit != WANT_KIT:
        die("kit table drifted from the record")

    return band, protective, weapons, potions, types, kit


# ---------------------------------------------------------------------------
# 2. gate data + lua emission + round-trip
# ---------------------------------------------------------------------------

def gate_data(band, protective, weapons, potions, types, kit):
    problems = []
    if len(band) != N_BAND or len(protective) != N_GEAR \
            or len(weapons) != N_GEAR or len(potions) != N_POTIONS \
            or len(types) != N_TYPES or len(kit) != N_KIT:
        problems.append("row counts")
    for b, o, lo, hi in band:
        if b < 1 or b > 3 or o < 1 or o > 3:
            problems.append("band/option %r" % ((b, o),))
        if lo < 1 or hi < lo or hi > 12:
            problems.append("level %r" % ((lo, hi),))
    for rows, what in ((protective, "protective"),
                       (weapons, "weapons")):
        for c, f, m, cl, t in rows:
            if c < 1 or c > 7:
                problems.append("%s col %r" % (what, c))
            for v in (f, m, cl, t):
                if v < 0 or v > 15:
                    problems.append("%s pct %r" % (what, v))
    for c, pct, mx in potions:
        if pct < 0 or pct > 15 or mx < 1 or mx > 3:
            problems.append("potion %r" % ((c, pct, mx),))
    for t in types:
        if not t:
            problems.append("empty potion type")
    for c, a, w, s in kit:
        if a < 0 or a > 15 or w < 0 or w > 15 or s < 0 or s > 15:
            problems.append("kit %r" % ((c, a, w, s),))
    return problems


LUA_HDR = """-- encounter table def: %(key)s
-- The DMG Appendix P convention party (R1040 de-wire): %(what)s
-- (DMG pp.225-226, 1eonline.info compilation, OCR-verified).
-- %(note)s
-- DO NOT hand-edit: tools/r1040_splice.py is the only writer.

"""


def lua_file(key, what, note, body):
    return (LUA_HDR % dict(key=key, what=what, note=note)
            + "return {\n"
            + '  key = "%s",\n' % key
            + body
            + "}\n")


def emit_lua(band, protective, weapons, potions, types, kit):
    os.makedirs(LUA_DIR, exist_ok=True)
    texts = {}

    b = "  rows = {\n"
    for bd, o, lo, hi in band:
        b += ("    { band = %d, option = %d, level = {%d,%d} },\n"
              % (bd, o, lo, hi))
    b += "  },\n"
    texts["appendixp_band_level.lua"] = lua_file(
        "appendixp_band_level",
        "the LEVEL options (p.225)",
        "band = the printed band (1 low / 2 medium / 3 upper); "
        "option = the printed option (1-3); level = the "
        "printed level range for that band x option.", b)

    for name, key, rows, what in (
            (None, "appendixp_protective", protective,
             "the PROTECTIVE ITEMS chances (p.225)"),
            (None, "appendixp_weapons", weapons,
             "the WEAPONS chances (p.225-226)")):
        b = "  rows = {\n"
        for c, f, m, cl, t in rows:
            b += ("    { col = %d, fighter = %d, magic_user = %d, "
                  "cleric = %d, thief = %d },\n" % (c, f, m, cl, t))
        b += "  },\n"
        texts[key + ".lua"] = lua_file(
            key, what,
            "col = the printed column in order (protective: "
            "shield, plate, banded, chain, leather, ring of "
            "protection, bracers; weapons: dagger, sword, mace, "
            "battle axe, spear, bow, the 15 bolts +2); the "
            "four fields = the per-class chance at percent "
            "(a printed dash encodes as 0).", b)

    b = "  rows = {\n"
    for c, pct, mx in potions:
        b += ("    { class = %d, pct = %d, max = %d },\n"
              % (c, pct, mx))
    b += "  },\n"
    texts["appendixp_potions.lua"] = lua_file(
        "appendixp_potions",
        "the POTION chance and maximum (p.226)",
        "class = the engine class (1 fighter / 2 magic-user / "
        "3 cleric / 4 thief); pct = the per-level chance; "
        "max = the most carried.", b)

    b = "  rows = {\n"
    for i, t in enumerate(types):
        b += '    { die = %d, key = "%s" },\n' % (i + 1, t)
    b += "  },\n"
    texts["appendixp_potion_types.lua"] = lua_file(
        "appendixp_potion_types",
        "the ten printed potion types (p.226)",
        "die = the roller face (1-10; 10 = the book's printed "
        '"0.", Polymorph Self); key = the printed type name.', b)

    b = "  rows = {\n"
    for c, a, w, s in kit:
        b += ("    { class = %d, armorPct = %d, weaponPct = %d, "
              "shieldPct = %d },\n" % (c, a, w, s))
    b += "  },\n"
    texts["appendixp_kit.lua"] = lua_file(
        "appendixp_kit",
        "the kit builder chances (p.225)",
        "class = the engine class (1-4); armorPct/weaponPct = "
        'the "only one sort" kit chances; shieldPct = the '
        "shield try (the armored classes fighter and cleric "
        "at 10%, the others none - printed as no shield).", b)

    if len(texts) != FILES:
        die("emitted %d lua files (expected %d)"
            % (len(texts), FILES))
    for name in sorted(texts):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(texts[name])


def lua_roundtrip(band, protective, weapons, potions, types, kit):
    def read(name):
        with open(os.path.join(LUA_DIR, name)) as f:
            return f.read()

    got = re.findall(
        r"\{ band = (\d+), option = (\d+), level = \{(\d+),(\d+)\} \}",
        read("appendixp_band_level.lua"))
    got = [(int(a), int(b), int(c), int(d)) for a, b, c, d in got]
    if got != band:
        die("round-trip: appendixp_band_level mismatch")

    for key, rows in (("appendixp_protective", protective),
                      ("appendixp_weapons", weapons)):
        got = re.findall(
            r"\{ col = (\d+), fighter = (\d+), magic_user = (\d+), "
            r"cleric = (\d+), thief = (\d+) \}",
            read(key + ".lua"))
        got = [tuple(int(x) for x in r) for r in got]
        if got != rows:
            die("round-trip: %s mismatch" % key)

    got = re.findall(r"\{ class = (\d+), pct = (\d+), max = (\d+) \}",
                     read("appendixp_potions.lua"))
    got = [tuple(int(x) for x in r) for r in got]
    if got != potions:
        die("round-trip: appendixp_potions mismatch")

    got = re.findall(r'\{ die = (\d+), key = "([^"]+)" \}',
                     read("appendixp_potion_types.lua"))
    got = [(int(a), b) for a, b in got]
    if got != [(i + 1, t) for i, t in enumerate(types)]:
        die("round-trip: appendixp_potion_types mismatch")

    got = re.findall(
        r"\{ class = (\d+), armorPct = (\d+), weaponPct = (\d+), "
        r"shieldPct = (\d+) \}", read("appendixp_kit.lua"))
    got = [tuple(int(x) for x in r) for r in got]
    if got != kit:
        die("round-trip: appendixp_kit mismatch")


# ---------------------------------------------------------------------------
# 3. the registry extension
# ---------------------------------------------------------------------------

def replace_once(text, old, new, where):
    n = text.count(old)
    if n != 1:
        die("%s: anchor appears %d times (expected 1)"
            % (where, n))
    return text.replace(old, new, 1)


H_COMMENT_OLD = """// tools/r1038_splice.py (castle family) and
// tools/r1039_splice.py (party family) are the only writers."""
H_COMMENT_NEW = """// tools/r1038_splice.py (castle family),
// tools/r1039_splice.py (party family) and
// tools/r1040_splice.py (Appendix P family) are the only writers."""

H_STRUCT_ANCHOR = """struct EncounterPartyRow {
    int lo = 0, hi = 0;
    std::string prof;
    std::string kind;
    int max = 0;
    int a = 0, b = 0;
    int t1pct = 0, t1n = 0, t2pct = 0, t2n = 0;
    int t3pct = 0, t3n = 0, t4pct = 0, t4n = 0;
};"""
H_STRUCT_NEW = H_STRUCT_ANCHOR + """

// R1040: the Appendix P family row (the DMG pp.225-226
// convention-party de-wire). The six printed tables ride one
// row shape: lo/hi = the band_level printed level range
// (elsewhere lo == hi = the row key: the printed column, the
// class index or the die face); key = the potion type string;
// band/option = the band_level axes (1-3 each); fighter/
// magic_user/cleric/thief = the transposed gear-table chance
// columns; pct/max = the potion chance and most-carried;
// armorPct/weaponPct/shieldPct = the kit builder chances.
// Unused columns stay defaulted - the per-file key lists in
// the loader keep each file strict (the R1034 lesson).
struct EncounterAppendixPRow {
    int lo = 0, hi = 0;
    std::string key;
    int band = 0, option = 0;
    int fighter = 0, magic_user = 0, cleric = 0, thief = 0;
    int pct = 0, max = 0;
    int armorPct = 0, weaponPct = 0, shieldPct = 0;
};"""

H_ACC_ANCHOR = """    const std::vector<EncounterPartyRow>& partyRows(
        const std::string& name) const;"""
H_ACC_NEW = H_ACC_ANCHOR + """
    // R1040: the Appendix P family views. name:
    // appendixp_band_level / appendixp_protective /
    // appendixp_weapons / appendixp_potions /
    // appendixp_potion_types / appendixp_kit.
    bool hasAppendixP(const std::string& name) const;
    const std::vector<EncounterAppendixPRow>& appendixPRows(
        const std::string& name) const;"""

H_MEM_ANCHOR = """    std::map<std::string, std::vector<EncounterPartyRow>>
        m_party;"""
H_MEM_NEW = H_MEM_ANCHOR + """
    // R1040: the Appendix P family (the six printed
    // convention-party tables; the gear rows are transposed -
    // one row per printed column).
    std::map<std::string, std::vector<EncounterAppendixPRow>>
        m_appendixp;"""

CPP_KEYS_ANCHOR = """const char* const kPartyItemKeys[] =
    { "die", "kind", "a", "b", nullptr };"""
CPP_KEYS_NEW = CPP_KEYS_ANCHOR + """
// R1040: the Appendix P family file/row keys. Exact keys
// only - no prefix, no exceptions (the R1034 dispatch-order
// lesson); the per-table row key lists keep each file's
// shape strict.
const char* const kAppendixPFileKeys[] =
    { "key", "rows", nullptr };
const char* const kAppendixPBandKeys[] =
    { "band", "option", "level", nullptr };
const char* const kAppendixPGearKeys[] =
    { "col", "fighter", "magic_user", "cleric", "thief",
      nullptr };
const char* const kAppendixPPotionKeys[] =
    { "class", "pct", "max", nullptr };
const char* const kAppendixPTypeKeys[] =
    { "die", "key", nullptr };
const char* const kAppendixPKitKeys[] =
    { "class", "armorPct", "weaponPct", "shieldPct",
      nullptr };"""

CPP_ELSE_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_BRANCH = """    } else if (key == "appendixp_band_level"
               || key == "appendixp_protective"
               || key == "appendixp_weapons"
               || key == "appendixp_potions"
               || key == "appendixp_potion_types"
               || key == "appendixp_kit") {
        const int t = lua_gettop(L);
        const char* const* rowKeys = kAppendixPGearKeys;
        if (key == "appendixp_band_level")
            rowKeys = kAppendixPBandKeys;
        else if (key == "appendixp_potions")
            rowKeys = kAppendixPPotionKeys;
        else if (key == "appendixp_potion_types")
            rowKeys = kAppendixPTypeKeys;
        else if (key == "appendixp_kit")
            rowKeys = kAppendixPKitKeys;
        if (!checkAllowedKeys(L, t, kAppendixPFileKeys, key, &err)) goto bad;
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
            std::vector<EncounterAppendixPRow> rows;
            int prevKey = 0;
            int prevBand = 0, prevOpt = 0;
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
                EncounterAppendixPRow row;
                if (key == "appendixp_band_level") {
                    lua_getfield(L, rt, "band");
                    if (!lua_isinteger(L, -1)) {
                        err = "band is not an integer"; goto bad;
                    }
                    const long long bd = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    lua_getfield(L, rt, "option");
                    if (!lua_isinteger(L, -1)) {
                        err = "option is not an integer"; goto bad;
                    }
                    const long long op = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (bd < 1 || bd > 3 || op < 1 || op > 3) {
                        err = "band/option outside 1-3"; goto bad;
                    }
                    if (bd != prevBand) {
                        if (prevBand != 0
                            && (bd != prevBand + 1
                                || prevOpt != 3)) {
                            err = "band must continue 1-3";
                            goto bad;
                        }
                        prevBand = (int)bd; prevOpt = 0;
                    }
                    if (op != prevOpt + 1) {
                        err = "option must continue 1-3 in order";
                        goto bad;
                    }
                    prevOpt = (int)op;
                    row.band = (int)bd; row.option = (int)op;
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
                    if (lv[0] < 1 || lv[1] < lv[0] || lv[1] > 12) {
                        err = "level outside 1-12"; goto bad;
                    }
                    row.lo = (int)lv[0]; row.hi = (int)lv[1];
                } else if (key == "appendixp_protective"
                           || key == "appendixp_weapons") {
                    lua_getfield(L, rt, "col");
                    if (!lua_isinteger(L, -1)) {
                        err = "col is not an integer"; goto bad;
                    }
                    const long long c = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (c != prevKey + 1 || c < 1 || c > 7) {
                        err = "col must continue 1-7 in order";
                        goto bad;
                    }
                    prevKey = (int)c;
                    row.lo = row.hi = (int)c;
                    static const char* const kCls[4] = {
                        "fighter", "magic_user", "cleric",
                        "thief" };
                    int* dst[4] = { &row.fighter,
                        &row.magic_user, &row.cleric,
                        &row.thief };
                    for (int j = 0; j < 4; ++j) {
                        lua_getfield(L, rt, kCls[j]);
                        if (!lua_isinteger(L, -1)) {
                            err = std::string(kCls[j])
                                + " is not an integer";
                            goto bad;
                        }
                        const long long v = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                        if (v < 0 || v > 15) {
                            err = std::string(kCls[j])
                                + " outside 0-15";
                            goto bad;
                        }
                        *dst[j] = (int)v;
                    }
                } else if (key == "appendixp_potions") {
                    lua_getfield(L, rt, "class");
                    if (!lua_isinteger(L, -1)) {
                        err = "class is not an integer"; goto bad;
                    }
                    const long long c = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (c != prevKey + 1 || c < 1 || c > 4) {
                        err = "class must continue 1-4 in order";
                        goto bad;
                    }
                    prevKey = (int)c;
                    row.lo = row.hi = (int)c;
                    lua_getfield(L, rt, "pct");
                    if (!lua_isinteger(L, -1)) {
                        err = "pct is not an integer"; goto bad;
                    }
                    const long long p = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    lua_getfield(L, rt, "max");
                    if (!lua_isinteger(L, -1)) {
                        err = "max is not an integer"; goto bad;
                    }
                    const long long mx = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (p < 0 || p > 15) {
                        err = "pct outside 0-15"; goto bad;
                    }
                    if (mx < 1 || mx > 3) {
                        err = "max outside 1-3"; goto bad;
                    }
                    row.pct = (int)p; row.max = (int)mx;
                } else if (key == "appendixp_potion_types") {
                    lua_getfield(L, rt, "die");
                    if (!lua_isinteger(L, -1)) {
                        err = "die is not an integer"; goto bad;
                    }
                    const long long d = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (d != prevKey + 1 || d < 1 || d > 10) {
                        err = "die must continue 1-10 in order";
                        goto bad;
                    }
                    prevKey = (int)d;
                    row.lo = row.hi = (int)d;
                    if (!getStr(L, rt, "key", &row.key, &err))
                        goto bad;
                    if (row.key.empty()) {
                        err = "empty potion type"; goto bad;
                    }
                } else {
                    // appendixp_kit
                    lua_getfield(L, rt, "class");
                    if (!lua_isinteger(L, -1)) {
                        err = "class is not an integer"; goto bad;
                    }
                    const long long c = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (c != prevKey + 1 || c < 1 || c > 4) {
                        err = "class must continue 1-4 in order";
                        goto bad;
                    }
                    prevKey = (int)c;
                    row.lo = row.hi = (int)c;
                    static const char* const kKit[3] = {
                        "armorPct", "weaponPct", "shieldPct" };
                    int* dst[3] = { &row.armorPct,
                        &row.weaponPct, &row.shieldPct };
                    for (int j = 0; j < 3; ++j) {
                        lua_getfield(L, rt, kKit[j]);
                        if (!lua_isinteger(L, -1)) {
                            err = std::string(kKit[j])
                                + " is not an integer";
                            goto bad;
                        }
                        const long long v = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                        if (v < 0 || v > 15) {
                            err = std::string(kKit[j])
                                + " outside 0-15";
                            goto bad;
                        }
                        *dst[j] = (int)v;
                    }
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (key == "appendixp_band_level"
                && (prevBand != 3 || prevOpt != 3)) {
                err = "band options do not complete 3x3";
                goto bad;
            }
            if (m_appendixp.count(key)) { err = "duplicate def key";
                                           goto bad; }
            m_appendixp[key] = rows;
        }
"""

CPP_ACC_ANCHOR = """const std::vector<EncounterPartyRow>&
EncounterTableRegistry::partyRows(
    const std::string& name) const {
    static const std::vector<EncounterPartyRow> none;
    auto it = m_party.find(name);
    return it == m_party.end() ? none : it->second;
}"""
CPP_ACC_NEW = CPP_ACC_ANCHOR + """

bool EncounterTableRegistry::hasAppendixP(
    const std::string& name) const {
    return m_appendixp.count(name) != 0;
}

const std::vector<EncounterAppendixPRow>&
EncounterTableRegistry::appendixPRows(
    const std::string& name) const {
    static const std::vector<EncounterAppendixPRow> none;
    auto it = m_appendixp.find(name);
    return it == m_appendixp.end() ? none : it->second;
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
# 4. the appendixp.h seam (per-function replaces; all
#    signatures stay for the r147/r156 audit callers)
# ---------------------------------------------------------------------------

REGTEST_OLD = ('    #include "rules/audits/'
               'r1039_party_encounter_registry.h"  // R1039')
REGTEST_NEW = (REGTEST_OLD + '\n'
               '    #include "rules/audits/'
               'r1040_appendixp_registry.h"  // R1040')

INC_OLD = '#include "../rules/engine/dice.h"'
INC_NEW = (INC_OLD + '\n'
           '#include "EncounterTableRegistry.h"   // R1040: the'
           ' kit tables ride the registry')

AP_REG = """
// R1040 (the registry-native de-wire, the R1032-R1039 shape):
// the printed pp.225-226 tables retired into
// content/tables/appendixp/ (six files; the gear tables
// transposed to one row per printed column). This seam is
// header-only like the module: the registry rides its own
// inline singleton below (encReg() in encounters.cpp is
// file-static and out of reach from a header - the load is
// this module's own concern). Every signature above and
// below is unchanged (rules/audits/r147_appendix_p.h and
// r156_convention_party.h pin them); the mechanics - the
// abilityRoll, the itemChance chain with the Gonzo worked
// example, rollItemPlus, the member builders - stay verbatim.

inline dm::EncounterTableRegistry& apReg() {
    static dm::EncounterTableRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/appendixp");
    }
    return reg;
}

// the registry-backed per-TU static cache (the R1032-R1039
// idiom; function-local statics in inline functions are
// shared across TUs)
inline const std::vector<dm::EncounterAppendixPRow>& apView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterAppendixPRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, apReg().appendixPRows(name)).first;
    return it->second;
}
"""

BANDLO_OLD = """inline int bandLevelLo(int band, int option) {
    static const int lo[3][3] = {
        { 1, 1, 2 },    // low: 1-2 / 1-3 / 2-4
        { 5, 5, 7 },    // medium: 5-7 / 5-8 / 7-9
        { 8, 8, 9 },    // upper: 8-10 / 8-11 / 9-12
    };
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    return lo[band][option];
}"""

BANDLO_NEW = """inline int bandLevelLo(int band, int option) {
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    for (const auto& r : apView("appendixp_band_level"))
        if (r.band == band + 1 && r.option == option + 1)
            return r.lo;
    return 1;   // defensive: the printed table covers 3x3
}"""

BANDHI_OLD = """inline int bandLevelHi(int band, int option) {
    static const int hi[3][3] = {
        { 2, 3, 4 },
        { 7, 8, 9 },
        { 10, 11, 12 },
    };
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    return hi[band][option];
}"""

BANDHI_NEW = """inline int bandLevelHi(int band, int option) {
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    for (const auto& r : apView("appendixp_band_level"))
        if (r.band == band + 1 && r.option == option + 1)
            return r.hi;
    return 2;   // defensive: the printed table covers 3x3
}"""

PROTECTIVE_OLD = """inline int protectivePct(int classIndex, int col) {
    static const int t[4][7] = {
        { 10, 6, 8, 10,  0,  0, 0 },   // fighter
        {  0, 0, 0,  0,  0, 15, 4 },   // magic-user
        { 10, 5, 6,  8,  0,  2, 0 },   // cleric
        {  0, 0, 0,  0, 10,  4, 0 },   // thief
    };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    return t[classIndex][col];
}"""

PROTECTIVE_NEW = """inline int protectivePct(int classIndex, int col) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    for (const auto& r : apView("appendixp_protective"))
        if (r.lo == col + 1)
            return classIndex == 0 ? r.fighter
                 : classIndex == 1 ? r.magic_user
                 : classIndex == 2 ? r.cleric
                 : r.thief;
    return 0;   // defensive: a printed dash encodes as 0
}"""

WEAPON_OLD = """inline int weaponPct(int classIndex, int col) {
    static const int t[4][7] = {
        { 10, 10,  0, 7, 8, 1, 10 },   // fighter
        { 15,  0,  0, 0, 0, 0,  0 },   // magic-user
        {  0,  0, 12, 0, 0, 0,  0 },   // cleric
        { 12, 11,  0, 0, 0, 0,  0 },   // thief
    };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    return t[classIndex][col];
}"""

WEAPON_NEW = """inline int weaponPct(int classIndex, int col) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    for (const auto& r : apView("appendixp_weapons"))
        if (r.lo == col + 1)
            return classIndex == 0 ? r.fighter
                 : classIndex == 1 ? r.magic_user
                 : classIndex == 2 ? r.cleric
                 : r.thief;
    return 0;   // defensive: a printed dash encodes as 0
}"""

POTION_OLD = """inline int potionPct(int classIndex) {
    static const int t[4] = { 8, 10, 6, 9 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    return t[classIndex];
}

inline int potionMax(int classIndex) {
    static const int t[4] = { 1, 3, 1, 2 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    return t[classIndex];
}

inline const char* potionType(int roll) {
    static const char* const k[10] = {
        "Climbing", "Diminution", "Extra-Healing",
        "Fire Resistance", "Flying", "Gaseous Form",
        "Growth", "Healing", "Invisibility",
        "Polymorph Self",
    };
    if (roll < 1) roll = 1;
    if (roll > 10) roll = 10;
    return k[roll - 1];
}"""

POTION_NEW = """inline int potionPct(int classIndex) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    for (const auto& r : apView("appendixp_potions"))
        if (r.lo == classIndex + 1)
            return r.pct;
    return 0;   // defensive
}

inline int potionMax(int classIndex) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    for (const auto& r : apView("appendixp_potions"))
        if (r.lo == classIndex + 1)
            return r.max;
    return 1;   // defensive
}

inline const char* potionType(int roll) {
    if (roll < 1) roll = 1;
    if (roll > 10) roll = 10;
    for (const auto& r : apView("appendixp_potion_types"))
        if (r.lo == roll)
            return r.key.c_str();
    return "";   // defensive: the table covers 1-10
}"""

KIT_OLD = """inline MemberMagic rollMemberMagic(rules::Dice& dice,
                                   int classIndex, int level) {
    static const int kArmor[4]  = { 10, 15, 8, 10 };
    static const int kWeapon[4] = { 10, 15, 12, 11 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    MemberMagic m;
    m.armorPlus  = rollItemPlus(dice, kArmor[classIndex], level);
    m.weaponPlus = rollItemPlus(dice, kWeapon[classIndex], level);
    if (classIndex == 0 || classIndex == 2)
        m.shieldPlus = rollItemPlus(dice, 10, level);
    return m;
}"""

KIT_NEW = """inline MemberMagic rollMemberMagic(rules::Dice& dice,
                                   int classIndex, int level) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    MemberMagic m;
    const dm::EncounterAppendixPRow* k = nullptr;
    for (const auto& r : apView("appendixp_kit"))
        if (r.lo == classIndex + 1) { k = &r; break; }
    if (!k) return m;   // defensive: the table covers 1-4
    m.armorPlus  = rollItemPlus(dice, k->armorPct, level);
    m.weaponPlus = rollItemPlus(dice, k->weaponPct, level);
    // the shield try is the armored classes' printed row
    // (fighter and cleric at 10%; the others carry none)
    if (classIndex == 0 || classIndex == 2)
        m.shieldPlus = rollItemPlus(dice, k->shieldPct, level);
    return m;
}"""


def seam_appendixp(src):
    # the inline registry singleton rides right after the
    # LEVEL band header (before bandLevelLo)
    anchor = "// ---- LEVEL (p.225): three printed options per band -----"
    src = replace_once(src, anchor,
                       anchor + "\n" + AP_REG, "apReg anchor")
    src = replace_once(src, INC_OLD, INC_NEW,
                       "appendixp include")
    src = replace_once(src, BANDLO_OLD, BANDLO_NEW,
                       "bandLevelLo")
    src = replace_once(src, BANDHI_OLD, BANDHI_NEW,
                       "bandLevelHi")
    src = replace_once(src, PROTECTIVE_OLD, PROTECTIVE_NEW,
                       "protectivePct")
    src = replace_once(src, WEAPON_OLD, WEAPON_NEW,
                       "weaponPct")
    src = replace_once(src, POTION_OLD, POTION_NEW,
                       "potion trio")
    src = replace_once(src, KIT_OLD, KIT_NEW,
                       "rollMemberMagic")
    for tok in RETIRED_TOKENS:
        if tok in src:
            die("retired token %r survived the splice" % tok)
    return src


# ---------------------------------------------------------------------------
# 5. the fragment (7 sections, derived pins)
# ---------------------------------------------------------------------------

CLASS_FIELD = ("fighter", "magic_user", "cleric", "thief")


def build_fragment(band, protective, weapons, potions, types, kit):
    L = []
    A = L.append

    band_pins = "".join(
        "        { const auto& r = rb[%d];\n"
        "          if (r.band != %d || r.option != %d) ++bad;\n"
        "          if (r.lo != %d || r.hi != %d) ++bad; }\n"
        % (i, b, o, lo, hi)
        for i, (b, o, lo, hi) in enumerate(band))

    band_fn = "".join(
        "        if (dm::appendixp::bandLevelLo(%d, %d) != %d)\n"
        "            ++bad;\n"
        "        if (dm::appendixp::bandLevelHi(%d, %d) != %d)\n"
        "            ++bad;\n"
        % (b - 1, o - 1, lo, b - 1, o - 1, hi)
        for b, o, lo, hi in band)

    def gear_pins(key, rows):
        out = ""
        for c, f, m, cl, t in rows:
            out += (
                "        { const auto& r = ereg.appendixPRows("
                "\"%s\")[%d];\n"
                "          if (r.lo != %d || r.hi != %d) ++bad;\n"
                "          if (r.fighter != %d) ++bad;\n"
                "          if (r.magic_user != %d) ++bad;\n"
                "          if (r.cleric != %d) ++bad;\n"
                "          if (r.thief != %d) ++bad; }\n"
                % (key, c - 1, c, c, f, m, cl, t))
        return out

    gear_fn = ""
    for key, rows, fn in (
            ("appendixp_protective", protective,
             "protectivePct"),
            ("appendixp_weapons", weapons, "weaponPct")):
        for c, f, m, cl, t in rows:
            gear_fn += (
                "        if (dm::appendixp::%s(%d, %d) != %d)\n"
                "            ++bad;\n" % (fn, 0, c - 1, f))
            gear_fn += (
                "        if (dm::appendixp::%s(%d, %d) != %d)\n"
                "            ++bad;\n" % (fn, 1, c - 1, m))
            gear_fn += (
                "        if (dm::appendixp::%s(%d, %d) != %d)\n"
                "            ++bad;\n" % (fn, 2, c - 1, cl))
            gear_fn += (
                "        if (dm::appendixp::%s(%d, %d) != %d)\n"
                "            ++bad;\n" % (fn, 3, c - 1, t))

    potion_pins = "".join(
        "        { const auto& r = ereg.appendixPRows("
        "\"appendixp_potions\")[%d];\n"
        "          if (r.lo != %d || r.hi != %d) ++bad;\n"
        "          if (r.pct != %d || r.max != %d) ++bad; }\n"
        % (i, c, c, p, mx)
        for i, (c, p, mx) in enumerate(potions))

    type_pins = "".join(
        "        { const auto& r = ereg.appendixPRows("
        "\"appendixp_potion_types\")[%d];\n"
        "          if (r.lo != %d || r.hi != %d) ++bad;\n"
        "          if (r.key != \"%s\") ++bad; }\n"
        % (i, i + 1, i + 1, t)
        for i, t in enumerate(types))

    type_fn = "".join(
        "        if (std::string(dm::appendixp::potionType(%d))\n"
        "            != \"%s\") ++bad;\n" % (i + 1, t)
        for i, t in enumerate(types))

    potion_fn = "".join(
        "        if (dm::appendixp::potionPct(%d) != %d) ++bad;\n"
        "        if (dm::appendixp::potionMax(%d) != %d) ++bad;\n"
        % (c - 1, p, c - 1, mx)
        for c, p, mx in potions)

    kit_pins = "".join(
        "        { const auto& r = ereg.appendixPRows("
        "\"appendixp_kit\")[%d];\n"
        "          if (r.lo != %d || r.hi != %d) ++bad;\n"
        "          if (r.armorPct != %d) ++bad;\n"
        "          if (r.weaponPct != %d) ++bad;\n"
        "          if (r.shieldPct != %d) ++bad; }\n"
        % (i, c, c, a, w, s)
        for i, (c, a, w, s) in enumerate(kit))

    A("""// ============================================================================
// Adnd1 - rules/audits/r1040_appendixp_registry.h  (R1040)
// The DMG Appendix P convention-party battery audit, the
// R1032-R1039 shape: the registry load, exact table counts
// and the band/column/class/die chains, the full 3x3 level
// options (registry rows and the bandLevelLo/Hi functions),
// the full transposed PROTECTIVE ITEMS and WEAPONS chance
// columns (rows and the protectivePct/weaponPct functions),
// the POTION chance/max columns, the ten printed potion
// types and the kit builder chances, the printed itemChance
// chain (incl. the Gonzo worked example) and the member
// builders. Expected: 6 appendixp files - the level options
// (9 rows), the two gear tables (7 rows each), the potions
// (4 rows), the types (10 rows) and the kit (4 rows) - all
// derived from the DMG record (pp.225-226, the 1eonline.info
// compilation) the splice parsed. The seam is header-only:
// an inline apReg() singleton self-loads the directory
// (encReg() is file-static to encounters.cpp and stays
// untouched).
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 6 appendixp files, zero errors, one reg --
    bad = 0;
    {
        const int af = ereg.loadDirectory(
            "content/tables/appendixp");
        if (af != 6) ++bad;
        if (!ereg.errors().empty()) ++bad;
        const int nf = ereg.loadDirectory(
            "content/tables/encounters_party");
        if (nf != 6) ++bad;
        const int kf = ereg.loadDirectory(
            "content/tables/encounters_castle");
        if (kf != 7) ++bad;
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
        if (!ereg.hasAppendixP("appendixp_band_level")) ++bad;
        if (!ereg.hasAppendixP("appendixp_protective")) ++bad;
        if (!ereg.hasAppendixP("appendixp_weapons")) ++bad;
        if (!ereg.hasAppendixP("appendixp_potions")) ++bad;
        if (!ereg.hasAppendixP("appendixp_potion_types")) ++bad;
        if (!ereg.hasAppendixP("appendixp_kit")) ++bad;
        // negative pins (the R1034 lesson; the R1038
        // phantom-pin lesson: every negative names a key
        // ABSENT from that map)
        if (ereg.hasAppendixP("")) ++bad;
        if (ereg.hasAppendixP("castle_type")) ++bad;
        if (ereg.hasAppendixP("appendixp_band")) ++bad;
        if (ereg.hasCastle("appendixp_kit")) ++bad;
        if (ereg.hasParty("appendixp_kit")) ++bad;
        if (ereg.hasPlanar("appendixp_kit")) ++bad;
        if (ereg.hasPlanarBands("appendixp_kit")) ++bad;
        if (ereg.hasWater("appendixp_kit")) ++bad;
        if (ereg.hasOutdoor("appendixp_kit")) ++bad;
        if (ereg.hasCityBands("appendixp_kit")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasParty("character_subtable")) ++bad;
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1040 appendixp registry load audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed chains ------------
    bad = 0;
    {
        if ((int)ereg.appendixPRows("appendixp_band_level")
            .size() != 9) ++bad;
        if ((int)ereg.appendixPRows("appendixp_protective")
            .size() != 7) ++bad;
        if ((int)ereg.appendixPRows("appendixp_weapons")
            .size() != 7) ++bad;
        if ((int)ereg.appendixPRows("appendixp_potions")
            .size() != 4) ++bad;
        if ((int)ereg.appendixPRows("appendixp_potion_types")
            .size() != 10) ++bad;
        if ((int)ereg.appendixPRows("appendixp_kit")
            .size() != 4) ++bad;
        // the gear columns chain 1-7
        const char* const gear[2] = {
            "appendixp_protective", "appendixp_weapons" };
        for (int g = 0; g < 2; ++g) {
            const auto& rs = ereg.appendixPRows(gear[g]);
            int c = 1;
            for (const auto& r : rs) {
                if (r.lo != c || r.hi != c) ++bad;
                ++c;
            }
            if (c != 8) ++bad;
        }
        // the class-keyed rows chain 1-4
        const char* const cls[2] = {
            "appendixp_potions", "appendixp_kit" };
        for (int g = 0; g < 2; ++g) {
            const auto& rs = ereg.appendixPRows(cls[g]);
            int c = 1;
            for (const auto& r : rs) {
                if (r.lo != c || r.hi != c) ++bad;
                ++c;
            }
            if (c != 5) ++bad;
        }
        // the die faces chain 1-10
        {
            const auto& rs =
                ereg.appendixPRows("appendixp_potion_types");
            int d = 1;
            for (const auto& r : rs) {
                if (r.lo != d || r.hi != d) ++bad;
                ++d;
            }
            if (d != 11) ++bad;
        }
        // the level ranges stay printed
        for (const auto& r :
             ereg.appendixPRows("appendixp_band_level"))
            if (r.lo < 1 || r.hi < r.lo || r.hi > 12) ++bad;
    }
    printf("R1040 appendixp registry counts audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 3. band: the full 3x3 level options ---------------
    bad = 0;
    {
        const auto& rb =
            ereg.appendixPRows("appendixp_band_level");
""")
    A(band_pins)
    A(band_fn)
    A("""        // the defensive clamps mirror the retired arrays
        if (dm::appendixp::bandLevelLo(-1, -1) != 1) ++bad;
        if (dm::appendixp::bandLevelLo(9, 9) != 9) ++bad;
        if (dm::appendixp::bandLevelHi(-1, -1) != 2) ++bad;
        if (dm::appendixp::bandLevelHi(9, 9) != 12) ++bad;
    }
    printf("R1040 appendixp registry band audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 4. gear: the full chance columns -------------------
    bad = 0;
    {
""")
    A(gear_pins("appendixp_protective", protective))
    A(gear_pins("appendixp_weapons", weapons))
    A(gear_fn)
    A("""        // the defensive clamps: out-of-range reads the
        // edge rows (the retired clamp behavior)
        if (dm::appendixp::protectivePct(0, -1) != 10) ++bad;
        if (dm::appendixp::protectivePct(0, 9) != 0) ++bad;
        if (dm::appendixp::weaponPct(1, -1) != 15) ++bad;
        if (dm::appendixp::weaponPct(1, 9) != 0) ++bad;
    }
    printf("R1040 appendixp registry gear audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 5. potions, types and kit ---------------------------
    bad = 0;
    {
""")
    A(potion_pins)
    A(potion_fn)
    A(type_pins)
    A(type_fn)
    A(kit_pins)
    A("""        // the defensive clamps
        if (dm::appendixp::potionPct(-1) != 8) ++bad;
        if (dm::appendixp::potionPct(9) != 9) ++bad;
        if (dm::appendixp::potionMax(-1) != 1) ++bad;
        if (dm::appendixp::potionMax(9) != 2) ++bad;
        if (*dm::appendixp::potionType(0) == 0) ++bad;
        if (*dm::appendixp::potionType(11) == 0) ++bad;
        if (std::string(dm::appendixp::potionType(0))
            != "Climbing") ++bad;
        if (std::string(dm::appendixp::potionType(11))
            != "Polymorph Self") ++bad;
    }
    printf("R1040 appendixp registry potions audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 6. chain: the printed itemChance chain -------------
    bad = 0;
    {
        // the Gonzo worked example (p.225): 15%/level chain
        // at 9th = 135%; +2 chance 9 + 45 = 54; +3 check 9
        if (dm::appendixp::itemChancePct(15, 9) != 135) ++bad;
        if (dm::appendixp::plusTwoChancePct(15, 9) != 54) ++bad;
        if (dm::appendixp::plusThreeChancePct(9) != 9) ++bad;
        if (dm::appendixp::itemChancePct(0, 9) != 0) ++bad;
        if (dm::appendixp::itemChancePct(15, 0) != 15) ++bad;
        // a zero chance never rolls a plus
        for (int i = 0; i < 100; ++i)
            if (dm::appendixp::rollItemPlus(dice, 0, 9) != 0)
                ++bad;
        // a huge chance always lands at least +1
        for (int i = 0; i < 100; ++i)
            if (dm::appendixp::rollItemPlus(dice, 100, 20) < 1)
                ++bad;
        // the ability roll stays 4d6-best-of-3
        for (int i = 0; i < 1000; ++i) {
            const int a = dm::appendixp::abilityRoll(dice);
            if (a < 3 || a > 18) ++bad;
        }
    }
    printf("R1040 appendixp registry chain audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 7. member: the spur-of-the-moment builders ----------
    bad = 0;
    {
        // rollMemberMagic: kit pluses stay 0-3
        for (int i = 0; i < 4000; ++i) {
            const int c = i % 4;
            dm::appendixp::MemberMagic m =
                dm::appendixp::rollMemberMagic(
                    dice, c, 1 + i % 12);
            if (m.armorPlus < 0 || m.armorPlus > 3) ++bad;
            if (m.weaponPlus < 0 || m.weaponPlus > 3) ++bad;
            if (m.shieldPlus < 0 || m.shieldPlus > 3) ++bad;
            if (c != 0 && c != 2 && m.shieldPlus != 0) ++bad;
        }
        // rollSpurMember: the level lands in its band x
        // option, the abilities stay 3-18, classIndex clamps
        for (int i = 0; i < 2000; ++i) {
            const int b = i % 3, o = (i / 3) % 3;
            dm::appendixp::SpurMember m =
                dm::appendixp::rollSpurMember(
                    dice, b, o, i % 4);
            if (m.level < dm::appendixp::bandLevelLo(b, o)
                || m.level > dm::appendixp::bandLevelHi(b, o))
                ++bad;
            for (int a = 0; a < 6; ++a)
                if (m.abilities[a] < 3 || m.abilities[a] > 18)
                    ++bad;
        }
        // the classIndex clamp (the R156 m9 pin shape)
        {
            dm::appendixp::SpurMember m =
                dm::appendixp::rollSpurMember(dice, 0, 0, 9);
            if (m.classIndex != 3) ++bad;
        }
    }
    printf("R1040 appendixp registry member audit: bad %d\\n", bad);
    if (bad) return 1;

}
""")
    # the dice used by sections 6-7
    text = "".join(L)
    text = text.replace(
        "    // -- 6. chain: the printed itemChance chain -------------\n"
        "    bad = 0;\n",
        "    // -- 6. chain: the printed itemChance chain -------------\n"
        "    bad = 0;\n"
        "    rules::Rng rng(1040);\n"
        "    rules::Dice dice(rng);\n")
    if "rules::Dice dice(rng);" not in text:
        die("section 6 dice injection failed")
    n = text.count("audit: bad %d")
    if n != 7:
        die("fragment carries %d census patterns (expected 7)"
            % n)
    return text


# ---------------------------------------------------------------------------
# 6. census + brace balance + main
# ---------------------------------------------------------------------------

CENSUS_PRE = 997
CENSUS_POST = 1004


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
    if ("// tools/r1040_splice.py (Appendix P family)"
            in h):
        # already applied: verify the landing state
        with open(AP, encoding="utf-8") as f:
            ap = f.read()
        if "kArmor" in ap:
            die("already applied but kArmor is still in "
                "dm/appendixp.h")
        if census_count() != CENSUS_POST:
            die("already applied but census is %d "
                "(expected %d)"
                % (census_count(), CENSUS_POST))
        for name in ("appendixp_band_level.lua",
                     "appendixp_protective.lua",
                     "appendixp_weapons.lua",
                     "appendixp_potions.lua",
                     "appendixp_potion_types.lua",
                     "appendixp_kit.lua"):
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
    with open(AP, encoding="utf-8") as f:
        src = f.read()
    (band, protective, weapons, potions, types, kit) = \
        parse_appendixp(src)
    problems = gate_data(band, protective, weapons,
                        potions, types, kit)
    if problems:
        die("data gate: %s" % "; ".join(problems))
    print("parsed: band %d rows, gear 7+7, potions %d, "
          "types %d, kit %d"
          % (len(band), len(potions), len(types), len(kit)))

    # -- lua + registry -------------------------------------
    emit_lua(band, protective, weapons, potions, types, kit)
    lua_roundtrip(band, protective, weapons, potions,
                  types, kit)
    print("round-trip: %d lua files parse back byte-exact"
          % FILES)
    extend_registry()

    # -- the appendixp.h seam --------------------------------
    with open(AP, "w", encoding="utf-8") as f:
        f.write(seam_appendixp(src))

    # -- the fragment + the regtest include -----------------
    frag = build_fragment(band, protective, weapons,
                         potions, types, kit)
    with open(FRAG, "w", encoding="utf-8") as f:
        f.write(frag)
    with open(REGTEST, encoding="utf-8") as f:
        rt = f.read()
    rt = replace_once(rt, REGTEST_OLD, REGTEST_NEW,
                     "regtest include")
    with open(REGTEST, "w", encoding="utf-8") as f:
        f.write(rt)

    # -- gates ----------------------------------------------
    for p in (AP, REG_H, REG_CPP, REGTEST, FRAG):
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
