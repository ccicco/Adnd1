#!/usr/bin/env python3
# tools/r140_splice.py - R140 the final Appendix H sweep:
# twelve odds-ends wired, and the 65-attribute list is
# CLOSED - every attribute is now either mechanical
# (52), talky (11), or documented-dressing by design
# (2: anti-magic needs a magic-use hook, enrages needs
# a berserk hook - neither engine exists).
# Wired: animated, combination, enlarges, false,
# gravity lesser/nil/varying, moves, randomly-acts,
# sloping, symbiotic, wish reversal.
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
# This file contains ZERO backslash characters (the
# R133b lesson); the audit printf assembles its
# escaped newline from chr(92).
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
"""// gives names only. The remaining 25 stay dressing;
// their effects ride future rounds.
""",
"""// gives names only. R140 wires the final sweep:
// animated (the furnishings buffet the company),
// combination (a strike and a repulse), enlarges
// (save or grow - STR up, DEX down), false (only
// light and shadow - the trick is spent), gravity
// lesser (a bob and drop), gravity nil (the company
// floats to the room's center), gravity varying
// (save or the crush), moves (the company is
// carried), randomly-acts (a d3 - strike, gift, or
// still), sloping (the low edge takes the company),
// symbiotic (save or a passenger settles - CON
// drops), wish reversal (the inverted boon table -
// harm, aging, or the purse bleeds). All twelve are
// conventions. THE LIST IS CLOSED: 52 mechanical,
// 11 talky, 2 dressing by design (anti-magic needs
// a magic-use hook, enrages needs a berserk hook -
// neither engine exists; documented, pinned).
""",
      "appendixgh.h: dressing comment R140",
      marker="THE LIST IS CLOSED: 52 mechanical")

patch("dm/appendixgh.h",
"""           a == TA_DISINTEGRATES;
}
""",
"""           a == TA_DISINTEGRATES ||
           a == TA_ANIMATED ||
           a == TA_COMBINATION ||
           a == TA_ENLARGES ||
           a == TA_FALSE ||
           a == TA_GRAVITY_LESSER ||
           a == TA_GRAVITY_NIL ||
           a == TA_GRAVITY_VARYING ||
           a == TA_MOVES ||
           a == TA_RANDOMLY_ACTS ||
           a == TA_SLOPING ||
           a == TA_SYMBIOTIC ||
           a == TA_WISH_REVERSAL;
}
""",
      "appendixgh.h: the final twelve join mechanical",
      marker="a == TA_WISH_REVERSAL;")

patch("game/state_dungeon.cpp",
"""        // spent), geases (save or WIS drops),
        // disintegrates (save or gone).
        if (roomIndex < 0 ||
""",
"""        // spent), geases (save or WIS drops),
        // disintegrates (save or gone). R140: the
        // final sweep - animated (the company is
        // buffeted, 1d4 each), combination (a 1d6
        // strike and a repulse), enlarges (save or
        // STR up DEX down), false (the trick is
        // spent, nothing happens), gravity lesser
        // (a bob and drop, 1d4), gravity nil (the
        // company floats to the room's center),
        // gravity varying (save or 1d6, everyone),
        // moves (carried to a random tile), randomly-
        // acts (a d3: strike, gift, or still), sloping
        // (the low edge takes the company), symbiotic
        // (save or CON drops), wish reversal (the
        // inverted boon: harm, aging, or the purse
        // bleeds).
        if (roomIndex < 0 ||
""",
      "state_dungeon.cpp: applyTrick doc R140",
      marker="R140: the")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_APPEARING) {
""",
"""        } else if (a == dm::appendixh::TA_ANIMATED) {
            // R140: the furnishings animate and buffet
            // the whole company (1d4 each, no save)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s animates - the furnishings "
                     "buffet the company!", name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                c.hp -= (int)dice.roll(1, 4, 0);
                if (c.hp <= 0) c.hp = 0;
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_COMBINATION) {
            // R140: the trick does double duty - a strike
            // AND a repulse (convention)
            int vi = victimIndex();
            if (vi >= 0) {
                Character& c = party.members[vi];
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char buf[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s strikes %s for %d - "
                             "%s falls!",
                             name.c_str(), c.name.c_str(),
                             dmg, c.name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s strikes %s for %d.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
                log.add(buf);
            }
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w > 0 && gr.h > 0) {
                int side = (int)rng.below((uint32_t)4);
                int nx = 0, ny = 0;
                if (side == 0) {
                    nx = gr.x;
                    ny = gr.y +
                         (int)rng.below((uint32_t)gr.h);
                } else if (side == 1) {
                    nx = gr.x + gr.w - 1;
                    ny = gr.y +
                         (int)rng.below((uint32_t)gr.h);
                } else if (side == 2) {
                    ny = gr.y;
                    nx = gr.x +
                         (int)rng.below((uint32_t)gr.w);
                } else {
                    ny = gr.y + gr.h - 1;
                    nx = gr.x +
                         (int)rng.below((uint32_t)gr.w);
                }
                party.x = nx;
                party.y = ny;
                log.add("The " + name + " turns on the "
                        "company - repelled!");
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_ENLARGES) {
            // R140: save vs petrification or the victim
            // grows - STR rises 1 (capped 18), DEX drops
            // 1 (floored 3 - the bulk)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " swells and "
                        "settles - " + c.name + " is "
                        "unchanged.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_STR) < 18)
                c.abilities.set(rules::ABILITY_STR,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_STR) + 1));
            if (c.abilities.get(rules::ABILITY_DEX) > 3)
                c.abilities.set(rules::ABILITY_DEX,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_DEX) - 1));
            log.add("The " + name + " swells " + c.name +
                    " - strength rises, grace thins!");
        } else if (a == dm::appendixh::TA_FALSE) {
            // R140: the feature is false - only light and
            // shadow; the trick is spent (the appearing
            // shape)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s wavers - false! Only light "
                     "and shadow. The room falls still.",
                     name.c_str());
            log.add(buf);
            room.trickFeature = -1;
        } else if (a == dm::appendixh::TA_GRAVITY_LESSER) {
            // R140: half gravity - a random member bobs
            // and drops (1d4, no save)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(1, 4, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s lightens - %s bobs, "
                         "drops - %d! %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s lightens - %s bobs and "
                         "drops - %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_GRAVITY_NIL) {
            // R140: no gravity - the company floats to
            // the room's center and hangs there
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + gr.w / 2;
            party.y = gr.y + gr.h / 2;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s stills the air - the company "
                     "floats!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_GRAVITY_VARYING) {
            // R140: gravity fluctuates - every living
            // member saves vs death/poison or 1d6 (the
            // crush shape)
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s lurches - gravity wavers!",
                     name.c_str());
            log.add(buf);
            for (auto& c : party.members) {
                if (c.hp <= 0) continue;
                int target = rules::saveTarget(
                    c.classIndex, c.level,
                    rules::SAVE_DEATH_POISON);
                if (rules::attemptSave(dice, target, 0))
                    continue;
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                if (c.hp <= 0) c.hp = 0;
            }
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_MOVES) {
            // R140: the feature moves - the company is
            // carried to a random tile of the room
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + (int)rng.below((uint32_t)gr.w);
            party.y = gr.y + (int)rng.below((uint32_t)gr.h);
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s shifts - the company is "
                     "carried along!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_RANDOMLY_ACTS) {
            // R140: the feature acts at random - a d3:
            // a strike, a gift, or stillness
            int what = (int)dice.roll(1, 3, 0);
            if (what == 1) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                int dmg = (int)dice.roll(1, 6, 0);
                c.hp -= dmg;
                char buf[192];
                if (c.hp <= 0) {
                    c.hp = 0;
                    snprintf(buf, sizeof buf,
                             "The %s lashes out at %s - %d! "
                             "%s falls!",
                             name.c_str(), c.name.c_str(),
                             dmg, c.name.c_str());
                } else {
                    snprintf(buf, sizeof buf,
                             "The %s lashes out at %s - %d.",
                             name.c_str(), c.name.c_str(),
                             dmg);
                }
                log.add(buf);
                if (!party.alive()) {
                    log.add("GAME OVER - press N to roll a "
                            "new party.");
                }
            } else if (what == 2) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                int heal = (int)dice.roll(2, 4, 2);
                c.hp += heal;
                if (c.hp > c.maxHp) c.hp = c.maxHp;
                char buf[192];
                snprintf(buf, sizeof buf,
                         "The %s gives freely - %s heals "
                         "%d.", name.c_str(),
                         c.name.c_str(), heal);
                log.add(buf);
            } else {
                log.add("The " + name + " stirs - and "
                        "does nothing.");
            }
        } else if (a == dm::appendixh::TA_SLOPING) {
            // R140: the floor slopes - the company slides
            // to the room's low (south) edge
            const dm::GeneratedRoom& gr =
                dungeon.rooms[room.roomIndex];
            if (gr.w <= 0 || gr.h <= 0) return;
            party.x = gr.x + (int)rng.below((uint32_t)gr.w);
            party.y = gr.y + gr.h - 1;
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s tilts - the company slides to "
                     "the low edge!", name.c_str());
            log.add(buf);
        } else if (a == dm::appendixh::TA_SYMBIOTIC) {
            // R140: a symbiote latches on - save vs
            // spells or CON drops 1 (floored 3)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_SPELLS);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " reaches - " +
                        c.name + " shrugs it off.");
                return;
            }
            if (c.abilities.get(rules::ABILITY_CON) > 3)
                c.abilities.set(rules::ABILITY_CON,
                    (uint8_t)(c.abilities.get(
                        rules::ABILITY_CON) - 1));
            log.add("A passenger from the " + name +
                    " settles into " + c.name + "!");
        } else if (a == dm::appendixh::TA_WISH_REVERSAL) {
            // R140: the wish fulfilled in reverse - the
            // inverted R134 boon table: harm the company,
            // age a victim, or the purse bleeds
            int what = (int)dice.roll(1, 3, 0);
            if (what == 1) {
                for (auto& c : party.members) {
                    if (c.hp <= 0) continue;
                    c.hp -= (int)dice.roll(1, 6, 0);
                    if (c.hp <= 0) c.hp = 0;
                }
                log.add("The " + name + " twists - the "
                        "company suffers!");
                if (!party.alive()) {
                    log.add("GAME OVER - press N to roll a "
                            "new party.");
                }
            } else if (what == 2) {
                int vi = victimIndex();
                if (vi < 0) return;
                Character& c = party.members[vi];
                applyMagicalAging(c, party.careerDays, 10);
                log.add("The " + name + " twists - " +
                        c.name + " ages 10 years!");
            } else {
                int loss = party.gold / 10;
                if (loss < 1) loss = 1;
                party.gold -= loss;
                char buf[160];
                snprintf(buf, sizeof buf,
                         "The %s twists - %d gp crumbles "
                         "away!", name.c_str(), loss);
                log.add(buf);
            }
        } else if (a == dm::appendixh::TA_APPEARING) {
""",
      "state_dungeon.cpp: the R140 twelve branches",
      marker="dm::appendixh::TA_WISH_REVERSAL) {")

patch("regtest.cpp",
"""        // the unwired geometry stays dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES)) ++bad;
""",
"""        // the R140 final sweep wired sloping and moves
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SLOPING)) ++bad;
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_MOVES)) ++bad;
""",
      "regtest.cpp: R135 geometry pins flip",
      marker="the R140 final sweep wired sloping and moves")

patch("regtest.cpp",
"""            if (mech != 40) ++bad;
""",
"""            if (mech != 52) ++bad;
""",
      "regtest.cpp: seven mech pins flip to 52",
      expect=7, marker="if (mech != 52) ++bad;")

patch("regtest.cpp",
"""exactly forty mechanical""",
"""exactly fifty-two mechanical""",
      "regtest.cpp: six comments flip to fifty-two",
      expect=6, marker="exactly fifty-two mechanical")

patch("regtest.cpp",
"""        // R135 19 -> 24, R136 24 -> 29, R139 29 -> 40)
""",
"""        // R135 19 -> 24, R136 24 -> 29, R139 29 -> 40,
        // R140 40 -> 52)
""",
      "regtest.cpp: growth chain comment R140",
      marker="R140 40 -> 52)")

r140_lines = [
"    // ---- R140: final sweep audit ----",
"    // The Appendix H list is CLOSED: 52 mechanical,",
"    // 11 talky, and 2 dressing by design (anti-magic",
"    // needs a magic-use hook, enrages needs a berserk",
"    // hook - neither engine exists; documented). The",
"    // final twelve: animated, combination, enlarges,",
"    // false, gravity lesser/nil/varying, moves,",
"    // randomly-acts, sloping, symbiotic, wish",
"    // reversal (all conventions - names only).",
"    {",
"        int bad = 0;",
"        {",
"            int mech = 0, talky = 0;",
"            for (int a = 0;",
"                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {",
"                if (dm::appendixh::trickIsMechanical(a)) ++mech;",
"                if (dm::appendixh::trickIsTalky(a)) ++talky;",
"            }",
"            if (mech != 52) ++bad;",
"            if (talky != 11) ++bad;",
"            if (mech + talky + 2 !=",
"                dm::appendixh::TRICK_ATTRIBUTE_COUNT) ++bad;",
"        }",
"        if (!dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ANIMATED) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_COMBINATION) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ENLARGES) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_FALSE) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GRAVITY_LESSER) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GRAVITY_NIL) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_GRAVITY_VARYING) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_MOVES) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_RANDOMLY_ACTS) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SLOPING) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_SYMBIOTIC) ||",
"            !dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_WISH_REVERSAL)) ++bad;",
"        // the two honest deeps stay dressing - by design",
"        if (dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ANTI_MAGIC) ||",
"            dm::appendixh::trickIsMechanical(",
"                dm::appendixh::TA_ENRAGES)) ++bad;",
"        // and the twelve never talk",
"        if (dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_ANIMATED) ||",
"            dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_RANDOMLY_ACTS) ||",
"            dm::appendixh::trickIsTalky(",
"                dm::appendixh::TA_WISH_REVERSAL)) ++bad;",
"        printf(" + chr(34) + "R140 final sweep audit: bad %d"
        + BS + "n" + chr(34) + ", bad);",
"        if (bad) return 1;",
"    }",
""]
r140_audit = NL.join(r140_lines)
old_r139_head = "    // ---- R139: engine-deep change-family audit ----"
patch("regtest.cpp", old_r139_head + NL,
      r140_audit + NL + old_r139_head + NL,
      "regtest.cpp: R140 audit",
      marker="R140 final sweep audit")

patch("tools/dmg_gap_report.md",
"""      change-family audit; census 57.

## Out of scope by design
""",
"""      change-family audit; census 57.
- [x] **The final Appendix H sweep (closing the
      list)** - CLOSED R140: twelve odds-ends wired -
      animated (the company is buffeted, 1d4 each),
      combination (a 1d6 strike and a repulse),
      enlarges (save or STR rises, DEX thins), false
      (only light and shadow - the trick is spent),
      gravity lesser (a bob and drop), gravity nil
      (the company floats to the room's center),
      gravity varying (save or 1d6, everyone), moves
      (carried to a random tile), randomly-acts (a
      d3: strike, gift, or still), sloping (the low
      edge takes the company), symbiotic (save or a
      passenger settles - CON drops), wish reversal
      (the inverted boon table: harm, aging, or the
      purse bleeds). THE 65-ATTRIBUTE LIST IS CLOSED:
      52 mechanical, 11 talky, and 2 dressing by
      design (anti-magic needs a magic-use hook,
      enrages needs a berserk hook - neither engine
      exists; documented and pinned). Pinned by the
      R140 final sweep audit; census 58.

## Out of scope by design
""",
      "gap report: R140 box",
      marker="CLOSED R140:")

# ---- R140 fails/tail ----
if fails:
    print("R140 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if already and not applied:
    print("R140 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R140 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
