    // ---- R481 WSG first aid equipment pin audit ----
    // The first aid equipment rules: bandages (several swatches of clean
    // fabric for covering and binding wounds and burns; clothing torn into
    // strips works in a pinch but adventurers clothing is usually not clean,
    // leaving a possibility of infection even when the wound is bandaged),
    // splints (not necessary when traveling through a wooded area, but wise
    // to pack for a mountain climb or a desert crossing: a couple of
    // straight, short 2-3-foot pieces of wood or other rigid material bound
    // along the sides of a broken limb to keep the bones properly aligned; a
    // large piece of thick leather or untanned hide works too, if large and
    // rigid enough to keep the limb and the joints on both sides immobilized,
    // in the same manner as a plaster cast), the stretcher (parts carried
    // separately and assembled when needed: two poles at least as long as the
    // injured character height, sturdy cloth or leather large enough to
    // recline on, and rope or cord of sufficient length to bind the poles to
    // the edges; two comrades can carry the victim as long as each supports
    // half the weight without being too encumbered to move), and the litter
    // (essentially a stretcher plus extra rope or cord to bind the victim to
    // the frame; one character - or one mount or beast of burden - can
    // transport the bound victim, supporting half the weight; unwise over
    // rugged or very rugged terrain because one end always drags on the
    // ground and the victim is jostled as the litter skids and bumps; the DM
    // may rule the trip causes further damage from the rough handling).
    {
        using namespace rules;
        int bad = 0;
    if (wfeEquipmentKindCount() != 4
            || wfeSplintMinFeet() != 2
            || wfeSplintMaxFeet() != 3
            || wfeStretcherPoleCount() != 2
            || wfeStretcherCarriers() != 2
            || wfeLitterCarriers() != 1
            || wfeHalfNum() != 1
            || wfeHalfDen() != 2
            || !wfePartyPacksAidMaterials()
            || !wfeBandagesCleanFabric()
            || !wfeClothingStripsInPinch()
            || !wfeClothingCarriesInfection()
            || !wfeSplintsUnneededInWood()
            || !wfeSplintsPackedForMountainDesert()
            || !wfeLeatherHideAsSplint()
            || !wfeStretcherPartsCarriedSeparately()
            || !wfeStretcherPolesAsTallAsVictim()
            || !wfeStretcherNeedsSurfaceAndBinding()
            || !wfeStretcherTwoCarryHalfEach()
            || !wfeLitterSameAsStretcher()
            || !wfeLitterOneCarrierOrBeast()
            || !wfeLitterUnwiseOnRugged()
            || !wfeLitterDragsAndJostles()
            || !wfeDmMayRuleRoughHandlingDamage()
        )
            ++bad;
        // the four essentials, and the splint length runs 2-3 feet
    if (wfeEquipmentKindCount() != 4
            || wfeSplintMinFeet() != 2
            || wfeSplintMaxFeet() != 3
            || wfeSplintMinFeet() > wfeSplintMaxFeet()
        )
            ++bad;
        // the carry bars: two stretcher carriers, one litter carrier, each at
        // half the weight
    if (wfeStretcherCarriers() != 2
            || wfeLitterCarriers() != 1
            || wfeHalfDen() != 2 * wfeHalfNum()
            || wfeStretcherPoleCount() != 2
        )
            ++bad;
        printf("R481 WSG first aid equipment pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
