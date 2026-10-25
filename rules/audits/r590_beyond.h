    // ---- R590 Beyond audit ----
    // BEYOND THE OUTER PLANES, printed p. 116, the closing essay of the
    // Manual of the Planes: the preceding pages a summary of the known
    // realms, layers and planes - by no means the final word, for the nature
    // of these infinite realms defies any all-encompassing treatise. There
    // can be any number of realms in a layer, so a third or fourth major
    // pantheon can exist in Olympus/Arvandor, or a DM-created evil power can
    // dominate a section of the Nine Hells where no arch-devils rule. Further
    // layers may lie beyond those discovered: an eighth heaven, a third
    // paradise unreachable by known spells and abilities, and Gladsheim
    // perhaps with as many layers as the Abyss but without the Abyssal method
    // of reaching them. The conception of the planes has grown with the AD&D
    // game - the original inner planes with no mention of the quasi- and
    // para-elemental planes, the early outer-plane discussions leaving out
    // Concordant Opposition - and more such planes may exist beyond the scope
    // of the model. There may also be a different form of Astral space
    // between the outer planes and planes farther out, or within the center
    // of Concordant Opposition. Even without new planes, the wild unexplored
    // known lands suffice for years: the Ethereal's floating demi-planes may
    // be world-sized, finite where the others are infinite, and the alternate
    // Prime Material planes run Earth-like or not-so-Earth-like, familiar,
    // hostile, and strange - the only limitation to planar adventures the
    // imagination of those involved, the tome's purpose to fire the
    // imaginations of DMs and players toward the myriad planes of the AD&D
    // system.
    {
        using namespace rules;
        int bad = 0;
    if (!ddtBeyondDoctrine()
            || !ddtUndiscoveredLayers()
            || !ddtGrowingModel()
            || !ddtNewAstralForms()
            || !ddtDemiPlaneRule()
            || !ddtAlternatePrimeRule()
        )
            ++bad;
        // the BeyondDoctrine pin
    if (ddtBeyondDoctrine() != 1
        )
            ++bad;
        // the UndiscoveredLayers pin
    if (ddtUndiscoveredLayers() != 1
        )
            ++bad;
        // the GrowingModel pin
    if (ddtGrowingModel() != 1
        )
            ++bad;
        // the NewAstralForms pin
    if (ddtNewAstralForms() != 1
        )
            ++bad;
        // the DemiPlaneRule pin
    if (ddtDemiPlaneRule() != 1
        )
            ++bad;
        // the AlternatePrimeRule pin
    if (ddtAlternatePrimeRule() != 1
        )
            ++bad;
        printf("R590 Beyond audit: bad %d\n", bad);
        if (bad) return 1;
    }
