    // ---- R151: Appendix O encumbrance audit -----------------------------
    // The DMG p.225 Appendix O weight list, pinned row by
    // row in dm/appendixo.h: the 64 printed items - 57
    // exact rows, the 7 printed ranges (the four chests,
    // gem, small jewelry, tapestry) both ends, the
    // tapestry open tail, the 1500 g.p. (150#) carry max
    // and the four exemption wordings. Seven
    // representative name wordings are pinned too. The
    // caller is items::encumbranceBand (PHB p.38); this
    // is its printed per-item source.
    {
        int bad = 0;
        namespace AO = dm::appendixo;
        if (AO::GR_COUNT != 64 || AO::EX_COUNT != 4 ||
            AO::MAX_CARRY_GP != 1500) ++bad;
        // all 64 rows: lo and hi pinned, the name
        // non-empty, printed order kept
        static const struct { int lo, hi; AO::Gear g; }
            kGR[] = {
            {   20,   20, AO::GR_BACKPACK },
            {    3,    3, AO::GR_BELT },
            {   10,   10, AO::GR_BELT_POUCH_LARGE },
            {    5,    5, AO::GR_BELT_POUCH_SMALL },
            {  200,  200, AO::GR_BOOK_LARGE_METAL_BOUND },
            {   60,   60, AO::GR_BOOTS_HARD },
            {   30,   30, AO::GR_BOOTS_SOFT },
            {   60,   60, AO::GR_BOTTLES_FLAGONS },
            {   80,   80, AO::GR_BOW_COMPOSITE_LONG },
            {   50,   50, AO::GR_BOW_COMPOSITE_SHORT },
            {  100,  100, AO::GR_BOW_LONG },
            {   50,   50, AO::GR_BOW_SHORT },
            {   50,   50, AO::GR_CALTROP },
            {    5,    5, AO::GR_CANDLE },
            { 1000, 5000, AO::GR_CHEST_LARGE_SOLID_IRON },
            {  200,  500, AO::GR_CHEST_SMALL_SOLID_IRON },
            {  100,  250, AO::GR_CHEST_SMALL_WOODEN },
            {  500, 1500, AO::GR_CHEST_LARGE_WOODEN },
            {   30,   30, AO::GR_CLOTHES_ONE_SET },
            {    2,    2, AO::GR_CORD_10FT },
            {   80,   80, AO::GR_CROSSBOW_HEAVY },
            {   50,   50, AO::GR_CROSSBOW_LIGHT },
            {  150,  150, AO::GR_CRYSTAL_BALL },
            {    7,    7, AO::GR_FLASK_EMPTY },
            {   20,   20, AO::GR_FLASK_FULL },
            {    1,    5, AO::GR_GEM },
            {  100,  100, AO::GR_GRAPNEL },
            {   10,   10, AO::GR_HAND_TOOL },
            {   45,   45, AO::GR_HELM },
            {  100,  100, AO::GR_HELM_GREAT },
            {   25,   25, AO::GR_HOLY_WATER_BOTTLE },
            {   50,   50, AO::GR_HORN },
            {   50,   50, AO::GR_JEWELRY_LARGE },
            {    1,    5, AO::GR_JEWELRY_SMALL },
            {   60,   60, AO::GR_LANTERN },
            {    5,    5, AO::GR_MIRROR },
            {  350,  350, AO::GR_MUSICAL_INSTRUMENT },
            {  100,  100, AO::GR_POLE_10FT },
            {    1,    1, AO::GR_PURSE },
            {   30,   30, AO::GR_QUIVER },
            {   75,   75, AO::GR_RATIONS_IRON },
            {  200,  200, AO::GR_RATIONS_STANDARD },
            {   50,   50, AO::GR_ROBE_FOLDED },
            {   25,   25, AO::GR_ROBE_WORN },
            {   60,   60, AO::GR_ROD },
            {   75,   75, AO::GR_ROPE_50FT },
            {   20,   20, AO::GR_SACK_LARGE },
            {    5,    5, AO::GR_SACK_SMALL },
            {  250,  250, AO::GR_SADDLE_LIGHT_HORSE },
            {  500,  500, AO::GR_SADDLE_HEAVY_HORSE },
            {  150,  150, AO::GR_SADDLEBAG },
            {   20,   20, AO::GR_SADDLE_BLANKET },
            {   50,   50, AO::GR_SCROLL_CASE_BONE_IVORY },
            {   25,   25, AO::GR_SCROLL_CASE_LEATHER },
            {   10,   10, AO::GR_SPIKE },
            {  100,  100, AO::GR_STAFF },
            {   50, 1000, AO::GR_TAPESTRY },
            {    2,    2, AO::GR_TINDERBOX },
            {   25,   25, AO::GR_TORCH },
            {   60,   60, AO::GR_WAND_BONE_IVORY_CASE },
            {   80,   80, AO::GR_WAND_BOX },
            {   30,   30, AO::GR_WAND_LEATHER_CASE },
            {    5,    5, AO::GR_WATERSKIN_EMPTY },
            {   50,   50, AO::GR_WATERSKIN_FULL },
        };
        for (size_t i = 0; i < sizeof(kGR)/sizeof(kGR[0]); ++i) {
            if (AO::lo(kGR[i].g) != kGR[i].lo) ++bad;
            if (AO::hi(kGR[i].g) != kGR[i].hi) ++bad;
            if (std::string(AO::name(kGR[i].g)).empty()) ++bad;
        }
        // the open tail: tapestry alone
        for (int g = 0; g < AO::GR_COUNT; ++g) {
            if (AO::openEnded((AO::Gear)g) !=
                (g == (int)AO::GR_TAPESTRY)) ++bad;
        }
        // 7 representative name wordings (the
        // sub-row, footnote, wrapping, pad and ft
        // spellings pinned as printed)
        if (std::string(AO::name(AO::GR_BELT_POUCH_SMALL)) !=
            "Belt pouch, small") ++bad;
        if (std::string(AO::name(AO::GR_BOOK_LARGE_METAL_BOUND)) !=
            "Book, large metal-bound") ++bad;
        if (std::string(AO::name(AO::GR_CRYSTAL_BALL)) !=
            "Crystal ball, base and wrapping") ++bad;
        if (std::string(AO::name(AO::GR_MUSICAL_INSTRUMENT)) !=
            "Musical instrument") ++bad;
        if (std::string(AO::name(AO::GR_SADDLE_BLANKET)) !=
            "Saddle blanket (pad)") ++bad;
        if (std::string(AO::name(AO::GR_CORD_10FT)) !=
            "Cord, 10 ft.") ++bad;
        if (std::string(AO::name(AO::GR_ROPE_50FT)) !=
            "Rope, 50 ft.") ++bad;
        // the four exemption wordings, as printed
        if (std::string(AO::exemptName(
            AO::EX_MATERIAL_COMPONENTS)) !=
            "material components (unless large and bulky)") ++bad;
        if (std::string(AO::exemptName(AO::EX_HELM)) !=
            "any helm but great helm, if the character has any armor")
            ++bad;
        if (std::string(AO::exemptName(AO::EX_CLOTHING)) !=
            "one set of clothing") ++bad;
        if (std::string(AO::exemptName(AO::EX_THIEVES_PICKS)) !=
            "thieves' picks and tools") ++bad;
        printf("R151 Appendix O encumbrance audit: bad %d\n", bad);
        if (bad) return 1;
    }
