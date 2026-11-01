-- ua: promoted from rules/uacantrips1.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 412,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 1 (R412): the USEFUL category (pp. 45-47), 20 cantrips. The R363 illusionist-cantrips precedent rides: the descriptions pin; the casting-time fraction cells garble in the scan (\"/? segment\", \"V?\", 'h', 'k, Tfe, '/e - the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean: Evocation 7 (Chill, Color, Dampen, Salt, Spice, Sweeten, Warm), Abjuration 4 (Clean, Dry, Dust, Exterminate), Alteration 7 (Gather, Polish, Shine, Sprout, Stitch, Tie, Wrap), Enchantment 2 (Flavor, Freshen).  The area lines print clean for 14 blocks: the one-object eight (Flavor, Freshen, Polish, Salt, Shine, Spice, Sweeten, Tie), the 1' cube pair (Chill, Warm), the cubic yard pair (Color, Wrap), the Clean 4 sq. yds., the Stitch Special. The six \"7\"-family garbles (Dampen, Dry, Dust 70', Exterminate, Gather, Sprout) record as area holes pending the PDF read.  The mechanics pin clean: the Chill/Warm 40 F pair (both directions cross-check), the Freshen/Salt 1-4 damage pair, the Salt 4 sq. yds. and 30 gallons limits, the Tie 1 range with the knot forms, the Shine 1 cubic yard with the DMG p. 26 revalue at -1 once only, the Color 30-day renewal, the Polish 1,000 sq. ft. floor.",
    },
  "consts" = { {
      "name" = "ucnUsefulCount",
      "value" = 20,
      "comment" = "",
    }, {
      "name" = "ucnTempDeltaF",
      "value" = 40,
      "comment" = "---- the mechanics pins ---- The Chill/Warm temperature delta (both about 40 F; the pair cross-checks).",
    }, {
      "name" = "ucnFreshenDmgMax",
      "value" = 4,
      "comment" = "The Freshen damage max (1-4 on a creature harmed by purify food and drink).",
    }, {
      "name" = "ucnSaltDmgMax",
      "value" = 4,
      "comment" = "The Salt damage max (1-4 on a salt-averse creature; the pair cross-checks freshen).",
    }, {
      "name" = "ucnSaltObjectSqYds",
      "value" = 4,
      "comment" = "The Salt object limits: about 4 square yards or 30 gallons.",
    }, {
      "name" = "ucnSaltGallons",
      "value" = 30,
      "comment" = "",
    }, {
      "name" = "ucnTieRangeFt",
      "value" = 1,
      "comment" = "The Tie range: the similar end within 1 foot.",
    }, {
      "name" = "ucnShineMaxCubicYds",
      "value" = 1,
      "comment" = "The Shine volume: a single object up to about 1 cubic yard.",
    }, {
      "name" = "ucnShineRevalueDieMod",
      "value" = -1,
      "comment" = "The Shine revalue: roll again on the DMG p. 26 table with a -1 die modifier, once only.",
    }, {
      "name" = "ucnColorRenewDays",
      "value" = 30,
      "comment" = "The Color renewal: the effect must be renewed every 30 days.",
    }, {
      "name" = "ucnPolishFloorSqFt",
      "value" = 1000,
      "comment" = "The Polish floor: up to 1,000 square feet.",
    } },
  "bools" = { {
      "name" = "ucnShineRevalueOnceOnly",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "ucnUseful",
      "comment" = "The 20 useful cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UcnCantrip T[20] = { { \"Chill\", 0, 1, 1 }, { \"Clean\", 1, 4, 4 }, { \"Color\", 0, 2, 1 }, { \"Dampen\", 0, -1, 0 }, { \"Dry\", 1, -1, 0 }, { \"Dust\", 1, -1, 0 }, { \"Exterminate\", 1, -1, 0 }, { \"Flavor\", 3, 0, 0 }, { \"Freshen\", 3, 0, 0 }, { \"Gather\", 2, -1, 0 }, { \"Polish\", 2, 0, 0 }, { \"Salt\", 0, 0, 0 }, { \"Shine\", 2, 0, 0 }, { \"Spice\", 0, 0, 0 }, { \"Sprout\", 2, -1, 0 }, { \"Stitch\", 2, 3, 0 }, { \"Sweeten\", 0, 0, 0 }, { \"Tie\", 2, 0, 0 }, { \"Warm\", 0, 1, 1 }, { \"Wrap\", 2, 2, 1 }, }; if (i < 0) i = 0; if (i > 19) i = 19; return T[i];",
    }, {
      "name" = "ucnSchoolCount",
      "comment" = "The school census.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 20; ++i) if (ucnUseful(i).school == s) ++n; return n;",
    }, {
      "name" = "ucnAreaKindCount",
      "comment" = "The area kind census.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 20; ++i) if (ucnUseful(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "ucnCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R418) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: 17 at 1/2 (Chill, Clean, Color, Dampen, Dry, Dust, Flavor, Freshen, Polish, Shine, Spice, Sprout, Stitch, Sweeten, Tie, Warm, Wrap), Exterminate at 1/10, Gather and Salt at 1/8.",
      "kind" = "header pin",
      "body" = "static const int D[20] = { 2, 2, 2, 2, 2, 2, 10, 2, 2, 8, 2, 8, 2, 2, 2, 2, 2, 2, 2, 2 }; if (i < 0) i = 0; if (i > 19) i = 19; return D[i];",
    }, {
      "name" = "ucnCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 20; ++i) if (ucnCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['ucnUsefulCount']() != 20  or m['uastCantripCount'](0) != 20  or m['cantMuCategoryCount']() != 6",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['ucnSchoolCount'](UCN_EVO) != 7  or m['ucnSchoolCount'](UCN_ABJ) != 4  or m['ucnSchoolCount'](UCN_ALT) != 7  or m['ucnSchoolCount'](UCN_ENCH) != 2",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['ucnAreaKindCount'](UCN_AREA_OBJECT) != 8  or m['ucnAreaKindCount'](UCN_AREA_CUBEFoot) != 2  or m['ucnAreaKindCount'](UCN_AREA_CUBICyd) != 2  or m['ucnAreaKindCount'](UCN_AREA_SPECIAL) != 1  or m['ucnAreaKindCount'](UCN_AREA_SQYDS) != 1  or m['ucnAreaKindCount'](UCN_AREA_HOLE) != 6  or strcmp(m['ucnUseful'](0).name,m['uastCantripName'](0, 0)) != 0  or m['ucnUseful'](0).school != 0  or m['ucnUseful'](0).areaKind != 1  or m['ucnUseful'](0).areaVal != 1  or strcmp(m['ucnUseful'](1).name,m['uastCantripName'](0, 1)) != 0  or m['ucnUseful'](1).school != 1  or m['ucnUseful'](1).areaKind != 4  or m['ucnUseful'](1).areaVal != 4  or strcmp(m['ucnUseful'](2).name,m['uastCantripName'](0, 2)) != 0  or m['ucnUseful'](2).school != 0  or m['ucnUseful'](2).areaKind != 2  or m['ucnUseful'](2).areaVal != 1  or strcmp(m['ucnUseful'](3).name,m['uastCantripName'](0, 3)) != 0  or m['ucnUseful'](3).school != 0  or m['ucnUseful'](3).areaKind != -1  or m['ucnUseful'](3).areaVal != 0  or strcmp(m['ucnUseful'](4).name,m['uastCantripName'](0, 4)) != 0  or m['ucnUseful'](4).school != 1  or m['ucnUseful'](4).areaKind != -1  or m['ucnUseful'](4).areaVal != 0  or strcmp(m['ucnUseful'](5).name,m['uastCantripName'](0, 5)) != 0  or m['ucnUseful'](5).school != 1  or m['ucnUseful'](5).areaKind != -1  or m['ucnUseful'](5).areaVal != 0  or strcmp(m['ucnUseful'](6).name,m['uastCantripName'](0, 6)) != 0  or m['ucnUseful'](6).school != 1  or m['ucnUseful'](6).areaKind != -1  or m['ucnUseful'](6).areaVal != 0  or strcmp(m['ucnUseful'](7).name,m['uastCantripName'](0, 7)) != 0  or m['ucnUseful'](7).school != 3  or m['ucnUseful'](7).areaKind != 0  or m['ucnUseful'](7).areaVal != 0  or strcmp(m['ucnUseful'](8).name,m['uastCantripName'](0, 8)) != 0  or m['ucnUseful'](8).school != 3  or m['ucnUseful'](8).areaKind != 0  or m['ucnUseful'](8).areaVal != 0  or strcmp(m['ucnUseful'](9).name,m['uastCantripName'](0, 9)) != 0  or m['ucnUseful'](9).school != 2  or m['ucnUseful'](9).areaKind != -1  or m['ucnUseful'](9).areaVal != 0  or strcmp(m['ucnUseful'](10).name,m['uastCantripName'](0, 10)) != 0  or m['ucnUseful'](10).school != 2  or m['ucnUseful'](10).areaKind != 0  or m['ucnUseful'](10).areaVal != 0  or strcmp(m['ucnUseful'](11).name,m['uastCantripName'](0, 11)) != 0  or m['ucnUseful'](11).school != 0  or m['ucnUseful'](11).areaKind != 0  or m['ucnUseful'](11).areaVal != 0  or strcmp(m['ucnUseful'](12).name,m['uastCantripName'](0, 12)) != 0  or m['ucnUseful'](12).school != 2  or m['ucnUseful'](12).areaKind != 0  or m['ucnUseful'](12).areaVal != 0  or strcmp(m['ucnUseful'](13).name,m['uastCantripName'](0, 13)) != 0  or m['ucnUseful'](13).school != 0  or m['ucnUseful'](13).areaKind != 0  or m['ucnUseful'](13).areaVal != 0  or strcmp(m['ucnUseful'](14).name,m['uastCantripName'](0, 14)) != 0  or m['ucnUseful'](14).school != 2  or m['ucnUseful'](14).areaKind != -1  or m['ucnUseful'](14).areaVal != 0  or strcmp(m['ucnUseful'](15).name,m['uastCantripName'](0, 15)) != 0  or m['ucnUseful'](15).school != 2  or m['ucnUseful'](15).areaKind != 3  or m['ucnUseful'](15).areaVal != 0  or strcmp(m['ucnUseful'](16).name,m['uastCantripName'](0, 16)) != 0  or m['ucnUseful'](16).school != 0  or m['ucnUseful'](16).areaKind != 0  or m['ucnUseful'](16).areaVal != 0  or strcmp(m['ucnUseful'](17).name,m['uastCantripName'](0, 17)) != 0  or m['ucnUseful'](17).school != 2  or m['ucnUseful'](17).areaKind != 0  or m['ucnUseful'](17).areaVal != 0  or strcmp(m['ucnUseful'](18).name,m['uastCantripName'](0, 18)) != 0  or m['ucnUseful'](18).school != 0  or m['ucnUseful'](18).areaKind != 1  or m['ucnUseful'](18).areaVal != 1  or strcmp(m['ucnUseful'](19).name,m['uastCantripName'](0, 19)) != 0  or m['ucnUseful'](19).school != 2  or m['ucnUseful'](19).areaKind != 2  or m['ucnUseful'](19).areaVal != 1",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['ucnCastTimeDen'](0) != 2  or m['ucnCastTimeDen'](1) != 2  or m['ucnCastTimeDen'](2) != 2  or m['ucnCastTimeDen'](3) != 2  or m['ucnCastTimeDen'](4) != 2  or m['ucnCastTimeDen'](5) != 2  or m['ucnCastTimeDen'](6) != 10  or m['ucnCastTimeDen'](7) != 2  or m['ucnCastTimeDen'](8) != 2  or m['ucnCastTimeDen'](9) != 8  or m['ucnCastTimeDen'](10) != 2  or m['ucnCastTimeDen'](11) != 8  or m['ucnCastTimeDen'](12) != 2  or m['ucnCastTimeDen'](13) != 2  or m['ucnCastTimeDen'](14) != 2  or m['ucnCastTimeDen'](15) != 2  or m['ucnCastTimeDen'](16) != 2  or m['ucnCastTimeDen'](17) != 2  or m['ucnCastTimeDen'](18) != 2  or m['ucnCastTimeDen'](19) != 2",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R418)",
    }, {
      "expr" = "m['ucnTempDeltaF']() != 40  or m['ucnFreshenDmgMax']() != 4  or m['ucnSaltDmgMax']() !=m['ucnFreshenDmgMax']()  or m['ucnSaltObjectSqYds']() != 4  or m['ucnSaltGallons']() != 30  or m['ucnTieRangeFt']() != 1  or m['ucnShineMaxCubicYds']() != 1  or m['ucnShineRevalueDieMod']() != -1  or  m['ucnShineRevalueOnceOnly']() != 1  or m['ucnColorRenewDays']() != 30  or m['ucnPolishFloorSqFt']() != 1000",
      "note" = "---- the mechanics ----",
    } },
  "audit" = {
      "label" = "R412: the UA useful cantrips pin audit",
      "comment" = "The 20 useful-category descriptions pin: the names cross-check the R341/R401 roster live, the schools and areas pin per row, the school census counts (7/4/7/2), the six area garbles record as holes pending the PDF read, the casting-time family stays the hole family, the mechanics pin with the chill/warm and freshen/salt pairs cross- checking each other; census 338 -> 339.",
    },
}
