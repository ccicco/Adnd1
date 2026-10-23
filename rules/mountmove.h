// =========================================================================================
// Adnd1 - rules/mountmove.h
// THE MOUNTED MOVEMENT CHARGE - the R123 feeder goes live, the warhorse kinds
// ride
// census 700 -> 701.
//
// The R776 site and the R777 stable left the mount bought but afoot in play:
// mountKind is saved and printed, yet nobody rides. This round charges the
// R123 feeder: a living member on a warhorse kind (2-4, the sdd ladder -
// Curtiss's call; the riding horse and pony stay walkers, the draft is a cart
// animal) moves at his mount's dm miles/day rate, every other member walks at
// his burden class, the henchman walks, and the company rides at the slowest
// member's pace. The kind mapping reads the saddle ladder consts through
// warhorseDmKind (game/party.h, the saddle include per the R400 lesson), the
// site is overlandMilesPerDay (game/state_overland.cpp, flipped from
// companyFootMilesPerDay to companyRiderMilesPerDay), and both TUs ride the
// preflight battery build, so every line is compile-gated. The first cut died
// at the Termux preflight: the party.h saddle include opened a second
// inclusion path in state_core, state_town and regtest (36 redefinitions), so
// the repair carries the classic #ifndef include guard on the saddle header
// (the wisdom.h house style; pragma once struck by Curtiss - a Windows-ism) -
// rverify is Python-only and cannot see the C++ double-include class
//
// Zero new book pages: the rates ride the already-pinned R123
// dm/outdoormove.h mounted rows
//
namespace rules {

// ---- the mounted movement charge (the R778 wiring) ----

// The feeder seam this round charges: the R123 mounted miles/day data
// (dm/outdoormove.h).
inline int mvmMovementFeederRound()
    { return 123; }

// The mounted movement round: the warhorse kinds ride, the company pace reads
// them.
inline int mvmMountedMovementRound()
    { return 778; }

// The warhorse kinds that ride: light, medium, heavy - the sdd ladder kinds
// 2-4 (Curtiss's call; the draft, riding and pony kinds walk this round).
inline int mvmWarhorseKindCount()
    { return 3; }

// The R123 terrain classes: normal, rugged, very rugged.
inline int mvmTerrainClassCount()
    { return 3; }

// The very-rugged floor every warhorse shares (the p.58-59 mounted table
// prints 5 across the warhorse rows).
inline int mvmMountedRateFloor()
    { return 5; }

// The light war horse's miles/day by terrain class (p.58-59: 60/25/5).
inline int mvmLightWarMiles(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 25;
        case 2:
            return 5;
        default:
            return 5;
        }
    }

// The medium war horse's miles/day by terrain class (p.58-59: 40/20/5).
inline int mvmMediumWarMiles(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 20;
        case 2:
            return 5;
        default:
            return 5;
        }
    }

// The heavy war horse's miles/day by terrain class (p.58-59: 30/15/5).
inline int mvmHeavyWarMiles(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 15;
        case 2:
            return 5;
        default:
            return 5;
        }
    }

// The overland site reads the riders: overlandMilesPerDay becomes
// companyRiderMilesPerDay (game/state_overland.cpp).
inline bool mvmWarhorseRidersSetThePace()
    { return true; }

// The company pace is the slowest member's: a walker still gates a mounted
// company.
inline bool mvmCompanyRidesTheSlowestMember()
    { return true; }

// The honest boundary: kinds 0/1/5/6 walk this round (the draft is a cart
// animal; the riding horse and pony stay out per Curtiss's call).
inline bool mvmNonWarhorseKindsWalk()
    { return true; }

// The henchman walks at his burden class (no mount field on the hire).
inline bool mvmHenchmanWalksTheMountedRound()
    { return true; }

// The site reads the R123 dm rows through warhorseDmKind, never a hardcoded
// rate.
inline bool mvmRatesRideThePinnedData()
    { return true; }

// The kind mapping reads the sdd ladder consts (rules/saddle.h), never raw
// ints.
inline bool mvmSaddleLadderFeedsMapping()
    { return true; }

// The saddle header carries its classic #ifndef include guard (the R778
// repair: the party.h include opened a second inclusion path in the state TUs
// and regtest - the double-include class the Python-only rverify cannot see;
// the Termux preflight is the only C++ gate; pragma once struck by Curtiss -
// a Windows-ism).
inline bool mvmSaddleHeaderGuarded()
    { return true; }

}   // namespace rules
