    // ---- R596 Indices audit ----
    // INDICES, printed pp. 127-128, the closing pair: the subject index of
    // the whole book on p. 127 - 132 entries from the abjurations and
    // alterations through the Yggdrasil, naming the planes (Astral 5, 60-72;
    // Ethereal 5-21; inner 5, 22-59; outer 5, 73-116; the Prime 5, 117-119;
    // the para-elemental and quasi-elemental 22-59), the rivers (Oceanus 84,
    // 90; the Styx 83, 100-101, 103, 105; Mnemosyne 101 restored from the OCR
    // Manale), the landmarks (Mount Olympus 72, 92, 105; Yggdrasil 72, 95,
    // 105), the creatures (Bahamut and the archons 88, Charon and the
    // charonadaemons 83, the dao and djian and efreet and marids, the
    // githyanki and githzerai with their silver swords 61, 72, 99, the
    // modrons 85, Nidhogg 106, the norns 116, Cerberus 106 restored from the
    // OCR Corberus, the trillochs, the xag-ya and xeg-yi 54, the einheriar
    // 122, the outer-planes creatures 122-123 and the inner 120-121), the
    // mechanics (color pools 80, 82-84; conduits 66, 74; the ether cyclone
    // 17; the psychic wind 64, 67; the silver cord 60-61; wormholes 66;
    // subjective time and true time 5-6; the power compass 75; the borders
    // intercalm, interlayer and interplanar 76); and the spell index of p.
    // 128 - 89 spells with its stated purpose, the pages of unusual or
    // important notes and the exceptions to the spell-type rules: the five
    // airy variants (earth, element, fire, smoke, water), astral projection
    // across its seven pages, plane shift at 11, 22, 61, 74, 117, teleport
    // without error 75, the wish 79 and alter reality 79 and limited wish 79,
    // the negative and positive plane protections 54, the two
    // transform-element spells 28, contact other plane 35, 45, 49, 80, the
    // chariot of Sustarre 29 restored to the real name, stone tell 28
    // restored from the OCR stone tail, and the necromancies restored from
    // the OCR neoromantics.
    {
        using namespace rules;
        int bad = 0;
    if (decIndexPages() != 2
            || decSubjectIndexEntries() != 132
            || decSpellIndexEntries() != 89
            || decAiryVariants() != 5
            || decPlaneShiftRefs() != 5
            || !decSubjectIndex()
            || !decSpellIndexRoster()
            || !decSpellIndexNote()
        )
            ++bad;
        // the IndexPages pin
    if (decIndexPages() != 2
        )
            ++bad;
        // the SubjectIndexEntries pin
    if (decSubjectIndexEntries() != 132
        )
            ++bad;
        // the SpellIndexEntries pin
    if (decSpellIndexEntries() != 89
        )
            ++bad;
        // the AiryVariants pin
    if (decAiryVariants() != 5
        )
            ++bad;
        // the PlaneShiftRefs pin
    if (decPlaneShiftRefs() != 5
        )
            ++bad;
        // the SubjectIndex pin
    if (decSubjectIndex() != 1
        )
            ++bad;
        // the SpellIndexRoster pin
    if (decSpellIndexRoster() != 1
        )
            ++bad;
        // the SpellIndexNote pin
    if (decSpellIndexNote() != 1
        )
            ++bad;
        printf("R596 Indices audit: bad %d\n", bad);
        if (bad) return 1;
    }
