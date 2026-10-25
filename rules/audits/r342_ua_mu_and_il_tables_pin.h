    // ---- R342: the UA MU and illusionist tables pin audit ----
    // The UA SPELL TABLES (pp. 30-31), part 2 - the MU
    // 1st-5th columns (35/30/28/28/28 readable names,
    // every garble position-decoded, the alphabetical
    // continuity documented), the MU continued table
    // (6th-9th: 17/16/10/8, the R785 ledger repairs
    // from the archive.org OCR plus the UA-new
    // description rosters and the registry) and the
    // illusionist table (5/4/1, the cantrip column
    // resolved, the 3rd-6th columns resolved on the
    // UA-new side). The R342 ledger holes close; the
    // ledger census pins in rules/spelltableledger.h.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the loss flags
        {
            if (uas2Mu1stCount() != 35) ++bad;
            if (uas2Mu2ndCount() != 30) ++bad;
            if (uas2Mu3rdCount() != 28) ++bad;
            if (uas2Mu4thCount() != 28) ++bad;
            if (uas2Mu5thCount() != 28) ++bad;
            if (uas2Mu6thCount() != 17) ++bad;
            if (uas2Mu7thCount() != 16) ++bad;
            if (uas2Mu8thCount() != 10) ++bad;
            if (uas2Mu9thCount() != 8) ++bad;
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (uas2MuSixthLevelColumnLost()) ++bad;
            if (!uas2MuHighTableNineLost()) ++bad;
            if (uas2IlCantripCount() != 8) ++bad;
        }
        // U2: the MU 1st column (the garble decodes)
        {
            if (strcmp(uas2Mu1stName(0),
                "Affect Normal Fires") != 0) ++bad;
            if (strcmp(uas2Mu1stName(5),
                "Comprehend Languages") != 0) ++bad;
            if (strcmp(uas2Mu1stName(19),
                "Magic Missile") != 0) ++bad;
            // the "Reso Magic" cell = Read Magic
            if (strcmp(uas2Mu1stName(27),
                "Read Magic") != 0) ++bad;
            // the "588985888 Grasp" cell = Shocking Grasp
            if (strcmp(uas2Mu1stName(28),
                "Shocking Grasp") != 0) ++bad;
            // the "From Evil" head-lost tail decode
            if (strcmp(uas2Mu1stName(26),
                "Protection From Evil") != 0) ++bad;
            // the merged Spider/Taunt/Tenser's cell
            if (strcmp(uas2Mu1stName(29),
                "Spider Climb") != 0) ++bad;
            if (strcmp(uas2Mu1stName(30), "Taunt")
                != 0) ++bad;
            if (strcmp(uas2Mu1stName(31),
                "Tenser's Floating Disc") != 0) ++bad;
            // the "Unseen Servan" tail loss
            if (strcmp(uas2Mu1stName(32),
                "Unseen Servant") != 0) ++bad;
            if (strcmp(uas2Mu1stName(34),
                "Wizard Mark") != 0) ++bad;
        }
        // U3: the MU 2nd-5th columns
        {
            // the "Continual Li" tail decode
            if (strcmp(uas2Mu2ndName(2),
                "Continual Light") != 0) ++bad;
            // the merged Detect Evil cell
            if (strcmp(uas2Mu2ndName(4),
                "Detect Evil") != 0) ++bad;
            // the "Meif's" garble
            if (strcmp(uas2Mu2ndName(16),
                "Melf's Acid Arrow") != 0) ++bad;
            // the "Whip" cell - verbatim, identity
            // pending the PDF
            if (strcmp(uas2Mu2ndName(27), "Whip")
                != 0) ++bad;
            if (strcmp(uas2Mu2ndName(29), "Zephyr")
                != 0) ++bad;
            // the "Runes" cell = Explosive Runes
            if (strcmp(uas2Mu3rdName(4),
                "Explosive Runes") != 0) ++bad;
            // the "Tiny Hut" decode
            if (strcmp(uas2Mu3rdName(14),
                "Leomund's Tiny Hut") != 0) ++bad;
            // the "Bolt" cell = Lightning Bolt
            if (strcmp(uas2Mu3rdName(15),
                "Lightning Bolt") != 0) ++bad;
            // the numeral-less print, verbatim
            if (strcmp(uas2Mu3rdName(17),
                "Monster Summoning") != 0) ++bad;
            // the Secret Page print sits in the 3rd
            // column (the PHB reads 2nd) - as printed
            if (strcmp(uas2Mu3rdName(21),
                "Secret Page") != 0) ++bad;
            // the "Dis oor" cell = Dimension Door
            if (strcmp(uas2Mu4thName(3),
                "Dimension Door") != 0) ++bad;
            // the "Ice" cell = Ice Storm (seam-proven)
            if (strcmp(uas2Mu4thName(11),
                "Ice Storm") != 0) ++bad;
            // the Secure/Shelter split decode
            if (strcmp(uas2Mu4thName(12),
                "Leomund's Secure Shelter") != 0) ++bad;
            // the "Fics 2 LA Terrain" cell
            if (strcmp(uas2Mu4thName(10),
                "Hallucinatory Terrain") != 0) ++bad;
            // the "Otiluke's Resilient"/"ere" split
            if (strcmp(uas2Mu4thName(16),
                "Otiluke's Resilient Sphere") != 0) ++bad;
            // the "Extension Il" pair decode
            if (strcmp(uas2Mu5thName(10),
                "Extension II") != 0) ++bad;
            // the three-name merged cell
            if (strcmp(uas2Mu5thName(14),
                "Leomund's Lamentable Belabourment")
                != 0) ++bad;
            if (strcmp(uas2Mu5thName(15),
                "Leomund's Secret Chest") != 0) ++bad;
            if (strcmp(uas2Mu5thName(16),
                "Magic Jar") != 0) ++bad;
            // the "Monster Summoning Ili" decode
            if (strcmp(uas2Mu5thName(17),
                "Monster Summoning III") != 0) ++bad;
            // the word-order scrambles
            if (strcmp(uas2Mu5thName(26),
                "Wall of Iron") != 0) ++bad;
            if (strcmp(uas2Mu5thName(27),
                "Wall of Stone") != 0) ++bad;
            // the Stone Shape print sits in the 5th
            // column (the PHB reads 4th) - as printed
            if (strcmp(uas2Mu5thName(21),
                "Stone Shape") != 0) ++bad;
        }
        // U4: the MU continued table (6th-9th; the
        // R785 repaired rosters)
        {
            // the 6th-column walk (the readable cells)
            if (strcmp(uas2Mu6thName(1),
                "Contingency") != 0) ++bad;
            // the "ntingency" fragment read
            if (strcmp(uas2Mu6thName(2),
                "Control Weather") != 0) ++bad;
            if (strcmp(uas2Mu6thName(3),
                "Death Spell") != 0) ++bad;
            if (strcmp(uas2Mu6thName(4),
                "Disintegrate") != 0) ++bad;
            if (strcmp(uas2Mu6thName(11),
                "Otiluke's Freezing Sphere") != 0) ++bad;
            // the "Project Im" fragment read
            if (strcmp(uas2Mu6thName(13),
                "Project Image") != 0) ++bad;
            // the "To Flesh" bleed cell re-seats
            if (strcmp(uas2Mu6thName(14),
                "Stone To Flesh") != 0) ++bad;
            if (strcmp(uas2Mu6thName(15),
                "Tenser's Transformation") != 0) ++bad;
            if (strcmp(uas2Mu6thName(16),
                "Transmute Water To Dust") != 0) ++bad;
            // the 7th walk (the repaired roster)
            if (strcmp(uas2Mu7thName(0),
                "Banishment") != 0) ++bad;
            // the merged Drawmij's cell head repairs
            if (strcmp(uas2Mu7thName(3),
                "Drawmij's Instant Summons") != 0) ++bad;
            // the numeral-less print repairs
            if (strcmp(uas2Mu7thName(7),
                "Monster Summoning V") != 0) ++bad;
            if (strcmp(uas2Mu7thName(6),
                "Limited Wish") != 0) ++bad;
            // the "Gravity" tail = Reverse Gravity
            if (strcmp(uas2Mu7thName(9),
                "Reverse Gravity") != 0) ++bad;
            // the 8th walk (Binding, Clone and the
            // telekinetic sphere newly read; the
            // Glassteel and Power Word Kill holes
            // stay open)
            if (strcmp(uas2Mu8thName(0),
                "Binding") != 0) ++bad;
            if (strcmp(uas2Mu8thName(1),
                "Clone") != 0) ++bad;
            // the "Il Demand" cell = Demand
            if (strcmp(uas2Mu8thName(2), "Demand")
                != 0) ++bad;
            // the "Otiluke's" tail newly reads
            if (strcmp(uas2Mu8thName(6),
                "Otiluke's Telekinetic Sphere") != 0) ++bad;
            if (strcmp(uas2Mu8thName(7),
                "Power Word Blind") != 0) ++bad;
            // the 9th walk (the repaired roster; the
            // "th Level" print stands)
            if (strcmp(uas2Mu9thName(0),
                "Crystalbrittle") != 0) ++bad;
            if (strcmp(uas2Mu9thName(2), "Gate")
                != 0) ++bad;
            if (strcmp(uas2Mu9thName(3),
                "Mordenkainen's Disjunction") != 0) ++bad;
            // the merged Shape Change/Sphere cell
            if (strcmp(uas2Mu9thName(4),
                "Prismatic Sphere") != 0) ++bad;
            if (strcmp(uas2Mu9thName(5),
                "Shape Change") != 0) ++bad;
            if (strcmp(uas2Mu9thName(6),
                "Succor") != 0) ++bad;
            // the registry row reads back
            if (strcmp(uas2Mu9thName(7), "Wish")
                != 0) ++bad;
        }
        // U5: the illusionist table
        {
            if (strcmp(uas2Il1stName(0),
                "Color Spray") != 0) ++bad;
            if (strcmp(uas2Il1stName(4),
                "Phantasmal Force") != 0) ++bad;
            // the "Hallucin: Terrain" fragment decode
            if (strcmp(uas2Il2ndName(1),
                "Hallucinatory Terrain") != 0) ++bad;
            // the "Phantom Wind Mirror" tail decode
            if (strcmp(uas2Il2ndName(3),
                "Mirror Image") != 0) ++bad;
            if (strcmp(uas2Il7thName(0),
                "Shadow Walk") != 0) ++bad;
        }
        // U6: the R80/R229 registry seam (live)
        {
            auto reglvl = [](const char* n,
                spells::SpellClass c) -> int {
                for (int id = 0;
                     id < spells::SPELL_COUNT; ++id) {
                    const spells::SpellDef& d =
                        spells::spell(
                            (spells::SpellId)id);
                    if (d.sclass == c
                        && strcmp(d.name, n) == 0)
                        return d.level;
                }
                return -1;
            };
            using spells::SPELL_MU;
            using spells::SPELL_ILLUSIONIST;
            // the 1st-5th columns verify
            if (reglvl("Magic Missile",
                SPELL_MU) != 1) ++bad;
            if (reglvl("Charm Person",
                SPELL_MU) != 1) ++bad;
            if (reglvl("Invisibility",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Mirror Image",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Strength",
                SPELL_MU) != 2) ++bad;
            if (reglvl("Fireball",
                SPELL_MU) != 3) ++bad;
            if (reglvl("Lightning Bolt",
                SPELL_MU) != 3) ++bad;
            if (reglvl("Dispel Magic",
                SPELL_MU) != 3) ++bad;
            // the "Ice" decode seam-proven
            if (reglvl("Ice Storm",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Charm Monster",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Polymorph Other",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Fire Shield",
                SPELL_MU) != 4) ++bad;
            if (reglvl("Cone of Cold",
                SPELL_MU) != 5) ++bad;
            if (reglvl("Teleport",
                SPELL_MU) != 5) ++bad;
            if (reglvl("Hold Monster",
                SPELL_MU) != 5) ++bad;
            // the 6th-column proof rows
            if (reglvl("Death Spell",
                SPELL_MU) != 6) ++bad;
            if (reglvl("Disintegrate",
                SPELL_MU) != 6) ++bad;
            // the lost 7th/9th registry rows
            if (reglvl("Limited Wish",
                SPELL_MU) != 7) ++bad;
            if (reglvl("Wish",
                SPELL_MU) != 9) ++bad;
            // the illusionist 2nd column verifies
            if (reglvl("Dispel Illusion",
                SPELL_ILLUSIONIST) != 2) ++bad;
            if (reglvl("Magic Mouth",
                SPELL_ILLUSIONIST) != 2) ++bad;
            // the "Hallucin: Terrain" decode seam
            if (reglvl("Hallucinatory Terrain",
                SPELL_ILLUSIONIST) != 2) ++bad;
            // the "Mirror" fragment decode seam
            if (reglvl("Mirror Image",
                SPELL_ILLUSIONIST) != 2) ++bad;
        }
        printf("R342 UA MU and IL tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
