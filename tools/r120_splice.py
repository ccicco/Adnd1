#!/usr/bin/env python3
# R120 splice: THE WIRING ROUND - R117's
# reaction roll and R118's listening get
# their first real callers.
# (1) THE PARLEY GATE (DMG p.63-64): room
# and wandering monster encounters roll
# R117's rollReaction (best-living-Cha
# spokesman adj, the R58 convention)
# before steel is drawn; only the book's
# two starred bands (violently hostile,
# hostile) mean immediate attack - the
# other five bands are parley. A parleyed
# room stops leaping (a parleyed flag on
# RoomOccupant); a non-hostile wandering
# group eyes the company and moves on.
# R58's NPC-party flow (p.176) is
# untouched. A deliberate-engage hook for
# parleyed rooms is a future round
# (documented).
# (2) LISTEN AT DOORS [H] (DMG p.60):
# new pure helper bestListenIn20(hasThief,
# thiefLevel) - a thief rides his
# hear-noise skill, else the human band
# (R114's no-race-field convention);
# listenExplore() costs a turn (R119's
# clock ticks), rolls the d20 through
# R118's listenAtDoor, and reports the
# book's IMPRECISE hint - "rumbling,
# voice-like sounds", never the monster's
# name; silent creatures (undead - the
# registry's flag) are never heard; the
# die always rolls even with nothing near
# (the book's DM discipline).
# Battery audit pins reactionAttacks on
# all seven bands and bestListenIn20's
# thief/human mapping; census becomes 38.
# Idempotent (marker checks per patch):
# run twice - the second run must print
# every patch already applied. ASCII-only.
# Refuses non-unique anchors,
# all-or-nothing.
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

DH_OLD = """// d100 + chaReactionAdj, banded (DMG p.64)
Reaction rollReaction(Dice& dice, int chaReactionAdj);"""

DH_NEW = """// d100 + chaReactionAdj, banded (DMG p.64)
Reaction rollReaction(Dice& dice, int chaReactionAdj);

// R120: the book's two starred bands mean immediate
// attack; every other band may be talked past (the
// parley gate - the caller logs the color and defers)
bool reactionAttacks(Reaction r);"""

DC_OLD = """Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    return reactionForScore((int)dice.d100() + chaReactionAdj);
}"""

DC_NEW = """Reaction rollReaction(Dice& dice, int chaReactionAdj) {
    return reactionForScore((int)dice.d100() + chaReactionAdj);
}

bool reactionAttacks(Reaction r) {
    // 01-05 violently hostile ("immediate attack") and
    // 06-25 hostile ("immediate action") - the starred
    // bands; the rest is parley (DMG p.64)
    return r == REACTION_VIOLENT || r == REACTION_HOSTILE;
}"""

ABH_OLD = """bool listenAtDoor(Dice& dice, int chanceIn20);  // d20 <= chance"""

ABH_NEW = """bool listenAtDoor(Dice& dice, int chanceIn20);  // d20 <= chance

// R120: the best listener at the door - a thief
// rides his hear-noise skill, otherwise the human
// band (R114's no-race-field convention)
int bestListenIn20(bool hasThief, int thiefLevel);"""

ABC_OLD = """bool listenAtDoor(Dice& dice, int chanceIn20) {
    if (chanceIn20 <= 0) return false;
    if (chanceIn20 >= 20) return true;
    return (int)dice.d20() <= chanceIn20;
}"""

ABC_NEW = """bool listenAtDoor(Dice& dice, int chanceIn20) {
    if (chanceIn20 <= 0) return false;
    if (chanceIn20 >= 20) return true;
    return (int)dice.d20() <= chanceIn20;
}

int bestListenIn20(bool hasThief, int thiefLevel) {
    // R120: the best ear leads - a thief's
    // hear-noise skill, else the human band
    if (hasThief) return thiefListenIn20(thiefLevel, 0);
    return listenChanceIn20(LISTEN_HUMAN, 0);
}"""

RO_OLD = """    bool flavorSeen = false;   // R46: first-entry description"""

RO_NEW = """    bool flavorSeen = false;   // R46: first-entry description
    // R120: a non-hostile parley bought peace - the room's
    // monsters no longer leap at the company (a deliberate-
    // engage hook is a future round)
    bool parleyed = false;"""

LD_OLD = """    void placeSecretDoors();"""

LD_NEW = """    // R120: [H] listen at doors (DMG p.60) - ear to the
    // nearest portal; the best listener leads (a thief's
    // hear-noise, else the human band); silent creatures
    // (undead) are never heard; the hint is imprecise per
    // the book. Costs a turn.
    void listenExplore();

    void placeSecretDoors();"""

IN_OLD = """#include "appstate.h"

// ---- restExplore ----"""

IN_NEW = """#include "appstate.h"
#include "abilities/abilities.h"   // R120: listening (p.60)

// ---- restExplore ----"""

LI_OLD = """// ---- spawnRoomEncounter ----"""

LI_NEW = """// ---- listenExplore ----
// R120: listening at doors (DMG p.60) - R118's first
// caller. [H] - ear to the nearest portal. The best
// listener leads (a thief's hear-noise skill, else the
// human band); the die ALWAYS rolls (the book's DM
// discipline - appear disinterested); silent creatures
// (undead - the registry's flag) are never heard; the
// hint is imprecise per the book: "never say 'You hear
// ogres'".
void AppState::listenExplore(){
        if (mode != MODE_EXPLORE) return;
        if (!party.alive()) return;
        ++turnCount;
        tickActivity(1);   // R119: the ear costs strain too
        int thiefLevel = 0;
        for (const auto& c : party.members)
            if (c.hp > 0 && c.classIndex == 3 &&
                c.level > thiefLevel)
                thiefLevel = c.level;
        int chance = abilities::bestListenIn20(
            thiefLevel > 0, thiefLevel);
        int roomIdx = occupiedRoomNear(party.x, party.y, 3);
        bool heard = abilities::listenAtDoor(dice, chance);
        if (roomIdx >= 0) {
            const auto& room = occupancy.rooms[roomIdx];
            const monsters::MonsterDef* def =
                registry.find(room.monsterKey);
            if (def && def->undead) heard = false;
        }
        if (roomIdx < 0 || !heard) {
            log.add("You hear nothing.");
            return;
        }
        log.add("You hear rumbling, voice-like sounds.");
    }

// ---- spawnRoomEncounter ----"""

RG_OLD = """        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.monsterKey.empty()) return;"""

RG_NEW = """        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.monsterKey.empty()) return;
        // R120: a parleyed room no longer leaps at the
        // company (the parley gate rolled non-hostile)
        if (room.parleyed) return;"""

PG_OLD = """        const monsters::MonsterDef* def = registry.find(room.monsterKey);
        // R52: foes build through the DMG-range path (hydra
        // heads / dragon age brackets, stored at population)
        std::vector<ai::Actor> foes =
            buildFoesFromDm(encFromRoom(room));
        if (foes.empty()) return;
        const char* mname = def ? def->name.c_str() : "monster";"""

PG_NEW = """        const monsters::MonsterDef* def = registry.find(room.monsterKey);
        // R52: foes build through the DMG-range path (hydra
        // heads / dragon age brackets, stored at population)
        std::vector<ai::Actor> foes =
            buildFoesFromDm(encFromRoom(room));
        if (foes.empty()) return;
        // R120: THE PARLEY GATE (DMG p.63-64, R117's first
        // caller) - the monsters react before steel is drawn;
        // only the book's two starred bands mean immediate
        // attack. Charisma follows the engine's best-living-
        // Cha spokesman convention (R58).
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        dm::Reaction react = dm::rollReaction(dice, chaAdj);
        if (!dm::reactionAttacks(react)) {
            room.parleyed = true;
            const char* mname2 = def ? def->name.c_str() : "monster";
            const char* calm =
                react == dm::REACTION_NEUTRAL
                    ? " ignores you." :
                react == dm::REACTION_UNCERTAIN_NEG
                    ? " grumbles and watches warily." :
                react == dm::REACTION_UNCERTAIN_POS
                    ? " seems curious about you." :
                react == dm::REACTION_FRIENDLY
                    ? " greets you warmly." :
                    " hails you joyfully!";
            char pbuf[96];
            if (room.count == 1)
                snprintf(pbuf, sizeof pbuf, "The %s%s",
                         mname2, calm);
            else
                snprintf(pbuf, sizeof pbuf, "The %ss%s",
                         mname2, calm);
            log.add(pbuf);
            return;
        }
        const char* mname = def ? def->name.c_str() : "monster";"""

WP_OLD = """        if (e.key.empty() || e.count <= 0) return;
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;"""

WP_NEW = """        if (e.key.empty() || e.count <= 0) return;
        std::vector<ai::Actor> foes = buildFoesFromDm(e);
        if (foes.empty()) return;

        // R120: the parley gate rides the wandering roll
        // too (DMG p.63-64) - non-hostile bands pass by
        int chaAdj = 0;
        for (const auto& c : party.members) {
            if (c.hp <= 0) continue;
            int adj = rules::chaReactionAdj(c.abilities.cha);
            if (adj > chaAdj) chaAdj = adj;
        }
        dm::Reaction react = dm::rollReaction(dice, chaAdj);
        if (!dm::reactionAttacks(react)) {
            char pbuf[96];
            if (e.count == 1)
                snprintf(pbuf, sizeof pbuf,
                         "A wandering %s eyes the company "
                         "and moves on.", e.key.c_str());
            else
                snprintf(pbuf, sizeof pbuf,
                         "%d wandering %ss eye the company "
                         "and move on.", e.count, e.key.c_str());
            log.add(pbuf);
            return;
        }"""

KH_OLD = """                    // R45: search the walls for secret doors
                    case 'F':
                    case 'f':
                        g_app.searchExplore();
                        break;"""

KH_NEW = """                    // R45: search the walls for secret doors
                    case 'F':
                    case 'f':
                        g_app.searchExplore();
                        break;

                    // R120: listen at doors (DMG p.60)
                    case 'H':
                    case 'h':
                        g_app.listenExplore();
                        break;"""

RT_OLD = """        printf("R119 forced rest audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

RT_NEW = """        printf("R119 forced rest audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R120: parley and listening wiring audit ----
    {
        int bad = 0;
        // the book's starred bands (DMG p.64): only
        // violently hostile and hostile mean immediate
        // attack; the other five bands are parley
        if (!dm::reactionAttacks(dm::REACTION_VIOLENT)) ++bad;
        if (!dm::reactionAttacks(dm::REACTION_HOSTILE)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_NEG)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_NEUTRAL)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_UNCERTAIN_POS)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_FRIENDLY)) ++bad;
        if (dm::reactionAttacks(dm::REACTION_ENTHUSIASTIC)) ++bad;
        // the best listener: a thief rides hear-noise,
        // no thief rides the human band (R114); level 0
        // clamps to the L1 row
        if (abilities::bestListenIn20(false, 0) != 2) ++bad;
        if (abilities::bestListenIn20(false, 9) != 2) ++bad;
        if (abilities::bestListenIn20(true, 0)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 1)  != 2) ++bad;
        if (abilities::bestListenIn20(true, 5)  != 4) ++bad;
        if (abilities::bestListenIn20(true, 12) != 7) ++bad;
        if (abilities::bestListenIn20(true, 13) != 7) ++bad;
        printf("R120 parley and listening audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----"""

GH_OLD = """R119 CLOSED forced rest (p.38) - one turn
in six plus a turn after combat, gated.

Categories:"""

GH_NEW = """R119 CLOSED forced rest (p.38) - one turn
in six plus a turn after combat, gated.
R120 WIRED parley (R117's reaction roll
gates room and wandering encounters;
only the starred bands attack) and
listening at doors ([H], R118's table) -
first callers for both.

Categories:"""


# ---- patch table: (file, marker, old, new, label) --------------------------

PATCHES = [
    ("dm/dm.h", "bool reactionAttacks(Reaction r);",
     DH_OLD, DH_NEW, "dm.h reactionAttacks decl"),
    ("dm/dm.cpp", "bool reactionAttacks(Reaction r) {",
     DC_OLD, DC_NEW, "dm.cpp reactionAttacks impl"),
    ("abilities/abilities.h", "int bestListenIn20(bool hasThief, int thiefLevel);",
     ABH_OLD, ABH_NEW, "abilities.h bestListenIn20 decl"),
    ("abilities/abilities.cpp", "int bestListenIn20(bool hasThief, int thiefLevel) {",
     ABC_OLD, ABC_NEW, "abilities.cpp bestListenIn20 impl"),
    ("game/appstate.h", "bool parleyed = false;",
     RO_OLD, RO_NEW, "appstate.h RoomOccupant parleyed flag"),
    ("game/appstate.h", "void listenExplore();",
     LD_OLD, LD_NEW, "appstate.h listenExplore decl"),
    ("game/state_dungeon.cpp", '#include "abilities/abilities.h"   // R120: listening (p.60)',
     IN_OLD, IN_NEW, "state_dungeon includes abilities"),
    ("game/state_dungeon.cpp", "void AppState::listenExplore(){",
     LI_OLD, LI_NEW, "state_dungeon listenExplore impl"),
    ("game/state_dungeon.cpp", "if (room.parleyed) return;",
     RG_OLD, RG_NEW, "state_dungeon parleyed guard"),
    ("game/state_dungeon.cpp", "dm::Reaction react = dm::rollReaction(dice, chaAdj);",
     PG_OLD, PG_NEW, "state_dungeon room parley gate"),
    ("game/state_combat.cpp", "eyes the company ",
     WP_OLD, WP_NEW, "state_combat wandering parley gate"),
    ("adnd1.cpp", "g_app.listenExplore();",
     KH_OLD, KH_NEW, "adnd1 [H] listen key"),
    ("regtest.cpp", "R120 parley and listening audit",
     RT_OLD, RT_NEW, "regtest R120 audit"),
    ("tools/dmg_gap_report.md", "R120 WIRED parley",
     GH_OLD, GH_NEW, "gap report header note"),
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
        print("R120 splice: REFUSED - %d of %d patches applied, "
              "nothing written" % (applied, len(PATCHES)))
        return
    for rel in texts:
        write(rel, texts[rel])
    if applied == len(PATCHES):
        print("R120 splice: ALL OK (%d patches)" % applied)
    elif applied == 0:
        print("R120 splice: nothing to do (already applied)")
    else:
        print("R120 splice: PARTIAL (%d applied, %d already) - "
              "inspect before committing" % (applied, already))


if __name__ == "__main__":
    main()
