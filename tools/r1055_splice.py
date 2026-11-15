#!/usr/bin/env python3
# r1055_splice.py - the R1055 splice tool: the PHB
# subclass gate de-wire of
# rules/phb/subclassgates.h.
#
# WHAT IT DOES (run from the repo root, idempotent):
#   - parses the 14 retiring static arrays (the 5
#     namespace-scope R180 matrices - the ability
#     minimums, Race Table I, Race Table II, the
#     alignment codes, the xp-bonus codes - and the
#     9 in-function R230/R231 private flat copies:
#     kDie, kAllow, kCap, kLen, kXp, kAdd, kFixed,
#     kHpB, kStop) plus a semantic MODEL of every
#     kept logic fn (the four if-chains, the gnome
#     conditional, the bonus-rule switch, the
#     derived cap fns, every clamp line)
#   - writes content/tables/ph_subgates/ as 3 defs,
#     12 named tables, every def's rows = the 6
#     registry subclasses: ph_subgates_qualify
#     (ability_min 36 [6][6] FLATTENED sub-major,
#     align_req 6, xp_bonus 6), ph_subgates_race
#     (race_allowed 42, race_cap 42, [6][7]
#     FLATTENED sub-major) and ph_subgates_leveling
#     (hit_die 6, xp_len 6, xp_attain 102 [6][17]
#     FLATTENED sub-major, xp_add 6, fixed_hp_level
#     6, hp_beyond_fixed 6, level_stop 6)
#   - DEDUPE (the round's structural kill): the R230
#     flat copies kAllow/kCap are DUPLICATES of
#     kGateRaceAllowed/kGateRaceCap (proven at parse
#     time - the tool DIES on any drift);
#     subclassPlayerAllowed and subclassLevelCapFor
#     retire ONTO the same race_allowed/race_cap
#     tables (one copy of the data, two accessors)
#   - rewrites the 14 array accessors onto a
#     namespace-rules seam: gtReg() / gtTable(key,
#     tag); every signature, clamp and branch stays;
#     the matrix reads become [sub * W + col]; the
#     fallback is the parsed cell (0,0) per table
#   - writes rules/audits/r1055_subgates_registry.h
#     at the R1041+ in-function seat (SEVEN printf
#     sections, SIX guards, census 1089 -> 1096) and
#     seats its include at regtest.cpp:1304
#
# HARD LESSONS APPLIED (the R1049-R1054 ledgers):
# every want is computed from the SAME parse that
# writes the lua; probe POLARITIES derive from the
# parsed models, never recalled constants;
# NEGATIVE cells handled end to end (the -1
# unlimited caps and the -6 halfling-druid NPC-only
# cap); wrap-agnostic regex self-scan checks; the
# rules:: token and the fn stay on ONE line; every
# per-def emitted loop is scoped to its own def
# block (the R1054 class-13 kill); the enum-typed
# args cast explicitly - (rules::Ability)a,
# (rules::CharRace)r - so the fragment compiles at
# the Termux preflight.

import os
import re
import sys

ROOT = os.getcwd()
HEAD = "rules/phb/subclassgates.h"
LUA_DIR = "content/tables/ph_subgates"
FRAG = "rules/audits/r1055_subgates_registry.h"
REGTEST = "regtest.cpp"
APPLIED_MARK = "// R1055 applied"
INC_LINE = ('    #include "rules/audits/'
            'r1055_subgates_registry.h"  // R1055')
CENSUS_BEFORE = 1089
CENSUS_AFTER = 1096
INC_ANCHOR = ('    #include "rules/audits/'
              'r1054_sage_registry.h"  // R1054')

# the 6 registry subclasses (SUB_COUNT 6, in
# subclasses.h registry order); every def's rows
SUB_ROWS = ["paladin", "ranger", "druid",
            "illusionist", "assassin", "monk"]

# the ability enum order (STR INT WIS DEX CON
# CHA - engine/character.h; the tokens must
# appear in the pristine header)
ABIL = {"ABILITY_STR": 0, "ABILITY_INT": 1,
        "ABILITY_WIS": 2, "ABILITY_DEX": 3,
        "ABILITY_CON": 4, "ABILITY_CHA": 5}

DEF_KEYS = ["ph_subgates_qualify",
            "ph_subgates_race",
            "ph_subgates_leveling"]

# the 12 named tables:
# (def key, tag, cells, kind, owner fns)
# kind: m6 = [sub * 6 + ab], m7 = [sub * 7 + race],
# flat = [sub], xp = the xp_attain 102-cell flat
TABLES = [
    ("ph_subgates_qualify", "ability_min",
     36, "m6", ["subclassAbilityMin"]),
    ("ph_subgates_qualify", "align_req",
     6, "flat", ["subclassAlignmentReq"]),
    ("ph_subgates_qualify", "xp_bonus",
     6, "flat", ["subclassXpBonusRule"]),
    ("ph_subgates_race", "race_allowed",
     42, "m7", ["subclassRaceAllowed",
                "subclassPlayerAllowed"]),
    ("ph_subgates_race", "race_cap",
     42, "m7", ["subclassRaceCap",
                "subclassLevelCapFor"]),
    ("ph_subgates_leveling", "hit_die",
     6, "flat", ["subclassHitDie"]),
    ("ph_subgates_leveling", "xp_len",
     6, "flat", ["subclassXpToAttain"]),
    ("ph_subgates_leveling", "xp_attain",
     102, "xp", ["subclassXpToAttain"]),
    ("ph_subgates_leveling", "xp_add",
     6, "flat", ["subclassXpToAttain"]),
    ("ph_subgates_leveling", "fixed_hp_level",
     6, "flat", ["subclassFixedHpLevel"]),
    ("ph_subgates_leveling", "hp_beyond_fixed",
     6, "flat", ["subclassHpBeyondFixed"]),
    ("ph_subgates_leveling", "level_stop",
     6, "flat", ["subclassLevelStop"]),
]

# the tables whose values ride a fragment want
# array (xp_len/xp_add are pinned by the
# derived adder probes instead)
WANT_TAGS = ["ability_min", "align_req",
             "xp_bonus", "race_allowed",
             "race_cap", "hit_die",
             "xp_attain", "fixed_hp_level",
             "hp_beyond_fixed", "level_stop"]

# the kept logic fns (if-chains + derived); every
# one is probed at the edges from its parsed model
CHAIN_FNS = ["subclassRuntimeBase",
             "subclassConClass",
             "subclassStartAgeBase",
             "subclassTwoDiceFirstLevel"]
DERIVED_FNS = ["subclassMeetsAbilityMin",
               "subclassCapIsNpcOnly",
               "illusionistGnomeCap",
               "subclassXpBonusEarned",
               "subclassLevelCapTotal"]
ALL_FNS = sorted(set(
    [f for _, _, _, _, fs in TABLES
     for f in fs] + CHAIN_FNS + DERIVED_FNS))

LABELS = [
    "R1055 subgates registry load",
    "R1055 subgates registry counts",
    "R1055 subgates qualify",
    "R1055 subgates race",
    "R1055 subgates leveling",
    "R1055 subgates registry seam",
    "R1055 subgates registry edges",
]

LUA_TITLE = {
    "ph_subgates_qualify":
        "PHB subclass qualification gates "
        "(ability minimums, alignment, xp bonus)",
    "ph_subgates_race":
        "PHB Character Race Tables I and II "
        "(eligibility and level caps)",
    "ph_subgates_leveling":
        "PHB subclass leveling pins (hit dice, "
        "XP ladders, fixed hp, level stops)",
}

LUA_ROWS_CMT = (
    "the six registry subclasses in order "
    "(paladin, ranger, druid, illusionist, "
    "assassin, monk)")

LUA_CMT = {
    "ability_min": "the class-section "
    "ability minimums, STR INT WIS DEX CON "
    "CHA columns, [6][6] FLATTENED sub-major; "
    "0 = no requirement",
    "align_req": "the Table I alignment "
    "requirement codes (the SubAlignReq "
    "enum order)",
    "xp_bonus": "the printed experience-bonus "
    "rule codes (the SubXpBonusRule enum "
    "order)",
    "race_allowed": "Character Race Table I "
    "(class limitations), [6][7] FLATTENED "
    "sub-major, columns human dwarf elf "
    "gnome half-elf halfling half-orc; "
    "1 = player-character eligible",
    "race_cap": "Character Race Table II "
    "(level caps), [6][7] FLATTENED "
    "sub-major; 0 = forbidden, -1 = "
    "unlimited, positive = the printed "
    "player cap, -n (n >= 2) = NPC-only "
    "cap n",
    "hit_die": "the subclass hit die (the "
    "registry pins)",
    "xp_len": "the printed XP attain rows "
    "per subclass (the ladder length)",
    "xp_attain": "the XP to ATTAIN each "
    "level, [6][17] FLATTENED sub-major; "
    "ragged rows pad with 0 (never read "
    "past xp_len)",
    "xp_add": "the XP adder past the "
    "printed rows; 0 = the top row "
    "repeats",
    "fixed_hp_level": "the fixed-hp level "
    "(past it the fixed hp per level)",
    "hp_beyond_fixed": "the fixed hp per "
    "level past the fixed-hp level",
    "level_stop": "the leveling stop (the "
    "name-cap analog)",
}


def die(msg):
    sys.stderr.write(
        "r1055_splice: FATAL: %s\n" % msg)
    sys.exit(1)


# ---- census --------------------------------

def census_count():
    n = open(os.path.join(
        ROOT, REGTEST)).read().count(
        "audit: bad %d")
    for d, _, fs in os.walk(
            os.path.join(
                ROOT, "rules/audits")):
        for f in fs:
            if f.endswith(".h"):
                n += open(os.path.join(
                    d, f)).read().count(
                    "audit: bad %d")
    return n


# ---- the parse -----------------------------
# An independent read of every retiring array
# plus a semantic MODEL of every kept logic fn
# (the frag probes derive from the models, never
# from recalled constants).

def fn_body(src, fn):
    m = re.search(
        r"inline [\w\* ]+?" + fn +
        r"\([\s\S]*?\n\}", src)
    if not m:
        die("body of " + fn + " not found")
    return m.group(0)


def flat(body):
    return re.sub(r"\s+", " ", body)


def strip_comments(s):
    return re.sub(r"//[^\n]*", "", s)


def parse_enum(src, name):
    m = re.search(
        r"enum " + name +
        r"\s*:\s*int\s*\{([^}]*)\}", src)
    if not m:
        die("enum " + name + " not found")
    body = strip_comments(m.group(1))
    out = {}
    val = 0
    for m2 in re.finditer(
            r"(\w+)(?:\s*=\s*(-?\d+))?\s*,"
            r"?", body):
        nm, v = m2.group(1), m2.group(2)
        if v is not None:
            val = int(v)
        out[nm] = val
        val += 1
    if not out:
        die("enum " + name + " empty")
    return out


def resolve_init(lit, emap):
    # cell tokens: ints or enum identifiers
    toks = [t.strip() for t in
            re.findall(r"[A-Za-z_]\w*|-?\d+",
                       lit)]
    out = []
    for t in toks:
        if re.match(r"-?\d+$", t):
            out.append(int(t))
        elif t in emap:
            out.append(emap[t])
        else:
            die("unresolved cell token " + t)
    return out


def parse_ns_matrix(src, name, rows, cols,
                   emap=None):
    m = re.search(
        r"static const int " + name +
        r"\[SUB_COUNT\](?:\[" + str(cols) +
        r"\])? = \{([\s\S]*?)\};", src)
    if not m:
        die("matrix " + name + " not found")
    lit = strip_comments(m.group(1))
    vals = resolve_init(lit, emap or {})
    want = rows * cols
    if len(vals) != want:
        die(name + ": %d cells parsed, "
            "want %d" % (len(vals), want))
    return vals


def parse_fn_array(src, fn, name, cells,
                   rows=None, cols=None):
    body = fn_body(src, fn)
    if rows:
        pat = (r"static const int " + name +
               r"\[" + str(rows) +
               r"\]\[" + str(cols) +
               r"\] = \{([\s\S]*?)\};")
    else:
        pat = (r"static const int " + name +
               r"\[" + str(cells) +
               r"\] = \{([\s\S]*?)\};")
    m = re.search(pat, body)
    if not m:
        die(fn + ": array " + name +
            " not found")
    vals = [int(v) for v in
            re.findall(r"-?\d+", m.group(1))]
    if len(vals) != cells:
        die(fn + ": %d cells parsed, "
            "want %d" % (len(vals), cells))
    return vals


def parse_chain(src, fn):
    body = fn_body(src, fn)
    fb = flat(body)
    if re.search(r"inline int \w+\(int sub\)",
                 fb) is None:
        die(fn + ": not an if-chain")
    got = re.findall(
        r"if \(sub == (\d+)\) "
        r"return (-?\d+);", fb)
    dfl = re.findall(
        r"return (-?\d+);", fb)
    if not dfl or len(got) < 2:
        die(fn + ": if-chain shape")
    out = {}
    for i, v in got:
        out[int(i)] = int(v)
    out["dfl"] = int(dfl[-1])
    return out


def parse_pristine(src):
    p = {}
    p["n_static"] = len(
        re.findall(r"static const ", src))
    if p["n_static"] != 14:
        die("pristine has %d static "
            "consts, want 14 (5 R180 "
            "matrices + 9 R230/R231 "
            "private flat copies)"
            % p["n_static"])
    # the enum maps (the align/bonus
    # arrays carry enum identifiers)
    p["align_map"] = parse_enum(
        src, "SubAlignReq")
    p["bonus_map"] = parse_enum(
        src, "SubXpBonusRule")
    if len(p["align_map"]) != 6 \
            or len(p["bonus_map"]) != 4:
        die("enum map sizes")
    # the ability tokens used by the bonus
    # switch must appear in the pristine
    for tok in ("ABILITY_STR", "ABILITY_INT",
                "ABILITY_WIS", "ABILITY_CHA",
                "ABILITY_COUNT"):
        if tok not in src:
            die("ability token " + tok +
                " not in the pristine")
    # the 5 namespace matrices
    p["tabs"] = {}
    p["tabs"]["ability_min"] = \
        parse_ns_matrix(
            src, "kGateAbilityMin", 6, 6)
    p["tabs"]["race_allowed"] = \
        parse_ns_matrix(
            src, "kGateRaceAllowed", 6, 7)
    p["tabs"]["race_cap"] = \
        parse_ns_matrix(
            src, "kGateRaceCap", 6, 7)
    p["tabs"]["align_req"] = \
        parse_ns_matrix(
            src, "kGateAlignReq", 6, 1,
            emap=p["align_map"])
    p["tabs"]["xp_bonus"] = \
        parse_ns_matrix(
            src, "kGateXpBonus", 6, 1,
            emap=p["bonus_map"])
    # the 9 in-function copies
    p["tabs"]["hit_die"] = \
        parse_fn_array(
            src, "subclassHitDie",
            "kDie", 6)
    k_allow = parse_fn_array(
        src, "subclassPlayerAllowed",
        "kAllow", 42)
    k_cap = parse_fn_array(
        src, "subclassLevelCapFor",
        "kCap", 42)
    # THE DEDUPE PROOF: the R230 flat
    # copies must equal the R180 matrices
    if k_allow != p["tabs"]["race_allowed"]:
        die("kAllow drifted from "
            "kGateRaceAllowed - the "
            "dedupe does not hold")
    if k_cap != p["tabs"]["race_cap"]:
        die("kCap drifted from "
            "kGateRaceCap - the "
            "dedupe does not hold")
    p["tabs"]["xp_len"] = \
        parse_fn_array(
            src, "subclassXpToAttain",
            "kLen", 6)
    p["tabs"]["xp_attain"] = \
        parse_fn_array(
            src, "subclassXpToAttain",
            "kXp", 102, rows=6, cols=17)
    p["tabs"]["xp_add"] = \
        parse_fn_array(
            src, "subclassXpToAttain",
            "kAdd", 6)
    p["tabs"]["fixed_hp_level"] = \
        parse_fn_array(
            src, "subclassFixedHpLevel",
            "kFixed", 6)
    p["tabs"]["hp_beyond_fixed"] = \
        parse_fn_array(
            src, "subclassHpBeyondFixed",
            "kHpB", 6)
    p["tabs"]["level_stop"] = \
        parse_fn_array(
            src, "subclassLevelStop",
            "kStop", 6)
    # the if-chain models
    p["chains"] = {}
    for fn in CHAIN_FNS:
        p["chains"][fn] = parse_chain(
            src, fn)
    # the gnome conditional model
    gb = flat(fn_body(
        src, "illusionistGnomeCap"))
    gm = re.search(
        r"if \(intScore < 17 \|\| "
        r"dexScore < 17\) "
        r"return (-?\d+); "
        r"return (-?\d+);", gb)
    if not gm:
        die("gnome conditional shape")
    p["gnome"] = (int(gm.group(1)),
                  int(gm.group(2)))
    # the bonus-rule switch model:
    # rule code -> the ability pair/triple
    p["bonus_rules"] = {}
    eb = fn_body(src, "subclassXpBonusEarned")
    for m in re.finditer(
            r"case (SUB_XP_BONUS_\w+):"
            r"([\s\S]*?)(?=case |default:)",
            eb):
        rule = p["bonus_map"][m.group(1)]
        abils = re.findall(
            r"s\.get\((ABILITY_\w+)\)",
            m.group(2))
        if not abils:
            die("bonus rule " + m.group(1))
        p["bonus_rules"][rule] = [
            ABIL[a] for a in abils]
    for a, v in p["bonus_map"].items():
        if v != 0 and v not in \
                p["bonus_rules"]:
            die("bonus rule " + a +
                " unmodeled")
    if "return false;" not in eb:
        die("bonus switch default shape")
    # the kept derived fns keep their
    # shapes (probed at the edges)
    if ("return subclassRaceCap(sub, r)"
        " <= -2;") not in flat(fn_body(
            src, "subclassCapIsNpcOnly")):
        die("npc-only flag shape")
    return p


def table_cells(p, tag):
    return p["tabs"][tag]


def def_table_list(key):
    return [(k, t, c, kind, fns)
            for (k, t, c, kind, fns)
            in TABLES if k == key]


# ---- the emitter ---------------------------

def wrap(text, ind=""):
    body = text.lstrip(" ")
    lead = ind + (" " * (len(text) - len(body)))
    if len(lead + body) <= 78:
        return [lead + body]
    if '"' in body:
        die("emit: line with a "
            + "string literal does "
            + "not fit 78: "
            + body[:40])
    words = body.split(" ")
    out = [lead + words[0]]
    for w in words[1:]:
        if len(out[-1]) + 1 + len(w) <= 78:
            out[-1] += " " + w
        else:
            out.append(lead + "    " + w)
    return out


class Emit:
    def __init__(self):
        self.lines = []

    def __call__(self, text, ind=""):
        self.lines.extend(wrap(text, ind))

    def raw(self, lines):
        for ln in lines:
            if len(ln.rstrip()) > 78:
                die("emit: raw line "
                    "over 78: " + ln[:50])
        self.lines.extend(lines)


def camel(tag):
    return "".join(
        part.capitalize()
        for part in tag.split("_"))


def want_name(tag):
    return "wantGt" + camel(tag)


# ---- lua emit -------------------------------

def lua_def(p, key):
    out = []
    w = out.append
    tabs = def_table_list(key)
    n = len(SUB_ROWS)
    w("-- " + key)
    w("-- The R1055 subclass gate "
      "de-wire (rules/phb/"
      "subclassgates.h).")
    w("-- " + LUA_TITLE[key] + ".")
    w("-- rows[]: " + LUA_ROWS_CMT
      + " - the R1042 equipment "
      "rows idiom.")
    w("-- tables[]: the printed "
      "columns; the accessors "
      "live in rules/phb/"
      "subclassgates.h and keep "
      "their clamps.")
    w("-- DO NOT hand-edit: "
      "tools/r1055_splice.py is the "
      "only writer.")
    w("")
    w("return {")
    w("  key = \"%s\"," % key)
    w("  name = \"%s\"," % LUA_TITLE[key])
    w("  sources = {")
    w("    { part = 0, round = 1055 },")
    w("  },")
    w("  pins = {")
    w("    { name = \"%sRowCount\","
      % key)
    w("      value = %d," % n)
    w("      comment = \"the table "
      "rows\" },")
    w("  },")
    w("  rows = {")
    for i, nm in enumerate(SUB_ROWS):
        w("    { name = \"%s\"," % nm)
        w("      set = \"%s\"," % key)
        w("      band = { %d, %d },"
          % (i, i))
        w("      xp = 0, xp_hi = 0, "
          "gp = 0, gp_hi = 0,")
        w("      qty = { 0, 0 } },")
    w("  },")
    w("  tables = {")
    for (_, tag, cells, _, _) in tabs:
        vals = table_cells(p, tag)
        w("    { name = \"%s\"," % tag)
        w("      values = {")
        for r in range(0, len(vals), 10):
            w("        "
              + ", ".join(str(v)
                          for v in
                          vals[r:r + 10])
              + ", ")
        w("      },")
        w("      comment = \"%s\" },"
          % LUA_CMT[tag])
    w("  },")
    w("}")
    w("")
    return "\n".join(out)


def build_lua(p):
    return {key: lua_def(p, key)
            for key in DEF_KEYS}


# ---- seam emit ------------------------------

SEAM_TXT = """\
// ---- the R1055 registry seam ---------------
// content/tables/ph_subgates/ via
// items::MiscItemRegistry: the R1042
// rows idiom plus named tables per def
// (the R1051 dzTable idiom). NO rows
// readers this round (the def rows are
// structural - the file prints no
// string-name arrays). Header-only
// singleton (the R1040 appendixp.h
// idiom). Every accessor below keeps
// its signature, clamp and branch; only
// the array read moves behind the
// registry. The [6][6] and [6][7]
// matrices retire FLATTENED sub-major;
// the matrix accessors read the cell
// [sub * W + col]. The R230 private
// flat copies kAllow/kCap retire ONTO
// the same race_allowed/race_cap tables
// (the dedupe: one copy of the data,
// two accessors). The fallback of every
// accessor is the parsed cell (0,0) of
// its table.

inline items::MiscItemRegistry&
gtReg() {
    static items::MiscItemRegistry
        reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory(
            "content/tables/"
            "ph_subgates");
    }
    return reg;
}

// one named int table of one def
// (null when absent or empty)
inline const std::vector<long
    long>* gtTable(const char* key,
                  const char* tag) {
    static std::map<std::string,
        std::vector<long long>>
        cache;
    const std::string kk =
        std::string(key) + "/"
        + tag;
    auto it = cache.find(kk);
    if (it == cache.end()) {
        const items::MiscItemDef*
            d = gtReg().find(key);
        const std::vector<long
            long>* v = nullptr;
        if (d) {
            for (const auto& t :
                 d->tables) {
                if (t.name == tag) {
                    v = &t.values;
                    break;
                }
            }
        }
        it = cache.emplace(
            kk, v ? *v
                  : std::vector<
                        long long>()
                   ).first;
    }
    return it->second.empty()
        ? nullptr
        : &it->second;
}
"""


def gt_site(key, tag, var="g"):
    # a hand-shaped two-line call site
    return [
        "    const auto* %s = gtTable(" % var,
        "        \"%s\", \"%s\");"
        % (key, tag)]


def new_body(p, fn, key, tag, kind):
    vals = table_cells(p, tag)
    e = Emit()
    if fn == "subclassAbilityMin":
        e("inline int subclassAbilityMin("
          "int sub, Ability ab) {")
        e.raw(gt_site(key, tag))
        e("    if (sub < 0) sub = 0;")
        e("    if (sub >= SUB_COUNT)")
        e("        sub = SUB_COUNT - 1;")
        e("    if ((int)ab < 0")
        e("        || (int)ab >= "
          "ABILITY_COUNT)")
        e("        return 0;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)")
        e("        [sub * 6 + (int)ab];")
    elif fn == "subclassRaceAllowed":
        e("inline int subclassRaceAllowed("
          "int sub, CharRace r) {")
        e.raw(gt_site(key, tag))
        e("    if (sub < 0) sub = 0;")
        e("    if (sub >= SUB_COUNT)")
        e("        sub = SUB_COUNT - 1;")
        e("    if ((int)r < 0")
        e("        || (int)r >= "
          "RACE_CHAR_COUNT)")
        e("        return 0;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)")
        e("        [sub * 7 + (int)r];")
    elif fn == "subclassRaceCap":
        e("inline int subclassRaceCap("
          "int sub, CharRace r) {")
        e.raw(gt_site(key, tag))
        e("    if (sub < 0) sub = 0;")
        e("    if (sub >= SUB_COUNT)")
        e("        sub = SUB_COUNT - 1;")
        e("    if ((int)r < 0")
        e("        || (int)r >= "
          "RACE_CHAR_COUNT)")
        e("        return 0;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)")
        e("        [sub * 7 + (int)r];")
    elif fn == "subclassAlignmentReq":
        e("inline int subclassAlignmentReq("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    if (sub < 0) sub = 0;")
        e("    if (sub >= SUB_COUNT)")
        e("        sub = SUB_COUNT - 1;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[sub];")
    elif fn == "subclassXpBonusRule":
        e("inline int subclassXpBonusRule("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    if (sub < 0) sub = 0;")
        e("    if (sub >= SUB_COUNT)")
        e("        sub = SUB_COUNT - 1;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[sub];")
    elif fn == "subclassHitDie":
        e("inline int subclassHitDie("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[si];")
    elif fn == "subclassPlayerAllowed":
        e("inline int subclassPlayerAllowed("
          "int sub, CharRace r) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    int ri = (int)r;")
        e("    if (ri < 0) ri = 0;")
        e("    if (ri > 6) ri = 6;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)")
        e("        [si * 7 + ri];")
    elif fn == "subclassLevelCapFor":
        e("inline int subclassLevelCapFor("
          "int sub, CharRace r,")
        e("                        "
          "int intScore, int dexScore) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    int ri = (int)r;")
        e("    if (ri < 0) ri = 0;")
        e("    if (ri > 6) ri = 6;")
        e("    if (si == 3 && ri == 3)")
        e("        return "
          "illusionistGnomeCap(")
        e("            intScore, "
          "dexScore);")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)")
        e("        [si * 7 + ri];")
    elif fn == "subclassXpToAttain":
        e("inline int subclassXpToAttain("
          "int sub, int level) {")
        e.raw(gt_site(key, "xp_len", "gl"))
        e.raw(gt_site(key, "xp_attain", "gx"))
        e.raw(gt_site(key, "xp_add", "ga"))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    if (level <= 1) return 0;")
        e("    int n = gl")
        e("        ? (int)(*gl)[si] : %d;"
          % p["tabs"]["xp_len"][0])
        e("    int add = ga")
        e("        ? (int)(*ga)[si] : %d;"
          % p["tabs"]["xp_add"][0])
        e("    if (!gx) return %d;"
          % p["tabs"]["xp_attain"][0])
        e("    if (level <= n)")
        e("        return (int)(*gx)")
        e("            [si * 17 + "
          "level - 1];")
        e("    return (int)(*gx)")
        e("        [si * 17 + n - 1]")
        e("        + (level - n) * add;")
    elif fn == "subclassFixedHpLevel":
        e("inline int subclassFixedHpLevel("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[si];")
    elif fn == "subclassHpBeyondFixed":
        e("inline int subclassHpBeyondFixed("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[si];")
    elif fn == "subclassLevelStop":
        e("inline int subclassLevelStop("
          "int sub) {")
        e.raw(gt_site(key, tag))
        e("    int si = sub;")
        e("    if (si < 0) si = 0;")
        e("    if (si > 5) si = 5;")
        e("    if (!g) return %d;" % vals[0])
        e("    return (int)(*g)[si];")
    else:
        die("no rewrite for " + fn)
    e("}")
    return "\n".join(e.lines)


def build_seam(src, p):
    s = src
    if APPLIED_MARK in s:
        die("applied mark already present")
    anchor = "namespace rules {\n"
    if anchor not in s:
        die("namespace rules anchor not found")
    inc = (APPLIED_MARK + "\n"
           + "#include \"items/"
           "MiscItemRegistry.h\"\n"
           + "\n")
    s = s.replace(
        anchor, inc + anchor + "\n" + SEAM_TXT, 1)
    # retire the 5 namespace-scope R180
    # arrays (each with its comment block)
    for name in ("kGateAbilityMin",
                 "kGateRaceAllowed",
                 "kGateRaceCap",
                 "kGateAlignReq",
                 "kGateXpBonus"):
        pat = (r"(?:(?:^//[^\n]*\n)+)?"
               r"^static const int " + name +
               r"\[SUB_COUNT\](?:\[\d+\])?"
               r" = \{[\s\S]*?\};\n\n")
        s2 = re.sub(pat, "", s, count=1,
                    flags=re.M)
        if s2 == s:
            die("namespace array " + name +
                " not removed")
        s = s2

    for (key, tag, cells, kind, fns) \
            in TABLES:
        for fn in fns:
            if fn == "subclassXpToAttain" \
                    and tag != "xp_len":
                continue
            body = new_body(p, fn, key,
                            tag, kind)
            m = re.search(
                r"inline [\w\* ]*?" + fn +
                r"\([^)]*\)[\s\S]*?\n\}", s)
            if not m:
                die("body of " + fn
                    + " not found for "
                    "the rewrite")
            s = s.replace(m.group(0), body, 1)
    if re.search(r"static const ", s):
        die("a static array survived "
            "the rewrite")
    for fn in CHAIN_FNS + DERIVED_FNS:
        if fn not in s:
            die("kept fn " + fn + " lost")
    for tok in ("SUB_ALIGN_ANY",
                "SUB_XP_BONUS_NONE",
                "SUB_COUNT",
                "RACE_CHAR_COUNT",
                "ABILITY_COUNT"):
        if tok not in s:
            die("enum token " + tok + " lost")
    return s


# ---- fragment emit --------------------------

def want_arr(P, name, vals, ind=""):
    P("%sconst int %s[] = {" % (ind, name))
    for r in range(0, len(vals), 10):
        P("%s    %s,"
          % (ind, ", ".join(str(v) for v in
                            vals[r:r + 10])))
    P("%s};" % ind)


def row_probe(E, i, nm, ind=""):
    # a string-literal probe hand-shaped
    # so the literal never wraps
    E.raw([
        "%sif (std::string(" % ind,
        "%s    d->rows[%d].name)" % (ind, i),
        "%s    != \"%s\")" % (ind, nm),
        "%s    ++bad;" % ind])


def probe_fn(E, fn, args, val):
    # a one-expectation accessor probe;
    # the rules:: token and the fn stay
    # on ONE line (the R1053 lesson)
    call = "rules::%s(%s)" % (fn, args)
    if len("            if (" + call
           + " != %d)" % val) <= 78:
        E.raw(["            if (" + call
               + " != %d)" % val,
               "                ++bad;"])
        return
    E.raw(["            if (" + call,
           "                != %d)" % val,
           "                ++bad;"])


def polarity_probe(E, fn, args, want_true):
    call = "rules::%s(%s)" % (fn, args)
    head = ("            if (!"
            if want_true
            else "            if (")
    E.raw([head + call + ")",
           "                ++bad;"])


def build_frag(p):
    E = Emit()
    P = E
    P("    // ==== R1055: subgates "
      "registry ===========")
    P("    // The R1055 de-wire: the 14")
    P("    // static arrays of rules/phb/")
    P("    // subclassgates.h ride")
    P("    // items::MiscItemRegistry from")
    P("    // content/tables/ph_subgates/ - 3")
    P("    // defs, 12 named tables; the R230")
    P("    // flat copies kAllow/kCap retire")
    P("    // ONTO the race tables - the")
    P("    // dedupe. Seven sections: load,")
    P("    // counts, qualify, race,")
    P("    // leveling, seam, edges. Census")
    P("    // 1089 -> 1096. DO NOT hand-edit:")
    P("    // tools/r1055_splice.py is the only")
    P("    // writer.")
    P("    {")
    P("        int bad = 0;")
    keys = DEF_KEYS
    # -- 1. load
    P("        // -- 1. load "
      "---------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            int n = reg.loadDirectory(")
    P("                \"content/tables/"
      "ph_subgates\");")
    P("            if (n != 3) ++bad;")
    P("            if (!reg.errors()."
      "empty()) ++bad;")
    P("            for (const auto& kv : "
      "reg.all())")
    P("                if ((int)kv.second."
      "sources.size() != 1")
    P("                    || kv.second."
      "sources[0].second != 1055)")
    P("                    ++bad;")
    for key in keys:
        P("            if (!reg.find("
          "\"%s\")) ++bad;" % key)
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[0])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 2. counts
    P("        // -- 2. counts "
      "--------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            reg.loadDirectory(")
    P("                \"content/tables/"
      "ph_subgates\");")
    for key in keys:
        tabs = def_table_list(key)
        n = len(SUB_ROWS)
        P("            {")
        P("                const items::"
          "MiscItemDef* d =")
        P("                    reg.find("
          "\"%s\");" % key)
        P("                if (!d) { ++bad; }"
          " else {")
        P("                    if ((int)d->rows."
          "size() != %d" % n)
        P("                        || (int)d->pins."
          "size() != 1")
        E.raw([
            "                        || d->pins[0]"
            ".name",
            "                            != "
            "\"%sRowCount\"" % key,
            "                        || d->pins[0]"
            ".value != %d" % n,
            "                        || (int)d->"
            "tables.size() != %d)"
            % len(tabs)])
        P("                        ++bad;")
        for i, (_, tag, cells, _, _) \
                in enumerate(tabs):
            P("                    if (d->tables"
              "[%d].name" % i)
            P("                        != "
              "\"%s\"" % tag)
            P("                        || (int)d->"
              "tables[%d]" % i)
            P("                            .values."
              "size() != %d)" % cells)
            P("                        ++bad;")
        for i in range(n):
            P("                    if (d->rows[%d]."
              "set" % i)
            P("                        != "
              "\"%s\"" % key)
            P("                        || d->rows"
              "[%d].bandLo != %d" % (i, i))
            P("                        || d->rows"
              "[%d].bandHi != %d)" % (i, i))
            P("                        ++bad;")
        for i, nm in enumerate(SUB_ROWS):
            row_probe(E, i, nm,
                      ind="    " * 4)
        P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[1])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 3. qualify
    P("        // -- 3. qualify "
      "---------------------------")
    P("        {")
    am = p["tabs"]["ability_min"]
    want_arr(P, want_name("ability_min"),
             am, ind="            ")
    P("            for (int s = 0; s < 6; ++s)")
    P("                for (int a = 0; a < 6;")
    P("                     ++a)")
    P("                    if (rules::"
      "subclassAbilityMin(")
    P("                            s, "
      "(rules::Ability)a)")
    P("                        != %s"
      % want_name("ability_min"))
    P("                            [s * 6 + a])")
    P("                        ++bad;")
    for tag in ("align_req", "xp_bonus"):
        vals = p["tabs"][tag]
        want_arr(P, want_name(tag), vals,
                 ind="            ")
        P("            for (int s = 0; s < 6; "
          "++s)")
        P("                if (rules::%s(s)"
          % ("subclassAlignmentReq"
             if tag == "align_req"
             else "subclassXpBonusRule"))
        P("                    != %s[s])"
          % want_name(tag))
        P("                    ++bad;")
    # the meetsAbilityMin mirror (DERIVED:
    # the pass vector = each ability at
    # max(min, 10) + 1; the fail vector =
    # the first required ability at min - 1)
    for s in range(6):
        row = am[s * 6:s * 6 + 6]
        E.raw(["            {"])
        E.raw(["                rules::"
               "AbilityScores s;"])
        for a in range(6):
            v = max(row[a], 10) + 1
            E.raw(["                s.set("
                   "(rules::Ability)%d, %d);"
                   % (a, v)])
        E.raw(["                if (!rules::"
               "subclassMeetsAbilityMin("])
        E.raw(["                        %d, s))"
               % s])
        E.raw(["                    ++bad;"])
        req = next(a for a in range(6)
                   if row[a] > 0)
        E.raw(["                s.set("
               "(rules::Ability)%d, %d);"
               % (req, row[req] - 1)])
        E.raw(["                if (rules::"
               "subclassMeetsAbilityMin("])
        E.raw(["                        %d, s))"
               % s])
        E.raw(["                    ++bad;"])
        E.raw(["            }"])
    # the xpBonusEarned mirror (DERIVED from
    # the parsed rule codes and the parsed
    # switch abilities: 16 passes, 15 fails;
    # a rule-less sub prints no bonus ever)
    for s in range(6):
        rule = p["tabs"]["xp_bonus"][s]
        abils = p["bonus_rules"].get(rule, [])
        E.raw(["            {"])
        E.raw(["                rules::"
               "AbilityScores s;"])
        for a in range(6):
            v = 16 if a in abils else 10
            E.raw(["                s.set("
                   "(rules::Ability)%d, %d);"
                   % (a, v)])
        if abils:
            E.raw(["                if (!rules::"
                   "subclassXpBonusEarned("])
            E.raw(["                        %d, s))"
                   % s])
            E.raw(["                    ++bad;"])
            a0 = abils[0]
            E.raw(["                s.set("
                   "(rules::Ability)%d, 15);"
                   % a0])
        E.raw(["                if (rules::"
               "subclassXpBonusEarned("])
        E.raw(["                        %d, s))"
               % s])
        E.raw(["                    ++bad;"])
        E.raw(["            }"])
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[2])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 4. race
    P("        // -- 4. race "
      "-------------------------------")
    P("        {")
    ra = p["tabs"]["race_allowed"]
    rc = p["tabs"]["race_cap"]
    want_arr(P, want_name("race_allowed"),
             ra, ind="            ")
    want_arr(P, want_name("race_cap"),
             rc, ind="            ")
    P("            for (int s = 0; s < 6; ++s)")
    P("                for (int r = 0; r < 7;")
    P("                     ++r) {")
    P("                    if (rules::"
      "subclassRaceAllowed(")
    P("                            s, "
      "(rules::CharRace)r)")
    P("                        != %s"
      % want_name("race_allowed"))
    P("                            [s * 7 + r])")
    P("                        ++bad;")
    # the dedupe dual-path: the R230
    # flat-copy accessors read the SAME
    # tables as the R180 accessors
    P("                    if (rules::"
      "subclassPlayerAllowed(")
    P("                            s, "
      "(rules::CharRace)r)")
    P("                        != %s"
      % want_name("race_allowed"))
    P("                            [s * 7 + r])")
    P("                        ++bad;")
    P("                    if (rules::"
      "subclassRaceCap(")
    P("                            s, "
      "(rules::CharRace)r)")
    P("                        != %s"
      % want_name("race_cap"))
    P("                            [s * 7 + r])")
    P("                        ++bad;")
    # the level-cap-for dual path skips
    # the gnome cell (the conditional)
    P("                    if (!(s == 3 "
      "&& r == 3) && (rules::"
      "subclassLevelCapFor(")
    P("                            s, "
      "(rules::CharRace)r,")
    P("                            18, 18)")
    P("                        != %s"
      % want_name("race_cap"))
    P("                            [s * 7 + r]))")
    P("                        ++bad;")
    P("                }")
    # the gnome conditional (DERIVED from
    # the parsed body: under 17 -> 5,
    # both at 17 -> 6; the base cell 7
    # never survives the footnote)
    g5, g6 = p["gnome"]
    probe_fn(E, "illusionistGnomeCap",
             "16, 10", g5)
    probe_fn(E, "illusionistGnomeCap",
             "17, 17", g6)
    probe_fn(E, "subclassRaceCap",
             "3, (rules::CharRace)3",
             rc[3 * 7 + 3])
    probe_fn(E, "subclassLevelCapFor",
             "3, (rules::CharRace)3,"
             " 16, 10", g5)
    probe_fn(E, "subclassLevelCapFor",
             "3, (rules::CharRace)3,"
             " 17, 17", g6)
    # the npc-only flag (DERIVED: a -n
    # cell and a plain cell)
    npc = next((s * 7 + r)
               for s in range(6)
               for r in range(7)
               if rc[s * 7 + r] <= -2)
    plain = next(s * 7 + r
                 for s in range(6)
                 for r in range(7)
                 if rc[s * 7 + r] >= 0)
    polarity_probe(
        E, "subclassCapIsNpcOnly",
        "%d, (rules::CharRace)%d"
        % (npc // 7, npc % 7), True)
    polarity_probe(
        E, "subclassCapIsNpcOnly",
        "%d, (rules::CharRace)%d"
        % (plain // 7, plain % 7), False)
    # the effective cap (DERIVED from the
    # parsed stop row and cap row; the
    # gnome cell excluded - the conditional
    # owns it)
    for s in range(6):
        for r in range(7):
            if s == 3 and r == 3:
                continue
            v = rc[s * 7 + r]
            if v > 0 and v < p["tabs"] \
                    ["level_stop"][s]:
                probe_fn(
                    E, "subclassLevelCapTotal",
                    "%d, (rules::CharRace)%d,"
                    " 18, 18" % (s, r), v)
                break
    for s in (0, 2):
        probe_fn(E, "subclassLevelCapTotal",
                 "%d, (rules::CharRace)0,"
                 " 18, 18" % s,
                 p["tabs"]["level_stop"][s])
    probe_fn(E, "subclassLevelCapTotal",
             "3, (rules::CharRace)3,"
             " 16, 10", g5)
    probe_fn(E, "subclassLevelCapTotal",
             "3, (rules::CharRace)3,"
             " 17, 17", g6)
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[3])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 5. leveling
    P("        // -- 5. leveling "
      "---------------------------")
    P("        {")
    hd = p["tabs"]["hit_die"]
    xl = p["tabs"]["xp_len"]
    xa = p["tabs"]["xp_attain"]
    xd = p["tabs"]["xp_add"]
    want_arr(P, want_name("hit_die"),
             hd, ind="            ")
    want_arr(P, want_name("xp_attain"),
             xa, ind="            ")
    P("            for (int s = 0; s < 6; ++s)")
    P("                if (rules::"
      "subclassHitDie(s)")
    P("                    != %s[s])"
      % want_name("hit_die"))
    P("                    ++bad;")
    # the printed rows 2..n, then the
    # adder rows n+1 and n+2 (DERIVED:
    # adder 0 repeats the top row)
    for s in range(6):
        n = xl[s]
        top = xa[s * 17 + n - 1]
        add = xd[s]
        b1 = top + add
        b2 = top + 2 * add
        P("            {")
        P("                for (int lvl = 2;"
          " lvl <= %d;" % n)
        P("                     ++lvl)")
        P("                    if (rules::"
          "subclassXpToAttain(")
        P("                            %d, lvl)"
          % s)
        P("                        != %s"
          % want_name("xp_attain"))
        P("                            [%d +"
          " lvl - 1])" % (s * 17))
        P("                        ++bad;")
        probe_fn(E, "subclassXpToAttain",
                 "%d, %d" % (s, n + 1), b1)
        probe_fn(E, "subclassXpToAttain",
                 "%d, %d" % (s, n + 2), b2)
        P("            }")
    for tag, fn in (
            ("fixed_hp_level",
             "subclassFixedHpLevel"),
            ("hp_beyond_fixed",
             "subclassHpBeyondFixed"),
            ("level_stop",
             "subclassLevelStop")):
        vals = p["tabs"][tag]
        want_arr(P, want_name(tag), vals,
                 ind="            ")
        P("            for (int s = 0; s < 6; "
          "++s)")
        P("                if (rules::%s(s)"
          % fn)
        P("                    != %s[s])"
          % want_name(tag))
        P("                    ++bad;")
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[4])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 6. seam: the raw registry
    # cross-read against the accessors
    # (dual-path diff; every loop scoped
    # to its own def block - the R1054
    # class-13 lesson)
    P("        // -- 6. seam "
      "---------------------------------")
    P("        {")
    P("            items::"
      "MiscItemRegistry reg;")
    P("            reg.loadDirectory(")
    P("                \"content/tables/"
      "ph_subgates\");")
    for key in keys:
        tabs = def_table_list(key)
        P("            {")
        P("                const items::"
          "MiscItemDef* d =")
        P("                    reg.find("
          "\"%s\");" % key)
        P("                if (!d) ++bad;")
        for (_, tag, cells, kind, fns) \
                in tabs:
            if tag in ("xp_len", "xp_add"):
                # no direct accessor; pinned
                # by the derived adder probes
                continue
            P("                {")
            P("                    int got = 0;")
            if tag == "xp_attain":
                # the walk bound rides the
                # registry's own xp_len row
                P("                    int lens[6]"
                  " = { %s };"
                  % ", ".join(str(v)
                              for v in
                              p["tabs"]
                              ["xp_len"]))
                P("                    for (const"
                  " auto& t2 : d->tables)")
                P("                        if (t2.name"
                  " == \"xp_len\")")
                P("                            "
                  "for (int s = 0; s < 6;")
                P("                                 "
                  "++s)")
                P("                                "
                  "lens[s] ="
                  " (int)t2.values[s];")
            P("                    for (const "
              "auto& t : d->tables) {")
            P("                        if (t.name"
              " != \"%s\")" % tag)
            P("                            "
              "continue;")
            P("                        got = 1;")
            if tag == "ability_min":
                P("                        "
                  "for (int s = 0; s < 6;")
                P("                             "
                  "++s)")
                P("                            "
                  "for (int a = 0;")
                P("                                 "
                  "a < 6;")
                P("                                 "
                  "++a)")
                P("                                "
                  "if ((int)t")
                P("                                    "
                  ".values[")
                P("                                    "
                  "s * 6 + a]")
                P("                                    "
                  "!=")
                P("                                    "
                  "rules::"
                  "subclassAbilityMin(")
                P("                                        "
                  "s,")
                P("                                        "
                  "(rules::"
                  "Ability)a))")
                P("                                    "
                  "++bad;")
            elif tag == "race_allowed":
                P("                        "
                  "for (int s = 0; s < 6;")
                P("                             "
                  "++s)")
                P("                            "
                  "for (int r = 0;")
                P("                                 "
                  "r < 7;")
                P("                                 "
                  "++r) {")
                P("                                "
                  "if ((int)t")
                P("                                    "
                  ".values[")
                P("                                    "
                  "s * 7 + r]")
                P("                                    "
                  "!=")
                P("                                    "
                  "rules::"
                  "subclassRaceAllowed(")
                P("                                        "
                  "s,")
                P("                                        "
                  "(rules::"
                  "CharRace)r))")
                P("                                    "
                  "++bad;")
                # the dedupe dual path
                P("                                "
                  "if ((int)t")
                P("                                    "
                  ".values[")
                P("                                    "
                  "s * 7 + r]")
                P("                                    "
                  "!=")
                P("                                    "
                  "rules::"
                  "subclassPlayerAllowed(")
                P("                                        "
                  "s,")
                P("                                        "
                  "(rules::"
                  "CharRace)r))")
                P("                                    "
                  "++bad;")
                P("                            }")
            elif tag == "race_cap":
                P("                        "
                  "for (int s = 0; s < 6;")
                P("                             "
                  "++s)")
                P("                            "
                  "for (int r = 0;")
                P("                                 "
                  "r < 7;")
                P("                                 "
                  "++r)")
                P("                                "
                  "if (!(s == 3 && r == 3)")
                P("                                    "
                  "&& ((int)t")
                P("                                        "
                  ".values[")
                P("                                        "
                  "s * 7 + r]")
                P("                                        "
                  "!=")
                P("                                        "
                  "rules::"
                  "subclassLevelCapFor(")
                P("                                            "
                  "s,")
                P("                                            "
                  "(rules::"
                  "CharRace)r,")
                P("                                            "
                  "18, 18)))")
                P("                                    "
                  "++bad;")
            elif tag == "xp_attain":
                P("                        "
                  "for (int s = 0; s < 6;")
                P("                             "
                  "++s)")
                P("                            "
                  "for (int lvl = 2;")
                P("                                 "
                  "lvl <= lens[s];")
                P("                                 "
                  "++lvl)")
                P("                                "
                  "if ((int)t")
                P("                                    "
                  ".values[")
                P("                                    "
                  "s * 17 + lvl")
                P("                                    "
                  " - 1]")
                P("                                    "
                  "!=")
                P("                                    "
                  "rules::"
                  "subclassXpToAttain(")
                P("                                        "
                  "s, lvl))")
                P("                                    "
                  "++bad;")
            else:
                P("                        "
                  "for (int s = 0; s < 6;")
                P("                             "
                  "++s)")
                P("                            "
                  "if ((int)t")
                P("                                "
                  ".values[s]")
                P("                                "
                  "!=")
                P("                                "
                  "rules::%s("
                  % fns[0])
                P("                                    s))")
                P("                                "
                  "++bad;")
            P("                    }")
            P("                    if (!got) "
              "++bad;")
            P("                }")
        P("            }")
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[5])
    P("        if (bad) return 1;")
    P("        bad = 0;")
    # -- 7. edges: every probe DERIVED
    # from the parse (the last section
    # carries NO guard)
    P("        // -- 7. edges "
      "--------------------------------")
    P("        {")
    am = p["tabs"]["ability_min"]
    ra = p["tabs"]["race_allowed"]
    rc = p["tabs"]["race_cap"]
    # the sub clamps: -1 reads row 0,
    # 6 reads row 5 (DERIVED)
    probe_fn(E, "subclassAbilityMin",
             "-1, (rules::Ability)0",
             am[0])
    probe_fn(E, "subclassAbilityMin",
             "6, (rules::Ability)5",
             am[5 * 6 + 5])
    probe_fn(E, "subclassAlignmentReq",
             "-1", p["tabs"]["align_req"][0])
    probe_fn(E, "subclassAlignmentReq",
             "6", p["tabs"]["align_req"][5])
    probe_fn(E, "subclassXpBonusRule",
             "-1", p["tabs"]["xp_bonus"][0])
    probe_fn(E, "subclassXpBonusRule",
             "6", p["tabs"]["xp_bonus"][5])
    probe_fn(E, "subclassHitDie",
             "-1", p["tabs"]["hit_die"][0])
    probe_fn(E, "subclassHitDie",
             "6", p["tabs"]["hit_die"][5])
    probe_fn(E, "subclassFixedHpLevel",
             "-1",
             p["tabs"]["fixed_hp_level"][0])
    probe_fn(E, "subclassFixedHpLevel",
             "6",
             p["tabs"]["fixed_hp_level"][5])
    probe_fn(E, "subclassHpBeyondFixed",
             "-1",
             p["tabs"]["hp_beyond_fixed"][0])
    probe_fn(E, "subclassHpBeyondFixed",
             "6",
             p["tabs"]["hp_beyond_fixed"][5])
    probe_fn(E, "subclassLevelStop",
             "-1", p["tabs"]["level_stop"][0])
    probe_fn(E, "subclassLevelStop",
             "6", p["tabs"]["level_stop"][5])
    # the race clamps: unknown race
    # reads 0 (DERIVED from the clamps)
    probe_fn(E, "subclassRaceAllowed",
             "0, (rules::CharRace)7", 0)
    probe_fn(E, "subclassRaceAllowed",
             "0, (rules::CharRace)-1", 0)
    probe_fn(E, "subclassRaceCap",
             "0, (rules::CharRace)7", 0)
    probe_fn(E, "subclassPlayerAllowed",
             "-1, (rules::CharRace)-1",
             ra[0])
    probe_fn(E, "subclassPlayerAllowed",
             "6, (rules::CharRace)7",
             ra[5 * 7 + 6])
    probe_fn(E, "subclassLevelCapFor",
             "-1, (rules::CharRace)-1,"
             " 18, 18", rc[0])
    probe_fn(E, "subclassLevelCapFor",
             "6, (rules::CharRace)7,"
             " 18, 18", rc[5 * 7 + 6])
    probe_fn(E, "subclassAbilityMin",
             "0, (rules::Ability)6", 0)
    probe_fn(E, "subclassAbilityMin",
             "0, (rules::Ability)-1", 0)
    # the xp ladder floor (level <= 1
    # reads 0 for every subclass)
    for s in range(6):
        probe_fn(E, "subclassXpToAttain",
                 "%d, 0" % s, 0)
        probe_fn(E, "subclassXpToAttain",
                 "%d, 1" % s, 0)
    # the if-chains: every sub value
    # from the parsed model (incl the
    # default at 6)
    for fn in CHAIN_FNS:
        ch = p["chains"][fn]
        for s in range(7):
            v = ch.get(s, ch["dfl"])
            probe_fn(E, fn, str(s), v)
    P("        }")
    P("        printf(\"%s audit: "
      "bad %%d\\\\n\", bad);"
      % LABELS[6])
    P("    }")
    return "\n".join(E.lines)


# ---- the self-scan --------------------------
# Nothing is written until the emitted
# fragment, seam and lua pass every
# structural and parity check.

def self_scan(frag, seam, luas, p):
    # fragment shape
    if frag.count("printf(") != 7:
        die("self-scan: printf count")
    if frag.count("audit: bad %d") != 7:
        die("self-scan: census pattern count")
    if frag.count("if (bad) return 1;") != 6:
        die("self-scan: guard count")
    if frag.count("\n        bad = 0;") != 6:
        die("self-scan: bad resets")
    for lbl in LABELS:
        if frag.count(lbl) != 1:
            die("self-scan: label " + lbl)
    # the balance checks run on
    # comment-stripped code (header
    # comments may carry parens)
    fbal = re.sub(r"//[^\n]*", "", frag)
    if fbal.count("(") != fbal.count(")"):
        die("self-scan: code paren balance")
    if fbal.count("{") != fbal.count("}"):
        die("self-scan: code brace balance")
    # seat shape
    for tok in ("#include", "#pragma",
                "namespace", "inline",
                "std::map", "std::set",
                "std::sort"):
        if tok in frag:
            die("self-scan: %s at the seat" % tok)
    # cols (banner lines exempt)
    for line in frag.splitlines():
        if line.startswith("    // ===="):
            continue
        if len(line.rstrip()) > 78:
            die("self-scan: cols " + repr(line[:50]))
    # fused tokens
    if re.search(r"[A-Za-z0-9_](?:rules|items)::", frag):
        die("self-scan: fused token")
    if re.search(r"\bconst(?=[A-Za-z_])", frag):
        die("self-scan: fused const")
    # rules:: qualification of every
    # accessor token (first occurrence)
    fcode = re.sub(r"//[^\n]*", "", frag)
    for tk in ALL_FNS:
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("rules::"):
                die("self-scan: " + tk + " unqualified")
            break
    for tk in ("MiscItemRegistry",
               "MiscItemDef"):
        for m in re.finditer(
                r"(?<![\w:])" + tk + r"(?![\w:])",
                fcode):
            if not fcode[:m.start()].endswith("items::"):
                die("self-scan: " + tk + " not items::")
    # find targets AS SETS
    if sorted(set(re.findall(
            r'reg\.find\("(\w+)"\)', frag))) \
            != sorted(DEF_KEYS):
        die("self-scan: find targets")
    # want arrays: values parity vs the
    # parse (NEGATIVE cells included)
    for tag in WANT_TAGS:
        wn = want_name(tag)
        m = re.search(
            r"const int " + wn +
            r"\[\] = \{([-\d\s,]+)\};", frag)
        if not m:
            die("self-scan: want " + wn + " missing")
        got = [int(v) for v in
               re.findall(r"-?\d+", m.group(1))]
        if got != p["tabs"][tag]:
            die("self-scan: want " + wn + " parity")
    # row-name probes: every row of
    # every def appears in exactly one
    # literal probe IN THAT DEF'S BLOCK
    parts = re.split(
        r'(?=reg\.find\("\w+"\))', frag)
    blocks = {}
    for part in parts:
        m = re.search(
            r'reg\.find\("(\w+)"\)', part)
        if m:
            blocks.setdefault(m.group(1), "")
            blocks[m.group(1)] += part
    for key in DEF_KEYS:
        for i, nm in enumerate(SUB_ROWS):
            c = len(re.findall(
                r'd->rows\[' + str(i) +
                r'\]\.name\)\s*!= "' +
                nm + r'"\)',
                blocks.get(key, "")))
            if c != 1:
                die("self-scan: row probe "
                    + key + " " + nm)
    # the walk probes: every table
    # walked once through its owner
    # (wrap-agnostic regexes)
    def probe_rx(rx):
        if re.search(rx, frag) is None:
            die("self-scan: probe missing " + rx[:60])
    probe_rx(r"rules::subclassAbilityMin\("
             r"\s*s,\s*\(rules::Ability\)a\)")
    probe_rx(r"rules::subclassRaceAllowed\("
             r"\s*s,\s*\(rules::CharRace\)r\)")
    probe_rx(r"rules::subclassPlayerAllowed\("
             r"\s*s,\s*\(rules::CharRace\)r\)")
    probe_rx(r"rules::subclassRaceCap\("
             r"\s*s,\s*\(rules::CharRace\)r\)")
    probe_rx(r"rules::subclassLevelCapFor\("
             r"\s*s,\s*\(rules::CharRace\)r,")
    probe_rx(r"rules::subclassXpToAttain\("
             r"\s*\d+,\s*lvl\)")
    for tag, fn in (
            ("align_req",
             "subclassAlignmentReq"),
            ("xp_bonus",
             "subclassXpBonusRule"),
            ("hit_die", "subclassHitDie"),
            ("fixed_hp_level",
             "subclassFixedHpLevel"),
            ("hp_beyond_fixed",
             "subclassHpBeyondFixed"),
            ("level_stop",
             "subclassLevelStop")):
        probe_rx(r"rules::" + fn +
                 r"\(\s*s\)\s*!=\s*"
                 + want_name(tag) + r"\[s\]")
    # the clamp probes (DERIVED bounds)
    probe_rx(r"rules::subclassAbilityMin\("
             r"\s*-1,\s*\(rules::Ability\)0\)"
             r"\s*!=\s*%d\)"
             % p["tabs"]["ability_min"][0])
    probe_rx(r"rules::subclassRaceAllowed\("
             r"\s*0,\s*\(rules::CharRace\)7\)"
             r"\s*!=\s*0\)")
    probe_rx(r"rules::subclassXpToAttain\("
             r"\s*0,\s*0\)\s*!=\s*0\)")
    # the meets mirror: one pass and one
    # fail probe per subclass (polarity
    # probes - if (!fn) / if (fn))
    for s in range(6):
        if len(re.findall(
                r"rules::"
                r"subclassMeetsAbilityMin\("
                r"\s*%d, s\)\)" % s,
                frag)) != 2:
            die("self-scan: meets mirror "
                + str(s))
    # the bonus mirror: one earned-false
    # probe per subclass, and a true
    # probe for every rule-carrying sub
    for s in range(6):
        n_true = len(re.findall(
            r"!rules::"
            r"subclassXpBonusEarned\("
            r"\s*%d, s\)\)" % s, frag))
        n_false = len(re.findall(
            r"if \(rules::"
            r"subclassXpBonusEarned\("
            r"\s*%d, s\)\)" % s, frag))
        rule = p["tabs"]["xp_bonus"][s]
        want_t = 1 if p["bonus_rules"].get(
            rule) else 0
        if n_true != want_t or n_false != 1:
            die("self-scan: bonus mirror "
                + str(s))
    # the if-chain probes: every value
    # 0..6 probed per chain fn
    for fn in CHAIN_FNS:
        ch = p["chains"][fn]
        for s in range(7):
            v = ch.get(s, ch["dfl"])
            probe_rx(r"rules::" + fn +
                     r"\(\s*" + str(s) +
                     r"\)\s*!=\s*" + str(v)
                     + r"\)")
    # the gnome conditional probes
    g5, g6 = p["gnome"]
    probe_rx(r"rules::illusionistGnomeCap\("
             r"\s*16,\s*10\)\s*!=\s*%d\)"
             % g5)
    probe_rx(r"rules::illusionistGnomeCap\("
             r"\s*17,\s*17\)\s*!=\s*%d\)"
             % g6)
    # seam checks
    if seam.count(APPLIED_MARK) != 1:
        die("self-scan: mark count")
    if ('#include "items/MiscItemRegistry.h"'
            not in seam):
        die("self-scan: registry include")
    if re.search(r"static const ", seam):
        die("self-scan: a static array survived")
    for tok in ("gtReg()", "gtTable("):
        if tok not in seam:
            die("self-scan: seam fn missing " + tok)
    # the call sites pin their def key and
    # tag; the dedupe tables carry TWO
    # sites each, the rest ONE
    for (key, tag, cells, kind, fns) in TABLES:
        want = len(set(fns))
        if tag in ("xp_len", "xp_attain",
                   "xp_add"):
            want = 1  # subclassXpToAttain
        n = seam.count('"%s", "%s\");'
                       % (key, tag))
        if n != want:
            die("self-scan: site count %s: "
                "%d, want %d"
                % (tag, n, want))
    # the clamps survived the rewrite
    for ln in ("if (sub < 0) sub = 0;",
               "if ((int)ab < 0",
               "if ((int)r < 0",
               "if (si < 0) si = 0;",
               "if (ri < 0) ri = 0;",
               "if (level <= 1) return 0;"):
        if ln not in seam:
            die("self-scan: clamp lost " + ln)
    if seam.count("if (sub >= SUB_COUNT)") != 5:
        die("self-scan: sub clamp count")
    if seam.count("if (si > 5) si = 5;") != 7:
        die("self-scan: si clamp count")
    if seam.count("if (!g) return") != 11:
        die("self-scan: fallback count %d"
            % seam.count("if (!g) return"))
    if seam.count("if (!gx) return") != 1:
        die("self-scan: gx fallback count")
    if seam.count("[sub * 6 + (int)ab];") != 1:
        die("self-scan: ability index count")
    if seam.count("[sub * 7 + (int)r];") != 2:
        die("self-scan: race index count")
    if seam.count("[si * 7 + ri];") != 2:
        die("self-scan: flat race index count")
    if seam.count("[si * 17 +") != 2:
        die("self-scan: xp index count")
    # lua checks
    for key in DEF_KEYS:
        x = luas[key]
        tabs = def_table_list(key)
        n = len(SUB_ROWS)
        if ('key = "%s"' % key) not in x:
            die("self-scan: lua key " + key)
        if "round = 1055" not in x:
            die("self-scan: lua round " + key)
        if x.count("band = { ") != n:
            die("self-scan: lua row count " + key)
        if ('name = "%sRowCount"' % key) not in x:
            die("self-scan: lua pin " + key)
        for nm in SUB_ROWS:
            if ('name = "%s",' % nm) not in x:
                die("self-scan: lua row " + nm)
        for (_, tag, cells, _, _) in tabs:
            if ('name = "%s",' % tag) not in x:
                die("self-scan: lua table " + tag)
            m = re.search(
                r'name = "' + tag +
                r'",\s*values = \{([-\d\s,]+)\}', x)
            if not m:
                die("self-scan: lua values " + tag)
            got = [int(v) for v in
                   re.findall(r"-?\d+", m.group(1))]
            if got != p["tabs"][tag]:
                die("self-scan: lua value parity " + tag)


# ---- main -----------------------------------

def main():
    if not os.path.isfile(
            os.path.join(ROOT, REGTEST)) \
            or not os.path.isfile(
                os.path.join(ROOT, HEAD)):
        die("run me from the repo root")
    src = open(os.path.join(ROOT, HEAD)).read()
    if APPLIED_MARK in src:
        print("applied 0, already 1")
        print("SPLICE OK")
        return
    c0 = census_count()
    if c0 != CENSUS_BEFORE:
        die("census %d, want %d"
            % (c0, CENSUS_BEFORE))
    p = parse_pristine(src)
    luas = build_lua(p)
    seam = build_seam(src, p)
    frag = build_frag(p)
    self_scan(frag, seam, luas, p)
    # the regtest seat
    rt = open(os.path.join(ROOT, REGTEST)).read()
    if INC_ANCHOR not in rt:
        die("R1054 include anchor not found in regtest.cpp")
    before = rt.splitlines()
    at = before.index(
        [l for l in before if INC_ANCHOR in l][0])
    if at != 1302:
        die("R1054 include at line %d, want 1303"
            % (at + 1))
    rt = rt.replace(INC_ANCHOR + "\n",
                    INC_ANCHOR + "\n" + INC_LINE + "\n", 1)
    # write everything
    os.makedirs(os.path.join(ROOT, LUA_DIR),
                exist_ok=True)
    for key, txt in luas.items():
        open(os.path.join(ROOT, LUA_DIR, key + ".lua"),
             "w").write(txt)
    open(os.path.join(ROOT, FRAG), "w").write(frag + "\n")
    open(os.path.join(ROOT, HEAD), "w").write(seam)
    open(os.path.join(ROOT, REGTEST), "w").write(rt)
    c1 = census_count()
    if c1 != CENSUS_AFTER:
        die("post census %d, want %d"
            % (c1, CENSUS_AFTER))
    print("census %d -> %d audit printf patterns"
          % (c0, c1))
    print("applied 1, rewrote 2 tracked files, "
          "wrote 4 new files")
    print("SPLICE OK")


if __name__ == "__main__":
    main()
