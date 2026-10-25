    // ---- R150: appendix I dressing audit ------------------------------
    // The DMG pp.217-220 dressing lists (Appendix I), pinned
    // band-by-band in dm/appendixi.h: air currents, odors,
    // air, general items and unexplained sounds. Every band
    // edge pinned both ways, the house discipline: at the
    // edge the kind, one past the edge the next. The 00 fold
    // and the clamp are pinned too. Count corrections, named
    // in the header: the R149 box said 16/100/68 bands; the
    // prints read 14/54/58 (odors 14 and air 6 were right).
    {
        int bad = 0;
        namespace AI = dm::appendixi;
        if (AI::AC_COUNT != 14 || AI::OD_COUNT != 14 ||
            AI::AIR_COUNT != 6 || AI::GI_COUNT != 54 ||
            AI::SK_COUNT != 58) ++bad;
        // air currents: 14 bands, edges both ways
        static const struct { int lo, hi; AI::AirCurrent k; }
            kAC[] = {
            {  1,  5, AI::AC_BREEZE_SLIGHT },
            {  6, 10, AI::AC_BREEZE_SLIGHT_DAMP },
            { 11, 12, AI::AC_BREEZE_GUSTING },
            { 13, 18, AI::AC_COLD_CURRENT },
            { 19, 20, AI::AC_DOWNDRAFT_SLIGHT },
            { 21, 22, AI::AC_DOWNDRAFT_STRONG },
            { 23, 69, AI::AC_STILL },
            { 70, 75, AI::AC_STILL_VERY_CHILL },
            { 76, 85, AI::AC_STILL_WARM },
            { 86, 87, AI::AC_UPDRAFT_SLIGHT },
            { 88, 89, AI::AC_UPDRAFT_STRONG },
            { 90, 93, AI::AC_WIND_STRONG },
            { 94, 95, AI::AC_WIND_STRONG_GUSTING },
            { 96,100, AI::AC_WIND_STRONG_MOANING },
        };
        for (size_t i = 0; i < sizeof(kAC)/sizeof(kAC[0]); ++i) {
            if (AI::airCurrentFor(kAC[i].lo) != kAC[i].k) ++bad;
            if (AI::airCurrentFor(kAC[i].hi) != kAC[i].k) ++bad;
            if (i + 1 < sizeof(kAC)/sizeof(kAC[0]) &&
                AI::airCurrentFor(kAC[i].hi + 1) != kAC[i+1].k)
                ++bad;
        }
        if (AI::airCurrentFor(0) != AI::AC_WIND_STRONG_MOANING)
            ++bad;   // 00 folds to 100
        // odors: 14 bands
        static const struct { int lo, hi; AI::Odor k; }
            kOD[] = {
            {  1,  3, AI::OD_ACRID },
            {  4,  5, AI::OD_CHLORINE },
            {  6, 39, AI::OD_DANK_MOULDY },
            { 40, 49, AI::OD_EARTHY },
            { 50, 57, AI::OD_MANURE },
            { 58, 61, AI::OD_METALLIC },
            { 62, 65, AI::OD_OZONE },
            { 66, 70, AI::OD_PUTRID },
            { 71, 75, AI::OD_ROTTING_VEGETATION },
            { 76, 77, AI::OD_SALTY_WET },
            { 78, 82, AI::OD_SMOKY },
            { 83, 89, AI::OD_STALE_FETID },
            { 90, 95, AI::OD_SULPHUROUS },
            { 96,100, AI::OD_URINE },
        };
        for (size_t i = 0; i < sizeof(kOD)/sizeof(kOD[0]); ++i) {
            if (AI::odorFor(kOD[i].lo) != kOD[i].k) ++bad;
            if (AI::odorFor(kOD[i].hi) != kOD[i].k) ++bad;
            if (i + 1 < sizeof(kOD)/sizeof(kOD[0]) &&
                AI::odorFor(kOD[i].hi + 1) != kOD[i+1].k) ++bad;
        }
        if (AI::odorFor(0) != AI::OD_URINE) ++bad;
        // air: 6 bands
        static const struct { int lo, hi; AI::AirState k; }
            kAIR[] = {
            {  1, 70, AI::AIR_CLEAR },
            { 71, 80, AI::AIR_FOGGY },
            { 81, 88, AI::AIR_FOGGY_NEAR_FLOOR },
            { 89, 90, AI::AIR_HAZY_DUST },
            { 91, 98, AI::AIR_HAZY_SMOKE },
            { 99,100, AI::AIR_MISTED },
        };
        for (size_t i = 0; i < sizeof(kAIR)/sizeof(kAIR[0]); ++i) {
            if (AI::airStateFor(kAIR[i].lo) != kAIR[i].k) ++bad;
            if (AI::airStateFor(kAIR[i].hi) != kAIR[i].k) ++bad;
            if (i + 1 < sizeof(kAIR)/sizeof(kAIR[0]) &&
                AI::airStateFor(kAIR[i].hi + 1) != kAIR[i+1].k)
                ++bad;
        }
        if (AI::airStateFor(0) != AI::AIR_MISTED) ++bad;
        // general items: 54 bands
        static const struct { int lo, hi; AI::GeneralItem k; }
            kGI[] = {
            {  1,  1, AI::GI_ARROW_BROKEN },
            {  2,  4, AI::GI_ASHES },
            {  5,  6, AI::GI_BONES },
            {  7,  7, AI::GI_BOTTLE_BROKEN },
            {  8,  8, AI::GI_CHAIN_CORRODED },
            {  9,  9, AI::GI_CLUB_SPLINTERED },
            { 10, 19, AI::GI_COBWEBS },
            { 20, 20, AI::GI_COIN_COPPER_BENT },
            { 21, 22, AI::GI_CRACKS_CEILING },
            { 23, 24, AI::GI_CRACKS_FLOOR },
            { 25, 26, AI::GI_CRACKS_WALL },
            { 27, 27, AI::GI_DAGGER_HILT },
            { 28, 29, AI::GI_DAMPNESS_CEILING },
            { 30, 33, AI::GI_DAMPNESS_WALL },
            { 34, 40, AI::GI_DRIPPING },
            { 41, 41, AI::GI_DRIED_BLOOD },
            { 42, 44, AI::GI_DUNG },
            { 45, 49, AI::GI_DUST },
            { 50, 50, AI::GI_FLASK_CRACKED },
            { 51, 51, AI::GI_FOOD_SCRAPS },
            { 52, 52, AI::GI_FUNGI_COMMON },
            { 53, 55, AI::GI_GUANO },
            { 56, 56, AI::GI_HAIR_FUR_BITS },
            { 57, 57, AI::GI_HAMMER_HEAD_CRACKED },
            { 58, 58, AI::GI_HELMET_DENTED },
            { 59, 59, AI::GI_IRON_BAR_BENT },
            { 60, 60, AI::GI_JAVELIN_HEAD_BLUNT },
            { 61, 61, AI::GI_LEATHER_BOOT },
            { 62, 64, AI::GI_LEAVES_TWIGS },
            { 65, 68, AI::GI_MOLD },
            { 69, 69, AI::GI_PICK_HANDLE },
            { 70, 70, AI::GI_POLE_BROKEN },
            { 71, 71, AI::GI_POTTERY_SHARDS },
            { 72, 73, AI::GI_RAGS },
            { 74, 74, AI::GI_ROPE_ROTTEN },
            { 75, 76, AI::GI_RUBBLE_DIRT },
            { 77, 77, AI::GI_SACK_TORN },
            { 78, 78, AI::GI_SLIMY_CEILING },
            { 79, 79, AI::GI_SLIMY_FLOOR },
            { 80, 80, AI::GI_SLIMY_WALL },
            { 81, 81, AI::GI_SPIKE_RUSTED },
            { 82, 83, AI::GI_STICKS },
            { 84, 84, AI::GI_STONES_SMALL },
            { 85, 85, AI::GI_STRAW },
            { 86, 86, AI::GI_SWORD_BLADE_BROKEN },
            { 87, 87, AI::GI_TEETH_SCATTERED },
            { 88, 88, AI::GI_TORCH_STUB },
            { 89, 89, AI::GI_WALL_SCRATCHINGS },
            { 90, 91, AI::GI_WATER_SMALL_PUDDLE },
            { 92, 93, AI::GI_WATER_LARGE_PUDDLE },
            { 94, 95, AI::GI_WATER_TRICKLE },
            { 96, 96, AI::GI_WAX_DRIPPINGS },
            { 97, 97, AI::GI_WAX_BLOB },
            { 98,100, AI::GI_WOOD_PIECES_ROTTING },
        };
        for (size_t i = 0; i < sizeof(kGI)/sizeof(kGI[0]); ++i) {
            if (AI::generalItemFor(kGI[i].lo) != kGI[i].k) ++bad;
            if (AI::generalItemFor(kGI[i].hi) != kGI[i].k) ++bad;
            if (i + 1 < sizeof(kGI)/sizeof(kGI[0]) &&
                AI::generalItemFor(kGI[i].hi + 1) != kGI[i+1].k)
                ++bad;
        }
        if (AI::generalItemFor(0) != AI::GI_WOOD_PIECES_ROTTING)
            ++bad;
        // unexplained sounds: 58 bands
        static const struct { int lo, hi; AI::SoundKind k; }
            kSK[] = {
            {  1,  5, AI::SK_BANG_SLAM },
            {  6,  6, AI::SK_BELLOW },
            {  7,  7, AI::SK_BONG },
            {  8,  8, AI::SK_BUZZING },
            {  9, 10, AI::SK_CHANTING },
            { 11, 11, AI::SK_CHIMING },
            { 12, 12, AI::SK_CHIRPING },
            { 13, 13, AI::SK_CLANKING },
            { 14, 14, AI::SK_CLASHING },
            { 15, 15, AI::SK_CLICKING },
            { 16, 16, AI::SK_COUGHING },
            { 17, 18, AI::SK_CREAKING },
            { 19, 19, AI::SK_DRUMMING },
            { 20, 23, AI::SK_FOOTSTEPS_AHEAD },
            { 24, 26, AI::SK_FOOTSTEPS_APPROACHING },
            { 27, 29, AI::SK_FOOTSTEPS_BEHIND },
            { 30, 31, AI::SK_FOOTSTEPS_RECEDING },
            { 32, 33, AI::SK_FOOTSTEPS_SIDE },
            { 34, 35, AI::SK_GIGGLING },
            { 36, 36, AI::SK_GONG },
            { 37, 39, AI::SK_GRATING },
            { 40, 41, AI::SK_GROANING },
            { 42, 42, AI::SK_GRUNTING },
            { 43, 44, AI::SK_HISSING },
            { 45, 45, AI::SK_HOOTING },
            { 46, 46, AI::SK_HORN },
            { 47, 47, AI::SK_HOWLING },
            { 48, 48, AI::SK_HUMMING },
            { 49, 49, AI::SK_JINGLING },
            { 50, 53, AI::SK_KNOCKING },
            { 54, 55, AI::SK_LAUGHTER },
            { 56, 57, AI::SK_MOANING },
            { 58, 60, AI::SK_MURMURING },
            { 61, 61, AI::SK_MUSIC },
            { 62, 62, AI::SK_RATTLING },
            { 63, 63, AI::SK_RINGING },
            { 64, 64, AI::SK_ROAR },
            { 65, 68, AI::SK_RUSTLING },
            { 69, 72, AI::SK_SCRATCHING },
            { 73, 74, AI::SK_SCREAMING },
            { 75, 77, AI::SK_SCUTTLING },
            { 78, 78, AI::SK_SHUFFLING },
            { 79, 80, AI::SK_SLITHERING },
            { 81, 81, AI::SK_SNAPPING },
            { 82, 82, AI::SK_SNEEZING },
            { 83, 83, AI::SK_SOBBING },
            { 84, 84, AI::SK_SPLASHING },
            { 85, 85, AI::SK_SPLINTERING },
            { 86, 87, AI::SK_SQUEAKING },
            { 88, 88, AI::SK_SQUEALING },
            { 89, 90, AI::SK_TAPPING },
            { 91, 92, AI::SK_THUD },
            { 93, 94, AI::SK_THUMPING },
            { 95, 95, AI::SK_TINKLING },
            { 96, 96, AI::SK_TWANGING },
            { 97, 97, AI::SK_WHINING },
            { 98, 98, AI::SK_WHISPERING },
            { 99,100, AI::SK_WHISTLING },
        };
        for (size_t i = 0; i < sizeof(kSK)/sizeof(kSK[0]); ++i) {
            if (AI::soundFor(kSK[i].lo) != kSK[i].k) ++bad;
            if (AI::soundFor(kSK[i].hi) != kSK[i].k) ++bad;
            if (i + 1 < sizeof(kSK)/sizeof(kSK[0]) &&
                AI::soundFor(kSK[i].hi + 1) != kSK[i+1].k) ++bad;
        }
        if (AI::soundFor(0) != AI::SK_WHISTLING) ++bad;
        printf("R150 appendix I dressing audit: bad %d\n", bad);
        if (bad) return 1;
    }
