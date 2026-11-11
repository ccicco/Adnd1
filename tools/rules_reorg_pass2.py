#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/rules_reorg_pass2.py
# The rules/ cleanup, pass 2: the banner-read homing of the leftover
# top-level pins (156 banners read, 128 confident, 28 held for
# Curtiss's adjudication - held files are NOT in this map and stay
# put). Moves: mop/ (Manual of the Planes walk), phb/ (PHB-cited),
# dmg/ (DMG-cited, incl. armorshield/mweapons/swimcross), keep-name
# additions to ua/, and 3 renames (pln->ddg, drg/art->dragon).
# Same proven engine as pass 1 v2: git mv, reference rewrite,
# include repair, stale verify, idempotent double-run. No commit.
# ============================================================================
import os, re, subprocess, sys

TOOL = "tools/rules_reorg_pass2.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- renames: old basename -> new path under rules/ (all .h) ---------------
RENAMES = {
    "pln": "ddg/appendix1_known_planes",
    "drg": "dragon/issue001_small_variants",
    "art": "dragon/artificer_devices",
}

# --- keep-name moves: target dir -> basenames ------------------------------
MOVES = {
    "mop": [
        "abyss",
        "acheron",
        "astralplane",
        "beyondouterplanes",
        "concordantopposition",
        "elysiumbeasts",
        "gehenna",
        "hades",
        "heavenstwins",
        "indices",
        "limbopandemonium",
        "ninehells",
        "nirvanaarcadia",
        "olympusgladsheim",
        "outerplanes",
        "outerplanesseal",
        "tarterus",
    ],
    "ua": [
        "acrobat",
        "barbarian",
        "cantriptier",
        "cavalier",
        "cavmoney",
        "classtables",
        "comeliness",
        "hierophant",
        "paladin",
        "spelltableledger",
        "subracecap",
        "subracelevels",
        "subraces",
        "thiefarmor",
        "weaponspec",
    ],
    "phb": [
        "armorratings",
        "bard",
        "startmoney",
        "thieffunc",
        "weaponprof",
        "wisdom",
    ],
    "dmg": [
        "armorshield",
        "assassinate",
        "conduct",
        "construct",
        "disease",
        "dmg_appendices_klm",
        "doorforce",
        "energydrain",
        "followers",
        "grenade",
        "herbs",
        "hirecost",
        "hoard",
        "humrpref",
        "insanity",
        "itemsavethrow",
        "locktime",
        "magres",
        "miscibility",
        "miscmagic1",
        "miscmagic2",
        "miscmagic3",
        "miscmagic4",
        "miscmagic5",
        "miscprose1",
        "miscprose10",
        "miscprose11",
        "miscprose12",
        "miscprose13",
        "miscprose14",
        "miscprose15",
        "miscprose16",
        "miscprose17",
        "miscprose18",
        "miscprose19",
        "miscprose2",
        "miscprose20",
        "miscprose21",
        "miscprose22",
        "miscprose23",
        "miscprose3",
        "miscprose4",
        "miscprose5",
        "miscprose6",
        "miscprose7",
        "miscprose8",
        "miscprose9",
        "mweapons",
        "npcbody",
        "npcpersonae",
        "npctraits",
        "poison",
        "potions",
        "potionsprose",
        "potionsprose2",
        "potionsprose3",
        "pursuit",
        "rings",
        "ringsprose",
        "ringsprose2",
        "ringsprose3",
        "rodsprose",
        "rodswands",
        "scrollfab",
        "scrollpins",
        "scrollsprose",
        "secondary",
        "socialrank",
        "spearset",
        "specart",
        "specartprose",
        "specartprose2",
        "spying",
        "stavesprose",
        "subdue",
        "swimcross",
        "swords",
        "taxation",
        "treasdet",
        "twoweapon",
        "uwfight",
        "uwspells",
        "wandsprose",
        "wandsprose2",
        "weaponless",
        "weaponspeed",
        "wonder",
    ],
}

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
    moves = []
    for base, new in sorted(RENAMES.items()):
        moves.append(("rules/" + base + ".h", "rules/" + new + ".h",
                      True))
    for d, files in MOVES.items():
        for base in files:
            moves.append(("rules/" + base + ".h",
                          "rules/" + d + "/" + base + ".h", False))
    return moves


def main():
    if not os.path.isfile("regtest.cpp"):
        die("run from the repo root (regtest.cpp not found)")
    moves = build_plan()
    applied, already = 0, 0
    for old, new, _rn in moves:
        o_exists = os.path.isfile(old)
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
