#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/dmg_prose_purge.py
# The rules/dmg/ prose-suffix purge: all 36 files with "prose"
# in their names take the banner-faithful "_explanation" instead
# - the banner titles read "X explanation prose" (miscmagic,
# potions, rings, rods, staves, scrolls, wands, specart), and
# "explanation" keeps the distinction from the pin files
# (potions.h, rings.h, scrollpins.h). miscmagic_prose_part1-23
# -> miscmagic_explanation_part1-23, potions/rings/wands/
# specart_prose_partN -> ..._explanation_partN,
# rods/staves/scrolls_prose -> ..._explanation. Same directory,
# no content changes; regtest.cpp include lines and spec/round
# provenance refs rewrite mechanically. doc/vibe history prose
# (ARCHIVE) never rewritten. No commit.
import os, re, subprocess, sys

TOOL = "tools/dmg_prose_purge.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v2.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- dmg prose-suffix purge: every file with "prose" in
# its name takes the banner-faithful "_explanation"
# (the banners read "X explanation prose"; the pin files
# potions.h/rings.h keep their distinct roles)
MOVES = {
    "rules/dmg/miscmagic_prose_part1.h": "rules/dmg/miscmagic_explanation_part1.h",
    "rules/dmg/miscmagic_prose_part10.h": "rules/dmg/miscmagic_explanation_part10.h",
    "rules/dmg/miscmagic_prose_part11.h": "rules/dmg/miscmagic_explanation_part11.h",
    "rules/dmg/miscmagic_prose_part12.h": "rules/dmg/miscmagic_explanation_part12.h",
    "rules/dmg/miscmagic_prose_part13.h": "rules/dmg/miscmagic_explanation_part13.h",
    "rules/dmg/miscmagic_prose_part14.h": "rules/dmg/miscmagic_explanation_part14.h",
    "rules/dmg/miscmagic_prose_part15.h": "rules/dmg/miscmagic_explanation_part15.h",
    "rules/dmg/miscmagic_prose_part16.h": "rules/dmg/miscmagic_explanation_part16.h",
    "rules/dmg/miscmagic_prose_part17.h": "rules/dmg/miscmagic_explanation_part17.h",
    "rules/dmg/miscmagic_prose_part18.h": "rules/dmg/miscmagic_explanation_part18.h",
    "rules/dmg/miscmagic_prose_part19.h": "rules/dmg/miscmagic_explanation_part19.h",
    "rules/dmg/miscmagic_prose_part2.h": "rules/dmg/miscmagic_explanation_part2.h",
    "rules/dmg/miscmagic_prose_part20.h": "rules/dmg/miscmagic_explanation_part20.h",
    "rules/dmg/miscmagic_prose_part21.h": "rules/dmg/miscmagic_explanation_part21.h",
    "rules/dmg/miscmagic_prose_part22.h": "rules/dmg/miscmagic_explanation_part22.h",
    "rules/dmg/miscmagic_prose_part23.h": "rules/dmg/miscmagic_explanation_part23.h",
    "rules/dmg/miscmagic_prose_part3.h": "rules/dmg/miscmagic_explanation_part3.h",
    "rules/dmg/miscmagic_prose_part4.h": "rules/dmg/miscmagic_explanation_part4.h",
    "rules/dmg/miscmagic_prose_part5.h": "rules/dmg/miscmagic_explanation_part5.h",
    "rules/dmg/miscmagic_prose_part6.h": "rules/dmg/miscmagic_explanation_part6.h",
    "rules/dmg/miscmagic_prose_part7.h": "rules/dmg/miscmagic_explanation_part7.h",
    "rules/dmg/miscmagic_prose_part8.h": "rules/dmg/miscmagic_explanation_part8.h",
    "rules/dmg/miscmagic_prose_part9.h": "rules/dmg/miscmagic_explanation_part9.h",
    "rules/dmg/potions_prose_part1.h": "rules/dmg/potions_explanation_part1.h",
    "rules/dmg/potions_prose_part2.h": "rules/dmg/potions_explanation_part2.h",
    "rules/dmg/potions_prose_part3.h": "rules/dmg/potions_explanation_part3.h",
    "rules/dmg/rings_prose_part1.h": "rules/dmg/rings_explanation_part1.h",
    "rules/dmg/rings_prose_part2.h": "rules/dmg/rings_explanation_part2.h",
    "rules/dmg/rings_prose_part3.h": "rules/dmg/rings_explanation_part3.h",
    "rules/dmg/rods_prose.h": "rules/dmg/rods_explanation.h",
    "rules/dmg/scrolls_prose.h": "rules/dmg/scrolls_explanation.h",
    "rules/dmg/specart_prose_part1.h": "rules/dmg/specart_explanation_part1.h",
    "rules/dmg/specart_prose_part2.h": "rules/dmg/specart_explanation_part2.h",
    "rules/dmg/staves_prose.h": "rules/dmg/staves_explanation.h",
    "rules/dmg/wands_prose_part1.h": "rules/dmg/wands_explanation_part1.h",
    "rules/dmg/wands_prose_part2.h": "rules/dmg/wands_explanation_part2.h",
}

# --- nothing deleted this round
DELETES = ()

# --- nothing deleted this round
DELETES = ()

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
