    // ---- R538 DSG Deepearth areas 10-11 audit ----
    // The DSG Deepearth areas 10-11 pin Area 10 (the Sunken Swamp with its
    // quake-fallen chambers, the degenerated cannibal tribes, the sacred
    // temple and the petrified cavern) and Area 11 (the illithid outpost with
    // its four side caves, the pillar-roofed central cavern and the secret
    // treasure trove).
    {
        using namespace rules;
        int bad = 0;
    if (dnagChamberMinCount() != 12
            || dnagChamberWidthLowFt() != 1000
            || dnagChamberWidthHighFt() != 4000
            || dnagChamberLenDice() != 3
            || dnagChamberLenSides() != 6
            || dnagTunnelLinkMin() != 2
            || dnagPopLow() != 50
            || dnagPopHigh() != 100
            || dnagSideCaveCount() != 4
            || dnagSideCaveMaxWidthFt() != 50
            || dnagSideCeilMaxFt() != 20
            || dnagSideCeilTypicalFt() != 6
            || dnagSideCaveLenMiles() != 1
            || dnagCentralDiaMiles() != 1
            || dnagCentralCeilFt() != 100
            || dnagPillarCount() != 6
            || dnagIllithidCount() != 25
            || dnagStreamCount() != 4
            || dnagGuardCount() != 4
            || !dnagQuakeOrigin()
            || !dnagLandFell()
            || !dnagDirtLined()
            || !dnagShoredTunnels()
            || !dnagDegenerated()
            || !dnagPrimitiveSpeech()
            || !dnagSavageWars()
            || !dnagSwampFauna()
            || !dnagMistyResources()
            || !dnagPeatFires()
            || !dnagSacredTemple()
            || !dnagSacredArmory()
            || !dnagPetrifiedCavern()
            || !dnagLivingCaves()
            || !dnagIllithidScouts()
            || !dnagOutpostScavengers()
            || !dnagDwarvenHuts()
            || !dnagSecretTreasure()
        )
            ++bad;
        // the Sunken Swamp chambers: more than a dozen, 1,000 to 4,000 feet
        // wide, 3d6 miles long.
    if (dnagChamberMinCount() != 12
            || dnagChamberWidthLowFt() != 1000
            || dnagChamberWidthHighFt() != 4000
            || dnagChamberLenDice() != 3
            || dnagChamberLenSides() != 6
        )
            ++bad;
        // the survivors' works and numbers: tunnels linking each cavern to at
        // least two others, the 50-to-100-strong cavern populations.
    if (dnagTunnelLinkMin() != 2
            || dnagPopLow() != 50
            || dnagPopHigh() != 100
        )
            ++bad;
        // the outpost side caverns: four of them, never wider than 50 feet,
        // ceilings to 20 feet but often 6 or less, each about a mile long.
    if (dnagSideCaveCount() != 4
            || dnagSideCaveMaxWidthFt() != 50
            || dnagSideCeilMaxFt() != 20
            || dnagSideCeilTypicalFt() != 6
            || dnagSideCaveLenMiles() != 1
        )
            ++bad;
        // the central cave: nearly a mile across, ceiling over 100 feet, six
        // pillars, four converging streams.
    if (dnagCentralDiaMiles() != 1
            || dnagCentralCeilFt() != 100
            || dnagPillarCount() != 6
            || dnagStreamCount() != 4
        )
            ++bad;
        // the mind flayers: about 25 in the central cavern, a single guard on
        // each of the four entry caves.
    if (dnagIllithidCount() != 25
            || dnagGuardCount() != 4
        )
            ++bad;
        printf("R538 DSG Deepearth areas 10-11 audit: bad %d\n", bad);
        if (bad) return 1;
    }
