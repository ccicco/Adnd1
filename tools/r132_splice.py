#!/usr/bin/python3
# tools/r132_splice.py - R132 Appendix H second-effects
# slice: six more attributes wired (the mechanical set
# grows 5 -> 11; 54 stay dressing).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical grows to eleven -
#    ages, flesh to stone, both shocks, counterfeit,
#    takes/steals (print sources: the altar ages 10
#    years, the face petrifies on a failed save, the
#    pedestal shocks 5-50 hp; counterfeit crumbles
#    worthless; takes/steals is a convention)
#  - game/state_dungeon.cpp: applyTrick gains the six
#    branches (the R115 aging shape, the petrification
#    save category, the pedestal shock, the worthless
#    shower, the purse lift)
#  - regtest.cpp: the R128 audit's mechanical count pins
#    update (5 -> 11; the counterfeit dressing pin
#    flips) and the new R132 audit pins the set
#    (census 50)
#  - tools/dmg_gap_report.md: the R128 box's dressing
#    count drops to 54; the R132 box closes
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
"""// R128: the first-effects slice - the five attributes the
// special-rooms layer wires to real mechanics (releases
// coins/gems/magic item, shoots, poison; see
// game/state_dungeon.cpp, applyTrick). The remaining 60
// stay dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
    return a == TA_REL_COINS || a == TA_REL_GEMS ||
           a == TA_REL_MAGIC_ITEM || a == TA_SHOOTS ||
           a == TA_POISON;
}
""",
"""// R128: the first-effects slice - the five attributes the
// special-rooms layer wires to real mechanics (releases
// coins/gems/magic item, shoots, poison; see
// game/state_dungeon.cpp, applyTrick). R132 wires the
// second-effects slice: ages (10 years, the altar example),
// flesh to stone (save or petrified, the face example),
// both electrical shocks (5-50 hp, the pedestal example),
// releases counterfeit (a worthless shower), and
// takes/steals (10-60 gp - the print gives no figure; a
// rebuild convention). The remaining 54 stay dressing;
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
      "appendixgh.h: mechanical set 11",
      marker="R132 wires the")

patch("game/state_dungeon.cpp",
"""        // shoots/poison strike a random living member with
        // the trap shape (save vs death/poison or 2d6).
""",
"""        // shoots/poison strike a random living member with
        // the trap shape (save vs death/poison or 2d6).
        // R132: the second-effects slice - ages (10 years),
        // flesh to stone (save vs petrification),
        // electrical shock (5-50 hp, no save printed),
        // releases counterfeit (worthless), takes/steals
        // (10-60 gp).
""",
      "state_dungeon.cpp: applyTrick doc",
      marker="R132: the second-effects slice - ages")

patch("game/state_dungeon.cpp",
"""        int a = room.trickAttribute;
""",
"""        int a = room.trickAttribute;
        // R132: the second-slice victim pick (the same
        // random-living-member selection the trap shape
        // uses, hoisted for the new branches)
        auto victimIndex = & -> int {
            int victims[PARTY_MAX];
            int nv = 0;
            for (int i = 0; i < (int)party.members.size(); ++i)
                if (party.members[i].hp > 0)
                    victims[nv++] = i;
            if (nv == 0) return -1;
            return victims[(size_t)rng.below((uint32_t)nv)];
        };
""",
      "state_dungeon.cpp: victim lambda",
      marker="R132: the second-slice victim pick")

patch("game/state_dungeon.cpp",
"""        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
"""        } else if (a == dm::appendixh::TA_AGES) {
            // R132: the print's altar example - age the
            // character 10 years (the R115 shape)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            applyMagicalAging(c, party.careerDays, 10);
            log.add("The " + name + " ages " + c.name +
                    " 10 years!");
        } else if (a == dm::appendixh::TA_FLESH_TO_STONE) {
            // R132: the print's face example - save versus
            // magic or be transformed; the petrification
            // save category, stone on failure
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level,
                rules::SAVE_PETRIFY_POLY);
            if (rules::attemptSave(dice, target, 0)) {
                log.add("The " + name + " glooms - " +
                        c.name + " saved!");
                return;
            }
            c.hp = 0;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s turns %s to stone - %s falls!",
                     name.c_str(), c.name.c_str(),
                     c.name.c_str());
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_SHOCK_METAL ||
                   a == dm::appendixh::TA_SHOCK_MAGIC) {
            // R132: the print's pedestal example - a
            // magical shock for 5-50 hit points (no save
            // printed)
            int vi = victimIndex();
            if (vi < 0) return;
            Character& c = party.members[vi];
            int dmg = (int)dice.roll(5, 10, 0);
            c.hp -= dmg;
            char buf[192];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s shocks %s for %d - %s falls!",
                         name.c_str(), c.name.c_str(), dmg,
                         c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s shocks %s for %d.",
                         name.c_str(), c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        } else if (a == dm::appendixh::TA_REL_COUNTERFEIT) {
            // R132: releases counterfeit - the shower crumbles
            // worthless (nothing gained)
            log.add("The " + name + " releases a shower of "
                    "coins - counterfeit, crumbling to dust.");
        } else if (a == dm::appendixh::TA_TAKES) {
            // R132: takes/steals - 10-60 gp from the purse
            // (the print gives no figure; a rebuild
            // convention)
            int gp = (int)dice.roll(1, 6, 0) * 10;
            if (party.gold >= gp) {
                party.gold -= gp;
            } else {
                gp = party.gold;
                party.gold = 0;
            }
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s steals %d gp and is gone.",
                     name.c_str(), gp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_SHOOTS ||
""",
      "state_dungeon.cpp: six new branches",
      marker="TA_AGES) {")

patch("regtest.cpp",
"""        // the first-effects slice: exactly five mechanical
""",
"""        // the two slices: exactly eleven mechanical (R132
        // grew the set 5 -> 11; counterfeit flipped)
""",
      "regtest.cpp: R128 audit comment",
      marker="the two slices: exactly eleven")

patch("regtest.cpp",
"""            if (mech != 5) ++bad;
""",
"""            if (mech != 11) ++bad;
""",
      "regtest.cpp: R128 mech count 11",
      marker="mech != 11")

patch("regtest.cpp",
"""        // the slice neighbors stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
""",
"""        // R132: counterfeit joined the mechanical set; the
        // talks stay dressing
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
""",
      "regtest.cpp: counterfeit flips",
      marker="counterfeit joined the mechanical set")


# R132-CHUNK-1-END
