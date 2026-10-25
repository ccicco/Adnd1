    // ---- R593 AppII audit ----
    // APPENDIX II: CREATURES OF THE INNER PLANES, printed pp. 120-121, the
    // elemental analogues: the inner planes natural environments to their
    // inhabitants - elemental herbivores grazing on their surroundings,
    // elemental carnivores preying on elemental (and normative) life, the DM
    // adapting the Monster Manual, Monster Manual II and Fiend Folio stats.
    // The no-analogue list: no Ethereal, Astral or outer-plane natives
    // (slaad, githyanki, devils), no elemental undead (though Prime undead
    // may visit), and none for the PC humanoids - no elemental wizards,
    // though some elemental creatures cast. The stat modifications: movement
    // tripled for Air, Smoke and Steam, doubled for Water; the lair
    // percentage 10% lower in the native plane and 10% higher in elemental
    // pockets elsewhere; AC, attacks, damage, frequency, number appearing,
    // magic resistance, intelligence unchanged, alignment unchanged or
    // neutral with tendencies, no psionics unless noted. The abilities:
    // movement through the home plane and its adjoining para- and
    // quasi-planes as Prime travelers move through the Ethereal, sight into
    // the Border Ethereal, entry to the Ethereal - but no Prime crossing
    // without outside help. The per-element rungs: Air immune to wind,
    // weather, lightning and clouds, hurt by vacuum; Fire hurt by cold and
    // water; Earth with the improved AC and the passwall; Water breathing and
    // blending; Smoke, Magma, Ooze, Ice, Lightning, Radiance, Minerals,
    // Steam, Vacuum, Ash, Dust and Salt each with the immunity and
    // vulnerability as printed - and the fire giant of Ash keeping its
    // immunity, for where the Prime creature's immunity is the analogue's
    // vulnerability, the analogue retains it. The appearances: ninety percent
    // of air creatures invisible, the rest from amorphous clouds to humanoid
    // avians; the Fire die from flaming solids through orbiting 2d6 geometric
    // swarms to the metallic-hide counterparts; Earth from boulders through
    // xorn-like tripeds to crystalline forms that shatter into useless
    // shards; the Water amoeboids, serpents, mer-creatures and fish; the
    // para-elemental humanoids and counterparts with the printed splits; and
    // the eight quasi-forms from the bolt-legged lightning balls to the
    // salt-encrusted duplicates. The size-change table by family with the
    // halving-and-doubling effects (the 15-foot giant's 60-foot equivalent);
    // and the treasure: Air's 10% coinage in perfume, Fire's 20% in melted
    // blocks or protected burnables, Earth's metal-and-gems preference,
    // Water's doubled potions, the 50/50 para-rule, the seven-of-eight
    // quasi-rule with Vacuum normal, the protection by low-intelligence
    // keepers, and the elemental-pocket equivalence.
    {
        using namespace rules;
        int bad = 0;
    if (ddyAirMoveMult() != 3
            || ddyAirInvisiblePct() != 90
            || ddyAirCoinPct() != 10
            || ddyFireCoinPct() != 20
            || ddyParaTreasureChance() != 50
            || !ddyAnalogueDoctrine()
            || !ddyStatModsRule()
            || !ddyElementAbilitiesRule()
            || !ddySizeChangeRule()
            || !ddyFireAppearanceRule()
            || !ddyEarthWaterAppearanceRule()
            || !ddyTreasureRule()
        )
            ++bad;
        // the AirMoveMult pin
    if (ddyAirMoveMult() != 3
        )
            ++bad;
        // the AirInvisiblePct pin
    if (ddyAirInvisiblePct() != 90
        )
            ++bad;
        // the AirCoinPct pin
    if (ddyAirCoinPct() != 10
        )
            ++bad;
        // the FireCoinPct pin
    if (ddyFireCoinPct() != 20
        )
            ++bad;
        // the ParaTreasureChance pin
    if (ddyParaTreasureChance() != 50
        )
            ++bad;
        // the AnalogueDoctrine pin
    if (ddyAnalogueDoctrine() != 1
        )
            ++bad;
        // the StatModsRule pin
    if (ddyStatModsRule() != 1
        )
            ++bad;
        // the ElementAbilitiesRule pin
    if (ddyElementAbilitiesRule() != 1
        )
            ++bad;
        // the SizeChangeRule pin
    if (ddySizeChangeRule() != 1
        )
            ++bad;
        // the FireAppearanceRule pin
    if (ddyFireAppearanceRule() != 1
        )
            ++bad;
        // the EarthWaterAppearanceRule pin
    if (ddyEarthWaterAppearanceRule() != 1
        )
            ++bad;
        // the TreasureRule pin
    if (ddyTreasureRule() != 1
        )
            ++bad;
        printf("R593 AppII audit: bad %d\n", bad);
        if (bad) return 1;
    }
