    // ---- R485 WSG artificial illumination pin audit ----
    // The artificial illumination rules: this section supplements the Players
    // Handbook page 102 statistics with facts relevant to the outdoors. The
    // use of an artificial light source in moonlight or darkness lets
    // characters within the illuminated area see with normal vision as if the
    // natural light was twilight (or perhaps daylight, as with a continual
    // light spell), but the light source's specified radius of illumination
    // takes precedence over the Range of Normal Vision Table figures - a
    // torch holder on a clear night sees only his 40-foot radius, even though
    // in actual twilight under a clear sky he would see 300 yards unaided.
    // Torch: both the radius and the burning time are affected by wind
    // velocity - below 10 mph the PHB figures apply; 11-25 mph the flame
    // struggles and flickers, reliable illumination only out to 30 feet
    // instead of 40 and a burn of 4 turns instead of 6; 26-40 mph the radius
    // is not further reduced but the flame lasts only 2 turns at most, with a
    // 25% chance checked every five rounds of being extinguished and needing
    // reignition; above 40 mph it is impossible to keep a torch burning more
    // than 1 round. Lighting a torch takes 1 round plus 1 per 10 mph of wind,
    // halved with fire building proficiency. In moonlight or darkness a
    // lighted torch can be seen from 200 yards. Lantern: much more reliable
    // in the wilderness - the flame protected, no flicker or wind
    // extinguishing, constant radius; regular lantern light is seen from 100
    // yards, a bullseye lanthorn beam from 200 yards if the viewer looks
    // directly back toward the source, or 100 yards if his gaze crosses the
    // beam path. Magic weapons: a smaller illuminated area than torch or
    // lantern, but no fuel and no wind effect; the glow is seen from ten
    // times the radius - 100 feet for a magic dagger, 150 for a magic short
    // sword, 200 for a magic long sword. Campfires: small 80-foot radius,
    // medium 120 feet on all sides, large at least 150 feet (perhaps more if
    // especially large). Any artificial light (including magical) in
    // moonlight or darkness limits long-range visibility for everyone within
    // the illuminated area: the lantern holder cannot make out details beyond
    // his 30-foot radius, but someone at the fringe still sees normally into
    // the darkness ahead, and the DM should track who carries light and where
    // the others stand.
    {
        using namespace rules;
        int bad = 0;
    if (wliTorchRadiusFt() != 40
            || wliTwilightNoLightYards() != 300
            || wliWind1MaxMph() != 10
            || wliWind2MinMph() != 11
            || wliWind2MaxMph() != 25
            || wliTorchWindyRadiusFt() != 30
            || wliTorchBurnTurns() != 6
            || wliTorchWindyBurnTurns() != 4
            || wliWind3MinMph() != 26
            || wliWind3MaxMph() != 40
            || wliTorchGaleBurnTurns() != 2
            || wliExtinguishPct() != 25
            || wliExtinguishCheckRounds() != 5
            || wliWind4MinMph() != 41
            || wliTorchStormMaxRounds() != 1
            || wliLightBaseRounds() != 1
            || wliLightWindStepMph() != 10
            || wliTorchSeenYards() != 200
            || wliLanternSeenYards() != 100
            || wliBullseyeBackYards() != 200
            || wliBullseyeAcrossYards() != 100
            || wliMagicGlowFactor() != 10
            || wliDaggerRadiusFt() != 10
            || wliDaggerGlowFt() != 100
            || wliShortSwordRadiusFt() != 15
            || wliShortSwordGlowFt() != 150
            || wliLongSwordRadiusFt() != 20
            || wliLongSwordGlowFt() != 200
            || wliCampSmallRadiusFt() != 80
            || wliCampMediumRadiusFt() != 120
            || wliCampLargeMinRadiusFt() != 150
            || wliLanternRadiusFt() != 30
            || !wliSupplementsPHB()
            || !wliLightAsTwilight()
            || !wliContinualLightAsDaylight()
            || !wliRadiusTakesPrecedence()
            || !wliTorchWindAffects()
            || !wliWindyFlicker()
            || !wliGaleRadiusHeld()
            || !wliGaleExtinguishRisk()
            || !wliStormImpossible()
            || !wliLightProfHalved()
            || !wliLanternReliable()
            || !wliMagicWeaponSmallerArea()
            || !wliMagicNoFuelNoWind()
            || !wliCampLargeAtLeast()
            || !wliCampfireSeeCamping()
            || !wliLightLimitsLongRange()
            || !wliHolderBlindBeyond()
            || !wliFringeSeesNormally()
            || !wliDMTracksPositions()
        )
            ++bad;
        // the three wind bands are contiguous and ascend from the calm band
    if (wliWind2MinMph() != wliWind1MaxMph() + 1
            || wliWind3MinMph() != wliWind2MaxMph() + 1
            || wliWind4MinMph() != wliWind3MaxMph() + 1
        )
            ++bad;
        // the torch radius and burning time degrade band by band: 40 to 30
        // feet, 6 to 4 to 2 turns
    if (wliTorchWindyRadiusFt() >= wliTorchRadiusFt()
            || wliTorchWindyBurnTurns() >= wliTorchBurnTurns()
            || wliTorchGaleBurnTurns() >= wliTorchWindyBurnTurns()
        )
            ++bad;
        // the gale holds the radius but halves the windy burn time, and the
        // storm allows only 1 round
    if (wliTorchGaleBurnTurns() != 2 * wliTorchStormMaxRounds()
            || wliTorchStormMaxRounds() >= wliTorchGaleBurnTurns()
        )
            ++bad;
        // lighting takes 1 round plus 1 per 10 mph of wind
    if (wliLightBaseRounds() != 1
            || wliLightWindStepMph() != 10
        )
            ++bad;
        // every magic weapon glow is exactly ten times its radius: 100/10,
        // 150/15, 200/20 feet
    if (wliDaggerGlowFt() != wliMagicGlowFactor() * wliDaggerRadiusFt()
            || wliShortSwordGlowFt() != wliMagicGlowFactor() *
            wliShortSwordRadiusFt()
            || wliLongSwordGlowFt() != wliMagicGlowFactor() *
            wliLongSwordRadiusFt()
        )
            ++bad;
        // the campfire radii strictly ascend: 80 under 120 under the 150
        // floor
    if (wliCampSmallRadiusFt() >= wliCampMediumRadiusFt()
            || wliCampMediumRadiusFt() >= wliCampLargeMinRadiusFt()
        )
            ++bad;
        // sighting: the lantern (100) never outsees the torch (200), and the
        // bullseye back-toward (200) doubles the across-beam (100)
    if (wliLanternSeenYards() >= wliTorchSeenYards()
            || wliBullseyeBackYards() != 2 * wliBullseyeAcrossYards()
        )
            ++bad;
        // the clear-night torch radius (40 feet) is the PHB figure the windy
        // band cuts to 30, and real twilight sees 300 yards
    if (wliTorchRadiusFt() != 40
            || wliTwilightNoLightYards() != 300
        )
            ++bad;
        printf("R485 WSG artificial illumination pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
