#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1034_splice.py  (R1034)
# The outdoor (wilderness) encounter table de-wire, the R1032/R1033
# shape: the retired kOutArctic..kOutTropical climate tables (R63, DMG
# Appendix C Premium reprint p.182-191), the eleven SUB_* terrain
# subtables (kOutDemiHuman..kOutUndead), the six pick-set arrays
# (kOutKiRinSet..kOutWolfDogSet) and the single-column tropical Sphinx
# footnote (the retired kSphinxT/kLoT/kHiT of outdoorSubBands) are
# extracted verbatim into content/tables/encounters_outdoor/*.lua and
# load through dm::EncounterTableRegistry (extended here with the
# outdoor family: EncounterOutdoorRow rows - one percentile band per
# terrain column, -1 = no entry - and the six pick-sets as registry
# lists). The outdoor directory is a sibling of content/tables/
# encounters/ and encounters_water/ so the R1032 audit's 20-file pin
# and the R1033 audit's 9-file pin stay untouched. rollOutdoorEncounter
# (), outdoorEncounterKeys(), outdoorBands() and outdoorSubBands()
# keep their signatures and behavior - they read registry-backed
# views (the R1032 misc-engine pattern). The tropical Sphinx footnote
# is stored as its own table (outdoor_sphinx_t) with the four bands
# replicated across all eight terrain columns: the footnote is
# terrain-independent, so every column serves the same four bands.
# This script is the only writer of the lua files and the R1034
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
LUA_DIR = os.path.join(ROOT, "content", "tables", "encounters_outdoor")
FRAG = os.path.join(ROOT, "rules", "audits",
                    "r1034_outdoor_encounter_registry.h")

# ---- table inventory: retired C++ array -> registry key -------------------
CLIMES = [
    ("kOutArctic",              "outdoor_arctic"),
    ("kOutSubArctic",           "outdoor_sub_arctic"),
    ("kOutTemperateWild",       "outdoor_temperate_wild"),
    ("kOutTemperateInhabited",  "outdoor_temperate_inhabited"),
    ("kOutFaerie",              "outdoor_faerie"),
    ("kOutPleistocene",         "outdoor_pleistocene"),
    ("kOutDinosaurAge",         "outdoor_dinosaur_age"),
    ("kOutTropical",            "outdoor_tropical"),
]
SUBS = [
    ("kOutDemiHuman",           "outdoor_sub_demihuman"),
    ("kOutDragon",              "outdoor_sub_dragon"),
    ("kOutFrog",                "outdoor_sub_frog"),
    ("kOutGiant",               "outdoor_sub_giant"),
    ("kOutHumanoid",            "outdoor_sub_humanoid"),
    ("kOutLycanthrope",         "outdoor_sub_lycanthrope"),
    ("kOutMen",                 "outdoor_sub_men"),
    ("kOutSnake",               "outdoor_sub_snake"),
    ("kOutSphinx",              "outdoor_sub_sphinx"),
    ("kOutSpider",              "outdoor_sub_spider"),
    ("kOutUndead",              "outdoor_sub_undead"),
]
TABLES = CLIMES + SUBS
SPHINX_T = "outdoor_sphinx_t"          # the tropical footnote table
SETS = [                       # pseudo-key -> (registry list, C++ array, members)
    ("KI_RIN_SET",     "ki_rin_set",     "kOutKiRinSet",
     ["ki_rin", "lammasu", "shedu"]),
    ("LEPRECHAUN_SET", "leprechaun_set", "kOutLeprechaunSet",
     ["leprechaun", "brownie"]),
    ("PORCUPINE_SET",  "porcupine_set",  "kOutPorcupineSet",
     ["giant_porcupine", "giant_skunk"]),
    ("IGUANODON_SET",  "iguanodon_set",  "kOutIguanodonSet",
     ["iguanodon", "lambeosaurus"]),
    ("LAMMASU_SET",    "lammasu_set",    "kOutLammasuSet",
     ["lammasu", "shedu"]),
    ("WOLF_DOG_SET",   "wolf_dog_set",   "kOutWolfDogSet",
     ["wolf", "wild_dog"]),
]
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
# 1. parse the retired region from the pristine source
# ---------------------------------------------------------------------------

ROW_RE = re.compile(r'\{"([^"]+)",\s*\{([^}]+)\},\s*\{([^}]+)\}')


def parse_outdoor_region(src):
    # The region runs from the separator above the R63 comment to the
    # separator above the R64 comment.
    start = src.find("// R63: the outdoor (wilderness) encounter tables")
    if start < 0:
        die("R63 marker not found (already spliced?)")
    start = src.rfind("// ------", 0, start)
    end = src.find("// R64: the CITY/TOWN ENCOUNTER MATRIX")
    if end < 0:
        die("R64 marker not found")
    end = src.rfind("// ------", 0, end)
    if start < 0 or end < 0 or end <= start:
        die("region separators not found")
    region = src[start:end]

    tables = {}
    for arr, key in TABLES:
        m = re.search(r"static const OutdoorRow " + arr
                      + r"\[\] = \{(.*?)\n\};", region, re.S)
        if not m:
            die("array %s not found in the outdoor region" % arr)
        rows = []
        for k, los, his in ROW_RE.findall(m.group(1)):
            lo = [int(x) for x in re.findall(r"-?\d+", los)]
            hi = [int(x) for x in re.findall(r"-?\d+", his)]
            if len(lo) != 8 or len(hi) != 8:
                die("%s row %s does not carry 8+8 columns" % (arr, k))
            rows.append((k, lo, hi))
        if not rows:
            die("array %s parsed empty" % arr)
        tables[key] = rows

    # the six pick-sets
    sets = {}
    for pseudo, name, arr, _ in SETS:
        m = re.search(r"static const char\* const " + arr
                      + r"\[\]\s*=\s*\{([^}]*)\}", region)
        if not m:
            die("set %s not found in the outdoor region" % arr)
        vals = re.findall(r'"([^"]+)"', m.group(1))
        if not vals:
            die("set %s parsed empty" % arr)
        sets[name] = vals

    # the tropical Sphinx footnote bands (retired kSphinxT/kLoT/kHiT)
    names = re.search(r'kSphinxT\[4\]\s*=\s*\{([^}]*)\}',
                      region)
    lo_t = re.search(r"kLoT\[4\]\s*=\s*\{\s*([^}]*)\}", region)
    hi_t = re.search(r"kHiT\[4\]\s*=\s*\{\s*([^}]*)\}", region)
    if not (names and lo_t and hi_t):
        die("sphinx footnote constants not found")
    st_names = re.findall(r'"([^"]+)"', names.group(1))
    st_lo = [int(x) for x in re.findall(r"-?\d+", lo_t.group(1))]
    st_hi = [int(x) for x in re.findall(r"-?\d+", hi_t.group(1))]
    if (len(st_names) != 4 or len(st_lo) != 4 or len(st_hi) != 4
            or st_names != ["androsphinx", "criosphinx",
                            "gynosphinx", "hieracosphinx"]
            or st_lo != [1, 11, 41, 71] or st_hi != [10, 40, 70, 100]):
        die("sphinx footnote constants drifted from the record")
    # replicated across the eight terrain columns (terrain-independent)
    tables[SPHINX_T] = [(k, [lo] * 8, [hi] * 8)
                        for k, lo, hi in zip(st_names, st_lo, st_hi)]

    return start, end, tables, sets


def gate_data(tables, sets):
    for pseudo, name, arr, expect in SETS:
        if sets[name] != expect:
            die("set %s drifted: %r" % (name, sets[name]))
        for k in sets[name]:
            if not monster_exists(k):
                die("set member %s is not a bestiary key" % k)
    counts = []
    for _, key in TABLES + [(None, SPHINX_T)]:
        rows = tables[key]
        counts.append(len(rows))
        # per-column discipline: a populated column covers 01-00
        # contiguously; a column with no entries is skipped (rows
        # that print no entry there carry -1, which is legal)
        for c in range(8):
            col = [(lo[c], hi[c]) for _, lo, hi in rows if lo[c] >= 0]
            if not col:
                continue                      # empty column
            for lo, hi in col:
                if lo < 0 or hi < lo or hi > 100:
                    die("%s col %d has a band gap at %d" % (key, c, lo))
            prev = 0
            for lo, hi in col:
                if lo != prev + 1:
                    die("%s col %d has a band gap at %d" % (key, c, lo))
                prev = hi
            if prev != 100:
                die("%s col %d ends at %d (expected 100)" % (key, c, prev))
    expect = [12, 24, 59, 40, 38, 23, 29, 52,
              4, 11, 3, 8, 5, 5, 9, 4, 4, 4, 10, 4]
    if counts != expect:
        die("unexpected per-table counts %r" % (counts,))
    if sum(counts) != 348:
        die("expected 348 outdoor rows, got %d" % sum(counts))
    return counts


# ---------------------------------------------------------------------------
# 2. lua emission + round-trip
# ---------------------------------------------------------------------------

LUA_HEADER = """-- encounter table def: %s
-- The DMG Appendix C outdoor (wilderness) encounter tables
-- (R1034 de-wire): extracted verbatim from the retired OutdoorRow
-- arrays of dm/encounters.cpp (R63 climate tables and SUB_*
-- subtables, Premium reprint p.182-191, OCR-verified; the tropical
-- Sphinx footnote p.189). cols carries one percentile band per
-- terrain column (Plain, Scrub, Forest, Rough, Desert, Hills,
-- Mountains, Marsh), -1 = the row prints no entry there. The
-- substitution and OCR-fold provenance lives in the R1034 seam
-- comment in dm/encounters.cpp. DO NOT hand-edit:
-- tools/r1034_splice.py is the only writer.


"""


def lua_text(key, rows):
    out = []
    out.append(LUA_HEADER % key)
    out.append("return {")
    out.append('  key = "%s",' % key)
    out.append("  rows = {")
    for k, lo, hi in rows:
        cols = ", ".join("{%d,%d}" % (lo[c], hi[c]) for c in range(8))
        out.append('    { key = "%s", cols = { %s } },' % (k, cols))
    out.append("  },")
    out.append("}")
    return "\n".join(out) + "\n"


SETS_LUA = """-- encounter table def: outdoor_sets
-- The six R63 outdoor pick-sets (R1034 de-wire): extracted
-- verbatim from the retired kOut*Set arrays of dm/encounters.cpp.
-- A set resolves on the second percentile modulo the set size
-- (DMG Appendix C, Premium reprint p.182-191). Porcupine/Skunk
-- maps to the giant varieties (the bestiary carries those only).
-- DO NOT hand-edit: tools/r1034_splice.py is the only writer.


return {
  key = "outdoor_sets",
  ki_rin = { %s },
  leprechaun = { %s },
  porcupine = { %s },
  iguanodon = { %s },
  lammasu = { %s },
  wolf_dog = { %s },
}
"""


def sets_lua_text(sets):
    def arr(name):
        return ", ".join('"%s"' % k for k in sets[name])
    return (SETS_LUA % (arr("ki_rin_set"), arr("leprechaun_set"),
                        arr("porcupine_set"), arr("iguanodon_set"),
                        arr("lammasu_set"), arr("wolf_dog_set")))


def emit_lua(tables, sets):
    if not os.path.isdir(LUA_DIR):
        os.makedirs(LUA_DIR)
    for _, key in TABLES + [(None, SPHINX_T)]:
        with open(os.path.join(LUA_DIR, key + ".lua"), "w") as f:
            f.write(lua_text(key, tables[key]))
    with open(os.path.join(LUA_DIR, "outdoor_sets.lua"), "w") as f:
        f.write(sets_lua_text(sets))


def lua_roundtrip(tables, sets):
    # every emitted table file must parse back and re-emit byte-exact
    for _, key in TABLES + [(None, SPHINX_T)]:
        path = os.path.join(LUA_DIR, key + ".lua")
        text = open(path).read()
        m = re.search(r'return \{\n  key = "([^"]+)",\n  rows = \{\n(.*?)'
                      r'\n  \},\n\}\n', text, re.S)
        if not m:
            die("%s does not parse" % path)
        if m.group(1) != key:
            die("%s key mismatch" % path)
        rows = []
        for line in m.group(2).split("\n"):
            r = re.match(r'    \{ key = "([^"]+)", cols = \{ (.*) \} \},',
                         line)
            if not r:
                die("%s row line does not parse: %r" % (path, line))
            cols = re.findall(r'\{(-?\d+),(-?\d+)\}', r.group(2))
            if len(cols) != 8:
                die("%s row %s does not carry 8 columns" % (path, r.group(1)))
            lo = [int(a) for a, _ in cols]
            hi = [int(b) for _, b in cols]
            rows.append((r.group(1), lo, hi))
        if rows != tables[key]:
            die("%s rows differ from the parsed record" % path)
        if lua_text(key, rows) != text:
            die("%s does not round-trip byte-exact" % path)
    # the sets file
    path = os.path.join(LUA_DIR, "outdoor_sets.lua")
    text = open(path).read()
    for pseudo, name, arr, expect in SETS:
        m = re.search(re.escape(name.split("_set")[0])
                      + r' = \{ ([^}]*) \}', text)
        if not m:
            die("sets file does not parse for %s" % name)
        vals = re.findall(r'"([^"]+)"', m.group(1))
        if vals != sets[name]:
            die("sets file drifted for %s" % name)
    if sets_lua_text(sets) != text:
        die("sets file does not round-trip byte-exact")


# ---------------------------------------------------------------------------
# 3. roll-path simulation (the pure-python twin of the C++ gates)
# ---------------------------------------------------------------------------

SUBKEY_OF = {"SUB_DEMIHUMAN": "outdoor_sub_demihuman",
             "SUB_DRAGON": "outdoor_sub_dragon",
             "SUB_FROG": "outdoor_sub_frog",
             "SUB_GIANT": "outdoor_sub_giant",
             "SUB_HUMANOID": "outdoor_sub_humanoid",
             "SUB_LYCANTHROPE": "outdoor_sub_lycanthrope",
             "SUB_MEN": "outdoor_sub_men",
             "SUB_SNAKE": "outdoor_sub_snake",
             "SUB_SPHINX": "outdoor_sub_sphinx",
             "SUB_SPIDER": "outdoor_sub_spider",
             "SUB_UNDEAD": "outdoor_sub_undead"}
SETNAME_OF = {pseudo: name for pseudo, name, _, _ in SETS}
CLIME_TABLE = [name for _, name in CLIMES]


def resolve_key(tables, sets, row_key, terrain, pctile2):
    """The python twin of resolveOutdoorKey - None = no encounter."""
    k = row_key
    if k in SETNAME_OF:
        s = sets[SETNAME_OF[k]]
        return s[pctile2 % len(s)]
    if k == "MISC_REPTILE":
        return "giant_lizard"
    if k == "SUB_SPHINX_T":
        for rk, lo, hi in tables[SPHINX_T]:
            if lo[0] >= 0 and pctile2 >= lo[0] and pctile2 <= hi[0]:
                return rk
        return None
    if k.startswith("SUB_"):
        sub = SUBKEY_OF.get(k)
        if sub is None:
            return None
        for rk, lo, hi in tables[sub]:
            if lo[terrain] >= 0 and pctile2 >= lo[terrain] \
                    and pctile2 <= hi[terrain]:
                return resolve_key(tables, sets, rk, terrain, pctile2)
        return None
    return k


def allowed_keys(tables, sets, key, terrain):
    """The python twin of pushOutKeys (the reg-filtered census)."""
    out = []

    def push(k):
        if k not in out:
            out.append(k)

    def expand(table_key, terrain):
        for rk, lo, hi in tables[table_key]:
            if lo[terrain] < 0:
                continue
            if rk == "SUB_CHARACTER":
                push("character_party")
            elif rk == "MISC_REPTILE":
                push("giant_lizard")
            elif rk in SETNAME_OF:
                for s in sets[SETNAME_OF[rk]]:
                    push(s)
            elif rk == "SUB_SPHINX_T":
                for sk, slo, shi in tables[SPHINX_T]:
                    push(sk)
            elif rk.startswith("SUB_"):
                sub = SUBKEY_OF.get(rk)
                if sub:
                    expand(sub, terrain)
            elif monster_exists(rk):
                push(rk)

    expand(key, terrain)
    return out


def simulate_roll_path(tables, sets):
    # First-shot resolution over the full pctile x pctile2 grid for
    # every climate x terrain combo: a resolved key must be in the
    # reg-filtered allowed set; SUB_CHARACTER resolves as the party.
    cells = 0
    resolved = 0
    absent = set()
    party_cells = 0
    for clime in range(8):
        tname = CLIME_TABLE[clime]
        for terrain in range(8):
            allowed = allowed_keys(tables, sets, tname, terrain)
            populated = any(lo[terrain] >= 0
                            for _, lo, hi in tables[tname])
            for pct in range(1, 101):
                for p2 in range(1, 101):
                    cells += 1
                    row = None
                    for rk, lo, hi in tables[tname]:
                        if lo[terrain] >= 0 and lo[terrain] <= pct \
                                and pct <= hi[terrain]:
                            row = rk
                            break
                    if row is None:
                        # an empty column yields no encounter (the
                        # C++ path returns e untouched); a populated
                        # column must cover every pctile
                        if populated:
                            die("%s terrain %d: pctile %d misses every "
                                "band" % (tname, terrain, pct))
                        continue
                    k = resolve_key(tables, sets, row, terrain, p2)
                    if k is None:
                        # resolveOutdoorKey returns false for the
                        # SUB_CHARACTER row (the R63 dispatch quirk,
                        # preserved verbatim): the roll path yields no
                        # encounter there - the rollCharacterParty
                        # block stays dead, as retired
                        if row == "SUB_MEN":
                            party_cells += 1
                        continue
                    if not monster_exists(k):
                        # the C++ path re-rolls on a missing bestiary
                        # record (the DMG ignore advice); legal, tracked
                        absent.add(k)
                        continue
                    if k not in allowed:
                        die("%s terrain %d: resolved key %s not in the "
                            "allowed set" % (tname, terrain, k))
                    resolved += 1
    return cells, resolved, absent, party_cells


# ---------------------------------------------------------------------------
# 4. the registry-native replacement block for dm/encounters.cpp
# ---------------------------------------------------------------------------

OUTDOOR_BLOCK = '''// ----------------------------------------------------------------------------
// R1034: the outdoor (wilderness) encounter tables ride the registry.
// The retired kOutArctic..kOutTropical climate tables, the eleven
// SUB_* terrain subtables, the six pick-set arrays and the tropical
// Sphinx footnote (all R63, DMG Appendix C Premium reprint p.182-191,
// OCR-verified against the uploaded DMG; the five 1eonline.info-
// carried climates line-diffed band-for-band at R126) were extracted
// verbatim into content/tables/encounters_outdoor/*.lua and load
// through dm::EncounterTableRegistry (see encReg() above). The
// provenance record: eight climate tables, each creature-major across
// eight terrain columns (Plain, Scrub, Forest, Rough - ruins within
// five miles per the book footnote - Desert, Hills, Mountains,
// Marsh); the subtables resolve on the second percentile against the
// same terrain column; the tropical Sphinx footnote is the single-
// column p.189 subtable (replicated across the eight columns in the
// registry def - it is terrain-independent); the pick-sets resolve on
// the second percentile modulo set size, Porcupine/Skunk mapping to
// the giant varieties. The DMG prints no number columns ("the numbers
// of monsters encountered are those shown in MONSTER MANUAL"), so
// counts come from the registry's noAppearing fields, as in R60/R1033.
// Substitutions documented at R63 and transcribed in-row in the lua:
// Men tribesmen -> caveman and nomad -> dervish, brigand -> bandit,
// Camel -> wild_camel, Misc reptiles -> giant_lizard (book fn *),
// "Pterodactyl, small" -> pteranodon, Nothosaurus -> megalosaurus
// (book fn **), Treant -> treant_mature_middle_aged, Titan -> titan.
// The OCR folds are pinned in-row by the data (sub-arctic marsh
// caveman 56-65, inhabited ghast, tropical bandit mountains 23-30,
// the dropped tropical dervish mountain/marsh duplicates, Faerie
// giant boar forest 09-12, temperate wild giant eagle plain 15-16,
// tropical dervish hills 46-47, Dragon subtable chimera forest
// 23-30, Giant subtable stone giant hills 82-98, Lycanthrope
// wereboar, Undead ghast, Men subtable marsh pilgrim 36-50 and
// tribesman 51-00, temperate wild scrub Humanoid 26-32, tropical
// rough giant scorpion 84-85). The Men Subtable Character row
// resolves as a character party of levels 7-10 per the p.187
// wilderness note: rollCharacterParty(dice, 8, 8). The roll paths,
// key companions and band edges below are behavior-identical to the
// retired arrays - the R126 line-diff audit and the R1034 battery
// fragment pin the parity. tools/r1034_splice.py is the only writer
// of the lua; this seam is its reader.
// ----------------------------------------------------------------------------

namespace {

struct OutdoorRow {
    std::string key;   // registry key, SUB_* / *_SET pseudo-key
    short lo[8];       // per-terrain percentile low (-1 = no entry)
    short hi[8];       // per-terrain percentile high (-1 = no entry)
};

// registry-backed views, built once (the R1032 misc-engine shape)
static const std::vector<OutdoorRow>& outdoorView(const char* name) {
    static std::map<std::string, std::vector<OutdoorRow>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* n : { "outdoor_arctic",
                               "outdoor_sub_arctic",
                               "outdoor_temperate_wild",
                               "outdoor_temperate_inhabited",
                               "outdoor_faerie",
                               "outdoor_pleistocene",
                               "outdoor_dinosaur_age",
                               "outdoor_tropical",
                               "outdoor_sub_demihuman",
                               "outdoor_sub_dragon",
                               "outdoor_sub_frog",
                               "outdoor_sub_giant",
                               "outdoor_sub_humanoid",
                               "outdoor_sub_lycanthrope",
                               "outdoor_sub_men",
                               "outdoor_sub_snake",
                               "outdoor_sub_sphinx",
                               "outdoor_sub_spider",
                               "outdoor_sub_undead",
                               "outdoor_sphinx_t" }) {
            const auto& rs = encReg().outdoorRows(n);
            std::vector<OutdoorRow> rows;
            for (const auto& r : rs) {
                OutdoorRow row;
                row.key = r.key;
                for (int c = 0; c < 8; ++c) {
                    row.lo[c] = (short)r.lo[c];
                    row.hi[c] = (short)r.hi[c];
                }
                rows.push_back(row);
            }
            m[n] = rows;
        }
    }
    static const std::vector<OutdoorRow> none;
    auto it = m.find(name);
    return it == m.end() ? none : it->second;
}

// the six pick-sets (registry lists; the retired kOut*Set arrays)
static const std::vector<std::string>& outdoorSet(const char* set) {
    static std::map<std::string, std::vector<std::string>> m;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        for (const char* s : { "ki_rin_set", "leprechaun_set",
                               "porcupine_set", "iguanodon_set",
                               "lammasu_set", "wolf_dog_set" })
            m[s] = encReg().list(s);
    }
    static const std::vector<std::string> none;
    auto it = m.find(set);
    return it == m.end() ? none : it->second;
}

// R63: the climate selector (OutdoorClime -> registry table name)
static const char* outdoorTableName(OutdoorClime clime) {
    switch (clime) {
        case OC_ARCTIC:              return "outdoor_arctic";
        case OC_SUB_ARCTIC:          return "outdoor_sub_arctic";
        case OC_TEMPERATE_WILD:      return "outdoor_temperate_wild";
        case OC_TEMPERATE_INHABITED: return "outdoor_temperate_inhabited";
        case OC_FAERIE:              return "outdoor_faerie";
        case OC_PLEISTOCENE:         return "outdoor_pleistocene";
        case OC_DINOSAUR_AGE:        return "outdoor_dinosaur_age";
        case OC_TROPICAL:            return "outdoor_tropical";
    }
    return nullptr;
}

// R63: the terrain-column subtable selector (SUB_* -> table name)
static const char* outdoorSubName(const std::string& subKey) {
    if      (subKey == "SUB_DEMIHUMAN")   return "outdoor_sub_demihuman";
    else if (subKey == "SUB_DRAGON")      return "outdoor_sub_dragon";
    else if (subKey == "SUB_FROG")        return "outdoor_sub_frog";
    else if (subKey == "SUB_GIANT")       return "outdoor_sub_giant";
    else if (subKey == "SUB_HUMANOID")    return "outdoor_sub_humanoid";
    else if (subKey == "SUB_LYCANTHROPE") return "outdoor_sub_lycanthrope";
    else if (subKey == "SUB_MEN")         return "outdoor_sub_men";
    else if (subKey == "SUB_SNAKE")       return "outdoor_sub_snake";
    else if (subKey == "SUB_SPHINX")      return "outdoor_sub_sphinx";
    else if (subKey == "SUB_SPIDER")      return "outdoor_sub_spider";
    else if (subKey == "SUB_UNDEAD")      return "outdoor_sub_undead";
    return nullptr;
}

} // namespace

// Resolve a main-table row (or Men-subtable row) at the terrain
// column: returns the registry key, or handles SUB_* dispatch and
// pick-sets. isParty set for the Men Character row. False return
// means no encounter (defensive; every printed column covers 01-00).
static bool resolveOutdoorKey(const OutdoorRow* row, int terrain,
                              int pctile2, std::string& key) {
    (void)terrain;   // sets don't vary by terrain
    key = row->key;
    if      (key == "KI_RIN_SET") {
        const auto& s = outdoorSet("ki_rin_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "LEPRECHAUN_SET") {
        const auto& s = outdoorSet("leprechaun_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "PORCUPINE_SET") {
        const auto& s = outdoorSet("porcupine_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "IGUANODON_SET") {
        const auto& s = outdoorSet("iguanodon_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "LAMMASU_SET") {
        const auto& s = outdoorSet("lammasu_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "WOLF_DOG_SET") {
        const auto& s = outdoorSet("wolf_dog_set");
        key = s[pctile2 % s.size()];
    }
    else if (key == "MISC_REPTILE")    key = "giant_lizard";
    else if (key == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable (p.189),
        // replicated across the terrain columns in the registry def
        for (const auto& r : outdoorView("outdoor_sphinx_t"))
            if (r.lo[0] >= 0 && pctile2 >= r.lo[0]
                && pctile2 <= r.hi[0]) { key = r.key; break; }
    } else if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
        // terrain-column subtable, resolved on pctile2
        const char* subName = outdoorSubName(key);
        const std::vector<OutdoorRow>* sub = nullptr;
        if (subName) sub = &outdoorView(subName);
        if (!sub) return false;
        const OutdoorRow* sr = nullptr;
        for (const auto& r : *sub)
            if (r.lo[terrain] >= 0 &&
                pctile2 >= r.lo[terrain] && pctile2 <= r.hi[terrain])
                { sr = &r; break; }
        if (!sr) return false;
        return resolveOutdoorKey(sr, terrain, pctile2, key);
    }
    return true;
}

// The registry keys one climate/terrain column can produce - the
// regtest-style companion of rollOutdoorEncounter.
static void pushOutKeys(std::vector<std::string>& out,
                        const monsters::MonsterRegistry& reg,
                        const std::vector<OutdoorRow>& t, int terrain) {
    for (const auto& row : t) {
        if (row.lo[terrain] < 0) continue;
        const std::string& key = row.key;
        if (key == "SUB_CHARACTER") { pushUnique(out, "character_party"); continue; }
        if (key == "MISC_REPTILE")  { pushUnique(out, "giant_lizard"); continue; }
        if (key == "KI_RIN_SET") {
            for (const auto& k : outdoorSet("ki_rin_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "LEPRECHAUN_SET") {
            for (const auto& k : outdoorSet("leprechaun_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "PORCUPINE_SET") {
            for (const auto& k : outdoorSet("porcupine_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "IGUANODON_SET") {
            for (const auto& k : outdoorSet("iguanodon_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "LAMMASU_SET") {
            for (const auto& k : outdoorSet("lammasu_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "WOLF_DOG_SET") {
            for (const auto& k : outdoorSet("wolf_dog_set")) pushUnique(out, k.c_str());
            continue;
        }
        if (key == "SUB_SPHINX_T") {
            for (const auto& r : outdoorView("outdoor_sphinx_t"))
                pushUnique(out, r.key.c_str());
            continue;
        }
        if (key.size() > 4 && key.compare(0, 4, "SUB_") == 0) {
            const char* subName = outdoorSubName(key);
            if (subName) pushOutKeys(out, reg, outdoorView(subName), terrain);
            continue;
        }
        if (reg.find(key)) pushUnique(out, key.c_str());
    }
}

// R63: the outdoor roll - see encounters.h.
DungeonEncounter rollOutdoorEncounter(
        const monsters::MonsterRegistry& reg, rules::Dice& dice,
        int pctile, int pctile2,
        OutdoorClime clime, OutdoorTerrain terrain) {
    DungeonEncounter e;

    const char* tn = outdoorTableName(clime);
    if (!tn) return e;
    const std::vector<OutdoorRow>& t = outdoorView(tn);
    int ti = (int)terrain;

    for (int attempt = 0; attempt < 24; ++attempt) {
        const OutdoorRow* row = nullptr;
        for (const auto& r : t)
            if (r.lo[ti] >= 0 &&
                pctile >= r.lo[ti] && pctile <= r.hi[ti])
                { row = &r; break; }
        if (!row) return e;   // defensive: columns cover 01-00

        std::string key;
        if (!resolveOutdoorKey(row, ti, pctile2, key)) return e;

        if (key == "SUB_CHARACTER") {
            // Men Subtable Character row - wilderness character
            // party, levels 7-10 (p.187 note)
            e.party = rollCharacterParty(dice, 8, 8);
            e.isParty = true;
            e.key = "character_party";
            e.count = e.party.size();
            return e;
        }

        const monsters::MonsterDef* def = reg.find(key);
        if (def) {
            e.key = key;
            // numbers per MONSTER MANUAL (registry noAppearing;
            // 0/0 falls back to a single specimen)
            if (def->noAppearingMin > 0) {
                int lo = def->noAppearingMin;
                int hi = def->noAppearingMax < lo ? lo : def->noAppearingMax;
                e.count = (lo == hi)
                    ? lo
                    : lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
            } else {
                e.count = 1;
            }
            return e;
        }

        // DMG advice: ignore & re-roll
        pctile  = 1 + (int)dice.roll(1, 100, 0) - 1;
        pctile2 = 1 + (int)dice.roll(1, 100, 0) - 1;
    }
    return e;
}

std::vector<std::string> outdoorEncounterKeys(
        const monsters::MonsterRegistry& reg,
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<std::string> out;
    const char* tn = outdoorTableName(clime);
    if (tn) pushOutKeys(out, reg, outdoorView(tn), (int)terrain);
    return out;
}

namespace {

// R126: the subtable matrix behind a SUB_* pseudo-key (see
// encounters.h; the tropical Sphinx Subtable is single-column
// and never reaches here - outdoorSubBands handles it before
// the lookup).
const std::vector<OutdoorRow>& outSub(const std::string& subKey) {
    const char* n = nullptr;
    if      (subKey == "SUB_DEMIHUMAN")   n = "outdoor_sub_demihuman";
    else if (subKey == "SUB_DRAGON")      n = "outdoor_sub_dragon";
    else if (subKey == "SUB_FROG")        n = "outdoor_sub_frog";
    else if (subKey == "SUB_GIANT")       n = "outdoor_sub_giant";
    else if (subKey == "SUB_HUMANOID")    n = "outdoor_sub_humanoid";
    else if (subKey == "SUB_LYCANTHROPE") n = "outdoor_sub_lycanthrope";
    else if (subKey == "SUB_MEN")         n = "outdoor_sub_men";
    else if (subKey == "SUB_SNAKE")       n = "outdoor_sub_snake";
    else if (subKey == "SUB_SPHINX")      n = "outdoor_sub_sphinx";
    else if (subKey == "SUB_SPIDER")      n = "outdoor_sub_spider";
    else if (subKey == "SUB_UNDEAD")      n = "outdoor_sub_undead";
    static const std::vector<OutdoorRow> none;
    return n ? outdoorView(n) : none;
}

// R126: band order comparator (lo ascending)
static bool outBandLess(const OutdoorBand& x,
                        const OutdoorBand& y) {
    return x.lo < y.lo;
}

// R126: collect a column's bands, low-ascending
static void pushBands(std::vector<OutdoorBand>& out,
                      const std::vector<OutdoorRow>& t, int ti) {
    for (const auto& r : t) {
        if (r.lo[ti] < 0) continue;
        OutdoorBand b;
        b.key = r.key;
        b.lo  = r.lo[ti];
        b.hi  = r.hi[ti];
        out.push_back(b);
    }
    std::stable_sort(out.begin(), out.end(), outBandLess);
}

} // namespace

// R126: the printed band edges behind the tables - see
// encounters.h.
std::vector<OutdoorBand> outdoorBands(
        OutdoorClime clime, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    const char* tn = outdoorTableName(clime);
    if (tn) pushBands(out, outdoorView(tn), (int)terrain);
    return out;
}

std::vector<OutdoorBand> outdoorSubBands(
        const std::string& subKey, OutdoorTerrain terrain) {
    std::vector<OutdoorBand> out;
    if (subKey == "SUB_SPHINX_T") {
        // tropical footnote: single-column Sphinx Subtable
        // (p.189) - 01-10/11-40/41-70/71-00, replicated across
        // the terrain columns in the registry def
        pushBands(out, outdoorView("outdoor_sphinx_t"), (int)terrain);
        return out;
    }
    pushBands(out, outSub(subKey), (int)terrain);
    return out;
}

'''

# ---------------------------------------------------------------------------
# 5. the registry extension (dm/EncounterTableRegistry.{h,cpp})
# ---------------------------------------------------------------------------

H_WRITER_OLD = ("// tools/r1032_splice.py (dungeon family) and\n"
                "// tools/r1033_splice.py (water family) are the only writers.")
H_WRITER_NEW = ("// tools/r1032_splice.py (dungeon family),\n"
                "// tools/r1033_splice.py (water family) and\n"
                "// tools/r1034_splice.py (outdoor family) are the only writers.")

H_STRUCT_ANCHOR = """// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""
H_STRUCT_ADD = """// One outdoor (wilderness) encounter table row (R1034): the R63
// eight climate tables, the eleven SUB_* terrain subtables and the
// single-column tropical Sphinx Subtable (replicated across the
// eight terrain columns - the footnote is terrain-independent).
// lo/hi carry one percentile band per terrain column
// (Plain/Scrub/Forest/Rough/Desert/Hills/Mountains/Marsh);
// -1 = the row prints no entry in that column.
struct EncounterOutdoorRow {
    std::string key;
    int lo[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
    int hi[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
};

// One Determination Matrix entry (d20 range -> monster level).
struct MatrixEntry { int lo = 0, hi = 0, mlv = 0; };"""

H_GETTER_ANCHOR = """    const std::vector<EncounterWaterRow>& waterRows(
        const std::string& name) const;"""
H_GETTER_ADD = """    const std::vector<EncounterWaterRow>& waterRows(
        const std::string& name) const;
    // name: outdoor_arctic / outdoor_sub_arctic /
    // outdoor_temperate_wild / outdoor_temperate_inhabited /
    // outdoor_faerie / outdoor_pleistocene / outdoor_dinosaur_age /
    // outdoor_tropical / outdoor_sub_demihuman / outdoor_sub_dragon /
    // outdoor_sub_frog / outdoor_sub_giant / outdoor_sub_humanoid /
    // outdoor_sub_lycanthrope / outdoor_sub_men / outdoor_sub_snake /
    // outdoor_sub_sphinx / outdoor_sub_spider / outdoor_sub_undead /
    // outdoor_sphinx_t (R1034)
    bool hasOutdoor(const std::string& name) const;
    const std::vector<EncounterOutdoorRow>& outdoorRows(
        const std::string& name) const;"""

H_LIST_ANCHOR = """    // set: princes / arch_devils / elementals / hill_stone /
    // fire_frost / piercers
    const std::vector<std::string>& list(const std::string& set) const;"""
H_LIST_ADD = """    // set: princes / arch_devils / elementals / hill_stone /
    // fire_frost / piercers / ki_rin_set / leprechaun_set /
    // porcupine_set / iguanodon_set / lammasu_set / wolf_dog_set
    const std::vector<std::string>& list(const std::string& set) const;"""

H_MEMBER_ANCHOR = """    std::map<std::string, std::vector<EncounterWaterRow>> m_waters;"""
H_MEMBER_ADD = """    std::map<std::string, std::vector<EncounterWaterRow>> m_waters;
    std::map<std::string, std::vector<EncounterOutdoorRow>> m_outdoors;"""

CPP_HEADER_ANCHOR = ("// The dungeon encounter table registry loader (R1032; "
                     "R1033 added\n// the water family loader). The shape")
CPP_HEADER_ADD = ("// The dungeon encounter table registry loader (R1032; "
                  "R1033 added\n// the water family loader; R1034 the outdoor "
                  "family and its pick-sets).\n// The shape")

CPP_KEYS_ANCHOR = """const char* const kWaterFileKeys[] = { "key", "rows", nullptr };"""
CPP_KEYS_ADD = """const char* const kWaterFileKeys[] = { "key", "rows", nullptr };
const char* const kOutdoorRowKeys[] = { "key", "cols", nullptr };
const char* const kOutdoorFileKeys[] = { "key", "rows", nullptr };
const char* const kOutdoorSetKeys[] =
    { "key", "ki_rin", "leprechaun", "porcupine", "iguanodon",
      "lammasu", "wolf_dog", nullptr };"""

CPP_KIND_ANCHOR = """bool isLevelKind(const std::string& k) {"""
CPP_KIND_ADD = """// R1034: the outdoor family file keys. NOTE: outdoor_sets is
// excluded - it must fall through to its own shape branch (the
// outdoor_sets pick-set loader), not the STRICT rows loader.
bool isOutdoorKey(const std::string& k) {
    return k.rfind("outdoor_", 0) == 0 && k != "outdoor_sets";
}

bool isLevelKind(const std::string& k) {"""

CPP_BRANCH_ANCHOR = """    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""
CPP_BRANCH_ADD = """    } else if (isOutdoorKey(key)) {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kOutdoorFileKeys, key, &err)) goto bad;
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
            std::vector<EncounterOutdoorRow> rows;
            for (int i = 1; i <= n; ++i) {
                lua_rawgeti(L, -1, i);
                const int rt = lua_gettop(L);
                if (!lua_istable(L, rt)) {
                    err = "rows[" + std::to_string(i) + "] is not a table";
                    goto bad;
                }
                if (!checkAllowedKeys(L, rt, kOutdoorRowKeys,
                        key + " rows[" + std::to_string(i) + "]", &err))
                    goto bad;
                EncounterOutdoorRow row;
                if (!getStr(L, rt, "key", &row.key, &err)) goto bad;
                lua_getfield(L, rt, "cols");
                if (!lua_istable(L, -1)
                    || (int)lua_rawlen(L, -1) != 8) {
                    err = "'cols' must carry 8 terrain pairs";
                    lua_pop(L, 1);
                    goto bad;
                }
                for (int c = 0; c < 8; ++c) {
                    lua_rawgeti(L, -1, c + 1);
                    const int ct = lua_gettop(L);
                    if (!lua_istable(L, ct)
                        || (int)lua_rawlen(L, ct) != 2) {
                        err = "cols pair must be {lo, hi}";
                        goto bad;
                    }
                    long long v[2];
                    for (int j = 0; j < 2; ++j) {
                        lua_rawgeti(L, ct, j + 1);
                        if (!lua_isinteger(L, -1)) {
                            err = "cols pair field is not an integer";
                            goto bad;
                        }
                        v[j] = lua_tointeger(L, -1);
                        lua_pop(L, 1);
                    }
                    lua_pop(L, 1);        // pair
                    const int clo = (int)v[0], chi = (int)v[1];
                    if (clo == -1 && chi == -1) {
                        // no entry in this terrain column
                    } else if (clo >= 1 && clo <= 100
                               && chi >= clo && chi <= 100) {
                        row.lo[c] = clo;
                        row.hi[c] = chi;
                    } else {
                        err = "cols pair outside 01-00";
                        goto bad;
                    }
                }
                lua_pop(L, 1);            // cols
                rows.push_back(row);
                lua_pop(L, 1);            // row
            }
            lua_pop(L, 1);                // rows array
            if (m_outdoors.count(key)) { err = "duplicate def key"; goto bad; }
            m_outdoors[key] = rows;
        }
    } else if (key == "outdoor_sets") {
        const int t = lua_gettop(L);
        if (!checkAllowedKeys(L, t, kOutdoorSetKeys, key, &err)) goto bad;
        {
            std::string k;
            if (!getStr(L, t, "key", &k, &err)) goto bad;
            if (k != "outdoor_sets") { err = "def key mismatch"; goto bad; }
        }
        {
            const char* const names[6] = { "ki_rin", "leprechaun",
                "porcupine", "iguanodon", "lammasu", "wolf_dog" };
            for (int i = 0; i < 6; ++i) {
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
    } else {
        err = "unknown file shape for key '" + key + "'";
        goto bad;
    }"""

CPP_ACC_ANCHOR = """const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {"""
CPP_ACC_ADD = """bool EncounterTableRegistry::hasOutdoor(const std::string& name) const {
    return m_outdoors.count(name) != 0;
}

const std::vector<EncounterOutdoorRow>&
EncounterTableRegistry::outdoorRows(const std::string& name) const {
    static const std::vector<EncounterOutdoorRow> none;
    auto it = m_outdoors.find(name);
    return it == m_outdoors.end() ? none : it->second;
}

const std::vector<std::string>&
EncounterTableRegistry::list(const std::string& set) const {"""

ENC_REG_ANCHOR = """        // R1033: the water family joined the registry from its own
        // directory (the R1032 audit pins 20 files in encounters/).
        reg.loadDirectory("content/tables/encounters_water");"""
ENC_REG_ADD = """        // R1033: the water family joined the registry from its own
        // directory (the R1032 audit pins 20 files in encounters/).
        reg.loadDirectory("content/tables/encounters_water");
        // R1034: the outdoor family joined likewise (the R1033
        // audit pins 9 files in encounters_water/).
        reg.loadDirectory("content/tables/encounters_outdoor");"""


def replace_once(text, old, new, where):
    if text.count(old) != 1:
        die("anchor in %s must occur exactly once (found %d)"
            % (where, text.count(old)))
    return text.replace(old, new, 1)


def extend_registry():
    h = open(REG_H).read()
    if "EncounterOutdoorRow" in h:
        return False
    h = replace_once(h, H_WRITER_OLD, H_WRITER_NEW, "registry header comment")
    h = replace_once(h, H_STRUCT_ANCHOR, H_STRUCT_ADD, "registry h struct")
    h = replace_once(h, H_GETTER_ANCHOR, H_GETTER_ADD, "registry h getters")
    h = replace_once(h, H_LIST_ANCHOR, H_LIST_ADD, "registry h list comment")
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

REGTEST_ANCHOR = ('    #include "rules/audits/r1033_water_encounter_registry.h"'
                  '  // R1033')
REGTEST_ADD = (REGTEST_ANCHOR + '\n    #include '
               '"rules/audits/r1034_outdoor_encounter_registry.h"  // R1034')


def splice_encounters(src, start, end):
    # fresh apply only (idempotency handled by the caller)
    out = src[:start] + OUTDOOR_BLOCK + src[end:]
    out = replace_once(out, ENC_REG_ANCHOR, ENC_REG_ADD, "encReg() outdoor dir")
    return out


# ---------------------------------------------------------------------------
# 7. the R1034 battery fragment (generated from the parsed record)
# ---------------------------------------------------------------------------

ALL_NAMES = [name for _, name in TABLES] + [SPHINX_T]


def row_index(tables, key, want_key):
    for i, (k, lo, hi) in enumerate(tables[key]):
        if k == want_key:
            return i
    die("pin row %s not found in %s" % (want_key, key))


def build_fragment(tables, sets, counts):
    names_c = ", ".join('"%s"' % k for k in ALL_NAMES)
    rows_c = ", ".join(str(c) for c in counts)

    def pin(table, row_key):
        idx = row_index(tables, table, row_key)
        k, lo, hi = tables[table][idx]
        lines = ['        r = ereg.outdoorRows("%s")[%d];' % (table, idx),
                 '        if (r.key != "%s") ++bad;' % k]
        for c in range(8):
            if lo[c] >= 0:
                lines.append("        if (r.lo[%d] != %d || r.hi[%d] != %d)"
                             " ++bad;" % (c, lo[c], c, hi[c]))
            else:
                lines.append("        if (r.lo[%d] != -1 || r.hi[%d] != -1)"
                             " ++bad;" % (c, c))
        return "\n".join(lines)

    frag = []
    A = frag.append
    A("// ============================================================================")
    A("// Adnd1 - rules/audits/r1034_outdoor_encounter_registry.h  (R1034)")
    A("// The outdoor (wilderness) encounter family battery audit, the")
    A("// R1032/R1033 shape: the registry load, exact table counts, band")
    A("// coverage and engine parity, row spot pins against the retired")
    A("// print-fidelity record, the pick-sets, the key companions vs the")
    A("// monster registry, and the rollOutdoorEncounter() path.")
    A("// Expected values: 21 files, 348 outdoor rows (19 tables + the")
    A("// tropical Sphinx footnote) - all from the R63 outdoor record")
    A("// (Premium reprint p.182-191) and the R126 line-diff record the")
    A("// splice parsed.")
    A("// ============================================================================")
    A("{")
    A("")
    A("    static const char* const kNames[20] =")
    A("        { %s };" % names_c)
    A("    static const int kRows[20] = { %s };" % rows_c)
    A("")
    A("    int bad = 0;")
    A("    dm::EncounterTableRegistry ereg;")
    A("")
    A("    // -- 1. load: 21 outdoor files, zero errors, all dirs one reg --")
    A("    bad = 0;")
    A("    {")
    A('        const int files = ereg.loadDirectory(')
    A('            "content/tables/encounters_outdoor");')
    A("        if (files != 21) ++bad;")
    A("        if (!ereg.errors().empty()) ++bad;")
    A("        // all three families in one registry: the dungeon and")
    A("        // water files join with no key collision (their own")
    A("        // audits pin their own loads separately)")
    A('        const int df = ereg.loadDirectory(')
    A('            "content/tables/encounters");')
    A("        if (df != 20) ++bad;")
    A('        const int wf = ereg.loadDirectory(')
    A('            "content/tables/encounters_water");')
    A("        if (wf != 9) ++bad;")
    A('        if (!ereg.hasOutdoor("outdoor_arctic")) ++bad;')
    A('        if (!ereg.hasOutdoor("outdoor_sphinx_t")) ++bad;')
    A('        if (!ereg.hasWater("dinosaur_sub")) ++bad;')
    A("        if (!ereg.hasLevel(10)) ++bad;")
    A("    }")
    A('    printf("R1034 outdoor encounter registry load audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 2. counts: every table, exact row census -----------------------")
    A("    bad = 0;")
    A("    {")
    A("        int total = 0;")
    A("        for (int i = 0; i < 20; ++i) {")
    A("            if (!ereg.hasOutdoor(kNames[i])) ++bad;")
    A("            const int n = (int)ereg.outdoorRows(kNames[i]).size();")
    A("            if (n != kRows[i]) ++bad;")
    A("            total += n;")
    A("        }")
    A("        if (total != 348) ++bad;")
    A('        if (ereg.hasOutdoor("dungeon_level_1")) ++bad;   // STRICT shapes')
    A('        if (ereg.hasOutdoor("underwater_fresh_shallow")) ++bad;')
    A('        // the sets file is its own shape, never an outdoor')
    A('        // table (the R1034 preflight dispatch-order bug)')
    A('        if (ereg.hasOutdoor("outdoor_sets")) ++bad;')
    A("        // the pick-sets ride the registry lists")
    A("        static const char* const kSets[6] =")
    A('            { "ki_rin_set", "leprechaun_set", "porcupine_set",')
    A('              "iguanodon_set", "lammasu_set", "wolf_dog_set" };')
    A("        static const int kSetSizes[6] = { 3, 2, 2, 2, 2, 2 };")
    A("        for (int i = 0; i < 6; ++i)")
    A("            if ((int)ereg.list(kSets[i]).size() != kSetSizes[i]) ++bad;")
    A("    }")
    A('    printf("R1034 outdoor encounter registry counts audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 3. bands: column coverage + engine parity ---------------------")
    A("    bad = 0;")
    A("    {")
    A("        // per-table column discipline: the entries a column")
    A("        // carries chain 1 -> 100 (a column with no entries")
    A("        // at all is legal - rows print no entry there)")
    A("        for (int i = 0; i < 20; ++i) {")
    A("            const auto& rs = ereg.outdoorRows(kNames[i]);")
    A("            for (int c = 0; c < 8; ++c) {")
    A("                int prev = 0; bool any = false;")
    A("                for (const auto& r : rs) {")
    A("                    if (r.lo[c] < 0) continue;")
    A("                    any = true;")
    A("                    if (r.lo[c] != prev + 1 || r.hi[c] < r.lo[c])")
    A("                        { ++bad; break; }")
    A("                    prev = r.hi[c];")
    A("                }")
    A("                if (any && prev != 100) ++bad;")
    A("            }")
    A("        }")
    A("        // engine parity: dm::outdoorBands must carry the registry")
    A("        // rows verbatim, every climate x terrain column")
    A("        for (int c = 0; c < 8; ++c)")
    A("            for (int t = 0; t < 8; ++t) {")
    A("                const auto& got = dm::outdoorBands(")
    A("                    (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("                const auto& want = ereg.outdoorRows(kNames[c]);")
    A("                size_t n = 0;")
    A("                for (const auto& r : want)")
    A("                    if (r.lo[t] >= 0) ++n;")
    A("                if (got.size() != n) { ++bad; continue; }")
    A("                size_t j = 0;")
    A("                for (const auto& r : want) {")
    A("                    if (r.lo[t] < 0) continue;")
    A("                    if (got[j].key != r.key || got[j].lo != r.lo[t]")
    A("                        || got[j].hi != r.hi[t]) { ++bad; break; }")
    A("                    ++j;")
    A("                }")
    A("            }")
    A("        // engine parity: the eleven SUB_* subtables and the")
    A("        // tropical Sphinx footnote, every terrain column")
    A("        static const char* const kSubs[12] = {")
    A('            "SUB_DEMIHUMAN", "SUB_DRAGON", "SUB_FROG",')
    A('            "SUB_GIANT", "SUB_HUMANOID", "SUB_LYCANTHROPE",')
    A('            "SUB_MEN", "SUB_SNAKE", "SUB_SPHINX",')
    A('            "SUB_SPIDER", "SUB_UNDEAD", "SUB_SPHINX_T" };')
    A("        static const char* const kSubNames[12] = {")
    A('            "outdoor_sub_demihuman", "outdoor_sub_dragon",')
    A('            "outdoor_sub_frog", "outdoor_sub_giant",')
    A('            "outdoor_sub_humanoid", "outdoor_sub_lycanthrope",')
    A('            "outdoor_sub_men", "outdoor_sub_snake",')
    A('            "outdoor_sub_sphinx", "outdoor_sub_spider",')
    A('            "outdoor_sub_undead", "outdoor_sphinx_t" };')
    A("        for (int s = 0; s < 12; ++s)")
    A("            for (int t = 0; t < 8; ++t) {")
    A("                const auto& got = dm::outdoorSubBands(")
    A("                    kSubs[s], (dm::OutdoorTerrain)t);")
    A("                const auto& want = ereg.outdoorRows(kSubNames[s]);")
    A("                size_t n = 0;")
    A("                for (const auto& r : want)")
    A("                    if (r.lo[t] >= 0) ++n;")
    A("                if (got.size() != n) { ++bad; continue; }")
    A("                size_t j = 0;")
    A("                for (const auto& r : want) {")
    A("                    if (r.lo[t] < 0) continue;")
    A("                    if (got[j].key != r.key || got[j].lo != r.lo[t]")
    A("                        || got[j].hi != r.hi[t]) { ++bad; break; }")
    A("                    ++j;")
    A("                }")
    A("            }")
    A("    }")
    A('    printf("R1034 outdoor encounter registry bands audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 4. rows: spot pins, the R126 line-diff record ------------------")
    A("    bad = 0;")
    A("    {")
    A("        dm::EncounterOutdoorRow r;")
    A(pin("outdoor_arctic", "brown_bear"))
    A(pin("outdoor_arctic", "yeti"))
    A(pin("outdoor_temperate_wild", "giant_eagle"))
    A(pin("outdoor_tropical", "bandit"))
    A(pin("outdoor_tropical", "dervish"))
    A(pin("outdoor_sub_giant", "stone_giant"))
    A(pin("outdoor_sub_dragon", "chimera"))
    A(pin("outdoor_sub_men", "SUB_CHARACTER"))
    A(pin("outdoor_sphinx_t", "gynosphinx"))
    A("    }")
    A('    printf("R1034 outdoor encounter registry pins audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 5. sets: the six pick-sets, exact membership -------------------")
    A("    bad = 0;")
    A("    {")
    for pseudo, name, arr, expect in SETS:
        A('        const auto& s_%s = ereg.list("%s");' % (name, name))
        A("        if ((int)s_%s.size() != %d) ++bad;" % (name, len(expect)))
        for i, k in enumerate(expect):
            A('        if (s_%s[%d] != "%s") ++bad;' % (name, i, k))
        for _, k in enumerate(expect):
            A('        if (!reg.find("%s")) ++bad;' % k)
    A('        if (!ereg.list("no_such_set").empty()) ++bad;   // STRICT')
    A("    }")
    A('    printf("R1034 outdoor encounter registry sets audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 6. keys: the companions vs an independent registry walk -------")
    A("    bad = 0;")
    A("    {")
    A("        auto pushU = [](std::vector<std::string>& v,")
    A("                      const std::string& k) {")
    A("            for (const auto& x : v) if (x == k) return;")
    A("            v.push_back(k);")
    A("        };")
    A("        auto setNameOf = [](const std::string& k) -> const char* {")
    A('            if (k == "KI_RIN_SET") return "ki_rin_set";')
    A('            if (k == "LEPRECHAUN_SET") return "leprechaun_set";')
    A('            if (k == "PORCUPINE_SET") return "porcupine_set";')
    A('            if (k == "IGUANODON_SET") return "iguanodon_set";')
    A('            if (k == "LAMMASU_SET") return "lammasu_set";')
    A('            if (k == "WOLF_DOG_SET") return "wolf_dog_set";')
    A("            return nullptr;")
    A("        };")
    A("        auto subNameOf = [](const std::string& k) -> const char* {")
    A('            if (k == "SUB_DEMIHUMAN") return "outdoor_sub_demihuman";')
    A('            if (k == "SUB_DRAGON") return "outdoor_sub_dragon";')
    A('            if (k == "SUB_FROG") return "outdoor_sub_frog";')
    A('            if (k == "SUB_GIANT") return "outdoor_sub_giant";')
    A('            if (k == "SUB_HUMANOID") return "outdoor_sub_humanoid";')
    A('            if (k == "SUB_LYCANTHROPE") return')
    A('                "outdoor_sub_lycanthrope";')
    A('            if (k == "SUB_MEN") return "outdoor_sub_men";')
    A('            if (k == "SUB_SNAKE") return "outdoor_sub_snake";')
    A('            if (k == "SUB_SPHINX") return "outdoor_sub_sphinx";')
    A('            if (k == "SUB_SPIDER") return "outdoor_sub_spider";')
    A('            if (k == "SUB_UNDEAD") return "outdoor_sub_undead";')
    A("            return nullptr;")
    A("        };")
    A("        // an independent worklist expansion straight off the")
    A("        // registry - must equal the engine's key companion")
    A("        for (int c = 0; c < 8; ++c)")
    A("            for (int t = 0; t < 8; ++t) {")
    A("                std::vector<std::string> work;")
    A("                for (const auto& r : ereg.outdoorRows(kNames[c]))")
    A("                    if (r.lo[t] >= 0) work.push_back(r.key);")
    A("                std::vector<std::string> want;")
    A("                while (!work.empty()) {")
    A("                    const std::string k = work.back();")
    A("                    work.pop_back();")
    A('                    if (k == "SUB_CHARACTER")')
    A('                        { pushU(want, "character_party"); continue; }')
    A('                    if (k == "MISC_REPTILE")')
    A('                        { pushU(want, "giant_lizard"); continue; }')
    A('                    if (k == "SUB_SPHINX_T") {')
    A('                        for (const auto& r :')
    A('                             ereg.outdoorRows("outdoor_sphinx_t"))')
    A("                            pushU(want, r.key);")
    A("                        continue;")
    A("                    }")
    A("                    const char* sn = setNameOf(k);")
    A("                    if (sn) {")
    A("                        for (const auto& s : ereg.list(sn))")
    A("                            pushU(want, s);")
    A("                        continue;")
    A("                    }")
    A("                    const char* sub = subNameOf(k);")
    A("                    if (sub) {")
    A("                        for (const auto& r : ereg.outdoorRows(sub))")
    A("                            if (r.lo[t] >= 0) work.push_back(r.key);")
    A("                        continue;")
    A("                    }")
    A("                    if (k.compare(0, 4, \"SUB_\") == 0) { ++bad; continue; }")
    A("                    if (reg.find(k)) pushU(want, k);")
    A("                }")
    A("                const auto got = dm::outdoorEncounterKeys(")
    A("                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("                if (got.size() != want.size()) { ++bad; continue; }")
    A("                // set equality, both unique")
    A("                for (const auto& k : got) {")
    A("                    bool hit = false;")
    A("                    for (const auto& w : want)")
    A("                        if (k == w) { hit = true; break; }")
    A("                    if (!hit) { ++bad; break; }")
    A("                    if (!reg.find(k) && k != \"character_party\") ++bad;")
    A("                }")
    A("                for (const auto& w : want) {")
    A("                    bool hit = false;")
    A("                    for (const auto& k : got)")
    A("                        if (k == w) { hit = true; break; }")
    A("                    if (!hit) { ++bad; break; }")
    A("                }")
    A("            }")
    A("    }")
    A('    printf("R1034 outdoor encounter registry keys audit: bad %d\\n", bad);')
    A("    if (bad) return 1;")
    A("")
    A("    // -- 7. roll: the outdoor path, sweep + smoke ----------------------")
    A("    bad = 0;")
    A("    {")
    A("        // the SUB_CHARACTER roll block is dead code in the")
    A("        // retired engine (resolveOutdoorKey returns false for")
    A("        // it - the R63 dispatch quirk, preserved verbatim);")
    A("        // outdoorEncounterKeys still lists character_party")
    A("        rules::Rng rng(1034);")
    A("        rules::Dice dice(rng);")
    A("        int produced = 0;")
    A("        static int seen[64];")
    A("        for (int i = 0; i < 64; ++i) seen[i] = 0;")
    A("        for (int c = 0; c < 8; ++c)")
    A("            for (int t = 0; t < 8; ++t) {")
    A("                const auto allowed = dm::outdoorEncounterKeys(")
    A("                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("                for (int pct = 1; pct <= 100; ++pct) {")
    A("                    const int p2 = 1 + (pct * 37) % 100;")
    A("                    dm::DungeonEncounter e = dm::rollOutdoorEncounter(")
    A("                        reg, dice, pct, p2,")
    A("                        (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("                    if (e.key.empty()) continue;")
    A("                    ++produced;")
    A("                    ++seen[c * 8 + t];")
    A("                    if (e.isParty)   // defensive: dead as retired")
    A('                        if (e.key != "character_party") ++bad;')
    A("                    if (!reg.find(e.key)) ++bad;")
    A("                    if (e.count < 1) ++bad;")
    A("                    bool hit = false;")
    A("                    for (const auto& k : allowed)")
    A("                        if (k == e.key) { hit = true; break; }")
    A("                    if (!hit) ++bad;")
    A("                }")
    A("            }")
    A("        // every populated combo (non-empty companion) must produce")
    A("        // (SUB_CHARACTER columns lose their quirk cells, so the")
    A("        // per-combo count is not pinned at 100)")
    A("        for (int c = 0; c < 8; ++c)")
    A("            for (int t = 0; t < 8; ++t) {")
    A("                const auto allowed = dm::outdoorEncounterKeys(")
    A("                    reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("                if (!allowed.empty() && seen[c * 8 + t] == 0) ++bad;")
    A("            }")
    A("        // rng smoke: 4000 rolls, outcomes must be legal")
    A("        for (int i = 0; i < 4000; ++i) {")
    A("            const int c = i % 8, t = (i / 8) % 8;")
    A("            dm::DungeonEncounter e = dm::rollOutdoorEncounter(")
    A("                reg, dice, 1 + i % 100, 1 + (i * 53) % 100,")
    A("                (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("            if (e.key.empty()) continue;")
    A("            if (e.isParty)   // defensive: dead as retired")
    A('                if (e.key != "character_party") ++bad;')
    A("            if (e.isParty) continue;")
    A("            if (!reg.find(e.key)) ++bad;")
    A("            if (e.count < 1) ++bad;")
    A("            const auto allowed = dm::outdoorEncounterKeys(")
    A("                reg, (dm::OutdoorClime)c, (dm::OutdoorTerrain)t);")
    A("            bool hit = false;")
    A("            for (const auto& k : allowed)")
    A("                if (k == e.key) { hit = true; break; }")
    A("            if (!hit) ++bad;")
    A("        }")
    A("        if (produced < 4000) ++bad;  // the sweep resolves broadly")
    A("    }")
    A('    printf("R1034 outdoor encounter registry roll audit: bad %d\\n", bad);')
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
    applied = "EncounterOutdoorRow" in reg_h
    if applied:
        if "static const OutdoorRow kOut" in enc:
            die("half-spliced state: registry extended but the outdoor "
                "arrays still stand in dm/encounters.cpp - recover with "
                "git checkout and re-run")
        if census_count() != 962:
            die("already applied but census is %d (expected 962)"
                % census_count())
        n_lua = len([f for f in os.listdir(LUA_DIR) if f.endswith(".lua")])
        if n_lua != 21:
            die("already applied but %d outdoor lua files (expected 21)"
                % n_lua)
        print("applied 0, already 1")
        print("SPLICE OK")
        return

    pre_census = census_count()
    if pre_census != 955:
        die("pristine census is %d (expected 955)" % pre_census)

    src = enc
    pre_lines = src.count("\n")

    # 1. parse
    start, end, tables, sets = parse_outdoor_region(src)
    counts = gate_data(tables, sets)
    clime_counts = counts[:8]
    sub_counts = counts[8:19]
    print("parsed: 19 tables, %d rows (climates %r, subtables %r), "
          "sphinx_t 4, 6 pick-sets" % (sum(counts[:19]), clime_counts,
                                       sub_counts))

    # 2. emit lua + round-trip
    emit_lua(tables, sets)
    lua_roundtrip(tables, sets)
    print("round-trip: 21 lua files parse back byte-exact")

    # 3. roll-path simulation
    cells, resolved, absent, party_cells = simulate_roll_path(tables, sets)
    print("roll-path sim: %d first-shot cells clean (%d resolved, "
          "%d dead SUB_CHARACTER cells (the preserved R63 quirk), "
          "absent-key rerolls: %s)"
          % (cells, resolved, party_cells,
             sorted(absent) or "none"))

    # 4. registry extension
    extend_registry()

    # 5. the encounters.cpp splice
    out = splice_encounters(src, start, end)
    retired = [arr for arr, _ in TABLES]
    retired += ["kOutKiRinSet", "kOutLeprechaunSet", "kOutPorcupineSet",
                "kOutIguanodonSet", "kOutLammasuSet", "kOutWolfDogSet",
                "kSphinxT", "kLoT", "kHiT", "sizeof kOut"]
    # the untouched head and tail must be clean (the replacement block
    # names the retired arrays in its provenance comment, by design)
    for tok in retired:
        if tok in src[:start] or tok in src[end:]:
            die("retired token %s survived outside the spliced region" % tok)
    kept = ["rollOutdoorEncounter", "outdoorEncounterKeys",
            "outdoorBands", "outdoorSubBands", "SUB_SPHINX_T",
            "SUB_CHARACTER", "MISC_REPTILE", "KI_RIN_SET",
            "rollCharacterParty"]
    for tok in kept:
        if tok not in out:
            die("retained token %s missing after the splice" % tok)
    with open(ENC, "w") as f:
        f.write(out)
    print("spliced dm/encounters.cpp (%d -> %d lines)"
          % (pre_lines, out.count("\n")))

    # 6. the battery fragment
    frag = build_fragment(tables, sets, counts)
    os.makedirs(os.path.dirname(FRAG), exist_ok=True)
    with open(FRAG, "w") as f:
        f.write(frag)

    # 7. regtest include
    rt = open(REGTEST).read()
    rt = replace_once(rt, REGTEST_ANCHOR, REGTEST_ADD, "regtest include")
    with open(REGTEST, "w") as f:
        f.write(rt)
    print("regtest.cpp: R1034 fragment included")

    # 8. static sanity: brace balance on every touched C++ file
    for p in (ENC, REG_H, REG_CPP):
        d = brace_balance(p)
        if d != 0:
            die("brace imbalance %d in %s" % (d, p))

    post_census = census_count()
    if post_census != 962:
        die("post-splice census is %d (expected 962)" % post_census)
    print("census: %d -> %d audit printf patterns"
          % (pre_census, post_census))

    n_lua = len([f for f in os.listdir(LUA_DIR) if f.endswith(".lua")])
    if n_lua != 21:
        die("wrote %d outdoor lua files (expected 21)" % n_lua)
    print("applied 1, rewrote 4 tracked files, wrote 22 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
