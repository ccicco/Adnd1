-- oa617: promoted from rules/oaclasscombos.h (the CLASS AND RACE COMBINATIONS, printed capture pp. 16-23 - the OA Chapter 2);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 617,
  "prefix" = "oa617",
  "banner" = {
      "title" = "CLASS AND RACE COMBINATIONS, printed capture pp. 16-23 - the OA Chapter 2",
      "provenance" = "opener round census 539 -> 540.  verified against capture pp. 16-23 of the oa.pdf OCR session (single Mistral-OCR capture; cites are capture pages). ENCODINGS: Table 9 U pins as the sentinel 99 and No as 0; Table 13 is a TEXT-HEAVY grid encoded as tiers - the armor tiers (any/leather-class/none), the weapon modes (any/any-but/named) with the list-count column carrying the printed weapon lists as counts (shukenja 16, the sohei 7-item exclusion list, wu jen 20, monk 16), the oil and poison tiers. The Table 12 colon notation pins as two columns - the required minimum and the 10-percent bonus minimum; the barbarian Wisdom 16 prints as the only MAXIMUM on a minimum table and pins as its own bool. The Table 13 riders (the samurai-kensai ninja-weapon honor loss, the samurai siege-oil exception, the ninja proficiency requirement) pin as bools.  the gap census after this round: 23 closed, 212 open - the Chapter 2 combos openers flip (census 539 -> 540); NEXT - R618: the three races - the korobokuru, hengeyokai and spirit folk sections with Table 11 Hengeyokai Creatures, prefix dge (verify free), audit \"R618 OA races audit\", include after rules/oaclasscombos.h",
    },
  "consts" = { {
      "name" = "dgdT9RowCount",
      "value" = 10,
      "comment" = "Table 9 (capture p. 16): ten class rows - samurai, shukenja, sohei, barbarian, kensai, bushi, wu jen, monk, ninja, yakuza",
    }, {
      "name" = "dgdT9Unlimited",
      "value" = 99,
      "comment" = "Table 9 (capture p. 16): the U sentinel - the unlimited class-level column value",
    }, {
      "name" = "dgdT9NotPermitted",
      "value" = 0,
      "comment" = "Table 9 (capture p. 16): the No sentinel - the class not permitted",
    }, {
      "name" = "dgdAlignLawful",
      "value" = 1,
      "comment" = "Table 9 (capture p. 16): the any-lawful alignment tier (samurai, sohei, kensai, monk, yakuza)",
    }, {
      "name" = "dgdAlignGood",
      "value" = 2,
      "comment" = "Table 9 (capture p. 16): the any-good alignment tier (shukenja)",
    }, {
      "name" = "dgdAlignNonLaw",
      "value" = 3,
      "comment" = "Table 9 (capture p. 16): the any-non-lawful alignment tier (barbarian, wu jen)",
    }, {
      "name" = "dgdAlignAny",
      "value" = 4,
      "comment" = "Table 9 (capture p. 16): the any alignment tier (bushi)",
    }, {
      "name" = "dgdAlignNonGood",
      "value" = 5,
      "comment" = "Table 9 (capture p. 16): the any-non-good alignment tier (ninja)",
    }, {
      "name" = "dgdT10RowCount",
      "value" = 6,
      "comment" = "Table 10 (capture p. 16): six ability rows - Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma",
    }, {
      "name" = "dgdT12RowCount",
      "value" = 10,
      "comment" = "Table 12 (capture p. 22): ten class rows, the same order as Table 9",
    }, {
      "name" = "dgdT12None",
      "value" = -1,
      "comment" = "Table 12 (capture p. 22): the no-requirement sentinel",
    }, {
      "name" = "dgdT13RowCount",
      "value" = 10,
      "comment" = "Table 13 (capture pp. 22-23): ten class rows in the Table 9 order",
    }, {
      "name" = "dgdArmorNone",
      "value" = 0,
      "comment" = "Table 13 armor tier (capture p. 22): no armor permitted - kensai, wu jen, monk",
    }, {
      "name" = "dgdArmorLeather",
      "value" = 1,
      "comment" = "Table 13 armor tier (capture p. 22): the leather class - shukenja leather padded hara-ate haramaki jingasa studded; ninja adds leather scale and chain; yakuza leather padded",
    }, {
      "name" = "dgdArmorAny",
      "value" = 2,
      "comment" = "Table 13 armor tier (capture p. 22): any armor - samurai, sohei, barbarian, bushi",
    }, {
      "name" = "dgdWeaponsAny",
      "value" = 0,
      "comment" = "Table 13 weapons mode (capture pp. 22-23): any weapon - samurai, kensai, barbarian, bushi, ninja, yakuza (with the class riders)",
    }, {
      "name" = "dgdWeaponsAnyBut",
      "value" = 1,
      "comment" = "Table 13 weapons mode (capture p. 22): any but the listed exclusions - sohei",
    }, {
      "name" = "dgdWeaponsNamed",
      "value" = 2,
      "comment" = "Table 13 weapons mode (capture pp. 22-23): the named permitted list - shukenja, wu jen, monk",
    }, {
      "name" = "dgdPoisonNever",
      "value" = 0,
      "comment" = "Table 13 poison tier (capture p. 22): never - shukenja",
    }, {
      "name" = "dgdPoisonEvilOnly",
      "value" = 1,
      "comment" = "Table 13 poison tier (capture pp. 22-23): only if evil - samurai, sohei",
    }, {
      "name" = "dgdPoisonDm",
      "value" = 2,
      "comment" = "Table 13 poison tier (capture pp. 22-23): the DM option - kensai, barbarian, bushi, wu jen, monk",
    }, {
      "name" = "dgdPoisonYes",
      "value" = 3,
      "comment" = "Table 13 poison tier (capture p. 23): yes - ninja, yakuza",
    }, {
      "name" = "dgdShukenjaWeaponCount",
      "value" = 16,
      "comment" = "Table 13 (capture p. 22): the shukenja permitted weapon list - axe hand, bo stick, boku-toh, chain, gunsen, jitte, jo stick, kama, kiseru, sai, sling, sling staff, spear, tetsubo, three-piece rod, tui-fa",
    }, {
      "name" = "dgdSoheiExclusionCount",
      "value" = 7,
      "comment" = "Table 13 (capture p. 22): the sohei exclusion list - blowpipe, katana, needle, nekode, shaken, shikomi-zue, shuriken any",
    }, {
      "name" = "dgdWuJenWeaponCount",
      "value" = 20,
      "comment" = "Table 13 (capture p. 23): the wu jen permitted weapon list - bo stick, boku-toh, blowpipe, bow short, chain, dagger, dart, gunsen, jitte, jo stick, kiseru, metsubishi, sai, shaken, shuriken any, siangkam, sling, sword short, tui-fan, uchi-ne",
    }, {
      "name" = "dgdMonkWeaponCount",
      "value" = 16,
      "comment" = "Table 13 (capture p. 23): the monk permitted weapon list - martial arts weapons any, axe hand, boku-toh, chijiriki, crossbow any, dagger, daikyu, halberd, javelin, kama, kusari-gama, lasso, naginata, parang, spear, trident",
    } },
  "bools" = { {
      "name" = "dgdUnlimitedMeansAny",
      "value" = true,
      "comment" = "the combos prose (capture p. 16): U means a character of the race can rise to any level in the class",
    }, {
      "name" = "dgdNumberMeansCap",
      "value" = true,
      "comment" = "the combos prose (capture p. 16): a number is the racial level cap - the class belongs but rises no higher",
    }, {
      "name" = "dgdWishOneAboveCap",
      "value" = true,
      "comment" = "the combos prose (capture p. 16): a wish spell allows one level above the racial maximum",
    }, {
      "name" = "dgdAlignmentAllRaces",
      "value" = true,
      "comment" = "the combos prose (capture p. 16): the alignment restrictions apply to members of all races",
    }, {
      "name" = "dgdT10ExceptionalStr",
      "value" = true,
      "comment" = "Table 10 footnote (capture p. 16): samurai, bushi, kensai, barbarian and sohei can have exceptional Strength scores",
    }, {
      "name" = "dgdT12BarbWisMax",
      "value" = true,
      "comment" = "Table 12 footnote (capture p. 22): the barbarian Wisdom 16 is a MAXIMUM - the only maximum on the class-minimum table",
    }, {
      "name" = "dgdT12ColonIsBonus",
      "value" = true,
      "comment" = "Table 12 note (capture p. 22): the numbers after the colons are the minimums required for the 10 percent experience bonus",
    }, {
      "name" = "dgdT13ShieldNone",
      "value" = true,
      "comment" = "Table 13 (capture pp. 22-23): every class prints None for shields",
    }, {
      "name" = "dgdT13SamuraiNinjaWeapons",
      "value" = true,
      "comment" = "Table 13 asterisk (capture pp. 22-23): the samurai and kensai asterisk - proficiency in or use of ninja preferred weapons loses honor",
    }, {
      "name" = "dgdT13SamuraiOilSiege",
      "value" = true,
      "comment" = "Table 13 double-asterisk (capture p. 23): the samurai oil rule - unacceptable in personal combat, allowed in siege warfare",
    }, {
      "name" = "dgdT13NinjaProficiencies",
      "value" = true,
      "comment" = "Table 13 dagger (capture p. 23): the ninja must use weapon proficiencies to gain the ninja preferred weapons",
    } },
  "switches" = { {
      "name" = "dgdT9Korobokuru",
      "values" = { 6, 0, 0, 10, 0, 99, 7, 0, 0, 10 },
      "default" = -99,
      "comment" = "the korobokuru level-cap column: samurai 6, barbarian and yakuza 10, wu jen 7, bushi unlimited, monk-shukenja-sohei-kensai-ninja No (capture p. 16).",
    }, {
      "name" = "dgdT9Hengeyokai",
      "values" = { 0, 8, 0, 0, 6, 99, 9, 0, 0, 0 },
      "default" = -99,
      "comment" = "the hengeyokai level-cap column: shukenja 8, kensai 6, wu jen 9, bushi unlimited, the rest No (capture p. 16).",
    }, {
      "name" = "dgdT9Human",
      "values" = { 99, 99, 99, 99, 99, 99, 99, 17, 99, 99 },
      "default" = -99,
      "comment" = "the human level-cap column: unlimited in every class except the monk 17 cap (capture p. 16).",
    }, {
      "name" = "dgdT9SpiritFolk",
      "values" = { 12, 0, 0, 0, 9, 99, 0, 17, 0, 0 },
      "default" = -99,
      "comment" = "the spirit folk level-cap column: samurai 12, kensai 9, monk 17, bushi unlimited, the rest No (capture p. 16).",
    }, {
      "name" = "dgdT9Align",
      "values" = { 1, 2, 1, 3, 1, 4, 3, 1, 5, 1 },
      "default" = -99,
      "comment" = "the alignment tier column: lawful, good, non-lawful, any, non-good per the printed restrictions (capture p. 16).",
    }, {
      "name" = "dgdT10KoroMin",
      "values" = { 8, 6, 12, 3, 3, 3 },
      "default" = -99,
      "comment" = "the korobokuru minimum column: Str 8, Dex 6, Con 12, Int 3, Wis 3, Cha 3 (capture p. 16).",
    }, {
      "name" = "dgdT10KoroMax",
      "values" = { 19, 18, 19, 15, 17, 16 },
      "default" = -99,
      "comment" = "the korobokuru maximum column: Str 19, Dex 18, Con 19, Int 15, Wis 17, Cha 16 (capture p. 16).",
    }, {
      "name" = "dgdT10HengeMin",
      "values" = { 12, 9, 12, 12, 12, 12 },
      "default" = -99,
      "comment" = "the hengeyokai minimum column: Str 12, Dex 9, Con 12, Int 12, Wis 12, Cha 12 (capture p. 16).",
    }, {
      "name" = "dgdT10HengeMax",
      "values" = { 18, 18, 18, 18, 18, 17 },
      "default" = -99,
      "comment" = "the hengeyokai maximum column: Str 18, Dex 18, Con 18, Int 18, Wis 18, Cha 17 (capture p. 16).",
    }, {
      "name" = "dgdT10SpiritMin",
      "values" = { 6, 12, 6, 12, 9, 14 },
      "default" = -99,
      "comment" = "the spirit folk minimum column: Str 6, Dex 12, Con 6, Int 12, Wis 9, Cha 14 (capture p. 16).",
    }, {
      "name" = "dgdT10SpiritMax",
      "values" = { 18, 18, 14, 18, 18, 18 },
      "default" = -99,
      "comment" = "the spirit folk maximum column: Str 18, Dex 18, Con 14, Int 18, Wis 18, Cha 18 (capture p. 16).",
    }, {
      "name" = "dgdT12StrMin",
      "values" = { -1, 9, 12, 15, -1, 13, 9, 13, -1, 11 },
      "default" = -99,
      "comment" = "the Strength minimum column: bushi 9, kensai 12, monk 15, samurai 13, shukenja 9, sohei 13, yakuza 11 (capture p. 22).",
    }, {
      "name" = "dgdT12StrBonus",
      "values" = { -1, 14, -1, -1, -1, -1, -1, 15, -1, -1 },
      "default" = -99,
      "comment" = "the Strength bonus column: bushi 14, sohei 15 (capture p. 22).",
    }, {
      "name" = "dgdT12DexMin",
      "values" = { 14, 8, 14, 15, 14, -1, -1, -1, -1, 15 },
      "default" = -99,
      "comment" = "the Dexterity minimum column: barbarian 14, bushi 8, kensai 14, monk 15, ninja 14, yakuza 15 (capture p. 22).",
    }, {
      "name" = "dgdT12DexBonus",
      "values" = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      "default" = -99,
      "comment" = "the Dexterity bonus column: none printed (capture p. 22).",
    }, {
      "name" = "dgdT12ConMin",
      "values" = { 15, 8, -1, 11, -1, 13, 9, 10, -1, -1 },
      "default" = -99,
      "comment" = "the Constitution minimum column: barbarian 15, bushi 8, monk 11, samurai 13, shukenja 9, sohei 10 (capture p. 22).",
    }, {
      "name" = "dgdT12ConBonus",
      "values" = { -1, -1, -1, -1, -1, -1, 15, -1, -1, -1 },
      "default" = -99,
      "comment" = "the Constitution bonus column: shukenja 15 (capture p. 22).",
    }, {
      "name" = "dgdT12IntMin",
      "values" = { -1, -1, -1, -1, 15, 14, -1, -1, 13, 15 },
      "default" = -99,
      "comment" = "the Intelligence minimum column: ninja 15, samurai 14, wu jen 13, yakuza 15 (capture p. 22).",
    }, {
      "name" = "dgdT12IntBonus",
      "values" = { -1, -1, -1, -1, -1, -1, -1, -1, 15, -1 },
      "default" = -99,
      "comment" = "the Intelligence bonus column: wu jen 15 (capture p. 22).",
    }, {
      "name" = "dgdT12WisMin",
      "values" = { -1, -1, 12, 15, -1, 13, 12, 12, -1, -1 },
      "default" = -99,
      "comment" = "the Wisdom minimum column: kensai 12, monk 15, samurai 13, shukenja 12, sohei 12 (capture p. 22).",
    }, {
      "name" = "dgdT12WisBonus",
      "values" = { -1, -1, 14, -1, -1, -1, 15, 15, -1, -1 },
      "default" = -99,
      "comment" = "the Wisdom bonus column: kensai 14, shukenja 15, sohei 15 (capture p. 22).",
    }, {
      "name" = "dgdT12ChaMin",
      "values" = { -1, -1, -1, -1, 14, -1, -1, -1, -1, 13 },
      "default" = -99,
      "comment" = "the Charisma minimum column: ninja 14, yakuza 13 (capture p. 22).",
    }, {
      "name" = "dgdT12ChaBonus",
      "values" = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
      "default" = -99,
      "comment" = "the Charisma bonus column: none printed (capture p. 22).",
    }, {
      "name" = "dgdT13Armor",
      "values" = { 2, 1, 2, 0, 2, 2, 0, 0, 1, 1 },
      "default" = -99,
      "comment" = "the armor tier column: any (2) for samurai, sohei, barbarian, bushi; the leather class (1) for shukenja, ninja, yakuza; none (0) for kensai, wu jen, monk (capture pp. 22-23).",
    }, {
      "name" = "dgdT13Weapons",
      "values" = { 0, 2, 1, 0, 0, 0, 2, 2, 0, 0 },
      "default" = -99,
      "comment" = "the weapons mode column: any (0) for the six any-classes, any-but (1) for the sohei, named (2) for shukenja, wu jen, monk (capture pp. 22-23).",
    }, {
      "name" = "dgdT13ListCount",
      "values" = { 0, 16, 7, 0, 0, 0, 20, 16, 0, 0 },
      "default" = -99,
      "comment" = "the list-count column: the named-list and exclusion-list counts - shukenja 16, sohei 7, wu jen 20, monk 16, zero elsewhere (capture pp. 22-23).",
    }, {
      "name" = "dgdT13Oil",
      "values" = { 0, 1, 1, 1, 1, 1, 0, 0, 1, 1 },
      "default" = -99,
      "comment" = "the oil column: permitted (1) for every class except samurai, wu jen and monk (capture pp. 22-23).",
    }, {
      "name" = "dgdT13Poison",
      "values" = { 1, 0, 1, 2, 2, 2, 2, 2, 3, 3 },
      "default" = -99,
      "comment" = "the poison tier column: never (0) for shukenja, evil-only (1) for samurai and sohei, the DM option (2) for kensai, barbarian, bushi, wu jen and monk, yes (3) for ninja and yakuza (capture pp. 22-23).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgdT9RowCount']() != 10  or m['dgdT9Unlimited']() != 99  or m['dgdT9NotPermitted']() != 0  or m['dgdAlignLawful']() != 1  or m['dgdAlignGood']() != 2  or m['dgdAlignNonLaw']() != 3  or m['dgdAlignAny']() != 4  or m['dgdAlignNonGood']() != 5  or m['dgdT10RowCount']() != 6  or m['dgdT12RowCount']() != 10  or m['dgdT12None']() != -1  or m['dgdT13RowCount']() != 10  or m['dgdArmorNone']() != 0  or m['dgdArmorLeather']() != 1  or m['dgdArmorAny']() != 2  or m['dgdWeaponsAny']() != 0  or m['dgdWeaponsAnyBut']() != 1  or m['dgdWeaponsNamed']() != 2  or m['dgdPoisonNever']() != 0  or m['dgdPoisonEvilOnly']() != 1  or m['dgdPoisonDm']() != 2  or m['dgdPoisonYes']() != 3  or m['dgdShukenjaWeaponCount']() != 16  or m['dgdSoheiExclusionCount']() != 7  or m['dgdWuJenWeaponCount']() != 20  or m['dgdMonkWeaponCount']() != 16  or  m['dgdUnlimitedMeansAny']() != 1  or  m['dgdNumberMeansCap']() != 1  or  m['dgdWishOneAboveCap']() != 1  or  m['dgdAlignmentAllRaces']() != 1  or  m['dgdT10ExceptionalStr']() != 1  or  m['dgdT12BarbWisMax']() != 1  or  m['dgdT12ColonIsBonus']() != 1  or  m['dgdT13ShieldNone']() != 1  or  m['dgdT13SamuraiNinjaWeapons']() != 1  or  m['dgdT13SamuraiOilSiege']() != 1  or  m['dgdT13NinjaProficiencies']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgdUnlimitedMeansAny']() != 1",
      "note" = "the dgdUnlimitedMeansAny pin",
    }, {
      "expr" = "m['dgdNumberMeansCap']() != 1",
      "note" = "the dgdNumberMeansCap pin",
    }, {
      "expr" = "m['dgdWishOneAboveCap']() != 1",
      "note" = "the dgdWishOneAboveCap pin",
    }, {
      "expr" = "m['dgdAlignmentAllRaces']() != 1",
      "note" = "the dgdAlignmentAllRaces pin",
    }, {
      "expr" = "m['dgdT9RowCount']() != 10",
      "note" = "the dgdT9RowCount pin",
    }, {
      "expr" = "m['dgdT9Unlimited']() != 99",
      "note" = "the dgdT9Unlimited pin",
    }, {
      "expr" = "m['dgdT9NotPermitted']() != 0",
      "note" = "the dgdT9NotPermitted pin",
    }, {
      "expr" = "m['dgdAlignLawful']() != 1",
      "note" = "the dgdAlignLawful pin",
    }, {
      "expr" = "m['dgdAlignGood']() != 2",
      "note" = "the dgdAlignGood pin",
    }, {
      "expr" = "m['dgdAlignNonLaw']() != 3",
      "note" = "the dgdAlignNonLaw pin",
    }, {
      "expr" = "m['dgdAlignAny']() != 4",
      "note" = "the dgdAlignAny pin",
    }, {
      "expr" = "m['dgdAlignNonGood']() != 5",
      "note" = "the dgdAlignNonGood pin",
    }, {
      "expr" = "m['dgdT10RowCount']() != 6",
      "note" = "the dgdT10RowCount pin",
    }, {
      "expr" = "m['dgdT10ExceptionalStr']() != 1",
      "note" = "the dgdT10ExceptionalStr pin",
    }, {
      "expr" = "m['dgdT12RowCount']() != 10",
      "note" = "the dgdT12RowCount pin",
    }, {
      "expr" = "m['dgdT12None']() != -1",
      "note" = "the dgdT12None pin",
    }, {
      "expr" = "m['dgdT12BarbWisMax']() != 1",
      "note" = "the dgdT12BarbWisMax pin",
    }, {
      "expr" = "m['dgdT12ColonIsBonus']() != 1",
      "note" = "the dgdT12ColonIsBonus pin",
    }, {
      "expr" = "m['dgdT13RowCount']() != 10",
      "note" = "the dgdT13RowCount pin",
    }, {
      "expr" = "m['dgdArmorNone']() != 0",
      "note" = "the dgdArmorNone pin",
    }, {
      "expr" = "m['dgdArmorLeather']() != 1",
      "note" = "the dgdArmorLeather pin",
    }, {
      "expr" = "m['dgdArmorAny']() != 2",
      "note" = "the dgdArmorAny pin",
    }, {
      "expr" = "m['dgdWeaponsAny']() != 0",
      "note" = "the dgdWeaponsAny pin",
    }, {
      "expr" = "m['dgdWeaponsAnyBut']() != 1",
      "note" = "the dgdWeaponsAnyBut pin",
    }, {
      "expr" = "m['dgdWeaponsNamed']() != 2",
      "note" = "the dgdWeaponsNamed pin",
    }, {
      "expr" = "m['dgdPoisonNever']() != 0",
      "note" = "the dgdPoisonNever pin",
    }, {
      "expr" = "m['dgdPoisonEvilOnly']() != 1",
      "note" = "the dgdPoisonEvilOnly pin",
    }, {
      "expr" = "m['dgdPoisonDm']() != 2",
      "note" = "the dgdPoisonDm pin",
    }, {
      "expr" = "m['dgdPoisonYes']() != 3",
      "note" = "the dgdPoisonYes pin",
    }, {
      "expr" = "m['dgdShukenjaWeaponCount']() != 16",
      "note" = "the dgdShukenjaWeaponCount pin",
    }, {
      "expr" = "m['dgdSoheiExclusionCount']() != 7",
      "note" = "the dgdSoheiExclusionCount pin",
    }, {
      "expr" = "m['dgdWuJenWeaponCount']() != 20",
      "note" = "the dgdWuJenWeaponCount pin",
    }, {
      "expr" = "m['dgdMonkWeaponCount']() != 16",
      "note" = "the dgdMonkWeaponCount pin",
    }, {
      "expr" = "m['dgdT13ShieldNone']() != 1",
      "note" = "the dgdT13ShieldNone pin",
    }, {
      "expr" = "m['dgdT13SamuraiNinjaWeapons']() != 1",
      "note" = "the dgdT13SamuraiNinjaWeapons pin",
    }, {
      "expr" = "m['dgdT13SamuraiOilSiege']() != 1",
      "note" = "the dgdT13SamuraiOilSiege pin",
    }, {
      "expr" = "m['dgdT13NinjaProficiencies']() != 1",
      "note" = "the dgdT13NinjaProficiencies pin",
    }, {
      "expr" = "m['dgdT9Human'](7) != 17  or m['dgdT9SpiritFolk'](7) != 17",
      "note" = "the monk human and spirit folk 17 caps (capture p. 16)",
    }, {
      "expr" = "m['dgdT9Korobokuru'](5) != 99  or m['dgdT9Hengeyokai'](5) != 99  or m['dgdT9SpiritFolk'](5) != 99  or m['dgdT9Align'](5) != 4",
      "note" = "the bushi row is unlimited in every race and any alignment (capture p. 16)",
    }, {
      "expr" = "m['dgdT9SpiritFolk'](0) != 12  or m['dgdT9Korobokuru'](0) != 6",
      "note" = "the samurai spirit folk 12 and the korobokuru 6 caps (capture p. 16)",
    }, {
      "expr" = "m['dgdT12StrMin'](3) != 15  or m['dgdT12DexMin'](3) != 15  or m['dgdT12ConMin'](3) != 11  or m['dgdT12WisMin'](3) != 15",
      "note" = "the monk mins - Str 15 Dex 15 Con 11 Wis 15 (capture p. 22)",
    }, {
      "expr" = "m['dgdT12IntMin'](8) != 13  or m['dgdT12IntBonus'](8) != 15",
      "note" = "the wu jen Int 13:15 - the min and the bonus (capture p. 22)",
    }, {
      "expr" = "m['dgdT12StrMin'](7) != 13  or m['dgdT12StrBonus'](7) != 15",
      "note" = "the sohei Str 13:15 - the min and the bonus (capture p. 22)",
    }, {
      "expr" = "m['dgdT13Armor'](6) != 0  or m['dgdT13ListCount'](6) != 20  or m['dgdT13Oil'](6) != 0",
      "note" = "the wu jen row - no armor, the 20-item list, no oil (capture p. 23)",
    }, {
      "expr" = "m['dgdT13Armor'](8) != 1  or m['dgdT13Weapons'](8) != 0  or m['dgdT13Poison'](8) != 3",
      "note" = "the ninja row - the leather-class armor, any weapons, poison yes (capture p. 23)",
    }, {
      "expr" = "m['dgdT13ListCount'](1) !=m['dgdShukenjaWeaponCount']()  or m['dgdT13ListCount'](6) !=m['dgdWuJenWeaponCount']()  or m['dgdT13ListCount'](7) !=m['dgdMonkWeaponCount']()",
      "note" = "the list counts match the named-list consts (capture pp. 22-23)",
    }, {
      "expr" = "m['dgdT13ListCount'](2) !=m['dgdSoheiExclusionCount']()",
      "note" = "the sohei exclusion count rides the grid (capture p. 22)",
    }, {
      "expr" = "m['dgdT10KoroMin'](0) != 8 or m['dgdT10KoroMin'](1) != 6 or m['dgdT10KoroMin'](2) != 12 or m['dgdT10KoroMin'](3) != 3 or m['dgdT10KoroMin'](4) != 3 or m['dgdT10KoroMin'](5) != 3 or m['dgdT10KoroMin'](6) != -99 or m['dgdT10KoroMax'](0) != 19",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT10KoroMax'](1) != 18 or m['dgdT10KoroMax'](2) != 19 or m['dgdT10KoroMax'](3) != 15 or m['dgdT10KoroMax'](4) != 17 or m['dgdT10KoroMax'](5) != 16 or m['dgdT10KoroMax'](6) != -99 or m['dgdT10HengeMin'](0) != 12 or m['dgdT10HengeMin'](1) != 9",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT10HengeMin'](2) != 12 or m['dgdT10HengeMin'](3) != 12 or m['dgdT10HengeMin'](4) != 12 or m['dgdT10HengeMin'](5) != 12 or m['dgdT10HengeMin'](6) != -99 or m['dgdT10HengeMax'](0) != 18 or m['dgdT10HengeMax'](1) != 18 or m['dgdT10HengeMax'](2) != 18",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT10HengeMax'](3) != 18 or m['dgdT10HengeMax'](4) != 18 or m['dgdT10HengeMax'](5) != 17 or m['dgdT10HengeMax'](6) != -99 or m['dgdT10SpiritMin'](0) != 6 or m['dgdT10SpiritMin'](1) != 12 or m['dgdT10SpiritMin'](2) != 6 or m['dgdT10SpiritMin'](3) != 12",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT10SpiritMin'](4) != 9 or m['dgdT10SpiritMin'](5) != 14 or m['dgdT10SpiritMin'](6) != -99 or m['dgdT10SpiritMax'](0) != 18 or m['dgdT10SpiritMax'](1) != 18 or m['dgdT10SpiritMax'](2) != 14 or m['dgdT10SpiritMax'](3) != 18 or m['dgdT10SpiritMax'](4) != 18",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT10SpiritMax'](5) != 18 or m['dgdT10SpiritMax'](6) != -99 or m['dgdT12DexBonus'](0) != -1 or m['dgdT12DexBonus'](1) != -1 or m['dgdT12DexBonus'](2) != -1 or m['dgdT12DexBonus'](3) != -1 or m['dgdT12DexBonus'](4) != -1 or m['dgdT12DexBonus'](5) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12DexBonus'](6) != -1 or m['dgdT12DexBonus'](7) != -1 or m['dgdT12DexBonus'](8) != -1 or m['dgdT12DexBonus'](9) != -1 or m['dgdT12DexBonus'](10) != -99 or m['dgdT12ConBonus'](0) != -1 or m['dgdT12ConBonus'](1) != -1 or m['dgdT12ConBonus'](2) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12ConBonus'](3) != -1 or m['dgdT12ConBonus'](4) != -1 or m['dgdT12ConBonus'](5) != -1 or m['dgdT12ConBonus'](6) != 15 or m['dgdT12ConBonus'](7) != -1 or m['dgdT12ConBonus'](8) != -1 or m['dgdT12ConBonus'](9) != -1 or m['dgdT12ConBonus'](10) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12WisBonus'](0) != -1 or m['dgdT12WisBonus'](1) != -1 or m['dgdT12WisBonus'](2) != 14 or m['dgdT12WisBonus'](3) != -1 or m['dgdT12WisBonus'](4) != -1 or m['dgdT12WisBonus'](5) != -1 or m['dgdT12WisBonus'](6) != 15 or m['dgdT12WisBonus'](7) != 15",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12WisBonus'](8) != -1 or m['dgdT12WisBonus'](9) != -1 or m['dgdT12WisBonus'](10) != -99 or m['dgdT12ChaMin'](0) != -1 or m['dgdT12ChaMin'](1) != -1 or m['dgdT12ChaMin'](2) != -1 or m['dgdT12ChaMin'](3) != -1 or m['dgdT12ChaMin'](4) != 14",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12ChaMin'](5) != -1 or m['dgdT12ChaMin'](6) != -1 or m['dgdT12ChaMin'](7) != -1 or m['dgdT12ChaMin'](8) != -1 or m['dgdT12ChaMin'](9) != 13 or m['dgdT12ChaMin'](10) != -99 or m['dgdT12ChaBonus'](0) != -1 or m['dgdT12ChaBonus'](1) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12ChaBonus'](2) != -1 or m['dgdT12ChaBonus'](3) != -1 or m['dgdT12ChaBonus'](4) != -1 or m['dgdT12ChaBonus'](5) != -1 or m['dgdT12ChaBonus'](6) != -1 or m['dgdT12ChaBonus'](7) != -1 or m['dgdT12ChaBonus'](8) != -1 or m['dgdT12ChaBonus'](9) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgdT12ChaBonus'](10) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R617 OA class combos audit",
      "comment" = "OA round four (capture pp. 16-23): the Chapter 2 opener - the class and race combinations riders and the four combination tables: the class limits with the alignment tiers, the racial ability limits, the class ability minimums with the bonus columns, and the armor and weapons permissions with the weapon-list counts.",
    },
}
