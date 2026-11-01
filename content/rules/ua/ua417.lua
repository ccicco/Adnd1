-- ua: promoted from rules/uacantrips6.h (the The UA MAGIC-USER CANTRIP);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 417,
  "prefix" = "ua",
  "banner" = {
      "title" = "The UA MAGIC-USER CANTRIP",
      "provenance" = "DESCRIPTIONS, part 6 (R417): the HAUNTING-SOUND category (pp. 50-51), 8 cantrips - the LAST of the six MU cantrip description rounds. The R363/R412/R413/R414/R415/R416 precedents ride: the descriptions pin; the casting-time fraction cells garble in the scan (the whole family) and record as holes pending the PDF read - never guesses.  The school tags print clean: NO new school codes this round. The census: Evocation 3 (Creak, Tap, Whistle), Illusion 5 (Footfall, Groan, Moan, Rattle, Thump).  The area lines print clean for ALL 8 blocks - ZERO area holes: the Special seven and the Tap 1 sq. ft. (a NEW area kind code).  The range family: five blocks print the numerals clean (the near 1, the footfall far 2) but the foot/inch glyphs garble - the numerals pin, the unit family records as holes pending the PDF read. The creak traverse prints an ambiguous \"1 0\" - the value records as a hole (never a guess). The whistle pair prints CLEAN: the faint 10 feet and the loud 30 feet pin with the loud == faint*3 derivation.  The mechanics pin clean: the creak latter half segment (the former 1/3 garbles - a hole), the moan two flavors, the rattle 2 seconds, the tap once/twice/thrice 1..3 band, and the whistle pair.",
    },
  "consts" = { {
      "name" = "uchHauntingSoundCount",
      "value" = 8,
      "comment" = "The count.",
    }, {
      "name" = "uchRangeNearVal",
      "value" = 1,
      "comment" = "The near range numeral (the groan, rattle, tap and thump blocks all print 1).",
    }, {
      "name" = "uchFootfallFarVal",
      "value" = 2,
      "comment" = "The footfall far numeral (the footfalls may move away up to 2).",
    }, {
      "name" = "uchCreakFormerDen",
      "value" = 3,
      "comment" = "---- the mechanics pins ---- The creak read (the PDF read resolves the garble - R419): the former sound (corroded- hinge door) lasts 1/3 segment (the denominator 3); the latter noise (squeaking floorboards) lasts half a segment (in halves).",
    }, {
      "name" = "uchCreakLatterHalfSegs",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uchCreakTraverseFeet",
      "value" = 10,
      "comment" = "The creak traverse: the PDF read resolves the ambiguity (R419) - the latter noise seems to traverse up to 10 feet distance.",
    }, {
      "name" = "uchMoanFlavors",
      "value" = 2,
      "comment" = "The moan read: the sound is either a low-pitched haunting moan or a high-pitched pitiful one - two flavors.",
    }, {
      "name" = "uchRattleSeconds",
      "value" = 2,
      "comment" = "The rattle read: the chain rattle lasts for up to 2 seconds.",
    }, {
      "name" = "uchTapCountMin",
      "value" = 1,
      "comment" = "The tap read: the sound occurs once, twice, or thrice, according to the number of fingers extended by the caster.",
    }, {
      "name" = "uchTapCountMax",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uchWhistleFaintFeet",
      "value" = 10,
      "comment" = "The whistle read: a faint whistling can be heard within 10 feet, a loud one within 30 feet (the pair prints clean).",
    }, {
      "name" = "uchWhistleLoudFeet",
      "value" = 30,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uchRangeUnitIsInch",
      "value" = true,
      "comment" = "The range units: the PDF read resolves the glyphs (R419) - the ranged blocks print the AD&D 1\" notation (one inch of range, the ten-foot indoor scale). The unit pins as inch; the numerals ride the standing uchRangeNearVal() and uchFootfallFarVal() pins.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uchHauntingSound",
      "comment" = "The 8 haunting-sound cantrips, in the R341/R401 roster order.",
      "kind" = "header pin",
      "body" = "static const UchCantrip T[8] = { { \"Creak\", 0, 3, 0 }, { \"Footfall\", 4, 3, 0 }, { \"Groan\", 4, 3, 0 }, { \"Moan\", 4, 3, 0 }, { \"Rattle\", 4, 3, 0 }, { \"Tap\", 0, 13, 1 }, { \"Thump\", 4, 3, 0 }, { \"Whistle\", 0, 3, 0 }, }; if (i < 0) i = 0; if (i > 7) i = 7; return T[i];",
    }, {
      "name" = "uchSchoolCount",
      "comment" = "The school census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 8; ++i) if (uchHauntingSound(i).school == s) ++n; return n;",
    }, {
      "name" = "uchAreaKindCount",
      "comment" = "The area kind census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 8; ++i) if (uchHauntingSound(i).areaKind == a) ++n; return n;",
    }, {
      "name" = "uchCastTimeDen",
      "comment" = "The casting times: the PDF read resolves the whole family (R419) - the real UA PDF prints every cell clean, a unit fraction, one segment over the denominator. The denominators, in roster order: order: Creak, Footfall, Groan, Tap and Whistle at 1/6, Moan, Rattle and Thump at 1/10 - the 1/6 lands inside the 2..10 band the p. 45 header prints.",
      "kind" = "header pin",
      "body" = "static const int D[8] = { 6, 6, 6, 10, 10, 6, 10, 6 }; if (i < 0) i = 0; if (i > 7) i = 7; return D[i];",
    }, {
      "name" = "uchCastTimeDenCount",
      "comment" = "The casting-time denominator census helper.",
      "kind" = "header pin",
      "body" = "int n = 0; for (int i = 0; i < 8; ++i) if (uchCastTimeDen(i) == d) ++n; return n;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['uchHauntingSoundCount']() != 8  or m['uastCantripCount'](5) != 8",
      "note" = "---- the census ----",
    }, {
      "expr" = "m['uchSchoolCount'](UCH_EVO) != 3  or m['uchSchoolCount'](UCH_ILL) != 5  or m['uchSchoolCount'](1) != 0  or m['uchSchoolCount'](2) != 0  or m['uchSchoolCount'](3) != 0  or m['uchSchoolCount'](5) != 0  or m['uchSchoolCount'](6) != 0  or m['uchSchoolCount'](7) != 0",
      "note" = "---- the school census ----",
    }, {
      "expr" = "m['uchAreaKindCount'](UCH_AREA_SPECIAL) != 7  or m['uchAreaKindCount'](UCH_AREA_SQFT) != 1  or m['uchAreaKindCount'](UCH_AREA_HOLE) != 0  or strcmp(m['uchHauntingSound'](0).name,m['uastCantripName'](5, 0)) != 0  or m['uchHauntingSound'](0) .school != 0  or m['uchHauntingSound'](0) .areaKind != 3  or m['uchHauntingSound'](0) .areaVal != 0  or strcmp(m['uchHauntingSound'](1).name,m['uastCantripName'](5, 1)) != 0  or m['uchHauntingSound'](1) .school != 4  or m['uchHauntingSound'](1) .areaKind != 3  or m['uchHauntingSound'](1) .areaVal != 0  or strcmp(m['uchHauntingSound'](2).name,m['uastCantripName'](5, 2)) != 0  or m['uchHauntingSound'](2) .school != 4  or m['uchHauntingSound'](2) .areaKind != 3  or m['uchHauntingSound'](2) .areaVal != 0  or strcmp(m['uchHauntingSound'](3).name,m['uastCantripName'](5, 3)) != 0  or m['uchHauntingSound'](3) .school != 4  or m['uchHauntingSound'](3) .areaKind != 3  or m['uchHauntingSound'](3) .areaVal != 0  or strcmp(m['uchHauntingSound'](4).name,m['uastCantripName'](5, 4)) != 0  or m['uchHauntingSound'](4) .school != 4  or m['uchHauntingSound'](4) .areaKind != 3  or m['uchHauntingSound'](4) .areaVal != 0  or strcmp(m['uchHauntingSound'](5).name,m['uastCantripName'](5, 5)) != 0  or m['uchHauntingSound'](5) .school != 0  or m['uchHauntingSound'](5) .areaKind != 13  or m['uchHauntingSound'](5) .areaVal != 1  or strcmp(m['uchHauntingSound'](6).name,m['uastCantripName'](5, 6)) != 0  or m['uchHauntingSound'](6) .school != 4  or m['uchHauntingSound'](6) .areaKind != 3  or m['uchHauntingSound'](6) .areaVal != 0  or strcmp(m['uchHauntingSound'](7).name,m['uastCantripName'](5, 7)) != 0  or m['uchHauntingSound'](7) .school != 0  or m['uchHauntingSound'](7) .areaKind != 3  or m['uchHauntingSound'](7) .areaVal != 0",
      "note" = "---- the area census ----",
    }, {
      "expr" = "m['uchCastTimeDen'](0) != 6  or m['uchCastTimeDen'](1) != 6  or m['uchCastTimeDen'](2) != 6  or m['uchCastTimeDen'](3) != 10  or m['uchCastTimeDen'](4) != 10  or m['uchCastTimeDen'](5) != 6  or m['uchCastTimeDen'](6) != 10  or m['uchCastTimeDen'](7) != 6",
      "note" = "---- the casting times ---- (the PDF read resolves the family - R419)",
    }, {
      "expr" = "m['uchRangeUnitIsInch']() != 1  or m['uchCreakFormerDen']() != 3  or m['uchCreakTraverseFeet']() != 10",
      "note" = "---- the resolved reads (the PDF read - R419)",
    }, {
      "expr" = "m['uchRangeNearVal']() != 1  or m['uchFootfallFarVal']() != 2  or m['uchMoanFlavors']() != 2  or m['uchRattleSeconds']() != 2  or m['uchCreakLatterHalfSegs']() != 1  or m['uchTapCountMin']() != 1  or m['uchTapCountMax']() != 3  or m['uchWhistleFaintFeet']() != 10  or m['uchWhistleLoudFeet']() != 30",
      "note" = "---- the mechanics ----",
    }, {
      "expr" = "m['uchTapCountMin']() >=m['uchTapCountMax']()  or m['uchWhistleLoudFeet']() !=m['uchWhistleFaintFeet']() * 3",
      "note" = "The band derivations: the tap once/twice/thrice opens below its close and the whistle loud radius rides three times the faint one - both cross-check by derivation (quiet on the healthy values - the R391 lesson).",
    } },
  "audit" = {
      "label" = "R417: the UA haunting-sound cantrips pin audit",
      "comment" = "The 8 haunting-sound descriptions pin - the LAST of the six description rounds: the names cross- check the R341/R401 roster live, the schools pin per row (NO new codes - the Evocation 3 / Illusion 5 census), the areas pin per row (ZERO area holes - the Special seven and the Tap one square foot, a NEW area kind), the censuses count, the mechanics pin with the band derivations cross- checking themselves (the whistle loud == faint*3); census 343 -> 344.",
    },
}
