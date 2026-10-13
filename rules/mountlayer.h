// ===========================================================================
// Adnd1 - rules/mountlayer.h
// The MOUNT LAYER (R403) - the
// deferred engine seam lands. The
// OUT reversal rides the R321
// aerial precedent: the pins
// charge here, the
// mounted-combat charge (the
// mount actor, the mounted
// resolution) charges the engine
// later; the engine has NO mount
// actor and NO mounted-combat
// site today. The layer
// consolidates the six feeder
// seams the corpus already
// pinned and gates the
// mounted-combat rules:
//   0: R123 the mounted movement
//      (dm/outdoormove.h - the
//      60/25/5 light-horse row,
//      the road-only cart and
//      wagon)
//   1: R170 the followers mounts
//      (rules/followers.h - the
//      animals and mounts tables,
//      the paladin warhorse)
//   2: R189 the charge damage
//      (rules/weapontables.h - the
//      three lances double from a
//      charging mount, the spear
//      set receives)
//   3: R321 the aerial environment
//      (rules/aerial.h - the
//      flying steed climbs at
//      half and dives at double)
//   4: R328 the cavalier mounted
//      reads (rules/cavalier.h -
//      the human +1 level mounted,
//      the 85 percent saddle, the
//      horsemanship ladder, the
//      steed hp and worth)
//   5: R356 the mount spell
//      (rules/uamuspells1.h - the
//      summoned steed ladder)
// The R403 audit cross-checks
// every feeder live; the charge
// stays open.

#pragma once

namespace rules {

// ---- the layer contract ----
// The engine has no mount actor
// (the pins precede any site).
inline bool mmlMountActorSiteExists()
    { return false; }

inline bool mmlPinsPrecedeSite()
    { return true; }

// The seam gates the
// mounted-combat charge.
inline bool mmlGatesMountedCombatCharge()
    { return true; }

// The charge (the mount actor,
// the mounted resolution) stays
// open after the seam lands.
inline bool mmlMountedCombatChargeOpen()
    { return true; }

// The named precedent: the R321
// aerial environment - pins
// first, the site charged later.
inline int mmlAerialPrecedentRound()
    { return 321; }

// ---- the feeder registry ----
inline int mmlFeederSeamCount()
    { return 6; }

// The feeder rounds, in registry
// order (0-5 above).
inline int mmlFeederRound(int i) {
    static const int k[6] = {
        123, 170, 189, 321, 328, 356
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

// ---- the flying steeds ----
// The cavalier horsemanship
// ladder grants three flying
// steeds: the 7th pegasus, the
// 9th hippogriff, the 11th
// griffon.
inline int mmlFlyingSteedCount()
    { return 3; }

inline int mmlFlyingSteedGrantLevel(
        int i) {
    static const int k[3] = { 7, 9, 11 };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// The flying steed rides the R321
// aerial environment (the climb
// and dive rates, the ceiling).
inline bool mmlFlyingSteedsRideAerialEnv()
    { return true; }

}   // namespace rules

