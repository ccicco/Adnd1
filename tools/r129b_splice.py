#!/usr/bin/python3
# tools/r129b_splice.py - the R129 repair: the R83 audit's
# own registry band check (its "gate domain" loop) still
# read 1..6 and the six new p.14 level 7-9 spells tripped
# it (bad 6). The band widens to 1..9, mirroring the R80
# widening in the R129 splice. One patch, then preflight.
# Idempotent: safe to run twice.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

# R129B-CHUNK-1-START (the R83 band repair)

patch("regtest.cpp",
r"""
        // every registry row sits in 1..6 (the R83 gate domain)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 6) ++bad;
        }""",
r"""
        // every registry row sits in 1..9 (the R83 gate
        // domain, widened R129 alongside the R80 band: the
        // six p.14 caster-aging spells ride as levels 7-9)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 9) ++bad;
        }""",
      "regtest.cpp: R83 band widens",
      marker="widened R129 alongside the R80 band")

# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R129b splice: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
