// R-refactor: split from uwspells.h - definitions
#include "rules/dmg/uwspells.h"

bool Uwspells::uwSpellRangesAsDungeons() { return true; }

bool Uwspells::uwMaterialComponentsAltered() {
    return true;
}

bool Uwspells::uwFireSpellsFailExceptInAiryWater() {
    return true;
}

bool Uwspells::uwElectricalSpellsConductedToArea() {
    return true;
}

int Uwspells::uwCannotCastCount() { return 41; }

bool Uwspells::uwStrEq(const char* a, const char* b) {
    int i = 0;
    while (a[i] != 0 && b[i] != 0) {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == b[i];
}

const UwCannotCast& Uwspells::uwCannotCast(int i) {
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

int Uwspells::uwCannotCastClassCount(const char* cls) {
    int n = 0;
    for (int i = 0; i < 41; ++i)
        if (uwStrEq(uwCannotCast(i).cls, cls)) ++n;
    return n;
}

bool Uwspells::uwIsCannotCast( const char* cls, int level, const char* name) {
    for (int i = 0; i < 41; ++i) {
        const UwCannotCast& e = uwCannotCast(i);
        if (e.level == level && uwStrEq(e.cls, cls)
                && uwStrEq(e.name, name))
            return true;
    }
    return false;
}

bool Uwspells::uwHeatMetalReverseChillWorks() {
    return true;
}

bool Uwspells::uwFireShieldColdFlameWorks() {
    return true;
}

int Uwspells::uwAlteredCount() { return 10; }

const UwAltered& Uwspells::uwAltered(int i) {
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

int Uwspells::uwPartWaterTunnelDiameterFeet() {
    return 10;
}

int Uwspells::uwEarthquakeStunRoundsMin() { return 5; }

int Uwspells::uwEarthquakeStunRoundsMax() { return 20; }

bool Uwspells::uwEarthquakeSaveVsDeathMagic() {
    return true;
}

bool Uwspells::uwConjureEarthElementalConfinedToFloor() {
    return true;
}

int Uwspells::uwFlyMaxSpeedInches() { return 9; }

int Uwspells::uwLightningBoltRadiusInches() { return 2; }

bool Uwspells::uwLightningBoltSaveForHalf() {
    return true;
}

int Uwspells::uwIceStormHailDamageMin() { return 1; }

int Uwspells::uwIceStormHailDamageMax() { return 10; }

bool Uwspells::uwIceStormSleetNoEffect() {
    return true;
}

bool Uwspells::uwWallOfIceFloatsToSurface() {
    return true;
}

bool Uwspells::uwConjureElementalAirOrFireImpossible() {
    return true;
}

bool Uwspells::uwConjureElementalWaterFine() {
    return true;
}

int Uwspells::uwFreezingSphereCubicFeetPerLevel() {
    return 50;
}

int Uwspells::uwFreezingSphereDurationRoundsPerLevel() {
    return 1;
}

bool Uwspells::uwFreezingSphereCasterSuffocates() {
    return true;
}
