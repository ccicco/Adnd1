-- ua: promoted from rules/uacantrips2.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 413,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 2 (R413): the REVERSED category (pp. 47-48), 12 cantrips. The R363/R412 precedents ride: the descriptions pin; the casting-time fraction cells garble in the scan (the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean: Evocation 3 (Dirty, Dusty, Sour), Abjuration 0, Alteration 7 (Hairy, Knot, Ravel, Spill, Tangle, Tarnish, Untie), Enchantment 2 (Curdle, Wilt).  The area lines print clean for ALL 12 blocks - ZERO area holes this round: the one-object eight (Curdle, Hairy, Knot, Sour, Tangle, Tarnish, Untie, Wilt), the Dirty 4 sq. yds. (cross-checks the Clean 4 sq. yds. from R412), the Dusty 10' radius, the Ravel Special, the Spill one container.  The mechanics pin clean: the Hairy 2-12 inch growth with the under-1-inch short- material read and the reversed 2-12 day absence, the Knot 2-8 rounds, the Tangle 3-12 rounds, the Sour 1-pint vinegar max, the Spill 1-gallon container limit, the Tarnish 1 cubic yard (the reverse of the R412 shine volume - a live cross-check).",
    },
  "consts" = { {
      "name" = "ucrReversedCount",
      "value" = 12,
      "comment" = "The count.",
    }, {
      "name" = "ucrHairyGrowthMinIn",
      "value" = 2,
      "comment" = "---- the mechanics pins ---- The Hairy growth range: the subject material increases from 2 to 12 inches in length.",
    }, {
      "name" = "ucrHairyGrowthMaxIn",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "ucrHairyShortUnderIn",
      "value" = 1,
      "comment" = "The Hairy short-material threshold: material under 1 inch in length.",
    }, {
      "name" = "ucrHairyAbsenceMinDays",
      "value" = 2,
      "comment" = "The Hairy reversed read: the complete absence of growth for 2 to 12 days.",
    }, {
      "name" = "ucrHairyAbsenceMaxDays",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "ucrKnotUntieMinRounds",
      "value" = 2,
      "comment" = "The Knot untie range: from 2 to 8 rounds, minus the dexterity reaction bonus.",
    }, {
      "name" = "ucrKnotUntieMaxRounds",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "ucrTangleUntangleMinRounds",
      "value" = 3,
      "comment" = "The Tangle untangle range: 3 to 12 rounds unless roughly done.",
    }, {
      "name" = "ucrTangleUntangleMaxRounds",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "ucrSourMaxPints",
      "value" = 1,
      "comment" = "The Sour vinegar max: about a pint appears over the subject.",
    }, {
      "name" = "ucrSpillMaxGallons",
      "value" = 1,
      "comment" = "The Spill container limit: containers of more than about gallon size are unaffected.",
    }, {
      "name" = "ucrTarnishMaxCubicYds",
      "value" = 1,
      "comment" = "The Tarnish volume: the object must be about 1 cubic yard or less - the reverse of the R412 shine volume (a live cross- check).",
    } },
  "bools" = {},
  "switches" = {},
  "tables" = { {
      "name" = "ucrReversed",
      "comment" = "The 12 reversed cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UcrCantrip T[12] = { { \"Curdle\", 3, 0, 0 }, { \"Dirty\", 0, 4, 4 }, { \"Dusty\", 0, 5, 10 }, { \"Hairy\", 2, 0, 0 }, { \"Knot\", 2, 0, 0 }, { \"Ravel\", 2, 3, 0 }, { \"Sour\", 0, 0, 0 }, { \"Spill\", 2, 6, 0 }, { \"Tangle\", 2, 0, 0 }, { \"Tarnish\", 2, 0, 0 }, { \"Untie\", 2, 0, 0 }, { \"Wilt\", 3, 0, 0 }, }; if (i < 0) i = 0; if (i > 11) i = 11; return T[i];",
    }, {
      "name" = "ucrSchoolCount",
      "comment" = "The school census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 12; ++i) if (ucrReversed(i).school == s) ++n; return n;",
    }, {
      "name" = "ucrAreaKindCount",
      "comment" = "The area kind census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 12; ++i) if (ucrReversed(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "ucrCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R418) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: Curdle, Dirty and Dusty at 1/8, Hairy at 1/10, Knot at 1/2, Ravel at 1/10, Sour at 1/2, Spill and Tangle at 1/8, Tarnish at 1/2, Untie at 1/3 (the lowercase Casting-time print, the systematic OCR read, noted in R413), Wilt at 1/2.",
      "kind" = "header pin",
      "body" = "static const int D[12] = { 8, 8, 8, 10, 2, 10, 2, 8, 8, 2, 3, 2 }; if (i < 0) i = 0; if (i > 11) i = 11; return D[i];",
    }, {
      "name" = "ucrCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 12; ++i) if (ucrCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ucrReversedCount']() != 12  or m['uastCantripCount'](1) != 12",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['ucrSchoolCount'](UCR_EVO) != 3  or m['ucrSchoolCount'](UCR_ABJ) != 0  or m['ucrSchoolCount'](UCR_ALT) != 7  or m['ucrSchoolCount'](UCR_ENCH) != 2",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['ucrAreaKindCount'](UCR_AREA_OBJECT) != 8  or m['ucrAreaKindCount'](UCR_AREA_SQYDS) != 1  or m['ucrAreaKindCount'](UCR_AREA_RADIUS) != 1  or m['ucrAreaKindCount'](UCR_AREA_SPECIAL) != 1  or m['ucrAreaKindCount'](UCR_AREA_CONTAINER) != 1  or m['ucrAreaKindCount'](UCR_AREA_HOLE) != 0  or strcmp(m['ucrReversed'](0).name,m['uastCantripName'](1, 0)) != 0  or m['ucrReversed'](0) .school != 3  or m['ucrReversed'](0) .areaKind != 0  or m['ucrReversed'](0) .areaVal != 0  or strcmp(m['ucrReversed'](1).name,m['uastCantripName'](1, 1)) != 0  or m['ucrReversed'](1) .school != 0  or m['ucrReversed'](1) .areaKind != 4  or m['ucrReversed'](1) .areaVal != 4  or strcmp(m['ucrReversed'](2).name,m['uastCantripName'](1, 2)) != 0  or m['ucrReversed'](2) .school != 0  or m['ucrReversed'](2) .areaKind != 5  or m['ucrReversed'](2) .areaVal != 10  or strcmp(m['ucrReversed'](3).name,m['uastCantripName'](1, 3)) != 0  or m['ucrReversed'](3) .school != 2  or m['ucrReversed'](3) .areaKind != 0  or m['ucrReversed'](3) .areaVal != 0  or strcmp(m['ucrReversed'](4).name,m['uastCantripName'](1, 4)) != 0  or m['ucrReversed'](4) .school != 2  or m['ucrReversed'](4) .areaKind != 0  or m['ucrReversed'](4) .areaVal != 0  or strcmp(m['ucrReversed'](5).name,m['uastCantripName'](1, 5)) != 0  or m['ucrReversed'](5) .school != 2  or m['ucrReversed'](5) .areaKind != 3  or m['ucrReversed'](5) .areaVal != 0  or strcmp(m['ucrReversed'](6).name,m['uastCantripName'](1, 6)) != 0  or m['ucrReversed'](6) .school != 0  or m['ucrReversed'](6) .areaKind != 0  or m['ucrReversed'](6) .areaVal != 0  or strcmp(m['ucrReversed'](7).name,m['uastCantripName'](1, 7)) != 0  or m['ucrReversed'](7) .school != 2  or m['ucrReversed'](7) .areaKind != 6  or m['ucrReversed'](7) .areaVal != 0  or strcmp(m['ucrReversed'](8).name,m['uastCantripName'](1, 8)) != 0  or m['ucrReversed'](8) .school != 2  or m['ucrReversed'](8) .areaKind != 0  or m['ucrReversed'](8) .areaVal != 0  or strcmp(m['ucrReversed'](9).name,m['uastCantripName'](1, 9)) != 0  or m['ucrReversed'](9) .school != 2  or m['ucrReversed'](9) .areaKind != 0  or m['ucrReversed'](9) .areaVal != 0  or strcmp(m['ucrReversed'](10).name,m['uastCantripName'](1, 10)) != 0  or m['ucrReversed'](10) .school != 2  or m['ucrReversed'](10) .areaKind != 0  or m['ucrReversed'](10) .areaVal != 0  or strcmp(m['ucrReversed'](11).name,m['uastCantripName'](1, 11)) != 0  or m['ucrReversed'](11) .school != 3  or m['ucrReversed'](11) .areaKind != 0  or m['ucrReversed'](11) .areaVal != 0",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['ucrCastTimeDen'](0) != 8  or m['ucrCastTimeDen'](1) != 8  or m['ucrCastTimeDen'](2) != 8  or m['ucrCastTimeDen'](3) != 10  or m['ucrCastTimeDen'](4) != 2  or m['ucrCastTimeDen'](5) != 10  or m['ucrCastTimeDen'](6) != 2  or m['ucrCastTimeDen'](7) != 8  or m['ucrCastTimeDen'](8) != 8  or m['ucrCastTimeDen'](9) != 2  or m['ucrCastTimeDen'](10) != 3  or m['ucrCastTimeDen'](11) != 2",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R418)",
    }, {
      "expr" = "m['ucrHairyGrowthMinIn']() != 2  or m['ucrHairyGrowthMaxIn']() != 12  or m['ucrHairyShortUnderIn']() != 1  or m['ucrHairyAbsenceMinDays']() != 2  or m['ucrHairyAbsenceMaxDays']() != 12  or m['ucrKnotUntieMinRounds']() != 2  or m['ucrKnotUntieMaxRounds']() != 8  or m['ucrTangleUntangleMinRounds']() != 3  or m['ucrTangleUntangleMaxRounds']() != 12  or m['ucrSourMaxPints']() != 1  or m['ucrSpillMaxGallons']() != 1",
      "note" = "---- the mechanics ----",
    }, {
      "expr" = "m['ucrTarnishMaxCubicYds']() !=m['ucnShineMaxCubicYds']()",
      "note" = "---- the live pairs ---- The tarnish volume is the reverse of the R412 shine volume.",
    }, {
      "expr" = "m['ucrReversed'](1).areaKind != UCR_AREA_SQYDS  or m['ucrReversed'](1).areaVal !=m['ucnUseful'](1).areaVal",
      "note" = "The Dirty 4 sq. yds. is the opposite of the Clean 4 sq. yds. (R412).",
    } },
  "audit" = {
      "label" = "R413: the UA reversed cantrips pin audit",
      "comment" = "The 12 reversed-category descriptions pin: the names cross-check the R341/R401 roster live, the schools and areas pin per row (ZERO area holes this round), the school census counts (3/0/7/2), the casting-time family stays the hole family, the mechanics pin with the tarnish/shine and dirty/clean pairs cross- checking each other; census 339 -> 340.",
    },
}
