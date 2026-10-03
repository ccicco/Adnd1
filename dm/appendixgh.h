// ============================================================================
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
// special-rooms layer: "Altar (Animated)"
inline std::string trickSummary(int f, int a) {
    return std::string(trickFeatureName(f)) + " (" +
           trickAttributeName(a) + ")";
}

}  // namespace appendixh
}  // namespace dm
