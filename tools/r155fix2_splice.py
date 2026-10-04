# tools/r155fix2_splice.py - R155 fix 2, 1 patch: the
# R155 audit called a.asTarget() - but ai/actor.cpp is
# outside the battery link (step 2 links no ai TU), so
# the audit checks the Actor header fields instead
# (the carry compiles in the step-1 syntax gate, the
# R147 convention). Idempotent; the tail ALWAYS prints.
# ZERO backslashes; no apostrophe in any content string.
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="latin-1") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="latin-1") as f:
        f.write(s)

NL = chr(10)
old = NL.join(['        // and the actor/target carry: the displacer holds the', '        // +2 die bonus and the fighter-12 bits', '        {', '            rules::Rng rngX(1);', '            rules::Dice diceX(rngX);', '            ai::Actor a = reg.toActor("displacer_beast", diceX);', '            spelleffects::TargetDesc t = a.asTarget();', '            if (t.saveAsMask != rules::SAVE_AS_FIGHTER ||', '                    t.saveBonus != 2 || t.saveAsLevels[0] != 12)', '                ++bad;', '        }'])
new = NL.join(['        // and the actor carry: the displacer holds the +2 die', '        // bonus and the fighter-12 bits. asTarget() lives in', '        // ai/actor.cpp, outside the battery link (step 2 links', '        // no ai TU) - the header fields are checked here; the', '        // carry itself rides the syntax gate (step 1 compiles', '        // ai/actor.cpp), the R147 convention.', '        {', '            rules::Rng rngX(1);', '            rules::Dice diceX(rngX);', '            ai::Actor a = reg.toActor("displacer_beast", diceX);', '            if (a.saveAsMask != rules::SAVE_AS_FIGHTER ||', '                    a.saveAsBonus != 2 || a.saveAsLevels[0] != 12)', '                ++bad;', '        }'])
p = "regtest.cpp"
s = rd(p)
marker = "outside the battery link (step 2 links"
if marker in s:
    already.append("regtest.cpp: audit actor-field fix")
else:
    n = s.count(old)
    if n != 1:
        fails.append("regtest.cpp: anchor count " + str(n)
                     + " (expected 1)")
    else:
        wr(p, s.replace(old, new))
        applied.append("regtest.cpp: audit actor-field fix")
assert len(applied) + len(already) == 1
if fails:
    print("R155fix2 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R155fix2 splice: ALL OK (applied 0, already 1)")
else:
    print("R155fix2 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R155fix2 note: preflight again, then the census-73 commit")
