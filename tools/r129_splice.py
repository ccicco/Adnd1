#!/usr/bin/python3
# tools/r129_splice.py - R129 magical aging causes, closed
# (DMG p.14 - the caster-aged spells enter the registry).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - spells/spells.h + .cpp: the six p.14 spells join the
#    registry (limited wish MU7/1, alter reality MU7/3,
#    wish MU9/3, gate MU9/5, restoration CL7/2,
#    resurrection CL7/3 - years stolen from the caster);
#    appended ids keep saved knownSpells indices valid
#  - spells.cpp: magicalAgingYears pins the six causes
#    (DMG p.14); the rows are TARGET_SELF - the aging
#    rider's "target" IS the caster (the book's semantics)
#  - ai/actor.cpp: the R115 rider comment updated - the
#    caster-aged causes are in the registry since R129
#  - regtest.cpp: the R80 audit band widens to levels
#    1-9 (L7-9 are "known, cast pending" rows - the slot
#    tables encode 1-6, so spellSlots yields 0 until the
#    high-level name-level tables arrive, documented);
#    the R129 caster aging audit pins the causes, rows,
#    and slot behavior (census 47)
#  - tools/dmg_gap_report.md: the p.14 box flips CLOSED
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
    # idempotency keys on a distinctive NEW-side marker
    # (the R125 lesson; an anchor that is a PREFIX of its
    # replacement still counts after the patch)
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

# R129-CHUNK-1-START (spells.h + spells.cpp)

patch("spells/spells.h",
r"""
    CL_INSECT_PLAGUE,
    CL_HEAL,
    SPELL_COUNT
};""",
r"""
    CL_INSECT_PLAGUE,
    CL_HEAL,
    // --- R129: the DMG p.14 caster-aging spells (levels
    //     7-9; appended ids keep saved knownSpells indices
    //     valid). TARGET_SELF rows: the aging rider treats
    //     the target as the caster (the book's semantics -
    //     the p.14 years land on the caster).
    MU_LIMITED_WISH,     // MU 7; caster ages 1 (p.14)
    MU_ALTER_REALITY,    // MU 7; caster ages 3 (p.14)
    MU_WISH,             // MU 9; caster ages 3 (p.14)
    MU_GATE,             // MU 9; caster ages 5 (p.14)
    CL_RESTORATION,      // CL 7; caster ages 2 (p.14)
    CL_RESURRECTION,     // CL 7; caster ages 3 (p.14)
    SPELL_COUNT
};""",
      "spells.h: R129 ids",
      marker="MU_LIMITED_WISH")

patch("spells/spells.h",
r"""
// R115: the years a spell steals (DMG p.14 magical aging
// causes): a haste spell costs its recipient 1 year. The
// caster-aged causes (limited wish 1, restoration 2,
// resurrection 3, wish 3, alter reality 3, gate 5) return
// their years when those spells enter the registry; the
// speed potion's 1 year is the item layer's, and found
// potions collapse into the healing stack today
// (documented - open item in the gap report).
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id);""",
r"""
// R115: the years a spell steals (DMG p.14 magical aging
// causes): a haste spell costs its recipient 1 year.
// R129: the caster-aged causes are in the registry and
// pinned - limited wish 1, restoration 2, resurrection 3,
// wish 3, alter reality 3, gate 5 - their rows are
// TARGET_SELF, so the aging rider's "target" IS the
// caster (the book's semantics; see ai/actor.cpp). The
// speed potion's 1 year remains the item layer's - found
// potions collapse into the healing stack today
// (documented engine limit, named in the gap report).
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id);""",
      "spells.h: aging comment",
      marker="R129: the caster-aged causes are in the registry")

patch("spells/spells.cpp",
r"""
    { "Heal",                SPELL_CLERIC, 6,  6,  0,  0,  -1, TARGET_CREATURE,   0, 8, 8, true  },
};""",
r"""
    { "Heal",                SPELL_CLERIC, 6,  6,  0,  0,  -1, TARGET_CREATURE,   0, 8, 8, true  },
    // ---- R129: the DMG p.14 caster-aging spells (levels
    // 7-9). "Known, cast pending" rows (the R80 utility
    // convention): the slot tables encode levels 1-6, so
    // spellSlots() yields 0 for these until the high-level
    // (name level+) tables arrive in a future round -
    // documented; the p.14 aging pins ride
    // magicalAgingYears regardless. TARGET_SELF: the aging
    // rider ages the target - for these rows the target IS
    // the caster. Casting times ride the file's convention
    // (MU = spell level segments, cleric = spell level + 1)
    // under the standing verification debt.
    { "Limited Wish",      SPELL_MU,     7,  7,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Alter Reality",     SPELL_MU,     7,  7,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Wish",              SPELL_MU,     9,  9,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Gate",              SPELL_MU,     9,  9,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Restoration",      SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Resurrection",     SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
};""",
      "spells.cpp: R129 rows",
      marker="R129: the DMG p.14 caster-aging spells (levels")

patch("spells/spells.cpp",
r"""
int magicalAgingYears(SpellId id) {
    if (id == MU_HASTE) return 1;   // p.14: under a haste spell
    return 0;
}""",
r"""
int magicalAgingYears(SpellId id) {
    if (id == MU_HASTE) return 1;   // p.14: under a haste spell
    // R129: the p.14 caster-aged causes (TARGET_SELF rows -
    // the rider ages the caster)
    if (id == MU_LIMITED_WISH)  return 1;   // p.14
    if (id == CL_RESTORATION)   return 2;   // p.14
    if (id == MU_ALTER_REALITY) return 3;   // p.14
    if (id == MU_WISH)          return 3;   // p.14
    if (id == CL_RESURRECTION)  return 3;   // p.14
    if (id == MU_GATE)          return 5;   // p.14
    return 0;
}""",
      "spells.cpp: aging pins",
      marker="if (id == MU_LIMITED_WISH)  return 1;")

# R129-CHUNK-1-END
# R129-CHUNK-2-START (actor + regtest + gap report)

patch("ai/actor.cpp",
r"""
        // R115: the years the spell steals (DMG p.14)
        // ride the actor and land on the Character at
        // the sync. Characters only - monsters track no
        // age. (The book's caster-aged causes - wish,
        // gate, etc. - will land here too when those
        // spells enter the registry.)""",
r"""
        // R115: the years the spell steals (DMG p.14)
        // ride the actor and land on the Character at
        // the sync. Characters only - monsters track no
        // age. R129: the caster-aged causes are in the
        // registry - their rows are TARGET_SELF, so the
        // target here IS the caster (the p.14 pins ride
        // spells.cpp).""",
      "actor.cpp: aging rider comment",
      marker="R129: the caster-aged causes are in the")

patch("regtest.cpp",
r"""
        int bad = 0, mu = 0, cl = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            if (s.level < 1 || s.level > 6) ++bad;
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu; else ++cl;
            if (s.level >= 4) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }""",
r"""
        int bad = 0, mu = 0, cl = 0, l46 = 0;
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s =
                spells::spell((spells::SpellId)id);
            // R129: the band widens to 1-9 - the p.14
            // caster-aging spells ride as levels 7-9
            if (s.level < 1 || s.level > 9) ++bad;
            if (s.sclass != spells::SPELL_MU &&
                s.sclass != spells::SPELL_CLERIC) ++bad;
            if (s.sclass == spells::SPELL_MU) ++mu; else ++cl;
            if (s.level >= 4 && s.level <= 6) {
                ++l46;
                // a slot row exists that can cast it
                if (spells::spellSlots(s.sclass, 12, s.level) < 1)
                    ++bad;
            }
        }""",
      "regtest.cpp: R80 band widens",
      marker="s.level > 9) ++bad;")

patch("regtest.cpp",
r"""
        printf("R128 special rooms audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
r"""
        printf("R128 special rooms audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R129: caster aging audit ----
    {
        int bad = 0;
        // the registry grew to 54: MU 31, CL 23
        if (spells::SPELL_COUNT != 54) ++bad;
        {
            int mu = 0, cl = 0;
            for (int id = 0; id < spells::SPELL_COUNT; ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_MU) ++mu;
                else ++cl;
            }
            if (mu != 31 || cl != 23) ++bad;
        }
        // the six p.14 rows: name, class, level, self-target
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_LIMITED_WISH);
            if (std::string(d.name) != "Limited Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_ALTER_REALITY);
            if (std::string(d.name) != "Alter Reality" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_WISH);
            if (std::string(d.name) != "Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_GATE);
            if (std::string(d.name) != "Gate" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESTORATION);
            if (std::string(d.name) != "Restoration" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESURRECTION);
            if (std::string(d.name) != "Resurrection" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        // the DMG p.14 pins: the caster-aged causes
        if (spells::magicalAgingYears(
                spells::MU_LIMITED_WISH) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESTORATION) != 2) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_ALTER_REALITY) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_WISH) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESURRECTION) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_GATE) != 5) ++bad;
        // the R115 precedent stands
        if (spells::magicalAgingYears(
                spells::MU_HASTE) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_FIREBALL) != 0) ++bad;
        // cast-pending: the slot tables encode 1-6, so
        // levels 7-9 yield no slots at any class level
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 7) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 9) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_CLERIC, 12, 7) != 0) ++bad;
        printf("R129 caster aging audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
      "regtest.cpp: R129 caster aging audit",
      marker="R129: caster aging audit")

patch("tools/dmg_gap_report.md",
r"""
- [ ] **Magical aging causes, remainder
      (p.14)** - haste is wired (R115:
      spells::magicalAgingYears +
      applyMagicalAging, landed at the
      fight-end sync, persisted as
      "mageage"). The caster-aged causes -
      limited wish 1, restoration 2,
      resurrection 3, wish 3, alter reality
      3, gate 5 - await those spells
      entering the registry; the speed
      potion's 1 year awaits a potion
      identity surviving pickup (found
      potions collapse into the healing
      stack today). The hire's stolen years
      land nowhere (no hire brackets).""",
r"""
- [x] **Magical aging causes, remainder
      (p.14)** - CLOSED R129: the six
      caster-aged causes enter the spell
      registry - Limited Wish (MU7, ages the
      caster 1), Alter Reality (MU7, 3),
      Wish (MU9, 3), Gate (MU9, 5),
      Restoration (CL7, 2), Resurrection
      (CL7, 3) - appended ids so saved
      knownSpells indices stay valid. Their
      rows are TARGET_SELF: the R115 aging
      rider ages the rider's target, which
      for these spells IS the caster (the
      book's semantics; the years land at
      the fight-end sync, persisted as
      "mageage"). The rows are "known, cast
      pending" (the R80 utility convention):
      the slot tables encode levels 1-6, so
      spellSlots yields 0 for 7-9 until the
      high-level (name level+) tables arrive
      in a future round - documented; the
      p.14 pins ride magicalAgingYears
      regardless. Two documented engine
      limits remain, named for the record:
      the speed potion's 1 year (found
      potions collapse into the healing
      stack - no identity survives pickup)
      and the hire's stolen years (no hire
      brackets exist). Pinned by the R129
      battery audit; census 47.""",
      "gap report: p.14 box flips",
      marker="CLOSED R129: the six")


# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R129 splice: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
