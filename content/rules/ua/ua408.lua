-- ua: promoted from rules/ua/uaac26.h (the The UA ARMOR CLASS TABLE (p. 26),);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 408,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA ARMOR CLASS TABLE (p. 26),",
      "provenance" = "R408: the 11 composite rows AC 10 down to 0, pinned directly from the print. The R392 manifest closed the item by derivation (the R371 pin pp. 75-76 + the R191 seam); this round pins the printed rows as printed and closes the two stale duplicate boxes the R392 pass missed in the weapons section checklist.  The print (the clean djvu scan, agreeing with the R392 PDF read): 10: none; 9: shield only; 8: leather armor or padded armor; 7: leather + shield, padded + shield, studded leather, ring mail; 6: studded leather + shield, ring mail + shield, scale mail; 5: scale mail + shield, chain mail, elfin chain mail; 4: chain mail + shield, elfin chain + shield, splint mail, banded mail, bronze plate mail; 3: splint mail + shield, banded mail + shield, bronze plate mail + shield, plate mail; 2: plate mail + shield or field plate armor; 1: field plate armor + shield or full plate armor; 0: full plate armor + shield. 28 composites across the 11 rows.  The cross-checks run live: - the type rows read armorRatingAc (the R191 ladder): leather 8, chain 5, plate mail 3; - the shield composites read base minus armorRatingShieldStep (the leather 8 with shield 7, the scale 6 with shield 5, the full plate 1 with shield 0); - the bronze plate mail reads 4, one worse than plate mail 3 - the R371 description pin; - the R392 equipment costs re-verify against the scan: bronze plate 100 gp, full plate 4000 gp, field plate 2000 gp, the buckler 5 gp.",
    },
  "consts" = { {
      "name" = "uacrRowCount",
      "value" = 11,
      "comment" = "The row count (AC 10 down to 0).",
    }, {
      "name" = "uacrCompositeCount",
      "value" = 28,
      "comment" = "The total composite count (28).",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "uacrRowAc",
      "comment" = "The i-th row armor class (10 - i).",
      "kind" = "header pin",
      "body" = "return 10 - i;",
    }, {
      "name" = "uacrRowSet",
      "comment" = "The i-th row armor-set description, as printed.",
      "kind" = "string array",
      "count" = 11,
      "values" = { "none", "shield only", "leather armor or padded armor", "leather + shield, padded + shield, studded leather, ring mail", "studded leather + shield, ring mail + shield, scale mail", "scale mail + shield, chain mail, elfin chain mail", "chain mail + shield, elfin chain + shield, splint mail, banded mail, bronze plate mail", "splint mail + shield, banded mail + shield, bronze plate mail + shield, plate mail", "plate mail + shield or field plate armor", "field plate armor + shield or full plate armor", "full plate armor + shield" },
    }, {
      "name" = "uacrRowMemberCount",
      "comment" = "The composite count per row: 1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1 - 28 total.",
      "kind" = "header pin",
      "body" = "static const int k[11] = { 1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1 }; if (i < 0) i = 0; if (i > 10) i = 10; return k[i];",
    }, {
      "name" = "uacrRowHasShieldMember",
      "comment" = "True when the row reads a shield composite member (rows 3-10 carry at least one; rows 0-2 none).",
      "kind" = "header pin",
      "body" = "return i >= 3;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uacrRowCount']() != 11  or m['uacrRowAc'](0) != 10  or m['uacrRowAc'](5) != 5  or m['uacrRowAc'](10) != 0  or strcmp(m['uacrRowSet'](0), \"none\") != 0  or strcmp(m['uacrRowSet'](1), \"shield only\") != 0  or strcmp(m['uacrRowSet'](10), \"full plate armor + shield\") != 0  or m['uacrRowMemberCount'](0) != 1  or m['uacrRowMemberCount'](3) != 4  or m['uacrRowMemberCount'](6) != 5  or m['uacrRowMemberCount'](10) != 1",
      "note" = "---- the ladder ----",
    }, {
      "expr" = "m['uacrRowMemberCount'](0) +m['uacrRowMemberCount'](1) +m['uacrRowMemberCount'](2) +m['uacrRowMemberCount'](3) +m['uacrRowMemberCount'](4) +m['uacrRowMemberCount'](5) +m['uacrRowMemberCount'](6) +m['uacrRowMemberCount'](7) +m['uacrRowMemberCount'](8) +m['uacrRowMemberCount'](9) +m['uacrRowMemberCount'](10) !=m['uacrCompositeCount']()  or m['uacrCompositeCount']() != 28  or  !m['uacrRowHasShieldMember'](3)  or  !m['uacrRowHasShieldMember'](10)  or m['uacrRowHasShieldMember'](0)  or m['uacrRowHasShieldMember'](2)",
      "note" = "the composites add up",
    }, {
      "expr" = "m['uacrRowAc'](2) !=m['armorRatingAc'](3)  or m['uacrRowAc'](4) !=m['armorRatingAc'](6)  or m['uacrRowAc'](5) !=m['armorRatingAc'](7)  or m['uacrRowAc'](7) !=m['armorRatingAc'](10)",
      "note" = "---- the R191 cross-checks ---- the type rows read the ladder",
    }, {
      "expr" = "m['uacrRowAc'](2) -m['armorRatingShieldStep']() !=m['uacrRowAc'](3)  or m['uacrRowAc'](4) -m['armorRatingShieldStep']() !=m['uacrRowAc'](5)  or m['uacrRowAc'](8) -m['armorRatingShieldStep']() !=m['uacrRowAc'](9)  or m['uacrRowAc'](9) -m['armorRatingShieldStep']() !=m['uacrRowAc'](10)",
      "note" = "the shield composites read base minus the step: leather 8 with shield 7, scale 6 with shield 5, full plate 1 with shield 0",
    }, {
      "expr" = "m['uaarmBronzeAc']() != 4  or m['uaarmBronzeAc']() !=m['armorRatingAc'](7) - 1",
      "note" = "---- the R371 bronze read ----",
    }, {
      "expr" = "m['uaarmBronzeAc']() !=m['uacrRowAc'](6)  or m['uaarmBronzeAc']() -m['armorRatingShieldStep']() !=m['uacrRowAc'](7)",
      "note" = "the bronze plate mail composite reads row 4, its shield row 3",
    }, {
      "expr" = "m['uaecArmorCount']() != 4  or m['uaecArmorCost'](0) != 100  or m['uaecArmorCost'](1) != 4000  or m['uaecArmorCost'](2) != 2000  or m['uaecArmorCost'](3) != 5  or m['uaecArmsCount']() != 19  or m['uaecArmsCost'](0) != 2  or m['uaecArmsCost'](5) != 300  or m['uaecArmsCost'](6) != 100  or m['uaecArmsPriceIsSilver'](11) != true",
      "note" = "---- the R392 equipment costs ---- the scan re-verifies the pins: bronze 100, full 4000, field 2000, the buckler 5",
    } },
  "audit" = {
      "label" = "R408: the UA p. 26 armor class table pin audit",
      "comment" = "The composite ladder pins directly: the 11 rows AC 10 to 0, the printed armor sets, the 28 composites; the type rows cross-check the R191 ladder live, the shield composites read base minus the step, the bronze read cross-checks the R371 pin, and the R392 equipment costs re-verify against the independent scan; the two stale boxes close; census 334 -> 335.",
    },
}
