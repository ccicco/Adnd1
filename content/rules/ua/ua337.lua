-- ua337: promoted from rules/uaweapontable.h (the The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) pins);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 337,
  "prefix" = "ua337",
  "banner" = {
      "title" = "The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) pins",
      "provenance" = "(R337).  Pin-era pattern (R322): pinned data only - no engine site exists.  JUDGMENTs: - the roster: 67 rows in the printed order. The OCR merges and garbles several rows; every row is attributed by data, not guesswork: the 50 PHB weapons (the R189 chart, rules/weapontables.h) match cell for cell - uawtPhbSeamIndex maps each row to its chart row. The merged Jo Stick/Javelin, Long/Short Sword and Lance (heavy)/Lasso rows split by seam. - the hyphen-loss pattern: the OCR drops hyphens in many damage cells (1-6 prints 16, 2-12 prints 212), dots or colons in others (2.5 = 2-5, 2:8 = 2-8). The pattern is proven against the R189 seam on every PHB row it touches (the arrow 16, dagger 14, bo stick 13, halberd 212, the heavy quarrel 2.5/2.7). The new-weapon cells decoded by the same pattern pin as pattern-decoded. - attributed rows: the Military Fork and Glaive-Guisarme data rows print nameless (OCR-displaced); each matches exactly one R189 row - attributed by unique seam match. The pick rows print garbled names; the data assigns them. The row between Ranseur and Scimitar (10, 1-2, 1-2) attributes to the Sap - the roster's named new weapon otherwise absent, in its alphabetical place. - the Garrot row prints a stray 3 beside the weight column; the weight 1 pins (the weight-column cell). The Lance (heavy)/Lasso merged row prints 150 20 - the 150 is the lance (seam), the 20 pins as the lasso weight. - the horseman flail S/M cell prints empty in the UA extract - it closes via the R189 seam (2-5, the PHB print), the R333 seam-closure convention; the L cell 2.5 decodes by the dot pattern to the same value. - flat damage cells pin as printed (the blowgun 1/1, the caltrop 1, the whip L 1).  R392 (the clean PDF read): every hole closes. The atlatl weight reads 30, the harpoon 50-60, the falchion 60-80, the lasso damage cells print the dash (0 damage, the print flagged uawtDamagePrintsDash), and the garbled quarrel row reads in full (Quarrel (or Bolt), hand - 1 gp, 1-3, 1-2 - the 68th row, appended at the roster end, its printed position between the pike and the light quarrel). One misdecode reconciles: the garrot L damage reads 1-6, not the hyphen-loss 1-8. The p. 26 footnotes read in full (the six numbered notes - uawtNote1 through uawtNote6).",
    },
  "consts" = { {
      "name" = "uawtRowCount",
      "value" = 68,
      "comment" = "The row count (68 = the 50 PHB rows plus 18 new-weapon rows; the R392 clean read adds the hand-crossbow quarrel row the garbled extract dropped).",
    }, {
      "name" = "uawtSeamVerifiedCount",
      "value" = 50,
      "comment" = "The PHB rows verified cell for cell against the R189 chart seam.",
    }, {
      "name" = "uawtNewWeaponCount",
      "value" = 18,
      "comment" = "The UA-new weapon rows (not in the PHB chart): the aklys, atlatl, blowgun, caltrop, garrot, harpoon, hook fauchard, knife, lasso, man catcher, sap, spiked buckler, staff sling (two rows), falchion, khopesh, whip and the hand-crossbow quarrels (the R392 clean read).",
    }, {
      "name" = "uawtNote3BladeClassLowInches",
      "value" = 15,
      "comment" = "Note 3: this weapon class includes all pointed cutting and thrusting weapons with blade length between 15 and 24 inches.",
    }, {
      "name" = "uawtNote3BladeClassHighInches",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uawtNote4DisarmOnAcEightHit",
      "value" = 8,
      "comment" = "Note 4: these weapons are capable of disarming an opponent on a score required to hit AC 8.",
    } },
  "bools" = { {
      "name" = "uawtNote1ChargingMountDouble",
      "value" = true,
      "comment" = "---- the printed notes (the p. 26 facing page) ---- Note 1: these weapons do twice the indicated damage against creatures of any size when employed by an attacker riding a charging mount (the lance rows).",
    }, {
      "name" = "uawtNote2SetDoubleVsCharge",
      "value" = true,
      "comment" = "Note 2: this weapon does twice the damage indicated to any opponent when the weapon is set to receive their charge.",
    }, {
      "name" = "uawtNote5BastardAsLongSword",
      "value" = true,
      "comment" = "Note 5: treat this weapon as a long sword if it is used one-handed.",
    }, {
      "name" = "uawtNote6VariantsSeePhb",
      "value" = true,
      "comment" = "Note 6: minor variations of these weapons, with different names, may exist in the campaign. See Players Handbook for particulars.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uawtName",
      "comment" = "The row name (printed, or the attribution judgment).",
      "kind" = "string array",
      "count" = 68,
      "values" = { "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle", "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin", "Bill-Guisarme", "Blowgun and needle", "Bo Stick", "Caltrop", "Club", "Dagger", "Dart", "Fauchard", "Fauchard-Fork", "Flail, Footman's", "Flail, Horseman's", "Military Fork", "Garrot", "Glaive", "Glaive-Guisarme", "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon", "Hammer, Lucern", "Hammer", "Hook Fauchard", "Javelin", "Jo Stick", "Knife", "Lance (light horse)", "Lance (medium horse)", "Lance (heavy horse)", "Lasso", "Mace, Footman's", "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan", "Pick, Footman's", "Pick, Horseman's", "Pike, Awl", "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy", "Ranseur", "Sap", "Scimitar", "Sling Bullet", "Sling Stone", "Spear", "Spetum", "Spiked Buckler", "Staff, Quarter", "Staff Sling Bullet", "Staff Sling Stone", "Sword, Bastard", "Sword, Broad", "Sword, Falchion", "Sword, Khopesh", "Long Sword", "Sword, Short", "Sword, Two-handed", "Trident", "Voulge", "Whip", "Quarrel (or Bolt), hand" },
    }, {
      "name" = "uawtIsNewWeapon",
      "comment" = "True when the row is a UA-new weapon.",
      "kind" = "header pin",
      "body" = "static const bool k[68] = { 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtPhbSeamIndex",
      "comment" = "The R189 chart row (rules/ weapontables.h) each PHB row verifies against; -1 = a new weapon.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12, 13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23, -1, 24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34, 35, 36, -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44, -1, -1, 45, 46, 47, 48, 49, -1, -1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtWeightMin",
      "comment" = "The approximate weight in gold pieces; -1 = the weight cell is OCR-lost.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5, 60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 50, 150, 50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4, 100, 75, 60, 75, 60, 35, 250, 50, 125, 25, 1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtWeightMax",
      "comment" = "The weight maximum - equal to the minimum except the printed ranges (caltrop, spear, whip).",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5, 60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 60, 150, 50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4, 100, 75, 80, 75, 60, 35, 250, 50, 125, 35, 1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtDamageSMMin",
      "comment" = "The damage vs. size S or M: the minimum; -1 = OCR-lost.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 0, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtDamageSMMax",
      "comment" = "The damage vs. size S or M: the maximum.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8, 4, 6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, 0, 7, 6, 2, 8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8, 8, 8, 7, 8, 8, 6, 10, 7, 8, 2, 3, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtDamageLMin",
      "comment" = "The damage vs. size L: the minimum; -1 = OCR-lost.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2, 2, 2, 2, 1, 1, 1, 3, 3, 2, 1, 1, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtDamageLMax",
      "comment" = "The damage vs. size L: the maximum.",
      "kind" = "header pin",
      "body" = "static const int k[68] = { 3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5, 8, 6, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18, 0, 6, 4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12, 3, 6, 9, 8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1, 2, }; if (i < 0) i = 0; if (i > 67) i = 67; return k[i];",
    }, {
      "name" = "uawtDamagePrintsDash",
      "comment" = "True when the row's damage cells print the dash (the lasso - the dash reads 0 damage).",
      "kind" = "header pin",
      "body" = "return i == 35;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uawtRowCount']() != 68  or m['uawtSeamVerifiedCount']() != 50  or m['uawtNewWeaponCount']() != 18  or strcmp(m['uawtName'](0), \"Aklys\") != 0  or strcmp(m['uawtName'](66), \"Whip\") != 0  or strcmp(m['uawtName'](67), \"Quarrel (or Bolt), hand\") != 0  or strcmp(m['uawtName'](30), \"Jo Stick\") != 0  or strcmp(m['uawtName'](47), \"Sap\") != 0  or strcmp(m['uawtName'](53), \"Spiked Buckler\") != 0",
      "note" = "U1: the counts and the roster anchors",
    }, {
      "expr" = "j < 0) continue; if (m['uawtWeightMin'](i) !=m['weaponChartWeight'](j)  or m['uawtDamageSMMin'](i) !=m['weaponChartDamageSMMin'](j)  or m['uawtDamageSMMax'](i) !=m['weaponChartDamageSMMax'](j)  or m['uawtDamageLMin'](i) !=m['weaponChartDamageLMin'](j)  or m['uawtDamageLMax'](i) !=m['weaponChartDamageLMax'](j)",
      "note" = "U2: the full 50-row R189 seam verification",
    }, {
      "expr" = "strcmp(m['uawtName'](8), \"Blowgun and needle\") != 0  or m['uawtWeightMin'](8) != 15  or m['uawtDamageSMMin'](8) != 1  or m['uawtDamageSMMax'](8) != 1  or m['uawtDamageLMin'](8) != 1  or m['uawtDamageLMax'](8) != 1  or m['uawtWeightMin'](19) != 1  or m['uawtDamageSMMin'](19) != 1  or m['uawtDamageSMMax'](19) != 4  or m['uawtDamageLMin'](19) != 1  or m['uawtDamageLMax'](19) != 6  or m['uawtWeightMin'](28) != 80  or m['uawtDamageSMMin'](28) != 1  or m['uawtDamageSMMax'](28) != 4  or m['uawtDamageLMin'](28) != 1  or m['uawtDamageLMax'](28) != 4  or m['uawtWeightMin'](31) != 6  or m['uawtDamageSMMax'](31) != 3  or m['uawtDamageLMin'](31) != 1  or m['uawtDamageLMax'](31) != 2  or m['uawtWeightMin'](38) != 80  or m['uawtDamageSMMax'](38) != 2  or m['uawtDamageLMax'](38) != 2  or m['uawtWeightMin'](47) != 10  or m['uawtDamageSMMin'](47) != 1  or m['uawtDamageSMMax'](47) != 2  or m['uawtDamageLMin'](47) != 1  or m['uawtDamageLMax'](47) != 2  or m['uawtWeightMin'](53) != 35  or m['uawtDamageSMMax'](53) != 4  or m['uawtDamageLMin'](53) != 1  or m['uawtDamageLMax'](53) != 3  or m['uawtWeightMin'](55) != 5  or m['uawtDamageSMMin'](55) != 2  or m['uawtDamageSMMax'](55) != 8  or m['uawtDamageLMin'](55) != 3  or m['uawtDamageLMax'](55) != 9  or m['uawtWeightMin'](56) != 4  or m['uawtDamageSMMin'](56) != 1  or m['uawtDamageSMMax'](56) != 8  or m['uawtDamageLMin'](56) != 2  or m['uawtDamageLMax'](56) != 8  or m['uawtWeightMin'](60) != 75  or m['uawtDamageSMMin'](60) != 2  or m['uawtDamageSMMax'](60) != 8  or m['uawtDamageLMin'](60) != 1  or m['uawtDamageLMax'](60) != 6  or m['uawtWeightMin'](66) != 25  or m['uawtWeightMax'](66) != 35  or m['uawtDamageSMMax'](66) != 2  or m['uawtDamageLMin'](66) != 1  or m['uawtDamageLMax'](66) != 1",
      "note" = "U3: the new-weapon rows, the pinned cells",
    }, {
      "expr" = "m['uawtWeightMin'](0) != 35  or m['uawtDamageSMMin'](0) != 1  or m['uawtDamageSMMax'](0) != 6  or m['uawtDamageLMin'](0) != 1  or m['uawtDamageLMax'](0) != 3  or m['uawtWeightMin'](1) != 30  or m['uawtDamageSMMin'](1) != 1  or m['uawtDamageSMMax'](1) != 6  or m['uawtDamageLMin'](1) != 1  or m['uawtDamageLMax'](1) != 6  or m['uawtWeightMin'](25) != 50  or m['uawtWeightMin'](59) != 60  or m['uawtWeightMin'](35) != 20  or m['uawtDamageSMMin'](35) != 0  or m['uawtDamageSMMax'](35) != 0  or m['uawtDamageLMin'](35) != 0  or m['uawtDamageLMax'](35) != 0",
      "note" = "U4: the aklys, the atlatl and the holes",
    }, {
      "expr" = "m['uawtWeightMin'](i) != rng[r][1]  or m['uawtWeightMax'](i) != rng[r][2]  or m['uawtWeightMin'](i) < 0) continue; bool ranged = i == 10  or i == 51  or i == 66  or i == 25  or i == 59; if (m['uawtWeightMax'](i) !=m['uawtWeightMin'](i) && !ranged  or m['uawtIsNewWeapon'](i)) ++newc; if (m['uawtIsNewWeapon'](i) != (m['uawtPhbSeamIndex'](i) < 0)  or newc != 18",
      "note" = "U5: the weight ranges and the new-weapon flag agreement",
    }, {
      "expr" = "m['weaponChartRowCount']() != 50",
      "note" = "U6: the R189 seam census",
    } },
  "audit" = {
      "label" = "R337: the UA weight and damage pin audit",
      "comment" = "The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) - the 68-row roster: all 50 PHB rows verified cell for cell against the R189 chart seam (the hyphen-loss pattern proven row by row), the 17 new-weapon rows pinned where printed or pattern-decoded; the R392 clean PDF read fills every hole (the atlatl 30, the harpoon 50-60, the falchion 60-80, the lasso dash) and adds the 68th row (the hand-crossbow quarrels), one misdecode reconciles (the garrot L 1-6) - the item AMENDED, closes.",
    },
}
