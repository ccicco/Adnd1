#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/rules_reorg_pass1.py (v2)
# The rules/ cleanup, pass 1 (book-family subdirs + engine split +
# cryptic renames). v2 adds the include-repair pass: every quoted
# include is normalized to its file-relative target (fixes bare
# includes that broke when their target moved - the R400 lesson).
# Pure stdlib. Idempotent: run twice -> the second run reports
# already N, applied 0. Does NOT commit; the ritual commits after
# preflight GREEN.
# ============================================================================
import os, re, subprocess, sys

TOOL = "tools/rules_reorg_pass1.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- renames: old basename -> new path under rules/ (all .h) ---------------
RENAMES = {
    # engine plumbing
    "afw": "engine/audit_wiring",
    # Dragon magazine arc
    "ivs": "dragon/issue001_ives_tables",
    "rmz": "dragon/issue002_remorhaz_lore",
    "wmn": "dragon/issue003_women_magic_notes",
    "cfe": "dragon/issue004_creature_features",
    "cfc": "dragon/issue004_close",
    "wch": "dragon/issue005_opener",
    "cwx": "dragon/issue005_close",
    "dso": "dragon/issue006_opener",
    "csx": "dragon/issue006_close",
    "pwl": "dragon/issue007_prowler",
    "cpx": "dragon/issue007_close",
    "dgo": "dragon/issue008_opener",
    "cgx": "dragon/issue008_close",
    "dgn": "dragon/issue009_opener",
    "dnp": "dragon/issue009_close",
    "dtn": "dragon/issue010_opener1",
    "dte": "dragon/issue010_opener2",
    "dfp": "dragon/issue010_close",
    "brw": "dragon/issue011_opener",
    "bfx": "dragon/issue011_close",
    "ilv": "dragon/issue012_opener1",
    "myt": "dragon/issue012_opener2",
    "fcl": "dragon/issue012_close",
    "dgm": "dragon/issue013_opener1",
    "kmy": "dragon/issue013_opener2",
    "icl": "dragon/issue013_close",
    "lyc": "dragon/issue014_opener",
    "f14": "dragon/issue014_close",
    "drm": "dragon/issue015_opener",
    "f15": "dragon/issue015_close",
    "nin": "dragon/issue016_opener",
    "f16": "dragon/issue016_close",
    "jou": "dragon/issue017_opener1",
    "wzd": "dragon/issue017_opener2",
    "f17": "dragon/issue017_close",
    "psy": "dragon/issue018_opener1",
    "mkn": "dragon/issue018_opener2",
    "f18": "dragon/issue018_close",
    "dws": "dragon/issue019_opener1",
    "sdm": "dragon/issue019_opener2",
    "d19": "dragon/issue019_close",
    "t20": "dragon/issue020_opener1",
    "dst": "dragon/issue020_opener2",
    "d2c": "dragon/issue020_close",
    "t21": "dragon/issue021_opener1",
    "g21": "dragon/issue021_opener2",
    "d21": "dragon/issue021_close",
    "t22": "dragon/issue022_opener1",
    "s22": "dragon/issue022_opener2",
    "k22": "dragon/issue022_opener3",
    "l22": "dragon/issue022_close",
    "t23": "dragon/issue023_opener1",
    "s23": "dragon/issue023_opener2",
    "k23": "dragon/issue023_opener3",
    "l23": "dragon/issue023_close",
    "t24": "dragon/issue024_opener1",
    "s24": "dragon/issue024_opener2",
    "k24": "dragon/issue024_opener3",
    "l24": "dragon/issue024_close",
    "t25": "dragon/issue025_opener1",
    "s25": "dragon/issue025_opener2",
    "k25": "dragon/issue025_opener3",
    "l25": "dragon/issue025_close",
    "t26": "dragon/issue026_opener1",
    "s26": "dragon/issue026_opener2",
    "k26": "dragon/issue026_opener3",
    "l26": "dragon/issue026_close",
    "alc": "dragon/class_alchemist",
    "arn": "dragon/aronson_illusionist_deltas",
    "chr": "dragon/dwarves_birth_eldar",
    "cmv": "dragon/idiot_jester_dex_mods",
    "fsc": "dragon/fighting_subclasses",
    "spr": "dragon/specialists_healers_scribes",
    "sys": "dragon/systems_round",
    "fch": "dragon/fischer_hints_magic_items",
    "wrm": "dragon/witch_remainders_elf_subraces",
    "wwt": "dragon/witchcraft_wilderness_table",
    "dq1": "dragon/registry_normalization",
    "dp1": "dragon/promo_batch01",
    "dp2": "dragon/promo_batch02",
    "dp3": "dragon/promo_batch03",
    "dp4": "dragon/promo_batch04",
    "dp5": "dragon/promo_batch05",
    "dp6": "dragon/promo_batch06",
    "dp7": "dragon/promo_batch07",
    "dp8": "dragon/promo_batch08",
    "dp9": "dragon/promo_batch09",
    "dp10": "dragon/promo_batch10",
    "dp11": "dragon/promo_batch11",
    "dp12": "dragon/promo_batch12",
    # D&DG walk
    "dga": "ddg/ddg_frontmatter",
    "dgb": "ddg/mythos_american_indian",
    "dgc": "ddg/mythos_arthurian",
    "dgd": "ddg/mythos_babylonian",
    "dge": "ddg/mythos_celtic",
    "dgf": "ddg/mythos_central_american",
    "dgg": "ddg/mythos_chinese",
    "cth": "ddg/mythos_cthulhu",
    "egp": "ddg/mythos_egyptian",
    "klv": "ddg/mythos_finnish",
    "grk": "ddg/mythos_greek",
    "idn": "ddg/mythos_indian",
    "jpn": "ddg/mythos_japanese",
    "mlb": "ddg/mythos_melnibonean",
    "nhw": "ddg/mythos_nehwon",
    "nhg": "ddg/nonhumans_deities",
    "nrs": "ddg/mythos_norse",
    "smr": "ddg/mythos_sumerian",
    "afg": "ddg/alignment_figures",
    "cqc": "ddg/cqc_batch1",
    "cqc2": "ddg/cqc_batch2",
    "cqc3": "ddg/cqc_batch3",
    "cqc4": "ddg/cqc_batch4",
    "cqc5": "ddg/cqc_batch5",
    "cqc6": "ddg/cqc_batch6",
    "cqc7": "ddg/cqc_batch7",
    "cqc8": "ddg/cqc_batch8",
    "idx": "ddg/appendix4_index",
    "tpl": "ddg/appendix2_temple_trappings",
    "dpe": "ddg/lua_promo_batch1",
    "dpt": "ddg/lua_promo_batch2",
    "dpu": "ddg/lua_promo_batch3",
    "dpw": "ddg/lua_promo_batch4",
    "dpx": "ddg/lua_promo_batch5",
    "dpy": "ddg/lua_promo_batch6",
    "dpz": "ddg/lua_promo_batch7",
    "ll1": "ddg/legends_lore_parity",
    # Fiend Folio arc
    "ffp": "ff/promo_batch1",
    "ffs": "ff/promo_batch2",
    "fft": "ff/promo_batch3",
    "ffu": "ff/promo_batch4",
    "ffj": "ff/promo_batch5",
    "ffk": "ff/promo_batch6",
    "ffl": "ff/promo_batch7",
    "ffm": "ff/promo_batch8",
    "ffh": "ff/hornet_promotion",
    "ffik": "ff/index_walk",
    "ffn": "ff/monster_level_tables",
    "ffo": "ff/encounter_listings",
    "ffq": "ff/magic_item_tables",
    "fq1": "ff/normalization_batch1",
    "fq2": "ff/normalization_batch2",
    "fq3": "ff/normalization_batch3",
    "lungp": "ff/lung_dragons_promotion",
    # MM arcs
    "mn1": "mm/mm1_normalization_batch1",
    "mn2": "mm/mm1_normalization_batch2",
    "mn3": "mm/mm1_normalization_batch3",
    "mn4": "mm/mm1_normalization_batch4",
    "mn5": "mm/mm1_normalization_batch5",
    "mn6": "mm/mm1_normalization_batch6",
    "mq1": "mm/mm2_normalization_batch1",
    "mq2": "mm/mm2_normalization_batch2",
    "mq3": "mm/mm2_normalization_batch3",
    "mq4": "mm/mm2_normalization_batch4",
    "mma": "mm/mm2_arc_opener",
    "lmp": "mm/mm2_lammasu_promotion",
    # process / tooling history
    "pmb": "meta/migration_batch_pilot",
    "nmb": "meta/migration_batch_dmg_appendix",
    "tmb": "meta/migration_batch_dmg_tables",
    "qmb": "meta/migration_batch_subclass",
    "kmb": "meta/migration_batch_planes_oa",
    "vmb": "meta/migration_batch_ua_wsg",
    "xmb": "meta/migration_batch_wsg_tail_dsg",
    "jmb": "meta/migration_batch_oa_tail",
    "zmb": "meta/migration_batch_hundred",
    "fmb": "meta/migration_batch_final_digest",
    "ymb": "meta/migration_batch_final_holdback",
    "hmb": "meta/tooling_holdback_patch",
    "migw": "meta/migration_wiring",
    "rns": "meta/rn_selfpatch_guard",
    "rtk": "meta/tooling_datafiles_adaptation",
    "rsc": "meta/registry_schema",
    "rpf": "meta/rules_record_format",
    "lreg": "meta/registry_promotion_wiring",
    "prg": "meta/registry_promotion_defs",
    "prf": "meta/registry_def_name_fix",
    "cnt": "meta/content_tree_creation",
    "csh": "meta/content_structure_charter",
    "filepatchseam": "meta/file_patch_seam",
    "rtseam": "meta/rt_seam",
    "pm1": "meta/promotions_mop_batch1",
    "pm2": "meta/promotions_mop_batch2",
    "pm3": "meta/promotions_mop_batch3",
    # in place (homed at pass 2)
    "klm": "dmg_appendices_klm",
}

# --- keep-name family moves: filename prefix -> target dir ---------------
FAMILIES = [("oa", "oa"), ("ua", "ua"), ("wsg", "wsg"),
            ("dsg", "dsg"), ("dmo", "dmo"), ("mm2", "mm"),
            ("motp", "mop")]

# --- explicit keep-name moves ---------------------------------------------
EXPLICIT = {"appendixiiinnercreatures.h": "mop",
            "appendixiiioutercreatures.h": "mop",
            "appendixiprimes.h": "mop",
            "appendixivabilitiespowers.h": "mop",
            "character.cpp": "engine", "character.h": "engine",
            "classes.cpp": "engine", "classes.h": "engine",
            "combat.cpp": "engine", "combat.h": "engine",
            "dice.cpp": "engine", "dice.h": "engine",
            "races.cpp": "engine", "races.h": "engine",
            "saves.cpp": "engine", "saves.h": "engine",
            "turn.cpp": "engine", "turn.h": "engine",
            "rules_test.cpp": "engine"}


def die(msg):
    sys.stderr.write("REORG RED: " + msg + "\n")
    sys.exit(1)


def git(*args):
    r = subprocess.run(["git"] + list(args), capture_output=True,
                      text=True)
    if r.returncode != 0:
        die("git " + " ".join(args) + " -> " + r.stderr.strip())
    return r.stdout


def build_plan():
    moves = []            # (old path, new path, is_rename)
    present = set(git("ls-files", "rules/").split())
    for base, new in sorted(RENAMES.items()):
        old = "rules/" + base + ".h"
        dst = "rules/" + new + ".h"
        moves.append((old, dst, True))
    for name in sorted(present):
        if not name.startswith("rules/") or "/" in name[6:]:
            continue                      # subdir files untouched
        base = name[6:]
        if base in EXPLICIT:
            moves.append((name, "rules/" + EXPLICIT[base] + "/" + base,
                          False))
            continue
        stem = base.split(".")[0]
        if stem in RENAMES:
            continue                      # rename wins over family
        hit = None
        for pre, d in FAMILIES:
            if stem.startswith(pre):
                hit = d
                break
        if hit is not None:
            moves.append((name, "rules/" + hit + "/" + base, False))
    return present, moves


def main():
    if not os.path.isfile("regtest.cpp"):
        die("run from the repo root (regtest.cpp not found)")
    present, moves = build_plan()
    applied, already = 0, 0
    for old, new, _rn in moves:
        o_exists = old in present or os.path.isfile(old)
        n_exists = os.path.isfile(new)
        if o_exists and n_exists:
            die("both exist: " + old + " and " + new)
        if not o_exists and n_exists:
            already += 1
            continue
        if not o_exists and not n_exists:
            die("missing: " + old)
        os.makedirs(os.path.dirname(new), exist_ok=True)
        git("mv", old, new)
        applied += 1
        print("moved " + old + " -> " + new)

    # reference rewrite -----------------------------------------------------
    tracked = [f for f in git("ls-files").split()
               if f != TOOL and f not in ARCHIVE
               and not f.endswith(BIN_EXT)]
    # longest-first so dp10.h is safe from dp1.h
    path_rules = [(o, n) for o, n, _rn in moves]
    path_rules.sort(key=lambda t: -len(t[0]))
    bare_rules = [(os.path.basename(o), n) for o, n, rn in moves
                  if rn]
    bare_rules.sort(key=lambda t: -len(t[0]))
    touched = 0
    for f in tracked:
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        orig = body
        for o, n in path_rules:
            if o in body:
                body = body.replace(o, n)
        for ob, n in bare_rules:
            pat = re.compile(r"(?<![A-Za-z0-9_/])" + re.escape(ob)
                             + r"(?![A-Za-z0-9_])")
            body = pat.sub(n, body)
        if body != orig:
            with open(f, "w", encoding="utf-8") as fh:
                fh.write(body)
            touched += 1
            print("rewrote " + f)

    # include repair (v2): normalize every quoted include to its
    # file-relative target (true quoted-include semantics - the
    # R400 lesson: a moved classes.h breaks bare includes that
    # only worked at the old location). Idempotent.
    by_base = {}
    for f in tracked:
        by_base.setdefault(os.path.basename(f), []).append(f)
    inc_pat = re.compile(r'(#include\s+")([^"]+)(")')
    fixed_inc, unresolved = 0, []

    def resolve_incl(f, m):
        nonlocal fixed_inc
        d = os.path.dirname(f) or "."
        target = os.path.normpath(os.path.join(d, m.group(2)))
        if os.path.isfile(target):
            return m.group(0)              # already correct
        cands = by_base.get(os.path.basename(m.group(2)), [])
        if len(cands) == 1:
            rel = os.path.relpath(cands[0], d).replace(os.sep, "/")
            fixed_inc += 1
            return m.group(1) + rel + m.group(3)
        if not cands:
            return m.group(0)
        unresolved.append(f + ': "' + m.group(2) + '"')
        return m.group(0)

    for f in tracked:
        if not f.endswith((".h", ".cpp", ".c")):
            continue
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        new = inc_pat.sub(lambda m: resolve_incl(f, m), body)
        if new != body:
            with open(f, "w", encoding="utf-8") as fh:
                fh.write(new)
            print("fixed includes in " + f)
    if unresolved:
        for u in sorted(set(unresolved))[:40]:
            sys.stderr.write("ambiguous include " + u + "\n")
        die("ambiguous includes (" + str(len(unresolved)) + ")")

    # verify: no stale references ------------------------------------------
    stale = []
    for f in tracked:
        try:
            with open(f, "r", encoding="utf-8") as fh:
                body = fh.read()
        except (UnicodeDecodeError, IsADirectoryError):
            continue
        for o, n, rn in moves:
            if o in body:
                stale.append(f + ": " + o)
    if stale:
        for s in sorted(set(stale))[:40]:
            sys.stderr.write("stale ref " + s + "\n")
        die("stale references remain (" + str(len(stale)) + ")")
    print("REORG GREEN: applied " + str(applied) + ", already "
          + str(already) + ", moved " + str(len(moves))
          + ", rewrote " + str(touched) + " files, include_fix "
          + str(fixed_inc))


main()
