// ============================================================================
// Adnd1 - dm/appendixgh.h
// R125: DMG pp.216-217 - APPENDIX G: TRAPS and APPENDIX
// H: TRICKS - the trap list and the dressing lists pinned
// row-by-row as pure data (inline accessors, no dice: the
// caller rolls). The book's trap page gives NAMES ONLY -
// no mechanics - so this repo's R45 set stays the sprung
// effect (save vs. death or 2d6, the thief spot chance);
// Appendix G supplies the name, Appendix H supplies the
// dressing lists - WIRED SINCE R128: the special-rooms
// layer rolls a feature + attribute per unoccupied,
// untrapped room and pays the first-effects slice (see
// game/state_dungeon.cpp, applyTrick).
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

// R137: the deliberate-engage hook - the prompt phrase
// the dungeon logs when a mechanical curiosity is first
// sighted (the sight alone no longer springs the
// feature; the company chooses: X to engage, or move
// on). Pure data - the battery pins the exact phrase.
inline const char* trickEngagePrompt() {
    return "Press X to engage the feature - or move on.";
}

// R128: the first-effects slice - the five attributes the
// special-rooms layer wires to real mechanics (releases
// coins/gems/magic item, shoots, poison; see
// game/state_dungeon.cpp, applyTrick). R132 wires the
// second-effects slice: ages (10 years, the altar example),
// flesh to stone (save or petrified, the face example),
// both electrical shocks (5-50 hp, the pedestal example),
// releases counterfeit (a worthless shower), and
// takes/steals (10-60 gp - the print gives no figure; a
// rebuild convention). R133 wires the third-effects
// slice: attacks (an animated strike, 1d8 - convention),
// fruit (heals a random living member 2d4+2, the potion
// shape - convention), greed (a scramble costs 10% of
// the purse - convention), teleports (an intra-level
// relocation to a random room center, the print's AREA
// example), collapsing (the ceiling comes down: every
// living member saves vs death/poison or 2d6 -
// convention). R134 wires the deep-effects slice:
// wish (a boon table - heal the company, restore a
// random member, or a gold shower; the print gives no
// table, so the rebuild keeps it benevolent), gravity
// greater (the pull doubles - 1d6 crushing on every
// living member, no save), polymorph (a random living
// member saves vs petrification/polymorph or takes 3d4
// reshaping damage). All three are conventions - the
// print gives no figures. R135 wires the
// room-geometry slice: one-way (the way back seals -
// the company is committed to the room), pivots and
// spinning (the room turns - the company's position
// rotates about the room center, clamped inside),
// shifting (the position mirrors across the center
// line), sliding (the company is shoved to a random
// room edge). All five are positional conventions -
// the print gives no mechanics. R136 wires the
// odds-and-ends slice: rising (water floods the room -
// every living member saves vs death/poison or takes
// 1d6), suspends (gravity nil - the company floats to
// a random interior tile), appearing (the feature
// manifests, startles, and melts away - the room's
// trick is spent), invisible (an unseen strike - 1d6
// on a random living member, no save), gaseous (a
// poison cloud - every living member saves vs
// death/poison or takes 1d6). All five are
// conventions - the print gives no figures. The
// R139 wires the engine-deep change-family slice:
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
// gives names only. R140 wires the final sweep:
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
// ---- R138: the talk-flavor parley ----
// The talks-class attributes stay NON-mechanical by
// design: they answer the deliberate-engage hook (the
// X key) with the line below - repeatable flavor;
// talk never spends the trick. Pure data - the
// battery pins the eleven-line set.
inline bool trickIsTalky(int a) {
    return a == TA_ASKS || a == TA_DIRECTS ||
           a == TA_POINTS || a == TA_SUGGESTS ||
           a == TA_INTELLIGENT ||
           a == TA_TALKS_SMART ||
           a == TA_TALKS_NONSENSE ||
           a == TA_TALKS_POETRY ||
           a == TA_TALKS_SINGING ||
           a == TA_TALKS_SPELLS ||
           a == TA_TALKS_YELLS;
}

inline const char* trickTalkLine(int a) {
    if (a == TA_ASKS)
        return "The feature asks after your quest - "
               "and waits.";
    if (a == TA_DIRECTS)
        return "The feature directs you down a "
               "corridor to the west.";
    if (a == TA_POINTS)
        return "The feature points the way onward.";
    if (a == TA_SUGGESTS)
        return "The feature suggests a quieter path "
               "below.";
    if (a == TA_INTELLIGENT)
        return "The feature weighs you with quiet, "
               "unblinking intelligence.";
    if (a == TA_TALKS_SMART)
        return "The feature speaks learnedly of the "
               "dungeon's history.";
    if (a == TA_TALKS_NONSENSE)
        return "The feature babbles nonsense and "
               "giggles.";
    if (a == TA_TALKS_POETRY)
        return "The feature recites an ode to fallen "
               "heroes.";
    if (a == TA_TALKS_SINGING)
        return "The feature sings a low, wordless "
               "melody.";
    if (a == TA_TALKS_SPELLS)
        return "The feature mutters syllables of "
               "spellcraft.";
    if (a == TA_TALKS_YELLS)
        return "The feature bellows a warning at the "
               "ceiling.";
    return "";
}

inline bool trickIsMechanical(int a) {
    return a == TA_REL_COINS || a == TA_REL_GEMS ||
           a == TA_REL_MAGIC_ITEM || a == TA_SHOOTS ||
           a == TA_POISON ||
           a == TA_AGES || a == TA_FLESH_TO_STONE ||
           a == TA_SHOCK_METAL || a == TA_SHOCK_MAGIC ||
           a == TA_REL_COUNTERFEIT || a == TA_TAKES ||
           a == TA_ATTACKS || a == TA_FRUIT ||
           a == TA_GREED || a == TA_TELEPORTS ||
           a == TA_COLLAPSING || a == TA_WISH ||
           a == TA_GRAVITY_GREATER || a == TA_POLYMORPH ||
           a == TA_ONE_WAY || a == TA_PIVOTS ||
           a == TA_SPINNING || a == TA_SHIFTING ||
           a == TA_SLIDING || a == TA_RISING ||
           a == TA_SUSPENDS || a == TA_APPEARING ||
           a == TA_INVISIBLE || a == TA_GASEOUS ||
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
           a == TA_DISINTEGRATES ||
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

}  // namespace appendixh
}  // namespace dm
