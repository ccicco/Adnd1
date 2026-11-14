#!/usr/bin/env python3
# r1039_splice.py - R1039: the R53 Character Subtable and the
# R55 party magic-item tables de-wire (the R1032-R1038 shape;
# census 990 -> 997).
#
# The R53/R55 region of dm/encounters.cpp (the separator above
# "R53: the Character Subtable" through the rollCharacterParty
# header) retires its six printed tables into
# content/tables/encounters_party/: the Character Subtable
# (DMG p.176, 10 rows, per-profession maxima) into
# character_subtable.lua, the level-chance ladder (p.176-177,
# 13 rows) into magic_ladder.lua, and the four magic-item
# tables (20/16/16/12 rows, "(d8, d6)" half-dice reading kept
# engine-side) into magic_table_1..4.lua. One new registry row
# shape (EncounterPartyRow) carries all six; the profession
# and item-kind enums ride as printed tokens, mapped
# engine-side in the seam. Mechanics stay engine-side and
# verbatim: classForProf, characterLevelFor, henchmanLevelFor,
# raceAllowsClass (R62), the applyItem pluses, the half-dice
# row selection, and rollCharacterParty's re-roll loops (only
# kProfTable[cand].max -> profMax(cand) rewrites). profFor and
# rollMagicItemsFor keep their signatures (the R65, R64, R1038
# callers). Fragment: rules/audits/
# r1039_party_encounter_registry.h (7 sections, census +7).
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
                       "encounters_party")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1039_party_encounter_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory (asserted against the source at parse time)
# ---------------------------------------------------------------------------

N_SUB = 10
N_LADDER = 13
N_T1 = 20
N_T2 = 16
N_T3 = 16
N_T4 = 12
FILES = 6        # lua files in encounters_party/

PROFS = ["cleric", "druid", "fighter", "paladin", "ranger",
         "magic_user", "illusionist", "thief", "assassin",
         "monk_bard"]
KIND_TOKENS = {"ITEM_NONE": "none", "ITEM_WPN": "wpn",
               "ITEM_RNG": "rng", "ITEM_ARM": "arm",
               "ITEM_SHD": "shd", "ITEM_ARM_SET": "arm_set"}

# the printed tables, PARSED from the region; these expected
# shapes gate the parse (the R1035 never-recall lesson)
WANT_SUB = [
    (1, 17, "cleric", 3),
    (18, 20, "druid", 2),
    (21, 60, "fighter", 5),
    (61, 62, "paladin", 2),
    (63, 65, "ranger", 2),
    (66, 86, "magic_user", 3),
    (87, 88, "illusionist", 1),
    (89, 98, "thief", 4),
    (99, 99, "assassin", 2),
    (100, 100, "monk_bard", 1),
]
WANT_LADDER = [
    (1, 10, 1, 0, 0, 0, 0, 0, 0),
    (2, 20, 2, 0, 0, 0, 0, 0, 0),
    (3, 30, 2, 10, 1, 0, 0, 0, 0),
    (4, 40, 2, 20, 1, 0, 0, 0, 0),
    (5, 50, 2, 30, 1, 0, 0, 0, 0),
    (6, 60, 3, 40, 2, 0, 0, 0, 0),
    (7, 70, 3, 50, 2, 10, 1, 0, 0),
    (8, 80, 3, 60, 2, 20, 1, 0, 0),
    (9, 90, 3, 70, 2, 30, 1, 0, 0),
    (10, -1, 3, 80, 2, 40, 1, 0, 0),
    (11, -1, 3, 90, 2, 50, 1, 10, 1),
    (12, -1, 3, -1, 2, 60, 1, 20, 1),
    (13, -1, 3, -1, 2, -1, 1, 60, 1),
]
_NONE = lambda n: [("none", 0, 0)] * n
WANT_T1 = _NONE(12) + [("arm", 1, 0), ("shd", 1, 0),
                       ("wpn", 1, 0), ("rng", 1, 0),
                       ("rng", 2, 0), ("wpn", 1, 0),
                       ("wpn", 2, 0), ("wpn", 1, 0)]
WANT_T2 = _NONE(12) + [("arm_set", 1, 2), ("arm", 4, 0),
                       ("wpn", 3, 0), ("wpn", 2, 0)]
WANT_T3 = _NONE(11) + [("arm_set", 3, 2), ("shd", 5, 0),
                       ("wpn", 4, 0), ("wpn", 3, 0),
                       ("wpn", 3, 0)]
WANT_T4 = _NONE(9) + [("arm_set", 4, 3), ("wpn", 1, 0),
                      ("none", 0, 0)]

# every source substring the retired region must carry
ASSERTS = [
    'struct ProfRow { int lo, hi, max; };',
    'const ProfRow kProfTable[PROF_COUNT] = {',
    'int profFor(int pctile) {',
    'int classForProf(int prof) {',
    'int characterLevelFor(rules::Dice& dice, int dungeonLevel,',
    'int henchmanLevelFor(int masterLevel) {',
    'bool raceAllowsClass(int race, int classIndex) {',
    'enum ItemKind { ITEM_NONE, ITEM_WPN, ITEM_RNG, ITEM_ARM, ITEM_SHD,',
    'struct ItemRow {',
    'const ItemRow kTableI[20] = {',
    'const ItemRow kTableII[16] = {',
    'const ItemRow kTableIII[16] = {',
    'const ItemRow kTableIV[12] = {',
    'const ItemRow& rollTable(rules::Dice& dice, const ItemRow* t, int n,',
    'void applyItem(const ItemRow& r, PartyMember& m) {',
    'const int kLadder[13][9] = {',
    'void rollMagicItemsFor(rules::Dice& dice, PartyMember& m) {',
    'applyItem(rollTable(dice, kTableI, 20, false), m)',
    'applyItem(rollTable(dice, kTableII, 16, true), m)',
    'applyItem(rollTable(dice, kTableIII, 16, true), m)',
    'applyItem(rollTable(dice, kTableIV, 12, false), m)',
]

# full-declaration tokens only (the R1036 lesson): none of
# these may survive the splice anywhere in encounters.cpp
RETIRED_TOKENS = [
    "struct ProfRow",
    "kProfTable",
    "struct ItemRow",
    "kTableI",
    "kTableII",
    "kTableIII",
    "kTableIV",
    "kLadder",
    "rollTable(",
]


def die(msg):
    sys.stderr.write("r1039_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the retired region out of dm/encounters.cpp
# ---------------------------------------------------------------------------

REGION_START = ("// R53: the Character Subtable "
                 "(DMG p.176), verbatim ranges and")
REGION_END = "CharacterParty rollCharacterParty(rules::Dice& dice,"
SEP = "// ----------------------------------------------------------------------------"


def parse_party_region(src):
    if "kProfTable" not in src:
        die("kProfTable not found (already spliced?)")
    i0 = src.index(REGION_START)
    i0 = src.rindex(SEP, 0, i0)
    i1 = src.index(REGION_END)
    region = src[i0:i1]

    for a in ASSERTS:
        if a not in region:
            die("assertion failed, the retired region must "
                "carry %r" % a)

    def arr(name):
        m = re.search(r"%s[^{]*\{(.*?)\};" % re.escape(name),
                      region, re.S)
        if not m:
            die("array %s not found" % name)
        return m.group(1)

    # the Character Subtable
    rows = re.findall(
        r"\{\s*(\d+),\s*(\d+),\s*(\d+)\s*\}",
        arr("const ProfRow kProfTable[PROF_COUNT]"))
    if len(rows) != N_SUB:
        die("parsed %d subtable rows (expected %d)"
            % (len(rows), N_SUB))
    sub = [(int(a), int(b), PROFS[i], int(c))
           for i, (a, b, c) in enumerate(rows)]
    if sub != WANT_SUB:
        die("character subtable drifted from the record")

    # the level-chance ladder
    rows = re.findall(
        r"\{\s*(\d+),\s*(-?\d+),\s*(\d+),\s*(-?\d+),\s*(\d+),"
        r"\s*(-?\d+),\s*(\d+),\s*(-?\d+),\s*(\d+)\s*\}",
        arr("const int kLadder[13][9]"))
    if len(rows) != N_LADDER:
        die("parsed %d ladder rows (expected %d)"
            % (len(rows), N_LADDER))
    ladder = [tuple(int(x) for x in r) for r in rows]
    if ladder != WANT_LADDER:
        die("magic ladder drifted from the record")

    # the four item tables
    items = {}
    for name, want in (("kTableI", WANT_T1), ("kTableII", WANT_T2),
                       ("kTableIII", WANT_T3),
                       ("kTableIV", WANT_T4)):
        rows = re.findall(
            r"\{(ITEM_\w+),\s*(\d+),\s*(\d+)\s*\}",
            arr("const ItemRow " + name))
        got = [(KIND_TOKENS[a], int(b), int(c))
               for a, b, c in rows]
        if got != want:
            die("item table %s drifted from the record "
                "(%d rows parsed)" % (name, len(got)))
        items[name] = got

    # verbatim slices the seam keeps (never hand-transcribed)
    c53 = region[:region.index("namespace {")].rstrip() + "\n"
    enum_prof = (region[region.index("enum ProfId"):
                         region.index("const ProfRow kProfTable")]
                 .rstrip() + "\n")
    classfor = (region[region.index(
                    "// engine class per profession"):
                region.index("// DMG p.176: character level")]
                .rstrip() + "\n")
    mid = (region[region.index("// DMG p.176: character level"):
                  region.index("} // namespace")].rstrip() + "\n")
    r55i = region.index("// R55: DMG p.176-177 party magic items")
    c55 = region[region.rindex(SEP, 0, r55i):
                 region.index("namespace {", r55i)]
    enum_item = (region[region.index("enum ItemKind"):
                         region.index("struct ItemRow")]
                 .rstrip() + "\n")
    # the whitespace between the region tail and the
    # rollCharacterParty header, preserved byte-exact
    rlast = region.rindex("} // namespace")
    tail_ws = region[rlast + len("} // namespace"):]
    if tail_ws != "\n\n":
        die("unexpected tail whitespace %r before "
            "rollCharacterParty" % tail_ws)
    return (i0, i1, sub, ladder, items,
            c53, enum_prof, classfor, mid, c55, enum_item)


# ---------------------------------------------------------------------------
# 2. gate data + lua emission + round-trip
# ---------------------------------------------------------------------------

def gate_data(sub, ladder, items):
    problems = []
    prev = 0
    for lo, hi, prof, mx in sub:
        if lo != prev + 1 or hi < lo or hi > 100:
            problems.append("subtable band %r" % ((lo, hi),))
        if prof not in PROFS:
            problems.append("prof token %r" % prof)
        if mx < 1 or mx > 5:
            problems.append("max %r" % ((prof, mx),))
        prev = hi
    if prev != 100:
        problems.append("subtable chain ends at %d" % prev)
    for i, r in enumerate(ladder):
        if r[0] != i + 1:
            problems.append("ladder level %r" % (r[0],))
        for j in (1, 3, 5, 7):
            if r[j] < -1 or r[j] > 100:
                problems.append("ladder pct %r" % (r,))
        for j in (2, 4, 6, 8):
            if r[j] < 0 or r[j] > 3:
                problems.append("ladder count %r" % (r,))
    for name, rows in items.items():
        for i, (kind, a, b) in enumerate(rows):
            if kind not in KIND_TOKENS.values():
                problems.append("kind token %r" % kind)
            if a < 0 or a > 5 or b < 0 or b > 5:
                problems.append("item pluses %r" % ((kind, a, b),))
            if kind == "none" and (a != 0 or b != 0):
                problems.append("none row with pluses %r"
                                % ((a, b),))
    return problems


LUA_HDR = """-- encounter table def: %(key)s
-- The R53/R55 party family (R1039 de-wire): %(what)s
-- (DMG Appendix C Premium reprint p.176-177, OCR-verified).
-- %(note)s
-- DO NOT hand-edit: tools/r1039_splice.py is the only writer.

"""


def lua_file(key, what, note, body):
    return (LUA_HDR % dict(key=key, what=what, note=note)
            + "return {\n"
            + '  key = "%s",\n' % key
            + body
            + "}\n")


def emit_lua(sub, ladder, items):
    os.makedirs(LUA_DIR, exist_ok=True)
    texts = {}

    b = "  rows = {\n"
    for lo, hi, prof, mx in sub:
        b += ('    { band = {%d,%d}, prof = "%s", max = %d },\n'
              % (lo, hi, prof, mx))
    b += "  },\n"
    texts["character_subtable.lua"] = lua_file(
        "character_subtable", "the Character Subtable",
        "band = the percentile column; prof = the printed "
        "profession token; max = the per-profession maximum "
        "per party (the DMG \"ignore such rolls\" advice). The "
        "monk-or-bard row shares the monk_bard token (the R1038 "
        "convention).", b)

    b = "  rows = {\n"
    for r in ladder:
        b += ("    { level = %d, t1pct = %d, t1n = %d, "
              "t2pct = %d, t2n = %d, "
              "t3pct = %d, t3n = %d, "
              "t4pct = %d, t4n = %d },\n" % r)
    b += "  },\n"
    texts["magic_ladder.lua"] = lua_file(
        "magic_ladder", "the level-chance ladder",
        "level = the character level (13+ reads row 13); "
        "tNpct = the chance per Table N roll (percentile x "
        "level; -1 = automatic, the printed \"3 items\" rows); "
        "tNn = the number of Table N rolls.", b)

    for name, key in (("kTableI", "magic_table_1"),
                      ("kTableII", "magic_table_2"),
                      ("kTableIII", "magic_table_3"),
                      ("kTableIV", "magic_table_4")):
        b = "  rows = {\n"
        for i, (kind, a, bb) in enumerate(items[name]):
            b += ('    { die = %d, kind = "%s", a = %d, b = %d },\n'
                  % (i + 1, kind, a, bb))
        b += "  },\n"
        texts[key + ".lua"] = lua_file(
            key, "MAGIC ITEM TABLE %s" % key[-1],
            "die = the die face (the table's own notation, "
            "1-20 / the 16-face \"(d8, d6)\" reading / 1-12 - "
            "the half-dice split stays engine-side); kind = "
            "the item-kind token (none / wpn / rng / arm / shd "
            "/ arm_set); a, b = the pluses (b = the shield "
            "plus on arm_set rows). Fiction-only rows ride "
            "kind = none (the R55 convention).", b)

    if len(texts) != FILES:
        die("emitted %d lua files (expected %d)"
            % (len(texts), FILES))
    for name in sorted(texts):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(texts[name])


def lua_roundtrip(sub, ladder, items):
    def read(name):
        with open(os.path.join(LUA_DIR, name)) as f:
            return f.read()

    t = read("character_subtable.lua")
    got = re.findall(
        r'\{ band = \{(\d+),(\d+)\}, prof = "(\w+)", max = (\d+) \}',
        t)
    got = [(int(a), int(b), c, int(d)) for a, b, c, d in got]
    if got != sub:
        die("round-trip: character_subtable mismatch")

    t = read("magic_ladder.lua")
    got = re.findall(
        r'\{ level = (\d+), t1pct = (-?\d+), t1n = (\d+), '
        r't2pct = (-?\d+), t2n = (\d+), '
        r't3pct = (-?\d+), t3n = (\d+), '
        r't4pct = (-?\d+), t4n = (\d+) \}', t)
    got = [tuple(int(x) for x in r) for r in got]
    if got != ladder:
        die("round-trip: magic_ladder mismatch")

    for name, key in (("kTableI", "magic_table_1"),
                      ("kTableII", "magic_table_2"),
                      ("kTableIII", "magic_table_3"),
                      ("kTableIV", "magic_table_4")):
        t = read(key + ".lua")
        got = re.findall(
            r'\{ die = (\d+), kind = "(\w+)", a = (\d+), b = (\d+) \}',
            t)
        got = [(int(a), b, int(c), int(d)) for a, b, c, d in got]
        want = [(i + 1,) + r for i, r in enumerate(items[name])]
        if got != want:
            die("round-trip: %s mismatch" % key)


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


def replace_exact(text, old, new, count, where):
    n = text.count(old)
    if n != count:
        die("%s: anchor appears %d times (expected %d)"
            % (where, n, count))
    return text.replace(old, new)


H_COMMENT_OLD = """// tools/r1037_splice.py (psionic family) and
// tools/r1038_splice.py (castle family) are the only writers."""
H_COMMENT_NEW = """// tools/r1037_splice.py (psionic family),
// tools/r1038_splice.py (castle family) and
// tools/r1039_splice.py (party family) are the only writers."""

H_STRUCT_ANCHOR = """struct EncounterCastleRow {
    int lo = 0, hi = 0;
    std::string size;
    std::string cat;
    std::string key;
    std::string type;
    std::string prof;
    int lvlLo = 0, lvlHi = 0;
    int n1 = 0, n2 = 0, n3 = 0;
};"""
H_STRUCT_NEW = H_STRUCT_ANCHOR + """

// R1039: the party family row (the R53/R55 de-wire). The six
// printed tables ride one row shape: lo/hi = the Character
// Subtable percentile band, or the ladder row's level, or the
// item table's die face (lo == hi for the unbanded rows);
// prof = the subtable profession token; kind = the item-kind
// token (none/wpn/rng/arm/shd/arm_set); max = the subtable
// per-party maximum; a/b = the item pluses (b = the shield
// plus on arm_set rows); t1pct..t4n = the ladder's per-table
// chance and count (pct -1 = automatic). Unused columns stay
// defaulted - the per-file key lists in the loader keep each
// file strict (the R1034 dispatch-order lesson).
struct EncounterPartyRow {
    int lo = 0, hi = 0;
    std::string prof;
    std::string kind;
    int max = 0;
    int a = 0, b = 0;
    int t1pct = 0, t1n = 0, t2pct = 0, t2n = 0;
    int t3pct = 0, t3n = 0, t4pct = 0, t4n = 0;
};"""

H_ACC_ANCHOR = """    const std::vector<EncounterCastleRow>& castleRows(
        const std::string& name) const;"""
H_ACC_NEW = H_ACC_ANCHOR + """
    // R1039: the party family views. name: character_subtable /
    // magic_ladder / magic_table_1 / magic_table_2 /
    // magic_table_3 / magic_table_4.
    bool hasParty(const std::string& name) const;
    const std::vector<EncounterPartyRow>& partyRows(
        const std::string& name) const;"""

H_MEM_ANCHOR = """    std::map<std::string, std::vector<EncounterCastleRow>>
        m_castle;"""
H_MEM_NEW = H_MEM_ANCHOR + """
    // R1039: the party family (the six printed R53/R55
    // tables; the ladder and item rows ride the same shape,
    // keyed by level / die face instead of a band).
    std::map<std::string, std::vector<EncounterPartyRow>>
        m_party;"""

CPP_KEYS_ANCHOR = """const char* const kCastleArtilleryKeys[] =
    { "type", "ballistae", "lightCatapults", "oilCauldrons",
      nullptr };"""
CPP_KEYS_NEW = CPP_KEYS_ANCHOR + """
// R1039: the party family file/row keys. Exact keys only -
// no prefix, no exceptions (the R1034 dispatch-order
// lesson); the per-table row key lists below keep each
// file's shape strict.
const char* const kPartyFileKeys[] = { "key", "rows", nullptr };
const char* const kPartySubKeys[] =
    { "band", "prof", "max", nullptr };
const char* const kPartyLadderKeys[] =
    { "level", "t1pct", "t1n", "t2pct", "t2n",
      "t3pct", "t3n", "t4pct", "t4n", nullptr };
const char* const kPartyItemKeys[] =
    { "die", "kind", "a", "b", nullptr };"""

CPP_ELSE_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_BRANCH = """    } else if (key == "character_subtable"
               || key == "magic_ladder"
               || key == "magic_table_1"
               || key == "magic_table_2"
               || key == "magic_table_3"
               || key == "magic_table_4") {
        const int t = lua_gettop(L);
        const char* const* rowKeys = kPartyItemKeys;
        if (key == "character_subtable")
            rowKeys = kPartySubKeys;
        else if (key == "magic_ladder")
            rowKeys = kPartyLadderKeys;
        if (!checkAllowedKeys(L, t, kPartyFileKeys, key, &err)) goto bad;
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
            std::vector<EncounterPartyRow> rows;
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
                EncounterPartyRow row;
                if (key == "character_subtable") {
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
                    lua_getfield(L, rt, "max");
                    if (!lua_isinteger(L, -1)) {
                        err = "max is not an integer";
                        goto bad;
                    }
                    const long long mx = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (mx < 1 || mx > 5) {
                        err = "max outside 1-5";
                        goto bad;
                    }
                    row.max = (int)mx;
                } else if (key == "magic_ladder") {
                    lua_getfield(L, rt, "level");
                    if (!lua_isinteger(L, -1)) {
                        err = "level is not an integer";
                        goto bad;
                    }
                    const long long lvl = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (lvl != prev + 1 || lvl < 1 || lvl > 13) {
                        err = "level must continue 1-13 in order";
                        goto bad;
                    }
                    row.lo = row.hi = (int)lvl;
                    prev = (int)lvl;
                    static const char* const kLad[8] = {
                        "t1pct", "t1n", "t2pct", "t2n",
                        "t3pct", "t3n", "t4pct", "t4n" };
                    long long lv[8];
                    for (int j = 0; j < 8; ++j) {
                        lua_getfield(L, rt, kLad[j]);
                        if (!lua_isinteger(L, -1)) {
                            err = std::string(kLad[j])
                                + " is not an integer";
                            goto bad;
                        }
                        lv[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    for (int j = 0; j < 8; ++j) {
                        if ((j % 2 == 0 && (lv[j] < -1 || lv[j] > 100))
                            || (j % 2 == 1 && (lv[j] < 0 || lv[j] > 3))) {
                            err = std::string(kLad[j])
                                + " outside the printed range";
                            goto bad;
                        }
                    }
                    row.t1pct = (int)lv[0]; row.t1n = (int)lv[1];
                    row.t2pct = (int)lv[2]; row.t2n = (int)lv[3];
                    row.t3pct = (int)lv[4]; row.t3n = (int)lv[5];
                    row.t4pct = (int)lv[6]; row.t4n = (int)lv[7];
                } else {
                    // magic_table_1 .. magic_table_4
                    lua_getfield(L, rt, "die");
                    if (!lua_isinteger(L, -1)) {
                        err = "die is not an integer";
                        goto bad;
                    }
                    const long long die = lua_tointeger(L, -1);
                    lua_pop(L, 1);
                    if (die != prev + 1 || die < 1 || die > 100) {
                        err = "die faces must continue from 1 in order";
                        goto bad;
                    }
                    row.lo = row.hi = (int)die;
                    prev = (int)die;
                    if (!getStr(L, rt, "kind", &row.kind, &err))
                        goto bad;
                    static const char* const kKinds[] = {
                        "none", "wpn", "rng", "arm", "shd",
                        "arm_set", nullptr };
                    bool ok = false;
                    for (int p = 0; kKinds[p]; ++p)
                        if (row.kind == kKinds[p]) { ok = true; break; }
                    if (!ok) {
                        err = "unknown item-kind token '" + row.kind + "'";
                        goto bad;
                    }
                    static const char* const kPlus[2] = { "a", "b" };
                    long long pv[2];
                    for (int j = 0; j < 2; ++j) {
                        lua_getfield(L, rt, kPlus[j]);
                        if (!lua_isinteger(L, -1)) {
                            err = std::string(kPlus[j])
                                + " is not an integer";
                            goto bad;
                        }
                        pv[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                        if (pv[j] < 0 || pv[j] > 5) {
                            err = std::string(kPlus[j])
                                + " outside 0-5";
                            goto bad;
                        }
                    }
                    row.a = (int)pv[0]; row.b = (int)pv[1];
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (key == "character_subtable" && prev != 100) {
                err = "bands do not reach 100";
                goto bad;
            }
            if (key == "magic_ladder" && prev != 13) {
                err = "ladder does not reach level 13";
                goto bad;
            }
            if (m_party.count(key)) { err = "duplicate def key";
                                       goto bad; }
            m_party[key] = rows;
        }
"""

CPP_ACC_ANCHOR = """const std::vector<EncounterCastleRow>&
EncounterTableRegistry::castleRows(
    const std::string& name) const {
    static const std::vector<EncounterCastleRow> none;
    auto it = m_castle.find(name);
    return it == m_castle.end() ? none : it->second;
}"""
CPP_ACC_NEW = CPP_ACC_ANCHOR + """

bool EncounterTableRegistry::hasParty(
    const std::string& name) const {
    return m_party.count(name) != 0;
}

const std::vector<EncounterPartyRow>&
EncounterTableRegistry::partyRows(
    const std::string& name) const {
    static const std::vector<EncounterPartyRow> none;
    auto it = m_party.find(name);
    return it == m_party.end() ? none : it->second;
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
                   '"content/tables/encounters_castle");')
ENC_LOAD_NEW = (ENC_LOAD_ANCHOR + '\n'
                '        reg.loadDirectory('
                '"content/tables/encounters_party");')

REGTEST_OLD = ('    #include "rules/audits/'
               'r1038_castle_encounter_registry.h"  // R1038')
REGTEST_NEW = (REGTEST_OLD + '\n'
               '    #include "rules/audits/'
               'r1039_party_encounter_registry.h"  // R1039')

PROF_MAX_OLD = ("if (perProf[cand] >= kProfTable[cand].max) "
                "continue;")
PROF_MAX_NEW = "if (perProf[cand] >= profMax(cand)) continue;"


def seam_body(c53, enum_prof, classfor, mid, c55, enum_item):
    return (
        c53 + "\n"
        + "namespace {\n\n"
        + enum_prof + "\n"
        + """// R1039 (the registry-native de-wire, the R1032-R1038
// shape): the printed Character Subtable retired into
// content/tables/encounters_party/character_subtable.lua -
// the percentile bands, the profession tokens and the
// per-party maxima all ride the registry now (the enums map
// here). classForProf, characterLevelFor and henchmanLevelFor
// stay verbatim below (mechanics, not tables); the R62 race
// allowance and raceAllowsClass stay untouched between the
// blocks. profFor keeps its signature (the R64 city, R65
// planar and rollCharacterParty callers); the retired
// per-profession maxima reads became profMax(cand).

// the registry-backed static cache (the R1032-R1038 idiom)
static const std::vector<dm::EncounterPartyRow>& partyView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterPartyRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, dm::encReg().partyRows(name)).first;
    return it->second;
}

// the printed token -> the dm-local ProfId (the R1038 idiom;
// a distinct name - the castle seam's profForToken lives in
// this same unnamed namespace below). Unknown tokens read as
// fighter (the classForProf default).
static int subtableProfForToken(const std::string& t) {
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

// DMG p.176: profession by percentile - the printed ranges
// now ride the registry (defensive default: fighter, the
// column covers 01-00).
int profFor(int pctile) {
    for (const auto& r : partyView("character_subtable"))
        if (pctile >= r.lo && pctile <= r.hi)
            return subtableProfForToken(r.prof);
    return PROF_FIGHTER;
}

// the per-profession maximum off the same table (the retired
// maxima reads in rollCharacterParty).
int profMax(int prof) {
    for (const auto& r : partyView("character_subtable"))
        if (subtableProfForToken(r.prof) == prof)
            return r.max;
    return 1;   // defensive
}

"""
        + classfor + "\n"
        + mid + "\n"
        + "} // namespace\n"
        + "\n"
        + c55
        + "namespace {\n\n"
        + enum_item + "\n"
        + """// the printed kind token -> ItemKind (unknown reads as
// none - fiction only, the retired default).
static int kindForToken(const std::string& t) {
    if (t == "wpn")     return ITEM_WPN;
    if (t == "rng")     return ITEM_RNG;
    if (t == "arm")     return ITEM_ARM;
    if (t == "shd")     return ITEM_SHD;
    if (t == "arm_set") return ITEM_ARM_SET;
    return ITEM_NONE;
}

// one row off a die-indexed item table (the retired rollTable).
// Table II/III keep the printed "(d8, d6)" reading: d8 within
// a half, d6 1-3/4-6 picking the half (a uniform 1-16 reading
// of the two-dice notation).
static const dm::EncounterPartyRow& rollPartyTable(
        rules::Dice& dice, const char* name, bool halfDice) {
    static const dm::EncounterPartyRow none{};
    const auto& rows = partyView(name);
    const int n = (int)rows.size();
    if (n <= 0) return none;   // defensive
    int row;
    if (halfDice)   // "(d8, d6)": d6 1-3 -> first half, 4-6 second
        row = (int)dice.roll(1, 8, 0) +
              ((int)dice.roll(1, 6, 0) > 3 ? n / 2 : 0) - 1;
    else
        row = (int)dice.roll(1, (uint32_t)n, 0) - 1;
    if (row < 0) row = 0;
    if (row >= n) row = n - 1;
    return rows[(size_t)row];
}

void applyItem(const dm::EncounterPartyRow& r, PartyMember& m) {
    switch (kindForToken(r.kind)) {
        case ITEM_WPN: if (r.a > m.wpnPlus) m.wpnPlus = r.a; break;
        case ITEM_RNG: if (r.a > m.rngPlus) m.rngPlus = r.a; break;
        case ITEM_ARM: if (r.a > m.armPlus) m.armPlus = r.a; break;
        case ITEM_SHD: if (r.a > m.shdPlus) m.shdPlus = r.a; break;
        case ITEM_ARM_SET:
            if (r.a > m.armPlus) m.armPlus = r.a;
            if (r.b > m.shdPlus) m.shdPlus = r.b;
            break;
        default: break;   // unmodeled device (fiction only)
    }
}

// DMG p.176-177: the level-chance ladder and the item rolls -
// the tables now ride the registry (magic_ladder.lua,
// magic_table_1..4.lua); pct -1 = automatic, level 13+ uses
// the 13th row, men-at-arms get nothing (level < 1).
void rollMagicItemsFor(rules::Dice& dice, PartyMember& m) {
    if (m.level < 1) return;   // men-at-arms: hp is all they need
    int li = m.level - 1;
    if (li > 12) li = 12;
    static const dm::EncounterPartyRow none{};
    const auto& lad = partyView("magic_ladder");
    const dm::EncounterPartyRow& row =
        (size_t)li < lad.size() ? lad[(size_t)li] : none;
    for (int t = 0; t < row.t1n; ++t)                     // Table I
        if (row.t1pct < 0 || (int)dice.roll(1, 100, 0) <= row.t1pct)
            applyItem(rollPartyTable(dice, "magic_table_1", false), m);
    for (int t = 0; t < row.t2n; ++t)                     // Table II
        if (row.t2pct < 0 || (int)dice.roll(1, 100, 0) <= row.t2pct)
            applyItem(rollPartyTable(dice, "magic_table_2", true), m);
    for (int t = 0; t < row.t3n; ++t)                     // Table III
        if (row.t3pct < 0 || (int)dice.roll(1, 100, 0) <= row.t3pct)
            applyItem(rollPartyTable(dice, "magic_table_3", true), m);
    for (int t = 0; t < row.t4n; ++t)                     // Table IV
        if (row.t4pct < 0 || (int)dice.roll(1, 100, 0) <= row.t4pct)
            applyItem(rollPartyTable(dice, "magic_table_4", false), m);
}

} // namespace

"""
        )


# ---------------------------------------------------------------------------
# 5. the fragment (7 sections, derived pins)
# ---------------------------------------------------------------------------

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


def build_fragment(sub, ladder, items):
    L = []
    A = L.append

    # -- derived pin lines (plain appends only - the R1037
    #    %% leak lesson: no % formatting of template blocks) --
    sub_pins = "".join(
        "        { const auto& r = rs[%d];\n"
        "          if (r.lo != %d || r.hi != %d) ++bad;\n"
        "          if (r.prof != \"%s\") ++bad;\n"
        "          if (r.max != %d) ++bad; }\n"
        % (i, lo, hi, prof, mx)
        for i, (lo, hi, prof, mx) in enumerate(sub))

    lad_pins = "".join(
        "        { const auto& r = ereg.partyRows("
        "\"magic_ladder\")[%d];\n"
        "          if (r.lo != %d || r.hi != %d) ++bad;\n"
        "          if (r.t1pct != %d || r.t1n != %d) ++bad;\n"
        "          if (r.t2pct != %d || r.t2n != %d) ++bad;\n"
        "          if (r.t3pct != %d || r.t3n != %d) ++bad;\n"
        "          if (r.t4pct != %d || r.t4n != %d) ++bad; }\n"
        % (i, r[0], r[0], r[1], r[2], r[3], r[4], r[5], r[6],
           r[7], r[8])
        for i, r in enumerate(ladder))

    item_pins = ""
    for name, key in (("kTableI", "magic_table_1"),
                      ("kTableII", "magic_table_2"),
                      ("kTableIII", "magic_table_3"),
                      ("kTableIV", "magic_table_4")):
        item_pins += ("        { const auto& tab = ereg.partyRows("
                      "\"%s\");\n" % key)
        for i, (kind, a, b) in enumerate(items[name]):
            item_pins += (
                "          { const auto& r = tab[%d];\n"
                "            if (r.lo != %d || r.hi != %d) ++bad;\n"
                "            if (r.kind != \"%s\") ++bad;\n"
                "            if (r.a != %d || r.b != %d) ++bad; }\n"
                % (i, i + 1, i + 1, kind, a, b))
        item_pins += "        }\n"

    A("""// ============================================================================
// Adnd1 - rules/audits/r1039_party_encounter_registry.h  (R1039)
// The R53/R55 party family battery audit, the R1032-R1038
// shape: the registry load, exact table counts and the
// percentile/level/die chains, the full Character Subtable
// pins (bands, profession tokens, per-party maxima), the
// full 13-row level-chance ladder, the full four item
// tables (every die face), the rollCharacterParty semantics
// (men-at-arms vs henchmen, level caps, plus bounds), and
// the cross-region callers (the R1038 castle master and
// patrol still ride the retired tables through
// rollMagicItemsFor). Expected: 6 party files - the
// Character Subtable (10 rows), the level-chance ladder (13
// rows) and MAGIC ITEM TABLES I-IV (20/16/16/12 rows) - all
// derived from the DMG record (Premium reprint p.176-177)
// the splice parsed. The enums ride as printed tokens; the
// class/level/henchman mechanics and the half-dice reading
// stay engine-side.
// ============================================================================
{
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 6 party files, zero errors, one reg --
    bad = 0;
    {
        const int nf = ereg.loadDirectory(
            "content/tables/encounters_party");
        if (nf != 6) ++bad;
        if (!ereg.errors().empty()) ++bad;
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
        if (!ereg.hasParty("character_subtable")) ++bad;
        if (!ereg.hasParty("magic_ladder")) ++bad;
        if (!ereg.hasParty("magic_table_1")) ++bad;
        if (!ereg.hasParty("magic_table_2")) ++bad;
        if (!ereg.hasParty("magic_table_3")) ++bad;
        if (!ereg.hasParty("magic_table_4")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // every negative names a key ABSENT from that map -
        // the R1038 phantom-pin lesson)
        if (ereg.hasParty("")) ++bad;
        if (ereg.hasParty("castle_type")) ++bad;
        if (ereg.hasParty("magic_table_5")) ++bad;
        if (ereg.hasCastle("character_subtable")) ++bad;
        if (ereg.hasPlanar("character_subtable")) ++bad;
        if (ereg.hasPlanarBands("character_subtable")) ++bad;
        if (ereg.hasWater("character_subtable")) ++bad;
        if (ereg.hasOutdoor("character_subtable")) ++bad;
        if (ereg.hasCityBands("character_subtable")) ++bad;
        // the earlier families still load clean
        if (!ereg.hasCastle("castle_master")) ++bad;
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        if ((int)ereg.list("psionic_spell_exact").size()
            != 20) ++bad;
    }
    printf("R1039 party encounter registry load audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 2. counts: rows and the printed chains ----------
    bad = 0;
    {
        if ((int)ereg.partyRows("character_subtable").size()
            != 10) ++bad;
        if ((int)ereg.partyRows("magic_ladder").size()
            != 13) ++bad;
        if ((int)ereg.partyRows("magic_table_1").size()
            != 20) ++bad;
        if ((int)ereg.partyRows("magic_table_2").size()
            != 16) ++bad;
        if ((int)ereg.partyRows("magic_table_3").size()
            != 16) ++bad;
        if ((int)ereg.partyRows("magic_table_4").size()
            != 12) ++bad;
        // the subtable bands chain 01-00
        {
            const auto& rs = ereg.partyRows(
                "character_subtable");
            int lo = 1;
            for (const auto& r : rs) {
                if (r.lo != lo) ++bad;          // contiguous
                if (r.hi < r.lo || r.hi > 100) ++bad;
                lo = r.hi + 1;
            }
            if (lo != 101) ++bad;                // 01-00
        }
        // the ladder levels chain 1-13
        {
            const auto& rs = ereg.partyRows("magic_ladder");
            int lvl = 1;
            for (const auto& r : rs) {
                if (r.lo != lvl || r.hi != lvl) ++bad;
                ++lvl;
            }
            if (lvl != 14) ++bad;
        }
        // the item die faces chain from 1
        const char* const tabs[4] = {
            "magic_table_1", "magic_table_2",
            "magic_table_3", "magic_table_4" };
        for (int t = 0; t < 4; ++t) {
            const auto& rs = ereg.partyRows(tabs[t]);
            int d = 1;
            for (const auto& r : rs) {
                if (r.lo != d || r.hi != d) ++bad;
                ++d;
            }
            if (d != (int)rs.size() + 1) ++bad;
        }
        // the pluses and maxima stay printed
        for (const auto& r :
             ereg.partyRows("character_subtable"))
            if (r.max < 1 || r.max > 5) ++bad;
        for (int t = 0; t < 4; ++t)
            for (const auto& r : ereg.partyRows(tabs[t]))
                if (r.a < 0 || r.a > 5
                    || r.b < 0 || r.b > 5) ++bad;
    }
    printf("R1039 party encounter registry counts audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 3. subtable: every row pinned -------------------
    bad = 0;
    {
        const auto& rs = ereg.partyRows("character_subtable");
""")
    A(sub_pins)
    A("""    }
    printf("R1039 party encounter registry subtable audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 4. ladder: every row, every field ----------------
    bad = 0;
    {
""")
    A(lad_pins)
    A("""    }
    printf("R1039 party encounter registry ladder audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 5. items: every die face of all four tables ------
    bad = 0;
    {
""")
    A(item_pins)
    A("""    }
    printf("R1039 party encounter registry items audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 6. party: the rollCharacterParty semantics -------
    bad = 0;
    {
        rules::Rng rng(1039);
        rules::Dice dice(rng);
        // low dungeon: 2-5 characters + 0-level men-at-arms
        for (int i = 0; i < 500; ++i) {
            dm::CharacterParty p =
                dm::rollCharacterParty(dice, 1, 1);
            if ((int)p.members.size() != 9) ++bad;
            int men = 0, chars = 0;
            for (const auto& m : p.members) {
                if (m.classIndex != rules::CLASS_FIGHTER
                    && m.classIndex != rules::CLASS_CLERIC
                    && m.classIndex != rules::CLASS_MAGIC_USER
                    && m.classIndex != rules::CLASS_THIEF) ++bad;
                if (m.manAtArms) {
                    ++men;
                    if (m.level != 0) ++bad;
                    if (m.classIndex != rules::CLASS_FIGHTER)
                        ++bad;
                } else {
                    ++chars;
                    if (m.level < 1 || m.level > 4) ++bad;
                    if (m.wpnPlus < 0 || m.wpnPlus > 4) ++bad;
                    if (m.rngPlus < 0 || m.rngPlus > 2) ++bad;
                    if (m.armPlus < 0 || m.armPlus > 4) ++bad;
                    if (m.shdPlus < 0 || m.shdPlus > 5) ++bad;
                }
            }
            if (chars < 2 || chars > 5) ++bad;
            if (men != 9 - chars) ++bad;
        }
        // deep dungeon: the followers are henchmen instead
        for (int i = 0; i < 500; ++i) {
            dm::CharacterParty p =
                dm::rollCharacterParty(dice, 10, 10);
            if ((int)p.members.size() != 9) ++bad;
            int hench = 0;
            for (const auto& m : p.members) {
                if (m.henchman) {
                    ++hench;
                    if (m.level < 1) ++bad;
                    if (m.manAtArms) ++bad;
                }
                if (m.level > 12) ++bad;   // characterLevelFor cap
            }
            if (hench < 4 || hench > 7) ++bad;
        }
    }
    printf("R1039 party encounter registry party audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 7. roll: the cross-region callers still ride ----
    bad = 0;
    {
        rules::Rng rng(1039);
        rules::Dice dice(rng);
        // the R1038 castle master rolls the R55 ladder and
        // the R53 helpers (levels 9-23, pluses bounded)
        for (int i = 0; i < 2000; ++i) {
            dm::PartyMember m = dm::rollCastleMaster(
                dice, 1 + i % 100);
            if (m.level < 9 || m.level > 23) ++bad;
            if (m.wpnPlus < 0 || m.wpnPlus > 4) ++bad;
            if (m.armPlus < 0 || m.armPlus > 4) ++bad;
            if (m.shdPlus < 0 || m.shdPlus > 5) ++bad;
        }
        // patrols ride the same construction
        for (int i = 0; i < 100; ++i) {
            dm::CharacterParty p =
                dm::rollPatrol(dice, i % 2 != 0);
            const int n = (int)p.members.size();
            if (n < 20 || n > 34) ++bad;
            int men = 0;
            for (const auto& m : p.members)
                if (m.manAtArms) ++men;
            if (men < 16 || men > 28) ++bad;
        }
    }
    printf("R1039 party encounter registry roll audit: bad %d\\n", bad);
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

CENSUS_PRE = 990
CENSUS_POST = 997


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
    if ("// tools/r1039_splice.py (party family)"
            in h):
        # already applied: verify the landing state
        with open(ENC, encoding="utf-8") as f:
            enc = f.read()
        if "kProfTable" in enc:
            die("already applied but kProfTable is "
                "still in dm/encounters.cpp")
        if census_count() != CENSUS_POST:
            die("already applied but census is %d "
                "(expected %d)"
                % (census_count(), CENSUS_POST))
        for name in ("character_subtable.lua",
                     "magic_ladder.lua", "magic_table_1.lua",
                     "magic_table_2.lua", "magic_table_3.lua",
                     "magic_table_4.lua"):
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
    (i0, i1, sub, ladder, items,
     c53, enum_prof, classfor, mid, c55, enum_item) = \
        parse_party_region(src)
    problems = gate_data(sub, ladder, items)
    if problems:
        die("data gate: %s" % "; ".join(problems))
    print("parsed: subtable %d rows, ladder %d rows, "
          "items %d/%d/%d/%d"
          % (len(sub), len(ladder), len(items["kTableI"]),
             len(items["kTableII"]), len(items["kTableIII"]),
             len(items["kTableIV"])))

    # -- lua + registry -------------------------------------
    emit_lua(sub, ladder, items)
    lua_roundtrip(sub, ladder, items)
    print("round-trip: %d lua files parse back byte-exact"
          % FILES)
    extend_registry()

    # -- the encounters.cpp seam ----------------------------
    new_enc = (src[:i0]
               + seam_body(c53, enum_prof, classfor, mid,
                           c55, enum_item)
               + src[i1:])
    new_enc = replace_once(new_enc, ENC_LOAD_ANCHOR,
                           ENC_LOAD_NEW, "enc load anchor")
    new_enc = replace_exact(new_enc, PROF_MAX_OLD,
                            PROF_MAX_NEW, 2,
                            "rollCharacterParty profMax reads")
    for tok in RETIRED_TOKENS:
        if tok in new_enc:
            die("retired token %r survived the splice"
                % tok)
    with open(ENC, "w", encoding="utf-8") as f:
        f.write(new_enc)

    # -- the fragment + the regtest include -----------------
    frag = build_fragment(sub, ladder, items)
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
