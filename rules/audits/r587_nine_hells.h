    // ---- R587 Nine Hells audit ----
    // THE NINE HELLS, printed pp. 109-113, the plane of evil organized to
    // further its own malefic ends: nine infinite layers, the barriers at the
    // lowest point of the upper and half a mile above the next below (the
    // flightless falling the 20d6 cap into spectacular attention), the
    // physical laws constant within each layer but changing between them. The
    // layers: Avernus the front parlor, dark red starless sky, flammable
    // vapor gathered in dimly glowing spheres bursting into fireballs at
    // 1-in-6 per turn (1-in-12 without open flame), Tiamat the watchdog and
    // her astrally-projecting crags; Dis the Iron City of Dispater, its
    // stone-and-lead sanctum beyond the barriers, green-overcast lightning
    // skies; Minauros Mammon's stinking sinking city at 13% disease per
    // visit, its barrier to Dis 30 feet above the palace roofs; Phlegethos
    // the liquefied-fire realm of Belial and Abriymoch, the Mount of Leaping
    // Flames; Stygia the frozen sea of the diluted Styx, the three-mile ice
    // pack over the limitless ocean, Geryon's Tantlin lit by dancing
    // lightning and 2d6 walls of cold fire; Malbolge the rockfall of Moloch
    // the viceroy, copper-shod fortresses under blood-red steam; Maladomini
    // of Baalzebul, quarries and lava aqueducts, Malagard the thousand-mile
    // million-room palace over a dungeon vaster than the devils know; Caina
    // at -60 degrees under Mephistopheles; and Nessus, the vast rifts
    // descending to Asmodeus's palace, dwarfing the Khin-Oin, on the banks of
    // the shifting ice lake fed by the Lethe - extremes of cold, heat and
    // cliff, triple-strength waves of fire turning all to ash. The paths: the
    // Styx through Avernus into Stygia, the Lethe of Nessus (black waters as
    // the Styx but Charon never there), the identical reddish-hoop portals of
    // Avernus to Acheron, Gehenna and Concordant Opposition guarded by
    // Tiamat's abishai and traps, the many Prime conduits whose squabbling
    // dooms evil's plans, and the rumored pre-overlord conduit in the
    // palace's heart that destroys all evil that touches it - the reason the
    // stories say the best escape from the Hells is to journey to the lowest
    // layer. The devils: the rigid caste, the MM2 layer frequencies, the
    // home-layer immunity (the Caina ice devil cold-immune only in Caina),
    // the arch-devils as lesser gods of their home planes whose lust to rule
    // in Hell outweighs defeating good. The politics: Asmodeus of layers 1, 5
    // and 9 with Geryon and Tiamat; Baalzebul of 4, 6 and 7 with Moloch and
    // the recruited Belial; Mephistopheles the reasonable with Dispater and
    // Mammon of 2, 3 and 8 - the overlord weakest-seeming yet supreme,
    // playing faction against faction, holding both ends of the Hells through
    // the underrated Tiamat. And the other Powers: Druaga tolerated on Dis's
    // layer; Set's blazing bone-dry swath of Avernus and his pyramid of
    // captive labor between the Hells and Acheron; Hecate and Inanna adjacent
    // in Phlegethos, the organized punisher and the fickle belligerent, both
    // courts called on by Belial and both dreaded by Asmodeus; Sekolah
    // beneath Stygia's ice devouring Geryon's ambassadors; Kurtulmak robbing
    // his suitors blind; No Cha the nocturnal thief forever moving; and the
    // false-name devils - the devil Dagon and the devil Nergal - muddling who
    // rules the lower planes, as Titivilus tells it: Nergal lives in the
    // Hells, outcast, hides in Avernus, looks like a toad, poor thing.
    {
        using namespace rules;
        int bad = 0;
    if (ddpHellsLayerCount() != 9
            || ddpAvernusFireballChance() != 6
            || ddpMinaurosDiseasePct() != 13
            || ddpStygiaIceMiles() != 3
            || ddpMalagardMiles() != 1000
            || ddpCainaCold() != 60
            || !ddpHellsDoctrine()
            || !ddpNineLayersRule()
            || !ddpHellsPortals()
            || !ddpDevilRule()
            || !ddpArchdevilPolitics()
            || !ddpHellsPowers()
        )
            ++bad;
        // the HellsLayerCount pin
    if (ddpHellsLayerCount() != 9
        )
            ++bad;
        // the AvernusFireballChance pin
    if (ddpAvernusFireballChance() != 6
        )
            ++bad;
        // the MinaurosDiseasePct pin
    if (ddpMinaurosDiseasePct() != 13
        )
            ++bad;
        // the StygiaIceMiles pin
    if (ddpStygiaIceMiles() != 3
        )
            ++bad;
        // the MalagardMiles pin
    if (ddpMalagardMiles() != 1000
        )
            ++bad;
        // the CainaCold pin
    if (ddpCainaCold() != 60
        )
            ++bad;
        // the HellsDoctrine pin
    if (ddpHellsDoctrine() != 1
        )
            ++bad;
        // the NineLayersRule pin
    if (ddpNineLayersRule() != 1
        )
            ++bad;
        // the HellsPortals pin
    if (ddpHellsPortals() != 1
        )
            ++bad;
        // the DevilRule pin
    if (ddpDevilRule() != 1
        )
            ++bad;
        // the ArchdevilPolitics pin
    if (ddpArchdevilPolitics() != 1
        )
            ++bad;
        // the HellsPowers pin
    if (ddpHellsPowers() != 1
        )
            ++bad;
        printf("R587 Nine Hells audit: bad %d\n", bad);
        if (bad) return 1;
    }
