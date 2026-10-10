#!/usr/bin/env python3
# tools/r313_seed_splice.py - R313: the
# seed round-state entry (the knowledge
# maintenance tail of R313; the GitHub
# connector reads but cannot write, so
# the seed update rides the Termux
# ritual).
#
# Patches doc/vibe/adnd1_knowledge_seed_v2.md:
#   (a) the frontmatter era (R34-R312 -> R34-R313)
#   (b) the title era (R312 -> R313)
#   (c) Current state: the R313 bullet + the
#       closed/updated open threads
#   (d) Round state: the R313 entry + lessons
#
# Idempotent: safe to run twice; the tail
# ALWAYS prints. Markdown prose - the
# apostrophes ride double-quoted Python
# strings (no C++ content here).
# Commit: "R313: the seed round-state entry"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

P = "doc/vibe/adnd1_knowledge_seed_v2.md"

# ---- (a) the frontmatter era ----
A_OLD = "hard-won lessons (R34-R312 era; the underwater seam era is open)"
A_NEW = "hard-won lessons (R34-R313 era; the underwater seam era is open)"
# ---- (b) the title era ----
B_OLD = "# Adnd1 delivery protocol (current practice, R312 era)"
B_NEW = "# Adnd1 delivery protocol (current practice, R313 era)"
# ---- (c) Current state ----
C_OLD = NL.join([
    "- Open threads: a deeper underwater layer (the vision decay, the",
    "  uw combat pins, a breathing mechanic), a strength",
    "  weight-allowance accessor (would un-caller-feed the R311 cap),",
    "  waterborne encounter wiring, or any fresh seam / sourcebook gap",
    "  report - next round is user choice.",
])
C_NEW = NL.join([
    "- R313 landed 2026-10-10: commit e6751ff, census 239, THE",
    "  UNDERWATER FIGHT (every chargeable open thread at once):",
    "  rules/uwfight.h (the seam - uwCrossCapLbs the R311 20-lb cap",
    "  fed by the R153 strWeightAllowGp ladder, un-caller-fed;",
    "  uwCrossLoadBars; uwStrikeAllowed thrusting-only;",
    "  uwMissileBarred total - no special crossbow pinned) wired at",
    "  the R312 crossing: the enterWater load gate (a living member",
    "  past the strength-fed cap bars the company, the bump",
    "  convention; the JUDGMENT - the surface paragraph carries no",
    "  load bar, the movement paragraph folds onto the crossing);",
    "  the water fight (ai/actor setWaterFight + the public",
    "  waterStrikeAllowed probe - the crushing and cleaving swings",
    "  fail; the bare fists, the monk open hand and the monsters",
    "  outside the gate); the combatShoot/combatThrow bars in the",
    "  pool. NOT charged (recorded in the seam header): the vision",
    "  decay (no engine vision layer), the breathing aids (recorded",
    "  notes, no print pin), the aquatic first strike and nets (no",
    "  aquatic monster roster). Audits R313a (seam, audit_eval",
    "  verified bad 0, 105 asserts) + R313 (engine, replica-walked",
    "  seeds).",
    "- Open threads: the vision decay seam (needs an engine vision",
    "  layer first), a breathing mechanic (needs a print pin), the",
    "  aquatic first strike and nets (need an aquatic monster",
    "  roster), the special crossbow (unpins the missile bar),",
    "  waterborne encounter wiring, or any fresh seam / sourcebook",
    "  gap report - next round is user choice.",
])
# ---- (d) Round state ----
D_OLD = NL.join([
    "- R312 + R312b landed 2026-10-10: commit 8661437, census 237",
    "  (the flooded crossing - see Current state above).",
])
D_NEW = NL.join([
    "- R312 + R312b landed 2026-10-10: commit 8661437, census 237",
    "  (the flooded crossing - see Current state above).",
    "- R313 landed 2026-10-10: commit e6751ff, census 239, the",
    "  underwater fight (see Current state above). GREEN on the",
    "  FIRST preflight (no b-round). Lessons: (1) the include-chain",
    "  grep earned its keep AGAIN pre-delivery - state_dungeon.cpp",
    "  called the uwfight accessors with no include (the R312b bite",
    "  class, caught in the sandbox, not by preflight); (2) splice",
    "  patch COUNT asserts must track the lettered patches (a patch",
    "  g assert read 8 with 7 landed - count the letters, not the",
    "  goal); (3) post-patch chronicle asserts must quote the line",
    "  AS WRAPPED (the 57-col gap report wraps mid-phrase - assert",
    "  a wrapped fragment, never the unwrapped sentence); (4) an",
    "  actor.h anchor line with an apostrophe in a comment (the 10'",
    "  bands line) cannot serve an apostrophe-free content block -",
    "  pick another anchor (the R175 apostrophe rule cuts both",
    "  ways).",
])

# each patch carries a marker unique to the NEW text -
# an old anchor that is a prefix of its own new block
# (patch d) would re-apply on rerun otherwise
PATCHES = (
    ("a", A_OLD, A_NEW, "R34-R313 era"),
    ("b", B_OLD, B_NEW, "(current practice, R313 era)"),
    ("c", C_OLD, C_NEW, "Open threads: the vision decay seam"),
    ("d", D_OLD, D_NEW, "GREEN on the"),
)

s = rd(P)
for tag, old, new, mark in PATCHES:
    if mark in s:
        already.append(tag)
        continue
    if s.count(old) != 1:
        fails.append("patch " + tag + " anchor not unique")
        continue
    s = s.replace(old, new)
    applied.append(tag)

if fails:
    print("R313 seed splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print("R313 seed splice: FAIL - expected 4 patches, counted "
          + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if applied:
    wr(P, s)

s = rd(P)
assert s.count("R34-R313 era") == 1, "a era"
assert s.count("(current practice, R313 era)") == 1, "b era"
assert s.count("R313 landed 2026-10-10: commit e6751ff, census 239") == 2, "cd entries"
assert s.count("Open threads: the vision decay seam") == 1, "c threads"
assert s.count("GREEN on the") == 1, "d lessons"
assert s.count("## Knowledge maintenance") == 1, "tail intact"
assert s.count("## Round state (update each land)") == 1, "head intact"

print("R313 seed splice: ALL OK (applied "
      + str(len(applied)) + ", already "
      + str(len(already)) + ")")
print("R313 seed note: the seed carries the R313")
print("round-state entry and lessons; commit:")
print("R313: the seed round-state entry")

