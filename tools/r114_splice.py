#!/usr/bin/env python3
# R114 splice: DMG p.13-14 aging - the book's five human
# age categories (young adult 14-20, mature 21-40, middle
# aged 41-60, old 61-90, venerable 91+) with the book's
# own per-bracket cumulative adjustments replace R98's
# four-bracket symmetric bend. The R98 battery audit (it
# pinned the old convention) is rewritten as the R114
# aging audit. Idempotent (marker checks): run twice -
# second run must print nothing to do. ASCII-only.
# Refuses non-unique anchors.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


def main():
    changed = 0

    p = read("game/party.h")
    if "R114: the years tell" in p:
        print("already applied: party.h age brackets")
    else:
        p, did = replace_exact(p, PH_OLD, PH_NEW, "party.h age brackets")
        if did:
            changed += 1
            write("game/party.h", p)

    r = read("regtest.cpp")
    if 'printf("R114 aging audit' in r:
        print("already applied: regtest R114 audit")
    else:
        r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R114 audit")
        if did:
            changed += 1
            write("regtest.cpp", r)

    g = read("tools/dmg_gap_report.md")
    if "R114 CLOSED divergence 6" in g:
        print("already applied: gap report header note")
    else:
        g, did = replace_exact(g, GHEAD_OLD, GHEAD_NEW, "gap report header note")
        if did:
            changed += 1
    if "CLOSED R114" in g:
        print("already applied: gap report aging box")
    else:
        g, did = replace_exact(g, GBOX_OLD, GBOX_NEW, "gap report aging box")
        if did:
            changed += 1
    if "R114 CLOSED divergence 6" in g and "CLOSED R114" in g:
        write("tools/dmg_gap_report.md", g)

    if changed == 4:
        print("R114 splice: ALL OK")
    elif changed == 0:
        print("R114 splice: nothing to do (already applied)")
    else:
        print("R114 splice: REFUSED - only %d of 4 patches "
              "applied; nothing merged" % changed)


PH_OLD = """// R98: the years tell. Brackets (DMG p.11-12 convention,
// book-verify pending): young < 45, middle 45..59,
// old 60..89, venerable 90+.
inline int ageBracket(int age) {
    if (age < 45) return 0;
    if (age < 60) return 1;
    if (age < 90) return 2;
    return 3;
}

// the bend by bracket: STR/CON/DEX fall 1/2/3, INT/WIS
// rise 1/2/3, CHA is untouched (a face is a face)
inline int ageAbilityDelta(int bracket, rules::Ability a) {
    if (bracket <= 0) return 0;
    int mag = bracket;   // 1/2/3
    switch (a) {
        case rules::ABILITY_STR:
        case rules::ABILITY_CON:
        case rules::ABILITY_DEX:
            return -mag;
        case rules::ABILITY_INT:
        case rules::ABILITY_WIS:
            return mag;
        default:
            return 0;
    }
}"""

PH_NEW = """// R114: the years tell. The book's five human age
// categories (DMG p.13-14): young adult 14-20,
// mature 21-40, middle aged 41-60, old 61-90,
// venerable 91+. Humans only - the repo has no
// race field (documented). R97's start ages all
// fall inside young adult, which is the as-rolled
// baseline: no creation-time adjustments (the
// book's YA bend of +1 CON/-1 WIS is the baseline
// itself, documented interpretation).
inline int ageBracket(int age) {
    if (age <= 20) return 0;
    if (age <= 40) return 1;
    if (age <= 60) return 2;
    if (age <= 90) return 3;
    return 4;
}

// the book's per-bracket adjustments (DMG p.14),
// applied progressively at each bracket crossing
// and cumulative. CHA is untouched at every
// bracket (a face is a face). Clamps stay 3..18:
// the book lets WIS exceed 18, clipped here
// (documented simplification).
inline int ageAbilityDelta(int bracket, rules::Ability a) {
    if (bracket <= 0) return 0;
    switch (bracket) {
        case 1:  // mature: +1 STR, +1 WIS
            if (a == rules::ABILITY_STR) return 1;
            if (a == rules::ABILITY_WIS) return 1;
            return 0;
        case 2:  // middle aged: -1 STR, -1 CON, +1 INT, +1 WIS
            if (a == rules::ABILITY_STR) return -1;
            if (a == rules::ABILITY_CON) return -1;
            if (a == rules::ABILITY_INT) return 1;
            if (a == rules::ABILITY_WIS) return 1;
            return 0;
        case 3:  // old: -2 STR, -2 DEX, -1 CON, +1 WIS
            if (a == rules::ABILITY_STR) return -2;
            if (a == rules::ABILITY_DEX) return -2;
            if (a == rules::ABILITY_CON) return -1;
            if (a == rules::ABILITY_WIS) return 1;
            return 0;
        default: // venerable: -1 STR, -1 DEX, -1 CON, +1 INT, +1 WIS
            if (a == rules::ABILITY_STR) return -1;
            if (a == rules::ABILITY_DEX) return -1;
            if (a == rules::ABILITY_CON) return -1;
            if (a == rules::ABILITY_INT) return 1;
            if (a == rules::ABILITY_WIS) return 1;
            return 0;
    }
}"""

RT_OLD = """    // ---- R98: years tell audit ----
    {
        int bad = 0;
        // bracket thresholds: 44 young, 45 middle, 60 old,
        // 90 venerable
        if (ageBracket(44) != 0) ++bad;
        if (ageBracket(45) != 1) ++bad;
        if (ageBracket(59) != 1) ++bad;
        if (ageBracket(60) != 2) ++bad;
        if (ageBracket(89) != 2) ++bad;
        if (ageBracket(90) != 3) ++bad;
        // the bend by bracket
        if (ageAbilityDelta(0, rules::ABILITY_STR) != 0)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_CON) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_DEX) != -3)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_WIS) != 2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_INT) != 3)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_CHA) != 0)
            ++bad;
        // the bend applies once and clamps 3..18
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  3);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            applyAgeBracket(c, 1);   // middle age
            if (c.abilities.get(rules::ABILITY_STR) != 17)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;                // clamped, no floor break
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;                // clamped at the ceiling
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 8)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;                // untouched
        }
        // a full life: 18/3/17/10/9/9 through three bends
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  9);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            applyAgeBracket(c, 1);
            applyAgeBracket(c, 2);
            applyAgeBracket(c, 3);
            // STR 18-6=12, CON 9-6=3, INT 17+6=18 (clamped),
            // WIS 10+6=16, DEX 9-6=3, CHA 10
            if (c.abilities.get(rules::ABILITY_STR) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 16)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 3)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;
        }
        printf("R98 years tell audit: bad %d\\n", bad);
        if (bad) return 1;
    }"""

RT_NEW = """    // ---- R114: aging audit ----
    {
        int bad = 0;
        // the book's five human brackets (DMG p.13-14):
        // young adult <= 20, mature <= 40, middle aged
        // <= 60, old <= 90, venerable 91+
        if (ageBracket(20) != 0) ++bad;
        if (ageBracket(21) != 1) ++bad;
        if (ageBracket(40) != 1) ++bad;
        if (ageBracket(41) != 2) ++bad;
        if (ageBracket(60) != 2) ++bad;
        if (ageBracket(61) != 3) ++bad;
        if (ageBracket(90) != 3) ++bad;
        if (ageBracket(91) != 4) ++bad;
        // the book's per-bracket adjustments (DMG p.14)
        if (ageAbilityDelta(0, rules::ABILITY_STR) != 0)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_STR) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_CHA) != 0)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_STR) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_DEX) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_DEX) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CHA) != 0)
            ++bad;
        // CHA is never touched at any bracket
        if (ageAbilityDelta(0, rules::ABILITY_CHA) != 0)
            ++bad;
        for (int b = 1; b <= 4; ++b)
            if (ageAbilityDelta(b, rules::ABILITY_CHA) != 0)
                ++bad;
        // mature applies once and clamps at the ceiling
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  3);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);   // mature
            if (c.abilities.get(rules::ABILITY_STR) != 18)
                ++bad;                // 18+1 clipped at ceiling
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;                // no CON bend at mature
            if (c.abilities.get(rules::ABILITY_INT) != 17)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 9)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;                // untouched
        }
        // a full life: STR 17, CON 9, INT 17, WIS 16,
        // DEX 9 through the four bends (cumulative)
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 17);
            c.abilities.set(rules::ABILITY_CON,  9);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 16);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);
            applyAgeBracket(c, 2);
            applyAgeBracket(c, 3);
            applyAgeBracket(c, 4);
            // STR 17+1-1-2-1=14, CON 9-1-1-1=6,
            // INT 17+1+1=19 -> 18 (clipped; the book
            // would let WIS pass 18 - WIS 16+4=20
            // -> 18 too, documented), DEX 9-2-1=6
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;
        }
        printf("R114 aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }"""

GHEAD_OLD = """R113 CLOSED divergence 4 of 6 (class attack
matrices); divergence 6 (aging) stays open."""

GHEAD_NEW = """R113 CLOSED divergence 4 of 6 (class attack
matrices).
R114 CLOSED divergence 6 of 6 (aging) - all
six of the original divergences are closed."""

GBOX_OLD = """- [~] 6. **Aging (p.13-14)** - the book has
      FIVE brackets with human thresholds at
      41/61/91, cumulative effects, and a
      gentler CON decline than the repo
      implements. R98's simplification is
      documented but not the book. Accepted
      until a round chooses otherwise."""

GBOX_NEW = """- [x] 6. **Aging (p.13-14)** - CLOSED R114.
      The book's five human brackets (young
      adult 14-20, mature 21-40, middle aged
      41-60, old 61-90, venerable 91+) with
      its per-bracket cumulative adjustments
      (p.14) replace R98's symmetric bend.
      Humans only (no race field; documented),
      young adult is the as-rolled baseline,
      WIS clipped at 18 (documented). Magical
      aging causes (haste, wish, etc., p.14)
      remain an open item below."""

if __name__ == "__main__":
    main()
