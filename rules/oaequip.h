// =========================================================================================
// Adnd1 - rules/oaequip.h
// EQUIPPING THE CHARACTER AND TABLE 47, printed capture pp. 76-78 - the OA
// equipment round
// census 561 -> 562.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. The equipping prose
// pins from capture p. 76 (printed p. 38) and the full Table 47 from capture
// pp. 77-78 (printed pp. 39-40); the T47 gap box label reads capture pp.
// 78-84 - the label is preserved byte-exact in the flip. The printed table
// carries TEN sections - the eight cost lists the box names plus the ARMOR
// and ARMS lists that ride the same table; all ten pin this round as 256
// rows, each a cost-unit-star triple (the unit code 1 fen, 2 yuan, 3 tael, 4
// ch'ien per the R636 T43 doctrine; the star flags pin the printed asterisks
// - the ten armor-piece rows, the chijiriki, the five ninja-preferred misc
// rows). No contested cells detected within the single source. OCR
// normalizations: the Kyoketsu-shogi "(biaded rope)" reads as bladed rope and
// the stray mid-table separator row after it is an OCR artifact pinning
// nothing. The Weapons chapter prose with Tables 48-49 (capture pp. 79-80) is
// deliberately left for the next round
//
// the gap census after this round: 89 closed, 146 open - the Table 47 box
// flips (census 561 -> 562); NEXT - R640: the Weapons prose with Table 48
// (Weapon Equivalents) and Table 49 (Weight and Damage by Weapon Type),
// capture pp. 79-80, the weapon equivalents doctrine, prefix dha (verify
// free), audit "R640 OA weapons audit", include after rules/oaequip.h
//
namespace rules {

// ---- the equipping prose pins ----

// equipping prose (capture p. 76): after a character is created it is
// important to equip him - without equipment the character is at a great
// disadvantage
inline bool dgzEquipAfterCreation()
    { return true; }

// equipping prose (capture p. 76): initially the character is not likely to
// get everything he wants - not enough money - which is not bad, since it
// provides the perfect reason to adventure
inline bool dgzEquipAdventuringReason()
    { return true; }

// equipping prose (capture p. 76): the prices given are figured using
// established currency
inline bool dgzEquipEstablishedPrices()
    { return true; }

// equipping prose (capture p. 76): characters can also purchase the equipment
// through barter units, using the barter-unit values already given
inline bool dgzEquipBarterPurchase()
    { return true; }

// equipping prose (capture p. 76): the equipment list is by no means complete
// - it covers the items most frequently used, and the DM can freely add items
// if needed
inline bool dgzEquipIncompleteList()
    { return true; }

// equipping prose (capture p. 76): the DM can change the price of any item
// for sound campaign reasons - scarcity, quality of workmanship
inline bool dgzEquipPriceChange()
    { return true; }

// equipping prose (capture p. 76): the DM can rule items unavailable in areas
// of Kara-Tur - such items obviously cannot be purchased
inline bool dgzEquipAvailability()
    { return true; }

// ---- the Table 47 cost lists ----

// Table 47 (capture pp. 77-78): the total row count across the ten printed
// sections
inline int dgzT47RowCount()
    { return 256; }

// Table 47 (capture pp. 77-78): the armor cost list row count
inline int dgzT47ArmorCount()
    { return 28; }

// Table 47 (capture pp. 77-78): the arms cost list row count
inline int dgzT47ArmsCount()
    { return 76; }

// Table 47 (capture pp. 77-78): the clothing cost list row count
inline int dgzT47ClothingCount()
    { return 22; }

// Table 47 (capture pp. 77-78): the livestock cost list row count
inline int dgzT47LivestockCount()
    { return 25; }

// Table 47 (capture pp. 77-78): the misc cost list row count
inline int dgzT47MiscCount()
    { return 42; }

// Table 47 (capture pp. 77-78): the provisions cost list row count
inline int dgzT47ProvisionsCount()
    { return 11; }

// Table 47 (capture pp. 77-78): the religious cost list row count
inline int dgzT47ReligiousCount()
    { return 8; }

// Table 47 (capture pp. 77-78): the services cost list row count
inline int dgzT47ServicesCount()
    { return 15; }

// Table 47 (capture pp. 77-78): the tack cost list row count
inline int dgzT47TackCount()
    { return 16; }

// Table 47 (capture pp. 77-78): the transport cost list row count
inline int dgzT47TransportCount()
    { return 13; }

// the printed cost value by row - 0 Banded, 1 Buckler, 2 Chain, 3 Do-maru, 4
// Haidate, 5 Hanburi, 6 Hara-ate, 7 Hara-ate-gawa, 8 Haramaki, 9 Haramaki-do,
// 10 Helmet, small, 11 Hide, 12 Horo, 13 Jingasa (war hat), 14 Kabuto (great
// helm), 15 Kote (armored sleeves), 16 Leather, 17 O-yoroi (great armor), 18
// Padded, 19 Ring, 20 Scale, leather, 21 Scale, metal, 22 Shield, large, 23
// Shield, medium, 24 Sode, pair, 25 Splinted, 26 Studded, 27 Sune-ate
// (capture pp. 77-78).
inline int dgzT47ArmorCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 5;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 8;
        case 12:
            return 2;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 8;
        case 16:
            return 2;
        case 17:
            return 20;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 4;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 30;
        case 24:
            return 8;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 5;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ArmorUnit(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 3;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 3;
        case 25:
            return 4;
        case 26:
            return 3;
        case 27:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ArmorStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 1;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 1;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Arrow, armor piercer, 1 Arrow, frog
// crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow, normal, 5 Axe,
// battle, 6 Axe, hand or throwing, 7 Blowpipe, 8 Bo stick, 9 Boku-toh (wooden
// sword), 10 Bow, composite short, 11 Bow, short, 12 Chain, 13 Chijiriki
// (spear & chain), 14 Chu-ko-nu (repeating crossbow), 15 Crossbow, heavy, 16
// Crossbow, light, 17 Dagger, 18 Daikyu (great bow), 19 Dart, blowpipe, 20
// Dart, thrown, 21 Fang (good), 22 Gunsen (iron fan), 23 Halberd, 24 Hankyu
// (little bow), 25 Javelin, 26 Jitte, 27 Jo stick, 28 Kama (sickle), 29
// Katana & scabbard, 30 Kau sin ke (whipping chain), 31 Kawanaga (grappling
// hook), 32 Kiseru (iron pipe), 33 Kumade (climbing rake), 34 Kusari-gama
// (sickle & chain), 35 Kyoketsu-shogi (bladed rope), 36 Lajatang, 37 Lance
// (light horse), 38 Man catcher, 39 Metsubishi (pepper blower), 40 Nagimaki
// (horseman's glaive), 41 Naginata (footman's glaive), 42 Needle, 43 Nekode,
// pair (climbing claws), 44 Ninja-to & scabbard (sword), 45 Nunchaku, 46
// Parang (machete), 47 Pellet bow, 48 Quarrel, single, 49 Quarrel, two dozen,
// 50 Sai, 51 Sang kauw, 52 Shaken, 53 Shakujo yari (concealed spear), 54
// Shikomi-zu, 55 Shuriken, spike, 56 Shuriken, star, large, 57 Shuriken,
// star, small, 58 Siangkam (metal arrow), 59 Sling, 60 Sling, staff, 61
// Sling/pellet bow bullets, score, 62 Sode garami (sleeve entangler), 63
// Spear, 64 Sword, broad & scabbard, 65 Sword, long & scabbard, 66 Sword,
// short & scabbard, 67 Sword, two-handed, 68 Tetsu-bishi (caltrops), 69
// Tetsubo (iron staff), 70 Three-piece rod, 71 Trident, 72 Tui-fa, 73 Uchi-ne
// (small javelin), 74 Wakizashi & scabbard (short sword), 75 Whip (capture
// pp. 77-78).
inline int dgzT47ArmsCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 6;
        case 10:
            return 1;
        case 11:
            return 5;
        case 12:
            return 10;
        case 13:
            return 6;
        case 14:
            return 3;
        case 15:
            return 8;
        case 16:
            return 6;
        case 17:
            return 1;
        case 18:
            return 10;
        case 19:
            return 1;
        case 20:
            return 8;
        case 21:
            return 1;
        case 22:
            return 4;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 10;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 10;
        case 30:
            return 1;
        case 31:
            return 5;
        case 32:
            return 50;
        case 33:
            return 1;
        case 34:
            return 3;
        case 35:
            return 1;
        case 36:
            return 7;
        case 37:
            return 3;
        case 38:
            return 6;
        case 39:
            return 2;
        case 40:
            return 6;
        case 41:
            return 8;
        case 42:
            return 3;
        case 43:
            return 3;
        case 44:
            return 4;
        case 45:
            return 1;
        case 46:
            return 15;
        case 47:
            return 5;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 10;
        case 51:
            return 1;
        case 52:
            return 2;
        case 53:
            return 5;
        case 54:
            return 7;
        case 55:
            return 4;
        case 56:
            return 1;
        case 57:
            return 6;
        case 58:
            return 2;
        case 59:
            return 2;
        case 60:
            return 5;
        case 61:
            return 10;
        case 62:
            return 5;
        case 63:
            return 3;
        case 64:
            return 4;
        case 65:
            return 6;
        case 66:
            return 3;
        case 67:
            return 2;
        case 68:
            return 5;
        case 69:
            return 2;
        case 70:
            return 2;
        case 71:
            return 5;
        case 72:
            return 5;
        case 73:
            return 3;
        case 74:
            return 6;
        case 75:
            return 1;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ArmsUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 1;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 3;
        case 26:
            return 2;
        case 27:
            return 1;
        case 28:
            return 3;
        case 29:
            return 4;
        case 30:
            return 3;
        case 31:
            return 2;
        case 32:
            return 2;
        case 33:
            return 3;
        case 34:
            return 3;
        case 35:
            return 3;
        case 36:
            return 3;
        case 37:
            return 3;
        case 38:
            return 3;
        case 39:
            return 3;
        case 40:
            return 3;
        case 41:
            return 3;
        case 42:
            return 1;
        case 43:
            return 3;
        case 44:
            return 3;
        case 45:
            return 3;
        case 46:
            return 2;
        case 47:
            return 3;
        case 48:
            return 2;
        case 49:
            return 3;
        case 50:
            return 2;
        case 51:
            return 4;
        case 52:
            return 3;
        case 53:
            return 3;
        case 54:
            return 3;
        case 55:
            return 2;
        case 56:
            return 3;
        case 57:
            return 2;
        case 58:
            return 3;
        case 59:
            return 2;
        case 60:
            return 2;
        case 61:
            return 2;
        case 62:
            return 3;
        case 63:
            return 3;
        case 64:
            return 3;
        case 65:
            return 3;
        case 66:
            return 3;
        case 67:
            return 4;
        case 68:
            return 2;
        case 69:
            return 3;
        case 70:
            return 3;
        case 71:
            return 3;
        case 72:
            return 2;
        case 73:
            return 2;
        case 74:
            return 4;
        case 75:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ArmsStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 0;
        case 45:
            return 0;
        case 46:
            return 0;
        case 47:
            return 0;
        case 48:
            return 0;
        case 49:
            return 0;
        case 50:
            return 0;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 0;
        case 56:
            return 0;
        case 57:
            return 0;
        case 58:
            return 0;
        case 59:
            return 0;
        case 60:
            return 0;
        case 61:
            return 0;
        case 62:
            return 0;
        case 63:
            return 0;
        case 64:
            return 0;
        case 65:
            return 0;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 0;
        case 69:
            return 0;
        case 70:
            return 0;
        case 71:
            return 0;
        case 72:
            return 0;
        case 73:
            return 0;
        case 74:
            return 0;
        case 75:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Boots, high hard, 1 Boots, high soft, 2
// Cap, 3 Cloak, cloth, 4 Cloak, fur, 5 Gloves, 6 Hat, fur, 7 Hat, straw, 8
// Loincloth, 9 Outer robe (ho, happi), 10 Raincape, straw (mino), 11 Robe,
// cotton (kosode, kimono), 12 Robe, fur trimmed, 13 Robe, silk (kosode), 14
// Sandals, 15 Sash or belt (obi), 16 Tabi (boot/sock), 17 Trousers, cotton
// (hakama), 18 Trousers, woolen, 19 Turban, 20 Vest, fur, 21 Vest, silk
// (capture pp. 77-78).
inline int dgzT47ClothingCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 3;
        case 2:
            return 8;
        case 3:
            return 1;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 5;
        case 17:
            return 3;
        case 18:
            return 1;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 1;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ClothingUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 1;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 2;
        case 20:
            return 3;
        case 21:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ClothingStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Canary, 1 Cat, 2 Chicken or rooster, 3
// Cricket, lighting, 4 Dog, guard, 5 Dog, hunting, 6 Dog, lap, 7 Donkey, 8
// Dove, 9 Elephant, war, 10 Fish, ornamental, 11 Goat, 12 Hawk, fledgling, 13
// Hawk, trained, 14 Horse, draft, 15 Horse, heavy war, 16 Horse, light war,
// 17 Horse, medium war, 18 Horse, riding (light), 19 Monkey, 20 Nightingale,
// 21 Ox, 22 Peacock, 23 Pony, riding, 24 Pony, war (capture pp. 77-78).
inline int dgzT47LivestockCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 5;
        case 5:
            return 3;
        case 6:
            return 8;
        case 7:
            return 1;
        case 8:
            return 5;
        case 9:
            return 50;
        case 10:
            return 2;
        case 11:
            return 5;
        case 12:
            return 5;
        case 13:
            return 20;
        case 14:
            return 15;
        case 15:
            return 5;
        case 16:
            return 25;
        case 17:
            return 3;
        case 18:
            return 2;
        case 19:
            return 8;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 6;
        case 23:
            return 15;
        case 24:
            return 2;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47LivestockUnit(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 3;
        case 15:
            return 4;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 3;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 4;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47LivestockStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Backpack, wicker, 1 Basket, large, 2
// Basket, small, 3 Blanket, coarse, 4 Candle, tallow, 5 Chest, Armor, 6
// Chest, common wooden, large, 7 Chest, common wooden, small, 8 Chest,
// quality, large, 9 Chest, quality, small, 10 Chopsticks, lacquered, 11
// Cloth, cotton bolt, 12 Cloth, silk bolt, 13 Cord, 10 ft, 14 Eggshell
// grenade, dust, 15 Eggshell grenade, flashpowder, 16 Eggshell grenade,
// pepper, 17 Eggshell grenade, poison smoke, 18 Fishhook, 19 Fishing net, 10
// ft, 20 Goza (straw mat), 21 Ink, brush, and inking stone, 22 Lantern,
// hooded, 23 Lantern, paper, 24 Mirror, small metal, 25 Oil, flask of, 26
// Paper, writing, 10 sheets, 27 Pot, iron, 28 Quiver, 2 dozen arrows cap, 29
// Rope, hemp 50 ft, 30 Rope, silk 50 ft, 31 Signal rocket, 32 Standard, flag,
// sashimono, 33 Sword stand, 34 Tent, large, 35 Tent, small, 36 Thieves picks
// and tools, 37 Tinder box, flint and steel, 38 Tobacco pipe, 39 Tobacco, 1
// lb, 40 Tool, common, 41 Torch (capture pp. 77-78).
inline int dgzT47MiscCost(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 5;
        case 6:
            return 3;
        case 7:
            return 30;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 4;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 10;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 1;
        case 20:
            return 10;
        case 21:
            return 3;
        case 22:
            return 5;
        case 23:
            return 2;
        case 24:
            return 1;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 6;
        case 28:
            return 1;
        case 29:
            return 10;
        case 30:
            return 5;
        case 31:
            return 1;
        case 32:
            return 2;
        case 33:
            return 1;
        case 34:
            return 2;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 8;
        case 38:
            return 5;
        case 39:
            return 1;
        case 40:
            return 10;
        case 41:
            return 1;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47MiscUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 3;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 3;
        case 10:
            return 2;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 3;
        case 17:
            return 4;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 3;
        case 24:
            return 4;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 2;
        case 28:
            return 3;
        case 29:
            return 2;
        case 30:
            return 4;
        case 31:
            return 3;
        case 32:
            return 3;
        case 33:
            return 4;
        case 34:
            return 3;
        case 35:
            return 3;
        case 36:
            return 4;
        case 37:
            return 2;
        case 38:
            return 2;
        case 39:
            return 3;
        case 40:
            return 3;
        case 41:
            return 1;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47MiscStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 1;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 0;
        case 36:
            return 0;
        case 37:
            return 0;
        case 38:
            return 0;
        case 39:
            return 0;
        case 40:
            return 0;
        case 41:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Beer, jar, 1 Food, banquet, 2 Food,
// common meal, 3 Food, exotic, 4 Food, poor, 5 Grain, horse 1 day, 6
// Pepper/spices, 1 lb, 7 Rice, koku, 8 Ricecake, 1 week rations, 9 Sake, jar,
// 10 Tea, 1 lb (capture pp. 77-78).
inline int dgzT47ProvisionsCost(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 10;
        case 6:
            return 10;
        case 7:
            return 5;
        case 8:
            return 15;
        case 9:
            return 5;
        case 10:
            return 1;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ProvisionsUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ProvisionsStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Beads, prayer, 1 Bell, small, 2 Bell,
// temple, 3 Gong, 4 Incense, stick, 5 Paper, prayer strip, 6 Symbol, holy
// (unholy), 7 Wheel, prayer (capture pp. 77-78).
inline int dgzT47ReligiousCost(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 50;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ReligiousUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 3;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ReligiousStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Acrobats, per performance, 1 Actors, per
// performance, 2 Chef, per banquet, 3 Clerk, per month, 4 Courier, per day, 5
// Dancers, per performance, 6 Gardener, per month, 7 Lantern bearer, 8
// Lodging, common or small village, 9 Lodging, good inn, 10 Messenger, in
// town, 11 Mourners, 12 Musician, per performance, 13 Servant, one month, 14
// Stabling, one night (capture pp. 77-78).
inline int dgzT47ServicesCost(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 7;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 6;
        case 7:
            return 1;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 3;
        case 13:
            return 5;
        case 14:
            return 3;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47ServicesUnit(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 3;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 2;
        case 13:
            return 3;
        case 14:
            return 1;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47ServicesStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Barding, half chain, 1 Barding, elephant,
// leather, 2 Barding, full leather or padded, 3 Barding, half brigandine, 4
// Barding, half padded, 5 Barding, half metal scale, 6 Bit and bridle, 7
// Harness and feed bag, 8 Horse yoke, 9 Howdah, 10 Ox yoke, 11 Saddle bags,
// large, 12 Saddle bags, small, 13 Saddle blanket, 14 Saddle, pack, 15
// Saddle, riding (capture pp. 77-78).
inline int dgzT47TackCost(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 20;
        case 2:
            return 2;
        case 3:
            return 5;
        case 4:
            return 1;
        case 5:
            return 8;
        case 6:
            return 2;
        case 7:
            return 15;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 1;
        case 12:
            return 15;
        case 13:
            return 1;
        case 14:
            return 5;
        case 15:
            return 8;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47TackUnit(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 3;
        case 15:
            return 3;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47TackStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        default:
            return -99;
        }
    }

// the printed cost value by row - 0 Barge, large, 1 Barge, small, 2 Boat, 3
// Canoe, small, 4 Canoe, war, 5 Chariot, riding, 6 Chariot, war, 7 Junk,
// large, 8 Junk, small, 9 Junk, war, 10 Ox cart, 11 Palanquin, 12 Wagon
// (capture pp. 77-78).
inline int dgzT47TransportCost(int b)
    {
        switch (b) {
        case 0:
            return 300;
        case 1:
            return 100;
        case 2:
            return 20;
        case 3:
            return 3;
        case 4:
            return 8;
        case 5:
            return 50;
        case 6:
            return 100;
        case 7:
            return 500;
        case 8:
            return 300;
        case 9:
            return 800;
        case 10:
            return 5;
        case 11:
            return 5;
        case 12:
            return 20;
        default:
            return -99;
        }
    }

// the cost unit as the 1-4 code: 1 fen, 2 yuan, 3 tael, 4 ch'ien - the R636
// T43 coin values (capture pp. 77-78).
inline int dgzT47TransportUnit(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 4;
        case 2:
            return 4;
        case 3:
            return 4;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 4;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the footnote read (capture pp. 77-78);
// 0 elsewhere.
inline int dgzT47TransportStar(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return -99;
        }
    }

// T47 armor footnote (capture p. 77): the asterisk marks an armor piece, not
// a complete suit
inline bool dgzT47ArmorPieceNote()
    { return true; }

// T47 misc footnote (capture p. 78): the asterisked items are preferred by
// ninja
inline bool dgzT47NinjaPrefNote()
    { return true; }

}   // namespace rules
