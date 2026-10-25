    // ---- R617 OA class combos audit ----
    // OA round four (capture pp. 16-23): the Chapter 2 opener - the class and
    // race combinations riders and the four combination tables: the class
    // limits with the alignment tiers, the racial ability limits, the class
    // ability minimums with the bonus columns, and the armor and weapons
    // permissions with the weapon-list counts.
    {
        using namespace rules;
        int bad = 0;
    if (dgdT9RowCount() != 10
            || dgdT9Unlimited() != 99
            || dgdT9NotPermitted() != 0
            || dgdAlignLawful() != 1
            || dgdAlignGood() != 2
            || dgdAlignNonLaw() != 3
            || dgdAlignAny() != 4
            || dgdAlignNonGood() != 5
            || dgdT10RowCount() != 6
            || dgdT12RowCount() != 10
            || dgdT12None() != -1
            || dgdT13RowCount() != 10
            || dgdArmorNone() != 0
            || dgdArmorLeather() != 1
            || dgdArmorAny() != 2
            || dgdWeaponsAny() != 0
            || dgdWeaponsAnyBut() != 1
            || dgdWeaponsNamed() != 2
            || dgdPoisonNever() != 0
            || dgdPoisonEvilOnly() != 1
            || dgdPoisonDm() != 2
            || dgdPoisonYes() != 3
            || dgdShukenjaWeaponCount() != 16
            || dgdSoheiExclusionCount() != 7
            || dgdWuJenWeaponCount() != 20
            || dgdMonkWeaponCount() != 16
            || !dgdUnlimitedMeansAny()
            || !dgdNumberMeansCap()
            || !dgdWishOneAboveCap()
            || !dgdAlignmentAllRaces()
            || !dgdT10ExceptionalStr()
            || !dgdT12BarbWisMax()
            || !dgdT12ColonIsBonus()
            || !dgdT13ShieldNone()
            || !dgdT13SamuraiNinjaWeapons()
            || !dgdT13SamuraiOilSiege()
            || !dgdT13NinjaProficiencies()
        )
            ++bad;
        // the Table 9 grid: the four race level-cap columns with the
        // alignment tiers across the ten classes (capture p. 16)
        int CT9[10][5] = {
            {6,0,99,12,1},
            {0,8,99,0,2},
            {0,0,99,0,1},
            {10,0,99,0,3},
            {0,6,99,9,1},
            {99,99,99,99,4},
            {7,9,99,0,3},
            {0,0,17,17,1},
            {0,0,99,0,5},
            {10,0,99,0,1},
            };
        for (int b = 0;
             b < dgdT9RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgdT9Korobokuru(b);
            vals[1] = dgdT9Hengeyokai(b);
            vals[2] = dgdT9Human(b);
            vals[3] = dgdT9SpiritFolk(b);
            vals[4] = dgdT9Align(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT9[b][c])
                    ++bad;
            }
        }
        // the Table 10 grid: the racial ability score min/max pairs for the
        // three nonhuman races (capture p. 16)
        int CT10[6][6] = {
            {8,19,12,18,6,18},
            {6,18,9,18,12,18},
            {12,19,12,18,6,14},
            {3,15,12,18,12,18},
            {3,17,12,18,9,18},
            {3,16,12,17,14,18},
            };
        for (int b = 0;
             b < dgdT10RowCount();
             ++b) {
            int vals[6];
            vals[0] = dgdT10KoroMin(b);
            vals[1] = dgdT10KoroMax(b);
            vals[2] = dgdT10HengeMin(b);
            vals[3] = dgdT10HengeMax(b);
            vals[4] = dgdT10SpiritMin(b);
            vals[5] = dgdT10SpiritMax(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT10[b][c])
                    ++bad;
            }
        }
        // the Table 12 grid: the class ability score minimums and the
        // 10-percent bonus minimums across the ten classes (capture p. 22)
        int CT12[10][12] = {
            {-1,-1,14,-1,15,-1,-1,-1,-1,-1,-1,-1},
            {9,14,8,-1,8,-1,-1,-1,-1,-1,-1,-1},
            {12,-1,14,-1,-1,-1,-1,-1,12,14,-1,-1},
            {15,-1,15,-1,11,-1,-1,-1,15,-1,-1,-1},
            {-1,-1,14,-1,-1,-1,15,-1,-1,-1,14,-1},
            {13,-1,-1,-1,13,-1,14,-1,13,-1,-1,-1},
            {9,-1,-1,-1,9,15,-1,-1,12,15,-1,-1},
            {13,15,-1,-1,10,-1,-1,-1,12,15,-1,-1},
            {-1,-1,-1,-1,-1,-1,13,15,-1,-1,-1,-1},
            {11,-1,15,-1,-1,-1,15,-1,-1,-1,13,-1},
            };
        for (int b = 0;
             b < dgdT12RowCount();
             ++b) {
            int vals[12];
            vals[0] = dgdT12StrMin(b);
            vals[1] = dgdT12StrBonus(b);
            vals[2] = dgdT12DexMin(b);
            vals[3] = dgdT12DexBonus(b);
            vals[4] = dgdT12ConMin(b);
            vals[5] = dgdT12ConBonus(b);
            vals[6] = dgdT12IntMin(b);
            vals[7] = dgdT12IntBonus(b);
            vals[8] = dgdT12WisMin(b);
            vals[9] = dgdT12WisBonus(b);
            vals[10] = dgdT12ChaMin(b);
            vals[11] = dgdT12ChaBonus(b);
            for (int c = 0; c < 12;
                 ++c) {
                if (vals[c] != CT12[b][c])
                    ++bad;
            }
        }
        // the Table 13 grid: the armor tiers, weapon modes, list counts, oil
        // and poison tiers across the ten classes (capture pp. 22-23)
        int CT13[10][5] = {
            {2,0,0,0,1},
            {1,2,16,1,0},
            {2,1,7,1,1},
            {0,0,0,1,2},
            {2,0,0,1,2},
            {2,0,0,1,2},
            {0,2,20,0,2},
            {0,2,16,0,2},
            {1,0,0,1,3},
            {1,0,0,1,3},
            };
        for (int b = 0;
             b < dgdT13RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgdT13Armor(b);
            vals[1] = dgdT13Weapons(b);
            vals[2] = dgdT13ListCount(b);
            vals[3] = dgdT13Oil(b);
            vals[4] = dgdT13Poison(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT13[b][c])
                    ++bad;
            }
        }
        // the dgdUnlimitedMeansAny pin
    if (dgdUnlimitedMeansAny() != 1
        )
            ++bad;
        // the dgdNumberMeansCap pin
    if (dgdNumberMeansCap() != 1
        )
            ++bad;
        // the dgdWishOneAboveCap pin
    if (dgdWishOneAboveCap() != 1
        )
            ++bad;
        // the dgdAlignmentAllRaces pin
    if (dgdAlignmentAllRaces() != 1
        )
            ++bad;
        // the dgdT9RowCount pin
    if (dgdT9RowCount() != 10
        )
            ++bad;
        // the dgdT9Unlimited pin
    if (dgdT9Unlimited() != 99
        )
            ++bad;
        // the dgdT9NotPermitted pin
    if (dgdT9NotPermitted() != 0
        )
            ++bad;
        // the dgdAlignLawful pin
    if (dgdAlignLawful() != 1
        )
            ++bad;
        // the dgdAlignGood pin
    if (dgdAlignGood() != 2
        )
            ++bad;
        // the dgdAlignNonLaw pin
    if (dgdAlignNonLaw() != 3
        )
            ++bad;
        // the dgdAlignAny pin
    if (dgdAlignAny() != 4
        )
            ++bad;
        // the dgdAlignNonGood pin
    if (dgdAlignNonGood() != 5
        )
            ++bad;
        // the dgdT10RowCount pin
    if (dgdT10RowCount() != 6
        )
            ++bad;
        // the dgdT10ExceptionalStr pin
    if (dgdT10ExceptionalStr() != 1
        )
            ++bad;
        // the dgdT12RowCount pin
    if (dgdT12RowCount() != 10
        )
            ++bad;
        // the dgdT12None pin
    if (dgdT12None() != -1
        )
            ++bad;
        // the dgdT12BarbWisMax pin
    if (dgdT12BarbWisMax() != 1
        )
            ++bad;
        // the dgdT12ColonIsBonus pin
    if (dgdT12ColonIsBonus() != 1
        )
            ++bad;
        // the dgdT13RowCount pin
    if (dgdT13RowCount() != 10
        )
            ++bad;
        // the dgdArmorNone pin
    if (dgdArmorNone() != 0
        )
            ++bad;
        // the dgdArmorLeather pin
    if (dgdArmorLeather() != 1
        )
            ++bad;
        // the dgdArmorAny pin
    if (dgdArmorAny() != 2
        )
            ++bad;
        // the dgdWeaponsAny pin
    if (dgdWeaponsAny() != 0
        )
            ++bad;
        // the dgdWeaponsAnyBut pin
    if (dgdWeaponsAnyBut() != 1
        )
            ++bad;
        // the dgdWeaponsNamed pin
    if (dgdWeaponsNamed() != 2
        )
            ++bad;
        // the dgdPoisonNever pin
    if (dgdPoisonNever() != 0
        )
            ++bad;
        // the dgdPoisonEvilOnly pin
    if (dgdPoisonEvilOnly() != 1
        )
            ++bad;
        // the dgdPoisonDm pin
    if (dgdPoisonDm() != 2
        )
            ++bad;
        // the dgdPoisonYes pin
    if (dgdPoisonYes() != 3
        )
            ++bad;
        // the dgdShukenjaWeaponCount pin
    if (dgdShukenjaWeaponCount() != 16
        )
            ++bad;
        // the dgdSoheiExclusionCount pin
    if (dgdSoheiExclusionCount() != 7
        )
            ++bad;
        // the dgdWuJenWeaponCount pin
    if (dgdWuJenWeaponCount() != 20
        )
            ++bad;
        // the dgdMonkWeaponCount pin
    if (dgdMonkWeaponCount() != 16
        )
            ++bad;
        // the dgdT13ShieldNone pin
    if (dgdT13ShieldNone() != 1
        )
            ++bad;
        // the dgdT13SamuraiNinjaWeapons pin
    if (dgdT13SamuraiNinjaWeapons() != 1
        )
            ++bad;
        // the dgdT13SamuraiOilSiege pin
    if (dgdT13SamuraiOilSiege() != 1
        )
            ++bad;
        // the dgdT13NinjaProficiencies pin
    if (dgdT13NinjaProficiencies() != 1
        )
            ++bad;
        // the monk human and spirit folk 17 caps (capture p. 16)
    if (dgdT9Human(7) != 17
            || dgdT9SpiritFolk(7) != 17
        )
            ++bad;
        // the bushi row is unlimited in every race and any alignment (capture
        // p. 16)
    if (dgdT9Korobokuru(5) != 99
            || dgdT9Hengeyokai(5) != 99
            || dgdT9SpiritFolk(5) != 99
            || dgdT9Align(5) != 4
        )
            ++bad;
        // the samurai spirit folk 12 and the korobokuru 6 caps (capture p.
        // 16)
    if (dgdT9SpiritFolk(0) != 12
            || dgdT9Korobokuru(0) != 6
        )
            ++bad;
        // the monk mins - Str 15 Dex 15 Con 11 Wis 15 (capture p. 22)
    if (dgdT12StrMin(3) != 15
            || dgdT12DexMin(3) != 15
            || dgdT12ConMin(3) != 11
            || dgdT12WisMin(3) != 15
        )
            ++bad;
        // the wu jen Int 13:15 - the min and the bonus (capture p. 22)
    if (dgdT12IntMin(8) != 13
            || dgdT12IntBonus(8) != 15
        )
            ++bad;
        // the sohei Str 13:15 - the min and the bonus (capture p. 22)
    if (dgdT12StrMin(7) != 13
            || dgdT12StrBonus(7) != 15
        )
            ++bad;
        // the wu jen row - no armor, the 20-item list, no oil (capture p. 23)
    if (dgdT13Armor(6) != 0
            || dgdT13ListCount(6) != 20
            || dgdT13Oil(6) != 0
        )
            ++bad;
        // the ninja row - the leather-class armor, any weapons, poison yes
        // (capture p. 23)
    if (dgdT13Armor(8) != 1
            || dgdT13Weapons(8) != 0
            || dgdT13Poison(8) != 3
        )
            ++bad;
        // the list counts match the named-list consts (capture pp. 22-23)
    if (dgdT13ListCount(1) != dgdShukenjaWeaponCount()
            || dgdT13ListCount(6) != dgdWuJenWeaponCount()
            || dgdT13ListCount(7) != dgdMonkWeaponCount()
        )
            ++bad;
        // the sohei exclusion count rides the grid (capture p. 22)
    if (dgdT13ListCount(2) != dgdSoheiExclusionCount()
        )
            ++bad;
        printf("R617 OA class combos audit: bad %d\n", bad);
        if (bad) return 1;
    }
