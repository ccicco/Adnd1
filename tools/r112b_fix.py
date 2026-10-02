#!/usr/bin/env python3
# R112b repair splice: the R112 splice's combat.cpp and regtest.cpp
# replacements both BEGIN with the same line(s) as their anchors, so
# each patch re-created its own anchor and a second run inserted the
# monster matrix section and the battery audit block a SECOND time
# (redefinition errors for kMonsterBands/kMonsterMatrix/
# monsterAttackBand/attackMatrixMonster; the battery would print the
# R112 audit line twice). This repair:
#   1. removes the duplicated monster section from rules/combat.cpp,
#   2. removes the duplicated audit block from regtest.cpp,
#   3. rewrites the splice's combat.cpp and regtest.cpp branches to
#      detect their patches by unique markers instead of the
#      self-re-creating anchors, making the splice idempotent again.
# ASCII-only. Refuses anything it does not recognize. Run twice -
# the second run must change nothing.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def dedupe_combat(c):
    HDR = ("// " + "-" * 76 + "\n"
           "// Monster attack matrix (DMG p.75-76, matrix II")
    END = "return kMonsterMatrix[row][band];\n}\n\n"
    n = c.count(HDR)
    if n == 1:
        return c, "already"
    if n != 2:
        return c, "REFUSED combat.cpp: found %d monster sections" % n
    start = c.rindex(HDR)
    end = c.index(END, start) + len(END)
    c2 = c[:start] + c[end:]
    ok = (c2.count(HDR) == 1
          and c2.count("static const int kMonsterBands") == 1
          and c2.count("static const int kMonsterAcRows") == 1
          and c2.count("static const int kMonsterMatrix") == 1
          and c2.count("static int monsterAttackBand") == 1
          and c2.count("int attackMatrixMonster(float hitDice, int ac)") == 1
          and c2.count("{") == c2.count("}"))
    if not ok:
        return c, "REFUSED combat.cpp dedupe: verification failed"
    return c2, "patched"


def dedupe_regtest(r):
    HDR = "// ---- R112: monster attack matrix audit (DMG p.75-76 II) ----"
    PRINTF = '        printf("R112 monster matrix audit: bad %d\\n", bad);\n'
    n = r.count(HDR)
    if n == 1:
        return r, "already"
    if n != 2:
        return r, "REFUSED regtest.cpp: found %d audit blocks" % n
    h2 = r.rindex(HDR)
    start = r.rindex("    }\n\n", 0, h2)
    end = r.index(PRINTF, h2) + len(PRINTF)
    r2 = r[:start] + r[end:]
    ok = (r2.count(HDR) == 1
          and r2.count("R112 monster matrix audit: bad %d") == 1
          and r2.count("R111 attack matrix audit: bad %d") == 1
          and r2.count("{") == r2.count("}"))
    if not ok:
        return r, "REFUSED regtest.cpp dedupe: verification failed"
    return r2, "patched"


SP_OLD_C = '''    c = read("rules/combat.cpp")
    c, did = replace_exact(c, CPP_OLD, CPP_NEW, "combat.cpp matrix II")
    changed = changed or did
    write("rules/combat.cpp", c)
'''
SP_NEW_C = '''    c = read("rules/combat.cpp")
    if "int attackMatrixMonster(" in c:
        print("already applied: combat.cpp matrix II")
    else:
        c, did = replace_exact(c, CPP_OLD, CPP_NEW, "combat.cpp matrix II")
        changed = changed or did
    write("rules/combat.cpp", c)
'''
SP_OLD_R = '''    r = read("regtest.cpp")
    r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R112 audit")
    changed = changed or did
    write("regtest.cpp", r)
'''
SP_NEW_R = '''    r = read("regtest.cpp")
    if 'printf("R112 monster matrix audit: bad %d' in r:
        print("already applied: regtest R112 audit")
    else:
        r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R112 audit")
        changed = changed or did
    write("regtest.cpp", r)
'''
SP_MARK_C = 'if "int attackMatrixMonster(" in c:'
SP_MARK_R = "if 'printf(\"R112 monster matrix audit: bad %d' in r:"


def main():
    changed = False

    c = read("rules/combat.cpp")
    c, msg = dedupe_combat(c)
    if msg == "patched":
        write("rules/combat.cpp", c)
        changed = True
    print(msg + (": combat.cpp duplicate monster section removed"
                 if msg == "patched" else ": combat.cpp single monster section"
                 if msg == "already" else ""))

    r = read("regtest.cpp")
    r, msg = dedupe_regtest(r)
    if msg == "patched":
        write("regtest.cpp", r)
        changed = True
    print(msg + (": regtest.cpp duplicate audit block removed"
                 if msg == "patched" else ": regtest.cpp single audit block"
                 if msg == "already" else ""))

    s = read("tools/r112_splice.py")
    if SP_MARK_C in s and SP_MARK_R in s:
        print("already applied: splice marker checks")
    elif s.count(SP_OLD_C) == 1 and s.count(SP_OLD_R) == 1:
        s = s.replace(SP_OLD_C, SP_NEW_C, 1).replace(SP_OLD_R, SP_NEW_R, 1)
        write("tools/r112_splice.py", s)
        changed = True
        print("patched: splice combat/regtest marker checks")
    else:
        print("REFUSED splice fix: anchors not unique or missing")

    print("R112b repair: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


main()
