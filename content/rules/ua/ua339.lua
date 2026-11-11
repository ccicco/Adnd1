-- ua339: promoted from rules/ua/uaprof.h (the The UA WEAPON PROFICIENCY TABLE (p. 26) pins (R339).);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 339,
  "prefix" = "ua339",
  "banner" = {
      "title" = "The UA WEAPON PROFICIENCY TABLE (p. 26) pins (R339).",
      "provenance" = "Pin-era pattern (R322): pinned data only - no engine site exists. The R297 PHB pin (rules/phb/weaponprof.h) is the decode seam.  JUDGMENTs: - the roster: 14 rows in the printed order. Seven rows match the PHB rows cell for cell (cleric, druid, fighter, magic-user, illusionist, thief, monk) - every readable cell seam-verifies against R297, proving the OCR patterns row by row. The UA-new rows: cavalier, barbarian, acrobat, bard (no PHB row). - the minus-loss decode: unsigned penalty magnitudes print where the PHB prints -2/-3 (the fighter 2, the monk 3) - the R297 magnitude convention, sign carried by the convention not the print. The barbarian prints -1 signed. - the cadence cells print \"1/4 levels\" style; the cavalier and paladin rows print \"112 levels\" - the slash-loss decode to 1/2 levels (the barbarian and monk rows print \"1/2 levels\" clean, proving the cadence in this table). - the cavalier initial prints \"3\u00b0\" - the degree sign is an OCR artifact on the digit; 3 pins. - attributed rows: the post-MAGIC-USER nameless row (1, -5, 1/6) attributes to the Illusionist - the only roster class otherwise absent in its printed place, cells matching the R297 illusionist row. The \"EF\" row (2, -3, 1/4) attributes to the Thief - the garbled name fragment, cells matching the R297 thief row. The post-Acrobat fragment row attributes to the Assassin - the only roster class otherwise absent, sitting exactly at the PHB table's assassin position. The fragment splits to FIVE cells (one misaligned extra empty); the added column anchors right (1/4 levels), and the 2 reads as the PENALTY cell - the PHB-consistent read (an initial-cell read would deviate from every other PHB-matching row in this table); the initial prints lost, a hole. - deviations from the PHB (pinned as printed, noted): the ranger initial prints 8 where the PHB row reads 3 (the R297 seam) - pinned as printed, the echo-of-the-barbarian row doubt noted pending the PDF. The paladin penalty prints 3 where the PHB reads 2, and the paladin cadence prints 1/2 where the PHB reads 1/3 - the UA paladin rides the cavalier group's values, pinned as printed.  R392 (the clean PDF read): every hole closes. The cavalier penalty prints 3 (magnitude 3, the R297 convention); the paladin and assassin initial cells print 3; the facing-page notes read in full: the 0-level Horsemen 1 proficiency, the 0-level Lancers 2, the 1st-level Armigers 3, and the cavalier/ranger weapon-choice restriction. Two misdecodes reconcile: the barbarian initial reads 6 (the pinned 8 was an echo), the ranger initial 3 (the asterisk row) - the deviations from the PHB resolve, the R297 seam now agrees cell for cell on every shared row except the paladin penalty/cadence pair, which rides the cavalier group as printed.",
    },
  "consts" = { {
      "name" = "uapfRowCount",
      "value" = 14,
      "comment" = "The row count (14 = the 10 PHB classes plus the cavalier, barbarian, acrobat and bard).",
    }, {
      "name" = "uapfHorsemenInitialSlots",
      "value" = 1,
      "comment" = "The 0-level Horsemen (cavaliers) have 1 weapon of proficiency.",
    }, {
      "name" = "uapfLancersInitialSlots",
      "value" = 2,
      "comment" = "The 0-level Lancers (cavaliers): 2 weapons.",
    }, {
      "name" = "uapfArmigersInitialSlots",
      "value" = 3,
      "comment" = "The 1st-level Armigers (cavaliers): 3 weapons.",
    } },
  "bools" = { {
      "name" = "uapfFacingPageNotesLost",
      "value" = false,
      "comment" = "The facing-page notes: the R392 clean read - the lost flag flips false, the notes read in full below.",
    }, {
      "name" = "uapfRestrictedWeaponChoice",
      "value" = true,
      "comment" = "Cavaliers and rangers are restricted in which weapons they can choose to take proficiency in (see the class descriptions).",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uapfName",
      "comment" = "The row name (printed; the three attributed rows carry the attribution JUDGMENT - uapfNameIsAttributed flags them).",
      "kind" = "string array",
      "count" = 14,
      "values" = { "Cavalier", "Paladin", "Cleric", "Druid", "Fighter", "Barbarian", "Ranger", "Magic-User", "Illusionist", "Thief", "Acrobat", "Assassin", "Monk", "Bard" },
    }, {
      "name" = "uapfPhbSeamRow",
      "comment" = "The R297 ProfRow each row seam-verifies against; -1 = a UA-new row (no PHB row). The acrobat seam-closes to the thief row's values by print (not by PHB membership).",
      "kind" = "header pin",
      "body" = "// cavalier, paladin, cleric, druid, fighter, // barbarian, ranger, magic-user, illusionist, // thief, acrobat, assassin, monk, bard static const int k[14] = { -1, 3, 0, 1, 2, -1, 4, 5, 6, 7, 7, 8, 9, -1 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    }, {
      "name" = "uapfNameIsAttributed",
      "comment" = "True when the row name is an attribution (the printed name is OCR-lost or garbled; the data assigns the row).",
      "kind" = "header pin",
      "body" = "// illusionist, thief, assassin static const bool k[14] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    }, {
      "name" = "uapfInitialSlots",
      "comment" = "The initial number of weapons (the R392 clean read: the paladin and assassin cells print 3, the barbarian 6, the ranger 3 - the asterisk rows carry the choice restriction).",
      "kind" = "header pin",
      "body" = "static const int k[14] = { 3, 3, 2, 2, 4, 6, 3, 1, 1, 2, 2, 3, 1, 5 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    }, {
      "name" = "uapfNonProfPenalty",
      "comment" = "The non-proficiency to-hit penalty MAGNITUDE (the R297 convention; the adjustment is negative). The R392 clean read: the cavalier cell prints 3.",
      "kind" = "header pin",
      "body" = "static const int k[14] = { 3, 3, 3, 4, 2, 1, 2, 5, 5, 3, 3, 2, 3, 2 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    }, {
      "name" = "uapfAddedCadence",
      "comment" = "The added-proficiency levels-per-slot (one new proficiency per N levels above the 1st, the R297 note).",
      "kind" = "header pin",
      "body" = "static const int k[14] = { 2, 2, 4, 5, 3, 2, 3, 6, 6, 4, 4, 4, 2, 4 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    }, {
      "name" = "uapfInitialAsterisk",
      "comment" = "True when the row's initial cell prints the restriction asterisk (the cavalier, paladin and ranger rows).",
      "kind" = "header pin",
      "body" = "static const bool k[14] = { 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }; if (i < 0) i = 0; if (i > 13) i = 13; return k[i];",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uapfRowCount']() != 14  or strcmp(m['uapfName'](0), \"Cavalier\") != 0  or strcmp(m['uapfName'](5), \"Barbarian\") != 0  or strcmp(m['uapfName'](10), \"Acrobat\") != 0  or strcmp(m['uapfName'](13), \"Bard\") != 0  or  !m['uapfNameIsAttributed'](8)  or  !m['uapfNameIsAttributed'](9)  or  !m['uapfNameIsAttributed'](11)  or m['uapfNameIsAttributed'](10)  or m['uapfNameIsAttributed'](i)) ++attr; if (attr != 3",
      "note" = "U1: the counts and the roster",
    }, {
      "expr" = "m['uapfInitialSlots'](i) != k[i]  or m['uapfInitialSlots'](1) != 3  or m['uapfInitialSlots'](11) != 3",
      "note" = "U2: the initial slots",
    }, {
      "expr" = "m['uapfNonProfPenalty'](i) != k[i]  or m['uapfNonProfPenalty'](0) != 3  or m['uapfNonProfPenalty'](1) != 3",
      "note" = "U3: the penalties (magnitudes)",
    }, {
      "expr" = "m['uapfAddedCadence'](i) != k[i]  or m['uapfAddedCadence'](0) != 2  or m['uapfAddedCadence'](1) != 2",
      "note" = "U4: the cadences",
    }, {
      "expr" = "j < 0) {  or m['uapfInitialSlots'](i) !=m['wpfInitialSlots'](j)  or m['uapfNonProfPenalty'](i) !=m['wpfNonProfPenalty'](j)  or m['uapfAddedCadence'](i) !=m['wpfAddedCadence'](j)  or m['uapfPhbSeamRow'](0) != -1  or m['uapfPhbSeamRow'](1) != PROF_PALADIN  or m['uapfPhbSeamRow'](6) != PROF_RANGER  or m['uapfPhbSeamRow'](11) != PROF_ASSASSIN  or m['uapfPhbSeamRow'](13) != -1",
      "note" = "U5: the R297 seam - the seven rows that match the PHB cell for cell",
    }, {
      "expr" = "m['uapfInitialSlots'](6) != 3  or m['wpfInitialSlots'](PROF_RANGER) != 3  or m['uapfNonProfPenalty'](1) !=m['wpfNonProfPenalty']( PROF_PALADIN) + 1  or m['uapfAddedCadence'](1) !=m['wpfAddedCadence']( PROF_PALADIN) - 1  or m['uapfNonProfPenalty'](11) !=m['wpfNonProfPenalty']( PROF_ASSASSIN)  or m['uapfAddedCadence'](11) !=m['wpfAddedCadence']( PROF_ASSASSIN)",
      "note" = "U6: the deviations reconciled (the R392 clean read)",
    }, {
      "expr" = "m['uapfInitialSlots'](0) + (1 - 1) /m['uapfAddedCadence'](0) != 3  or m['uapfInitialSlots'](0) + (3 - 1) /m['uapfAddedCadence'](0) != 4  or m['uapfInitialSlots'](5) + (3 - 1) /m['uapfAddedCadence'](5) != 7",
      "note" = "U7: the slots arithmetic rides the R297 convention (one per cadence above 1st)",
    }, {
      "expr" = "m['uapfFacingPageNotesLost']()  or m['uapfHorsemenInitialSlots']() != 1  or m['uapfLancersInitialSlots']() != 2  or m['uapfArmigersInitialSlots']() != 3  or  m['uapfRestrictedWeaponChoice']() != 1  or  !m['uapfInitialAsterisk'](0)  or  !m['uapfInitialAsterisk'](1)  or  !m['uapfInitialAsterisk'](6)  or m['uapfInitialAsterisk'](5)  or m['uapfInitialAsterisk'](13)",
      "note" = "U8: the facing-page notes (the R392 clean read: the notes recover in full)",
    } },
  "audit" = {
      "label" = "R339: the UA proficiency pin audit",
      "comment" = "The UA WEAPON PROFICIENCY TABLE (p. 26) - the 14-row roster: seven rows match the PHB rows cell for cell (the R297 seam, verified live), the UA-new rows (cavalier, barbarian, acrobat, bard), the attributed fragment rows (illusionist, thief, assassin - documented JUDGMENTs); the R392 clean PDF read fills every hole (the cavalier penalty 3, the paladin and assassin initials 3) and reconciles the misdecodes (the barbarian 6, the ranger 3), the facing-page notes read in full - the item AMENDED, closes.",
    },
}
