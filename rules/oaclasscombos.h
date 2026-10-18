// =========================================================================================
// Adnd1 - rules/oaclasscombos.h
// CLASS AND RACE COMBINATIONS, printed capture pp. 16-23 - the OA Chapter 2
// opener round
// census 539 -> 540.
//
// verified against capture pp. 16-23 of the oa.pdf OCR session (single
// Mistral-OCR capture; cites are capture pages). ENCODINGS: Table 9 U pins as
// the sentinel 99 and No as 0; Table 13 is a TEXT-HEAVY grid encoded as tiers
// - the armor tiers (any/leather-class/none), the weapon modes
// (any/any-but/named) with the list-count column carrying the printed weapon
// lists as counts (shukenja 16, the sohei 7-item exclusion list, wu jen 20,
// monk 16), the oil and poison tiers. The Table 12 colon notation pins as two
// columns - the required minimum and the 10-percent bonus minimum; the
// barbarian Wisdom 16 prints as the only MAXIMUM on a minimum table and pins
// as its own bool. The Table 13 riders (the samurai-kensai ninja-weapon honor
// loss, the samurai siege-oil exception, the ninja proficiency requirement)
// pin as bools.
//
// the gap census after this round: 23 closed, 212 open - the Chapter 2 combos
// openers flip (census 539 -> 540); NEXT - R618: the three races - the
// korobokuru, hengeyokai and spirit folk sections with Table 11 Hengeyokai
// Creatures, prefix dge (verify free), audit "R618 OA races audit", include
// after rules/oaclasscombos.h
//
namespace rules {

// ---- the combos prose pins ----

// the combos prose (capture p. 16): U means a character of the race can rise
// to any level in the class
inline bool dgdUnlimitedMeansAny()
    { return true; }

// the combos prose (capture p. 16): a number is the racial level cap - the
// class belongs but rises no higher
inline bool dgdNumberMeansCap()
    { return true; }

// the combos prose (capture p. 16): a wish spell allows one level above the
// racial maximum
inline bool dgdWishOneAboveCap()
    { return true; }

// the combos prose (capture p. 16): the alignment restrictions apply to
// members of all races
inline bool dgdAlignmentAllRaces()
    { return true; }

// ---- the Table 9 class limits grid ----

// Table 9 (capture p. 16): ten class rows - samurai, shukenja, sohei,
// barbarian, kensai, bushi, wu jen, monk, ninja, yakuza
inline int dgdT9RowCount()
    { return 10; }

// Table 9 (capture p. 16): the U sentinel - the unlimited class-level column
// value
inline int dgdT9Unlimited()
    { return 99; }

// Table 9 (capture p. 16): the No sentinel - the class not permitted
inline int dgdT9NotPermitted()
    { return 0; }

// Table 9 (capture p. 16): the any-lawful alignment tier (samurai, sohei,
// kensai, monk, yakuza)
inline int dgdAlignLawful()
    { return 1; }

// Table 9 (capture p. 16): the any-good alignment tier (shukenja)
inline int dgdAlignGood()
    { return 2; }

// Table 9 (capture p. 16): the any-non-lawful alignment tier (barbarian, wu
// jen)
inline int dgdAlignNonLaw()
    { return 3; }

// Table 9 (capture p. 16): the any alignment tier (bushi)
inline int dgdAlignAny()
    { return 4; }

// Table 9 (capture p. 16): the any-non-good alignment tier (ninja)
inline int dgdAlignNonGood()
    { return 5; }

// the korobokuru level-cap column: samurai 6, barbarian and yakuza 10, wu jen
// 7, bushi unlimited, monk-shukenja-sohei-kensai-ninja No (capture p. 16).
inline int dgdT9Korobokuru(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 10;
        case 4:
            return 0;
        case 5:
            return 99;
        case 6:
            return 7;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 10;
        default:
            return -99;
        }
    }

// the hengeyokai level-cap column: shukenja 8, kensai 6, wu jen 9, bushi
// unlimited, the rest No (capture p. 16).
inline int dgdT9Hengeyokai(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 8;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 6;
        case 5:
            return 99;
        case 6:
            return 9;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the human level-cap column: unlimited in every class except the monk 17 cap
// (capture p. 16).
inline int dgdT9Human(int b)
    {
        switch (b) {
        case 0:
            return 99;
        case 1:
            return 99;
        case 2:
            return 99;
        case 3:
            return 99;
        case 4:
            return 99;
        case 5:
            return 99;
        case 6:
            return 99;
        case 7:
            return 17;
        case 8:
            return 99;
        case 9:
            return 99;
        default:
            return -99;
        }
    }

// the spirit folk level-cap column: samurai 12, kensai 9, monk 17, bushi
// unlimited, the rest No (capture p. 16).
inline int dgdT9SpiritFolk(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 9;
        case 5:
            return 99;
        case 6:
            return 0;
        case 7:
            return 17;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the alignment tier column: lawful, good, non-lawful, any, non-good per the
// printed restrictions (capture p. 16).
inline int dgdT9Align(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 1;
        default:
            return -99;
        }
    }

// ---- the Table 10 racial limits grid ----

// Table 10 (capture p. 16): six ability rows - Strength, Dexterity,
// Constitution, Intelligence, Wisdom, Charisma
inline int dgdT10RowCount()
    { return 6; }

// Table 10 footnote (capture p. 16): samurai, bushi, kensai, barbarian and
// sohei can have exceptional Strength scores
inline bool dgdT10ExceptionalStr()
    { return true; }

// the korobokuru minimum column: Str 8, Dex 6, Con 12, Int 3, Wis 3, Cha 3
// (capture p. 16).
inline int dgdT10KoroMin(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 6;
        case 2:
            return 12;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        default:
            return -99;
        }
    }

// the korobokuru maximum column: Str 19, Dex 18, Con 19, Int 15, Wis 17, Cha
// 16 (capture p. 16).
inline int dgdT10KoroMax(int b)
    {
        switch (b) {
        case 0:
            return 19;
        case 1:
            return 18;
        case 2:
            return 19;
        case 3:
            return 15;
        case 4:
            return 17;
        case 5:
            return 16;
        default:
            return -99;
        }
    }

// the hengeyokai minimum column: Str 12, Dex 9, Con 12, Int 12, Wis 12, Cha
// 12 (capture p. 16).
inline int dgdT10HengeMin(int b)
    {
        switch (b) {
        case 0:
            return 12;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 12;
        case 4:
            return 12;
        case 5:
            return 12;
        default:
            return -99;
        }
    }

// the hengeyokai maximum column: Str 18, Dex 18, Con 18, Int 18, Wis 18, Cha
// 17 (capture p. 16).
inline int dgdT10HengeMax(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 18;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 17;
        default:
            return -99;
        }
    }

// the spirit folk minimum column: Str 6, Dex 12, Con 6, Int 12, Wis 9, Cha 14
// (capture p. 16).
inline int dgdT10SpiritMin(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 12;
        case 2:
            return 6;
        case 3:
            return 12;
        case 4:
            return 9;
        case 5:
            return 14;
        default:
            return -99;
        }
    }

// the spirit folk maximum column: Str 18, Dex 18, Con 14, Int 18, Wis 18, Cha
// 18 (capture p. 16).
inline int dgdT10SpiritMax(int b)
    {
        switch (b) {
        case 0:
            return 18;
        case 1:
            return 18;
        case 2:
            return 14;
        case 3:
            return 18;
        case 4:
            return 18;
        case 5:
            return 18;
        default:
            return -99;
        }
    }

// ---- the Table 12 class minimums grid ----

// Table 12 (capture p. 22): ten class rows, the same order as Table 9
inline int dgdT12RowCount()
    { return 10; }

// Table 12 (capture p. 22): the no-requirement sentinel
inline int dgdT12None()
    { return -1; }

// Table 12 footnote (capture p. 22): the barbarian Wisdom 16 is a MAXIMUM -
// the only maximum on the class-minimum table
inline bool dgdT12BarbWisMax()
    { return true; }

// Table 12 note (capture p. 22): the numbers after the colons are the
// minimums required for the 10 percent experience bonus
inline bool dgdT12ColonIsBonus()
    { return true; }

// the Strength minimum column: bushi 9, kensai 12, monk 15, samurai 13,
// shukenja 9, sohei 13, yakuza 11 (capture p. 22).
inline int dgdT12StrMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 9;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return 13;
        case 6:
            return 9;
        case 7:
            return 13;
        case 8:
            return -1;
        case 9:
            return 11;
        default:
            return -99;
        }
    }

// the Strength bonus column: bushi 14, sohei 15 (capture p. 22).
inline int dgdT12StrBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return 14;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return 15;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Dexterity minimum column: barbarian 14, bushi 8, kensai 14, monk 15,
// ninja 14, yakuza 15 (capture p. 22).
inline int dgdT12DexMin(int b)
    {
        switch (b) {
        case 0:
            return 14;
        case 1:
            return 8;
        case 2:
            return 14;
        case 3:
            return 15;
        case 4:
            return 14;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return 15;
        default:
            return -99;
        }
    }

// the Dexterity bonus column: none printed (capture p. 22).
inline int dgdT12DexBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Constitution minimum column: barbarian 15, bushi 8, monk 11, samurai
// 13, shukenja 9, sohei 10 (capture p. 22).
inline int dgdT12ConMin(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 8;
        case 2:
            return -1;
        case 3:
            return 11;
        case 4:
            return -1;
        case 5:
            return 13;
        case 6:
            return 9;
        case 7:
            return 10;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Constitution bonus column: shukenja 15 (capture p. 22).
inline int dgdT12ConBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return 15;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Intelligence minimum column: ninja 15, samurai 14, wu jen 13, yakuza 15
// (capture p. 22).
inline int dgdT12IntMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 15;
        case 5:
            return 14;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 13;
        case 9:
            return 15;
        default:
            return -99;
        }
    }

// the Intelligence bonus column: wu jen 15 (capture p. 22).
inline int dgdT12IntBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return 15;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Wisdom minimum column: kensai 12, monk 15, samurai 13, shukenja 12,
// sohei 12 (capture p. 22).
inline int dgdT12WisMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 12;
        case 3:
            return 15;
        case 4:
            return -1;
        case 5:
            return 13;
        case 6:
            return 12;
        case 7:
            return 12;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Wisdom bonus column: kensai 14, shukenja 15, sohei 15 (capture p. 22).
inline int dgdT12WisBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return 14;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return 15;
        case 7:
            return 15;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// the Charisma minimum column: ninja 14, yakuza 13 (capture p. 22).
inline int dgdT12ChaMin(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return 14;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return 13;
        default:
            return -99;
        }
    }

// the Charisma bonus column: none printed (capture p. 22).
inline int dgdT12ChaBonus(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -1;
        case 2:
            return -1;
        case 3:
            return -1;
        case 4:
            return -1;
        case 5:
            return -1;
        case 6:
            return -1;
        case 7:
            return -1;
        case 8:
            return -1;
        case 9:
            return -1;
        default:
            return -99;
        }
    }

// ---- the Table 13 armor and weapons grid ----

// Table 13 (capture pp. 22-23): ten class rows in the Table 9 order
inline int dgdT13RowCount()
    { return 10; }

// Table 13 armor tier (capture p. 22): no armor permitted - kensai, wu jen,
// monk
inline int dgdArmorNone()
    { return 0; }

// Table 13 armor tier (capture p. 22): the leather class - shukenja leather
// padded hara-ate haramaki jingasa studded; ninja adds leather scale and
// chain; yakuza leather padded
inline int dgdArmorLeather()
    { return 1; }

// Table 13 armor tier (capture p. 22): any armor - samurai, sohei, barbarian,
// bushi
inline int dgdArmorAny()
    { return 2; }

// Table 13 weapons mode (capture pp. 22-23): any weapon - samurai, kensai,
// barbarian, bushi, ninja, yakuza (with the class riders)
inline int dgdWeaponsAny()
    { return 0; }

// Table 13 weapons mode (capture p. 22): any but the listed exclusions -
// sohei
inline int dgdWeaponsAnyBut()
    { return 1; }

// Table 13 weapons mode (capture pp. 22-23): the named permitted list -
// shukenja, wu jen, monk
inline int dgdWeaponsNamed()
    { return 2; }

// Table 13 poison tier (capture p. 22): never - shukenja
inline int dgdPoisonNever()
    { return 0; }

// Table 13 poison tier (capture pp. 22-23): only if evil - samurai, sohei
inline int dgdPoisonEvilOnly()
    { return 1; }

// Table 13 poison tier (capture pp. 22-23): the DM option - kensai,
// barbarian, bushi, wu jen, monk
inline int dgdPoisonDm()
    { return 2; }

// Table 13 poison tier (capture p. 23): yes - ninja, yakuza
inline int dgdPoisonYes()
    { return 3; }

// Table 13 (capture p. 22): the shukenja permitted weapon list - axe hand, bo
// stick, boku-toh, chain, gunsen, jitte, jo stick, kama, kiseru, sai, sling,
// sling staff, spear, tetsubo, three-piece rod, tui-fa
inline int dgdShukenjaWeaponCount()
    { return 16; }

// Table 13 (capture p. 22): the sohei exclusion list - blowpipe, katana,
// needle, nekode, shaken, shikomi-zue, shuriken any
inline int dgdSoheiExclusionCount()
    { return 7; }

// Table 13 (capture p. 23): the wu jen permitted weapon list - bo stick,
// boku-toh, blowpipe, bow short, chain, dagger, dart, gunsen, jitte, jo
// stick, kiseru, metsubishi, sai, shaken, shuriken any, siangkam, sling,
// sword short, tui-fan, uchi-ne
inline int dgdWuJenWeaponCount()
    { return 20; }

// Table 13 (capture p. 23): the monk permitted weapon list - martial arts
// weapons any, axe hand, boku-toh, chijiriki, crossbow any, dagger, daikyu,
// halberd, javelin, kama, kusari-gama, lasso, naginata, parang, spear,
// trident
inline int dgdMonkWeaponCount()
    { return 16; }

// Table 13 (capture pp. 22-23): every class prints None for shields
inline bool dgdT13ShieldNone()
    { return true; }

// Table 13 asterisk (capture pp. 22-23): the samurai and kensai asterisk -
// proficiency in or use of ninja preferred weapons loses honor
inline bool dgdT13SamuraiNinjaWeapons()
    { return true; }

// Table 13 double-asterisk (capture p. 23): the samurai oil rule -
// unacceptable in personal combat, allowed in siege warfare
inline bool dgdT13SamuraiOilSiege()
    { return true; }

// Table 13 dagger (capture p. 23): the ninja must use weapon proficiencies to
// gain the ninja preferred weapons
inline bool dgdT13NinjaProficiencies()
    { return true; }

// the armor tier column: any (2) for samurai, sohei, barbarian, bushi; the
// leather class (1) for shukenja, ninja, yakuza; none (0) for kensai, wu jen,
// monk (capture pp. 22-23).
inline int dgdT13Armor(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        default:
            return -99;
        }
    }

// the weapons mode column: any (0) for the six any-classes, any-but (1) for
// the sohei, named (2) for shukenja, wu jen, monk (capture pp. 22-23).
inline int dgdT13Weapons(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the list-count column: the named-list and exclusion-list counts - shukenja
// 16, sohei 7, wu jen 20, monk 16, zero elsewhere (capture pp. 22-23).
inline int dgdT13ListCount(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 16;
        case 2:
            return 7;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 20;
        case 7:
            return 16;
        case 8:
            return 0;
        case 9:
            return 0;
        default:
            return -99;
        }
    }

// the oil column: permitted (1) for every class except samurai, wu jen and
// monk (capture pp. 22-23).
inline int dgdT13Oil(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 1;
        default:
            return -99;
        }
    }

// the poison tier column: never (0) for shukenja, evil-only (1) for samurai
// and sohei, the DM option (2) for kensai, barbarian, bushi, wu jen and monk,
// yes (3) for ninja and yakuza (capture pp. 22-23).
inline int dgdT13Poison(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        default:
            return -99;
        }
    }

}   // namespace rules
