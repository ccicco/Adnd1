    // ---- R581 Olympus-Gladsheim audit ----
    // OLYMPUS AND GLADSHEIM, printed pp. 92-97, the last two Upper Planes in
    // one round, closing the top of the wheel: Olympus, home of the Greek and
    // elvish pantheons (the three layers - the convex Olympus/Arvandor of
    // mountains and wilderlands, the shallow three-foot seas of Ossa/Aquallor
    // holding the Oceanus outflow, the white-dust Pallon/Mithardir with its
    // buried predecessor realms; the rare barriers opening into the water
    // domains, the spinning crimson-disk portals walled and gated by the
    // Powers, the creature modifications - size up, AC 2 better, claws +2,
    // doubled hit dice, the 1-in-20 casters - all lost outside the plane; the
    // Greek pantheon from Zeus's marble citadel through Aphrodite's quartz,
    // Apollo's sunlight, the bone-and-iron of Ares and Athena, Dionysus's
    // vines, Hermes's den and Poseidon's sea, twice a common front for the
    // titans and the mountain conduit; the elvish Seldarine - Corellon
    // Larethian, Erevan, Solonor, Labelas, Hanali's Evergold shared with
    // yearly-pilgrim Aphrodite, Deep Bashelas, the Leaflord Rillifane, the
    // wandering Aedrie Faenya with her 10d10 birds, Nephthys's lone desert,
    // and the Chosen serving both); and Gladsheim, the Norse plane where
    // reality breaks down (the earthberg rivers arching through space, the
    // radiant-fire undersides and the reddish glow, the layers Asgard,
    // Muspelheim with Surtur's reversed bergs, and the cavern-realmed
    // Nidavellir; the wells at 80% accuracy, the Yggdrasil whose 100-day
    // Prime climb has never been done, the 10-yard Bifrost that strips magic
    // from all but Powers and artifacts, the necromantic cowardice ban in
    // Asgard and Vanaheim, the giant casters at 1-in-4/1-in-10/1-in-20, and
    // the realm census - Mount Joy, Hildskialf, Bilskirnir, Fensalir,
    // Breidablik, Himinbjorg, Ydalir, Landvidi, Gilmir, Loki's bolt-holes,
    // Idun's orchards with Bragi in far Elysium).
    {
        using namespace rules;
        int bad = 0;
    if (ddjOlympusCreatureAcBonus() != 2
            || ddjWellAccuracyPct() != 80
            || ddjBifrostWidthYards() != 10
            || ddjGladsheimTransitDays() != 100
            || ddjGiantIllusionistDiv() != 4
            || !ddjOlympusStructure()
            || !ddjGreekPantheon()
            || !ddjElvishPantheon()
            || !ddjGladsheimStructure()
            || !ddjGladsheimNecroBan()
            || !ddjNorsePantheon()
            || !ddjGladsheimCreatures()
        )
            ++bad;
        // the OlympusCreatureAcBonus pin
    if (ddjOlympusCreatureAcBonus() != 2
        )
            ++bad;
        // the WellAccuracyPct pin
    if (ddjWellAccuracyPct() != 80
        )
            ++bad;
        // the BifrostWidthYards pin
    if (ddjBifrostWidthYards() != 10
        )
            ++bad;
        // the GladsheimTransitDays pin
    if (ddjGladsheimTransitDays() != 100
        )
            ++bad;
        // the GiantIllusionistDiv pin
    if (ddjGiantIllusionistDiv() != 4
        )
            ++bad;
        // the OlympusStructure pin
    if (ddjOlympusStructure() != 1
        )
            ++bad;
        // the GreekPantheon pin
    if (ddjGreekPantheon() != 1
        )
            ++bad;
        // the ElvishPantheon pin
    if (ddjElvishPantheon() != 1
        )
            ++bad;
        // the GladsheimStructure pin
    if (ddjGladsheimStructure() != 1
        )
            ++bad;
        // the GladsheimNecroBan pin
    if (ddjGladsheimNecroBan() != 1
        )
            ++bad;
        // the NorsePantheon pin
    if (ddjNorsePantheon() != 1
        )
            ++bad;
        // the GladsheimCreatures pin
    if (ddjGladsheimCreatures() != 1
        )
            ++bad;
        printf("R581 Olympus-Gladsheim audit: bad %d\n", bad);
        if (bad) return 1;
    }
