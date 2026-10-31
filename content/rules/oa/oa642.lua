-- oa642: promoted from rules/oahurled.h (the TABLE 51 (HURLED WEAPONS AND MISSILES), printed capture pp. 80-81 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 642,
  "prefix" = "oa642",
  "banner" = {
      "title" = "TABLE 51 (HURLED WEAPONS AND MISSILES), printed capture pp. 80-81 - the OA",
      "provenance" = "hurled round census 564 -> 565.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the spread - the 28-row grid cross-checked cell-by-cell between the two passes; six cells contest in two clusters and all settle per the print capture: the bow-short AC-10 cell reads +3 in the print against the compressed +2 (both readings ladder-consistent, the settling print read stands, flagged for the physical-copy check) and the sling-staff-stone ladder reads -4, -4, -3, -3, -2, -2, -1 in the print against the compressed -6, -5, -4, -3, -2, -1, 0 (the compressed stone-one-worse-than-bullet pattern is design-plausible, but the settling print read stands, flagged for the physical-copy check). The four note lines the print pass OCR dropped entirely were recovered from the compressed capture and corroborated by the UA sibling doctrine (rules/uamissile.h - the aklys feet note, the medium -2 and long -5): the star feet note (range is 10 feet, not 10 yards), the double-star see-description note on the needle fire rate, the short-range basis note and the medium/long adjust pins. T51 pins as the 28-row hurled grid: the eleven-column AC 0-10 to-hit adjustment ladder, the footnote letters as the R640 bitmask (the grenade, hankyu and metsubishi d 8, the javelin h 128), the star set (metsubishi and needle), -99 sentinels for the grenade and metsubishi dashes; the two stacked two-line cells (the blow pipe dart AC 0-2, the needle AC 0-4) decode cleanly in both passes; the fire rates and the short/medium/long range bands are textual and ride the column comments per the T48 doctrine. The weapon descriptions prose box stays open; Table 52 (capture p. 94) is deliberately left for the next round  the gap census after this round: 93 closed, 142 open - the Table 51 box flips (census 564 -> 565); NEXT - R643: Table 52 (Armor Class Table), capture p. 94, the armor-class grid, prefix dhd (verify free), audit \"R643 OA armor audit\", include after rules/oahurled.h",
    },
  "consts" = { {
      "name" = "dhcT51RowCount",
      "value" = 28,
      "comment" = "Table 51 (capture pp. 80-81): twenty-eight hurled weapon and missile rows",
    }, {
      "name" = "dhcT51AcCount",
      "value" = 11,
      "comment" = "the AC adjustment ladder - armor classes 0 through 10, eleven columns (capture pp. 80-81)",
    }, {
      "name" = "dhcT51MediumAdjust",
      "value" = -2,
      "comment" = "the grid note under Table 51: adjust by -2 at all medium ranges (capture p. 81)",
    }, {
      "name" = "dhcT51LongAdjust",
      "value" = -5,
      "comment" = "the grid note under Table 51: adjust by -5 at all long ranges (capture p. 81)",
    } },
  "bools" = { {
      "name" = "dhcT51AcAtShortRange",
      "value" = true,
      "comment" = "the grid note: the armor class adjustment is based on the weapon or missile being discharged at short range (capture p. 81)",
    }, {
      "name" = "dhcT51StarFeetNote",
      "value" = true,
      "comment" = "the star note under Table 51: range is 10 feet, not 10 yards (capture p. 81)",
    }, {
      "name" = "dhcT51DoubleStarSeeDescription",
      "value" = true,
      "comment" = "the double-star note on the needle fire rate: see weapon description (capture p. 81)",
    } },
  "switches" = { {
      "name" = "dhcT51Ac0",
      "values" = { -6, -14, -4, -7, -4, -9, -2, -3, -7, -1, -7, -99, -5, -7, 9, -99, -16, -3, -7, -7, -7, -7, -3, -7, -5, -4, -4, -7 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 0 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99. The weapon roster with the fire rate and the short/medium/long range bands rides this comment: 0 Axe, hand (rate 1; ranges 1/2/3), 1 Blow pipe dart (rate 2; ranges 1/2/3), 2 Bow, composite short (rate 2; ranges 5/10/18), 3 Bow, short (rate 2; ranges 5/10/15), 4 Chu-ko-nu (repeating crossbow) (rate 2; ranges 5/10/15), 5 Club, thrown (rate 1; ranges 2/4/6), 6 Crossbow, heavy (rate 1/2; ranges 8/16/24), 7 Crossbow, light (rate 1; ranges 6/12/18), 8 Dagger, thrown (rate 2; ranges 1/2/3), 9 Daikyu (great bow) (rate 2; ranges 7/14/21), 10 Dart (rate 3; ranges 1.5/3/4.5), 11 Grenade (rate 3; ranges 1/1.5/2), 12 Hankyu (little bow) (rate 2; ranges 5/10/15), 13 Javelin (rate 1; ranges 2/4/6), 14 Lasso (rate 1/2; ranges 1/2/3), 15 Metsubishi (rate 1/3; ranges 3'/-/-), 16 Needle (rate **; ranges 1/2/1/2), 17 Pellet bow (rate 1; ranges 6/12/18), 18 Shaken (rate 2; ranges 1/2/3), 19 Shuriken, spike (rate 2; ranges 1/-/-), 20 Shuriken, star, large (rate 3; ranges 1/2/1/2), 21 Shuriken, star, small (rate 4; ranges 1/2/1/2), 22 Sling (bullet) (rate 1; ranges 5/10/20), 23 Sling (stone) (rate 1; ranges 4/8/16), 24 Sling, staff (bullet) (rate 1/2; ranges -/3-6/9), 25 Sling, staff (stone) (rate 1/2; ranges -/3-6/9), 26 Spear (rate 1; ranges 1/2/3), 27 Uchi-ne (rate 2; ranges 1/2/3); the needle fire rate prints the double star (see weapon description), the metsubishi short range prints 3 feet with dashes beyond, the shuriken-spike and sling-staff short cells and the shuriken-spike medium/long cells print dashes, the sling-staff medium/long print 3-6/9 (capture pp. 80-81).",
    }, {
      "name" = "dhcT51Ac1",
      "values" = { -5, -12, -4, -6, -3, -8, -1, -2, -6, 0, -6, -99, -5, -6, 8, -99, -14, -2, -6, -6, -6, -6, -3, -6, -4, -4, -4, -6 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 1 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac2",
      "values" = { -4, -10, -3, -5, -3, -7, -1, -2, -5, 0, -5, -99, -4, -5, 7, -99, -12, -2, -5, -5, -5, -5, -2, -5, -3, -3, -3, -5 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 2 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac3",
      "values" = { -3, -8, -3, -4, -2, -5, 0, -1, -4, 0, -4, -99, -4, -4, 6, -99, -10, -1, -4, -4, -4, -4, -2, -4, -2, -3, -3, -4 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 3 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac4",
      "values" = { -2, -6, -1, -1, -1, -3, 1, 0, -3, 0, -3, -99, -2, -3, 5, -99, -10, 0, -3, -3, -3, -3, -1, -2, -1, -2, -2, -3 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 4 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac5",
      "values" = { -1, -4, 0, 0, 0, -2, 2, 0, -2, 1, -2, -99, -1, -2, 4, -99, -8, 0, -2, -2, -2, -2, 0, -1, 0, -2, -2, -2 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 5 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac6",
      "values" = { -1, -2, 1, 0, 0, -1, 3, 1, -1, 2, -1, -99, 0, -1, 3, -99, -6, 1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 6 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac7",
      "values" = { 0, -1, 2, 1, 1, -1, 3, 2, -1, 3, 0, -99, 0, -1, 2, -99, -4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 7 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac8",
      "values" = { 0, -1, 2, 2, 2, -1, 4, 3, 0, 4, 1, -99, 1, 0, 1, -99, -2, 3, 1, 1, 1, 1, 2, 2, 0, 0, 0, 1 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 8 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac9",
      "values" = { 0, 1, 2, 2, 3, 0, 4, 3, 0, 4, 0, -99, 2, 0, 0, -99, -3, 3, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 9 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51Ac10",
      "values" = { 1, 2, 3, 3, 3, 0, 4, 3, 1, 4, 1, -99, 2, 1, -1, -99, 0, 3, 1, 1, 1, 1, 3, 3, 0, 0, 0, 1 },
      "default" = -99,
      "comment" = "the to-hit adjustment vs armor class 10 (capture pp. 80-81); the grenade and metsubishi rows print dashes and pin as -99.",
    }, {
      "name" = "dhcT51LNote",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 128, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the printed footnote letters as a bitmask: a=1, b=2, c=4, d=8, e=16, f=32, g=64, h=128 per the R640 doctrine; the grenade, hankyu and metsubishi rows carry d 8 and the javelin h 128, 0 elsewhere (capture pp. 80-81).",
    }, {
      "name" = "dhcT51Star",
      "values" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      "default" = -99,
      "comment" = "the star footnote markers: the metsubishi and needle rows carry the star, 0 elsewhere - the star note reads range is 10 feet, not 10 yards (capture p. 81).",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhcT51RowCount']() != 28  or m['dhcT51AcCount']() != 11  or m['dhcT51MediumAdjust']() != -2  or m['dhcT51LongAdjust']() != -5  or  m['dhcT51AcAtShortRange']() != 1  or  m['dhcT51StarFeetNote']() != 1  or  m['dhcT51DoubleStarSeeDescription']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhcT51RowCount']() != 28",
      "note" = "the T51 row count pin",
    }, {
      "expr" = "m['dhcT51AcCount']() != 11",
      "note" = "the T51 AC ladder width pin",
    }, {
      "expr" = "m['dhcT51MediumAdjust']() != -2  or m['dhcT51LongAdjust']() != -5",
      "note" = "the medium/long range adjust pins",
    }, {
      "expr" = "m['dhcT51AcAtShortRange']() != 1",
      "note" = "the short-range basis note pin",
    }, {
      "expr" = "m['dhcT51StarFeetNote']() != 1",
      "note" = "the star feet note pin",
    }, {
      "expr" = "m['dhcT51DoubleStarSeeDescription']() != 1",
      "note" = "the double-star see-description note pin",
    }, {
      "expr" = "m['dhcT51Ac10'](3) != 3",
      "note" = "the bow, short row - the contested AC-10 cell settles +3 per the print capture (both readings ladder-consistent, the settling print read stands over the compressed +2; flagged for the physical-copy check)",
    }, {
      "expr" = "m['dhcT51Ac0'](25) != -4  or m['dhcT51Ac1'](25) != -4  or m['dhcT51Ac5'](25) != -2  or m['dhcT51Ac6'](25) != -1",
      "note" = "the sling, staff (stone) row - the contested ladder settles per the print capture (the compressed stone-one-worse-than-bullet pattern is design-plausible, but the settling print read stands; flagged for the physical-copy check)",
    }, {
      "expr" = "m['dhcT51Ac0'](1) != -14  or m['dhcT51Ac2'](1) != -10",
      "note" = "the blow pipe dart row - the stacked two-line cells decode as -14, -12, -10 (capture p. 80)",
    }, {
      "expr" = "m['dhcT51Ac0'](16) != -16  or m['dhcT51Ac4'](16) != -10  or m['dhcT51Ac9'](16) != -3  or m['dhcT51Star'](16) != 1",
      "note" = "the needle row - the stacked two-line cells decode as -16 through -10, the AC-9 dip at -3, the star marker (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac0'](11) != -99  or m['dhcT51Ac10'](11) != -99  or m['dhcT51LNote'](11) != 8",
      "note" = "the grenade row - the -99 dashes across the ladder, the d footnote letter 8 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac0'](15) != -99  or m['dhcT51LNote'](15) != 8  or m['dhcT51Star'](15) != 1",
      "note" = "the metsubishi row - the -99 dashes, the d footnote letter 8, the star marker (capture p. 81)",
    }, {
      "expr" = "m['dhcT51LNote'](13) != 128",
      "note" = "the javelin row - the h footnote letter, bitmask 128 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51LNote'](12) != 8",
      "note" = "the hankyu row - the d footnote letter 8 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac0'](14) != 9  or m['dhcT51Ac10'](14) != -1",
      "note" = "the lasso row - the inverted ladder, +9 at AC 0 falling to -1 at AC 10 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac8'](22) != 2  or m['dhcT51Ac9'](22) != 1",
      "note" = "the sling (bullet) row - the AC-8 bump at +2 over the AC-9 +1 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac0'](6) != -2  or m['dhcT51Ac10'](6) != 4",
      "note" = "the heavy crossbow row - the shallowest ladder, -2 at AC 0 to the +4 plateau (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac0'](9) != -1  or m['dhcT51Ac10'](9) != 4",
      "note" = "the daikyu row - the AC-0 at -1 only, the +4 plateau at the tail (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac5'](24) != 0  or m['dhcT51Ac10'](24) != 0",
      "note" = "the sling, staff (bullet) row - the flat zero tail from AC 5 through AC 10 (capture p. 81)",
    }, {
      "expr" = "m['dhcT51Ac3'](0) != -3 or m['dhcT51Ac3'](1) != -8 or m['dhcT51Ac3'](2) != -3 or m['dhcT51Ac3'](3) != -4 or m['dhcT51Ac3'](4) != -2 or m['dhcT51Ac3'](5) != -5 or m['dhcT51Ac3'](6) != 0 or m['dhcT51Ac3'](7) != -1",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac3'](8) != -4 or m['dhcT51Ac3'](9) != 0 or m['dhcT51Ac3'](10) != -4 or m['dhcT51Ac3'](11) != -99 or m['dhcT51Ac3'](12) != -4 or m['dhcT51Ac3'](13) != -4 or m['dhcT51Ac3'](14) != 6 or m['dhcT51Ac3'](15) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac3'](16) != -10 or m['dhcT51Ac3'](17) != -1 or m['dhcT51Ac3'](18) != -4 or m['dhcT51Ac3'](19) != -4 or m['dhcT51Ac3'](20) != -4 or m['dhcT51Ac3'](21) != -4 or m['dhcT51Ac3'](22) != -2 or m['dhcT51Ac3'](23) != -4",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac3'](24) != -2 or m['dhcT51Ac3'](25) != -3 or m['dhcT51Ac3'](26) != -3 or m['dhcT51Ac3'](27) != -4 or m['dhcT51Ac3'](28) != -99 or m['dhcT51Ac7'](0) != 0 or m['dhcT51Ac7'](1) != -1 or m['dhcT51Ac7'](2) != 2",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac7'](3) != 1 or m['dhcT51Ac7'](4) != 1 or m['dhcT51Ac7'](5) != -1 or m['dhcT51Ac7'](6) != 3 or m['dhcT51Ac7'](7) != 2 or m['dhcT51Ac7'](8) != -1 or m['dhcT51Ac7'](9) != 3 or m['dhcT51Ac7'](10) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac7'](11) != -99 or m['dhcT51Ac7'](12) != 0 or m['dhcT51Ac7'](13) != -1 or m['dhcT51Ac7'](14) != 2 or m['dhcT51Ac7'](15) != -99 or m['dhcT51Ac7'](16) != -4 or m['dhcT51Ac7'](17) != 2 or m['dhcT51Ac7'](18) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac7'](19) != 0 or m['dhcT51Ac7'](20) != 0 or m['dhcT51Ac7'](21) != 0 or m['dhcT51Ac7'](22) != 0 or m['dhcT51Ac7'](23) != 0 or m['dhcT51Ac7'](24) != 0 or m['dhcT51Ac7'](25) != 0 or m['dhcT51Ac7'](26) != 0",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    }, {
      "expr" = "m['dhcT51Ac7'](27) != 0 or m['dhcT51Ac7'](28) != -99",
      "note" = "the switch census - the fail-on-wrong pin of every unpinned-in-audit fact",
    } },
  "audit" = {
      "label" = "R642 OA hurled audit",
      "comment" = "OA round twenty-nine (capture pp. 80-81): the Table 51 hurled weapons and missiles grid - the fire rates, ranges and the to-hit adjustments",
    },
}
