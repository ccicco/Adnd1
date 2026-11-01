-- oa651: promoted from rules/oamslspec.h (the TABLE 57 MISSILE SPECIALIZATIONS, printed capture pp. 100-101 - the OA);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 651,
  "prefix" = "oa651",
  "banner" = {
      "title" = "TABLE 57 MISSILE SPECIALIZATIONS, printed capture pp. 100-101 - the OA",
      "provenance" = "missile specializations round census 573 -> 574.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the section - the Table 57 grid cross-checked cell-by-cell between the two passes (the table opens on capture p. 100 of the print pass with the Number of Attacks Per Round With header and its column-name fragments, the full grid printing on p. 101; compressed p. 52); every printed cell agrees - zero contested cells. The grid pins per the T55 pair precedent: each printed num/den attacks pair becomes a numerator and a denominator column, the level rows 0 the 1-6 band, 1 the 7-12 band and 2 the 13-and-up band riding the first column comment, and the level-band bounds pin as consts (three bands, tops at 6 and 12). The seven printed columns: the bow (2/1, 3/1, 4/1 up the bands), the light crossbow (1/1, 3/2, 2/1), the pellet bow and heavy crossbow (1/2, 1/1, 3/2), the lasso and staff sling (1/1, 3/2, 2/1), the large shuriken and thrown dagger (3/1, 4/1, 5/1), the dart and small shuriken (4/1, 5/1, 6/1) and the other column (3/2, 2/1, 5/2). Two column-name reads settle from the print pass's own p. 100 header fragments plus the compressed corroboration: the p. 101 header reads Bow & Heavy Crossbow and Shuriken, Thrown Dagger, dropping the Pellet and Large that the p. 100 fragments carry - the names pin as pellet bow & heavy crossbow and large shuriken & thrown dagger. The specialist-prose cross-references stay with R650; the grid completes the weapon proficiencies arc of Chapter 6  the gap census after this round: 103 closed, 132 open - the Table 57 box flips (census 573 -> 574); NEXT - R652: the Non-Weapon Proficiencies prose with the optional peaceful proficiency bonuses, the success-and-failure doctrine and the contests (capture pp. 101-103), prefix dhm (verify free), audit \"R652 OA non-weapon proficiencies audit\", include after rules/oamslspec.h",
    },
  "consts" = { {
      "name" = "dhlT57BandCount",
      "value" = 3,
      "comment" = "the three level bands of the specialist grid - 1 through 6, 7 through 12, and 13 and up (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57FirstBandTop",
      "value" = 6,
      "comment" = "the first level band runs 1 through 6 (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57SecondBandTop",
      "value" = 12,
      "comment" = "the second level band runs 7 through 12, the third band 13 and up (capture p. 100 of the print pass; compressed p. 52)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "dhlT57BowNum",
      "values" = { 2, 3, 4 },
      "default" = -99,
      "comment" = "the bow specialist attacks-per-round numerator by level band (capture p. 100 of the print pass; compressed p. 52). The level rows ride this comment: 0 the 1-6 band, 1 the 7-12 band, 2 the 13-and-up band - the printed cell is the num/den attacks pair, carried per the T55 full/half pair precedent",
    }, {
      "name" = "dhlT57BowDen",
      "values" = { 1, 1, 1 },
      "default" = -99,
      "comment" = "the bow specialist attacks-per-round denominator - the number after the slash (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57LightNum",
      "values" = { 1, 3, 2 },
      "default" = -99,
      "comment" = "the light crossbow specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57LightDen",
      "values" = { 1, 2, 1 },
      "default" = -99,
      "comment" = "the light crossbow denominator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57PelletHeavyNum",
      "values" = { 1, 1, 3 },
      "default" = -99,
      "comment" = "the pellet bow and heavy crossbow specialist attacks-per-round numerator - the column name settles from the print p. 100 header fragment Pellet plus the compressed corroboration, the print p. 101 header read dropping it (capture pp. 100-101 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57PelletHeavyDen",
      "values" = { 2, 1, 2 },
      "default" = -99,
      "comment" = "the pellet bow and heavy crossbow denominator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57LassoNum",
      "values" = { 1, 3, 2 },
      "default" = -99,
      "comment" = "the lasso and staff sling specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57LassoDen",
      "values" = { 1, 2, 1 },
      "default" = -99,
      "comment" = "the lasso and staff sling denominator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57ShurikenNum",
      "values" = { 3, 4, 5 },
      "default" = -99,
      "comment" = "the large shuriken and thrown dagger specialist attacks-per-round numerator - the column name settles from the print p. 100 header fragment Large plus the compressed corroboration (capture pp. 100-101 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57ShurikenDen",
      "values" = { 1, 1, 1 },
      "default" = -99,
      "comment" = "the large shuriken and thrown dagger denominator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57DartNum",
      "values" = { 4, 5, 6 },
      "default" = -99,
      "comment" = "the dart and small shuriken specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57DartDen",
      "values" = { 1, 1, 1 },
      "default" = -99,
      "comment" = "the dart and small shuriken denominator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57OtherNum",
      "values" = { 3, 2, 5 },
      "default" = -99,
      "comment" = "the other missile weapons column attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "name" = "dhlT57OtherDen",
      "values" = { 2, 1, 2 },
      "default" = -99,
      "comment" = "the other column denominator (capture p. 100 of the print pass; compressed p. 52)",
    } },
  "tables" = { {
      "name" = "dhlT57Grid",
      "tag" = "T57Data",
      "count" = "dhlT57BandCount",
      "sentinel" = -99,
      "cols" = { "dhlT57BowNum", "dhlT57BowDen", "dhlT57LightNum", "dhlT57LightDen", "dhlT57PelletHeavyNum", "dhlT57PelletHeavyDen", "dhlT57LassoNum", "dhlT57LassoDen", "dhlT57ShurikenNum", "dhlT57ShurikenDen", "dhlT57DartNum", "dhlT57DartDen", "dhlT57OtherNum", "dhlT57OtherDen" },
      "col_comments" = { "the bow specialist attacks-per-round numerator by level band (capture p. 100 of the print pass; compressed p. 52). The level rows ride this comment: 0 the 1-6 band, 1 the 7-12 band, 2 the 13-and-up band - the printed cell is the num/den attacks pair, carried per the T55 full/half pair precedent", "the bow specialist attacks-per-round denominator - the number after the slash (capture p. 100 of the print pass; compressed p. 52)", "the light crossbow specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)", "the light crossbow denominator (capture p. 100 of the print pass; compressed p. 52)", "the pellet bow and heavy crossbow specialist attacks-per-round numerator - the column name settles from the print p. 100 header fragment Pellet plus the compressed corroboration, the print p. 101 header read dropping it (capture pp. 100-101 of the print pass; compressed p. 52)", "the pellet bow and heavy crossbow denominator (capture p. 100 of the print pass; compressed p. 52)", "the lasso and staff sling specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)", "the lasso and staff sling denominator (capture p. 100 of the print pass; compressed p. 52)", "the large shuriken and thrown dagger specialist attacks-per-round numerator - the column name settles from the print p. 100 header fragment Large plus the compressed corroboration (capture pp. 100-101 of the print pass; compressed p. 52)", "the large shuriken and thrown dagger denominator (capture p. 100 of the print pass; compressed p. 52)", "the dart and small shuriken specialist attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)", "the dart and small shuriken denominator (capture p. 100 of the print pass; compressed p. 52)", "the other missile weapons column attacks-per-round numerator (capture p. 100 of the print pass; compressed p. 52)", "the other column denominator (capture p. 100 of the print pass; compressed p. 52)" },
      "data" = { { 2, 1, 1, 1, 1, 2, 1, 1, 3, 1, 4, 1, 3, 2 }, { 3, 1, 3, 2, 1, 1, 3, 2, 4, 1, 5, 1, 2, 1 }, { 4, 1, 2, 1, 3, 2, 2, 1, 5, 1, 6, 1, 5, 2 } },
      "comment" = "the Table 57 missile weapon specializations grid (capture p. 100 of the print pass; compressed p. 52)",
      "audit_comment" = "the Table 57 grid: the specialist attacks-per-round pairs by level band",
      "sentinel_census" = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhlT57BandCount']() != 3  or m['dhlT57FirstBandTop']() != 6  or m['dhlT57SecondBandTop']() != 12",
      "note" = "",
    }, {
      "expr" = "m['dhlT57BandCount']() != 3  or m['dhlT57FirstBandTop']() != 6  or m['dhlT57SecondBandTop']() != 12",
      "note" = "the level-band pins - three bands, tops at 6 and 12",
    }, {
      "expr" = "m['dhlT57BowNum'](0) != 2  or m['dhlT57BowDen'](0) != 1  or m['dhlT57BowNum'](1) != 3  or m['dhlT57BowDen'](1) != 1  or m['dhlT57BowNum'](2) != 4  or m['dhlT57BowDen'](2) != 1",
      "note" = "the bow row pairs - 2/1, 3/1, 4/1 up the bands (capture p. 100 of the print pass; compressed p. 52)",
    }, {
      "expr" = "m['dhlT57LightNum'](0) != 1  or m['dhlT57LightDen'](0) != 1  or m['dhlT57LightNum'](1) != 3  or m['dhlT57LightDen'](1) != 2  or m['dhlT57LightNum'](2) != 2  or m['dhlT57LightDen'](2) != 1",
      "note" = "the light crossbow row pairs - 1/1, 3/2, 2/1 (capture p. 100)",
    }, {
      "expr" = "m['dhlT57PelletHeavyNum'](0) != 1  or m['dhlT57PelletHeavyDen'](0) != 2  or m['dhlT57PelletHeavyNum'](1) != 1  or m['dhlT57PelletHeavyDen'](1) != 1  or m['dhlT57PelletHeavyNum'](2) != 3  or m['dhlT57PelletHeavyDen'](2) != 2",
      "note" = "the pellet bow & heavy crossbow row pairs - 1/2, 1/1, 3/2 (capture p. 100)",
    }, {
      "expr" = "m['dhlT57LassoNum'](0) != 1  or m['dhlT57LassoDen'](0) != 1  or m['dhlT57LassoNum'](1) != 3  or m['dhlT57LassoDen'](1) != 2  or m['dhlT57LassoNum'](2) != 2  or m['dhlT57LassoDen'](2) != 1",
      "note" = "the lasso & staff sling row pairs - 1/1, 3/2, 2/1 (capture p. 100)",
    }, {
      "expr" = "m['dhlT57ShurikenNum'](0) != 3  or m['dhlT57ShurikenDen'](0) != 1  or m['dhlT57ShurikenNum'](1) != 4  or m['dhlT57ShurikenDen'](1) != 1  or m['dhlT57ShurikenNum'](2) != 5  or m['dhlT57ShurikenDen'](2) != 1",
      "note" = "the large shuriken & thrown dagger row pairs - 3/1, 4/1, 5/1 (capture p. 100)",
    }, {
      "expr" = "m['dhlT57DartNum'](0) != 4  or m['dhlT57DartDen'](0) != 1  or m['dhlT57DartNum'](1) != 5  or m['dhlT57DartDen'](1) != 1  or m['dhlT57DartNum'](2) != 6  or m['dhlT57DartDen'](2) != 1",
      "note" = "the dart & small shuriken row pairs - 4/1, 5/1, 6/1 (capture p. 100)",
    }, {
      "expr" = "m['dhlT57OtherNum'](0) != 3  or m['dhlT57OtherDen'](0) != 2  or m['dhlT57OtherNum'](1) != 2  or m['dhlT57OtherDen'](1) != 1  or m['dhlT57OtherNum'](2) != 5  or m['dhlT57OtherDen'](2) != 2",
      "note" = "the other column row pairs - 3/2, 2/1, 5/2 (capture p. 100)",
    } },
  "audit" = {
      "label" = "R651 OA missile specializations audit",
      "comment" = "OA round thirty-eight (capture p. 100): Table 57 - the missile weapon specializations grid, the specialist attacks-per-round pairs by level band",
    },
}
