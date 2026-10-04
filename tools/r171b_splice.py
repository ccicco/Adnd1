# tools/r171b_splice.py - R171b, 2 patches: the R171
# hotfix, the drift-proof rebuild. The R171 audit
# block built its land evil-alternate array
# kLdEvil[98] with only 96 initializers: the two
# missing empty-string entries left null pointers
# at flat indices 96 and 97, and the audit walk
# dereferences every entry (kLdEvil[ldFlat][0]), so
# the battery segfaulted (exit 139); the pipe
# buffering then discarded all audit output,
# leaving the census file empty - the
# all-lines-count-0 RED. The first delivery of
# this hotfix matched its anchor by pasted
# literal text and drifted in transit (py_compile
# passes but the anchor no longer matched); this
# rebuild eliminates the problem: it EXTRACTS the
# broken block from regtest.cpp at runtime and
# rebuilds the correct 98-entry list from the
# rules/klm.h ground truth (the committed land
# rows, evil alternates included). No long
# literals to paste, nothing to drift.
#
# Patch (1): regtest.cpp - the extracted kLdEvil
# block is replaced by the correct 98-entry list
# (evil alternates at flat indices 1-4 dwarf, elf,
# halfling, gnome; 25 blink dog; 51 lammasu;
# 52 werebear; 64 couatl; 90 shedu; every other
# entry the empty string). Patch (2):
# tools/r171_splice.py - the same 96-entry element
# run inside the p3_new join is located by its
# unique bracketing elements and rebuilt from the
# same ground truth, so a fresh clone can never
# regenerate the fault. The audit logic, the
# rules/klm.h layer and the gap report are
# unchanged (census stays 89).
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R171b: fix the R171 land evil-alternate audit
# array - the two missing entries caused the battery
# segfault"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
        f.write(s)

# ---- the ground truth: the 98 land rows of rules/klm.h ----
# Each row line holds two or four double quotes; the evil
# alternate (where present) sits between quotes 3 and 4.
h = rd("rules/klm.h")
a = h.find("static const SummonedMonsterRow k[98] = {")
if a < 0:
    print("R171b splice: FAIL - land rows not found in rules/klm.h")
    sys.exit(1)
b = h.find(NL + "    };", a)
land_evils = []
for ln in h[a:b].split(NL):
    s = ln.strip()
    if not s.startswith("{ "):
        continue
    parts = s.split(DQ)
    if len(parts) == 3:
        land_evils.append("")
    elif len(parts) == 5:
        land_evils.append(parts[3])
    else:
        print("R171b splice: FAIL - unparseable klm.h row: " + s)
        sys.exit(1)
if len(land_evils) != 98:
    print("R171b splice: FAIL - expected 98 land rows, counted " + str(len(land_evils)))
    sys.exit(1)
if (land_evils[1] != "dwarf" or land_evils[25] != "blink dog"
        or land_evils[51] != "lammasu" or land_evils[64] != "couatl"
        or land_evils[90] != "shedu"):
    print("R171b splice: FAIL - klm.h land evils fail the sanity gate")
    sys.exit(1)

# the corrected 98-entry block, four entries per line
ent = [DQ + DQ if e == "" else DQ + e + DQ for e in land_evils]
new_lines = ["        static const char* kLdEvil[98] = {"]
for s in range(0, 98, 4):
    new_lines.append("            " + ", ".join(ent[s:s+4])
                     + ("," if s + 4 < 98 else ""))
new_lines.append("        };")
new_block = NL.join(new_lines)
mk1 = NL.join(["            " + DQ + DQ + ", " + DQ + DQ + ", "
               + DQ + "shedu" + DQ + ", " + DQ + DQ + ","])
mk2 = DQ + DQ + ", " + DQ + DQ + ", " + DQ + "shedu" + DQ

# ---- patch 1: regtest.cpp ----
src = rd("regtest.cpp")
if mk1 in src:
    already.append("regtest.cpp: the kLdEvil 98-entry fix")
else:
    a2 = src.find("        static const char* kLdEvil[98] = {")
    if a2 < 0:
        fails.append("regtest.cpp: kLdEvil block not found")
    else:
        b2 = src.find("};", a2) + 2
        old_block = src[a2:b2]
        n_old = (len(old_block.split(DQ)) - 1) // 2
        if (DQ + "dwarf" + DQ not in old_block
                or DQ + "shedu" + DQ not in old_block):
            fails.append("regtest.cpp: extracted block failed the sanity gate")
        else:
            wr("regtest.cpp", src.replace(old_block, new_block))
            applied.append("regtest.cpp: the kLdEvil 98-entry fix")
            print("R171b found the broken block: " + str(n_old)
                  + " of 98 entries; replaced with the klm.h truth")
assert len(applied) + len(already) == 1

# ---- patch 2: tools/r171_splice.py (the p3_new element run) ----
sp = rd("tools/r171_splice.py")
if mk2 in sp:
    already.append("tools/r171_splice.py: the kLdEvil 98-entry fix")
else:
    open_el = Q + "        static const char* kLdEvil[98] = {" + Q + ","
    close_el = Q + "        };" + Q + ","
    a3 = sp.find(open_el)
    if a3 < 0 or sp.count(open_el) != 1:
        fails.append("tools/r171_splice.py: kLdEvil element run not found")
    else:
        b3 = sp.find(close_el, a3)
        if b3 < 0:
            fails.append("tools/r171_splice.py: element run closer not found")
        else:
            b3 += len(close_el)
            new_run = " ".join(Q + l + Q + "," for l in new_lines)
            wr("tools/r171_splice.py", sp[:a3] + new_run + sp[b3:])
            applied.append("tools/r171_splice.py: the kLdEvil 98-entry fix")
assert len(applied) + len(already) == 2

# ---- R171b fails/tail ----
if fails:
    print("R171b splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 2:
    print("R171b splice: FAIL - expected 2 patches, counted " + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R171b splice: ALL OK (applied 0, already " + str(len(already)) + ")")
else:
    print("R171b splice: ALL OK (applied " + str(len(applied)) + ", already " + str(len(already)) + ")")
print("R171b note: 2 patches; census 89 unchanged; commit: R171b: fix the R171 land evil-alternate audit array - the two missing entries caused the battery segfault")
