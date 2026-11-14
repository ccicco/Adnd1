#!/usr/bin/env python3
# r1037_splice.py - R1037: the R66 psionic encounter table de-wire
# (the R1032-R1036 shape; census 976 -> 983)
#
# The R66 region of dm/encounters.cpp (separator above
# "// R66: the PSIONIC ENCOUNTER TABLE" through separator above
# "// R67: the PATROL") retires into content/tables/
# encounters_psionic/: the 19-row kPsionicTable (the percentile
# bands, the printed Numbers column, the PSI_* pseudo-keys) into
# psionic_table.lua (the EncounterPlanarRow shape - the loader
# branch gains the exact key), and the printed "Spells
# Resembling Psionic Powers" lists (20 exact + 6 family
# prefixes) into psionic_spells.lua (two registry lists). The
# pick rows resolve through the R1036 planarSetView (already in
# place); kPrinces/kArchDevils stay engine-side (the R52
# record). Mechanics stay verbatim in the engine: the 24-attempt
# ignore-&-reroll, the second-percentile modulo selection, the
# (**) Men character party (rollCharacterParty(dice, 8, 8)), the
# yellow_mold printed dash (registry noAppearing fallback), the
# printed Numbers column, and the case-insensitive spell
# matching. Fragment: rules/audits/
# r1037_psionic_encounter_registry.h (7 sections, census +7).
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
                       "encounters_psionic")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1037_psionic_encounter_registry.h")

# ---------------------------------------------------------------------------
# 0. the retired inventory (asserted against the source at parse time)
# ---------------------------------------------------------------------------

ROWS = 19
SPELLS_EXACT = 20
SPELLS_FAMILY = 6
COMPANION = 41        # 13 plain + 27 picks/princes/arch + 1 party

# the printed spells lists are PARSED from the region; these are
# the expected contents (the R1035 never-recall lesson: the
# parse gates them against the source)
WANT_EXACT = [
    "astral spell", "augury", "blink", "clairadience",
    "clairvoyance", "dimension door", "enlarge", "esp",
    "feather fall", "feign death", "heat metal", "heal",
    "hypnotism", "know alignment", "levitation",
    "plane shift", "remove curse", "shape change",
    "stone tell", "temporal stasis",
]
WANT_FAMILY = ["charm", "cure", "detect", "invisibility",
               "polymorph", "tele"]

# the pick rows reuse the R1036 sets (already registry lists)
PICK_SETS = [
    ("demon_major", 10),
    ("demon_minor", 6),
    ("devil_greater", 3),
]
PRINCES = ["demogorgon", "juiblex", "orcus", "yeenoghu"]
ARCH_DEVILS = ["asmodeus", "baalzebul", "dispater", "geryon"]

# every source substring the retired region must carry
ASSERTS = [
    'static const PsionicRow kPsionicTable[] = {',
    'DungeonEncounter rollPsionicEncounter(',
    'std::vector<std::string> psionicEncounterKeys(',
    'bool spellResemblesPsionicPower(const std::string& name) {',
    'static const char* const exact[] = {',
    'static const char* const family[] = {',
    'rollCharacterParty(dice, 8, 8)',
    'planarSetView("demon_major_set")',
    'planarSetView("demon_minor_set")',
    'planarSetView("devil_greater_set")',
    'kPrinces[pctile2 % 4]',
    'kArchDevils[pctile2 % 4]',
    'attempt < 24',
    'dice.roll(1, 100, 0)',
    'def->noAppearingMin',
    'key == "yellow_mold"',
    'PSI_MEN',
    'PSI_DEMON_MAJOR',
    'PSI_DEMON_MINOR',
    'PSI_DEMON_PRINCE',
    'PSI_DEVIL_ARCH',
    'PSI_DEVIL_GREATER',
    'pushUnique(out, "character_party")',
]

# full-declaration tokens only (the R1036 lesson): the retained
# c66 provenance comment mentions spellResemblesPsionicPower by
# name, and the seam re-declares the public functions with the
# same signatures - so the retired-token list must carry only
# what the seam truly retires
RETIRED_TOKENS = [
    "kPsionicTable",
    "struct PsionicRow",
    "sizeof kPsionicTable",
    "static const char* const exact[]",
    "static const char* const family[]",
]


def die(msg):
    sys.stderr.write("r1037_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---------------------------------------------------------------------------
# 1. parse the retired region out of dm/encounters.cpp
# ---------------------------------------------------------------------------

REGION_START = "// R66: the PSIONIC ENCOUNTER TABLE"
REGION_END = "// R67: the PATROL and CASTLE/FORTRESS tables"
SEP = "// ----------------------------------------------------------------------------"


def parse_psionic_region(src):
    if "kPsionicTable" not in src:
        die("kPsionicTable not found (already spliced?)")
    i0 = src.index(REGION_START)
    i0 = src.rindex(SEP, 0, i0)
    i1 = src.index(REGION_END)
    i1 = src.rindex(SEP, i0, i1)
    region = src[i0:i1]

    for a in ASSERTS:
        if a not in region:
            die("assertion failed, the retired region must "
                "carry %r" % a)

    # the 19 rows: (lo, hi, key, nMin, nMax)
    m = re.search(r"static const PsionicRow kPsionicTable\[\]"
                  r" = \{(.*?)\};", region, re.S)
    if not m:
        die("kPsionicTable array not found")
    rows = re.findall(
        r"\{(\d+),\s*(\d+),\s*\"([A-Za-z_0-9]+)\","
        r"\s*(\d+),\s*(\d+)[^}]*\}", m.group(1))
    if len(rows) != ROWS:
        die("parsed %d psionic rows (expected %d)"
            % (len(rows), ROWS))
    table = [(int(a), int(b), k, int(c), int(d))
             for a, b, k, c, d in rows]

    # the printed spells lists (verbatim, lower-case in source)
    m = re.search(r"static const char\* const exact\[\] = \{"
                  r"(.*?)\};", region, re.S)
    if not m:
        die("the exact spells array not found")
    exact = re.findall(r'"([a-z\'\- ]+)"', m.group(1))
    if exact != WANT_EXACT:
        die("the exact spells list drifted from the record")
    m = re.search(r"static const char\* const family\[\] = \{"
                  r"(.*?)\};", region, re.S)
    if not m:
        die("the family spells array not found")
    family = re.findall(r'"([a-z]+)"', m.group(1))
    if family != WANT_FAMILY:
        die("the family spells list drifted from the record")

    # the verbatim provenance header (kept in the seam)
    c66 = region[:region.index("namespace {")].rstrip() + "\n"
    return i0, i1, table, exact, family, c66


# ---------------------------------------------------------------------------
# 2. gate data + the python twin of the roll path
# ---------------------------------------------------------------------------

def gate_data(table):
    problems = []
    prev = 0
    for lo, hi, key, nMin, nMax in table:
        if lo != prev + 1 or hi < lo or hi > 100:
            problems.append("band %r at %s" % ((lo, hi), key))
        if nMin < 0 or nMax < nMin or nMax > 100:
            problems.append("numbers %r at %s" % ((nMin, nMax), key))
        prev = hi
    if prev != 100:
        problems.append("chain ends at %d" % prev)
    return problems


# pseudo-key -> expanded member list
def expansion(key):
    if key == "PSI_DEMON_MAJOR":
        return None       # gated on the set at audit time
    if key == "PSI_DEMON_MINOR":
        return None
    if key == "PSI_DEVIL_GREATER":
        return None
    if key == "PSI_DEMON_PRINCE":
        return list(PRINCES)
    if key == "PSI_DEVIL_ARCH":
        return list(ARCH_DEVILS)
    if key == "PSI_MEN":
        return ["character_party"]
    return [key]


def expected_keys(table, picks):
    pm = dict(picks)   # set_key (no suffix) -> members
    set_of = {"PSI_DEMON_MAJOR": "demon_major",
              "PSI_DEMON_MINOR": "demon_minor",
              "PSI_DEVIL_GREATER": "devil_greater"}
    out = []
    def push(k):
        if k not in out:
            out.append(k)
    for lo, hi, key, nMin, nMax in table:
        if key in set_of:
            for v in pm[set_of[key]]:
                push(v)
        else:
            for v in expansion(key):
                push(v)
    return out


def simulate_roll_path(table, picks):
    keys = expected_keys(table, picks)
    if len(keys) != COMPANION:
        die("companion computed %d (expected %d)"
            % (len(keys), COMPANION))
    plain = [k for k in keys if not k.startswith("type_")
             and k not in PRINCES and k not in ARCH_DEVILS
             and k != "character_party"]
    # the 13 plain rows must be bestiary keys the audit can find
    for pct in range(1, 101):
        row = None
        for lo, hi, key, nMin, nMax in table:
            if pct >= lo and pct <= hi:
                row = key
                break
        if row is None:
            die("no row for pctile %d" % pct)
        if row.startswith("PSI_") and row not in (
                "PSI_MEN",):
            if not expansion(row) and row not in (
                    "PSI_DEMON_MAJOR", "PSI_DEMON_MINOR",
                    "PSI_DEVIL_GREATER"):
                die("unexpandable pseudo-key %r" % row)
    for k in keys:
        if k.startswith("PSI_"):
            die("pseudo-key %r leaked into the companion" % k)
    return len(keys), len(plain)


# ---------------------------------------------------------------------------
# 3. lua emission + round-trip
# ---------------------------------------------------------------------------

LUA_HDR = """-- encounter table def: %(key)s
-- The R66 psionic family (R1037 de-wire): %(what)s
-- (DMG Appendix C Premium reprint p.182, OCR-verified).
-- %(note)s
-- DO NOT hand-edit: tools/r1037_splice.py is the only writer.

"""


def table_lua_text(table):
    out = [LUA_HDR % dict(
        key="psionic_table",
        what="the PSIONIC ENCOUNTER TABLE",
        note="band = the percentile column; key = the bestiary "
             "key or the printed pseudo-key (the PSI_* demon/"
             "devil rows resolve through the R1036 planar "
             "pick-sets on the second percentile; PSI_MEN "
             "builds a character party); numbers = the printed "
             "Numbers column (0,0 marks the Men party and the "
             "yellow mold dash - the engine handles both). "
             "primeOnly is always false here (the psionic table "
             "prints no (*) footnote) but rides the shared "
             "planar row shape.")]
    out.append("return {\n")
    out.append('  key = "psionic_table",\n')
    out.append("  rows = {\n")
    for lo, hi, key, nMin, nMax in table:
        out.append('    { band = {%d,%d}, key = "%s", '
                   'numbers = {%d,%d}, primeOnly = false },\n'
                   % (lo, hi, key, nMin, nMax))
    out.append("  },\n}\n")
    return "".join(out)


def spells_lua_text(exact, family):
    out = [LUA_HDR % dict(
        key="psionic_spells",
        what="the printed Spells Resembling Psionic Powers list",
        note="exact = the 20 printed spell names (matched "
             "case-insensitively on the full name); family = "
             "the 6 printed '(any)' leading words (charm, cure, "
             "detect, invisibility, polymorph, tele-), matched "
             "by prefix. The engine's matching logic is "
             "spellResemblesPsionicPower's, unchanged.")]
    out.append("return {\n")
    out.append('  key = "psionic_spells",\n')
    out.append('  exact = { "%s" },\n'
               % '", "'.join(exact))
    out.append('  family = { "%s" },\n'
               % '", "'.join(family))
    out.append("}\n")
    return "".join(out)


def emit_lua(table, exact, family):
    os.makedirs(LUA_DIR, exist_ok=True)
    texts = {
        "psionic_table.lua": table_lua_text(table),
        "psionic_spells.lua": spells_lua_text(exact, family),
    }
    for name in sorted(texts):
        with open(os.path.join(LUA_DIR, name), "w") as f:
            f.write(texts[name])


def lua_roundtrip(table, exact, family):
    t = open(os.path.join(LUA_DIR, "psionic_table.lua")).read()
    got = [(int(a), int(b), k, int(c), int(d))
           for a, b, k, c, d in re.findall(
        r'\{ band = \{(\d+),(\d+)\}, key = "([A-Za-z_0-9]+)", '
        r'numbers = \{(\d+),(\d+)\}, primeOnly = '
        r'(?:true|false) \}', t)]
    if got != table:
        die("round-trip: psionic_table mismatch")
    t = open(os.path.join(LUA_DIR, "psionic_spells.lua")).read()
    m = re.search(r'exact = \{ (.*?) \},\n', t)
    if not m:
        die("round-trip: the exact list missing")
    if re.findall(r'"([^"]+)"', m.group(1)) != exact:
        die("round-trip: the exact list mismatch")
    m = re.search(r'family = \{ (.*?) \},\n', t)
    if not m:
        die("round-trip: the family list missing")
    if re.findall(r'"([^"]+)"', m.group(1)) != family:
        die("round-trip: the family list mismatch")


# ---------------------------------------------------------------------------
# 4. the registry extension (comment, the planar-branch key, the
#    spells loader branch)
# ---------------------------------------------------------------------------

def replace_once(text, old, new, where):
    n = text.count(old)
    if n != 1:
        die("%s: anchor appears %d times (expected 1)"
            % (where, n))
    return text.replace(old, new, 1)


H_COMMENT_OLD = """// tools/r1034_splice.py (outdoor family),
// tools/r1035_splice.py (city family) and
// tools/r1036_splice.py (planar family) are the only writers."""
H_COMMENT_NEW = """// tools/r1034_splice.py (outdoor family),
// tools/r1035_splice.py (city family),
// tools/r1036_splice.py (planar family) and
// tools/r1037_splice.py (psionic family) are the only writers."""

CPP_BRANCH_OLD = """    } else if (key == "planar_astral"
               || key == "planar_ethereal") {"""
CPP_BRANCH_NEW = """    } else if (key == "planar_astral"
               || key == "planar_ethereal"
               || key == "psionic_table") {"""

CPP_KEYS_ANCHOR = """const char* const kPlanarFileKeys[]  = { "key", "rows", nullptr };"""
CPP_KEYS_NEW = """const char* const kPlanarFileKeys[]  = { "key", "rows", nullptr };
// R1037: the psionic spells file keys (two registry lists).
// Exact keys only - no prefix, no exceptions (the R1034
// dispatch-order lesson).
const char* const kPsionicSpellKeys[] =
    { "key", "exact", "family", nullptr };"""

CPP_ELSE_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""
CPP_SPELLS_BRANCH = """    } else if (key == "psionic_spells") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kPsionicSpellKeys, key, &err))
            goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "psionic_spells") { err = "def key mismatch";
                                         goto bad; }
        }
        {
            static const char* const names[2] = { "exact",
                                                  "family" };
            for (int i = 0; i < 2; ++i) {
                lua_getfield(L, t, names[i]);
                if (!lua_istable(L, -1)) {
                    err = std::string("'") + names[i]
                        + "' is not a table";
                    goto bad;
                }
                const int cnt = (int)lua_rawlen(L, -1);
                if (cnt < 1) {
                    err = std::string("'") + names[i]
                        + "' must carry at least one entry";
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
                    std::string("psionic_spell_") + names[i];
                if (m_lists.count(setKey)) {
                    err = "duplicate def key";
                    goto bad;
                }
                m_lists[setKey] = vals;
            }
        }
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

ENC_LOAD_ANCHOR = '        reg.loadDirectory("content/tables/encounters_planar");'
ENC_LOAD_NEW = ('        reg.loadDirectory("content/tables/encounters_planar");\n'
                '        reg.loadDirectory("content/tables/encounters_psionic");')

REGTEST_OLD = ('    #include "rules/audits/r1036_planar_encounter_registry.h"'
               '  // R1036')
REGTEST_NEW = ('    #include "rules/audits/r1036_planar_encounter_registry.h"'
               '  // R1036\n'
               '    #include "rules/audits/r1037_psionic_encounter_registry.h"'
               '  // R1037')


def extend_registry():
    with open(REG_H, encoding="utf-8") as f:
        h = f.read()
    h = replace_once(h, H_COMMENT_OLD, H_COMMENT_NEW,
                    "registry h comment")
    with open(REG_H, "w", encoding="utf-8") as f:
        f.write(h)

    with open(REG_CPP, encoding="utf-8") as f:
        c = f.read()
    c = replace_once(c, CPP_BRANCH_OLD, CPP_BRANCH_NEW,
                    "registry cpp planar branch")
    c = replace_once(c, CPP_KEYS_ANCHOR, CPP_KEYS_NEW,
                     "registry cpp keys")
    c = replace_once(c, CPP_ELSE_ANCHOR, CPP_SPELLS_BRANCH,
                     "registry cpp spells branch")
    with open(REG_CPP, "w", encoding="utf-8") as f:
        f.write(c)


# ---------------------------------------------------------------------------
# 5. the encounters.cpp seam (registry-backed views, mechanics
#    kept verbatim)
# ---------------------------------------------------------------------------

SEAM_NOTE = """
// R1037 (the registry-native de-wire, the R1032-R1036 shape):
// the 19-row psionic table retired into content/tables/
// encounters_psionic/psionic_table.lua (band = the percentile,
// key = the bestiary key or the printed PSI_* pseudo-key,
// numbers = the printed Numbers column; 0,0 marks the (**) Men
// party and the yellow mold dash); the printed "Spells
// Resembling Psionic Powers" lists into psionic_spells.lua
// (the registry lists psionic_spell_exact /
// psionic_spell_family). The rows ride the R1036 planar row
// shape and the loader branch's exact keys; the PSI_* demon/
// devil rows resolve through the R1036 planarSetView (the
// R1036 rewire, already in place); kPrinces/kArchDevils stay
// engine-side (the R52 record). What stays here is the
// mechanics: the 24-attempt ignore-&-reroll, the
// second-percentile modulo selection, the (**) Men character
// party (rollCharacterParty(dice, 8, 8), the R63 convention),
// the yellow mold printed dash (registry noAppearing
// fallback), the printed Numbers column, and the
// case-insensitive spell matching. Signatures and behavior
// are unchanged - the views are registry-backed.

namespace {

// the two printed spells lists (psionic_spells.lua -> the
// registry lists); the lazy-load idiom of planarSetView
static const std::vector<std::string>& psionicSpellView(
        const char* which) {
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        m["psionic_spell_exact"] =
            dm::encReg().list("psionic_spell_exact");
        m["psionic_spell_family"] =
            dm::encReg().list("psionic_spell_family");
    }
    static const std::vector<std::string> none;
    auto it = m.find(which);
    return it == m.end() ? none : it->second;
}

} // namespace
"""

SPELLS_FN = """
// R66: the printed "Spells Resembling Psionic Powers" list
// (p.182) - the exact names and the "(any)" family prefixes
// now live in psionic_spells.lua (the registry lists); the
// case-insensitive matching is the engine's, unchanged.
bool spellResemblesPsionicPower(const std::string& name) {
    std::string lower;
    for (char c : name) {
        unsigned char u = (unsigned char)c;
        lower.push_back((char)(u >= 'A' && u <= 'Z' ? u + 32 : u));
    }
    for (const auto& e : psionicSpellView("psionic_spell_exact"))
        if (lower == e) return true;
    // "(any)" families - the printed leading word
    for (const auto& f : psionicSpellView("psionic_spell_family"))
        if (lower.rfind(f, 0) == 0) return true;
    return false;
}
"""

PSI_ROLL_FN = """
DungeonEncounter rollPsionicEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2) {
    DungeonEncounter e;

    const std::vector<dm::EncounterPlanarRow>& t =
        planarView("psionic_table");

    for (int attempt = 0; attempt < 24; ++attempt) {
        const dm::EncounterPlanarRow* row = nullptr;
        for (const auto& r : t)
            if (pctile >= r.lo && pctile <= r.hi)
                { row = &r; break; }
        if (!row) return e;   // defensive: column covers 01-00

        std::string key = row->key;
        if      (key == "PSI_DEMON_MAJOR")   {
            const auto& v =
                planarSetView("demon_major_set");
            if (!v.empty())
                key = v[pctile2 % (int)v.size()];
        }
        else if (key == "PSI_DEMON_MINOR")   {
            const auto& v =
                planarSetView("demon_minor_set");
            if (!v.empty())
                key = v[pctile2 % (int)v.size()];
        }
        else if (key == "PSI_DEMON_PRINCE")  key = kPrinces[pctile2 % 4];
        else if (key == "PSI_DEVIL_ARCH")    key = kArchDevils[pctile2 % 4];
        else if (key == "PSI_DEVIL_GREATER") {
            const auto& v =
                planarSetView("devil_greater_set");
            if (!v.empty())
                key = v[pctile2 % (int)v.size()];
        }

        if (key == "PSI_MEN") {
            // (**) Character Subtable party - the R63
            // wilderness convention (not dungeon-level-tied)
            e.party = rollCharacterParty(dice, 8, 8);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            if (key == "yellow_mold") {
                // printed dash: numbers per MONSTER MANUAL
                // (registry noAppearing; 0/0 -> single patch)
                if (def->noAppearingMin > 0) {
                    int lo = def->noAppearingMin;
                    int hi = def->noAppearingMax < lo
                           ? lo : def->noAppearingMax;
                    e.count = (lo == hi)
                        ? lo
                        : lo + (int)dice.roll(
                              1, (uint32_t)(hi - lo + 1), 0) - 1;
                } else {
                    e.count = 1;
                }
            } else if (row->nMin == row->nMax) {
                e.count = row->nMin;
            } else {
                // printed Numbers column
                e.count = row->nMin + (int)dice.roll(
                    1, (uint32_t)(row->nMax - row->nMin + 1), 0)
                    - 1;
            }
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}
"""

PSI_KEYS_FN = """
// Every result key the table can produce - the regtest-style
// companion of rollPsionicEncounter.
std::vector<std::string> psionicEncounterKeys(
        const monsters::MonsterRegistry& reg) {
    std::vector<std::string> out;
    for (const auto& r : planarView("psionic_table")) {
        const std::string key = r.key;
        if      (key == "PSI_DEMON_MAJOR")
            for (const auto& k : planarSetView("demon_major_set"))
                pushUnique(out, k.c_str());
        else if (key == "PSI_DEMON_MINOR")
            for (const auto& k : planarSetView("demon_minor_set"))
                pushUnique(out, k.c_str());
        else if (key == "PSI_DEMON_PRINCE")
            for (const char* k : kPrinces) pushUnique(out, k);
        else if (key == "PSI_DEVIL_ARCH")
            for (const char* k : kArchDevils) pushUnique(out, k);
        else if (key == "PSI_DEVIL_GREATER")
            for (const auto& k : planarSetView("devil_greater_set"))
                pushUnique(out, k.c_str());
        else if (key == "PSI_MEN")
            pushUnique(out, "character_party");
        else if (reg.find(key))
            pushUnique(out, key.c_str());
    }
    return out;
}
"""


def seam_body(c66):
    # c66 (verbatim provenance) + seam note + the spells view,
    # then the spells fn, the roll fn and the keys fn. Blank
    # line between every block, one before the region-end sep.
    return (c66 + SEAM_NOTE + "\n" + SPELLS_FN
            + "\n" + PSI_ROLL_FN + "\n" + PSI_KEYS_FN + "\n")


# ---------------------------------------------------------------------------
# 6. the fragment (7 sections, derived pins)
# ---------------------------------------------------------------------------

def idx_of(table, key):
    for i, r in enumerate(table):
        if r[2] == key:
            return i
    die("pin index for %r not derivable" % key)


def build_fragment(table, exact, family):
    pin_keys = ["brain_mole", "PSI_DEMON_PRINCE", "PSI_MEN",
                "yellow_mold", "triton"]
    pins = []
    for k in pin_keys:
        i = idx_of(table, k)
        lo, hi, _, nMin, nMax = table[i]
        pins.append(
            "        { const int i = %d; const auto& r = rs[i];\n"
            "          if (r.lo != %d || r.hi != %d)\n"
            "              ++bad;\n"
            "          if (r.key != \"%s\") ++bad;\n"
            "          if (r.nMin != %d || r.nMax != %d)\n"
            "              ++bad;\n"
            "          if (r.primeOnly) ++bad; }\n"
            % (i, lo, hi, k, nMin, nMax))
    pins = "".join(pins)

    L = []
    A = L.append
    A("""// ============================================================================
// Adnd1 - rules/audits/r1037_psionic_encounter_registry.h  (R1037)
// The R66 psionic family battery audit, the R1032-R1036
// shape: the registry load, exact table counts, the percentile
// chain, row spot pins against the parsed R66 record, the
// printed spells lists, the key companion vs the table
// expansion, and the rollPsionicEncounter() path. Expected:
// 2 psionic files - the 19-row psionic table (band, key, the
// printed Numbers column, the shared planar row shape) and
// the spells file (20 exact names + 6 family prefixes) -
// all derived from the DMG record (Premium reprint p.182)
// the splice parsed. The demon/devil rows resolve through
// the R1036 pick-sets; kPrinces/kArchDevils stay
// engine-side (the R52 record); PSI_MEN resolves as a
// Character Subtable party (the R63 convention); the
// yellow mold dash falls back to the registry's
// noAppearing (the R60 convention).
// ============================================================================
{
""")
    A("    static const char* const kFragPrinces[4] = {\n")
    for p in PRINCES:
        A('        "%s",\n' % p)
    A("    };\n")
    A("    static const char* const kFragArchDevils[4] = {\n")
    for p in ARCH_DEVILS:
        A('        "%s",\n' % p)
    A("    };\n")
    A("""
    int bad = 0;
    dm::EncounterTableRegistry ereg;

    // -- 1. load: 2 psionic files, zero errors, one reg --
    bad = 0;
    {
        const int pf = ereg.loadDirectory(
            "content/tables/encounters_psionic");
        if (pf != 2) ++bad;
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
        if (!ereg.hasPlanar("psionic_table")) ++bad;
        // the spells file rides m_lists, not m_planar
        if (ereg.hasPlanar("psionic_spells")) ++bad;
        // negative pins (the R1034 dispatch-order lesson:
        // the exact keys stay exclusive on every side)
        if (ereg.hasPlanar("")) ++bad;
        if (ereg.hasPlanarBands("psionic_table")) ++bad;
        if (ereg.hasPlanarBands("")) ++bad;
        if (ereg.hasCityBands("psionic_table")) ++bad;
        if (ereg.hasWater("psionic_table")) ++bad;
        if (ereg.hasOutdoor("psionic_table")) ++bad;
        if (ereg.hasPlanar("planar_picks")) ++bad;
        // the spells lists and the R1036 pick-sets
        if ((int)ereg.list("psionic_spell_exact").size()
            != %d) ++bad;
        if ((int)ereg.list("psionic_spell_family").size()
            != %d) ++bad;
        if (!ereg.list("psionic_spell_exact").empty()
            && ereg.list("psionic_spell_exact")[0]
               != "astral spell") ++bad;
        if ((int)ereg.list("demon_minor_set").size() != 6)
            ++bad;
        if ((int)ereg.list("demon_major_set").size() != 10)
            ++bad;
        if ((int)ereg.list("devil_greater_set").size() != 3)
            ++bad;
    }
    printf("R1037 psionic encounter registry load audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 2. counts: the 19 rows, the printed columns ------
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
        if ((int)rs.size() != %d) ++bad;
        int lo = 1;
        for (const auto& r : rs) {
            if (r.lo != lo) ++bad;             // contiguous
            if (r.hi < r.lo || r.hi > 100) ++bad;
            if (r.nMin < 0 || r.nMax < r.nMin
                || r.nMax > 100) ++bad;
            if (r.primeOnly) ++bad;   // no (*) footnote here
            lo = r.hi + 1;
        }
        if (lo != 101) ++bad;                   // covers 01-00
    }
    printf("R1037 psionic encounter registry counts audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 3. chains: one row per percentile ---------------
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
        for (int pct = 1; pct <= 100; ++pct) {
            int hits = 0;
            for (const auto& r : rs)
                if (pct >= r.lo && pct <= r.hi) ++hits;
            if (hits != 1) ++bad;
        }
        // the printed Numbers column never exceeds the band
        for (const auto& r : rs) {
            if (r.nMin == 0 && r.nMax == 0) continue;
            if (r.nMin < 1) ++bad;
        }
    }
    printf("R1037 psionic encounter registry chains audit: bad %%d\\n", bad);
    if (bad) return 1;

    // -- 4. pins: spot pins derived from the parsed record -
    bad = 0;
    {
        const auto& rs = ereg.planarRows("psionic_table");
""" % (len(exact), len(family), len(table)))
    A(pins)
    A("""    }
    printf("R1037 psionic encounter registry pins audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 5. spells: the printed lists, case-insensitive ---
    bad = 0;
    {
        // exact positives (the case-insensitivity pin:
        // the battery feeds mixed case at the engine)
        if (!dm::spellResemblesPsionicPower("feather fall"))
            ++bad;
        if (!dm::spellResemblesPsionicPower(
                "FEATHER FALL")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "Temporal Stasis")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "astral spell")) ++bad;
        if (!dm::spellResemblesPsionicPower("esp"))
            ++bad;
        // family positives (the printed "(any)" leading
        // words)
        if (!dm::spellResemblesPsionicPower(
                "charm person")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "cure light wounds")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "detect magic")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "invisibility 10' radius")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "polymorph self")) ++bad;
        if (!dm::spellResemblesPsionicPower(
                "teleport")) ++bad;
        // negatives (near-misses and unrelated classics)
        if (dm::spellResemblesPsionicPower(
                "fireball")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "magic missile")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "lightning bolt")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "sleep")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "web")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "shield")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "healing")) ++bad;      // heal, not healing
        if (dm::spellResemblesPsionicPower(
                "curing")) ++bad;      // cure family needs
                                        // the full prefix
        if (dm::spellResemblesPsionicPower("")) ++bad;
        if (dm::spellResemblesPsionicPower(
                "feather")) ++bad;     // not the exact name
    }
    printf("R1037 psionic encounter registry spells audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 6. keys: the companion vs the expansion ----------
    bad = 0;
    {
        const auto got = dm::psionicEncounterKeys(reg);
        std::vector<std::string> want;
        auto pushU = [&](const std::string& k) {
            for (const auto& w : want)
                if (w == k) return;
            want.push_back(k);
        };
        const auto& rs = ereg.planarRows("psionic_table");
        for (const auto& r : rs) {
            const std::string& k = r.key;
            if      (k == "PSI_DEMON_MAJOR")
                for (const auto& x :
                     ereg.list("demon_major_set"))
                    pushU(x);
            else if (k == "PSI_DEMON_MINOR")
                for (const auto& x :
                     ereg.list("demon_minor_set"))
                    pushU(x);
            else if (k == "PSI_DEMON_PRINCE")
                for (const char* x : kFragPrinces)
                    pushU(x);
            else if (k == "PSI_DEVIL_ARCH")
                for (const char* x : kFragArchDevils)
                    pushU(x);
            else if (k == "PSI_DEVIL_GREATER")
                for (const auto& x :
                     ereg.list("devil_greater_set"))
                    pushU(x);
            else if (k == "PSI_MEN")
                pushU("character_party");
            else
                pushU(k);
        }
        // both directions, then the size pin (the derived
        // companion: 13 plain + 27 picks/princes/arch + party)
        if (got.size() != want.size()) ++bad;
        if ((int)got.size() != __COMPANION__) ++bad;
        for (const auto& k : got) {
            bool hit = false;
            for (const auto& w : want)
                if (k == w) { hit = true; break; }
            if (!hit) { ++bad; break; }
        }
        for (const auto& k : want) {
            bool hit = false;
            for (const auto& g : got)
                if (k == g) { hit = true; break; }
            if (!hit) { ++bad; break; }
        }
        auto has = [&](const char* k) {
            for (const auto& g : got)
                if (g == k) return true;
            return false;
        };
        // structural pins (grepped, never recalled)
        if (!has("character_party")) ++bad;
        if (!has("demogorgon")) ++bad;
        if (!has("asmodeus")) ++bad;
        if (!has("type_vi_demon_balor")) ++bad;
        if (!has("pit_fiend")) ++bad;
        if (!has("brain_mole")) ++bad;
        if (!has("triton")) ++bad;
        if (!has("yellow_mold")) ++bad;
        // no pseudo-key leaks into the companion
        for (const auto& g : got)
            if (g.compare(0, 4, "PSI_") == 0) ++bad;
    }
    printf("R1037 psionic encounter registry keys audit: bad %d\\n", bad);
    if (bad) return 1;

    // -- 7. roll: the psionic path, sweep + smoke ---------
    bad = 0;
    {
        rules::Rng rng(1037);
        rules::Dice dice(rng);
        // expanded key -> the printed numbers range (the
        // map is keyed by EXPANDED keys - the R1036 lesson)
        std::map<std::string, std::pair<int,int>> nums;
        {
            const auto& rs =
                ereg.planarRows("psionic_table");
            for (const auto& r : rs) {
                std::vector<std::string> kk;
                const std::string& k = r.key;
                if      (k == "PSI_DEMON_MAJOR")
                    kk = ereg.list("demon_major_set");
                else if (k == "PSI_DEMON_MINOR")
                    kk = ereg.list("demon_minor_set");
                else if (k == "PSI_DEMON_PRINCE")
                    for (const char* x : kFragPrinces)
                        kk.push_back(x);
                else if (k == "PSI_DEVIL_ARCH")
                    for (const char* x : kFragArchDevils)
                        kk.push_back(x);
                else if (k == "PSI_DEVIL_GREATER")
                    kk = ereg.list("devil_greater_set");
                else
                    kk.push_back(k);
                for (const auto& x : kk) {
                    if (x == "PSI_MEN"
                        || x == "yellow_mold") continue;
                    auto& p = nums[x];
                    if (r.nMax > p.second)
                        p = { r.nMin, r.nMax };
                }
            }
        }
        const auto companion = dm::psionicEncounterKeys(reg);
        auto inCompanion = [&](const std::string& k) {
            for (const auto& c : companion)
                if (c == k) return true;
            return false;
        };
        const monsters::MonsterDef* ym =
            reg.find("yellow_mold");
        for (int pct = 1; pct <= 100; ++pct) {
            const int p2 = 1 + (pct * 37) % 100;
            dm::DungeonEncounter e =
                dm::rollPsionicEncounter(reg, dice, pct, p2);
            if (e.key.empty()) { ++bad; continue; }
            if (!inCompanion(e.key)) ++bad;
            if (e.key == "character_party") {
                if (!e.isParty) ++bad;
                if ((int)e.party.members.size() != e.count)
                    ++bad;
            } else if (e.key == "yellow_mold") {
                if (e.isParty) ++bad;
                // the printed dash: the registry's
                // noAppearing (0/0 -> single patch)
                if (ym && ym->noAppearingMin > 0) {
                    const int lo = ym->noAppearingMin;
                    const int hi = ym->noAppearingMax < lo
                        ? lo : ym->noAppearingMax;
                    if (e.count < lo || e.count > hi)
                        ++bad;
                } else if (e.count != 1) ++bad;
            } else {
                if (e.isParty) ++bad;
                const auto it = nums.find(e.key);
                if (it == nums.end()) ++bad;
                else if (e.count < it->second.first
                      || e.count > it->second.second)
                    ++bad;
            }
        }
        // rng smoke: 4000 rolls, outcomes must be legal
        for (int i = 0; i < 4000; ++i) {
            dm::DungeonEncounter e = dm::rollPsionicEncounter(
                reg, dice, 1 + i % 100, 1 + (i * 53) % 100);
            if (e.key.empty()) { ++bad; continue; }
            if (e.key == "character_party") {
                if (!e.isParty) ++bad;
                if ((int)e.party.members.size() != e.count)
                    ++bad;
            } else if (e.key == "yellow_mold") {
                if (e.isParty) ++bad;
                if (e.count < 1) ++bad;
            } else {
                if (e.isParty) ++bad;
                if (e.count < 1) ++bad;
            }
        }
    }
    printf("R1037 psionic encounter registry roll audit: bad %d\\n", bad);
    if (bad) return 1;

}
""")
    text = "".join(L)
    text = text.replace("__COMPANION__", str(COMPANION))
    # the fragment's printf patterns are the census payload
    n = text.count("audit: bad %d")
    if n != 7:
        die("fragment carries %d census patterns (expected 7)"
            % n)
    return text


# ---------------------------------------------------------------------------
# 7. census + brace balance + main
# ---------------------------------------------------------------------------

CENSUS_PRE = 976
CENSUS_POST = 983


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
    if ("// tools/r1037_splice.py (psionic family)"
            in h):
        # already applied: verify the landing state
        with open(ENC, encoding="utf-8") as f:
            enc = f.read()
        if "kPsionicTable" in enc:
            die("already applied but kPsionicTable is "
                "still in dm/encounters.cpp")
        if census_count() != CENSUS_POST:
            die("already applied but census is %d "
                "(expected %d)"
                % (census_count(), CENSUS_POST))
        for name in ("psionic_table.lua",
                     "psionic_spells.lua"):
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
    i0, i1, table, exact, family, c66 = \
        parse_psionic_region(src)
    problems = gate_data(table)
    if problems:
        die("data gate: %s" % "; ".join(problems))
    picks = []
    for name, size in PICK_SETS:
        picks.append((name, size))
    # the python twin picks (member lists from the R1036
    # record - the fragment reads them from the registry)
    pick_members = {
        "demon_major": [
            "type_v_demon_aishapra",
            "type_v_demon_kevokulli",
            "type_v_demon_marilith",
            "type_v_demon_rehnaremme",
            "type_vi_demon_alzoll",
            "type_vi_demon_balor",
            "type_vi_demon_errtu",
            "type_vi_demon_ndulu",
            "type_vi_demon_tersath",
            "type_vi_demon_wendonai"],
        "demon_minor": [
            "type_i_vrock", "type_ii_hezrou",
            "type_iii_glabrezu", "type_iv_demon_bilwhr",
            "type_iv_demon_johud",
            "type_iv_demon_nalfeshnee"],
        "devil_greater": [
            "horned_devil", "ice_devil", "pit_fiend"],
    }
    for name, size in picks:
        if len(pick_members[name]) != size:
            die("pick-set %s: %d members (expected %d)"
                % (name, len(pick_members[name]), size))
    ncomp, nplain = simulate_roll_path(table,
                                       pick_members)
    print("parsed: %d psionic rows, spells %d exact + %d "
          "family" % (len(table), len(exact), len(family)))
    print("roll-path sim: pct sweeps clean, companion keys "
          "%d (%d plain)" % (ncomp, nplain))

    # -- lua + registry -------------------------------------
    emit_lua(table, exact, family)
    lua_roundtrip(table, exact, family)
    print("round-trip: 2 lua files parse back byte-exact")
    extend_registry()

    # -- the encounters.cpp seam ----------------------------
    new_enc = src[:i0] + seam_body(c66) + src[i1:]
    new_enc = replace_once(new_enc, ENC_LOAD_ANCHOR,
                           ENC_LOAD_NEW, "enc load anchor")
    for tok in RETIRED_TOKENS:
        if tok in new_enc:
            die("retired token %r survived the splice"
                % tok)
    with open(ENC, "w", encoding="utf-8") as f:
        f.write(new_enc)

    # -- the fragment + the regtest include ----------------
    frag = build_fragment(table, exact, family)
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
          "wrote 2 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
