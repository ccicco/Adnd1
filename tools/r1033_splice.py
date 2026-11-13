#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1033_splice.py  (R1033)
# The water encounter table de-wire, the R1032 shape: the retired
# kFreshShallow/kFreshDeep/kSaltShallow/kSaltDeep/kDinoSub arrays of
# dm/encounters.cpp (R60 underwater set, DMG Appendix C Premium
# reprint p.179-181) and kWaterFreshSmall/kWaterFreshLarge/
# kWaterSaltShallow/kWaterSaltDeep (R127 waterborne set, p.190) are
# extracted verbatim into content/tables/encounters_water/*.lua and
# load through dm::EncounterTableRegistry (extended here with the
# water family: EncounterWaterRow rows, underwater_*/waterborne_*/
# dinosaur_sub keys). The water directory is a sibling of
# content/tables/encounters/ so the R1032 audit's 20-file pin and
# the R127 line-diff pins stay untouched. rollWaterEncounter(),
# rollWaterborneEncounter(), waterEncounterKeys(),
# waterborneEncounterKeys(), waterborneBands() and
# dinosaurSubBands() keep their signatures and behavior - they read
# registry-backed views (the R1032 misc-engine pattern).
# This script is the only writer of the lua files and the R1033
# battery fragment; it is idempotent (run twice = "applied 0").
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
LUA_DIR = os.path.join(ROOT, "content", "tables", "encounters_water")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1033_water_encounter_registry.h")

# ---- table inventory: retired C++ array -> registry key --------------------
TABLES = [
    ("kFreshShallow",     "underwater_fresh_shallow"),
    ("kFreshDeep",        "underwater_fresh_deep"),
    ("kSaltShallow",      "underwater_salt_shallow"),
    ("kSaltDeep",         "underwater_salt_deep"),
    ("kDinoSub",          "dinosaur_sub"),
    ("kWaterFreshSmall",  "waterborne_fresh_small"),
    ("kWaterFreshLarge",  "waterborne_fresh_large"),
    ("kWaterSaltShallow", "waterborne_salt_shallow"),
    ("kWaterSaltDeep",    "waterborne_salt_deep"),
]
FLAGS = {"WF_NONE": 0, "WF_COOL_ONLY": 1, "WF_WARM_ONLY": 2,
         "WF_DEEP_ONLY": 4}
FLAG_COMMENT = {0: "no gate", 1: "cool only", 2: "warm only",
                4: "deep water only"}
MON_DIR = os.path.join(ROOT, "content", "monsters")


def die(msg):
    sys.stderr.write("SPLICE FAIL: " + msg + "\n")
    sys.exit(1)


def md5(path):
    with open(path, "rb") as f:
        return hashlib.md5(f.read()).hexdigest()


def monster_exists(key):
    # reg.find() proxy: the monster registry loads content/monsters/
    # <first letter>/<key>.lua (the R74 directory contract).
    p = os.path.join(MON_DIR, key[0], key + ".lua")
    return os.path.isfile(p)


# ---------------------------------------------------------------------------
# 1. parse the retired arrays from the pristine source
# ---------------------------------------------------------------------------

ROW_RE = re.compile(
    r"\{\s*(\d+)\s*,\s*(\d+)\s*,\s*\"([^\"]+)\"\s*,\s*(WF_\w+)\}")


def parse_water_region(src):
    # The region runs from the separator above the R60 comment to the
    # separator above the R63 comment.
    start = src.find("// R60: the underwater tables")
    if start < 0:
        die("R60 marker not found (already spliced?)")
    start = src.rfind("// ------", 0, start)
    end = src.find("// R63: the outdoor (wilderness) encounter tables")
    if end < 0:
        die("R63 marker not found")
    end = src.rfind("// ------", 0, end)
    if start < 0 or end < 0 or end <= start:
        die("region separators not found")
    region = src[start:end]
    tables = {}
    for arr, key in TABLES:
        m = re.search(r"static const WaterRow " + arr + r"\[\] = \{(.*?)\n\};",
                      region, re.S)
        if not m:
            die("array %s not found in the water region" % arr)
        rows = []
        for lo, hi, key_, fl in ROW_RE.findall(m.group(1)):
            rows.append((int(lo), int(hi), key_, FLAGS[fl]))
        if not rows:
            die("array %s parsed empty" % arr)
        tables[key] = rows
    if len(tables) != 9:
        die("expected 9 water tables, parsed %d" % len(tables))
    return start, end, tables


def gate_data(tables):
    total = 0
    counts = []
    for _, key in TABLES:
        rows = tables[key]
        counts.append(len(rows))
        total += len(rows)
        if rows[0][0] != 1 or rows[-1][1] != 100:
            die("%s does not span 01-00" % key)
        prev = 0
        for lo, hi, k, fl in rows:
            if lo != prev + 1 or hi < lo:
                die("%s has a band gap at %d" % (key, lo))
            if fl not in (0, 1, 2, 4):
                die("%s row %s carries flags %d" % (key, k, fl))
            if not k:
                die("%s has an empty key" % key)
            prev = hi
    if total != 205:
        die("expected 205 water rows, got %d" % total)
    if counts != [27, 23, 42, 35, 5, 9, 20, 24, 20]:
        die("unexpected per-table counts %r" % (counts,))
    return total, counts


# ---------------------------------------------------------------------------
# 2. lua emission + round-trip
# ---------------------------------------------------------------------------

def lua_text(key, rows):
    out = []
    out.append("-- encounter table def: %s" % key)
    out.append("-- The DMG Appendix C water encounter tables (R1033")
    out.append("-- de-wire): extracted verbatim from the retired")
    out.append("-- WaterRow arrays of dm/encounters.cpp (R60 underwater")
    out.append("-- set, Premium reprint p.179-181; R127 waterborne set,")
    out.append("-- p.190; the shared p.190 Dinosaur Subtable). flags")
    out.append("-- carries the footnote gates: 1 = cool waters only,")
    out.append("-- 2 = warm waters only, 4 = deep water only. In-row")
    out.append("-- substitutions and as-printed discrepancies are")
    out.append("-- documented in dm/encounters.cpp. DO NOT hand-edit:")
    out.append("-- tools/r1033_splice.py is the only writer.")
    out.append("")
    out.append("")
    out.append("return {")
    out.append('  key = "%s",' % key)
    out.append("  rows = {")
    for lo, hi, k, fl in rows:
        out.append('    { band = { %d, %d }, key = "%s", flags = %d },'
                   % (lo, hi, k, fl))
    out.append("  },")
    out.append("}")
    return "\n".join(out) + "\n"


def emit_lua(tables):
    if not os.path.isdir(LUA_DIR):
        os.makedirs(LUA_DIR)
    for _, key in TABLES:
        with open(os.path.join(LUA_DIR, key + ".lua"), "w") as f:
            f.write(lua_text(key, tables[key]))


def lua_roundtrip(tables):
    # every emitted file must parse back and re-emit byte-exact
    for _, key in TABLES:
        path = os.path.join(LUA_DIR, key + ".lua")
        text = open(path).read()
        m = re.search(r"return \{\n  key = \"([^\"]+)\",\n  rows = \{\n(.*?)\n  \},\n\}\n",
                      text, re.S)
        if not m:
            die("%s does not parse" % path)
        if m.group(1) != key:
            die("%s key mismatch" % path)
        rows = []
        for lo, hi, k, fl in re.findall(
                r'\{ band = \{ (\d+), (\d+) \}, key = "([^"]+)", flags = (\d+) \},',
                m.group(2)):
            rows.append((int(lo), int(hi), k, int(fl)))
        if rows != tables[key]:
            die("%s rows differ from the parsed record" % path)
        if lua_text(key, rows) != text:
            die("%s does not round-trip byte-exact" % path)


# ---------------------------------------------------------------------------
# 3. roll-path simulation (the pure-python twin of the C++ gates)
# ---------------------------------------------------------------------------

UNDERWATER = [("underwater_fresh_shallow", 0, 0),
              ("underwater_fresh_deep", 0, 1),
              ("underwater_salt_shallow", 1, 0),
              ("underwater_salt_deep", 1, 1)]
WATERBORNE = [("waterborne_fresh_small", 0, 0),
              ("waterborne_fresh_large", 0, 1),
              ("waterborne_salt_shallow", 1, 0),
              ("waterborne_salt_deep", 1, 1)]


def allowed_keys(tables, key):
    out = []
    for lo, hi, k, fl in tables[key]:
        if k == "DINOSAUR":
            for dlo, dhi, dk, dfl in tables["dinosaur_sub"]:
                if monster_exists(dk) and dk not in out:
                    out.append(dk)
        elif monster_exists(k) and k not in out:
            out.append(k)
    return out


def simulate_roll_path(tables):
    # First-shot resolution over the full pctile x pctile2 grid for
    # every (family, body, depth, clime) combo: a resolved key must
    # be a registry member; a gated roll re-rolls (skipped - the C++
    # path then consumes dice and the battery's roll smoke covers it).
    dino = tables["dinosaur_sub"]
    cells = 0
    resolved = 0
    absent = set()
    for fam in (UNDERWATER, WATERBORNE):
        for key, body, depth in fam:
            allowed = allowed_keys(tables, key)
            for clime in (0, 1):          # 0 = cool, 1 = warm
                for pct in range(1, 101):
                    for p2 in range(1, 101):
                        cells += 1
                        row = None
                        for r in tables[key]:
                            if r[0] <= pct <= r[1]:
                                row = r
                                break
                        if row is None:
                            die("%s: pctile %d misses every band"
                                % (key, pct))
                        fl = row[3]
                        if fl == 1 and clime == 1:
                            continue
                        if fl == 2 and clime == 0:
                            continue
                        k = row[2]
                        if k == "DINOSAUR":
                            dr = None
                            for d in dino:
                                if d[0] <= p2 <= d[1]:
                                    dr = d
                                    break
                            if dr is None:
                                die("%s: dino subtable misses %d"
                                    % (key, p2))
                            if dr[3] == 4 and depth == 0:
                                continue
                            k = dr[2]
                        if not monster_exists(k):
                            # the C++ path re-rolls on a missing
                            # bestiary record (the DMG ignore advice);
                            # legal, tracked for the report
                            absent.add(k)
                            continue
                        if k not in allowed:
                            die("%s: resolved key %s not in the "
                                "allowed set" % (key, k))
                        resolved += 1
    return cells, resolved, absent


# ---------------------------------------------------------------------------
# 4. the registry-native replacement block for dm/encounters.cpp
# ---------------------------------------------------------------------------

WATER_BLOCK = '''// ----------------------------------------------------------------------------
// R1033: the water encounter tables ride the registry. The retired
// kFreshShallow/kFreshDeep/kSaltShallow/kSaltDeep/kDinoSub (the R60
// underwater set, DMG Appendix C Premium reprint p.179-181,
// OCR-verified) and kWaterFreshSmall/kWaterFreshLarge/
// kWaterSaltShallow/kWaterSaltDeep (the R127 waterborne set,
// line-diffed against the 1eonline.info Appendix C compilation)
// were extracted verbatim into content/tables/encounters_water/*.lua
// and load through dm::EncounterTableRegistry (see encReg() above).
// The provenance notes moved with the data: footnote clime gates
// (* cool only / ** warm only) are the lua flags column, the
// fresh-water Dinosaur warm gate rides the parent row (the R60
// convention), and the substitutions (Koalinth -> hobgoblin,
// Kopoacinth -> gargoyle, Lacedon -> ghoul, Elf (aquatic) -> elf,
// Pirate -> buccaneer / caveman, Mermaid -> merman, the R61 whale
// size mapping) are transcribed in-row there, as are the two
// as-printed nixie clime discrepancies (book-verify debt).
// Counts still come from the registry's noAppearing fields (the
// book prints no number columns for either set). The roll paths,
// key companions and band edges below are behavior-identical to
// the retired arrays - the R127 line-diff audit and the R1033
// battery fragment pin the parity. tools/r1033_splice.py is the
// only writer of the lua; this seam is its reader.
// ----------------------------------------------------------------------------

namespace {

enum WaterFlagBits { WF_NONE = 0, WF_COOL_ONLY = 1, WF_WARM_ONLY = 2,
                     WF_DEEP_ONLY = 4 };

struct WaterRow { int lo, hi; std::string key; int flags; };

// registry-backed views, built once (the R1032 misc-engine shape)
static const std::vector<WaterRow>& waterView(const char* name) {
    static std::map<std::string, std::vector<WaterRow>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* n : { "underwater_fresh_shallow",
                               "underwater_fresh_deep",
                               "underwater_salt_shallow",
                               "underwater_salt_deep",
                               "dinosaur_sub",
                               "waterborne_fresh_small",
                               "waterborne_fresh_large",
                               "waterborne_salt_shallow",
                               "waterborne_salt_deep" }) {
            const auto& rs = encReg().waterRows(n);
            std::vector<WaterRow> rows;
            for (const auto& r : rs)
                rows.push_back(WaterRow{ r.lo, r.hi, r.key, r.flags });
            m[n] = rows;
        }
    }
    static const std::vector<WaterRow> none;
    auto it = m.find(name);
    return it == m.end() ? none : it->second;
}

// the R60 underwater selector: fresh/salt x shallow/deep
static const char* underwaterTableName(WaterBody body,
                                        WaterDepth depth) {
    if (body == WaterBody::FRESH)
        return depth == WaterDepth::SHALLOW
            ? "underwater_fresh_shallow" : "underwater_fresh_deep";
    return depth == WaterDepth::SHALLOW
        ? "underwater_salt_shallow" : "underwater_salt_deep";
}

// the R127 waterborne selector: the fresh body size rides the
// depth enum (SHALLOW = small body, DEEP = large body)
static const char* waterborneTableName(WaterBody body,
                                       WaterDepth depth) {
    if (body == WaterBody::FRESH)
        return depth == WaterDepth::SHALLOW
            ? "waterborne_fresh_small" : "waterborne_fresh_large";
    return depth == WaterDepth::SHALLOW
        ? "waterborne_salt_shallow" : "waterborne_salt_deep";
}

} // namespace

// R60: the underwater roll - see encounters.h.
DungeonEncounter rollWaterEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    const std::vector<WaterRow>& t =
        waterView(underwaterTableName(body, depth));

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi) { row = &r; break; }
        if (!row) return e;

        // footnote clime gates (DMG: "otherwise roll again")
        bool ok = true;
        if ((row->flags & WF_COOL_ONLY) && clime == WaterClime::WARM)
            ok = false;
        if ((row->flags & WF_WARM_ONLY) && clime == WaterClime::COOL)
            ok = false;

        std::string key = row->key;
        if (ok && key == "DINOSAUR") {
            const WaterRow* dr = nullptr;
            const auto& ds = waterView("dinosaur_sub");
            for (const auto& d : ds)
                if (pctile2 >= d.lo && pctile2 <= d.hi)
                    { dr = &d; break; }
            if (!dr) return e;    // subtable covers 01-00; defensive
            // Dinosaur Subtable *: deep water only (dinichthys)
            if ((dr->flags & WF_DEEP_ONLY) && depth == WaterDepth::SHALLOW)
                ok = false;
            else
                key = dr->key;
        }

        if (ok) {
            const monsters::MonsterDef* def = reg.find(key);
            if (def) {
                e.key = key;
                // numbers per MONSTER MANUAL (registry noAppearing;
                // 0/0 falls back to a single specimen)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(1,
                                (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
                return e;
            }
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> waterEncounterKeys(
        const monsters::MonsterRegistry& reg,
        WaterBody body, WaterDepth depth) {
    std::vector<std::string> out;
    const std::vector<WaterRow>& t =
        waterView(underwaterTableName(body, depth));
    for (const auto& r : t) {
        std::string key = r.key;
        if (key == "DINOSAUR") {
            for (const auto& d : waterView("dinosaur_sub"))
                if (reg.find(d.key))
                    pushUnique(out, d.key.c_str());
        } else if (reg.find(key)) {
            pushUnique(out, key.c_str());
        }
    }
    return out;
}

// R127: the waterborne roll - see encounters.h.
DungeonEncounter rollWaterborneEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        WaterBody body, WaterDepth depth, WaterClime clime) {
    DungeonEncounter e;

    const std::vector<WaterRow>& t =
        waterView(waterborneTableName(body, depth));

    for (int attempt = 0; attempt < 24; ++attempt) {
        const WaterRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi)
                { row = &r; break; }
        if (!row) return e;

        // footnote clime gates (DMG: "otherwise roll again")
        bool ok = true;
        if ((row->flags & WF_COOL_ONLY) && clime == WaterClime::WARM)
            ok = false;
        if ((row->flags & WF_WARM_ONLY) && clime == WaterClime::COOL)
            ok = false;

        std::string key = row->key;
        if (ok && key == "DINOSAUR") {
            const WaterRow* dr = nullptr;
            const auto& ds = waterView("dinosaur_sub");
            for (const auto& d : ds)
                if (pctile2 >= d.lo && pctile2 <= d.hi)
                    { dr = &d; break; }
            if (!dr) return e;    // subtable covers 01-00; defensive
            // Dinosaur Subtable *: deep water only (dinichthys)
            if ((dr->flags & WF_DEEP_ONLY)
                && depth == WaterDepth::SHALLOW)
                ok = false;
            else
                key = dr->key;
        }

        if (ok) {
            const monsters::MonsterDef* def = reg.find(key);
            if (def) {
                e.key = key;
                // numbers per MONSTER MANUAL (registry
                // noAppearing; 0/0 falls back to a single
                // specimen)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(1,
                                (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
                return e;
            }
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

// Every registry key the waterborne table can produce - the
// regtest-style companion of rollWaterborneEncounter.
std::vector<std::string> waterborneEncounterKeys(
        const monsters::MonsterRegistry& reg,
        WaterBody body, WaterDepth depth) {
    std::vector<std::string> out;
    const std::vector<WaterRow>& t =
        waterView(waterborneTableName(body, depth));
    for (const auto& r : t) {
        std::string key = r.key;
        if (key == "DINOSAUR") {
            for (const auto& d : waterView("dinosaur_sub"))
                if (reg.find(d.key))
                    pushUnique(out, d.key.c_str());
        } else if (reg.find(key)) {
            pushUnique(out, key.c_str());
        }
    }
    return out;
}

// R127: the printed band edges - see encounters.h.
std::vector<WaterborneBand> waterborneBands(
        WaterBody body, WaterDepth depth) {
    std::vector<WaterborneBand> out;
    for (const auto& r : waterView(waterborneTableName(body, depth))) {
        WaterborneBand b;
        b.key = r.key;
        b.lo  = r.lo;
        b.hi  = r.hi;
        b.flags = r.flags;
        out.push_back(b);
    }
    return out;
}

// The shared p.190 Dinosaur Subtable - see encounters.h.
std::vector<WaterborneBand> dinosaurSubBands() {
    std::vector<WaterborneBand> out;
    for (const auto& r : waterView("dinosaur_sub")) {
        WaterborneBand b;
        b.key = r.key;
        b.lo  = r.lo;
        b.hi  = r.hi;
        b.flags = r.flags;
        out.push_back(b);
    }
    return out;
}

'''

# ---------------------------------------------------------------------------
# 5. the registry extension (dm/EncounterTableRegistry.{h,cpp})
# ---------------------------------------------------------------------------

H_WRITER_OLD = "// tools/r1032_splice.py is the only writer."
H_WRITER_NEW = ("// tools/r1032_splice.py (dungeon family) and\n"
                "// tools/r1033_splice.py (water family) are the only writers.")

H_STRUCT_ANCHOR = """// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""
H_STRUCT_ADD = """// One water encounter table row (R1033): the R60 underwater set,
// the R127 waterborne set and the shared p.190 Dinosaur Subtable.
// flags carries the footnote gates: 1 = cool waters only,
// 2 = warm waters only, 4 = deep water only.
struct EncounterWaterRow {
    std::string key;
    int lo = 0, hi = 0;
    int flags = 0;
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""

H_GETTER_ANCHOR = """    const std::vector<DragonAgeRow>& dragonRows(int n) const;"""
H_GETTER_ADD = """    const std::vector<DragonAgeRow>& dragonRows(int n) const;
    // name: underwater_fresh_shallow / underwater_fresh_deep /
    // underwater_salt_shallow / underwater_salt_deep / dinosaur_sub /
    // waterborne_fresh_small / waterborne_fresh_large /
    // waterborne_salt_shallow / waterborne_salt_deep (R1033)
    bool hasWater(const std::string& name) const;
    const std::vector<EncounterWaterRow>& waterRows(
        const std::string& name) const;"""

H_MEMBER_ANCHOR = """    std::map<std::string, std::vector<DragonAgeRow>> m_dragons;"""
H_MEMBER_ADD = """    std::map<std::string, std::vector<DragonAgeRow>> m_dragons;
    std::map<std::string, std::vector<EncounterWaterRow>> m_waters;"""

CPP_HEADER_ANCHOR = ("// The dungeon encounter table registry loader (R1032). "
                     "The shape")
CPP_HEADER_ADD = ("// The dungeon encounter table registry loader (R1032; "
                  "R1033 added\n// the water family loader). The shape")

CPP_KEYS_ANCHOR = """const char* const kDragonRowKeys[] =
    { "band", "key", "age", nullptr };"""
CPP_KEYS_ADD = """const char* const kDragonRowKeys[] =
    { "band", "key", "age", nullptr };
const char* const kWaterRowKeys[] =
    { "band", "key", "flags", nullptr };
const char* const kWaterFileKeys[] = { "key", "rows", nullptr };"""

CPP_KIND_ANCHOR = """bool isLevelKind(const std::string& k) {"""
CPP_KIND_ADD = """// R1033: the water family file keys.
bool isWaterKey(const std::string& k) {
    return k.rfind("underwater_", 0) == 0
        || k.rfind("waterborne_", 0) == 0
        || k == "dinosaur_sub";
}

bool isLevelKind(const std::string& k) {"""

CPP_BRANCH_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""
CPP_BRANCH_ADD = """    } else if (isWaterKey(key)) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kWaterFileKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != key) { err = "def key '" + k + "' does not match file";
                            goto bad; }
        }
        lua_getfield(L, t, "rows");
        if (!lua_istable(L, -1)) { err = "rows is not a table"; goto bad; }
        {
            const int n = (int)lua_rawlen(L, -1);
            std::vector<EncounterWaterRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kWaterRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterWaterRow row;
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                lua_getfield(L, rt, "flags");
                if (!lua_isinteger(L, -1)) {
                    err = "'flags' is not an integer";
                    lua_pop(L, 1);
                    goto bad;
                }
                row.flags = (int)lua_tointeger(L, -1);
                lua_pop(L, 1);
                // STRICT: the gates are single footnote bits
                if (row.flags != 0 && row.flags != 1
                    && row.flags != 2 && row.flags != 4) {
                    err = "'flags' outside the gate bits";
                    goto bad;
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_waters.count(key)) { err = "duplicate def key"; goto bad; }
            m_waters[key] = rows;
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_ACC_ANCHOR = """const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {"""
CPP_ACC_ADD = """bool EncounterTableRegistry::hasWater(const std::string& name) const {
    return m_waters.count(name) != 0;
}

const std::vector<EncounterWaterRow>&
EncounterTableRegistry::waterRows(const std::string& name) const {
    static const std::vector<EncounterWaterRow> none;
    auto it = m_waters.find(name);
    return it == m_waters.end() ? none : it->second;
}

const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {"""

ENC_REG_ANCHOR = """        reg.loadDirectory("content/tables/encounters");"""
ENC_REG_ADD = """        reg.loadDirectory("content/tables/encounters");
        // R1033: the water family joined the registry from its own
        // directory (the R1032 audit pins 20 files in encounters/).
        reg.loadDirectory("content/tables/encounters_water");"""


def replace_once(text, old, new, where):
    if text.count(old) != 1:
        die("anchor in %s must occur exactly once (found %d)"
            % (where, text.count(old)))
    return text.replace(old, new, 1)


def extend_registry():
    h = open(REG_H).read()
    if "EncounterWaterRow" in h:
        return False
    h = replace_once(h, H_WRITER_OLD, H_WRITER_NEW, "registry header comment")
    h = replace_once(h, H_STRUCT_ANCHOR, H_STRUCT_ADD, "registry h struct")
    h = replace_once(h, H_GETTER_ANCHOR, H_GETTER_ADD, "registry h getters")
    h = replace_once(h, H_MEMBER_ANCHOR, H_MEMBER_ADD, "registry h members")
    with open(REG_H, "w") as f:
        f.write(h)

    c = open(REG_CPP).read()
    c = replace_once(c, CPP_HEADER_ANCHOR, CPP_HEADER_ADD, "registry cpp head")
    c = replace_once(c, CPP_KEYS_ANCHOR, CPP_KEYS_ADD, "registry cpp keys")
    c = replace_once(c, CPP_KIND_ANCHOR, CPP_KIND_ADD, "registry cpp helper")
    c = replace_once(c, CPP_BRANCH_ANCHOR, CPP_BRANCH_ADD, "registry cpp branch")
    c = replace_once(c, CPP_ACC_ANCHOR, CPP_ACC_ADD, "registry cpp accessors")
    with open(REG_CPP, "w") as f:
        f.write(c)
    return True


# ---------------------------------------------------------------------------
# 6. the splice proper (dm/encounters.cpp + regtest.cpp include)
# ---------------------------------------------------------------------------

REGTEST_ANCHOR = ('    #include "rules/audits/r1032_encounter_engine_registry.h"'
                  '  // R1032')
REGTEST_ADD = (REGTEST_ANCHOR + '\n    #include '
               '"rules/audits/r1033_water_encounter_registry.h"  // R1033')


def splice_encounters(src, start, end):
    # fresh apply only (idempotency handled by the caller)
    out = src[:start] + WATER_BLOCK + src[end:]
    out = replace_once(out, ENC_REG_ANCHOR, ENC_REG_ADD, "encReg() water dir")
    return out


# ---------------------------------------------------------------------------
# 7. the R1033 battery fragment (generated from the parsed record)
# ---------------------------------------------------------------------------

def row_find(rows, key):
    for i, (lo, hi, k, fl) in enumerate(rows):
        if k == key:
            return i
    die("key %s not found in table" % key)


def build_fragment(tables, counts):
    names_c = ", ".join('"%s"' % k for _, k in TABLES)
    rows_c = ", ".join(str(c) for c in counts)
    uw = [k for _, k in TABLES[:4]]
    wb = [k for _, k in TABLES[5:]]

    def pin(key, idx):
        lo, hi, k, fl = tables[key][idx]
        return ('        r = ereg.waterRows("%s")[%d];\n'
                '        if (r.lo != %d || r.hi != %d || r.key != "%s"\n'
                '            || r.flags != %d) ++bad;'
                % (key, idx, lo, hi, k, fl))

    # exact pins derived from the parse
    fs0 = tables["underwater_fresh_shallow"][0]
    fs_dino = tables["underwater_fresh_shallow"][4]
    wf_small_nixie = tables["waterborne_fresh_small"][4]
    wf_large_nixie = tables["waterborne_fresh_large"][15]
    dino_din = tables["dinosaur_sub"][1]

    def rowsel(key, want):
        for i, (lo, hi, k, fl) in enumerate(tables[key]):
            if (lo, hi, k, fl) == want:
                return i
        die("pin not found in %s: %r" % (key, want))

    pins = [
        ("underwater_salt_shallow", (92, 92, "sperm_whale", 0)),
        ("underwater_salt_shallow", (99, 100, "white_whale_beluga", 0)),
        ("underwater_fresh_deep", (61, 63, "purple_worm", 0)),
        ("underwater_salt_deep", (21, 21, "dragon_turtle", 0)),
        ("waterborne_salt_shallow", (68, 70, "caveman", 0)),
        ("waterborne_salt_shallow", (75, 75, "giant_octopus", 0)),
        ("waterborne_salt_shallow", (91, 96, "black_whale", 0)),
        ("waterborne_salt_deep", (96, 100, "white_whale_beluga", 0)),
        ("waterborne_fresh_large", (34, 48, "buccaneer", 0)),
    ]
    pin_lines = []
    for key, want in pins:
        pin_lines.append(pin(key, rowsel(key, want)))

    # key-count expectations per roll table (the reg-filtered census)
    key_counts = []
    for fam in (UNDERWATER, WATERBORNE):
        for key, body, depth in fam:
            key_counts.append((key, len(allowed_keys(tables, key))))

    cool_counts = []
    for key in ["underwater_fresh_shallow", "waterborne_fresh_small",
                "waterborne_fresh_large"]:
        n = sum(1 for r in tables[key] if r[3] == 1)
        warm = sum(1 for r in tables[key] if r[3] == 2)
        cool_counts.append((key, n, warm))

    frag = []
    A = frag.append
    A("// ============================================================================")
    A("// Adnd1 - rules/audits/r1033_water_encounter_registry.h  (R1033)")
    A("// The water encounter family battery audit, the R1032 shape: the")
    A("// registry load, exact table counts, band coverage, the footnote")
    A("// flag gates, row spot pins against the retired print-fidelity")
    A("// record, the key companions vs the monster registry, and the")
    A("// rollWaterEncounter() / rollWaterborneEncounter() paths.")
    A("// Expected values: 9 files, 205 water rows - all from the R60")
    A("// underwater record (p.179-181) and the R127 waterborne record")
    A("// (p.190) the splice parsed.")
    A("// ============================================================================")
    A("{")
    A("")
    A("    static const char* const kNames[9] =")
    A("        { %s };" % names_c)
    A("    static const int kRows[9] = { %s };" % rows_c)
    A("")
    A("    int bad = 0;")
    A("    dm::EncounterTableRegistry ereg;")
    A("")
    A("    // -- 1. load: 9 water files, zero errors, both dirs one reg -")
    A("    bad = 0;")
    A("    {")
    A('        const int files = ereg.loadDirectory(')
    A('            "content/tables/encounters_water");')
    A("        if (files != 9) ++bad;")
    A("        if (!ereg.errors().empty()) ++bad;")
    A("        // both families in one registry: 20 dungeon files join")
    A("        // with no key collision (the R1032 audit pins its own")
    A("        // 20-file load separately)")
    A('        const int df = ereg.loadDirectory(')
    A('            "content/tables/encounters");')
    A("        if (df != 20) ++bad;")
    A('        if (!ereg.hasWater("dinosaur_sub")) ++bad;')
    A("        if (!ereg.hasLevel(10)) ++bad;")
    A("    }")
    A('    printf("R1033 water encounter registry load audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 2. counts: every table, exact row census ------------------------")
    A("    bad = 0;")
    A("    {")
    A("        int total = 0;")
    A("        for (int i = 0; i < 9; ++i) {")
    A("            if (!ereg.hasWater(kNames[i])) ++bad;")
    A("            const int n = (int)ereg.waterRows(kNames[i]).size();")
    A("            if (n != kRows[i]) ++bad;")
    A("            total += n;")
    A("        }")
    A("        if (total != 205) ++bad;")
    A('        if (ereg.hasWater("dungeon_level_1")) ++bad;   // STRICT shapes')
    A("    }")
    A('    printf("R1033 water encounter registry counts audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 3. bands: 01-00 coverage + engine parity ----------------------")
    A("    bad = 0;")
    A("    {")
    A("        for (int i = 0; i < 9; ++i) {")
    A("            const auto& rs = ereg.waterRows(kNames[i]);")
    A("            if (rs.empty() || rs[0].lo != 1 || rs.back().hi != 100)")
    A("                { ++bad; continue; }")
    A("            int prev = 0;")
    A("            for (const auto& r : rs) {")
    A("                if (r.lo != prev + 1 || r.hi < r.lo) { ++bad; break; }")
    A("                prev = r.hi;")
    A("            }")
    A("        }")
    A("        // engine parity: dm::waterborneBands / dinosaurSubBands must")
    A("        // carry the registry rows verbatim (the R127 line-diff pins)")
    A("        for (int body = 0; body < 2; ++body)")
    A("            for (int dep = 0; dep < 2; ++dep) {")
    A("                const auto& got = dm::waterborneBands(")
    A("                    (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                const auto& want = ereg.waterRows(")
    A("                    body == 0 ? (dep == 0")
    A('                        ? "waterborne_fresh_small"')
    A('                        : "waterborne_fresh_large")')
    A("                    : (dep == 0")
    A('                        ? "waterborne_salt_shallow"')
    A('                        : "waterborne_salt_deep"));')
    A("                if (got.size() != want.size()) { ++bad; continue; }")
    A("                for (size_t i = 0; i < got.size(); ++i)")
    A("                    if (got[i].key != want[i].key")
    A("                        || got[i].lo != want[i].lo")
    A("                        || got[i].hi != want[i].hi")
    A("                        || got[i].flags != want[i].flags)")
    A("                        { ++bad; break; }")
    A("            }")
    A("        const auto& db = dm::dinosaurSubBands();")
    A('        const auto& dw = ereg.waterRows("dinosaur_sub");')
    A("        if (db.size() != dw.size() || db.size() != 5) ++bad;")
    A("        for (size_t i = 0; i < db.size() && i < dw.size(); ++i)")
    A("            if (db[i].key != dw[i].key || db[i].lo != dw[i].lo")
    A("                || db[i].hi != dw[i].hi || db[i].flags != dw[i].flags)")
    A("                ++bad;")
    A("    }")
    A('    printf("R1033 water encounter registry bands audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 4. flags: footnote gates, domain and pins ----------------------")
    A("    bad = 0;")
    A("    {")
    A("        for (int i = 0; i < 9; ++i)")
    A("            for (const auto& r : ereg.waterRows(kNames[i]))")
    A("                if (r.flags != 0 && r.flags != 1 && r.flags != 2")
    A("                    && r.flags != 4) ++bad;")
    A("        dm::EncounterWaterRow r;")
    A("        r = ereg.waterRows(kNames[0])[0];")
    A("        if (r.lo != %d || r.hi != %d || r.key != \"%s\"\n"
      "            || r.flags != %d) ++bad;" % (fs0[0], fs0[1], fs0[2], fs0[3]))
    A("        r = ereg.waterRows(kNames[0])[4];")
    A("        if (r.lo != %d || r.hi != %d || r.key != \"DINOSAUR\"\n"
      "            || r.flags != %d) ++bad;"
      % (fs_dino[0], fs_dino[1], fs_dino[3]))
    A("        r = ereg.waterRows(kNames[5])[4];")
    A("        if (r.lo != %d || r.hi != %d || r.key != \"nixie\"\n"
      "            || r.flags != %d) ++bad;"
      % (wf_small_nixie[0], wf_small_nixie[1], wf_small_nixie[3]))
    A("        r = ereg.waterRows(kNames[6])[15];")
    A("        if (r.lo != %d || r.hi != %d || r.key != \"nixie\"\n"
      "            || r.flags != %d) ++bad;"
      % (wf_large_nixie[0], wf_large_nixie[1], wf_large_nixie[3]))
    A("        r = ereg.waterRows(kNames[4])[1];")
    A("        if (r.lo != %d || r.hi != %d || r.key != \"%s\"\n"
      "            || r.flags != %d) ++bad;"
      % (dino_din[0], dino_din[1], dino_din[2], dino_din[3]))
    A("        // gate census: cool/warm row counts per clime-split table")
    for key, ncool, nwarm in cool_counts:
        A("        {")
        A("            int c = 0, w = 0;")
        A('            for (const auto& r : ereg.waterRows("%s"))' % key)
        A("                { if (r.flags == 1) ++c; if (r.flags == 2) ++w; }")
        A("            if (c != %d || w != %d) ++bad;" % (ncool, nwarm))
        A("        }")
    A("    }")
    A('    printf("R1033 water encounter registry flags audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 5. rows: spot pins, substitutions documented in-row ----------")
    A("    bad = 0;")
    A("    {")
    A("        dm::EncounterWaterRow r;")
    for line in pin_lines:
        A(line)
    A("    }")
    A('    printf("R1033 water encounter registry rows audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 6. keys: the companions vs the monster registry -------------")
    A("    bad = 0;")
    A("    {")
    A("        for (int body = 0; body < 2; ++body)")
    A("            for (int dep = 0; dep < 2; ++dep) {")
    A("                const auto uk = dm::waterEncounterKeys(")
    A("                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                const auto bk = dm::waterborneEncounterKeys(")
    A("                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                for (const auto& k : uk)")
    A("                    if (!reg.find(k)) ++bad;")
    A("                for (const auto& k : bk)")
    A("                    if (!reg.find(k)) ++bad;")
    A("                for (size_t i = 0; i < uk.size(); ++i)")
    A("                    for (size_t j = i + 1; j < uk.size(); ++j)")
    A("                        if (uk[i] == uk[j]) ++bad;")
    A("                for (size_t i = 0; i < bk.size(); ++i)")
    A("                    for (size_t j = i + 1; j < bk.size(); ++j)")
    A("                        if (bk[i] == bk[j]) ++bad;")
    A("            }")
    A("        // every DINOSAUR-bearing table reaches all five subtable keys")
    A("        // (the registry carries all five MM dinosaurs; the union")
    A("        // covers the fresh-small table, which prints no Dinosaur")
    A("        // row - as printed)")
    A("        static const char* const kDinos[5] =")
    A('            { "archelon_ischyros", "dinichthys", "elasmosaurus",')
    A('              "mosasaurus", "plesiosaurus" };')
    A("        for (int i = 0; i < 5; ++i)")
    A("            if (!reg.find(kDinos[i])) ++bad;")
    A("        for (int i = 0; i < 5; ++i) {")
    A("            bool hit = false;")
    A("            for (int body = 0; body < 2 && !hit; ++body)")
    A("                for (int dep = 0; dep < 2 && !hit; ++dep) {")
    A("                    const auto bk = dm::waterborneEncounterKeys(")
    A("                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                    for (const auto& k : bk)")
    A("                        if (k == kDinos[i]) { hit = true; break; }")
    A("                }")
    A("            if (!hit) ++bad;")
    A("        }")
    A("        // the four underwater tables and the three dino-bearing")
    A("        // waterborne tables each expand all five keys directly")
    A("        for (int body = 0; body < 2; ++body)")
    A("            for (int dep = 0; dep < 2; ++dep) {")
    A("                const auto uk = dm::waterEncounterKeys(")
    A("                    reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                if (uk.empty()) ++bad;")
    A("                for (int i = 0; i < 5; ++i) {")
    A("                    bool hit = false;")
    A("                    for (const auto& k : uk)")
    A("                        if (k == kDinos[i]) { hit = true; break; }")
    A("                    if (!hit) ++bad;")
    A("                }")
    A("            }")
    A("        for (int dep = 1; dep < 2; ++dep) {")
    A("            const auto bk = dm::waterborneEncounterKeys(")
    A("                reg, dm::WaterBody::FRESH, (dm::WaterDepth)dep);")
    A("            if (bk.empty()) ++bad;")
    A("            for (int i = 0; i < 5; ++i) {")
    A("                bool hit = false;")
    A("                for (const auto& k : bk)")
    A("                    if (k == kDinos[i]) { hit = true; break; }")
    A("                if (!hit) ++bad;")
    A("            }")
    A("        }")
    A("    }")
    A('    printf("R1033 water encounter registry keys audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 7. roll: both water paths, sweep + smoke ---------------------")
    A("    bad = 0;")
    A("    {")
    A("        rules::Rng rng(1033);")
    A("        rules::Dice dice(rng);")
    A("        for (int body = 0; body < 2; ++body)")
    A("            for (int dep = 0; dep < 2; ++dep)")
    A("                for (int cl = 0; cl < 2; ++cl) {")
    A("                    const auto uk = dm::waterEncounterKeys(")
    A("                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                    const auto bk = dm::waterborneEncounterKeys(")
    A("                        reg, (dm::WaterBody)body, (dm::WaterDepth)dep);")
    A("                    int rolled = 0;")
    A("                    for (int pct = 1; pct <= 100; ++pct) {")
    A("                        const int p2 = 1 + (pct * 37) % 100;")
    A("                        dm::DungeonEncounter a = dm::rollWaterEncounter(")
    A("                            reg, dice, pct, p2, (dm::WaterBody)body,")
    A("                            (dm::WaterDepth)dep, (dm::WaterClime)cl);")
    A("                        dm::DungeonEncounter b =")
    A("                            dm::rollWaterborneEncounter(")
    A("                                reg, dice, pct, p2, (dm::WaterBody)body,")
    A("                                (dm::WaterDepth)dep,")
    A("                                (dm::WaterClime)cl);")
    A("                        ++rolled;")
    A("                        if (!a.key.empty() && !reg.find(a.key)) ++bad;")
    A("                        if (!b.key.empty() && !reg.find(b.key)) ++bad;")
    A("                        if (!a.key.empty()) {")
    A("                            bool hit = false;")
    A("                            for (const auto& k : uk)")
    A("                                if (k == a.key) { hit = true; break; }")
    A("                            if (!hit) ++bad;")
    A("                        }")
    A("                        if (!b.key.empty()) {")
    A("                            bool hit = false;")
    A("                            for (const auto& k : bk)")
    A("                                if (k == b.key) { hit = true; break; }")
    A("                            if (!hit) ++bad;")
    A("                        }")
    A("                    }")
    A("                    if (rolled != 100) ++bad;")
    A("                }")
    A("        // rng smoke: 2000 rolls per path, outcomes must be legal and")
    A("        // every table must have produced at least one encounter")
    A("        int seen[8] = { 0 };")
    A("        int produced = 0;")
    A("        for (int i = 0; i < 2000; ++i) {")
    A("            const int body = i % 2, dep = (i / 2) % 2;")
    A("            const int cl = (i / 4) % 2;")
    A("            dm::DungeonEncounter a = dm::rollWaterEncounter(")
    A("                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,")
    A("                (dm::WaterBody)body, (dm::WaterDepth)dep,")
    A("                (dm::WaterClime)cl);")
    A("            dm::DungeonEncounter b = dm::rollWaterborneEncounter(")
    A("                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,")
    A("                (dm::WaterBody)body, (dm::WaterDepth)dep,")
    A("                (dm::WaterClime)cl);")
    A("            if (!a.key.empty()) {")
    A("                if (!reg.find(a.key)) ++bad;")
    A("                if (a.count < 1) ++bad;")
    A("                ++seen[body * 2 + dep];")
    A("                ++produced;")
    A("            }")
    A("            if (!b.key.empty()) {")
    A("                if (!reg.find(b.key)) ++bad;")
    A("                if (b.count < 1) ++bad;")
    A("                ++seen[4 + body * 2 + dep];")
    A("                ++produced;")
    A("            }")
    A("        }")
    A("        if (produced < 2000) ++bad;")
    A("        for (int i = 0; i < 8; ++i)")
    A("            if (seen[i] == 0) ++bad;")
    A("    }")
    A('    printf("R1033 water encounter registry roll audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("}")
    return "\n".join(frag) + "\n"


# ---------------------------------------------------------------------------
# 8. census + static sanity
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
    applied = "EncounterWaterRow" in reg_h
    if applied:
        if any(("static const WaterRow " + a + "[]") in enc
               for a, _ in TABLES):
            die("half-spliced state: registry extended but the water "
                "arrays still stand in dm/encounters.cpp - recover with "
                "git checkout and re-run")
        if census_count() != 955:
            die("already applied but census is %d (expected 955)"
                % census_count())
        n_lua = len([f for f in os.listdir(LUA_DIR) if f.endswith(".lua")])
        if n_lua != 9:
            die("already applied but %d water lua files (expected 9)"
                % n_lua)
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    pre_census = census_count()
    if pre_census != 948:
        die("pristine census is %d (expected 948)" % pre_census)

    src = enc
    pre_lines = src.count("\n")

    # 1. parse
    start, end, tables = parse_water_region(src)
    total, counts = gate_data(tables)
    uw_counts = counts[:4]
    wb_counts = counts[5:]
    print("parsed: %d water rows (underwater %r, dino %d, waterborne %r), "
          "flags ok" % (total, uw_counts, counts[4], wb_counts))

    # 2. emit lua + round-trip
    emit_lua(tables)
    lua_roundtrip(tables)
    print("round-trip: 9 lua files parse back byte-exact")

    # 3. roll-path simulation
    cells, resolved, absent = simulate_roll_path(tables)
    print("roll-path sim: %d first-shot cells clean (%d resolved, "
          "absent-key rerolls: %s)"
          % (cells, resolved, sorted(absent) or "none"))

    # 4. registry extension
    extend_registry()

    # 5. the encounters.cpp splice
    out = splice_encounters(src, start, end)
    retired = ["kFreshShallow", "kFreshDeep", "kSaltShallow",
               "kSaltDeep", "kDinoSub", "kWaterFreshSmall",
               "kWaterFreshLarge", "kWaterSaltShallow", "kWaterSaltDeep",
               "sizeof kDinoSub"]
    # the untouched head and tail must be clean (the replacement block
    # names the retired arrays in its provenance comment, by design)
    for tok in retired:
        if tok in src[:start] or tok in src[end:]:
            die("retired token %s survived outside the spliced region" % tok)
    kept = ["rollWaterEncounter", "rollWaterborneEncounter",
            "waterEncounterKeys", "waterborneEncounterKeys",
            "waterborneBands", "dinosaurSubBands", "WF_COOL_ONLY",
            "WF_WARM_ONLY", "WF_DEEP_ONLY"]
    for tok in kept:
        if tok not in out:
            die("retained token %s missing after the splice" % tok)
    with open(ENC, "w") as f:
        f.write(out)
    print("spliced dm/encounters.cpp (%d -> %d lines)"
          % (pre_lines, out.count("\n")))

    # 6. the battery fragment
    frag = build_fragment(tables, counts)
    os.makedirs(os.path.dirname(FRAG), exist_ok=True)
    with open(FRAG, "w") as f:
        f.write(frag)

    # 7. regtest include
    rt = open(REGTEST).read()
    rt = replace_once(rt, REGTEST_ANCHOR, REGTEST_ADD, "regtest include")
    with open(REGTEST, "w") as f:
        f.write(rt)
    print("regtest.cpp: R1033 fragment included")

    # 8. static sanity: brace balance on every touched C++ file
    for p in (ENC, REG_H, REG_CPP):
        d = brace_balance(p)
        if d != 0:
            die("brace imbalance %d in %s" % (d, p))

    post_census = census_count()
    if post_census != 955:
        die("post-splice census is %d (expected 955)" % post_census)
    print("census: %d -> %d audit printf patterns" % (pre_census, post_census))

    n_lua = len([f for f in os.listdir(LUA_DIR) if f.endswith(".lua")])
    if n_lua != 9:
        die("wrote %d water lua files (expected 9)" % n_lua)
    print("applied 1, rewrote 4 tracked files, wrote 10 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
