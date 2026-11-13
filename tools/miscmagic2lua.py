#!/usr/bin/env python3
# tools/miscmagic2lua.py - the A1 data-only land of the misc magic lua
# promotion: the 23 III.E explanation prose part headers
# (rules/dmg/miscmagic_prose_part1..23.h, R257-R279) promote to 166
# item defs in content/magic_items/<letter>/ (one .lua per roster
# item, bucketed by first letter the content/monsters way; the 16
# sub-items - 9 figurines of wondrous power, 7 bard instruments -
# nest inside their parent defs).
#
# The headers retired to boneyard/dmg/ in R1027 (the A2 de-wire):
# they remain the print-fidelity record - this tool still reads
# them there - but the build no longer compiles them; the defs go
# live through items/MiscItemRegistry, audited by the R1027
# registry audit fragment.
#
# Pure stdlib. Idempotent: run 1 PROMOTE (writes the defs, then
# verifies), run 2 VERIFY (same gates, byte-compares the on-disk
# defs). Dies loudly (RED) on anything unexpected. PROMOTE also
# migrates defs found at the legacy flat content/magic_items/ root
# into their letter dirs (pure os.replace, bytes untouched).

import os
import re
import sys

RED = "\033[31m"
OFF = "\033[0m"


def FAIL(msg):
    print(RED + "PROMOTE RED: " + msg + OFF)
    sys.exit(1)


def repo_root():
    d = os.getcwd()
    if not os.path.isfile(os.path.join(d, "regtest.cpp")):
        FAIL("run from the repo root (regtest.cpp not found in cwd)")
    return d


ROOT = repo_root()
MISC = os.path.join(ROOT, "content", "magic_items")


def def_dir(stem):
    """content/magic_items/<first letter>/ - the monsters layout."""
    return os.path.join(MISC, stem[0])


def def_path(stem):
    """The one legal on-disk location of stem's def."""
    return os.path.join(def_dir(stem), stem + ".lua")


def legacy_path(stem):
    """The pre-letter-layout flat location (PROMOTE migrates)."""
    return os.path.join(MISC, stem + ".lua")


def scan_phantoms(stems):
    """Everything under content/magic_items/ that is not a known
    def at its letter-dir path (or a legacy flat def of a known
    stem, which PROMOTE migrates): unknown .lua stems, stray
    files, non-letter dirs, unknown entries inside letter dirs.
    An empty letter dir of the roster's letters is fine (PROMOTE
    refills it); an empty dir of any other letter is a phantom."""
    phantoms = []
    if not os.path.isdir(MISC):
        return phantoms
    letters = {s[0] for s in stems}
    for e in sorted(os.listdir(MISC)):
        p = os.path.join(MISC, e)
        if os.path.isfile(p):
            if e.endswith(".lua") and e[:-4] in stems:
                continue  # legacy flat def, PROMOTE migrates it
            phantoms.append(e)
        else:
            if len(e) != 1 or not "a" <= e <= "z":
                phantoms.append(e + "/")
                continue
            entries = sorted(os.listdir(p))
            if not entries:
                if e in letters:
                    continue  # emptied by a delete, PROMOTE refills
                phantoms.append(e + "/ (empty)")
            for f in entries:
                if os.path.isfile(os.path.join(p, f)):
                    if not f.endswith(".lua") or f[:-4] not in stems:
                        phantoms.append(e + "/" + f)
                else:
                    phantoms.append(e + "/" + f + "/")
    return phantoms


# ---- header parsing -----------------------------------------------------

def parse_headers():
    """Parse the 23 part headers -> {method: (kind, comment, payload)}.

    kind 's': payload = int scalar.  kind 'a': payload = int list.
    All 1452 functions must be a bare scalar return or a
    static-array index walker; anything else dies loudly."""
    out = {}
    for n in range(1, 24):
        path = os.path.join(ROOT, "boneyard", "dmg",
                            "miscmagic_prose_part%d.h" % n)
        if not os.path.isfile(path):
            FAIL("missing part header: %s" % path)
        src = open(path).read()
        fn_re = re.compile(
            r"^inline\s+int\s+(mmp\w+)\s*\(([^)]*)\)\s*\{\n(.*?)\n\}",
            re.M | re.S)
        found = fn_re.findall(src)
        if not found:
            FAIL("no functions parsed from %s" % path)
        for name, args, body in found:
            if name in out:
                FAIL("duplicate function %s (part %d)" % (name, n))
            args = args.strip()
            lines = body.split("\n")
            comment = []
            code = []
            for ln in lines:
                t = ln.strip()
                if t.startswith("//"):
                    comment.append(t[2:].strip())
                elif t == "":
                    continue  # blank lines may interleave anywhere
                else:
                    code.append(t)
            text = " ".join(comment)
            rest = "\n".join(code)
            if args == "" and re.fullmatch(r"return\s+(-?\d+)\s*;", rest):
                out[name] = ("s", text,
                             int(rest.split()[1].rstrip(";")), None)
            elif args == "int i":
                # walkers may carry the standard index clamp pair
                # (if (i < 0) i = 0; if (i > K) i = K;) - the clamp is
                # recorded as data (clamp_hi); raw walkers have none
                clamp_hi = None
                mlo = re.match(r"if\s+\(i\s*<\s*0\)\s*i\s*=\s*0;\s*", rest)
                if mlo:
                    rest = rest[mlo.end():]
                    mhi = re.match(
                        r"if\s+\(i\s*>\s*(\d+)\)\s*i\s*=\s*\1;\s*", rest)
                    if not mhi:
                        FAIL("clamp low without matching high in %s:\n%s"
                             % (name, rest))
                    clamp_hi = int(mhi.group(1))
                    rest = rest[mhi.end():]
                m = re.fullmatch(
                    r"static\s+const\s+int\s+t\[(\d+)\]\s*=\s*\{([^}]*)\};"
                    r"\s*return\s+t\[i\]\s*;", rest, re.S)
                if not m:
                    FAIL("unparseable walker body in %s:\n%s" % (name, rest))
                cnt = int(m.group(1))
                vals = [int(x) for x in
                        m.group(2).replace("\n", " ").split(",")
                        if x.strip()]
                if cnt != len(vals):
                    FAIL("walker %s: declared %d, parsed %d"
                         % (name, cnt, len(vals)))
                if clamp_hi is not None and clamp_hi != cnt - 1:
                    FAIL("walker %s: clamp_hi %d != len-1 %d"
                         % (name, clamp_hi, cnt - 1))
                out[name] = ("a", text, vals, clamp_hi)
            else:
                FAIL("unexpected function form %s (args %r)" % (name, args))
    return out


def parse_kmisc():
    """dm/treasure.cpp kMisc1-5 -> {stem: [row,...]}, Artifact excluded."""
    path = os.path.join(ROOT, "dm", "treasure.cpp")
    if not os.path.isfile(path):
        FAIL("missing dm/treasure.cpp")
    src = open(path).read()

    def norm(name):
        s = name.lower()
        s = re.sub(r"\(.*?\)", "", s)
        s = re.sub(r"[',.&/]", "", s)
        return "_".join(s.split())

    alias_norm = {norm(k): v for k, v in ALIASES.items()}
    rows = {}
    total = 0
    for n in range(1, 6):
        m = re.search(r"kMisc%d\[\] = \{(.*?)\n\};" % n, src, re.S)
        if not m:
            FAIL("kMisc%d not found in dm/treasure.cpp" % n)
        for r in re.finditer(
                r"\{\s*(\d+),(\d+),\s*\"([^\"]+)\",\s*"
                r"(\d+),(\d+),\s*(\d+),(\d+),\s*(\d+),(\d+)\s*\}",
                m.group(1)):
            lo, hi, name, xp, xph, gp, gph, qlo, qhi = r.groups()
            total += 1
            if name == "Artifact or Relic":
                continue
            stem = alias_norm.get(norm(name), norm(name))
            rows.setdefault(stem, []).append({
                "set": "kMisc%d" % n,
                "band": [int(lo), int(hi)],
                "name": name,
                "xp": int(xp), "xp_hi": int(xph),
                "gp": int(gp), "gp_hi": int(gph),
                "qty": [int(qlo), int(qhi)],
            })
    if total != 167:
        FAIL("kMisc1-5 row count %d != 167" % total)
    return rows


# ---- lua emission -------------------------------------------------------

def lstr(s):
    """Escape a python str as a lua double-quoted string."""
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def q(text, indent0, budget):
    """A lua string expression for a `comment = ` field: one line if it
    fits, else quoted chunks joined with ' .. ' (each non-final chunk
    keeps its trailing space; the budget reserves room for the entry
    closer that the caller appends to the last line)."""
    if indent0 + 10 + len(text) + 2 <= budget:
        return [lstr(text)]
    words = text.split(" ")
    chunks = []
    cur = ""
    for w in words:
        cand = (cur + " " + w) if cur else w
        if cur and indent0 + 10 + len(cand) + 2 > budget:
            chunks.append(cur + " ")
            cur = w
        else:
            cur = cand
    chunks.append(cur)
    out = [lstr(chunks[0])]
    for c in chunks[1:]:
        out.append(" " * indent0 + ".. " + lstr(c))
    return out


def emit_int_list(vals, indent):
    """An int list wrapped at ~74 cols (trailing commas are fine in
    lua table constructors)."""
    pad = " " * indent
    lines = []
    cur = pad
    for v in vals:
        add = str(v) if cur == pad else ", " + str(v)
        if cur != pad and len(cur) + len(add) > 74:
            lines.append(cur + ",")
            cur = pad + "  " + str(v)
        else:
            cur += add
    lines.append(cur + ",")
    return lines


def emit_pin(entry, indent):
    name, kind, text, payload, clamp = entry
    """One entry; kind 's' -> pins[] (value), 'a' -> tables[] (values)."""
    if kind == "s":
        head = " " * indent + "{ name = %s, value = %d" \
            % (lstr(name), payload)
        if not text:
            return [head + " },"]
        out = [head + ","]
        cmt = q(text, indent + 2, 71)
        out.append(" " * (indent + 2) + "comment = " + cmt[0])
        out.extend(cmt[1:])
        out[-1] += " },"
        return out
    out = [" " * indent + "{ name = %s," % lstr(name)]
    if text:
        cmt = q(text, indent + 2, 73)
        out.append(" " * (indent + 2) + "comment = " + cmt[0])
        out.extend(cmt[1:])
        out[-1] += ","
    if clamp is not None:
        out.append(" " * (indent + 2) + "clamp_hi = %d," % clamp)
    out.append(" " * (indent + 2) + "values = {")
    out.extend(emit_int_list(payload, indent + 4))
    out.append(" " * (indent + 2) + "} },")
    return out


def emit_def(stem, name, rowlist, sources, scalars, walkers, subs):
    """One item def: the full .lua file text."""
    L = []
    L.append("-- misc magic item def: %s" % stem)
    L.append("-- promoted from the III.E explanation prose part headers:")
    for part, rno in sources:
        L.append("--   boneyard/dmg/miscmagic_prose_part%d.h (R%d)"
                 % (part, rno))
    L.append("-- The part headers remain in boneyard/dmg/ as the")
    L.append("-- print-fidelity record. DO NOT hand-edit this file; the")
    L.append("-- part header pins are the adjudicated record.")
    L.append("-- (tools/miscmagic2lua.py is the only writer.)")
    L.append("return {")
    L.append("  key = %s," % lstr(stem))
    L.append("  name = %s," % lstr(name))
    if rowlist:
        L.append("  rows = {")
        for r in rowlist:
            L.append("    { name = %s," % lstr(r["name"]))
            L.append("      set = %s, band = { %d, %d }, xp = %d,"
                     " xp_hi = %d,"
                     % (lstr(r["set"]), r["band"][0], r["band"][1],
                        r["xp"], r["xp_hi"]))
            L.append("      gp = %d, gp_hi = %d, qty = { %d, %d } },"
                     % (r["gp"], r["gp_hi"], r["qty"][0], r["qty"][1]))
        L.append("  },")
    L.append("  sources = {")
    for part, rno in sources:
        L.append("    { part = %d, round = %d }," % (part, rno))
    L.append("  },")
    L.append("  pins = {")
    for entry in scalars:
        L.extend(emit_pin(entry, 4))
    L.append("  },")
    L.append("  tables = {")
    for entry in walkers:
        L.extend(emit_pin(entry, 4))
    L.append("  },")
    if subs:
        L.append("  subs = {")
        for sub in subs:
            L.append("    {")
            L.append("      key = %s," % lstr(sub["key"]))
            L.append("      name = %s," % lstr(sub["name"]))
            L.append("      sources = {")
            for part, rno in sub["sources"]:
                L.append("        { part = %d, round = %d }," % (part, rno))
            L.append("      },")
            L.append("      pins = {")
            for entry in sub["scalars"]:
                L.extend(emit_pin(entry, 8))
            L.append("      },")
            L.append("      tables = {")
            for entry in sub["walkers"]:
                L.extend(emit_pin(entry, 8))
            L.append("      },"+"")
            L.append("    },")
        L.append("  },")
    L.append("}")
    return "\n".join(L) + "\n"


# ---- main ---------------------------------------------------------------

def main():
    parsed = parse_headers()
    if len(parsed) != TOTAL_METHODS:
        FAIL("parsed %d functions, expected %d"
             % (len(parsed), TOTAL_METHODS))
    npsc = sum(1 for v in parsed.values() if v[0] == "s")
    npwa = sum(1 for v in parsed.values() if v[0] == "a")
    if npsc != SCALAR_COUNT or npwa != WALKER_COUNT:
        FAIL("parsed %d scalars / %d walkers, expected %d / %d"
             % (npsc, npwa, SCALAR_COUNT, WALKER_COUNT))

    rows = parse_kmisc()

    sub_stems = set()
    for parent, kids in SUBS.items():
        sub_stems.update(kids)
    def_stems = [s for s in ORDER if s not in sub_stems]
    if len(ORDER) != 182:
        FAIL("ORDER holds %d stems, expected 182" % len(ORDER))
    if len(def_stems) != 166:
        FAIL("%d def stems, expected 166" % len(def_stems))

    # kMisc reconciliation
    rowless = set(FAMILY_NAMES) - {"librams"}
    for stem in def_stems:
        if stem not in rows and stem not in rowless:
            FAIL("no kMisc row for roster item %s" % stem)
    for stem in rows:
        if stem not in def_stems:
            FAIL("kMisc row maps to non-roster stem %s" % stem)
    nlibrams = len(rows.get("librams", []))
    if nlibrams != 3:
        FAIL("librams holds %d kMisc rows, expected 3" % nlibrams)
    nrows = sum(len(v) for v in rows.values())
    if nrows != 166:
        FAIL("kMisc rows reconciled to %d stems' rows, expected 166"
             % nrows)

    def build(stem):
        srcs = SOURCES[stem]
        sources = [(part, ROUNDS[part]) for part, _ in srcs]
        scalars, walkers = [], []
        for part, methods in srcs:
            for m in methods:
                if m not in parsed:
                    FAIL("mapped method %s (%s, part %d) not parsed"
                         % (m, stem, part))
                kind, text, payload, clamp = parsed[m]
                (scalars if kind == "s" else walkers).append(
                    (m[3].lower() + m[4:], kind, text, payload, clamp))
        return sources, scalars, walkers

    defs = {}
    nsc = nw = 0
    for stem in def_stems:
        sources, scalars, walkers = build(stem)
        nsc += len(scalars)
        nw += len(walkers)
        if stem in FAMILY_NAMES:
            name = FAMILY_NAMES[stem]
        else:
            name = rows[stem][0]["name"]
        subs = []
        for kid in SUBS.get(stem, []):
            ksrc, ksc, kwlk = build(kid)
            nsc += len(ksc)
            nw += len(kwlk)
            subs.append({"key": kid, "name": SUB_NAMES[kid],
                         "sources": ksrc, "scalars": ksc,
                         "walkers": kwlk})
        defs[stem] = emit_def(stem, name, rows.get(stem, []), sources,
                              scalars, walkers, subs)
    if nsc + nw != TOTAL_METHODS:
        FAIL("emitted %d of %d methods (unmapped or duplicate parse)"
             % (nsc + nw, TOTAL_METHODS))

    # mode: any missing def -> PROMOTE (self-healing: the headers are
    # the record, the tool is the only writer), all present -> VERIFY.
    # Present-but-different defs and phantom files always die loudly.
    # Layout is the content/monsters way: defs live in letter dirs;
    # PROMOTE migrates any legacy flat defs (bytes gated first).
    for s in def_stems:
        if not "a" <= s[0] <= "z":
            FAIL("def stem %r does not start a-z (letter-dir layout)"
                 % s)
        if os.path.isfile(def_path(s)) and os.path.isfile(legacy_path(s)):
            FAIL("def %s exists both flat and in %s/ (delete the flat "
                 "copy)" % (s, s[0]))
    present = [s for s in def_stems if os.path.isfile(def_path(s))]
    legacy = [s for s in def_stems
              if s not in set(present) and os.path.isfile(legacy_path(s))]
    missing = [s for s in def_stems
               if s not in set(present) and s not in set(legacy)]
    phantoms = scan_phantoms(set(def_stems))
    if phantoms:
        FAIL("phantom defs in content/magic_items/: %s" % phantoms[:3])
    badp = [s for s in present
            if open(def_path(s)).read() != defs[s]]
    badl = [s for s in legacy
            if open(legacy_path(s)).read() != defs[s]]
    if badl:
        FAIL("verify: %d legacy def(s) not byte-identical (%s...)"
             % (len(badl), badl[0]))
    # present defs may drift ONLY in Lua comments (the tool reworded the
    # header path note when the part headers moved to boneyard/dmg/);
    # any other drift is real and stays RED
    drifted = []
    for s in badp:
        old_lines = open(def_path(s)).read().splitlines()
        new_lines = defs[s].splitlines()
        if len(old_lines) != len(new_lines):
            FAIL("verify: def %s drifted (line count %d -> %d)"
                 % (s, len(old_lines), len(new_lines)))
        for a, b in zip(old_lines, new_lines):
            if a != b and not (a.lstrip().startswith("--")
                               and b.lstrip().startswith("--")):
                FAIL("verify: def %s drifted beyond comments" % s)
        drifted.append(s)
    mode = "PROMOTE" if (missing or legacy or drifted) else "VERIFY"
    written = 0
    moved = 0
    if mode == "PROMOTE":
        for s in legacy + missing:
            os.makedirs(def_dir(s), exist_ok=True)
        for s in legacy:
            os.replace(legacy_path(s), def_path(s))
            moved += 1
        for s in missing:
            with open(def_path(s), "w") as f:
                f.write(defs[s])
        for s in drifted:
            with open(def_path(s), "w") as f:
                f.write(defs[s])
        written = len(missing) + len(drifted)

    # final verify pass: byte-compare every def (letter-dir paths)
    bad = [stem for stem, text in defs.items()
           if open(def_path(stem)).read() != text]
    if bad:
        FAIL("verify: %d def(s) not byte-identical (%s...)"
             % (len(bad), bad[0]))

    hdr_only = [s for s in def_stems if s in HEADER_ONLY]
    print("misc magic lua promotion: %s" % mode)
    print("  part headers: 23 (R257-R279)")
    print("  methods: %d (%d scalar pins, %d table walkers)"
          % (TOTAL_METHODS, SCALAR_COUNT, WALKER_COUNT))
    print("  item defs: %d (+%d subs nested: 9 figurines, 7 instruments)"
          % (len(defs), sum(len(k) for k in SUBS.values())))
    print("  kMisc rows reconciled: %d (167 rows, artifact excluded)"
          % nrows)
    print("  header-only defs: %d" % len(hdr_only))
    print("  defs: %d present, %d written, %d legacy moved"
          % (len(present), written, moved))
    letters = sorted({s[0] for s in def_stems})
    print("  letters: %d (%s)" % (len(letters), " ".join(letters)))
    print("  verify: %d/%d byte-identical" % (len(defs) - len(bad),
                                              len(defs)))
    print("  GREEN: the misc magic lua promotion is verified")


# ---- embedded map ----
# the verified miscmagic assignment (the R257-R279 matcher, recovered
# from the miscmagic_item_split tool's embedded map - authoritative)
ROUNDS = {1: 257,
 2: 258,
 3: 259,
 4: 260,
 5: 261,
 6: 262,
 7: 263,
 8: 264,
 9: 265,
 10: 266,
 11: 267,
 12: 268,
 13: 269,
 14: 270,
 15: 271,
 16: 272,
 17: 273,
 18: 274,
 19: 275,
 20: 276,
 21: 277,
 22: 278,
 23: 279}

ORDER = ['intro',
 'alchemy_jug',
 'amulet_of_inescapable_location',
 'amulet_of_life_protection',
 'amulet_of_the_planes',
 'amulet_of_proof_against_detection_and_location',
 'apparatus_of_kwalish',
 'arrow_of_direction',
 'bag_of_beans',
 'bag_of_devouring',
 'bag_of_holding',
 'bag_of_transmuting',
 'bag_of_tricks',
 'beaker_of_plentiful_potions',
 'boat_folding',
 'book_of_exalted_deeds',
 'book_of_infinite_spells',
 'book_of_vile_darkness',
 'boots_of_dancing',
 'boots_of_elvenkind',
 'boots_of_levitation',
 'boots_of_speed',
 'boots_of_striding_and_springing',
 'bowl_commanding_water_elementals',
 'bowl_of_watery_death',
 'bracers_of_defense',
 'bracers_of_defenselessness',
 'brazier_commanding_fire_elementals',
 'brazier_of_sleep_smoke',
 'brooch_of_shielding',
 'broom_of_animated_attack',
 'broom_of_flying',
 'bucknards_everfull_purse',
 'candle_of_invocation',
 'carpet_of_flying',
 'censer_controlling_air_elementals',
 'censer_of_summoning_hostile_air_elementals',
 'chime_of_opening',
 'chime_of_hunger',
 'cloak_of_displacement',
 'cloak_of_elvenkind',
 'cloak_of_manta_ray',
 'cloak_of_poisonousness',
 'cloak_of_protection',
 'crystal_ball',
 'crystal_hypnosis_ball',
 'cube_of_force',
 'cube_of_frost_resistance',
 'cubic_gate',
 'daerns_instant_fortress',
 'decanter_of_endless_water',
 'deck_of_many_things',
 'drums_of_deafening',
 'drums_of_panic',
 'dust_of_appearance',
 'dust_of_disappearance',
 'dust_of_sneezing_and_choking',
 'efreeti_bottle',
 'eversmoking_bottle',
 'eyes_of_charming',
 'eyes_of_the_eagle',
 'eyes_of_minute_seeing',
 'eyes_of_petrification',
 'eyes',
 'figurines_of_wondrous_power',
 'ebony_fly',
 'golden_lions',
 'ivory_goat_travel',
 'ivory_goat_travail',
 'ivory_goat_terror',
 'marble_elephant',
 'obsidian_stead',
 'onyx_dog',
 'serpentine_owl',
 'flask_of_curses',
 'gauntlets_of_dexterity',
 'gauntlets_of_fumbling',
 'gauntlets_of_ogre_power',
 'gauntlets_of_swimming_and_climbing',
 'gem_of_brightness',
 'gem_of_seeing',
 'girdle_of_femininity_masculinity',
 'girdle_of_giant_strength',
 'helm_of_brilliance',
 'helm_of_comprehending_languages_reading_magic',
 'helm_of_opposite_alignment',
 'helm_of_telepathy',
 'helm_of_teleportation',
 'helm_of_underwater_action',
 'horn_of_blasting',
 'horn_of_bubbles',
 'horn_of_collapsing',
 'horn_of_the_tritons',
 'horn_of_valhalla',
 'horseshoes_of_speed',
 'horseshoes_of_a_zephyr',
 'incense_of_meditation',
 'incense_of_obsession',
 'ioun_stone',
 'fochlucan_bandore',
 'mac_fuirmidh_cittern',
 'doss_lute',
 'canaith_mandolin',
 'cli_lyre',
 'anstruth_harp',
 'ollamh_harp',
 'instrument_of_the_bards',
 'iron_flask',
 'javelin_of_lightning',
 'javelin_of_piercing',
 'jewel_of_attacks',
 'jewel_of_flawlessness',
 'keoghtoms_ointment',
 'librams',
 'lyre_of_building',
 'manual_of_bodily_health',
 'manual_of_gainful_exercise',
 'manual_of_golems',
 'manual_of_puissant_skill_at_arms',
 'manual_of_quickness_of_action',
 'manual_of_stealthy_pilfering',
 'mattock_of_the_titans',
 'maul_of_the_titans',
 'medallion_of_esp',
 'medallion_of_thought_projection',
 'mirror_of_life_trapping',
 'mirror_of_mental_prowess',
 'mirror_of_opposition',
 'necklace_of_adaptation',
 'necklace_of_missiles',
 'necklace_of_prayer_beads',
 'necklace_of_strangulation',
 'net_of_entrapment',
 'net_of_snaring',
 'nolzurs_marvelous_pigments',
 'pearl_of_power',
 'pearl_of_wisdom',
 'periapt_of_foul_rotting',
 'periapt_of_health',
 'periapt_of_proof_against_poison',
 'periapt_of_wound_closure',
 'phylactery_of_faithfulness',
 'phylactery_of_long_years',
 'phylactery_of_monstrous_attention',
 'pipes_of_the_sewers',
 'portable_hole',
 'quaals_feather_token',
 'robe_of_the_archmagi',
 'robe_of_blending',
 'robe_of_eyes',
 'robe_of_powerlessness',
 'robe_of_scintillating_colors',
 'robe_of_useful_items',
 'rope_of_climbing',
 'rope_of_constriction',
 'rope_of_entanglement',
 'rug_of_smothering',
 'rug_of_welcome',
 'saw_of_mighty_cutting',
 'scarab_of_death',
 'scarab_of_enraging_enemies',
 'scarab_of_insanity',
 'scarab_of_protection',
 'spade_of_colossal_excavation',
 'sphere_of_annihilation',
 'stone_of_controlling_earth_elementals',
 'stone_of_good_luck',
 'stone_of_weight',
 'talisman_of_pure_good',
 'talisman_of_the_sphere',
 'talisman_of_ultimate_evil',
 'talisman_of_zagy',
 'tome_of_clear_thought',
 'tome_of_leadership_and_influence',
 'tome_of_understanding',
 'trident_of_fish_command',
 'trident_of_submission',
 'trident_of_warning',
 'trident_of_yearning',
 'vacuous_grimoire',
 'well_of_many_worlds',
 'wings_of_flying']

SOURCES = {'intro': [(1, ['mmpIntroMaxDuplicates', 'mmpIntroBooksExactWishCount'])],
 'alchemy_jug': [(1,
                  ['mmpAlchemyJugRowCount',
                   'mmpAlchemyJugKindsPerDay',
                   'mmpAlchemyJugPouringsPerDay',
                   'mmpAlchemyJugGallonsPerRound',
                   'mmpAlchemyJugRoundsPerLargePouring',
                   'mmpAlchemyJugRowQty',
                   'mmpAlchemyJugRowUnit'])],
 'amulet_of_inescapable_location': [(1, ['mmpAmuletLocationMultiplier'])],
 'amulet_of_life_protection': [(1, ['mmpAmuletLifeProtectionDays'])],
 'amulet_of_the_planes': [(1,
                           ['mmpAmuletPlanesRowCount',
                            'mmpAmuletPlanesLowDieFaces',
                            'mmpAmuletPlanesHighDieFaces',
                            'mmpAmuletPlanesAddOnHigh',
                            'mmpAmuletPlanesResultMax',
                            'mmpAmuletPlanesAltRowCount',
                            'mmpAmuletPlanesRowLo',
                            'mmpAmuletPlanesRowHi',
                            'mmpAmuletPlanesAltLo'])],
 'amulet_of_proof_against_detection_and_location': [(1,
                                                     ['mmpAmuletProofNoAuraFlag'])],
 'apparatus_of_kwalish': [(1,
                           ['mmpKwalishLeverCount',
                            'mmpKwalishForwardInches',
                            'mmpKwalishBackwardInches',
                            'mmpKwalishPincerReachFeet',
                            'mmpKwalishPincerDamageLo',
                            'mmpKwalishPincerDamageHi',
                            'mmpKwalishPincerHitPct',
                            'mmpKwalishMaxDepthFeet',
                            'mmpKwalishOccupants',
                            'mmpKwalishAirHoursLo',
                            'mmpKwalishAirHoursHi',
                            'mmpKwalishArmorClass',
                            'mmpKwalishLeakHp',
                            'mmpKwalishStaveHp'])],
 'arrow_of_direction': [(1,
                         ['mmpArrowDirectionUsesPerDay',
                          'mmpArrowDirectionRepetitions',
                          'mmpArrowDirectionTurns',
                          'mmpArrowDirectionRequestKinds'])],
 'bag_of_beans': [(1,
                   ['mmpBeanExplodeDamageLo',
                    'mmpBeanExplodeDamageHi',
                    'mmpBeanExplodeRadiusFeet',
                    'mmpBeanOptimumLo',
                    'mmpBeanOptimumHi',
                    'mmpBeanBeneficialMax',
                    'mmpBeanEffectRowCount',
                    'mmpBeanBerryCountLo',
                    'mmpBeanBerryCountHi',
                    'mmpBeanBerryGemLo',
                    'mmpBeanBerryGemHi',
                    'mmpBeanSmokeRadiusFeet',
                    'mmpBeanSmokeTurns',
                    'mmpBeanBlindRoundsLo',
                    'mmpBeanBlindRoundsHi',
                    'mmpBeanGasRadiusFeet',
                    'mmpBeanGasTurns'])],
 'bag_of_devouring': [(1,
                       ['mmpDevouringIgnorePct',
                        'mmpDevouringClosePct',
                        'mmpDevouringBaseDrawPct',
                        'mmpDevouringDrawModPerPlus',
                        'mmpDevouringExampleStr18Pct',
                        'mmpDevouringExampleStr5Pct',
                        'mmpDevouringCapacityCubicFeet',
                        'mmpDevouringSwallowPctPerTurn',
                        'mmpDevouringConsumeSegments'])],
 'bag_of_holding': [(2,
                     ['mmpHoldingSackShortSideFeet',
                      'mmpHoldingSackLongSideFeet',
                      'mmpHoldingRowCount',
                      'mmpHoldingRuptureCauseCount',
                      'mmpHoldingRowLo',
                      'mmpHoldingRowHi',
                      'mmpHoldingRowWeightPounds',
                      'mmpHoldingRowWeightLimitPounds',
                      'mmpHoldingRowVolumeLimitCubicFeet'])],
 'bag_of_transmuting': [(2,
                         ['mmpTransmutingDisguiseQualityCount',
                          'mmpTransmutingProperUsesMin',
                          'mmpTransmutingProperUsesMax',
                          'mmpTransmutingTransmuteKindCount',
                          'mmpTransmutingItemBaseMaterialCount',
                          'mmpTransmutingExemptKindCount'])],
 'bag_of_tricks': [(2,
                    ['mmpTricksTossMinFeet',
                     'mmpTricksTossMaxFeet',
                     'mmpTricksTypeDieSides',
                     'mmpTricksTypeCount',
                     'mmpTricksAnimalsPerType',
                     'mmpTricksAnimalDieMin',
                     'mmpTricksAnimalDieMax',
                     'mmpTricksDrawnAtOnceMax',
                     'mmpTricksDurationTurns',
                     'mmpTricksEndConditionCount',
                     'mmpTricksTypeRollCount',
                     'mmpTricksWeeklyDrawMax',
                     'mmpTricksTypeLo',
                     'mmpTricksTypeHi'])],
 'beaker_of_plentiful_potions': [(2,
                                  ['mmpBeakerDoseMin',
                                   'mmpBeakerDoseMax',
                                   'mmpBeakerPotionCountMin',
                                   'mmpBeakerPotionCountMax',
                                   'mmpBeakerCountDieSides',
                                   'mmpBeakerCountDiePlus',
                                   'mmpBeakerPourRounds',
                                   'mmpBeakerPourDoses',
                                   'mmpBeakerBadTypeCount',
                                   'mmpBeakerMonthlyTypeLoss',
                                   'mmpBeakerDispenseRowMin',
                                   'mmpBeakerDispenseRowMax',
                                   'mmpBeakerPerDayByCount',
                                   'mmpBeakerPerWeekByCount'])],
 'boat_folding': [(2,
                   ['mmpBoatBoxLengthInches',
                    'mmpBoatBoxWidthInches',
                    'mmpBoatBoxDepthInches',
                    'mmpBoatLengthFeet',
                    'mmpBoatWidthFeet',
                    'mmpBoatDepthFeet',
                    'mmpBoatShipLengthFeet',
                    'mmpBoatShipWidthFeet',
                    'mmpBoatShipDepthFeet',
                    'mmpBoatOarPairs',
                    'mmpBoatComponentCount',
                    'mmpBoatShipOarSets',
                    'mmpBoatShipComponentCount',
                    'mmpBoatPersonsMin',
                    'mmpBoatPersonsMax',
                    'mmpBoatShipPersons',
                    'mmpBoatCommandWordCount'])],
 'book_of_exalted_deeds': [(2,
                            ['mmpExaltedReadingWeeks',
                             'mmpExaltedWisdomGain',
                             'mmpExaltedHalfwayPct',
                             'mmpExaltedNeutralXpLossMin',
                             'mmpExaltedNeutralXpLossMax',
                             'mmpExaltedLevelFloor',
                             'mmpExaltedEvilLevelLoss',
                             'mmpExaltedAtonementPct',
                             'mmpExaltedAtonementAdventuresMin',
                             'mmpExaltedAtonementAdventuresMax',
                             'mmpExaltedMuIntLoss',
                             'mmpExaltedMuSaveXpLossMin',
                             'mmpExaltedMuSaveXpLossMax',
                             'mmpExaltedThiefHpMin',
                             'mmpExaltedThiefHpMax',
                             'mmpExaltedThiefDexLoss',
                             'mmpExaltedThiefConvertPctMin',
                             'mmpExaltedThiefConvertPctMax',
                             'mmpExaltedThiefConvertWisReq',
                             'mmpExaltedAssassinHpMin',
                             'mmpExaltedAssassinHpMax',
                             'mmpExaltedVanishesAfterPerusal',
                             'mmpExaltedMaxBenefitTimes'])],
 'book_of_infinite_spells': [(3,
                              ['mmpInfiniteFirstReadHpMin',
                               'mmpInfiniteFirstReadHpMax',
                               'mmpInfiniteFirstReadStunTurnsMin',
                               'mmpInfiniteFirstReadStunTurnsMax',
                               'mmpInfinitePageMin',
                               'mmpInfinitePageMax',
                               'mmpInfinitePageBase',
                               'mmpInfinitePageDieSides',
                               'mmpInfinitePageRowCount',
                               'mmpInfinitePageLo',
                               'mmpInfinitePageHi',
                               'mmpInfiniteLevelDieSides',
                               'mmpInfiniteMuLevelDieSides',
                               'mmpInfiniteLevelRerollLo',
                               'mmpInfiniteLevelRerollHi',
                               'mmpInfiniteMuLevelRerollLo',
                               'mmpInfiniteMuLevelRerollHi',
                               'mmpInfiniteRerollDieSides',
                               'mmpInfiniteMuRerollDieSides',
                               'mmpInfiniteVanishesAtLastPage',
                               'mmpInfiniteCastPerDay',
                               'mmpInfiniteCastPerDayIfKnown',
                               'mmpInfiniteTurnPctUsable',
                               'mmpInfiniteTurnPctForeign',
                               'mmpInfiniteTurnPctNonCasterCleric',
                               'mmpInfiniteTurnPctNonCasterMu'])],
 'book_of_vile_darkness': [(3,
                            ['mmpVileReadingWeeks',
                             'mmpVileWisdomGain',
                             'mmpVileHalfwayPct',
                             'mmpVileNeutralXpLossMin',
                             'mmpVileNeutralXpLossMax',
                             'mmpVileNeutralSplitPct',
                             'mmpVileGoodSaveCount',
                             'mmpVileGoodXpLossBase',
                             'mmpVileGoodXpLossPerWis',
                             'mmpVileGoodHandlingHpMin',
                             'mmpVileGoodHandlingHpMax',
                             'mmpVileNightHagPct',
                             'mmpVileNeutralHandlingHpMin',
                             'mmpVileNeutralHandlingHpMax'])],
 'boots_of_dancing': [(3,
                       ['mmpDancingDisguisedBootTypeCount',
                        'mmpDancingTriggerCaseCount',
                        'mmpDancingAcPenalty',
                        'mmpDancingRemovalSpellCount'])],
 'boots_of_elvenkind': [(3,
                         ['mmpElvenkindSilencePctWorst',
                          'mmpElvenkindSilencePctBest'])],
 'boots_of_levitation': [(3,
                          ['mmpLevitationSpeedInchesPerRound',
                           'mmpLevitationWeightIncrementPounds',
                           'mmpLevitationWeightDieSides',
                           'mmpLevitationWeightBasePounds',
                           'mmpLevitationWeightMinPounds',
                           'mmpLevitationWeightMaxPounds'])],
 'boots_of_speed': [(3,
                     ['mmpSpeedBaseMovementInches',
                      'mmpSpeedSlowPoundsPerInch',
                      'mmpSpeedFreeWeightPounds',
                      'mmpSpeedExampleHumanPounds',
                      'mmpSpeedExampleGearPounds',
                      'mmpSpeedExampleRateInches',
                      'mmpSpeedSackCoins',
                      'mmpSpeedSackSlowInches',
                      'mmpSpeedRestHoursPerMoveHour',
                      'mmpSpeedMaxContinuousHours',
                      'mmpSpeedAcBonus'])],
 'boots_of_striding_and_springing': [(3,
                                      ['mmpStridingBaseMovementInches',
                                       'mmpStridingMaxHoursPerDay',
                                       'mmpStridingRechargeHours',
                                       'mmpStridingNormalPaceFeet',
                                       'mmpStridingForwardJumpFeet',
                                       'mmpStridingBackwardLeapFeet',
                                       'mmpStridingVerticalSpringFeet',
                                       'mmpStridingStumbleBasePct',
                                       'mmpStridingStumbleDexAdjPct',
                                       'mmpStridingStumbleDexThreshold',
                                       'mmpStridingStumbleRowCount',
                                       'mmpStridingStumblePctByDex',
                                       'mmpStridingAcBonus'])],
 'bowl_commanding_water_elementals': [(4,
                                       ['mmpBowlCmdHd',
                                        'mmpBowlCmdWordsRounds',
                                        'mmpBowlCmdSaltBonusPerDie',
                                        'mmpBowlCmdSaltMaxHpPerDie',
                                        'mmpBowlCmdDiameterInches',
                                        'mmpBowlCmdDepthInches'])],
 'bowl_of_watery_death': [(4,
                           ['mmpWateryDeathSaltSavePenalty',
                            'mmpWateryDeathDrownMinRounds',
                            'mmpWateryDeathDrownMaxRounds',
                            'mmpWateryDeathFreeSpellCount',
                            'mmpWateryDeathDeathPermanent',
                            'mmpWateryDeathSweetWaterAnotherSave'])],
 'bracers_of_defense': [(4,
                         ['mmpBracersDefRowCount',
                          'mmpBracersDefAcMin',
                          'mmpBracersDefAcMax',
                          'mmpBracersDefBandLo',
                          'mmpBracersDefBandHi',
                          'mmpBracersDefAc'])],
 'bracers_of_defenselessness': [(4,
                                 ['mmpDefenselessAc',
                                  'mmpDefenselessNegatesProtections',
                                  'mmpDefenselessRemoveCurseOnly'])],
 'brazier_commanding_fire_elementals': [(4,
                                         ['mmpBrazierFireHd',
                                          'mmpBrazierFireLightRounds',
                                          'mmpBrazierFireSulphurBonusPerDie',
                                          'mmpBrazierFireSulphurHpMin',
                                          'mmpBrazierFireSulphurHpMax'])],
 'brazier_of_sleep_smoke': [(4,
                             ['mmpSleepSmokeRadiusInches',
                              'mmpSleepSmokeHd',
                              'mmpSleepSmokeAwakenSpellCount'])],
 'brooch_of_shielding': [(4,
                          ['mmpBroochPctWithoutGems', 'mmpBroochAbsorbHp'])],
 'broom_of_animated_attack': [(4,
                               ['mmpBroomAttackDumpMinFeet',
                                'mmpBroomAttackDumpMaxFeet',
                                'mmpBroomAttackAttacksPerRound',
                                'mmpBroomAttackAsHd',
                                'mmpBroomAttackStrawBlindRounds',
                                'mmpBroomAttackHandleDmgMin',
                                'mmpBroomAttackHandleDmgMax',
                                'mmpBroomAttackAc',
                                'mmpBroomAttackHpToDestroy'])],
 'broom_of_flying': [(4,
                      ['mmpBroomFlySpeedInches',
                       'mmpBroomFlyCapacityPounds',
                       'mmpBroomFlyPoundsPerInch',
                       'mmpBroomFlyClimbDiveDegrees',
                       'mmpBroomFlyFetchSpeedInches'])],
 'bucknards_everfull_purse': [(4,
                               ['mmpPurseCoinsPerType',
                                'mmpPurseTypeRowCount',
                                'mmpPurseGemsBaseGp',
                                'mmpPurseGemsMaxGp',
                                'mmpPurseAbilitiesNeverChange',
                                'mmpPurseSpiceNote',
                                'mmpPurseTypeBandLo',
                                'mmpPurseTypeBandHi'])],
 'candle_of_invocation': [(5,
                           ['mmpCandleAlignments',
                            'mmpCandleClericLevelBoost',
                            'mmpCandleBurnHours',
                            'mmpCandleGateSpell'])],
 'carpet_of_flying': [(5,
                       ['mmpCarpetRowCount',
                        'mmpCarpetBandLo',
                        'mmpCarpetBandHi',
                        'mmpCarpetWidthFeet',
                        'mmpCarpetLengthFeet',
                        'mmpCarpetPersons',
                        'mmpCarpetSpeedInches'])],
 'censer_controlling_air_elementals': [(5,
                                        ['mmpCenserAirHd',
                                         'mmpCenserAirMedBonusPerDie',
                                         'mmpCenserAirWidthInches',
                                         'mmpCenserAirHeightInches',
                                         'mmpCenserAirTurnsIfExtinguished'])],
 'censer_of_summoning_hostile_air_elementals': [(5,
                                                 ['mmpCenserHostileMin',
                                                  'mmpCenserHostileMax',
                                                  'mmpCenserHostilePerRound'])],
 'chime_of_opening': [(5,
                       ['mmpChimeOpenLengthInches',
                        'mmpChimeOpenWizardLockLevel',
                        'mmpChimeOpenRoundPerFunction',
                        'mmpChimeOpenSoundingsMin',
                        'mmpChimeOpenSoundingsMax',
                        'mmpChimeOpenChargesMin',
                        'mmpChimeOpenChargesMax',
                        'mmpChimeOpenChargesDieSides',
                        'mmpChimeOpenChargesDieMult'])],
 'chime_of_hunger': [(5,
                      ['mmpChimeHungerRadiusInches',
                       'mmpChimeHungerMinEatRounds'])],
 'cloak_of_displacement': [(5,
                            ['mmpDisplacementMinFeet',
                             'mmpDisplacementMaxFeet',
                             'mmpDisplacementAcBonus',
                             'mmpDisplacementSaveBonus',
                             'mmpDisplacementHumanoidPct',
                             'mmpDisplacementSmallPct'])],
 'cloak_of_elvenkind': [(5,
                         ['mmpElvenkindRowCount',
                          'mmpElvenkindOutdoorNaturalRows',
                          'mmpElvenkindOutdoorOtherRows',
                          'mmpElvenkindUndergroundRows',
                          'mmpElvenkindHumanoidPct',
                          'mmpElvenkindSmallPct',
                          'mmpElvenkindInvisibilityPct'])],
 'cloak_of_manta_ray': [(5,
                         ['mmpMantaRayLikenessPct',
                          'mmpMantaRayMoveInches',
                          'mmpMantaRayAc',
                          'mmpMantaRayTailDmgMin',
                          'mmpMantaRayTailDmgMax',
                          'mmpMantaRayTailStun',
                          'mmpMantaRaySaltWaterTrigger'])],
 'cloak_of_poisonousness': [(5,
                             ['mmpPoisonCloakRevivalPctPenalty',
                              'mmpPoisonCloakRemoveCurseDestroys',
                              'mmpPoisonCloakNeutralizeNoEffect'])],
 'cloak_of_protection': [(5,
                          ['mmpCloakProtRowCount',
                           'mmpCloakProtAcPerPlus',
                           'mmpCloakProtSavePerPlus',
                           'mmpCloakProtExampleBaseAc',
                           'mmpCloakProtBandLo',
                           'mmpCloakProtBandHi',
                           'mmpCloakProtPlus'])],
 'crystal_ball': [(6,
                   ['mmpCrystalBallDiameterInches',
                    'mmpCrystalBallLocatingRowCount',
                    'mmpCrystalBallLocatingWellKnownPct',
                    'mmpCrystalBallLocatingKnownSlightlyPct',
                    'mmpCrystalBallLocatingPicturedPct',
                    'mmpCrystalBallLocatingPartPct',
                    'mmpCrystalBallLocatingGarmentPct',
                    'mmpCrystalBallLocatingWellInformedPct',
                    'mmpCrystalBallLocatingSlightlyInformedPct',
                    'mmpCrystalBallLocatingOtherPlanePct',
                    'mmpCrystalBallViewingRowCount',
                    'mmpCrystalBallOverrunIntLoss',
                    'mmpCrystalBallOverrunInsaneUntilHealed',
                    'mmpCrystalBallImprovingSpellCount',
                    'mmpCrystalBallCastThroughSpellCount',
                    'mmpCrystalBallCastThroughChancePerLevelPct',
                    'mmpCrystalBallFeatureRowCount',
                    'mmpCrystalBallSpellFunctionLevel',
                    'mmpCrystalBallNoticeMinInt',
                    'mmpCrystalBallDetectClassCount',
                    'mmpCrystalBallIntFactorCount',
                    'mmpCrystalBallDetectPerLevelPct',
                    'mmpCrystalBallDetectionTablePage',
                    'mmpCrystalBallDispelDownDays',
                    'mmpCrystalBallCheckPerRound',
                    'mmpCrystalBallSpellUserClassCount',
                    'mmpCrystalBallClericDevicesAllowed',
                    'mmpCrystalBallKnowledgeNotDistance',
                    'mmpCrystalBallTelepathyCommunicationOnly',
                    'mmpCrystalBallLocatingPct',
                    'mmpCrystalBallViewingMinutes',
                    'mmpCrystalBallViewingTimesPerDay',
                    'mmpCrystalBallViewingBandHiPct',
                    'mmpCrystalBallFeatureBandLo',
                    'mmpCrystalBallFeatureBandHi',
                    'mmpCrystalBallFeatureCountAt',
                    'mmpCrystalBallDetectBasePct',
                    'mmpCrystalBallIntFactorPct'])],
 'crystal_hypnosis_ball': [(6,
                            ['mmpHypnosisBallCursed',
                             'mmpHypnosisBallRadiatesEvil',
                             'mmpHypnosisBallSuggestionImplanted',
                             'mmpHypnosisBallIndistinguishable',
                             'mmpHypnosisBallInfluencerKindCount',
                             'mmpHypnosisBallFateCount',
                             'mmpHypnosisBallRefereePace'])],
 'cube_of_force': [(7,
                    ['mmpCubeForceWallInches',
                     'mmpCubeForceCharges',
                     'mmpCubeForceRestoreDays',
                     'mmpCubeForceFaceCount',
                     'mmpCubeForceSurchargeFormCount',
                     'mmpCubeForceSpellsInOutBlocked',
                     'mmpCubeForceMaterialCount',
                     'mmpCubeForceCostPerTurn',
                     'mmpCubeForceMoveInches',
                     'mmpCubeForceSurchargeAt'])],
 'cube_of_frost_resistance': [(7,
                               ['mmpCubeFrostSideInches',
                                'mmpCubeFrostTempF',
                                'mmpCubeFrostColdAttackCount',
                                'mmpCubeFrostCollapseHp',
                                'mmpCubeFrostTurnRounds',
                                'mmpCubeFrostRenewHours',
                                'mmpCubeFrostDestroyHp',
                                'mmpCubeFrostColdPer10BelowF',
                                'mmpCubeFrostAt40BelowHp'])],
 'cubic_gate': [(7,
                 ['mmpCubicGateSideCount',
                  'mmpCubicGatePrimeSides',
                  'mmpCubicGateChosenSides',
                  'mmpCubicGateNexusChancePct',
                  'mmpCubicGateDrawRadiusFeet',
                  'mmpCubicGateMaxLinks'])],
 'daerns_instant_fortress': [(7,
                              ['mmpDaernSquareFeet',
                               'mmpDaernHeightFeet',
                               'mmpDaernGroundDepthFeet',
                               'mmpDaernCollapseHp',
                               'mmpDaernWishRepairHp',
                               'mmpDaernSpringRounds',
                               'mmpDaernGrowthDamageMin',
                               'mmpDaernGrowthDamageMax',
                               'mmpDaernDoorOwnerOnly',
                               'mmpDaernNormalWeaponsAffect',
                               'mmpDaernDamageCumulative'])],
 'decanter_of_endless_water': [(7,
                                ['mmpDecanterModeCount',
                                 'mmpDecanterStreamGallonsPerRound',
                                 'mmpDecanterFountainLengthFeet',
                                 'mmpDecanterFountainGallonsPerRound',
                                 'mmpDecanterGeyserLengthFeet',
                                 'mmpDecanterGeyserGallonsPerRound',
                                 'mmpDecanterWaterTypeCount',
                                 'mmpDecanterGeyserKnockover',
                                 'mmpDecanterStopsOnCommand'])],
 'deck_of_many_things': [(8,
                          ['mmpDeckPlaqueMaterialCount',
                           'mmpDeckMinDraws',
                           'mmpDeckMaxDraws',
                           'mmpDeckJesterBonusDraws',
                           'mmpDeckBasePlaqueCount',
                           'mmpDeckFullPlaqueCount',
                           'mmpDeckBaseChancePct',
                           'mmpDeckFullChancePct',
                           'mmpDeckAsteriskPlaqueCount',
                           'mmpDeckDiscardPlaqueCount',
                           'mmpDeckBoldFaceStopCount',
                           'mmpDeckTablePlaqueCount',
                           'mmpDeckSunXp',
                           'mmpDeckMoonWishesMin',
                           'mmpDeckMoonWishesMax',
                           'mmpDeckMoonSpellLevel',
                           'mmpDeckStarPoints',
                           'mmpDeckStarMaxScore',
                           'mmpDeckStarFallbackOrderCount',
                           'mmpDeckCometMidpointProgress',
                           'mmpDeckThroneCharisma',
                           'mmpDeckThroneReactionBonusPct',
                           'mmpDeckKeyMapBonusPct',
                           'mmpDeckKeyWeaponCount',
                           'mmpDeckKnightLevel',
                           'mmpDeckKnightBonusPerDie',
                           'mmpDeckKnightAbilityMax',
                           'mmpDeckGemJewelryCount',
                           'mmpDeckGemGemCount',
                           'mmpDeckGemGemBaseGp',
                           'mmpDeckGemXpLevelCap',
                           'mmpDeckEuryaleSavePenalty',
                           'mmpDeckRogueHenchmenAlienated',
                           'mmpDeckJesterXp',
                           'mmpDeckJesterExtraDraws',
                           'mmpDeckFoolXp',
                           'mmpDeckIdiotIntLossMin',
                           'mmpDeckIdiotIntLossMax',
                           'mmpDeckSkullDeathAc',
                           'mmpDeckSkullDeathHp',
                           'mmpDeckSkullScytheDmgMin',
                           'mmpDeckSkullScytheDmgMax',
                           'mmpDeckSkullUndeadForSpells',
                           'mmpDeckFatesPartyEndures',
                           'mmpDeckDonjonGearStripped',
                           'mmpDeckPlaqueAsterisk',
                           'mmpDeckPlaqueBoldFace',
                           'mmpDeckPlaqueDiscarded'])],
 'drums_of_deafening': [(9,
                         ['mmpDrumDeafDeafRangeInches',
                          'mmpDrumDeafStunRangeInches',
                          'mmpDrumDeafStunMinRounds',
                          'mmpDrumDeafStunMaxRounds',
                          'mmpDrumDeafHemisphereHalfFeet'])],
 'drums_of_panic': [(9,
                     ['mmpDrumPanicRangeInches',
                      'mmpDrumPanicSafeZoneInches',
                      'mmpDrumPanicFleeTurns',
                      'mmpDrumPanicRestRoundsPerTurn',
                      'mmpDrumPanicInt2SaveMod',
                      'mmpDrumPanicInt1SaveMod',
                      'mmpDrumPanicHemisphereHalfFeet'])],
 'dust_of_appearance': [(9,
                         ['mmpDustAppearDurationMinTurns',
                          'mmpDustAppearDurationMaxTurns',
                          'mmpDustAppearPacketRadiusFeet',
                          'mmpDustAppearTubeStartFeet',
                          'mmpDustAppearTubeEndFeet',
                          'mmpDustAppearTubeLengthFeet',
                          'mmpDustAppearContainerMin',
                          'mmpDustAppearContainerMax'])],
 'dust_of_disappearance': [(9,
                            ['mmpDustGoneDurationMinTurns',
                             'mmpDustGoneDurationMaxTurns',
                             'mmpDustGoneSprinkleMinTurns',
                             'mmpDustGoneSprinkleMaxTurns',
                             'mmpDustGoneAcBonusPlaces'])],
 'dust_of_sneezing_and_choking': [(9,
                                   ['mmpDustChokeRadiusFeet',
                                    'mmpDustChokeDisabledMinRounds',
                                    'mmpDustChokeDisabledMaxRounds'])],
 'efreeti_bottle': [(9,
                     ['mmpEfreetiInsanePct',
                      'mmpEfreetiWishesPct',
                      'mmpEfreetiServePct',
                      'mmpEfreetiWishCount',
                      'mmpEfreetiReleaseSegments'])],
 'eversmoking_bottle': [(9,
                         ['mmpEversmokeFirstRoundCubicFeet',
                          'mmpEversmokePerRoundCubicFeet',
                          'mmpEversmokeMaxCubicFeet'])],
 'eyes_of_charming': [(9,
                       ['mmpEyesCharmTargetsPerRound',
                        'mmpEyesCharmBothSaveMod',
                        'mmpEyesCharmOneSaveMod'])],
 'eyes_of_the_eagle': [(9,
                        ['mmpEyesEagleVisionFactor',
                         'mmpEyesEagleMinDistanceFeet',
                         'mmpEyesEagleSeeAtFeet',
                         'mmpEyesEagleNormalSeeFeet',
                         'mmpEyesEagleSingleStunRounds'])],
 'eyes_of_minute_seeing': [(9,
                            ['mmpEyesMinuteVisionFactor',
                             'mmpEyesMinuteMaxDistanceFeet'])],
 'eyes_of_petrification': [(9, ['mmpEyesPetrifyBasiliskGazePct'])],
 'eyes': [(9,
           ['mmpEyesMixInsanityMinTurns',
            'mmpEyesMixInsanityMaxTurns',
            'mmpEyesMixInsanityDice'])],
 'figurines_of_wondrous_power': [(10,
                                  ['mmpFigTypeCount',
                                   'mmpFigStatuetteInchesHigh',
                                   'mmpFigTypeLo',
                                   'mmpFigTypeHi',
                                   'mmpGoatCount',
                                   'mmpGoatUsesBeforeBurnout'])],
 'ebony_fly': [(10,
                ['mmpFlyAc',
                 'mmpFlyHitDiceBase',
                 'mmpFlyHitDiceExtra',
                 'mmpFlyAirManeuverClass',
                 'mmpFlySpeedUnladenInches',
                 'mmpFlySpeedLadenInches',
                 'mmpFlySpeedMaxLoadInches',
                 'mmpFlyLadenMaxPounds',
                 'mmpFlyMaxLoadPounds',
                 'mmpFlyUsesPerWeek',
                 'mmpFlyHoursPerDay'])],
 'golden_lions': [(10,
                   ['mmpLionCount',
                    'mmpLionAcFront',
                    'mmpLionAcRear',
                    'mmpLionHitDiceBase',
                    'mmpLionHitDiceExtra',
                    'mmpLionSlainReturnWeeks',
                    'mmpLionUseDays'])],
 'ivory_goat_travel': [(10,
                        ['mmpGoatTravelAc',
                         'mmpGoatTravelHp',
                         'mmpGoatTravelAttacks',
                         'mmpGoatTravelHornDmgMin',
                         'mmpGoatTravelHornDmgMax',
                         'mmpGoatTravelHitDice',
                         'mmpGoatTravelMoveInches',
                         'mmpGoatTravelMaxLoadPounds',
                         'mmpGoatTravelPoundsPerMoveLoss',
                         'mmpGoatTravelHoursPerWeek',
                         'mmpGoatTravelRestDays'])],
 'ivory_goat_travail': [(10,
                         ['mmpGoatTravailHoofDmgMin',
                          'mmpGoatTravailHoofDmgMax',
                          'mmpGoatTravailBiteDmgMin',
                          'mmpGoatTravailBiteDmgMax',
                          'mmpGoatTravailHornDmgMin',
                          'mmpGoatTravailHornDmgMax',
                          'mmpGoatTravailChargeBonus',
                          'mmpGoatTravailChargeHornMin',
                          'mmpGoatTravailChargeHornMax',
                          'mmpGoatTravailAc',
                          'mmpGoatTravailHp',
                          'mmpGoatTravailHitDice',
                          'mmpGoatTravailUsesPerMonth',
                          'mmpGoatTravailMoveInches'])],
 'ivory_goat_terror': [(10,
                        ['mmpGoatTerrorMoveInches',
                         'mmpGoatTerrorAc',
                         'mmpGoatTerrorHp',
                         'mmpGoatTerrorHornSpearBonus',
                         'mmpGoatTerrorHornSwordBonus',
                         'mmpGoatTerrorRadiusInches',
                         'mmpGoatTerrorStrengthLossPct',
                         'mmpGoatTerrorHitPenalty',
                         'mmpGoatTerrorIntervalWeeks'])],
 'marble_elephant': [(10,
                      ['mmpElephantTypeLo',
                       'mmpElephantTypeHi',
                       'mmpElephantHoursPerUse',
                       'mmpElephantUsesPerMonth'])],
 'obsidian_stead': [(10,
                     ['mmpSteadGoodRiderPct',
                      'mmpSteadHoursPerUse',
                      'mmpSteadUsesPerWeek'])],
 'onyx_dog': [(10,
               ['mmpDogIntMin',
                'mmpDogIntMax',
                'mmpDogScentFreshPct',
                'mmpDogScentFreshHours',
                'mmpDogScentDecayPctPerHour',
                'mmpDogInfravisionFeet',
                'mmpDogSpotHiddenPct',
                'mmpDogSpotInvisiblePct',
                'mmpDogSpotPhasedPct',
                'mmpDogHoursPerUse',
                'mmpDogUsesPerWeek'])],
 'serpentine_owl': [(10,
                     ['mmpOwlAc',
                      'mmpOwlMoveInches',
                      'mmpOwlHpMin',
                      'mmpOwlHpMax',
                      'mmpOwlDmgMin',
                      'mmpOwlDmgMax',
                      'mmpOwlGiantUses',
                      'mmpOwlSilencePct',
                      'mmpOwlInfravisionFeet',
                      'mmpOwlDarkVisionFactor',
                      'mmpOwlHearMouseFeet',
                      'mmpOwlCounterStealthPct',
                      'mmpOwlIntMin',
                      'mmpOwlIntMax'])],
 'flask_of_curses': [(11,
                      ['mmpFlaskCurseOnFirstOpen',
                       'mmpFlaskHarmlessAfterUse'])],
 'gauntlets_of_dexterity': [(11,
                             ['mmpGauntDexBoostLow',
                              'mmpGauntDexBoostMid',
                              'mmpGauntDexBoostHigh',
                              'mmpGauntDexThiefLevel',
                              'mmpGauntDexThiefBonusPct'])],
 'gauntlets_of_fumbling': [(11,
                            ['mmpGauntFumbDropPct',
                             'mmpGauntFumbDexPenalty',
                             'mmpGauntFumbRemoveCurseOnly'])],
 'gauntlets_of_ogre_power': [(11,
                              ['mmpGauntOgreStrength',
                               'mmpGauntOgreStrengthPercentile',
                               'mmpGauntOgreHitBonus',
                               'mmpGauntOgreDmgBonus'])],
 'gauntlets_of_swimming_and_climbing': [(11,
                                         ['mmpGauntSwimUnderwaterInches',
                                          'mmpGauntSwimSurfaceInches',
                                          'mmpGauntSwimClimbSuccessPct',
                                          'mmpGauntSwimThiefSuccessTenthPct'])],
 'gem_of_brightness': [(11,
                        ['mmpGemBrightLightSorts',
                         'mmpGemBrightConeLengthFeet',
                         'mmpGemBrightConeRadiusHalfFeet',
                         'mmpGemBrightRayDiameterFeet',
                         'mmpGemBrightRayLengthFeet',
                         'mmpGemBrightDazzleMinRounds',
                         'mmpGemBrightDazzleMaxRounds',
                         'mmpGemBrightRayCharges',
                         'mmpGemBrightFlashLengthFeet',
                         'mmpGemBrightFlashRadiusFeet',
                         'mmpGemBrightBlindMinRounds',
                         'mmpGemBrightBlindMaxRounds',
                         'mmpGemBrightEyePenaltyMin',
                         'mmpGemBrightEyePenaltyMax',
                         'mmpGemBrightFlashCharges',
                         'mmpGemBrightTotalCharges',
                         'mmpGemBrightDarknessDrainCharges',
                         'mmpGemBrightDarknessRoundUseless',
                         'mmpGemBrightDarknessDayUseless',
                         'mmpGemBrightDarknessExpelCharges'])],
 'gem_of_seeing': [(11,
                    ['mmpGemSeeCursoryRangeInches',
                     'mmpGemSeeCarefulRangeInches',
                     'mmpGemSeeCursoryAreaFeet',
                     'mmpGemSeeCursoryRounds',
                     'mmpGemSeeCarefulAreaFeet',
                     'mmpGemSeeCarefulRounds',
                     'mmpGemSeeHallucinationPct'])],
 'girdle_of_femininity_masculinity': [(11,
                                       ['mmpGirdleSexWishRestorePct',
                                        'mmpGirdleSexSexlessPct'])],
 'girdle_of_giant_strength': [(11,
                               ['mmpGirdleGiantTypeCount',
                                'mmpGirdleGiantRockDmgMin',
                                'mmpGirdleGiantDiceLo',
                                'mmpGirdleGiantDiceHi',
                                'mmpGirdleGiantStrength',
                                'mmpGirdleGiantHitBonus',
                                'mmpGirdleGiantDmgBonus',
                                'mmpGirdleGiantOpenDoorsTop',
                                'mmpGirdleGiantOpenDoorsBottom',
                                'mmpGirdleGiantOpenChances',
                                'mmpGirdleGiantOpenOutOf',
                                'mmpGirdleGiantWeightAllowance',
                                'mmpGirdleGiantRangeInches',
                                'mmpGirdleGiantRockDmgMax',
                                'mmpGirdleGiantRockWeight',
                                'mmpGirdleGiantBendBarsPct'])],
 'helm_of_brilliance': [(12,
                         ['mmpHelmBrilCommandWordOnly',
                          'mmpHelmBrilTrueNatureVisible',
                          'mmpHelmBrilArmorPlus',
                          'mmpHelmBrilDiamondCount',
                          'mmpHelmBrilRubyCount',
                          'mmpHelmBrilFireOpalCount',
                          'mmpHelmBrilOpalCount',
                          'mmpHelmBrilScintillatesInBrightLight',
                          'mmpHelmBrilJewelUseSegments',
                          'mmpHelmBrilJewelUsableOnce',
                          'mmpHelmBrilUsesPerRound',
                          'mmpHelmBrilSpellLevelDoublingFactor',
                          'mmpHelmBrilUndeadGlowRangeFeet',
                          'mmpHelmBrilUndeadPainDmgMin',
                          'mmpHelmBrilUndeadPainDmgMax',
                          'mmpHelmBrilUndeadExemptKinds',
                          'mmpHelmBrilFlameSwordEffectRounds',
                          'mmpHelmBrilFlameSwordAdditional',
                          'mmpHelmBrilProduceFlameDruidLevel',
                          'mmpHelmBrilFireResistRingStrength',
                          'mmpHelmBrilFireResistAugmentable',
                          'mmpHelmBrilPowderOnExpenditure',
                          'mmpHelmBrilJewelRemovalDestroys',
                          'mmpHelmBrilJewelRemagickable',
                          'mmpHelmBrilRetrySaveWithoutMagic',
                          'mmpHelmBrilOverloadDetonatesRemaining',
                          'mmpHelmBrilOverloadEffectsInMultiple',
                          'mmpHelmBrilJewelRowCount',
                          'mmpHelmBrilJewelGemCount',
                          'mmpHelmBrilJewelSpellLevel',
                          'mmpHelmBrilJewelCasterKind',
                          'mmpHelmBrilJewelFunctionKind'])],
 'helm_of_comprehending_languages_reading_magic': [(12,
                                                    ['mmpHelmComprStrangeTonguesPct',
                                                     'mmpHelmComprMagicalWritingsPct',
                                                     'mmpHelmComprAllOrNone',
                                                     'mmpHelmComprImpliesSpellUse',
                                                     'mmpHelmComprHelmetOfAcValue'])],
 'helm_of_opposite_alignment': [(12,
                                 ['mmpHelmOppAlignIndeterminateDweomer',
                                  'mmpHelmOppAlignCurseOnDonning',
                                  'mmpHelmOppAlignAbsoluteKinds',
                                  'mmpHelmOppAlignAlterationDesired',
                                  'mmpHelmOppAlignRestoreSpellKinds',
                                  'mmpHelmOppAlignSelfRestoreAttempts',
                                  'mmpHelmOppAlignPaladinQuestAndAtone',
                                  'mmpHelmOppAlignPowersAfterFunctioning'])],
 'helm_of_telepathy': [(12,
                        ['mmpHelmTelepathyRangeInches',
                         'mmpHelmTelepathyStoneBarrierFeet',
                         'mmpHelmTelepathyIronBarrierQuarterFeet',
                         'mmpHelmTelepathyLeadGoldSheetBlocks',
                         'mmpHelmTelepathyDirectional',
                         'mmpHelmTelepathyConsciousEffort',
                         'mmpHelmTelepathySuggestPctPer2IntAbove',
                         'mmpHelmTelepathySuggestPctPer1IntBelow',
                         'mmpHelmTelepathySavePenaltyPer2IntBelow',
                         'mmpHelmTelepathySaveBonusPer1IntAbove',
                         'mmpHelmTelepathyEqualIntSaveAdjustment',
                         'mmpHelmTelepathyPsionicAttackBonus',
                         'mmpHelmTelepathyPsionicStrengthBonus'])],
 'helm_of_teleportation': [(12,
                            ['mmpHelmTeleportPerDay',
                             'mmpHelmTeleportMuRefreshRepeats',
                             'mmpHelmTeleportMuStillPersonalAfterRefresh',
                             'mmpHelmTeleportMuUncastPersonalCount',
                             'mmpHelmTeleportUsageAfterMemoryLost'])],
 'helm_of_underwater_action': [(12,
                                ['mmpHelmUnderwaterSeeAndBreathe',
                                 'mmpHelmUnderwaterLensCompartments',
                                 'mmpHelmUnderwaterVisionFactor',
                                 'mmpHelmUnderwaterObstructionsBlock',
                                 'mmpHelmUnderwaterAirGlobeUntilRepeat'])],
 'horn_of_blasting': [(12,
                       ['mmpHornBlastingConeLengthInches',
                        'mmpHornBlastingConeBaseWidthInches',
                        'mmpHornBlastingSaveStunRounds',
                        'mmpHornBlastingSaveDeafRounds',
                        'mmpHornBlastingFailDmgMin',
                        'mmpHornBlastingFailDmgMax',
                        'mmpHornBlastingFailStunRounds',
                        'mmpHornBlastingFailDeafRounds',
                        'mmpHornBlastingPulseWidthFeet',
                        'mmpHornBlastingPulseLengthInches',
                        'mmpHornBlastingCatapultMultiplier',
                        'mmpHornBlastingCatapultHitDamage',
                        'mmpHornBlastingStructuralPoints',
                        'mmpHornBlastingExplodePctPerExtraUse',
                        'mmpHornBlastingExplodeDmgMin',
                        'mmpHornBlastingExplodeDmgMax',
                        'mmpHornBlastingCharges',
                        'mmpHornBlastingShiverPctPerUse',
                        'mmpHornBlastingShiverWielderDamage'])],
 'horn_of_bubbles': [(12,
                      ['mmpHornBubblesBlindRoundsMin',
                       'mmpHornBubblesBlindRoundsMax',
                       'mmpHornBubblesOnlyWhenSlayerSeeks',
                       'mmpHornBubblesAppearanceMayDelay'])],
 'horn_of_collapsing': [(13,
                         ['mmpHornCollapseMisfirePct',
                          'mmpHornCollapseOutRocksMin',
                          'mmpHornCollapseOutRocksMax',
                          'mmpHornCollapseOutRockDmgMin',
                          'mmpHornCollapseOutRockDmgMax',
                          'mmpHornCollapseIndoorDmgMin',
                          'mmpHornCollapseIndoorDmgMax',
                          'mmpHornCollapseUnderDmgMin',
                          'mmpHornCollapseUnderDmgMax',
                          'mmpHornCollapseUnderHeightFactorFeet',
                          'mmpHornCollapseAimRangeMinFeet',
                          'mmpHornCollapseAimRangeMaxFeet',
                          'mmpHornCollapseRoofWidthFeet',
                          'mmpHornCollapseRoofLengthFeet',
                          'mmpHornCollapseRoofRadiusFeet',
                          'mmpHornCollapseIndoorsOrUndergroundOnly'])],
 'horn_of_the_tritons': [(13,
                          ['mmpHornTritonPerDay',
                           'mmpHornTritonTritonPerDay',
                           'mmpHornTritonFunctionCount',
                           'mmpHornTritonCalmRadiusMiles',
                           'mmpHornTritonCalmDispelKinds',
                           'mmpHornTritonSummonKindCount',
                           'mmpHornTritonSummonDieLo',
                           'mmpHornTritonSummonDieHi',
                           'mmpHornTritonSummonCountMin',
                           'mmpHornTritonSummonCountMax',
                           'mmpHornTritonPanicAnimalOrLower',
                           'mmpHornTritonPanicToHitPenalty',
                           'mmpHornTritonPanicTurnsMin',
                           'mmpHornTritonPanicTurnsMax',
                           'mmpHornTritonPanicRoundsPerTurn',
                           'mmpHornTritonPanicRoundsMin',
                           'mmpHornTritonPanicRoundsMax',
                           'mmpHornTritonHearRadiusLeagues'])],
 'horn_of_valhalla': [(13,
                       ['mmpHornValhallaVarietyCount',
                        'mmpHornValhallaBlowIntervalDays',
                        'mmpHornValhallaSummonedAc',
                        'mmpHornValhallaSummonedHpPerDie',
                        'mmpHornValhallaSwordSpearPct',
                        'mmpHornValhallaAxeSpearPct',
                        'mmpHornValhallaServiceTurns',
                        'mmpHornValhallaAlignedPct',
                        'mmpHornValhallaBronzeXpMultiplier',
                        'mmpHornValhallaIronXpMultiplier',
                        'mmpHornValhallaDiceLo',
                        'mmpHornValhallaDiceHi',
                        'mmpHornValhallaCountMin',
                        'mmpHornValhallaCountMax',
                        'mmpHornValhallaLevel',
                        'mmpHornValhallaUsableAny',
                        'mmpHornValhallaUsableCleric',
                        'mmpHornValhallaUsableFighter',
                        'mmpHornValhallaUsableThief'])],
 'horseshoes_of_speed': [(13,
                          ['mmpHorseshoesSpeedShoeCount',
                           'mmpHorseshoesSpeedFullPct',
                           'mmpHorseshoesSpeedDropPct',
                           'mmpHorseshoesSpeedDropLeagues',
                           'mmpHorseshoesSpeedOneLostPct',
                           'mmpHorseshoesSpeedTwoLostPct'])],
 'horseshoes_of_a_zephyr': [(13,
                             ['mmpHorseshoesZephyrGroundless',
                              'mmpHorseshoesZephyrNoTracks',
                              'mmpHorseshoesZephyrNoTireHours',
                              'mmpHorseshoesZephyrPerDay'])],
 'incense_of_meditation': [(13,
                            ['mmpIncenseMedRecognizeClericLevel',
                             'mmpIncenseMedPrayHours',
                             'mmpIncenseMedCureAlwaysMax',
                             'mmpIncenseMedBroadestArea',
                             'mmpIncenseMedSavePenalty',
                             'mmpIncenseMedNotSurvivingDivisor',
                             'mmpIncenseMedPieceCountMin',
                             'mmpIncenseMedPieceCountMax',
                             'mmpIncenseMedBurnHours',
                             'mmpIncenseMedEffectHours'])],
 'incense_of_obsession': [(14,
                           ['mmpObsessionDurationHours',
                            'mmpObsessionPiecesMin',
                            'mmpObsessionPiecesMax',
                            'mmpObsessionBurnHours'])],
 'ioun_stone': [(14,
                 ['mmpIounSortCount',
                  'mmpIounOwnerRadiusFeet',
                  'mmpIounOrbitMinFeet',
                  'mmpIounOrbitMaxFeet',
                  'mmpIounFoundMin',
                  'mmpIounFoundMax',
                  'mmpIounTableRowCount',
                  'mmpIounDeadRowLo',
                  'mmpIounDeadRowHi',
                  'mmpIounStatBonusPoints',
                  'mmpIounStatCap',
                  'mmpIounStatBonusRowCount',
                  'mmpIounLevelGainLevels',
                  'mmpIounRegenHpPerTurn',
                  'mmpIounPurpleStoreMin',
                  'mmpIounPurpleStoreMax',
                  'mmpIounRoseProtectionBonus',
                  'mmpIounGrayPsionicBonus',
                  'mmpIounGrayPsionicCap',
                  'mmpIounHpToDestroy',
                  'mmpIounSaveBonus',
                  'mmpIounAttackAc',
                  'mmpIounRowRollLo',
                  'mmpIounRowRollHi',
                  'mmpIounRowAddsStat',
                  'mmpIounRowAbsorbMaxLevel',
                  'mmpIounRowBurnoutMin',
                  'mmpIounRowBurnoutMax'])],
 'fochlucan_bandore': [(14,
                        ['mmpFochlucanStringCount',
                         'mmpFochlucanLowestFaeriePct',
                         'mmpFochlucanLowestReversePct',
                         'mmpFochlucanFaerieBasePct',
                         'mmpFochlucanReverseReductionPerLevelPct',
                         'mmpFochlucanSongCount',
                         'mmpFochlucanCharmBonusPct',
                         'mmpFochlucanEntanglePerDay',
                         'mmpFochlucanShillelaghPerDay',
                         'mmpFochlucanSpeakAnimalsPerDay',
                         'mmpFochlucanLowestSongWorkPct',
                         'mmpFochlucanLowestSongFailPct',
                         'mmpFochlucanLowestFailDamageMin',
                         'mmpFochlucanLowestFailDamageMax'])],
 'mac_fuirmidh_cittern': [(15,
                           ['mmpCitternMisusePct',
                            'mmpCitternDamageMin',
                            'mmpCitternDamageMax',
                            'mmpCitternLevelGate',
                            'mmpCitternCharmBonusPct',
                            'mmpCitternSongCount'])],
 'doss_lute': [(15,
                ['mmpDossMisusePct',
                 'mmpDossDamageMin',
                 'mmpDossDamageMax',
                 'mmpDossLevelGate',
                 'mmpDossCharmBonusPct',
                 'mmpDossSongCount',
                 'mmpDossProtFireRadiusFeet'])],
 'canaith_mandolin': [(15,
                       ['mmpCanaithMisusePct',
                        'mmpCanaithDamageMin',
                        'mmpCanaithDamageMax',
                        'mmpCanaithLevelGate',
                        'mmpCanaithCharmBonusPct',
                        'mmpCanaithSongCount',
                        'mmpCanaithProtLightningRadiusFeet'])],
 'cli_lyre': [(15,
               ['mmpCliMisusePct',
                'mmpCliDamageMin',
                'mmpCliDamageMax',
                'mmpCliLevelGate',
                'mmpCliCharmBonusPct',
                'mmpCliSongCount'])],
 'anstruth_harp': [(15,
                    ['mmpAnstruthMisusePct',
                     'mmpAnstruthDamageMin',
                     'mmpAnstruthDamageMax',
                     'mmpAnstruthLevelGate',
                     'mmpAnstruthCharmBonusPct',
                     'mmpAnstruthSongCount'])],
 'ollamh_harp': [(15,
                  ['mmpOllamhDamageMin',
                   'mmpOllamhDamageMax',
                   'mmpOllamhLevelGate',
                   'mmpOllamhCharmBonusPct',
                   'mmpOllamhSongCount'])],
 'instrument_of_the_bards': [(14, ['mmpBardInstrumentCount']),
                             (15,
                              ['mmpInstrumentAbilityCount',
                               'mmpInstrumentAbilityRadiusFeet',
                               'mmpInstrumentAbilityPerDay',
                               'mmpInstrumentActivateSegments',
                               'mmpInstrumentCompleteRounds',
                               'mmpInstrumentCollegeTurnsMin',
                               'mmpInstrumentCollegeTurnsMax',
                               'mmpInstrumentMagnusTurns',
                               'mmpInstrumentCharmExcessThresholdPct',
                               'mmpInstrumentCharmExcessStepPct',
                               'mmpInstrumentCharmExcessPenaltyPerStep',
                               'mmpInstrumentKindRowCount',
                               'mmpInstrumentDieLo',
                               'mmpInstrumentDieHi'])],
 'iron_flask': [(16,
                 ['mmpFlaskRangeInches',
                  'mmpFlaskMaxCreatures',
                  'mmpFlaskServiceTurns',
                  'mmpFlaskServiceHours',
                  'mmpFlaskRepeatSaveBonus',
                  'mmpFlaskContentsRowCount',
                  'mmpFlaskContentsLo',
                  'mmpFlaskContentsHi'])],
 'javelin_of_lightning': [(16,
                           ['mmpJavelinLightningPlus',
                            'mmpJavelinLightningRangeInches',
                            'mmpJavelinLightningStrokeWidthHalfInches',
                            'mmpJavelinLightningStrokeLengthInches',
                            'mmpJavelinLightningDamageMin',
                            'mmpJavelinLightningDamageMax',
                            'mmpJavelinLightningElectricalDamage',
                            'mmpJavelinLightningBackstrokeMin',
                            'mmpJavelinLightningBackstrokeMax',
                            'mmpJavelinLightningBackstrokeInches',
                            'mmpJavelinLightningFoundMin',
                            'mmpJavelinLightningFoundMax'])],
 'javelin_of_piercing': [(16,
                          ['mmpJavelinPiercingRangeInches',
                           'mmpJavelinPiercingToHitBonus',
                           'mmpJavelinPiercingDamageMin',
                           'mmpJavelinPiercingDamageMax',
                           'mmpJavelinPiercingFoundMin',
                           'mmpJavelinPiercingFoundMax',
                           'mmpJavelinPiercingThrows'])],
 'jewel_of_attacks': [(16,
                       ['mmpJewelAttacksWanderingPct',
                        'mmpJewelAttacksPursuitPct'])],
 'jewel_of_flawlessness': [(16,
                            ['mmpJewelFlawlessBoostPct',
                             'mmpJewelFlawlessBaseTenths',
                             'mmpJewelFlawlessBoostedTenths',
                             'mmpJewelFlawlessFacetMin',
                             'mmpJewelFlawlessFacetMax',
                             'mmpJewelFlawlessTriggerD10',
                             'mmpJewelFlawlessFacetsLostPerBoost'])],
 'keoghtoms_ointment': [(16,
                         ['mmpOintmentJarDiameterInches',
                          'mmpOintmentJarDepthInches',
                          'mmpOintmentApplications',
                          'mmpOintmentHealMin',
                          'mmpOintmentHealMax',
                          'mmpOintmentFoundMin',
                          'mmpOintmentFoundMax'])],
 'librams': [(17,
              ['mmpLibramStudyWeeks',
               'mmpLibramMisuseDamageMin',
               'mmpLibramMisuseDamageMax',
               'mmpLibramUnconsciousTurnsMin',
               'mmpLibramUnconsciousTurnsMax',
               'mmpLibramInsanityRestMonths',
               'mmpLibramDamnationLevelLoss'])],
 'lyre_of_building': [(17,
                       ['mmpLyreNegateKindCount',
                        'mmpLyreNegateRounds',
                        'mmpLyreNegatePerDay',
                        'mmpLyreBuildPerWeek',
                        'mmpLyreBuildTurns',
                        'mmpLyreBuildMen',
                        'mmpLyreBuildDays',
                        'mmpLyreFalseChordPct',
                        'mmpLyreFalseChordKnownPct',
                        'mmpLyreFalseChordDisturbedPct'])],
 'manual_of_bodily_health': [(17,
                              ['mmpHealthReadHours',
                               'mmpHealthReadDaysMin',
                               'mmpHealthReadDaysMax',
                               'mmpHealthConGain',
                               'mmpHealthRegimenMonths',
                               'mmpHealthForgetMonths'])],
 'manual_of_gainful_exercise': [(17, ['mmpExerciseStrGain'])],
 'manual_of_golems': [(17,
                       ['mmpGolemKindCount',
                        'mmpGolemMinUserLevel',
                        'mmpGolemFailurePctPerLevel',
                        'mmpGolemFailureWindowTurns',
                        'mmpGolemClericXpLossMin',
                        'mmpGolemClericXpLossMax',
                        'mmpGolemMuLevelLoss',
                        'mmpGolemOtherDamageMin',
                        'mmpGolemOtherDamageMax',
                        'mmpGolemDieLo',
                        'mmpGolemDieHi',
                        'mmpGolemMonths',
                        'mmpGolemCostGp'])],
 'manual_of_puissant_skill_at_arms': [(17,
                                       ['mmpPuissantPracticeMonths',
                                        'mmpPuissantForgetMonths',
                                        'mmpPuissantStunTurnsMin',
                                        'mmpPuissantStunTurnsMax',
                                        'mmpPuissantXpLossMin',
                                        'mmpPuissantXpLossMax'])],
 'manual_of_quickness_of_action': [(17,
                                    ['mmpQuicknessStudyDays',
                                     'mmpQuicknessPracticeMonths',
                                     'mmpQuicknessDexGain',
                                     'mmpQuicknessRememberMonths'])],
 'manual_of_stealthy_pilfering': [(18,
                                   ['mmpStealthyPracticeMonths',
                                    'mmpStealthyKnowledgeMonths',
                                    'mmpStealthyAssassinXp',
                                    'mmpStealthyAssassinWeeks',
                                    'mmpStealthyWrongDamageMin',
                                    'mmpStealthyWrongDamageMax',
                                    'mmpStealthyStunRoundsMin',
                                    'mmpStealthyStunRoundsMax',
                                    'mmpStealthyXpLossMin',
                                    'mmpStealthyXpLossMax',
                                    'mmpStealthyAtoneDays',
                                    'mmpStealthyWisdomLoss'])],
 'mattock_of_the_titans': [(18,
                            ['mmpMattockLengthFeet',
                             'mmpMattockWeightLb',
                             'mmpMattockMinStrength',
                             'mmpMattockEarthCubicFeet',
                             'mmpMattockRockCubicFeet',
                             'mmpMattockAreaTurns',
                             'mmpMattockHitBonus',
                             'mmpMattockDamageMin',
                             'mmpMattockDamageMax'])],
 'maul_of_the_titans': [(18,
                         ['mmpMaulLengthFeet',
                          'mmpMaulWeightLb',
                          'mmpMaulMinStrength',
                          'mmpMaulPileDiameterFeet',
                          'mmpMaulPileDepthFeet',
                          'mmpMaulBlowsPerRound',
                          'mmpMaulDoorHeightFeet',
                          'mmpMaulDoorWidthFeet',
                          'mmpMaulDoorThicknessInches',
                          'mmpMaulDoorBlows',
                          'mmpMaulDoorIronBlows',
                          'mmpMaulHitBonus',
                          'mmpMaulDamageMin',
                          'mmpMaulDamageMax'])],
 'medallion_of_esp': [(18,
                       ['mmpEspPathWidthFeet',
                        'mmpEspBroadenFeet',
                        'mmpEspBroadenPerFeet',
                        'mmpEspMaxWidthFeet',
                        'mmpEspMaxWidthAtFeet',
                        'mmpEspUseRounds',
                        'mmpEspStoneBlockFeet',
                        'mmpEspMetalBlockSixthsFeet',
                        'mmpEspMalfunctionRoll',
                        'mmpEspMalfunctionDieSides',
                        'mmpEspRowLo',
                        'mmpEspRowHi',
                        'mmpEspRangeFeet',
                        'mmpEspEmpathy'])],
 'medallion_of_thought_projection': [(18, ['mmpProjectionWorksRoll'])],
 'mirror_of_life_trapping': [(18,
                              ['mmpTrapAreaSquareFeet',
                               'mmpTrapCellMin',
                               'mmpTrapCellMax',
                               'mmpTrapTriggerFeet',
                               'mmpTrapSeePctUnaware',
                               'mmpTrapSeePctAvoiding',
                               'mmpTrapSeePctAware',
                               'mmpTrapOverflowFreed'])],
 'mirror_of_mental_prowess': [(18,
                               ['mmpProwessQuestionsPerWeek',
                                'mmpProwessWidthFeet',
                                'mmpProwessHeightFeet'])],
 'mirror_of_opposition': [(18, [])],
 'necklace_of_adaptation': [(18, ['mmpAdaptationAirlessDays'])],
 'necklace_of_missiles': [(18,
                           ['mmpMissileRangeInches',
                            'mmpNeckRowLo',
                            'mmpNeckRowHi',
                            'mmpNeckDieOf',
                            'mmpNeckCell'])],
 'necklace_of_prayer_beads': [(19,
                               ['mmpBeadStoneMin',
                                'mmpBeadStoneMax',
                                'mmpBeadSemiPreciousPct',
                                'mmpBeadFancyPct',
                                'mmpBeadPetitionBonusPct',
                                'mmpBeadSpecialMin',
                                'mmpBeadSpecialMax',
                                'mmpBeadGemBaseGp',
                                'mmpBeadUsesPerDay',
                                'mmpBeadKarmaLevels',
                                'mmpBeadSummonsPct',
                                'mmpBeadRowLo',
                                'mmpBeadRowHi'])],
 'necklace_of_strangulation': [(19, ['mmpStrangleDamagePerRound'])],
 'net_of_entrapment': [(19,
                        ['mmpEntrapMinStrength',
                         'mmpEntrapCutAc',
                         'mmpEntrapSizeFeet',
                         'mmpEntrapMeshQuarterFeet',
                         'mmpEntrapThrowFeet',
                         'mmpEntrapCloseCubeFeet'])],
 'net_of_snaring': [(19, ['mmpSnareRangeInches'])],
 'nolzurs_marvelous_pigments': [(19,
                                 ['mmpPigPotCubicFeet',
                                  'mmpPigDepictSquareFeet',
                                  'mmpPigContainersMin',
                                  'mmpPigContainersMax',
                                  'mmpPigInstrumentFeet',
                                  'mmpPigDepictTurns'])],
 'pearl_of_power': [(19,
                     ['mmpPowerRecallPerDay',
                      'mmpPowerSpellsRecalled',
                      'mmpPowerReverseOneIn',
                      'mmpPowerDoubleMin',
                      'mmpPowerDoubleMaxLevel',
                      'mmpPowerDoubleDieSides',
                      'mmpPowerRowLo',
                      'mmpPowerRowHi',
                      'mmpPowerSpellLevel'])],
 'pearl_of_wisdom': [(19,
                      ['mmpWisdomGain',
                       'mmpWisdomMonths',
                       'mmpWisdomDays',
                       'mmpWisdomReverseOneIn'])],
 'periapt_of_foul_rotting': [(19,
                              ['mmpRotAbilityLossPerWeek',
                               'mmpRotStartWeek',
                               'mmpRotAbilityCount',
                               'mmpRotDeathScore'])],
 'periapt_of_health': [(19, [])],
 'periapt_of_proof_against_poison': [(19,
                                      ['mmpPoisonSavePctPerPlus',
                                       'mmpPoisonRowLo',
                                       'mmpPoisonRowHi',
                                       'mmpPoisonPlus'])],
 'periapt_of_wound_closure': [(19, ['mmpWoundHealRateMult'])],
 'phylactery_of_faithfulness': [(20, [])],
 'phylactery_of_long_years': [(20,
                               ['mmpLongYearsSlowPct',
                                'mmpLongYearsDonAge',
                                'mmpLongYearsMonthsPerYear',
                                'mmpLongYearsPhysicalAge',
                                'mmpLongYearsChronAge',
                                'mmpLongYearsReverseOneIn'])],
 'phylactery_of_monstrous_attention': [(20, ['mmpAttentionMinLevel'])],
 'pipes_of_the_sewers': [(20,
                          ['mmpPipeGiantRatMin',
                           'mmpPipeGiantRatMax',
                           'mmpPipeGiantRatPct',
                           'mmpPipeNormalRatMin',
                           'mmpPipeNormalRatMax',
                           'mmpPipeNormalRatPct',
                           'mmpPipeCallRangeInches',
                           'mmpPipeDelayPerInches',
                           'mmpPipeObeyPct',
                           'mmpPipeReplayObeyPct',
                           'mmpPipeReplayTurnPct',
                           'mmpPipeTakeoverPctPerRound',
                           'mmpPipeKeepPct'])],
 'portable_hole': [(20,
                    ['mmpHoleDiameterFeet',
                     'mmpHoleDepthFeet',
                     'mmpHoleBreathTurns',
                     'mmpHoleGateRadiusFeet'])],
 'quaals_feather_token': [(20,
                           ['mmpTokenUses',
                            'mmpTokenRowLo',
                            'mmpTokenRowHi',
                            'mmpTokenAnchorDays',
                            'mmpTokenBirdDays',
                            'mmpTokenFanHours',
                            'mmpTokenSwanSpeedInches',
                            'mmpTokenSwanHorses',
                            'mmpTokenSwanMen',
                            'mmpTokenSwanDays',
                            'mmpTokenTreeTrunkFeet',
                            'mmpTokenTreeHeightFeet',
                            'mmpTokenTreeTopFeet',
                            'mmpTokenWhipPlus',
                            'mmpTokenWhipLevel',
                            'mmpTokenWhipDmgMin',
                            'mmpTokenWhipDmgMax',
                            'mmpTokenWhipBindMin',
                            'mmpTokenWhipBindMax',
                            'mmpTokenWhipTurns'])],
 'robe_of_the_archmagi': [(21,
                           ['mmpArchmagiWhitePct',
                            'mmpArchmagiGrayPct',
                            'mmpArchmagiBlackPct',
                            'mmpArchmagiAcClass',
                            'mmpArchmagiMagicResistPct',
                            'mmpArchmagiSaveBonus',
                            'mmpArchmagiPenaltyPct',
                            'mmpArchmagiPenaltyMinus',
                            'mmpArchmagiCharmFamilyCount',
                            'mmpArchmagiClashDmgMin',
                            'mmpArchmagiClashDmgMax',
                            'mmpArchmagiClashDiceCount',
                            'mmpArchmagiClashDiceBonus',
                            'mmpArchmagiClashXpMin',
                            'mmpArchmagiClashXpMax',
                            'mmpArchmagiGrayDmgMin',
                            'mmpArchmagiGrayDmgMax',
                            'mmpArchmagiGrayXpMin',
                            'mmpArchmagiGrayXpMax'])],
 'robe_of_blending': [(21,
                       ['mmpBlendDetectRangeInches',
                        'mmpBlendDetectPerIntPct',
                        'mmpBlendDetectIntMin',
                        'mmpBlendLevelDetectIntMin',
                        'mmpBlendLevelDetectLevelMin',
                        'mmpBlendDetectPerLevelPct',
                        'mmpBlendExamplePct'])],
 'robe_of_eyes': [(21,
                   ['mmpEyesInfravisionInches',
                    'mmpEyesSeeInvisibleInches',
                    'mmpEyesSeeInfraredInches',
                    'mmpEyesTrackRangerLevel',
                    'mmpEyesBlindLightMin',
                    'mmpEyesBlindLightMax',
                    'mmpEyesBlindContinualMin',
                    'mmpEyesBlindContinualMax'])],
 'robe_of_powerlessness': [(21,
                            ['mmpPowerlessIntelligence',
                             'mmpPowerlessStrength'])],
 'robe_of_scintillating_colors': [(21,
                                   ['mmpScintIntMin',
                                    'mmpScintWisMin',
                                    'mmpScintLightFeet',
                                    'mmpScintStartRounds',
                                    'mmpScintTransfixMin',
                                    'mmpScintTransfixMax',
                                    'mmpScintHitPctPerRound',
                                    'mmpScintHitPctMax',
                                    'mmpScintHitMaxRounds',
                                    'mmpScintCastRangeInches',
                                    'mmpScintHypnotizeMin',
                                    'mmpScintHypnotizeMax'])],
 'robe_of_useful_items': [(21,
                           ['mmpUsefulDetachRounds',
                            'mmpUsefulBaseEach',
                            'mmpUsefulBaseCount',
                            'mmpUsefulExtraMin',
                            'mmpUsefulExtraMax',
                            'mmpUsefulGpBag',
                            'mmpUsefulCofferGp',
                            'mmpUsefulGemsCount',
                            'mmpUsefulGemValueGp',
                            'mmpUsefulLadderFeet',
                            'mmpUsefulPitCubicFeet',
                            'mmpUsefulRowboatFeet',
                            'mmpUsefulWindowWidthFeet',
                            'mmpUsefulWindowHeightFeet',
                            'mmpUsefulWindowDepthFeet',
                            'mmpUsefulScrollSpells',
                            'mmpUsefulWarDogsPair',
                            'mmpUsefulRowLo',
                            'mmpUsefulRowHi'])],
 'rope_of_climbing': [(22,
                       ['mmpClimbLengthFeet',
                        'mmpClimbWeightPounds',
                        'mmpClimbSupportPounds',
                        'mmpClimbSpeedFeetPerRound',
                        'mmpClimbKnotIntervalFeet',
                        'mmpClimbKnottedLengthFeet'])],
 'rope_of_constriction': [(22,
                           ['mmpConstrictExtraVictimsMin',
                            'mmpConstrictExtraVictimsMax',
                            'mmpConstrictVictimRangeFeet',
                            'mmpConstrictDmgMin',
                            'mmpConstrictDmgMax',
                            'mmpConstrictAcClass',
                            'mmpConstrictCutHitPoints'])],
 'rope_of_entanglement': [(22,
                           ['mmpEntangleLashFeet',
                            'mmpEntangleUpwardFeet',
                            'mmpEntangleManSizedMax',
                            'mmpEntangleStrikeSegments',
                            'mmpEntangleEntwineSegments',
                            'mmpEntangleCommandSegments',
                            'mmpEntangleWholeSegments',
                            'mmpEntangleAcClass',
                            'mmpEntangleCutHitPoints',
                            'mmpEntangleRepairTurns',
                            'mmpEntangleManUnits'])],
 'rug_of_smothering': [(22,
                        ['mmpSmotherRoundsMin',
                         'mmpSmotherRoundsMax',
                         'mmpSmotherBlockingSpells'])],
 'rug_of_welcome': [(22,
                     ['mmpWelcomeFlyWidthFeet',
                      'mmpWelcomeFlyLengthFeet',
                      'mmpWelcomeBridgeFeet',
                      'mmpWelcomeBridgeWidthFeet',
                      'mmpWelcomeAcClass',
                      'mmpWelcomeDestroyHitPoints',
                      'mmpWelcomeShrinkDivisor'])],
 'saw_of_mighty_cutting': [(22,
                            ['mmpSawLengthFeet',
                             'mmpSawWidthFeet',
                             'mmpSawSoloStrength',
                             'mmpSawTandemStrength',
                             'mmpSawTandemPersons',
                             'mmpSawHardwoodFeet',
                             'mmpSawHardwoodTurns',
                             'mmpSawTrunkFeet',
                             'mmpSawTrunkTurns',
                             'mmpSawSmallDiameterFeet',
                             'mmpSawSmallRounds',
                             'mmpSawWorkTurns',
                             'mmpSawRestTurns'])],
 'scarab_of_death': [(22,
                      ['mmpDeathHoldRounds',
                       'mmpDeathContainerFeet',
                       'mmpDeathContainerTurns',
                       'mmpDeathHeartRounds'])],
 'scarab_of_enraging_enemies': [(22,
                                 ['mmpEnrageRadiusInches',
                                  'mmpEnrageToHitBonus',
                                  'mmpEnrageDamageBonus',
                                  'mmpEnrageAcPenalty',
                                  'mmpEnrageRageMin',
                                  'mmpEnrageRageMax',
                                  'mmpEnrageChargesMin',
                                  'mmpEnrageChargesMax'])],
 'scarab_of_insanity': [(22,
                         ['mmpInsanityRadiusInches',
                          'mmpInsanitySavePenalty',
                          'mmpInsanityMagicResistPenaltyPct',
                          'mmpInsanityRoundsMin',
                          'mmpInsanityRoundsMax',
                          'mmpInsanityChargesMin',
                          'mmpInsanityChargesMax'])],
 'scarab_of_protection': [(22,
                           ['mmpProtectSaveBonus',
                            'mmpProtectNoSaveBase',
                            'mmpProtectAbsorbCount',
                            'mmpProtectReversedOneIn',
                            'mmpProtectReversedPenalty',
                            'mmpProtectFixedOneIn',
                            'mmpProtectFixedBonus',
                            'mmpProtectRemoveClericLevel',
                            'mmpProtectRemovedAbsorbCount'])],
 'spade_of_colossal_excavation': [(22,
                                   ['mmpSpadeLengthFeet',
                                    'mmpSpadeBladeWidthFeet',
                                    'mmpSpadeBladeLengthFeet',
                                    'mmpSpadeUserStrength',
                                    'mmpSpadeDigYardsPerRound',
                                    'mmpSpadeWorkRounds',
                                    'mmpSpadeRestRounds',
                                    'mmpSpadeHardPanFactor',
                                    'mmpSpadeGravelFactor',
                                    'mmpSpadeLooseSoilDivisor'])],
 'sphere_of_annihilation': [(23,
                             ['mmpSphereDiameterFeet',
                              'mmpSphereControlRangeFeet',
                              'mmpSphereControlPerLevelInches',
                              'mmpSphereBaseMoveFeetPerRound',
                              'mmpSphereIntBonusLowPct',
                              'mmpSphereIntBonusHighPct',
                              'mmpSphereIntBonusMaxPct',
                              'mmpSphereIntBonusLowStat',
                              'mmpSphereIntBonusHighStat',
                              'mmpSphereIntBonusMaxStat',
                              'mmpSphereDriftRoundsMin',
                              'mmpSphereDriftRoundsMax',
                              'mmpSphereDriftRangeFeet',
                              'mmpSphereMultiUserPenaltyPct',
                              'mmpSphereGateDestroyPct',
                              'mmpSphereGateNothingPct',
                              'mmpSphereGateTearPct',
                              'mmpSphereGateTearRadiusInches',
                              'mmpSphereCancelRadiusInches',
                              'mmpSphereCancelDmgMin',
                              'mmpSphereCancelDmgMax',
                              'mmpSphereCtlRows',
                              'mmpSphereCtlLevelLo',
                              'mmpSphereCtlLevelHi',
                              'mmpSphereCtlMoveFeet',
                              'mmpSphereCtlProbPct',
                              'mmpSphereTaliNonMuDmgMin',
                              'mmpSphereTaliNonMuDmgMax',
                              'mmpSphereTaliLowPctPerPoint',
                              'mmpSphereTaliHighPctPerPoint',
                              'mmpSphereTaliCheckIntervalRounds',
                              'mmpSphereTaliMaxMoveFeet',
                              'mmpSphereWandNegationOnTalisman',
                              'mmpSphereWandNegationOnSphere'])],
 'stone_of_controlling_earth_elementals': [(23,
                                            ['mmpEarthStoneEarthDice',
                                             'mmpEarthStoneRoughDice',
                                             'mmpEarthStoneWorkedStoneDice',
                                             'mmpEarthStoneAreaFeet',
                                             'mmpEarthStoneVolumeYards',
                                             'mmpEarthStoneRoundsMin',
                                             'mmpEarthStoneRoundsMax',
                                             'mmpEarthStonePerDay'])],
 'stone_of_good_luck': [(23,
                         ['mmpLuckSaveBonus',
                          'mmpLuckSavePctBonus',
                          'mmpLuckItemPctMin',
                          'mmpLuckItemPctMax'])],
 'stone_of_weight': [(23,
                      ['mmpLoadMoveReductionPct',
                       'mmpLoadAttackReductionPct',
                       'mmpLoadDispelClears'])],
 'talisman_of_pure_good': [(23,
                            ['mmpPureGoodCharges',
                             'mmpPureGoodRechargeable',
                             'mmpPureGoodNeutralDmgMin',
                             'mmpPureGoodNeutralDmgMax',
                             'mmpPureGoodEvilDmgMin',
                             'mmpPureGoodEvilDmgMax',
                             'mmpPureGoodNonClericDmg'])],
 'talisman_of_the_sphere': [(23, [])],
 'talisman_of_ultimate_evil': [(23, ['mmpUltimateEvilCharges'])],
 'talisman_of_zagy': [(23,
                       ['mmpZagyHostileDmgMin',
                        'mmpZagyHostileDmgMax',
                        'mmpZagyNeutralHoursMin',
                        'mmpZagyNeutralHoursMax',
                        'mmpZagyFriendlyMonthsPerChaPoint',
                        'mmpZagyWishChaDivisor',
                        'mmpZagyTrapRangeFeet',
                        'mmpZagyDiamondGp'])],
 'tome_of_clear_thought': [(23,
                            ['mmpClearThoughtIntGain',
                             'mmpClearThoughtReadHours',
                             'mmpClearThoughtReadDays',
                             'mmpClearThoughtStartWeeks',
                             'mmpClearThoughtGainMonths',
                             'mmpClearThoughtRereadGain'])],
 'tome_of_leadership_and_influence': [(23, ['mmpLeadershipChaGain'])],
 'tome_of_understanding': [(23, ['mmpUnderstandingWisGain'])],
 'trident_of_fish_command': [(23,
                              ['mmpFishCmdRadiusInches',
                               'mmpFishCmdChargeCost',
                               'mmpFishCmdProtectFeet',
                               'mmpFishCmdApproachFeet',
                               'mmpFishCmdSchoolsAsOne',
                               'mmpFishCmdChargesMin',
                               'mmpFishCmdChargesMax',
                               'mmpFishCmdMagicBonus'])],
 'trident_of_submission': [(23,
                            ['mmpSubmitMoraleDelayRounds',
                             'mmpSubmitHopelessRoundsMin',
                             'mmpSubmitHopelessRoundsMax',
                             'mmpSubmitChargesMin',
                             'mmpSubmitChargesMax',
                             'mmpSubmitMagicBonus'])],
 'trident_of_warning': [(23,
                         ['mmpWarningRadiusInches',
                          'mmpWarningScanRounds',
                          'mmpWarningChargesMin',
                          'mmpWarningChargesMax',
                          'mmpWarningChargeRounds',
                          'mmpWarningMagicBonus'])],
 'trident_of_yearning': [(23,
                          ['mmpYearningMagicPenalty',
                           'mmpYearningFreeingSpells',
                           'mmpYearningGrantsWaterBreathing'])],
 'vacuous_grimoire': [(23,
                       ['mmpVacuousSaveCount',
                        'mmpVacuousIntLoss',
                        'mmpVacuousWisLoss',
                        'mmpVacuousBurnAfterRemoveCurse'])],
 'well_of_many_worlds': [(23, ['mmpWellTwoWay'])],
 'wings_of_flying': [(23,
                      ['mmpWingsSpanFeet',
                       'mmpWingsRestHours',
                       'mmpWingsQuietHours',
                       'mmpWingsNoRestTurns',
                       'mmpWingsUsesPerDay',
                       'mmpWingsSupportPounds',
                       'mmpWingsSpeedRows',
                       'mmpWingsSpeedTurns',
                       'mmpWingsSpeedInches'])]}

HEADER_ONLY = ['mirror_of_opposition',
 'periapt_of_health',
 'phylactery_of_faithfulness',
 'talisman_of_the_sphere']

SUBS = {'figurines_of_wondrous_power': ['ebony_fly',
                                 'golden_lions',
                                 'ivory_goat_terror',
                                 'ivory_goat_travail',
                                 'ivory_goat_travel',
                                 'marble_elephant',
                                 'obsidian_stead',
                                 'onyx_dog',
                                 'serpentine_owl'],
 'instrument_of_the_bards': ['anstruth_harp',
                             'canaith_mandolin',
                             'cli_lyre',
                             'doss_lute',
                             'fochlucan_bandore',
                             'mac_fuirmidh_cittern',
                             'ollamh_harp']}

SUB_NAMES = {'ebony_fly': 'Ebony Fly',
 'golden_lions': 'Golden Lions',
 'ivory_goat_terror': 'Ivory Goat of Terror',
 'ivory_goat_travail': 'Ivory Goat of Travail',
 'ivory_goat_travel': 'Ivory Goat of Travel',
 'marble_elephant': 'Marble Elephant',
 'obsidian_stead': 'Obsidian Steed',
 'onyx_dog': 'Onyx Dog',
 'serpentine_owl': 'Serpentine Owl',
 'anstruth_harp': 'Anstruth Harp',
 'canaith_mandolin': 'Canaith Mandolin',
 'cli_lyre': 'Cli Lyre',
 'doss_lute': 'Doss Lute',
 'fochlucan_bandore': 'Fochlucan Bandore',
 'mac_fuirmidh_cittern': 'Mac-Fuirmidh Cittern',
 'ollamh_harp': 'Ollamh Harp'}

FAMILY_NAMES = {'intro': 'Intro (the misc magic section)',
 'eyes': 'Eye mix note',
 'librams': 'Librams (the three librams)'}

ALIASES = {'Figurine of Wondrous Power': 'figurines_of_wondrous_power',
 'Girdle of Femininity/Masculinity': 'girdle_of_femininity_masculinity',
 'Helm of Comprehending Languages & Reading Magic': 'helm_of_comprehending_languages_reading_magic',
 'Libram of Gainful Conjuration': 'librams',
 'Libram of Ineffable Damnation': 'librams',
 'Libram of Silver Magic': 'librams'}

TOTAL_METHODS = 1452
SCALAR_COUNT = 1329
WALKER_COUNT = 123


main()
