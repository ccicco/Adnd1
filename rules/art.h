// =========================================================================================
// Adnd1 - rules/art.h
// The Artificer devices round - Ward's Magic and Science: Are They Compatible
// in D&D? (folios 8, 10)
// census 816 -> 817.
//
// Pinned from The Dragon Vol. 1 No. 1 (June 1976): folios 8 and 10, James M.
// Ward's Magic and Science article (the chain runs 8 -> 10 past Gold's
// Languages on 9) - the Artificer pistol and its six color-coded spheres, the
// three blue-sphere rank badges with their two beams and ray suites, and the
// anologic computer with its heat core and its logic weakness. The Parked box
// was un-parked at Curtiss's call: the items sweep.
//
// The variant-layer doctrine holds: Dragon ink is never core 1e canon. These
// are science-magic devices presented against too-powerful players, pinned as
// scanned; the sphere effect codes are CONVERTED integers - 1 melting heat, 2
// disintegration, 3 nullification, 4 the illusion maze, 5 the death circle, 6
// the crystal wall - the legend pinned beside the grid, the conversion noted,
// never silent. The silver wall and the smallest sphere's healing-void carry
// scanned zeros, noted in the column comments. OD&D-era ink converted per the
// walk doctrine: the pin IS the conversion, noted, never silent.
//
namespace rules {

// ---- the pistol and its spheres (folio 8) ----

// the Artificer pistol shoots a two-inch sphere to a MAXIMUM range of fifty
// yards (folio 8)
inline int artPistolRangeYards()
    { return 50; }

// the pistol sphere is two inches across - the stored power emits only on
// contact after release (folio 8)
inline int artSphereDiameterInches()
    { return 2; }

// six pistol sphere types, all color coded for easy identification (folio 8)
inline int artSphereTypeCount()
    { return 6; }

// the CONVERTED effect code - 1 the red circle of melting heat, 2 the black
// disintegrating circle, 3 the clear nullifying circle, 4 the brown illusion
// maze, 5 the purple circle of death, 6 the silver crystal wall - the legend
// pinned beside the grid, the conversion noted, never silent (folio 8)
inline int artSphEffectCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        default:
            return 9;
        }
    }

// the burst circle radius from the point of contact - fifteen feet for the
// five effect spheres; the silver sphere emits a wall, not a burst, pinned as
// scanned zero (folio 8)
inline int artSphBurstRadiusFeet(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 15;
        case 2:
            return 15;
        case 3:
            return 15;
        case 4:
            return 15;
        case 5:
            return 0;
        default:
            return 9;
        }
    }

// the magic saving throw gate - ONLY the black disintegrating and the purple
// death spheres carry the save; red, clear and brown are expressly no-save,
// the silver wall states none (folio 8)
inline int artSphSaveApplicable(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        default:
            return 9;
        }
    }

// the red sphere emits a circle of heat so intense it melts everything and
// anything in the area - no magic saving throw applicable (folio 8)
inline bool artRedMeltsEverything()
    { return true; }

// the clear sphere's nullifying energy destroys the usefulness of any magic
// item forever - no magic saving throw applicable (folio 8)
inline bool artClearNullifiesForever()
    { return true; }

// the brown sphere's maze is an illusion those in the circle must travel
// through to free themselves of the effects - no save (folio 8)
inline bool artBrownMazeTravel()
    { return true; }

// the silver sphere's crystal wall runs to a maximum height of sixty feet
// (folio 8)
inline int artSilverWallHeightFeet()
    { return 60; }

// the wall runs one hundred twenty feet long (folio 8)
inline int artSilverWallLengthFeet()
    { return 120; }

// the wall is ten feet thick (folio 8)
inline int artSilverWallThicknessFeet()
    { return 10; }

// the silver sphere's wall will always fill any passage or space to the
// fullest possible extent (folio 8)
inline bool artSilverFillsSpace()
    { return true; }

// the wall is synthetic crystal with the resistance of a diamond to physical
// forces (folio 8)
inline bool artSilverDiamondHard()
    { return true; }

// ---- the blue spheres (folio 8) ----

// the blue sphere comes in three sizes - largest, middle, smallest (folio 8)
inline int artBlueSphereSizes()
    { return 3; }

// the badge diameter - three feet largest, two feet middle, one foot
// smallest, and the smallest is the most powerful (folio 8)
inline int artDiameterFeet(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the damage absorber cap per melee turn - ten, fifteen, twenty points as the
// sphere shrinks (folio 8)
inline int artDamageAbsorber(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 20;
        default:
            return 9;
        }
    }

// the heat ray dice - three, five, seven dice (folio 8)
inline int artHeatRayDice(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 7;
        default:
            return 9;
        }
    }

// the healing ray per melee round - three and five points of the
// cure-light-wounds ray; the smallest carries the restoration ray instead,
// pinned as scanned zero (folio 8)
inline int artHealingPerRound(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 0;
        default:
            return 9;
        }
    }

// the displacer ray - all three sizes carry it, as the powers of the magical
// cloak (folio 8)
inline int artDisplacer(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the damage shield cap - twenty, thirty, forty points; only the damage over
// the given amount affects the sphere (folio 8)
inline int artDamageShield(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 30;
        case 2:
            return 40;
        default:
            return 9;
        }
    }

// the anti-magic shell - as the spell, carried by the middle and smallest
// spheres (folio 8)
inline int artAntiMagicShell(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the fear ray - a sonic blast as the spell, magic saving throw applicable,
// carried by the middle and smallest spheres (folio 8)
inline int artFearRay(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the anti-sphere ray - negates any pistol sphere or blue sphere effect,
// carried ONLY by the smallest (folio 8)
inline int artAntiSphereRay(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the charm monster ray - as the spell, magic saving throw applicable,
// carried ONLY by the smallest (folio 8)
inline int artCharmMonsterRay(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the restoration ray - completely regenerates any being dead or dying,
// always works within one hour of death, carried ONLY by the smallest (folio
// 8)
inline int artRestorationRay(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        default:
            return 9;
        }
    }

// the blue sphere takes twenty-five points of damage before being destroyed
// (folio 8)
inline int artBlueSphereHitPoints()
    { return 25; }

// a blue sphere floats beside its master and is able to shoot two beams
// (folio 8)
inline int artBlueSphereBeamCount()
    { return 2; }

// the restoration ray completely regenerates any being dead or dying, and
// always works if applied within one hour of death (folio 8)
inline int artRestorationWindowHours()
    { return 1; }

// the smallest blue sphere is the most powerful - the spheres are badges of
// rank, only the highest ranking leaders use them (folio 8)
inline bool artSmallestIsMostPowerful()
    { return true; }

// the best way to negate a blue sphere is an anti-magic shell cutting its
// energy supply - the sphere becomes useless forever (folio 8)
inline bool artAntiMagicKillsSphere()
    { return true; }

// the displacer ray works as the powers of the magical cloak (folio 8)
inline bool artDisplacerRayAsCloak()
    { return true; }

// ---- the anologic computer (folios 8, 10) ----

// the anologic computer is able to analyze up to one hundred spells sent at
// it (folios 8, 10)
inline int artComputerSpellAnalysis()
    { return 100; }

// the computer has a heat core power source (folio 10)
inline bool artComputerHeatCore()
    { return true; }

// the computer's primary attack is to analyze the hit points of its enemies
// and emit a double amount heat ray (folio 10)
inline bool artComputerDoubleHeatRay()
    { return true; }

// the computer's greatest weakness is its strict following of its program -
// more intelligent beings can use logic to get around it (folio 10)
inline bool artComputerLogicBlind()
    { return true; }

}   // namespace rules
