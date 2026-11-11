-- ua: promoted from the round R392 pin headers (the the UA players tables);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 392,
  "prefix" = "ua",
  "banner" = {
      "title" = "the UA players tables",
      "provenance" = "rules/ua/uaequip26.h (the The UA BASIC EQUIPMENT AND SUPPLIES COSTS table (p. 26) pins): (R392).  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs: - the armor roster: four rows in the printed order; the print runs two columns (Bronze Plate 100 gp beside Full Plate 4000 gp), the pairs split in printed order. - the arms roster: 19 rows; \"Quarrels for same\" pins as printed (the hand-crossbow quarrels); the falchion entry prints across two lines (Sword, falchion, and scabbard) - the split row merges. - the units pin as printed (gp, sp, ep) - uaecArmsUnit names the row unit, the IsSilver/IsElectrum flags carry the same reading.  No holes: the R392 clean PDF read - every cell legible.  rules/ua/uahandheld.h (the The UA HAND HELD WEAPON TYPES, GENERAL DATA, AND \"TO HIT\"): ADJUSTMENTS table (p. 27) pins (R392).  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs: - the roster: 60 rows in the printed order - the R392 clean PDF read, every cell legible, no holes, no attributions. - the n/a cells (the atlatl, blowgun and caltrop rows) pin -1 in the numeric columns, \"n/a\" in the string columns. - the half-foot glyphs (c. 1 1/2' and the like) normalize to ASCII; the foot and inch marks print straight. - the aklys speed factor prints \"4 (+ 1)\" - the 4 pins, the +1 bonus rides uahhAklysSpeedBonus. - the Spear and Trident speed factors print the range 6-8, the Whip 5-8 - the min/max accessors carry the ranges. - the footnotes: * = the set-double note (the spetum, the bastard sword), ** = the dismount note (eight rows) - uahhSetDoubleFlag/uahhDismountFlag; the general note: +2 vs the back, +4 vs stunned, prone and motionless.",
    },
  "consts" = { {
      "name" = "uaecArmorCount",
      "value" = 4,
      "comment" = "The armor row count (4).",
    }, {
      "name" = "uaecArmsCount",
      "value" = 19,
      "comment" = "The arms row count (19 = the 16 new weapons plus the quarrels, the scabbard knife and the two swords).",
    }, {
      "name" = "uahhRowCount",
      "value" = 60,
      "comment" = "The row count (60).",
    }, {
      "name" = "uahhAklysSpeedBonus",
      "value" = 1,
      "comment" = "The aklys speed-factor bonus (the print \"4 (+ 1)\").",
    }, {
      "name" = "uahhRearAttackBonus",
      "value" = 2,
      "comment" = "The general note: any weapon strikes at +2 vs the back.",
    }, {
      "name" = "uahhStunnedProneBonus",
      "value" = 4,
      "comment" = "The general note: +4 vs stunned, prone and motionless.",
    } },
  "bools" = { {
      "name" = "uahhNoteSetDoubleVsCharge",
      "value" = true,
      "comment" = "The * footnote: these weapons do twice the damage indicated to size L creatures when set (firmly grounded) to receive a charging opponent.",
    }, {
      "name" = "uahhNoteDismountOnHit",
      "value" = true,
      "comment" = "The ** footnote: these weapons are capable of dismounting a rider on a score equal to or greater than the \"to hit\" score.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uaecArmorName",
      "comment" = "The armor row name (printed).",
      "kind" = "string array",
      "count" = 4,
      "values" = { "Bronze Plate", "Full Plate", "Field Plate", "Shield, buckler" },
    }, {
      "name" = "uaecArmorCost",
      "comment" = "The armor cost (printed).",
      "kind" = "header pin",
      "body" = "static const int k[4] = { 100, 4000, 2000, 5, }; if (i < 0) i = 0; if (i > 3) i = 3; return k[i];",
    }, {
      "name" = "uaecArmorUnit",
      "comment" = "The armor cost unit (gp, printed).",
      "kind" = "header pin",
      "body" = "(void)i; return \"gp\";",
    }, {
      "name" = "uaecArmsName",
      "comment" = "The arms row name (printed; the falchion two-line entry merges).",
      "kind" = "string array",
      "count" = 19,
      "values" = { "Aklys", "Atlatl", "Blowgun", "Blowgun Needle", "Caltrop", "Crossbow, hand", "Quarrels for same", "Garrot", "Harpoon", "Hook Fauchard", "Knife & scabbard", "Lasso", "Man Catcher", "Sap", "Spiked Buckler", "Staff Sling", "Sword, falchion, and scabbard", "Sword, khopesh", "Whip" },
    }, {
      "name" = "uaecArmsCost",
      "comment" = "The arms cost (printed number).",
      "kind" = "header pin",
      "body" = "static const int k[19] = { 2, 1, 20, 1, 2, 300, 100, 1, 5, 6, 1, 5, 25, 1, 10, 2, 10, 10, 3, }; if (i < 0) i = 0; if (i > 18) i = 18; return k[i];",
    }, {
      "name" = "uaecArmsUnit",
      "comment" = "The arms cost unit (\"gp\", \"sp\" or \"ep\", printed).",
      "kind" = "string array",
      "count" = 19,
      "values" = { "gp", "gp", "gp", "sp", "sp", "gp", "gp", "ep", "gp", "gp", "gp", "sp", "gp", "gp", "gp", "gp", "gp", "gp", "gp" },
    }, {
      "name" = "uaecArmsPriceIsSilver",
      "comment" = "True when the row price prints in silver pieces (the blowgun needle, the caltrop, the lasso).",
      "kind" = "header pin",
      "body" = "static const bool k[19] = { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, }; if (i < 0) i = 0; if (i > 18) i = 18; return k[i];",
    }, {
      "name" = "uaecArmsPriceIsElectrum",
      "comment" = "True when the row price prints in electrum pieces (the garrot).",
      "kind" = "header pin",
      "body" = "static const bool k[19] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }; if (i < 0) i = 0; if (i > 18) i = 18; return k[i];",
    }, {
      "name" = "uahhName",
      "comment" = "The row name (printed).",
      "kind" = "string array",
      "count" = 60,
      "values" = { "Aklys", "Atlatl", "Axe, Battle", "Axe, Hand", "Bardiche", "Bec de Corbin", "Bill-Guisarme", "Blowgun", "Bo Stick", "Caltrop", "Club", "Dagger", "Fauchard", "Fauchard-Fork", "Fist or Open Hand", "Flail, Footman's", "Flail, Horseman's", "Fork, Military", "Garrot", "Glaive", "Glaive-Guisarme", "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon", "Hammer, Lucern", "Hammer", "Hook Fauchard", "Jo Stick", "Knife", "Lance (light horse)", "Lance (medium horse)", "Lance (heavy horse)", "Lasso", "Mace, Footman's", "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan", "Pick, Military, Footman's", "Pick, Military, Horseman's", "Pike, Awl", "Ranseur", "Sap", "Scimitar", "Spear", "Spetum", "Spiked Buckler", "Staff, Quarter", "Staff Sling", "Sword, Bastard", "Sword, Broad", "Sword, Falchion", "Sword, Khopesh", "Sword, Long", "Sword, Short", "Sword, Two-handed", "Trident", "Voulge", "Whip" },
    }, {
      "name" = "uahhLength",
      "comment" = "The length (printed; \"n/a\" = the not-applicable rows).",
      "kind" = "string array",
      "count" = 60,
      "values" = { "c. 2'", "c. 3'", "c. 4'", "c. 1 1/2'", "c. 5'", "c. 6'", "8' +", "4'-7'", "c. 5'", "n/a", "c. 3'", "c. 15\\\"", "8' +", "8'", "2' +", "c. 4'", "c. 2'", "7' +", "c. 3'", "8' +", "8' +", "6' +", "7' +", "5' +", "6'-8'", "5' +", "c. 1 1/2'", "8' +", "c. 3'", "c. 1'", "10'", "12'", "c. 14'", "(10'-20')", "c. 2 1/2'", "c. 1 1/2'", "8' +", "c. 4'", "7' +", "c. 4'", "c. 2'", "18'", "8' +", "1/2'", "c. 3'", "5'-13' +", "8' +", "1'", "6'-8'", "5'", "c. 4 1/2'", "c. 3 1/2'", "c. 3 1/2'", "c. 3 1/2'", "c. 3 1/2'", "c. 2'", "c. 6'", "4'-8' +", "8' +", "8'-20'" },
    }, {
      "name" = "uahhSpaceRequired",
      "comment" = "The space required (printed; \"n/a\" = the caltrop).",
      "kind" = "string array",
      "count" = 60,
      "values" = { "2'", "1'", "4'", "1'", "5'", "6'", "2'", "1'", "3'", "n/a", "1'-3'", "1'", "2'", "2'", "n/a", "6'", "4'", "1'", "1 1/2'", "1'", "1'", "2'", "2'", "5'", "1 1/2'", "5'", "2'", "2 1/2'", "2'", "1'", "1'", "1'", "1'", "8' +", "4'", "2'", "2 1/2'", "5'", "3'", "4'", "2'", "1'", "1'", "1'", "2'", "1'", "1'", "2'", "3'", "6'", "4' +", "4'", "3 1/2'", "4'", "3'", "1'", "6'", "1'", "2'", "8'-20'" },
    }, {
      "name" = "uahhSpeedFactorMin",
      "comment" = "The speed factor minimum; -1 = the n/a rows (the atlatl, the blowgun, the caltrop).",
      "kind" = "header pin",
      "body" = "static const int k[60] = { 4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2, 8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9, 7, 5, 13, 8, 2, 4, 6, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 6, 10, 5, }; if (i < 0) i = 0; if (i > 59) i = 59; return k[i];",
    }, {
      "name" = "uahhSpeedFactorMax",
      "comment" = "The speed factor maximum (the Spear and Trident print the range 6-8, the Whip 5-8).",
      "kind" = "header pin",
      "body" = "static const int k[60] = { 4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2, 8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9, 7, 5, 13, 8, 2, 4, 8, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 8, 10, 8, }; if (i < 0) i = 0; if (i > 59) i = 59; return k[i];",
    }, {
      "name" = "uahhAcAdjustment",
      "comment" = "The AC adjustment by AC 0..10 (the full printed ladder).",
      "kind" = "header pin",
      "body" = "static const int k[60][11] = { { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { -5, -4, -3, -2, -1, -1, 0, 0, 1, 1, 2 }, { -5, -4, -3, -2, -2, -1, 0, 0, 1, 1, 1 }, { -3, -2, -2, -1, 0, 0, 1, 1, 2, 2, 3 }, { 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, -1 }, { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { -13, -11, -9, -7, -5, -3, -1, 0, 1, 0, 3 }, { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2 }, { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 }, { -4, -4, -3, -3, -2, -2, 0, 0, 1, 1, 3 }, { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 }, { -2, -2, -1, -1, -1, 0, 0, 0, 1, 0, 1 }, { -9, -8, -7, -5, -3, -1, 0, 0, 2, 0, 4 }, { 3, 3, 2, 2, 1, 2, 1, 1, 1, 1, -1 }, { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 }, { -3, -3, -2, -2, -1, 0, 0, 1, 1, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 }, { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 }, { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 }, { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 }, { 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 0 }, { -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 }, { 0, 1, 1, 1, 2, 2, 2, 1, 1, 0, 0 }, { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }, { -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, -1 }, { -10, -9, -8, -6, -4, -2, -1, 0, 1, 0, 2 }, { -6, -5, -5, -4, -3, -2, -1, 0, 1, 1, 3 }, { -3, -3, -2, -2, -1, 0, 0, 0, 0, 0, 0 }, { -1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 }, { 4, 4, 3, 3, 2, 2, 2, 1, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 2, 2, 1, 1, 0, 0, 0, 0, 0, 1, -1 }, { 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3 }, { 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 3, 3, 2, 2, 1, 1, 0, -1, -1, -1, -2 }, { 2, 2, 1, 1, 1, 1, 0, 0, -1, -1, -1 }, { -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -2 }, { -3, -3, -2, -1, -1, 0, 0, 0, 0, 0, 1 }, { -14, -13, -12, -10, -8, -6, -5, -4, -3, -2, 0 }, { -4, -3, -3, -2, -2, -1, 0, 0, 1, 1, 3 }, { -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 }, { -2, -2, -2, -1, 0, 0, 0, 0, 0, 1, 2 }, { -7, -6, -5, -4, -3, -2, -1, 0, 0, 0, 2 }, { -9, -8, -7, -5, -3, -1, 0, 0, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 }, { -5, -4, -3, -2, -1, 0, 0, 1, 1, 1, 2 }, { -3, -2, -2, -1, 0, 1, 1, 1, 1, 0, 0 }, { -7, -6, -5, -4, -2, -1, 0, 0, 1, 1, 2 }, { -4, -3, -2, -1, 0, 0, 0, 0, 0, 1, 2 }, { -5, -4, -3, -2, -1, 0, 0, 0, 1, 0, 2 }, { 2, 2, 2, 2, 2, 2, 3, 3, 3, 1, 0 }, { -4, -3, -3, -2, -1, -1, 0, 0, 1, 0, 1 }, { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 }, { -14, -12, -10, -8, -6, -4, -2, -1, 1, 0, 3 }, }; if (i < 0) i = 0; if (i > 59) i = 59; if (ac < 0) ac = 0; if (ac > 10) ac = 10; return k[i][ac];",
    }, {
      "name" = "uahhSetDoubleFlag",
      "comment" = "True when the row carries the * footnote (set to receive a charge: double damage - the spetum, the bastard sword).",
      "kind" = "header pin",
      "body" = "static const bool k[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, }; if (i < 0) i = 0; if (i > 59) i = 59; return k[i];",
    }, {
      "name" = "uahhDismountFlag",
      "comment" = "True when the row carries the ** footnote (the dismount capability - eight rows).",
      "kind" = "header pin",
      "body" = "static const bool k[60] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, }; if (i < 0) i = 0; if (i > 59) i = 59; return k[i];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uaecArmorCount']() != 4  or m['uaecArmsCount']() != 19  or strcmp(m['uaecArmorName'](0), \"Bronze Plate\") != 0  or m['uaecArmorCost'](0) != 100  or strcmp(m['uaecArmorName'](1), \"Full Plate\") != 0  or m['uaecArmorCost'](1) != 4000  or strcmp(m['uaecArmorName'](2), \"Field Plate\") != 0  or m['uaecArmorCost'](2) != 2000  or m['uaecArmorCost'](3) != 5  or strcmp(m['uaecArmsName'](0), \"Aklys\") != 0  or m['uaecArmsCost'](0) != 2  or strcmp(m['uaecArmsName'](5), \"Crossbow, hand\") != 0  or m['uaecArmsCost'](5) != 300  or strcmp(m['uaecArmsName'](6), \"Quarrels for same\") != 0  or m['uaecArmsCost'](6) != 100  or m['uaecArmsCost'](18) != 3  or  !m['uaecArmsPriceIsSilver'](3)  or  !m['uaecArmsPriceIsSilver'](4)  or  !m['uaecArmsPriceIsSilver'](11)  or m['uaecArmsPriceIsSilver'](0)  or  !m['uaecArmsPriceIsElectrum'](7)  or m['uaecArmsPriceIsElectrum'](0)  or m['uaecArmsPriceIsSilver'](i)) continue; if (m['uaecArmsPriceIsElectrum'](i)) continue; ++gp; } if (gp != 15",
      "note" = "U1: the equipment and supplies costs",
    }, {
      "expr" = "m['uahhRowCount']() != 60  or strcmp(m['uahhName'](0), \"Aklys\") != 0  or strcmp(m['uahhName'](59), \"Whip\") != 0  or strcmp(m['uahhName'](46), \"Spetum\") != 0  or strcmp(m['uahhLength'](0), \"c. 2'\") != 0  or strcmp(m['uahhSpaceRequired'](0), \"2'\") != 0  or m['uahhSpeedFactorMin'](0) != 4  or m['uahhSpeedFactorMax'](0) != 4  or m['uahhAklysSpeedBonus']() != 1  or m['uahhSpeedFactorMin'](1) != -1  or m['uahhSpeedFactorMin'](7) != -1  or m['uahhSpeedFactorMin'](9) != -1  or m['uahhSpeedFactorMin'](45) != 6  or m['uahhSpeedFactorMax'](45) != 8  or m['uahhSpeedFactorMin'](59) != 5  or m['uahhSpeedFactorMax'](59) != 8  or m['uahhAcAdjustment'](0, ac) != ac - 7  or m['uahhAcAdjustment'](5, 0) != 2  or m['uahhAcAdjustment'](5, 4) != 2  or m['uahhAcAdjustment'](5, 5) != 0  or m['uahhAcAdjustment'](5, 10) != -1  or m['uahhAcAdjustment'](59, 10) != 3  or m['uahhRearAttackBonus']() != 2  or m['uahhStunnedProneBonus']() != 4  or  m['uahhNoteSetDoubleVsCharge']() != 1  or  m['uahhNoteDismountOnHit']() != 1  or  !m['uahhSetDoubleFlag'](46)  or  !m['uahhSetDoubleFlag'](50)  or m['uahhSetDoubleFlag'](0)  or  !m['uahhDismountFlag'](12)  or  !m['uahhDismountFlag'](42)  or m['uahhDismountFlag'](0)  or m['uahhSetDoubleFlag'](i)) ++sd; if (m['uahhDismountFlag'](i)) ++dm; } if (sd != 2  or dm != 8",
      "note" = "U2: the hand-held weapons table",
    }, {
      "expr" = "m['uawtRowCount']() != 68  or m['uawtNewWeaponCount']() != 18  or strcmp(m['uawtName'](67), \"Quarrel (or Bolt), hand\") != 0  or  !m['uawtIsNewWeapon'](67)  or m['uawtPhbSeamIndex'](67) != -1  or m['uawtWeightMin'](67) != 1  or m['uawtDamageSMMin'](67) != 1  or m['uawtDamageSMMax'](67) != 3  or m['uawtDamageLMin'](67) != 1  or m['uawtDamageLMax'](67) != 2  or m['uawtDamageLMax'](19) != 6  or  !m['uawtDamagePrintsDash'](35)  or m['uawtDamagePrintsDash'](0)  or  m['uawtNote1ChargingMountDouble']() != 1  or  m['uawtNote2SetDoubleVsCharge']() != 1  or m['uawtNote3BladeClassLowInches']() != 15  or m['uawtNote3BladeClassHighInches']() != 24  or m['uawtNote4DisarmOnAcEightHit']() != 8  or  m['uawtNote5BastardAsLongSword']() != 1  or  m['uawtNote6VariantsSeePhb']() != 1  or m['uapfInitialSlots'](5) != 6  or m['uapfInitialSlots'](6) != 3  or m['uapfNonProfPenalty'](0) != 3  or m['uapfFacingPageNotesLost']()  or strcmp(m['uamtRateOfFire'](18), \"1/2\") != 0  or strcmp(m['uamtRangeShort'](0), \"1*\") != 0  or  m['uamtAklysTenFootOnly']() != 1",
      "note" = "U3: the amended tables (the reconcile cross-checks)",
    } },
  "audit" = {
      "label" = "R392: the UA players tables pin audit",
      "comment" = "The players tables manifest sweep (20 items): the equipment and supplies costs table and the hand-held weapons table pin NEW (rules/ua/uaequip26.h, rules/ua/uahandheld.h); the weight/damage, missile and proficiency tables AMEND (the clean PDF read: every hole fills, three misdecodes reconcile - the garrot L damage, the barbarian initial, the ranger initial); the seventeen covered rides close the manifest.",
    },
}
