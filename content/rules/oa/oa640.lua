-- oa640: promoted from rules/oaweapon.h (the WEAPONS OPENER, TABLE 48 AND TABLE 49, printed capture pp. 79-80 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 640,
  "prefix" = "oa640",
  "banner" = {
      "title" = "WEAPONS OPENER, TABLE 48 AND TABLE 49, printed capture pp. 79-80 - the OA",
      "provenance" = "weapons round census 562 -> 563.  pinned from the 2018 print capture alone for this range (the settling authority): the first Mistral-OCR capture session is unavailable above p. 33, so the cross-capture agreement check is impossible. The weapons opener and equivalents prose pin from capture p. 79 (printed p. 41), T48 and T49 from capture p. 79, and the T49 footnotes from capture p. 80 (printed p. 42) - T49's page directs to the footnotes at the bottom of the next page, where they print under T50 and serve both tables. T48 pins as the 16-row equivalent-count grid, the name lists riding the column comment (textual cells, the count is the pinnable datum). T49 pins as the 69-row weight-damage grid: the weight bounds (the lone numbers as lo=hi, the spear 40-60, the two-handed sword 150-250 and the whip 25-35 as printed ranges), the S-M and L damage bounds with -99 marking the printed dashes (the lasso, the needle's blank vs-L cell), the a-h footnote letters as bitmasks, and the javelin, naginata and spear stars. No contested cells detected within the single source. OCR normalizations: the boldface two-hand set is lost to the OCR - the NOTE pins as a bool, the set does not; the T49 mace row prints no footnote letter while the T50 mace row carries h - T49 pins as printed; the kawanga row spells as printed (the R639 T47 arms list printed kawanaga) and the T49 arrow standard row spells as printed (T47 printed arrow, normal) - both pin as printed. The Weapons prose and weapon descriptions box stays open (the descriptions pin later); Table 50 (capture p. 80) is deliberately left for the next round  the gap census after this round: 91 closed, 144 open - the Table 48 and Table 49 boxes flip (census 562 -> 563); NEXT - R641: Table 50 (Hand Held Weapons, General Data and To Hit Adjustments), capture p. 80, the hand-held AC adjustment grid, prefix dhb (verify free), audit \"R641 OA handheld audit\", include after rules/oaweapon.h",
    },
  "consts" = { {
      "name" = "dhaT48RowCount",
      "value" = 16,
      "comment" = "Table 48 (capture p. 79): sixteen weapon equivalent rows",
    }, {
      "name" = "dhaT49RowCount",
      "value" = 69,
      "comment" = "Table 49 (capture p. 79): sixty-nine weapon type rows",
    } },
  "bools" = { {
      "name" = "dhaWeaponsEnglishNames",
      "value" = true,
      "comment" = "weapon equivalents prose (capture p. 79): a number of weapons are listed by their common English names",
    }, {
      "name" = "dhaWeaponsManyNames",
      "value" = true,
      "comment" = "weapon equivalents prose (capture p. 79): these weapons are known by many different names in many different lands - some listed below",
    }, {
      "name" = "dhaWeaponsAppearanceDiff",
      "value" = true,
      "comment" = "weapon equivalents prose (capture p. 79): there may be slight differences in appearance between the equivalent weapons",
    }, {
      "name" = "dhaWeaponsFunctionSame",
      "value" = true,
      "comment" = "weapon equivalents prose (capture p. 79): the appearance differences do not affect the general function of the weapon",
    }, {
      "name" = "dhaT49BoldfaceTwoHands",
      "value" = true,
      "comment" = "T49 note (capture p. 79): weapons listed in boldface require two hands to use - the boldface set itself is lost to the OCR",
    }, {
      "name" = "dhaT49StarSetNote",
      "value" = true,
      "comment" = "T49 star footnote (capture p. 80): these weapons do twice the damage indicated to size L creatures when set firmly grounded to receive a charging opponent",
    }, {
      "name" = "dhaT49NoteA",
      "value" = true,
      "comment" = "T49 footnote a (capture p. 80): these weapons do twice the indicated damage against creatures of any size when employed by an attacker riding a charging mount",
    }, {
      "name" = "dhaT49NoteB",
      "value" = true,
      "comment" = "T49 footnote b (capture p. 80): these weapons do twice the damage indicated to any opponent when the weapon is set to receive their charge",
    }, {
      "name" = "dhaT49NoteC",
      "value" = true,
      "comment" = "T49 footnote c (capture p. 80): this weapon class includes all pointed cutting and thrusting weapons with a blade length between 15 and 24 inches, except as noted in the listing",
    }, {
      "name" = "dhaT49NoteD",
      "value" = true,
      "comment" = "T49 footnote d (capture p. 80): these weapons are primarily used by ninja characters",
    }, {
      "name" = "dhaT49NoteE",
      "value" = true,
      "comment" = "T49 footnote e (capture p. 80): these weapons can only be used with martial arts weapon styles and can be used to perform the weapon style special maneuvers",
    }, {
      "name" = "dhaT49NoteF",
      "value" = true,
      "comment" = "T49 footnote f (capture p. 80): these weapons can be used to perform the martial arts weapon style special maneuvers",
    }, {
      "name" = "dhaT49NoteG",
      "value" = true,
      "comment" = "T49 footnote g (capture p. 80): these weapons can make entangling attacks",
    }, {
      "name" = "dhaT49NoteH",
      "value" = true,
      "comment" = "T49 footnote h (capture p. 80): minor variations of these weapons, with different names, may exist in the campaign - see the Weapon Equivalents listing for particulars",
    } },
  "switches" = { {
      "name" = "dhaT48EquivCount",
      "values" = { 11, 2, 2, 2, 4, 4, 1, 2, 2, 1, 2, 1, 1, 1, 1, 2 },
      "default" = -99,
      "comment" = "the equivalent-name count by row - 0 Axe, battle (Fu, liu, ch'iang, chi, chin, yueh, chien, ch'i fu, i huang, masakari, ono), 1 Axe, hand (Piso tonkeng, batak kapak), 2 Bo stick (Rokushakubo, staff), 3 Chain (Manriki gusari, rante), 4 Dagger (tanto, do-su, kozuka, aikuchi), 5 Halberd (Ko, ch'i chi, pi chi, bisento), 6 Javelin (mau), 7 Jo stick (Muton, amis), 8 Lance, light (Hsaio, shuo), 9 Mace (Suan Tao Fung), 10 Pike (Mao, lembing), 11 Spear (Yari), 12 Sword, long (Tau-kien), 13 Sword, short (Kris), 14 Sword, two-handed (No-dachi), 15 Trident (Magari yari, tiger lance) (capture p. 79).",
    }, {
      "name" = "dhaT49WeightLo",
      "values" = { 2, 2, 2, 2, 2, 75, 50, 40, 30, 30, 60, 1, 30, 10, 1, 5, 30, 10, 175, 20, 15, 15, 20, 60, 40, 10, 5, 15, 30, 10, 60, 50, 20, 100, 80, 60, 100, 1, 5, 50, 30, 50, 2, 1, 20, 100, 5, 1, 2, 1, 5, 2, 1, 5, 4, 50, 40, 75, 60, 35, 150, 3, 75, 50, 50, 15, 5, 30, 25 },
      "default" = -99,
      "comment" = "the approximate weight lower bound, by weapon row - 0 Arrow, armor piercer, 1 Arrow, frog crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow, standard, 5 Axe, battle, 6 Axe, hand or throwing, 7 Bo stick, 8 Boku-toh, 9 Chain, 10 Chijiriki, 11 Chopsticks, 12 Club, 13 Dagger, 14 Dart, blowgun, 15 Dart, thrown, 16 Fang, 17 Gunsen, 18 Halberd, 19 Javelin, 20 Jitte, 21 Jo stick, 22 Kama, 23 Katana, 24 Kau sin ke, 25 Kawanga, 26 Kiseru, 27 Kumade, 28 Kusari-gama, 29 Kyoketsu-shogi, 30 Lajatang, 31 Lance (light horse), 32 Lasso, 33 Mace, 34 Man catcher, 35 Nagimaki, 36 Naginata, 37 Needle, 38 Nekode, 39 Ninja-to, 40 Nunchaku, 41 Parang, 42 Quarrel, heavy, 43 Quarrel, light, 44 Sai, 45 Sang kauw, 46 Shaken, 47 Shuriken, spike, 48 Shuriken, star, large, 49 Shuriken, star, small, 50 Siangkam, 51 Sling/pellet bow bullet, 52 Sling/pellet bow stone, 53 Sling, staff bullet, 54 Sling, staff stone, 55 Sode garami, 56 Spear, 57 Sword, broad, 58 Sword, long, 59 Sword, short, 60 Sword, two-handed, 61 Tetsu-bishi, 62 Tetsubo, 63 Three-piece rod, 64 Trident, 65 Tui-fa (Tonfa), 66 Uchi-ne, 67 Wakizashi, 68 Whip; a lone number prints as lo=hi, the spear 40-60, the two-handed sword 150-250 and the whip 25-35 print as ranges (capture p. 79).",
    }, {
      "name" = "dhaT49WeightHi",
      "values" = { 2, 2, 2, 2, 2, 75, 50, 40, 30, 30, 60, 1, 30, 10, 1, 5, 30, 10, 175, 20, 15, 15, 20, 60, 40, 10, 5, 15, 30, 10, 60, 50, 20, 100, 80, 60, 100, 1, 5, 50, 30, 50, 2, 1, 20, 100, 5, 1, 2, 1, 5, 2, 1, 5, 4, 50, 60, 75, 60, 35, 250, 3, 75, 50, 50, 15, 5, 30, 35 },
      "default" = -99,
      "comment" = "the approximate weight upper bound (capture p. 79).",
    }, {
      "name" = "dhaT49SmLo",
      "values" = { 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -99, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
      "default" = -99,
      "comment" = "the damage vs size S or M lower bound, dice lo-hi; -99 marks the printed dash - the lasso has no damage and the needle reads 1 per needle (capture p. 79).",
    }, {
      "name" = "dhaT49SmHi",
      "values" = { 5, 6, 2, 8, 6, 8, 6, 6, 4, 5, 6, 3, 6, 4, 2, 3, 6, 3, 10, 6, 4, 6, 6, 10, 8, 3, 4, 4, 6, 4, 10, 6, -99, 7, 2, 6, 8, 1, 4, 8, 6, 8, 5, 4, 4, 8, 4, 4, 6, 4, 5, 5, 4, 8, 8, 4, 6, 8, 8, 6, 10, 4, 8, 6, 7, 6, 4, 8, 2 },
      "default" = -99,
      "comment" = "the damage vs size S or M upper bound (capture p. 79).",
    }, {
      "name" = "dhaT49LLo",
      "values" = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -99, 1, 1, 1, 1, -99, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 2, 1, 1, 2, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 1 },
      "default" = -99,
      "comment" = "the damage vs size L lower bound; -99 marks the printed dash/blank - the lasso and the needle (capture p. 79).",
    }, {
      "name" = "dhaT49LHi",
      "values" = { 4, 3, 2, 6, 6, 8, 4, 4, 2, 4, 8, 2, 3, 3, 1, 2, 4, 2, 12, 6, 2, 3, 4, 12, 6, 2, 2, 3, 4, 4, 10, 8, -99, 6, 2, 8, 10, -99, 3, 6, 6, 8, 7, 4, 2, 6, 4, 3, 4, 4, 4, 7, 4, 9, 8, 3, 8, 7, 12, 8, 18, 4, 8, 4, 12, 4, 4, 8, 1 },
      "default" = -99,
      "comment" = "the damage vs size L upper bound (capture p. 79).",
    }, {
      "name" = "dhaT49SmNote",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128; 0 = no letter (capture pp. 79-80).",
    }, {
      "name" = "dhaT49LNote",
      "values" = { 0, 0, 0, 0, 0, 128, 128, 32, 0, 224, 64, 0, 0, 0, 0, 0, 16, 32, 128, 0, 16, 32, 0, 0, 16, 72, 32, 8, 72, 72, 32, 1, 0, 0, 0, 2, 2, 0, 8, 8, 16, 0, 0, 0, 16, 16, 8, 8, 8, 8, 16, 0, 0, 0, 0, 64, 34, 128, 128, 132, 128, 8, 32, 16, 128, 16, 0, 0, 64 },
      "default" = -99,
      "comment" = "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128; 0 = no letter (capture pp. 79-80).",
    }, {
      "name" = "dhaT49Star",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "1 marks the printed asterisk rows - the javelin, naginata and spear, the set-weapon note (capture p. 79); 0 elsewhere.",
    } },
  "tables" = { {
      "name" = "dhaT48Grid",
      "tag" = "T48Equiv",
      "count" = "dhaT48RowCount",
      "sentinel" = -99,
      "cols" = { "dhaT48EquivCount" },
      "data" = { { 11 }, { 2 }, { 2 }, { 2 }, { 4 }, { 4 }, { 1 }, { 2 }, { 2 }, { 1 }, { 2 }, { 1 }, { 1 }, { 1 }, { 1 }, { 2 } },
      "comment" = "the Table 48 weapon equivalents grid (capture p. 79)",
      "col_comments" = { "the equivalent-name count by row - 0 Axe, battle (Fu, liu, ch'iang, chi, chin, yueh, chien, ch'i fu, i huang, masakari, ono), 1 Axe, hand (Piso tonkeng, batak kapak), 2 Bo stick (Rokushakubo, staff), 3 Chain (Manriki gusari, rante), 4 Dagger (tanto, do-su, kozuka, aikuchi), 5 Halberd (Ko, ch'i chi, pi chi, bisento), 6 Javelin (mau), 7 Jo stick (Muton, amis), 8 Lance, light (Hsaio, shuo), 9 Mace (Suan Tao Fung), 10 Pike (Mao, lembing), 11 Spear (Yari), 12 Sword, long (Tau-kien), 13 Sword, short (Kris), 14 Sword, two-handed (No-dachi), 15 Trident (Magari yari, tiger lance) (capture p. 79)." },
      "audit_comment" = "the Table 48 grid: the equivalent-name counts (capture p. 79)",
      "sentinel_census" = { 0 },
    }, {
      "name" = "dhaT49Grid",
      "tag" = "T49Data",
      "count" = "dhaT49RowCount",
      "sentinel" = -99,
      "cols" = { "dhaT49WeightLo", "dhaT49WeightHi", "dhaT49SmLo", "dhaT49SmHi", "dhaT49LLo", "dhaT49LHi", "dhaT49SmNote", "dhaT49LNote", "dhaT49Star" },
      "data" = { { 2, 2, 2, 5, 1, 4, 0, 0, 0 }, { 2, 2, 1, 6, 1, 3, 0, 0, 0 }, { 2, 2, 1, 2, 1, 2, 0, 0, 0 }, { 2, 2, 1, 8, 1, 6, 0, 0, 0 }, { 2, 2, 1, 6, 1, 6, 0, 0, 0 }, { 75, 75, 1, 8, 1, 8, 0, 128, 0 }, { 50, 50, 1, 6, 1, 4, 0, 128, 0 }, { 40, 40, 1, 6, 1, 4, 0, 32, 0 }, { 30, 30, 1, 4, 1, 2, 0, 0, 0 }, { 30, 30, 2, 5, 1, 4, 0, 224, 0 }, { 60, 60, 1, 6, 1, 8, 0, 64, 0 }, { 1, 1, 1, 3, 1, 2, 0, 0, 0 }, { 30, 30, 1, 6, 1, 3, 0, 0, 0 }, { 10, 10, 1, 4, 1, 3, 0, 0, 0 }, { 1, 1, 1, 2, 1, 1, 0, 0, 0 }, { 5, 5, 1, 3, 1, 2, 0, 0, 0 }, { 30, 30, 1, 6, 1, 4, 0, 16, 0 }, { 10, 10, 1, 3, 1, 2, 0, 32, 0 }, { 175, 175, 1, 10, 1, 12, 0, 128, 0 }, { 20, 20, 1, 6, 1, 6, 0, 0, 1 }, { 15, 15, 1, 4, 1, 2, 0, 16, 0 }, { 15, 15, 1, 6, 1, 3, 0, 32, 0 }, { 20, 20, 1, 6, 1, 4, 0, 0, 0 }, { 60, 60, 1, 10, 1, 12, 0, 0, 0 }, { 40, 40, 1, 8, 1, 6, 0, 16, 0 }, { 10, 10, 1, 3, 1, 2, 0, 72, 0 }, { 5, 5, 1, 4, 1, 2, 0, 32, 0 }, { 15, 15, 1, 4, 1, 3, 0, 8, 0 }, { 30, 30, 1, 6, 1, 4, 0, 72, 0 }, { 10, 10, 1, 4, 1, 4, 0, 72, 0 }, { 60, 60, 1, 10, 1, 10, 0, 32, 0 }, { 50, 50, 1, 6, 1, 8, 0, 1, 0 }, { 20, 20, -99, -99, -99, -99, 0, 0, 0 }, { 100, 100, 2, 7, 1, 6, 0, 0, 0 }, { 80, 80, 1, 2, 1, 2, 0, 0, 0 }, { 60, 60, 1, 6, 1, 8, 0, 2, 0 }, { 100, 100, 1, 8, 1, 10, 0, 2, 1 }, { 1, 1, 1, 1, -99, -99, 8, 0, 0 }, { 5, 5, 1, 4, 1, 3, 0, 8, 0 }, { 50, 50, 1, 8, 1, 6, 0, 8, 0 }, { 30, 30, 1, 6, 1, 6, 0, 16, 0 }, { 50, 50, 1, 8, 1, 8, 0, 0, 0 }, { 2, 2, 2, 5, 2, 7, 0, 0, 0 }, { 1, 1, 1, 4, 1, 4, 0, 0, 0 }, { 20, 20, 1, 4, 1, 2, 0, 16, 0 }, { 100, 100, 1, 8, 1, 6, 0, 16, 0 }, { 5, 5, 1, 4, 1, 4, 0, 8, 0 }, { 1, 1, 1, 4, 1, 3, 0, 8, 0 }, { 2, 2, 1, 6, 1, 4, 0, 8, 0 }, { 1, 1, 1, 4, 1, 4, 0, 8, 0 }, { 5, 5, 2, 5, 1, 4, 0, 16, 0 }, { 2, 2, 2, 5, 2, 7, 0, 0, 0 }, { 1, 1, 1, 4, 1, 4, 0, 0, 0 }, { 5, 5, 2, 8, 3, 9, 0, 0, 0 }, { 4, 4, 1, 8, 2, 8, 0, 0, 0 }, { 50, 50, 1, 4, 1, 3, 0, 64, 0 }, { 40, 60, 1, 6, 1, 8, 0, 34, 1 }, { 75, 75, 2, 8, 2, 7, 0, 128, 0 }, { 60, 60, 1, 8, 1, 12, 0, 128, 0 }, { 35, 35, 1, 6, 1, 8, 0, 132, 0 }, { 150, 250, 1, 10, 3, 18, 0, 128, 0 }, { 3, 3, 1, 4, 1, 4, 0, 8, 0 }, { 75, 75, 1, 8, 1, 8, 0, 32, 0 }, { 50, 50, 1, 6, 1, 4, 0, 16, 0 }, { 50, 50, 2, 7, 3, 12, 0, 128, 0 }, { 15, 15, 1, 6, 1, 4, 0, 16, 0 }, { 5, 5, 1, 4, 1, 4, 0, 0, 0 }, { 30, 30, 1, 8, 1, 8, 0, 0, 0 }, { 25, 35, 1, 2, 1, 1, 0, 64, 0 } },
      "comment" = "the Table 49 weight and damage grid (capture p. 79)",
      "col_comments" = { "the approximate weight lower bound, by weapon row - 0 Arrow, armor piercer, 1 Arrow, frog crotch, 2 Arrow, humming bulb, 3 Arrow, leaf head, 4 Arrow, standard, 5 Axe, battle, 6 Axe, hand or throwing, 7 Bo stick, 8 Boku-toh, 9 Chain, 10 Chijiriki, 11 Chopsticks, 12 Club, 13 Dagger, 14 Dart, blowgun, 15 Dart, thrown, 16 Fang, 17 Gunsen, 18 Halberd, 19 Javelin, 20 Jitte, 21 Jo stick, 22 Kama, 23 Katana, 24 Kau sin ke, 25 Kawanga, 26 Kiseru, 27 Kumade, 28 Kusari-gama, 29 Kyoketsu-shogi, 30 Lajatang, 31 Lance (light horse), 32 Lasso, 33 Mace, 34 Man catcher, 35 Nagimaki, 36 Naginata, 37 Needle, 38 Nekode, 39 Ninja-to, 40 Nunchaku, 41 Parang, 42 Quarrel, heavy, 43 Quarrel, light, 44 Sai, 45 Sang kauw, 46 Shaken, 47 Shuriken, spike, 48 Shuriken, star, large, 49 Shuriken, star, small, 50 Siangkam, 51 Sling/pellet bow bullet, 52 Sling/pellet bow stone, 53 Sling, staff bullet, 54 Sling, staff stone, 55 Sode garami, 56 Spear, 57 Sword, broad, 58 Sword, long, 59 Sword, short, 60 Sword, two-handed, 61 Tetsu-bishi, 62 Tetsubo, 63 Three-piece rod, 64 Trident, 65 Tui-fa (Tonfa), 66 Uchi-ne, 67 Wakizashi, 68 Whip; a lone number prints as lo=hi, the spear 40-60, the two-handed sword 150-250 and the whip 25-35 print as ranges (capture p. 79).", "the approximate weight upper bound (capture p. 79).", "the damage vs size S or M lower bound, dice lo-hi; -99 marks the printed dash - the lasso has no damage and the needle reads 1 per needle (capture p. 79).", "the damage vs size S or M upper bound (capture p. 79).", "the damage vs size L lower bound; -99 marks the printed dash/blank - the lasso and the needle (capture p. 79).", "the damage vs size L upper bound (capture p. 79).", "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128; 0 = no letter (capture pp. 79-80).", "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128; 0 = no letter (capture pp. 79-80).", "1 marks the printed asterisk rows - the javelin, naginata and spear, the set-weapon note (capture p. 79); 0 elsewhere." },
      "audit_comment" = "the Table 49 grid: weights, damage bounds, footnote bitmasks, stars (capture p. 79)",
      "sentinel_census" = { 0, 0, 1, 1, 2, 2, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhaT48RowCount']() != 16  or m['dhaT49RowCount']() != 69  or  m['dhaWeaponsEnglishNames']() != 1  or  m['dhaWeaponsManyNames']() != 1  or  m['dhaWeaponsAppearanceDiff']() != 1  or  m['dhaWeaponsFunctionSame']() != 1  or  m['dhaT49BoldfaceTwoHands']() != 1  or  m['dhaT49StarSetNote']() != 1  or  m['dhaT49NoteA']() != 1  or  m['dhaT49NoteB']() != 1  or  m['dhaT49NoteC']() != 1  or  m['dhaT49NoteD']() != 1  or  m['dhaT49NoteE']() != 1  or  m['dhaT49NoteF']() != 1  or  m['dhaT49NoteG']() != 1  or  m['dhaT49NoteH']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhaT48RowCount']() != 16",
      "note" = "the T48 row count pin",
    }, {
      "expr" = "m['dhaT49RowCount']() != 69",
      "note" = "the T49 row count pin",
    }, {
      "expr" = "m['dhaWeaponsEnglishNames']() != 1",
      "note" = "the WeaponsEnglishNames pin",
    }, {
      "expr" = "m['dhaWeaponsManyNames']() != 1",
      "note" = "the WeaponsManyNames pin",
    }, {
      "expr" = "m['dhaWeaponsAppearanceDiff']() != 1",
      "note" = "the WeaponsAppearanceDiff pin",
    }, {
      "expr" = "m['dhaWeaponsFunctionSame']() != 1",
      "note" = "the WeaponsFunctionSame pin",
    }, {
      "expr" = "m['dhaT49BoldfaceTwoHands']() != 1",
      "note" = "the T49BoldfaceTwoHands pin",
    }, {
      "expr" = "m['dhaT49StarSetNote']() != 1",
      "note" = "the T49StarSetNote pin",
    }, {
      "expr" = "m['dhaT49NoteA']() != 1",
      "note" = "the T49NoteA pin",
    }, {
      "expr" = "m['dhaT49NoteB']() != 1",
      "note" = "the T49NoteB pin",
    }, {
      "expr" = "m['dhaT49NoteC']() != 1",
      "note" = "the T49NoteC pin",
    }, {
      "expr" = "m['dhaT49NoteD']() != 1",
      "note" = "the T49NoteD pin",
    }, {
      "expr" = "m['dhaT49NoteE']() != 1",
      "note" = "the T49NoteE pin",
    }, {
      "expr" = "m['dhaT49NoteF']() != 1",
      "note" = "the T49NoteF pin",
    }, {
      "expr" = "m['dhaT49NoteG']() != 1",
      "note" = "the T49NoteG pin",
    }, {
      "expr" = "m['dhaT49NoteH']() != 1",
      "note" = "the T49NoteH pin",
    }, {
      "expr" = "m['dhaT48EquivCount'](0) != 11",
      "note" = "the T48 axe battle row - the eleven equivalents (capture p. 79)",
    }, {
      "expr" = "m['dhaT48EquivCount'](4) != 4  or m['dhaT48EquivCount'](5) != 4  or m['dhaT48EquivCount'](11) != 1",
      "note" = "the T48 dagger and halberd rows - four equivalents apiece; the lone spear yari (capture p. 79)",
    }, {
      "expr" = "m['dhaT49WeightLo'](23) != 60  or m['dhaT49SmLo'](23) != 1  or m['dhaT49SmHi'](23) != 10  or m['dhaT49LLo'](23) != 1  or m['dhaT49LHi'](23) != 12",
      "note" = "the T49 katana row - weight 60, 1-10 vs S-M, 1-12 vs L (capture p. 79)",
    }, {
      "expr" = "m['dhaT49WeightLo'](18) != 175  or m['dhaT49SmHi'](18) != 10  or m['dhaT49LHi'](18) != 12  or m['dhaT49LNote'](18) != 128",
      "note" = "the T49 halberd row - weight 175, 1-10 vs S-M, 1-12 vs L with the h letter (capture p. 79)",
    }, {
      "expr" = "m['dhaT49LNote'](9) != 224  or m['dhaT49WeightLo'](9) != 30",
      "note" = "the T49 chain row - the f, g, h letters bitmask 224 (capture p. 79)",
    }, {
      "expr" = "m['dhaT49WeightLo'](56) != 40  or m['dhaT49WeightHi'](56) != 60  or m['dhaT49LNote'](56) != 34  or m['dhaT49Star'](56) != 1",
      "note" = "the T49 spear row - the 40-60 weight range, the b and f letters 34, the star (capture p. 79)",
    }, {
      "expr" = "m['dhaT49WeightLo'](60) != 150  or m['dhaT49WeightHi'](60) != 250  or m['dhaT49LLo'](60) != 3  or m['dhaT49LHi'](60) != 18",
      "note" = "the T49 two-handed sword row - the 150-250 weight range, 1-10 vs S-M, 3-18 vs L (capture p. 79)",
    }, {
      "expr" = "m['dhaT49SmLo'](32) != -99  or m['dhaT49SmHi'](32) != -99  or m['dhaT49LLo'](32) != -99  or m['dhaT49LHi'](32) != -99  or m['dhaT49WeightLo'](32) != 20",
      "note" = "the T49 lasso row - no damage, the -99 dashes (capture p. 79)",
    }, {
      "expr" = "m['dhaT49SmLo'](37) != 1  or m['dhaT49SmHi'](37) != 1  or m['dhaT49SmNote'](37) != 8  or m['dhaT49LLo'](37) != -99",
      "note" = "the T49 needle row - 1 per needle with the d letter, the blank vs-L cell (capture p. 79)",
    }, {
      "expr" = "m['dhaT49WeightLo'](68) != 25  or m['dhaT49WeightHi'](68) != 35  or m['dhaT49LHi'](68) != 1  or m['dhaT49LNote'](68) != 64",
      "note" = "the T49 whip row - the 25-35 weight range, 1-2 vs S-M, 1 vs L with the g letter (capture p. 79)",
    }, {
      "expr" = "m['dhaT49LNote'](59) != 132  or m['dhaT49WeightLo'](59) != 35",
      "note" = "the T49 sword short row - the c and h letters bitmask 132 (capture p. 79)",
    }, {
      "expr" = "m['dhaT49Star'](19) != 1  or m['dhaT49Star'](36) != 1  or m['dhaT49Star'](23) != 0",
      "note" = "the T49 stars - the javelin, naginata and spear; the unstarred katana (capture p. 79)",
    } },
  "audit" = {
      "label" = "R640 OA weapons audit",
      "comment" = "OA round twenty-seven (capture pp. 79-80): the weapons opener, the weapon equivalents and the Table 49 weight-damage grid",
    },
}
