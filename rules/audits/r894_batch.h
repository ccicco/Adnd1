    // ---- R894 Artificer audit ----
    // THE ARTIFICER DEVICES ROUND - the un-parked items sweep of issue 1's
    // Parked list (Curtiss's call, 2026-10-29). Ward's magic-and-science
    // devices pinned as variant-layer items: the pistol frame (two-inch
    // sphere, fifty yards, six color-coded types), the six-sphere grid with
    // the CONVERTED effect codes and the save gates (only black
    // disintegration and purple death carry the save - red, clear, brown
    // expressly do not), the silver crystal wall (60 x 120 x 10, fills any
    // passage, diamond resistance), the blue-sphere badge grid (three sizes,
    // two beams each, the ray suites inverted to size, the smallest most
    // powerful), the chassis doctrines (25 hit points, the anti-magic kill,
    // the displacer provenance), and the computer (heat core, 100 spells
    // analyzed, the double heat ray off enemy hit points, the logic
    // weakness). The chain runs folio 8 -> 10 past Gold's Languages; the
    // effect-code conversion and the scanned zeros are noted, never silent.
    {
        using namespace rules;
        int bad = 0;
    if (artPistolRangeYards() != 50
            || artSphereDiameterInches() != 2
            || artSphereTypeCount() != 6
            || artSilverWallHeightFeet() != 60
            || artSilverWallLengthFeet() != 120
            || artSilverWallThicknessFeet() != 10
            || artRestorationWindowHours() != 1
            || artBlueSphereHitPoints() != 25
            || artBlueSphereBeamCount() != 2
            || artBlueSphereSizes() != 3
            || artComputerSpellAnalysis() != 100
            || !artRedMeltsEverything()
            || !artClearNullifiesForever()
            || !artBrownMazeTravel()
            || !artSilverFillsSpace()
            || !artSilverDiamondHard()
            || !artSmallestIsMostPowerful()
            || !artAntiMagicKillsSphere()
            || !artDisplacerRayAsCloak()
            || !artComputerHeatCore()
            || !artComputerDoubleHeatRay()
            || !artComputerLogicBlind()
        )
            ++bad;
        // the six-sphere pistol grid, rows Red, Black, Clear, Brown, Purple,
        // Silver in the folio order - each emits its circle from the point of
        // contact upon release from the pistol (folio 8)
        int CArtSph[6][3] = {
            {1,15,0},
            {2,15,1},
            {3,15,0},
            {4,15,0},
            {5,15,1},
            {6,0,0},
            };
        for (int b = 0;
             b < artSphereTypeCount();
             ++b) {
            int vals[3];
            vals[0] = artSphEffectCode(b);
            vals[1] = artSphBurstRadiusFeet(b);
            vals[2] = artSphSaveApplicable(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CArtSph[b][c])
                    ++bad;
            }
        }
        // the blue-sphere badge grid, rows largest, middle, smallest in the
        // folio order - two beams each, floating beside the master (folio 8)
        int CArtBlu[3][11] = {
            {3,10,3,3,1,20,0,0,0,0,0},
            {2,15,5,5,1,30,1,1,0,0,0},
            {1,20,7,0,1,40,1,1,1,1,1},
            };
        for (int b = 0;
             b < artBlueSphereSizes();
             ++b) {
            int vals[11];
            vals[0] = artDiameterFeet(b);
            vals[1] = artDamageAbsorber(b);
            vals[2] = artHeatRayDice(b);
            vals[3] = artHealingPerRound(b);
            vals[4] = artDisplacer(b);
            vals[5] = artDamageShield(b);
            vals[6] = artAntiMagicShell(b);
            vals[7] = artFearRay(b);
            vals[8] = artAntiSphereRay(b);
            vals[9] = artCharmMonsterRay(b);
            vals[10] = artRestorationRay(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CArtBlu[b][c])
                    ++bad;
            }
        }
        // the pistol frame - a two-inch sphere to fifty yards maximum, six
        // color-coded types (folio 8)
    if (artPistolRangeYards() != 50
            || artSphereDiameterInches() != 2
            || artSphereTypeCount() != 6
        )
            ++bad;
        // the red sphere - code one melting heat, a fifteen-foot circle, no
        // magic saving throw (folio 8)
    if (artSphEffectCode(0) != 1
            || artSphBurstRadiusFeet(0) != 15
            || artSphSaveApplicable(0) != 0
        )
            ++bad;
        // the black sphere - code two disintegrating damage as the spell, a
        // fifteen-foot circle, the save applies (folio 8)
    if (artSphEffectCode(1) != 2
            || artSphBurstRadiusFeet(1) != 15
            || artSphSaveApplicable(1) != 1
        )
            ++bad;
        // the clear sphere - code three nullifying energy, magic items
        // destroyed forever, no save (folio 8)
    if (artSphEffectCode(2) != 3
            || artSphBurstRadiusFeet(2) != 15
            || artSphSaveApplicable(2) != 0
        )
            ++bad;
        // the brown sphere - code four the illusion maze, traveled to free
        // oneself, no save (folio 8)
    if (artSphEffectCode(3) != 4
            || artSphBurstRadiusFeet(3) != 15
            || artSphSaveApplicable(3) != 0
        )
            ++bad;
        // the purple sphere - code five the circle of death as the spell, the
        // save applies (folio 8)
    if (artSphEffectCode(4) != 5
            || artSphBurstRadiusFeet(4) != 15
            || artSphSaveApplicable(4) != 1
        )
            ++bad;
        // the silver sphere - code six the crystal wall, a wall not a burst,
        // no save stated (folio 8)
    if (artSphEffectCode(5) != 6
            || artSphBurstRadiusFeet(5) != 0
            || artSphSaveApplicable(5) != 0
        )
            ++bad;
        // the three no-save effect doctrines - the melt, the forever
        // nullification, the maze travel (folio 8)
    if (artRedMeltsEverything() != 1
            || artClearNullifiesForever() != 1
            || artBrownMazeTravel() != 1
        )
            ++bad;
        // the crystal wall dimensions - sixty feet high, one hundred twenty
        // long, ten thick (folio 8)
    if (artSilverWallHeightFeet() != 60
            || artSilverWallLengthFeet() != 120
            || artSilverWallThicknessFeet() != 10
        )
            ++bad;
        // the wall always fills any passage to the fullest extent,
        // diamond-resistant synthetic crystal (folio 8)
    if (artSilverFillsSpace() != 1
            || artSilverDiamondHard() != 1
        )
            ++bad;
        // the blue-sphere chassis - twenty-five points to destroy, two beams,
        // three sizes (folio 8)
    if (artBlueSphereHitPoints() != 25
            || artBlueSphereBeamCount() != 2
            || artBlueSphereSizes() != 3
        )
            ++bad;
        // the rank badge inverted to size, the anti-magic kill, the displacer
        // provenance (folio 8)
    if (artSmallestIsMostPowerful() != 1
            || artAntiMagicKillsSphere() != 1
            || artDisplacerRayAsCloak() != 1
        )
            ++bad;
        // the LARGEST sphere - three feet, a ten-point absorber, three heat
        // dice (folio 8)
    if (artDiameterFeet(0) != 3
            || artDamageAbsorber(0) != 10
            || artHeatRayDice(0) != 3
        )
            ++bad;
        // the MIDDLE sphere - two feet, a fifteen-point absorber, five heat
        // dice (folio 8)
    if (artDiameterFeet(1) != 2
            || artDamageAbsorber(1) != 15
            || artHeatRayDice(1) != 5
        )
            ++bad;
        // the SMALLEST sphere - one foot, a twenty-point absorber, seven heat
        // dice (folio 8)
    if (artDiameterFeet(2) != 1
            || artDamageAbsorber(2) != 20
            || artHeatRayDice(2) != 7
        )
            ++bad;
        // the healing ray - three and five points per melee round,
        // restoration instead on the smallest (folio 8)
    if (artHealingPerRound(0) != 3
            || artHealingPerRound(1) != 5
            || artHealingPerRound(2) != 0
        )
            ++bad;
        // the damage shield caps - twenty, thirty, forty points (folio 8)
    if (artDamageShield(0) != 20
            || artDamageShield(1) != 30
            || artDamageShield(2) != 40
        )
            ++bad;
        // the displacer ray rides all three sizes (folio 8)
    if (artDisplacer(0) != 1
            || artDisplacer(1) != 1
            || artDisplacer(2) != 1
        )
            ++bad;
        // the anti-magic shell - middle and smallest only (folio 8)
    if (artAntiMagicShell(0) != 0
            || artAntiMagicShell(1) != 1
            || artAntiMagicShell(2) != 1
        )
            ++bad;
        // the fear ray - middle and smallest only (folio 8)
    if (artFearRay(0) != 0
            || artFearRay(1) != 1
            || artFearRay(2) != 1
        )
            ++bad;
        // the anti-sphere ray - the smallest alone negates pistol and blue
        // spheres (folio 8)
    if (artAntiSphereRay(0) != 0
            || artAntiSphereRay(1) != 0
            || artAntiSphereRay(2) != 1
        )
            ++bad;
        // the charm monster ray - the smallest alone (folio 8)
    if (artCharmMonsterRay(0) != 0
            || artCharmMonsterRay(1) != 0
            || artCharmMonsterRay(2) != 1
        )
            ++bad;
        // the restoration ray - the smallest alone (folio 8)
    if (artRestorationRay(0) != 0
            || artRestorationRay(1) != 0
            || artRestorationRay(2) != 1
        )
            ++bad;
        // the restoration ray always works within one hour of death (folio 8)
    if (artRestorationWindowHours() != 1
        )
            ++bad;
        // the anologic computer - one hundred spells analyzed, a heat core
        // power source (folios 8, 10)
    if (artComputerSpellAnalysis() != 100
            || artComputerHeatCore() != 1
        )
            ++bad;
        // the computer analyzes enemy hit points for a double heat ray, and
        // its program strictness is its weakness (folio 10)
    if (artComputerDoubleHeatRay() != 1
            || artComputerLogicBlind() != 1
        )
            ++bad;
        // the no-save trio confirmed - red, clear, brown (folio 8)
    if (artSphSaveApplicable(0) != 0
            || artSphSaveApplicable(2) != 0
            || artSphSaveApplicable(3) != 0
        )
            ++bad;
        // the smallest tops every cap - seven dice, forty shield, twenty
        // absorber (folio 8)
    if (artHeatRayDice(2) != 7
            || artDamageShield(2) != 40
            || artDamageAbsorber(2) != 20
        )
            ++bad;
        printf("R894 Artificer audit: bad %d\n", bad);
        if (bad) return 1;
    }
