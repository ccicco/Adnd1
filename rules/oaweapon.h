// =========================================================================================
// Adnd1 - rules/oaweapon.h
// WEAPONS OPENER, TABLE 48 AND TABLE 49, printed capture pp. 79-80 - the OA
// weapons round
// census 562 -> 563.
//
// pinned from the 2018 print capture alone for this range (the settling
// authority): the first Mistral-OCR capture session is unavailable above p.
// 33, so the cross-capture agreement check is impossible. The weapons opener
// and equivalents prose pin from capture p. 79 (printed p. 41), T48 and T49
// from capture p. 79, and the T49 footnotes from capture p. 80 (printed p.
// 42) - T49's page directs to the footnotes at the bottom of the next page,
// where they print under T50 and serve both tables. T48 pins as the 16-row
// equivalent-count grid, the name lists riding the column comment (textual
// cells, the count is the pinnable datum). T49 pins as the 69-row
// weight-damage grid: the weight bounds (the lone numbers as lo=hi, the spear
// 40-60, the two-handed sword 150-250 and the whip 25-35 as printed ranges),
// the S-M and L damage bounds with -99 marking the printed dashes (the lasso,
// the needle's blank vs-L cell), the a-h footnote letters as bitmasks, and
// the javelin, naginata and spear stars. No contested cells detected within
// the single source. OCR normalizations: the boldface two-hand set is lost to
// the OCR - the NOTE pins as a bool, the set does not; the T49 mace row
// prints no footnote letter while the T50 mace row carries h - T49 pins as
// printed; the kawanga row spells as printed (the R639 T47 arms list printed
// kawanaga) and the T49 arrow standard row spells as printed (T47 printed
// arrow, normal) - both pin as printed. The Weapons prose and weapon
// descriptions box stays open (the descriptions pin later); Table 50 (capture
// p. 80) is deliberately left for the next round
//
// the gap census after this round: 91 closed, 144 open - the Table 48 and
// Table 49 boxes flip (census 562 -> 563); NEXT - R641: Table 50 (Hand Held
// Weapons, General Data and To Hit Adjustments), capture p. 80, the hand-held
// AC adjustment grid, prefix dhb (verify free), audit "R641 OA handheld
// audit", include after rules/oaweapon.h
//
namespace rules {

// ---- the weapon equivalents pins ----

// Table 48 (capture p. 79): sixteen weapon equivalent rows
inline int dhaT48RowCount()
    { return 16; }

// the equivalent-name count by row - 0 Axe, battle (Fu, liu, ch'iang, chi,
// chin, yueh, chien, ch'i fu, i huang, masakari, ono), 1 Axe, hand (Piso
// tonkeng, batak kapak), 2 Bo stick (Rokushakubo, staff), 3 Chain (Manriki
// gusari, rante), 4 Dagger (tanto, do-su, kozuka, aikuchi), 5 Halberd (Ko,
// ch'i chi, pi chi, bisento), 6 Javelin (mau), 7 Jo stick (Muton, amis), 8
// Lance, light (Hsaio, shuo), 9 Mace (Suan Tao Fung), 10 Pike (Mao, lembing),
// 11 Spear (Yari), 12 Sword, long (Tau-kien), 13 Sword, short (Kris), 14
// Sword, two-handed (No-dachi), 15 Trident (Magari yari, tiger lance)
// (capture p. 79).
inline int dhaT48EquivCount(int b)
    {
        switch (b) {
        case 0:
            return 11;
        case 1:
            return 2;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 1;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 2;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 2;
        default:
            return -99;
        }
    }

// weapon equivalents prose (capture p. 79): a number of weapons are listed by
// their common English names
inline bool dhaWeaponsEnglishNames()
    { return true; }

// weapon equivalents prose (capture p. 79): these weapons are known by many
// different names in many different lands - some listed below
inline bool dhaWeaponsManyNames()
    { return true; }

// weapon equivalents prose (capture p. 79): there may be slight differences
// in appearance between the equivalent weapons
inline bool dhaWeaponsAppearanceDiff()
    { return true; }

// weapon equivalents prose (capture p. 79): the appearance differences do not
// affect the general function of the weapon
inline bool dhaWeaponsFunctionSame()
    { return true; }

// ---- the Table 49 weight-damage grid ----

// Table 49 (capture p. 79): sixty-nine weapon type rows
inline int dhaT49RowCount()
    { return 69; }

// the approximate weight lower bound, by weapon row - 0 Arrow, armor piercer,
// 1 Arrow, frog crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow,
// standard, 5 Axe, battle, 6 Axe, hand or throwing, 7 Bo stick, 8 Boku-toh, 9
// Chain, 10 Chijiriki, 11 Chopsticks, 12 Club, 13 Dagger, 14 Dart, blowgun,
// 15 Dart, thrown, 16 Fang, 17 Gunsen, 18 Halberd, 19 Javelin, 20 Jitte, 21
// Jo stick, 22 Kama, 23 Katana, 24 Kau sin ke, 25 Kawanga, 26 Kiseru, 27
// Kumade, 28 Kusari-gama, 29 Kyoketsu-shogi, 30 Lajatang, 31 Lance (light
// horse), 32 Lasso, 33 Mace, 34 Man catcher, 35 Nagimaki, 36 Naginata, 37
// Needle, 38 Nekode, 39 Ninja-to, 40 Nunchaku, 41 Parang, 42 Quarrel, heavy,
// 43 Quarrel, light, 44 Sai, 45 Sang kauw, 46 Shaken, 47 Shuriken, spike, 48
// Shuriken, star, large, 49 Shuriken, star, small, 50 Siangkam, 51
// Sling/pellet bow bullet, 52 Sling/pellet bow stone, 53 Sling, staff bullet,
// 54 Sling, staff stone, 55 Sode garami, 56 Spear, 57 Sword, broad, 58 Sword,
// long, 59 Sword, short, 60 Sword, two-handed, 61 Tetsu-bishi, 62 Tetsubo, 63
// Three-piece rod, 64 Trident, 65 Tui-fa (Tonfa), 66 Uchi-ne, 67 Wakizashi,
// 68 Whip; a lone number prints as lo=hi, the spear 40-60, the two-handed
// sword 150-250 and the whip 25-35 print as ranges (capture p. 79).
inline int dhaT49WeightLo(int b)
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
            return 2;
        case 5:
            return 75;
        case 6:
            return 50;
        case 7:
            return 40;
        case 8:
            return 30;
        case 9:
            return 30;
        case 10:
            return 60;
        case 11:
            return 1;
        case 12:
            return 30;
        case 13:
            return 10;
        case 14:
            return 1;
        case 15:
            return 5;
        case 16:
            return 30;
        case 17:
            return 10;
        case 18:
            return 175;
        case 19:
            return 20;
        case 20:
            return 15;
        case 21:
            return 15;
        case 22:
            return 20;
        case 23:
            return 60;
        case 24:
            return 40;
        case 25:
            return 10;
        case 26:
            return 5;
        case 27:
            return 15;
        case 28:
            return 30;
        case 29:
            return 10;
        case 30:
            return 60;
        case 31:
            return 50;
        case 32:
            return 20;
        case 33:
            return 100;
        case 34:
            return 80;
        case 35:
            return 60;
        case 36:
            return 100;
        case 37:
            return 1;
        case 38:
            return 5;
        case 39:
            return 50;
        case 40:
            return 30;
        case 41:
            return 50;
        case 42:
            return 2;
        case 43:
            return 1;
        case 44:
            return 20;
        case 45:
            return 100;
        case 46:
            return 5;
        case 47:
            return 1;
        case 48:
            return 2;
        case 49:
            return 1;
        case 50:
            return 5;
        case 51:
            return 2;
        case 52:
            return 1;
        case 53:
            return 5;
        case 54:
            return 4;
        case 55:
            return 50;
        case 56:
            return 40;
        case 57:
            return 75;
        case 58:
            return 60;
        case 59:
            return 35;
        case 60:
            return 150;
        case 61:
            return 3;
        case 62:
            return 75;
        case 63:
            return 50;
        case 64:
            return 50;
        case 65:
            return 15;
        case 66:
            return 5;
        case 67:
            return 30;
        case 68:
            return 25;
        default:
            return -99;
        }
    }

// the approximate weight upper bound (capture p. 79).
inline int dhaT49WeightHi(int b)
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
            return 2;
        case 5:
            return 75;
        case 6:
            return 50;
        case 7:
            return 40;
        case 8:
            return 30;
        case 9:
            return 30;
        case 10:
            return 60;
        case 11:
            return 1;
        case 12:
            return 30;
        case 13:
            return 10;
        case 14:
            return 1;
        case 15:
            return 5;
        case 16:
            return 30;
        case 17:
            return 10;
        case 18:
            return 175;
        case 19:
            return 20;
        case 20:
            return 15;
        case 21:
            return 15;
        case 22:
            return 20;
        case 23:
            return 60;
        case 24:
            return 40;
        case 25:
            return 10;
        case 26:
            return 5;
        case 27:
            return 15;
        case 28:
            return 30;
        case 29:
            return 10;
        case 30:
            return 60;
        case 31:
            return 50;
        case 32:
            return 20;
        case 33:
            return 100;
        case 34:
            return 80;
        case 35:
            return 60;
        case 36:
            return 100;
        case 37:
            return 1;
        case 38:
            return 5;
        case 39:
            return 50;
        case 40:
            return 30;
        case 41:
            return 50;
        case 42:
            return 2;
        case 43:
            return 1;
        case 44:
            return 20;
        case 45:
            return 100;
        case 46:
            return 5;
        case 47:
            return 1;
        case 48:
            return 2;
        case 49:
            return 1;
        case 50:
            return 5;
        case 51:
            return 2;
        case 52:
            return 1;
        case 53:
            return 5;
        case 54:
            return 4;
        case 55:
            return 50;
        case 56:
            return 60;
        case 57:
            return 75;
        case 58:
            return 60;
        case 59:
            return 35;
        case 60:
            return 250;
        case 61:
            return 3;
        case 62:
            return 75;
        case 63:
            return 50;
        case 64:
            return 50;
        case 65:
            return 15;
        case 66:
            return 5;
        case 67:
            return 30;
        case 68:
            return 35;
        default:
            return -99;
        }
    }

// the damage vs size S or M lower bound, dice lo-hi; -99 marks the printed
// dash - the lasso has no damage and the needle reads 1 per needle (capture
// p. 79).
inline int dhaT49SmLo(int b)
    {
        switch (b) {
        case 0:
            return 2;
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
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return -99;
        case 33:
            return 2;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return 1;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 2;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 2;
        case 52:
            return 1;
        case 53:
            return 2;
        case 54:
            return 1;
        case 55:
            return 1;
        case 56:
            return 1;
        case 57:
            return 2;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 1;
        case 61:
            return 1;
        case 62:
            return 1;
        case 63:
            return 1;
        case 64:
            return 2;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the damage vs size S or M upper bound (capture p. 79).
inline int dhaT49SmHi(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 2;
        case 3:
            return 8;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 6;
        case 7:
            return 6;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 3;
        case 12:
            return 6;
        case 13:
            return 4;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 6;
        case 17:
            return 3;
        case 18:
            return 10;
        case 19:
            return 6;
        case 20:
            return 4;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 10;
        case 24:
            return 8;
        case 25:
            return 3;
        case 26:
            return 4;
        case 27:
            return 4;
        case 28:
            return 6;
        case 29:
            return 4;
        case 30:
            return 10;
        case 31:
            return 6;
        case 32:
            return -99;
        case 33:
            return 7;
        case 34:
            return 2;
        case 35:
            return 6;
        case 36:
            return 8;
        case 37:
            return 1;
        case 38:
            return 4;
        case 39:
            return 8;
        case 40:
            return 6;
        case 41:
            return 8;
        case 42:
            return 5;
        case 43:
            return 4;
        case 44:
            return 4;
        case 45:
            return 8;
        case 46:
            return 4;
        case 47:
            return 4;
        case 48:
            return 6;
        case 49:
            return 4;
        case 50:
            return 5;
        case 51:
            return 5;
        case 52:
            return 4;
        case 53:
            return 8;
        case 54:
            return 8;
        case 55:
            return 4;
        case 56:
            return 6;
        case 57:
            return 8;
        case 58:
            return 8;
        case 59:
            return 6;
        case 60:
            return 10;
        case 61:
            return 4;
        case 62:
            return 8;
        case 63:
            return 6;
        case 64:
            return 7;
        case 65:
            return 6;
        case 66:
            return 4;
        case 67:
            return 8;
        case 68:
            return 2;
        default:
            return -99;
        }
    }

// the damage vs size L lower bound; -99 marks the printed dash/blank - the
// lasso and the needle (capture p. 79).
inline int dhaT49LLo(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 1;
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
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return -99;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        case 36:
            return 1;
        case 37:
            return -99;
        case 38:
            return 1;
        case 39:
            return 1;
        case 40:
            return 1;
        case 41:
            return 1;
        case 42:
            return 2;
        case 43:
            return 1;
        case 44:
            return 1;
        case 45:
            return 1;
        case 46:
            return 1;
        case 47:
            return 1;
        case 48:
            return 1;
        case 49:
            return 1;
        case 50:
            return 1;
        case 51:
            return 2;
        case 52:
            return 1;
        case 53:
            return 3;
        case 54:
            return 2;
        case 55:
            return 1;
        case 56:
            return 1;
        case 57:
            return 2;
        case 58:
            return 1;
        case 59:
            return 1;
        case 60:
            return 3;
        case 61:
            return 1;
        case 62:
            return 1;
        case 63:
            return 1;
        case 64:
            return 3;
        case 65:
            return 1;
        case 66:
            return 1;
        case 67:
            return 1;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the damage vs size L upper bound (capture p. 79).
inline int dhaT49LHi(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 6;
        case 4:
            return 6;
        case 5:
            return 8;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 8;
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
            return 4;
        case 17:
            return 2;
        case 18:
            return 12;
        case 19:
            return 6;
        case 20:
            return 2;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 12;
        case 24:
            return 6;
        case 25:
            return 2;
        case 26:
            return 2;
        case 27:
            return 3;
        case 28:
            return 4;
        case 29:
            return 4;
        case 30:
            return 10;
        case 31:
            return 8;
        case 32:
            return -99;
        case 33:
            return 6;
        case 34:
            return 2;
        case 35:
            return 8;
        case 36:
            return 10;
        case 37:
            return -99;
        case 38:
            return 3;
        case 39:
            return 6;
        case 40:
            return 6;
        case 41:
            return 8;
        case 42:
            return 7;
        case 43:
            return 4;
        case 44:
            return 2;
        case 45:
            return 6;
        case 46:
            return 4;
        case 47:
            return 3;
        case 48:
            return 4;
        case 49:
            return 4;
        case 50:
            return 4;
        case 51:
            return 7;
        case 52:
            return 4;
        case 53:
            return 9;
        case 54:
            return 8;
        case 55:
            return 3;
        case 56:
            return 8;
        case 57:
            return 7;
        case 58:
            return 12;
        case 59:
            return 8;
        case 60:
            return 18;
        case 61:
            return 4;
        case 62:
            return 8;
        case 63:
            return 4;
        case 64:
            return 12;
        case 65:
            return 4;
        case 66:
            return 4;
        case 67:
            return 8;
        case 68:
            return 1;
        default:
            return -99;
        }
    }

// the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32,
// g=64, h=128; 0 = no letter (capture pp. 79-80).
inline int dhaT49SmNote(int b)
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
            return 8;
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
        default:
            return -99;
        }
    }

// the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32,
// g=64, h=128; 0 = no letter (capture pp. 79-80).
inline int dhaT49LNote(int b)
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
            return 128;
        case 6:
            return 128;
        case 7:
            return 32;
        case 8:
            return 0;
        case 9:
            return 224;
        case 10:
            return 64;
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
            return 16;
        case 17:
            return 32;
        case 18:
            return 128;
        case 19:
            return 0;
        case 20:
            return 16;
        case 21:
            return 32;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 16;
        case 25:
            return 72;
        case 26:
            return 32;
        case 27:
            return 8;
        case 28:
            return 72;
        case 29:
            return 72;
        case 30:
            return 32;
        case 31:
            return 1;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 0;
        case 35:
            return 2;
        case 36:
            return 2;
        case 37:
            return 0;
        case 38:
            return 8;
        case 39:
            return 8;
        case 40:
            return 16;
        case 41:
            return 0;
        case 42:
            return 0;
        case 43:
            return 0;
        case 44:
            return 16;
        case 45:
            return 16;
        case 46:
            return 8;
        case 47:
            return 8;
        case 48:
            return 8;
        case 49:
            return 8;
        case 50:
            return 16;
        case 51:
            return 0;
        case 52:
            return 0;
        case 53:
            return 0;
        case 54:
            return 0;
        case 55:
            return 64;
        case 56:
            return 34;
        case 57:
            return 128;
        case 58:
            return 128;
        case 59:
            return 132;
        case 60:
            return 128;
        case 61:
            return 8;
        case 62:
            return 32;
        case 63:
            return 16;
        case 64:
            return 128;
        case 65:
            return 16;
        case 66:
            return 0;
        case 67:
            return 0;
        case 68:
            return 64;
        default:
            return -99;
        }
    }

// 1 marks the printed asterisk rows - the javelin, naginata and spear, the
// set-weapon note (capture p. 79); 0 elsewhere.
inline int dhaT49Star(int b)
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
            return 1;
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
            return 1;
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
            return 1;
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
        default:
            return -99;
        }
    }

// T49 note (capture p. 79): weapons listed in boldface require two hands to
// use - the boldface set itself is lost to the OCR
inline bool dhaT49BoldfaceTwoHands()
    { return true; }

// T49 star footnote (capture p. 80): these weapons do twice the damage
// indicated to size L creatures when set firmly grounded to receive a
// charging opponent
inline bool dhaT49StarSetNote()
    { return true; }

// T49 footnote a (capture p. 80): these weapons do twice the indicated damage
// against creatures of any size when employed by an attacker riding a
// charging mount
inline bool dhaT49NoteA()
    { return true; }

// T49 footnote b (capture p. 80): these weapons do twice the damage indicated
// to any opponent when the weapon is set to receive their charge
inline bool dhaT49NoteB()
    { return true; }

// T49 footnote c (capture p. 80): this weapon class includes all pointed
// cutting and thrusting weapons with a blade length between 15 and 24 inches,
// except as noted in the listing
inline bool dhaT49NoteC()
    { return true; }

// T49 footnote d (capture p. 80): these weapons are primarily used by ninja
// characters
inline bool dhaT49NoteD()
    { return true; }

// T49 footnote e (capture p. 80): these weapons can only be used with martial
// arts weapon styles and can be used to perform the weapon style special
// maneuvers
inline bool dhaT49NoteE()
    { return true; }

// T49 footnote f (capture p. 80): these weapons can be used to perform the
// martial arts weapon style special maneuvers
inline bool dhaT49NoteF()
    { return true; }

// T49 footnote g (capture p. 80): these weapons can make entangling attacks
inline bool dhaT49NoteG()
    { return true; }

// T49 footnote h (capture p. 80): minor variations of these weapons, with
// different names, may exist in the campaign - see the Weapon Equivalents
// listing for particulars
inline bool dhaT49NoteH()
    { return true; }

}   // namespace rules
