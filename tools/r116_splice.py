#!/usr/bin/env python3
# R116 splice: missile range modifiers (DMG p.75 -
# "Missiles: -5 at long range, -2 at medium range").
# The engagement already carries distance (R43's
# m_distance, 10' bands closing one per round) and the
# registry already stores each missile weapon's short
# range - this round attaches the book's band mods to
# the geometry: rules::missileRangeMod/missileInRange
# (medium = 2x short, long = 3x short - documented
# derivation), resolveMissile applies the mod to fired
# missile weapons (out of long range = no shot, nothing
# spent; hurled weapons exempt - no thrown ranges in
# the registry; the monsters' volley is the 50' short
# convention, mod 0), battery audit pins the helpers,
# the registry values, and the engagement geometry, and
# the gap report box flips. Idempotent (marker checks
# per patch): run twice - the second run must print
# every patch already applied. ASCII-only. Refuses
# non-unique anchors, all-or-nothing.
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

RH_OLD = """bool weaponSufficient(int requiredPlus, int weaponBonus);

// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77). Rows are the"""

RH_NEW = """bool weaponSufficient(int requiredPlus, int weaponBonus);

// ----------------------------------------------------------------------------
// R116: missile range modifiers (DMG p.75 - "Missiles:
// -5 at long range, -2 at medium range"). The registry
// stores each missile weapon's SHORT range (items, PHB
// p.38); medium is twice short and long three times -
// the weapon tables' own shape for bows (documented
// derivation; the M/L columns are not in the registry).
// Beyond long range no shot is possible.
// ----------------------------------------------------------------------------

// true while the distance is within the weapon's long
// range (3x short) - a shot at all
bool missileInRange(int distanceFeet, int shortRangeFeet);

// the book's to-hit modifier at that distance:
// 0 at short, -2 at medium, -5 at long
int missileRangeMod(int distanceFeet, int shortRangeFeet);

// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77). Rows are the"""

RC_OLD = """bool weaponSufficient(int requiredPlus, int weaponBonus) {
    return weaponBonus >= requiredPlus;
}

// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77)"""

RC_NEW = """bool weaponSufficient(int requiredPlus, int weaponBonus) {
    return weaponBonus >= requiredPlus;
}

// ----------------------------------------------------------------------------
// R116: missile range bands (DMG p.75)
// ----------------------------------------------------------------------------

bool missileInRange(int distanceFeet, int shortRangeFeet) {
    return distanceFeet <= shortRangeFeet * 3;
}

int missileRangeMod(int distanceFeet, int shortRangeFeet) {
    if (distanceFeet <= shortRangeFeet) return 0;        // short
    if (distanceFeet <= shortRangeFeet * 2) return -2;  // medium
    return -5;                                           // long
}

// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77)"""

AC1_OLD = """    if (!attacker.canAct() || !defender.alive()) return;

    // R36: a hurled melee weapon - the weapon itself is the"""

AC1_NEW = """    if (!attacker.canAct() || !defender.alive()) return;

    // R116: the range band (DMG p.75 - missiles are -2
    // at medium range, -5 at long). Fired missile
    // weapons only: a hurled melee weapon's thrown
    // range is not in the registry (documented - it
    // fires without the band mod), and the monsters'
    // volley convention is 50' short range (R37),
    // where the mod is 0. Beyond long range the shot
    // is impossible - nothing is spent.
    int rangeAdj = 0;
    if (attacker.isCharacter && !attacker.throwing &&
        attacker.hasRangedWeapon()) {
        int shortFeet = items::weapon(attacker.rangedWeapon.id)
                            .rangeTens * 10;
        int distFeet = m_distance * 10;
        if (!rules::missileInRange(distFeet, shortFeet)) {
            logLine(attacker.name + "'s target is beyond " +
                    "long range - no shot");
            return;   // nothing spent: the shot is impossible
        }
        rangeAdj = rules::missileRangeMod(distFeet, shortFeet);
    }

    // R36: a hurled melee weapon - the weapon itself is the"""

AC2_OLD = """        adj += attacker.ammoPlus;   // R80: the arrow's enchant
"""

AC2_NEW = """        adj += attacker.ammoPlus;   // R80: the arrow's enchant
        adj += rangeAdj;   // R116: -2 medium / -5 long (DMG p.75)
"""
RT_OLD = """        printf("R115 magic aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R115 magic aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R116: missile range audit ----
    {
        int bad = 0;
        // the book's note (DMG p.75): missiles -2 at
        // medium range, -5 at long. Medium is twice the
        // registry's short range, long three times
        // (documented derivation); beyond long, no
        // shot is possible
        // helper sweep at short = 40' (the sling): the
        // short band is 0..40 (mod 0, in range)
        if (!rules::missileInRange(0, 40)) ++bad;
        if (!rules::missileInRange(40, 40)) ++bad;
        if (rules::missileRangeMod(0, 40) != 0) ++bad;
        if (rules::missileRangeMod(40, 40) != 0) ++bad;
        if (!rules::missileInRange(120, 40)) ++bad;
        if (rules::missileInRange(121, 40)) ++bad;
        if (rules::missileRangeMod(41, 40) != -2) ++bad;
        if (rules::missileRangeMod(80, 40) != -2) ++bad;
        if (rules::missileRangeMod(81, 40) != -5) ++bad;
        if (rules::missileRangeMod(120, 40) != -5) ++bad;
        if (rules::missileRangeMod(39, 40) != 0) ++bad;
        // the registry's missile weapons, pinned: sling
        // 40, short bow 50, long bow 70, crossbow 60
        if (items::weapon(items::WPN_SLING).rangeTens != 4)
            ++bad;
        if (items::weapon(items::WPN_SHORT_BOW).rangeTens != 5)
            ++bad;
        if (items::weapon(items::WPN_LONG_BOW).rangeTens != 7)
            ++bad;
        if (items::weapon(items::WPN_CROSSBOW_LIGHT).rangeTens
                != 6) ++bad;
        // the engagement's geometry (R43): 50' at the
        // opening band - the sling's first-round volley
        // is at medium (-2), the bows' at short (0)
        if (rules::missileRangeMod(50, 40) != -2) ++bad;
        if (rules::missileRangeMod(50, 50) != 0) ++bad;
        if (rules::missileRangeMod(50, 60) != 0) ++bad;
        if (rules::missileRangeMod(50, 70) != 0) ++bad;
        printf("R116 missile range audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R115 verified the magic-weapon-to-hit gate
(p.76 - already the book's) and wired the
first magical aging cause (haste, p.14)."""

GH_NEW = """R115 verified the magic-weapon-to-hit gate
(p.76 - already the book's) and wired the
first magical aging cause (haste, p.14).
R116 CLOSED the missile range modifiers
(p.75) - -2 medium, -5 long, on the
engagement distance."""

GB_OLD = """- [ ] **Missile range modifiers (p.75)** - -5
      long / -2 medium; verify or implement in
      the combat round."""

GB_NEW = """- [x] **Missile range modifiers (p.75)** -
      CLOSED R116: rules::missileRangeMod (-5
      long, -2 medium, the book's own note)
      rides the engagement distance in
      resolveMissile - fired missile weapons
      only. Medium is 2x and long 3x the
      registry's short range (documented
      derivation - the M/L columns are not in
      the registry); hurled weapons are
      exempt (no thrown ranges in the
      registry - documented); the monsters'
      volley is the 50' short convention
      (R37, mod 0). Beyond long range no
      shot is possible (nothing spent).
      Under R43's 50' engagement geometry the
      long band is unreachable in play (it
      activates if the geometry ever opens);
      the sling's opening volley is medium,
      -2. Pinned by the R116 battery audit."""

# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("rules/combat.h", "bool missileInRange(int distanceFeet,",
     RH_OLD, RH_NEW, "combat.h missile range decls"),
    ("rules/combat.cpp", "bool missileInRange(int distanceFeet, int shortRangeFeet) {",
     RC_OLD, RC_NEW, "combat.cpp missile range defs"),
    ("ai/actor.cpp", "int rangeAdj = 0;",
     AC1_OLD, AC1_NEW, "actor.cpp resolveMissile band"),
    ("ai/actor.cpp", "adj += rangeAdj;",
     AC2_OLD, AC2_NEW, "actor.cpp adj rides the band"),
    ("regtest.cpp", "R116 missile range audit",
     RT_OLD, RT_NEW, "regtest R116 audit"),
    ("tools/dmg_gap_report.md", "R116 CLOSED the missile range",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "CLOSED R116: rules::missileRangeMod",
     GB_OLD, GB_NEW, "gap report missile range box"),
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
        print("R116 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R116 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R116 splice: nothing to do (already applied)")
    else:
        print("R116 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
