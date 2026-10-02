#!/usr/bin/env python3
# R118 splice: listening at doors (DMG p.60, OCR
# page-061.md). The book's table is RACIAL d20
# chances: dwarf 2, elf 3, gnome 4, half-elf 2,
# halfling 3, half-orc 3, human 2 (in 20), plus a
# keen-eared bonus of 1 or 2 in 20. R11's
# listenChanceIn6 was an admitted d6-band
# approximation (stone-door/1-in-10 shape) - a
# TRUE divergence, retired here. No callers
# exist (dead code; nothing in the tree includes
# abilities.h), so the reshape is free.
# The repo has no race field, so callers use the
# human band (R114's convention, documented); the
# full seven-entry table is pinned anyway so a
# future race field inherits it verified. Keen-
# eared is per-character state the repo does not
# track - the caller passes the bonus. Thieves
# substitute their hear-noise skill (PHB),
# converted pct/5 to in-20 bands (documented
# derivation; the table's own verification-debt
# NOTE rides). Silent creatures, sleeping/
# resting/alerted creatures: the caller's gate
# (the book's own rule).
# DISCOVERY: abilities/abilities.cpp was compiled
# by NOTHING on Termux (not in the battery build,
# not in the syntax gate) - it joins the battery
# build here so the audit actually links.
# Battery audit pins all seven table entries,
# keen-bonus arithmetic, both clamps, the thief
# mapping cross-checked against thiefSkillBase,
# roll edges, and a seeded 2000-roll smoke.
# Census becomes 36. Idempotent (marker checks
# per patch): run twice - the second run must
# print every patch already applied. ASCII-only.
# Refuses non-unique anchors, all-or-nothing.
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


# ---- patch bodies ----------------------------------------------------------

AH_OLD = """// Listening at doors (PHB p.26, DMG p.19).
bool listenAtDoor(Dice& dice, int chanceIn6);
int listenChanceIn6(bool stoneDoor, bool isThief, int thiefLevel);"""

AH_NEW = """// R118: LISTENING AT DOORS (DMG p.60) - the
// book's table is RACIAL d20 chances; R11's d6
// bands are retired. The repo has no race field,
// so callers use LISTEN_HUMAN (R114's human-only
// convention - documented); the full table stays
// pinned so a future race field inherits it
// verified. Keen-eared characters gain 1 or 2 in
// 20 (the DM determines keenness on the first
// listen and the player notes it); the repo keeps
// no per-character state, so the caller passes the
// bonus. Thieves substitute their hear-noise skill
// (PHB), converted to in-20 bands (pct/5 -
// documented derivation; the PHB table's own
// verification-debt NOTE rides). Silent creatures
// (undead, bugbears), sleeping, resting, or
// alerted creatures are never heard - the caller
// must not roll (the book's own rule).
enum ListenRace : int {
    LISTEN_DWARF    = 0,   // 2 in 20 (10%)
    LISTEN_ELF      = 1,   // 3 in 20 (15%)
    LISTEN_GNOME    = 2,   // 4 in 20 (20%)
    LISTEN_HALF_ELF = 3,   // 2 in 20 (10%)
    LISTEN_HALFLING = 4,   // 3 in 20 (15%)
    LISTEN_HALF_ORC = 5,   // 3 in 20 (15%)
    LISTEN_HUMAN    = 6,   // 2 in 20 (10%)
    LISTEN_RACE_COUNT
};

int raceListenIn20(ListenRace race);            // the book's table
int listenChanceIn20(ListenRace race, int keenIn20);
int thiefListenIn20(int thiefLevel, int keenIn20);
bool listenAtDoor(Dice& dice, int chanceIn20);  // d20 <= chance"""

AC_OLD = """bool listenAtDoor(Dice& dice, int chanceIn6) {
    if (chanceIn6 <= 0) return false;
    if (chanceIn6 >= 6) return true;
    return (int)dice.d6() <= chanceIn6;
}

int listenChanceIn6(bool stoneDoor, bool isThief, int thiefLevel) {
    if (isThief) {
        // thieves substitute their hear-noise percent - handled by
        // the caller with attemptThiefSkill; here map to a d6 band
        (void)thiefLevel;
        return 3;
    }
    if (stoneDoor) return 1;   // 1-in-10 approximated as worst band
    return 2;                  // 1-2 on d6
}"""

AC_NEW = """// R118: listening at doors (DMG p.60) - the
// book's racial d20 table (R11's d6-band
// approximation retired; no callers existed,
// so the reshape is free)
int raceListenIn20(ListenRace race) {
    // the book's table: chance of hearing noise,
    // in 20 (dwarf, elf, gnome, half-elf,
    // halfling, half-orc, human)
    static const int kChance[LISTEN_RACE_COUNT] = {
        2, 3, 4, 2, 3, 3, 2
    };
    if (race < 0 || race >= LISTEN_RACE_COUNT)
        return kChance[LISTEN_HUMAN];   // unknown -> human band
    return kChance[race];
}

int listenChanceIn20(ListenRace race, int keenIn20) {
    int chance = raceListenIn20(race) + keenIn20;
    if (chance < 0)  chance = 0;
    if (chance > 20) chance = 20;
    return chance;
}

int thiefListenIn20(int thiefLevel, int keenIn20) {
    // thieves ride their hear-noise skill (PHB):
    // percent / 5 = in-20 bands (documented
    // derivation; the PHB table's verification-
    // debt NOTE rides)
    int chance = thiefSkillBase(SKILL_HEAR_NOISE, thiefLevel) / 5
               + keenIn20;
    if (chance < 0)  chance = 0;
    if (chance > 20) chance = 20;
    return chance;
}

bool listenAtDoor(Dice& dice, int chanceIn20) {
    if (chanceIn20 <= 0) return false;
    if (chanceIn20 >= 20) return true;
    return (int)dice.d20() <= chanceIn20;
}"""

PF_OLD = """if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \\
  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \\
  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \\
  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\
  items/items.cpp regtest.cpp \\"""

PF_NEW = """if g++ -std=c++17 -I. -I"$PREFIX/include/lua5.4" \\
  rules/dice.cpp rules/character.cpp rules/classes.cpp rules/combat.cpp \\
  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp \\
  dm/treasure.cpp monsters/MonsterRegistry.cpp spells/spells.cpp \\
  abilities/abilities.cpp items/items.cpp regtest.cpp \\"""

PC_OLD = """# R107 (the lean gate): the battery build below compiles
# rules/, dm/, items/, spells/, monsters/MonsterRegistry
# .cpp and regtest.cpp - a syntax pass over the same files"""

PC_NEW = """# R107 (the lean gate): the battery build below compiles
# rules/, dm/, abilities/ (R118 - it was compiled by
# nothing before), items/, spells/, monsters/
# MonsterRegistry.cpp and regtest.cpp - a syntax pass
# over the same files"""

RI_OLD = """#include "spells/spells.h"
#include <cstdio>"""

RI_NEW = """#include "spells/spells.h"
#include "abilities/abilities.h"
#include <cstdio>"""

RT_OLD = """        printf("R117 encounter reactions audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R117 encounter reactions audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R118: listening at doors audit ----
    {
        int bad = 0;
        // the book's table (DMG p.60): all seven
        // racial entries pinned, in 20
        if (abilities::raceListenIn20(abilities::LISTEN_DWARF)    != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_ELF)      != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_GNOME)   != 4)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ELF) != 2)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALFLING) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HALF_ORC) != 3)
            ++bad;
        if (abilities::raceListenIn20(abilities::LISTEN_HUMAN)   != 2)
            ++bad;
        // out-of-range race -> the human band
        // (documented default)
        if (abilities::raceListenIn20(abilities::LISTEN_RACE_COUNT) != 2)
            ++bad;
        // the keen-eared bonus (1 or 2 in 20,
        // the caller passes it)
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 0) != 2)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_HUMAN, 2) != 4)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 1) != 5)
            ++bad;
        // clamps at both ends
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, -9) != 0)
            ++bad;
        if (abilities::listenChanceIn20(abilities::LISTEN_GNOME, 20) != 20)
            ++bad;
        // thieves ride hear-noise (PHB) as in-20
        // bands (pct/5): L1 10% -> 2, L5 20% -> 4,
        // L12 35% -> 7, L13+ repeats the L12 row
        if (abilities::thiefListenIn20(1, 0)  != 2) ++bad;
        if (abilities::thiefListenIn20(5, 0)  != 4) ++bad;
        if (abilities::thiefListenIn20(12, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(13, 0) != 7) ++bad;
        if (abilities::thiefListenIn20(9, 2)  != 8) ++bad;
        // clamps, and the derivation cross-checked
        // against the skill table itself
        if (abilities::thiefListenIn20(1, -9)  != 0)  ++bad;
        if (abilities::thiefListenIn20(12, 20) != 20) ++bad;
        for (int lvl = 1; lvl <= 14; ++lvl) {
            int expected =
                abilities::thiefSkillBase(abilities::SKILL_HEAR_NOISE,
                                         lvl) / 5;
            if (abilities::thiefListenIn20(lvl, 0) != expected)
                ++bad;
        }
        // the roll: d20 <= chance; the edges and a
        // seeded smoke with both ends reachable
        {
            rules::Rng rng8(6180);
            rules::Dice dice8(rng8);
            for (int i = 0; i < 100; ++i) {
                if (abilities::listenAtDoor(dice8, 0))  ++bad;
                if (!abilities::listenAtDoor(dice8, 20)) ++bad;
            }
            int hits = 0, misses = 0;
            for (int i = 0; i < 2000; ++i) {
                if (abilities::listenAtDoor(dice8, 2)) ++hits;
                else ++misses;
            }
            if (hits == 0 || misses == 0) ++bad;
        }
        printf("R118 listening at doors audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R117 CLOSED encounter reactions (p.64) -
the book's percentile seven-band table
replaces R8's 2d6 stand-in.

Categories:"""

GH_NEW = """R117 CLOSED encounter reactions (p.64) -
the book's percentile seven-band table
replaces R8's 2d6 stand-in.
R118 CLOSED listening at doors (p.60) -
the book's racial d20 table replaces R11's
d6 bands; abilities.cpp joins the battery
build (it was compiled by nothing).

Categories:"""

GB_OLD = """- [ ] **Listening at doors (p.60)** - the
      chance and the elves' bonus."""

GB_NEW = """- [x] **Listening at doors (p.60)** -
      CLOSED R118: the book's table is
      racial d20 chances - dwarf 2, elf 3,
      gnome 4, half-elf 2, halfling 3,
      half-orc 3, human 2 in 20 (all seven
      pinned) - replacing R11's d6-band
      approximation. No race field, so
      callers use the human band
      (documented, R114 convention). The
      keen-eared bonus (1 or 2 in 20) is
      per-character state the repo does
      not track - the caller passes it
      (the DM notes it on the first
      listen, per the book). Thieves ride
      their hear-noise skill as pct/5
      in-20 bands (documented derivation;
      the PHB table's verification-debt
      NOTE rides). Silent creatures,
      sleeping/resting/alerted creatures:
      the caller's gate (the book's own
      rule). No callers yet - a door-
      listening hook is a future round.
      Pinned by the R118 battery audit;
      abilities.cpp now in the battery
      build (it was compiled by nothing
      on Termux before)."""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("abilities/abilities.h", "int raceListenIn20(ListenRace race);",
     AH_OLD, AH_NEW, "abilities.h book's listen table"),
    ("abilities/abilities.cpp", "int raceListenIn20(ListenRace race) {",
     AC_OLD, AC_NEW, "abilities.cpp book's listen table"),
    ("tools/preflight.sh", "abilities/abilities.cpp items/items.cpp",
     PF_OLD, PF_NEW, "preflight battery build gains abilities.cpp"),
    ("tools/preflight.sh", "R118 - it was compiled by",
     PC_OLD, PC_NEW, "preflight gate comment"),
    ("regtest.cpp", '#include "abilities/abilities.h"',
     RI_OLD, RI_NEW, "regtest includes abilities"),
    ("regtest.cpp", "R118 listening at doors audit",
     RT_OLD, RT_NEW, "regtest R118 audit"),
    ("tools/dmg_gap_report.md", "R118 CLOSED listening at doors",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "CLOSED R118: the book's table is",
     GB_OLD, GB_NEW, "gap report listening box"),
]


def main():
    # all-or-nothing: compute every patch, write only if
    # every patch applied or was already applied
    texts = {}
    applied = 0
    already = 0
    failed = []
    for rel, marker, old, new, label in PATCHES:
        if rel not in texts:
            texts[rel] = read(rel)
        t = texts[rel]
        if marker in t:
            print("already applied: " + label)
            already += 1
        else:
            t2, did = replace_exact(t, old, new, label)
            if not did:
                failed.append(label)
            else:
                texts[rel] = t2
                applied += 1
    if failed:
        print("R118 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R118 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R118 splice: nothing to do (already applied)")
    else:
        print("R118 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
