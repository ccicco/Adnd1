#!/usr/bin/python3
# tools/r125_splice.py - R125 "THE SNARE" (DMG pp.216-217,
# Appendices G: Traps and H: Tricks).
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints.
#  - writes the new header-only dm/appendixgh.h (46-kind
#    Appendix G d% trap list, band edges checked against a
#    scan of the printed page; Appendix H dressing lists,
#    37 features / 65 attributes, pinned as data)
#  - wires the trap name through the R45 trap set:
#    appstate.h trapKind field + include, the three arming
#    sites, spring/disarm log lines, the sprung-room
#    dressing line
#  - regtest.cpp: include + the R125 traps and tricks
#    audit (census becomes 43)
#  - tools/dmg_gap_report.md: the pp.216-217 box flips
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
    # idempotency keys on a distinctive NEW-side marker:
    # an anchor that is a PREFIX of its replacement (the
    # include lines, the trapKind field) still counts
    # after the patch, so "old not in s" cannot be the
    # already-applied test.
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

def writeFile(p, content, tag):
    fp = os.path.join(ROOT, p)
    if os.path.exists(fp):
        try:
            if rd(p) == content:
                already.append(tag)
                return
        except Exception:
            pass
    wr(p, content)
    applied.append(tag)


# R125-CHUNK-1-START (the new header)
H_txt = r'''// ============================================================================
// Adnd1 - dm/appendixgh.h
// R125: DMG pp.216-217 - APPENDIX G: TRAPS and APPENDIX
// H: TRICKS - the trap list and the dressing lists pinned
// row-by-row as pure data (inline accessors, no dice: the
// caller rolls). The book's trap page gives NAMES ONLY -
// no mechanics - so this repo's R45 set stays the sprung
// effect (save vs. death or 2d6, the thief spot chance);
// Appendix G supplies the name, Appendix H supplies the
// dressing lists for the future special-rooms layer.
//
// Verification note (rides the book-verify debt): the d%
// band weights below were checked against a scan of the
// printed page (p.216, "TRAP LIST (d%)"); the name
// spellings and the Appendix H lists are transcribed from
// the 1eonline.info compilation of the book pages, which
// merges a few OSRIC rows into the H lists - when the DMG
// PDF is re-uploaded, confirm the H counts (37 features /
// 65 attributes) and the trap-name spellings; the printed
// table wins on any disagreement.
// ============================================================================

#pragma once

#include <string>

namespace dm {
namespace appendixg {

// ---- APPENDIX G: TRAP LIST (p.216, d%) -------------------------------------
// 46 kinds, bands tiling 1-100 exactly as printed.
enum TrapKind {
    TRAP_ARROW = 0,              // 01-05
    TRAP_ARROW_POISONED,         // 06
    TRAP_BALL,                   // 07
    TRAP_CALTROPS,               // 08-09
    TRAP_CALTROPS_POISONED,      // 10
    TRAP_CEILING_BLOCK,          // 11
    TRAP_CEILING_COLLAPSE,       // 12
    TRAP_CEILING_LOWER,          // 13
    TRAP_CHUTE,                  // 14-16
    TRAP_DOOR_FALLING,           // 17-18
    TRAP_DOOR_ONE_WAY,           // 19-23
    TRAP_DOOR_RESISTING,         // 24-30
    TRAP_DOOR_SPECIFIC,          // 31
    TRAP_DOOR_SPRING,            // 32
    TRAP_FLOOR_COLLAPSE,         // 33
    TRAP_FLOOR_ILLUSIONARY,       // 34
    TRAP_GAS_BLINDING,           // 35-36
    TRAP_GAS_CORRODING,          // 37-38
    TRAP_GAS_FEAR,               // 39-40
    TRAP_GAS_NAUSEA,             // 41-42
    TRAP_GAS_OBSCURING,          // 43-46
    TRAP_GAS_POISON,             // 47-48
    TRAP_GAS_SLEEP,              // 49-50
    TRAP_GAS_SLOWING,            // 51-52
    TRAP_GAS_WEAKNESS,           // 53-54
    TRAP_JAW,                    // 55-56
    TRAP_LIGHTNING_BOLT,         // 57
    TRAP_PENDULUM,               // 58-59
    TRAP_PIT,                    // 60-63
    TRAP_PIT_LOCKING,            // 64-65
    TRAP_PIT_LOCKING_FLOODING,   // 66-67
    TRAP_PIT_SPIKES,             // 68-70
    TRAP_PIT_POISONED_SPIKES,    // 71-72
    TRAP_BARS_FALLING,           // 73-77
    TRAP_STONE_BLOCK,            // 78-79
    TRAP_ROOM_ELEVATOR,          // 80
    TRAP_ROOM_FLOODING,          // 81
    TRAP_ROOM_SLIDING,           // 82
    TRAP_SCYTHE,                 // 83-84
    TRAP_SPEAR,                  // 85-87
    TRAP_SPEAR_POISONED,         // 88
    TRAP_STAIRS_COLLAPSE,        // 89
    TRAP_TELEPORTER,             // 90-91
    TRAP_VENT_ACID,              // 92
    TRAP_VENT_FIRE,              // 93-94
    TRAP_VENT_GAS,               // 95-00
    TRAP_KIND_COUNT
};

// the printed d% band edges, row by row (lo, hi; 95-00
// is stored as 95-100)
inline int trapBandLo(int kind) {
    static const int LO[TRAP_KIND_COUNT] = {
        1, 6, 7, 8, 10, 11, 12, 13, 14, 17, 19, 24, 31,
        32, 33, 34, 35, 37, 39, 41, 43, 47, 49, 51, 53,
        55, 57, 58, 60, 64, 66, 68, 71, 73, 78, 80, 81,
        82, 83, 85, 88, 89, 90, 92, 93, 95 };
    if (kind < 0 || kind >= TRAP_KIND_COUNT) return 0;
    return LO[kind];
}

inline int trapBandHi(int kind) {
    static const int HI[TRAP_KIND_COUNT] = {
        5, 6, 7, 9, 10, 11, 12, 13, 16, 18, 23, 30, 31,
        32, 33, 34, 36, 38, 40, 42, 46, 48, 50, 52, 54,
        56, 57, 59, 63, 65, 67, 70, 72, 77, 79, 80, 81,
        82, 84, 87, 88, 89, 91, 92, 94, 100 };
    if (kind < 0 || kind >= TRAP_KIND_COUNT) return 0;
    return HI[kind];
}

// d% roll 1-100 -> kind (faces outside 1-100 clamp to the
// table's edges)
inline int trapFor(int r) {
    if (r < 1) r = 1;
    if (r > 100) r = 100;
    for (int k = 0; k < TRAP_KIND_COUNT; ++k)
        if (r <= trapBandHi(k)) return k;
    return TRAP_KIND_COUNT - 1;
}

// the printed name, verbatim (out-of-range kinds report
// "unknown" - a -1 trapKind on an un-rolled room)
inline const char* trapName(int kind) {
    static const char* const NAMES[TRAP_KIND_COUNT] = {
        "Arrow trap", "Arrow trap, poisoned", "Ball trap",
        "Caltrops", "Caltrops, poisoned",
        "Ceiling block falls", "Ceiling collapses",
        "Ceiling lowers", "Chute", "Door, falling",
        "Door, one way", "Door, resisting", "Door, specific",
        "Door, spring", "Floor, collapsing",
        "Floor, illusionary", "Gas, blinding",
        "Gas, corroding", "Gas, fear", "Gas, nausea",
        "Gas, obscuring", "Gas, poison", "Gas, sleep",
        "Gas, slowing", "Gas, weakness", "Jaw trap",
        "Lightning bolt", "Pendulum, ball or blade", "Pit",
        "Pit, locking", "Pit, locking and flooding",
        "Pit, with spikes", "Pit, with poisoned spikes",
        "Passage, blocked by falling bars",
        "Passage, closed by stone block", "Room, elevator",
        "Room, flooding", "Room, sliding", "Scything blade",
        "Spear trap", "Spear trap, poisoned",
        "Stairs, collapsing", "Teleporter", "Vent, acid",
        "Vent, fire", "Vent, gas" };
    if (kind < 0 || kind >= TRAP_KIND_COUNT) return "unknown";
    return NAMES[kind];
}

}  // namespace appendixg

namespace appendixh {

// ---- APPENDIX H: TRICKS, A. FEATURES (pp.216-217) -------------------------
// 37 features (transcription merges a few OSRIC rows -
// see the file-header verification note).
enum TrickFeature {
    TF_ALTAR = 0, TF_ARCH, TF_AREA, TF_BOX, TF_BUBBLES,
    TF_CEILING, TF_CONTAINER, TF_DOME, TF_DOOR,
    TF_DOOR_SECRET, TF_FACE, TF_FIRE, TF_FIREPLACE,
    TF_FORCE_FIELD, TF_FOUNTAIN, TF_FRESCO, TF_FURNISHINGS,
    TF_HALL, TF_IDOL, TF_ILLUSION, TF_ITEM, TF_MACHINE,
    TF_MONSTER, TF_PARASITE, TF_PASSAGE, TF_PEDESTAL,
    TF_PILLAR, TF_PIT, TF_POOL, TF_ROOM, TF_STAIRWAY,
    TF_STATUE, TF_TAPESTRY, TF_TREASURE, TF_VEGETATION,
    TF_WALL, TF_WELL,
    TRICK_FEATURE_COUNT
};

// ---- APPENDIX H: TRICKS, B. ATTRIBUTES (p.217) -----------------------------
// 65 attributes.
enum TrickAttribute {
    TA_AGES = 0, TA_ANIMATED, TA_ANTI_MAGIC,
    TA_APPEARING, TA_ASKS, TA_ATTACKS, TA_CHANGE_ALIGN,
    TA_CHANGE_ATTRIBUTE, TA_CHANGE_CLASS, TA_CHANGE_MINDS,
    TA_CHANGE_SEX, TA_COMBINATION, TA_COLLAPSING,
    TA_DIRECTS, TA_DISINTEGRATES, TA_DISTORTED_WL,
    TA_DISTORTED_HD, TA_ENLARGES, TA_ENRAGES, TA_SHOCK_METAL,
    TA_SHOCK_MAGIC, TA_FALSE, TA_FLESH_TO_STONE, TA_FRUIT,
    TA_GASEOUS, TA_GEASES, TA_GRAVITY_GREATER,
    TA_GRAVITY_LESSER, TA_GRAVITY_NIL, TA_GRAVITY_VARYING,
    TA_GREED, TA_INTELLIGENT, TA_INVISIBLE, TA_MOVES,
    TA_ONE_WAY, TA_PIVOTS, TA_POINTS, TA_POISON,
    TA_POLYMORPH, TA_RANDOMLY_ACTS, TA_REL_COINS,
    TA_REL_COUNTERFEIT, TA_REL_GEMS, TA_REL_MAGIC_ITEM,
    TA_RESISTING_GENERAL, TA_RESISTING_SPECIFIC, TA_RISING,
    TA_SHIFTING, TA_SHOOTS, TA_SLIDING, TA_SLOPING,
    TA_SPINNING, TA_SUGGESTS, TA_SUSPENDS, TA_SYMBIOTIC,
    TA_TAKES, TA_TALKS_SMART, TA_TALKS_NONSENSE,
    TA_TALKS_POETRY, TA_TALKS_SINGING, TA_TALKS_SPELLS,
    TA_TALKS_YELLS, TA_TELEPORTS, TA_WISH, TA_WISH_REVERSAL,
    TRICK_ATTRIBUTE_COUNT
};

inline const char* trickFeatureName(int f) {
    static const char* const NAMES[TRICK_FEATURE_COUNT] = {
        "Altar", "Arch", "Area", "Box", "Bubbles", "Ceiling",
        "Container", "Dome", "Door", "Door, secret", "Face",
        "Fire", "Fireplace", "Force field", "Fountain",
        "Fresco, mosaic, or painting", "Furnishings", "Hall",
        "Idol", "Illusion", "Item", "Machine or device",
        "Monster", "Parasite", "Passage/corridor", "Pedestal",
        "Pillar or column", "Pit", "Pool", "Room",
        "Stairway", "Statue", "Tapestry", "Treasure",
        "Vegetation", "Wall", "Well" };
    if (f < 0 || f >= TRICK_FEATURE_COUNT) return "unknown";
    return NAMES[f];
}

inline const char* trickAttributeName(int a) {
    static const char* const NAMES[TRICK_ATTRIBUTE_COUNT] = {
        "Ages", "Animated", "Anti-magic",
        "Appearing/disappearing", "Asks", "Attacks",
        "Changes alignment", "Changes attribute",
        "Changes class", "Changes minds from body to body",
        "Changes sex", "Combination", "Collapsing",
        "Directs", "Disintegrates",
        "Distorted width/length", "Distorted height/depth",
        "Enlarges/reduces", "Enrages",
        "Electrical shock if metallic",
        "Electrical shock if magical", "False",
        "Flesh to stone", "Fruit", "Gaseous", "Geases",
        "Gravity greater", "Gravity lesser", "Gravity nil",
        "Gravity varying", "Greed-producing", "Intelligent",
        "Invisible", "Moves/rolls", "One-way",
        "Pivots two possible ways", "Points", "Poison",
        "Polymorphing", "Randomly acts", "Releases coins",
        "Releases counterfeit", "Releases gems/jewelry",
        "Releases magic item", "Resisting general",
        "Resisting specific", "Rising/sinking", "Shifting",
        "Shoots", "Sliding", "Sloping", "Spinning",
        "Suggests", "Suspends animation", "Symbiotic",
        "Takes/steals", "Talks intelligently/normally",
        "Talks nonsense", "Talks poetry and rhymes",
        "Talks singing", "Talks spell casting",
        "Talks yells/screams", "Teleports",
        "Wish fulfillment", "Wish fulfillment, reversal" };
    if (a < 0 || a >= TRICK_ATTRIBUTE_COUNT) return "unknown";
    return NAMES[a];
}

// the dressing combo, phrased neutrally for the future
// special-rooms layer: "altar (animated)"
inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

}  // namespace appendixh
}  // namespace dm
'''
writeFile('dm/appendixgh.h', H_txt, 'appendixgh.h')
# R125-CHUNK-1-END
# R125-CHUNK-2-START (wiring: appstate + dungeon + town)
P_old = r'''#include "../dm/treasure.h"    // R71: MM treasure types
'''
P_new = r'''#include "../dm/treasure.h"    // R71: MM treasure types
#include "../dm/appendixgh.h"  // R125: pp.216-217 trap/trick lists
'''
patch('game/appstate.h', P_old, P_new, 'appstate-include', 1, '#include "../dm/appendixgh.h"')
P_old = r'''    // R45: 0 = no trap, 1 = armed dart trap, 2 = sprung
    int trap = 0;
'''
P_new = r'''    // R45: 0 = no trap, 1 = armed dart trap, 2 = sprung
    int trap = 0;
    // R125: the Appendix G name rolled at arming (-1 none);
    // transient - rooms re-populate on load
    int trapKind = -1;
'''
patch('game/appstate.h', P_old, P_new, 'appstate-trapkind', 1, 'int trapKind = -1;')
P_old = r'''            room.trap = 0;
            room.flavorSeen = false;   // R46
'''
P_new = r'''            room.trap = 0;
            room.trapKind = -1;   // R125: re-rolled at arming
            room.flavorSeen = false;   // R46
'''
patch('game/state_dungeon.cpp', P_old, P_new, 'dungeon-reset', 1, 'room.trapKind = -1;   // R125')
P_old = r'''                if (rng.below(100) < 15) room.trap = 1;
'''
P_new = r'''                if (rng.below(100) < 15) {
                    room.trap = 1;   // R45 dart set
                    // R125: Appendix G names the snare (d%);
                    // the book lists names only, so the R45
                    // save/2d6 mechanics stay the effect
                    room.trapKind = (int)dm::appendixg::trapFor(
                        1 + (int)rng.below(100));
                }
'''
patch('game/state_dungeon.cpp', P_old, P_new, 'dungeon-arm', 3, 'R125: Appendix G names the snare')
P_old = r'''                room.trap = 2;
                log.add(c.name + " spots a dart trap and "
                        "disarms it.");
                return;'''
P_new = r'''                room.trap = 2;
                // R125: the book's name for the snare
                log.add(c.name + " spots the trap (" +
                        dm::appendixg::trapName(room.trapKind) +
                        ") and disarms it.");
                return;'''
patch('game/state_dungeon.cpp', P_old, P_new, 'dungeon-disarm', 1, 'spots the trap (')
P_old = r'''            char buf[96];
            snprintf(buf, sizeof buf,
                     "A dart whistles past %s - saved!",
                     c.name.c_str());'''
P_new = r'''            char buf[96];
            snprintf(buf, sizeof buf,
                     "A trap! %s - %s saved!",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str());'''
patch('game/state_dungeon.cpp', P_old, P_new, 'dungeon-save', 1, '"A trap! %s - %s saved!"')
P_old = r'''        int dmg = (int)dice.roll(2, 6, 0);
        c.hp -= dmg;
        char buf[96];
        if (c.hp <= 0) {
            c.hp = 0;
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d - %s "
                     "falls!",
                     c.name.c_str(), dmg, c.name.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "A trap! Darts strike %s for %d.",
                     c.name.c_str(), dmg);
        }'''
P_new = r'''        int dmg = (int)dice.roll(2, 6, 0);
        c.hp -= dmg;
        char buf[128];   // R125: room for the book's long names
        if (c.hp <= 0) {
            c.hp = 0;
            snprintf(buf, sizeof buf,
                     "A trap! %s strikes %s for %d - %s "
                     "falls!",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str(), dmg, c.name.c_str());
        } else {
            snprintf(buf, sizeof buf,
                     "A trap! %s strikes %s for %d.",
                     dm::appendixg::trapName(room.trapKind),
                     c.name.c_str(), dmg);
        }'''
patch('game/state_dungeon.cpp', P_old, P_new, 'dungeon-fall', 1, 'char buf[128];')
P_old = r'''        room.flavorSeen = true;
        const char* line = nullptr;'''
P_new = r'''        room.flavorSeen = true;
        char sprung[96];   // R125: the sprung-trap line
        const char* line = nullptr;'''
patch('game/state_town.cpp', P_old, P_new, 'town-buf', 1, 'char sprung[96];')
P_old = r'''        else if (room.trap == 2)
            line = "Darts jut from the wall at knee height.";'''
P_new = r'''        else if (room.trap == 2) {
            // R125: name the sprung snare (App G)
            snprintf(sprung, sizeof sprung,
                     "The sprung trap (%s) lies quiet here.",
                     dm::appendixg::trapName(room.trapKind));
            line = sprung;
        }'''
patch('game/state_town.cpp', P_old, P_new, 'town-sprung', 1, 'The sprung trap (%s) lies quiet here.')
# R125-CHUNK-2-END

# R125-CHUNK-3-START (regtest audit + gap report)
P_old = r'''#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
'''
P_new = r'''#include "dm/appendixa.h"   // R124: pp.169-172 Appendix A tables
#include "dm/appendixgh.h"  // R125: pp.216-217 Appendix G/H lists
'''
patch('regtest.cpp', P_old, P_new, 'regtest-include', 1, '#include "dm/appendixgh.h"')
P_old = r'''        printf("R124 appendix A dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----'''
P_new = r'''        printf("R124 appendix A dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R125: traps and tricks audit (App G/H) ----
    {
        int bad = 0;
        {
            namespace AG = dm::appendixg;
            namespace AH = dm::appendixh;
            // band continuity: the 46 bands tile 1-100 with
            // no gaps and no overlaps (the band edges chain)
            int lo = 1;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                if (AG::trapBandLo(k) != lo) ++bad;
                if (AG::trapBandHi(k) < AG::trapBandLo(k)) ++bad;
                lo = AG::trapBandHi(k) + 1;
            }
            if (lo != 101) ++bad;
            // spot pins from the printed page (p.216)
            if (AG::trapFor(3) != AG::TRAP_ARROW) ++bad;
            if (AG::trapFor(6) != AG::TRAP_ARROW_POISONED) ++bad;
            if (AG::trapFor(9) != AG::TRAP_CALTROPS) ++bad;
            if (AG::trapFor(19) != AG::TRAP_DOOR_ONE_WAY) ++bad;
            if (AG::trapFor(24) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(30) != AG::TRAP_DOOR_RESISTING) ++bad;
            if (AG::trapFor(46) != AG::TRAP_GAS_OBSCURING) ++bad;
            if (AG::trapFor(57) != AG::TRAP_LIGHTNING_BOLT) ++bad;
            if (AG::trapFor(63) != AG::TRAP_PIT) ++bad;
            if (AG::trapFor(70) != AG::TRAP_PIT_SPIKES) ++bad;
            if (AG::trapFor(72) != AG::TRAP_PIT_POISONED_SPIKES) ++bad;
            if (AG::trapFor(77) != AG::TRAP_BARS_FALLING) ++bad;
            if (AG::trapFor(83) != AG::TRAP_SCYTHE) ++bad;
            if (AG::trapFor(87) != AG::TRAP_SPEAR) ++bad;
            if (AG::trapFor(88) != AG::TRAP_SPEAR_POISONED) ++bad;
            if (AG::trapFor(91) != AG::TRAP_TELEPORTER) ++bad;
            if (AG::trapFor(92) != AG::TRAP_VENT_ACID) ++bad;
            if (AG::trapFor(95) != AG::TRAP_VENT_GAS) ++bad;
            if (AG::trapFor(100) != AG::TRAP_VENT_GAS) ++bad;
            // counts, and every name nonempty and pure ASCII
            if (AG::TRAP_KIND_COUNT != 46) ++bad;
            for (int k = 0; k < AG::TRAP_KIND_COUNT; ++k) {
                const char* nm = AG::trapName(k);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // Appendix H: the feature (37) and attribute
            // (65) dressing lists, same name discipline
            if (AH::TRICK_FEATURE_COUNT != 37) ++bad;
            if (AH::TRICK_ATTRIBUTE_COUNT != 65) ++bad;
            for (int f = 0; f < AH::TRICK_FEATURE_COUNT; ++f) {
                const char* nm = AH::trickFeatureName(f);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            for (int a = 0; a < AH::TRICK_ATTRIBUTE_COUNT; ++a) {
                const char* nm = AH::trickAttributeName(a);
                if (!nm || !nm[0]) { ++bad; continue; }
                for (const char* p = nm; *p; ++p)
                    if ((unsigned char)*p > 127) ++bad;
            }
            // every d% face lands in range (full loop)
            for (int r = 1; r <= 100; ++r)
                if (AG::trapFor(r) < 0 ||
                    AG::trapFor(r) >= AG::TRAP_KIND_COUNT) ++bad;
            // the dressing combo smoke
            if (AH::trickSummary(AH::TF_ALTAR, AH::TA_ANIMATED)
                    != "altar (animated)") ++bad;
        }
        printf("R125 traps and tricks audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R100: hire's years audit ----'''
patch('regtest.cpp', P_old, P_new, 'regtest-audit', 1, 'R125 traps and tricks audit: bad %d')
P_old = r'''- [ ] **Traps and dressing lists (pp.216-217)**
      - full tables vs the repo's trap set.'''
P_new = r'''- [x] **Traps and dressing lists (pp.216-217)**
      - CLOSED R125: Appendix G's trap list (the d% TRAP
      LIST, 46 kinds - band weights checked against a scan
      of the printed page) is pinned row-by-row in the new
      dm/appendixgh.h, and the R45 dart-trap set now rolls
      its NAME from the table at arming: spring/disarm/
      sprung-room lines quote the book name verbatim (the
      book lists names only, so the R45 save-or-2d6 set
      stays the effect). Appendix H's dressing lists (37
      features, 65 attributes) are pinned as data for the
      future special-rooms layer (trickSummary helper).
      Pinned by the R125 battery audit; census 43. NOTE:
      name spellings and the H lists are transcribed from
      the 1eonline.info compilation of the pages and ride
      the book-verify debt with the printed table as the
      winner.'''
patch('tools/dmg_gap_report.md', P_old, P_new, 'gap-report', 1, 'CLOSED R125')
# R125-CHUNK-3-END

# ---- verification (never trust a silent run) ----
touched = ['dm/appendixgh.h', 'game/appstate.h',
           'game/state_dungeon.cpp', 'game/state_town.cpp',
           'regtest.cpp', 'tools/dmg_gap_report.md']
for f in touched:
    fp = os.path.join(ROOT, f)
    if not os.path.exists(fp):
        fails.append('missing: ' + f)
        continue
    raw = open(fp, 'rb').read()
    if any(b > 127 for b in raw):
        fails.append('non-ascii: ' + f)
    if f.endswith(('.h', '.cpp')):
        if raw.count(b'{') != raw.count(b'}'):
            fails.append('brace imbalance: ' + f)
        if raw.count(b'(') != raw.count(b')'):
            fails.append('paren imbalance: ' + f)

for tag in applied:
    print('patched: ' + tag)
for tag in already:
    print('already: ' + tag)
if fails:
    for t in fails:
        print('FAIL: ' + t)
    sys.exit(1)
if not applied and not already:
    print('FAIL: nothing to do - anchors not found?')
    sys.exit(1)
print('R125 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
