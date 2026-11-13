#!/usr/bin/env python3
# ============================================================================
# Adnd1 - tools/r1031_batch_content_names.py
# R1031: the content-name doctrine sweep, part three - ALL remaining
# mechanical batch names in one round (37 files, three dirs):
#   rules/meta: migration_batch_* -> migration_<banner content>; the
#               "batch" is the form word, "migration" is the operation.
#               promotions_mop_batch1-3 -> promotions_mop_<content>.
#   rules/dragon: promo_batch01-12 -> promotion_<issue span per banner>.
#   rules/ff: normalization_batch1-3 -> letters_a_to_g / h_to_r /
#             book_closer (banner spans; batch3 is the stated book
#             closer). promo_batch1-8 -> promotion_<banner hook>.
# Zero content changes except the self-identifying banner path lines.
# The R-round title comments in regtest.cpp includes stay verbatim
# (the filename-strip precedent).
#
# History NEVER rewritten: doc/vibe/ (the four seeds/backups) and
# tools/rules_reorg_pass1.py (the committed reorg tool's own record).
#
# Pure stdlib. git mv for history. Word-boundary token rewrites (the
# new paths do not contain the old tokens, so no sentinel class).
# Idempotent: run twice -> "applied 0, already 37, rewrote 0".
# ============================================================================

import json
import os
import re
import subprocess
import sys

# old stem -> new stem (same dir for every entry)
MAP = {
    # rules/meta: the migration batches, banner content, batch stripped
    "migration_batch_pilot": "migration_pilot",
    "migration_batch_dmg_appendix": "migration_dmg_appendix",
    "migration_batch_dmg_tables": "migration_dmg_tables",
    "migration_batch_subclass": "migration_subclass",
    "migration_batch_hundred": "migration_hundred_blocks",
    "migration_batch_ua_wsg": "migration_ua_and_wsg",
    "migration_batch_wsg_tail_dsg": "migration_wsg_tail_and_dsg",
    "migration_batch_planes_oa": "migration_planes_and_oa",
    "migration_batch_oa_tail": "migration_oa_tail",
    "migration_batch_final_digest": "migration_final_digest",
    "migration_batch_final_holdback": "migration_final_holdback",
    # rules/meta: the promotions mop rounds, content hooks per banner
    "promotions_mop_batch1": "promotions_mop_ff_never_load_repairs",
    "promotions_mop_batch2": "promotions_mop_mm1_text_completion",
    "promotions_mop_batch3": "promotions_mop_mm1_collation",
    # rules/dragon: the Dragon promotion batches, issue spans per banner
    "promo_batch01": "promotion_pre_walk_trio_and_issue_2",
    "promo_batch02": "promotion_issue_3",
    "promo_batch03": "promotion_issue_4",
    "promo_batch04": "promotion_issues_5_to_7",
    "promo_batch05": "promotion_issues_8_to_10",
    "promo_batch06": "promotion_issues_11_to_12",
    "promo_batch07": "promotion_issues_13_to_14",
    "promo_batch08": "promotion_issues_15_to_16",
    "promo_batch09": "promotion_issues_17_to_18",
    "promo_batch10": "promotion_issues_19_to_20",
    "promo_batch11": "promotion_issues_21_to_23",
    "promo_batch12": "promotion_issues_24_to_26",
    # rules/ff: the FF normalization batches, banner spans
    "normalization_batch1": "letters_a_to_g",
    "normalization_batch2": "letters_h_to_r",
    "normalization_batch3": "book_closer",
    # rules/ff: the FF promotion batches, banner hooks
    "promo_batch1": "promotion_arc_opener",
    "promo_batch2": "promotion_disenchanter_to_sandman",
    "promo_batch3": "promotion_outdoor_tail",
    "promo_batch4": "promotion_dungeon_cells",
    "promo_batch5": "promotion_missing_prints_opener",
    "promo_batch6": "promotion_prints_flind_to_kuo_toa",
    "promo_batch7": "promotion_prints_lamia_noble_to_umpleby",
    "promo_batch8": "promotion_print_walk_closer",
}

SKIP_PREFIX = (
    "doc/vibe/",                    # history seeds/backups, never rewritten
    "tools/rules_reorg_pass1.py",   # the committed reorg tool's own record
    "tools/r1031_batch_content_names.py", # this tool
)
TEXT_EXT = (".h", ".cpp", ".py", ".json", ".md", ".sh", ".lua", ".txt")

TOKENS = {old: re.compile(r"\b%s\b" % re.escape(old)) for old in MAP}


def fail(msg):
    print("SWEEP ABORT: %s" % msg)
    sys.exit(1)


def dir_for(stem):
    if stem.startswith("migration_") or stem.startswith("promotions_"):
        return "rules/meta"
    if re.match(r"promo_batch\d\d$", stem):      # zero-padded = dragon
        return "rules/dragon"
    return "rules/ff"   # single-digit promo batches + normalization batches


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
    for old in MAP:
        if TOKENS[old].search(rt):
            fail("regtest gate: old include token remains (%s)" % old)

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
