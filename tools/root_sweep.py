#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/root_sweep.py
# The repo-root cleanup: the G1 hall-scan artifacts seat under
# extract/g1/ (the repo-as-persistence doctrine - the map-006
# commit message itself says "extract/g1: map-006 seat"), the R878
# figure crops (D&DG print p.131, FIG. 4/FIG. 5) seat under
# extract/ddg/. Deleted (git history preserves them): the
# reorg.b64 transport file, the ten zero-byte pNNN stubs, and the
# stale root hallscan.py - the fitted tool already seats at
# tools/hallscan.py (the root copy is the pre-fit template; its
# own header says "replace with fit_lattice output").
# STAY at root, ritual-anchored: regtest.cpp, adnd1.cpp,
# treasuresim.cpp, rn, bn, nn (the standing ruling - R369/R372
# struck their rebuild paths, not their presence). Deletion
# mentions in the records (the ./bn and ./nn history) are NEVER
# rewritten - they are history, not paths. No commit.
import os, re, subprocess, sys

TOOL = "tools/root_sweep.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- root moves: old repo path -> new repo path ---------------------------
MOVES = {
    "map-006.jpg": "extract/g1/map-006.jpg",
    "map-006.ask.json": "extract/g1/map-006.ask.json",
    "map-006.match.json": "extract/g1/map-006.match.json",
    "exemplars.json": "extract/g1/exemplars.json",
    "d1-132.png": "extract/ddg/d1-132.png",
    "d2-132.png": "extract/ddg/d2-132.png",
    "d3-132.png": "extract/ddg/d3-132.png",
    "d4-132.png": "extract/ddg/d4-132.png",
    "t1-132.png": "extract/ddg/t1-132.png",
    "t2-132.png": "extract/ddg/t2-132.png",
    "pg-132.png": "extract/ddg/pg-132.png",
    "pg4-132.png": "extract/ddg/pg4-132.png",
    "pg5-132.png": "extract/ddg/pg5-132.png",
}

# --- deletions: struck launchers (R369/R372: out of the repo),
# --- the pass-1 transport file, and the ten zero-byte pNNN stubs.
DELETES = (
    "reorg.b64", "hallscan.py",
    "p081_full.txt", "p081_tsv.tsv",
    "p082_full.txt", "p082_tsv.tsv",
    "p083_full.txt", "p083_tsv.tsv",
    "p084_full.txt", "p084_tsv.tsv",
    "p62_full.txt", "p62_tsv.tsv",
)



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
    return [(o, n, False) for o, n in sorted(MOVES.items())]


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

    # deletions -----------------------------------------------------------
    deleted = 0
    for d in DELETES:
        if os.path.isfile(d) or os.path.islink(d):
            git("rm", "-q", "--", d)
            deleted += 1
            print("deleted " + d)
    print("deletes applied " + str(deleted) + " of "
          + str(len(DELETES)))

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
                sent = "\x00KEEP\x00"
                body = body.replace(n, sent)
                body = body.replace(o, n)
                body = body.replace(sent, n)
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
            # n contains o (root sweep pairs), so blank out the new
            # path before looking for a stale old one
            if o in body.replace(n, "\x00"):
                stale.append(f + ": " + o)
    if stale:
        for s in sorted(set(stale))[:40]:
            sys.stderr.write("stale ref " + s + "\n")
        die("stale references remain (" + str(len(stale)) + ")")
    print("REORG GREEN: applied " + str(applied) + ", already "
          + str(already) + ", moved " + str(len(moves))
          + ", rewrote " + str(touched) + " files, include_fix "
          + str(fixed_inc) + ", deletes " + str(deleted))


main()
