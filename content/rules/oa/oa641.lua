-- oa641: promoted from rules/oahandheld.h (the TABLE 50 (HAND HELD WEAPONS, GENERAL DATA AND TO HIT ADJUSTMENTS), printed);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 641,
  "prefix" = "oa641",
  "banner" = {
      "title" = "TABLE 50 (HAND HELD WEAPONS, GENERAL DATA AND TO HIT ADJUSTMENTS), printed",
      "provenance" = "capture p. 80 - the OA hand-held weapons round census 563 -> 564.  pinned from the 2018 print capture (the settling authority), with the cross-capture check available for the first time above p. 33: the compressed-print capture OCR'd full this turn gives a second independent read of the page - the 49-row grid cross-checked cell-by-cell between the two passes; four cells contest and all settle per the print capture (the katana AC-8, sword-short AC-8 and tui-fa AC-9 cells read +1 in the print against the compressed -1, a non-monotonic dip that contradicts its own ladder - the R622 doctrine kills the compressed class; the jo-stick AC-5 cell reads -1 in the print against the compressed -2 - both ladder-consistent, the settling print read stands, the cell flags for the physical-copy check). T50 pins as the 49-row hand-held grid: the speed factor bounds (the lone numbers as lo=hi; the chijiriki-spear, spear and trident 6-8 and the whip 5-8 as printed ranges), the eleven-column AC 0-10 to-hit adjustment ladder, the footnote letters as the R640 bitmask (the mace h 128, the tetsu-bishi d 8), and the chijiriki-chain row - its printed dashes pin as -99 and its (see chain) cross-reference pins as a bool; the length and space-required columns are textual and ride the column comments per the T48 doctrine. The footnote texts are not re-pinned: the block printed under T50 serves both tables and was pinned in R640; the d and h lines reprint under the T50 tail serving the two marker rows. OCR normalizations: the names and lengths pin as printed (the kawanga spelling per the R640 settle; the compressed pass's 2* tetsu-bishi length reads as 2'; the plus-after-prime cells print as N + and pin as printed; the half-foot glyph rides the comment). The weapons descriptions prose box stays open; Table 51 (capture pp. 80-81) is deliberately left for the next round  the gap census after this round: 92 closed, 143 open - the Table 50 box flips (census 563 -> 564); NEXT - R642: Table 51 (Hurled Weapons and Missiles), capture pp. 80-81, the hurled-missile fire-rate and AC-adjustment grid, prefix dhc (verify free), audit \"R642 OA hurled audit\", include after rules/oahandheld.h",
    },
  "consts" = { {
      "name" = "dhbT50RowCount",
      "value" = 49,
      "comment" = "Table 50 (capture p. 80): forty-nine hand held weapon rows",
    }, {
      "name" = "dhbT50AcCount",
      "value" = 11,
      "comment" = "the AC adjustment ladder - armor classes 0 through 10, eleven columns (capture p. 80)",
    } },
  "bools" = { {
      "name" = "dhbT50ChijirikiSeeChain",
      "value" = true,
      "comment" = "the chijiriki, chain row prints dashes and directs to the chain row (see chain) - the chain row grid data serves (capture p. 80)",
    } },
  "switches" = { {
      "name" = "dhbT50SpeedLo",
      "values" = { 7, 4, 3, 4, 5, 6, -99, 2, 4, 2, 4, 2, 9, 2, 2, 4, 6, 7, 3, 4, 6, 5, 6, 7, 10, 7, 7, 6, 7, 2, 3, 3, 4, 2, 7, 3, 7, 6, 5, 5, 3, 10, 4, 7, 7, 6, 4, 4, 5 },
      "default" = -99,
      "comment" = "the speed factor lower bound, by weapon row - 0 Axe, battle, 1 Axe, hand, 2 Bo stick, 3 Boku-toh, 4 Chain, 5 Chijiriki, spear, 6 Chijiriki, chain, 7 Chopsticks, 8 Club, 9 Dagger, 10 Fang, 11 Gunsen, 12 Halberd, 13 Jitte, 14 Jo stick, 15 Katana, 16 Kau sin ke, 17 Kawanga, 18 Kiseru, 19 Kumade, 20 Kusari-gama, 21 Kyoketsu-shogi, 22 Lajatang, 23 Lance (light), 24 Lasso, 25 Mace, 26 Man catcher, 27 Nagimaki, 28 Naginata, 29 Nekode, 30 Ninja-to, 31 Nunchaku, 32 Parang, 33 Sai, 34 Sang kauw, 35 Siangkam, 36 Sode garami, 37 Spear, 38 Sword, broad, 39 Sword, long, 40 Sword, short, 41 Sword, two-handed, 42 Tetsu-bishi, 43 Tetsubo, 44 Three-piece rod, 45 Trident, 46 Tui-fa (Tonfa), 47 Wakizashi, 48 Whip; a lone number prints as lo=hi, the chijiriki-spear, spear and trident 6-8 and the whip 5-8 print as ranges, the chijiriki-chain dashes pin as -99 (capture p. 80).",
    }, {
      "name" = "dhbT50SpeedHi",
      "values" = { 7, 4, 3, 4, 5, 8, -99, 2, 4, 2, 4, 2, 9, 2, 2, 4, 6, 7, 3, 4, 6, 5, 6, 7, 10, 7, 7, 6, 7, 2, 3, 3, 4, 2, 7, 3, 7, 8, 5, 5, 3, 10, 4, 7, 7, 8, 4, 4, 8 },
      "default" = -99,
      "comment" = "the speed factor upper bound; the printed length and space-required cells ride this comment as length-by-space pairs: c. 4' by 4', c. 1.5' by 1', c. 5'-7' by 3', c. 3' by 3', 5'-10' by 5', c. 7'-10' by 1', the chijiriki-chain dashes, half-foot by half-foot, c. 3' by 1'-3', 1'-1.5' by 1', c. 3' by 1', 1' by 1', 5' + by 5', 1'-1.5' by 1', c. 3' by 2', c. 3' by 3', 4'-6' by 4', 8' + by 5', 2' by 1', 6' by 3', 2' + by 2' +, 6' + by 5', c. 5' by 3', 10' by 1', 10'-20' by 8' +, c. 3' by 4', 8' + by 2.5', 5'-8' by 1', 8' + by 1', half-foot by 1', c. 2' by 1', c. 3' by 4', c. 2' by 3', 1'-1.5' by 1', 3'-5' by 3', 1' by 3', 6' + by 5', 5'-10' by 1', c. 3.5' by 4', c. 3.5' by 3', c. 2' by 1', c. 6' by 6', 2' by 0, c. 4' by 5', c. 6' by 4', 4'-8' + by 1', 2' by 1', 2'-3' by 1', 8'-20' by 8'-20' - the textual cells pin nothing numeric, the roster order carries them (capture p. 80)",
    }, {
      "name" = "dhbT50Ac0",
      "values" = { -5, -5, -13, -7, -8, -2, -99, -16, -7, -4, -5, -14, 0, -4, -10, -5, 3, -8, -7, -6, -3, -8, -3, -3, 0, 2, 0, -3, -2, -8, -5, -8, -5, -4, -7, -8, -10, -2, -5, -4, -5, 2, 0, 2, -2, -4, -8, -5, -14 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 0 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac1",
      "values" = { -4, -4, -11, -6, -8, -2, -99, -14, -6, -4, -4, -12, 1, -3, -9, -4, 3, -8, -6, -6, -2, -8, -3, -3, 0, 2, 0, -3, -2, -7, -4, -7, -5, -3, -6, -7, -9, -2, -4, -3, -4, 2, 0, 2, -2, -3, -8, -4, -12 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 1 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac2",
      "values" = { -3, -3, -9, -5, -7, -2, -99, -12, -5, -3, -3, -10, 1, -2, -8, -3, 2, -8, -5, -5, -1, -8, -3, -2, 0, 1, 0, -2, -1, -7, -3, -6, -4, -2, -5, -6, -9, -2, -3, -2, -3, 2, 0, 1, -2, -3, -6, -3, -10 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 2 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac3",
      "values" = { -2, -2, -7, -4, -7, -1, -99, -10, -4, -3, -2, -8, 1, -1, -6, -2, 2, -6, -4, -5, -1, -6, -2, -2, 0, 1, 0, -2, -1, -6, -2, -4, -4, -1, -4, -5, -8, -1, -2, -1, -2, 2, 0, 1, -1, -2, -6, -2, -8 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 3 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac4",
      "values" = { -1, -2, -5, -3, -5, -1, -99, -8, -3, -2, -1, -6, 1, 0, -4, -1, 1, -6, -3, -3, -1, -6, -2, -1, 0, 0, 0, -1, 0, -5, -1, -2, -3, 0, -3, -4, -6, -1, -1, 0, -1, 2, 0, 0, -1, -1, -4, -1, -6 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 4 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac5",
      "values" = { -1, -1, -3, -2, -5, -1, -99, -6, -2, -2, 0, -4, 2, 0, -1, 0, 2, -4, -2, -2, 1, -4, -1, 0, 0, 0, 0, 0, 0, -4, 0, -2, -1, 0, -2, -3, -6, -1, 0, 0, 0, 2, 0, 0, 0, -1, -2, 0, -4 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 5 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac6",
      "values" = { 0, 0, -1, -1, -2, 0, -99, -4, -1, 0, 0, -3, 2, 0, -1, 0, 1, -4, -1, -2, 1, -4, 0, 0, 0, 0, 0, 0, 0, -3, 0, 0, 0, 0, -1, -2, -4, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, -2 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 6 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac7",
      "values" = { 0, 0, 0, 0, 0, 0, -99, -2, -1, 0, 0, -2, 2, 0, 0, 0, 1, -2, -1, -1, 1, -2, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, -1, -3, 0, 1, 0, 0, 3, 0, 0, 0, 0, 0, 0, -1 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 7 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac8",
      "values" = { 1, 1, 1, 0, 0, 0, -99, -1, 0, 1, 0, 0, 1, 0, 1, 1, 1, -1, 0, -1, 0, -1, 1, 0, 0, 0, -1, 0, 0, -1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 3, 0, 0, 0, 1, 0, 1, 1 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 8 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac9",
      "values" = { 1, 1, 0, -1, 1, 0, -99, -1, 0, 1, 0, -1, 1, -2, 0, 2, 1, -2, 0, 0, -1, -2, 1, 0, 0, 1, -2, 0, 0, 0, 0, 0, 1, -2, 0, -1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 9 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50Ac10",
      "values" = { 2, 2, 3, 0, 0, 0, -99, -1, 1, 3, 0, 0, 0, 0, 2, 3, -1, 0, 1, 1, 2, 1, 3, 0, 0, -1, -3, 0, 0, 0, 2, 3, 2, 0, 1, 0, 2, 0, 2, 2, 2, 0, 0, -1, 0, 1, 2, 0, 3 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 10 (capture p. 80); the chijiriki-chain row printed dash pins as -99.",
    }, {
      "name" = "dhbT50LNote",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128 per the R640 doctrine; the mace row carries h 128 and the tetsu-bishi d 8, 0 elsewhere (capture p. 80).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhbT50RowCount']() != 49  or m['dhbT50AcCount']() != 11  or  m['dhbT50ChijirikiSeeChain']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhbT50RowCount']() != 49",
      "note" = "the T50 row count pin",
    }, {
      "expr" = "m['dhbT50AcCount']() != 11",
      "note" = "the T50 AC ladder width pin",
    }, {
      "expr" = "m['dhbT50ChijirikiSeeChain']() != 1",
      "note" = "the ChijirikiSeeChain pin",
    }, {
      "expr" = "m['dhbT50Ac8'](15) != 1",
      "note" = "the katana row - the contested AC-8 cell settles +1 per the print capture (the compressed -1 dips non-monotonically between the AC-7 zero and the AC-9 plus-two)",
    }, {
      "expr" = "m['dhbT50Ac8'](40) != 1",
      "note" = "the sword, short row - the contested AC-8 cell settles +1 per the print capture (the same compressed dip class)",
    }, {
      "expr" = "m['dhbT50Ac9'](46) != 1",
      "note" = "the tui-fa row - the contested AC-9 cell settles +1 per the print capture (the compressed -1 dips between the AC-8 zero and the AC-10 plus-two)",
    }, {
      "expr" = "m['dhbT50Ac5'](14) != -1",
      "note" = "the jo stick row - the contested AC-5 cell settles -1 per the print capture (both readings ladder-consistent, the settling print read stands over the compressed -2)",
    }, {
      "expr" = "m['dhbT50Ac0'](2) != -13  or m['dhbT50Ac10'](2) != 3",
      "note" = "the bo stick row - the steepest ladder, AC 0 at -13 and AC 10 at plus-three (capture p. 80)",
    }, {
      "expr" = "m['dhbT50Ac0'](7) != -16",
      "note" = "the chopsticks row - the AC-0 floor at -16 (capture p. 80)",
    }, {
      "expr" = "m['dhbT50SpeedLo'](6) != -99  or m['dhbT50Ac0'](6) != -99  or m['dhbT50Ac10'](6) != -99",
      "note" = "the chijiriki, chain row - the -99 dashes across the grid, the cross-ref bool",
    }, {
      "expr" = "m['dhbT50SpeedLo'](5) != 6  or m['dhbT50SpeedHi'](5) != 8",
      "note" = "the chijiriki, spear row - the 6-8 speed range (capture p. 80)",
    }, {
      "expr" = "m['dhbT50SpeedLo'](37) != 6  or m['dhbT50SpeedHi'](37) != 8  or m['dhbT50Ac5'](37) != -1",
      "note" = "the spear row - the 6-8 speed range, the flat upper ladder (capture p. 80)",
    }, {
      "expr" = "m['dhbT50SpeedLo'](48) != 5  or m['dhbT50SpeedHi'](48) != 8  or m['dhbT50Ac0'](48) != -14",
      "note" = "the whip row - the 5-8 speed range, the AC-0 at -14 (capture p. 80)",
    }, {
      "expr" = "m['dhbT50LNote'](25) != 128",
      "note" = "the mace row - the h footnote letter, bitmask 128 (capture p. 80)",
    }, {
      "expr" = "m['dhbT50LNote'](42) != 8",
      "note" = "the tetsu-bishi row - the d footnote letter 8, the zero space pinning as data (capture p. 80)",
    }, {
      "expr" = "m['dhbT50Ac0'](24) != 0  or m['dhbT50Ac10'](24) != 0  or m['dhbT50SpeedLo'](24) != 10",
      "note" = "the lasso row - the all-zero ladder with speed 10 (capture p. 80)",
    }, {
      "expr" = "m['dhbT50Ac0'](41) != 2  or m['dhbT50Ac6'](41) != 3",
      "note" = "the sword, two-handed row - the +2 plateau into the +3 band (capture p. 80)",
    }, {
      "expr" = "m['dhbT50Ac8'](26) != -1  or m['dhbT50Ac10'](26) != -3",
      "note" = "the man catcher row - the zero ladder breaking at AC 8 through 10 (capture p. 80)",
    }, {
      "expr" = "m['dhbT50Ac0'](17) != -8",
      "note" = "the kawanga row - the AC-0 at -8, the printed spelling per the R640 settle riding the roster",
    }, {
      "expr" = "m['dhbT50Ac1'](0) != -4 or m['dhbT50Ac1'](1) != -4 or m['dhbT50Ac1'](2) != -11 or m['dhbT50Ac1'](3) != -6 or m['dhbT50Ac1'](4) != -8 or m['dhbT50Ac1'](5) != -2 or m['dhbT50Ac1'](6) != -99 or m['dhbT50Ac1'](7) != -14",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](8) != -6 or m['dhbT50Ac1'](9) != -4 or m['dhbT50Ac1'](10) != -4 or m['dhbT50Ac1'](11) != -12 or m['dhbT50Ac1'](12) != 1 or m['dhbT50Ac1'](13) != -3 or m['dhbT50Ac1'](14) != -9 or m['dhbT50Ac1'](15) != -4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](16) != 3 or m['dhbT50Ac1'](17) != -8 or m['dhbT50Ac1'](18) != -6 or m['dhbT50Ac1'](19) != -6 or m['dhbT50Ac1'](20) != -2 or m['dhbT50Ac1'](21) != -8 or m['dhbT50Ac1'](22) != -3 or m['dhbT50Ac1'](23) != -3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](24) != 0 or m['dhbT50Ac1'](25) != 2 or m['dhbT50Ac1'](26) != 0 or m['dhbT50Ac1'](27) != -3 or m['dhbT50Ac1'](28) != -2 or m['dhbT50Ac1'](29) != -7 or m['dhbT50Ac1'](30) != -4 or m['dhbT50Ac1'](31) != -7",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](32) != -5 or m['dhbT50Ac1'](33) != -3 or m['dhbT50Ac1'](34) != -6 or m['dhbT50Ac1'](35) != -7 or m['dhbT50Ac1'](36) != -9 or m['dhbT50Ac1'](37) != -2 or m['dhbT50Ac1'](38) != -4 or m['dhbT50Ac1'](39) != -3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](40) != -4 or m['dhbT50Ac1'](41) != 2 or m['dhbT50Ac1'](42) != 0 or m['dhbT50Ac1'](43) != 2 or m['dhbT50Ac1'](44) != -2 or m['dhbT50Ac1'](45) != -3 or m['dhbT50Ac1'](46) != -8 or m['dhbT50Ac1'](47) != -4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac1'](48) != -12 or m['dhbT50Ac1'](49) != -99 or m['dhbT50Ac2'](0) != -3 or m['dhbT50Ac2'](1) != -3 or m['dhbT50Ac2'](2) != -9 or m['dhbT50Ac2'](3) != -5 or m['dhbT50Ac2'](4) != -7 or m['dhbT50Ac2'](5) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](6) != -99 or m['dhbT50Ac2'](7) != -12 or m['dhbT50Ac2'](8) != -5 or m['dhbT50Ac2'](9) != -3 or m['dhbT50Ac2'](10) != -3 or m['dhbT50Ac2'](11) != -10 or m['dhbT50Ac2'](12) != 1 or m['dhbT50Ac2'](13) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](14) != -8 or m['dhbT50Ac2'](15) != -3 or m['dhbT50Ac2'](16) != 2 or m['dhbT50Ac2'](17) != -8 or m['dhbT50Ac2'](18) != -5 or m['dhbT50Ac2'](19) != -5 or m['dhbT50Ac2'](20) != -1 or m['dhbT50Ac2'](21) != -8",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](22) != -3 or m['dhbT50Ac2'](23) != -2 or m['dhbT50Ac2'](24) != 0 or m['dhbT50Ac2'](25) != 1 or m['dhbT50Ac2'](26) != 0 or m['dhbT50Ac2'](27) != -2 or m['dhbT50Ac2'](28) != -1 or m['dhbT50Ac2'](29) != -7",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](30) != -3 or m['dhbT50Ac2'](31) != -6 or m['dhbT50Ac2'](32) != -4 or m['dhbT50Ac2'](33) != -2 or m['dhbT50Ac2'](34) != -5 or m['dhbT50Ac2'](35) != -6 or m['dhbT50Ac2'](36) != -9 or m['dhbT50Ac2'](37) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](38) != -3 or m['dhbT50Ac2'](39) != -2 or m['dhbT50Ac2'](40) != -3 or m['dhbT50Ac2'](41) != 2 or m['dhbT50Ac2'](42) != 0 or m['dhbT50Ac2'](43) != 1 or m['dhbT50Ac2'](44) != -2 or m['dhbT50Ac2'](45) != -3",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac2'](46) != -6 or m['dhbT50Ac2'](47) != -3 or m['dhbT50Ac2'](48) != -10 or m['dhbT50Ac2'](49) != -99 or m['dhbT50Ac3'](0) != -2 or m['dhbT50Ac3'](1) != -2 or m['dhbT50Ac3'](2) != -7 or m['dhbT50Ac3'](3) != -4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](4) != -7 or m['dhbT50Ac3'](5) != -1 or m['dhbT50Ac3'](6) != -99 or m['dhbT50Ac3'](7) != -10 or m['dhbT50Ac3'](8) != -4 or m['dhbT50Ac3'](9) != -3 or m['dhbT50Ac3'](10) != -2 or m['dhbT50Ac3'](11) != -8",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](12) != 1 or m['dhbT50Ac3'](13) != -1 or m['dhbT50Ac3'](14) != -6 or m['dhbT50Ac3'](15) != -2 or m['dhbT50Ac3'](16) != 2 or m['dhbT50Ac3'](17) != -6 or m['dhbT50Ac3'](18) != -4 or m['dhbT50Ac3'](19) != -5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](20) != -1 or m['dhbT50Ac3'](21) != -6 or m['dhbT50Ac3'](22) != -2 or m['dhbT50Ac3'](23) != -2 or m['dhbT50Ac3'](24) != 0 or m['dhbT50Ac3'](25) != 1 or m['dhbT50Ac3'](26) != 0 or m['dhbT50Ac3'](27) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](28) != -1 or m['dhbT50Ac3'](29) != -6 or m['dhbT50Ac3'](30) != -2 or m['dhbT50Ac3'](31) != -4 or m['dhbT50Ac3'](32) != -4 or m['dhbT50Ac3'](33) != -1 or m['dhbT50Ac3'](34) != -4 or m['dhbT50Ac3'](35) != -5",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](36) != -8 or m['dhbT50Ac3'](37) != -1 or m['dhbT50Ac3'](38) != -2 or m['dhbT50Ac3'](39) != -1 or m['dhbT50Ac3'](40) != -2 or m['dhbT50Ac3'](41) != 2 or m['dhbT50Ac3'](42) != 0 or m['dhbT50Ac3'](43) != 1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac3'](44) != -1 or m['dhbT50Ac3'](45) != -2 or m['dhbT50Ac3'](46) != -6 or m['dhbT50Ac3'](47) != -2 or m['dhbT50Ac3'](48) != -8 or m['dhbT50Ac3'](49) != -99 or m['dhbT50Ac4'](0) != -1 or m['dhbT50Ac4'](1) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](2) != -5 or m['dhbT50Ac4'](3) != -3 or m['dhbT50Ac4'](4) != -5 or m['dhbT50Ac4'](5) != -1 or m['dhbT50Ac4'](6) != -99 or m['dhbT50Ac4'](7) != -8 or m['dhbT50Ac4'](8) != -3 or m['dhbT50Ac4'](9) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](10) != -1 or m['dhbT50Ac4'](11) != -6 or m['dhbT50Ac4'](12) != 1 or m['dhbT50Ac4'](13) != 0 or m['dhbT50Ac4'](14) != -4 or m['dhbT50Ac4'](15) != -1 or m['dhbT50Ac4'](16) != 1 or m['dhbT50Ac4'](17) != -6",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](18) != -3 or m['dhbT50Ac4'](19) != -3 or m['dhbT50Ac4'](20) != -1 or m['dhbT50Ac4'](21) != -6 or m['dhbT50Ac4'](22) != -2 or m['dhbT50Ac4'](23) != -1 or m['dhbT50Ac4'](24) != 0 or m['dhbT50Ac4'](25) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](26) != 0 or m['dhbT50Ac4'](27) != -1 or m['dhbT50Ac4'](28) != 0 or m['dhbT50Ac4'](29) != -5 or m['dhbT50Ac4'](30) != -1 or m['dhbT50Ac4'](31) != -2 or m['dhbT50Ac4'](32) != -3 or m['dhbT50Ac4'](33) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](34) != -3 or m['dhbT50Ac4'](35) != -4 or m['dhbT50Ac4'](36) != -6 or m['dhbT50Ac4'](37) != -1 or m['dhbT50Ac4'](38) != -1 or m['dhbT50Ac4'](39) != 0 or m['dhbT50Ac4'](40) != -1 or m['dhbT50Ac4'](41) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac4'](42) != 0 or m['dhbT50Ac4'](43) != 0 or m['dhbT50Ac4'](44) != -1 or m['dhbT50Ac4'](45) != -1 or m['dhbT50Ac4'](46) != -4 or m['dhbT50Ac4'](47) != -1 or m['dhbT50Ac4'](48) != -6 or m['dhbT50Ac4'](49) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](0) != 0 or m['dhbT50Ac7'](1) != 0 or m['dhbT50Ac7'](2) != 0 or m['dhbT50Ac7'](3) != 0 or m['dhbT50Ac7'](4) != 0 or m['dhbT50Ac7'](5) != 0 or m['dhbT50Ac7'](6) != -99 or m['dhbT50Ac7'](7) != -2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](8) != -1 or m['dhbT50Ac7'](9) != 0 or m['dhbT50Ac7'](10) != 0 or m['dhbT50Ac7'](11) != -2 or m['dhbT50Ac7'](12) != 2 or m['dhbT50Ac7'](13) != 0 or m['dhbT50Ac7'](14) != 0 or m['dhbT50Ac7'](15) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](16) != 1 or m['dhbT50Ac7'](17) != -2 or m['dhbT50Ac7'](18) != -1 or m['dhbT50Ac7'](19) != -1 or m['dhbT50Ac7'](20) != 1 or m['dhbT50Ac7'](21) != -2 or m['dhbT50Ac7'](22) != 0 or m['dhbT50Ac7'](23) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](24) != 0 or m['dhbT50Ac7'](25) != 0 or m['dhbT50Ac7'](26) != 0 or m['dhbT50Ac7'](27) != 0 or m['dhbT50Ac7'](28) != 0 or m['dhbT50Ac7'](29) != -2 or m['dhbT50Ac7'](30) != 0 or m['dhbT50Ac7'](31) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](32) != 0 or m['dhbT50Ac7'](33) != 0 or m['dhbT50Ac7'](34) != 0 or m['dhbT50Ac7'](35) != -1 or m['dhbT50Ac7'](36) != -3 or m['dhbT50Ac7'](37) != 0 or m['dhbT50Ac7'](38) != 1 or m['dhbT50Ac7'](39) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](40) != 0 or m['dhbT50Ac7'](41) != 3 or m['dhbT50Ac7'](42) != 0 or m['dhbT50Ac7'](43) != 0 or m['dhbT50Ac7'](44) != 0 or m['dhbT50Ac7'](45) != 0 or m['dhbT50Ac7'](46) != 0 or m['dhbT50Ac7'](47) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhbT50Ac7'](48) != -1 or m['dhbT50Ac7'](49) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R641 OA handheld audit",
      "comment" = "OA round twenty-eight (capture p. 80): the Table 50 hand-held weapons grid - the general data and the to-hit adjustments",
    },
}
