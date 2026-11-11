-- oa639: promoted from rules/oa/oaequip.h (the EQUIPPING THE CHARACTER AND TABLE 47, printed capture pp. 76-78 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 639,
  "prefix" = "oa639",
  "banner" = {
      "title" = "EQUIPPING THE CHARACTER AND TABLE 47, printed capture pp. 76-78 - the OA",
      "provenance" = "equipment round census 561 -> 562.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. The equipping prose pins from capture p. 76 (printed p. 38) and the full Table 47 from capture pp. 77-78 (printed pp. 39-40); the T47 gap box label reads capture pp. 78-84 - the label is preserved byte-exact in the flip. The printed table carries TEN sections - the eight cost lists the box names plus the ARMOR and ARMS lists that ride the same table; all ten pin this round as 256 rows, each a cost-unit-star triple (the unit code 1 fen, 2 yuan, 3 tael, 4 ch'ien per the R636 T43 doctrine; the star flags pin the printed asterisks - the ten armor-piece rows, the chijiriki, the five ninja-preferred misc rows). No contested cells detected within the single source. OCR normalizations: the Kyoketsu-shogi \"(biaded rope)\" reads as bladed rope and the stray mid-table separator row after it is an OCR artifact pinning nothing. The Weapons chapter prose with Tables 48-49 (capture pp. 79-80) is deliberately left for the next round  the gap census after this round: 89 closed, 146 open - the Table 47 box flips (census 561 -> 562); NEXT - R640: the Weapons prose with Table 48 (Weapon Equivalents) and Table 49 (Weight and Damage by Weapon Type), capture pp. 79-80, the weapon equivalents doctrine, prefix dha (verify free), audit \"R640 OA weapons audit\", include after rules/oa/oaequip.h",
    },
  "consts" = { {
      "name" = "dgzT47RowCount",
      "value" = 256,
      "comment" = "Table 47 (capture pp. 77-78): the total row count across the ten printed sections",
    }, {
      "name" = "dgzT47ArmorCount",
      "value" = 28,
      "comment" = "Table 47 (capture pp. 77-78): the armor cost list row count",
    }, {
      "name" = "dgzT47ArmsCount",
      "value" = 76,
      "comment" = "Table 47 (capture pp. 77-78): the arms cost list row count",
    }, {
      "name" = "dgzT47ClothingCount",
      "value" = 22,
      "comment" = "Table 47 (capture pp. 77-78): the clothing cost list row count",
    }, {
      "name" = "dgzT47LivestockCount",
      "value" = 25,
      "comment" = "Table 47 (capture pp. 77-78): the livestock cost list row count",
    }, {
      "name" = "dgzT47MiscCount",
      "value" = 42,
      "comment" = "Table 47 (capture pp. 77-78): the misc cost list row count",
    }, {
      "name" = "dgzT47ProvisionsCount",
      "value" = 11,
      "comment" = "Table 47 (capture pp. 77-78): the provisions cost list row count",
    }, {
      "name" = "dgzT47ReligiousCount",
      "value" = 8,
      "comment" = "Table 47 (capture pp. 77-78): the religious cost list row count",
    }, {
      "name" = "dgzT47ServicesCount",
      "value" = 15,
      "comment" = "Table 47 (capture pp. 77-78): the services cost list row count",
    }, {
      "name" = "dgzT47TackCount",
      "value" = 16,
      "comment" = "Table 47 (capture pp. 77-78): the tack cost list row count",
    }, {
      "name" = "dgzT47TransportCount",
      "value" = 13,
      "comment" = "Table 47 (capture pp. 77-78): the transport cost list row count",
    } },
  "bools" = { {
      "name" = "dgzEquipAfterCreation",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): after a character is created it is important to equip him - without equipment the character is at a great disadvantage",
    }, {
      "name" = "dgzEquipAdventuringReason",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): initially the character is not likely to get everything he wants - not enough money - which is not bad, since it provides the perfect reason to adventure",
    }, {
      "name" = "dgzEquipEstablishedPrices",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): the prices given are figured using established currency",
    }, {
      "name" = "dgzEquipBarterPurchase",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): characters can also purchase the equipment through barter units, using the barter-unit values already given",
    }, {
      "name" = "dgzEquipIncompleteList",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): the equipment list is by no means complete - it covers the items most frequently used, and the DM can freely add items if needed",
    }, {
      "name" = "dgzEquipPriceChange",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): the DM can change the price of any item for sound campaign reasons - scarcity, quality of workmanship",
    }, {
      "name" = "dgzEquipAvailability",
      "value" = true,
      "comment" = "equipping prose (capture p. 76): the DM can rule items unavailable in areas of Kara-Tur - such items obviously cannot be purchased",
    }, {
      "name" = "dgzT47ArmorPieceNote",
      "value" = true,
      "comment" = "T47 armor footnote (capture p. 77): the asterisk marks an armor piece, not a complete suit",
    }, {
      "name" = "dgzT47NinjaPrefNote",
      "value" = true,
      "comment" = "T47 misc footnote (capture p. 78): the asterisked items are preferred by ninja",
    } },
  "switches" = { {
      "name" = "dgzT47ArmorCost",
      "values" = { 5, 5, 5, 5, 1, 1, 1, 5, 2, 3, 2, 8, 2, 1, 5, 8, 2, 20, 1, 1, 4, 2, 2, 30, 8, 4, 4, 5 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Banded, 1 Buckler, 2 Chain, 3 Do-maru, 4 Haidate, 5 Hanburi, 6 Hara-ate, 7 Hara-ate-gawa, 8 Haramaki, 9 Haramaki-do, 10 Helmet, small, 11 Hide, 12 Horo, 13 Jingasa (war hat), 14 Kabuto (great helm), 15 Kote (armored sleeves), 16 Leather, 17 O-yoroi (great armor), 18 Padded, 19 Ring, 20 Scale, leather, 21 Scale, metal, 22 Shield, large, 23 Shield, medium, 24 Sode, pair, 25 Splinted, 26 Studded, 27 Sune-ate (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ArmorUnit",
      "values" = { 4, 2, 4, 4, 4, 3, 4, 3, 4, 4, 3, 3, 3, 3, 4, 3, 3, 4, 3, 4, 3, 4, 3, 2, 3, 4, 3, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ArmorStar",
      "values" = { 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47ArmsCost",
      "values" = { 5, 10, 10, 1, 2, 5, 2, 2, 2, 6, 1, 5, 10, 6, 3, 8, 6, 1, 10, 1, 8, 1, 4, 1, 1, 1, 10, 1, 1, 10, 1, 5, 50, 1, 3, 1, 7, 3, 6, 2, 6, 8, 3, 3, 4, 1, 15, 5, 1, 1, 10, 1, 2, 5, 7, 4, 1, 6, 2, 2, 5, 10, 5, 3, 4, 6, 3, 2, 5, 2, 2, 5, 5, 3, 6, 1 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Arrow, armor piercer, 1 Arrow, frog crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow, normal, 5 Axe, battle, 6 Axe, hand or throwing, 7 Blowpipe, 8 Bo stick, 9 Boku-toh (wooden sword), 10 Bow, composite short, 11 Bow, short, 12 Chain, 13 Chijiriki (spear & chain), 14 Chu-ko-nu (repeating crossbow), 15 Crossbow, heavy, 16 Crossbow, light, 17 Dagger, 18 Daikyu (great bow), 19 Dart, blowpipe, 20 Dart, thrown, 21 Fang (good), 22 Gunsen (iron fan), 23 Halberd, 24 Hankyu (little bow), 25 Javelin, 26 Jitte, 27 Jo stick, 28 Kama (sickle), 29 Katana & scabbard, 30 Kau sin ke (whipping chain), 31 Kawanaga (grappling hook), 32 Kiseru (iron pipe), 33 Kumade (climbing rake), 34 Kusari-gama (sickle & chain), 35 Kyoketsu-shogi (bladed rope), 36 Lajatang, 37 Lance (light horse), 38 Man catcher, 39 Metsubishi (pepper blower), 40 Nagimaki (horseman's glaive), 41 Naginata (footman's glaive), 42 Needle, 43 Nekode, pair (climbing claws), 44 Ninja-to & scabbard (sword), 45 Nunchaku, 46 Parang (machete), 47 Pellet bow, 48 Quarrel, single, 49 Quarrel, two dozen, 50 Sai, 51 Sang kauw, 52 Shaken, 53 Shakujo yari (concealed spear), 54 Shikomi-zu, 55 Shuriken, spike, 56 Shuriken, star, large, 57 Shuriken, star, small, 58 Siangkam (metal arrow), 59 Sling, 60 Sling, staff, 61 Sling/pellet bow bullets, score, 62 Sode garami (sleeve entangler), 63 Spear, 64 Sword, broad & scabbard, 65 Sword, long & scabbard, 66 Sword, short & scabbard, 67 Sword, two-handed, 68 Tetsu-bishi (caltrops), 69 Tetsubo (iron staff), 70 Three-piece rod, 71 Trident, 72 Tui-fa, 73 Uchi-ne (small javelin), 74 Wakizashi & scabbard (short sword), 75 Whip (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ArmsUnit",
      "values" = { 2, 2, 2, 3, 2, 3, 3, 2, 1, 2, 4, 3, 2, 3, 4, 3, 3, 3, 4, 1, 2, 3, 3, 4, 4, 3, 2, 1, 3, 4, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 2, 3, 2, 3, 2, 4, 3, 3, 3, 2, 3, 2, 3, 2, 2, 2, 3, 3, 3, 3, 3, 4, 2, 3, 3, 3, 2, 2, 4, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ArmsStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47ClothingCost",
      "values" = { 5, 3, 8, 1, 4, 5, 2, 1, 1, 4, 1, 2, 3, 3, 4, 1, 5, 3, 1, 2, 2, 1 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Boots, high hard, 1 Boots, high soft, 2 Cap, 3 Cloak, cloth, 4 Cloak, fur, 5 Gloves, 6 Hat, fur, 7 Hat, straw, 8 Loincloth, 9 Outer robe (ho, happi), 10 Raincape, straw (mino), 11 Robe, cotton (kosode, kimono), 12 Robe, fur trimmed, 13 Robe, silk (kosode), 14 Sandals, 15 Sash or belt (obi), 16 Tabi (boot/sock), 17 Trousers, cotton (hakama), 18 Trousers, woolen, 19 Turban, 20 Vest, fur, 21 Vest, silk (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ClothingUnit",
      "values" = { 2, 2, 1, 3, 3, 2, 2, 1, 1, 2, 2, 2, 3, 3, 1, 2, 2, 2, 3, 2, 3, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ClothingStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47LivestockCost",
      "values" = { 5, 2, 3, 1, 5, 3, 8, 1, 5, 50, 2, 5, 5, 20, 15, 5, 25, 3, 2, 8, 1, 2, 6, 15, 2 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Canary, 1 Cat, 2 Chicken or rooster, 3 Cricket, lighting, 4 Dog, guard, 5 Dog, hunting, 6 Dog, lap, 7 Donkey, 8 Dove, 9 Elephant, war, 10 Fish, ornamental, 11 Goat, 12 Hawk, fledgling, 13 Hawk, trained, 14 Horse, draft, 15 Horse, heavy war, 16 Horse, light war, 17 Horse, medium war, 18 Horse, riding (light), 19 Monkey, 20 Nightingale, 21 Ox, 22 Peacock, 23 Pony, riding, 24 Pony, war (capture pp. 77-78).",
    }, {
      "name" = "dgzT47LivestockUnit",
      "values" = { 3, 2, 1, 3, 3, 3, 3, 4, 3, 4, 3, 3, 4, 4, 3, 4, 3, 4, 4, 3, 4, 4, 3, 3, 4 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47LivestockStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47MiscCost",
      "values" = { 5, 4, 2, 1, 3, 5, 3, 30, 1, 6, 4, 1, 3, 2, 10, 3, 1, 1, 2, 1, 10, 3, 5, 2, 1, 3, 4, 6, 1, 10, 5, 1, 2, 1, 2, 1, 1, 8, 5, 1, 10, 1 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Backpack, wicker, 1 Basket, large, 2 Basket, small, 3 Blanket, coarse, 4 Candle, tallow, 5 Chest, Armor, 6 Chest, common wooden, large, 7 Chest, common wooden, small, 8 Chest, quality, large, 9 Chest, quality, small, 10 Chopsticks, lacquered, 11 Cloth, cotton bolt, 12 Cloth, silk bolt, 13 Cord, 10 ft, 14 Eggshell grenade, dust, 15 Eggshell grenade, flashpowder, 16 Eggshell grenade, pepper, 17 Eggshell grenade, poison smoke, 18 Fishhook, 19 Fishing net, 10 ft, 20 Goza (straw mat), 21 Ink, brush, and inking stone, 22 Lantern, hooded, 23 Lantern, paper, 24 Mirror, small metal, 25 Oil, flask of, 26 Paper, writing, 10 sheets, 27 Pot, iron, 28 Quiver, 2 dozen arrows cap, 29 Rope, hemp 50 ft, 30 Rope, silk 50 ft, 31 Signal rocket, 32 Standard, flag, sashimono, 33 Sword stand, 34 Tent, large, 35 Tent, small, 36 Thieves picks and tools, 37 Tinder box, flint and steel, 38 Tobacco pipe, 39 Tobacco, 1 lb, 40 Tool, common, 41 Torch (capture pp. 77-78).",
    }, {
      "name" = "dgzT47MiscUnit",
      "values" = { 2, 2, 2, 2, 1, 3, 3, 2, 4, 3, 2, 4, 4, 1, 2, 3, 3, 4, 2, 3, 2, 3, 3, 3, 4, 2, 3, 2, 3, 2, 4, 3, 3, 4, 3, 3, 4, 2, 2, 3, 3, 1 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47MiscStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47ProvisionsCost",
      "values" = { 2, 1, 1, 4, 2, 10, 10, 5, 15, 5, 1 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Beer, jar, 1 Food, banquet, 2 Food, common meal, 3 Food, exotic, 4 Food, poor, 5 Grain, horse 1 day, 6 Pepper/spices, 1 lb, 7 Rice, koku, 8 Ricecake, 1 week rations, 9 Sake, jar, 10 Tea, 1 lb (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ProvisionsUnit",
      "values" = { 2, 3, 2, 3, 1, 2, 2, 4, 2, 2, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ProvisionsStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47ReligiousCost",
      "values" = { 1, 3, 50, 1, 3, 1, 1, 3 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Beads, prayer, 1 Bell, small, 2 Bell, temple, 3 Gong, 4 Incense, stick, 5 Paper, prayer strip, 6 Symbol, holy (unholy), 7 Wheel, prayer (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ReligiousUnit",
      "values" = { 2, 2, 4, 4, 1, 1, 3, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ReligiousStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47ServicesCost",
      "values" = { 3, 5, 10, 7, 2, 3, 6, 1, 4, 6, 2, 1, 3, 5, 3 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Acrobats, per performance, 1 Actors, per performance, 2 Chef, per banquet, 3 Clerk, per month, 4 Courier, per day, 5 Dancers, per performance, 6 Gardener, per month, 7 Lantern bearer, 8 Lodging, common or small village, 9 Lodging, good inn, 10 Messenger, in town, 11 Mourners, 12 Musician, per performance, 13 Servant, one month, 14 Stabling, one night (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ServicesUnit",
      "values" = { 2, 2, 2, 3, 2, 2, 3, 1, 1, 1, 1, 1, 2, 3, 1 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47ServicesStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47TackCost",
      "values" = { 10, 20, 2, 5, 1, 8, 2, 15, 4, 5, 3, 1, 15, 1, 5, 8 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Barding, half chain, 1 Barding, elephant, leather, 2 Barding, full leather or padded, 3 Barding, half brigandine, 4 Barding, half padded, 5 Barding, half metal scale, 6 Bit and bridle, 7 Harness and feed bag, 8 Horse yoke, 9 Howdah, 10 Ox yoke, 11 Saddle bags, large, 12 Saddle bags, small, 13 Saddle blanket, 14 Saddle, pack, 15 Saddle, riding (capture pp. 77-78).",
    }, {
      "name" = "dgzT47TackUnit",
      "values" = { 4, 4, 4, 4, 4, 4, 3, 2, 3, 4, 3, 3, 2, 2, 3, 3 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47TackStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    }, {
      "name" = "dgzT47TransportCost",
      "values" = { 300, 100, 20, 3, 8, 50, 100, 500, 300, 800, 5, 5, 20 },
      "default" = -99,
      "comment" = "the printed cost value by row - 0 Barge, large, 1 Barge, small, 2 Boat, 3 Canoe, small, 4 Canoe, war, 5 Chariot, riding, 6 Chariot, war, 7 Junk, large, 8 Junk, small, 9 Junk, war, 10 Ox cart, 11 Palanquin, 12 Wagon (capture pp. 77-78).",
    }, {
      "name" = "dgzT47TransportUnit",
      "values" = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
      "default" = -99,
      "comment" = "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).",
    }, {
      "name" = "dgzT47TransportStar",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere.",
    } },
  "tables" = { {
      "name" = "dgzT47ArmorGrid",
      "tag" = "T47Armor",
      "count" = "dgzT47ArmorCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ArmorCost", "dgzT47ArmorUnit", "dgzT47ArmorStar" },
      "data" = { { 5, 4, 0 }, { 5, 2, 0 }, { 5, 4, 0 }, { 5, 4, 1 }, { 1, 4, 1 }, { 1, 3, 0 }, { 1, 4, 1 }, { 5, 3, 1 }, { 2, 4, 1 }, { 3, 4, 1 }, { 2, 3, 0 }, { 8, 3, 0 }, { 2, 3, 1 }, { 1, 3, 0 }, { 5, 4, 0 }, { 8, 3, 1 }, { 2, 3, 0 }, { 20, 4, 0 }, { 1, 3, 0 }, { 1, 4, 0 }, { 4, 3, 0 }, { 2, 4, 0 }, { 2, 3, 0 }, { 30, 2, 0 }, { 8, 3, 1 }, { 4, 4, 0 }, { 4, 3, 0 }, { 5, 3, 1 } },
      "comment" = "the Table 47 armor cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Banded, 1 Buckler, 2 Chain, 3 Do-maru, 4 Haidate, 5 Hanburi, 6 Hara-ate, 7 Hara-ate-gawa, 8 Haramaki, 9 Haramaki-do, 10 Helmet, small, 11 Hide, 12 Horo, 13 Jingasa (war hat), 14 Kabuto (great helm), 15 Kote (armored sleeves), 16 Leather, 17 O-yoroi (great armor), 18 Padded, 19 Ring, 20 Scale, leather, 21 Scale, metal, 22 Shield, large, 23 Shield, medium, 24 Sode, pair, 25 Splinted, 26 Studded, 27 Sune-ate (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 armor grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47ArmsGrid",
      "tag" = "T47Arms",
      "count" = "dgzT47ArmsCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ArmsCost", "dgzT47ArmsUnit", "dgzT47ArmsStar" },
      "data" = { { 5, 2, 0 }, { 10, 2, 0 }, { 10, 2, 0 }, { 1, 3, 0 }, { 2, 2, 0 }, { 5, 3, 0 }, { 2, 3, 0 }, { 2, 2, 0 }, { 2, 1, 0 }, { 6, 2, 0 }, { 1, 4, 0 }, { 5, 3, 0 }, { 10, 2, 0 }, { 6, 3, 1 }, { 3, 4, 0 }, { 8, 3, 0 }, { 6, 3, 0 }, { 1, 3, 0 }, { 10, 4, 0 }, { 1, 1, 0 }, { 8, 2, 0 }, { 1, 3, 0 }, { 4, 3, 0 }, { 1, 4, 0 }, { 1, 4, 0 }, { 1, 3, 0 }, { 10, 2, 0 }, { 1, 1, 0 }, { 1, 3, 0 }, { 10, 4, 0 }, { 1, 3, 0 }, { 5, 2, 0 }, { 50, 2, 0 }, { 1, 3, 0 }, { 3, 3, 0 }, { 1, 3, 0 }, { 7, 3, 0 }, { 3, 3, 0 }, { 6, 3, 0 }, { 2, 3, 0 }, { 6, 3, 0 }, { 8, 3, 0 }, { 3, 1, 0 }, { 3, 3, 0 }, { 4, 3, 0 }, { 1, 3, 0 }, { 15, 2, 0 }, { 5, 3, 0 }, { 1, 2, 0 }, { 1, 3, 0 }, { 10, 2, 0 }, { 1, 4, 0 }, { 2, 3, 0 }, { 5, 3, 0 }, { 7, 3, 0 }, { 4, 2, 0 }, { 1, 3, 0 }, { 6, 2, 0 }, { 2, 3, 0 }, { 2, 2, 0 }, { 5, 2, 0 }, { 10, 2, 0 }, { 5, 3, 0 }, { 3, 3, 0 }, { 4, 3, 0 }, { 6, 3, 0 }, { 3, 3, 0 }, { 2, 4, 0 }, { 5, 2, 0 }, { 2, 3, 0 }, { 2, 3, 0 }, { 5, 3, 0 }, { 5, 2, 0 }, { 3, 2, 0 }, { 6, 4, 0 }, { 1, 3, 0 } },
      "comment" = "the Table 47 arms cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Arrow, armor piercer, 1 Arrow, frog crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow, normal, 5 Axe, battle, 6 Axe, hand or throwing, 7 Blowpipe, 8 Bo stick, 9 Boku-toh (wooden sword), 10 Bow, composite short, 11 Bow, short, 12 Chain, 13 Chijiriki (spear & chain), 14 Chu-ko-nu (repeating crossbow), 15 Crossbow, heavy, 16 Crossbow, light, 17 Dagger, 18 Daikyu (great bow), 19 Dart, blowpipe, 20 Dart, thrown, 21 Fang (good), 22 Gunsen (iron fan), 23 Halberd, 24 Hankyu (little bow), 25 Javelin, 26 Jitte, 27 Jo stick, 28 Kama (sickle), 29 Katana & scabbard, 30 Kau sin ke (whipping chain), 31 Kawanaga (grappling hook), 32 Kiseru (iron pipe), 33 Kumade (climbing rake), 34 Kusari-gama (sickle & chain), 35 Kyoketsu-shogi (bladed rope), 36 Lajatang, 37 Lance (light horse), 38 Man catcher, 39 Metsubishi (pepper blower), 40 Nagimaki (horseman's glaive), 41 Naginata (footman's glaive), 42 Needle, 43 Nekode, pair (climbing claws), 44 Ninja-to & scabbard (sword), 45 Nunchaku, 46 Parang (machete), 47 Pellet bow, 48 Quarrel, single, 49 Quarrel, two dozen, 50 Sai, 51 Sang kauw, 52 Shaken, 53 Shakujo yari (concealed spear), 54 Shikomi-zu, 55 Shuriken, spike, 56 Shuriken, star, large, 57 Shuriken, star, small, 58 Siangkam (metal arrow), 59 Sling, 60 Sling, staff, 61 Sling/pellet bow bullets, score, 62 Sode garami (sleeve entangler), 63 Spear, 64 Sword, broad & scabbard, 65 Sword, long & scabbard, 66 Sword, short & scabbard, 67 Sword, two-handed, 68 Tetsu-bishi (caltrops), 69 Tetsubo (iron staff), 70 Three-piece rod, 71 Trident, 72 Tui-fa, 73 Uchi-ne (small javelin), 74 Wakizashi & scabbard (short sword), 75 Whip (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 arms grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47ClothingGrid",
      "tag" = "T47Clothing",
      "count" = "dgzT47ClothingCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ClothingCost", "dgzT47ClothingUnit", "dgzT47ClothingStar" },
      "data" = { { 5, 2, 0 }, { 3, 2, 0 }, { 8, 1, 0 }, { 1, 3, 0 }, { 4, 3, 0 }, { 5, 2, 0 }, { 2, 2, 0 }, { 1, 1, 0 }, { 1, 1, 0 }, { 4, 2, 0 }, { 1, 2, 0 }, { 2, 2, 0 }, { 3, 3, 0 }, { 3, 3, 0 }, { 4, 1, 0 }, { 1, 2, 0 }, { 5, 2, 0 }, { 3, 2, 0 }, { 1, 3, 0 }, { 2, 2, 0 }, { 2, 3, 0 }, { 1, 3, 0 } },
      "comment" = "the Table 47 clothing cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Boots, high hard, 1 Boots, high soft, 2 Cap, 3 Cloak, cloth, 4 Cloak, fur, 5 Gloves, 6 Hat, fur, 7 Hat, straw, 8 Loincloth, 9 Outer robe (ho, happi), 10 Raincape, straw (mino), 11 Robe, cotton (kosode, kimono), 12 Robe, fur trimmed, 13 Robe, silk (kosode), 14 Sandals, 15 Sash or belt (obi), 16 Tabi (boot/sock), 17 Trousers, cotton (hakama), 18 Trousers, woolen, 19 Turban, 20 Vest, fur, 21 Vest, silk (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 clothing grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47LivestockGrid",
      "tag" = "T47Livestock",
      "count" = "dgzT47LivestockCount",
      "sentinel" = -99,
      "cols" = { "dgzT47LivestockCost", "dgzT47LivestockUnit", "dgzT47LivestockStar" },
      "data" = { { 5, 3, 0 }, { 2, 2, 0 }, { 3, 1, 0 }, { 1, 3, 0 }, { 5, 3, 0 }, { 3, 3, 0 }, { 8, 3, 0 }, { 1, 4, 0 }, { 5, 3, 0 }, { 50, 4, 0 }, { 2, 3, 0 }, { 5, 3, 0 }, { 5, 4, 0 }, { 20, 4, 0 }, { 15, 3, 0 }, { 5, 4, 0 }, { 25, 3, 0 }, { 3, 4, 0 }, { 2, 4, 0 }, { 8, 3, 0 }, { 1, 4, 0 }, { 2, 4, 0 }, { 6, 3, 0 }, { 15, 3, 0 }, { 2, 4, 0 } },
      "comment" = "the Table 47 livestock cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Canary, 1 Cat, 2 Chicken or rooster, 3 Cricket, lighting, 4 Dog, guard, 5 Dog, hunting, 6 Dog, lap, 7 Donkey, 8 Dove, 9 Elephant, war, 10 Fish, ornamental, 11 Goat, 12 Hawk, fledgling, 13 Hawk, trained, 14 Horse, draft, 15 Horse, heavy war, 16 Horse, light war, 17 Horse, medium war, 18 Horse, riding (light), 19 Monkey, 20 Nightingale, 21 Ox, 22 Peacock, 23 Pony, riding, 24 Pony, war (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 livestock grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47MiscGrid",
      "tag" = "T47Misc",
      "count" = "dgzT47MiscCount",
      "sentinel" = -99,
      "cols" = { "dgzT47MiscCost", "dgzT47MiscUnit", "dgzT47MiscStar" },
      "data" = { { 5, 2, 0 }, { 4, 2, 0 }, { 2, 2, 0 }, { 1, 2, 0 }, { 3, 1, 0 }, { 5, 3, 0 }, { 3, 3, 0 }, { 30, 2, 0 }, { 1, 4, 0 }, { 6, 3, 0 }, { 4, 2, 0 }, { 1, 4, 0 }, { 3, 4, 0 }, { 2, 1, 0 }, { 10, 2, 1 }, { 3, 3, 1 }, { 1, 3, 1 }, { 1, 4, 1 }, { 2, 2, 0 }, { 1, 3, 0 }, { 10, 2, 0 }, { 3, 3, 0 }, { 5, 3, 0 }, { 2, 3, 0 }, { 1, 4, 0 }, { 3, 2, 0 }, { 4, 3, 0 }, { 6, 2, 0 }, { 1, 3, 0 }, { 10, 2, 0 }, { 5, 4, 1 }, { 1, 3, 0 }, { 2, 3, 0 }, { 1, 4, 0 }, { 2, 3, 0 }, { 1, 3, 0 }, { 1, 4, 0 }, { 8, 2, 0 }, { 5, 2, 0 }, { 1, 3, 0 }, { 10, 3, 0 }, { 1, 1, 0 } },
      "comment" = "the Table 47 misc cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Backpack, wicker, 1 Basket, large, 2 Basket, small, 3 Blanket, coarse, 4 Candle, tallow, 5 Chest, Armor, 6 Chest, common wooden, large, 7 Chest, common wooden, small, 8 Chest, quality, large, 9 Chest, quality, small, 10 Chopsticks, lacquered, 11 Cloth, cotton bolt, 12 Cloth, silk bolt, 13 Cord, 10 ft, 14 Eggshell grenade, dust, 15 Eggshell grenade, flashpowder, 16 Eggshell grenade, pepper, 17 Eggshell grenade, poison smoke, 18 Fishhook, 19 Fishing net, 10 ft, 20 Goza (straw mat), 21 Ink, brush, and inking stone, 22 Lantern, hooded, 23 Lantern, paper, 24 Mirror, small metal, 25 Oil, flask of, 26 Paper, writing, 10 sheets, 27 Pot, iron, 28 Quiver, 2 dozen arrows cap, 29 Rope, hemp 50 ft, 30 Rope, silk 50 ft, 31 Signal rocket, 32 Standard, flag, sashimono, 33 Sword stand, 34 Tent, large, 35 Tent, small, 36 Thieves picks and tools, 37 Tinder box, flint and steel, 38 Tobacco pipe, 39 Tobacco, 1 lb, 40 Tool, common, 41 Torch (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 misc grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47ProvisionsGrid",
      "tag" = "T47Provisions",
      "count" = "dgzT47ProvisionsCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ProvisionsCost", "dgzT47ProvisionsUnit", "dgzT47ProvisionsStar" },
      "data" = { { 2, 2, 0 }, { 1, 3, 0 }, { 1, 2, 0 }, { 4, 3, 0 }, { 2, 1, 0 }, { 10, 2, 0 }, { 10, 2, 0 }, { 5, 4, 0 }, { 15, 2, 0 }, { 5, 2, 0 }, { 1, 3, 0 } },
      "comment" = "the Table 47 provisions cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Beer, jar, 1 Food, banquet, 2 Food, common meal, 3 Food, exotic, 4 Food, poor, 5 Grain, horse 1 day, 6 Pepper/spices, 1 lb, 7 Rice, koku, 8 Ricecake, 1 week rations, 9 Sake, jar, 10 Tea, 1 lb (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 provisions grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47ReligiousGrid",
      "tag" = "T47Religious",
      "count" = "dgzT47ReligiousCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ReligiousCost", "dgzT47ReligiousUnit", "dgzT47ReligiousStar" },
      "data" = { { 1, 2, 0 }, { 3, 2, 0 }, { 50, 4, 0 }, { 1, 4, 0 }, { 3, 1, 0 }, { 1, 1, 0 }, { 1, 3, 0 }, { 3, 3, 0 } },
      "comment" = "the Table 47 religious cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Beads, prayer, 1 Bell, small, 2 Bell, temple, 3 Gong, 4 Incense, stick, 5 Paper, prayer strip, 6 Symbol, holy (unholy), 7 Wheel, prayer (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 religious grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47ServicesGrid",
      "tag" = "T47Services",
      "count" = "dgzT47ServicesCount",
      "sentinel" = -99,
      "cols" = { "dgzT47ServicesCost", "dgzT47ServicesUnit", "dgzT47ServicesStar" },
      "data" = { { 3, 2, 0 }, { 5, 2, 0 }, { 10, 2, 0 }, { 7, 3, 0 }, { 2, 2, 0 }, { 3, 2, 0 }, { 6, 3, 0 }, { 1, 1, 0 }, { 4, 1, 0 }, { 6, 1, 0 }, { 2, 1, 0 }, { 1, 1, 0 }, { 3, 2, 0 }, { 5, 3, 0 }, { 3, 1, 0 } },
      "comment" = "the Table 47 services cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Acrobats, per performance, 1 Actors, per performance, 2 Chef, per banquet, 3 Clerk, per month, 4 Courier, per day, 5 Dancers, per performance, 6 Gardener, per month, 7 Lantern bearer, 8 Lodging, common or small village, 9 Lodging, good inn, 10 Messenger, in town, 11 Mourners, 12 Musician, per performance, 13 Servant, one month, 14 Stabling, one night (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 services grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47TackGrid",
      "tag" = "T47Tack",
      "count" = "dgzT47TackCount",
      "sentinel" = -99,
      "cols" = { "dgzT47TackCost", "dgzT47TackUnit", "dgzT47TackStar" },
      "data" = { { 10, 4, 0 }, { 20, 4, 0 }, { 2, 4, 0 }, { 5, 4, 0 }, { 1, 4, 0 }, { 8, 4, 0 }, { 2, 3, 0 }, { 15, 2, 0 }, { 4, 3, 0 }, { 5, 4, 0 }, { 3, 3, 0 }, { 1, 3, 0 }, { 15, 2, 0 }, { 1, 2, 0 }, { 5, 3, 0 }, { 8, 3, 0 } },
      "comment" = "the Table 47 tack cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Barding, half chain, 1 Barding, elephant, leather, 2 Barding, full leather or padded, 3 Barding, half brigandine, 4 Barding, half padded, 5 Barding, half metal scale, 6 Bit and bridle, 7 Harness and feed bag, 8 Horse yoke, 9 Howdah, 10 Ox yoke, 11 Saddle bags, large, 12 Saddle bags, small, 13 Saddle blanket, 14 Saddle, pack, 15 Saddle, riding (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 tack grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    }, {
      "name" = "dgzT47TransportGrid",
      "tag" = "T47Transport",
      "count" = "dgzT47TransportCount",
      "sentinel" = -99,
      "cols" = { "dgzT47TransportCost", "dgzT47TransportUnit", "dgzT47TransportStar" },
      "data" = { { 300, 4, 0 }, { 100, 4, 0 }, { 20, 4, 0 }, { 3, 4, 0 }, { 8, 4, 0 }, { 50, 4, 0 }, { 100, 4, 0 }, { 500, 4, 0 }, { 300, 4, 0 }, { 800, 4, 0 }, { 5, 4, 0 }, { 5, 4, 0 }, { 20, 4, 0 } },
      "comment" = "the Table 47 transport cost list (capture pp. 77-78)",
      "col_comments" = { "the printed cost value by row - 0 Barge, large, 1 Barge, small, 2 Boat, 3 Canoe, small, 4 Canoe, war, 5 Chariot, riding, 6 Chariot, war, 7 Junk, large, 8 Junk, small, 9 Junk, war, 10 Ox cart, 11 Palanquin, 12 Wagon (capture pp. 77-78).", "the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636 T43 coin values (capture pp. 77-78).", "1 marks the printed asterisk rows - the footnote read (capture pp. 77-78); 0 elsewhere." },
      "audit_comment" = "the Table 47 transport grid: cost, unit, star (capture pp. 77-78)",
      "sentinel_census" = { 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dgzT47RowCount']() != 256  or m['dgzT47ArmorCount']() != 28  or m['dgzT47ArmsCount']() != 76  or m['dgzT47ClothingCount']() != 22  or m['dgzT47LivestockCount']() != 25  or m['dgzT47MiscCount']() != 42  or m['dgzT47ProvisionsCount']() != 11  or m['dgzT47ReligiousCount']() != 8  or m['dgzT47ServicesCount']() != 15  or m['dgzT47TackCount']() != 16  or m['dgzT47TransportCount']() != 13  or  m['dgzEquipAfterCreation']() != 1  or  m['dgzEquipAdventuringReason']() != 1  or  m['dgzEquipEstablishedPrices']() != 1  or  m['dgzEquipBarterPurchase']() != 1  or  m['dgzEquipIncompleteList']() != 1  or  m['dgzEquipPriceChange']() != 1  or  m['dgzEquipAvailability']() != 1  or  m['dgzT47ArmorPieceNote']() != 1  or  m['dgzT47NinjaPrefNote']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dgzT47RowCount']() != 256",
      "note" = "the T47 total row count pin",
    }, {
      "expr" = "m['dgzT47ArmorCount']() != 28",
      "note" = "the armor count pin",
    }, {
      "expr" = "m['dgzT47ArmsCount']() != 76",
      "note" = "the arms count pin",
    }, {
      "expr" = "m['dgzT47ClothingCount']() != 22",
      "note" = "the clothing count pin",
    }, {
      "expr" = "m['dgzT47LivestockCount']() != 25",
      "note" = "the livestock count pin",
    }, {
      "expr" = "m['dgzT47MiscCount']() != 42",
      "note" = "the misc count pin",
    }, {
      "expr" = "m['dgzT47ProvisionsCount']() != 11",
      "note" = "the provisions count pin",
    }, {
      "expr" = "m['dgzT47ReligiousCount']() != 8",
      "note" = "the religious count pin",
    }, {
      "expr" = "m['dgzT47ServicesCount']() != 15",
      "note" = "the services count pin",
    }, {
      "expr" = "m['dgzT47TackCount']() != 16",
      "note" = "the tack count pin",
    }, {
      "expr" = "m['dgzT47TransportCount']() != 13",
      "note" = "the transport count pin",
    }, {
      "expr" = "m['dgzEquipAfterCreation']() != 1",
      "note" = "the EquipAfterCreation pin",
    }, {
      "expr" = "m['dgzEquipAdventuringReason']() != 1",
      "note" = "the EquipAdventuringReason pin",
    }, {
      "expr" = "m['dgzEquipEstablishedPrices']() != 1",
      "note" = "the EquipEstablishedPrices pin",
    }, {
      "expr" = "m['dgzEquipBarterPurchase']() != 1",
      "note" = "the EquipBarterPurchase pin",
    }, {
      "expr" = "m['dgzEquipIncompleteList']() != 1",
      "note" = "the EquipIncompleteList pin",
    }, {
      "expr" = "m['dgzEquipPriceChange']() != 1",
      "note" = "the EquipPriceChange pin",
    }, {
      "expr" = "m['dgzEquipAvailability']() != 1",
      "note" = "the EquipAvailability pin",
    }, {
      "expr" = "m['dgzT47ArmorPieceNote']() != 1",
      "note" = "the T47ArmorPieceNote pin",
    }, {
      "expr" = "m['dgzT47NinjaPrefNote']() != 1",
      "note" = "the T47NinjaPrefNote pin",
    }, {
      "expr" = "m['dgzT47ArmorCost'](17) != 20  or m['dgzT47ArmorUnit'](17) != 4",
      "note" = "the T47 armor O-yoroi row - the great armor at 20 ch'ien (capture p. 77)",
    }, {
      "expr" = "m['dgzT47ArmsCost'](29) != 10  or m['dgzT47ArmsUnit'](29) != 4",
      "note" = "the T47 arms katana row - the katana and scabbard at 10 ch'ien (capture p. 77)",
    }, {
      "expr" = "m['dgzT47ArmsCost'](32) != 50  or m['dgzT47ArmsUnit'](32) != 2",
      "note" = "the T47 arms kiseru row - the iron pipe at 50 yuan (capture p. 77)",
    }, {
      "expr" = "m['dgzT47ClothingCost'](13) != 3  or m['dgzT47ClothingUnit'](13) != 3",
      "note" = "the T47 clothing silk robe row - the silk kosode at 3 tael (capture p. 77)",
    }, {
      "expr" = "m['dgzT47LivestockCost'](9) != 50  or m['dgzT47LivestockUnit'](9) != 4",
      "note" = "the T47 livestock elephant row - the war elephant at 50 ch'ien (capture p. 78)",
    }, {
      "expr" = "m['dgzT47MiscCost'](17) != 1  or m['dgzT47MiscUnit'](17) != 4  or m['dgzT47MiscStar'](17) != 1",
      "note" = "the T47 misc poison-smoke grenade row - 1 ch'ien, starred (capture p. 78)",
    }, {
      "expr" = "m['dgzT47MiscCost'](30) != 5  or m['dgzT47MiscUnit'](30) != 4  or m['dgzT47MiscStar'](30) != 1",
      "note" = "the T47 misc silk rope row - 5 ch'ien, starred (capture p. 78)",
    }, {
      "expr" = "m['dgzT47ProvisionsCost'](7) != 5  or m['dgzT47ProvisionsUnit'](7) != 4",
      "note" = "the T47 provisions rice row - the koku at 5 ch'ien (capture p. 78)",
    }, {
      "expr" = "m['dgzT47ReligiousCost'](2) != 50  or m['dgzT47ReligiousUnit'](2) != 4",
      "note" = "the T47 religious temple bell row - 50 ch'ien (capture p. 78)",
    }, {
      "expr" = "m['dgzT47ServicesCost'](13) != 5  or m['dgzT47ServicesCost'](3) != 7  or m['dgzT47ServicesUnit'](3) != 3",
      "note" = "the T47 services rows - the servant 5 tael, the clerk 7 tael (capture p. 78)",
    }, {
      "expr" = "m['dgzT47TackCost'](1) != 20  or m['dgzT47TackUnit'](1) != 4",
      "note" = "the T47 tack elephant barding row - 20 ch'ien (capture p. 78)",
    }, {
      "expr" = "m['dgzT47TransportCost'](9) != 800  or m['dgzT47TransportUnit'](9) != 4",
      "note" = "the T47 transport war junk row - 800 ch'ien (capture p. 78)",
    }, {
      "expr" = "m['dgzT47ArmorStar'](3) != 1  or m['dgzT47ArmorStar'](27) != 1  or m['dgzT47ArmsStar'](13) != 1  or m['dgzT47ArmsStar'](74) != 0",
      "note" = "the T47 star flags - the Do-maru and Sune-ate armor pieces, the chijiriki, the unstarred wakizashi (capture pp. 77-78)",
    }, {
      "expr" = "m['dgzT47ClothingStar'](0) != 0 or m['dgzT47ClothingStar'](1) != 0 or m['dgzT47ClothingStar'](2) != 0 or m['dgzT47ClothingStar'](3) != 0 or m['dgzT47ClothingStar'](4) != 0 or m['dgzT47ClothingStar'](5) != 0 or m['dgzT47ClothingStar'](6) != 0 or m['dgzT47ClothingStar'](7) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ClothingStar'](8) != 0 or m['dgzT47ClothingStar'](9) != 0 or m['dgzT47ClothingStar'](10) != 0 or m['dgzT47ClothingStar'](11) != 0 or m['dgzT47ClothingStar'](12) != 0 or m['dgzT47ClothingStar'](13) != 0 or m['dgzT47ClothingStar'](14) != 0 or m['dgzT47ClothingStar'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ClothingStar'](16) != 0 or m['dgzT47ClothingStar'](17) != 0 or m['dgzT47ClothingStar'](18) != 0 or m['dgzT47ClothingStar'](19) != 0 or m['dgzT47ClothingStar'](20) != 0 or m['dgzT47ClothingStar'](21) != 0 or m['dgzT47ClothingStar'](22) != -99 or m['dgzT47LivestockStar'](0) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47LivestockStar'](1) != 0 or m['dgzT47LivestockStar'](2) != 0 or m['dgzT47LivestockStar'](3) != 0 or m['dgzT47LivestockStar'](4) != 0 or m['dgzT47LivestockStar'](5) != 0 or m['dgzT47LivestockStar'](6) != 0 or m['dgzT47LivestockStar'](7) != 0 or m['dgzT47LivestockStar'](8) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47LivestockStar'](9) != 0 or m['dgzT47LivestockStar'](10) != 0 or m['dgzT47LivestockStar'](11) != 0 or m['dgzT47LivestockStar'](12) != 0 or m['dgzT47LivestockStar'](13) != 0 or m['dgzT47LivestockStar'](14) != 0 or m['dgzT47LivestockStar'](15) != 0 or m['dgzT47LivestockStar'](16) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47LivestockStar'](17) != 0 or m['dgzT47LivestockStar'](18) != 0 or m['dgzT47LivestockStar'](19) != 0 or m['dgzT47LivestockStar'](20) != 0 or m['dgzT47LivestockStar'](21) != 0 or m['dgzT47LivestockStar'](22) != 0 or m['dgzT47LivestockStar'](23) != 0 or m['dgzT47LivestockStar'](24) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47LivestockStar'](25) != -99 or m['dgzT47ProvisionsStar'](0) != 0 or m['dgzT47ProvisionsStar'](1) != 0 or m['dgzT47ProvisionsStar'](2) != 0 or m['dgzT47ProvisionsStar'](3) != 0 or m['dgzT47ProvisionsStar'](4) != 0 or m['dgzT47ProvisionsStar'](5) != 0 or m['dgzT47ProvisionsStar'](6) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ProvisionsStar'](7) != 0 or m['dgzT47ProvisionsStar'](8) != 0 or m['dgzT47ProvisionsStar'](9) != 0 or m['dgzT47ProvisionsStar'](10) != 0 or m['dgzT47ProvisionsStar'](11) != -99 or m['dgzT47ReligiousStar'](0) != 0 or m['dgzT47ReligiousStar'](1) != 0 or m['dgzT47ReligiousStar'](2) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ReligiousStar'](3) != 0 or m['dgzT47ReligiousStar'](4) != 0 or m['dgzT47ReligiousStar'](5) != 0 or m['dgzT47ReligiousStar'](6) != 0 or m['dgzT47ReligiousStar'](7) != 0 or m['dgzT47ReligiousStar'](8) != -99 or m['dgzT47ServicesStar'](0) != 0 or m['dgzT47ServicesStar'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ServicesStar'](2) != 0 or m['dgzT47ServicesStar'](3) != 0 or m['dgzT47ServicesStar'](4) != 0 or m['dgzT47ServicesStar'](5) != 0 or m['dgzT47ServicesStar'](6) != 0 or m['dgzT47ServicesStar'](7) != 0 or m['dgzT47ServicesStar'](8) != 0 or m['dgzT47ServicesStar'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47ServicesStar'](10) != 0 or m['dgzT47ServicesStar'](11) != 0 or m['dgzT47ServicesStar'](12) != 0 or m['dgzT47ServicesStar'](13) != 0 or m['dgzT47ServicesStar'](14) != 0 or m['dgzT47ServicesStar'](15) != -99 or m['dgzT47TackStar'](0) != 0 or m['dgzT47TackStar'](1) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47TackStar'](2) != 0 or m['dgzT47TackStar'](3) != 0 or m['dgzT47TackStar'](4) != 0 or m['dgzT47TackStar'](5) != 0 or m['dgzT47TackStar'](6) != 0 or m['dgzT47TackStar'](7) != 0 or m['dgzT47TackStar'](8) != 0 or m['dgzT47TackStar'](9) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47TackStar'](10) != 0 or m['dgzT47TackStar'](11) != 0 or m['dgzT47TackStar'](12) != 0 or m['dgzT47TackStar'](13) != 0 or m['dgzT47TackStar'](14) != 0 or m['dgzT47TackStar'](15) != 0 or m['dgzT47TackStar'](16) != -99 or m['dgzT47TransportStar'](0) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47TransportStar'](1) != 0 or m['dgzT47TransportStar'](2) != 0 or m['dgzT47TransportStar'](3) != 0 or m['dgzT47TransportStar'](4) != 0 or m['dgzT47TransportStar'](5) != 0 or m['dgzT47TransportStar'](6) != 0 or m['dgzT47TransportStar'](7) != 0 or m['dgzT47TransportStar'](8) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dgzT47TransportStar'](9) != 0 or m['dgzT47TransportStar'](10) != 0 or m['dgzT47TransportStar'](11) != 0 or m['dgzT47TransportStar'](12) != 0 or m['dgzT47TransportStar'](13) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R639 OA equipment audit",
      "comment" = "OA round twenty-six (capture pp. 76-78): the equipping the character prose and the Table 47 cost lists",
    },
}
