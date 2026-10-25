    // ---- R591 Outer seal audit ----
    // THE OUTER PLANES CHAPTER SEAL, printed pp. 73-116: the parent box
    // closes on the census of its children. The seventeen named planes in
    // their wheel order - Nirvana, Arcadia, the Seven Heavens, the Twin
    // Paradises, Elysium, the Happy Hunting Grounds, Olympus and Gladsheim on
    // the lawful-good arc; Limbo and Pandemonium in chaos; the Abyss,
    // Tarterus and Hades in the evil middle; Gehenna, the Nine Hells and
    // Acheron on the lawful-evil slope; and the Concordant Opposition at the
    // hub, the seventeenth touching all. The chapter's rounds: the general
    // doctrine of R577 with the plane-shift arrival table, the
    // alteration-spells chaos table, the turning-undead alignment modifiers,
    // the unique-powers 2-or-20 rule and the human-travelers doctrine; the
    // plane rounds R578 through R589 - Nirvana and Arcadia together, the
    // Seven Heavens with the Twin Paradises, Elysium with the Happy Hunting
    // Grounds, Olympus with Gladsheim closing the Upper Planes, Limbo with
    // Pandemonium opening the Chaos side, the Abyss alone, Tarterus, Hades,
    // Gehenna, the Nine Hells, Acheron, and the Concordant Opposition with
    // its center and destination tables - the Beastlands casting table
    // reattributed by amendment; and the closing essay of R590. Every child
    // box flipped; the wheel sealed.
    {
        using namespace rules;
        int bad = 0;
    if (dduOuterPlaneCount() != 17
            || !dduWheelOrder()
            || !dduChapterSeal()
        )
            ++bad;
        // the OuterPlaneCount pin
    if (dduOuterPlaneCount() != 17
        )
            ++bad;
        // the WheelOrder pin
    if (dduWheelOrder() != 1
        )
            ++bad;
        // the ChapterSeal pin
    if (dduChapterSeal() != 1
        )
            ++bad;
        printf("R591 Outer seal audit: bad %d\n", bad);
        if (bad) return 1;
    }
