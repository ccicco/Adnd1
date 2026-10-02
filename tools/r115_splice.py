#!/usr/bin/env python3
# R115 splice: three items in one round.
# (a) Magic-weapon-to-hit gate (DMG p.76): VERIFIED as
#     already implemented (R5's rules::weaponSufficient +
#     monsters' requiredPlus + both attack paths); the gap
#     report's box flips to [x] and the battery pins the
#     gate's convention.
# (b) Magical aging causes (DMG p.14): the full table
#     documented; haste (1 year on the recipient) wired
#     end-to-end - spells::magicalAgingYears, the Actor
#     carries the stolen years out of the fight, the
#     endCombat sync lands them on the Character via
#     applyMagicalAging (per-crossing brackets, R114
#     machinery), and they persist (save/load "mageage").
# (c) Open-gap review: gate box flipped, new open item
#     for the unwired causes, header updated.
# Idempotent (marker checks per patch): run twice - the
# second run must print every patch already applied.
# ASCII-only. Refuses non-unique anchors, all-or-nothing.
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
SPH_OLD = """int chanceToLearnPct(uint8_t int_);
bool rollChanceToLearn(Dice& dice, uint8_t int_);
"""

SPH_NEW = """int chanceToLearnPct(uint8_t int_);
bool rollChanceToLearn(Dice& dice, uint8_t int_);

// ----------------------------------------------------------------------------
// R115: the years a spell steals (DMG p.14 magical aging
// causes): a haste spell costs its recipient 1 year. The
// caster-aged causes (limited wish 1, restoration 2,
// resurrection 3, wish 3, alter reality 3, gate 5) return
// their years when those spells enter the registry; the
// speed potion's 1 year is the item layer's, and found
// potions collapse into the healing stack today
// (documented - open item in the gap report).
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id);
"""

SPC_OLD = """bool rollChanceToLearn(Dice& dice, uint8_t int_) {
    int pct = chanceToLearnPct(int_);
    if (pct <= 0) return false;
    return (int)dice.d100() <= pct;
}
"""

SPC_NEW = """bool rollChanceToLearn(Dice& dice, uint8_t int_) {
    int pct = chanceToLearnPct(int_);
    if (pct <= 0) return false;
    return (int)dice.d100() <= pct;
}

// ----------------------------------------------------------------------------
// R115: the years magic steals (DMG p.14). Only haste is in
// the registry today (its recipient pays 1 year); the rest
// of the book's table rides the comment in spells.h until
// those spells arrive.
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id) {
    if (id == MU_HASTE) return 1;   // p.14: under a haste spell
    return 0;
}
"""

CH_OLD = """    // R97: the gray beard - age at leaving the training
    // hall; grows on the R95 career clock (ageYears).
    // 0 = a v1 save member whose youth is unknown.
    int  startAge = 0;

    items::WeaponInstance weapon;
"""

CH_NEW = """    // R97: the gray beard - age at leaving the training
    // hall; grows on the R95 career clock (ageYears).
    // 0 = a v1 save member whose youth is unknown.
    int  startAge = 0;
    // R115: the years magic stole (DMG p.14 - a haste
    // spell costs its recipient 1). They ride the age
    // clock inside ageYears; bracket crossings apply at
    // the moment of aging (applyMagicalAging), the same
    // per-crossing convention as the birthday path.
    int  magicAgeYears = 0;

    items::WeaponInstance weapon;
"""

AY_OLD = """// age today: the starting age plus whole years on the
// career clock (365 days to the year)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365;
}
"""

AY_NEW = """// age today: the starting age plus whole years on the
// career clock (365 days to the year), plus the years
// magic stole (R115 - they ride the same brackets)
inline int ageYears(const Character& c, int careerDays) {
    return c.startAge + careerDays / 365 + c.magicAgeYears;
}
"""

AMA_OLD = """        c.abilities.set(as[i], (uint8_t)v);
    }
}

// R92: the road home - 12 turns per dungeon level (2 hours
"""

AMA_NEW = """        c.abilities.set(as[i], (uint8_t)v);
    }
}

// R115: magical aging (DMG p.14) - unnatural years (a
// haste spell today; wish, gate and their kin when those
// spells arrive) advance the recipient at once, and each
// bracket entered on the way applies its bend
// progressively - the book's cumulative adjustments, the
// same per-crossing convention as the birthday path.
// (The hire's stolen years land nowhere: hire aging has
// no ability brackets - documented.)
inline void applyMagicalAging(Character& c, int careerDays,
                              int years) {
    if (years <= 0) return;
    int oldB = ageBracket(ageYears(c, careerDays));
    c.magicAgeYears += years;
    int newB = ageBracket(ageYears(c, careerDays));
    for (int b = oldB + 1; b <= newB; ++b)
        applyAgeBracket(c, b);
}

// R92: the road home - 12 turns per dungeon level (2 hours
"""

AH_OLD = """    int  requiredPlusToHit = 0;    // gating: needs +N weapon (R5)
"""

AH_NEW = """    int  requiredPlusToHit = 0;    // gating: needs +N weapon (R5)
    // R115: the years a spell stole from this character
    // in the fight (DMG p.14 - haste costs its recipient
    // 1). Rides the actor; the sync at fight's end lands
    // them on the Character via applyMagicalAging.
    // Monsters never age (the accumulate check is
    // characters-only).
    int  magicAgingYears = 0;
"""

AC_OLD = """        if (tr.status.kind != spelleffects::STATUS_NONE &&
            t.alive())
            t.addStatus(tr.status);
"""

AC_NEW = """        if (tr.status.kind != spelleffects::STATUS_NONE &&
            t.alive())
            t.addStatus(tr.status);

        // R115: the years the spell steals (DMG p.14)
        // ride the actor and land on the Character at
        // the sync. Characters only - monsters track no
        // age. (The book's caster-aged causes - wish,
        // gate, etc. - will land here too when those
        // spells enter the registry.)
        if (t.isCharacter && t.team == 0 && t.alive()) {
            int yrs = spells::magicalAgingYears(id);
            if (yrs > 0) t.magicAgingYears += yrs;
        }
"""

SC_OLD = """                    quiverConsumeShots(
                        c.quiver, c.missileAmmo - a.missileAmmo);
                    c.missileAmmo = a.missileAmmo;
                    break;
"""

SC_NEW = """                    quiverConsumeShots(
                        c.quiver, c.missileAmmo - a.missileAmmo);
                    c.missileAmmo = a.missileAmmo;
                    // R115: the stolen years land on the
                    // roster (DMG p.14 - a member hasted in
                    // the fight aged in it)
                    if (a.magicAgingYears > 0) {
                        applyMagicalAging(c, party.careerDays,
                                          a.magicAgingYears);
                        log.add(c.name + " feels the stolen " +
                                "years - magic's price.");
                    }
                    break;
"""

SV_OLD = """            if (c.startAge > 0)
                fprintf(f, "age %d\\n", c.startAge);
"""

SV_NEW = """            if (c.startAge > 0)
                fprintf(f, "age %d\\n", c.startAge);
            // R115: the years magic stole (optional line -
            // v1 saves load with none stolen)
            if (c.magicAgeYears > 0)
                fprintf(f, "mageage %d\\n", c.magicAgeYears);
"""

LD_OLD = """                c.startAge = ag;
            } else if (strcmp(tag, "ringplus") == 0) {
"""

LD_NEW = """                c.startAge = ag;
            } else if (strcmp(tag, "mageage") == 0) {
                int mg = 0;
                if (fscanf(f, "%d", &mg) != 1 ||
                    mg < 0 || mg > 200) {
                    fclose(f);
                    log.add("adnd1.sav is corrupt (mageage).");
                    return false;
                }
                c.magicAgeYears = mg;
            } else if (strcmp(tag, "ringplus") == 0) {
"""
RT_OLD = """        printf("R114 aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----
"""

RT_NEW = """        printf("R114 aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R115: magic weapon gate audit ----
    {
        int bad = 0;
        // the book's gate (p.76): a defender struck only
        // by +N weapons is hit by +N or better - pinned
        // so no refactor can flip the convention
        if (!rules::weaponSufficient(0, 0)) ++bad;
        if (rules::weaponSufficient(1, 0)) ++bad;
        if (!rules::weaponSufficient(1, 1)) ++bad;
        if (rules::weaponSufficient(2, 1)) ++bad;
        if (!rules::weaponSufficient(2, 2)) ++bad;
        if (rules::weaponSufficient(3, 2)) ++bad;
        if (!rules::weaponSufficient(3, 3)) ++bad;
        if (rules::weaponSufficient(4, 3)) ++bad;
        if (!rules::weaponSufficient(4, 4)) ++bad;
        printf("R115 magic weapon gate audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R115: magic aging audit ----
    {
        int bad = 0;
        // the book's table (DMG p.14): haste costs its
        // recipient 1 year; the caster-aged causes await
        // their spells
        if (spells::magicalAgingYears(spells::MU_HASTE) != 1)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_FIREBALL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::CL_HEAL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_TELEPORT) != 0)
            ++bad;
        // the stolen years ride the age clock: 20 -> 21
        // crosses into mature (+1 STR, +1 WIS)
        {
            Character c;
            c.startAge = 20;
            c.abilities.set(rules::ABILITY_STR, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_CON, 10);
            if (ageYears(c, 0) != 20) ++bad;
            applyMagicalAging(c, 0, 1);
            if (c.magicAgeYears != 1) ++bad;
            if (ageYears(c, 0) != 21) ++bad;
            if (ageYears(c, 3650) != 31) ++bad;  // +10 career
            if (c.abilities.get(rules::ABILITY_STR) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 10)
                ++bad;    // no CON bend at mature
        }
        // zero years is a no-op
        {
            Character c;
            c.startAge = 30;
            applyMagicalAging(c, 0, 0);
            if (c.magicAgeYears != 0) ++bad;
            if (ageYears(c, 0) != 30) ++bad;
        }
        // one crossing: 39 -> 44 enters middle aged
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            applyMagicalAging(c, 364, 5);   // 39 -> 44
            if (c.magicAgeYears != 5) ++bad;
            if (ageYears(c, 364) != 44) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
        }
        // two crossings at once: 39 -> 61 enters old,
        // middle aged's bend then old's, progressively
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX, 15);
            applyMagicalAging(c, 0, 22);   // 39 -> 61
            // STR 15-1-2=12, CON 15-1-1=13, INT 10+1=11,
            // WIS 10+1+1=12, DEX 15-2=13
            if (ageYears(c, 0) != 61) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 13)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 13)
                ++bad;
        }
        printf("R115 magic aging audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----
"""

GH_OLD = """R114 CLOSED divergence 6 of 6 (aging) - all
six of the original divergences are closed."""

GH_NEW = """R114 CLOSED divergence 6 of 6 (aging) - all
six of the original divergences are closed.
R115 verified the magic-weapon-to-hit gate
(p.76 - already the book's) and wired the
first magical aging cause (haste, p.14)."""

GB_OLD = """- [ ] **Magic-weapon-to-hit gate (p.76)** - the
      book's table: creatures struck only by
      magic weapons need +1 at HD 4+1, +2 at
      6+2, +3 at 8+3, +4 at 10+4 or better. No
      such gate found in the repo."""

GB_NEW = """- [x] **Magic-weapon-to-hit gate (p.76)** -
      VERIFIED R115: already implemented -
      monsters' requiredPlus comes from the
      Lua specials text (MonsterRegistry),
      and rules::weaponSufficient gates both
      the melee and missile paths
      (ai/actor.cpp; the quiver's ammo
      enchant counts toward it, R80).
      Attacking monsters are always
      sufficient: the book's attacker HD
      column (+1 at HD 4+1...) governs
      monsters hitting gated creatures,
      which this repo's encounters (monsters
      vs characters) never do - documented.
      Pinned by the R115 battery audit.
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
      land nowhere (no hire brackets)."""

AB_OLD = """      WIS clipped at 18 (documented). Magical
      aging causes (haste, wish, etc., p.14)
      remain an open item below."""

AB_NEW = """      WIS clipped at 18 (documented). Magical
      aging causes are an open item below
      (haste wired R115)."""

# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("spells/spells.h", "int magicalAgingYears(SpellId id);",
     SPH_OLD, SPH_NEW, "spells.h magicalAgingYears decl"),
    ("spells/spells.cpp", "int magicalAgingYears(SpellId id) {",
     SPC_OLD, SPC_NEW, "spells.cpp magicalAgingYears def"),
    ("game/party.h", "int  magicAgeYears = 0;",
     CH_OLD, CH_NEW, "party.h magicAgeYears field"),
    ("game/party.h", "+ c.magicAgeYears;",
     AY_OLD, AY_NEW, "party.h ageYears rides stolen years"),
    ("game/party.h", "inline void applyMagicalAging",
     AMA_OLD, AMA_NEW, "party.h applyMagicalAging"),
    ("ai/actor.h", "int  magicAgingYears = 0;",
     AH_OLD, AH_NEW, "actor.h magicAgingYears field"),
    ("ai/actor.cpp", "spells::magicalAgingYears(id)",
     AC_OLD, AC_NEW, "actor.cpp accumulate stolen years"),
    ("game/state_combat.cpp", "applyMagicalAging(c, party.careerDays,",
     SC_OLD, SC_NEW, "state_combat.cpp sync lands years"),
    ("game/state_core.cpp", 'fprintf(f, "mageage',
     SV_OLD, SV_NEW, "state_core.cpp save mageage"),
    ("game/state_core.cpp", 'strcmp(tag, "mageage")',
     LD_OLD, LD_NEW, "state_core.cpp load mageage"),
    ("regtest.cpp", "R115 magic weapon gate audit",
     RT_OLD, RT_NEW, "regtest R115 audits"),
    ("tools/dmg_gap_report.md", "R115 verified the magic-weapon",
     GH_OLD, GH_NEW, "gap report header note"),
    ("tools/dmg_gap_report.md", "VERIFIED R115: already implemented",
     GB_OLD, GB_NEW, "gap report gate box + remainder item"),
    ("tools/dmg_gap_report.md", "haste wired R115",
     AB_OLD, AB_NEW, "gap report aging box note"),
]


def main():
    # two passes: compute all patches, write only if every
    # patch applied or was already applied (all-or-nothing)
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
        for rel in texts:
            pass   # nothing written - pristine
        print("R115 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R115 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R115 splice: nothing to do (already applied)")
    else:
        print("R115 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
