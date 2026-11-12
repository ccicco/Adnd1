// ====================================================================
// Adnd1 - rules/dmg/uwspells.h
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



// ----------------------------------------------------------------------------
// The cannot-cast lists (p.57)
// ----------------------------------------------------------------------------
struct UwCannotCast {
    const char* cls;
    int level;
    const char* name;
    bool printedMark;  // the printed asterisk
};



// ----------------------------------------------------------------------------
// The altered-effects list (p.57)
// ----------------------------------------------------------------------------
struct UwAltered {
    const char* cls;
    int level;
    const char* name;
    const char* effect;
};

// R-refactor: namespace rules -> class Uwspells (instance methods)
class Uwspells {
public:


// ----------------------------------------------------------------------------
// The general paragraph (p.57)
// ----------------------------------------------------------------------------
    bool uwSpellRangesAsDungeons();
    bool uwMaterialComponentsAltered();
    bool uwFireSpellsFailExceptInAiryWater();
    bool uwElectricalSpellsConductedToArea();
    int uwCannotCastCount();


// A tiny string equality (no library includes
// in the header).
    bool uwStrEq(const char* a, const char* b);
    const UwCannotCast& uwCannotCast(int i);
    int uwCannotCastClassCount(const char* cls);
    bool uwIsCannotCast( const char* cls, int level, const char* name);


// The printed druid note: heat metal will not
// function but its reverse, chill metal, will.
    bool uwHeatMetalReverseChillWorks();


// The printed magic-user note: the cold flame
// version of fire shield will still function.
    bool uwFireShieldColdFlameWorks();
    int uwAlteredCount();
    const UwAltered& uwAltered(int i);


// The altered-effect numerics (p.57).
    int uwPartWaterTunnelDiameterFeet();
    int uwEarthquakeStunRoundsMin();
    int uwEarthquakeStunRoundsMax();
    bool uwEarthquakeSaveVsDeathMagic();
    bool uwConjureEarthElementalConfinedToFloor();
    int uwFlyMaxSpeedInches();
    int uwLightningBoltRadiusInches();
    bool uwLightningBoltSaveForHalf();
    int uwIceStormHailDamageMin();
    int uwIceStormHailDamageMax();
    bool uwIceStormSleetNoEffect();
    bool uwWallOfIceFloatsToSurface();
    bool uwConjureElementalAirOrFireImpossible();
    bool uwConjureElementalWaterFine();
    int uwFreezingSphereCubicFeetPerLevel();
    int uwFreezingSphereDurationRoundsPerLevel();
    bool uwFreezingSphereCasterSuffocates();
};
