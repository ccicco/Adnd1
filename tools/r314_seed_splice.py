#!/usr/bin/env python3
# tools/r314_seed_splice.py - R314: the
# seed round-state entry (the knowledge
# maintenance tail of R314; the GitHub
# connector reads but cannot write, so
# the seed update rides the Termux
# ritual).
#
# Patches doc/vibe/adnd1_knowledge_seed_v2.md:
#   (a) the frontmatter era (R34-R313 -> R34-R314)
#   (b) the title era (R313 -> R314)
#   (c) Current state: the R314 bullet + the
#       closed/updated open threads
#   (d) Round state: the R314 entry + lessons
#
# Idempotent: safe to run twice; the tail
# ALWAYS prints. Markdown prose - the
# apostrophes ride double-quoted Python
# strings (no C++ content here).
# Commit: "R314: the seed round-state entry"
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
A_OLD = "hard-won lessons (R34-R313 era; the underwater seam era is open)"
A_NEW = "hard-won lessons (R34-R314 era; the underwater seam era is open)"
# ---- (b) the title era ----
B_OLD = "# Adnd1 delivery protocol (current practice, R313 era)"
B_NEW = "# Adnd1 delivery protocol (current practice, R314 era)"
# ---- (c) Current state ----
C_OLD = NL.join([
    "- Open threads: the vision decay seam (needs an engine vision",
    "  layer first), a breathing mechanic (needs a print pin), the",
    "  aquatic first strike and nets (need an aquatic monster",
    "  roster), the special crossbow (unpins the missile bar),",
    "  waterborne encounter wiring, or any fresh seam / sourcebook",
    "  gap report - next round is user choice.",
])
C_NEW = NL.join([
    "- R314 landed 2026-10-10: commit cabfcd8, census 241, THE",
    "  DEEP CROSSBOW, THE AQUATIC FIRST STRIKE AND THE",
    "  WATERBORNE WANDERERS (one splice): items WPN_CROSSBOW_DEEP (fights",
    "  as the light crossbow - the p.38 AC row; half the range, 3",
    "  tens of feet; ten times the price, 120 g.p.; the R311",
    "  data) and the R313 missile bar lifted for it alone",
    "  (combatShoot, the uwDeepCrossbowAllowed fold; the throw",
    "  stays barred); the aquatic first strike folded at",
    "  actor.cpp stepRound (the waterborne monsters floor at",
    "  segment 1, the company earliest at 2 - the",
    "  significantly-longer weapon exception reads data, no",
    "  reach layer exists; the JUDGMENT: no roster is pinned,",
    "  aquatic means the encounter arrived via the waterborne",
    "  table); the waterborne wanderers at the flood pool (the",
    "  R127 fresh shallow cool table, the state_sea precedent;",
    "  the count rides the registry noAppearing; the aquatic",
    "  flag rides the encounter). The net throw prose stays",
    "  data (no net item is pinned). Audits R314a (seam,",
    "  audit_eval verified bad 0) + R314 (engine,",
    "  replica-walked seeds).",
    "- Open threads: the vision decay seam (needs an engine vision",
    "  layer first), a breathing mechanic (needs a print pin), the",
    "  net throw prose (needs a net item), or any fresh seam /",
    "  sourcebook gap report - next round is user choice.",
])
# ---- (d) Round state ----
D_OLD = NL.join([
    "  pick another anchor (the R175 apostrophe rule cuts both",
    "  ways).",
])
D_NEW = NL.join([
    "  pick another anchor (the R175 apostrophe rule cuts both",
    "  ways).",
    "- R314 landed 2026-10-10: commit cabfcd8, census 241, the",
    "  deep crossbow and the aquatic wanderers (see Current",
    "  state above). GREEN on the FIRST preflight (no b-round).",
    "  Lessons: (1) the seam survey must GREP FOR THE PIN NAME",
    "  FIRST - the R311 header already pinned",
    "  uwAquaticFirstStrike, and the R314 seam reuses the",
    "  existing pin instead of redefining it (a redefinition",
    "  would shadow the data pin and break the R311 audit);",
    "  (2) the wrapped-fragment lesson rides EVERY gap-report",
    "  assert (the R314 census assert read the unwrapped",
    "  phrase and failed in the sandbox - assert what the",
    "  57-col wrap actually printed).",
])

# each patch carries a marker unique to the NEW text -
# an old anchor that is a prefix of its own new block
# (patch d) would re-apply on rerun otherwise. The
# R314 markers must NOT appear in the R313-era text
# (patch c marker cannot be the open-threads head -
# the R313-era bullet opens the same way).
PATCHES = (
    ("a", A_OLD, A_NEW, "R34-R314 era"),
    ("b", B_OLD, B_NEW, "(current practice, R314 era)"),
    ("c", C_OLD, C_NEW, "DEEP CROSSBOW, THE AQUATIC FIRST STRIKE"),
    ("d", D_OLD, D_NEW, "the seam survey must GREP"),
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
    print("R314 seed splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print("R314 seed splice: FAIL - expected 4 patches, counted "
          + str(len(applied) + len(already)) + " (a truncated paste?)")
    sys.exit(1)
if applied:
    wr(P, s)

s = rd(P)
assert s.count("R34-R314 era") == 1, "a era"
assert s.count("(current practice, R314 era)") == 1, "b era"
assert s.count("R314 landed 2026-10-10: commit cabfcd8, census 241") == 2, "cd entries"
assert s.count("DEEP CROSSBOW, THE AQUATIC FIRST STRIKE") == 1, "c bullet"
assert s.count("the seam survey must GREP") == 1, "d lessons"
assert s.count("## Knowledge maintenance") == 1, "tail intact"
assert s.count("## Round state (update each land)") == 1, "head intact"
assert s.count("R313 landed 2026-10-10: commit e6751ff, census 239") == 2, "r313 entries intact"
assert s.count("the special crossbow (unpins the missile bar)") == 0, "c old threads gone"

print("R314 seed splice: ALL OK (applied "
      + str(len(applied)) + ", already "
      + str(len(already)) + ")")
print("R314 seed note: the seed carries the R314")
print("round-state entry and lessons; commit:")
print("R314: the seed round-state entry")

