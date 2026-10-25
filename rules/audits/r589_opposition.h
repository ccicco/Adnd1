    // ---- R589 Opposition audit ----
    // CONCORDANT OPPOSITION, printed pp. 114-116, the exception plane: true
    // neutral if aligned at all, connecting every outer plane and the Astral,
    // mixing all their properties - limitless yet with a definite center,
    // moment-to-moment change like chaos yet the same order and placement,
    // good and evil coexisting with their effects on each other reduced. It
    // presents a different face each visit (a gothic city, an aquatic
    // wonderland, a forest of hollow trees) yet the familiar still find their
    // way, the special locations constant; the first visit always a
    // much-larger version of the traveler's homeland - the farm boy in acres
    // of farms, the scribe in a massive library, the modern guide among more
    // interlocking wheels than busy Nirvana. The minimum-damage rule:
    // random-damage weapons and spells inflict the least possible (the short
    // sword 1, the two-handed broadsword 3, cure light wounds 1, the heal all
    // but 1), poisons and strength and magic bonuses unaffected, true
    // throughout the plane. The center: a tower, column, mountain,
    // waterspout, tornado, or tree, unclimbable, unenterable, undamageable by
    // any means godly or not - and the neutralization ladder, one spell level
    // per 100 miles inward from the 9th at 1,000 miles to the 1st at 200,
    // with the specials: illusions failing as gems of seeing at 700 and
    // life-draining dying; astral portals and artificial poisons at 600;
    // natural poisons and the conduits' reach at 500; conjuration, summoning,
    // and the demi-gods' powers at 400; the lesser gods' at 300; the greater
    // gods' at 200; and at 100 the chemical reactions stop, neither man nor
    // god a step closer. The Powers' common ground: the central region as
    // meeting place and trade-market, the differing-alignment Greater Powers
    // conferring at 200 miles without fear of advantage. The ways in: the
    // color pools landing beyond 600 miles, and the great ring of white disks
    // at the 1,000-mile mark - simple disks laid into any ground,
    // party-sized, destination by concentration, majority rules, and the
    // chaotic (alone or in majority) sometimes wrong: 1-80 the intended
    // plane, 81-90 one step around the wheel, 91-00 the opposite location (do
    // you remember the smell of brimstone the last time we were in Olympus?).
    // The features: no native races, all the outer planes' intelligentsia at
    // home frequencies - demons, devils, Anu's warriors, weapon-seeking
    // spirit legions, einherjar, planetars, devas, slaadi; the Powers who
    // reject the wheel - true neutrals, exiles, and the above-alignment -
    // coloring the plane's face to their sensibilities, keeping domains
    // outside the ring, and seeking the center when overmatched. The census:
    // Dagda's Celtic swath of Tir na Og with Mag Mell, Brigit, Diancocht,
    // Dunatis, Lugh, Morrigan, Nuada and Silvanus; Manannan mac Lir's Tir fo
    // Thuiran under the waves; Goibhniu's weapons that work only in the Land
    // of Youth; Ogma's near-center prison where devils and demons are
    // negated; Thoth and Bes with their unoverlapping portfolios and separate
    // households; Untamo's Sleeping Lands beside clattering Tvashtri and his
    // discovery-first inventions; the Modrons' well of souls at the very edge
    // of the center, an unattainable Yggdrasil where men and Powers seek
    // their fortunes from the fates; Yen-Wang-Yeh the Chinese sorter of the
    // dead, one week a year before the August Personage of Jade while his
    // assistant misplaces the wandering spirits; Semuanya's swamp beside
    // Eadro's sea of locathah and mermen; Sheela Peryroyal's orchard;
    // Dumathoin's realm reaching near the center; and Vergadain the dwarven
    // luck-god, suspiciously similar to Bes, both denying they are one Power.
    {
        using namespace rules;
        int bad = 0;
    if (ddsCenterSpellStepMiles() != 100
            || ddsCenterChemicalFloorMiles() != 100
            || ddsChaosDestIntendedPct() != 80
            || ddsChaosDestAdjacentPct() != 90
            || ddsChaosDestOppositePct() != 100
            || ddsPortalRingMiles() != 1000
            || !ddsOppositionDoctrine()
            || !ddsMinDamageRule()
            || !ddsCenterRule()
            || !ddsDiskRule()
            || !ddsOppositionInhabitants()
            || !ddsOppositionPowers()
        )
            ++bad;
        // the CenterSpellStepMiles pin
    if (ddsCenterSpellStepMiles() != 100
        )
            ++bad;
        // the CenterChemicalFloorMiles pin
    if (ddsCenterChemicalFloorMiles() != 100
        )
            ++bad;
        // the ChaosDestIntendedPct pin
    if (ddsChaosDestIntendedPct() != 80
        )
            ++bad;
        // the ChaosDestAdjacentPct pin
    if (ddsChaosDestAdjacentPct() != 90
        )
            ++bad;
        // the ChaosDestOppositePct pin
    if (ddsChaosDestOppositePct() != 100
        )
            ++bad;
        // the PortalRingMiles pin
    if (ddsPortalRingMiles() != 1000
        )
            ++bad;
        // the OppositionDoctrine pin
    if (ddsOppositionDoctrine() != 1
        )
            ++bad;
        // the MinDamageRule pin
    if (ddsMinDamageRule() != 1
        )
            ++bad;
        // the CenterRule pin
    if (ddsCenterRule() != 1
        )
            ++bad;
        // the DiskRule pin
    if (ddsDiskRule() != 1
        )
            ++bad;
        // the OppositionInhabitants pin
    if (ddsOppositionInhabitants() != 1
        )
            ++bad;
        // the OppositionPowers pin
    if (ddsOppositionPowers() != 1
        )
            ++bad;
        printf("R589 Opposition audit: bad %d\n", bad);
        if (bad) return 1;
    }
