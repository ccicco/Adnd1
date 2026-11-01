-- ua338: promoted from rules/uamissile.h (the The UA HURLED WEAPON AND MISSILE TYPES, GENERAL DATA, AND);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 338,
  "prefix" = "ua338",
  "banner" = {
      "title" = "The UA HURLED WEAPON AND MISSILE TYPES, GENERAL DATA, AND",
      "provenance" = "\"TO HIT\" ADJUSTMENTS table (p. 28) pins (R338).  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs: - the range column: the extract prints one number per row (two leading cells OCR-lost). The number reads as the LONG range in tens of feet - PHB-seam-verified: the short bow 15 (150'), the long bow 21 (210'), the light crossbow 18 (180'), the sling stone 16 (160'), the javelin 6 (60'), the hand crossbow 6 (60'), the dagger and hand axe 3 (30'). The composite long bow prints 21 - the long bow's value; the PHB composite prints 24 - pinned as printed, the doubt noted pending the PDF. - the minus-loss decode: unsigned magnitude tokens between signed neighbors of a monotone ladder read as negative (the aklys -8,7,-6... reads -8,-7,-6...). The pattern is seam-proven on the R145 engine rows: the bow short prints <7,6,5,-4,-1,0,0 and the PHB row reads -7,-6,-5,-4,-1,0,0; the bow long prints 2,-1,-1,0 (PHB -2,-1,-1,0); the light crossbow -3,2,-2,-1,0,0 (PHB -3,-2,-2,-1,0,0); the sling bullet -3,-3,2 (PHB -3,-3,-2). - attributions: the garbled \"Bow,\" row attributes to the long bow (range 21, the AC cells match the PHB row); the composite rows differ from it, so the match is unique. The lasso's \"#7\" reads as +7 - the only sign consistent with the printed descending +9,+8 ladder. The dart's \"=7\" and trailing '\"1' read as -7 and -1 (the row's ladder matches the dagger's exactly). The bow short's \"<7\" seam-closes to -7. The staff sling rows read their merged leading cells as the rate garbage and the range 9 (both rows print 9). - the AC columns are AC 0 through 6, the adjustment applied at SHORT range (the printed note); medium range adjusts -2, long -5 - the R116 convention, seam-cross-checked. - the dagger and dart rows read -7 through -1 - the UA hurled rows, NOT the PHB p.38 melee rows (the R145 dagger row is the melee chart; the hurled chart carries its own row).  R392 (the clean PDF read): every hole closes. The rate column and the S/M/L ranges read in full (the strings pin as printed: \"1/2\" for the half-rate rows, \"1*\" for the aklys, the dash for the staff slings' short range, the \"1 1/2\" and \"4 1/2\" dart cells, the \"3-6\" staff-sling medium). Every 100 sentinel fills (the light crossbow AC6 reads +1, the PHB-seam value the R338 pin could not confirm); the AC 7..10 columns pin - the R392 uamtAcAdjustmentHigh accessor. The aklys range footnote reads: 10-foot only, not 10 yards. The composite long bow's 21 stays the printed value (the PHB reads 24 - the deviation noted, pinned as printed).",
    },
  "consts" = { {
      "name" = "uamtRowCount",
      "value" = 24,
      "comment" = "The row count (24 = the 16 standard weapons plus 8 new).",
    }, {
      "name" = "uamtNewWeaponCount",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uamtStandardWeaponCount",
      "value" = 16,
      "comment" = "",
    }, {
      "name" = "uamtMediumRangeAdjustment",
      "value" = -2,
      "comment" = "The medium-range adjustment: -2 (the R116 seam).",
    }, {
      "name" = "uamtLongRangeAdjustment",
      "value" = -5,
      "comment" = "The long-range adjustment: -5 (the R116 seam).",
    } },
  "bools" = { {
      "name" = "uamtRateOfFireTurnOrRound",
      "value" = true,
      "comment" = "---- the printed notes (p. 28) ---- Rate of fire is based on the turn (for table-top miniatures) or the melee round. The AC adjustment applies at short range; the range labels are S = Short, M = Medium, L = Long.",
    }, {
      "name" = "uamtAcAdjustmentAtShortRange",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uamtAklysTenFootOnly",
      "value" = true,
      "comment" = "The aklys range footnote: the \"1*\" reads 10-foot only, not 10 yards (the R392 clean read).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uamtName",
      "comment" = "The row name (printed, or the attribution judgment - the \"AKlys\" caps slip normalized, the garbled \"Bow,\" row attributed to the long bow).",
      "kind" = "string array",
      "count" = 24,
      "values" = { "Aklys (hurled)", "Atlatl (javelin)", "Axe, Hand", "Blowgun Needle", "Bow, Composite, Long", "Bow, Composite, Short", "Bow, Long", "Bow, Short", "Club", "Crossbow, Hand", "Crossbow, Heavy", "Crossbow, Light", "Dagger", "Dart", "Hammer", "Harpoon", "Javelin", "Knife", "Lasso", "Sling (bullet)", "Sling (stone)", "Spear", "Staff Sling (bullet)", "Staff Sling (stone)" },
    }, {
      "name" = "uamtIsNewWeapon",
      "comment" = "True when the row is a UA-new weapon (the aklys, atlatl, blowgun, harpoon, knife, lasso and the two staff sling rows).",
      "kind" = "header pin",
      "body" = "static const bool k[24] = { 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, }; if (i < 0) i = 0; if (i > 23) i = 23; return k[i];",
    }, {
      "name" = "uamtRangePrinted",
      "comment" = "The printed range number - the long range in tens of feet (the JUDGMENT above); -1 = the cell is OCR-lost (the aklys, the dart).",
      "kind" = "header pin",
      "body" = "static const int k[24] = { -1, 9, 3, 3, 21, 18, 21, 15, 3, 6, 24, 18, 3, -1, 3, 3, 6, 3, 3, 20, 16, 3, 9, 9, }; if (i < 0) i = 0; if (i > 23) i = 23; return k[i];",
    }, {
      "name" = "uamtAcAdjustment",
      "comment" = "The AC adjustment by AC 0..6, applied at short range (the R392 clean read: every cell recovers; no sentinel remains).",
      "kind" = "header pin",
      "body" = "static const int k[24][7] = { { -8, -7, -6, -5, -4, -3, -2 }, { -6, -5, -4, -3, -2, -1, 0 }, { -6, -5, -4, -3, -2, -1, -1 }, { -14, -12, -10, -8, -6, -4, -2 }, { -4, -3, -2, -1, 0, 0, 1 }, { -4, -4, -3, -3, -1, 0, 1 }, { -2, -1, -1, 0, 0, 1, 2 }, { -7, -6, -5, -4, -1, 0, 0 }, { -9, -8, -7, -5, -3, -2, -1 }, { -6, -4, -2, -1, 0, 0, 0 }, { -2, -1, -1, 0, 1, 2, 3 }, { -3, -2, -2, -1, 0, 0, 1 }, { -7, -6, -5, -4, -3, -2, -1 }, { -7, -6, -5, -4, -3, -2, -1 }, { -4, -3, -2, -1, 0, 0, 0 }, { -6, -5, -4, -3, -2, -1, 0 }, { -7, -6, -5, -4, -3, -2, -1 }, { -8, -7, -6, -5, -4, -3, -2 }, { 9, 8, 7, 6, 5, 4, 3 }, { -3, -3, -2, -2, -1, 0, 0 }, { -7, -6, -5, -4, -2, -1, 0 }, { -4, -4, -3, -3, -2, -2, -1 }, { -5, -4, -3, -2, -1, 0, 0 }, { -6, -5, -4, -3, -2, -1, 0 }, }; if (i < 0) i = 0; if (i > 23) i = 23; if (ac < 0) ac = 0; if (ac > 6) ac = 6; return k[i][ac];",
    }, {
      "name" = "uamtAcAdjustmentHigh",
      "comment" = "The AC adjustment by AC 7..10 (the R392 clean read; the short-range ladders extend past AC 6).",
      "kind" = "header pin",
      "body" = "static const int k[24][4] = { { -1, 0, 0, 0 }, { 0, 1, 1, 2 }, { 0, 0, 0, 1 }, { -1, -1, 1, 2 }, { 2, 2, 3, 3 }, { 2, 2, 2, 3 }, { 3, 3, 3, 3 }, { 1, 2, 2, 2 }, { -1, -1, 0, 0 }, { 1, 2, 2, 3 }, { 3, 4, 4, 4 }, { 2, 3, 3, 3 }, { -1, 0, 0, 1 }, { 0, 1, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 1, 0, 1 }, { -1, 0, 0, 1 }, { 2, 1, 0, -1 }, { 0, 2, 1, 3 }, { 0, 2, 1, 3 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, }; if (i < 0) i = 0; if (i > 23) i = 23; if (ac < 0) ac = 0; if (ac > 3) ac = 3; return k[i][ac];",
    }, {
      "name" = "uamtRateOfFire",
      "comment" = "The rate of fire (printed; \"1/2\" = the half-rate rows: the heavy crossbow, the lasso, the two staff slings).",
      "kind" = "string array",
      "count" = 24,
      "values" = { "1", "1", "1", "2", "2", "2", "2", "2", "1", "1", "1/2", "1", "2", "3", "1", "1", "1", "2", "1/2", "1", "1", "1", "1/2", "1/2" },
    }, {
      "name" = "uamtRangeShort",
      "comment" = "The short range (printed; \"-\" = the dash, \"1*\" = the aklys footnote, \"1 1/2\" = the dart).",
      "kind" = "string array",
      "count" = 24,
      "values" = { "1*", "3", "1", "1", "6", "5", "7", "5", "1", "2", "8", "6", "1", "1 1/2", "1", "1", "2", "1", "1", "5", "4", "1", "-", "-" },
    }, {
      "name" = "uamtRangeMedium",
      "comment" = "The medium range (printed; \"3-6\" = the staff slings).",
      "kind" = "string array",
      "count" = 24,
      "values" = { "-", "6", "2", "2", "12", "10", "14", "10", "2", "4", "16", "12", "2", "3", "2", "2", "4", "2", "2", "10", "8", "2", "3-6", "3-6" },
    }, {
      "name" = "uamtRangeLong",
      "comment" = "The long range (printed).",
      "kind" = "string array",
      "count" = 24,
      "values" = { "-", "9", "3", "3", "21", "18", "21", "15", "3", "6", "24", "18", "3", "4 1/2", "3", "3", "6", "3", "3", "20", "16", "3", "9", "9" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uamtRowCount']() != 24  or m['uamtNewWeaponCount']() != 8  or m['uamtStandardWeaponCount']() != 16  or strcmp(m['uamtName'](0), \"Aklys (hurled)\") != 0  or strcmp(m['uamtName'](1), \"Atlatl (javelin)\") != 0  or strcmp(m['uamtName'](6), \"Bow, Long\") != 0  or strcmp(m['uamtName'](23), \"Staff Sling (stone)\") != 0  or  !m['uamtIsNewWeapon'](0)  or  !m['uamtIsNewWeapon'](18)  or m['uamtIsNewWeapon'](2)  or m['uamtIsNewWeapon'](11)  or m['uamtIsNewWeapon'](i)) ++newc; if (newc != 8",
      "note" = "U1: the counts and the roster",
    }, {
      "expr" = "m['uamtRangePrinted'](7) != 15  or m['uamtRangePrinted'](6) != 21  or m['uamtRangePrinted'](11) != 18  or m['uamtRangePrinted'](20) != 16  or m['uamtRangePrinted'](16) != 6  or m['uamtRangePrinted'](9) != 6  or m['uamtRangePrinted'](4) != 21  or m['uamtRangePrinted'](5) != 18  or m['uamtRangePrinted'](10) != 24  or m['uamtRangePrinted'](2) != 3  or m['uamtRangePrinted'](12) != 3  or m['uamtRangePrinted'](22) != 9  or m['uamtRangePrinted'](23) != 9  or m['uamtRangePrinted'](19) != 20  or m['uamtRangePrinted'](0) != -1  or m['uamtRangePrinted'](13) != -1",
      "note" = "U2: the range column (the long range in tens of feet; the PHB seams)",
    }, {
      "expr" = "m['uamtAcAdjustment'](0, ac) != -8 + ac  or m['uamtAcAdjustment'](3, ac) != -14 + 2 * ac  or m['uamtAcAdjustment'](12, ac) != -7 + ac  or m['uamtAcAdjustment'](13, ac) != -7 + ac  or m['uamtAcAdjustment'](5, 0) != -4  or m['uamtAcAdjustment'](5, 1) != -4  or m['uamtAcAdjustment'](5, 2) != -3  or m['uamtAcAdjustment'](5, 3) != -3  or m['uamtAcAdjustment'](5, 4) != -1  or m['uamtAcAdjustment'](5, 6) != 1  or m['uamtAcAdjustment'](4, 2) != -2  or m['uamtAcAdjustment'](4, 6) != 1  or m['uamtAcAdjustment'](18, 0) != 9  or m['uamtAcAdjustment'](18, 1) != 8  or m['uamtAcAdjustment'](18, 2) != 7  or m['uamtAcAdjustment'](10, 0) != -2  or m['uamtAcAdjustment'](10, 2) != -1  or m['uamtAcAdjustment'](10, 6) != 3  or m['uamtAcAdjustment'](21, 0) != -4  or m['uamtAcAdjustment'](21, 1) != -4  or m['uamtAcAdjustment'](21, 2) != -3  or m['uamtAcAdjustment'](22, 0) != -5  or m['uamtAcAdjustment'](23, 0) != -6  or m['uamtAcAdjustment'](9, 0) != -6  or m['uamtAcAdjustment'](9, 2) != -2  or m['uamtAcAdjustment'](8, 0) != -9  or m['uamtAcAdjustment'](8, 6) != -1  or m['uamtAcAdjustment'](14, 1) != -3  or m['uamtAcAdjustment'](1, 0) != -6  or m['uamtAcAdjustment'](1, 4) != -2",
      "note" = "U3: the AC ladders, the pinned cells",
    }, {
      "expr" = "m['uamtAcAdjustment'](0, 0) == 100  or m['uamtAcAdjustment'](8, 2) != -7  or m['uamtAcAdjustment'](14, 0) != -4  or m['uamtAcAdjustment'](14, 5) != 0  or m['uamtAcAdjustment'](1, 5) != -1  or m['uamtAcAdjustment'](1, 6) != 0  or m['uamtAcAdjustment'](9, 6) != 0  or m['uamtAcAdjustment'](10, 1) != -1  or m['uamtAcAdjustment'](11, 6) != 1  or m['uamtAcAdjustment'](20, 0) != -7  or m['uamtAcAdjustment'](6, 4) != 0  or m['uamtAcAdjustment'](6, 5) != 1  or m['uamtAcAdjustment'](6, 6) != 2  or pinned != 168  or strcmp(m['uamtRateOfFire'](0), \"1\") != 0  or strcmp(m['uamtRateOfFire'](10), \"1/2\") != 0  or strcmp(m['uamtRateOfFire'](13), \"3\") != 0  or strcmp(m['uamtRangeShort'](0), \"1*\") != 0  or m['uamtRangeShort'](22)[0] != '-'  or strcmp(m['uamtRangeMedium'](22), \"3-6\") != 0  or strcmp(m['uamtRangeLong'](1), \"9\") != 0  or strcmp(m['uamtRangeShort'](13), \"1 1/2\") != 0  or strcmp(m['uamtRangeLong'](13), \"4 1/2\") != 0  or  m['uamtAklysTenFootOnly']() != 1  or m['uamtAcAdjustmentHigh'](18, 0) != 2  or m['uamtAcAdjustmentHigh'](18, 3) != -1  or m['uamtAcAdjustmentHigh'](0, 0) != -1  or m['uamtAcAdjustmentHigh'](0, 3) != 0  or m['uamtAcAdjustmentHigh'](3, 0) != -1  or m['uamtAcAdjustmentHigh'](3, 1) != -1  or m['uamtAcAdjustmentHigh'](3, 2) != 1  or m['uamtAcAdjustmentHigh'](3, 3) != 2",
      "note" = "U4: the recovered cells (the R392 clean read; every 100 sentinel fills)",
    }, {
      "expr" = "m['uamtRateOfFireTurnOrRound']() != 1  or  m['uamtAcAdjustmentAtShortRange']() != 1  or m['uamtMediumRangeAdjustment']() != -2  or m['uamtLongRangeAdjustment']() != -5  or m['missileRangeMod'](60, 40) != -2  or m['missileRangeMod'](100, 40) != -5",
      "note" = "U5: the prose notes and the R116 seam",
    }, {
      "expr" = "m['uamtAcAdjustment'](7, ac) != items::m['weapon']( items::WPN_SHORT_BOW) .acAdj[ac]  or m['uamtAcAdjustment'](6, ac) != items::m['weapon']( items::WPN_LONG_BOW) .acAdj[ac]  or m['uamtAcAdjustment'](11, ac) != items::m['weapon']( items::WPN_CROSSBOW_LIGHT) .acAdj[ac]  or m['uamtAcAdjustment'](19, ac) != items::m['weapon']( items::WPN_SLING) .acAdj[ac]",
      "note" = "U6: the R145 engine seam - the minus-loss decode proven on the standard rows",
    }, {
      "expr" = "strcmp(m['uawtName'](0), \"Aklys\") != 0  or  !m['uawtIsNewWeapon'](0)  or strcmp(m['uawtName'](53), \"Spiked Buckler\") != 0",
      "note" = "U7: the R337 seam - the new-weapon roster agreement",
    } },
  "audit" = {
      "label" = "R338: the UA missile data pin audit",
      "comment" = "The UA HURLED WEAPON AND MISSILE TYPES table (p. 28) - the 24-row roster: the range column (the long range in tens of feet, PHB-seam verified), the AC-adjustment ladders minus-loss decoded (the pattern seam-proven on the bow, crossbow and sling rows against the R145 engine rows); the R392 clean PDF read fills the rate column, the S/M/L range strings and every lost AC cell, and adds the AC 7..10 columns - the item AMENDED, closes.",
    },
}
