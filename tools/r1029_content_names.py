#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1029_content_names.py
# R1029: the content-name doctrine sweep over rules/ddg and rules/dmo -
# the last form-word and concatenated-cryptic name families:
#   cqc_batch1-8   -> appendix3_<mythos range>  (joins the appendix1/2/4
#                     family; the chart slices are mythos ranges, the
#                     banner is the source)
#   lua_promo_batch1-7 -> defs_<mythos range>   (the def batches are the
#                     content; "lua" and "promo" are form words)
#   dmo<concatenated> -> the banner's operative title (the dmo prefix
#                     stutters inside rules/dmo/)
# Zero content changes except the self-identifying banner path lines.
# The R-round title comments in regtest.cpp includes stay verbatim
# (the filename-strip precedent).
#
# History NEVER rewritten: doc/vibe/ (the four seeds/backups) and
# tools/rules_reorg_pass1.py (the committed reorg tool's own record).
#
# Pure stdlib. git mv for history. Word-boundary token rewrites (the
# new paths do not contain the old tokens, so no sentinel class).
# Idempotent: run twice -> "applied 0, already 30, rewrote 0".
# ============================================================================

import json
import os
import re
import subprocess
import sys

# old stem -> new stem (same dir for every entry)
MAP = {
    # rules/ddg: the clerical quick-reference chart, Appendix 3
    "cqc_batch1": "appendix3_american_indian_to_celtic",
    "cqc_batch2": "appendix3_central_american_to_cthulhu",
    "cqc_batch3": "appendix3_egyptian_to_finnish",
    "cqc_batch4": "appendix3_greek_to_indian",
    "cqc_batch5": "appendix3_japanese_to_melnibonean",
    "cqc_batch6": "appendix3_nehwon",
    "cqc_batch7": "appendix3_nonhumans_deities",
    "cqc_batch8": "appendix3_norse_to_sumerian",
    # rules/ddg: the def promotion batches
    "lua_promo_batch1": "defs_american_indian_to_celtic",
    "lua_promo_batch2": "defs_central_american_to_egyptian",
    "lua_promo_batch3": "defs_finnish_to_greek",
    "lua_promo_batch4": "defs_indian_to_japanese",
    "lua_promo_batch5": "defs_melnibonean",
    "lua_promo_batch6": "defs_nehwon_to_nonhumans_deities",
    "lua_promo_batch7": "defs_norse_to_sumerian",
    # rules/dmo: the banner titles, dmo prefix stripped
    "dmomaxims": "seven_maxims",
    "dmocampaign": "remaining_maxims",
    "dmoadventures": "adventure_doctrines",
    "dmoworlds": "world_ratings",
    "dmomonsters": "legendary_ladder",
    "dmospells": "spells_and_magical_items",
    "dmoitems": "creating_magical_items",
    "dmoduels": "magical_duels",
    "dmodweomers": "true_dweomers",
    "dmohighlevel": "high_level_characters",
    "dmohighskills": "high_level_skills_and_warriors",
    "dmohighwizpri": "wizards_and_priests_beyond_20th",
    "dmohighrogues": "rogues_beyond_20th",
    "dmohighascend": "demihumans_divine_ascension",
    "dmoduelroster": "spell_dueling_roster_and_index",
}

DIRS = {
    "cqc_batch": "rules/ddg",
    "lua_promo_batch": "rules/ddg",
    "dmo": "rules/dmo",
}

SKIP_PREFIX = (
    "doc/vibe/",                    # history seeds/backups, never rewritten
    "tools/rules_reorg_pass1.py",   # the committed reorg tool's own record
    "tools/r1029_content_names.py", # this tool
)
TEXT_EXT = (".h", ".cpp", ".py", ".json", ".md", ".sh", ".lua", ".txt")

TOKENS = {old: re.compile(r"\b%s\b" % re.escape(old)) for old in MAP}


def fail(msg):
    print("SWEEP ABORT: %s" % msg)
    sys.exit(1)


def dir_for(stem):
    if stem.startswith("cqc_") or stem.startswith("lua_"):
        return "rules/ddg"
    return "rules/dmo"


def tracked_text_files():
    out = subprocess.run(["git", "ls-files"], capture_output=True,
                         text=True)
    if out.returncode != 0:
        fail("git ls-files failed: %s" % out.stderr.strip())
    for path in out.stdout.split("\n"):
        if not path or path.startswith(SKIP_PREFIX):
            continue
        if os.path.splitext(path)[1] not in TEXT_EXT:
            continue
        yield path


def stale_scan(files=None):
    bad = []
    for path in (files if files is not None
                 else list(tracked_text_files())):
        try:
            src = open(path, encoding="utf-8").read()
        except UnicodeDecodeError:
            continue
        for old in MAP:
            if TOKENS[old].search(src):
                bad.append((path, old))
    return bad


def main():
    os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..")
             if os.path.basename(os.getcwd()) == "tools" else ".")

    # snapshot the tracked text list BEFORE renames (git ls-files would
    # otherwise report post-rename paths mid-pass)
    files = list(tracked_text_files())

    # -- idempotency probe ---------------------------------------------
    already = 0
    applied = 0
    for old, new in sorted(MAP.items()):
        oldp = os.path.join(dir_for(old), old + ".h")
        newp = os.path.join(dir_for(old), new + ".h")
        if os.path.exists(newp):
            already += 1
            if os.path.exists(oldp):
                fail("BOTH old and new exist: %s / %s" % (oldp, newp))
        elif os.path.exists(oldp):
            applied += 1
        else:
            fail("neither exists for %s (expected %s)" % (old, oldp))

    if already == len(MAP):
        # idempotent re-run: verify clean, then exit
        bad = stale_scan()
        if bad:
            for path, old in bad:
                print("STALE: %s still references %s" % (path, old))
            fail("idempotent re-run found %d stale refs" % len(bad))
        print("applied 0, already %d, rewrote 0" % len(MAP))
        print("SWEEP OK (already applied)")
        return

    if already != 0:
        fail("half-applied tree: %d present, %d missing"
             % (already, len(MAP) - already))
    if applied != len(MAP):
        fail("gate: expected %d old files, counted %d"
             % (len(MAP), applied))

    # -- 1. token rewrite over tracked text files (BEFORE the renames, so
    # the pre-rename path snapshot still matches on-disk paths) --------
    rewrote = 0
    touched = 0
    for path in files:
        src = open(path, encoding="utf-8").read()
        out = src
        n = 0
        for old, new in sorted(MAP.items()):
            out, k = TOKENS[old].subn(new, out)
            n += k
        if n:
            open(path, "w", encoding="utf-8").write(out)
            rewrote += n
            touched += 1
    print("rewrote %d refs across %d files" % (rewrote, touched))

    # -- 2. git mv (history-preserving) --------------------------------
    for old, new in sorted(MAP.items()):
        oldp = os.path.join(dir_for(old), old + ".h")
        newp = os.path.join(dir_for(old), new + ".h")
        r = subprocess.run(["git", "mv", oldp, newp], capture_output=True,
                           text=True)
        if r.returncode != 0:
            fail("git mv %s -> %s failed: %s"
                 % (oldp, newp, r.stderr.strip()))
    print("renamed %d files (git mv 100%% renames)" % len(MAP))


    # -- 3. gates --------------------------------------------------------
    # every new file's own banner path line points at the new path
    for old, new in sorted(MAP.items()):
        newp = os.path.join(dir_for(old), new + ".h")
        head = open(newp, encoding="utf-8").read(2000)
        if "// Adnd1 - %s" % os.path.join(dir_for(old), new + ".h") \
                not in head:
            fail("self-path gate: %s banner not re-pointed" % newp)
        if TOKENS[old].search(head):
            fail("self-path gate: %s banner still carries %s" % (newp, old))

    # regtest includes re-pointed, comments verbatim
    rt = open("regtest.cpp", encoding="utf-8").read()
    for old, new in sorted(MAP.items()):
        if ('#include "%s"' % os.path.join(dir_for(old), new + ".h")) \
                not in rt:
            fail("regtest gate: include for %s missing" % new)
    n_inc = len(re.findall(r'#include "rules/(ddg|dmo)/', rt))
    if TOKENS["cqc_batch1"].search(rt) or TOKENS["dmomaxims"].search(rt):
        fail("regtest gate: old include tokens remain")

    # all spec JSONs re-validate
    nspec = 0
    for f in sorted(os.listdir("tools")):
        if not (f.startswith("spec_r") and f.endswith(".json")):
            continue
        json.load(open(os.path.join("tools", f), encoding="utf-8"))
        nspec += 1
    print("specs re-validated: %d" % nspec)

    # -- 4. stale-verify --------------------------------------------------
    bad = stale_scan()
    if bad:
        for path, old in bad:
            print("STALE: %s still references %s" % (path, old))
        fail("stale-verify found %d refs" % len(bad))

    # -- 5. census mirror (must be unchanged) -----------------------------
    pats = set()
    for path in ["regtest.cpp"] + sorted(
            os.path.join("rules/audits", f)
            for f in os.listdir("rules/audits")):
        for line in open(path, encoding="utf-8"):
            if 'printf("' not in line:
                continue
            for m in re.findall(r'[^"]*audit: bad %d', line):
                pats.add(m[:-2])
    if len(pats) != 941:
        fail("census gate: expected 941 audit printf patterns, got %d"
             % len(pats))
    print("census: 941 audit printf patterns (unchanged)")

    print("applied %d, rewrote %d" % (len(MAP), rewrote))
    print("SWEEP OK")


if __name__ == "__main__":
    main()
