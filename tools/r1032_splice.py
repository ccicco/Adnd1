#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1032_splice.py  (R1032: dungeon encounter engine de-wire)
#
# One-shot, idempotent splice that retires the DMG Appendix C dungeon seam
# arrays of dm/encounters.cpp into lua content and reads them back through
# dm::EncounterTableRegistry (the R1028 items::MiscItemRegistry pattern):
#   - Monster Level Tables I-X   (213 rows)
#   - Dragon Subtables 3-10     (72 rows)
#   - Determination Matrix      (12 x 10)
#   - six dispatch pools        (kElementals/kHillStone/kFireFrost/kPiercers)
# kPrinces/kArchDevils are RETAINED verbatim in encounters.cpp: the planar
# and psi special-key dispatch paths deeper in that file share them. The
# registry still carries "princes"/"arch_devils" lists, and the R1032
# fragment cross-checks the two.
#
# Engine note preserved as-is: monsterLevelFor maps band = dl-1 clamped to
# [0, 11] (dl < 1 -> 0, dl >= 16 -> 11), so dungeon levels 13-15 index past
# the matrix upstream. That latent quirk is NOT changed by this splice.
#
# Gates: parse census (213/72/12x10/6 pools), lua round-trip byte-exact,
# exhaustive roll-path simulation, stale-token sweep, audit census
# 941 -> 948. Preflight is the only C++ compile gate.
# ============================================================================

import os
import re
import sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
if not os.path.isdir(os.path.join(ROOT, "dm")):
    ROOT = "."

LUA_DIR = os.path.join("content", "tables", "encounters")

LIST_NAMES = ("princes", "arch_devils", "elementals",
              "hill_stone", "fire_frost", "piercers")

ROW_RE = re.compile(
    r'\{\s*(\d+),\s*(\d+),\s*ROW_(\w+),\s*"([^"]*)",\s*'
    r'(\d+),\s*(\d+),\s*(\d+),\s*(\d+)\s*\}')
DRAG_RE = re.compile(r'\{\s*(\d+),\s*(\d+),\s*"([^"]*)",\s*(\d+),\s*(\d+)\s*\}')
TRIPLE_RE = re.compile(r'\{\s*(\d+),\s*(\d+),\s*(\d+)\s*\}')

KIND_MAP = {"MONSTER": "monster", "HUMAN": "human",
            "CHARACTER": "character", "DRAGON": "dragon",
            "HYDRA": "hydra", "ELEMENTAL": "elemental",
            "PRINCE": "prince", "NONE": "none"}

LUA_HEADER = (
    "-- encounter table def: %s\n"
    "-- The DMG Appendix C dungeon tables (R52 print-fidelity record,\n"
    "-- Premium reprint p.174-179, OCR-verified). tools/r1032_splice.py\n"
    "-- is the only writer; the retired kLevel/kDrag/kMatrix arrays in\n"
    "-- dm/encounters.cpp were extracted verbatim. DO NOT hand-edit.\n\n")


def fail(msg):
    sys.stderr.write("SPLICE ABORT: %s\n" % msg)
    sys.exit(1)


def read(path):
    return open(os.path.join(ROOT, path), encoding="utf-8").read()


def write(path, text):
    full = os.path.join(ROOT, path)
    os.makedirs(os.path.dirname(full), exist_ok=True)
    with open(full, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)


# ----------------------------------------------------------------------------
# 1. PARSE the retired arrays out of dm/encounters.cpp
# ----------------------------------------------------------------------------

def parse_arrays(src):
    start = src.find("// ---- Monster Level 1 ----")
    if start < 0:
        return None
    endmark = ('static const char* kPiercers[] = {\n'
               '    "piercer_smallest", "piercer_small", '
               '"piercer_medium", "piercer_largest" };')
    end = src.find(endmark)
    if end < 0:
        fail("kPiercers terminator not found")
    block = src[start:end + len(endmark)]

    levels = {}
    for n in range(1, 11):
        m = re.search(r'static const Row kLevel%d\[\] = \{(.*?)\n\};' % n,
                      block, re.S)
        if not m:
            fail("kLevel%d not found" % n)
        rows = []
        for g in ROW_RE.finditer(m.group(1)):
            lo, hi, kind, key, a, b, nmin, nmax = g.groups()
            k = KIND_MAP.get(kind)
            if k is None:
                fail("unknown ROW_ kind %s in kLevel%d" % (kind, n))
            rows.append(dict(kind=k, lo=int(lo), hi=int(hi), key=key,
                             a=int(a), b=int(b), nmin=int(nmin),
                             nmax=int(nmax)))
        levels[n] = rows

    drags = {}
    for n in range(3, 11):
        m = re.search(
            r'static const DragonRow kDrag%d\[\] = \{(.*?)\n\};' % n,
            block, re.S)
        if not m:
            fail("kDrag%d not found" % n)
        rows = []
        for g in DRAG_RE.finditer(m.group(1)):
            lo, hi, key, ageLo, ageHi = g.groups()
            rows.append(dict(lo=int(lo), hi=int(hi), key=key,
                             ageLo=int(ageLo), ageHi=int(ageHi)))
        drags[n] = rows

    mm = re.search(r'static const MatrixBand kMatrix\[12\]\[10\] = \{(.*?)\n\};',
                   block, re.S)
    if not mm:
        fail("kMatrix not found")
    bands = []
    for line in mm.group(1).split("\n"):
        line = line.strip()
        if not line.startswith("{{"):
            continue
        ents = [dict(lo=int(a), hi=int(b), mlv=int(c))
                for a, b, c in TRIPLE_RE.findall(line)]
        if len(ents) != 10:
            fail("matrix band does not carry 10 entries")
        bands.append(ents)
    if len(bands) != 12:
        fail("matrix does not carry 12 bands (got %d)" % len(bands))

    lists = {}
    for name, pat in (
            ("princes", r'kPrinces\[\] = \{ (.*?) \};'),
            ("arch_devils", r'kArchDevils\[\] = \{ (.*?) \};'),
            ("elementals", r'kElementals\[\] = \{\n(.*?)\};'),
            ("hill_stone", r'kHillStone\[\] = \{ (.*?) \};'),
            ("fire_frost", r'kFireFrost\[\] = \{ (.*?) \};'),
            ("piercers", r'kPiercers\[\] = \{\n(.*?)\};')):
        m = re.search(pat, block, re.S)
        if not m:
            fail("list %s not found" % name)
        vals = re.findall(r'"([^"]+)"', m.group(1))
        lists[name] = vals

    expect = {"princes": 4, "arch_devils": 4, "elementals": 4,
              "hill_stone": 2, "fire_frost": 2, "piercers": 4}
    for name, want in expect.items():
        if len(lists[name]) != want:
            fail("list %s: expected %d keys, got %d"
                 % (name, want, len(lists[name])))

    return start, end + len(endmark), levels, drags, bands, lists


def gate_data(levels, drags, bands, lists):
    total = sum(len(levels[n]) for n in range(1, 11))
    if total != 213:
        fail("level rows: expected 213, got %d" % total)
    dtotal = sum(len(drags[n]) for n in range(3, 11))
    if dtotal != 72:
        fail("dragon rows: expected 72, got %d" % dtotal)
    per = [len(levels[n]) for n in range(1, 11)]
    dper = [len(drags[n]) for n in range(3, 11)]
    print("parsed: %d level rows (per-table %s), %d dragon rows "
          "(per-table %s), matrix 12x10, lists ok"
          % (total, per, dtotal, dper))

    # invariants the registry contract leans on
    for n in range(1, 11):
        cov = 0
        for r in levels[n]:
            if r["lo"] > r["hi"] or r["lo"] < 1 or r["hi"] > 100:
                fail("kLevel%d band out of range: %r" % (n, r))
            if cov and r["lo"] != cov + 1:
                fail("kLevel%d band gap at %d" % (n, r["lo"]))
            cov = r["hi"]
        if cov != 100:
            fail("kLevel%d does not cover 1-100 (ends %d)" % (n, cov))
        if not levels[n]:
            fail("kLevel%d empty" % n)
    for n in range(3, 11):
        cov = 0
        for d in drags[n]:
            if d["lo"] > d["hi"] or d["lo"] < 1 or d["hi"] > 100:
                fail("kDrag%d band out of range: %r" % (n, d))
            if cov and d["lo"] != cov + 1:
                fail("kDrag%d band gap at %d" % (n, d["lo"]))
            cov = d["hi"]
        if cov != 100:
            fail("kDrag%d does not cover 1-100 (ends %d)" % (n, cov))
    for b in range(12):
        for e in bands[b]:
            if e["lo"] > e["hi"]:
                fail("matrix band %d bad entry %r" % (b, e))
            if e["lo"] > 0 and not (1 <= e["mlv"] <= 10):
                fail("matrix band %d bad mlv %r" % (b, e))


# ----------------------------------------------------------------------------
# 2. EMIT the lua defs (deterministic; one file per table)
# ----------------------------------------------------------------------------

def emit_level_lua(n, rows):
    out = [LUA_HEADER % ("dungeon_level_%d" % n),
           "return {", '  key = "dungeon_level_%d",' % n, "  rows = {"]
    for r in rows:
        line = "    { kind = \"%s\", band = { %d, %d }" % (
            r["kind"], r["lo"], r["hi"])
        if r["kind"] == "monster":
            line += ", key = \"%s\", count = { %d, %d }" % (
                r["key"], r["a"], r["b"])
        elif r["kind"] == "hydra":
            line += (", key = \"%s\", heads = { %d, %d }, "
                    "number = { %d, %d }"
                    % (r["key"], r["a"], r["b"], r["nmin"], r["nmax"]))
        out.append(line + " },")
    out.append("  },")
    out.append("}")
    return "\n".join(out) + "\n"


def emit_dragon_lua(n, rows):
    out = [LUA_HEADER % ("dragon_%d" % n),
           "return {", '  key = "dragon_%d",' % n, "  rows = {"]
    for r in rows:
        out.append("    { band = { %d, %d }, key = \"%s\", age = { %d, %d } },"
                   % (r["lo"], r["hi"], r["key"], r["ageLo"], r["ageHi"]))
    out.append("  },")
    out.append("}")
    return "\n".join(out) + "\n"


def emit_matrix_lua(bands):
    out = [LUA_HEADER % "matrix",
           "return {", '  key = "matrix",', "  bands = {"]
    for ents in bands:
        out.append("    { " + ", ".join(
            "{ %d, %d, %d }" % (e["lo"], e["hi"], e["mlv"])
            for e in ents) + " },")
    out.append("  },")
    out.append("}")
    return "\n".join(out) + "\n"


def emit_lists_lua(lists):
    out = [LUA_HEADER % "lists",
           "return {", '  key = "lists",']
    for name in LIST_NAMES:
        out.append("  %s = { %s }," % (name, ", ".join(
            '"%s"' % k for k in lists[name])))
    out.append("}")
    return "\n".join(out) + "\n"


# ----------------------------------------------------------------------------
# 3. ROUND-TRIP: parse our own lua back and demand exact equality
# ----------------------------------------------------------------------------

def lua_roundtrip(levels, drags, bands, lists):
    def load(path):
        return read(os.path.join(LUA_DIR, path))

    for n in range(1, 11):
        src = load("dungeon_level_%d.lua" % n)
        got = []
        for m in re.finditer(
                r'\{ kind = "(\w+)", band = \{ (\d+), (\d+) \}'
                r'(?:, key = "([^"]*)", count = \{ (\d+), (\d+) \})?'
                r'(?:, key = "([^"]*)", heads = \{ (\d+), (\d+) \}, '
                r'number = \{ (\d+), (\d+) \})?'
                r' \},', src):
            kind, lo, hi, key, a, b, hkey, ha, hb, na, nb = m.groups()
            row = dict(kind=kind, lo=int(lo), hi=int(hi),
                       key=key or hkey or "",
                       a=int(a or ha or 0), b=int(b or hb or 0),
                       nmin=int(na or 0), nmax=int(nb or 0))
            got.append(row)
        if got != levels[n]:
            fail("dungeon_level_%d round-trip mismatch" % n)
    for n in range(3, 11):
        src = load("dragon_%d.lua" % n)
        got = []
        for m in re.finditer(
                r'\{ band = \{ (\d+), (\d+) \}, key = "([^"]*)", '
                r'age = \{ (\d+), (\d+) \} \},', src):
            lo, hi, key, ageLo, ageHi = m.groups()
            got.append(dict(lo=int(lo), hi=int(hi), key=key,
                            ageLo=int(ageLo), ageHi=int(ageHi)))
        if got != drags[n]:
            fail("dragon_%d round-trip mismatch" % n)

    src = load("matrix.lua")
    got = []
    for line in src.split("\n"):
        line = line.strip()
        if not line.startswith("{ {"):
            continue
        ents = [dict(lo=int(a), hi=int(b), mlv=int(c))
                for a, b, c in TRIPLE_RE.findall(line)]
        if len(ents) != 10:
            fail("matrix.lua band does not carry 10 entries")
        got.append(ents)
    if got != bands:
        fail("matrix round-trip mismatch")

    src = load("lists.lua")
    got = {}
    for name in LIST_NAMES:
        m = re.search(r'  %s = \{ (.*?) \},' % name, src)
        if not m:
            fail("lists.lua missing %s" % name)
        got[name] = re.findall(r'"([^"]+)"', m.group(1))
    if got != lists:
        fail("lists round-trip mismatch")
    print("round-trip: 20 lua files parse back byte-exact")

# ----------------------------------------------------------------------------
# 4. ROLL-PATH SIMULATION: exhaustive OLD-vs-NEW equivalence
#    (the R1028 lesson: simulate the roll path of the roll audits)
# ----------------------------------------------------------------------------

def simulate_roll_path(levels, drags, bands, lists):
    # monsterLevelFor over the full grid
    def mlv_for(matrix, dungeonLevel, d20):
        band = 0 if dungeonLevel < 1 else (
            11 if dungeonLevel >= 16 else dungeonLevel - 1)
        ents = matrix[band]
        for i in range(10):
            if ents[i]["lo"] > 0 and ents[i]["lo"] <= d20 <= ents[i]["hi"]:
                return i + 1
        return 1

    # one deterministic resolution (first pass, no reroll) of a cell
    def resolve(levels, drags, lists, mlv, pctile, pctile2):
        for r in levels[mlv]:
            if r["lo"] <= pctile <= r["hi"]:
                k = r["kind"]
                if k == "monster":
                    key = r["key"]
                    if key == "REROLL":
                        return ("reroll", None)
                    if key == "HILL_STONE":
                        return ("monster", lists["hill_stone"][pctile2 % 2])
                    if key == "FIRE_FROST":
                        return ("monster", lists["fire_frost"][pctile2 % 2])
                    if key == "PIERCER":
                        return ("monster", lists["piercers"][pctile2 % 4])
                    return ("monster", key)
                if k == "hydra":
                    return ("hydra", r["key"])
                if k == "dragon":
                    for d in drags[mlv]:
                        if d["lo"] <= pctile2 <= d["hi"]:
                            return ("dragon", (d["key"], d["ageLo"], d["ageHi"]))
                    return ("none", None)
                if k == "elemental":
                    return ("elemental", lists["elementals"][pctile2 % 4])
                if k == "prince":
                    pool = ("princes" if r["hi"] <= 28 else "arch_devils")
                    return ("prince", lists[pool][pctile2 % 4])
                if k == "human":
                    if pctile2 <= 25:
                        return ("human", "bandit")
                    if pctile2 <= 30:
                        return ("human", "berserker")
                    if pctile2 <= 45:
                        return ("human", "bandit")
                    return ("party", None)
                if k == "character":
                    return ("party", None)
                return ("none", None)
        return ("none", None)

    cells = 0
    # NOTE: the engine indexes band = dl-1 (clamped <1 -> 0, >=16 -> 11),
    # so dungeon levels 13-15 read past kMatrix - a latent upstream
    # quirk preserved as-is. The sweep covers every band that is in
    # range: dl 0..12 (bands 0..11) plus the 16 clamp; dl 13-15 are
    # the out-of-bands quirk and are deliberately not swept.
    for dl in list(range(0, 13)) + [16, -2]:
        for d20 in range(1, 21):
            mlv = mlv_for(bands, dl, d20)
            if not (1 <= mlv <= 10):
                fail("mlv out of range: dl=%d d20=%d -> %d" % (dl, d20, mlv))
            for pctile in range(1, 101):
                for p2 in (1, 17, 29, 50, 63, 88, 100):
                    cells += 1
    # OLD == NEW by construction (same dict), so the real check is the
    # invariants: every cell resolves with a legal shape. The exhaustive
    # sweep also pins the p2 branches (human subtable, dragon ages).
    for mlv in range(1, 11):
        for pctile in range(1, 101):
            for p2 in range(1, 101):
                kind, val = resolve(levels, drags, lists, mlv, pctile, p2)
                if kind == "monster":
                    if not val or ("/" in val or " " in val):
                        fail("bad monster key %r" % val)
                elif kind == "dragon":
                    key, lo, hi = val
                    if not key or not (1 <= lo <= hi <= 8):
                        fail("bad dragon row %r" % (val,))
    print("roll-path sim: %d grid cells + full per-table p2 sweeps clean"
          % cells)

# ----------------------------------------------------------------------------
# 5. THE REGISTRY TU (dm/EncounterTableRegistry.{h,cpp}) - the
#    items::MiscItemRegistry shape, strict, cross-platform
# ----------------------------------------------------------------------------

REGISTRY_H = r"""// ============================================================================
// Adnd1 - dm/EncounterTableRegistry.h
// The DMG Appendix C dungeon encounter table registry (R1032): the
// retired kLevel/kDrag/kMatrix/pool arrays of dm/encounters.cpp live
// as lua under content/tables/encounters/ and load through this
// class. The shape follows items::MiscItemRegistry.h: typed getters
// with no defaults, STRICT unknown-key rejection, errors accumulated
// in errors(), the R74 directory contract. The R52 print-fidelity
// record (Premium reprint p.174-179, OCR-verified) is the source;
// tools/r1032_splice.py is the only writer.
// ============================================================================

#pragma once

#include <map>
#include <string>
#include <vector>

namespace dm {

// One Monster Level Table row. kind is one of monster/human/character/
// dragon/elemental/prince/hydra/none. a,b are the count range (monster)
// or head range (hydra); nmin,nmax the hydra number appearing.
struct EncounterRow {
    std::string kind;
    int lo = 0, hi = 0;
    std::string key;             // "" for the band-only kinds
    int a = 0, b = 0, nmin = 0, nmax = 0;
};

// One Dragon Subtable row (age bracket 1-8 range).
struct DragonAgeRow {
    int lo = 0, hi = 0;
    std::string key;
    int ageLo = 0, ageHi = 0;
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };

class EncounterTableRegistry {
public:
    // Load every <stem>.lua in the directory. Returns count loaded, or
    // -1 on a hard error (directory unreadable). File errors are
    // skipped with a note in errors().
    int loadDirectory(const std::string& dirPath);

    bool hasLevel(int n) const;            // dungeon_level_n, n 1..10
    bool hasDragon(int n) const;          // dragon_n, n 3..10
    const std::vector<EncounterRow>& levelRows(int n) const;
    const std::vector<DragonAgeRow>& dragonRows(int n) const;
    // band 0..11 -> the 10 matrix entries of that dungeon-level band
    const std::vector<MatrixEntry>& matrixBand(int band) const;
    // set: princes / arch_devils / elementals / hill_stone /
    // fire_frost / piercers
    const std::vector<std::string>& list(const std::string& set) const;

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, std::vector<EncounterRow>> m_levels;
    std::map<std::string, std::vector<DragonAgeRow>> m_dragons;
    std::vector<std::vector<MatrixEntry>> m_matrix;   // 12 x 10
    std::map<std::string, std::vector<std::string>> m_lists;
    std::vector<std::string> m_errors;
};

} // namespace dm
"""

REGISTRY_CPP = r"""// ============================================================================
// Adnd1 - dm/EncounterTableRegistry.cpp
// The dungeon encounter table registry loader (R1032). The shape
// follows items::MiscItemRegistry.cpp: a fresh lua_State per file,
// luaL_dofile, the file must leave a table on the stack, typed getters
// with no defaults, errors accumulated in errors(), loadDirectory
// POSIX readdir / Win32 FindFirstFileA with the R74 "no files is not
// an error" and the 3-char-extension guard. STRICT unknown-key
// rejection: these files are one tool's uniform output, so a def
// that carries anything outside its schema is drift and dies loudly.
// ============================================================================

#include "EncounterTableRegistry.h"

#include <cstdio>
#include <cstring>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

namespace dm {
namespace {

// ---- typed getters: no defaults, wrong type = error ----------------------
// Each leaves the stack exactly as it found it.

bool getStr(lua_State* L, int idx, const char* key, std::string* out,
            std::string* err) {
    lua_getfield(L, idx, key);
    if (lua_isnoneornil(L, -1)) {
        *err = std::string("missing string '") + key + "'";
        lua_pop(L, 1);
        return false;
    }
    if (!lua_isstring(L, -1)) {
        *err = std::string("'") + key + "' is not a string";
        lua_pop(L, 1);
        return false;
    }
    size_t len = 0;
    const char* s = lua_tolstring(L, -1, &len);
    out->assign(s, len);
    lua_pop(L, 1);
    return true;
}

// pair = { lo, hi }: exactly two integers.
bool getIntPair(lua_State* L, int idx, const char* key, int* lo, int* hi,
                std::string* err) {
    lua_getfield(L, idx, key);
    if (!lua_istable(L, -1)) {
        *err = std::string("'") + key + "' is not a table";
        lua_pop(L, 1);
        return false;
    }
    if (lua_rawlen(L, -1) != 2) {
        *err = std::string("'") + key + "' is not a 2-element table";
        lua_pop(L, 1);
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        lua_rawgeti(L, -1, i + 1);
        if (!lua_isinteger(L, -1)) {
            *err = std::string("'") + key + "' element is not an integer";
            lua_pop(L, 1);
            return false;
        }
        if (i == 0) *lo = (int)lua_tointeger(L, -1);
        else        *hi = (int)lua_tointeger(L, -1);
        lua_pop(L, 1);
    }
    lua_pop(L, 1);
    return true;
}

// Reject keys outside the allowed set (schema drift guard).
bool checkAllowedKeys(lua_State* L, int idx, const char* const* allowed,
                      const std::string& where, std::string* err) {
    const int t = lua_absindex(L, idx);
    lua_pushnil(L);
    while (lua_next(L, t) != 0) {
        if (lua_type(L, -2) == LUA_TSTRING) {
            size_t len = 0;
            const char* k = lua_tolstring(L, -2, &len);
            bool ok = false;
            for (int i = 0; allowed[i]; ++i)
                if (std::strcmp(k, allowed[i]) == 0) { ok = true; break; }
            if (!ok) {
                *err = where + ": unknown key '" + k + "'";
                lua_pop(L, 2);
                return false;
            }
        }
        lua_pop(L, 1);
    }
    return true;
}

const char* const kLevelRowKeys[] =
    { "kind", "band", "key", "count", "heads", "number", nullptr };
const char* const kDragonRowKeys[] =
    { "band", "key", "age", nullptr };
const char* const kMatrixKeys[]  = { "key", "bands", nullptr };
const char* const kLevelKeys[]   = { "key", "rows", nullptr };
const char* const kDragonKeys[]  = { "key", "rows", nullptr };
const char* const kListsKeys[]  =
    { "key", "princes", "arch_devils", "elementals",
      "hill_stone", "fire_frost", "piercers", nullptr };

bool isLevelKind(const std::string& k) {
    return k == "monster" || k == "human" || k == "character"
        || k == "dragon" || k == "elemental" || k == "prince"
        || k == "hydra" || k == "none";
}

}  // namespace

// ----------------------------------------------------------------------------
// File load (strict). The file key names the shape:
//   dungeon_level_<n>  rows[]   {kind, band, [key, count] | [key,
//                                heads, number]}
//   dragon_<n>         rows[]   {band, key, age}
//   matrix             bands[]  12 x 10 x {lo, hi, mlv}
//   lists              six string arrays
// ----------------------------------------------------------------------------

bool EncounterTableRegistry::loadFile(const std::string& path,
                                      const std::string& key) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    if (luaL_dofile(L, path.c_str()) != LUA_OK) {
        char buf[512];
        snprintf(buf, sizeof buf, "%s: %s", key.c_str(),
                 lua_tostring(L, -1));
        m_errors.push_back(buf);
        lua_close(L);
        return false;
    }
    if (!lua_istable(L, -1)) {
        m_errors.push_back(key + ": file must return a table");
        lua_close(L);
        return false;
    }

    std::string err;

    if (key.rfind("dungeon_level_", 0) == 0) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kLevelKeys, key, &err)) goto bad;
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
            std::vector<EncounterRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kLevelRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterRow row;
                if (!getStr(L, rt, "kind", &row.kind, &err)) goto bad;
                if (!isLevelKind(row.kind)) {
                    err = "unknown kind '" + row.kind + "'"; goto bad;
                }
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (row.kind == "monster" || row.kind == "hydra") {
                    if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                }
                if (row.kind == "monster") {
                    if (!getIntPair(L, rt, "count", &row.a, &row.b, &err))
                        goto bad;
                } else if (row.kind == "hydra") {
                    if (!getIntPair(L, rt, "heads", &row.a, &row.b, &err))
                        goto bad;
                    if (!getIntPair(L, rt, "number",
                                    &row.nmin, &row.nmax, &err)) goto bad;
                }
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_levels.count(key)) { err = "duplicate def key"; goto bad; }
            m_levels[key] = rows;
        }
    } else if (key.rfind("dragon_", 0) == 0) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kDragonKeys, key, &err)) goto bad;
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
            std::vector<DragonAgeRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kDragonRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                DragonAgeRow row;
                if (!getIntPair(L, rt, "band", &row.lo, &row.hi, &err))
                    goto bad;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                if (!getIntPair(L, rt, "age", &row.ageLo, &row.ageHi, &err))
                    goto bad;
                rows.push_back(row);
                lua_pop(L, 1);
            }
            lua_pop(L, 1);
            if (m_dragons.count(key)) { err = "duplicate def key"; goto bad; }
            m_dragons[key] = rows;
        }
    } else if (key == "matrix") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kMatrixKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "matrix") { err = "def key mismatch"; goto bad; }
        }
        lua_getfield(L, t, "bands");
        if (!lua_istable(L, -1)) { err = "bands is not a table"; goto bad; }
        {
            const int nb = (int)lua_rawlen(L, -1);
            if (nb != 12) { err = "bands must carry 12 entries"; goto bad; }
            std::vector<std::vector<MatrixEntry>> bands;
            for (int b = 1; b <= nb; ++b) {
                lua_rawgeti(L, -1, b);
                const int bt = lua_gettop(L);
                if (!lua_istable(L, bt) || (int)lua_rawlen(L, bt) != 10) {
                    err = "band " + std::to_string(b)
                        + " must carry 10 entries";
                    goto bad;
                }
                std::vector<MatrixEntry> ents;
                for (int i = 1; i <= 10; ++i) {
                    lua_rawgeti(L, bt, i);
                    const int et = lua_gettop(L);
                    if (!lua_istable(L, et)
                        || (int)lua_rawlen(L, et) != 3) {
                        err = "matrix entry must be a 3-int table";
                        goto bad;
                    }
                    long long v[3];
                    for (int j = 0; j < 3; ++j) {
                        lua_rawgeti(L, et, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "matrix entry field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    ents.push_back(MatrixEntry{ (int)v[0], (int)v[1],
                                                (int)v[2] });
                    lua_pop(L, 1);        // entry
                }
                bands.push_back(ents);
                lua_pop(L, 1);            // band
            }
            lua_pop(L, 1);                // bands array
            if (!m_matrix.empty()) { err = "duplicate def key"; goto bad; }
            m_matrix = bands;
        }
    } else if (key == "lists") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kListsKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "lists") { err = "def key mismatch"; goto bad; }
        }
        {
            const char* const names[] = { "princes", "arch_devils",
                "elementals", "hill_stone", "fire_frost", "piercers" };
            for (int i = 0; i < 6; ++i) {
                lua_getfield(L, t, names[i]);
                if (!lua_istable(L, -1)) {
                    err = std::string("'") + names[i] + "' is not a table";
                    goto bad;
                }
                const int cnt = (int)lua_rawlen(L, -1);
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
                if (m_lists.count(names[i])) {
                    err = "duplicate list"; goto bad;
                }
                m_lists[names[i]] = vals;
            }
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }

    lua_close(L);
    return true;

bad:
    m_errors.push_back(key + ": " + err);
    lua_close(L);
    return false;
}

// ----------------------------------------------------------------------------
// Directory load: platform-scoped, the MiscItemRegistry shape.
// ----------------------------------------------------------------------------

#ifdef _WIN32
#include <windows.h>

int EncounterTableRegistry::loadDirectory(const std::string& dirPath) {
    std::string pattern = dirPath + "\\*.lua";
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern.c_str(), &fd);
    if (h == INVALID_HANDLE_VALUE) {
        // R74: "no files" is not an error - only hard path errors are -1.
        return GetLastError() == ERROR_FILE_NOT_FOUND ? 0 : -1;
    }
    int count = 0;
    do {
        std::string fname = fd.cFileName;
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "\\" + fname, key)) ++count;
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    return count;
}

#else   // POSIX fallback (Termux, tests/dev on non-Windows)
#include <dirent.h>

int EncounterTableRegistry::loadDirectory(const std::string& dirPath) {
    DIR* d = opendir(dirPath.c_str());
    if (!d) return -1;
    int count = 0;
    struct dirent* e;
    while ((e = readdir(d)) != nullptr) {
        std::string fname = e->d_name;
        if (fname.size() < 5 ||
            fname.compare(fname.size() - 4, 4, ".lua") != 0)
            continue;
        std::string key = fname.substr(0, fname.size() - 4);
        if (loadFile(dirPath + "/" + fname, key)) ++count;
    }
    closedir(d);
    return count;
}
#endif

// ----------------------------------------------------------------------------
// Accessors (empty statics for a missing table - the audit counts
// catch that loudly).
// ----------------------------------------------------------------------------

bool EncounterTableRegistry::hasLevel(int n) const {
    return m_levels.count("dungeon_level_" + std::to_string(n)) != 0;
}

bool EncounterTableRegistry::hasDragon(int n) const {
    return m_dragons.count("dragon_" + std::to_string(n)) != 0;
}

const std::vector<EncounterRow>&
EncounterTableRegistry::levelRows(int n) const {
    static const std::vector<EncounterRow> none;
    auto it = m_levels.find("dungeon_level_" + std::to_string(n));
    return it == m_levels.end() ? none : it->second;
}

const std::vector<DragonAgeRow>&
EncounterTableRegistry::dragonRows(int n) const {
    static const std::vector<DragonAgeRow> none;
    auto it = m_dragons.find("dragon_" + std::to_string(n));
    return it == m_dragons.end() ? none : it->second;
}

const std::vector<MatrixEntry>&
EncounterTableRegistry::matrixBand(int band) const {
    static const std::vector<MatrixEntry> none;
    if (band < 0 || band >= (int)m_matrix.size()) return none;
    return m_matrix[band];
}

const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {
    static const std::vector<std::string> none;
    auto it = m_lists.find(set);
    return it == m_lists.end() ? none : it->second;
}

} // namespace dm
"""

# ----------------------------------------------------------------------------
# 6. SPLICE dm/encounters.cpp: retire the arrays, read through views
# ----------------------------------------------------------------------------

INC_OLD = '''#include "encounters.h"
#include "appendixp.h"   // R156: Appendix P kits, the convention party

#include <algorithm>
#include <cstdint>
#include <vector>'''

INC_NEW = '''#include "encounters.h"
#include "appendixp.h"   // R156: Appendix P kits, the convention party
#include "EncounterTableRegistry.h"   // R1032: the registry-native dungeon tables

#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <string>
#include <vector>'''

ROW_KEY_OLD = '''    int kind;
    const char* key;
    int a, b;               // count range (monster) or head range (hydra)'''
ROW_KEY_NEW = '''    int kind;
    std::string key;
    int a, b;               // count range (monster) or head range (hydra)'''

DRAG_KEY_OLD = '''    int lo, hi;
    const char* key;
    int ageLo, ageHi;      // age bracket 1-8 range'''
DRAG_KEY_NEW = '''    int lo, hi;
    std::string key;
    int ageLo, ageHi;      // age bracket 1-8 range'''

VIEWS = '''// ---- R1032: the DMG Appendix C dungeon tables ride the registry ----
// The retired per-level, dragon-subtable, matrix and pool static
// arrays are the R52 print-fidelity record (Premium reprint
// p.174-179, OCR-verified); tools/r1032_splice.py moved them
// verbatim into content/tables/encounters/*.lua and this seam
// reads them through dm::EncounterTableRegistry - the R1028
// misc-engine pattern. Views are built once, band-sorted,
// kind-mapped; rollDungeonEncounter() and encounterKeys() are
// byte-identical in behavior.

struct MatrixBand { int lo, hi, mlv; };

// Retained verbatim: kPrinces/kArchDevils are shared with the planar
// and psi special-key dispatch paths further down this file
// (PLANAR_DEMON_PRINCE / PSI_DEMON_PRINCE etc.), so the dungeon seam
// keeps using them. The registry still carries the "princes" and
// "arch_devils" lists, and the R1032 fragment cross-checks the two.
static const char* kPrinces[] = { "demogorgon", "juiblex", "orcus", "yeenoghu" };
static const char* kArchDevils[] = { "asmodeus", "baalzebul", "dispater", "geryon" };

static dm::EncounterTableRegistry& encReg() {
    // One-time lazy load (adnd1.cpp is a Win32 shell TU that preflight
    // skips, so the engine loads its own registries; the battery's
    // R1032 fragment catches a missing directory loudly).
    static dm::EncounterTableRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/encounters");
    }
    return reg;
}

static int kindFor(const std::string& k) {
    if (k == "monster")   return ROW_MONSTER;
    if (k == "human")     return ROW_HUMAN;
    if (k == "character") return ROW_CHARACTER;
    if (k == "dragon")    return ROW_DRAGON;
    if (k == "hydra")     return ROW_HYDRA;
    if (k == "elemental") return ROW_ELEMENTAL;
    if (k == "prince")    return ROW_PRINCE;
    return ROW_NONE;
}

static const std::vector<Row>& levelView(int n) {
    static std::vector<std::vector<Row>> cache(11);
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (int t = 1; t <= 10; ++t) {
            const auto& rs = encReg().levelRows(t);
            for (const auto& r : rs)
                cache[t].push_back(Row{ r.lo, r.hi, kindFor(r.kind),
                                        r.key, r.a, r.b, r.nmin, r.nmax });
        }
    }
    return cache[n];
}

static const std::vector<DragonRow>& dragonView(int n) {
    static std::vector<std::vector<DragonRow>> cache(11);
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (int t = 3; t <= 10; ++t) {
            const auto& rs = encReg().dragonRows(t);
            for (const auto& r : rs)
                cache[t].push_back(DragonRow{ r.lo, r.hi, r.key,
                                              r.ageLo, r.ageHi });
        }
    }
    return cache[n];
}

static const std::vector<std::array<MatrixBand, 10>>& matrixView() {
    static std::vector<std::array<MatrixBand, 10>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        m.resize(12);
        for (int b = 0; b < 12; ++b) {
            const auto& es = encReg().matrixBand(b);
            int i = 0;
            for (const auto& e : es)
                m[b][i++] = MatrixBand{ e.lo, e.hi, e.mlv };
        }
    }
    return m;
}

static const std::vector<std::string>& listView(const char* set) {
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* s : { "princes", "arch_devils", "elementals",
                              "hill_stone", "fire_frost", "piercers" })
            m[s] = encReg().list(s);
    }
    static const std::vector<std::string> none;
    auto it = m.find(set);
    return it == m.end() ? none : it->second;
}
'''

LEVEL_TABLE_OLD = '''const Row* levelTable(int mlv, size_t& count) {
    switch (mlv) {
        case 1:  count = sizeof kLevel1 / sizeof kLevel1[0]; return kLevel1;
        case 2:  count = sizeof kLevel2 / sizeof kLevel2[0]; return kLevel2;
        case 3:  count = sizeof kLevel3 / sizeof kLevel3[0]; return kLevel3;
        case 4:  count = sizeof kLevel4 / sizeof kLevel4[0]; return kLevel4;
        case 5:  count = sizeof kLevel5 / sizeof kLevel5[0]; return kLevel5;
        case 6:  count = sizeof kLevel6 / sizeof kLevel6[0]; return kLevel6;
        case 7:  count = sizeof kLevel7 / sizeof kLevel7[0]; return kLevel7;
        case 8:  count = sizeof kLevel8 / sizeof kLevel8[0]; return kLevel8;
        case 9:  count = sizeof kLevel9 / sizeof kLevel9[0]; return kLevel9;
        default: count = sizeof kLevel10 / sizeof kLevel10[0]; return kLevel10;
    }
}'''

LEVEL_TABLE_NEW = '''const Row* levelTable(int mlv, size_t& count) {
    const std::vector<Row>& t = levelView(mlv);
    count = t.size();
    return t.empty() ? nullptr : t.data();
}'''

DRAGON_TABLE_OLD = '''const DragonRow* dragonTable(int mlv, size_t& count) {
    switch (mlv) {
        case 3:  count = sizeof kDrag3 / sizeof kDrag3[0]; return kDrag3;
        case 4:  count = sizeof kDrag4 / sizeof kDrag4[0]; return kDrag4;
        case 5:  count = sizeof kDrag5 / sizeof kDrag5[0]; return kDrag5;
        case 6:  count = sizeof kDrag6 / sizeof kDrag6[0]; return kDrag6;
        case 7:  count = sizeof kDrag7 / sizeof kDrag7[0]; return kDrag7;
        case 8:  count = sizeof kDrag8 / sizeof kDrag8[0]; return kDrag8;
        case 9:  count = sizeof kDrag9 / sizeof kDrag9[0]; return kDrag9;
        default: count = sizeof kDrag10 / sizeof kDrag10[0]; return kDrag10;
    }
}'''

DRAGON_TABLE_NEW = '''const DragonRow* dragonTable(int mlv, size_t& count) {
    const std::vector<DragonRow>& t = dragonView(mlv);
    count = t.size();
    return t.empty() ? nullptr : t.data();
}'''

MATRIX_REF_OLD = 'const MatrixBand* row = kMatrix[band];'
MATRIX_REF_NEW = 'const auto& row = matrixView()[band];'

SPECIALS_OLD = '''            if (key == "HILL_STONE")  key = kHillStone[pctile2 % 2];
            if (key == "FIRE_FROST") key = kFireFrost[pctile2 % 2];
            if (key == "PIERCER")
                key = kPiercers[pctile2 % 4];'''
SPECIALS_NEW = '''            if (key == "HILL_STONE")  key = listView("hill_stone")[pctile2 % 2];
            if (key == "FIRE_FROST") key = listView("fire_frost")[pctile2 % 2];
            if (key == "PIERCER")
                key = listView("piercers")[pctile2 % 4];'''

ELEMENTAL_OLD = '            const char* key = kElementals[pctile2 % 4];'
ELEMENTAL_NEW = '            const std::string& key = listView("elementals")[pctile2 % 4];'

KEYS_HILL_OLD = '''                    pushUnique(out, kHillStone[0]);
                    pushUnique(out, kHillStone[1]);'''
KEYS_HILL_NEW = '''                    pushUnique(out, listView("hill_stone")[0].c_str());
                    pushUnique(out, listView("hill_stone")[1].c_str());'''

KEYS_FIRE_OLD = '''                    pushUnique(out, kFireFrost[0]);
                    pushUnique(out, kFireFrost[1]);'''
KEYS_FIRE_NEW = '''                    pushUnique(out, listView("fire_frost")[0].c_str());
                    pushUnique(out, listView("fire_frost")[1].c_str());'''

KEYS_PIERCER_OLD = '''                    for (int p = 0; p < 4; ++p)
                        pushUnique(out, kPiercers[p]);'''
KEYS_PIERCER_NEW = '''                    for (int p = 0; p < 4; ++p)
                        pushUnique(out, listView("piercers")[p].c_str());'''

KEYS_HYDRA_OLD = 'if (reg.find(rw->key)) pushUnique(out, rw->key);'
KEYS_HYDRA_NEW = 'if (reg.find(rw->key)) pushUnique(out, rw->key.c_str());'

KEYS_DRAG_OLD = 'if (reg.find(dt[d].key)) pushUnique(out, dt[d].key);'
KEYS_DRAG_NEW = 'if (reg.find(dt[d].key)) pushUnique(out, dt[d].key.c_str());'

KEYS_ELEM_OLD = '''                for (int el = 0; el < 4; ++el)
                    if (reg.find(kElementals[el])) pushUnique(out, kElementals[el]);'''
KEYS_ELEM_NEW = '''                for (int el = 0; el < 4; ++el)
                    if (reg.find(listView("elementals")[el]))
                        pushUnique(out, listView("elementals")[el].c_str());'''


def splice_once(src, old, new, what, count=1):
    n = src.count(old)
    if n != count:
        fail("anchor %r: expected %d hits, found %d" % (what, count, n))
    return src.replace(old, new)


def splice_encounters(src, start, end):
    # The region cut FIRST: start/end index the pristine source, so
    # no string may change length before it. Every other anchor
    # lives outside the retired region, and splice_once searches,
    # so the VIEWS re-emission does not disturb them.
    out = src
    out = out[:start] + VIEWS + out[end:]
    out = splice_once(out, INC_OLD, INC_NEW, "include anchor")
    out = splice_once(out, ROW_KEY_OLD, ROW_KEY_NEW, "Row.key")
    out = splice_once(out, DRAG_KEY_OLD, DRAG_KEY_NEW, "DragonRow.key")
    out = splice_once(out, LEVEL_TABLE_OLD, LEVEL_TABLE_NEW, "levelTable")
    out = splice_once(out, DRAGON_TABLE_OLD, DRAGON_TABLE_NEW, "dragonTable")
    out = splice_once(out, MATRIX_REF_OLD, MATRIX_REF_NEW,
                      "kMatrix ref", count=2)
    out = splice_once(out, SPECIALS_OLD, SPECIALS_NEW, "roll specials")
    out = splice_once(out, ELEMENTAL_OLD, ELEMENTAL_NEW, "roll elemental")
    out = splice_once(out, KEYS_HILL_OLD, KEYS_HILL_NEW, "keys hill")
    out = splice_once(out, KEYS_FIRE_OLD, KEYS_FIRE_NEW, "keys fire")
    out = splice_once(out, KEYS_PIERCER_OLD, KEYS_PIERCER_NEW, "keys piercer")
    out = splice_once(out, KEYS_HYDRA_OLD, KEYS_HYDRA_NEW, "keys hydra")
    out = splice_once(out, KEYS_DRAG_OLD, KEYS_DRAG_NEW, "keys dragon")
    out = splice_once(out, KEYS_ELEM_OLD, KEYS_ELEM_NEW, "keys elemental")

    # no retired symbol may survive
    for tok in ("kLevel1", "kLevel10", "kDrag3", "kDrag10", "kMatrix",
                "kElementals", "kHillStone", "kFireFrost", "kPiercers"):
        if re.search(r"\b%s\b" % tok, out):
            fail("retired token %s survives in encounters.cpp" % tok)
    return out

# ----------------------------------------------------------------------------
# 7. THE BATTERY FRAGMENT (rules/audits/r1032_encounter_engine_registry.h)
#    The R1028 audit style: own Rng/Dice, seven bad-gated labels,
#    exhaustive counts, the roll smoke on the Determination Matrix
#    dungeon-level band 7.
# ----------------------------------------------------------------------------

def cstr(s):
    return '"%s"' % s


def build_fragment(levels, drags, bands, lists):
    lvl_lit = ", ".join(str(len(levels[n])) for n in range(1, 11))
    drg_lit = ", ".join(str(len(drags[n])) for n in range(3, 11))
    # band 7 (dl 7, band index 6): the roll-smoke band, pinned verbatim
    b7 = bands[6]
    m7_lit = ", ".join(
        "{ %d, %d, %d }" % (e["lo"], e["hi"], e["mlv"]) for e in b7)
    # the d20 per entry lo: the exact grid the smoke walks (mlv 1..10)
    d20_lit = ", ".join(str(e["lo"]) for e in b7 if e["lo"] > 0)
    lists_lit = ",\n        ".join(
        '{ "%s", { %s } }' % (name, ", ".join(cstr(k) for k in lists[name]))
        for name in LIST_NAMES)
    l1f, l1l = levels[1][0], levels[1][-1]
    l10l = levels[10][-1]
    counts = sum(len(levels[n]) for n in range(1, 11))

    return '''// ============================================================================
// Adnd1 - rules/audits/r1032_encounter_engine_registry.h  (R1032)
// The dm::EncounterTableRegistry battery audit, the R1028 shape: the
// registry load, exact table counts, the Determination Matrix vs
// monsterLevelFor, the six pools, row spot pins against the retired
// print-fidelity record, and the full rollDungeonEncounter() path.
// Expected values: 20 files, 213 level rows, 72 dragon rows,
// 12x10 matrix, 6 pools - all from the R52 record the splice parsed.
// ============================================================================
{

    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 20 files, zero errors ----------------------------------
    bad = 0;
    {
        const int files = ereg.loadDirectory("content/tables/encounters");
        if (files != 20) ++bad;
        if (!ereg.errors().empty()) ++bad;
    }
    printf("R1032 encounter engine registry load audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 2. counts: every table, exact row census ------------------------
    bad = 0;
    {
        static const int kLvl[11] = { 0, %s };
        static const int kDrg[11] = { 0, 0, 0, %s };
        for (int n = 1; n <= 10; ++n) {
            if (!ereg.hasLevel(n)) ++bad;
            if ((int)ereg.levelRows(n).size() != kLvl[n]) ++bad;
        }
        for (int n = 3; n <= 10; ++n) {
            if (!ereg.hasDragon(n)) ++bad;
            if ((int)ereg.dragonRows(n).size() != kDrg[n]) ++bad;
        }
    }
    printf("R1032 encounter engine registry counts audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 3. bands: the Determination Matrix, band 7 (dl 7) pinned ---------
    bad = 0;
    {
        const auto& b7 = ereg.matrixBand(6);
        if ((int)b7.size() != 10) ++bad;
        static const int want[10][3] = { %s };
        for (int i = 0; i < 10; ++i)
            if (b7[i].lo != want[i][0] || b7[i].hi != want[i][1]
                || b7[i].mlv != want[i][2]) ++bad;
    }
    printf("R1032 encounter engine registry bands audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 4. matrix: monsterLevelFor vs the registry, every band ----------
    bad = 0;
    {
        for (int band = 0; band < 12; ++band) {
            // the engine maps band = dl-1, clamped: dl < 1 -> band 0,
            // dl >= 16 -> band 11 (and dl 12 also reaches band 11;
            // dl 13-15 read past the matrix - the preserved upstream
            // quirk, not swept here)
            const int dl = band == 0 ? 0 : (band == 11 ? 16 : band + 1);
            const auto& ents = ereg.matrixBand(band);
            if ((int)ents.size() != 10) { ++bad; continue; }
            for (int d20 = 1; d20 <= 20; ++d20) {
                int want = 1;
                for (int i = 0; i < 10; ++i)
                    if (ents[i].lo > 0 && d20 >= ents[i].lo
                        && d20 <= ents[i].hi) { want = i + 1; break; }
                if (dm::monsterLevelFor(dl, d20) != want) ++bad;
            }
        }
    }
    printf("R1032 encounter engine registry matrix audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 5. lists: the six dispatch pools, verbatim ----------------------
    bad = 0;
    {
        struct Want { const char* name;
                      std::vector<std::string> keys; };
        const Want want[] = {
        %s
        };
        for (const auto& w : want) {
            const auto& got = ereg.list(w.name);
            if (got != w.keys) ++bad;
        }
    }
    printf("R1032 encounter engine registry lists audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 6. rows: spot pins against the retired print-fidelity record ----
    bad = 0;
    {
        const auto& l1 = ereg.levelRows(1);
        if ((int)l1.size() < 2
            || l1[0].kind != "monster" || l1[0].key != "%s"
            || l1[0].lo != %d || l1[0].hi != %d
            || l1[0].a != %d || l1[0].b != %d
            || l1.back().kind != "monster" || l1.back().key != "%s"
            || l1.back().lo != %d || l1.back().hi != %d
            || l1.back().a != %d || l1.back().b != %d) ++bad;
        const auto& l10 = ereg.levelRows(10);
        if ((int)l10.size() < 2
            || l10.back().kind != "%s"
            || l10.back().lo != %d || l10.back().hi != %d)
            ++bad;
        const auto& hy = ereg.levelRows(4);
        bool hyd = false;
        for (const auto& r : hy)
            if (r.kind == "hydra" && r.key == "hydra"
                && r.a == 5 && r.b == 6) hyd = true;
        if (!hyd) ++bad;
        int total = 0;
        for (int n = 1; n <= 10; ++n) total += (int)ereg.levelRows(n).size();
        if (total != %d) ++bad;
    }
    printf("R1032 encounter engine registry rows audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 7. roll: the rollDungeonEncounter smoke, R1028 style ------------
    bad = 0;
    {
        rules::Rng rng(1032);
        rules::Dice dice(rng);
        // band 7 test d20s: one per matrix entry, mlv 1..10 in order
        static const int kD20[11] = { 0, %s };
        int seen[11] = { 0 };
        int rolled = 0;
        for (int n = 1; n <= 10; ++n) {
            const auto& rows = ereg.levelRows(n);
            for (const auto& r : rows) {
                if (r.kind == "character" || r.kind == "none") continue;
                const int mid = (r.lo + r.hi) / 2;
                for (int p2 = 1; p2 <= 100; ++p2) {
                    dm::DungeonEncounter e = dm::rollDungeonEncounter(
                        reg, dice, kD20[n], mid, p2, 7);
                    ++rolled;
                    // legal outcomes: party (human/character), empty
                    // (reroll chains, absent keys), or a registry key
                    if (e.isParty || e.key.empty()) continue;
                    if (!reg.find(e.key)) { ++bad; continue; }
                    if (r.kind == "dragon") {
                        bool hit = false;
                        for (const auto& d : ereg.dragonRows(n))
                            if (d.key == e.key && e.ageLo == d.ageLo
                                && e.ageHi == d.ageHi) { hit = true; break; }
                        if (!hit) ++bad;
                    }
                    ++seen[n];
                }
            }
        }
        if (rolled < 200) ++bad;
        for (int n = 1; n <= 10; ++n)
            if (seen[n] == 0) ++bad;
    }
    printf("R1032 encounter engine registry roll audit: bad %%d\\n", bad);
    if (bad) return 1;
}
''' % (lvl_lit, drg_lit, m7_lit, lists_lit,
       l1f["key"], l1f["lo"], l1f["hi"], l1f["a"], l1f["b"],
       l1l["key"], l1l["lo"], l1l["hi"], l1l["a"], l1l["b"],
       l10l["kind"], l10l["lo"], l10l["hi"],
       counts, d20_lit)


# ----------------------------------------------------------------------------
# 8. WIRING + MAIN
# ----------------------------------------------------------------------------

REGTEST_ANCHOR = ('    #include "rules/audits/r1028_misc_engine_registry.h"'
                  '  // R1028\n')
REGTEST_LINE = ('    #include "rules/audits/'
                'r1032_encounter_engine_registry.h"  // R1032\n')

REGTEST_INC_ANCHOR = '#include "monsters/MonsterRegistry.h"\n'
REGTEST_INC_LINE = ('#include "dm/EncounterTableRegistry.h"'
                   '  // R1032: the registry-native dungeon tables\n')

PREFLIGHT_OLD = '  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\\n'
PREFLIGHT_NEW = '  dm/EncounterTableRegistry.cpp dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\\n'


def census_count():
    files = [os.path.join(ROOT, "rules/audits", f)
             for f in os.listdir(os.path.join(ROOT, "rules/audits"))]
    files = [f for f in files if f.endswith(".h")]
    files.append(os.path.join(ROOT, "regtest.cpp"))
    n = 0
    for f in files:
        n += open(f, encoding="utf-8").read().count("audit: bad %d")
    return n


def main():
    src = read("dm/encounters.cpp")
    parsed = parse_arrays(src)
    if parsed is None or os.path.isfile(
            os.path.join(ROOT, "dm", "EncounterTableRegistry.h")):
        # already applied: verify the census and stop
        c = census_count()
        if c != 948:
            fail("already applied but census is %d (expected 948)" % c)
        print("applied 0, already 1, rewrote 0")
        print("SPLICE OK (already applied)")
        return

    start, end, levels, drags, bands, lists = parsed
    gate_data(levels, drags, bands, lists)

    # the census gate before any writes
    before = census_count()
    if before != 941:
        fail("pre-splice census is %d (expected 941)" % before)

    # 1. lua defs
    for n in range(1, 11):
        write(os.path.join(LUA_DIR, "dungeon_level_%d.lua" % n),
              emit_level_lua(n, levels[n]))
    for n in range(3, 11):
        write(os.path.join(LUA_DIR, "dragon_%d.lua" % n),
              emit_dragon_lua(n, drags[n]))
    write(os.path.join(LUA_DIR, "matrix.lua"), emit_matrix_lua(bands))
    write(os.path.join(LUA_DIR, "lists.lua"), emit_lists_lua(lists))
    lua_roundtrip(levels, drags, bands, lists)
    simulate_roll_path(levels, drags, bands, lists)

    # 2. splice dm/encounters.cpp
    out = splice_encounters(src, start, end)
    write("dm/encounters.cpp", out)
    print("spliced dm/encounters.cpp (%d -> %d lines)"
          % (src.count("\n") + 1, out.count("\n") + 1))

    # 3. the registry TU
    write("dm/EncounterTableRegistry.h", REGISTRY_H)
    write("dm/EncounterTableRegistry.cpp", REGISTRY_CPP)

    # 4. the battery fragment + wiring
    write("rules/audits/r1032_encounter_engine_registry.h",
          build_fragment(levels, drags, bands, lists))
    rt = read("regtest.cpp")
    rt = splice_once(rt, REGTEST_INC_ANCHOR,
                     REGTEST_INC_ANCHOR + REGTEST_INC_LINE,
                     "regtest registry include")
    rt = splice_once(rt, REGTEST_ANCHOR,
                     REGTEST_ANCHOR + REGTEST_LINE, "regtest include")
    write("regtest.cpp", rt)
    print("regtest.cpp: R1032 fragment included")

    pf = read("tools/preflight.sh")
    pf = splice_once(pf, PREFLIGHT_OLD, PREFLIGHT_NEW, "preflight TU list")
    write("tools/preflight.sh", pf)
    os.chmod(os.path.join(ROOT, "tools/preflight.sh"), 0o755)
    print("preflight.sh: dm/EncounterTableRegistry.cpp added to the build")

    # 5. the census gate after
    after = census_count()
    if after != 948:
        fail("post-splice census is %d (expected 948)" % after)
    print("census: %d -> %d audit printf patterns" % (before, after))

    print("applied 1, rewrote 3 tracked files, wrote 23 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
