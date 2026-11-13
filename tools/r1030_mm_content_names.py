#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1030_mm_content_names.py
# R1030: the content-name doctrine sweep over rules/mm - the MM1 and MM2
# normalization batch files carry mechanical batch numbers; the banners
# state the letter spans, so the spans are the names:
#   mm1_normalization_batch1-6 -> mm1_letters_a_to_f / g_to_k / l_to_p /
#                                 q_to_s / t_to_v / w_to_z
#   mm2_normalization_batch1-4 -> mm2_letters_a_to_d / d_to_m / m_to_s /
#                                 s_to_z
# (mm2 batch1's span rides its audited-keys list amaimon..dao; batches
#  2-4 state their spans outright: derro through mephistopheles, mihstu
#  through shadow_mastiff, shator through zygom.)
# The rules/audits rNNNN_mm1_normalization_batch_one..six names are fine
# by design (R822) and stay; they use word suffixes, so the batch-digit
# tokens cannot touch them.
# Zero content changes except the self-identifying banner path lines.
# The R-round title comments in regtest.cpp includes stay verbatim
# (the filename-strip precedent).
#
# History NEVER rewritten: doc/vibe/ (the four seeds/backups) and
# tools/rules_reorg_pass1.py (the committed reorg tool's own record).
#
# Pure stdlib. git mv for history. Word-boundary token rewrites (the
# new paths do not contain the old tokens, so no sentinel class).
# Idempotent: run twice -> "applied 0, already 10, rewrote 0".
# ============================================================================

import json
import os
import re
import subprocess
import sys

# old stem -> new stem (same dir for every entry)
MAP = {
    # rules/mm: the MM1 normalization batches, letters per banner
    "mm1_normalization_batch1": "mm1_letters_a_to_f",
    "mm1_normalization_batch2": "mm1_letters_g_to_k",
    "mm1_normalization_batch3": "mm1_letters_l_to_p",
    "mm1_normalization_batch4": "mm1_letters_q_to_s",
    "mm1_normalization_batch5": "mm1_letters_t_to_v",
    "mm1_normalization_batch6": "mm1_letters_w_to_z",
    # rules/mm: the MM2 normalization batches, letters per banner
    "mm2_normalization_batch1": "mm2_letters_a_to_d",
    "mm2_normalization_batch2": "mm2_letters_d_to_m",
    "mm2_normalization_batch3": "mm2_letters_m_to_s",
    "mm2_normalization_batch4": "mm2_letters_s_to_z",
}

SKIP_PREFIX = (
    "doc/vibe/",                    # history seeds/backups, never rewritten
    "tools/rules_reorg_pass1.py",   # the committed reorg tool's own record
    "tools/r1030_mm_content_names.py", # this tool
)
TEXT_EXT = (".h", ".cpp", ".py", ".json", ".md", ".sh", ".lua", ".txt")

TOKENS = {old: re.compile(r"\b%s\b" % re.escape(old)) for old in MAP}


def fail(msg):
    print("SWEEP ABORT: %s" % msg)
    sys.exit(1)


def dir_for(stem):
    return "rules/mm"


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
    n_inc = len(re.findall(r'#include "rules/mm/mm[12]_letters_', rt))
    if n_inc != len(MAP):
        fail("regtest gate: expected %d letters includes, got %d"
             % (len(MAP), n_inc))
    if (TOKENS["mm1_normalization_batch1"].search(rt)
            or TOKENS["mm2_normalization_batch1"].search(rt)):
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
