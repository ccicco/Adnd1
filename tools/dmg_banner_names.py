#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/dmg_banner_names.py
# The rules/dmg/ naming pass: the 41 numbered/prose-series files
# take their banner names - miscprose1-23 ->
# miscmagic_prose_part1-23, miscmagic1-5 ->
# miscmagic_table1-5_footnotes, potionsprose/2/3 ->
# potions_prose_part1-3, ringsprose/2/3 -> rings_prose_part1-3,
# wandsprose/2 -> wands_prose_part1-2, rodsprose/stavesprose/
# scrollsprose -> rods/staves/scrolls_prose, specartprose/2 ->
# specart_prose_part1-2 - and the 5 terse cryptics:
# humrpref -> humanoid_preferences, magres -> magic_research,
# treasdet -> treasure_determination, scrollfab ->
# scroll_manufacture, spearset -> set_spear. Same directory,
# no content changes; regtest.cpp include lines and spec/round
# provenance refs rewrite mechanically. History prose in doc/vibe
# (ARCHIVE) never rewritten. No commit.
import os, re, subprocess, sys

TOOL = "tools/dmg_banner_names.py"
ARCHIVE = ("doc/vibe/adnd1_knowledge_backup_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v3.md",
              "doc/vibe/adnd1_knowledge_seed_v2.md",
           "doc/vibe/adnd1_seed_backup_v3.md",
           "doc/vibe/adnd1_knowledge_backup_v2.md")
BIN_EXT = (".png", ".jpg", ".jpeg", ".ico", ".pdf", ".xlsx", ".zip",
           ".b64")

# --- dmg renames: the numbered series take their banner
# names (miscproseN -> miscmagic_prose_partN, miscmagicN ->
# miscmagic_tableN_footnotes, the *prose families ->
# <family>_prose[_partN]), the terse cryptics take theirs
# (humrpref -> humanoid_preferences, magres ->
# magic_research, treasdet -> treasure_determination,
# scrollfab -> scroll_manufacture, spearset -> set_spear)
MOVES = {
    "rules/dmg/humrpref.h": "rules/dmg/humanoid_preferences.h",
    "rules/dmg/magres.h": "rules/dmg/magic_research.h",
    "rules/dmg/miscmagic1.h": "rules/dmg/miscmagic_table1_footnotes.h",
    "rules/dmg/miscmagic2.h": "rules/dmg/miscmagic_table2_footnotes.h",
    "rules/dmg/miscmagic3.h": "rules/dmg/miscmagic_table3_footnotes.h",
    "rules/dmg/miscmagic4.h": "rules/dmg/miscmagic_table4_footnotes.h",
    "rules/dmg/miscmagic5.h": "rules/dmg/miscmagic_table5_footnotes.h",
    "rules/dmg/miscprose1.h": "rules/dmg/miscmagic_explanation_part1.h",
    "rules/dmg/miscprose10.h": "rules/dmg/miscmagic_explanation_part10.h",
    "rules/dmg/miscprose11.h": "rules/dmg/miscmagic_explanation_part11.h",
    "rules/dmg/miscprose12.h": "rules/dmg/miscmagic_explanation_part12.h",
    "rules/dmg/miscprose13.h": "rules/dmg/miscmagic_explanation_part13.h",
    "rules/dmg/miscprose14.h": "rules/dmg/miscmagic_explanation_part14.h",
    "rules/dmg/miscprose15.h": "rules/dmg/miscmagic_explanation_part15.h",
    "rules/dmg/miscprose16.h": "rules/dmg/miscmagic_explanation_part16.h",
    "rules/dmg/miscprose17.h": "rules/dmg/miscmagic_explanation_part17.h",
    "rules/dmg/miscprose18.h": "rules/dmg/miscmagic_explanation_part18.h",
    "rules/dmg/miscprose19.h": "rules/dmg/miscmagic_explanation_part19.h",
    "rules/dmg/miscprose2.h": "rules/dmg/miscmagic_explanation_part2.h",
    "rules/dmg/miscprose20.h": "rules/dmg/miscmagic_explanation_part20.h",
    "rules/dmg/miscprose21.h": "rules/dmg/miscmagic_explanation_part21.h",
    "rules/dmg/miscprose22.h": "rules/dmg/miscmagic_explanation_part22.h",
    "rules/dmg/miscprose23.h": "rules/dmg/miscmagic_explanation_part23.h",
    "rules/dmg/miscprose3.h": "rules/dmg/miscmagic_explanation_part3.h",
    "rules/dmg/miscprose4.h": "rules/dmg/miscmagic_explanation_part4.h",
    "rules/dmg/miscprose5.h": "rules/dmg/miscmagic_explanation_part5.h",
    "rules/dmg/miscprose6.h": "rules/dmg/miscmagic_explanation_part6.h",
    "rules/dmg/miscprose7.h": "rules/dmg/miscmagic_explanation_part7.h",
    "rules/dmg/miscprose8.h": "rules/dmg/miscmagic_explanation_part8.h",
    "rules/dmg/miscprose9.h": "rules/dmg/miscmagic_explanation_part9.h",
    "rules/dmg/potionsprose.h": "rules/dmg/potions_explanation_part1.h",
    "rules/dmg/potionsprose2.h": "rules/dmg/potions_explanation_part2.h",
    "rules/dmg/potionsprose3.h": "rules/dmg/potions_explanation_part3.h",
    "rules/dmg/ringsprose.h": "rules/dmg/rings_explanation_part1.h",
    "rules/dmg/ringsprose2.h": "rules/dmg/rings_explanation_part2.h",
    "rules/dmg/ringsprose3.h": "rules/dmg/rings_explanation_part3.h",
    "rules/dmg/rodsprose.h": "rules/dmg/rods_explanation.h",
    "rules/dmg/scrollfab.h": "rules/dmg/scroll_manufacture.h",
    "rules/dmg/scrollsprose.h": "rules/dmg/scrolls_explanation.h",
    "rules/dmg/spearset.h": "rules/dmg/set_spear.h",
    "rules/dmg/specartprose.h": "rules/dmg/specart_explanation_part1.h",
    "rules/dmg/specartprose2.h": "rules/dmg/specart_explanation_part2.h",
    "rules/dmg/stavesprose.h": "rules/dmg/staves_explanation.h",
    "rules/dmg/treasdet.h": "rules/dmg/treasure_determination.h",
    "rules/dmg/wandsprose.h": "rules/dmg/wands_explanation_part1.h",
    "rules/dmg/wandsprose2.h": "rules/dmg/wands_explanation_part2.h",
}

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
