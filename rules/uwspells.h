// ====================================================================
// Adnd1 - rules/uwspells.h
// R168: underwater spell use (DMG p.57) - the
// cannot-cast and altered spell lists.
//
// Pure data, header-only (the grenade.h pattern:
// the caller decides casting and tracks the
// effects; the underwater encounter tables stay
// pinned R60/R127).
//
// The p.57 print:
//   - Spell ranges and distances are limited to
//     the same as in dungeons; material
//     components are altered by water.
//   - Fire-based spells (such as fireball) will
//     not function at all underwater, except
//     within the radius of an airy water spell.
//   - Electrical spells are conducted to the
//     entire surrounding area - a lightning
//     bolt behaves as a fireball.
//   - The cannot-cast lists (9 cleric, 22 druid,
//     10 magic-user): every entry, its level
//     and its printed asterisk mark pinned below.
//     The re-upload OCR shows no footnote
//     explaining the asterisk, so it rides as a
//     flag.
//   - The altered-effects list (10 entries) with
//     the printed effect text and numerics.
// ====================================================================

#pragma once

namespace rules {

// ----------------------------------------------------------------------------
// The general paragraph (p.57)
// ----------------------------------------------------------------------------

inline bool uwSpellRangesAsDungeons() { return true; }
inline bool uwMaterialComponentsAltered() {
    return true;
}
inline bool uwFireSpellsFailExceptInAiryWater() {
    return true;
}
inline bool uwElectricalSpellsConductedToArea() {
    return true;
}

// ----------------------------------------------------------------------------
// The cannot-cast lists (p.57)
// ----------------------------------------------------------------------------

struct UwCannotCast {
    const char* cls;
    int level;
    const char* name;
    bool printedMark;  // the printed asterisk
};

inline int uwCannotCastCount() { return 41; }

// A tiny string equality (no library includes
// in the header).
inline bool uwStrEq(const char* a, const char* b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == b[i];
}

inline const UwCannotCast& uwCannotCast(int i) {
    static const UwCannotCast k[41] = {
        // cleric (9)
        { "cleric", 3, "speak with dead", true },
        { "cleric", 4, "lower water", false },
        { "cleric", 4, "speak with plants", true },
        { "cleric", 5, "atonement", true },
        { "cleric", 5, "flame strike", false },
        { "cleric", 5, "insect plague", false },
        { "cleric", 6, "aerial servant", false },
        { "cleric", 7, "control weather", false },
        { "cleric", 7, "wind walk", false },
        // druid (22)
        { "druid", 1, "predict weather", false },
        { "druid", 2, "fire trap", false },
        { "druid", 2, "heat metal", false },
        { "druid", 2, "produce flame", true },
        { "druid", 3, "call lightning", false },
        { "druid", 3, "pyrotechnics", true },
        { "druid", 4, "animal summoning I", false },
        { "druid", 4, "call woodland beings", false },
        { "druid", 4, "produce fire", true },
        { "druid", 5, "animal summoning II", false },
        { "druid", 5, "control winds", false },
        { "druid", 5, "insect plague", false },
        { "druid", 5, "pass plant", false },
        { "druid", 5, "wall of fire", false },
        { "druid", 6, "animal summoning III", false },
        { "druid", 6, "conjure fire elemental", false },
        { "druid", 6, "fire seeds", false },
        { "druid", 6, "weather summoning", false },
        { "druid", 7, "Chariot of Sustarre", false },
        { "druid", 7, "control weather", false },
        { "druid", 7, "creeping doom", false },
        { "druid", 7, "fire storm", false },
        // magic-user (10)
        { "magic-user", 1, "affect normal fires", true },
        { "magic-user", 1, "burning hands", true },
        { "magic-user", 1, "find familiar", false },
        { "magic-user", 2, "pyrotechnics", true },
        { "magic-user", 3, "fireball", false },
        { "magic-user", 3, "flame arrow", true },
        { "magic-user", 3, "gust of wind", false },
        { "magic-user", 4, "fire charm", false },
        { "magic-user", 4, "fire shield (hot flame)", true },
        { "magic-user", 4, "fire trap", false }
    };
    if (i < 0) i = 0;
    if (i > 40) i = 40;
    return k[i];
}

inline int uwCannotCastClassCount(const char* cls) {
    int n = 0;
    for (int i = 0; i < 41; ++i)
        if (uwStrEq(uwCannotCast(i).cls, cls)) ++n;
    return n;
}

inline bool uwIsCannotCast(
        const char* cls, int level, const char* name) {
    for (int i = 0; i < 41; ++i) {
        const UwCannotCast& e = uwCannotCast(i);
        if (e.level == level && uwStrEq(e.cls, cls)
                && uwStrEq(e.name, name))
            return true;
    }
    return false;
}

// The printed druid note: heat metal will not
// function but its reverse, chill metal, will.
inline bool uwHeatMetalReverseChillWorks() {
    return true;
}

// The printed magic-user note: the cold flame
// version of fire shield will still function.
inline bool uwFireShieldColdFlameWorks() {
    return true;
}

// ----------------------------------------------------------------------------
// The altered-effects list (p.57)
// ----------------------------------------------------------------------------

struct UwAltered {
    const char* cls;
    int level;
    const char* name;
    const char* effect;
};

inline int uwAlteredCount() { return 10; }

inline const UwAltered& uwAltered(int i) {
    static const UwAltered k[10] = {
        { "cleric", 6, "part water",
          "tunnel through deep water, no wider than 10 feet" },
        { "cleric", 7, "earthquake",
          "shock waves stun all in range, save vs death magic, 5-20 rounds" },
        { "druid", 7, "conjure earth elemental",
          "confined to the water floor, may strike what rests on or in the ground" },
        { "magic-user", 3, "fly",
          "swim easily at any depth, even encumbered, speed 9 inches" },
        { "magic-user", 3, "lightning bolt",
          "behaves as fireball, 2 inch radius sphere, save for half" },
        { "magic-user", 3, "ice storm",
          "hail 1-10 damage then floats, sleet no effect" },
        { "magic-user", 3, "wall of ice",
          "floats to the surface like an ice floe" },
        { "magic-user", 5, "conjure elemental",
          "air and fire impossible, earth as the druid spell, water fine" },
        { "magic-user", 6, "freezing sphere (Otiluke)",
          "50 cubic feet of ice per level, rounds per level, suffocation" },
        { "magic-user", 6, "part water",
          "as the 6th level clerical part water" }
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

// The altered-effect numerics (p.57).
inline int uwPartWaterTunnelDiameterFeet() {
    return 10;
}
inline int uwEarthquakeStunRoundsMin() { return 5; }
inline int uwEarthquakeStunRoundsMax() { return 20; }
inline bool uwEarthquakeSaveVsDeathMagic() {
    return true;
}
inline bool uwConjureEarthElementalConfinedToFloor() {
    return true;
}
inline int uwFlyMaxSpeedInches() { return 9; }
inline int uwLightningBoltRadiusInches() { return 2; }
inline bool uwLightningBoltSaveForHalf() {
    return true;
}
inline int uwIceStormHailDamageMin() { return 1; }
inline int uwIceStormHailDamageMax() { return 10; }
inline bool uwIceStormSleetNoEffect() {
    return true;
}
inline bool uwWallOfIceFloatsToSurface() {
    return true;
}
inline bool uwConjureElementalAirOrFireImpossible() {
    return true;
}
inline bool uwConjureElementalWaterFine() {
    return true;
}
inline int uwFreezingSphereCubicFeetPerLevel() {
    return 50;
}
inline int uwFreezingSphereDurationRoundsPerLevel() {
    return 1;
}
inline bool uwFreezingSphereCasterSuffocates() {
    return true;
}

} // namespace rules
