#!/usr/bin/env python3
# tools/r139_splice.py - R139 the engine-deep change-family
# slice: eleven Appendix H attributes wired at last -
# the five change-family attributes (align, attribute,
# class, minds, sex), both distorted readings, both
# resisting readings, geases, and disintegrates.
# Mechanical set 29 -> 40; dressing 25 left.
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: the eleven join trickIsMechanical;
#    the dressing comment updates (36 -> 25)
#  - game/state_dungeon.cpp: applyTrick doc + the eleven
#    branches (all conventions - the print gives names
#    only)
#  - regtest.cpp: the six mech-count pins flip 29 -> 40;
#    the R139 audit (census 57)
#  - tools/dmg_gap_report.md: the R139 box
# This file contains ZERO backslash characters - the
# audit printf's escaped newline is assembled from
# chr(92), which nothing can eat (the R133b lesson).
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
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
"""// remaining 36 stay dressing; their effects ride
// future rounds.
""",
"""// R139 wires the engine-deep change-family slice:
// change align (the convictions waver - WIS and CHA
// drop), change attribute (two abilities swap),
// change class (training unravels - xp resets to the
// level's start), change minds (INT drops), change
// sex (semblance remade - CHA drops), distorted WL
// (the bent space turns a weapon on its wielder),
// distorted HD (vitality squeezed - max hp drops),
// resisting general (the feature repels the whole
// company), resisting specific (the same repulse,
// and the trick is NOT spent), geases (a compulsion
// settles - WIS drops), disintegrates (save or
// gone). All eleven are conventions - the print
// gives names only. The remaining 25 stay dressing;
// their effects ride future rounds.
""",
      "appendixgh.h: dressing comment R139",
      marker="remaining 25 stay dressing")

patch("dm/appendixgh.h",
"""           a == TA_INVISIBLE || a == TA_GASEOUS;
}
""",
"""           a == TA_INVISIBLE || a == TA_GASEOUS ||
           a == TA_CHANGE_ALIGN ||
           a == TA_CHANGE_ATTRIBUTE ||
           a == TA_CHANGE_CLASS ||
           a == TA_CHANGE_MINDS ||
           a == TA_CHANGE_SEX ||
           a == TA_DISTORTED_WL ||
           a == TA_DISTORTED_HD ||
           a == TA_RESISTING_GENERAL ||
           a == TA_RESISTING_SPECIFIC ||
           a == TA_GEASES ||
           a == TA_DISINTEGRATES;
}
""",
      "appendixgh.h: eleven join mechanical",
      marker="a == TA_DISINTEGRATES;")

patch("game/state_dungeon.cpp",
"""        // appearing (the melt-away), invisible (the
        // unseen strike), gaseous (the gas cloud).
        if (roomIndex < 0 ||
""",
"""        // appearing (the melt-away), invisible (the
        // unseen strike), gaseous (the gas cloud).
        // R139: the engine-deep change-family slice -
        // change align (save or WIS and CHA drop),
        // change attribute (save or two abilities
        // swap), change class (save or training
        // unravels), change minds (save or INT drops),
        // change sex (save or CHA drops), distorted
        // WL (1d6, the bent weapon), distorted HD
        // (save or max hp drops), resisting general
        // (the company is repelled), resisting
        // specific (repelled, and the trick is not
        // spent), geases (save or WIS drops),
        // disintegrates (save or gone).
        if (roomIndex < 0 ||
""",
      "state_dungeon.cpp: applyTrick doc R139",
      marker="R139: the engine-deep change-family slice")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_APPEARING) {
""",
"""        } else if (a == dm::appendixh::TA_CHANGE_ALIGN) {
            // R139: alignments are not modeled - the
            // convention: save vs spells or the
            // victim's convictions waver (WIS and CHA
            // each drop 1, floored at 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " hums - " +
                        c.name + " stands firm.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_WIS) > 3)
                c.abilities.set(rules::ABILITY_WIS,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_WIS) - 1));
            if (c.abilities.get(rules::ABILITY_CHA) > 3)
                c.abilities.set(rules::ABILITY_CHA,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CHA) - 1));
            log.add("The " + name + " remakes " + c.name +
                    " - their convictions waver!");
        } else if (a ==
                   dm::appendixh::TA_CHANGE_ATTRIBUTE) {
            // R139: save vs spells or two of the victim's
            // abilities trade places (convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " flickers - " +
                        c.name + " is unchanged.");
                return;
            }
            int a1 = (int)rng.below((uint32_t)
                rules::ABILITY_COUNT);
            int a2 = (int)rng.below((uint32_t)
                (rules::ABILITY_COUNT - 1));
            if (a2 >= a1) ++a2;
            uint8_t tmp = c.abilities.get(
                (rules::Ability)a1);
            c.abilities.set((rules::Ability)a1,
                c.abilities.get((rules::Ability)a2));
            c.abilities.set((rules::Ability)a2, tmp);
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s scrambles %s - %s and %s trade!",
                     name.c_str(), c.name.c_str(),
                     rules::abilityName((rules::Ability)a1),
                     rules::abilityName((rules::Ability)a2));
            log.add(buf);
        } else if (a == dm::appendixh::TA_CHANGE_CLASS) {
            // R139: no class-change engine - convention:
            // save vs spells or the victim's training
            // unravels (xp resets to the level's start)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " gestures - " +
                        c.name + " keeps their trade.");
                return;
            }
            c.xp = rules::xpForLevel(c.classIndex,
                                     c.level);
            log.add("The " + name + " remakes " + c.name +
                    " - their training unravels!");
        } else if (a == dm::appendixh::TA_CHANGE_MINDS) {
            // R139: save vs spells or the victim's
            // thoughts scramble (INT drops 1, floored
            // at 3 - convention)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " whispers - " +
                        c.name + " keeps their wits.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_INT) > 3)
                c.abilities.set(rules::ABILITY_INT,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_INT) - 1));
            log.add("The " + name + " scrambles " +
                    c.name + "'s thoughts!");
        } else if (a == dm::appendixh::TA_CHANGE_SEX) {
            // R139: sex is not modeled - convention:
            // save vs petrification (the transformation
            // category) or the semblance is remade and
            // CHA drops 1, floored at 3
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " shimmers - " +
                        c.name + " is untouched.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_CHA) > 3)
                c.abilities.set(rules::ABILITY_CHA,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CHA) - 1));
            log.add("The " + name + " remakes " + c.name +
                    "'s semblance!");
        } else if (a == dm::appendixh::TA_DISTORTED_WL) {
            // R139: distorted weapon lengths - the bent
            // space turns the victim's own blow on them
            // (1d6, no save - the unseen-strike shape)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 6, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s bends %s's weapon awry - "
                         "%d! %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s bends %s's weapon awry - %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_DISTORTED_HD) {
            // R139: distorted hit dice - the victim's
            // vitality is squeezed (save vs death/poison
            // or max hp drops 1d6, floored at 1)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_DEATH_POISON);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " warps - " +
                        c.name + " keeps their vigor.");
                return;
            }
            int loss = (int)dice.roll(1, 6, 0);
            if (c.maxHp - loss < 1) loss = c.maxHp - 1;
            c.maxHp -= loss;
            if (c.hp > c.maxHp) c.hp = c.maxHp;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s squeezes %s - %d vitality!",
                     name.c_str(), c.name.c_str(), loss);
            log.add(buf);
        } else if (a ==
                   dm::appendixh::TA_RESISTING_GENERAL) {
            // R139: the feature resists - it repels the
            // whole company to a random edge tile (the
            // R135 sliding shape; convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s resists - the company is "
                     "repelled!", name.c_str());
            log.add(buf);
        } else if (a ==
                   dm::appendixh::TA_RESISTING_SPECIFIC) {
            // R139: resisting one specific thing - the
            // company is repelled AND the trick is not
            // spent (trickDone unwound - convention)
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            int side = (int)rng.below((uint32_t)4);
            int nx = 0, ny = 0;
            if (side == 0) {
                nx = gr.x;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 1) {
                nx = gr.x + gr.w - 1;
                ny = gr.y + (int)rng.below((uint32_t)gr.h);
            } else if (side == 2) {
                ny = gr.y;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            } else {
                ny = gr.y + gr.h - 1;
                nx = gr.x + (int)rng.below((uint32_t)gr.w);
            }
            party.x = nx;
            party.y = ny;
            room.trickDone = false;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shrugs the attempt off - the "
                     "company is repelled!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_GEASES) {
            // R139: a quest compulsion - no quest engine,
            // so the convention: save vs spells or a
            // geas settles and WIS drops 1 (floored at 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " murmurs - " +
                        c.name + " resists the geas.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_WIS) > 3)
                c.abilities.set(rules::ABILITY_WIS,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_WIS) - 1));
            log.add("A geas settles over " + c.name +
                    " - a duty unspoken rides them!");
        } else if (a == dm::appendixh::TA_DISINTEGRATES) {
            // R139: the hardest bite - save vs spells or
            // the victim is gone (the flesh-to-stone
            // shape, disintegrated instead)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " crackles - " +
                        c.name + " holds fast!");
                return;
            }
            c.hp = 0;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s unmakes %s - only dust "
                     "settles!", name.c_str(),
                     c.name.c_str());
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_APPEARING) {
""",
      "state_dungeon.cpp: the R139 eleven branches",
      marker="dm::appendixh::TA_DISINTEGRATES) {")

patch("regtest.cpp",
"""            if (mech != 29) ++bad;
""",
"""            if (mech != 40) ++bad;
""",
      "regtest.cpp: six mech pins flip to 40",
      expect=6, marker="if (mech != 40) ++bad;")

patch("regtest.cpp",
"""exactly twenty-nine mechanical""",
"""exactly forty mechanical""",
      "regtest.cpp: six comments flip to forty",
      expect=6, marker="exactly forty mechanical")

patch("regtest.cpp",
"""        // R135 19 -> 24, R136 24 -> 29)
""",
"""        // R135 19 -> 24, R136 24 -> 29, R139 29 -> 40)
""",
      "regtest.cpp: growth chain comment",
      marker="R139 29 -> 40)")

r139_lines = [
"    // ---- R139: engine-deep change-family audit ----",
"    // The eleven deepest attributes are wired at last:",
"    // the change family (align, attribute, class,",
"    // minds, sex), both distorted readings, both",
"    // resisting readings, geases, disintegrates - the",
"    // mechanical set grows to forty (all conventions;",
"    // the print gives names only).",
"    {",
"        int bad = 0;",
"        {",
"            int mech = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)",
"                if (dm::appendixh::trickIsMechanical(a)) ++mech;",
"            if (mech != 40) ++bad;",
"        }",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_CHANGE_ALIGN) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_CHANGE_ATTRIBUTE) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_CHANGE_CLASS) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_CHANGE_MINDS) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_CHANGE_SEX)) ++bad;",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_DISTORTED_WL) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_DISTORTED_HD) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_RESISTING_GENERAL) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_RESISTING_SPECIFIC) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GEASES) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_DISINTEGRATES)) ++bad;",
"        // the honest deeps stay dressing",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ANTI_MAGIC) ||",
"            dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ENRAGES)) ++bad;",
"        // and the eleven never talk",
"        if (dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_CHANGE_ALIGN) ||",
"            dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_GEASES) ||",
"            dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_DISINTEGRATES)) ++bad;",
"        printf(" + chr(34) + "R139 engine-deep change-family audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r139_audit = NL.join(r139_lines)
old_r138_head = "    // ---- R138: talk-flavor parley audit ----"
patch("regtest.cpp", old_r138_head + NL,
      r139_audit + NL + old_r138_head + NL,
      "regtest.cpp: R139 audit",
      marker="R139 engine-deep change-family audit")

patch("tools/dmg_gap_report.md",
"""      exact. Pinned by the R138 parley audit; census 56.

## Out of scope by design
""",
"""      exact. Pinned by the R138 parley audit; census 56.
- [x] **Engine-deep change-family slice (the hardest
      mapping left)** - CLOSED R139: eleven Appendix H
      attributes wired, mechanical set 29 -> 40, all
      conventions (the print gives names only). Change
      align (save or WIS and CHA drop), change
      attribute (save or two abilities swap), change
      class (save or training unravels - xp resets),
      change minds (save or INT drops), change sex
      (save or CHA drops), distorted WL (the bent
      weapon, 1d6), distorted HD (save or max hp
      drops), resisting general (the company is
      repelled), resisting specific (repelled, and the
      trick is not spent), geases (save or WIS drops),
      disintegrates (save or gone). The battery pins
      the set at forty, the eleven mechanical, the
      honest deeps (anti-magic, enrages) dressing, and
      the eleven never talky. Pinned by the R139
      change-family audit; census 57.

## Out of scope by design
""",
      "gap report: R139 box",
      marker="CLOSED R139:")

# ---- R139 fails/tail ----
if fails:
    print("R139 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R139 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R139 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
