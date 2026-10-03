#!/usr/bin/python3
# tools/r133_splice.py - R133 Appendix H third-effects
# slice: five more attributes wired (the mechanical set
# grows 11 -> 16; 49 stay dressing).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical grows to sixteen -
#    attacks, fruit, greed, teleports, collapsing (all
#    conventions - the print gives no figures; the teleport
#    follows the print's intra-level AREA example)
#  - game/state_dungeon.cpp: applyTrick gains the five
#    branches (the 1d8 strike, the potion-shape heal, the
#    10% purse scramble, the room-center relocation, the
#    save-or-2d6 ceiling)
#  - regtest.cpp: the R128 and R132 audits' mechanical
#    count pins update (11 -> 16) and the new R133 audit
#    pins the set (census 51)
#  - tools/dmg_gap_report.md: the R128 and R132 boxes'
#    dressing counts drop to 49; the R133 box closes
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

patch("dm/appendixgh.h",
"""// rebuild convention). The remaining 54 stay dressing;
// their effects ride future rounds.
inline bool trickIsMechanical(int a) {
    return a == TA_REL_COINS || a == TA_REL_GEMS ||
           a == TA_REL_MAGIC_ITEM || a == TA_SHOOTS ||
           a == TA_POISON ||
           a == TA_AGES || a == TA_FLESH_TO_STONE ||
           a == TA_SHOCK_METAL || a == TA_SHOCK_MAGIC ||
           a == TA_REL_COUNTERFEIT || a == TA_TAKES;
}
""",
"""// rebuild convention). R133 wires the third-effects
// slice: attacks (an animated strike, 1d8 - convention),
// fruit (heals a random living member 2d4+2, the potion
// shape - convention), greed (a scramble costs 10% of
// the purse - convention), teleports (an intra-level
// relocation to a random room center, the print's AREA
// example), collapsing (the ceiling comes down: every
// living member saves vs death/poison or 2d6 -
// convention). The remaining 49 stay dressing; their
// effects ride future rounds.
inline bool trickIsMechanical(int a) {
    return a == TA_REL_COINS || a == TA_REL_GEMS ||
           a == TA_REL_MAGIC_ITEM || a == TA_SHOOTS ||
           a == TA_POISON ||
           a == TA_AGES || a == TA_FLESH_TO_STONE ||
           a == TA_SHOCK_METAL || a == TA_SHOCK_MAGIC ||
           a == TA_REL_COUNTERFEIT || a == TA_TAKES ||
           a == TA_ATTACKS || a == TA_FRUIT ||
           a == TA_GREED || a == TA_TELEPORTS ||
           a == TA_COLLAPSING;
}
""",
      "appendixgh.h: mechanical set 16",
      marker="R133 wires the")

patch("game/state_dungeon.cpp",
"""        // releases counterfeit (worthless), takes/steals
        // (10-60 gp).
""",
"""        // releases counterfeit (worthless), takes/steals
        // (10-60 gp). R133: the third-effects slice -
        // attacks (animated strike, 1d8), fruit (heals
        // 2d4+2, the potion shape), greed (10% of the
        // purse), teleports (intra-level, a random room
        // center), collapsing (save or 2d6, everyone).
""",
      "state_dungeon.cpp: applyTrick doc",
      marker="R133: the third-effects slice")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
"""        } else if (a == dm::appendixh::TA_ATTACKS) {
            // R133: the animated feature strikes - 1d8,
            // no save (the print gives no figure; the
            // unarmed-strike convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 8, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s strikes %s for %d - %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s strikes %s for %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_FRUIT) {
            // R133: wholesome fruit - a random living
            // member eats and heals 2d4+2, the potion
            // shape, capped at max hp (the print gives no
            // figure; convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int heal = (int)dice.roll(2, 4, 2);
            int before = c.hp;
            c.hp += heal;
            if (c.hp > c.maxHp) c.hp = c.maxHp;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s offers fruit - %s eats and "
                     "heals %d (now %d/%d).",
                     name.c_str(), c.name.c_str(),
                     c.hp - before, c.hp, c.maxHp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_GREED) {
            // R133: the greed aura - a scramble costs 10%
            // of the purse (the print gives no figure;
            // convention)
            int lost = party.gold / 10;
            if (lost > 0) {
                party.gold -= lost;
                char buf[160];
                snprintf(buf, sizeof buf,
                         "The %s glitters - the company "
                         "scrambles and drops %d gp!",
                         name.c_str(), lost);
                log.add(buf);
            } else {
                log.add("The " + name + " glitters - but "
                        "the purse is empty.");
            }
        } else if (a == dm::appendixh::TA_TELEPORTS) {
            // R133: the print's intra-level AREA example -
            // the company is relocated to a random room
            // center on this level
            if (dungeon.rooms.empty()) return;
            int ri = (int)rng.below(
                (uint32_t)dungeon.rooms.size());
            const dm::GeneratedRoom& r = dungeon.rooms[ri];
            party.x = r.x + r.w / 2;
            party.y = r.y + r.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s flares - the company blinks "
                     "across the level!",
                     name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_COLLAPSING) {
            // R133: the ceiling comes down - every living
            // member saves vs death/poison or takes 2d6
            // (the print gives no figure; the trap shape)
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s groans - the ceiling comes "
                     "down!", name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0)) {
                    char b2[160];
                    snprintf(b2, sizeof b2,
                             "%s dives clear.", c.name.c_str());
                    log.add(b2);
                    continue;
                }
                int dmg = (int)dice.roll(2, 6, 0);
                c.hp -= dmg;
                char b2[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(b2, sizeof b2,
                             "Rubble buries %s for %d - "
                             "%s falls!",
                             c.name.c_str(), dmg,
                             c.name.c_str());
                } else {
                    snprintf(b2, sizeof b2,
                             "Rubble bruises %s for %d.",
                             c.name.c_str(), dmg);
                }
                log.add(b2);
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
      "state_dungeon.cpp: five new branches",
      marker="TA_ATTACKS) {")

# R133-CHUNK-1-END (code patches above)
patch("regtest.cpp",
"""        // the two slices: exactly eleven mechanical (R132
        // grew the set 5 -> 11; counterfeit flipped)
""",
"""        // the slices: exactly sixteen mechanical (R132
        // grew the set 5 -> 11, R133 11 -> 16)
""",
      "regtest.cpp: R128 audit comment",
      marker="the slices: exactly sixteen")

patch("regtest.cpp",
"""            if (mech != 11) ++bad;
""",
"""            if (mech != 16) ++bad;
""",
      "regtest.cpp: both mech counts 16",
      expect=2,
      marker="mech != 16")

patch("regtest.cpp",
"""    // ---- R132: second-effects slice audit ----
""",
"""    // ---- R133: third-effects slice audit ----
    // The Appendix H mechanical set grows to sixteen: the
    // R132 eleven plus attacks, fruit, greed, teleports,
    // and collapsing (all conventions - the print gives
    // no figures for these five; the teleport follows
    // the print's intra-level AREA example).
    {
        int bad = 0;
        // exactly sixteen mechanical of 65
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 16) ++bad;
        }
        // the R133 five are mechanical
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_ATTACKS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_FRUIT)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GREED)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TELEPORTS)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_COLLAPSING)) ++bad;
        // the deep waters stay dressing (engine limits)
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_WISH)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_GRAVITY_GREATER)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POLYMORPH)) ++bad;
        printf("R133 third-effects slice audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R132: second-effects slice audit ----
""",
      "regtest.cpp: R133 audit",
      marker="R133 third-effects slice audit")

patch("regtest.cpp",
"""        // exactly eleven mechanical of 65
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 16) ++bad;
        }
""",
"""        // exactly sixteen mechanical of 65 (R133 grew it)
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 16) ++bad;
        }
""",
      "regtest.cpp: R132 count 16",
      marker="exactly sixteen mechanical of 65 (R133 grew it)")

patch("tools/dmg_gap_report.md",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box). The other 54 attributes stay
      dressing - documented; their effects ride future
      rounds.
""",
"""      2d6). R132's second-effects slice wires six more
      (the R132 box), R133's five more (the R133 box).
      The other 49 attributes stay dressing - documented;
      their effects ride future rounds.
""",
      "gap report: R128 box 49",
      marker="R133's five more (the R133 box)")

patch("tools/dmg_gap_report.md",
"""      The remaining 54 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
"""      The R133 slice wires five more (the R133 box).
      The remaining 49 attributes stay dressing;
      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
""",
      "gap report: R132 box 49",
      marker="The R133 slice wires five more")

patch("tools/dmg_gap_report.md",
"""      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.

## Out of scope by design
""",
"""      their effects ride future rounds. Pinned by
      the R132 battery audit; census 50.
- [x] **Appendix H third-effects slice (the R128
      dressing debt, second five)** - CLOSED R133: the
      mechanical set grows 11 -> 16. Attacks:
      the animated feature strikes a random living
      member for 1d8, no save. Fruit: a random
      living member eats and heals 2d4+2 (the
      potion shape, capped at max hp). Greed: a
      scramble costs 10% of the purse. Teleports:
      the company blinks to a random room center
      on this level (the print's intra-level AREA
      example). Collapsing: the ceiling comes down
      - every living member saves vs death/poison
      or takes 2d6. All five are rebuild
      conventions (the print gives no figures);
      documented. The remaining 49 attributes stay
      dressing; their effects ride future rounds.
      Pinned by the R133 battery audit; census 51.

## Out of scope by design
""",
      "gap report: R133 box",
      marker="CLOSED R133: the")

# ---- R133 fails/tail ----
if fails:
    print("R133 splice: FAIL - " + str(len(fails)) + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R133 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R133 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
