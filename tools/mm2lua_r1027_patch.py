#!/usr/bin/env python3
# R1027 (the A2 de-wire): in-place patch for tools/miscmagic2lua.py.
# Applies the boneyard re-pointing + comment-only drift rewrite.
import sys

P = "tools/miscmagic2lua.py"
src = open(P).read()


def rep(old, new):
    global src
    if new in src and old not in src:
        return          # already applied
    if old not in src:
        sys.exit("PATCH RED: anchor not found: %r" % old[:60])
    if src.count(old) != 1:
        sys.exit("PATCH RED: anchor not unique: %r" % old[:60])
    src = src.replace(old, new)


rep('# THE HEADERS STAY, untouched: they remain in rules/dmg/ as the\n'
    '# print-fidelity record (de-wiring regtest/audits is A2, a later\n'
    '# round). This land is pure data promotion - regtest, preflight and\n'
    '# the engine are NOT touched.',
    '# The headers retired to boneyard/dmg/ in R1027 (the A2 de-wire):\n'
    '# they remain the print-fidelity record - this tool still reads\n'
    '# them there - but the build no longer compiles them; the defs go\n'
    '# live through items/MiscItemRegistry, audited by the R1027\n'
    '# registry audit fragment.')

rep('        path = os.path.join(ROOT, "rules", "dmg",',
    '        path = os.path.join(ROOT, "boneyard", "dmg",')

rep('        L.append("--   rules/dmg/miscmagic_prose_part%d.h (R%d)"',
    '        L.append("--   boneyard/dmg/miscmagic_prose_part%d.h (R%d)"')

rep('    L.append("-- The part headers remain in rules/dmg/ as the")',
    '    L.append("-- The part headers remain in boneyard/dmg/ as the")')

rep('    mode = "PROMOTE" if (missing or legacy) else "VERIFY"\n'
    '    badp = [s for s in present\n'
    '            if open(def_path(s)).read() != defs[s]]\n'
    '    badl = [s for s in legacy\n'
    '            if open(legacy_path(s)).read() != defs[s]]\n'
    '    if badp or badl:\n'
    '        bad = badp or badl\n'
    '        FAIL("verify: %d present def(s) not byte-identical (%s...)"\n'
    '             % (len(bad), bad[0]))\n',
    '    badp = [s for s in present\n'
    '            if open(def_path(s)).read() != defs[s]]\n'
    '    badl = [s for s in legacy\n'
    '            if open(legacy_path(s)).read() != defs[s]]\n'
    '    if badl:\n'
    '        FAIL("verify: %d legacy def(s) not byte-identical (%s...)"\n'
    '             % (len(badl), badl[0]))\n'
    '    # present defs may drift ONLY in Lua comments (the tool reworded the\n'
    '    # header path note when the part headers moved to boneyard/dmg/);\n'
    '    # any other drift is real and stays RED\n'
    '    drifted = []\n'
    '    for s in badp:\n'
    '        old_lines = open(def_path(s)).read().splitlines()\n'
    '        new_lines = defs[s].splitlines()\n'
    '        if len(old_lines) != len(new_lines):\n'
    '            FAIL("verify: def %s drifted (line count %d -> %d)"\n'
    '                 % (s, len(old_lines), len(new_lines)))\n'
    '        for a, b in zip(old_lines, new_lines):\n'
    '            if a != b and not (a.lstrip().startswith("--")\n'
    '                               and b.lstrip().startswith("--")):\n'
    '                FAIL("verify: def %s drifted beyond comments" % s)\n'
    '        drifted.append(s)\n'
    '    mode = "PROMOTE" if (missing or legacy or drifted) else "VERIFY"\n')

rep('        for s in missing:\n'
    '            with open(def_path(s), "w") as f:\n'
    '                f.write(defs[s])\n'
    '        written = len(missing)\n',
    '        for s in missing:\n'
    '            with open(def_path(s), "w") as f:\n'
    '                f.write(defs[s])\n'
    '        for s in drifted:\n'
    '            with open(def_path(s), "w") as f:\n'
    '                f.write(defs[s])\n'
    '        written = len(missing) + len(drifted)\n')

open(P, "w").write(src)
print("mm2lua patch: GREEN")
