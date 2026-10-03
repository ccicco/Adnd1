#!/usr/bin/python3
# tools/r128_splice.py - R128 special rooms (DMG Appendix H
# tricks, pp.216-217 - the first-effects slice of the layer
# R125 pinned).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - dm/appendixgh.h: trickIsMechanical - the five
#    attributes wired to real mechanics this round (releases
#    coins / gems / magic item, shoots, poison); the other
#    60 stay dressing, documented
#  - game/appstate.h: RoomOccupant gains trickFeature /
#    trickAttribute / trickDone (transient, re-populated on
#    load like trapKind); the applyTrick declaration
#  - game/state_dungeon.cpp: populateRooms rolls a curiosity
#    (20%, the design figure - the H lists are selection
#    lists, not frequency tables) for an unoccupied,
#    untrapped room; applyTrick pays the mechanical slice
#  - game/state_town.cpp: describeRoom announces the
#    curiosity on first entry and triggers the effect
#  - regtest.cpp: the R128 special rooms audit (counts 37/65,
#    name loops, summary pins, slice pins - census 46)
#  - tools/dmg_gap_report.md: the special-rooms box opens
#    CLOSED R128
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

# R128-CHUNK-1-START (appendixgh.h + appstate.h)

patch("dm/appendixgh.h",
r"""
inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

}  // namespace appendixh""",
r"""
inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

// R128: the first-effects slice - the five attributes the
// special-rooms layer wires to real mechanics (releases
// coins/gems/magic item, shoots, poison; see
// game/state_dungeon.cpp, applyTrick). The remaining 60
// stay dressing; their effects ride future rounds.
inline bool trickIsMechanical(int a) {
    return a == TA_REL_COINS || a == TA_REL_GEMS ||
           a == TA_REL_MAGIC_ITEM || a == TA_SHOOTS ||
           a == TA_POISON;
}

}  // namespace appendixh""",
      "appendixgh.h: trickIsMechanical",
      marker="inline bool trickIsMechanical(int a) {")

patch("dm/appendixgh.h",
r"""
// Appendix G supplies the name, Appendix H supplies the
// dressing lists for the future special-rooms layer.""",
r"""
// Appendix G supplies the name, Appendix H supplies the
// dressing lists - WIRED SINCE R128: the special-rooms
// layer rolls a feature + attribute per unoccupied,
// untrapped room and pays the first-effects slice (see
// game/state_dungeon.cpp, applyTrick).""",
      "appendixgh.h: wired note",
      marker="WIRED SINCE R128")

patch("game/appstate.h",
r"""
    int headsLo = 0, headsHi = 0;
    int ageLo = 0, ageHi = 0;
};""",
r"""
    int headsLo = 0, headsHi = 0;
    int ageLo = 0, ageHi = 0;
    // R128: Appendix H special rooms - the rolled trick
    // (feature + attribute) for an unoccupied, untrapped
    // room; transient, re-populated on load like trapKind.
    // trickDone gates the one-shot mechanical effect.
    int trickFeature = -1;
    int trickAttribute = -1;
    bool trickDone = false;
};""",
      "appstate.h: RoomOccupant trick fields",
      marker="int trickFeature = -1;")

patch("game/appstate.h",
r"""
    void springTrap(int roomIndex);

    // R45: place secret doors""",
r"""
    void springTrap(int roomIndex);

    // R128: apply a special room's mechanical trick effect
    // (the first-effects slice: releases coins/gems/magic
    // item, shoots, poison - the trap-strike shape).
    void applyTrick(int roomIndex);

    // R45: place secret doors""",
      "appstate.h: applyTrick decl",
      marker="void applyTrick(int roomIndex);")

# R128-CHUNK-1-END

# R128-CHUNK-2-START (dungeon + town + regtest + gap report)

patch("game/state_dungeon.cpp",
r"""
            room.trap = 0;
            room.trapKind = -1;   // R125: re-rolled at arming
            room.flavorSeen = false;   // R46""",
r"""
            room.trap = 0;
            room.trapKind = -1;   // R125: re-rolled at arming
            room.trickFeature = -1;   // R128: re-rolled below
            room.trickAttribute = -1;
            room.trickDone = false;
            room.flavorSeen = false;   // R46""",
      "state_dungeon.cpp: populate resets",
      marker="room.trickFeature = -1;   // R128: re-rolled below")

patch("game/state_dungeon.cpp",
r"""
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                }
                continue;
            }""",
r"""
            if (rng.below(100) >= 50) {
                // R45: an unoccupied room may hide a dart trap
                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                } else if (rng.below(100) < 20) {
                    // R128: Appendix H special rooms - an
                    // unoccupied, untrapped room may hold a
                    // curiosity (20%, the design figure: the
                    // book's H lists are selection lists, not
                    // frequency tables, so no printed weights
                    // exist - the odds ride the design debt).
                    // Uniform picks, the book gives no weights;
                    // a room is a snare OR a curiosity, never
                    // both (documented).
                    room.trickFeature = (int)rng.below(
                        (uint32_t)dm::appendixh::
                        TRICK_FEATURE_COUNT);
                    room.trickAttribute = (int)rng.below(
                        (uint32_t)dm::appendixh::
                        TRICK_ATTRIBUTE_COUNT);
                    room.trickDone = false;
                }
                continue;
            }""",
      "state_dungeon.cpp: the trick roll",
      marker="R128: Appendix H special rooms - an")

patch("game/state_dungeon.cpp",
r"""
        log.add(buf);
        if (!party.alive()) {
            log.add("GAME OVER - press N to roll a new party.");
        }
    }

// ---- placeSecretDoors ----""",
r"""
        log.add(buf);
        if (!party.alive()) {
            log.add("GAME OVER - press N to roll a new party.");
        }
    }

// ---- applyTrick ----
void AppState::applyTrick(int roomIndex){
        // R128: the special room's mechanical effect - the
        // first-effects slice. Releases coins/gems/magic item
        // pay out (the R56 strip convention: delveGold rides,
        // no xp - an unguarded dressing find is not a hoard);
        // shoots/poison strike a random living member with
        // the trap shape (save vs death/poison or 2d6).
        if (roomIndex < 0 ||
            roomIndex >= (int)occupancy.rooms.size())
            return;
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.trickFeature < 0) return;
        const std::string name = dm::appendixh::trickSummary(
            room.trickFeature, room.trickAttribute);
        int a = room.trickAttribute;
        if (a == dm::appendixh::TA_REL_COINS) {
            int gp = (int)dice.roll(2, 6, 0) * 10 * dungeonLevel;
            party.gold += gp;
            party.delveGold += gp;   // R45: the take
            char buf[160];
            snprintf(buf, sizeof buf,
                     "The %s releases %d gp - yours.",
                     name.c_str(), gp);
            log.add(buf);
        } else if (a == dm::appendixh::TA_REL_GEMS) {
            int gems = (int)dice.roll(1, 3, 0);
            long long worth = 0;
            for (int i = 0; i < gems; ++i)
                worth += dm::treasure::rollGemValue(dice);
            party.gold += (int)worth;
            party.delveGold += (int)worth;
            char buf[192];
            snprintf(buf, sizeof buf,
                     "The %s releases %d gems, worth %lld gp.",
                     name.c_str(), gems, worth);
            log.add(buf);
        } else if (a == dm::appendixh::TA_REL_MAGIC_ITEM) {
            // the R44 unidentified-pickup shape
            Party::PendingItem it;
            it.kind = (int)rng.below(2);
            it.plus = 1 + (rng.below(100) < 10 ? 1 : 0);
            party.unidentified.push_back(it);
            log.add("The " + name + " yields an unidentified "
                    "magic item - a scribe's scroll would "
                    "serve.");
        } else if (a == dm::appendixh::TA_SHOOTS ||
                   a == dm::appendixh::TA_POISON) {
            int victims[PARTY_MAX];
            int nv = 0;
            for (int i = 0; i < (int)party.members.size(); ++i)
                if (party.members[i].hp > 0)
                    victims[nv++] = i;
            if (nv == 0) return;
            int vi = victims[(size_t)rng.below((uint32_t)nv)];
            Character& c = party.members[vi];
            int target = rules::saveTarget(
                c.classIndex, c.level, rules::SAVE_DEATH_POISON);
            if (rules::attemptSave(dice, target, 0)) {
                char buf[192];
                snprintf(buf, sizeof buf,
                         "The %s %s - %s saved!",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "belches venom" : "fires",
                         c.name.c_str());
                log.add(buf);
                return;
            }
            int dmg = (int)dice.roll(2, 6, 0);
            c.hp -= dmg;
            char buf[224];
            if (c.hp <= 0) {
                c.hp = 0;
                snprintf(buf, sizeof buf,
                         "The %s %s %s for %d - %s falls!",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "envenoms" : "hits",
                         c.name.c_str(), dmg, c.name.c_str());
            } else {
                snprintf(buf, sizeof buf,
                         "The %s %s %s for %d.",
                         name.c_str(),
                         a == dm::appendixh::TA_POISON
                             ? "envenoms" : "hits",
                         c.name.c_str(), dmg);
            }
            log.add(buf);
            if (!party.alive()) {
                log.add("GAME OVER - press N to roll a new "
                        "party.");
            }
        }
    }

// ---- placeSecretDoors ----""",
      "state_dungeon.cpp: applyTrick",
      marker="void AppState::applyTrick(int roomIndex){")

patch("game/state_town.cpp",
r"""
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
        char sprung[96];   // R125: the sprung-trap line""",
r"""
        RoomOccupant& room = occupancy.rooms[roomIndex];
        if (room.flavorSeen) return;
        room.flavorSeen = true;
        // R128: the special room - an Appendix H curiosity
        // commands the chamber (rolled at populate for an
        // unoccupied, untrapped room). The mechanical slice
        // pays out once per populate (trickDone).
        if (room.trickFeature >= 0 && room.monsterKey.empty()) {
            log.add("Something odd commands the room: " +
                    dm::appendixh::trickSummary(
                        room.trickFeature,
                        room.trickAttribute) + ".");
            if (dm::appendixh::trickIsMechanical(
                    room.trickAttribute) && !room.trickDone) {
                room.trickDone = true;
                applyTrick(roomIndex);
            }
            return;
        }
        char sprung[96];   // R125: the sprung-trap line""",
      "state_town.cpp: describeRoom special room",
      marker="Something odd commands the room")

patch("regtest.cpp",
r"""
        printf("R127 waterborne line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
r"""
        printf("R127 waterborne line-diff audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R128: special rooms audit ----
    {
        int bad = 0;
        // the Appendix H lists R128 wires: counts, names,
        // the summary phrase, and the first-effects slice
        if (dm::appendixh::TRICK_FEATURE_COUNT != 37) ++bad;
        if (dm::appendixh::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
        for (int f = 0; f < dm::appendixh::TRICK_FEATURE_COUNT;
             ++f) {
            const char* n = dm::appendixh::trickFeatureName(f);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        for (int a = 0;
             a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a) {
            const char* n =
                dm::appendixh::trickAttributeName(a);
            if (!n || !*n) { ++bad; continue; }
            for (const char* p = n; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        // out-of-range reads fall to "unknown"
        if (std::string(dm::appendixh::trickFeatureName(
                dm::appendixh::TRICK_FEATURE_COUNT))
            != "unknown") ++bad;
        if (std::string(dm::appendixh::trickAttributeName(
                dm::appendixh::TRICK_ATTRIBUTE_COUNT))
            != "unknown") ++bad;
        // the summary phrase: first and last combos
        if (dm::appendixh::trickSummary(0, 0)
            != "Altar (Ages)") ++bad;
        if (dm::appendixh::trickSummary(
                dm::appendixh::TRICK_FEATURE_COUNT - 1,
                dm::appendixh::TRICK_ATTRIBUTE_COUNT - 1)
            != "Well (Wish fulfillment, reversal)") ++bad;
        // the first-effects slice: exactly five mechanical
        {
            int mech = 0;
            for (int a = 0;
                 a < dm::appendixh::TRICK_ATTRIBUTE_COUNT; ++a)
                if (dm::appendixh::trickIsMechanical(a)) ++mech;
            if (mech != 5) ++bad;
        }
        if (!dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COINS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_GEMS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_MAGIC_ITEM) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_SHOOTS) ||
            !dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_POISON)) ++bad;
        // the slice neighbors stay dressing
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_REL_COUNTERFEIT)) ++bad;
        if (dm::appendixh::trickIsMechanical(
                dm::appendixh::TA_TALKS_NONSENSE)) ++bad;
        printf("R128 special rooms audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----""",
      "regtest.cpp: R128 special rooms audit",
      marker="R128: special rooms audit")

patch("tools/dmg_gap_report.md",
r"""
      mermaid -> merman). Pinned by the R127 battery
      audit; census 45.

## Out of scope by design""",
r"""
      mermaid -> merman). Pinned by the R127 battery
      audit; census 45.
- [x] **Special rooms (Appendix H tricks,
      pp.216-217)** - CLOSED R128: the R125-pinned dressing
      lists are wired: an unoccupied, untrapped room has a
      20% chance (the design figure - the book's H lists
      are selection lists, not frequency tables, so no
      printed weights exist; the odds ride the design debt)
      to hold a curiosity - a uniform feature (of 37) +
      attribute (of 65) rolled at populate, announced on
      first entry via trickSummary ("Something odd commands
      the room: Fountain (Talks singing)."). A room is a
      snare OR a curiosity, never both (documented). The
      first-effects slice pays out once (trickDone):
      releases coins (2d6 x 10 x level, the delve take),
      releases gems (1d3 at the DMG gem appraisal),
      releases magic item (the R44 unidentified-pickup
      shape), and shoots / poison strike a random living
      member with the trap shape (save vs death/poison or
      2d6). The other 60 attributes stay dressing -
      documented; their effects ride future rounds.
      Transient like trapKind: rooms re-populate on load.
      Pinned by the R128 battery audit; census 46.

## Out of scope by design""",
      "gap report: special-rooms box",
      marker="CLOSED R128")

# ---- the end ----
if fails:
    for f in fails:
        print("FAIL: " + f)
    sys.exit(1)
if not applied and not already:
    print("FAIL: nothing to do - anchors not found?")
    sys.exit(1)
print("R128 splice: ALL OK (applied %d, already %d)"
      % (len(applied), len(already)))
