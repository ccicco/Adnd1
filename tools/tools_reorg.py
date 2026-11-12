#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/tools_reorg.py
# The tools/ organization pass: the G1 map pipeline (23 files -
# scan/crop, lattice/numerals, rooms/places, stamps, library.json)
# seats under tools/map/, moving TOGETHER so the same-dir python
# imports (mgrid/mstruct/mrender/mcomp/mblob, jdec) and mapp's
# --lib library.json default keep working; the 36 gap reports
# and 5 surveys seat under tools/reports/. The ritual family
# STAYS at tools/ top: the rNNN round tools, spec_r*.json, the
# engine infra (speclib/splice_engine/rverify/preflight.sh),
# the reorg history tools. The 206 historical full-path refs in
# round tools and specs rewrite mechanically. History prose in
# doc/vibe (ARCHIVE) never rewritten. No content changes, no
# commit.
import os, re, subprocess, sys

TOOL = "tools/tools_reorg.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v2.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- tools reorg: the map pipeline seats under tools/map/ (all
# 23 together - same-dir imports hold), the gap reports and
# surveys under tools/reports/; the ritual family (round tools,
# specs, engine infra, reorg history) stays at tools/ top
MOVES = {
    "tools/audit_migration_survey.md": "tools/reports/audit_migration_survey.md",
    "tools/ddg_gap_report.md": "tools/reports/ddg_gap_report.md",
    "tools/dmg_gap_report.md": "tools/reports/dmg_gap_report.md",
    "tools/dmo_gap_report.md": "tools/reports/dmo_gap_report.md",
    "tools/dragon_gap_report.md": "tools/reports/dragon_gap_report.md",
    "tools/dragon_gap_report_002.md": "tools/reports/dragon_gap_report_002.md",
    "tools/dragon_gap_report_003.md": "tools/reports/dragon_gap_report_003.md",
    "tools/dragon_gap_report_004.md": "tools/reports/dragon_gap_report_004.md",
    "tools/dragon_gap_report_005.md": "tools/reports/dragon_gap_report_005.md",
    "tools/dragon_gap_report_006.md": "tools/reports/dragon_gap_report_006.md",
    "tools/dragon_gap_report_007.md": "tools/reports/dragon_gap_report_007.md",
    "tools/dragon_gap_report_008.md": "tools/reports/dragon_gap_report_008.md",
    "tools/dragon_gap_report_009.md": "tools/reports/dragon_gap_report_009.md",
    "tools/dragon_gap_report_010.md": "tools/reports/dragon_gap_report_010.md",
    "tools/dragon_gap_report_011.md": "tools/reports/dragon_gap_report_011.md",
    "tools/dragon_gap_report_012.md": "tools/reports/dragon_gap_report_012.md",
    "tools/dragon_gap_report_013.md": "tools/reports/dragon_gap_report_013.md",
    "tools/dragon_gap_report_014.md": "tools/reports/dragon_gap_report_014.md",
    "tools/dragon_gap_report_015.md": "tools/reports/dragon_gap_report_015.md",
    "tools/dragon_gap_report_016.md": "tools/reports/dragon_gap_report_016.md",
    "tools/dragon_gap_report_017.md": "tools/reports/dragon_gap_report_017.md",
    "tools/dragon_gap_report_018.md": "tools/reports/dragon_gap_report_018.md",
    "tools/dragon_gap_report_019.md": "tools/reports/dragon_gap_report_019.md",
    "tools/dragon_gap_report_020.md": "tools/reports/dragon_gap_report_020.md",
    "tools/dragon_gap_report_021.md": "tools/reports/dragon_gap_report_021.md",
    "tools/dragon_gap_report_022.md": "tools/reports/dragon_gap_report_022.md",
    "tools/dragon_gap_report_023.md": "tools/reports/dragon_gap_report_023.md",
    "tools/dragon_gap_report_024.md": "tools/reports/dragon_gap_report_024.md",
    "tools/dragon_gap_report_025.md": "tools/reports/dragon_gap_report_025.md",
    "tools/dragon_gap_report_026.md": "tools/reports/dragon_gap_report_026.md",
    "tools/dsg_gap_report.md": "tools/reports/dsg_gap_report.md",
    "tools/fit_lattice.py": "tools/map/fit_lattice.py",
    "tools/hallscan.py": "tools/map/hallscan.py",
    "tools/jdec.py": "tools/map/jdec.py",
    "tools/jpg2png.py": "tools/map/jpg2png.py",
    "tools/library.json": "tools/map/library.json",
    "tools/maintenance_survey_r104.md": "tools/reports/maintenance_survey_r104.md",
    "tools/mapbatch.py": "tools/map/mapbatch.py",
    "tools/mapp.py": "tools/map/mapp.py",
    "tools/match.py": "tools/map/match.py",
    "tools/mblob.py": "tools/map/mblob.py",
    "tools/mcomp.py": "tools/map/mcomp.py",
    "tools/mcrop.py": "tools/map/mcrop.py",
    "tools/mgrid.py": "tools/map/mgrid.py",
    "tools/mkmap.py": "tools/map/mkmap.py",
    "tools/mkplace.py": "tools/map/mkplace.py",
    "tools/mkstairtiles.py": "tools/map/mkstairtiles.py",
    "tools/mkstamp.py": "tools/map/mkstamp.py",
    "tools/mktexstamp.py": "tools/map/mktexstamp.py",
    "tools/mm1.md": "tools/reports/mm1.md",
    "tools/mm2_gap_report.md": "tools/reports/mm2_gap_report.md",
    "tools/mnum.py": "tools/map/mnum.py",
    "tools/monsters.md": "tools/reports/monsters.md",
    "tools/motp_gap_report.md": "tools/reports/motp_gap_report.md",
    "tools/mrender.py": "tools/map/mrender.py",
    "tools/mroom.py": "tools/map/mroom.py",
    "tools/mseat.py": "tools/map/mseat.py",
    "tools/mstruct.py": "tools/map/mstruct.py",
    "tools/oa_gap_report.md": "tools/reports/oa_gap_report.md",
    "tools/phb_gap_report.md": "tools/reports/phb_gap_report.md",
    "tools/playverify_r77_r83.md": "tools/reports/playverify_r77_r83.md",
    "tools/rot90.py": "tools/map/rot90.py",
    "tools/ua_gap_report.md": "tools/reports/ua_gap_report.md",
    "tools/wsg_gap_report.md": "tools/reports/wsg_gap_report.md",
}

# --- nothing deleted this round
DELETES = ()

# --- nothing deleted this round
DELETES = ()



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
